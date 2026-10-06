#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"
#include "stag3000/battlestate.h"
#include "stag3000/fighter.h"
#include "stag3000/fightmsg.h"
#include "stag3000/popup.h"
#include "stag3000/interruptselect.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_ResultInit(Actor *a0, Stg30Pair *args);
void Stg30_ResultUpdate(Actor *a0);
void Stg30_ResultDestroy(Actor *a0);
void Stg30_ResultDraw(Actor *a0);
/* Level-up stat gain tables. */
u16 Stg30_HpMpGrowth[6][3][4] = {
    { { -1, 0, 1, 2 }, { -1, 0, 0, 1 }, { -2, -1, 0, 1 } },
    { { -1, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 1 } },
    { { 0, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 0 } },
    { { 0, 0, 0, 1 }, { -1, 0, 0, 1 }, { -1, 0, 0, 0 } },
    { { 0, 0, 1, 1 }, { 0, 0, 1, 1 }, { 0, 0, 1, 1 } },
    { { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 } },
};
u16 Stg30_AtkDefGrowth[5][3][4] = {
    { { -1, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 1 } },
    { { 0, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 0 } },
    { { 0, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 0 } },
    { { 0, 0, 0, 1 }, { -1, 0, 0, 1 }, { -1, 0, 0, 0 } },
    { { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 } },
};
u16 Stg30_SpeedGrowth[5][3][4] = {
    { { -1, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 1 } },
    { { 0, 0, 1, 1 }, { -1, 0, 0, 1 }, { -1, -1, 0, 0 } },
    { { 0, 0, 0, 1 }, { -1, 0, 0, 1 }, { -1, 0, 0, 0 } },
    { { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 } },
    { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
};
Stg30TextRec Stg30_ResultTextLayout[] = {
    { 0, 0x5A, 0, 0, { 134, 60 } },
    { 1, 0x5A, 0, 0, { 134, 96 } },
    { 2, 0x5A, 0, 0, { 134, 132 } },
    { 0, 0x5B, 0, 0, { 134, 73 } },
    { 1, 0x5B, 0, 0, { 134, 109 } },
    { 2, 0x5B, 0, 0, { 134, 145 } },
    { 9, 0x5D, 4, 0, { 37, 19 } },
    { 9, 0x5E, 0, 1, { 36, 32 } },
    { 0, 0x0, 0, 0, { 37, 58 } },
    { 1, 0x1, 0, 0, { 37, 94 } },
    { 2, 0x2, 0, 0, { 37, 130 } },
    { 9, 0x5F, 0, 0, { 37, 210 } },
    { 9, 0x5F, 0, 0, { 37, 170 } },
    { 9, 0x60, 0, 1, { 36, 183 } },
};
s32 Stg30_ResultParts[] = { 0x01A1000C, 0x01A1000D, 0x01A1000E, 0x01A10010, 0x01A1000F, 0x01A10011 };
TaskDesc Stg30_ResultDesc = {
    (TaskInitFn)Stg30_ResultInit, Stg30_ResultUpdate, Stg30_ResultDestroy, Stg30_ResultDraw, 0x5C, 0,
};

void Stg30_ResultInit(Actor *a0, Stg30Pair *args) {
    ((Stg30ResultWork *)a0->work)->pair = *args;
}

u8 *Stg30_NumToDigits(u8 *out, s32 n) {
    u8 buf[8];
    s32 i;
    s32 lead;
    s32 k;

    for (i = 7; i != -1; i--) {
        buf[i] = n % 10;
        n /= 10;
    }
    lead = 1;
    k = 0;
    for (i = 0; i < 8; i++) {
        if (!lead || buf[i] != 0) {
            out[k++] = buf[i];
            lead = 0;
        }
    }
    out[k] = 0xFF;
    return out;
}

void Stg30_LevelUpStats(DigiRosterEntry *e) {
    u16 *p;
    s32 r;
    s32 c;
    s32 lv;
    s32 k;
    u16 t;

    e->level = e->level + 1;
    lv = e->level;
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            p = &e->maxHp;
        } else {
            p = &e->maxMp;
        }
        r = Rand_Next() & 3;
        c = Digi_GetStatGrowth(e->digiId, k);
        if (lv < 12) {
            *p += Stg30_HpMpGrowth[0][c][r] + 10;
        } else if (lv < 22) {
            *p += Stg30_HpMpGrowth[1][c][r] + 6;
        } else if (lv < 32) {
            *p += Stg30_HpMpGrowth[2][c][r] + 4;
        } else if (lv < 42) {
            *p += Stg30_HpMpGrowth[3][c][r] + 2;
        } else if (lv < 52) {
            *p = *p + Stg30_HpMpGrowth[4][c][r];
        } else {
            *p = *p + Stg30_HpMpGrowth[5][c][r];
        }
        t = *p;
        if ((s16)*p >= 1000) {
            t = 999;
        }
        *p = t;
    }
    k = 1;
    lv = e->level - (Digi_GetRank(e->digiId) * 10 + k);
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            p = (u16 *)&e->attack;
        } else {
            p = &e->defense;
        }
        r = Rand_Next() & 3;
        c = Digi_GetStatGrowth(e->digiId, k + 2);
        if (lv == 1) {
            *p += Stg30_AtkDefGrowth[0][c][r] + 4;
        } else if (lv < 4) {
            *p += Stg30_AtkDefGrowth[1][c][r] + 3;
        } else if (lv < 7) {
            *p += Stg30_AtkDefGrowth[2][c][r] + 2;
        } else if (lv < 11) {
            *p += Stg30_AtkDefGrowth[3][c][r] + 1;
        } else {
            *p = *p + Stg30_AtkDefGrowth[4][c][r];
        }
        t = *p;
        if ((s16)*p >= 1000) {
            t = 999;
        }
        *p = t;
    }
    lv = e->speed;
    p = (u16 *)&e->speed;
    r = Rand_Next() & 3;
    c = Digi_GetStatGrowth(e->digiId, 4);
    if (lv < 21) {
        *p += Stg30_SpeedGrowth[0][c][r] + 3;
    } else if (lv < 51) {
        *p += Stg30_SpeedGrowth[1][c][r] + 2;
    } else if (lv < 101) {
        *p += Stg30_SpeedGrowth[2][c][r] + 1;
    } else {
        *p = *p + Stg30_SpeedGrowth[3][c][r];
    }
    t = *p;
    if ((s16)*p >= 1000) {
        t = 999;
    }
    *p = t;
    e->hp = e->maxHp;
    e->mp = e->maxMp;
}

