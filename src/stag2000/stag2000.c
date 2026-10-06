#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_StageMain(Actor *a);

TaskDesc Stg20_StageMainDesc = { 0, Stg20_StageMain, Task_DefaultDestroy, 0, 0x10, 0x70 };

void Stg20_StageMain(Actor *a) {
    Stg20MainWork *w = (Stg20MainWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    Stg20Spawn sp;
    Stg20Start *st;
    Stg20BytePair *src;
    s32 id;
    s32 n;
    s32 k;
    s32 task;

    switch (a->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        if (Sys_GameMode[0] != 0x32F) {
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        } else {
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        }
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x1E);
        Task_Create(9, &slot[0], 0);
        Flag_SetTableFile(Stg20_GetMapInfo()->flagTableFile);
        Task_Create(0x308, &slot[5], 0);
        if (Sys_State.gameMode < 0x32A) {
            st = &((Stg20Start *)Stg20_GetMapInfo()->startRecs)[Sys_State.modeArg];
            sp.id = 0x1F4;
            sp.blk[0].x = st->x;
            sp.blk[0].y = st->y;
            sp.blk[1].x = 0;
            sp.blk[1].y = 0;
            sp.facing = st->dir;
            Task_Create(0x302, &slot[4], (s32)&sp);
            if (Stg20_GetMapInfo()->flagTableFile != 0) {
                n = 0;
                for (id = Flag_FirstPassingEntry(); id != -1; id = Flag_NextPassingEntry()) {
                    src = (Stg20BytePair *)Flag_GetEntryPosList(id);
                    sp.id = Flag_GetEntryDigiId(id);
                    sp.facing = Flag_GetEntryDir(id);
                    sp.flagEntry = id;
                    for (k = 0; k < 6; k++) {
                        sp.blk[k].x = src[k].x != 0xFF ? src[k].x : 0;
                        sp.blk[k].y = src[k].y != 0xFF ? src[k].y : 0;
                    }
                    Task_Create(0x302, &slot[6 + n], (s32)&sp);
                    n++;
                }
            }
            Task_Create(0x304, &slot[26], 0);
            Task_Create(0x301, &slot[2], Stg20_GetMapInfo()->bgFileId);
            switch (Sys_GameMode[0]) {
            case 0x31D:
                Task_Create(0x31C, &slot[27], 0);
                break;
            case 0x320:
                Task_Create(0x31C, &slot[27], 1);
                break;
            case 0x326:
                Task_Create(0x31C, &slot[27], 2);
                break;
            case 0x327:
                Task_Create(0x31C, &slot[27], 3);
                break;
            }
        } else if (Sys_State.gameMode < 0x32F) {
            w->areaSelect = 1;
            Stg20_MenuState.menuAllowed = 1;
            Task_Create(0x305, &slot[2], Stg20_GetMapInfo()->bgFileId);
            Task_Create(0x306, &slot[3], 0);
        } else {
            if (Sys_State.gameMode < 0x330) {
                task = 0x307;
            } else if (Sys_State.gameMode < 0x333) {
                task = 0x314;
            } else {
                task = 0x319;
            }
            Task_Create(task, &slot[2], 0);
        }
        Gfx_InitLights();
        ((Stg20MainWork *)a->work)->field_0 = -1;
        Stg20_MenuState.talkActive = 0;
        if (Stg20_GetMapInfo()->sndSlotContent != 0) {
            Snd_UnloadSlot(2);
            Snd_SetSlotContent(1, Stg20_GetMapInfo()->sndSlotContent);
        }
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        if (Sys_State.fadeLevel != 0) {
            Mem_Zero(Pad_State, 0x40);
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Flag_Set(0x10, 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (w->bgmOn == 0 && Snd_AnySlotLoading() == 0) {
                if (Stg20_GetMapInfo()->bgmId != -1) {
                    Snd_PlayById(Stg20_GetMapInfo()->bgmId, 1);
                }
                w->bgmOn = 1;
            }
            if (((Stg20BlinkTask *)a)->frameCount == 10) {
                Cd_QueueFile(0x312);
                Cd_QueueFile(0x315);
                Cd_QueueFile(0x325);
            }
            if (((Stg20BlinkTask *)a)->frameCount == 15
                && ((Sys_State.gameMode == 0x307 && Flag_Test(0x320) == 0)
                    || (Sys_GameMode[0] == 0x301 && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x320) == 1 && Flag_Test(0x2336) == 1)
                    || (Sys_GameMode[0] == 0x304 && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x32A) == 1)
                    || (Sys_GameMode[0] == 0x308 && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x320) == 1 && Flag_Test(0x32B) == 1)
                    || (Sys_GameMode[0] == 0x30C && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x32C) == 1))) {
                Cd_QueueFile(0x1FD);
                Cd_QueueFile(0x1A1);
                Cd_QueueFile(0x314);
                Cd_QueueFile(0x25C);
            }
            if (Pad_State[0].circle > 0 && Stg20_MenuState.talkActive == 0 && Sys_GameMode[0] < 0x32F
                && Stg20_MenuState.menuAllowed != 0 && Snd_AnySlotLoading() == 0) {
                Task_Create(0xB, &slot[1], 0);
                a->childCount = 2;
                Task_NextState1(a);
                if (w->areaSelect != 0) {
                    Stg20_AreaSelectShowName((Actor *)slot[3], 0);
                }
            }
            break;
        case 1:
            if (slot[1] == 0) {
                a->childCount = 0x1C;
                if (w->areaSelect != 0 && Menu_TopMenuResult != 0) {
                    Gfx_FadeSetBlack();
                    Sys_State.nextGameMode = 0x601;
                    Task_NextState0(a);
                } else {
                    Gfx_FadeInFromBlack(0x20);
                    Task_SetState1(a, 0);
                }
                if (w->areaSelect != 0) {
                    Stg20_AreaSelectShowName((Actor *)slot[3], 1);
                }
            }
            break;
        }
        break;
    }
}

Stg20MapFile *Stg20_GetMapInfo(void) {
    Stg20MapFile *f = (Stg20MapFile *)Cd_GetFileEntry(((Stg20Mode *)&Sys_State.gameMode)->lo + 0x308FFFF);
    s32 base;

    if (f->loaded == 0) {
        base = Cd_GetFileOrNull(0x309);
        f->loaded = 1;
        f->exits += base;
        f->startRecs += base;
        f->bits += base;
        f->stepSndBits = f->stepSndBits != 0 ? f->stepSndBits + base : 0;
    }
    return f;
}
