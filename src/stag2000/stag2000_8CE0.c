#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/stag2000_funcs.h"

void Stg20_BeetleShopMenuDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

void Stg20_BeetleShopMenuDraw(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930008);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = Stg20_MenuState.menuChoice != 0 ? -0x57 : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}

s32 Stg20_ByteListHas(u8 *s, s32 c) {
    for (; *s != 0; s++) {
        if (*s == c) {
            return 1;
        }
    }
    return 0;
}

s32 Stg20_IsPartInstalled(s32 id) {
    s32 i;

    for (i = 0; i < 0x13; i++) {
        if (((Stg20GameState *)&Save_GameState)->slotItems[i] == id) {
            return 1;
        }
    }
    return 0;
}

s32 Stg20_GetPartFitMsg(s32 id) {
    if (Stg20_IsPartInstalled(id)) {
        return 0x132;
    }
    if (Stg20_ByteListHas(Stg20_PartsAnyBody, id)) {
        return 0x131;
    }
    if (Stg20_ByteListHas(Stg20_ShooterGunAmmo, id)) {
        if (D_8005E65C != 0) {
            return 0x12F;
        }
        return 0x130;
    }
    if (Stg20_ByteListHas(Stg20_ZCannonAmmo, id)) {
        if (D_8005E65E != 0) {
            return 0x12F;
        }
        return 0x133;
    }
    if (Stg20_ByteListHas(Stg20_MissileGunAmmo, id)) {
        if (D_8005E662 != 0) {
            return 0x12F;
        }
        return 0x135;
    }
    if (Stg20_ByteListHas(Stg20_RCannonAmmo, id)) {
        if (D_8005E660 != 0) {
            return 0x12F;
        }
        return 0x136;
    }
    if (Stg20_ByteListHas(Stg20_PartsAdmantOnly, id)) {
        if (D_8005E64C == 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsSteelOnly, id)) {
        if (D_8005E64C == 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsTitanOnly, id)) {
        if (D_8005E64C == 0xEB) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsNotAdmant, id)) {
        if (D_8005E64C != 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsNotSteel, id)) {
        if (D_8005E64C != 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    return 0;
}

s32 Stg20_CountOwnedItem(s32 id) {
    s32 n;
    s32 i;
    s32 r;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (((Stg20GameState *)&Save_GameState)->bagItems[i] == id) {
            n++;
        }
    }
    n += ((Stg20GameState *)&Save_GameState)->storageCounts[id];
    r = 99;
    if (n < 100) {
        r = n;
    }
    return r;
}

