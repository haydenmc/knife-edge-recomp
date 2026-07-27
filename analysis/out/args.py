#!/usr/bin/env python3
"""Track lui/addiu/ori-formed register constants and report argument values at
jal call sites to a set of target functions."""
import struct, sys, bisect
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from dis import DATA, BOOT_ROM, BOOT_VRAM, BOOT_SIZE

N = BOOT_SIZE // 4
W = struct.unpack_from('>%dI' % N, DATA, BOOT_ROM)
CODE_END = 0x800E8578

CALLER_SAVED = set(range(1, 16)) | {24, 25, 31}


def run(targets, start=BOOT_VRAM, end=CODE_END, verbose=False):
    """targets: set of vram addresses. yields (callsite, target, {reg:val})"""
    regs = {}
    n = (end - start) // 4
    base = (start - BOOT_VRAM) // 4
    out = []
    pending = None  # (target, callsite, regs_snapshot_before_delay)
    i = 0
    while i < n:
        w = W[base + i]
        v = start + i * 4
        op = w >> 26
        rs = (w >> 21) & 0x1F
        rt = (w >> 16) & 0x1F
        rd = (w >> 11) & 0x1F
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm

        if op == 0x0F:
            regs[rt] = imm << 16
        elif op == 0x09:  # addiu
            if rs == 0:
                regs[rt] = simm & 0xFFFFFFFF
            elif rs in regs:
                regs[rt] = (regs[rs] + simm) & 0xFFFFFFFF
            else:
                regs.pop(rt, None)
        elif op == 0x0D:  # ori
            if rs == 0:
                regs[rt] = imm
            elif rs in regs:
                regs[rt] = regs[rs] | imm
            else:
                regs.pop(rt, None)
        elif op == 0 and (w & 0x3F) == 0x25:  # or
            if rt == 0 and rs in regs:
                regs[rd] = regs[rs]
            elif rs == 0 and rt in regs:
                regs[rd] = regs[rt]
            elif rs == 0 and rt == 0:
                regs[rd] = 0
            else:
                regs.pop(rd, None)
        elif op == 0 and (w & 0x3F) in (0x21, 0x20):  # addu/add
            if rt == 0 and rs in regs:
                regs[rd] = regs[rs]
            elif rs == 0 and rt in regs:
                regs[rd] = regs[rt]
            else:
                regs.pop(rd, None)
        elif op == 3:  # jal
            t = ((v + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if t in targets:
                pending = (t, v)
            # process delay slot then clobber
            i += 1
            continue
        elif op == 0 and (w & 0x3F) in (0x08, 0x09):  # jr/jalr
            pass
        else:
            if op in (0x08, 0x0A, 0x0B, 0x0C, 0x0E, 0x18, 0x19,
                      0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x1F, 0x27, 0x37):
                regs.pop(rt, None)
            elif op == 0:
                f = w & 0x3F
                if f not in (0x08, 0x09, 0x0C, 0x0D):
                    regs.pop(rd, None)
            elif op == 0x11 and rs in (4, 5):  # cop1 mtc1 etc - ignore
                pass
        i += 1
        # handle pending jal: the instruction just processed was the delay slot
        if pending is not None:
            t, cs = pending
            out.append((cs, t, dict(regs)))
            for r in CALLER_SAVED:
                regs.pop(r, None)
            regs.pop(2, None)
            regs.pop(3, None)
            pending = None
    return out


if __name__ == '__main__':
    tg = set(int(x, 0) for x in sys.argv[1:])
    for cs, t, regs in run(tg):
        a = {k: regs.get(k) for k in (4, 5, 6, 7)}
        print('%08X -> %08X  a0=%s a1=%s a2=%s a3=%s' % (
            cs, t,
            *['%08X' % a[k] if a[k] is not None else '?' for k in (4, 5, 6, 7)]))
