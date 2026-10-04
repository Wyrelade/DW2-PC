#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/stag2000_funcs.h"

void func_8006C040(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

void func_8006C074(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930008);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = D_800709B0.field_50 != 0 ? -0x57 : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}

s32 func_8006C14C(u8 *s, s32 c) {
    for (; *s != 0; s++) {
        if (*s == c) {
            return 1;
        }
    }
    return 0;
}

s32 func_8006C18C(s32 id) {
    s32 i;

    for (i = 0; i < 0x13; i++) {
        if (((Stg20GameState *)&Save_GameState)->field_2C[i] == id) {
            return 1;
        }
    }
    return 0;
}

s32 func_8006C1C4(s32 id) {
    if (func_8006C18C(id)) {
        return 0x132;
    }
    if (func_8006C14C(D_800704FC, id)) {
        return 0x131;
    }
    if (func_8006C14C(D_80070530, id)) {
        if (D_8005E65C != 0) {
            return 0x12F;
        }
        return 0x130;
    }
    if (func_8006C14C(D_80070548, id)) {
        if (D_8005E65E != 0) {
            return 0x12F;
        }
        return 0x133;
    }
    if (func_8006C14C(D_800705A4, id)) {
        if (D_8005E662 != 0) {
            return 0x12F;
        }
        return 0x135;
    }
    if (func_8006C14C(D_800705B4, id)) {
        if (D_8005E660 != 0) {
            return 0x12F;
        }
        return 0x136;
    }
    if (func_8006C14C(D_80070554, id)) {
        if (D_8005E64C == 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070570, id)) {
        if (D_8005E64C == 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070588, id)) {
        if (D_8005E64C == 0xEB) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070580, id)) {
        if (D_8005E64C != 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (func_8006C14C(D_80070594, id)) {
        if (D_8005E64C != 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    return 0;
}

s32 func_8006C3B8(s32 id) {
    s32 n;
    s32 i;
    s32 r;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (((Stg20GameState *)&Save_GameState)->field_66[i] == id) {
            n++;
        }
    }
    n += ((Stg20GameState *)&Save_GameState)->field_DD4[id];
    r = 99;
    if (n < 100) {
        r = n;
    }
    return r;
}

void func_8006C420(u8 *out, s32 v) {
    u8 d[5];
    s32 n;
    s32 i;
    s32 lead;

    n = Item_GetPrice(v);
    if (D_80070A04 != 0) {
        n /= 2;
    }
    n = n < 0 ? 0 : n;
    for (i = 4; i != -1; i--) {
        d[i] = n % 10;
        n /= 10;
    }
    lead = 1;
    for (i = 0; i < 5; i++) {
        if (i == 4 || lead == 0 || d[i] != 0) {
            lead = 0;
            out[i] = d[i];
        }
    }
}

void func_8006C514(Actor *a, s32 id) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    s32 i;
    s32 j;
    u8 *name;
    u8 *list = (u8 *)Cd_GetFileEntry(id + 0x3CF0000);

    w->count = 0;
    for (i = 0; i < 50; i++) {
        D_80070A08.items[i] = 0;
        for (j = 0; j < 25; j++) {
            D_80070A08.names[i][j] = 0xFD;
        }
        D_80070A08.names[i][24] = 0xFF;
    }
    for (i = 0; i < 50; i++) {
        if (list[i] == 0) {
            break;
        }
        D_80070A08.items[i] = list[i];
        name = (u8 *)Item_GetNameText(list[i]);
        for (j = 0; j < 10; j++) {
            if (*name == 0xFF) {
                break;
            }
            D_80070A08.names[i][j] = *name++;
        }
        func_8006C420(&D_80070A08.names[i][14], list[i]);
        D_80070A08.names[i][19] = 0xB;
        D_80070A08.names[i][20] = 0x12;
        D_80070A08.names[i][21] = 0x1D;
        D_80070A08.names[i][22] = 0x36;
        w->count++;
    }
    w->pages = w->count != 0 ? (w->count - 1) / 8 : 0;
}

void func_8006C6F0(Actor *a) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    s32 i;
    s32 j;
    u8 *name;
    u16 *list = D_8005E686;
    s32 k;

    w->count = 0;
    for (i = 0; i < 50; i++) {
        D_80070A08.items[i] = 0;
        for (j = 0; j < 25; j++) {
            D_80070A08.names[i][j] = 0xFD;
        }
        D_80070A08.names[i][24] = 0xFF;
    }
    for (i = 0, k = 0; i < 0x30; k++, i++) {
        if (list[i] == 0) {
            break;
        }
        D_80070A08.items[k] = list[i];
        name = (u8 *)Item_GetNameText(list[i]);
        for (j = 0; j < 10; j++) {
            if (*name == 0xFF) {
                break;
            }
            D_80070A08.names[k][j] = *name++;
        }
        func_8006C420(&D_80070A08.names[k][14], list[i]);
        D_80070A08.names[k][19] = 0xB;
        D_80070A08.names[k][20] = 0x12;
        D_80070A08.names[k][21] = 0x1D;
        D_80070A08.names[k][22] = 0x36;
        w->count++;
    }
    w->pages = w->count != 0 ? (w->count - 1) / 8 : 0;
}

