#!/usr/bin/env python3
"""Build function list + call graph for the boot segment."""
import struct, sys, json, collections
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from dis import DATA, BOOT_ROM, BOOT_VRAM, BOOT_SIZE, rom_to_vram, vram_to_rom

N = BOOT_SIZE // 4
W = struct.unpack_from('>%dI' % N, DATA, BOOT_ROM)

jal_targets = set()
jal_sites = collections.defaultdict(list)   # target -> [caller vram]
for i, w in enumerate(W):
    op = w >> 26
    v = BOOT_VRAM + i * 4
    if op == 3:  # jal
        t = ((v + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        jal_targets.add(t)
        jal_sites[t].append(v)

# function starts: jal targets, plus word after a jr $ra + delay slot
starts = set(jal_targets)
starts.add(BOOT_VRAM)
for i, w in enumerate(W):
    if w == 0x03E00008:  # jr $ra
        v = BOOT_VRAM + i * 4
        # next function starts after delay slot, skipping nops
        j = i + 2
        while j < N and W[j] == 0:
            j += 1
        if j < N:
            starts.add(BOOT_VRAM + j * 4)
starts = sorted(x for x in starts if BOOT_VRAM <= x < BOOT_VRAM + BOOT_SIZE)

# find end of code: last jr $ra
last_jr = max(i for i, w in enumerate(W) if w == 0x03E00008)
CODE_END = BOOT_VRAM + (last_jr + 2) * 4

if __name__ == '__main__':
    print('num jal targets', len(jal_targets))
    print('num func starts', len(starts))
    print('code end approx %08X (rom %06X)' % (CODE_END, vram_to_rom(CODE_END)))
    # print top called functions
    top = sorted(jal_sites.items(), key=lambda kv: -len(kv[1]))[:30]
    for t, c in top:
        print('%08X  %d callers' % (t, len(c)))
