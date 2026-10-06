#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"
#include "stag3500/parts.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_RoundBannerInit(Actor *arg0, s32 arg1);
void Stg35_RoundBannerTask(Actor *arg0);
void Stg35_RoundBannerDestroy(Actor *arg0);
void Stg35_RoundBannerDraw(Actor *arg0);

TaskDesc Stg35_RoundBannerDesc = {
    (TaskInitFn)Stg35_RoundBannerInit, Stg35_RoundBannerTask, Stg35_RoundBannerDestroy, Stg35_RoundBannerDraw, 8, 0,
};
/* Task_DescTable[7]: task ids 0x700-0x70D. */
TaskDesc *Stg35_TaskDescs[] = {
    &Stg35_RootDesc, &Stg35_VsMenuDesc, &Stg35_BgDesc, &Stg35_MatchupDesc, &Stg35_FightBgDesc,
    &Stg35_BattleDesc, &Stg35_CameraDesc, &Stg35_FighterDesc, &Stg35_BattleHudDesc,
    &Stg35_BattleScriptDesc, &Stg35_ActionLoadDesc, &Stg35_XaPlayDesc, &Stg35_RoundBannerDesc,
    &Stg35_WinBannerDesc,
};

void Stg35_RoundBannerInit(Actor *arg0, s32 arg1) {
    arg0->param = arg1;
}

const Stg35Masks Stg35_RoundBannerMasks = { { 1, 2, 0x10 } };
void Stg35_RoundBannerTask(Actor *arg0) {
    Stg35RoundBannerWork *w = (Stg35RoundBannerWork *)arg0->work;

    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        Stg35_PartsSetFile(w->load, 0xD3F0009);
        {
            Stg35Masks masks = Stg35_RoundBannerMasks;

            Stg35_PartsHideByMask(w->load, ~masks.v[arg0->param]);
        }
        Snd_PlayById(0x24, 0);
        Task_NextState0(arg0);
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->fade++;
            Stg35_PartsSetPalette(w->load, 0x1F, w->fade >> 1);
            if (w->fade != 14) {
                break;
            }
            Task_NextState1(arg0);
        case 1:
            if (((ActorAllocView *)arg0)->frameCount < 8) {
                break;
            }
            Task_NextState1(arg0);
        case 2:
            w->fade--;
            Stg35_PartsSetPalette(w->load, 0x1F, w->fade >> 1);
            if (w->fade == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void Stg35_RoundBannerDestroy(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsFree(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_RoundBannerDraw(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsDraw(&w[i]);
    }
}

void Stg35_ClearBattle(void) {
    Mem_Zero(&Stg35_Battle, 0x358);
}
