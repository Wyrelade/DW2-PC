#include "libpress.h"
#include "psyq_log.h"

/* libpress, P1.10 prototype stub: no MDEC. DecDCTout "finishes" at once: it runs the
 * DecDCToutCallback handler before it returns (no image data is written). The stag1000 movie
 * callback issues the next DecDCTout itself, so a call from inside the handler only marks one
 * more completion, which runs after the handler returns (no recursion). */

static void (*out_cb)(void);
static int in_cb;
static int pending;

void DecDCTReset(int mode) {
    PSYQ_LOG("%d", mode);
}

void DecDCTin(u_long *buf, int mode) {
    PSYQ_LOG("%p, %d", (void *)buf, mode);
}

void DecDCTout(u_long *buf, int size) {
    PSYQ_LOG("%p, %d", (void *)buf, size);
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
    return 0;
}
