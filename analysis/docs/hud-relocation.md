# HUD relocation — Phase 1: identification

Goal of the eventual enhancement (`hud_relocation`, **not** implemented here):
when `widescreen` / `full_height` are on, re-anchor the in-mission HUD to the
true window corners instead of leaving it pinned inside the centred 4:3 /
320×200-era box. Phase 1 answers *what the HUD actually is at display-list
level* and whether RT64's `gEXSetRectAlign` is the right lever.

Everything below is measured, not inferred: it comes from a new display-list
dumper (§1) run against real gameplay under Xvfb (§2). No behaviour was
changed; `scripts/smoke_test.sh` still passes with the dumper compiled in and
`KE_DL_DUMP` unset.

**Headline: every HUD element is a `G_TEXRECT`.** Not one of them is a
textured triangle. Each lives in its own self-contained, `G_ENDDL`-terminated
sub-display-list at a *fixed RDRAM address*, called by a single 8-byte `G_DL`
push from a contiguous run at the tail of the frame's main display list. That
is close to the best possible shape for `gEXSetRectAlign` surgery.

---

## 1. The dumper (`KE_DL_DUMP`)

`src/main/rt64_render_context.cpp`. `send_dl` walks the game's own display
list — the address *before* `maybe_inject_rate_prologue` may substitute the
`high_framerate` prologue — and appends one compact text line per interesting
command. It is read-only: it never writes RDRAM and never changes the entry
address handed to RT64. Unset, it costs one cached null test per frame
(function-local `static`), which is why it can stay in the tree as a permanent
diagnostic alongside `KE_PERF` / `KE_AUDIO_DUMP`.

```
KE_DL_DUMP=<path>          append the dump here (text, one line per command)
KE_DL_DUMP_AFTER_S=<sec>   start dumping this long after the first display
                           list (default 0). Needed: a mission frame is ~2000
                           commands / ~100 KB of text at ~27 fps, so dumping
                           from boot fills any cap long before scripted input
                           reaches gameplay.
KE_DL_DUMP_FRAMES=<n>      stop after n dumped frames (default 0 = unlimited)
```

A hard 40 MB byte cap, a 16384-command-per-frame cap, an 8-deep return stack
and an RDRAM-bounds check on every read mean a malformed stream can waste a
frame but cannot wedge or crash the graphics thread.

Line format — `<frame> <index> @<physaddr> <OP> <params>`, preceded per frame
by `=== frame N entry=PPPPPP ===`. Coordinates are printed in pixels
(the raw 10.2 fixed-point value / 4). Consecutive `G_TRI1`/`G_TRI2`/`G_QUAD`
runs collapse to one `TRIxN` line. `G_RDPPIPESYNC` is dropped (one per state
change, pure noise) — this is why indices have small gaps.

Decoding was written against `deps/rt64/src/gbi/rt64_gbi_f3dex2.cpp`,
`rt64_gbi_rdp.cpp`, `rt64_gbi_f3d.cpp` and
`deps/rt64/src/shared/rt64_f3d_defines.h`, not from memory, so what is logged
is what RT64 itself acts on: same `{w0,w1}` native-u32 read as
`RT64::DisplayList`, same `G_DL` push/branch bit (`w0` bit 16, clear = push),
same `G_MOVEWORD`/`G_MW_SEGMENT` segment table, same `fromSegmented` +
`0x00FFFFF8` mask, same "texrect is followed by two continuation words whose
`w1` carry s/t and dsdx/dtdy".

## 2. Captures

Four runs, all `DISPLAY=:99` Xvfb 1280×720 + lavapipe, dummy audio, scratch
`KE_DATA_DIR`, dumps written outside the repo. Menus driven with `xdotool`
using the held-key recipe from `timing-and-mission-debug.md` §3.1 (keys held
0.4 s; `windowfocus`, not `windowactivate`).

| capture | profile | window | frames | what it caught |
|---|---|---|---|---|
| `cap_title` | vanilla | +6 s | 40 | boot / title, hi-res 640×480 front end |
| `cap_intro` | vanilla | +56 s | 220 | mission-1 intro cutscene (radio dialogue box + portrait) **and** the first ~156 gameplay frames |
| `cap_mission` | vanilla | +72 s | 150 | mission-1 gameplay, aim driven (WASD held) and firing (Left Shift) |
| `cap_enh` | enhanced | +72 s | 40 | same, `--profile enhanced` (high_resolution + widescreen + full_height) |

Gameplay was confirmed by screenshot (`import -window root`) — health dial,
S-BOMB gauge, reticle visibly displaced to the top-right by the scripted aim —
and by `KE_PERF=1` reporting a steady 26–27 frames/s throughout.

Driving script and analysis scripts are throwaway and live in the job scratch
dir, not the repo (repo policy: no data dumps).

---

## 3. Q1 — what each element is, and where

All coordinates are in the game's 320×240 framebuffer space; `ul` is the
texrect's upper-left. Every row below is a `G_TEXRECT` (opcode 0xE4), tile 0,
`dsdx/dtdy = 1024/1024` (1:1, unscaled) unless noted.

### 3.1 In-mission HUD (fingerprint table)

| element | sub-DL @ | texture (`G_SETTIMG` w1) | size | ul | frames seen | moves? |
|---|---|---|---|---|---|---|
| **aiming reticle** | `0x801C8470` | `0x8003E480` | 32×32 | `(cx−16, cy−16)` | 150/150 | **yes** |
| health dial: backing | `0x801BCE30` | `0x8003EC80` | 64×48 | (20,172) | 150/150 | no |
| health dial: green arc | `0x801BD4F0` | `0x8003F600` | 48×48 | (20,172) | 25/150 | no |
| health dial: green arc (alt) | `0x801BDBB0` | `0x80040380` | 48×48 | (20,172) | 125/150 | no |
| health dial: jet glyph | `0x801BD070` | `0x8003F280` | 32×32 | (28,180) | 150/150 | no |
| health dial: number panel | `0x801BD2B0` | `0x8003F480` | 32×24 | (54,179) | 150/150 | no |
| health % digits (2–3) | `0x800F2B50` | `0x8016B3C8` | 8×13 | (59\|67\|75, 183) | 325 rects/150 frames | no (glyph via s/t) |
| **S-BOMB gauge**: 5 segments | `0x801C25F0` | `0x80045100` … `0x80045500` | 16×32 | (215\|231\|247\|263\|279, 188) | 150/150 | no |
| S-BOMB: blinker | `0x801C31F0` | `0x80045880` | 16×8 | (215,207) | 110/150 | no (blinks) |
| full-screen flash | `0x801B6CB0` | `0x801A0C90` | 319×239 | (0,0) | 8/150 | n/a |

Derived bounding boxes:

* **health cluster** (dial + digits): x 20…86, y 172…**220**
* **S-BOMB cluster**: x 215…**295**, y 188…**220**
* **reticle centre**: x ∈ [32, 288], y ∈ [36, 204]

The `220` is load-bearing: it is exactly the bottom row of the vanilla
320×200 letterbox (`letterbox-full-height.md` §4, scissor `0,20 → 320,220`).
Both bottom clusters sit flush against the letterbox floor. With
`full_height` the scissor opens to `0,0 → 320,240` (confirmed in `cap_enh`,
§3.4) and the HUD keeps its 220 bottom edge — i.e. **it now floats 20 px above
the true bottom**, which is exactly the artefact this enhancement exists to
fix. Horizontally the S-BOMB cluster ends 25 px short of 320 and the health
cluster starts 20 px in; those insets are the design's own margins and should
be preserved when re-anchoring.