void func_8006C8BC(Actor *a) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    Stg20TextArgs args;
    s32 page;
    s32 base;
    s32 i;
    s32 id;

    if (w->dirty != 0) {
        page = w->page;
        if (w->pages < page) {
            page = w->pages;
        }
        base = page * 8;
        w->page = page;
        args.bigFont = 0;
        args.color = 0;
        args.pos.x = 0x21;
        args.charAdvance = 0;
        args.lineAdvance = 0;
        args.charDelay = 0;
        for (i = 0; i < 8; i++) {
            Text_Close(&w->texts[i]);
        }
        for (i = 0; i < 8; i++) {
            if (D_80070A08.items[i + base] == 0) {
                break;
            }
            args.text = (s32)D_80070A08.names[i + base];
            args.pos.y = 0x30 + i * 12;
            w->field_50 = 9;
            w->field_51 = 0xFF;
            Text_Open(&w->texts[i], &args);
        }
        id = D_80070A08.items[w->cursor + w->page * 8];
        Text_Close(&w->descText);
        if (id != 0) {
            args.text = Item_GetDescText(id);
            args.pos.x = 0x13;
            args.bigFont = 0;
            args.color = 0;
            args.pos.y = 0xA2;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            args.charDelay = 0;
            Text_Open(&w->descText, &args);
        }
        if (D_80070A04 == 0) {
            if (id != 0) {
                w->field_58 = func_8006C3B8(id);
            } else {
                w->field_58 = 0;
            }
        }
        Text_Close(&w->text14);
        if (w->field_5C != 0) {
            args.text = (s32)Cd_GetFileEntry(w->field_5C + 0x1FD0000);
            args.bigFont = 1;
            args.color = 0;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            args.charDelay = 0;
            args.pos.x = D_800704E4[4].x;
            args.pos.y = D_800704E4[4].y;
            Text_Open(&w->text14, &args);
        }
        Text_Close(&w->text18);
        if (w->field_60 != 0) {
            args.text = (s32)Cd_GetFileEntry(w->field_60 + 0x1FD0000);
            args.bigFont = 1;
            args.color = 0;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            args.charDelay = 0;
            args.pos.x = D_800704E4[5].x;
            args.pos.y = D_800704E4[5].y;
            Text_Open(&w->text18, &args);
        }
        w->dirty = 0;
    }
}

void func_8006CB58(Actor *a) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    s32 id;
    s32 idx;
    Stg20GameState *g;
    PadState *pad;
    s32 item;
    Stg20MenuSub *m;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->hdr, 0xF);
        Task_Create(0x30D, slot, 0);
        Text_OpenById(&w->hdr[0], 0x12D, 4, *(Halves *)&D_800704E4[0]);
        Text_OpenById(&w->hdr[1], D_800709B0.field_54 + 0x12B, 4, *(Halves *)&D_800704E4[1]);
        Text_OpenById(&w->hdr[2], 0xFA, 0, *(Halves *)&D_800704E4[2]);
        if (D_800709B0.field_54 == 0) {
            Text_OpenById(&w->hdr[3], 0x12E, 0, *(Halves *)&D_800704E4[3]);
        }
        if (D_800709B0.field_54 == 0) {
            func_8006C514(a, Sys_State.modeArg);
        } else {
            func_8006C6F0(a);
        }
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                w->dirty = 1;
                Task_NextState2(a);
            case 1:
                break;
            }
            do {
                w->field_5C = 0x138;
                w->field_60 = 0;
            } while (0);
            m = &D_800709B8;
            if ((Pad_State->repeat & 0x1000) && w->cursor != 0) {
                goto up;
            }
            if ((Pad_State->repeat & 0x4000) && w->cursor != 7) {
                goto down;
            }
            pad = Pad_State;
            if (pad->right > 0) {
                if (w->page != w->pages) {
                    w->page++;
                    w->dirty = 1;
                    Snd_PlayById(0xD, 0);
                }
            } else if (Pad_State->left > 0) {
                if (w->page != 0) {
                    w->page--;
                    w->dirty = 1;
                    Snd_PlayById(0xD, 0);
                }
            } else if (Pad_State->triangle > 0) {
                goto cancel;
            } else if (pad->cross > 0) {
                if (m->field_4C == 0) {
                    item = D_80070A08.items[w->cursor + w->page * 8];
                    if (item != 0) {
                        if (Item_GetPrice(item) > D_8005E628) {
                            w->field_5C = 0x139;
                            w->dirty = 1;
                            Snd_PlayById(0x10, 0);
                        } else {
                            goto buy;
                        }
                    }
                } else {
                    item = D_80070A08.items[w->cursor + w->page * 8];
                    if (item != 0) {
                        if (Item_GetPrice(item) != 0) {
                            goto sell;
                        }
                        Snd_PlayById(0x10, 0);
                    }
                }
            }
            break;
        case 1:
            id = D_80070A08.items[w->cursor + w->page * 8];
            switch (a->stateLevel2) {
            case 0:
            default:
                w->field_5C = func_8006C1C4(id);
                w->field_60 = 0x137;
                w->dirty = 1;
                Flag_Set(0x10, 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (Flag_Test(0x10) != 0 && Flag_Test(0x11) == 0) {
                Snd_PlayById(0xF, 0);
                g = (Stg20GameState *)&Save_GameState;
                g->field_DD4[id] = g->field_DD4[id] == 99 ? 99 : g->field_DD4[id] + 1;
                Save_GameState.bits -= Item_GetPrice(id);
                Task_SetState1(a, 0);
            } else if (D_8005F70C > 0 || Flag_Test(0x10) != 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState1(a, 0);
            }
            break;
        up:
            w->cursor--;
            w->dirty = 1;
            Snd_PlayById(0xD, 0);
            break;
        down:
            w->cursor++;
            w->dirty = 1;
            Snd_PlayById(0xD, 0);
            break;
        cancel:
            m->field_0 = 1;
            Task_SetState0(a, 3);
            Snd_PlayById(0xB, 0);
            break;
        sell:
            Task_NextState1(a);
        buy:
            Task_NextState1(a);
            break;
        case 2:
            idx = w->cursor + w->page * 8;
            id = D_80070A08.items[idx];
            switch (a->stateLevel2) {
            case 0:
            default:
                w->field_5C = 0x13A;
                w->field_60 = 0;
                w->dirty = 1;
                Flag_Set(0x10, 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (Flag_Test(0x10) != 0) {
                if (Flag_Test(0x11) == 0) {
                    Snd_PlayById(0xF, 0);
                    Save_GameState.bits += Item_GetPrice(id) / 2;
                    if (Save_GameState.bits > 99999999) {
                        Save_GameState.bits = 99999999;
                    }
                    Item_RemoveFromBag(idx);
                    func_8006C6F0(a);
                }
                Task_SetState1(a, 0);
            }
            break;
        }
        func_8006C8BC(a);
        break;
    }
}

void func_8006D0F0(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xF);
    Task_DefaultDestroy(a);
}

