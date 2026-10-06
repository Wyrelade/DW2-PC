#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"

/* Task callbacks of the battle descriptor (defined further down). */
void Stg30_BattleUpdate(Actor *a0);
void Stg30_BattleDestroy(Actor *a0);

s16 Stg30_JoinChance[][3] = { { 32, 80, 128 }, { 28, 70, 112 }, { 24, 60, 96 }, { 20, 50, 80 } };
TaskDesc Stg30_BattleDesc = { 0, Stg30_BattleUpdate, Stg30_BattleDestroy, 0, 0xC, 0x4C };

void Stg30_SetDigiAction(Actor *a0, s32 a1, s32 a2) {
    a0->stateLevel0 = 2;
    a0->stateLevel1 = a1;
    a0->stateLevel2 = 0;
    a0->stateLevel3 = 0;
    a0->stateLevel4 = a2;
}

void Stg30_ShowPartyFighters(Stg30ListOwner *a0) {
    s32 i;
    Stg30BattleChildren *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            if (i < 3) {
                Stg30_FighterSetVisible(l->actors[i], 1);
                Stg30_FighterQueueHomeReset(l->actors[i]);
            } else {
                Stg30_FighterSetVisible(l->actors[i], 0);
            }
        }
    }
}

void Stg30_ShowAllFighters(Stg30ListOwner *a0) {
    s32 i;
    Stg30BattleChildren *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            Stg30_FighterSetVisible(l->actors[i], 1);
        }
    }
}

void Stg30_ResetAllFightersHome(Stg30ListOwner *a0) {
    s32 i;
    Stg30BattleChildren *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            Stg30_FighterQueueHomeReset(l->actors[i]);
        }
    }
}

s32 Stg30_HasSkillOrNew(Stg30IdSet *a0, s16 *a1, u8 id) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (a0->ids[i] == id) {
            return 1;
        }
        if (a1[i] == id) {
            return 1;
        }
    }
    return 0;
}

s32 Stg30_RankCanLearnSkill(s32 a0, u8 a1) {
    return a0 >= Skill_GetRank(a1);
}

