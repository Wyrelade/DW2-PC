#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"
#include "main/digistatus.h"
#include "main/skilllist.h"
#include "main/spawnlist.h"
#include "main/winframe.h"
#include "main/sound.h"
#include "main/text.h"
#include "main/gpu.h"
#include "main/fade.h"
#include "main/ot.h"
#include "main/primbuf.h"
#include "main/texslot.h"
#include "main/parts.h"
#include "main/digibase.h"
#include "main/gamedata.h"
#include "main/flagtable.h"
#include "main/digidata.h"
#include "main/F400.h"
#include "main/skill.h"
#include "main/anim.h"
#include "main/model.h"
#include "main/12550.h"
#include "main/flags.h"
#include "main/savedata.h"

/* .bss (game.h order). */
Elm678 Pad_PortButtons[2];
u8 Pad_RecvBufs[0x48];
PadState Pad_State[2];
/* Scalar view of Pad_State[0].cross for one read in Stg20_BeetlePartsUpdate: cc1 schedules the
 * store through the Save_GameState pointer before it below the read only when the read is not a
 * struct member (retail order). */
DATA_LABEL(Pad_Cross, Pad_State, 0x14);

void Pad_Init(void) {
    PadInitDirect(Pad_RecvBufs, Pad_RecvBufs + 0x22);
    PadStartCom();
}

void Pad_ResetButtons(PadButtons *arg0) {
    arg0->connected = 0;
    arg0->repeatTimer = 0;
    arg0->repeating = 0;
    arg0->repeat = 0;
    arg0->prevHeld = 0;
    arg0->held = 0;
    arg0->prevHeld = 0;
}

void Pad_UpdateButtons(PadButtons *p, u8 *buf) {
    s32 n;

    p->prevHeld = p->held;
    p->held = ((buf[2] << 8) + buf[3]) ^ 0xFFFF;
    p->pressed = (p->prevHeld ^ p->held) & p->held;
    if (p->prevHeld != p->held) {
        p->repeat = p->pressed;
        p->repeating = 0;
        p->repeatTimer = 0;
        return;
    }
    n = ++p->repeatTimer;
    if (p->repeating == 0) {
        if (n >= 11) {
            goto rep;
        }
    } else if (n >= 4) {
    rep:
        p->repeating = 1;
        p->repeatTimer = 0;
        p->repeat = p->held;
        return;
    }
    p->repeat = 0;
}

void Pad_PollPort(PadBuf *a0, s32 i) {
    switch (PadGetState(i << 4)) {
    case 2:
    case 6:
        switch (Pad_PortButtons[i].initialized) {
        case 0:
        default:
            Pad_ResetButtons((PadButtons *)&Pad_PortButtons[i]);
            Pad_PortButtons[i].initialized = 1;
            break;
        case 1:
            Pad_UpdateButtons(&Pad_PortButtons[i], a0);
            break;
        }
        break;
    case 0:
    default:
        Pad_PortButtons[i].initialized = 0;
        break;
    }
}

s32 Pad_GetButtonState(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    if (arg0 & arg2) {
        r = 1;
    } else if (arg1 & arg2) {
        r = -1;
    }
    return r;
}

void Pad_Update(void) {
    s32 i;
    PadBuf *a8 = (PadBuf *)Pad_RecvBufs;

    for (i = 0; i < 2; i++) {
        if (a8[i].status != 0) {
            Pad_PortButtons[i].initialized = 0;
            Pad_PortButtons[i].held = 0;
            Pad_PortButtons[i].pressed = 0;
            Pad_PortButtons[i].repeat = 0;
            Pad_State[i].connected = 0;
        } else if ((a8[i].padType >> 4) == 4) {
            Pad_PollPort(&a8[i], i);
            Pad_State[i].connected = 1;
        } else {
            Pad_PortButtons[i].held = 0;
            Pad_PortButtons[i].pressed = 0;
            Pad_PortButtons[i].repeat = 0;
            Pad_State[i].connected = 0;
        }
        Pad_State[i].up = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x1000);
        Pad_State[i].down = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x4000);
        Pad_State[i].right = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x2000);
        Pad_State[i].left = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x8000);
        Pad_State[i].circle = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x20);
        Pad_State[i].cross = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x40);
        Pad_State[i].triangle = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x10);
        Pad_State[i].square = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x80);
        Pad_State[i].l1 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x4);
        Pad_State[i].l2 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x1);
        Pad_State[i].r1 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x8);
        Pad_State[i].r2 = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x2);
        Pad_State[i].select = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x100);
        Pad_State[i].start = Pad_GetButtonState(Pad_PortButtons[i].pressed, Pad_PortButtons[i].held, 0x800);
        Pad_State[i].held = Pad_PortButtons[i].held;
        Pad_State[i].pressed = Pad_PortButtons[i].pressed;
        Pad_State[i].repeat = Pad_PortButtons[i].repeat;
    }
}