void Stg20_FormatPrice(u8 *out, s32 v) {
    u8 d[5];
    s32 n;
    s32 i;
    s32 lead;

    n = Item_GetPrice(v);
    if (Stg20_ShopSellMode != 0) {
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

void Stg20_LoadShopBuyList(Actor *a, s32 id) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    s32 i;
    s32 j;
    u8 *name;
    u8 *list = (u8 *)Cd_GetFileEntry(id + 0x3CF0000);

    w->count = 0;
    for (i = 0; i < 50; i++) {
        Stg20_ShopItems.items[i] = 0;
        for (j = 0; j < 25; j++) {
            Stg20_ShopItems.names[i][j] = 0xFD;
        }
        Stg20_ShopItems.names[i][24] = 0xFF;
    }
    for (i = 0; i < 50; i++) {
        if (list[i] == 0) {
            break;
        }
        Stg20_ShopItems.items[i] = list[i];
        name = (u8 *)Item_GetNameText(list[i]);
        for (j = 0; j < 10; j++) {
            if (*name == 0xFF) {
                break;
            }
            Stg20_ShopItems.names[i][j] = *name++;
        }
        Stg20_FormatPrice(&Stg20_ShopItems.names[i][14], list[i]);
        Stg20_ShopItems.names[i][19] = 0xB;
        Stg20_ShopItems.names[i][20] = 0x12;
        Stg20_ShopItems.names[i][21] = 0x1D;
        Stg20_ShopItems.names[i][22] = 0x36;
        w->count++;
    }
    w->pages = w->count != 0 ? (w->count - 1) / 8 : 0;
}

void Stg20_LoadShopSellList(Actor *a) {
    Stg20ShopListWork *w = (Stg20ShopListWork *)a->work;
    s32 i;
    s32 j;
    u8 *name;
    u16 *list = D_8005E686;
    s32 k;

    w->count = 0;
    for (i = 0; i < 50; i++) {
        Stg20_ShopItems.items[i] = 0;
        for (j = 0; j < 25; j++) {
            Stg20_ShopItems.names[i][j] = 0xFD;
        }
        Stg20_ShopItems.names[i][24] = 0xFF;
    }
    for (i = 0, k = 0; i < 0x30; k++, i++) {
        if (list[i] == 0) {
            break;
        }
        Stg20_ShopItems.items[k] = list[i];
        name = (u8 *)Item_GetNameText(list[i]);
        for (j = 0; j < 10; j++) {
            if (*name == 0xFF) {
                break;
            }
            Stg20_ShopItems.names[k][j] = *name++;
        }
        Stg20_FormatPrice(&Stg20_ShopItems.names[k][14], list[i]);
        Stg20_ShopItems.names[k][19] = 0xB;
        Stg20_ShopItems.names[k][20] = 0x12;
        Stg20_ShopItems.names[k][21] = 0x1D;
        Stg20_ShopItems.names[k][22] = 0x36;
        w->count++;
    }
    w->pages = w->count != 0 ? (w->count - 1) / 8 : 0;
}

void Stg20_ShopListRefresh(Actor *a) {
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
            if (Stg20_ShopItems.items[i + base] == 0) {
                break;
            }
            args.text = (s32)Stg20_ShopItems.names[i + base];
            args.pos.y = 0x30 + i * 12;
            w->field_50 = 9;
            w->field_51 = 0xFF;
            Text_Open(&w->texts[i], &args);
        }
        id = Stg20_ShopItems.items[w->cursor + w->page * 8];
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
        if (Stg20_ShopSellMode == 0) {
            if (id != 0) {
                w->ownedCount = Stg20_CountOwnedItem(id);
            } else {
                w->ownedCount = 0;
            }
        }
        Text_Close(&w->text14);
        if (w->msgId != 0) {
            args.text = (s32)Cd_GetFileEntry(w->msgId + 0x1FD0000);
            args.bigFont = 1;
            args.color = 0;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            args.charDelay = 0;
            args.pos.x = Stg20_ShopListTextPos[4].x;
            args.pos.y = Stg20_ShopListTextPos[4].y;
            Text_Open(&w->text14, &args);
        }
        Text_Close(&w->text18);
        if (w->promptId != 0) {
            args.text = (s32)Cd_GetFileEntry(w->promptId + 0x1FD0000);
            args.bigFont = 1;
            args.color = 0;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            args.charDelay = 0;
            args.pos.x = Stg20_ShopListTextPos[5].x;
            args.pos.y = Stg20_ShopListTextPos[5].y;
            Text_Open(&w->text18, &args);
        }
        w->dirty = 0;
    }
}

