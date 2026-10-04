#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/4BCC.h"
#include "main/6530.h"
#include "main/77DC.h"
#include "main/E280.h"
#include "main/105BC.h"
#include "main/12550.h"

/* Small data this unit defines (.sdata). Retail reaches it with %gp_rel here. */
GameStateView *Save_GameStatePtr = (GameStateView *)&Save_GameState;

/* Digimon a Digi-Beetle can carry, by its part 2 item id - 0x2F (Beetle_GetDigiCapacity). */
u8 Beetle_PartDigiCapacity[] = { 4, 5, 6, 7, 8, 12 };

s32 Mem_TestBit(u8 *arg0, s32 arg1) {
    s32 i = arg1 >> 3;
    s32 m = 1 << (arg1 & 7);

    return (arg0[i] & m) != 0;
}

extern s32 Mem_TestBit(u8 *, s32);
extern s32 Stg20_TestSpecialFlag(s32);

s32 Flag_Test(s32 arg0) {
    s32 i;

    if (arg0 < 0x258) {
        return Mem_TestBit(Flag_Bits.flags0, arg0);
    }
    if (arg0 < 0x2BC) {
        return Mem_TestBit(Flag_Bits.flags600, arg0 - 0x258);
    }
    if (arg0 < 0x320) {
        return Mem_TestBit(Flag_Bits.flags700, arg0 - 0x2BC);
    }
    if (arg0 < 0x3E8) {
        return Mem_TestBit(Flag_Bits.flags800, arg0 - 0x320);
    }
    if (arg0 < 0x44C) {
        return Flag_Bits.progress >= arg0 - 0x3E8;
    }
    if (arg0 < 0x640) {
        return Flag_Bits.progress < arg0 - 0x5DC;
    }
    if (arg0 < 0x8BD) {
        for (i = 0; i < 0x30; i++) {
            if (((V66_21E78 *)&Save_GameState)->a[i] == arg0 - 0x7D0) {
                return 1;
            }
        }
        return 0;
    }
    if (arg0 < 0xBB8) {
        return ((VDD4_21E78 *)&Save_GameState)->a[arg0 - 0x7D0] != 0;
    }
    if (arg0 < 0xFA0) {
        s32 key = arg0 - 0xBB8;
        for (i = 0; i < 0x24; i++) {
            if (((EntV_21E78 *)&Save_GameState)->elems[i].field_1 == key) {
                if (((EntV_21E78 *)&Save_GameState)->elems[i].field_0 >= 2) {
                    return 1;
                }
            }
        }
        return 0;
    }
    if (Ovl_GetCurrentId() == 2) {
        return Stg20_TestSpecialFlag(arg0);
    }
    return 0;
}

s32 Flag_TestConds(Ent22038 *p) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (p[i].id != -1) {
            if (p[i].flag != 0) {
                if (Flag_Test(p[i].id) != 1) {
                    return 0;
                }
            } else {
                if (Flag_Test(p[i].id) != 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


void Mem_WriteBit(u8 *arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 >> 3;
    s32 mask = 1 << (arg1 & 7);
    if (arg2 != 0) {
        arg0[idx] |= mask;
    } else {
        arg0[idx] &= ~mask;
    }
}

void Digi_AddNew(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state == 0) {
            break;
        }
    }
    Digi_InitFromTable(arg0, 0, &Save_GameState.elems[i]);
    Digi_SortRoster();
    for (i = 0; i < 3; i++) {
        Save_GameState.elems[i].state =
            (Save_GameState.elems[i].state >= 2) ? (i + 3) : 0;
    }
}

void Flag_Set(s32 id, s32 val) {
    if (id < 600) {
        if (id == 0x10 && val == 0) {
            Mem_WriteBit(Flag_Bits.flags0, 0x11, 0);
        }
        Mem_WriteBit(Flag_Bits.flags0, id, val);
    } else if (id < 700) {
        Mem_WriteBit(Flag_Bits.flags600, id - 600, val);
    } else if (id < 800) {
        Mem_WriteBit(Flag_Bits.flags700, id - 700, val);
    } else if (id < 1000) {
        Mem_WriteBit(Flag_Bits.flags800, id - 800, val);
    } else if (id < 2000) {
        Flag_Bits.progress = id - 1900;
    } else if (id < 0x8BD) {
        Save_GameState.field_C4 = id - 2000;
        Item_SortList();
    } else if (id < 3000) {
        ((VDD4_21E78 *)&Save_GameState)->a[id - 2000]++;
    } else if (id < 4000) {
        switch (id - 3000) {
        case 3:
            Digi_AddNew(0xB7);
            break;
        case 31:
            Digi_AddNew(0xB6);
            break;
        case 217:
            Digi_AddNew(0xB8);
            break;
        }
    } else if (id < 10000) {
        if (Ovl_GetCurrentId() == 2) {
            Stg20_SetSpecialFlag(id, val);
        }
    }
}

void Flag_ApplySets(FlagSetPair *p) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (p[i].flag != -1) {
            Flag_Set(p[i].flag, p[i].value);
        }
    }
}

s32 Math_CycleRange(s32 v, s32 div, s32 lo, s32 hi) {
    s32 r;
    v /= div;
    if (lo < hi) {
        r = v % (hi - lo + 1);
        return r + lo;
    } else {
        r = v % (lo - hi + 1);
        return lo - r;
    }
}


s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi) {
    s32 span;
    s32 r;

    v /= div;
    span = hi - lo;
    r = v % (span * 2);
    if (r < span) {
        return r + lo;
    }
    return hi - (r - span);
}


void Save_ResetGameState(void) {
    Mem_Zero(Save_GameStatePtr, 0x1058);
    Save_GameStatePtr->field_0 = 1;
    Save_ClearEventFlags();
    Save_GameState.field_14 = 0x8F;
    Save_GameState.field_15 = 0x95;
    Save_GameState.field_16 = 0xB7;
    Save_GameState.field_17 = 0xFF;
    Save_GameState.bits = 0x1F4;
    Save_GameState.field_D1 = 0x9E;
    Save_GameState.field_D2 = 0xD5;
    Save_GameState.field_D3 = 0x96;
    Save_GameState.field_D4 = 0xFF;
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