void func_8006D124(Actor *a) {
    Stg20ShopWork *w = (Stg20ShopWork *)a->work;
    GfxPart *p;
    GfxPart *q;

    Cd_GetFileEntry(0xDD60002);
    p = (GfxPart *)Cd_GetFileEntry(0xDD60002);
    for (q = p; q->fileId != 0; q++) {
        switch (q->groupMask) {
        case 2:
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = -0x8A;
            q->y = w->row * 12 - 0x49;
            break;
        case 0x20:
            q->visible = w->field_44 != 0;
            break;
        case 0x40:
            q->visible = w->field_44 != w->field_4C;
            break;
        }
    }
    Gfx_SetPartsNumber(p, 4, 2, w->field_44 + 1);
    Gfx_SetPartsNumber(p, 8, 2, w->field_4C + 1);
    Gfx_DrawParts((s32)p);
    if (D_80070A04 == 0) {
        p = (GfxPart *)Cd_GetFileEntry(0xDD60003);
        Gfx_SetPartsNumber(p, 2, 2, w->field_58);
        Gfx_DrawParts((s32)p);
    }
}

void func_8006D2C0(void *t, s32 id, Halves pos, s32 arg) {
    Stg20TextArgs args;

    if (id < 1000) {
        args.text = (s32)Cd_GetFileEntry(id + 0x1FD0000);
    } else {
        args.text = Item_GetDescText(id - 1000);
    }
    args.bigFont = 1;
    args.color = 0;
    args.pos.x = pos.lo;
    args.pos.y = pos.hi;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = 0;
    args.strArg0 = arg;
    Text_Open(t, &args);
}

void func_8006D350(Actor *a) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;
    s32 n;

    for (i = 0x2F; i >= 0; i--) {
        ((Stg20GameState *)&Save_GameState)->field_66[i] = 0;
    }
    n = 0;
    for (i = 0; i < 0x43; i++) {
        if (w->field_60[i] != 0) {
            ((Stg20GameState *)&Save_GameState)->field_66[n++] = w->field_60[i];
        }
    }
    Item_SortList();
}

void func_8006D3CC(Actor *a) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (((Stg20GameState *)&Save_GameState)->field_66[i] != 0) {
            w->field_60[n++] = ((Stg20GameState *)&Save_GameState)->field_66[i];
        }
    }
    for (i = 1; i < 0x13; i++) {
        if (((Stg20GameState *)&Save_GameState)->field_2C[i] != 0) {
            w->field_60[n++] = ((Stg20GameState *)&Save_GameState)->field_2C[i];
        }
    }
    for (i = 1; i < 0x13; i++) {
        ((Stg20GameState *)&Save_GameState)->field_2C[i] = 0;
        ((Stg20GameState *)&Save_GameState)->field_52[i] = 0;
    }
}

s32 func_8006D484(Actor *a, s32 v) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;

    for (i = 0; i < 0x43; i++) {
        if (w->field_60[i] == v) {
            return 1;
        }
    }
    return 0;
}

void func_8006D4BC(Actor *a, s32 v) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;

    for (i = 0; i < 0x43; i++) {
        if (w->field_60[i] == v) {
            w->field_60[i] = 0;
            return;
        }
    }
}

void func_8006D4F4(s16 *list, s32 n, s32 v) {
    s32 i;
    s32 t;

    for (i = 0; i < n; i++) {
        t = list[i];
        if (t < v) {
            list[i] = v;
            v = t;
        }
    }
    list[i] = v;
}

void func_8006D53C(Actor *a, s32 mode) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    Stg20GameState *g;
    s32 i;
    s32 n;
    s32 id;
    s32 ok;
    s32 mask;
    s32 cnt;

    for (i = 0; i < 0x43; i++) {
        w->items[i] = 0;
        w->colors[i] = 1;
    }
    i = n = 0;
    g = (Stg20GameState *)&Save_GameState;
    for (; i < 0x43; i++) {
        id = w->inv[i];
        if (id == 0) {
            continue;
        }
        if (mode != 0x63) {
            if (Item_GetCategory(id) != mode) {
                continue;
            }
        } else {
            ok = 0;
            if (g->field_2C[8] == 0) {
                ok = Item_GetCategory(id) == 7;
            }
            if (g->field_2C[9] == 0 && Item_GetCategory(id) == 8) {
                ok = 1;
            }
            if (g->field_2C[10] == 0 && Item_GetCategory(id) == 9) {
                ok = 1;
            }
            if (g->field_2C[11] == 0 && Item_GetCategory(id) == 10) {
                ok = 1;
            }
            if (g->field_2C[12] == 0 && Item_GetCategory(id) == 11) {
                ok = 1;
            }
            if (ok == 0) {
                continue;
            }
        }
        func_8006D4F4(w->items, n, id);
        n++;
    }
    w->count = n;
    mask = 1 << w->field_48;
    cnt = 0;
    for (i = 0; i < 0x43; i++) {
        if (w->items[i] != 0) {
            if (Item_GetBodyMask(w->items[i]) & mask) {
                w->colors[i] = 0;
                cnt++;
            } else {
                w->colors[i] = 1;
            }
        }
    }
    if (cnt == 0) {
        w->count = 0;
    }
    cnt = 0;
    if (mode == 1 || mode == 3) {
        for (i = 0; i < 0x43; i++) {
            if (cnt == 0 && w->items[i] != 0 && (Item_GetBodyMask(w->items[i]) & mask)) {
                w->colors[i] = 0;
                cnt = 1;
            } else {
                w->colors[i] = 1;
            }
        }
    }
}

