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
first run on a GitHub runner (happens on next push). (`regen-verify` was
originally slated for the owner's self-hosted podman runner; the
encrypted-ROM CI work below moved it to hosted runners instead — no
self-hosted runner exists anywhere in the workflow now.)

Flatpak packaging shipped (2026-07-30): `packaging/flatpak/` (manifest,
launcher wrapper, desktop/metainfo/icon) + `scripts/build_flatpak.sh`. Two
src-side changes make it possible, both verified headless in this session:
`KE_DATA_DIR` env override for `get_app_folder_path()` (`src/main/support.cpp`)
so the Flatpak wrapper can point config/ROM-cache at the per-app XDG data dir;
and a portal ROM picker in `main.cpp` (NFD, already linked in via `rt64`) that
runs when no ROM is cached, so the manifest's `finish-args` need **no
`--filesystem` permission at all**. Two real hang/abort hazards were found and
fixed on the way, both in this session, both confirmed via `strace`: (1)
`NFD_Quit()` unconditionally `dbus_connection_unref()`s, which aborts if
`NFD_Init()` failed — guarded so `NFD_Quit()` is reachable only after
`NFD_Init() == NFD_OKAY`; (2) NFD's portal `OpenFile` call blocks with
`DBUS_TIMEOUT_INFINITE` and **hangs forever** if no portal service is
reachable at all (reproduced: bare Xvfb + a plain session bus, no
`xdg-desktop-portal` installed) — fixed with a `portal_reachable()` precheck
that asks the local D-Bus daemon (never the portal process) whether the
portal has an owner or is at least D-Bus-activatable, entirely skipping NFD
when neither is true; confirmed by `strace` to resolve in well under a
millisecond either way. A third, separate, **pre-existing** behavior was
also found and deliberately left alone: `show_error_message_box()`'s SDL
message box is genuinely modal under any live display (forks and blocks for
a human), which only matters for automated testing under a bare Xvfb with no
window manager — never for CI (no `DISPLAY` at all, confirmed clean exit 1
in ~5 ms) or a real desktop/Flatpak session (always has a compositor and a
user). Full design and the exact verification transcripts are in
`analysis/docs/build-notes.md`, "Flatpak packaging". **Owner-verified on
the host (2026-07-30)**: flatpak-builder + manifest build and run. That
test caught a real first-launch bug — the portal picker stored the ROM but
the game still errored "no ROM present" until relaunch, because
`select_rom()` writes to disk while validity is checked against an
in-memory set populated only by an earlier `check_all_stored_roms()` scan —
fixed by rescanning after a successful pick (6788841; owner retest on a
fresh data dir pending). Same commit: default profile switched to
`enhanced` (existing config.toml files pin their own profile and stay
vanilla until edited/deleted) and a `flatpak-release` CI job (vX.Y.Z tag →
build + attach bundle to the GitHub release).

