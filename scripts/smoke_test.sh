#!/usr/bin/env bash
# Headless boot smoke test: launches the game under Xvfb + Mesa lavapipe, lets it
# run through part of the attract sequence, and asserts it is actually alive and
# producing real audio/video rather than hanging or drawing a blank screen.
#
# Requires a ROM, so this is a LOCAL/self-hosted check - CI cannot run it (see
# .github/workflows/build.yml, which does the no-ROM smoke test instead).
#
# Usage: scripts/smoke_test.sh [--rom PATH] [--binary PATH] [--seconds N] [--keep-artifacts]
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ROM="$ROOT/build/knife_edge.z64"
BIN="$ROOT/build-shim/KnifeEdgeRecompiled"
SECONDS_TO_RUN=35
KEEP=0
DISPLAY_NUM=":99"

# A frame with real content has thousands of distinct colours; a blank or
# single-fill frame has a handful. 256 is far above "blank" and far below what
# any actual rendered 3D frame produces (observed: 12k-45k).
MIN_COLORS=256
# Fraction of non-zero PCM samples expected once the synthesiser is running.
MIN_NONZERO_PCT=50

while [ $# -gt 0 ]; do
    case "$1" in
        --rom) ROM="$2"; shift 2 ;;
        --binary) BIN="$2"; shift 2 ;;
        --seconds) SECONDS_TO_RUN="$2"; shift 2 ;;
        --keep-artifacts) KEEP=1; shift ;;
        -h|--help) sed -n '2,10p' "${BASH_SOURCE[0]}"; exit 0 ;;
        *) echo "unknown argument: $1" >&2; exit 2 ;;
    esac
done

for f in "$ROM" "$BIN"; do
    if [ ! -f "$f" ]; then
        echo "error: missing $f" >&2
        echo "  (build with: cmake --build build-shim; normalize a ROM with analysis/byteswap.py)" >&2
        exit 2
    fi
done

# Absolutize before the `cd` below -- --rom/--binary may be given relative to
# the caller's directory (container_build.sh --smoke does), and a relative
# path silently dangles once we move into the scratch dir.
ROM="$(realpath "$ROM")"
BIN="$(realpath "$BIN")"

WORK="$(mktemp -d)"
cleanup() {
    [ -n "${APP_PID:-}" ] && kill "$APP_PID" 2>/dev/null
    [ -n "${XVFB_PID:-}" ] && kill "$XVFB_PID" 2>/dev/null
    if [ "$KEEP" -eq 1 ]; then
        echo "artifacts kept in $WORK"
    else
        rm -rf "$WORK"
    fi
}
trap cleanup EXIT

# Run from a scratch dir so the game's ROM cache/config does not land in the repo.
cd "$WORK"

Xvfb "$DISPLAY_NUM" -screen 0 1280x720x24 >/dev/null 2>&1 &
XVFB_PID=$!
sleep 3

echo "running $SECONDS_TO_RUN s under $DISPLAY_NUM (lavapipe, dummy audio device)..."
DISPLAY="$DISPLAY_NUM" SDL_AUDIODRIVER=dummy KE_AUDIO_DUMP="$WORK/audio.pcm" \
    "$BIN" --rom "$ROM" > "$WORK/run.log" 2>&1 &
APP_PID=$!

sleep "$SECONDS_TO_RUN"

status=0

if ! ps -p "$APP_PID" > /dev/null; then
    echo "FAIL: process exited before $SECONDS_TO_RUN s"
    tail -20 "$WORK/run.log"
    exit 1
fi
echo "  ok: process alive"

DISPLAY="$DISPLAY_NUM" import -window root "$WORK/frame.png" 2>/dev/null
colors=$(identify -format "%k" "$WORK/frame.png" 2>/dev/null || echo 0)
if [ "${colors:-0}" -lt "$MIN_COLORS" ]; then
    echo "FAIL: frame has only ${colors:-0} distinct colours (expected >= $MIN_COLORS) - blank screen?"
    status=1
else
    echo "  ok: video rendering ($colors distinct colours)"
fi

if [ ! -s "$WORK/audio.pcm" ]; then
    echo "FAIL: no audio samples captured"
    status=1
else
    read -r nonzero peak <<< "$(python3 - "$WORK/audio.pcm" <<'PY'
import struct, sys
d = open(sys.argv[1], "rb").read()
n = len(d) // 2
s = struct.unpack("<%dh" % n, d[:n * 2]) if n else ()
nz = sum(1 for x in s if x) / len(s) * 100 if s else 0.0
print("%.1f %d" % (nz, max((abs(x) for x in s), default=0)))
PY
)"
    if (( $(echo "$nonzero < $MIN_NONZERO_PCT" | bc -l) )); then
        echo "FAIL: audio is mostly silent (${nonzero}% non-zero, peak $peak)"
        status=1
    else
        echo "  ok: audio non-silent (${nonzero}% non-zero samples, peak $peak/32767)"
    fi
fi

# Failures the runtime reports without dying.
if grep -qiE "Unable to find a GBI|No RSP microcode registered for task type 1|Failed to|error:" "$WORK/run.log"; then
    echo "WARN: suspicious messages in run log:"
    grep -iE "Unable to find a GBI|No RSP microcode registered|Failed to|error:" "$WORK/run.log" | sort -u | head -5
fi

if [ "$status" -eq 0 ]; then
    echo "PASS"
else
    echo "FAILED"
fi
exit "$status"
