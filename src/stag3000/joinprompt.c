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
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"
#include "stag3000/battlestate.h"
#include "stag3000/fighter.h"
#include "stag3000/fightmsg.h"
#include "stag3000/popup.h"
#include "stag3000/interruptselect.h"
#include "stag3000/camera.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_JoinPromptInit(Actor *a0, s32 *args);
void Stg30_JoinPromptUpdate(Actor *a0);
void Stg30_JoinPromptDraw(Actor *a0);

Halves Stg30_JoinPromptTextPos[] = { { 0x24, 0xB2 }, { 0x23, 0xBF } };
u8 Stg30_MemoryCapacity[] = { 4, 5, 6, 7, 8, 0xC };
TaskDesc Stg30_JoinPromptDesc = {
    (TaskInitFn)Stg30_JoinPromptInit, Stg30_JoinPromptUpdate, Task_DefaultDestroy, Stg30_JoinPromptDraw, 0x14, 4,
};

void Stg30_JoinPromptInit(Actor *a0, s32 *args) {
    s32 idx = args[0];

    ((Stg30JoinPromptWork *)a0->work)->index = idx;
    a0->digiId = Stg30_Battle.entries[idx].digiId;
}

void Stg30_JoinCreateDigi(Actor *a0, s32 a1) {
    DigiRosterEntry *e = &D_8005F398;

    Digi_InitFromTable(Sys_State.modeArg, ((Stg30WorkWord *)a0->work)->field_0 - 3, e);
    if (a1 != 0) {
        e->state = 1;
    }
}

void Stg30_JoinPromptUpdate(Actor *a0) {
    Stg30JoinPromptWork *w = (Stg30JoinPromptWork *)a0->work;
    Stg30GameRoster *g;
    TaskEntry *t;
    Stg30Pair args;
    s32 i;
    s32 cnt;
    s32 n;
    s32 j;
    s32 *p;

    p = (s32 *)a0->u34.children;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->text, 2);
        w->fighter = (Actor *)Task_FindFirst(0x509, -1, w->index);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            ((void (*)(s32))Stg30_SetCameraShot)(w->index + 2);
            Stg30_FighterSetVisible(w->fighter, 1);
            a0->elapsed = 0;
            Task_NextState1(a0);
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                if (a0->elapsed < 0x15) {
                    break;
                }
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->param < 3) {
                        Stg30_FighterSetVisible((Actor *)t, 0);
                        Stg30_FighterQueueHomeReset((Actor *)t);
                    }
                }
                Task_NextState2(a0);
                break;
            case 1:
                if (a0->elapsed < 0x78) {
                    break;
                }
                Task_SetState0(w->fighter, 2);
                Task_SetState1(w->fighter, 0xB);
                Task_NextState1(a0);
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                w->windowVisible = 1;
                Text_OpenPacked(&w->text[0], (s32)Digi_GetDefaultName(a0->digiId), 0, Stg30_JoinPromptTextPos[0]);
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018D), 0x81, Stg30_JoinPromptTextPos[1]);
                Flag_Set(0x10, 0);
                Task_NextState2(a0);
                break;
            case 1:
                if (!Flag_Test(0x10)) {
                    break;
                }
                if (Flag_Test(0x11)) {
                    Task_SetState1(a0, 8);
                    break;
                }
                Task_SetState1(a0, 3);
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                cnt = 0;
                for (j = 0; j < 0x24; j++) {
                    if (Save_GameState.elems[j].state >= 2) {
                        cnt++;
                    }
                }
                n = Stg30_MemoryCapacity[D_8005E650 - 0x2F] - Dung_StatePtr->memBugCount;
                if (n > 0 && cnt < n) {
                    Task_SetState1(a0, 4);
                    break;
                }
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018E), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
                break;
            case 1:
                if (Pad_State[0].cross <= 0) {
                    break;
                }
                g = (Stg30GameRoster *)&Save_GameState;
                if (g->field_4A == 0) {
                    Task_SetState1(a0, 6);
                    break;
                }
                if (g->dmTransferBroken != 0) {
                    Task_SetState1(a0, 7);
                    break;
                }
                cnt = 0;
                for (i = 0; i < 0x24; i++) {
                    if (g->elems[i].state == 1) {
                        cnt++;
                    }
                }
                if (cnt < 0x18) {
                    Task_SetState1(a0, 5);
                    break;
                }
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0190), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
                break;
            case 2:
                if (Pad_State[0].cross > 0) {
                    Task_SetState1(a0, 8);
                }
                break;
            }
            break;
        case 4: {
            s32 *q = (s32 *)a0->u34.children;

            switch (a0->stateLevel2) {
            case 0:
            default:
                w->windowVisible = 0;
                Text_Close(&w->text[0]);
                Text_Close(&w->text[1]);
                Stg30_JoinCreateDigi(a0, 0);
                args.field_0 = 0;
                args.field_4 = 0x23;
                Task_Create(0x16, q, (s32)&args);
                Task_NextState2(a0);
                break;
            case 1:
                if (*q != 0) {
                    break;
                }
                Digi_SortRoster();
                Task_NextState0(a0);
                break;
            }
            break;
        }
        case 5:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018F), 0x81, Stg30_JoinPromptTextPos[1]);
                Flag_Set(0x10, 0);
                Task_NextState2(a0);
                break;
            case 1:
                if (!Flag_Test(0x10)) {
                    break;
                }
                if (!Flag_Test(0x11)) {
                    Task_NextState2(a0);
                    break;
                }
                Task_SetState1(a0, 8);
                break;
            case 2:
                w->windowVisible = 0;
                Text_Close(&w->text[0]);
                Text_Close(&w->text[1]);
                Stg30_JoinCreateDigi(a0, 1);
                args.field_0 = 0;
                args.field_4 = 0x23;
                Task_Create(0x16, p, (s32)&args);
                Task_NextState2(a0);
                break;
            case 3:
                if (*p != 0) {
                    break;
                }
                Digi_SortRoster();
                Task_NextState0(a0);
                break;
            }
            break;
        case 7:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0191), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
                break;
            case 1:
                if (Pad_State[0].cross > 0) {
                    Task_SetState1(a0, 8);
                }
                break;
            }
            break;
        case 6:
        case 8:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Snd_PlayById(0x1C, 0);
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0192), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
            case 1:
                if (Pad_State[0].cross > 0) {
                    Task_NextState0(a0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        Text_CloseArray(w->text, 2);
        Task_NextState0(a0);
        break;
    }
}

void Stg30_JoinPromptDraw(Actor *a0) {
    if (((Stg30JoinPromptWork *)a0->work)->windowVisible != 0) {
        Gfx_DrawParts(Cd_GetFileEntry(0x1A10017));
    }
}
