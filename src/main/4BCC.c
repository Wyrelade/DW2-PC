#include "common.h"
#include "main/game.h"
#include "main/187C.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
Halves D_80050700;
Halves D_80050704;
Halves D_80050708;
Halves D_8005070C;
Halves D_80050710;
Halves D_80050714;
u8 *D_8005076C;
u8 *D_80050770;
s32 D_80050778;
s32 D_8005077C;
s32 Snd_CurrentId;
s32 Snd_SavedId;

void func_800143CC(Actor *arg0, s16 arg1) {
    ActorWork *w = arg0->work;

    w->field_38 = arg1;
    if (arg1 == 3) {
        Menu_Ctx->pickResult = 0;
    }
    w->field_3C = 0;
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
            if (D_8005F6F0[0].cross > 0) {
                idx = Menu_GridIndexColMajor(w->cursor, w->u2C.gridSize);
                if (tbl[idx].field_0 == -1) {
                    break;
                }
                w->selection = idx;
                Snd_PlayById(0xA, 0);
                switch (w->menuId) {
                case 7:
                case 8:
                    Menu_Ctx->field_124 = w->cursor[0];
                    Task_NextState1(a);
                    break;
                case 4:
                    Task_SetState1(a, 3);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            } else if (D_8005F6F0[0].triangle > 0) {
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

    if (w->field_40 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130009);
    if (*p == 0) {
        return;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        if (w->field_2C != 0 && w->field_3C == 0) {
            Menu_SetPartsGridPos(obj, 2, &w->field_28, &w->field_2C);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 2);
        }
        list++;
        Gfx_SetPartsScale(obj, 0x1000, w->field_40);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);
}

void func_80014978(Actor *arg0, s16 arg1) {
    arg0->work->field_6C = arg1;
}

void func_80014984(Actor *a0) {
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
            w->textArgs[0] = (s32)D_80050720->field_14;
            tbl = (s16 *)Cd_GetFileEntry(0x513000F);
            w->textArgs[1] = (s32)Cd_GetFileEntry(tbl[D_80050720->field_11 * 11 + D_80050720->field_12] + 0x1FD0000);
            w->textArgs[2] = (s32)D_80050720->field_D1;
            p = &w->textArgs[3];
            for (i = 0; i < w->digiCount; i++) {
                *p++ = (s32)w->digiList[i]->name;
            }
            *p = 0;
            Text_PrintList(w->listTexts, (Halves *)Cd_GetFileEntry(0x513000C), w->textArgs, 2);
            if (Menu_Ctx->flags & 1) {
                h = (Halves *)Cd_GetFileEntry(0x513000D);
                for (i = 0; i < 4; i++) {
                    v = (i == 3) ? func_80021D60() : D_8005071C->field_BA5[i];
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
            if (D_8005F6F0[0].triangle > 0) {
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

void func_80014CBC(Actor *actor) {
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
            Gfx_SetPartsNumber(obj, 2, 8, D_80050720->field_8);
            Gfx_SetPartsNumber(obj, 4, 4, D_80050720->maxHp);
            Gfx_SetPartsNumber(obj, 8, 4, D_80050720->hp);
            Gfx_SetPartsNumber(obj, 0x10, 4, D_80050720->maxMp);
            Gfx_SetPartsNumber(obj, 0x20, 4, D_80050720->mp);
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
        st.pos = D_80050700;
        st.color = 0;
        st.packedStyle = 0x81;
        st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
        st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        Text_OpenDesc(&w->msgText, (TextDesc *)&st);
        Snd_PlayById(0x1D, 0);
    } else {
        Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, D_80050700);
    }
}


#ifdef NORMALIZED
void func_80014F78(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    Halves *pos;
    Sub17D84 *rec;
    s32 n;
    s32 m;
    s32 r;
    TextDescHalves st;

    rec = (Sub17D84 *)Item_GetEffectRec(Menu_Ctx->itemId);
    pos = &D_80050700;
    n = rec->digiId - 0xC;
    m = D_8005071C->field_BA5[n];
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
            r = m + 0x1FD00EC;
            st.strArg0 = (s32)Cd_GetFileEntry(n * 3 + r);
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
            Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, D_80050700);
            goto end;
        }
        if (r == 2) {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        } else if (D_8005071C->field_BA8 != 0) {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B5);
            st.strArg0 = 0;
        } else {
            st.text = (s32)Cd_GetFileEntry(0x1FD00B3);
            r = 0x1FD00EC;
            st.strArg0 = (s32)Cd_GetFileEntry(n * 3 + (D_80050760 + r));
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
            if (D_8005071C->field_BA5[0] + D_8005071C->field_BA5[1] + D_8005071C->field_BA5[2] + D_8005071C->field_BA8 != 0) {
                st.text = (s32)Cd_GetFileEntry(0x1FD00B7);
            } else {
                st.text = (s32)Cd_GetFileEntry(0x1FD00B6);
            }
        }
        Text_OpenDesc(&w->msgText, (TextDesc *)&st);
        break;
    }
end:
    func_800153F4(a0, 0);
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80014F78);
void func_80014F78(Actor *a0);
#endif


void Menu_OpenItemNameTexts(Actor *a0, s32 a1) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 i;
    s32 id;
    s32 k;
    s32 img;
    Halves h;

    for (i = 0; i < 20; i++) {
        img = (s32)Cd_GetFileEntry(0x1FD0098);
        id = D_8005076C[i];
        k = 0;
        if (id != 0xFF && D_80050720->slotItems[id] != 0) {
            img = Item_GetNameText(D_80050720->slotItems[id]);
            if (D_80050720->slotStatus[id] != 0) {
                k = 3;
            }
        }
        h.lo = (i / w->gridSize[1]) * 98 + 0x88;
        h.hi = (i % w->gridSize[1]) * 12 + 0x32;
        Text_OpenPacked(&w->itemTexts[i], img, a1, h);
        Text_SetColor(w->itemTexts[i], k);
    }
}


#ifdef NORMALIZED
void func_800153F4(Actor *a0, s32 a1) {
    HudSlots153F4 *w = (HudSlots153F4 *)a0->work;
    Halves *h;
    s32 i;
    s32 id;
    s32 v;

    h = (Halves *)Cd_GetFileEntry(0x5130016);
    for (i = 0; i < 4; i++) {
        if (i == 3) {
            v = func_80021D60();
        } else {
            v = D_8005071C->field_BA5[i];
        }
        if (v != 0) {
            id = v + 0x1FD00EC;
            id = i * 3 + id;
            Text_OpenPacked(&w->slot[i], (s32)Cd_GetFileEntry(id), a1, *h);
        } else {
            Text_Close(&w->slot[i]);
        }
        h++;
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_800153F4);
void func_800153F4(Actor *a0, s32 a1);
#endif

void func_800154F0(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 i;
    s32 id;
    Halves h;

    i = Menu_GridIndexColMajor(w->cursor, w->gridSize);
    Text_Close(&w->msgText);
    Text_Close(&w->field_54);
    Text_Close(&w->field_58);
    id = D_8005076C[i];
    if (id != 0xFF) {
        h.lo = 0xF;
        h.hi = 0x32;
        Text_OpenPacked(&w->field_58, (s32)Cd_GetFileEntry(D_80050770[i] | 0x1FD0000), 0, h);
        if (D_80050720->slotItems[id] != 0) {
            Text_OpenPacked(&w->msgText, Item_GetDescText(D_80050720->slotItems[id]), 0x80, D_80050700);
            if (D_80050720->slotStatus[id] != 0) {
                h.lo = 0x10;
                h.hi = 0xCA;
                Text_OpenPacked(&w->field_54, (s32)Cd_GetFileEntry(0x1FD0097), 0x80, h);
            }
        }
    }
}


void func_80015668(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    Halves h;

    Text_Close(&w->field_58);
    Text_Close(&w->itemNameText);
    h.lo = 0xF;
    h.hi = 0x32;
    Text_OpenPacked(&w->field_58, (s32)Cd_GetFileEntry(0x1FD009B), 0, h);
    h.lo = 0xF;
    h.hi = 0x47;
    Text_OpenPacked(&w->itemNameText, Item_GetNameText(Menu_Ctx->itemId), 0, h);
    if (w->useMode == 3) {
        Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(0x1FD00FB), 0x80, D_80050700);
    }
}


void Menu_UseItemOnTarget(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 id;
    TextDescHalves st;

    if (D_8005F6F0[0].cross > 0) {
        id = D_8005076C[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
        if (id != 0xFF && Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, id, 0) != 0) {
            st.pos = D_80050700;
            st.color = 0;
            st.packedStyle = 0x81;
            st.text = (s32)Cd_GetFileEntry(0x1FD00FC);
            st.strArg0 = Item_GetNameText(D_80050720->slotItems[id]);
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

    w->field_98 = arg;
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
            w->field_98 = 4;
            return;
        }
    def:
        w->field_98 = mode;
        return;
    three:
        w->field_98 = 3;
    }
}

