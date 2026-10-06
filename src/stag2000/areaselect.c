#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/mapbg.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_AreaSelectUpdate(Actor *a);
void Stg20_AreaSelectDraw(Actor *a);
/* New-game save blocks (Stg20_ApplyStartPreset). */
Stg20StartBlock Stg20_StartPreset0 = { {
    0x320, 0x320, 0x64, 0x64, 0xEA, 1, 0x2F, 0x35, 0x4A, 0, 0, 0x5A,
    0x5F, 0, 0, 0, 0, 0, 0, 0, 0x73, 0x75, 0x77, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0x78, 0x78, 0x7B,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0x203, 1, 0xFF,
    0, 0, 0x300, 0x102, 0xFF00, 0, 0, 0, 0, 0, 0,
} };
Stg20StartBlock Stg20_StartPreset1 = { {
    0xC80, 0xC80, 0xAF0, 0xAF0, 0xEB, 0x1E, 0x31, 0x43, 0x4D, 0, 0x55, 0x5A,
    0x5F, 0x60, 0x63, 0, 0, 0x6C, 0x6F, 0, 0x73, 0x75, 0x77, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0x78, 0x78, 0x78,
    0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B,
    0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0xA6, 0xA7, 0xC1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0xA2CB, 0xCDB9, 0xFFB9,
    0, 0, 0x2300, 0x2738, 0x32, 0xFF01, 0, 0, 0, 0, 0,
} };
/* "AKAGI", "NAOMI", "DINOGON" in the game's glyph codes (0x0A 'A', 0xFF end). */
u8 Stg20_PresetDigiNames[3][8] = {
    { 0x0A, 0x14, 0x0A, 0x10, 0x12, 0xFF },
    { 0x17, 0x0A, 0x18, 0x16, 0x12, 0xFF },
    { 0x0D, 0x12, 0x17, 0x18, 0x10, 0x18, 0x17, 0xFF },
};
Stg20Vec3 Stg20_MoveParams[] = { { 0, 0x7AE, 0x2666 }, { 0, 0x170A, 0x828F } };
Stg20Cell Stg20_DirCellDelta[4] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
s32 Stg20_AreaIconHideMasks[] = { 0x1E0, 0x1D0, 0x1B0, 0x170, 0xF0 };
s32 Stg20_AreaScreenPartsIds[] = { 0x03D80002, 0x0DF50002, 0x0DF70002, 0x0CD90003, 0x05140003 };
TaskDesc Stg20_AreaSelectDesc = { 0, Stg20_AreaSelectUpdate, Task_DefaultDestroy, Stg20_AreaSelectDraw, 0x2DC, 0 };
Stg20Cell Stg20_CellTmp;
Stg20MenuState Stg20_MenuState;

void Stg20_ApplyStartPreset(s32 arg0) {
    s32 i;
    s32 j;

    if (arg0 == 0) {
        ((Stg20GameInit *)&Save_GameState)->start = Stg20_StartPreset0;
        Save_GameState.elems[0].state = 0;
        Save_GameState.elems[1].state = 0;
        Save_GameState.elems[2].state = 0;
    } else {
        ((Stg20GameInit *)&Save_GameState)->start = Stg20_StartPreset1;
        Digi_InitFromTable(0x99, 0, &Save_GameState.elems[0]);
        Save_GameState.elems[0].state = 3;
        Digi_InitFromTable(0x99, 1, &Save_GameState.elems[1]);
        Save_GameState.elems[1].state = 4;
        Digi_InitFromTable(0x99, 2, &Save_GameState.elems[2]);
        Save_GameState.elems[2].state = 5;
        Digi_SortRoster();
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 8; j++) {
                Save_GameState.elems[i].name[j] = Stg20_PresetDigiNames[i][j];
            }
        }
    }
}

s32 Stg20_OwnsDigi(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state >= 2 && Save_GameState.elems[i].digiId == id) {
            return 1;
        }
    }
    return 0;
}

void Stg20_AddBits(s32 d) {
    GameState *g = &Save_GameState;

    g->bits += d;
    if (g->bits < 0) {
        g->bits = 0;
    }
    if (g->bits > 99999999) {
        g->bits = 99999999;
    }
}

void Stg20_RemoveOwnedDigi(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state >= 2 && Save_GameState.elems[i].digiId == id) {
            Save_GameState.elems[i].state = 0;
            break;
        }
    }
    Digi_SortRoster();
}

