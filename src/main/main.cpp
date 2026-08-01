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
#include <cstring>
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

// ROM picker (see the no-ROM fallback in main() below). Already linked into
// this binary: deps/rt64/CMakeLists.txt links `nfd` (nativefiledialog-extended)
// into the `rt64` target this executable links, and its headers are already
// on our include path (CMakeLists.txt, nativefiledialog-extended/src/include).
#include "nfd.h"

#if defined(__linux__)
// See portal_reachable() below: a direct (second, independent) use of
// libdbus, needed only to pre-flight whether NFD's portal call is safe to
// make at all.
#   include <dbus/dbus.h>
#endif

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

#if defined(__linux__)
    // Whether org.freedesktop.portal.Desktop is reachable on the session bus:
    // either already running (has an owner) or D-Bus-activatable (a .service
    // file exists, so the bus daemon starts it on first use -- the common
    // case, since xdg-desktop-portal is normally not running until something
    // asks for it; this is exactly how a Flatpak sandbox's proxied session
    // bus normally looks). Both queries below are answered by the LOCAL
    // dbus-daemon about its own registry -- neither is proxied to the portal
    // process itself -- so both return promptly even when no portal exists
    // at all.
    //
    // This exists because nfd_portal.cpp's own D-Bus calls
    // (dbus_connection_send_with_reply_and_block(..., DBUS_TIMEOUT_INFINITE,
    // ...) in NFD_DBus_OpenFile()) have NO timeout, and were verified here to
    // hang forever under a live X display with a working session bus but no
    // portal service and no activation entry for it (bare Xvfb inside this
    // project's dev container -- see analysis/docs/build-notes.md, "Flatpak
    // packaging"). Skipping the NFD call entirely in that situation is the
    // only reliable way to guarantee main() can't hang here; a wall-clock
    // timeout around the NFD call instead would be wrong, since a real portal
    // dialog is expected to legitimately block for as long as the user takes
    // to pick a file.
    bool portal_reachable() {
        DBusError err;
        dbus_error_init(&err);
        // _private, not the shared dbus_bus_get(): this connection is ours
        // alone to close below. Closing a connection obtained via the
        // shared, process-wide dbus_bus_get() cache would also break it for
        // NFD_Init()'s own later dbus_bus_get() call on the happy path.
        DBusConnection* conn = dbus_bus_get_private(DBUS_BUS_SESSION, &err);
        if (conn == nullptr) {
            dbus_error_free(&err);
            return false;
        }

        bool reachable = dbus_bus_name_has_owner(conn, "org.freedesktop.portal.Desktop", &err);
        dbus_error_free(&err);

        if (!reachable) {
            DBusMessage* query = dbus_message_new_method_call(
                "org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus",
                "ListActivatableNames");
            if (query != nullptr) {
                DBusError list_err;
                dbus_error_init(&list_err);
                // Bounded out of caution, even though this call goes to the
                // daemon about its own registry and should never actually
                // wait on the (possibly absent) portal.
                DBusMessage* reply =
                    dbus_connection_send_with_reply_and_block(conn, query, 2000, &list_err);
                dbus_message_unref(query);
                if (reply != nullptr) {
                    DBusMessageIter iter;
                    if (dbus_message_iter_init(reply, &iter) &&
                        dbus_message_iter_get_arg_type(&iter) == DBUS_TYPE_ARRAY) {
                        DBusMessageIter arr_iter;
                        dbus_message_iter_recurse(&iter, &arr_iter);
                        while (dbus_message_iter_get_arg_type(&arr_iter) == DBUS_TYPE_STRING) {
                            const char* name = nullptr;
                            dbus_message_iter_get_basic(&arr_iter, &name);
                            if (name != nullptr && std::strcmp(name, "org.freedesktop.portal.Desktop") == 0) {
                                reachable = true;
                                break;
                            }
                            dbus_message_iter_next(&arr_iter);
                        }
                    }
                    dbus_message_unref(reply);
                }
                dbus_error_free(&list_err);
            }
        }

        dbus_connection_close(conn);
        dbus_connection_unref(conn);
        return reachable;
    }
