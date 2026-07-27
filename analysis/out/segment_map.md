# Knife Edge – Nose Gunner (USA) — ROM → RAM load map

ROM analysed: `build/knife_edge.z64`, 8 MiB, big-endian (`80371240`), name `KNIFE EDGE`,
cart id `NKEE`, CRC1 `FCE0D799` / CRC2 `65316C54`, CIC-6102.

All addresses below are byte offsets into that file (`rom_*`) and KSEG0 virtual
addresses (`vram_*`). Every runtime DMA in this game is a *cart* transfer through
`osEPiStartDma`, so `devAddr` == plain ROM file offset; no address translation is
applied anywhere.

Reproduce with the scripts next to this file:
`dis.py` (disassembler), `funcs.py` (call graph), `args.py` / `segscan.py`
(constant-argument recovery), `build_map.py` (the map), `verify.py` (per-segment
sanity check), `emit.py` (emits `segments.json` + the table below).

---

## (a) Load map

| rom_start | rom_end | vram_start | vram_end | kind | loaded by / how discovered |
|---|---|---|---|---|---|
| 0x001000 | 0x02DB50 | 0x800C2400 | 0x800EEF50 | code+data | IPL3 (CIC-6102) |
| - | - | 0x800EEF50 | 0x8016ABF0 | bss | cleared by entry stub 0x800C2400 |
| 0x02DB50 | 0x02FC30 | 0x8016ABF0 | 0x8016D6F0 | data | func_800C3930, desc@0x800E8600 |
| 0x02FC30 | 0x034BE0 | 0x8016D6F0 | 0x801726A0 | code+data | func_800C38C8, desc@0x800EB4A0 |
| 0x034BE0 | 0x03D600 | 0x801726A0 | 0x8017B0C0 | data | func_800C3930, desc@0x800EB4C0 |
| 0x03D600 | 0x03DF80 | 0x8017B0C0 | 0x8017BA40 | code+data | func_800C38C8, desc@0x800EB4D0 |
| 0x03DF80 | 0x041630 | 0x8017BA40 | 0x8017F0F0 | data | func_800C3930, desc@0x800EB4F0 |
| 0x041630 | 0x041650 | 0x80000400 | 0x80000420 | data(staging buffer) | func_800C3968, desc@0x800EB500 |
| 0x041650 | 0x042E70 | 0x8017B0C0 | 0x8017C8E0 | code+data | func_800C38C8, desc@0x800EB50C |
| 0x042E70 | 0x04C7D0 | 0x8017C8E0 | 0x8018CB40 | data | func_800C3930, desc@0x800EB52C |
| 0x04C7D0 | 0x079B90 | 0x80000400 | 0x8002D7C0 | data(staging buffer) | func_800C3968, desc@0x800EB53C |
| 0x079B90 | 0x0BA450 | 0x8017B0C0 | 0x801DC320 | data | func_800C3930, desc@0x800EB664 |
| 0x0BA450 | 0x0CCB00 | 0x801DC320 | 0x801EE9D0 | code+data | func_800C38C8, desc@0x800EB644 |
| 0x0CCB00 | 0x0EC0B0 | 0x80000400 | 0x8001F9B0 | data(staging buffer) | func_800C3968, desc@0x800EB674 |
| 0x0EC0B0 | 0x0EF7C0 | 0x80000400 | 0x80003B10 | data(staging buffer) | func_800C3968, desc@0x800EB680 |
| 0x0EF7C0 | 0x0F3A80 | 0x8017B0C0 | 0x8017F380 | code+data | func_800C38C8, desc@0x800EB548 |
| 0x0F3A80 | 0x0F3F00 | 0x8017F380 | 0x8017F800 | data | func_800C3930, desc@0x800EB568 |
| 0x0F3F00 | 0x0F4810 | 0x80000400 | 0x80000D10 | data(staging buffer) | func_800C3968, desc@0x800EB578 |
| 0x0F4810 | 0x0F5440 | 0x8017B0C0 | 0x8017BCF0 | code+data | func_800C38C8, desc@0x800EB584 |
| 0x0F5440 | 0x0FDFF0 | 0x8017BCF0 | 0x8018B020 | data | func_800C3930, desc@0x800EB5A4 |
| 0x0FDFF0 | 0x10ACC0 | 0x80000400 | 0x8000D0D0 | data(staging buffer) | func_800C3968, desc@0x800EB5B4 |
| 0x10ACC0 | 0x111CC0 | 0x80000400 | 0x80007400 | data(staging buffer) | func_800C3968, desc@0x800EB5C0 |
| 0x111CC0 | 0x114EE0 | 0x8017B0C0 | 0x8017E2E0 | code+data | func_800C38C8, desc@0x800EB5CC |
| 0x114EE0 | 0x1150E0 | 0x8017E2E0 | 0x8017EF00 | data | func_800C3930, desc@0x800EB5EC |
| 0x1150E0 | 0x1199D0 | 0x80000400 | 0x80004CF0 | data(staging buffer) | func_800C3968, desc@0x800EB5FC |
| 0x1199D0 | 0x11CA40 | 0x8017B0C0 | 0x8017E130 | code+data | func_800C38C8, desc@0x800EB608 |
| 0x11CA40 | 0x12C1A0 | 0x8017E130 | 0x8018DBF0 | data | func_800C3930, desc@0x800EB628 |
| 0x12C1A0 | 0x12C2F0 | 0x80000400 | 0x80000550 | data(staging buffer) | func_800C3968, desc@0x800EB638 |
| 0x12C2F0 | 0x12E8F0 | 0x8017B0C0 | 0x8017D6C0 | code+data | func_800C38C8, desc@0x800EB68C |
| 0x12E8F0 | 0x12FBE0 | 0x8017D6C0 | 0x80184E30 | data | func_800C3930, desc@0x800EB6AC |
| 0x12FBE0 | 0x1501A0 | 0x80000400 | 0x800209C0 | data(staging buffer) | func_800C3968, desc@0x800EB6BC |
| 0x1501A0 | 0x183700 | 0x8016D6F0 | 0x801A0C50 | code+data | func_800C38C8, desc@0x800EB6C8 |
| 0x183700 | 0x199640 | 0x801A0C50 | 0x801D21F0 | data | func_800C3930, desc@0x800EB6E8 |
| 0x199640 | 0x1B6400 | 0x80000400 | 0x8001D1C0 | data(staging buffer) | func_800C3968, desc@0x800EB6F8 |
| 0x1B6400 | 0x1B66F0 | 0x80000400 | 0x800006F0 | data(staging buffer) | func_800C3968, desc@0x800EB704 |
| 0x1B66F0 | 0x1E6420 | 0x801D21F0 | 0x80201F20 | code+data | func_800C38C8, desc@0x800EB710 |
| 0x1E6420 | 0x22C680 | 0x80201F20 | 0x80248180 | data | func_800C3930, desc@0x800EB730 |
| 0x22C680 | 0x250360 | 0x80000400 | 0x800240E0 | data(staging buffer) | func_800C3968, desc@0x800EB740 |
| 0x250360 | 0x250D50 | 0x800BE400 | 0x800BEDF0 | data(staging buffer) | func_800C3968, desc@0x800EB74C |
| 0x250D50 | 0x255660 | 0x80020400 | 0x80024D10 | data(staging buffer) | func_800C3968, desc@0x800EB758 |
| 0x255660 | 0x2A75B0 | 0x801D21F0 | 0x80224140 | code+data | func_800C38C8, desc@0x800EB764 |
| 0x2A75B0 | 0x30B090 | 0x80224140 | 0x80287C20 | data | func_800C3930, desc@0x800EB784 |
| 0x30B090 | 0x333FF0 | 0x80000400 | 0x80029360 | data(staging buffer) | func_800C3968, desc@0x800EB794 |
| 0x333FF0 | 0x334A90 | 0x800BE400 | 0x800BEEA0 | data(staging buffer) | func_800C3968, desc@0x800EB7A0 |
| 0x334A90 | 0x336A10 | 0x80020400 | 0x80022380 | data(staging buffer) | func_800C3968, desc@0x800EB7AC |
| 0x336A10 | 0x345300 | 0x80224140 | 0x80232A30 | data | func_800C3930, desc@0x800EB7B8 |
| 0x345300 | 0x34B590 | 0x80000400 | 0x80006690 | data(staging buffer) | func_800C3968, desc@0x800EB7C8 |
| 0x34B590 | 0x378CC0 | 0x801D21F0 | 0x801FF920 | code+data | func_800C38C8, desc@0x800EB7D4 |
| 0x378CC0 | 0x3C3DD0 | 0x801FF920 | 0x8024FBF0 | data | func_800C3930, desc@0x800EB7F4 |
| 0x3C3DD0 | 0x3EAF80 | 0x80000400 | 0x800275B0 | data(staging buffer) | func_800C3968, desc@0x800EB804 |
| 0x3EAF80 | 0x3EBA30 | 0x800BE400 | 0x800BEEB0 | data(staging buffer) | func_800C3968, desc@0x800EB810 |
| 0x3EBA30 | 0x3EFDD0 | 0x80020400 | 0x800247A0 | data(staging buffer) | func_800C3968, desc@0x800EB81C |
| 0x3EFDD0 | 0x42B310 | 0x801D21F0 | 0x8020D730 | code+data | func_800C38C8, desc@0x800EB828 |
| 0x42B310 | 0x473E60 | 0x8020D730 | 0x80256280 | data | func_800C3930, desc@0x800EB848 |
| 0x473E60 | 0x494E50 | 0x80000400 | 0x800213F0 | data(staging buffer) | func_800C3968, desc@0x800EB858 |
| 0x494E50 | 0x495540 | 0x800BE400 | 0x800BEAF0 | data(staging buffer) | func_800C3968, desc@0x800EB864 |
| 0x495540 | 0x497140 | 0x80020400 | 0x80022000 | data(staging buffer) | func_800C3968, desc@0x800EB870 |
| 0x497140 | 0x4A30E0 | 0x801D21F0 | 0x801DE190 | code+data | func_800C38C8, desc@0x800EB87C |
| 0x4A30E0 | 0x4C0300 | 0x801DE190 | 0x801FB3B0 | data | func_800C3930, desc@0x800EB89C |
| 0x4C0300 | 0x4D5E10 | 0x80000400 | 0x80015F10 | data(staging buffer) | func_800C3968, desc@0x800EB8AC |
| 0x4D5E10 | 0x4D5ED0 | 0x800BE400 | 0x800BE4C0 | data(staging buffer) | func_800C3968, desc@0x800EB8B8 |
| 0x4D5ED0 | 0x4D5FC0 | 0x80020400 | 0x800204F0 | data(staging buffer) | func_800C3968, desc@0x800EB8C4 |
| 0x4D5FC0 | 0x4DC330 | 0x801DC320 | 0x801E2690 | code+data | func_800C38C8, desc@0x800EB8D0 |
| 0x4DC330 | 0x4DC6D0 | 0x800BE400 | 0x800BE7A0 | data(staging buffer) | func_800C3968, desc@0x800EB8F0 |
| 0x4DC6D0 | 0x514B40 | 0x801D21F0 | 0x8020A660 | code+data | func_800C38C8, desc@0x800EB8FC |
| 0x514B40 | 0x5571B0 | 0x8020A660 | 0x8024CCD0 | data | func_800C3930, desc@0x800EB91C |
| 0x5571B0 | 0x580480 | 0x8024CCD0 | 0x80275FA0 | data | func_800C3930, desc@0x800EB92C |
| 0x580480 | 0x5A3930 | 0x80000400 | 0x800238B0 | data(staging buffer) | func_800C3968, desc@0x800EB93C |
| 0x5A3930 | 0x5B3F40 | 0x80000400 | 0x80010A10 | data(staging buffer) | func_800C3968, desc@0x800EB948 |
| 0x5B3F40 | 0x5B4520 | 0x800BE400 | 0x800BE9E0 | data(staging buffer) | func_800C3968, desc@0x800EB954 |
| 0x5B4520 | 0x5B6F20 | 0x80020400 | 0x80022E00 | data(staging buffer) | func_800C3968, desc@0x800EB960 |
| 0x5B6F20 | 0x5BF280 | (heap) | - | data | func_800CE290 (malloc + func_800D1D10) @0x800CB4C4 |
| 0x5BF280 | 0x78C860 | (heap) | - | data | streamed by func_800CD8C0 -> osEPiStartDma(0x800D8A00) |
| 0x78C860 | 0x7C1AF0 | (heap) | - | data | func_800CD800 @0x800C801C, table at 0x800EAB50, desc@0x800EAB50 |
| 0x7C1AF0 | 0x800000 | (heap) | - | pad | (none) |