void Stg20_ShopListUpdate(Actor *a) {
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
        Text_OpenById(&w->hdr[0], 0x12D, 4, *(Halves *)&Stg20_ShopListTextPos[0]);
        Text_OpenById(&w->hdr[1], Stg20_MenuState.sellMode + 0x12B, 4, *(Halves *)&Stg20_ShopListTextPos[1]);
        Text_OpenById(&w->hdr[2], 0xFA, 0, *(Halves *)&Stg20_ShopListTextPos[2]);
        if (Stg20_MenuState.sellMode == 0) {
            Text_OpenById(&w->hdr[3], 0x12E, 0, *(Halves *)&Stg20_ShopListTextPos[3]);
        }
        if (Stg20_MenuState.sellMode == 0) {
            Stg20_LoadShopBuyList(a, Sys_State.modeArg);
        } else {
            Stg20_LoadShopSellList(a);
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
                w->msgId = 0x138;
                w->promptId = 0;
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
                if (m->sellMode == 0) {
                    item = Stg20_ShopItems.items[w->cursor + w->page * 8];
                    if (item != 0) {
                        if (Item_GetPrice(item) > D_8005E628) {
                            w->msgId = 0x139;
                            w->dirty = 1;
                            Snd_PlayById(0x10, 0);
                        } else {
                            goto buy;
                        }
                    }
                } else {
                    item = Stg20_ShopItems.items[w->cursor + w->page * 8];
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
            id = Stg20_ShopItems.items[w->cursor + w->page * 8];
            switch (a->stateLevel2) {
            case 0:
            default:
                w->msgId = Stg20_GetPartFitMsg(id);
                w->promptId = 0x137;
                w->dirty = 1;
                Flag_Set(0x10, 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (Flag_Test(0x10) != 0 && Flag_Test(0x11) == 0) {
                Snd_PlayById(0xF, 0);
                g = (Stg20GameState *)&Save_GameState;
                g->storageCounts[id] = g->storageCounts[id] == 99 ? 99 : g->storageCounts[id] + 1;
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
            m->result = 1;
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
            id = Stg20_ShopItems.items[idx];
            switch (a->stateLevel2) {
            case 0:
            default:
                w->msgId = 0x13A;
                w->promptId = 0;
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
                    Stg20_LoadShopSellList(a);
                }
                Task_SetState1(a, 0);
            }
            break;
        }
        Stg20_ShopListRefresh(a);
        break;
    }
}

void Stg20_ShopListDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xF);
    Task_DefaultDestroy(a);
}

void Stg20_ShopListDraw(Actor *a) {
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
            q->visible = w->page != 0;
            break;
        case 0x40:
            q->visible = w->page != w->pages;
            break;
        }
    }
    Gfx_SetPartsNumber(p, 4, 2, w->page + 1);
    Gfx_SetPartsNumber(p, 8, 2, w->pages + 1);
    Gfx_DrawParts((s32)p);
    if (Stg20_ShopSellMode == 0) {
        p = (GfxPart *)Cd_GetFileEntry(0xDD60003);
        Gfx_SetPartsNumber(p, 2, 2, w->ownedCount);
        Gfx_DrawParts((s32)p);
    }
}

void Stg20_OpenMsgOrDesc(void *t, s32 id, Halves pos, s32 arg) {
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

void Stg20_PartsListToBag(Actor *a) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;
    s32 n;

    for (i = 0x2F; i >= 0; i--) {
        ((Stg20GameState *)&Save_GameState)->bagItems[i] = 0;
    }
    n = 0;
    for (i = 0; i < 0x43; i++) {
        if (w->inv[i] != 0) {
            ((Stg20GameState *)&Save_GameState)->bagItems[n++] = w->inv[i];
        }
    }
    Item_SortList();
}

void Stg20_GatherPartsList(Actor *a) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < 0x30; i++) {
        if (((Stg20GameState *)&Save_GameState)->bagItems[i] != 0) {
            w->inv[n++] = ((Stg20GameState *)&Save_GameState)->bagItems[i];
        }
    }
    for (i = 1; i < 0x13; i++) {
        if (((Stg20GameState *)&Save_GameState)->slotItems[i] != 0) {
            w->inv[n++] = ((Stg20GameState *)&Save_GameState)->slotItems[i];
        }
    }
    for (i = 1; i < 0x13; i++) {
        ((Stg20GameState *)&Save_GameState)->slotItems[i] = 0;
        ((Stg20GameState *)&Save_GameState)->slotStatus[i] = 0;
    }
}

s32 Stg20_PartsListHas(Actor *a, s32 v) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;

    for (i = 0; i < 0x43; i++) {
        if (w->inv[i] == v) {
            return 1;
        }
    }
    return 0;
}

void Stg20_PartsListRemove(Actor *a, s32 v) {
    Stg20ListWork *w = (Stg20ListWork *)a->work;
    s32 i;

    for (i = 0; i < 0x43; i++) {
        if (w->inv[i] == v) {
            w->inv[i] = 0;
            return;
        }
    }
}

