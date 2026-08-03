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
    // If the KE_DATA_DIR environment variable is set to a non-empty value,
    // that path is used verbatim (still create_directories'd). This is the
    // override the Flatpak wrapper (packaging/flatpak/knife-edge-recompiled.sh)
    // sets to a per-app XDG_DATA_HOME path, since the sandbox's working
    // directory is not a stable (or necessarily writable) place to keep the
    // ROM cache/config across launches and updates.
    //
    // Windows: without KE_DATA_DIR, this is %LOCALAPPDATA%\KnifeEdgeRecompiled
    // (LOCALAPPDATA, not roaming APPDATA -- this directory holds the cached
    // ROM (~12 MB) plus config, and roaming would sync that across domain
    // profiles). Falls back to the CWD-relative default below if
    // LOCALAPPDATA is unset or empty.
    //
    // TODO: without KE_DATA_DIR, Linux/macOS still fall back to the
    // CWD-relative default below rather than a proper XDG_DATA_HOME (Linux)
    // / Application Support (macOS) directory, once save/config handling is
    // implemented more broadly.
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

    // ---- measured game-frame cadence (analysis/docs/high-framerate.md,
    // src/main/rcp_timing.cpp) ----
    // EMA (alpha 0.25) of the interval between consecutive game graphics
    // tasks, in milliseconds; load/pause hitches (>250 ms) and sub-millisecond
    // noise (<1 ms) are excluded from the average rather than resetting it.
    // 0.0 means no measurement yet (no task has completed a second time).
    // Used by src/main/rt64_render_context.cpp to declare the game's logic
    // rate to RT64 so its frame-interpolation auto-detection -- which needs a
    // consistent 60/N VI cadence this game never produces -- has a rate to
    // work with at all.
    double measured_game_frame_interval_ms();

    // ---- enhancements (analysis/docs/enhancements.md, src/main/full_height.cpp) --
    // Turns the full_height enhancement on/off (removes the in-mission
    // letterbox, rendering the full 320x240 frame instead of 320x200).
    // Implemented in full_height.cpp. Call once, before recomp::start(), with
    // the resolved kerecomp::EnhancementFlags's value.
    void set_full_height_enhancement(bool on);

    // ---- extended aim range (analysis/docs/hud-relocation.md, "Reticle range
    // extension"; src/main/extended_aim.cpp) ----
    //
    // The reticle's clamp rails, in N64 pixels, as currently resolved. Vanilla
    // is {128, 84, 0}; the extended_aim enhancement widens them to the same
    // fraction of the enlarged view that the originals were of the 4:3 /
    // 320x200 one. `draw_bias` is the N64-pixel shift the reticle's sprite
    // blit is given so its texrect coordinates stay non-negative at the left
    // rail, and which the reticle's hud_relocation stub subtracts again at
    // draw time; it is derived from `x` (= x - 128), never stored separately,
    // so the two can never disagree.
    //
    // Read by the positional mouse controller (src/main/main.cpp, whose target
    // clamp has to match the rail the game will actually enforce) and by the
    // renderer (src/main/rt64_render_context.cpp, for the stub offset).
    struct AimRails {
        int32_t x = 128;
        int32_t y = 84;
        int32_t draw_bias = 0;
    };
    AimRails extended_aim_rails();

    // Turns the two halves of the enhancement on/off. Call once from main(),
    // before recomp::start(), with:
    //
    //   horizontal = extended_aim && widescreen && hud_relocation
    //   vertical   = extended_aim && full_height
    //
    // widescreen/full_height because without them there is no extra visible
    // area to pan into. hud_relocation because the horizontal half's draw side
    // is built out of its machinery: the reticle's re-anchoring stub is what
    // undoes the blit bias, and its prologue's scissor re-expression is what
    // stops RT64 clipping the reticle at the centered 4:3 column's edge. The
    // vertical half needs neither.
    void set_extended_aim_enhancement(bool horizontal, bool vertical);

    // The live window aspect ratio (width/height) the horizontal rail is
    // derived from. Called from update_gfx() whenever the window size changes,
    // for the same reason window_height is republished there: a rail computed
    // from a stale aspect would let the reticle point at world the current
    // window does not render.
    void set_extended_aim_window_aspect(double aspect);

    // Called with false by the renderer if its scratch RDRAM is not available,
    // which is what the reticle's relocation stub is built in. Without that
    // stub the blit bias would never be undone, so the horizontal half falls
    // back to the vanilla rail instead. Fails safe; never called with true.
    void set_extended_aim_draw_supported(bool supported);
}
