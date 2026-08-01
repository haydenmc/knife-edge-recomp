# Multiplayer

Phase 1 (feasibility) is the body of this document; **phase 2 (input
plumbing) is at the end**, after the phase-1 quick-reference.

## Phase 1: feasibility (2026-08-01)

Knife Edge has a **four-player** multiplayer mode set that has never run under
this recomp: the game refuses to offer it unless the runtime reports more than
one controller, and `get_connected_device_info` has always reported port 0
only. This phase answers whether that code even works here before any input
plumbing is designed.

**Verdict: GO.** A four-player game boots, runs, and exits cleanly; the frame
rate is normal; nothing wedges. Two enhancements misbehave and are precisely
characterised in §6 — both are *draw-side* faults with no gameplay consequence,
and both are deferred to phase 3 by design (nothing was fixed here).

All measurements are on this tree, headless: Xvfb `:95` 1280x720 + lavapipe,
dummy audio, scratch `KE_DATA_DIR`, `build-shim`, ROM
`ke_recomp_data/knifeedge.n64.us.1.0.z64`. Screenshots, dumps and the driving
scripts are throwaway and live in the job scratch dir, not the repo. Reads and
pokes of game RAM use the `/proc/<pid>/mem` method of
`letterbox-full-height.md` §6 (process + rdram base located exactly as
`scripts/capture_wedge_state.sh` does).

---

## 1. `KE_FORCE_PORTS` — the diagnostic this phase needed

`src/main/main.cpp`, `get_connected_device_info`. `KE_FORCE_PORTS=<n>` (1..4)
makes ports `0..n-1` report the same `Device::Controller` / `Pak::None` that
port 0 reports today; ports `n..3` stay `Device::None`. One stderr line on the
first call:

```
[input] KE_FORCE_PORTS=4: reporting ports 0..3 as connected (only port 0 receives input)
```

It is a **permanent, env-gated diagnostic** in the same family as `KE_PERF`,
`KE_AUDIO_DUMP` and `KE_DL_DUMP`, not an enhancement: it changes nothing unless
the variable is set. Unset, `parse_forced_ports()` returns 1 and the function
reduces to the original `controller_num == 0` test — the same two return
values, in the same order, for every input. (Phase 2 changed the unset return
to `0` and moved the resolution into `main()`; the override's meaning and its
precedence over everything else are unchanged. See P2.1.) Confirmed by inspection and by
`scripts/smoke_test.sh` **PASS** with the variable unset (alive, 34215 distinct
colours, 99.3 % non-zero audio) plus a boot with no `[input]` line in the log.

It deliberately does **not** route input. `get_input()` still early-returns for
`controller_num != 0`, so ports 1..3 read connected-but-neutral. That is enough
for the game to offer *and enter* a multiplayer game with idle players, which
is exactly what a feasibility probe wants: it isolates "does the multiplayer
code path work" from "is our input plumbing right". (Phase 2 routes input to
ports 1..3 for real; a forced port with no pad on it still reads
connected-but-neutral, so this paragraph's *use* as a diagnostic is unchanged.)

Setting it does **not** disturb single player: a STORY mission entered with
`KE_FORCE_PORTS=4` still draws one reticle and one player (§10 O1).

---

## 2. What the game offers, and what gates it

`GAME MODE SELECT` is a four-entry horizontal carousel, `Left`/`Right` to
scroll, `A` to accept, with a one-line green/red caption underneath:

| entry | caption | players |
|---|---|---|
| STORY | Single Player Story Mode | 1 |
| **TEAM** | **Multi Player Story Mode** | 2–4, co-op |
| **BATTLE** | **2 or 4 Player Team Battle Mode** | 2 or 4, teams |
| PRACTICE | (single) | 1 |

Order left→right is `PRACTICE, STORY, TEAM, BATTLE` and it wraps; the carousel
opens on STORY.

**The caption colour *is* the gate, and the gate is the reported controller
count.** Measured by sampling the caption band (y 600..660) of the screenshot:

| ports reported | TEAM caption | BATTLE caption | `A` accepted? |
|---|---|---|---|
| 1 (default) | **rgb(151,0,0)** red | **rgb(151,0,0)** red | **no** — screen unchanged |
| 2 | rgb(0,188,0) green | rgb(0,187,0) green | yes |
| 3 | rgb(0,188,0) green | rgb(0,187,0) green | yes |
| 4 | rgb(0,188,0) green | rgb(0,187,0) green | yes |

So the requirement is simply **≥ 2 controllers reported at `osContInit` time**.
BATTLE's "2 or 4" is a *description*, not an extra gate — 3 reported
controllers still enables it. STORY's caption is green at every count.

Nothing else gates it: there is no player-count screen, no lobby, no "press
start to join". Player count is taken from the controller count and the game
goes straight from mode → level → stage → Rumble Pak notice → mission.

### 2.1 The exact key path (headless, `xdotool`)

Keys held 0.45 s per `timing-and-mission-debug.md` §3.1; `windowfocus`, not
`windowactivate`. Sleep after each press in parentheses.

```
Return (4 s)   title -> main menu (GAME START / CONTROLLER CONFIG / SOUND OPTION)
x      (4 s)   GAME START -> GAME MODE SELECT, opens on STORY
Right  (2 s)   -> TEAM              [Right Right for BATTLE]
x      (4 s)   -> GAME LEVEL SELECT (NORMAL)
x      (5 s)   -> STAGE 1  (TEAM: "PATH A"; BATTLE: "Stage Select")
x      (6 s)   -> Rumble Pak notice
x      (12 s)  -> mission (intro cutscene, then gameplay ~25 s later)
```

Total process-start to gameplay is ~95 s, which is what `KE_DL_DUMP_AFTER_S`
has to clear.

**Correction from phase 2:** the first `x` after `Return` is swallowed in
practice (it lands during the title→main-menu transition), so the sequences
that actually work are `Return, x, x, Right, x, x, x, x` for TEAM and
`Return, x, x, x, x, x, x` for STORY. Getting this wrong is *silent* — the
`Right` lands on the vertical main menu, does nothing, and the run enters
STORY while looking exactly like a successful TEAM boot. Always screenshot the
GAME MODE SELECT frame and confirm the caption before trusting a multiplayer
measurement.

---

## 3. Boot / run verdict: **no wedge**

`KE_FORCE_PORTS=4`, `--profile enhanced`, TEAM, stage 1, keyboard on P1 only,
P2–P4 idle.

* **Reaches gameplay.** Mission-intro cutscene with radio dialogue and
  portraits, then normal gameplay with terrain, enemies, four reticles, health
  and S-BOMB HUD.
