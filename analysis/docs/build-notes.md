# Build system notes — Knife Edge Recompiled skeleton

Written while wiring up the top-level CMake project (`/CMakeLists.txt`) that
builds `deps/N64ModernRuntime` (librecomp + ultramodern) and `deps/rt64`
into a `KnifeEdgeRecompiled` executable. Verified 2026-07-27 by a clean
`rm -rf build-shim && cmake -B build-shim -G Ninja ... && ninja -C build-shim`
(see "Build status" below).

## Build status

- **Configures and links cleanly** with clang/clang++ 19 + Ninja, both with
  `KE_GENERATED_DIR` unset (compiles `src/stub_game/`) and with it pointing
  at a fake generated-output directory (exercised the real path too).
- Full clean build: 448 ninja targets, ~30s wall / ~6m CPU on this
  devcontainer. Only warnings, no errors (a couple of harmless `-Wswitch`
  warnings on `RT64::UserConfiguration::GraphicsAPI::OptionCount` not being
  handled — that's a sentinel value, matches upstream Zelda64Recomp's own
  code, not fixed).
- **Runtime smoke test**: ran the built binary under `Xvfb :50` (container
  has no real display) with `DISPLAY` pointed at it and `SDL_AUDIODRIVER=dummy`.
  SDL picked the `x11` video driver, RT64's `Application::setup()` succeeded
  against the container's lavapipe (software Vulkan) ICD, and the process
  sat alive in `recomp::start()`'s idle loop (`while (!exited) { ... }`,
  waiting for a game that's never started since there's no ROM picker yet)
  until killed after 6s. So this isn't just a link-level skeleton — it's a
  window-and-renderer-initializing skeleton. Under the container's default
  `SDL_VIDEODRIVER=dummy` (no `DISPLAY`), it fails fast with a clear error
  ("Vulkan support is ... not available in current SDL video driver
  (dummy)"), which is expected and not a bug.

## Target names / options this project defines

- `KnifeEdgeRecompiled` — the executable.
- `RecompiledFuncs` — static lib holding either the N64Recomp output
  (`KE_GENERATED_DIR/*.c` + `*.cpp`) or `src/stub_game/recomp_entrypoint.c`.
- `KE_GENERATED_DIR` (cache `PATH`, default empty) — point this at an
  N64Recomp output directory (`RecompiledFuncs/*.c` + `recomp_overlays.inl` +
  `funcs.h`, see `n64recomp-formats.md`) to build real game code instead of
  the stub.
- `N64RECOMP_HOST_TOOL` / `RSPRECOMP_HOST_TOOL` (cache `FILEPATH`) — point at
  the prebuilt host tool binaries (default `deps/N64Recomp/build/N64Recomp`
  and `.../RSPRecomp`). If found, imported as `N64RecompHostTool` /
  `RSPRecompHostTool` `IMPORTED` executable targets for future custom
  commands (e.g. a build step that reruns N64Recomp on a config.toml). Not
  currently invoked by anything — this is scaffolding for when the ROM→C
  step gets driven from CMake instead of run by hand. TODO(superbuild):
  replace the by-path import with actually building `deps/N64Recomp` as part
  of this configure.

## Target names this project consumes (from the vendored deps)

- `deps/N64ModernRuntime/CMakeLists.txt` just does
  `add_subdirectory(ultramodern)` then `add_subdirectory(librecomp)` — no
  options of its own.
  - `ultramodern` (static lib): world-facing headers under
    `ultramodern/include/ultramodern/*.hpp`. Defines the `callbacks_t`
    structs for rsp/renderer/input/events/error_handling/threads that the
    game project fills in, plus `ultramodern::start`-adjacent plumbing
    (`preinit`, thread/message-queue machinery, `renderer::WindowHandle`
    which is `SDL_Window*` on Linux, `HWND`-wrapper on Windows,
    `{window,view}` struct on macOS).
  - `librecomp` (static lib): the `recomp::` namespace — `GameEntry`,
    `register_game`, `Configuration`/`start`, overlay registration
    (`recomp::overlays::register_overlays`), RSP dispatch. Its
    `CMakeLists.txt` also `add_subdirectory`s `../thirdparty/miniz` and
    `../N64Recomp` (a **second**, nested copy of the N64Recomp repo vendored
    under `N64ModernRuntime/N64Recomp/`, distinct from the top-level
    `deps/N64Recomp` used for the prebuilt host tools) to get the
    `N64Recomp`/`LiveRecomp` libraries it links against for mod support.
    `librecomp`'s only *exported* (`PUBLIC`) include dir is
    `librecomp/include`; things like `librecomp/rsp.hpp` live one level
    deeper at `librecomp/include/librecomp/rsp.hpp` and are pulled in via
    quoted `#include "rsp.hpp"` from inside `librecomp/game.hpp` — that
    works because quoted includes fall back to "relative to the including
    file" regardless of `-I` flags, so you never need to add
    `librecomp/include/librecomp` to your own include path.
- `deps/rt64/CMakeLists.txt` defines `rt64` (static, since we set
  `RT64_STATIC TRUE`) plus a pile of vendored-contrib targets (`nfd`,
  `plume`, `re-spirv`, `libzstd_static`, `file_to_c`, ...). Its own
  `target_include_directories(rt64 ...)` are almost all `PRIVATE`, so a
  consumer executable has to manually add the same include dirs
  Zelda64Recomp does: `src/contrib`, `src/contrib/hlslpp/include`,
  `src/contrib/dxc/inc`, `src`, `src/rhi`, `src/render`,
  `src/contrib/nativefiledialog-extended/src/include` (this project's
  `CMakeLists.txt` does this for the `KnifeEdgeRecompiled` target).
  `HLSL_CPU` must be defined project-wide before `rt64`'s sources are
  compiled (it's what makes RT64's HLSL-mirroring C++ code compile as plain
  C++); set once via `add_compile_definitions(HLSL_CPU)` at the top of the
  top-level `CMakeLists.txt`, not per-target (defining it again in a
  `.cpp` that includes RT64 headers just produces a `-Wmacro-redefined`
  warning, which is what happened here until removed from
  `rt64_render_context.cpp`).

## RT64 + ultramodern wiring points

`ultramodern::renderer::callbacks_t::create_render_context` is the one
mandatory hook a game project provides to get pixels on screen. This
project's implementation is `kerecomp::renderer::create_render_context` in
`src/main/rt64_render_context.{h,cpp}`, which builds an
`RT64::Application` from an `RT64::Application::Core` (raw pointers to
RDRAM/DMEM/IMEM and RDP/VI register storage — Knife Edge doesn't drive real
RDP interrupts since RT64 owns display-list processing directly, so those
are just backing storage) and an `RT64::ApplicationConfiguration`
(`useConfigurationFile = false`, since there's no on-disk RT64 config file
management here). `RendererContext::send_dl` is only invoked for
`M_GFXTASK` RSP tasks — `ultramodern::submit_rsp_task` in
`ultramodern/src/events.cpp` special-cases `M_GFXTASK` to call
`renderer_context->send_dl` directly and routes everything else (audio,
jpeg, ...) through `recomp::rsp::callbacks_t::get_rsp_microcode`, so RT64
already handles F3DEX/F3DLX without needing an RSPRecomp-generated ucode —
only non-graphics RSP microcode (audio ucode, still TBD per
`n64recomp-formats.md`) will ever need one.

`ultramodern::gfx_callbacks_t` is the SDL side: `create_gfx` (SDL_Init),
`create_window` (SDL_CreateWindow with `SDL_WINDOW_VULKAN` on Linux, guarded
by the `RT64_SDL_WINDOW_VULKAN` compile definition — this project sets both
`set(RT64_SDL_WINDOW_VULKAN TRUE)` for rt64's own build **and**
`add_compile_definitions("RT64_SDL_WINDOW_VULKAN")` on Linux for consumer
code, matching what Zelda64Recomp does), and `update_gfx` (pumps
`SDL_PollEvent`, calls `ultramodern::quit()` on `SDL_QUIT`).

`recomp::mods::initialize_mods()` is called unconditionally inside
`recomp::start()` and needs `recomp::register_config_path(...)` to have been
called first (it `create_directories`s `config_path / "mods"` etc. even
though this project doesn't use mods yet) — `main()` calls
`recomp::register_config_path(kerecomp::get_app_folder_path())` before
`recomp::start(...)` for this reason.

## Zelda64Recomp patterns followed (fetched dev branch via
   raw.githubusercontent.com: `CMakeLists.txt`, `src/main/main.cpp`,
   `src/main/rt64_render_context.cpp`, `include/zelda_render.h`,
   `src/main/support.cpp`, `src/main/register_overlays.cpp`)

- Top-level `CMakeLists.txt` shape: `add_subdirectory` rt64 then
  N64ModernRuntime, then a `RecompiledFuncs` static lib globbing
  `*.c`/`*.cpp` from a recompiler-output directory, then the main
  executable linking `RecompiledFuncs`, `librecomp`, `ultramodern`, `rt64`.
  This project's `CMakeLists.txt` mirrors that shape but swaps the
  always-glob-a-fixed-directory approach for the `KE_GENERATED_DIR`
  cache-path switch (Zelda64Recomp doesn't need this because their
  `RecompiledFuncs/` directory is always populated by their patches build
  step; this project doesn't have recompiled code yet).
- `register_overlays.cpp` including a bare `#include "recomp_overlays.inl"`
  and building `overlay_section_table_data_t`/`overlays_by_index_t` from the
  generated `section_table`/`num_sections`/`overlay_sections_by_index`
  globals — copied close to verbatim, since this is exactly the contract
  N64Recomp's generated output expects (see `n64recomp-formats.md`). The
  *directory* that `"recomp_overlays.inl"` resolves against is switched per
  build via `set_source_files_properties(.../register_overlays.cpp
  PROPERTIES INCLUDE_DIRECTORIES "${KE_OVERLAYS_DIR}")`, which is *additive*
  to the target's other include dirs (not a replacement) — that's how one
  `register_overlays.cpp` source file works against either
  `KE_GENERATED_DIR` or `src/stub_game/` without duplicating the file.
- `rt64_render_context.cpp`: kept the `RT64::Application::Core` setup, the
  `GraphicsConfig -> RT64::UserConfiguration` field mapping
  (`set_application_user_config`), `SetupResult`/`GraphicsApi` enum mapping,
  and the `send_dl`/`update_screen`/`shutdown`/`update_config`/
  `enable_instant_present`/`get_display_framerate`/`get_resolution_scale`
  method bodies essentially verbatim. **Dropped**: the whole texture-pack /
  mod-content-type integration (`enable_texture_pack`,
  `TexturePackAction` queue, `RT64::ReplacementDirectory` loading,
  `recompui::set_render_hooks()`) and the MSAA-capability probing
  (`device->getCapabilities().sampleLocations`,
  `shaderLibrary->usesHDR`) — none of it is exposed anywhere without a UI
  layer, which this skeleton doesn't have yet.
- `main.cpp`: kept `create_gfx`/`create_window`/`update_gfx` and the
  `GameEntry` → `recomp::start(Configuration{...})` wiring. **Dropped**:
  NativeFileDialog usage, RmlUi/`recompui` UI bring-up, audio device setup
  (SDL_OpenAudioDevice + resampling), controller-mapping-DB loading, window
  icon (`SetImageAsIcon`/`stb_image`), executable preloading
  (`VirtualLock`/mlock trick) — all explicitly out of scope per the task
  ("controller/save/ROM-picker come later").
- One thing this project's `librecomp` version differs on from what
  Zelda64Recomp's `dev` branch expects: `recomp::start()` here takes a
  single `const recomp::Configuration&` aggregate (with a
  `window_handle` field and `message_queue_control`), not the ten
  positional arguments Zelda64Recomp's fetched `main.cpp` passes. Wrote
  `main.cpp` against the header actually vendored in
  `deps/N64ModernRuntime/librecomp/include/librecomp/game.hpp`, not the
  fetched reference — worth remembering if pulling more patterns from
  Zelda64Recomp later, since the two repos' N64ModernRuntime pins have
  drifted.

## Patching a pinned submodule (`patches/`)

Almost nothing in `deps/` needs patching — see the next section, and the
project rule of thumb in `CLAUDE.md` ("prefer fixing on our side over patching
`deps/`"). Exactly one change does not have a seam on our side:
**`patches/n64modernruntime-orderly-shutdown.patch`**, which stops and joins
the game's own threads before `recomp::start()` frees RDRAM. Everything that
needed changing (the scheduler's yield points, the thread registry, the
teardown order in `recomp::start()`) is inside librecomp/ultramodern, between
the point the gfx thread returns and the point `main()` regains control.

**How it is carried.** `deps/N64ModernRuntime` stays pinned at its upstream
SHA and the fix lives as an *uncommitted working-tree modification* of the
submodule. The reviewable source of truth is the patch file; the submodule
pointer in this repo still names a commit that exists upstream. Committing a
local submodule commit instead would leave a dangling SHA that nobody else
could fetch — a clone would fail at `git submodule update`.

**How it is applied.** Top-level `CMakeLists.txt` calls
`ke_apply_dep_patch()` at configure time, just before
`add_subdirectory(deps/N64ModernRuntime ...)`. It is idempotent:

1. `git apply --reverse --check` succeeds → already applied, do nothing.
2. otherwise `git apply --check` succeeds → apply it.
3. otherwise `FATAL_ERROR` — the submodule has diverged from the SHA the
   patch was written against. Recover with
   `git -C deps/N64ModernRuntime checkout -- .` and re-run cmake, or
   regenerate with `git -C deps/N64ModernRuntime diff > patches/...`.

So a fresh clone + `cmake -B build` gets the fix automatically, and a
developer who edits the submodule by hand is told rather than silently
overruled.

**Keeping it honest.** `git -C deps/N64ModernRuntime diff` must always be
byte-identical to the patch file. If you change the deps code, regenerate the
patch in the same commit.

**This is temporary.** The patch is written as an upstream PR would be —
generic naming, no Knife Edge specifics, comments explaining the mechanism —
because upstream (N64Recomp/N64ModernRuntime) has no fix for this and should
have one. When it lands upstream, bump the submodule and delete both the patch
file and the `ke_apply_dep_patch()` call.

## Dependency quirks / workarounds (no other submodule patches needed)

Nothing else in `deps/` needed patching — everything below is a CMake
cache-variable set from the top-level `CMakeLists.txt`, which is the
sanctioned way to influence a vendored subdirectory without touching it.

- **`nativefiledialog-extended` (pulled in unconditionally by `rt64`) wants
  GTK3 or dbus on Linux.** This devcontainer has no GTK3 dev headers
  (`pkg-config gtk+-3.0` fails) but does have `dbus-1`. Top-level
  `CMakeLists.txt` sets `set(NFD_PORTAL ON CACHE BOOL "" FORCE)` on Linux
  before `add_subdirectory(deps/rt64 ...)`, which makes `nfd` build its
  `nfd_portal.cpp` (xdg-desktop-portal) backend instead of `nfd_gtk.cpp`.
  Confirmed via configure log: `Using DBUS version: 1.16.2`.
- **RT64's shader-building `add_custom_command`s invoke the vendored
  `dxc-linux`/`spirv-cross` binaries via
  `COMMAND "LD_LIBRARY_PATH=..." "path/to/dxc-linux" ...`** — this only
  works because CMake's Ninja generator runs custom commands through a
  shell, so the `VAR=VAL` prefix is interpreted as an env-var assignment by
  `sh -c`, not passed as a literal argv[0]. Worth knowing if this ever moves
  to a generator that doesn't shell out custom commands (e.g. some remote
  execution setups).
- **`SDL_GetError()` returns a pointer into SDL's internal mutable error
  buffer, not an owned string.** Found this the hard way during the runtime
  smoke test: `main.cpp`'s original `exit_error(SDL_GetError())` passed that
  raw pointer through to a function that itself made further SDL calls
  (`SDL_ShowSimpleMessageBox`, which fails and overwrites the error buffer
  under the container's headless `dummy` video driver) before the message
  was ever printed — so the *original* error got silently replaced with
  `SDL_ShowSimpleMessageBox`'s own failure text ("No message system
  available"). Fixed by changing `exit_error` to take the message by
  `std::string` value instead of `const char*`, forcing a copy at the call
  site before any further SDL calls can happen. General lesson: never hold
  onto an `SDL_GetError()` pointer across another SDL call.
- **Own bug, not a dependency one**: `kerecomp::get_app_folder_path()`
  originally returned `current_path() / "KnifeEdgeRecompiled"` — when run
  from the build directory, that collides with the executable's own
  filename (`build-shim/KnifeEdgeRecompiled` the directory vs.
  `build-shim/KnifeEdgeRecompiled` the binary), and
  `recomp::mods::initialize_mods()`'s `create_directories()` throws
  `std::filesystem::filesystem_error` trying to treat the binary as a
  directory. Renamed the config folder to `ke_recomp_data` to avoid any
  name collision with the executable.

## Containerized build

Added so CI and local development share one toolchain definition instead of
three copy-pasted apt-get lists (one per CI job) plus the devcontainer's own
fourth copy. Two files carry the whole design:

- **`containers/Containerfile`** — the canonical toolchain. Base
  `debian:trixie-slim`, chosen to match
  `.devcontainer/devcontainer.json`'s `mcr.microsoft.com/devcontainers/base:trixie`
  base image exactly, so there is zero toolchain drift between "the
  environment everything has been tested in" (the devcontainer) and "the
  environment CI/release builds run in" (this image). Single apt layer,
  package list is the union of what the three CI jobs and the devcontainer's
  `postCreateCommand` install, minus pure dev conveniences. Two additions
  beyond that union that are worth flagging explicitly: `bc` and `procps`.
  Neither appears in any existing CI job's package list or in the
  devcontainer's `postCreateCommand`, because no existing CI job runs
  `scripts/smoke_test.sh` (self-hosted/local only) — but that script uses
  `ps -p $PID` (procps) and `bc -l` (the audio-nonzero-percentage float
  compare), so `--smoke` would fail without them. The devcontainer's base
  image is a much fuller image than `debian:trixie-slim` and evidently
  already carries both, which is exactly why its `postCreateCommand` never
  needed to ask for them — the gap only became visible once a truly minimal
  base was used. A second venv (`/opt/ke-pyenv`, `pip install rabbitizer
  capstone tomlkit`) is put first on `PATH`, so plain `python3`/`python`
  invocations anywhere in the build resolve to it without needing a
  repo-relative `.venv/`. No `USER`/`ENTRYPOINT`: the run-time identity and
  command are entirely `scripts/container_build.sh`'s call, not baked into
  the image.
- **`scripts/container_build.sh`** — the one script both developers and CI
  invoke. It detects a runtime (`$KE_CONTAINER_RUNTIME`, else podman, else
  docker), builds `containers/Containerfile` into an image tagged
  `knife-edge-build:<sha256 of the Containerfile, first 12 hex>` (so a
  Containerfile edit always produces a new tag rather than silently reusing
  a stale image), and runs the build inside it.

**Build-dir isolation.** The container always builds into
`deps/N64Recomp/build-container/` and `build-container/` — never
`deps/N64Recomp/build/`, `build/`, or `build-shim/`, which is what a native
host build (Option B) or the devcontainer (Option A) uses. This is not
incidental: the container's clang/lld/libc are a different toolchain than
whatever the host has, and letting the two share a CMake binary dir would
produce a build that half-belongs to each — stale object files, an ABI
mismatch, or a `CMakeCache.txt` pointing at compilers that no longer agree
with each other. Every path the script writes to is named `*-container` for
exactly this reason.

**ROM handling.** The ROM is never baked into the image — the script mounts
it read-only at `/rom/rom.n64` (`-v <abspath>:/rom/rom.n64:ro`) only when
`--rom` is given, and only for that one container invocation (`--rm`, so
nothing persists). This mirrors the repo-wide policy (README.md
"Repository policy") that the ROM and anything derived from it never enters
committed/durable storage.

**A subtler .venv hazard, and how it's handled.** Both `CMakeLists.txt`
(`KE_PYTHON` prefers `${CMAKE_SOURCE_DIR}/.venv/bin/python` over
`find_program(python3)`) and `analysis/Makefile` (`PY :=
$(ROOT)/.venv/bin/python`, unconditionally) hardcode a repo-relative
`.venv/`. The container bind-mounts the *whole* repo at `/work`, so if the
host checkout happens to carry its own `.venv/` (common on a machine that's
also done native builds — this workspace is a live example), that host venv
would come along for the ride and get silently preferred over the
container's own `/opt/ke-pyenv`, even though it may be built against a
different libc/interpreter ABI than the container's. Handled with explicit
overrides, not mounts: `CMakeLists.txt` guards its auto-detect with
`if (NOT KE_PYTHON)` so `scripts/container_build.sh` can pass
`-DKE_PYTHON=/opt/ke-pyenv/bin/python`, and the regen-verify recipe passes
`PY=/opt/ke-pyenv/bin/python` on the `make -C analysis` command line
(command-line assignments beat the Makefile's `:=`). A clean CI checkout
never has a `.venv/` at all (it's gitignored), so both overrides are
no-ops there; they only matter for local container builds against an
existing working tree.

*Rejected first attempt, kept for the record:* a
`--tmpfs /work/.venv:...,size=16m` shadow mount over the host venv failed
on the owner's host at first real run — crun applies `tmpcopyup` to tmpfs
mounts, i.e. it **copies the underlying directory's contents into the new
tmpfs**, and the 95 MB host venv overflowed the 16 MB tmpfs:
`crun: write: No space left on device` at container start, with terabytes
actually free. Docker doesn't copy up at all, so the mount also behaved
differently per runtime. Explicit overrides have neither problem.

**Podman/SELinux run flags.** `--userns=keep-id --security-opt label=disable`
for podman are lifted verbatim from
`.devcontainer/devcontainer.json`'s `runArgs`, where they're already proven
on the project owner's rootless-podman/SELinux (Fedora) host: `keep-id`
lines up the host uid inside the container so the mounted source is
container-user-owned instead of root-owned, and `label=disable` opts out of
SELinux label separation, which otherwise denies `container_t` access to
the host's `user_home_t`-labelled source. Docker instead gets
`--user "$(id -u):$(id -g)")`, which needs no SELinux workaround.

**CI integration.** `.github/workflows/build.yml`'s three jobs each call
`scripts/container_build.sh` instead of an inline apt-get/cmake recipe:
`build` uses `--check` (build + the no-ROM graceful-failure assertion),
`release` uses `--rom <path>` (build only; the asset-leak check runs
separately, directly on the runner, since it only needs the stdlib),
`regen-verify` uses `--rom <path> --exec '<script>'` to run the analysis
pipeline's regen-and-diff recipe inside the container. Caching is keyed on
`hashFiles('containers/Containerfile')` in place of the old literal
`clang19` string, so a toolchain change (image edit) busts the cache exactly
like a submodule bump does. The `build` and `release` jobs deliberately do
NOT share a `build-container/` cache under the same key formula: `release`
always configures with `-DKE_ROM=...` and `build` never does, and since the
cache key doesn't encode that distinction, sharing it risks one job's stub
configure silently winning the cache slot for the other's ROM-driven one.
Only the ROM-independent `deps/N64Recomp/build-container/` (the host tools)
is shared between them. No registry push/pull machinery was added — the
image builds fresh (well, cached by the runner's local docker/podman image
store within a run, but not across runs) each time; see "Future work" below.

### Future: unify with `.devcontainer`

`.devcontainer/devcontainer.json` was deliberately left untouched by this
work — it's the project owner's live, daily-use environment, not something
to risk destabilizing while the container-build design was still settling.
It now duplicates a chunk of `containers/Containerfile`'s package list (both
trace back to the same underlying toolchain needs) and the same
podman/SELinux run-flag knowledge (both files cite the same rationale). The
obvious next step, once the Containerfile has had some real mileage, is to
point the devcontainer at the same image — e.g. `"build": {"dockerfile":
"../containers/Containerfile"}` in `devcontainer.json` — so there is
exactly one toolchain definition instead of two that merely agree today by
manual upkeep.

### Future: registry caching

Right now every CI run builds `containers/Containerfile` from scratch (the
apt layer costs roughly 2-4 minutes) since nothing pushes the resulting
image anywhere durable. If CI minutes become a concern, the obvious speedup
is to push the image to a registry (GHCR is the natural choice given this
already lives on GitHub) tagged by the same Containerfile-hash scheme
`scripts/container_build.sh` already uses locally, and have the workflow
pull-if-present before falling back to building. Deliberately not done yet:
it adds a registry-auth/push surface to a workflow that currently needs
none, and the config surface here is still young enough that keeping the
workflow thin seemed more valuable than the minutes saved.

## Flatpak packaging

`packaging/flatpak/io.github.haydenmc.KnifeEdgeRecompiled.yml` +
`scripts/build_flatpak.sh`. Design decisions:

- **Runtime: `org.freedesktop.Platform`/`Sdk` 24.08 + the `llvm18` SDK
  extension.** Same clang-based toolchain this project already builds with
  everywhere else (devcontainer, `containers/Containerfile`), just sourced
  from the Flatpak SDK instead of apt. `build-options` puts
  `/usr/lib/sdk/llvm18/bin` on `PATH` and its `lib/` on the linker's runtime
  search path, and `config-opts` forces `-fuse-ld=lld` (matching this
  project's other build paths, which all use lld over the Sdk's default
  bfd/gold).
- **`dir` source over pre-generated code, not `git`.** flatpak-builder's
  sandboxed build has no network access and no ROM, so it can neither fetch
  git submodules (`deps/`) nor run the analysis pipeline
  (`analysis/byteswap.py` + `analysis/gen_syms.py`) nor invoke the
  N64Recomp/RSPRecomp host tools — all three require either the internet or a
  ROM the sandbox will never have. A `type: dir, path: ../..` source sidesteps
  all of that: flatpak-builder copies the *already-checked-out* working tree
  verbatim (submodules included, since they're just directories under
  `deps/` once initialized) into `/run/build/<module-name>/`, gitignored
  `generated/` included. `-DKE_GENERATED_DIR=/run/build/knife-edge-recompiled/generated/us`
  points the build at that copy directly, which — confirmed by reading
  `CMakeLists.txt` — needs neither python nor the N64Recomp/RSPRecomp host
  tools: those only run inside the `if (KE_ROM)` block, and this module
  never sets `KE_ROM`. `find_package(Git QUIET REQUIRED)` does still run
  unconditionally (for `patches/n64modernruntime-orderly-shutdown.patch` and
  the build-stamp commit), so the module needs `git` inside the sandbox;
  `org.freedesktop.Sdk` carries it. The `dir` source copies the whole
  working tree, `.git` included (no `skip:` field exists for `dir` sources
  in the flatpak-builder version this was written against) — around 1 GB
  with `deps/`'s vendored contrib libraries, accepted as the cost of not
  needing network access. **Flathub distribution is out of scope for this
  manifest** and would need a different source strategy entirely (Flathub's
  build service has no access to a `dir` source pointing outside the
  manifest's own repo, and typically expects reproducible `git`/archive
  sources it can fetch itself).
- **No `install()` rules in `CMakeLists.txt`** (this is a build-system
  skeleton by design, see its header comment), so `ninja install` — what
  flatpak-builder's `cmake-ninja` buildsystem runs by default — is a
  harmless no-op. The manifest's `post-install` does the placement by hand:
  binary to `/app/bin/knife-edge-recompiled-bin`, the wrapper script
  (below) to `/app/bin/knife-edge-recompiled.sh` (the `command:`), desktop
  file, AppStream metainfo, and the hicolor SVG icon. Paths there are
  relative to flatpak-builder's cmake-ninja build directory, which its
  `cmake-ninja`/`cmake` buildsystem creates at `_build/` under the module's
  source root — **not independently verified in this sandbox** (no
  flatpak-builder here; see the manifest's own comment on this and re-check
  on the first real build).
- **Portal ROM picker enables zero filesystem `finish-args`.** Every other
  Flatpak-packaged emulator/recompilation port either ships copyrighted data
  (not an option here) or asks for a broad `--filesystem=host` grant just to
  read one ROM file the user already owns. `src/main/main.cpp` instead calls
  `NFD_OpenDialogU8` (nativefiledialog-extended, already linked into this
  binary via `rt64` — see "Dependency quirks" above) when no ROM is cached,
  a display is present, and — new for this work — the portal is actually
  reachable (see below); the chosen path is fed through the exact same
  `select_rom()` validation `--rom` uses. A portal-mediated file pick needs
  no Flatpak permission at all, which is why `finish-args` in the manifest
  carries no `--filesystem=*` of any kind — that absence is the point, not
  an oversight.
  - **Verified hazard #1 (fixed): `NFD_Quit()` after a failed `NFD_Init()`
    aborts the process.** NFD's portal backend calls
    `dbus_connection_unref()` unconditionally inside `NFD_Quit()`, on a
    connection that only exists if `NFD_Init()` actually returned
    `NFD_OKAY` — nfd.h's own doc comment says as much ("Call this to
    de-initialize NFD, if NFD_Init returned NFD_OKAY"), but violating it
    aborts rather than failing soft. This is the same shape as the
    already-known "RT64-bundled nativefiledialog null-dbus abort" issue
    (CLAUDE.md open items; `RT64::FileDialog::initialize()`/`finish()` in
    `deps/rt64/src/gui/rt64_file_dialog.cpp`, called unconditionally at
    `RT64Application` startup/shutdown, has the *same* unguarded pairing —
    that one is pre-existing RT64 code, out of scope for this work, and
    still a candidate upstream report). Our own new call site guards it:
    `NFD_Quit()` in `main.cpp` is reachable only from inside the
    `NFD_Init() == NFD_OKAY` branch.
  - **Verified hazard #2 (fixed): NFD's portal `OpenFile` call can hang
    forever with no portal service present.** `nfd_portal.cpp`'s
    `NFD_DBus_OpenFile()` calls
    `dbus_connection_send_with_reply_and_block(..., DBUS_TIMEOUT_INFINITE,
    ...)` — confirmed by reading it — so under a live X/Wayland display
    with a working D-Bus session but no `xdg-desktop-portal` service and no
    D-Bus activation entry for it (reproduced here: a bare Xvfb + a plain
    `dbus-run-session`, no portal package installed at all), that call
    never returns and the process wedges permanently. A wall-clock timeout
    around the NFD call would be the wrong fix — a *real* portal dialog is
    supposed to block indefinitely, for as long as the user takes to pick a
    file. Instead, `main.cpp`'s `portal_reachable()` asks the **local D-Bus
    daemon** (never the portal process itself) two fast questions before
    ever calling `NFD_Init()`: does `org.freedesktop.portal.Desktop`
    currently have an owner (`dbus_bus_name_has_owner`), or is it at least
    D-Bus-activatable (`ListActivatableNames` — the common case, since
    `xdg-desktop-portal` is normally not running until first asked for;
    this is exactly how a Flatpak sandbox's proxied session bus looks). Both
    answers come from the daemon's own registry, so they return promptly
    even when no portal exists anywhere — confirmed by `strace`: the whole
    round trip takes well under a millisecond. If neither is true, the
    picker is skipped entirely and control falls straight through to the
    ordinary no-ROM error, unchanged. This needs a second, independent
    `pkg_check_modules(... dbus-1)` in `CMakeLists.txt` for
    `KnifeEdgeRecompiled` itself: `nativefiledialog-extended` already
    depends on `dbus-1` too, but links it `PRIVATE`
    (`nativefiledialog-extended/src/CMakeLists.txt`), so that dependency
    isn't visible to us transitively through `rt64`.
  - **A third, separate, pre-existing behavior surfaced by testing this:**
    the fatal-error path (`exit_error()` → `show_error_message_box()` →
    `SDL_ShowSimpleMessageBox`) shows a genuinely *modal* dialog under any
    live X/Wayland display, which SDL implements by forking a child process
    that blocks until a human dismisses it. Under a real desktop (or inside
    a real Flatpak sandbox, which always has a compositor and a user) this
    is exactly the intended, correct behavior. Under a bare Xvfb with no
    window manager and no human (this project's own automated verification
    harness, not a real deployment target), that dialog can never be
    dismissed and the process appears to hang — confirmed to be unrelated
    to the two hazards above (verified via `strace`: no further NFD/D-Bus
    activity after the picker is skipped) and confirmed to resolve cleanly
    (exit 1) the instant the dialog is dismissed (via `xdotool key ...
    Return` in testing). Not fixed here — it's a property of
    `show_error_message_box()` shared by every fatal-error call site in
    this project, not something introduced by the ROM picker, and it never
    affects CI or the real no-ROM contract (no `DISPLAY` at all → SDL's
    message box fails immediately and falls back to stderr, confirmed:
    exit 1 in ~5 ms). Left as a candidate follow-up (CLAUDE.md open items).
- **`KE_DATA_DIR`.** `src/main/support.cpp`'s `get_app_folder_path()` now
  honors this env var when set (falls back to the pre-existing
  CWD-relative default otherwise, so nothing changes for non-Flatpak
  builds). `packaging/flatpak/knife-edge-recompiled.sh` (the manifest's
  `command:`) sets it to `$XDG_DATA_HOME/knife-edge-recompiled`, which
  inside the sandbox is `~/.var/app/<appid>/data/knife-edge-recompiled` —
  stable across app updates, unlike the working directory Flatpak launches
  the command from.

## Open problems / TODOs left for later work

- `N64RECOMP_HOST_TOOL`/`RSPRECOMP_HOST_TOOL` are imported by path, not
  built from source as part of this configure (see TODO(superbuild) comment
  in `CMakeLists.txt`). Fine for now since `deps/N64Recomp/build/` already
  exists in this devcontainer.
- `GameEntry.rom_hash`, `.save_type`, and `.game_id` in `src/main/main.cpp`
  are explicit TODO placeholders (see the comment block right above the
  `GameEntry` initializer) — `rom_hash` needs `XXH3_64bits()` over the
  verified ROM once one is confirmed, `save_type` needs the save mechanism
  identified from further ROM analysis, `game_id` is just an internal
  key and can stay as-is. `entrypoint_address = 0x800C2400` is **not** a
  TODO — that's an established fact from `n64recomp-formats.md` (CIC 6102
  boot mapping).
- No ROM picker: `recomp::start_game()` is never called, so
  `recomp_entrypoint` (real or stub) never actually runs yet — the runtime
  comes up, opens a window, initializes RT64, and idles. Confirmed safe via
  the `wait_for_game_started` codepath in `librecomp/src/recomp.cpp`
  (blocks on a `game_status` that only changes via `start_game`).
- No audio/input/config-persistence — all corresponding `callbacks_t`
  structs are left default-constructed (all-`nullptr` function pointers);
  every callsite in `ultramodern`/`librecomp` that reads them null-checks
  first, confirmed by reading `ultramodern/src/{audio,input,threads,
  error_handling}.cpp`.
