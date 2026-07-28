# Knife Edge Recompiled — working notes for Claude

Orientation for a session picking this project up cold. Findings live in
`analysis/docs/`; this file covers **how we work** and **where things stand**.

## What this is

A static-recompilation PC port of *Knife Edge – Nose Gunner* (N64, Kemco 1998)
built on N64Recomp + N64ModernRuntime + RT64. The game's MIPS code is translated
to C ahead of time (no emulation); libultra/OS calls are HLE'd by librecomp;
graphics go through RT64. **No decompilation of this game exists**, so the novel
piece is `analysis/` — a Python pipeline that derives the symbol metadata
N64Recomp needs directly from the ROM.

## Status (2026-07-28)

Playable and stable. Boots → title → attract → menus → gameplay through at
least stage 4 including alternate paths, with correct music/SFX, correct speed,
working results/overview screens, and no known defects.

Verified by the project owner on real hardware GPU: stages 1–3 clean, stage 4
with an alternate path, in-mission music and SFX correct, results-screen timeout
working repeatedly, high-score screen appears.

Not yet verified: full campaign completion; `--profile enhanced` input latching
by hand; high-score persistence across runs (analyzed — almost certainly absent
and *faithful*, see `analysis/docs/enhancements.md` candidates table).

Still inferred, not measured: the RCP frame budget (59.733 ms) comes from the
game's own cutscene limiter, cross-checked against the owner's "~4x too fast"
observation. `KE_RCP_FRAME_MS` retunes it live if it ever feels wrong.

## Build / run / test

- Build with a ROM: `cmake -B build -G Ninja -DKE_ROM=<path to rom>` then
  `cmake --build build`. Configure-time it normalizes the ROM, runs the analysis
  pipeline, and invokes N64Recomp + RSPRecomp.
- Without a ROM the build compiles `src/stub_game/` — links and runs, no game
  code. This is what CI builds.
- Run: `./build/KnifeEdgeRecompiled --rom <path>`; afterwards the ROM is cached
  so `--rom` is optional. Controls table in README.
- `./scripts/smoke_test.sh` — headless boot check (alive + real video + non-silent
  audio). Requires a ROM; CI uses a no-ROM well-formedness check instead.
- Live diagnosis of a running/hung game: `scripts/capture_wedge_state.sh` and
  `scripts/capture_voice_state.sh` (they locate the process and game RAM
  themselves). Env: `KE_PERF=1` (VI/s + frames/s), `KE_AUDIO_DUMP=<path>` (PCM).
- Every binary prints its git commit at startup — always ask for that line in a
  bug report.

## Repo policy

Committed: the analysis pipeline and its metadata (`analysis/`, `config/*.toml`),
the runtime shim (`src/`), docs, scripts.

**Never committed**: the ROM, any asset/data dump, screenshots or audio captures
(`*.png`/`*.wav`/`*.pcm` are gitignored), and **recompiler output** — it is a
build artifact, regenerated per build. `config/knife_edge.us.syms.toml` is the
reviewable source of truth; generated C is not.

Consequence: normal CI needs no ROM and no secrets (stub build, works for fork
PRs). Only the manual-dispatch `release` job touches a ROM, and it asserts the
binary embeds no ROM data before publishing.

## Where the knowledge lives

| Doc | Contents |
|---|---|
| `analysis/out/segment_map.md` | ROM→RAM load map: 69 fixed-address loads, no relocs, no TLB. Open questions in §d. |
| `analysis/docs/n64recomp-formats.md` | Exact N64Recomp/RSPRecomp input formats + the librecomp runtime contract. libultra HLE is automatic **by symbol name**. |
| `analysis/docs/pipeline-spec.md` / `pipeline-report.md` | How symbols are derived from the ROM, and the results. |
| `analysis/docs/boot-debug.md` | Getting from first recompile to the title screen. |
| `analysis/docs/timing-and-mission-debug.md` | The deepest doc. Frame pacing, the mission-start and results-screen wedges, overlay tail survival (§4.2), forced-mission-completion recipe, headless input recipe (§3.1). |
| `analysis/docs/audio.md` | Locating/recompiling the audio microcode; the SDL sink. |
| `analysis/docs/overlay-tracking.md` | Why overlay DMA is hooked and how. |
| `analysis/docs/enhancements.md` | **Read before adding any feature.** Policy, mechanism menu, current flags, deferred candidates. |
| `analysis/docs/build-notes.md` | CMake/dependency integration details. |

