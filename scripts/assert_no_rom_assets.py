#!/usr/bin/env python3
"""Assert that no ROM asset bytes leaked into a shippable binary.

Usage: assert_no_rom_assets.py <normalized-rom.z64> <binary>

Samples 400 pseudo-random (seed(1), so the run is deterministic — the same
"random" offsets are checked every time, which makes a failure reproducible
and a pass comparable across runs) 64-byte chunks from the ROM's *data*
region (offset >= 0x2E000, i.e. past the boot-code segment that legitimately
does get compiled in as recompiled code — only asset/level/audio data past
that point would be a leak). Chunks that are low-entropy (fewer than 8
distinct byte values — think runs of 0x00 or 0xFF padding) are skipped
because they are likely to appear "by accident" in any sufficiently large
binary and would make the check noisy rather than meaningful. Every
remaining chunk is checked for verbatim containment in the binary; any hit
means ROM data leaked into the artifact and the check fails.

This replaces two identical inline Python heredocs that used to live in
.github/workflows/build.yml (one for the release binary, one for the
flatpak bundle binary) — behavior here is bit-identical to both: same
random.seed(1), same random.randrange(0x2E000, len(rom) - 64), same skip
rule, same output line, same exit code convention.
"""
import random
import sys


def main() -> int:
    if len(sys.argv) != 3:
        print(f"usage: {sys.argv[0]} <normalized-rom.z64> <binary>", file=sys.stderr)
        return 2

    rom_path, binary_path = sys.argv[1], sys.argv[2]

    try:
        with open(rom_path, "rb") as f:
            rom = f.read()
    except OSError as e:
        print(f"error: could not read ROM at '{rom_path}': {e}", file=sys.stderr)
        return 2

    try:
        with open(binary_path, "rb") as f:
            binary = f.read()
    except OSError as e:
        print(f"error: could not read binary at '{binary_path}': {e}", file=sys.stderr)
        return 2

    random.seed(1)
    leaked = tried = 0
    for _ in range(400):
        off = random.randrange(0x2E000, len(rom) - 64)  # past the boot code segment
        chunk = rom[off:off + 64]
        if len(set(chunk)) < 8:
            continue
        tried += 1
        if chunk in binary:
            leaked += 1

    print(f"sampled {tried} distinctive ROM data blocks; embedded in binary: {leaked}")
    return 1 if leaked else 0


if __name__ == "__main__":
    sys.exit(main())
