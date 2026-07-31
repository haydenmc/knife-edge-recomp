# Enhancement flags

## Policy

This is a recompilation, not a remaster: the default experience should be
indistinguishable from the original N64 hardware. But a static recompile also
makes things possible that the console never allowed (uncapped input
sampling, alternate renderer behavior, and so on), and some of those are
worth offering.

The rule this project follows: **every deviation from the original game's
behavior is a runtime-toggleable option.** Since 2026-07-30 (owner
decision) the **default profile is `enhanced`** — the out-of-box experience
is the curated quality-of-life set — but every enhancement remains
individually toggleable and vanilla remains one `--profile vanilla` away.
Concretely:

- "Vanilla" (every enhancement off) is always available and is the
  **regression baseline** — the configuration every bug report and timing
  measurement in `analysis/docs/` assumes unless stated otherwise. (The
  smoke test now exercises the enhanced default, deliberately: it should
  test what players actually run.)
- An enhancement is never baked in unconditionally. If a change to behavior
  can't be made optional (e.g. it's a straight bugfix for something that was
  never intentional, like `analysis/docs/timing-and-mission-debug.md`'s
  wedge fixes), it isn't an "enhancement" in this sense — it's a
  correctness fix and ships unconditionally.
- Diagnostics (`KE_AUDIO_DUMP`, `KE_PERF`) are not enhancements: they don't
  change what the player experiences, only what gets written to a file or
  stderr. They stay as environment variables, not config-file entries.

See `src/main/config.h` / `src/main/config.cpp` for the schema and loader,
and the "Configuration" section of the top-level `README.md` for the
player-facing summary.

## Mechanism menu

Different enhancements suit different implementation layers. When adding a
new one, pick from (roughly in order of how deep it reaches):

**(a) N64Recomp `[patches]` hooks / instruction patches, via
`analysis/gen_syms.py`.** For changes that need to intercept or replace
recompiled game code itself — the same mechanism `RCP_PACING_HOOKS` and
`EXTRA_SPIN_YIELD_HOOKS` in `analysis/gen_syms.py` already use to inject C
before a given VRAM address or overwrite an instruction word pre-recompile
(see `analysis/docs/n64recomp-formats.md`'s `[[patches.hook]]` /
`[[patches.instruction]]` format). Good for anything that has to observe or
change what the game's own logic does. The hook site should read the
resolved flag once (see `src/main/rcp_timing.cpp`'s
`kerecomp::set_rcp_frame_ms_tuning` for the pattern: a value set from
`main()` before the runtime starts, read by an atomic in the hook's
translation unit) rather than re-parsing config in generated code.

**(b) Linker-override patch mode.** N64Recomp also supports replacing whole
recompiled functions with hand-written C (see
`analysis/docs/n64recomp-formats.md`). Good for a behavior change too
large or structurally different to express as a hook/instruction patch.
Heavier-weight than (a); prefer (a) unless a hook genuinely can't express
the change.

**(c) RT64 renderer options.** For presentation-layer changes (resolution,
filtering, aspect ratio, HUD scaling) that RT64 already exposes knobs for —
wire the resolved config flag into `src/main/rt64_render_context.cpp`'s
renderer setup instead of touching game code at all.

**(d) Runtime shim.** For changes entirely on the host side of the
HLE boundary — input handling, audio routing, pacing/timing models — same
layer as `src/main/main.cpp` and `src/main/rcp_timing.cpp`. This is where
`input_latching` (below) lives: it only touches how the SDL-backed
`ultramodern::input::callbacks_t` implementation samples the keyboard, never
recompiled game code.