* **Frame rate is normal.** `KE_PERF` steady at **26.6–27.0 frames/s** at
  60.00 VI/s through the whole mission — indistinguishable from single player
  at the current 36.5 ms budget. Cutscenes run at 16–20 frames/s, exactly as
  in single player (the game's own limiter, see CLAUDE.md).
* **Soak: 4.6 minutes of continuous in-mission play**, plus ~1.5 min of
  menus/cutscene, in one run. 384 `[perf]` samples, mean 24.2 frames/s overall
  and 25.5 over the last 200 (the dips are cutscene frames). Zero
  `error`/`fail`/`assert` lines. Graphics-tasks-in-flight `0x8013C280` and the
  per-retrace callback `0x800EBC00` both healthy throughout.
  (P1 alone cannot keep the aircraft alive indefinitely, so the health word —
  §5.3 — was held at 100 from outside the process for the soak. That is a
  measurement aid, not a fix: the run before it ended by the aircraft being
  destroyed, which is the *correct* outcome and is covered next.)
* **Mission exit is clean.** In an earlier, unheld run the aircraft was
  destroyed after ~2.5 min. The game ran the death sequence, tore the mission
  down and returned to the **title screen** with the front-end overlays
  reloaded into their shared slots — `0x800EBC00` went from `0x8019CF84`
  (mission) to `0x8017B17C` (title). No hang, no stray-sound burst, none of
  `timing-and-mission-debug.md` §5's signature.
* **BATTLE mode also boots and plays**, reaching gameplay with its own
  two-team HUD (§4.2). Same 27 frames/s, same in-mission callback.
* **A mid-mission cutscene** (radio dialogue partway through stage 1) and a
  **boss with a health bar** were both reached during the soak and rendered
  without incident.

No new spin-loop wedge appeared. That is consistent with the mechanism rather
than luck: multiplayer runs the *same* in-game overlay (`seg_1501A0`, per-retrace
callback `0x8019CF84`) and the same mission loop as single player — see §5.4 —
so `find_spin_loops()`'s existing coverage applies unchanged.

---

## 4. The multiplayer HUD, from the display list

`KE_DL_DUMP` captures of 60 mission frames each, attributed per executing
sub-DL (same method as `hud-relocation.md` phase 3 §2).

### 4.1 TEAM (co-op) — single HUD, four reticles

| element | sub-DL @ | texture | size | ul | frames |
|---|---|---|---|---|---|
| **reticle P1** | `0x801C8470` | `0x8003E480` | 32x32 | (166,124) | 60/60 |
| **reticle P2** | `0x801C8590` | `0x8003E680` | 32x32 | (206,124) | 60/60 |
| **reticle P3** | `0x801C86B0` | `0x8003E880` | 32x32 | (166,84) | 60/60 |
| **reticle P4** | `0x801C87D0` | `0x8003EA80` | 32x32 | (206,84) | 60/60 |
| health backing | `0x801BCE30` | `0x8003EC80` | 64x48 | (20,172) | 60/60 |
| health jet glyph | `0x801BD070` | `0x8003F280` | 32x32 | (28,180) | 60/60 |
| health number panel | `0x801BD2B0` | `0x8003F480` | 32x24 | (54,179) | 60/60 |
| health fill | `0x801BD4F0` | `0x8003F600` | 48x48 | (20,172) | 60/60 |
| health % digits | `0x800F2B50` | `0x8016B3C8` | 3 x 8x13 | (59\|67\|75,183) | 60/60 |
| S-BOMB gauge | `0x801C25F0` | `0x80045100`+ | 5 x 16x32 | (215..295,188) | 60/60 |

**The co-op HUD is the single-player HUD, unchanged, plus three extra
reticles.** Every non-reticle address, texture and coordinate is byte-identical
to `hud-relocation.md` §3.1's single-player table. There is one health dial,
one S-BOMB gauge, one % readout — no per-player elements, no score displays.

That is because in TEAM the four players are gunners on **one aircraft**:
health is a single shared scalar (§5.3), so a single dial is correct.

The four reticles form two clean arithmetic progressions:

```
sub-DL  = 0x801C8470 + slot * 0x120
texture = 0x8003E480 + slot * 0x200
```

and each has its own colour: **slot 0 green, slot 1 red, slot 2 yellow,
slot 3 magenta** (established by poking one slot at a time, §5.2).

The `ul` values above are the *biased* ones — see §6.1; unbiased they would be
(124,124) / (164,124) / (124,84) / (164,84), i.e. `160 + X - 16`,
`120 + Y - 16` from the slot's reticle words.

### 4.2 BATTLE — a genuinely different, mirrored two-team HUD

| element | team A sub-DL | ul | team B sub-DL | ul |
|---|---|---|---|---|
| health backing | `0x801BCE30` | (16,172) | `0x801BCF50` | (233,172) |
| health jet glyph | `0x801BD070` | (24,180) | `0x801BD190` | (241,180) |
| health number panel | `0x801BD2B0` | (50,179) | `0x801BD3D0` | (267,179) |
| health fill | `0x801BE6F0` | (16,172) | `0x801BE810` | (233,172) |
| health % digits (2) | `0x800F2B50` | (63\|71,183) | `0x800F2BF0` | (280\|288,183) |
| S-BOMB gauge | `0x801C25F0` | (78..158,188) | `0x801C2890` | (156..236,188) |
| reticles | `0x801C8470` +slot*0x120 (all four, identical to TEAM) | | | |

Three things phase 3 must not miss:

1. **The mirror twins are `+0x120` from the team-A addresses** for every dial
   part (and `+0xA0` for the digits, `+0x2A0` for the gauge) — the same
   `0x120` grid the reticles use. Team B's copies are *not* in
   `hud_relocation`'s fingerprint table.
2. **Team A's elements are at different coordinates than in single player**
   (dial x 16 not 20; two digits not three; S-BOMB at x 78 not 215) — but at
   the *same addresses*, so the existing table still matches them and moves
   them as if they were the single-player widgets.
3. **The two S-BOMB gauges sit side by side in the centre**, not at a frame
   edge, which is what makes `hud_relocation`'s `Right` anchor visibly wrong
   there (§6.2).

---

## 5. RAM layout

### 5.1 The reticle slots — base, stride, all four

From `func_8016E520_1501A0`'s own address arithmetic (generated C, four
identical clamp blocks at `0x8016EC30`–`0x8016ECEC`):

```
0x8016EC30  lui   $t9, 0x8012
0x8016EC34  addiu $t9, $t9, -0x2BA8       ->  base = 0x8011D458
0x8016EC38  sll   $t0, $a0, 2             ->  slot * 4
0x8016EC3C  addu  $t5, $t0, $t9
0x8016EC40  lw    $t6, 0x64($t5)          ->  reticle X
...         lw    $t4, 0x74($t8)          ->  reticle Y
```

so, confirming and completing `hud-relocation.md`'s "Reticle range extension"
§2 for every slot:

| | address | measured value at mission start (stage 1) |
|---|---|---|
| reticle X | `0x8011D4BC + slot*4` | slot 0..3 = **−20, +20, −20, +20** |
| reticle Y | `0x8011D4CC + slot*4` | slot 0..3 = **+20, +20, −20, −20** |

Both are four-element `int32` arrays, stride 4, base `0x8011D458 + 0x64` /
`+ 0x74`. Verified live: writing slot *n* moves exactly one reticle.

`func_8016E520_1501A0` is called **six** times from `func_8016DF5C_1501A0`,
with `$a0` = `0` (twice), a stack variable, `1`, `2`, `3` — i.e. the
multiplayer paths pass explicit slot numbers, so the per-slot hooks are
genuinely exercised for all four.

Related per-slot table, used by the `extended_aim` blit hook:

```
reticle sprite object pointer = *(0x8019D864 + slot*4)
measured live in a 4-player mission: 801A5D20, 801A5D94, 801A5E08, 801A5E7C
```

Four distinct live pointers, stride `0x74`. This matters: `ke_reticle_blit_x`
compares the blit's sprite against **all four** entries, so it biases all four
reticles, not just P1's (§6.1).

### 5.2 Slot → player → colour

| slot | colour | who |
|---|---|---|
| 0 | green | **P1** — the only slot our keyboard/pad/mouse reaches |
| 1 | red | P2 |
| 2 | yellow | P3 |
| 3 | magenta | P4 |

Slot 0 = P1 was established directly: with all four slots zeroed, holding `d`
(right on the keyboard stick) for 1.2 s moved slot 0 to its rail and left
slots 1–3 at 0. The colour assignment was established by setting the four X
words to four distinct values and measuring each hue's centroid; every
prediction landed within 1 px.

### 5.3 Shared health, not per-player

`0x8011D464` (= `0x8011D458 + 0x0C`) tracks the on-screen health readout
exactly (measured `100 → 78` while the HUD read `100 → 78`). It is a **single
scalar**, not a four-element array, in TEAM mode — consistent with §4.1's
single dial and with the premise that co-op players are gunners on one
aircraft. Holding it at 100 from outside the process keeps a TEAM mission alive
indefinitely, which is how the §3 soak was run. BATTLE shows two dials with
independent values (80 / 78 observed), so it has a second health word that was
not located; not needed for this phase.

### 5.4 Multiplayer uses the same in-mission code as single player

`0x800EBC00`, the per-VI-retrace callback pointer whose value names the running
screen (`rcp_timing.cpp`, `mouse-aim.md` §6.2), reads **`0x8019CF84`** in a
TEAM mission *and* in a BATTLE mission — the same `func_8019CF84` of
`seg_1501A0` that single player registers. Measured repeatedly across four runs.

This is the single most load-bearing negative result in the probe. It means
multiplayer is not a separate screen with its own overlay and its own waits:
it is the same mission loop, so every timing fix, spin-yield hook and gate this
port already carries applies to it unchanged — including `mouse-aim`'s gate 1
(§6.3).

---

## 6. Enhancement compatibility

### 6.1 `extended_aim`: the clamp is right for all four slots, the draw is not

**A — the clamp (`src/main/extended_aim.cpp`, `ke_reticle_clamp_stash` /
`ke_reticle_clamp_apply`): correct.** The hooks take the slot from `$a0` and
index `base + slot*4`, which §5.1 confirms is the real layout, and the
single-scalar stash remains sound because the six calls are sequential, never
nested. Verified live by poking all four slots past the rails and reading them
back one game frame later:

| profile | poked | slot 0 | slot 1 | slot 2 | slot 3 |
|---|---|---|---|---|---|
| enhanced | X = +250 | **+170** | **+170** | **+170** | **+170** |
| enhanced | X = −250 | −170 | −170 | −170 | −170 |
| enhanced | Y = ±250 | ±100 | ±100 | ±100 | ±100 |
| vanilla | X = ±250 | ±128 | ±128 | ±128 | ±128 |
| vanilla | Y = ±250 | ±84 | ±84 | ±84 | ±84 |

So the widened rails apply per slot exactly as intended, and **vanilla still
rails all four slots at the original ±128 / ±84** — the regression baseline is
intact.

(The clamp only re-applies on frames where the aim function runs. During an
in-mission cutscene it does not, and a poked out-of-range value simply persists
until gameplay resumes. Observed, and not a defect.)

