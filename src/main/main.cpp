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

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <unordered_map>

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
    // Keyboard plus any SDL-recognized gamepad; a proper remappable binding UI
    // is still TODO.
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

    // Digital gamepad buttons, mirroring `bindings` above. Shared by the
    // per-iteration sampler and by controller-button latching further down.
    struct PadBinding { SDL_GameControllerButton button; uint16_t mask; };
    constexpr PadBinding pad_bindings[] = {
        { SDL_CONTROLLER_BUTTON_A,             BTN_A },     { SDL_CONTROLLER_BUTTON_B,              BTN_B },
        { SDL_CONTROLLER_BUTTON_START,          BTN_START },
        { SDL_CONTROLLER_BUTTON_LEFTSHOULDER,   BTN_L },     { SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,  BTN_R },
        { SDL_CONTROLLER_BUTTON_DPAD_UP,        BTN_DU },    { SDL_CONTROLLER_BUTTON_DPAD_DOWN,      BTN_DD },
        { SDL_CONTROLLER_BUTTON_DPAD_LEFT,      BTN_DL },    { SDL_CONTROLLER_BUTTON_DPAD_RIGHT,     BTN_DR },
    };

    // Open SDL_GameController handles, keyed by joystick instance id. Every
    // SDL_GameController* call (open/close/get-state) happens only here in
    // update_gfx(), on the thread that pumps SDL events -- get_input() runs
    // on a separate ~15 Hz controller-read thread and never touches SDL
    // gamepad state directly, only the atomics below, same division of labor
    // as input_latching_enabled/latched_buttons.
    std::unordered_map<SDL_JoystickID, SDL_GameController*> open_controllers;

    // Combined state of every open pad, published once per update_gfx()
    // iteration and consumed by get_input(). Multiple pads deliberately all
    // act as N64 controller 1 -- buttons OR'd, stick contributions summed --
    // so whichever pad is in hand works, with no pad-selection step.
    std::atomic<uint16_t> pad_buttons{0};
    std::atomic<float> pad_stick_x{0.0f};
    std::atomic<float> pad_stick_y{0.0f};

    // config.input.stick_* (analysis/docs/enhancements.md is the enhancement
    // doc; these are NOT enhancements -- see InputTuning in config.h). Set
    // once at startup from the resolved config, same pattern as
    // input_latching_enabled below, and read once per update_gfx() sampling
    // pass (not per pad) into locals that shape the radial deadzone below.
    std::atomic<float> stick_deadzone{0.15f};
    std::atomic<float> stick_curve{1.0f};
    std::atomic<float> stick_sensitivity{1.0f};

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

    // ---- mouse aim -----------------------------------------------------
    // config.input.mouse_aim / mouse_sensitivity (see InputTuning in
    // config.h). Set once at startup, same pattern as the stick_* atomics
    // above; read from update_gfx() (the capture click / motion / button
    // handling, all on the event thread) and get_input() (sensitivity only).
    std::atomic<bool> mouse_aim_enabled{true};
    std::atomic<float> mouse_sensitivity{1.0f};

    // config.input.mouse_mode / mouse_invert_y (see MouseMode in config.h and
    // analysis/docs/mouse-aim.md). Set once at startup like the two above and
    // read once per get_input() call. `positional` is the default mapping.
    std::atomic<bool> mouse_mode_positional{true};
    std::atomic<bool> mouse_invert_y{false};

    // Window height in pixels, republished by update_gfx() once per pass and
    // read by get_input()'s positional controller, which needs it to convert
    // mouse pixels into the game's own reticle units. Those units are N64
    // pixels of the 240-line frame -- measured: at 1280x720 the reticle moves
    // exactly 3.0 host px per unit, i.e. window_h / 240 (see
    // analysis/docs/mouse-aim.md). Sampled rather than assumed so the mapping
    // survives a window resize. The initial value matches create_window()'s
    // 1280x720.
    std::atomic<int> window_height{720};

    // Whether the pointer is currently captured (relative-mouse-mode). Only
    // SDL_SetRelativeMouseMode/capture-state transitions happen in
    // update_gfx() on the event thread, which is also the only writer of
    // this atomic; mouse_captured_local is a plain, non-atomic mirror kept
    // for that same thread's own branching (no reason to pay for an atomic
    // load to read back a value only this thread ever wrote). The atomic is
    // published in case get_input() or a future consumer needs the state
    // from another thread.
    std::atomic<bool> mouse_captured{false};
    bool mouse_captured_local = false;

    // Raw relative mouse motion (SDL_MOUSEMOTION xrel/yrel), accumulated by
    // update_gfx() while captured and drained by get_input() each read via
    // exchange(0.0f) -- same producer(event thread)/consumer(~15 Hz input
    // thread) split as latched_buttons above. atomic<float>::fetch_add is a
    // real (non-emulated) atomic RMW as of C++20 (this tree targets C++20,
    // see CMAKE_CXX_STANDARD in CMakeLists.txt), so no CAS loop is needed;
    // this is the one place motion accumulation happens.
    std::atomic<float> mouse_accum_x{0.0f};
    std::atomic<float> mouse_accum_y{0.0f};

    // Mouse-button state while captured, mapped to N64 buttons below (L/R/M
    // -> Z/A/B, owner-specified -- see the SDL_MOUSEBUTTONDOWN/UP handling
    // in update_gfx()). Set/cleared from button-down/up events, OR'd into
    // get_input()'s `held` alongside pad_buttons.
    std::atomic<uint16_t> mouse_buttons{0};

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
            // Escape releases mouse capture. Checked ahead of the latching
            // branch below (which would otherwise consume every KEYDOWN when
            // latching is on) so release works regardless of the latching
            // setting. Escape is deliberately not in `bindings[]`, so it was
            // never latchable anyway -- this branch just makes the release
            // unconditional rather than relying on that as an accident.
            else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE &&
                     mouse_captured_local) {
                SDL_SetRelativeMouseMode(SDL_FALSE);
                mouse_captured_local = false;
                mouse_captured.store(false, std::memory_order_relaxed);
                // Nothing should stay held across a release.
                mouse_buttons.store(0, std::memory_order_relaxed);
                std::fprintf(stdout, "Mouse released\n");
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
            // SDL2 delivers ADDED for every controller already connected at
            // SDL_Init time too, so this is also startup enumeration -- no
            // separate pass needed. `which` is a device index here.
            else if (event.type == SDL_CONTROLLERDEVICEADDED) {
                SDL_GameController* gc = SDL_GameControllerOpen(event.cdevice.which);
                if (gc != nullptr) {
                    const SDL_JoystickID id = SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(gc));
                    open_controllers[id] = gc;
                    // SDL_GameControllerName can return NULL for a nameless device.
                    const char* name = SDL_GameControllerName(gc);
                    std::fprintf(stdout, "Gamepad connected: %s\n", name != nullptr ? name : "(unnamed)");
                }
            }
            // `which` is a joystick instance id here (unlike ADDED above).
            else if (event.type == SDL_CONTROLLERDEVICEREMOVED) {
                auto it = open_controllers.find(event.cdevice.which);
                if (it != open_controllers.end()) {
                    const char* name = SDL_GameControllerName(it->second);
                    std::fprintf(stdout, "Gamepad disconnected: %s\n", name != nullptr ? name : "(unnamed)");
                    SDL_GameControllerClose(it->second);
                    open_controllers.erase(it);
                }
            }
            // Digital buttons only -- axis-derived inputs (Z via triggers, C
            // via the right stick) aren't latched. A human trigger pull
            // comfortably spans the game's ~67 ms read interval, unlike the
            // short taps latching exists to rescue, so there's nothing to
            // catch there and latching would just add stale state to drain.
            else if (latching && event.type == SDL_CONTROLLERBUTTONDOWN) {
                const auto button = static_cast<SDL_GameControllerButton>(event.cbutton.button);
                for (const PadBinding& b : pad_bindings) {
                    if (b.button == button) {
                        latched_buttons.fetch_or(b.mask, std::memory_order_relaxed);
                        break;
                    }
                }
            }
            // Mouse aim (config.input.mouse_aim -- see InputTuning in
            // config.h). The first click while not captured just captures
            // the pointer and is consumed -- it does not also register as a
            // game button, matching how a click to focus/capture a window
            // normally isn't also a click "into" whatever's under it.
            else if (event.type == SDL_MOUSEBUTTONDOWN && mouse_aim_enabled.load(std::memory_order_relaxed)) {
                if (!mouse_captured_local) {
                    SDL_SetRelativeMouseMode(SDL_TRUE);
                    mouse_captured_local = true;
                    mouse_captured.store(true, std::memory_order_relaxed);
                    std::fprintf(stdout, "Mouse captured (Esc releases)\n");
                } else {
                    // Left/right/middle -> Z/A/B, owner-specified after
                    // hands-on play (2026-07-29). Must match the BUTTONUP
                    // mapping below.
                    uint16_t mask = 0;
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:   mask = BTN_Z; break;
                        case SDL_BUTTON_RIGHT:  mask = BTN_A; break;
                        case SDL_BUTTON_MIDDLE: mask = BTN_B; break;
                        default: break;
                    }
                    if (mask != 0) {
                        mouse_buttons.fetch_or(mask, std::memory_order_relaxed);
                        // Same rationale as the keyboard/pad latch paths
                        // above: a click shorter than one game frame should
                        // still register. The capture-consuming first click
                        // never reaches here, so it's never latched either.
                        if (latching) {
                            latched_buttons.fetch_or(mask, std::memory_order_relaxed);
                        }
                    }
                }
            }
            else if (event.type == SDL_MOUSEBUTTONUP) {
                uint16_t mask = 0;
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:   mask = BTN_Z; break;
                    case SDL_BUTTON_RIGHT:  mask = BTN_A; break;
                    case SDL_BUTTON_MIDDLE: mask = BTN_B; break;
                    default: break;
                }
                if (mask != 0) {
                    mouse_buttons.fetch_and(static_cast<uint16_t>(~mask), std::memory_order_relaxed);
                }
            }
            else if (event.type == SDL_MOUSEMOTION && mouse_captured_local) {
                // Drained by get_input() below; accumulating here (rather
                // than sampling absolute position) means no motion is lost
                // between get_input() reads, however many update_gfx()
                // iterations happen in between.
                mouse_accum_x.fetch_add(static_cast<float>(event.motion.xrel), std::memory_order_relaxed);
                mouse_accum_y.fetch_add(static_cast<float>(event.motion.yrel), std::memory_order_relaxed);
            }
        }

        // Republish the window height for get_input()'s positional mouse
        // controller (see window_height above). Once per pass, on the thread
        // that owns the SDL window, rather than from the input thread.
        if (window != nullptr) {
            int w = 0;
            int h = 0;
            SDL_GetWindowSize(window, &w, &h);
            if (h > 0) {
                window_height.store(h, std::memory_order_relaxed);
            }
        }

        // Sample every open pad and publish the combined state (see
        // open_controllers/pad_buttons above for the threading rationale and
        // the multi-pad-as-controller-1 rationale).
        uint16_t buttons = 0;
        float stick_x = 0.0f;
        float stick_y = 0.0f;
        // Loaded once per sampling pass, not per pad -- config.input.stick_*
        // (see the atomics above).
        const float deadzone = stick_deadzone.load(std::memory_order_relaxed);
        const float curve = stick_curve.load(std::memory_order_relaxed);
        const float sensitivity = stick_sensitivity.load(std::memory_order_relaxed);
        for (const auto& [id, gc] : open_controllers) {
            for (const PadBinding& b : pad_bindings) {
                if (SDL_GameControllerGetButton(gc, b.button)) {
                    buttons |= b.mask;
                }
            }

            // Either trigger fires Z -- this is a rail shooter, the trigger is
            // the natural fire control, and a simple threshold is enough (no
            // need to expose analog trigger depth to the game).
            if (SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 16384 ||
                SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 16384) {
                buttons |= BTN_Z;
            }

            // Right stick -> C buttons, digital thresholds at 0.4 of full
            // scale. SDL's Y axis is down-positive, so negative Y is C-up.
            constexpr Sint16 c_threshold = 13107; // 0.4 * 32767, rounded down
            const Sint16 rx = SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTX);
            const Sint16 ry = SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTY);
            if (rx < -c_threshold) buttons |= BTN_CL;
            if (rx >  c_threshold) buttons |= BTN_CR;
            if (ry < -c_threshold) buttons |= BTN_CU;
            if (ry >  c_threshold) buttons |= BTN_CD;

            // Left stick -> N64 stick. Radial (not per-axis) deadzone: below
            // `deadzone` magnitude the stick contributes nothing; above it,
            // travel is rescaled so the deadzone edge maps to 0 and full
            // deflection still maps to 1. A per-axis deadzone would clip
            // diagonals unevenly, which a radial one avoids. Shaping order
            // after that rescale is curve (response exponent) -> sensitivity
            // (post-curve multiplier) -> clamp to full deflection; see
            // InputTuning in config.h. `mag > deadzone` (strictly, was `>=`)
            // plus `mag > 0` below guard the division by zero when deadzone
            // is 0 -- this only changes behavior exactly on the boundary
            // mag == deadzone > 0, a measure-zero case in practice.
            float lx = std::clamp(SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f, -1.0f, 1.0f);
            float ly = std::clamp(SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f, -1.0f, 1.0f);
            ly = -ly; // SDL's Y is down-positive; match the keyboard binding's W=+1 (up-positive) convention.
            const float mag = std::sqrt(lx * lx + ly * ly);
            if (mag > deadzone && mag > 0.0f) {
                const float mag_norm = std::min((mag - deadzone) / (1.0f - deadzone), 1.0f);
                float shaped = mag_norm;
                // Guard keeps the default (curve == 1.0) path bit-identical
                // to the pre-tuning code (no pow() call at all).
                if (curve != 1.0f) {
                    shaped = std::pow(mag_norm, curve);
                }
                shaped = std::min(shaped * sensitivity, 1.0f);
                const float scale = shaped / mag;
                stick_x += lx * scale;
                stick_y += ly * scale;
            }
        }
        pad_buttons.store(buttons, std::memory_order_relaxed);
        pad_stick_x.store(std::clamp(stick_x, -1.0f, 1.0f), std::memory_order_relaxed);
        pad_stick_y.store(std::clamp(stick_y, -1.0f, 1.0f), std::memory_order_relaxed);
    }

    // ---- positional mouse aim ---------------------------------------------
    //
    // The game's reticle is not a position the host can write; it is an
    // integrator the game advances by a fixed number of units per game frame,
    // and the size of that step is a staircase function of the stick byte it
    // reads. Measured against a live mission (all 34 sample points on both
    // axes fit, see analysis/docs/mouse-aim.md):
    //
    //     units_per_frame = clamp(floor((|stick| - 5) * 20 / 58), 0, 20)
    //
    // so a stick below 8 does nothing, 63 already saturates at 20 units/frame
    // (half the s8 range is dead weight), and there is no auto-centering --
    // release the stick and the reticle simply stays put. That makes an exact
    // deadbeat controller possible: each frame, ask for the step that closes
    // the remaining error.
    //
    // mouse_step_thresholds[k-1] is the smallest stick magnitude that yields k
    // units/frame.
    constexpr int mouse_max_step = 20;
    constexpr int mouse_step_thresholds[mouse_max_step] = {
        8, 11, 14, 17, 20, 23, 26, 29, 32, 34, 37, 40, 43, 46, 49, 52, 55, 58, 61, 63,
    };

    // Stick magnitude (0..127) that makes the game move the reticle `step`
    // units on its next frame. Aims one past the threshold so it lands inside
    // the band rather than on its edge -- the narrowest band is 2 wide, so
    // this is always still the right band, and it costs nothing to be robust
    // to the curve fit being a unit off anywhere. Saturation is asked for at
    // 80 rather than 63: there is no step above 20 to overshoot into, so the
    // extra margin is free.
    int mouse_stick_for_step(int step) {
        if (step <= 0) {
            return 0;
        }
        if (step >= mouse_max_step) {
            return 80;
        }
        return mouse_step_thresholds[step - 1] + 1;
    }

    // Deadbeat law for one axis. floor(), not round(): commanding fewer units
    // than remain can never overshoot, so the reticle walks onto the target
    // monotonically and stops -- no dither, no oscillation. The cost is
    // settling up to 1 unit short, which is ~3 host pixels at 720p.
    int mouse_step_for_error(float err) {
        const int step = std::min(static_cast<int>(std::floor(std::fabs(err))), mouse_max_step);
        const int mag = mouse_stick_for_step(step);
        return err < 0.0f ? -mag : mag;
    }

    // The per-VI-retrace callback the game registers while a mission is
    // running: func_8019CF84 of seg_1501A0, the shared in-game code overlay.
    // Every screen registers its own callback (see src/main/rcp_timing.cpp's
    // header comment), so this value names the screen, and it is the only
    // cheap test for "a mission is actually running" -- the reticle words
    // cannot answer that, since nothing zeroes them on mission exit.
    //
    // Measured 300/300 samples in a mission and 400/400 on the attract screen
    // (which reads 0x801DC3E4 there); seg_1501A0 is shared by every stage, so
    // this is stage-independent. Evidence and the leak that motivated the gate
    // are in analysis/docs/mouse-aim.md sections 6.2 and 9.
    constexpr uint32_t mission_retrace_callback = 0x8019CF84u;

    // Stick byte -> the float ultramodern will convert back into exactly that
    // byte. deps/N64ModernRuntime/ultramodern/src/input.cpp:154 does
    // `data[controller].stick_x = (int8_t)(127 * x)`, a C truncation toward
    // zero, so every x in [s/127, (s+1)/127) yields s; the midpoint keeps the
    // most room on both sides for float rounding.
    float mouse_stick_axis(int s) {
        if (s == 0) {
            return 0.0f;
        }
        const float mag = (static_cast<float>(std::abs(s)) + 0.5f) / 127.0f;
        return s > 0 ? mag : -mag;
    }

    bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
        if (controller_num != 0) {
            return false;
        }
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        if (keys == nullptr) {
            return false;
        }
        uint16_t held = sample_buttons(keys) | pad_buttons.load(std::memory_order_relaxed) |
                        mouse_buttons.load(std::memory_order_relaxed);
        if (input_latching_enabled.load(std::memory_order_relaxed)) {
            // Press-latch: OR everything pressed since the last read into what
            // we return now, then clear so the next read starts fresh. Vanilla
            // (flag off) never touches latched_buttons at all, so this is a
            // pure no-op there -- the raw sample above is exactly what used to
            // be returned.
            held |= latched_buttons.exchange(0, std::memory_order_relaxed);
        }
        *buttons = held;
        const float kx = (keys[SDL_SCANCODE_D] ? 1.0f : 0.0f) - (keys[SDL_SCANCODE_A] ? 1.0f : 0.0f);
        const float ky = (keys[SDL_SCANCODE_W] ? 1.0f : 0.0f) - (keys[SDL_SCANCODE_S] ? 1.0f : 0.0f);

        // Mouse aim: drain the motion accumulated by update_gfx() since the
        // last call (zero if not captured -- update_gfx() only accumulates
        // while mouse_captured_local is set), turn it into a stick deflection
        // by whichever of the two mappings is configured, then fold that into
        // the same axis sum keyboard/pad already go through.
        //
        // dt below is measured rather than assumed because this function runs
        // on its own thread, driven by the game's controller read, at a rate
        // it does not control (measured: ~3.2 calls per game frame). Only the
        // velocity mapping needs it -- the positional controller is driven by
        // the game's own frame counter instead, which is the point of it.
        const float mouse_dx = mouse_accum_x.exchange(0.0f, std::memory_order_relaxed);
        const float mouse_dy = mouse_accum_y.exchange(0.0f, std::memory_order_relaxed);
        static std::chrono::steady_clock::time_point last_mouse_read{};
        static bool have_last_mouse_read = false;
        const auto now = std::chrono::steady_clock::now();
        float dt;
        if (have_last_mouse_read) {
            dt = std::chrono::duration<float>(now - last_mouse_read).count();
            dt = std::clamp(dt, 0.001f, 0.25f);
        } else {
            dt = 1.0f / 15.0f; // First call: assume the game's own ~15 Hz read rate.
            have_last_mouse_read = true;
        }
        last_mouse_read = now;
        const float sens = mouse_sensitivity.load(std::memory_order_relaxed);

        // Vertical sign. SDL's yrel is down-positive and the game's reticle
        // value is ALSO down-positive (a stick pushed up drives the reticle
        // down -- the game aims flight-inverted; measured, see
        // analysis/docs/mouse-aim.md). So passing yrel straight through gives
        // mouse-down = reticle-down, i.e. the non-inverted convention, and
        // mouse_invert_y flips it back to the game's own. This is also the fix
        // for the velocity path below, which used to negate yrel on the
        // assumption that stick +y meant "up" -- as shipped, moving the mouse
        // up aimed DOWN.
        const float ysign = mouse_invert_y.load(std::memory_order_relaxed) ? -1.0f : 1.0f;

        float mouse_x = 0.0f;
        float mouse_y = 0.0f;
        if (mouse_mode_positional.load(std::memory_order_relaxed)) {
            const kerecomp::ReticleState reticle = kerecomp::reticle_state();

            // Function-local: get_input() is the only reader of the published
            // reticle state and runs on one thread, so the loop's own memory
            // needs no synchronization.
            static float target_x = 0.0f;
            static float target_y = 0.0f;
            static uint32_t last_clock = 0;
            static std::chrono::steady_clock::time_point last_step{};
            static std::chrono::steady_clock::time_point last_motion{};
            static bool have_step = false;
            static bool have_motion = false;

            if (reticle.clock != last_clock) {
                last_clock = reticle.clock;
                last_step = now;
                have_step = true;
            }
            if (mouse_dx != 0.0f || mouse_dy != 0.0f) {
                last_motion = now;
                have_motion = true;
            }

            // Three gates; ALL must hold or the loop stays open (zero mouse
            // contribution) and the target is resynced to wherever the reticle
            // actually is, so re-engaging never starts with a stale error.
            // They are layered deliberately, coarsest first:
            //
            //  1. A mission is running, i.e. the game's per-retrace callback is
            //     the in-mission one. This is the discriminator, and it FAILS
            //     CLOSED: any screen or game mode this code has not anticipated
            //     registers some other callback, so aim goes quiet there rather
            //     than emitting stick input into a menu. That is the right way
            //     round -- inert aim is a visible annoyance, phantom menu input
            //     is a corrupting one.
            //
            //     It is load-bearing, not belt-and-braces: gate 2 alone does
            //     not keep the front end safe, because the attract/demo screens
            //     tick the same counter once per frame exactly as a mission
            //     does. Measured, with the pointer captured and the mouse moved
            //     continuously for 30 s at attract, gates 2+3 alone left the
            //     game's stick byte saturated at +-80 for 17.4% of samples --
            //     the reticle words are frozen there, so the error never closes
            //     and the controller never stops commanding.
            //
            //  2. The game stepped RECENTLY. Kills aim while the world is
            //     frozen inside a mission (a pause, a load, a cutscene): the
            //     reticle cannot move then, so chasing it would just wind the
            //     target up against a value that never changes.
            //
            //     Deliberately a time window and not "the clock changed since
            //     the previous call": this function is driven by the game's
            //     controller read, which measurement puts at ~3.2 calls per
            //     game frame (median 2, and hundreds while a load or cutscene
            //     holds the world still). Testing for a change per call would
            //     therefore fail on roughly two calls in three purely from
            //     sampling faster than the thing being sampled, and each
            //     failure would resync the target -- which empirically zeroed
            //     the output entirely. 250 ms is ~7 game frames at the current
            //     pace and ~4 at the console-faithful 15 fps, so a live world
            //     always passes and a genuinely stopped one trips it well
            //     inside gate 3's window.
            //
            //  3. The mouse moved within the last second, which bounds whatever
            //     residual exposure the first two leave. A full-width chase is
            //     256 units = 13 frames = ~0.5 s at the measured 20
            //     units/frame, so this never truncates a real flick; it is
            //     what stops the loop from holding a deflection indefinitely.
            const bool in_mission = reticle.retrace_callback == mission_retrace_callback;
            const bool stepped = have_step &&
                std::chrono::duration<float>(now - last_step).count() <= 0.25f;
            const bool recent = have_motion &&
                std::chrono::duration<float>(now - last_motion).count() <= 1.0f;

            if (!in_mission || !stepped || !recent) {
                target_x = static_cast<float>(reticle.x);
                target_y = static_cast<float>(reticle.y);
            } else {
                // Mouse pixels -> reticle units. Reticle units are N64 pixels
                // of the 240-line frame, so one unit is window_h/240 host
                // pixels (measured exactly 3.0 at 720p) and the inverse is
                // 240/window_h. Sensitivity scales that mapping, which makes
                // it a plain "reticle travel per inch of mouse" knob.
                const int win_h = window_height.load(std::memory_order_relaxed);
                const float px_to_units = (240.0f / static_cast<float>(win_h > 0 ? win_h : 720)) * sens;
                target_x += mouse_dx * px_to_units;
                target_y += ysign * mouse_dy * px_to_units;
                // Clamp to the measured rails (stage-independent). The game
                // clamps hard there itself, so without this the target would
                // wind up past a reticle that has stopped following.
                target_x = std::clamp(target_x, -128.0f, 128.0f);
                target_y = std::clamp(target_y, -84.0f, 84.0f);

                mouse_x = mouse_stick_axis(mouse_step_for_error(target_x - static_cast<float>(reticle.x)));
                mouse_y = mouse_stick_axis(mouse_step_for_error(target_y - static_cast<float>(reticle.y)));
            }
        } else {
            // Velocity mapping: full deflection at 500 px/s of mouse travel at
            // sensitivity 1.0. Open loop -- the reticle drifts for as long as
            // the mouse keeps moving.
            mouse_x = (mouse_dx / dt) * sens / 500.0f;
            mouse_y = ysign * (mouse_dy / dt) * sens / 500.0f;
        }

        *x = std::clamp(kx + pad_stick_x.load(std::memory_order_relaxed) + mouse_x, -1.0f, 1.0f);
        *y = std::clamp(ky + pad_stick_y.load(std::memory_order_relaxed) + mouse_y, -1.0f, 1.0f);
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
    kerecomp::set_full_height_enhancement(enhancements.full_height);

    // config.input (analysis-doc terminology aside, NOT an enhancement -- see
    // InputTuning in config.h). Stored once here, same pattern as
    // input_latching_enabled above; update_gfx()'s sampling pass loads these
    // once per pass, not per pad.
    stick_deadzone.store(static_cast<float>(config.input.stick_deadzone), std::memory_order_relaxed);
    stick_curve.store(static_cast<float>(config.input.stick_curve), std::memory_order_relaxed);
    stick_sensitivity.store(static_cast<float>(config.input.stick_sensitivity), std::memory_order_relaxed);
    mouse_aim_enabled.store(config.input.mouse_aim, std::memory_order_relaxed);
    mouse_sensitivity.store(static_cast<float>(config.input.mouse_sensitivity), std::memory_order_relaxed);
    mouse_mode_positional.store(config.input.mouse_mode == kerecomp::MouseMode::Positional,
                                std::memory_order_relaxed);
    mouse_invert_y.store(config.input.mouse_invert_y, std::memory_order_relaxed);

    // enhancements.high_resolution / .widescreen (analysis/docs/enhancements.md).
    // Must be set before recomp::start() below spins up the gfx thread, since
    // gfx_thread_func() reads get_graphics_config() as its very first action
    // (both directly for developer_mode and via create_render_context(), and
    // again for its "old_config" baseline) -- setting it any later would
    // race the gfx thread's startup read. Every field except res_option and
    // ar_option pins today's value-initialized GraphicsConfig{} default (all
    // enums 0, ints 0) so that vanilla (both flags off) stays bit-identical
    // to pre-existing behavior; ds_option=1 here vs the implicit 0 before
    // this code existed are equivalent because set_application_user_config()
    // (src/main/rt64_render_context.cpp) clamps with max(ds_option, 1).
    ultramodern::renderer::GraphicsConfig gfx_config{};
    gfx_config.developer_mode = false;
    gfx_config.res_option = enhancements.high_resolution ? ultramodern::renderer::Resolution::Auto
                                                          : ultramodern::renderer::Resolution::Original;
    gfx_config.wm_option = ultramodern::renderer::WindowMode::Windowed;
    gfx_config.hr_option = ultramodern::renderer::HUDRatioMode::Original;
    gfx_config.api_option = ultramodern::renderer::GraphicsApi::Auto;
    gfx_config.ar_option = enhancements.widescreen ? ultramodern::renderer::AspectRatio::Expand
                                                    : ultramodern::renderer::AspectRatio::Original;
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
