#!/usr/bin/env python3
"""Stage 3 of the ROM -> symbols pipeline: emit the N64Recomp TOML inputs.

Merges analysis/out/functions.json with analysis/out/libultra_names.json and
writes:

  config/knife_edge.us.syms.toml   one [[section]] per loaded code segment plus
                                   the boot .bss section (functions = [])
  config/knife_edge.us.toml        the main N64Recomp config

Naming: a function keeps its libultra name when stage 2 assigned one, otherwise
it becomes `func_{vram:08X}` in the boot segment and `func_{vram:08X}_{rom:06X}`
elsewhere.  The ROM suffix is required because six mission overlays are all
based at 0x801D21F0 and eight menu overlays at 0x8017B0C0, so bare VRAM names
would collide - and N64Recomp emits one C function per symbol name, so a
collision is a duplicate C definition.

Section extents use the segment's *ROM* size, not the descriptor's vramEnd: the
.bss tail carries no functions, and a section that stops at the end of the DMA'd
image keeps `rom + (vram - section.vram)` inside the ROM for every function.
No `relocs` key is emitted anywhere - segment_map.md §c establishes that all 69
loads are to fixed addresses with no relocation pass.
"""

import argparse
import json
import os
import sys

import tomlkit

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ident_libultra import load_symbol_lists, DEFAULT_SYMLISTS  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_FUNCS = os.path.join(ROOT, "analysis", "out", "functions.json")
DEFAULT_NAMES = os.path.join(ROOT, "analysis", "out", "libultra_names.json")
DEFAULT_SEGMENTS = os.path.join(ROOT, "analysis", "out", "segments.json")
DEFAULT_CONFIG_DIR = os.path.join(ROOT, "config")
DEFAULT_REPORT = os.path.join(ROOT, "analysis", "out", "syms_report.txt")

ENTRYPOINT = 0x800C2400
SYMS_NAME = "knife_edge.us.syms.toml"
CONFIG_NAME = "knife_edge.us.toml"

# Paths written into the config, relative to config/ (N64Recomp resolves
# relative paths against the config file's own directory).
REL_ROM = "../build/knife_edge.z64"
# Generated recompiled code is committed (functional RE output policy) so CI can
# build without the ROM. Regenerating requires the ROM at build/knife_edge.z64.
REL_OUT = "../generated/us"


# Extra busy-wait yield hooks, for loops find_functions.find_spin_loops() does
# not recognise.  Entries are (segment name, function vram, hook vram, why).
#
# find_spin_loops() only accepts a *straight-line* loop body (no branch other
# than the back-edge) so that it can prove the loop cannot reach an OS
# primitive.  The in-game overlay's mission loop is the one place in this game
# where the wait and the work share a loop: the body is 53 instructions with the
# per-frame work behind `if (state.flags & 1)`, and when that bit is clear the
# executed cycle is just `lbu; andi; beqz -> lw 0x8011D1B4; beqz` - a pure poll
# with no yield, which wedged ultramodern's cooperative scheduler on mission
# start.  Relaxing the detector to reason about paths instead of whole bodies
# was tried and rejected: it also matches every memcpy/strlen/table-scan loop in
# the ROM (_bcopy, memcpy, _bcmp, alCopy, __osSumcalc, ...), and a 1 ms yield in
# those is a large, silent slowdown.  The audit behind this entry is in
# analysis/docs/timing-and-mission-debug.md; all three back-edges of the loop
# (0x8019CF28 / 0x8019CF3C / 0x8019CF54) target 0x8019CE5C, so one hook covers
# them.
# The same function contains a *second*, inner loop: the cutscene fast-forward.
# When the player asks to skip a cutscene (func_8016E454 sets bit 0 of
# 0x8011D1D8+0xE), func_8019CE04 deregisters the per-retrace callback and runs
# the world logic-only, looping back to 0x8019CE84 for as long as a cutscene is
# playing (0x8011D298 != 0) or the "cutscene armed" flag is set
# (*(u16*)0x8011D458 & 0x4000).  Its two back-edges (0x8019CEDC / 0x8019CEF0)
# target 0x8019CE84, *not* the outer loop head at 0x8019CE5C, so the hook above
# does not cover it and the thread never re-enters an OS primitive.
EXTRA_SPIN_YIELD_HOOKS = [
    ("seg_1501A0", 0x8019CE04, 0x8019CE5C,
     "mission loop: polls the frame-ready bit at 0x8011D1D8+0xE and the "
     "screen-result word at 0x8011D1B4 (find_spin_loops needs a "
     "straight-line body; this one is 53 instructions with the per-frame "
     "work behind a branch)"),
    ("seg_1501A0", 0x8019CE04, 0x8019CE84,
     "mission loop, inner cutscene fast-forward: back-edges 0x8019CEDC and "
     "0x8019CEF0 re-run the logic-only frame step from here while a cutscene "
     "is playing, with no OS primitive on the path"),
]


