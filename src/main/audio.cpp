// Knife Edge Recompiled -- SDL2 audio sink.
//
// This is the output half of the audio path. The input half is the recompiled
// audio microcode (generated/us/rsp/aspMain.cpp, see analysis/docs/audio.md):
// the game's audio thread runs alSynthesize -> osAiSetNextBuffer, librecomp
// HLEs osAiSetNextBuffer into ultramodern::queue_audio_buffer, and that lands
// in queue_samples() below.
//
// Modeled on Zelda64Recomp's src/main/main.cpp (dev branch) audio block, minus
// its config/main-volume plumbing which this project doesn't have yet.
//
// Two format details matter and are easy to get wrong:
//
//  1. Channel order. ultramodern hands us a raw `int16_t*` into the rdram
//     array, and librecomp stores rdram byte-swapped within each 32-bit word
//     (recomp.h indexes bytes as `addr ^ 3`). So halfword index i in that array
//     is really the N64 halfword at byte offset (2*i) ^ 2, i.e. every adjacent
//     pair of samples comes out reversed. The N64 buffer is interleaved
//     [L,R,L,R...], so reading it linearly gives [R,L,R,L...] and the two
//     channels have to be swapped back.
//
//  2. Sample rate. The game picks its own AI frequency (osAiSetFrequency ->
//     set_frequency below) and it is not the device rate, so every buffer is
//     resampled with SDL_AudioCVT. Four input frames are carried over between
//     buffers and re-fed to the converter so its linear interpolation has real
//     history instead of a discontinuity at each chunk boundary; the
//     corresponding output frames are then dropped.

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <vector>

#if defined(_WIN32)
#   include "SDL.h"
#else
#   include "SDL2/SDL.h"
#endif

#include "audio.h"

namespace {
    SDL_AudioCVT audio_convert{};
    SDL_AudioDeviceID audio_device = 0;

    // Samples per channel per second.
    uint32_t sample_rate = 48000;
    uint32_t output_sample_rate = 48000;

    // A "frame" here is one sample for every channel, i.e. 2 int16s in, 2
    // floats out. Nothing to do with graphics frames.
    constexpr uint32_t input_channels = 2;
    constexpr uint32_t output_channels = 2;
    constexpr uint32_t bytes_per_output_frame = output_channels * sizeof(float);

    // Input frames carried across chunk boundaries to prime the resampler, and
    // the number of resulting output frames that therefore have to be dropped.
    constexpr uint32_t duplicated_input_frames = 4;
    uint32_t discarded_output_frames = duplicated_input_frames;

    // ---- KE_AUDIO_DUMP ----------------------------------------------------
    // Debug tap: raw S16LE stereo PCM at the game's own sample rate, i.e. the
    // exact samples the RSP produced, before any resampling or float
    // conversion. Used to prove the pipeline is not emitting silence.
    std::FILE* dump_file = nullptr;
    std::vector<int16_t> dump_scratch;
    std::mutex dump_mutex;

    void open_dump_file() {
        const char* path = std::getenv("KE_AUDIO_DUMP");
        if (path == nullptr || path[0] == '\0') {
            return;
        }
        dump_file = std::fopen(path, "wb");
        if (dump_file == nullptr) {
            std::fprintf(stderr, "KE_AUDIO_DUMP: could not open '%s' for writing\n", path);
            return;
        }
        std::fprintf(stderr, "KE_AUDIO_DUMP: writing raw S16LE stereo PCM to '%s'\n", path);
    }

    void update_audio_converter() {
        int ret = SDL_BuildAudioCVT(&audio_convert, AUDIO_F32, input_channels, static_cast<int>(sample_rate),
                                    AUDIO_F32, output_channels, static_cast<int>(output_sample_rate));
        if (ret < 0) {
            std::fprintf(stderr, "Error creating SDL audio converter: %s\n", SDL_GetError());
            return;
        }

        // How many output frames the duplicated input frames turn into.
        discarded_output_frames = duplicated_input_frames * output_sample_rate / sample_rate;
    }

