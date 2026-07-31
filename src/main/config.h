#pragma once

// Enhancement-flag / profile configuration (analysis/docs/enhancements.md).
//
// The policy: every deviation from the original game's behavior is a
// runtime-toggleable "enhancement", off by default, so the game stays
// available as a faithful regression baseline ("vanilla") at all times.
// This header is the config surface for that policy; src/main/main.cpp reads
// it once at startup and wires the resulting flags into the input backend
// (press-latching), src/main/rcp_timing.cpp (the RCP frame-time tuning
// knob), and the RT64 renderer's graphics config (resolution).
//
// Precedence, matching analysis/docs/enhancements.md: CLI > env > config file
// > built-in defaults. The only CLI flags are --profile <name> and
// --config <path>; the only env var is KE_RCP_FRAME_MS (unchanged from
// before this file existed), which src/main/rcp_timing.cpp still reads
// directly and which wins over tuning.rcp_frame_ms from the file.

#include <filesystem>
#include <string>

namespace kerecomp {

// Which set of enhancements is active. "vanilla" and "enhanced" are curated,
// named baselines; "custom" reads [enhancements] from the config file
// individually. See effective_enhancements() below.
enum class Profile {
    Vanilla,
    Enhanced,
    Custom,
};

// Runtime-toggleable behavioral deviations from the original game. Every
// field defaults to off/faithful, so a default-constructed EnhancementFlags
// is always a safe fallback (it's exactly what "vanilla" resolves to).
struct EnhancementFlags {
    // Latches a key press between controller reads so a tap shorter than one
    // game frame (~67 ms -- the game samples the pad at ~15 Hz, see
    // analysis/docs/timing-and-mission-debug.md 3.1) still registers on the
    // next read. Vanilla (off) samples raw state per read, same as hardware.
    bool input_latching = false;

    // Renders the 3D scene at window resolution through RT64 (window-integer-
    // scale mode) instead of the original 320x240. Vanilla (off) renders
    // native 320x240 like original hardware, upscaled by the display path.
    bool high_resolution = false;

    // Expands the 3D scene's field of view to fill the window's aspect ratio
    // via RT64's Expand mode, instead of staying 4:3. Vanilla (off) keeps the
    // original 4:3 presentation, pillarboxed in a wider window, like original
    // hardware.
    bool widescreen = false;

    // Removes the in-mission letterbox: the game renders missions at
    // 320x200 (a 20-line black band top and bottom), an RDP scissor derived
    // from a height global that the viewport/projection never see -- the
    // extra rows are genuinely rendered scene, not a stretch. On = full
    // 320x240. Vanilla (off) keeps the 320x200 letterbox, faithful to
    // original hardware.
    bool full_height = false;

    // Re-anchors the in-mission HUD to the true window edges instead of
    // leaving it inside the centered 4:3 column (widescreen) and against the
    // 320x200-era letterbox bands (full_height). The health cluster anchors
    // LEFT and the S-BOMB gauge RIGHT, each keeping its own original margin
    // (20 px / 25 px), dynamic fills included; the aiming reticle anchors
    // CENTER, i.e. exactly where it is today; the full-screen flash stretches
    // edge to edge. The in-mission cutscene radio box is deliberately left
    // exactly where the game draws it (owner decision 2026-07-31 -- the
    // cutscene's own effects are authored against the 4:3 column). The
    // vertical half only applies when full_height is also on -- that is what
    // exposes the 20-line bands the HUD is currently flush against, so the
    // bottom clusters move 20 px down; with the letterbox still present there
    // is nothing to correct. Purely a presentation change: the game's own
    // coordinates, its aim math and every game-side global are untouched,
    // only where RT64 places the resulting rectangles changes. Vanilla (off)
    // leaves the HUD where original hardware put it.
    bool hud_relocation = false;

    // EXPERIMENTAL. Renders at the display's refresh rate via RT64's frame
    // interpolation: game logic keeps stepping at its original paced rate
    // (rcp_timing.cpp is untouched), and RT64 synthesizes the in-between
    // frames by interpolating transforms between consecutive game frames.
    // Known visual artifacts (owner hands-on, 2026-07-31): RT64's heuristic
    // transform matching warps/smears some per-frame-respawned effects --
    // confirmed on the lock-on effect and bullet trails -- so this is NOT in
    // the enhanced profile's curated set; opt in via the custom profile. The
    // fix path is per-effect gEXMatrixGroup tagging (analysis/docs/
    // high-framerate.md section 4). Vanilla (off) presents one frame per game
    // step, like original hardware.
    bool high_framerate = false;
};

// Fidelity knobs -- NOT enhancements. These approximate a real-hardware
// mechanism (here, how long the RCP takes to render a frame; see
// src/main/rcp_timing.cpp) rather than changing behavior on purpose.
struct TuningFlags {
    // Overrides the modelled RCP frame-time budget, in milliseconds.
    // 0 = built-in model (59.733 ms). Distinct from the KE_RCP_FRAME_MS env
    // var, whose own 0 explicitly disables pacing -- that existing meaning is
    // preserved unchanged in rcp_timing.cpp; this file-derived value never
    // disables pacing, it only opts out of overriding the built-in default.
    double rcp_frame_ms = 0.0;
};

// How mouse motion is turned into stick deflection (src/main/main.cpp's
// get_input(); the full RE and controller design are in
// analysis/docs/mouse-aim.md).
enum class MouseMode {
    // Closed loop on the game's own reticle position: mouse travel moves a
    // target in reticle units and a deadbeat controller emits whatever stick
    // deflection walks the reticle onto it. 1:1 and absolute -- the same
    // mouse travel always produces the same on-screen movement.
    Positional,
    // Open loop: mouse speed maps directly to stick deflection, so the
    // reticle drifts while the mouse moves. The original mouse-aim mapping,
    // kept because it needs no reticle state at all.
    Velocity,
};

// Analog-stick response shaping -- host input-device tuning, NOT enhancements
// (the pad itself is not an enhancement either; see the gamepad commit).
// Applies in every profile, vanilla included: it shapes how the host stick
// maps to the N64 stick range, never what the game does with the result.
struct InputTuning {
    double stick_deadzone = 0.15;     // radial, [0.0, 0.9]
    double stick_curve = 1.0;         // response exponent, [0.25, 4.0]
    double stick_sensitivity = 1.0;   // post-curve multiplier, [0.1, 3.0]

