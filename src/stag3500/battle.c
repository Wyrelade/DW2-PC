#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_BattleUpdate(Actor *arg0);
void Stg35_BattleDestroy(Actor *arg0);

TaskDesc Stg35_BattleDesc = { 0, Stg35_BattleUpdate, Stg35_BattleDestroy, 0, 0x10, 0x50 };

void Stg35_SetDigiAction(Actor *arg0, s32 arg1, s32 arg2) {
    arg0->stateLevel0 = 2;
    arg0->stateLevel1 = arg1;
    arg0->stateLevel2 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel4 = arg2;
}

void Stg35_ShowWinnerSide(Stg35ChildOwner *arg0, s32 arg1) {
    Stg35BattleChildren *l = arg0->children;
    s32 i;

    for (i = 0; i < 6; i++) {
        Actor *a = P32(Actor, l->fighters[i]);

        if (a != NULL) {
            if (arg1 == 0) {
                if (i < 3) {
                    Stg35_FighterSetVisible(a, 1);
                    Stg35_FighterQueueHomeReset(P32(Actor, l->fighters[i]));
                } else {
                    Stg35_FighterSetVisible(a, 0);
                }
            } else {
                if (i >= 3) {
                    Stg35_FighterSetVisible(a, 1);
                    Stg35_FighterQueueHomeReset(P32(Actor, l->fighters[i]));
                } else {
                    Stg35_FighterSetVisible(a, 0);
                }
            }
        }
    }
}

void Stg35_ShowAllDigi(Stg35ChildOwner *arg0) {
    Stg35BattleChildren *l = arg0->children;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (P32(Actor, l->fighters[i]) != NULL) {
            Stg35_FighterSetVisible(P32(Actor, l->fighters[i]), 1);
            Stg35_FighterQueueHomeReset(P32(Actor, l->fighters[i]));
        }
    }
}

