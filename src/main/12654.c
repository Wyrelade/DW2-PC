#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/4BCC.h"
#include "main/12550.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
GameStateView *D_80050720;

s32 Mem_TestBit(u8 *arg0, s32 arg1) {
    s32 i = arg1 >> 3;
    s32 m = 1 << (arg1 & 7);

    return (arg0[i] & m) != 0;
}

extern s32 Mem_TestBit(u8 *, s32);
extern s32 func_80066B48(s32);

s32 Flag_Test(s32 arg0) {
    s32 i;

    if (arg0 < 0x258) {
        return Mem_TestBit(D_8005F624.flags0, arg0);
    }
    if (arg0 < 0x2BC) {
        return Mem_TestBit(D_8005F624.flags600, arg0 - 0x258);
    }
    if (arg0 < 0x320) {
        return Mem_TestBit(D_8005F624.flags700, arg0 - 0x2BC);
    }
    if (arg0 < 0x3E8) {
        return Mem_TestBit(D_8005F624.flags800, arg0 - 0x320);
    }
    if (arg0 < 0x44C) {
        return D_8005F624.field_40 >= arg0 - 0x3E8;
    }
    if (arg0 < 0x640) {
        return D_8005F624.field_40 < arg0 - 0x5DC;
    }
    if (arg0 < 0x8BD) {
        for (i = 0; i < 0x30; i++) {
            if (((V66_21E78 *)&D_8005E620)->a[i] == arg0 - 0x7D0) {
                return 1;
            }
        }
        return 0;
    }
    if (arg0 < 0xBB8) {
        return ((VDD4_21E78 *)&D_8005E620)->a[arg0 - 0x7D0] != 0;
    }
    if (arg0 < 0xFA0) {
        s32 key = arg0 - 0xBB8;
        for (i = 0; i < 0x24; i++) {
            if (((EntV_21E78 *)&D_8005E620)->elems[i].field_1 == key) {
                if (((EntV_21E78 *)&D_8005E620)->elems[i].field_0 >= 2) {
                    return 1;
                }
            }
        }
        return 0;
    }
    if (Ovl_GetCurrentId() == 2) {
        return func_80066B48(arg0);
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
        if (D_8005E620.elems[i].state == 0) {
            break;
        }
    }
    Digi_InitFromTable(arg0, 0, &D_8005E620.elems[i]);
    Digi_SortRoster();
    for (i = 0; i < 3; i++) {
        D_8005E620.elems[i].state =
            (D_8005E620.elems[i].state >= 2) ? (i + 3) : 0;
    }
}

void Flag_Set(s32 id, s32 val) {
    if (id < 600) {
        if (id == 0x10 && val == 0) {
            Mem_WriteBit(D_8005F624.flags0, 0x11, 0);
        }
        Mem_WriteBit(D_8005F624.flags0, id, val);
    } else if (id < 700) {
        Mem_WriteBit(D_8005F624.flags600, id - 600, val);
    } else if (id < 800) {
        Mem_WriteBit(D_8005F624.flags700, id - 700, val);
    } else if (id < 1000) {
        Mem_WriteBit(D_8005F624.flags800, id - 800, val);
    } else if (id < 2000) {
        D_8005F624.field_40 = id - 1900;
    } else if (id < 0x8BD) {
        D_8005E620.field_C4 = id - 2000;
        Item_SortList();
    } else if (id < 3000) {
        ((VDD4_21E78 *)&D_8005E620)->a[id - 2000]++;
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
            func_80066F34(id, val);
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
    Mem_Zero(D_80050720, 0x1058);
    D_80050720->field_0 = 1;
    Save_ClearEventFlags();
    D_8005E620.field_14 = 0x8F;
    D_8005E620.field_15 = 0x95;
    D_8005E620.field_16 = 0xB7;
    D_8005E620.field_17 = 0xFF;
    D_8005E620.field_8 = 0x1F4;
    D_8005E620.field_D1 = 0x9E;
    D_8005E620.field_D2 = 0xD5;
    D_8005E620.field_D3 = 0x96;
    D_8005E620.field_D4 = 0xFF;
    D_8005E620.playTime = 0;
}


void func_800224EC(s32 i, s32 v, s32 flag) {
    GameStateView *p = D_80050720;

    p->slotItems[i] = v;
    p->slotStatus[i] = (v != 0) ? flag : 1;
}


s32 func_80022518(s32 i) {
    GameStateView *p = D_80050720;
    if (p->slotStatus[i] == 1) {
        return -1;
    }
    return p->slotItems[i];
}


void func_8002254C(s32 i, s32 v) {
    GameStateView *p = D_80050720;

    p->slotStatus[i] = (p->slotItems[i] != 0) ? v : 0;
}


u8 func_80022578(void) {
    u8 result = 0;
    s32 v = func_80022518(2) - 0x2F;
    if ((u32)v < 6) {
        result = D_800416FC[v];
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
        if (D_80050720->bagItems[i] == 0) {
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

    src = D_80050720->bagItems;
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
    u16 *base = D_80050720->bagItems;
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
        D_80050720->bagItems[i] = id;
    }
    return i;
}


void Item_RemoveFromBag(s32 i) {
    D_80050720->bagItems[i] = 0;
    Item_CompactBag();
}


s32 Item_GetBagCapacity(void) {
    u16 v = D_80050720->slot4Item;
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
    DigiRosterEntry *e = D_80050720->elems;

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


#ifdef NORMALIZED
s32 Digi_ListByState(s32 mode, DigiRosterEntry **list) {
    s32 n = 0;
    s32 i;
    DigiRosterEntry **p = list;
    DigiRosterEntry *e = D_80050720->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->state == mode) {
                *p++ = e;
                n++;
            }
            break;
        case 2:
            if (e->state >= 2) {
                *p++ = e;
                n++;
            }
            break;
        case 3:
            if (e->state >= 3) {
                p++;
                list[e->state - 3] = e;
                n++;
            }
            break;
        case 4:
            if (e->state == 2) {
                *p++ = e;
                n++;
            }
            break;
        }
    }
    return n;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Digi_ListByState);
s32 Digi_ListByState(s32 mode, DigiRosterEntry **list);
#endif


void Digi_CompactRoster(void) {
    DigiRosterEntry tmp;
    DigiRosterEntry *src;
    DigiRosterEntry *dst;
    s32 i;

    src = D_80050720->elems;
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
    DigiSortRank tbl = D_80050724[0];
    DigiRosterEntry *base = D_80050720->elems;
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
