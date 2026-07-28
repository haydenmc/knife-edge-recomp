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
