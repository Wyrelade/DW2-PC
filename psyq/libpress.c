#include "libpress.h"
#include "psyq_log.h"

/* libpress stubs (P1.1): no MDEC. STR movies are P1.10. */

void DecDCTReset(int mode) {
    PSYQ_LOG("%d", mode);
}

void DecDCTin(u_long *buf, int mode) {
    PSYQ_LOG("%p, %d", (void *)buf, mode);
}

void DecDCTout(u_long *buf, int size) {
    PSYQ_LOG("%p, %d", (void *)buf, size);
}

int DecDCToutCallback(void (*func)()) {
    PSYQ_LOG("%p", (void *)func);
    return 0;
}

int DecDCTvlc2(u_long *bs, u_long *buf, DECDCTTAB table) {
    PSYQ_LOG("%p, %p, %p", (void *)bs, (void *)buf, (void *)table);
    return 0;
}
