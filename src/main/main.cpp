// Knife Edge Recompiled -- runtime entry point.
//
// This is a minimal shim modeled on Zelda64Recomp's src/main/main.cpp (see
// analysis/docs/build-notes.md for what was kept vs dropped): it brings up
// SDL, wires ultramodern's callback surface to RT64 for rendering, registers
// this project's recomp::GameEntry, and starts the recomp runtime.
//
// Deliberately NOT implemented yet (see TODOs below and in build-notes.md):
//   - ROM picker / ROM validation UI (recomp::start_game is never called, so
//     the runtime comes up and idles waiting for a game that never starts)
//   - Controller input (ultramodern::input::callbacks_t is left empty)
//   - Audio output (ultramodern::audio_callbacks_t is left empty)
//   - Save data plumbing beyond what librecomp does by default
//   - Config persistence / any UI at all

#include <cstdio>
#include <cstdlib>
#include <string>

#include "ultramodern/ultra64.h"
#include "ultramodern/ultramodern.hpp"

#define SDL_MAIN_HANDLED
#if defined(_WIN32)
#   define WIN32_LEAN_AND_MEAN
#   include <Windows.h>
#   include "SDL.h"
#   include "SDL_syswm.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_syswm.h"
// SDL_syswm.h drags in X11 macros on Linux that collide with identifiers used
// elsewhere in the N64Recomp/librecomp headers.
#   undef None
#   undef Status
#   undef LockMask
#   undef ControlMask
#   undef Success
#   undef Always
#endif

#include "librecomp/game.hpp"

#include "rt64_render_context.h"
#include "support.h"

namespace kerecomp {
    // Defined in register_overlays.cpp.
    void register_overlays();
}

// Defined in src/stub_game/recomp_entrypoint.c today; will come from
// KE_GENERATED_DIR once the ROM has been run through N64Recomp.
extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);

namespace {
    const std::string version_string = "0.0.1";

    SDL_Window* window = nullptr;

    // Takes the message by value (not `const char*`) so callers passing
    // SDL_GetError() get it copied out of SDL's mutable internal error
    // buffer immediately, before show_error_message_box() makes further SDL
    // calls that could otherwise clobber it in place.
    void exit_error(std::string message) {
        kerecomp::show_error_message_box("Knife Edge Recompiled - Fatal Error", message.c_str());
        ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
    }

    ultramodern::gfx_callbacks_t::gfx_data_t create_gfx() {
        SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");

        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
            exit_error(SDL_GetError());
        }

        std::fprintf(stdout, "SDL video driver: %s\n", SDL_GetCurrentVideoDriver());

        return {};
    }

    ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
        uint32_t flags = SDL_WINDOW_RESIZABLE;

#if defined(__APPLE__)
        flags |= SDL_WINDOW_METAL;
#elif defined(RT64_SDL_WINDOW_VULKAN)
        flags |= SDL_WINDOW_VULKAN;
#endif

        window = SDL_CreateWindow("Knife Edge Recompiled", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, flags);

        if (window == nullptr) {
            exit_error(SDL_GetError());
        }

#if defined(__linux__)
        SDL_SetWindowFullscreen(window, 0);
#endif

        SDL_SysWMinfo wm_info;
        SDL_VERSION(&wm_info.version);
        SDL_GetWindowWMInfo(window, &wm_info);

#if defined(_WIN32)
        return ultramodern::renderer::WindowHandle{ wm_info.info.win.window, GetCurrentThreadId() };
#elif defined(__linux__) || defined(__ANDROID__)
        return ultramodern::renderer::WindowHandle{ window };
#elif defined(__APPLE__)
        SDL_MetalView view = SDL_Metal_CreateView(window);
        return ultramodern::renderer::WindowHandle{ wm_info.info.cocoa.window, SDL_Metal_GetLayer(view) };
