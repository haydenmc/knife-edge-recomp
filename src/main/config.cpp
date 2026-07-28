#include "config.h"

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
    using kerecomp::Profile;
    using kerecomp::TuningFlags;

    void warn(const std::string& message) {
        std::fprintf(stderr, "[config] warning: %s\n", message.c_str());
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
        "# \"vanilla\" (default): every enhancement OFF -- the regression baseline,\n"
        "#   faithful to original hardware behavior.\n"
        "# \"enhanced\": a curated set of opt-in quality-of-life changes.\n"
        "# \"custom\": read [enhancements] below individually.\n"
        "active = \"vanilla\"\n"
        "\n"
        "[enhancements]\n"
        "# Only consulted when profile.active = \"custom\".\n"
        "input_latching = false\n"
        "\n"
        "[tuning]\n"
        "# Fidelity knobs, NOT enhancements -- see src/main/rcp_timing.cpp.\n"
        "# 0 = built-in model (59.733 ms/frame). The KE_RCP_FRAME_MS environment\n"
        "# variable still overrides this when set.\n"
        "rcp_frame_ms = 0.0\n";

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
            if (k != "profile" && k != "enhancements" && k != "tuning") {
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
                             "vanilla|enhanced|custom; using vanilla");
                    }
                } else {
                    warn("profile.active is not a string; using vanilla");
                }
            }
        }

        if (const toml::table* enh_tbl = tbl["enhancements"].as_table()) {
            for (auto&& [key, value] : *enh_tbl) {
                if (key.str() != "input_latching") {
                    unknown.emplace_back(std::string("enhancements.") + std::string(key.str()));
                }
            }
            if (auto v = (*enh_tbl)["input_latching"].value<bool>()) {
                cfg.enhancements.input_latching = *v;
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

    Config cfg{}; // vanilla defaults; every early-return below leaves this in effect.

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
                 std::string(err.description()) + " -- using vanilla defaults");
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
    if (cfg.tuning.rcp_frame_ms > 0.0) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "rcp_frame_ms=%.1f", cfg.tuning.rcp_frame_ms);
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
