#include "config.h"

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <string_view>
#include <vector>

// Vendored by deps/N64Recomp (deps/N64ModernRuntime/N64Recomp/lib/tomlplusplus),
// already a linkable CMake target (tomlplusplus::tomlplusplus) because
// N64Recomp/RSPRecomp use it for their own config.toml input format -- see
// analysis/docs/enhancements.md for why this project reuses it instead of
// vendoring a second TOML parser.
#include <toml++/toml.hpp>

namespace {
    using kerecomp::Config;
    using kerecomp::EnhancementFlags;
    using kerecomp::InputTuning;
    using kerecomp::MouseMode;
    using kerecomp::Profile;
    using kerecomp::TuningFlags;

    void warn(const std::string& message) {
        std::fprintf(stderr, "[config] warning: %s\n", message.c_str());
    }

    // Clamps an [input] value to [lo, hi], warning once (naming the key, the
    // given value, and the clamped value) if it was out of range.
    double clamp_input_value(const char* key, double value, double lo, double hi) {
        if (value < lo || value > hi) {
            double clamped = std::clamp(value, lo, hi);
            char buf[192];
            std::snprintf(buf, sizeof(buf),
                "input.%s = %g is out of range [%g, %g]; clamping to %g",
                key, value, lo, hi, clamped);
            warn(buf);
            return clamped;
        }
        return value;
    }

    // Integer counterpart of clamp_input_value, same warning shape (whole
    // numbers read better as "= 7" than "= 7.000000" in the message, and the
    // TOML values are genuinely integers).
    int clamp_input_int(const char* key, int64_t value, int lo, int hi) {
        if (value < lo || value > hi) {
            int clamped = static_cast<int>(std::clamp<int64_t>(value, lo, hi));
            char buf[192];
            std::snprintf(buf, sizeof(buf),
                "input.%s = %lld is out of range [%d, %d]; clamping to %d",
                key, static_cast<long long>(value), lo, hi, clamped);
            warn(buf);
            return clamped;
        }
        return static_cast<int>(value);
    }

    const char* profile_name(Profile p) {
        switch (p) {
            case Profile::Vanilla: return "vanilla";
            case Profile::Enhanced: return "enhanced";
            case Profile::Custom: return "custom";
        }
        return "vanilla";
    }

    bool parse_profile_name(std::string_view s, Profile& out) {
        if (s == "vanilla") { out = Profile::Vanilla; return true; }
        if (s == "enhanced") { out = Profile::Enhanced; return true; }
        if (s == "custom") { out = Profile::Custom; return true; }
        return false;
    }

    bool parse_mouse_mode_name(std::string_view s, MouseMode& out) {
        if (s == "positional") { out = MouseMode::Positional; return true; }
        if (s == "velocity") { out = MouseMode::Velocity; return true; }
        return false;
    }

