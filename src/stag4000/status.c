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
#include "stag4000/status.h"

u8 Stg40_HazardRevealChance[] = {
    0, 0, 0, 0, 0,
    80, 50, 0, 0, 0,
    100, 80, 50, 0, 0,
    100, 100, 80, 50, 0,
    100, 100, 100, 80, 50,
    100, 100, 100, 100, 80,
};
u8 Stg40_BugNestRevealChance[] = { 0, 0, 0, 80, 50, 0, 100, 80, 50, 100, 100, 80 };

s32 Stg40_TickStatusEffects(Actor *a0) {
    DungStatus *st;
    u8 *stack;
    u8 *p;
    s16 *count;
    s32 sfx;
    s32 i;
    s32 slot;
    s32 n;
    s32 r;
    DigiRosterEntry *ent;

    sfx = 0;
    st = &Dung_StatePtr->status;
    stack = Stg40_RootState->statusCodes;
    count = &Stg40_RootState->statusCount;
    p = &stack[7];
    for (i = 7; i >= 0; i--) {
        *p-- = 0;
    }
    *count = 0;
    if (st->statusFlags & 1) {
        if (++st->bindTurns >= 3 || (Stg40_RandPercent() < 50 && (st->statusFlags & 0x40))) {
            st->statusFlags &= ~1;
            stack[(*count)++] = 0;
        }
        st->statusFlags |= 0x40;
    }
    if (st->statusFlags & 2) {
        if (Stg40_RandPercent() < 10 && (st->statusFlags & 0x80)) {
            st->statusFlags &= ~2;
            stack[(*count)++] = 1;
        }
        st->statusFlags |= 0x80;
    }
    if (Dung_StatePtr->status.bugLevels[0] != 0) {
        slot = Stg40_PickRandomPart();
        if ((Stg40_RandPercent() < 5 && (st->statusFlags & 0x100)) || (Save_GameStatePtr->bits == 0 && slot == -1)) {
            stack[(*count)++] = 2;
            Dung_StatePtr->status.bugLevels[0] = 0;
        } else {
            if (Save_GameStatePtr->bits != 0) {
                s32 cost[4] = { 0, 20, 50, 100 };
                s32 v = Save_GameStatePtr->bits -= cost[st->bugLevels[0]];
                if (v < 0) {
                    v = 0;
                }
                Save_GameStatePtr->bits = v;
                sfx = 4;
            } else {
                Beetle_SetPartBroken(slot, 1);
                stack[(*count)++] = 6;
                sfx = 3;
                Stg40_RootState->brokenPartText = Item_GetNameText(Save_GameStatePtr->slotItems[slot]);
            }
            Stg40_ObjStartFlash(a0, 2);
        }
        st->statusFlags |= 0x100;
    }
    if (Dung_StatePtr->status.bugLevels[1] != 0) {
        if (Stg40_RandPercent() < 2 && (st->statusFlags & 0x200)) {
            stack[(*count)++] = 3;
            Dung_StatePtr->status.bugLevels[1] = 0;
        } else {
            s32 cost[4] = { 0, 2, 4, 6 };
            s16 v = Save_GameStatePtr->mp - cost[st->bugLevels[1]];
            Save_GameStatePtr->mp = v;
            if (v < 0) {
                v = 0;
            }
            Save_GameStatePtr->mp = v;
            Stg40_ObjStartFlash(a0, 2);
            sfx = 2;
        }
        st->statusFlags |= 0x200;
    }
    if (Dung_StatePtr->status.bugLevels[2] != 0) {
        s32 chance[4] = { 0, 50, 40, 30 };
        n = ((s32 (*)(s32))Stg40_ListPartyDigi)(1);
        if ((Stg40_RandPercent() < chance[st->bugLevels[2]] && (st->statusFlags & 0x400)) || n < 2 ||
            Digi_CountByState(1) >= 24) {
            stack[(*count)++] = 4;
            Dung_StatePtr->status.bugLevels[2] = 0;
        } else {
            n = ((s32 (*)(s32))Stg40_ListPartyDigi)(0);
            r = Stg40_RandPercent() / (100 / n);
            if (r > n - 1) {
                r = n - 1;
            }
            ent = &Save_GameStatePtr->elems[Stg40_RootState->partyIdx[r]];
            ent->state = 1;
            *(Stg40DigiName *)Stg40_RootState->lostDigiName = *(Stg40DigiName *)ent->name;
            Digi_SortRoster();
            for (i = 0; i < 3; i++) {
                if (Save_GameStatePtr->elems[i].state < 2) {
                    break;
                }
                Save_GameStatePtr->elems[i].state = i + 3;
            }
            stack[(*count)++] = 7;
            Stg40_ObjStartFlash(a0, 2);
            sfx = 1;
        }
        st->statusFlags |= 0x400;
    }
    if (Dung_StatePtr->status.memBugCount != 0) {
        st->statusFlags |= 0x800;
    }
    switch (sfx) {
    case 1:
        Snd_PlayById(3, 0);
        break;
    case 2:
        Snd_PlayById(7, 0);
        break;
    case 3:
        Snd_PlayById(6, 0);
        break;
    case 4:
        Snd_PlayById(8, 0);
        break;
    }
    return Stg40_RootState->statusCount;
}

void Stg40_RollObjectReveal(void) {
    Stg40Ent48 *e = Dung_StatePtr->ents;
    s32 a;
    s32 b;
    s32 i;
    s32 v;

    a = Stg40_GetPartLevel(13);
    a = a < 0 ? 0 : a;
    b = Stg40_GetPartLevel(14);
    b = b < 0 ? 0 : b;
    for (i = 0; i < Dung_StatePtr->entCount; e++, i++) {
        if (e->flags & 0x8000) {
            switch (e->kind) {
            case 6:
            case 8:
                v = Stg40_HazardRevealChance[e->params[1] - 1 + a * 5];
                if (Stg40_RandPercent() < v) {
                    e->flags |= 0x1000;
                }
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                v = Stg40_BugNestRevealChance[e->params[1] - 1 + b * 3];
                if (Stg40_RandPercent() < v) {
                    e->flags |= 0x1000;
                }
                break;
            }
        }
    }
}
