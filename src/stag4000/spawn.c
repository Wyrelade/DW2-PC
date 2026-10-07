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

u8 Stg40_EnemyAiTable[] = {
    0x02, 0x00, 0x02, 0x01, 0x04, 0x02, 0x03, 0x02, 0x07, 0x02, 0x06, 0x02, 0x05, 0x02, 0x02, 0x03,
};
u8 Stg40_EnemyPaceTable[] = { 1, 0, 2, 0, 0, 1, 1, 0 };
/* Task_DescTable[2]: task ids 0x200-0x20D. */
TaskDesc *Stg40_TaskDescs[] = {
    &Stg40_RootDesc, 0, &Stg40_FloorDesc, &Stg40_CameraDesc, &Stg40_ObjDesc, 0, &Stg40_AutomapDesc,
    &Stg40_LinkedModelDesc, &Stg40_MsgWinDesc, &Stg40_HudDesc, &Stg40_BitsWinDesc, &Stg40_ItemMenuDesc,
    &Stg40_EnemyInfoDesc, &Stg40_HudDesc,
};

s32 Stg40_AddEntity(kind, a1, a2, a3, x, y)
    s32 kind;
    s32 a1;
    s32 a2;
    s16 a3;
    s16 x;
    s16 y;
{
    Stg40Ent48 *e;
    s32 flag = 0;
    s32 n;
    s16 h;

    e = &Dung_StatePtr->ents[Dung_StatePtr->entCount];
    if (Dung_StatePtr->entCount >= 41) {
        return -1;
    }
    e->turnId = Dung_StatePtr->entCount;
    e->field_6 = 0;
    e->flags = 0xC000;
    e->kind = kind;
    e->spawnKind = a1;
    e->digiId = a2;
    h = (a3 << 12) / 360;
    e->heading = h;
    e->targetHeading = h;
    e->octant = h / 512;
    e->loc.u0.pair.field_0 = x;
    e->loc.u0.pair.field_2 = y;
    e->loc.height = 0;
    if (a2 >= 500 && a2 <= 532) {
        e->scaleX = e->scaleY = e->scaleZ = 0xD99;
    } else {
        e->scaleX = e->scaleY = e->scaleZ = 0x1000;
    }
    switch (e->kind) {
    case 0:
        flag = 1;
        e->flags |= flag;
        e->params = (u8 *)&Dung_StatePtr->statusFlags;
        Stg40_RootState->playerEnt = e;
        Dung_StatePtr->statusFlags = 0;
        Dung_StatePtr->confusionTurn = 0;
        break;
    case 1:
        flag = 1;
        e->params = Dung_StatePtr->parties[Dung_StatePtr->partyCount++];
        e->flags |= 2;
        break;
    case 4:
        flag = 1;
        n = Dung_StatePtr->chestCount++;
        e->params = Dung_StatePtr->chests[n + 1];
        e->flags |= 4;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        flag = 0;
        n = Dung_StatePtr->hazardCount++;
        e->params = Dung_StatePtr->hazards[n];
        e->flags |= 4;
        break;
    case 2:
    case 3:
        flag = 0;
        e->flags |= 4;
        break;
    }
    Stg40_SetCellOccupied(x, y, flag);
    Dung_StatePtr->entCount++;
    return 0;
}

