# Audio: locating, recompiling and wiring the audio microcode (2026-07-28)

Starting point: the game booted and rendered correctly but was silent. Every
`M_AUDTASK` RSP task was swallowed by a no-op stand-in
(`skip_audio_task` in `src/main/main.cpp`, see `boot-debug.md` §4) and
`ultramodern::audio_callbacks_t` was empty.

End state: the stock libultra audio microcode is recompiled by RSPRecomp and
runs for real, and an SDL2 sink plays what it produces. A 41.6 s capture of the
attract sequence has peak 8274/32767, RMS 740, 99.6 % non-zero samples and a
spectral flatness of 0.0044 (i.e. strongly tonal — music, not noise). A 153 s
soak run stayed alive with video still rendering and no RSP diagnostics.

---

## 1. Identifying the microcode

### 1.1 Which audio library?

`analysis/out/libultra_names.json` names the classic (non-`n_`) libultra
synthesis driver in the boot segment: `alInit`, `alSynNew`, `alAudioFrame`,
`alSynAllocVoice`/`alSynStartVoice`/`alSynSetVol`/`alSynSetPitch`/`alSynSetPan`,
`alAdpcmPull`, `alRaw16Pull`, `alResamplePull`, `alEnvmixerPull`, `alFxPull`,
`alAuxBusPull`, `alMainBusPull`, `alSavePull`, `alLoadParam`, `alFilterNew`,
`_collectPVoices`, `_allocatePVoice`. There is no `n_alAudioFrame` /
`n_alSynNew` anywhere, so this is **`aspMain`**, not `n_aspMain`. Confirmed
independently in §1.4 by the command-table size.

### 1.2 The authoritative addresses: the game's own OSTask

The audio `OSTask` is built by a loop in the boot segment at
`0x800CDD90..0x800CDE1C` (inside `func_800CDD00`, the audio-thread bring-up
that also calls `alHeapDBAlloc`, `osCreateMesgQueue`, `osAiSetFrequency`
(`func_800D8BB0`) and `alInit` (`func_800D88CC`)):

```
800CDD90 3C0E800E  lui   $t6, 0x800E
800CDD94 3C0F800E  lui   $t7, 0x800E
800CDD98 25EF51F0  addiu $t7, $t7, 0x51F0     ; 0x800E51F0  rspbootTextStart
800CDD9C 25CE52C0  addiu $t6, $t6, 0x52C0     ; 0x800E52C0  rspbootTextEnd == aspMainTextStart
...
800CDDB8 24A551F0  addiu $a1, $a1, 0x51F0     ; a1 = 0x800E51F0
800CDDBC 24C652C0  addiu $a2, $a2, 0x52C0     ; a2 = 0x800E52C0
800CDDC0 24E7E460  addiu $a3, $a3, -0x1BA0    ; a3 = 0x800EE460
800CDDCC 24428C28  addiu $v0, $v0, -0x73D8    ; v0 = 0x80148C28 (boot .bss)
800CDDD0 01CF5023  subu  $t2, $t6, $t7        ; t2 = 0xD0
800CDDD4 24080800  addiu $t0, $zero, 0x800
800CDDD8 24040002  addiu $a0, $zero, 0x2      ; M_AUDTASK
loop:
800CDDDC 24630184  addiu $v1, $v1, 0x184
800CDDE0 24420058  addiu $v0, $v0, 0x58       ; 2 iterations (double-buffered)
800CDDE4 AC40FFFC  sw    $zero, -0x4($v0)
800CDDE8 AC44FFB8  sw    $a0,  -0x48($v0)     ; +0x00 type            = 2
800CDDEC AC45FFC0  sw    $a1,  -0x40($v0)     ; +0x08 ucode_boot      = 0x800E51F0
800CDDF0 AC4AFFC4  sw    $t2,  -0x3C($v0)     ; +0x0C ucode_boot_size = 0xD0
800CDDF4 AC46FFC8  sw    $a2,  -0x38($v0)     ; +0x10 ucode           = 0x800E52C0
800CDDF8 AC47FFD0  sw    $a3,  -0x30($v0)     ; +0x18 ucode_data      = 0x800EE460
800CDDFC AC48FFD4  sw    $t0,  -0x2C($v0)     ; +0x1C ucode_data_size = 0x800
800CDE00..0C  sw $zero ...                    ; +0x20..0x2C dram_stack/output_buff
800CDE10/14   sw $zero ...                    ; +0x38/0x3C yield_data
```

