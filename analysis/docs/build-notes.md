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

**CI integration.** `.github/workflows/build.yml`'s ROM-independent `build`
job and its three ROM-needing jobs (`linux-build`, `flatpak-build`,
`regen-verify` — renamed from `release`/`flatpak-release`/`regen-verify`
respectively as part of the 2026-07-31 CI restructure that made same-repo
PRs produce full artifacts, see "Encrypted ROM in CI" below) each call
`scripts/container_build.sh` instead of an inline apt-get/cmake recipe:
`build` uses `--check` (build + the no-ROM graceful-failure assertion),
`linux-build` uses `--rom <path> --smoke` (build, then the full
Xvfb/lavapipe smoke test *inside* the container — previously smoke-testing
was local/self-hosted only; the asset-leak check still runs separately,
directly on the runner, since it only needs the stdlib — see
`scripts/assert_no_rom_assets.py`, shared verbatim with `flatpak-build`),
`regen-verify` uses `--rom <path> --exec '<script>'` to run the analysis
pipeline's regen-and-diff recipe inside the container. The ROM fetch+decrypt
steps that used to be duplicated across all three ROM-needing jobs (install
age, then `scripts/fetch_rom.sh`) are now the single composite action
`.github/actions/fetch-rom/action.yml`; composite actions can't read the
`secrets` context directly, so each caller passes the four secret values
through as `with:` inputs (GitHub's log masking is by value, not by context
path, so this doesn't weaken masking). Caching is keyed on
`hashFiles('containers/Containerfile')` in place of the old literal
`clang19` string, so a toolchain change (image edit) busts the cache exactly
like a submodule bump does. The `build` and `linux-build` jobs deliberately
do NOT share a `build-container/` cache under the same key formula:
`linux-build` always configures with `-DKE_ROM=...` and `build` never does,
and since the cache key doesn't encode that distinction, sharing it risks
one job's stub configure silently winning the cache slot for the other's
ROM-driven one — see "Encrypted ROM in CI" below for a second, more serious
reason `build-container/` must never be cached from a ROM-driven job at all.
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

- **Runtime: `org.freedesktop.Platform`/`Sdk` 25.08 + the `llvm20` SDK
  extension.** Same clang-based toolchain this project already builds with
  everywhere else (devcontainer, `containers/Containerfile`), just sourced
  from the Flatpak SDK instead of apt. `build-options` puts
  `/usr/lib/sdk/llvm20/bin` on `PATH` and its `lib/` on the linker's runtime
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

## Encrypted ROM in CI (Backblaze B2)

### Motivation

Every ROM-needing job (originally named `release`, `regen-verify`,
`flatpak-release`) used to be gated to `workflow_dispatch` and require
either a `rom_path` pointing at a ROM already sitting on the runner's
filesystem, or (for `flatpak-release`) a repository variable `KE_ROM_PATH`
doing the same — which in practice meant a self-hosted runner the project
owner controlled, since GitHub-hosted runners start with an empty,
ephemeral filesystem and no ROM can legally live in the repo. That worked
but had real costs: it required maintaining a self-hosted runner at all (a
machine to keep patched, online, and secure), and it meant `regen-verify` —
the proof that the analysis pipeline regenerates exactly what's committed
in `config/` — only ran when someone remembered to dispatch it by hand, not
on every change that could plausibly affect it.

This work replaces all of that with an age-encrypted ROM fetched from
owner-controlled cloud storage (Backblaze B2 in practice) and decrypted
in-run on a plain hosted `ubuntu-latest` runner. Consequences: `regen-verify`
now runs continuously, on every push to `main` (plus manual dispatch)
instead of only when hand-triggered; `release` and `flatpak-release` no
longer need a self-hosted runner at all; and there is no self-hosted runner
anywhere in `.github/workflows/build.yml` any more.

A second restructure (2026-07-31) went further: `release` and
`flatpak-release` were renamed `linux-build` and `flatpak-build` and moved
off manual-dispatch/tag-push-only gating onto the same trigger set as
`regen-verify` — same-repo pull request, push to `main`, version tag, or
manual dispatch, wherever `rom-gate` finds the secrets configured — so every
PR now produces a downloadable tarball and Flatpak bundle artifact, not just
tagged releases. Publishing those artifacts to an actual GitHub release
stayed tag-triggered, but moved into a new, separate `publish` job that
holds the workflow's only write-permission grant (see "The flatpak-on-hosted
specifics" below, and the composite action note under "CI integration"
above, for what else changed in that pass).

