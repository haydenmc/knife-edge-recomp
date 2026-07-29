#include <algorithm>
#include <atomic>
#include <cassert>
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

    app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
}

void kerecomp::renderer::RT64Context::update_screen() {
    app->updateScreen();
}

void kerecomp::renderer::RT64Context::shutdown() {
    if (app != nullptr) {
        app->end();
    }

    // End the process here rather than returning and letting recomp::start()
    // finish its teardown.
    //
    // ultramodern::quit() only sets `exited`; it does not stop the threads the
    // game created with osCreateThread. Those keep running recompiled code
    // throughout the whole shutdown, and recomp::start() ends with
    // `munmap(rdram, allocation_size)` (deps/N64ModernRuntime/librecomp/src/
    // recomp.cpp, end of recomp::start) -- so RDRAM is unmapped while its
    // users are still live. It is not a narrow race either: every one of this
    // game's busy-wait loops is hooked with yield_self_1ms() (config/
    // knife_edge.us.toml [[patches.hook]] entries; see the spin-yield section
    // of analysis/gen_syms.py), and that waits on the external message queue
    // with a 1 ms *timeout*, so a parked game thread re-enters
    // ultramodern::check_running_queue() -- which dereferences RDRAM to read
    // OSThread::priority -- within 1 ms of any moment, forever. The result is
    // a reliable SIGSEGV in "Game Thread 3" a millisecond after the unmap.
    //
    // This function is the last moment at which the process is still coherent:
    // the renderer is fully torn down, and everything recomp::start() does
    // afterwards (joining the remaining runtime threads, freeing RDRAM) is
    // bookkeeping the OS does for free at process exit. There is no seam
    // further along -- the unsafe steps are inside librecomp, between the
    // point the gfx thread returns and the point main() regains control.
    //
    // Safe for this game specifically because it has no save file
    // (GameEntry::save_type is SaveType::None in main.cpp), so librecomp's
    // saving thread owns nothing that still needs flushing.
    kerecomp::exit_after_renderer_shutdown();
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