The OSTask therefore starts at `-0x48($v0)`; the field offsets `+0x00 / +0x08 /
+0x0C / +0x10 / +0x18 / +0x1C` line up exactly with `OSTask_t`, and rspboot
(§1.3) reads the same offsets. `t.flags` (`+0x04`), `t.ucode_size` (`+0x14`) and
`t.data_ptr`/`t.data_size` (`+0x30`/`+0x34`) are deliberately not written here:
the struct lives in boot `.bss` so they start at 0, the command-list pointer is
filled in per audio frame, and `ucode_size == 0` means `osSpTaskLoad` substitutes
`SP_UCODE_SIZE`.

A whole-boot-segment `lui`/`addiu` constant sweep finds these three call sites
and no others touching `0x800E4E00..0x800E9000`, i.e. **only the audio path
builds a task from the boot segment**; the graphics tasks are built inside the
front-end / in-game code overlays (which is why the F3DEX/F3DLX blobs are never
referenced from boot).

ROM offsets (boot segment is ROM `0x1000` → VRAM `0x800C2400`):

| item | VRAM | ROM |
|---|---|---|
| `rspbootTextStart` | 0x800E51F0 | 0x23DF0 |
| `aspMainTextStart` (`t.ucode`) | 0x800E52C0 | 0x23EC0 |
| `aspMainTextEnd` (see §1.4) | 0x800E60E0 | 0x24CE0 |
| `aspMainDataStart` (`t.ucode_data`) | 0x800EE460 | 0x2D060 |

### 1.3 `text_address` comes from rspboot, not from a guess

Disassembling `t.ucode_boot` (0xD0 bytes at `0x800E51F0`) as RSP gives the stock
libultra `rspboot`:

```
1000 09000419  j     0x1064            # start: check t.flags bit 1 (yield)
1064 8C220004  lw    $2, 0x4($1)       # $1 = 0xFC0, the OSTask in DMEM
...
108C 8C220018  lw    $2, 0x18($1)      # ucode_data
1090 8C23001C  lw    $3, 0x1C($1)      # ucode_data_size
1094 2063FFFF  addi  $3, $3, -0x1
10A4 40800000  mtc0  $zero, SP_MEM_ADDR    # -> DMEM 0x000
10A8 40820800  mtc0  $2, SP_DRAM_ADDR
10AC 40831000  mtc0  $3, SP_RD_LEN
10C4 09000402  j     0x1008
1008 8C220010  lw    $2, 0x10($1)      # ucode (text)
100C 20030F7F  addi  $3, $zero, 0xF7F  # 0xF80 bytes - 1
1010 20071080  addi  $7, $zero, 0x1080 # <-- IMEM destination
1014 40870000  mtc0  $7, SP_MEM_ADDR
1018 40820800  mtc0  $2, SP_DRAM_ADDR
101C 40831000  mtc0  $3, SP_RD_LEN
1034 00E00008  jr    $7                # <-- entry point = IMEM 0x080
```

So the ucode text is DMA'd to **IMEM offset 0x80** and entered there, i.e.
RSPRecomp's `text_address = 0x1080` (RSPRecomp masks addresses with 0x1FFF,
where 0x0000-0x0FFF is DMEM and 0x1000-0x1FFF is IMEM). rspboot always moves a
fixed 0xF80 bytes — the whole rest of IMEM — regardless of the real ucode size.

### 1.4 Where the audio text ends (`text_size`)

Two independent bounds agree:

* The ABI command dispatcher lives at IMEM `0x1104`:

  ```
  1104 00011020  add  $2, $zero, $1
  1108 84420010  lh   $2, 0x10($2)      # halfword table at DMEM 0x10
  110C 00400008  jr   $2
  ```

  The table at `ucode_data + 0x10` (ROM `0x2D070`) is exactly **16** entries —
  the standard N64 audio ABI command set (SPNOOP, ADPCM, CLEARBUFF, ENVMIXER,
  LOADBUFF, RESAMPLE, SAVEBUFF, SEGMENT, SETBUFF, SETVOL, DMEMMOVE, LOADADPCM,
  MIXER, INTERLEAVE, POLEF, SETLOOP), which is what pins the identity to
  `aspMain`. Their highest target is `0x1E24`.

