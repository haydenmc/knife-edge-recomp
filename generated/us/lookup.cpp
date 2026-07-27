#include "recomp.h"
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);

gpr get_entrypoint_address() { return (gpr)(int32_t)0x800C2400u; }

const char* get_rom_name() { return ".z64"; }