    // Written verbatim to <app_folder>/config.toml (or --config's path) the
    // first time no config file is found there, so a fresh install has a
    // documented, editable starting point rather than a silently-implied one.
    constexpr std::string_view default_file_contents =
        "# Knife Edge Recompiled configuration.\n"
        "#\n"
        "# See analysis/docs/enhancements.md for what these do and why. This file\n"
        "# is regenerated with these defaults if it's missing; if it fails to\n"
        "# parse, the game warns to stderr and falls back to these defaults too\n"
        "# rather than refusing to start.\n"
        "\n"
        "[profile]\n"
        "# \"enhanced\" (default): a curated set of quality-of-life changes.\n"
        "# \"vanilla\": every enhancement OFF -- the regression baseline,\n"
        "#   faithful to original hardware behavior.\n"
        "# \"custom\": read [enhancements] below individually.\n"
        "active = \"enhanced\"\n"
        "\n"
        "[enhancements]\n"
        "# Only consulted when profile.active = \"custom\".\n"
        "input_latching = false\n"
        "# Renders the 3D scene at window resolution via RT64 instead of native\n"
        "# 320x240.\n"
        "high_resolution = false\n"
        "# Expands the 3D scene's field of view to fill the window's aspect ratio\n"
        "# instead of staying 4:3 (pillarboxed).\n"
        "widescreen = false\n"
        "# Removes the 20-line letterbox during missions (renders the full\n"
        "# 320x240 frame).\n"
        "full_height = false\n"
        "# Re-anchors the in-mission HUD to the true window edges: the health\n"
        "# cluster to the bottom-left, the S-BOMB gauge to the bottom-right,\n"
        "# each keeping its original margin. The cutscene radio box is left\n"
        "# exactly where the game draws it. Only meaningful alongside\n"
        "# widescreen (which is what creates the gap) and full_height (which\n"
        "# is what exposes the extra 20 lines the HUD then moves into).\n"
        "hud_relocation = false\n"
        "# Lets the aiming reticle reach the whole visible viewport instead of\n"
        "# stopping at the original +-128/+-84 rails, scaling them by exactly\n"
        "# how much the view opened (+-170 at 16:9, +-100 vertically). Changes\n"
        "# what is aimable, not just how it looks. The horizontal half needs\n"
        "# widescreen and hud_relocation, the vertical half needs full_height.\n"
        "extended_aim = false\n"
        "# EXPERIMENTAL: renders at the display's refresh rate via RT64 frame\n"
        "# interpolation; game logic keeps its original paced rate (see\n"
        "# analysis/docs/high-framerate.md). Known visual artifacts on some\n"
        "# effects (e.g. the lock-on effect and bullet trails) -- not part of\n"
        "# the enhanced profile for that reason. Off presents one frame per\n"
        "# game step, like original hardware.\n"
        "high_framerate = false\n"
        "\n"
        "[tuning]\n"
        "# Fidelity knobs, NOT enhancements -- see src/main/rcp_timing.cpp.\n"
        "# 0 = built-in model (59.733 ms/frame). The KE_RCP_FRAME_MS environment\n"
        "# variable still overrides this when set.\n"
        "rcp_frame_ms = 0.0\n"
        "\n"
        "[input]\n"
        "# Analog-stick response shaping -- host input-device tuning, NOT\n"
        "# enhancements. Applies in every profile, vanilla included: it shapes how\n"
        "# the host stick maps to the N64 stick range, never what the game does\n"
        "# with the result. Out-of-range values are clamped, with a warning.\n"
        "# Radial deadzone: stick travel below this magnitude is ignored. Range\n"
        "# [0.0, 0.9].\n"
        "stick_deadzone = 0.15\n"
        "# Response curve exponent applied after the deadzone rescale. 1.0 is\n"
        "# linear; >1.0 gives finer control near center without changing full\n"
        "# deflection. Range [0.25, 4.0].\n"
        "stick_curve = 1.0\n"
        "# Multiplier applied after the curve. >1.0 reaches full deflection\n"
        "# before the stick is maxed out; <1.0 caps below full deflection.\n"
        "# Range [0.1, 3.0].\n"
        "stick_sensitivity = 1.0\n"
        "# Mouse aim: click the window to capture the pointer and steer with\n"
        "# mouse motion (added to the control stick); Esc releases capture.\n"
        "# While captured, left/right/middle mouse buttons map to Z/A/B\n"
        "# (left = fire).\n"
        "mouse_aim = true\n"
        "# Multiplier on mouse-derived aiming. Range [0.05, 20.0].\n"
        "mouse_sensitivity = 1.0\n"
        "# \"positional\" (default): the reticle is driven to follow the mouse 1:1,\n"
        "#   closed-loop on the game's own reticle position (analysis/docs/mouse-aim.md).\n"
        "# \"velocity\": mouse speed maps to stick deflection, so the reticle drifts\n"
        "#   while the mouse moves.\n"
        "mouse_mode = \"positional\"\n"
        "# Inverts the vertical mouse axis in both modes. Off (default) is\n"
        "# mouse-up = reticle-up; on restores the game's own flight-inverted aim.\n"
        "mouse_invert_y = false\n"
        "# Multiplayer port assignment. Keyboard and mouse are always N64\n"
        "# controller 1 (port 0); pads take ports in connection order starting\n"
        "# at pad_start_port, lowest free port first, and keep them until\n"
        "# unplugged. 0 (default) puts the first pad on port 0 too, merged with\n"
        "# keyboard and mouse -- the single-player behavior. Set it to 1 for\n"
        "# keyboard-on-P1 plus pads on P2..P4. Range [0, 3].\n"
        "pad_start_port = 0\n"
        "# How many controller ports to report to the game. The game only\n"
        "# offers its TEAM/BATTLE multiplayer modes when it sees at least 2, and\n"
        "# it checks once at startup. 0 (default) = auto: port 0 always, ports\n"
        "# 1-3 while a pad is assigned to them. 1-4 reports exactly that many\n"
        "# whatever is plugged in, so you can reach multiplayer with fewer pads\n"
        "# than players (the empty ports just never press anything). Range\n"
        "# [0, 4].\n"
        "ports = 0\n";

