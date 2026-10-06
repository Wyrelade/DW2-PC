#include "common.h"
#include "stag3000/stag3000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_BannerInit(Actor *a0, s32 a1);
void Stg30_BannerUpdate(Actor *a0);
void Stg30_BannerDraw(Actor *a0);

s32 Stg30_BannerParts[] = { 0x01A10001, 0x01A10012, 0x01A1001F, 0x01A10013 };
TaskDesc Stg30_BannerDesc = {
    (TaskInitFn)Stg30_BannerInit, Stg30_BannerUpdate, Task_DefaultDestroy, Stg30_BannerDraw, 0, 0,
};

void Stg30_BannerInit(Actor *a0, s32 a1) {
    a0->param = a1;
}

void Stg30_BannerUpdate(Actor *a0) {
    switch (a0->stateLevel0) {
    case 0:
        if (a0->param == 1) Snd_PlayById(0x24, 0);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->param) {
        case 0:
        default:
            if (a0->elapsed >= 0x100) Task_SetState0(a0, 3);
            break;
        case 1:
        case 2:
            if (a0->elapsed >= 0x80) Task_SetState0(a0, 3);
            break;
        case 3:
            if (a0->elapsed >= 0x12D && (Pad_Pressed & 0x840)) Task_SetState0(a0, 3);
            break;
        }
        break;
case 2: break;
    }
}

void Stg30_BannerDraw(Actor *a0) {
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(Stg30_BannerParts[a0->param]);
    Stg30Part *q;

    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_CycleRange(a0->elapsed, 4, 0, 7);
    }
    if (a0->param == 3) {
        if (Stg30_Battle.entries[0].fromCity != 0) {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 1);
        } else {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 2);
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}