void Stg30_ResultUpdate(Actor *a0) {
    Stg30ResultWork *w = (Stg30ResultWork *)a0->work;
    Stg30TextArgs args;
    Stg30TextRec *r;
    s32 i;
    s32 j;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->text, 14);
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].hp != 0) {
                Stg30_Battle.entries[i].exp += w->pair.field_0;
            }
            w->expToNext[i] = Digi_GetExpToNextLevel(Stg30_Battle.entries[i].level, Stg30_Battle.entries[i].maxLevel,
                                                   Stg30_Battle.entries[i].exp);
            if (w->expToNext[i] == 0 && Stg30_Battle.entries[i].hp != 0) {
                Stg30_Battle.leveledUp[i] = 1;
                Stg30_LevelUpStats(&((Stg30StateDigis *)&Stg30_Battle)->digis[i]);
            } else {
                Stg30_Battle.leveledUp[i] = 0;
            }
        }
        Save_GameState.bits += w->pair.field_4;
        if (Save_GameState.bits > 99999999) {
            Save_GameState.bits = 99999999;
        }
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            for (j = 0; j < 14; j++) {
                r = &Stg30_ResultTextLayout[j];
                if (r->slot == 9 || Stg30_Battle.entries[r->slot].digiId != 0) {
                    if (r->src < 3) {
                        args.text = (s32)D_80073D24[r->src].name;
                    } else {
                        args.text = (s32)Cd_GetFileEntry(r->src | 0x1FD0000);
                    }
                    if (j == 7) {
                        args.strArg0 = (s32)Stg30_NumToDigits(w->buf0, w->pair.field_0);
                    }
                    if (j == 13) {
                        args.strArg0 = (s32)Stg30_NumToDigits(w->buf1, w->pair.field_4);
                    }
                    args.bigFont = r->bigFont;
                    args.color = r->color;
                    args.pos = r->pos;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    args.charDelay = 0;
                    Text_Open(&w->text[j], (TextOpenArgs *)&args);
                }
            }
            Task_NextState1(a0);
        case 1:
            if (Pad_Cross > 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg30_ResultDestroy(Actor *a0) {
    Text_CloseArray(((Stg30ResultWork *)a0->work)->text, 14);
    Task_DefaultDestroy(a0);
}

void Stg30_ResultDraw(Actor *a0) {
    Stg30ResultWork *w = (Stg30ResultWork *)a0->work;
    GfxPart *p;
    s32 i;
    s32 draw;

    for (i = 0; i < 6; i++) {
        draw = 1;
        p = (GfxPart *)Cd_GetFileEntry(Stg30_ResultParts[i]);
        switch (i) {
        case 0:
        case 1:
        case 2:
            if (Stg30_Battle.entries[i].digiId == 0) {
                draw = 0;
                break;
            }
            if (Stg30_Battle.leveledUp[i] != 0) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0x10);
            }
            Gfx_SetPartsNumber(p, 1, 8, Stg30_Battle.entries[i].exp);
            Gfx_SetPartsNumber(p, 4, 8, w->expToNext[i]);
            Gfx_SetPartsNumber(p, 8, 2, Stg30_Battle.entries[i].level);
            break;
        case 4:
            Gfx_SetPartsNumber(p, 1, 8, Save_GameState.bits);
            break;
        }
        if (draw) {
            Gfx_DrawParts((EntA0 *)p);
        }
    }
}
