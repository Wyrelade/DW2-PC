#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
Halves Menu_ItemUseMsgPos;
u8 *Menu_PartGridSlots;
u8 *Menu_PartGridLabels;

void Menu_SubMenuInit(Actor *arg0, s16 arg1) {
    ActorWork *w = arg0->work;

    w->menuId = arg1;
    if (arg1 == 3) {
        Menu_Ctx->pickResult = 0;
    }
    w->optionsHidden = 0;
}

void Menu_SubMenuTask(Actor *a) {
    MenuSubMenuWork *w = (MenuSubMenuWork *)a->work;
    s32 *p = (s32 *)a->u34.children;
    Pair54 *tbl;
    s32 idx;

    switch (a->stateLevel0) {
    default:
    case 0:
        w->u2C.blk = ((MenuSubMenuLayout *)Cd_GetFileEntry(0x5130007))[w->menuId - 1];
        Mem_FillWordsNeg1(w, 0xA);
        Task_NextState0(a);
        break;
    case 1:
        tbl = (Pair54 *)Cd_GetFileEntrySubPtr(0x513000A, w->menuId - 1);
        switch (a->stateLevel1) {
        default:
        case 0:
            if (Math_RampToOne((s32)a, &w->ramp) == 0) {
                Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130008, w->menuId - 1), 2);
                switch (w->menuId) {
                case 5:
                case 6:
                    Task_SetState1(a, 2);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            }
            break;
        case 1:
            if (((s32 (*)(s16 *, s16 *))Menu_MoveGridCursorP1)(w->cursor, w->u2C.gridSize) == 0) {
            if (Pad_State[0].cross > 0) {
                idx = Menu_GridIndexColMajor(w->cursor, w->u2C.gridSize);
                if (tbl[idx].field_0 == -1) {
                    break;
                }
                w->selection = idx;
                Snd_PlayById(0xA, 0);
                switch (w->menuId) {
                case 7:
                case 8:
                    Menu_Ctx->subMenuCursor = w->cursor[0];
                    Task_NextState1(a);
                    break;
                case 4:
                    Task_SetState1(a, 3);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            } else if (Pad_State[0].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a, 2);
            }
            } else {
                Snd_PlayById(0xC, 0);
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            default:
            case 0:
                Task_Create(tbl[w->selection].field_0, p, tbl[w->selection].field_2);
                Task_NextState2(a);
                break;
            case 1:
                if (w->menuId == 3) {
                    switch (Menu_Ctx->pickResult) {
                    case 1:
                        Text_CloseArray(w->optionTexts, 9);
                        w->optionsHidden = 1;
                        break;
                    case 2:
                        Text_CloseArray(w, 0xA);
                        Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130008, w->menuId - 1), 0);
                        w->optionsHidden = 0;
                        break;
                    }
                    Menu_Ctx->pickResult = 0;
                }
                if (*p == 0) {
                    switch (w->menuId) {
                    default:
                        Task_SetState1(a, 1);
                        break;
                    case 5:
                    case 6:
                        Task_SetState0(a, 2);
                        break;
                    }
                }
                break;
            }
            break;
        case 3: {
            s32 *q = (s32 *)a->u34.children;
            switch (a->stateLevel2) {
            default:
            case 0:
                Text_CloseArray(w, 0xA);
                Task_NextState2(a);
                break;
            case 1:
                if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                    Task_NextState2(a);
                }
                break;
            case 2:
                Task_Create(tbl[w->selection].field_0, q, tbl[w->selection].field_2);
                Task_NextState2(a);
                break;
            case 3:
                if (*q == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        default:
        case 0:
            Text_CloseArray(w, 0xA);
            Task_NextState1(a);
            break;
        case 1:
            if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}


extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(GfxPart *, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);

void Menu_SubMenuDraw(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;

    if (w->subMenuRamp == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130009);
    if (*p == 0) {
        return;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        if (w->field_2C != 0 && w->optionsHidden == 0) {
            Menu_SetPartsGridPos(obj, 2, &w->field_28, &w->field_2C);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 2);
        }
        list++;
        Gfx_SetPartsScale(obj, 0x1000, w->subMenuRamp);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);
}

void Menu_StatusInit(Actor *arg0, s16 arg1) {
    arg0->work->field_6C = arg1;
}