void Menu_ItemUseTask(Actor *a0) {
    MenuItemUseWork *w = (MenuItemUseWork *)a0->work;
    s32 r;
    s32 id;
    s32 next;

    D_8005076C = (u8 *)Cd_GetFileEntry(0x5130014);
    D_80050770 = (u8 *)Cd_GetFileEntry(0x5130015);
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
            Text_PrintIdList(&w->field_70, (TextIdListEntry *)Cd_GetFileEntry(0x5130011), 2);
            Menu_OpenItemNameTexts(a0, 1);
            if (Menu_Ctx->flags & 1) {
                func_800153F4(a0, 1);
            }
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->useMode) {
            case 1:
                func_800154F0(a0);
                Task_NextState1(a0);
                break;
            case 2:
                func_80015668(a0);
                Menu_UseItemDirect(a0);
                Task_SetState1(a0, 3);
                break;
            case 3:
                func_80015668(a0);
                Task_NextState1(a0);
                break;
            case 4:
                func_80015668(a0);
                func_80014F78(a0);
                Task_SetState1(a0, 3);
                break;
            case 5:
switch (func_80022518(0x10)) {
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
                Text_OpenPacked(&w->msgText, (s32)Cd_GetFileEntry(id | 0x1FD0000), 0x82, D_80050700);
                Task_SetState1(a0, next);
                break;
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->gridSize) == 0) {
                if (D_8005F6F0[0].triangle > 0) {
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
                if (D_8005F6F0[0].triangle > 0 || D_8005F6F0[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 4:
            r = func_800136A4(w->msgText);
            switch (r) {
            case 1:
                Gfx_FadeOutToBlack(0x20);
                Menu_Ctx->field_360 = r;
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

    if (w->field_9C == 0) {
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
        if (((s32 *)Cd_GetFileEntry(0x5130013))[w->field_98 - 1] & mask) {
            switch (i) {
            case 0:
            if (w->field_98 == 1 || w->field_98 == 3) {
                Menu_SetPartsGridPos(obj, 2, &w->field_88, &w->field_8C);
                Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
                Gfx_HidePartsByMask(obj, 0);
            } else {
                Gfx_HidePartsByMask(obj, 2);
            }
            Gfx_SetPartsNumber(obj, 4, 4, D_80050720->maxHp);
            Gfx_SetPartsNumber(obj, 8, 4, D_80050720->hp);
            Gfx_SetPartsNumber(obj, 0x10, 4, D_80050720->maxMp);
            Gfx_SetPartsNumber(obj, 0x20, 4, D_80050720->mp);
                break;
            case 1:
            case 3:
                k = 0;
                if (w->field_98 == 5) {
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
            Gfx_SetPartsScale(obj, 0x1000, w->field_9C);
            Gfx_DrawParts((s32)obj);
        }
        i++;
    } while (p[i] != 0);
}


void Item_BuildMenuList(MenuItemWork *w) {
    MenuItemCell *c = w->cells;
    MenuItemCell *q;
    MenuItemCell *p;
    s32 i;
    s32 id;

    if (w->menuMode >= 6) {
        goto party;
    }
    if (w->menuMode < 4) {
    party:
        i = 0;
        w->itemCount = Item_GetBagCapacity();
        p = w->cells;
        for (; i < w->itemCount;) {
            c->itemId = D_80050720->bagItems[i];
            p->count = 0;
            p->bagSlot = i++;
            p++;
            c++;
        }
        w->gridLayout.gridSize[0] = w->itemCount / 8;
        w->gridLayout.gridSize[1] = w->itemCount >= 9 ? 8 : w->itemCount;
    } else {
        w->itemCount = 0;
        q = w->cells;
        for (i = 1; i < 0x118; i++) {
            id = Item_GetIdAtIndex(i - 1);
            if (w->menuMode == 4) {
                if (func_8001E0C0(id) == 0x1F) {
                    continue;
                }
            } else if (func_8001E0C0(id) != 0x1F) {
                continue;
            }
            if (D_80050720->storageCounts[id] != 0) {
                c->itemId = id;
                q->count = D_80050720->storageCounts[id];
                q->count = q->count >= 100 ? 99 : q->count;
                q->count = w->menuMode == 5 ? 0 : q->count;
                q++;
                c++;
                w->itemCount++;
            }
        }
        w->gridLayout.gridSize[0] = w->itemCount / 8;
        w->gridLayout.gridSize[0] += (u16)w->itemCount % 8 != 0;
        w->gridLayout.gridSize[1] = w->itemCount >= 9 ? 8 : w->itemCount;
    }
    w->hasItems = w->itemCount != 0;
}


void Menu_DrawItemGrid(MenuItemWork *a0, s32 a1) {
    s32 n;
    s32 i;
    s32 base;
    s32 img;
    Halves h;
    TextDescHalves st;

    base = a0->scrollRow * 8;
    n = a0->itemCount - base;
    n = (n > 16) ? 16 : n;
    for (i = 0; i < 16; i++) {
        Text_Close(&a0->cellTextSlots[i]);
    }
    for (i = 0; i < n; i++) {
        h.lo = (i / 8) * 113 + 30;
        h.hi = (i % 8) * 12 + 71;
        if (a0->cells[base + i].itemId == 0) {
            img = (s32)Cd_GetFileEntry(0x1FD0098);
        } else {
            img = Item_GetNameText(a0->cells[base + i].itemId);
        }
        if (a0->cells[base + i].itemId != 0 && a0->cells[base + i].count != 0) {
            st.pos = h;
            st.packedStyle = a1;
            st.color = 0;
            st.text = (s32)Cd_GetFileEntry(0x1FD0125);
            st.strArg0 = img;
            st.strArg1 = a0->countText[i];
            Text_FormatNumber(a0->countText[i], a0->cells[base + i].count, -2);
            Text_OpenDesc(&a0->cellTextSlots[i], (TextDesc *)&st);
        } else {
            Text_OpenPacked(&a0->cellTextSlots[i], img, a1, h);
        }
    }
}

void Item_MoveToStorage(Actor *a0, MenuItemWork *w) {
    MenuItemCell *c;
    s32 id;
    s32 snd;
    TextDescHalves st;

    c = &w->cells[Menu_GridIndexColMajor(w->cursor, w->gridLayout.gridSize)];
    if (c->itemId == 0) {
        snd = 0x10;
    } else {
        id = c->itemId;
        D_80050720->storageCounts[id] += (D_80050720->storageCounts[id] + 1 < 100);
        Item_RemoveFromBag(c->bagSlot);
        st.pos = D_80050704;
        st.packedStyle = 0x81;
        st.color = 0;
        st.strArg0 = Item_GetNameText(id);
        st.text = (s32)Cd_GetFileEntry(0x1FD0122);
        Text_OpenDesc(&w->msgTextSlot, (TextDesc *)&st);
        Item_BuildMenuList(w);
        Menu_DrawItemGrid(w, 0);
        Task_SetState1(a0, 2);
        snd = 0xE;
    }
    Snd_PlayById(snd, 0);
}

void Item_TakeFromStorage(Actor *a0, MenuItemWork *w) {
    MenuItemCell *c;
    s32 n;
    s32 i;
    s32 t;
    s32 snd;
    TextDescHalves st;

    c = &w->cells[Menu_GridIndexColMajor(w->cursor, w->gridLayout.gridSize)];
    if (c->itemId == 0) {
        snd = 0x10;
    } else if (Menu_GridIndexColMajor(w->cursor, w->gridLayout.gridSize) >= w->itemCount) {
        snd = 0x10;
    } else {
        n = Item_GetBagCapacity();
        for (i = 0; i < n; i++) {
            if (D_80050720->bagItems[i] == 0) {
                break;
            }
        }
        if (i == n) {
            Text_OpenPacked(&w->msgTextSlot, (s32)Cd_GetFileEntry(0x1FD0124), 0x81, D_80050704);
            snd = 0x10;
        } else {
            D_80050720->bagItems[i] = c->itemId;
            D_80050720->storageCounts[c->itemId]--;
            st.pos = D_80050704;
            st.packedStyle = 0x81;
            st.color = 0;
            st.strArg0 = Item_GetNameText(c->itemId);
            st.text = (s32)Cd_GetFileEntry(0x1FD0123);
            Text_OpenDesc(&w->msgTextSlot, (TextDesc *)&st);
            Item_BuildMenuList(w);
            if (w->cursor[0] >= w->gridLayout.gridSize[0]) {
                w->cursor[0] = w->gridLayout.gridSize[0] - 1;
            }
            if (w->cursor[1] >= w->gridLayout.gridSize[1]) {
                w->cursor[1] = w->gridLayout.gridSize[1] - 1;
            }
            t = w->gridLayout.gridSize[0] - 2;
            if (t < 0) {
                t = 0;
            }
            w->scrollRow = (w->scrollRow < t) ? w->scrollRow : t;
            Menu_DrawItemGrid(w, 0);
            if (w->itemCount == 0) {
                Task_SetState1(a0, 6);
            } else {
                Task_SetState1(a0, 2);
            }
            snd = 0xE;
        }
    }
    Snd_PlayById(snd, 0);
}


void Menu_PickItemToUse(Actor *a0, MenuItemPickWork *o) {
    s16 *pos = o->cursor;
    s16 *size = o->gridSize;
    s32 id = o->cells[Menu_GridIndexColMajor(pos, size)].itemId;
    s32 r;
    Halves h;

    if (id != 0) {
        r = Item_GetUseKind(id);
        if (r != 0) {
            goto found;
        }
        h.lo = 0x10;
        h.hi = 0xBA;
        Text_OpenPacked(o->descText, Cd_GetFileEntry(0x1FD00A1), 0x81, h);
    }
    Snd_PlayById(0x10, 0);
    return;
found:
    Menu_Ctx->itemId = id;
    Menu_Ctx->bagSlot = o->cells[Menu_GridIndexColMajor(pos, size)].bagSlot;
    o->nextTaskIdx = r == 1;
    Snd_PlayById(0xE, 0);
    Task_NextState1(a0);
}

void Menu_ItemGridSelect(Actor *a0, GridMenu *m) {
    u16 v = m->cells[Menu_GridIndexColMajor(m->cursor, m->gridSize)].itemId;

    if (v == 0) {
        Snd_PlayById(0x10, 0);
    } else {
        Snd_PlayById(0xE, 0);
        Menu_Ctx->itemId = v;
        Menu_Ctx->bagSlot = Menu_GridIndexColMajor(m->cursor, m->gridSize);
        Task_SetState1(a0, 4);
    }
}

void Menu_ShowSelItemText(Actor *a0, MenuItemPickWork *o) {
    s32 idx;
    u16 id;

    idx = Menu_GridIndexColMajor(o->cursor, o->gridSize);
    Text_Close(&o->nameText);
    Text_Close((s32 *)o->descText);
    id = o->cells[idx].itemId;
    if (id != 0) {
        if (o->menuMode != 5) {
            Text_OpenPacked(&o->nameText, Item_GetNameText(id), 0, D_80050708);
        }
        Text_OpenPacked(o->descText, Item_GetDescText(id), 0x80, D_80050704);
    }
}

void func_800169D0(Actor *arg0, s16 arg1) {
    arg0->work->field_64 = arg1;
}

void Menu_ItemTask(Actor *a0) {
    MenuItemWork *w = (MenuItemWork *)a0->work;
    s32 *slot;
    s32 r;
    s32 id;
    TextDescHalves st;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->gridLayout = *(MenuGridLayout *)Cd_GetFileEntry(0x5130017);
        Item_SortList();
        w->scrollRow = 0;
        w->cursor[1] = 0;
        w->cursor[0] = 0;
        Item_BuildMenuList(w);
        Mem_FillWordsNeg1(w->cellTextSlots, 0x15);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->fade) != 0) {
                break;
            }
            Text_PrintIdList(&w->labelTexts, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130018, w->menuMode - 1), 2);
            Item_BuildMenuList(w);
            Menu_DrawItemGrid(w, 1);
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->menuMode) {
            default:
                Menu_ShowSelItemText(a0, (MenuItemPickWork *)w);
                break;
            case 5:
                if (w->itemCount == 0) {
                    id = 0x1FD0151;
                    goto msg;
                }
                Menu_ShowSelItemText(a0, (MenuItemPickWork *)w);
                Task_NextState1(a0);
                return;
            case 3:
            case 4:
                if (w->menuMode == 4) {
                    if (w->itemCount == 0) {
                        goto full;
                    }
                }
                Text_OpenPacked(&w->msgTextSlot, (s32)Cd_GetFileEntry(((s32)((u16)w->menuMode << 16) >> 16) + 0x1FD011D), 0x80, D_80050704);
                break;
            }
            Task_NextState1(a0);
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->gridLayout.gridSize) != 0) {
                Snd_PlayById(0xD, 0);
                if (w->cursor[0] - w->scrollRow >= 2) {
                    w->scrollRow = w->cursor[0] - 1;
                    Menu_DrawItemGrid(w, 0);
                } else if (w->cursor[0] < w->scrollRow) {
                    w->scrollRow = w->cursor[0];
                    Menu_DrawItemGrid(w, 0);
                }
                Task_SetState1(a0, 1);
            } else if (D_8005F6F0[0].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 2);
            } else if (D_8005F6F0[0].cross > 0) {
                switch (w->menuMode) {
                case 1:
                    Menu_PickItemToUse(a0, (MenuItemPickWork *)w);
                    break;
                case 2:
                    Menu_ItemGridSelect(a0, (GridMenu *)w);
                    break;
                case 3:
                    Item_MoveToStorage(a0, w);
                    break;
                case 4:
                    Item_TakeFromStorage(a0, w);
                    break;
                }
            }
            break;
        case 3:
            slot = (s32 *)a0->u34.children;
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(w->cellTextSlots, 0x15);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->fade) != 0) {
                    break;
                }
                Task_Create(D_80040EFC[w->nextTaskIdx].field_0, slot, D_80040EFC[w->nextTaskIdx].field_2);
                Task_NextState2(a0);
                break;
            case 2:
                if (*slot == 0) {
                    Task_SetState1(a0, 0);
                }
                break;
            }
            break;
        case 4:
            st.pos.lo = 0x10;
            st.pos.hi = 0xBA;
            st.packedStyle = 0x81;
            st.color = 0;
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
            switch (a0->stateLevel2) {
            case 0:
            default:
                st.text = (s32)Cd_GetFileEntry(0x1FD00B9);
                Text_OpenDesc(&w->descText, (TextDesc *)&st);
                Task_NextState2(a0);
                break;
            case 1:
                r = func_800136A4(w->descText);
                switch (r) {
                case 1:
                    Item_RemoveFromBag(Menu_Ctx->bagSlot);
                    st.text = (s32)Cd_GetFileEntry(0x1FD00BA);
                    Text_OpenDesc(&w->descText, (TextDesc *)&st);
                    Item_BuildMenuList(w);
                    Menu_DrawItemGrid(w, 0);
                    Task_SetState1(a0, 2);
                    break;
                case -1:
                    Task_SetState1(a0, 1);
                    break;
                }
                break;
            }
            break;
        case 5:
            switch (a0->stateLevel2) {
            case 0:
                if (Text_IsFinished(w->msgTextSlot) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].triangle > 0 || D_8005F6F0[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 6:
            if (Text_IsFinished(w->msgTextSlot) == 0) {
                break;
            }
        full:
            id = 0x1FD0127;
        msg:
            Text_OpenPacked(&w->msgTextSlot, (s32)Cd_GetFileEntry(id), 0x81, D_80050704);
            Task_SetState1(a0, 5);
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Item_SortList();
            Text_CloseArray(w->cellTextSlots, 0x15);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->fade) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


#ifdef NORMALIZED
void Menu_ItemDraw(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 k;
    s32 f;
    u16 m;
    Pair54 tmp;

    if (w->field_68 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130019);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
loop:
        obj = Cd_GetFileEntry(*list);
        switch (i) {
        case 0:
            tmp = w->field_54;
            f = w->field_54.field_0 + 1;
            Gfx_SetPartsNumber(obj, 0x10, 2, f ? f : 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->field_58 ? w->field_58 : 1);
            tmp.field_0 = w->field_54.field_0 - w->field_6E;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->field_58);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            f = Menu_BlinkOrHideParts(obj, 8, w->field_6E);
            f |= Menu_BlinkOrHideParts(obj, 4, w->field_58 - w->field_6E - 2);
            if (w->field_70 == 0) {
                f |= 0xE;
            }
            Gfx_HidePartsByMask(obj, f);
            break;
        case 1:
            if (w->field_64 < 3) {
                m = 2;
            } else {
                m = 0xFFFF;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        case 3:
            m = 0xFFFF;
            if (w->field_64 == 3 || w->field_64 == 5) {
                m = 1;
            } else if (w->field_64 == 4) {
                m = 2;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->field_68);
        list++;
        Gfx_DrawParts((s32)obj);
        i++;
    if (*list != 0) goto loop;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Menu_ItemDraw);
void Menu_ItemDraw(Actor *actor);
#endif


#ifdef NORMALIZED
void func_80017214(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e;
    DigiRosterSwapRec *g;
    MenuDigiPickRow *d;
    DigiRosterSwapRec tmp;
    u8 k;
    s32 id;
    s32 n;
    MenuCtx *p;

    e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    p = Menu_Ctx;
    do {} while (0);
    n = D_8005F6F0[0].cross;
    g = (DigiRosterSwapRec *)p->field_128;
    if (n > 0) {
        switch (e->kind) {
        case 0:
        default:
            if (g->state >= 3) {
                id = 0x1FD0111;
            icon:
                Text_OpenPacked(w->field_40, Cd_GetFileEntry(id), 0x81, D_8005070C);
                break;
            }
            g->state = w->pickedIndices[3] != 0 ? 1 : 2;
            d = &w->rows[w->cursor[1]];
            d->kind = 1;
            d->record = (s32)g;
            d->pickState = g->state;
            id = 0x1FD0110;
            goto swap;
        case 1:
            k = g->state;
            tmp = *(DigiRosterSwapRec *)e->record;
            g->state = tmp.state;
            tmp.state = k;
            *(DigiRosterSwapRec *)e->record = *g;
            *g = tmp;
            id = 0x1FD0112;
        swap:
            Text_OpenPacked(w->field_40, Cd_GetFileEntry(id), 0x81, D_8005070C);
            Menu_Ctx->field_126 = -1;
            Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
            Snd_PlayById(0xE, 0);
            Task_SetState1(a0, 4);
            return;
        case 3:
            if (g->state >= 3) {
                id = 0x1FD011E;
                goto icon;
            }
            Text_OpenPacked(w->field_40, Cd_GetFileEntry(0x1FD011F), 0x81, D_8005070C);
            Task_SetState1(a0, 5);
            return;
        case 2:
            break;
        }
        Snd_PlayById(0x10, 0);
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80017214);
void func_80017214(Actor *a0);
#endif

void func_800174F8(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    s32 k;

    if (D_8005F6F0[0].cross > 0) {
        k = 0x10;
        if (e->kind == 1) {
            Menu_Ctx->field_128 = e->record;
            Menu_Ctx->field_126 = 0;
            w->field_62 = 3;
            Task_SetState1(a0, 3);
            k = 0xE;
        }
        Snd_PlayById(k, 0);
    }
}

#ifdef NORMALIZED
void Menu_ConfirmMultiPick(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    s32 k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
    MenuDigiPickRow *e = &w->rows[k];
    s32 i;

    if (D_8005F6F0[0].cross > 0) {
        if (e->pickState != 2) {
            Snd_PlayById(0x10, 0);
            return;
        }
        e->pickState = w->pickedCount + 3;
        w->pickedIndices[w->pickedCount++] = k;
        Snd_PlayById(0xE, 0);
        if (w->pickedCount < w->pickMax) {
            Task_SetState1(a0, 1);
        } else {
            MenuCtx *d;
            Menu_Ctx->pickCount = w->pickMax;
            d = Menu_Ctx;
            i = 0;
            if (w->pickMax > 0) {
                do {
                    d->pickedRecords[i] = w->rows[w->pickedIndices[i]].record;
                } while (++i < w->pickMax);
            }
            w->field_62 = 2;
            Task_SetState1(a0, 3);
        }
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Menu_ConfirmMultiPick);
void Menu_ConfirmMultiPick(Actor *a0);
#endif

void Menu_UndoLastPick(Actor *s0) {
    MenuPickWork *w = (MenuPickWork *)s0->work;
    s16 c = w->pickCount;
    if (c == 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(s0, 2);
    } else {
        s16 idx = (u16)c - 1;
        s16 v;
        w->pickCount = idx;
        v = w->picks[idx];
        ((WorkElem8 *)((u8 *)w + 0x6C))[v].field_2 = 2;
        w->picks[w->pickCount] = 0;
        Snd_PlayById(0xB, 0);
        Task_SetState1(s0, 1);
    }
}

void Menu_UseItemOnDigi(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    TextDescHalves st;

    if (D_8005F6F0[0].cross > 0) {
        if (e->kind == 1 && Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, e->record) != 0) {
            st.pos = D_8005070C;
            st.color = 0;
            st.packedStyle = 0x81;
            st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
            Text_OpenDesc(w->field_40, (TextDesc *)&st);
            Snd_PlayById(0x1D, 0);
            Task_SetState1(a0, 4);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}

void Menu_PickUseItemDirect(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    TextDescHalves st;

    st.pos = D_8005070C;
    st.color = 0;
    st.packedStyle = 0x81;
    if (Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, 0) != 0) {
        st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
        st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
        Snd_PlayById(0x1D, 0);
    } else {
        st.text = (s32)Cd_GetFileEntry(0x1FD00A0);
        st.strArg0 = 0;
    }
    Text_OpenDesc(w->field_40, (TextDesc *)&st);
}

void Menu_ConfirmSinglePick(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    s32 k;
    s32 c;

    if (D_8005F6F0[0].cross > 0) {
        k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
        if ((c = w->rows[k].kind) == 1) {
            Menu_Ctx->selRecord = (u8 *)w->rows[k].record;
            w->field_62 = 0;
            Task_SetState1(a0, 3);
            Menu_Ctx->pickResult = c;
            Snd_PlayById(0xE, 0);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}


#ifdef NORMALIZED
void Menu_BuildDigiList(MenuDigiListBuildWork *w) {
    MenuDigiListBuildRow *r = w->rows;
    DigiRosterEntry *el = D_80050720->elems;
    s32 n = 0;
    s32 i;
    s32 ok;
    MenuDigiListBuildRow *t;

    t = r;
    for (i = 0; i < 0x26; i++) {
        t->field_2 = 0;
        t->kind = 0;
        t++;
    }
    w->gridCols = 1;
    switch (w->mode) {
    default:
        w->rowCount = func_80022578();
        break;
    case 2:
        w->rowCount = 0x18;
        break;
    case 7:
    case 8:
        if (w->parity == 0) {
            w->rowCount = func_80022578();
        } else {
            w->rowCount = 0x18;
        }
        if (w->mode == 8) {
            w->rowCount++;
            n++;
            r->kind = 3;
            r->entry = 0;
            r->field_2 = 0;
            r++;
            w->cursorRow++;
        }
        break;
    case 6:
        w->rowCount = Menu_Ctx->pickCount;
        for (i = 0; i < Menu_Ctx->pickCount; i++) {
            r->kind = 1;
            r->entry = Menu_Ctx->pickedRecords[i];
            r->field_2 = i + 3;
            r++;
        }
        return;
    }
    for (i = 0; i < 0x24; i++, el++) {
        if (el->state != 0) {
            ok = 0;
            switch (w->mode) {
            default:
                if (el->state >= 2) ok = -1;
                break;
            case 5:
                if (el->state >= 2 && (s16)el->hp != 0) ok = -1;
                break;
            case 7:
            case 8:
                if (w->parity != 0) {
                    if (el->state == 1) ok = -1;
                } else {
                    if (el->state >= 2) ok = -1;
                }
                break;
            case 2:
                if (el->state == 1) ok = -1;
                break;
            }
            if (ok) {
                r->kind = 1;
                r->entry = el;
                r->field_2 = (w->mode == 5) ? 2 : el->state;
                r++;
                n++;
            }
        }
    }
    if (Menu_Ctx->flags & 1) {
        if (w->mode != 2 && w->mode != 5) {
            r = &w->rows[w->rowCount - 1];
            for (i = 0; i < D_8005071C->field_BA8; i++, r--) {
                r->kind = 2;
                r->field_1 = D_8005071C->field_BA9[i];
            }
        }
    }
    if (w->mode == 5) {
        w->rowCount = n;
        if (n < 4) {
            w->pickMax = n;
        } else {
            w->pickMax = 3;
        }
        w->pickCount = 0;
        w->pick2 = 0;
        w->pick1 = 0;
        w->pick0 = 0;
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Menu_BuildDigiList);
void Menu_BuildDigiList(MenuDigiListBuildWork *w);
#endif


void Menu_DigiListDrawRows(MenuDigiListRowsView *a0, s32 a1) {
    s32 i;
    MenuDigiListRow *rec;
    TextDesc st;

    st.strArg0 = 0;
    st.packedStyle = a1;
    st.color = 0;
    for (i = 0; i < 16; i++) {
        Text_Close(&a0->textBoxes[i]);
    }
    rec = &a0->entries[a0->scrollTop];
    for (i = 0; i < 4; i++) {
        switch (rec->kind) {
        case 0:
            break;
        case 1:
            st.x = 109;
            st.y = i * 33 + 62;
            st.text = (s32)Cd_GetFileEntry(0x1FD0082);
            Text_OpenDesc(&a0->textBoxes[i * 4], &st);
            st.x = 208;
            st.y = i * 33 + 62;
            st.text = (s32)Cd_GetFileEntry(0x1FD00BB);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 1], &st);
            st.x = 109;
            st.y = i * 33 + 50;
            st.text = (s32)rec->digi->name;
            Text_OpenDesc(&a0->textBoxes[i * 4 + 2], &st);
            st.x = 208;
            st.y = i * 33 + 50;
            st.text = (s32)Digi_GetDefaultName(rec->digi->digiId);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 3], &st);
            break;
        case 2:
            st.x = 109;
            st.y = i * 33 + 50;
            st.text = (s32)Cd_GetFileEntry(rec->field_1 + 0x1FD00F5);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 2], &st);
            break;
        case 3:
            st.x = 109;
            st.y = i * 33 + 50;
            st.text = (s32)Cd_GetFileEntry(0x1FD0114);
            Text_OpenDesc(&a0->textBoxes[i * 4 + 2], &st);
            break;
        }
        rec++;
    }
}

void Menu_SetDigiListMode(Actor *a, s16 mode) {
    MenuDigiListModeWork *w = (MenuDigiListModeWork *)a->work;

    w->mode = mode;
    if (mode == 3 && ((ItemEffect *)Item_GetEffectRec(Menu_Ctx->itemId))->useType == 2) {
        w->mode = 4;
    }
    w->flag6A = 1;
    switch (w->mode) {
    default:
        w->flag6A = 1;
        break;
    case 4:
    case 6:
        w->flag6A = 0;
        break;
    case 7:
    case 8:
        { s16 t = Menu_Ctx->field_124 - 7; w->parity = (w->mode + t) & 1; }
        break;
    }
}

#ifdef NORMALIZED
void Menu_DigiListTask(Actor *a0) {
    MenuDigiListWork *w = (MenuDigiListWork *)a0->work;
    s32 *slot;
    s32 r;
    s32 i;
    s32 id;
    u8 *p;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->grid = D_80040F1C;
        w->scrollTop = 0;
        w->cursor[1] = 0;
        w->cursor[0] = 0;
        Menu_BuildDigiList((MenuDigiListBuildWork *)w);
        Mem_FillWordsNeg1(w->texts, 0x14);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->scale) != 0) {
                break;
            }
            Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 1);
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->mode) {
            default:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD00D3), 0x80, D_8005070C);
                Task_NextState1(a0);
                break;
            case 3:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD009E), 0x80, D_8005070C);
                Task_NextState1(a0);
                break;
            case 4:
                Menu_PickUseItemDirect(a0);
                Task_SetState1(a0, 4);
                break;
            case 5:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(w->pickCount + 0x1FD0109), 0x80, D_8005070C);
                Task_NextState1(a0);
                break;
            case 6:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD010C), 0x80, D_8005070C);
                Task_SetState1(a0, 5);
                break;
            case 7:
            case 8:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(w->mode + 0x1FD0107), 0x80, D_8005070C);
                id = 0x1FD0072;
                if (w->parity != 0) {
                    id = 0x1FD009A;
                }
                Text_OpenPacked(&w->field_44, (s32)Cd_GetFileEntry(id), 0, D_80040F38[w->parity]);
                Task_NextState1(a0);
                break;
            }
            if (w->showCursor != 0) {
                Text_OpenPacked(&w->field_48, (s32)Cd_GetFileEntry(0x1FD00FA), 0, D_80050710);
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->grid.gridSize) == 0) {
                if (D_8005F6F0[0].triangle > 0) {
                    if (w->mode != 5) {
                        Snd_PlayById(0xB, 0);
                        Task_SetState0(a0, 2);
                    } else {
                        Menu_UndoLastPick(a0);
                    }
                } else {
                    switch (w->mode) {
                    case 1:
                    case 2:
                        Menu_ConfirmSinglePick(a0);
                        break;
                    case 3:
                        Menu_UseItemOnDigi(a0);
                        break;
                    case 5:
                        Menu_ConfirmMultiPick(a0);
                        break;
                    case 7:
                        func_800174F8(a0);
                        break;
                    case 8:
                        func_80017214(a0);
                        break;
                    }
                }
            } else {
                Snd_PlayById(0xD, 0);
                if (w->cursor[1] - w->scrollTop >= 4) {
                    w->scrollTop = w->cursor[1] - 3;
                    Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
                } else if (w->cursor[1] < w->scrollTop) {
                    w->scrollTop = w->cursor[1];
                    Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
                }
                Task_SetState1(a0, 1);
            }
            break;
        case 3:
            slot = (s32 *)a0->u34.children;
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(w->texts, 0x14);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->scale) != 0) {
                    break;
                }
                Task_NextState2(a0);
                break;
            case 2:
                Task_Create(D_80040F28[w->field_62].field_0, slot, D_80040F28[w->field_62].field_2);
                Task_NextState2(a0);
                break;
            case 3:
                if (*slot != 0) {
                    break;
                }
                switch (w->mode) {
                case 1:
                case 2:
                    if (Menu_Ctx->confirmed == 0) {
                        Task_SetState1(a0, 0);
                        Menu_Ctx->pickResult = 2;
                    } else {
                        w->field_62 ^= 1;
                        Task_SetState2(a0, 2);
                    }
                    break;
                case 5:
                    if (Menu_Ctx->pickConfirmed != 0) {
                        Digi_SortRoster();
                        Task_SetState0(a0, 2);
                        break;
                    }
                    Menu_UndoLastPick(a0);
                    Task_SetState1(a0, 0);
                    break;
                case 7:
                    if (Menu_Ctx->field_126 != 0) {
                        Digi_SortRoster();
                        Task_SetState0(a0, 0);
                        break;
                    }
                default:
                    Task_SetState1(a0, 0);
                    break;
                }
                break;
            }
            break;
        case 4:
            switch (a0->stateLevel2) {
            case 0:
                if (Text_IsFinished(w->promptText) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].triangle > 0 || D_8005F6F0[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 5:
            r = func_800136A4(w->promptText);
            if (r == 0) {
                break;
            }
            switch (w->mode) {
            case 6:
            default:
                if (r == 1) {
                    Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD010D), 0x81, D_8005070C);
                    for (i = 0; i < 0x24; i++) {
                        if (D_80050720->elems[i].state >= 3) {
                            D_80050720->elems[i].state = 2;
                        }
                    }
                    for (i = 0; i < Menu_Ctx->pickCount; i++) {
                        *Menu_Ctx->pickedRecords[i] = i + 3;
                    }
                    Menu_Ctx->pickConfirmed = -1;
                    Task_SetState1(a0, 4);
                } else {
                    Menu_Ctx->pickConfirmed = 0;
                    Task_SetState0(a0, 2);
                }
                break;
            case 8:
                if (r == 1) {
                    p = (u8 *)Menu_Ctx->field_128;
                    Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD0113), 0x81, D_8005070C);
                    *p = 0;
                    Menu_Ctx->field_126 = -1;
                    Snd_PlayById(0xE, 0);
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 1);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 0x14);
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
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Menu_DigiListTask);
void Menu_DigiListTask(Actor *a0);
#endif


