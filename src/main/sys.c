#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"
#include "main/digistatus.h"
#include "main/skilllist.h"
#include "main/spawnlist.h"
#include "main/winframe.h"
#include "main/sound.h"
#include "main/text.h"
#include "main/gpu.h"
#include "main/fade.h"
#include "main/ot.h"
#include "main/primbuf.h"
#include "main/texslot.h"
#include "main/parts.h"
#include "main/digibase.h"
#include "main/gamedata.h"
#include "main/flagtable.h"
#include "main/digidata.h"
#include "main/shadow.h"
#include "main/skill.h"
#include "main/anim.h"
#include "main/model.h"
#include "main/12550.h"
#include "main/flags.h"
#include "main/savedata.h"
#include "main/mem.h"
#include "main/pad.h"

/* RCS id of the original sys.c. */
const char Sys_RcsId[] = "$Id: sys.c,v 1.140 1998/01/12 07:52:27 noda Exp yos $";

/* Small data in retail order. Retail reaches the Sys_ ones with %gp_rel; the others are read
 * elsewhere (model.c Gfx_ZeroSVector, 187C/77DC Gfx_NeutralRgb, STAG1000 Sys_MovieActive). */
s32 Sys_VSyncsSinceFlip = 0;
RECT Sys_BootImageRect = { 0, 0, 320, 480 };
s32 Sys_LastVSyncTime = 0;
/* Unreferenced. */
s32 D_8005073C = 0x10000;
u8 D_80050740 = 0;
/* 1 while the stag1000 movie task runs (written only). */
u8 Sys_MovieActive = 0;
/* Unreferenced. */
s16 D_80050742 = 0;
GfxQuadVert Gfx_ZeroSVector[1] = { 0 };
Halves Gfx_NeutralRgb = { 0x8080, 0x80 };
s32 Sys_FlipPending;
s32 Rand_Index;
/* .bss */
SysState Sys_State;
/* Scalar view of Sys_State.gameMode for Stg20_StageMain: its other Sys_State reads share one base
 * register, these 7 reads do not (retail code). */
DATA_LABEL(Sys_GameMode, Sys_State, 0x18);

/* Rand_Next's table of 0x1000 random halfwords. */
INCLUDE_BIN(Rand_Table, "assets/main/rand_table.bin");
/* Gfx_ZeroVector and the matrices sit in this unit's data in retail order (E280 and model.c
 * use them). */
