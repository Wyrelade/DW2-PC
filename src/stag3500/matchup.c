#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_MatchupUpdate(Actor *arg0);
void Stg35_MatchupDestroy(Actor *arg0);
void Stg35_MatchupDraw(Actor *arg0);

Stg35XY Stg35_MatchupLabelPos[] = {
    { 177, 28 }, { 18, 137 }, { 177, 45 }, { 18, 154 }, { 177, 66 }, { 18, 175 },
};
s16 Stg35_MatchupLabelMsgs[] = { 441, 442, 443, 443, 444, 444 };
Stg35XY Stg35_MatchupPartyPos[] = { { 213, 78 }, { 54, 187 } };
Stg35XY Stg35_MatchupTamerPos[] = { { 222, 45 }, { 63, 154 } };
TaskDesc Stg35_MatchupDesc = { 0, Stg35_MatchupUpdate, Stg35_MatchupDestroy, Stg35_MatchupDraw, 0x3C, 4 };

void Stg35_MatchupUpdate(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 v;

    switch (arg0->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x32000);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, slot, 0);
        for (i = 0; i < 1; i++) {
            Stg35_PartsAlloc(&w->load[i]);
        }
        for (i = 0; i < 14; i++) {
            Stg35_TextAlloc(&w->text[i]);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Stg35_PartsSetFile(w->load, 0xD3F0002);
                Stg35_PartsStartSlideX(w->load, 0, 2, 0x140, 0, -0x1400);
                Stg35_PartsStartSlideX(w->load, 1, 4, -0x140, 0, 0x1400);
                Stg35_PartsHideByMask(w->load, 0x18);
                Task_NextState2(arg0);
            case 1:
                if (++arg0->stateLevel3 == 0x14) {
                    Snd_PlayById(0x101, 1);
                    Stg35_PartsHideByMask(w->load, 0x10);
                    for (j = 0; j < 6; j++) {
                        Stg35_TextSetLayout(&w->text[j], 1, Stg35_MatchupLabelPos[j].x, Stg35_MatchupLabelPos[j].y);
                        Stg35_TextSetSysMsg(&w->text[j], Stg35_MatchupLabelMsgs[j]);
                        Stg35_TextOpen(&w->text[j]);
                    }
                    for (k = 0; k < 6; k++) {
                        Stg35_TextSetLayout(&w->text[k + 6], 1, Stg35_MatchupPartyPos[k / 3].x, Stg35_MatchupPartyPos[k / 3].y + (k % 3) * 12);
                        Stg35_TextSetString((Stg35PartsHandle *)&w->text[k + 6], (s32)Digi_GetDefaultName(Save_GameState.elems[k].digiId));
                        Stg35_TextOpen(&w->text[k + 6]);
                    }
                    for (l = 0; l < 2; l++) {
                        Stg35_TextSetLayout(&w->text[l + 12], 1, Stg35_MatchupTamerPos[l].x, Stg35_MatchupTamerPos[l].y);
                        Stg35_TextSetString((Stg35PartsHandle *)&w->text[l + 12], (s32)Save_GameState.elems[l + 6].name);
                        Stg35_TextOpen(&w->text[l + 12]);
                    }
                }
                if (arg0->stateLevel3 == 0x1E) {
                    Task_NextState2(arg0);
                }
                break;
            case 2:
                v = Math_CycleRange(arg0->elapsed, 6, 0, 7);
                Stg35_PartsHideByMask(w->load, 0);
                Stg35_PartsSetPalette(w->load, 0x10, v);
                if (v == 7) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 1:
            if (Pad_State[0].cross > 0 || Pad_State[1].cross > 0) {
                Task_NextState0(arg0);
            }
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
        case 1:
            if (Sys_State.fadeLevel == 0xFF) {
                Sys_State.nextGameMode = 0x703;
            }
            break;
        }
        break;
    }
}

void Stg35_MatchupDestroy(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsFree(&w->load[i]);
    }
    for (i = 0; i < 14; i++) {
        Stg35_TextFree(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_MatchupDraw(Actor *arg0) {
    Stg35_PartsDraw((Stg35PartsHandle *)arg0->work);
}
