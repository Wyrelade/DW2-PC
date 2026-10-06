#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_BgUpdate(Actor *arg0);
void Stg35_BgDestroy(Actor *arg0);
void Stg35_BgDraw(Actor *arg0);

TaskDesc Stg35_BgDesc = { 0, Stg35_BgUpdate, Stg35_BgDestroy, Stg35_BgDraw, 4, 0 };

void Stg35_BgUpdate(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;

    if (arg0->stateLevel0 == 0) {
        Stg35_PartsAlloc(w);
        Stg35_PartsSetFile(w, 0xD3F0000);
        Task_NextState0(arg0);
    }
}

void Stg35_BgDestroy(Actor *arg0) {
    Stg35_PartsFree((Stg35PartsHandle *)arg0->work);
    Task_DefaultDestroy(arg0);
}

void Stg35_BgDraw(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;

    Stg35_PartsSetPalette(w, 2, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    Stg35_PartsDraw(w);
}
