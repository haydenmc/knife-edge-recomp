#!/usr/bin/env bash
# Containerized build for Knife Edge Recompiled.
#
# This is the ONE script both developers and CI use to build inside the
# canonical toolchain defined by containers/Containerfile — there is no
# separate "CI build" and "local container build" path to keep in sync.
# See analysis/docs/build-notes.md, "Containerized build", for the design.
#
# Usage:
#   scripts/container_build.sh [--rom <path>] [--smoke] [--check] [--shell]
#                               [--exec "<cmd>"] [--jobs N] [--rebuild-image]
#
#   --rom <path>       Mount a Knife Edge (USA) ROM read-only at
#                       /rom/rom.n64 inside the container and pass
#                       -DKE_ROM=/rom/rom.n64 to the main build's configure
#                       step, so the recompiled game code (not just the
#                       stub) gets built.
#   --smoke            After building, run scripts/smoke_test.sh inside the
#                       container against the build just produced. Requires
#                       --rom (the smoke test needs a real, playable build).
#   --check            After building, assert the no-ROM graceful-failure
#                       behavior (binary exits 1, not a hang/crash). Works
#                       with or without --rom.
#   --shell             Drop into an interactive shell in the container
#                       instead of building anything.
#   --exec "<cmd>"      Run an arbitrary shell command in the container
#                       instead of building (used by the regen-verify CI
#                       job). Mutually exclusive with --shell.
#   --jobs N            Cap ninja's parallelism (applies to both the
#                       N64Recomp/RSPRecomp host-tool build and the main
#                       project build).
#   --rebuild-image     Force a rebuild of the container image even if a
#                       matching tag already exists.
#
# Container runtime: $KE_CONTAINER_RUNTIME if set, else podman if present,
# else docker, else this script errors out with a clear message.
#
# Output lands in build-container/ (and deps/N64Recomp/build-container/ for
# the host tools) — deliberately separate from any host-side build
# directories (build/, build-shim/, deps/N64Recomp/build/), since a
# container build uses a different compiler/libc than a native host build
# and the two must never share object directories.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# ---------------------------------------------------------------------------
# Argument parsing. --help must work with NO container runtime installed and
# NO network access, so this whole block runs before any runtime detection.
# ---------------------------------------------------------------------------
usage() {
    sed -n '2,32p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'
}

rom_path=""
do_smoke=0
do_check=0
do_shell=0
exec_cmd=""
have_exec=0
jobs=""
rebuild_image=0

while [ $# -gt 0 ]; do
    case "$1" in
        --rom)
            [ $# -ge 2 ] || { echo "error: --rom requires a path argument" >&2; exit 2; }
            rom_path="$2"; shift 2 ;;
        --smoke)
            do_smoke=1; shift ;;
        --check)
            do_check=1; shift ;;
        --shell)
            do_shell=1; shift ;;
        --exec)
            [ $# -ge 2 ] || { echo "error: --exec requires a command string argument" >&2; exit 2; }
            exec_cmd="$2"; have_exec=1; shift 2 ;;
        --jobs)
            [ $# -ge 2 ] || { echo "error: --jobs requires a number argument" >&2; exit 2; }
            jobs="$2"; shift 2 ;;
        --rebuild-image)
            rebuild_image=1; shift ;;
        -h|--help)
            usage; exit 0 ;;
        *)
            echo "error: unknown argument: $1" >&2
            usage >&2
            exit 2 ;;
    esac
done

# ---------------------------------------------------------------------------
# Validate argument combinations before touching a container runtime at all.
# ---------------------------------------------------------------------------
if [ "$do_shell" -eq 1 ] && [ "$have_exec" -eq 1 ]; then
    echo "error: --shell and --exec are mutually exclusive" >&2
    exit 2
fi
if { [ "$do_shell" -eq 1 ] || [ "$have_exec" -eq 1 ]; } && { [ "$do_check" -eq 1 ] || [ "$do_smoke" -eq 1 ]; }; then
    echo "error: --check/--smoke apply to the normal build and are mutually exclusive with --shell/--exec" >&2
    exit 2
fi
if [ "$do_smoke" -eq 1 ] && [ -z "$rom_path" ]; then
    echo "error: --smoke requires --rom (the smoke test needs a real, playable build)" >&2
    exit 2
fi
if [ -n "$jobs" ] && ! [[ "$jobs" =~ ^[0-9]+$ ]]; then
    echo "error: --jobs must be a positive integer, got '$jobs'" >&2
    exit 2
fi