# RCP frame-time model (analysis/docs/timing-and-mission-debug.md).
#
# The game advances exactly one logic step per *rendered* frame and skips a
# retrace whenever a graphics task is still in flight, so its speed is set by
# how long the RCP takes.  librecomp+RT64 retire a graphics task essentially
# instantly, which made every retrace produce a step (60/s instead of 15/s).
#
# func_800D25F0 is the graphics task thread (it receives from the task queue at
# 0x801423EC, does the double-buffer wait in func_800D2768, runs the task and
# then posts completion, which is what decrements the outstanding-task counter
# at 0x8013C280 that the per-retrace callback tests).  Bracketing the task with
# these two hooks gives it a realistic minimum residency.
#
# Entries are (segment name, function vram, hook vram, C text, why).
RCP_PACING_HOOKS = [
    ("boot", 0x800D25F0, 0x800D26D0, "ke_gfx_task_begin();",
     "osSpTaskStartGo: the RCP has just been handed this display list"),
    ("boot", 0x800D25F0, 0x800D2728, "ke_gfx_task_end(rdram);",
     "hold the completion message until the modelled RCP frame time elapsed"),
]


# Extended aim range (analysis/docs/hud-relocation.md, "Reticle range
# extension"; implementation in src/main/extended_aim.cpp).
#
# The aiming reticle is an integrator the game clamps to +-128 / +-84 N64
# pixels every frame, which is 80% of the half-width and 70% of the half-height
# of the original 4:3 / 320x200 view.  With `widescreen` and `full_height` on
# there is visibly more frame than the reticle can reach.  Four hooks widen it,
# all of them no-ops unless the enhancement resolves to a wider rail:
#
#   A. the clamp, in func_8016E520_1501A0's tail (0x8016EC30..0x8016ECEC: four
#      load / slti / conditional-store blocks against 0x81 / -0x80 / 0x55 /
#      -0x54, on the SoA at 0x8011D458 + slot*4, X at +0x64 and Y at +0x74).
#      A hook at the head of the block stashes the *unclamped* pair for this
#      slot; a hook on the `jr $ra` at 0x8016ECF0 re-clamps the stash to our own
#      rails and stores it back.  The pair, rather than one hook per slti site,
#      because its correctness argument is global instead of per-site; the stash
#      validity flag is what makes the three early exits that also land on
#      0x8016ECF0 (the recentre path's `b`, and the two `bne` at 0x8016E720 /
#      0x8016E734) safe -- they never set a stash, so the exit hook does
#      nothing.  With the enhancement off the entry hook returns on one atomic
#      load and the game's own clamp is the only clamp.
#
#   B. the aim ray needs no hook at all: func_8019C1D0_1501A0 maps the same two
#      integers to a direction with atan2(pixel, 120/tan(FOV/2)), which is the
#      rendering frustum's own focal length -- unbounded, monotone, and still
#      registered with RT64's `Expand` widening past the original rails.
#
#   C. the draw.  func_800C6C6C is the game's generic 2D sprite blit and the
#      reticle's only draw path (func_801757A0_1501A0 tail: spMove x = X + 144).
#      Every call re-asserts a *software* clip box of (0,0)-(319,239) through
#      the sprite library's spScissor, and spX2Draw clips the rect to it (and
#      drops it entirely once it leaves), which is what stopped a poked
#      out-of-range reticle at exactly N64 x = 0 / 320 -- not the RDP scissor,
#      so hud_relocation's widened scissor did not lift it.  The entry hook
#      shifts the reticle's x by a bias B >= 0 so the emitted texrect stays
#      non-negative (G_TEXRECT coordinates are 12-bit *unsigned* 10.2), and
#      marks the next spScissor as the reticle's; the callee hook on spScissor
#      substitutes the widened box for that one call only.  The bias is undone
#      at draw time by the reticle's hud_relocation stub
#      (src/main/rt64_render_context.cpp), which is why the horizontal half of
#      this enhancement is gated on hud_relocation.
#
#   The spScissor hook has to be on the callee, not the call site: a3 (lry) is
#   assigned in the `jal`'s delay slot at 0x800C6D0C and N64Recomp emits delay
#   slots *before* the call, so a `before_vram = 0x800C6D08` hook would be
#   overwritten -- the trap letterbox-full-height.md section 7 records.
#
# Entries are (segment name, function vram, hook vram or None for an entry
# hook, C text, why).
EXTENDED_AIM_HOOKS = [
    ("seg_1501A0", 0x8016E520, 0x8016EC30,
     "ke_reticle_clamp_stash(rdram, (uint32_t)ctx->r4);",
     "reticle clamp: stash the unclamped X/Y for slot $a0 before the game's "
     "four slti blocks (0x8016EC44/0x8016EC74/0x8016ECA4/0x8016ECD4) run"),
    ("seg_1501A0", 0x8016E520, 0x8016ECF0,
     "ke_reticle_clamp_apply(rdram);",
     "reticle clamp: re-clamp the stashed pair to the resolved rails and store "
     "it back, on the `jr $ra` every path exits through"),
    ("boot", 0x800C6C6C, None,
     "ctx->r5 = (int32_t)ke_reticle_blit_x(rdram, (uint32_t)ctx->r4, "
     "(int32_t)ctx->r5);",
     "generic 2D sprite blit: bias the reticle's x (a1) so its texrect stays "
     "non-negative, and mark the spScissor this call is about to make"),
    ("boot", 0x800D3D84, None,
     "ctx->r5 = (int32_t)ke_sprite_scissor_lrx((int32_t)ctx->r5);",
     "sprite-library scissor: substitute a widened lrx (a1) for the marked "
     "reticle blit only, so spX2Draw stops clipping it at N64 x = 320"),
]