#else
#       error "Unsupported platform"
#endif
    }

    // Pumps the SDL event queue. Runs once per iteration of recomp::start()'s
    // main loop regardless of whether a game is running.
    void update_gfx(void*) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                ultramodern::quit();
            }
        }
    }

    // TODO: no RSP microcodes are wired up yet. RT64 handles F3DEX/F3DLX
    // graphics tasks (M_GFXTASK) internally via RT64Context::send_dl, so this
    // is only consulted for other task types (e.g. the audio ucode, still
    // TBD per analysis/docs/n64recomp-formats.md). Returning nullptr causes
    // librecomp to log and skip the task rather than crash.
    RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
        std::fprintf(stderr, "No RSP microcode registered for task type %u yet\n", task->t.type);
        return nullptr;
    }
}

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    recomp::Version project_version{};
    if (!recomp::Version::from_string(version_string, project_version)) {
        exit_error(("Invalid version string: " + version_string).c_str());
        return EXIT_FAILURE;
    }

    recomp::register_config_path(kerecomp::get_app_folder_path());

    // TODO: rom_hash/save_type/game_id are placeholders until the ROM has
    // been analyzed enough to fill them in for real:
    //   - rom_hash: XXH3_64bits() over the raw ROM bytes (see
    //     recomp::is_rom_valid / check_hash in librecomp/src/recomp.cpp).
    //     0 will never match a real ROM, which is intentional for now --
    //     there's no ROM picker yet (see main.cpp header comment), so this
    //     never gets exercised.
    //   - save_type: unknown; Knife Edge's save mechanism hasn't been
    //     identified in analysis/ yet.
    //   - game_id: an arbitrary-but-stable internal id used for config/save
    //     file naming; not derived from the ROM.
    //
    // entrypoint_address is NOT a TODO: it's an established fact from
    // analysis/docs/n64recomp-formats.md (boot: ROM 0x1000 -> VRAM
    // 0x800C2400, CIC 6102).
    recomp::GameEntry knife_edge_entry {
        .rom_hash = 0, // TODO: XXH3_64bits() of the verified ROM.
        .internal_name = "KNIFE EDGE",
        .game_id = u8"knifeedge.n64.us.1.0", // TODO: confirm/replace once versioning is settled.
        .mod_game_id = "",
        .save_type = recomp::SaveType::None, // TODO: unknown save type.
        .is_enabled = true,
        .has_compressed_code = false,
        .entrypoint_address = 0x800C2400,
        .entrypoint = recomp_entrypoint,
    };

    recomp::register_game(knife_edge_entry);

    kerecomp::register_overlays();

    recomp::rsp::callbacks_t rsp_callbacks {
        .get_rsp_microcode = get_rsp_microcode,
    };

    ultramodern::renderer::callbacks_t renderer_callbacks {
        .create_render_context = kerecomp::renderer::create_render_context,
    };

    ultramodern::gfx_callbacks_t gfx_callbacks {
        .create_gfx = create_gfx,
        .create_window = create_window,
        .update_gfx = update_gfx,
    };

    // TODO: audio, input, events, threads and error-handling callbacks are
    // all optional (librecomp null-checks each field individually) and left
    // unset for this skeleton. Wire these up alongside the ROM picker.
    ultramodern::audio_callbacks_t audio_callbacks {};
    ultramodern::input::callbacks_t input_callbacks {};
    ultramodern::events::callbacks_t events_callbacks {};
    ultramodern::threads::callbacks_t threads_callbacks {};

    ultramodern::error_handling::callbacks_t error_handling_callbacks {
        .message_box = +[](const char* msg) {
            kerecomp::show_error_message_box("Knife Edge Recompiled", msg);
        },
    };

    recomp::start({
        .project_version = project_version,
        .window_handle = {},
        .rsp_callbacks = rsp_callbacks,
        .renderer_callbacks = renderer_callbacks,
        .audio_callbacks = audio_callbacks,
        .input_callbacks = input_callbacks,
        .gfx_callbacks = gfx_callbacks,
        .events_callbacks = events_callbacks,
        .error_handling_callbacks = error_handling_callbacks,
        .threads_callbacks = threads_callbacks,
    });

    return EXIT_SUCCESS;
}
