#!/usr/bin/env bash
# Builds the Flatpak bundle for Knife Edge Recompiled.
#
# See analysis/docs/build-notes.md, "Flatpak packaging", for the design
# (why a `dir` source over pre-generated code, the portal ROM picker, and
# KE_DATA_DIR). packaging/flatpak/io.github.haydenmc.KnifeEdgeRecompiled.yml
# is the manifest this drives.
#
# Usage:
#   scripts/build_flatpak.sh [--install] [--bundle <out.flatpak>]
#                            [--runtime-install] [-h|--help]
#
#   --install           After building, also `flatpak install --user` it
#                        (via flatpak-builder's own --install, not a
#                        separate step over the bundle).
#   --bundle <out>       Where to write the distributable .flatpak bundle.
#                        Default: KnifeEdgeRecompiled.flatpak in the repo
#                        root.
#   --runtime-install     Install the runtime/SDK/extension this manifest
#                        needs (org.freedesktop.Platform//24.08,
#                        org.freedesktop.Sdk//24.08,
#                        org.freedesktop.Sdk.Extension.llvm18//24.08) via
#                        `flatpak install`, then exit. Run this once before
#                        the first real build if flatpak-builder complains
#                        about a missing runtime.
#   -h, --help            Show this and exit.
#
# Requires: flatpak-builder on PATH, and generated/us/ already populated
# (configure once with -DKE_ROM=<rom>, or scripts/container_build.sh
# --rom <rom>) -- this script does NOT touch a ROM itself; the manifest
# builds from that pre-generated code (see the manifest's source comment
# for why: no ROM, no network, and no python/N64Recomp host tools are
# available inside flatpak-builder's sandboxed build).
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
APP_ID="io.github.haydenmc.KnifeEdgeRecompiled"
MANIFEST="$ROOT/packaging/flatpak/$APP_ID.yml"
WORKDIR="$ROOT/build-flatpak"
BUNDLE_OUT="$ROOT/KnifeEdgeRecompiled.flatpak"
DO_INSTALL=0
RUNTIME_INSTALL=0

while [ $# -gt 0 ]; do
    case "$1" in
        --install) DO_INSTALL=1; shift ;;
        --bundle) BUNDLE_OUT="$2"; shift 2 ;;
        --runtime-install) RUNTIME_INSTALL=1; shift ;;
        -h|--help) sed -n '2,29p' "${BASH_SOURCE[0]}"; exit 0 ;;
        *) echo "unknown argument: $1" >&2; exit 2 ;;
    esac
done

if [ "$RUNTIME_INSTALL" -eq 1 ]; then
    exec flatpak install --user --noninteractive \
        org.freedesktop.Platform//24.08 \
        org.freedesktop.Sdk//24.08 \
        org.freedesktop.Sdk.Extension.llvm18//24.08
fi

# --- Preflight ---------------------------------------------------------
if ! command -v flatpak-builder >/dev/null 2>&1; then
    echo "error: flatpak-builder not found on PATH." >&2
    echo "  Install it, then fetch the runtime this manifest needs with:" >&2
    echo "    $0 --runtime-install" >&2
    exit 2
fi

if [ ! -f "$ROOT/generated/us/recomp_overlays.inl" ]; then
    echo "error: recompiled game code not present — configure once with" >&2
    echo "  -DKE_ROM=<rom> (or run scripts/container_build.sh --rom ...)" >&2
    echo "  so generated/us exists" >&2
    exit 2
fi

# --- Build ---------------------------------------------------------------
mkdir -p "$WORKDIR"
BUILDER_ARGS=(--force-clean "--repo=$WORKDIR/repo")
if [ "$DO_INSTALL" -eq 1 ]; then
    BUILDER_ARGS+=(--install --user)
fi
flatpak-builder "${BUILDER_ARGS[@]}" "$WORKDIR/build" "$MANIFEST"

# --- Bundle ----------------------------------------------------------------
flatpak build-bundle "$WORKDIR/repo" "$BUNDLE_OUT" "$APP_ID"

echo
echo "Built $BUNDLE_OUT"
echo "Install it with:  flatpak install --user $BUNDLE_OUT"
echo "First run opens a portal ROM picker (no ROM ships in the bundle)."