Notes on the table:

* `vram_end` for a `code+data` or `data` row is the descriptor's own `vramEnd`
  field. Where it exceeds `vram_start + (rom_end - rom_start)` the tail is the
  segment's **.bss** (see §a.1).
* `data(staging buffer)` rows land in the free low RAM below the boot segment
  (`0x80000400`, `0x80020400`, `0x800BE400`). These are raw asset blobs
  (textures / compressed data), not linked code, and they are re-used constantly —
  20 different ROM ranges are loaded to `0x80000400` alone.
* The last four rows are audio and are **not** loaded to a fixed VRAM address.

### a.1 Segments that carry a .bss tail

Nine descriptors declare `vramEnd` beyond the end of the DMA'd image; the gap is
zero-initialised BSS belonging to that segment:

| desc | vram range | rom size | bss size |
|---|---|---|---|
| 0x800E8600 | 0x8016ABF0..0x8016D6F0 | 0x20E0 | 0xA20 |
| 0x800EB52C | 0x8017C8E0..0x8018CB40 | 0x9960 | 0x6900 |
| 0x800EB664 | 0x8017B0C0..0x801DC320 | 0x408C0 | 0x209A0 |
| 0x800EB5A4 | 0x8017BCF0..0x8018B020 | 0x8BB0 | 0x6780 |
| 0x800EB5EC | 0x8017E2E0..0x8017EF00 | 0x200 | 0xA20 |
| 0x800EB628 | 0x8017E130..0x8018DBF0 | 0xF760 | 0x360 |
| 0x800EB6AC | 0x8017D6C0..0x80184E30 | 0x12F0 | 0x6480 |
| 0x800EB6E8 | 0x801A0C50..0x801D21F0 | 0x15F40 | 0x1B660 |
| 0x800EB7F4 | 0x801FF920..0x8024FBF0 | 0x4B110 | 0x51C0 |

