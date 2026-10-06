#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/mapbg.h"
#include "stag2000/staticbg.h"
#include "stag2000/digilab.h"
#include "stag2000/itemshop.h"
#include "stag2000/beetleshop.h"
#include "stag2000/stag2000_funcs.h"
#include "stag2000/areaselect.h"
#include "stag2000/labmodesel.h"
#include "stag2000/labroster.h"
#include "stag2000/msgwin.h"
#include "stag2000/labcaption.h"
#include "stag2000/labinfo.h"
#include "stag2000/labskills.h"
#include "stag2000/labpair.h"
#include "stag2000/dna.h"
#include "stag2000/shadow.h"
#include "stag2000/labjogbg.h"
#include "stag2000/labdigimodel.h"
#include "stag2000/mapexit.h"
#include "stag2000/walker.h"
#include "stag2000/xastream.h"
#include "stag2000/shopbg.h"
#include "stag2000/shopbits.h"
#include "stag2000/itemshopmenu.h"
#include "stag2000/beetleshopmenu.h"
#include "stag2000/shoplist.h"

Stg20Cell Stg20_ShopListTextPos[6] = {
    { 0x28, 0x17 }, { 0x82, 0x17 }, { 0xE7, 0x30 }, { 0xD5, 0xA2 }, { 0x10, 0xBA }, { 0x10, 0xCA },
};
/* Beetle part item id lists, 0-terminated. */
u8 Stg20_PartsAnyBody[] = {
    0x2F, 0x30, 0x31, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x4A, 0x4B, 0x4C,
    0x50, 0x51, 0x52, 0x55, 0x56, 0x57, 0x5A, 0x5B, 0x5C, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65,
    0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75,
    0x76, 0x77, 0,
};
u8 Stg20_ShooterGunAmmo[] = {
    0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB,
    0xCC, 0xCD, 0xCE, 0xCF, 0,
};
u8 Stg20_ZCannonAmmo[] = { 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0 };
u8 Stg20_PartsAdmantOnly[] = {
    0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x33, 0x34, 0x44, 0x45, 0x46,
    0x47, 0x48, 0x49, 0x4E, 0x4F, 0x54, 0x59, 0x5E, 0,
};
u8 Stg20_PartsSteelOnly[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0 };
u8 Stg20_PartsNotAdmant[] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0 };
u8 Stg20_PartsTitanOnly[] = { 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0 };
u8 Stg20_PartsNotSteel[] = {
    0x1F, 0x20, 0x21, 0x22, 0x23, 0x32, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x4D, 0x53, 0x58, 0x5D, 0,
};
u8 Stg20_MissileGunAmmo[] = {
    0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0,
};
u8 Stg20_RCannonAmmo[] = { 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0 };
TaskDesc Stg20_ShopListDesc = { 0, Stg20_ShopListUpdate, Stg20_ShopListDestroy, Stg20_ShopListDraw, 0x64, 4 };

Stg20ShopList Stg20_ShopItems;

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
        if (Save_GameState.itemCounts[8] != 0) {
            return 0x12F;
        }
        return 0x130;
    }
    if (Stg20_ByteListHas(Stg20_ZCannonAmmo, id)) {
        if (Save_GameState.itemCounts[9] != 0) {
            return 0x12F;
        }
        return 0x133;
    }
    if (Stg20_ByteListHas(Stg20_MissileGunAmmo, id)) {
        if (Save_GameState.itemCounts[11] != 0) {
            return 0x12F;
        }
        return 0x135;
    }
    if (Stg20_ByteListHas(Stg20_RCannonAmmo, id)) {
        if (Save_GameState.itemCounts[10] != 0) {
            return 0x12F;
        }
        return 0x136;
    }
    if (Stg20_ByteListHas(Stg20_PartsAdmantOnly, id)) {
        if (Save_GameState.itemCounts[0] == 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsSteelOnly, id)) {
        if (Save_GameState.itemCounts[0] == 0xEA) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsTitanOnly, id)) {
        if (Save_GameState.itemCounts[0] == 0xEB) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsNotAdmant, id)) {
        if (Save_GameState.itemCounts[0] != 0xEC) {
            return 0x131;
        }
        return 0x134;
    }
    if (Stg20_ByteListHas(Stg20_PartsNotSteel, id)) {
        if (Save_GameState.itemCounts[0] != 0xEA) {
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
    u16 *list = &Save_GameState.itemCounts[29];
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
                        if (Item_GetPrice(item) > Save_GameState.bits) {
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
            } else if (Pad_State[0].triangle > 0 || Flag_Test(0x10) != 0) {
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
