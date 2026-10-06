#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"
#include "stag4000/hud.h"
#include "stag4000/bitswin.h"
#include "stag4000/itemmenu.h"
#include "stag4000/enemyinfo.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"
#include "stag4000/enemy.h"
#include "stag4000/entity.h"
#include "stag4000/spawn.h"
#include "stag4000/automap.h"
#include "stag4000/dungfile.h"
#include "stag4000/trap.h"

s16 Stg40_TrapPartSlots[] = { 0x0D, 0x0E, 0x0B, 0x0C, 0x08, 0x0A, 0x09, 0x11, 0x12, 0x05, 0x06, 0x0F };
u8 Stg40_TrapDisarmRanks[][6] = {
    { 4, 4, 4, 4, 4, 4 },
    { 0, 1, 2, 3, 4, 4 },
    { 0, 0, 1, 2, 3, 4 },
    { 0, 0, 0, 1, 2, 3 },
    { 0, 0, 0, 0, 1, 2 },
    { 0, 0, 0, 0, 0, 1 },
};
s32 Stg40_TrapDisarmChance[] = { 100, 80, 50, 25, 0 };
u8 Stg40_TrapEffectTable[] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
u8 Stg40_RandomPartSlots[] = { 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 17, 18 };

s32 Stg40_GetTrapDisarmRank(s32 i) {
    s32 r = Stg40_GetPartLevel(7);
    r = r < 0 ? 0 : r;
    return Stg40_TrapDisarmRanks[r][i];
}

s32 Stg40_RollTrapDisarm(s32 i) {
    return Stg40_RandPercent() < Stg40_TrapDisarmChance[i];
}

s32 Stg40_RollTrapEffect(void) {
    s32 r = Stg40_TrapEffectTable[Stg40_RandPercent() / 4];

    if (r >= 4 && r < 16) {
        if (Stg40_GetBeetlePart(Stg40_TrapPartSlots[r - 4]) <= 0) {
            r = 16;
        }
    }
    return r;
}

void Stg40_ShowTrapEffectMsg(s32 a0, s32 a1) {
    s32 base = 0x1FD0011;

    if (a0 == 0) {
        base = 0x1FD0047;
    }
    switch (a1) {
    case 0:
        Stg40_MsgWinOpen(1, base, (s32)Save_GameStatePtr->beetleName, (s32)Stg40_NumToDigits(0, Stg40_RootState->damage));
        break;
    case 1:
        Stg40_MsgWinOpen(1, base + 1, (s32)Stg40_NumToDigits(0, Stg40_RootState->damage), 0);
        break;
    case 2:
    case 3:
        Stg40_MsgWinOpen(1, base + a1, 0, 0);
        break;
    case 16:
        Stg40_MsgWinOpen(1, base + 5, 0, 0);
        break;
    default:
        {
            s32 k = Stg40_TrapPartSlots[a1 - 4];
            Stg40_MsgWinOpen(1, base + 4, Item_GetNameText(Save_GameStatePtr->slotItems[k]), 0);
        }
        break;
    }
}

void Stg40_ApplyTrapEffect(s32 a0, s32 a1) {
    s32 i;
    s32 k;
    DigiRosterEntry *r;
    Stg40DungState *g;

    switch (a0) {
    case 0:
        Stg40_RootState->damage = a1 * 400;
        Stg40_DamageBeetle(Stg40_RootState->damage);
        break;
    case 1:
        Stg40_RootState->damage = a1 * 10;
        Stg40_ListPartyDigi(3);
        for (i = 0; i < Stg40_RootState->partyCount; i++) {
            r = &Save_GameStatePtr->elems[Stg40_RootState->partyIdx[i]];
            r->hp = ((s16)r->hp - Stg40_RootState->damage > 0) ? (u16)r->hp - (u16)Stg40_RootState->damage : 1;
        }
        break;
    case 2:
        Dung_StatePtr->statusFlags = (Dung_StatePtr->statusFlags | 2) & ~0x80;
        Dung_StatePtr->confusionTurn = Stg40_RandInt(4) + 1;
        break;
    case 3:
        g = Dung_StatePtr;
        g->bindTurns = 0;
        g->statusFlags = (g->statusFlags | 1) & ~0x40;
        break;
    default:
        k = Stg40_TrapPartSlots[a0 - 4];
        Save_GameStatePtr->slotStatus[k] = 1;
        break;
    case 16:
        break;
    }
}

s32 Stg40_GetPartState(void) {
    s32 r = Stg40_GetBeetlePart();

    if (r > 0) {
        r = 1;
    }
    return r;
}

s32 Stg40_PickRandomPart(void) {
    u8 buf[16];
    s32 n = 0;
    s32 r = -1;
    u32 i;

    for (i = 0; i < 12; i++) {
        if (Beetle_GetPart(Stg40_RandomPartSlots[i]) > 0) {
            buf[n++] = Stg40_RandomPartSlots[i];
        }
    }
    if (n != 0) {
        r = Stg40_RandPercent() / (100 / n);
        r = buf[r > n - 1 ? n - 1 : r];
    }
    return r;
}