**C — the draw: BUG, `enhanced` only.** `ke_reticle_blit_x` shifts the blit's
x right by `B = rails_x() − 128` (42 at 16:9) for **any** sprite in the
four-entry table of §5.1, and `hud_relocation`'s reticle stub subtracts the
same `B` back — but only for sub-DL `0x801C8470`. P2–P4's sub-DLs
(`0x801C8590` / `0x801C86B0` / `0x801C87D0`) are not in the fingerprint table,
so nothing undoes their bias and nothing `Center`-anchors them either.

The dumped `ul` values in §4.1 are the direct evidence: every reticle's texrect
is emitted at `160 + X − 16 + 42`.

Measured, 1280x720, `--profile enhanced`, all four slots poked to the same X,
Y = 0. "Correct" is where P1's reticle lands for that X.

| poked X | slot 0 (green) bbox | slots 1–3 bbox | error |
|---|---|---|---|
| −100 | 289..384 (full 96 px) | 568..663 / 718..813 / 868..963 for X = −50/0/+50 | +128.5 px each |
| +128 (vanilla rail) | 973..1068 (full) | 1102..1197 (full) | **+129 px** |
| +170 (widened rail) | 1099..1194 (full) | **1228..1275** (48 of 96 px) | +129 px, then **sliced by the window's right edge** |
| −170 | 79..174 (full) | 208..303 (full) | +129 px |

`+129` is `42 N64 px x 3 = 126` plus RT64's known ~3 px misalignment shift,
which applies to P1's origin-tagged rect and not to theirs
(`hud-relocation.md` phase 2 §4). The slicing at `+170` is *not* the game's
own sprite-library clip — `ke_reticle_blit_x` marks the scissor call for every
reticle, so the software box is widened for all four; it is the render target's
right edge, because an untagged rect at N64 x 356..388 maps to window
1228..1324 inside the centred 4:3 column.

**Vertical is unaffected**: `extended_aim` applies no vertical bias, and at
Y = ±100 all four reticles draw in full at window y 612..707 / 12..107.

**Vanilla is unaffected**: with `B = 0` the blit hook returns `x` unchanged and
the stub is not built. Measured in a vanilla TEAM mission with the four slots
at X = −100/−40/+40/+100: all four land exactly at `160 + (160 + X − 16)*3`,
error 0 px.

Two candidate shapes for phase 3, both obvious once the mechanism is stated —
either add the three sub-DLs to the fingerprint table as `Center`-anchored
bias-undoing entries (they are a fixed `+ slot*0x120` progression, so this is
three table rows), or restrict `ke_reticle_blit_x`'s bias to slot 0. The first
keeps all four players' extended range; the second gives it to P1 only.
Not decided here, and deliberately not implemented.

### 6.2 `hud_relocation`: fine in TEAM, wrong in BATTLE

**TEAM: correct.** §4.1's HUD is the single-player HUD at the same addresses,
so the fingerprint table matches it exactly. `[hud] relocation active: 7
element redirects this frame` — the same 7 as single player — and the health
fill is picked up by the phase-3 region matcher (`[hud] health fill matched by
region at sub-DL 0x801BD4F0`). Screenshots show the dial flush in the
bottom-left and the gauge flush in the bottom-right, as designed.

**BATTLE: visibly wrong**, and the display list says exactly why:

* Only **6** redirects fire (`[hud] relocation active: 6 element redirects
  this frame`). Team B's mirror twins (`0x801BCF50`, `0x801BD190`,
  `0x801BD3D0`, `0x801BE810`, `0x800F2BF0`, `0x801C2890`) are unmatched and
  stay in the centred 4:3 column while team A's are dragged to the window
  edges. Measured on screen: team A's dial at window x≈45 (relocated), team B's
  at x≈860 (not).
* Worse, team A's **S-BOMB gauge is dragged the wrong way**. The table gives
  `0x801C25F0` a `Right` anchor with a −320 px offset because in single player
  it sits at N64 x 215..295. In BATTLE it sits at x 78..158, so the anchor puts
  it at window `1280 + (78 − 320)*3 = 554` — left of centre, next to team B's
  untouched copy at `160 + 156*3 = 628`. Both gauges end up huddled in the
  middle of the screen, which is what the screenshot shows.
* The **region matcher misfires** there too: `[hud] S-BOMB fill matched by
  region at sub-DL 0x801BF7D0` — an address from the *health* fill pool
  matching the *S-BOMB* box. The geometric boxes in
  `rt64_render_context.cpp` are the single-player containers' footprints and
  BATTLE's layout does not respect them. This was observed once, outside the
  dumped window; phase 3 should take a dedicated capture before designing
  around it.

