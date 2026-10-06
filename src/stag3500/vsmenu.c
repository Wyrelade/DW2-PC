#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_VsMenuUpdate(Actor *arg0);
void Stg35_VsMenuDestroy(Actor *arg0);
void Stg35_VsMenuDraw(Actor *arg0);

s32 Stg35_VsMenuPromptMsgs[] = { 0x1B3, 0x1C4, 0x1B4 };
s32 Stg35_VsMenuPhaseMasks[] = { 0x2C, 0x4A, 0x32 };
TaskDesc Stg35_VsMenuDesc = { 0, Stg35_VsMenuUpdate, Stg35_VsMenuDestroy, Stg35_VsMenuDraw, 0x44, 8 };

void Stg35_VsMenuUpdate(Actor *arg0) {
    Stg35VsMenuWork *w = (Stg35VsMenuWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 i;
    u16 pad;
    SysState *g;

    switch (arg0->stateLevel0) {
    case 0:
        switch (Sys_State.modeArg) {
        case 0:
        default:
            for (i = 4; i >= 0; i--) {
                Save_GameState.elems[i].state = 0;
            }
            w->phase = 0;
            break;
        case 1:
            w->phase = 2;
            break;
        case 2:
            w->phase = 1;
            break;
        }
        if (Save_GameState.elems[0].state != 0) {
            w->p1Loaded = 1;
        }
        if (Save_GameState.elems[3].state != 0) {
            w->p2Loaded = 1;
        }
        Gpu_AllocPacketBufs(0x32000);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, &slot[0], 0);
        Task_Create(0x702, &slot[1], 0);
        for (i = 0; i < 4; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        for (i = 0; i < 7; i++) {
            Stg35_TextAlloc(&w->text[i]);
        }
        Snd_UnloadSlot(2);
        Snd_SetSlotContent(1, 0x18);
        Task_NextState0(arg0);
        break;
    case 1:
        if (w->musicStarted == 0 && Snd_AnySlotLoading() == 0) {
            w->musicStarted = 1;
            Snd_PlayById(0x103, 1);
            Snd_SetSlotContent(2, 0x19);
        }
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Stg35_PartsSetFile(&w->load[0], 0xD3F0001);
            Stg35_PartsStartOpen(&w->load[0]);
            Stg35_PartsSetFile(&w->load[1], 0x3120003);
            Stg35_PartsStartOpen(&w->load[1]);
            if (w->p1Loaded != 0) {
                Stg35_PartsSetFile(&w->load[2], 0xD3F0003);
                Stg35_PartsStartOpen(&w->load[2]);
                Stg35_PartsSetNumber(&w->load[2], 2, 3, (s16)Save_GameState.elems[0].maxHp);
                Stg35_PartsSetNumber(&w->load[2], 0x10, 3, (s16)Save_GameState.elems[0].maxMp);
                Stg35_PartsSetNumber(&w->load[2], 4, 3, (s16)Save_GameState.elems[1].maxHp);
                Stg35_PartsSetNumber(&w->load[2], 0x20, 3, (s16)Save_GameState.elems[1].maxMp);
                Stg35_PartsSetNumber(&w->load[2], 8, 3, (s16)Save_GameState.elems[2].maxHp);
                Stg35_PartsSetNumber(&w->load[2], 0x40, 3, (s16)Save_GameState.elems[2].maxMp);
            }
            if (w->p2Loaded != 0) {
                Stg35_PartsSetFile(&w->load[3], 0xD3F0004);
                Stg35_PartsStartOpen(&w->load[3]);
                Stg35_PartsSetNumber(&w->load[3], 2, 3, (s16)Save_GameState.elems[3].maxHp);
                Stg35_PartsSetNumber(&w->load[3], 0x10, 3, (s16)Save_GameState.elems[3].maxMp);
                Stg35_PartsSetNumber(&w->load[3], 4, 3, (s16)Save_GameState.elems[4].maxHp);
                Stg35_PartsSetNumber(&w->load[3], 0x20, 3, (s16)Save_GameState.elems[4].maxMp);
                Stg35_PartsSetNumber(&w->load[3], 8, 3, (s16)Save_GameState.elems[5].maxHp);
                Stg35_PartsSetNumber(&w->load[3], 0x40, 3, (s16)Save_GameState.elems[5].maxMp);
            }
            Stg35_TextSetLayout(&w->text[0], 0x101, 0x10, 0xBA);
            if (w->p1Loaded != 0) {
                for (i = 0; i < 3; i++) {
                    Stg35_TextSetLayout(&w->text[i + 1], 0, 0x15, i * 0x22 + 0x4E);
                    Stg35_TextSetString((Stg35PartsHandle *)&w->text[i + 1], (s32)Save_GameState.elems[i].name);
                    Stg35_TextOpen(&w->text[i + 1]);
                }
            }
            if (w->p2Loaded != 0) {
                for (i = 0; i < 3; i++) {
                    Stg35_TextSetLayout(&w->text[i + 4], 0, 0xC9, i * 0x22 + 0x4E);
                    Stg35_TextSetString((Stg35PartsHandle *)&w->text[i + 4], (s32)Save_GameState.elems[i + 3].name);
                    Stg35_TextOpen(&w->text[i + 4]);
                }
            }
            w->promptDirty = 1;
            Task_NextState1(arg0);
        case 1:
            do {
                switch (w->phase) {
                case 0:
                default:
                    pad = Pad_State[0].pressed;
                    break;
                case 1:
                    pad = Pad_State[0].pressed | Pad_State[1].pressed;
                    break;
                case 2:
                    pad = Pad_State[1].pressed;
                    break;
                }
                if (pad & 0x10) {
                    Snd_PlayById(0xB, 0);
                    w->backPressed = 1;
                    Task_NextState0(arg0);
                    break;
                }
                if (pad & 0x40) {
                    Snd_PlayById(0xE, 0);
                    w->backPressed = 0;
                    Task_NextState0(arg0);
                }
            } while (0);
            if (w->promptDirty != 0) {
                w->promptDirty = 0;
                Stg35_TextSetSysMsg(&w->text[0], Stg35_VsMenuPromptMsgs[w->phase]);
                Stg35_TextOpen(&w->text[0]);
            }
            Stg35_PartsHideByMask(&w->load[0], Stg35_VsMenuPhaseMasks[w->phase]);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        case 0:
        default:
            for (i = 0; i < 4; i++) {
                Stg35_PartsStartScaleOut(&w->load[i]);
            }
            for (i = 0; i < 7; i++) {
                Stg35_TextClose(&w->text[i]);
            }
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
        case 1:
            break;
        }
        g = &Sys_State;
        if (g->fadeLevel == 0xFF) {
            s32 v;

            switch (w->phase) {
            case 0:
            default:
                v = w->backPressed == 0 ? 0x603 : 0x401;
                break;
            case 1:
                v = w->backPressed == 0 ? 0x702 : 0x701;
                break;
            case 2:
                v = w->backPressed == 0 ? 0x604 : 0x701;
                break;
            }
            g->nextGameMode = v;
        }
        break;
    }
}

void Stg35_VsMenuDestroy(Actor *arg0) {
    Stg35VsMenuWork *w = (Stg35VsMenuWork *)arg0->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        Stg35_PartsFree(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        Stg35_TextFree(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_VsMenuDraw(Actor *arg0) {
    Stg35VsMenuWork *w = (Stg35VsMenuWork *)arg0->work;

    Stg35_PartsSetPalette(&w->load[0], 0x2A, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    Stg35_PartsDraw(&w->load[0]);
    Stg35_PartsDraw(&w->load[1]);
    if (w->p1Loaded != 0) {
        Stg35_PartsDraw(&w->load[2]);
    }
    if (w->p2Loaded != 0) {
        Stg35_PartsDraw(&w->load[3]);
    }
}
