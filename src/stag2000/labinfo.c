#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/areaselect.h"
#include "stag2000/msgwin.h"

/* Task callbacks the descriptors below need (defined further down). Stg20_GetDnaResult (dna.c) is
 * called with no prototype in scope: its u8 one would change that call. */
void Stg20_LabInfoUpdate(Actor *a);
void Stg20_LabInfoDraw(Actor *a);

Stg20Cell Stg20_LabInfoTextPos[13] = {
    { 18, 24 }, { 9, 49 }, { 54, 61 }, { 70, 73 }, { 70, 85 }, { 36, 153 }, { 36, 165 },
    { 9, 61 }, { 212, 49 }, { 212, 129 }, { 9, 141 }, { 204, 24 }, { 275, 49 },
};
u8 Stg20_DigivolveRuleTbl[4][4] = { { 0, 0, 0, 2 }, { 1, 0, 0, 2 }, { 1, 1, 0, 2 }, { 1, 1, 1, 2 } };
TaskDesc Stg20_LabInfoDesc = { 0, Stg20_LabInfoUpdate, Task_DefaultDestroy, Stg20_LabInfoDraw, 0x60, 0 };

void Stg20_LabInfoUpdate(Actor *a) {
    Stg20InfoWork *w = (Stg20InfoWork *)a->work;
    DigiRosterEntry *d;
    s32 t;
    s32 lv;
    s32 ok;
    s32 id0;
    s32 id1;
    s32 x;
    s32 y;
    s32 p;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 0xD);
        w->digi = (DigiRosterEntry *)&Save_GameState.elems[D_800709D8];
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            Stg20_OpenText(&w->texts[0], (s32)w->digi->name, 0, &Stg20_LabInfoTextPos[0], 0);
            Stg20_OpenText(&w->texts[1], (s32)Digi_GetDefaultName(w->digi->digiId), 0, &Stg20_LabInfoTextPos[1], 0);
            Stg20_OpenText(&w->texts[2], 0, Digi_GetType(w->digi->digiId) + 0xC3, &Stg20_LabInfoTextPos[2], 0);
            Stg20_OpenText(&w->texts[3], 0, Digi_GetRank(w->digi->digiId) + 0xC6, &Stg20_LabInfoTextPos[3], 0);
            Stg20_OpenText(&w->texts[4], 0, Digi_GetSpecialty(w->digi->digiId) + 0xCA, &Stg20_LabInfoTextPos[4], 0);
            if (w->digi->attr[0x25] != 0) {
                Stg20_OpenText(&w->texts[5], (s32)Digi_GetDefaultName(w->digi->attr[0x25]), 0, &Stg20_LabInfoTextPos[5], 0);
            }
            if (w->digi->attr[0x26] != 0) {
                Stg20_OpenText(&w->texts[6], (s32)Digi_GetDefaultName(w->digi->attr[0x26]), 0, &Stg20_LabInfoTextPos[6], 0);
            }
            Stg20_OpenText(&w->texts[7], 0, 0x105, &Stg20_LabInfoTextPos[7], 0);
            Stg20_OpenText(&w->texts[8], 0, 0x106, &Stg20_LabInfoTextPos[8], 0);
            Stg20_OpenText(&w->texts[9], 0, 0x107, &Stg20_LabInfoTextPos[9], 0);
            Stg20_OpenText(&w->texts[10], 0, 0xBF, &Stg20_LabInfoTextPos[10], 0);
            Stg20_OpenText(&w->texts[11], 0, 0xD0, &Stg20_LabInfoTextPos[11], 0);
            Stg20_OpenText(&w->texts[12], 0, 0x9D, &Stg20_LabInfoTextPos[12], 0);
            switch (D_800709D4) {
            case 0:
                t = Digi_GetRank(w->digi->digiId);
                d = w->digi;
                lv = (d->level - 1) / 10;
                if (lv >= 4) {
                    lv = 3;
                }
                switch (Stg20_DigivolveRuleTbl[lv][t]) {
                case 0:
                    Stg20_MsgWinShowSysMsg(0x118);
                    break;
                case 1:
                    p = Digi_GetEvolutionTarget(d->digiId, d->dp);
                    Stg20_EvoTargetId = p;
                    if (p == 0) {
                case 2:
                        Stg20_MsgWinShowSysMsg(0x11D);
                    } else {
                        Stg20_MsgWinShowDigiMsg(0x119, p);
                    }
                    break;
                }
                break;
            case 1:
                Stg20_MsgWinShowDigiMsg(0x126, Stg20_EvoTargetId);
                break;
            case 2:
                if (Digi_GetRank(w->digi->digiId) != 0) {
                    Stg20_MsgWinShowSysMsg(0x11B);
                } else {
                    Stg20_MsgWinShowSysMsg(0x11A);
                }
                break;
            case 3:
                ok = 0;
                id0 = Save_GameState.elems[D_800709E4].digiId;
                id1 = w->digi->digiId;
                x = Digi_GetType(id0);
                y = Digi_GetType(id1);
                switch (Sys_State.prevGameMode) {
                case 0x305:
                    if (x != 0 && y != 0) {
                        ok = 1;
                    }
                    break;
                case 0x309:
                    if (x != 2 && y != 2) {
                        ok = 1;
                    }
                    break;
                case 0x30D:
                    if (x != 1 && y != 1) {
                        ok = 1;
                    }
                    break;
                default:
                    ok = 1;
                    break;
                }
                if (ok != 0) {
                    if (Digi_GetRank(w->digi->digiId) == 0) {
                        Stg20_MsgWinShowSysMsg(0x11A);
                    } else {
                        Stg20_EvoTargetId = Stg20_GetDnaResult(id0, id1);
                        Stg20_MsgWinShowDigiMsg(0x128, Stg20_EvoTargetId);
                    }
                } else {
                    Stg20_MsgWinShowSysMsg(0x12A);
                }
                break;
            case 4:
                Stg20_MsgWinShowDigiMsg(0x129, Stg20_EvoTargetId);
                break;
            }
            Task_NextState1(a);
            break;
        case 1:
            do {
                if (Pad_State[0].circle > 0) {
                    D_800709B8.result = 0;
                    Task_NextState0(a);
                    break;
                }
                if (Pad_State[0].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    D_800709B8.result = 1;
                    Task_NextState0(a);
                    break;
                }
                if (Stg20_MenuState.infoMode == 1) {
                    break;
                }
                switch (Stg20_MsgWinGetChoice()) {
                case 0:
                    Stg20_MenuState.result = 2;
                    Task_NextState0(a);
                    break;
                case 1:
                    Stg20_MenuState.result = 3;
                    Task_NextState0(a);
                    break;
                }
            } while (0);
            break;
        }
        break;
    case 2:
        Text_CloseArray(w->texts, 0xD);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabInfoDraw(Actor *a) {
    Stg20StatusWork *w = (Stg20StatusWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120008);

    Gfx_SetPartsNumber(p, 2, 3, w->digi->maxHp);
    Gfx_SetPartsNumber(p, 4, 3, w->digi->hp);
    Gfx_SetPartsNumber(p, 8, 3, w->digi->maxMp);
    Gfx_SetPartsNumber(p, 0x10, 3, w->digi->mp);
    Gfx_SetPartsNumber(p, 0x20, 2, w->digi->level);
    Gfx_SetPartsNumber(p, 0x40, 3, w->digi->attack);
    Gfx_SetPartsNumber(p, 0x80, 3, w->digi->defense);
    Gfx_SetPartsNumber(p, 0x100, 3, w->digi->speed);
    Gfx_SetPartsNumber(p, 0x200, 8, w->digi->exp);
    Gfx_SetPartsNumber(p, 0x400, 8, Digi_GetExpToNextLevel(w->digi->level, w->digi->maxLevel, w->digi->exp));
    Gfx_SetPartsNumber(p, 0x800, 2, w->digi->dp);
    Gfx_DrawParts((s32)p);
}
