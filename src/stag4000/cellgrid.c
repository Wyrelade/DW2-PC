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
#include "stag4000/spawn.h"
#include "stag4000/automap.h"
#include "stag4000/cellgrid.h"

u16 Stg40_FloorBitsPal[10] = { 2, 1, 4, 3, 7, 6, 5 };
u16 Stg40_SpecialFloorValues[6] = { 4, 3, 7, 6, 5, 2 };
s32 Stg40_FillNeighbours[8] = { 0, -1, 0, 1, -1, 0, 1, 0 };

/* Room Stg40_LabelRooms is labeling (written only). */
s32 Stg40_LabelRoomsCur;

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
    DungState *g = Dung_StatePtr;
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
    DungState *b = Dung_StatePtr;
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
    DungState *b = Dung_StatePtr;
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
    DungState *b = Dung_StatePtr;
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
    DungState *b = Dung_StatePtr;
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
    while ((Stg40_LabelRoomsCur = i = Stg40_FindUnlabeledRoom()) != -1) {
        Stg40_FloodFillRoom(buf, 0, i % w, i / w, 0x2000);
        Stg40_LabelFilledCells();
        Stg40_RootState->roomCount++;
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Cell *Stg40_GetCell2(s32 x, s32 y) {
    DungState *b = Dung_StatePtr;
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
    DungState *b = Dung_StatePtr;
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
    DungState *b = Dung_StatePtr;
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
