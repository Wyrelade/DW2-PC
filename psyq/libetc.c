#include "libetc.h"
#include "psyq_log.h"
#include "psyq_vblank.h"
#include "host/host.h"

/* libetc on host time (P1.2). Psyq_VBlank() is the VBlank "interrupt": it advances the VSync(-1)
 * counter and runs the VSyncCallback handler. The host's 59.94 Hz clock (host/vblank.c) calls
 * it at each deadline; VSync(0 / n) sleeps on that clock, like Sys_Main's Sys_FlipPending spin. */

static void (*vsync_cb)(void);
static volatile int vblank_count;
static int last_vsync; /* counter when the last VSync(0 / n) returned */

void Psyq_VBlank(void) {
    vblank_count++;
    if (vsync_cb != 0) {
        vsync_cb();
    }
}

int VSync(int mode) {
    int target;

    PSYQ_LOG("%d", mode);
    if (mode < 0) {
        return vblank_count;
    }
    if (mode == 1) {
        return 0; /* horizontal blank count since the last VSync */
    }
    /* 0: the next VBlank; n > 1: n VBlanks after the last VSync, at least the next one. */
    target = vblank_count + 1;
    if (mode > 1 && last_vsync + mode > target) {
        target = last_vsync + mode;
    }
    while (vblank_count - target < 0) {
        Host_VBlank();
    }
    last_vsync = vblank_count;
    return 0;
}

int ResetCallback(void) {
    PSYQ_LOG("");
    vsync_cb = 0;
    return 0;
}

int VSyncCallback(void (*f)(void)) {
    PSYQ_LOG("%p", (void *)f);
    vsync_cb = f;
    return 0;
}

int Psyq_VBlankCount(void) {
    return vblank_count;
}