The **health % digits are drawn from a shared boot-segment buffer**
(`0x800F2B50`, in the same BSS region as the main gfx DL buffers), in a
*separate* 2D group after a render-mode restore — not inside the health-dial
group. Phase 2 must handle it as its own unit even though it is visually part
of the bottom-left dial. The glyph is selected by the texrect's `s/t`
(`st=1024,1536` / `1280,1536` / `1792,1024` observed), not by a different
texture address, so the fingerprint for "a digit" is texture `0x8016B3C8` +
size 8×13, not a per-glyph address.

The **full-screen flash** (319×239, `dsdx=51 dtdy=34`, i.e. a 16×8 texture
stretched over the whole frame) shares the 2D block with the HUD and must be
**excluded** from any re-anchoring — it is a screen effect, not a HUD element.
Its 319×239 size makes it trivially separable.

### 3.2 The radio / dialogue box (in-mission cutscene)

During the mission-intro cutscene the same 2D block draws, again all
`G_TEXRECT`, a four-part overlay across the **top** of the frame:

| element | sub-DL @ | textures | tiles | extent |
|---|---|---|---|---|
| dialogue panel plane | `0x801C88F0` | `0x80033C00` + 0x40·n (133 tiles) | 133 × 16×8 | x 0…**304**, y **20**…76 |
| dialogue glyphs (2 text rows) | `0x80109550` | `0x800C0400` … `0x800C1380` | 32 × 16×16 | x 34…290, y 36 and 52 |
| portrait frame | `0x801D0AB0` | `0x80039180` … `0x8003A180` | 9 × 32×32 | 96×96 at (16,78) |
| portrait image | `0x801D1110` / `0x801D1C50` / … | `0x8003D180` … | 4 × 32×32 | 64×64 at (32,94) |

Note the panel's top edge is **20** — flush against the letterbox ceiling, the
mirror image of the HUD's 220 floor. Same ±20 px correction, opposite sign.
The panel is a 19×7 grid of 16×8 tiles each with its own texture address, so
"re-anchor the dialogue box" means moving 133 + 32 + 9 + 4 = 178 rects
coherently — mechanically fine (they share the group) but the biggest single
consumer of any per-rect cost.

**No top-centre "info marquee" appeared in any of the 346 gameplay frames**
dumped across three independent mission entries. The only thing that occupies the top band is this
dialogue box. If a marquee exists it belongs to a mission state we did not
reach (objective banner, WARNING, boss intro, mission-complete). Recorded as
open question O1 rather than guessed at.

### 3.3 The front end draws no rects at all

`cap_title` (hi-res 640×480 front end, 40 frames): **zero** `G_TEXRECT` and
zero `G_FILLRECT` other than the clears. The title/menu 2D is entirely
`G_VTX` + `G_TRI1/G_TRI2` — textured quads through the RSP. `gEXSetRectAlign`
would be inert there; front-end relocation, if ever wanted, is a
`gEXSetViewportAlign`/matrix problem. This is a clean split: *missions are
rect-based, the front end is triangle-based.*

### 3.4 Profile invariance

`cap_enh` (`--profile enhanced`) reproduces the mission table byte-for-byte:
identical sub-DL addresses, identical texture addresses, identical texrect
coordinates, identical group ordering. The **only** display-list difference
found is the scissor —

```
vanilla   SETSCISSOR mode=0 ul=0.00,20.00 lr=320.00,220.00
enhanced  SETSCISSOR mode=0 ul=0.00,0.00  lr=320.00,240.00
```

— which is `full_height` doing exactly what `letterbox-full-height.md` §7
says it does. `widescreen` and `high_resolution` leave the display list
untouched (they act on the projection matrix and on RT64's render target).
So phase 2 can be developed against a vanilla capture and will apply
unchanged in `enhanced`.

---

## 4. Q2 — contiguity and offsets

**Within an element: perfectly contiguous.** Each element's sub-DL is a
15–16 command self-contained blob ending in `G_ENDDL`. The reticle's, in full
(frame 20, `cap_mission`):

```
@1C8470 SETOTHERMODE_L E200001C 00504240
@1C8478 G_SETPRIMDEPTH (0xEE) 12340000
@1C8480 SETPRIMCOLOR FFFFFFC8
@1C8488 SETCOMBINE FC119623 FF2FFFFF
@1C8490 SETOTHERMODE_H E3001001 00008000
@1C8498 SETTIMG fmt=0 siz=2 addr=801A5D00      <- TLUT
@1C84A8 SETTILE tile=7 ... tmem=256
@1C84B8 LOADTLUT tile=7 count=15
@1C84D0 SETTIMG fmt=2 siz=2 addr=8003E480      <- the reticle texture
@1C84D8 SETTILE tile=7 fmt=2 siz=2 tmem=0
@1C84E8 LOADBLOCK tile=7 lrs=255 dxt=1024
@1C84F8 SETTILE tile=0 fmt=2 siz=0 line=2
@1C8500 SETTILESIZE tile=0 0,0 -> 31,31
@1C8508 TEXRECT ul=272,20 lr=304,52 tile=0     <- the one that moves
@1C8528 SETOTHERMODE_H E3001001 00000000
@1C8530 ENDDL
```

**Across elements: a contiguous run of `G_DL` pushes.** The tail of the main
display list, every mission frame:

```
+04F0  DL push 0x801A9718        (2D TLUT / render-mode helper)
+0500..+0548   10-command "enter 2D" state burst, ending
               SETOTHERMODE_L E200001C 0F0A7008
+0550  DL push 0x801C8470        reticle
+0558  DL push 0x801BD070        health: jet glyph
+0560  DL push 0x801BCE30        health: backing
+0568  DL push 0x801BD2B0        health: number panel
+0570  DL push 0x801BD4F0        health: arc      (or 0x801BDBB0)
+0578  DL push 0x801C25F0        S-BOMB gauge (all 5 segments inside)
      [+ DL push 0x801C31F0      S-BOMB blinker, when lit]
      [0x801B6CB0 full-screen flash, when present, is *prepended* to the run]
+0580..+0590   "leave 2D" (TEXTURE off, SETCOMBINE, SETOTHERMODE_L 0F0A4000)
+0598  DL push 0x8016AD10        render-mode restore
+05A8..+05F0   "enter 2D" burst again
+05F8  DL push 0x800F2B50        health % digits
+0600..+0610   "leave 2D"
+0618  RDPFULLSYNC
+0620  ENDDL
```

Across 150 mission frames only **four** distinct group sequences occur, and
they differ only by the three optional members (flash, blinker, which of the
two arc buffers). Order of the mandatory members never varies.

**Sub-DL addresses are stable; call-site offsets are not.** The sub-DL
addresses above were identical in `cap_mission`, `cap_intro` and `cap_enh` —
three separate process launches, two separate mission entries. But the offset
of the 2D block inside the main buffer ranged over **52 distinct values,
+0490…+07A8** in 150 frames (scene geometry ahead of it varies), and the main
buffer itself alternates between `0x8010BAF0` and `0x8010FAF0` (double
buffered). The element sub-DLs are *rebuilt every frame at their fixed
addresses* — the reticle's blob has two observed lengths (16 commands
normally, 15 when the preceding `SETOTHERMODE_L` is elided), so even the
texrect's offset *within* its own sub-DL is not perfectly fixed.

Conclusion for phase 2: **identify by target address, never by offset.** A
single forward scan of the main buffer for `G_DL` words whose resolved target
is one of the nine known HUD sub-DL addresses finds the whole block; that is
~200 main-buffer commands to scan (the nested ~2000 need not be walked).

---

## 5. Q3 — display-list branch/call structure

* **All `G_DL` commands are pushes (calls).** Zero `G_DL` branches across
  450 dumped frames in four captures — every sub-list returns via `G_ENDDL`.
