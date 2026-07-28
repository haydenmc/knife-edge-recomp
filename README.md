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

- The recompiled binary **boots, initializes RT64/SDL, and runs the game's
  own code**: KEMCO logo → title screen ("KNIFE EDGE / NOSE GUNNER") → the
  full attract loop (story text, Mars canyon flythrough, space-station
  cinematic), looping stably. See `analysis/docs/boot-debug.md` for the debug
  log that got it there, including a 200 s soak run with no crash.
- **Audio is not implemented.** RSP audio tasks are currently swallowed by a
  no-op microcode stand-in (see `src/main/main.cpp`'s `skip_audio_task`) so
  the game doesn't stall waiting on them, but no samples are ever produced.
  Wiring up real audio needs an RSPRecomp pass over Knife Edge's audio
  microcode plus an SDL audio sink — tracked as TBD in
  `analysis/docs/n64recomp-formats.md` and `analysis/docs/boot-debug.md`.
- **Gameplay beyond the title/attract sequence has not been verified.**
  There is no ROM picker and `recomp::start_game()` is only ever triggered
  automatically a few VI retraces after boot — nothing has driven the game
  past Start yet, so mission/gameplay code paths are untested.
- Keyboard input is wired up (see "Controls" below) so `osContInit` reports a
  connected controller instead of the game's "no controllers attached" stall,
  but there's no controller/gamepad support, no save-file UI, and no
  in-game configuration yet.

## Repository policy

Reverse-engineered **functional code** is committed to this repo:

- `config/*.toml` — the symbol/section tables produced by the analysis
  pipeline (`analysis/`).
- `generated/us/*.c`, `*.cpp`, `*.inl`, `funcs.h` — N64Recomp's C output for
  Knife Edge (US), generated from those config files.

The **ROM itself, and any asset/data dumps extracted from it, are never
committed** (see `.gitignore`: `*.n64`/`*.z64`/`*.v64`/`*.rom` and
`/build*/`). Knife Edge – Nose Gunner is © 1998 Kemco; you need your own
legally-obtained dump of the cartridge to run the recompiled build or to
regenerate `generated/us/` yourself.

One consequence: **CI needs no ROM and no secrets.** `.github/workflows/build.yml`
compiles the committed `generated/us/` output directly; it never touches a
ROM. The one job that does need a ROM (`regen-verify`) is manual-dispatch
only and documents the regen recipe rather than running it automatically —
see "Regenerating from a ROM" below.

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
  -DKE_GENERATED_DIR="$(pwd)/generated/us"
cmake --build build
```

The resulting binary is `build/KnifeEdgeRecompiled`. (Any build directory
name works — local development in this repo has also used `build-shim`;
CI uses `build`.)

Leaving `-DKE_GENERATED_DIR` unset builds against `src/stub_game/` instead —
a placeholder that links and runs but has no real game code, useful for
build-system iteration without needing `generated/us/` to be in a working
state.

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
  -DCMAKE_BUILD_TYPE=Release -DKE_GENERATED_DIR="$(pwd)/generated/us"
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

## Regenerating from a ROM

`generated/us/` and `config/*.toml` are committed, but if you want to
reproduce them yourself (e.g. after changing the analysis pipeline), the
recipe is:

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
4. **Run N64Recomp**, which writes straight into `generated/us/` per
   `output_func_path` in `config/knife_edge.us.toml`:
   ```sh
   deps/N64Recomp/build/N64Recomp config/knife_edge.us.toml
   ```
5. **Diff against what's committed**:
   ```sh
   git diff --stat -- generated/us config
   ```
   No diff means the pipeline is reproducible and nothing to update. A diff
   means either the pipeline changed behavior or the committed output was
   stale — review before committing.
6. Rebuild `KnifeEdgeRecompiled` against the (re)generated `generated/us/`
   as in "Building" above.

`.github/workflows/build.yml` has a `regen-verify` job that automates exactly
this recipe and fails if step 5 finds a diff — but it's gated to
`workflow_dispatch` with an explicit `rom_path` input and targets a
self-hosted runner, since (per the policy above) no ROM is ever available to
GitHub-hosted CI runners. It exists as executable documentation of this
recipe, not as something that runs on every push.

## Architecture

- `CMakeLists.txt` — top-level build; wires up RT64 + N64ModernRuntime
  (`ultramodern`/`librecomp`) + the `RecompiledFuncs` static lib (either
  `generated/us/` or `src/stub_game/`) into the `KnifeEdgeRecompiled`
  executable. See `analysis/docs/build-notes.md` for how it was put together,
  including dependency quirks and what was and wasn't kept from
  Zelda64Recomp's reference implementation.
- `src/main/` — runtime entry point (`main.cpp`), RT64 renderer wiring
  (`rt64_render_context.{h,cpp}`), overlay registration
  (`register_overlays.cpp`), small platform helpers (`support.{h,cpp}`).
- `src/stub_game/` — placeholder game code used when `KE_GENERATED_DIR` is
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
