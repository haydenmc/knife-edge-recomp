# Mouse aim — the reticle RE, and the controller built on it (2026-07-29)

Two things live here:

1. **§1–§6, the measurements.** What the game's aiming reticle actually is in
   RDRAM, how it moves, and what it does out of a mission. Everything is
   measured against a running game, not inferred; the numbers are load-bearing
   for §7 and future sessions must not re-derive them.
2. **§7–§9, the controller.** How positional mouse aim uses those numbers, and
   the two places the implementation had to depart from what a reading of the
   measurements alone would suggest.

The prior art this replaces: the first mouse-aim commit (`a0d7907`) mapped
mouse *speed* to stick deflection open-loop, which needs no knowledge of any of
the below. That mapping survives as `mouse_mode = "velocity"`.

---

## 1. Memory layout, and how the byte order was proven

The reticle is **two big-endian `int32`s** in the boot segment's BSS:

```
0x8011D4BC  int32  reticle X   measured range [-128, +128]
0x8011D4CC  int32  reticle Y   measured range [ -84,  +84]
```

An earlier live-memory session read these as an `int8` "sign" at `+0` plus an
`int16` at `+2`. That is the same storage seen through a smaller window: the
"sign" byte is the sign extension of a single 32-bit value. Proof is a
continuous sweep straddling zero, with the raw N64-order bytes going
`00000008` → `fffffff4` → `ffffffe0` → … → `ffffff80`. All 32 bits move
together; there is no separate sign field.

`config/knife_edge.us.syms.toml` puts both inside **`boot_bss`** (vram
`0x800EEF50`, size `0x07BCA0`), so they are never overlaid — no other overlay
reuses the addresses. That matters for §6.

### 1.1 RDRAM byte order (get this wrong and every number above is garbage)

librecomp stores game RAM with each aligned 4-byte word holding the N64
big-endian word in **host little-endian order** (a per-word byteswap). Proven
two independent ways against a live process:

* **ASCII.** At `0x80123B40` the raw host bytes read `"ECILDESN YB TNIN"`;
  reversing each 4-byte group gives `"LICENSED BY NINT"`.
* **Statistics.** Over `0x80100000..0x80140000`, words that look like RDRAM
  pointers (`0x80000000`–`0x80800000`) number **776** under a little-endian
  reading and **6** under a big-endian one.

So, reading `/proc/<pid>/mem` at `base + (vaddr & 0x0FFFFFFF)`:

| access | host offset | decode |
|---|---|---|
| 32-bit aligned | `vaddr` | direct little-endian `int32`/`uint32` |
| 16-bit | `vaddr ^ 2` | direct little-endian `uint16` |
| 8-bit | `vaddr ^ 3` | direct byte |

