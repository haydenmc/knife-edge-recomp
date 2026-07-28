# Overlay tracking design (decided 2026-07-27)

> **Superseded in part on 2026-07-28** - the hook now calls
> `ke_overlay_dma()` (src/main/register_overlays.cpp) rather than librecomp's
> `unload_overlays`/`load_overlays` pair directly, and librecomp's first-1MB
> registration has to be undone at the entrypoint. Both reasons, with the
> failure modes that forced them, are in `boot-debug.md` §3.

Problem: the game swaps fixed-address code overlays (69 loads, shared VRAM slots) via
its own loaders; librecomp only registers the boot 1MB (`recomp.cpp:486`) and its PI DMA
(`pi.cpp do_dma`) does NOT update the overlay function map.

Decision: single `[[patches.hook]]` on the game's DMA primitive `func_800D1D10(devAddr,
dramAddr, size)` (every ROM→RAM load funnels through it — see segment_map.md):

```toml
[[patches.hook]]
func = "func_800D1D10"
# before_vram omitted → hook at function start (registration order vs byte copy is
# irrelevant; the tables don't read rdram bytes)
text = "unload_overlays((int32_t)ctx->r5, (uint32_t)ctx->r6); load_overlays((uint32_t)ctx->r4, (int32_t)ctx->r5, (uint32_t)ctx->r6);"
```

plus `recomp_include` extended with the two extern decls (librecomp exports them
`extern "C"`: `load_overlays(uint32_t rom, int32_t ram, uint32_t size)`,
`unload_overlays(int32_t ram, uint32_t size)`).

Why it's correct:
- `load_overlays` binary-searches the generated code-section table by ROM range —
  data/audio DMAs match nothing and no-op.
- `unload_overlays` first evicts func_map entries overlapping [ram, ram+size), then
  `load_overlays` installs the new section's functions ⇒ identical to hardware
  semantics where the DMA overwrites the bytes. Stale tails beyond a shorter new
  image match hardware (old code still resident) — acceptable.
- Boot registration at startup is unaffected.

Caveat: verify at integration that a0 really carries the ROM offset (descriptor
romStart, e.g. 0x1501A0) rather than a KSEG1/phys 0xB0000000-based address; if the
latter, mask with `& 0x1FFFFFFF` in the hook text.
