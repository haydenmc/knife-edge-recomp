# Analysis pipeline spec (ROM → knife_edge.us.syms.toml)

Target: emit a symbols TOML per `n64recomp-formats.md` §2 covering every loaded code
segment from `analysis/out/segments.json`, such that N64Recomp runs with zero
"No function found for jal target" errors.

Inputs: `build/knife_edge.z64`, `analysis/out/segments.json`, n64sym binary
(`deps/n64sym/bin/n64sym`). Python: `.venv/bin/python` (rabbitizer, tomlkit).

## Stage 1 — find_functions.py

Per code segment (kind == "code"):

1. **Linear sweep** with rabbitizer over the whole segment; harvest:
   - direct call targets (`jal` — high confidence function starts),
   - branch targets (intra-function, used for boundary sanity),
   - `jr $ra` sites (return points), `jr $reg` (jump tables / tail calls).
2. **Jump-table harvesting**: scan segment *data* and code-adjacent rodata for runs of
   ≥3 big-endian words that all land word-aligned inside the same segment's code
   range; treat entries as branch targets (not function starts) unless also jal'd.
   Also detect `lui/addiu` pairs that materialize in-segment code addresses —
   candidates for function pointers → mark as function starts.
3. **Boundary construction**: sort starts; a function runs to the next start.
   Refine: a function must end at/after its last reachable instruction; trailing
   nops before the next start belong to the earlier function (padding). If a region
   between functions is never targeted and fails validity, mark it data-in-text and
   exclude (record in report).
4. **Entrypoint**: force a function at segment start when segment.rom == 0x1000
   (vram 0x800C2400) so N64Recomp's entrypoint rename works.
5. Prologue heuristic (`addiu $sp,$sp,-N` / `sw $ra`) is a *tiebreaker* only —
   leaf functions lack it.

Output: `analysis/out/functions.json`: per segment, sorted
`[{"vram": …, "size": …, "how": "jal|ptr|table|gap"}]` + a stats block
(counts, unclaimed gaps with sizes).

## Stage 2 — ident_libultra.py

1. Synthesize a RAM image (0x80000000-based) with every code segment placed at its
   vram; run n64sym `-s -t -f splat` on it.
2. **Filter false positives**: accept a hit only if (a) its vram is a detected
   function start from Stage 1 (or ±0 after alignment), and (b) the name is
   plausible for a 1998 libultra game — drop `osBb*`, `leo*` (64DD), `rmon*`
   unless corroborated; on duplicate names at different vrams keep the better
   structural match (same-name collision ⇒ prefer the one whose size/neighbors
   match libultra ordering, else drop both and record).
3. Cross-check the handful of runtime-critical names (osRecvMesg/osSendMesg,
   osCreateThread/osStartThread, osPiStartDma/osEPiStartDma, osSpTaskLoad/Yield,
   osViSwapBuffer, osAiSetNextBuffer, osContInit/osContStartReadData, osGetCount,
   osInvalDCache/osWritebackDCache, __osException) by structure (e.g. osGetCount is
   `mfc0 v0, Count; jr ra; nop`). These MUST be right; anything else mislabeled is
   recoverable later.
4. Output: `analysis/out/libultra_names.json` `{vram: name}` + a confidence report
   listing accepted/rejected hits.

## Stage 3 — gen_syms.py

1. Merge: functions.json + libultra_names.json → named functions
   (`func_{vram:08X}` for unnamed).
2. Emit `config/knife_edge.us.syms.toml` with one `[[section]]` per loaded segment
   (+ BSS section with `functions = []`), using tomlkit.
   Word-alignment invariants asserted. No `relocs` unless segments.json marks a
   segment relocatable.
3. Emit `config/knife_edge.us.toml` main config per formats doc §1 (entrypoint
   0x800C2400, rom_file_path pointing at build/knife_edge.z64 via relative path,
   output_func_path build/RecompiledFuncs, functions_per_output_file 50).

## Acceptance

- `deps/N64Recomp/build/N64Recomp config/knife_edge.us.toml` exits 0.
- Every jal target resolves (no NoMatch aborts). Iterate stage 1 rules if not.
- Runtime-critical libultra names present and structurally verified.