void func_800188BC(Actor *actor) {
    MenuDigiListDrawView *w = (MenuDigiListDrawView *)actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 j;
    s32 f;
    u16 m;
    MenuDigiListDrawRow *r;
    DigiRosterListView *e;
    Pair54 tmp;

    if (w->scale == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x513001B);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            if (w->showCursor != 0) {
            tmp = w->cursor;
            tmp.field_2 = w->cursor.field_2 - w->scrollTop;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->gridCols);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            {
                s32 fl = (w->scrollTop < 1) << 2;
                if (w->rowCount - w->scrollTop - 4 <= 0) {
                    fl |= 8;
                }
                Gfx_HidePartsByMask(obj, fl);
            }
            Gfx_SetPartsNumber(obj, 0x10, 2, w->cursor.field_2 + 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->rowCount);
            } else {
                Gfx_HidePartsByMask(obj, -1);
            }
            break;
        default:
            r = &w->rows[w->scrollTop + (i - 1)];
            j = i - 1;
            if (j >= w->rowCount) {
                Gfx_HidePartsByMask(obj, -1);
                break;
            }
            Gfx_HidePartsByMask(obj, 0);
            f = 2;
            if (w->showCursor != 0 && j == w->cursor.field_2 - w->scrollTop) {
                f = 1;
            }
            switch (r->kind) {
            case 0:
                Gfx_HidePartsByMask(obj, f | 0xFE4);
                break;
            case 1:
                e = (DigiRosterListView *)r->digi;
                Gfx_HidePartsByMask(obj, f | D_80040F40[r->field_2 - 1]);
                Gfx_SetPartsNumber(obj, 0x20, 3, e->maxHp);
                Gfx_SetPartsNumber(obj, 0x40, 3, e->hp);
                Gfx_SetPartsNumber(obj, 0x80, 3, e->maxMp);
                Gfx_SetPartsNumber(obj, 0x100, 3, e->mp);
                break;
            case 2:
            case 3:
                Gfx_HidePartsByMask(obj, -5);
                break;
            }
            break;
        case 5:
            break;
        case 6:
            m = 0xFFFF;
            if (w->mode == 7 || w->mode == 8) {
                m = 1;
                if (w->parity != 0) {
                    m = 2;
                }
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->scale);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void Menu_DigiStatusInit(Actor *a0, s16 a1) {
    MenuDigiStatusInitWork *w;
    u8 *p;
    s32 i;
    Blk16 *b;
    s32 *q;

    w = (MenuDigiStatusInitWork *)a0->work;
    w->field_7C = a1;
    p = Menu_Ctx->selRecord;
    w->digimon = p;
    a0->digiId = p[1];
    Actor_InitTransform((ContC40 *)a0, w->pos, w->initRotY);
    w->modelFile = Digi_GetModelFile(a0->digiId);
    w->animFile = Anim_GetModelAnimFile(a0->digiId, 0);
    Gfx_AttachModel(a0, w->modelFile)->otIndex = 3;
    Cd_QueueFile(w->modelFile);
    Cd_QueueFile(w->animFile);
    w->modelPhase = 0;
    w->modelScale = 0;
    w->view = D_80040F64;
    GsInitCoordinate2(0, (Coord1F668 *)&w->coord);
    w->field_148 = 1;
    w->rotSpeedY = 11;
    w->rotSpeedX = 0;
    w->rotSpeedZ = 0;
    w->rotX = -0xE3;
    b = (Blk16 *)Cd_GetFileEntry(0x513001F);
    q = (s32 *)Cd_GetFileEntry(0x5130020);
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &b[i]);
    }
    GsSetAmbient(q[0], q[1], q[2]);
    GsSetLightMode(0);
}


