#include "common.h"
#include "main/game.h"

/* Small data this file defines (.sbss). Retail reaches it with %gp_rel here. */
u8 Bug_LastZappedLevel;

void Bug_CompactMemBugs(void) {
    s32 i;
    s32 j;
    s32 v;

    i = 0;
    j = i;
    do {
        v = Dung_StatePtr->status.memBugLevels[i];
        Dung_StatePtr->status.memBugLevels[i] = 0;
        if (v != 0) {
            Dung_StatePtr->status.memBugLevels[j++] = v;
        }
        i++;
    } while (i < 12);
}

s32 *Item_GetEffectRec(s32 id) {
    s32 *base = 0;
    u32 i;
    s32 key;

    if ((i = id - 0x78) < 0x10) {
        key = 0x5130000;
    } else if ((i = id - 0xD0) < 0x1A) {
        key = 0x5130001;
    } else if ((i = id - 0x97) < 0xF) {
        key = 0x5130002;
    } else {
        goto end;
    }
    base = (s32 *)Cd_GetFileEntry(key);
    id = i;
end:
    if (base != 0) {
        base = &base[id];
    }
    return base;
}

s32 Item_GetUseKind(s32 arg0) {
    s32 r = 0;
/* Unnamed: ITEMDATA word0 bits 30-31, gates Item_GetUseKind; set/clear pattern across items
 * (disks/chips set, antidotes/gifts/parts clear) does not prove "usable". */
    if (func_8001E134() != 0) {
        u8 *p = Item_GetEffectRec(arg0);
        if (p != 0) {
            u8 b = *p;
            if (b != 0) {
                if (b < 5) {
                    r = 1;
                } else {
                    r = 2;
                }
            }
        }
    }
    return r;
}

s32 Item_UseOnBeetle(s32 a0, s32 a1, s32 a2, s32 a3) {
    ItemEffect *rec;
    s32 r;
    s16 *p;
    s16 *q;
    u8 v;
    s32 c;
    s32 i;
    s32 j;
    s32 best;
    s32 max;
    s32 n;
    s32 cnt;
    s32 k;
    DungState *b;

    rec = (ItemEffect *)Item_GetEffectRec(a0);
    r = 0;
    switch (rec->effectType) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    default:
        if (rec->effectType == 0) {
            p = &Save_GameStatePtr->hp;
            q = &Save_GameStatePtr->maxHp;
        } else {
            p = &Save_GameStatePtr->mp;
            q = &Save_GameStatePtr->maxMp;
        }
        if (*p >= *q) {
            return r;
        }
        *p = (*q < *p + rec->amount) ? *q : (s16)(*p + rec->amount);
        r = 1;
        break;
    case 0xB:
        if (Beetle_GetPart(a2) < 0) {
            Beetle_SetPartBroken(a2, 0);
            r = 1;
        }
    case 0xC:
    case 0xD:
    case 0xE:
        k = rec->effectType - 0xC;
        b = Dung_StatePtr;
        c = b->status.bugLevels[k];
        v = c;
        if (c != 0) {
            r = 2;
            if (rec->amount >= v) {
                b->status.bugLevels[k] = 0;
                r = 1;
            }
        }
        break;
    case 0xF:
        if (Dung_StatePtr->status.memBugCount != 0) {
            best = -1;
            max = 0;
            for (j = 0; j < Dung_StatePtr->status.memBugCount; j++) {
                v = Dung_StatePtr->status.memBugLevels[j];
                if (rec->amount >= v && max < v) {
                    best = j;
                    max = v;
                }
            }
            r = 1;
            if (best == -1) {
                goto none;
            }
            Dung_StatePtr->status.memBugCount--;
            Dung_StatePtr->status.memBugLevels[best] = 0;
            Bug_CompactMemBugs();
            Bug_LastZappedLevel = max;
            break;
        }
        break;
    case 0x10:
        if (Dung_StatePtr->status.bugLevels[0] + Dung_StatePtr->status.bugLevels[1] + Dung_StatePtr->status.bugLevels[2] + Dung_StatePtr->status.memBugCount != 0) {
            cnt = 0;
            for (i = 0; i < 3; i++) {
                if (Dung_StatePtr->status.bugLevels[i] != 0 && rec->amount >= Dung_StatePtr->status.bugLevels[i]) {
                    Dung_StatePtr->status.bugLevels[i] = 0;
                    cnt++;
                }
            }
            n = Dung_StatePtr->status.memBugCount;
            for (i = 0; i < n; i++) {
                if (rec->amount >= Dung_StatePtr->status.memBugLevels[i]) {
                    Dung_StatePtr->status.memBugLevels[i] = 0;
                    b = Dung_StatePtr;
                    b->status.memBugCount--;
                    cnt++;
                }
            }
            Bug_CompactMemBugs();
            r = 1;
            if (cnt == 0) {
            none:
                r = 2;
            }
        }
        break;
    }
    return r;
}