void func_8006D7DC(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    s32 i;
    s32 id;

    if (w->dirty != 0) {
        w->dirty = 0;
        for (i = 0; i < 10; i++) {
            Text_Close(&w->texts[i]);
        }
        for (i = 0; i < 10; i++) {
            if (w->items[i + w->top] == 0) {
                break;
            }
            Text_OpenPacked(&w->texts[i], Item_GetNameText(w->items[i + w->top]), w->colors[i + w->top] << 2, D_800705DC[i + 8]);
        }
        if (a->stateLevel2 == 2) {
            Text_Close(&w->descText);
            id = w->items[w->top + w->cursor];
            if (id != 0) {
                func_8006D2C0(&w->descText, id + 1000, D_800705DC[7], 0);
            }
        }
    }
}

void func_8006D93C(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    s32 mask;
    s32 shift;

    w->field_54 = 0;
    w->field_58 = 0;
    mask = 0x3FF;
    if (((Stg20GameState *)&Save_GameState)->field_2C[1] != 0) {
        shift = (((Stg20GameState *)&Save_GameState)->field_2C[1] - 1) / 5;
        w->field_54 |= mask - (1 << shift);
    } else {
        w->field_54 |= mask;
    }
    mask = 0x1F8000;
    if (((Stg20GameState *)&Save_GameState)->field_2C[2] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->field_2C[2] - 0x2F;
        w->field_54 |= mask - (0x8000 << shift);
    } else {
        w->field_54 |= mask;
    }
    mask = 0x7C00;
    if (((Stg20GameState *)&Save_GameState)->field_2C[3] != 0) {
        shift = (((Stg20GameState *)&Save_GameState)->field_2C[3] - 0x35) / 5;
        w->field_54 |= mask - (0x400 << shift);
    } else {
        w->field_54 |= mask;
    }
    mask = 0x7E00000;
    if (((Stg20GameState *)&Save_GameState)->field_2C[4] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->field_2C[4] - 0x4A;
        w->field_54 |= mask - (0x200000 << shift);
    } else {
        w->field_54 |= mask;
    }
    mask = 0x3E;
    if (((Stg20GameState *)&Save_GameState)->field_2C[5] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->field_2C[5] - 0x50;
        w->field_58 |= mask - (2 << shift);
    } else {
        w->field_58 |= mask;
    }
    mask = 0x7C0;
    if (((Stg20GameState *)&Save_GameState)->field_2C[6] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->field_2C[6] - 0x55;
        w->field_58 |= mask - (0x40 << shift);
    } else {
        w->field_58 |= mask;
    }
    mask = 0x1F0000;
    if (((Stg20GameState *)&Save_GameState)->field_2C[7] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->field_2C[7] - 0x5A;
        w->field_58 |= mask - (0x10000 << shift);
    } else {
        w->field_58 |= mask;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[8] == 0) {
        w->field_58 |= 0x800;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[9] == 0) {
        w->field_58 |= 0x8000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[10] == 0) {
        w->field_58 |= 0x4000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[11] == 0) {
        w->field_58 |= 0x1000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[12] == 0) {
        w->field_58 |= 0x2000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[13] == 0) {
        w->field_58 |= 0x2000000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[14] == 0) {
        w->field_58 |= 0x4000000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[15] == 0) {
        w->field_58 |= 0x8000000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[17] == 0) {
        w->field_58 |= 0x200000;
    }
    if (((Stg20GameState *)&Save_GameState)->field_2C[18] == 0) {
        w->field_58 |= 0x400000;
    }
}

