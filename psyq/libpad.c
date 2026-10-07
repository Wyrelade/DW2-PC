#include "libpad.h"
#include "psyq_log.h"
#include "psyq_vblank.h"
#include "host/host.h"

/* libpad direct mode (P1.7). On the PS1, PadInitDirect hands libpad the two receive buffers and
 * after PadStartCom the VBlank interrupt reads both controller ports into them; main/pad.c
 * (Pad_Update) decodes them in the update pass. Here Psyq_PadVBlank, called from the VBlank
 * "interrupt" before the VSyncCallback handler, writes the host buttons in the same reply
 * format: byte 0 status (0x00 ok, 0xFF no controller), byte 1 type / length (0x41 = digital
 * pad, 1 halfword of data), bytes 2-3 the buttons, active low, in reply bit order. */

#define PAD_TYPE_DIGITAL 0x41

static u_char *recv_bufs[2];
static int started;

void PadInitDirect(u_char *pad1, u_char *pad2) {
    PSYQ_LOG("%p, %p", (void *)pad1, (void *)pad2);
    recv_bufs[0] = pad1;
    recv_bufs[1] = pad2;
}

void PadStartCom(void) {
    PSYQ_LOG("");
    started = 1;
}

/* port = 0x00 / 0x10 (port << 4, no multitap). A digital pad stays in FindCTP1 (no actuators,
 * nothing to set up); main/pad.c accepts 2 and 6. */
int PadGetState(int port) {
    PSYQ_LOG("0x%X", port);
    if (!started || !Host_PadConnected((port >> 4) & 1)) {
        return PadStateDiscon;
    }
    return PadStateFindCTP1;
}

void Psyq_PadVBlank(void) {
    int p;

    if (!started) {
        return;
    }
    for (p = 0; p < 2; p++) {
        u_char *b = recv_bufs[p];
        unsigned short m;

        if (b == 0) {
            continue;
        }
        if (!Host_PadConnected(p)) {
            b[0] = 0xFF;
            continue;
        }
        m = Host_PadButtons(p);
        b[0] = 0x00;
        b[1] = PAD_TYPE_DIGITAL;
        b[2] = (u_char)~(m & 0xFF);
        b[3] = (u_char)~(m >> 8);
    }
}
