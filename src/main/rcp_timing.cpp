// Models how long the N64's RCP takes to render one frame.
//
// Why this exists (analysis/docs/timing-and-mission-debug.md):
//
// Knife Edge has no frame timer of its own. Its logic step *is* its render
// step: the game registers a per-VI-retrace callback (func_800D1640 stores it
// at 0x800EBC00) and the dispatcher thread func_800D2930 invokes it once per
// retrace with the number of graphics tasks still in flight (0x8013C280) in
// $a0. Every one of those callbacks - the KEMCO logo, the title screen, each
// attract scene, and the in-mission one at 0x8019CF84 - starts with
//
//     if (tasks_outstanding > 0) return;      // `bgtz $a0, epilogue`
//
// and otherwise advances the world by exactly one step and submits one display
// list. So the game's speed is *defined* by how many VI retraces the RCP needs
// to finish a frame: on console a 3D frame spans several retraces, so the
// callback no-ops on most of them.
//
// Under librecomp+RT64 a graphics task is retired almost instantly
// (ultramodern's gfx_thread_func calls sp_complete() on receipt and
// dp_complete() the moment RT64's send_dl returns), so the counter is 0 at
// every retrace and the game ran at a full 60 steps/s - roughly 4x too fast.
//
// The fix is to give a graphics task a minimum residency, which is what the two
// hooks in analysis/gen_syms.py (RCP_PACING_HOOKS) wire up: ke_gfx_task_begin()
// at the game's osSpTaskStartGo call and ke_gfx_task_end() just before it
// reports the task complete, in the graphics task thread func_800D25F0.
//
// The default budget is the game's own number. func_801978C0 (in-game overlay),
// which runs only while a cutscene is playing (0x8011D298 != 0 - see
// timing-and-mission-debug.md section 5.1), ends with a hand-written frame
// limiter:
//
//     801978AE0  jal osGetTime
//     ...        while (hi != 0 || lo < 0x002AB980) osGetTime();
//     80197B38   osSetTime(0, 0)
//
// 0x2AB980 = 2,800,000 OSTime counts; OSTime runs at 46.875 MHz, so that is
// 59.733 ms - the frame time the developers paced their own debug view at.
// Quantised by the 16.683 ms retrace it yields one game step every 4 retraces,
// i.e. 15 fps, which is exactly the ~4x that was reported.
//
// KE_RCP_FRAME_MS overrides it (0 disables the pacing entirely).
//
// tuning.rcp_frame_ms in config.toml (analysis/docs/enhancements.md) is a
// second, lower-precedence source for the same budget: set via
// kerecomp::set_rcp_frame_ms_tuning() from main() before the runtime starts,
// it applies only when KE_RCP_FRAME_MS is unset. Its meaning is deliberately
// not identical to the env var's: config's 0 means "no override, use the
// built-in 59.733 ms model" (there's no way to spell "explicitly disable
// pacing" in the config file), whereas the env var's existing 0-disables-it
// behavior is preserved exactly as it was for this wedge-fix logic.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstdint>

// For the MEM_* accessors used by the reticle publisher below. librecomp
// stores game RAM byte-swapped within each 32-bit word, so reading it by hand
// is a standing bug waiting to happen; these are the same macros the
// recompiled code itself uses.
#include "recomp.h"

#include "support.h"

// ultramodern/src/scheduling.cpp. Waits up to 1 ms for an external message,
// delivers it, then hands execution to any higher-priority ready thread. This
// is the only legal way for recompiled code to burn game time: a plain sleep
// would freeze ultramodern's cooperative scheduler (see boot-debug.md 2).
extern "C" void yield_self_1ms(uint8_t* rdram);

namespace {
    using clock_type = std::chrono::steady_clock;

    // Modelled RCP frame time, in milliseconds. Tuned by eye against real N64
    // gameplay footage (the project owner's capture), landing at 36.5 ms
    // (~24.6 measured game fps -- the effective rate is continuous, not
    // quantised to 60/N, because the game's per-retrace callback returns early
    // whenever a task is still outstanding).
    //
    // This deliberately REPLACES the earlier 2800000/46875 = 59.733 ms figure,
    // which came from the game's own cutscene playback limiter
    // (func_801978C0's osGetTime busy-wait). That number paced cutscenes
    // correctly -- unsurprisingly, since it is the cutscene limiter -- but had
    // no reason to match gameplay, where nothing self-limits and the pace is
    // purely how long the RCP takes. Cutscenes are unaffected by lowering this:
    // while our budget stays below the game's own limiter, cutscenes are paced
    // by that limiter and not by us.
    //
    // Caveat inherent to a single constant: on real hardware RCP frame time
    // rises with scene complexity, so busy scenes genuinely ran slower. This
    // matches the typical case, not every moment. A workload-proportional model
    // (scaling with display-list size) would track the real thing more closely
    // and is a candidate enhancement, not a bug fix.
    //
    // Override live with KE_RCP_FRAME_MS=<ms>, or persistently via
    // tuning.rcp_frame_ms in config.toml. NOTE: 0 disables pacing entirely
    // (the game then runs ~4x too fast); it does not mean "use this default".
    constexpr double default_frame_ms = 36.5;