void Stg35_BattleUpdate(Actor *arg0) {
    Stg35BattleWork *w = (Stg35BattleWork *)arg0->work;
    PTR32(Actor) *c = (PTR32(Actor) *)arg0->u34.children;
    Stg35Arg3 a;
    s32 buf[6];
    s32 cnt[2];
    Actor *e;
    Actor *e2;
    s32 i;
    s32 k;
    s32 n;
    s32 m;
    s32 j;
    s32 r;
    s32 sum;
    s32 wait;
    s32 f;

    switch (arg0->stateLevel0) {
    case 0:
        Snd_PlayById(0x102, 1);
        Stg35_ClearBattle();
        Cd_FreeUnlockedFiles();
        Gpu_AllocPacketBufs(0x32000);
        Gfx_InitLights();
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, (s32 *)&c[0], 0);
        Task_Create(0x706, (s32 *)&c[4], 0);
        Task_Create(0x704, (s32 *)&c[5], 0);
        Cd_QueueFile(0x1FD);
        Cd_QueueFile(0x25B);
        Cd_QueueFile(0xD3F);
        Cd_QueueFile(0xD41);
        Cd_QueueFile(0xD93);
        for (k = 0; k < 6; k++) {
            Stg35_Battle.rec[k] = Save_GameState.elems[k];
        }
        for (j = 0; j < 6; j++) {
            a.field_8 = 0;
            a.field_0 = Stg35_Battle.rec[j].digiId;
            a.field_4 = j;
            Task_Create(0x707, (s32 *)&c[11 + j], (s32)&a);
        }
        for (j = 0; j < 6; j++) {
            Stg35_BuildCommandList(j);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (P32(Actor, c[4])->stateLevel0 == 1 && P32(Actor, c[4])->stateLevel1 == 1) {
                Task_Create(0x708, (s32 *)&c[19], 0);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Stg35_ShowAllDigi((Stg35ChildOwner *)arg0);
                Stg35_SetCameraShot(0x18);
                Stg35_BuildTurnOrder();
                e2 = (Actor *)Task_FindFirst(0x708, -1, -1);
                if (e2 != NULL) {
                    Task_SetState1(e2, 1);
                }
                Task_NextState2(arg0);
            case 2:
                Task_Create(0x70C, (s32 *)&c[17], w->round);
                Task_NextState2(arg0);
            case 3:
                if (P32(Actor, c[17]) == NULL) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 2:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                if (Stg35_Battle.rec[Stg35_TurnOrderGet(0)].hp == 0) {
                    Task_NextState1(arg0);
                    break;
                }
                Task_NextState2(arg0);
            case 1:
                switch (arg0->stateLevel3) {
                case 0:
                default:
                    Stg35_SetCameraShot(Stg35_TurnOrderGet(0) + 0xA);
                    for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                        if (e->param == Stg35_TurnOrderGet(0)) {
                            Stg35_FighterSetVisible(e, 1);
                            Stg35_FighterQueueHomeReset(e);
                        } else {
                            Stg35_FighterSetVisible(e, 0);
                        }
                    }
                    for (m = 0; m < 6; m++) {
                        buf[5 - m] = Stg35_Battle.actions[Stg35_TurnOrderGet(0)].skills[m];
                    }
                    Stg35_HudStartGauge(Stg35_TurnOrderGet(0) >= 3, buf);
                    Task_NextState3(arg0);
                    break;
                case 1:
                    if (Stg35_HudGetGaugeStatus() == 1) {
                        break;
                    }
                    if (Stg35_HudGetGaugeStatus() == 2) {
                        Task_SetState1(arg0, 3);
                        break;
                    }
                    f = Stg35_TurnOrderGet(0);
                    Stg35_SetChosenAction(f, Stg35_HudGetGaugeLevel());
                    Task_NextState2(arg0);
                    break;
                }
                break;
            case 2:
                if (Stg35_PrepareAction(Stg35_TurnOrderGet(0)) != 0) {
                    Task_Create(0x709, (s32 *)&c[18], 1);
                }
                Task_NextState2(arg0);
            case 3:
                if (P32(Actor, c[18]) == NULL) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        lose:
            Task_SetState1(arg0, 3);
            r = 1;
            w->winnerSide = r;
            goto chk;
        case 3:
            r = 0;
            sum = 0;
            for (n = 0; n < 3; n++) {
                sum += Stg35_Battle.rec[n].hp;
            }
            if (sum == 0) {
                goto lose;
            }
            sum = 0;
            for (n = 3; n < 6; n++) {
                sum += Stg35_Battle.rec[n].hp;
            }
            if (sum == 0) {
                Task_SetState1(arg0, 4);
                r = 1;
                w->winnerSide = 0;
            }
        chk:
            if (r == 0) {
                Stg35_TurnOrderRemove(0);
                if (Stg35_TurnOrderGet(0) == -1) {
                if (++w->round == 3) {
                memset((u8 *)cnt, 0, 8);
                for (n = 0; n < 3; n++) {
                    if (Stg35_Battle.rec[n].hp != 0) {
                        cnt[0]++;
                    }
                }
                for (n = 3; n < 6; n++) {
                    if (Stg35_Battle.rec[n].hp != 0) {
                        cnt[1]++;
                    }
                }
                if (cnt[0] == cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;
                    for (n = 0; n < 3; n++) {
                        if (Stg35_Battle.rec[n].hp != 0) {
                            cnt[0] += Stg35_Battle.rec[n].hp;
                        }
                    }
                    for (n = 3; n < 6; n++) {
                        if (Stg35_Battle.rec[n].hp != 0) {
                            cnt[1] += Stg35_Battle.rec[n].hp;
                        }
                    }
                }
                if (cnt[0] >= cnt[1]) {
                    w->winnerSide = 0;
                } else {
                    w->winnerSide = 1;
                }
                } else {
                    Task_SetState1(arg0, 1);
                    break;
                }
                } else {
                    Task_SetState1(arg0, 2);
                    break;
                }
            }
            Task_NextState0(arg0);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel1) {
        nf:
            wait = 1;
            goto done;
        case 0:
        default:
            Snd_PlayById(0x202, 1);
            Stg35_SetCameraShot(w->winnerSide + 0x19);
            Stg35_ShowWinnerSide((Stg35ChildOwner *)arg0, w->winnerSide);
            arg0->elapsed = 0;
            Task_NextState1(arg0);
        case 1:
            wait = 0;
            for (i = w->winnerSide * 3; i < w->winnerSide * 3 + 3; i++) {
                if (Stg35_Battle.rec[i].hp != 0) {
                    f = Digi_GetAnimFile(Stg35_Battle.rec[i].digiId, 8);
                    Cd_QueueFile(f);
                    if (Cd_GetFileState(f) != 3) {
                        goto nf;
                    }
                }
            }
        done:
            if (wait != 0) {
                break;
            }
            if (arg0->elapsed < 0x3C) {
                break;
            }
            for (j = w->winnerSide * 3; j < w->winnerSide * 3 + 3; j++) {
                if (Stg35_Battle.rec[j].hp != 0) {
                    Task_SetState01(P32(Actor, c[11 + j]), 2, 2);
                }
            }
            Task_NextState1(arg0);
            arg0->elapsed = 0;
        case 2:
            if (arg0->elapsed < 0x78) {
                break;
            }
            Task_Create(0x70D, (s32 *)&c[10], w->winnerSide);
            Task_NextState1(arg0);
        case 3:
            if (arg0->elapsed < 0x78) {
                break;
            }
            if (Pad_State[0].cross > 0 || Pad_State[1].cross > 0) {
                Task_NextState1(arg0);
            }
            break;
        case 4:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState1(arg0);
        case 5:
            if (++arg0->stateLevel2 >= 0x10) {
                Sys_State.nextGameMode = 0x701;
                Task_NextState1(arg0);
            }
            break;
        case 6:
            break;
        }
        break;
    }
}

void Stg35_BattleDestroy(Actor *arg0) {
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(arg0);
}
