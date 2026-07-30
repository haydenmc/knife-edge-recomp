#!/bin/sh
# Flatpak launcher wrapper (packaging/flatpak/io.github.haydenmc.KnifeEdgeRecompiled.yml
# "command:"). Not the raw binary, because the game needs to be told where to
# keep its config/ROM cache inside the sandbox.
#
# Inside the sandbox XDG_DATA_HOME is ~/.var/app/<appid>/data, so this makes
# the ROM cache/config persist per-app and survive updates (the app's own
# working directory, which is what KE_DATA_DIR defaults to outside a
# Flatpak -- see src/main/support.cpp -- is not a stable or even necessarily
# writable place to keep it from inside a sandbox).
export KE_DATA_DIR="${XDG_DATA_HOME:-$HOME/.local/share}/knife-edge-recompiled"
exec /app/bin/knife-edge-recompiled-bin "$@"
