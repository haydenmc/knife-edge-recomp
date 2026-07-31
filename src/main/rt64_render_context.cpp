#include <algorithm>
#include <atomic>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "hle/rt64_application.h"

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"

#include "rt64_render_context.h"
#include "support.h"

namespace {
    // RT64's Application::Core wants raw pointers to RDP/VI register storage
    // and scratch DMEM/IMEM. Knife Edge doesn't drive real RDP interrupts
    // (there's no CPU-side RDP emulation, RT64 owns display list processing
    // directly), so these just need to exist as backing storage.
    uint8_t DMEM[0x1000];
    uint8_t IMEM[0x1000];

    unsigned int MI_INTR_REG = 0;
    unsigned int DPC_START_REG = 0;
    unsigned int DPC_END_REG = 0;
    unsigned int DPC_CURRENT_REG = 0;
    unsigned int DPC_STATUS_REG = 0;
    unsigned int DPC_CLOCK_REG = 0;
    unsigned int DPC_BUFBUSY_REG = 0;
    unsigned int DPC_PIPEBUSY_REG = 0;
    unsigned int DPC_TMEM_REG = 0;

    void dummy_check_interrupts() {}

    RT64::UserConfiguration::AspectRatio to_rt64(ultramodern::renderer::AspectRatio option) {
        switch (option) {
            case ultramodern::renderer::AspectRatio::Original:
                return RT64::UserConfiguration::AspectRatio::Original;
            case ultramodern::renderer::AspectRatio::Expand:
                return RT64::UserConfiguration::AspectRatio::Expand;
            case ultramodern::renderer::AspectRatio::Manual:
                return RT64::UserConfiguration::AspectRatio::Manual;
            default:
                return RT64::UserConfiguration::AspectRatio::Original;
        }
    }

    RT64::UserConfiguration::Antialiasing to_rt64(ultramodern::renderer::Antialiasing option) {
        switch (option) {
            case ultramodern::renderer::Antialiasing::None:
                return RT64::UserConfiguration::Antialiasing::None;
            case ultramodern::renderer::Antialiasing::MSAA2X:
                return RT64::UserConfiguration::Antialiasing::MSAA2X;
            case ultramodern::renderer::Antialiasing::MSAA4X:
                return RT64::UserConfiguration::Antialiasing::MSAA4X;
            case ultramodern::renderer::Antialiasing::MSAA8X:
                return RT64::UserConfiguration::Antialiasing::MSAA8X;
            default:
                return RT64::UserConfiguration::Antialiasing::None;
        }
    }

    RT64::UserConfiguration::RefreshRate to_rt64(ultramodern::renderer::RefreshRate option) {
        switch (option) {
            case ultramodern::renderer::RefreshRate::Original:
                return RT64::UserConfiguration::RefreshRate::Original;
            case ultramodern::renderer::RefreshRate::Display:
                return RT64::UserConfiguration::RefreshRate::Display;
            case ultramodern::renderer::RefreshRate::Manual:
                return RT64::UserConfiguration::RefreshRate::Manual;
            default:
                return RT64::UserConfiguration::RefreshRate::Original;
        }
    }

    RT64::UserConfiguration::InternalColorFormat to_rt64(ultramodern::renderer::HighPrecisionFramebuffer option) {
        switch (option) {
            case ultramodern::renderer::HighPrecisionFramebuffer::Off:
                return RT64::UserConfiguration::InternalColorFormat::Standard;
            case ultramodern::renderer::HighPrecisionFramebuffer::On:
                return RT64::UserConfiguration::InternalColorFormat::High;
            case ultramodern::renderer::HighPrecisionFramebuffer::Auto:
                return RT64::UserConfiguration::InternalColorFormat::Automatic;
            default:
                return RT64::UserConfiguration::InternalColorFormat::Automatic;
        }
    }

    void set_application_user_config(RT64::Application* application, const ultramodern::renderer::GraphicsConfig& config) {
        switch (config.res_option) {
            default:
            case ultramodern::renderer::Resolution::Auto:
                application->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
                application->userConfig.downsampleMultiplier = 1;
                break;
            case ultramodern::renderer::Resolution::Original:
                application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
                application->userConfig.resolutionMultiplier = std::max(config.ds_option, 1);
                application->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
                break;
            case ultramodern::renderer::Resolution::Original2x:
                application->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
                application->userConfig.resolutionMultiplier = 2.0 * std::max(config.ds_option, 1);
                application->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
                break;
        }

        switch (config.hr_option) {
            default:
            case ultramodern::renderer::HUDRatioMode::Original:
                application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Original;
                break;
            case ultramodern::renderer::HUDRatioMode::Clamp16x9:
                application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Manual;
                application->userConfig.extAspectTarget = 16.0 / 9.0;
                break;
            case ultramodern::renderer::HUDRatioMode::Full:
                application->userConfig.extAspectRatio = RT64::UserConfiguration::AspectRatio::Expand;
                break;
        }

        application->userConfig.aspectRatio = to_rt64(config.ar_option);
        application->userConfig.antialiasing = to_rt64(config.msaa_option);
        application->userConfig.refreshRate = to_rt64(config.rr_option);
        application->userConfig.refreshRateTarget = config.rr_manual_value;
        application->userConfig.internalColorFormat = to_rt64(config.hpfb_option);
        application->userConfig.displayBuffering = RT64::UserConfiguration::DisplayBuffering::Triple;
    }

