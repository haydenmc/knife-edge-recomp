# N64Recomp input formats — project reference

Extracted from deps/N64Recomp source (src/config.cpp, src/symbol_lists.cpp, src/main.cpp,
src/recompilation.cpp) and deps/N64ModernRuntime (librecomp). Verified 2026-07-27.

## Main config TOML (passed as argv[1] to N64Recomp)

Relative paths resolve against the config file's own directory.

```toml
[input]
entrypoint = 0x800C2400            # must match a functions[] entry whose ROM offset is exactly 0x1000
symbols_file_path = "knife_edge.us.syms.toml"
rom_file_path = "…/knife_edge.z64" # function words are read from here at section rom offsets
output_func_path = "…/RecompiledFuncs"
# optional: relocatable_sections_path, single_file_output=false,
# functions_per_output_file=50, recomp_include, trace_mode

[patches]
stubs = []      # emitted as no-op bodies (names must exist)
ignored = []    # no C emitted at all (you provide impl elsewhere)
renamed = []    # emitted as <name>_recomp

[[patches.instruction]]           # overwrite an instruction word pre-recompile
func = "some_func"
vram = 0x80012340
value = 0x00000000

[[patches.hook]]                  # inject raw C before instruction at before_vram
func = "some_func"
before_vram = 0x80012350
text = "ctx->r4 = 0;\n"
```

## Symbols TOML (symbols_file_path — what gen_syms.py must emit)

```toml
[[section]]
name = "boot"
rom = 0x1000          # word-aligned; rom + (func.vram - section.vram) = func's ROM offset
vram = 0x800C2400     # word-aligned
size = 0x2CB50
functions = [
    { name = "recomp_entrypoint_fn", vram = 0x800C2400, size = 0x40 },
    { name = "osRecvMesg",           vram = 0x…,        size = 0x… },
]
# relocs = [...]  # ONLY for relocatable overlays; presence of the key marks the
#                 # section relocatable. Types: R_MIPS_HI16/LO16/26/32 with
#                 # { vram, target_vram, type }.
```

- No data symbols exist in this mode; data is referenced by raw addresses.
- BSS sections: list with functions = [] (rom key still required, word-aligned).

## Function coverage rules (src/recompilation.cpp resolve_jal)

- `jal` to an unlisted address **inside the same section** → auto-creates
  `static_{sec}_{vram}` bounded by next known function. Small local helpers may be
  omitted if only reached this way.
- `jal` to an address with **no match in any section** → HARD ERROR (abort).
- Ambiguous cross-section match → runtime lookup fallback (warning only).
- Functions reached only via function pointers/jump tables must be listed so they
  exist in the lookup table. **Practical rule: list every detected function.**

## libultra handling is automatic (src/symbol_lists.cpp)

In symbols-file mode, functions whose *names* match the hard-coded sets are handled
without any config:
- `reimplemented_funcs` (osInitialize, osRecvMesg, osSendMesg, osSpTaskLoad,
  osContInit, osPiStartDma, osCartRomInit, osCreateThread, osGetCount, …):
  declared as `<name>_recomp` extern, body provided by librecomp.
- `ignored_funcs` (~250: exception handlers, TLB, PI/SI internals, rmon, inflate…):
  nothing emitted.
- `renamed_funcs` (memcpy, sprintf, malloc, sqrt, sinf, __divdi3, setjmp…):
  recompiled but emitted as `<name>_recomp`.

⇒ ident_libultra.py just has to assign the exact original names at the right vrams.
Wrong/missing names = the recompiled body races librecomp's HLE (or duplicates it).

## Entrypoint / runtime contract (librecomp)

- N64Recomp renames the function at (vram==entrypoint, rom==0x1000) to `recomp_entrypoint`;
  errors out if absent.
- Game project registers `recomp::GameEntry{ rom_hash, internal_name, game_id,
  save_type, is_enabled, entrypoint = recomp_entrypoint, entrypoint_address, … }`
  via `recomp::register_game`. librecomp DMAs the first 1MB, sets osTvType/osRomBase/
  osMemSize, then calls the entrypoint.
- Generated `recomp_overlays.inl` (always emitted) must be included and passed to
  `recomp::overlays::register_overlays(...)`.
- ABI everywhere: `void fn(uint8_t* rdram, recomp_context* ctx)`.

## RSPRecomp config (flat TOML, one per microcode)

```toml
text_offset = 0x…        # ROM offset of ucode text
text_size = 0x…
text_address = 0x0       # IMEM address
rom_file_path = "…"
output_file_path = "aspMain.c"
output_function_name = "aspMain"
# optional: extra_indirect_branch_targets = [..], unsupported_instructions = [..],
# [[overlay_slots]] { text_address, [[overlay_slots.overlays]] { offset, size } }
```

## Knife Edge established facts

- CIC 6102; boot: ROM 0x1000 → 0x800C2400, size ≈ 0x2CB50; BSS 0x800EEF50 +0x7BC98;
  boot proc 0x800CD6B0; stack top 0x80126A60.
- Second dense code region in ROM ≈ 0x151000–0x180000 (mapping: see
  analysis/out/segment_map.md once generated).
- Ucodes: F3DEX 2.05 fifo + F3DLX.Rej 2.05 fifo (gfx); audio ucode TBD.
- n64sym (deps/n64sym) gives seed libultra names from a synthesized RAM image but
  has false positives — validate before trusting.
