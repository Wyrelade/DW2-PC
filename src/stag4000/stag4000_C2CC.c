#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"
#include "stag4000/stag4000_8338_funcs.h"
#include "stag4000/stag4000_9364_funcs.h"
#include "stag4000/stag4000_A180_funcs.h"

void Stg40_RevealCell(Stg40AutomapWork *a0, s32 x, s32 y) {
    if (Stg40_GetCellFlags(x, y) & 0x8000) {
        ((Stg40Cell *)Dung_StatePtr->cells)[a0->cols * y + x].flags |= 0x2000;
        Stg40_AutomapSetCell(x, y, 1);
    }
}

void Stg40_AutomapRevealAround(Stg40AutomapWork *w) {
    s32 x = Dung_StatePtr->playerLoc->u0.pair.field_0;
    s32 y = Dung_StatePtr->playerLoc->u0.pair.field_2;
    s32 dx = w->lastPlayerX - x;
    s32 dy = w->lastPlayerY - y;

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
    w->lastPlayerX = Dung_StatePtr->playerLoc->u0.pair.field_0;
    w->lastPlayerY = Dung_StatePtr->playerLoc->u0.pair.field_2;
}

void Stg40_AutomapDrawWindow(Stg40AutomapWork *w, s32 x, s32 y, s32 cx, s32 cy, s32 cw, s32 ch, s32 scale, s32 shade) {
    Stg40FT4 a;
    Stg40FT4 b;
    Stg40FT4 *p = (Stg40FT4 *)Sys_State.packet.addr;
    s32 *ot = Sys_State.otLayers.s[1];
    s32 maxX = w->cols;
    s32 maxY = w->rows;
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
    Stg40AutomapWork *t = (Stg40AutomapWork *)w;
    Stg40Loc *loc;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == Stg40_RootState->automapMode - 1) {
            t->modeFade[i] = (t->modeFade[i] + 0x20 < 0x100) ? (u16)t->modeFade[i] + 0x20 : 0xFF;
        } else {
            t->modeFade[i] = (t->modeFade[i] - 0x20 >= 0) ? (u16)t->modeFade[i] - 0x20 : 0;
        }
        if (t->modeFade[i] != 0) {
            switch (i) {
            case 0:
                loc = Dung_StatePtr->playerLoc;
                Stg40_AutomapDrawWindow(t, 0x50, 0, loc->u0.pair.field_0, loc->u0.pair.field_2, 0x11, 0x11, 3, t->modeFade[0]);
                break;
            case 1:
                Stg40_AutomapDrawWindow(t, 0, 0, 0x20, 0x18, 0x41, 0x31, 4, t->modeFade[1]);
                break;
            }
        }
    }
}

void Stg40_AutomapInit(void) {
}

void Stg40_AutomapUpdate(Actor *a0) {
    Stg40AutomapWork *w = (Stg40AutomapWork *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Stg40_AutomapWork = (Stg40TileGrid *)w;
        Stg40_AutomapInitDims(w);
        Stg40_AutomapInitTex(w);
        Stg40_AutomapRedraw(w);
        Stg40_AutomapFlush(w);
        Stg40_RootState->automapMode = 0;
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
        Stg40_RootState->automapMode = 0;
    }
    Stg40_AutomapDrawModes(w);
}

void Stg40_AllocCellGrid(void) {
    Stg40FloorHeader *d = Dung_StatePtr->floorHdr;

    Dung_StatePtr->cells = (ActorWork *)Mem_Alloc(d->cols * (d->rows << 2), 2);
}

void Stg40_FreeCellGrid(void) {
    Mem_Free(Dung_StatePtr->cells);
}

u16 Stg40_ReadFloorBits(u16 *pal, u32 *bits, s32 x, s32 y) {
    s32 w = Dung_StatePtr->floorHdr->cols / 8;

    return pal[(bits[w * y + x / 8] >> ((x % 8) * 4)) & 0xF];
}

