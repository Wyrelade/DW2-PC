#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/submenu.h"

/* Declarations the original file made before this code. */
extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);

/* Small data this unit defines: initialised ones go to .sdata, the rest to .sbss in
 * game.h's order. Retail reaches them with %gp_rel here. */
Halves Menu_ItemUseMsgPos = { 0x10, 0xBA };
u8 *Menu_PartGridSlots;
u8 *Menu_PartGridLabels;

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_SetItemUseMode(Actor *a, s16 arg);
void Menu_ItemUseTask(Actor *a0);
void Menu_ItemUseDraw(Actor *actor);

TaskDesc D_80040EE4 = {
    (TaskInitFn)Menu_SetItemUseMode, Menu_ItemUseTask, Task_DefaultDestroy, Menu_ItemUseDraw, 0xA0, 4,
};

void Menu_UseItemDirect(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    TextDescHalves st;

    if (Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, 0) != 0) {
        st.pos = Menu_ItemUseMsgPos;
        st.color = 0;
        st.packedStyle = 0x81;
        st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
        st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        Text_OpenDesc(&w->msgText, (TextDesc *)&st);
        Snd_PlayById(0x1D, 0);
    } else {
        Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, Menu_ItemUseMsgPos);
    }
}

void Menu_UseBugZapItem(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    Halves *pos;
    Sub17D84 *rec;
    s32 n;
    s32 m;
    s32 r;
    TextDescHalves st;

    rec = (Sub17D84 *)Item_GetEffectRec(Menu_Ctx->itemId);
    pos = &Menu_ItemUseMsgPos;
    n = rec->digiId - 0xC;
    m = Dung_StatePtr->bugLevels[n];
    st.pos = *pos;
    st.color = 0;
    st.packedStyle = 0x81;
    switch (rec->digiId) {
    case 0xC:
    case 0xD:
    case 0xE:
        r = Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, 0);
        if (r == 0) {
            Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, *pos);
            goto end;
        }
        if (r == 1) {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B3);
            r = 0x1FD00EC;
            st.strArg0 = (s32)Cd_GetFileEntry(n * 3 + (m + r));
        } else {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        }
        Text_OpenDesc(&w->msgText, (TextDesc *)&st);
        break;
    case 0xF:
    default:
        r = Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, 0);
        if (r == 0) {
            Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, Menu_ItemUseMsgPos);
            goto end;
        }
        if (r == 2) {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        } else if (Dung_StatePtr->memBugCount != 0) {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B5);
            st.strArg0 = 0;
        } else {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B3);
            r = 0x1FD00EC;
            st.strArg0 = (s32)Cd_GetFileEntry(n * 3 + (Bug_LastZappedLevel + r));
        }
        Text_OpenDesc(&w->msgText, (TextDesc *)&st);
        break;
    case 0x10:
        r = Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, 0);
        if (r == 0) {
            Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, *pos);
            goto end;
        }
        if (r == 2) {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        } else {
            st.strArg0 = 0;
            if (Dung_StatePtr->bugLevels[0] + Dung_StatePtr->bugLevels[1] + Dung_StatePtr->bugLevels[2] + Dung_StatePtr->memBugCount != 0) {
                st.text = (s32)Cd_GetFileEntry(0x1FD00B7);
            } else {
                st.text = (s32)Cd_GetFileEntry(0x1FD00B6);
            }
        }
        Text_OpenDesc(&w->msgText, (TextDesc *)&st);
        break;
    }
end:
    Menu_OpenBugTexts(a0, 0);
}

void Menu_OpenItemNameTexts(Actor *a0, s32 a1) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 i;
    s32 id;
    s32 k;
    s32 img;
    Halves h;

    for (i = 0; i < 20; i++) {
        img = (s32)Cd_GetFileEntry(0x1FD0098);
        id = Menu_PartGridSlots[i];
        k = 0;
        if (id != 0xFF && Save_GameStatePtr->slotItems[id] != 0) {
            img = Item_GetNameText(Save_GameStatePtr->slotItems[id]);
            if (Save_GameStatePtr->slotStatus[id] != 0) {
                k = 3;
            }
        }
        h.lo = (i / w->gridSize[1]) * 98 + 0x88;
        h.hi = (i % w->gridSize[1]) * 12 + 0x32;
        Text_OpenPacked(&w->itemTexts[i], img, a1, h);
        Text_SetColor(w->itemTexts[i], k);
    }
}