# ---------------------------------------------------------------------------
# Container runtime detection.
# ---------------------------------------------------------------------------
runtime="${KE_CONTAINER_RUNTIME:-}"
if [ -z "$runtime" ]; then
    if command -v podman >/dev/null 2>&1; then
        runtime=podman
    elif command -v docker >/dev/null 2>&1; then
        runtime=docker
    else
        echo "error: no container runtime found (checked: podman, docker)." >&2
        echo "Install one of them, or set KE_CONTAINER_RUNTIME=<name> to use a" >&2
        echo "differently-named/pathed docker-compatible CLI." >&2
        exit 1
    fi
elif ! command -v "$runtime" >/dev/null 2>&1; then
    echo "error: KE_CONTAINER_RUNTIME='$runtime' is not an executable on PATH." >&2
    exit 1
fi
echo "==> using container runtime: $runtime"

# ---------------------------------------------------------------------------
# Image build (tag = first 12 hex chars of the Containerfile's sha256, so a
# Containerfile change always produces a new tag and never reuses a stale
# image under the same name).
# ---------------------------------------------------------------------------
containerfile="$ROOT/containers/Containerfile"
if [ ! -f "$containerfile" ]; then
    echo "error: $containerfile not found" >&2
    exit 1
fi

sha256_hex() {
    if command -v sha256sum >/dev/null 2>&1; then
        sha256sum "$1" | cut -d' ' -f1
    elif command -v shasum >/dev/null 2>&1; then
        shasum -a 256 "$1" | cut -d' ' -f1
    else
        echo "error: neither sha256sum nor shasum is available on this host" >&2
        exit 1
    fi
}

image_tag="knife-edge-build:$(sha256_hex "$containerfile" | cut -c1-12)"

image_exists() {
    "$runtime" image inspect "$1" >/dev/null 2>&1
}

if [ "$rebuild_image" -eq 1 ] || ! image_exists "$image_tag"; then
    echo "==> building container image $image_tag (first use after a Containerfile" \
         "change takes ~2-4 min for the apt layer; cached after that)"
    if ! "$runtime" build -t "$image_tag" -f "$containerfile" "$ROOT/containers"; then
        echo "error: '$runtime build' failed — see output above." >&2
        exit 1
    fi
else
    echo "==> reusing existing container image $image_tag (use --rebuild-image to force a rebuild)"
fi

# ---------------------------------------------------------------------------
# Assemble `run` flags.
# ---------------------------------------------------------------------------
run_args=(--rm -e HOME=/tmp/ke-home -v "$ROOT:/work:rw" -w /work)

case "$runtime" in
    podman)
        # Proven on the project owner's rootless-podman/SELinux (Fedora) host —
        # see .devcontainer/devcontainer.json's runArgs comment for the same
        # two flags and why each is needed (keep-id lines up uids so the
        # mounted source is owned by the container user; label=disable opts
        # out of SELinux label separation, which otherwise denies container_t
        # access to the host's user_home_t-labelled source).
        run_args+=(--userns=keep-id --security-opt label=disable) ;;
    docker)
        run_args+=(--user "$(id -u):$(id -g)") ;;
    *)
        echo "note: runtime '$runtime' is neither podman nor docker;" \
             "not adding either's uid-mapping flags — you may hit permission" \
             "errors on files the build writes." >&2 ;;
esac

rom_mounted=0
if [ -n "$rom_path" ]; then
    if [ ! -f "$rom_path" ]; then
        echo "error: --rom path '$rom_path' does not exist" >&2
        exit 1
    fi
    rom_abs="$(cd "$(dirname "$rom_path")" && pwd)/$(basename "$rom_path")"
    # label=disable (podman) / no special option needed (docker) means no :Z
    # suffix is required here, matching the ROM mount in the same spirit as
    # the source mount above.
    run_args+=(-v "$rom_abs:/rom/rom.n64:ro")
    rom_mounted=1
fi

if [ "$do_shell" -eq 1 ]; then
    run_args+=(-it)
fi

jobs_flag=""
if [ -n "$jobs" ]; then
    jobs_flag="-j $jobs"
fi

rom_cmake_flag=""
if [ "$rom_mounted" -eq 1 ]; then
    rom_cmake_flag="-DKE_ROM=/rom/rom.n64"
fi

# ---------------------------------------------------------------------------
# Inner script(s) — executed inside the container via `bash -c`.
# ---------------------------------------------------------------------------

