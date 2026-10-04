#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"

void func_80065134(Stg40Loc *loc) {
    D_8005071C->field_1064 = loc;
    Task_SetState1(D_80072B68, 0);
}

void func_80065168(s32 a0, s32 a1, s32 a2) {
    Actor *t = D_80072B68;
    Stg40B60 *b = D_80072B60;
    Stg40B68Work *w = (Stg40B68Work *)t->work;

    w->field_1E90 = a0;
    w->field_1E94 = a1;
    w->field_1E98 = b->field_2C;
    w->field_1E9C = b->field_30;
    w->field_1EA0 = a2;
    Task_SetState1(t, 1);
}

void func_800651C0(Stg40Loc *loc, s32 a1) {
    Actor *t = D_80072B68;
    Stg40B68Work *w = (Stg40B68Work *)t->work;
    Stg40B60 *b;

    w->field_1E90 = loc->field_C;
    w->field_1E94 = loc->field_10;
    b = D_80072B60;
    w->field_1E98 = b->field_2C;
    w->field_1E9C = b->field_30;
    w->field_1EA0 = a1;
    D_8005071C->field_1064 = loc;
    Task_SetState1(t, 2);
}

s32 func_80065230(void) {
    Stg40B68Work *w = (Stg40B68Work *)D_80072B68->work;
    s32 r = 0;

    if (D_80072B60->field_2C == w->field_1E90 && D_80072B60->field_30 == w->field_1E94) {
        r = -1;
    }
    return r;
}

void func_80065278(Actor *a0) {
    Stg40B68Work *w = (Stg40B68Work *)a0->work;
    s32 x0 = w->field_1E90;
    s32 y0 = w->field_1E94;
    s32 n = w->field_1EA0;
    s32 k = n - a0->stateLevel2;
    s32 dx = (x0 - w->field_1E98) * k / n;
    s32 dy = (y0 - w->field_1E9C) * k / n;
    Stg40B60 *b = D_80072B60;

    b->field_2C = x0 - dx;
    b->field_30 = y0 - dy;
    a0->stateLevel2++;
}

void func_80065300(Actor *a0) {
    Stg40B68Work *w = (Stg40B68Work *)a0->work;

    switch (a0->stateLevel1) {
    case 0:
    default:
        D_80072B60->field_2C = D_8005071C->field_1064->field_C;
        D_80072B60->field_30 = D_8005071C->field_1064->field_10;
        break;
    case 1:
        if (a0->stateLevel2 < w->field_1EA0) {
            func_80065278(a0);
        } else {
            D_80072B60->field_2C = w->field_1E90;
            D_80072B60->field_30 = w->field_1E94;
        }
        break;
    case 2:
        if (a0->stateLevel2 < w->field_1EA0) {
            func_80065278(a0);
        } else {
            D_80072B60->field_2C = w->field_1E90;
            D_80072B60->field_30 = w->field_1E94;
            Task_SetState1(a0, 0);
        }
        break;
    }
}

