#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_MapBgInit(Actor *a, s32 v);
void Stg20_MapBgUpdate(Actor *a);
void Stg20_MapBgDraw(Actor *a);

Stg20Pos2 Stg20_ShakeOffsets[4] = { { -1, -1 }, { 0, 2 }, { 2, -2 }, { 0, 2 } };
TaskDesc Stg20_MapBgDesc = {
    (TaskInitFn)Stg20_MapBgInit, Stg20_MapBgUpdate, Task_DefaultDestroy, Stg20_MapBgDraw, 0x38, 0,
};

u8 Stg20_MapGrid[24][24];

void Stg20_BuildMapGrid(Actor *a) {
    s32 x, y;
    u8 *p;
    s32 bit = 0;
    p = Stg20_GetMapInfo()->bits;
    p--;
    for (x = 0; x < 0x18; x++) {
        for (y = 0; y < 0x18; y++) {
            bit <<= 1;
            if (!(y & 7)) {
                bit = 1;
                p++;
            }
            if (*p & bit) {
                Stg20_MapGrid[y][x] = 1;
            } else {
                Stg20_MapGrid[y][x] = 0;
            }
        }
    }
}

s32 Stg20_GetGridCell(Stg20Cell *c) {
    return Stg20_MapGrid[c->x][c->y];
}

void Stg20_MarkGridOccupant(Stg20Cell *c, s32 set, s32 flag) {
    s32 bit = 0x40;
    s32 m;

    if (flag) {
        bit = 0x80;
    }
    if (set) {
        Stg20_MapGrid[c->x][c->y] |= bit;
    } else {
        m = 0xFF;
        Stg20_MapGrid[c->x][c->y] &= m - bit;
    }
}

void Stg20_MapBgInit(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
    Stg20_BuildMapGrid(a);
}

void Stg20_MapBgUpdate(Actor *a) {
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    s32 *tbl;
    s32 i;

    switch (a->stateLevel0) {
    case 0:
        tbl = (s32 *)Cd_GetFileOrNull(w->fileId);
        for (i = 0; i < 10; i++) {
            if (tbl[i] != 0) {
                w->ids[i] = (w->fileId << 16) + i;
            } else {
                w->ids[i] = 0;
            }
        }
        w->field_2C = 0;
        w->geomY = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                a->elapsed = 0;
                Task_NextState2(a);
            case 1:
                w->field_2C += Stg20_ShakeOffsets[((Stg20BlinkTask *)a)->frameCount & 3].x;
                w->geomY += Stg20_ShakeOffsets[((Stg20BlinkTask *)a)->frameCount & 3].y;
                if (a->elapsed >= 0x78) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg20_MapBgDraw(Actor *a) {
    s32 gx = 0;
    s32 gy = 0;
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    Actor *e;
    AllocC40 *t;
    GfxPartPkt *p;
    GfxPartOTag *ot;
    GfxPartTexSlot *tex;
    GfxPart *parts;
    GfxPart *q;
    s32 n;
    s32 j;
    s32 i;
    s16 x;
    s32 sx;

    e = Stg20_FindWalkerByDigiId(0x1F4);
    if (e != 0) {
        if (w->settleFrames >= 5) {
            n = 1;
        } else {
            w->settleFrames++;
            n = 0x14;
        }
        for (j = 0; j < n; j++) {
            t = ((ContC40 *)e)->transform;
            Actor_ProjectToScreen(e);
            if (t->screenX < -0x18) {
                w->field_2C += (s16)(-t->screenX - 0x18) >> 3;
            } else if (t->screenX > 0x18) {
                w->field_2C -= (s16)(t->screenX - 0x18) >> 3;
            }
            if (t->screenY < -0x18) {
                w->geomY += (s16)(-t->screenY - 0x18) >> 3;
            } else if (t->screenY > 0x18) {
                w->geomY -= (s16)(t->screenY - 0x18) >> 3;
            }
            if (w->geomY > 0x20) {
                w->geomY = 0x20;
            }
            gx = w->field_2C / 2 - 0xA0;
            gy = w->geomY / 2;
            SetGeomOffset(w->field_2C, w->geomY);
        }
    }
    ot = (GfxPartOTag *)Sys_State.otLayers.addr[6];
    p = (GfxPartPkt *)Sys_State.packet.addr;
    for (sx = gx - 0xA0, i = 0; i < 10; i++) {
        if (w->ids[i] != 0) {
            tex = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(w->ids[i]);
            do {
                p->s.c = *(Col1CE9C *)&Gfx_NeutralRgb;
                p->s.tag.len = 4;
                p->s.c.code = 0x64;
                x = sx + i * 64;
                p->s.x0 = x;
                if (p->s.x0 < -0xE0) {
                    break;
                }
                if (p->s.x0 > 0xA0) {
                    break;
                }
                p->s.u0 = tex->u;
                p->s.w = 0x40;
                p->s.y0 = gy - 0x80;
                p->s.v0 = 0;
                p->s.h = 0xFF;
                p->s.clut = (tex->index + 0x1E0) << 6;
                p->s.tag.addr = ot->addr;
                ot->addr = (u32)p;
                p = (GfxPartPkt *)(&p->s + 1);
                p->t.tag.len = 1;
                p->t.code = 0xE1000600 | (tex->tpage & 0x9FF);
                p->t.tag.addr = ot->addr;
                ot->addr = (u32)p;
                p = (GfxPartPkt *)(&p->t + 1);
            } while (0);
        }
    }
    Sys_State.packet.addr = (s32)p;
    if (Stg20_GetMapInfo()->overlayParts != 0) {
        parts = (GfxPart *)Cd_GetFileEntry(Stg20_GetMapInfo()->overlayParts);
        for (q = parts; q->fileId != 0; q++) {
            if (q->groupMask & 4) {
                q->palette = Math_CycleRange(a->elapsed, 8, 0, 7);
            }
            q->x = gx + 0xA0;
            q->y = gy;
        }
        Gfx_DrawParts((s32)parts);
    }
}

void Stg20_StartBgShake(void) {
    Actor *a = (Actor *)Task_FindFirst(0x301, -1, -1);

    if (a != NULL && a->stateLevel0 == 1) {
        Task_SetState1(a, 1);
    }
}