* Disassembling forward from `0x1080`, the code is continuous audio work
  (`lqv/sqv`, `vmulf/vmacf`, SP DMA via `SP_MEM_ADDR`/`SP_DRAM_ADDR`) up to
  `0x1E94 j 0x1118` / `0x1E98 nop` / `0x1E9C 00000000`. At `0x1EA0` it changes
  character completely:

  ```
  1EA0 4A00002C  vxor  $v0, $v0, $v0
  1EA4 C81F201B  lqv   $v31[0], 0x1B0($zero)
  ...
  1EE0 400B5800  mfc0  $11, DPC_STATUS
  1F30 40824000  mtc0  $2, DPC_START
  1F34 40824800  mtc0  $2, DPC_END
  ```

  DPC (RDP command) register traffic — that is the start of the **graphics**
  microcode text (`RSP Gfx ucode F3DEX fifo 2.05`, whose data string sits at ROM
  `0x2D458`). Nothing in the audio ucode touches the DPC.

So `text_size = 0x1EA0 - 0x1080 = 0xE20` (3616 bytes, 904 instructions),
VRAM `0x800E52C0..0x800E60E0`, ROM `0x23EC0..0x24CE0`. This also resolves open
question 2 in `analysis/out/segment_map.md` §d for the audio half of the
`~0x800E51F0..~0x800E85F0` blob region: it is
`rspboot (0xD0) | aspMain text (0xE20) | gfx ucode text ...`.

### 1.5 A note on `ucode_data_size = 0x800`

`0x800` is `SP_UCODE_DATA_SIZE`, the ABI constant, not the size of `aspMain`'s
own data. The real `aspMain` data content (magic words, the 16-entry jump table
at `+0x10`, vector constants, ADPCM/resample coefficient tables) occupies only
the first ~0x2C0 bytes of `0x800EE460`; the tail of the 0x800-byte DMA pulls in
the beginning of the F3DEX2 data blob that follows it in the boot rodata. That
is exactly what happens on hardware too — those DMEM addresses are scratch/output
buffers the ucode writes before it reads.

Related: librecomp's `recomp::rsp::run_task`
(`deps/N64ModernRuntime/librecomp/src/rsp.cpp`) hardcodes a **0xF80**-byte
`ucode_data` DMA rather than using `t.ucode_data_size` (0x800), so DMEM
`0x800..0xF80` additionally receives more of that same neighbouring blob. It
does not disturb the OSTask copy at `dmem[0xFC0]` and, empirically, the output
is clean; noted here because it is a deviation from the console behaviour, not
because it caused a problem.

---

## 2. RSPRecomp

`config/aspMain.us.toml`:

```toml
text_offset = 0x23EC0
text_size = 0xE20
text_address = 0x1080
rom_file_path = "../build/knife_edge.z64"
output_file_path = "../generated/us/rsp/aspMain.cpp"
output_function_name = "aspMain"
extra_indirect_branch_targets = [
    0x1118, 0x1470, 0x11DC, 0x1B38, 0x1214, 0x187C, 0x1254, 0x12D0,
    0x12EC, 0x1328, 0x140C, 0x1294, 0x1E24, 0x138C, 0x170C, 0x144C,
]
unsupported_instructions = []
```

The only configuration that is not mechanical is
`extra_indirect_branch_targets`: RSPRecomp discovers direct branch targets and
`jal` return addresses on its own, but it cannot see through the `lh` + `jr`
command dispatch, so the 16 jump-table entries are read out of the ROM at
`0x2D070` and listed. The other three indirect jumps need nothing:
`jr $ra` at `0x11A8`/`0x11D4` and the `addi $5, $ra, 0` (`0x1150`) /
`jr $5` (`0x117C`) save-restore pair are all reached from `jal`s whose return
addresses RSPRecomp already collects.

```
$ deps/N64Recomp/build/RSPRecomp config/aspMain.us.toml
```

succeeds first try, silently, producing `generated/us/rsp/aspMain.cpp`
(2272 lines, 73 kB, 81 labels, one 31-case indirect-jump switch).

**No RSPRecomp limitation was hit.** In particular:

* **No overlay slots are needed.** `aspMain` is a single flat 0xE20-byte image;
  the only DMAs it issues are audio buffer/sample transfers to DMEM, never an
  IMEM reload, so there is no `SwapOverlay` path and no `[[overlay_slots]]`
  section. (Contrast the Zelda64Recomp `njpgdspMain` case, which does need
  them.)
* **No `unsupported_instructions`.** Every one of the 904 words decodes to an
  instruction rabbitizer and RSPRecomp both handle; there are no `mfc0`/`mtc0`
  accesses outside the set RSPRecomp models (`SP_STATUS`, `SP_SEMAPHORE`,
  `SP_DMA_BUSY`, `SP_DMA_FULL`, `SP_MEM_ADDR`, `SP_DRAM_ADDR`, `SP_RD_LEN`,
  `SP_WR_LEN`), and no DPC access at all.
