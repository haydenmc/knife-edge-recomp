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

#include "ultramodern/config.hpp"
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
#include "librecomp/rsp.hpp"

#include "audio.h"
#include "config.h"
#include "rt64_render_context.h"
#include "support.h"

#include <atomic>

namespace kerecomp {
    // Defined in register_overlays.cpp.
    void register_overlays();
    void reset_boot_window_overlays();
}

// Defined in src/stub_game/recomp_entrypoint.c today; will come from
// KE_GENERATED_DIR once the ROM has been run through N64Recomp.
extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);

// generated/us/rsp/aspMain.cpp -- RSPRecomp output for Knife Edge's audio
// microcode (stock libultra aspMain). See config/aspMain.us.toml.
// KE_HAVE_ASPMAIN is defined by CMake only when that file is in the build.
#if defined(KE_HAVE_ASPMAIN)
extern RspUcodeFunc aspMain;
#endif

namespace {
    // librecomp's init() registers every code section whose ROM range falls in
    // the first 1MB before handing control to the entrypoint, which for this
    // game wrongly registers six overlays (see register_overlays.cpp). Undo
    // that here: this runs after init() and before any recompiled game code.
    void knife_edge_entrypoint(uint8_t* rdram, recomp_context* ctx) {
        kerecomp::reset_boot_window_overlays();
        recomp_entrypoint(rdram, ctx);
    }
}

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

        // SDL2 enables text input during video init, which attaches an input
        // method (XIM/ibus/fcitx on X11, text-input-v3 on Wayland) to this
        // window. The game never accepts text, and an active IME is actively
        // harmful here: a desktop that shows a long-press character/IME picker
        // swallows held keys and its popup takes focus, at which point
        // SDL_GetKeyboardState() stops reflecting what the player is holding.
        // Holds matter because the game samples the controller once per game
        // frame (~15 Hz, see analysis/docs/timing-and-mission-debug.md).
        const bool ime_was_active = SDL_IsTextInputActive() == SDL_TRUE;
        if (ime_was_active) {
            SDL_StopTextInput();
        }
        std::fprintf(stdout, "SDL text input (IME): %s at window creation, %s now\n",
                     ime_was_active ? "on" : "off",
                     SDL_IsTextInputActive() == SDL_TRUE ? "on" : "off");

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

    // ---- input -------------------------------------------------------------
    // Minimal but real: without this the game stops on its "THERE ARE NO
    // CONTROLLERS ATTACHED" screen forever, because osContInit (HLE'd by
    // librecomp) reports zero devices when get_connected_device_info is unset.
    // Keyboard only for now; a proper remappable binding UI is still TODO.
    constexpr uint16_t BTN_A = 0x8000, BTN_B = 0x4000, BTN_Z = 0x2000, BTN_START = 0x1000;
    constexpr uint16_t BTN_DU = 0x0800, BTN_DD = 0x0400, BTN_DL = 0x0200, BTN_DR = 0x0100;
    constexpr uint16_t BTN_L = 0x0020, BTN_R = 0x0010;
    constexpr uint16_t BTN_CU = 0x0008, BTN_CD = 0x0004, BTN_CL = 0x0002, BTN_CR = 0x0001;

    struct Binding { SDL_Scancode key; uint16_t mask; };
    constexpr Binding bindings[] = {
        { SDL_SCANCODE_X,      BTN_A },     { SDL_SCANCODE_Z,     BTN_B },
        { SDL_SCANCODE_LSHIFT, BTN_Z },     { SDL_SCANCODE_RETURN, BTN_START },
        { SDL_SCANCODE_UP,     BTN_DU },    { SDL_SCANCODE_DOWN,  BTN_DD },
        { SDL_SCANCODE_LEFT,   BTN_DL },    { SDL_SCANCODE_RIGHT, BTN_DR },
        { SDL_SCANCODE_Q,      BTN_L },     { SDL_SCANCODE_E,     BTN_R },
        { SDL_SCANCODE_I,      BTN_CU },    { SDL_SCANCODE_K,     BTN_CD },
        { SDL_SCANCODE_J,      BTN_CL },    { SDL_SCANCODE_L,     BTN_CR },
    };

    uint16_t sample_buttons(const Uint8* keys) {
        uint16_t held = 0;
        for (const Binding& b : bindings) {
            if (keys[b.key]) {
                held |= b.mask;
            }
        }
        return held;
    }

    // enhancements.input_latching (analysis/docs/enhancements.md). Set once
    // at startup from the resolved config, before recomp::start() -- read
    // from exactly one call site each in update_gfx() and get_input() below,
    // per the "one flag read, not scattered ifs" structure the design calls
    // for. Vanilla (false) leaves both functions doing exactly what they did
    // before this flag existed: raw per-read sampling.
    std::atomic<bool> input_latching_enabled{false};
    // Accumulates buttons pressed since the last get_input() call. Only
    // written/read when input_latching_enabled is set; update_gfx() ORs
    // fresh presses in (it runs once per host render-loop iteration, far
    // more often than the game's ~15 Hz controller read), and get_input()
    // drains it into the buttons it returns.
    std::atomic<uint16_t> latched_buttons{0};

    void poll_input() {
        SDL_PumpEvents();
    }

    // Pumps the SDL event queue. Runs once per iteration of recomp::start()'s
    // main loop regardless of whether a game is running -- i.e. far more
    // often than get_input() below, which is what makes it the right place
    // to sample for press-latching (see input_latching_enabled above).
    void update_gfx(void*) {
        const bool latching = input_latching_enabled.load(std::memory_order_relaxed);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                ultramodern::quit();
            }
            // Latch from key-down EVENTS, not from polled keyboard state. SDL
            // queues every press, so a tap that goes down and up between two
            // polls is still captured; polling state can only ever sample, and
            // would miss exactly the short taps latching exists to rescue.
            // event.key.repeat is ignored - auto-repeat adds nothing here.
            else if (latching && event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                const SDL_Scancode sc = event.key.keysym.scancode;
                for (const Binding& b : bindings) {
                    if (b.key == sc) {
                        latched_buttons.fetch_or(b.mask, std::memory_order_relaxed);
                        break;
                    }
                }
            }
        }
    }

    bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
        if (controller_num != 0) {
            return false;
        }
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        if (keys == nullptr) {
            return false;
        }
        uint16_t held = sample_buttons(keys);
        if (input_latching_enabled.load(std::memory_order_relaxed)) {
            // Press-latch: OR everything pressed since the last read into what
            // we return now, then clear so the next read starts fresh. Vanilla
            // (flag off) never touches latched_buttons at all, so this is a
            // pure no-op there -- the raw sample above is exactly what used to
            // be returned.
            held |= latched_buttons.exchange(0, std::memory_order_relaxed);
        }
        *buttons = held;
        *x = (keys[SDL_SCANCODE_D] ? 1.0f : 0.0f) - (keys[SDL_SCANCODE_A] ? 1.0f : 0.0f);
        *y = (keys[SDL_SCANCODE_W] ? 1.0f : 0.0f) - (keys[SDL_SCANCODE_S] ? 1.0f : 0.0f);
        return true;
    }

    void set_rumble(int, bool) {}

    ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
        if (controller_num == 0) {
            return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
        }
        return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
    }

    // Fallback for task types we have no microcode for. Consuming the task
    // without doing anything is structurally correct: the RSP "finishes" and
    // librecomp's task_thread_func sends the SP-done message the game is
    // blocked on. Returning nullptr instead would make librecomp abort the
    // process.
    RspExitReason skip_unknown_task(uint8_t*, uint32_t) {
        return RspExitReason::Broke;
    }

    // RT64 handles F3DEX/F3DLX graphics tasks (M_GFXTASK) internally via
    // RT64Context::send_dl, so this is only consulted for other task types.
    // Knife Edge only ever submits M_GFXTASK and M_AUDTASK (the audio task is
    // built in the boot segment at 0x800CDDC0; see analysis/docs/audio.md).
    RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
        uint32_t type = task->t.type;

