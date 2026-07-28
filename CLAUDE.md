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

Enhancement work has started. Shipped, in the `enhanced` profile, verified
headless: `high_resolution` (render 3D at window resolution via RT64) and
`widescreen` (expand FOV to window aspect). Owner verified both on the host
GPU, including no widescreen edge pop-in. Also shipped: `full_height`
(removes the in-mission 320×200 letterbox — an uncrop; see
`analysis/docs/letterbox-full-height.md` for the RE), **not** in `enhanced`
yet pending the owner's hands-on check (results screens, later stages,
cutscene framing). Known vanilla-only cosmetic issue found during that RE:
RT64 renders the letterbox bands in the scene fill color instead of black
(scissor not honored on a fill rect) — candidate upstream report, doc §4.
Agreed order for the rest: gamepad support → mouse aim → Flatpak → high
framerate. Rationale: gamepad before mouse aim (both touch `get_input`'s
axis path; gamepad is the simpler pattern-setter), high framerate last
because it is the deepest timing-sensitive cut, Flatpak once the config
surface stops churning. Mouse aim caveat: reticle updates at game rate
(~15 Hz pad sampling) regardless of input smoothness — fully smooth aim is
coupled to the high-framerate work.

RCP frame budget: **36.5 ms** (~24.6 measured game fps), tuned by the owner
against real N64 gameplay footage. This replaced an earlier 59.733 ms figure
taken from the game's own cutscene limiter — that paced cutscenes correctly but
had no reason to match gameplay. Lowering it does not disturb cutscenes: while
our budget stays under the game's own limiter, cutscenes are paced by that
limiter. Retune live with `KE_RCP_FRAME_MS=<ms>` or persistently via
`tuning.rcp_frame_ms`; **`0` disables pacing entirely** rather than meaning
"default". Real hardware frame time rises with scene complexity, so a single
constant matches the typical case only — a workload-proportional model is a
candidate enhancement.

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
4. Enhancements not yet started, in agreed order (see Status): gamepad support,
   mouse aim, Flatpak packaging, high framerate. High-score persistence
   deferred (see candidates).
5. Owner hands-on GPU check of `full_height` (results screens, stages beyond
   1, cutscene framing) — then promote it into the `enhanced` set (one line
   in `config.cpp` + docs).
6. RT64 letterbox-band color bug (vanilla-only cosmetic; see
   `letterbox-full-height.md` §4) — decide whether to report upstream.