void func_8006DCCC(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    Stg20GameState *g;
    s32 item;
    s32 i;
    s32 v;
    s32 u;
    s32 k;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->hdr, 0x12);
        Text_OpenPacked(&w->hdr[0], (s32)&Save_GameState.field_D1, 0, D_800705DC[0]);
        Task_Create(0x30D, slot, 1);
        if (((Stg20GameState *)&Save_GameState)->field_2C[0] == 0xEA) {
            w->field_48 = 0;
        } else if (((Stg20GameState *)&Save_GameState)->field_2C[0] == 0xEB) {
            w->field_48 = 1;
        } else {
            w->field_48 = 2;
        }
        func_8006D3CC(a);
        w->field_54 = 0x7FFFFFF;
        w->field_58 = 0x7FFFFE;
        w->field_4C = w->field_48 + 3;
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Text_OpenById(&w->hdr[1], 0x13E, 0, D_800705DC[1]);
                Text_OpenById(&w->hdr[2], w->field_48 + 0x13F, 0, D_800705DC[2]);
                func_8006D2C0(&w->descText, w->field_48 + 0x13B, D_800705DC[7], 0);
                w->field_50 = 1;
                Task_NextState2(a);
            case 1:
                break;
            }
            if (D_8005F704 > 0) {
                Snd_PlayById(0x13, 0);
                Text_Close(&w->hdr[1]);
                Text_Close(&w->hdr[2]);
                Text_Close(&w->descText);
                Task_NextState1(a);
            }
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                Text_OpenById(&w->hdr[1], 0x142, 0, D_800705DC[1]);
                Text_OpenPacked(&w->hdr[2], Item_GetNameText(func_8006D484(a, 0x75) != 0 ? 0x75 : 0x76), 0, D_800705DC[2]);
                Text_OpenPacked(&w->hdr[3], Item_GetNameText(0x77), 0, D_800705DC[3]);
                Text_OpenPacked(&w->hdr[4], Item_GetNameText(func_8006D484(a, 0x73) != 0 ? 0x73 : 0x74), 0, D_800705DC[4]);
                func_8006D2C0(&w->descText, 0x143, D_800705DC[7], 0);
                w->field_50 = 3;
                Task_NextState2(a);
            case 1:
                break;
            }
            g = (Stg20GameState *)&Save_GameState;
            if (a->elapsed & 0x10) {
                v = func_8006D484(a, 0x75) != 0 ? 0x75 : 0x76;
            } else {
                v = 0;
            }
            g->field_2C[17] = v;
            u = 0;
            g = (Stg20GameState *)&Save_GameState;
            if (a->elapsed & 0x10) {
                u = 0x77;
            }
            g->field_2C[18] = u;
            if (D_8005F704 > 0) {
                Snd_PlayById(0x14, 0);
                Text_Close(&w->hdr[1]);
                Text_Close(&w->hdr[2]);
                Text_Close(&w->hdr[3]);
                Text_Close(&w->hdr[4]);
                Text_Close(&w->descText);
                g->field_2C[17] = func_8006D484(a, 0x75) != 0 ? 0x75 : 0x76;
                g->field_2C[18] = 0x77;
                g->field_2C[16] = func_8006D484(a, 0x73) != 0 ? 0x73 : 0x74;
                func_8006D4BC(a, g->field_2C[17]);
                func_8006D4BC(a, g->field_2C[18]);
                func_8006D4BC(a, g->field_2C[16]);
                Task_NextState1(a);
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11: {
            s32 st = a->stateLevel1;
            s32 idx = st - 2;

            switch (a->stateLevel2) {
            case 0:
            default:
                func_8006D53C(a, D_80070624[idx]);
                if (w->count == 0) {
                    Task_NextState1(a);
                    break;
                }
                Text_OpenById(&w->hdr[1], st + 0x158, 0, D_800705DC[1]);
                Text_OpenById(&w->hdr[2], 0x14F, 0, D_800705DC[2]);
                func_8006D2C0(&w->descText, st + 0x142, D_800705DC[7], 0);
                w->field_50 = 1;
                w->field_1B8 = 1;
                w->dirty = 1;
                w->top = 0;
                w->cursor = 0;
                w->field_1BC = 0;
                Task_NextState2(a);
            case 1:
                if (D_8005F704 > 0) {
                    Snd_PlayById(0x13, 0);
                    w->dirty = 1;
                    w->field_1BC = 1;
                    Task_NextState2(a);
                }
                break;
            case 2:
                ((Stg20GameState *)&Save_GameState)->field_2C[D_8007064C[idx]] = (a->elapsed & 0x10) ? w->items[w->cursor + w->top] : 0;
                if (Pad_State[0].repeat & 0x1000) {
                    if (w->cursor != 0) {
                        w->cursor--;
                    } else if (w->top != 0) {
                        w->top--;
                    } else {
                        w->dirty = 1;
                        break;
                    }
                    Snd_PlayById(0xD, 0);
                    w->dirty = 1;
                } else if (Pad_State[0].repeat & 0x4000) {
                    if (w->cursor != 9) {
                        w->cursor++;
                    } else if (w->top + 9 < w->count - 1) {
                        w->top++;
                    } else {
                        w->dirty = 1;
                        break;
                    }
                    Snd_PlayById(0xD, 0);
                    w->dirty = 1;
                } else if (Pad_State[0].cross > 0) {
                    if (w->colors[w->top + w->cursor] != 0) {
                        Snd_PlayById(0x10, 0);
                        break;
                    }
                    Snd_PlayById(0x14, 0);
                    ((Stg20GameState *)&Save_GameState)->field_2C[D_8007064C[idx]] = w->items[w->cursor + w->top];
                    func_8006D4BC(a, ((Stg20GameState *)&Save_GameState)->field_2C[D_8007064C[idx]]);
                    Task_NextState1(a);
                }
                break;
            }
            func_8006D7DC(a);
            break;
        }
        case 12:
        case 13:
        case 14:
        case 15:
        case 16: {
            s32 m = a->stateLevel1 - 12;

            switch (a->stateLevel2) {
            case 0:
            default:
                if (w->field_48 == 0 && m >= 3) {
                    Task_NextState1(a);
                    break;
                }
                if (w->field_48 == 1 && m >= 4) {
                    Task_NextState1(a);
                    break;
                }
                func_8006D53C(a, 0x63);
                if (w->count == 0) {
                    Task_NextState1(a);
                    break;
                }
                Text_OpenById(&w->hdr[1], m + 0x164, 0, D_800705DC[1]);
                Text_OpenById(&w->hdr[2], 0x14F, 0, D_800705DC[2]);
                func_8006D2C0(&w->descText, m + 0x155, D_800705DC[7], 0);
                w->field_50 = 1;
                w->field_1B8 = 1;
                w->dirty = 1;
                w->top = 0;
                w->cursor = 0;
                w->field_1BC = 0;
                Task_NextState2(a);
            case 1:
                if (D_8005F704 > 0) {
                    Snd_PlayById(0x13, 0);
                    w->dirty = 1;
                    w->field_1BC = 1;
                    Task_NextState2(a);
                }
                break;
            case 2:
                item = w->items[w->cursor + w->top];
                k = -1;
                if (item != 0) {
                    k = Item_GetCategory(item) - 7;
                }
                goto blink;
            deny:
                Snd_PlayById(0x10, 0);
                break;
            blink:
                if (k != -1) {
                    ((Stg20GameState *)&Save_GameState)->field_2C[k + 8] = (a->elapsed & 0x10) ? item : 0;
                }
                if (Pad_State[0].repeat & 0x1000) {
                    if (w->cursor != 0) {
                        w->cursor--;
                        Snd_PlayById(0xD, 0);
                    } else if (w->top != 0) {
                        w->top--;
                        Snd_PlayById(0xD, 0);
                    }
                    w->dirty = 1;
                    if (k != -1) {
                        ((Stg20GameState *)&Save_GameState)->field_2C[k + 8] = 0;
                    }
                } else if (Pad_State[0].repeat & 0x4000) {
                    if (w->cursor != 9) {
                        w->cursor++;
                        Snd_PlayById(0xD, 0);
                    } else if (w->top + 9 < w->count - 1) {
                        w->top++;
                        Snd_PlayById(0xD, 0);
                    }
                    if (k != -1) {
                        ((Stg20GameState *)&Save_GameState)->field_2C[k + 8] = 0;
                    }
                    w->dirty = 1;
                } else if (Pad_State[0].cross > 0) {
                    if (k == -1) {
                        goto deny;
                    }
                    Snd_PlayById(0x14, 0);
                    ((Stg20GameState *)&Save_GameState)->field_2C[k + 8] = item;
                    func_8006D4BC(a, item);
                    Task_NextState1(a);
                }
                break;
            }
            func_8006D7DC(a);
            break;
        }
        case 17:
            switch (a->stateLevel2) {
            case 0:
            default:
                for (i = 0; i < 10; i++) {
                    Text_Close(&w->texts[i]);
                }
                w->field_1B8 = 0;
                func_8006D2C0(&w->descText, 0x14E, D_800705DC[7], 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (D_8005F704 > 0) {
                func_8006D350(a);
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}

void func_8006E720(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0x12);
    Task_DefaultDestroy(a);
}

void func_8006E754(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    GfxPart *p;
    GfxPart *q;

    func_8006D93C(a);
    p = (GfxPart *)Cd_GetFileEntry(D_80070674[0][w->field_48]);
    Gfx_HidePartsByMask((GfxPartMaskView *)p, w->field_54);
    Gfx_DrawParts((s32)p);
    p = (GfxPart *)Cd_GetFileEntry(D_80070674[1][w->field_48]);
    Gfx_HidePartsByMask((GfxPartMaskView *)p, w->field_58);
    Gfx_DrawParts((s32)p);
    p = (GfxPart *)Cd_GetFileEntry(0xC93000A);
    for (q = p; q->fileId != 0; q++) {
        switch (w->field_50) {
        case 0:
        default:
            q->visible = (q->groupMask & 0x78) == 0;
            break;
        case 3:
            q->visible = (q->groupMask & 0x60) == 0;
            break;
        case 4:
            q->visible = (((u32)q->groupMask >> 6) ^ 1) & 1;
            break;
        case 5:
            q->visible = 1;
            break;
        }
        if (q->groupMask & 2) {
            q->visible = 0;
        }
    }
    Gfx_DrawParts((s32)p);
    Gfx_DrawParts((s32)Cd_GetFileEntry(0xC930009));
    if (w->field_1B8 != 0) {
        p = (GfxPart *)Cd_GetFileEntry(0xC93000B);
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & 2) {
                q->visible = w->field_1BC != 0;
                q->x = 0x26;
                q->y = w->cursor * 12 - 0x50;
                q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            }
            if (q->groupMask & 4) {
                q->visible = w->top != 0;
            }
            if (q->groupMask & 8) {
                q->visible = w->count - 1 >= w->top + 10;
            }
        }
        Gfx_DrawParts((s32)p);
    }
}