#if defined(KE_HAVE_ASPMAIN)
        if (type == M_AUDTASK) {
            return aspMain;
        }
#endif

        static bool warned[8] = {};
        if (type < 8 && !warned[type]) {
            warned[type] = true;
            std::fprintf(stderr,
                "No RSP microcode registered for task type %u; skipping these tasks\n", type);
        }
        return skip_unknown_task;
    }
}

int main(int argc, char** argv) {
    // Minimal ROM provisioning: `KnifeEdgeRecompiled --rom <path>` selects and
    // stores the ROM (librecomp handles z64/v64/n64 byte orders and validates the
    // XXH3 hash), then the game starts immediately. Without --rom, a previously
    // stored ROM is used if present.
    std::filesystem::path rom_path{};
    for (int i = 1; i < argc - 1; i++) {
        if (std::string_view{argv[i]} == "--rom") {
            rom_path = argv[i + 1];
        }
    }

    recomp::Version project_version{};
    if (!recomp::Version::from_string(version_string, project_version)) {
        exit_error(("Invalid version string: " + version_string).c_str());
        return EXIT_FAILURE;
    }

    kerecomp::log_build_info();

    // Config surface (analysis/docs/enhancements.md): profile + enhancement
    // flags + fidelity tuning, loaded from <app folder>/config.toml (or
    // --config's path), CLI/env overrides applied. Logged right after the
    // build stamp so a bug report self-identifies its config too.
    std::filesystem::path app_folder = kerecomp::get_app_folder_path();
    kerecomp::Config config = kerecomp::load_config(argc, argv, app_folder);
    std::fprintf(stdout, "%s\n", kerecomp::describe_config(config).c_str());
    std::fflush(stdout);

    kerecomp::EnhancementFlags enhancements = kerecomp::effective_enhancements(config);
    input_latching_enabled.store(enhancements.input_latching, std::memory_order_relaxed);
    kerecomp::set_rcp_frame_ms_tuning(config.tuning.rcp_frame_ms);

    // enhancements.high_resolution (analysis/docs/enhancements.md). Must be
    // set before recomp::start() below spins up the gfx thread, since
    // gfx_thread_func() reads get_graphics_config() as its very first action
    // (both directly for developer_mode and via create_render_context(), and
    // again for its "old_config" baseline) -- setting it any later would
    // race the gfx thread's startup read. Every field except res_option pins
    // today's value-initialized GraphicsConfig{} default (all enums 0, ints
    // 0) so that vanilla (high_resolution off) stays bit-identical to
    // pre-existing behavior; ds_option=1 here vs the implicit 0 before this
    // code existed are equivalent because set_application_user_config()
    // (src/main/rt64_render_context.cpp) clamps with max(ds_option, 1).
    ultramodern::renderer::GraphicsConfig gfx_config{};
    gfx_config.developer_mode = false;
    gfx_config.res_option = enhancements.high_resolution ? ultramodern::renderer::Resolution::Auto
                                                          : ultramodern::renderer::Resolution::Original;
    gfx_config.wm_option = ultramodern::renderer::WindowMode::Windowed;
    gfx_config.hr_option = ultramodern::renderer::HUDRatioMode::Original;
    gfx_config.api_option = ultramodern::renderer::GraphicsApi::Auto;
    gfx_config.ar_option = ultramodern::renderer::AspectRatio::Original;
    gfx_config.msaa_option = ultramodern::renderer::Antialiasing::None;
    gfx_config.rr_option = ultramodern::renderer::RefreshRate::Original;
    gfx_config.hpfb_option = ultramodern::renderer::HighPrecisionFramebuffer::Auto;
    gfx_config.rr_manual_value = 0;
    gfx_config.ds_option = 1;
    ultramodern::renderer::set_graphics_config(gfx_config);

    recomp::register_config_path(app_folder);

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
        // XXH3_64bits of the normalized z64 image (md5 8043d829fcd4f8f72dd81e5c6dde916f).
        .rom_hash = 0x56605501A85C79AFULL,
        .internal_name = "KNIFE EDGE",
        .game_id = u8"knifeedge.n64.us.1.0",
        .mod_game_id = "",
        // Cart has no EEPROM/SRAM/Flash symbols; high scores go to Controller Pak
        // (osPfsIsPlug is the only save-adjacent symbol) which librecomp HLEs.
        .save_type = recomp::SaveType::None,
        .is_enabled = true,
        .has_compressed_code = false,
        // Must be SIGN-EXTENDED: recomp.h's MEM_* macros index rdram as
        // (addr - 0xFFFFFFFF80000000), so a bare positive 0x800C2400 lands ~4GB
        // out of bounds and segfaults in the initial DMA.
        .entrypoint_address = static_cast<gpr>(static_cast<int32_t>(0x800C2400)),
        .entrypoint = knife_edge_entrypoint,
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

    // Audio sink (src/main/audio.cpp). Opens the SDL audio device now so the
    // callbacks are live before the game's audio thread starts; if there is no
    // usable device this returns an empty callback set and the runtime stays
    // silent instead of failing.
    ultramodern::audio_callbacks_t audio_callbacks = kerecomp::init_audio(48000);

    // TODO: events and threads callbacks are optional (librecomp null-checks
    // each field individually) and left unset for this skeleton.
    ultramodern::input::callbacks_t input_callbacks {
        .poll_input = poll_input,
        .get_input = get_input,
        .set_rumble = set_rumble,
        .get_connected_device_info = get_connected_device_info,
    };
    ultramodern::events::callbacks_t events_callbacks {};
    ultramodern::threads::callbacks_t threads_callbacks {};

    ultramodern::error_handling::callbacks_t error_handling_callbacks {
        .message_box = +[](const char* msg) {
            kerecomp::show_error_message_box("Knife Edge Recompiled", msg);
        },
    };

    // Select/validate the ROM before starting the runtime threads. select_rom
    // stores a normalized copy under the config path for future runs.
    if (!rom_path.empty()) {
        recomp::RomValidationError rom_err = recomp::select_rom(rom_path, knife_edge_entry.game_id);
        if (rom_err != recomp::RomValidationError::Good) {
            exit_error("ROM validation failed (error " +
                       std::to_string(static_cast<int>(rom_err)) + ") for " +
                       rom_path.string());
            return EXIT_FAILURE;
        }
    }
    recomp::check_all_stored_roms();
    if (!recomp::is_rom_valid(knife_edge_entry.game_id)) {
        exit_error("No valid ROM. Run with: KnifeEdgeRecompiled --rom <path-to-knife-edge-rom>");
        return EXIT_FAILURE;
    }

    // Start the game from the VI callback rather than here. ultramodern's VI
    // thread only initializes its ViState (mode/framebuffer) via set_dummy_vi
    // while `!is_game_started()`; starting the game before the VI thread has
    // ticked leaves both ViStates with a null `mode` and update_vi() segfaults.
    // Waiting a few retraces guarantees both double-buffered states are valid.
    static std::u8string start_game_id = knife_edge_entry.game_id;
    events_callbacks.vi_callback = +[]() {
        kerecomp::perf_count_vi();
        static int vis = 0;
        if (vis <= 3 && ++vis == 3) {
            recomp::start_game(start_game_id);
        }
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

    kerecomp::shutdown_audio();

    return EXIT_SUCCESS;
}