s32 Item_ApplyToDigi(s32 a0, s32 a1, s32 a2, s32 a3) {
    DigiRosterItemView *o = (DigiRosterItemView *)a3;
    ItemEffect *r = (ItemEffect *)Item_GetEffectRec(a0);
    s16 *cur;
    s16 *lim;
    s16 step;

    if (r->useType == 3 && r->amount != ((s32 (*)(s32))Digi_GetType)(o->digiId)) {
        return 0;
    }
    if (r->effectType == 3) {
        if (o->hp != 0) {
            return 0;
        }
        o->hp = o->maxHp;
        return 1;
    }
    if (o->hp == 0) {
        return 0;
    }
    if (r->effectType == 0) {
        cur = &o->hp;
        lim = &o->maxHp;
    } else {
        cur = &o->mp;
        lim = &o->maxMp;
    }
    if (*cur == *lim) {
        return 0;
    }
    if (r->useType == 3) {
        step = *lim - *cur;
    } else {
        step = r->amount;
    }
    *cur = (*lim < *cur + step) ? *lim : (s16)(*cur + step);
    return 1;
}

s32 Item_UseStatBoost(s32 a0, s32 a1, s32 a2, s32 a3) {
    DigiRosterBoostView *dg = (DigiRosterBoostView *)a3;
    ItemStatEffect *rec;
    s16 *p;
    s32 d;
    s32 n;
    s32 inc;

    rec = (ItemStatEffect *)Item_GetEffectRec(a0);
    if (dg->hp == 0) {
        return 0;
    }
    switch (rec->effectType) {
    case 9:
        d = rec->amount;
        if (d > 0 && d + dg->dp >= 100) {
            return 0;
        }
        if (d < 0 && d + dg->dp < 0) {
            return 0;
        }
        dg->dp += rec->amount;
        return 1;
    case 10:
        if (dg->exp == 99999999) {
            return 0;
        }
        d = dg->exp += rec->amount;
        if (d > 99999999) {
            d = 99999999;
        }
        dg->exp = d;
        return 1;
    case 4:
    default:
        p = &dg->maxHp;
        break;
    case 5:
        p = &dg->maxMp;
        break;
    case 6:
        p = &dg->attack;
        break;
    case 7:
        p = &dg->defense;
        break;
    case 8:
        p = &dg->speed;
        break;
    }
    if (*p == 999) {
        return 0;
    }
    n = (Rand_Next() & 0xFFF) * 100 / 0x21000;
    inc = 3;
    if (n < 3) {
        inc = n + 1;
    }
    n = inc;
    *p = (*p + n < 1000) ? (s16)(*p + n) : 999;
    return 1;
}

s32 Item_UseRecoverAll(s32 a0, s32 a1) {
    DigiRosterEntry *e = Save_GameStatePtr->elems;
    ItemRecoverEffect *c = (ItemRecoverEffect *)Item_GetEffectRec(a0);
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x24; i++, e++) {
        s16 cur;
        s16 max;
        if (e->state < 2) continue;
        cur = e->hp;
        if (cur == 0) continue;
        if (c->effectType == 0 || c->effectType == 2) {
            s32 m;

            max = m = (u16)e->maxHp;
            if (cur != max) {
                if (c->amount == 0) {
                    e->hp = max;
                } else {
                    e->hp = max < cur + c->amount ? max : e->hp + c->amount;
                }
                n++;
            }
        }
        if ((u8)(c->effectType - 1) < 2) {
            cur = e->mp;
            max = e->maxMp;
            if (cur != max) {
                if (c->amount == 0) {
                    e->mp = max;
                } else {
                    e->mp = max < cur + c->amount ? max : e->mp + c->amount;
                }
                n++;
            }
        }
    }
    return n != 0;
}

s32 Item_Use(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p;
    s32 r;

    p = (u8 *)Item_GetEffectRec(a0);
    r = 0;
    if (p != NULL) {
        switch (*p) {
        case 5:
            r = Item_UseOnBeetle(a0, a1, a2, a3);
            break;
        case 1:
        case 3:
            r = Item_ApplyToDigi(a0, a1, a2, a3);
            break;
        case 4:
            r = Item_UseStatBoost(a0, a1, a2, a3);
            break;
        case 2:
            r = Item_UseRecoverAll(a0, a1);
            break;
        }
        if (r != 0) {
            Item_RemoveFromBag(a1);
        }
    }
    return r;
}
