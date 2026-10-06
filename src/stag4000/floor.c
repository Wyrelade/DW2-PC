#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"

u8 Stg40_FloorPrimIdx[] = {
    0x04, 0x02, 0x06, 0x03, 0x05, 0x00, 0x01, 0x00, 0x0B, 0x09, 0x0D, 0x0A, 0x0C, 0x07, 0x08, 0x07,
    0x12, 0x10, 0x14, 0x11, 0x13, 0x0E, 0x0F, 0x0E, 0x33, 0x31, 0x35, 0x32, 0x34, 0x2F, 0x30, 0x2F,
    0x33, 0x31, 0x35, 0x32, 0x34, 0x2F, 0x30, 0x2F, 0x3A, 0x38, 0x3C, 0x39, 0x3B, 0x36, 0x37, 0x36,
    0x16, 0x19, 0x15, 0x17, 0x18, 0x3D, 0x3E, 0x3F, 0x40, 0x41,
};
u8 Stg40_ShadowPrimIdx = 0x1A;
u8 Stg40_WallPrimIdx[] = {
    0x1B, 0x1E, 0x1C, 0x1F, 0x1D, 0x25, 0x28, 0x26, 0x29, 0x27,
    0x20, 0x23, 0x21, 0x24, 0x22, 0x2A, 0x2D, 0x2B, 0x2E, 0x2C,
};
Stg40WallSide Stg40_WallSides[] = {
    { 0x0800, 0, 0, 0, 1, 0, 0, 0, 64 },
    { 0x0400, 2, 1, 1, 0, 1, 0, 1, 127 },
    { 0x0200, 4, 0, 1, 0, 0, 0, 0, 64 },
    { 0x0100, 6, 1, 0, 1, 1, 1, 0, 127 },
};
TaskDesc Stg40_FloorDesc = {
    (TaskInitFn)Stg40_FloorInit, Stg40_FloorUpdate, Task_DefaultDestroy, Stg40_FloorDraw, 0x1EA4, 0,
};

Actor *Stg40_FloorTask;
Stg40FloorWork *Stg40_FloorWork;

const Stg40Quad Stg40_ShadowCorners = { { -0x500, -0x400, 0x500, -0x400, -0x500, 0x400, 0x500, 0x400 } };
void Stg40_DrawEntityShadow(Stg40Loc *loc) {
    struct {
        s16 x;
        s16 y;
        u8 _pad4[8];
    } out[4];
    struct {
        s16 x;
        s16 y;
        s16 z;
    } vec;
    Mat1F668 mtx;
    Stg40Quad quad;
    s32 xoff;
    s32 zoff;
    Stg40FloorWork *w;
    Stg40Vtx *a;
    Stg40Vtx *b;
    Stg40FT4 *pkt;
    s32 row;
    s32 col;
    s32 i;
    s32 count;
    s32 dz;
    s32 centerX;
    s32 centerY;

    if ((loc->posX & 0x3F) == 0 && (loc->posY & 0x3F) == 0) {
        col = loc->posX / 64 - Stg40_RootState->viewX / 64 + 4;
        row = loc->posY / 64 - Stg40_RootState->viewY / 64 + 4;
        if (col >= 0 && col < Stg40_FloorWork->gridCols - 1 && row >= 0 && row < Stg40_FloorWork->gridRows - 1) {
            w = Stg40_FloorWork;
            a = &w->verts[row][col];
            b = &w->verts[row + 1][col];
            pkt = (Stg40FT4 *)Sys_State.packet.addr;
            *pkt = w->prims[Stg40_ShadowPrimIdx];
            pkt->x0 = a[0].s[0].x;
            pkt->y0 = a[0].s[0].y;
            pkt->x1 = a[1].s[0].x;
            pkt->y1 = a[1].s[0].y;
            pkt->x2 = b[0].s[0].x;
            pkt->y2 = b[0].s[0].y;
            pkt->x3 = b[1].s[0].x;
            pkt->y3 = b[1].s[0].y;
            pkt->tag.f.addr = ((Stg40OTag *)Sys_State.otLayers.u[4])->addr;
            ((Stg40OTag *)Sys_State.otLayers.u[4])->addr = (u32)pkt;
            pkt++;
            Sys_State.packet.addr = (s32)pkt;
        }
        return;
    }
    mtx = GsWSMATRIX;
    quad = Stg40_ShadowCorners;
    centerX = Sys_State.centerX.s;
    centerY = Sys_State.centerY.s;
    count = 0;
    PushMatrix();
    SetRotMatrix(&mtx);
    SetTransMatrix(&mtx);
    dz = (loc->posY - Stg40_RootState->viewY) << 11;
    xoff = (loc->posX - Stg40_RootState->viewX) * 40;
    zoff = dz / 64;
    zoff = -zoff;
    vec.y = 0;
    for (i = 0; i < 4; i++) {
        vec.x = quad.v[i * 2] + xoff;
        vec.z = quad.v[i * 2 + 1] + zoff;
        RotTransPers(&vec, &out[i], 0, 0);
        {
            s32 x = out[i].x;
            s32 y;

            if (centerX != 0x140) {
                x >>= 1;
            }
            out[i].x = x;
            y = out[i].y;
            if (centerY != 0xF0) {
                y >>= 1;
            }
            out[i].y = y;
        }
        count += ((out[i].x < 0 ? -out[i].x : out[i].x) < centerX) && ((out[i].y < 0 ? -out[i].y : out[i].y) < centerY);
    }
    if (count != 0) {
        pkt = (Stg40FT4 *)Sys_State.packet.addr;
        *pkt = Stg40_FloorWork->prims[Stg40_ShadowPrimIdx];
        pkt->x0 = out[0].x;
        pkt->y0 = out[0].y;
        pkt->x1 = out[1].x;
        pkt->y1 = out[1].y;
        pkt->x2 = out[2].x;
        pkt->y2 = out[2].y;
        pkt->x3 = out[3].x;
        pkt->y3 = out[3].y;
        pkt->tag.f.addr = ((Stg40OTag *)Sys_State.otLayers.u[4])->addr;
        ((Stg40OTag *)Sys_State.otLayers.u[4])->addr = (u32)pkt;
        pkt++;
        Sys_State.packet.addr = (s32)pkt;
    }
    PopMatrix();
}

