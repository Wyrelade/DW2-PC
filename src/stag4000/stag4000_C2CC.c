#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"
#include "stag4000/stag4000_8338_funcs.h"
#include "stag4000/stag4000_9364_funcs.h"
#include "stag4000/stag4000_A180_funcs.h"

void Stg40_RevealCell(Stg40TileWork *a0, s32 x, s32 y) {
    if (Stg40_GetCellFlags(x, y) & 0x8000) {
        ((Stg40Cell *)D_8005071C->field_E58)[a0->field_766 * y + x].field_0 |= 0x2000;
        Stg40_AutomapSetCell(x, y, 1);
    }
}

void Stg40_AutomapRevealAround(Stg40TileWork *w) {
    s32 x = D_8005071C->field_1068->u0.pair.field_0;
    s32 y = D_8005071C->field_1068->u0.pair.field_2;
    s32 dx = w->field_76C - x;
    s32 dy = w->field_76E - y;

    if (dx == 0 && dy == 0) {
        return;
    }
    Stg40_RevealRoom(w, x, y);
    if (dx > 0) {
        Stg40_RevealCell(w, x - 1, y - 1);
        Stg40_RevealCell(w, x - 1, y);
        Stg40_RevealCell(w, x - 1, y + 1);
    }
    if (dx < 0) {
        Stg40_RevealCell(w, x + 1, y - 1);
        Stg40_RevealCell(w, x + 1, y);
        Stg40_RevealCell(w, x + 1, y + 1);
    }
    if (dy > 0) {
        Stg40_RevealCell(w, x - 1, y - 1);
        Stg40_RevealCell(w, x, y - 1);
        Stg40_RevealCell(w, x + 1, y - 1);
    }
    if (dy < 0) {
        Stg40_RevealCell(w, x - 1, y + 1);
        Stg40_RevealCell(w, x, y + 1);
        Stg40_RevealCell(w, x + 1, y + 1);
    }
    Stg40_RevealCell(w, x, y);
    w->field_76C = D_8005071C->field_1068->u0.pair.field_0;
    w->field_76E = D_8005071C->field_1068->u0.pair.field_2;
}

void Stg40_AutomapDrawWindow(Stg40TileWork *w, s32 x, s32 y, s32 cx, s32 cy, s32 cw, s32 ch, s32 scale, s32 shade) {
    Stg40FT4 a;
    Stg40FT4 b;
    Stg40FT4 *p = (Stg40FT4 *)Sys_State.packet.addr;
    s32 *ot = Sys_State.otLayers.s[1];
    s32 maxX = w->field_766;
    s32 maxY = w->field_768;
    s32 left;
    s32 right;
    s32 top;
    s32 bottom;
    s32 width;
    s32 height;

    cw = (cw - 1) / 2;
    ch = (ch - 1) / 2;
    left = cx - cw;
    if (left < 0) {
        left = 0;
    }
    if (maxX + 1 >= cx + cw + 2) {
        right = cx + cw + 2;
    } else {
        right = maxX + 1;
    }
    top = cy - ch;
    if (top < 0) {
        top = 0;
    }
    if (maxY + 1 >= cy + ch + 2) {
        bottom = cy + ch + 2;
    } else {
        bottom = maxY + 1;
    }
    a.tag.b.len = 9;
    a.code = 0x2C;
    a.r0 = shade;
    a.g0 = shade;
    a.b0 = shade;
    a.tpage = 0x20 | ((w->slot->vramY & 0x100) >> 4) | ((w->slot->vramX & 0x3FF) >> 6) | (((u16)w->slot->vramY & 0x200) << 2);
    a.clut = ((u16)w->clut.y << 6) | (((u16)w->clut.x >> 4) & 0x3F);
    a.code = 0x2E;
    width = right - left;
    height = bottom - top;
    a.u0 = w->slot->uOffset + left + 3;
    a.v0 = top;
    a.u1 = w->slot->uOffset + left + 3 + width;
    a.v1 = top;
    a.u2 = w->slot->uOffset + left + 3;
    a.v2 = top + height;
    a.u3 = w->slot->uOffset + left + 3 + width;
    a.v3 = top + height;
    a.x0 = x + (left - cx) * scale;
    a.y0 = y + (top - cy) * scale;
    a.x1 = x + (right - cx) * scale;
    a.y1 = y + (top - cy) * scale;
    a.x2 = x + (left - cx) * scale;
    a.y2 = y + ((top + height) - cy) * scale;
    a.x3 = x + (right - cx) * scale;
    a.y3 = y + ((top + height) - cy) * scale;
    b = a;
    b.tpage = 0x40 | ((w->slot->vramY & 0x100) >> 4) | ((w->slot->vramX & 0x3FF) >> 6) | (((u16)w->slot->vramY & 0x200) << 2);
    b.clut = (((u16)w->clut.y + 1) << 6) | (((u16)w->clut.x >> 4) & 0x3F);
    *p = a;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((s32)p & 0xFFFFFF);
    p++;
    *p = b;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((s32)p & 0xFFFFFF);
    p++;
    Sys_PacketCursor = (s32)p;
}

