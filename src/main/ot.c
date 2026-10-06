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

/* The two ordering tables (Gpu_OtBufs[i + 1] is the end of table i). */
GpuOtBuf Gpu_OtBufs[2];
/* OT layout mode (index into Gpu_OtLayerLens); code reads it as Gpu_OtBufs[2].entries[0]. */
s32 D_8005CD58[2];
/* Ordering table layout per mode: layer lengths and offsets (8 layers). */
s32 Gpu_OtLayerLens[][8] = {
    { 15, 15, 15, 4, 15, 15, 15, 0 },
    { 15, 15, 15, 5, 15, 5, 15, 0 },
    { 15, 5, 15, 5, 15, 15, 15, 0 },
    { 15, 6, 15, 5, 15, 6, 15, 0 },
};
s32 Gpu_OtLayerOffsets[][8] = {
    { 0, 2, 4, 6, 0x1006, 0x1008, 0x100A, 0 },
    { 0, 2, 4, 6, 0x806, 0x808, 0x1008, 0 },
    { 0, 2, 0x802, 0x804, 0x1004, 0x1006, 0x1008, 0 },
    { 0, 2, 0x402, 0x404, 0xC04, 0xC06, 0x1006, 0 },
};

void Gpu_SetLayerOtPtrs(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        Sys_State.otLayerLen[i] = Gpu_OtLayerLens[Gpu_OtBufs[2].entries[0]][i];
        Sys_State.otLayers.s[i] = &Gpu_OtBufs[Sys_State.bufIndex].entries[Gpu_OtLayerOffsets[Gpu_OtBufs[2].entries[0]][i]];
    }
}

void Gpu_SetOtLayout(s32 arg0) {
    Gpu_OtBufs[2].entries[0] = arg0;
}

void Gpu_ClearOt(s32 arg0) {
    ClearOTagR(&Gpu_OtBufs[arg0], 0x100C);
}

s32 Gpu_DrawOt(s32 arg0) {
    s32 *p = (s32 *)&Gpu_OtBufs[arg0 + 1];
    return DrawOTag(&p[-1]);
}

void Gpu_SkipEmptyOtEntries(s32 arg0) {
    u32 *ot = (u32 *)&Gpu_OtBufs[arg0 + 1];
    u32 *end = (u32 *)&Gpu_OtBufs[arg0];
    u32 *p;
    u32 *q;
    u32 m;

    p = ot - 1;
    m = 0xFFFFFF;
    while (p != end) {
        q = p - 1;
        if ((*p & m) == ((u32)q & m)) {
            while ((*q & m) == ((u32)(q - 1) & m)) {
                q--;
            }
            *p = (u32)q & m;
        }
        p = q;
    }
}