* **Maximum nesting depth is 2** in mission frames (3 during the intro
  cutscene, 1 at the title). An 8-deep return stack is ample.
* **Segmented addressing is effectively unused.** Exactly one
  `G_MOVEWORD`/`G_MW_SEGMENT` per frame, always `segment 0 → 0x00000000`, so
  `fromSegmented(0x801C8470) = 0x001C8470` — the game addresses everything
  directly and the KSEG0 bit is stripped by RT64's `0x00FFFFF8` mask. Matrix
  and vertex pointers are already written as bare physical addresses
  (`MTX addr=00113B28`), textures and DLs as `0x80…`. Nothing needs segment
  tracking, but the dumper does it anyway and logs `raw` + `phys` for every
  address-bearing command.
* Frame size: 1564–2184 commands per mission frame, 244 at the title.

For phase 2 this means "branch out and back" is easy: an 8-byte `G_DL` push
word in the main buffer can be repointed at a trampoline in scratch RDRAM that
does `align → G_DL push (real sub-DL) → reset align → G_ENDDL`, and control
returns to the main buffer exactly as before.

---

## 6. Q4 — where the 2D phase begins

**Not at a scissor or viewport change.** A mission frame contains exactly two
`G_SETSCISSOR` commands and one `G_MOVEMEM` viewport, all inside the opening
clear sequence (`letterbox-full-height.md` §4); nothing between the 3D scene
and the HUD touches either.

The 2D phase is delimited by an **other-mode state burst**, emitted inline in
the main buffer, byte-identical every frame:

```
enter:  SETOTHERMODE_H E3000A01 00000000     (cycle type -> 1 cycle)
        TEXTURE tile=0 lvl=0 on=1 sc=32768 tc=32768
        SETOTHERMODE_L E2001E01 00000000
        SETOTHERMODE_H E3000C00 00000000
        SETOTHERMODE_H E3001201 00002000
        SETOTHERMODE_H E3001402 00000C00
        SETOTHERMODE_H E3000D01 00000000
        SETOTHERMODE_H E3000F00 00000000
        SETOTHERMODE_H E3001001 00000000
        SETOTHERMODE_L E200001C 0F0A7008     <- last command before the block
leave:  TEXTURE ... on=0
        SETCOMBINE FCFFFFFF FFFE793C
        SETOTHERMODE_L E200001C 0F0A4000     <- first command after
```

`SETOTHERMODE_L E200001C 0F0A7008` / `…0F0A4000` is therefore a reliable
frame-independent bracket for "2D rects follow / stop". It occurs twice per
mission frame (HUD group, then the digits group) and twice per cutscene frame.
It is a usable fallback identifier, but §4's address matching is stronger and
should be preferred; the bracket is best used as a *sanity assertion* (all
matched sub-DL calls must fall inside a bracket).

The HUD block is always the last thing in the frame — everything after it is
the render-mode restore, `G_RDPFULLSYNC`, `G_ENDDL`.

---

## 7. Feasibility verdict for `gEXSetRectAlign`

`gEXSetRectAlign(cmd, lorigin, rorigin, ulxOff, ulyOff, lrxOff, lryOff)`
(`deps/rt64/include/rt64_extended_gbi.h:269`, handler `setRectAlignV1` in
`deps/rt64/src/gbi/rt64_gbi_extended.cpp:77`) sets `RDP::extended.global.rect`,
which `RDP::drawRect` / `drawTexRect` apply to **every** subsequent
`G_TEXRECT`, `G_TEXRECTFLIP` and `G_FILLRECT`
(`deps/rt64/src/hle/rt64_rdp.cpp:1163`):

```
ulx += leftOffset;  uly += topOffset;  lrx += rightOffset;  lry += bottomOffset;
final_ulx = movedFromOrigin(ulx, leftOrigin);
final_lrx = movedFromOrigin(lrx, rightOrigin);
movedFromOrigin(x, ori) = x + ori * colorImage.width * 4 / G_EX_ORIGIN_RIGHT
```

with `G_EX_ORIGIN_LEFT = 0`, `CENTER = 0x200`, `RIGHT = 0x400`,
`NONE = 0x800` (pass-through). At `colorImage.width = 320` that is `+0`,
`+160 px`, `+320 px` in 10.2 units. The origin is what makes the renderer
place the coordinate relative to the *window* edge rather than inside the 4:3
sub-rect (`rt64_framebuffer_renderer.cpp:1646` — `regularOrigins` is only true
when both origins are `NONE`).

**Verdict per element:**

| element | verdict | notes |
|---|---|---|
| health dial (4 rects) | **feasible, clean** | `lorigin = rorigin = LEFT`, `topOffset = bottomOffset = +80` (10.2 for +20 px) to reach the `full_height` floor |
| health % digits | **feasible**, separate group | same offsets, but the group is called after a render-mode restore, so it needs its own align/reset pair |
| S-BOMB gauge (6 rects) | **feasible, clean** | `lorigin = rorigin = RIGHT` with `leftOffset = rightOffset = −1280` (−320 px in 10.2) to preserve the 25 px right margin; same +80 vertical |
| aiming reticle | **feasible but probably should NOT be re-anchored** | it is a world-relative cursor, not a corner-anchored widget — see §8 |
| dialogue / radio box (178 rects) | **feasible** | one group, `lorigin = LEFT`, `rorigin = RIGHT` for the full-width panel (it must *stretch*, not translate); `topOffset = bottomOffset = −80` to reach the `full_height` ceiling |
| front-end / title 2D | **not applicable** | triangles, §3.3 |
| full-screen flash (319×239) | **must be excluded**, or explicitly `LEFT`/`RIGHT` stretched | it is a screen effect |

Three things phase 2 must not miss:

1. **The alignment is sticky and is never reset per frame.**
   `RDP::clearExtended()` — the only thing that restores
   `extended.global.rect` — is reached only from `RDP::reset()`, which
   `Application::end()` calls at *shutdown*. `send_dl` calls
   `state->rsp->reset()`, not `state->reset()`. So an align left set at the
   end of one display list is still in force for the *next* frame's three
   full-screen clear `G_FILLRECT`s. Every align must be paired with an
   explicit reset to `G_EX_ORIGIN_NONE` / zero offsets.
2. **There is no vertical origin.** `gEXSetRectAlign` provides
   left/centre/right horizontal origins plus four static offsets; nothing
   anchors to top/bottom. That is fine here because the framebuffer height
   stays 240 and only the letterbox bands change, so the vertical correction
   is the known constant ±20 px — but it does mean the vertical part is a
   fixed offset, not a true anchor, and it must be conditioned on
   `full_height` being on.
3. **Extended GBI must be live only around our own commands.** Same
   discipline as the `high_framerate` prologue
   (`rt64_render_context.cpp::maybe_inject_rate_prologue`): hook-ENABLE →
   `gEXSetRectAlign` → hook-DISABLE, so the game's own display list is never
   executed with an extended opcode registered.

**Suggested mechanism (to be validated in phase 2):** in `send_dl`, scan the
main buffer (≈200 commands, cheap) for `G_DL` pushes whose resolved target is
a known HUD sub-DL address; for each match, write an 8-byte `G_DL` push into
the main buffer pointing at a per-element trampoline built in the scratch
region already used by `high_framerate` (`0x807FF000`, upper 4 MiB, with the
same one-time zero check). The trampoline is
`ENABLE → gEXSetRectAlign(anchor) → DISABLE → G_DL push(real sub-DL) →
ENABLE → gEXSetRectAlign(reset) → DISABLE → G_ENDDL`. Writing into the main
buffer is safe in the sense that the game rewrites it wholesale every frame
from the write pointer at `0x8010BAEC`, but it *is* a write into game RAM and
deserves the same fail-closed treatment as the scratch check.

