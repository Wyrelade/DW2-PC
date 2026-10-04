#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"

void Stg40_ScrollFollow(Stg40Loc *loc) {
    D_8005071C->scrollTarget = loc;
    Task_SetState1(Stg40_FloorTask, 0);
}

void Stg40_ScrollTo(s32 a0, s32 a1, s32 a2) {
    Actor *t = Stg40_FloorTask;
    Stg40B60 *b = D_80072B60;
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
    b = D_80072B60;
    w->scrollStartX = b->viewX;
    w->scrollStartY = b->viewY;
    w->scrollFrames = a1;
    D_8005071C->scrollTarget = loc;
    Task_SetState1(t, 2);
}

s32 Stg40_IsScrollDone(void) {
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)Stg40_FloorTask->work;
    s32 r = 0;

    if (D_80072B60->viewX == w->scrollGoalX && D_80072B60->viewY == w->scrollGoalY) {
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
    Stg40B60 *b = D_80072B60;

    b->viewX = x0 - dx;
    b->viewY = y0 - dy;
    a0->stateLevel2++;
}

void Stg40_ScrollUpdate(Actor *a0) {
    Stg40FloorScrollView *w = (Stg40FloorScrollView *)a0->work;

    switch (a0->stateLevel1) {
    case 0:
    default:
        D_80072B60->viewX = D_8005071C->scrollTarget->posX;
        D_80072B60->viewY = D_8005071C->scrollTarget->posY;
        break;
    case 1:
        if (a0->stateLevel2 < w->scrollFrames) {
            Stg40_ScrollStep(a0);
        } else {
            D_80072B60->viewX = w->scrollGoalX;
            D_80072B60->viewY = w->scrollGoalY;
        }
        break;
    case 2:
        if (a0->stateLevel2 < w->scrollFrames) {
            Stg40_ScrollStep(a0);
        } else {
            D_80072B60->viewX = w->scrollGoalX;
            D_80072B60->viewY = w->scrollGoalY;
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
    if (D_80072B60->viewY & 0x3F) {
        rows = 0xB;
    }
    cols = 0xA;
    if (D_80072B60->viewX & 0x3F) {
        cols = 0xB;
    }
    n.lo = rows;
    w->gridCols = cols;
    w->gridRows = n.lo;
    vec.vy = 0;
    t = (D_80072B60->viewY & 0x3F) << 11;
    if (t < 0) {
        t += 0x3F;
    }
    vec.vz = ((u32)t >> 6) + 0x2400;
    step = 0x500;
    if (D_8005071C->floorHdr->field_4 != 0) {
        step = -0x500;
    }
    for (row = 0; row < rows; row++) {
        t = (D_80072B60->viewX & 0x3F) * 0xA00;
        if (t < 0) {
            t += 0x3F;
        }
        vec.vx = -(t >> 6) - 0x2D00;
        v = w->verts[row];
        for (col = 0; col < cols; col++) {
            v->s[0].field_4 = RotTransPers(&vec, &v->s[0].x, 0, 0);
            v->s[0].x = v->s[0].x >> shiftX;
            v->s[0].y = v->s[0].y >> shiftY;
            v->s[0].field_4 = v->s[0].field_4 >> shiftZ;
            v->s[0].flag = ((v->s[0].x < 0 ? -v->s[0].x : v->s[0].x) < centerX)
                && ((v->s[0].y < 0 ? -v->s[0].y : v->s[0].y) < centerY);
            vec.vy += step;
            v->s[1].field_4 = RotTransPers(&vec, &v->s[1].x, 0, 0);
            v->s[1].x = v->s[1].x >> shiftX;
            v->s[1].y = v->s[1].y >> shiftY;
            v->s[1].field_4 = v->s[1].field_4 >> shiftZ;
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
                p->field_18 = Stg40_Max4(p->s[0].field_4, p->s[1].field_4, p[1].s[0].field_4, p[1].s[1].field_4);
            }
            if (row != rows - 1) {
                p->field_1C = Stg40_Max4(p->s[0].field_4, p->s[1].field_4, below->s[0].field_4, below->s[1].field_4);
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

    e54 = D_8005071C->floorHdr;
    grid = (Stg40Cell *)D_8005071C->cells;
    rowCount = 9;
    gridCols = e54->cols;
    gridRows = e54->rows;
    if (D_80072B60->viewY & 0x3F) {
        rowCount = 0xA;
    }
    colCount = 9;
    if (D_80072B60->viewX & 0x3F) {
        colCount = 0xA;
    }
    mapRow = D_80072B60->viewY / 64 - 4;
    for (row = 0; row < rowCount; row++) {
        tp = ((Stg40FloorWork *)arg0)->tiles[row];
        v0p = ((Stg40FloorWork *)arg0)->verts[row];
        v1p = ((Stg40FloorWork *)arg0)->verts[row + 1];
        mapCol = D_80072B60->viewX / 64 - 4;
        for (col = 0; col < colCount; col++) {
            tp->field_4 = Stg40_Max4(v0p[0].s[0].field_4, v0p[1].s[0].field_4, v1p[0].s[0].field_4, v1p[1].s[0].field_4);
            tp->otz = Stg40_Min4(v0p[0].s[1].field_4, v0p[1].s[1].field_4, v1p[0].s[1].field_4, v1p[1].s[1].field_4);
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
    Stg40B60 *b = D_80072B60;
    s32 t;

    out->vz = -(((z - b->viewY) << 11) / 64);
    t = x - b->viewX;
    out->vy = -y;
    out->vx = t * 40;
}

s32 Stg40_DrawTileWalls(Stg40FloorWork *w, s32 pkt, s32 x, s32 y)
{
    Stg40Tile *tile = &w->tiles[y][x];
    Stg40Rec10 *rec;
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

    base = &Stg40_WallPrimIdx[(u16)D_8005071C->floorHdr->wallStyle * 5];

    for (i = 0; i < 4; i++) {
        rec = &Stg40_WallSides[i];
        if ((tile->flags & rec->field_0) == 0) {
            continue;
        }
        a = &w->verts[y + rec->field_4][x + rec->field_3];
        b = &w->verts[y + rec->field_6][x + rec->field_5];
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
        k = (tile->wallBits >> rec->field_2) & 3;
        if (k == 0 && (tile->primIdx & 0x80)) {
            k = 4;
        }
        ot = &Sys_State.otLayers.u[3][w->verts[y + rec->field_8][x + rec->field_7].field_1C];
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
        ((Stg40FT4 *)pkt)->r0 = rec->field_9;
        ((Stg40FT4 *)pkt)->g0 = rec->field_9;
        ((Stg40FT4 *)pkt)->b0 = rec->field_9;
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
        ot = D_8005F8C0;
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
        ot = &D_8005F8B4[w->tiles[y][x].otz];
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

    rows = (D_80072B60->viewY & 0x3F) ? 10 : 9;
    cols = (D_80072B60->viewX & 0x3F) ? 10 : 9;
    pkt = Sys_PacketCursor;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            pkt = Stg40_DrawTileTop(w, pkt, x, y);
            if (w->tiles[y][x].flags & 0xF00) {
                pkt = Stg40_DrawTileWalls(w, pkt, x, y);
            }
        }
    }
    Sys_PacketCursor = pkt;
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
        D_80072B60->viewX = D_8005071C->scrollTarget->posX;
        D_80072B60->viewY = D_8005071C->scrollTarget->posY;
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

    if (n <= 0 || (D_8005071C->dungeonIdx == 0x10 && n == 0x75)) {
        f = 0;
    }
    if (f) {
        Stg40_DrawFloorTiles(w);
    }
    for (p = w->texIds; *p != -1; p++) {
        Gfx_FindOrLoadTexSlot(*p);
    }
}

void Stg40_HudUpdate(Actor *a0) {
    Stg40HudWork *w = (Stg40HudWork *)a0->work;
    Stg40Slot34 *s3 = (Stg40Slot34 *)a0->u34.children;
    TextOpenArgs args;
    Stg40FloorHeader *fe;
    s32 n;
    s32 x = 0x12;
    s32 sh;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->labelText0, 3);
        w->scale = 0;
        s3->field_0 = 0;
        n = D_8005071C->floorHdr->nameLen - 6;
        sh = n;
        do {
            if (n >= 7) {
                sh = 6;
            }
        } while (0);
        w->partMask = ~(1 << sh);
        w->shownHp = Save_GameStatePtr->hp;
        w->shownMp = Save_GameStatePtr->mp;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->scale) == 0) {
                fe = D_8005071C->floorHdr;
                args.x = x;
                args.y = 0x16;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                args.text = (s32)fe->name;
                Text_Open(&w->nameText, &args);
                Text_SetOtLayer(w->nameText, 2);
                Text_OpenById(&w->labelText0, Stg40_HudLabels[0].id, 0, Stg40_HudLabels[0].pos);
                Text_OpenById(&w->labelText1, Stg40_HudLabels[1].id, 0, Stg40_HudLabels[1].pos);
                Text_SetOtLayer(w->labelText0, 2);
                Text_SetOtLayer(w->labelText1, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->shownHp > Save_GameStatePtr->hp) {
                w->shownHp = (w->shownHp - 0x21 < Save_GameStatePtr->hp) ? Save_GameStatePtr->hp : (u16)w->shownHp - 0x21;
            }
            if (w->shownHp < Save_GameStatePtr->hp) {
                w->shownHp = (Save_GameStatePtr->hp < w->shownHp + 0x21) ? Save_GameStatePtr->hp : (u16)w->shownHp + 0x21;
            }
            if (Save_GameStatePtr->hp == 0) {
                w->shownHp = 0;
            }
            if (w->shownMp > Save_GameStatePtr->mp) {
                w->shownMp = (w->shownMp - 1 < Save_GameStatePtr->mp) ? Save_GameStatePtr->mp : (u16)w->shownMp - 1;
            }
            if (w->shownMp < Save_GameStatePtr->mp) {
                w->shownMp = (Save_GameStatePtr->mp < w->shownMp + 1) ? Save_GameStatePtr->mp : (u16)w->shownMp + 1;
            }
            if (Save_GameStatePtr->mp == 0) {
                w->shownMp = 0;
            }
            break;
        }
        if (s3->field_0 != 0) {
            if (D_8005071C->bitBugLevel == 0 && s3->field_0->stateLevel0 != 2) {
                Task_SetState0(s3->field_0, 2);
            }
        } else {
            if (D_8005071C->bitBugLevel != 0) {
                Task_Create(0x20A, (s32 *)s3, 0);
            }
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            n = 3;
            Text_CloseArray(&w->labelText0, n);
            if (s3->field_0 != 0) {
                Task_SetState0(s3->field_0, 2);
            }
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Stg40_HudDraw(Actor *a0) {
    Stg40W6AD0 *w = (Stg40W6AD0 *)a0->work;
    EntA0 *p;
    s32 i;

    if (w->field_C != 0) {
        for (i = 0; i < 2; i++) {
            p = Cd_GetFileEntry(Stg40_HudParts[i]);
            switch (i) {
            case 0:
            default:
                Gfx_SetPartsNumber((GfxPart *)p, 2, 4, Save_GameState.maxHp);
                Gfx_SetPartsNumber((GfxPart *)p, 4, 4, w->field_12);
                Gfx_SetPartsNumber((GfxPart *)p, 8, 4, Save_GameState.maxMp);
                Gfx_SetPartsNumber((GfxPart *)p, 0x10, 4, w->field_14);
                break;
            case 1:
                Gfx_HidePartsByMask((GfxPartMaskView *)p, w->field_10);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_C);
            Gfx_DrawParts((s32)p);
        }
    }
}

void Stg40_BitsWinUpdate(Actor *a0) {
    Stg40W6BE4 *w = (Stg40W6BE4 *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->field_0, 1);
        w->field_4 = 0;
        w->field_8 = Save_GameStatePtr->bits;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_4) == 0) {
                Text_OpenById(w, Stg40_BitsLabelText.id, 0, Stg40_BitsLabelText.pos);
                Text_SetOtLayer(w->field_0, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (Save_GameStatePtr->bits < w->field_8) {
                w->field_8 = (w->field_8 - 10 < Save_GameStatePtr->bits) ? Save_GameStatePtr->bits : w->field_8 - 10;
            }
            if (w->field_8 < Save_GameStatePtr->bits) {
                w->field_8 = (w->field_8 + 10 > Save_GameStatePtr->bits) ? Save_GameStatePtr->bits : w->field_8 + 10;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->field_0, 1);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_4) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Stg40_BitsWinDraw(Actor *a0) {
    ActorWork *w = a0->work;
    EntA0 *p;

    if (w->field_4 != 0) {
        p = Cd_GetFileEntry(0x7D40002);
        Gfx_SetPartsNumber((GfxPart *)p, 2, 8, w->field_8);
        Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_4);
        Gfx_DrawParts((s32)p);
    }
}

void Stg40_ItemMenuSetCursor(a0, a1, a2)
    u8 a0;
    u8 a1;
    u8 a2;
{
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)Stg40_ItemMenuTask->work;

    w->cursorRow = a0;
    w->rowCount = a1;
    w->arrowFlags = a2;
    w->refresh = -1;
}

s32 *Stg40_ItemMenuGetTextIds(void) {
    return ((Stg40ItemMenuWork *)Stg40_ItemMenuTask->work)->rowTextIds;
}

void Stg40_ItemMenuInit(Actor *a0, s32 *a1) {
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)a0->work;

    Stg40_ItemMenuTask = a0;
    w->hasDesc = *a1;
}

void Stg40_ItemMenuUpdate(Actor *a0) {
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)a0->work;
    TextOpenArgs args;
    s32 n;
    s32 i;

    n = 6;
    if (w->hasDesc != 0) {
        n = 7;
    }
    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(w->rowTexts, n);
        w->scale = 0;
        Stg40_ItemMenuTask = a0;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->scale) == 0) {
                args.x = 0x1B;
                args.y = 0x33;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                for (i = 0; i < w->rowCount; i++) {
                    args.text = w->rowTextIds[i];
                    Text_Open(&w->rowTexts[i], &args);
                    Text_SetOtLayer(w->rowTexts[i], 2);
                    args.y += 0xC;
                }
                if (w->hasDesc != 0) {
                    args.bigFont = 1;
                    args.text = w->descTextId;
                    args.x = 0x10;
                    args.y = 0x8A;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(&w->descText, &args);
                    Text_SetOtLayer(w->descText, 2);
                }
                w->refresh = 0;
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->refresh != 0) {
                Task_SetState1(a0, 0);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->rowTexts, n);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Stg40_ItemMenuDraw(Actor *a0) {
    Stg40ItemMenuWork *w = (Stg40ItemMenuWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 n;
    s32 i;
    s32 mask;

    if (w->scale != 0) {
        n = 1;
        if (w->hasDesc != 0) {
            n = 2;
        }
        for (i = 0; i < n; i++) {
            p = (GfxPart *)Cd_GetFileEntry(Stg40_ItemMenuParts[i]);
            switch (i) {
            case 0:
            default:
                mask = ((w->arrowFlags & 1) == 0) << 2;
                if (!(w->arrowFlags & 2)) {
                    mask |= 8;
                }
                for (q = p; q->fileId != 0; q++) {
                    if (q->groupMask & 2) {
                        q->x = -0x90;
                        q->y = w->cursorRow * 12 - 0x46;
                        q->palette = (a0->elapsed >> 2) & 3;
                    }
                    if (q->groupMask & 0xC) {
                        q->palette = (a0->elapsed >> 2) & 3;
                    }
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)p, mask);
                break;
            case 1:
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
            Gfx_DrawParts((s32)p);
        }
    }
}

void Stg40_EnemyInfoInit(void) {
}

void Stg40_EnemyInfoUpdate(Actor *a0) {
    Stg40W71F0 *w = (Stg40W71F0 *)a0->work;
    Stg40EnemyParty *info;
    TextOpenArgs args;
    u16 *pos;
    s32 i;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Stg40_EnemyInfoTask = a0;
        Mem_FillWordsNeg1(w->field_8, 12);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_0) == 0) {
                pos = Stg40_EnemyInfoTextPos;
                info = (Stg40EnemyParty *)D_80072B60->enemyList[D_80072B60->enemyIndex]->params;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 1;
                Text_CloseArray(w->field_8, 12);
                for (i = 0; i < info->digiCount * 4; i++) {
                    args.x = *pos++;
                    args.y = *pos++;
                    k = info->digiIds[i / 4];
                    switch (i % 4) {
                    case 0:
                    default:
                        args.text = (s32)Cd_GetFileEntry(0x1FD0081);
                        break;
                    case 1:
                        args.text = (s32)Digi_GetDefaultName(k);
                        break;
                    case 2:
                        args.text = (s32)Cd_GetFileEntry(Digi_GetType(k) + 0x1FD00C3);
                        break;
                    case 3:
                        args.text = (s32)Cd_GetFileEntry(Digi_GetRank(k) + 0x1FD00C6);
                        break;
                    }
                    Text_Open(&w->field_8[i], &args);
                    Text_SetOtLayer(w->field_8[i], 2);
                }
                Task_NextState1(a0);
            }
            break;
        case 1:
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->field_8, 12);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_0) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        case 100:
            Task_SetState0(a0, 1);
            break;
        }
        break;
    }
}

