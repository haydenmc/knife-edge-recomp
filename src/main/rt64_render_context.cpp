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

    // RT64: RSP::fromSegmented() + the 0x00FFFFF8 DMA mask
    // (deps/rt64/src/hle/rt64_rsp.cpp).
    inline uint32_t dl_resolve(const uint32_t* segments, uint32_t seg_addr) {
        return (segments[(seg_addr >> 24) & 0x0F] + (seg_addr & 0x00FFFFFFu)) & 0x00FFFFF8u;
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

        uint32_t resolve(uint32_t seg_addr) const { return dl_resolve(segments, seg_addr); }
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

    // ------------------------------------------------------------------
    // Shared display-list iterator.
    //
    // Two things walk the game's display list: the KE_DL_DUMP dumper below,
    // and hud_relocation's per-frame redirect pass. The *structure* of that
    // walk is identical and non-obvious -- the 8-byte {w0,w1} command stream,
    // G_DL pushes with a return stack, G_ENDDL pops, the two continuation
    // words that follow a texrect (which are not commands and must be
    // skipped), the G_MW_SEGMENT table that address operands resolve
    // through, and the RDRAM-bounds / depth / command caps that keep a
    // malformed stream from wedging the graphics thread -- so it lives here
    // once and only the per-command action is a callback.
    //
    // `visit` returns what to do with the command it was handed; only G_DL
    // pushes read anything but Continue:
    //   Continue  descend into a push, as the RSP would
    //   SkipCall  do not descend; resume at the command after the push
    //             (hud_relocation uses this: it has just repointed the push
    //             at one of its own stubs, and walking into either the stub
    //             or the element sub-DL would be pointless at best)
    //   Stop      abandon the walk
    // `note` reports the three abnormal terminations, for diagnostics.
    // ------------------------------------------------------------------
    enum class DLStep { Continue, SkipCall, Stop };
    enum class DLNote { BadAddress, DepthCap, CommandCap };

    template <typename Visit, typename Note>
    void dl_walk(const uint8_t* rdram, uint32_t entry, uint32_t* segments, Visit&& visit, Note&& note) {
        uint32_t ret_stack[DL_DUMP_MAX_DEPTH];
        int depth = 0;
        uint32_t addr = entry & 0x00FFFFF8u;
        int index = 0;

        while (index < DL_DUMP_MAX_CMDS) {
            uint32_t w0 = 0, w1 = 0;
            if (!dl_read(rdram, addr, w0, w1)) {
                note(DLNote::BadAddress, index, addr);
                return;
            }

            const uint8_t op = uint8_t(w0 >> 24);
            const uint32_t here = addr;
            const int here_index = index;
            addr += 8;
            index++;

            // Tracked here rather than in the visitor because the target
            // address computed just below depends on it.
            if (op == DL_G_MOVEWORD && dl_bits(w0, 16, 8) == 0x06) {   // G_MW_SEGMENT
                segments[dl_bits(w0, 2, 4)] = w1;
            }

            // rt64_gbi_f3dex2 maps G_DL to GBI_F3D::runDl: w0 bit 16 clear
            // == push (call), set == branch (no return address pushed).
            const bool is_dl = (op == DL_G_DL);
            const bool push = is_dl && (dl_bits(w0, 16, 1) == 0);
            const uint32_t target = is_dl ? dl_resolve(segments, w1) : 0;

            const DLStep step = visit(here, here_index, op, w0, w1, push, target);
            if (step == DLStep::Stop) {
                return;
            }

            switch (op) {
            case DL_G_TEXRECT:
            case DL_G_TEXRECTFLIP:
                addr += 16;   // skip the two continuation words
                index += 2;
                break;
            case DL_G_DL:
                if (step == DLStep::SkipCall) {
                    break;
                }
                if (push) {
                    if (depth >= DL_DUMP_MAX_DEPTH) {
                        note(DLNote::DepthCap, here_index, here);
                        return;
                    }
                    ret_stack[depth++] = addr;
                }
                addr = target;
                break;
            case DL_G_ENDDL:
                if (depth == 0) {
                    return;
                }
                addr = ret_stack[--depth];
                break;
            default:
                break;
            }
        }

        note(DLNote::CommandCap, index, 0);
    }

    void dl_dump_walk(DLDumpState& st, const uint8_t* rdram, uint32_t entry) {
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

        auto visit = [&](uint32_t here, int here_index, uint8_t op, uint32_t w0, uint32_t w1,
                         bool push, uint32_t target) -> DLStep {
            if (op == DL_G_TRI1 || op == DL_G_TRI2 || op == DL_G_QUAD) {
                if (tri_run == 0) {
                    tri_start_addr = here;
                    tri_start_index = here_index;
                }
                tri_run += (op == DL_G_TRI1) ? 1 : 2;
                return DLStep::Continue;
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
                dl_read(rdram, here + 8, h0w0, h0w1);
                dl_read(rdram, here + 16, h1w0, h1w1);
                const int16_t uls = int16_t(h0w1 >> 16), ult = int16_t(h0w1 & 0xFFFF);
                const int16_t dsdx = int16_t(h1w1 >> 16), dtdy = int16_t(h1w1 & 0xFFFF);
                std::snprintf(q, qn,
                    "%s ul=%.2f,%.2f lr=%.2f,%.2f w=%.2f h=%.2f tile=%u st=%d,%d d=%d,%d",
                    (op == DL_G_TEXRECT) ? "TEXRECT" : "TEXRECTFLIP",
                    ulx / 4.0, uly / 4.0, lrx / 4.0, lry / 4.0,
                    (lrx - ulx) / 4.0, (lry - uly) / 4.0,
                    tile, int(uls), int(ult), int(dsdx), int(dtdy));
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
                if (type == 0x06) {   // G_MW_SEGMENT (dl_walk() already applied it)
                    std::snprintf(q, qn, "MOVEWORD SEGMENT seg=%u -> %08X", dl_bits(w0, 2, 4), w1);
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
            case DL_G_DL:
                std::snprintf(q, qn, "DL %s addr=%08X phys=%06X",
                              push ? "push" : "branch", w1, target);
                break;
            case DL_G_ENDDL:
                std::snprintf(q, qn, "ENDDL");
                break;
            default:
                std::snprintf(q, qn, "OP_%02X %08X %08X", op, w0, w1);
                break;
            }

            if (print) {
                st.emit();
            }
            return DLStep::Continue;
        };

        auto note = [&](DLNote kind, int index, uint32_t addr) {
            flush_tris();
            switch (kind) {
            case DLNote::BadAddress:
                std::snprintf(st.line, sizeof(st.line), "%llu %d @%06X BADADDR",
                              (unsigned long long)st.frame, index, addr);
                break;
            case DLNote::DepthCap:
                std::snprintf(st.line, sizeof(st.line), "%llu %d @%06X DEPTHCAP",
                              (unsigned long long)st.frame, index, addr);
                break;
            case DLNote::CommandCap:
                std::snprintf(st.line, sizeof(st.line), "%llu %d CMDCAP",
                              (unsigned long long)st.frame, index);
                break;
            }
            st.emit();
        };

        dl_walk(rdram, entry, st.segments, visit, note);
        flush_tris();
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

    // ==================================================================
    // hud_relocation enhancement (analysis/docs/hud-relocation.md).
    //
    // Every in-mission HUD element is a self-contained, G_ENDDL-terminated
    // sub-display-list at a fixed RDRAM address, reached by exactly one
    // 8-byte G_DL *push* from the tail of the frame's main display list
    // (phase 1, §3-§5: verified over 450 dumped frames in four captures --
    // one push per element per frame, addresses identical across process
    // launches and across profiles). So relocation needs no code patching
    // and no writes to the elements themselves: for each such push we
    // repoint it at a small stub in scratch RDRAM that sets RT64's
    // extended-GBI rect alignment, calls the element's real sub-DL, resets
    // the alignment, and returns.
    //
    // This is a pure presentation change. The game's own coordinates, its
    // aim math and every game-side global are untouched; only where RT64
    // places the resulting rectangles changes.
    // ==================================================================

    // Set once from main(), before recomp::start() spins up the gfx thread.
    std::atomic<bool> hud_relocation_on{false};
    std::atomic<bool> hud_vertical_shift_on{false};

    // Scratch RDRAM layout, physical addresses (vaddr 0x807FFxxx). The
    // upper 4 MiB of librecomp's 8 MiB RDRAM allocation, which this
    // base-4-MiB-machine game never touches (analysis/out/segment_map.md:
    // highest write ever seen is 0x80287C20).
    //
    //   0x7FF000 .. 0x7FF03F   the display-list prologue (16 words of room;
    //                          12 is the longest form it emits)
    //   0x7FF040 ..            one 12-word stub per fingerprinted HUD element
    //   (then)                 HUD_DYN_STUBS 12-word stubs for the
    //                          dynamic fills, rebuilt every frame because
    //                          the sub-DL they call moves (see
    //                          hud_regions[] below)
    constexpr uint32_t SCRATCH_BASE = 0x7FF000u;
    constexpr uint32_t HUD_STUB_BASE = 0x7FF040u;
    constexpr uint32_t HUD_STUB_WORDS = 12;
    // How many region-matched (variable-address) elements one frame can
    // relocate. Two are expected -- the health fill arc and the S-BOMB
    // charge fill -- and no capture has ever shown a third; the slack is so
    // that an unexpected extra is dropped rather than overflowing.
    constexpr size_t HUD_DYN_STUBS = 8;

    // How far inward the re-expressed scissor's left edge starts, in N64
    // pixels. See the long comment at its use site in
    // maybe_inject_prologue() -- 1 is the provable minimum and nothing but
    // the deliberately-overdrawn flash comes near it.
    constexpr int HUD_SCISSOR_LEFT_BIAS_PX = 1;

    // RT64 extended-GBI encodings, derived from deps/rt64/include/
    // rt64_extended_gbi.h and cross-checked against the handlers in
    // deps/rt64/src/gbi/rt64_gbi_extended.cpp.
    //
    //   G_EX_COMMAND2(cmd, w0, w1, w2, w3) writes two Gfx commands, i.e.
    //   four native u32s, in order.
    //   PARAM(v, bits, shift) == (v & ((1<<bits)-1)) << shift.
    //
    // gEXSetRectAlign(cmd, lorigin, rorigin, ulxOff, ulyOff, lrxOff, lryOff)
    // expands to:
    //   w0 = PARAM(0x64, 8, 24) | PARAM(G_EX_SETRECTALIGN_V1 = 6, 24, 0)
    //      = 0x64000006
    //   w1 = PARAM(lorigin, 12, 0) | PARAM(rorigin, 12, 12)
    //   w2 = PARAM(ulxOff, 16, 16) | PARAM(ulyOff, 16, 0)
    //   w3 = PARAM(lrxOff, 16, 16) | PARAM(lryOff, 16, 0)
    //
    // Units: setRectAlignV1() reads the four offsets as int16_t and hands
    // them to RDP::setRectAlign(); RDP::drawRect() then does
    // `ulx += leftOffset; uly += topOffset; ...` directly on the texrect's
    // *raw* coordinates, which are 10.2 fixed point
    // (deps/rt64/src/hle/rt64_rdp.cpp:1173). So the offsets are in 10.2
    // units: one N64 pixel is 4. Note that gEXSetRectAlign is the one
    // alignment macro that does NOT pre-multiply its offsets by 4 (its
    // gEXSetScissor / gEXSetScissorAlign neighbours do), so the macro's
    // arguments are already in these units too.
    constexpr uint32_t G_EX_SETRECTALIGN_W0 = 0x64000006u;
    constexpr uint32_t EX_ORIGIN_LEFT = 0x0u;
    constexpr uint32_t EX_ORIGIN_CENTER = 0x200u;
    constexpr uint32_t EX_ORIGIN_RIGHT = 0x400u;
    constexpr uint32_t EX_ORIGIN_NONE = 0x800u;

    // F3DEX2, from deps/rt64/src/gbi/rt64_gbi_f3dex2.cpp's opcode map plus
    // GBI_F3D::runDl/endDl in rt64_gbi_f3d.cpp: G_DL is 0xDE with w0 bit 16
    // clear meaning "push" (the return address is stacked, control comes
    // back on the callee's G_ENDDL); G_ENDDL is 0xDF and ignores w1.
    constexpr uint32_t F3DEX2_DL_PUSH_W0 = 0xDE000000u;
    constexpr uint32_t F3DEX2_ENDDL_W0 = 0xDF000000u;

    // How an element re-anchors horizontally.
    enum class HudAnchor {
        Left,      // hug the window's left edge, keeping the element's own inset
        Right,     // hug the window's right edge, keeping its own inset
        Center,    // stay centred -- i.e. exactly where it is today
        Stretch,   // left edge to the window's left, right edge to its right
    };

    struct HudElement {
        uint32_t sub_dl;       // KSEG0 address of the game's element sub-DL
        HudAnchor anchor;
        int16_t vertical_px;   // applied only when full_height is also on
        // True for a sub-DL address the game also uses outside missions.
        // Such an element is only redirected on frames that also contain an
        // unambiguously in-mission element -- see hud_redirect_frame().
        bool shared_buffer;
        // True for the one element whose game-side coordinates the
        // extended_aim enhancement biases (the reticle): its stub carries the
        // matching negative offset that puts the sprite back where the game
        // meant it. Zero unless that enhancement is active, so this is the
        // exact identity in every other configuration.
        bool aim_biased;
        const char* name;
    };

    // Fingerprint table (analysis/docs/hud-relocation.md §10). Every address
    // here was observed pushed exactly once per frame in the states where it
    // appears, never in the front end, across four captures.
    //
    // Vertical: with full_height the mission scissor opens from 0,20->320,220
    // to 0,0->320,240, but the HUD keeps drawing against the old band edges,
    // so the bottom clusters float 20 px above the true floor and the radio
    // box hangs 20 px below the true ceiling. There is no vertical origin in
    // gEXSetRectAlign (§7 landmine 2), but none is needed: the framebuffer
    // stays 240 tall, so the correction is the known constant +/-20 px.
    // Without full_height the letterbox is still there and the elements are
    // already flush against it -- zero vertical offset.
    constexpr HudElement hud_elements[] = {
        // The reticle is a world-relative cursor, not a corner widget. It is
        // anchored Center with NO vertical offset, ever: it has to stay
        // registered with the 3D projection, and widescreen (RT64
        // AspectRatio::Expand) widens the frustum *around* the original 4:3
        // content, which therefore stays centred at its original scale. A
        // reticle moved off that registration would point at something other
        // than what the game's hit test is aiming at.
        //
        // It is also the one element the extended_aim enhancement biases
        // game-side (analysis/docs/hud-relocation.md, "Reticle range
        // extension"): to be drawable outside the original 4:3 column at all,
        // the blit's x is shifted right by B N64 pixels so the game's own
        // sprite library emits non-negative, unclipped texrect coordinates,
        // and this stub subtracts the same B again. B is 0 -- the exact
        // identity -- whenever that enhancement is not widening the
        // horizontal rail.
        { 0x801C8470u, HudAnchor::Center,  0, false, true, "reticle" },

        // Bottom-left health cluster: x 20..86, y 172..220 (a 20 px left
        // margin, flush against the letterbox floor).
        // The fill arc is deliberately absent: it is a dynamic fill and is
        // matched by region below. Phase 2 listed two of its addresses here,
        // which is why it stayed behind at any health those two did not cover.
        { 0x801BCE30u, HudAnchor::Left, 20, false, false, "health backing" },
        { 0x801BD070u, HudAnchor::Left, 20, false, false, "health jet glyph" },
        { 0x801BD2B0u, HudAnchor::Left, 20, false, false, "health number panel" },
        // Drawn from a shared boot-segment buffer in its own 2D group after a
        // render-mode restore, so it needs its own align/reset pair even
        // though it is visually part of the dial. The buffer really is shared
        // (phase 1 open question O3, settled for phase 2 by a from-boot dump)
        // -- hence shared_buffer = true and the in-mission gate in
        // hud_redirect_frame().
        { 0x800F2B50u, HudAnchor::Left, 20, true, false, "health % digits" },

        // Bottom-right S-BOMB cluster: x 215..295, y 188..220 (a 25 px right
        // margin, same letterbox floor).
        // Likewise the charge fill (phase 2's "S-BOMB blinker") is a dynamic
        // fill, matched by region below.
        { 0x801C25F0u, HudAnchor::Right, 20, false, false, "S-BOMB gauge" },

        // A screen effect, not a widget: one 319x239 rect covering the whole
        // frame. Stretched to the true window edges rather than translated.
        { 0x801B6CB0u, HudAnchor::Stretch, 0, false, false, "full-screen flash" },

        // The in-mission cutscene radio box (dialogue panel 0x801C88F0,
        // glyphs 0x80109550, portrait frame 0x801D0AB0, portraits
        // 0x801D1110/0x801D1C50) is deliberately NOT here. Phase 2 centred
        // it and lifted it 20 px to the true frame top; the owner's hands-on
        // verdict (2026-07-31) was to put it back exactly where the game
        // draws it -- the cutscene's own graphical effects are authored
        // against the 4:3 column and looked misaligned beside a moved box,
        // and the box does not read as out of place there. Leaving the
        // addresses unlisted is the whole revert: unmatched pushes are
        // executed untouched. See analysis/docs/hud-relocation.md phase 3.
    };
    constexpr size_t HUD_ELEMENT_COUNT = sizeof(hud_elements) / sizeof(hud_elements[0]);

    // ------------------------------------------------------------------
    // Region table -- the *dynamic* HUD fills.
    //
    // The table above fingerprints elements by sub-DL address, which works
    // because those elements are rebuilt every frame at a fixed address.
    // The two elements whose *content* varies are not like that: the health
    // fill arc and the S-BOMB charge fill are drawn from a pool of 0x240-byte
    // display-list buffers starting at 0x801BCE30, and which slot they land
    // in changes with the value being displayed. Four KE_DL_DUMP captures
    // (1769 mission frames) saw the health fill at thirteen distinct
    // addresses and the S-BOMB fill at three, with the static dial parts
    // sharing the same pool at fixed slots in between -- so no address list
    // can ever be complete, and no address *range* can separate them from
    // their neighbours in the pool (the top enemy bar lives in it too).
    //
    // They are matched geometrically instead: any sub-DL called from the
    // frame's main list whose texrects all fall inside one of these boxes
    // belongs to that cluster and rides with it. The boxes are the static
    // containers' own footprints, so this is a statement about the HUD's
    // layout rather than about the game's buffer allocator.
    //
    // False positives: the match requires *every* texrect in the sub-DL to
    // be inside the box, which is 71x49 for the health dial and 86x36 for
    // the S-BOMB gauge, and it only applies on frames that already matched
    // an unambiguously in-mission element (same gate as the shared digit
    // buffer). Across those 1769 mission frames the only sub-DLs that
    // qualify are the two fills; every effect sprite seen near the bottom of
    // the frame is a 64x64 or larger rect that cannot fit either box, and
    // the full-screen flash (319x239) and the enemy bar (y 0..37) are
    // nowhere near. The one element that *could* geometrically qualify is
    // the reticle -- 32x32, and aimed at the bottom left its rect does fit
    // the health box -- but it is matched by address first, and its address
    // was identical in all 1769 frames of every capture.
    struct HudRegion {
        int16_t x0, y0, x1, y1;   // N64 pixels, inclusive
        HudAnchor anchor;
        int16_t vertical_px;      // applied only when full_height is also on
        const char* name;
    };

    constexpr HudRegion hud_regions[] = {
        // Health dial: backing 64x48 at (20,172), number panel out to x 86,
        // the fill arc 48x48 at (20,172) shrinking towards its fixed
        // bottom-right corner (68,220) as health drops.
        { 20, 172, 90, 220, HudAnchor::Left, 20, "health fill" },
        // S-BOMB gauge: five 16x32 segments spanning (215,188)..(295,220),
        // charge fill 16x8 at (215,207).
        { 215, 185, 300, 220, HudAnchor::Right, 20, "S-BOMB fill" },
    };
    constexpr size_t HUD_REGION_COUNT = sizeof(hud_regions) / sizeof(hud_regions[0]);

    // Total scratch footprint, prologue included -- what the one-time
    // zero-check below has to cover.
    constexpr uint32_t SCRATCH_WORDS =
        (HUD_STUB_BASE - SCRATCH_BASE) / 4 + (HUD_ELEMENT_COUNT + HUD_DYN_STUBS) * HUD_STUB_WORDS;

    uint32_t hud_stub_address(size_t index) {
        return HUD_STUB_BASE + uint32_t(index) * HUD_STUB_WORDS * 4u;
    }

    // The per-frame stubs for region matches live immediately after the
    // fixed per-element ones.
    uint32_t hud_dyn_stub_address(size_t slot) {
        return hud_stub_address(HUD_ELEMENT_COUNT + slot);
    }

    // Horizontal alignment for one element, in RT64's terms.
    //
    // RDP::drawRect() adds the offsets to the raw 10.2 coordinates and then
    // calls movedFromOrigin(x, origin) = x + origin*width*4/G_EX_ORIGIN_RIGHT;
    // the framebuffer renderer later undoes exactly that shift about the
    // window's corresponding edge (convertViewportRect()'s computeOrigin(),
    // deps/rt64/src/render/rt64_framebuffer_renderer.cpp:88). Net effect for
    // a 320-wide color image, writing S for the 4:3 pixel scale:
    //
    //   LEFT    window_x = (x + off) * S                      -- from the left edge
    //   CENTER  window_x = window_centre + (x + off) * S
    //   RIGHT   window_x = window_width  + (x + off) * S      -- from the right edge
    //
    // So the offset is just "what the element's own coordinate must become
    // once it is measured from the chosen edge":
    //   Left    keep x as-is                      -> 0
    //   Center  x is measured from 160            -> -160 px
    //   Right   x is measured from 320            -> -320 px
    //
    // A pleasant consequence: with these offsets the transform is the exact
    // identity when RT64's extAspectRatio is Original (extAspectPercentage
    // 0 collapses every computeOrigin() to the framebuffer centre), so the
    // stubs are a no-op rather than a corruption in that configuration.
    struct HudAlign {
        uint32_t lorigin;
        uint32_t rorigin;
        int16_t ulx_off;
        int16_t lrx_off;
    };

    HudAlign hud_align_for(HudAnchor anchor) {
        switch (anchor) {
            case HudAnchor::Left:
                return { EX_ORIGIN_LEFT, EX_ORIGIN_LEFT, 0, 0 };
            case HudAnchor::Right:
                return { EX_ORIGIN_RIGHT, EX_ORIGIN_RIGHT, -320 * 4, -320 * 4 };
            case HudAnchor::Stretch:
                // The flash rect is 319 wide, not 320 -- the classic
                // one-pixel-short full-screen rect -- so reaching the
                // window's right edge is -319 px, not -320. Both edges are
                // then pushed a further 2 px outward so the flash overdraws
                // the scissor instead of falling short of it: the scissor's
                // own left bias and RT64's misalignment correction between
                // them leave a few window pixels of margin, and a flash with
                // an unlit hairline down each side would be visible.
                return { EX_ORIGIN_LEFT, EX_ORIGIN_RIGHT, -2 * 4, (-319 + 2) * 4 };
            case HudAnchor::Center:
            default:
                return { EX_ORIGIN_CENTER, EX_ORIGIN_CENTER, -160 * 4, -160 * 4 };
        }
    }

    // Writes one 12-word stub. Direct native-u32 stores into the RDRAM
    // block, the same convention as the prologue and as RT64's own
    // DisplayList reads (and as the recompiled game's 4-byte-aligned SW
    // instructions).
    //
    // `sub_dl_word` is the address word the stub's own G_DL push carries --
    // for a fingerprinted element the table's KSEG0 constant, for a region
    // match the exact w1 the game's own push carried, so whatever the game
    // meant by it (it never uses a nonzero segment: phase 1 §5) is preserved.
    // `aim_bias_px` is the extended_aim draw bias for this element, in N64
    // pixels (0 for everything but the reticle, and 0 for the reticle too
    // unless that enhancement is widening the horizontal rail). Subtracted
    // from both horizontal offsets, in the same 10.2 units, so the sprite
    // lands exactly where the game's own coordinate said before the bias.
    void hud_write_stub(uint8_t* rdram, uint32_t stub_addr, uint32_t sub_dl_word,
                        HudAnchor anchor, int16_t vertical_px, bool vertical_shift,
                        int16_t aim_bias_px = 0) {
        const HudAlign align = hud_align_for(anchor);
        const int16_t v = vertical_shift ? int16_t(vertical_px * 4) : int16_t(0);
        const int16_t ulx_off = int16_t(align.ulx_off - aim_bias_px * 4);
        const int16_t lrx_off = int16_t(align.lrx_off - aim_bias_px * 4);

        const uint32_t align_origins =
            (align.lorigin & 0xFFFu) | ((align.rorigin & 0xFFFu) << 12);
        const uint32_t align_ul =
            (uint32_t(uint16_t(ulx_off)) << 16) | uint32_t(uint16_t(v));
        const uint32_t align_lr =
            (uint32_t(uint16_t(lrx_off)) << 16) | uint32_t(uint16_t(v));

        uint32_t* p = reinterpret_cast<uint32_t*>(rdram + stub_addr);
        p[0] = G_EX_SETRECTALIGN_W0;  p[1] = align_origins;   // gEXSetRectAlign(anchor)
        p[2] = align_ul;              p[3] = align_lr;
        p[4] = F3DEX2_DL_PUSH_W0;     p[5] = sub_dl_word;     // call the real element
        // The reset is mandatory in EVERY stub, not once at the end of
        // the group: RT64's rect alignment is global state that nothing
        // in the game's display list ever restores (phase 1 landmine 1 --
        // RDP::clearExtended() runs only from State::fullSync(), i.e. at
        // the frame's G_RDPFULLSYNC, long after the whole HUD has been
        // drawn). Without it, one element's anchor would displace every
        // rect after it, starting with its own neighbours.
        p[6] = G_EX_SETRECTALIGN_W0;
        p[7] = (EX_ORIGIN_NONE & 0xFFFu) | ((EX_ORIGIN_NONE & 0xFFFu) << 12);
        p[8] = 0;                     p[9] = 0;
        p[10] = F3DEX2_ENDDL_W0;      p[11] = 0;              // back to the main DL
    }

    // Builds every fixed-address element's stub. The region stubs are not
    // built here: the sub-DL they call moves from frame to frame, so they are
    // rewritten on each frame that matches one.
    //
    // Rebuilt (rather than built once) whenever `aim_bias_px` changes, which
    // only happens when the window is resized with extended_aim active -- the
    // bias is derived from the window aspect. See maybe_redirect_hud().
    void hud_build_stubs(uint8_t* rdram, bool vertical_shift, int16_t aim_bias_px) {
        for (size_t i = 0; i < HUD_ELEMENT_COUNT; i++) {
            hud_write_stub(rdram, hud_stub_address(i), hud_elements[i].sub_dl,
                           hud_elements[i].anchor, hud_elements[i].vertical_px, vertical_shift,
                           hud_elements[i].aim_biased ? aim_bias_px : int16_t(0));
        }
    }

    // Rewrites, in place, every G_DL push in this frame's display list whose
    // target is a fingerprinted element, so it lands on that element's stub
    // instead. Returns how many were rewritten.
    //
    // This does write into the game's own main display-list buffer, which is
    // the one place this project touches game RAM at all. It is safe by
    // construction rather than by luck: the game rebuilds the entire frame
    // display list every frame at a per-frame-varying offset in one of two
    // double-buffered arenas (phase 1 §4 measured 52 distinct offsets over
    // 150 frames), so a rewritten word is dead the moment the frame is
    // submitted and is never read back by game code. The element sub-DLs
    // themselves are never written.
    uint32_t hud_redirect_frame(uint8_t* rdram, uint32_t entry, bool vertical_shift) {
        uint32_t segments[16] = {};
        uint32_t rewrites = 0;

        // A shared-buffer element can only be judged once the whole frame has
        // been seen, so its call sites are collected and resolved afterwards.
        // In practice there is at most one per frame; the small fixed array
        // keeps this allocation-free on a per-frame path.
        struct Deferred { uint32_t here; size_t index; };
        Deferred deferred[8];
        size_t deferred_count = 0;
        bool in_mission = false;

        // Region (geometric) matches. Deferred for the same reason and behind
        // the same gate as the shared buffer, plus one of their own: a stub
        // has to be written for each, and writing it before the frame is
        // known to be in-mission would be a scratch write on a front-end
        // frame.
        struct DeferredRegion { uint32_t here; uint32_t sub_dl_word; size_t region; };
        DeferredRegion dyn[HUD_DYN_STUBS];
        size_t dyn_count = 0;

        // Region-match probe state. Every push out of the main display list
        // that is not a fingerprinted element is followed into, and the
        // bounding box of the texrects it draws (its own, and any it calls in
        // turn) is accumulated until control returns. `depth` mirrors the
        // walker's own call depth, which is why SkipCall -- the one case
        // where the walker does not descend -- must not touch it.
        int depth = 0;
        bool probing = false;
        uint32_t probe_here = 0;
        uint32_t probe_word = 0;
        bool probe_has_rect = false;
        int32_t bx0 = 0, by0 = 0, bx1 = 0, by1 = 0;   // 10.2, like the texrects

        auto finish_probe = [&]() {
            if (probe_has_rect && dyn_count < HUD_DYN_STUBS) {
                for (size_t r = 0; r < HUD_REGION_COUNT; r++) {
                    const HudRegion& region = hud_regions[r];
                    if (bx0 >= int32_t(region.x0) * 4 && bx1 <= int32_t(region.x1) * 4 &&
                        by0 >= int32_t(region.y0) * 4 && by1 <= int32_t(region.y1) * 4) {
                        dyn[dyn_count++] = { probe_here, probe_word, r };
                        break;
                    }
                }
            }
            probing = false;
            probe_has_rect = false;
        };

        auto visit = [&](uint32_t here, int, uint8_t op, uint32_t w0, uint32_t w1,
                         bool push, uint32_t target) -> DLStep {
            if (op == DL_G_TEXRECT || op == DL_G_TEXRECTFLIP) {
                if (probing) {
                    // rt64_gbi_rdp.cpp::texrect(): lr in w0, ul in w1, both
                    // 10.2 fixed point.
                    const int32_t lrx = int32_t(dl_bits(w0, 12, 12));
                    const int32_t lry = int32_t(dl_bits(w0, 0, 12));
                    const int32_t ulx = int32_t(dl_bits(w1, 12, 12));
                    const int32_t uly = int32_t(dl_bits(w1, 0, 12));
                    if (!probe_has_rect) {
                        bx0 = ulx; by0 = uly; bx1 = lrx; by1 = lry;
                        probe_has_rect = true;
                    }
                    else {
                        bx0 = std::min(bx0, ulx); by0 = std::min(by0, uly);
                        bx1 = std::max(bx1, lrx); by1 = std::max(by1, lry);
                    }
                }
                return DLStep::Continue;
            }
            if (op == DL_G_ENDDL) {
                if (depth > 0 && --depth == 0 && probing) {
                    finish_probe();
                }
                return DLStep::Continue;
            }
            if (op != DL_G_DL || !push) {
                return DLStep::Continue;
            }
            for (size_t i = 0; i < HUD_ELEMENT_COUNT; i++) {
                if (target != (hud_elements[i].sub_dl & 0x00FFFFF8u)) {
                    continue;
                }
                if (hud_elements[i].shared_buffer) {
                    if (deferred_count < sizeof(deferred) / sizeof(deferred[0])) {
                        deferred[deferred_count++] = { here, i };
                    }
                    return DLStep::SkipCall;
                }
                in_mission = true;
                // w1 of the push, i.e. the second word of the command.
                // Written in the game's own KSEG0 form: RSP::fromSegmented()
                // indexes the segment table with bits 27:24, which are 0 for
                // both 0x80... and a bare physical address, and the game
                // sets segment 0 to 0 exactly once per frame (phase 1 §5).
                const uint32_t stub = 0x80000000u | hud_stub_address(i);
                std::memcpy(rdram + here + 4, &stub, 4);
                rewrites++;
                return DLStep::SkipCall;
            }
            if (depth == 0) {
                probing = true;
                probe_here = here;
                probe_word = w1;
                probe_has_rect = false;
            }
            depth++;
            return DLStep::Continue;
        };

        dl_walk(rdram, entry, segments, visit, [](DLNote, int, uint32_t) {});

        // The health % digits live in a boot-segment buffer the front end
        // also draws from (phase 1 open question O3, measured for phase 2:
        // in the 640x480 boot/logo screen the same sub-DL address draws 8x19
        // glyphs at y=381 from the same glyph texture family, 88 of the first
        // 97 frames of a run). Relocating those would drag the logo screen's
        // own text across the window, so a shared-buffer element is only
        // redirected when the same frame also contained an element that can
        // only be in-mission -- which, in a mission, always holds: the
        // reticle, the health dial backing, the jet glyph and the number
        // panel are each present in 100% of dumped gameplay frames, and the
        // digits never appear without them.
        if (in_mission) {
            for (size_t d = 0; d < deferred_count; d++) {
                const uint32_t stub = 0x80000000u | hud_stub_address(deferred[d].index);
                std::memcpy(rdram + deferred[d].here + 4, &stub, 4);
                rewrites++;
            }
            // The dynamic fills. Same gate, and the stub is built here rather
            // than once at startup because the sub-DL it calls is whichever
            // pool slot the game happened to use for this frame's health /
            // charge value. Rebuilding is 12 stores.
            for (size_t d = 0; d < dyn_count; d++) {
                const HudRegion& region = hud_regions[dyn[d].region];
                const uint32_t stub_addr = hud_dyn_stub_address(d);
                hud_write_stub(rdram, stub_addr, dyn[d].sub_dl_word,
                               region.anchor, region.vertical_px, vertical_shift);
                const uint32_t stub = 0x80000000u | stub_addr;
                std::memcpy(rdram + dyn[d].here + 4, &stub, 4);
                rewrites++;

                // One line per region, the first time it ever matches: which
                // pool slot a fill lands in is the single most useful thing
                // to have in a bug report about it.
                static bool region_logged[HUD_REGION_COUNT] = {};
                if (!region_logged[dyn[d].region]) {
                    region_logged[dyn[d].region] = true;
                    std::fprintf(stderr, "[hud] %s matched by region at sub-DL 0x%08X\n",
                                 region.name, dyn[d].sub_dl_word);
                }
            }
        }
        return rewrites;
    }
}

void kerecomp::renderer::set_hud_relocation_enhancement(bool on, bool vertical_shift) {
    hud_relocation_on.store(on, std::memory_order_relaxed);
    hud_vertical_shift_on.store(vertical_shift, std::memory_order_relaxed);
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
    // game's own display list before anything below modifies it or changes
    // the entry address RT64 will be handed.
    dl_dump_maybe(app->core.RDRAM, dl_addr);
    const bool hud_this_frame = maybe_redirect_hud(dl_addr) > 0;
    uint32_t entry = maybe_inject_prologue(dl_addr, hud_this_frame);
    app->processDisplayLists(app->core.RDRAM, entry, 0, true);
}

// One-time check that nothing else has claimed our scratch RDRAM, run
// strictly before our first write ever happens (afterwards the words are
// nonzero by our own hand, so the check could never run again anyway). If
// any word of the region we're about to use is already nonzero, something
// else owns it, and we fail safe -- permanently disabling both the
// high_framerate prologue and hud_relocation rather than risk corrupting
// whatever that is.
//
// Scratch is physical 0x7FF000 (vaddr 0x807FF000): inside librecomp's 8 MiB
// RDRAM allocation but in the upper 4 MiB, which this base-4-MiB-machine
// game never touches (analysis/out/segment_map.md: highest write ever seen
// is 0x80287C20).
bool kerecomp::renderer::RT64Context::scratch_usable() {
    static const bool usable = [this]() {
        const uint32_t* p = reinterpret_cast<const uint32_t*>(app->core.RDRAM + SCRATCH_BASE);
        for (uint32_t i = 0; i < SCRATCH_WORDS; i++) {
            if (p[i] != 0) {
                std::fprintf(stderr,
                    "[gfx] scratch RDRAM at 0x807FF000 unexpectedly in use (word %u); "
                    "high framerate interpolation and HUD relocation disabled\n", i);
                // extended_aim's horizontal half is built on the reticle's
                // relocation stub, which lives in that scratch: without it
                // nothing would undo the game-side draw bias, so tell it to
                // fall back to the vanilla rail rather than draw wrong. This
                // resolves on the run's first display list, long before any
                // mission (src/main/extended_aim.cpp).
                kerecomp::set_extended_aim_draw_supported(false);
                return false;
            }
        }
        return true;
    }();
    return usable;
}

// True when the hud_relocation enhancement should act on this frame. Both
// the redirect pass and the prologue's ENABLE gate on exactly this, so the
// stubs' extended-GBI commands can never be reached without the extended
// opcode registered.
bool kerecomp::renderer::RT64Context::hud_relocation_active() {
    return hud_relocation_on.load(std::memory_order_relaxed) && scratch_usable();
}

// hud_relocation enhancement (analysis/docs/hud-relocation.md). Builds the
// per-element stubs on the first frame they're needed, then repoints this
// frame's HUD display-list calls at them. Returns how many calls it
// repointed, which is also the "does this frame contain relocated HUD at
// all" answer the prologue needs.
uint32_t kerecomp::renderer::RT64Context::maybe_redirect_hud(uint32_t game_dl_addr) {
    if (!hud_relocation_active()) {
        return 0;
    }

    const bool vertical_shift = hud_vertical_shift_on.load(std::memory_order_relaxed);

    // The reticle's stub carries the extended_aim draw bias, which is derived
    // from the live window aspect -- so unlike everything else here it is not
    // a build-once constant. Rebuild on change; a resize is the only thing
    // that changes it, and the rebuild is 12 stores per element. Plain
    // statics: this runs only on the graphics thread.
    const int16_t aim_bias =
        static_cast<int16_t>(kerecomp::extended_aim_rails().draw_bias);
    static bool stubs_built = false;
    static int16_t built_aim_bias = 0;
    if (!stubs_built || built_aim_bias != aim_bias) {
        hud_build_stubs(app->core.RDRAM, vertical_shift, aim_bias);
        stubs_built = true;
        built_aim_bias = aim_bias;
    }

    const uint32_t rewrites = hud_redirect_frame(app->core.RDRAM, game_dl_addr, vertical_shift);

    // One line, on the first frame that actually matches something -- this
    // runs at ~27 Hz, so anything per-frame would be a flood.
    static bool logged = false;
    if (!logged && rewrites > 0) {
        logged = true;
        std::fprintf(stderr, "[hud] relocation active: %u element redirects this frame\n", rewrites);
    }
    return rewrites;
}

// Extended-GBI display-list prologue, shared by two enhancements.
//
// high_framerate (analysis/docs/high-framerate.md): RT64's frame
// interpolation only engages once it knows the game's original logic rate;
// its own VI-cadence auto-detection can't derive one for this game (a
// continuous ~27 fps that straddles 2-3 VIs per frame, never a consistent
// 60/N), so we declare it per display list via gEXSetRefreshRate.
//
// hud_relocation (analysis/docs/hud-relocation.md): the per-element stubs
// contain extended-GBI commands themselves, so unlike the rate declaration
// the extended opcode has to stay registered *through* the game's display
// list rather than being switched off before branching to it.
//
// Returns game_dl_addr unchanged (untouched, no scratch RDRAM write at all)
// unless at least one of the two is active and scratch RDRAM is ours.
uint32_t kerecomp::renderer::RT64Context::maybe_inject_prologue(uint32_t game_dl_addr, bool hud) {
    // high_framerate needs a measured rate before it has anything to say; on
    // the very first display lists of a run there is none yet. Evaluated in
    // this order so that with both enhancements off (vanilla) this function
    // reads one config field and returns, exactly as it did before
    // hud_relocation existed.
    const auto& cur_config = ultramodern::renderer::get_graphics_config();
    double interval_ms = 0.0;
    bool rate_declared = false;
    if (cur_config.rr_option != ultramodern::renderer::RefreshRate::Original) {
        interval_ms = kerecomp::measured_game_frame_interval_ms();
        rate_declared = (interval_ms > 0.0);
    }

    if (!hud && !rate_declared) {
        return game_dl_addr;
    }
    if (!scratch_usable()) {
        return game_dl_addr;
    }

    int rate = 0;
    if (rate_declared) {
        rate = std::clamp(static_cast<int>(std::lround(1000.0 / interval_ms)), 10, 60);

        static int last_logged_rate = -1;
        if (rate != last_logged_rate) {
            last_logged_rate = rate;
            std::fprintf(stderr, "[hfr] declaring game logic rate %d Hz to RT64 (display target %u Hz)\n",
                         rate, get_display_framerate());
        }
    }

    // RT64 extended-GBI hook commands (deps/rt64/include/rt64_extended_gbi.h,
    // handler: noOpHook in deps/rt64/src/gbi/rt64_gbi_extended.cpp). The game
    // runs F3DEX2, whose G_SPNOOP opcode is 0xE0 = RT64_HOOK_OPCODE; magic
    // 0x525464 ("RT",0x64) marks the NOOP as an RT64 hook.
    //
    //   high_framerate only:  ENABLE -> SETREFRESHRATE -> DISABLE -> BRANCH
    //   hud_relocation only:  ENABLE ->                SCISSORALIGN -> BRANCH
    //   both:                 ENABLE -> SETREFRESHRATE -> SCISSORALIGN -> BRANCH
    //
    // Leaving the opcode registered across the game's own display list is
    // safe here, and is checked rather than assumed: opcode 0x64 does not
    // occur anywhere in 450 dumped frames across four KE_DL_DUMP captures
    // (title, cutscene, two mission entries, both profiles) -- the only
    // opcodes the dumper could not name were 0x00 (G_NOOP, once per frame)
    // and 0xEE (G_SETPRIMDEPTH). RT64 unregisters it again by itself at the
    // frame's G_RDPFULLSYNC (State::fullSync() ends with disableExtendedGBI()
    // + clearExtended(), deps/rt64/src/hle/rt64_state.cpp:1834), which every
    // frame of this game emits, so the DISABLE is genuinely redundant and
    // not merely omitted.
    //
    // Direct u32 stores, no byte-swapping: RT64's DisplayList struct reads
    // {w0, w1} as native u32s from this same buffer, and 4-byte-aligned u32
    // stores are exactly what the recompiled game's own SW instructions
    // produce.
    uint32_t* p = reinterpret_cast<uint32_t*>(app->core.RDRAM + SCRATCH_BASE);
    uint32_t i = 0;
    p[i++] = 0xE0525464u; p[i++] = 0x10000064u;                      // HOOK_OP_ENABLE, extended opcode 0x64
    if (rate_declared) {
        p[i++] = 0x64000009u; p[i++] = static_cast<uint32_t>(rate) & 0xFFFFu;  // G_EX_SETREFRESHRATE_V1
    }
    if (hud) {
        // gEXSetScissorAlign(LEFT, RIGHT, 0, 0, -320 px, 0, unbounded).
        //
        // Without this the re-anchored rects are placed correctly and then
        // clipped away, because a rect's GPU scissor is the game's own
        // scissor converted through the *rect's* aspect scale but the
        // *scissor's* own origins (rt64_framebuffer_renderer.cpp:1679):
        // untagged, that is the centered 4:3 column, so anything anchored to
        // a true window edge lands outside it. Measured, before this was
        // added: the health cluster was cut off at the column's left edge and
        // the S-BOMB gauge at its right edge.
        //
        // This is a re-expression of the same scissor, not a new one. The
        // game emits G_SETSCISSOR(0, y0, 320, y1) at the top of every frame;
        // RDP::setScissor() applies leftOffset/rightOffset and then
        // movedFromOrigin(), so LEFT with 0 and RIGHT with -320 px give back
        // ulx = 0 and lrx = 320 px unchanged -- bit-identical numbers, with
        // the origins now recorded alongside them. Everything that keys off
        // the scissor *rectangle* (RT64's coversWholeWidth / coversScissorWidth
        // wide-viewport heuristics, and therefore the 3D scene and every
        // full-width fill rect) is untouched; the one thing that changes is
        // that convertFixedRect() now resolves it against the window edges,
        // which is exactly the clip region the relocated HUD needs.
        //
        // Emitted only on frames that actually contain relocated HUD, so
        // the front end -- triangle-based, no rects at all (phase 1 §3.3) --
        // never sees it.
        //
        // The 1 px left bias is not cosmetic, it is required. For an
        // origin-tagged coordinate convertFixedRect() finishes with
        // correctMisalignment(), which subtracts the render target's
        // sub-pixel misalignX -- 2 at 1280x720 (RenderTarget::
        // computeScaledSize: |1280-960|/2 = 160, 160 % 3 = 1, so
        // misalignX = 2). An untagged scissor never goes through that path,
        // but a tagged one whose left edge converts to 0 comes out at -2,
        // and a RenderRect with a negative left reaches setScissors()
        // unclamped for rect draws (the 3D path survives it only because
        // viewportScissorIntersection() clamps it against the viewport
        // first). Measured: with no bias, every relocated element vanished
        // -- gameplay HUD *and* the cutscene radio box -- while the 3D
        // scene rendered normally.
        //
        // One N64 pixel is the provable minimum: the converted left edge is
        // floor(1 * resScale.y) = resScale.y, and misalignX is always in
        // [0, resScale.y - 1], so the result is >= 1 at any resolution. The
        // cost is that HUD clipping starts one N64 pixel in from the window
        // edge, which no element comes near -- the closest, the full-screen
        // flash, is deliberately overdrawn past it (see hud_align_for()).
        //
        // Encoding: gEXSetScissorAlign is a G_EX_COMMAND3 (six u32s).
        // Offsets are 10.2 like gEXSetRectAlign's; the four bounds are read
        // *unsigned* (p0/p1 without an int16_t cast, unlike the offsets), so
        // "no bound" is 0 .. 0xFFFF rather than a negative number.
        p[i++] = 0x64000008u;                                        // G_EX_SETSCISSORALIGN_V1
        p[i++] = (EX_ORIGIN_LEFT & 0xFFFu) | ((EX_ORIGIN_RIGHT & 0xFFFu) << 12);
        p[i++] = uint32_t(uint16_t(int16_t(HUD_SCISSOR_LEFT_BIAS_PX * 4))) << 16;  // ulxOff, ulyOff 0
        p[i++] = uint32_t(uint16_t(int16_t(-320 * 4))) << 16;        // lrxOff -320 px, lryOff 0
        p[i++] = 0x00000000u;                                        // leftBound 0, topBound 0
        p[i++] = 0xFFFFFFFFu;                                        // rightBound/bottomBound: none
    }
    else {
        p[i++] = 0xE0525464u; p[i++] = 0x20000000u;                  // HOOK_OP_DISABLE
    }
    p[i++] = 0xE0525464u; p[i++] = 0x40000000u | (game_dl_addr & 0x0FFFFFFFu); // HOOK_OP_BRANCH -> game DL

    return SCRATCH_BASE;
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
