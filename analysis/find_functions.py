#!/usr/bin/env python3
"""Stage 1 of the ROM -> symbols pipeline: locate function boundaries.

Reads the verified load map (analysis/out/segments.json) and the ROM, then for
every *code* segment performs a linear rabbitizer sweep of the segment's declared
text range and derives function starts from:

  * the text start of the segment (and the hard entrypoint at vram 0x800C2400),
  * `jal` targets raised inside the segment itself ("jal", always trusted),
  * `jal` targets raised by *other* segments that land in this segment's text
    range ("xjal"; plausibility-filtered when several overlay images share the
    same VRAM slot, because a target that is a real function in overlay A is
    usually mid-function in overlay B),
  * the first non-nop word after a `jr $ra` + delay slot ("gap"),
  * `lui`/`addiu` pairs that materialise an in-text address ("ptr" - function
    pointers / callback tables).

Every candidate that is not backed by a `jal` must survive two sanity checks:
it may not be crossed by an intra-segment branch (compiler branches never cross
a function boundary), and it must be preceded by a flow terminator.

Output: analysis/out/functions.json
"""

import argparse
import collections
import json
import os
import struct
import sys

import rabbitizer

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_ROM = os.path.join(ROOT, "build", "knife_edge.z64")
DEFAULT_SEGMENTS = os.path.join(ROOT, "analysis", "out", "segments.json")
DEFAULT_OUT = os.path.join(ROOT, "analysis", "out", "functions.json")
DEFAULT_REPORT = os.path.join(ROOT, "analysis", "out", "functions_report.txt")

ENTRYPOINT_VRAM = 0x800C2400
ENTRYPOINT_ROM = 0x1000

# The boot segment is the only code segment without a descriptor-declared text
# range (IPL3 loads it blind).  Its text ends at the last `jr $ra` before the two
# embedded RSP microcode blobs; n64sym independently labels 0x800E51F0
# `rspbootTextStart`, which agrees with the opcode statistics in segment_map.md.
BOOT_TEXT = (0x800C2400, 0x800E51F0)

rabbitizer.config.pseudos_pseudoMove = False


# --------------------------------------------------------------------------- #
# segment loading
# --------------------------------------------------------------------------- #

class Segment(object):
    __slots__ = ("name", "rom", "size", "vram", "kind", "text_start", "text_end",
                 "text_rom", "words", "insns", "n")

    def __repr__(self):
        return "<Segment %s rom=%06X vram=%08X text=%08X..%08X>" % (
            self.name, self.rom, self.vram, self.text_start, self.text_end)


def load_code_segments(segments_path, rom_data):
    """Return the code segments from segments.json, with words decoded."""
    raw = json.load(open(segments_path))
    out = []
    for s in raw:
        kind = s.get("kind", "")
        text = s.get("text")
        if "code" not in kind and not text:
            continue
        if text:
            t0, t1 = int(text[0]), int(text[1])
        elif s["name"] == "boot":
            t0, t1 = BOOT_TEXT
        else:
            sys.stderr.write("warning: code segment %s has no text range, skipped\n"
                             % s["name"])
            continue
        seg = Segment()
        seg.name = s["name"]
        seg.rom = int(s["rom"])
        seg.size = int(s["size"])
        seg.vram = int(s["vram"])
        seg.kind = kind
        seg.text_start = t0
        seg.text_end = t1
        seg.text_rom = seg.rom + (t0 - seg.vram)
        assert t0 % 4 == 0 and t1 % 4 == 0, seg.name
        assert seg.vram <= t0 < t1 <= seg.vram + seg.size, seg.name
        seg.n = (t1 - t0) // 4
        seg.words = struct.unpack_from(">%dI" % seg.n, rom_data, seg.text_rom)
        seg.insns = [rabbitizer.Instruction(w, vram=t0 + i * 4)
                     for i, w in enumerate(seg.words)]
        out.append(seg)
    return out


# --------------------------------------------------------------------------- #
# per-segment structural scan
# --------------------------------------------------------------------------- #

# Registers clobbered across a call; used to invalidate tracked constants.
CALL_CLOBBER = frozenset([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                          24, 25, 31])