void Stg20_InsertDescS16(s16 *list, s32 n, s32 v) {
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

void Stg20_FilterPartsList(Actor *a, s32 mode) {
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
            if (g->slotItems[8] == 0) {
                ok = Item_GetCategory(id) == 7;
            }
            if (g->slotItems[9] == 0 && Item_GetCategory(id) == 8) {
                ok = 1;
            }
            if (g->slotItems[10] == 0 && Item_GetCategory(id) == 9) {
                ok = 1;
            }
            if (g->slotItems[11] == 0 && Item_GetCategory(id) == 10) {
                ok = 1;
            }
            if (g->slotItems[12] == 0 && Item_GetCategory(id) == 11) {
                ok = 1;
            }
            if (ok == 0) {
                continue;
            }
        }
        Stg20_InsertDescS16(w->items, n, id);
        n++;
    }
    w->count = n;
    mask = 1 << w->bodyType;
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

void Stg20_PartsListRefresh(Actor *a) {
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
            Text_OpenPacked(&w->texts[i], Item_GetNameText(w->items[i + w->top]), w->colors[i + w->top] << 2, Stg20_BeetlePartsTextPos[i + 8]);
        }
        if (a->stateLevel2 == 2) {
            Text_Close(&w->descText);
            id = w->items[w->top + w->cursor];
            if (id != 0) {
                Stg20_OpenMsgOrDesc(&w->descText, id + 1000, Stg20_BeetlePartsTextPos[7], 0);
            }
        }
    }
}

void Stg20_CalcBeetleHideMasks(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    s32 mask;
    s32 shift;

    w->hideMask0 = 0;
    w->hideMask1 = 0;
    mask = 0x3FF;
    if (((Stg20GameState *)&Save_GameState)->slotItems[1] != 0) {
        shift = (((Stg20GameState *)&Save_GameState)->slotItems[1] - 1) / 5;
        w->hideMask0 |= mask - (1 << shift);
    } else {
        w->hideMask0 |= mask;
    }
    mask = 0x1F8000;
    if (((Stg20GameState *)&Save_GameState)->slotItems[2] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->slotItems[2] - 0x2F;
        w->hideMask0 |= mask - (0x8000 << shift);
    } else {
        w->hideMask0 |= mask;
    }
    mask = 0x7C00;
    if (((Stg20GameState *)&Save_GameState)->slotItems[3] != 0) {
        shift = (((Stg20GameState *)&Save_GameState)->slotItems[3] - 0x35) / 5;
        w->hideMask0 |= mask - (0x400 << shift);
    } else {
        w->hideMask0 |= mask;
    }
    mask = 0x7E00000;
    if (((Stg20GameState *)&Save_GameState)->slotItems[4] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->slotItems[4] - 0x4A;
        w->hideMask0 |= mask - (0x200000 << shift);
    } else {
        w->hideMask0 |= mask;
    }
    mask = 0x3E;
    if (((Stg20GameState *)&Save_GameState)->slotItems[5] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->slotItems[5] - 0x50;
        w->hideMask1 |= mask - (2 << shift);
    } else {
        w->hideMask1 |= mask;
    }
    mask = 0x7C0;
    if (((Stg20GameState *)&Save_GameState)->slotItems[6] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->slotItems[6] - 0x55;
        w->hideMask1 |= mask - (0x40 << shift);
    } else {
        w->hideMask1 |= mask;
    }
    mask = 0x1F0000;
    if (((Stg20GameState *)&Save_GameState)->slotItems[7] != 0) {
        shift = ((Stg20GameState *)&Save_GameState)->slotItems[7] - 0x5A;
        w->hideMask1 |= mask - (0x10000 << shift);
    } else {
        w->hideMask1 |= mask;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[8] == 0) {
        w->hideMask1 |= 0x800;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[9] == 0) {
        w->hideMask1 |= 0x8000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[10] == 0) {
        w->hideMask1 |= 0x4000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[11] == 0) {
        w->hideMask1 |= 0x1000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[12] == 0) {
        w->hideMask1 |= 0x2000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[13] == 0) {
        w->hideMask1 |= 0x2000000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[14] == 0) {
        w->hideMask1 |= 0x4000000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[15] == 0) {
        w->hideMask1 |= 0x8000000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[17] == 0) {
        w->hideMask1 |= 0x200000;
    }
    if (((Stg20GameState *)&Save_GameState)->slotItems[18] == 0) {
        w->hideMask1 |= 0x400000;
    }
}