void Menu_OpenBugTexts(Actor *a0, s32 a1) {
    HudSlots153F4 *w = (HudSlots153F4 *)a0->work;
    Halves *h;
    s32 i;
    s32 id;
    s32 v;

    h = (Halves *)Cd_GetFileEntry(0x5130016);
    for (i = 0; i < 4; i++) {
        if (i == 3) {
            v = Bug_GetMaxMemBugLevel();
        } else {
            v = Dung_StatePtr->bugLevels[i];
        }
        if (v != 0) {
            id = 0x1FD00EC;
            id = i * 3 + (v + id);
            Text_OpenPacked(&w->slot[i], (s32)Cd_GetFileEntry(id), a1, h[i]);
        } else {
            Text_Close(&w->slot[i]);
        }
    }
}

void Menu_ShowPartSlotInfo(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 i;
    s32 id;
    Halves h;

    i = Menu_GridIndexColMajor(w->cursor, w->gridSize);
    Text_Close(&w->msgText);
    Text_Close(&w->field_54);
    Text_Close(&w->labelText);
    id = Menu_PartGridSlots[i];
    if (id != 0xFF) {
        h.lo = 0xF;
        h.hi = 0x32;
        Text_OpenPacked(&w->labelText, (s32)Cd_GetFileEntry(Menu_PartGridLabels[i] | 0x1FD0000), 0, h);
        if (Save_GameStatePtr->slotItems[id] != 0) {
            Text_OpenPacked(&w->msgText, Item_GetDescText(Save_GameStatePtr->slotItems[id]), 0x80, Menu_ItemUseMsgPos);
            if (Save_GameStatePtr->slotStatus[id] != 0) {
                h.lo = 0x10;
                h.hi = 0xCA;
                Text_OpenPacked(&w->field_54, (s32)Cd_GetFileEntry(0x1FD0097), 0x80, h);
            }
        }
    }
}

void Menu_OpenUseItemTexts(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    Halves h;

    Text_Close(&w->labelText);
    Text_Close(&w->itemNameText);
    h.lo = 0xF;
    h.hi = 0x32;
    Text_OpenPacked(&w->labelText, (s32)Cd_GetFileEntry(0x1FD009B), 0, h);
    h.lo = 0xF;
    h.hi = 0x47;
    Text_OpenPacked(&w->itemNameText, Item_GetNameText(Menu_Ctx->itemId), 0, h);
    if (w->useMode == 3) {
        Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00FB), 0x80, Menu_ItemUseMsgPos);
    }
}

