#!/usr/bin/env bash
# Captures targeted game-state words from a running (or wedged) KnifeEdgeRecompiled
# process without disturbing it. Output goes to /tmp/ke_state.txt.
#
# What the five memory windows are (game addresses; rdram base + offset):
#   0x8011D1A0..  flag cluster the results screen / mission loop communicate
#                 through (result word 0x8011D1B4, sub-state bits 0x8011D1E2)
#   0x80109440..  game-mode area (0x801094B4 is compared against 0x1D by the
#                 audio-idle gate func_800CB720)
#   0x8013C270..  graphics tasks in flight (0x8013C280)
#   0x800EBC00    per-retrace callback pointer (mission code vs front-end?)
#   0x8011BE20..  controller held-buttons words
#
# Usage: scripts/capture_wedge_state.sh   (needs gdb; run as the same user)
set -euo pipefail

OUT=/tmp/ke_state.txt

PIDS=$(pidof KnifeEdgeRecompiled || true)
if [ -z "$PIDS" ]; then
    echo "error: no running KnifeEdgeRecompiled process found" >&2
    exit 1
fi

# pidof can return several PIDs (stray instances). Pick the one that actually
# owns the game-RAM mapping: librecomp reserves game RAM as a single 4 GiB
# anonymous reservation - an rw-p head (the committed part) immediately
# followed by a ---p tail, together exactly 0x100000000 bytes. That pattern is
# unique, so it pins both the right process and the rdram base, no symbols
# needed.
PID=""
BASE=""
for pid in $PIDS; do
    base=$(python3 -c '
import sys
prev = None
try:
    for line in open(f"/proc/{sys.argv[1]}/maps"):
        parts = line.split()
        start, end = (int(x, 16) for x in parts[0].split("-"))
        perms = parts[1]
        if prev and perms == "---p" and start == prev[1] and (end - prev[0]) == 0x100000000:
            print(hex(prev[0])); break
        prev = (start, end) if perms == "rw-p" else None
except OSError:
    pass
' "$pid")
    if [ -n "$base" ]; then
        PID="$pid"
        BASE="$base"
        break
    fi
done

if [ -z "$BASE" ]; then
    echo "error: no KnifeEdgeRecompiled process with a 4 GiB rdram mapping found (checked: $PIDS)" >&2
    exit 1
fi
echo "process: $PID"
echo "rdram base: $BASE"

gdb -p "$PID" -batch \
    -ex "echo \n=== flag cluster 0x8011D1A0 ===\n" \
    -ex "x/32wx $BASE+0x11D1A0" \
    -ex "echo \n=== game mode 0x80109440 ===\n" \
    -ex "x/32wx $BASE+0x109440" \
    -ex "echo \n=== gfx tasks in flight 0x8013C270 ===\n" \
    -ex "x/8wx  $BASE+0x13C270" \
    -ex "echo \n=== per-retrace callback ptr 0x800EBC00 ===\n" \
    -ex "x/4wx  $BASE+0xEBC00" \
    -ex "echo \n=== held buttons 0x8011BE20 ===\n" \
    -ex "x/8wx  $BASE+0x11BE20" \
    > "$OUT" 2>&1

echo "wrote $OUT"
grep -c "Cannot access" "$OUT" >/dev/null 2>&1 && \
    echo "warning: some reads failed - check $OUT" || true