Nothing in the loader path zeroes these ranges (see §d, open question 1).

### a.2 Fixed VRAM "slots" (overlay structure)

| slot base | # distinct ROM images | role |
|---|---|---|
| 0x8016D6F0 | 2 | main code: front-end (`rom 0x02FC30`, 0x4FB0) **or** in-game (`rom 0x1501A0`, 0x33560) |
| 0x801726A0 / 0x801A0C50 | 1 each | data companion of the two main-code images |
| 0x8017B0C0 | 8 | secondary code/data overlay slot (menu screens, HUD, etc.) |
| 0x801D21F0 | 6 | per-mission code overlays |
| 0x801DC320 | 2 | code overlay used with the front-end |
| 0x80201F20, 0x80224140, 0x8020D730, 0x801DE190, 0x8020A660, 0x801FF920, 0x8024CCD0 | 1–2 each | per-mission data companions |
| 0x80000400 / 0x80020400 / 0x800BE400 | 20 / 6 / 7 | low-RAM asset staging buffers |

Highest VRAM ever written: `0x80287C20` (rom `0x2A75B0`, mission 2 data) — comfortably
inside 4 MiB, so no Expansion Pak dependency.

### a.3 Boot segment internal layout

| range | content |
|---|---|
| 0x800C2400..0x800C2438 | entry stub: BSS clear loop, then `jr` to boot proc 0x800CD6B0 |
| 0x800C2450 | `main` (called as thread 3 from the idle thread) |
| 0x800C2400..~0x800E51F0 | MIPS text (game core + libultra + libm) |
| ~0x800E51F0..~0x800E85F0 | two RSP microcode blobs (dense `lwc2/swc2/cop2`, RSP-relative `j`/`jal`) |
| 0x800E8600..0x800EEF50 | rodata/data — includes the segment descriptor tables |
| 0x800EEF50..0x8016ABF0 | .bss, cleared by the entry stub (0x7BCA0 bytes) |
| 0x80126A60 | boot/idle-thread stack top (inside .bss) |