s32 func_8006E9E8(s32 item)
{
    if (item < 0x2F) {
        if (item == 0x2E) return 0;
        if (item == item / 5 * 5) return 0;
    } else if (item < 0x4A) {
        if (item == 0x49) return 0;
        { s32 n = item - 0x34;
        if (n == n / 5 * 5) return 0; }
    } else if (item < 0x63) {
        if (item == 0x62) return 0;
    } else if (item < 0x66) {
        if (item == 0x65) return 0;
    } else if (item < 0x6D) {
        if (item == 0x6C) return 0;
    } else if (item < 0x72) {
        if (item == 0x6F) return 0;
    }
    return 1;
}

void func_8006EA90(Actor *a) {
    Stg20ItemWork *w = (Stg20ItemWork *)a->work;
    u8 digits[5];
    s32 i;
    s32 j;
    s32 k;
    s32 id;
    s32 v;
    s32 lead;
    u8 *name;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 0x18; j++) {
            w->recs[i].name[j] = 0xFD;
        }
        w->recs[i].name[0x14] = 0xB;
        w->recs[i].name[0x15] = 0x12;
        w->recs[i].name[0x16] = 0x1D;
        w->recs[i].name[0x17] = 0xFF;
    }
    for (i = 0; i < 6; i++) {
        id = ((Stg20GameState *)&Save_GameState)->field_2C[D_800706D4[i]];
        w->recs[i].item = id;
        if (id != 0) {
            name = (u8 *)Item_GetNameText(id);
            j = 0;
            while (*name != 0xFF) {
                w->recs[i].name[j++] = *name++;
            }
            if (func_8006E9E8(id) != 0) {
                w->recs[i].price = Item_GetPrice(id + 1) - Item_GetPrice(id);
            } else {
                w->recs[i].price = 0;
            }
        } else {
            for (j = 0; j < 10; j++) {
                w->recs[i].name[j] = 0x49;
            }
            w->recs[i].price = 0;
        }
        v = w->recs[i].price;
        if (v != 0) {
            for (k = 4; k != -1; k--) {
                digits[k] = v % 10;
                v /= 10;
            }
            lead = 1;
            for (k = 0; k < 5; k++) {
                if (!lead || digits[k] != 0) {
                    lead = 0;
                    w->recs[i].name[k + 0xF] = digits[k];
                }
            }
        } else {
            for (k = 0; k < 5; k++) {
                w->recs[i].name[k + 0xF] = 0x49;
            }
        }
    }
}