Encrypted-ROM CI shipped (2026-07-31): full-ROM CI jobs now run on
GitHub-hosted runners with no self-hosted runner anywhere. The owner keeps
an **age-encrypted** ROM in a private Backblaze B2 bucket;
`scripts/fetch_rom.sh` (curl + age only — the B2 private-bucket signed
fetch uses curl's native `--aws-sigv4` against B2's S3-compatible endpoint,
no B2/AWS CLI) downloads, decrypts, md5-gates (mirrors
`analysis/byteswap.py`'s `KNOWN_MD5`), and atomically installs the
plaintext to `$RUNNER_TEMP` only (never in caches/artifacts/logs). Secrets:
`KE_ROM_URL` + `KE_ROM_AGE_KEY` (+ optional `KE_B2_KEY_ID`/`KE_B2_APP_KEY`
pair). A `rom-gate` job republishes "secrets configured?" as a job output
(job-level `if:` can't read the `secrets` context), so ROM jobs skip
cleanly on forks/PRs — the no-ROM/no-secrets fork-PR property is preserved
structurally. Consequences: `regen-verify` is now **continuous on every
main push** (plus dispatch); `release` fetches instead of needing a
`rom_path` (input removed); `flatpak-release` moved to ubuntu-latest
(apt-installed flatpak-builder, AppArmor userns sysctl for bwrap, cached
flathub runtime, and a quarantine step that moves `build/knife_edge.z64`
out of the tree before flatpak-builder's `dir` source stages the working
tree, plus the asset-leak assertion now also run against the bundled
binary). Verified here: full round-trip against a loopback server with the
real ROM (byte-identical, mode 600), the entire failure matrix (wrong key,
corrupt ciphertext, wrong plaintext, 404, env errors — all clean, no temp
or secret leakage), and a SigV4-signed request accepted by live B2 (403 on
fake creds = signing/region-parse correct). Design/threat model/owner
setup: `analysis/docs/build-notes.md`, "Encrypted ROM in CI (Backblaze
B2)". Owner configured the bucket + secrets 2026-07-31; two first-run
issues surfaced and were fixed: a secret-name typo (`KR_`→`KE_ROM_AGE_KEY`,
owner-side) and a real script bug — the B2 URL shape check only accepted
path-style S3 URLs, rejecting the virtual-hosted "S3-friendly URL" the B2
web UI hands out (`<bucket>.s3.<region>.backblazeb2.com`); both styles now
pass (verified against live B2: signed request accepted, 403 only on fake
creds).

CI restructure shipped (2026-07-31, owner-requested): every push-to-main
and **same-repo PR** now produces the full artifact set — a Linux x86_64
tarball (binary + COPYING + `packaging/linux/README.txt`) from
`linux-build` (renamed `release`; now also runs the containerized
Xvfb/lavapipe smoke test every build) and a `.flatpak` from `flatpak-build`
(renamed `flatpak-release`) — plus `regen-verify` on PRs too (config/
drift caught pre-merge). A `v*` tag additionally triggers the new thin
`publish` job: downloads the two artifacts **by name** (a glob would catch
the stub binary) and attaches them to the GitHub release; it is the *only*
job with `contents: write` and runs no checked-out code. Fork PRs stay
stub-only (`pull_request_target` deliberately never used; rom-gate has no
checkout). Dedup: `.github/actions/fetch-rom` composite action +
`scripts/assert_no_rom_assets.py` (replaces the two identical heredocs;
verified pass on real ROM vs /bin/ls and fail on a planted
sampled-offset chunk — note a fixed-offset plant does NOT trip it, the
sampling is seeded-random). Security note recorded in build-notes:
`build-container/` must never be cached from ROM jobs — it contains the
decrypted z64 and **default-branch caches are restorable by fork-PR
runs**. `on.push` is now filtered to `main` + `v*` (PRs cover branches);
workflow `concurrency` cancels superseded PR runs only.

High framerate shipped (2026-07-31) — the last item of the agreed
enhancement order. `high_framerate` flag (in `enhanced`, like its siblings
pre-verification): `rr_option = Display` activates RT64's frame
interpolation, but the load-bearing piece is rate declaration — RT64's VI
auto-detect needs a consistent 60/N cadence and this game's paced ~27 fps
straddles 2-3 VIs, so detection returns 0 and interpolation silently never
engages. Fix: `send_dl` (which already chooses the DL entry address)
prepends a 4-command extended-GBI prologue in scratch RDRAM at 0x807FF000
(upper 4 MiB; base-4MiB game never touches it; one-time zero-check
fail-safe): hook-ENABLE → `gEXSetRefreshRate(rate)` → hook-DISABLE →
hook-BRANCH to the game DL. The OSTask is never modified and extended GBI
is never live inside the game's own DL. The declared rate is a live EMA
over `ke_gfx_task_begin` intervals (cutscenes self-limit to ~15 fps and
must interpolate at their own cadence — a constant would make them judder
worse than vanilla). Game logic pace untouched (verified: identical DL
counts flag-on vs flag-off). Full design record:
`analysis/docs/high-framerate.md`. Headless cannot exercise interpolation
itself (Xvfb → display target 0 Hz → targetRate 0); the owner's GPU run
was the first real interpolation run. **Owner-verified 2026-07-31**: works
(visibly higher frame rate, most of the scene smooth), but heuristic
transform matching artifacts confirmed on the lock-on effect and bullet
trails — **owner decision: out of the `enhanced` set, experimental opt-in
via custom profile**, labeled as such in config/README. Escalation path
when wanted: per-effect gEXMatrixGroup tagging (doc §4); lock-on + trails
are the first targets, likely treatment is opting them out of
interpolation.

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
  themselves). Env: `KE_PERF=1` (VI/s + frames/s), `KE_AUDIO_DUMP=<path>` (PCM),
  `KE_DL_DUMP=<path>` (+ `KE_DL_DUMP_AFTER_S` / `KE_DL_DUMP_FRAMES`) — decoded
  display lists, see `analysis/docs/hud-relocation.md` §1.
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
| `analysis/docs/hud-relocation.md` | The `KE_DL_DUMP` display-list dumper, and the phase-1 identification of every in-mission HUD element (all `G_TEXRECT`, fixed sub-DL addresses, fingerprint table) plus the `gEXSetRectAlign` feasibility verdict. |
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