---

## (b) Evidence

### b.1 The single ROM-read primitive: `func_800D1D10(devAddr, dramAddr, size)`

```
800D1D10 27BDFFB0  addiu  $sp, $sp, -0x50
800D1D18 AFA40050  sw     $a0, 0x50($sp)      ; devAddr  (ROM offset)
800D1D1C AFA50054  sw     $a1, 0x54($sp)      ; dramAddr
800D1D20 AFA60058  sw     $a2, 0x58($sp)      ; size
800D1D2C 0C0362E0  jal    func_800D8B80       ; osCreateMesgQueue(sp+0x20, sp+0x1C, 1)
800D1D44 A3A0003A  sb     $zero, 0x3A($sp)    ; mb(=sp+0x38)->hdr.pri = 0
800D1D48 AFAE003C  sw     $t6,  0x3C($sp)     ; mb->hdr.retQueue = &mq
800D1D4C AFA40040  sw     $a0,  0x40($sp)     ; mb->dramAddr = arg1
800D1D50 AFA50048  sw     $a1,  0x48($sp)     ; mb->size     = arg2
800D1D54 0C035918  jal    func_800D6460       ; osInvalDCache(dram, size)
800D1D58 AFAF0044  sw     $t7,  0x44($sp)     ; mb->devAddr  = arg0
800D1D60 8C84C3A0  lw     $a0, -0x3C60($a0)   ; __CartRomHandle (0x8014C3A0)
800D1D68 0C036280  jal    func_800D8A00       ; osEPiStartDma(handle, mb, OS_READ)
800D1D78 0C036340  jal    func_800D8D00       ; osRecvMesg(&mq, &msg, OS_MESG_BLOCK)
```