void Stg40_ScrollFollow(Stg40Loc *loc) {
    Dung_StatePtr->scrollTarget = loc;
    Task_SetState1(Stg40_FloorTask, 0);
}

void Stg40_ScrollTo(s32 a0, s32 a1, s32 a2) {
    Actor *t = Stg40_FloorTask;
    Stg40B60 *b = Stg40_RootState;
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)t->work;

    w->scrollGoalX = a0;
    w->scrollGoalY = a1;
    w->scrollStartX = b->viewX;
    w->scrollStartY = b->viewY;
    w->scrollFrames = a2;
    Task_SetState1(t, 1);
}

void Stg40_ScrollToFollow(Stg40Loc *loc, s32 a1) {
    Actor *t = Stg40_FloorTask;
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)t->work;
    Stg40B60 *b;

    w->scrollGoalX = loc->posX;
    w->scrollGoalY = loc->posY;
    b = Stg40_RootState;
    w->scrollStartX = b->viewX;
    w->scrollStartY = b->viewY;
    w->scrollFrames = a1;
    Dung_StatePtr->scrollTarget = loc;
    Task_SetState1(t, 2);
}

s32 Stg40_IsScrollDone(void) {
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)Stg40_FloorTask->work;
    s32 r = 0;

    if (Stg40_RootState->viewX == w->scrollGoalX && Stg40_RootState->viewY == w->scrollGoalY) {
        r = -1;
    }
    return r;
}

void Stg40_ScrollStep(Actor *a0) {
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)a0->work;
    s32 x0 = w->scrollGoalX;
    s32 y0 = w->scrollGoalY;
    s32 n = w->scrollFrames;
    s32 k = n - a0->stateLevel2;
    s32 dx = (x0 - w->scrollStartX) * k / n;
    s32 dy = (y0 - w->scrollStartY) * k / n;
    Stg40B60 *b = Stg40_RootState;

    b->viewX = x0 - dx;
    b->viewY = y0 - dy;
    a0->stateLevel2++;
}

void Stg40_ScrollUpdate(Actor *a0) {
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)a0->work;

    switch (a0->stateLevel1) {
    case 0:
    default:
        Stg40_RootState->viewX = Dung_StatePtr->scrollTarget->posX;
        Stg40_RootState->viewY = Dung_StatePtr->scrollTarget->posY;
        break;
    case 1:
        if (a0->stateLevel2 < w->scrollFrames) {
            Stg40_ScrollStep(a0);
        } else {
            Stg40_RootState->viewX = w->scrollGoalX;
            Stg40_RootState->viewY = w->scrollGoalY;
        }
        break;
    case 2:
        if (a0->stateLevel2 < w->scrollFrames) {
            Stg40_ScrollStep(a0);
        } else {
            Stg40_RootState->viewX = w->scrollGoalX;
            Stg40_RootState->viewY = w->scrollGoalY;
            Task_SetState1(a0, 0);
        }
        break;
    }
}

