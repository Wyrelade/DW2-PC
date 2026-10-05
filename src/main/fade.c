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

FadeState Gfx_FadeState = { 1, 0, 0 };

void Gfx_FadeInFromBlack(s32 arg0) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 2;
    Gfx_FadeState.speed = arg0;
    Sys_State.fadeLevel = arg0 + 0xFF;
}

void Gfx_FadeOutToBlack(s32 arg0) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 3;
    Gfx_FadeState.speed = arg0;
}

void Gfx_FadeInFromWhite(s32 arg0) {
    Gfx_FadeState.additive = 1;
    Gfx_FadeState.mode = 2;
    Gfx_FadeState.speed = arg0;
    Sys_State.fadeLevel = arg0 + 0xFF;
}

void Gfx_FadeOutToWhite(s32 arg0) {
    Gfx_FadeState.additive = 1;
    Gfx_FadeState.mode = 3;
    Gfx_FadeState.speed = arg0;
}

void Gfx_FadeClear(void) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 0;
}

void Gfx_FadeSetBlack(void) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 1;
}

void Gfx_DrawFade(void) {
    GfxFadePkt *p;
    GfxFadeMode *q;
    GfxPartOTag *ot;
    s32 w;
    s32 h;
    u8 c;
    s32 abr;

    if (Sys_State.packet.work == 0) {
        return;
    }
    for (;;) {
        switch (Gfx_FadeState.mode) {
        default:
        case 0:
            Sys_State.fadeLevel = 0;
            return;
        case 1:
            Sys_State.fadeLevel = 0xFF;
            goto check;
        case 2:
            Sys_State.fadeLevel -= Gfx_FadeState.speed;
            if (Sys_State.fadeLevel > 0) {
                goto draw;
            }
            Sys_State.fadeLevel = 0;
            Gfx_FadeState.mode = 0;
            continue;
        case 3:
            Sys_State.fadeLevel += Gfx_FadeState.speed;
            if (Sys_State.fadeLevel < 0xFF) {
                goto check;
            }
            Sys_State.fadeLevel = 0xFF;
            Gfx_FadeState.mode = 1;
            continue;
        }
    }
check:
    if (Sys_State.fadeLevel == 0) {
        return;
    }
draw:
    abr = 2;
    q = (GfxFadeMode *)Sys_State.packet.work;
    p = (GfxFadePkt *)q;
    ot = (GfxPartOTag *)Sys_State.otLayers.s[0];
    p->t.len = 5;
    p->code = 0x2A;
    c = Sys_State.fadeLevel;
    p->g = c;
    p->b = c;
    p->r = c;
    w = Sys_State.centerX.lo;
    p->x0 = p->x2 = -w;
    p->x1 = p->x3 = w;
    h = Sys_State.centerY.lo;
    p->y0 = p->y1 = -h;
    p->y2 = p->y3 = h;
    p->t.addr = ot->addr;
    ot->addr = (u32)p;
    q = &p->m;
    if (Gfx_FadeState.additive != 0) {
        abr = 1;
    }
    q->t.len = 1;
    q->mode = (abr << 5) | 0xE1000400;
    p->m.t.addr = ot->addr;
    ot->addr = (u32)q;
    q = (GfxFadeMode *)(p + 1);
    Sys_State.packet.work = (ActorWork *)q;
}
