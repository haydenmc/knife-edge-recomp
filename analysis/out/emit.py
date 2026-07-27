#!/usr/bin/env python3
"""Emit segments.json + the table body for segment_map.md."""
import sys, json, struct
sys.path.insert(0, '/workspaces/knife-edge-recomp/analysis/out')
from build_map import main as build
from dis import DATA

loads, callsites, unres = build()

rows = []

rows.append(dict(name='boot', rom=0x1000, size=0x2CB50, vram=0x800C2400,
                 kind='code+data', romend=0x2DB50, vramend=0x800EEF50,
                 loader='IPL3 (CIC-6102)', desc=None,
                 note='entry 0x800C2400; text ~0x800C2400-0x800E51F0, RSP microcode '
                      '~0x800E51F0-0x800E8578, rodata/data 0x800E8578-0x800EEF50'))
rows.append(dict(name='boot_bss', rom=None, size=0x7BCA0, vram=0x800EEF50,
                 kind='bss', romend=None, vramend=0x8016ABF0,
                 loader='cleared by entry stub 0x800C2400', desc=None,
                 note='lui/ori 0x0007BCA0 loop at 0x800C2410'))

SLOT_ROLE = {}


def role_of(d):
    if d['nw'] == 8:
        return 'code+data'
    if d['vram'] < 0x800C2400:
        return 'data(staging buffer)'
    return 'data'


for k in sorted(loads):
    d = loads[k]
    size = d['romend'] - d['rom']
    r = dict(name='seg_%06X' % d['rom'],
             rom=d['rom'], size=size, vram=d['vram'],
             romend=d['romend'],
             vramend=d['vramend'] if d['vramend'] else d['vram'] + size,
             kind=role_of(d),
             loader={8: 'func_800C38C8', 4: 'func_800C3930', 3: 'func_800C3968'}[d['nw']],
             desc=d['desc'],
             callers=['%s:0x%08X' % c for c in callsites[k]])
    if d['nw'] == 8:
        e = d['extra']
        r['text'] = [e[4], e[5]]
        r['data'] = [e[6], e[7]]
    if r['vramend'] > d['vram'] + size:
        r['bss'] = [d['vram'] + size, r['vramend']]
    rows.append(r)

# audio
rows.append(dict(name='audio_ptrtable', rom=0x5B6F20, size=0x8360, vram=None,
                 romend=0x5BF280, vramend=None, kind='data',
                 loader='func_800CE290 (malloc + func_800D1D10) @0x800CB4C4',
                 desc=None,
                 note='"N64 PtrTablesV2" / "NEDGE.WBK" bank+pointer file; destination is '
                      'heap-allocated at runtime, then fixed up by func_800CF810 with the '
                      'wavetable ROM base 0x5BF280'))
rows.append(dict(name='audio_wavetable', rom=0x5BF280, size=0x1CD5E0, vram=None,
                 romend=0x78C860, vramend=None, kind='data',
                 loader='streamed by func_800CD8C0 -> osEPiStartDma(0x800D8A00)',
                 desc=None,
                 note='"N64 WaveTables " header; ADPCM sample data, DMA\'d in 0x400-byte '
                      'pages into a runtime buffer cache; never resident as a whole'))
rows.append(dict(name='audio_music', rom=0x78C860, size=0x35290, vram=None,
                 romend=0x7C1AF0, vramend=None, kind='data',
                 loader='func_800CD800 @0x800C801C, table at 0x800EAB50',
                 desc=0x800EAB50,
                 note='30 entries of {u32,u32 romStart,u32 romEnd} (index 0 null); destination is the '
                      'buffer pointed to by *(0x80149AEC)'))
rows.append(dict(name='padding', rom=0x7C1AF0, size=0x3E510, vram=None,
                 romend=0x800000, vramend=None, kind='pad',
                 loader='(none)', desc=None, note='0xFF filler to 8 MiB'))

out = []
for r in rows:
    d = {k: v for k, v in r.items() if v is not None}
    for k in ('rom', 'romend', 'size', 'vram', 'vramend', 'desc'):
        if k in d:
            d[k + '_hex'] = '0x%08X' % d[k]
    for k in ('text', 'data', 'bss'):
        if k in d:
            d[k + '_hex'] = ['0x%08X' % x for x in d[k]]
    out.append(d)

with open('/workspaces/knife-edge-recomp/analysis/out/segments.json', 'w') as f:
    json.dump(out, f, indent=2)

# markdown table
lines = ['| rom_start | rom_end | vram_start | vram_end | kind | loaded by / how discovered |',
         '|---|---|---|---|---|---|']
for r in rows:
    rs = '0x%06X' % r['rom'] if r.get('rom') is not None else '-'
    re_ = '0x%06X' % r['romend'] if r.get('romend') is not None else '-'
    vs = '0x%08X' % r['vram'] if r.get('vram') is not None else '(heap)'
    ve = '0x%08X' % r['vramend'] if r.get('vramend') is not None else '-'
    how = r['loader']
    if r.get('desc'):
        how += ', desc@0x%08X' % r['desc']
    lines.append('| %s | %s | %s | %s | %s | %s |' % (rs, re_, vs, ve, r['kind'], how))
open('/workspaces/knife-edge-recomp/analysis/out/_table.md', 'w').write('\n'.join(lines))
print('\n'.join(lines))
print('\nrows: %d' % len(rows))