`func_800D8A00` is `osEPiStartDma` — it stores `$a0` to `mb+0x14` (`piHandle`) and
`0xF`/`0x10` to `mb+0x00` (`hdr.type`), matching the standard `OSIoMesg` layout;
it bails out with `-1` when `__osPiDevMgr.active` (`0x800FCE10`) is 0.

`func_800E00A0` is `__osPiRawStartDma(dir, devAddr, dramAddr, size)` — it writes
`osVirtualToPhysical(dram)` to `PI_DRAM_ADDR (0xA4600000)`, `devAddr | osRomBase`
masked with `0x1FFFFFFF` to `PI_CART_ADDR (0xA4600004)` and `size-1` to
`PI_WR_LEN (0xA460000C)` for reads. It is only reachable through the PI manager
(its address is planted into `__osPiDevMgr` by `osCartRomInit` at `0x800DA270`).
`osCreatePiManager` is `func_800DA180` (piThread `0x80168230`, stack
`0x801683E0`, piEventQueue `0x801693E0` — all inside the boot .bss).

Callers of `func_800D1D10` (exhaustive, 6):

```
800C3898  (func_800C3848 — dead, 0 callers)
800C3918  (func_800C38C8 — 8-word descriptor loader, 21 call sites)
800C3950  (func_800C3930 — 4-word descriptor loader, 22 call sites)
800C3988  (func_800C3968 — 3-word descriptor loader, 16 call sites)
800CD820  (func_800CD800 — streamed-music page loader)
800CE2D8  (func_800CE290 — malloc + load, used once, for the audio bank)
```

### b.2 The three descriptor loaders

```
; func_800C38C8(desc)   ; 8-word descriptor  = code segment
800C38D8 8DCF0010  lw   $t7, 0x10($t6)   \  osInvalICache(desc[4], desc[5]-desc[4])
800C38DC 8DD80014  lw   $t8, 0x14($t6)   /  (func_800D63E0, 0x20-byte lines)
800C38E4 0C0358F8  jal  func_800D63E0
800C38F0 8F280018  lw   $t0, 0x18($t9)   \  osInvalDCache(desc[6], desc[7]-desc[6])
800C38F4 8F29001C  lw   $t1, 0x1C($t9)   /  (func_800D6460, `cache 0x15`)
800C38FC 0C035918  jal  func_800D6460
800C3908 8D4B0008  lw   $t3, 0x8($t2)    ; a0 = desc[2]  romStart
800C390C 8D4C000C  lw   $t4, 0xC($t2)    ;      desc[3]  romEnd
800C3910 8D450000  lw   $a1, 0x0($t2)    ; a1 = desc[0]  vramStart
800C3918 0C034744  jal  func_800D1D10
800C391C 018B3023  subu $a2, $t4, $t3    ; a2 = size
```

so the 8-word descriptor is

```
+0x00 vramStart   +0x04 vramEnd      (may include a .bss tail)
+0x08 romStart    +0x0C romEnd
+0x10 textStart   +0x14 textEnd      (icache invalidate range)
+0x18 dataStart   +0x1C dataEnd      (dcache invalidate range)
```

`func_800C3930` uses only `{+0x00 vram, +0x08 romStart, +0x0C romEnd}` (4-word
descriptor, pure data), and `func_800C3968` uses `{+0x00 vram, +0x04 romStart,
+0x08 romEnd}` (3-word descriptor, staging-buffer load). **No loader performs any
relocation, symbol fix-up, or bss clear** — they are DMA + cache maintenance only.

### b.3 The descriptor tables (boot rodata)

First descriptor, referenced by `main`'s init chain:

```
800C2578 3C04800F  lui   $a0, 0x800F
800C257C 0C030E4C  jal   func_800C3930
800C2580 24848600  addiu $a0, $a0, -0x7A00     ; a0 = 0x800E8600

800E8600 (rom 0x027200):  8016ABF0 8016D6F0 0002DB50 0002FC30
                          ^vram    ^vramEnd  ^romStart ^romEnd
```

`romStart = 0x2DB50` is exactly the end of the IPL3-loaded boot segment
(`0x1000 + 0x2CB50`), and `vram = 0x8016ABF0` is exactly the end of the BSS the
entry stub clears — the two images are contiguous in both spaces.

The main table lives at `0x800EB4A0..0x800EB96C` (rom `0x02A0A0..0x02A56C`).
Excerpt:

```
800EB4A0: 8016D6F0 801726A0 0002FC30 00034BE0   ; 8-word: front-end code
800EB4B0: 8016D6F0 80172530 80172530 801726A0   ;   text / data split
800EB4C0: 801726A0 8017B0C0 00034BE0 0003D600   ; 4-word: its data
800EB4D0: 8017B0C0 8017BA40 0003D600 0003DF80   ; 8-word: overlay code
800EB4E0: 8017B0C0 8017B980 8017B980 8017BA40
800EB4F0: 8017BA40 8017F0F0 0003DF80 00041630   ; 4-word
800EB500: 80000400 00041630 00041650            ; 3-word: staging
...
800EB6C8: 8016D6F0 801A0C50 001501A0 00183700   ; 8-word: IN-GAME code
800EB6D8: 8016D6F0 8019D2B0 8019D2B0 801A0C50
800EB6E8: 801A0C50 801D21F0 00183700 00199640   ; 4-word: its data (+0x1B660 bss)
800EB6F8: 80000400 00199640 001B6400            ; 3-word: staging
800EB710: 801D21F0 80201F20 001B66F0 001E6420   ; 8-word: mission 1 code
```

Call sites in the boot segment (via `args.py`, register-constant tracking; **zero
unresolved `$a0`**) recover 34 distinct loads. The remaining descriptors
(`0x800EB710`..`0x800EB96C`) are referenced from *inside the in-game code overlay*,
so the map is closed by iterating: scan boot → find `seg 0x1501A0` → scan it →
find the mission table, etc. (`build_map.py`). Example hits inside
`seg_1501A0` (VRAM `0x8016D6F0`):

```
8016D97C -> func_800C38C8  a0 = 0x800EB710   (mission 1 code)
8016D988 -> func_800C3930  a0 = 0x800EB730   (mission 1 data)
8016D994 -> func_800C3968  a0 = 0x800EB740   (mission 1 staging)
8016D9F8 -> func_800C38C8  a0 = 0x800EB764   (mission 2 code)
...
```

Result: **69 distinct descriptor loads, all `$a0` values statically resolved,
covering ROM `0x001000..0x5B6F20` contiguously with no gaps and no overlaps in ROM.**

### b.4 Second dense code region — resolved

The instruction-density hit at ROM `~0x151000..0x180000` is a *single* segment:
descriptor `0x800EB6C8`, ROM `0x1501A0..0x183700` (0x33560 bytes), loaded to
`0x8016D6F0..0x801A0C50`, of which `0x8016D6F0..0x8019D2B0` (0x2FBC0) is text and
`0x8019D2B0..0x801A0C50` is rodata. It is the in-game code overlay and shares the
`0x8016D6F0` slot with the much smaller front-end code overlay (ROM `0x2FC30`).
The elevated-density regions near `0x1B1000` and `0x251000` are the mission-1 code
overlay (`0x1B66F0`, text `0x801D21F0..0x801E68C0`) and the mission-2 code overlay
(`0x255660`, text `0x801D21F0..0x801EA5C0`).

### b.5 Audio (the ROM tail, `0x5B6F20..0x7C1AF0`)

```
800CB4A8 3C08005B  lui   $t0, 0x5B
800CB4AC 3C09005C  lui   $t1, 0x5C
800CB4B0 2529F280  addiu $t1, $t1, -0xD80     ; 0x5BF280
800CB4B4 25086F20  addiu $t0, $t0, 0x6F20     ; 0x5B6F20
800CB4C4 0C0338A4  jal   func_800CE290        ; (0x5B6F20, 0x8360, 0x5BF280)
```

`func_800CE290` mallocs `size` bytes (`func_800D8AE0`), DMAs ROM
`0x5B6F20..0x5BF280` into it, then calls `func_800CF810(bank, 0x5BF280)` —
an `alBnkfNew`-style fix-up that binds the bank to the wavetable ROM base.

* `0x5B6F20`: ASCII `"N64 PtrTablesV2\0"` + `"NEDGE.WBK\0"` — instrument/bank pointer file.
* `0x5BF280`: ASCII `"N64 WaveTables "` — ADPCM sample data, never resident; it is
  paged in 0x400-byte chunks by `func_800CD8C0`, the only other caller of
  `osEPiStartDma` (`0x800CDA50`).
* `0x78C860..0x7C1AF0`: 30 streamed music files (index 0 of the table is null), driven by `func_800CD800` from a
  static `{u32, u32 romStart, u32 romEnd}` table at `0x800EAB50` (rom `0x029750`),
  destination `*(0x80149AEC)`; indexed at `0x800C7FF8`.