None of this is new *code* risk — it is `hud-relocation.md` phase 1's open
question **O2** ("other in-mission states … a HUD element that only appears
there is simply not in the fingerprint table, so it stays in the 4:3 column
while its neighbours move; that is the failure mode to look for") arriving
exactly as predicted, in a mode nobody had been able to enter.

### 6.3 `mouse-aim`: live in multiplayer, drives P1 only, no inertness

The brief's specific worry — that multiplayer might register a different
per-retrace callback and silently make mouse aim inert — **does not
materialise**. §5.4: `0x800EBC00` reads `0x8019CF84` in TEAM and in BATTLE,
the same value `main.cpp`'s `mission_retrace_callback` tests for, so gate 1
passes. Gates 2 (the mission clock stepped recently) and 3 (the mouse moved
recently) are mode-independent.

`publish_reticle_state` reads slot 0's words only, and the controller it drives
is `get_input(0)`, so mouse aim closes its loop on P1 and cannot disturb P2–P4.
That is the correct behaviour today and stays correct after phase 2 as long as
mouse aim keeps targeting whichever port the mouse is assigned to.

### 6.4 The rest

`widescreen`, `high_resolution`, `full_height` are mode-independent by
construction (projection matrix, render target, scissor) and nothing in the
captures contradicts that: the BATTLE and TEAM dumps show the same
`full_height` scissor and the same 3D behaviour as single player.

---

## 7. Design inputs for phase 2 (input plumbing)

1. **Report the real count.** The only thing standing between this port and
   multiplayer is `get_connected_device_info`. Phase 2 should report one port
   per connected host input device (keyboard counts as one), and
   `KE_FORCE_PORTS` should keep working as an override for testing. The count
   must be right **before** `osContInit`, i.e. before `recomp::start()`, since
   the mode gate is evaluated from what the game latched then — mid-session
   hotplug changing the *count* is a separate question (the gamepad hotplug
   path already exists but currently only ever feeds port 0).
2. **`get_input` must become per-port.** It early-returns for
   `controller_num != 0` today, and every input source (`sample_buttons`, the
   pad state, the mouse controller) is a single set of process-wide atomics.
   Phase 2 needs a per-port record and a device→port assignment policy. Today
   *all* pads deliberately act as controller 1 (CLAUDE.md); that is exactly the
   line that has to change, and it should stay the default when only one device
   is present so nothing regresses for single-player users.
3. **Only slot 0 has enhancement support.** Mouse aim, the `extended_aim` draw
   stub and `reticle_state` are all slot-0-specific. Phase 2 should decide
   whether the mouse belongs to a *port* (and follows it) or stays pinned to
   P1.
4. **Nothing needs to change in the recompiled game code.** The game already
   drives four slots; the clamp hooks already take a slot argument and already
   work for all four (§6.1).
5. **The reticle colours are fixed by texture** (`0x8003E480 + slot*0x200`), so
   "which player am I" is answered on screen by colour, not by position. Worth
   surfacing in the README's controls table when phase 2 lands.

## 8. Design inputs for phase 3 (enhancement fixes)

| # | what | where |
|---|---|---|
| F1 | P2–P4 reticles drawn +42 N64 px right and sliced at the rail in `enhanced` | §6.1 — three fingerprint rows, or restrict the bias to slot 0 |
| F2 | BATTLE HUD: team B's six mirror elements unmatched | §6.2 — the twins are `+0x120`/`+0xA0`/`+0x2A0` from team A's |
| F3 | BATTLE HUD: team A's S-BOMB gauge dragged to the wrong side | §6.2 — the `Right` anchor's offset assumes the single-player x |
| F4 | BATTLE: region matcher misfire (`S-BOMB fill` matched a health-pool sub-DL) | §6.2 — needs a dedicated capture first |

All four are cosmetic and `enhanced`-only; `--profile vanilla` is correct in
every multiplayer mode measured.

**All four are fixed — see "Phase 3: enhancement compatibility" at the end of
this document** for what changed, the BATTLE anchor design, and the before/after
measurements. Two claims in §4.2/§6.2 above are corrected there: the BATTLE
health fills have no fixed address (the `+0x120` twin rule holds for them, the
specific addresses do not), and F4's misfiring sub-DL is identified — it is
team B's *health* fill matching single player's S-BOMB box.

A **fifth** fault of the same family, F5, was found during phase 3 rather than
predicted by phase 1 and is fixed there too (P3.6): BATTLE's damage flash is
*two* half-frame rects in two sub-DLs, one per team, and the table had the
single-player full-frame anchor on one of them and no entry for the other.

---

## 9. Verdict and risk list

**GO.** Multiplayer is not a hazardous unknown in this port: it is the same
mission loop, the same overlay, the same per-retrace callback and the same
per-slot state arrays the single-player path already exercises, and it runs at
full speed for minutes without incident. The work in phase 2 is confined to our
own input layer.

Risks, in descending order:

1. **Per-port input is a real refactor of `get_input`**, touching the keyboard,
   pad, mouse and latching paths at once — all of which are currently
   process-wide singletons and all of which are owner-verified as they stand.
   Regression surface for single player is the thing to protect.
2. **Device→port assignment has no obviously right answer** (which pad is P2?
   what if the keyboard and one pad are present?) and it is user-visible.
   Decide it in the brief, not in the code.
3. **Mode selection is latched from the controller count at boot.** A player
   who plugs a second pad in at the title screen may not get the multiplayer
   entries enabled. Needs checking once the count is real.
4. **F1–F4 are cosmetic but will read as "multiplayer is broken"** to anyone
   who tries it on the default (`enhanced`) profile. Phase 3 should land with,
   or before, phase 2.
5. **Only stage 1 was exercised**, in TEAM and BATTLE, on `NORMAL`. The
   results screen, stage clear and the multiplayer score/ranking screens are
   unexamined — `hud-relocation.md`'s **O2** again.
6. **`KE_FORCE_PORTS` reports *phantom* controllers.** Everything above was
   measured with three players who never press anything. A mode that waits on
   all players (a versus round that needs both teams to act) could behave
   differently with real input. Nothing observed suggests it, but it is not
   ruled out.

## 10. Open questions

* ~~**O1 — does a reported count > 1 change single-player STORY?**~~
  **Answered: no.** A STORY mission entered with `KE_FORCE_PORTS=4` draws
  exactly **one** reticle (slot 0, green, centroid window x 636.5 for X = 0 —
  the correct `Center`-anchored, unbiased position), leaves slots 1–3 at
  `X = Y = 0` and never draws them, and shows the ordinary single-player HUD.
  Forcing the count enables the *menu entries*; it does not add players to a
  single-player game.
* **O2 — BATTLE's second health word** was not located (§5.3).
* **O3 — the boss health bar** (seen at the top of the frame during the soak)
  is not in any fingerprint table and was never dumped. It is a single-player
  element too, so this is `hud-relocation.md` O2 rather than a multiplayer
  question, but the multiplayer soak is what finally reached it.
* **O4 — hotplug.** Whether a pad connected mid-session can raise the port
  count usefully, or whether `osContInit`'s snapshot is final, is untested
  (§7.1).

## 11. Address quick-reference

```
per-slot reticle state (int32 arrays, stride 4, slots 0..3):
0x8011D458                state block base (= 0x80120000 - 0x2BA8)
0x8011D4BC + slot*4       reticle X   (+0x64)
0x8011D4CC + slot*4       reticle Y   (+0x74)
0x8011D464                shared health readout (TEAM; single scalar)
0x8019D864 + slot*4       reticle sprite object pointer
                          (live: 801A5D20 / 801A5D94 / 801A5E08 / 801A5E7C)

reticle sub-DLs and textures (both arithmetic in the slot):
0x801C8470 + slot*0x120   0x801C8470 / 8590 / 86B0 / 87D0
0x8003E480 + slot*0x200   0x8003E480 / E680 / E880 / EA80   32x32
slot 0 green, 1 red, 2 yellow, 3 magenta

BATTLE mirror twins (team B = team A + delta):
+0x120  health backing / jet glyph / number panel / fill
        0x801BCF50 / 0x801BD190 / 0x801BD3D0 / 0x801BE810
+0xA0   health % digits          0x800F2BF0
+0x2A0  S-BOMB gauge             0x801C2890

screen identity:
0x800EBC00 == 0x8019CF84   in a mission, single player AND TEAM AND BATTLE
0x800EBC00 == 0x8017B17C   title screen

code:
func_8016E520_1501A0      per-slot aim integrator + clamp; $a0 = slot
                          six call sites in func_8016DF5C_1501A0:
                          0, 0, <stack var>, 2, 1, 3
0x8016EC30 .. 0x8016ECEC  the four clamp blocks (extended_aim's hook sites)
```

---

# Phase 2: input plumbing (2026-08-01)

Phase 1 left the game able to *enter* a multiplayer match with phantom
players: `get_connected_device_info` could be made to report up to four ports,
but `get_input()` early-returned for every port but 0, so P2–P4 never pressed
anything. Phase 2 makes ports 1–3 real.

The design was fixed in the brief before any code was written (phase 1 §9
risk 2: *"device→port assignment has no obviously right answer and it is
user-visible — decide it in the brief, not in the code"*). What follows is
that design, what it cost, and how each part was verified.

Everything is in `src/main/main.cpp` (the input region) and
`src/main/config.{h,cpp}`. **No recompiled game code, no `analysis/` pipeline
change, and nothing in `deps/`** — phase 1 §7.4 predicted exactly this, and it
held.

## P2.1 The policy

1. **Keyboard and mouse are port 0's, always, and only port 0's.** Every
   keyboard binding, the mouse capture/accumulate/button state and the whole
   positional mouse controller stay single-instance. Mouse aim therefore keeps
   closing its loop on reticle slot 0 (phase 1 §6.3) with no change at all.

2. **Pads take ports in connection order**, each new pad claiming the lowest
   free port at or above `input.pad_start_port` (new key, `0..3`, default `0`).

   * `pad_start_port = 0` (default) puts the first pad on port 0, where it
     merges with keyboard and mouse — **bit-for-bit the behavior every build
     before this one had for a single pad**. A second pad then becomes P2, a
     third P3, and so on.
   * `pad_start_port = 1` gives a keyboard-only P1 and pads as P2–P4: the
     two-humans-one-pad setup.

   Assignment is **sticky**: a disconnect frees only that pad's port and the
   pads that remain keep theirs, so ports never renumber under a player's
   hands. A reconnect takes the lowest free port again.

   This replaces the old "every pad acts as controller 1, buttons OR'd and
   sticks summed" policy. That merge now happens only *within* a port, and at
   most one pad can occupy a port — so in practice only port 0 merges
   anything, and only with keyboard and mouse.

3. **Reported connectivity**, highest precedence first:

   | source | meaning |
   |---|---|
   | `KE_FORCE_PORTS=<n>` env | report ports `0..n-1`; unchanged from phase 1 |
   | `input.ports` = 1..4 (new key) | report exactly that many ports |
   | auto (`input.ports = 0`, default) | port 0 always; ports 1–3 iff a pad is *currently* assigned there |

   The count is resolved and logged **once, in `main()`, before
   `recomp::start()`** — not lazily on first call as in phase 1. That is
   deliberate: the game latches the controller count at `osContInit` and gates
   the multiplayer menu entries on what it latched (§2, and phase 1 §9 risk 3).
   The startup line names the resolved policy:

   ```
   [input] ports: auto -- port 0 always (keyboard/mouse), ports 1-3 follow connected pads; pads from port 0
   [input] ports: KE_FORCE_PORTS=2 -- reporting ports 0..1 as connected (a port with no pad assigned reads neutral); pads from port 0
   [input] ports: input.ports=2 -- reporting ports 0..1 as connected (a port with no pad assigned reads neutral); pads from port 1
   ```

   Hot-plug lines now name the port: `Gamepad connected: pad '<name>' ->
   port N` and, on removal, `Gamepad disconnected: port N freed`.

4. **`get_input(n)`**:
   * `n == 0` — the pre-existing full merge: keyboard sample, event-latched
     keys/mouse/port-0-pad presses (only when the `input_latching`
     enhancement is on), port-0 pad state, mouse controller output.
   * `n in 1..3` — that port's pad and nothing else. Identical stick shaping
     (`input.stick_deadzone`/`stick_curve`/`stick_sensitivity`), identical
     trigger→Z and right-stick→C mappings, identical per-port press latching
     under the same enhancement flag. No keyboard, no mouse.
   * A port reported connected with **no pad** reads connected-but-neutral:
     `true` with zero buttons and zero stick.
   * A port reported **disconnected** returns `false`, which librecomp turns
     into `CONT_NO_RESPONSE_ERROR`. This is exactly what every previous build
     did for `n != 0`, so the single-player wire format is unchanged.

## P2.2 The guarantee that mattered most: port 0 is untouched

Phase 1 §9 risk 1 was that this refactor touches keyboard, pad, mouse and
latching at once, all of them owner-verified as they stand. The structure was
chosen to make that reviewable rather than to be elegant:

* `pad_buttons` / `pad_stick_x` / `pad_stick_y` / `latched_buttons` became
  `[4]` arrays with the **same relaxed-atomic discipline** (event thread
  writes, the ~15 Hz controller-read thread reads).
* The sampling pass in `update_gfx()` kept its accumulate-then-publish shape
  and simply indexes the accumulators by port, so the port-0 path diffs as
  "the old path plus an index" rather than as a rewrite. The OR/sum now only
  ever has one contributor per port, which is a harmless no-op, not a
  behavior change.
* Every keyboard and mouse write is hard-coded to `latched_buttons[0]`, with a
  comment saying why at each site.

Net effect with no pad connected and no new config keys set: the port-0 code
path is the old code path with `[0]` appended to four loads, and
`get_connected_device_info` answers exactly as before.

## P2.3 Rumble: plumbing wired, behavior deliberately unchanged

`set_rumble` was an empty `void set_rumble(int, bool)` and **remains a no-op**,
now with the port index named and documented.

This is not laziness, it is the enhancement policy. `set_rumble` is only ever
reached through `osMotorStart`/`osMotorStop`, and
`ultramodern/src/input.cpp`'s `osMotorInit` refuses with `PFS_ERR_NOPACK`
unless `get_connected_device_info` reports `Pak::RumblePak` for that port. We
report `Pak::None` on every port — the faithful answer for a player with no
Rumble Pak — so the callback is unreachable in practice. Making pads actually
rumble means telling the game a Rumble Pak is *inserted*, which changes what
the game does (it has its own Rumble Pak notice screen before every mission).
That is an enhancement with a flag, not a quiet side effect of per-port input,
and it was not in this brief. The comment at `set_rumble` records where the
port→pad lookup would go.

## P2.4 Verification (headless, this tree)

Xvfb 1280x720 + lavapipe, dummy audio, scratch `KE_DATA_DIR`, `build-shim`,
ROM `ke_recomp_data/knifeedge.n64.us.1.0.z64`. Driving scripts are throwaway
and live outside the repo.

**A note on the key path.** Phase 1 §2.1's recipe is one press short in
practice: the first `x` after `Return` is swallowed (it lands during the
title→main-menu transition), so the working sequences here are
`Return, x, x, x, x, x, x` for STORY and
`Return, x, x, Right, x, x, x, x` for TEAM. Getting this wrong is silent —
the `Right` lands on the vertical main menu, does nothing, and the run enters
**STORY** while looking exactly like a successful TEAM boot. Two runs were
wasted that way before per-step screenshots caught it. Screenshot the GAME
MODE SELECT frame and confirm the caption, always.

| gate | result |
|---|---|
| Build | clean (`cmake --build build-shim`) |
| `scripts/smoke_test.sh` | **PASS** — alive, 34215 distinct colours, 99.4 % non-zero audio |
| Single-player regression, keyboard | **PASS** — reaches stage-1 gameplay, one green reticle, 26.6–27.0 frames/s at 60.00 VI/s |
| TEAM via `KE_FORCE_PORTS=2` | **PASS** — TEAM caption green, two-player mission, green P1 + red P2 reticles |
| TEAM via `input.ports = 2` | **PASS** — same, and the same policy line modulo its source |
| TEAM soak | **PASS** — 274 s run (~3.5 min in-mission), 271 `[perf]` samples, last-50 mean 26.68 frames/s, min 16.0 (cutscene frames), no new errors |
| Config keys | **PASS** — see below |
| **Pad→port assignment, end to end** | **PASS** via SDL virtual joysticks — see P2.5 |

**Keyboard drives P1 and only P1.** Measured on a live two-player TEAM
mission by holding `d` for 2 s and reading the reticle centroids off the
frames (green = slot 0, red = slot 1, per phase 1 §5.2):

| | green (P1) | red (P2) |
|---|---|---|
| before | (571, 352) | (823, 359) |
| after holding `d` 2 s | **(1144, 366)** | **(825, 359)** |

P1 travels 573 px; P2 does not move. That is the whole phase-2 contract in one
measurement: the keyboard reaches port 0, port 1 is reported connected and
reads neutral.

**Config surface.** New keys parse, clamp with the standard single warning,
appear in the generated template with comments, and are reported by
`describe_config`:

```
input.pad_start_port = 7  -> [config] warning: input.pad_start_port = 7 is out of range [0, 3]; clamping to 3
input.ports = 9           -> [config] warning: input.ports = 9 is out of range [0, 4]; clamping to 4
input.pad_start_port = -3 -> clamped to 0;  input.ports = -1 -> clamped to 0
unknown key                -> [config] warning: unknown key(s) in ...: input.bogus_key (ignored)
non-default values         -> profile: vanilla (stick_deadzone=0.20, pad_start_port=1, ports=2)
```

The freshly generated `config.toml` template round-trips with **no** warnings.

**Precedence proven, not assumed.** With `input.ports = 2` in the file *and*
`KE_FORCE_PORTS=4` in the environment, the resolved line is
`KE_FORCE_PORTS=4 -- reporting ports 0..3`, while `describe_config` still
honestly reports the file's `ports=2`. A malformed `KE_FORCE_PORTS=zz` warns
and falls through to `input.ports`, as it should.

## P2.5 The pad path, proven headless with SDL virtual joysticks

No pad hardware reaches this container, but SDL 2.32's
`SDL_JoystickAttachVirtual` can synthesise one in-process. That is enough to
exercise the whole pad path end to end without a single real device.

This needs code inside the binary (a virtual joystick is process-local, so no
external helper can create one), so it was a **throwaway hack in
`update_gfx()`, since reverted** — no test seam ships. It attached two
virtual controllers on the first event pump, then drove and detached pad #2 on
a timer.

**Assignment and the log lines** (auto mode, no `KE_FORCE_PORTS`, no
`input.ports`):

```
[input] ports: auto -- port 0 always (keyboard/mouse), ports 1-3 follow connected pads; pads from port 0
Gamepad connected: pad 'Virtual Controller' -> port 0
Gamepad connected: pad 'Virtual Controller' -> port 1
...
Gamepad disconnected: Virtual Controller
Gamepad disconnected: port 1 freed
```

With `input.pad_start_port = 1` the same two pads instead take **ports 1 and
2**, leaving port 0 to the keyboard — the two-humans-one-pad setup, confirmed
directly.

**The reported count follows the pads.** With two virtual pads and *no*
override of any kind, the GAME MODE SELECT carousel showed TEAM's caption in
**green**. Nothing else could have enabled it: `auto` reports port 1 only when
a pad is assigned there. This is the phase-1 gate (§2) being satisfied by real
device presence for the first time.

**Routing is per port.** In a live two-player TEAM mission, virtual pad #2's
left stick was held full right for 4 s. Reticle centroids across the soak
captures:

| capture | green (P1) | red (P2) |
|---|---|---|
| before the push | (569, 366) | (825, 359) |
| after (stick released) | (569, 357) | **(1243, 357)** |
| +15 s, +30 s, +45 s later | (561–576, ~365) | (1258, ~360) |

P2's reticle travels to the rail and stays there (the game does not
auto-centre — phase 1 §5.1); P1's does not move at all, because the pad on
port 1 reaches port 1 and nothing else. The red sprite's pixel count halves at
the rail (252 → 129), which is phase-1 §6.1's **F1** slicing showing up
exactly as predicted now that P2 can actually reach the rail.

## P2.6 What is still not verified here

1. **Real pad hardware.** Virtual joysticks exercise our assignment,
   sampling, routing and disconnect logic, but not SDL's real-device paths:
   actual button/axis mappings, trigger scaling, and physical hotplug.
   **Owner hands-on remains the gate** for those, and for whether the
   `pad_start_port` default feels right with one pad plus keyboard.
2. **Reconnect after a disconnect** taking the lowest free port again. Only
   the free half (`port 1 freed`) was driven.
3. **BATTLE mode with real per-port input.** Only TEAM was driven here.
   Phase 1 §9 risk 6 (a mode that *waits* on all players behaving differently
   once the players can actually act) is still open, and now testable.
4. **Hot-plug changing the reported count mid-session** — phase 1 O4. In auto
   mode a pad connecting after `osContInit` does update `port_has_pad`, and
   `get_connected_device_info` will report it, but whether the game re-reads
   the count is unknown. `input.ports` is the reliable answer either way.
   (Pads present at launch are fine: the virtual-pad run above enabled TEAM
   from device presence alone.)
5. **A pad with no port.** With more pads than ports at or above
   `pad_start_port` (e.g. two pads at `pad_start_port = 3`), the extra pad is
   opened, logged as `-> no free port (idle)` and contributes nothing. It is
   **not** promoted when a port later frees, because assignment is sticky.
   Reported here rather than improvised around: it is a deliberate corner of
   the frozen policy, not an oversight, but it is the one place where "sticky"
   and "lowest free port" visibly disagree with what a user might expect.
6. **Phase 3's cosmetic faults are untouched** (phase 1 §8, F1–F4). P2–P4's
   reticles are still drawn +42 N64 px right on the `enhanced` profile, which
   is now much easier to notice because P2–P4 can move them.

## P2.7 Where the frozen design met the code

Three places, all reported rather than redesigned:

1. **`get_input` for a disconnected port.** The brief asked whether the
   callback contract wants `true` with zeros or `false`. Answer, from
   `ultramodern/src/input.cpp`'s `osContGetReadData`: `false` sets
   `err_no = CONT_NO_RESPONSE_ERROR`, which is exactly "nothing in this port".
   So the split is: reported-disconnected → `false`; reported-connected but
   empty → `true` with zeros. Implemented that way, and it keeps the
   single-player wire format byte-identical to before.
2. **Rumble.** The brief allowed either implementing it or wiring plumbing
   only, conditional on what `get_connected_device_info` reports for the Pak
   field. It reports `Pak::None`, so rumble stayed a no-op — see P2.3.
3. **Clearing state on disconnect.** Not in the brief and it has to be decided
   somewhere: a pad's port has its buttons and stick zeroed when it leaves, or
   the game would read that pad's last sampled state forever (the sampling
   pass no longer visits the port). Undrained *latches* are also cleared, but
   **only on ports 1–3** — port 0's latch also holds keyboard and mouse
   presses, which are not the departing pad's to discard.