void func_8006ED24(Actor *a) {
    Stg20ItemWork *w = (Stg20ItemWork *)a->work;
    s32 i;

    if (w->dirty != 0) {
        w->dirty = 0;
        for (i = 0; i < 6; i++) {
            Text_OpenPacked(&w->texts[i], (s32)w->recs[i].name, 0, D_800706A4[i + 4]);
        }
        Text_Close(&w->descText);
        if (w->recs[w->index].item != 0) {
            Text_OpenPacked(&w->descText, Item_GetDescText(w->recs[w->index].item), 0, D_800706A4[10]);
        }
    }
}

void func_8006EE24(Actor *task) {
    Stg20ItemWork *w = (Stg20ItemWork *) task->work;
    s32 state = task->stateLevel0;
    s32 children = task->u34.children;
    s32 sub;
    s32 st2;

    if (state == 1) {
        goto case1;
    }
    if (state >= 2) {
        return;
    }
    if (state != 0) {
        return;
    }
    {
        Mem_FillWordsNeg1(w->hdr, 0xC);
        Text_OpenById(&w->hdr[0], 0x17A, 4, D_800706A4[0]);
        Text_OpenById(&w->hdr[1], 0x17B, 4, D_800706A4[1]);
        Text_OpenById(&w->hdr[2], 0xDE, 0, D_800706A4[2]);
        Text_OpenPacked(&w->hdr[3], (s32) &D_8005E6F1, 0, D_800706A4[3]);
        Task_Create(0x30D, (s32 *) children, 0);
        func_8006EA90(task);
        w->dirty = 1;
        w->msg = 0x17C;
        Task_NextState0(task);
        return;
    triangle:
        Snd_PlayById(0xB, 0);
        Task_SetState0(task, 3);
        goto f070;
    noPrice:
        sub = 0x17D;
        goto buzz;
    tooHigh:
        sub = 0x139;
    buzz:
        w->msg = sub;
        Snd_PlayById(0x10, 0);
        goto f070;
    case1:
        sub = task->stateLevel1;
        if (sub != 0 && sub == state) {
            goto f080;
        }
        if (Pad_State[0].repeat & 0x1000) {
            if (w->index == 0) {
                goto efec;
            }
            w->index = w->index - 1;
            goto beep;
        }
        if (Pad_State[0].repeat & 0x4000) {
            if (w->index == 5) {
                goto efec;
            }
            w->index = w->index + 1;
        beep:
            Snd_PlayById(0xD, 0);
        efec:
            w->dirty = state;
            w->msg = 0x17C;
            goto f070;
        }
        do {
        if (Pad_State[0].triangle > 0) {
            goto triangle;
        }
        if (Pad_State[0].cross <= 0) {
            goto f070;
        }
        if (w->recs[w->index].item == 0) {
            goto f070;
        }
        if (w->recs[w->index].price == 0) {
            goto noPrice;
        }
        if (D_8005E628 < w->recs[w->index].price) {
            goto tooHigh;
        }
        Snd_PlayById(0xE, 0);
        Task_NextState1(task);
        } while (0);
    f070:
        func_8006ED24(task);
        goto text_update;
    f080:
        state = task->stateLevel2;
        st2 = state;
        switch (st2) {
        default:
        case 0:
        w->msgArg = Item_GetNameText(w->recs[w->index].item + 1);
        w->msg = 0x17E;
        Flag_Set(0x10, 0);
        Task_NextState2(task);
        goto text_update;
        case 1:
        if (Flag_Test(0x10) != 0) {
            if (Flag_Test(0x11) == 0) {
                goto f144;
            }
        }
        if (D_8005F70C > 0) {
            goto f124;
        }
        if (Flag_Test(0x10) == 0) {
            goto text_update;
        }
    f124:
        Snd_PlayById(0xB, 0);
        w->dirty = st2;
        w->msg = 0x17C;
        Task_SetState1(task, 0);
        goto text_update;
    f144:
        Snd_PlayById(0x14, 0);
        Save_GameState.bits -= w->recs[w->index].price;
        Save_GameState.itemCounts[D_800706D4[w->index]]++;
        func_8006EA90(task);
        w->dirty = st2;
        w->msg = 0x17F;
        Task_NextState2(task);
        goto text_update;
        case 2:
        if (D_8005F704 > 0) {
            Task_SetState1(task, 0);
        }
        }
    text_update:
        if (w->msg == w->shownMsg) {
            return;
        }
        w->shownMsg = w->msg;
        Text_Close(&w->msgText);
        if (w->msg == 0) {
            return;
        }
        func_8006D2C0(&w->msgText, w->msg, D_800706A4[11], w->msgArg);
    }
}

void func_8006F258(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xC);
    Task_DefaultDestroy(a);
}

void func_8006F28C(Actor *a) {
    Stg20RowWork *w = (Stg20RowWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930000);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = -0x56;
            q->y = w->field_30 * 12 - 0x34;
        }
    }
    Gfx_DrawParts((s32)p);
}

Stg20FileRec *func_8006F360(s32 i) {
    Stg20FileRec *r = (Stg20FileRec *)Cd_GetFileEntry(Sys_GameMode[0] + 0xD28FCD6);

    if (r[i].field_13 == 0) {
        s32 base = Cd_GetFileOrNull(0xD29);

        r[i].field_13 = 1;
        r[i].field_4 += base;
    }
    return &r[i];
}