void Stg30_BattleWonUpdate(Actor *a0) {
    Stg30BattleChildren *l = (Stg30BattleChildren *)a0->u34.children;
    Stg30Pair sum;
    Stg30SkillLearnArgs args;
    u8 ids[24];
    u8 idx[24];
    s32 arg;
    s32 cnt;
    Stg30IdSet *e;
    s32 flag;
    s32 i;
    s32 n;
    s32 m;
    s32 stage;
    s32 f;
    s32 st;
    s32 t;
    s32 k;
    s32 done;
    s32 j;
    s32 stage2;

    switch (a0->stateLevel2) {
    case 0:
    default:
        if (D_8007409C != 0) {
            Snd_PlayById(0x202, 1);
        } else {
            Snd_PlayById(0x201, 1);
        }
        Task_Create(0x505, &l->bannerTask, 2);
        Stg30_SetCameraShot(0x19);
        Stg30_ShowPartyFighters((Stg30ListOwner *)a0);
        a0->elapsed = 0;
        Task_NextState2(a0);
    case 1:
        done = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].hp != 0) {
                f = Anim_GetModelAnimFile(Stg30_Battle.entries[i].digiId, 8);
                Cd_QueueFile(f);
                if (Cd_GetFileState(f) != 3) {
                    done = 1;
                    break;
                }
            }
        }
        if (done) {
            break;
        }
        if (a0->elapsed < 0x3C) {
            break;
        }
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].hp != 0) {
                Task_SetState01(l->actors[i], 2, 2);
            }
        }
        Cd_QueueFile(0x13A);
        Cd_QueueFile(0x110);
        Cd_QueueFile(0x25C);
        a0->elapsed = 0;
        Task_NextState2(a0);
    case 2:
        if (Cd_GetFileState(0x13A) != 3 || Cd_GetFileState(0x110) != 3 || Cd_GetFileState(0x25C) != 3) {
            break;
        }
        if (a0->elapsed < 0xF0) {
            break;
        }
        if (Stg30_Battle.entries[0].fromCity == 0) {
            sum.field_4 = 0;
            sum.field_0 = 0;
            for (t = 3; t < 6; t++) {
                if (Stg30_Battle.entries[t].digiId != 0) {
                    sum.field_4 += Stg30_Battle.enemyAi[t].bits;
                    sum.field_0 += Stg30_Battle.entries[t].exp;
                }
            }
            Task_Create(0x502, &l->resultTask, (s32)&sum);
            Task_NextState2(a0);
            break;
        }
        Task_SetState2(a0, 5);
        break;
    case 3:
        switch (a0->stateLevel3) {
        case 0:
        default:
            if (l->resultTask != 0) {
                break;
            }
            Task_NextState3(a0);
        case 1:
        case 2:
        case 3:
            if (Stg30_Battle.leveledUp[a0->stateLevel3 - 1] == 0) {
                Task_NextState3(a0);
                break;
            }
            switch (a0->stateLevel4) {
            case 0:
            default:
                e = (Stg30IdSet *)&((Stg30StateDigis *)&Stg30_Battle)->digis[a0->stateLevel3 - 1];
                Mem_Zero(&args, 0x1C);
                args.slot = a0->stateLevel3 - 1;
                flag = 0;
                cnt = 0;
                if (e->pendingSkill != 0) {
                    if (!Stg30_HasSkillOrNew(e, args.skillIds, e->pendingSkill)) {
                        args.skillIds[cnt++] = e->pendingSkill;
                        flag = 1;
                    }
                    e->pendingSkill = 0;
                }
                do {
                    stage = Digi_GetRank(e->digiId);
                    j = 0;
                    n = 0;
                    for (; j < 0x18; j++) {
                        if (e->learnableSkills[j] != 0 && Stg30_RankCanLearnSkill(stage, e->learnableSkills[j])) {
                            idx[n] = j;
                            ids[n] = e->learnableSkills[j];
                            n++;
                        }
                    }
                    if (n != 0) {
                        m = (e->level - 2) % 10;
                        if (m >= 3) {
                            k = n;
                        } else {
                            k = n / (4 - m) + 1;
                        }
                        for (j = 0; j < k; j++) {
                            if (Stg30_HasSkillOrNew(e, args.skillIds, ids[j])) {
                                e->learnableSkills[idx[j]] = 0;
                            } else {
                                flag = 1;
                                args.skillIds[cnt++] = ids[j];
                                e->learnableSkills[idx[j]] = 0;
                            }
                        }
                    }
                } while (0);
                if (!flag) {
                    Task_NextState3(a0);
                    break;
                }
                Task_Create(0x512, &l->resultTask, (s32)&args);
                Task_NextState4(a0);
                break;
            case 1:
                if (l->resultTask == 0) {
                    Task_NextState3(a0);
                }
                break;
            }
            break;
        case 4:
            Task_NextState2(a0);
            break;
        }
        break;
    case 4:
        if (l->resultTask != 0) {
            break;
        }
        st = D_8005E5E0;
        if (st != 0) {
            stage2 = Digi_GetRank(Stg30_Battle.entries[Stg30_Battle.joinCandidate].digiId);
            if ((Rand_Next() & 0x7F) < Stg30_JoinChance[stage2][st - 1]) {
                arg = Stg30_Battle.joinCandidate;
                Task_Create(0x513, &l->resultTask, (s32)&arg);
            }
        }
        Task_NextState2(a0);
        break;
    case 5:
        if (l->resultTask != 0) {
            break;
        }
        if ((Sys_State.prevGameMode & 0xFF00) == 0x200) {
            Cd_QueueStag4000Files();
        }
        Task_NextState2(a0);
    case 6:
        switch (a0->stateLevel3) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState3(a0);
        case 1:
            if (++a0->stateLevel4 < 0x10) {
                break;
            }
            if (Flag_Test(0x2DD)) {
                Flag_Set(0x2DD, 0);
                Sys_State.nextGameMode = 0x406;
            } else {
                Sys_State.modeArg = 2;
                Sys_State.nextGameMode = Sys_State.prevGameMode;
            }
            Task_NextState3(a0);
            break;
        case 2:
            break;
        }
        break;
    }
}