s32 Stg40_Max4(s32 a, s32 b, s32 c, s32 d) {
    if (a >= b) {
        b = a;
    }
    a = b;
    if (a >= c) {
        c = a;
    }
    a = c;
    if (a >= d) {
        d = a;
    }
    return d;
}

s32 Stg40_Min4(s32 a, s32 b, s32 c, s32 d) {
    if (b >= a) {
        b = a;
    }
    a = b;
    if (c >= a) {
        c = a;
    }
    a = c;
    if (d >= a) {
        d = a;
    }
    return d;
}

void Stg40_ProjectGrid(Stg40FloorWork *w) {
    Stg40Vec3 vec;
    Mat1F668 mtx;
    s32 centerX = Sys_State.centerX.s;
    s32 centerY = Sys_State.centerY.s;
    s32 rows;
    s32 shiftX;
    s32 shiftY;
    s32 shiftZ;
    s32 cols;
    s32 step;
    s32 row;
    s32 col;
    s32 t;
    Stg40Vtx *v;
    Stg40Vtx *below;
    Stg40Vtx *p;
    union {
        s32 s;
        s16 lo;
    } n;

    mtx = GsWSMATRIX;
    shiftX = centerX != 0x140;
    shiftY = centerY != 0xF0;
    shiftZ = Sys_State.otLayerLen[3] - 2;
    PushMatrix();
    SetRotMatrix(&mtx);
    SetTransMatrix(&mtx);
    rows = 0xA;
    if (Stg40_RootState->viewY & 0x3F) {
        rows = 0xB;
    }
    cols = 0xA;
    if (Stg40_RootState->viewX & 0x3F) {
        cols = 0xB;
    }
    n.lo = rows;
    w->gridCols = cols;
    w->gridRows = n.lo;
    vec.vy = 0;
    t = (Stg40_RootState->viewY & 0x3F) << 11;
    if (t < 0) {
        t += 0x3F;
    }
    vec.vz = ((u32)t >> 6) + 0x2400;
    step = 0x500;
    if (Dung_StatePtr->floorHdr->field_4 != 0) {
        step = -0x500;
    }
    for (row = 0; row < rows; row++) {
        t = (Stg40_RootState->viewX & 0x3F) * 0xA00;
        if (t < 0) {
            t += 0x3F;
        }
        vec.vx = -(t >> 6) - 0x2D00;
        v = w->verts[row];
        for (col = 0; col < cols; col++) {
            v->s[0].otz = RotTransPers(&vec, &v->s[0].x, 0, 0);
            v->s[0].x = v->s[0].x >> shiftX;
            v->s[0].y = v->s[0].y >> shiftY;
            v->s[0].otz = v->s[0].otz >> shiftZ;
            v->s[0].flag = ((v->s[0].x < 0 ? -v->s[0].x : v->s[0].x) < centerX)
                && ((v->s[0].y < 0 ? -v->s[0].y : v->s[0].y) < centerY);
            vec.vy += step;
            v->s[1].otz = RotTransPers(&vec, &v->s[1].x, 0, 0);
            v->s[1].x = v->s[1].x >> shiftX;
            v->s[1].y = v->s[1].y >> shiftY;
            v->s[1].otz = v->s[1].otz >> shiftZ;
            vec.vy -= step;
            v->s[1].flag = ((v->s[1].x < 0 ? -v->s[1].x : v->s[1].x) < centerX)
                && ((v->s[1].y < 0 ? -v->s[1].y : v->s[1].y) < centerY);
            vec.vx += 0xA00;
            v++;
        }
        vec.vz -= 0x800;
    }

    for (row = 0; row < rows; row++) {
        p = w->verts[row];
        below = w->verts[row + 1];
        for (col = 0; col < cols; col++) {
            if (col != cols - 1) {
                p->otzRight = Stg40_Max4(p->s[0].otz, p->s[1].otz, p[1].s[0].otz, p[1].s[1].otz);
            }
            if (row != rows - 1) {
                p->otzDown = Stg40_Max4(p->s[0].otz, p->s[1].otz, below->s[0].otz, below->s[1].otz);
            }
            p++;
            below++;
        }
    }
    PopMatrix();
}

