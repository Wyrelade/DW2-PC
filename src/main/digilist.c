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
#include "main/itemmenu.h"

/* Small data this unit defines: initialised ones go to .sdata, the rest to .sbss in
 * game.h's order. Retail reaches them with %gp_rel here. */
Halves Menu_DigiMsgPos = { 0x10, 0xBA };
Halves Menu_DigiListCursorTextPos = { 0x21, 0x9E };

/* Task callbacks the descriptor below names (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_SetDigiListMode(Actor *a, s16 mode);
void Menu_DigiListTask(Actor *a0);
void Menu_DigiListDraw(Actor *actor);

MenuGridLayout Menu_DigiListGrid = { { 1, 1 }, { -60, -66, 0, 0x21 } };
/* Sub tasks the digimon list opens: { task id, Task_Create argument }. */
Pair61900 Menu_DigiListSubTasks[] = { { 0x11, 1 }, { 0x12, 1 }, { 0x10, 6 }, { 0x10, 8 } };
Halves Menu_DigiListTitlePos[] = { { 0x0E, 0x32 }, { 0x15, 0x32 } };
u16 Menu_DigiListRowMasks[] = { 0x0E04, 0x0E04, 0x0C04, 0x0A04, 0x0604 };
TaskDesc Menu_DigiListDesc = {
    (TaskInitFn)Menu_SetDigiListMode, Menu_DigiListTask, Task_DefaultDestroy, Menu_DigiListDraw, 0x1A8, 4,
};

void Menu_DigiTransferPlace(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e;
    DigiRosterSwapRec *g;
    MenuDigiPickRow *d;
    DigiRosterSwapRec tmp;
    u8 k;
    s32 id;
    s32 n;

    e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    n = Pad_State[0].cross;
    g = (DigiRosterSwapRec *)Menu_Ctx->field_128;
    if (n > 0) {
        switch (e->kind) {
        case 0:
        default:
            if (g->state >= 3) {
                id = 0x1FD0111;
            icon:
                Text_OpenPacked(w->msgText, Cd_GetFileEntry(id), 0x81, Menu_DigiMsgPos);
                break;
            }
            g->state = w->pickedIndices[3] != 0 ? 1 : 2;
            d = &w->rows[w->cursor[1]];
            d->kind = 1;
            d->record = (s32)g;
            d->pickState = g->state;
            Text_OpenPacked(w->msgText, Cd_GetFileEntry(0x1FD0110), 0x81, Menu_DigiMsgPos);
            Menu_Ctx->field_126 = -1;
            Menu_DigiListDrawRows((MenuDigiListRowsView *)w, 0);
            Snd_PlayById(0xE, 0);
            Task_SetState1(a0, 4);
            return;
        case 1:
            k = g->state;
            tmp = *(DigiRosterSwapRec *)e->record;
            g->state = tmp.state;
            tmp.state = k;
            *(DigiRosterSwapRec *)e->record = *g;
            *g = tmp;
            Text_OpenPacked(w->msgText, Cd_GetFileEntry(0x1FD0112), 0x81, Menu_DigiMsgPos);
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
            Text_OpenPacked(w->msgText, Cd_GetFileEntry(0x1FD011F), 0x81, Menu_DigiMsgPos);
            Task_SetState1(a0, 5);
            return;
        case 2:
            break;
        }
        Snd_PlayById(0x10, 0);
    }
}

void Menu_DigiTransferPickSrc(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    s32 k;

    if (Pad_State[0].cross > 0) {
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

void Menu_ConfirmMultiPick(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    s32 k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
    MenuDigiPickRow *e = &w->rows[k];
    s32 i;

    if (Pad_State[0].cross > 0) {
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
            MenuCtx *d = Menu_Ctx;
            d->pickCount = w->pickMax;
            for (i = 0; i < w->pickMax; i++) {
                e = &w->rows[w->pickedIndices[i]];
                d->pickedRecords[i] = e->record;
            }
            w->field_62 = 2;
            Task_SetState1(a0, 3);
        }
    }
}

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
        ((WorkElem8 *)((u8 *)w + 0x6C))[v].pickState = 2;
        w->picks[w->pickCount] = 0;
        Snd_PlayById(0xB, 0);
        Task_SetState1(s0, 1);
    }
}

