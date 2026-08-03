Knife Edge Recompiled
======================

A native PC port of Knife Edge - Nose Gunner (N64, Kemco 1998), built via
static recompilation: the game's original code is translated ahead of time
to run natively, with no emulation involved.

THIS ARCHIVE CONTAINS NO GAME DATA. You must supply your own legally
obtained ROM dump of Knife Edge - Nose Gunner (USA) to play.

First run
---------

From a command prompt (cmd.exe or PowerShell):

    KnifeEdgeRecompiled.exe --rom C:\path\to\your\dump

Or simply double-click KnifeEdgeRecompiled.exe and select your ROM dump in
the file dialog that opens.

Accepts .z64, .v64, or .n64 dumps and validates the ROM's hash before
proceeding. A normalized copy is cached in %LOCALAPPDATA%\KnifeEdgeRecompiled,
so later runs don't need --rom again.

Keep the folder together: SDL2.dll, dxcompiler.dll, and dxil.dll must remain
in the same directory as KnifeEdgeRecompiled.exe. Do not copy the exe to a
different location without these dependencies.

Runtime requirements
---------------------

- Windows 10 or later, x86_64
- A GPU and up-to-date driver supporting Direct3D 12 (default renderer) or
  Vulkan
- Microsoft Visual C++ 2015–2022 Redistributable (x64) — most systems have
  this already. If the game fails to start with a missing-DLL error mentioning
  VCRUNTIME or MSVCP, download and install it from:
  https://aka.ms/vs/17/release/vc_redist.x64.exe

Configuration
-------------

Settings live in %LOCALAPPDATA%\KnifeEdgeRecompiled\config.toml, created on
first run. To find this folder quickly, press Win+R, type the path above, and
press Enter. You can override the data directory by setting the KE_DATA_DIR
environment variable.

See the project README for the full list of options (enhancement profiles,
input tuning, frame pacing, etc).

Diagnostic log
--------------

A console window opens alongside the game. This is the diagnostic log. The first
line displays the exact build commit — include it in any bug report.

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