    // `sample_count` counts int16s, not frames: it is byte_count / 2 straight
    // out of ultramodern::queue_audio_buffer.
    void queue_samples(int16_t* audio_data, size_t sample_count) {
        static std::vector<float> swap_buffer;
        static std::array<float, duplicated_input_frames * input_channels> carry_buffer{};

        if (audio_device == 0 || sample_count == 0) {
            return;
        }

        constexpr size_t carry_samples = duplicated_input_frames * input_channels;

        // A chunk shorter than the carry window would make the carry logic
        // read its own uninitialized tail. The N64 audio frame is ~1kB, so this
        // is a guard, not a real case.
        if (sample_count <= carry_samples) {
            return;
        }

        size_t total_input_samples = sample_count + carry_samples;
        size_t needed = std::max<size_t>(total_input_samples,
                                         total_input_samples * static_cast<size_t>(std::max(audio_convert.len_mult, 1)));
        if (needed > swap_buffer.size()) {
            swap_buffer.resize(needed);
        }

        for (size_t i = 0; i < carry_samples; i++) {
            swap_buffer[i] = carry_buffer[i];
        }

        // Un-swap the channels (see note 2 in the file header) and convert to
        // float. The 0.5 keeps headroom: the N64 mixer's output regularly
        // clips at full scale on this game's title-screen sting.
        for (size_t i = 0; i < sample_count; i += input_channels) {
            swap_buffer[carry_samples + i + 0] = audio_data[i + 1] * (0.5f / 32768.0f);
            swap_buffer[carry_samples + i + 1] = audio_data[i + 0] * (0.5f / 32768.0f);
        }

        if (dump_file != nullptr) {
            std::lock_guard<std::mutex> lock{dump_mutex};
            if (dump_scratch.size() < sample_count) {
                dump_scratch.resize(sample_count);
            }
            for (size_t i = 0; i < sample_count; i += input_channels) {
                dump_scratch[i + 0] = audio_data[i + 1];
                dump_scratch[i + 1] = audio_data[i + 0];
            }
            std::fwrite(dump_scratch.data(), sizeof(int16_t), sample_count, dump_file);
        }

        // Keep the tail of this chunk to prime the next one.
        for (size_t i = 0; i < carry_samples; i++) {
            carry_buffer[i] = swap_buffer[sample_count + i];
        }

        audio_convert.buf = reinterpret_cast<Uint8*>(swap_buffer.data());
        audio_convert.len = static_cast<int>(total_input_samples * sizeof(float));

        if (audio_convert.needed) {
            if (SDL_ConvertAudio(&audio_convert) < 0) {
                std::fprintf(stderr, "Error using SDL audio converter: %s\n", SDL_GetError());
                return;
            }
        }
        else {
            audio_convert.len_cvt = audio_convert.len;
        }

        // Drop the primed frames: half at the head, half at the tail, matching
        // where the duplicated input frames ended up.
        uint32_t head_frames = discarded_output_frames / 2;
        int32_t bytes_to_queue =
            audio_convert.len_cvt - static_cast<int32_t>(discarded_output_frames * bytes_per_output_frame);
        float* samples_to_queue = swap_buffer.data() + head_frames * output_channels;
        if (bytes_to_queue <= 0) {
            return;
        }

        // Don't let latency build up: if a lot is already queued (the game runs
        // its audio thread faster than the device drains when the window is
        // not vsync-limited), decimate.
        uint64_t queued_frames = SDL_GetQueuedAudioSize(audio_device) / bytes_per_output_frame;
        uint64_t queued_microseconds = queued_frames * 1000000ull / output_sample_rate;
        uint32_t skip_factor = static_cast<uint32_t>(queued_microseconds / 100000);
        if (skip_factor != 0) {
            uint32_t skip_ratio = 1u << skip_factor;
            bytes_to_queue /= static_cast<int32_t>(skip_ratio);
            size_t frames = bytes_to_queue / bytes_per_output_frame;
            for (size_t i = 0; i < frames; i++) {
                samples_to_queue[2 * i + 0] = samples_to_queue[2 * skip_ratio * i + 0];
                samples_to_queue[2 * i + 1] = samples_to_queue[2 * skip_ratio * i + 1];
            }
        }

        SDL_QueueAudio(audio_device, samples_to_queue, static_cast<Uint32>(bytes_to_queue));
    }

