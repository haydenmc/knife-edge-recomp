// Extended aim range enhancement (analysis/docs/enhancements.md;
// analysis/docs/hud-relocation.md, "Reticle range extension" for the full RE
// evidence and the patch plan this implements).
//
// The aiming reticle is an integrator the game re-clamps to +-128 / +-84 N64
// pixels on every frame, in the tail of func_8016E520_1501A0. Those rails are
// 80% of the half-width of the original 4:3 view and 70% of the half-height of
// the 320x200 mission view -- a deliberate margin, not a technical limit. With
// `widescreen` and `full_height` on there is visibly more frame than the
// reticle can be pointed at, and this enhancement lets it reach the same
// fraction of the *enlarged* view instead:
//
//     X rail = 128 * (window aspect) / (4/3)      = 170 at 16:9
//     Y rail = 84  * 240 / 200                    = 100 with full_height
//
// i.e. the rails are scaled by exactly how much the view opened, keeping the
// game's own edge margins and keeping 1 reticle unit = 1 N64 pixel. That last
// property is why this is an *extension* and not a rescale: every constant in
// analysis/docs/mouse-aim.md (the stick->units curve, the 20 units/frame cap,
// the positional controller's deadbeat threshold table) stays literally valid.
// Scaling the per-frame step to match -- so a rail-to-rail flick takes the
// same time as vanilla -- is a deliberate follow-on knob, not part of this.
//
// Three things had to agree, and only two of them needed a patch:
//
//   A. the clamp. Two hooks (analysis/gen_syms.py, EXTENDED_AIM_HOOKS) bracket
//      the game's own clamp block: the first stashes the unclamped pair, the
//      second re-clamps the stash to our rails and stores it back.
//
//   B. the aim ray. Nothing: func_8019C1D0_1501A0 turns the same two integers
//      into a direction with atan2(pixel, 120/tan(FOV/2)), and that focal
//      length is the rendering frustum's own -- verified two ways in the RE
//      doc -- so the drawn crosshair and the shot direction stay the same two
//      integers at any value, inside or outside the rails.
//
//   C. the draw. The reticle's sprite is blitted through the game's generic 2D
//      sprite library, which re-asserts a *software* clip box of
//      (0,0)-(319,239) on every blit and drops any rect that leaves it. Two
//      more hooks handle that: the blit shifts the reticle's x right by a bias
//      B (so the emitted G_TEXRECT coordinates, which are 12-bit *unsigned*,
//      stay non-negative at the left rail) and marks the scissor call it is
//      about to make; the scissor hook widens the box for that one call. The
//      bias is undone at draw time by the reticle's hud_relocation stub
//      (src/main/rt64_render_context.cpp), which subtracts the same B.
//
// THE OFF-PATH IS THE FIDELITY GUARANTEE. All four hooks exist in the
// recompiled code in every profile, vanilla included -- there is no such thing
// as "not compiled in" here -- so vanilla-faithfulness lives entirely in the
// early-outs below. Each one is a single relaxed atomic load against the
// resolved rails, and rails_x()/rails_y() only ever return something other
// than 128/84 when the enhancement resolved to a wider value.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>

// For the MEM_* accessors: librecomp stores game RAM byte-swapped within each
// 32-bit word, so these are the only correct way to read it by hand (and the
// same macros the recompiled code itself uses).
#include "recomp.h"

#include "support.h"

namespace {
    // ---- resolved state --------------------------------------------------
    //
    // Set from main() before recomp::start() (the halves this run is allowed
    // to widen at all) and from update_gfx() whenever the window is resized
    // (the aspect the horizontal rail is derived from). Read by the hooks
    // below on game threads and by the renderer when it builds the reticle's
    // relocation stub.
    //
    // The horizontal half additionally needs hud_relocation's machinery -- see
    // set_extended_aim_enhancement()'s comment in support.h -- so main() folds
    // that flag into `horizontal` rather than this file second-guessing it.
    std::atomic<bool> allow_horizontal{false};
    std::atomic<bool> allow_vertical{false};

    // Cleared by the renderer if its scratch RDRAM turns out not to be ours
    // (src/main/rt64_render_context.cpp's scratch_usable()): without the stub
    // there is nothing to undo the draw bias with, so the horizontal half has
    // to fall back to the vanilla rail. Fails safe, and in practice resolves
    // on the run's very first display list -- long before a mission starts.
    std::atomic<bool> draw_supported{true};

    // Live window aspect, republished by update_gfx(). The initial value is
    // create_window()'s 1280x720, and it only matters for the frames before
    // the first republish.
    std::atomic<double> window_aspect{16.0 / 9.0};

    // The game's own rails, and the two dimensions they are a fraction of.
    constexpr int32_t vanilla_rail_x = 128;
    constexpr int32_t vanilla_rail_y = 84;
    constexpr double base_aspect = 4.0 / 3.0;
    // full_height uncrops the mission view from 200 to 240 lines
    // (analysis/docs/letterbox-full-height.md), so the vertical rail scales by
    // 240/200 exactly: 84 * 1.2 = 100.8, truncated to keep the sprite's own
    // 16 px half-extent clear of the frame (100 + 16 = 116 < 120).
    constexpr int32_t full_height_rail_y = 100;

