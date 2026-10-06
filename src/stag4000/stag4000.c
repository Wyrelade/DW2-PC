#include "common.h"
#include "stag4000/stag4000.h"

/* Task callbacks this unit defines further down (the descriptors come first). Not
 * stag4000_funcs.h: Stg40_SetupStage calls Stg40_InitDungeonEntry before its K&R definition. */
void Stg40_RootInit(void);
void Stg40_RootUpdate(Actor *arg0);
void Stg40_RootDestroy(Actor *a0);
void Stg40_RootDraw(void);

/* Unreferenced. */
s32 D_800725B0[] = { 0x020E0000, 0x020F0000, -1 };
TaskDesc Stg40_RootDesc = {
    (TaskInitFn)Stg40_RootInit, Stg40_RootUpdate, Stg40_RootDestroy, (TaskFn)Stg40_RootDraw, 0x14, 0xE0,
};

Actor *Stg40_RootTask;
Stg40RootTasks *Stg40_RootChildren;
u8 D_80072AA8[0x18];
u8 D_80072AC0[0xA0];
Stg40B60 *Stg40_RootState;

void Stg40_InitDisplay(void) {
    Blk16 *l;
    Stg40Rgb *c;

    Sys_SetFrameRate30();
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Gpu_SetBgClearColor(0, 0, 0);
    Gpu_ClearScreens();
    Gfx_FadeInFromBlack(0x20);
    Gpu_AllocPacketBufs(0x19000);
    l = (Blk16 *)Cd_GetFileEntry(0xE200001);
    c = (Stg40Rgb *)Cd_GetFileEntry(0xE200002);
    Stg40_SetLights(l, c->r, c->g, c->b);
}

void Stg40_InitFloorHeader(void) {
    Stg40DungState *b = Dung_StatePtr;

    b->floorHdr = &b->defaultFloorHdr;
    b->defaultFloorHdr.cols = 0x40;
    b->floorHdr->rows = 0x30;
}

void Stg40_InitDungeonEntry() { /* K&R: Stg40_SetupStage passes its work pointer */
    Stg40DungEntry *tbl;
    s32 i;
    Stg40Ent48 *e;

    Dung_StatePtr->entryMode = 1;
    Dung_StatePtr->field_5 = 0;
    Dung_StatePtr->floor = 0;
    Dung_StatePtr->fromMode32B = 0;
    Dung_StatePtr->beetleDown = 0;
    if (Sys_State.prevGameMode == 0x32B) {
        Dung_StatePtr->fromMode32B = 1;
    }
    if (Sys_State.gameMode != 0x200) {
        Dung_StatePtr->dungeonIdx = (u16)Sys_State.gameMode - 0x201;
    } else {
        Dung_StatePtr->dungeonIdx = Sys_State.modeArg;
    }
    tbl = (Stg40DungEntry *)Cd_GetFileEntry(0xE20000A);
    Dung_StatePtr->dungeon = tbl[Dung_StatePtr->dungeonIdx];
    Dung_StatePtr->floorTexId0 = tbl[Dung_StatePtr->dungeonIdx].floorTexId0;
    Dung_StatePtr->floorTexId1 = tbl[Dung_StatePtr->dungeonIdx].floorTexId1;
    e = Dung_StatePtr->ents;
    for (i = 0; i < 41; i++, e++) {
        e->flags = 0;
    }
    Dung_StatePtr->bitBugLevel = Dung_StatePtr->energyBugLevel = Dung_StatePtr->returnBugLevel = Dung_StatePtr->memBugCount = 0;
    for (i = 0; i < 12; i++) {
        Dung_StatePtr->memBugLevels[i] = 0;
    }
    Dung_StatePtr->dungFileId = Dung_StatePtr->dungeon.dungFileId;
    Digi_SortRoster();
    for (i = 0; i < 3; i++) {
        if (Save_GameStatePtr->elems[i].state < 2) {
            break;
        }
        Save_GameStatePtr->elems[i].state = i + 3;
    }
}