    // Parses argv for --profile <name> and --config <path> only, matching
    // main.cpp's existing minimal --rom parsing style.
    struct CliArgs {
        std::string profile;
        std::filesystem::path config_path;
    };

    CliArgs parse_cli_args(int argc, char** argv) {
        CliArgs args{};
        for (int i = 1; i < argc - 1; i++) {
            std::string_view arg{argv[i]};
            if (arg == "--profile") {
                args.profile = argv[i + 1];
            } else if (arg == "--config") {
                args.config_path = argv[i + 1];
            }
        }
        return args;
    }

    // Reads [profile]/[enhancements]/[tuning] out of an already-parsed TOML
    // table into a Config, collecting any key it doesn't recognize (at any
    // level) into `unknown` instead of warning immediately -- load_config()
    // reports them as a single consolidated warning.
    Config config_from_table(const toml::table& tbl, std::vector<std::string>& unknown) {
        Config cfg{};

        for (auto&& [key, value] : tbl) {
            std::string_view k = key.str();
            if (k != "profile" && k != "enhancements" && k != "tuning" && k != "input") {
                unknown.emplace_back(k);
            }
        }

        if (const toml::table* profile_tbl = tbl["profile"].as_table()) {
            for (auto&& [key, value] : *profile_tbl) {
                if (key.str() != "active") {
                    unknown.emplace_back(std::string("profile.") + std::string(key.str()));
                }
            }
            if (auto active = profile_tbl->get("active")) {
                if (auto s = active->value<std::string>()) {
                    Profile p;
                    if (parse_profile_name(*s, p)) {
                        cfg.profile = p;
                    } else {
                        warn("profile.active = \"" + *s + "\" is not one of "
                             "vanilla|enhanced|custom; using the default (enhanced)");
                    }
                } else {
                    warn("profile.active is not a string; using the default (enhanced)");
                }
            }
        }

        if (const toml::table* enh_tbl = tbl["enhancements"].as_table()) {
            // Known [enhancements] keys -- add one line here per new flag.
            static constexpr std::string_view known_enhancement_keys[] = {
                "input_latching", "high_resolution", "widescreen", "full_height",
                "hud_relocation", "extended_aim", "high_framerate",
            };
            for (auto&& [key, value] : *enh_tbl) {
                std::string_view k = key.str();
                bool is_known = false;
                for (std::string_view known : known_enhancement_keys) {
                    if (k == known) {
                        is_known = true;
                        break;
                    }
                }
                if (!is_known) {
                    unknown.emplace_back(std::string("enhancements.") + std::string(k));
                }
            }
            if (auto v = (*enh_tbl)["input_latching"].value<bool>()) {
                cfg.enhancements.input_latching = *v;
            }
            if (auto v = (*enh_tbl)["high_resolution"].value<bool>()) {
                cfg.enhancements.high_resolution = *v;
            }
            if (auto v = (*enh_tbl)["widescreen"].value<bool>()) {
                cfg.enhancements.widescreen = *v;
            }
            if (auto v = (*enh_tbl)["full_height"].value<bool>()) {
                cfg.enhancements.full_height = *v;
            }
            if (auto v = (*enh_tbl)["hud_relocation"].value<bool>()) {
                cfg.enhancements.hud_relocation = *v;
            }
            if (auto v = (*enh_tbl)["extended_aim"].value<bool>()) {
                cfg.enhancements.extended_aim = *v;
            }
            if (auto v = (*enh_tbl)["high_framerate"].value<bool>()) {
                cfg.enhancements.high_framerate = *v;
            }
        }

        if (const toml::table* tuning_tbl = tbl["tuning"].as_table()) {
            for (auto&& [key, value] : *tuning_tbl) {
                if (key.str() != "rcp_frame_ms") {
                    unknown.emplace_back(std::string("tuning.") + std::string(key.str()));
                }
            }
            // Accept either an integer or float TOML value (`rcp_frame_ms = 0`
            // is an easy typo for `0.0` and there's no reason to reject it).
            if (auto v = (*tuning_tbl)["rcp_frame_ms"].value<double>()) {
                cfg.tuning.rcp_frame_ms = *v;
            }
        }

        // [input] is read regardless of profile.active, like [tuning] above
        // and unlike [enhancements] -- see InputTuning in config.h.
        if (const toml::table* input_tbl = tbl["input"].as_table()) {
            for (auto&& [key, value] : *input_tbl) {
                std::string_view k = key.str();
                if (k != "stick_deadzone" && k != "stick_curve" && k != "stick_sensitivity" &&
                    k != "mouse_aim" && k != "mouse_sensitivity" && k != "mouse_mode" &&
                    k != "mouse_invert_y" && k != "pad_start_port" && k != "ports") {
                    unknown.emplace_back(std::string("input.") + std::string(k));
                }
            }
            // A non-numeric value is left at its InputTuning default, same as
            // rcp_frame_ms above; an in-range numeric value is used as-is,
            // an out-of-range one is clamped with a single warning.
            if (auto v = (*input_tbl)["stick_deadzone"].value<double>()) {
                cfg.input.stick_deadzone = clamp_input_value("stick_deadzone", *v, 0.0, 0.9);
            }
            if (auto v = (*input_tbl)["stick_curve"].value<double>()) {
                cfg.input.stick_curve = clamp_input_value("stick_curve", *v, 0.25, 4.0);
            }
            if (auto v = (*input_tbl)["stick_sensitivity"].value<double>()) {
                cfg.input.stick_sensitivity = clamp_input_value("stick_sensitivity", *v, 0.1, 3.0);
            }
            // A non-bool value is left at its InputTuning default silently,
            // same treatment as profile-name typos elsewhere in this file.
            if (auto v = (*input_tbl)["mouse_aim"].value<bool>()) {
                cfg.input.mouse_aim = *v;
            }
            if (auto v = (*input_tbl)["mouse_sensitivity"].value<double>()) {
                cfg.input.mouse_sensitivity = clamp_input_value("mouse_sensitivity", *v, 0.05, 20.0);
            }
            // An unrecognized mode name warns and leaves the default, the same
            // shape as profile.active's typo handling above (a mistyped mode
            // shouldn't silently change how aiming feels).
            if (auto mode = (*input_tbl).get("mouse_mode")) {
                if (auto s = mode->value<std::string>()) {
                    MouseMode m;
                    if (parse_mouse_mode_name(*s, m)) {
                        cfg.input.mouse_mode = m;
                    } else {
                        warn("input.mouse_mode = \"" + *s + "\" is not one of "
                             "positional|velocity; using positional");
                    }
                } else {
                    warn("input.mouse_mode is not a string; using positional");
                }
            }
            if (auto v = (*input_tbl)["mouse_invert_y"].value<bool>()) {
                cfg.input.mouse_invert_y = *v;
            }
            // Multiplayer port assignment (see InputTuning in config.h). Read
            // as integers -- a float or a string is left at the default, same
            // as every other type mismatch in this file -- and clamped with
            // the same single warning the stick knobs get.
            if (auto v = (*input_tbl)["pad_start_port"].value<int64_t>()) {
                cfg.input.pad_start_port = clamp_input_int("pad_start_port", *v, 0, 3);
            }
            if (auto v = (*input_tbl)["ports"].value<int64_t>()) {
                cfg.input.ports = clamp_input_int("ports", *v, 0, 4);
            }
        }

        return cfg;
    }