---

## 8. The reticle, and the "let the reticle reach the widescreen edges" ambition

The dump independently confirms `mouse-aim.md`'s numbers from the *draw* side:

* the reticle is one 32×32 `G_TEXRECT`, `ul = (centre − 16)`;
* over 306 frames across two captures its centre spanned exactly
  **x ∈ [32, 288]** and **y ∈ [36, 204]** — i.e. 160 ± 128 and 120 ± 84, the
  clamps `mouse-aim.md` derives from the game's integrator, matched to the
  pixel;
* observed per-frame steps were 0, 8, 16 or 20 px — the 20-units/frame
  full-deflection step, plus the smaller steps produced by the deflection
  curve.

Consequences for the two ambitions:

* **Relocation.** The reticle is *not* a corner widget. Re-anchoring it with
  `gEXSetRectAlign` would only shift it; what "correct" means for a widescreen
  reticle is that it keeps tracking where the player is aiming in the widened
  view. Since `widescreen` widens the *projection* while the reticle stays a
  320-space rect, the honest treatment is a horizontal **rescale** of the
  reticle's x about the screen centre by the same factor the FOV was widened
  by, not an anchor. `gEXSetRectAlign` cannot scale (offsets are additive),
  but `lorigin = rorigin = CENTER` plus a per-frame computed offset derived
  from the current reticle x *can* express the rescale, because we already
  know the reticle position (`mouse-aim.md` reads it out of RDRAM every
  frame). Phase 2 should treat the reticle as its own case, decided
  separately from the corner widgets.
* **Reaching the edges.** That is a *game-logic* clamp (±128/±84 in the
  integrator), not a draw-side one — nothing in the display list limits the
  texrect. Widening it is a poke at the clamp, with the caveat that the
  reticle's screen position and the game's hit-test are the same number, so
  moving it past ±128 aims at world space the vanilla frustum never covered.
  Out of scope for phase 1; noted because the draw side imposes **no**
  additional obstacle.

---

## 9. Open questions for phase 2

* **O1 — the "info marquee".** Never observed. All 346 gameplay frames across three
  mission entries contained only the reticle, the two bottom clusters and the
  occasional full-screen flash. Either it belongs to an unvisited mission
  state (objective banner / WARNING / boss / mission-complete), or the brief's
  "top-centre marquee" *is* the radio dialogue box of §3.2. Re-dump with
  `KE_DL_DUMP_AFTER_S` aimed at a mission-complete or boss encounter before
  designing for it.
* **O2 — other in-mission states.** Only stage 1, only normal gameplay plus
  its intro cutscene. Pause screen, lock-on reticle, boss health bar,
  results screen and stage-clear all run under the same 320×200 mode and are
  unexamined. The mission results screen in particular is known to draw over
  the darkened terrain and may reuse `0x800F2B50`.
* **O3 — `0x800F2B50` is a shared buffer.** In-mission the only 8×13 glyph
  rects were the health readout, but the buffer lives in the boot segment
  (same BSS region as the main gfx DL buffers), so it is very likely reused by
  the front end and possibly by score popups. Fingerprint on
  *position + texture*, not on the sub-DL address alone.
* **O4 — the two health-arc buffers.** `0x801BD4F0` and `0x801BDBB0` alternate
  (25/125 in one capture, 156/0 in another). Presumably two animation phases
  or a damage-flash pair. Both draw 48×48 at (20,172); harmless for
  relocation, but any address-list must contain both.
* **O5 — `extAspectRatio` interaction.** `src/main/main.cpp:966` pins
  `hr_option = HUDRatioMode::Original` → RT64 `extAspectRatio = Original`.
  That is what currently keeps the HUD inside the 4:3 box. Whether phase 2
  should change that global instead of / in addition to per-element aligns is
  a design question; `Full`/`Expand` would stretch *all* rects, which is
  wrong for these (they must translate, not stretch — except the dialogue
  panel, which must stretch).
* **O6 — is writing into the game's main DL buffer acceptable?** The
  alternative is copying the whole main buffer into scratch and editing the
  copy (~200 commands, still cheap, and read-only w.r.t. game RAM). Phase 2
  should pick deliberately; the project's precedent (`high_framerate`) is
  "never touch game RAM", and the cost of honouring it here is low.

---

## 10. Address quick-reference

```
0x8010BAF0 / 0x8010FAF0   main frame DL buffers (double buffered; the entry
                          address send_dl receives)
0x8010BAEC                gfx DL write pointer (letterbox-full-height.md §9)

in-mission HUD sub-DLs (rebuilt every frame at these fixed addresses):
0x801C8470  aiming reticle          texture 0x8003E480   32x32
0x801BCE30  health dial backing     texture 0x8003EC80   64x48 @ (20,172)
0x801BD4F0  health arc              texture 0x8003F600   48x48 @ (20,172)
0x801BDBB0  health arc (alt)        texture 0x80040380   48x48 @ (20,172)
0x801BD070  health jet glyph        texture 0x8003F280   32x32 @ (28,180)
0x801BD2B0  health number panel     texture 0x8003F480   32x24 @ (54,179)
0x800F2B50  health % digits         texture 0x8016B3C8    8x13 @ (59|67|75,183)
0x801C25F0  S-BOMB gauge, 5 segs    textures 0x80045100..0x80045500  16x32 @ y=188
0x801C31F0  S-BOMB blinker          texture 0x80045880   16x8  @ (215,207)
0x801B6CB0  full-screen flash       texture 0x801A0C90   319x239 @ (0,0)  [exclude]

in-mission cutscene overlay sub-DLs:
0x801C88F0  dialogue panel plane    textures 0x80033C00+0x40n  133 x 16x8, y 20..76
0x80109550  dialogue glyphs         textures 0x800C0400..      32 x 16x16, y 36/52
0x801D0AB0  portrait frame          textures 0x80039180..      9 x 32x32 @ (16,78)
0x801D1110/0x801D1C50/...  portrait image                      4 x 32x32 @ (32,94)

2D-phase bracket (main buffer, inline):
  enter   SETOTHERMODE_L  E200001C 0F0A7008
  leave   SETOTHERMODE_L  E200001C 0F0A4000
```

---

# Phase 2: implementation

Shipped as the `hud_relocation` enhancement flag, in the `enhanced` profile's
curated set (owner hands-on verification pending, like its siblings at this
stage). Everything below was measured on this tree, headless, 1280x720
Xvfb + lavapipe, stage 1 driven with the `timing-and-mission-debug.md` §3.1
held-key recipe. Screenshots and dumps live in the job scratch dir, not the
repo.

## 1. What it does

| element | anchor | vertical (only with `full_height`) |
|---|---|---|
| health cluster (backing, jet glyph, number panel, % digits, fill arc) | LEFT, keeping its 20 px margin | +20 px |
| S-BOMB gauge + charge fill | RIGHT, keeping its 25 px margin | +20 px |
| ~~radio / dialogue box (panel, glyphs, portrait frame, portrait)~~ | ~~CENTER~~ | ~~−20 px~~ **reverted, see phase 3 §4** |
| aiming reticle | CENTER, **no offsets ever** | none |
| full-screen flash | LEFT + RIGHT (stretched edge to edge) | none |

CENTER is deliberately a no-op placement: the 4:3 column is already centred
in the window, so a CENTER-anchored element lands exactly where it lands
today. It is used rather than "leave untagged" because it states the intent,
and because it makes the reticle's registration explicit — `widescreen` widens
the frustum *around* the original 4:3 content, so the reticle has to keep
tracking that content's scale or it would point somewhere the game's hit test
does not.

