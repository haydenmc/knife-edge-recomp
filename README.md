# Knife Edge Recompiled

A static-recompilation PC port of *Knife Edge – Nose Gunner* (N64, Kemco,
1998), built on [N64Recomp](https://github.com/N64Recomp/N64Recomp) /
[N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) and
[RT64](https://github.com/rt64/rt64) — the same toolchain used by
[Zelda64Recomp](https://github.com/Zelda64Recomp/Zelda64Recomp).

Knife Edge's N64 machine code is translated to C ahead of time (no
emulation), linked against a runtime that HLEs the OS/libultra layer, and
rendered through RT64's modern graphics backend.

## Status

Playable and stable. Boots through the KEMCO logo, title screen and attract
loop into the menus and gameplay — verified on real hardware through stage 4
including an alternate stage path, with correct music and sound effects,
correct game speed, and working results/stage-overview screens. No known
defects.

Not yet verified: full campaign completion, and high-score persistence across
runs (analyzed and almost certainly absent — which is *faithful*, since the
game only probes for a Controller Pak; see `analysis/docs/enhancements.md`).

Not yet built: widescreen, high framerate, mouse aim, gamepad support, and
packaging. The configuration system that these will hang off is in place —
`vanilla` is the default profile and the regression baseline (see
"Configuration" below and `analysis/docs/enhancements.md`).

Development notes, working practices and a documentation index live in
`CLAUDE.md`.

## Repository policy

What this repo contains is the **analysis pipeline and its metadata**, not build
artifacts:

- `analysis/` — the scripts that derive symbols from a ROM (function boundary
  detection, libultra identification, spin-loop detection).
- `config/*.toml` — the symbol/section tables those scripts produce. This is the
  reviewable source of truth: a change here is human-meaningful.
- `src/` — the runtime shim (window, renderer, audio, input, ROM provisioning).

Deliberately **not** committed:

- **The ROM, and any asset or data dump taken from it.** Knife Edge – Nose
  Gunner is © 1998 Kemco; you need your own legally-obtained dump to build a
  playable binary or to regenerate anything.
- **Recompiler output** (`generated/`). It is a build artifact derived
  mechanically from the ROM, so it is regenerated rather than stored — see
  "Regenerating from a ROM".

Two consequences worth knowing:

**Normal CI needs no ROM and no secrets.** With no ROM available, the build
compiles `src/stub_game/` instead of recompiled game code, so
`.github/workflows/build.yml` still validates the runtime shim, RT64,
librecomp, ultramodern, audio and input on every push — and works for pull
requests from forks, which cannot receive secrets.

**Release binaries contain recompiled code but no game data.** The player
supplies their own ROM at runtime and the game reads assets, audio and level
data directly out of it, exactly as it did on hardware — there is no asset
extraction step. The `release` workflow job asserts this by sampling the ROM's
data regions and failing if any of those bytes appear in the binary.

## Building

### Option A: devcontainer (recommended)

Open the repo in the provided devcontainer (`.devcontainer/devcontainer.json`).
Its `postCreateCommand` installs the full toolchain, sets up a Python venv
for the analysis pipeline, and initializes submodules. Then:

```sh
git submodule update --init --recursive   # if not already done
cmake -B build -G Ninja \
  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_BUILD_TYPE=Release \
  -DKE_ROM="/path/to/Knife Edge - Nose Gunner (USA).n64"
cmake --build build
```

The resulting binary is `build/KnifeEdgeRecompiled`. (Any build directory
name works — local development in this repo has also used `build-shim`;
CI uses `build`.)

`KE_ROM` makes CMake normalize the ROM, run the analysis pipeline, and invoke
N64Recomp/RSPRecomp at configure time; the results land in `build/generated/`.
Omit it to build against `src/stub_game/` instead — a placeholder that links and
runs but has no real game code, useful for build-system iteration and for CI
without a ROM. (`-DKE_GENERATED_DIR=<dir>` still works if you have recompiler
output from elsewhere.)

### Option B: native deps

Install (Debian/Ubuntu package names — matches
`.devcontainer/devcontainer.json`'s `postCreateCommand`):

```sh
sudo apt-get install -y cmake ninja-build clang lld pkg-config \
  libsdl2-dev libx11-dev libvulkan-dev vulkan-tools \
  glslang-tools spirv-tools mesa-vulkan-drivers xvfb
```

(`xvfb` and a Vulkan software rasterizer like `mesa-vulkan-drivers`'
lavapipe are only needed for headless/CI runs without a real GPU/display.)
Then clone with submodules and build as in Option A:

```sh
git clone --recurse-submodules <this repo>
cmake -B build -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_BUILD_TYPE=Release -DKE_ROM="/path/to/knife_edge.n64"
cmake --build build
```

macOS and Windows should work per the top-level `CMakeLists.txt`'s
platform branches (this mirrors Zelda64Recomp's supported set) but have not
been exercised for this project — Linux is the actively-tested platform (see
`analysis/docs/build-notes.md`).

## Running

You need your own dump of *Knife Edge – Nose Gunner (USA)* (`.z64`, `.v64`,
or `.n64` byte order — all three are accepted).

```sh
./build/KnifeEdgeRecompiled --rom /path/to/knife_edge.z64
```

The first run with `--rom` validates the dump (hash-checked against the
known-good ROM) and stores a normalized copy under a `ke_recomp_data/`
directory next to wherever you run the binary from. Subsequent runs can omit
`--rom` and will reuse the stored copy. Running without `--rom` and without a
previously stored ROM prints a clear error and exits (this is what
CI's smoke test checks — see below).

### Controls

Keyboard only for now (see `src/main/main.cpp`); no gamepad support yet.

| N64 input | Key |
|---|---|
| A | X |
| B | Z |
| Z | Left Shift |
| Start | Enter |
| D-pad Up/Down/Left/Right | Arrow keys |
| C-Up / C-Down / C-Left / C-Right | I / K / J / L |
| L / R shoulder | Q / E |
| Control stick | W A S D |

The game samples the controller once per game frame (~15 Hz — see
`analysis/docs/timing-and-mission-debug.md`), the same as on console, so a key
has to be held for a frame to register. The window disables SDL's text input
so a desktop input method cannot swallow those holds; if your desktop still
intercepts held keys, try running with `XMODIFIERS=@im=none QT_IM_MODULE=
GTK_IM_MODULE=` to take the input method out of the path entirely.

## Configuration

Settings live in `<app folder>/config.toml` (the `ke_recomp_data/` directory
mentioned above, next to wherever you run the binary from), created with
commented defaults on first run. It selects a **profile**:

- `vanilla` (default) — every enhancement off, faithful to original hardware
  behavior. This is what every other section of this README assumes.
- `enhanced` — a curated set of opt-in quality-of-life changes: currently
  `input_latching` (see Controls above), `high_resolution` (renders the 3D
  scene at window resolution through RT64 instead of native 320x240), and
  `widescreen` (expands the 3D field of view to the window's aspect ratio
  instead of 4:3-pillarboxing it).
- `custom` — reads individual `[enhancements]` flags from the file.

Two CLI flags, and nothing else config-related:

```sh
./build/KnifeEdgeRecompiled --rom /path/to/knife_edge.z64 --profile enhanced
./build/KnifeEdgeRecompiled --config /path/to/other-config.toml
```

`--profile` overrides `[profile] active` from the file; `--config` points at
a config file somewhere other than the default location. A missing file is
created with defaults; a malformed one falls back to vanilla defaults with a
warning on stderr rather than failing to start. The active profile and any
non-default flags are logged on startup right after the build stamp, so a
bug report identifies its config along with its build. See
`analysis/docs/enhancements.md` for the full policy, the current flag table,
and how future enhancements get added.

## Regenerating from a ROM

Recompiler output is not committed, so a playable build always regenerates it.
Passing `-DKE_ROM=<path>` to CMake does all of this for you; the manual recipe
below is what that automates, and is what you want when iterating on the
analysis pipeline itself:

1. **Build the one-time tools** (if you haven't already):
   ```sh
   cmake -S deps/N64Recomp -B deps/N64Recomp/build -G Ninja \
     -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
   ninja -C deps/N64Recomp/build N64Recomp
   make -C deps/n64sym          # symbol-identification oracle used by stage 2 below
   ```
2. **Ingest your ROM** into the normalized form the pipeline expects:
   ```sh
   .venv/bin/python analysis/byteswap.py /path/to/your/rom build/knife_edge.z64
   ```
   This accepts z64/v64/n64 byte order, verifies the dump's md5 against the
   known-good Knife Edge (USA) hash, and writes a normalized big-endian z64
   to `build/knife_edge.z64` (outside the repo tree — never committed).
3. **Run the analysis pipeline**:
   ```sh
   make -C analysis
   ```
   This runs `find_functions.py` → `ident_libultra.py` → `gen_syms.py`
   (see `analysis/docs/pipeline-spec.md` and `pipeline-report.md`) and
   (re)writes `config/knife_edge.us.syms.toml` and `config/knife_edge.us.toml`.
4. **Run N64Recomp** (and `RSPRecomp` for the audio microcode). Output goes
   wherever `output_func_path` in `config/knife_edge.us.toml` points — a build
   directory, never the repo:
   ```sh
   deps/N64Recomp/build/N64Recomp config/knife_edge.us.toml
   deps/N64Recomp/build/RSPRecomp config/aspMain.us.toml
   ```
5. **Check the metadata is unchanged**:
   ```sh
   git diff --stat -- config
   ```
   No diff means the pipeline is reproducible. A diff means the pipeline
   changed behavior — review it, since `config/` is the reviewable record of
   what the analysis concluded.
6. Rebuild `KnifeEdgeRecompiled` against the regenerated output as in
   "Building" above.

`.github/workflows/build.yml` has a `regen-verify` job that automates this
recipe and fails if step 5 finds a diff — but it's gated to
`workflow_dispatch` with an explicit `rom_path` input and targets a
self-hosted runner, since (per the policy above) no ROM is ever available to
GitHub-hosted CI runners. It exists as executable documentation of this
recipe, not as something that runs on every push.

## Architecture

- `CMakeLists.txt` — top-level build; wires up RT64 + N64ModernRuntime
  (`ultramodern`/`librecomp`) + the `RecompiledFuncs` static lib (either
  the regenerated output or `src/stub_game/`) into the `KnifeEdgeRecompiled`
  executable. See `analysis/docs/build-notes.md` for how it was put together,
  including dependency quirks and what was and wasn't kept from
  Zelda64Recomp's reference implementation.
- `src/main/` — runtime entry point (`main.cpp`), RT64 renderer wiring
  (`rt64_render_context.{h,cpp}`), overlay registration
  (`register_overlays.cpp`), the RCP frame-time model that sets the game's
  speed (`rcp_timing.cpp`), small platform helpers (`support.{h,cpp}`), the
  enhancement-flag/profile config loader (`config.{h,cpp}` — see
  "Configuration" above and `analysis/docs/enhancements.md`).
- `src/stub_game/` — placeholder game code used when no ROM/generated code is
  unset, so the executable always links and runs even without a ROM-derived
  build.
- `analysis/` — the ROM → symbols pipeline (Python): `find_functions.py`
  (function boundary detection), `ident_libultra.py` (libultra/OS function
  naming via the vendored `n64sym` tool plus a curated override table),
  `gen_syms.py` (emits the `config/*.toml` N64Recomp consumes). Full pipeline
  design in `analysis/docs/pipeline-spec.md`, results in
  `analysis/docs/pipeline-report.md`.
- `analysis/docs/n64recomp-formats.md` — reference for the N64Recomp input
  TOML formats and output contract this project relies on.
- `analysis/docs/overlay-tracking.md` — how Knife Edge's own code-overlay
  loader is hooked so librecomp's function-lookup tables stay correct across
  overlay swaps.
- `analysis/docs/boot-debug.md` — the crash-by-crash debugging log from first
  boot to a stable title/attract loop; the best single source for "what does
  and doesn't work yet."
- `analysis/docs/timing-and-mission-debug.md` — why the game ran 4x too fast
  and why starting a mission hung, with the measurements and backtraces; also
  documents `KE_PERF` (frame-rate instrumentation) and `KE_RCP_FRAME_MS` (the
  RCP frame-time budget), and the headless recipe for driving the menus.

## Credits

- [N64Recomp](https://github.com/N64Recomp/N64Recomp) and
  [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) (MIT,
  N64Recomp org / Wiseguy) — the static recompiler and the
  `ultramodern`/`librecomp` runtime this project's game code and `main.cpp`
  are built on.
- [RT64](https://github.com/rt64/rt64) (MIT, RT64 Contributors) — the
  rendering backend used for `ultramodern::renderer::callbacks_t`.
- [n64sym](https://github.com/shygoo/n64sym) (MIT, shygoo) — the signature-
  based symbol identification tool used as the seed oracle in
  `analysis/ident_libultra.py`.
- [Zelda64Recomp](https://github.com/Zelda64Recomp/Zelda64Recomp) — reference
  implementation this project's `main.cpp`, `rt64_render_context.cpp`, and
  `register_overlays.cpp` patterns were adapted from (see
  `analysis/docs/build-notes.md` for exactly what was kept vs. dropped).

Knife Edge – Nose Gunner is © 1998 Kemco. This project contains no Kemco
assets, game data, or ROM content — only independently reverse-engineered
control-flow structure (function boundaries and libultra/OS symbol names)
needed to recompile the game's own machine code.
