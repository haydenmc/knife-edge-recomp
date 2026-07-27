#!/usr/bin/env python3
"""Stage 2 of the ROM -> symbols pipeline: assign libultra / libc names.

n64sym is used as the seed oracle: RAM images are synthesised at 0x80000000 and
scanned with `-s -t -f splat`.  Because several overlay images share one VRAM
slot, the code segments are partitioned into non-overlapping groups and one
image is built per group.

n64sym's raw output is noisy (data symbols, sub-object `*_text_0038` labels,
64DD/iQue/rmon families, and duplicate names at unrelated addresses), so every
hit goes through four gates:

  1. structural gates - must be a function start found by find_functions.py,
     must not be a sub-object label, must not be from an implausible family;
  2. a per-segment "libultra cluster floor": the lowest hit that has >= 3 other
     hits within +/-0x800.  Everything below that floor in the boot segment is
     game code that the signature scanner mislabelled;
  3. duplicate resolution by neighbourhood density;
  4. hard structural verification for the runtime-critical names, which is the
     only gate that can override the ones above.

Only names in N64Recomp's `reimplemented_funcs` / `ignored_funcs` sets are
actually dangerous to get wrong (the body is replaced by librecomp's HLE, or no
body is emitted at all); `renamed_funcs` and unknown names are still recompiled
verbatim, so a mislabel there is cosmetic.  The gates above are tuned with that
asymmetry in mind and every rejection is recorded in the report.

Output: analysis/out/libultra_names.json + analysis/out/libultra_report.txt
"""

import argparse
import collections
import json
import os
import re
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_ROM = os.path.join(ROOT, "build", "knife_edge.z64")
DEFAULT_FUNCS = os.path.join(ROOT, "analysis", "out", "functions.json")
DEFAULT_N64SYM = os.path.join(ROOT, "deps", "n64sym", "bin", "n64sym")
DEFAULT_SYMLISTS = os.path.join(ROOT, "deps", "N64Recomp", "src", "symbol_lists.cpp")
DEFAULT_OUT = os.path.join(ROOT, "analysis", "out", "libultra_names.json")
DEFAULT_REPORT = os.path.join(ROOT, "analysis", "out", "libultra_report.txt")
DEFAULT_CACHE = os.path.join(ROOT, "analysis", "out", "n64sym")

RAM_SIZE = 0x00400000
RAM_BASE = 0x80000000

# Anchors recovered structurally in analysis/out/segment_map.md (§b.1/§b.2).
# Both are re-verified at run time before any name derived from them is trusted.
DMA_WRAPPER = 0x800D1D10        # func(devAddr, dramAddr, size), 6 call sites
CODE_SEG_LOADER = 0x800C38C8    # 8-word descriptor loader
BOOT_BSS = (0x800EEF50, 0x8016ABF0)   # DMA_WRAPPER reads __CartRomHandle here

SUBSYM_RE = re.compile(r"_(text|data|bss|rodata)_[0-9A-Fa-f]{4,8}$")
BOGUS_PREFIXES = ("osBb", "leo", "rmon", "__rmon", "n_al", "__osBb")

# Names n64sym cannot produce (it only emits a sub-object label, or no label at
# all) but that must be assigned anyway, because leaving them unnamed makes
# N64Recomp emit a body that calls into `ignored_funcs` helpers which by
# contract have neither a generated body nor a librecomp implementation.
# Each entry is only applied if the function at `vram` actually calls every
# listed already-accepted name.
MANUAL_NAMES = [
    (0x800D73E0, "osInitialize",
     ["osUnmapTLBAll", "osMapTLBRdb", "__osSetSR", "__osSpRawWriteIo",
      "osPiRawReadIo"],
     "segment_map.md §c: osUnmapTLBAll/osMapTLBRdb have exactly one caller each, "
     "at 0x800D7560/0x800D7568, i.e. inside this function; the SR/SP/PI raw-IO "
     "sequence is osInitialize's body"),
    (0x800DA4F0, "viMgrMain",
     ["__osViSwapContext", "__osTimerInterrupt"],
     "vimgr.c object layout osCreateViManager(800DA370) < this < "
     "osViSetEvent(800DA680); n64sym labels it vimgr_text_0180"),
    (0x800DB2F8, "_MakeMotorData",
     ["__osContAddressCrc"],
     "motor.c object layout __osMotorAccess(800DB190) < this < "
     "osMotorInit(800DB404); builds the 0xFF/0x23/0x01/0x03/0xC0 rumble PIF "
     "block and CRCs address 0x600; n64sym labels it motor_text_0168"),
]

