# Enhancement flags

## Policy

This is a recompilation, not a remaster: the default experience should be
indistinguishable from the original N64 hardware. But a static recompile also
makes things possible that the console never allowed (uncapped input
sampling, alternate renderer behavior, and so on), and some of those are
worth offering.

The rule this project follows: **every deviation from the original game's
behavior is a runtime-toggleable option, off by default.** Concretely:

- "Vanilla" (every enhancement off) is always available and is the
  regression baseline — the configuration every bug report, smoke test, and
  timing measurement in `analysis/docs/` assumes unless stated otherwise.
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
