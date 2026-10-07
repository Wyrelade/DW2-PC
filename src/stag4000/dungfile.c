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
#include "stag4000/dungfile.h"

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
    DungState *g = Dung_StatePtr;
    Stg40DungFloor *m = (Stg40DungFloor *)b->floorMap;
    u8 *src;
    u8 *dst;

    b->layout = P32(Stg40DungLayout, m->layouts[g->floorLayout]);
    g->floorHdr->wallStyle = m->wallStyle;
    g->floorHdr->field_4 = 1;
    g->floorHdr->hazardLevel = m->hazardLevel;
    src = P32(u8, m->name);
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
    Stg40DungFloorRel *m;
    Stg40DungLayoutRel *r;
    u32 *q;

    while (*tbl != 0) {
        if (*tbl < base) {
            *tbl += base;
            m = (Stg40DungFloorRel *)*tbl;
            m->name += base;
            for (i = 0; i < 8; i++) {
                q = &m->layouts[i];
                *q += base;
                r = (Stg40DungLayoutRel *)*q;
                Stg40_RelocPtr(&r->offsets[0], base);
                Stg40_RelocPtr(&r->offsets[1], base);
                Stg40_RelocPtr(&r->offsets[2], base);
                Stg40_RelocPtr(&r->offsets[3], base);
                Stg40_RelocPtr(&r->offsets[4], base);
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
    Stg40CellPoint *list = P32(Stg40CellPoint, Stg40_RootState->layout->spawnPoints);
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