void Stg40_SpawnEnemyParties(void) {
    Stg40Drop *r;
    Stg40EnemyParty *s;
    Out1DB68 out;
    s32 k;
    s32 id;
    s32 i;
    s16 t;
    s32 m;
    s32 c;
    Stg40DungFloor *map;

    for (r = Stg40_RootState->layout->enemyParties; r->x != 0xFF; r++) {
        if (Dung_StatePtr->partyCount >= 10) {
            break;
        }
        switch (Stg40_RandInt(4)) {
        case 0:
        default:
            k = r->pick0;
            break;
        case 1:
            k = r->pick1;
            break;
        case 2:
            k = r->pick2;
            break;
        case 3:
            k = r->pick3;
            break;
        }
        if (k != 0) {
            id = k[((Stg40DungFloor *)Stg40_RootState->floorMap)->enemySets];
            Enemy_GetSetSummary(id, &out);
            c = out.mapDigiId;
            Stg40_AddEntity(1, 0, c, 0, r->x, r->y);
            s = (Stg40EnemyParty *)Dung_StatePtr->parties[Dung_StatePtr->partyCount - 1];
            s->setId = id;
            s->useDungeonBgm = out.useDungeonBgm != 0;
            s->likedGift = out.likedGift;
            s->pointsPerLevel = out.pointsPerLevel;
            t = s->pointsPerLevel;
            if (t == 0) {
                t = 1;
            }
            s->pointsPerLevel = t;
            s->giftsTaken = 0;
            s->giftPoints = 0;
            s->stepsPerBurst = Stg40_EnemyPaceTable[out.paceType * 2];
            s->idleTicks = Stg40_EnemyPaceTable[out.paceType * 2 + 1];
            s->cellCode = Stg40_EnemyAiTable[out.aiType * 2];
            m = s->pathMode = Stg40_EnemyAiTable[out.aiType * 2 + 1];
            if (m == 2) {
                if (s->cellCode != (Stg40_GetCellFlags(r->x, r->y) & 0xF)) {
                    s->cellCode = m;
                    s->pathMode = 0;
                }
            }
            s->digiCount = 0;
            for (i = 0; i < 3; i++) {
                if ((s16)out.digiIds[i] == 0) {
                    break;
                }
                s->digiIds[i] = out.digiIds[i];
                s->levels[i] = out.levels[i];
                s->digiCount++;
            }
        }
    }
}

void Stg40_SpawnChests(void) {
    Stg40ChestDef *pos = ((Stg40DungFloor *)Stg40_RootState->floorMap)->chests;
    Stg40Drop *r;
    s32 k;
    u8 *d;

    for (r = Stg40_RootState->layout->chests; r->x != 0xFF; r++) {
        if (Dung_StatePtr->chestCount >= 12) {
            break;
        }
        switch (Stg40_RandInt(4)) {
        case 0:
        default:
            k = r->pick0;
            break;
        case 1:
            k = r->pick1;
            break;
        case 2:
            k = r->pick2;
            break;
        case 3:
            k = r->pick3;
            break;
        }
        if (k != 0) {
            Stg40_AddEntity(4, 0, 0x276, 0, r->x, r->y);
            k--;
            d = Dung_StatePtr->chests[Dung_StatePtr->chestCount];
            d[0] = pos[k].itemId;
            d[1] = pos[k].trapLevel;
        }
    }
}

const Stg40Ids4 Stg40_BugModelIds = { { 0x265, 0x268, 0x26B, 0x26E } };
s32 Stg40_SpawnHazard(a0, a1, a2, a3)
    s32 a0;
    s32 a1;
    s16 a2;
    s16 a3;
{
    Stg40Ids4 tbl;
    s32 lvl;
    s32 t;
    s32 u;
    s32 m;
    s32 kind;
    s32 model;
    s32 id;
    s32 bit;
    Stg40CellPoint *r;
    u8 *d;

    lvl = a1;
    u = lvl;
    if (lvl == 0) {
        u = 1;
    }
    lvl = u;
    switch (a0) {
    case 0:
    default:
        return 0;
    case 2:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x25A;
        kind = 6;
        bit = lvl - 1;
        break;
    case 3:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x25F;
        kind = 7;
        bit = lvl + 4;
        break;
    case 4:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x270;
        kind = 8;
        bit = lvl + 9;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        tbl = Stg40_BugModelIds;
        t = 3;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        kind = a0 + 4;
        id = tbl.id[a0 - 5];
        t = lvl + 5;
        bit = kind + t;
        id += lvl;
        model = id - 1;
        break;
    case 1:
        m = 5;
        m = (lvl < m) ? lvl : m;
        lvl = m;
        if (Dung_StatePtr->trapCount >= 100) {
            return -1;
        }
        r = &Dung_StatePtr->trapCells[Dung_StatePtr->trapCount];
        r->x = a2;
        r->y = a3;
        r->kind = lvl;
        Dung_StatePtr->trapCount++;
        return 0;
    }
    if (!(bit & Stg40_RootState->hazardMask)) {
        if (Stg40_RootState->hazardTypeCount >= 12) {
            return -1;
        }
        Stg40_RootState->hazardMask |= bit;
        Stg40_RootState->hazardTypeCount++;
    }
    if (Dung_StatePtr->hazardCount < 16) {
        Stg40_AddEntity(kind, a0, model, 0, a2, a3);
        d = Dung_StatePtr->hazards[Dung_StatePtr->hazardCount - 1];
        d[0] = a0;
        d[1] = lvl;
        return 0;
    }
    return -1;
}

