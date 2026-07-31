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