void Stg40_FillTileCache(ActorWork *arg0)
{
    Stg40Cell *grid;
    s32 rowCount;
    s32 colCount;
    s32 gridCols;
    s32 gridRows;
    Stg40FloorHeader *e54;
    s32 mapRow;
    s32 row;
    s32 col;
    s32 mapCol;
    Stg40Tile *tp;
    Stg40Vtx *v0p;
    Stg40Vtx *v1p;
    s32 r;
    s32 k;
    s32 a;
    s32 lt400;
    s32 n;

    e54 = Dung_StatePtr->floorHdr;
    grid = (Stg40Cell *)Dung_StatePtr->cells;
    rowCount = 9;
    gridCols = e54->cols;
    gridRows = e54->rows;
    if (Stg40_RootState->viewY & 0x3F) {
        rowCount = 0xA;
    }
    colCount = 9;
    if (Stg40_RootState->viewX & 0x3F) {
        colCount = 0xA;
    }
    mapRow = Stg40_RootState->viewY / 64 - 4;
    for (row = 0; row < rowCount; row++) {
        tp = ((Stg40FloorWork *)arg0)->tiles[row];
        v0p = ((Stg40FloorWork *)arg0)->verts[row];
        v1p = ((Stg40FloorWork *)arg0)->verts[row + 1];
        mapCol = Stg40_RootState->viewX / 64 - 4;
        for (col = 0; col < colCount; col++) {
            tp->texOtz = Stg40_Max4(v0p[0].s[0].otz, v0p[1].s[0].otz, v1p[0].s[0].otz, v1p[1].s[0].otz);
            tp->otz = Stg40_Min4(v0p[0].s[1].otz, v0p[1].s[1].otz, v1p[0].s[1].otz, v1p[1].s[1].otz);
            if (mapCol < 0 || mapRow < 0 || mapCol >= gridCols || mapRow >= gridRows) {
                tp->flags = 0;
                tp->wallBits = 0;
                tp->primIdx = 0;
            } else {
                r = Rand_GetAt(mapCol + (mapRow << 6));
                tp->flags = grid[mapRow * gridCols + mapCol].flags;
                tp->wallBits = grid[mapRow * gridCols + mapCol].wallBits;
                k = tp->flags & 0xF;
                switch (k) {
                case 0:
                    tp->primIdx = 0;
                    break;
                case 1:
                case 2:
                    n = 0;
                    if (k == 1) {
                        n = 0x18;
                    }
                    tp->primIdx = n;
                    a = tp->primIdx + ((tp->flags >> 9) & 1);
                    tp->primIdx = a;
                    a = tp->primIdx;
                    if (tp->flags & 0x80) {
                        a += 2;
                    }
                    tp->primIdx = a;
                    a = tp->primIdx;
                    if (tp->flags & 0x800) {
                        a += 4;
                    }
                    tp->primIdx = a;
                    a = tp->primIdx;
                    if ((u16)r < 0x200) {
                        a += 8;
                    }
                    tp->primIdx = a;
                    a = tp->primIdx;
                    if ((u16)r < 0x400) {
                        a += 8;
                    }
                    tp->primIdx = a;
                    a = tp->primIdx;
                    if ((u16)r < 0x400) {
                        a |= 0x80;
                    }
                    tp->primIdx = a;
                    break;
                default:
                    tp->primIdx = (tp->flags & 0xF) + 0x2D;
                    a = tp->primIdx;
                    if ((u16)r < 0x400) {
                        a |= 0x80;
                    }
                    tp->primIdx = a;
                    break;
                }
            }
            mapCol++;
            v0p++;
            v1p++;
            tp++;
        }
        mapRow++;
    }
}

void Stg40_MapPosToWorld(s32 x, s32 z, s32 y, Stg40Vec3 *out) {
    Stg40B60 *b = Stg40_RootState;
    s32 t;

    out->vz = -(((z - b->viewY) << 11) / 64);
    t = x - b->viewX;
    out->vy = -y;
    out->vx = t * 40;
}