void Menu_DigiStatusTask(Actor *a) {
    MenuDigiStatusWork *w = (MenuDigiStatusWork *)a->work;
    Halves *h;
    MenuDigiStatusEntry *r;
    u8 **q;
    s32 i;
    Actor *t[1];
    s16 *p;
    s16 *s;
    PadState *d;

    switch (a->stateLevel0) {
    default:
    case 0:
        w->blk = *(MenuDigiStatusLayout *)Cd_GetFileEntry(0x513001C);
        Mem_FillWordsNeg1(w, 0x1B);
        GsSetOffset(-0xA0, 0xB4);
        t[0] = a;
        Task_Create(6, (s32 *)a->u34.children, (s32)t);
        a->childCount = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        default:
        case 0:
            h = (Halves *)Cd_GetFileEntry(0x513001E);
            (*(Actor **)a->u34.children)->model->otIndex = 4;
            if (Math_RampToOne((s32)a, &w->ramp) != 0) {
                break;
            }
            Text_PrintIdList((s32 *)w, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x513001D, 0), 1);
            r = w->digimon;
            Text_OpenPacked(&w->nameText, (s32)r->name, 0x81, h[0]);
            w->speciesName = Digi_GetDefaultName(r->speciesId);
            w->field_8C = Cd_GetFileEntry(((s32 (*)(s32))func_8001D934)(r->speciesId) + 0x1FD00C3);
            w->field_90 = Cd_GetFileEntry(((s32 (*)(s32))func_8001D958)(r->speciesId) + 0x1FD00C6);
            w->field_94 = Cd_GetFileEntry(((s32 (*)(s32))func_8001D980)(r->speciesId) + 0x1FD00CA);
            q = w->field_98;
            for (i = 0; i < 2; i++) {
                if (r->field_47[i] != 0) {
                    *q++ = Digi_GetDefaultName(r->field_47[i]);
                }
            }
            *q = 0;
            Text_PrintList(&w->infoTexts, &h[1], (s32 *)&w->speciesName, 1);
            Task_NextState1(a);
            break;
        case 1:
            w->modelPhase = 1;
            GsSetOffset(-0xA0, w->rot[0] * 80 / 682 + 180);
            Task_NextState1(a);
            break;
        case 2:
            Math_RampToOne((s32)a, &w->modelScale);
            p = w->rot;
            s = w->rotSpeed;
            a->childCount = 1;
            p[1] += s[1];
            if (D_8005F6F0[0].left != 0) {
                s[1] = (s[1] - 5 < -0x22) ? -0x22 : s[1] - 5;
            }
            if (D_8005F6F0[0].right != 0) {
                s[1] = (s[1] + 5 >= 0x23) ? 0x22 : s[1] + 5;
            }
            if (D_8005F6F0[0].down != 0) {
                p[0] = (p[0] + 0xB > 0) ? 0 : p[0] + 0xB;
            }
            if (D_8005F6F0[0].up != 0) {
                p[0] = (p[0] - 0xB < -0x2AA) ? -0x2AA : p[0] - 0xB;
            }
            GsSetOffset(-0xA0, p[0] * 80 / 682 + 180);
            d = D_8005F6F0;
            if (d->triangle > 0 || d->circle > 0) {
                Task_SetState0(a, 2);
                if (d->circle > 0) {
                    Menu_Ctx->confirmed = -1;
                    Snd_PlayById(0xE, 0);
                } else {
                    Menu_Ctx->confirmed = 0;
                    Snd_PlayById(0xB, 0);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        default:
        case 0:
            Text_CloseArray(w, 0x1B);
            Task_NextState1(a);
            break;
        case 1:
            Math_RampToZero((s32)a, &w->modelScale);
            if (Math_RampToZero((s32)a, &w->ramp) == 0) {
                GsSetOffset(0, 0);
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}

extern s32 GsSetRefView2(Ctx19214 *);

void Menu_DigiStatusDraw(Actor *actor) {
    Wk19214 *work;
    Rec19214 *rec;
    s32 *list;
    s32 *p;
    void *obj;
    Nd19214 *node;
    Ctx19214 ls;

    work = (Wk19214 *)actor->work;
    if (work->field_80 == 0) {
        goto Ltail;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130021);
    rec = (Rec19214 *)work->field_84;
    if (*p == 0) {
        goto Ltail;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        list++;
        Gfx_SetPartsNumber(obj, 0x2, 3, rec->field_14);
        Gfx_SetPartsNumber(obj, 0x4, 3, rec->field_16);
        Gfx_SetPartsNumber(obj, 0x8, 3, rec->field_18);
        Gfx_SetPartsNumber(obj, 0x10, 3, rec->field_1A);
        Gfx_SetPartsNumber(obj, 0x20, 2, rec->field_D);
        Gfx_SetPartsNumber(obj, 0x40, 3, rec->field_1C);
        Gfx_SetPartsNumber(obj, 0x80, 3, rec->field_1E);
        Gfx_SetPartsNumber(obj, 0x100, 3, rec->field_20);
        Gfx_SetPartsNumber(obj, 0x200, 8, rec->field_10);
        Gfx_SetPartsNumber(obj, 0x400, 8, Digi_GetExpToNextLevel(rec->field_D, rec->field_F, rec->field_10));
        Gfx_SetPartsScale((GfxPartScaleView *)obj, 0x1000, work->field_80);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);

Ltail:
    work->field_148 = 0;
    RotMatrixYXZ(&work->field_138, &work->field_EC);
    work->field_100 = work->field_B0;
    work->field_104 = work->field_B4;
    work->field_108 = work->field_B8;
    work->field_E8 = 0;
    ls.field_0 = work->field_CC;
    ls.field_4 = work->field_D0;
    ls.field_8 = work->field_D4;
    ls.field_C = work->field_D8;
    ls.field_10 = work->field_DC;
    ls.field_14 = work->field_E0;
    ls.field_18 = 0;
    ls.field_1C = &work->field_E8;
    GsSetProjection(work->field_E4);
    GsSetRefView2(&ls);
    if (work->field_C8 == 0) {
        return;
    }
    if (work->field_14C == 0) {
        return;
    }
    if (work->field_C8 == 1) {
        Anim_SetModelAnim(actor, 0);
        work->field_C8 = work->field_C8 + 1;
    }
    node = (Nd19214 *)actor->u38.ptr38;
    node->field_58 = work->field_14C;
    node->field_5C = work->field_14C;
    node->field_60 = work->field_14C;
    Gfx_AttachModel(actor, work->field_C0);
    Anim_StepModelAnim(actor);
    Actor_UpdateTransform(actor);
    Gfx_CalcModelBoneMatrices(actor);
    Gfx_DrawTexModel(actor, 0);
}

void func_800194C8(a)
Actor194C8 *a;
{
    u8 *tbl;
    s32 i;
    s32 r, c;
    u8 *q;
    void *base;

    tbl = a->selRecord;

    for (i = 3; i >= 0; i--) {
        a->records[i].count = 0;
    }

    for (i = 0; i < 0xC; i++) {
        q = tbl + i;
        if (q[0x22] == 0) continue;
        r = func_8001EE34(q[0x22]);
        c = a->records[r].count;
        a->records[r].arr[c] = q[0x22];
        a->records[r].count = (u16)a->records[r].count + 1;
    }

    for (i = 0; i < 4; i++) {
        base = Cd_GetFileEntry(0x5130022);
        a->block64[i] = *(Blk12 *)((u8 *)base + i * 0xC);
        a->scrollTop[i] = 0;
        a->slot54[i].v = 0;
        *(s16 *)((u8 *)&a->block64[i] + 2) = a->records[i].count;
    }
}

#ifdef NORMALIZED
void func_80019614(Actor194C8 *w, s32 arg1) {
    TextDescHalves st;
    s32 i;
    s32 ch;
    s32 n;
    s32 j;
    s32 k;
    s32 d0;
    s32 d;
    s32 f;
    s32 m;

    for (i = 6; i < 18; i++) {
        Text_Close(&w->textBoxes[i]);
    }
    st.strArg0 = 0;
    st.packedStyle = arg1;
    for (ch = 0; ch < 4; ch++) {
        st.pos = ((Halves *)Cd_GetFileEntry(0x5130025))[ch];
        d0 = w->scrollTop[ch];
        d = w->records[ch].count - d0;
        n = 3;
        if (d < 4) {
            n = d;
        }
        for (j = 0; j < n; j++) {
            f = 0;
            if (w->curTab != ch) {
                f = 1;
            } else if (w->slot54[ch].row != j + d0) {
                f = 1;
            }
            st.color = f;
            st.text = func_8001ED84(w->records[ch].arr[j + d0]);
            m = j + 6;
            Text_OpenDesc(&w->textBoxes[ch * 3 + m], (TextDesc *)&st);
            st.pos.hi += 11;
        }
        Text_SetColor(w->textBoxes[ch + 2], w->curTab != ch);
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80019614);
void func_80019614(Actor194C8 *w, s32 arg1);
#endif


void func_800197FC(Actor *arg0, s16 arg1) {
    arg0->work->field_A4 = arg1;
}

void func_80019808(Actor *a0) {
    Actor194C8 *w = (Actor194C8 *)a0->work;
    Halves h;
    TextDescHalves st;
    s32 i;
    s32 k;
    s32 id;
    s32 t;
    s32 j;
    s32 n;

    switch (a0->stateLevel0) {
    case 0:
    default:
        w->selRecord = Menu_Ctx->selRecord;
        func_800194C8(w);
        w->curTab = 0;
        Mem_FillWordsNeg1(&w->textBoxes, 0x15);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->fadeRamp) != 0) {
                break;
            }
            Text_PrintIdList(&w->textBoxes, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0x5130024, 0), 1);
            func_80019614(w, 1);
            h.lo = 0x13;
            h.hi = 0x32;
            Text_OpenPacked(&w->nameText, (s32)&w->selRecord[0x4C], 1, h);
            Task_NextState1(a0);
            break;
        case 1:
            i = w->curTab;
            k = Menu_GridIndexColMajor(&w->slot54[i].v, (s16 *)w->block64[i].data);
            Text_Close(&w->descText);
            Text_Close(&w->numberText);
            if (k < w->records[i].count) {
                id = w->records[i].arr[w->slot54[i].row];
                st.pos = D_80050714;
                st.packedStyle = 0x80;
                st.color = 0;
                st.text = func_8001EDD4(id);
                Text_OpenDesc(&w->descText, (TextDesc *)&st);
                st.pos.hi = 0xCA;
                st.text = (s32)Cd_GetFileEntry(0x1FD0150);
                Text_FormatNumber(w->numBuf, func_8001EE80(id), -4);
                st.strArg0 = (s32)w->numBuf;
                Text_OpenDesc(&w->numberText, (TextDesc *)&st);
            }
            Task_NextState1(a0);
            break;
        case 2:
            t = D_8005F6F0[0].left;
            if (t > 0 || D_8005F6F0[0].right > 0) {
                n = w->curTab;
                if (t > 0) {
                    n--;
                } else {
                    n++;
                }
                w->curTab = n & 3;
                Snd_PlayById(0xD, 0);
                func_80019614(w, 0);
                Task_SetState1(a0, 1);
            } else {
                j = w->curTab;
                if (Menu_MoveGridCursorP1((s32)&w->slot54[j], (s32)&w->block64[j]) != 0) {
                    Menu_ScrollToShow(&w->scrollTop[j], w->slot54[j].row, 3);
                    func_80019614(w, 0);
                    Snd_PlayById(0xD, 0);
                    Task_SetState1(a0, 1);
                } else if (D_8005F6F0[0].triangle > 0 || D_8005F6F0[0].circle > 0) {
                    Task_SetState0(a0, 2);
                    if (D_8005F6F0[0].circle > 0) {
                        Menu_Ctx->confirmed = -1;
                        Snd_PlayById(0xE, 0);
                    } else {
                        Menu_Ctx->confirmed = 0;
                        Snd_PlayById(0xB, 0);
                    }
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->textBoxes, 0x15);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->fadeRamp) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80019BF4(Actor *actor) {
    Wk19BF4 *w = (Wk19BF4 *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u16 v;
    Pair54 tmp;

    if (w->ramp == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130026);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            k = w->activePane;
            v = D_80040F98[k];
            if (w->field_AC[k].field_0 != 0) {
                tmp = w->cursors[k];
                tmp.field_2 = w->cursors[k].field_2 - w->scroll[k];
                Menu_SetPartsGridPos(obj, 0x4000, (s32 *)&tmp, &w->grids[k].field_0);
                Gfx_SetPartsPalette(obj, 0x4000, (actor->elapsed >> 2) & 3);
            } else {
                v |= 0x4000;
            }
            Gfx_HidePartsByMask(obj, v);
            break;
        case 1:
            m = 0xFFFFF;
            for (j = 0; j < 4; j++) {
                if (w->scroll[j] != 0) {
                    if (w->activePane == j) {
                        m -= 1 << (j * 4 + 1);
                    } else {
                        m -= 1 << (j * 4 + 2);
                    }
                }
                if (w->grids[j].rows - w->scroll[j] >= 4) {
                    if (w->activePane == j) {
                        m -= 1 << (j * 4 + 3);
                    } else {
                        m -= 1 << (j * 4 + 4);
                    }
                }
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->ramp);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void func_80019E40(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void Task_SpawnListFromFile(Actor *a0) {
    TaskSpawnEntry *p;
    s32 *slot;
    s32 end = -1;
    s32 *s;

    if (a0->stateLevel0 != 0) {
        return;
    }
    s = (s32 *)a0->u34.children;
    p = (TaskSpawnEntry *)Cd_GetFileOrNull(a0->work->field_0);
    slot = s;
loop:
    if (p->taskId == end) {
        goto done;
    }
    Task_Create(p->taskId, slot, (s32)&p->args);
    slot++;
    p = (TaskSpawnEntry *)((u8 *)p + p->size);
    goto loop;
done:
    Task_NextState0(a0);
}


void func_80019EE0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_80019EE8(Actor *a0) {
    s32 v1 = a0->stateLevel0;
    u16 *a1 = (u16 *)&a0->work->field_0;
    switch (v1) {
    case 1:
        if (a0->stateLevel1 == 0 || a0->stateLevel1 != v1) {
            u16 nv = *a1 + 0x555;
            *a1 = nv;
            if ((s16)nv >= 0x1000) {
                *a1 = 0x1000;
                Task_NextState1(a0);
            }
        }
        break;
    case 0:
        Task_NextState0(a0);
        break;
    case 2: {
        s16 nv = *a1 - 0x555;
        *a1 = nv;
        if (nv <= 0) {
            *a1 = 0;
            Task_NextState0(a0);
        }
        break;
    }
    }
}

void func_80019FB4(Actor *arg0) {
    ActorWork *w = arg0->work;
    void *e = Cd_GetFileEntry(D_80040FD0[arg0->field_8]);
    Gfx_SetPartsScale(e, 0x1000, *(s16 *)w);
    Gfx_DrawParts((s32)e);
}

void Snd_ServiceSlotLoads(void) {
    s32 i;
    SndSlot *e;
    u32 n;
    u32 k;
    s32 *src;
    s32 *dst;
    s32 p;
    s32 j;

    for (i = 0; i < 3; i++) {
        e = &D_80054C48[i];
        switch (e->loadState) {
        case 0:
            break;
        case 1:
            if (e->contentId == 0) {
                e->loadState = 0;
                break;
            }
            e->vbFileId = D_80041194[e->contentId]->vbFile >> 16;
            e->vhFileId = D_80041194[e->contentId]->vhFile >> 16;
            Cd_QueueFile(e->vhFileId);
            e->loadState++;
            break;
        case 2:
            if (Cd_GetFileState(e->vhFileId) == 3) {
                src = (s32 *)Cd_GetFileSync(e->vhFileId);
                n = D_800411FC[i];
                dst = e->headerBuf;
                if ((u32)src + n > 0x801FFFFF) {
                    n = 0x801FFFFC - (u32)src;
                }
                n >>= 2;
                for (k = 0; k < n; k++) {
                    *dst++ = *src++;
                }
                e->loadState++;
            }
            break;
        case 3:
            Cd_QueueFile(e->vbFileId);
            e->loadState++;
            break;
        case 4:
            e->vabId = SsVabOpenHead(Mem_GetOffsetEntry(D_80041194[e->contentId]->vhFile, e->headerBuf), i);
            e->loadState++;
            break;
        case 5:
            if (Cd_GetFileState(e->vbFileId) == 3) {
                Cd_LockFile(e->vbFileId);
                e->vabId = SsVabTransBody((s32)Cd_GetFileEntry(D_80041194[e->contentId]->vbFile), e->vabId);
                e->loadState++;
            }
            break;
        case 6:
            e->sepCount = 0;
            e->loadState++;
        case 7:
            j = e->sepCount;
            p = *(j + D_80041194[e->contentId]->sepOffsets);
            if (p != 0) {
                e->sepIds[j] = SsSepOpen(Mem_GetOffsetEntry(p, e->headerBuf), e->vabId, 0x10);
                e->sepCount++;
            } else {
                e->loadState++;
            }
            break;
        default:
            if (SsVabTransCompleted(0)) {
                Cd_UnlockFile(e->vbFileId);
                e->loadState = 0;
            }
            break;
        }
    }
}


s32 Snd_AnySlotLoading(void) {
    s32 found = 0;
    s32 i = 0;
    SndSlot *p = D_80054C48;
    for (; i < 3; i++, p++) {
        if (p->loadState != 0) found = 1;
        if (found) break;
    }
    return found;
}

void Snd_StopAll(void) {
    SndSlot *p;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 3; i++) {
        p = &D_80054C48[i];
        if (p->vabId != -1) {
            for (j = 0; j < p->sepCount; j++) {
                for (k = 0; k < 0x10; k++) {
                    SsSepStop(p->sepIds[j], k);
                }
            }
        }
    }
    SsUtAllKeyOff(0);
    Snd_CurrentId = -1;
}

void Snd_StopById(s32 id) {
    s32 i;
    s32 j;
    s32 k;

    if (id != -1) {
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        if (D_80054C48[i].loadState == 0) {
            SsSepStop(D_80054C48[i].sepIds[j], k);
        }
        if (Snd_CurrentId == id) {
            Snd_CurrentId = -1;
        }
    }
}

void Snd_UnloadSlot(s32 idx) {
    s32 i;
    s32 k;

    if (D_80054C48[idx].vabId == -1) {
        return;
    }
    for (i = 0; i < D_80054C48[idx].sepCount; i++) {
        for (k = 0; k < 0x10; k++) {
            SsSepStop(D_80054C48[idx].sepIds[i], k);
        }
        SsSepClose(D_80054C48[idx].sepIds[i]);
    }
    SsVabClose(D_80054C48[idx].vabId);
    D_80054C48[idx].loadState = 0;
    D_80054C48[idx].contentId = -1;
    D_80054C48[idx].sepCount = 0;
    D_80054C48[idx].vabId = -1;
}

void Snd_SetSlotContent(s32 idx, s32 v) {
    if (D_80054C48[idx].contentId != v) {
        Snd_UnloadSlot(idx);
        D_80054C48[idx].loadState = 1;
        D_80054C48[idx].contentId = v;
        if (Snd_CurrentId != -1 && idx == ((Snd_CurrentId & 0xF00) >> 8)) {
            Snd_StopById(Snd_CurrentId);
        }
    }
}

void Snd_PlayById(s32 id, s32 set) {
    s32 k;
    s32 i;
    s32 j;
    if (Snd_CurrentId != id) {
        if (set != 0 && Snd_CurrentId != -1) {
            Snd_StopById(Snd_CurrentId);
        }
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        SsSepStop(D_80054C48[i].sepIds[j], k);
        SsSepSetVol(D_80054C48[i].sepIds[j], k, 0x7F, 0x7F);
        SsSepPlay(D_80054C48[i].sepIds[j], k, 1, 1);
        if (set != 0) {
            Snd_CurrentId = id;
        }
    }
} /* libsnd sequence table: SS_SEQ_TABSIZ * 6 seqs * 16 */

extern void SsSetTableSize(void *, s16, s16);
extern void SsSetTickMode(s32);
extern void SsStart2();
extern void SsSetMVol(s16, s16);
extern void SsSetSerialAttr(s8, s8, s8);
extern void SsSetSerialVol(s8, s16, s16);
extern s16 SsUtSetReverbType(s16);
extern void SsUtSetReverbDepth(s16, s16);
extern void SsUtReverbOn();
extern s32 Mem_Alloc(s32, s32);
extern void Snd_SetSlotContent(s32, s32);
extern void Cd_ServiceQueue();

void Snd_Init(void) {
    s32 v0;
    s32 i;
    Ew54C48 *e;

    SsSetTableSize(D_80050A48, 6, 0x10);
    SsSetTickMode(0x1000);
    SsStart2();
    SsSetMVol(0x7F, 0x7F);
    SsSetSerialAttr(0, 0, 1);
    SsSetSerialVol(0, 0x7F, 0x7F);
    SsUtSetReverbType(3);
    SsUtSetReverbDepth(0, 0);
    SsUtReverbOn();

    v0 = Mem_Alloc(D_800411FC[0] + D_800411FC[1] + D_800411FC[2], 4);
    e = (Ew54C48 *)D_80054C48;
    e[0].field_28 = v0;
    v0 += D_800411FC[0];
    e[1].field_28 = v0;
    v0 += D_800411FC[1];
    e[2].field_28 = v0;
    for (i = 0; i < 3; i++) {
        e[i].field_4 = 0;
        e[i].field_0 = -1;
        e[i].field_A = 0;
        e[i].field_8 = -1;
    }

    Snd_SetSlotContent(0, 1);
    do {
        Snd_ServiceSlotLoads();
        Cd_ServiceQueue();
    } while (D_80054C48[0].loadState != 0);

    Snd_SetSlotContent(1, 0xE);
    do {
        Snd_ServiceSlotLoads();
        Cd_ServiceQueue();
    } while (D_80054C48[1].loadState != 0);
}

void Snd_SaveCurrentId(void) {
    Snd_SavedId = Snd_CurrentId;
}


void Snd_RestoreSavedId(void) {
    Snd_PlayById(Snd_SavedId, 1);
}


void Text_PushReturn(s32 arg0) {
    Text_ReturnStack.data[Text_ReturnStack.count] = arg0;
    Text_ReturnStack.count = Text_ReturnStack.count + 1;
}

s32 Text_PopReturn(void) {
    if (Text_ReturnStack.count == 0) {
        return 0;
    }
    Text_ReturnStack.count = Text_ReturnStack.count - 1;
    return Text_ReturnStack.data[Text_ReturnStack.count];
}

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern void Task_Create(u32, s32 *, s32);

void func_8001A958(Actor *a0) {
    if (a0->stateLevel0 != 0) {
        return;
    }
    Gfx_FindOrLoadTexSlot(0x13A0000);
    if ((D_8005F788[0] & 0xF00) != 0x500) {
        Gfx_FindOrLoadTexSlot(0x1100000);
        Task_Create(0xA, a0->u34.children, 0);
    }
    Task_NextState0(a0);
}

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern Obj6A8C0 *func_8006A8C0(s32);
extern void func_8006A920(void *, s32 *);
extern s32 func_8006A9F8(void *);
extern void func_8006AA0C(Obj6A8C0 *, s32);
extern void func_80071FBC(s32 *);
extern s32 func_800720FC(void);
extern void func_80063C84(void);

#ifdef NORMALIZED
void Text_UpdateAllBoxes(Actor *a0) {
    GfxTexSlot *font[2];
    Pair54 glyph;
    Pair54 cell;
    Pair54 pos;
    s32 num[2];
    s32 nums[3];
    TextBoxWork *wk;
    Actor **slots;
    s32 row;
    TextGlyphPoly *pkt;
    s32 *ot;
    s32 cols;
    s32 page;
    s32 nFA;
    s32 nFB;
    s32 nF9;
    s32 nF8;
    s32 nF6;
    s32 nF5;
    s32 nF4b;
    s32 nF4a;
    s32 nF4c;
    u8 nF4d;
    s32 grew;
    TextBox *r;
    u8 *s;
    s32 stop;
    s32 line;
    s32 c;
    s32 v;
    s32 vf;
    u8 k9;
    s32 k4;
    s32 id;
    u8 k;
    s32 j;
    s32 *np;
    u8 isF6;
    u8 mode2;
    Obj6A8C0 *h;
    PadState *e;
    PadState *tb;

    pkt = (TextGlyphPoly *)D_8005F770.packet.addr;
    slots = (Actor **)a0->u34.children;
    wk = (TextBoxWork *)a0->work;
    tb = D_8005F6F0;
    row = 0;
    do {
        if (wk->rec[row].inUse != 0) {
            r = &wk->rec[row];
            nFA = 0;
            nFB = 0;
            nF9 = 0;
            nF8 = 0;
            nF6 = 0;
            nF5 = 0;
            nF4b = 0;
            nF4a = 0;
            s = (u8 *)r->text;
            nF4c = 0;
            pos = *(Pair54 *)&r->x;
            nF4d = 0;
            ot = D_8005F770.otLayers.u[r->otIndex];
            line = 0;
            page = 0;
            r->color = r->baseColor;
            if (r->waitingInput == 0 && r->charDelay != 0) {
                r->delayTimer += D_8005F770.frameDelta;
                if (r->delayTimer >= r->charDelay) {
                    r->visibleChars++;
                    r->delayTimer -= r->charDelay;
                }
            }
            if (r->bigFont != 0) {
                glyph.field_0 = 8;
                glyph.field_2 = 0xD;
                cell.field_0 = 9;
                cols = 0xD;
                cell.field_2 = 0xE;
                font[0] = Gfx_FindOrLoadTexSlot(0x1100000);
                font[1] = Gfx_FindOrLoadTexSlot(0x1100000);
            } else {
                glyph.field_0 = 7;
                cell.field_0 = 7;
                cols = 0x11;
                glyph.field_2 = 9;
                cell.field_2 = 0xA;
                font[0] = Gfx_FindOrLoadTexSlot(0x13A0000);
                font[1] = Gfx_FindOrLoadTexSlot(0x13A0000);
            }
            Text_ReturnStack.count = 0;
            stop = 0;
            grew = 0;
            do {
                switch (*s) {
                case 0xFF:
                    vf = Text_PopReturn();
                    if (vf == 0) {
                        r->charDelay = 0;
                        r->finished = 1;
                        stop = 1;
                        break;
                    }
                    s = (u8 *)vf - 1;
                    line--;
                    break;
                case 0xFE:
                    pos.field_0 = r->x;
                    pos.field_2 += r->lineAdvance;
                    break;
                case 0xFD:
                    pos.field_0 += r->charAdvance;
                    if (grew == 0 && line + 1 >= r->visibleChars) {
                        grew = 1;
                        r->visibleChars++;
                    }
                    break;
                case 0xFC:
                    r->text = (s32)(s + 1);
                    r->visibleChars = 0;
                    r->cmdFADone = 0;
                    r->cmdFBDone = 0;
                    r->cmdF9Done = 0;
                    r->cmdF6Done = 0;
                    r->pausesDone = 0;
                    r->cmdF4TurnDone = 0;
                    r->cmdF4ObjDone = 0;
                    r->cmdF4TaskDone = 0;
                    r->soundsDone = 0;
                    break;
                case 0xFB:
                    if (r->cmdFBDone == nFB) {
                        stop = 1;
                        if (tb[r->padIndex].cross > 0) {
                            r->cmdFBDone = nFB + 1;
                            r->waitingInput = 0;
                            Snd_PlayById(0x13, 0);
                        } else {
                            wk->blinkTimer += D_8005F770.frameDelta;
                            if (wk->blinkTimer >= 0x18) {
                                wk->blinkTimer -= 0x18;
                            }
                            c = ((wk->blinkTimer / 6) & 3) + 0x4F;
                            r->waitingInput = 1;
                            goto draw;
                        }
                    }
                    nFB++;
                    break;
                case 0xFA:
                    s++;
                    if (r->cmdFADone == nFA) {
                        switch (a0->stateLevel1) {
                        default:
                        case 0:
                            Snd_PlayById((*s & 1) ? 0x38 : 0x37, 0);
                            switch (*s) {
                            case 0:
                                Task_Create(4, (s32 *)&slots[row + 1], 0);
                                r->x = -0x90;
                                r->y = 0x34;
                                break;
                            case 2:
                                Task_Create(4, (s32 *)&slots[row + 1], 1);
                                r->x = -0x90;
                                r->y = 0x42;
                                break;
                            case 6:
                                Task_Create(4, (s32 *)&slots[row + 1], 3);
                                r->x = -0x90;
                                r->y = 0x42;
                                break;
                            case 4:
                                Task_Create(4, (s32 *)&slots[row + 1], 2);
                                r->x = -0x90;
                                r->y = 0x12;
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                if (slots[row + 1] != 0) {
                                    Task_SetState0(slots[row + 1], 2);
                                }
                                Task_NextState1(a0);
                                break;
                            }
                            r->waitingInput = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            if (slots[row + 1]->stateLevel1 == 1) {
                                r->waitingInput = 0;
                                r->cmdFADone++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        case 2:
                            if (slots[row + 1] == 0) {
                                r->waitingInput = 0;
                                r->cmdFADone++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        }
                    }
                    nFA++;
                    break;
                case 0xF9:
                    s++;
                    k9 = *s;
                    if (k9 & 1) {
                        if (r->cmdF9Done == nF9) {
                            if (slots[((k9 >> 1) & 1) + 0x33] != 0) {
                                Task_SetState0(slots[((k9 >> 1) & 1) + 0x33], 2);
                            }
                            r->cmdF9Done++;
                            Snd_PlayById(0x3A, 0);
                        }
                    } else if (r->cmdF9Done == nF9) {
                        num[1] = (k9 >> 1) & 1;
                        s++;
                        num[0] = *s++ * 100;
                        num[0] += *s++ * 10;
                        num[0] += *s;
                        if (slots[num[1] + 0x33] != 0) {
                            func_80011B58(slots[num[1] + 0x33], num[0]);
                        } else {
                            Task_Create(5, (s32 *)&slots[num[1] + 0x33], (s32)num);
                        }
                        r->cmdF9Done++;
                        Snd_PlayById(0x39, 0);
                    } else {
                        s += 3;
                    }
                    nF9++;
                    break;
                set1:
                    r->choiceCursor = 1;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                set0:
                    r->choiceCursor = 0;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                case 0xF8:
                    s++;
                    if (r->choicesDone == nF8) {
                        switch (*s) {
                        default:
                        case 0:
                            stop = 1;
                            r->waitingInput = 1;
                            e = &tb[r->padIndex];
                            if (e->pressed & 0x6000) {
                                goto set1;
                            }
                            if (e->pressed & 0x9000) {
                                goto set0;
                            }
                            if (e->cross > 0) {
                                r->waitingInput = 0;
                                r->choicesDone++;
                                Flag_Set(0x10, 1);
                                Flag_Set(0x11, r->choiceCursor);
                                Snd_PlayById(0xA, 0);
                            }
                        cntF8:
                            nF8++;
                            goto next;
                        case 1:
                            c = 0x53;
                            if (r->choiceCursor == 0) {
                                goto draw;
                            }
                            break;
                        case 2:
                            c = 0x53;
                            if (r->choiceCursor == 1) {
                                goto draw;
                            }
                            break;
                        }
                    }
                    pos.field_0 += r->charAdvance;
                    break;
                case 0xF6:
                case 0xF7:
                    isF6 = *s == 0xF6;
                    mode2 = D_8005F770.gameMode / 256 == 2;
                    s++;
                    if (r->cmdF6Done == nF6) {
                        switch (a0->stateLevel1) {
                        case 0:
                        default:
                            np = nums;
                            for (j = 0; j < 3; j++) {
                                *np = *s++ * 100;
                                *np += *s++ * 10;
                                *np += *s++;
                                np++;
                            }
                            if (mode2) {
                                func_80071FBC(nums);
                            } else {
                                h = func_8006A8C0(nums[0]);
                                wk->field_A2C = h;
                                func_8006A920(h, &nums[1]);
                            }
                            r->waitingInput = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            break;
                        }
                        if (mode2 == 0) {
                            if (isF6 == 0 || func_8006A9F8(wk->field_A2C) != 0) {
                                goto advF6;
                            }
                            goto nextF6;
                        }
                        if (func_800720FC() != 0) {
                            goto nextF6;
                        }
                    advF6:
                        r->waitingInput = 0;
                        r->cmdF6Done++;
                        Task_SetState1(a0, 0);
                    } else {
                        s += 8;
                    }
                nextF6:
                    nF6++;
                    break;
                case 0xF5:
                    if (r->pausesDone == nF5) {
                        stop = 1;
                        if (wk->waitTimer == 0x1E) {
                            r->pausesDone = nF5 + 1;
                            r->waitingInput = 0;
                            wk->waitTimer = 0;
                        } else {
                            wk->waitTimer++;
                            r->waitingInput = 1;
                        }
                    }
                    nF5++;
                    break;
                case 0xF4:
                    s++;
                    k4 = *s;
                    s++;
                    if (k4 < 0x10) {
                        if (r->cmdF4ObjDone == nF4a) {
                            s32 d0, d1;
                            d0 = *s++;
                            d1 = *s++;
                            h = func_8006A8C0(d0 * 100 + d1 * 10 + *s);
                            if (h != 0) {
                                func_8006AA0C(h, k4 + 0x1E);
                            }
                            r->cmdF4ObjDone++;
                        } else {
                            s += 2;
                        }
                        nF4a++;
                    } else if (k4 < 0x20) {
                        if (r->cmdF4TurnDone == nF4b) {
                            s32 n;
                            n = *s++ * 100;
                            n += *s++ * 10;
                            do {} while (0);
                            k4 = (k4 - 0x10) << 10;
                            h = func_8006A8C0(n + *s);
                            if (h != 0) {
                                h->transform->rotY = k4;
                            }
                            r->cmdF4TurnDone++;
                        } else {
                            s += 2;
                        }
                        nF4b++;
                    } else if (k4 < 0x30) {
                        if (r->cmdF4TaskDone == nF4c) {
                            switch (a0->stateLevel1) {
                            case 0:
                            default:
                                num[0] = k4 & 0xF;
                                num[1] = 0;
                                Task_Create(0x16, (s32 *)&slots[0x35], (s32)num);
                                a0->stateLevel1++;
                                r->waitingInput = 1;
                                break;
                            case 1:
                                s += 2;
                                if (slots[0x35] == 0) {
                                    a0->stateLevel1 = 0;
                                    r->waitingInput = 0;
                                    r->cmdF4TaskDone++;
                                }
                                break;
                            }
                        } else {
                            s--;
                        }
                        nF4c++;
                    } else if (k4 < 0x40) {
                        r->color = k4 & 0xF;
                        s--;
                    } else {
                        k4 &= 0xF;
                        if (r->soundsDone == nF4d) {
                            if (k4 != 7) {
                                Snd_PlayById(D_8004142C[k4], 0);
                            }
                            r->soundsDone++;
                            if (k4 == 4) {
                                func_80063C84();
                            }
                        }
                        s--;
                        nF4d++;
                    }
                    break;
                case 0xF3:
                    stop = 1;
                    s++;
                    switch (a0->stateLevel1) {
                    case 0:
                    default:
                        Gfx_FadeOutToBlack(0xA);
                        Task_NextState1(a0);
                        break;
                    case 1:
                        break;
                    }
                    if (++a0->stateLevel2 >= 0x19) {
                        if (*s == 0xFC) {
                            D_8005F770.nextGameMode = 0x605;
                        } else if (*s == 0xFD) {
                            D_8005F770.nextGameMode = 0x500;
                        } else if (*s == 0xFE) {
                            D_8005F770.nextGameMode = 0x404;
                        } else if (*s == 0xFF) {
                            D_8005F770.nextGameMode = 0x405;
                        } else {
                            D_8005F770.nextGameMode = *s + 0x300;
                        }
                        s++;
                        D_8005F770.field_24 = *s;
                    }
                    break;
                case 0xF2:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        line--;
                        Text_PushReturn((s32)(s + 1));
                        s = (u8 *)Item_GetNameText(n) - 1;
                    }
                    break;
                case 0xF1:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        line--;
                        Text_PushReturn((s32)(s + 1));
                        s = Digi_GetDefaultName(n) - 1;
                    }
                    break;
                case 0xF0:
                    s++;
                    k = *s;
                    Text_PushReturn((s32)(s + 1));
                    switch (k) {
                    case 0:
                        s = &D_8005E620.field_14 - 1; /* text before the player name */
                        break;
                    case 5:
                        s = &D_8005E620.field_D1 - 1; /* text before the name at 0xD1 */
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        {
                            s32 jj = k - 1;
                            s = (u8 *)(&r->strArg0)[jj] - 1;
                        }
                        break;
                    default:
                        s = (u8 *)D_80041440[k - 6] - 1;
                        break;
                    }
                    line--;
                    break;
                case 0xEF:
                    do {
                        s++;
                        c = *s + 0xF0;
                        goto draw;
                    } while (0);
                default:
                    c = *s;
                draw:
                    if (r->bigFont != 0) {
                        if ((s16)c >= 0x88) {
                            c -= 0x88;
                            page = 1;
                        } else {
                            page = 0;
                        }
                    }
                    pkt->c = *(Col1A9C8 *)D_8005074C;
                    pkt->tag.b.len = 9;
                    pkt->c.code = 0x2C;
                    pkt->x0 = pkt->x2 = pos.field_0;
                    pkt->x1 = pkt->x3 = pkt->x0 + glyph.field_0;
                    pkt->y0 = pkt->y1 = pos.field_2;
                    pkt->y2 = pkt->y3 = pkt->y0 + glyph.field_2;
                    pkt->u0 = pkt->u2 = font[page]->uOffset + ((s16)c % cols) * cell.field_0;
                    pkt->u1 = pkt->u3 = pkt->u0 + glyph.field_0;
                    pkt->v0 = pkt->v1 = ((s16)c / cols) * cell.field_2;
                    pkt->v2 = pkt->v3 = pkt->v0 + glyph.field_2;
                    pkt->clut = ((font[page]->vramY + (r->color + 0xF8)) << 6) | ((font[page]->vramX >> 4) & 0x3F);
                    pkt->tpage = font[page]->tpage;
                    if (D_8005F770.centerX.s == 0x140) {
                        pkt->x0 *= 2;
                        pkt->x1 *= 2;
                        pkt->x2 *= 2;
                        pkt->x3 *= 2;
                    }
                    if (D_8005F770.centerY.s == 0xF0) {
                        pkt->y0 *= 2;
                        pkt->y1 *= 2;
                        pkt->y2 *= 2;
                        pkt->y3 *= 2;
                    }
                    pkt->tag.word = (pkt->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
                    *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                    pkt++;
                    pos.field_0 += r->charAdvance;
                    if (grew == 0 && line + 1 >= r->visibleChars) {
                        grew = 1;
                        r->visibleChars++;
                    }
                    break;
                }
            next:
                s++;
                if (stop != 0) {
                    break;
                }
            } while (r->charDelay == 0 || ++line < r->visibleChars);
        }
    } while (++row < 0x32);
    D_8005F770.packet.addr = (s32)pkt;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Text_UpdateAllBoxes);
void Text_UpdateAllBoxes(Actor *a0);
#endif


void Text_Close(s32 *slot) {
    TaskEntry *e;
    Actor *a;
    s32 i;
    TextBox *r;
    Actor **q;

    if (*slot == -1) {
        return;
    }
    e = Task_FindFirst(9, -1, -1);
    if (e != 0) {
        i = *slot;
        r = &e->work[i];
        q = &e->children[i];
        r->inUse = 0;
        a = q[1];
        if (a != 0) {
            Task_SetState0(a, 3);
        }
        *slot = -1;
    }
}


void Text_Open(void *arg0, TextOpenArgs *arg1) {
    TextOpenSrc *src = (TextOpenSrc *)arg1;
    TaskEntry *r;
    TextBox *base;
    TextBox *p;
    TextBox *rec;
    s32 i;

    r = Task_FindFirst(9, -1, -1);
    if (r == 0) {
        return;
    }
    i = 0;
    base = r->work;
    Text_Close(arg0);

    for (p = base; i < 0x32; i++, p++) {
        if (p->inUse == 0) {
            break;
        }
    }

    if (src->charAdvance == 0) {
        if (src->bigFont != 0) {
            src->charAdvance = 9;
        } else {
            src->charAdvance = 7;
        }
    }
    if (src->lineAdvance == 0) {
        if (src->bigFont != 0) {
            src->lineAdvance = 0xF;
        } else {
            src->lineAdvance = 0xA;
        }
    }

    rec = &base[i];
    rec->inUse = 1;
    rec->bigFont = *(u8 *)&src->bigFont;
    rec->color = *(u8 *)&src->color;
    rec->text = src->text;
    rec->x = src->x - 0xA0;
    rec->y = src->y - 0x78;
    rec->charAdvance = *(u8 *)&src->charAdvance;
    rec->lineAdvance = *(u8 *)&src->lineAdvance;
    rec->charDelay = *(u16 *)&src->charDelay;
    rec->strArg0 = src->strArg0;
    rec->strArg1 = src->strArg1;
    rec->strArg2 = src->strArg2;
    rec->strArg3 = src->strArg3;
    rec->baseColor = *(u8 *)&src->color;
    rec->delayTimer = *(u8 *)&src->charDelay;
    rec->visibleChars = 0;
    rec->finished = 0;
    rec->cmdFADone = 0;
    rec->cmdFBDone = 0;
    rec->waitingInput = 0;
    rec->cmdF9Done = 0;
    rec->choicesDone = 0;
    rec->choiceCursor = 0;
    rec->cmdF6Done = 0;
    rec->pausesDone = 0;
    rec->cmdF4TurnDone = 0;
    rec->cmdF4ObjDone = 0;
    rec->cmdF4TaskDone = 0;
    rec->soundsDone = 0;
    rec->padIndex = 0;
    rec->otIndex = 0;

    *(s32 *)arg0 = i;
}

s32 Text_IsFinished(s32 id) {
    TaskEntry *p;

    if (id == -1) {
        return 1;
    }
    p = Task_FindFirst(9, -1, -1);
    if (p != 0) {
        TextBox *w = &p->work[id];
        return w->finished;
    }
    return 0;
}

void Text_SetColor(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->baseColor = a1;
        r->color = a1;
    }
}

void Text_SetInputPad(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->padIndex = a1;
    }
}

void Text_SetOtLayer(s32 a0, s32 a1) {
    TaskEntry *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        TextBox *r = &p->work[a0];
        r->otIndex = a1;
    }
}

void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3) {
    TextOpenArgs local;
    local.text = (s32)Cd_GetFileEntry(a1 + 0x1FD0000);
    local.bigFont = 0;
    local.color = a2;
    local.x = a3.lo;
    local.y = a3.hi;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = 0;
    Text_Open(a0, &local);
}

void func_8001C038(void *arg0, s32 arg1) {
    TextOpenArgs local;
    local.bigFont = 1;
    local.color = 0;
    local.x = 0;
    local.y = 0;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.text = arg1;
    local.charDelay = 1;
    Text_Open(arg0, &local);
    Flag_Set(0x10, 0);
}

void Mem_FillWordsNeg1(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        *arg0++ = -1;
    }
}

void Text_CloseArray(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        Text_Close(arg0);
        arg0++;
    }
}