    ultramodern::renderer::SetupResult map_setup_result(RT64::Application::SetupResult rt64_result) {
        switch (rt64_result) {
            case RT64::Application::SetupResult::Success:
                return ultramodern::renderer::SetupResult::Success;
            case RT64::Application::SetupResult::DynamicLibrariesNotFound:
                return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
            case RT64::Application::SetupResult::InvalidGraphicsAPI:
                return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
            case RT64::Application::SetupResult::GraphicsAPINotFound:
                return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
            case RT64::Application::SetupResult::GraphicsDeviceNotFound:
                return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
        }

        std::fprintf(stderr, "Unhandled RT64::Application::SetupResult\n");
        std::abort();
    }

    ultramodern::renderer::GraphicsApi map_graphics_api(RT64::UserConfiguration::GraphicsAPI api) {
        switch (api) {
            case RT64::UserConfiguration::GraphicsAPI::D3D12:
                return ultramodern::renderer::GraphicsApi::D3D12;
            case RT64::UserConfiguration::GraphicsAPI::Vulkan:
                return ultramodern::renderer::GraphicsApi::Vulkan;
            case RT64::UserConfiguration::GraphicsAPI::Metal:
                return ultramodern::renderer::GraphicsApi::Metal;
            case RT64::UserConfiguration::GraphicsAPI::Automatic:
                return ultramodern::renderer::GraphicsApi::Auto;
        }

        std::fprintf(stderr, "Unhandled RT64::UserConfiguration::GraphicsAPI\n");
        std::abort();
    }
}