s32 Stg40_DrawTileWalls(Stg40FloorWork *w, s32 pkt, s32 x, s32 y)
{
    Stg40Tile *tile = &w->tiles[y][x];
    Stg40WallSide *rec;
    u8 *base;
    s32 i;
    Stg40Vtx *a;
    Stg40Vtx *b;
    s32 k;
    u32 *ot;
    s32 ax;
    s32 ay;
    s32 n;
    s32 m;
    Stg40FT4 *src;

    base = &Stg40_WallPrimIdx[(u16)Dung_StatePtr->floorHdr->wallStyle * 5];

    for (i = 0; i < 4; i++) {
        rec = &Stg40_WallSides[i];
        if ((tile->flags & rec->wallMask) == 0) {
            continue;
        }
        a = &w->verts[y + rec->ay][x + rec->ax];
        b = &w->verts[y + rec->by][x + rec->bx];
        if (a->s[0].flag + b->s[0].flag + a->s[1].flag + b->s[1].flag == 0) {
            continue;
        }
        ax = a->s[0].x;
        ay = a->s[0].y;
        n = (b->s[0].x - ax) * (b->s[1].y - ay);
        m = b->s[0].y - ay;
        if (n - (b->s[1].x - ax) * m > 0) {
            continue;
        }
        k = (tile->wallBits >> rec->wallBitShift) & 3;
        if (k == 0 && (tile->primIdx & 0x80)) {
            k = 4;
        }
        ot = &Sys_State.otLayers.u[3][w->verts[y + rec->otY][x + rec->otX].otzDown];
        src = &w->prims[base[k]];
        *(Stg40FT4 *)pkt = *src;
        ((Stg40FT4 *)pkt)->x0 = a->s[1].x;
        ((Stg40FT4 *)pkt)->y0 = a->s[1].y;
        ((Stg40FT4 *)pkt)->x1 = b->s[1].x;
        ((Stg40FT4 *)pkt)->y1 = b->s[1].y;
        ((Stg40FT4 *)pkt)->x2 = a->s[0].x;
        ((Stg40FT4 *)pkt)->y2 = a->s[0].y;
        ((Stg40FT4 *)pkt)->x3 = b->s[0].x;
        ((Stg40FT4 *)pkt)->y3 = b->s[0].y;
        ((Stg40FT4 *)pkt)->r0 = rec->shade;
        ((Stg40FT4 *)pkt)->g0 = rec->shade;
        ((Stg40FT4 *)pkt)->b0 = rec->shade;
        ((Stg40OTag *)pkt)->addr = ((Stg40OTag *)ot)->addr;
        ((Stg40OTag *)ot)->addr = pkt;
        pkt += sizeof(Stg40FT4);
    }
    return pkt;
}

s32 Stg40_DrawTileTop(Stg40FloorWork *w, s32 pkt, s32 x, s32 y) {
    Stg40Vtx *a = &w->verts[y][x];
    Stg40Vtx *b = &w->verts[y + 1][x];
    Stg40Tile *t = &w->tiles[y][x];
    s32 k = t->flags == 0;
    u32 *ot;

    if (a[0].s[k].flag + a[1].s[k].flag + b[0].s[k].flag + b[1].s[k].flag == 0) {
        return pkt;
    }
    if (t->flags != 0) {
        ot = Sys_State.otLayers.u[6];
        *(Stg40FT4 *)pkt = w->prims[Stg40_FloorPrimIdx[t->primIdx & 0x7F]];
        ((Stg40FT4 *)pkt)->x0 = a[0].s[0].x;
        ((Stg40FT4 *)pkt)->y0 = a[0].s[0].y;
        ((Stg40FT4 *)pkt)->x1 = a[1].s[0].x;
        ((Stg40FT4 *)pkt)->y1 = a[1].s[0].y;
        ((Stg40FT4 *)pkt)->x2 = b[0].s[0].x;
        ((Stg40FT4 *)pkt)->y2 = b[0].s[0].y;
        ((Stg40FT4 *)pkt)->x3 = b[1].s[0].x;
        ((Stg40FT4 *)pkt)->y3 = b[1].s[0].y;
        ((Stg40FT4 *)pkt)->tag.word = (((Stg40FT4 *)pkt)->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
        pkt += sizeof(Stg40FT4);
    } else {
        ot = &Sys_State.otLayers.u[3][w->tiles[y][x].otz];
        ((Stg40F4 *)pkt)->tag.b.len = 5;
        ((Stg40F4 *)pkt)->code = 0x28;
        ((Stg40F4 *)pkt)->r0 = 0;
        ((Stg40F4 *)pkt)->g0 = 0;
        ((Stg40F4 *)pkt)->b0 = 0;
        ((Stg40F4 *)pkt)->x0 = a[0].s[1].x;
        ((Stg40F4 *)pkt)->y0 = a[0].s[1].y;
        ((Stg40F4 *)pkt)->x1 = a[1].s[1].x;
        ((Stg40F4 *)pkt)->y1 = a[1].s[1].y;
        ((Stg40F4 *)pkt)->x2 = b[0].s[1].x;
        ((Stg40F4 *)pkt)->y2 = b[0].s[1].y;
        ((Stg40F4 *)pkt)->x3 = b[1].s[1].x;
        ((Stg40F4 *)pkt)->y3 = b[1].s[1].y;
        ((Stg40F4 *)pkt)->tag.word = (((Stg40F4 *)pkt)->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
        pkt += sizeof(Stg40F4);
    }
    return pkt;
}

void Stg40_DrawFloorTiles(Stg40FloorWork *w) {
    s32 rows;
    s32 cols;
    s32 y;
    s32 x;
    s32 pkt;

    rows = (Stg40_RootState->viewY & 0x3F) ? 10 : 9;
    cols = (Stg40_RootState->viewX & 0x3F) ? 10 : 9;
    pkt = Sys_State.packet.addr;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            pkt = Stg40_DrawTileTop(w, pkt, x, y);
            if (w->tiles[y][x].flags & 0xF00) {
                pkt = Stg40_DrawTileWalls(w, pkt, x, y);
            }
        }
    }
    Sys_State.packet.addr = pkt;
}

