#!/usr/bin/env python3
"""Disassembly helpers for Knife Edge ROM analysis."""
import sys, struct
import rabbitizer

ROM = '/workspaces/knife-edge-recomp/build/knife_edge.z64'
DATA = open(ROM, 'rb').read()

BOOT_ROM = 0x1000
BOOT_VRAM = 0x800C2400
BOOT_SIZE = 0x2CB50

rabbitizer.config.pseudos_pseudoMove = False


def vram_to_rom(v):
    return v - BOOT_VRAM + BOOT_ROM


def rom_to_vram(r):
    return r - BOOT_ROM + BOOT_VRAM


def words(rom_off, n):
    return struct.unpack_from('>%dI' % n, DATA, rom_off)


def dis_range(rom_off, n, vram=None):
    """Yield (vram, word, Instruction)."""
    if vram is None:
        vram = rom_to_vram(rom_off)
    for i in range(n):
        w = struct.unpack_from('>I', DATA, rom_off + i * 4)[0]
        ins = rabbitizer.Instruction(w, vram=vram + i * 4)
        yield vram + i * 4, w, ins


def show(rom_off, n, vram=None):
    out = []
    for v, w, ins in dis_range(rom_off, n, vram):
        out.append('%08X %08X  %s' % (v, w, ins.disassemble()))
    return '\n'.join(out)


if __name__ == '__main__':
    a = int(sys.argv[1], 0)
    n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 32
    if a >= 0x80000000:
        print(show(vram_to_rom(a), n, a))
    else:
        v = int(sys.argv[3], 0) if len(sys.argv) > 3 else rom_to_vram(a)
        print(show(a, n, v))
