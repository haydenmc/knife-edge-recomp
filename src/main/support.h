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
}