void Gpu_ClearScreens(void) {
    RECT r;
    s32 i;

    for (i = 0; i < 2; i++) {
        r = D_8005F770.disp[i].disp;
        ResetGraph(1);
        ClearImage2((s32)&r, 0, 0, 0);
        DrawSync(0);
    }
}


void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_8005F770.draw[i].isbg = 1;
        D_8005F770.draw[i].r0 = a0;
        D_8005F770.draw[i].g0 = a1;
        D_8005F770.draw[i].b0 = a2;
    }
}

void Gpu_DisableBgClear(void) {
    D_8005F770.draw[0].isbg = 0;
    D_8005F770.draw[1].isbg = 0;
}

void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter) {
    SysState *g = &D_8005F770;
    s32 n = 0;
    s32 hw = w / 2;
    s32 hh = h / 2;

    g->centerX.s = hw;
    g->centerY.s = hh;
    switch (mode) {
    default:
    case 0:
        SetDefDrawEnv(&g->draw[0], 0, h, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, h, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = h + hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 1:
        SetDefDrawEnv(&g->draw[0], 0, 0, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, 0, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 2:
        if (inter != 0) {
            SetDefDrawEnv(&g->draw[0], 480, 0, 320, 480);
            SetDefDrawEnv(&g->draw[1], 0, 0, 320, 480);
            SetDefDispEnv(&g->disp[0], 0, 0, 320, 480);
            g->disp[0].isrgb24 = 1;
            SetDefDispEnv(&g->disp[1], 480, 0, 320, 480);
            g->disp[1].isrgb24 = 1;
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
        } else {
            SetDefDrawEnv(&g->draw[0], w, 0, w, h);
            SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
            SetDefDispEnv(&g->disp[0], 0, 0, w, h);
            SetDefDispEnv(&g->disp[1], w, 0, w, h);
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
            n = 0x40 - (w / 16) * 2;
        }
        break;
    }
    Gfx_SetTexSlotCount(n);
    func_8002B4C4();
    SetGeomOffset(0, 0);
}

void Gfx_FadeInFromBlack(s32 arg0) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 2;
    Gfx_FadeState.speed = arg0;
    D_8005F770.fadeLevel = arg0 + 0xFF;
}

void Gfx_FadeOutToBlack(s32 arg0) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 3;
    Gfx_FadeState.speed = arg0;
}

void Gfx_FadeInFromWhite(s32 arg0) {
    Gfx_FadeState.additive = 1;
    Gfx_FadeState.mode = 2;
    Gfx_FadeState.speed = arg0;
    D_8005F770.fadeLevel = arg0 + 0xFF;
}

void Gfx_FadeOutToWhite(s32 arg0) {
    Gfx_FadeState.additive = 1;
    Gfx_FadeState.mode = 3;
    Gfx_FadeState.speed = arg0;
}

void Gfx_FadeClear(void) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 0;
}

void Gfx_FadeSetBlack(void) {
    Gfx_FadeState.additive = 0;
    Gfx_FadeState.mode = 1;
}

void Gfx_DrawFade(void) {
    GfxFadePkt *p;
    GfxFadeMode *q;
    GfxPartOTag *ot;
    s32 w;
    s32 h;
    u8 c;
    s32 abr;

    if (D_8005F770.packet.work == 0) {
        return;
    }
    for (;;) {
        switch (Gfx_FadeState.mode) {
        default:
        case 0:
            D_8005F770.fadeLevel = 0;
            return;
        case 1:
            D_8005F770.fadeLevel = 0xFF;
            goto check;
        case 2:
            D_8005F770.fadeLevel -= Gfx_FadeState.speed;
            if (D_8005F770.fadeLevel > 0) {
                goto draw;
            }
            D_8005F770.fadeLevel = 0;
            Gfx_FadeState.mode = 0;
            continue;
        case 3:
            D_8005F770.fadeLevel += Gfx_FadeState.speed;
            if (D_8005F770.fadeLevel < 0xFF) {
                goto check;
            }
            D_8005F770.fadeLevel = 0xFF;
            Gfx_FadeState.mode = 1;
            continue;
        }
    }
check:
    if (D_8005F770.fadeLevel == 0) {
        return;
    }
draw:
    abr = 2;
    q = (GfxFadeMode *)D_8005F770.packet.work;
    p = (GfxFadePkt *)q;
    ot = (GfxPartOTag *)D_8005F770.otLayers.s[0];
    p->t.len = 5;
    p->code = 0x2A;
    c = D_8005F770.fadeLevel;
    p->g = c;
    p->b = c;
    p->r = c;
    w = D_8005F770.centerX.lo;
    p->x0 = p->x2 = -w;
    p->x1 = p->x3 = w;
    h = D_8005F770.centerY.lo;
    p->y0 = p->y1 = -h;
    p->y2 = p->y3 = h;
    p->t.addr = ot->addr;
    ot->addr = (u32)p;
    q = &p->m;
    if (Gfx_FadeState.additive != 0) {
        abr = 1;
    }
    q->t.len = 1;
    q->mode = (abr << 5) | 0xE1000400;
    p->m.t.addr = ot->addr;
    ot->addr = (u32)q;
    q = (GfxFadeMode *)(p + 1);
    D_8005F770.packet.work = (ActorWork *)q;
}

#ifdef NORMALIZED
void Gpu_SetLayerOtPtrs(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_8005F770.otLayerLen[i] = D_80041570[D_8005CCF8.field_60][i];
        D_8005F770.otLayers.s[i] = &Gpu_OtBufs[D_8005F770.bufIndex].entries[D_800415F0[D_8005CCF8.field_60][i]];
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gpu_SetLayerOtPtrs);
void Gpu_SetLayerOtPtrs(void);
#endif

void func_8001C800(s32 arg0) {
    Gpu_OtBufs[2].entries[0] = arg0;
}

void Gpu_ClearOt(s32 arg0) {
    ClearOTagR(&Gpu_OtBufs[arg0], 0x100C);
}

s32 Gpu_DrawOt(s32 arg0) {
    s32 *p = (s32 *)&D_80058D28[arg0];
    return DrawOTag(&p[-1]);
}

#ifdef NORMALIZED
void Gpu_SkipEmptyOtEntries(s32 arg0) {
    u32 *p = (u32 *)&D_80058D28[arg0];
    u32 *end = (u32 *)&D_80058D28[arg0 - 1];
    u32 *q;
    u32 m = 0xFFFFFF;

    p--;
    while (p != end) {
        q = p - 1;
        if ((*p & m) == ((u32)q & m)) {
            u32 v = *q;
            u32 w = (u32)(q - 1) & m;

            while ((v & m) == w) {
                q--;
                v = *q;
                w = (u32)(q - 1) & m;
            }
            *p = (u32)q & m;
        }
        p = q;
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gpu_SkipEmptyOtEntries);
void Gpu_SkipEmptyOtEntries(s32 arg0);
#endif

s32 func_8001C92C(void) {
    return 0;
}

void Gpu_FreePrimBufs(void) {
    if (D_80041670[0] != 0) {
        Mem_Free(D_80041670[0]);
        D_80041670[0] = 0;
        Mem_Free(D_80041670[1]);
        D_80041670[1] = 0;
    }
    D_8005F770.packet.addr = 0;
}

void Gpu_ResetPrimBuf(void) {
    D_8005F770.packet.work = D_80041670[D_8005F770.bufIndex];
}

extern s32 Mem_Alloc(s32, s32);

void Gpu_AllocPacketBufs(s32 a0) {
    D_80041670[2] = (ActorWork *)a0;
    D_80041670[0] = (ActorWork *)Mem_Alloc(a0, 2);
    D_80041670[1] = (ActorWork *)Mem_Alloc(a0, 2);
    D_8005F770.packet.work = D_80041670[D_8005F770.bufIndex];
}

GfxTexSlot *Gfx_GetTexSlot(s32 arg0) {
    return &Gfx_TexSlots[arg0];
}

void Gfx_InitTexSlots(void) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        Gfx_TexSlots[i].vramX = 0x3E0 - (i / 2) * 32;
        Gfx_TexSlots[i].index = i;
        Gfx_TexSlots[i].vramY = (i & 1) << 8;
        Gfx_TexSlots[i].fileId = 0;
        Gfx_TexSlots[i].lastUsed = 0;
        Gfx_TexSlots[i].colorMode = 0;
        Gfx_TexSlots[i].uOffset = 0;
        Gfx_TexSlots[i].tpage = 0;
    }
}

s32 Gfx_GetTimPixelMode() {
    return Cd_GetFileEntry()->packedId & 7;
}

#ifdef NORMALIZED
void Gfx_LoadTexSlotImage(GfxTexSlot *a0) {
    u32 *p;
    u32 flags;
    RECT clut;
    RECT img;

    p = (u32 *)Cd_GetFileEntry(a0->fileId);
    p++;
    flags = *p++;
    if (flags & 8) {
        if (flags & 7) {
            clut.x = 0;
            clut.y = a0->index + 0x1E0;
            clut.w = 0x100;
            clut.h = 1;
            LoadImage((s32)&clut, (s32)((TimBlk *)p + 1));
        }
        p = (u32 *)((u8 *)p + *p);
    }
    img.x = a0->vramX;
    img.y = a0->vramY;
    img.w = ((TimBlk *)p)->rect.w;
    img.h = ((TimBlk *)p)->rect.h;
    LoadImage((s32)&img, (s32)((TimBlk *)p + 1));
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_LoadTexSlotImage);
void Gfx_LoadTexSlotImage(GfxTexSlot *a0);
#endif


#ifdef NORMALIZED
GfxTexSlot *Gfx_FindOrLoadTexSlot(s32 id) {
    GfxTexSlot *e;
    GfxTexSlot *p;
    s32 i;
    u32 best;
    s32 idx;
    s32 n;
    s32 tp;
    s32 t;

    p = Gfx_TexSlots;
    for (i = 0; i < 0x40; i++, p++) {
        if (p->fileId == -1) {
            continue;
        }
        if (p->fileId == -2) {
            continue;
        }
        if (p->fileId == id) {
            p->lastUsed = D_8005F770.frameCount;
            return p;
        }
    }
    best = -1;
    idx = 0;
    if (Gfx_GetTimPixelMode(id)) {
        n = 0x20;
        tp = 1;
    } else {
        n = 0x40;
        tp = 0;
    }
    e = Gfx_TexSlots;
    for (i = 0; i < n; i++, e++) {
        if (e->fileId == -1) {
            continue;
        }
        if (e->fileId == -2) {
            continue;
        }
        if (e->fileId == 0) {
            idx = i;
            break;
        }
        if (e->lastUsed < best) {
            best = e->lastUsed;
            idx = i;
        }
    }
    e = &Gfx_TexSlots[idx];
    e->fileId = id;
    e->lastUsed = D_8005F770.frameCount;
    e->colorMode = tp;
    t = e->index & 2;
    e->uOffset = t == 0;
    if (tp) {
        e->uOffset <<= 6;
    } else {
        e->uOffset <<= 7;
    }
    e->tpage = (tp << 7) | ((e->vramY & 0x100) >> 4) | ((e->vramX & 0x3FF) >> 6) | ((e->vramY & 0x200) << 2);
    Gfx_LoadTexSlotImage(e);
    return e;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_FindOrLoadTexSlot);
GfxTexSlot *Gfx_FindOrLoadTexSlot(s32 id);
#endif

void Gfx_SetTexSlotCount(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        GfxTexSlot *p = Gfx_GetTexSlot(i);
        if (i >= arg0) {
            p->fileId = -1;
        } else {
            if (p->fileId == -1) p->fileId = 0;
        }
    }
}

s32 Gfx_ReserveTexSlot(void) {
    u32 min = -1;
    s32 best = 0;
    s32 i;
    GfxTexSlot *p = Gfx_TexSlots;

    for (i = 0; i < 24; i++, p++) {
        if (p->fileId == -2) {
            continue;
        }
        if (p->fileId == 0) {
            best = i;
            break;
        }
        if ((u32)p->lastUsed < min) {
            min = p->lastUsed;
            best = i;
        }
    }
    p = &Gfx_TexSlots[best];
    p->fileId = -2;
    p->lastUsed = D_8005F770.frameCount;
    p->colorMode = 0;
    p->uOffset = ((p->index & 2) == 0) << 7;
    p->tpage = ((p->vramY & 0x100) >> 4) | ((p->vramX & 0x3FF) >> 6) | ((p->vramY & 0x200) << 2);
    return (s32)p;
}