Git history is deliberately verbose — commit messages carry root causes and
rejected alternatives. `git log` is a real source.

## Working practices

**Delegation.** The main session orchestrates and does architecture, RE judgment,
and design decisions. Subagents do the rest, chosen by tier:
- **Opus** — hard-but-scoped work where a wrong conclusion is *quiet*: root-cause
  debugging, disassembly judgment, heuristics.
- **Sonnet** — well-specified implementation from a written spec.
- **Haiku** — bulk chores, log triage.

Two rules that decide the tier:
1. *Complexity lives in the brief or in the agent, and it's cheapest in the brief.*
   Making the design decisions up front demotes a task a full tier.
2. *Pick by risk shape, not just difficulty.* Loud failures (build breaks, test
   fails, wrong output) are cheap to catch in review → lower tier is fine. Reserve
   Opus for work whose errors are silent and poison later work.

**Verify subagent claims before committing.** Every fix in this project was
re-run independently by the main session before landing. This has caught real
problems — a CI assertion that passed locally but would fail on a runner, and a
latching implementation that was probabilistic where it should be deterministic.
Treat an agent's verification as a claim, not evidence.

**Scripts over tokens.** Bulk analysis is deterministic Python writing to files;
build logs get grepped, not pasted. The model should never read a disassembly
listing wholesale.

**Never hand-edit recompiler output.** It is regenerated on every ROM build.
Fixes belong in `analysis/` (pipeline), `src/` (runtime shim), or N64Recomp
patches/hooks emitted by `gen_syms.py`. See the mechanism menu in
`enhancements.md`.

**Enhancements go behind flags.** Vanilla is the default and the regression
baseline; every deviation from original behavior is runtime-toggleable. Fidelity
knobs (e.g. `tuning.rcp_frame_ms`) are *not* enhancements.

## Hard-won gotchas

- **Sign-extend N64 addresses.** `recomp.h`'s `MEM_*` macros index RDRAM as
  `addr - 0xFFFFFFFF80000000`; a bare `0x800C2400` reads ~4 GB out of bounds.
- **Un-yielded busy-waits wedge the cooperative scheduler.** The game polls flags
  that only advance when the runtime drains its message queue. `find_spin_loops()`
  detects them; `EXTRA_SPIN_YIELD_HOOKS` is the escape hatch when a general rule
  would over-match (it will: memcpy, table scans).
- **A screen waiting on input is indistinguishable from a hang** when input is
  being dropped. Cost a whole investigation once — an IME was swallowing keys.
  The startup line reporting text-input state exists to disambiguate this.
- **The game samples the pad once per game frame (~15 Hz)**, so taps under ~67 ms
  are invisible. Faithful. Scripted input must *hold* keys (~0.4 s).
- **Timing changes have long-range consequences.** The frame-pacing fix silently
  created a stall that only detonated at mission end, minutes later.
- **Prefer fixing on our side over patching `deps/`.** Both times it looked like a
  dependency patch was needed, a clean seam existed in our own code.

## Open items

1. Campaign completion (owner, when time allows) — the ending is never-run code.
2. Hands-on check of `--profile enhanced` input latching; the headless tap test is
   confounded by the title screen auto-advancing and cannot decide it.
3. `segment_map.md` §d Q1 — un-zeroed BSS tails on overlay reload. Ruled out as
   the cause of the one failure we caught; still theoretically open.
4. Enhancements not yet started: widescreen, high framerate, mouse aim, gamepad
   support, Flatpak packaging. High-score persistence deferred (see candidates).