* `0x7C1AF0..0x800000`: `0xFF` filler (last non-pad byte is at `0x7C1AEC`).

### b.6 Sanity check of the claimed bases (§d of the brief)

`verify.py` disassembles each claimed image *at its claimed VRAM* and classifies
`jal` targets. Every `code+data` row is clean; representative results:

| segment | vram | valid MIPS | `jr $ra` | jal in-seg | jal → boot | jal elsewhere |
|---|---|---|---|---|---|---|
| rom 0x02FC30 (front-end code) | 0x8016D6F0 | 99.1 % | 24 | 32 | 34 | 0 |
| rom 0x1501A0 (in-game code)   | 0x8016D6F0 | 98.8 % | 284 | 621 | 698 | 80 (data tail) |
| rom 0x12C2F0 (overlay)        | 0x8017B0C0 | 99.1 % | 21 | 51 | 75 | 1 |
| rom 0x0F4810 (overlay)        | 0x8017B0C0 | 98.6 % | 8 | 5 | 48 | 0 |
| rom 0x1B66F0 (mission 1 code) | 0x801D21F0 | 78.0 %* | 27 | 97 | 194 | (mission data) |

\* whole image; restricted to the descriptor's declared text range the figure is
comparable to the others.

`jal` target histograms restricted to each declared *text* range land **only** in
loaded windows:

```
seg 0x1501A0 text  -> 800C:410 800D:234 800E:54   (boot)
                      8016:46 8017:204 8018:177 8019:194 (itself, 8016D6F0..801A0C50)
                      801D:70 801E:10             (mission code slot)
seg 0x1B66F0 text  -> 800C:114 800D:69 800E:11    (boot)
                      8017:218 8018:227 8019:49   (in-game code slot)
                      801D:17 801E:80             (itself)
seg 0x12C2F0 text  -> 800C:47 800D:17 800E:11 8017:52
```

Entry-point sanity (first instructions at each claimed base are function prologues,
not mid-instruction garbage):

```
8016D6F0 27BDFFE0  addiu $sp, $sp, -0x20      ; rom 0x1501A0
8016D6F4 3C0E8012  lui   $t6, 0x8012          ; -> boot .bss
801D21F0 3C0E8012  lui   $t6, 0x8012          ; rom 0x1B66F0
801D2204 3C0F8020  lui   $t7, 0x8020          ; -> 0x8020E4EC, inside its own data seg
8017B0C0 27BDFFE0  addiu $sp, $sp, -0x20      ; rom 0x12C2F0
```

`lui`/`addiu` address constants formed in every code overlay fall in
`0x800C…0x800E` (boot text/data), `0x800F…0x8016A` (boot .bss), or the overlay's
own / its sibling's loaded window. No constant points outside a mapped range.

---

## (c) Verdicts

### Relocatable overlays: **NO — every load is to a fixed, hard-coded VRAM address.**

Grounds:

1. The only three loaders (`func_800C38C8/3930/3968`) are fully disassembled above:
   `osInvalICache` + `osInvalDCache` + `osEPiStartDma` + `osRecvMesg`. There is no
   post-DMA pass over the image, no `.rel` walk, no HI16/LO16 patch loop.
2. All 69 destinations come from a static, ROM-resident descriptor table in the boot
   segment's rodata (`0x800E8600`, `0x800EAB50`, `0x800EB4A0..0x800EB96C`). No
   destination is computed from a heap pointer.
3. Overlay images that share a slot have *different sizes* but identical bases
   (`0x8016D6F0`: 0x4FB0 and 0x33560; `0x8017B0C0`: eight images from 0x980 to
   0x408C0). That only works with absolute linkage.
4. Cross-overlay `jal`s are absolute and correct in both directions (in-game code at
   `0x8016D6F0` calls mission code at `0x801D…`, and mission code calls back into
   `0x8017…/0x8018…/0x8019…`). A relocating loader would not need this, and the
   values are already correct in the ROM image.