void Stg40_AutomapDrawModes(ActorWork *w) {
    Stg40TileWork *t = (Stg40TileWork *)w;
    Stg40Loc *loc;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == D_80072B60->field_7E - 1) {
            t->field_762[i] = (t->field_762[i] + 0x20 < 0x100) ? (u16)t->field_762[i] + 0x20 : 0xFF;
        } else {
            t->field_762[i] = (t->field_762[i] - 0x20 >= 0) ? (u16)t->field_762[i] - 0x20 : 0;
        }
        if (t->field_762[i] != 0) {
            switch (i) {
            case 0:
                loc = D_8005071C->field_1068;
                Stg40_AutomapDrawWindow(t, 0x50, 0, loc->u0.pair.field_0, loc->u0.pair.field_2, 0x11, 0x11, 3, t->field_762[0]);
                break;
            case 1:
                Stg40_AutomapDrawWindow(t, 0, 0, 0x20, 0x18, 0x41, 0x31, 4, t->field_762[1]);
                break;
            }
        }
    }
}

void Stg40_AutomapInit(void) {
}

void Stg40_AutomapUpdate(Actor *a0) {
    Stg40TileWork *w = (Stg40TileWork *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Stg40_AutomapWork = (Stg40TileGrid *)w;
        Stg40_AutomapInitDims(w);
        Stg40_AutomapInitTex(w);
        Stg40_AutomapRedraw(w);
        Stg40_AutomapFlush(w);
        D_80072B60->field_7E = 0;
        Task_NextState0(a0);
        break;
    case 1:
        Stg40_AutomapRevealAround(w);
        Stg40_AutomapFlush(w);
        Stg40_AutomapCycleClut((Stg40ImgWork *)w);
        break;
    case 2:
        break;
    }
}

void Stg40_AutomapDestroy(Actor *a0) {
    Stg40_AutomapReleaseTex((Stg40ImgWork *)a0->work);
    Task_DefaultDestroy(a0);
}

void Stg40_AutomapDraw(Actor *a0) {
    ActorWork *w = a0->work;

    if (Beetle_GetPart(0x12) <= 0) {
        D_80072B60->field_7E = 0;
    }
    Stg40_AutomapDrawModes(w);
}

void Stg40_AllocCellGrid(void) {
    Stg40E34 *d = D_8005071C->field_E54;

    D_8005071C->field_E58 = (ActorWork *)Mem_Alloc(d->field_0 * (d->field_2 << 2), 2);
}

void Stg40_FreeCellGrid(void) {
    Mem_Free(D_8005071C->field_E58);
}

u16 Stg40_ReadFloorBits(u16 *pal, u32 *bits, s32 x, s32 y) {
    s32 w = D_8005071C->field_E54->field_0 / 8;

    return pal[(bits[w * y + x / 8] >> ((x % 8) * 4)) & 0xF];
}

