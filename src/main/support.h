#pragma once

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

    // ---- enhancements (analysis/docs/enhancements.md, src/main/full_height.cpp) --
    // Turns the full_height enhancement on/off (removes the in-mission
    // letterbox, rendering the full 320x240 frame instead of 320x200).
    // Implemented in full_height.cpp. Call once, before recomp::start(), with
    // the resolved kerecomp::EnhancementFlags's value.
    void set_full_height_enhancement(bool on);
}