* At runtime the ucode exits through the `break` at `0x1140` after setting
  `SP_STATUS` — i.e. `RspExitReason::Broke`, which is what
  `recomp::rsp::run_task` requires. Over a 153 s run there was not one
  "Unhandled jump target", "ImemOverrun" or "exited unexpectedly" message.

---

## 3. Build and dispatch wiring

* `CMakeLists.txt` globs `${KE_GENERATED_DIR}/rsp/*.cpp` into a
  `KE_RSP_SOURCES` list and adds it to the `KnifeEdgeRecompiled` target rather
  than to `RecompiledFuncs`. Two reasons: the CPU glob is `*.c`/`*.cpp` at the
  top level only, and librecomp's `rsp_vu_impl.hpp` vector backend needs SSE4.1,
  which only the main executable is compiled with (`-march=nehalem`). When the
  glob comes up empty (the stub configuration) `KE_HAVE_ASPMAIN` is not defined
  and `src/main/main.cpp` does not reference `aspMain`, so the skeleton build
  still links.

* `src/main/main.cpp`'s `get_rsp_microcode` now dispatches:

  ```cpp
  if (type == M_AUDTASK) { return aspMain; }
  ... return skip_unknown_task;   // Broke, so librecomp still posts SP-done
  ```

  `M_GFXTASK` never reaches here (RT64 intercepts graphics tasks), and the
  no-op fallback is kept for genuinely unknown types so an unexpected task
  cannot kill the process — returning `nullptr` makes librecomp `exit(1)`.

---

## 4. The output sink (`src/main/audio.cpp`)

The path is: game audio thread → `alAudioFrame`/`alSynthesize` → the recompiled
`aspMain` writes the mixed buffer into rdram → `osAiSetNextBuffer`, which is in
librecomp's `reimplemented_funcs` and lands in `librecomp/src/ai.cpp` →
`ultramodern::queue_audio_buffer` → `audio_callbacks.queue_samples`.

`kerecomp::init_audio(48000)` opens an `AUDIO_F32` stereo device with a 0x100
frame buffer and returns the `ultramodern::audio_callbacks_t`. It is modeled on
Zelda64Recomp's `src/main/main.cpp` (dev branch), minus its config/main-volume
plumbing. Design points:

1. **Channel order.** ultramodern hands over a raw `int16_t*` into the rdram
   array, and librecomp stores rdram byte-swapped inside each 32-bit word
   (`recomp.h` indexes bytes as `addr ^ 3`). Halfword index `i` in that array is
   really the N64 halfword at byte offset `(2*i) ^ 2`, so reading the
   interleaved `[L,R,L,R…]` N64 buffer linearly yields `[R,L,R,L…]`. Every pair
   is swapped back on the way out. (Verified: with the swap, 92.6 % of output
   frames have L ≠ R; the buffer is genuinely stereo, so getting this wrong is
   audible.)

2. **Sample rate.** The game calls `osAiSetFrequency(32000)` — confirmed at
   runtime by the `Audio: AI frequency set to 32000 Hz` log line — while the
   device runs at 48000. Every chunk goes through an `SDL_AudioCVT` built in
   `set_frequency`. Four input frames are carried across chunk boundaries and
   re-fed to the converter so its linear interpolation has real history instead
   of a discontinuity at every ~1 kB buffer; the corresponding output frames are
   then discarded (half at the head, half at the tail).

3. **Latency control.** `queue_samples` decimates when more than 100 ms is
   already queued, and `get_frames_remaining` reports the device backlog
   rescaled into *input-rate* frames minus a one-VI guard band (ultramodern
   multiplies it back into bytes for `osAiGetLength`, which the game uses to
   decide how many samples to synthesise).

4. **Failure is non-fatal.** If `SDL_OpenAudioDevice` fails, `init_audio`
   returns an empty callback set and the game runs silent instead of aborting —
   the normal outcome on a machine with no sound device.

### 4.1 `KE_AUDIO_DUMP`

Debug tap, off unless the environment variable is set:

```
KE_AUDIO_DUMP=/tmp/ke_audio.pcm ./build-shim/KnifeEdgeRecompiled --rom …
```

appends every buffer that reaches `queue_samples` to that path as raw **S16LE
stereo PCM at the game's own rate (32000 Hz)** — post channel-swap, but before
any resampling, gain or float conversion, so it is exactly what the RSP
produced. Dumps are game asset data: write them outside the repo and never
commit them (`.gitignore` covers ROM/asset material, not `.pcm`).

---

## 5. Measured non-silence

Harness (the container has no sound device, so SDL's dummy driver stands in; it
still drains the queue at real time, which keeps `osAiGetLength` honest):

