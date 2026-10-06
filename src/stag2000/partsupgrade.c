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
#include "stag2000/partsupgrade.h"

Halves Stg20_UpgradeTextPos[] = {
    { 0x54, 0x39 }, { 0xAF, 0x39 }, { 0x77, 0x17 }, { 0x20, 0x17 }, { 0x54, 0x45 }, { 0x54, 0x51 },
    { 0x54, 0x5D }, { 0x54, 0x69 }, { 0x54, 0x75 }, { 0x54, 0x81 }, { 0x47, 0x9C }, { 0x10, 0xBA },
};
s32 Stg20_UpgradeSlots[6] = { 1, 3, 9, 0xA, 0xD, 0xE };
TaskDesc Stg20_PartsUpgradeDesc = {
    0, Stg20_PartsUpgradeUpdate, Stg20_PartsUpgradeDestroy, Stg20_PartsUpgradeDraw, 0x104, 4,
};

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
        if (Pad_Triangle > 0) {
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
        if (Pad_Cross > 0) {
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
