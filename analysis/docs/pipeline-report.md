# ROM → symbols pipeline — results

Implements `pipeline-spec.md`. Regenerate everything with `make -C analysis`
(≈15 s using the cached n64sym scans) or `make -C analysis refresh` (≈10 min,
re-runs n64sym). `make -C analysis recomp` also runs N64Recomp, `make -C
analysis smoke` additionally compiles a sample of the generated C.

| stage | script | output |
|---|---|---|
| 1 | `analysis/find_functions.py` | `out/functions.json`, `out/functions_report.txt` |
| 2 | `analysis/ident_libultra.py` | `out/libultra_names.json`, `out/libultra_report.txt`, `out/n64sym/group*.txt` |
| 3 | `analysis/gen_syms.py` | `config/knife_edge.us.syms.toml`, `config/knife_edge.us.toml`, `out/syms_report.txt` |

Headline: **N64Recomp exits 0, 1115 functions, zero `No function found for jal
target`, zero auto-created statics, all 20 generated `.c` files compile clean
with clang.**

---

## 1. Function detection

18 code segments (every `kind == "code+data"` row of `segments.json`); the 22
`data`, 33 staging-buffer and 1 `pad` segments get no section, as specified.

Function starts come from, in priority order: the hard entrypoint, the segment's
own `jal` targets, `jal` targets raised by *other* segments that land in this
segment's text, `lui`/`addiu` pairs that materialise an in-text address, and the
first non-nop word after a `jr $ra` + delay slot.

Two filters keep the last three rules from over-splitting:

* **branch crossing** — a candidate is discarded if any intra-segment branch
  spans it. Compiler branches never cross a function boundary, so this
  correctly suppresses the second/third `jr $ra` of a multi-return function
  (49 such candidates in boot, 32 in `seg_1501A0`, 3 in `seg_4DC6D0`).
* **terminator precedence** — the candidate must follow a `jr`/`j`/`eret`/
  unconditional branch (skipping nop padding).

Foreign `jal` targets are additionally plausibility-filtered when the segment
shares its VRAM base with another code segment (eight images at `0x8017B0C0`,
six at `0x801D21F0`, two each at `0x8016D6F0` and `0x801DC320`) — an address
that is a real function in overlay A is usually mid-function in overlay B.

| segment | text range | size | funcs | jal | xjal | gap | ptr | largest func |
|---|---|---|---|---|---|---|---|---|
| boot | 800C2400..800E51F0 | 0x22DF0 | 565 | 380 | 60 | 94 | 30 | 0x1720 |
| seg_02FC30 | 8016D6F0..80172530 | 0x4E40 | 22 | 12 | 8 | 2 | 0 | 0xDCC |
| seg_03D600 | 8017B0C0..8017B980 | 0x8C0 | 7 | 3 | 3 | 1 | 0 | 0x304 |
| seg_041650 | 8017B0C0..8017C3D0 | 0x1310 | 9 | 5 | 3 | 1 | 0 | 0x6C4 |
| seg_0BA450 | 801DC320..801E23C0 | 0x60A0 | 28 | 23 | 3 | 2 | 0 | 0x26E8 |
| seg_0EF7C0 | 8017B0C0..8017EE80 | 0x3DC0 | 15 | 9 | 4 | 2 | 0 | 0xDB0 |
| seg_0F4810 | 8017B0C0..8017BC50 | 0xB90 | 8 | 5 | 2 | 1 | 0 | 0x5B4 |
| seg_111CC0 | 8017B0C0..8017E130 | 0x3070 | 25 | 21 | 2 | 2 | 0 | 0x8E4 |
| seg_1199D0 | 8017B0C0..8017D980 | 0x28C0 | 14 | 11 | 2 | 1 | 0 | 0xCBC |
| seg_12C2F0 | 8017B0C0..8017D560 | 0x24A0 | 21 | 16 | 3 | 2 | 0 | 0x778 |
| seg_1501A0 | 8016D6F0..8019D2B0 | 0x2FBC0 | 252 | 197 | 44 | 10 | 1 | 0x2880 |
| seg_1B66F0 | 801D21F0..801E68C0 | 0x146D0 | 27 | 15 | 12 | 0 | 0 | 0x87C8 |
| seg_255660 | 801D21F0..801EA5C0 | 0x183D0 | 29 | 15 | 13 | 1 | 0 | 0xA298 |
| seg_34B590 | 801D21F0..801E32B0 | 0x110C0 | 24 | 10 | 13 | 1 | 0 | 0x935C |
| seg_3EFDD0 | 801D21F0..801DE160 | 0xBF70 | 15 | 4 | 11 | 0 | 0 | 0x4AF0 |
| seg_497140 | 801D21F0..801D7780 | 0x5590 | 16 | 4 | 12 | 0 | 0 | 0x24A0 |
| seg_4D5FC0 | 801DC320..801DE9F0 | 0x26D0 | 11 | 9 | 1 | 1 | 0 | 0x199C |
| seg_4DC6D0 | 801D21F0..801E1470 | 0xF280 | 27 | 12 | 13 | 2 | 0 | 0x60F4 |