s32 Stg20_TestSpecialFlag(s32 id) {
    s32 i;
    s32 n;
    s32 free;
    s32 j;

    switch (id) {
    case 9000:
        n = Item_GetBagCapacity();
        for (j = 0; j < n; j++) {
            if (((Stg20GameState *)&Save_GameState)->bagItems[j] == 0) {
                return 1;
            }
        }
        return 0;
    case 9001:
        n = 0;
        free = 0;
        for (i = 0; i < 0x24; i++) {
            if (Save_GameState.elems[i].state == 0) {
                free = 1;
            }
            if (Save_GameState.elems[i].state >= 2) {
                n++;
            }
        }
        if (free == 0) {
            return 0;
        }
        return n < 12;
    case 9003:
        return Stg20_OwnsDigi(0xDA);
    case 9004:
        return Stg20_OwnsDigi(0xD1);
    case 9005:
        return Stg20_OwnsDigi(0x43);
    case 9023:
        for (n = 0; n < 3; n++) {
            if (((Stg20GameRoster *)&Save_GameState)->elems[n].state == n + 3
                && ((Stg20GameRoster *)&Save_GameState)->elems[n].hp != 0) {
                return 0;
            }
        }
        return 1;
    case 9009:
        return Save_GameState.itemCounts[1] >= 0x10;
    case 9010:
        return Save_GameState.itemCounts[1] >= 0x1F;
    case 9012:
        return Sys_State.prevGameMode == 0x32A;
    case 9034:
        return Sys_State.prevGameMode == 0x32B;
    case 9013:
        if (Sys_State.gameMode == 0x301 && Sys_State.modeArg == 3) {
            return 1;
        }
        if (Sys_State.gameMode == 0x321 && Sys_State.modeArg == 2) {
            return 1;
        }
        return 0;
    case 9014:
        if (Sys_State.gameMode == 0x301 && Sys_State.modeArg == 4) {
            return 1;
        }
        if (Sys_State.gameMode == 0x321 && Sys_State.modeArg == 3) {
            return 1;
        }
        return 0;
    case 9015:
        return Save_GameState.bits >= 500;
    case 9016:
        return Save_GameState.bits >= 1000;
    case 9017:
        return Save_GameState.bits >= 1500;
    case 9018:
        return Save_GameState.bits >= 2000;
    case 9019:
        return Save_GameState.bits >= 2500;
    case 9020:
        return Save_GameState.bits >= 3000;
    case 9021:
        return Save_GameState.bits >= 3500;
    case 9022:
        return Save_GameState.bits >= 4000;
    case 9024:
        return Save_GameState.rank < 2;
    case 9025:
        return Save_GameState.rank < 3;
    case 9026:
        return Save_GameState.rank < 4;
    case 9027:
        return Save_GameState.rank < 5;
    case 9028:
        return Save_GameState.rank < 6;
    case 9029:
        return Save_GameState.rank < 7;
    case 9030:
        return Save_GameState.rank < 8;
    case 9031:
        return Save_GameState.rank < 9;
    case 9032:
        return Save_GameState.rank < 10;
    case 9033:
        return Save_GameState.rank < 11;
    case 9035:
        if (Flag_Test(0x2C6) == 0) {
            return 0;
        }
        if (Flag_Test(0x2C7) == 0) {
            return 0;
        }
        return Flag_Test(0x2C8) != 0;
    }
    return 0;
}