void Stg40_FillCellGrid(void) {
    Stg40Blk5071C *g = D_8005071C;
    Stg40Cell *cell;
    Stg40E34 *dims;
    Stg40Map *map;
    Stg40MapRoom *room;
    u32 *bits;
    s32 cols;
    s32 rows;
    s32 lastX;
    s32 x;
    s32 y;
    u16 up;
    u16 down;
    u16 left;
    u16 right;
    u16 v;

    cell = (Stg40Cell *)g->field_E58;
    map = (Stg40Map *)D_80072B60->field_10;
    dims = g->field_E54;
    cols = dims->field_0;
    rows = dims->field_2;
    room = D_80072B60->field_14;
    bits = room->field_0;
    Stg40_FloorBitsPal[7] = D_800729B4[map->field_2C];
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            v = Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x, y);
            if (v == 0) {
                cell->field_0 = 0;
                cell->field_2 = 0xFF;
                cell->field_3 = 0;
            } else {
                cell->field_0 = v | 0x8000;
                cell->field_0 |= (v != 1) ? 0x4000 : 0;
                if (y == 0 || (y > 0 && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x, y - 1))) {
                    cell->field_0 |= 0x800;
                }
                if (y == rows - 1 || (y < rows - 1 && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x, y + 1))) {
                    cell->field_0 |= 0x400;
                }
                if (x == 0 || (x > 0 && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x - 1, y))) {
                    cell->field_0 |= 0x200;
                }
                lastX = cols - 1;
                if (x == lastX || (x < lastX && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x + 1, y))) {
                    cell->field_0 |= 0x100;
                }
            }
            cell->field_2 = 0xFF;
            cell->field_3 = 0;
            cell++;
        }
    }

    cell = (Stg40Cell *)D_8005071C->field_E58;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            if (cell->field_0 & 0xF) {
                up = Stg40_GetCellFlags(x, y - 1);
                down = Stg40_GetCellFlags(x, y + 1);
                left = Stg40_GetCellFlags(x - 1, y);
                right = Stg40_GetCellFlags(x + 1, y);
                if (cell->field_0 & 0x800) {
                    cell->field_3 |= (left & 0x800) ? 0 : 1;
                    cell->field_3 |= (right & 0x800) ? 0 : 2;
                }
                if (cell->field_0 & 0x400) {
                    cell->field_3 |= (right & 0x400) ? 0 : 4;
                    cell->field_3 |= (left & 0x400) ? 0 : 8;
                }
                if (cell->field_0 & 0x200) {
                    cell->field_3 |= (down & 0x200) ? 0 : 0x10;
                    cell->field_3 |= (up & 0x200) ? 0 : 0x20;
                }
                if (cell->field_0 & 0x100) {
                    cell->field_3 |= (up & 0x100) ? 0 : 0x40;
                    cell->field_3 |= (down & 0x100) ? 0 : 0x80;
                }
                if (!(Stg40_GetCellFlags(x - 1, y - 1) & 0xF)) {
                    cell->field_0 |= 0x80;
                }
            }
            cell++;
        }
    }
}

u16 Stg40_GetCellFlags(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    Stg40Cell *cells = (Stg40Cell *)b->field_E58;
    s32 w = d->field_0;
    s32 h = d->field_2;
    u16 r = 0;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = cells[w * y + x].field_0;
    }
    return r;
}

Stg40Cell *Stg40_GetCell(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->field_E58)[w * y + x];
    }
    return r;
}

void Stg40_FloodFillRoom(s32 buf, s32 p1, s32 x, s32 y, s32 fill)
{
    Stg40Cell *grid = (Stg40Cell *)D_8005071C->field_E58;
    s32 width = D_8005071C->field_E54->field_0;
    s32 maxRun = 0;
    s32 count;
    s32 k;
    s32 nx;
    s32 ny;
    s32 r;

    if (!(Stg40_GetCellFlags(x, y) & 0x4000)) {
        return;
    }
    count = 1;
    ((Stg40FillPt *)buf)[0].x = x;
    ((Stg40FillPt *)buf)[0].y = y;
    grid[width * y + x].field_0 |= fill;
    do {
        if (maxRun < count) {
            maxRun = count;
        }
        count--;
        x = ((Stg40FillPt *)buf)[count].x;
        y = ((Stg40FillPt *)buf)[count].y;
        for (k = 0; k < 4; k++) {
            nx = Stg40_FillNeighbours[k * 2] + x;
            ny = Stg40_FillNeighbours[k * 2 + 1] + y;
            r = Stg40_GetCellFlags(nx, ny);
            if ((r & (fill | 0x8000)) != 0x8000) {
                continue;
            }
            if (p1 != 0) {
                grid[width * ny + nx].field_0 |= fill;
            }
            if (!(r & 0x4000)) {
                continue;
            }
            grid[width * ny + nx].field_0 |= fill;
            ((Stg40FillPt *)buf)[count].x = nx;
            ((Stg40FillPt *)buf)[count].y = ny;
            count++;
        }
    } while (count != 0);
}

s32 Stg40_FindUnlabeledRoom(void) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Cell *c = (Stg40Cell *)b->field_E58;
    s32 h = b->field_E54->field_2;
    s32 w = b->field_E54->field_0;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++, c++) {
            if ((c->field_0 & 0x4000) && c->field_2 == 0xFF) {
                return y * w + x;
            }
        }
    }
    return -1;
}