void Stg40_BuildFloorMap(void) {
    Stg40_ApplyFloorLayout();
    Stg40_AllocCellGrid();
    Stg40_FillCellGrid();
    Stg40_LabelRooms();
}

const Stg40BeetleIdTable Stg40_BeetleDigiIds = { { 0x1F8, 0x1FB, 0x1FE, 0x1F5, 0x202, 0x205, 0x1F9, 0x1FC, 0x1F6,
      0x200, 0x203, 0x206, 0x1FA, 0x1FD, 0x1FF, 0x201, 0x204, 0x1F7 } };
void Stg40_SetupStage(Actor *a0) {
    ActorWork *work = a0->work;
    s32 *slots = (s32 *)a0->u34.children;
    s32 reset = 0;
    s32 *cur;
    s32 j;
    Stg40Ent48 *e;
    Stg40DungState *blk;
    s32 mode;

    Stg40_InitDisplay();
    Stg40_InitFloorHeader();
    Stg40_ClearPreloadList();
    mode = D_8005F790 / 256;
    switch (mode) {
    default:
        Dung_StatePtr->entryMode = 0;
        break;
    case 2:
        Dung_StatePtr->entryMode = 1;
        break;
    case 5:
        Dung_StatePtr->entryMode = 2;
        break;
    }
    if (Dung_StatePtr->entryMode == 0) {
        Stg40_InitDungeonEntry(work);
    }
    Stg40_LoadDungFile(Dung_StatePtr->dungFileId);
    Stg40_LoadEventTiles(((Stg40DungFloor *)Stg40_RootState->floorMap)->eventTable);
    if (Dung_StatePtr->entryMode == 1) {
        Stg40Ent48 *p;
        s32 i;
        Stg40BeetleIdTable buf;
        s32 level;

        blk = Dung_StatePtr;
        blk->entCount = 0;
        blk->partyCount = 0;
        blk->chestCount = 0;
        blk->hazardCount = 0;
        blk->trapCount = 0;
        Stg40_RootState->hazardTypeCount = 0;
        Stg40_RootState->hazardMask = 0;
        p = blk->ents;
        for (i = 0x28; i >= 0; i--) {
            p->flags = 0;
            p++;
        }
        reset = -1;
        Stg40_PickFloorLayout(blk, p);
        Stg40_BuildFloorMap();
        Stg40_PickSpawnPoints();
        buf = Stg40_BeetleDigiIds;
        level = Save_GameStatePtr->slotItems[0];
        level = (level != 0) ? (level - 0xEA) * 6 : 0;
        if (Save_GameStatePtr->field_36 != 0) {
            level += Save_GameStatePtr->field_36 - 0x4F;
        }
        if (level < 0x12) {
            level = buf.digiIds[level];
        } else {
            level = 0x1F8;
        }
        if (Flag_Test(0x68) != 0) {
            level = 0x20B;
        }
        Stg40_AddEntity(0, 0, level, 0, Stg40_RootState->startPos.x, Stg40_RootState->startPos.y);
        if (Stg40_RootState->gatePos.x != -1) {
            Stg40_AddEntity(2, 0, 0x258, 0, Stg40_RootState->gatePos.x, Stg40_RootState->gatePos.y);
        }
        if (Stg40_RootState->exitPos.x != -1) {
            Stg40_AddEntity(3, 0, 0x259, 0, Stg40_RootState->exitPos.x, Stg40_RootState->exitPos.y);
        }
        Stg40_SpawnEnemyParties();
        Stg40_SpawnChests();
        Stg40_SpawnFixedHazards();
        Stg40_ApplyTrapCells();
        Stg40_SpawnRandomHazards();
        Stg40_RollObjectReveal();
        Stg40_ClearVisitedBits();
        Stg40_TurnQueueReset();
    }
    Dung_StatePtr->freeze = 0;
    Dung_StatePtr->transitionReq = 0;
    if (reset != -1) {
        Stg40_BuildFloorMap();
        Stg40_ApplyTrapCells();
    }
    Stg40_SyncVisitedBits(1);
    Task_Create(9, slots, 0);
    cur = slots + 6;
    Task_Create(0x203, cur, (s32)Cd_GetFileEntry(0xE200000));
    cur = slots + 7;
    j = 0;
    e = Dung_StatePtr->ents;
    if (Dung_StatePtr->entCount > 0) {
        do {
            if (e->flags & 0x8000) {
                Task_Create(0x204, cur, (s32)e);
                cur++;
            }
            e++;
            j++;
        } while (j < Dung_StatePtr->entCount);
    }
    Task_Create(0x202, cur, (s32)&Dung_StatePtr->floorTexId0);
    cur++;
    Task_Create(0x206, cur, 0);
    cur++;
    Task_Create(0x208, cur, 0);
    if (Dung_StatePtr->entryMode == 2) {
        Cd_QueueFile(0xE31);
        Cd_QueueFile(0xE30);
    }
    Dung_StatePtr->freeze = 1;
    Dung_StatePtr->floorHdr->field_4 = 1;
}