void Stg20_BeetlePartsUpdate(Actor *a) {
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
        Text_OpenPacked(&w->hdr[0], (s32)&Save_GameState.field_D1, 0, Stg20_BeetlePartsTextPos[0]);
        Task_Create(0x30D, slot, 1);
        if (((Stg20GameState *)&Save_GameState)->slotItems[0] == 0xEA) {
            w->bodyType = 0;
        } else if (((Stg20GameState *)&Save_GameState)->slotItems[0] == 0xEB) {
            w->bodyType = 1;
        } else {
            w->bodyType = 2;
        }
        Stg20_GatherPartsList(a);
        w->hideMask0 = 0x7FFFFFF;
        w->hideMask1 = 0x7FFFFE;
        w->cannonCount = w->bodyType + 3;
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
                Text_OpenById(&w->hdr[1], 0x13E, 0, Stg20_BeetlePartsTextPos[1]);
                Text_OpenById(&w->hdr[2], w->bodyType + 0x13F, 0, Stg20_BeetlePartsTextPos[2]);
                Stg20_OpenMsgOrDesc(&w->descText, w->bodyType + 0x13B, Stg20_BeetlePartsTextPos[7], 0);
                w->frameMode = 1;
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
                Text_OpenById(&w->hdr[1], 0x142, 0, Stg20_BeetlePartsTextPos[1]);
                Text_OpenPacked(&w->hdr[2], Item_GetNameText(Stg20_PartsListHas(a, 0x75) != 0 ? 0x75 : 0x76), 0, Stg20_BeetlePartsTextPos[2]);
                Text_OpenPacked(&w->hdr[3], Item_GetNameText(0x77), 0, Stg20_BeetlePartsTextPos[3]);
                Text_OpenPacked(&w->hdr[4], Item_GetNameText(Stg20_PartsListHas(a, 0x73) != 0 ? 0x73 : 0x74), 0, Stg20_BeetlePartsTextPos[4]);
                Stg20_OpenMsgOrDesc(&w->descText, 0x143, Stg20_BeetlePartsTextPos[7], 0);
                w->frameMode = 3;
                Task_NextState2(a);
            case 1:
                break;
            }
            g = (Stg20GameState *)&Save_GameState;
            if (a->elapsed & 0x10) {
                v = Stg20_PartsListHas(a, 0x75) != 0 ? 0x75 : 0x76;
            } else {
                v = 0;
            }
            g->slotItems[17] = v;
            u = 0;
            g = (Stg20GameState *)&Save_GameState;
            if (a->elapsed & 0x10) {
                u = 0x77;
            }
            g->slotItems[18] = u;
            if (D_8005F704 > 0) {
                Snd_PlayById(0x14, 0);
                Text_Close(&w->hdr[1]);
                Text_Close(&w->hdr[2]);
                Text_Close(&w->hdr[3]);
                Text_Close(&w->hdr[4]);
                Text_Close(&w->descText);
                g->slotItems[17] = Stg20_PartsListHas(a, 0x75) != 0 ? 0x75 : 0x76;
                g->slotItems[18] = 0x77;
                g->slotItems[16] = Stg20_PartsListHas(a, 0x73) != 0 ? 0x73 : 0x74;
                Stg20_PartsListRemove(a, g->slotItems[17]);
                Stg20_PartsListRemove(a, g->slotItems[18]);
                Stg20_PartsListRemove(a, g->slotItems[16]);
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
                Stg20_FilterPartsList(a, Stg20_PartsPageCategory[idx]);
                if (w->count == 0) {
                    Task_NextState1(a);
                    break;
                }
                Text_OpenById(&w->hdr[1], st + 0x158, 0, Stg20_BeetlePartsTextPos[1]);
                Text_OpenById(&w->hdr[2], 0x14F, 0, Stg20_BeetlePartsTextPos[2]);
                Stg20_OpenMsgOrDesc(&w->descText, st + 0x142, Stg20_BeetlePartsTextPos[7], 0);
                w->frameMode = 1;
                w->listShown = 1;
                w->dirty = 1;
                w->top = 0;
                w->cursor = 0;
                w->cursorShown = 0;
                Task_NextState2(a);
            case 1:
                if (D_8005F704 > 0) {
                    Snd_PlayById(0x13, 0);
                    w->dirty = 1;
                    w->cursorShown = 1;
                    Task_NextState2(a);
                }
                break;
            case 2:
                ((Stg20GameState *)&Save_GameState)->slotItems[Stg20_PartsPageSlot[idx]] = (a->elapsed & 0x10) ? w->items[w->cursor + w->top] : 0;
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
                    ((Stg20GameState *)&Save_GameState)->slotItems[Stg20_PartsPageSlot[idx]] = w->items[w->cursor + w->top];
                    Stg20_PartsListRemove(a, ((Stg20GameState *)&Save_GameState)->slotItems[Stg20_PartsPageSlot[idx]]);
                    Task_NextState1(a);
                }
                break;
            }
            Stg20_PartsListRefresh(a);
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
                if (w->bodyType == 0 && m >= 3) {
                    Task_NextState1(a);
                    break;
                }
                if (w->bodyType == 1 && m >= 4) {
                    Task_NextState1(a);
                    break;
                }
                Stg20_FilterPartsList(a, 0x63);
                if (w->count == 0) {
                    Task_NextState1(a);
                    break;
                }
                Text_OpenById(&w->hdr[1], m + 0x164, 0, Stg20_BeetlePartsTextPos[1]);
                Text_OpenById(&w->hdr[2], 0x14F, 0, Stg20_BeetlePartsTextPos[2]);
                Stg20_OpenMsgOrDesc(&w->descText, m + 0x155, Stg20_BeetlePartsTextPos[7], 0);
                w->frameMode = 1;
                w->listShown = 1;
                w->dirty = 1;
                w->top = 0;
                w->cursor = 0;
                w->cursorShown = 0;
                Task_NextState2(a);
            case 1:
                if (D_8005F704 > 0) {
                    Snd_PlayById(0x13, 0);
                    w->dirty = 1;
                    w->cursorShown = 1;
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
                    ((Stg20GameState *)&Save_GameState)->slotItems[k + 8] = (a->elapsed & 0x10) ? item : 0;
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
                        ((Stg20GameState *)&Save_GameState)->slotItems[k + 8] = 0;
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
                        ((Stg20GameState *)&Save_GameState)->slotItems[k + 8] = 0;
                    }
                    w->dirty = 1;
                } else if (Pad_State[0].cross > 0) {
                    if (k == -1) {
                        goto deny;
                    }
                    Snd_PlayById(0x14, 0);
                    ((Stg20GameState *)&Save_GameState)->slotItems[k + 8] = item;
                    Stg20_PartsListRemove(a, item);
                    Task_NextState1(a);
                }
                break;
            }
            Stg20_PartsListRefresh(a);
            break;
        }
        case 17:
            switch (a->stateLevel2) {
            case 0:
            default:
                for (i = 0; i < 10; i++) {
                    Text_Close(&w->texts[i]);
                }
                w->listShown = 0;
                Stg20_OpenMsgOrDesc(&w->descText, 0x14E, Stg20_BeetlePartsTextPos[7], 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (D_8005F704 > 0) {
                Stg20_PartsListToBag(a);
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}

void Stg20_BeetlePartsDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0x12);
    Task_DefaultDestroy(a);
}