# Names whose correctness is load-bearing at run time (spec stage 2.3).
RUNTIME_CRITICAL = [
    "osRecvMesg", "osSendMesg", "osCreateThread", "osStartThread",
    "osPiStartDma", "osEPiStartDma", "osSpTaskLoad", "osSpTaskStartGo",
    "osViSwapBuffer", "osAiSetNextBuffer", "osContInit", "osContStartReadData",
    "osGetCount", "osInvalDCache", "osInvalICache", "osWritebackDCache",
    "osCreateMesgQueue", "osSetEventMesg", "osVirtualToPhysical",
]


# --------------------------------------------------------------------------- #
# N64Recomp's built-in name sets
# --------------------------------------------------------------------------- #

def load_symbol_lists(path):
    """Parse reimplemented/ignored/renamed name sets out of symbol_lists.cpp."""
    text = open(path).read()
    sets = {}
    for key in ("reimplemented_funcs", "ignored_funcs", "renamed_funcs"):
        m = re.search(re.escape(key) + r"\s*\{(.*?)\n\};", text, re.S)
        if not m:
            raise RuntimeError("could not parse %s from %s" % (key, path))
        sets[key] = set(re.findall(r'"([^"]+)"', m.group(1)))
    return sets


# --------------------------------------------------------------------------- #
# n64sym driving
# --------------------------------------------------------------------------- #

def partition_segments(segments):
    """Greedily split segments into VRAM-disjoint groups."""
    groups = []
    for seg in sorted(segments, key=lambda s: (-s["size"], s["rom"])):
        for g in groups:
            if all(seg["vram"] >= o["vram"] + o["size"] or
                   o["vram"] >= seg["vram"] + seg["size"] for o in g):
                g.append(seg)
                break
        else:
            groups.append([seg])
    return groups