void Stg40_FloorInit(Actor *a0, s32 *ids) {
    Stg40FloorWork *w = (Stg40FloorWork *)a0->work;
    GfxTexSlot *slot;
    Stg40TexRec *e;
    Stg40FT4 *p;
    Stg40FT4 *q;
    s32 i;

    Stg40_FloorTask = a0;
    Stg40_FloorWork = w;
    w->texCount = 0;
    w->primCount = 0;
    for (i = 0; i < 2; i++) {
        slot = Gfx_FindOrLoadTexSlot(*ids);
        e = (Stg40TexRec *)Cd_GetFileEntry(*ids + 1);
        w->texSlots[w->texCount] = slot;
        w->texRecs[w->texCount] = e;
        w->texIds[w->texCount] = *ids;
        for (; e->u != 0xFF; e++) {
            p = &w->prims[w->primCount];
            p->tag.b.len = 9;
            p->code = 0x2C;
            p->r0 = 0x7F;
            p->g0 = 0x7F;
            p->b0 = 0x7F;
            if (w->primCount != 26) {
                p->code &= ~2;
                p->tpage = ((slot->vramY & 0x100) >> 4) | ((slot->vramX & 0x3FF) >> 6) | ((slot->vramY & 0x200) << 2);
            } else {
                p->code |= 2;
                p->tpage = 0x40 | ((slot->vramY & 0x100) >> 4) | ((slot->vramX & 0x3FF) >> 6) | ((slot->vramY & 0x200) << 2);
            }
            p->clut = ((slot->vramY + e->cy) << 6) | (((slot->vramX + (e->cx >> 2)) >> 4) & 0x3F);
            p->u0 = slot->uOffset + e->u;
            p->v0 = e->v;
            p->u1 = slot->uOffset + e->u + (e->w * 4 - 1);
            p->v1 = e->v;
            p->u2 = slot->uOffset + e->u;
            p->v2 = e->v + (e->h - 1);
            p->u3 = slot->uOffset + e->u + (e->w * 4 - 1);
            p->v3 = e->v + (e->h - 1);
            w->primCount++;
        }
        ids++;
        w->texCount++;
    }
    w->texIds[w->texCount] = -1;
    q = &w->prims[26];
    q->code |= 2;
}

void Stg40_FloorUpdate(Actor *a0) {
    ActorWork *w = a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Stg40_RootState->viewX = Dung_StatePtr->scrollTarget->posX;
        Stg40_RootState->viewY = Dung_StatePtr->scrollTarget->posY;
        Task_NextState0(a0);
        break;
    case 1:
        Stg40_ScrollUpdate(a0);
        Stg40_ProjectGrid((Stg40FloorWork *)w);
        Stg40_FillTileCache(w);
        break;
    case 2:
        break;
    }
}

void Stg40_FloorDraw(Actor *a0) {
    Stg40FloorWork *w = (Stg40FloorWork *)a0->work;
    s32 f = 1;
    s32 n = Beetle_GetPart(0x11);
    s32 *p;

    if (n <= 0 || (Dung_StatePtr->dungeonIdx == 0x10 && n == 0x75)) {
        f = 0;
    }
    if (f) {
        Stg40_DrawFloorTiles(w);
    }
    for (p = w->texIds; *p != -1; p++) {
        Gfx_FindOrLoadTexSlot(*p);
    }
}
