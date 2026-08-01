# Multiplayer — phase 1: feasibility (2026-08-01)

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
values, in the same order, for every input. Confirmed by inspection and by
`scripts/smoke_test.sh` **PASS** with the variable unset (alive, 34215 distinct
colours, 99.3 % non-zero audio) plus a boot with no `[input]` line in the log.

It deliberately does **not** route input. `get_input()` still early-returns for
`controller_num != 0`, so ports 1..3 read connected-but-neutral. That is enough
for the game to offer *and enter* a multiplayer game with idle players, which
is exactly what a feasibility probe wants: it isolates "does the multiplayer
code path work" from "is our input plumbing right".

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