void Gfx_ReleaseTexSlot(s32 *arg0) {
    if (*arg0 == -2) {
        *arg0 = 0;
    }
}

#ifdef NORMALIZED
void Gfx_DrawPartSprites(void *arg0, s32 arg1) {
    GfxPartSprite *s = arg0;
    GfxPartOTag *ot = (GfxPartOTag *)arg1;
    GfxPartCell *e;
    GfxPartTexSlot *t;
    GfxPartPkt *p;
    u16 tpage;
    s32 y;

    e = (GfxPartCell *)Cd_GetFileEntry(s->fileId);
    t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(s->fileId & 0xFFFF0000);
    p = (GfxPartPkt *)D_8005F770.packet.addr;
    for (; e->u != 0xFF; e++) {
        if (e->frame != s->partGroup) {
            continue;
        }
        p->s.c = s->color;
        p->s.tag.len = 4;
        p->s.c.code = 0x64;
        if (e->blend & 0x80) {
            p->s.c.code = 0x66;
            tpage = t->tpage + ((e->blend & 3) << 5);
        } else {
            tpage = t->tpage;
        }
        p->s.x0 = e->x + s->x;
        p->s.u0 = e->u + t->u;
        p->s.w = e->w;
        p->s.y0 = e->y + s->y;
        p->s.v0 = e->v;
        p->s.h = e->h;
        if (p->s.h == 0) {
            p->s.h--;
        }
        if (t->is8bit != 0) {
            y = t->index + 0x1E0;
            p->s.clut = (e->clutRow + y + s->clutRow) << 6;
        } else {
            p->s.clut = ((e->clutY + t->clutY + e->clutRow + s->clutRow) << 6) |
                       (((e->clutX + t->clutX) >> 4) & 0x3F);
        }
        p->s.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (GfxPartPkt *)(&p->s + 1);
        p->t.tag.len = 1;
        p->t.code = 0xE1000600 | (tpage & 0x9FF);
        p->t.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (GfxPartPkt *)(&p->t + 1);
    }
    D_8005F770.packet.addr = (s32)p;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_DrawPartSprites);
void Gfx_DrawPartSprites(void *arg0, s32 arg1);
#endif


void Gfx_DrawPartQuadsRot(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    GfxPartCell *e;
    GfxPartTexSlot *t;
    GfxPartPolyFT4 *p;
    GfxPartRotXY out;
    SVec1D104 sv[4];
    s32 i;
    s32 u;
    s32 y;

    e = (GfxPartCell *)Cd_GetFileEntry(((GfxPartSprite *)arg0)->fileId);
    t = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(((GfxPartSprite *)arg0)->fileId & 0xFFFF0000);
    p = (GfxPartPolyFT4 *)D_8005F770.packet.addr;
    for (; e->u != 0xFF; e++) {
        if (e->frame != ((GfxPartSprite *)arg0)->partGroup) {
            continue;
        }
        p->c = ((GfxPartSprite *)arg0)->color;
        p->tag.len = 9;
        p->c.code = 0x2C;
        if (e->blend & 0x80) {
            p->c.code = 0x2E;
            p->v[1].extra = t->tpage | ((e->blend & 3) << 5);
        } else {
            p->v[1].extra = t->tpage;
        }
        sv[0].vx = sv[2].vx = e->x;
        sv[1].vx = sv[3].vx = e->x + e->w;
        sv[0].vy = sv[1].vy = e->y;
        if (e->h) sv[2].vy = sv[3].vy = e->y + e->h; else sv[2].vy = sv[3].vy = e->y + 0xFF;
        sv[0].vz = sv[1].vz = sv[2].vz = sv[3].vz = 0;
        for (i = 0; i < 4; i++) {
            ApplyMatrixSV(arg1, &sv[i], &out);
            p->v[i].x = out.vx + ((GfxPartSprite *)arg0)->x;
            p->v[i].y = out.vy + ((GfxPartSprite *)arg0)->y;
        }
        u = e->u + t->u;
        p->v[0].u = p->v[2].u = u;
        u += e->w;
        p->v[1].u = p->v[3].u = u;
        if (((GfxPartSprite *)arg0)->scaleX < 0) {
            p->v[1].u = p->v[3].u = u - 1;
        }
        if (p->v[1].u == 0) {
            p->v[1].u = p->v[3].u = 0xFF;
        }
        p->v[0].v = p->v[1].v = e->v;
        u = e->v + e->h;
        p->v[2].v = p->v[3].v = u;
        if (((GfxPartSprite *)arg0)->scaleY < 0) {
            p->v[2].v = p->v[3].v = u - 1;
        }
        if (p->v[2].v == 0) {
            p->v[2].v = p->v[3].v = 0xFF;
        }
        if (t->is8bit != 0) {
            y = t->index + 0x1E0;
            p->v[0].extra = (e->clutRow + y + ((GfxPartSprite *)arg0)->clutRow) << 6;
        } else {
            p->v[0].extra = ((e->clutY + t->clutY + e->clutRow + ((GfxPartSprite *)arg0)->clutRow) << 6) |
                            (((e->clutX + t->clutX) >> 4) & 0x3F);
        }
        if (arg3 & 1) {
            p->v[0].x *= 2;
            p->v[1].x *= 2;
            p->v[2].x *= 2;
            p->v[3].x *= 2;
        }
        if (arg3 & 2) {
            p->v[0].y *= 2;
            p->v[1].y *= 2;
            p->v[2].y *= 2;
            p->v[3].y *= 2;
        }
        p->tag.addr = ((GfxPartOTag *)arg2)->addr;
        ((GfxPartOTag *)arg2)->addr = (u32)p;
        p++;
    }
    D_8005F770.packet.addr = (s32)p;
}


void Gfx_HidePartsByMask(GfxPartMaskView *p, s32 mask) {
    s32 i;

    for (i = 0; p[i].fileId != 0; i++) {
        if (p[i].partMask & mask) {
            p[i].visible = 0;
        } else {
            p[i].visible = 1;
        }
    }
}

void Gfx_SetPartsScale(GfxPartScaleView *p, s32 a1, s32 a2) {
    if (p->fileId == 0) {
        return;
    }
    do {
        if (a1 != 0x1000) {
            p->unscaled = 0;
        } else {
            p->unscaled = 1;
        }
        p->scaleX = a1;
        if (a2 != 0x1000) {
            p->unscaled = 0;
        } else {
            p->unscaled = 1;
        }
        p->scaleY = a2;
        p++;
    } while (p->fileId != 0);
}

void Gfx_SetPartsNumber(GfxPart *p, s32 mask, s32 n, s32 val) {
    u8 d[8];
    GfxPart *q;
    s32 i = 0;
    s32 lead = 0;
    s32 k;
    s32 x;

    if (n < 0) {
        lead = 1;
        n = -n;
    }
    x = val;
    for (k = n - 1; k != -1; k--) {
        d[k] = x % 10;
        x /= 10;
    }
    if (p->fileId != 0) {
        q = p;
        do {
            if (q->groupMask & mask) {
                if (lead == 1 || i == n - 1 || d[i] != 0) {
                    lead = 1;
                    q->frame = d[i];
                } else {
                    q->frame = 0xFF;
                }
                i++;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
} /* identity matrix */
extern void Gfx_DrawPartSprites(void *, s32);
extern void Gfx_DrawPartQuadsRot(void *, void *, s32, s32);
extern void ScaleMatrix(Obj209 *, s32 *);

void Gfx_DrawPartsEx(void *arg0, s32 arg1) {
    Rec1D6B4 *s2 = (Rec1D6B4 *)arg0;
    s32 s3 = 0;
    s32 s4;

    if (arg1 != 0) {
        s32 f114 = D_8005F770.centerY.s;
        s3 = 0;
        s3 = (D_8005F770.centerX.s ^ 0x140) == s3;
        if (f114 == 0xF0) {
            s3 |= 2;
        }
    }
    if (s2->field_0 == 0) {
        return;
    }
    do {
        s4 = D_8005F770.otLayers.addr[s2->field_B];
        if (s2->field_F != 0) {
            if (s2->field_E != 0) {
                if (s3 != 0) {
                    s2->field_24 = 0;
                    s2->field_22 = 0;
                    s2->field_20 = 0;
                    s2->field_10 = 0x1000;
                    s2->field_14 = 0x1000;
                } else {
                    Gfx_DrawPartSprites(s2, s4);
                    goto Ladv;
                }
            }
            if (D_8004167C.field_0 == *(s32 *)&s2->field_20 &&
                D_8004167C.field_4 == s2->field_24 &&
                D_8004167C.field_8 == s2->field_10 &&
                D_8004167C.field_C == s2->field_14) {
            } else {
                *(Agg1D6B4 *)&D_8004167C = *(Agg1D6B4 *)&s2->field_20;
                D_8004167C.field_8 = s2->field_10;
                D_8004167C.field_C = s2->field_14;
                RotMatrixYXZ(&D_8004167C, (Obj209 *)&D_8004167C.field_18);
                ScaleMatrix((Obj209 *)&D_8004167C.field_18, &D_8004167C.field_8);
            }
            Gfx_DrawPartQuadsRot(s2, &D_80041694, s4, s3);
        }
    Ladv:
        s2 = (Rec1D6B4 *)((u8 *)s2 + 0x28);
    } while (s2->field_0 != 0);
}

void Gfx_DrawParts(s32 arg0) {
    Gfx_DrawPartsEx(arg0, 1);
}

void func_8001D8A4(s32 arg0) {
    Gfx_DrawPartsEx(arg0, 0);
}

EntD8C4 *func_8001D8C4(id) s32 id; {
    EntD8C4 *p = (EntD8C4 *)Cd_GetFileOrNull(0xC6C);
    s16 v;

loop:
    v = p->id;
    if (v == 0) {
        goto fail;
    }
    if (v == id) {
        return p;
    }
    p++;
    goto loop;
fail:
    return 0;
}

u8 func_8001D910(void) {
    return func_8001D8C4()->field_3;
}

u8 func_8001D934(void) {
    return func_8001D8C4()->u4.field_4 & 0xF;
}

s32 func_8001D958(void) {
    return (func_8001D8C4()->u4.field_4h >> 4) & 0xF;
}

s32 func_8001D980(void) {
    return (func_8001D8C4()->u4.field_4h >> 8) & 0xF;
}

u8 func_8001D9A8(void) {
    return func_8001D8C4()->field_2;
}

s32 func_8001D9CC(s32 id, s32 k) {
    switch (k) {
    default:
    case 0:
        return func_8001D8C4(id)->u4.field_4h >> 12;
    case 1:
        return func_8001D8C4(id)->u6.field_6 & 0xF;
    case 2:
        return (func_8001D8C4(id)->u6.field_6h >> 4) & 0xF;
    case 3:
        return (func_8001D8C4(id)->u6.field_6h >> 8) & 0xF;
    case 4:
        return func_8001D8C4(id)->u6.field_6h >> 12;
    }
}


u8 func_8001DA80(s32 id, s32 val) {
    EntD8C4 *e = func_8001D8C4(id);
    s32 i;

    if (e->rangeValues[0] == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (e->rangeBounds[i + 1] == 0) {
            break;
        }
        if (val >= e->rangeBounds[i] && val < e->rangeBounds[i + 1]) {
            break;
        }
    }
    return e->rangeValues[i];
}

Ent1DB18 *func_8001DB18(s32 id) {
    Rec1DB18 *p = (Rec1DB18 *)Cd_GetFileOrNull(0xC6F);

    while (1) {
        if (p->id == 0) {
            break;
        }
        if (p->id == id) {
            return (Ent1DB18 *)p;
        }
        p++;
    }
    return 0;
}

void func_8001DB68(void *a0, Out1DB68 *out) {
    Ent1DB18 *src = func_8001DB18(a0);
    Ent1DB18 *p;
    s32 i;
    out->field_0 = src->u0.h.field_2;
    out->field_4 = ((s32)src->u0.field_0 << 20) >> 28;
    out->field_8 = ((s32)src->u0.field_0 << 16) >> 28;
    out->field_C = src->u4.field_4b;
    out->field_10 = (src->u4.field_4 >> 8) & 0xF;
    out->field_14 = (src->u4.field_4 >> 12) & 0xF;
    p = src;
    out->field_18 = p->u4.h.field_6;
    {
        DigiInitRow *row = (DigiInitRow *)p;
        for (i = 0; i < 3; i++) {
            out->digiIds[i] = row[i].digiId;
            out->levels[i] = row[i].level;
        }
    }
}

void Digi_InitFromTable(s32 a0, s32 a1, DigiRosterEntry *e) {
    DigiInitRow *r = (DigiInitRow *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    Mem_Zero(e, 0x5C);
    e->state = 2;
    {
        DigiInitRow *row = &r[a1];
        e->digiId = row->digiId;
        e->hp = e->maxHp = row->hp;
        e->mp = e->maxMp = row->mp;
    }
    name = Digi_GetDefaultName(e->digiId);
    for (i = 0; i < 14; i++) {
        e->name[i] = name[i];
    }
    {
        DigiInitRow *row = &r[a1];
        e->level = row->level;
        e->field_1C = row->field_13;
        e->field_1E = row->field_14;
        e->field_20 = row->field_16;
        e->attr[0] = row->field_17;
        e->attr[1] = row->field_18;
        e->attr[2] = row->field_19;
    }
    e->maxLevel = func_8001EB58(e->level);
    if (e->level == 1) {
        e->exp = 0;
    } else {
        e->exp = Digi_GetExpToNextLevel(e->level - 1, 100, 0);
    }
}

void func_8001DDA8(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o) {
    Tbl1DDA8 *t = (Tbl1DDA8 *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    e->state = a1 + 3;
    e->digiId = t->rows[a1].digiId;
    e->hp = e->maxHp = t->rows[a1].hp;
    e->mp = e->maxMp = t->rows[a1].mp;
    if (e->digiId != 0) {
        name = Digi_GetDefaultName(e->digiId);
        for (i = 0; i < 14; i++) {
            e->name[i] = name[i];
        }
        e->level = t->rows[a1].field_A;
        e->exp = t->rows[a1].field_6;
        e->field_1C = t->rows[a1].field_B;
        e->field_1E = t->rows[a1].field_C;
        e->field_20 = t->rows[a1].field_E;
        e->attr[0] = t->rows[a1].field_F;
        e->attr[1] = t->rows[a1].field_10;
        e->attr[2] = t->rows[a1].field_11;
        for (i = 3; i < 12; i++) {
            e->attr[i] = 0;
        }
        o->field_2 = t->rows[a1].field_F;
        o->field_3 = t->rows[a1].field_10;
        o->field_4 = t->rows[a1].field_11;
        o->field_9[0] = t->rows[a1].field_12[0][1];
        o->field_9[1] = t->rows[a1].field_12[1][1];
        o->field_9[2] = t->rows[a1].field_12[2][1];
        o->field_9[3] = t->rows[a1].field_12[3][1];
        o->field_0 = t->rows[a1].field_8;
        o->field_D[0] = t->rows[a1].field_12[0][2];
        o->field_D[1] = t->rows[a1].field_12[1][2];
        o->field_D[2] = t->rows[a1].field_12[2][2];
        o->field_D[3] = t->rows[a1].field_12[3][2];
        o->field_5[0] = t->rows[a1].field_12[0][0];
        o->field_5[1] = t->rows[a1].field_12[1][0];
        o->field_5[2] = t->rows[a1].field_12[2][0];
        o->field_5[3] = t->rows[a1].field_12[3][0];
    }
}


ItemTableEntry *Item_FindById(arg0)
s32 arg0;
{
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    while (*p != 0) {
        if (*p == arg0) {
            return (ItemTableEntry *)p;
        }
        p = (s16 *)((u8 *)p + 0x10);
    }
    return 0;
}

s32 Item_GetNameText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->nameOffset + base;
}

s32 Item_GetDescText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->descOffset + base;
}

s32 func_8001E0C0(s32 id) {
    return Item_FindById(id)->u0.b0.field_2;
}

s32 func_8001E0E4(void) {
    return Item_FindById()->u0.b0.field_3 & 0xF;
}

s32 Item_CheckId(void) {
    return Item_FindById() != 0 ? 0 : -1;
}

s32 func_8001E134(void) {
    return Item_FindById()->u0.field_0 >> 30;
}

s32 func_8001E158(void) {
    return (Item_FindById()->u0.field_0 >> 28) & 3;
}

s32 func_8001E180(void) {
    return Item_FindById()->u4.field_4 & 0xFFFFFF;
}

u8 func_8001E1AC(void) {
    return Item_FindById()->u4.b4.field_7;
}

s32 Item_GetTableIndex(s32 id) {
    ItemTableEntry *p = (ItemTableEntry *)Cd_GetFileEntry(0x45E0000);
    s32 i = 0;

    while (p->u0.id != 0) {
        if (p->u0.id == id) {
            return i;
        }
        p++;
        i++;
    }
    return 0;
}

s32 Item_GetIdAtIndex(s32 a0) {
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    s32 i;
    s32 r;
    for (i = 0; i < a0; i++) {
        if (*p == 0) break;
        p = (s16 *)((u8 *)p + 0x10);
    }
    r = 0;
    if (i == a0) {
        r = *p;
    }
    return r;
}

void func_8001E28C(s32 arg0) {
    D_8005D560.fileId = arg0;
}

Blk18 *func_8001E298(FlagEntryIdx *arg0) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 2);
    return &base[arg0->condIdx];
}

Blk18 *func_8001E2E0(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altCondIdx];
}

Blk18 *func_8001E338(FlagEntryIdx *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 2);
    return &base[((FlagEntryIdx *)((u8 *)arg0 + arg1))->altSetIdx];
}

s32 Flag_NextPassingEntry(void) {
    while (D_8005D560.cursor->field_0 != 0) {
        if (Flag_TestConds(func_8001E298((FlagEntryIdx *)D_8005D560.cursor)) != 0) {
            D_8005D560.match = *D_8005D560.cursor;
            {
                s32 r = D_8005D560.entryIndex;

                D_8005D560.cursor++;
                D_8005D560.entryIndex = r + 1;
                return r;
            }
        }
        D_8005D560.cursor++;
        D_8005D560.entryIndex++;
    }
    return -1;
}

void func_8001E480(void) {
    D_8005D560.fileBase = Cd_GetFileOrNull(D_8005D560.fileId);
    D_8005D560.cursor = Cd_GetFileEntry(D_8005D560.fileId << 16);
    D_8005D560.entryIndex = 0;
    Flag_NextPassingEntry();
}

FlagBranchEntry *func_8001E4CC(arg0)
s32 arg0;
{
    FlagBranchEntry *base = (FlagBranchEntry *)Cd_GetFileEntry(D_8005D560.fileId << 16);
    return &base[arg0];
}

extern s32 Flag_TestConds();
extern void Flag_ApplySets();

s32 Flag_SelectBranch(s32 arg0) {
    FlagBranchEntry *base;
    s32 r;
    s32 i;
    r = Cd_GetFileOrNull(D_8005D560.fileId);
    base = func_8001E4CC(arg0);
    for (i = 0; i < 6; i++) {
        if (Flag_TestConds(func_8001E2E0((FlagEntryIdx *)base, i)) != 0) {
            break;
        }
    }
    if (i == 6) {
        i = 0;
    }
    Flag_ApplySets(func_8001E338((FlagEntryIdx *)base, i));
    return base->branchOffsets[i] + r;
}

s32 func_8001E5C0(void) {
    return Cd_GetFileOrNull(D_8005D560.fileId);
}

Blk12 *func_8001E5E8(void) {
    FlagBranchEntry *e = func_8001E4CC();
    Blk12 *base = (Blk12 *)Cd_GetFileEntry((D_8005D560.fileId << 16) | 1);
    return &base[e->blockIndex];
}

s16 func_8001E634(void) {
    return func_8001E4CC()->field_0;
}