class Scan(object):
    """Structural facts about one segment's text."""

    def __init__(self, seg):
        self.seg = seg
        self.jal_targets = collections.Counter()   # absolute vram -> count
        self.term = bytearray(seg.n)               # 1 == ends basic flow
        self.jr_ra = []                            # indices
        self.valid = bytearray(seg.n)
        self.cross = None                          # branch-crossing prefix sums
        self.ptr_consts = collections.Counter()    # vram -> count
        self.branch_targets = set()                # in-segment vram


def scan_segment(seg):
    sc = Scan(seg)
    n = seg.n
    base = seg.text_start
    W = seg.words
    I = seg.insns
    delta = [0] * (n + 2)  # difference array for "a branch crosses index i"

    regs = {}
    for i in range(n):
        ins = I[i]
        w = W[i]
        if ins.isValid():
            sc.valid[i] = 1

        if ins.isFunctionCall():           # jal (and jalr is not JumpWithAddress)
            if ins.isJumpWithAddress():
                sc.jal_targets[ins.getInstrIndexAsVram()] += 1
        elif ins.isJumpWithAddress():      # plain `j`
            sc.term[i] = 1
        elif ins.isJrRa():
            sc.term[i] = 1
            sc.jr_ra.append(i)
        elif ins.isJrNotRa():
            sc.term[i] = 1
        elif w == 0x42000018:              # eret
            sc.term[i] = 1
        elif ins.isBranch():
            try:
                tgt = ins.getBranchVramGeneric()
            except Exception:
                tgt = None
            if tgt is not None and base <= tgt < seg.text_end:
                j = (tgt - base) // 4
                sc.branch_targets.add(tgt)
                lo, hi = (i, j) if i < j else (j, i)
                # a boundary at index k is "crossed" when lo < k <= hi
                delta[lo + 1] += 1
                delta[hi + 1] -= 1
            if ins.isUnconditionalBranch():
                sc.term[i] = 1

        # ---- constant tracking (lui / addiu / ori) for function pointers ----
        op = w >> 26
        rs = (w >> 21) & 0x1F
        rt = (w >> 16) & 0x1F
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0F:            # lui
            regs[rt] = (imm << 16) & 0xFFFFFFFF
        elif op == 0x09:          # addiu
            if rs in regs:
                v = (regs[rs] + simm) & 0xFFFFFFFF
                regs[rt] = v
                if base <= v < seg.text_end and v % 4 == 0:
                    sc.ptr_consts[v] += 1
            elif rs == 0:
                regs[rt] = simm & 0xFFFFFFFF
            else:
                regs.pop(rt, None)
        elif op == 0x0D:          # ori
            if rs in regs:
                v = regs[rs] | imm
                regs[rt] = v
                if base <= v < seg.text_end and v % 4 == 0:
                    sc.ptr_consts[v] += 1
            elif rs == 0:
                regs[rt] = imm
            else:
                regs.pop(rt, None)
        elif op == 3:             # jal
            for r in list(regs):
                if r in CALL_CLOBBER:
                    del regs[r]
        elif op == 0:
            funct = w & 0x3F
            rd = (w >> 11) & 0x1F
            if funct == 0x25 and rt == 0 and rs in regs:   # or rd, rs, $zero
                regs[rd] = regs[rs]
            elif funct == 9:      # jalr
                for r in list(regs):
                    if r in CALL_CLOBBER:
                        del regs[r]
            else:
                regs.pop(rd, None)
        elif op in (0x08, 0x0A, 0x0B, 0x0C, 0x0E, 0x18, 0x19,
                    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x1F):
            regs.pop(rt, None)

    # prefix-sum the crossing counts
    cross = [0] * (n + 1)
    acc = 0
    for i in range(n + 1):
        acc += delta[i]
        cross[i] = acc
    sc.cross = cross
    return sc


def is_padding(w):
    return w == 0x00000000


def preceded_by_terminator(sc, idx):
    """True when idx looks like it follows the end of a function."""
    if idx == 0:
        return True
    j = idx - 1
    while j >= 0 and is_padding(sc.seg.words[j]):
        j -= 1
    if j < 0:
        return True
    # j is either the terminator itself or its delay slot
    if sc.term[j]:
        return True
    if j >= 1 and sc.term[j - 1]:
        return True
    return False