void Stg40_LabelFilledCells(void) {
    Stg40Blk5071C *b = D_8005071C;
    s32 n = b->field_E54->field_0 * b->field_E54->field_2;
    u8 v = D_80072B60->field_0;
    Stg40Cell *c = (Stg40Cell *)b->field_E58;
    s32 i;

    for (i = 0; i < n; i++, c++) {
        if (c->field_0 & 0x2000) {
            c->field_2 = v;
            c->field_0 &= ~0x2000;
        }
    }
}

void Stg40_LabelRooms(void) {
    s32 w = D_8005071C->field_E54->field_0;
    s32 buf = Mem_Alloc(0x3FF8, 2);
    s32 i;

    D_80072B60->field_0 = 0;
    while ((D_80072BB8 = i = Stg40_FindUnlabeledRoom()) != -1) {
        Stg40_FloodFillRoom(buf, 0, i % w, i / w, 0x2000);
        Stg40_LabelFilledCells();
        D_80072B60->field_0++;
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Cell *Stg40_GetCell2(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->field_E58)[w * y + x];
    }
    return r;
}

void Stg40_SetCellOccupied(s32 x, s32 y, s32 flag) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->field_E58;
        c[w * y + x].field_0 |= flag == 0 ? 0x40 : 0x60;
    }
}

void Stg40_ClearCellOccupied(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->field_E58;
        c[w * y + x].field_0 &= ~0x60;
    }
}

void Stg40_ApplyTrapCells(void) {
    Stg40Rec3 *r = D_8005071C->field_D08;
    Stg40Cell *c;
    s32 i;

    for (i = 0; i < D_8005071C->field_14; r++, i++) {
        c = Stg40_GetCell2(r->field_0, r->field_1);
        c->field_0 &= 0xFFF0;
        c->field_0 |= r->field_2 + 7;
    }
}

void Stg40_TurnQueueReset(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;
    s16 *q = p->field_0;
    s32 i;

    p->field_18 = 10;
    p->field_16 = 0;
    p->field_1A = 0;
    for (i = 0; i < p->field_18; i++) {
        *q++ = -1;
    }
    *q = -2;
}

s16 *Stg40_TurnQueueFind(s16 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;
    s16 *p = f->field_0;

    while (*p != -2) {
        if (*p == v) {
            return p;
        }
        p++;
    }
    return NULL;
}

void Stg40_TurnQueueAdd(s32 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;

    if (Stg40_TurnQueueFind(v) == NULL && f->field_16 < f->field_18) {
        f->field_0[f->field_16] = v;
        f->field_16++;
    }
}

void Stg40_TurnQueueRemove(s16 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;
    s16 *p = Stg40_TurnQueueFind(v);
    s16 *q;

    if (p != NULL) {
        for (q = p + 1; *q != -2;) {
            *p++ = *q++;
        }
        *p = -1;
        f->field_16--;
        if (f->field_0[f->field_1A] == -1) {
            f->field_1A = 0;
        }
    }
}

s16 Stg40_TurnQueueNext(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    p->field_1A = (p->field_1A + 1 < p->field_16) ? p->field_1A + 1 : 0;
    return p->field_0[p->field_1A];
}

s16 Stg40_TurnQueueCurrent(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    return p->field_0[p->field_1A];
}

void Stg40_LoadDungFile(s32 id) {
    s32 *p;

    p = (s32 *)Cd_GetFileOrNull(id);
    Stg40_RelocDungFile(p);
    D_80072B60->field_1C = id;
    D_80072B60->field_C = p;
    D_80072B60->field_10 = p[D_8005071C->field_3];
    D_80072B60->field_18 = 0;
    while (D_80072B60->field_C[D_80072B60->field_18] != 0) {
        D_80072B60->field_18++;
    }
}

void Stg40_PickFloorLayout(void) {
    s32 i;

    D_8005071C->field_4 = Stg40_RandInt(8);
    for (i = 7; i >= 0; i--) {
        D_8005071C->field_E5C[i] = 0;
    }
}

void Stg40_ApplyFloorLayout(void) {
    Stg40B60 *b = D_80072B60;
    Stg40Blk5071C *g = D_8005071C;
    Stg40Map *m = (Stg40Map *)b->field_10;
    u8 *src;
    u8 *dst;

    b->field_14 = m->field_8[g->field_4];
    g->field_E54->field_A = m->field_28;
    g->field_E54->field_4 = 1;
    g->field_E54->field_C = m->field_2E;
    src = m->field_0;
    dst = D_8005071C->field_E54->field_E;
    memset(dst, 0xFF, 16);
    D_8005071C->field_E54->field_D = 0;
    while (*src != 0xFF) {
        *dst = *src;
        D_8005071C->field_E54->field_D++;
        src++;
        dst++;
    }
}

