#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"

/* Small data this file defines (.sdata). Retail reaches it with %gp_rel here. */
s32 Ovl_CurrentId = -1;

/* Task callbacks the descriptors below name (defined further down). */
void Sys_GameModeTask(Actor *a0);
void Sys_GameModeDestroy(void);
/* CD file id of each overlay (Ovl_Load), indexed by overlay id. */
s32 Ovl_FileIds[] = { 0x190, 0x19A, 0x192, 0x191, 0x193, 0xD1E, 0xD4D };
TaskDesc Sys_GameModeDesc = { 0, Sys_GameModeTask, (TaskFn)Sys_GameModeDestroy, 0, 0, 4 };

/* Ovl_FileIds[id] (Cd file ids, matched by LBA + sector count):
 * 0 STAG0000, 1 STAG4000, 2 STAG2000, 3 STAG1000, 4 STAG3000, 5 STAG1100, 6 STAG3500.
 * Sys_GameModeTask loads id (gameMode >> 8) - 1. */
void Ovl_Load(s32 id) {
    s32 *ids;
    s32 *p;
    u8 *src;
    u8 *dst;

    if (Ovl_CurrentId != id) {
        ids = Ovl_FileIds;
        p = &ids[id];
        Ovl_CurrentId = id;
        src = (u8 *)Cd_GetFileSync(*p);
        dst = Ovl_LoadAddr;
        memcpy(dst, src, Cd_GetFileSectors(*p) << 11);
    }
}

s32 Ovl_GetCurrentId(void) {
    return Ovl_CurrentId;
}

extern void Ovl_Load(s32);
extern void Task_Create(u32, s32 *, s32);
extern s32 Snd_AnySlotLoading(void);

void Sys_GameModeTask(Actor *a0) {
    s32 st = a0->stateLevel0;
    s32 t = a0->u34.children;
    switch (st) {
    case 0:
    default:
        Ovl_Load((Sys_State.gameMode >> 8) - 1);
        Task_Create(Sys_State.gameMode & 0xFF00, t, 0);
        Task_NextState0(a0);
        break;
    case 1:
        if (Sys_State.nextGameMode != 0) {
            Task_SetState0(a0, 2);
        }
        break;
    case 2:
        if (Snd_AnySlotLoading() == 0) {
            Task_SetState0(a0, 3);
        }
        break;
    }
}

void Sys_GameModeDestroy(void) {
    Task_Free();
}
