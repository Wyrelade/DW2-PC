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
#include "stag2000/beetleparts.h"

/* Task callback the descriptor below needs (defined further down). */
void Stg20_BeetlePartsUpdate(Actor *a);

Halves Stg20_BeetlePartsTextPos[] = {
    { 0x1C, 0x13 }, { 0x68, 0x13 }, { 0xD1, 0x13 }, { 0xD1, 0x21 }, { 0xD1, 0x2F }, { 0xD1, 0x3D },
    { 0xD1, 0x4B }, { 0x10, 0xAC }, { 0xD1, 0x29 }, { 0xD1, 0x35 }, { 0xD1, 0x41 }, { 0xD1, 0x4D },
    { 0xD1, 0x59 }, { 0xD1, 0x65 }, { 0xD1, 0x71 }, { 0xD1, 0x7D }, { 0xD1, 0x89 }, { 0xD1, 0x95 },
};
s32 Stg20_PartsPageCategory[10] = { 0, 2, 1, 3, 4, 5, 6, 0xC, 0xD, 0xE };
s32 Stg20_PartsPageSlot[10] = { 1, 3, 2, 4, 5, 6, 7, 0xD, 0xE, 0xF };
s32 Stg20_BodyDiagramParts[2][3] = {
    { 0x0C930002, 0x0C930003, 0x0C930004 },
    { 0x0C930005, 0x0C930006, 0x0C930007 },
};
TaskDesc Stg20_BeetlePartsDesc = {
    0, Stg20_BeetlePartsUpdate, Stg20_BeetlePartsDestroy, Stg20_BeetlePartsDraw, 0x1C8, 4,
};

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
            if (Pad_State[0].cross > 0) {
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
            if (Pad_Cross > 0) {
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
                if (Pad_State[0].cross > 0) {
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
                if (Pad_State[0].cross > 0) {
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
            if (Pad_State[0].cross > 0) {
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
