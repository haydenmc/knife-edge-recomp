#include "support.h"

#include <cstdio>

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
