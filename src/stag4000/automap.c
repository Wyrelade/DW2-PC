#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"
#include "stag4000/hud.h"
#include "stag4000/bitswin.h"
#include "stag4000/itemmenu.h"
#include "stag4000/enemyinfo.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"
#include "stag4000/enemy.h"
#include "stag4000/entity.h"

/* Task callbacks this unit defines further down (the descriptor comes first). */
void Stg40_AutomapInit(void);
void Stg40_AutomapUpdate(Actor *a0);
void Stg40_AutomapDestroy(Actor *a0);
void Stg40_AutomapDraw(Actor *a0);

s32 D_80072944 = 0;
INCLUDE_BIN(Stg40_AutomapClut, "assets/stag4000/automap_clut.bin");
TaskDesc Stg40_AutomapDesc = {
    (TaskInitFn)Stg40_AutomapInit, Stg40_AutomapUpdate, Stg40_AutomapDestroy, Stg40_AutomapDraw, 0xB70, 4,
};

Stg40TileGrid *Stg40_AutomapWork;

void Stg40_AutomapSetCell(s32 idx, s32 row, s32 val) {
    Stg40TileGrid *t = Stg40_AutomapWork;
    s32 sh = (idx % 4) * 4;
    u16 *p = &t->pix[(row + 1) * 18 + idx / 4 + 1];
    *p = (*p & ~(0xF << sh)) | (val << sh);
    t->texDirty = -1;
}

void Stg40_AutomapMoveMarker(s32 x, s32 y, s32 ox, s32 oy, s32 dir) {
    s32 v;

    if (ox != -1) {
        Stg40_AutomapSetCell(ox, oy, (Stg40_GetCellFlags(ox, oy) >> 13) & 1);
    }
    if (x != -1) {
        switch (dir) {
        case 0:
            v = 14;
            break;
        case 1:
            v = 13;
            break;
        case 2:
        case 3:
            v = 10;
            break;
        case 4:
            v = 11;
            break;
        default:
            v = 12;
            break;
        }
        Stg40_AutomapSetCell(x, y, v);
    }
}

void Stg40_AutomapRedraw(Stg40AutomapWork *a0) {
    s32 h = a0->rows;
    s32 w = a0->cols;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            Stg40_AutomapSetCell(x, y, (Stg40_GetCellFlags(x, y) >> 13) & 1);
        }
    }
}

void Stg40_ClearVisitedBits(void) {
    s32 i;
    u8 *p = Dung_StatePtr->visitedBits;

    i = 0x17F;
    do {
        i--;
        *p++ = 0;
    } while (i >= 0);
    D_80072944 = 0;
}

void Stg40_SyncVisitedBits(s32 arg0) {
    s32 n;
    u8 *p;
    Stg40Cell *c;
    s32 i;

    p = Dung_StatePtr->visitedBits;
    c = (Stg40Cell *)Dung_StatePtr->cells;
    n = Dung_StatePtr->floorHdr->cols * Dung_StatePtr->floorHdr->rows / 8;

    for (i = 0; i < n; i++) {
        if (arg0 == 0) {
            *p = 0;
            *p = (c->flags >> 13) & 1;
            c++;
            *p |= (c->flags & 0x2000) ? 2 : 0;
            c++;
            *p |= (c->flags & 0x2000) ? 4 : 0;
            c++;
            *p |= (c->flags & 0x2000) ? 8 : 0;
            c++;
            *p |= (c->flags & 0x2000) ? 0x10 : 0;
            c++;
            *p |= (c->flags & 0x2000) ? 0x20 : 0;
            c++;
            *p |= (c->flags & 0x2000) ? 0x40 : 0;
            c++;
            *p |= (c->flags & 0x2000) ? 0x80 : 0;
            c++;
        } else {
            if (*p & 1) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 2) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 4) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 8) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 0x10) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 0x20) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 0x40) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
            if (*p & 0x80) c->flags |= 0x2000; else c->flags &= ~0x2000;
            c++;
        }
        p++;
    }
}

void Stg40_ResetVisitedCells(void) {
    Stg40_ClearVisitedBits();
    Stg40_SyncVisitedBits(1);
}

void Stg40_AutomapRevealAll(void) {
    Stg40AutomapWork *t = (Stg40AutomapWork *)Stg40_AutomapWork;
    s32 x;
    s32 y;

    for (y = 0; y < Dung_StatePtr->floorHdr->rows; y++) {
        for (x = 0; x < Dung_StatePtr->floorHdr->cols; x++) {
            Stg40_RevealCell(t, x, y);
        }
    }
}

void Stg40_AutomapLoadClut(Stg40ImgWork *a0) {
    LoadImage(&a0->rect, a0->data);
}

void Stg40_AutomapFlush(Stg40AutomapWork *a0) {
    if (a0->texDirty != 0) {
        LoadImage(&a0->rect, a0->data);
        a0->texDirty = 0;
    }
}

void Stg40_AutomapCycleClut(Stg40ImgWork *a0) {
    Stg40ImgClut *p = (Stg40ImgClut *)a0;
    s32 c;
    s32 v;
    s32 h;
    s32 g;
    s32 b;

    p->clutTimer++;
    c = 15 - ((p->clutTimer & 0xF) >> 1);
    v = c & 0x1F;
    b = v << 10;
    g = (v << 5) | 0x8000;
    p->clut[4] = b | g;
    p->clut[3] = v | 0x8000;
    p->clut[2] = (v << 5) | 0x8000 | v;
    p->clut[1] = g;
    h = (c / 2) & 0x1F;
    p->clut[0] = b | ((h << 5) | 0x8000) | h;
    if (Pad_State[0].start != 0) {
        p->clut[6] = 0xA94A;
        p->clut[7] = 0xE318;
    } else {
        p->clut[6] = 0x8000;
        p->clut[7] = 0xA94A;
    }
    Stg40_AutomapLoadClut(a0);
}

