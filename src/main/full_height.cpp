// Full-height missions enhancement (analysis/docs/enhancements.md,
// analysis/docs/letterbox-full-height.md for the full RE evidence).
//
// Missions render at 320x200, not the console's full 320x240 -- the in-game
// overlay's per-frame clear builder (func_800C277C) reads a height global
// (0x8010BAE4) and derives an RDP scissor rectangle uly = (240-H)/2, cropping
// 20 lines off the top and bottom. That's the *only* thing the height global
// feeds: the viewport (Vp at 0x8016AEC0, 320x240) and the projection (30deg
// FOV, 4:3, gSPClipRatio(FRUSTRATIO_2)) are already full-frame and unaffected,
// so removing the scissor is a genuine uncrop of already-rendered scene, not
// a stretch.
//
// func_800C3044(w, h) is the lo-res mode setter that stores the height
// global; the mission overlay is its only caller passing h=200 (the ROM's
// only other caller is the front-end, passing (320,240) already). The hook
// in analysis/gen_syms.py rewrites that one call's height argument via
// ke_view_height() below, entirely on the host side -- no recompiled
// instruction is altered.
//
// NOT part of the "enhanced" profile yet (src/main/config.cpp): pending the
// project owner's hands-on verification on real hardware-adjacent footage.

#include <atomic>
#include <cstdint>

#include "support.h"

namespace {
    // Set by kerecomp::set_full_height_enhancement() (called from main(),
    // before recomp::start()) from the resolved config's effective
    // enhancements.full_height. Read by ke_view_height() below.
    std::atomic<bool> full_height_enabled{false};
}

// Hooked at the entry of func_800C3044(w, h), the lo-res mode setter.
// Rewrites its height argument (a1) from 320x200 to 320x240 when the
// enhancement is on -- the (320,200) pair is unique to the mission call
// site, so guarding on it leaves the front-end's (320,240) call and the
// blank/unblank pair (h=0) untouched.
extern "C" uint32_t ke_view_height(uint32_t w, uint32_t h) {
    if (full_height_enabled.load(std::memory_order_relaxed) && w == 320 && h == 200) {
        return 240;
    }
    return h;
}

void kerecomp::set_full_height_enhancement(bool on) {
    full_height_enabled.store(on, std::memory_order_relaxed);
}
