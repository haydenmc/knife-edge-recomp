#pragma once

#include <cstdint>
#include <filesystem>

// Small helpers used by main.cpp. Kept deliberately tiny for this skeleton;
// Zelda64Recomp's equivalent (src/main/support.cpp) also handles native file
// dialogs and app-bundle resource paths, neither of which this project needs
// yet (no ROM picker, no mod install flow).
namespace kerecomp {
    // Base directory used for config/save data.
    //
    // TODO: use a proper per-OS user data directory (XDG_DATA_HOME on Linux,
    // %APPDATA% on Windows, Application Support on macOS) once save/config
    // handling is implemented. For now this just anchors everything under a
    // folder next to the current working directory so the skeleton has
    // somewhere writable to point recomp::register_config_path() at.
    std::filesystem::path get_app_folder_path();

    // Shows a native OS error dialog. Falls back to stderr if SDL's video
    // subsystem isn't available (e.g. running headless).
    void show_error_message_box(const char* title, const char* message);

    // ---- pacing instrumentation (analysis/docs/timing-and-mission-debug.md) --
    // Off unless KE_PERF is set in the environment. When on, one line per
    // second is written to stderr with the measured VI retrace rate and the
    // game's own frame rate (graphics display lists submitted per second).
    void perf_count_vi();
    void perf_count_dl();

    // Writes the commit this binary was built from to stdout at startup, so a
    // bug report identifies an exact tree. See src/main/build_info.h.in.
    void log_build_info();

    // ---- tuning (analysis/docs/enhancements.md, src/main/rcp_timing.cpp) ----
    // Sets the config-file-derived RCP frame-time budget, in milliseconds
    // (tuning.rcp_frame_ms; 0 = no override). Implemented in rcp_timing.cpp.
    // The KE_RCP_FRAME_MS env var still takes precedence when set. Call once,
    // before recomp::start(), with the resolved kerecomp::Config's value.
    void set_rcp_frame_ms_tuning(double ms);

    // ---- mouse aim (analysis/docs/mouse-aim.md, src/main/rcp_timing.cpp) ----
    // The game's aiming state, sampled out of game RAM once per game frame and
    // published for src/main/main.cpp's get_input() to close its positional
    // mouse-aim loop on. Read-only with respect to game memory.
    //
    // x/y are the reticle position in N64 pixels relative to the center of the
    // in-mission viewport (+x right, +y DOWN); measured ranges are x [-128,
    // +128] and y [-84, +84]. `clock` is the game's own per-frame counter
    // (0x8011D1CC): it advances by 1 per game frame while a mission runs, so a
    // change in it is the "the world stepped" signal the controller gates on.
    // `retrace_callback` is the game's per-VI-retrace callback pointer
    // (0x800EBC00), which identifies WHICH screen is running and is therefore
    // the "are we in a mission at all" test -- the reticle words themselves
    // cannot answer that, since nothing zeroes them on mission exit. Published
    // raw rather than as a bool so a diagnostic can report what it actually
    // was; see analysis/docs/mouse-aim.md sections 6.2 and 9.
    struct ReticleState {
        int32_t x = 0;
        int32_t y = 0;
        uint32_t clock = 0;
        uint32_t retrace_callback = 0;
    };
    ReticleState reticle_state();

    // ---- enhancements (analysis/docs/enhancements.md, src/main/full_height.cpp) --
    // Turns the full_height enhancement on/off (removes the in-mission
    // letterbox, rendering the full 320x240 frame instead of 320x200).
    // Implemented in full_height.cpp. Call once, before recomp::start(), with
    // the resolved kerecomp::EnhancementFlags's value.
    void set_full_height_enhancement(bool on);
}
