#!/usr/bin/env bash
# Fetch and decrypt an age-encrypted Knife Edge (USA) ROM for CI (or local
# testing) that has no ROM sitting on disk already.
#
# Design (see analysis/docs/build-notes.md, "Encrypted ROM in CI (Backblaze
# B2)" for the full threat model and rationale): the owner keeps only
# CIPHERTEXT in cloud storage, encrypted to an age X25519 recipient. This
# script downloads that ciphertext and decrypts it in-place with the age
# identity (private key), which is handed to CI as a secret, never committed.
# Confidentiality lives entirely in the age encryption, not in the bucket
# being private -- a private bucket + scoped B2 application key is defense in
# depth on top of that, not the primary control.
#
# Usage: scripts/fetch_rom.sh <output-path>
#
# Required environment:
#   KE_ROM_URL      URL of the age-encrypted ROM ciphertext. Any
#                    curl-fetchable URL -- https in CI, http/file for local
#                    testing against a throwaway `python3 -m http.server`.
#   KE_ROM_AGE_KEY   The age identity (the "AGE-SECRET-KEY-1..." line from
#                    `age-keygen`) that decrypts the ciphertext at KE_ROM_URL.
#
# Optional environment (must be set together, or neither):
#   KE_B2_KEY_ID     A Backblaze B2 application key ID, scoped read-only to
#   KE_B2_APP_KEY    the one private bucket holding the ciphertext. When set,
#                    the download is signed with curl's native AWS SigV4
#                    support against B2's S3-compatible endpoint -- no B2 or
#                    AWS CLI dependency, so this script runs anywhere with
#                    curl and age. Requires KE_ROM_URL to be B2's
#                    S3-compatible endpoint, either style:
#                    https://s3.<region>.backblazeb2.com/<bucket>/<file> or
#                    https://<bucket>.s3.<region>.backblazeb2.com/<file>
#                    (not the "friendly" B2 native URL, which SigV4 cannot
#                    address). Omit both to
#                    fetch from a public URL instead (a public flat file, or
#                    a B2 bucket with public-read access) -- the ciphertext
#                    is the protection either way.
#
# NEVER print KE_ROM_URL, KE_ROM_AGE_KEY, KE_B2_KEY_ID, or KE_B2_APP_KEY --
# not even on error paths. This is why `set -x` must never be enabled in this
# script (or in any caller that sources it).
set -euo pipefail

usage() {
    sed -n '2,39p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'
}

if [ "${1:-}" = "-h" ] || [ "${1:-}" = "--help" ]; then
    usage
    exit 0
fi