Without `full_height` the letterbox is still there and both bottom clusters
are already flush against its floor, so the vertical correction is zero. It is
therefore keyed off `full_height`, not off `hud_relocation` itself.

## 2. Mechanism

`src/main/rt64_render_context.cpp`, all of it inside `send_dl`:

1. **Stubs in scratch RDRAM.** Built once, at physical `0x7FF040` upward
   (the display-list prologue owns `0x7FF000..0x7FF03F`), one 12-word stub per
   fingerprinted element:

   ```
   gEXSetRectAlign(anchor, offsets)      64000006 <origins> <ulxOff|ulyOff> <lrxOff|lryOff>
   G_DL push -> the real element sub-DL  DE000000 <sub-DL address>
   gEXSetRectAlign(NONE, NONE, 0,0,0,0)  64000006 00800800 00000000 00000000
   G_ENDDL                               DF000000 00000000
   ```

   The reset is in **every** stub, not once at the end of the group: RT64's
   rect alignment is global state, and nothing in the game's display list
   restores it (§7 landmine 1 — `RDP::clearExtended()` is reached from
   `State::fullSync()`, i.e. at the frame's `G_RDPFULLSYNC`, long after the
   whole HUD is drawn). Without it, each element's anchor would displace every
   rect after it.

2. **Extended GBI live across the game's own display list.** The prologue
   `maybe_inject_rate_prologue` grew into `maybe_inject_prologue` and now
   emits one of three sequences:

   ```
   high_framerate only   ENABLE -> SETREFRESHRATE -> DISABLE -> BRANCH   (unchanged)
   hud_relocation only   ENABLE ->                SCISSORALIGN -> BRANCH
   both                  ENABLE -> SETREFRESHRATE -> SCISSORALIGN -> BRANCH
   ```

   The `DISABLE` has to go when the stubs are in play, since they contain
   `0x64` commands mid-frame. That is safe and was checked rather than
   assumed: opcode `0x64` occurs **nowhere** in the 450 frames of the four
   phase-1 captures plus a 400-frame front-end capture — the only opcodes the
   dumper could not name were `0x00` (`G_NOOP`, once per frame) and `0xEE`
   (`G_SETPRIMDEPTH`). RT64 unregisters the opcode itself at the frame's
   `G_RDPFULLSYNC`, which every frame of this game emits, so `DISABLE` is
   redundant rather than merely dropped.

3. **Per-frame redirect pass.** Between the `KE_DL_DUMP` hook and
   `processDisplayLists`, the frame's display list is walked and every `G_DL`
   push whose resolved target is a fingerprint-table entry has its `w1`
   rewritten in place to that element's stub address. The dumper's walk
   skeleton was factored out into a shared `dl_walk()` iterator (return stack,
   texrect continuation words, `G_MW_SEGMENT` table, bounds/depth/command
   caps) with the per-command action as a callback; `dl_dump_walk` now uses
   it too, and its output is byte-identical over a 40-frame title capture
   re-run against the phase-1 dump.

   Writing into the game's main display-list buffer resolves phase-1 open
   question **O6** in favour of the in-place rewrite. It is safe by
   construction, not by luck: the game rebuilds the whole frame list every
   frame at a per-frame-varying offset in one of two arenas (§4: 52 distinct
   offsets over 150 frames), so a rewritten word is dead as soon as the frame
   is submitted and is never read back by game code. The element sub-display-
   lists themselves are never written.

4. One stderr line on first activation
   (`[hud] relocation active: N element redirects this frame`), nothing
   per-frame after.

### 2.1 Encoding derivation

`gEXSetRectAlign` (`deps/rt64/include/rt64_extended_gbi.h:269`) is a
`G_EX_COMMAND2`, i.e. two Gfx commands / four native u32s:

```
w0 = PARAM(RT64_EXTENDED_OPCODE=0x64, 8, 24) | PARAM(G_EX_SETRECTALIGN_V1=6, 24, 0) = 0x64000006
w1 = PARAM(lorigin, 12, 0) | PARAM(rorigin, 12, 12)
w2 = PARAM(ulxOffset, 16, 16) | PARAM(ulyOffset, 16, 0)
w3 = PARAM(lrxOffset, 16, 16) | PARAM(lryOffset, 16, 0)
```

**Units: 10.2, i.e. one N64 pixel is 4.** `setRectAlignV1`
(`rt64_gbi_extended.cpp:77`) reads the four offsets as `int16_t` and hands
them to `RDP::setRectAlign`; `RDP::drawRect` then adds them to the texrect's
*raw* coordinates, which are 10.2 (`rt64_rdp.cpp:1173`). Note that
`gEXSetRectAlign` is the one alignment macro that does **not** pre-multiply
its offsets by 4 — its `gEXSetScissor` / `gEXSetScissorAlign` neighbours do —
so the macro's arguments are in the same units as the words we build.

Origins are `LEFT 0x0`, `CENTER 0x200`, `RIGHT 0x400`, `NONE 0x800`.
F3DEX2 `G_DL` is `0xDE` with `w0` bit 16 clear for a push, `G_ENDDL` is `0xDF`
(`rt64_gbi_f3dex2.cpp` opcode map + `GBI_F3D::runDl`/`endDl`).

### 2.2 Why the offsets are what they are

`RDP::drawRect` adds the offsets and then applies
`movedFromOrigin(x, ori) = x + ori*width*4/G_EX_ORIGIN_RIGHT`; the framebuffer
renderer later undoes exactly that shift about the window's corresponding edge
(`convertViewportRect`'s `computeOrigin`,
`rt64_framebuffer_renderer.cpp:88`). For a 320-wide colour image, writing `S`
for the 4:3 pixel scale (`resolutionScale.y`, 3 at 720p):

```
LEFT    window_x = (x + off) * S
CENTER  window_x = window_centre + (x + off) * S
RIGHT   window_x = window_width  + (x + off) * S
```

so the offset is only ever "what the element's coordinate must become once it
is measured from the chosen edge":

| anchor | x offset |
|---|---|
| LEFT | 0 |
| CENTER | −160 px (−640) |
| RIGHT | −320 px (−1280) |
| flash | ulx −2 px, lrx −317 px (its rect is 319 wide, plus 2 px of deliberate overdraw — see §4) |

A pleasant consequence: with those offsets the whole transform is the **exact
identity** when RT64's `extAspectRatio` is `Original`, because
`extAspectPercentage` is then 0 and `computeOrigin()` collapses every origin
onto the framebuffer centre. The stubs degrade to a no-op rather than to a
corruption. That is also the answer to §3 below.

## 3. The `hr_option` question, answered

**Reality picked the second arm: `hr_option` must be `Full`.**

`hr_option` drives RT64's `extAspectRatio`, which feeds
`workloadConfig.extAspectPercentage` — `Original` → 0, `Expand` → 1
(`rt64_workload_queue.cpp:156-183`). That percentage is consulted *only*
inside `computeOrigin()`, and only for `origin < G_EX_ORIGIN_NONE`; an
untagged rect returns `fbWidth/2` regardless. So:

* `Original` (percentage 0): every origin resolves to the framebuffer centre,
  the compensating offsets cancel it exactly, and LEFT/RIGHT-anchored rects
  stay precisely where they were — **inside the 4:3 column**.
* `Full` (percentage 1): origins resolve to the window's left / centre / right
  edges, and the anchors reach the true window edges.

Critically, `extAspectPercentage` has **no effect at all** on untagged rects,
so switching to `Full` cannot disturb anything except our own stubs. The
change is therefore gated on `hud_relocation && widescreen` in `main.cpp` —
without a widescreen gap there is nothing to escape into.

