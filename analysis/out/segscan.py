#!/usr/bin/env python3
"""Scan an arbitrary loaded segment for jal targets into the boot segment's
loader helpers, and recover the descriptor pointer in $a0."""
import struct, sys
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from dis import DATA, vram_to_rom

CALLER_SAVED = set(range(1, 16)) | {24, 25, 31}


def scan(rom, size, vram, targets):
    n = size // 4
    W = struct.unpack_from('>%dI' % n, DATA, rom)
    regs = {}
    out = []
    pending = None
    i = 0
    while i < n:
        w = W[i]
        v = vram + i * 4
        op = w >> 26
        rs = (w >> 21) & 0x1F
        rt = (w >> 16) & 0x1F
        rd = (w >> 11) & 0x1F
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0F:
            regs[rt] = imm << 16
        elif op == 0x09:
            if rs == 0:
                regs[rt] = simm & 0xFFFFFFFF
            elif rs in regs:
                regs[rt] = (regs[rs] + simm) & 0xFFFFFFFF
            else:
                regs.pop(rt, None)
        elif op == 0x0D:
            if rs == 0:
                regs[rt] = imm
            elif rs in regs:
                regs[rt] = regs[rs] | imm
            else:
                regs.pop(rt, None)
        elif op == 0 and (w & 0x3F) == 0x25:
            if rt == 0 and rs in regs:
                regs[rd] = regs[rs]
            elif rs == 0 and rt in regs:
                regs[rd] = regs[rt]
            else:
                regs.pop(rd, None)
        elif op == 3:
            t = ((v + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            if t in targets:
                pending = (t, v)
            i += 1
            continue
        else:
            if op in (0x08, 0x0A, 0x0B, 0x0C, 0x0E, 0x18, 0x19,
                      0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x1F, 0x27, 0x37):
                regs.pop(rt, None)
            elif op == 0:
                f = w & 0x3F
                if f not in (0x08, 0x09, 0x0C, 0x0D):
                    regs.pop(rd, None)
        i += 1
        if pending is not None:
            t, cs = pending
            out.append((cs, t, dict(regs)))
            for r in CALLER_SAVED:
                regs.pop(r, None)
            pending = None
    return out