void Stg40_SpawnFixedHazards(void) {
    Stg40Spawn *e;
    s32 kind;
    s32 val;

    for (e = Stg40_RootState->layout->hazards; e->x != 0xFF; e++) {
        switch (Stg40_RandInt(4)) {
        case 0:
        default:
            kind = e->kind0;
            val = e->val0;
            break;
        case 1:
            kind = e->kind1;
            val = e->val1;
            break;
        case 2:
            kind = e->kind2;
            val = e->val2;
            break;
        case 3:
            kind = e->kind3;
            val = e->val3;
            break;
        }
        if (kind != 0) {
            Stg40_SpawnHazard(kind, val + Dung_StatePtr->floorHdr->hazardLevel, e->x, e->y);
        }
    }
}

s32 Stg40_GetRegionCells(u8 (*tbl)[2], s32 v) {
    Stg40DungState *b = Dung_StatePtr;
    Stg40Cell *cells = (Stg40Cell *)b->cells;
    s32 h = b->floorHdr->rows;
    s32 w = b->floorHdr->cols;
    s32 n = 0;
    s32 x;
    s32 y;
    Stg40Cell *c;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            c = &cells[y * w + x];
            if (c->roomId == v && !(c->flags & 0x40) && (c->flags & 0xF) < 8) {
                tbl[n][0] = x;
                tbl[n][1] = y;
                n++;
            }
        }
    }
    return n;
}

void Stg40_SpawnHazardAtRandom(u8 (*tbl)[2], s32 a1, s32 a2) {
    s32 n = Stg40_GetRegionCells(tbl, Stg40_RandInt(Stg40_RootState->roomCount));

    if (n != 0) {
        n = Stg40_RandInt(n);
        Stg40_SpawnHazard(a1, a2, tbl[n][0], tbl[n][1]);
    }
}