```
rm -rf ke_recomp_data
Xvfb :99 -screen 0 1280x720x24 & sleep 2
DISPLAY=:99 SDL_AUDIODRIVER=dummy KE_AUDIO_DUMP=/tmp/ke_audio.pcm \
  timeout 40 ./build-shim/KnifeEdgeRecompiled --rom build/knife_edge.z64
```

40 s of wall clock produced **5 324 800 bytes = 1 331 200 stereo frames =
41.60 s of 32 kHz audio** (1.04× real time, i.e. the synthesiser is keeping up).

Whole capture:

| metric | value |
|---|---|
| peak sample | 8274 / 32767 |
| RMS | 739.6 |
| non-zero samples | 99.56 % |
| frames with L ≠ R | 92.64 % |
| spectral flatness (1 s @ t=10 s, L) | 0.00439 (1.0 = white noise) |
| strongest spectral peaks | 148, 888, 932, 1036, 1405, 1585 Hz |

Per-second peak / RMS (abridged; the full 41-row table is reproducible with the
snippet at the end of this section):

```
t= 0s peak= 4973 rms= 971.0 nonzero=0.997     t=21s peak= 4106 rms= 531.1
t= 1s peak= 4442 rms= 665.6 nonzero=0.999     t=22s peak= 5257 rms= 817.6
t= 4s peak= 1504 rms= 356.5 nonzero=0.999     t=26s peak= 3042 rms= 546.1
t= 8s peak= 3054 rms= 485.0 nonzero=0.859     t=27s peak= 5322 rms= 852.0
t= 9s peak= 3430 rms= 756.3 nonzero=1.000     t=31s peak= 5853 rms=1008.4
t=15s peak= 8274 rms=1325.4 nonzero=1.000     t=34s peak= 5833 rms=1172.8
t=17s peak= 6602 rms=1081.6 nonzero=0.999     t=40s peak= 5698 rms=1175.3
t=20s peak= 5741 rms=1098.4 nonzero=0.999
```

Reading of these numbers: the level tracks the attract sequence (quiet KEMCO
logo → title sting at t=15 s → the two cinematic tracks), never flatlines, and
the spectrum is sharply harmonic rather than broadband, which is what
distinguishes "the mixer is really running" from "the buffer is full of garbage
or a stuck DC value".

A listenable WAV of the same capture was written to `/tmp/knife_edge_audio.wav`
(outside the repo, deliberately).

```python
import numpy as np
RATE = 32000
st = np.fromfile('/tmp/ke_audio.pcm', dtype='<i2').reshape(-1, 2).astype(float)
print(int(np.abs(st).max()), float(np.sqrt((st**2).mean())), float((st != 0).mean()))
for i in range(st.shape[0] // RATE):
    b = st[i*RATE:(i+1)*RATE]
    print(i, int(np.abs(b).max()), round(float(np.sqrt((b**2).mean())), 1))
```

## 6. Video is not regressed

Same harness without the dump, run for 153 s: process alive the whole time,
`/tmp/ke_audio_video1.png` and `/tmp/ke_audio_video2.png` (Xvfb `import -window
root`, taken 12 s apart) show two different frames of the Mars canyon attract
flythrough, so frames are still being produced. stdout/stderr contains only the
six expected `[overlays] dropping first-1MB registration` lines and the two
audio-init lines — no RSP diagnostics, no assertions.

---

## 7. Remaining gaps

1. **No master volume / mute.** `queue_samples` applies a fixed 0.5 gain for
   headroom. Zelda64Recomp reads this from its config UI; this project has no
   config UI yet.
2. **No device-change handling.** The device is opened once at startup; hot-plug
   and `SDL_AUDIODEVICEADDED`/`REMOVED` are ignored.
3. **`ucode_data` DMA length.** librecomp reads 0xF80 bytes where the task says
   0x800 (§1.5). Harmless here, but it is a real difference from hardware and
   would matter for a microcode that reads its own data tail.
4. **Only the attract loop has been heard.** The headless harness still cannot
   press Start (`boot-debug.md` §6), so in-mission SFX, the ADPCM voice path
   under load and the streamed-music path (`func_800CD800`, the 30 files at ROM
   `0x78C860`) are exercised only as far as the attract sequence uses them.
5. **Second/third ucode blob boundaries.** This pass pinned rspboot and the
   audio ucode exactly; the two graphics ucode text/data blobs that follow are
   still only bracketed, not split (`segment_map.md` §d open question 2). RT64
   HLEs graphics, so nothing needs them.