s32 Gfx_ZeroVector[4] = { 0 };
Blk20 Gfx_IdentityMatrix = { { { { 0x1000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
/* Unreferenced: the same with x, y, then x and y scaled by 2. */
Blk20 Gfx_MatrixScaleX2 = { { { { 0x2000, 0, 0 }, { 0, 0x1000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
Blk20 Gfx_MatrixScaleY2 = { { { { 0x1000, 0, 0 }, { 0, 0x2000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };
Blk20 Gfx_MatrixScaleXY2 = { { { { 0x2000, 0, 0 }, { 0, 0x2000, 0 }, { 0, 0, 0x1000 } } }, { 0 }, { 0, 0, 0 } };

void Sys_VSyncHandler(void) {
    s32 t = Sys_State.vsyncWait - (Sys_State.vsyncWait != 0);

    if (Sys_FlipPending != 0 && Sys_VSyncsSinceFlip >= t) {
        Sys_State.bufIndex = (Sys_State.bufIndex == 0);
        PutDispEnv(&Sys_State.disp[Sys_State.bufIndex]);
        PutDrawEnv(&Sys_State.draw[Sys_State.bufIndex]);
        Gpu_DrawOt(Sys_State.bufIndex ^ 1);
        Sys_FlipPending = 0;
        Sys_VSyncsSinceFlip = 0;
    } else {
        Sys_VSyncsSinceFlip++;
    }
    SsSeqCalledTbyT();
}

void Sys_Main(void) {
    SysClearRect r;
    GsIMAGE tim;
    u8 buf;
    s32 slot;
    s32 i;
    s32 t;
    s32 d;
    s32 u;

    func_80010D74();
    ResetCallback();
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    VSyncCallback((s32)Sys_VSyncHandler);
    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x1FF;
    ClearImage((s32)&r, 0, 0, 0);
    DrawSync(0);
    GsInitGraph(0x140, 0xF0, 1, 1, 0);
    GsInit3D();
    SsInit();
    InitGeom();
    Gpu_InitDoubleBuffer(0x140, 0x280, 1, 0);
    PutDrawEnv(&Sys_State.draw[0]);
    PutDispEnv(&Sys_State.disp[0]);
    VSync(0);
    GsGetTimInfo((u32 *)(Ovl_LoadAddr + 4), &tim);
    VSync(0);
    LoadImage((s32)&Sys_BootImageRect, (s32)tim.paddr);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);
    CdInit();
    CdSetDebug(0);
    SetGraphDebug(0);
#ifdef DW2_NATIVE
    Mem_InitHeap(Mem_HeapStart, (s32)PS1_RAM(0x801FF000) - (s32)Mem_HeapStart);
#else
    Mem_InitHeap(Mem_HeapStart, 0x801FF000 - (s32)Mem_HeapStart);
#endif
    Cd_ClearFileCache();
    Snd_Init();
    Sys_State.frameCount = 0;
    Sys_State.vsyncWait = 0;
    Sys_State.bufIndex = 1;
    Gpu_FreePrimBufs();
    Gpu_SetOtLayout(0);
    Gpu_SetLayerOtPtrs();
    Rand_Seed(0);
    ((void (*)(s32))MemCardInit)(0);
    MemCardStart();
    Pad_Init();
    buf = 0x80;
    while (((s32 (*)(s32, u8 *, s32))CdControl)(0xE, &buf, 0) == 0) {
    }
    VSync(3);
    CdControlB(9, 0, 0);
    Task_ClearList();
    Gfx_InitTexSlots();
    Gpu_ClearOt(0);
    Gpu_ClearOt(1);
    Sys_State.frameCount = 1;
    Sys_State.gameMode = 0x402;
    Sys_State.nextGameMode = 0x402;
    Sys_State.modeArg = 0;
    Sys_State.field_C = 0;
    Save_ResetGameState();
    Dung_StatePtr->entryMode = 0;
    Gfx_FadeSetBlack();
    Gfx_DrawFade();
    slot = 0;
    for (;;) {
        if (slot == 0) {
            Task_ClearList();
            Gpu_FreePrimBufs();
            Mem_FreeTag(2);
            Gpu_ClearOt(0);
            Gpu_ClearOt(1);
            {
                s32 cur = Sys_State.gameMode;
                s32 next = Sys_State.nextGameMode;

                Sys_State.nextGameMode = 0;
                Sys_State.prevGameMode = cur;
                Sys_State.gameMode = next;
            }
            for (i = 0; i < 0x11; i++) {
                Flag_Set(i, 0);
            }
            Task_Create(1, &slot, 0);
        }
        Gfx_DrawFade();
        Sys_State.drawPass = 0;
        slot = Task_TryRun((void *)slot);
        Sys_State.drawPass = 1;
        slot = Task_TryRun((void *)slot);
#ifdef DW2_NATIVE
        if (Gfx_LateDraw != NULL) { /* PG.8a: draw-only extras after every retail draw */
            void (*late)(void) = Gfx_LateDraw;

            Gfx_LateDraw = NULL;
            late();
        }
#endif
        Gpu_SkipEmptyOtEntries(Sys_State.bufIndex);
        DrawSync(0);
        Sys_FlipPending = 1;
        while (*(volatile s32 *)&Sys_FlipPending != 0) {
#ifdef DW2_NATIVE
            Host_WaitVBlank(); /* no VBlank interrupt: the host runs Sys_VSyncHandler */
#endif
        }
        Gpu_ResetPrimBuf();
        Gpu_SetLayerOtPtrs();
        Gpu_ClearOt(Sys_State.bufIndex);
        t = VSync(-1);
        u = Sys_LastVSyncTime;
        Sys_LastVSyncTime = t;
        d = t - u;
        Sys_State.frameDelta = d;
        Save_GameState.playTime += d;
        if (d > 6) {
            Sys_State.frameDelta = 6;
        }
        Sys_State.frameCount++;
        Pad_Update();
        Rand_Step();
        Cd_ServiceQueue();
        Snd_ServiceSlotLoads();
    }
}

void Rand_Seed(s32 a0) {
    Rand_Index = a0 & 0xFFF;
}

void Rand_Step(void) {
    Rand_Index = (Rand_Index + 1) & 0xFFF;
}

s32 Rand_Next(void) {
    Rand_Step();
    return Rand_Table[Rand_Index];
}

u16 Rand_GetAt(u32 arg0) {
    return Rand_Table[arg0 & 0xFFF];
}

void Sys_SetFrameRate60(void) {
    Sys_State.vsyncWait = 0;
}

void Sys_SetFrameRate30(void) {
    Sys_State.vsyncWait = 2;
}

void Sys_SetFrameRate20(void) {
    Sys_State.vsyncWait = 3;
}

void Sys_SetFrameRate15(void) {
    Sys_State.vsyncWait = 4;
}
