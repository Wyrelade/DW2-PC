#include "common.h"
#include "stag2000/stag2000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabCaptionUpdate(Actor *a);
void Stg20_LabCaptionDraw(void);

Halves Stg20_LabCaptionPos[3] = { { 0x1E, 0x18 }, { 0x13, 0x18 }, { 0x24, 0x30 } };
TaskDesc Stg20_LabCaptionDesc = {
    0, Stg20_LabCaptionUpdate, Task_DefaultDestroy, (TaskFn)Stg20_LabCaptionDraw, 8, 0,
};

void Stg20_LabCaptionUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        if (D_800709D0 == 0) {
            Text_OpenById(w, 0x102, 0, Stg20_LabCaptionPos[0]);
        } else {
            Text_OpenById(w, 0x103, 0, Stg20_LabCaptionPos[1]);
            Text_OpenById(&w[1], 0x104, 0, Stg20_LabCaptionPos[2]);
        }
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        Text_CloseArray(w, 2);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabCaptionDraw(void) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120001);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 6) {
            switch (Stg20_MenuState.pickStep) {
            case 0:
            default:
                q->visible = 0;
                break;
            case 1:
                q->visible = ((u32)q->groupMask >> 1) & 1;
                break;
            case 2:
                q->visible = ((u32)q->groupMask >> 2) & 1;
                break;
            }
        }
    }
    Gfx_DrawParts((s32)p);
}
