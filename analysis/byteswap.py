#!/usr/bin/env python3
"""ROM ingest for Knife Edge - Nose Gunner (USA).

Accepts a ROM in z64 (big-endian), v64 (16-bit byteswapped), or n64
(32-bit little-endian) byte order, verifies it is the expected dump,
and writes a normalized big-endian z64 image to the output path.

The output must land outside the repo tree (build dir) — ROM-derived
bytes are never committed.
"""

import argparse
import hashlib
import sys

# md5 of the known-good dump in v64 (byteswapped) order, and of its
# normalized z64 form. Either input is accepted.
KNOWN_MD5 = {
    "2ccbea019d3d1aaa1e8e6198dd677573": "v64 dump",
    "8043d829fcd4f8f72dd81e5c6dde916f": "z64 (normalized)",
}
Z64_MAGIC = b"\x80\x37\x12\x40"
V64_MAGIC = b"\x37\x80\x40\x12"
N64_MAGIC = b"\x40\x12\x37\x80"


def to_z64(data: bytes) -> bytes:
    magic = data[:4]
    if magic == Z64_MAGIC:
        return data
    if magic == V64_MAGIC:
        out = bytearray(data)
        out[0::2], out[1::2] = data[1::2], data[0::2]
        return bytes(out)
    if magic == N64_MAGIC:
        out = bytearray(len(data))
        out[0::4], out[1::4], out[2::4], out[3::4] = (
            data[3::4], data[2::4], data[1::4], data[0::4],
        )
        return bytes(out)
    raise SystemExit(f"error: unrecognized ROM byte order (magic {magic.hex()})")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", help="input ROM (.z64/.v64/.n64)")
    parser.add_argument("output", help="normalized z64 output path")
    parser.add_argument(
        "--allow-unknown", action="store_true",
        help="skip the known-dump md5 gate (development only)",
    )
    args = parser.parse_args()

    with open(args.rom, "rb") as f:
        data = f.read()

    z64 = to_z64(data)
    md5_input = hashlib.md5(data).hexdigest()
    md5_z64 = hashlib.md5(z64).hexdigest()

    if md5_input not in KNOWN_MD5 and md5_z64 not in KNOWN_MD5:
        msg = (
            f"error: ROM does not match a known Knife Edge (USA) dump\n"
            f"  input md5: {md5_input}\n  z64 md5:   {md5_z64}"
        )
        if not args.allow_unknown:
            raise SystemExit(msg)
        print(msg.replace("error:", "warning:"), file=sys.stderr)

    name = z64[0x20:0x34].decode("ascii", "replace").rstrip()
    if name != "KNIFE EDGE" and not args.allow_unknown:
        raise SystemExit(f"error: internal name is {name!r}, expected 'KNIFE EDGE'")

    with open(args.output, "wb") as f:
        f.write(z64)
    print(f"wrote {args.output} ({len(z64)} bytes, internal name {name!r}, md5 {md5_z64})")


if __name__ == "__main__":
    main()