void Stg40_FillCellGrid(void) {
    Stg40DungState *g = Dung_StatePtr;
    Stg40Cell *cell;
    Stg40FloorHeader *dims;
    Stg40DungFloor *map;
    Stg40DungLayout *room;
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

    cell = (Stg40Cell *)g->cells;
    map = (Stg40DungFloor *)Stg40_RootState->floorMap;
    dims = g->floorHdr;
    cols = dims->cols;
    rows = dims->rows;
    room = Stg40_RootState->layout;
    bits = room->cellBits;
    Stg40_FloorBitsPal[7] = Stg40_SpecialFloorValues[map->paletteIdx];
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            v = Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x, y);
            if (v == 0) {
                cell->flags = 0;
                cell->roomId = 0xFF;
                cell->wallBits = 0;
            } else {
                cell->flags = v | 0x8000;
                cell->flags |= (v != 1) ? 0x4000 : 0;
                if (y == 0 || (y > 0 && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x, y - 1))) {
                    cell->flags |= 0x800;
                }
                if (y == rows - 1 || (y < rows - 1 && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x, y + 1))) {
                    cell->flags |= 0x400;
                }
                if (x == 0 || (x > 0 && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x - 1, y))) {
                    cell->flags |= 0x200;
                }
                lastX = cols - 1;
                if (x == lastX || (x < lastX && !Stg40_ReadFloorBits(Stg40_FloorBitsPal, bits, x + 1, y))) {
                    cell->flags |= 0x100;
                }
            }
            cell->roomId = 0xFF;
            cell->wallBits = 0;
            cell++;
        }
    }

    cell = (Stg40Cell *)Dung_StatePtr->cells;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            if (cell->flags & 0xF) {
                up = Stg40_GetCellFlags(x, y - 1);
                down = Stg40_GetCellFlags(x, y + 1);
                left = Stg40_GetCellFlags(x - 1, y);
                right = Stg40_GetCellFlags(x + 1, y);
                if (cell->flags & 0x800) {
                    cell->wallBits |= (left & 0x800) ? 0 : 1;
                    cell->wallBits |= (right & 0x800) ? 0 : 2;
                }
                if (cell->flags & 0x400) {
                    cell->wallBits |= (right & 0x400) ? 0 : 4;
                    cell->wallBits |= (left & 0x400) ? 0 : 8;
                }
                if (cell->flags & 0x200) {
                    cell->wallBits |= (down & 0x200) ? 0 : 0x10;
                    cell->wallBits |= (up & 0x200) ? 0 : 0x20;
                }
                if (cell->flags & 0x100) {
                    cell->wallBits |= (up & 0x100) ? 0 : 0x40;
                    cell->wallBits |= (down & 0x100) ? 0 : 0x80;
                }
                if (!(Stg40_GetCellFlags(x - 1, y - 1) & 0xF)) {
                    cell->flags |= 0x80;
                }
            }
            cell++;
        }
    }
}

u16 Stg40_GetCellFlags(s32 x, s32 y) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40FloorHeader *d = b->floorHdr;
    Stg40Cell *cells = (Stg40Cell *)b->cells;
    s32 w = d->cols;
    s32 h = d->rows;
    u16 r = 0;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = cells[w * y + x].flags;
    }
    return r;
}

Stg40Cell *Stg40_GetCell(s32 x, s32 y) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40FloorHeader *d = b->floorHdr;
    s32 w = d->cols;
    s32 h = d->rows;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->cells)[w * y + x];
    }
    return r;
}

void Stg40_FloodFillRoom(s32 buf, s32 p1, s32 x, s32 y, s32 fill)
{
    Stg40Cell *grid = (Stg40Cell *)Dung_StatePtr->cells;
    s32 width = Dung_StatePtr->floorHdr->cols;
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
    grid[width * y + x].flags |= fill;
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
                grid[width * ny + nx].flags |= fill;
            }
            if (!(r & 0x4000)) {
                continue;
            }
            grid[width * ny + nx].flags |= fill;
            ((Stg40FillPt *)buf)[count].x = nx;
            ((Stg40FillPt *)buf)[count].y = ny;
            count++;
        }
    } while (count != 0);
}