    // Sanity bound on the horizontal rail. Nothing in the mechanism needs it
    // -- the bias and the widened box are both derived from the rail, and the
    // texrect coordinate field would not overflow until ~490 -- but an absurd
    // window aspect (or a bogus one from a zero-height window) should degrade
    // rather than produce a reticle nobody can see. 256 is a 32:9 window.
    constexpr int32_t max_rail_x = 256;

    int32_t rails_x() {
        if (!allow_horizontal.load(std::memory_order_relaxed) ||
            !draw_supported.load(std::memory_order_relaxed)) {
            return vanilla_rail_x;
        }
        const double aspect = window_aspect.load(std::memory_order_relaxed);
        if (!(aspect > 0.0)) {
            return vanilla_rail_x;
        }
        const double scaled = vanilla_rail_x * (aspect / base_aspect);
        // Never below the vanilla rail: a narrower-than-4:3 window is the one
        // case where "scale by how much the view opened" would take something
        // away, and an enhancement that makes the game strictly worse than
        // hardware is not what the flag promises.
        return std::clamp(static_cast<int32_t>(std::floor(scaled)), vanilla_rail_x, max_rail_x);
    }

    int32_t rails_y() {
        return allow_vertical.load(std::memory_order_relaxed) ? full_height_rail_y
                                                              : vanilla_rail_y;
    }

    // Draw-side bias, in N64 pixels: how far right the reticle's blit is
    // shifted so its texrect stays non-negative, and equally how far left the
    // relocation stub shifts it back.
    //
    // It is DERIVED from the rail rather than stored, so the two can never
    // disagree -- risk 2 in the RE doc's register ("the bias/offset pair is two
    // numbers that must agree"). B = rail - 128 makes it 0 exactly when the
    // rail is vanilla, i.e. the draw side is untouched unless the clamp was
    // widened. Left edge: -rail + 144 + B = 16 >= 0 for any rail. Right edge:
    // rail + 144 + B + 32 = 2*rail + 48, against a box widened to 319 + 2B =
    // 2*rail + 63, i.e. 15 px of headroom at any rail.
    int32_t draw_bias_px(int32_t rail_x) {
        return rail_x - vanilla_rail_x;
    }

    // ---- A: the clamp ----------------------------------------------------
    //
    // Per-player reticle state is a structure-of-arrays at 0x8011D458 + slot*4
    // with X at +0x64 and Y at +0x74, so slot 0 is 0x8011D4BC / 0x8011D4CC --
    // mouse-aim.md's two words are element 0 of two four-element arrays.
    //
    // SIGN-EXTENDED, per CLAUDE.md's first gotcha: MEM_W indexes rdram as
    // (addr - 0xFFFFFFFF80000000), so a bare positive 0x8011D4BC reads ~4 GB
    // out of bounds.
    constexpr gpr reticle_x_base = static_cast<gpr>(static_cast<int32_t>(0x8011D4BC));
    constexpr gpr reticle_y_base = static_cast<gpr>(static_cast<int32_t>(0x8011D4CC));
    constexpr uint32_t max_slots = 4;

    // The unclamped pair, stashed by the entry hook for the exit hook.
    //
    // A plain scalar rather than a per-slot array: the two hook sites bracket a
    // straight-line arithmetic block with no call and no yield point in it, on
    // one cooperatively-scheduled game thread, so the entry/exit pair is always
    // adjacent in time. `stash_valid` is nonetheless load-bearing -- three
    // control paths reach the exit hook without passing the entry one (the
    // recentre path branches straight to the `jr`, as do two early `bne`s), and
    // on those the exit hook must do nothing at all.
    bool stash_valid = false;
    uint32_t stash_slot = 0;
    int32_t stash_x = 0;
    int32_t stash_y = 0;

    // ---- C: the draw -----------------------------------------------------
    //
    // Pointer to each slot's reticle sprite object; the blit's a0.
    constexpr gpr reticle_sprite_table = static_cast<gpr>(static_cast<int32_t>(0x8019D864));

    // The per-VI-retrace callback the game registers while a mission is
    // running (func_8019CF84 of the shared in-game overlay seg_1501A0). Every
    // screen registers its own, so this value names the screen -- see
    // analysis/docs/mouse-aim.md section 6.2, and src/main/main.cpp, which uses
    // the same constant for the positional mouse controller's first gate.
    //
    // It gates the blit hook because the sprite-pointer table above lives in
    // that same overlay: out of a mission the overlay may be unloaded and those
    // four words are then stale, so a front-end sprite could in principle
    // collide with one. In a mission the table is live and the comparison is
    // exact. Fails closed -- an unrecognised screen gets vanilla behavior.
    constexpr uint32_t mission_retrace_callback = 0x8019CF84u;

    // Set by the blit hook, consumed by the very next spScissor call, which is
    // the one func_800C6C6C itself makes a few instructions later (its only
    // callees in between -- spMove, spScale, spColor -- are pure stores). Never
    // left set: the scissor hook clears it unconditionally.
    std::atomic<bool> scissor_marked{false};

