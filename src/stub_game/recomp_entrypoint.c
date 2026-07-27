// Stub placeholder for the recompiled game entrypoint.
//
// Once a real config.toml is fed through N64Recomp (see
// analysis/docs/n64recomp-formats.md), the ROM function at
// (vram == entrypoint, rom == 0x1000) gets renamed to `recomp_entrypoint` and
// emitted here with real MIPS-translated logic. Until then this stub exists
// purely so RecompiledFuncs has something to compile and KnifeEdgeRecompiled
// can link end-to-end.
//
// It is never actually invoked by this skeleton: recomp::start() only calls
// GameEntry::entrypoint after a ROM has been selected and validated via
// recomp::start_game(), and that flow isn't wired up yet (see the ROM-picker
// TODO in src/main/main.cpp). Should it ever run, it's a safe no-op.

#include "recomp.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
}