    // Set by kerecomp::set_rcp_frame_ms_tuning() (called from main(), before
    // recomp::start()) from the resolved config file's tuning.rcp_frame_ms.
    // 0 = no file override. Read only by frame_budget_ms()'s one-time init,
    // which runs well after main() has had the chance to set this.
    std::atomic<double> tuning_frame_ms{0.0};

    double frame_budget_ms() {
        static const double value = []() {
            double ms = default_frame_ms;
            double file_ms = tuning_frame_ms.load(std::memory_order_relaxed);
            if (file_ms > 0.0) {
                ms = file_ms;
            }
            const char* env = std::getenv("KE_RCP_FRAME_MS");
            if (env != nullptr) {
                char* end = nullptr;
                double parsed = std::strtod(env, &end);
                if (end != env && parsed >= 0.0) {
                    ms = parsed;
                }
            }
            std::fprintf(stderr, "[timing] RCP graphics-task budget: %.3f ms (%.2f fps cap)\n",
                         ms, ms > 0.0 ? 1000.0 / ms : 0.0);
            return ms;
        }();
        return value;
    }

    // Only ever touched by the game's graphics task thread (func_800D25F0),
    // which runs one task at a time; atomic purely for tidiness.
    std::atomic<clock_type::time_point> task_start{clock_type::time_point{}};

    // Last time some game thread was seen spinning in func_800D2B40 waiting for
    // 0x8013C280 ("graphics tasks in flight") to reach 0.  Written by the
    // waiting thread, read by whichever thread is about to queue the next task.
    std::atomic<clock_type::time_point> idle_wait_seen{clock_type::time_point{}};

    // How stale an idle_wait_seen stamp may be and still count as "a thread is
    // waiting".  The waiter refreshes it once per yield_self_1ms, so anything
    // within a few of those is live; once it leaves the loop the stamp ages out
    // and pacing resumes on the very next graphics task.
    constexpr std::chrono::milliseconds idle_wait_live{5};

    bool idle_waiter_live() {
        clock_type::time_point seen = idle_wait_seen.load(std::memory_order_relaxed);
        return clock_type::now() - seen <= idle_wait_live;
    }

    // ---- reticle publisher (analysis/docs/mouse-aim.md) -------------------
    //
    // Positional mouse aim has to know where the game currently thinks the
    // reticle is, and this file's ke_gfx_task_end() is the project's only
    // per-game-frame hook that is handed `rdram` -- the game advances the
    // world exactly once per submitted display list (see the header comment),
    // so a read here samples every frame and never twice within one. That is
    // the whole reason this lives in the pacing file rather than beside the
    // controller in main.cpp.
    //
    // Addresses must be SIGN-EXTENDED (CLAUDE.md's first gotcha): MEM_W
    // indexes rdram as `addr - 0xFFFFFFFF80000000`, so a bare positive
    // 0x8011D4BC would read ~4 GB out of bounds.
    constexpr gpr reticle_x_addr = static_cast<gpr>(static_cast<int32_t>(0x8011D4BC));
    constexpr gpr reticle_y_addr = static_cast<gpr>(static_cast<int32_t>(0x8011D4CC));
    constexpr gpr mission_clock_addr = static_cast<gpr>(static_cast<int32_t>(0x8011D1CC));
    // The game's per-VI-retrace callback pointer (func_800D1640 stores it here;
    // func_800D2930 dispatches it -- see this file's header comment). Whichever
    // screen is running owns it, so its value names the screen. Published so
    // get_input() can tell "in a mission" from "in the front end", which the
    // reticle words alone cannot do: nothing zeroes them on mission exit, so a
    // menu legitimately reads a stale +-128/+-84.
    constexpr gpr retrace_callback_addr = static_cast<gpr>(static_cast<int32_t>(0x800EBC00));