**Never hand-edit recompiler output.** Everything under `generated/` (or
whatever `KE_GENERATED_DIR` points at) is produced mechanically by
N64Recomp/RSPRecomp from `config/*.toml` and the ROM, and is regenerated on
every ROM build (see "Regenerating from a ROM" in the top-level
`README.md`) — it is never committed and any hand edit to it is silently
discarded the next time someone runs `make -C analysis` +
`N64Recomp config/knife_edge.us.toml`. If an enhancement needs different
recompiled-code behavior, it goes through mechanism (a) or (b) above so the
change lives in `config/*.toml` (or `analysis/gen_syms.py`, which writes
`config/*.toml`) — reviewable, versioned, and reproduced by
`make -C analysis`. The `regen-verify` CI job
(`.github/workflows/build.yml`, `workflow_dispatch`-gated, see the
top-level README's "Regenerating from a ROM" section) exists specifically to
catch drift here: it reruns the pipeline against a ROM and fails on any
`git diff -- config`, so a hand-edit to generated output that isn't backed
by a `config/` change would eventually surface there even though it can't
run on every push (no ROM on GitHub-hosted CI).

## Current flags

| flag | what | why | mechanism | default |
|---|---|---|---|---|
| `input_latching` | Latches a key press between controller reads: any button pressed since the last read is OR'd into the buttons returned on the next read, then cleared. Capture is **event-driven** — presses are latched from SDL `KEYDOWN` events (which SDL queues and never drops), not from polled keyboard state, so a tap that begins and ends between two polls is still caught. Polling could only ever sample, and would miss exactly the short taps this exists to rescue. | The game samples the controller once per game frame (~15 Hz — see `analysis/docs/timing-and-mission-debug.md` §3.1), which is faithful to hardware but means a tap shorter than ~67 ms (including a scripted `xdotool key` tap, or a fast human press) can land entirely between two reads and be dropped. Latching makes short presses reliable without changing anything about held-button behavior. | (d) runtime shim (`src/main/main.cpp`'s `get_input`/`update_gfx`) | off |
| `high_resolution` | Renders the 3D scene at window resolution instead of the original 320x240, via RT64's window-integer-scale resolution mode (`ultramodern::renderer::Resolution::Auto`) rather than its manual 1x mode. Off leaves `res_option` at `Original` with `ds_option` clamped to 1x, which is bit-identical to the pre-existing (unset) `GraphicsConfig` default. | 320x240 upscaled by integer factors to fill a modern window is blocky compared to native-resolution rendering RT64 already supports; this is the same tradeoff every other RT64-based recompilation project exposes as an option. | (c) RT64 renderer options (`src/main/main.cpp` builds the `GraphicsConfig`; `src/main/rt64_render_context.cpp`'s `set_application_user_config` already translated it) | off |
| `widescreen` | Sets `ar_option = Expand`, which `set_application_user_config` (`src/main/rt64_render_context.cpp`) translates to RT64's `aspectRatio = Expand` — the 3D projection widens to fill the window's actual aspect ratio instead of staying 4:3. (`extAspectRatio` is a different knob, driven by `hr_option`.) `hr_option` stays `Original` regardless, so the HUD/2D elements stay pinned to the centered 4:3 region rather than stretching or re-laying-out. **Caveat:** the game's own view-frustum culling is tuned for a 4:3 frustum, so objects near the newly-widened left/right edges may pop in/out of view there — this hasn't been checked hands-on against real hardware footage and is flagged for that verification. | The window is created at 1280x720 (`src/main/main.cpp`); off (default), that pillarboxes the game's native 4:3 output like original hardware. | (c) RT64 renderer options (`src/main/main.cpp` builds the `GraphicsConfig`; `set_application_user_config` already translated it) | off |
| `full_height` | An entry hook (`analysis/gen_syms.py`) on `func_800C3044`, the game's lo-res mode setter, rewrites the mission overlay's `(320,200)` mode request to `(320,240)` via `ke_view_height()` (`src/main/full_height.cpp`) when the flag is on. The 200-line letterbox is only an RDP scissor derived from the height this call stores — the viewport (`Vp` at `0x8016AEC0`, 320x240) and projection (30° FOV, 4:3, `gSPClipRatio(FRUSTRATIO_2)`) are already full-frame, so this is an uncrop of already-rendered scene (visible vertical FOV 25.17°→30°), not a stretch. See `analysis/docs/letterbox-full-height.md` for the full RE evidence. | Missions letterbox to 200 lines by design (confirmed on real hardware); on a modern display those bands are dead space. | (a) N64Recomp hook via `gen_syms.py` (`ke_view_height` in `src/main/full_height.cpp`) | off |
| `high_framerate` | Renders at the display's refresh rate via RT64 frame interpolation while game logic keeps stepping at its original paced rate (`src/main/rcp_timing.cpp` untouched). RT64 auto-interpolates transforms between consecutive game frames (`G_EX_ID_AUTO` transform matching; vertex/texcoord interpolation off by default) once it is told two things: `rr_option = Display` (`src/main/main.cpp`, translated to RT64's `refreshRate` by `set_application_user_config`), and the game's *original* logic rate. The second part is the reason this is the first enhancement needing two mechanisms: RT64's own VI-cadence auto-detection (`VIHistory::logicalRateFromFactors`) needs a consistent 60/N pattern and this game's paced rate is a continuous ~27 fps that straddles 2-3 VIs per frame, so detection returns 0 and interpolation silently never engages. We measure the game's own cadence instead — an EMA over consecutive `ke_gfx_task_begin()` timestamps (`src/main/rcp_timing.cpp`, `kerecomp::measured_game_frame_interval_ms()`) — and declare it per display list via RT64's extended-GBI `gEXSetRefreshRate`, injected as a 4-command prologue in scratch RDRAM by `RT64Context::send_dl` (`src/main/rt64_render_context.cpp`). Because the declared rate is a live measurement rather than a constant, cutscenes (self-limited to ~15 fps by the game's own busy-wait) and gameplay (~27 fps) both interpolate against their own true rate. Full design/verification record: `analysis/docs/high-framerate.md`. **Known risk:** RT64's transform matching is heuristic — HUD elements or respawning/teleporting objects may show warping/smearing artifacts during the interpolated in-between frames; per-object `gEXMatrixGroup` tagging is the documented escalation path if the owner sees this hands-on. | Presenting one N64 frame per RT64-rendered frame (vanilla, off) means motion is only as smooth as the game's own ~24-27 fps logic rate; interpolation lets the display run at its native rate while logic pace (and therefore gameplay feel/timing) stays exactly as before. | (c) RT64 renderer options (`rr_option`) **and** (d) runtime shim (the measured-rate EMA and the prologue injection) | off |