def branch_crosses(sc, idx):
    return sc.cross[idx] > 0


# --------------------------------------------------------------------------- #
# candidate collection
# --------------------------------------------------------------------------- #

REASON_RANK = {"entry": 0, "jal": 1, "xjal": 2, "ptr": 3, "seg": 4, "gap": 5}


def collect(segments, scans, min_ptr_uses=1):
    """Return {segment name: {vram: reason}} plus global jal bookkeeping."""
    # Which segments overlap another code segment in VRAM (shared overlay slot)?
    ambiguous = set()
    for a in segments:
        for b in segments:
            if a is b:
                continue
            if a.text_start < b.text_end and b.text_start < a.text_end:
                ambiguous.add(a.name)
                break

    all_jal = collections.defaultdict(collections.Counter)   # target -> {seg: n}
    for seg in segments:
        for tgt, cnt in scans[seg.name].jal_targets.items():
            all_jal[tgt][seg.name] += cnt

    starts = {}
    for seg in segments:
        sc = scans[seg.name]
        cand = {}

        def add(vram, reason):
            if vram % 4 or not (seg.text_start <= vram < seg.text_end):
                return
            old = cand.get(vram)
            if old is None or REASON_RANK[reason] < REASON_RANK[old]:
                cand[vram] = reason

        add(seg.text_start, "seg")
        if seg.rom == ENTRYPOINT_ROM:
            add(ENTRYPOINT_VRAM, "entry")

        # own jal targets: definitionally correct for this image
        for tgt in sc.jal_targets:
            add(tgt, "jal")

        # foreign jal targets landing in this image's text
        for tgt, srcs in all_jal.items():
            if not (seg.text_start <= tgt < seg.text_end):
                continue
            if tgt in sc.jal_targets:
                continue
            idx = (tgt - seg.text_start) // 4
            if seg.name in ambiguous:
                # only believe it if it also looks like a boundary here
                if branch_crosses(sc, idx) or not preceded_by_terminator(sc, idx):
                    continue
            add(tgt, "xjal")

        # function pointers built with lui/addiu
        for tgt, cnt in sc.ptr_consts.items():
            if cnt < min_ptr_uses or tgt in cand:
                continue
            idx = (tgt - seg.text_start) // 4
            if branch_crosses(sc, idx) or not preceded_by_terminator(sc, idx):
                continue
            add(tgt, "ptr")

        # first non-nop after a `jr $ra` + delay slot
        for i in sc.jr_ra:
            j = i + 2
            while j < seg.n and is_padding(seg.words[j]):
                j += 1
            if j >= seg.n:
                continue
            vram = seg.text_start + j * 4
            if vram in cand:
                continue
            if branch_crosses(sc, j):
                continue
            add(vram, "gap")

        starts[seg.name] = cand

    return starts, all_jal, ambiguous


# --------------------------------------------------------------------------- #
# boundary construction + data-in-text rejection
# --------------------------------------------------------------------------- #

def build_functions(seg, sc, cand, min_valid=0.90):
    """Turn a {vram: reason} candidate set into sorted function records."""
    keys = sorted(cand)
    funcs = []
    dropped = []
    for k, vram in enumerate(keys):
        end = keys[k + 1] if k + 1 < len(keys) else seg.text_end
        i0 = (vram - seg.text_start) // 4
        i1 = (end - seg.text_start) // 4
        reason = cand[vram]
        nw = i1 - i0
        nvalid = sum(sc.valid[i0:i1])
        has_term = any(sc.term[i0:i1])
        ratio = float(nvalid) / nw if nw else 1.0
        rec = {
            "vram": vram,
            "size": (end - vram),
            "how": reason,
            "valid": round(ratio, 4),
            "term": bool(has_term),
        }
        # Data-in-text: only ever discard regions that nothing points at.
        if reason == "gap" and (ratio < min_valid or not has_term):
            rec["reject"] = "data-in-text" if ratio < min_valid else "no-terminator"
            dropped.append(rec)
            continue
        funcs.append(rec)

    # Re-close boundaries after drops so functions stay contiguous.
    for k, f in enumerate(funcs):
        end = funcs[k + 1]["vram"] if k + 1 < len(funcs) else seg.text_end
        f["size"] = end - f["vram"]
    return funcs, dropped