---

# Phase 3: enhancement compatibility (2026-08-01)

Phase 1 §8 listed four cosmetic, `enhanced`-only faults — F1–F4 — and
deliberately fixed none of them. This phase fixes all four. **One source file
changed: `src/main/rt64_render_context.cpp`.** No new flag, no config key, no
recompiled game code, no `analysis/` pipeline change, nothing in `deps/`.

Everything below is measured on this tree, headless, Xvfb 1280x720 + lavapipe,
dummy audio, scratch `KE_DATA_DIR`, `build-shim`, ROM
`ke_recomp_data/knifeedge.n64.us.1.0.z64`, stage 1. Screenshots, dumps and the
driving scripts are throwaway and live in the job scratch dir, not the repo.

**Every before/after number in this section is an A/B against a binary built
from the previous commit in the same session**, not a comparison against the
phase-1 write-up — the two agree, which is itself a check on phase 1.

## P3.0 The menu path, corrected again for BATTLE

Phase 1 §2.1 and phase 2's correction both describe TEAM. **BATTLE has one
extra screen**: `Stage Select` (the stage name, "Amethyst Ravine") comes
*before* `PATH A`. So the working sequences are

```
STORY    Return, x, x, x, x, x, x
TEAM     Return, x, x, Right, x, x, x, x
BATTLE   Return, x, x, Right, Right, x, x, x, x, x
```