void Stg40_RootInit(void) {
}

const Blk13 Stg40_FloorSpecialtyByCell = { { 0, 0, 0, 3, 2, 6, 5, 4, 0, 0, 0, 0, 0 } };
s32 Stg40_BeginTransition(Actor *arg0) {
    Blk13 sp10;
    Stg40Ent48 *e;
    ActorWork *w = arg0->work;
    s16 q;
    s32 a0v;
    s32 a1v;
    s32 ret;
    u8 **slot;

    if (Dung_StatePtr->transitionReq == 0) {
        return 0;
    }
    switch (Dung_StatePtr->transitionReq) {
    case 1:
    default:
        Stg40_CamLoadScript(Cd_GetFileEntry(0xE200003));
        Dung_StatePtr->freeze = 1;
        w->field_0 = 0x500;
        e = Dung_StatePtr->encounterList.ents[0];
        sp10 = Stg40_FloorSpecialtyByCell;
        Dung_StatePtr->floorSpecialty = sp10.b[Stg40_GetCellFlags(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2) & 0xF];
        slot = &e->params;
        Dung_StatePtr->partyPointsPerLevel = ((Stg40EnemyParty *)e->params)->pointsPerLevel;
        q = ((Stg40EnemyParty *)*slot)->giftPoints / (s16)((Stg40EnemyParty *)*slot)->pointsPerLevel;
        Dung_StatePtr->giftLevel = q;
        if ((s16)q >= 4) {
            q = 3;
        }
        Dung_StatePtr->giftLevel = q;
        D_8005F794 = ((Stg40EnemyParty *)*slot)->setId;
        if (((Stg40EnemyParty *)*slot)->useDungeonBgm != 0) {
            if (Flag_Test(0x88) != 0 && Dung_StatePtr->dungeon.battleBgmId == 0x100) {
                a0v = 0x101;
                a1v = 1;
            } else {
                a0v = Dung_StatePtr->dungeon.battleBgmId;
                a1v = Dung_StatePtr->dungeon.battleBgmSet;
            }
        } else {
            a0v = 0x200;
            a1v = 1;
        }
        ret = 1;
        Snd_PlayById(a0v, a1v);
        Snd_PlayById(0x206, 0);
        Task_SetState1(arg0, 3);
        Gfx_FadeOutToBlack(8);
        Cd_QueueFile(0x193);
        break;

    case 2:
        Stg40_CamLoadScript(Cd_GetFileEntry(0xE200004));
        w->field_0 = Sys_GameMode;
        Task_SetState1(arg0, 3);
        ret = 1;
        Dung_StatePtr->floor = Dung_StatePtr->floor + ret;
        break;

    case 3:
    case 4:
        if (Dung_StatePtr->fromMode32B == 0) {
            w->field_0 = 0x301;
            Sys_State.modeArg = Dung_StatePtr->beetleDown ? 3 : 4;
        } else if (!Flag_Test(0x81)) {
            w->field_0 = 0x301;
            Sys_State.modeArg = Dung_StatePtr->beetleDown ? 3 : 4;
        } else {
            w->field_0 = 0x321;
            Sys_State.modeArg = Dung_StatePtr->beetleDown ? 2 : 3;
        }
        if (Dung_StatePtr->beetleDown != 0) {
            Stg40_CamLoadScript(Cd_GetFileEntry(0xE200009));
        } else {
            Stg40_CamLoadScript(Cd_GetFileEntry(0xE200004));
        }
        ret = 1;
        Task_SetState1(arg0, 3);
        break;
    }
    return ret;
}

