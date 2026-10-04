#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"
#include "stag4000/stag4000_8338_funcs.h"
#include "stag4000/stag4000_9364_funcs.h"

s32 func_8006D4E0(kind, a1, a2, a3, x, y)
    s32 kind;
    s32 a1;
    s32 a2;
    s16 a3;
    s16 x;
    s16 y;
{
    Stg40Ent48 *e;
    s32 flag = 0;
    s32 n;
    s16 h;

    e = &D_8005071C->field_18[D_8005071C->field_C];
    if (D_8005071C->field_C >= 41) {
        return -1;
    }
    e->field_7 = D_8005071C->field_C;
    e->field_6 = 0;
    e->field_0 = 0xC000;
    e->field_8 = kind;
    e->field_9 = a1;
    e->field_4 = a2;
    h = (a3 << 12) / 360;
    e->field_C = h;
    e->field_E = h;
    e->field_B = h / 512;
    e->field_18.u0.pair.field_0 = x;
    e->field_18.u0.pair.field_2 = y;
    e->field_18.field_14 = 0;
    if (a2 >= 500 && a2 <= 532) {
        e->field_38 = e->field_3C = e->field_40 = 0xD99;
    } else {
        e->field_38 = e->field_3C = e->field_40 = 0x1000;
    }
    switch (e->field_8) {
    case 0:
        flag = 1;
        e->field_0 |= flag;
        e->field_10 = (u8 *)&D_8005071C->field_BA0;
        D_80072B60->field_4 = e;
        D_8005071C->field_BA0 = 0;
        D_8005071C->field_BA4 = 0;
        break;
    case 1:
        flag = 1;
        e->field_10 = D_8005071C->field_BB8[D_8005071C->field_E++];
        e->field_0 |= 2;
        break;
    case 4:
        flag = 1;
        n = D_8005071C->field_10++;
        e->field_10 = D_8005071C->field_CCE[n + 1];
        e->field_0 |= 4;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        flag = 0;
        n = D_8005071C->field_12++;
        e->field_10 = D_8005071C->field_CE8[n];
        e->field_0 |= 4;
        break;
    case 2:
    case 3:
        flag = 0;
        e->field_0 |= 4;
        break;
    }
    func_800708FC(x, y, flag);
    D_8005071C->field_C++;
    return 0;
}

void func_8006D738(void) {
    Stg40Drop *r;
    Stg40SlotInfo *s;
    Out1DB68 out;
    s32 k;
    s32 id;
    s32 i;
    s16 t;
    s32 m;
    s32 c;
    Stg40Map *map;

    for (r = D_80072B60->field_14->field_10; r->x != 0xFF; r++) {
        if (D_8005071C->field_E >= 10) {
            break;
        }
        switch (func_800711C4(4)) {
        case 0:
        default:
            k = r->pick0;
            break;
        case 1:
            k = r->pick1;
            break;
        case 2:
            k = r->pick2;
            break;
        case 3:
            k = r->pick3;
            break;
        }
        if (k != 0) {
            id = k[((Stg40Map *)D_80072B60->field_10)->field_2F];
            Enemy_GetSetSummary(id, &out);
            c = out.field_0;
            func_8006D4E0(1, 0, c, 0, r->x, r->y);
            s = (Stg40SlotInfo *)D_8005071C->field_BB8[D_8005071C->field_E - 1];
            s->field_0 = id;
            s->field_2 = out.field_10 != 0;
            s->field_3 = out.field_C;
            s->field_E = out.field_18;
            t = s->field_E;
            if (t == 0) {
                t = 1;
            }
            s->field_E = t;
            s->field_A = 0;
            s->field_C = 0;
            s->field_7 = D_80072904[out.field_8 * 2];
            s->field_6 = D_80072904[out.field_8 * 2 + 1];
            s->field_4 = D_800728F4[out.field_4 * 2];
            m = s->field_5 = D_800728F4[out.field_4 * 2 + 1];
            if (m == 2) {
                if (s->field_4 != (func_800703E0(r->x, r->y) & 0xF)) {
                    s->field_4 = m;
                    s->field_5 = 0;
                }
            }
            s->field_B = 0;
            for (i = 0; i < 3; i++) {
                if ((s16)out.digiIds[i] == 0) {
                    break;
                }
                s->field_10[i] = out.digiIds[i];
                s->field_16[i] = out.levels[i];
                s->field_B++;
            }
        }
    }
}

