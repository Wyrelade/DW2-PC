#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/bg.h"
#include "stag1100/vsparty.h"
#include "stag1100/card.h"

TaskDesc Stg11_BgDesc = { 0, Stg11_BgUpdate, Task_DefaultDestroy, Stg11_BgDraw, 0, 0 };

void Stg11_BgUpdate(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Task_NextState0(arg0);
    }
}

void Stg11_BgDraw(Actor *arg0) {
    GfxPart *list = (GfxPart *)Cd_GetFileEntry(0x459000C);
    GfxPart *p;

    for (p = list; p->fileId != 0; p++) {
        switch (p->groupMask) {
        case 2:
            p->palette = Math_CycleRange(arg0->elapsed, 10, 0, 7);
            break;
        case 8:
            p->x -= 2;
            if (p->x == -0x168) {
                p->x = 0;
            }
            break;
        case 0x10:
            p->x += 1;
            if (p->x == 0xD8) {
                p->x = 0;
            }
            break;
        case 0x20:
            p->x -= 2;
            if (p->x == -0x1C0) {
                p->x = 0;
            }
            break;
        }
    }
    Gfx_DrawParts(list);
}
