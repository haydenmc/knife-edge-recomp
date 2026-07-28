// Registers the recompiled code's section/overlay tables with librecomp, and
// owns this project's overlay bookkeeping (see analysis/docs/overlay-tracking.md
// and analysis/docs/boot-debug.md).
//
// "recomp_overlays.inl" is always emitted by N64Recomp alongside the
// recompiled .c files (see analysis/docs/n64recomp-formats.md). This
// translation unit's include directory is switched by the top-level
// CMakeLists between KE_GENERATED_DIR and src/stub_game/ depending on
// whether real recompiled output exists yet.

#include <algorithm>
#include <cstdio>
#include <mutex>
#include <vector>

#include "recomp_overlays.inl"

#include "librecomp/overlays.hpp"

namespace {
    // librecomp's init() unconditionally does load_overlays(0x1000, entrypoint,
    // 1MB) before calling the game entrypoint. That is correct for games whose
    // overlays all live past the first megabyte of ROM, but six of Knife Edge's
    // code segments (rom 0x02FC30 .. 0x0F4810) sit *inside* it, so they get
    // registered at bogus addresses (section rom_addr + 0x800C1400) that no
    // game DMA will ever unload. The first real overlay DMA then trips
    // librecomp's "Cannot partially unload section" abort.
    constexpr uint32_t boot_rom = 0x1000;
    constexpr uint32_t boot_window_size = 1024 * 1024;

    struct LoadedSection {
        uint32_t rom;
        int32_t ram;
        uint32_t size;
    };

    // Mirrors librecomp's internal `loaded_sections`, which it does not expose.
    // We need it because unload_overlays() aborts unless the range it is given
    // fully contains every section it overlaps, and Knife Edge reuses one VRAM
    // slot (0x8017B0C0) for eight overlays of different sizes.
    std::vector<LoadedSection> loaded_shadow;
    std::mutex overlay_mutex;

    // The same selection librecomp's load_overlays() performs. The section
    // table is sorted by rom_addr (init_overlays() sorts our array in place),
    // so a DMA covers the sections in [lower_bound(rom), upper_bound(rom+size)).
    std::vector<LoadedSection> sections_covered_by(uint32_t rom, int32_t ram, uint32_t size) {
        SectionTableEntry* begin = section_table;
        SectionTableEntry* end = section_table + ARRLEN(section_table);

        auto lower = std::lower_bound(begin, end, rom,
            [](const SectionTableEntry& entry, uint32_t addr) { return entry.rom_addr < addr; });
        auto upper = std::upper_bound(begin, end, rom + size,
            [](uint32_t addr, const SectionTableEntry& entry) { return addr < entry.size + entry.rom_addr; });

        std::vector<LoadedSection> out;
        for (auto it = lower; it != upper; ++it) {
            out.push_back({ it->rom_addr,
                            static_cast<int32_t>(it->rom_addr - rom + static_cast<uint32_t>(ram)),
                            it->size });
        }
        return out;
    }

    // Exactly librecomp's predicate in unload_overlays():
    //   ram_addr < loaded_ram + size  &&  ram_addr + size >= loaded_ram
    // Note the `>=`: a section starting exactly where the unloaded range ends
    // still counts as overlapping, so our growth loop has to agree or we hand
    // librecomp a range it considers partial.
    bool overlaps(const LoadedSection& s, int32_t start, int64_t end) {
        return static_cast<int64_t>(start) < static_cast<int64_t>(s.ram) + s.size &&
               end >= static_cast<int64_t>(s.ram);
    }
}

namespace kerecomp {
    void register_overlays() {
        recomp::overlays::overlay_section_table_data_t sections {
            .code_sections = section_table,
            .num_code_sections = ARRLEN(section_table),
            .total_num_sections = num_sections,
        };

        recomp::overlays::overlays_by_index_t overlays {
            .table = overlay_sections_by_index,
            .len = ARRLEN(overlay_sections_by_index),
        };

        recomp::overlays::register_overlays(sections, overlays);
    }

    // Runs from the entrypoint wrapper, i.e. after librecomp's init() has done
    // its first-1MB registration and before any game code executes. Drops every
    // section that registration placed at a bogus address and seeds the shadow
    // list with the one section that really is resident: boot.
    void reset_boot_window_overlays() {
        std::lock_guard lock{ overlay_mutex };
        loaded_shadow.clear();

        // librecomp used `(int32_t)game_entry.entrypoint_address` as the ram
        // base, which is the boot section's own ram_addr.
        const int32_t entrypoint_ram = static_cast<int32_t>(section_table[0].ram_addr);
        for (const LoadedSection& s : sections_covered_by(boot_rom, entrypoint_ram, boot_window_size)) {
            if (s.rom == boot_rom) {
                loaded_shadow.push_back(s);     // boot really is resident
            }
            else {
                std::fprintf(stderr,
                    "[overlays] dropping first-1MB registration of rom 0x%06X (bogus ram 0x%08X)\n",
                    s.rom, static_cast<uint32_t>(s.ram));
                unload_overlays(s.ram, s.size);
            }
        }
    }
}

// Hooked into the game's single ROM->RAM DMA primitive (func_800D1D10) by
// analysis/gen_syms.py. Replaces the naive
// `unload_overlays(ram, size); load_overlays(rom, ram, size);` pair: the unload
// range is first grown to whole-section granularity, because a smaller overlay
// landing in a slot that currently holds a larger one only partially covers it
// and librecomp treats that as fatal. Dropping the whole displaced section is
// the closest representable behaviour - its tail bytes survive in rdram exactly
// as on hardware, but the game never calls into a half-overwritten overlay.
// (That last clause has a known counter-example on the mission-completion path;
// see analysis/docs/timing-and-mission-debug.md section 4.2.)
extern "C" void ke_overlay_dma(uint32_t rom, int32_t ram, uint32_t size) {
    std::lock_guard lock{ overlay_mutex };

    int32_t start = ram;
    int64_t end = static_cast<int64_t>(ram) + size;
    bool grew = true;
    while (grew) {
        grew = false;
        for (const LoadedSection& s : loaded_shadow) {
            if (overlaps(s, start, end)) {
                if (s.ram < start) { start = s.ram; grew = true; }
                if (static_cast<int64_t>(s.ram) + s.size > end) { end = static_cast<int64_t>(s.ram) + s.size; grew = true; }
            }
        }
    }

    if (end > start) {
        unload_overlays(start, static_cast<uint32_t>(end - start));
        loaded_shadow.erase(
            std::remove_if(loaded_shadow.begin(), loaded_shadow.end(),
                [&](const LoadedSection& s) { return overlaps(s, start, end); }),
            loaded_shadow.end());
    }

    load_overlays(rom, ram, size);
    for (const LoadedSection& s : sections_covered_by(rom, ram, size)) {
        loaded_shadow.push_back(s);
    }
}
