#!/usr/bin/env bash
# Follow-up to capture_wedge_state.sh: decodes the audio voice table that the
# mission loop's audio-idle gate (func_800CB720 -> func_800CF488) polls, to
# identify which voice never goes idle. Output: /tmp/ke_voices.txt.
#
# Table layout (from func_800CF488 disassembly):
#   count    = *(0x80139CF4)
#   base ptr = *(0x80139CFC)        (game address of first entry)
#   entries are 0x120 bytes; entry is active when word[0] != 0;
#   halfword at +0x9E classifies it (nonzero -> counted under mask 1,
#   zero -> counted under mask 2).
set -euo pipefail

OUT=/tmp/ke_voices.txt
RAW=/tmp/ke_voices.bin

PIDS=$(pidof KnifeEdgeRecompiled || true)
[ -z "$PIDS" ] && { echo "error: game not running" >&2; exit 1; }

PID=""; BASE=""
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
    [ -n "$base" ] && { PID="$pid"; BASE="$base"; break; }
done
[ -z "$BASE" ] && { echo "error: no process with rdram mapping (checked: $PIDS)" >&2; exit 1; }
echo "process: $PID  rdram base: $BASE"

# Pass 1: binary-dump the 16-byte header (0x80139CF0..) and decode in python -
# gdb's text output carries symbol annotations that are unpleasant to parse.
HDRBIN=/tmp/ke_vhdr.bin
gdb -p "$PID" -batch \
    -ex "dump binary memory $HDRBIN $BASE+0x139CF0 $BASE+0x139D00" > /dev/null 2>&1
read -r COUNT TBL <<< "$(python3 -c '
import struct, sys
b = open(sys.argv[1], "rb").read()
count = struct.unpack_from("<I", b, 4)[0]    # 0x80139CF4
tbl   = struct.unpack_from("<I", b, 12)[0]   # 0x80139CFC
ok = 0 < count <= 64 and 0x80000000 <= tbl < 0x80800000
print(f"{count:#x} {tbl:#x}" if ok else "BAD BAD")
' "$HDRBIN")"
rm -f "$HDRBIN"
[ "$COUNT" = "BAD" ] && { echo "error: implausible voice-table header" >&2; exit 1; }
echo "voice count: $COUNT   table (game addr): $TBL"

# Pass 2: binary-dump the whole table, decode locally.
HOST_TBL=$(python3 -c "print(hex($BASE + ($TBL - 0x80000000)))")
END=$(python3 -c "print(hex($HOST_TBL + $COUNT * 0x120))")
gdb -p "$PID" -batch -ex "dump binary memory $RAW $HOST_TBL $END" > /dev/null 2>&1

python3 - "$RAW" "$COUNT" "$TBL" > "$OUT" <<'PY'
import struct, sys
raw = open(sys.argv[1], "rb").read()
count = int(sys.argv[2], 16)
tbl = int(sys.argv[3], 16)
print(f"voice table @ {tbl:#010x}, {count} entries, stride 0x120")
print(f"{'idx':>3} {'game addr':>10} {'w0(active)':>10} {'hw+0x9E':>8}  first words / +0x90 region")
for i in range(count):
    e = raw[i*0x120:(i+1)*0x120]
    if len(e) < 0x120: break
    w = struct.unpack("<72I", e)
    # halfword at game offset +0x9E lives at host offset (0x9E ^ 2) = 0x9C, LE
    hw9e = struct.unpack_from("<H", e, 0x9C)[0]
    active = "ACTIVE" if w[0] else "  -   "
    head = " ".join(f"{x:08x}" for x in w[0:6])
    mid = " ".join(f"{x:08x}" for x in w[0x90//4:0x90//4+8])
    print(f"{i:>3} {tbl+i*0x120:#010x} {active:>10} {hw9e:#06x}  {head} | {mid}")
n_active = sum(1 for i in range(count)
               if len(raw) >= (i+1)*0x120 and struct.unpack_from("<I", raw, i*0x120)[0])
print(f"\nactive entries: {n_active}")
PY

rm -f "$RAW"
echo "wrote $OUT"
