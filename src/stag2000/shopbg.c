#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_ShopBgUpdate(Actor *a);
void Stg20_ShopBgDraw(Actor *a);

TaskDesc Stg20_ShopBgDesc = { 0, Stg20_ShopBgUpdate, Task_DefaultDestroy, Stg20_ShopBgDraw, 0, 0 };

void Stg20_ShopBgUpdate(Actor *a) {
    if (a->stateLevel0 == 0) {
        Task_NextState0(a);
    }
}

void Stg20_ShopBgDraw(Actor *a) {
    GfxPart *p;
    GfxPart *q;

    if (Sys_GameMode[0] < 0x333) {
        p = (GfxPart *)Cd_GetFileEntry(0xDD60001);
    } else {
        p = (GfxPart *)Cd_GetFileEntry(0xC930001);
    }
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask == 2) {
            q->palette = Math_CycleRange(a->elapsed, 6, 0, 7);
        }
    }
    Gfx_DrawParts((s32)p);
}