    // The lo-res box every blit re-asserts, as an lrx: spScissor(0, 0x13F, 0,
    // 0xEF). The hi-res box (0x27F) is deliberately not widened -- the reticle
    // is only ever drawn in the lo-res mission mode, and the bias is expressed
    // in lo-res pixels, so substituting into a hi-res call would be wrong
    // rather than merely useless.
    constexpr int32_t sprite_scissor_lrx_lores = 0x13F;
}

// Hooked at 0x8016EC30, the head of func_8016E520_1501A0's clamp block, where
// $a0 is still the player slot.
extern "C" void ke_reticle_clamp_stash(uint8_t* rdram, uint32_t slot) {
    stash_valid = false;
    if (rails_x() == vanilla_rail_x && rails_y() == vanilla_rail_y) {
        return;   // vanilla rails: leave the game's own clamp as the only one
    }
    if (slot >= max_slots) {
        return;
    }
    stash_slot = slot;
    stash_x = MEM_W(static_cast<int32_t>(slot) * 4, reticle_x_base);
    stash_y = MEM_W(static_cast<int32_t>(slot) * 4, reticle_y_base);
    stash_valid = true;
}

// Hooked at 0x8016ECF0, the `jr $ra`. Reachable without a stash (see
// stash_valid above), in which case it does nothing.
//
// The re-clamp reproduces the semantics of the four slti blocks it replaces
// exactly, only against wider bounds: the game stores +128 when X >= +129 and
// -128 when X < -128 (and +84 / -84 likewise), i.e. plain
// clamp(X, -128, +128) with both endpoints inclusive. std::clamp is the same
// function; at the vanilla rails it would write back exactly what the game's
// own clamp just wrote, which is why the off-path can skip the write entirely
// rather than having to be bit-compared against it.
extern "C" void ke_reticle_clamp_apply(uint8_t* rdram) {
    if (!stash_valid) {
        return;
    }
    stash_valid = false;
    const int32_t rx = rails_x();
    const int32_t ry = rails_y();
    MEM_W(static_cast<int32_t>(stash_slot) * 4, reticle_x_base) = std::clamp(stash_x, -rx, rx);
    MEM_W(static_cast<int32_t>(stash_slot) * 4, reticle_y_base) = std::clamp(stash_y, -ry, ry);
}

// Hooked at the entry of func_800C6C6C(sprite, x, y, ...), the game's generic
// 2D sprite blit (126 call sites). Returns the x it should use.
//
// Costs one relaxed atomic load on every blit in the game when the enhancement
// is off, and additionally one published-state read plus up to four RDRAM word
// reads on the blits of a live mission when it is on.
extern "C" int32_t ke_reticle_blit_x(uint8_t* rdram, uint32_t sprite, int32_t x) {
    const int32_t bias = draw_bias_px(rails_x());
    if (bias == 0) {
        return x;
    }
    if (kerecomp::reticle_state().retrace_callback != mission_retrace_callback) {
        return x;
    }
    for (uint32_t slot = 0; slot < max_slots; slot++) {
        if (static_cast<uint32_t>(MEM_W(static_cast<int32_t>(slot) * 4, reticle_sprite_table))
                != sprite) {
            continue;
        }
        // This blit is a reticle. Widen the box it is about to assert, and
        // shift it right so the left rail's texrect stays non-negative.
        scissor_marked.store(true, std::memory_order_relaxed);
        return x + bias;
    }
    return x;
}

// Hooked at the entry of spScissor(ulx, lrx, uly, lry) -- a callee hook rather
// than a call-site one because a3 is assigned in the `jal`'s delay slot and
// N64Recomp emits delay slots before the call. Returns the lrx to use.
//
// Only ulx/lrx move: the vertical rail (100 + 16 = 116) is comfortably inside
// the box's own 0..239, so the vertical half of this enhancement needs no draw
// change at all and works with hud_relocation off.
extern "C" int32_t ke_sprite_scissor_lrx(int32_t lrx) {
    if (!scissor_marked.exchange(false, std::memory_order_relaxed)) {
        return lrx;
    }
    if (lrx != sprite_scissor_lrx_lores) {
        return lrx;
    }
    return lrx + 2 * draw_bias_px(rails_x());
}

void kerecomp::set_extended_aim_enhancement(bool horizontal, bool vertical) {
    allow_horizontal.store(horizontal, std::memory_order_relaxed);
    allow_vertical.store(vertical, std::memory_order_relaxed);
}

void kerecomp::set_extended_aim_window_aspect(double aspect) {
    if (aspect > 0.0) {
        window_aspect.store(aspect, std::memory_order_relaxed);
    }
}

void kerecomp::set_extended_aim_draw_supported(bool supported) {
    draw_supported.store(supported, std::memory_order_relaxed);
}

kerecomp::AimRails kerecomp::extended_aim_rails() {
    AimRails rails;
    rails.x = rails_x();
    rails.y = rails_y();
    rails.draw_bias = draw_bias_px(rails.x);
    return rails;
}
