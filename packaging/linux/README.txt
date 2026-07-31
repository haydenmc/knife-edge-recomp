Knife Edge Recompiled
======================

A native PC port of Knife Edge - Nose Gunner (N64, Kemco 1998), built via
static recompilation: the game's original code is translated ahead of time
to run natively, with no emulation involved.

THIS ARCHIVE CONTAINS NO GAME DATA. You must supply your own legally
obtained ROM dump of Knife Edge - Nose Gunner (USA) to play.

First run
---------

    ./KnifeEdgeRecompiled --rom /path/to/your/dump

Accepts .z64, .v64, or .n64 dumps and validates the ROM's hash before
proceeding. A normalized copy is cached in ./ke_recomp_data/ next to your
working directory, so later runs don't need --rom again.

Runtime requirements
---------------------

- Linux, x86_64
- SDL2 (shared library, typically already present or available from your
  distro's package manager)
- A Vulkan-capable GPU and driver

Configuration
-------------

Settings live in ke_recomp_data/config.toml, created on first run. See the
project README for the full list of options (enhancement profiles, input
tuning, frame pacing, etc).

More information
-----------------

Source code, issue tracker, and full documentation:
    https://github.com/haydenmc/knife-edge-recomp

License
-------

This distribution is licensed under the GNU General Public License v3.0 —
see COPYING in this archive for the full text. Knife Edge Recompiled bundles
N64Recomp, N64ModernRuntime, and RT64, each licensed under the MIT License;
see the project README's Credits section for details.
