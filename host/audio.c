#include <stdio.h>
#include <stdlib.h>

#include "host/host.h"
#include "host/host_sdl.h"
#include "backend/psxspu.h"
#include "host/settings.h"

/* Audio device: 44.1 kHz stereo s16 (the SPU's own rate), fed from the VBlank tick on the main
 * thread with frames of the emulated SPU (backend/psxspu.c). Keeps about 4 VBlanks queued, so
 * the SPU advances as fast as the device plays. No device is not an error: the game runs
 * without sound (the SPU then still runs, one VBlank of samples per tick). PR.2 volume setting:
 * the stream gain, (v / 100)^2, on the device side only (the SPU output and DW2_WAV unchanged). */

#define AUDIO_RATE 44100
#define FRAME_BYTES 4                                  /* s16 stereo */
#define QUEUE_BYTES (4 * (AUDIO_RATE * 1001 / 60000 + 1) * FRAME_BYTES)

static SDL_AudioStream *stream;
static Sint16 mixbuf[1024 * 2];
static FILE *wav;
static Uint32 wav_bytes;

/* Dev option DW2_WAV=path: also write everything the SPU renders to a 44.1 kHz stereo WAV. */
static void wav_header(void) {
    Uint32 h[11];
    h[0] = 0x46464952; h[1] = 36 + wav_bytes; h[2] = 0x45564157; h[3] = 0x20746D66;
    h[4] = 16; h[5] = 0x00020001; h[6] = AUDIO_RATE; h[7] = AUDIO_RATE * FRAME_BYTES;
    h[8] = 0x00100004; h[9] = 0x61746164; h[10] = wav_bytes;
    fseek(wav, 0, SEEK_SET);
    fwrite(h, 4, 11, wav);
    fseek(wav, 0, SEEK_END);
}

static void render(int frames) {
    static int checked;
    PsxSpu_Render(mixbuf, frames);
    if (!checked) {
        const char *path = getenv("DW2_WAV");
        checked = 1;
        if (path != NULL && (wav = fopen(path, "wb")) != NULL) {
            wav_header();
            printf("[audio] writing %s\n", path);
        }
    }
    if (wav != NULL) {
        fwrite(mixbuf, FRAME_BYTES, frames, wav);
        wav_bytes += frames * FRAME_BYTES;
    }
}

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
    Host_AudioSetVolume(Settings_Get(SET_VOLUME));
    Host_AudioFeed();
    SDL_ResumeAudioStreamDevice(stream);
    printf("[audio] driver %s, device \"%s\", 44100 Hz stereo s16, SPU output\n", SDL_GetCurrentAudioDriver(),
           SDL_GetAudioDeviceName(SDL_GetAudioStreamDevice(stream)));
}

/* Main thread: 0..100. */
void Host_AudioSetVolume(int volume) {
    float v = (float)volume / 100.0f;

    if (stream != NULL) {
        SDL_SetAudioStreamGain(stream, v * v);
    }
}

void Host_AudioFeed(void) {
    int queued;

    if (stream == NULL) {
        /* no device: keep the SPU running at about the VBlank rate (735.7 frames) */
        static int frac;
        int n = 735;
        frac += 735;
        if (frac >= 1000) { frac -= 1000; n++; }
        render(n);
        return;
    }
    queued = SDL_GetAudioStreamQueued(stream);
    while (queued >= 0 && queued < QUEUE_BYTES) {
        int n = QUEUE_BYTES - queued;

        if (n > (int)sizeof(mixbuf)) {
            n = sizeof(mixbuf);
        }
        n &= ~(FRAME_BYTES - 1);
        render(n / FRAME_BYTES);
        SDL_PutAudioStreamData(stream, mixbuf, n);
        queued += n;
    }
}

void Host_AudioClose(void) {
    if (wav != NULL) {
        wav_header();
        fclose(wav);
        wav = NULL;
    }
    if (stream != NULL) {
        SDL_DestroyAudioStream(stream);
        stream = NULL;
    }
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