void Stg40_EnemyInfoDraw(Actor *a0) {
    ActorWork *w = a0->work;
    Stg40EnemyParty *info;
    EntA0 *p;
    s32 i;

    if (w->field_0 != 0) {
        info = (Stg40EnemyParty *)D_80072B60->enemyList[D_80072B60->enemyIndex]->params;
        for (i = 0; i < 3; i++) {
            p = Cd_GetFileEntry(Stg40_EnemyInfoParts[i]);
            if (i >= info->digiCount) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, -1);
            } else {
                Gfx_SetPartsNumber((GfxPart *)p, 2, 2, info->levels[i]);
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_0);
            }
            Gfx_DrawParts((s32)p);
        }
    }
}

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

void Stg40_SetLights(Blk16 *l, s32 r, s32 g, s32 b) {
    s32 i;
    Blk16 *p;

    for (i = 0, p = l; i < 3; i++, p++) {
        GsSetFlatLight(i, p);
    }
    GsSetAmbient(r, g, b);
    GsSetLightMode(0);
}

void Stg40_ObjStartFlash(Actor *a0, u8 a1) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    w->flashKind = a1;
    w->flashFrame = 0;
}

void Stg40_SetModelTint(Actor *a0, u8 on, u8 r, u8 g, u8 b) {
    Stg40ModelView *m = (Stg40ModelView *)a0->model;

    if (on == 0) {
        m->field_34 = 0;
        return;
    }
    m->field_34 = 2;
    m->field_38 = r;
    m->field_39 = g;
    m->field_3A = b;
}