**Enhancements go behind flags.** The default profile is **enhanced** (owner
decision 2026-07-30); vanilla remains one `--profile vanilla` away and remains
the **regression baseline** — measurements and bug investigations assume
vanilla unless stated otherwise. Every deviation from original behavior is
runtime-toggleable. Fidelity knobs (e.g. `tuning.rcp_frame_ms`) are *not*
enhancements. Note: an existing config.toml pins its own profile — the new
default only affects fresh installs.

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
4. HUD relocation: shipped; first owner hands-on round done (2026-07-31)
   and its two findings fixed: the dynamic fills (health arc, S-BOMB
   charge) draw from a 0x240-byte slot pool at VALUE-DEPENDENT sub-DL
   addresses (13 arc / 3 charge variants — phase 1's near-full-health
   captures saw only 2), now matched geometrically by region instead of
   by address (`hud-relocation.md` phase 3); and the cutscene radio box
   is deliberately left at its original position (owner decision —
   cutscene effects misalign alongside it and its 4:3 placement reads
   naturally). Verified headless at 20% health: fills ride with their
   containers, nothing strands in the 4:3 column. Owner verdict on that
   round: "looks good". Watch item unchanged: elements from uncaptured
   states (pause, boss bars, results — O2) stay in the 4:3 column;
   report + KE_DL_DUMP capture is the fix path.
   `extended_aim` shipped on top (2026-07-31, owner-requested): reticle
   rails widen from ±128/±84 to the enlarged view (±170 x at 16:9 with
   widescreen+hud_relocation, ±100 y with full_height) — an EXTEND at
   1 unit = 1 px, deliberately not a rescale (mouse-aim.md's measured
   curves stay literally valid). Feasibility RE proved the aim ray is
   the same two integers through an unbounded atan2 with the frustum's
   own focal constant, so crosshair and shots agree at any value; four
   gen_syms hooks (clamp stash/re-apply, blit x-bias, scissor widen) +
   draw-side bias compensation in the reticle stub. THE OFF-PATH IS THE
   FIDELITY GUARANTEE (hooks exist in every profile; vanilla measured
   railing at exactly ±128/±84). In `enhanced`; owner hands-on pending
   — edge-of-screen hit-registration feel is the one thing only play
   can confirm. Full RE + plan: `hud-relocation.md`, "Reticle range
   extension".
5. High framerate: shipped and owner-verified (see Status); experimental
   opt-in, not in `enhanced` (owner decision 2026-07-31 — confirmed
   artifacts on lock-on effect + bullet trails). Deferred follow-up when
   the owner wants it: per-effect interpolation opt-out tagging
   (`high-framerate.md` §4; needs RE to identify the offending draws'
   signatures — no decompilation exists to tag at the source). All items
   of the agreed enhancement order are now shipped. High-score
   persistence remains deferred (see candidates).
6. Mouse aim: owner hands-on pending (positional/velocity A/B, sensitivity,
   `mouse-aim.md` §9.1 inert-aim watch-item). Buttons settled: L/R/M →
   Z/A/B, owner-specified.
7. Gamepad: hotplug mid-game unverified (everything else owner-verified);
   `[input]` stick knobs shipped, owner feel-check pending.
8. Upstream: owner decided (2026-07-29) **not** to pursue a N64ModernRuntime
   PR for the orderly-shutdown patch — we carry it in `patches/`
   indefinitely (an upstream *issue* with repro + patch link remains an
   option if the owner ever wants it). Report candidates unchanged: RT64
   letterbox-band color bug (vanilla-only cosmetic;
   `letterbox-full-height.md` §4); RT64-bundled nativefiledialog null-dbus
   abort (container-only).
9. Containerized build: owner-verified end-to-end on the host (see Status).
   Remaining: first GitHub-runner execution of the rewritten workflow
   (automatic on next push — check the Actions tab).
10. Flatpak packaging: owner-verified build+run on the host (see Status).
   Remaining: retest the first-launch picker fix (6788841) against a fresh
   data dir (wipe `~/.var/app/io.github.haydenmc.KnifeEdgeRecompiled/data/`
   or unset-`KE_DATA_DIR` equivalent), and data-dir persistence across
   runs. Report candidate: the pre-existing modal-message-box behavior
   under a bare-Xvfb-no-WM harness (`build-notes.md`, "Flatpak packaging"
   — not a real-world defect, left alone).
11. Encrypted-ROM CI: owner setup done (2026-07-31, see Status).
    Unverified-in-anger after the restructure: first full run on the next
    main push (linux-build with in-CI smoke + tarball, flatpak-build —
    first-ever flatpak-builder on a hosted runner: AppArmor userns sysctl,
    flathub runtime cache, `test -f`-guarded `build-flatpak/build/files/`
    layout assumption — and regen-verify), and `publish` on the first
    `v*` tag. Watch-items for the in-CI smoke test: docker's 64 MB
    default /dev/shm and lavapipe speed on 4-vCPU runners — if it flakes,
    raise smoke `--seconds`, don't loosen the color/audio thresholds;
    only add `--shm-size` plumbing if an actual XShm error appears.