void func_8006DA18(void) {
    Stg40MapPos *pos = ((Stg40Map *)D_80072B60->field_10)->field_34;
    Stg40Drop *r;
    s32 k;
    u8 *d;

    for (r = D_80072B60->field_14->field_8; r->x != 0xFF; r++) {
        if (D_8005071C->field_10 >= 12) {
            break;
        }
        switch (func_800711C4(4)) {
        case 0:
        default:
            k = r->pick0;
            break;
        case 1:
            k = r->pick1;
            break;
        case 2:
            k = r->pick2;
            break;
        case 3:
            k = r->pick3;
            break;
        }
        if (k != 0) {
            func_8006D4E0(4, 0, 0x276, 0, r->x, r->y);
            k--;
            d = D_8005071C->field_CCE[D_8005071C->field_10];
            d[0] = pos[k].field_0;
            d[1] = pos[k].field_1;
        }
    }
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_8006362C);
s32 func_8006DB68(a0, a1, a2, a3)
    s32 a0;
    s32 a1;
    s16 a2;
    s16 a3;
{
    Stg40Ids4 tbl;
    s32 lvl;
    s32 t;
    s32 u;
    s32 m;
    s32 kind;
    s32 model;
    s32 id;
    s32 bit;
    Stg40Rec3 *r;
    u8 *d;

    lvl = a1;
    u = lvl;
    if (lvl == 0) {
        u = 1;
    }
    lvl = u;
    switch (a0) {
    case 0:
    default:
        return 0;
    case 2:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x25A;
        kind = 6;
        bit = lvl - 1;
        break;
    case 3:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x25F;
        kind = 7;
        bit = lvl + 4;
        break;
    case 4:
        t = 5;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        model = lvl + 0x270;
        kind = 8;
        bit = lvl + 9;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        tbl = D_8006362C;
        t = 3;
        t = (lvl < t) ? lvl : t;
        lvl = t;
        kind = a0 + 4;
        id = tbl.id[a0 - 5];
        t = lvl + 5;
        bit = kind + t;
        id += lvl;
        model = id - 1;
        break;
    case 1:
        m = 5;
        m = (lvl < m) ? lvl : m;
        lvl = m;
        if (D_8005071C->field_14 >= 100) {
            return -1;
        }
        r = &D_8005071C->field_D08[D_8005071C->field_14];
        r->field_0 = a2;
        r->field_1 = a3;
        r->field_2 = lvl;
        D_8005071C->field_14++;
        return 0;
    }
    if (!(bit & D_80072B60->field_188)) {
        if (D_80072B60->field_18C >= 12) {
            return -1;
        }
        D_80072B60->field_188 |= bit;
        D_80072B60->field_18C++;
    }
    if (D_8005071C->field_12 < 16) {
        func_8006D4E0(kind, a0, model, 0, a2, a3);
        d = D_8005071C->field_CE8[D_8005071C->field_12 - 1];
        d[0] = a0;
        d[1] = lvl;
        return 0;
    }
    return -1;
}

void func_8006DDDC(void) {
    Stg40Spawn *e;
    s32 kind;
    s32 val;

    for (e = D_80072B60->field_14->field_C; e->x != 0xFF; e++) {
        switch (func_800711C4(4)) {
        case 0:
        default:
            kind = e->kind0;
            val = e->val0;
            break;
        case 1:
            kind = e->kind1;
            val = e->val1;
            break;
        case 2:
            kind = e->kind2;
            val = e->val2;
            break;
        case 3:
            kind = e->kind3;
            val = e->val3;
            break;
        }
        if (kind != 0) {
            func_8006DB68(kind, val + D_8005071C->field_E54->field_C, e->x, e->y);
        }
    }
}

s32 func_8006DEF0(u8 (*tbl)[2], s32 v) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Cell *cells = (Stg40Cell *)b->field_E58;
    s32 h = b->field_E54->field_2;
    s32 w = b->field_E54->field_0;
    s32 n = 0;
    s32 x;
    s32 y;
    Stg40Cell *c;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            c = &cells[y * w + x];
            if (c->field_2 == v && !(c->field_0 & 0x40) && (c->field_0 & 0xF) < 8) {
                tbl[n][0] = x;
                tbl[n][1] = y;
                n++;
            }
        }
    }
    return n;
}