s32 Stg40_ObjAnimDone(Actor *a0) {
    return a0->model->animDone < 0;
}

s32 Stg40_ObjStepMove(Stg40Ent48 *e) {
    s32 d;
    Stg40Loc *loc = &e->loc;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 c;

    if ((s16)e->targetHeading != e->heading) {
        c = e->heading;
        if (((s16)(e->targetHeading - ((u16)e->heading - 0x1000)) / 0x800) & 1) {
            e->heading = c - 0x100;
        } else {
            e->heading = c + 0x100;
        }
        e->heading &= 0xFFF;
        d = (s16)e->targetHeading - e->heading;
        if ((d >= 0) ? (d < 0x100) : ((e->heading - (s16)e->targetHeading) < 0x100)) {
            e->heading = e->targetHeading;
        }
    }
    e->octant = (s16)e->targetHeading / 512;
    if ((s16)e->targetHeading == e->heading && loc->moveFramesLeft != 0 && --loc->moveFramesLeft == 0 && loc->moving == 1) {
        loc->moving = 0;
    }
    x = loc->u0.pair.field_0 << 6;
    dx = ((x - (loc->prevTile.field_0 << 6)) * loc->moveFramesLeft) / loc->moveFrames;
    y = loc->u0.pair.field_2 << 6;
    dy = ((y - (loc->prevTile.field_2 << 6)) * loc->moveFramesLeft) / loc->moveFrames;
    loc->posX = x - dx;
    loc->posY = y - dy;
    e->roomId = Stg40_GetCell(loc->u0.pair.field_0, loc->u0.pair.field_2)->roomId;
    return loc->moveFramesLeft != 0;
}

void Stg40_ObjInit(Actor *a0, Stg40Ent48 *e)
{
  Stg40ActWork *w = (Stg40ActWork *) a0->work;
  Stg40Ent48 *new_var;
  Stg40Loc *loc;
  w->ent = e;
  e->actor = a0;
  if (e->digiId != (-1))
  {
    a0->digiId = e->digiId;
    w->modelFile = Digi_GetModelFile(a0->digiId);
    w->animFile = Anim_GetModelAnimFile(a0->digiId, 4);
    w->posZ = 0;
    w->posY = 0;
    w->posX = 0;
    w->rotY = (s16) e->targetHeading;
    w->field_20 = 0;
    w->field_22 = (w->field_23 = (w->field_24 = 0x80));
    w->flashKind = 0;
    w->flashFrame = 0;
    w->field_28 = 0;
  }
  loc = &e->loc;
  e->loc.u0.pair.field_0 = (loc->prevTile.field_0 = e->loc.u0.pair.field_0);
  loc->u0.pair.field_2 = (loc->prevTile.field_2 = e->loc.u0.pair.field_2);
  loc->moveFramesLeft = 0;
  loc->moveFrames = 1;
  loc->moving = 0;
  loc->posX = loc->u0.pair.field_0 << 6;
  loc->posY = loc->u0.pair.field_2 << 6;
  if (e->flags & 1)
  {
    D_8005071C->scrollTarget = loc;
    D_8005071C->playerLoc = loc;
    new_var = w->ent;
    D_80072B60->playerActor = a0;
    D_80072B60->playerEnt = new_var;
    Stg40_TurnQueueAdd(e->turnId);
  }
  w->drawn = 0;
}

void Stg40_ObjUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Arg207 arg;
    s32 *slot;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Task_NextState0(a0);
        if (w->ent->flags & 0x100) {
            if (w->ent->flags & 1) {
                Task_SetState1(a0, 5);
            }
            if (w->ent->flags & 2) {
                if (w->ent->flags & 0x800) {
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 3);
                }
            }
            if (w->ent->flags & 0x200) {
                Task_SetState1(a0, 0);
                w->ent->flags &= ~0x200;
            }
            w->ent->flags &= ~0x900;
        }
        Actor_InitTransform(a0, &w->posX, w->rotY);
        w->pendingAnim = 0x28;
        w->curAnim = -1;
        w->pendingLinkedModel = -1;
        w->linkedModel = -1;
        break;
    case 1:
        Stg40_ObjStepMove(w->ent);
        if (w->ent->flags & 1) {
            Stg40_PlayerUpdate(a0);
        }
        if (w->ent->flags & 2) {
            Stg40_EnemyUpdate(a0);
        }
        if (w->ent->flags & 4) {
            Stg40_FixtureUpdate(a0);
        }
        if (w->pendingLinkedModel != -1) {
            slot = (s32 *)a0->u34.children;
            if (*slot != 0) {
                Task_SetState0((Actor *)*slot, 3);
            } else {
                arg.field_0 = a0;
                arg.field_4 = w->pendingLinkedModel;
                Task_Create(0x207, slot, (s32)&arg);
                w->linkedModel = w->pendingLinkedModel;
                w->pendingLinkedModel = -1;
            }
        }
        break;
    case 2:
        break;
    }
}

void Stg40_ObjDraw(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    Stg40Xform *x;
    s32 dx;
    s32 dy;
    s32 vis;
    s32 r;
    u8 k;

    w->drawn = 0;
    if (e->digiId == -1) {
        return;
    }
    dx = e->loc.posX - D_80072B60->viewX;
    if (dx < 0) {
        dx = D_80072B60->viewX - e->loc.posX;
    }
    dy = e->loc.posY - D_80072B60->viewY;
    if (dy < 0) {
        dy = D_80072B60->viewY - e->loc.posY;
    }
    if (dx < 0x1C0 && dy < 0x1C0) {
        Cd_QueueFile(w->modelFile);
        Cd_QueueFile(w->animFile);
    }
    if (dx < 0x140 && dy < 0x140) {
        vis = 1;
        r = Beetle_GetPart(0x11);
        if (r <= 0 || (D_8005071C->dungeonIdx == 0x10 && r == 0x75)) {
            vis = 0;
        }
        if (e->flags & 1) {
            vis = 1;
        }
        Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
        if (w->pendingAnim != -1) {
            Anim_SetModelAnim(a0, w->pendingAnim);
            w->curAnim = w->pendingAnim;
            w->pendingAnim = -1;
        }
        x = (Stg40Xform *)a0->u38.ptr38;
        x->posX = (s16)((e->loc.posX - D_80072B60->viewX) * 40);
        x->posZ = (s16)-(((e->loc.posY - D_80072B60->viewY) << 11) / 64);
        x->posY = -(s16)e->loc.height;
        x->rotY = e->heading;
        x->scaleX = e->scaleX;
        x->scaleY = e->scaleY;
        x->scaleZ = e->scaleZ;
        if ((e->flags & 0x4000) && vis) {
            if (!(e->flags & 0x80)) {
                Stg40_DrawEntityShadow(&e->loc);
            }
            if (!(e->flags & 0x400)) {
                Anim_StepModelAnim(a0);
                Actor_UpdateTransform(a0);
                Gfx_CalcModelBoneMatrices(a0);
                Gfx_DrawTexModel(a0, 0);
            }
        }
        w->drawn = 1;
    }
    if (w->flashKind != 0) {
        k = Stg40_FlashPattern[w->flashFrame];
        if (k == 0xFF) {
            w->flashKind = 0;
            Stg40_SetModelTint(a0, 0, 0, 0, 0);
        } else {
            Stg40_SetModelTint(a0, k, Stg40_FlashColors[w->flashKind - 1].r, Stg40_FlashColors[w->flashKind - 1].g,
                          Stg40_FlashColors[w->flashKind - 1].b);
            w->flashFrame++;
        }
    }
}