# --------------------------------------------------------------------------- #
# no-yield busy-wait detection
# --------------------------------------------------------------------------- #
#
# ultramodern schedules recompiled threads cooperatively: messages posted by
# native threads (VI retrace, SP/DP done, PI) are only drained when a game
# thread enters osSendMesg/osRecvMesg/osJamMesg or blocks.  A recompiled thread
# that polls a memory flag in a tight loop therefore wedges the entire runtime,
# where real hardware would have preempted it from an RCP interrupt.
#
# N64Recomp already rewrites the unconditional `b .` form into pause_self(), so
# what is left to find is the conditional form.  The signature that separates a
# poll from an ordinary data loop is that the polled address is loop-invariant:
#
#   * the loop body is short and contains no call, no store and no other branch,
#   * it performs at least one load, and
#   * no load's base register is written inside the body (a memcpy/strlen style
#     loop always advances its pointer, so it is excluded).
#
# gen_syms.py turns each hit into a [[patches.hook]] that calls yield_self_1ms().

LOAD_OPS = frozenset([0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x31, 0x35, 0x37])
STORE_OPS = frozenset([0x28, 0x29, 0x2B, 0x2C, 0x2D, 0x2F, 0x39, 0x3D])
MAX_SPIN_BODY = 12


def _writes_gpr(w):
    """Destination GPR of instruction word `w`, or None."""
    op = w >> 26
    if op == 0:                       # SPECIAL: R-type writes rd, except jr/jalr-less
        funct = w & 0x3F
        if funct == 0x08:             # jr
            return None
        if funct in (0x0C, 0x0D):     # syscall / break
            return None
        return (w >> 11) & 0x1F
    if op == 1:                       # REGIMM: branches (bltz/bgez[al])
        return 31 if ((w >> 16) & 0x1E) == 0x10 else None
    if op in (0x02, 0x03):            # j / jal
        return 31 if op == 3 else None
    if op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17):
        return None                   # branches
    if op in (0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x18, 0x19,
              0x11, 0x12, 0x13):
        # addi/addiu/slti/sltiu/andi/ori/xori/lui/daddi/daddiu; COPz writes are
        # only relevant for mtc/mfc which we treat conservatively below.
        if op in (0x11, 0x12, 0x13):
            return (w >> 16) & 0x1F if ((w >> 21) & 0x1F) == 0 else None
        return (w >> 16) & 0x1F
    if op in LOAD_OPS:
        return (w >> 16) & 0x1F
    return None