Getting the BATTLE one wrong is silent in the same way the `Right` was: the
run simply parks on the Rumble Pak notice and stays there for the rest of its
life, which from a log looks exactly like a mission that never started.
Screenshot each step.

## P3.1 F1 — the P2–P4 reticle draw

**The clamp side needed nothing** (phase 1 §6.1 A), and neither did the
`extended_aim` blit hook. Re-read of `src/main/extended_aim.cpp` confirms the
brief's suspicion:

* `ke_reticle_blit_x()` loops `slot = 0..3` over the game's own sprite-object
  table at `0x8019D864 + slot*4` and biases **any** match, and
* it sets the one-shot `scissor_marked` flag on that same match, which
  `ke_sprite_scissor_lrx()` consumes on the `spScissor` call the blit makes a
  few instructions later.

So the widened software clip box already covered all four reticles' blits, and
always did. The measurements below confirm it from the outside: at the widened
rail P2's sprite draws its full 32x32 (96x96 host px), which is only possible
if its box was widened too.

The bug was entirely that only P1's sub-DL was in `hud_relocation`'s
fingerprint table, so nothing subtracted the bias back for P2–P4. **Fix: three
more table rows**, `0x801C8590` / `0x801C86B0` / `0x801C87D0`, with exactly
P1's entry (`Center`, no vertical offset, `aim_biased`).

**Measured — reticles at rest.** BATTLE, `KE_FORCE_PORTS=4`,
`--profile enhanced`. All four slots sit at their mission-start values
(X = ∓20, Y = ±20), so the four sprites form a 2x2. Centroids, host px, from
the colour of each slot (phase 1 §5.2):

| slot | `--profile vanilla` (ground truth) | before | after |
|---|---|---|---|
| P1 green | 579.5 | 576.5 | **576.5** |
| P2 red | 700.6 | **824.0** | **697.7** |
| P3 yellow | 579.5 | **705.5** | **576.5** |
| P4 magenta | 700.3 | **826.3** | **697.3** |

Before: P2–P4 are +123.4 / +126.0 / +126.0 px out. After: all four are
−2.9 ± 0.1 px from vanilla — RT64's `misalignX` sub-pixel correction, the
same residual P1 has had since `hud_relocation` shipped
(`hud-relocation.md` phase 2 §3 measured −3 for the reticle). Nothing else in
the frame moved.

**Measured — P2 at the widened rail.** TEAM, `KE_FORCE_PORTS=2`, P2's reticle
X word `0x8011D4C0` held at 250 from outside the process (the game clamps it
to the `extended_aim` rail, +170):

| | sprite bbox (host px) | drawn | centroid |
|---|---|---|---|
| before | (1228,312)–(1275,407) | **48 x 96** — half of it, sliced by the window's right edge | 1253.3 |
| after | (1099,312)–(1194,407) | **96 x 96**, the full 32x32 N64 sprite | **1146.5** |

Predicted `640 + 3·170 = 1150`, less the misalignment shift. For comparison,
`hud-relocation.md`'s own measurement of **P1** at the same rail is
`(1099,12)–(1194,107)`, centroid 1146.6 — P2 now lands in the same pixel
column as P1 does, which is the whole requirement.

## P3.2 The BATTLE HUD map, measured

Phase 1 §4.2's map is confirmed, with one correction. `KE_DL_DUMP`, 80
consecutive BATTLE gameplay frames, `--profile vanilla`, every `G_TEXRECT`
attributed to the sub-DL executing when it was issued:

| element | team A sub-DL | ul..lr | team B sub-DL | ul..lr |
|---|---|---|---|---|
| health backing | `0x801BCE30` | (16,172)–(80,220) | `0x801BCF50` | (233,172)–(297,220) |
| health jet glyph | `0x801BD070` | (24,180)–(56,212) | `0x801BD190` | (241,180)–(273,212) |
| health number panel | `0x801BD2B0` | (50,179)–(82,203) | `0x801BD3D0` | (267,179)–(299,203) |
| health fill | *pool slot* | (16,172)–(64,220) | *pool slot* `+0x120` | (233,172)–(281,220) |
| health % digits (2) | `0x800F2B50` | (63,183)–(79,196) | `0x800F2BF0` | (280,183)–(296,196) |
| S-BOMB gauge (5x 16x32) | `0x801C25F0` | (78,188)–(158,220) | `0x801C2890` | (156,188)–(236,220) |
| reticles | `0x801C8470 + slot*0x120`, all four, identical to TEAM | | | |

Exactly **16 sub-DLs draw texrects** in a *typical* BATTLE frame, and all
sixteen are in this table — there is no third HUD family to miss. The one thing
this capture window did not contain is the intermittent screen effect: a frame
that also draws a damage flash has one or two more, and those turned out to
matter (P3.6).

**The correction: the health fills are *not* at a fixed address**, in either
team. Phase 1 listed `0x801BE6F0` / `0x801BE810`; this capture measured
`0x801BE270` / `0x801BE390`, and two later runs measured
`0x801BD4F0` / `0x801BD610` and `0x801BFD70` / `0x801BFE90`. They are the same
0x240-byte display-list buffer pool `hud-relocation.md` phase 3 identified in
single player, indexed by the value being displayed — phase 1 simply sampled it
once. What *does* hold for them is the `+0x120` twin rule: **every** observed
pair is (slot, slot + 0x120). So the mirror-twin structure of §4.2 is right and
the specific fill addresses in it are one sample of a ramp.

## P3.3 The BATTLE anchor design

**Each team's cluster is anchored to its own side's window edge, as a unit.**
Team A (dial + jet + panel + digits + fill + gauge) anchors `Left`; team B's
six mirror elements anchor `Right`. Nothing is anchored `Center` except the
reticles, which are `Center` in every mode.

The reason to say "as a unit" rather than to anchor each widget on its own
merits is that a shared anchor is a **rigid translation**: `Left` maps
`window_x = 3x` where untagged is `160 + 3x`, so every team-A element moves by
exactly −160 px, and `Right` maps `window_x = 3x + 320`, so every team-B
element moves by exactly +160 px. Every internal relationship inside a cluster
survives byte-for-byte — including the 3 N64 px by which each gauge's far end
tucks *under* its own dial (team A 78..158 against a dial at 16..80; team B
156..236 against a dial at 233..297). Anchoring the gauges to the centre
instead, which the abutting pair invites, would have kept the gauges still
while the dials flew outward and torn that overlap apart.

This is also why the design is stated as the mirror of single player rather
than as something new: single player has one cluster with a 20 px left margin
and one with a 25 px right margin, and each keeps its margin against the true
window edge. BATTLE has two clusters with a 16 px left margin and a 23 px right
margin, and each keeps its margin against the true window edge.

