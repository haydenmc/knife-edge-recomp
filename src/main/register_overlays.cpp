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
#include <array>
#include <atomic>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <unordered_map>
#include <utility>
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

    // --- Stale-tail survival (analysis/docs/timing-and-mission-debug.md §4.2) ---
    //
    // librecomp's unload_overlays() aborts unless the range it is given fully
    // contains every loaded section it overlaps (see
    // deps/N64ModernRuntime/librecomp/src/overlays.cpp), which is why the
    // unload range above is grown to whole-section granularity. Left alone,
    // that means the moment a new image touches ANY byte of an existing
    // section, its ENTIRE function map gets dropped - including a tail the
    // incoming image never writes. On hardware that tail is untouched RAM and
    // stays executable, and a still-live function pointer into it (the
    // mission per-retrace callback at 0x8019CF84) can be called after such a
    // displacement; dropping it made that call unresolvable.
    //
    // The fix: after librecomp erases a displaced section's functions, we
    // re-insert (via the exposed add_loaded_function()) every function whose
    // whole byte range lies outside [new_start, new_end) - the range the
    // incoming DMA actually writes. A function that straddles that boundary
    // is partially overwritten, so it is never re-inserted; a function whose
    // start lies inside the new range is destroyed outright. Re-insertion
    // happens after unload_overlays() and before load_overlays() for the
    // incoming image, so a genuine new function at a reused address always
    // wins the race.
    //
    // librecomp has no API to remove a single func_map entry (only whole
    // sections), which matters for keeping this loud rather than silent and
    // for the "a later load can cover the same tail again" case: every
    // re-inserted address gets a distinct trampoline function (generated via
    // a compile-time index, since recomp_func_t carries no identity of its
    // own) instead of the real function pointer directly. A trampoline can be
    // flipped in place, after publication, between two behaviours:
    //   - Call: forwards to the real function, logging once per displacement
    //     event (not per call) the first time it actually runs.
    //   - Tombstone: a later DMA now covers what used to be a surviving tail;
    //     the trampoline reproduces get_function()'s own
    //     "Failed to find function" fatal diagnostic, so that address can
    //     never again silently resolve to the old, now-destroyed code.
    constexpr size_t kTrampolinePoolSize = 1024;

    struct TrampolineSlot {
        enum class Kind { Unused, Call, Tombstone };
        std::atomic<Kind> kind{ Kind::Unused };
        // Set once, before the slot is published into func_map, and never
        // written again (slots are never recycled) - safe to read from any
        // thread without synchronization once `kind` has been observed.
        recomp_func_t* real_func = nullptr;
        uint32_t vram = 0;
        uint32_t size = 0;
        uint32_t section_rom = 0;
        // Shared by every survivor of the same displacement event; never
        // freed once published (tiny, session-lifetime allocation).
        std::atomic<bool>* event_logged = nullptr;
    };

    std::array<TrampolineSlot, kTrampolinePoolSize> trampoline_slots;
    size_t next_trampoline_slot = 0;   // only touched under overlay_mutex
    bool trampoline_pool_exhausted_warned = false;

    // vram -> pool slot index, for every currently-live Call trampoline, so a
    // later DMA that covers a surviving tail can flip it to Tombstone.
    std::unordered_map<uint32_t, size_t> live_survivor_slots;

    template <size_t I>
    void trampoline_thunk(uint8_t* rdram, recomp_context* ctx) {
        TrampolineSlot& slot = trampoline_slots[I];
        if (slot.kind.load() == TrampolineSlot::Kind::Tombstone) {
            // Mirrors get_function()'s own fatal path exactly: this address
            // used to be resolvable (a surviving tail), but a later load has
            // since overwritten it for real, so it must fail exactly as if it
            // had never been registered.
            std::fprintf(stderr, "Failed to find function at 0x%08X\n", slot.vram);
            assert(false);
            std::exit(EXIT_FAILURE);
        }
        if (!slot.event_logged->exchange(true)) {
            std::fprintf(stderr,
                "[overlays] executing stale-tail function 0x%08X from displaced section (rom 0x%06X) - hardware-faithful but worth knowing\n",
                slot.vram, slot.section_rom);
        }
        slot.real_func(rdram, ctx);
    }

    template <size_t... I>
    constexpr std::array<recomp_func_t*, sizeof...(I)> make_trampoline_table(std::index_sequence<I...>) {
        return { &trampoline_thunk<I>... };
    }

    const std::array<recomp_func_t*, kTrampolinePoolSize> trampoline_table =
        make_trampoline_table(std::make_index_sequence<kTrampolinePoolSize>{});

    // Registers a Call-kind trampoline for one surviving function. Falls back
    // to registering the real function pointer directly if the pool is
    // exhausted (correctness - resolvability - is preserved; only the
    // logging/tombstone diagnostics are lost for that entry).
    void register_survivor(uint32_t vram, uint32_t size, uint32_t section_rom, recomp_func_t* real_func, std::atomic<bool>* event_logged) {
        size_t index = next_trampoline_slot;
        if (index >= kTrampolinePoolSize) {
            if (!trampoline_pool_exhausted_warned) {
                trampoline_pool_exhausted_warned = true;
                std::fprintf(stderr, "[overlays] trampoline pool exhausted - stale-tail diagnostics disabled for further survivors\n");
            }
            recomp::overlays::add_loaded_function(static_cast<int32_t>(vram), real_func);
            return;
        }
        ++next_trampoline_slot;

        TrampolineSlot& slot = trampoline_slots[index];
        slot.real_func = real_func;
        slot.vram = vram;
        slot.size = size;
        slot.section_rom = section_rom;
        slot.event_logged = event_logged;
        slot.kind.store(TrampolineSlot::Kind::Call);

        live_survivor_slots[vram] = index;
        recomp::overlays::add_loaded_function(static_cast<int32_t>(vram), trampoline_table[index]);
    }

    const SectionTableEntry* section_entry_by_rom(uint32_t rom) {
        SectionTableEntry* begin = section_table;
        SectionTableEntry* end = section_table + ARRLEN(section_table);
        auto it = std::lower_bound(begin, end, rom,
            [](const SectionTableEntry& entry, uint32_t addr) { return entry.rom_addr < addr; });
        if (it != end && it->rom_addr == rom) {
            return &*it;
        }
        return nullptr;
    }

    // For a section librecomp is about to fully unload (because the incoming
    // DMA only partially covers it - see above), re-register whichever of its
    // functions lie wholly outside [new_start, new_end), the range of bytes
    // the DMA actually writes. Must run after unload_overlays() has erased
    // the section's entries and before load_overlays() installs the incoming
    // image, so a real new function at a reused address always wins.
    void preserve_surviving_tail(const LoadedSection& s, int64_t new_start, int64_t new_end) {
        const SectionTableEntry* section = section_entry_by_rom(s.rom);
        if (section == nullptr) {
            return;   // defensive; should not happen, sections_covered_by sourced s.rom from this same table
        }

        std::atomic<bool>* event_logged = new std::atomic<bool>(false);
        bool any_survivor = false;

        for (size_t i = 0; i < section->num_funcs; ++i) {
            const FuncEntry& func = section->funcs[i];
            int64_t fstart = static_cast<int64_t>(s.ram) + func.offset;
            int64_t fend = fstart + func.rom_size;

            // A function survives only if its ENTIRE range misses the newly
            // written bytes. Comparing the whole range (not just fstart)
            // means a function that starts in the surviving tail but runs
            // into the new image - the straddling case - is still destroyed,
            // matching partially-overwritten code. In this game every load
            // shares its target section's own base address, so fstart is
            // never below new_start and the simpler "does fstart fall inside
            // the new range" test would agree; the full-range test is used
            // anyway because it stays correct even if that stopped holding.
            bool fully_outside = fend <= new_start || fstart >= new_end;
            if (!fully_outside) {
                continue;
            }

            register_survivor(static_cast<uint32_t>(fstart), func.rom_size, s.rom, func.func, event_logged);
            any_survivor = true;
        }

        if (!any_survivor) {
            delete event_logged;   // never published anywhere; nothing will ever read it
        }
    }

    // Flips any currently-live surviving-tail trampoline whose function now
    // falls (even partially) inside [new_start, new_end) to Tombstone, so a
    // later call into it fails loudly instead of resolving to code this DMA
    // has since overwritten. Runs on every DMA, independent of whichever
    // sections are being displaced this time (constraint: multiple partial
    // displacements of the same original section must keep working).
    void tombstone_covered_survivors(int64_t new_start, int64_t new_end) {
        for (auto it = live_survivor_slots.begin(); it != live_survivor_slots.end();) {
            TrampolineSlot& slot = trampoline_slots[it->second];
            int64_t fstart = static_cast<int64_t>(slot.vram);
            int64_t fend = fstart + slot.size;
            bool fully_outside = fend <= new_start || fstart >= new_end;
            if (!fully_outside) {
                slot.kind.store(TrampolineSlot::Kind::Tombstone);
                it = live_survivor_slots.erase(it);
            }
            else {
                ++it;
            }
        }
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
// and librecomp treats that as fatal. Rather than dropping the whole displaced
// section, whichever of its functions lie entirely outside the bytes this DMA
// actually writes are kept resolvable (hardware-faithful: that RAM is
// untouched) via the stale-tail trampoline machinery above; see
// analysis/docs/timing-and-mission-debug.md section 4.2 for the failure this
// fixes and the straddling-function reasoning.
extern "C" void ke_overlay_dma(uint32_t rom, int32_t ram, uint32_t size) {
    std::lock_guard lock{ overlay_mutex };

    const int64_t new_start = ram;
    const int64_t new_end = static_cast<int64_t>(ram) + size;

    // A previously-preserved stale-tail function that this DMA now actually
    // overwrites must stop resolving to its old code, independent of whatever
    // else this call displaces.
    tombstone_covered_survivors(new_start, new_end);

    int32_t start = ram;
    int64_t end = new_end;
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
        // Capture which sections are about to be dropped before erasing them
        // so their surviving tails - measured against the DMA's real
        // [new_start, new_end), not the (possibly larger) grown unload range
        // above - can be re-registered afterwards.
        std::vector<LoadedSection> displaced;
        for (const LoadedSection& s : loaded_shadow) {
            if (overlaps(s, start, end)) {
                displaced.push_back(s);
            }
        }

        unload_overlays(start, static_cast<uint32_t>(end - start));
        loaded_shadow.erase(
            std::remove_if(loaded_shadow.begin(), loaded_shadow.end(),
                [&](const LoadedSection& s) { return overlaps(s, start, end); }),
            loaded_shadow.end());

        for (const LoadedSection& s : displaced) {
            preserve_surviving_tail(s, new_start, new_end);
        }
    }

    load_overlays(rom, ram, size);
    for (const LoadedSection& s : sections_covered_by(rom, ram, size)) {
        loaded_shadow.push_back(s);
    }
}