def run_n64sym(rom_data, group, gi, n64sym, cache_dir, refresh):
    out_path = os.path.join(cache_dir, "group%02d.txt" % gi)
    img_path = os.path.join(cache_dir, "group%02d.bin" % gi)
    if refresh or not os.path.exists(out_path):
        img = bytearray(RAM_SIZE)
        for seg in group:
            off = seg["vram"] - RAM_BASE
            img[off:off + seg["size"]] = rom_data[seg["rom"]:seg["rom"] + seg["size"]]
        with open(img_path, "wb") as fh:
            fh.write(img)
        subprocess.run([n64sym, img_path, "-s", "-t", "-f", "splat",
                        "-o", out_path], check=True,
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        os.remove(img_path)
    hits = []
    for line in open(out_path):
        for m in re.finditer(r"([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+);", line):
            hits.append((m.group(1), int(m.group(2), 16)))
    return hits


# --------------------------------------------------------------------------- #
# structural verification helpers
# --------------------------------------------------------------------------- #

class Boot(object):
    """Random access to the boot segment's words + its detected functions."""

    def __init__(self, rom_data, seg):
        self.vram = seg["vram"]
        self.rom = seg["rom"]
        self.size = seg["size"]
        self.text_start = seg["text_start"]
        self.text_end = seg["text_end"]
        self.data = rom_data
        self.funcs = {f["vram"]: f["size"] for f in seg["functions"]}
        self.starts = sorted(self.funcs)

    def word(self, v):
        return struct.unpack_from(">I", self.data, v - self.vram + self.rom)[0]

    def words(self, v, n):
        return struct.unpack_from(">%dI" % n, self.data, v - self.vram + self.rom)

    def func_words(self, v):
        n = self.funcs.get(v)
        if n is None:
            return ()
        return self.words(v, n // 4)

    def is_start(self, v):
        return v in self.funcs

    def jals(self, v):
        """Ordered jal targets inside the function starting at v."""
        out = []
        for i, w in enumerate(self.func_words(v)):
            if w >> 26 == 3:
                pc = v + i * 4
                out.append(((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2))
        return out

    def consts(self, v):
        """Addresses materialised by lui+addiu/ori inside function v."""
        regs = {}
        out = set()
        for i, w in enumerate(self.func_words(v)):
            op = w >> 26
            rs = (w >> 21) & 0x1F
            rt = (w >> 16) & 0x1F
            imm = w & 0xFFFF
            simm = imm - 0x10000 if imm & 0x8000 else imm
            if op == 0x0F:
                regs[rt] = imm << 16
            elif op == 0x09 and rs in regs:
                regs[rt] = (regs[rs] + simm) & 0xFFFFFFFF
                out.add(regs[rt])
            elif op == 0x0D and rs in regs:
                regs[rt] = regs[rs] | imm
                out.add(regs[rt])
            elif op in (0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B,
                        0x31, 0x35, 0x39, 0x3D) and rs in regs:
                out.add((regs[rs] + simm) & 0xFFFFFFFF)
            elif op == 0x0F:
                pass
        return out

    def cache_ops(self, v):
        return set((w >> 16) & 0x1F for w in self.func_words(v) if w >> 26 == 0x2F)

    def immediates(self, v):
        """All 16-bit immediate fields of I-type instructions in function v."""
        out = collections.Counter()
        for w in self.func_words(v):
            op = w >> 26
            if 0x08 <= op <= 0x0F or 0x20 <= op <= 0x3F:
                out[w & 0xFFFF] += 1
        return out

    def loads_offset_from(self, v, base_reg_arg, offset):
        """True if some lw/lhu/lbu in v uses the given immediate offset."""
        for w in self.func_words(v):
            op = w >> 26
            if op in (0x20, 0x21, 0x23, 0x24, 0x25) and (w & 0xFFFF) == offset:
                return True
        return False

    def stores_offset(self, v, offset):
        for w in self.func_words(v):
            op = w >> 26
            if op in (0x28, 0x29, 0x2B) and (w & 0xFFFF) == offset:
                return True
        return False


def verify_anchors(boot):
    """Re-derive the DMA wrapper chain documented in segment_map.md §b.1."""
    notes = []
    ok = True
    if not boot.is_start(DMA_WRAPPER):
        return False, ["%08X is not a detected function start" % DMA_WRAPPER], {}
    jals = boot.jals(DMA_WRAPPER)
    if len(jals) != 4:
        ok = False
        notes.append("DMA wrapper %08X has %d jals, expected 4" %
                     (DMA_WRAPPER, len(jals)))
    handles = [c for c in boot.consts(DMA_WRAPPER) if BOOT_BSS[0] <= c < BOOT_BSS[1]]
    if not handles:
        ok = False
        notes.append("DMA wrapper reads no pointer out of the boot .bss")
    else:
        notes.append("DMA wrapper reads cart rom handle from %s" %
                     ", ".join("%08X" % h for h in sorted(handles)))
    mapping = {}
    if ok:
        mapping = {
            jals[0]: "osCreateMesgQueue",
            jals[1]: "osInvalDCache",
            jals[2]: "osEPiStartDma",
            jals[3]: "osRecvMesg",
        }
        notes.append("DMA wrapper %08X -> osCreateMesgQueue %08X, osInvalDCache "
                     "%08X, osEPiStartDma %08X, osRecvMesg %08X" %
                     ((DMA_WRAPPER,) + tuple(jals)))
    # the 8-word descriptor loader: osInvalICache, osInvalDCache, dma wrapper
    if boot.is_start(CODE_SEG_LOADER):
        lj = boot.jals(CODE_SEG_LOADER)
        if len(lj) == 3 and lj[2] == DMA_WRAPPER:
            mapping.setdefault(lj[0], "osInvalICache")
            mapping.setdefault(lj[1], "osInvalDCache")
            notes.append("code-segment loader %08X -> osInvalICache %08X, "
                         "osInvalDCache %08X" % (CODE_SEG_LOADER, lj[0], lj[1]))
        else:
            notes.append("code-segment loader %08X jal chain unexpected: %s" %
                         (CODE_SEG_LOADER, ["%08X" % x for x in lj]))
    return ok, notes, mapping


# Each verifier: (boot, vram, named) -> (bool, evidence string)

def v_osGetCount(b, v, named):
    w = b.func_words(v)
    ok = len(w) >= 3 and w[0] == 0x40024800 and w[1] == 0x03E00008 and w[2] == 0
    return ok, "mfc0 v0,Count / jr ra / nop"


def v_osInvalICache(b, v, named):
    ops = b.cache_ops(v)
    imm = b.immediates(v)
    ok = ops == {0x00, 0x10} and imm.get(0x4000) and imm.get(0x1F)
    return bool(ok), "cache ops %s, icache size 0x4000, 32-byte lines" % sorted(ops)


def v_osInvalDCache(b, v, named):
    ops = b.cache_ops(v)
    imm = b.immediates(v)
    ok = 0x15 in ops and 0x01 in ops and imm.get(0x2000) and imm.get(0xF)
    return bool(ok), "cache ops %s (Hit_Invalidate_D), dcache 0x2000, 16-byte lines" % sorted(ops)


def v_osWritebackDCache(b, v, named):
    ops = b.cache_ops(v)
    imm = b.immediates(v)
    ok = ops == {0x01, 0x19} and imm.get(0x2000) and imm.get(0xF)
    return bool(ok), "cache ops %s (Hit_Writeback_D), dcache 0x2000" % sorted(ops)


def v_osCreateMesgQueue(b, v, named):
    w = b.func_words(v)
    ok = (len(w) >= 8 and w[-4] == 0xAC800008 and w[-3] == 0xAC80000C and
          w[-2] == 0x03E00008 or
          (0xAC800008 in w and 0xAC80000C in w and 0xAC860010 in w and
           0xAC850014 in w))
    return bool(ok), "sw zero,8/0xC(a0); sw a2,0x10(a0); sw a1,0x14(a0)"


def v_osVirtualToPhysical(b, v, named):
    c = b.consts(v)
    imm = b.immediates(v)
    ok = imm.get(0x8000) and imm.get(0xA000) and imm.get(0x1FFF) and imm.get(0xFFFF)
    return bool(ok), "KSEG0/KSEG1 range test + 0x1FFFFFFF mask"


def v_osCreateThread(b, v, named):
    cleanup = named.get("__osCleanupThread")
    c = b.consts(v)
    ok = (b.stores_offset(v, 0x14) and b.stores_offset(v, 0x38) and
          b.stores_offset(v, 0x3C) and b.stores_offset(v, 0xF4))
    ev = "stores id@0x14, entry@0x38/0x3C, sp@0xF0/0xF4"
    if cleanup is not None and cleanup in c:
        ev += ", plants __osCleanupThread %08X in the thread frame" % cleanup
    elif ok:
        ok = len([x for x in c if b.text_start <= x < b.text_end]) > 0
        ev += ", plants an in-text return address"
    return bool(ok), ev


def v_osStartThread(b, v, named):
    w = b.func_words(v)
    # lhu <r>, 0x10(thread) then compare against OS_STATE_STOPPED(1)/WAITING(8)
    has_lhu = any((x >> 26) == 0x25 and (x & 0xFFFF) == 0x10 for x in w)
    imm = b.immediates(v)
    ok = has_lhu and imm.get(1) and imm.get(8)
    return bool(ok), "lhu state@0x10; compares OS_STATE_STOPPED(1)/OS_STATE_WAITING(8)"


def v_osSpTaskStartGo(b, v, named):
    imm = b.immediates(v)
    ok = bool(imm.get(0x125))
    return ok, "writes SP_STATUS 0x125 (clr_halt|clr_broke|set_intr_break)"


def v_osSpTaskLoad(b, v, named):
    imm = b.immediates(v)
    # reads OSTask.ucode_boot(+0x38)[0xBFC] and kicks SP_STATUS 0x2B00
    ok = imm.get(0x2B00) and imm.get(0xBFC) and b.loads_offset_from(v, 4, 0x38)
    return bool(ok), ("reads OSTask.ucode_boot(+0x38)+0xBFC, writes SP_STATUS "
                      "0x2B00, DMAs to IMEM 0x04001000")


def v_osViSwapBuffer(b, v, named):
    jals = b.jals(v)
    ok = b.stores_offset(v, 0x04) and len(jals) >= 2
    return bool(ok), "__osDisableInt, store framebuffer into __osViNext->framep(+4)"


def v_osAiSetNextBuffer(b, v, named):
    w = b.func_words(v)
    ok = any(x == 0x25D8E000 or ((x >> 26) == 0x09 and (x & 0xFFFF) == 0xE000)
             for x in w)
    return bool(ok), "AI hardware-bug workaround: addiu <r>, <r>, -0x2000"


def v_osContInit(b, v, named):
    imm = b.immediates(v)
    ok = bool(imm.get(0xFF01) or imm.get(0x1)) and len(b.jals(v)) >= 3
    return bool(ok), "PIF ram command setup + >=3 helper calls"


def v_osContStartReadData(b, v, named):
    ok = len(b.jals(v)) >= 3
    return bool(ok), "__osSiGetAccess / __osPackReadData / __osSiRawStartDma chain"


def v_osSendMesg(b, v, named):
    # distinguishes send from recv: send tests validCount(+8) against msgCount(+0x10)
    ok = b.loads_offset_from(v, 4, 0x08) and b.loads_offset_from(v, 4, 0x10)
    return bool(ok), "tests mq->validCount(+8) against mq->msgCount(+0x10) (queue-full test)"


def v_osSetEventMesg(b, v, named):
    tab = named.get("__osEventStateTab")
    c = b.consts(v)
    w = b.func_words(v)
    # sll rd, rt, 3  -> OSEventState is 8 bytes wide
    shifts = any((x >> 26) == 0 and (x & 0x3F) == 0 and ((x >> 6) & 0x1F) == 3
                 for x in w)
    ok = shifts and b.stores_offset(v, 0x00) and b.stores_offset(v, 0x04)
    ev = "indexes an 8-byte-per-entry table by event<<3, stores mq@+0/msg@+4"
    if tab is not None:
        if tab in c:
            ev += "; table base is __osEventStateTab %08X" % tab
        else:
            ok = False
            ev += "; expected table base __osEventStateTab %08X not referenced" % tab
    return bool(ok), ev


def v_osEPiStartDma(b, v, named):
    imm = b.immediates(v)
    ok = (b.stores_offset(v, 0x14) and imm.get(0x0F) and imm.get(0xFFFF))
    return bool(ok), ("stores piHandle into OSIoMesg+0x14, sets hdr.type 0xF/0x10, "
                      "returns -1 when __osPiDevMgr is inactive")


VERIFIERS = {
    "osGetCount": v_osGetCount,
    "osInvalICache": v_osInvalICache,
    "osInvalDCache": v_osInvalDCache,
    "osWritebackDCache": v_osWritebackDCache,
    "osCreateMesgQueue": v_osCreateMesgQueue,
    "osVirtualToPhysical": v_osVirtualToPhysical,
    "osCreateThread": v_osCreateThread,
    "osStartThread": v_osStartThread,
    "osSpTaskStartGo": v_osSpTaskStartGo,
    "osSpTaskLoad": v_osSpTaskLoad,
    "osViSwapBuffer": v_osViSwapBuffer,
    "osAiSetNextBuffer": v_osAiSetNextBuffer,
    "osContInit": v_osContInit,
    "osContStartReadData": v_osContStartReadData,
    "osSendMesg": v_osSendMesg,
    "osSetEventMesg": v_osSetEventMesg,
    "osEPiStartDma": v_osEPiStartDma,
}


# --------------------------------------------------------------------------- #
# filtering
# --------------------------------------------------------------------------- #

def cluster_floor(vrams, window=0x800, min_neighbours=3):
    """Lowest address that sits in a dense neighbourhood of other hits."""
    vs = sorted(vrams)
    for v in vs:
        n = sum(1 for o in vs if o != v and abs(o - v) <= window)
        if n >= min_neighbours:
            return v
    return None


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", default=DEFAULT_ROM)
    ap.add_argument("--functions", default=DEFAULT_FUNCS)
    ap.add_argument("--n64sym", default=DEFAULT_N64SYM)
    ap.add_argument("--symbol-lists", default=DEFAULT_SYMLISTS)
    ap.add_argument("--cache-dir", default=DEFAULT_CACHE)
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--report", default=DEFAULT_REPORT)
    ap.add_argument("--refresh", action="store_true",
                    help="re-run n64sym even if cached output exists")
    ap.add_argument("-q", "--quiet", action="store_true")
    args = ap.parse_args(argv)

    rom_data = open(args.rom, "rb").read()
    funcs = json.load(open(args.functions))
    segments = funcs["segments"]
    by_name = {s["name"]: s for s in segments}
    sets = load_symbol_lists(args.symbol_lists)
    dangerous = sets["reimplemented_funcs"] | sets["ignored_funcs"]

    os.makedirs(args.cache_dir, exist_ok=True)
    groups = partition_segments(segments)

    raw = collections.defaultdict(list)     # segment -> [(name, vram)]
    for gi, group in enumerate(groups):
        hits = run_n64sym(rom_data, group, gi, args.n64sym, args.cache_dir,
                          args.refresh)
        for name, vram in hits:
            for seg in group:
                if seg["text_start"] <= vram < seg["text_end"]:
                    raw[seg["name"]].append((name, vram))
                    break

    rejects = []          # (segment, name, vram, reason)
    survivors = []        # (segment, name, vram)
    data_syms = {}        # name -> vram, for verifiers that want globals

    # collect every raw hit (incl. data ones) for verifier context
    all_hits = collections.Counter()
    for gi in range(len(groups)):
        path = os.path.join(args.cache_dir, "group%02d.txt" % gi)
        if not os.path.exists(path):
            continue
        for line in open(path):
            for m in re.finditer(r"([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+);", line):
                all_hits[(m.group(1), int(m.group(2), 16))] += 1
    for (name, vram), _ in all_hits.items():
        data_syms.setdefault(name, vram)

    for segname, hits in sorted(raw.items()):
        seg = by_name[segname]
        starts = set(f["vram"] for f in seg["functions"])
        stage = []
        for name, vram in sorted(set(hits)):
            if SUBSYM_RE.search(name):
                rejects.append((segname, name, vram, "sub-object label"))
            elif name.startswith(BOGUS_PREFIXES):
                rejects.append((segname, name, vram, "implausible family (64DD/iQue/rmon/n_audio)"))
            elif vram not in starts:
                rejects.append((segname, name, vram, "not a detected function start"))
            else:
                stage.append((name, vram))
        floor = cluster_floor([v for _, v in stage])
        if floor is None:
            for name, vram in stage:
                rejects.append((segname, name, vram, "no libultra cluster in segment"))
            continue
        for name, vram in stage:
            if vram < floor:
                rejects.append((segname, name, vram,
                                "below libultra cluster floor %08X" % floor))
            else:
                survivors.append((segname, name, vram))

    # ---- duplicate resolution -------------------------------------------- #
    accepted_vrams = [v for _, _, v in survivors]

    def density(v):
        return sum(1 for o in accepted_vrams if o != v and abs(o - v) <= 0x2000)

    by_nm = collections.defaultdict(list)
    for segname, name, vram in survivors:
        by_nm[name].append((segname, vram))

    names = {}            # (segment, vram) -> name
    for name, cands in sorted(by_nm.items()):
        if len(cands) == 1:
            names[cands[0]] = name
            continue
        scored = sorted(cands, key=lambda sv: (-density(sv[1]), sv[1]))
        best, second = scored[0], scored[1]
        if density(best[1]) == density(second[1]):
            for c in cands:
                rejects.append((c[0], name, c[1], "ambiguous duplicate, unresolved"))
            continue
        names[best] = name
        for c in scored[1:]:
            rejects.append((c[0], name, c[1],
                            "duplicate of %08X (lower neighbourhood density)" % best[1]))

    # one name per vram
    seen_vram = {}
    for key in sorted(names, key=lambda k: (k[0], k[1])):
        if key in seen_vram:
            continue
        seen_vram[key] = names[key]
    names = seen_vram

    # ---- structural verification ------------------------------------------ #
    boot = Boot(rom_data, by_name["boot"])
    anchors_ok, anchor_notes, anchor_map = verify_anchors(boot)

    named_addr = {}
    for (segname, vram), nm in names.items():
        if segname == "boot":
            named_addr.setdefault(nm, vram)
    for nm, v in [("__osEventStateTab", data_syms.get("__osEventStateTab")),
                  ("__osCleanupThread", named_addr.get("__osCleanupThread"))]:
        if v is not None:
            named_addr.setdefault(nm, v)

    # anchors win: they are derived from the call graph, not from signatures
    anchor_conflicts = []
    for vram, nm in sorted(anchor_map.items()):
        cur = names.get(("boot", vram))
        if cur == nm:
            continue
        if cur is not None:
            anchor_conflicts.append((vram, cur, nm))
        # drop any other address currently holding this name
        for key in [k for k, val in names.items() if val == nm]:
            del names[key]
        names[("boot", vram)] = nm

    # ---- manual names (call-graph derived, see MANUAL_NAMES) --------------- #
    manual_notes = []
    for vram, nm, needs, why in MANUAL_NAMES:
        if not boot.is_start(vram):
            manual_notes.append("%s %08X: not a detected function start, skipped"
                                % (nm, vram))
            continue
        want = {}
        for req in needs:
            hit = [v for (s, v), n in names.items() if s == "boot" and n == req]
            if hit:
                want[req] = hit[0]
        jals = set(boot.jals(vram))
        missing = [r for r in needs if r not in want or want[r] not in jals]
        if missing:
            manual_notes.append("%s %08X: rejected, does not call %s"
                                % (nm, vram, ", ".join(missing)))
            continue
        for key in [k for k, val in names.items() if val == nm]:
            del names[key]
        names[("boot", vram)] = nm
        manual_notes.append("%s %08X: accepted (calls %s) - %s"
                            % (nm, vram,
                               ", ".join("%s@%08X" % (r, want[r]) for r in needs),
                               why))

    verification = []
    for nm in RUNTIME_CRITICAL:
        vram = None
        for (segname, v), n in names.items():
            if n == nm:
                vram = v
                break
        if vram is None:
            verification.append((nm, None, "absent", "no surviving candidate"))
            continue
        status = "assigned"
        ev = ""
        if nm in anchor_map.values() and anchor_map.get(vram) == nm:
            status = "verified"
            ev = "call-graph anchor (segment_map.md §b.1/§b.2)"
        fn = VERIFIERS.get(nm)
        if fn is not None:
            ok, sig = fn(boot, vram, named_addr)
            ev = (ev + "; " if ev else "") + sig
            if ok:
                status = "verified"
            elif status != "verified":
                status = "unverified"
        verification.append((nm, vram, status, ev))

    # ---- output ------------------------------------------------------------ #
    out = {"segments": {}, "stats": {}}
    for (segname, vram), nm in sorted(names.items()):
        out["segments"].setdefault(segname, {})["0x%08X" % vram] = nm
    out["stats"] = {
        "accepted": len(names),
        "rejected": len(rejects),
        "n64sym_groups": len(groups),
        "dangerous_accepted": sum(1 for n in names.values() if n in dangerous),
        "anchors_verified": anchors_ok,
    }
    out["verification"] = [
        {"name": n, "vram": v, "status": s, "evidence": e}
        for n, v, s, e in verification]
    with open(args.out, "w") as fh:
        json.dump(out, fh, indent=1, sort_keys=True)
        fh.write("\n")

    L = []
    L.append("== call-graph anchors ==")
    for n in anchor_notes:
        L.append("  " + n)
    if anchor_conflicts:
        L.append("  anchor overrode n64sym at: " +
                 ", ".join("%08X %s->%s" % c for c in anchor_conflicts))
    L.append("")
    L.append("== manual (call-graph derived) names ==")
    for n in manual_notes:
        L.append("  " + n)
    L.append("")
    L.append("== runtime-critical names ==")
    for n, v, s, e in verification:
        L.append("  %-22s %-10s %-10s %s" %
                 (n, ("%08X" % v) if v else "-", s, e))
    L.append("")
    L.append("== accepted (%d) ==" % len(names))
    for (segname, vram), nm in sorted(names.items(), key=lambda kv: (kv[0][0], kv[0][1])):
        tag = ""
        if nm in sets["reimplemented_funcs"]:
            tag = " [reimplemented]"
        elif nm in sets["ignored_funcs"]:
            tag = " [ignored]"
        elif nm in sets["renamed_funcs"]:
            tag = " [renamed]"
        L.append("  %-12s %08X  %s%s" % (segname, vram, nm, tag))
    L.append("")
    L.append("== rejected (%d) ==" % len(rejects))
    for segname, nm, vram, why in sorted(rejects, key=lambda r: (r[0], r[2], r[1])):
        L.append("  %-12s %08X  %-32s %s" % (segname, vram, nm, why))
    report = "\n".join(L) + "\n"
    with open(args.report, "w") as fh:
        fh.write(report)
    if not args.quiet:
        sys.stdout.write("\n".join(L[:L.index("== accepted (%d) ==" % len(names))]) + "\n")
        print("accepted %d, rejected %d (full report: %s)" %
              (len(names), len(rejects), args.report))
    return 0


if __name__ == "__main__":
    sys.exit(main())
