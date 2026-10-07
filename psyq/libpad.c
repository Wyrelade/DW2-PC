#include "libpad.h"
#include "psyq_log.h"

/* libpad stubs (P1.1): no pad connected; the receive buffers stay as the game set them.
 * Host input into the pad reply buffers is P1.7. */

static u_char *recv_bufs[2];

void PadInitDirect(u_char *pad1, u_char *pad2) {
    PSYQ_LOG("%p, %p", (void *)pad1, (void *)pad2);
    recv_bufs[0] = pad1;
    recv_bufs[1] = pad2;
}

void PadStartCom(void) {
    PSYQ_LOG("");
}

int PadGetState(int port) {
    PSYQ_LOG("0x%X", port);
    return PadStateDiscon;
}