void Stg40_RelocPtr(u32 *p, u32 n) {
    if (*p < n) {
        *p += n;
    }
}

s32 Stg40_RelocDungFile(s32 *p) {
    u32 *tbl = (u32 *)p;
    u32 base = (u32)p;
    s32 n = 0;
    s32 i;
    Stg40MapRel *m;
    Stg40MapRoomRel *r;
    u32 *q;

    while (*tbl != 0) {
        if (*tbl < base) {
            *tbl += base;
            m = (Stg40MapRel *)*tbl;
            m->field_0 += base;
            for (i = 0; i < 8; i++) {
                q = &m->field_8[i];
                *q += base;
                r = (Stg40MapRoomRel *)*q;
                Stg40_RelocPtr(&r->field_0[0], base);
                Stg40_RelocPtr(&r->field_0[1], base);
                Stg40_RelocPtr(&r->field_0[2], base);
                Stg40_RelocPtr(&r->field_0[3], base);
                Stg40_RelocPtr(&r->field_0[4], base);
            }
        }
        tbl++;
        n++;
    }
    return n;
}

s32 Stg40_PickRandomPoint(Stg40Pick *out, Stg40Rec3 *e, u8 key) {
    s32 r = -1;
    s32 n = 0;

    for (; e->field_0 != 0xFF; e++) {
        if (e->field_2 == key) {
            out->field_0 = e->field_0;
            out->field_2 = e->field_1;
            n++;
            out++;
        }
    }
    if (n != 0) {
        r = Stg40_RandInt(n);
    }
    return r;
}

void Stg40_PickSpawnPoints(void) {
    Stg40Pick buf[20];
    Stg40Rec3 *list = D_80072B60->field_14->field_4;
    s32 r;

    r = Stg40_PickRandomPoint(buf, list, 0);
    D_80072B60->field_20.field_0 = buf[r].field_0;
    D_80072B60->field_20.field_2 = buf[r].field_2;
    r = Stg40_PickRandomPoint(buf, list, 1);
    D_80072B60->field_24.field_2 = -1;
    D_80072B60->field_24.field_0 = -1;
    if (r != -1) {
        D_80072B60->field_24.field_0 = buf[r].field_0;
        D_80072B60->field_24.field_2 = buf[r].field_2;
    }
    r = Stg40_PickRandomPoint(buf, list, 2);
    D_80072B60->field_28.field_2 = -1;
    D_80072B60->field_28.field_0 = -1;
    if (r != -1) {
        D_80072B60->field_28.field_0 = buf[r].field_0;
        D_80072B60->field_28.field_2 = buf[r].field_2;
    }
}

s32 Stg40_RandPercent(void) {
    return (Rand_Next() & 0xFFF) * 100 / 4096;
}

s32 Stg40_RandInt(s32 n) {
    return (Rand_Next() & 0xFFF) * n / 4096;
}

s32 Stg40_GetTrapDisarmRank(s32 i) {
    s32 r = Stg40_GetPartLevel(7);
    r = r < 0 ? 0 : r;
    return Stg40_TrapDisarmRanks[r][i];
}

s32 Stg40_RollTrapDisarm(s32 i) {
    return Stg40_RandPercent() < Stg40_TrapDisarmChance[i];
}

s32 Stg40_RollTrapEffect(void) {
    s32 r = Stg40_TrapEffectTable[Stg40_RandPercent() / 4];

    if (r >= 4 && r < 16) {
        if (Stg40_GetBeetlePart(Stg40_TrapPartSlots[r - 4]) <= 0) {
            r = 16;
        }
    }
    return r;
}

void Stg40_ShowTrapEffectMsg(s32 a0, s32 a1) {
    s32 base = 0x1FD0011;

    if (a0 == 0) {
        base = 0x1FD0047;
    }
    switch (a1) {
    case 0:
        Stg40_MsgWinOpen(1, base, (s32)Save_GameStatePtr->field_D1, (s32)Stg40_NumToDigits(0, D_80072B60->field_58));
        break;
    case 1:
        Stg40_MsgWinOpen(1, base + 1, (s32)Stg40_NumToDigits(0, D_80072B60->field_58), 0);
        break;
    case 2:
    case 3:
        Stg40_MsgWinOpen(1, base + a1, 0, 0);
        break;
    case 16:
        Stg40_MsgWinOpen(1, base + 5, 0, 0);
        break;
    default:
        {
            s32 k = Stg40_TrapPartSlots[a1 - 4];
            Stg40_MsgWinOpen(1, base + 4, Item_GetNameText(Save_GameStatePtr->slotItems[k]), 0);
        }
        break;
    }
}

