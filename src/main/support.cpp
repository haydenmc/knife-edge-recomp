#include "support.h"

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#if defined(_WIN32)
#   include "SDL.h"
#else
#   include "SDL2/SDL.h"
#endif

std::filesystem::path kerecomp::get_app_folder_path() {
    // TODO: see header comment; this is a placeholder location. Deliberately
    // not named after the executable itself (e.g. "KnifeEdgeRecompiled") to
    // avoid colliding with the binary when run from its own build directory.
    std::filesystem::path path = std::filesystem::current_path() / "ke_recomp_data";
    // librecomp writes the stored ROM and config here without creating the
    // directory itself; a missing dir makes every ROM validation fail silently.
    std::error_code ec;
    std::filesystem::create_directories(path, ec);
    return path;
}

void kerecomp::show_error_message_box(const char* title, const char* message) {
    if (SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, message, nullptr) != 0) {
        std::fprintf(stderr, "[%s] %s\n", title, message);
    }
}

namespace {
    const bool perf_enabled = std::getenv("KE_PERF") != nullptr;
    std::atomic<uint64_t> perf_vis{0};
    std::atomic<uint64_t> perf_dls{0};
}

void kerecomp::perf_count_dl() {
    if (perf_enabled) {
        perf_dls.fetch_add(1, std::memory_order_relaxed);
    }
}

void kerecomp::perf_count_vi() {
    if (!perf_enabled) {
        return;
    }
    using clock = std::chrono::steady_clock;
    static clock::time_point last = clock::now();
    static uint64_t last_vis = 0, last_dls = 0;

    uint64_t vis = perf_vis.fetch_add(1, std::memory_order_relaxed) + 1;
    clock::time_point now = clock::now();
    double elapsed = std::chrono::duration<double>(now - last).count();
    if (elapsed >= 1.0) {
        uint64_t dls = perf_dls.load(std::memory_order_relaxed);
        std::fprintf(stderr, "[perf] %6.2f VI/s  %6.2f frames/s  (total vi=%llu dl=%llu)\n",
                     (vis - last_vis) / elapsed, (dls - last_dls) / elapsed,
                     (unsigned long long)vis, (unsigned long long)dls);
        std::fflush(stderr);
        last = now;
        last_vis = vis;
        last_dls = dls;
    }
}
