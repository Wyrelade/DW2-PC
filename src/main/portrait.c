#include "common.h"
#include "main/game.h"
#include "main/task.h"

/* Task callbacks the descriptors below name (defined further down). */
void Text_PortraitInit(Actor *arg0, s32 *arg1);
void Text_PortraitTask(Actor *a0);
void Text_PortraitDraw(Actor *a0);

/* Portrait quad mesh: 3x3 grid points (x scaled by the portrait width, y). */
Pair54 Text_PortraitQuadGrid[3][3] = {
    { { 0x2E, -90 }, { 0x51, -96 }, { 0x79, -103 } },
    { { 0x3A, -55 }, { 0x5C, -56 }, { 0x87, -57 } },
    { { 0x44, -26 }, { 0x65, -21 }, { 0x95, -13 } },
};
TaskDesc Text_PortraitDesc = {
    (TaskInitFn)Text_PortraitInit, Text_PortraitTask, Task_DefaultDestroy, Text_PortraitDraw, 0x18, 0,
};

void Text_PortraitInit(Actor *arg0, s32 *arg1) {
    ActorWork *w = arg0->work;
    w->field_0 = arg1[0];
    w->field_4 = arg1[1];
}

void Text_PortraitTask(Actor *a0) {
    Wk116CC *w = (Wk116CC *)a0->work;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
            break;
        case 1:
            return;
        }
        if (w->delay == 0) {
            switch (w->step) {
            case 0:
                v = 0xE;
                goto set;
            case 1:
                v = 0xD;
                goto set;
            case 2:
                v = 0xB;
            set:
                w->hideMask = v;
                w->palette = 0;
                w->delay = 0;
                break;
            default:
                w->hideMask = 7;
                w->delay = 2;
                w->palette = w->step - 3;
                break;
            }
            w->step++;
            if (w->step == 0x12) {
                w->step = 0xF;
            }
        } else {
            w->delay--;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 1:
            w->hideMask = 0xD;
            w->palette = 0;
            a0->stateLevel1++;
            break;
        case 2:
            w->hideMask = 0xE;
            w->palette = 0;
            a0->stateLevel1++;
            break;
        case 0:
        default:
            w->hideMask = 0xB;
            w->palette = 0;
            a0->stateLevel1++;
            break;
        case 3:
            Task_SetState0(a0, 3);
            break;
        }
        break;
    }
}

void Text_PortraitDraw(Actor *a0) {
    ActorWork *w = a0->work;
    Part11854 *e;
    Part11854 *q;
    GfxVramPos pos;
    GfxVramPos clut;
    GfxImageInfo tex;
    s32 s;
    s32 i;
    s32 j;
    u8 u;
    u8 v;

    Ft4_11854 *p;

    e = (Part11854 *)Cd_GetFileEntry(0x3120002);
    for (q = e; q->fileId != 0; q++) {
        if (q->partMask & w->field_C) {
            q->visible = 0;
        } else {
            q->visible = 1;
            q->palette = w->field_14;
            if (w->field_4 != 0) {
                q->scaleX = -0x1000;
                q->unscaled = 0;
            } else {
                q->scaleX = 0x1000;
                q->unscaled = 1;
            }
        }
    }
    Gfx_DrawParts((s32)e);
    Gfx_FindOrLoadImageSlot(w->field_0, &tex, &pos, &clut);
    s = 1;
    if (w->field_4 != 0) {
        s = -1;
    }

    p = (Ft4_11854 *)Sys_State.packet.work;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            p->c = *(Col1A9C8 *)&Gfx_NeutralRgb;
            p->tag.len = 9;
            p->c.code = 0x2C;
            p->x0 = Text_PortraitQuadGrid[j][i].field_0 * s;
            p->x1 = Text_PortraitQuadGrid[j][i + 1].field_0 * s;
            p->x2 = Text_PortraitQuadGrid[j + 1][i].field_0 * s;
            p->x3 = Text_PortraitQuadGrid[j + 1][i + 1].field_0 * s;
            p->y0 = Text_PortraitQuadGrid[j][i].field_2;
            p->y1 = Text_PortraitQuadGrid[j][i + 1].field_2;
            p->y2 = Text_PortraitQuadGrid[j + 1][i].field_2;
            p->y3 = Text_PortraitQuadGrid[j + 1][i + 1].field_2;
            u = pos.x + (tex.uBase + i * 20);
            p->u0 = p->u2 = u;
            p->u1 = p->u3 = u + 20;
            v = pos.y + j * 20;
            p->v0 = p->v1 = v;
            p->v2 = p->v3 = v + 20;
            p->tpage = tex.tpage;
            p->clut = ((tex.vramY + clut.y) << 6) | (((tex.vramX + clut.x) >> 4) & 0x3F);
            p->tag.addr = ((PTag11854 *)Sys_State.otLayers.s[0])->addr;
            ((PTag11854 *)Sys_State.otLayers.s[0])->addr = (u32)p;
            p++;
        }
    }
    Sys_State.packet.addr = (s32)p;
}

void Text_PortraitSetImage(Actor *arg0, s32 arg1) {
    arg0->work->field_0 = arg1;
}