void Stg40_ApplyTrapEffect(s32 a0, s32 a1) {
    s32 i;
    s32 k;
    DigiRosterEntry *r;
    Stg40Blk5071C *g;

    switch (a0) {
    case 0:
        D_80072B60->field_58 = a1 * 400;
        Stg40_DamageBeetle(D_80072B60->field_58);
        break;
    case 1:
        D_80072B60->field_58 = a1 * 10;
        Stg40_ListPartyDigi(3);
        for (i = 0; i < D_80072B60->field_140; i++) {
            r = &Save_GameStatePtr->elems[D_80072B60->field_128[i]];
            r->hp = ((s16)r->hp - D_80072B60->field_58 > 0) ? (u16)r->hp - (u16)D_80072B60->field_58 : 1;
        }
        break;
    case 2:
        D_8005071C->field_BA0 = (D_8005071C->field_BA0 | 2) & ~0x80;
        D_8005071C->field_BA4 = Stg40_RandInt(4) + 1;
        break;
    case 3:
        g = D_8005071C;
        g->field_BB5 = 0;
        g->field_BA0 = (g->field_BA0 | 1) & ~0x40;
        break;
    default:
        k = Stg40_TrapPartSlots[a0 - 4];
        Save_GameStatePtr->slotStatus[k] = 1;
        break;
    case 16:
        break;
    }
}

s32 Stg40_GetPartState(void) {
    s32 r = Stg40_GetBeetlePart();

    if (r > 0) {
        r = 1;
    }
    return r;
}

s32 Stg40_PickRandomPart(void) {
    u8 buf[16];
    s32 n = 0;
    s32 r = -1;
    u32 i;

    for (i = 0; i < 12; i++) {
        if (Beetle_GetPart(Stg40_RandomPartSlots[i]) > 0) {
            buf[n++] = Stg40_RandomPartSlots[i];
        }
    }
    if (n != 0) {
        r = Stg40_RandPercent() / (100 / n);
        r = buf[r > n - 1 ? n - 1 : r];
    }
    return r;
}

s32 Stg40_TickStatusEffects(Actor *a0) {
    Stg40BA0View *st;
    u8 *stack;
    u8 *p;
    s16 *count;
    s32 sfx;
    s32 i;
    s32 slot;
    s32 n;
    s32 r;
    DigiRosterEntry *ent;

    sfx = 0;
    st = (Stg40BA0View *)&D_8005071C->field_BA0;
    stack = D_80072B60->field_60;
    count = &D_80072B60->field_68;
    p = &stack[7];
    for (i = 7; i >= 0; i--) {
        *p-- = 0;
    }
    *count = 0;
    if (st->field_0 & 1) {
        if (++st->field_15 >= 3 || (Stg40_RandPercent() < 50 && (st->field_0 & 0x40))) {
            st->field_0 &= ~1;
            stack[(*count)++] = 0;
        }
        st->field_0 |= 0x40;
    }
    if (st->field_0 & 2) {
        if (Stg40_RandPercent() < 10 && (st->field_0 & 0x80)) {
            st->field_0 &= ~2;
            stack[(*count)++] = 1;
        }
        st->field_0 |= 0x80;
    }
    if (D_8005071C->field_BA5 != 0) {
        slot = Stg40_PickRandomPart();
        if ((Stg40_RandPercent() < 5 && (st->field_0 & 0x100)) || (Save_GameStatePtr->bits == 0 && slot == -1)) {
            stack[(*count)++] = 2;
            D_8005071C->field_BA5 = 0;
        } else {
            if (Save_GameStatePtr->bits != 0) {
                s32 cost[4] = { 0, 20, 50, 100 };
                s32 v = Save_GameStatePtr->bits -= cost[st->field_5];
                if (v < 0) {
                    v = 0;
                }
                Save_GameStatePtr->bits = v;
                sfx = 4;
            } else {
                Beetle_SetPartBroken(slot, 1);
                stack[(*count)++] = 6;
                sfx = 3;
                D_80072B60->field_78 = Item_GetNameText(Save_GameStatePtr->slotItems[slot]);
            }
            Stg40_ObjStartFlash(a0, 2);
        }
        st->field_0 |= 0x100;
    }
    if (D_8005071C->field_BA6 != 0) {
        if (Stg40_RandPercent() < 2 && (st->field_0 & 0x200)) {
            stack[(*count)++] = 3;
            D_8005071C->field_BA6 = 0;
        } else {
            s32 cost[4] = { 0, 2, 4, 6 };
            s16 v = Save_GameStatePtr->mp - cost[st->field_6];
            Save_GameStatePtr->mp = v;
            if (v < 0) {
                v = 0;
            }
            Save_GameStatePtr->mp = v;
            Stg40_ObjStartFlash(a0, 2);
            sfx = 2;
        }
        st->field_0 |= 0x200;
    }
    if (D_8005071C->field_BA7 != 0) {
        s32 chance[4] = { 0, 50, 40, 30 };
        n = ((s32 (*)(s32))Stg40_ListPartyDigi)(1);
        if ((Stg40_RandPercent() < chance[st->field_7] && (st->field_0 & 0x400)) || n < 2 ||
            Digi_CountByState(1) >= 24) {
            stack[(*count)++] = 4;
            D_8005071C->field_BA7 = 0;
        } else {
            n = ((s32 (*)(s32))Stg40_ListPartyDigi)(0);
            r = Stg40_RandPercent() / (100 / n);
            if (r > n - 1) {
                r = n - 1;
            }
            ent = &Save_GameStatePtr->elems[D_80072B60->field_128[r]];
            ent->state = 1;
            *(Stg40Agg14 *)D_80072B60->field_6A = *(Stg40Agg14 *)ent->name;
            Digi_SortRoster();
            for (i = 0; i < 3; i++) {
                if (Save_GameStatePtr->elems[i].state < 2) {
                    break;
                }
                Save_GameStatePtr->elems[i].state = i + 3;
            }
            stack[(*count)++] = 7;
            Stg40_ObjStartFlash(a0, 2);
            sfx = 1;
        }
        st->field_0 |= 0x400;
    }
    if (D_8005071C->field_BA8 != 0) {
        st->field_0 |= 0x800;
    }
    switch (sfx) {
    case 1:
        Snd_PlayById(3, 0);
        break;
    case 2:
        Snd_PlayById(7, 0);
        break;
    case 3:
        Snd_PlayById(6, 0);
        break;
    case 4:
        Snd_PlayById(8, 0);
        break;
    }
    return D_80072B60->field_68;
}