#endif

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

    // The N64 has four controller ports; librecomp calls get_input() and
    // get_connected_device_info() once per port (0..3, zero-indexed -- see
    // ultramodern/input.hpp).
    constexpr int max_ports = 4;

    // ---- pads and ports ---------------------------------------------------
    //
    // Port assignment policy (multiplayer phase 2, analysis/docs/multiplayer.md):
    //
    //   * Keyboard and mouse are PORT 0's, always, and only port 0's. Every
    //     keyboard/mouse path below is single-instance for that reason.
    //   * Pads take ports in CONNECTION ORDER, starting at
    //     config.input.pad_start_port (default 0). Each new pad takes the
    //     lowest free port >= that. With the default and a single pad this is
    //     port 0, where it merges with keyboard/mouse -- i.e. exactly the
    //     behavior every previous build had for one pad. pad_start_port = 1
    //     gives keyboard-only P1 and pads as P2..P4 (one human on the
    //     keyboard, one on a pad).
    //   * Disconnect frees that port; the pads that stay keep their ports
    //     (assignment is sticky, never renumbered under a player's hands). A
    //     reconnect then takes the lowest free port again.
    //
    // This replaces the old "every pad acts as controller 1" policy (buttons
    // OR'd, sticks summed across all pads). That merge now happens only within
    // a single port, which at most one pad can occupy -- so in practice only
    // port 0 ever merges anything, and only with keyboard/mouse.
    struct OpenPad {
        SDL_GameController* gc;
        // 0..3, or -1 for a pad with no port left to take (more pads than
        // ports at/above pad_start_port). Such a pad stays open and named in
        // the log but contributes nothing; it is not retroactively promoted
        // when a port later frees, because assignment is sticky by design.
        int port;
    };

    // Open SDL_GameController handles, keyed by joystick instance id. Every
    // SDL_GameController* call (open/close/get-state) happens only here in
    // update_gfx(), on the thread that pumps SDL events -- get_input() runs
    // on a separate ~15 Hz controller-read thread and never touches SDL
    // gamepad state directly, only the atomics below, same division of labor
    // as input_latching_enabled/latched_buttons. This map likewise belongs to
    // the event thread alone; cross-thread readers use port_has_pad below.
    std::unordered_map<SDL_JoystickID, OpenPad> open_pads;

    // config.input.pad_start_port. Set once at startup, before any event pump,
    // same pattern as the stick_* atomics below.
    std::atomic<int> pad_start_port{0};

    // Whether a pad is currently assigned to each port. Written by the event
    // thread on connect/disconnect, read by get_connected_device_info() (which
    // librecomp calls from the game's own threads). Port 0 is not driven by
    // this -- it is always reported connected, keyboard/mouse being there.
    std::atomic<bool> port_has_pad[max_ports] = {};

    // Per-port pad state, published once per update_gfx() iteration and
    // consumed by get_input(). One entry per N64 port rather than the single
    // process-wide set this used to be; the memory-ordering discipline is
    // unchanged (relaxed; event thread writes, the controller-read thread
    // reads -- there is nothing to order these against, each value stands
    // alone and a one-iteration-stale read is indistinguishable from having
    // sampled a moment earlier).
    std::atomic<uint16_t> pad_buttons[max_ports] = {};
    std::atomic<float> pad_stick_x[max_ports] = {};
    std::atomic<float> pad_stick_y[max_ports] = {};

    // Lowest port with no pad assigned, at or above pad_start_port; -1 if
    // there is none. Event thread only (it is the only writer of open_pads).
    int lowest_free_port() {
        const int start = std::clamp(pad_start_port.load(std::memory_order_relaxed), 0, max_ports - 1);
        for (int port = start; port < max_ports; port++) {
            bool taken = false;
            for (const auto& [id, pad] : open_pads) {
                if (pad.port == port) {
                    taken = true;
                    break;
                }
            }
            if (!taken) {
                return port;
            }
        }
        return -1;
    }

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
    // Accumulates buttons pressed since the last get_input() call, per port.
    // Only written/read when input_latching_enabled is set; update_gfx() ORs
    // fresh presses in (it runs once per host render-loop iteration, far
    // more often than the game's ~15 Hz controller read), and get_input()
    // drains its own port's entry into the buttons it returns.
    //
    // Port 0's entry collects keyboard, mouse and port-0-pad presses (the
    // sources that merge there); ports 1..3 collect only their own pad's.
    std::atomic<uint16_t> latched_buttons[max_ports] = {};

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
                        // Keyboard is port 0's, always.
                        latched_buttons[0].fetch_or(b.mask, std::memory_order_relaxed);
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
                    const int port = lowest_free_port();
                    open_pads[id] = OpenPad{ gc, port };
                    if (port >= 0) {
                        port_has_pad[port].store(true, std::memory_order_relaxed);
                    }
                    // SDL_GameControllerName can return NULL for a nameless device.
                    const char* name = SDL_GameControllerName(gc);
                    if (port >= 0) {
                        std::fprintf(stdout, "Gamepad connected: pad '%s' -> port %d\n",
                                     name != nullptr ? name : "(unnamed)", port);
                    } else {
                        std::fprintf(stdout,
                                     "Gamepad connected: pad '%s' -> no free port (idle)\n",
                                     name != nullptr ? name : "(unnamed)");
                    }
                }
            }
            // `which` is a joystick instance id here (unlike ADDED above).
            else if (event.type == SDL_CONTROLLERDEVICEREMOVED) {
                auto it = open_pads.find(event.cdevice.which);
                if (it != open_pads.end()) {
                    const int port = it->second.port;
                    const char* name = SDL_GameControllerName(it->second.gc);
                    std::fprintf(stdout, "Gamepad disconnected: %s\n", name != nullptr ? name : "(unnamed)");
                    SDL_GameControllerClose(it->second.gc);
                    open_pads.erase(it);
                    if (port >= 0) {
                        port_has_pad[port].store(false, std::memory_order_relaxed);
                        // Nothing may stay held on a port whose pad just left,
                        // or the game would read the last sampled state
                        // forever (the sampling pass below no longer visits
                        // this port).
                        pad_buttons[port].store(0, std::memory_order_relaxed);
                        pad_stick_x[port].store(0.0f, std::memory_order_relaxed);
                        pad_stick_y[port].store(0.0f, std::memory_order_relaxed);
                        // Undrained latches on ports 1..3 must go too: that
                        // port stops being reported connected below, so
                        // get_input() no longer drains it, and the presses
                        // would otherwise resurface on whichever pad next
                        // takes the port. Port 0's latch is deliberately left
                        // alone -- it holds keyboard and mouse presses as
                        // well, which are not this pad's to discard, and port
                        // 0 keeps being read either way.
                        if (port != 0) {
                            latched_buttons[port].store(0, std::memory_order_relaxed);
                        }
                        std::fprintf(stdout, "Gamepad disconnected: port %d freed\n", port);
                    }
                }
            }
            // Digital buttons only -- axis-derived inputs (Z via triggers, C
            // via the right stick) aren't latched. A human trigger pull
            // comfortably spans the game's ~67 ms read interval, unlike the
            // short taps latching exists to rescue, so there's nothing to
            // catch there and latching would just add stale state to drain.
            //
            // Per port: `which` is the joystick instance id, so the press
            // latches onto the port that pad is assigned to and nowhere else.
            // A pad with no port (OpenPad::port < 0) latches nothing.
            else if (latching && event.type == SDL_CONTROLLERBUTTONDOWN) {
                auto it = open_pads.find(event.cbutton.which);
                if (it != open_pads.end() && it->second.port >= 0) {
                    const auto button = static_cast<SDL_GameControllerButton>(event.cbutton.button);
                    for (const PadBinding& b : pad_bindings) {
                        if (b.button == button) {
                            latched_buttons[it->second.port].fetch_or(b.mask, std::memory_order_relaxed);
                            break;
                        }
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
                            // Mouse is port 0's, always, like the keyboard.
                            latched_buttons[0].fetch_or(mask, std::memory_order_relaxed);
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
        //
        // The window's aspect ratio goes to the extended_aim enhancement in
        // the same pass and for the same reason: its horizontal reticle rail
        // is "how much wider than 4:3 the view actually is", so a rail left
        // over from a previous window size would let the player aim at world
        // this window does not render (src/main/extended_aim.cpp).
        if (window != nullptr) {
            int w = 0;
            int h = 0;
            SDL_GetWindowSize(window, &w, &h);
            if (h > 0) {
                window_height.store(h, std::memory_order_relaxed);
                if (w > 0) {
                    kerecomp::set_extended_aim_window_aspect(static_cast<double>(w) /
                                                             static_cast<double>(h));
                }
            }
        }

        // Sample every open pad and publish the per-port state (see
        // open_pads/pad_buttons above for the threading rationale and the
        // port-assignment policy). This is the same accumulate-then-publish
        // pass it has always been, with the accumulators indexed by port: at
        // most one pad can occupy a port, so the OR/sum below now only ever
        // has one contributor per port -- but keeping the shape makes the
        // port-0 path diff as "the old path plus an index".
        uint16_t buttons[max_ports] = {};
        float stick_x[max_ports] = {};
        float stick_y[max_ports] = {};
        // Loaded once per sampling pass, not per pad -- config.input.stick_*
        // (see the atomics above). Identical shaping for every port.
        const float deadzone = stick_deadzone.load(std::memory_order_relaxed);
        const float curve = stick_curve.load(std::memory_order_relaxed);
        const float sensitivity = stick_sensitivity.load(std::memory_order_relaxed);
        for (const auto& [id, pad] : open_pads) {
            if (pad.port < 0) {
                continue; // no port to drive (see OpenPad::port)
            }
            SDL_GameController* const gc = pad.gc;
            const int port = pad.port;
            for (const PadBinding& b : pad_bindings) {
                if (SDL_GameControllerGetButton(gc, b.button)) {
                    buttons[port] |= b.mask;
                }
            }

            // Either trigger fires Z -- this is a rail shooter, the trigger is
            // the natural fire control, and a simple threshold is enough (no
            // need to expose analog trigger depth to the game).
            if (SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 16384 ||
                SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 16384) {
                buttons[port] |= BTN_Z;
            }

            // Right stick -> C buttons, digital thresholds at 0.4 of full
            // scale. SDL's Y axis is down-positive, so negative Y is C-up.
            constexpr Sint16 c_threshold = 13107; // 0.4 * 32767, rounded down
            const Sint16 rx = SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTX);
            const Sint16 ry = SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTY);
            if (rx < -c_threshold) buttons[port] |= BTN_CL;
            if (rx >  c_threshold) buttons[port] |= BTN_CR;
            if (ry < -c_threshold) buttons[port] |= BTN_CU;
            if (ry >  c_threshold) buttons[port] |= BTN_CD;

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
                stick_x[port] += lx * scale;
                stick_y[port] += ly * scale;
            }
        }
        for (int port = 0; port < max_ports; port++) {
            pad_buttons[port].store(buttons[port], std::memory_order_relaxed);
            pad_stick_x[port].store(std::clamp(stick_x[port], -1.0f, 1.0f), std::memory_order_relaxed);
            pad_stick_y[port].store(std::clamp(stick_y[port], -1.0f, 1.0f), std::memory_order_relaxed);
        }
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

    // ---- reported port count ----------------------------------------------
    //
    // What the game is told is plugged in. It gates the multiplayer modes on
    // this (>= 2 controllers enables TEAM and BATTLE -- measured, see
    // analysis/docs/multiplayer.md section 2) and latches the answer at
    // osContInit time, so the policy is resolved once in main() BEFORE
    // recomp::start() rather than lazily on first call.
    //
    // Highest precedence first:
    //   1. KE_FORCE_PORTS=<n> env  -- diagnostic, unchanged from phase 1.
    //   2. config.input.ports 1..4 -- report exactly that many ports.
    //   3. auto (the default): port 0 always, ports 1..3 iff a pad is
    //      currently assigned there.
    //
    // 0 in `configured_ports` means "auto", i.e. not set -- same convention
    // as tuning.rcp_frame_ms.
    std::atomic<int> forced_ports{0};     // 0 = KE_FORCE_PORTS unset
    std::atomic<int> configured_ports{0}; // 0 = input.ports unset (auto)

    bool port_reported_connected(int controller_num) {
        if (controller_num < 0 || controller_num >= max_ports) {
            return false;
        }
        const int forced = forced_ports.load(std::memory_order_relaxed);
        if (forced > 0) {
            return controller_num < forced;
        }
        const int configured = configured_ports.load(std::memory_order_relaxed);
        if (configured > 0) {
            return controller_num < configured;
        }
        // Auto: port 0 is the keyboard/mouse port and is always there.
        return controller_num == 0 || port_has_pad[controller_num].load(std::memory_order_relaxed);
    }

    bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
        if (!port_reported_connected(controller_num)) {
            // A port the game is told is empty must read as no-response, not
            // as a neutral controller -- that is what `false` means here (see
            // ultramodern/input.hpp, and osContGetReadData's err_no). This is
            // also what every previous build did for controller_num != 0.
            return false;
        }

        if (controller_num != 0) {
            // Ports 1..3: that port's pad, and nothing else. No keyboard, no
            // mouse -- those are port 0's by policy (see open_pads above).
            // Stick shaping, trigger->Z and right-stick->C all already
            // happened identically for every port in update_gfx()'s sampling
            // pass, so this is just a publish-side read.
            //
            // A port reported connected with no pad assigned (KE_FORCE_PORTS,
            // input.ports, or a pad unplugged mid-game) lands here and reads
            // connected-but-neutral: every per-port atomic is zeroed on
            // disconnect and starts at zero.
            uint16_t held = pad_buttons[controller_num].load(std::memory_order_relaxed);
            if (input_latching_enabled.load(std::memory_order_relaxed)) {
                held |= latched_buttons[controller_num].exchange(0, std::memory_order_relaxed);
            }
            *buttons = held;
            *x = pad_stick_x[controller_num].load(std::memory_order_relaxed);
            *y = pad_stick_y[controller_num].load(std::memory_order_relaxed);
            return true;
        }

        // Port 0: keyboard + mouse + whichever pad (if any) was assigned to
        // port 0. Everything below this line is the pre-multiplayer path,
        // with the pad atomics indexed [0].
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        if (keys == nullptr) {
            return false;
        }
        uint16_t held = sample_buttons(keys) | pad_buttons[0].load(std::memory_order_relaxed) |
                        mouse_buttons.load(std::memory_order_relaxed);
        if (input_latching_enabled.load(std::memory_order_relaxed)) {
            // Press-latch: OR everything pressed since the last read into what
            // we return now, then clear so the next read starts fresh. Vanilla
            // (flag off) never touches latched_buttons at all, so this is a
            // pure no-op there -- the raw sample above is exactly what used to
            // be returned.
            held |= latched_buttons[0].exchange(0, std::memory_order_relaxed);
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
                // Clamp to the rails the game will actually enforce this
                // frame. It clamps hard there itself, so without this the
                // target would wind up past a reticle that has stopped
                // following.
                //
                // Not the measured +-128/+-84 constants any more: the
                // extended_aim enhancement widens the game's own clamp
                // (src/main/extended_aim.cpp), and a target clamp left behind
                // at the old rails would stop mouse aim short of where the
                // keyboard and pad can still go -- which would read as a
                // mouse bug rather than a range one.
                const kerecomp::AimRails rails = kerecomp::extended_aim_rails();
                target_x = std::clamp(target_x, -static_cast<float>(rails.x),
                                      static_cast<float>(rails.x));
                target_y = std::clamp(target_y, -static_cast<float>(rails.y),
                                      static_cast<float>(rails.y));

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

        *x = std::clamp(kx + pad_stick_x[0].load(std::memory_order_relaxed) + mouse_x, -1.0f, 1.0f);
        *y = std::clamp(ky + pad_stick_y[0].load(std::memory_order_relaxed) + mouse_y, -1.0f, 1.0f);
        return true;
    }

    // Rumble stays a no-op, per port, DELIBERATELY.
    //
    // This callback is only ever reached through osMotorStart/osMotorStop,
    // which librecomp gates on osMotorInit having succeeded, which it does
    // only if get_connected_device_info() reports Pak::RumblePak for that port
    // (deps/N64ModernRuntime/ultramodern/src/input.cpp). We report Pak::None
    // on every port -- the faithful answer for a player with no Rumble Pak --
    // so osMotorInit returns PFS_ERR_NOPACK and this function is unreachable
    // in practice. Making pads actually rumble would mean telling the game a
    // Rumble Pak is inserted, which changes what the game does (it has its own
    // Rumble Pak notice screen before every mission), i.e. it would be an
    // enhancement with a flag, not a quiet side effect of per-port input.
    // See analysis/docs/enhancements.md.
    //
    // The plumbing is nonetheless per-port now: the port index arrives here,
    // and the pad it names is `open_pads`' entry with that `port` -- one
    // lookup away, on the event thread's map, if a flagged rumble enhancement
    // is ever added.
    void set_rumble(int controller_num, bool rumble) {
        (void)controller_num;
        (void)rumble;
    }

    // KE_FORCE_PORTS=<n> (1..4) -- diagnostic, not an enhancement. Unchanged
    // from multiplayer phase 1 except for the log line's parenthetical, which
    // used to say "only port 0 receives input" and no longer would be true.
    //
    // The game asks the runtime how many controllers are plugged in
    // (osContInit -> librecomp -> get_connected_device_info) and gates its
    // multiplayer offer on the answer. Before per-port input existed this was
    // the only way to reach the multiplayer code paths at all; it remains the
    // way to reach them without four pads on the desk. With the variable set,
    // ports 0..n-1 report Device::Controller; ports n..3 stay Device::None.
    //
    // Unset => 0 and the whole override drops out of port_reported_connected().
    int parse_forced_ports() {
        const char* env = std::getenv("KE_FORCE_PORTS");
        if (env == nullptr || env[0] == '\0') {
            return 0;
        }
        char* end = nullptr;
        long parsed = std::strtol(env, &end, 10);
        if (end == env || parsed < 1 || parsed > 4) {
            std::fprintf(stderr,
                "[input] KE_FORCE_PORTS=\"%s\" is not a number in 1..4; ignoring\n", env);
            return 0;
        }
        return static_cast<int>(parsed);
    }

    // Resolves the reported-port-count policy and logs it, once, from main()
    // before recomp::start(). Must happen before osContInit: the game latches
    // the controller count then, and the multiplayer menu entries are gated on
    // what it latched (analysis/docs/multiplayer.md sections 2 and 7.1).
    void init_port_policy(const kerecomp::Config& config) {
        pad_start_port.store(config.input.pad_start_port, std::memory_order_relaxed);
        configured_ports.store(config.input.ports, std::memory_order_relaxed);
        const int forced = parse_forced_ports();
        forced_ports.store(forced, std::memory_order_relaxed);

        const int start = config.input.pad_start_port;
        if (forced > 0) {
            std::fprintf(stderr,
                "[input] ports: KE_FORCE_PORTS=%d -- reporting ports 0..%d as connected "
                "(a port with no pad assigned reads neutral); pads from port %d\n",
                forced, forced - 1, start);
        } else if (config.input.ports > 0) {
            std::fprintf(stderr,
                "[input] ports: input.ports=%d -- reporting ports 0..%d as connected "
                "(a port with no pad assigned reads neutral); pads from port %d\n",
                config.input.ports, config.input.ports - 1, start);
        } else {
            std::fprintf(stderr,
                "[input] ports: auto -- port 0 always (keyboard/mouse), ports 1-3 follow "
                "connected pads; pads from port %d\n", start);
        }
    }

    ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
        if (port_reported_connected(controller_num)) {
            // Pak::None on every port, deliberately -- see set_rumble() above
            // for why reporting a Rumble Pak would be an enhancement.
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
    // App data (config/ROM cache) location can vary now (KE_DATA_DIR, see
    // support.cpp) -- print it so a bug report self-identifies where to look.
    std::fprintf(stdout, "app data: %s\n", app_folder.string().c_str());
    std::fflush(stdout);

    kerecomp::EnhancementFlags enhancements = kerecomp::effective_enhancements(config);
    input_latching_enabled.store(enhancements.input_latching, std::memory_order_relaxed);
    kerecomp::set_rcp_frame_ms_tuning(config.tuning.rcp_frame_ms);
    kerecomp::set_full_height_enhancement(enhancements.full_height);
    // hud_relocation (analysis/docs/hud-relocation.md). The vertical half of
    // the re-anchoring only applies when full_height is on -- that is what
    // exposes the 20-line bands the HUD is otherwise flush against.
    kerecomp::renderer::set_hud_relocation_enhancement(enhancements.hud_relocation,
                                                       enhancements.full_height);
    // extended_aim (analysis/docs/hud-relocation.md, "Reticle range
    // extension"). Each half is keyed to the flag that creates the screen area
    // it pans into: widescreen for the horizontal rail, full_height for the
    // vertical one. The horizontal half additionally needs hud_relocation,
    // because its draw side IS hud_relocation's machinery -- the reticle's
    // re-anchoring stub is what cancels the game-side blit bias, and the
    // prologue's scissor re-expression is what keeps RT64 from clipping the
    // reticle at the centered 4:3 column. The rails themselves are derived
    // from the live window aspect, which update_gfx() publishes; there is no
    // window yet at this point in startup.
    kerecomp::set_extended_aim_enhancement(
        enhancements.extended_aim && enhancements.widescreen && enhancements.hud_relocation,
        enhancements.extended_aim && enhancements.full_height);

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

    // Multiplayer port policy (config.input.pad_start_port / .ports, plus the
    // KE_FORCE_PORTS override). Resolved and logged here, before
    // recomp::start() spins up the game threads -- osContInit latches the
    // controller count and the multiplayer menu entries are gated on it.
    init_port_policy(config);

    // enhancements.high_resolution / .widescreen / .high_framerate
    // (analysis/docs/enhancements.md). Must be set before recomp::start()
    // below spins up the gfx thread, since gfx_thread_func() reads
    // get_graphics_config() as its very first action (both directly for
    // developer_mode and via create_render_context(), and again for its
    // "old_config" baseline) -- setting it any later would race the gfx
    // thread's startup read. Every field except res_option, ar_option, and
    // rr_option pins today's value-initialized GraphicsConfig{} default (all
    // enums 0, ints 0) so that vanilla (all three flags off) stays
    // bit-identical to pre-existing behavior; ds_option=1 here vs the
    // implicit 0 before this code existed are equivalent because
    // set_application_user_config() (src/main/rt64_render_context.cpp)
    // clamps with max(ds_option, 1). rr_manual_value stays pinned at 0 --
    // RT64's Manual refresh-rate mode is deliberately not exposed yet (see
    // analysis/docs/high-framerate.md).
    ultramodern::renderer::GraphicsConfig gfx_config{};
    gfx_config.developer_mode = false;
    gfx_config.res_option = enhancements.high_resolution ? ultramodern::renderer::Resolution::Auto
                                                          : ultramodern::renderer::Resolution::Original;
    gfx_config.wm_option = ultramodern::renderer::WindowMode::Windowed;
    // hr_option drives RT64's extAspectRatio, which is *only* consulted for
    // rects that carry an extended-GBI origin (it scales
    // convertViewportRect()'s computeOrigin() by extAspectPercentage, and
    // that function returns the framebuffer centre unconditionally for
    // G_EX_ORIGIN_NONE -- deps/rt64/src/render/rt64_framebuffer_renderer.cpp).
    // No game rect ever carries one, so this changes nothing except how the
    // hud_relocation stubs' own aligned rects resolve: Original collapses
    // every origin onto the 4:3 column's centre, which makes the stubs an
    // exact no-op, and Expand is what lets LEFT/RIGHT reach the real window
    // edges. Only worth switching when there is a widescreen gap to escape
    // into. See analysis/docs/hud-relocation.md, "Phase 2".
    gfx_config.hr_option = (enhancements.hud_relocation && enhancements.widescreen)
                               ? ultramodern::renderer::HUDRatioMode::Full
                               : ultramodern::renderer::HUDRatioMode::Original;
    gfx_config.api_option = ultramodern::renderer::GraphicsApi::Auto;
    gfx_config.ar_option = enhancements.widescreen ? ultramodern::renderer::AspectRatio::Expand
                                                    : ultramodern::renderer::AspectRatio::Original;
    gfx_config.msaa_option = ultramodern::renderer::Antialiasing::None;
    gfx_config.rr_option = enhancements.high_framerate ? ultramodern::renderer::RefreshRate::Display
                                                        : ultramodern::renderer::RefreshRate::Original;
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
        // Portal ROM picker. Launcher UX, not an enhancement
        // (analysis/docs/enhancements.md's policy is about gameplay-affecting
        // deviations from vanilla; this only gets a path onto disk). It
        // exists chiefly for the Flatpak build (packaging/flatpak/), where a
        // portal file-open dialog is the sanctioned way to reach host files
        // from a sandbox granted zero explicit filesystem permissions -- see
        // that manifest's finish-args comment.
        //
        // Only attempted when a display is plausibly present. A headless run
        // (no DISPLAY and no WAYLAND_DISPLAY -- this is CI's contract, and
        // also plain `--rom`-less local runs over SSH) must keep failing
        // exactly as before: promptly, with no dialog attempt at all, so it
        // can never hang a script or a CI job.
        const char* display_env = std::getenv("DISPLAY");
        const char* wayland_env = std::getenv("WAYLAND_DISPLAY");
        bool have_display = (display_env != nullptr && display_env[0] != '\0') ||
                             (wayland_env != nullptr && wayland_env[0] != '\0');

#if defined(__linux__)
        // See portal_reachable() above: without this, a live display but no
        // portal service (bare Xvfb, no xdg-desktop-portal) hangs forever
        // inside NFD's own D-Bus call rather than falling through.
        bool attempt_picker = have_display && portal_reachable();
#else
        bool attempt_picker = have_display;
#endif

        if (attempt_picker) {
            // CRITICAL (see CLAUDE.md open items / this file's git history):
            // on NFD's portal backend, NFD_Quit() unconditionally calls
            // dbus_connection_unref() on a connection that only exists if
            // NFD_Init() actually succeeded. Calling NFD_Quit() after a
            // FAILED NFD_Init() (e.g. no xdg-desktop-portal service, or no
            // session bus at all -- both plausible under a bare Xvfb) aborts
            // the whole process. nfd.h's own doc comment says as much
            // ("Call this ... if NFD_Init returned NFD_OKAY"); the bug is
            // that violating it doesn't fail soft, it aborts. So: the
            // NFD_Quit() call below is reachable ONLY through the
            // `NFD_Init() == NFD_OKAY` branch, and nowhere else in this
            // function.
            if (NFD_Init() == NFD_OKAY) {
                nfdu8char_t* picked_path = nullptr;
                const nfdu8filteritem_t rom_filters[1] = {{"N64 ROM", "z64,n64,v64"}};
                nfdresult_t dialog_result = NFD_OpenDialogU8(&picked_path, rom_filters, 1, nullptr);
                if (dialog_result == NFD_OKAY && picked_path != nullptr) {
                    // Treat the picked path exactly as if it had been passed
                    // via --rom: run it through the same select_rom()
                    // validation, so a bad pick fails the same way a bad
                    // --rom path would.
                    rom_path = picked_path;
                    NFD_FreePathU8(picked_path);
                    recomp::RomValidationError rom_err = recomp::select_rom(rom_path, knife_edge_entry.game_id);
                    if (rom_err != recomp::RomValidationError::Good) {
                        NFD_Quit();
                        exit_error("ROM validation failed (error " +
                                   std::to_string(static_cast<int>(rom_err)) + ") for " +
                                   rom_path.string());
                        return EXIT_FAILURE;
                    }
                    // select_rom() stores the ROM on disk but is_rom_valid()
                    // consults an in-memory set populated only by
                    // check_all_stored_roms() -- which already ran, before
                    // this picker. Rescan, or the is_rom_valid() gate below
                    // fails on exactly the launch that picked the ROM (it
                    // then works on every later launch, which is how this
                    // shipped: the one-launch-late symptom looked like
                    // success in every after-the-first test).
                    recomp::check_all_stored_roms();
                }
                // Cancel, dialog error, or NFD_Init failure: fall through to
                // the no-ROM error below, unchanged.
                NFD_Quit();
            }
        }
    }

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
