#include "common.h"
#include "stag1000/stag1000.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg10_EndScreenUpdate(Actor *arg0);
void Stg10_EndScreenDraw(Actor *arg0);

TaskDesc Stg10_EndScreenDesc = { 0, Stg10_EndScreenUpdate, Task_DefaultDestroy, Stg10_EndScreenDraw, 4, 0 };

void Stg10_EndScreenUpdate(Actor *arg0) {
    StgWork *w = (StgWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (++w->count != 7) {
                break;
            }
            Task_NextState1(arg0);
        case 1:
            if (Pad_State[0].cross > 0 || Pad_State[0].start > 0) {
                Task_NextState1(arg0);
            }
            break;
        case 2:
            if (--w->count == 0) {
                Sys_NextGameMode = 0x407;
                Task_NextState1(arg0);
            }
            break;
        case 3:
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg10_EndScreenDraw(Actor *arg0) {
    StgWork *w = (StgWork *)arg0->work;
    Stg10EndPart *e = (Stg10EndPart *)Cd_GetFileEntry(0xD760000);
    Stg10EndPart *p;

    for (p = e; p->fileId != 0; p++) {
        p->palette = w->byte;
    }
    Gfx_DrawPartsNoResScale((s32)e);
}