void Stg40_RollObjectReveal(void) {
    Stg40Ent48 *e = D_8005071C->field_18;
    s32 a;
    s32 b;
    s32 i;
    s32 v;

    a = Stg40_GetPartLevel(13);
    a = a < 0 ? 0 : a;
    b = Stg40_GetPartLevel(14);
    b = b < 0 ? 0 : b;
    for (i = 0; i < D_8005071C->field_C; e++, i++) {
        if (e->field_0 & 0x8000) {
            switch (e->field_8) {
            case 6:
            case 8:
                v = D_80072A58[e->field_10[1] - 1 + a * 5];
                if (Stg40_RandPercent() < v) {
                    e->field_0 |= 0x1000;
                }
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                v = D_80072A78[e->field_10[1] - 1 + b * 3];
                if (Stg40_RandPercent() < v) {
                    e->field_0 |= 0x1000;
                }
                break;
            }
        }
    }
}

Stg40Ent48 *Stg40_FindEntByDigiId(s32 id) {
    Stg40Ent48 *e;
    s32 i;

    for (i = 0, e = D_8005071C->field_18; i < 41; i++, e++) {
        if (e->field_0 & 0x8000) {
            if ((id != 0 && id == e->field_4) || (id == 0 && (e->field_0 & 1))) {
                return e;
            }
        }
    }
    return NULL;
}

void Stg40_TextObjCommand(s32 *arg) {
    Stg40Ent48 *e;
    Actor *t;
    s32 st;

    st = -1;
    D_80072B60->field_178 = *arg++;
    D_80072B60->field_17C.field_0 = arg[0] - 1;
    D_80072B60->field_17C.field_2 = arg[1] - 1;
    D_80072B60->field_180 = 0;
    D_80072B60->field_184 = NULL;
    e = Stg40_FindEntByDigiId(D_80072B60->field_178);
    if (e != NULL) {
        t = e->field_14;
        D_80072B60->field_180 = 1;
        switch (D_80072B60->field_17C.field_0) {
        default:
            st = 5;
            break;
        case 0x62:
            if (D_80072B60->field_17C.field_2 == -1) {
                st = 4;
                D_80072B60->field_184 = t;
            } else {
                st = 6;
                D_80072B60->field_180 = 0;
            }
            break;
        case 0x61:
            e->field_E = (D_80072B60->field_17C.field_2 << 12) / 360;
            D_80072B60->field_180 = 0;
            break;
        case 0x60:
            e->field_0 |= 0x200;
            D_80072B60->field_180 = 0;
            break;
        }
        if (st != -1) {
            Task_SetState1(t, (u8)st);
        }
    }
}