void Stg20_BeetlePartsDraw(Actor *a) {
    Stg20ItemListWork *w = (Stg20ItemListWork *)a->work;
    GfxPart *p;
    GfxPart *q;

    Stg20_CalcBeetleHideMasks(a);
    p = (GfxPart *)Cd_GetFileEntry(Stg20_BodyDiagramParts[0][w->bodyType]);
    Gfx_HidePartsByMask((GfxPartMaskView *)p, w->hideMask0);
    Gfx_DrawParts((s32)p);
    p = (GfxPart *)Cd_GetFileEntry(Stg20_BodyDiagramParts[1][w->bodyType]);
    Gfx_HidePartsByMask((GfxPartMaskView *)p, w->hideMask1);
    Gfx_DrawParts((s32)p);
    p = (GfxPart *)Cd_GetFileEntry(0xC93000A);
    for (q = p; q->fileId != 0; q++) {
        switch (w->frameMode) {
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
    if (w->listShown != 0) {
        p = (GfxPart *)Cd_GetFileEntry(0xC93000B);
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & 2) {
                q->visible = w->cursorShown != 0;
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

s32 Stg20_CanUpgradePart(s32 item)
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

void Stg20_BuildUpgradeList(Actor *a) {
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
        id = ((Stg20GameState *)&Save_GameState)->slotItems[Stg20_UpgradeSlots[i]];
        w->recs[i].item = id;
        if (id != 0) {
            name = (u8 *)Item_GetNameText(id);
            j = 0;
            while (*name != 0xFF) {
                w->recs[i].name[j++] = *name++;
            }
            if (Stg20_CanUpgradePart(id) != 0) {
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

void Stg20_UpgradeListRefresh(Actor *a) {
    Stg20ItemWork *w = (Stg20ItemWork *)a->work;
    s32 i;

    if (w->dirty != 0) {
        w->dirty = 0;
        for (i = 0; i < 6; i++) {
            Text_OpenPacked(&w->texts[i], (s32)w->recs[i].name, 0, Stg20_UpgradeTextPos[i + 4]);
        }
        Text_Close(&w->descText);
        if (w->recs[w->index].item != 0) {
            Text_OpenPacked(&w->descText, Item_GetDescText(w->recs[w->index].item), 0, Stg20_UpgradeTextPos[10]);
        }
    }
}

void Stg20_PartsUpgradeUpdate(Actor *task) {
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
        Text_OpenById(&w->hdr[0], 0x17A, 4, Stg20_UpgradeTextPos[0]);
        Text_OpenById(&w->hdr[1], 0x17B, 4, Stg20_UpgradeTextPos[1]);
        Text_OpenById(&w->hdr[2], 0xDE, 0, Stg20_UpgradeTextPos[2]);
        Text_OpenPacked(&w->hdr[3], (s32) &D_8005E6F1, 0, Stg20_UpgradeTextPos[3]);
        Task_Create(0x30D, (s32 *) children, 0);
        Stg20_BuildUpgradeList(task);
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
        Stg20_UpgradeListRefresh(task);
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
        Save_GameState.itemCounts[Stg20_UpgradeSlots[w->index]]++;
        Stg20_BuildUpgradeList(task);
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
        Stg20_OpenMsgOrDesc(&w->msgText, w->msg, Stg20_UpgradeTextPos[11], w->msgArg);
    }
}

void Stg20_PartsUpgradeDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 0xC);
    Task_DefaultDestroy(a);
}

void Stg20_PartsUpgradeDraw(Actor *a) {
    Stg20RowWork *w = (Stg20RowWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xC930000);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = -0x56;
            q->y = w->index * 12 - 0x34;
        }
    }
    Gfx_DrawParts((s32)p);
}

Stg20FileRec *Stg20_GetMapDest(s32 i) {
    Stg20FileRec *r = (Stg20FileRec *)Cd_GetFileEntry(Sys_GameMode[0] + 0xD28FCD6);

    if (r[i].relocated == 0) {
        s32 base = Cd_GetFileOrNull(0xD29);

        r[i].relocated = 1;
        r[i].text += base;
    }
    return &r[i];
}

void Stg20_WarpPadInit(Actor *a, s32 v) {
    a->param = v;
}

void Stg20_WarpPadUpdate(Actor *a) {
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
            c = *Stg20_GetActorCell(w->target);
            if (c.x == Stg20_WarpPads[a->param].cell.x && c.y == Stg20_WarpPads[a->param].cell.y) {
                ok = Stg20_IsOnCellCenter(w->target) != 0;
            }
            if (ok == 0) {
                Task_NextState0(a);
            }
        }
        break;
    case 1:
        c = *Stg20_GetActorCell(w->target);
        if (c.x == Stg20_WarpPads[a->param].cell.x && c.y == Stg20_WarpPads[a->param].cell.y
            && Stg20_IsOnCellCenter(w->target) != 0) {
            Stg20_WalkerHalt(w->target);
            Stg20_TalkActive = 1;
            Task_NextState0(a);
        }
        break;
    case 2:
        o = (Stg20Rot *)w->target->u38.ptr38;
        o->rotY += 0x177;
        o->scaleY += 0x190;
        if (o->scaleX > 100) {
            o->scaleX -= 100;
        } else {
            o->scaleX = 0;
        }
        v = o->scaleZ;
        if (v > 100) {
            o->scaleZ -= 100;
        } else {
            o->scaleZ = 0;
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            Snd_PlayById(0x32, 0);
            o = (Stg20Rot *)w->target->u38.ptr38;
            slot = (s32 *)a->u34.children;
            args.animFileId = 0xE45;
            args.modelFileId = 0xE46;
            args.rotY = 0;
            args.duration = 0x78;
            args.x = o->posX;
            args.y = o->posY;
            args.z = o->posZ;
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
                Sys_State.nextGameMode = Stg20_WarpPads[a->param].nextMode;
                Sys_State.modeArg = Stg20_WarpPads[a->param].modeArg;
            }
            break;
        }
        break;
    }
}