s32 Stg40_FindUnlabeledRoom(void) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40Cell *c = (Stg40Cell *)b->cells;
    s32 h = b->floorHdr->rows;
    s32 w = b->floorHdr->cols;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++, c++) {
            if ((c->flags & 0x4000) && c->roomId == 0xFF) {
                return y * w + x;
            }
        }
    }
    return -1;
}

void Stg40_LabelFilledCells(void) {
    Stg40DungState *b = Dung_StatePtr;
    s32 n = b->floorHdr->cols * b->floorHdr->rows;
    u8 v = Stg40_RootState->roomCount;
    Stg40Cell *c = (Stg40Cell *)b->cells;
    s32 i;

    for (i = 0; i < n; i++, c++) {
        if (c->flags & 0x2000) {
            c->roomId = v;
            c->flags &= ~0x2000;
        }
    }
}

void Stg40_LabelRooms(void) {
    s32 w = Dung_StatePtr->floorHdr->cols;
    s32 buf = Mem_Alloc(0x3FF8, 2);
    s32 i;

    Stg40_RootState->roomCount = 0;
    while ((D_80072BB8 = i = Stg40_FindUnlabeledRoom()) != -1) {
        Stg40_FloodFillRoom(buf, 0, i % w, i / w, 0x2000);
        Stg40_LabelFilledCells();
        Stg40_RootState->roomCount++;
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Cell *Stg40_GetCell2(s32 x, s32 y) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40FloorHeader *d = b->floorHdr;
    s32 w = d->cols;
    s32 h = d->rows;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->cells)[w * y + x];
    }
    return r;
}

void Stg40_SetCellOccupied(s32 x, s32 y, s32 flag) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40FloorHeader *d = b->floorHdr;
    s32 w = d->cols;
    s32 h = d->rows;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->cells;
        c[w * y + x].flags |= flag == 0 ? 0x40 : 0x60;
    }
}

void Stg40_ClearCellOccupied(s32 x, s32 y) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40FloorHeader *d = b->floorHdr;
    s32 w = d->cols;
    s32 h = d->rows;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->cells;
        c[w * y + x].flags &= ~0x60;
    }
}

void Stg40_ApplyTrapCells(void) {
    Stg40CellPoint *r = Dung_StatePtr->trapCells;
    Stg40Cell *c;
    s32 i;

    for (i = 0; i < Dung_StatePtr->trapCount; r++, i++) {
        c = Stg40_GetCell2(r->x, r->y);
        c->flags &= 0xFFF0;
        c->flags |= r->kind + 7;
    }
}

void Stg40_TurnQueueReset(void) {
    Stg40TurnQueue *p = &Dung_StatePtr->turnQueue;
    s16 *q = p->ids;
    s32 i;

    p->capacity = 10;
    p->count = 0;
    p->cursor = 0;
    for (i = 0; i < p->capacity; i++) {
        *q++ = -1;
    }
    *q = -2;
}

s16 *Stg40_TurnQueueFind(s16 v) {
    Stg40TurnQueue *f = &Dung_StatePtr->turnQueue;
    s16 *p = f->ids;

    while (*p != -2) {
        if (*p == v) {
            return p;
        }
        p++;
    }
    return NULL;
}

void Stg40_TurnQueueAdd(s32 v) {
    Stg40TurnQueue *f = &Dung_StatePtr->turnQueue;

    if (Stg40_TurnQueueFind(v) == NULL && f->count < f->capacity) {
        f->ids[f->count] = v;
        f->count++;
    }
}

void Stg40_TurnQueueRemove(s16 v) {
    Stg40TurnQueue *f = &Dung_StatePtr->turnQueue;
    s16 *p = Stg40_TurnQueueFind(v);
    s16 *q;

    if (p != NULL) {
        for (q = p + 1; *q != -2;) {
            *p++ = *q++;
        }
        *p = -1;
        f->count--;
        if (f->ids[f->cursor] == -1) {
            f->cursor = 0;
        }
    }
}

