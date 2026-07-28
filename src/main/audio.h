#ifndef KERECOMP_AUDIO_H
#define KERECOMP_AUDIO_H

#include "ultramodern/ultramodern.hpp"

namespace kerecomp {
    // Opens the SDL audio device at `output_freq` Hz and returns the callback
    // set to hand to ultramodern. Must be called before recomp::start().
    //
    // Honours the KE_AUDIO_DUMP environment variable: when set, every buffer
    // handed to queue_samples is also appended, verbatim, to that path as raw
    // signed-16-bit little-endian stereo PCM at the *game's* sample rate (see
    // analysis/docs/audio.md). This is a debugging/verification hook only.
    ultramodern::audio_callbacks_t init_audio(unsigned int output_freq);

    // Closes the SDL audio device and finalizes any KE_AUDIO_DUMP file.
    void shutdown_audio();
}

#endif