void Stg40_PlayerAnimThenMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    Stg40_ObjSetAnim(a0, a1);
    Task_SetState1(a0, 9);
    D_80072B60->msgAnim = a2;
    D_80072B60->msgNextState = a3;
    D_80072B60->msgId = a4;
    D_80072B60->msgArg0 = a5;
    D_80072B60->msgArg1 = a6;
}

void Stg40_PlayerShowMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    Stg40_ObjSetAnim(a0, a1);
    Task_SetState1(a0, 0xB);
    D_80072B60->msgNextState = a2;
    Stg40_MsgWinOpen(1, a3, a4, a5);
}

s32 Stg40_PlayerCheckEnemyInfo(Actor *a0) {
    Stg40Ent48 *self = ((Stg40ActWork *)a0->work)->ent;
    Stg40Ent48 *e;
    s32 i;

    if (Pad_Square > 0 && self->roomId != 0xFF) {
        e = D_8005071C->ents;
        D_80072B60->enemyCount = 0;
        D_80072B60->enemyIndex = 0;
        for (i = 0; i < D_8005071C->entCount; e++, i++) {
            if ((e->flags & 0x8000) && e->kind == 1 && e->roomId == self->roomId) {
                D_80072B60->enemyList[D_80072B60->enemyCount++] = e;
            }
        }
        if (D_80072B60->enemyCount != 0) {
            Task_SetState1(a0, 0x1A);
            D_80072B60->automapMode = 0;
            return -1;
        }
    }
    return 0;
}

s32 Stg40_PlayerInteract(Actor *a0)
{
    Stg40Ent48 *e;
    Stg40Ent48 *found;
    s32 snd;
    s32 r;
    s32 idx;
    s32 lim;
    s32 snd2;
    Actor *child;
    s32 r2;
    s32 r3;

    e = ((Stg40ActWork *)a0->work)->ent;
    if (Pad_Cross <= 0) {
        return 0;
    }
    found = Stg40_FindEntAt(e->loc.u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(e->octant + 1) << 1],
                          e->loc.u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((e->octant + 1) << 1) | 1]);
    if (found == 0) {
        snd2 = 0x1FD000F;
        r2 = Stg40_GetCellFlags(e->loc.u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(e->octant + 1) << 1],
                          e->loc.u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((e->octant + 1) << 1) | 1]) & 0xF;
        if (r2 >= 3) {
            snd2 = r2 + 0x1FD0194;
        }
        Snd_PlayById(0x2E, 0);
        Stg40_PlayerAnimThenMsg(a0, 0x2D, 0x28, 6, snd2, 0, 0);
        goto end;
    }
    child = found->actor;
    D_80072B60->targetActor = child;
    D_80072B60->targetEnt = found;
    switch (found->kind) {
    default:
        Snd_PlayById(0x2E, 0);
        Stg40_PlayerAnimThenMsg(a0, 0x2D, 0x28, 6, 0x1FD000F, 0, 0);
        return -1;
    case 2:
    case 3:
        Snd_PlayById(0x2E, 0);
        Stg40_PlayerAnimThenMsg(a0, 0x2D, 0x28, 6, (found->kind == 2) ? 0x1FD0195 : 0x1FD0196, 0, 0);
        return -1;
    case 4:
        Task_SetState1(a0, 0x13);
        return -1;
    case 8:
        snd = -1;
        if (!(found->flags & 0x1000)) {
            break;
        }
        r = Stg40_GetBeetlePart(6);
        if (r == -1) {
            snd = 0x1FD0019;
        } else if (r == 0) {
            snd = 0x1FD001A;
        } else {
            lim = found->params[1];
            if (Stg40_GetPartLevel(6) < lim) {
                snd = 0x1FD0018;
            }
        }
        if (snd != -1) {
            Stg40_PlayerShowMsg(a0, 0x28, 1, snd, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0xE);
        return -1;
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
        idx = found->kind - 6;
        if (!(found->flags & 0x1000)) {
            break;
        }
        Item_CheckId(0);
        r3 = Stg40_ListUsableItems(&D_800727E8[idx]);
        if (r3 != 0) {
            Stg40_PlayerShowMsg(a0, 0x28, 1, r3, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0x11);
        D_80072B60->automapMode = 0;
        D_80072B60->giftMenu = 0;
        D_80072B60->selItem = D_80072B60->itemIds[0];
        goto end;
    }
    Task_SetState1(a0, 0xC);
end:
    return -1;
}

s32 Stg40_PlayerTryMove(Stg40Ent48 *e) {
    Stg40Loc *loc = &e->loc;
    s32 bits;
    s32 idx;
    s32 oct;
    s32 k;
    s32 dir;
    s16 d;
    s32 nx;
    s32 ny;
    u16 f;
    u16 fl;
    u16 fr;
    s16 *pl;
    s16 *tbl;

    if (loc->moving != 0) {
        return 0;
    }
    bits = (Pad_State[0].right != 0) << 2;
    if (Pad_State[0].left != 0) {
        bits |= 8;
    }
    dir = bits;
    if (Pad_State[0].up != 0) {
        dir |= 2;
    }
    idx = dir | (Pad_State[0].down != 0);
    k = Stg40_PadDirTable[idx];
    oct = (s16)k;
    if (k < 0) {
        return 0;
    }
    if (D_8005071C->statusFlags & 2) {
        oct = (oct + D_8005071C->confusionTurn) & 7;
    }
    e->targetHeading = (oct << 16) >> 7;
    e->octant = oct;
    if (Pad_State[0].l1 != 0 && (oct & 1) == 0) {
        return 0;
    }
    if (D_8005F710 != 0) {
        return 0;
    }
    dir = oct + 1;
    oct = dir;
    if ((s16)e->targetHeading != e->heading) {
        return 0;
    }
    nx = ny = -1;
    loc->moveFlags &= 0xFFFE;
    d = dir;
    {
        s16 *p = (s16 *)Stg40_DirOffsets;

        f = Stg40_GetCellFlags(loc->u0.pair.field_0 + p[d << 1], loc->u0.pair.field_2 + p[(d << 1) | 1]);
    }
    if (!(f & 0x8000) || (f & 0x30) == 0x20) {
        return 0;
    }
    if (f & 0x10) {
        loc->moveFlags |= 1;
        dir = loc->u0.pair.field_0;
        nx = dir + ((s16 *)Stg40_DirOffsets)[d << 1];
        ny = loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[(d << 1) | 1];
    }
    if ((oct & 1) == 0) {
        pl = &((s16 *)Stg40_DirOffsets)[(d - 1) << 1];
        fl = Stg40_GetCellFlags(loc->u0.pair.field_0 + pl[0],
                           loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d - 1) << 1) | 1]);
        fr = Stg40_GetCellFlags(loc->u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(d + 1) << 1],
                           loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d + 1) << 1) | 1]);
        if (!(fl & 0x8000) || (fl & 0x30) == 0x20 || !(fr & 0x8000) || (fr & 0x30) == 0x20) {
            return 0;
        }
        if (fl & 0x10) {
            loc->moveFlags |= 1;
            nx = loc->u0.pair.field_0 + pl[0];
            ny = loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d - 1) << 1) | 1];
        } else if (fr & 0x10) {
            loc->moveFlags |= 1;
            nx = loc->u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(d + 1) << 1];
            ny = loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d + 1) << 1) | 1];
        }
    }
    if (D_8005071C->statusFlags & 1) {
        return 1;
    }
    if (nx != -1) {
        Stg40Ent48 *te = Stg40_FindEntAt(nx, ny);
        Stg40B60 *b = D_80072B60;

        b->targetEnt = te;
        b->targetActor = te->actor;
    }
    loc->prevTile.field_0 = loc->u0.pair.field_0;
    loc->prevTile.field_2 = loc->u0.pair.field_2;
    tbl = (s16 *)Stg40_DirOffsets;
    loc->u0.pair.field_0 += tbl[(s16)oct << 1];
    loc->u0.pair.field_2 += tbl[((s16)oct << 1) | 1];
    loc->moveFrames = 0xC;
    loc->moveFramesLeft = 0xC;
    dir = loc->prevTile.field_2;
    Stg40_ClearCellOccupied(loc->prevTile.field_0, dir);
    Stg40_SetCellOccupied(loc->u0.pair.field_0, loc->u0.pair.field_2, 1);
    loc->moving = 1;
    return 1;
}

Stg40Ent48 *Stg40_FindObjAtSameTile(Stg40Ent48 *a0) {
    Stg40DungState *b = D_8005071C;
    Stg40Ent48 *e = b->ents;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < b->entCount; i++, e++) {
        if ((e->flags & 0x8000) && e != a0 && e->loc.u0.tileXY == a0->loc.u0.tileXY) {
            r = e;
            break;
        }
    }
    return r;
}