void Menu_StatusTask(Actor *a0) {
    Wk14CBC *w = (Wk14CBC *)a0->work;
    s32 i;
    s32 v;
    s32 id;
    s32 *p;
    s16 *tbl;
    Halves *h;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->digiCount = Digi_ListByState(3, (DigiRosterEntry **)w->digiList);
        Mem_FillWordsNeg1(w, 0x1A);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->scale) != 0) {
                break;
            }
            Text_PrintIdList(w->labelTexts, (TextIdListEntry *)Cd_GetFileEntry(0x513000B), 2);
            w->textArgs[0] = (s32)Save_GameStatePtr->field_14;
            tbl = (s16 *)Cd_GetFileEntry(0x513000F);
            w->textArgs[1] = (s32)Cd_GetFileEntry(tbl[Save_GameStatePtr->field_11 * 11 + Save_GameStatePtr->field_12] + 0x1FD0000);
            w->textArgs[2] = (s32)Save_GameStatePtr->field_D1;
            p = &w->textArgs[3];
            for (i = 0; i < w->digiCount; i++) {
                *p++ = (s32)w->digiList[i]->name;
            }
            *p = 0;
            Text_PrintList(w->listTexts, (Halves *)Cd_GetFileEntry(0x513000C), w->textArgs, 2);
            if (Menu_Ctx->flags & 1) {
                h = (Halves *)Cd_GetFileEntry(0x513000D);
                for (i = 0; i < 4; i++) {
                    v = (i == 3) ? Bug_GetMaxMemBugLevel() : D_8005071C->bugLevels[i];
                    if (v != 0) {
                        id = v + 0x1FD00EC;
                        Text_OpenPacked(&w->field_58[i], (s32)Cd_GetFileEntry(i * 3 + id), 1, h[i]);
                    }
                }
            }
            for (i = w->digiCount; i < 3; i++) {
                Text_Close(&w->labelTexts[i * 3 + 7]);
                Text_Close(&w->labelTexts[i * 3 + 8]);
                Text_Close(&w->labelTexts[i * 3 + 9]);
            }
            Task_NextState1(a0);
            break;
        case 1:
            if (Pad_State[0].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 2);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w, 0x1A);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->scale) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void Menu_StatusDraw(Actor *actor) {
    Wk14CBC *w = (Wk14CBC *)actor->work;
    s32 *p;
    s32 *list;
    s32 i;
    GfxPart *obj;
    DigiRosterHudView *rec;

    if (w->scale == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x513000E);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
    do {
        obj = (GfxPart *)Cd_GetFileEntry(*list);
        if (i == 0) {
            Gfx_SetPartsNumber(obj, 2, 8, Save_GameStatePtr->field_8);
            Gfx_SetPartsNumber(obj, 4, 4, Save_GameStatePtr->maxHp);
            Gfx_SetPartsNumber(obj, 8, 4, Save_GameStatePtr->hp);
            Gfx_SetPartsNumber(obj, 0x10, 4, Save_GameStatePtr->maxMp);
            Gfx_SetPartsNumber(obj, 0x20, 4, Save_GameStatePtr->mp);
        } else if (i - 1 < w->digiCount) {
            rec = w->digiList[i - 1];
            Gfx_SetPartsNumber(obj, 2, 3, rec->maxHp);
            Gfx_SetPartsNumber(obj, 4, 3, rec->hp);
            Gfx_SetPartsNumber(obj, 8, 3, rec->maxMp);
            Gfx_SetPartsNumber(obj, 0x10, 3, rec->mp);
            Gfx_SetPartsNumber(obj, 0x20, 2, rec->level);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 0xFFFF);
        }
        Gfx_SetPartsScale((GfxPartScaleView *)obj, 0x1000, w->scale);
        list++;
        Gfx_DrawParts((s32)obj);
        i++;
    } while (*list != 0);
}

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
    m = D_8005071C->bugLevels[n];
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
        } else if (D_8005071C->memBugCount != 0) {
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
            if (D_8005071C->bugLevels[0] + D_8005071C->bugLevels[1] + D_8005071C->bugLevels[2] + D_8005071C->memBugCount != 0) {
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
            v = D_8005071C->bugLevels[i];
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
