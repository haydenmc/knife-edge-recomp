# The mission letterbox, and the `full_height` enhancement

Missions (gameplay and in-mission cutscenes) render 320×200: framebuffer rows
20..219, with 20-line bands top and bottom. Real N64 hardware footage shows the
same black bars, so this is faithful, deliberate behavior — but the attract
flythrough renders all 240 lines with the same engine, which is what made a
"fill the screen" enhancement plausible. This doc records the reverse
engineering behind that enhancement (the `full_height` flag, see
`enhancements.md`) so the mechanism is never re-derived.

Method note: everything below was established read-only — a static scan of the
ROM, greps over the recompiled C, live RDRAM dumps/pokes of the running port
(the process's 8 MiB RDRAM block is easy to locate from `/proc/<pid>/maps`;
RDRAM is stored byte-swapped per 32-bit word, so plain little-endian u32
reads/writes at `base + (vram - 0x80000000)` are correct) — and each key claim
was re-verified independently before the enhancement was designed on top of it.

## Headline: the letterbox is only an RDP scissor

The viewport stays 320×240 and the projection stays fovy 30° / aspect 4:3 in
missions *and* in attract mode. The scene for rows 0–19 and 220–239 is already
transformed, clipped and rasterized every frame; the scissor throws it away.
Opening the scissor to 240 lines reveals genuinely more scene at unchanged
pixel scale — an uncrop, not a stretch. Visible vertical FOV goes 25.17° →
30.0° (2·atan(tan 15° · 100/120) → the full 30°).

## 1. The viewport is static and never letterboxed

The whole ROM contains exactly four `gSPViewport` commands (F3DEX2 `G_MOVEMEM`,
w0 = `0xDC080008`), found by an exhaustive 4-aligned scan of the 8 MiB image.
They reference two `Vp` structs, both static data in the segment
ROM 0x02DB50 → 0x8016ABF0 (`analysis/out/segment_map.md`):

* **0x8016AEC0** (ROM 0x02DE20) — `vscale=(640,480,511,0)`,
  `vtrans=(640,480,511,0)` → **320×240, centered, full frame** (lo-res).
* **0x8016AED0** (ROM 0x02DE30) — `(1280,960,511,0)`×2 → 640×480 (hi-res,
  used by the 2D front-end screens).

Live RDRAM reads at four game states (boot logo, title/menu, attract, stage-1
gameplay) plus a 210 s change-poll: 0x8016AEC0 always reads 640/480 — never
rewritten.

The lo-res init DL at 0x8016ABF0 (dumped live during a mission) sets that
viewport and `gSPClipRatio(FRUSTRATIO_2)` — the RSP clips at 2× the viewport,
so geometry generation already covers well beyond the 240 rows.

## 2. What actually changes: two globals and one scissor

A small graphics-state block in the boot section:

| address | meaning |
|---|---|
| 0x8010BAD0 | u16 mode flags (0x1000 = hi-res, 0x40 = blanked) |
| **0x8010BAE0** | **screen width** (320 / 640) |
| **0x8010BAE4** | **screen height** (240 / 200 / 480 / 420 / 400 / 0) |
| 0x8010BAE8 | saved height for the blank/unblank pair |
| 0x8010BAEC | current gfx DL write pointer |

A grep over the entire recompiled output for every reference to the width and
height words returns **21 hits, all in `funcs_0.c`, all inside five boot
functions** (setters + the two clear/scissor builders). Nothing else in the
ROM reads them: the height is *not* an input to the viewport, the projection,
the culler, or HUD layout. This negative result is what makes the enhancement
safe and small.

The functions:

| function | role |
|---|---|
| `func_800C2500` | gfx init; W=320, H=240 |
| **`func_800C3044(W, H)`** | **select lo-res mode**: stores W→0x8010BAE0, H→0x8010BAE4, clears flag 0x1000, swaps the gfx ucode task. **The enhancement hooks this.** |
| `func_800C30F4(W, H)` | hi-res twin (sets flag 0x1000) |
| `func_800C3234` / `func_800C3264` | blank (save H, set H=0) / unblank (restore) |
| `func_800C277C` / `func_800C2BCC` | per-frame clear + scissor builders (lo/hi-res); read H at 0x800C29C0 / equivalent |

The 20-line band height is never stored anywhere — the scissor builder
computes `uly = (240 − H)/2` at 0x800C29D0 (and `ulx = (320 − W)/2`).

## 3. Where 200 comes from: one immediate, one call site

All 13 call sites of the two mode setters, with argument immediates recovered
from the generated C:

| jal VRAM | callee | section | W | H |
|---|---|---|---|---|
| **0x8019CE38** | `func_800C3044` | **seg_1501A0 (in-mission overlay)** | 320 | **200** |
| 0x801DC354 | `func_800C3044` | seg_0BA450 / seg_4D5FC0 (front-end, two overlay copies) | 320 | 240 |
| 0x801E02F4 | `func_800C3044` | seg_0BA450 | 320 | 240 |
| 0x8017B0F0, 0x8017BAE8, 0x8017B108, 0x8017BEC4 | `func_800C30F4` | menu overlays | 640 | 480 |
| 0x8017B0F4 (×2), 0x8017DA34, 0x8017B688 | `func_800C30F4` | menu overlays | 640 | 420 |
| 0x8017E0B0 | `func_800C30F4` | menu overlay | 640 | 400 |

The 640×420 rows are the title/menu safe-area inset ((480−420)/2 = 15 lines in
240-space) — same mechanism, good cross-check. The mission site, in
`func_8019CE04_1501A0` (the mission entry/main loop already known from
`EXTRA_SPIN_YIELD_HOOKS`):

```
8019CE28  24040140  addiu $a0, $zero, 0x140   ; 320       ROM 0x17F8D8
8019CE38  0C030C11  jal   0x800C3044                      ROM 0x17F8E8
8019CE3C  240500C8  addiu $a1, $zero, 0xC8    ; 200 <==   ROM 0x17F8EC
```

The `(W,H) = (320,200)` pair is unique to this one site — which is why the
enhancement's hook guards on exactly that pair.

## 4. The mission frame's clear sequence (live DL capture)

`func_800C25FC(r,g,b,a)` begins each frame: init DL + render-mode DL, then the
clear builder. Captured from RDRAM during stage 1 (frame DL at 0x8010BAF8,
4346 words, containing **no other scissor or viewport command**):

```
de000000 8016abf0   gSPDisplayList(lo-res init: viewport 320x240 + clip ratio)
de000000 8016ac60   gSPDisplayList(render-mode setup)
e7000000 00000000   gDPPipeSync
fe000000 002ea000   gDPSetDepthImage(0x802EA000)
e3000a01 00300000   gDPSetCycleType(G_CYC_FILL)
ff10013f 002ea000   gDPSetColorImage(w=320 -> Z buffer)
f7000000 fffcfffc   gDPSetFillColor(max depth)
f64fc3bc 00000000   gDPFillRectangle(0,0,319,239)   <- Z clear
ed000000 005003c0   gDPSetScissor(0,0, 320,240)     <- FULL
ff10013f 0030f800   gDPSetColorImage(-> frame buffer)
f7000000 00010001   gDPSetFillColor(0x0001) = BLACK
f64fc3bc 00000000   gDPFillRectangle(0,0,319,239)   <- paints the BANDS
ed000050 00500370   gDPSetScissor(0,20, 320,220)    <- LETTERBOX rows 20..219
f7000000 38413841   gDPSetFillColor(0x3841) = scene color
f64fc3bc 00000000   gDPFillRectangle(0,0,319,239)   <- interior
e7000000 00000000   gDPPipeSync
... scene ...
```

Nothing after the scene repaints the bands, so once the scissor is open the
bands simply cease to exist. During attract (H=240) the identical builder
degenerates to a single full-screen clear — exactly the DL shape the
enhancement produces.

### Side finding: RT64 renders the bands the wrong color (vanilla fidelity bug)

The DL asks for **black** bands (fill color 0x0001), and hardware shows black.
Our port renders them dark maroon — measured band pixel `srgb(57,8,0)`, an
exact match for the *scene* fill color 0x3841 = RGBA5551 (7,1,0,1) of the
third, scissored fill. So RT64 is not honoring the narrowed scissor for that
`FILLRECT` (or coalesces the fills). Purely cosmetic, vanilla-only (invisible
with `full_height` on), and a candidate for an upstream report — recorded here
so it is never attributed to the enhancement. Per project policy we did not
patch `deps/` for it.

## 5. The projection is letterbox-independent

The projection is loaded with `G_MTX` param `PROJECTION|LOAD` at 0x800C5934
(inside `func_800C58E8`; four sibling helpers) from `[0x80113AF0]+0x30`, a
double-buffered matrix pool. Read live:

| | mission (H=200) | attract (H=240) |
|---|---|---|
| m[0][0] | 2.79903 | 2.79903 |
| m[1][1] | 3.73204 | 3.73204 |
| m[2][2], m[3][2] | −1.00166, −2.00166 | −1.00266, −4.00534 |

m[1][1] = cot(fovy/2) = 3.73204 → fovy = exactly 30°; m[1][1]/m[0][0] =
1.33333 → aspect = exactly 4:3. Only near/far differ (scene-dependent). Had
the aspect tracked the letterbox it would be 320/200 = 1.6. So the projection
is a plain `guPerspective(30°, 4/3, …)` matched to the full frame, identical
in both modes — the enhancement must not (and does not) touch it. (Honest
gap: `guPerspective` is not a named symbol in our table and the code filling
the pool slot was not located; the live matrix measurements make it
unnecessary.)

