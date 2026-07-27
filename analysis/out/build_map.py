#!/usr/bin/env python3
"""Build the complete Knife Edge load map by:
  1. scanning the boot segment for calls to the three segment-loader helpers
  2. iteratively scanning every newly discovered code segment for more calls
"""
import sys, struct, json, collections
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from dis import DATA, vram_to_rom
from segscan import scan

BOOT_ROM, BOOT_VRAM, BOOT_SIZE = 0x1000, 0x800C2400, 0x2CB50
CODE_END = 0x800E8578

LOADERS = {0x800C38C8: 8, 0x800C3930: 4, 0x800C3968: 3}


def w(vram, i):
    return struct.unpack_from('>I', DATA, vram_to_rom(vram) + i * 4)[0]


def desc(a0, nw):
    ws = [w(a0, i) for i in range(nw)]
    if nw == 3:
        return dict(vram=ws[0], rom=ws[1], romend=ws[2], vramend=None, extra=ws)
    return dict(vram=ws[0], vramend=ws[1], rom=ws[2], romend=ws[3], extra=ws)


def main():
    loads = {}          # (rom, romend, vram) -> dict
    callsites = collections.defaultdict(list)
    seen_segs = set()
    queue = [('boot', BOOT_ROM, BOOT_SIZE, BOOT_VRAM)]
    unresolved = []
    while queue:
        name, rom, size, vram = queue.pop(0)
        if (rom, size, vram) in seen_segs:
            continue
        seen_segs.add((rom, size, vram))
        for cs, t, regs in scan(rom, size, vram, set(LOADERS)):
            a0 = regs.get(4)
            if a0 is None or not (0x800E8578 <= a0 < 0x800EEF50):
                unresolved.append((name, cs, t, a0))
                continue
            d = desc(a0, LOADERS[t])
            key = (d['rom'], d['romend'], d['vram'])
            d['desc'] = a0
            d['nw'] = LOADERS[t]
            loads.setdefault(key, d)
            callsites[key].append((name, cs))
            # queue any newly-found segment that looks like code
            sz = d['romend'] - d['rom']
            if d['vram'] >= 0x80100000 and sz > 0x100:
                queue.append(('seg_%06X' % d['rom'], d['rom'], sz, d['vram']))
    return loads, callsites, unresolved


if __name__ == '__main__':
    loads, callsites, unresolved = main()
    print('total distinct loads: %d' % len(loads))
    for k in sorted(loads):
        d = loads[k]
        cs = callsites[k]
        print('rom %06X..%06X size %6X -> %08X  desc@%08X(%dw)  callers: %s' % (
            d['rom'], d['romend'], d['romend'] - d['rom'], d['vram'], d['desc'], d['nw'],
            ', '.join('%s:%08X' % c for c in cs[:4]) + (' ...' if len(cs) > 4 else '')))
    print('unresolved:', unresolved)
    # coverage
    ivs = sorted([(BOOT_ROM, BOOT_ROM + BOOT_SIZE)] +
                 [(d['rom'], d['romend']) for d in loads.values()])
    merged = []
    for a, b in ivs:
        if merged and a <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], b)
        else:
            merged.append([a, b])
    print('\ncovered ROM ranges:')
    prev = 0
    for a, b in merged:
        if a > prev:
            print('   GAP  %06X..%06X (%X)' % (prev, a, a - prev))
        print('   COV  %06X..%06X (%X)' % (a, b, b - a))
        prev = b
    if prev < len(DATA):
        print('   GAP  %06X..%06X (%X)' % (prev, len(DATA), len(DATA) - prev))
