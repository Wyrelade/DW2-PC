#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/msgwin.h"

TaskDesc Stg40_MsgWinDesc = {
    (TaskInitFn)Stg40_MsgWinInit, Stg40_MsgWinUpdate, Task_DefaultDestroy, (TaskFn)Stg40_MsgWinDraw, 0x28, 0,
};
Actor *Stg40_MsgWinTask;
s32 *Stg40_MsgWinTexts;
s32 D_80072B88[2];
u8 Stg40_DigitBufs[4][8];

u8 *Stg40_NumToDigits(s32 i, s32 v) {
    s32 d = 10000;
    s32 nz = 0;
    u8 *p = Stg40_DigitBufs[i];
    s32 k;
    s32 q;

    v = (v > 99999) ? 99999 : v;
    for (k = 0; k < 4; k++) {
        q = v / d;
        *p = q;
        if (*p != 0) {
            nz = -1;
        }
        v -= q * d;
        p -= nz;
        d /= 10;
    }
    p[1] = 0xFF;
    p[0] = v;
    p = Stg40_DigitBufs[i];
    return p;
}

void Stg40_MsgWinOpen(s32 i, s32 file, s32 a2, s32 a3) {
    TextOpenArgs arg;
    s32 *p;

    arg.bigFont = 1;
    arg.color = 0;
    arg.x = 0;
    arg.y = 0;
    arg.charAdvance = 0;
    arg.lineAdvance = 0xF;
    arg.text = (s32)Cd_GetFileEntry(file);
    arg.charDelay = 1;
    p = &Stg40_MsgWinTexts[i];
    p[5] = 0;
    arg.strArg0 = a2;
    arg.strArg1 = a3;
    Text_Open(p, &arg);
}

void Stg40_MsgWinClose(s32 i) {
    Text_Close(&Stg40_MsgWinTexts[i]);
}

s32 Stg40_MsgWinIsFinished(s32 i) {
    s32 *p = &Stg40_MsgWinTexts[i];

    return Text_IsFinished(*p);
}

s32 Stg40_MsgWinCloseIfDone(s32 i) {
    s32 r = 0;

    if (Stg40_MsgWinIsFinished(i) == 1) {
        Stg40_MsgWinClose(i);
        r = 1;
    }
    return r;
}

s32 Stg40_MsgWinGetChoice(s32 i) {
    s32 *p = &Stg40_MsgWinTexts[i];

    return Text_WaitYesNo(*p);
}

void Stg40_MsgWinInit(void) {
}

void Stg40_MsgWinUpdate(Actor *a0) {
    s32 *w = (s32 *)a0->work;
    s32 i;
    s32 m;

    switch (a0->stateLevel0) {
    case 1:
    case 2:
        break;
    case 0:
    default:
        m = -1;
        Stg40_MsgWinTask = a0;
        Stg40_MsgWinTexts = w;
        for (i = 4; i >= 0; i--) {
            w[i] = m;
        }
        Task_NextState0(a0);
        break;
    }
}

void Stg40_MsgWinDraw(void) {
}