s32 Stg40_PlayerCheckStepHazard(Actor *task) {
    Stg40ActWork *w = (Stg40ActWork *)task->work;
    Stg40Ent48 *ent = w->ent;
    Stg40Ent48 *other;
    GameStateView *gs;
    u16 dir;
    s32 n;
    s32 hp;
    s32 state;
    s32 ret;
    Actor *child;

    ret = 0;
    if ((u32)((dir = Stg40_GetCellFlags(ent->loc.u0.pair.field_0, ent->loc.u0.pair.field_2) & 0xF) - 8) < 5) {
        n = dir - 7;
        if (Stg40_GetPartLevel(5) < n) {
            n *= 50;
            gs = Save_GameStatePtr;
            hp = gs->hp - n;
            if (hp < 0) {
                hp = ret;
            }
            gs->hp = hp;
            Task_SetState1(task, 0xD);
            return 1;
        }
    }
    other = Stg40_FindObjAtSameTile(ent);
    if (other != NULL) {
        child = other->actor;
        D_80072B60->targetActor = child;
        D_80072B60->targetEnt = other;
        switch (other->kind) {
        default:
            break;
        case 8:
            Task_SetState1(task, 0x16);
            ret = 1;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            Task_SetState1(task, 0x10);
            ret = 1;
            break;
        }
    }
    return ret;
}

s32 Stg40_PlayerCheckTileEvent(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;
    s32 r = 0;
    Stg40Ent48 *f;
    Stg40B60 *b;
    Actor *t;

    if (Stg40_CheckEventTile()) {
        Task_SetState1(a0, 0x1E);
        return 1;
    }
    f = Stg40_FindObjAtSameTile(e);
    if (f == NULL) {
        return 0;
    }
    t = f->actor;
    b = D_80072B60;
    b->targetActor = t;
    b->targetEnt = f;
    switch (f->kind) {
    case 2:
    case 3:
        D_8005071C->transitionReq = (f->kind != 2) ? 3 : 2;
        Task_SetState1(a0, 0x17);
        r = 1;
        break;
    }
    return r;
}

s32 Stg40_PlayerCheckSporeBounce(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;
    Stg40Loc *l = &e->loc;
    s32 r = 0;
    s16 t;

    if (l->moveFramesLeft == l->moveFrames / 2 && (l->moveFlags & 1)) {
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        t = e->loc.u0.pair.field_0;
        e->loc.u0.pair.field_0 = e->loc.prevTile.field_0;
        e->loc.prevTile.field_0 = t;
        t = e->loc.u0.pair.field_2;
        e->loc.u0.pair.field_2 = e->loc.prevTile.field_2;
        e->loc.prevTile.field_2 = t;
        e->loc.moveFramesLeft = 0xC;
        e->loc.moveFrames = 0x18;
        Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 1);
        Task_SetState1(a0, 0xF);
        r = -1;
    }
    return r;
}

void Stg40_PlayerWaitTurn(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;

    Stg40_ObjSetAnimIfNew(a0, 0x28);
    if (Stg40_TurnQueueCurrent() == e->turnId) {
        Stg40_ScrollFollow(&e->loc);
        if (Stg40_CheckEncounter()) {
            Task_SetState1(a0, 4);
        } else {
            Task_SetState1(a0, 1);
        }
    }
}

void Stg40_PlayerMoveStep(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_ObjSetAnimIfNew(a0, 0x29);
    if (e->loc.moveFramesLeft == 0xB) {
        Snd_PlayById(0x2C, 0);
    }
    if (Stg40_PlayerCheckSporeBounce(a0) != 0) {
        return;
    }
    if (w->ent->loc.moveFramesLeft >= 2) {
        return;
    }
    Save_GameStatePtr->mp = (Save_GameStatePtr->mp - 1 < 0) ? 0 : (u16)Save_GameStatePtr->mp - 1;
    if (Stg40_PlayerCheckStepHazard(a0) != 0) {
        return;
    }
    if (Stg40_TickStatusEffects(a0)) {
        Task_SetState1(a0, 8);
        return;
    }
    if (Flag_Test(0x68) && Save_GameStatePtr->mp == 0) {
        Save_GameStatePtr->mp = 1;
    }
    if (Save_GameStatePtr->mp == 0 || Save_GameStatePtr->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (Stg40_PlayerCheckTileEvent(a0) == 0) {
        Task_SetState1(a0, 3);
    }
}

void Stg40_PlayerMoveEnd(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    if (Stg40_TurnQueueNext() == e->turnId) {
        if (Stg40_PlayerTryMove(w->ent) == 1) {
            Task_SetState1(a0, 2);
        } else {
            Task_SetState1(a0, 0);
        }
    } else if (Stg40_CheckEncounter()) {
        Task_SetState1(a0, 4);
    } else {
        Task_SetState1(a0, 0);
    }
}

void Stg40_PlayerAfterAction(Actor *a0) {
    if (Stg40_TickStatusEffects(a0)) {
        Task_SetState1(a0, 8);
    } else {
        Task_SetState1(a0, 7);
    }
}

void Stg40_PlayerEndTurn(Actor *a0) {
    if (Flag_Test(0x68) && Save_GameStatePtr->mp == 0) {
        Save_GameStatePtr->mp = 1;
    }
    if (Save_GameStatePtr->mp == 0 || Save_GameStatePtr->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (Stg40_PlayerCheckTileEvent(a0) == 0) {
        Stg40_TurnQueueNext();
        Task_SetState1(a0, 0);
        if (Stg40_CheckEncounter()) {
            Task_SetState1(a0, 4);
        }
    }
}

void Stg40_PlayerShowStatusMsgs(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    s32 arg = 0;
    s32 k;

    if (b->statusCount == 0) {
        Task_SetState1(a0, 7);
        return;
    }
    b->statusCount--;
    k = b->statusCodes[b->statusCount];
    if (k >= 2 && k < 6) {
        arg = (s32)Save_GameStatePtr->field_D1;
    }
    if (k == 6) {
        arg = b->brokenPartText;
    }
    if (k == 7) {
        arg = (s32)b->lostDigiName;
    }
    Stg40_PlayerShowMsg(a0, 0x28, 8, Stg40_StatusMsgIds[k], arg, 0);
}

void Stg40_PlayerInput(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    s32 v;
    s32 n;

    Stg40_ObjSetAnimIfNew(a0, 0x28);
    if (D_8005071C->freeze != 0) {
        return;
    }
    if (Pad_Circle > 0 && Stg40_RootTask->stateLevel0 == 1 && Stg40_RootTask->stateLevel1 == 1 && Stg40_RootTask->stateLevel2 == 1) {
        Task_SetState1(Stg40_RootTask, 4);
        D_8005071C->freeze = 1;
        return;
    }
    if (Stg40_PlayerTryMove(w->ent) == 1) {
        if (D_8005071C->statusFlags & 1) {
            Stg40_PlayerShowMsg(a0, 0x28, 6, 0x1FD001D, 0, 0);
        } else {
            Task_SetState1(a0, 2);
        }
        return;
    }
    if (Stg40_PlayerInteract(a0) == 0 && Stg40_PlayerCheckEnemyInfo(a0) == 0 && Beetle_GetPart(0x12) > 0 && Pad_Select > 0) {
        v = Save_GameStatePtr->field_0 + 1;
        n = (v < 3) ? v : 0;
        Save_GameStatePtr->field_0 = n;
        D_80072B60->automapMode = Save_GameStatePtr->field_0;
    }
}

void Stg40_PlayerResumeAfterBattle(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2D);
        Task_SetState2(a0, 1);
        break;
    case 1:
        if (Stg40_ObjAnimDone(a0) == 1) {
            Task_SetState2(a0, 2);
        }
        break;
    case 2:
        if (D_8005071C->freeze == 0) {
            if (Stg40_TurnQueueCurrent() == e->turnId) {
                Task_SetState1(a0, 1);
            } else {
                Task_SetState1(a0, 0);
            }
        }
        break;
    }
}

void Stg40_PlayerAnimThenMsgUpdate(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            if (D_80072B60->msgAnim != -1) {
                Stg40_ObjSetAnim(a0, D_80072B60->msgAnim);
            }
            Stg40_MsgWinOpen(1, D_80072B60->msgId, D_80072B60->msgArg0, D_80072B60->msgArg1);
            Task_NextState2(a0);
        }
        break;
    case 1:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, (u8)D_80072B60->msgNextState);
        }
        break;
    }
}

void Stg40_PlayerWaitAnim(Actor *a0) {
    if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
        Task_SetState1(a0, (u8)D_80072B60->msgNextState);
    }
}