void Stg30_BattleLostUpdate(Stg30ListOwner *a0) {
    Stg30BattleChildren *l = a0->list;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x203, 1);
        Stg30_ShowPartyFighters(a0);
        Task_Create(0x505, &l->bannerTask, 3);
        Stg30_SetCameraShot(0x19);
        Task_NextState2((Actor *)a0);
    case 1:
        if (l->bannerTask != 0) {
            break;
        }
        Task_NextState2((Actor *)a0);
    case 2:
        switch (a0->stateLevel3) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState3((Actor *)a0);
        case 1:
            if (Sys_State.fadeLevel == 0xFF) {
                if (Stg30_Battle.entries[0].fromCity != 0) {
                    Sys_State.modeArg = 2;
                    Sys_State.nextGameMode = Sys_State.prevGameMode;
                } else {
                    Sys_State.nextGameMode = 0x401;
                }
                Task_NextState3((Actor *)a0);
            }
        case 2:
            break;
        }
        break;
    }
}

void Stg30_ResetPartyStats(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (Stg30_Battle.entries[i].state >= 3) {
            Stg30_Battle.entries[i].attack = Save_GameState.elems[i].attack;
            Stg30_Battle.entries[i].defense = Save_GameState.elems[i].defense;
            Stg30_Battle.entries[i].speed = Save_GameState.elems[i].speed;
        }
    }
}