void func_8006DFA4(u8 (*tbl)[2], s32 a1, s32 a2) {
    s32 n = func_8006DEF0(tbl, func_800711C4(D_80072B60->field_0));

    if (n != 0) {
        n = func_800711C4(n);
        func_8006DB68(a1, a2, tbl[n][0], tbl[n][1]);
    }
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063664);
void func_8006E024(void) {
    Stg40Map *m = (Stg40Map *)D_80072B60->field_10;
    Stg40Ids5 ids = D_80063664;
    Stg40MapGen *g = m->field_54;
    s32 buf;
    s32 i;
    s32 j;
    s32 n;
    s32 v;

    if (D_80072B60->field_0 == 0) {
        return;
    }
    buf = Mem_Alloc(0x1800, 2);
    for (i = 0; i < 5; g++, i++) {
        switch (func_800711C4(4)) {
        case 0:
        default:
            n = g->cnt0;
            break;
        case 1:
            n = g->cnt1;
            break;
        case 2:
            n = g->cnt2;
            break;
        case 3:
            n = g->cnt3;
            break;
        }
        for (j = 0; j < n; j++) {
            switch (func_800711C4(4)) {
            case 0:
            default:
                v = g->val0;
                break;
            case 1:
                v = g->val1;
                break;
            case 2:
                v = g->val2;
                break;
            case 3:
                v = g->val3;
                break;
            }
            func_8006DFA4((u8 (*)[2])buf, ids.id[i], v);
        }
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Ent48 *func_8006E200(s16 x, s16 y) {
    Stg40Ent48 *e = D_8005071C->field_18;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < 41; i++, e++) {
        if (e->field_18.u0.pair.field_0 == x && e->field_18.u0.pair.field_2 == y && (e->field_0 & 0x8000)) {
            r = e;
            break;
        }
    }
    return r;
}

void func_8006E278(void) {
    s32 i;
    Stg40Ent48 *e = D_8005071C->field_18;

    for (i = 0; i < 41; i++, e++) {
        if (e->field_0 & 0x8000) {
            e->field_0 |= 0x5000;
        }
    }
}

s32 func_8006E2B8(Stg40Ent48 *a, Stg40Ent48 *b) {
    s16 dx;
    s16 dy;

    if (a->field_18.u0.pair.field_0 - b->field_18.u0.pair.field_0 >= 0) {
        dx = a->field_18.u0.pair.field_0 - b->field_18.u0.pair.field_0;
    } else {
        dx = b->field_18.u0.pair.field_0 - a->field_18.u0.pair.field_0;
    }
    if (a->field_18.u0.pair.field_2 - b->field_18.u0.pair.field_2 >= 0) {
        dy = a->field_18.u0.pair.field_2 - b->field_18.u0.pair.field_2;
    } else {
        dy = b->field_18.u0.pair.field_2 - a->field_18.u0.pair.field_2;
    }
    return dx < 2 && dy < 2;
}

s32 func_8006E330(void) {
    Stg40List *l = &D_8005071C->field_1018;
    Stg40Ent48 *e = D_8005071C->field_18;
    s32 i;
    s32 r;

    l->field_20 = 0;
    for (i = 0; i < D_8005071C->field_C; i++, e++) {
        if ((e->field_0 & 0x8002) == 0x8002 && e->field_14->stateLevel1 != 4) {
            r = func_8006E2B8(e, D_80072B60->field_4);
            if (r == 1) {
                l->field_0[l->field_20++] = e;
                e->field_0 |= 0x100;
                Task_SetState1(e->field_14, 3);
                e->field_0 |= (l->field_20 == r) ? 0x800 : 0;
            }
        }
    }
    if (l->field_20 != 0) {
        D_80072B60->field_4->field_0 |= 0x100;
    }
    return l->field_20;
}

s32 func_8006E490(s32 dx, s32 dy) {
    s32 idx = 0;
    s32 r;
    s32 v;

    if (dx < 0) {
        idx |= 8;
    }
    if (dx > 0) {
        idx |= 4;
    }
    if (dy < 0) {
        idx |= 2;
    }
    idx |= dy > 0;
    v = D_800728D4[idx];
    r = 0;
    if (v != -1) {
        r = v;
    }
    return r;
}

void func_8006E4DC(a0, a1)
    Actor *a0;
    s16 a1;
{
    ((Stg40ActWork *)a0->work)->field_30 = a1;
}

void func_8006E4E8(Actor *a0, s32 a1) {
    if (((Stg40ActWork *)a0->work)->field_32 != a1) {
        func_8006E4DC(a0, a1);
    }
}

s32 func_8006E520(Actor *a0) {
    s32 r = 0;

    a0->stateLevel4++;
    if (func_800678C4(a0) == 1 || a0->stateLevel4 >= 31) {
        r = 1;
    }
    return r;
}

s32 func_8006E588(Actor *a0) {
    s32 r = 0;

    a0->stateLevel4++;
    if (func_800678C4(a0) == 1 || a0->stateLevel4 >= 31 || (a0->stateLevel4 >= 11 && D_8005F704 != 0)) {
        r = 1;
    }
    return r;
}

void func_8006E60C(s32 a0) {
    s32 n;
    Blk12 *e;
    Stg40B60 *b;

    D_80072B60->field_16C = 0;
    if (a0 != 0) {
        Flag_SetTableFile(a0);
        for (n = Flag_FirstPassingEntry(); n != -1; n = Flag_NextPassingEntry()) {
            e = Flag_GetEntryPosList(n);
            b = D_80072B60;
            b->field_144[b->field_16C].u0.pair.field_0 = e->data[0] - 1;
            b->field_144[b->field_16C].u0.pair.field_2 = e->data[1] - 1;
            b->field_144[b->field_16C].field_4 = n;
            b->field_16C++;
        }
    }
}

s32 func_8006E6CC(void) {
    u32 i = 0;
    s32 r = 0;
    Stg40B60Ent *e = D_80072B60->field_144;

    for (; i < D_80072B60->field_16C; e++) {
        Stg40B60 *b = D_80072B60;
        i++;
        if (b->field_4->field_18.u0.field_0 == e->u0.field_0) {
            b->field_170 = e->field_4;
            e->u0.pair.field_2 = -1;
            e->u0.pair.field_0 = -1;
            r = -1;
            D_8005071C->field_2 = 2;
            break;
        }
    }
    return r;
}

void func_8006E764(Stg40E764 *a0, s32 a1, s32 a2) {
    if (a0->field_34 == 0) {
        a0->field_28 = 0;
        return;
    }
    if (a0->field_28 == 0) {
        if (a1 != 0) {
            Cd_QueueFile(a1);
        }
        if (a2 != 0) {
            Cd_QueueFile(a2);
        }
        a0->field_28 = 16;
    }
    a0->field_28--;
}

void func_8006E7F0(s32 i, s32 item, u8 status) {
    GameStateView *g = Save_GameStatePtr;

    g->slotItems[i] = item;
    g->slotStatus[i] = item ? status : 1;
}

s32 func_8006E820(i)
    s32 i;
{
    GameStateView *g = Save_GameStatePtr;

    if (g->slotStatus[i] == 1) {
        return -1;
    }
    return g->slotItems[i];
}

s32 func_8006E858(s32 slot) {
    GameStateView *gs = Save_GameStatePtr;
    s32 r;

    if (gs->slotItems[slot] == 0) {
        return 0;
    }
    if (gs->slotStatus[slot] == 1) {
        return -1;
    }
    r = Item_GetLevel(gs->slotItems[slot]);
    r = r ? r : 1;
    return r;
}

void func_8006E8C4(s32 i, u8 status) {
    GameStateView *g = Save_GameStatePtr;

    g->slotStatus[i] = g->slotItems[i] ? status : 0;
}

void func_8006E8F4(s32 n) {
    GameStateView *g = Save_GameStatePtr;

    g->hp = (g->hp - n < 0) ? 0 : g->hp - n;
}

s32 func_8006E920(Stg40Shop *a) {
    s32 ret;
    s32 j;
    s32 i;
    s32 key;
    u16 *bag;
    u16 *items;

    D_80072B60->field_E1 = 0;
    switch (func_8006E820(a->field_0)) {
    case -1:
        ret = a->field_C;
        break;
    case 0:
        ret = a->field_C + 1;
        break;
    default:
        for (j = 0; j < 4; j++) {
            key = a->field_2[j];
            items = Save_GameStatePtr->bagItems;
            if (key != -1) {
                for (i = 0, bag = items; i < 0x30; i++, bag++) {
                    if (*bag != 0 && key == Item_GetCategory(*bag)) {
                        D_80072B60->field_B0[D_80072B60->field_E1] = *bag;
                        D_80072B60->field_E1++;
                    }
                }
            }
        }
        if (D_80072B60->field_E1 == 0) {
            ret = a->field_C + 2;
        } else {
            ret = 0;
        }
        break;
    }
    return ret;
}

s16 func_8006EA84(s32 mode) {
    DigiRosterEntry *e = Save_GameStatePtr->elems;
    Stg40B60 *b;
    s32 *pi;
    s32 i;

    D_80072B60->field_140 = 0;
    b = D_80072B60;
    for (i = 0; i < 36; e++, i++) {
        if (e->state >= 2) {
            switch (mode) {
            case 1:
                if ((s16)e->hp == 0) {
                    continue;
                }
                b->field_128[b->field_140++] = i;
                break;
            case 2:
                if ((s16)e->hp == 0) {
                    b->field_128[b->field_140++] = i;
                }
                break;
            case 3:
                if ((s16)e->hp >= 2) {
                    b->field_128[b->field_140++] = i;
                }
                break;
            default:
                b->field_128[b->field_140++] = *(pi = &i);
                break;
            }
        }
    }
    i = D_80072B60->field_140;
    return i;
}

void func_8006EB84(s32 idx, s32 row, s32 val) {
    Stg40TileGrid *t = D_80072BB0;
    s32 sh = (idx % 4) * 4;
    u16 *p = &t->pix[(row + 1) * 18 + idx / 4 + 1];
    *p = (*p & ~(0xF << sh)) | (val << sh);
    t->field_760 = -1;
}

void func_8006EBF4(s32 x, s32 y, s32 ox, s32 oy, s32 dir) {
    s32 v;

    if (ox != -1) {
        func_8006EB84(ox, oy, (func_800703E0(ox, oy) >> 13) & 1);
    }
    if (x != -1) {
        switch (dir) {
        case 0:
            v = 14;
            break;
        case 1:
            v = 13;
            break;
        case 2:
        case 3:
            v = 10;
            break;
        case 4:
            v = 11;
            break;
        default:
            v = 12;
            break;
        }
        func_8006EB84(x, y, v);
    }
}

void func_8006ECD0(Stg40TileWork *a0) {
    s32 h = a0->field_768;
    s32 w = a0->field_766;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            func_8006EB84(x, y, (func_800703E0(x, y) >> 13) & 1);
        }
    }
}