void Stg40_EndTextObjCmd(void) {
    D_80072B60->field_180 = 0;
}

s16 Stg40_IsTextObjCmdBusy(void) {
    return D_80072B60->field_180;
}

s32 Stg40_CamIsMoving(void) {
    return Stg40_CameraTask->stateLevel1;
}

void Stg40_CamStartMove(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3) {
    Actor *t = Stg40_CameraTask;
    Stg40BC0Work *w = (Stg40BC0Work *)t->work;

    w->field_88 = *blk;
    w->field_A8 = a1;
    w->field_AC = a2;
    w->field_B0 = a3;
    Task_SetState1(t, 1);
}

void Stg40_CamLoadScript(Stg40Cmd *src) {
    Stg40BC0Work *w = (Stg40BC0Work *)Stg40_CameraTask->work;
    s32 i;

    w->field_B4 = w->field_BC;
    w->field_B8 = 0;
    for (i = 0; src->field_0 != 0; i++, src++) {
        w->field_BC[i] = *src;
        w->field_B8++;
    }
}

void Stg40_CamNextCommand(Actor *a0) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;
    Stg40Cmd *c;

    if (w->field_B8 != 0) {
        c = w->field_B4;
        Stg40_CamStartMove(&c->field_C, c->field_0, c->field_4, c->field_8);
        w->field_B8--;
        w->field_B4++;
    }
}

void Stg40_CamMoveStep(Actor *task) {
    Stg40BC0Work *w = (Stg40BC0Work *)task->work;
    s32 dx;
    s32 x0;
    s32 y0;
    s32 z0;

    if (task->stateLevel2 >= w->field_A8) {
        do {
            w->field_0.words[0] = w->field_88.words[4];
            w->field_0.words[1] = w->field_88.words[5];
            w->field_0.words[2] = w->field_88.words[6];
            w->field_7C[1] = (u16)w->field_AC;
            if (w->field_B8 != 0) {
                Stg40_CamNextCommand(task);
            } else {
                Task_SetState1(task, 0);
            }
        } while (0);
        return;
    }
    x0 = w->field_88.words[0];
    dx = (x0 - w->field_88.words[4]) / w->field_A8;
    y0 = w->field_88.words[1];
    z0 = w->field_88.words[2];
    w->field_0.words[0] = x0 - dx * task->stateLevel2;
    w->field_0.words[1] = y0 - ((y0 - w->field_88.words[5]) / w->field_A8) * task->stateLevel2;
    w->field_0.words[2] = z0 - ((z0 - w->field_88.words[6]) / w->field_A8) * task->stateLevel2;
    w->field_84 = 1;
    w->field_7C[1] = (u16)w->field_AC + (w->field_B0 / w->field_A8) * (w->field_A8 - task->stateLevel2);
    task->stateLevel2 = task->stateLevel2 + 1;
}

void Stg40_CameraInit(Actor *a0, Block1C *a1) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;

    Stg40_CameraTask = a0;
    w->field_0 = *a1;
    w->field_B4 = 0;
    w->field_B8 = 0;
}

void Stg40_CameraUpdate(Actor *a0) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;
    Stg40RView v;

    switch (a0->stateLevel0) {
    case 0:
    default:
        GsInitCoordinate2(0, &w->field_1C);
        w->field_84 = 1;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->field_B8 != 0) {
                Stg40_CamNextCommand(a0);
            }
            break;
        case 1:
            Stg40_CamMoveStep(a0);
            break;
        }
        w->field_84 = 0;
        RotMatrixYXZ(w->field_7C, &w->field_1C.coord);
        w->field_1C.coord.t[0] = w->field_6C;
        w->field_1C.coord.t[1] = w->field_70;
        w->field_1C.coord.t[2] = w->field_74;
        w->field_1C.flg = 0;
        v.field_0[0] = w->field_0.words[0];
        v.field_0[1] = w->field_0.words[1];
        v.field_0[2] = w->field_0.words[2];
        v.field_0[3] = w->field_0.words[3];
        v.field_0[4] = w->field_0.words[4];
        v.field_0[5] = w->field_0.words[5];
        v.field_18 = 0;
        v.field_1C = &w->field_1C;
        GsSetProjection(w->field_0.words[6]);
        GsSetRefView2(&v);
        break;
    case 2:
        break;
    }
}

void Stg40_CameraDraw(void) {
}