    // Returns *input-rate* frames still buffered, which is what the game's
    // osAiGetLength wants. ultramodern multiplies this back up by
    // 2 * sizeof(int16_t) in get_remaining_audio_bytes().
    size_t get_frames_remaining() {
        if (audio_device == 0) {
            return 0;
        }

        constexpr float buffer_offset_frames = 1.0f;

        uint64_t buffered_bytes = SDL_GetQueuedAudioSize(audio_device);

        // Rescale device bytes into input-rate frames.
        uint64_t buffered_input_frames =
            buffered_bytes / bytes_per_output_frame * sample_rate / output_sample_rate;

        // Report slightly fewer than are really buffered so a hiccup on the
        // audio thread doesn't leave the device starved; see the same
        // adjustment in ultramodern::get_remaining_audio_bytes.
        uint64_t guard_frames = static_cast<uint64_t>(buffer_offset_frames * (sample_rate / 60));
        if (buffered_input_frames > guard_frames) {
            buffered_input_frames -= guard_frames;
        }
        else {
            buffered_input_frames = 0;
        }

        return static_cast<size_t>(buffered_input_frames);
    }

    void set_frequency(uint32_t freq) {
        if (freq == 0) {
            return;
        }
        static bool reported = false;
        if (freq != sample_rate || !reported) {
            reported = true;
            std::fprintf(stderr, "Audio: AI frequency set to %u Hz (device %u Hz)\n", freq, output_sample_rate);
        }
        sample_rate = freq;
        update_audio_converter();
    }
}

namespace kerecomp {
    ultramodern::audio_callbacks_t init_audio(unsigned int output_freq) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
            std::fprintf(stderr, "SDL error initializing audio subsystem: %s\n", SDL_GetError());
            return {};
        }

        SDL_AudioSpec spec_desired{};
        spec_desired.freq = static_cast<int>(output_freq);
        spec_desired.format = AUDIO_F32;
        spec_desired.channels = static_cast<Uint8>(output_channels);
        // Small buffer to keep the internal latency low.
        spec_desired.samples = 0x100;
        spec_desired.callback = nullptr;
        spec_desired.userdata = nullptr;

        SDL_AudioSpec spec_obtained{};
        audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, &spec_obtained, 0);
        if (audio_device == 0) {
            // Not fatal: the game is perfectly playable silent, and this is the
            // normal outcome on a machine with no sound device at all.
            std::fprintf(stderr, "SDL error opening audio device (continuing without audio): %s\n", SDL_GetError());
            return {};
        }

        output_sample_rate = static_cast<uint32_t>(spec_obtained.freq);
        std::fprintf(stderr, "SDL audio driver: %s, %u Hz, %u ch\n",
                     SDL_GetCurrentAudioDriver(), output_sample_rate, spec_obtained.channels);

        SDL_PauseAudioDevice(audio_device, 0);

        update_audio_converter();
        open_dump_file();

        return ultramodern::audio_callbacks_t{
            .queue_samples = queue_samples,
            .get_frames_remaining = get_frames_remaining,
            .set_frequency = set_frequency,
        };
    }

    void shutdown_audio() {
        if (audio_device != 0) {
            SDL_CloseAudioDevice(audio_device);
            audio_device = 0;
        }
        std::lock_guard<std::mutex> lock{dump_mutex};
        if (dump_file != nullptr) {
            std::fclose(dump_file);
            dump_file = nullptr;
        }
    }
}