    // Master switch for mouse-look input (src/main/main.cpp: click to
    // capture the pointer, Esc to release; while captured, mouse motion
    // adds to the control stick and L/R/M buttons map to A/B/Z). Off by
    // default is NOT vanilla-fidelity policy here -- mouse aim has no N64
    // hardware analog either way, so this defaults on as a QoL convenience
    // available regardless of profile, same as the stick tuning above.
    bool mouse_aim = true;
    // Multiplier on mouse-derived stick deflection. Range [0.05, 20.0]. In
    // positional mode it scales the pixels-to-reticle-units mapping instead,
    // i.e. it is a straightforward "how far the reticle goes per inch of
    // mouse" knob rather than a deflection multiplier.
    double mouse_sensitivity = 1.0;
    // Positional (default) or velocity mouse-to-stick mapping; see MouseMode.
    MouseMode mouse_mode = MouseMode::Positional;
    // Inverts the vertical mouse axis in BOTH modes. Default (off) is
    // mouse-up = reticle-up. The game's own aiming is flight-inverted (a
    // stick pushed up drives the reticle DOWN -- measured, see
    // analysis/docs/mouse-aim.md), so turning this on restores that
    // convention for players who prefer it.
    bool mouse_invert_y = false;
};

struct Config {
    // Default is Enhanced (owner decision, 2026-07-30): the out-of-box
    // experience is the curated quality-of-life set. Vanilla remains fully
    // available (--profile vanilla / [profile] active) and remains the
    // REGRESSION BASELINE -- every timing measurement and bug investigation
    // in analysis/docs/ assumes vanilla unless stated otherwise.
    Profile profile = Profile::Enhanced;
    // Only consulted when profile == Custom; effective_enhancements() below
    // ignores this field for Vanilla/Enhanced.
    EnhancementFlags enhancements;
    TuningFlags tuning;
    // Read regardless of profile, like tuning above -- see InputTuning.
    InputTuning input;
};

// Resolves the full config for this run:
//   1. Parses argv for --profile <name> and --config <path> (no other flags).
//   2. Loads TOML from --config's path, or <app_folder>/config.toml if
//      --config wasn't given.
//   3. If that file doesn't exist, creates it with commented vanilla
//      defaults and returns vanilla defaults.
//   4. If the file exists but fails to parse, warns to stderr once and falls
//      back to vanilla defaults. Never throws or crashes.
//   5. Unknown keys anywhere in the file are collected and warned about once
//      (not per-key spam), then ignored.
//   6. --profile (if given) overrides [profile].active from the file.
//   7. [input] values outside their documented ranges are clamped, each with
//      its own single stderr warning naming the key, the given value, and
//      the clamped value.
// KE_RCP_FRAME_MS is deliberately NOT resolved here -- src/main/rcp_timing.cpp
// still reads it directly and applies it with higher precedence than
// tuning.rcp_frame_ms, so that existing behavior/log line is untouched.
Config load_config(int argc, char** argv, const std::filesystem::path& app_folder);

// The enhancement set actually in effect for cfg.profile:
//   Vanilla  -> EnhancementFlags{} (everything off)
//   Enhanced -> the curated set (input_latching = true, high_resolution = true,
//               widescreen = true, full_height = true, hud_relocation = true;
//               high_framerate stays off -- experimental, known artifacts,
//               see its field comment)
//   Custom   -> cfg.enhancements verbatim
EnhancementFlags effective_enhancements(const Config& cfg);

// One-line startup summary ("profile: vanilla" or
// "profile: custom (input_latching=on, rcp_frame_ms=55.0)"), logged right
// after the build stamp so a bug report self-identifies its config too.
// Any [input] field left at its default is omitted; a tuned stick appears as
// e.g. "stick_deadzone=0.10" regardless of profile.
std::string describe_config(const Config& cfg);

} // namespace kerecomp
