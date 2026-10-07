#include <stdio.h>

#include "host/host.h"
#include "host/host_sdl.h"

/* Audio device: 44.1 kHz stereo s16, fed silence from the VBlank tick on the main thread (the
 * place the SPU / libsnd mix goes in P1.8). Keeps about 4 VBlanks queued. No device is not an
 * error: the game runs without sound. */

#define AUDIO_RATE 44100
#define FRAME_BYTES 4                                  /* s16 stereo */
#define QUEUE_BYTES (4 * (AUDIO_RATE * 1001 / 60000 + 1) * FRAME_BYTES)

static SDL_AudioStream *stream;
static const Sint16 silence[1024 * 2];

void Host_AudioOpen(void) {
    SDL_AudioSpec spec;

    if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
        printf("[audio] no audio: %s\n", SDL_GetError());
        return;
    }
    spec.format = SDL_AUDIO_S16;
    spec.channels = 2;
    spec.freq = AUDIO_RATE;
    stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
    if (stream == NULL) {
        printf("[audio] no audio device: %s\n", SDL_GetError());
        return;
    }
    Host_AudioFeed();
    SDL_ResumeAudioStreamDevice(stream);
    printf("[audio] driver %s, device \"%s\", 44100 Hz stereo s16, silent\n", SDL_GetCurrentAudioDriver(),
           SDL_GetAudioDeviceName(SDL_GetAudioStreamDevice(stream)));
}

void Host_AudioFeed(void) {
    int queued;

    if (stream == NULL) {
        return;
    }
    queued = SDL_GetAudioStreamQueued(stream);
    while (queued >= 0 && queued < QUEUE_BYTES) {
        int n = QUEUE_BYTES - queued;

        if (n > (int)sizeof(silence)) {
            n = sizeof(silence);
        }
        SDL_PutAudioStreamData(stream, silence, n);
        queued += n;
    }
}

void Host_AudioClose(void) {
    if (stream != NULL) {
        SDL_DestroyAudioStream(stream);
        stream = NULL;
    }
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