if [ $# -ne 1 ]; then
    echo "error: expected exactly one argument, the output path (got $#)" >&2
    usage >&2
    exit 2
fi
out_path="$1"

# ---------------------------------------------------------------------------
# Env validation.
# ---------------------------------------------------------------------------
if [ -z "${KE_ROM_URL:-}" ]; then
    echo "error: KE_ROM_URL is required (URL of the age-encrypted ROM)" >&2
    exit 2
fi
if [ -z "${KE_ROM_AGE_KEY:-}" ]; then
    echo "error: KE_ROM_AGE_KEY is required (the AGE-SECRET-KEY-1... identity line)" >&2
    exit 2
fi

have_b2_key_id=0
have_b2_app_key=0
[ -n "${KE_B2_KEY_ID:-}" ] && have_b2_key_id=1
[ -n "${KE_B2_APP_KEY:-}" ] && have_b2_app_key=1
if [ "$have_b2_key_id" -ne "$have_b2_app_key" ]; then
    echo "error: KE_B2_KEY_ID and KE_B2_APP_KEY must be set together (both or neither) — only one is set" >&2
    exit 2
fi
b2_signed=0
[ "$have_b2_key_id" -eq 1 ] && b2_signed=1

# ---------------------------------------------------------------------------
# Tool preflight.
# ---------------------------------------------------------------------------
if ! command -v curl >/dev/null 2>&1; then
    echo "error: curl is not on PATH" >&2
    exit 1
fi
if ! command -v age >/dev/null 2>&1; then
    echo "error: age is not on PATH. Install it: sudo apt-get install -y age (Debian/Ubuntu package 'age')" >&2
    exit 1
fi

# ---------------------------------------------------------------------------
# Build the extra curl args for a signed B2 S3-compatible fetch, if requested.
# curl's --aws-sigv4 has been available since curl 7.75 (2021); GitHub-hosted
# runners ship curl 8.x, so no version check is needed here.
# ---------------------------------------------------------------------------
curl_extra_args=()
if [ "$b2_signed" -eq 1 ]; then
    # Parse the region out of the host. B2's S3-compatible endpoint comes in
    # two equivalent shapes and curl can sign either (SigV4 covers the Host
    # header, so bucket-in-host vs bucket-in-path makes no difference):
    #   path-style:           https://s3.<region>.backblazeb2.com/<bucket>/<file>
    #   virtual-hosted style: https://<bucket>.s3.<region>.backblazeb2.com/<file>
    # The B2 web UI hands out the virtual-hosted form ("S3-friendly URL"), so
    # both must pass this check.
    host="$(printf '%s\n' "$KE_ROM_URL" | sed -E 's#^https?://([^/]+)/.*#\1#')"
    if ! printf '%s\n' "$host" | grep -qE '(^|\.)s3\.[A-Za-z0-9-]+\.backblazeb2\.com$'; then
        echo "error: KE_B2_KEY_ID/KE_B2_APP_KEY are set, but KE_ROM_URL's host is not a B2 S3-compatible endpoint." >&2
        echo "  Signed fetch requires one of:" >&2
        echo "    https://s3.<region>.backblazeb2.com/<bucket>/<file>" >&2
        echo "    https://<bucket>.s3.<region>.backblazeb2.com/<file>" >&2
        exit 2
    fi
    region="$(printf '%s\n' "$host" | sed -E 's#^.*s3\.([A-Za-z0-9-]+)\.backblazeb2\.com$#\1#')"
    curl_extra_args+=(--user "$KE_B2_KEY_ID:$KE_B2_APP_KEY" --aws-sigv4 "aws:amz:$region:s3")
fi

# ---------------------------------------------------------------------------
# Temp files. Everything lands under ${TMPDIR:-/tmp}; the trap removes all of
# them unconditionally, success or failure.
# ---------------------------------------------------------------------------
tmp_dir="${TMPDIR:-/tmp}"
cipher_tmp="$(mktemp "$tmp_dir/ke_rom_cipher.XXXXXX")"
identity_tmp="$(mktemp "$tmp_dir/ke_rom_identity.XXXXXX")"   # mktemp creates mode 600
# The plaintext temp must live in the SAME directory as the final output path
# so the last-step `mv` is a same-filesystem rename (atomic), not a copy.
mkdir -p "$(dirname "$out_path")"
out_dir="$(cd "$(dirname "$out_path")" && pwd)"
plain_tmp="$(mktemp "$out_dir/.ke_rom_plain.XXXXXX")"

cleanup() {
    rm -f "$cipher_tmp" "$identity_tmp" "$plain_tmp"
}
trap cleanup EXIT

# ---------------------------------------------------------------------------
# Download the ciphertext. NEVER echo $KE_ROM_URL -- see the header comment.
# ---------------------------------------------------------------------------
echo "==> downloading encrypted ROM"
curl --fail --silent --show-error --location --retry 3 --retry-connrefused \
    "${curl_extra_args[@]}" \
    -o "$cipher_tmp" \
    "$KE_ROM_URL"

# ---------------------------------------------------------------------------
# Decrypt. age is authenticated encryption, so a failure here always means
# one of: wrong KE_ROM_AGE_KEY, a corrupted upload, or the wrong object --
# never a transient/network condition (that already failed the curl above).
# ---------------------------------------------------------------------------
echo "==> decrypting"
printf '%s\n' "$KE_ROM_AGE_KEY" > "$identity_tmp"
if ! age -d -i "$identity_tmp" -o "$plain_tmp" "$cipher_tmp"; then
    echo "error: age decryption failed. age is authenticated encryption, so this means one of:" >&2
    echo "  - KE_ROM_AGE_KEY is the wrong identity for whatever KE_ROM_URL encrypts to" >&2
    echo "  - the uploaded ciphertext is corrupted" >&2
    echo "  - KE_ROM_URL points at the wrong object entirely" >&2
    exit 1
fi

# ---------------------------------------------------------------------------
# md5 gate on the decrypted plaintext. These two hashes mirror KNOWN_MD5 in
# analysis/byteswap.py -- the build's own ROM ingestion normalizes byte order
# itself, so either dump order (v64 byteswapped or z64 normalized) is
# acceptable input here.
# ---------------------------------------------------------------------------
md5="$(md5sum "$plain_tmp" | cut -d' ' -f1)"
case "$md5" in
    2ccbea019d3d1aaa1e8e6198dd677573) dump_kind="v64 (byteswapped) dump" ;;
    8043d829fcd4f8f72dd81e5c6dde916f) dump_kind="z64 (normalized) dump" ;;
    *)
        rm -f "$plain_tmp"
        echo "error: decrypted file's md5 is $md5, which does not match the known Knife Edge (USA) dump — wrong file uploaded?" >&2
        exit 1
        ;;
esac

# ---------------------------------------------------------------------------
# Publish: lock down permissions, then atomically move into place.
# ---------------------------------------------------------------------------
chmod 600 "$plain_tmp"
mv "$plain_tmp" "$out_path"
size="$(wc -c < "$out_path" | tr -d ' ')"
echo "fetched ROM OK ($dump_kind, $size bytes)"