Notes on `full_height`: unlike `widescreen`, there is **no pop-in risk** — the game's 30°/4:3 frustum plus `gSPClipRatio(FRUSTRATIO_2)` already cover all 240 rows, so nothing culled for a 200-line view needs to reappear. In the `enhanced` profile's curated set (promoted after the owner's hands-on check confirmed it works as intended). It reveals roughly 20% more scene vertically, which is an inherent gameplay effect (more of the world is visible), not a bug. In-mission cutscenes lose their letterbox bars too via the same mechanism — also inherent, since cutscenes reuse the mission's rendering path.

Notes on `high_framerate`: in the `enhanced` profile's curated set, like the other three, but **pending the owner's hands-on hardware verification** (same status widescreen/high_resolution had before their own hands-on checks) — headless verification (build + the `[hfr] declaring` log line + an identical measured game-fps with the flag on vs off) is done, but only a human can judge whether interpolated motion looks right and whether the heuristic transform-matching risk above is visible in practice.

Diagnostics, for completeness (not enhancements — see "Policy" above, both
stay as env vars rather than config-file entries):

| var | what |
|---|---|
| `KE_AUDIO_DUMP` | Path to write raw PCM audio output to, for offline inspection (`scripts/smoke_test.sh` uses it). |
| `KE_PERF` | Turns on the per-second VI-rate / game-frame-rate counters in `src/main/support.cpp`, used throughout `analysis/docs/timing-and-mission-debug.md` to measure pacing. |

## Candidate enhancements (not implemented)

Ideas that have been analyzed but deliberately not built yet. Recorded so the
reasoning is not re-derived.

| Candidate | Analysis | Mechanism | Notes |
|---|---|---|---|
| Workload-proportional RCP timing | The RCP frame budget is a single constant (`default_frame_ms` in `src/main/rcp_timing.cpp`, currently 36.5 ms). On real hardware, RCP frame time rises with scene complexity — the owner's footage shows the original speeding up and slowing down through a stage — so a constant matches the typical case but cannot reproduce that variation. Scaling the modelled budget with display-list size (command/triangle count seen in `send_dl`) would track the real behaviour more closely. | (d) runtime shim (`rcp_timing.cpp` + `rt64_render_context.cpp`) | This is a *fidelity* improvement, not an enhancement, so it would be a tuning knob rather than a profile flag — but it changes pacing, so it needs the same care as the original pacing work (see the wedge in `timing-and-mission-debug.md` §5). |
| High-score persistence | The game's only save-adjacent symbol is `osPfsIsPlug` (a Controller Pak probe), and we register `SaveType::None` with `get_connected_device_info` reporting `Pak::None`. So the game sees no pak and keeps scores in RAM only — which is *faithful* to a console with no pak inserted, i.e. vanilla-correct. librecomp already HLEs the Pfs/Controller Pak API (`osPfsAllocateFile` and friends are in its reimplemented set), so wiring a virtual pak is mostly reporting the device and choosing where its data file lives (alongside the rest of `ke_recomp_data`). | (d) runtime shim | Presenting a pak the player did not have is technically an enhancement and belongs behind a flag — though it is a strong candidate for the `enhanced` profile's default set, since persistent high scores are about the least controversial modernization available. Deferred by project decision. |

## Config file

Schema, precedence (CLI > env > config file > built-in defaults), and
missing/malformed-file handling are documented in `src/main/config.h`. Short
version: `<app folder>/config.toml`, `[profile] active = "vanilla" |
"enhanced" | "custom"`, `[enhancements]` (consulted only when
`profile.active = "custom"`), `[tuning]` for fidelity knobs like
`rcp_frame_ms` that are not enhancements. `--profile <name>` and
`--config <path>` are the only CLI flags; `KE_RCP_FRAME_MS` is the only env
var that feeds into this system (it maps onto `tuning.rcp_frame_ms` and
wins over the file, preserving its pre-existing "0 disables pacing"
behavior — see `src/main/rcp_timing.cpp`).
