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

/* Declarations the original file made before this code. */
extern s32 Mem_Alloc(s32, s32);

ActorWork *Gpu_PrimBufs[3] = { 0 };

/* Unnamed: returns 0, no callers, no table ref. */
s32 func_8001C92C(void) {
    return 0;
}

void Gpu_FreePrimBufs(void) {
    if (Gpu_PrimBufs[0] != 0) {
        Mem_Free(Gpu_PrimBufs[0]);
        Gpu_PrimBufs[0] = 0;
        Mem_Free(Gpu_PrimBufs[1]);
        Gpu_PrimBufs[1] = 0;
    }
    Sys_State.packet.addr = 0;
}

void Gpu_ResetPrimBuf(void) {
    Sys_State.packet.work = Gpu_PrimBufs[Sys_State.bufIndex];
}

extern s32 Mem_Alloc(s32, s32);

void Gpu_AllocPacketBufs(s32 a0) {
    Gpu_PrimBufs[2] = (ActorWork *)a0;
    Gpu_PrimBufs[0] = (ActorWork *)Mem_Alloc(a0, 2);
    Gpu_PrimBufs[1] = (ActorWork *)Mem_Alloc(a0, 2);
    Sys_State.packet.work = Gpu_PrimBufs[Sys_State.bufIndex];
}