def leaf_functions(segments, funcs_by_seg):
    """vram -> True when every function starting there makes no calls at all.

    A leaf cannot reach osRecvMesg/osSendMesg/osYieldThread, so calling one from
    inside a loop still leaves the loop unable to yield.  Overlay slots are
    shared, so a vram only counts as a leaf if *all* images agree.
    """
    leaf = {}
    for seg in segments:
        base = seg.text_start
        for f in funcs_by_seg[seg.name]:
            i0 = (f["vram"] - base) // 4
            i1 = min(i0 + f["size"] // 4, seg.n)
            calls = any((seg.words[j] >> 26) in (0x02, 0x03) or
                        ((seg.words[j] >> 26) == 0 and (seg.words[j] & 0x3F) == 0x09)
                        for j in range(i0, i1))
            leaf[f["vram"]] = leaf.get(f["vram"], True) and not calls
    return leaf


def find_spin_loops(seg, funcs, leaf):
    """Locate no-yield polling loops; returns [{func, branch, target, ...}]."""
    base = seg.text_start
    W = seg.words
    out = []
    for f in funcs:
        i0 = (f["vram"] - base) // 4
        i1 = i0 + f["size"] // 4
        for i in range(i0, min(i1, seg.n)):
            w = W[i]
            op = w >> 26
            is_cond = op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17) or \
                (op == 1 and ((w >> 16) & 0x1E) != 0x10)
            if not is_cond:
                continue
            off = w & 0xFFFF
            if not off & 0x8000:          # forward branch: not a loop back-edge
                continue
            target = base + (i + 1 + (off - 0x10000)) * 4
            if target < f["vram"] or target > base + i * 4:
                continue
            t = (target - base) // 4
            body = list(range(t, i + 2))  # branch + its delay slot included
            if len(body) > MAX_SPIN_BODY or i + 1 >= seg.n:
                continue
            bad = False
            written_any = set()
            for j in body:
                bw = W[j]
                bop = bw >> 26
                if j != i:
                    if bop == 0x03:
                        # A call is tolerated only when the callee is a leaf:
                        # a leaf cannot reach an OS primitive, so the loop is
                        # still unable to yield. Anything else (including an
                        # unknown target) is assumed to be able to block.
                        tgt = ((base + (j + 1) * 4) & 0xF0000000) | ((bw & 0x03FFFFFF) << 2)
                        if not leaf.get(tgt, False):
                            bad = True
                            break
                        written_any |= CALL_CLOBBER
                        continue
                    other_branch = bop in (0x01, 0x02, 0x04, 0x05, 0x06,
                                           0x07, 0x14, 0x15, 0x16, 0x17)
                    jr_jalr = bop == 0 and (bw & 0x3F) in (0x08, 0x09)
                    if other_branch or jr_jalr:
                        bad = True
                        break
                if bop in STORE_OPS:
                    bad = True
                    break
                d = _writes_gpr(bw)
                if d:
                    written_any.add(d)
            if bad:
                continue
            # If the loop calls something, the call must not be fed with a value
            # the loop computed: `while (x) { unlink(x); link(x); }` walks a data
            # structure and only looks like a poll. A real poll either takes no
            # argument or a constant one (e.g. the PRNG the KEMCO logo screens
            # spin on).
            if any((W[j] >> 26) == 0x03 for j in body):
                for j in body:
                    bw = W[j]
                    bop = bw >> 26
                    d = _writes_gpr(bw)
                    if d is None or not (4 <= d <= 7):
                        continue
                    src = (bw >> 21) & 0x1F
                    const_src = bop == 0x0F or (bop in (0x09, 0x0D, 0x0C, 0x0E) and src == 0)
                    if not const_src:
                        bad = True
                        break
            if bad:
                continue
            # One forward pass over the body: every load must address either a
            # register the body never writes, or an address the body itself
            # materialises from immediates (lui / addiu from $zero).
            const_regs = set()
            nloads = 0
            for j in body:
                bw = W[j]
                bop = bw >> 26
                rs = (bw >> 21) & 0x1F
                rt = (bw >> 16) & 0x1F
                if bop in LOAD_OPS:
                    nloads += 1
                    if rs not in const_regs and rs in written_any:
                        bad = True
                        break
                if bop == 0x03:                       # jal: clobbers caller-saved
                    const_regs -= CALL_CLOBBER
                elif bop == 0x0F:                     # lui
                    const_regs.add(rt)
                elif bop in (0x09, 0x0D, 0x0C, 0x0E) and (rs == 0 or rs in const_regs):
                    const_regs.add(rt)                # addiu/ori/andi/xori
                else:
                    d = _writes_gpr(bw)
                    if d:
                        const_regs.discard(d)
            if bad or not nloads:
                continue
            out.append({
                "func": f["vram"],
                "branch": base + i * 4,
                "target": target,
                "body": len(body),
            })
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", default=DEFAULT_ROM)
    ap.add_argument("--segments", default=DEFAULT_SEGMENTS)
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--report", default=DEFAULT_REPORT)
    ap.add_argument("--min-valid", type=float, default=0.90,
                    help="instruction-validity floor for unreferenced regions")
    ap.add_argument("--min-ptr-uses", type=int, default=1)
    ap.add_argument("-q", "--quiet", action="store_true")
    args = ap.parse_args(argv)

    rom_data = open(args.rom, "rb").read()
    segments = load_code_segments(args.segments, rom_data)
    scans = {s.name: scan_segment(s) for s in segments}
    starts, all_jal, ambiguous = collect(segments, scans,
                                         min_ptr_uses=args.min_ptr_uses)

    result = {"segments": [], "stats": {}}
    dropped_all = []
    built = {}
    for seg in segments:
        funcs, dropped = build_functions(seg, scans[seg.name], starts[seg.name],
                                         min_valid=args.min_valid)
        built[seg.name] = funcs
        dropped_all.append((seg.name, dropped))
    leaf = leaf_functions(segments, built)
    for seg in segments:
        funcs = built[seg.name]
        dropped = dict(dropped_all)[seg.name]
        result["segments"].append({
            "name": seg.name,
            "rom": seg.rom,
            "size": seg.size,
            "vram": seg.vram,
            "text_start": seg.text_start,
            "text_end": seg.text_end,
            "ambiguous_slot": seg.name in ambiguous,
            "functions": funcs,
            "rejected": dropped,
            "spin_loops": find_spin_loops(seg, funcs, leaf),
        })

    # ---- global coverage check: every jal target must be somebody's function ----
    claimed = collections.defaultdict(set)
    for s in result["segments"]:
        for f in s["functions"]:
            claimed[f["vram"]].add(s["name"])

    unclaimed = []
    for tgt, srcs in sorted(all_jal.items()):
        if tgt in claimed:
            continue
        containers = [s for s in result["segments"]
                      if s["text_start"] <= tgt < s["text_end"]]
        unclaimed.append((tgt, dict(srcs), [s["name"] for s in containers]))

    # Force-add the ones we can: a jal target inside a known text range must be a
    # function somewhere or N64Recomp aborts with NoMatch.
    forced = []
    for tgt, srcs, containers in unclaimed:
        if not containers:
            continue
        for s in result["segments"]:
            if s["name"] not in containers:
                continue
            s["functions"].append({"vram": tgt, "size": 0, "how": "forced",
                                   "valid": 1.0, "term": True})
            forced.append((tgt, s["name"]))
        s_names = containers

    # rebuild sizes for segments we touched
    forced_segs = set(name for _, name in forced)
    for s in result["segments"]:
        if s["name"] not in forced_segs:
            continue
        s["functions"].sort(key=lambda f: f["vram"])
        for k, f in enumerate(s["functions"]):
            end = (s["functions"][k + 1]["vram"] if k + 1 < len(s["functions"])
                   else s["text_end"])
            f["size"] = end - f["vram"]

    outside = [(t, srcs) for t, srcs, c in unclaimed if not c]

    total = sum(len(s["functions"]) for s in result["segments"])
    by_how = collections.Counter()
    for s in result["segments"]:
        for f in s["functions"]:
            by_how[f["how"]] += 1
    result["stats"] = {
        "total_functions": total,
        "by_how": dict(by_how),
        "segments": len(result["segments"]),
        "forced": [{"vram": t, "segment": n} for t, n in forced],
        "jal_targets_outside_any_text": [
            {"vram": t, "sources": dict(s)} for t, s in outside],
    }

    with open(args.out, "w") as fh:
        json.dump(result, fh, indent=1, sort_keys=True)
        fh.write("\n")

    lines = []
    lines.append("segment              text range              funcs  jal  xjal  ptr  gap  forced  rejected")
    for s in result["segments"]:
        c = collections.Counter(f["how"] for f in s["functions"])
        lines.append("%-20s %08X..%08X %6d %5d %5d %4d %4d %6d %8d" % (
            s["name"], s["text_start"], s["text_end"], len(s["functions"]),
            c["jal"] + c["entry"] + c["seg"], c["xjal"], c["ptr"], c["gap"],
            c["forced"], len(s["rejected"])))
    lines.append("")
    lines.append("total functions: %d" % total)
    lines.append("by how: %s" % dict(by_how))
    lines.append("forced (unclaimed jal targets): %d" % len(forced))
    if outside:
        lines.append("jal targets outside every text range: %d" % len(outside))
        for t, srcs in outside[:40]:
            lines.append("  %08X  from %s" % (t, dict(srcs)))
    lines.append("")
    for name, dropped in dropped_all:
        if not dropped:
            continue
        lines.append("rejected regions in %s:" % name)
        for d in dropped:
            lines.append("  %08X size %6X  %s (valid %.2f, term=%s)" % (
                d["vram"], d["size"], d["reject"], d["valid"], d["term"]))
    report = "\n".join(lines) + "\n"
    with open(args.report, "w") as fh:
        fh.write(report)
    if not args.quiet:
        sys.stdout.write(report)
    return 0


if __name__ == "__main__":
    sys.exit(main())
