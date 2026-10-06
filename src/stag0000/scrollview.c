#include "common.h"
#include "stag0000/stag0000.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_ScrollViewTask(Actor *arg0);
void Stg00_ScrollViewDraw(Actor *arg0);

TaskDesc Stg00_ScrollViewDesc = { 0, Stg00_ScrollViewTask, Task_DefaultDestroy, Stg00_ScrollViewDraw, 8, 0 };
/* Stg00_ScrollViewDraw reads this descriptor and the 14 words after it as texture ids
 * (a debug view; the table it meant is not in the overlay). */
DATA_LABEL(Stg00_ScrollTileTex, Stg00_ScrollViewDesc, 0);

void Stg00_ScrollViewTask(Actor *arg0) {
    Stg00ScrollWork *w = (Stg00ScrollWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        w->scrollX = 0;
        w->scrollY = 0;
        Task_NextState0(arg0);
        break;
    case 1:
        if (Pad_State[0].up) {
            w->scrollY += 4;
        }
        if (Pad_State[0].down) {
            w->scrollY -= 4;
        }
        if (Pad_State[0].right) {
            w->scrollX -= 4;
        }
        if (Pad_State[0].left) {
            w->scrollX += 4;
        }
        if (w->scrollX > 0) {
            w->scrollX = 0;
        }
        if (w->scrollX < -0x3C0) {
            w->scrollX = -0x3C0;
        }
        if (w->scrollY > 0) {
            w->scrollY = 0;
        }
        if (w->scrollY < -0x300) {
            w->scrollY = -0x300;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_InitTileSprt(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s32 arg2, s32 arg3) {
    arg0->c = *(Col1A9C8 *)&Gfx_NeutralRgb;
    arg0->tag.len = 4;
    arg0->c.code = 0x64;
    arg0->x0 = arg2;
    arg0->u0 = arg1->u;
    arg0->w = 0x40;
    arg0->y0 = arg3;
    arg0->v0 = 0;
    arg0->h = 0x100;
    arg0->clut = (arg1->index + 0x1E0) << 6;
}

void Stg00_ScrollViewDraw(Actor *arg0) {
    Stg00ScrollWork *w = (Stg00ScrollWork *)arg0->work;
    GfxPartOTag *ot = (GfxPartOTag *)Sys_State.otLayers.addr[6];
    GfxPartPkt *p = (GfxPartPkt *)Sys_State.packet.addr;
    GfxPartTexSlot *t;
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 20; j++) {
            t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(Stg00_ScrollTileTex[j % 10 + (i % 2) * 10]);
            x = w->scrollX - 0xA0;
            y = w->scrollY - 0x78;
            Stg00_InitTileSprt((Stg00Sprt *)&p->s, t, j * 64 + x, i * 256 + y);
            p->s.tag.addr = ot->addr;
            ot->addr = (u32)p;
            p = (GfxPartPkt *)(&p->s + 1);
            p->t.tag.len = 1;
            p->t.code = 0xE1000600 | (t->tpage & 0x9FF);
            p->t.tag.addr = ot->addr;
            ot->addr = (u32)p;
            p = (GfxPartPkt *)(&p->t + 1);
        }
    }
    Sys_State.packet.addr = (s32)p;
}