## 6. Empirical proof

Poking 240 into the height global 0x8010BAE4 of a live stage-1 mission (done
twice, in two independent sessions): the very next frames render clean
full-height 320×240 — ~20 % more scene vertically at unchanged pixel scale,
HUD elements (health dial, S-BOMB gauge, reticle, dialogue box) at their
absolute positions and looking natural, gameplay continuing with no depth
glitches, no missing geometry, no artifacts over ~45 s. Poking 200 back
restores the letterbox cleanly. Composes with `--profile enhanced`
(high_resolution + widescreen): full-window 16:9, HUD still pinned to the
centered 4:3 region.

Unlike `widescreen`, this expansion has **no pop-in risk**: the game's own
30°/4:3 frustum plus `gSPClipRatio(FRUSTRATIO_2)` already cover all 240 rows,
so the revealed bands contain properly culled, properly clipped geometry.

## 7. The shipping patch

See `enhancements.md` (flag `full_height`) for the player-facing summary. The
mechanism is a single N64Recomp entry hook emitted by `analysis/gen_syms.py`:

```toml
[[patches.hook]]
func = "func_800C3044"
text = "ctx->r5 = (int32_t)ke_view_height((uint32_t)ctx->r4, (uint32_t)ctx->r5);"
```

with `ke_view_height` in `src/main/full_height.cpp` returning 240 iff the flag
is on and (w,h)==(320,200), else h unchanged — so the front-end's (320,240)
calls and the blank/unblank H=0 pair are untouched, and the save/restore pair
stays coherent (0x8010BAE8 saves and restores 240).

Design notes, for the record:

* **Callee hook, not call-site**: N64Recomp emits a `jal`'s delay-slot
  instruction *before* the call, so a `before_vram` hook at 0x8019CE38 would
  run before `a1 = 200` is assigned and be overwritten. There is no in-caller
  VRAM between the delay slot and the call.
* **Not the height read in the scissor builder** (0x800C29C0): overriding
  there would also override the H=0 blanked state used by fades, breaking
  them.
* **Not an instruction patch** of the 0x240500C8 word (though
  `value = 0x240500F0` works and is the quickest manual experiment): an
  instruction patch cannot be runtime-gated, violating the "every deviation is
  toggleable" rule.

## 8. Known risks / open verification

* Stale Z in the band rows on the first mission frame only (the Z clear runs
  under the previous frame's scissor) — theoretical, not observed even in the
  harder mid-mission poke case.
* Mission-results / stage-clear screens run under the same 320×200 setting and
  so widen too — consistent, but not yet eyeballed. Stages beyond 1 not yet
  hands-on verified (mechanism is stage-independent; edge content is not).
* In-mission cutscenes lose their bars (same mechanism, not a separate
  cinematic-bar system). Inherent to the enhancement.
* Seeing ~20 % more vertically reveals enemies slightly earlier. Inherent;
  why the flag defaults off and is not yet in the `enhanced` set.

## 9. Address quick-reference

```
0x8010BAD0  u16  gfx mode flags (0x1000 = hi-res, 0x40 = blanked)
0x8010BAE0  u32  screen width   (320 / 640)
0x8010BAE4  u32  screen height  (240 / 200 / 480 / 420 / 400 / 0)
0x8010BAE8  u32  saved height (blank/unblank)
0x8010BAEC  ptr  gfx DL write pointer
0x8016AEC0  Vp   lo-res viewport 320x240 (ROM 0x02DE20) - never modified
0x8016AED0  Vp   hi-res viewport 640x480 (ROM 0x02DE30)
0x8016ABF0  DL   lo-res init (viewport + clip ratio)
0x8016AC28  DL   hi-res init
0x8016AC60  DL   render-mode setup
0x80113AF0  ptr  matrix pool base; +0x30 projection, +0x70 view

0x800C2500  gfx init (W=320, H=240)
0x800C25FC  begin frame(r,g,b,a) -> init DLs + clear builder
0x800C277C  lo-res clear + scissor builder (H read at 0x800C29C0)
0x800C2BCC  hi-res twin
0x800C3044  set lo-res mode(W, H)   <== the enhancement's hook
0x800C30F4  set hi-res mode(W, H)
0x800C3234  blank / 0x800C3264 unblank
0x800C5934  emits G_MTX PROJECTION|LOAD
0x8019CE04  func_8019CE04_1501A0, mission entry/main loop
0x8019CE3C  addiu $a1,$zero,0xC8 == the 200 (ROM 0x17F8EC, word 0x240500C8)
```