void func_8006ED5C(void) {
    s32 i;
    u8 *p = D_8005071C->field_E7C;

    i = 0x17F;
    do {
        i--;
        *p++ = 0;
    } while (i >= 0);
    D_80072944 = 0;
}

void func_8006ED88(s32 arg0) {
    s32 n;
    u8 *p;
    Stg40Cell *c;
    s32 i;

    p = D_8005071C->field_E7C;
    c = (Stg40Cell *)D_8005071C->field_E58;
    n = D_8005071C->field_E54->field_0 * D_8005071C->field_E54->field_2 / 8;

    for (i = 0; i < n; i++) {
        if (arg0 == 0) {
            *p = 0;
            *p = (c->field_0 >> 13) & 1;
            c++;
            *p |= (c->field_0 & 0x2000) ? 2 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 4 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 8 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x10 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x20 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x40 : 0;
            c++;
            *p |= (c->field_0 & 0x2000) ? 0x80 : 0;
            c++;
        } else {
            if (*p & 1) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 2) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 4) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 8) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x10) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x20) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x40) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
            if (*p & 0x80) c->field_0 |= 0x2000; else c->field_0 &= ~0x2000;
            c++;
        }
        p++;
    }
}

void func_8006F06C(void) {
    func_8006ED5C();
    func_8006ED88(1);
}

