#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/digilist.h"
#include "main/digistatus.h"
#include "main/skilllist.h"
#include "main/spawnlist.h"
#include "main/winframe.h"
#include "main/sound.h"
#include "main/text.h"
#include "main/gpu.h"
#include "main/fade.h"
#include "main/ot.h"
#include "main/primbuf.h"
#include "main/texslot.h"
#include "main/parts.h"
#include "main/digibase.h"
#include "main/gamedata.h"
#include "main/flagtable.h"
#include "main/digidata.h"
#include "main/F400.h"
#include "main/skill.h"
#include "main/anim.h"
#include "main/model.h"
#include "main/12550.h"

/* Small data this unit defines (.sdata). Retail reaches it with %gp_rel here. */
GameStateView *Save_GameStatePtr = (GameStateView *)&Save_GameState;
/* .bss: the game state (save data). Code and overlays reach parts of it by their own
 * symbols. */
GameState Save_GameState;

/* Digimon a Digi-Beetle can carry, by its part 2 item id - 0x2F (Beetle_GetDigiCapacity). */
u8 Beetle_PartDigiCapacity[] = { 4, 5, 6, 7, 8, 12 };

void Save_ResetGameState(void) {
    Mem_Zero(Save_GameStatePtr, 0x1058);
    Save_GameStatePtr->field_0 = 1;
    Save_ClearEventFlags();
    Save_GameState.playerName[0] = 0x8F;
    Save_GameState.playerName[1] = 0x95;
    Save_GameState.playerName[2] = 0xB7;
    Save_GameState.playerName[3] = 0xFF;
    Save_GameState.bits = 0x1F4;
    Save_GameState.field_D1[0] = 0x9E;
    Save_GameState.field_D1[1] = 0xD5;
    Save_GameState.field_D1[2] = 0x96;
    Save_GameState.field_D1[3] = 0xFF;
    Save_GameState.playTime = 0;
}

void Beetle_SetPart(s32 i, s32 v, s32 flag) {
    GameStateView *p = Save_GameStatePtr;

    p->slotItems[i] = v;
    p->slotStatus[i] = (v != 0) ? flag : 1;
}

s32 Beetle_GetPart(s32 i) {
    GameStateView *p = Save_GameStatePtr;
    if (p->slotStatus[i] == 1) {
        return -1;
    }
    return p->slotItems[i];
}

void Beetle_SetPartBroken(s32 i, s32 v) {
    GameStateView *p = Save_GameStatePtr;

    p->slotStatus[i] = (p->slotItems[i] != 0) ? v : 0;
}

u8 Beetle_GetDigiCapacity(void) {
    u8 result = 0;
    s32 v = Beetle_GetPart(2) - 0x2F;
    if ((u32)v < 6) {
        result = Beetle_PartDigiCapacity[v];
    }
    return result;
}

s32 Item_FindFreeBagSlot(void) {
    s32 r;
    s32 n;
    s32 i;

    r = -1;
    n = Item_GetBagCapacity();
    for (i = 0; i < n; i++) {
        if (Save_GameStatePtr->bagItems[i] == 0) {
            r = i;
            goto done;
        }
    }
done:
    return r;
}

void Item_CompactBag(void) {
    u16 *src;
    u16 *dst;
    s32 i;
    s32 v;

    src = Save_GameStatePtr->bagItems;
    dst = src;
    for (i = 0; i < 0x30; i++, src++) {
        v = *src;
        *src = 0;
        if (((s32 (*)(s32))Item_CheckId)(v & 0xFFFF) == 0) {
            *dst = v;
            if ((v & 0xFFFF) != 0) {
                dst++;
            }
        }
    }
}

void Item_SortList(void) {
    u16 *base = Save_GameStatePtr->bagItems;
    u16 *pi;
    s32 i;
    s32 j;
    s32 best;
    s32 bestv;
    s32 v;
    u16 t;

    Item_CompactBag();
    pi = base;
    for (i = 0; i < 0x2F; i++, pi++) {
        if (*pi == 0) {
            return;
        }
        best = i;
        bestv = Item_GetTableIndex(*pi);
        for (j = i + 1; j < 0x30; j++) {
            if (base[j] == 0) {
                break;
            }
            v = Item_GetTableIndex(base[j]);
            if (v < bestv) {
                best = j;
                bestv = v;
            }
        }
        if (best != i) {
            t = *pi;
            *pi = base[best];
            base[best] = t;
        }
    }
}

s32 Item_AddToBag(s32 id) {
    s32 i = Item_FindFreeBagSlot();
    if (i != -1) {
        Save_GameStatePtr->bagItems[i] = id;
    }
    return i;
}

void Item_RemoveFromBag(s32 i) {
    Save_GameStatePtr->bagItems[i] = 0;
    Item_CompactBag();
}

s32 Item_GetBagCapacity(void) {
    u16 v = Save_GameStatePtr->slot4Item;
    s32 r = v - 0x49;
    s32 ret = 8;
    if ((u32)(v - 0x4B) < 5) {
        ret = r * 8;
    }
    return ret;
}

s32 Digi_CountByState(s32 mode) {
    s32 n = 0;
    s32 i;
    DigiRosterEntry *e = Save_GameStatePtr->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->state == mode) n++;
            break;
        case 2:
            if (e->state >= 2) n++;
            break;
        case 3:
            if (e->state >= 3) n++;
            break;
        case 4:
            if (e->state == 2) n++;
            break;
        }
    }
    return n;
}

s32 Digi_ListByState(s32 mode, DigiRosterEntry **list) {
    s32 n = 0;
    s32 i;
    DigiRosterEntry *e = Save_GameStatePtr->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->state == mode) {
                list[n++] = e;
            }
            break;
        case 2:
            if (e->state >= 2) {
                list[n++] = e;
            }
            break;
        case 3:
            if (e->state >= 3) {
                list[e->state - 3] = e;
                n++;
            }
            break;
        case 4:
            if (e->state == 2) {
                list[n++] = e;
            }
            break;
        }
    }
    return n;
}

void Digi_CompactRoster(void) {
    DigiRosterEntry tmp;
    DigiRosterEntry *src;
    DigiRosterEntry *dst;
    s32 i;

    src = Save_GameStatePtr->elems;
    dst = src;
    for (i = 0; i < 0x24; i++, src++) {
        tmp = *src;
        src->state = 0;
        if (tmp.state != 0) {
            *dst = tmp;
            if (dst->state != 0) {
                dst++;
            }
        }
    }
}

void Digi_SortRoster(void) {
    DigiSortRank tbl = Digi_StateSortRank[0];
    DigiRosterEntry *base = Save_GameStatePtr->elems;
    DigiRosterEntry tmp;
    s32 i;
    s32 j;
    s32 best;
    s32 bestk;
    s32 k;

    Digi_CompactRoster();
    for (i = 0; i < 0x23; i++) {
        if (base[i].state == 0) {
            return;
        }
        best = i;
        bestk = base[i].digiId + (999 - base[i].level) * 1000 + tbl.sortRank[base[i].state] * 1000000;
        for (j = i + 1; j < 0x24; j++) {
            if (base[j].state == 0) {
                break;
            }
            k = base[j].digiId + (999 - base[j].level) * 1000 + tbl.sortRank[base[j].state] * 1000000;
            if (k < bestk) {
                best = j;
                bestk = k;
            }
        }
        if (best != i) {
            tmp = base[i];
            base[i] = base[best];
            base[best] = tmp;
        }
    }
}