void Stg40_RootUpdate(Actor *arg0) {
    ActorWork *work = arg0->work;
    s32 st;
    Stg40RootTasks *ctx = (Stg40RootTasks *)arg0->u34.children;
    Actor *bt;
    s32 a0v;
    switch (arg0->stateLevel0) {
    default:
    case 0:
        Stg40_RootTask = arg0;
        Stg40_RootChildren = ctx;
        Stg40_RootState = (Stg40B60 *)Mem_Alloc(0x190, 2);
        Stg40_SetupStage(arg0);
        Task_NextState0(arg0);
        Stg40_RootState->automapMode = 0;
        Snd_SetSlotContent(1, Dung_StatePtr->dungeon.sndSlotContent);
        work->field_8 = 0;
        break;
    case 1:
        if (work->field_8 == 0 && Snd_AnySlotLoading() == 0) {
            work->field_8 = 1;
            Snd_PlayById(Dung_StatePtr->dungeon.bgmId, Dung_StatePtr->dungeon.bgmSet);
            Snd_SetSlotContent(2, 0x19);
        }
        switch (arg0->stateLevel1) {
        default:
        case 0:
            st = arg0->stateLevel2;
            switch (st) {
            default:
            case 0:
                a0v = Dung_StatePtr->entryMode;
                if (a0v >= 3) {
                    goto setSt;
                }
                if (a0v != 0) {
                    goto load;
                }
            setSt:
                Task_SetState1(arg0, 1);
                goto done0;
            load:
                if (a0v == 1) {
                    Stg40_CamLoadScript(Cd_GetFileEntry(0xE200006));
                } else {
                    Stg40_CamLoadScript(Cd_GetFileEntry(0xE200005));
                }

                Task_NextState2(arg0);
                Dung_StatePtr->freeze = 1;
            done0:
                Dung_StatePtr->freeze = 1;
                Stg40_RootState->automapMode = 0;
                break;
            case 1:
                if (Stg40_CamIsMoving() == 0) {
                    bt = Stg40_RootState->playerActor;
                    if (Stg40_CheckEventTile() != 0) {
                        Task_SetState1(bt, 0x1E);
                        Task_SetState1(arg0, 2);
                    } else if (Stg40_CheckEncounter() != 0) {
                        Task_SetState1(bt, 4);
                        Dung_StatePtr->transitionReq = st;
                        Dung_StatePtr->freeze = st;
                        Stg40_BeginTransition(arg0);
                    } else {
                        Task_SetState1(arg0, 1);
                    }
                } else {
                    if (++arg0->stateLevel3 == 6) {
                        Cd_QueueFile(0x1FD);
                        Cd_QueueFile(0x315);
                        Cd_QueueFile(0x7D4);
                        Cd_QueueFile(0x457);
                        Cd_QueueFile(0x6B5);
                        Cd_QueueFile(0x312);
                    }
                }
                break;
            case 2:
                break;
            }
            break;
        case 1:
            st = arg0->stateLevel2;
            switch (st) {
            default:
            case 0:
                Task_Create(0x209, &ctx->hudTask, 0);
                Dung_StatePtr->freeze = 0;
                Stg40_RootState->automapMode = Save_GameStatePtr->field_0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (Dung_StatePtr->freeze == 2) {
                    Task_SetState0((Actor *)ctx->hudTask, 2);
                    Stg40_RootState->automapMode = 0;
                    Task_SetState1(arg0, 2);
                } else if (Stg40_BeginTransition(arg0) == st) {
                    Stg40_RootState->automapMode = 0;
                }
                break;
            }
            break;
        case 2:
            if (Dung_StatePtr->freeze != 2) {
                if (Dung_StatePtr->freeze == 0) {
                    Task_SetState1(arg0, 1);
                } else if (Stg40_BeginTransition(arg0) != 1) {
                    Task_SetState1(arg0, 1);
                }
            }
            break;
        case 4:
            switch (arg0->stateLevel2) {
            default:
            case 0:
                Task_SetState0((Actor *)ctx->hudTask, 2);
                Stg40_RootState->automapMode = 0;
                Gfx_FadeOutToBlack(0x20);
                Task_NextState2(arg0);
                break;
            case 1:
                if (ctx->hudTask == 0) {
                    if (arg0->stateLevel4++ >= 0xF) {
                        Task_Create(0xB, &ctx->menuTask, 0);
                        arg0->childCount = 2;
                        Task_NextState2(arg0);
                    }
                }
                break;
            case 2:
                if (ctx->menuTask == 0) {
                    arg0->childCount = 0x38;
                    Gfx_FadeInFromBlack(0x20);
                    if (Menu_TopMenuResult == 1) {
                        Task_SetState1(Stg40_RootState->playerActor, 0x1D);
                        Task_SetState2(arg0, 4);
                    } else {
                        Task_Create(0x209, &ctx->hudTask, 0);
                        Stg40_RootState->automapMode = Save_GameStatePtr->field_0;
                        Task_NextState2(arg0);
                    }
                }
                break;
            case 3:
                if (arg0->stateLevel4++ >= 8) {
                    Dung_StatePtr->freeze = 0;
                    Task_SetState1(arg0, 1);
                    Task_SetState2(arg0, 1);
                }
                break;
            case 4:
                if (arg0->stateLevel4++ >= 8) {
                    Dung_StatePtr->transitionReq = 4;
                    Task_SetState1(Stg40_RootState->playerActor, 0x17);
                    Stg40_BeginTransition(arg0);
                }
                break;
            }
            break;
        case 3:
            switch (arg0->stateLevel2) {
            default:
            case 0:
                Dung_StatePtr->freeze = 1;
                Task_SetState0((Actor *)ctx->hudTask, 2);
                Task_NextState2(arg0);
                break;
            case 1:
                if (Stg40_CamIsMoving() == 0) {
                    Sys_NextGameMode = work->field_0;
                    Task_NextState2(arg0);
                }
                break;
            case 2:
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg40_RootDraw(void) {
}

void Stg40_RootDestroy(Actor *a0) {
    Stg40_SyncVisitedBits(0);
    Stg40_FreeCellGrid();
    Mem_Free((ActorWork *)Stg40_RootState);
    Task_DefaultDestroy(a0);
}

void Stg40_ClearPreloadList(void) {
    s32 i;

    for (i = 0x3F; i >= 0; i--) {
        Cd_PreloadIds[i] = 0;
    }
    Cd_PreloadCount = 0;
}

s32 Stg40_AddPreloadId(s32 val) {
    s32 i;
    s32 *p;
    s32 *list;
    s32 count;
    s32 ret;

    i = 0;
    ret = 0;
    list = &Cd_PreloadIds[0];
    if (Cd_PreloadCount > 0) {
        p = list;
        do {
            if (*p == val) {
                return 1;
            }
            i++;
            if (i >= Cd_PreloadCount) {
                break;
            }
            p++;
        } while (1);
    }
    count = Cd_PreloadCount;
    if (count < 0x40) {
        ret = 1;
        Cd_PreloadIds[count] = val;
        Cd_PreloadCount = count + 1;
    }
    return ret;
}

/* Unnamed: dead code, no callers, no table ref; sets state0 = 2 and state1 = a1. */
void func_80064930(Actor *a0, s32 a1) {
    Task_SetState0(a0, 2);
    Task_SetState1(a0, (u8)a1);
}
