// Stub placeholder for N64Recomp's generated `recomp_overlays.inl`.
//
// Real output (see analysis/docs/n64recomp-formats.md) declares one
// `section_table[]` entry per code section plus `num_sections` and
// `overlay_sections_by_index[]`, in exactly this shape. This skeleton has no
// recompiled sections yet, so the tables are empty --- `register_overlays()`
// in src/main/register_overlays.cpp is happy to register zero sections, and
// `recomp::GameEntry::entrypoint` is wired directly to the stub in
// recomp_entrypoint.c rather than being looked up through this table.
//
// This file is only used when KE_GENERATED_DIR is unset; do not hand-edit it
// once real generated output exists.

#include "funcs.h"
#include "librecomp/sections.h"

static SectionTableEntry section_table[] = {
};

const size_t num_sections = 0;

static int overlay_sections_by_index[] = {
    -1,
};