# Always run: uid/safe.directory setup. Kept as a single quoted (no
# expansion needed) block.
#
# Host-.venv note: the bind-mounted repo may carry a host-built .venv/ that
# CMakeLists.txt would otherwise auto-prefer. The build below neutralizes
# that with -DKE_PYTHON=/opt/ke-pyenv/bin/python (honored since CMakeLists
# guards its auto-detect with `if (NOT KE_PYTHON)`), and the regen-verify
# recipe passes PY= to analysis/Makefile the same way. An earlier approach
# (--tmpfs shadow over /work/.venv) failed in practice: crun applies
# tmpcopyup to tmpfs mounts, copying the host's ~95MB venv into the 16MB
# tmpfs -> ENOSPC at container start -- and docker doesn't copy up at all,
# so the mount behaved differently per runtime. Explicit override > mount
# games.
read -r -d '' preamble <<'PREAMBLE' || true
set -euo pipefail
git config --global --add safe.directory '*'
PREAMBLE

submodule_check=""
if [ "$do_shell" -ne 1 ]; then
    read -r -d '' submodule_check <<'SUBCHECK' || true
if [ ! -f deps/N64Recomp/CMakeLists.txt ]; then
    echo "error: submodules are not initialized (deps/N64Recomp/CMakeLists.txt missing)." >&2
    echo "Run: git submodule update --init --recursive" >&2
    exit 1
fi
SUBCHECK
fi

build_block=""
if [ "$do_shell" -ne 1 ] && [ "$have_exec" -ne 1 ]; then
    build_block="echo '==> building N64Recomp + RSPRecomp host tools (deps/N64Recomp/build-container)'
cmake -S deps/N64Recomp -B deps/N64Recomp/build-container -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXE_LINKER_FLAGS=-fuse-ld=lld
ninja -C deps/N64Recomp/build-container $jobs_flag N64Recomp RSPRecomp

echo '==> configuring + building KnifeEdgeRecompiled (build-container)'
cmake -S . -B build-container -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXE_LINKER_FLAGS=-fuse-ld=lld -DKE_PYTHON=/opt/ke-pyenv/bin/python -DN64RECOMP_HOST_TOOL=/work/deps/N64Recomp/build-container/N64Recomp -DRSPRECOMP_HOST_TOOL=/work/deps/N64Recomp/build-container/RSPRecomp $rom_cmake_flag
ninja -C build-container $jobs_flag"
fi

check_block=""
if [ "$do_check" -eq 1 ]; then
    read -r -d '' check_block <<'CHECKBLOCK' || true
echo "==> no-ROM graceful-failure check"
set +e
out="$(env -u DISPLAY -u SDL_VIDEODRIVER timeout 15 ./build-container/KnifeEdgeRecompiled 2>&1)"
status=$?
set -e
echo "$out"
echo "exit status: $status"
if [ "$status" -eq 124 ]; then
    echo "error: binary hung with no ROM (timeout); expected a clean exit" >&2
    exit 1
fi
if [ "$status" -ge 128 ]; then
    echo "error: binary died from signal $((status - 128)) (crash); expected a clean exit" >&2
    exit 1
fi
if [ "$status" -ne 1 ]; then
    echo "error: expected exit status 1 (EXIT_FAILURE), got $status" >&2
    exit 1
fi
echo "OK: binary is well-formed and fails cleanly without a ROM."
CHECKBLOCK
fi

smoke_block=""
if [ "$do_smoke" -eq 1 ]; then
    read -r -d '' smoke_block <<'SMOKEBLOCK' || true
echo "==> smoke test (scripts/smoke_test.sh against the build just produced)"
./scripts/smoke_test.sh --rom build-container/knife_edge.z64 --binary build-container/KnifeEdgeRecompiled
SMOKEBLOCK
fi

# ---------------------------------------------------------------------------
# Dispatch.
# ---------------------------------------------------------------------------
if [ "$do_shell" -eq 1 ]; then
    full_script="$preamble
echo 'Knife Edge container shell. Repo is mounted at /work (rw). deps/N64Recomp/build-container and build-container are the container-isolated build dirs.'
exec bash -l"
    exec "$runtime" run "${run_args[@]}" "$image_tag" bash -c "$full_script"
fi

if [ "$have_exec" -eq 1 ]; then
    full_script="$preamble
$submodule_check
$exec_cmd"
    exec "$runtime" run "${run_args[@]}" "$image_tag" bash -c "$full_script"
fi

full_script="$preamble
$submodule_check
$build_block
$check_block
$smoke_block"

if ! "$runtime" run "${run_args[@]}" "$image_tag" bash -c "$full_script"; then
    echo "error: container build failed — see output above." >&2
    echo "Common causes: submodules not initialized (git submodule update --init" >&2
    echo "--recursive), or a stale build-container/ from a previous toolchain —" >&2
    echo "try 'rm -rf build-container deps/N64Recomp/build-container' and retry." >&2
    exit 1
fi

echo "==> done. Binary: $ROOT/build-container/KnifeEdgeRecompiled"
