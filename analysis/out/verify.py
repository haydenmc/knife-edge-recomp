#!/usr/bin/env python3
"""Verify a claimed (rom_start, size, vram) mapping by checking that
jal targets and lui/addiu constants inside the region are self-consistent."""
import struct, sys, collections
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from dis import DATA
import rabbitizer


def analyze(rom, size, vram, label=''):
    n = size // 4
    W = struct.unpack_from('>%dI' % n, DATA, rom)
    valid = 0
    jr_ra = 0
    jal = collections.Counter()
    jal_in = 0
    jal_boot = 0
    jal_other = []
    consts = collections.Counter()
    regs = {}
    for i, w in enumerate(W):
        v = vram + i * 4
        ins = rabbitizer.Instruction(w, vram=v)
        if ins.isValid():
            valid += 1
        if w == 0x03E00008:
            jr_ra += 1
        op = w >> 26
        if op == 3:
            t = ((v + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
            jal[t] += 1
            if vram <= t < vram + size:
                jal_in += 1
            elif 0x800C2400 <= t < 0x800E8578:
                jal_boot += 1
            else:
                jal_other.append(t)
        rt = (w >> 16) & 0x1F
        rs = (w >> 21) & 0x1F
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0F:
            regs[rt] = imm << 16
        elif op == 0x09 and rs in regs:
            val = (regs[rs] + simm) & 0xFFFFFFFF
            regs[rt] = val
            if val >= 0x80000000:
                consts[val] += 1
        elif op in (0x23, 0x2B, 0x21, 0x25, 0x20, 0x24, 0x29, 0x28, 0x2D, 0x31, 0x39, 0x35, 0x3D) and rs in regs:
            val = (regs[rs] + simm) & 0xFFFFFFFF
            if val >= 0x80000000:
                consts[val] += 1
    print('== %s rom %06X..%06X -> %08X..%08X  (size %X)' % (
        label, rom, rom + size, vram, vram + size, size))
    print('   valid MIPS: %.1f%%  jr $ra: %d  jal: %d (in-seg %d, boot %d, other %d)' % (
        100.0 * valid / n, jr_ra, sum(jal.values()), jal_in, jal_boot, len(jal_other)))
    if jal_other:
        c = collections.Counter(jal_other)
        print('   other jal targets:', ['%08X x%d' % (a, k) for a, k in c.most_common(8)])
    # histogram of constants by 64K bucket
    b = collections.Counter()
    for a, k in consts.items():
        b[a >> 16] += k
    print('   const buckets:', ['%04X:%d' % (k, v) for k, v in sorted(b.items())])
    return valid / n


if __name__ == '__main__':
    analyze(int(sys.argv[1], 0), int(sys.argv[2], 0), int(sys.argv[3], 0))