Totals: **1115 functions** over 0xCC530 bytes of text — `jal` 751, `xjal` 209,
`gap` 123, `ptr` 31, entrypoint 1.

* **Text coverage is 100.00 %** — no byte of any declared text range is left
  unclaimed, and there are **no gaps and no data-in-text rejections**.
* **0 forced entries**: every `jal` target raised anywhere already resolves to a
  detected function start, without the fallback that force-adds unclaimed
  targets.
* **0 `jal` targets outside every declared text range.**
* Quality check (not part of the shipped output): exactly **one** of the 1115
  functions does not end in a terminator — `__osCleanupThread` (0x800DC1F0),
  which legitimately never returns (it tail-calls `osDestroyThread` on the
  running thread). Everything else ends in `jr $ra`/`j`/`jr $reg` + delay slot,
  which is the strongest available evidence that boundaries are not split
  through the middle of real functions.

### Segments with very few, very large functions

The mission overlays (`seg_1B66F0`, `seg_255660`, `seg_34B590`, `seg_3EFDD0`,
`seg_497140`, `seg_4DC6D0`) really do contain only 15–29 functions across
0x5000–0x18000 bytes. This was checked directly: `seg_1B66F0`'s 0x146D0-byte
text contains 27 `jr $ra`, 20 `addiu $sp, $sp, -N` prologues and 19 `sw $ra`,
and rabbitizer decodes 100 % of it as valid MIPS. The mission code is heavily
inlined/unrolled per-mission logic, not a mis-sized text range.

### Data in text / the RSP microcode blob

The boot segment's text range is fixed at `0x800C2400..0x800E51F0`. The last
`jr $ra` before the microcode is at `0x800E51DC` (+delay slot + 3 nops of
padding), and n64sym independently labels `0x800E51F0` `rspbootTextStart` and
`0x800E52C0` `aspMainTextStart`. The two RSP blobs are therefore entirely
outside the section's function list and are never turned into CPU functions.
No other data-in-text region was found inside any declared text range.

### Jump tables vs function-pointer tables

Spec stage 1.2 asks for jump-table harvesting. All 87 runs of ≥3 consecutive
word-aligned in-text addresses live in the segments' **data** ranges (none in
text) and cover 2015 distinct targets. Classified by how many distinct enclosing
functions each run's entries fall into:

* 86 runs are switch jump tables (many entries, 1–8 enclosing functions; the
  multi-function ones are simply several adjacent `.rodata` tables that the
  run detector merges). Their entries are intra-function branch targets and are
  deliberately **not** promoted to function starts.
* 1 run is a genuine function-pointer table: **boot `0x800EB990`, 42 entries,
  42 distinct enclosing functions** — and all 42 targets are already detected
  function starts, so nothing is missing.

---

## 2. libultra identification

n64sym was run on 8 synthesised 4 MiB RAM images (`-s -t -f splat`). The code
segments are greedily partitioned into VRAM-disjoint groups because eight
overlays share `0x8017B0C0` and six share `0x801D21F0`; group 0 holds boot plus
the largest non-conflicting overlays. Raw output is cached in
`analysis/out/n64sym/group*.txt` (40 KB) so re-runs are instant; `--refresh`
forces a rescan.