const Stg40Ids5 Stg40_RandomHazardKinds = { { 4, 5, 6, 7, 8 } };
void Stg40_SpawnRandomHazards(void) {
    Stg40DungFloor *m = (Stg40DungFloor *)Stg40_RootState->floorMap;
    Stg40Ids5 ids = Stg40_RandomHazardKinds;
    Stg40MapGen *g = m->hazardGroups;
    s32 buf;
    s32 i;
    s32 j;
    s32 n;
    s32 v;

    if (Stg40_RootState->roomCount == 0) {
        return;
    }
    buf = Mem_Alloc(0x1800, 2);
    for (i = 0; i < 5; g++, i++) {
        switch (Stg40_RandInt(4)) {
        case 0:
        default:
            n = g->cnt0;
            break;
        case 1:
            n = g->cnt1;
            break;
        case 2:
            n = g->cnt2;
            break;
        case 3:
            n = g->cnt3;
            break;
        }
        for (j = 0; j < n; j++) {
            switch (Stg40_RandInt(4)) {
            case 0:
            default:
                v = g->val0;
                break;
            case 1:
                v = g->val1;
                break;
            case 2:
                v = g->val2;
                break;
            case 3:
                v = g->val3;
                break;
            }
            Stg40_SpawnHazardAtRandom((u8 (*)[2])buf, ids.id[i], v);
        }
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Ent48 *Stg40_FindEntAt(s16 x, s16 y) {
    Stg40Ent48 *e = Dung_StatePtr->ents;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < 41; i++, e++) {
        if (e->loc.u0.pair.field_0 == x && e->loc.u0.pair.field_2 == y && (e->flags & 0x8000)) {
            r = e;
            break;
        }
    }
    return r;
}

void Stg40_RevealAllEnts(void) {
    s32 i;
    Stg40Ent48 *e = Dung_StatePtr->ents;

    for (i = 0; i < 41; i++, e++) {
        if (e->flags & 0x8000) {
            e->flags |= 0x5000;
        }
    }
}

s32 Stg40_IsEntAdjacent(Stg40Ent48 *a, Stg40Ent48 *b) {
    s16 dx;
    s16 dy;

    if (a->loc.u0.pair.field_0 - b->loc.u0.pair.field_0 >= 0) {
        dx = a->loc.u0.pair.field_0 - b->loc.u0.pair.field_0;
    } else {
        dx = b->loc.u0.pair.field_0 - a->loc.u0.pair.field_0;
    }
    if (a->loc.u0.pair.field_2 - b->loc.u0.pair.field_2 >= 0) {
        dy = a->loc.u0.pair.field_2 - b->loc.u0.pair.field_2;
    } else {
        dy = b->loc.u0.pair.field_2 - a->loc.u0.pair.field_2;
    }
    return dx < 2 && dy < 2;
}

s32 Stg40_CheckEncounter(void) {
    Stg40EncounterList *l = &Dung_StatePtr->encounterList;
    Stg40Ent48 *e = Dung_StatePtr->ents;
    s32 i;
    s32 r;

    l->count = 0;
    for (i = 0; i < Dung_StatePtr->entCount; i++, e++) {
        if ((e->flags & 0x8002) == 0x8002 && e->actor->stateLevel1 != 4) {
            r = Stg40_IsEntAdjacent(e, Stg40_RootState->playerEnt);
            if (r == 1) {
                l->ents[l->count++] = e;
                e->flags |= 0x100;
                Task_SetState1(e->actor, 3);
                e->flags |= (l->count == r) ? 0x800 : 0;
            }
        }
    }
    if (l->count != 0) {
        Stg40_RootState->playerEnt->flags |= 0x100;
    }
    return l->count;
}

s32 Stg40_DeltaToOctant(s32 dx, s32 dy) {
    s32 idx = 0;
    s32 r;
    s32 v;

    if (dx < 0) {
        idx |= 8;
    }
    if (dx > 0) {
        idx |= 4;
    }
    if (dy < 0) {
        idx |= 2;
    }
    idx |= dy > 0;
    v = Stg40_PadDirTable[idx];
    r = 0;
    if (v != -1) {
        r = v;
    }
    return r;
}

void Stg40_ObjSetAnim(a0, a1)
    Actor *a0;
    s16 a1;
{
    ((Stg40ActWork *)a0->work)->pendingAnim = a1;
}

void Stg40_ObjSetAnimIfNew(Actor *a0, s32 a1) {
    if (((Stg40ActWork *)a0->work)->curAnim != a1) {
        Stg40_ObjSetAnim(a0, a1);
    }
}

s32 Stg40_ObjWaitAnim(Actor *a0) {
    s32 r = 0;

    a0->stateLevel4++;
    if (Stg40_ObjAnimDone(a0) == 1 || a0->stateLevel4 >= 31) {
        r = 1;
    }
    return r;
}

s32 Stg40_ObjWaitAnimOrSkip(Actor *a0) {
    s32 r = 0;

    a0->stateLevel4++;
    if (Stg40_ObjAnimDone(a0) == 1 || a0->stateLevel4 >= 31 || (a0->stateLevel4 >= 11 && Pad_State[0].cross != 0)) {
        r = 1;
    }
    return r;
}

void Stg40_LoadEventTiles(s32 a0) {
    s32 n;
    Blk12 *e;
    Stg40B60 *b;

    Stg40_RootState->eventTileCount = 0;
    if (a0 != 0) {
        Flag_SetTableFile(a0);
        for (n = Flag_FirstPassingEntry(); n != -1; n = Flag_NextPassingEntry()) {
            e = Flag_GetEntryPosList(n);
            b = Stg40_RootState;
            b->eventTiles[b->eventTileCount].u0.pair.field_0 = e->data[0] - 1;
            b->eventTiles[b->eventTileCount].u0.pair.field_2 = e->data[1] - 1;
            b->eventTiles[b->eventTileCount].entry = n;
            b->eventTileCount++;
        }
    }
}

s32 Stg40_CheckEventTile(void) {
    u32 i = 0;
    s32 r = 0;
    Stg40EventTile *e = Stg40_RootState->eventTiles;

    for (; i < Stg40_RootState->eventTileCount; e++) {
        Stg40B60 *b = Stg40_RootState;
        i++;
        if (b->playerEnt->loc.u0.tileXY == e->u0.tileXY) {
            b->eventEntry = e->entry;
            e->u0.pair.field_2 = -1;
            e->u0.pair.field_0 = -1;
            r = -1;
            Dung_StatePtr->freeze = 2;
            break;
        }
    }
    return r;
}

void Stg40_ObjQueueFiles(Stg40ObjQueueView *a0, s32 a1, s32 a2) {
    if (a0->drawn == 0) {
        a0->requeueTimer = 0;
        return;
    }
    if (a0->requeueTimer == 0) {
        if (a1 != 0) {
            Cd_QueueFile(a1);
        }
        if (a2 != 0) {
            Cd_QueueFile(a2);
        }
        a0->requeueTimer = 16;
    }
    a0->requeueTimer--;
}

void Stg40_SetBeetlePart(s32 i, s32 item, u8 status) {
    GameState *g = Save_GameStatePtr;

    g->slotItems[i] = item;
    g->slotStatus[i] = item ? status : 1;
}

s32 Stg40_GetBeetlePart(i)
    s32 i;
{
    GameState *g = Save_GameStatePtr;

    if (g->slotStatus[i] == 1) {
        return -1;
    }
    return g->slotItems[i];
}

s32 Stg40_GetPartLevel(s32 slot) {
    GameState *gs = Save_GameStatePtr;
    s32 r;

    if (gs->slotItems[slot] == 0) {
        return 0;
    }
    if (gs->slotStatus[slot] == 1) {
        return -1;
    }
    r = Item_GetLevel(gs->slotItems[slot]);
    r = r ? r : 1;
    return r;
}

void Stg40_SetPartBroken(s32 i, u8 status) {
    GameState *g = Save_GameStatePtr;

    g->slotStatus[i] = g->slotItems[i] ? status : 0;
}

void Stg40_DamageBeetle(s32 n) {
    GameState *g = Save_GameStatePtr;

    g->hp = (g->hp - n < 0) ? 0 : g->hp - n;
}

s32 Stg40_ListUsableItems(Stg40ItemReq *a) {
    s32 ret;
    s32 j;
    s32 i;
    s32 key;
    u16 *bag;
    u16 *items;

    Stg40_RootState->itemCount = 0;
    switch (Stg40_GetBeetlePart(a->partSlot)) {
    case -1:
        ret = a->msgBase;
        break;
    case 0:
        ret = a->msgBase + 1;
        break;
    default:
        for (j = 0; j < 4; j++) {
            key = a->itemCategories[j];
            items = Save_GameStatePtr->bagItems;
            if (key != -1) {
                for (i = 0, bag = items; i < 0x30; i++, bag++) {
                    if (*bag != 0 && key == Item_GetCategory(*bag)) {
                        Stg40_RootState->itemIds[Stg40_RootState->itemCount] = *bag;
                        Stg40_RootState->itemCount++;
                    }
                }
            }
        }
        if (Stg40_RootState->itemCount == 0) {
            ret = a->msgBase + 2;
        } else {
            ret = 0;
        }
        break;
    }
    return ret;
}

s16 Stg40_ListPartyDigi(s32 mode) {
    DigiRosterEntry *e = Save_GameStatePtr->elems;
    Stg40B60 *b;
    s32 *pi;
    s32 i;

    Stg40_RootState->partyCount = 0;
    b = Stg40_RootState;
    for (i = 0; i < 36; e++, i++) {
        if (e->state >= 2) {
            switch (mode) {
            case 1:
                if ((s16)e->hp == 0) {
                    continue;
                }
                b->partyIdx[b->partyCount++] = i;
                break;
            case 2:
                if ((s16)e->hp == 0) {
                    b->partyIdx[b->partyCount++] = i;
                }
                break;
            case 3:
                if ((s16)e->hp >= 2) {
                    b->partyIdx[b->partyCount++] = i;
                }
                break;
            default:
                b->partyIdx[b->partyCount++] = *(pi = &i);
                break;
            }
        }
    }
    i = Stg40_RootState->partyCount;
    return i;
}