void Menu_UseItemOnDigi(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    MenuDigiPickRow *e = &w->rows[Menu_GridIndexColMajor(w->cursor, w->gridSize)];
    TextDescHalves st;

    if (Pad_State[0].cross > 0) {
        if (e->kind == 1 && Item_Use(Menu_Ctx->itemId, Menu_Ctx->bagSlot, 0, e->record) != 0) {
            st.pos = Menu_DigiMsgPos;
            st.color = 0;
            st.packedStyle = 0x81;
            st.text = (s32)Cd_GetFileEntry(0x1FD00FD);
            st.strArg0 = Item_GetNameText(Menu_Ctx->itemId);
            Text_OpenDesc(w->msgText, (TextDesc *)&st);
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

    st.pos = Menu_DigiMsgPos;
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
    Text_OpenDesc(w->msgText, (TextDesc *)&st);
}

void Menu_ConfirmSinglePick(Actor *a0) {
    MenuDigiPickWork *w = (MenuDigiPickWork *)a0->work;
    s32 k;
    s32 c;

    if (Pad_State[0].cross > 0) {
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

void Menu_BuildDigiList(MenuDigiListBuildWork *w) {
    MenuDigiListBuildRow *r = w->rows;
    DigiRosterEntry *el = Save_GameStatePtr->elems;
    s32 n = 0;
    s32 i;
    s32 ok;
    MenuDigiListBuildRow *t;

    for (i = 0, t = r; i < 0x26; i++) {
        t->field_2 = 0;
        t->kind = 0;
        t++;
    }
    w->gridCols = 1;
    switch (w->mode) {
    default:
        w->rowCount = Beetle_GetDigiCapacity();
        break;
    case 2:
        w->rowCount = 0x18;
        break;
    case 7:
    case 8:
        if (w->parity == 0) {
            w->rowCount = Beetle_GetDigiCapacity();
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
                if (w->parity == 0 ? el->state >= 2 : el->state == 1) ok = -1;
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
        switch (w->mode) {
        case 2:
        case 5:
            break;
        default:
            r = &w->rows[w->rowCount - 1];
            for (i = 0; i < Dung_StatePtr->memBugCount; i++, r--) {
                r->kind = 2;
                r->bugLevel = Dung_StatePtr->memBugLevels[i];
            }
            break;
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
            st.text = (s32)Cd_GetFileEntry(rec->memBugLevel + 0x1FD00F5);
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
        { s16 t = Menu_Ctx->subMenuCursor - 7; w->parity = (w->mode + t) & 1; }
        break;
    }
}

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
        w->grid = Menu_DigiListGrid;
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
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD00D3), 0x80, Menu_DigiMsgPos);
                Task_NextState1(a0);
                break;
            case 3:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD009E), 0x80, Menu_DigiMsgPos);
                Task_NextState1(a0);
                break;
            case 4:
                Menu_PickUseItemDirect(a0);
                Task_SetState1(a0, 4);
                break;
            case 5:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(w->pickCount + 0x1FD0109), 0x80, Menu_DigiMsgPos);
                Task_NextState1(a0);
                break;
            case 6:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD010C), 0x80, Menu_DigiMsgPos);
                Task_SetState1(a0, 5);
                break;
            case 7:
            case 8:
                Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(w->mode + 0x1FD0107), 0x80, Menu_DigiMsgPos);
                id = 0x1FD0072;
                if (w->parity != 0) {
                    id = 0x1FD009A;
                }
                Text_OpenPacked(&w->titleText, (s32)Cd_GetFileEntry(id), 0, Menu_DigiListTitlePos[w->parity]);
                Task_NextState1(a0);
                break;
            }
            if (w->showCursor != 0) {
                Text_OpenPacked(&w->cursorText, (s32)Cd_GetFileEntry(0x1FD00FA), 0, Menu_DigiListCursorTextPos);
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->grid.gridSize) == 0) {
                if (Pad_State[0].triangle > 0) {
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
                        Menu_DigiTransferPickSrc(a0);
                        break;
                    case 8:
                        Menu_DigiTransferPlace(a0);
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
                Task_Create(Menu_DigiListSubTasks[w->subTask].field_0, slot, Menu_DigiListSubTasks[w->subTask].field_2);
                Task_NextState2(a0);
                break;
            case 3:
                if (*slot != 0) {
                    break;
                }
                switch (w->mode) {
                default:
                    Task_SetState1(a0, 0);
                    break;
                case 1:
                case 2:
                    if (Menu_Ctx->confirmed == 0) {
                        Task_SetState1(a0, 0);
                        Menu_Ctx->pickResult = 2;
                    } else {
                        w->subTask ^= 1;
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
                if (Pad_State[0].triangle > 0 || Pad_State[0].cross > 0 || a0->stateLevel4++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 5:
            r = Text_WaitYesNo(w->promptText);
            if (r == 0) {
                break;
            }
            switch (w->mode) {
            case 6:
            default:
                if (r == 1) {
                    Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD010D), 0x81, Menu_DigiMsgPos);
                    for (i = 0; i < 0x24; i++) {
                        if (Save_GameStatePtr->elems[i].state >= 3) {
                            Save_GameStatePtr->elems[i].state = 2;
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
                    Text_OpenPacked(&w->promptText, (s32)Cd_GetFileEntry(0x1FD0113), 0x81, Menu_DigiMsgPos);
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

void Menu_DigiListDraw(Actor *actor) {
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
                Gfx_HidePartsByMask(obj, f | Menu_DigiListRowMasks[r->pickState - 1]);
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