5. No overlay ever calls `func_800D1D10`, `osEPiStartDma`, `func_800CE290` or
   `func_800CD800` directly — an exhaustive scan of all 69 segments plus boot finds
   exactly 10 call sites, all inside the boot segment (`build_map.py` /
   the scan in this file's `segscan.py`). So there is no second, hidden loader.

### TLB: **not used by the game — libultra boilerplate only. Direct-mapped KSEG0 throughout.**

The entire 8 MiB ROM contains exactly four canonically-encoded TLB instructions
(`0x42000001/2/6/8`), all inside the boot segment:

```
rom 0x01A304  tlbp    vram 0x800DB704   in func_800DB6E0  = __osProbeTLB
rom 0x01A324  tlbr    vram 0x800DB724   in func_800DB6E0
rom 0x01AEA0  tlbwi   vram 0x800DC2A0   in func_800DC280  = osUnmapTLBAll
rom 0x01AF08  tlbwi   vram 0x800DC308   in func_800DC2D0  = osMapTLBRdb
```

```
800DC280 40085000  mfc0  $t0, EntryHi
800DC284 2409001E  addiu $t1, $zero, 0x1E        ; entries 30..0
800DC288 3C0A8000  lui   $t2, 0x8000
800DC28C 408A5000  mtc0  $t2, EntryHi
800DC290 40801000  mtc0  $zero, EntryLo0
800DC294 40801800  mtc0  $zero, EntryLo1
800DC298 40890000  mtc0  $t1, Index
800DC2A0 42000002  tlbwi
```

Call-graph facts:

* `func_800DC280` (osUnmapTLBAll) — 1 caller: `0x800D7560`, inside `osInitialize`.
* `func_800DC2D0` (osMapTLBRdb)   — 1 caller: `0x800D7568`, the next instruction.
* `func_800DB6E0` (__osProbeTLB)  — 1 caller: `0x800D7104`, the non-KSEG0 fallback
  path of `osVirtualToPhysical`; unreachable for this game's addresses.
* There is no `osMapTLB`, no `osSetTLBASID` beyond init, and no TLB instruction
  anywhere outside `0x800DB6E0`/`0x800DC280`/`0x800DC2D0`.

Every DMA destination is `0x8000_0400..0x8028_7C20`, i.e. plain KSEG0. The 167 other
`tlb*`-looking words the naive scan reports all have non-zero reserved bits and lie
in texture/model data or in the RSP microcode blob (`~0x800E51F0..0x800E85F0`), which
also explains the `mtc0 Index/EntryLo/PageMask` hits at `0x800E5204` etc. — those are
RSP instructions, not CPU ones.

### RAM

Highest byte ever written by a load is `0x80287C20`. Base 4 MiB machine; no
Expansion Pak requirement observed in the load map.

---

## (d) Open questions / not resolved statically

1. **Who clears the per-segment .bss tails?** Nine descriptors declare BSS beyond the
   DMA'd image (§a.1), but `func_800C38C8/3930/3968` do not zero it. The dead
   `func_800C3848` (0 callers) *does* have a fourth step —
   `func_800D6510(desc[8], desc[9]-desc[8])`, a `bzero` — using two extra descriptor
   words at `+0x20/+0x24`, which suggests the live loaders were trimmed and the
   game either relies on the entry-stub clear (only valid for the first segment,
   `0x8016ABF0..0x8016D6F0`) or zeroes those ranges from segment init code. Needs a
   pass over the overlays' init functions to confirm.
2. **Exact boundary of the two RSP microcode blobs** inside the boot segment. I have
   bracketed them to `~0x800E51F0..~0x800E85F0` by opcode statistics and by the last
   real MIPS function ending at `0x800E51E8`, but I did not identify the ucode
   (`gspF3DEX2`-class + an audio ucode) or split text/data precisely.
3. **Wavetable / music boundary is inferred, not read from a header.** I take
   `0x5BF280..0x78C860` as wavetable because `0x78C860` is the lowest `romStart` in
   the music table at `0x800EAB50`; the `"N64 PtrTablesV2"` header at `0x5B6F20`
   contains offsets (`0xBF, 0x7F9C, 0x805C, 0x7CA0, 0x10, 0xF78`) that are internal
   to that 0x8360-byte file and do not state the wavetable length. If an exact
   wavetable size is needed it must come from parsing that custom format.
4. **Mission-slot ownership.** Descriptors `0x800EB7B8`/`0x800EB7C8` are referenced
   only from inside the mission-2 code overlay (`seg 0x255660`, call sites `0x801D35C0` / `0x801D35CC`), and
   `0x800EB8F0` only from `seg 0x4D5FC0`. They are in the map, but the exact
   game-state that triggers them was not traced.
5. **`func_800CD800`'s destination** is `*(0x80149AEC)`, a runtime pointer (a music
   streaming buffer). Its size/allocation site was not traced, so the music rows in
   the table have no `vram_start`.
6. `func_800C3848` is dead code (0 callers) — kept in the ROM but never invoked. If a
   later analysis finds an indirect call to it, its extra `bzero` field would change
   the descriptor size for the 8-word entries from 0x20 to 0x28 bytes; nothing in the
   current data layout contradicts 0x20 (descriptors pack tightly at 0x20/0x10/0x0C).