Measured, stage 1 gameplay, 1280x720, `full_height` on, comparing the same
screenshot slot with and without the flag (`before` = the `enhanced` set minus
`hud_relocation`, via a custom profile):

| feature | before | after | delta | predicted |
|---|---|---|---|---|
| health "100" digits, x | 341..403 | 179..241 | **−162** | −162 (`160 + 3u` → `3u − 2`) |
| health "100" digits, y | 556..577 | 616..637 | **+60** | +60 (20 px × 3) |
| S-BOMB gauge bars, x | 811..1002 | 967..1169 | **+156…+167** | +158 ±2 (rounding, §4) |
| S-BOMB gauge bars, y (bottom) | 647 | 707 | **+60** | +60 |
| reticle bounding box, x | 592..687 | 589..684 | **−3** | −2 ±1 (misalignment only) |
| radio panel interior, y (col 900) | 99..215 | 39..155 | **−60** | −60 (20 px × 3) |

The reticle's −3 px is the whole story for it: CENTER anchoring is an identity
transform, and the residual is RT64's own sub-pixel misalignment correction
(§4). It stays registered with the 3D projection, which is the entire
requirement.

With `full_height` **off** (`hud_relocation` + `widescreen` only), the same
run gives digits `x 179..241, y 555..577` and S-BOMB `y 600..647` — the
horizontal relocation applies, the vertical correction does not, and the
radio panel measures `99..215`, identical to `before`. Exactly the specified
interplay.

## 4. The scissor: the one thing phase 1 did not see coming

Anchoring the rects correctly is not enough — they then get **clipped away**.
A rect's GPU scissor is the game's own scissor rectangle converted through the
*rect's* aspect scale but the *scissor's* own origins
(`rt64_framebuffer_renderer.cpp:1679`). Untagged, that converts to the centred
4:3 column, so anything anchored to a true window edge falls outside it.
Measured on the first working build: the health cluster was cut off at the
column's left edge (x 160) and the S-BOMB gauge at its right edge (x 1120) —
the elements had moved, and then been sliced.

The fix is one `gEXSetScissorAlign(LEFT, RIGHT, +1 px, 0, −320 px, 0,
unbounded)` in the prologue, emitted **only on frames that actually contain
relocated HUD** (so the triangle-based front end, §3.3, never sees it). It is
a re-expression of the same scissor, not a new one: the game emits
`G_SETSCISSOR(0, y0, 320, y1)` at the top of every frame, and
`RDP::setScissor` applies the offsets and then `movedFromOrigin()`, so LEFT
with ~0 and RIGHT with −320 px hand back `ulx = 0`, `lrx = 320 px` unchanged.
Every heuristic that keys off the scissor *rectangle* — RT64's
`coversWholeWidth` / `coversScissorWidth` wide-viewport tests, and therefore
the 3D scene and every full-width fill rect — sees identical numbers. The one
thing that changes is that `convertFixedRect` now resolves it against the
window edges.

**The `+1 px` left bias is required, not cosmetic.** For an origin-tagged
coordinate `convertFixedRect` finishes with `correctMisalignment()`, which
subtracts the render target's sub-pixel `misalignX` — 2 at 1280x720
(`RenderTarget::computeScaledSize`: `|1280−960|/2 = 160`, `160 % 3 = 1`, so
`misalignX = (3−1) % 3 = 2`). An untagged scissor never goes through that
path; a tagged one whose left edge converts to 0 comes out at **−2**, and a
`RenderRect` with a negative left reaches `setScissors()` unclamped for rect
draws. (The 3D survives it only because `viewportScissorIntersection()` clamps
against the viewport first — which is exactly why the observed failure was
"every relocated element vanishes, gameplay HUD *and* the cutscene radio box,
while the 3D renders normally".) One N64 pixel is the provable minimum: the
converted left edge is `floor(1 × resScale.y) = resScale.y`, and `misalignX`
is always in `[0, resScale.y − 1]`, so the result is ≥ 1 at any resolution.

Bisected empirically, one variable at a time: `NONE/NONE` align (a literal
no-op) → HUD present; `LEFT/RIGHT` with zero offsets → HUD gone;
`LEFT/RIGHT` with `−320 px` → HUD gone; `LEFT/RIGHT` with a `+2 px` left bias
→ HUD present and correctly anchored.

Consequences, both accepted and both sub-pixel-ish:

* Clipping starts 1 N64 px in from the left window edge and ends ~4 window px
  short of the right one. Nothing comes near either — the closest is the
  full-screen flash, which is therefore given 2 px of deliberate overdraw on
  each side so it fills the scissor instead of leaving an unlit hairline.
* Origin-tagged rects are snapped down to a multiple of `resScale.y` and
  shifted by `misalignX` (2 px at 720p). That is RT64 doing to our rects what
  it already does to every widescreen-tagged rect, and it accounts for the
  ±2 px in the measurement table above.

## 5. The `0x800F2B50` digits, and the O3 gate

Phase 1 flagged the health % digits' sub-DL address as a **shared boot-segment
buffer** (open question O3) and could not settle it, because all four captures
started at least 6 s into a run. Phase 2 dumped **from boot**, and O3 is
real: in the 640x480 front end the same address draws 8x19 glyphs at
`y = 381` from the same glyph texture family (`0x8016B3C8`) — the copyright /
"LICENSED BY NINTENDO" text — in **88 of the first 97 frames** of a run. A
400-frame capture across the whole menu path found it in a further **334**
frames. Left in the table naively, the enhancement would have dragged the
logo screen's own text 160 px across the window (and 30 px down under
`full_height`). It did, in the first build: the `[hud] relocation active`
line fired in the first second of the run.

Rather than drop the digits — which would have left them stranded in the 4:3
column while the dial they belong to moved — they are marked
`shared_buffer` and redirected **only on frames that also contain an element
that can only be in-mission**. The gate is exact against every capture taken:

| capture | frames | digits + mission element (redirected) | digits alone (front end, left alone) |
|---|---|---|---|
| from-boot, vanilla | 97 | 0 | 88 |
| menu path, vanilla | 400 | 0 | 334 |
| `cap_title` | 40 | 0 | 0 |
| `cap_intro` | 220 | 156 | 0 |
| `cap_mission` | 150 | 150 | 0 |
| `cap_enh` | 40 | 40 | 0 |

346/346 gameplay frames still redirect the digits; 422/422 front-end frames do
not. Confirmed at runtime too: with the gate, the `[hud]` line moves from the
first second of the run to the mission start (~46 s in).

No other fingerprint address appears anywhere outside a mission across those
537 front-end frames.

## 6. Verification

All headless, 1280x720 Xvfb + lavapipe, stage 1.

* **Vanilla bit-identical.** `--profile vanilla`: no `[hud]`, `[hfr]` or
  `[gfx]` line, and by inspection `maybe_redirect_hud` returns on an atomic
  load before touching RDRAM while `maybe_inject_prologue` returns after
  reading one config field — no scratch read, no scratch write, no rewrite,
  the entry address handed to RT64 unchanged.
* **Smoke test PASS** on the default (enhanced) profile: alive, 34215
  distinct colours, 99.3% non-zero audio samples.
* **Screenshot evidence**, before/after on the same game state: §3's table.
* **`high_framerate` interplay.** Custom profile with `high_framerate` and
  `hud_relocation` both on: `[hfr] declaring game logic rate …` lines still
  appear, `[hud] relocation active` still appears, and the measured HUD
  positions are pixel-identical to the enhanced profile's. Both prologue
  variants exercised, no anomalies in a ~3 minute run.