void func_8006F094(void) {
    Stg40TileWork *t = (Stg40TileWork *)D_80072BB0;
    s32 x;
    s32 y;

    for (y = 0; y < D_8005071C->field_E54->field_2; y++) {
        for (x = 0; x < D_8005071C->field_E54->field_0; x++) {
            func_8006F62C(t, x, y);
        }
    }
}

void func_8006F168(Stg40ImgWork *a0) {
    LoadImage(&a0->rect, a0->data);
}

void func_8006F18C(Stg40TileWork *a0) {
    if (a0->field_760 != 0) {
        LoadImage(&a0->rect, a0->data);
        a0->field_760 = 0;
    }
}

void func_8006F1C8(Stg40ImgWork *a0) {
    Stg40ImgClut *p = (Stg40ImgClut *)a0;
    s32 c;
    s32 v;
    s32 h;
    s32 g;
    s32 b;

    p->field_75C++;
    c = 15 - ((p->field_75C & 0xF) >> 1);
    v = c & 0x1F;
    b = v << 10;
    g = (v << 5) | 0x8000;
    p->clut[4] = b | g;
    p->clut[3] = v | 0x8000;
    p->clut[2] = (v << 5) | 0x8000 | v;
    p->clut[1] = g;
    h = (c / 2) & 0x1F;
    p->clut[0] = b | ((h << 5) | 0x8000) | h;
    if (Pad_State[0].start != 0) {
        p->clut[6] = 0xA94A;
        p->clut[7] = 0xE318;
    } else {
        p->clut[6] = 0x8000;
        p->clut[7] = 0xA94A;
    }
    func_8006F168(a0);
}