s16 func_8001E658(void) {
    return func_8001E4CC()->field_2;
}

s32 Digi_GetDataFileId(s32 arg0) {
    if (arg0 < 0x12C) {
        return 0xCB9;
    }
    if ((u32)(arg0 - 0x190) < 0x65) {
        return 0xCBB;
    }
    return 0xCBA;
}

DigiData *Digi_FindDataById(s32 id) {
    DigiData *e = (DigiData *)Cd_GetFileEntry(Digi_GetDataFileId(id) << 16);
    s32 k;

    while (1) {
        k = (e->u4.packedId >> 1) & 0x7FFF;
        if (k == 0) {
            break;
        }
        if (k == id) {
            return e;
        }
        e++;
    }
    return 0;
}

s32 Digi_GetModelFile(s32 id) {
    return Digi_FindDataById(id)->u4.h4.modelFile;
}

s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1) {
    return Digi_FindDataById(arg0)->animFiles[arg1];
}

u8 *Digi_GetDefaultName(s32 id) {
    s32 v;

    v = Digi_FindDataById(id)->nameOffset;
    v += Cd_GetFileOrNull(Digi_GetDataFileId(id));
    return (u8 *)v;
}

s16 func_8001E79C(s32 id) {
    return Digi_FindDataById(id)->field_1E;
}

s16 func_8001E7C0(s32 id) {
    return Digi_FindDataById(id)->field_20;
}

void func_8001E7E4(s32 a0, void *a1) {
    u8 *base;
    DigiData *e;
    base = (u8 *)Cd_GetFileEntry((Digi_GetDataFileId(a0) << 16) | 1);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 0) = *(Row6 *)(base + e->field_22 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 6) = *(Row6 *)(base + e->field_24 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 12) = *(Row6 *)(base + e->field_26 * 6);
}

s32 func_8001E8D0(s32 id) {
    return Digi_FindDataById(id)->u4.packedId & 1;
}

u16 func_8001E8F4(s32 idx) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000) + idx;
    return (p->packedId >> 1) & 0x7FFF;
}

s32 func_8001E938(void) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000);
    s32 i = 0;
    while ((p->packedId >> 1) & 0x7FFF) {
        p++;
        i++;
    }
    return i;
}

#ifdef NORMALIZED
s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur) {
    s32 x;
    s32 sq;
    s32 exp;

    if (lv >= max) {
        return 99999999;
    }
    if (lv >= 62) {
        x = lv - 61;
        exp = 826540 + x * 65535;
    } else if (lv >= 31) {
        x = lv - 30;
        sq = x * x;
        exp = (sq * x * 5 + sq * 15 + x * 1145) * 4 + 31080;
    } else if (lv >= 21) {
        x = lv - 20;
        sq = x * x;
        exp = (sq * x * 5 + sq * 15) * 2 + x * 1220 + 5880;
    } else if (lv >= 11) {
        x = lv - 10;
        sq = x * x;
        exp = sq * x * 10 / 3 + sq * 10 + x * 107 + 480;
    } else {
        x = lv;
        sq = x * x;
        exp = sq * x / 3 + sq + x * 5;
    }
    if (exp < cur) {
        return 0;
    }
    return exp - cur;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Digi_GetExpToNextLevel);
s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur);
#endif

s32 func_8001EB58(s32 x) {
    s32 h = x / 2;

    if (x < 6) {
        return x / 3 + 13;
    }
    if (x < 18) {
        return h + 14;
    }
    if (x < 28) {
        return h + 17;
    }
    {
        s32 r = (u16)((u16)Rand_Next() % 3) + 2;
        return x + r;
    }
}

void func_8001EC00(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void func_8001EC10(Actor *arg0) {
    s32 state = arg0->stateLevel0;

    switch (state) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, 0x5B)->otIndex = 4;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
        break;
    case 1: {
        ActorWork *w = arg0->work;
        Actor *v1 = (Actor *)w->field_0;
        w->field_4 = 0;
        if (v1 != 0) {
            s32 st = v1->stateLevel0;
            if (st != 0 && st != 3) {
                ModelBone *de = v1->model->bones;
                ActorTransformView *dst = arg0->u38.ptr38;
                s32 t = de->worldTx;
                dst->posY = 0;
                dst->posX = t;
                dst->posZ = de->worldTz;
                w->field_4 = state;
            }
        }
        break;
    }
    case 2:
        break;
    }
}

void func_8001ECE4(Actor *arg0) {
    if (arg0->work->field_4 != 0) {
        Gfx_AttachModel(arg0, 0x5B);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 1);
    }
}

EntED40 *func_8001ED40(s32 id) {
    EntED40 *p = (EntED40 *)Cd_GetFileEntry(0x25B0000);

    do {
        if (p->u0.id == id) {
            return p;
        }
    } while ((p++)->u0.id != 0);
    return 0;
}

s32 func_8001ED84(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    EntED40 *p = func_8001ED40(arg0);
    if (p != 0) {
        return p->nameOffset + base;
    }
    return 0;
}

s32 func_8001EDD4(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    return func_8001ED40(arg0)->descOffset + base;
}

s32 func_8001EE10(s32 id) {
    return func_8001ED40(id)->u0.h0.field_2 & 3;
}

s32 func_8001EE34(s32 id) {
    return (func_8001ED40(id)->u0.field_0 >> 18) & 3;
}

s32 func_8001EE5C(s32 id) {
    return func_8001ED40(id)->field_C;
}

u8 func_8001EE80(s32 id) {
    return func_8001ED40(id)->field_4;
}

void func_8001EEA4(s32 id, s32 n, s16 *a, s16 *b) {
    EntED40 *p = func_8001ED40(id);
    s32 i;

    n *= 2;
    for (i = 0; i < 3; i++) {
        a[i] = p->field_2C[n][i];
        b[i] = p->field_2C[n + 1][i];
    }
}


s32 func_8001EF3C(s32 id) {
    return (func_8001ED40(id)->u0.field_0 >> 20) & 0xF;
}

s16 func_8001EF64(s32 id) {
    return func_8001ED40(id)->field_8;
}

u16 func_8001EF88(s32 id) {
    u16 v = func_8001ED40(id)->u0.b0.field_3 & 0xF;

    if (v == 6) {
        return (u16)Rand_Next() % 5;
    }
    return v;
}

s32 *func_8001EFF0(s32 id) {
    EntED40 *e = func_8001ED40(id);
    D_80050778 = e->field_6;
    D_8005077C = e->field_5;
    return &D_80050778;
}


u8 func_8001F020(s32 id) {
    return func_8001ED40(id)->u10.field_10b;
}

s32 func_8001F044(s32 id) {
    return func_8001ED40(id)->field_20 & 0xF;
}

s32 func_8001F068(s32 id) {
    return func_8001ED40(id)->field_18 & 0x3FFFFFF;
}

s32 func_8001F094(s32 id) {
    return func_8001ED40(id)->field_1C & 0x3FFFF;
}

s32 func_8001F0C0(s32 id) {
    return func_8001ED40(id)->u0.field_0 >> 28;
}

s32 func_8001F0E4(s32 id) {
    return (func_8001ED40(id)->u10.field_10 >> 8) & 0x7FFF;
}

s32 func_8001F10C(s32 id) {
    return func_8001ED40(id)->field_14 & 0x3FF;
}

s32 func_8001F130(s32 id) {
    return (func_8001ED40(id)->field_14 >> 10) & 0x1FFF;
}

s32 func_8001F158(s32 id) {
    return (func_8001ED40(id)->field_1C >> 18) & 0x1F;
}

s32 func_8001F180(s32 id) {
    return (func_8001ED40(id)->field_1C >> 23) & 0xFF;
}

void Anim_SetModelAnim(Actor *a, s32 n) {
    ActorModel *s = a->model;
    s32 i;
    s32 k;

    s->animId = n;
    s->animPos = 0;
    s->animData = 0;
    for (i = 10; i < 0x6F; i += 10) {
        if (n < i) {
            s->animFileId = Anim_GetModelAnimFile(a->digiId, i / 10 - 1);
            k = i - 10;
            s->animIndex = n - k;
            break;
        }
    }
    s->animTimer = 1;
    s->animDone = 0;
}

void Anim_SetModelAnimFile(Actor *arg0, s32 arg1, s32 arg2) {
    ActorModel *p = arg0->model;
    p->animId = arg1;
    p->animPos = 0;
    p->animData = 0;
    p->animFileId = arg2;
    p->animIndex = 0;
    p->animTimer = 1;
    p->animDone = 0;
}

#ifdef NORMALIZED
s32 Anim_HasModelAnim(Actor *a0, s32 n) {
    ActorModel *sub = a0->model;
    s32 id;
    s32 k;
    s32 *p;

    if (n < 10) {
        k = 0;
        n = k;
        id = Anim_GetModelAnimFile(a0->digiId, k);
    } else if (n < 20) {
        id = Anim_GetModelAnimFile(a0->digiId, 1);
        n -= 10;
    } else {
        id = Anim_GetModelAnimFile(a0->digiId, 2);
        n -= 20;
    }
    p = (s32 *)(Cd_GetFileOrNull(id) + ((sub->boneCount + 1) << 2));
    sub->animTable = p;
    return p[n] != 0;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Anim_HasModelAnim);
s32 Anim_HasModelAnim(Actor *a0, s32 n);
#endif

#ifdef NORMALIZED
void Anim_StepModelAnim(Actor *a) {
    ActorModel *s = a->model;
    s32 *data = (s32 *)Cd_GetFileOrNull(s->animFileId);
    s32 i;
    s32 j;
    s32 k;
    ModelBone *e;
    u8 *f;
    u8 *q;
    s32 pos;
    Rec18 *r;

    if (data != s->animData) {
        s->animData = data;
        s->bonePoseTables = data + 1;
        i = s->boneCount + 1;
        s->animTable = &data[i];
    }
    if (data[0] == 0) {
        data[0] = 1;
        for (k = 0; s->animTable[k] != 1; k++) {
            if (s->animTable[k] != 0) {
                s->animTable[k] += (s32)data;
            }
        }
        for (k = 0; k < s->boneCount; k++) {
            s->bonePoseTables[k] += (s32)data;
        }
    }
    s->animTimer += D_8005F770.frameDelta;
    while (s->animTimer >= 2) {
        s->animTimer -= 2;
        e = s->bones;
        f = (u8 *)s->animTable[s->animIndex];
        pos = s->animPos;
        for (i = 0; i < s->boneCount; i++) {
            e->keyIndex = f[s->animPos++];
            e++;
        }
        q = &f[s->animPos];
        if (*q & 0x80) {
            switch (*q) {
            case 0xFF:
                s->animDone = -1;
                s->animPos = pos;
                goto done;
            case 0xFE:
                s->animPos = (q[2] << 8) | q[1];
                s->animDone = -1;
                break;
            }
        }
    }
done:
    e = s->bones;
    for (i = 0; i < s->boneCount; i++) {
        r = &((Rec18 *)s->bonePoseTables[i])[e->keyIndex];
        e->localMat.m = r->m;
        for (j = 0; j < 3; j++) {
            e->localMat.t[j] = r->t[j];
        }
        e++;
    }
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Anim_StepModelAnim);
void Anim_StepModelAnim(Actor *a);
#endif

void Gfx_ResetModelBones(Actor *a0) {
    ActorModel *sub = a0->model;
    ModelBone *p = sub->bones;
    s32 i = 0;
    while (i < sub->boneCount) {
        i++;
        p->localMat = D_80043714;
        p++;
    }
}

void Gfx_AddFlatQuad3D(GfxQuadColor *col, GfxQuadVert *v, s32 flags, s32 idx) {
    Coord1F668 coord;
    Mat1F668 m;
    s32 pz;
    s32 flag;
    PolyF4_1F668 *p;
    PolyF4_1F668 *q;
    DrMode1F668 *dm;
    s32 *ot;
    SysState *g;

    GsInitCoordinate2(0, &coord);
    GsGetLs(&coord, &m);
    GsSetLsMatrix(&m);
    g = &D_8005F770;
    p = (PolyF4_1F668 *)g->packet.work;
    ot = g->otLayers.s[idx];
    p->c = *col;
    SetPolyF4((u8 *)p);
    q = p;
    if (flags & 4) {
        p->c.code |= 2;
    }
    RotTransPers(&v[0], &p->xy[0], &pz, &flag);
    p->xy[0].x /= 2;
    p->xy[0].y /= 2;
    RotTransPers(&v[1], &p->xy[1], &pz, &flag);
    p->xy[1].x /= 2;
    p->xy[1].y /= 2;
    RotTransPers(&v[2], &p->xy[2], &pz, &flag);
    p->xy[2].x /= 2;
    p->xy[2].y /= 2;
    RotTransPers(&v[3], &p->xy[3], &pz, &flag);
    p->xy[3].x /= 2;
    p->xy[3].y /= 2;
    p->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p++;
    SetDrawMode((DrMode1F668 *)p, 0, 0, (flags & 3) << 5, 0);
    dm = (DrMode1F668 *)(q + 1);
    dm->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p = (PolyF4_1F668 *)(dm + 1);
    g->packet.work = (ActorWork *)p;
}


void Gfx_InitLights(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &D_800416CC[i]);
    }
    GsSetAmbient(0x4CC, 0x4CC, 0x4CC);
    GsSetLightMode(0);
}

s32 func_8001F970(s32 arg0) {
    if (arg0 == 0x64 || arg0 == 0xA || arg0 == 0x14) {
        return 0;
    }
    if (arg0 == 0x15) {
        return 0;
    }
    return arg0 != 0x16;
}

#ifdef NORMALIZED
void Gfx_AnimateModelTex(Actor *a0) {
    ActorModel *w = a0->model;
    GfxTexAnimPart *r = (GfxTexAnimPart *)w->texAnimParts;
    GfxModelTexSlot *pos = w->texSlot;
    s32 k = 0;
    s32 j;
    s32 i;
    s32 m;
    DR_MOVE *prim;
    RECT rc;
    RECT rc2;
    GfxModelTexAnim *q;
    u8 n;

    if (r->dstX != 0xFF) {
        if (func_8001F970(w->animId) != 0) {
            switch (w->blinkTimer >> 1) {
            case 0:
                w->blinkTimer = (Rand_Next() & 0x7F) + 0x3C;
                k = 0;
                break;
            case 1:
            case 2:
            case 5:
            case 6:
                k = 2;
                break;
            case 3:
            case 4:
                k = 4;
                break;
            }
            if ((w->blinkTimer -= D_8005F770.frameDelta) < 0) {
                w->blinkTimer = 0;
            }
        } else {
            k = 4;
            w->blinkTimer = 0;
        }
    }
    w->texAnimTimer += D_8005F770.frameDelta;
    while (1) {
        if (w->texAnimTimer < 0x18) break;
        w->texAnimTimer -= 0x18;
    }
    j = (w->texAnimTimer / 8) * 2;
    prim = D_8005F770.packet.drMove;
    for (i = 0; i < 10; i++, r++) {
        if (i < 2) {
            if (r->dstX == 0xFF) continue;
        } else {
            if (r->dstX == 0xFF) break;
            if (r->dstX == 0xFE) break;
        }
        if (i < 2) {
            rc.x = r->uv[k] + pos->vramX;
            rc.y = r->uv[k + 1] + pos->vramY;
        } else {
            rc.x = r->uv[j] + pos->vramX;
            rc.y = r->uv[j + 1] + pos->vramY;
        }
        rc.w = r->w;
        rc.h = r->h;
        SetDrawMove(prim, &rc, r->dstX + pos->vramX, r->dstY + pos->vramY);
        AddPrim(D_8005F770.otLayers.u[6], (unsigned int *)prim);
        prim++;
    }
    if (r->dstX == 0xFE) {
        q = (GfxModelTexAnim *)&r->dstY;
        for (i = 0; i < 10; i++, q++) {
            if (q->dstX == 0xFF) break;
            if (D_8005F770.frameDelta == 1) {
                q->timer += 1;
            } else {
                q->timer += 2;
            }
            n = q->period;
            while (1) {
                if (q->timer < n) break;
                q->timer -= n;
            }
            m = (q->timer >> 1) * 4;
            rc2.x = q->uv[m] + pos->vramX;
            rc2.y = q->uv[m + 1] + pos->vramY;
            rc2.w = q->w;
            rc2.h = q->h;
            SetDrawMove(prim, &rc2, q->dstX + pos->vramX, q->dstY + pos->vramY);
            AddPrim(D_8005F770.otLayers.u[6], (unsigned int *)prim);
            prim++;
            rc2.x = q->uv[m + 2] + pos->vramX;
            rc2.y = q->uv[m + 3] + pos->vramY;
            rc2.w = q->w2;
            rc2.h = q->h2;
            SetDrawMove(prim, &rc2, q->dstX2 + pos->vramX, q->dstY2 + pos->vramY);
            AddPrim(D_8005F770.otLayers.u[6], (unsigned int *)prim);
            prim++;
        }
    }
    D_8005F770.packet.addr = (s32)prim;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_AnimateModelTex);
void Gfx_AnimateModelTex(Actor *a0);
#endif


ActorModel *Gfx_AttachModel(Actor *a0, s32 id) {
    s32 fresh = 0;
    GfxModelFile *m = (GfxModelFile *)Cd_GetFileOrNull(id);
    GfxModelFile *base = m;
    ActorModel *t = a0->model;
    ActorModel *s;
    s32 i;
    ModelQuadSection *p;
    ModelQuadSection *q;
    GfxModelTriSec *r;
    s32 v;
    Ent1FDBC20 *e;

    if (t == NULL) {
        a0->model = (ActorModel *)Mem_Alloc(0x7C, 2);
        Mem_Zero(a0->model, 0x7C);
        fresh = 1;
    } else if (t->file == m && m->relocated != 0) {
        return t;
    }
    s = a0->model;
    s->fileId = id;
    s->file = base;
    s->boneCount = m->count;
    s->boneVerts = (s16 **)base->tables;
    s->boneNormals = s->boneVerts + s->boneCount;
    s->bonePolys = (ModelQuadSection **)(s->boneNormals + s->boneCount);
    s->boneDepths = (s32 *)(s->bonePolys + s->boneCount);
    s->texAnimParts = s->boneDepths + s->boneCount;
    if (m->relocated == 0) {
        for (i = 0; i < s->boneCount; i++) {
            s->boneVerts[i] = (s16 *)((s32)s->boneVerts[i] + (s32)base);
            s->boneNormals[i] = (s16 *)((s32)s->boneNormals[i] + (s32)base);
            s->bonePolys[i] = (ModelQuadSection *)((s32)s->bonePolys[i] + (s32)base);
        }
        m->relocated = 1;
    }
    if (fresh) {
        s->maxVerts = 0;
        s->maxNormals = 0;
        for (i = 0; i < s->boneCount; i++) {
            if (s->maxVerts < *s->boneVerts[i]) {
                s->maxVerts = *s->boneVerts[i];
            }
            if (s->maxNormals < *s->boneNormals[i]) {
                s->maxNormals = *s->boneNormals[i];
            }
        }
        s->field_28 = 0;
        for (i = 0; i < s->boneCount; i++) {
            p = s->bonePolys[i];
            e = p->e;
            q = (ModelQuadSection *)(e + p->n);
            e = q->e;
            r = (GfxModelTriSec *)(e + q->n);
            v = r->e[r->n].v[0];
            if (s->field_28 < v) {
                s->field_28 = v;
            }
        }
        s->bones = (ModelBone *)Mem_Alloc(s->boneCount * sizeof(ModelBone), 2);
        s->screenXY = (s32 *)Mem_Alloc(s->maxVerts * 4, 2);
        s->vertOtz = (s32 *)Mem_Alloc(s->maxVerts * 4, 2);
        s->vertColors = (s32 *)Mem_Alloc(s->maxNormals * 4, 2);
    }
    return s;
}