void Menu_UseItemOnTarget(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 id;
    TextDescHalves st;

    if (Pad_State[0].cross > 0) {
        id = Menu_PartGridSlots[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
        if (id != 0xFF && Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, id, 0) != 0) {
            st.pos = Menu_ItemUseMsgPos;
            st.color = 0;
            st.packedStyle = 0x81;
            st.text = (s32)Cd_GetFileEntry(0x1FD00FC);
            st.strArg0 = Item_GetNameText(Save_GameStatePtr->slotItems[id]);
            Text_OpenDesc(&w->msgText, (TextDesc *)&st);
            Menu_OpenItemNameTexts(a0, 0);
            Snd_PlayById(0x1D, 0);
            Task_SetState1(a0, 3);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}

void Menu_SetItemUseMode(Actor *a, s16 arg) {
    ActorWork *w = a->work;
    s32 mode;
    s32 k;

    w->useMode = arg;
    mode = arg;
    if (mode == 2) {
        k = ((u8 *)Item_GetEffectRec(Menu_Ctx->itemId))[1];
        if (k == 11) {
            goto three;
        }
        if (k < 11) {
            goto def;
        }
        if (k < 17) {
            w->useMode = 4;
            return;
        }
    def:
        w->useMode = mode;
        return;
    three:
        w->useMode = 3;
    }
}

void Menu_ItemUseTask(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 r;
    s32 id;
    s32 next;

    Menu_PartGridSlots = (u8 *)Cd_GetFileEntry(0x5130014);
    Menu_PartGridLabels = (u8 *)Cd_GetFileEntry(0x5130015);
    switch (a0->stateLevel0) {
    case 0:
    default:
        *(Layout8C *)w->gridSize = *(Layout8C *)Cd_GetFileEntry(0x5130010);
        Mem_FillWordsNeg1(w->itemTexts, 0x22);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->ramp) != 0) {
                break;
            }
            Text_PrintIdList(&w->listTexts, (TextIdListEntry *)Cd_GetFileEntry(0x5130011), 2);
            Menu_OpenItemNameTexts(a0, 1);
            if (Menu_Ctx->flags & 1) {
                Menu_OpenBugTexts(a0, 1);
            }
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->useMode) {
            case 1:
                Menu_ShowPartSlotInfo(a0);
                Task_NextState1(a0);
                break;
            case 2:
                Menu_OpenUseItemTexts(a0);
                Menu_UseItemDirect(a0);
                Task_SetState1(a0, 3);
                break;
            case 3:
                Menu_OpenUseItemTexts(a0);
                Task_NextState1(a0);
                break;
            case 4:
                Menu_OpenUseItemTexts(a0);
                Menu_UseBugZapItem(a0);
                Task_SetState1(a0, 3);
                break;
            case 5:
switch (Beetle_GetPart(0x10)) {
case -1:
id = 0x154;
 next = 3;
break;
case 0:
id = 0x153;
 next = 3;
break;
default:
id = 0x152;
 next = 4;
break;
}
                Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(id | 0x1FD0000), 0x82, Menu_ItemUseMsgPos);
                Task_SetState1(a0, next);
                break;
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->gridSize) == 0) {
                if (Pad_State[0].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(a0, 2);
                } else if (w->useMode == 3) {
                    Menu_UseItemOnTarget(a0);
                }
            } else {
                Snd_PlayById(0xD, 0);
                Task_SetState1(a0, 1);
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
                if (Text_IsFinished(w->msgText) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (Pad_State[0].triangle > 0 || Pad_State[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 4:
            r = Text_WaitYesNo(w->msgText);
            switch (r) {
            case 1:
                Gfx_FadeOutToBlack(0x20);
                Menu_Ctx->topMenuResult = r;
                Task_SetState0(a0, 2);
                break;
            case -1:
                Task_SetState0(a0, 2);
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->itemTexts, 0x22);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->ramp) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Menu_ItemUseDraw(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 k;
    s32 mask;

    if (w->useRamp == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130012);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        mask = 1 << i;
        if (((s32 *)Cd_GetFileEntry(0x5130013))[w->useMode - 1] & mask) {
            switch (i) {
            case 0:
            if (w->useMode == 1 || w->useMode == 3) {
                Menu_SetPartsGridPos(obj, 2, &w->useCursor, &w->useGridSize);
                Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
                Gfx_HidePartsByMask(obj, 0);
            } else {
                Gfx_HidePartsByMask(obj, 2);
            }
            Gfx_SetPartsNumber(obj, 4, 4, Save_GameStatePtr->maxHp);
            Gfx_SetPartsNumber(obj, 8, 4, Save_GameStatePtr->hp);
            Gfx_SetPartsNumber(obj, 0x10, 4, Save_GameStatePtr->maxMp);
            Gfx_SetPartsNumber(obj, 0x20, 4, Save_GameStatePtr->mp);
                break;
            case 1:
            case 3:
                k = 0;
                if (w->useMode == 5) {
                    k = -1;
                } else if (i == 3) {
                    k = 4;
                }
                Gfx_HidePartsByMask(obj, k);
                break;
            default:
                Gfx_HidePartsByMask(obj, 0);
                break;
            }
            Gfx_SetPartsScale(obj, 0x1000, w->useRamp);
            Gfx_DrawParts((s32)obj);
        }
        i++;
    } while (p[i] != 0);
}