s32 func_800653EC(s32 a, s32 b, s32 c, s32 d) {
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

s32 func_80065424(s32 a, s32 b, s32 c, s32 d) {
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

void func_8006545C(Stg40W667C *w) {
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
    if (D_80072B60->field_30 & 0x3F) {
        rows = 0xB;
    }
    cols = 0xA;
    if (D_80072B60->field_2C & 0x3F) {
        cols = 0xB;
    }
    n.lo = rows;
    w->field_13D0 = cols;
    w->field_13D2 = n.lo;
    vec.field_2 = 0;
    t = (D_80072B60->field_30 & 0x3F) << 11;
    if (t < 0) {
        t += 0x3F;
    }
    vec.field_4 = ((u32)t >> 6) + 0x2400;
    step = 0x500;
    if (D_8005071C->field_E54->field_4 != 0) {
        step = -0x500;
    }
    for (row = 0; row < rows; row++) {
        t = (D_80072B60->field_2C & 0x3F) * 0xA00;
        if (t < 0) {
            t += 0x3F;
        }
        vec.field_0 = -(t >> 6) - 0x2D00;
        v = w->field_0[row];
        for (col = 0; col < cols; col++) {
            v->s[0].field_4 = RotTransPers(&vec, &v->s[0].x, 0, 0);
            v->s[0].x = v->s[0].x >> shiftX;
            v->s[0].y = v->s[0].y >> shiftY;
            v->s[0].field_4 = v->s[0].field_4 >> shiftZ;
            v->s[0].flag = ((v->s[0].x < 0 ? -v->s[0].x : v->s[0].x) < centerX)
                && ((v->s[0].y < 0 ? -v->s[0].y : v->s[0].y) < centerY);
            vec.field_2 += step;
            v->s[1].field_4 = RotTransPers(&vec, &v->s[1].x, 0, 0);
            v->s[1].x = v->s[1].x >> shiftX;
            v->s[1].y = v->s[1].y >> shiftY;
            v->s[1].field_4 = v->s[1].field_4 >> shiftZ;
            vec.field_2 -= step;
            v->s[1].flag = ((v->s[1].x < 0 ? -v->s[1].x : v->s[1].x) < centerX)
                && ((v->s[1].y < 0 ? -v->s[1].y : v->s[1].y) < centerY);
            vec.field_0 += 0xA00;
            v++;
        }
        vec.field_4 -= 0x800;
    }

    for (row = 0; row < rows; row++) {
        p = w->field_0[row];
        below = w->field_0[row + 1];
        for (col = 0; col < cols; col++) {
            if (col != cols - 1) {
                p->field_18 = func_800653EC(p->s[0].field_4, p->s[1].field_4, p[1].s[0].field_4, p[1].s[1].field_4);
            }
            if (row != rows - 1) {
                p->field_1C = func_800653EC(p->s[0].field_4, p->s[1].field_4, below->s[0].field_4, below->s[1].field_4);
            }
            p++;
            below++;
        }
    }
    PopMatrix();
}

void func_80065890(ActorWork *arg0)
{
    Stg40Cell *grid;
    s32 rowCount;
    s32 colCount;
    s32 gridCols;
    s32 gridRows;
    Stg40E34 *e54;
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

    e54 = D_8005071C->field_E54;
    grid = (Stg40Cell *)D_8005071C->field_E58;
    rowCount = 9;
    gridCols = e54->field_0;
    gridRows = e54->field_2;
    if (D_80072B60->field_30 & 0x3F) {
        rowCount = 0xA;
    }
    colCount = 9;
    if (D_80072B60->field_2C & 0x3F) {
        colCount = 0xA;
    }
    mapRow = D_80072B60->field_30 / 64 - 4;
    for (row = 0; row < rowCount; row++) {
        tp = ((Stg40W667C *)arg0)->field_F20[row];
        v0p = ((Stg40W667C *)arg0)->field_0[row];
        v1p = ((Stg40W667C *)arg0)->field_0[row + 1];
        mapCol = D_80072B60->field_2C / 64 - 4;
        for (col = 0; col < colCount; col++) {
            tp->field_4 = func_800653EC(v0p[0].s[0].field_4, v0p[1].s[0].field_4, v1p[0].s[0].field_4, v1p[1].s[0].field_4);
            tp->field_8 = func_80065424(v0p[0].s[1].field_4, v0p[1].s[1].field_4, v1p[0].s[1].field_4, v1p[1].s[1].field_4);
            if (mapCol < 0 || mapRow < 0 || mapCol >= gridCols || mapRow >= gridRows) {
                tp->field_0 = 0;
                tp->field_2 = 0;
                tp->field_3 = 0;
            } else {
                r = Rand_GetAt(mapCol + (mapRow << 6));
                tp->field_0 = grid[mapRow * gridCols + mapCol].field_0;
                tp->field_2 = grid[mapRow * gridCols + mapCol].field_3;
                k = tp->field_0 & 0xF;
                switch (k) {
                case 0:
                    tp->field_3 = 0;
                    break;
                case 1:
                case 2:
                    n = 0;
                    if (k == 1) {
                        n = 0x18;
                    }
                    tp->field_3 = n;
                    a = tp->field_3 + ((tp->field_0 >> 9) & 1);
                    tp->field_3 = a;
                    a = tp->field_3;
                    if (tp->field_0 & 0x80) {
                        a += 2;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if (tp->field_0 & 0x800) {
                        a += 4;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if ((u16)r < 0x200) {
                        a += 8;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if ((u16)r < 0x400) {
                        a += 8;
                    }
                    tp->field_3 = a;
                    a = tp->field_3;
                    if ((u16)r < 0x400) {
                        a |= 0x80;
                    }
                    tp->field_3 = a;
                    break;
                default:
                    tp->field_3 = (tp->field_0 & 0xF) + 0x2D;
                    a = tp->field_3;
                    if ((u16)r < 0x400) {
                        a |= 0x80;
                    }
                    tp->field_3 = a;
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

void func_80065BF8(s32 x, s32 z, s32 y, Stg40Vec3 *out) {
    Stg40B60 *b = D_80072B60;
    s32 t;

    out->field_4 = -(((z - b->field_30) << 11) / 64);
    t = x - b->field_2C;
    out->field_2 = -y;
    out->field_0 = t * 40;
}

s32 func_80065C50(Stg40W667C *w, s32 pkt, s32 x, s32 y)
{
    Stg40Tile *tile = &w->field_F20[y][x];
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

    base = &D_8007265C[(u16)D_8005071C->field_E54->field_A * 5];

    for (i = 0; i < 4; i++) {
        rec = &D_80072670[i];
        if ((tile->field_0 & rec->field_0) == 0) {
            continue;
        }
        a = &w->field_0[y + rec->field_4][x + rec->field_3];
        b = &w->field_0[y + rec->field_6][x + rec->field_5];
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
        k = (tile->field_2 >> rec->field_2) & 3;
        if (k == 0 && (tile->field_3 & 0x80)) {
            k = 4;
        }
        ot = &Sys_State.otLayers.u[3][w->field_0[y + rec->field_8][x + rec->field_7].field_1C];
        src = &w->field_143C[base[k]];
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

s32 func_80065F94(Stg40W667C *w, s32 pkt, s32 x, s32 y) {
    Stg40Vtx *a = &w->field_0[y][x];
    Stg40Vtx *b = &w->field_0[y + 1][x];
    Stg40Tile *t = &w->field_F20[y][x];
    s32 k = t->field_0 == 0;
    u32 *ot;

    if (a[0].s[k].flag + a[1].s[k].flag + b[0].s[k].flag + b[1].s[k].flag == 0) {
        return pkt;
    }
    if (t->field_0 != 0) {
        ot = D_8005F8C0;
        *(Stg40FT4 *)pkt = w->field_143C[D_80072620[t->field_3 & 0x7F]];
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
        ot = &D_8005F8B4[w->field_F20[y][x].field_8];
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

void func_8006620C(Stg40W667C *w) {
    s32 rows;
    s32 cols;
    s32 y;
    s32 x;
    s32 pkt;

    rows = (D_80072B60->field_30 & 0x3F) ? 10 : 9;
    cols = (D_80072B60->field_2C & 0x3F) ? 10 : 9;
    pkt = Sys_PacketCursor;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            pkt = func_80065F94(w, pkt, x, y);
            if (w->field_F20[y][x].field_0 & 0xF00) {
                pkt = func_80065C50(w, pkt, x, y);
            }
        }
    }
    Sys_PacketCursor = pkt;
}

void func_80066318(Actor *a0, s32 *ids) {
    Stg40W667C *w = (Stg40W667C *)a0->work;
    GfxTexSlot *slot;
    Stg40TexRec *e;
    Stg40FT4 *p;
    Stg40FT4 *q;
    s32 i;

    D_80072B68 = a0;
    D_80072B6C = w;
    w->field_1414 = 0;
    w->field_1438 = 0;
    for (i = 0; i < 2; i++) {
        slot = Gfx_FindOrLoadTexSlot(*ids);
        e = (Stg40TexRec *)Cd_GetFileEntry(*ids + 1);
        w->field_13D4[w->field_1414] = slot;
        w->field_13F4[w->field_1414] = e;
        w->field_1418[w->field_1414] = *ids;
        for (; e->u != 0xFF; e++) {
            p = &w->field_143C[w->field_1438];
            p->tag.b.len = 9;
            p->code = 0x2C;
            p->r0 = 0x7F;
            p->g0 = 0x7F;
            p->b0 = 0x7F;
            if (w->field_1438 != 26) {
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
            w->field_1438++;
        }
        ids++;
        w->field_1414++;
    }
    w->field_1418[w->field_1414] = -1;
    q = &w->field_143C[26];
    q->code |= 2;
}

void func_800665E0(Actor *a0) {
    ActorWork *w = a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        D_80072B60->field_2C = D_8005071C->field_1064->field_C;
        D_80072B60->field_30 = D_8005071C->field_1064->field_10;
        Task_NextState0(a0);
        break;
    case 1:
        func_80065300(a0);
        func_8006545C((Stg40W667C *)w);
        func_80065890(w);
        break;
    case 2:
        break;
    }
}

void func_8006667C(Actor *a0) {
    Stg40W667C *w = (Stg40W667C *)a0->work;
    s32 f = 1;
    s32 n = Beetle_GetPart(0x11);
    s32 *p;

    if (n <= 0 || (D_8005071C->field_1058 == 0x10 && n == 0x75)) {
        f = 0;
    }
    if (f) {
        func_8006620C(w);
    }
    for (p = w->field_1418; *p != -1; p++) {
        Gfx_FindOrLoadTexSlot(*p);
    }
}

void func_80066720(Actor *a0) {
    Stg40W6720 *w = (Stg40W6720 *)a0->work;
    Stg40Slot34 *s3 = (Stg40Slot34 *)a0->u34.children;
    TextOpenArgs args;
    Stg40E34 *fe;
    s32 n;
    s32 x = 0x12;
    s32 sh;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(&w->field_0, 3);
        w->field_C = 0;
        s3->field_0 = 0;
        n = D_8005071C->field_E54->field_D - 6;
        sh = n;
        do {
            if (n >= 7) {
                sh = 6;
            }
        } while (0);
        w->field_10 = ~(1 << sh);
        w->field_12 = Save_GameStatePtr->hp;
        w->field_14 = Save_GameStatePtr->mp;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_C) == 0) {
                fe = D_8005071C->field_E54;
                args.x = x;
                args.y = 0x16;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                args.text = (s32)fe->field_E;
                Text_Open(&w->field_8, &args);
                Text_SetOtLayer(w->field_8, 2);
                Text_OpenById(&w->field_0, D_800726B0[0].id, 0, D_800726B0[0].pos);
                Text_OpenById(&w->field_4, D_800726B0[1].id, 0, D_800726B0[1].pos);
                Text_SetOtLayer(w->field_0, 2);
                Text_SetOtLayer(w->field_4, 2);
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->field_12 > Save_GameStatePtr->hp) {
                w->field_12 = (w->field_12 - 0x21 < Save_GameStatePtr->hp) ? Save_GameStatePtr->hp : (u16)w->field_12 - 0x21;
            }
            if (w->field_12 < Save_GameStatePtr->hp) {
                w->field_12 = (Save_GameStatePtr->hp < w->field_12 + 0x21) ? Save_GameStatePtr->hp : (u16)w->field_12 + 0x21;
            }
            if (Save_GameStatePtr->hp == 0) {
                w->field_12 = 0;
            }
            if (w->field_14 > Save_GameStatePtr->mp) {
                w->field_14 = (w->field_14 - 1 < Save_GameStatePtr->mp) ? Save_GameStatePtr->mp : (u16)w->field_14 - 1;
            }
            if (w->field_14 < Save_GameStatePtr->mp) {
                w->field_14 = (Save_GameStatePtr->mp < w->field_14 + 1) ? Save_GameStatePtr->mp : (u16)w->field_14 + 1;
            }
            if (Save_GameStatePtr->mp == 0) {
                w->field_14 = 0;
            }
            break;
        }
        if (s3->field_0 != 0) {
            if (D_8005071C->field_BA5 == 0 && s3->field_0->stateLevel0 != 2) {
                Task_SetState0(s3->field_0, 2);
            }
        } else {
            if (D_8005071C->field_BA5 != 0) {
                Task_Create(0x20A, (s32 *)s3, 0);
            }
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            n = 3;
            Text_CloseArray(&w->field_0, n);
            if (s3->field_0 != 0) {
                Task_SetState0(s3->field_0, 2);
            }
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_C) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void func_80066AD0(Actor *a0) {
    Stg40W6AD0 *w = (Stg40W6AD0 *)a0->work;
    EntA0 *p;
    s32 i;

    if (w->field_C != 0) {
        for (i = 0; i < 2; i++) {
            p = Cd_GetFileEntry(D_800726C0[i]);
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

void func_80066BE4(Actor *a0) {
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
                Text_OpenById(w, D_800726E0.id, 0, D_800726E0.pos);
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

void func_80066D78(Actor *a0) {
    ActorWork *w = a0->work;
    EntA0 *p;

    if (w->field_4 != 0) {
        p = Cd_GetFileEntry(0x7D40002);
        Gfx_SetPartsNumber((GfxPart *)p, 2, 8, w->field_8);
        Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_4);
        Gfx_DrawParts((s32)p);
    }
}

void func_80066DF0(a0, a1, a2)
    u8 a0;
    u8 a1;
    u8 a2;
{
    Stg40ObjWork *w = (Stg40ObjWork *)D_80072B70->work;

    w->field_46 = a0;
    w->field_44 = a1;
    w->field_45 = a2;
    w->field_24 = -1;
}

s32 *func_80066E18(void) {
    return ((Stg40ObjWork *)D_80072B70->work)->field_28;
}

void func_80066E30(Actor *a0, s32 *a1) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;

    D_80072B70 = a0;
    w->field_20 = *a1;
}

void func_80066E48(Actor *a0) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;
    TextOpenArgs args;
    s32 n;
    s32 i;

    n = 6;
    if (w->field_20 != 0) {
        n = 7;
    }
    switch (a0->stateLevel0) {
    case 0:
    default:
        Mem_FillWordsNeg1(w->field_0, n);
        w->field_1C = 0;
        D_80072B70 = a0;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_1C) == 0) {
                args.x = 0x1B;
                args.y = 0x33;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 0;
                for (i = 0; i < w->field_44; i++) {
                    args.text = w->field_28[i];
                    Text_Open(&w->field_0[i], &args);
                    Text_SetOtLayer(w->field_0[i], 2);
                    args.y += 0xC;
                }
                if (w->field_20 != 0) {
                    args.bigFont = 1;
                    args.text = w->field_40;
                    args.x = 0x10;
                    args.y = 0x8A;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(&w->field_18, &args);
                    Text_SetOtLayer(w->field_18, 2);
                }
                w->field_24 = 0;
                Task_NextState1(a0);
            }
            break;
        case 1:
            if (w->field_24 != 0) {
                Task_SetState1(a0, 0);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->field_0, n);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero(a0, &w->field_1C) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void func_80067044(Actor *a0) {
    Stg40ObjWork *w = (Stg40ObjWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 n;
    s32 i;
    s32 mask;

    if (w->field_1C != 0) {
        n = 1;
        if (w->field_20 != 0) {
            n = 2;
        }
        for (i = 0; i < n; i++) {
            p = (GfxPart *)Cd_GetFileEntry(D_80072700[i]);
            switch (i) {
            case 0:
            default:
                mask = ((w->field_45 & 1) == 0) << 2;
                if (!(w->field_45 & 2)) {
                    mask |= 8;
                }
                for (q = p; q->fileId != 0; q++) {
                    if (q->groupMask & 2) {
                        q->x = -0x90;
                        q->y = w->field_46 * 12 - 0x46;
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
            Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_1C);
            Gfx_DrawParts((s32)p);
        }
    }
}

void func_800671E8(void) {
}

void func_800671F0(Actor *a0) {
    Stg40W71F0 *w = (Stg40W71F0 *)a0->work;
    Stg40SlotInfo *info;
    TextOpenArgs args;
    u16 *pos;
    s32 i;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
    default:
        D_80072B78 = a0;
        Mem_FillWordsNeg1(w->field_8, 12);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(a0, &w->field_0) == 0) {
                pos = D_80072720;
                info = (Stg40SlotInfo *)D_80072B60->field_80[D_80072B60->field_AC]->field_10;
                args.bigFont = 0;
                args.color = 0;
                args.charAdvance = 0;
                args.lineAdvance = 0xC;
                args.charDelay = 1;
                Text_CloseArray(w->field_8, 12);
                for (i = 0; i < info->field_B * 4; i++) {
                    args.x = *pos++;
                    args.y = *pos++;
                    k = info->field_10[i / 4];
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

void func_80067454(Actor *a0) {
    ActorWork *w = a0->work;
    Stg40SlotInfo *info;
    EntA0 *p;
    s32 i;

    if (w->field_0 != 0) {
        info = (Stg40SlotInfo *)D_80072B60->field_80[D_80072B60->field_AC]->field_10;
        for (i = 0; i < 3; i++) {
            p = Cd_GetFileEntry(D_80072750[i]);
            if (i >= info->field_B) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, -1);
            } else {
                Gfx_SetPartsNumber((GfxPart *)p, 2, 2, info->field_16[i]);
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
                Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->field_0);
            }
            Gfx_DrawParts((s32)p);
        }
    }
}

u8 *func_8006755C(s32 i, s32 v) {
    s32 d = 10000;
    s32 nz = 0;
    u8 *p = D_80072B90[i];
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
    p = D_80072B90[i];
    return p;
}

void func_80067610(s32 i, s32 file, s32 a2, s32 a3) {
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
    p = &D_80072B84[i];
    p[5] = 0;
    arg.strArg0 = a2;
    arg.strArg1 = a3;
    Text_Open(p, &arg);
}

void func_800676A4(s32 i) {
    Text_Close(&D_80072B84[i]);
}

s32 func_800676D0(s32 i) {
    s32 *p = &D_80072B84[i];

    return Text_IsFinished(*p);
}

s32 func_80067704(s32 i) {
    s32 r = 0;

    if (func_800676D0(i) == 1) {
        func_800676A4(i);
        r = 1;
    }
    return r;
}

s32 func_80067750(s32 i) {
    s32 *p = &D_80072B84[i];

    return Text_WaitYesNo(*p);
}

void func_80067784(void) {
}

void func_8006778C(Actor *a0) {
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
        D_80072B80 = a0;
        D_80072B84 = w;
        for (i = 4; i >= 0; i--) {
            w[i] = m;
        }
        Task_NextState0(a0);
        break;
    }
}

void func_800677F4(void) {
}

void func_800677FC(Blk16 *l, s32 r, s32 g, s32 b) {
    s32 i;
    Blk16 *p;

    for (i = 0, p = l; i < 3; i++, p++) {
        GsSetFlatLight(i, p);
    }
    GsSetAmbient(r, g, b);
    GsSetLightMode(0);
}

void func_80067880(Actor *a0, u8 a1) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    w->field_26 = a1;
    w->field_27 = 0;
}

void func_80067894(Actor *a0, u8 on, u8 r, u8 g, u8 b) {
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

s32 func_800678C4(Actor *a0) {
    return a0->model->animDone < 0;
}

s32 func_800678D8(Stg40Ent48 *e) {
    s32 d;
    Stg40Loc *loc = &e->field_18;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 c;

    if ((s16)e->field_E != e->field_C) {
        c = e->field_C;
        if (((s16)(e->field_E - ((u16)e->field_C - 0x1000)) / 0x800) & 1) {
            e->field_C = c - 0x100;
        } else {
            e->field_C = c + 0x100;
        }
        e->field_C &= 0xFFF;
        d = (s16)e->field_E - e->field_C;
        if ((d >= 0) ? (d < 0x100) : ((e->field_C - (s16)e->field_E) < 0x100)) {
            e->field_C = e->field_E;
        }
    }
    e->field_B = (s16)e->field_E / 512;
    if ((s16)e->field_E == e->field_C && loc->field_8 != 0 && --loc->field_8 == 0 && loc->field_1C == 1) {
        loc->field_1C = 0;
    }
    x = loc->u0.pair.field_0 << 6;
    dx = ((x - (loc->field_4.field_0 << 6)) * loc->field_8) / loc->field_A;
    y = loc->u0.pair.field_2 << 6;
    dy = ((y - (loc->field_4.field_2 << 6)) * loc->field_8) / loc->field_A;
    loc->field_C = x - dx;
    loc->field_10 = y - dy;
    e->field_A = func_80070438(loc->u0.pair.field_0, loc->u0.pair.field_2)->field_2;
    return loc->field_8 != 0;
}

void func_80067A80(Actor *a0, Stg40Ent48 *e)
{
  Stg40ActWork *w = (Stg40ActWork *) a0->work;
  Stg40Ent48 *new_var;
  Stg40Loc *loc;
  w->field_2C = e;
  e->field_14 = a0;
  if (e->field_4 != (-1))
  {
    a0->digiId = e->field_4;
    w->field_14 = Digi_GetModelFile(a0->digiId);
    w->field_18 = Anim_GetModelAnimFile(a0->digiId, 4);
    w->field_C = 0;
    w->field_8 = 0;
    w->field_4 = 0;
    w->field_10 = (s16) e->field_E;
    w->field_20 = 0;
    w->field_22 = (w->field_23 = (w->field_24 = 0x80));
    w->field_26 = 0;
    w->field_27 = 0;
    w->field_28 = 0;
  }
  loc = &e->field_18;
  e->field_18.u0.pair.field_0 = (loc->field_4.field_0 = e->field_18.u0.pair.field_0);
  loc->u0.pair.field_2 = (loc->field_4.field_2 = e->field_18.u0.pair.field_2);
  loc->field_8 = 0;
  loc->field_A = 1;
  loc->field_1C = 0;
  loc->field_C = loc->u0.pair.field_0 << 6;
  loc->field_10 = loc->u0.pair.field_2 << 6;
  if (e->field_0 & 1)
  {
    D_8005071C->field_1064 = loc;
    D_8005071C->field_1068 = loc;
    new_var = w->field_2C;
    D_80072B60->field_8 = a0;
    D_80072B60->field_4 = new_var;
    func_80070B2C(e->field_7);
  }
  w->field_34 = 0;
}

void func_80067BA8(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Arg207 arg;
    s32 *slot;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Task_NextState0(a0);
        if (w->field_2C->field_0 & 0x100) {
            if (w->field_2C->field_0 & 1) {
                Task_SetState1(a0, 5);
            }
            if (w->field_2C->field_0 & 2) {
                if (w->field_2C->field_0 & 0x800) {
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 3);
                }
            }
            if (w->field_2C->field_0 & 0x200) {
                Task_SetState1(a0, 0);
                w->field_2C->field_0 &= ~0x200;
            }
            w->field_2C->field_0 &= ~0x900;
        }
        Actor_InitTransform(a0, &w->field_4, w->field_10);
        w->field_30 = 0x28;
        w->field_32 = -1;
        w->field_36 = -1;
        w->field_38 = -1;
        break;
    case 1:
        func_800678D8(w->field_2C);
        if (w->field_2C->field_0 & 1) {
            func_8006B420(a0);
        }
        if (w->field_2C->field_0 & 2) {
            func_8006BFB0(a0);
        }
        if (w->field_2C->field_0 & 4) {
            func_8006D418(a0);
        }
        if (w->field_36 != -1) {
            slot = (s32 *)a0->u34.children;
            if (*slot != 0) {
                Task_SetState0((Actor *)*slot, 3);
            } else {
                arg.field_0 = a0;
                arg.field_4 = w->field_36;
                Task_Create(0x207, slot, (s32)&arg);
                w->field_38 = w->field_36;
                w->field_36 = -1;
            }
        }
        break;
    case 2:
        break;
    }
}

void func_80067DB4(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;
    Stg40Xform *x;
    s32 dx;
    s32 dy;
    s32 vis;
    s32 r;
    u8 k;

    w->field_34 = 0;
    if (e->field_4 == -1) {
        return;
    }
    dx = e->field_18.field_C - D_80072B60->field_2C;
    if (dx < 0) {
        dx = D_80072B60->field_2C - e->field_18.field_C;
    }
    dy = e->field_18.field_10 - D_80072B60->field_30;
    if (dy < 0) {
        dy = D_80072B60->field_30 - e->field_18.field_10;
    }
    if (dx < 0x1C0 && dy < 0x1C0) {
        Cd_QueueFile(w->field_14);
        Cd_QueueFile(w->field_18);
    }
    if (dx < 0x140 && dy < 0x140) {
        vis = 1;
        r = Beetle_GetPart(0x11);
        if (r <= 0 || (D_8005071C->field_1058 == 0x10 && r == 0x75)) {
            vis = 0;
        }
        if (e->field_0 & 1) {
            vis = 1;
        }
        Gfx_AttachModel(a0, w->field_14)->otIndex = 3;
        if (w->field_30 != -1) {
            Anim_SetModelAnim(a0, w->field_30);
            w->field_32 = w->field_30;
            w->field_30 = -1;
        }
        x = (Stg40Xform *)a0->u38.ptr38;
        x->field_30 = (s16)((e->field_18.field_C - D_80072B60->field_2C) * 40);
        x->field_38 = (s16)-(((e->field_18.field_10 - D_80072B60->field_30) << 11) / 64);
        x->field_34 = -(s16)e->field_18.field_14;
        x->field_42 = e->field_C;
        x->field_58 = e->field_38;
        x->field_5C = e->field_3C;
        x->field_60 = e->field_40;
        if ((e->field_0 & 0x4000) && vis) {
            if (!(e->field_0 & 0x80)) {
                func_80064BD8(&e->field_18);
            }
            if (!(e->field_0 & 0x400)) {
                Anim_StepModelAnim(a0);
                Actor_UpdateTransform(a0);
                Gfx_CalcModelBoneMatrices(a0);
                Gfx_DrawTexModel(a0, 0);
            }
        }
        w->field_34 = 1;
    }
    if (w->field_26 != 0) {
        k = D_8007278C[w->field_27];
        if (k == 0xFF) {
            w->field_26 = 0;
            func_80067894(a0, 0, 0, 0, 0);
        } else {
            func_80067894(a0, k, D_8007279C[w->field_26 - 1].r, D_8007279C[w->field_26 - 1].g,
                          D_8007279C[w->field_26 - 1].b);
            w->field_27++;
        }
    }
}

void func_800680B0(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    func_8006E4DC(a0, a1);
    Task_SetState1(a0, 9);
    D_80072B60->field_34 = a2;
    D_80072B60->field_38 = a3;
    D_80072B60->field_44 = a4;
    D_80072B60->field_48 = a5;
    D_80072B60->field_4C = a6;
}

void func_8006813C(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_8006E4DC(a0, a1);
    Task_SetState1(a0, 0xB);
    D_80072B60->field_38 = a2;
    func_80067610(1, a3, a4, a5);
}

s32 func_800681BC(Actor *a0) {
    Stg40Ent48 *self = ((Stg40ActWork *)a0->work)->field_2C;
    Stg40Ent48 *e;
    s32 i;

    if (Pad_Square > 0 && self->field_A != 0xFF) {
        e = D_8005071C->field_18;
        D_80072B60->field_A8 = 0;
        D_80072B60->field_AC = 0;
        for (i = 0; i < D_8005071C->field_C; e++, i++) {
            if ((e->field_0 & 0x8000) && e->field_8 == 1 && e->field_A == self->field_A) {
                D_80072B60->field_80[D_80072B60->field_A8++] = e;
            }
        }
        if (D_80072B60->field_A8 != 0) {
            Task_SetState1(a0, 0x1A);
            D_80072B60->field_7E = 0;
            return -1;
        }
    }
    return 0;
}

s32 func_800682DC(Actor *a0)
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

    e = ((Stg40ActWork *)a0->work)->field_2C;
    if (D_8005F704 <= 0) {
        return 0;
    }
    found = func_8006E200(e->field_18.u0.pair.field_0 + ((s16 *)D_800727C0)[(e->field_B + 1) << 1],
                          e->field_18.u0.pair.field_2 + ((s16 *)D_800727C0)[((e->field_B + 1) << 1) | 1]);
    if (found == 0) {
        snd2 = 0x1FD000F;
        r2 = func_800703E0(e->field_18.u0.pair.field_0 + ((s16 *)D_800727C0)[(e->field_B + 1) << 1],
                          e->field_18.u0.pair.field_2 + ((s16 *)D_800727C0)[((e->field_B + 1) << 1) | 1]) & 0xF;
        if (r2 >= 3) {
            snd2 = r2 + 0x1FD0194;
        }
        Snd_PlayById(0x2E, 0);
        func_800680B0(a0, 0x2D, 0x28, 6, snd2, 0, 0);
        goto end;
    }
    child = found->field_14;
    D_80072B60->field_3C = child;
    D_80072B60->field_40 = found;
    switch (found->field_8) {
    default:
        Snd_PlayById(0x2E, 0);
        func_800680B0(a0, 0x2D, 0x28, 6, 0x1FD000F, 0, 0);
        return -1;
    case 2:
    case 3:
        Snd_PlayById(0x2E, 0);
        func_800680B0(a0, 0x2D, 0x28, 6, (found->field_8 == 2) ? 0x1FD0195 : 0x1FD0196, 0, 0);
        return -1;
    case 4:
        Task_SetState1(a0, 0x13);
        return -1;
    case 8:
        snd = -1;
        if (!(found->field_0 & 0x1000)) {
            break;
        }
        r = func_8006E820(6);
        if (r == -1) {
            snd = 0x1FD0019;
        } else if (r == 0) {
            snd = 0x1FD001A;
        } else {
            lim = found->field_10[1];
            if (func_8006E858(6) < lim) {
                snd = 0x1FD0018;
            }
        }
        if (snd != -1) {
            func_8006813C(a0, 0x28, 1, snd, 0, 0);
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
        idx = found->field_8 - 6;
        if (!(found->field_0 & 0x1000)) {
            break;
        }
        Item_CheckId(0);
        r3 = func_8006E920(&D_800727E8[idx]);
        if (r3 != 0) {
            func_8006813C(a0, 0x28, 1, r3, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0x11);
        D_80072B60->field_7E = 0;
        D_80072B60->field_E4 = 0;
        D_80072B60->field_E0 = D_80072B60->field_B0[0];
        goto end;
    }
    Task_SetState1(a0, 0xC);
end:
    return -1;
}

s32 func_80068604(Stg40Ent48 *e) {
    Stg40Loc *loc = &e->field_18;
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

    if (loc->field_1C != 0) {
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
    k = D_800728D4[idx];
    oct = (s16)k;
    if (k < 0) {
        return 0;
    }
    if (D_8005071C->field_BA0 & 2) {
        oct = (oct + D_8005071C->field_BA4) & 7;
    }
    e->field_E = (oct << 16) >> 7;
    e->field_B = oct;
    if (Pad_State[0].l1 != 0 && (oct & 1) == 0) {
        return 0;
    }
    if (D_8005F710 != 0) {
        return 0;
    }
    dir = oct + 1;
    oct = dir;
    if ((s16)e->field_E != e->field_C) {
        return 0;
    }
    nx = ny = -1;
    loc->field_1E &= 0xFFFE;
    d = dir;
    {
        s16 *p = (s16 *)D_800727C0;

        f = func_800703E0(loc->u0.pair.field_0 + p[d << 1], loc->u0.pair.field_2 + p[(d << 1) | 1]);
    }
    if (!(f & 0x8000) || (f & 0x30) == 0x20) {
        return 0;
    }
    if (f & 0x10) {
        loc->field_1E |= 1;
        dir = loc->u0.pair.field_0;
        nx = dir + ((s16 *)D_800727C0)[d << 1];
        ny = loc->u0.pair.field_2 + ((s16 *)D_800727C0)[(d << 1) | 1];
    }
    if ((oct & 1) == 0) {
        pl = &((s16 *)D_800727C0)[(d - 1) << 1];
        fl = func_800703E0(loc->u0.pair.field_0 + pl[0],
                           loc->u0.pair.field_2 + ((s16 *)D_800727C0)[((d - 1) << 1) | 1]);
        fr = func_800703E0(loc->u0.pair.field_0 + ((s16 *)D_800727C0)[(d + 1) << 1],
                           loc->u0.pair.field_2 + ((s16 *)D_800727C0)[((d + 1) << 1) | 1]);
        if (!(fl & 0x8000) || (fl & 0x30) == 0x20 || !(fr & 0x8000) || (fr & 0x30) == 0x20) {
            return 0;
        }
        if (fl & 0x10) {
            loc->field_1E |= 1;
            nx = loc->u0.pair.field_0 + pl[0];
            ny = loc->u0.pair.field_2 + ((s16 *)D_800727C0)[((d - 1) << 1) | 1];
        } else if (fr & 0x10) {
            loc->field_1E |= 1;
            nx = loc->u0.pair.field_0 + ((s16 *)D_800727C0)[(d + 1) << 1];
            ny = loc->u0.pair.field_2 + ((s16 *)D_800727C0)[((d + 1) << 1) | 1];
        }
    }
    if (D_8005071C->field_BA0 & 1) {
        return 1;
    }
    if (nx != -1) {
        Stg40Ent48 *te = func_8006E200(nx, ny);
        Stg40B60 *b = D_80072B60;

        b->field_40 = te;
        b->field_3C = te->field_14;
    }
    loc->field_4.field_0 = loc->u0.pair.field_0;
    loc->field_4.field_2 = loc->u0.pair.field_2;
    tbl = (s16 *)D_800727C0;
    loc->u0.pair.field_0 += tbl[(s16)oct << 1];
    loc->u0.pair.field_2 += tbl[((s16)oct << 1) | 1];
    loc->field_A = 0xC;
    loc->field_8 = 0xC;
    dir = loc->field_4.field_2;
    func_80070974(loc->field_4.field_0, dir);
    func_800708FC(loc->u0.pair.field_0, loc->u0.pair.field_2, 1);
    loc->field_1C = 1;
    return 1;
}

Stg40Ent48 *func_800689E0(Stg40Ent48 *a0) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Ent48 *e = b->field_18;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < b->field_C; i++, e++) {
        if ((e->field_0 & 0x8000) && e != a0 && e->field_18.u0.field_0 == a0->field_18.u0.field_0) {
            r = e;
            break;
        }
    }
    return r;
}

s32 func_80068A54(Actor *task) {
    Stg40ActWork *w = (Stg40ActWork *)task->work;
    Stg40Ent48 *ent = w->field_2C;
    Stg40Ent48 *other;
    GameStateView *gs;
    u16 dir;
    s32 n;
    s32 hp;
    s32 state;
    s32 ret;
    Actor *child;

    ret = 0;
    if ((u32)((dir = func_800703E0(ent->field_18.u0.pair.field_0, ent->field_18.u0.pair.field_2) & 0xF) - 8) < 5) {
        n = dir - 7;
        if (func_8006E858(5) < n) {
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
    other = func_800689E0(ent);
    if (other != NULL) {
        child = other->field_14;
        D_80072B60->field_3C = child;
        D_80072B60->field_40 = other;
        switch (other->field_8) {
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

s32 func_80068B8C(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;
    s32 r = 0;
    Stg40Ent48 *f;
    Stg40B60 *b;
    Actor *t;

    if (func_8006E6CC()) {
        Task_SetState1(a0, 0x1E);
        return 1;
    }
    f = func_800689E0(e);
    if (f == NULL) {
        return 0;
    }
    t = f->field_14;
    b = D_80072B60;
    b->field_3C = t;
    b->field_40 = f;
    switch (f->field_8) {
    case 2:
    case 3:
        D_8005071C->field_1 = (f->field_8 != 2) ? 3 : 2;
        Task_SetState1(a0, 0x17);
        r = 1;
        break;
    }
    return r;
}

s32 func_80068C60(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;
    Stg40Loc *l = &e->field_18;
    s32 r = 0;
    s16 t;

    if (l->field_8 == l->field_A / 2 && (l->field_1E & 1)) {
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        t = e->field_18.u0.pair.field_0;
        e->field_18.u0.pair.field_0 = e->field_18.field_4.field_0;
        e->field_18.field_4.field_0 = t;
        t = e->field_18.u0.pair.field_2;
        e->field_18.u0.pair.field_2 = e->field_18.field_4.field_2;
        e->field_18.field_4.field_2 = t;
        e->field_18.field_8 = 0xC;
        e->field_18.field_A = 0x18;
        func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
        Task_SetState1(a0, 0xF);
        r = -1;
    }
    return r;
}

void func_80068D3C(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;

    func_8006E4E8(a0, 0x28);
    if (func_80070C94() == e->field_7) {
        func_80065134(&e->field_18);
        if (func_8006E330()) {
            Task_SetState1(a0, 4);
        } else {
            Task_SetState1(a0, 1);
        }
    }
}

void func_80068DC0(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_8006E4E8(a0, 0x29);
    if (e->field_18.field_8 == 0xB) {
        Snd_PlayById(0x2C, 0);
    }
    if (func_80068C60(a0) != 0) {
        return;
    }
    if (w->field_2C->field_18.field_8 >= 2) {
        return;
    }
    Save_GameStatePtr->mp = (Save_GameStatePtr->mp - 1 < 0) ? 0 : (u16)Save_GameStatePtr->mp - 1;
    if (func_80068A54(a0) != 0) {
        return;
    }
    if (func_800716EC(a0)) {
        Task_SetState1(a0, 8);
        return;
    }
    if (Flag_Test(0x68) && Save_GameStatePtr->mp == 0) {
        Save_GameStatePtr->mp = 1;
    }
    if (Save_GameStatePtr->mp == 0 || Save_GameStatePtr->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (func_80068B8C(a0) == 0) {
        Task_SetState1(a0, 3);
    }
}

void func_80068F20(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    if (func_80070C48() == e->field_7) {
        if (func_80068604(w->field_2C) == 1) {
            Task_SetState1(a0, 2);
        } else {
            Task_SetState1(a0, 0);
        }
    } else if (func_8006E330()) {
        Task_SetState1(a0, 4);
    } else {
        Task_SetState1(a0, 0);
    }
}

void func_80068FBC(Actor *a0) {
    if (func_800716EC(a0)) {
        Task_SetState1(a0, 8);
    } else {
        Task_SetState1(a0, 7);
    }
}

void func_80068FFC(Actor *a0) {
    if (Flag_Test(0x68) && Save_GameStatePtr->mp == 0) {
        Save_GameStatePtr->mp = 1;
    }
    if (Save_GameStatePtr->mp == 0 || Save_GameStatePtr->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (func_80068B8C(a0) == 0) {
        func_80070C48();
        Task_SetState1(a0, 0);
        if (func_8006E330()) {
            Task_SetState1(a0, 4);
        }
    }
}

void func_800690CC(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    s32 arg = 0;
    s32 k;

    if (b->field_68 == 0) {
        Task_SetState1(a0, 7);
        return;
    }
    b->field_68--;
    k = b->field_60[b->field_68];
    if (k >= 2 && k < 6) {
        arg = (s32)Save_GameStatePtr->field_D1;
    }
    if (k == 6) {
        arg = b->field_78;
    }
    if (k == 7) {
        arg = (s32)b->field_6A;
    }
    func_8006813C(a0, 0x28, 8, D_80072868[k], arg, 0);
}

void func_80069188(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    s32 v;
    s32 n;

    func_8006E4E8(a0, 0x28);
    if (D_8005071C->field_2 != 0) {
        return;
    }
    if (Pad_Circle > 0 && D_80072AA0->stateLevel0 == 1 && D_80072AA0->stateLevel1 == 1 && D_80072AA0->stateLevel2 == 1) {
        Task_SetState1(D_80072AA0, 4);
        D_8005071C->field_2 = 1;
        return;
    }
    if (func_80068604(w->field_2C) == 1) {
        if (D_8005071C->field_BA0 & 1) {
            func_8006813C(a0, 0x28, 6, 0x1FD001D, 0, 0);
        } else {
            Task_SetState1(a0, 2);
        }
        return;
    }
    if (func_800682DC(a0) == 0 && func_800681BC(a0) == 0 && Beetle_GetPart(0x12) > 0 && Pad_Select > 0) {
        v = Save_GameStatePtr->field_0 + 1;
        n = (v < 3) ? v : 0;
        Save_GameStatePtr->field_0 = n;
        D_80072B60->field_7E = Save_GameStatePtr->field_0;
    }
}

void func_8006932C(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2D);
        Task_SetState2(a0, 1);
        break;
    case 1:
        if (func_800678C4(a0) == 1) {
            Task_SetState2(a0, 2);
        }
        break;
    case 2:
        if (D_8005071C->field_2 == 0) {
            if (func_80070C94() == e->field_7) {
                Task_SetState1(a0, 1);
            } else {
                Task_SetState1(a0, 0);
            }
        }
        break;
    }
}

void func_8006940C(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        if (func_8006E588(a0) == 1) {
            if (D_80072B60->field_34 != -1) {
                func_8006E4DC(a0, D_80072B60->field_34);
            }
            func_80067610(1, D_80072B60->field_44, D_80072B60->field_48, D_80072B60->field_4C);
            Task_NextState2(a0);
        }
        break;
    case 1:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, (u8)D_80072B60->field_38);
        }
        break;
    }
}

void func_800694D0(Actor *a0) {
    if (func_8006E588(a0) == 1) {
        Task_SetState1(a0, (u8)D_80072B60->field_38);
    }
}

void func_80069514(Actor *a0) {
    if (func_80067704(1) == 1) {
        Task_SetState1(a0, (u8)D_80072B60->field_38);
    }
}

void func_8006955C(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    Stg40Ent48 *e = b->field_40;
    Actor *t = b->field_3C;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        func_8006E4DC(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            Task_SetState1(t, 5);
            func_80067610(1, 0x1FD0010, (s32)Cd_GetFileEntry(e->field_8 + 0x1FD0064), 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_8006965C(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2F, 0);
        func_8006E4DC(a0, 0x2C);
        func_80067880(a0, 1);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_800678C4(a0) == 1 || a0->stateLevel4++ >= 11) {
            func_8006E4DC(a0, 0x28);
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_80069714(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;
    s32 msg;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2A);
        Snd_PlayById(0x2E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            r = Beetle_GetPart(6);
            n = e->field_10[1];
            if (Item_GetLevel(r) >= n) {
                Task_SetState1(t, 6);
                msg = 0x1FD0017;
            } else {
                msg = 0x1FD0018;
            }
            func_80067610(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_80069830(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2C);
        func_80067880(a0, 2);
        Task_SetState1(t, 4);
        D_80072B60->field_58 = e->field_10[1] * 200;
        func_8006E8F4(D_80072B60->field_58);
        Snd_PlayById(0x33, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            func_80067610(1, 0x1FD001F, (s32)Save_GameStatePtr->field_D1, (s32)func_8006755C(0, D_80072B60->field_58));
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_8006997C(Actor *arg0)
{
    Stg40Ent48 *e;
    Actor *t;
    s32 idx;
    s32 bit;
    s32 r;
    s32 n;

    e = D_80072B60->field_40;
    t = D_80072B60->field_3C;
    idx = e->field_8 - 9;
    bit = 0x100 << idx;
    switch (arg0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(arg0, 0x28);
        Task_SetState1(t, 4);
        Task_NextState2(arg0);
        break;
    case 1:
        if (t->stateLevel1 != 1) {
            return;
        }
        r = 0;
        switch (e->field_8) {
        default:
            if (((Stg40BA5View *)D_8005071C)->field_BA5[idx] == 0) {
                ((Stg40BA5View *)D_8005071C)->field_BA5[idx] = e->field_10[1];
                r = -1;
            }
            break;
        case 9:
            if (D_8005071C->field_BA5 == 0) {
                if (Save_GameStatePtr->bits != 0 || func_80071608() != -1) {
                    r = -1;
                    ((Stg40BA5View *)D_8005071C)->field_BA5[e->field_8 - 9] = e->field_10[1];
                }
            }
            break;
        case 0xB:
            if (D_8005071C->field_BA7 != 0 || ((s32 (*)(s32))func_8006EA84)(1) < 2 || Digi_CountByState(1) >= 0x18) {
                r = 0;
            } else {
                r = -1;
                ((Stg40BA5View *)D_8005071C)->field_BA5[e->field_8 - 9] = e->field_10[1];
            }
            break;
        case 0xC:
            n = ((s32 (*)(void))Beetle_GetDigiCapacity)();
            n -= ((s32 (*)(s32))func_8006EA84)(0);
            if (n != D_8005071C->field_BA8) {
                D_8005071C->field_BA9[D_8005071C->field_BA8] = e->field_10[1];
                r = -1;
                D_8005071C->field_BA8++;
            }
            break;
        }
        if (r == 0) {
            func_80067610(1, e->field_8 + 0x1FD0022, (s32)Save_GameStatePtr + 0xD1, 0);
            Task_SetState2(arg0, 3);
        } else {
            D_8005071C->field_BA0 &= ~bit;
            func_8006E4DC(arg0, 0x2A);
            func_80067880(arg0, 2);
            Task_NextState2(arg0);
            Snd_PlayById(0x2F, 0);
        }
        break;
    case 2:
        if (func_8006E588(arg0) == 1) {
            func_8006E4DC(arg0, 0x28);
            func_80067610(1, e->field_8 + 0x1FD001E, 0, 0);
            Task_NextState2(arg0);
        }
        break;
    case 3:
        if (func_80067704(1) == 1) {
            Task_SetState1(arg0, 6);
        }
        break;
    }
}

void func_80069C94(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->field_2C;
    Stg40B60 *g = D_80072B60;
    Stg40Ent48 *t;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_Create(0x20C, &D_80072AA4->field_14, 0);
        func_8006E4DC(a0, 0x28);
        Task_NextState2(a0);
        break;
    case 1:
        t = g->field_80[g->field_AC];
        g->field_3C = t->field_14;
        g->field_40 = t;
        func_800651C0(&t->field_18, 0x10);
        Task_SetState0((Actor *)D_80072AA4->field_14, 2);
        Task_SetState1((Actor *)D_80072AA4->field_14, 0x64);
        Task_NextState2(a0);
        break;
    case 2:
        if (a0->stateLevel3 == 0) {
            if (func_80065230() != 0) {
                Snd_PlayById(0x12, 0);
                Task_SetState3(a0, 1);
            }
        }
        if (Pad_State[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 0x64);
        } else if (Pad_State[0].square > 0 && D_80072B60->field_A8 >= 2) {
            n = D_80072B60->field_AC + 1;
            D_80072B60->field_AC = (n < D_80072B60->field_A8) ? n : 0;
            Task_SetState2(a0, 1);
        } else if (D_8005F704 > 0) {
            r = func_8006E920(&D_80072858);
            if (r != 0) {
                func_80067610(1, r, 0, 0);
                Task_SetState2(a0, 0x3C);
            } else {
                Task_SetState1(a0, 0x11);
                D_80072B60->field_E4 = 1;
                D_80072B60->field_E0 = D_80072B60->field_B0[0];
            }
        }
        break;
    case 0x3C:
        if (func_80067704(1) == 1) {
            Task_SetState2(a0, 2);
            Task_SetState3(a0, 1);
        }
        break;
    case 0x64:
        func_80065134(&e->field_18);
        Task_SetState0((Actor *)D_80072AA4->field_14, 2);
        Task_NextState2(a0);
        break;
    case 0x65:
        if (D_80072AA4->field_14 == 0) {
            g->field_7E = Save_GameStatePtr->field_0;
            Task_SetState1(a0, 1);
        }
        break;
    }
}

void func_80069F84(Actor *actor) {
    s32 state = actor->stateLevel2;
    Stg40Ent48 *self = ((Stg40ActWork *)actor->work)->field_2C;
    Stg40Ent48 *target = D_80072B60->field_40;
    Stg40Loc *loc = &D_80072B60->field_108;

    switch (state) {
    case 0:
    default: {
        s32 angle;

        func_8006E4DC(actor, 0x29);
        angle = ratan2(self->field_18.field_C - target->field_18.field_C,
                       target->field_18.field_10 - self->field_18.field_10);
        D_80072B60->field_E8 = angle & 0xFFF;
        D_80072B60->field_EC = -rsin(D_80072B60->field_E8);
        D_80072B60->field_F0 = rcos(D_80072B60->field_E8);
        D_80072B60->field_F4 = self->field_18.u0.pair.field_0 << 14;
        D_80072B60->field_F8 = self->field_18.u0.pair.field_2 << 14;
        D_80072B60->field_FC = target->field_18.u0.pair.field_0 << 14;
        D_80072B60->field_100 = target->field_18.u0.pair.field_2 << 14;
        Task_NextState2(actor);
        break;
    }
    case 1:
        if ((s16)self->field_E != D_80072B60->field_E8) {
            s32 h = (s16)self->field_E;
            s32 diff = (s16)((u16)D_80072B60->field_E8 - ((u16)self->field_E - 0x1000));
            s32 d;
            s32 t;

            if (diff < 0) {
                diff += 0x7FF;
            }
            if ((diff >> 11) & 1) {
                self->field_E = h - 0x40;
            } else {
                self->field_E = h + 0x40;
            }
            t = self->field_E & 0xFFF;
            self->field_E = t;
            d = D_80072B60->field_E8 - t;
            if ((d >= 0) ? (d < 0x40) : (t - D_80072B60->field_E8 < 0x40)) {
                self->field_E = D_80072B60->field_E8;
            }
            self->field_C = self->field_E;
        } else {
            func_8006E4DC(actor, 0x28);
            goto next;
        }
        break;
    case 2:
        if (actor->stateLevel4++ < 0x10) {
            break;
        }
        Snd_PlayById(0x2D, 0);
        func_8006E4DC(actor, 0x2A);
        goto next;
    case 3:
        if (actor->stateLevel4++ < 6) {
            break;
        }
        goto next;
    case 4: {
        s32 ax;
        s32 ay;

        D_80072B60->field_F4 += D_80072B60->field_EC;
        D_80072B60->field_F8 += D_80072B60->field_F0;
        loc->field_C = D_80072B60->field_F4 >> 8;
        loc->field_10 = D_80072B60->field_F8 >> 8;
        func_80065134(loc);
        ax = D_80072B60->field_EC;
        ax = (ax >= 0) ? ax : -ax;
        if ((D_80072B60->field_FC - D_80072B60->field_F4 >= 0)
                ? (ax >= D_80072B60->field_FC - D_80072B60->field_F4)
                : (ax >= D_80072B60->field_F4 - D_80072B60->field_FC)) {
            ay = D_80072B60->field_F0;
            ay = (ay >= 0) ? ay : -ay;
            if ((D_80072B60->field_100 - D_80072B60->field_F8 >= 0)
                    ? (ay >= D_80072B60->field_100 - D_80072B60->field_F8)
                    : (ay >= D_80072B60->field_F8 - D_80072B60->field_100)) {
                func_80065134(&target->field_18);
                Task_NextState2(actor);
                Snd_PlayById(0x1B, 0);
            }
        }
        break;
    }
    case 5: {
        Stg40SlotInfo *info;
        s32 msg;

        if (actor->stateLevel4++ < 0x1F) {
            break;
        }
        info = (Stg40SlotInfo *)target->field_10;
        msg = 0x1FD0050;
        if (info->field_A < 9) {
            s32 r = Item_GetCategory(D_80072B60->field_E0);
            s32 kind;

            if (r >= 0x25) {
                kind = 3;
            } else if (r >= 0x22) {
                kind = 0x22;
                kind = r - kind;
            } else {
                kind = 3;
            }
            if (kind == 3 || kind == info->field_3) {
                if (func_80071180() < D_80072888[info->field_A]) {
                    s32 idx;

                    info->field_A++;
                    idx = Item_GetLevel(D_80072B60->field_E0);
                    msg = 0x1FD004F;
                    info->field_C += D_80072894[idx - 1];
                }
            }
        }
        func_80067610(1, msg, Digi_GetDefaultName(info->field_10[0]),
                      Item_GetNameText(D_80072B60->field_E0));
        goto next;
    }
    case 6:
        if (func_80067704(1) != 1) {
            break;
        }
        func_800651C0(&self->field_18, 8);
        Task_SetState0((Actor *)D_80072AA4->field_14, 2);
    next:
        Task_NextState2(actor);
        break;
    case 7:
        if (D_80072AA4->field_14 == 0) {
            break;
        }
        Task_SetState1(actor, 6);
        D_80072B60->field_7E = Save_GameStatePtr->field_0;
        break;
    }
}

void func_8006A498(Actor *a0) {
    u8 *d = D_80072B60->field_40->field_10;
    s32 r;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        func_8006E4DC(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (d[1] == 0) {
            Task_SetState1(a0, 0x14);
        } else {
            D_80072B60->field_50 = func_80071204(d[1]);
            r = func_800715DC(7);
            msg = D_80072B60->field_50 + 0x1FD0040;
            if (r == -1) {
                msg = 0x1FD0045;
            }
            if (r == 0) {
                msg = 0x1FD0046;
            }
            func_80067610(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 3:
        switch (func_80067750(1)) {
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

void func_8006A614(Actor *a0) {
    Stg40B60 *b = D_80072B60;
    Actor *t = b->field_3C;
    u8 *d = b->field_40->field_10;

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
        } else if (func_80071258(b->field_50) == 1) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 0x16);
        }
        break;
    }
}

void func_8006A6EC(Actor *a0) {
    Actor *t = D_80072B60->field_3C;
    u8 *d = D_80072B60->field_40->field_10;

    switch (a0->stateLevel2) {
    case 0:
    default:
        if (d[0] == 0) {
            func_80067610(1, 0x1FD004E, 0, 0);
            Task_SetState1(t, 5);
        } else if (Item_AddToBag(d[0]) == -1) {
            func_80067610(1, 0x1FD0055, Item_GetNameText(d[0]), 0);
            d[1] = 0xFF;
            Snd_PlayById(0x1C, 0);
        } else {
            func_80067610(1, 0x1FD004D, Item_GetNameText(d[0]), 0);
            Task_SetState1(t, 5);
            Snd_PlayById(0x19, 0);
            Item_SortList();
        }
        Task_NextState2(a0);
        break;
    case 1:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void func_8006A848(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;
    s32 nc = e->field_8 != 4;
    u8 *d = e->field_10;

    switch (a0->stateLevel2) {
    case 0:
    default:
        D_80072B60->field_54 = func_80071294();
        if (D_80072B60->field_54 != 0x10) {
            func_8006E4DC(a0, 0x2C);
            func_80067880(a0, 1);
            func_8007142C(D_80072B60->field_54, d[1]);
        }
        if (nc) {
            Task_SetState1(t, 4);
        }
        ((Stg40ActWork *)a0->work)->field_36 = d[1] + 1;
        Snd_PlayById(0x34, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            func_80071310(nc, D_80072B60->field_54);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
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
void func_8006A9CC(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;
    Stg40ModelFade *m = (Stg40ModelFade *)a0->model;
    s32 v;
    switch (a0->stateLevel2) {
        case 0:
        default:
        {
            u8 k = D_8005071C->field_1;
            if (k == 2) {
                Snd_PlayById(0x23, 0);
                w->field_36 = 0;
            } else {
                if (k == 3)
                    Snd_PlayById(0x18, 0);
                else
                    Snd_PlayById(0x1F, 0);
                w->field_36 = 1;
            }
            m->field_34 = 1;
            m->field_36 = 0x20;
            m->field_38 = D_80063438;
            func_8006E4DC(a0, 0x28);
            e->field_0 |= 0x80;
            w->field_26 = 0;
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

    v = e->field_38 - 0x51;
    if (v < 0) {
        v = 0;
    }
    e->field_38 = v;
    e->field_40 = v;
    if (m->field_38.r != 0xFF) {
        m->field_38.r++;
        m->field_38.g++;
        m->field_38.b++;
    }
}

void func_8006AB48(Actor *a0) {
    Stg40Ent48 *e = D_80072B60->field_40;
    Actor *t = D_80072B60->field_3C;
    s32 k = e->field_8 - 6;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x2A);
        Snd_PlayById(k < 3 ? 0x2D : 0x1E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (func_8006E588(a0) == 1) {
            func_8006E4DC(a0, 0x28);
            if (Item_GetLevel(D_80072B60->field_E0) >= e->field_10[1]) {
                Task_SetState1(t, 6);
                msg = D_8007289C[k * 2];
                Task_SetState2(a0, 3);
            } else {
                msg = D_8007289C[k * 2 + 1];
                Task_NextState2(a0);
            }
            func_80067610(1, msg, 0, 0);
        }
        break;
    case 2:
        if (func_80067704(1) == 1) {
            Task_SetState1(a0, 6);
            D_80072B60->field_7E = Save_GameStatePtr->field_0;
        }
        break;
    case 3:
        if (func_80067704(1) == 1 && e->field_0 == 0) {
            Task_SetState1(a0, 6);
            D_80072B60->field_7E = Save_GameStatePtr->field_0;
        }
        break;
    }
}

void func_8006AD10(void) {
    s32 s3;
    s32 s0;
    s32 s1;
    s32 e1;
    s32 e3;
    s32 v1;
    s32 *dst;
    s32 *p;

    s3 = 0;
    s0 = D_80072B60->field_E2 - D_80072B60->field_E3;
    dst = func_80066E18();
    p = dst;
    if (s0 >= 6) {
        D_80072B60->field_E3 = D_80072B60->field_E2 - 5;
    }
    if (s0 < 0) {
        D_80072B60->field_E3 = D_80072B60->field_E2;
    }
    e1 = D_80072B60->field_E1;
    e3 = D_80072B60->field_E3;
    s1 = e1;
    v1 = e3 + 6;
    if (s1 >= v1) {
        s1 = v1;
    }
    s0 = e3;
    while (s0 < s1) {
        *p = Item_GetNameText(D_80072B60->field_B0[s0]);
        s0++;
        p++;
    }
    s3 |= D_80072B60->field_E3 != 0;
    if (s1 < D_80072B60->field_E1) {
        s3 |= 2;
    }
    func_80066DF0(D_80072B60->field_E2 - D_80072B60->field_E3, s1 - D_80072B60->field_E3, s3);
    dst[6] = Item_GetDescText(D_80072B60->field_B0[D_80072B60->field_E2]);
    s1 = e1;
}

void func_8006AE74(void) {
    s32 old = D_80072B60->field_E2;
    s32 n;

    if (Pad_Repeat & 0x1000) {
        if (old != 0) {
            D_80072B60->field_E2 = old - 1;
        }
    }
    if (Pad_Repeat & 0x4000) {
        n = D_80072B60->field_E2 + 1;
        if (n < D_80072B60->field_E1) {
            D_80072B60->field_E2 = n;
        }
    }
    if (old != D_80072B60->field_E2) {
        Snd_PlayById(D_80072B60->field_E4 ? 0xD : 0xC, 0);
        func_8006AD10();
    }
}

void func_8006AF34(Actor *a0) {
    s32 arg;
    s32 i;
    u16 *bag;

    switch (a0->stateLevel2) {
    case 0:
    default:
        D_80072B60->field_E2 = 0;
        D_80072B60->field_E3 = 0;
        func_8006E4DC(a0, 0x28);
        arg = D_80072B60->field_E4 != 0;
        Task_Create(0x20B, &D_80072AA4->field_10, (s32)&arg);
        Snd_PlayById(0x37, 0);
        func_8006AD10();
        Task_NextState2(a0);
        break;
    case 1:
        if (a0->stateLevel3++ >= 9) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        func_8006AE74();
        if (Pad_State[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 4);
        } else if (Pad_State[0].cross > 0) {
            D_80072B60->field_E0 = D_80072B60->field_B0[D_80072B60->field_E2];
            for (i = 0, bag = Save_GameStatePtr->bagItems; i < 0x30; i++, bag++) {
                if (*bag == D_80072B60->field_E0) {
                    *bag = 0;
                    Item_CompactBag();
                    break;
                }
            }
            if (D_80072B60->field_E4 != 0) {
                func_800651C0(&((Stg40ActWork *)a0->work)->field_2C->field_18, 8);
                Snd_PlayById(0xE, 0);
            } else {
                Snd_PlayById(0xA, 0);
            }
            Task_NextState2(a0);
        }
        if (a0->stateLevel2 != 2) {
            Task_SetState0((Actor *)D_80072AA4->field_10, 2);
        }
        break;
    case 3:
        if (D_80072AA4->field_10 == 0) {
            if (D_80072B60->field_E4 == 0) {
                Task_SetState1(a0, 0x12);
            } else {
                Task_SetState1(a0, 0x1B);
            }
        }
        break;
    case 4:
        if (D_80072AA4->field_10 == 0) {
            if (D_80072B60->field_E4 == 0) {
                Task_SetState1(a0, 1);
                D_80072B60->field_7E = Save_GameStatePtr->field_0;
            } else {
                Task_SetState1(a0, 0x1A);
                Task_SetState2(a0, 2);
                Task_SetState3(a0, 1);
            }
        }
        break;
    }
}

void func_8006B20C(Actor *a0) {
    s32 r;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x30, 1);
        func_8006E4DC(a0, 0x2B);
        break;
    case 1:
        if (func_8006E588(a0) != 1) {
            return;
        }
        func_80067610(1, 0x1FD0054, (s32)Save_GameStatePtr->field_D1, 0);
        break;
    case 2:
        r = func_80067704(1);
        if (r != 1) {
            return;
        }
        D_8005071C->field_1 = 3;
        D_8005071C->field_7 = r;
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

void func_8006B320(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        func_8006E4DC(a0, 0x28);
        D_80072B60->field_178 = 0;
        D_80072B60->field_174 = -1;
        Text_OpenMsgClearChoice(&D_80072B60->field_174, Flag_SelectBranch(D_80072B60->field_170));
        Task_NextState2(a0);
        break;
    case 1:
        if (Text_IsFinished(D_80072B60->field_174)) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        func_80070C48();
        Task_SetState1(a0, 0);
        if (func_8006E330()) {
            Task_SetState1(a0, 4);
        } else {
            D_8005071C->field_2 = 0;
        }
        break;
    }
}

void func_8006B420(Actor *a0) {
    Stg40Ent48 *e;

    func_800708FC(((Stg40ActWork *)a0->work)->field_2C->field_18.u0.pair.field_0, ((Stg40ActWork *)a0->work)->field_2C->field_18.u0.pair.field_2, 1);
    switch (a0->stateLevel1) {
    case 0:
    case 24:
    case 25:
    default:
        func_80068D3C(a0);
        break;
    case 1:
        func_80069188(a0);
        break;
    case 2:
        func_80068DC0(a0);
        break;
    case 3:
        func_80068F20(a0);
        break;
    case 6:
        func_80068FBC(a0);
        break;
    case 7:
        func_80068FFC(a0);
        break;
    case 8:
        func_800690CC(a0);
        break;
    case 4:
        if (a0->stateLevel2 != 1) {
            D_8005071C->field_1 = 1;
            D_8005071C->field_2 = 1;
            Task_NextState2(a0);
        }
        break;
    case 5:
        func_8006932C(a0);
        break;
    case 9:
        func_8006940C(a0);
        break;
    case 10:
        func_800694D0(a0);
        break;
    case 11:
        func_80069514(a0);
        break;
    case 12:
        func_8006955C(a0);
        break;
    case 13:
        func_8006965C(a0);
        break;
    case 14:
        func_80069714(a0);
        break;
    case 15:
        func_80069830(a0);
        break;
    case 16:
        func_8006997C(a0);
        break;
    case 19:
        func_8006A498(a0);
        break;
    case 20:
        func_8006A614(a0);
        break;
    case 21:
        func_8006A6EC(a0);
        break;
    case 22:
        func_8006A848(a0);
        break;
    case 23:
        func_8006A9CC(a0);
        break;
    case 18:
        func_8006AB48(a0);
        break;
    case 17:
        func_8006AF34(a0);
        break;
    case 26:
        func_80069C94(a0);
        break;
    case 27:
        func_80069F84(a0);
        break;
    case 28:
        func_8006B20C(a0);
        break;
    case 30:
        func_8006B320(a0);
        break;
    case 29:
        break;
    }
    e = ((Stg40ActWork *)a0->work)->field_2C;
    func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_18.field_4.field_0, e->field_18.field_4.field_2, e->field_8);
}