void Stg20_SetSpecialFlag(s32 id, s32 on) {
    s32 i;
    s32 j;

    if (on == 0) {
        return;
    }
    switch (id) {
    case 0x238C:
        Save_GameState.itemCounts[0] = 0xEB;
        break;
    case 0x23B5:
        Save_GameState.itemCounts[0] = 0xEC;
        break;
    case 0x238D:
        Save_GameState.itemCounts[17] = 0x76;
        break;
    case 0x238E:
        Stg20_ApplyStartPreset(0);
        break;
    case 0x238F:
        Stg20_ApplyStartPreset(1);
        break;
    case 0x2390:
        Stg20_AddBits(2000);
        break;
    case 0x2391:
        Stg20_AddBits(1000);
        break;
    case 0x2392:
        Stg20_RemoveOwnedDigi(0x54);
        Digi_AddNew(0xBF);
        break;
    case 0x2393:
        Stg20_RemoveOwnedDigi(0xC5);
        Digi_AddNew(0xC0);
        break;
    case 0x2394:
        Stg20_RemoveOwnedDigi(0xB);
        Digi_AddNew(0xC1);
        break;
    case 0x2395:
        Stg20_RemoveOwnedDigi(0x16);
        Digi_AddNew(0xC2);
        break;
    case 0x2396:
        Stg20_RemoveOwnedDigi(0x4F);
        Digi_AddNew(0xC3);
        break;
    case 0x2397:
        Stg20_RemoveOwnedDigi(0x85);
        Digi_AddNew(0xC4);
        break;
    case 0x2398:
        Stg20_RemoveOwnedDigi(0xEA);
        Digi_AddNew(0xC5);
        break;
    case 0x2399:
        Stg20_RemoveOwnedDigi(0xCC);
        Digi_AddNew(0xC6);
        break;
    case 0x239A:
        Stg20_RemoveOwnedDigi(0x1A);
        Digi_AddNew(0xC7);
        break;
    case 0x23AA:
        Stg20_AddBits(-500);
        break;
    case 0x23AB:
        Stg20_AddBits(-1000);
        break;
    case 0x23AC:
        Stg20_AddBits(-1500);
        break;
    case 0x23AD:
        Stg20_AddBits(-2000);
        break;
    case 0x23AE:
        Stg20_AddBits(-2500);
        break;
    case 0x23AF:
        Stg20_AddBits(-3000);
        break;
    case 0x23B0:
        Stg20_AddBits(-3500);
        break;
    case 0x23B1:
        Stg20_AddBits(-4000);
        break;
    case 0x239C:
        Save_GameState.rank = 1;
        break;
    case 0x239D:
        Save_GameState.rank = 2;
        break;
    case 0x239E:
        Save_GameState.rank = 3;
        break;
    case 0x239F:
        Save_GameState.rank = 4;
        break;
    case 0x23A0:
        Save_GameState.rank = 5;
        break;
    case 0x23A1:
        Save_GameState.rank = 6;
        break;
    case 0x23A2:
        Save_GameState.rank = 7;
        break;
    case 0x23A3:
        Save_GameState.rank = 8;
        break;
    case 0x23A4:
        Save_GameState.rank = 9;
        break;
    case 0x23A5:
        Save_GameState.rank = 10;
        break;
    case 0x23A6:
        Save_GameState.rankTitleSet = 0;
        break;
    case 0x23A7:
        Save_GameState.rankTitleSet = 1;
        break;
    case 0x23A8:
        Save_GameState.rankTitleSet = 2;
        break;
    case 0x23B3:
        for (j = 0; j < Item_GetBagCapacity(); j++) {
            if (((Stg20GameState *)&Save_GameState)->bagItems[j] == 0xC2) {
                ((Stg20GameState *)&Save_GameState)->bagItems[j] = 0;
                Item_SortList();
                break;
            }
        }
        break;
    case 0x23B2:
    case 0x23B4:
        ((Stg20GameState *)&Save_GameState)->mp = ((Stg20GameState *)&Save_GameState)->maxMp;
        ((Stg20GameState *)&Save_GameState)->hp = ((Stg20GameState *)&Save_GameState)->maxHp;
        for (i = 0; i < 0x13; i++) {
            ((Stg20GameState *)&Save_GameState)->slotStatus[i] = 0;
        }
        for (i = 0; i < 0x24; i++) {
            if (Save_GameState.elems[i].state != 0) {
                Save_GameState.elems[i].hp = Save_GameState.elems[i].maxHp;
                Save_GameState.elems[i].mp = Save_GameState.elems[i].maxMp;
            }
        }
        break;
    case 0x23B6:
        Flag_Set(0x25B, 0);
        Flag_Set(0x25C, 0);
        Flag_Set(0x25D, 0);
        Flag_Set(0x262, 1);
        Flag_Set(0x263, 1);
        Flag_Set(0x264, 1);
        break;
    case 0x23B7:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xDA]++;
        break;
    case 0x23B8:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xBF]++;
        break;
    case 0x23B9:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xD6]++;
        break;
    case 0x23BA:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xC0]++;
        break;
    case 0x23BB:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xDF]++;
        break;
    case 0x23BC:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xE0]++;
        break;
    case 0x23BD:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xD3]++;
        break;
    case 0x23BE:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xD8]++;
        break;
    case 0x23BF:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x49]++;
        break;
    case 0x23C0:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x4F]++;
        break;
    case 0x23C1:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x2E]++;
        break;
    case 0x23C2:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x34]++;
        break;
    }
}

void Stg20_OpenText(void *t, s32 text, s32 id, Stg20Cell *pos, s32 color) {
    Stg20TextArgs args;

    if (id == 0) {
        args.text = text;
    } else {
        args.text = (s32)Cd_GetFileEntry(id + 0x1FD0000);
    }
    args.bigFont = 0;
    args.color = color;
    args.pos = *pos;
    args.charAdvance = 0;
    args.lineAdvance = 0xC;
    args.charDelay = 0;
    Text_Open(t, &args);
}

