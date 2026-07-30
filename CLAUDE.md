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
GPU, including no widescreen edge pop-in. Also shipped and owner-verified hands-on: `full_height` (removes the
in-mission 320×200 letterbox — an uncrop; see
`analysis/docs/letterbox-full-height.md` for the RE), promoted into
`enhanced`. Known vanilla-only cosmetic issue found during that RE:
RT64 renders the letterbox bands in the scene fill color instead of black
(scissor not honored on a fill rect) — candidate upstream report, doc §4.
Gamepad support shipped (2026-07-29) — deliberately **not** an enhancement
flag: host input-device support like the keyboard mapping, always on, no
config keys. SDL_GameController with hotplug, all pads act as controller 1,
0.15 radial deadzone, either trigger → Z, right stick → C. Verified headless
(build + smoke test — no pad hardware reaches the container) and owner
hands-on (2026-07-29, Xbox Elite 2 via xone): connect line, stick aim,
trigger fire, right-stick C-buttons, A/B/Start all correct. Hotplug
mid-game is the one unexercised path. Stick-response knobs shipped
(3d355d7): `[input]` config section — `stick_deadzone`/`stick_curve`/
`stick_sensitivity`, defaults bit-identical to shipped behavior; host
input shaping, not enhancements, active in every profile. Owner hands-on
feel check pending.

Shutdown segfault on quit: **fixed properly**. Root cause was librecomp's
`recomp::start()` munmap'ing RDRAM while the game's `osCreateThread`
threads still run recompiled code (our 1 ms spin-yield hooks re-touch RDRAM
constantly, making it deterministic). The original fix (628ced4) was an
`_Exit(0)` from `RT64Context::shutdown()`; that has been **removed** and
replaced by a real orderly teardown in the runtime —
`ultramodern::terminate_game_threads()` sets a termination flag, every yield
point (`check_running_queue`, `wait_for_resumed`, the external-message waits)
throws `thread_terminated` once it is set, and the game's host threads are
joined before RDRAM is freed. `main()` returns normally again, so the
`save_type == SaveType::None` caveat is gone. The change lives in
`deps/N64ModernRuntime`, carried as
`patches/n64modernruntime-orderly-shutdown.patch` and applied at cmake
configure time — see `analysis/docs/build-notes.md`, "Patching a pinned
submodule". Written as an upstream PR would be; **drop the patch when
upstream takes it**. One upstream report candidate remains from this work:
RT64's bundled nativefiledialog aborting on an unguarded
`dbus_connection_unref` when no session bus exists (container-only; masked
the segfault until repro ran under `dbus-run-session`).

Mouse aim shipped (2026-07-29) — host input support like the pad, `[input]`
keys, active in every profile. Two modes: `mouse_mode = "positional"`
(default; closed-loop deadbeat controller driving the game's own reticle
integrator via the stick — the full RE and controller design are in
`analysis/docs/mouse-aim.md`, including the owner-seeded reticle addresses,
the measured deflection→step curve, and the three-layer gate that keeps it
inert outside missions) and `"velocity"` (FPS-style fallback). Also
`mouse_invert_y` (the game aims flight-inverted; default un-inverts).
Click captures / Esc releases; L/R/M buttons → Z/A/B (owner-specified
after hands-on; Z = left click is the fire button). Verified
headless including a closed-loop tracking test (zero overshoot) and a
0/5938 menu-safety re-measurement; **owner hands-on pending** (positional
vs velocity A/B, sensitivity default, which button should fire, and §9.1's
watch-item: aim going inert in any untested in-mission variant). Reticle
updates at game rate (~26.7 Hz at current budget) regardless of mouse
smoothness — fully smooth aim is coupled to the high-framerate work.

Containerized build shipped (2026-07-29): `containers/Containerfile`
(`debian:trixie-slim`, matching the devcontainer's base image so there's no
toolchain drift) plus `scripts/container_build.sh`, the one script both CI
and local dev use to build in it. `.github/workflows/build.yml`'s three jobs
were rewritten to call it instead of each carrying its own inline
apt-get/cmake recipe. Design in `analysis/docs/build-notes.md`,
"Containerized build" — build-dir isolation (`*-container` suffix, never
shares an object dir with a host build), ROM-as-mount-never-in-image, the
podman/SELinux run flags lifted from `.devcontainer`'s proven ones, and a
`-DKE_PYTHON`/`PY=` overrides that stop a host-built `.venv` the
bind-mounted repo might carry from being silently preferred over the
container's own (a tmpfs-shadow first attempt died on crun's tmpcopyup —
see build-notes).
**Owner-verified end-to-end (2026-07-30)** on the rootless-podman/SELinux
host: image build, stub build + `--check` (clean exit-1), and the full
`--rom --smoke` path (analysis pipeline on the image venv, recompile, link,
in-container Xvfb/lavapipe smoke PASS). Two real bugs found and fixed on
the way: the `.venv` tmpfs shadow died on crun's tmpcopyup (95 MB venv into
a 16 MB tmpfs — replaced with `-DKE_PYTHON`/`PY=` overrides, 3cc4266), and
`smoke_test.sh` dangled relative `--rom`/`--binary` paths after its
scratch-dir `cd` (35ead54). Still unexercised: the rewritten workflow's
first run on a GitHub runner (happens on next push), and `regen-verify` on
the self-hosted podman runner.

Agreed order for the rest: Flatpak → high framerate (containerized builds
were the item ahead of Flatpak — a reproducible container build is the
substrate the Flatpak manifest reuses — and are now done pending the
owner's host verification above). High framerate last because it is the
deepest timing-sensitive cut.

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
- Containerized build (no local toolchain install needed, docker or podman):
  `./scripts/container_build.sh --rom <path>` — output in `build-container/`.
  Same script CI runs; `--help` for the rest of its flags. See
  `analysis/docs/build-notes.md`, "Containerized build".
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
| `analysis/docs/mouse-aim.md` | The aiming reticle in RDRAM: layout + byte-order proof, 20-units/frame step and its stick-deflection curve, no auto-centering, out-of-mission staleness, and which word actually means "in a mission" (§6.2). Then the positional (closed-loop) mouse controller built on it, its three gates, and the fail-closed limitation that buys (§9.1). |
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
4. Enhancements not yet started, in agreed order (see Status): Flatpak
   packaging, high framerate. High-score persistence deferred (see
   candidates).
5. Mouse aim: owner hands-on pending (positional/velocity A/B, sensitivity,
   `mouse-aim.md` §9.1 inert-aim watch-item). Buttons settled: L/R/M →
   Z/A/B, owner-specified.
6. Gamepad: hotplug mid-game unverified (everything else owner-verified);
   `[input]` stick knobs shipped, owner feel-check pending.
7. Upstream: owner decided (2026-07-29) **not** to pursue a N64ModernRuntime
   PR for the orderly-shutdown patch — we carry it in `patches/`
   indefinitely (an upstream *issue* with repro + patch link remains an
   option if the owner ever wants it). Report candidates unchanged: RT64
   letterbox-band color bug (vanilla-only cosmetic;
   `letterbox-full-height.md` §4); RT64-bundled nativefiledialog null-dbus
   abort (container-only).
8. Containerized build: owner-verified end-to-end on the host (see Status).
   Remaining: first GitHub-runner execution of the rewritten workflow
   (automatic on next push — check the Actions tab), and the `regen-verify`
   job's containerized form on the self-hosted (podman) runner.
