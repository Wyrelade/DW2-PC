#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"
#include "stag3500/textrect.h"
#include "stag3500/turn.h"
#include "stag3500/parts.h"
#include "stag3500/fighter.h"
#include "stag3500/roundbanner.h"
#include "stag3500/xaplay.h"
#include "stag3500/hud.h"
#include "stag3500/battlescript.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_WinBannerInit(Actor *arg0, s32 arg1);
void Stg35_WinBannerUpdate(Actor *arg0);
void Stg35_WinBannerDestroy(Actor *arg0);
void Stg35_WinBannerDraw(Actor *arg0);

TaskDesc Stg35_WinBannerDesc = {
    (TaskInitFn)Stg35_WinBannerInit, Stg35_WinBannerUpdate, Stg35_WinBannerDestroy, Stg35_WinBannerDraw, 8, 0,
};
/* Unreferenced: the word before .bss (retail .bss starts 8-aligned). */
s32 D_8006AA54 = 0;

void Stg35_WinBannerInit(Actor *arg0, s32 arg1) {
    arg0->param = arg1;
}

void Stg35_WinBannerUpdate(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 masks[2];
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            Stg35_PartsAlloc(&w[i]);
        }
        Stg35_PartsSetFile(w, 0xD3F0008);
        masks[0] = 2;
        masks[1] = 4;
        Stg35_PartsHideByMask(w, ~masks[arg0->param]);
        Task_NextState0(arg0);
    case 1:
        Stg35_PartsSetPalette(w, 6, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
        break;
    case 2:
    default:
        break;
    }
}

void Stg35_WinBannerDestroy(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsFree(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_WinBannerDraw(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsDraw(&w[i]);
    }
}