    void write_default_file(const std::filesystem::path& path) {
        std::error_code ec;
        if (path.has_parent_path()) {
            std::filesystem::create_directories(path.parent_path(), ec);
        }
        std::ofstream out(path, std::ios::binary);
        if (!out) {
            warn("could not create default config file at " + path.string());
            return;
        }
        out << default_file_contents;
    }
}

kerecomp::Config kerecomp::load_config(int argc, char** argv, const std::filesystem::path& app_folder) {
    CliArgs cli = parse_cli_args(argc, argv);

    std::filesystem::path config_path = cli.config_path.empty()
        ? (app_folder / "config.toml")
        : cli.config_path;

    Config cfg{}; // built-in defaults (enhanced profile); every early-return below leaves this in effect.

    if (!std::filesystem::exists(config_path)) {
        write_default_file(config_path);
    } else {
        try {
            toml::table tbl = toml::parse_file(config_path.string());
            std::vector<std::string> unknown;
            cfg = config_from_table(tbl, unknown);
            if (!unknown.empty()) {
                std::string joined;
                for (size_t i = 0; i < unknown.size(); i++) {
                    if (i != 0) {
                        joined += ", ";
                    }
                    joined += unknown[i];
                }
                warn("unknown key(s) in " + config_path.string() + ": " + joined + " (ignored)");
            }
        } catch (const toml::parse_error& err) {
            warn("failed to parse " + config_path.string() + ": " +
                 std::string(err.description()) + " -- using built-in defaults (enhanced)");
            cfg = Config{};
        }
    }

    if (!cli.profile.empty()) {
        Profile p;
        if (parse_profile_name(cli.profile, p)) {
            cfg.profile = p;
        } else {
            warn("--profile '" + cli.profile + "' is not one of vanilla|enhanced|custom; ignoring");
        }
    }

    return cfg;
}