void Stg40_PlayerWaitMsg(Actor *a0) {
    if (Stg40_MsgWinCloseIfDone(1) == 1) {
        Task_SetState1(a0, (u8)D_80072B60->msgNextState);
    }
}

void Stg40_PlayerFoundObject(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    Stg40Ent48 *e = b->targetEnt;
    Actor *t = b->targetActor;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        Stg40_ObjSetAnim(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Task_SetState1(t, 5);
            Stg40_MsgWinOpen(1, 0x1FD0010, (s32)Cd_GetFileEntry(e->kind + 0x1FD0064), 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerHurtAnim(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2F, 0);
        Stg40_ObjSetAnim(a0, 0x2C);
        Stg40_ObjStartFlash(a0, 1);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjAnimDone(a0) == 1 || a0->stateLevel4++ >= 11) {
            Stg40_ObjSetAnim(a0, 0x28);
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerDestroyMine(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->targetEnt;
    Actor *t = D_80072B60->targetActor;
    s32 msg;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2A);
        Snd_PlayById(0x2E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            r = Beetle_GetPart(6);
            n = e->params[1];
            if (Item_GetLevel(r) >= n) {
                Task_SetState1(t, 6);
                msg = 0x1FD0017;
            } else {
                msg = 0x1FD0018;
            }
            Stg40_MsgWinOpen(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerSporeDamage(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->targetEnt;
    Actor *t = D_80072B60->targetActor;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2C);
        Stg40_ObjStartFlash(a0, 2);
        Task_SetState1(t, 4);
        D_80072B60->damage = e->params[1] * 200;
        Stg40_DamageBeetle(D_80072B60->damage);
        Snd_PlayById(0x33, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Stg40_MsgWinOpen(1, 0x1FD001F, (s32)Save_GameStatePtr->field_D1, (s32)Stg40_NumToDigits(0, D_80072B60->damage));
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerBugInvade(Actor *arg0)
{
    Stg40Ent48 *e;
    Actor *t;
    s32 idx;
    s32 bit;
    s32 r;
    s32 n;

    e = D_80072B60->targetEnt;
    t = D_80072B60->targetActor;
    idx = e->kind - 9;
    bit = 0x100 << idx;
    switch (arg0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(arg0, 0x28);
        Task_SetState1(t, 4);
        Task_NextState2(arg0);
        break;
    case 1:
        if (t->stateLevel1 != 1) {
            return;
        }
        r = 0;
        switch (e->kind) {
        default:
            if (((Stg40BA5View *)D_8005071C)->field_BA5[idx] == 0) {
                ((Stg40BA5View *)D_8005071C)->field_BA5[idx] = e->params[1];
                r = -1;
            }
            break;
        case 9:
            if (D_8005071C->bitBugLevel == 0) {
                if (Save_GameStatePtr->bits != 0 || Stg40_PickRandomPart() != -1) {
                    r = -1;
                    ((Stg40BA5View *)D_8005071C)->field_BA5[e->kind - 9] = e->params[1];
                }
            }
            break;
        case 0xB:
            if (D_8005071C->returnBugLevel != 0 || ((s32 (*)(s32))Stg40_ListPartyDigi)(1) < 2 || Digi_CountByState(1) >= 0x18) {
                r = 0;
            } else {
                r = -1;
                ((Stg40BA5View *)D_8005071C)->field_BA5[e->kind - 9] = e->params[1];
            }
            break;
        case 0xC:
            n = ((s32 (*)(void))Beetle_GetDigiCapacity)();
            n -= ((s32 (*)(s32))Stg40_ListPartyDigi)(0);
            if (n != D_8005071C->memBugCount) {
                D_8005071C->memBugLevels[D_8005071C->memBugCount] = e->params[1];
                r = -1;
                D_8005071C->memBugCount++;
            }
            break;
        }
        if (r == 0) {
            Stg40_MsgWinOpen(1, e->kind + 0x1FD0022, (s32)Save_GameStatePtr + 0xD1, 0);
            Task_SetState2(arg0, 3);
        } else {
            D_8005071C->statusFlags &= ~bit;
            Stg40_ObjSetAnim(arg0, 0x2A);
            Stg40_ObjStartFlash(arg0, 2);
            Task_NextState2(arg0);
            Snd_PlayById(0x2F, 0);
        }
        break;
    case 2:
        if (Stg40_ObjWaitAnimOrSkip(arg0) == 1) {
            Stg40_ObjSetAnim(arg0, 0x28);
            Stg40_MsgWinOpen(1, e->kind + 0x1FD001E, 0, 0);
            Task_NextState2(arg0);
        }
        break;
    case 3:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(arg0, 6);
        }
        break;
    }
}

void Stg40_PlayerEnemyInfo(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;
    Stg40B60 *g = D_80072B60;
    Stg40Ent48 *t;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_Create(0x20C, &Stg40_RootChildren->enemyInfoTask, 0);
        Stg40_ObjSetAnim(a0, 0x28);
        Task_NextState2(a0);
        break;
    case 1:
        t = g->enemyList[g->enemyIndex];
        g->targetActor = t->actor;
        g->targetEnt = t;
        Stg40_ScrollToFollow(&t->loc, 0x10);
        Task_SetState0((Actor *)Stg40_RootChildren->enemyInfoTask, 2);
        Task_SetState1((Actor *)Stg40_RootChildren->enemyInfoTask, 0x64);
        Task_NextState2(a0);
        break;
    case 2:
        if (a0->stateLevel3 == 0) {
            if (Stg40_IsScrollDone() != 0) {
                Snd_PlayById(0x12, 0);
                Task_SetState3(a0, 1);
            }
        }
        if (Pad_State[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 0x64);
        } else if (Pad_State[0].square > 0 && D_80072B60->enemyCount >= 2) {
            n = D_80072B60->enemyIndex + 1;
            D_80072B60->enemyIndex = (n < D_80072B60->enemyCount) ? n : 0;
            Task_SetState2(a0, 1);
        } else if (Pad_Cross > 0) {
            r = Stg40_ListUsableItems(&Stg40_GiftGunReq);
            if (r != 0) {
                Stg40_MsgWinOpen(1, r, 0, 0);
                Task_SetState2(a0, 0x3C);
            } else {
                Task_SetState1(a0, 0x11);
                D_80072B60->giftMenu = 1;
                D_80072B60->selItem = D_80072B60->itemIds[0];
            }
        }
        break;
    case 0x3C:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState2(a0, 2);
            Task_SetState3(a0, 1);
        }
        break;
    case 0x64:
        Stg40_ScrollFollow(&e->loc);
        Task_SetState0((Actor *)Stg40_RootChildren->enemyInfoTask, 2);
        Task_NextState2(a0);
        break;
    case 0x65:
        if (Stg40_RootChildren->enemyInfoTask == 0) {
            g->automapMode = Save_GameStatePtr->field_0;
            Task_SetState1(a0, 1);
        }
        break;
    }
}

void Stg40_PlayerShootGift(Actor *actor) {
    s32 state = actor->stateLevel2;
    Stg40Ent48 *self = ((Stg40ActWork *)actor->work)->ent;
    Stg40Ent48 *target = D_80072B60->targetEnt;
    Stg40Loc *loc = &D_80072B60->shotLoc;

    switch (state) {
    case 0:
    default: {
        s32 angle;

        Stg40_ObjSetAnim(actor, 0x29);
        angle = ratan2(self->loc.posX - target->loc.posX,
                       target->loc.posY - self->loc.posY);
        D_80072B60->shotAngle = angle & 0xFFF;
        D_80072B60->shotStepX = -rsin(D_80072B60->shotAngle);
        D_80072B60->shotStepY = rcos(D_80072B60->shotAngle);
        D_80072B60->shotX = self->loc.u0.pair.field_0 << 14;
        D_80072B60->shotY = self->loc.u0.pair.field_2 << 14;
        D_80072B60->shotTargetX = target->loc.u0.pair.field_0 << 14;
        D_80072B60->shotTargetY = target->loc.u0.pair.field_2 << 14;
        Task_NextState2(actor);
        break;
    }
    case 1:
        if ((s16)self->targetHeading != D_80072B60->shotAngle) {
            s32 h = (s16)self->targetHeading;
            s32 diff = (s16)((u16)D_80072B60->shotAngle - ((u16)self->targetHeading - 0x1000));
            s32 d;
            s32 t;

            if (diff < 0) {
                diff += 0x7FF;
            }
            if ((diff >> 11) & 1) {
                self->targetHeading = h - 0x40;
            } else {
                self->targetHeading = h + 0x40;
            }
            t = self->targetHeading & 0xFFF;
            self->targetHeading = t;
            d = D_80072B60->shotAngle - t;
            if ((d >= 0) ? (d < 0x40) : (t - D_80072B60->shotAngle < 0x40)) {
                self->targetHeading = D_80072B60->shotAngle;
            }
            self->heading = self->targetHeading;
        } else {
            Stg40_ObjSetAnim(actor, 0x28);
            goto next;
        }
        break;
    case 2:
        if (actor->stateLevel4++ < 0x10) {
            break;
        }
        Snd_PlayById(0x2D, 0);
        Stg40_ObjSetAnim(actor, 0x2A);
        goto next;
    case 3:
        if (actor->stateLevel4++ < 6) {
            break;
        }
        goto next;
    case 4: {
        s32 ax;
        s32 ay;

        D_80072B60->shotX += D_80072B60->shotStepX;
        D_80072B60->shotY += D_80072B60->shotStepY;
        loc->posX = D_80072B60->shotX >> 8;
        loc->posY = D_80072B60->shotY >> 8;
        Stg40_ScrollFollow(loc);
        ax = D_80072B60->shotStepX;
        ax = (ax >= 0) ? ax : -ax;
        if ((D_80072B60->shotTargetX - D_80072B60->shotX >= 0)
                ? (ax >= D_80072B60->shotTargetX - D_80072B60->shotX)
                : (ax >= D_80072B60->shotX - D_80072B60->shotTargetX)) {
            ay = D_80072B60->shotStepY;
            ay = (ay >= 0) ? ay : -ay;
            if ((D_80072B60->shotTargetY - D_80072B60->shotY >= 0)
                    ? (ay >= D_80072B60->shotTargetY - D_80072B60->shotY)
                    : (ay >= D_80072B60->shotY - D_80072B60->shotTargetY)) {
                Stg40_ScrollFollow(&target->loc);
                Task_NextState2(actor);
                Snd_PlayById(0x1B, 0);
            }
        }
        break;
    }
    case 5: {
        Stg40EnemyParty *info;
        s32 msg;

        if (actor->stateLevel4++ < 0x1F) {
            break;
        }
        info = (Stg40EnemyParty *)target->params;
        msg = 0x1FD0050;
        if (info->giftsTaken < 9) {
            s32 r = Item_GetCategory(D_80072B60->selItem);
            s32 kind;

            if (r >= 0x25) {
                kind = 3;
            } else if (r >= 0x22) {
                kind = 0x22;
                kind = r - kind;
            } else {
                kind = 3;
            }
            if (kind == 3 || kind == info->likedGift) {
                if (Stg40_RandPercent() < Stg40_GiftTakeChance[info->giftsTaken]) {
                    s32 idx;

                    info->giftsTaken++;
                    idx = Item_GetLevel(D_80072B60->selItem);
                    msg = 0x1FD004F;
                    info->giftPoints += Stg40_GiftPointsByLevel[idx - 1];
                }
            }
        }
        Stg40_MsgWinOpen(1, msg, Digi_GetDefaultName(info->digiIds[0]),
                      Item_GetNameText(D_80072B60->selItem));
        goto next;
    }
    case 6:
        if (Stg40_MsgWinCloseIfDone(1) != 1) {
            break;
        }
        Stg40_ScrollToFollow(&self->loc, 8);
        Task_SetState0((Actor *)Stg40_RootChildren->enemyInfoTask, 2);
    next:
        Task_NextState2(actor);
        break;
    case 7:
        if (Stg40_RootChildren->enemyInfoTask == 0) {
            break;
        }
        Task_SetState1(actor, 6);
        D_80072B60->automapMode = Save_GameStatePtr->field_0;
        break;
    }
}

void Stg40_PlayerChestTrapPrompt(Actor *a0) {
    u8 *d = D_80072B60->targetEnt->params;
    s32 r;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        Stg40_ObjSetAnim(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (d[1] == 0) {
            Task_SetState1(a0, 0x14);
        } else {
            D_80072B60->trapDisarmRank = Stg40_GetTrapDisarmRank(d[1]);
            r = Stg40_GetPartState(7);
            msg = D_80072B60->trapDisarmRank + 0x1FD0040;
            if (r == -1) {
                msg = 0x1FD0045;
            }
            if (r == 0) {
                msg = 0x1FD0046;
            }
            Stg40_MsgWinOpen(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 3:
        switch (Stg40_MsgWinGetChoice(1)) {
        case -1:
            Task_SetState1(a0, 6);
            break;
        case 1:
            Task_SetState1(a0, 0x14);
            break;
        }
        break;
    }
}

void Stg40_PlayerOpenChest(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    Actor *t = b->targetActor;
    u8 *d = b->targetEnt->params;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_SetState1(t, 4);
        Task_NextState2(a0);
        break;
    case 1:
        if (t->stateLevel1 == 3) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0 || d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (Stg40_RollTrapDisarm(b->trapDisarmRank) == 1) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 0x16);
        }
        break;
    }
}

void Stg40_PlayerTakeChestItem(Actor *a0) {
    Actor *t = D_80072B60->targetActor;
    u8 *d = D_80072B60->targetEnt->params;

    switch (a0->stateLevel2) {
    case 0:
    default:
        if (d[0] == 0) {
            Stg40_MsgWinOpen(1, 0x1FD004E, 0, 0);
            Task_SetState1(t, 5);
        } else if (Item_AddToBag(d[0]) == -1) {
            Stg40_MsgWinOpen(1, 0x1FD0055, Item_GetNameText(d[0]), 0);
            d[1] = 0xFF;
            Snd_PlayById(0x1C, 0);
        } else {
            Stg40_MsgWinOpen(1, 0x1FD004D, Item_GetNameText(d[0]), 0);
            Task_SetState1(t, 5);
            Snd_PlayById(0x19, 0);
            Item_SortList();
        }
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerTriggerTrap(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->targetEnt;
    Actor *t = D_80072B60->targetActor;
    s32 nc = e->kind != 4;
    u8 *d = e->params;

    switch (a0->stateLevel2) {
    case 0:
    default:
        D_80072B60->trapEffect = Stg40_RollTrapEffect();
        if (D_80072B60->trapEffect != 0x10) {
            Stg40_ObjSetAnim(a0, 0x2C);
            Stg40_ObjStartFlash(a0, 1);
            Stg40_ApplyTrapEffect(D_80072B60->trapEffect, d[1]);
        }
        if (nc) {
            Task_SetState1(t, 4);
        }
        ((Stg40ActWork *)a0->work)->pendingLinkedModel = d[1] + 1;
        Snd_PlayById(0x34, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Stg40_ShowTrapEffectMsg(nc, D_80072B60->trapEffect);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_NextState2(a0);
        }
        break;
    case 3:
        Task_NextState2(a0);
        break;
    case 4:
        if (nc == 0) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063438);
void Stg40_PlayerExitFloor(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    Stg40ModelFade *m = (Stg40ModelFade *)a0->model;
    s32 v;
    switch (a0->stateLevel2) {
        case 0:
        default:
        {
            u8 k = D_8005071C->transitionReq;
            if (k == 2) {
                Snd_PlayById(0x23, 0);
                w->pendingLinkedModel = 0;
            } else {
                if (k == 3)
                    Snd_PlayById(0x18, 0);
                else
                    Snd_PlayById(0x1F, 0);
                w->pendingLinkedModel = 1;
            }
            m->clutRow = 1;
            m->tpageFlags = 0x20;
            m->fadeColor = D_80063438;
            Stg40_ObjSetAnim(a0, 0x28);
            e->flags |= 0x80;
            w->flashKind = 0;
            Task_NextState2(a0);
            break;
        }
        case 1:
            if (a0->stateLevel3++ >= 0x3C) {
                Gfx_FadeOutToBlack(8);
                Task_NextState2(a0);
            }
            break;
        case 2:
            break;
    }

    v = e->scaleX - 0x51;
    if (v < 0) {
        v = 0;
    }
    e->scaleX = v;
    e->scaleZ = v;
    if (m->fadeColor.r != 0xFF) {
        m->fadeColor.r++;
        m->fadeColor.g++;
        m->fadeColor.b++;
    }
}

void Stg40_PlayerShootObstacle(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->targetEnt;
    Actor *t = D_80072B60->targetActor;
    s32 k = e->kind - 6;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2A);
        Snd_PlayById(k < 3 ? 0x2D : 0x1E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            if (Item_GetLevel(D_80072B60->selItem) >= e->params[1]) {
                Task_SetState1(t, 6);
                msg = Stg40_ShootMsgIds[k * 2];
                Task_SetState2(a0, 3);
            } else {
                msg = Stg40_ShootMsgIds[k * 2 + 1];
                Task_NextState2(a0);
            }
            Stg40_MsgWinOpen(1, msg, 0, 0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
            D_80072B60->automapMode = Save_GameStatePtr->field_0;
        }
        break;
    case 3:
        if (Stg40_MsgWinCloseIfDone(1) == 1 && e->flags == 0) {
            Task_SetState1(a0, 6);
            D_80072B60->automapMode = Save_GameStatePtr->field_0;
        }
        break;
    }
}

void Stg40_ItemMenuRefresh(void) {
    s32 s3;
    s32 s0;
    s32 s1;
    s32 e1;
    s32 e3;
    s32 v1;
    s32 *dst;
    s32 *p;

    s3 = 0;
    s0 = D_80072B60->cursor - D_80072B60->scrollTop;
    dst = Stg40_ItemMenuGetTextIds();
    p = dst;
    if (s0 >= 6) {
        D_80072B60->scrollTop = D_80072B60->cursor - 5;
    }
    if (s0 < 0) {
        D_80072B60->scrollTop = D_80072B60->cursor;
    }
    e1 = D_80072B60->itemCount;
    e3 = D_80072B60->scrollTop;
    s1 = e1;
    v1 = e3 + 6;
    if (s1 >= v1) {
        s1 = v1;
    }
    s0 = e3;
    while (s0 < s1) {
        *p = Item_GetNameText(D_80072B60->itemIds[s0]);
        s0++;
        p++;
    }
    s3 |= D_80072B60->scrollTop != 0;
    if (s1 < D_80072B60->itemCount) {
        s3 |= 2;
    }
    Stg40_ItemMenuSetCursor(D_80072B60->cursor - D_80072B60->scrollTop, s1 - D_80072B60->scrollTop, s3);
    dst[6] = Item_GetDescText(D_80072B60->itemIds[D_80072B60->cursor]);
    s1 = e1;
}

void Stg40_ItemMenuMoveCursor(void) {
    s32 old = D_80072B60->cursor;
    s32 n;

    if (Pad_Repeat & 0x1000) {
        if (old != 0) {
            D_80072B60->cursor = old - 1;
        }
    }
    if (Pad_Repeat & 0x4000) {
        n = D_80072B60->cursor + 1;
        if (n < D_80072B60->itemCount) {
            D_80072B60->cursor = n;
        }
    }
    if (old != D_80072B60->cursor) {
        Snd_PlayById(D_80072B60->giftMenu ? 0xD : 0xC, 0);
        Stg40_ItemMenuRefresh();
    }
}

void Stg40_PlayerItemMenu(Actor *a0) {
    s32 arg;
    s32 i;
    u16 *bag;

    switch (a0->stateLevel2) {
    case 0:
    default:
        D_80072B60->cursor = 0;
        D_80072B60->scrollTop = 0;
        Stg40_ObjSetAnim(a0, 0x28);
        arg = D_80072B60->giftMenu != 0;
        Task_Create(0x20B, &Stg40_RootChildren->itemMenuTask, (s32)&arg);
        Snd_PlayById(0x37, 0);
        Stg40_ItemMenuRefresh();
        Task_NextState2(a0);
        break;
    case 1:
        if (a0->stateLevel3++ >= 9) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        Stg40_ItemMenuMoveCursor();
        if (Pad_State[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 4);
        } else if (Pad_State[0].cross > 0) {
            D_80072B60->selItem = D_80072B60->itemIds[D_80072B60->cursor];
            for (i = 0, bag = Save_GameStatePtr->bagItems; i < 0x30; i++, bag++) {
                if (*bag == D_80072B60->selItem) {
                    *bag = 0;
                    Item_CompactBag();
                    break;
                }
            }
            if (D_80072B60->giftMenu != 0) {
                Stg40_ScrollToFollow(&((Stg40ActWork *)a0->work)->ent->loc, 8);
                Snd_PlayById(0xE, 0);
            } else {
                Snd_PlayById(0xA, 0);
            }
            Task_NextState2(a0);
        }
        if (a0->stateLevel2 != 2) {
            Task_SetState0((Actor *)Stg40_RootChildren->itemMenuTask, 2);
        }
        break;
    case 3:
        if (Stg40_RootChildren->itemMenuTask == 0) {
            if (D_80072B60->giftMenu == 0) {
                Task_SetState1(a0, 0x12);
            } else {
                Task_SetState1(a0, 0x1B);
            }
        }
        break;
    case 4:
        if (Stg40_RootChildren->itemMenuTask == 0) {
            if (D_80072B60->giftMenu == 0) {
                Task_SetState1(a0, 1);
                D_80072B60->automapMode = Save_GameStatePtr->field_0;
            } else {
                Task_SetState1(a0, 0x1A);
                Task_SetState2(a0, 2);
                Task_SetState3(a0, 1);
            }
        }
        break;
    }
}

void Stg40_PlayerBeetleDown(Actor *a0) {
    s32 r;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x30, 1);
        Stg40_ObjSetAnim(a0, 0x2B);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) != 1) {
            return;
        }
        Stg40_MsgWinOpen(1, 0x1FD0054, (s32)Save_GameStatePtr->field_D1, 0);
        break;
    case 2:
        r = Stg40_MsgWinCloseIfDone(1);
        if (r != 1) {
            return;
        }
        D_8005071C->transitionReq = 3;
        D_8005071C->beetleDown = r;
        Snd_PlayById(0x1F, 0);
        break;
    case 3:
        if (a0->stateLevel3++ < 30) {
            return;
        }
        Gfx_FadeOutToBlack(0x10);
        break;
    case 4:
        return;
    }
    Task_NextState2(a0);
}

