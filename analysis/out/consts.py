#!/usr/bin/env python3
"""Scan boot code for immediate constants formed by lui + addiu/ori, report
ones that look like ROM offsets or unusual VRAM addresses."""
import struct, sys, bisect
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from dis import DATA, BOOT_ROM, BOOT_VRAM, BOOT_SIZE, rom_to_vram

N = BOOT_SIZE // 4
W = struct.unpack_from('>%dI' % N, DATA, BOOT_ROM)


def scan(lo, hi, code_end_vram=0x800E8578):
    res = []
    regs = {}
    n = (code_end_vram - BOOT_VRAM) // 4
    for i in range(n):
        w = W[i]
        v = BOOT_VRAM + i * 4
        op = w >> 26
        rs = (w >> 21) & 0x1F
        rt = (w >> 16) & 0x1F
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0F:      # lui
            regs[rt] = (imm << 16, v)
            if lo <= (imm << 16) < hi:
                res.append((v, imm << 16, 'lui'))
        elif op == 0x09:    # addiu
            if rs in regs:
                val = (regs[rs][0] + simm) & 0xFFFFFFFF
                regs[rt] = (val, regs[rs][1])
                if lo <= val < hi:
                    res.append((v, val, 'lui@%08X+addiu' % regs[rs][1]))
            elif rs == 0:
                regs[rt] = (simm & 0xFFFFFFFF, v)
                if lo <= (simm & 0xFFFFFFFF) < hi:
                    res.append((v, simm & 0xFFFFFFFF, 'li'))
            else:
                regs.pop(rt, None)
        elif op == 0x0D:    # ori
            if rs in regs:
                val = regs[rs][0] | imm
                regs[rt] = (val, regs[rs][1])
                if lo <= val < hi:
                    res.append((v, val, 'lui@%08X+ori' % regs[rs][1]))
            elif rs == 0:
                regs[rt] = (imm, v)
            else:
                regs.pop(rt, None)
        else:
            # crude: kill dest reg for common writing ops
            if op in (0x08, 0x0A, 0x0B, 0x0C, 0x0E, 0x23, 0x24, 0x25, 0x20, 0x21, 0x27, 0x1F):
                regs.pop(rt, None)
            elif op == 0:
                rd = (w >> 11) & 0x1F
                funct = w & 0x3F
                if funct == 0x25 and rt == 0 and rs in regs:  # or rd, rs, zero
                    regs[rd] = regs[rs]
                else:
                    regs.pop(rd, None)
            elif op == 3:  # jal - clobber caller-saved
                for r in list(regs):
                    if r in (2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 1, 31):
                        regs.pop(r, None)
    return res


if __name__ == '__main__':
    lo = int(sys.argv[1], 0)
    hi = int(sys.argv[2], 0)
    for v, val, how in scan(lo, hi):
        print('%08X  %08X  %s' % (v, val, how))