kerecomp::EnhancementFlags kerecomp::effective_enhancements(const Config& cfg) {
    switch (cfg.profile) {
        case Profile::Vanilla:
            return EnhancementFlags{};
        case Profile::Enhanced: {
            EnhancementFlags flags{};
            flags.input_latching = true;
            flags.high_resolution = true;
            flags.widescreen = true;
            flags.full_height = true;
            // hud_relocation only does anything alongside the two flags above
            // (widescreen creates the horizontal gap, full_height the
            // vertical one), so it belongs with them rather than on its own.
            flags.hud_relocation = true;
            // extended_aim likewise only does anything alongside those: its
            // horizontal half rides on widescreen + hud_relocation and its
            // vertical half on full_height (see the flag's comment in
            // config.h). Curated pending the owner's hands-on check, the same
            // way hud_relocation was.
            flags.extended_aim = true;
            // high_framerate is deliberately NOT in the curated set (owner
            // decision 2026-07-31 after hands-on): it works -- frame rate is
            // visibly higher and most of the scene interpolates cleanly --
            // but RT64's heuristic transform matching produces visible
            // artifacts on some effects (lock-on effect, bullet trails), so
            // it stays an experimental opt-in via the custom profile until
            // per-effect tagging addresses those (high-framerate.md section 4).
            return flags;
        }
        case Profile::Custom:
            return cfg.enhancements;
    }
    return EnhancementFlags{};
}

std::string kerecomp::describe_config(const Config& cfg) {
    EnhancementFlags effective = effective_enhancements(cfg);
    std::vector<std::string> parts;

    if (effective.input_latching) {
        parts.emplace_back("input_latching=on");
    }
    if (effective.high_resolution) {
        parts.emplace_back("high_resolution=on");
    }
    if (effective.widescreen) {
        parts.emplace_back("widescreen=on");
    }
    if (effective.full_height) {
        parts.emplace_back("full_height=on");
    }
    if (effective.hud_relocation) {
        parts.emplace_back("hud_relocation=on");
    }
    if (effective.extended_aim) {
        parts.emplace_back("extended_aim=on");
    }
    if (effective.high_framerate) {
        parts.emplace_back("high_framerate=on");
    }
    if (cfg.tuning.rcp_frame_ms > 0.0) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "rcp_frame_ms=%.1f", cfg.tuning.rcp_frame_ms);
        parts.emplace_back(buf);
    }

    // [input] applies regardless of profile, so these are checked against
    // InputTuning's own defaults rather than folded into `effective` above.
    constexpr InputTuning default_input{};
    if (cfg.input.stick_deadzone != default_input.stick_deadzone) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "stick_deadzone=%.2f", cfg.input.stick_deadzone);
        parts.emplace_back(buf);
    }
    if (cfg.input.stick_curve != default_input.stick_curve) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "stick_curve=%.2f", cfg.input.stick_curve);
        parts.emplace_back(buf);
    }
    if (cfg.input.stick_sensitivity != default_input.stick_sensitivity) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "stick_sensitivity=%.2f", cfg.input.stick_sensitivity);
        parts.emplace_back(buf);
    }
    if (!cfg.input.mouse_aim) {
        parts.emplace_back("mouse_aim=off");
    }
    if (cfg.input.mouse_sensitivity != default_input.mouse_sensitivity) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "mouse_sensitivity=%.2f", cfg.input.mouse_sensitivity);
        parts.emplace_back(buf);
    }
    if (cfg.input.mouse_mode != default_input.mouse_mode) {
        parts.emplace_back("mouse_mode=velocity");
    }
    if (cfg.input.mouse_invert_y) {
        parts.emplace_back("mouse_invert_y=on");
    }
    if (cfg.input.pad_start_port != default_input.pad_start_port) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "pad_start_port=%d", cfg.input.pad_start_port);
        parts.emplace_back(buf);
    }
    if (cfg.input.ports != default_input.ports) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "ports=%d", cfg.input.ports);
        parts.emplace_back(buf);
    }

    std::string line = std::string("profile: ") + profile_name(cfg.profile);
    if (!parts.empty()) {
        line += " (";
        for (size_t i = 0; i < parts.size(); i++) {
            if (i != 0) {
                line += ", ";
            }
            line += parts[i];
        }
        line += ")";
    }
    return line;
}