void Stg20_CameraUpdate(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;
    Actor *e;

    switch (a->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->coord);
        if (Sys_GameMode[0] < 0x32F) {
            w->proj = 0x5A0;
            w->view.vpy = -0x5D00;
            w->view.vpx = 0;
            w->view.vpz = -0x5A00;
            w->view.vrx = 0;
            w->view.vry = 0;
            w->view.vrz = 0;
        } else {
            w->proj = 0x5DC;
            w->view.vpy = -0xFA0;
            w->view.vpz = -0x3578;
            w->view.vpx = 0;
            w->view.vrx = 0;
            w->view.vry = -0x3E8;
            w->view.vrz = 0;
        }
        w->view.rz = 0;
        w->view.super = &w->coord;
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
            w->view.vpy = -0xFA0;
            w->view.vpz = -0x3578;
            w->speed = 0;
            return;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (w->view.vpy >= -0x270F) {
                    w->view.vpy -= 0x1F4;
                    break;
                }
                w->view.vpy = -0x2710;
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
                w->view.vpz += 0x390;
                w->view.vpy += 0x29A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeInFromWhite(0x14);
            case 3:
                w->speed -= 0x1080;
                w->view.vpz -= 0x390;
                w->view.vpy -= 0x10A;
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
                if (w->view.vpy >= -0x270F) {
                    w->view.vpy -= 0x1F4;
                    break;
                }
                w->view.vpy = -0x2710;
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
                w->view.vpz += 0x390;
                w->view.vpy += 0x29A;
                if (--w->timer != 0) {
                    break;
                }
                Task_NextState2(a);
                w->timer = 0xF;
                Gfx_FadeInFromWhite(0x14);
            case 3:
                w->speed -= 0x840;
                w->view.vpz -= 0x390;
                w->view.vpy -= 0x10A;
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
                ((Stg20Rot *)e->u38.ptr38)->rotY += w->speed / 256;
            }
            e = (Actor *)Task_FindFirst(0x30A, -1, 1);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->rotY -= w->speed / 256;
            }
            break;
        }
        if (Stg20_LabIsDna[0] == 0) {
            e = (Actor *)Task_FindFirst(7, -1, -1);
            if (e != NULL) {
                ((Stg20Rot *)e->u38.ptr38)->rotY = w->rot[1];
            }
        }
        break;
    }
}

void Stg20_CameraDraw(Actor *a) {
    Stg20CamWork *w = (Stg20CamWork *)a->work;

    RotMatrixYXZ(w->rot, &w->coord.coord);
    w->coord.coord.t[0] = w->tx;
    w->coord.coord.t[1] = w->ty;
    w->coord.coord.t[2] = w->tz;
    w->coord.flg = 0;
    GsSetProjection(w->proj);
    GsSetRefView2(&w->view);
}