s16 Stg40_TurnQueueNext(void) {
    Stg40TurnQueue *p = &Dung_StatePtr->turnQueue;

    p->cursor = (p->cursor + 1 < p->count) ? p->cursor + 1 : 0;
    return p->ids[p->cursor];
}

s16 Stg40_TurnQueueCurrent(void) {
    Stg40TurnQueue *p = &Dung_StatePtr->turnQueue;

    return p->ids[p->cursor];
}

void Stg40_LoadDungFile(s32 id) {
    s32 *p;

    p = (s32 *)Cd_GetFileOrNull(id);
    Stg40_RelocDungFile(p);
    Stg40_RootState->dungFileId = id;
    Stg40_RootState->floorTable = p;
    Stg40_RootState->floorMap = p[Dung_StatePtr->floor];
    Stg40_RootState->floorCount = 0;
    while (Stg40_RootState->floorTable[Stg40_RootState->floorCount] != 0) {
        Stg40_RootState->floorCount++;
    }
}

void Stg40_PickFloorLayout(void) {
    s32 i;

    Dung_StatePtr->floorLayout = Stg40_RandInt(8);
    for (i = 7; i >= 0; i--) {
        Dung_StatePtr->revealedRooms[i] = 0;
    }
}

void Stg40_ApplyFloorLayout(void) {
    Stg40B60 *b = Stg40_RootState;
    Stg40DungState *g = Dung_StatePtr;
    Stg40DungFloor *m = (Stg40DungFloor *)b->floorMap;
    u8 *src;
    u8 *dst;

    b->layout = m->layouts[g->floorLayout];
    g->floorHdr->wallStyle = m->wallStyle;
    g->floorHdr->field_4 = 1;
    g->floorHdr->hazardLevel = m->hazardLevel;
    src = m->name;
    dst = Dung_StatePtr->floorHdr->name;
    memset(dst, 0xFF, 16);
    Dung_StatePtr->floorHdr->nameLen = 0;
    while (*src != 0xFF) {
        *dst = *src;
        Dung_StatePtr->floorHdr->nameLen++;
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

s32 Stg40_PickRandomPoint(Stg40CellPos *out, Stg40CellPoint *e, u8 key) {
    s32 r = -1;
    s32 n = 0;

    for (; e->x != 0xFF; e++) {
        if (e->kind == key) {
            out->x = e->x;
            out->y = e->y;
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
    Stg40CellPos buf[20];
    Stg40CellPoint *list = Stg40_RootState->layout->spawnPoints;
    s32 r;

    r = Stg40_PickRandomPoint(buf, list, 0);
    Stg40_RootState->startPos.x = buf[r].x;
    Stg40_RootState->startPos.y = buf[r].y;
    r = Stg40_PickRandomPoint(buf, list, 1);
    Stg40_RootState->gatePos.y = -1;
    Stg40_RootState->gatePos.x = -1;
    if (r != -1) {
        Stg40_RootState->gatePos.x = buf[r].x;
        Stg40_RootState->gatePos.y = buf[r].y;
    }
    r = Stg40_PickRandomPoint(buf, list, 2);
    Stg40_RootState->exitPos.y = -1;
    Stg40_RootState->exitPos.x = -1;
    if (r != -1) {
        Stg40_RootState->exitPos.x = buf[r].x;
        Stg40_RootState->exitPos.y = buf[r].y;
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
        Stg40_MsgWinOpen(1, base, (s32)Save_GameStatePtr->field_D1, (s32)Stg40_NumToDigits(0, Stg40_RootState->damage));
        break;
    case 1:
        Stg40_MsgWinOpen(1, base + 1, (s32)Stg40_NumToDigits(0, Stg40_RootState->damage), 0);
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
    Stg40DungState *g;

    switch (a0) {
    case 0:
        Stg40_RootState->damage = a1 * 400;
        Stg40_DamageBeetle(Stg40_RootState->damage);
        break;
    case 1:
        Stg40_RootState->damage = a1 * 10;
        Stg40_ListPartyDigi(3);
        for (i = 0; i < Stg40_RootState->partyCount; i++) {
            r = &Save_GameStatePtr->elems[Stg40_RootState->partyIdx[i]];
            r->hp = ((s16)r->hp - Stg40_RootState->damage > 0) ? (u16)r->hp - (u16)Stg40_RootState->damage : 1;
        }
        break;
    case 2:
        Dung_StatePtr->statusFlags = (Dung_StatePtr->statusFlags | 2) & ~0x80;
        Dung_StatePtr->confusionTurn = Stg40_RandInt(4) + 1;
        break;
    case 3:
        g = Dung_StatePtr;
        g->bindTurns = 0;
        g->statusFlags = (g->statusFlags | 1) & ~0x40;
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
    st = (Stg40BA0View *)&Dung_StatePtr->statusFlags;
    stack = Stg40_RootState->statusCodes;
    count = &Stg40_RootState->statusCount;
    p = &stack[7];
    for (i = 7; i >= 0; i--) {
        *p-- = 0;
    }
    *count = 0;
    if (st->statusFlags & 1) {
        if (++st->bindTurns >= 3 || (Stg40_RandPercent() < 50 && (st->statusFlags & 0x40))) {
            st->statusFlags &= ~1;
            stack[(*count)++] = 0;
        }
        st->statusFlags |= 0x40;
    }
    if (st->statusFlags & 2) {
        if (Stg40_RandPercent() < 10 && (st->statusFlags & 0x80)) {
            st->statusFlags &= ~2;
            stack[(*count)++] = 1;
        }
        st->statusFlags |= 0x80;
    }
    if (Dung_StatePtr->bitBugLevel != 0) {
        slot = Stg40_PickRandomPart();
        if ((Stg40_RandPercent() < 5 && (st->statusFlags & 0x100)) || (Save_GameStatePtr->bits == 0 && slot == -1)) {
            stack[(*count)++] = 2;
            Dung_StatePtr->bitBugLevel = 0;
        } else {
            if (Save_GameStatePtr->bits != 0) {
                s32 cost[4] = { 0, 20, 50, 100 };
                s32 v = Save_GameStatePtr->bits -= cost[st->bitBugLevel];
                if (v < 0) {
                    v = 0;
                }
                Save_GameStatePtr->bits = v;
                sfx = 4;
            } else {
                Beetle_SetPartBroken(slot, 1);
                stack[(*count)++] = 6;
                sfx = 3;
                Stg40_RootState->brokenPartText = Item_GetNameText(Save_GameStatePtr->slotItems[slot]);
            }
            Stg40_ObjStartFlash(a0, 2);
        }
        st->statusFlags |= 0x100;
    }
    if (Dung_StatePtr->energyBugLevel != 0) {
        if (Stg40_RandPercent() < 2 && (st->statusFlags & 0x200)) {
            stack[(*count)++] = 3;
            Dung_StatePtr->energyBugLevel = 0;
        } else {
            s32 cost[4] = { 0, 2, 4, 6 };
            s16 v = Save_GameStatePtr->mp - cost[st->energyBugLevel];
            Save_GameStatePtr->mp = v;
            if (v < 0) {
                v = 0;
            }
            Save_GameStatePtr->mp = v;
            Stg40_ObjStartFlash(a0, 2);
            sfx = 2;
        }
        st->statusFlags |= 0x200;
    }
    if (Dung_StatePtr->returnBugLevel != 0) {
        s32 chance[4] = { 0, 50, 40, 30 };
        n = ((s32 (*)(s32))Stg40_ListPartyDigi)(1);
        if ((Stg40_RandPercent() < chance[st->returnBugLevel] && (st->statusFlags & 0x400)) || n < 2 ||
            Digi_CountByState(1) >= 24) {
            stack[(*count)++] = 4;
            Dung_StatePtr->returnBugLevel = 0;
        } else {
            n = ((s32 (*)(s32))Stg40_ListPartyDigi)(0);
            r = Stg40_RandPercent() / (100 / n);
            if (r > n - 1) {
                r = n - 1;
            }
            ent = &Save_GameStatePtr->elems[Stg40_RootState->partyIdx[r]];
            ent->state = 1;
            *(Stg40DigiName *)Stg40_RootState->lostDigiName = *(Stg40DigiName *)ent->name;
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
        st->statusFlags |= 0x400;
    }
    if (Dung_StatePtr->memBugCount != 0) {
        st->statusFlags |= 0x800;
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
    return Stg40_RootState->statusCount;
}

void Stg40_RollObjectReveal(void) {
    Stg40Ent48 *e = Dung_StatePtr->ents;
    s32 a;
    s32 b;
    s32 i;
    s32 v;

    a = Stg40_GetPartLevel(13);
    a = a < 0 ? 0 : a;
    b = Stg40_GetPartLevel(14);
    b = b < 0 ? 0 : b;
    for (i = 0; i < Dung_StatePtr->entCount; e++, i++) {
        if (e->flags & 0x8000) {
            switch (e->kind) {
            case 6:
            case 8:
                v = Stg40_HazardRevealChance[e->params[1] - 1 + a * 5];
                if (Stg40_RandPercent() < v) {
                    e->flags |= 0x1000;
                }
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                v = Stg40_BugNestRevealChance[e->params[1] - 1 + b * 3];
                if (Stg40_RandPercent() < v) {
                    e->flags |= 0x1000;
                }
                break;
            }
        }
    }
}

Stg40Ent48 *Stg40_FindEntByDigiId(s32 id) {
    Stg40Ent48 *e;
    s32 i;

    for (i = 0, e = Dung_StatePtr->ents; i < 41; i++, e++) {
        if (e->flags & 0x8000) {
            if ((id != 0 && id == e->digiId) || (id == 0 && (e->flags & 1))) {
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
    Stg40_RootState->cmdDigiId = *arg++;
    Stg40_RootState->cmdArgs.field_0 = arg[0] - 1;
    Stg40_RootState->cmdArgs.field_2 = arg[1] - 1;
    Stg40_RootState->cmdBusy = 0;
    Stg40_RootState->cmdActor = NULL;
    e = Stg40_FindEntByDigiId(Stg40_RootState->cmdDigiId);
    if (e != NULL) {
        t = e->actor;
        Stg40_RootState->cmdBusy = 1;
        switch (Stg40_RootState->cmdArgs.field_0) {
        default:
            st = 5;
            break;
        case 0x62:
            if (Stg40_RootState->cmdArgs.field_2 == -1) {
                st = 4;
                Stg40_RootState->cmdActor = t;
            } else {
                st = 6;
                Stg40_RootState->cmdBusy = 0;
            }
            break;
        case 0x61:
            e->targetHeading = (Stg40_RootState->cmdArgs.field_2 << 12) / 360;
            Stg40_RootState->cmdBusy = 0;
            break;
        case 0x60:
            e->flags |= 0x200;
            Stg40_RootState->cmdBusy = 0;
            break;
        }
        if (st != -1) {
            Task_SetState1(t, (u8)st);
        }
    }
}

void Stg40_EndTextObjCmd(void) {
    Stg40_RootState->cmdBusy = 0;
}

s16 Stg40_IsTextObjCmdBusy(void) {
    return Stg40_RootState->cmdBusy;
}

s32 Stg40_CamIsMoving(void) {
    return Stg40_CameraTask->stateLevel1;
}

void Stg40_CamStartMove(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3) {
    Actor *t = Stg40_CameraTask;
    Stg40CameraWork *w = (Stg40CameraWork *)t->work;

    w->moveGoal = *blk;
    w->moveFrames = a1;
    w->rotYEnd = a2;
    w->rotYDelta = a3;
    Task_SetState1(t, 1);
}

void Stg40_CamLoadScript(Stg40Cmd *src) {
    Stg40CameraWork *w = (Stg40CameraWork *)Stg40_CameraTask->work;
    s32 i;

    w->scriptPos = w->script;
    w->scriptLeft = 0;
    for (i = 0; src->field_0 != 0; i++, src++) {
        w->script[i] = *src;
        w->scriptLeft++;
    }
}

void Stg40_CamNextCommand(Actor *a0) {
    Stg40CameraWork *w = (Stg40CameraWork *)a0->work;
    Stg40Cmd *c;

    if (w->scriptLeft != 0) {
        c = w->scriptPos;
        Stg40_CamStartMove(&c->field_C, c->field_0, c->field_4, c->field_8);
        w->scriptLeft--;
        w->scriptPos++;
    }
}

void Stg40_CamMoveStep(Actor *task) {
    Stg40CameraWork *w = (Stg40CameraWork *)task->work;
    s32 dx;
    s32 x0;
    s32 y0;
    s32 z0;

    if (task->stateLevel2 >= w->moveFrames) {
        do {
            w->view.words[0] = w->moveGoal.words[4];
            w->view.words[1] = w->moveGoal.words[5];
            w->view.words[2] = w->moveGoal.words[6];
            w->rot[1] = (u16)w->rotYEnd;
            if (w->scriptLeft != 0) {
                Stg40_CamNextCommand(task);
            } else {
                Task_SetState1(task, 0);
            }
        } while (0);
        return;
    }
    x0 = w->moveGoal.words[0];
    dx = (x0 - w->moveGoal.words[4]) / w->moveFrames;
    y0 = w->moveGoal.words[1];
    z0 = w->moveGoal.words[2];
    w->view.words[0] = x0 - dx * task->stateLevel2;
    w->view.words[1] = y0 - ((y0 - w->moveGoal.words[5]) / w->moveFrames) * task->stateLevel2;
    w->view.words[2] = z0 - ((z0 - w->moveGoal.words[6]) / w->moveFrames) * task->stateLevel2;
    w->dirty = 1;
    w->rot[1] = (u16)w->rotYEnd + (w->rotYDelta / w->moveFrames) * (w->moveFrames - task->stateLevel2);
    task->stateLevel2 = task->stateLevel2 + 1;
}

void Stg40_CameraInit(Actor *a0, Block1C *a1) {
    Stg40CameraWork *w = (Stg40CameraWork *)a0->work;

    Stg40_CameraTask = a0;
    w->view = *a1;
    w->scriptPos = 0;
    w->scriptLeft = 0;
}

void Stg40_CameraUpdate(Actor *a0) {
    Stg40CameraWork *w = (Stg40CameraWork *)a0->work;
    Stg40RView v;

    switch (a0->stateLevel0) {
    case 0:
    default:
        GsInitCoordinate2(0, &w->coord);
        w->dirty = 1;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->scriptLeft != 0) {
                Stg40_CamNextCommand(a0);
            }
            break;
        case 1:
            Stg40_CamMoveStep(a0);
            break;
        }
        w->dirty = 0;
        RotMatrixYXZ(w->rot, &w->coord.coord);
        w->coord.coord.t[0] = w->originX;
        w->coord.coord.t[1] = w->originY;
        w->coord.coord.t[2] = w->originZ;
        w->coord.flg = 0;
        v.vpvr[0] = w->view.words[0];
        v.vpvr[1] = w->view.words[1];
        v.vpvr[2] = w->view.words[2];
        v.vpvr[3] = w->view.words[3];
        v.vpvr[4] = w->view.words[4];
        v.vpvr[5] = w->view.words[5];
        v.rz = 0;
        v.super = &w->coord;
        GsSetProjection(w->view.words[6]);
        GsSetRefView2(&v);
        break;
    case 2:
        break;
    }
}

void Stg40_CameraDraw(void) {
}
