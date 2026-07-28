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
// The default budget is the game's own number. The debug/profiling path inside
// func_801978C0 (in-game overlay, gated on 0x8011D298) ends with a hand-written
// frame limiter:
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

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstdint>

// ultramodern/src/scheduling.cpp. Waits up to 1 ms for an external message,
// delivers it, then hands execution to any higher-priority ready thread. This
// is the only legal way for recompiled code to burn game time: a plain sleep
// would freeze ultramodern's cooperative scheduler (see boot-debug.md 2).
extern "C" void yield_self_1ms(uint8_t* rdram);

namespace {
    using clock_type = std::chrono::steady_clock;

    // 2,800,000 OSTime counts / 46.875 MHz.
    constexpr double default_frame_ms = 2800000.0 / 46875.0;

    double frame_budget_ms() {
        static const double value = []() {
            const char* env = std::getenv("KE_RCP_FRAME_MS");
            double ms = default_frame_ms;
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
        yield_self_1ms(rdram);
    }
}