* **Cutscene.** Mission-1 intro with `full_height`: the radio panel's interior
  moves from `y 99..215` to `y 39..155`, i.e. its plane's top edge from
  window `y = 60` to `y = 0` — the true top.
* **Dumper regression.** The shared-iterator refactor was checked by re-running
  a 40-frame vanilla title capture and diffing against the phase-1 dump:
  **40/40 frames identical**.

## 7. What is still open

* Owner hands-on, as for every other enhancement at this stage.
* Only stage 1, only normal gameplay plus its intro cutscene — phase 1's open
  question **O2** is untouched. Pause screen, lock-on reticle, boss health
  bar, results and stage-clear screens all run under the same 320x200 mode and
  have never been dumped. A HUD element that only appears there is simply not
  in the fingerprint table, so it stays in the 4:3 column while its neighbours
  move; that is the failure mode to look for. The mission results screen is
  the most likely to reuse `0x800F2B50`, in which case §5's gate decides its
  fate and may need widening.
* **O1** (the "info marquee") remains never-observed.
* The RT64 letterbox-band colour bug (`letterbox-full-height.md` §4) is
  visible in the `full_height`-off screenshots, unchanged and unrelated.

---

# Phase 3: owner feedback round

Shipped in phase 2, verified hands-on by the owner on 2026-07-31, two
findings came back. One was a real bug in the identification (§1-§3 below),
the other a design call (§4). Everything here was measured on this tree,
headless, 1280x720 Xvfb + lavapipe, stage 1 driven with the §3.1 held-key
recipe; dumps and screenshots live in the job scratch dir, not the repo.

## 1. The report

> The health dial container + percent digits relocated correctly to the
> window's bottom-left -- but the yellow health **fill arc** still floats at
> its old 4:3-column position, detached to the right of the dial. Likewise
> the S-BOMB charge fill (small gold segmented bar) floats left of its
> relocated container.

Both strays are the **dynamic** parts -- the ones whose picture changes with
the value being displayed. Every static element moved correctly. That shape
is the clue: phase 1 identified elements by sub-DL *address*, and phase 2's
fingerprint table is that identification frozen into code.

## 2. What the fills turned out to be

Four fresh `KE_DL_DUMP` captures (1769 mission frames, health driven from
100% down to 7% by just playing, plus a state where the S-BOMB had charge),
analysed by attributing every `G_TEXRECT` to the sub-DL that was executing
when it was issued:

| sub-DL @ | frames | rect | texture | what |
|---|---|---|---|---|
| `0x801BCE30` | 1769 | 64x48 @ (20,172) | `0x8003EC80` | dial backing (static, in table) |
| `0x801BD070` | 1769 | 32x32 @ (28,180) | `0x8003F280` | jet glyph (static, in table) |
| `0x801BD2B0` | 1769 | 32x24 @ (54,179) | `0x8003F480` | number panel (static, in table) |
| `0x801BD4F0` | 259 | 48x48 @ (20,172) | `0x8003F600` | **health fill** |
| `0x801BDBB0` | 36 | 48x48 @ (20,172) | `0x80040380` | health fill |
| `0x801BE270` | 579 | 48x48 @ (20,172) | `0x80041100` | health fill |
| `0x801BE4B0` | 239 | 48x48 @ (20,172) | `0x80041580` | health fill |
| `0x801BE930` | 80 | 48x48 @ (20,172) | `0x80041E80` | health fill |
| `0x801BF230` | 1 | 48x40 @ (20,180) | `0x80042E40` | health fill |
| `0x801BF470` | 81 | 48x32 @ (20,188) | `0x80043200` | health fill |
| `0x801BF6B0` | 14 | 48x32 @ (20,188) | `0x80043500` | health fill |
| `0x801BF8F0` | 59 | 48x24 @ (20,196) | `0x80043800` | health fill |
| `0x801BFB30` | 264 | 48x24 @ (20,196) | `0x80043A40` | health fill |
| `0x801BFFB0` | 17 | 48x24 @ (20,196) | `0x80043EC0` | health fill |
| `0x801C0AF0` | 43 | 32x24 @ (36,196) | `0x80044940` | health fill |
| `0x801C13F0` | 97 | 16x24 @ (52,196) | `0x80044F40` | health fill |
| `0x801C25F0` | 1769 | 5 x 16x32 @ y 188 | `0x80045100`+ | S-BOMB gauge (static, in table) |
| `0x801C31F0` | 80 | 16x8 @ (215,207) | `0x80045880` | **S-BOMB fill** |
| `0x801C3430` | 11 | 16x8 @ (215,207) | `0x800458C0` | S-BOMB fill |
| `0x801C3670` | 565 | 16x8 @ (215,207) | `0x80045900` | S-BOMB fill |

So the hypothesis list in the brief resolves to **"a variable-address push"**,
and emphatically not to per-frame-generated inline commands: across all 1769
mission frames the main display list contains **zero** inline `G_TEXRECT`s --
every rect in the frame, without exception, comes from a sub-DL reached by a
single `G_DL` push, exactly as phase 1 §4 found. The mechanism phase 2 built
is right; the *identification* was wrong.

Two further facts fell out and they are what decides the fix:

* **The addresses come from a 0x240-byte display-list buffer pool, not from a
  per-element buffer.** The whole health family is `0x801BCE30 + n*0x240` for
  integer `n`: backing `n=0`, jet `n=1`, panel `n=2`, and the thirteen fill
  variants at `n = 3, 6, 9, 10, 12, 16, 17, 18, 19, 20, 22, 27, 31`. The
  S-BOMB gauge is `n=39` on the same grid, and the three charge-fill variants
  are `0x801C31F0 + m*0x240` (a grid offset 0xC0 from the health one). The
  static elements happen to sit at fixed slots; the fills do not.
* **The fill's rect shrinks as the value drops.** The arc is a crop that keeps
  its bottom-right corner at (68,220) and loses rows/columns off its top-left
  as health falls -- 48x48, then 48x40, 48x32, 48x24, 32x24, 16x24. Thirteen
  distinct (address, texture) pairs observed for the arc alone, and clearly
  not all of them (health is displayed to the percent, and no capture reached
  the top or bottom of the ramp).

The two entries phase 2 *did* list for the arc (`0x801BD4F0`, `0x801BDBB0`)
were two of those thirteen, which is exactly why the owner saw the arc move
correctly at some health values and stay behind at others. Phase 1's open
question **O4** -- "the two health-arc buffers... presumably two animation
phases" -- is therefore answered and was wrong: they are two frames of a
thirteen-plus-frame value ramp, and only looked like an alternating pair
because both phase-1 captures were taken near full health. The same is true
of phase 1's "S-BOMB blinker": it does not blink, it is the charge fill, it
has at least three variants of its own, and it was absent from whole captures
here because the S-BOMB had no charge in them.

## 3. Mechanism: region matching

An address list cannot be completed (the value ramp is longer than anything
we can enumerate by playing), and an address *range* cannot separate the
fills from their neighbours either -- the enemy bar at the top of the frame
(`0x801C1AB0`, `0x801C1F30`, `0x801C23B0`, `0x801C24D0`) lives in the middle
of the same pool. So the fills are matched by **content signature**, and the
signature that is actually structural here is geometric:

> a sub-DL called from the frame's main display list, **all** of whose
> texrects fall inside a HUD cluster's own footprint, belongs to that cluster.

`hud_regions[]` in `src/main/rt64_render_context.cpp`:

| region | box (N64 px, inclusive) | anchor | vertical |
|---|---|---|---|
| health fill | x 20..90, y 172..220 | LEFT | +20 (full_height only) |
| S-BOMB fill | x 215..300, y 185..220 | RIGHT | +20 (full_height only) |