402 distinct `(name, vram)` pairs across all groups; 377 of them in group 0
(boot). Only 276 land inside a declared text range and reach the gates — the
rest are data/bss symbols, which the pipeline ignores entirely (N64Recomp's
symbols-file mode has no data symbols).

| outcome | count |
|---|---|
| accepted | **226** |
| rejected | 50 |

Rejection reasons: 21 "not a detected function start" (this alone removes every
mislabelled interior address, e.g. `0x800DA270` inside `osCreatePiManager`),
11 sub-object labels (`sprintf_text_0000`, `vimgr_text_0180`, …), 7 implausible
families (`osBb*`, `leo*`, `rmon*`, `n_al*`), 6 below the libultra cluster
floor, 4 duplicate names, 1 segment with no cluster (21+11+7+6+4+1 = 50).

Of the 226 accepted names, **122 are in N64Recomp's `reimplemented_funcs` or
`ignored_funcs`** (the two dangerous sets), 9 in `renamed_funcs`, and 95 in no
set at all.

### Gates, and why they are shaped that way

The asymmetry that drives the whole design: only names in `reimplemented_funcs`
(body replaced by librecomp's HLE) and `ignored_funcs` (no body emitted) are
dangerous to get wrong. `renamed_funcs` and unknown names are still recompiled
verbatim, so a mislabel there is cosmetic. The gates are therefore strict about
*structure* (which protects the dangerous names) and lenient about *identity*.

1. **Sub-object labels** (`_text_`/`_data_`/`_bss_`/`_rodata_` + hex offset) are
   dropped — they are signature-file artefacts, not function names.
2. **Implausible families** dropped outright: `osBb*`/`__osBb*` (iQue),
   `leo*` (64DD), `rmon*`/`__rmon*` (debug monitor), `n_al*` (the alternate
   n_audio library, which cannot coexist with the `al*` set that is present).
3. **Must be a detected function start** from stage 1.
4. **Per-segment libultra cluster floor** — the lowest surviving hit that has
   ≥3 other hits within ±0x800. In boot this is `0x800D3A80`
   (`osViSetYScale`); everything below it is game code that the signature
   scanner mislabelled (`osSetTime@800C7A60`, `myfree`, `__osGetActiveQueue`,
   `osDestroyThread@800D1640/1680`, `osProfileFlush@800D2EAC`). In every
   overlay no cluster exists at all, so all overlay hits are rejected — which
   is right: this game links libultra only into the boot segment.
5. **Duplicate names** resolved by neighbourhood density (count of other
   accepted hits within ±0x2000). This is what picks
   `osSetTime = 0x800D7A20` over `0x800C7A60`, `osDestroyThread = 0x800E13B0`
   over `0x800D1640`, and `__osSiGetAccess/__osSiRelAccess/`
   `__osSiCreateAccessQueue` from the second `siacs.c` copy (0x800E0EA0…),
   which is the copy `osContStartReadData` actually calls.

### Call-graph anchors (override everything above)

Re-derived at run time from the ROM, not taken on trust from `segment_map.md`:

```
DMA wrapper 800D1D10 -> osCreateMesgQueue 800D8B80, osInvalDCache 800D6460,
                        osEPiStartDma    800D8A00, osRecvMesg    800D8D00
code-seg loader 800C38C8 -> osInvalICache 800D63E0, osInvalDCache 800D6460
```

The wrapper is validated first (function start, exactly 4 `jal`s, reads a
pointer out of the boot `.bss`). Note: it reads the cart ROM handle from
**`0x8013C3A0`**, not `0x8014C3A0` as stated in `segment_map.md` §b.1 — that
appears to be a typo in the map (`lui $a0, 0x8014` / `lw $a0, -0x3C60($a0)`).

### Manual, call-graph-derived names

Three functions n64sym cannot name (it only produces a sub-object label) had to
be named anyway, because leaving them unnamed makes N64Recomp emit bodies that
call `ignored_funcs` helpers which by contract have neither a generated body nor
a librecomp implementation. Each is applied only if the function actually calls
every listed already-accepted name:

| vram | name | evidence |
|---|---|---|
| 0x800D73E0 | `osInitialize` | calls `osUnmapTLBAll@800DC280`, `osMapTLBRdb@800DC2D0`, `__osSetSR@800DB830`, `__osSpRawWriteIo@800DB8B0`, `osPiRawReadIo@800DC330`; `segment_map.md` §c records that the two TLB functions have exactly one caller each, at 0x800D7560/0x800D7568 |
| 0x800DA4F0 | `viMgrMain` | calls `__osViSwapContext@800E0850` and `__osTimerInterrupt@800DC71C`; sits between `osCreateViManager@800DA370` and `osViSetEvent@800DA680`, i.e. the vimgr.c object layout; n64sym labels it `vimgr_text_0180` |
| 0x800DB2F8 | `_MakeMotorData` | calls `__osContAddressCrc@800E0F60`; builds the `FF 23 01 03 C0` rumble PIF block; sits between `__osMotorAccess@800DB190` and `osMotorInit@800DB404`; n64sym labels it `motor_text_0168` |

Without these three, the generated C referenced 10 undeclared
`*_recomp` externs. With them, zero.

### Runtime-critical names (spec stage 2.3)

All 19 required names are accounted for: **18 assigned and structurally
verified, 1 explicitly absent.**

| name | vram | status | evidence |
|---|---|---|---|
| osRecvMesg | 800D8D00 | verified | call-graph anchor (4th jal of the DMA wrapper) |
| osSendMesg | 800D95F0 | verified | tests `mq->validCount(+8)` against `mq->msgCount(+0x10)` — the queue-full test that distinguishes it from `osRecvMesg` |
| osCreateThread | 800D76A0 | verified | stores id@0x14, entry@0x38/0x3C, sp@0xF0/0xF4 and plants `__osCleanupThread` 800DC1F0 into the thread frame |
| osStartThread | 800D77F0 | verified | `lhu` state@0x10, compares OS_STATE_STOPPED(1)/OS_STATE_WAITING(8) |
| **osPiStartDma** | — | **absent** | see below |
| osEPiStartDma | 800D8A00 | verified | call-graph anchor; stores piHandle into `OSIoMesg+0x14`, sets `hdr.type` 0xF/0x10, returns −1 when `__osPiDevMgr` is inactive |
| osSpTaskLoad | 800DA91C | verified | reads `OSTask.ucode_boot(+0x38)+0xBFC`, writes SP_STATUS 0x2B00, DMAs to IMEM 0x04001000 |
| osSpTaskStartGo | 800DAAAC | verified | writes SP_STATUS 0x125 (clr_halt \| clr_broke \| set_intr_break) |
| osViSwapBuffer | 800DAB70 | verified | `__osDisableInt`, then stores the framebuffer into `__osViNext->framep(+4)` |
| osAiSetNextBuffer | 800D8E60 | verified | the AI hardware-bug workaround `addiu <r>, <r>, -0x2000` |
| osContInit | 800DABC0 | verified | PIF ram command setup + ≥3 helper calls |
| osContStartReadData | 800DAF00 | verified | `__osSiGetAccess` / `__osPackReadData` / `__osSiRawStartDma` chain |
| osGetCount | 800E0B50 | verified | exact 3-word body `mfc0 v0, Count; jr ra; nop` |
| osInvalDCache | 800D6460 | verified | call-graph anchor; cache ops {1,0x11,0x15} incl. Hit_Invalidate_D, dcache 0x2000, 16-byte lines |
| osInvalICache | 800D63E0 | verified | call-graph anchor; cache ops {0,0x10}, icache 0x4000, 32-byte lines |
| osWritebackDCache | 800DC200 | verified | cache ops {1,0x19} (Hit_Writeback_D), dcache 0x2000 — distinguishes it from `osInvalDCache`, which has the same size/line constants |
| osCreateMesgQueue | 800D8B80 | verified | call-graph anchor; `sw zero,8/0xC(a0); sw a2,0x10(a0); sw a1,0x14(a0)` |
| osSetEventMesg | 800DA6F0 | verified | indexes an 8-byte-per-entry table by `event<<3` at base `__osEventStateTab` 0x8016A620, stores mq@+0/msg@+4 |
| osVirtualToPhysical | 800D70A0 | verified | KSEG0/KSEG1 range test + 0x1FFFFFFF mask; `__osProbeTLB@800DB6E0`'s only caller is inside it |

**`osPiStartDma` is absent from this ROM.** n64sym produces no signature match
for it anywhere, and the load map is independently conclusive: `segment_map.md`
§b.1/§c establishes that all 10 DMA call sites in the entire 8 MiB image go
through `osEPiStartDma` (0x800D8A00), reached from exactly six callers of the
`func_800D1D10` wrapper plus the music streamer. The game never links
`osPiStartDma`. Its sibling `osEPiStartDma` is present and verified, which is
what librecomp needs.

---

## 3. Symbols emission

`config/knife_edge.us.syms.toml`: 19 sections — 18 code segments plus
`boot_bss` (`vram 0x800EEF50`, `size 0x7BCA0`, `functions = []`, `rom` pointed
at the end of the boot image so the required key is present and word-aligned;
with no functions nothing is ever read from it).

Decisions beyond the spec:

* **Section extents use the segment's ROM size, not the descriptor's
  `vramEnd`.** Nine descriptors declare a `.bss` tail past the DMA'd image
  (`segment_map.md` §a.1); including it would put section VRAM ranges outside
  the ROM. No function lives there, and stopping at the ROM size keeps
  `rom + (vram − section.vram)` in range for every symbol. Assertions in
  `gen_syms.py` enforce word alignment and in-section containment for all 1115
  functions.
* **Section size covers text *and* the segment's data**, not just the text
  range. This is deliberate: an in-section `jal` whose target N64Recomp cannot
  match creates a `static_…` function rather than aborting, so a mistake
  degrades instead of failing. (In practice zero statics were created.)
* **No `relocs` key anywhere.** `segment_map.md` §c establishes that all 69
  loads are to fixed hard-coded addresses with no relocation pass, so no
  section is marked relocatable — which is also what makes the cross-slot
  ambiguity resolvable by N64Recomp's runtime lookup.
* **Name uniqueness.** Unnamed functions are `func_{vram:08X}` in boot and
  `func_{vram:08X}_{segment_rom:06X}` elsewhere. The ROM suffix is required:
  six mission overlays all start at 0x801D21F0 and eight menu overlays at
  0x8017B0C0, and N64Recomp emits one C function per symbol name, so bare VRAM
  names would be duplicate C definitions.
* **`[patches].renamed` is auto-populated** with the 95 accepted names that are
  in none of N64Recomp's three built-in sets. Those are emitted verbatim as C
  functions, so `fabs`, `fabsf`, `_bzero`, `_bcopy`, `_bcmp`, `_Printf`,
  `_Ldtob`, … collide with the real declarations in `<math.h>`/`<string.h>`.
  Routing them through `renamed` emits them as `<name>_recomp`, still fully
  recompiled. Before this, 8 of 10 sampled files failed to compile.

`config/knife_edge.us.toml`: `entrypoint = 0x800C2400`,
`rom_file_path = "../build/knife_edge.z64"`,
`output_func_path = "../build/RecompiledFuncs"`,
`functions_per_output_file = 50`; all paths relative to `config/`.

---

## 4. N64Recomp run

```
$ deps/N64Recomp/build/N64Recomp config/knife_edge.us.toml
Function count: 1115
exit 0
```

* **0** `No function found for jal target` (the hard-error case).
* **0** auto-created `static_…` functions — every `jal` target is an explicitly
  listed symbol.
* **17** `Ambiguous jal target … falling back to function lookup` info lines, at
  exactly 4 addresses: `0x8017B0C0` (4×), `0x801DC320` (2×), `0x801D21F0` (6×),
  `0x801D2270` (5×). These are the shared overlay slots; runtime lookup is the
  correct and expected resolution for them.
* **1** `Indirect tail call in recomp_entrypoint` — the entry stub at
  0x800C2400 clears BSS then `jr`s to the boot proc, so the rename to
  `recomp_entrypoint` worked (N64Recomp hard-errors if it cannot find a
  function at vram 0x800C2400 with rom 0x1000).

Output: `build/RecompiledFuncs/` — 20 × `funcs_N.c` (19 MB), `funcs.h`,
`lookup.cpp`, `recomp_overlays.inl` (19 sections, `relocs = nullptr`,
`overlay_sections_by_index = {-1}`).

## 5. Compile smoke

All 20 generated files pass `clang -fsyntax-only -std=c11 -I
deps/N64Recomp/include -I build/RecompiledFuncs` with **zero errors and zero
warnings**. A 10-file sample was additionally compiled to objects with
`clang -c -std=c11 -O1` (clang 19.1.7):

```
funcs_0  ok  82888 B      funcs_10 ok 129504 B
funcs_2  ok  64320 B      funcs_12 ok 119472 B
funcs_4  ok  56168 B      funcs_14 ok 174728 B
funcs_6  ok 141920 B      funcs_16 ok 180136 B
funcs_8  ok  94784 B      funcs_19 ok 230176 B
```

`recomp.h` comes from `deps/N64Recomp/include`; `funcs.h` from the output
directory. `recomp_overlays.inl` and `lookup.cpp` are C++ and need librecomp's
`librecomp/sections.h`, so they are out of scope here (full build integration
happens elsewhere).

---

## 6. Determinism

`make -C analysis clean && make -C analysis` reproduces byte-identical
`functions.json`, `libultra_names.json` and both TOMLs. All three scripts are
argparse CLIs with defaults that need no arguments. n64sym output is cached
under `analysis/out/n64sym/` (40 KB of text, committable); `make refresh`
re-runs the scanner.

---

## 7. Remaining risks

1. **Under-split giant functions in the mission overlays.** `seg_34B590` has a
   0x935C-byte function, `seg_1B66F0` a 0x87C8-byte one. Every function ends in
   a terminator and no jump/pointer table points into their interiors, so
   nothing *known* is missing — but a function reached only through a pointer
   stored at runtime (not a static table) would be invisible to all five rules
   and would silently be absorbed into its predecessor. Symptom at run time
   would be an "unknown function" lookup failure on a `jalr`, not a
   miscompile.
2. **`xjal` starts in shared slots.** 209 function starts come from another
   segment's `jal`. They pass the branch-crossing and terminator-precedence
   filters, but for the eight overlays sharing `0x8017B0C0` a coincidence is
   conceivable: overlay A's function address happens to land on a
   terminator-preceded, branch-free word in overlay B. That would split one of
   B's functions in two, and the first half would fall off its end. No
   instance was detected (the end-terminator audit found exactly one
   non-terminating function and it is a genuine noreturn), but the check is
   heuristic, not proof.
3. **Two linked copies of `siacs.c`.** `__osSiCreateAccessQueue`,
   `__osSiGetAccess` and `__osSiRelAccess` each exist twice (0x800DFFC0/
   0x800E0010/0x800E0054 and 0x800E0EA0/0x800E0EF0/0x800E0F34). Only the
   second copy is named; the first is recompiled as `func_…`. The named copy is
   the one `osContStartReadData` calls, which is the path that matters, but if
   anything reaches the other copy it will run recompiled SI register pokes
   instead of librecomp's HLE. Same caveat applies to the duplicated
   `alAuxBusParam`.
4. **`osProfileFlush`, `__osGetActiveQueue` and friends were dropped by the
   cluster floor.** If any of those below-floor hits was actually correct, the
   function is now recompiled verbatim under a `func_…` name instead of being
   ignored. All of them are in the game-code region 0x800C2400–0x800D3A80,
   and none is in the runtime-critical set, so the failure mode is a redundant
   recompiled body rather than a conflict — but it is an unverified assumption.
5. **`ignored_funcs` externs.** The three manual names removed all 10 known
   undeclared `*_recomp` references. If future re-runs change function
   boundaries, new ones can appear; the check is
   `clang -fsyntax-only` over `build/RecompiledFuncs/funcs_*.c`, which
   `make -C analysis smoke` does not currently run over *all* files (it
   compiles a 10-file sample). Worth wiring into CI as a full sweep.
6. **Per-segment `.bss` tails are still unzeroed** (`segment_map.md` §d open
   question 1). Not a symbols-pipeline problem, but it will surface as
   uninitialised-memory behaviour once the recompiled game runs.
7. **The boot text/ucode boundary is asserted, not proven.** `0x800E51F0` is
   backed by three independent signals (last `jr $ra` at 0x800E51DC + padding,
   n64sym's rspbootTextStart, opcode statistics in `segment_map.md` §d), but
   it is a constant in `find_functions.py` (`BOOT_TEXT`), not derived.