void func_8006F290(Stg40TileWork *w) {
    GfxTexSlot *s;
    RECT *r;
    u16 *d;
    u16 *src;
    s32 i;
    s32 n;
    s32 j;
    s32 k;

    ((Stg40ImgWork *)w)->field_758 = Gfx_ReserveTexSlot();
    s = (GfxTexSlot *)((Stg40ImgWork *)w)->field_758;
    r = &((Stg40ImgWork *)w)->rect;
    r->x = s->vramX;
    r->y = s->vramY + 0xFE;
    r->w = 0x10;
    r->h = 2;
    d = (u16 *)((Stg40ImgWork *)w)->data;
    src = D_80072948;
    for (j = 0; j < 32; j++) {
        *d++ = *src++;
    }
    func_8006F168((Stg40ImgWork *)w);
    r = &w->rect;
    r->x = s->vramX;
    r->y = s->vramY;
    r->w = 0x12;
    r->h = 0x32;
    n = 0x12 * 0x32;
    d = ((Stg40TileGrid *)w)->pix;
    for (i = 0; i < n; i++) {
        *d++ = 0;
    }
    w->field_760 = -1;
    func_8006F18C(w);
    for (k = 1; k >= 0; k--) {
        w->field_762[k] = 0;
    }
}

void func_8006F38C(Stg40ImgWork *a0) {
    Gfx_ReleaseTexSlot(a0->field_758);
}

s16 func_8006F3B0(Stg40TileWork *a0) {
    Stg40Blk5071C *b = D_8005071C;

    a0->field_766 = b->field_E54->field_0;
    a0->field_768 = b->field_E54->field_2;
    return a0->field_76A = a0->field_766 / 8;
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_8006368C);
void func_8006F3F4(Stg40TileWork *w, s32 x, s32 y)
{
    s32 group;
    s32 row;
    s32 n;
    s32 mask;
    u8 kind;
    s32 dim1;
    Stg40E34 *dims;
    s32 count;
    Stg40Cell *grid;
    s32 col;
    s32 t;

    dims = D_8005071C->field_E54;
    dim1 = dims->field_0;
    count = dims->field_2;
    kind = func_80070438(x, y)->field_2;
    if (kind == 0xFF) {
        return;
    }
    group = kind >> 5;
    mask = 1 << (kind % 32);
    if (group < 8) {
        t = D_8005071C->field_E5C[group];
        if (t & mask) {
            return;
        }
        D_8005071C->field_E5C[group] |= mask;
    }
    grid = (Stg40Cell *)D_8005071C->field_E58;
    for (row = 0; row < count; row++) {
        for (col = 0; col < dim1; col++) {
            if (grid[col + row * dim1].field_2 == kind) {
                grid[col + row * dim1].field_0 |= 0x2000;
                func_8006EB84(col, row, 1);
                {
                    Stg40Offs8 o = D_8006368C;

                    for (n = 0; n < 4; n++) {
                        s32 nx = col + o.v[n * 2];
                        s32 ny = row + o.v[n * 2 + 1];

                        if ((func_800703E0(nx, ny) & 0xC000) == 0x8000) {
                            do {
                                do {
                                    t = nx + dim1 * ny;
                                    grid[t].field_0 |= 0x2000;
                                    func_8006EB84(nx, ny, 1);
                                } while (0);
                            } while (0);
                        }
                    }
                }
            }
        }
    }
}