Implementation, all inside the existing per-frame redirect pass:

* Every top-level `G_DL` push that the fingerprint table does **not** claim is
  followed into (the walker already descended into these; nothing new is
  read), and the bounding box of the texrects issued until control returns is
  accumulated. `depth` mirrors `dl_walk`'s own call depth, which is why the
  `SkipCall` return -- the one case where the walker does not descend -- must
  not touch it.
* A box match is **deferred**, resolved after the walk, behind the same
  in-mission gate phase 2 built for the shared digit buffer (§5): the frame
  must also have matched an element that can only be in a mission. So a
  region match can never fire on a front-end frame, and no scratch RDRAM is
  written on one.
* Each match gets a stub from a small per-frame pool (`HUD_DYN_STUBS = 8`,
  laid out immediately after the fixed per-element stubs; the scratch layout
  comment and the one-time zero check cover it). The stub is identical in
  form to the static ones -- `gEXSetRectAlign(anchor)` / push the real sub-DL
  / `gEXSetRectAlign(reset)` / `G_ENDDL` -- but is rewritten each frame
  because the address it calls moves. That is 12 stores, on a path that
  already writes the prologue every frame.
* The push word it carries is the exact `w1` the game's own push carried,
  not a re-derived address, so whatever the game meant by it is preserved.
  (It never means anything unusual: segment 0 is the only segment this game
  ever sets, and always to 0 -- phase 1 §5.)
* One stderr line per region, the first time it ever matches, naming the pool
  slot: `[hud] health fill matched by region at sub-DL 0x801BD4F0`. Which
  slot a fill landed in is the single most useful thing to have in a future
  bug report about it.

**The two arc addresses and the blinker address are removed from the
fingerprint table.** They are three of the sixteen observed variants (two of
thirteen for the arc, one of three for the charge fill), and leaving
them would mean the same element took a different code path depending on the
player's health -- a split that would have hidden this bug for another round.
One element, one mechanism. The table now holds only genuinely static
elements: reticle, dial backing, jet glyph, number panel, percent digits
(shared buffer), S-BOMB gauge, full-screen flash.

### 3.1 False-positive analysis

The match requires *every* texrect in the sub-DL to be inside a box that is
71x49 (health) or 86x36 (S-BOMB) N64 pixels, on a frame already known to be
in a mission. Against all 1769 mission frames:

* The only sub-DLs that qualify are the two fills. Nothing else, in any frame.
* Every effect sprite seen anywhere near the bottom of the frame
  (`0x801B8330`, `0x801B8450`, `0x801B8570`, ...) draws 64x64 rects, which
  cannot fit inside a 49-tall or 36-tall box at any position -- the size
  constraint does the work, not luck about where they happened to be.
* The full-screen flash (319x239) and the enemy bar (y 0..37) are nowhere
  near either box, and the flash is claimed by the table first anyway.
* The cutscene overlay -- now unclaimed, see §4 -- also fails both boxes: the
  panel is y 20..76, the portrait frame y 78..174.
* The percent digits (x 59..83, y 183..196) *are* inside the health box, but
  are claimed by the table by address first. In the front end the same buffer
  draws at y 381, outside every box and on a frame with no in-mission
  element, so both gates reject it independently.

The one element that could geometrically qualify is the **reticle**: 32x32,
and aimed at the bottom-left its rect does fit the health box. It is claimed
by address first, and its address was `0x801C8470` in all 1769 frames of
every capture ever taken of this game. If that ever changed, the reticle
itself would visibly stop being relocated -- a loud failure, noticed before
this rule could act on it.

The residual risk is unchanged in kind from phase 2 and stated the same way:
an unexamined in-mission state (pause, boss, results -- phase 1 **O2**) could
contain a small rect inside one of the boxes. The failure mode would be a
cosmetic misplacement of that one element, and the fix path is the same as
ever: `KE_DL_DUMP`, then either a table entry or a tighter box.

## 4. The radio box: reverted

**Owner decision, 2026-07-31: the in-mission cutscene radio box goes back to
its original, untouched position, in every mode.** Reasoning, recorded
because it overrides phase 2's §1 table: the cutscene's own graphical effects
are authored against the 4:3 column and read as misaligned next to a moved
box, and the box's original position is not unnatural to begin with. There is
nothing to gain and a visible inconsistency to lose.

The revert is the removal of five fingerprint-table entries -- radio panel
`0x801C88F0`, radio glyphs `0x80109550`, portrait frame `0x801D0AB0`,
portraits `0x801D1110` / `0x801D1C50` -- and with them the whole `-20 px`
vertical case. An unmatched push is executed exactly as the game wrote it, so
no other code changes. `HudAnchor::Center` survives, used only by the
reticle, and the `vertical_px` field is now `+20` or `0` everywhere.

The reticle CENTER pin and the full-screen flash's edge-to-edge stretch are
unchanged.

## 5. Verification

All headless, 1280x720 Xvfb + lavapipe, stage 1 driven end to end.

* **Both fills ride with their containers.** `--profile enhanced`, mission
  screenshot at 26% health. Health-fill-coloured pixels in the bottom band:
  **1880 in x 17..162** (inside the relocated dial's own bbox, x 58..250) and
  **0 anywhere in x 210..400**, the 4:3-column position the arc used to
  occupy. S-BOMB charge fill at **x 976..984, y 684..698**, against a
  predicted right-anchored box of x 963..1011, y 681..705; in the vanilla
  screenshot of the same element it measures **x 820..822, y 624..638**,
  against a predicted 4:3-column box of x 805..853, y 621..645. So the fill
  moved **+156 px horizontally and +60 px vertically**, which is the same
  delta phase 2 measured for the gauge container it belongs to (+156..167,
  +60). Before this change the same measurement put it in the 4:3 column
  while its container sat at the right edge.
* **`[hud]` lines fire at mission start, not at boot.** First `[hud]` line
  ~89 s into the run (gameplay begins ~87 s); 0 in the whole front end. The
  in-mission gate on the region matches holds.
* **The cutscene is byte-identical with the flag on and off.** Mission-1
  intro frame, `--profile enhanced` vs a `custom` profile identical except
  `hud_relocation = false`: **max per-channel pixel difference 0 over all
  921600 pixels**. The radio box revert is exact, not approximate.
* **Vanilla clean.** `--profile vanilla`, driven to gameplay: **0**
  `[hud]` / `[hfr]` / `[gfx]` lines.
* **Smoke test PASS** (`scripts/smoke_test.sh`): alive, 5932 distinct
  colours, 99.3% non-zero audio samples.
* **The phase-2 relocations still hold**, on the same screenshot: dial
  backing, jet glyph, number panel and percent digits at the true
  bottom-left; S-BOMB gauge at the true bottom-right; reticle centred over
  the 3D scene.

## 6. What this changes in the phase 1/2 record

* **O4 is answered, and phase 1's guess was wrong.** The "two health-arc
  buffers ... presumably two animation phases or a damage-flash pair" are two
  frames of a value ramp with at least thirteen members, drawn from a shared
  0x240-byte display-list buffer pool. Both phase-1 captures were near full health,
  which is why only two appeared.
* **The "S-BOMB blinker" is not a blinker.** It is the charge fill; the
  110/150 frame count phase 1 recorded is charge state, not blinking, and it
  has at least three variants of its own.
* **"Sub-DL addresses are stable" (phase 1 §4) holds only for static
  elements.** It was measured over 450 frames of near-full-health gameplay
  and generalised one step too far. The corrected statement: static elements
  occupy fixed slots in the pool; anything whose picture depends on a game
  value does not.
* **Phase 2's §1 table row for the radio box is superseded by §4 above.**