### Design

**age, not ad-hoc `openssl`.** [age](https://age-encryption.org/) is
authenticated encryption (ChaCha20-Poly1305 under the hood): a wrong key,
corrupted upload, or wrong object all fail loudly at decrypt time rather
than silently producing garbage bytes that only fail later at some unrelated
step (e.g. the md5 gate, or worse, a confusing build failure three steps
downstream). Just as importantly, age's X25519 recipients are asymmetric —
the owner encrypts with a *public* key, CI only ever holds the *private*
identity. That means re-encrypting and re-uploading a new ciphertext (a ROM
revision, or just re-keying) never requires touching a single GitHub secret;
the existing `KE_ROM_AGE_KEY` keeps working against any ciphertext encrypted
to the matching public key. An ad-hoc symmetric scheme (`openssl enc
-aes-256-cbc -k "$PASSWORD"`) would tie the secret and the ciphertext
together — rotating either means updating both, and unauthenticated modes
like plain CBC don't fail cleanly on a wrong key or corrupted stream, they
just decrypt to noise.

**Ciphertext-only in the bucket.** The bucket (or plain URL, if the
`KE_B2_*` secrets are omitted) never holds anything but the `age`-encrypted
blob. There is no plaintext ROM anywhere outside the owner's own machine and
each CI job's `$RUNNER_TEMP`.

**`scripts/fetch_rom.sh` contract.** `scripts/fetch_rom.sh <output-path>`,
required env `KE_ROM_URL` (any curl-fetchable URL — https in CI, http/file
for local testing) and `KE_ROM_AGE_KEY` (the age identity line), optional
`KE_B2_KEY_ID`/`KE_B2_APP_KEY` pair (must be set together or neither) for a
signed fetch against a private B2 bucket. It downloads the ciphertext to a
`mktemp` file, decrypts with `age -d`, gates the plaintext against the exact
two md5 hashes in `KNOWN_MD5` in `analysis/byteswap.py` (either the v64
byteswapped dump or the z64 normalized dump — this script doesn't normalize
byte order itself, the build's own `analysis/byteswap.py` ingestion step
does that later, so either dump order passing here is fine), and only then
`chmod 600` + atomically `mv`s the plaintext into place (the intermediate
plaintext temp file is created in the *same directory* as the output path
specifically so that final `mv` is a same-filesystem rename, not a copy —
see the script's own comments for why). A `trap ... EXIT` removes every temp
file it created, on both success and failure paths. It never prints
`KE_ROM_URL` or any of the four secret env vars, on any path, including
errors — there is no `set -x` anywhere in it, deliberately.

**Private-bucket support via curl's native SigV4, deliberately no B2/AWS
CLI.** When `KE_B2_KEY_ID`/`KE_B2_APP_KEY` are set, the script requires
`KE_ROM_URL` to be B2's S3-compatible endpoint, in either style —
path-style `https://s3.<region>.backblazeb2.com/<bucket>/<file>` or
virtual-hosted `https://<bucket>.s3.<region>.backblazeb2.com/<file>` (the
"S3-friendly URL" the B2 web UI hands out; SigV4 signs the Host header, so
bucket-in-host vs bucket-in-path makes no difference to curl). B2's
"friendly" native URL (`f00N.backblazeb2.com/file/...`) is rejected with a
clear error — SigV4 can't address it. The script parses the region out of
the host either way,
and adds `--user "$KE_B2_KEY_ID:$KE_B2_APP_KEY" --aws-sigv4
"aws:amz:<region>:s3"` to the curl call. `--aws-sigv4` has been in curl
since 7.75 (2021); GitHub-hosted runners carry curl 8.x, so no version
detection is needed. The point of doing it this way instead of installing
the B2 CLI or the AWS CLI is that this script then runs anywhere with `curl`
and `age` on `PATH` — no additional CLI dependency, no Python SDK, works
identically in this workflow and in a bare local test with
`python3 -m http.server`.

### Threat model

Confidentiality lives in the encryption, not in the bucket's access control.
A leaked `KE_ROM_URL` — logged accidentally somewhere, or a bucket
misconfigured to public-read — leaks only ciphertext; without
`KE_ROM_AGE_KEY` (which never leaves GitHub's encrypted secrets store and is
never printed by this script) that ciphertext is useless. The private
bucket plus a read-only application key scoped to that one bucket is
defense in depth on top of that, not the primary control — worth doing
(it also caps blast radius if the B2 credentials themselves ever leaked:
read-only, one bucket), but the design does not depend on it. GitHub itself
masks any string that equals a configured secret's value in job logs, and
`scripts/fetch_rom.sh` independently never echoes `KE_ROM_URL` or any of the
three other secret env vars (the *md5* of the decrypted plaintext, printed
on a mismatch, is not secret — it's just a hash of already-public game
data, useful for diagnosing "wrong file uploaded").

Decrypted plaintext exists only in `$RUNNER_TEMP` — a directory GitHub
Actions creates per-job, outside the workspace, outside every
`actions/cache` and `actions/upload-artifact` path, and wiped when the job
ends. It's mounted read-only into the build container
(`scripts/container_build.sh --rom` already did this for local ROMs; nothing
changed there). It is never written into the git working tree except
transiently, inside the `regen-verify`/`flatpak-build` `--exec` scripts,
as `build/knife_edge.z64` — the normalized copy `analysis/byteswap.py`
produces, which was already how those recipes worked before this change and
remains outside git (`build/` is gitignored) either way.

There is a second cache-related exposure the design has to avoid, distinct
from the `secrets` context problem above: `actions/cache` entries saved from
a run on the default branch are restorable by workflow runs triggered from a
fork PR. `linux-build`'s `build-container/` directory contains
`knife_edge.z64` (the decrypted, normalized ROM) whenever that job ran with
`-DKE_ROM=...`, so that directory must never be cached under a key a fork PR
run could hit — caching it would hand the ROM to arbitrary fork-authored
code. This is on top of, not instead of, the pre-existing key-collision
reason (`build` vs. `linux-build` configuring CMake differently under what
would otherwise be the same cache key formula) documented under "CI
integration" above. Path-excluding just the `.z64` from the cached directory
was considered and rejected as too fragile to bet the policy on; the only
robust rule is that `build-container/` is never cached from a ROM-driven job
at all, full stop.

Fork PRs get no secrets — GitHub's own rule, unrelated to anything in this
design — so ROM-needing jobs must not simply fail when the secrets are
absent; they must skip. The complication: a job-level `if:` condition cannot
read the `secrets` context directly (GitHub Actions restricts `secrets` to
`env:`/`with:`/`run:` inside steps). `rom-gate` works around this: one small
job whose single step reads `secrets.KE_ROM_URL`/`KE_ROM_AGE_KEY` via `env:`
and republishes the boolean as a `steps.check.outputs.have` job output,
which downstream jobs' `if:` conditions *can* read via `needs.rom-gate.outputs.have`.
Every ROM-needing job now `needs: rom-gate` and gates on that output.

### The flatpak-on-hosted specifics

Three things `flatpak-build` (renamed from `flatpak-release` in the
2026-07-31 restructure — see "Motivation"/"Design" above) needed that the
other ROM-jobs didn't, all because it's the first job in this workflow to
run `flatpak-builder` on a GitHub-hosted runner rather than a machine the
owner had already tuned by hand:

- **AppArmor userns sysctl for bwrap.** Ubuntu 24.04 runner images restrict
  unprivileged user namespaces via AppArmor by default (a hardening change
  upstream Ubuntu shipped and GitHub's runner images inherited), which
  breaks `bubblewrap` — the sandboxing tool `flatpak-builder` requires for
  every build step. The fix is one `sysctl -w
  kernel.apparmor_restrict_unprivileged_userns=0`, tolerantly `||`-guarded
  in case some future runner image removes the knob entirely (rather than
  failing the job over a hardening detail that stopped applying).
- **The flathub runtime cache.** `org.freedesktop.Platform`/`Sdk` 25.08 plus
  the `llvm20` extension is roughly 1.5 GB from flathub — fine once, wasteful
  on every run. `actions/cache@v4` over `~/.local/share/flatpak`, keyed on a
  hash of the manifest file itself (so a runtime-version bump in the
  manifest correctly busts the cache instead of silently reusing a stale
  runtime), makes every run after the first a fast no-op through
  `scripts/build_flatpak.sh --runtime-install`.
- **The `dir`-source staging hazard, and the quarantine step.** As covered
  under "Flatpak packaging" above, the manifest's `type: dir` source copies
  the *entire* checked-out working tree into flatpak-builder's sandbox, with
  no exclusion mechanism. On a self-hosted runner this was already true, but
  it mattered less: the owner's own machine, ROM handling already scoped to
  that one job. On a shared, ephemeral hosted runner the same staging is
  worth actively defending: by the time `generated/us` exists,
  `build/knife_edge.z64` — a decrypted, normalized copy of the ROM — is
  sitting in the working tree too, and without intervention it would get
  copied into `/run/build/knife-edge-recompiled/` inside the sandbox along
  with everything else. It was never *installed* into `/app` (no
  `install()` rule touches it — see "Flatpak packaging" above), so it never
  reached the actual `.flatpak` bundle either way, but staging it into the
  sandbox is still more exposure than this project's ROM-handling policy
  allows. The `flatpak-build` job's "Quarantine ROM-derived files out of
  the source tree" step runs *between* generating sources and invoking
  `scripts/build_flatpak.sh`: it moves `build/knife_edge.z64` out to
  `$RUNNER_TEMP` (kept only so the final asset-leak assertion still has
  something to sample against) and `rm -rf`s `build/` and `build-container/`
  entirely before flatpak-builder ever runs.
- **The bundle-binary asset assertion.** Same shared script as `linux-build`'s
  `Assert the binary embeds no game assets` step —
  `scripts/assert_no_rom_assets.py`, 400 random 64-byte slices of the ROM's
  data region, checked for exact containment in the binary — just pointed at
  flatpak-builder's own build tree layout
  (`build-flatpak/build/files/bin/knife-edge-recompiled-bin`) and at the
  quarantined ROM copy in `$RUNNER_TEMP` instead of `build-container/`'s. A
  `test -f` guard fails loudly with a clear `::error::` if that path ever
  turns out to be wrong (flatpak-builder's internal build-directory layout is
  not something this project controls), rather than the assertion silently
  no-oping on a missing file. (Both jobs used to carry their own copy of this
  check as an inline Python heredoc; the 2026-07-31 restructure extracted it
  into the one shared script so the two copies couldn't drift apart.)

Publishing the bundle to a GitHub release is no longer this job's
responsibility: `flatpak-build` ends at `actions/upload-artifact` (name
`KnifeEdgeRecompiled-flatpak`), and it no longer carries a `permissions:
contents: write` grant at all. The separate `publish` job (tag pushes only)
downloads that artifact by name, alongside `linux-build`'s tarball artifact,
and is the sole place in the workflow that calls `gh release create`/`gh
release upload` — see "Motivation"/"Design" above.

### Owner setup

One-time, done on the owner's own machine — nothing here ever touches CI:

```sh
age-keygen -o ke_rom.agekey        # prints "Public key: age1..."; keep this file OFFLINE, never in the repo
age -r age1<publickey> -o knifeedge.z64.age <path-to-rom>
# B2: create a PRIVATE bucket, upload knifeedge.z64.age (web UI or b2 CLI)
# B2: create an application key, READ-ONLY, scoped to that one bucket
# GitHub repo secrets (Settings → Secrets and variables → Actions):
#   KE_ROM_URL     = https://s3.<region>.backblazeb2.com/<bucket>/knifeedge.z64.age
#                    (or the bucket's "S3-friendly URL" from the B2 web UI:
#                     https://<bucket>.s3.<region>.backblazeb2.com/knifeedge.z64.age)
#   KE_ROM_AGE_KEY = the AGE-SECRET-KEY-1... line from ke_rom.agekey
#   KE_B2_KEY_ID   = the application keyID
#   KE_B2_APP_KEY  = the application key itself
# (public-bucket alternative: skip the two KE_B2_* secrets and use the
#  bucket's friendly URL — the ciphertext is the protection either way)
```

### Local test recipe

No B2 bucket needed to exercise the script end-to-end — a loopback HTTP
server is enough:

```sh
age-keygen -o test.agekey                       # note the "Public key: age1..." line
age -r age1<publickey> -o rom.age /path/to/a/known-dump/rom
python3 -m http.server 8099 &                    # serves the cwd; rom.age must be in it
KE_ROM_URL=http://127.0.0.1:8099/rom.age \
KE_ROM_AGE_KEY="$(grep AGE-SECRET-KEY test.agekey)" \
  scripts/fetch_rom.sh /tmp/knife_edge.rom
```

A wrong `KE_ROM_AGE_KEY` fails at the `age -d` step with the diagnostic
described above; a ciphertext that decrypts to something other than a known
Knife Edge (USA) dump fails at the md5 gate instead, with the actual
(non-secret) md5 printed for comparison.


## Windows build

**Status: implemented, first CI run pending.** Both `windows-stub-build` and
`windows-build` are new in `.github/workflows/build.yml` on
`feature/windows-build` and have not yet executed on a GitHub runner (the
branch's push hasn't landed at time of writing). No human has run the
resulting `.exe` on real Windows hardware either. Nothing below is
"verified" or "shipped" — see "Status and what's actually unproven" at the
end of this section for exactly what each unresolved risk is and who can
resolve it.

### Toolchain: clang-cl, Ninja, no container

Windows builds require `clang-cl`, enforced by a configure-time guard in
`CMakeLists.txt` (`if (WIN32 AND NOT CMAKE_CXX_COMPILER_ID STREQUAL
"Clang")` → `FATAL_ERROR`). Reason: this project's recompiled-code compile
flags (`-march=nehalem`, `-fms-extensions`, assorted `-Wno-*`) are GCC-style
and used **verbatim** — the same block Zelda64Recomp ships its own Windows
builds with. `clang-cl` accepts and passes them straight through (it's a
Clang frontend with an MSVC-compatible CLI); MSVC's `cl.exe` would reject
every one of them with a wall of unknown-flag errors. Rather than let that
cascade confuse a first-time Windows builder, the guard fails fast with a
message naming the exact `-DCMAKE_C_COMPILER=clang-cl
-DCMAKE_CXX_COMPILER=clang-cl` fix.

Ninja is the generator on Windows too (`choco install ninja`), for the same
reason it's used everywhere else in this project: one generator, one set of
build-script assumptions, no MSBuild-specific CI logic to maintain in
parallel.

`containers/Containerfile` is **Linux-only** (Debian-based, apt-driven) —
there is no containerized Windows build, and none is planned; Windows CI
builds natively on `windows-latest` using an inline `vswhere` + `vcvars64`
step to export `INCLUDE`/`LIB`/`LIBPATH`/`PATH` (deliberately not a
third-party action — same minimal-trusted-code-surface reasoning as
elsewhere in this workflow, and the exact step both `windows-stub-build`
and `windows-build` share verbatim).

**Host tools are the one deliberate exception**: `deps/N64Recomp`
(N64Recomp/RSPRecomp) builds with the **default MSVC `cl.exe`**, not
clang-cl — this is upstream N64Recomp's own proven `windows-latest` CI
configuration, reused rather than "harmonized" to clang-cl. There's no ABI
coupling to worry about: the host tools are standalone `.exe` processes
invoked by CMake's `execute_process`/`add_custom_command`, not linked
against anything the game executable links against. Mixing toolchains here
is intentional and called out in a workflow comment precisely so a future
cleanup pass doesn't "fix" it.

### The exception-model decision

Both Windows CI jobs configure with:

```
-DCMAKE_CXX_FLAGS='-Xclang -fexceptions -Xclang -fcxx-exceptions'
```

and a workflow comment marked "IMPORTANT, do not simplify" forbids
replacing this with `/EHsc`. The reason is the orderly-shutdown patch
(`patches/n64modernruntime-orderly-shutdown.patch`, see CLAUDE.md's
"Shutdown segfault on quit"): it throws `ultramodern::thread_terminated`
*through* recompiled `extern "C"` frames as part of tearing down the game's
host threads before RDRAM is freed. `/EHsc`'s trailing `c` is a promise to
the compiler that `extern "C"` functions never throw — on that promise,
MSVC-ABI unwinding is permitted to skip destructors and catch frames when
crossing such a boundary, which would silence or corrupt the exact throw
path the shutdown fix depends on. `-fexceptions -Xclang -fcxx-exceptions`
(the Clang/Itanium-style flags, passed through clang-cl's `-Xclang`
passthrough) make no such promise and are what keeps that throw path
working.

**Residual risk, explicitly not closed by CI.** This is the
highest-consequence untested path in the whole Windows port: MSVC-ABI
exception unwinding through *recompiled C* frames specifically (the CXX
flag covers `KnifeEdgeRecompiled`'s own C++ TUs, but `RecompiledFuncs` is
compiled as C — `CMAKE_C_FLAGS` carries no equivalent override yet). Only a
real clean-quit test on real Windows hardware exercises this path; neither
CI job's kill-based launch check comes anywhere near it (see "have_display"
below — the launch checks kill the process, they never let it reach a quit
path). The pre-designed fallback, not yet applied because it's unproven
whether it's even necessary: add the same `-Xclang -fexceptions -Xclang
-fcxx-exceptions` pair to `CMAKE_C_FLAGS` so the recompiled C translation
units aren't implicitly marked `nounwind` either. Apply it if the owner's
clean-quit test crashes or hangs on shutdown; leave it alone if that test
passes, since an unnecessary flag on every recompiled C function is not
free.

### The `link_directories` scoping trap

`deps/rt64` vendors SDL2 for Windows under
`src/contrib/mupen64plus-win32-deps/SDL2-2.26.3` and links it by **bare
name** (`target_link_libraries(rt64 SDL2 SDL2main)`), which does propagate
to a consumer target like `KnifeEdgeRecompiled`. But the `link_directories()`
call that makes that bare name resolvable is **directory-scoped** — it does
not cross `add_subdirectory()`. This is the exact same trap already known
from the dxc include path (`deps/rt64/src/contrib/dxc/inc`, re-added
manually at the top level for the same reason). `CMakeLists.txt`'s
`if (WIN32)` block re-adds the search path explicitly:

```cmake
target_link_directories(KnifeEdgeRecompiled PRIVATE "${KE_WIN_SDL2_DIR}/lib/x64")
```

Skipping this reproduces as an "unresolved external symbol" /
`SDL2.lib not found`-shaped link failure, not a configure-time error — worth
knowing if this ever needs re-diagnosing.

### DLL staging

There are no `install()` rules anywhere in this project's `CMakeLists.txt`
(it's a build-system skeleton by design), so local Windows runs must work
directly out of the build directory — there's no packaging step that would
otherwise gather dependencies. `deps/rt64` does have its own
`configure_file()` calls that copy `dxcompiler.dll`/`dxil.dll`, but they
target *rt64's own* binary output directory, and this project overrides
`CMAKE_RUNTIME_OUTPUT_DIRECTORY` to point at the top-level build dir instead
— so rt64's copies land somewhere `KnifeEdgeRecompiled.exe` never looks.
The `if (WIN32)` block instead stages the three required DLLs
(`SDL2.dll`, `dxcompiler.dll`, `dxil.dll`) with an explicit `POST_BUILD`
`copy_if_different` sourced directly from the vendored paths
(`deps/rt64/src/contrib/dxc/bin/x64/`, `${KE_WIN_SDL2_DIR}/lib/x64/`) into
`$<TARGET_FILE_DIR:KnifeEdgeRecompiled>` — independent of rt64's internal
output layout, so it can't silently break if that layout changes upstream.
Both CI jobs also verify this by uploading the staged DLLs alongside the
exe (`windows-stub-build`'s artifact exists specifically to keep this rule
continuously checked, not just occasionally hand-built).

### The `autocrlf` trap

Git for Windows defaults to `core.autocrlf=true`. `deps/N64ModernRuntime`
(a submodule) carries no `.gitattributes` of its own, so a default Windows
checkout would silently convert its files to CRLF line endings — including
the file `patches/n64modernruntime-orderly-shutdown.patch` is a diff
against. That patch is LF-only; applying it to a CRLF working tree fails
`git apply`'s context matching, and `ke_apply_dep_patch()`'s existing
divergence check (`git apply --check` fails, and it's not already applied
either) surfaces as a `FATAL_ERROR` at configure time — before any compiler
even runs.

Both Windows CI jobs run:

```yaml
- name: Configure git for Windows checkouts
  run: |
    git config --global core.autocrlf false
    git config --global core.longpaths true
```

**before** `actions/checkout@v4`, so the checkout itself never introduces
CRLF. `CMakeLists.txt`'s `ke_apply_dep_patch()` error message was also
extended to name this trap explicitly (`"On Windows this also happens when
the checkout used core.autocrlf=true..."`), for the benefit of anyone who
clones without following the CI recipe. `core.longpaths true` is unrelated
housekeeping — it guards against Windows's legacy `MAX_PATH` limit biting
on the deep object paths this repo's several vendored submodules produce.

### Renderer default

Nothing to configure here — it falls out of how `RT64_SDL_WINDOW_VULKAN` is
defined. rt64's own CMake only sets that flag on Linux, and
`CMakeLists.txt`'s `if (WIN32)` block deliberately does **not** define it
either. Without it, `create_window()` in `src/main/main.cpp` takes the
HWND/`GetCurrentThreadId` path instead of requesting an `SDL_WINDOW_VULKAN`
surface, which is what lets RT64's own device selection default to
D3D12-first on Windows. No Windows-side equivalent flag exists or is
needed — this is purely an absence, not a Windows-specific code path to
maintain.

### `have_display` / launch-check contract

`main.cpp`'s `have_display` is unconditionally `true` on `_WIN32` —
`DISPLAY`/`WAYLAND_DISPLAY` (the env vars the Linux code checks) simply
don't exist on Windows, and the NFD Win32 file-dialog backend needs no
portal preflight the way the Linux/Flatpak path does (see "Flatpak
packaging" above for that preflight's own history). The consequence: a
no-ROM Windows run can legitimately reach and block on a native file-picker
dialog, or later on a modal `MessageBox` from `exit_error()` — either can
sit forever on a CI runner with no human to dismiss it.

Because of this, **every Windows CI launch check is kill-based, never
exit-code-based**: both jobs `Start-Process` the exe, wait up to 30 s,
`Kill()` it if it's still alive (expected — that's the file-dialog-or-no-GPU
case), and then assert only that stdout contains the literal startup line
(`"Knife Edge Recompiled"`, from `kerecomp::log_build_info()`, immediately
`fflush`'d). That's a deliberately narrow assertion — process image loaded,
`main()` ran, the staged DLLs resolved, the CRT is satisfied — and nothing
more. The Linux `build` job's exit-code contract (clean exit 1 with no
ROM/no display) does **not** transfer to Windows; `have_display` being
unconditionally true is exactly why not.

### `fetch-rom` on Windows

`.github/actions/fetch-rom/action.yml` gained a `runner.os == 'Windows'`
branch so both ROM-gated Windows jobs can reuse it unchanged from the Linux
callers' point of view. Git Bash (preinstalled on `windows-latest`) already
supplies everything `scripts/fetch_rom.sh` itself needs — `curl` 8.x with
`--aws-sigv4`, `md5sum`, `mktemp`, `sed -E`, same-directory `mv` — so the
script required **no changes**. What the action adds around it:

- **age**: not preinstalled on Windows, and rather than a floating
  choco/scoop package (unreviewed third-party code in the same job that
  holds the ROM-decryption secrets), it downloads the official v1.2.1
  Windows release zip and checks it against a pinned SHA256
  (`46db0db71f146061f7c8fffa912cb806aef1bc8450e27a3abc1744f0591b89fb`),
  extracted with `bsdtar` (Git Bash's `tar` reads zip natively; there is no
  `unzip` on `PATH`). That pin was cross-checked against Microsoft's
  independently published winget manifest for the same release URL — exact
  match — as a second source of truth beyond "trust the download."
- **The age identity file** (`KE_ROM_AGE_KEY`, written by
  `fetch_rom.sh` via `printf '%s\n' ... > "$identity_tmp"`) ends up bare
  LF, not CRLF, on Windows too — `printf` never inserts a `\r`, and msys
  mounts are binary (no autocrlf-style translation happens on file writes
  through Git Bash the way it does on `git checkout`), so `age -d -i` reads
  the identity line cleanly. `chmod 600` on that file is only advisory on
  NTFS via msys, accepted as fine on an ephemeral single-tenant runner
  whose entire temp directory is wiped with the job regardless.
- **`TMPDIR`** is pointed at `$RUNNER_TEMP` (converted once via `cygpath
  -u`) before invoking `fetch_rom.sh`, so its `mktemp` scratch (the identity
  file and the downloaded ciphertext) stays job-scoped instead of landing in
  the machine-wide `%TEMP%` — a tightening Linux's own runner layout doesn't
  need.
- **The new `rom-path` output** exists because the decrypted ROM's path
  needs to reach `-DKE_ROM=...` on the `cmake` command line, and the
  Windows path shape differs from Linux's plain POSIX path: the action
  reports `cygpath -m "$out_path"` (drive-letter-with-forward-slashes,
  e.g. `C:/Users/.../knife_edge.rom`) — a form CMake accepts directly
  without any path-translation logic on the CMake side. Existing Linux
  callers are unaffected (still exactly `$RUNNER_TEMP/knife_edge.rom`).

### Zip packaging

`windows-build`'s "Assemble release zip" step mirrors `linux-build`'s
tarball step in structure but diverges in a few Windows-specific ways:

- **Staged in `$RUNNER_TEMP/stage`** (converted to its msys form via
  `cygpath -u`), with the decrypted ROM (`$RUNNER_TEMP/knife_edge.rom`)
  sitting outside that staged subtree — the same "ROM can't be swept into
  the archive by construction" pattern `linux-build` uses, not just a
  `.gitignore`-style exclude list that could silently miss a new file.
- **7z writes a relative name, then Git Bash `mv` relocates it.** 7z is
  preinstalled on `windows-latest` and reachable on `PATH` under Git Bash,
  but it's a *native* Windows tool, not an msys one — whether
  `$GITHUB_WORKSPACE`/`$PWD` in the form Git Bash exports would even be a
  path 7z understands wasn't something this branch could verify before its
  first real run (no Windows runner to test against pre-merge). Rather than
  gamble on that translation, the step `cd`s into the stage directory
  first (unambiguous to any tool, msys or native, once `cd` has resolved
  it) and has 7z write a plain relative filename there; the *relocation*
  into the workspace root is then done with `mv`, which — being an msys
  tool itself — already handles the translation correctly. This is a
  deliberate hedge against an unverified path-form assumption, not a
  simplification for its own sake.
- **Fixed artifact name, versioned inner filename** — same convention as
  `linux-build`'s tarball: `actions/upload-artifact` always sees
  `KnifeEdgeRecompiled-windows-x86_64`, while the zip's own name and the
  directory inside it carry the tag or short SHA
  (`KnifeEdgeRecompiled-windows-x86_64-<version>`), so `publish`'s
  by-exact-name download never has to guess.
- **VC++ redistributable**: not bundled, documented instead.
  `packaging/windows/README.txt` names the Microsoft VC++ 2015–2022 x64
  redistributable and links `https://aka.ms/vs/17/release/vc_redist.x64.exe`,
  with a note on the missing-DLL symptom (`VCRUNTIME`/`MSVCP` errors) that
  means it's needed. Owner decision: `/MD` (dynamic CRT) plus documenting
  the redist, rather than static-CRT linking machinery — most target
  systems already have the redist from some other application, and static
  linking the CRT is extra build-system surface for a marginal convenience.

### Status and what's actually unproven

**Implemented, all headless/local-review only — no Windows runner has ever
executed either job:**
- `windows-stub-build` (no ROM, fork-PR-safe) and `windows-build` (full
  ROM, gated identically to `linux-build` via `rom-gate`), both added to
  `.github/workflows/build.yml`.
- `CMakeLists.txt`'s `WIN32` branch (SDL2 include/link re-add, DLL staging,
  NOMINMAX/WIN32_LEAN_AND_MEAN, the clang-cl guard), the `_WIN32`
  `have_display` branch in `src/main/main.cpp`, and the `%LOCALAPPDATA%`
  data dir in `src/main/support.cpp`.
- `.github/actions/fetch-rom`'s Windows leg (pinned age install,
  `TMPDIR`/`rom-path` handling).
- `packaging/windows/README.txt`.

**What the first CI runs must prove** (mechanical/toolchain risk, the kind
of thing that fails loudly if wrong):
- The GCC-style recompiled-code flags actually pass through clang-cl
  without being silently dropped (the "assert no compiler flags were
  silently dropped" step exists for exactly this — a dropped
  `-march=nehalem` would lose SSE4.1 for librecomp's RSP vector backend
  with no compile error, just wrong runtime behavior).
- `cl.exe`-built host tools (on a cache miss) actually produce
  `N64RecompCLI`/`RSPRecomp` binaries `-DN64RECOMP_HOST_TOOL`/
  `-DRSPRECOMP_HOST_TOOL` can drive from a clang-cl-configured outer build.
- `fetch-rom` actually round-trips under Git Bash on a real
  `windows-latest` image (the pinned age zip extracts, `cygpath`
  conversions produce paths CMake accepts, `TMPDIR` scoping holds).
- The kill-based launch checks actually see the startup line (i.e. the
  staged DLLs really do resolve at process load).
- The 7z-then-`mv` zip-staging hedge actually behaves the way it's
  reasoned to (see "Zip packaging" above) — this is the one step in the
  whole design explicitly flagged as unverifiable before a real run.

**What only the project owner, on real Windows hardware, can prove** (no CI
job — kill-based launch checks included — comes anywhere near these):
- Actual D3D12 device creation and rendering on a real GPU (CI's launch
  checks never get past the file dialog / no-GPU wait).
- Input (keyboard, gamepad, mouse aim) and audio output.
- The `enhanced` profile end-to-end.
- The NFD Win32 file-picker dialog actually opening and completing a pick.
- `%LOCALAPPDATA%\KnifeEdgeRecompiled` persistence across runs (config +
  cached ROM).
- **Clean quit** — the highest-consequence item on this whole list, since
  it's the one exercising MSVC-ABI unwinding through recompiled `extern
  "C"`/C frames (see "The exception-model decision" above). If this hangs
  or crashes, the pre-designed fallback is adding the exception flags to
  `CMAKE_C_FLAGS` too.