    // Written only here (on the game's graphics task thread), read only by
    // get_input() on the controller-read thread. Relaxed is right for the same
    // reason as main.cpp's input atomics: three independent scalars whose
    // slight skew across one frame boundary is indistinguishable from sampling
    // a frame earlier, which the controller already tolerates.
    std::atomic<int32_t> reticle_x{0};
    std::atomic<int32_t> reticle_y{0};
    std::atomic<uint32_t> mission_clock{0};
    std::atomic<uint32_t> retrace_callback{0};

    void publish_reticle_state(uint8_t* rdram) {
        reticle_x.store(MEM_W(0, reticle_x_addr), std::memory_order_relaxed);
        reticle_y.store(MEM_W(0, reticle_y_addr), std::memory_order_relaxed);
        mission_clock.store(static_cast<uint32_t>(MEM_W(0, mission_clock_addr)),
                            std::memory_order_relaxed);
        retrace_callback.store(static_cast<uint32_t>(MEM_W(0, retrace_callback_addr)),
                               std::memory_order_relaxed);
    }
}

kerecomp::ReticleState kerecomp::reticle_state() {
    ReticleState state;
    state.x = reticle_x.load(std::memory_order_relaxed);
    state.y = reticle_y.load(std::memory_order_relaxed);
    state.clock = mission_clock.load(std::memory_order_relaxed);
    state.retrace_callback = retrace_callback.load(std::memory_order_relaxed);
    return state;
}

// Hooked at the game's osSpTaskStartGo call site: the RCP has just been handed
// a display list.
extern "C" void ke_gfx_task_begin(void) {
    task_start.store(clock_type::now(), std::memory_order_relaxed);
}

// Hooked just before the graphics task thread posts "task complete" back to the
// task-done thread (which is what decrements the outstanding-task counter the
// game's per-retrace callback reads). Holds the completion until the modelled
// RCP frame time has elapsed.
extern "C" void ke_gfx_task_end(uint8_t* rdram) {
    // Ahead of the budget check below so the reticle keeps being published
    // even with pacing disabled (KE_RCP_FRAME_MS=0), where this early-returns.
    publish_reticle_state(rdram);

    double budget = frame_budget_ms();
    if (budget <= 0.0) {
        return;
    }
    clock_type::time_point deadline =
        task_start.load(std::memory_order_relaxed) +
        std::chrono::microseconds{static_cast<int64_t>(budget * 1000.0)};

    // Cap the wait so a bogus KE_RCP_FRAME_MS or a clock jump can never wedge
    // the graphics thread.
    clock_type::time_point limit = clock_type::now() + std::chrono::milliseconds{500};
    if (deadline > limit) {
        deadline = limit;
    }

    while (clock_type::now() < deadline) {
        // A game thread waiting in func_800D2B40 for the RCP to go idle cannot
        // make progress until this task retires, and cannot be scheduled during
        // the sliver of time between it retiring and the next one being queued
        // (see ke_rcp_idle_wait below). Retire now and let it through; the
        // console's wait resolves inside one frame too.
        if (idle_waiter_live()) {
            break;
        }
        yield_self_1ms(rdram);
    }
}

// Hooked into func_800D2B40's poll loop, which is
//
//     while (*(u32*)0x8013C280 != 0) {}      // wait until the RCP is idle
//
// and is what func_800D1640 runs before it swaps the per-retrace callback
// pointer at 0x800EBC00.
//
// Yields exactly like the generic spin hook, and additionally publishes "a
// thread is waiting for the RCP to go idle" so ke_gfx_task_end() above can stop
// holding the current task. Without that the wait never ends:
//
//   * modelling RCP frame time keeps 0x8013C280 non-zero for essentially the
//     whole frame - measured over 4.3M samples of a live mission it read 0 for
//     0.067% of the time, i.e. ~30 microseconds between one task retiring and
//     the next being queued (on console that gap is the milliseconds the CPU
//     spends building the next display list; our host builds it ~1000x faster);
//   * ultramodern only ever hands execution to a *higher* priority thread
//     (check_running_queue in ultramodern/src/scheduling.cpp), so this waiter is
//     resumed exactly when the retrace-callback thread blocks - which is just
//     after it has queued the next task. Every poll therefore reads a non-zero
//     counter, deterministically, not merely with bad luck.
//
// A console CPU polls the word every few cycles and always lands in the gap, so
// func_800D1640 returns within a frame. See
// analysis/docs/timing-and-mission-debug.md section 5.
extern "C" void ke_rcp_idle_wait(uint8_t* rdram) {
    idle_wait_seen.store(clock_type::now(), std::memory_order_relaxed);
    yield_self_1ms(rdram);
}

void kerecomp::set_rcp_frame_ms_tuning(double ms) {
    tuning_frame_ms.store(ms, std::memory_order_relaxed);
}