The consequence for the code is one element with two anchors:

| sub-DL | single player / TEAM | BATTLE |
|---|---|---|
| `0x801C25F0` S-BOMB gauge | `Right` (x 215..295, a right-edge widget) | **`Left`** (x 78..158, part of team A's left cluster) |

That single disagreement is F3. With the single-player anchor a BATTLE gauge
lands at `1280 + (78 − 320)·3 = 554` — left of centre, dragged off its own team
and on top of team B's untouched copy, which is exactly the "both gauges
huddled in the middle" the phase-1 screenshot shows.

### How the redirect pass tells BATTLE from TEAM/single

**By the presence of team B's mirror sub-DLs in the same frame.** Four of the
six new table entries are flagged `battle_marker`: `0x801BCF50`, `0x801BD190`,
`0x801BD3D0`, `0x801C2890`. Each appears in 100 % of dumped BATTLE frames and
in no frame of any other capture ever taken of this game; matching any one of
them sets the frame's `is_battle`. The percent digits `0x800F2BF0` are
deliberately **not** a marker — they come out of the same shared boot-segment
buffer family as `0x800F2B50` and could in principle be a front-end draw.

Because a marker can appear anywhere in the frame relative to the element being
decided, the decision cannot be made in walk order. So **every** match is now
collected during the walk and resolved after it, which is a generalisation of
the deferral `hud_relocation` already had for the shared digit buffer and the
region fills rather than a new mechanism. Each element gets two pre-built
stubs, one per layout, and resolution picks one with a boolean.

The alternative considered and rejected: deciding the gauge's anchor
*geometrically*, from its own texrect x in this frame (215 vs 78 is
unmistakable). It needs no mode concept at all, but it means descending into
fingerprinted elements instead of `SkipCall`ing them, i.e. touching the
walker's hottest path and its region-probe depth accounting, to remove a
distinction the rest of the table wants anyway. Recorded here because it is the
better answer if a *third* layout ever turns up.

Failure mode if detection is ever wrong: a BATTLE frame with no team-B element
in it would draw team A's gauge with the single-player anchor for that one
frame. All four markers are in 100 % of frames, so this needs the game to stop
drawing team B's entire dial and gauge; if it ever happens it is one frame of a
gauge jumping, not a persistent state.

## P3.4 F4 — the region matcher

`hud_regions[]` is now split by layout, because BATTLE's containers are
somewhere else entirely and single player's boxes there are not merely useless
but actively wrong:

| box (N64 px, inclusive) | anchor | layout | what |
|---|---|---|---|
| x 20..90, y 172..220 | `Left` | single / TEAM | health fill |
| x 215..300, y 185..220 | `Right` | single / TEAM | S-BOMB fill |
| x 14..72, y 172..220 | `Left` | BATTLE | health fill, team A |
| x 231..289, y 172..220 | `Right` | BATTLE | health fill, team B |
| x 74..160, y 203..222 | `Left` | BATTLE | S-BOMB fill, team A |
| x 154..240, y 203..222 | `Right` | BATTLE | S-BOMB fill, team B |

The misfire phase 1 recorded — `[hud] S-BOMB fill matched by region at sub-DL
0x801BF7D0` — was **reproduced first-hand** on the pre-fix binary, in a BATTLE
run driven to ~40 % health:

```
[hud] relocation active: 6 element redirects this frame
[hud] S-BOMB fill matched by region at sub-DL 0x801BFE90
```

and it is now fully explained. `0x801BFE90 = 0x801BFD70 + 0x120`, and
`0x801BFD70 = 0x801BCE30 + 21·0x240` — the team-B twin of *health* fill pool
slot 21. Phase 1's `0x801BF7D0 = 0x801BF6B0 + 0x120` is the same shape, one
slot away. **Team B's health fill was matching the S-BOMB box**: in BATTLE
team B's dial sits at x 233..297, and its shorter fill variants (48x32 at
y 188..220, 48x24 at y 196..220) land inside single player's S-BOMB box of
x 215..300, y 185..220. Not a subtle geometric coincidence — the box was simply
describing a part of the screen that means something else in this mode.

Two things keep it from recurring: the BATTLE health boxes claim those fills by
address-free geometry *first* (they are listed first and the match takes the
first fit), and the BATTLE S-BOMB boxes are **19 rows tall**, against a
shortest-ever-observed health fill of 24 rows — so no health fill can fit one
at any value, at any x.

After the fix, the same scenario (BATTLE, 4 ports, driven to 36 % / 23 %
health) logs only:

```
[hud] health fill (team A) matched by region at sub-DL 0x801BD4F0
[hud] health fill (team B) matched by region at sub-DL 0x801BD610
[hud] S-BOMB fill (team A) matched by region at sub-DL 0x801C31F0
```

`0x801BD610 = 0x801BD4F0 + 0x120`, the twin rule again, and `0x801C31F0` is the
same charge-fill address single player uses — the gauge is the same widget in a
different place, which is the whole premise of the region approach.

## P3.5 Measurements

### Redirect counts per frame

| mode | before | after | composition (after) |
|---|---|---|---|
| single player | 7 | **7** | 1 reticle + backing/jet/panel/digits/gauge + 1 health fill |
| TEAM, 2 ports | 7 | **8** | +1 reticle |
| TEAM, 4 ports | 7 | **10** | +3 reticles |
| BATTLE, 4 ports | **6** | **15** | 4 reticles + 5 team A + 5 team B + 2 health fills (+1 more when a gauge has charge) |

A damage-flash frame adds one more on top of those (single player / TEAM) or
**two** in BATTLE, where the flash is two half-frame rects — see P3.6.

Single player is **unchanged at 7**, which is the whole of gate 3 for the
non-BATTLE path: the new rows are addresses single player never pushes.

### BATTLE cluster positions (host px, 1280x720)

Measured off screenshots by colour, on the same game state
(`--profile enhanced` before/after, `--profile vanilla` for the untouched
reference). The percent digits are the cleanest landmark — bright white glyphs
with nothing else their colour in the bottom band:

| | vanilla (4:3 column) | before | after | intended |
|---|---|---|---|---|
| team A digits, x | 349..387 | 196..229 | **196..229** | `Left`: −160 px + 2 px misalign = −158 |
| team B digits, x | 1000..1044 | **1000..1042** (untouched) | **1156..1198** | `Right`: +160 px − 2 px = +158 |
| digits, y | 552..578 | A 612..638, **B 552..578** | **both 612..638** | +20 N64 px = +60 |

So before the fix team A's half of the HUD was 158 px and 60 px away from team
B's half; after, the two halves are mirror images at the two window corners.

Cluster extents, against the geometric prediction from the map in P3.2
(`Left`: `3x`; `Right`: `3x + 320`):

| cluster | predicted after | measured (chrome extents) |
|---|---|---|
| team A dial, x | 48..240 | right edge **240** |
| team A gauge, x | 234..474 | chrome spans **328..441** |
| team B gauge, x | 788..1028 | chrome spans **886..981** |
| team B dial, x | 1019..1211 | right edge **1209** |

and in the *before* screenshot of the same scene the two gauges instead measure
as one blob of chrome from **646..825**, straddling the centre, with team B's
dial still at **971..1053** — F2 and F3 in one picture.

### Regressions

* **Single player, `--profile enhanced`, health held at 11 %** (poke of
  `0x8011D464`, so the fill is a late, small pool variant): fill pixels occupy
  window **x 157..189** in the bottom band, inside the relocated dial, and
  **0** fill pixels appear anywhere in x 210..400 — the 4:3-column position the
  dial used to occupy. `[hud] health fill matched by region at sub-DL
  0x801BD4F0`, 7 redirects. The phase-3 fills still ride.
* **TEAM, `--profile enhanced`**: the health cluster, gauge and fill are at the
  identical positions single player measures, and P1 + P2's reticles are both
  centre-registered (576.5 / 696.5 against a vanilla 579.5 / 700.6).
* **`--profile vanilla`, BATTLE, driven to gameplay**: **0**
  `[hud]` / `[hfr]` / `[aim]` / `[gfx]` lines, digits at 349..387 and
  1000..1044 — i.e. exactly the original 4:3-column positions. Same for
  single-player vanilla.
* **Front end**: a 75 s `--profile enhanced` boot with no input at all prints
  **0** `[hud]` / `[hfr]` / `[aim]` lines. The in-mission gate on the shared
  digit buffer and on every region match is intact.
* **`scripts/smoke_test.sh`**: **PASS** — alive, 34215 distinct colours,
  99.4 % non-zero audio.
* Build clean.

## P3.6 F5 — BATTLE's damage flash is two half-frame rects

Found *during* phase 3, not in phase 1's list: a BATTLE screenshot taken
mid-damage-flash under `--profile enhanced` shows **three unequal vertical
bands** of red instead of a tint. Band edges, measured off the screenshot by
column mean (1280x720, R channel, rows 100..500):