kerecomp::renderer::RT64Context::RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool debug) {
    static unsigned char dummy_rom_header[0x40];

    RT64::Application::Core appCore{};
#if defined(_WIN32)
    appCore.window = window_handle.window;
#elif defined(__linux__) || defined(__ANDROID__)
    appCore.window = window_handle;
#elif defined(__APPLE__)
    appCore.window.window = window_handle.window;
    appCore.window.view = window_handle.view;
#endif

    appCore.checkInterrupts = dummy_check_interrupts;

    appCore.HEADER = dummy_rom_header;
    appCore.RDRAM = rdram;
    appCore.DMEM = DMEM;
    appCore.IMEM = IMEM;

    appCore.MI_INTR_REG = &MI_INTR_REG;

    appCore.DPC_START_REG = &DPC_START_REG;
    appCore.DPC_END_REG = &DPC_END_REG;
    appCore.DPC_CURRENT_REG = &DPC_CURRENT_REG;
    appCore.DPC_STATUS_REG = &DPC_STATUS_REG;
    appCore.DPC_CLOCK_REG = &DPC_CLOCK_REG;
    appCore.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
    appCore.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
    appCore.DPC_TMEM_REG = &DPC_TMEM_REG;

    ultramodern::renderer::ViRegs* vi_regs = ultramodern::renderer::get_vi_regs();

    appCore.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
    appCore.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
    appCore.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
    appCore.VI_INTR_REG = &vi_regs->VI_INTR_REG;
    appCore.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
    appCore.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
    appCore.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
    appCore.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
    appCore.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
    appCore.VI_H_START_REG = &vi_regs->VI_H_START_REG;
    appCore.VI_V_START_REG = &vi_regs->VI_V_START_REG;
    appCore.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
    appCore.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
    appCore.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;

    RT64::ApplicationConfiguration appConfig;
    appConfig.useConfigurationFile = false;

    app = std::make_unique<RT64::Application>(appCore, appConfig);

    auto& cur_config = ultramodern::renderer::get_graphics_config();
    set_application_user_config(app.get(), cur_config);
    app->userConfig.developerMode = debug;
    // Force gbi depth branches to prevent LODs from kicking in.
    app->enhancementConfig.f3dex.forceBranch = true;
    // Scale LODs based on the output resolution.
    app->enhancementConfig.textureLOD.scale = true;

    switch (cur_config.api_option) {
        case ultramodern::renderer::GraphicsApi::D3D12:
            app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::D3D12;
            break;
        case ultramodern::renderer::GraphicsApi::Vulkan:
            app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Vulkan;
            break;
        case ultramodern::renderer::GraphicsApi::Metal:
            app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Metal;
            break;
        case ultramodern::renderer::GraphicsApi::Auto:
            app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic;
            break;
    }

    uint32_t thread_id = 0;
#ifdef _WIN32
    thread_id = window_handle.thread_id;
#endif
    setup_result = map_setup_result(app->setup(thread_id));
    chosen_api = map_graphics_api(app->chosenGraphicsAPI);
    if (setup_result != ultramodern::renderer::SetupResult::Success) {
        app = nullptr;
        return;
    }

    app->setFullScreen(cur_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
}

kerecomp::renderer::RT64Context::~RT64Context() = default;

void kerecomp::renderer::RT64Context::send_dl(const OSTask* task) {
    kerecomp::perf_count_dl();
    app->state->rsp->reset();

    const uint32_t ucode_text = task->t.ucode & 0x3FFFFFF;
    const uint32_t ucode_data = task->t.ucode_data & 0x3FFFFFF;
    app->interpreter->loadUCodeGBI(ucode_text, ucode_data, true);

    // Guard against a display list built from an unidentifiable microcode.
    // This became reachable once the overlay tail-survival fix
    // (analysis/docs/timing-and-mission-debug.md §4.2) started letting a
    // surviving stale-tail function run to completion instead of aborting at
    // get_function(): if it submits a graphics task whose ucode bytes don't
    // hash-match anything in RT64's GBI database, loadUCodeGBI() above leaves
    // Interpreter::hleGBI null (RT64::GBIManager::getGBIForUCode() in
    // deps/rt64/src/gbi/rt64_gbi.cpp), and
    // Interpreter::processDisplayLists() in
    // deps/rt64/src/hle/rt64_interpreter.cpp only guards that with
    // `assert(hleGBI != nullptr)`, which is compiled out in this release
    // (NDEBUG) build -- so it falls through to a null-pointer dereference.
    //
    // `Interpreter::hleGBI` and `Application::interpreter` are both public
    // members, so this checks the exact same state RT64 would have crashed
    // on, from our side, without patching deps/rt64: skip this one display
    // list (dp_complete() still fires because send_dl still returns
    // normally -- see analysis/docs/timing-and-mission-debug.md §1.2) and log
    // once, not per frame, since a stuck-in-this-state game would otherwise
    // flood stderr at 15+ Hz.
    if (app->interpreter->hleGBI == nullptr) {
        static std::atomic<bool> warned{false};
        if (!warned.exchange(true)) {
            std::fprintf(stderr,
                "[rt64] unable to identify microcode (ucode 0x%08X, data 0x%08X); "
                "dropping this display list instead of crashing "
                "(see analysis/docs/timing-and-mission-debug.md §4.2)\n",
                ucode_text, ucode_data);
        }
        return;
    }

    uint32_t dl_addr = task->t.data_ptr & 0x3FFFFFF;
    uint32_t entry = maybe_inject_rate_prologue(dl_addr);
    app->processDisplayLists(app->core.RDRAM, entry, 0, true);
}

// high_framerate enhancement (analysis/docs/high-framerate.md). RT64's frame
// interpolation only engages once it knows the game's original logic rate;
// its own VI-cadence auto-detection can't derive one for this game (a
// continuous ~27 fps that straddles 2-3 VIs per frame, never a consistent
// 60/N), so we declare it per display list via RT64's extended-GBI
// gEXSetRefreshRate instead. Returns game_dl_addr unchanged (untouched, no
// scratch RDRAM write at all) unless every one of the gating conditions holds.
uint32_t kerecomp::renderer::RT64Context::maybe_inject_rate_prologue(uint32_t game_dl_addr) {
    const auto& cur_config = ultramodern::renderer::get_graphics_config();
    if (cur_config.rr_option == ultramodern::renderer::RefreshRate::Original) {
        return game_dl_addr;
    }

    double interval_ms = kerecomp::measured_game_frame_interval_ms();
    if (interval_ms <= 0.0) {
        // No measurement yet (e.g. the very first display list of the run).
        return game_dl_addr;
    }

    // Scratch RDRAM: physical 0x7FF000 (vaddr 0x807FF000). Inside librecomp's
    // 8 MiB RDRAM allocation but in the upper 4 MiB, which this base-4-MiB-
    // machine game never touches (analysis/out/segment_map.md: highest write
    // ever seen is 0x80287C20). One-time check, strictly before our first
    // write ever happens (afterwards the words are nonzero by our own hand,
    // so the check could never run again anyway): if any of the 8 words we're
    // about to use are already nonzero, something else claimed this region,
    // and we fail safe -- disable the injection permanently rather than risk
    // corrupting whatever that is.
    static const bool scratch_usable = [this]() {
        uint32_t* p = reinterpret_cast<uint32_t*>(app->core.RDRAM + 0x7FF000);
        for (int i = 0; i < 8; i++) {
            if (p[i] != 0) {
                std::fprintf(stderr,
                    "[hfr] scratch RDRAM at 0x807FF000 unexpectedly in use; "
                    "high framerate interpolation disabled\n");
                return false;
            }
        }
        return true;
    }();
    if (!scratch_usable) {
        return game_dl_addr;
    }

    int rate = std::clamp(static_cast<int>(std::lround(1000.0 / interval_ms)), 10, 60);

    static int last_logged_rate = -1;
    if (rate != last_logged_rate) {
        last_logged_rate = rate;
        std::fprintf(stderr, "[hfr] declaring game logic rate %d Hz to RT64 (display target %u Hz)\n",
                     rate, get_display_framerate());
    }

    // RT64 extended-GBI hook commands (deps/rt64/include/rt64_extended_gbi.h,
    // handler: noOpHook in deps/rt64/src/gbi/rt64_gbi_extended.cpp). The game
    // runs F3DEX2, whose G_SPNOOP opcode is 0xE0 = RT64_HOOK_OPCODE; magic
    // 0x525464 ("RT",0x64) marks the NOOP as an RT64 hook. Sequence:
    //   ENABLE(ext opcode 0x64) -> gEXSetRefreshRate(rate) -> DISABLE ->
    //   BRANCH(game DL)
    // DISABLE before the branch means the game's own display list never runs
    // with the extended opcode registered, so 0x64 cannot collide with any
    // game command byte.
    //
    // Direct u32 stores, no byte-swapping: RT64's DisplayList struct reads
    // {w0, w1} as native u32s from this same buffer, and 4-byte-aligned u32
    // stores are exactly what the recompiled game's own SW instructions
    // produce.
    uint32_t* p = reinterpret_cast<uint32_t*>(app->core.RDRAM + 0x7FF000);
    p[0] = 0xE0525464u; p[1] = 0x10000064u;                       // HOOK_OP_ENABLE, extended opcode 0x64
    p[2] = 0x64000009u; p[3] = static_cast<uint32_t>(rate) & 0xFFFFu; // G_EX_SETREFRESHRATE_V1
    p[4] = 0xE0525464u; p[5] = 0x20000000u;                       // HOOK_OP_DISABLE
    p[6] = 0xE0525464u; p[7] = 0x40000000u | (game_dl_addr & 0x0FFFFFFFu); // HOOK_OP_BRANCH -> game DL

    return 0x7FF000;
}

void kerecomp::renderer::RT64Context::update_screen() {
    app->updateScreen();
}

void kerecomp::renderer::RT64Context::shutdown() {
    if (app != nullptr) {
        app->end();
    }

    // Returns normally. recomp::start() stops and joins the game's own threads
    // straight after this (ultramodern::terminate_game_threads(), added by
    // patches/n64modernruntime-orderly-shutdown.patch) and only then frees
    // RDRAM, so there is no longer anything unsafe about letting its teardown
    // run to completion -- see analysis/docs/build-notes.md.
}

bool kerecomp::renderer::RT64Context::update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) {
    if (old_config == new_config) {
        return false;
    }

    if (new_config.wm_option != old_config.wm_option) {
        app->setFullScreen(new_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
    }

    set_application_user_config(app.get(), new_config);
    app->updateUserConfig(true);

    if (new_config.msaa_option != old_config.msaa_option) {
        app->updateMultisampling();
    }
    return true;
}

void kerecomp::renderer::RT64Context::enable_instant_present() {
    app->enhancementConfig.presentation.mode = RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
    app->updateEnhancementConfig();
}

uint32_t kerecomp::renderer::RT64Context::get_display_framerate() const {
    return app->presentQueue->ext.sharedResources->swapChainRate;
}

float kerecomp::renderer::RT64Context::get_resolution_scale() const {
    constexpr int ReferenceHeight = 240;
    switch (app->userConfig.resolution) {
        case RT64::UserConfiguration::Resolution::WindowIntegerScale:
            if (app->sharedQueueResources->swapChainHeight > 0) {
                return std::max(float((app->sharedQueueResources->swapChainHeight + ReferenceHeight - 1) / ReferenceHeight), 1.0f);
            }
            return 1.0f;
        case RT64::UserConfiguration::Resolution::Manual:
            return float(app->userConfig.resolutionMultiplier);
        case RT64::UserConfiguration::Resolution::Original:
        default:
            return 1.0f;
    }
}

std::unique_ptr<ultramodern::renderer::RendererContext> kerecomp::renderer::create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<kerecomp::renderer::RT64Context>(rdram, window_handle, developer_mode);
}