which is exactly what `recomp.h`'s `MEM_W` / `MEM_H` / `MEM_B` do. **In shim
code, use those macros rather than hand-built offsets** — and sign-extend the
address first (CLAUDE.md's first gotcha).

### 1.2 The units are N64 pixels

Green-pixel centroids of the reticle sprite, from screenshots at 1280x720 with
the vanilla letterbox:

| reticle value | centroid |
|---|---|
| `X=0, Y=0` | (640, 360) — exactly screen center |
| `X=+128, Y=-84` | (1028, 111) |

That is 3.03 host px per unit horizontally and 2.96 vertically, and the render
scale is 960 px / 320 N64 px = 3.0. So **1 reticle unit = 1 N64 pixel**, origin
at the viewport center, **+X right and +Y DOWN**. The rails are ±128 of the
±160 half-width and ±84 of the ±100 half-height of the 320x200 in-mission
viewport — the reticle deliberately cannot reach the screen edge.

The practical consequence for any host code: one unit is `window_h / 240` host
pixels, so pixels convert to units by `240 / window_h`.

---

## 2. Axes and orientation

| axis | address | key (stick) | value sign | screen direction |
|---|---|---|---|---|
| X | `0x8011D4BC` | `D` = stick +x | +x → value increases | right |
| Y | `0x8011D4CC` | `W` = stick +y | +y → value increases | **down** |

**The game aims flight-inverted.** A stick pushed up drives the reticle *down*.
Verified visually as well as numerically: `A`+`W` puts the reticle bottom-left,
`D`+`S` puts it top-right.

This is the single easiest thing to get backwards, and the first mouse-aim
commit did: it negated SDL's `yrel` on the assumption that stick +y meant "up",
so mouse-up aimed down.

---

## 3. Motion: a fixed step per game frame, no acceleration

At full deflection the reticle moves **exactly 20 units per game frame**, in
both directions on both axes. Twelve rail-to-rail sweeps (3 per direction per
axis): *every* inter-frame delta was ±20, with only the final step truncated by
the clamp (X: `[20×12, 16]` for 256 units; Y: `[20×8, 8]` for 168). Zero
spread — no ramp-in, no ramp-out, no acceleration.

Update cadence is **one update per game frame**, never per host frame. Two
proofs: the counter at `0x8011D1CC` advances by exactly +1 per reticle change,
and 126 measured inter-update intervals give mean **37.47 ms** (median 33.60,
histogram `{33ms: 11, 34ms: 56, 42ms: 59}`) — the 36.5 ms RCP budget quantized
to the 60 Hz retrace grid, i.e. 26.7 Hz. At the console-faithful budget this
would be ~15 Hz. In units/second the speed is therefore frame-rate coupled:
20 × 26.7 = **534 units/s** at the current pace.

### 3.1 The step is proportional to stick deflection

Full-stick keyboard input hides this entirely. Measured by injecting stick
bytes directly (`0x8011BE26` = stick_x, `0x8011BE27` = stick_y in the game's
per-frame pad copy) at 34 points per axis — both axes identical, all points fit:

```
units_per_frame = clamp( floor( (|stick| - 5) * 20 / 58 ), 0, 20 ) * sign(stick)
```

* **deadzone**: `|stick| <= 7` gives 0 (7 → 0, 8 → 1)
* **saturation**: `|stick| >= 63` gives the maximum 20. **Half the s8 range is
  dead weight** — anything a host emits above 63 is wasted resolution.
* every integer rate 0…20 is commandable. The smallest stick magnitude that
  yields rate `k` is `5 + ceil(29k/10)`:

| k | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| stick | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 34 | 37 | 40 | 43 | 46 | 49 | 52 | 55 | 58 | 61 | 63 |

Spot values, X axis (Y identical where tested): 8→1, 10→1, 11→2, 13→2, 14→3,
17→4, 20→5, 24→6, 27→7, 29→8, 32→9, 34→10, 37→11, 41→12, 44→13, 46→14, 49→15,
51→15, 54→16, 57→17, 58→18, 60→18, 61→19, 62→19, 63→20, 127→20.

*Method note.* The injector races the game's own once-per-frame pad copy. A
lost race substitutes 0, which can only **shrink** a step, never grow one, so
the maximum observed step for a given deflection is the true one. In practice
the injector won 24–64 consecutive frames per test point with a single step
value, so contamination was visible where it happened and negligible overall.

---

## 4. There is no auto-centering

The values are pure integrators. Driven to a non-rail position (X = −108,
Y = −24) with every key released, sampling at 120 Hz for **18.67 s** produced
**zero** changes. Rail dwells held for up to 34.5 s likewise.

This is what makes a positional controller cheap: there is no re-centering
force to fight, so the host only ever has to close the gap it opened.

## 5. The rails clamp hard

At every rail, between 451 and 4110 consecutive samples with no intermediate
value ever observed — no oscillation, no jitter. Overshoot is silently
absorbed, so it is safe to command past a rail. Ranges are stage-independent
(±128 / ±84 measured in both stage 1 and stage 2).

## 6. Out of mission the values are stale, not garbage

| state | X, Y | changes on its own? | responds to WASD? |
|---|---|---|---|
| fresh boot → title/attract (no mission yet) | 0, 0 | no (1196 samples / 20 s) | no (10 s of held D/A/W/S) |
| after a mission (death → attract; results; stage overview) | **retains its last in-mission value** | no | no |
| Rumble Pak notice / stage select | retains last in-mission value | no | no |
| next mission start | **reset to 0, 0** | — | — |

Because the addresses are boot BSS (§1) nothing else ever writes them; they
simply keep whatever the last mission left. **So "the value is zero" is not a
usable test for "in a mission"** — a post-mission menu legitimately reads
±128/±84 — and neither is "the value changed".

### 6.1 `0x8011D1CC` is NOT a mission-only clock

It advances +1 per frame during a mission (§3), and this is genuinely the
mission clock there (`timing-and-mission-debug.md` §5.1). But the front-end
overlays reuse the same word:

* **attract/demo scenes**: it ticks once per frame, exactly like in a mission —
  700 changes in 30 s, mean interval 37 ms.
* **title screen**: it changes rarely and non-monotonically (41 distinct values
  in 10 s, running *downwards*), i.e. it is some other per-overlay variable
  there.
* **stage overview**: frozen at whatever the mission left (9968 for 12 s).

This matters because it is the signal §7's controller gates on, and it is
**not sufficient** to establish "in a mission" — see §9.

### 6.2 A word that *does* discriminate

`0x800EBC00`, the per-retrace callback pointer (`timing-and-mission-debug.md`
§1.2), names whichever screen is running, because every screen registers its
own callback through `func_800D1640`. Measured values:

| screen | `0x800EBC00` | samples |
|---|---|---|
| in a mission | **`0x8019CF84`** | 300/300, and 1011/1011 in a second run |
| attract / demo | `0x801DC3E4` | 400/400, and 5938 more across §9's stress test |
| stage overview (STAGE 2 / PATH A) | `0x8017B700` | 189/189 |

`0x8019CF84` lives in `seg_1501A0`, the in-game code overlay shared by every
stage, so the in-mission value is stage-independent. This is the gate the
controller uses (§7).

One boundary worth knowing: **the results screen still reads `0x8019CF84`**.
The pointer was sampled continuously across a forced mission end and held the
mission value through mission clock 8807…9967 — which spans both the results
screen (raised at tick 9450) and its script timeout (9950) — flipping to
`0x8017B700` only on arrival at the stage overview. That is correct rather
than a leak: the game is genuinely still inside the mission loop there, and
the results screen exits on A/B/START only, never on the stick
(`timing-and-mission-debug.md` §4.1). The screen where stick input *would*
do something unwanted — stage/path selection — is the one the gate closes.

---

## 7. The controller

`src/main/main.cpp`'s `get_input()`, active when `input.mouse_mode =
"positional"` (the default).

**Publisher.** `src/main/rcp_timing.cpp`'s `ke_gfx_task_end()` — the project's
only per-game-frame hook that is handed `rdram` — reads the two reticle words,
`0x8011D1CC`, and the retrace callback pointer `0x800EBC00` through `MEM_W`
each frame and publishes them to relaxed atomics, exposed as
`kerecomp::reticle_state()` in `support.h`. Read-only with respect to game
memory. It runs ahead of the frame-budget check so the reticle is still
published when pacing is disabled (`KE_RCP_FRAME_MS=0`). The callback pointer
is published **raw**, not pre-reduced to a bool, so a diagnostic can report
what it actually was (§9.1).

**Target.** Two floats, private to the input thread. Mouse pixels convert to
reticle units by `240 / window_h` (§1.2) times `mouse_sensitivity`, and the
result is clamped to the measured rails (§5) so the target cannot wind up past
a reticle that has stopped following. `window_h` is republished by
`update_gfx()` each pass so a resize is tracked rather than assumed.

**Lead cap.** After the rails clamp, the target is further clamped to within
±20 units (one game frame's maximum travel, §3) of the current reticle
position. Without this, a fast flick left the target hundreds of units ahead
and the reticle visibly tail-chased it at its game-capped 20 units/frame for
up to half a second after the hand had stopped — the owner's first hands-on
report. With the cap, the reticle tracks at full speed while the mouse moves
and stops within one frame (~37 ms) of the mouse stopping; flick travel the
reticle cannot match is dropped rather than queued (standard speed-capped-
pointer behavior — the hand covers more distance than the reticle on a slam,
and the player naturally re-aims).

**Deadbeat law**, per axis, once the gates pass:

```
err  = target - published_reticle
step = min(floor(|err|), 20)          units to ask for this frame
s    = threshold[step] + 1            stick magnitude, from §3.1's table
```

`floor`, not `round`: commanding fewer units than remain can never overshoot,
so the reticle walks onto the target monotonically and stops — no dither, no
oscillation, no integral term, no tuning. The cost is settling up to 1 unit
short, which is ~3 host pixels at 720p. Aiming one *past* each threshold lands
mid-band (the narrowest band is 2 wide) so a one-unit error anywhere in the
§3.1 fit would still select the right rate. Saturation asks for 80 rather than
63 because there is no rate above 20 to overshoot into.

**Float encoding.** `get_input()` returns `x`/`y` in [-1, 1] and
`deps/N64ModernRuntime/ultramodern/src/input.cpp:154-155` converts with

```c
data[controller].stick_x = (int8_t)(127 * x);
data[controller].stick_y = (int8_t)(127 * y);
```

— a C truncation toward zero. So any `x` in `[s/127, (s+1)/127)` yields byte
`s`; the implementation emits the midpoint `(|s| + 0.5) / 127`, signed, which
leaves maximum room for float rounding on both sides.

The mouse contribution is then summed with keyboard and pad and clamped, exactly
as before — the merge is unchanged.

**Gates.** All three must hold, or the mouse contributes zero *and* the target
resyncs to the current reticle so re-engaging never starts with a stale error.
They are layered coarsest first:

1. **a mission is running** — `0x800EBC00 == 0x8019CF84` (§6.2). The
   discriminator, and it **fails closed**: any screen or game mode this code
   has not anticipated registers some other callback, so aim goes quiet rather
   than emitting stick input into a menu. Inert aim is a visible annoyance;
   phantom menu input is a corrupting one.
2. **the world stepped recently** — `0x8011D1CC` changed within 250 ms. Kills
   aim while the world is frozen *inside* a mission (pause, load, cutscene),
   where the reticle cannot move and chasing it would wind the target up.
3. **the mouse moved within 1.0 s** — bounds whatever residual exposure the
   first two leave, and stops the loop from holding a deflection indefinitely.

Gate 1 is load-bearing, not belt-and-braces: §9 is the measurement showing
gates 2+3 alone are not sufficient.

---

## 8. Deviation: gate 1 is a time window, not "changed since the last call"

The design as specified tested "the mission clock advanced since the previous
`get_input()` call". That does not work, and the failure is total rather than
subtle: **`get_input()` is called ~3.2 times per game frame** (measured over
3673 calls: median 2, mean 3.21, max 754 while a load or cutscene holds the
world still). So a per-call change test fails on roughly two calls in three
purely from sampling faster than the thing being sampled — and because each
failure resyncs the target, the accumulated mouse motion was thrown away before
it could ever be acted on. Measured output in that form: stick byte `0` on
1980/1980 samples with the mouse moving.

Testing "changed within 250 ms" preserves the intent exactly (don't chase a
world that isn't advancing; resync when disengaged) and fixes the rate mismatch.
250 ms is ~7 game frames at the current pace and ~4 at 15 fps, so a live world
always passes, while a genuinely stopped one trips it well inside gate 2's
window.

## 9. Why gate 1 exists: the attract-screen leak

The clock window (gate 2) plus motion recency (gate 3) were originally expected
to keep the controller quiet outside missions. §6.1 is why they cannot: on
**attract/demo screens** `0x8011D1CC` ticks once per frame exactly as in a
mission, so gate 2 passes, while the reticle words sit frozen. The error
therefore never closes and the controller never stops commanding.

Measured with only gates 2+3 in place, 30 s of continuous mouse motion with the
pointer captured at the attract screen: the game's stick bytes were non-zero for
**17.4 %** of samples, at the saturation value ±80. That is worse than the
velocity mapping's exposure in two ways — velocity's injection is proportional
to mouse speed and ends the instant the mouse stops, whereas this one is
saturated and persists up to a second afterwards.

On the title screen proper the same test gave exactly 0 on 1979/1979 samples,
but only because that overlay happens to touch the counter rarely. That is luck
about which screen is up, not a property to rely on.

Adding gate 1 (`0x800EBC00 == 0x8019CF84`) closes it. Re-measured with all
three gates, same 30 s attract stress test: **0 non-zero samples out of 5938,
0.00 %** — while the front-end counter changed 724 times in that same window,
i.e. gate 2 was passing throughout and gate 1 is demonstrably what closed it.
The stage-overview screen, the front-end screen where the stick actually
navigates, likewise measures 0/1980 with the stale reticle words (100, 0)
sitting in memory.

### 9.1 The limitation this trades for

Gate 1 asserts one specific callback address. **If any in-mission variant ever
runs a different per-retrace callback, mouse aim will simply be inert there.**
That is the deliberate fail-closed direction, but it is a real failure mode to
watch for in hands-on play: the symptom is "positional mouse aim does nothing
on this screen or in this mode, while keyboard and pad still work".

The diagnostic is one line, and is the reason the publisher stores the pointer
raw rather than reduced to a bool: log
`kerecomp::reticle_state().retrace_callback` and compare it against
`0x8019CF84`. Everything exercised so far — stage 1, stage 2, mission intro
cutscenes, and the results screen (§6.2) — reports the expected value. The
untested surface is the later stages, the alternate game modes, and two-player.

---

## 10. Verification performed

All headless, on `:94` under Xvfb, against a live stage-1 mission with player
health pinned from outside the process (`/proc/<pid>/mem`, no code change).

* **Horizontal.** 300 px of mouse travel → target 300 × 240/720 = 100.0 units.
  Reticle went 0 → **100** in 6 game frames and stopped: steps
  `[20, 20, 10, 20, 20, 10]`, commanded sticks 80 and 35, then stick 0. No
  overshoot, no oscillation.
* **Vertical.** 150 px down → 50.0 units. Reticle 0 → **+50**, i.e. down the
  screen, confirming the default non-inverted orientation. Commanded sticks 21
  and 35 → steps 5 and 10. X unchanged at 100 throughout (no cross-axis leak).
* **Diagonal.** −444 px, −240 px → −148, −80 units (the odd number is the test
  script's integer division, not the controller). Reticle tracked both axes
  simultaneously to exactly those deltas, X saturating at stick −80 while Y ran
  proportional at −24/−47/−44/−27/−30.
* **Every commanded stick value produced exactly the step §3.1 predicts** —
  80→20, 35→10, 30→8, 27→7, 24→6, 21→5, 44→13, 47→14. The inverse curve is
  validated end to end, not just the fit.
* **Idle.** 6.55 s / 1297 samples after the mouse stopped: stick 0 throughout,
  reticle static. No creep.
* **Velocity mode.** Sustained mouse-up in a mission drives the reticle to the
  **top** rail (Y 0 → −84) with `stick_y` strictly negative — the §2 inversion
  bug is fixed, and the mode still works.
* **Gate 1 regression pass** (after the third gate was added): attract stress
  test 0/5938 non-zero (§9); stage overview 0/1980; in-mission horizontal
  tracking unchanged — 0 → 100 in 6 frames, steps `[10, 20, 10, 20, 20, 20]`,
  sticks 35/80 then 0, no overshoot.

---

## 11. Gotchas for anyone re-running these measurements

* **SDL needs mouse focus before it will deliver a click.** Under Xvfb with no
  window manager the pointer is already inside the window when SDL creates it,
  so no `EnterNotify` is ever sent and `SDL_MOUSEBUTTONDOWN` is dropped —
  capture silently never happens. Make the X screen larger than the window
  (e.g. `Xvfb :94 -screen 0 1600x900x24` for a 1280x720 window), move the
  pointer outside and back, *then* click.
* **SDL's relative mode does not confine the pointer under Xvfb.** Motion is
  still reported correctly, but the pointer will walk to a screen edge and stop
  generating events. Re-center it (`xdotool mousemove 800 450`) before each
  motion burst.
* **The app folder follows the working directory**, so `config.toml` is read
  from `./ke_recomp_data/` relative to wherever the binary is *run*, not
  where it lives.
* **stdout is block-buffered** when redirected, so `Mouse captured` and friends
  will not appear in a log tail until the buffer flushes. Run under
  `stdbuf -o0 -e0` when those lines are the signal being waited on.