# Spin-yield hooks whose body is something other than the default
# `yield_self_1ms(rdram);`.  Keyed by (segment name, function vram).
SPIN_YIELD_TEXT_OVERRIDES = {
    # func_800D2B40 is the "wait until 0x8013C280 == 0" rendezvous that
    # func_800D1640 runs before it swaps the per-retrace callback pointer.
    # Modelling RCP frame time (RCP_PACING_HOOKS above) keeps that counter
    # non-zero for essentially the whole frame, and ultramodern only ever hands
    # execution to a *higher* priority thread, so a waiting thread is resumed
    # exactly when the retrace-callback thread blocks - just after it queued the
    # next task.  The default yield therefore never terminates this loop.
    # ke_rcp_idle_wait() yields identically and publishes "someone is waiting",
    # which ke_gfx_task_end() uses to retire the in-flight task at once.
    # See analysis/docs/timing-and-mission-debug.md section 5.
    ("boot", 0x800D2B40): "ke_rcp_idle_wait(rdram);",
}


def hexint(v):
    return tomlkit.value("0x%08X" % v)


def hexint6(v):
    return tomlkit.value("0x%06X" % v)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--functions", default=DEFAULT_FUNCS)
    ap.add_argument("--names", default=DEFAULT_NAMES)
    ap.add_argument("--segments", default=DEFAULT_SEGMENTS)
    ap.add_argument("--config-dir", default=DEFAULT_CONFIG_DIR)
    ap.add_argument("--report", default=DEFAULT_REPORT)
    ap.add_argument("--rom-path", default=REL_ROM)
    ap.add_argument("--output-func-path", default=REL_OUT)
    ap.add_argument("--functions-per-file", type=int, default=50)
    ap.add_argument("--symbol-lists", default=DEFAULT_SYMLISTS)
    ap.add_argument("--no-bss", action="store_true",
                    help="omit the boot .bss section entry")
    ap.add_argument("-q", "--quiet", action="store_true")
    args = ap.parse_args(argv)

    funcs = json.load(open(args.functions))
    names_doc = json.load(open(args.names))
    names = names_doc.get("segments", {})
    segments_raw = json.load(open(args.segments))
    bss = next((s for s in segments_raw if s.get("kind") == "bss"), None)

    os.makedirs(args.config_dir, exist_ok=True)

    doc = tomlkit.document()
    doc.add(tomlkit.comment("Generated by analysis/gen_syms.py - do not edit by hand."))
    doc.add(tomlkit.comment("Sources: analysis/out/functions.json, analysis/out/libultra_names.json"))
    sections = tomlkit.aot()

    used_names = {}
    stub_names = {}       # (segment, vram) -> emitted symbol name
    stats = []
    entry_ok = False

    for seg in funcs["segments"]:
        segnames = names.get(seg["name"], {})
        tbl = tomlkit.table()
        tbl["name"] = seg["name"]
        tbl["rom"] = hexint6(seg["rom"])
        tbl["vram"] = hexint(seg["vram"])
        tbl["size"] = hexint6(seg["size"])

        arr = tomlkit.array()
        arr.multiline(True)
        named = 0
        for f in sorted(seg["functions"], key=lambda x: x["vram"]):
            vram = f["vram"]
            size = f["size"]
            assert vram % 4 == 0, "%s: vram %08X not word aligned" % (seg["name"], vram)
            assert size % 4 == 0 and size > 0, \
                "%s: bad size %X at %08X" % (seg["name"], size, vram)
            rom = seg["rom"] + (vram - seg["vram"])
            assert rom % 4 == 0, "%s: rom %X not word aligned" % (seg["name"], rom)
            assert seg["rom"] <= rom and rom + size <= seg["rom"] + seg["size"], \
                "%s: function %08X (rom %X+%X) escapes the section" % (
                    seg["name"], vram, rom, size)

            nm = segnames.get("0x%08X" % vram)
            if nm is None:
                nm = ("func_%08X" % vram if seg["name"] == "boot"
                      else "func_%08X_%06X" % (vram, seg["rom"]))
            else:
                named += 1
            if nm in used_names:
                raise SystemExit("duplicate symbol name %s (%s and %s)" %
                                 (nm, used_names[nm], seg["name"]))
            used_names[nm] = seg["name"]
            stub_names[(seg["name"], vram)] = nm

            if vram == ENTRYPOINT and rom == 0x1000:
                entry_ok = True

            it = tomlkit.inline_table()
            it["name"] = nm
            it["vram"] = hexint(vram)
            it["size"] = hexint6(size)
            arr.append(it)
        tbl["functions"] = arr
        sections.append(tbl)
        stats.append((seg["name"], seg["rom"], len(seg["functions"]), named,
                      len(seg["rejected"])))

    if bss is not None and not args.no_bss:
        boot = next(s for s in funcs["segments"] if s["name"] == "boot")
        tbl = tomlkit.table()
        tbl["name"] = bss["name"]
        # No ROM backing; point at the end of the boot image so the key is
        # present and word aligned.  With functions = [] nothing is ever read.
        tbl["rom"] = hexint6(boot["rom"] + boot["size"])
        tbl["vram"] = hexint(bss["vram"])
        tbl["size"] = hexint6(bss["size"])
        empty = tomlkit.array()
        tbl["functions"] = empty
        sections.append(tbl)
        stats.append((bss["name"], boot["rom"] + boot["size"], 0, 0, 0))

    if not entry_ok:
        raise SystemExit("no function at vram 0x%08X / rom 0x1000 - N64Recomp's "
                         "entrypoint rename would fail" % ENTRYPOINT)

    doc["section"] = sections
    syms_path = os.path.join(args.config_dir, SYMS_NAME)
    with open(syms_path, "w") as fh:
        fh.write(tomlkit.dumps(doc))

    # ---- main config ------------------------------------------------------ #
    cfg = tomlkit.document()
    cfg.add(tomlkit.comment("Generated by analysis/gen_syms.py - do not edit by hand."))
    inp = tomlkit.table()
    inp["entrypoint"] = hexint(ENTRYPOINT)
    inp["symbols_file_path"] = SYMS_NAME
    inp["rom_file_path"] = args.rom_path
    inp["output_func_path"] = args.output_func_path
    inp["functions_per_output_file"] = args.functions_per_file
    # Overlay tracking (analysis/docs/overlay-tracking.md): the hook below calls
    # librecomp's overlay bookkeeping from the game's single DMA primitive, so the
    # generated code needs the extern declarations.
    inp["recomp_include"] = (
        '#include "recomp.h"\n'
        "#ifdef __cplusplus\n"
        'extern "C" {\n'
        "#endif\n"
        "/* src/main/register_overlays.cpp - whole-section overlay tracking. */\n"
        "extern void ke_overlay_dma(uint32_t rom, int32_t ram_addr, uint32_t size);\n"
        "/* ultramodern/src/scheduling.cpp - pumps the external message queue and\n"
        "   yields to any higher-priority ready thread; used by SPIN_YIELD_HOOKS. */\n"
        "extern void yield_self_1ms(uint8_t* rdram);\n"
        "/* src/main/rcp_timing.cpp - models the time the RCP needs for one frame,\n"
        "   which is what sets this game's speed; used by RCP_PACING_HOOKS. */\n"
        "extern void ke_gfx_task_begin(void);\n"
        "extern void ke_gfx_task_end(uint8_t* rdram);\n"
        "extern void ke_rcp_idle_wait(uint8_t* rdram);\n"
        "/* src/main/full_height.cpp - full-height missions enhancement: rewrites the\n"
        "   mission's 320x200 request to 320x240 when the flag is on. */\n"
        "extern uint32_t ke_view_height(uint32_t w, uint32_t h);\n"
        "/* src/main/extended_aim.cpp - extended aim range enhancement: widens the\n"
        "   reticle's clamp and lets its sprite be drawn outside the 4:3 column. */\n"
        "extern void ke_reticle_clamp_stash(uint8_t* rdram, uint32_t slot);\n"
        "extern void ke_reticle_clamp_apply(uint8_t* rdram);\n"
        "extern int32_t ke_reticle_blit_x(uint8_t* rdram, uint32_t sprite, int32_t x);\n"
        "extern int32_t ke_sprite_scissor_lrx(int32_t lrx);\n"
        "#ifdef __cplusplus\n"
        "}\n"
        "#endif"
    )
    cfg["input"] = inp
    # Names that N64Recomp does not already know about are emitted verbatim as C
    # functions, so anything matching a libc/libm identifier (fabs, fabsf,
    # _bzero, _Printf, ...) collides with the real declaration in <math.h> etc.
    # Route every such name through [patches].renamed so it is emitted as
    # `<name>_recomp`; the body is still recompiled normally.
    sets = load_symbol_lists(args.symbol_lists)
    known = set().union(*sets.values())
    to_rename = sorted(n for n in used_names
                       if n not in known and not n.startswith("func_"))

    # OS-level functions that must not execute but that stage 2 could not name
    # (ident_libultra.STUB_FUNCS).  N64Recomp emits an empty body for each, so
    # the symbol still exists for jal resolution but the original MMIO-touching
    # code never runs.
    patches = tomlkit.table()
    stub_arr = tomlkit.array()
    stub_arr.multiline(True)
    for s in names_doc.get("stubs", []):
        vram = int(s["vram"], 16)
        nm = stub_names.get((s["segment"], vram))
        if nm is None:
            raise SystemExit("stub target %s %s has no emitted symbol"
                             % (s["segment"], s["vram"]))
        stub_arr.append(nm)
    patches["stubs"] = stub_arr
    patches["ignored"] = tomlkit.array()
    ren = tomlkit.array()
    ren.multiline(True)
    for n in to_rename:
        ren.append(n)
    patches["renamed"] = ren
    cfg["patches"] = patches

    # Overlay-tracking hook: func_800D1D10(devAddr, dramAddr, size) is the single
    # funnel for every ROM->RAM DMA (segment_map.md). Registering the range with
    # librecomp before the copy is fine - the lookup tables never read rdram.
    # devAddr is masked in case it is KSEG1/phys-based rather than a raw ROM offset.
    # ke_overlay_dma() wraps librecomp's unload_overlays/load_overlays pair so the
    # unload range is grown to whole-section granularity; see
    # src/main/register_overlays.cpp and analysis/docs/boot-debug.md.
    hook = tomlkit.table()
    hook["func"] = "func_800D1D10"
    hook["text"] = (
        "ke_overlay_dma(((uint32_t)ctx->r4) & 0x1FFFFFFF, "
        "(int32_t)ctx->r5, (uint32_t)ctx->r6);"
    )
    hooks = tomlkit.aot()
    hooks.append(hook)

    # Full-height missions enhancement (analysis/docs/letterbox-full-height.md).
    # The in-mission letterbox (320x200, rows 20..219) is only an RDP scissor:
    # the per-frame clear builder func_800C277C computes uly=(240-H)/2 from the
    # height global 0x8010BAE4, and nothing else in the ROM reads that height -
    # the viewport (Vp at 0x8016AEC0, 320x240) and projection (30deg / 4:3) are
    # already full-frame. func_800C3044(w, h) is the lo-res mode setter that
    # stores the global; the mission overlay is its only caller passing h=200
    # (jal 0x8019CE38, immediate 0x240500C8 at 0x8019CE3C). Entry hook (no
    # before_vram) rewrites a1: ke_view_height returns 240 iff the enhancement
    # is on and (w,h)==(320,200), else h unchanged - so front-end callers
    # (320,240) and the blank/unblank pair are untouched.
    hook = tomlkit.table()
    hook["func"] = "func_800C3044"
    hook["text"] = (
        "ctx->r5 = (int32_t)ke_view_height((uint32_t)ctx->r4, "
        "(uint32_t)ctx->r5);"
    )
    hooks.append(hook)

    # Busy-wait yield hooks (analysis/docs/boot-debug.md).
    #
    # ultramodern schedules game threads cooperatively: messages posted from
    # native threads (VI retrace, SP/DP done, PI) sit in an external queue and
    # are only drained when a *game* thread calls osSendMesg/osRecvMesg/osJamMesg
    # or blocks.  A recompiled thread that spins on a memory flag therefore
    # deadlocks the whole runtime - on hardware the same loop is preempted by
    # the RCP interrupt handler, which has no equivalent here.
    #
    # N64Recomp only rewrites the unconditional `b .` form into pause_self(), so
    # the conditional form needs an explicit hook.  yield_self_1ms() drains the
    # external queue (waiting at most 1 ms) and hands execution to a higher
    # priority ready thread, which is what the interrupt would have done.
    #
    # The loops come from find_functions.find_spin_loops(); the hook goes at the
    # top of the loop body so it runs once per iteration.  Functions whose name
    # puts them in reimplemented_funcs/ignored_funcs are skipped: N64Recomp
    # emits no body for them, so there is nothing to hook (and librecomp's own
    # implementation blocks properly).
    spins = []
    for seg in funcs["segments"]:
        for sl in seg.get("spin_loops", []):
            spins.append((seg["name"], sl["func"], sl["target"], sl["branch"]))
    for segname, func_vram, hook_vram, branch_vram in spins:
        nm = stub_names.get((segname, func_vram))
        if nm is None or nm in sets["reimplemented_funcs"] or nm in sets["ignored_funcs"]:
            continue
        h = tomlkit.table()
        h.add(tomlkit.comment(
            "polling loop %08X..%08X (find_functions.find_spin_loops)"
            % (hook_vram, branch_vram)))
        h["func"] = nm
        h["before_vram"] = hexint(hook_vram)
        h["text"] = SPIN_YIELD_TEXT_OVERRIDES.get((segname, func_vram),
                                                  "yield_self_1ms(rdram);")
        hooks.append(h)
    for segname, func_vram, hook_vram, why in EXTRA_SPIN_YIELD_HOOKS:
        nm = stub_names.get((segname, func_vram))
        if nm is None:
            raise SystemExit("spin-yield hook target %s %08X is not an emitted "
                             "function" % (segname, func_vram))
        h = tomlkit.table()
        h.add(tomlkit.comment(why))
        h["func"] = nm
        h["before_vram"] = hexint(hook_vram)
        h["text"] = "yield_self_1ms(rdram);"
        hooks.append(h)

    # RCP frame-time model (see RCP_PACING_HOOKS above).
    for segname, func_vram, hook_vram, text, why in RCP_PACING_HOOKS:
        nm = stub_names.get((segname, func_vram))
        if nm is None:
            raise SystemExit("rcp pacing hook target %s %08X is not an emitted "
                             "function" % (segname, func_vram))
        h = tomlkit.table()
        h.add(tomlkit.comment(why))
        h["func"] = nm
        h["before_vram"] = hexint(hook_vram)
        h["text"] = text
        hooks.append(h)

    # Extended aim range (see EXTENDED_AIM_HOOKS above).
    for segname, func_vram, hook_vram, text, why in EXTENDED_AIM_HOOKS:
        nm = stub_names.get((segname, func_vram))
        if nm is None:
            raise SystemExit("extended-aim hook target %s %08X is not an emitted "
                             "function" % (segname, func_vram))
        h = tomlkit.table()
        h.add(tomlkit.comment(why))
        h["func"] = nm
        if hook_vram is not None:
            h["before_vram"] = hexint(hook_vram)
        h["text"] = text
        hooks.append(h)
    patches["hook"] = hooks
    cfg_path = os.path.join(args.config_dir, CONFIG_NAME)
    with open(cfg_path, "w") as fh:
        fh.write(tomlkit.dumps(cfg))

    L = ["section              rom      functions  named  rejected"]
    for name, rom, n, named, rej in stats:
        L.append("%-20s %06X %9d %6d %9d" % (name, rom, n, named, rej))
    L.append("")
    L.append("total sections : %d" % len(stats))
    L.append("total functions: %d" % sum(s[2] for s in stats))
    L.append("named functions: %d" % sum(s[3] for s in stats))
    L.append("wrote %s" % syms_path)
    L.append("wrote %s" % cfg_path)
    report = "\n".join(L) + "\n"
    with open(args.report, "w") as fh:
        fh.write(report)
    if not args.quiet:
        sys.stdout.write(report)
    return 0


if __name__ == "__main__":
    sys.exit(main())
