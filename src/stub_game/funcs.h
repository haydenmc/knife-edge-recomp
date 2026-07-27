// Stub placeholder for N64Recomp's generated `funcs.h`.
//
// When a real config.toml is recompiled with N64Recomp (see
// analysis/docs/n64recomp-formats.md), this file is generated automatically
// with one `extern`-C declaration per recompiled function, wrapped exactly
// like this. This hand-written version declares only the one function this
// skeleton needs: the entrypoint stub in recomp_entrypoint.c.
//
// Do not hand-edit this once KE_GENERATED_DIR points at real output --- this
// whole directory (src/stub_game/) is only used when KE_GENERATED_DIR is
// unset.

#include "recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);

#ifdef __cplusplus
}
#endif
