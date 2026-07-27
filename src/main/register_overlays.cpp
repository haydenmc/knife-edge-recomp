// Registers the recompiled code's section/overlay tables with librecomp.
//
// "recomp_overlays.inl" is always emitted by N64Recomp alongside the
// recompiled .c files (see analysis/docs/n64recomp-formats.md). This
// translation unit's include directory is switched by the top-level
// CMakeLists between KE_GENERATED_DIR and src/stub_game/ depending on
// whether real recompiled output exists yet.

#include "recomp_overlays.inl"

#include "librecomp/overlays.hpp"

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
}
