#include "libetc.h"
#include "psyq_log.h"
#include "psyq_vblank.h"

/* libetc (P1.1): a VBlank counter and the VSyncCallback handler. There is no timer yet: each
 * Psyq_VBlank() call is one VBlank (VSync waits and the host's Sys_FlipPending pump call it).
 * P1.2 paces it at 59.94 Hz from the SDL3 host. */

static void (*vsync_cb)(void);
static volatile int vblank_count;

void Psyq_VBlank(void) {
    vblank_count++;
    if (vsync_cb != 0) {
        vsync_cb();
    }
}

int VSync(int mode) {
    int start = vblank_count;

    PSYQ_LOG("%d", mode);
    if (mode < 0) {
        return vblank_count;
    }
    if (mode == 1) {
        return 0; /* horizontal blank count since the last VSync */
    }
    /* 0: next VBlank; n > 1: n VBlanks after the last one. */
    do {
        Psyq_VBlank();
    } while (vblank_count - start < (mode > 1 ? mode : 1));
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