void Stg30_BattleUpdate(Actor *a0) {
    Stg30BattleWork *w = (Stg30BattleWork *)a0->work;
    Stg30BattleChildren *l = (Stg30BattleChildren *)a0->u34.children;
    s32 args[3];
    Out1DB68 out;
    TaskEntry *t;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 v;
    s32 sum;
    s32 alive;
    s32 flag;
    s32 n1;
    s32 n2;
    s32 n3;
    s32 n4;
    s32 n5;
    s32 n6;
    s32 n7;

    switch (a0->stateLevel0) {
    case 0:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Stg30_InitBattle();
            Task_NextState1(a0);
        case 1:
            if (Stg30_Battle.entries[0].fromCity != 0) {
                switch (a0->stateLevel2) {
                case 0:
                default:
                    Snd_SetSlotContent(2, 0x19);
                    Task_NextState2(a0);
                case 1:
                    if (Snd_AnySlotLoading()) {
                        break;
                    }
                    Snd_PlayById(0x200, 1);
                    Task_NextState1(a0);
                    break;
                }
                break;
            }
            Task_NextState1(a0);
        case 2:
            Cd_FreeUnlockedFiles();
            Gpu_AllocPacketBufs(0x32000);
            Gfx_InitLights();
            Sys_SetFrameRate30();
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x40);
            Task_Create(9, &l->field_0, 0);
            Task_Create(0x503, &l->cameraTask, 0);
            Task_Create(0x50A, &l->fightBgTask, 0);
            Task_Create(0x505, &l->bannerTask, 0);
            Cd_QueueFile(0x1FD);
            Cd_QueueFile(0x25B);
            Cd_QueueFile(0xC6C);
            Cd_QueueFile(0x1A0);
            Cd_QueueFile(0x22B);
            Cd_QueueFile(0x45E);
            for (i = 0; i < 3; i++) {
                Mem_Zero(&((Stg30StateDigis *)&Stg30_Battle)->digis[i], 0x5C);
                if (Save_GameState.elems[i].state >= 3) {
                    ((Stg30StateDigis *)&Stg30_Battle)->digis[i] = Save_GameState.elems[i];
                    args[1] = i;
                    args[2] = Stg30_Battle.entries[i].hp == 0;
                    Task_Create(0x509, (s32 *)&l->actors[i], (s32)args);
                }
            }
            for (i = 3; i < 6; i++) {
                Mem_Zero(&((Stg30StateDigis *)&Stg30_Battle)->digis[i], 0x5C);
                Enemy_InitRosterEntry(Sys_State.modeArg, i - 3, &((Stg30StateDigis *)&Stg30_Battle)->digis[i],
                              (Out1DDA8 *)&Stg30_Battle.enemyAi[i]);
                if (Stg30_Battle.entries[i].digiId != 0) {
                    args[1] = i;
                    args[2] = 0;
                    Task_Create(0x509, (s32 *)&l->actors[i], (s32)args);
                }
            }
            Enemy_GetSetSummary((void *)Sys_State.modeArg, &out);
            Stg30_Battle.isBossFight = out.field_14;
            for (n1 = 0; n1 < 6; n1++) {
                Stg30_Battle.attackBase[n1] = Stg30_Battle.attackCur[n1] = Stg30_Battle.entries[n1].attack;
                Stg30_Battle.defenseBase[n1] = Stg30_Battle.defenseCur[n1] = Stg30_Battle.entries[n1].defense;
                Stg30_Battle.speedBase[n1] = Stg30_Battle.speedCur[n1] = Stg30_Battle.entries[n1].speed;
            }
            w->field_0 = 0;
            Task_NextState0(a0);
            break;
        }
        break;
    case 2:
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            t = Task_FindFirst(0x503, -1, -1);
            if (t != NULL && ((Actor *)t)->stateLevel0 == 1 && ((Actor *)t)->stateLevel1 == 1) {
                Task_NextState1(a0);
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                for (n2 = 0; n2 < 7; n2++) {
                    Stg30_Battle.turns[n2].noInterrupt = 0;
                    Stg30_Battle.turns[n2].noCounter = 0;
                    Stg30_Battle.turns[n2].skillId = 0;
                    Stg30_Battle.turns[n2].target = 0;
                    Stg30_Battle.turns[n2].turnType = 0;
                }
                for (n3 = 0; n3 < 6; n3++) {
                    Stg30_Battle.entries[n3].attack = Stg30_Battle.attackCur[n3];
                    Stg30_Battle.entries[n3].defense = Stg30_Battle.defenseCur[n3];
                    Stg30_Battle.entries[n3].speed = Stg30_Battle.speedCur[n3];
                }
                Stg30_ResetAllFightersHome((Stg30ListOwner *)a0);
                Stg30_ShowAllFighters((Stg30ListOwner *)a0);
                Task_Create(0x50B, &l->commandTask, 0);
                Task_NextState2(a0);
                break;
            case 1:
                Cd_QueueFile(0x22B);
                if (l->commandTask != 0) {
                    break;
                }
                if (D_80073CC4 == 1) {
                    switch (a0->stateLevel3) {
                    case 0:
                    default:
                        out.field_0 = 5;
                        out.field_4 = 1;
                        Task_Create(0x50C, &l->bannerTask, (s32)&out);
                        Task_NextState3(a0);
                    case 1:
                        if (l->bannerTask != 0) {
                            break;
                        }
                        Stg30_ResetPartyStats();
                        Gfx_FadeOutToBlack(0xF);
                        Task_NextState3(a0);
                    case 2:
                        if (++a0->stateLevel4 < 0x10) {
                            break;
                        }
                        Sys_State.nextGameMode = Sys_State.prevGameMode;
                        break;
                    }
                    break;
                }
                if (D_80073CC4 == 2) {
                    switch (a0->stateLevel3) {
                    case 0:
                    default:
                        out.field_0 = 5;
                        out.field_4 = 0;
                        Task_Create(0x50C, &l->bannerTask, (s32)&out);
                        Task_NextState3(a0);
                    case 1:
                        if (l->bannerTask != 0) {
                            break;
                        }
                        for (n4 = 0; n4 < 3; n4++) {
                            Stg30_Battle.turns[n4].skillId = 0;
                            Stg30_Battle.turns[n4].target = 0;
                            Stg30_Battle.turns[n4].turnType = 0;
                        }
                        D_80073CC4 = 0;
                        break;
                    }
                    break;
                }
                Task_NextState2(a0);
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                    Task_Create(0x505, &l->bannerTask, 1);
                    Task_NextState3(a0);
                case 1:
                    if (l->bannerTask != 0) {
                        break;
                    }
                    Stg30_Battle.interruptActive = 0;
                    if (Stg30_Battle.turns[6].turnType != 0) {
                        Task_NextState3(a0);
                    } else {
                        Task_SetState3(a0, 0xFF);
                    }
                    break;
                case 2:
                    Stg30_BuildItemScript();
                    Task_Create(0x50F, &l->scriptTask, 0);
                    Task_NextState3(a0);
                case 3:
                    if (l->scriptTask != 0) {
                        break;
                    }
                    sum = 0;
                    for (n5 = 3; n5 < 6; n5++) {
                        sum += Stg30_Battle.entries[n5].hp;
                    }
                    if (sum == 0) {
                        Stg30_ResetPartyStats();
                        Task_SetState1(a0, 4);
                        break;
                    }
                    Task_NextState3(a0);
                default:
                    a0->elapsed = 0;
                    Task_NextState2(a0);
                    break;
                }
                break;
            case 3:
                if (a0->elapsed < 0x3C) {
                    break;
                }
                Stg30_AiChooseEnemyTurns();
                Stg30_BuildTurnOrder();
                for (n6 = 5; n6 >= 0; n6--) {
                    Stg30_Battle.turns[n6].hpDelta = 0;
                }
                Task_NextState1(a0);
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_Battle.actionTaken = 0;
                Stg30_Battle.interruptActive = 0;
                Stg30_Battle.preventFlags[0] = 0;
                Stg30_Battle.preventFlags[1] = 0;
                Stg30_Battle.preventFlags[2] = 0;
                Stg30_Battle.preventFlags[3] = 0;
                Stg30_Battle.preventFlags[4] = 0;
                Stg30_Battle.preventFlags[5] = 0;
                w->field_4 = 0;
                Task_NextState2(a0);
            case 1:
                if (Stg30_Battle.entries[Stg30_TurnOrderGet(0)].hp == 0) {
                    Task_SetState2(a0, 4);
                    break;
                }
                Stg30_SaveFighterStates();
                if (!Stg30_UpdateTurnStatus(Stg30_TurnOrderGet(0))) {
                    Task_SetState2(a0, 4);
                    break;
                }
                Stg30_RetargetAction();
                w->counterQueued = 0;
                Stg30_Battle.interruptSlot = -1;
                if (Stg30_PrepareAction(Stg30_TurnOrderGet(0))) {
                    Task_Create(0x50F, &l->scriptTask, 1);
                }
                Task_NextState2(a0);
            case 2:
                if (Stg30_Battle.interruptSlot != -1) {
                    switch (a0->stateLevel3) {
                    case 0:
                    default:
                        Stg30_RestoreFighterStates();
                        Task_Destroy(&l->scriptTask);
                        Stg30_Battle.turns[Stg30_Battle.interruptSlot].target = Stg30_TurnOrderGet(0);
                        Stg30_TurnOrderInsert(0, Stg30_Battle.interruptSlot);
                        Stg30_Battle.statusMsg = 0;
                        if (Stg30_PrepareAction(Stg30_TurnOrderGet(0))) {
                            Task_Create(0x50F, &l->scriptTask, 1);
                        }
                        Task_NextState3(a0);
                    case 1:
                        if (l->scriptTask != 0) {
                            break;
                        }
                        Stg30_Battle.turns[Stg30_TurnOrderGet(0)].turnType = 0;
                        Stg30_TurnOrderRemove(0);
                        if (Stg30_Battle.entries[Stg30_TurnOrderGet(0)].hp == 0) {
                            Task_NextState2(a0);
                            Task_NextState2(a0);
                            break;
                        }
                        Stg30_Battle.statusMsg = 0;
                        if (Stg30_PrepareAction(Stg30_TurnOrderGet(0))) {
                            Task_Create(0x50F, &l->scriptTask, 1);
                        }
                        Task_NextState3(a0);
                    case 2:
                        if (l->scriptTask != 0) {
                            break;
                        }
                        Task_NextState2(a0);
                        Task_NextState2(a0);
                        break;
                    }
                    break;
                }
                if (l->scriptTask != 0) {
                    break;
                }
                Task_NextState2(a0);
                break;
            case 3:
                if (Stg30_Battle.actionTaken != 0 && Stg30_Battle.turns[Stg30_TurnOrderGet(0)].turnType == 1 &&
                    Stg30_Battle.turns[Stg30_TurnOrderGet(0)].noCounter == 0) {
                    for (i = 0; i < 6; i++) {
                        if (Stg30_Battle.lastTargets[i] == -1) {
                            continue;
                        }
                        if (Stg30_Battle.entries[Stg30_Battle.lastTargets[i]].hp == 0) {
                            continue;
                        }
                        j = Stg30_TurnOrderFind(Stg30_Battle.lastTargets[i]);
                        if (j == -1) {
                            continue;
                        }
                        k = Stg30_TurnOrderGet(j);
                        if (Stg30_Battle.turns[k].turnType != 2) {
                            continue;
                        }
                        Stg30_TurnOrderRemove(j);
                        Stg30_TurnOrderInsert(1, k);
                        if (Stg30_TurnOrderGet(0) < 3 && Stg30_Battle.lastTargets[i] < 3) {
                            Stg30_Battle.turns[k].target = Stg30_PickTarget(0, 1, Stg30_Battle.lastTargets[i]);
                        } else if (Stg30_TurnOrderGet(0) >= 3 && Stg30_Battle.lastTargets[i] >= 3) {
                            Stg30_Battle.turns[k].target = Stg30_PickTarget(0, 7, Stg30_Battle.lastTargets[i]);
                        } else {
                            Stg30_Battle.turns[k].target = Stg30_TurnOrderGet(0);
                        }
                        w->counterQueued = 1;
                    }
                }
                Task_NextState2(a0);
            case 4:
                m = Stg30_TurnOrderGet(0);
                if (m != Stg30_TurnOrderGet(1)) {
                    if (Stg30_Battle.turns[Stg30_TurnOrderGet(0)].turnType != 5) {
                        Stg30_Battle.turns[Stg30_TurnOrderGet(0)].turnType = 0;
                    }
                }
                flag = 0;
                do {
                    alive = 0;
                    for (n7 = 0; n7 < 3; n7++) {
                        if (Stg30_Battle.entries[n7].hp != 0) {
                            alive = 1;
                        } else {
                            Stg30_Battle.statusFlags[n7] = 0;
                        }
                    }
                    if (!alive) {
                        Task_SetState1(a0, 3);
                        flag = 1;
                        break;
                    }
                    alive = 0;
                    for (n7 = 3; n7 < 6; n7++) {
                        if (Stg30_Battle.entries[n7].hp != 0) {
                            alive = 1;
                        } else {
                            Stg30_Battle.statusFlags[n7] = 0;
                        }
                    }
                    if (!alive) {
                        Task_SetState1(a0, 4);
                        flag = 1;
                    }
                } while (0);
                if (flag) {
                    Stg30_ResetPartyStats();
                    break;
                }
                Stg30_TurnOrderRemove(0);
                v = Stg30_TurnOrderGet(0);
                if (v != -1) {
                    if (w->counterQueued == 0) {
                        if (Stg30_Battle.turns[v].turnType == 2) {
                            Stg30_Battle.turns[v].turnType = 1;
                        }
                    }
                    Task_SetState2(a0, 1);
                    break;
                }
                Task_SetState1(a0, 1);
                Stg30_Battle.interruptActive = 1;
                for (n7 = 5; n7 >= 0; n7--) {
                    Stg30_Battle.turns[n7].turnType = 0;
                }
                break;
            }
            break;
        case 3:
            Stg30_BattleLostUpdate((Stg30ListOwner *)a0);
            break;
        case 4:
            Stg30_BattleWonUpdate(a0);
            break;
        }
        break;
    }
}

void Stg30_BattleDestroy(Actor *a0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (((Stg30StateDigis *)&Stg30_Battle)->digis[i].state >= 3) {
            Save_GameState.elems[i] = ((Stg30StateDigis *)&Stg30_Battle)->digis[i];
        }
    }
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(a0);
}
