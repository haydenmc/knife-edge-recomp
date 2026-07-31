#include <algorithm>
#include <atomic>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <cstring>
#include <string>

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

    // ------------------------------------------------------------------
    // KE_DL_DUMP -- display list dumper (diagnostic; see
    // analysis/docs/hud-relocation.md)
    //
    // When KE_DL_DUMP is set to a path, every display list the game submits
    // is walked and appended there as compact text, one line per interesting
    // command. Read-only: it never writes RDRAM and never changes what is
    // handed to RT64. When the variable is unset the whole thing costs one
    // cached pointer test per frame.
    //
    // Two companion knobs, because a mission display list is ~2200 commands
    // (~150 KB of text) per frame at ~27 fps -- dumping from boot would blow
    // any cap long before scripted input reaches gameplay:
    //   KE_DL_DUMP_AFTER_S=<sec>   start dumping this long after the first
    //                              display list (default 0 = immediately)
    //   KE_DL_DUMP_FRAMES=<n>      stop after n dumped frames (default 0 =
    //                              unlimited, subject to the byte cap)
    //
    // Decoding follows deps/rt64/src/gbi/rt64_gbi_f3dex2.cpp and
    // rt64_gbi_rdp.cpp exactly (F3DEX2 opcode numbering, RDP command
    // numbering, texrect's two continuation words, moveword's segment
    // writes), so what is logged is what RT64 itself acts on.
    // ------------------------------------------------------------------

    constexpr uint32_t DL_RDRAM_SIZE = 8u * 1024u * 1024u;
    constexpr int DL_DUMP_MAX_DEPTH = 8;
    constexpr int DL_DUMP_MAX_CMDS = 16384;
    constexpr size_t DL_DUMP_MAX_BYTES = 40u * 1024u * 1024u;

    // F3DEX2 opcodes (deps/rt64/src/gbi/rt64_gbi_f3dex2.h).
    enum : uint8_t {
        DL_G_VTX = 0x01, DL_G_MODIFYVTX = 0x02, DL_G_CULLDL = 0x03,
        DL_G_BRANCH_Z = 0x04, DL_G_TRI1 = 0x05, DL_G_TRI2 = 0x06,
        DL_G_QUAD = 0x07,
        DL_G_TEXTURE = 0xD7, DL_G_POPMTX = 0xD8, DL_G_GEOMETRYMODE = 0xD9,
        DL_G_MTX = 0xDA, DL_G_MOVEWORD = 0xDB, DL_G_MOVEMEM = 0xDC,
        DL_G_LOAD_UCODE = 0xDD, DL_G_DL = 0xDE, DL_G_ENDDL = 0xDF,
        DL_G_SPNOOP = 0xE0, DL_G_RDPHALF_1 = 0xE1,
        DL_G_SETOTHERMODE_L = 0xE2, DL_G_SETOTHERMODE_H = 0xE3,
        DL_G_RDPHALF_2 = 0xF1,
        // RDP (deps/rt64/src/shared/rt64_f3d_defines.h).
        DL_G_TEXRECT = 0xE4, DL_G_TEXRECTFLIP = 0xE5,
        DL_G_RDPLOADSYNC = 0xE6, DL_G_RDPPIPESYNC = 0xE7,
        DL_G_RDPTILESYNC = 0xE8, DL_G_RDPFULLSYNC = 0xE9,
        DL_G_SETKEYGB = 0xEA, DL_G_SETKEYR = 0xEB, DL_G_SETCONVERT = 0xEC,
        DL_G_SETSCISSOR = 0xED, DL_G_SETPRIMDEPTH = 0xEE,
        DL_G_RDPSETOTHERMODE = 0xEF, DL_G_LOADTLUT = 0xF0,
        DL_G_SETTILESIZE = 0xF2, DL_G_LOADBLOCK = 0xF3, DL_G_LOADTILE = 0xF4,
        DL_G_SETTILE = 0xF5, DL_G_FILLRECT = 0xF6, DL_G_SETFILLCOLOR = 0xF7,
        DL_G_SETFOGCOLOR = 0xF8, DL_G_SETBLENDCOLOR = 0xF9,
        DL_G_SETPRIMCOLOR = 0xFA, DL_G_SETENVCOLOR = 0xFB,
        DL_G_SETCOMBINE = 0xFC, DL_G_SETTIMG = 0xFD, DL_G_SETZIMG = 0xFE,
        DL_G_SETCIMG = 0xFF,
    };

    inline uint32_t dl_bits(uint32_t w, uint8_t pos, uint8_t bits) {
        return (w >> pos) & ((bits == 32) ? 0xFFFFFFFFu : ((1u << bits) - 1u));
    }

    struct DLDumpState {
        std::FILE* file = nullptr;
        size_t written = 0;
        bool capped = false;
        uint64_t frame = 0;
        uint64_t seen = 0;
        uint64_t max_frames = 0;
        double after_s = 0.0;
        std::chrono::steady_clock::time_point start{};
        bool started = false;
        uint32_t segments[16]{};
        std::string out;
        char line[256]{};

        void emit() {
            out.append(line);
            out.push_back('\n');
        }

        // RT64: RSP::fromSegmented() + the 0x00FFFFF8 DMA mask
        // (deps/rt64/src/hle/rt64_rsp.cpp).
        uint32_t resolve(uint32_t seg_addr) const {
            uint32_t phys = segments[(seg_addr >> 24) & 0x0F] + (seg_addr & 0x00FFFFFF);
            return phys & 0x00FFFFF8u;
        }
    };

    bool dl_read(const uint8_t* rdram, uint32_t addr, uint32_t& w0, uint32_t& w1) {
        if (addr + 8u > DL_RDRAM_SIZE) {
            return false;
        }
        // Same convention RT64 uses: RT64::DisplayList is two native u32s read
        // straight out of the RDRAM block (deps/rt64/src/gbi/rt64_display_list.h).
        std::memcpy(&w0, rdram + addr, 4);
        std::memcpy(&w1, rdram + addr + 4, 4);
        return true;
    }

    void dl_dump_walk(DLDumpState& st, const uint8_t* rdram, uint32_t entry) {
        uint32_t ret_stack[DL_DUMP_MAX_DEPTH];
        int depth = 0;
        uint32_t addr = entry & 0x00FFFFF8u;
        int index = 0;

        // Consecutive triangle commands are aggregated into one TRIxN line.
        int tri_run = 0;
        uint32_t tri_start_addr = 0;
        int tri_start_index = 0;
        auto flush_tris = [&]() {
            if (tri_run > 0) {
                std::snprintf(st.line, sizeof(st.line), "%llu %d @%06X TRIx%d",
                              (unsigned long long)st.frame, tri_start_index, tri_start_addr, tri_run);
                st.emit();
                tri_run = 0;
            }
        };

        while (index < DL_DUMP_MAX_CMDS) {
            uint32_t w0 = 0, w1 = 0;
            if (!dl_read(rdram, addr, w0, w1)) {
                flush_tris();
                std::snprintf(st.line, sizeof(st.line), "%llu %d @%06X BADADDR",
                              (unsigned long long)st.frame, index, addr);
                st.emit();
                return;
            }

            const uint8_t op = uint8_t(w0 >> 24);
            const uint32_t here = addr;
            const int here_index = index;
            addr += 8;
            index++;

            if (op == DL_G_TRI1 || op == DL_G_TRI2 || op == DL_G_QUAD) {
                if (tri_run == 0) {
                    tri_start_addr = here;
                    tri_start_index = here_index;
                }
                tri_run += (op == DL_G_TRI1) ? 1 : 2;
                continue;
            }
            flush_tris();

            char* p = st.line;
            const size_t n = sizeof(st.line);
            int used = std::snprintf(p, n, "%llu %d @%06X ",
                                     (unsigned long long)st.frame, here_index, here);
            char* q = p + used;
            size_t qn = (used < int(n)) ? n - used : 0;
            bool print = true;

            switch (op) {
            case DL_G_TEXRECT:
            case DL_G_TEXRECTFLIP: {
                // rt64_gbi_rdp.cpp::texrect(): coords 10.2 fixed point, and the
                // two following Gfx words (G_RDPHALF_1 / G_RDPHALF_2) carry
                // s/t and dsdx/dtdy in their w1.
                const uint32_t lrx = dl_bits(w0, 12, 12), lry = dl_bits(w0, 0, 12);
                const uint32_t ulx = dl_bits(w1, 12, 12), uly = dl_bits(w1, 0, 12);
                const uint32_t tile = dl_bits(w1, 24, 3);
                uint32_t h0w0 = 0, h0w1 = 0, h1w0 = 0, h1w1 = 0;
                dl_read(rdram, addr, h0w0, h0w1);
                dl_read(rdram, addr + 8, h1w0, h1w1);
                const int16_t uls = int16_t(h0w1 >> 16), ult = int16_t(h0w1 & 0xFFFF);
                const int16_t dsdx = int16_t(h1w1 >> 16), dtdy = int16_t(h1w1 & 0xFFFF);
                std::snprintf(q, qn,
                    "%s ul=%.2f,%.2f lr=%.2f,%.2f w=%.2f h=%.2f tile=%u st=%d,%d d=%d,%d",
                    (op == DL_G_TEXRECT) ? "TEXRECT" : "TEXRECTFLIP",
                    ulx / 4.0, uly / 4.0, lrx / 4.0, lry / 4.0,
                    (lrx - ulx) / 4.0, (lry - uly) / 4.0,
                    tile, int(uls), int(ult), int(dsdx), int(dtdy));
                addr += 16;   // skip the two continuation words
                index += 2;
                break;
            }
            case DL_G_FILLRECT: {
                const uint32_t lrx = dl_bits(w0, 12, 12), lry = dl_bits(w0, 0, 12);
                const uint32_t ulx = dl_bits(w1, 12, 12), uly = dl_bits(w1, 0, 12);
                std::snprintf(q, qn, "FILLRECT ul=%.2f,%.2f lr=%.2f,%.2f",
                              ulx / 4.0, uly / 4.0, lrx / 4.0, lry / 4.0);
                break;
            }
            case DL_G_SETTIMG:
                std::snprintf(q, qn, "SETTIMG fmt=%u siz=%u w=%u addr=%08X phys=%06X",
                              dl_bits(w0, 21, 3), dl_bits(w0, 19, 2), dl_bits(w0, 0, 12) + 1,
                              w1, st.resolve(w1));
                break;
            case DL_G_SETCIMG:
                std::snprintf(q, qn, "SETCIMG fmt=%u siz=%u w=%u addr=%08X",
                              dl_bits(w0, 21, 3), dl_bits(w0, 19, 2), dl_bits(w0, 0, 12) + 1, w1);
                break;
            case DL_G_SETZIMG:
                std::snprintf(q, qn, "SETZIMG addr=%08X", w1);
                break;
            case DL_G_SETTILE:
                std::snprintf(q, qn, "SETTILE tile=%u fmt=%u siz=%u line=%u tmem=%u pal=%u",
                              dl_bits(w1, 24, 3), dl_bits(w0, 21, 3), dl_bits(w0, 19, 2),
                              dl_bits(w0, 9, 9), dl_bits(w0, 0, 9), dl_bits(w1, 20, 4));
                break;
            case DL_G_SETTILESIZE:
                std::snprintf(q, qn, "SETTILESIZE tile=%u uls=%.2f ult=%.2f lrs=%.2f lrt=%.2f",
                              dl_bits(w1, 24, 3), dl_bits(w0, 12, 12) / 4.0, dl_bits(w0, 0, 12) / 4.0,
                              dl_bits(w1, 12, 12) / 4.0, dl_bits(w1, 0, 12) / 4.0);
                break;
            case DL_G_LOADBLOCK:
                std::snprintf(q, qn, "LOADBLOCK tile=%u uls=%u ult=%u lrs=%u dxt=%u",
                              dl_bits(w1, 24, 3), dl_bits(w0, 12, 12), dl_bits(w0, 0, 12),
                              dl_bits(w1, 12, 12), dl_bits(w1, 0, 12));
                break;
            case DL_G_LOADTILE:
                std::snprintf(q, qn, "LOADTILE tile=%u uls=%u ult=%u lrs=%u lrt=%u",
                              dl_bits(w1, 24, 3), dl_bits(w0, 12, 12), dl_bits(w0, 0, 12),
                              dl_bits(w1, 12, 12), dl_bits(w1, 0, 12));
                break;
            case DL_G_LOADTLUT:
                std::snprintf(q, qn, "LOADTLUT tile=%u count=%u",
                              dl_bits(w1, 24, 3), dl_bits(w1, 14, 10));
                break;
            case DL_G_SETSCISSOR:
                std::snprintf(q, qn, "SETSCISSOR mode=%u ul=%.2f,%.2f lr=%.2f,%.2f",
                              dl_bits(w1, 24, 2), dl_bits(w0, 12, 12) / 4.0, dl_bits(w0, 0, 12) / 4.0,
                              dl_bits(w1, 12, 12) / 4.0, dl_bits(w1, 0, 12) / 4.0);
                break;
            case DL_G_MOVEMEM: {
                const uint32_t idx = dl_bits(w0, 0, 8);
                std::snprintf(q, qn, "MOVEMEM idx=%u%s off=%u addr=%08X phys=%06X",
                              idx, (idx == 8) ? "(VIEWPORT)" : "", dl_bits(w0, 8, 8) * 8,
                              w1, st.resolve(w1));
                break;
            }
            case DL_G_MOVEWORD: {
                const uint32_t type = dl_bits(w0, 16, 8);
                if (type == 0x06) {   // G_MW_SEGMENT
                    const uint32_t seg = dl_bits(w0, 2, 4);
                    st.segments[seg] = w1;
                    std::snprintf(q, qn, "MOVEWORD SEGMENT seg=%u -> %08X", seg, w1);
                }
                else {
                    std::snprintf(q, qn, "MOVEWORD type=%02X off=%u val=%08X",
                                  type, dl_bits(w0, 0, 16), w1);
                }
                break;
            }
            case DL_G_MTX:
                std::snprintf(q, qn, "MTX params=%02X addr=%08X phys=%06X",
                              dl_bits(w0, 0, 8), w1, st.resolve(w1));
                break;
            case DL_G_POPMTX:
                std::snprintf(q, qn, "POPMTX %08X", w1);
                break;
            case DL_G_VTX:
                std::snprintf(q, qn, "VTX n=%u vbidx=%u addr=%08X phys=%06X",
                              dl_bits(w0, 12, 8), dl_bits(w0, 1, 7), w1, st.resolve(w1));
                break;
            case DL_G_TEXTURE:
                std::snprintf(q, qn, "TEXTURE tile=%u lvl=%u on=%u sc=%u tc=%u",
                              dl_bits(w0, 8, 3), dl_bits(w0, 11, 3), dl_bits(w0, 1, 7),
                              dl_bits(w1, 16, 16), dl_bits(w1, 0, 16));
                break;
            case DL_G_GEOMETRYMODE:
                std::snprintf(q, qn, "GEOMETRYMODE clr=%06X set=%08X", dl_bits(w0, 0, 24), w1);
                break;
            case DL_G_SETCOMBINE:
                std::snprintf(q, qn, "SETCOMBINE %08X %08X", w0, w1);
                break;
            case DL_G_SETOTHERMODE_H:
                std::snprintf(q, qn, "SETOTHERMODE_H %08X %08X", w0, w1);
                break;
            case DL_G_SETOTHERMODE_L:
                std::snprintf(q, qn, "SETOTHERMODE_L %08X %08X", w0, w1);
                break;
            case DL_G_RDPSETOTHERMODE:
                std::snprintf(q, qn, "RDPSETOTHERMODE %08X %08X", w0, w1);
                break;
            case DL_G_SETPRIMCOLOR:
                std::snprintf(q, qn, "SETPRIMCOLOR %08X", w1);
                break;
            case DL_G_SETENVCOLOR:
                std::snprintf(q, qn, "SETENVCOLOR %08X", w1);
                break;
            case DL_G_SETBLENDCOLOR:
                std::snprintf(q, qn, "SETBLENDCOLOR %08X", w1);
                break;
            case DL_G_SETFOGCOLOR:
                std::snprintf(q, qn, "SETFOGCOLOR %08X", w1);
                break;
            case DL_G_SETFILLCOLOR:
                std::snprintf(q, qn, "SETFILLCOLOR %08X", w1);
                break;
            case DL_G_SPNOOP:
                std::snprintf(q, qn, "SPNOOP %08X %08X", w0, w1);
                break;
            case DL_G_RDPHALF_1:
                std::snprintf(q, qn, "RDPHALF_1 %08X", w1);
                break;
            case DL_G_RDPHALF_2:
                std::snprintf(q, qn, "RDPHALF_2 %08X", w1);
                break;
            case DL_G_RDPFULLSYNC:
                std::snprintf(q, qn, "RDPFULLSYNC");
                break;
            case DL_G_RDPPIPESYNC:
            case DL_G_RDPLOADSYNC:
            case DL_G_RDPTILESYNC:
                print = false;   // pure noise, one per state change
                break;
            case DL_G_DL: {
                // rt64_gbi_f3dex2 maps G_DL to GBI_F3D::runDl: w0 bit 16 clear
                // == push (call), set == branch (no return address pushed).
                const bool branch = dl_bits(w0, 16, 1) != 0;
                const uint32_t target = st.resolve(w1);
                std::snprintf(q, qn, "DL %s addr=%08X phys=%06X",
                              branch ? "branch" : "push", w1, target);
                st.emit();
                print = false;
                if (!branch) {
                    if (depth < DL_DUMP_MAX_DEPTH) {
                        ret_stack[depth++] = addr;
                    }
                    else {
                        std::snprintf(st.line, sizeof(st.line), "%llu %d @%06X DEPTHCAP",
                                      (unsigned long long)st.frame, here_index, here);
                        st.emit();
                        return;
                    }
                }
                addr = target;
                break;
            }
            case DL_G_ENDDL:
                std::snprintf(q, qn, "ENDDL");
                st.emit();
                print = false;
                if (depth == 0) {
                    return;
                }
                addr = ret_stack[--depth];
                break;
            default:
                std::snprintf(q, qn, "OP_%02X %08X %08X", op, w0, w1);
                break;
            }

            if (print) {
                st.emit();
            }
        }

        flush_tris();
        std::snprintf(st.line, sizeof(st.line), "%llu %d CMDCAP",
                      (unsigned long long)st.frame, index);
        st.emit();
    }

    // Called once per submitted display list, with the game's own entry
    // address (before any high_framerate prologue injection).
    void dl_dump_maybe(const uint8_t* rdram, uint32_t entry) {
        static DLDumpState* st = []() -> DLDumpState* {
            const char* path = std::getenv("KE_DL_DUMP");
            if (path == nullptr || path[0] == '\0') {
                return nullptr;
            }
            std::FILE* f = std::fopen(path, "ab");
            if (f == nullptr) {
                std::fprintf(stderr, "[dldump] cannot open '%s' for append; dumping disabled\n", path);
                return nullptr;
            }
            auto* s = new DLDumpState();
            s->file = f;
            if (const char* after = std::getenv("KE_DL_DUMP_AFTER_S")) {
                s->after_s = std::atof(after);
            }
            if (const char* frames = std::getenv("KE_DL_DUMP_FRAMES")) {
                s->max_frames = std::strtoull(frames, nullptr, 10);
            }
            std::fprintf(stderr, "[dldump] writing display lists to '%s' (after %.1f s, max %llu frames)\n",
                         path, s->after_s, (unsigned long long)s->max_frames);
            return s;
        }();

        if (st == nullptr || st->capped) {
            return;
        }

        st->seen++;
        if (!st->started) {
            if (st->seen == 1) {
                st->start = std::chrono::steady_clock::now();
            }
            const double elapsed =
                std::chrono::duration<double>(std::chrono::steady_clock::now() - st->start).count();
            if (elapsed < st->after_s) {
                return;
            }
            st->started = true;
            std::fprintf(stderr, "[dldump] starting at display list %llu (%.1f s in)\n",
                         (unsigned long long)st->seen, elapsed);
        }

        st->out.clear();
        std::snprintf(st->line, sizeof(st->line), "=== frame %llu entry=%06X ===",
                      (unsigned long long)st->frame, entry & 0x00FFFFF8u);
        st->emit();
        std::memset(st->segments, 0, sizeof(st->segments));
        dl_dump_walk(*st, rdram, entry);

        std::fwrite(st->out.data(), 1, st->out.size(), st->file);
        st->written += st->out.size();
        st->frame++;
        if (st->written >= DL_DUMP_MAX_BYTES || (st->max_frames != 0 && st->frame >= st->max_frames)) {
            st->capped = true;
            std::fflush(st->file);
            std::fprintf(stderr, "[dldump] %llu frames / %zu bytes written; dumping stopped\n",
                         (unsigned long long)st->frame, st->written);
        }
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
    // Diagnostic only (KE_DL_DUMP unset => one cached null test): walk the
    // game's own display list before any prologue injection changes the entry
    // address RT64 will be handed.
    dl_dump_maybe(app->core.RDRAM, dl_addr);
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