Stg20Cell *Stg20_GetActorCell(Actor *a) {
    ActorTransformView *t = a->u38.ptr38;

    Stg20_CellTmp.x = (t->posX + 0x4500) / 0x600;
    Stg20_CellTmp.y = 0x16 - (t->posZ + 0x4500) / 0x600;
    return &Stg20_CellTmp;
}

s32 Stg20_IsOnCellCenter(Actor *a) {
    ActorTransformView *t = a->u38.ptr38;
    s32 m = 0xE6;
    s32 r;
    s32 v;

    do {
        v = (t->posX + 0x12C73) % 0x600;
        if (v > m) {
            break;
        }
        r = 1;
        v = (t->posZ + 0x12C73) % 0x600;
        if (v > m) {
            break;
        }
        return r;
    } while (0);
    return 0;
}

void Stg20_SnapToCell(Actor *a, s32 doX, s32 doZ) {
    ActorTransformView *t = a->u38.ptr38;

    if (doX) {
        t->posX = (t->posX + 0x12F00) / 0x600 * 0x600 - 0x12C00;
    }
    if (doZ) {
        t->posZ = (t->posZ + 0x12F00) / 0x600 * 0x600 - 0x12C00;
    }
}

void Stg20_SetMoveParams(Actor *a, s32 i) {
    Stg20Vec3 *v = &((Stg20Rot *)a->u38.ptr38)->axisMotion2;

    if (v->field_0 == 0) {
        v->field_0 = Stg20_MoveParams[i].field_0;
    }
    v->field_4 = Stg20_MoveParams[i].field_4;
    v->field_8 = Stg20_MoveParams[i].field_8;
}

Stg20Cell *Stg20_GetCellInDir(Actor *a, s32 dir) {
    Stg20Cell *c = Stg20_GetActorCell(a);

    c->x += Stg20_DirCellDelta[dir].x;
    c->y += Stg20_DirCellDelta[dir].y;
    return c;
}

s32 Stg20_IsCellBlocked(Actor *a, s32 dir) {
    s32 mask;

    if (Stg20_MenuState.talkActive != 0) {
        return 0;
    }
    mask = 0xBF;
    if (((Stg20ModelTask *)a)->walkerKind == 0) {
        mask = 0x7F;
    }
    return Stg20_GetGridCell(Stg20_GetCellInDir(a, dir)) & mask;
}

void Stg20_AddOccupantMark(Actor *a, Stg20Marks *m, s32 dir, s32 timer) {
    Stg20Cell *c;
    s32 i;

    if (dir == -1) {
        c = Stg20_GetActorCell(a);
    } else {
        c = Stg20_GetCellInDir(a, dir);
    }
    for (i = 0; i < 5; i++) {
        if (m->cell[i].x == c->x && m->cell[i].y == c->y) {
            goto found;
        }
    }
    for (i = 0; i < 5; i++) {
        if (m->timer[i] == 0) {
            goto found;
        }
    }
    return;
found:
    m->cell[i] = *c;
    m->timer[i] = timer;
}

void Stg20_TickOccupantMarks(Actor *a, Stg20Marks *m) {
    s32 i;
    s32 flag = ((Stg20ModelTask *)a)->walkerKind == 0;

    for (i = 0; i < 5; i++) {
        if (m->timer[i] != 0) {
            if (--m->timer[i] == 0) {
                Stg20_MarkGridOccupant(&m->cell[i], 0, flag);
            } else {
                Stg20_MarkGridOccupant(&m->cell[i], 1, flag);
            }
        }
    }
}

s32 Stg20_CellDistWeighted(Stg20Cell *c, s32 x, s32 y, s32 flag) {
    s32 dx = c->x - x;
    s32 dy;

    if (dx < 0) {
        dx = -dx;
    }
    dy = c->y - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (flag) {
        dx *= 3;
    } else {
        dy *= 3;
    }
    return dx + dy;
}

s32 Stg20_AreaSelectFindDir(Actor *a, s32 dir) {
    Stg20NavWork *w = (Stg20NavWork *)a->work;
    Stg20Cell c;
    s32 best;
    s32 found;
    s32 i;
    s32 d;
    Stg20PickRec *r;

    c.x = w->recs[w->index].cell.x;
    c.y = w->recs[w->index].cell.y;
    best = 0x7D00;
    found = -1;
    for (i = 0; (r = &w->recs[i])->id != -1; i++) {
        if (i == w->index) {
            continue;
        }
        switch (dir) {
        case 0:
            if (c.y < r->cell.y) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 1);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        case 1:
            if (c.x > r->cell.x) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 0);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        case 2:
            if (c.y > r->cell.y) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 1);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        case 3:
            if (c.x < r->cell.x) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 0);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        }
    }
    return found;
}

