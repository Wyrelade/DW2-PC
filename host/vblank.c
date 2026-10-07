#include <stdio.h>

#include "host/host.h"
#include "host/host_sdl.h"
#include "psyq/psyq_vblank.h"

/* VBlank clock: NTSC 60000/1001 Hz, one VBlank every 1001/60000 s = 50050000/3 ns. Deadline k
 * is t0 + k * period, computed from k, so rounding never accumulates (no drift). One thread: the
 * caller (a VSync wait or the Sys_FlipPending spin) sleeps here until the next deadline.
 *
 * VBlanks that came due while the game was busy all run on the next call, like the PS1
 * interrupt firing during a long frame (VSync(-1) then advances by the real elapsed count). After
 * a longer stall (debugger, window drag) the clock restarts from now instead of bursting. */

#define VBLANK_PERIOD_NUM 50050000ULL /* ns * 3 */
#define VBLANK_PERIOD_DEN 3ULL
#define MAX_CATCH_UP 8
#define RATE_LOG_EVERY 600 /* VBlanks, about 10 s */

extern int Sys_FlipPending;

static Uint64 t0;       /* clock base (ns) */
static Uint64 next;     /* index of the next deadline from t0 */
static Uint64 first_ns, last_ns; /* first and last VBlank run, for the overall rate */
static Uint64 fired;    /* VBlanks run */
static Uint64 flips;    /* buffer flips presented */
static Uint64 window_ns, window_fired;
static unsigned int restarts;

static Uint64 deadline(Uint64 k) {
    return t0 + k * VBLANK_PERIOD_NUM / VBLANK_PERIOD_DEN;
}

void Host_ClockStart(void) {
    t0 = SDL_GetTicksNS();
    next = 1;
    window_ns = t0;
    printf("[host] VBlank clock: 59.94 Hz (period %.6f ms)\n",
           (double)VBLANK_PERIOD_NUM / VBLANK_PERIOD_DEN / 1e6);
}

static void run_vblank(void) {
    int flip_pending = Sys_FlipPending;

    last_ns = SDL_GetTicksNS();
    if (fired == 0) {
        first_ns = last_ns;
    }
    Psyq_VBlank();
    fired++;
    if (flip_pending && !Sys_FlipPending) {
        flips++;
        Host_Present();
    }
    if (fired - window_fired >= RATE_LOG_EVERY) {
        Uint64 now = SDL_GetTicksNS();

        printf("[host] %llu VBlanks in %.3f s: %.3f Hz (total %llu, %llu flips)\n",
               (unsigned long long)(fired - window_fired), (now - window_ns) / 1e9,
               (fired - window_fired) * 1e9 / (double)(now - window_ns), (unsigned long long)fired,
               (unsigned long long)flips);
        window_ns = now;
        window_fired = fired;
    }
}

void Host_VBlank(void) {
    Uint64 now = SDL_GetTicksNS();
    int n;

    while (now < deadline(next)) {
        SDL_DelayPrecise(deadline(next) - now);
        now = SDL_GetTicksNS();
    }
    for (n = 0; n < MAX_CATCH_UP && now >= deadline(next); n++) {
        run_vblank();
        next++;
    }
    if (now >= deadline(next)) {
        restarts++;
        printf("[host] VBlank clock restarted (%.1f ms behind, restart %u)\n",
               (now - deadline(next)) / 1e6, restarts);
        t0 = now;
        next = 1;
    }
    Host_PumpEvents();
    Host_AudioFeed();
}

void Host_LogRate(const char *what) {
    Uint64 ns = last_ns - first_ns;

    printf("[host] %s: %llu VBlanks, first to last %.3f s: %.3f Hz (%llu flips, %u clock restarts)\n", what,
           (unsigned long long)fired, ns / 1e9, ns != 0 ? (fired - 1) * 1e9 / (double)ns : 0.0,
           (unsigned long long)flips, restarts);
    fflush(stdout);
}