void Stg40_PlayerRunEvent(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x28);
        D_80072B60->cmdDigiId = 0;
        D_80072B60->eventText = -1;
        Text_OpenMsgClearChoice(&D_80072B60->eventText, Flag_SelectBranch(D_80072B60->eventEntry));
        Task_NextState2(a0);
        break;
    case 1:
        if (Text_IsFinished(D_80072B60->eventText)) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        Stg40_TurnQueueNext();
        Task_SetState1(a0, 0);
        if (Stg40_CheckEncounter()) {
            Task_SetState1(a0, 4);
        } else {
            D_8005071C->freeze = 0;
        }
        break;
    }
}

void Stg40_PlayerUpdate(Actor *a0) {
    Stg40Ent48 *e;

    Stg40_SetCellOccupied(((Stg40ActWork *)a0->work)->ent->loc.u0.pair.field_0, ((Stg40ActWork *)a0->work)->ent->loc.u0.pair.field_2, 1);
    switch (a0->stateLevel1) {
    case 0:
    case 24:
    case 25:
    default:
        Stg40_PlayerWaitTurn(a0);
        break;
    case 1:
        Stg40_PlayerInput(a0);
        break;
    case 2:
        Stg40_PlayerMoveStep(a0);
        break;
    case 3:
        Stg40_PlayerMoveEnd(a0);
        break;
    case 6:
        Stg40_PlayerAfterAction(a0);
        break;
    case 7:
        Stg40_PlayerEndTurn(a0);
        break;
    case 8:
        Stg40_PlayerShowStatusMsgs(a0);
        break;
    case 4:
        if (a0->stateLevel2 != 1) {
            D_8005071C->transitionReq = 1;
            D_8005071C->freeze = 1;
            Task_NextState2(a0);
        }
        break;
    case 5:
        Stg40_PlayerResumeAfterBattle(a0);
        break;
    case 9:
        Stg40_PlayerAnimThenMsgUpdate(a0);
        break;
    case 10:
        Stg40_PlayerWaitAnim(a0);
        break;
    case 11:
        Stg40_PlayerWaitMsg(a0);
        break;
    case 12:
        Stg40_PlayerFoundObject(a0);
        break;
    case 13:
        Stg40_PlayerHurtAnim(a0);
        break;
    case 14:
        Stg40_PlayerDestroyMine(a0);
        break;
    case 15:
        Stg40_PlayerSporeDamage(a0);
        break;
    case 16:
        Stg40_PlayerBugInvade(a0);
        break;
    case 19:
        Stg40_PlayerChestTrapPrompt(a0);
        break;
    case 20:
        Stg40_PlayerOpenChest(a0);
        break;
    case 21:
        Stg40_PlayerTakeChestItem(a0);
        break;
    case 22:
        Stg40_PlayerTriggerTrap(a0);
        break;
    case 23:
        Stg40_PlayerExitFloor(a0);
        break;
    case 18:
        Stg40_PlayerShootObstacle(a0);
        break;
    case 17:
        Stg40_PlayerItemMenu(a0);
        break;
    case 26:
        Stg40_PlayerEnemyInfo(a0);
        break;
    case 27:
        Stg40_PlayerShootGift(a0);
        break;
    case 28:
        Stg40_PlayerBeetleDown(a0);
        break;
    case 30:
        Stg40_PlayerRunEvent(a0);
        break;
    case 29:
        break;
    }
    e = ((Stg40ActWork *)a0->work)->ent;
    Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->loc.prevTile.field_0, e->loc.prevTile.field_2, e->kind);
}