```
x   0.. 640   R≈110      640.. 805   R≈155      805..1120   R≈109      1120..1280  R≈42
```

### What the game draws

`KE_DL_DUMP`, BATTLE, 400 gameplay frames. The flash is **two sub-DLs**, each
drawing one half of the frame:

```
272 1843 @10FDA8 DL push addr=801B6CB0 phys=1B6CB0
272 1862 @1B6D40 TEXRECT ul=0.00,0.00   lr=160.00,239.00 w=160.00 h=239.00 tile=0 st=0,0 d=102,34
273 2012 @10BEA0 DL push addr=801B6DD0 phys=1B6DD0
273 2031 @1B6E60 TEXRECT ul=160.00,0.00 lr=319.00,239.00 w=159.00 h=239.00 tile=0 st=0,0 d=102,34
```

against single player's one full-frame rect from the same address:

```
25 3958 @1B6D48 TEXRECT ul=0.00,0.00 lr=319.00,239.00 w=319.00 h=239.00 tile=0 st=0,0 d=51,34
```

`0x801B6DD0 = 0x801B6CB0 + 0x120` — the mirror-twin rule again. Both halves use
the *same* texture (`0x801A0C90`) at `dsdx=102`, i.e. each half contains a
complete copy of the 16x12 flash texture rather than half of one stretched
across the screen: they are two independent effects, not one rect split for a
hardware limit. The per-frame pattern says the same thing — over 400 frames,
5 pushes of each, on frames `272 CB0 / 273 DD0 / 277 CB0 / 278 DD0 / 283 both /
289 both / 294 DD0 / 295 CB0`. **Each half is one team's damage indicator, drawn
over that team's own side of the screen** (team A's HUD is bottom-left, team B's
bottom-right).

`0x801B6DD0` is BATTLE-only: **0** pushes across the title (9 800 dumped
lines), the mission intro (284 059), the single-player mission (284 939 and
73 269) and a **TEAM** mission (797 376).

**TEAM uses the single-player flash**, settled by a dedicated capture
(`KE_FORCE_PORTS=2`, 2 reticles pushed, no team-B HUD element anywhere): 16
pushes of `0x801B6CB0`, every one of them the 319x239 `d=51,34` rect, and zero
of `0x801B6DD0`. So `HudMode::Normal` keeps the full-frame `Stretch` and only
BATTLE needs anything new.

### Verdict: ours, but the half-screen shape is authentic

`--profile vanilla`, BATTLE, same stage, flash frames located by per-frame mean
in a 45 s 30 fps X11 capture. The 4:3 column is x 160..1120; column means, R
channel:

| frame | x 200..630 | x 650..1100 | reading |
|---|---|---|---|
| 437 | 126..141 | 95 → 41 | **left half only** |
| 905 | 92..122 | 160..164 | **right half only** |
| 909 | 155..167 | 124 → 64 | left half only |
| 444, 450, 1287 | ~120..150 | ~120..150 | both halves, uniform |

and the boundary between the halves is at window **x 639..641** in every
one — the centre of the 4:3 column, i.e. N64 x 160, exactly where the two rects
meet. **So a half-screen flash is the game's own behaviour and must be
preserved.** What is ours is where the halves land:

* `0x801B6CB0` was in the fingerprint table as the full-frame `Stretch`, so its
  *half*-width rect was stretched across the whole window: predicted
  `ulx (0−2)·3 = −6`, `lrx = 1280 + (160−317)·3 = 809`, measured band edge 805.
* `0x801B6DD0` was not in the table at all, so it stayed in the 4:3 column at
  `160 + 160·3 = 640 .. 160 + 319·3 = 1117`, measured 1120.

Which is the observed banding exactly: a double-tinted overlap at 640..805, a
single tint either side of it, and nothing at all past 1120.

### The fix: two half-window anchors

Two new `HudAnchor` values, built from the same origin/offset rule as the rest
of the table (`offset = −(the N64 x of the chosen origin)`), so both are still
the exact identity when RT64's aspect ratio is `Original`:

| anchor | lorigin / ulxOff | rorigin / lrxOff | maps |
|---|---|---|---|
| `StretchLeftHalf` | `LEFT` / −2 px | `CENTER` / −160 px | x 0..160 → window left edge .. centre |
| `StretchRightHalf` | `CENTER` / −160 px | `RIGHT` / −317 px | x 160..319 → window centre .. right edge |

The two inner edges use the *same* origin and the *same* offset, so the halves
abut exactly instead of leaving a seam. The outer edges reuse the full-frame
`Stretch`'s ±2 px of deliberate overdraw, for the reason `hud-relocation.md` §4
gives. Table rows:

| sub-DL | single player / TEAM | BATTLE |
|---|---|---|
| `0x801B6CB0` damage flash | `Stretch` (319x239, the whole frame) | **`StretchLeftHalf`** |
| `0x801B6DD0` damage flash | `StretchRightHalf` (never drawn there) | **`StretchRightHalf`** |

`0x801B6DD0` is deliberately **not** a `battle_marker` even though it passes
that test (BATTLE and nowhere else): a marker has to be in *every* BATTLE frame
and this one is in ~2 % of them. The layout is already decided by team B's HUD
twins, which are in 100 %.

### After

Same harness, `--profile enhanced`, flash frames differenced against their
immediate non-flash neighbours so scene content cancels. Per-column R delta:

| frame | what | delta profile |
|---|---|---|
| 374 | left half only | `+76..+82` over x 1..636, `≈0` from 637 on |
| 380 | right half only | `≈0` to x 636, `+72..+89` over 637..1275 |
| 393 | both halves | `+60..+88`, mean **+80**, over x 2..1275 — **no band structure at all** |

The seam sits at 636/637 rather than 640 — the −3.5 px RT64 `misalignX`
residual every relocated element carries (`hud-relocation.md` phase 2 §3
measured −3 for the reticle) — and is invisible, being the join between two
identical tints with neither a gap nor an overlap column.

The 1 px at the extreme left and 2 px at the extreme right that the flash does
not reach are **pre-existing and unchanged**: the untouched full-frame
`Stretch` flash measures identically (TEAM, pre-fix binary, frame 768:
`+76..+97` over x 1..1275, `0` at x 0 and at 1276+).

### Regressions for F5 specifically

All on the fixed binary, all `--profile enhanced`:

| run | redirects | flash sub-DLs pushed | region matches |
|---|---|---|---|
| single player (1 port) | **7** (unchanged) | `0x801B6CB0` x14, **no** `0x801B6DD0` | `health fill … 0x801BD4F0` |
| TEAM, 2 ports | **8** (unchanged) | `0x801B6CB0` x16, **no** `0x801B6DD0` | `health fill … 0x801BD4F0` |
| BATTLE, 4 ports | **15** (unchanged) | `0x801B6CB0` x5 + `0x801B6DD0` x5 | team A + team B fills |

The TEAM full-frame flash renders identically on the fixed binary
(`+77..+98` over x 1..1275) to the pre-fix one, and `scripts/smoke_test.sh`
passes (34215 distinct colours, 99.3 % non-zero audio).

**BATTLE with 4 ports still draws exactly two halves** — not four — which is
the check that matters for the "one per team, not one per player" reading:
5 pushes of each address in 900 frames, all four reticles present, and
`0x801B6DD0`'s rect is the same `(160,0)–(319,239)` it is at 2 ports.

## P3.7 What is still open

1. **Owner hands-on**, as for every enhancement at this stage — and here
   specifically whether the per-team edge anchoring reads better than leaving
   the gauge pair centred. The alternative is one word in the table
   (`HudAnchor::Center` for both gauges' BATTLE anchor) and is measured
   above only as a prediction.
2. **BATTLE's S-BOMB charge fill for team B was never seen.** Team A's charged
   during the run (`0x801C31F0`, correctly matched and relocated); team B's
   never did, so its box is designed from team A's geometry mirrored, not
   measured. If it is ever stranded, the fix is the box, and the
   `[hud] S-BOMB fill (team B) matched by region` line is what to look for.
3. **Only stage 1, only normal gameplay.** `hud-relocation.md` phase 1's open
   question **O2** is untouched and now has a multiplayer half: the BATTLE
   round-end / winner screens have never been dumped, and phase 1 §9 risk 5
   still applies. The damage flash (P3.6) is subject to the same limit: two
   half-frame rects is what stage-1 BATTLE draws at 2 and at 4 ports, and if
   some other state ever drew a *third* screen-effect rect from the same
   `+0x120` pool it would be unlisted and would stay in the 4:3 column —
   the F5 symptom again, and the thing to look for is a flash frame whose tint
   has an edge in it.
4. **The BATTLE detection is per frame and fail-soft**, see P3.3. Nothing
   observed suggests a BATTLE frame without a team-B element, but it has not
   been proven impossible either.
5. **The pending-match array is 24 deep** (a BATTLE frame uses 15, or 17 on the
   ~2 % of frames that also draw both damage-flash halves). An
   overflowing frame drops the extra redirects rather than misplacing
   anything, and nothing observed comes near it.