void Gfx_CalcModelBoneMatrices(Actor *a0) {
    CoordMatrix cam;
    Mat1F668 light;
    ActorModel *s;
    ActorTransformView *o;
    ModelBone *d;
    GfxBoneScratchNode *sp;
    GfxBoneScratchNode *e;
    Blk20 *r;
    Blk20 *in;
    Blk20 *out;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    s = a0->model;
    o = a0->u38.ptr38;
    d = s->bones;
    cam = D_80061A08;
    light = D_800619A8;
    sp = (GfxBoneScratchNode *)0x1F800000;
    sp[0].parent = 0;
    sp[0].local = o->matrix;
    sp[0].local.t[0] = o->posX;
    sp[0].local.t[1] = o->posY;
    sp[0].local.t[2] = o->posZ;
    sp[0].world.m = sp[0].local;
    for (i = 1; i < 9; i++) {
        sp[i].parent = &sp[i - 1];
    }
    n = s->boneCount;
    for (j = 0; j < n; j++, d++) {
        e = &sp[s->boneDepths[j] + 1];
        e->local = d->localMat;
        for (k = 0; k < 3; k++) {
            switch (k) {
            default:
            case 0:
                r = &e->parent->world.m;
                in = &e->local;
                out = &e->world.m;
                break;
            case 1:
                r = (Blk20 *)&cam;
                in = &e->world.m;
                out = &d->viewMat;
                break;
            case 2:
                r = (Blk20 *)&light;
                in = &e->world.m;
                out = &d->lightMat;
                break;
            }
            gte_SetRotMatrix(r);
            gte_ldclmv(&in->m.m[0][0]);
            gte_rtir();
            if (k == 1) {
                d->worldM0 = e->world.w[0];
                d->worldM1 = e->world.w[1];
            }
            gte_stclmv(&out->m.m[0][0]);
            gte_ldclmv(&in->m.m[0][1]);
            gte_rtir();
            if (k == 1) {
                d->worldM2 = e->world.w[2];
                d->worldM3 = e->world.w[3];
            }
            gte_stclmv(&out->m.m[0][1]);
            gte_ldclmv(&in->m.m[0][2]);
            gte_rtir();
            if (k == 1) {
                d->worldM4 = e->world.w[4];
                d->worldTx = e->world.w[5];
            }
            gte_stclmv(&out->m.m[0][2]);
            gte_SetTransMatrix(r);
            gte_ldlv0(in->t);
            gte_rtv0tr();
            if (k == 1) {
                d->worldTy = e->world.w[6];
                d->worldTz = e->world.w[7];
            }
            gte_stlvnl(out->t);
        }
    }
}


void Gfx_DrawTexModel(Actor *a0, s32 mode) {
    ActorModel *s;
    ModelBone *e;
    ModelQuadSection *p;
    ModelQuadGT4 *q;
    GfxModelTriGT3 *r;
    s32 i;
    s32 j;
    s32 n;

    s = a0->model;
    i = 0;
    e = s->bones;
    s->texSlot = (struct GfxModelTexSlot *)Gfx_FindOrLoadTexSlot(s->fileId << 16);
    s->otzShift = D_8005F770.otLayerLen[s->otIndex] - 2;
    for (; i < s->boneCount; i++, e++) {
        p = s->bonePolys[i];
        gte_SetRotMatrix(&e->viewMat);
        gte_SetTransMatrix(&e->viewMat);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->boneVerts[i], (ModelProjView *)s, mode) != 0) {
            continue;
        }
        gte_SetLightMatrix(&e->lightMat);
        Gfx_CalcNormalColors((Vert6Pmv *)s->boneNormals[i], (ModelProjView *)s);
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = (ModelQuadGT4 *)p->e;
            if (n != 0) {
                if (s->field_34 == 1) {
                    Gfx_AddQuadsGT4(q, n, s, 2);
                } else {
                    Gfx_AddQuadsGT4(q, n, s, j);
                }
                q += n;
            }
            p = (ModelQuadSection *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = (GfxModelTriGT3 *)((GfxModelTriSec *)p)->e;
            if (n != 0) {
                if (s->field_34 == 1) {
                    func_80020FD0(r, n, s, 2);
                } else {
                    func_80020FD0(r, n, s, j);
                }
                r += n;
            }
            p = (ModelQuadSection *)r;
        }
    }
    Gfx_AnimateModelTex(a0);
}


void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col) {
    ActorModel *s;
    ModelBone *e;
    ModelQuadSection *p;
    Ent1FDBC20 *q;
    GfxModelTri *r;
    s32 i;
    s32 j;
    s32 n;

    i = 0;
    s = a0->model;
    e = s->bones;
    s->otzShift = D_8005F770.otLayerLen[s->otIndex] - 2;
    for (; i < s->boneCount; i++, e++) {
        p = s->bonePolys[i];
        gte_SetRotMatrix(&e->viewMat);
        gte_SetTransMatrix(&e->viewMat);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->boneVerts[i], (ModelProjView *)s, mode) != 0) {
            continue;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = p->e;
            if (n != 0) {
                Gfx_DrawWireQuads((GfxModelQuad *)q, n, (ModelProjView *)s, col);
                q += n;
            }
            p = (ModelQuadSection *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = ((GfxModelTriSec *)p)->e;
            if (n != 0) {
                Gfx_DrawWireTris((ModelWireTri *)r, n, (ModelProjView *)s, col);
                r += n;
            }
            p = (ModelQuadSection *)r;
        }
    }
}


extern void RotMatrixYXZ(void *, Obj209 *);
extern void ScaleMatrix(Obj209 *, s32 *);

void Actor_UpdateTransform(Actor *arg0) {
    Obj209 *obj = (Obj209 *)arg0->u38.ptr38;
    s32 local[3];

    obj->prevPos = obj->pos;
    RotMatrixYXZ(&obj->rot, obj);
    ApplyMatrixLV((CoordMatrix *)obj, &obj->moveX, local);
    obj->pos.x += local[0];
    obj->pos.y += local[1];
    obj->pos.z += local[2];
    if (obj->scaleX == 0x1000 && obj->scaleY == obj->scaleX &&
        obj->scaleZ == obj->scaleY) {
    } else {
        ScaleMatrix(obj, &obj->scaleX);
    }
    obj->moveZ = 0;
    obj->moveY = 0;
    obj->moveX = 0;
}

s32 Actor_ProjectToScreen(ContC40 *a0) {
    Mat1F668 m;
    AllocC40 *p;
    LongVec3 *t;
    s32 x, y;

    p = a0->transform;
    t = &p->t;
    *t = *(LongVec3 *)&p->posX;
    gte_SetRotMatrix(&D_80061A08);
    gte_ldclmv(&p->m[0][0]);
    gte_rtir();
    gte_stclmv(&m.m[0][0]);
    gte_ldclmv(&p->m[0][1]);
    gte_rtir();
    gte_stclmv(&m.m[0][1]);
    gte_ldclmv(&p->m[0][2]);
    gte_rtir();
    gte_stclmv(&m.m[0][2]);
    gte_SetTransMatrix(&D_80061A08);
    gte_ldlv0(t);
    gte_rtv0tr();
    gte_stlvnl(m.t);
    gte_SetRotMatrix(&m);
    gte_SetTransMatrix(&m);
    gte_ldv0(D_80050744);
    gte_rtps();
    gte_stsxy(&p->screenX);
    x = 0x160;
    y = 0x110;
    if (p->screenX < -x) return 1;
    if (p->screenX > x) return 1;
    if (p->screenY < -y) return 1;
    return p->screenY > y;
}


void Actor_RefreshTransform(s32 arg0) {
    Actor_UpdateTransform(arg0);
    Actor_ProjectToScreen(arg0);
}

extern void Mem_Zero(void *, s32);

void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2) {
    AllocC40 *p;
    if (a0->transform == 0) {
        a0->transform = (AllocC40 *)Mem_Alloc(0x90, 2);
    }
    Mem_Zero(a0->transform, 0x90);
    p = a0->transform;
    p->scaleZ = 0x1000;
    p->scaleY = 0x1000;
    p->scaleX = 0x1000;
    if (a1 != 0) {
        p->posX = a1[0];
        p->posY = a1[1];
        p->posZ = a1[2];
    }
    p->rotY = a2;
    Actor_RefreshTransform((s32)a0);
}

void Actor_StepAxisMotion(AxisMotion *a0, s32 a1) {
    s32 v = a0->speed + a0->accel;
    a0->speed = v;
    if (v > 0) {
        if (v >= a0->maxSpeed) {
            a0->speed = a0->maxSpeed;
        }
    } else if (a1 == 0) {
        a0->maxSpeed = 0;
        a0->accel = 0;
        a0->speed = 0;
    } else {
        if (v >= a0->maxSpeed) {
            a0->speed = -a0->maxSpeed;
        }
    }
}

#ifdef NORMALIZED
s32 func_80020D54(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->transform;
    AxisMotion *e = &p->axisMotion[i];

    if (i != 1) {
        Actor_StepAxisMotion(e, 0);
    } else {
        Actor_StepAxisMotion(e, 1);
    }
    if (i != 2) {
        p->moveDelta[i] += e->speed >> 8;
    } else {
        p->moveDelta[2] -= e->speed >> 8;
    }
    return e->speed >> 8;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020D54);
s32 func_80020D54(ContC40 *a0, s32 i);
#endif

#ifdef NORMALIZED
s32 func_80020E00(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->transform;
    AxisMotion *e = &p->axisMotion[i];

    Actor_StepAxisMotion(e, 0);
    switch (i) {
    case 0:
    case 1:
        p->moveDelta[i] -= e->speed >> 8;
        break;
    case 2:
        p->moveDelta[2] += e->speed >> 8;
        break;
    }
    return e->speed >> 8;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020E00);
s32 func_80020E00(ContC40 *a0, s32 i);
#endif

void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->speed = arg2->speed;
    e->accel = arg2->accel;
    e->maxSpeed = arg2->maxSpeed;
}

void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->maxSpeed = 0;
    e->accel = 0;
    e->speed = 0;
}

void Gfx_CalcNormalColors(Vert6Pmv *v, ModelProjView *o) {
    s32 n;
    CVECTOR *c;
    s32 i;

    n = v->vx;
    c = o->vertColors;
    v++;
    if (o->field_34 != 0) {
        for (i = 0; i < n; i++) {
            *c = o->flatColor;
            c++;
        }
        return;
    }
    gte_ldv0u(v);
    gte_ncs();
    gte_strgb(c);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_ncs();
        v++;
        c++;
        i++;
        gte_strgb(c);
    }
}

#ifdef NORMALIZED
void func_80020FD0(GfxModelTriGT3 *t, s32 n, ActorModel *s, s32 mode) {
    s32 sxy[3];
    s32 opz;
    s32 *xy;
    s32 *sz;
    CVECTOR *col;
    GfxTexSlot *tex;
    s32 idx;
    u8 code;
    PolyGT3_20FD0 *p;
    s32 i;
    s32 z;
    SysState *g;

    xy = s->screenXY;
    col = (CVECTOR *)s->vertColors;
    sz = s->vertOtz;
    tex = (GfxTexSlot *)s->texSlot;
    idx = s->otIndex;
    code = 0x36;
    if (mode == 1) {
        code = 0x34;
    }
    g = &D_8005F770;
    p = (PolyGT3_20FD0 *)g->packet.work;
    for (i = 0; i < n; i++, t++) {
        sxy[0] = xy[t->v[0]];
        sxy[1] = xy[t->v[1]];
        sxy[2] = xy[t->v[2]];
        gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
        gte_nclip();
        if (sxy[0] == sxy[1] || sxy[0] == sxy[2] || sxy[1] == sxy[2]) {
            continue;
        }
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        p->tag.len = 9;
        p->c0.code = 0x34;
        p->xy0 = sxy[0];
        p->xy1 = sxy[1];
        p->xy2 = sxy[2];
        p->c0 = col[t->c[0]];
        p->c1 = col[t->c[1]];
        p->c2 = col[t->c[2]];
        p->c0.code = code;
        z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
        if (mode == 2) {
            p->tpage = tex->tpage | s->field_36;
        } else {
            p->tpage = tex->tpage | t->tpage;
        }
        p->clut = t->clut + (((tex->vramY + s->field_34) << 6) | ((tex->vramX >> 4) & 0x3F));
        p->u0 = t->u0 + tex->uOffset;
        p->u1 = t->u1 + tex->uOffset;
        p->u2 = t->u2 + tex->uOffset;
        p->v0 = t->v0;
        p->v1 = t->v1;
        p->v2 = t->v2;
        p->tag.addr = ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr;
        ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr = (u32)p;
        p++;
        z = t->v[2];
    }
    D_8005F770.packet.addr = (s32)p;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020FD0);
void func_80020FD0(GfxModelTriGT3 *t, s32 n, ActorModel *s, s32 mode);
#endif


#ifdef NORMALIZED
void Gfx_AddQuadsGT4(ModelQuadGT4 *t, s32 n, ActorModel *s, s32 mode) {
    s32 sxy[4];
    s32 opz;
    s32 *xy;
    s32 *sz;
    CVECTOR *col;
    GfxTexSlot *tex;
    s32 idx;
    u8 code;
    PolyGT4_2130C *p;
    s32 i;
    s32 z;
    SysState *g;

    tex = (GfxTexSlot *)s->texSlot;
    xy = s->screenXY;
    col = (CVECTOR *)s->vertColors;
    sz = s->vertOtz;
    idx = s->otIndex;
    code = 0x3E;
    if (mode == 1) {
        code = 0x3C;
    }
    g = &D_8005F770;
    p = (PolyGT4_2130C *)g->packet.work;
    for (i = 0; i < n; i++, t++) {
        sxy[0] = xy[t->v[0]];
        sxy[1] = xy[t->v[1]];
        sxy[2] = xy[t->v[2]];
        sxy[3] = xy[t->v[3]];
        gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
        gte_nclip();
        if (sxy[0] == sxy[1] || sxy[0] == sxy[2] || sxy[0] == sxy[3] ||
            sxy[1] == sxy[2] || sxy[1] == sxy[3] || sxy[2] == sxy[3]) {
            continue;
        }
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        p->tag.len = 12;
        p->c0.code = 0x3C;
        p->xy0 = sxy[0];
        p->xy1 = sxy[1];
        p->xy2 = sxy[2];
        p->xy3 = sxy[3];
        p->c0 = col[t->c[0]];
        p->c1 = col[t->c[1]];
        p->c2 = col[t->c[2]];
        p->c3 = col[t->c[3]];
        p->c0.code = code;
        z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]] + sz[t->v[3]]) / 4;
        if (mode == 2) {
            p->tpage = tex->tpage | s->field_36;
        } else {
            p->tpage = tex->tpage | t->tpage;
        }
        p->clut = t->clut + (((tex->vramY + s->field_34) << 6) | ((tex->vramX >> 4) & 0x3F));
        p->u0 = t->u0 + tex->uOffset;
        p->u1 = t->u1 + tex->uOffset;
        p->u2 = t->u2 + tex->uOffset;
        p->u3 = t->u3 + tex->uOffset;
        p->v0 = t->v0;
        p->v1 = t->v1;
        p->v2 = t->v2;
        p->v3 = t->v3;
        p->tag.addr = ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr;
        ((GfxModelOTag *)&g->otLayers.s[idx][z])->addr = (u32)p;
        p++;
    }
    D_8005F770.packet.addr = (s32)p;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_AddQuadsGT4);
void Gfx_AddQuadsGT4(ModelQuadGT4 *t, s32 n, ActorModel *s, s32 mode);
#endif


s32 Gfx_ProjectModelVerts(Vert6Pmv *v, ModelProjView *o, s32 noCheck) {
    s32 otz;
    s32 flag;
    s32 n;
    SxyPmv *sxy;
    s32 *z;
    s32 zs;
    s32 xs;
    s32 ys;
    s32 i;
    SysState *scr;

    n = v->vx;
    v++;
    scr = &D_8005F770;
    sxy = (SxyPmv *)o->screenXY;
    z = o->vertOtz;
    zs = o->otzShift;
    xs = scr->centerX.s != 320;
    ys = scr->centerY.s != 240;
    gte_ldv0u(v);
    gte_rtps();
    gte_stsxy(sxy);
    gte_stszotz(&otz);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_rtps();
        v++;
        i++;
        *z = otz >> zs;
        z++;
        sxy->vx >>= xs;
        sxy->vy >>= ys;
        sxy++;
        gte_stsxy(sxy);
        gte_stszotz(&otz);
        if (!noCheck) {
            gte_stflg(&flag);
            if (flag < 0) {
                return 1;
            }
        }
    }
    *z = otz >> zs;
    sxy->vx >>= xs;
    sxy->vy >>= ys;
    return 0;
}

s32 Gfx_IsOriginOffscreen(void) {
    SxyIso sxy;
    s32 flag;

    gte_ldv0(D_80043704);
    gte_rtps();
    gte_stflg(&flag);
    if (flag < 0) {
        return 1;
    }
    gte_stsxy(&sxy);
    if (sxy.vx < -0x160) {
        return 1;
    }
    if (sxy.vx > 0x160) {
        return 1;
    }
    if (sxy.vy < -0x110) {
        return 1;
    }
    return sxy.vy > 0x110;
}

#ifdef NORMALIZED
void Gfx_DrawWireTris(ModelWireTri *t, s32 n, ModelProjView *o, CVECTOR *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 *sxy;
    s32 *sz;
    GfxModelOTag *pk;
    LINE_F4 *l;
    Tpage21ABC *tp;
    s32 idx;

    pk = (GfxModelOTag *)D_8005F770.packet.work;
    sxy = o->screenXY;
    sz = o->vertOtz;
    idx = o->otIndex;
    for (i = 0; i < n; i++, t++) {
        do {
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
            ot = (u32 *)D_8005F770.otLayers.s[idx];
            l = (LINE_F4 *)pk;
            l->c = *col;
            l->tag.len = 6;
            l->c.code = 0x4E;
            l->end = 0x55555555;
            l->xy[3] = l->xy[0] = sxy[t->v[0]];
            l->xy[1] = sxy[t->v[1]];
            l->xy[2] = sxy[t->v[2]];
            ot += z;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F4 *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F770.packet.addr = (s32)pk;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_DrawWireTris);
void Gfx_DrawWireTris(ModelWireTri *t, s32 n, ModelProjView *o, CVECTOR *col);
#endif

#ifdef NORMALIZED
void Gfx_DrawWireQuads(GfxModelQuad *q, s32 n, ModelProjView *o, CVECTOR *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 xy[4];
    s32 *sxy;
    s32 *sz;
    GfxModelOTag *pk;
    LINE_F4 *l4;
    LINE_F2 *l2;
    Tpage21ABC *tp;
    s32 idx;

    pk = (GfxModelOTag *)D_8005F770.packet.work;
    sxy = o->screenXY;
    sz = o->vertOtz;
    idx = o->otIndex;
    for (i = 0; i < n; i++, q++) {
        do {
            z = (sz[q->v[0]] + sz[q->v[1]] + sz[q->v[2]] + sz[q->v[3]]) / 4;
            ot = (u32 *)D_8005F770.otLayers.s[idx];
            xy[0] = sxy[q->v[0]];
            xy[1] = sxy[q->v[1]];
            xy[2] = sxy[q->v[2]];
            xy[3] = sxy[q->v[3]];
            l4 = (LINE_F4 *)pk;
            l4->c = *col;
            l4->tag.len = 6;
            l4->c.code = 0x4E;
            l4->end = 0x55555555;
            l4->xy[0] = xy[0];
            l4->xy[1] = xy[1];
            l4->xy[2] = xy[3];
            l4->xy[3] = xy[2];
            do {
            } while (0);
            ot += z;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F4 *)pk + 1);
            l2 = (LINE_F2 *)pk;
            l2->c = *col;
            l2->tag.len = 3;
            l2->c.code = 0x42;
            l2->xy[0] = xy[2];
            l2->xy[1] = xy[0];
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((LINE_F2 *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((GfxModelOTag *)ot)->addr;
            ((GfxModelOTag *)ot)->addr = (u32)pk;
            pk = (GfxModelOTag *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F770.packet.addr = (s32)pk;
}
#else
INCLUDE_ASM("asm/USA/main/nonmatchings/156C", Gfx_DrawWireQuads);
void Gfx_DrawWireQuads(GfxModelQuad *q, s32 n, ModelProjView *o, CVECTOR *col);
#endif
