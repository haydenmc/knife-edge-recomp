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

// Analog-stick response shaping -- host input-device tuning, NOT enhancements
// (the pad itself is not an enhancement either; see the gamepad commit).
// Applies in every profile, vanilla included: it shapes how the host stick
// maps to the N64 stick range, never what the game does with the result.
struct InputTuning {
    double stick_deadzone = 0.15;     // radial, [0.0, 0.9]
    double stick_curve = 1.0;         // response exponent, [0.25, 4.0]
    double stick_sensitivity = 1.0;   // post-curve multiplier, [0.1, 3.0]
};

struct Config {
    Profile profile = Profile::Vanilla;
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
//               widescreen = true, full_height = true)
//   Custom   -> cfg.enhancements verbatim
EnhancementFlags effective_enhancements(const Config& cfg);

// One-line startup summary ("profile: vanilla" or
// "profile: custom (input_latching=on, rcp_frame_ms=55.0)"), logged right
// after the build stamp so a bug report self-identifies its config too.
// Any [input] field left at its default is omitted; a tuned stick appears as
// e.g. "stick_deadzone=0.10" regardless of profile.
std::string describe_config(const Config& cfg);

} // namespace kerecomp
