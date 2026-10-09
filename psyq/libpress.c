#include "libpress.h"
#include "psyq_log.h"

#include "backend/mdec.h"

/* libpress (PR.4): the MDEC work runs in backend/mdec.c. DecDCTvlc2 turns an STR frame into
 * run-length codes, DecDCTin starts the MDEC on them, DecDCTout decodes `size` words of
 * macroblocks at once and then runs the DecDCToutCallback handler before it returns. The stag1000
 * movie callback issues the next DecDCTout itself, so a call from inside the handler decodes at
 * once but only marks one more completion, which runs after the handler returns (no recursion).
 * Headless runs without --movies get no frames from libcd (P1.10 stub): DecDCTvlc2 then writes
 * an empty stream and DecDCTout is asked for 0 words. */

/* The game's run-length buffers are 0x28000 bytes (stag1000 movie.c); Psy-Q passes no size. */
#define VLC_BUF_WORDS (0x28000 / 4)

static void (*out_cb)(void);
static int in_cb;
static int pending;

void DecDCTReset(int mode) {
    PSYQ_LOG("%d", mode);
}

/* mode bit 0: 24-bit output, bit 1: 15-bit output with the mask bit set. */
void DecDCTin(u_long *buf, int mode) {
    PSYQ_LOG("%p, %d", (void *)buf, mode);
    Mdec_Start((const uint32_t *)buf, mode & 1, (mode >> 1) & 1);
}

void DecDCTout(u_long *buf, int size) {
    PSYQ_LOG("%p, %d", (void *)buf, size);
    Mdec_Out((uint32_t *)buf, size);
    if (out_cb == 0) {
        return;
    }
    if (in_cb) {
        pending = 1;
        return;
    }
    do {
        pending = 0;
        in_cb = 1;
        out_cb();
        in_cb = 0;
    } while (pending && out_cb != 0);
}

int DecDCToutCallback(void (*func)()) {
    PSYQ_LOG("%p", (void *)func);
    out_cb = (void (*)(void))func;
    return 0;
}

int DecDCTvlc2(u_long *bs, u_long *buf, DECDCTTAB table) {
    PSYQ_LOG("%p, %p, %p", (void *)bs, (void *)buf, (void *)table);
    return Mdec_Vlc((const uint8_t *)bs, (uint32_t *)buf, VLC_BUF_WORDS) < 0 ? -1 : 0;
}