void Stg40_AutomapInitTex(Stg40AutomapWork *w) {
    GfxTexSlot *s;
    RECT *r;
    u16 *d;
    u16 *src;
    s32 i;
    s32 n;
    s32 j;
    s32 k;

    ((Stg40ImgWork *)w)->slot = P32_SET(Gfx_ReserveTexSlot());
    s = P32(GfxTexSlot, ((Stg40ImgWork *)w)->slot);
    r = &((Stg40ImgWork *)w)->rect;
    r->x = s->vramX;
    r->y = s->vramY + 0xFE;
    r->w = 0x10;
    r->h = 2;
    d = (u16 *)((Stg40ImgWork *)w)->data;
    src = Stg40_AutomapClut;
    for (j = 0; j < 32; j++) {
        *d++ = *src++;
    }
    Stg40_AutomapLoadClut((Stg40ImgWork *)w);
    r = &w->rect;
    r->x = s->vramX;
    r->y = s->vramY;
    r->w = 0x12;
    r->h = 0x32;
    n = 0x12 * 0x32;
    d = ((Stg40TileGrid *)w)->pix;
    for (i = 0; i < n; i++) {
        *d++ = 0;
    }
    w->texDirty = -1;
    Stg40_AutomapFlush(w);
    for (k = 1; k >= 0; k--) {
        w->modeFade[k] = 0;
    }
}

void Stg40_AutomapReleaseTex(Stg40ImgWork *a0) {
    Gfx_ReleaseTexSlot(P32(s32, a0->slot));
}

s16 Stg40_AutomapInitDims(Stg40AutomapWork *a0) {
    DungState *b = Dung_StatePtr;

    a0->cols = b->floorHdr->cols;
    a0->rows = b->floorHdr->rows;
    return a0->field_76A = a0->cols / 8;
}

const Stg40Offs8 Stg40_NeighborOffsets = { { -1, 0, 1, 0, 0, -1, 0, 1 } };
void Stg40_RevealRoom(Stg40AutomapWork *w, s32 x, s32 y)
{
    s32 group;
    s32 row;
    s32 n;
    s32 mask;
    u8 kind;
    s32 dim1;
    Stg40FloorHeader *dims;
    s32 count;
    Stg40Cell *grid;
    s32 col;
    s32 t;

    dims = Dung_StatePtr->floorHdr;
    dim1 = dims->cols;
    count = dims->rows;
    kind = Stg40_GetCell(x, y)->roomId;
    if (kind == 0xFF) {
        return;
    }
    group = kind >> 5;
    mask = 1 << (kind % 32);
    if (group < 8) {
        t = Dung_StatePtr->revealedRooms[group];
        if (t & mask) {
            return;
        }
        Dung_StatePtr->revealedRooms[group] |= mask;
    }
    grid = (Stg40Cell *)Dung_StatePtr->cells;
    for (row = 0; row < count; row++) {
        for (col = 0; col < dim1; col++) {
            if (grid[col + row * dim1].roomId == kind) {
                grid[col + row * dim1].flags |= 0x2000;
                Stg40_AutomapSetCell(col, row, 1);
                {
                    Stg40Offs8 o = Stg40_NeighborOffsets;

                    for (n = 0; n < 4; n++) {
                        s32 nx = col + o.v[n * 2];
                        s32 ny = row + o.v[n * 2 + 1];

                        if ((Stg40_GetCellFlags(nx, ny) & 0xC000) == 0x8000) {
                            do {
                                do {
                                    t = nx + dim1 * ny;
                                    grid[t].flags |= 0x2000;
                                    Stg40_AutomapSetCell(nx, ny, 1);
                                } while (0);
                            } while (0);
                        }
                    }
                }
            }
        }
    }
}

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
    a.tpage = 0x20 | ((P32(GfxTexSlot, w->slot)->vramY & 0x100) >> 4) | ((P32(GfxTexSlot, w->slot)->vramX & 0x3FF) >> 6) | (((u16)P32(GfxTexSlot, w->slot)->vramY & 0x200) << 2);
    a.clut = ((u16)w->clut.y << 6) | (((u16)w->clut.x >> 4) & 0x3F);
    a.code = 0x2E;
    width = right - left;
    height = bottom - top;
    a.u0 = P32(GfxTexSlot, w->slot)->uOffset + left + 3;
    a.v0 = top;
    a.u1 = P32(GfxTexSlot, w->slot)->uOffset + left + 3 + width;
    a.v1 = top;
    a.u2 = P32(GfxTexSlot, w->slot)->uOffset + left + 3;
    a.v2 = top + height;
    a.u3 = P32(GfxTexSlot, w->slot)->uOffset + left + 3 + width;
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
    b.tpage = 0x40 | ((P32(GfxTexSlot, w->slot)->vramY & 0x100) >> 4) | ((P32(GfxTexSlot, w->slot)->vramX & 0x3FF) >> 6) | (((u16)P32(GfxTexSlot, w->slot)->vramY & 0x200) << 2);
    b.clut = (((u16)w->clut.y + 1) << 6) | (((u16)w->clut.x >> 4) & 0x3F);
    *p = a;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((s32)p & 0xFFFFFF);
    p++;
    *p = b;
    p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((s32)p & 0xFFFFFF);
    p++;
    Sys_State.packet.addr = (s32)p;
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