const Halves Stg20_AreaNamePos = { 0xC6, 0x12 };
void Stg20_AreaSelectUpdate(Actor *a) {
    Stg20NavWork *w = (Stg20NavWork *)a->work;
    Stg20PickRec *r;
    s32 i;
    s32 n;
    s32 k;

    switch (a->stateLevel0) {
    case 0:
        if (Sys_State.prevGameMode == 0x602) {
            Sys_State.modeArg = ((Stg20GameState *)&Save_GameState)->areaSelectArg;
        }
        Mem_FillWordsNeg1(&w->text, 1);
        w->index = 0;
        for (i = 0, n = 0; ; i++) {
            r = (Stg20PickRec *)Stg20_GetMapDest(i);
            if (i == Sys_State.modeArg) {
                w->index = n;
            }
            if (r->id == -1) {
                break;
            }
            if (r->id == 0 || Flag_Test(r->id) != 0) {
                w->recs[n] = *r;
                n++;
            }
        }
        w->recs[n].id = -1;
        w->redraw = 1;
        ((Stg20GameState *)&Save_GameState)->areaSelectArg = Sys_State.modeArg;
        Task_NextState0(a);
        break;
    case 1:
        do {
            if (Pad_State[0].down > 0) {                k = Stg20_AreaSelectFindDir(a, 0);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].left > 0) {                k = Stg20_AreaSelectFindDir(a, 1);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].up > 0) {                k = Stg20_AreaSelectFindDir(a, 2);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].right > 0) {                k = Stg20_AreaSelectFindDir(a, 3);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].cross > 0) {                if (w->recs[w->index].mode != 0x301) {                    goto play;                }                if (w->recs[w->index].arg != 2 || Flag_Test(0x12) != 0) {                play:                    Snd_PlayById(0xE, 0);                    Task_NextState0(a);                }            }            if (w->redraw != 0) {                w->redraw = 0;                Text_Close(&w->text);                Text_OpenPacked(&w->text, w->recs[w->index].text, 0, Stg20_AreaNamePos);            }        } while (0);
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = w->recs[w->index].mode;
                Sys_State.modeArg = w->recs[w->index].arg;
                Text_CloseArray(&w->text, 1);
            }
            break;
        }
        break;
    }
}

void Stg20_AreaSelectDraw(Actor *a) {
    Stg20NavWork *w = (Stg20NavWork *)a->work;
    s32 i;
    GfxPart *p;
    GfxPart *q;

    for (i = 0; ; i++) {
        GfxPart *unused; /* block-scope decl: keeps GCC from copying the exit test (loop not inverted) */

        if (w->recs[i].fileId == 0) {
            break;
        }
        if (w->recs[i].flag != 0 && Flag_Test(w->recs[i].flag) != 0) {
            p = (GfxPart *)Cd_GetFileEntry(w->recs[i].altFileId);
        } else {
            p = (GfxPart *)Cd_GetFileEntry(w->recs[i].fileId);
        }
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & (0xF - (1 << Math_CycleRange(a->elapsed, 6, 0, 3)))) {
                q->visible = 0;
            } else {
                q->visible = 1;
                q->x = w->recs[i].cell.x;
                q->y = w->recs[i].cell.y;
            }
        }
        Gfx_DrawParts((s32)p);
    }
    p = (GfxPart *)Cd_GetFileEntry(0x4100000);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 7);
            q->x = w->recs[w->index].cell.x;
            q->y = w->recs[w->index].cell.y;
        }
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, Stg20_AreaIconHideMasks[Sys_State.gameMode - 0x32A]);
    do {
        Gfx_DrawParts((s32)p);
    } while (0);
    p = (GfxPart *)Cd_GetFileEntry(Stg20_AreaScreenPartsIds[Sys_State.gameMode - 0x32A]);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 0xF);
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_AreaSelectShowName(Actor *a, s32 open) {
    Stg20PickWork *w = (Stg20PickWork *)a->work;

    if (open == 0) {
        Text_Close(&w->text);
    } else {
        Text_OpenPacked(&w->text, w->recs[w->index].text, 0, Stg20_AreaNamePos);
    }
}