void func_8006F3D8(Actor *a, s32 v) {
    a->param = v;
}

void func_8006F3E0(Actor *a) {
    Stg20LinkWork *w = (Stg20LinkWork *)a->work;
    Stg20Cell c;
    Stg20WarpFx args;
    Stg20Rot *o;
    s32 ok;
    s32 *slot;
    s32 v;

    switch (a->stateLevel0) {
    case 0:
        if (++a->stateLevel1 >= 5) {
            Cd_QueueFile(0xE45);
            Cd_QueueFile(0xE46);
            w->target = (Actor *)Task_FindFirst(0x302, 0, -1);
            ok = 0;
            c = *func_80067504(w->target);
            if (c.x == D_80070704[a->param].cell.x && c.y == D_80070704[a->param].cell.y) {
                ok = func_80067568(w->target) != 0;
            }
            if (ok == 0) {
                Task_NextState0(a);
            }
        }
        break;
    case 1:
        c = *func_80067504(w->target);
        if (c.x == D_80070704[a->param].cell.x && c.y == D_80070704[a->param].cell.y
            && func_80067568(w->target) != 0) {
            func_8006AD8C(w->target);
            D_800709B4 = 1;
            Task_NextState0(a);
        }
        break;
    case 2:
        o = (Stg20Rot *)w->target->u38.ptr38;
        o->field_42 += 0x177;
        o->field_5C += 0x190;
        if (o->field_58 > 100) {
            o->field_58 -= 100;
        } else {
            o->field_58 = 0;
        }
        v = o->field_60;
        if (v > 100) {
            o->field_60 -= 100;
        } else {
            o->field_60 = 0;
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            Snd_PlayById(0x32, 0);
            o = (Stg20Rot *)w->target->u38.ptr38;
            slot = (s32 *)a->u34.children;
            args.field_4 = 0xE45;
            args.field_0 = 0xE46;
            args.field_14 = 0;
            args.field_18 = 0x78;
            args.x = o->field_30;
            args.y = o->field_34;
            args.z = o->field_38;
            Task_Create(7, slot, (s32)&args);
            Task_NextState1(a);
            a->elapsed = 0;
        case 1:
            if (a->elapsed < 0x5A) {
                break;
            }
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 2:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = D_80070704[a->param].nextMode;
                Sys_State.modeArg = D_80070704[a->param].field_8;
            }
            break;
        }
        break;
    }
}

void func_8006F730(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;
    Actor *e;

    switch (a->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->coord);
        if (Sys_GameMode[0] < 0x32F) {
            w->proj = 0x5A0;
            w->view.field_4 = -0x5D00;
            w->view.field_0 = 0;
            w->view.field_8 = -0x5A00;
            w->view.field_C = 0;
            w->view.field_10 = 0;
            w->view.field_14 = 0;
        } else {
            w->proj = 0x5DC;
            w->view.field_4 = -0xFA0;
            w->view.field_8 = -0x3578;
            w->view.field_0 = 0;
            w->view.field_C = 0;
            w->view.field_10 = -0x3E8;
            w->view.field_14 = 0;
        }
        w->view.field_18 = 0;
        w->view.field_1C = &w->coord;
        w->rot[2] = 0;
        w->rot[1] = 0;
        w->rot[0] = 0;
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        if (Sys_GameMode[0] < 0x32F) {
            break;
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            w->view.field_4 = -0xFA0;
            w->view.field_8 = -0x3578;
            w->speed = 0;
            return;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (w->view.field_4 >= -0x270F) {
                    w->view.field_4 -= 0x1F4;
                    break;
                }
                w->view.field_4 = -0x2710;
                Task_NextState2(a);
                w->timer = 0x7B;
            case 1:
                w->speed += 0x840;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeOutToWhite(0x14);
            case 2:
                w->speed += 0x840;
                w->view.field_8 += 0x390;
                w->view.field_4 += 0x29A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeInFromWhite(0x14);
            case 3:
                w->speed -= 0x1080;
                w->view.field_8 -= 0x390;
                w->view.field_4 -= 0x10A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0x78;
            case 4:
                if (w->speed > 0) {
                    w->speed -= 0x1080;
                } else {
                    w->speed = 0;
                }
                if (--w->timer == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            w->rot[1] -= w->speed / 256;
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (w->view.field_4 >= -0x270F) {
                    w->view.field_4 -= 0x1F4;
                    break;
                }
                w->view.field_4 = -0x2710;
                Task_NextState2(a);
                w->timer = 0x7B;
            case 1:
                w->speed += 0x840;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeOutToWhite(0x14);
            case 2:
                w->speed += 0x840;
                w->view.field_8 += 0x390;
                w->view.field_4 += 0x29A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeInFromWhite(0x14);
            case 3:
                w->speed -= 0x840;
                w->view.field_8 -= 0x390;
                w->view.field_4 -= 0x10A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0x78;
            case 4:
                w->speed -= 0x840;
                if (--w->timer == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            e = (Actor *)Task_FindFirst(0x30A, -1, 0);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->field_42 += w->speed / 256;
            }
            e = (Actor *)Task_FindFirst(0x30A, -1, 1);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->field_42 -= w->speed / 256;
            }
            break;
        }
        if (D_800709EC[0] == 0) {
            e = (Actor *)Task_FindFirst(7, -1, -1);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->field_42 = w->rot[1];
            }
        }
        break;
    }
}

void func_8006FBF0(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;

    RotMatrixYXZ(w->rot, &w->coord.coord);
    w->coord.coord.t[0] = w->tx;
    w->coord.coord.t[1] = w->ty;
    w->coord.coord.t[2] = w->tz;
    w->coord.flg = 0;
    GsSetProjection(w->proj);
    GsSetRefView2(&w->view);
}
