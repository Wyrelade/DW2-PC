#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"

/* Small data this unit defines (.sdata). Retail reaches it with %gp_rel here. */
Halves Menu_ItemMsgPos = { 0x10, 0xBA };
Halves Menu_ItemNamePos = { 0x67, 0x32 };

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_ItemInit(Actor *arg0, s16 arg1);
void Menu_ItemTask(Actor *a0);
void Menu_ItemDraw(Actor *actor);

/* Sub tasks the item menu opens: { task id, Task_Create argument }. */
Pair61900 Menu_ItemSubTasks[] = { { 0x0E, 2 }, { 0x10, 3 } };
TaskDesc D_80040F04 = {
    (TaskInitFn)Menu_ItemInit, Menu_ItemTask, Task_DefaultDestroy, Menu_ItemDraw, 0x744, 4,
};

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
            c->itemId = Save_GameStatePtr->bagItems[i];
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
                if (Item_GetCategory(id) == 0x1F) {
                    continue;
                }
            } else if (Item_GetCategory(id) != 0x1F) {
                continue;
            }
            if (Save_GameStatePtr->storageCounts[id] != 0) {
                c->itemId = id;
                q->count = Save_GameStatePtr->storageCounts[id];
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
        Save_GameStatePtr->storageCounts[id] += (Save_GameStatePtr->storageCounts[id] + 1 < 100);
        Item_RemoveFromBag(c->bagSlot);
        st.pos = Menu_ItemMsgPos;
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
            if (Save_GameStatePtr->bagItems[i] == 0) {
                break;
            }
        }
        if (i == n) {
            Text_OpenPacked(&w->msgTextSlot, (s32)Cd_GetFileEntry(0x1FD0124), 0x81, Menu_ItemMsgPos);
            snd = 0x10;
        } else {
            Save_GameStatePtr->bagItems[i] = c->itemId;
            Save_GameStatePtr->storageCounts[c->itemId]--;
            st.pos = Menu_ItemMsgPos;
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
            Text_OpenPacked(&o->nameText, Item_GetNameText(id), 0, Menu_ItemNamePos);
        }
        Text_OpenPacked(o->descText, Item_GetDescText(id), 0x80, Menu_ItemMsgPos);
    }
}

void Menu_ItemInit(Actor *arg0, s16 arg1) {
    arg0->work->menuMode = arg1;
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
                Text_OpenPacked(&w->msgTextSlot, (s32)Cd_GetFileEntry(((s32)((u16)w->menuMode << 16) >> 16) + 0x1FD011D), 0x80, Menu_ItemMsgPos);
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
            } else if (Pad_State[0].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 2);
            } else if (Pad_State[0].cross > 0) {
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
                Task_Create(Menu_ItemSubTasks[w->nextTaskIdx].field_0, slot, Menu_ItemSubTasks[w->nextTaskIdx].field_2);
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
                r = Text_WaitYesNo(w->descText);
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
                if (Pad_State[0].triangle > 0 || Pad_State[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
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
            Text_OpenPacked(&w->msgTextSlot, (s32)Cd_GetFileEntry(id), 0x81, Menu_ItemMsgPos);
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

void Menu_ItemDraw(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 k;
    s32 f;
    u16 m;
    Pair54 tmp;

    if (w->fade == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130019);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            tmp = w->itemCursor;
            f = w->itemCursor.field_0 + 1;
            Gfx_SetPartsNumber(obj, 0x10, 2, f ? f : 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->itemGridSize ? w->itemGridSize : 1);
            tmp.field_0 = w->itemCursor.field_0 - w->scrollRow;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->itemGridSize);
            Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
            k = Menu_BlinkOrHideParts(obj, 8, w->scrollRow);
            k |= Menu_BlinkOrHideParts(obj, 4, w->itemGridSize - w->scrollRow - 2);
            if (w->hasItems == 0) {
                k |= 0xE;
            }
            Gfx_HidePartsByMask(obj, k);
            break;
        case 1:
            f = w->menuMode;
            if (f < 3) {
                m = 2;
            } else {
                m = 0xFFFF;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        case 3:
            m = 0xFFFF;
            if (w->menuMode == 3 || w->menuMode == 5) {
                m = 1;
            } else if (w->menuMode == 4) {
                m = 2;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->fade);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}
