#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_CommandInputTask(Actor *a0);
void Stg30_CommandMenuUpdate(Actor *a0);
void Stg30_CommandMenuDestroy(Actor *a0);
void Stg30_CommandMenuDraw(Actor *a0);
void Stg30_ItemMenuInit(Actor *a0, s32 *args);
void Stg30_ItemMenuUpdate(Actor *a0);
void Stg30_ItemMenuDraw(Actor *a0);
void Stg30_SkillMenuUpdate(Actor *a0);
void Stg30_SkillMenuDraw(Actor *a0);
void Stg30_TargetSelectUpdate(Actor *a0);
void Stg30_TargetSelectDraw(Actor *a0);

TaskDesc Stg30_CommandInputDesc = { 0, Stg30_CommandInputTask, Task_DefaultDestroy, 0, 4, 4 };
u8 Stg30_CursorBlinkPalettes[] = { 0, 1, 2, 3, 2, 1, 0xFF };
TaskDesc Stg30_CommandMenuDesc = {
    0, Stg30_CommandMenuUpdate, Stg30_CommandMenuDestroy, Stg30_CommandMenuDraw, 0x14, 0,
};
Stg30XY Stg30_ItemListTextPos[] = { { 21, 59 }, { 50, 108 }, { 156, 59 } };
Halves Stg30_ItemColumnLabelPos[] = { { 0x15, 0x30 }, { 0x32, 0x61 }, { 0x9C, 0x30 } };
s32 Stg30_ItemMenuArrowBlinkMasks[] = { 0xA, 0xA0, 0xA00, 0xA000 };
s32 Stg30_ItemMenuColHideMasks[] = { 0xAC, 0x12A, 0xB2 };
Stg30XY Stg30_ItemMenuCursorPos[] = { { -147, -52 }, { -118, -3 }, { -11, -52 } };
TaskDesc Stg30_ItemMenuDesc = {
    (TaskInitFn)Stg30_ItemMenuInit, Stg30_ItemMenuUpdate, Task_DefaultDestroy, Stg30_ItemMenuDraw, 0xF8, 0,
};
Stg30XY Stg30_SkillListTextPos[] = { { 21, 59 }, { 50, 108 }, { 156, 59 }, { 185, 108 } };
Halves Stg30_SkillColumnLabelPos[] = { { 0x15, 0x30 }, { 0x32, 0x61 }, { 0x9C, 0x30 }, { 0xB9, 0x61 } };
s32 Stg30_SkillMenuArrowBlinkMasks[] = { 0xA, 0xA0, 0xA00, 0xA000 };
Stg30XY Stg30_SkillMenuCursorPos[] = { { -147, -52 }, { -118, -3 }, { -11, -52 }, { 18, -3 } };
s32 Stg30_SkillMenuColHideMasks[] = { 0xAC, 0xCA, 0xB2, 0x12A };
TaskDesc Stg30_SkillMenuDesc = { 0, Stg30_SkillMenuUpdate, Task_DefaultDestroy, Stg30_SkillMenuDraw, 0x54, 0 };
s32 Stg30_TargetCursorMasks[] = { ~0x2, ~0x4, ~0x8, ~0x10, ~0x20, ~0x40 };
s32 Stg30_TargetAllEnemiesMask = ~0x70;
s32 Stg30_TargetAllAlliesMask = ~0xE;
TaskDesc Stg30_TargetSelectDesc = {
    0, Stg30_TargetSelectUpdate, Task_DefaultDestroy, Stg30_TargetSelectDraw, 0x20, 0,
};

s32 Stg30_CommandMenuCursor;
u8 D_800737E4[4];
s16 Stg30_ItemMenuColumn;
u8 D_800737EA[6];
s16 Stg30_ItemMenuRow[3];
u8 D_800737F6[2];
s16 Stg30_ItemMenuScroll[3];
u8 D_800737FE[2];
s16 Stg30_SkillMenuColumn;
u8 D_80073802[6];
s16 Stg30_SkillMenuRow[4];
s16 Stg30_SkillMenuScroll[4];
u8 D_80073818[8];
Stg30SkillList Stg30_SkillMenuLists[4];
u8 D_8007388C[4];

void Stg30_ActionLoadDestroy(Actor *a0) {
    Stg30ActionLoadWork *w = (Stg30ActionLoadWork *)a0->work;
    s32 i;

    for (i = 0; i < w->tempCount; i++) {
        if (w->tempFiles[i] != 0) {
            Cd_FreeFile(w->tempFiles[i]);
        }
    }
}

void Stg30_DimFightersExcept(s32 sel, s32 from, s32 to) {
    s32 i;
    TaskEntry *t;

    for (i = from; i <= to; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            if (sel == -1 || i == sel) {
                Task_SetState01((Actor *)t, 2, 8);
            } else {
                Task_SetState01((Actor *)t, 2, 7);
            }
        }
    }
}

void Stg30_UndimPartyFighters(void) {
    s32 i;
    TaskEntry *t;

    for (i = 0; i < 3; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            Task_SetState01((Actor *)t, 2, 8);
        }
    }
}

void Stg30_CommandInputTask(Actor *a0) {
    Stg30WorkWord *w = (Stg30WorkWord *)a0->work;
    s32 *p = (s32 *)a0->u34.children;
    TaskEntry *t;
    s32 i;
    s32 n;
    s32 a;
    s32 b;
    s32 r;
    s32 j;

    switch (a0->stateLevel0) {
    case 0:
        D_80073CC4 = 0;
        Task_NextState0(a0);
        break;
    case 2:
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_SetCameraShot(1);
                Stg30_Battle.entries[0].inputSlot = 6;
                Task_Create(0x504, p, 0);
                Stg30_Battle.turns[6].turnType = 0;
                for (i = 0; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL) {
                        Task_SetState01((Actor *)t, 2, 9);
                    }
                }
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                switch (Stg30_Battle.entries[0].menuChoice) {
                case 0:
                default:
                    Task_SetState1(a0, 2);
                    w->field_0 = Stg30_TargetFirst(0, 0, 0);
                    break;
                case 1:
                    Task_SetState1(a0, 1);
                    break;
                case 2:
                    if (Stg30_Battle.isBossFight != 0) {
                        Stg30_Battle.entries[0].escapeResult = 2;
                    } else {
                        a = 0;
                        b = 0;
                        n = 0;
                        for (j = 0; j < 3; j++) {
                            if (Stg30_Battle.entries[j].hp != 0) {
                                n++;
                                a += Stg30_Battle.entries[j].speed;
                            }
                        }
                        a /= n;
                        n = 0;
                        for (j = 3; j < 6; j++) {
                            if (Stg30_Battle.entries[j].hp != 0) {
                                n++;
                                b += Stg30_Battle.entries[j].speed;
                            }
                        }
                        b /= n;
                        n = a * 100 / b;
                        if ((Rand_Next() & 0x7F) < n) {
                            D_80073CC4 = 1;
                        } else {
                            D_80073CC4 = 2;
                        }
                    }
                    Task_SetState0(a0, 3);
                    break;
                }
                break;
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_SetCameraShot(8);
                Task_Create(0x506, p, 0);
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                if (D_80073CD4 != 0) {
                    Task_SetState1(a0, 0);
                } else {
                    Task_NextState2(a0);
                }
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    Task_Create(0x508, p, 0);
                    Task_NextState3(a0);
                    break;
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (Stg30_Battle.entries[0].cancelled != 0) {
                        Stg30_UndimPartyFighters();
                        Stg30_Battle.turns[6].turnType = 0;
                        Task_SetState2(a0, 0);
                        break;
                    }
                    Stg30_Battle.turns[6].target = Stg30_Battle.entries[0].chosenTarget;
                    w->field_0 = Stg30_TargetFirst(0, 0, 0);
                    Task_SetState1(a0, 2);
                    break;
                }
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_DimFightersExcept(w->field_0, 0, 2);
                ((void (*)(s32))Stg30_SetCameraShot)(w->field_0 + 2);
                D_80073CC8 = w->field_0;
                Task_Create(0x504, p, 0);
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                if (Stg30_Battle.entries[0].cancelled != 0) {
                    if (w->field_0 != Stg30_TargetFirst(0, 0, 0)) {
                        r = Stg30_TargetPrev(0, w->field_0, 0, 0);
                        w->field_0 = r;
                        Stg30_Battle.turns[r].turnType = 0;
                        Task_SetState1(a0, 2);
                        break;
                    }
                    Task_SetState1(a0, 0);
                    break;
                }
                if (Stg30_Battle.entries[0].menuChoice == 0) {
                    Task_NextState2(a0);
                    break;
                }
                Stg30_Battle.turns[w->field_0].turnType = 5;
                Task_SetState2(a0, 4);
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    ((void (*)(s32))Stg30_SetCameraShot)(w->field_0 + 2);
                    D_80073CC8 = w->field_0;
                    Task_Create(0x507, p, 0);
                    Task_NextState3(a0);
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (D_80073CD4 != 0) {
                        Task_SetState1(a0, 2);
                    } else {
                        Task_NextState2(a0);
                    }
                    break;
                }
                break;
            case 3:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    Task_Create(0x508, p, 0);
                    Task_NextState3(a0);
                    break;
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (Stg30_Battle.entries[0].cancelled != 0) {
                        Stg30_DimFightersExcept(w->field_0, 0, 2);
                        Task_SetState2(a0, 2);
                        break;
                    }
                    Stg30_Battle.turns[w->field_0].target = Stg30_Battle.entries[0].chosenTarget;
                    Task_NextState2(a0);
                    break;
                }
                break;
            case 4:
                n = w->field_0;
                w->field_0 = Stg30_TargetNext(0, n, 0, 0);
                if (w->field_0 == n) {
                    Task_NextState1(a0);
                } else {
                    Task_SetState1(a0, 2);
                }
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                for (n = 0; n < 6; n++) {
                    t = Task_FindFirst(0x509, -1, n);
                    if (t != NULL) {
                        Task_SetState01((Actor *)t, 2, 9);
                    }
                }
                Stg30_SetCameraShot(1);
                Task_NextState2(a0);
            case 1:
                Task_SetState0(a0, 3);
                break;
            }
            break;
        }
        break;
    }
}

const Halves Stg30_TamerNameTextPos = { 0x16, 0x30 };
void Stg30_CommandMenuUpdate(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Halves pos;
    TextOpenArgs args;
    s32 i;
    s32 j;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
        Stg30_CommandMenuCursor = 0;
        Mem_FillWordsNeg1(w->text, 4);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel2) {
        case 0:
        default:
            switch (a0->stateLevel3) {
            case 0:
            default:
                a0->elapsed = 0;
                Task_NextState3(a0);
                break;
            case 1:
                for (j = 0; j < a0->elapsed; j++) {
                    w->scale += 0x2AA;
                }
                a0->elapsed = 0;
                if (w->scale > 0x1000) {
                    w->scale = 0x1000;
                    Task_NextState2(a0);
                }
                break;
            }
            break;
        case 1:
            do {
                if (Pad_State[0].up > 0) {
                    if (Stg30_CommandMenuCursor == 0) break;
                    Stg30_CommandMenuCursor--;
                    Snd_PlayById(0xC, 0);
                    break;
                }
                if (Pad_State[0].down > 0) {
                    if (Stg30_Battle.entries[0].inputSlot == 6) {
                        if (Stg30_CommandMenuCursor == 2) break;
                        if (Stg30_Battle.entries[0].fromCity != 0) break;
                        Stg30_CommandMenuCursor++;
                        Snd_PlayById(0xC, 0);
                        break;
                    }
                    if (Stg30_CommandMenuCursor == 1) break;
                    Stg30_CommandMenuCursor++;
                    Snd_PlayById(0xC, 0);
                    break;
                }
                if (Pad_State[0].cross > 0) {
                    Stg30_Battle.entries[0].cancelled = 0;
                    Stg30_Battle.entries[0].menuChoice = Stg30_CommandMenuCursor;
                    Snd_PlayById(0xA, 0);
                    Task_NextState0(a0);
                    break;
                }
                if (Stg30_Battle.entries[0].inputSlot == 6) break;
                if (Pad_State[0].triangle > 0) {
                    Stg30_Battle.entries[0].cancelled = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                }
            } while (0);
            if (Stg30_Battle.entries[0].inputSlot == 6) {
                Text_OpenPacked(w->text, (s32)Save_PlayerName, 0x10, Stg30_TamerNameTextPos);
                for (k = 0; k < 3; k++) {
                    if (Stg30_Battle.entries[0].fromCity != 0 && k != 0) {
                        s32 *text = &w->text[k + 1];
                        s32 id = k + 2;

                        pos.lo = 0x16;
                        pos.hi = k * 11 + 0x3C;
                        Text_OpenById(text, id, 3, pos);
                    } else if (Stg30_CommandMenuCursor == k) {
                        s32 *text = &w->text[k + 1];
                        s32 id = k + 2;

                        pos.lo = 0x16;
                        pos.hi = k * 11 + 0x3C;
                        Text_OpenById(text, id, 0, pos);
                    } else {
                        s32 *text = &w->text[k + 1];
                        s32 id = k + 2;

                        pos.lo = 0x16;
                        pos.hi = k * 11 + 0x3C;
                        Text_OpenById(text, id, 1, pos);
                    }
                }
            } else {
                if (w->text[0] == -1) {
                    args.text = (s32)((Stg30StateDigis *)&Stg30_Battle)->digis[Stg30_Battle.entries[0].inputSlot].name;
                    args.color = 4;
                    args.x = 0x16;
                    args.bigFont = 0;
                    args.y = 0x30;
                    args.charDelay = 0;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(w->text, &args);
                }
                for (i = 0; i < 2; i++) {
                    s32 *text = &w->text[i + 1];

                    pos.hi = i * 11 + 0x3C;
                    pos.lo = 0x16;
                    Text_OpenById(text, i + 5, Stg30_CommandMenuCursor != i, pos);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->text, 4);
            a0->elapsed = 0;
            Task_NextState1(a0);
            break;
        case 1:
            for (j = 0; j < a0->elapsed; j++) {
                w->scale -= 0x2AA;
            }
            if (w->scale <= 0) {
                w->scale = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

void Stg30_CommandMenuDestroy(Actor *a0) {
    Text_CloseArray(((Stg30Work73078 *)a0->work)->text, 4);
    Task_DefaultDestroy(a0);
}

void Stg30_CommandMenuDraw(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Stg30Part *p;
    Stg30Part *q;

    p = (Stg30Part *)Cd_GetFileEntry(0x1A10009);
    Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = -0x92;
            q->y = Stg30_CommandMenuCursor * 11 - 0x33;
            while (1) {
                if (a0->elapsed < 0x18) break;
                a0->elapsed = a0->elapsed - 0x18;
            }
            q->palette = Stg30_CursorBlinkPalettes[a0->elapsed / 4];
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}

void Stg30_ItemMenuBuildLists(Actor *a0) {
    Stg30ItemMenuWork *w = (Stg30ItemMenuWork *)a0->work;
    s32 i;
    s32 n;
    s32 id;

    if (w->columnEnabled[0] != 0 && w->columnBroken[0] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&Save_GameState)->bagItems[i];
            if (id == 0) {
                break;
            }
            switch (Item_GetCategory(id)) {
            case 0x14:
            case 0x1D:
            case 0x1E:
                w->itemLists[0][n++] = id;
                break;
            }
        }
        w->itemCounts[0] = n;
    } else {
        w->itemCounts[0] = 0;
    }
    if (w->columnEnabled[1] != 0 && w->columnBroken[1] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&Save_GameState)->bagItems[i];
            if (id == 0) {
                break;
            }
            if (Item_GetCategory(id) == 0x1A) {
                w->itemLists[1][n++] = id;
            }
        }
        w->itemCounts[1] = n;
    } else {
        w->itemCounts[1] = 0;
    }
    if (w->columnEnabled[2] != 0 && w->columnBroken[2] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&Save_GameState)->bagItems[i];
            if (id == 0) {
                break;
            }
            if (Item_GetCategory(id) == 0x19) {
                w->itemLists[2][n++] = id;
            }
        }
        w->itemCounts[2] = n;
    } else {
        w->itemCounts[2] = 0;
    }
}

void Stg30_OpenItemText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay) {
    TextOpenArgs args;

    if (name == 0) {
        args.text = Item_GetDescText(id);
    } else {
        args.text = Item_GetNameText(id);
    }
    args.bigFont = 0;
    args.color = color;
    args.x = pos.x;
    args.y = pos.y;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = delay;
    Text_Open(a0, &args);
}

const Stg30XY Stg30_ItemDescTextPos = { 0x5D, 0x96 };
void Stg30_ItemMenuRefreshText(Actor *a0) {
    Stg30ItemMenuWork *w = (Stg30ItemMenuWork *)a0->work;
    s32 i;
    s32 j;
    s32 item;
    s32 cat;

    for (i = 0; i < 3; i++) {
        u8 *row = w->itemLists[i];
        for (j = 0; j < 3; j++) {
            u8 *p = &row[j + Stg30_ItemMenuScroll[i]];
            if (*p != 0) {
                Stg30XY pos = Stg30_ItemListTextPos[i];
                pos.y += j * 0xB;
                Stg30_OpenItemText(&w->texts[i][j], *p, (Stg30_ItemMenuColumn ^ i) != 0, pos, 1, 0);
            }
        }
    }
    
    item = w->itemLists[Stg30_ItemMenuColumn][Stg30_ItemMenuRow[Stg30_ItemMenuColumn] + Stg30_ItemMenuScroll[Stg30_ItemMenuColumn]];
    if (item != 0) {
        if (w->shownItem != item) {
            w->shownItem = item;
            Stg30_OpenItemText(&w->descText, item, 0, Stg30_ItemDescTextPos, 0, 3);
        }
    } else {
        w->shownItem = -1;
        Text_Close(&w->descText);
        w->shownItem = 0;
    }
}

s32 Stg30_ItemToSkillId(s32 c) {
    if (c >= 0xE1) {
        return c + 0x2E;
    }
    if (c >= 0xD9) {
        return c + 0x2E;
    }
    if (c >= 0xB0) {
        return c + 0x68;
    }
    if (c >= 0xA6) {
        return c + 0x7E;
    }
    return c + 0x85;
}

void Stg30_ItemMenuInit(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

const Halves Stg30_ItemMenuTitlePos = { 0x14, 0x96 };
void Stg30_ItemMenuUpdate(Actor *a0) {
    Stg30ItemMenuWork *w = (Stg30ItemMenuWork *)a0->work;
    Stg30BeetleWeapons *g;
    s32 item;
    s32 id;
    s32 i;
    s32 c;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->field_4, 0xE);
        Text_OpenById(&w->field_4, 0x178, 0, Stg30_ItemMenuTitlePos);
        g = (Stg30BeetleWeapons *)&Save_GameState;
        if (g->gunPart != 0) {
            w->columnEnabled[0] = 1;
        }
        if (g->rCannonPart != 0) {
            w->columnEnabled[1] = 1;
        }
        if (g->zCannonPart != 0) {
            w->columnEnabled[2] = 1;
        }
        if (g->gunBroken != 0) {
            w->columnBroken[0] = 1;
        }
        if (g->rCannonBroken != 0) {
            w->columnBroken[1] = 1;
        }
        if (g->zCannonBroken != 0) {
            w->columnBroken[2] = 1;
        }
        Stg30_ItemMenuColumn = 0;
        Stg30_ItemMenuRow[0] = 0;
        Stg30_ItemMenuRow[1] = 0;
        Stg30_ItemMenuRow[2] = 0;
        Stg30_ItemMenuScroll[0] = 0;
        Stg30_ItemMenuScroll[1] = 0;
        Stg30_ItemMenuScroll[2] = 0;
        w->openScale = 0;
        Stg30_ItemMenuBuildLists(a0);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->openScale += 0x555;
            if (w->openScale >= 0x1000) {
                w->openScale = 0x1000;
                Task_NextState1(a0);
            }
            break;
        case 1:
            do {
                s32 cat = Stg30_ItemMenuColumn;
                s16 *row = &Stg30_ItemMenuRow[cat];
                s16 *top = &Stg30_ItemMenuScroll[cat];
                s16 *pc = &Stg30_ItemMenuColumn;

                if (Pad_State[0].left > 0) {
                    if (cat == 0) break;
                    Stg30_ItemMenuColumn--;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (Pad_State[0].right > 0) {
                    if (cat == 2) break;
                    Stg30_ItemMenuColumn++;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (w->columnEnabled[cat] != 0 && w->columnBroken[cat] == 0) {
                    if (Pad_State[0].repeat & 0x1000) {
                        if (*row != 0) {
                            *row -= 1;
                            Snd_PlayById(0xD, 0);
                            break;
                        }
                        if (*top == 0) break;
                        *top -= 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                    if (Pad_State[0].repeat & 0x4000) {
                        if (*row != 2) {
                            *row += 1;
                            Snd_PlayById(0xD, 0);
                            break;
                        }
                        if (w->itemLists[cat][*row + *top + 1] == 0) break;
                        *top += 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                }
                if (Pad_State[0].triangle > 0) {
                    D_80073CD4 = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                    break;
                }
                if (Pad_State[0].cross <= 0) break;
                item = w->itemLists[Stg30_ItemMenuColumn][Stg30_ItemMenuRow[Stg30_ItemMenuColumn] + Stg30_ItemMenuScroll[Stg30_ItemMenuColumn]];
                if (w->columnEnabled[Stg30_ItemMenuColumn] == 0 || w->columnBroken[Stg30_ItemMenuColumn] != 0 || item == 0) {
                    Snd_PlayById(0x10, 0);
                    break;
                }
                id = Stg30_ItemToSkillId(item);
                Stg30_Battle.itemId = item;
                Stg30_Battle.entries[0].cancelled = 0;
                Stg30_Battle.itemColumn = *pc;
                Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].turnType = Skill_GetType(id) + 1;
                Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].skillId = id;
                Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].effectKind = Stg30_GetSkillEffectKind(id);
                Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].target = Skill_GetTarget(id);
                Snd_PlayById(0xE, 0);
                Task_NextState0(a0);
            } while (0);
            for (i = 0; i < 3; i++) {
                if (Stg30_ItemMenuColumn == i) {
                    c = 4;
                } else {
                    c = 5;
                }
                Text_OpenById(&w->columnTitles[i], i + 7, c, Stg30_ItemColumnLabelPos[i]);
            }
            Stg30_ItemMenuRefreshText(a0);
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->field_4, 0xE);
            Task_NextState1(a0);
        case 1:
            w->openScale -= 0x555;
            if (w->openScale <= 0) {
                w->openScale = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

void Stg30_ItemMenuDraw(Actor *a0) {
    Stg30ItemMenuWork *w = (Stg30ItemMenuWork *)a0->work;
    Stg30Part *p;
    Stg30Part *q;
    Stg30Part *s;
    Stg30Part *r;
    s32 m;
    s32 bit;
    s32 i;
    s32 m2;
    Stg30Part *p2;
    Stg30Part *p3;

    p = (Stg30Part *)Cd_GetFileEntry(0x1A10016);
    for (r = p; r->fileId != 0; r++) {
        r->visible = 0;
        switch (r->groupMask) {
        case 0x2:
        case 0x4:
            if (w->columnEnabled[0] == 0 || w->columnBroken[0] != 0) {
                r->visible = 1;
            }
            break;
        case 0x8:
        case 0x10:
            if (w->columnEnabled[0] == 0) {
                r->visible = 1;
            } else if (w->columnBroken[0] != 0) {
                r->visible = 1;
            }
            break;
        case 0x20:
        case 0x40:
            if (w->columnEnabled[1] == 0 || w->columnBroken[1] != 0) {
                r->visible = 1;
            }
            break;
        case 0x80:
        case 0x100:
            if (w->columnEnabled[1] == 0 || w->columnBroken[1] != 0) {
                r->visible = 1;
            }
            break;
        case 0x200:
        case 0x400:
        case 0x800:
        case 0x1000:
            if (w->columnEnabled[2] == 0 || w->columnBroken[2] != 0) {
                r->visible = 1;
            }
            break;
        }
        if (r->visible != 0) {
            r->unscaled = 0;
            switch (r->groupMask) {
            case 0x2:
            case 0x8:
            case 0x20:
            case 0x80:
            case 0x200:
            case 0x800:
                r->rotZ = 0x9F;
                break;
            case 0x4:
            case 0x10:
            case 0x40:
            case 0x100:
            case 0x400:
            case 0x1000:
                r->rotZ = -0x9F;
                break;
            }
        }
    }
    Gfx_DrawParts((EntA0 *)p);
    if (w->openScale == 0x1000) {
        p2 = (Stg30Part *)Cd_GetFileEntry(0x1A10015);
        m = 0;
        bit = 2;
        for (i = 0; i < 3; i++) {
            if (Stg30_ItemMenuScroll[i] == 0) {
                m |= bit;
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            } else if (Stg30_ItemMenuColumn != i) {
                m |= bit;
                bit <<= 2;
            } else {
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            }
            if (w->itemCounts[i] < 4 || w->itemCounts[i] == Stg30_ItemMenuScroll[i] + 3) {
                m |= bit;
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            } else if (Stg30_ItemMenuColumn != i) {
                m |= bit;
                bit <<= 2;
            } else {
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            }
        }
        Gfx_HidePartsByMask((GfxPartMaskView *)p2, m);
        m2 = ~m & Stg30_ItemMenuArrowBlinkMasks[Stg30_ItemMenuColumn];
        for (q = p2; q->fileId != 0; q++) {
            if (q->groupMask & m2) {
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
        Gfx_DrawParts((EntA0 *)p2);
    }
    p3 = (Stg30Part *)Cd_GetFileEntry(0x1A10014);
    Gfx_SetPartsScale((GfxPartScaleView *)p3, 0x1000, w->openScale);
    Gfx_HidePartsByMask((GfxPartMaskView *)p3, Stg30_ItemMenuColHideMasks[Stg30_ItemMenuColumn]);
    for (s = p3; s->fileId != 0; s++) {
        if (s->groupMask & 0x4000) {
            if (w->columnEnabled[Stg30_ItemMenuColumn] != 0 && w->columnBroken[Stg30_ItemMenuColumn] == 0) {
                s->x = Stg30_ItemMenuCursorPos[Stg30_ItemMenuColumn].x;
                s->y = Stg30_ItemMenuCursorPos[Stg30_ItemMenuColumn].y + Stg30_ItemMenuRow[Stg30_ItemMenuColumn] * 11;
                s->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
                s->visible = 1;
            } else {
                s->visible = 0;
            }
        }
    }
    Gfx_DrawParts((EntA0 *)p3);
}

void Stg30_SkillMenuBuildLists(void) {
    s32 cnt[4];
    s32 a[3];
    s32 b[3];
    Stg30IdSet *d;
    s32 i;
    s32 j;
    s32 id;
    s32 k;
    s32 cost;
    s32 flag;
    s32 m;

    d = (Stg30IdSet *)&((Stg30StateDigis *)&Stg30_Battle)->digis[Stg30_Battle.entries[0].inputSlot];
    for (i = 0; i < 4; i++) {
        cnt[i] = 0;
        Stg30_SkillMenuLists[i].skillIds[13] = 0;
        for (j = 0; j < 12; j++) {
            Stg30_SkillMenuLists[i].skillIds[j] = 0;
        }
    }
    for (i = 0; i < 12; i++) {
        j = d->ids[i];
        if (j != 0) {
            k = Skill_GetType(j);
            cost = Skill_GetMpCost(j);
            Stg30_SkillMenuLists[k].skillIds[cnt[k]] = j;
            Stg30_SkillMenuLists[k].disabled[cnt[k]] = (d->mp < cost) * 2;
            cnt[k]++;
        }
    }
    for (i = 0; i < 4; i++) {
        Stg30_SkillMenuLists[i].skillIds[13] = cnt[i];
    }
    if (Stg30_Battle.statusFlags[Stg30_Battle.entries[0].inputSlot] & 8) {
        b[1] = 0;
        b[0] = 0;
        a[1] = 0;
        a[0] = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < cnt[i]; j++) {
                id = Stg30_SkillMenuLists[i].skillIds[j];
                m = Skill_GetPower(id);
                cost = Skill_GetMpCost(id);
                if (a[0] < m) {
                    a[0] = m;
                    a[1] = i;
                    a[2] = j;
                }
                if (b[0] < cost) {
                    b[0] = cost;
                    b[1] = i;
                    b[2] = j;
                }
            }
        }
        if (a[0] != 0) {
            Stg30_SkillMenuLists[a[1]].disabled[a[2]] = 2;
        }
        if (b[0] != 0) {
            Stg30_SkillMenuLists[b[1]].disabled[b[2]] = 2;
        }
    }
    flag = 0;
    for (i = 3; i < 6; i++) {
        if (Stg30_Battle.entries[i].hp != 0 && !(Stg30_Battle.statusFlags[i] & 0x10000)) {
            flag = 1;
            break;
        }
    }
    if (!flag) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < cnt[i]; j++) {
                if (Skill_GetTarget(Stg30_SkillMenuLists[i].skillIds[j]) == 5) {
                    Stg30_SkillMenuLists[i].disabled[j] = 2;
                }
            }
        }
    }
}

void Stg30_OpenSkillText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay) {
    TextOpenArgs args;

    if (name == 0) {
        args.text = Skill_GetDescText(id);
    } else {
        args.text = Skill_GetNameText(id);
    }
    args.bigFont = 0;
    args.color = color;
    args.x = pos.x;
    args.y = pos.y;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = delay;
    Text_Open(a0, &args);
}

const Stg30XY Stg30_SkillDescTextPos = { 0x45, 0x96 };
void Stg30_SkillMenuRefreshText(Actor *a0) {
    Stg30SkillMenuWork *w = (Stg30SkillMenuWork *)a0->work;
    s32 i;
    s32 j;
    s32 item;

    for (i = 0; i < 4; i++) {
        Stg30SkillList *rec = &Stg30_SkillMenuLists[i];
        for (j = 0; j < 3; j++) {
            s32 off = j + Stg30_SkillMenuScroll[i];
            if (rec->skillIds[off] != 0) {
                s32 k = j + 6;
                s32 color;
                Stg30XY pos = Stg30_SkillListTextPos[i];
                pos.y += j * 0xB;
                color = (Stg30_SkillMenuColumn ^ i) != 0;
                Stg30_OpenSkillText(&w->texts[i * 3 + k], rec->skillIds[off], color + rec->disabled[off], pos, 1, 0);
            }
        }
    }
    item = Stg30_SkillMenuLists[Stg30_SkillMenuColumn].skillIds[Stg30_SkillMenuRow[Stg30_SkillMenuColumn] + Stg30_SkillMenuScroll[Stg30_SkillMenuColumn]];
    if (item != 0) {
        if (w->shownSkill != item) {
            w->shownSkill = item;
            Stg30_OpenSkillText(&w->texts[5], item, 0, Stg30_SkillDescTextPos, 0, 3);
        }
        w->mpCost = Skill_GetMpCost(item);
    } else {
        w->shownSkill = -1;
        Text_Close(&w->texts[5]);
        w->mpCost = 0;
    }
}

const Halves Stg30_SkillMenuTitlePos = { 0x14, 0x96 };
void Stg30_SkillMenuUpdate(Actor *a0) {
    Stg30SkillMenuWork *w = (Stg30SkillMenuWork *)a0->work;
    s16 *row;
    s16 *top;
    s32 cat;
    s32 c;
    s32 i;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 0x12);
        Stg30_SkillMenuBuildLists();
        w->shownSkill = -1;
        Stg30_SkillMenuColumn = 0;
        w->openScale = 0;
        Stg30_SkillMenuRow[0] = 0;
        Stg30_SkillMenuRow[1] = 0;
        Stg30_SkillMenuRow[2] = 0;
        Stg30_SkillMenuRow[3] = 0;
        Stg30_SkillMenuScroll[0] = 0;
        Stg30_SkillMenuScroll[1] = 0;
        Stg30_SkillMenuScroll[2] = 0;
        Stg30_SkillMenuScroll[3] = 0;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->openScale += 0x555;
            if (w->openScale >= 0x1000) {
                w->openScale = 0x1000;
                Task_NextState1(a0);
            }
            break;
        case 1:
            cat = Stg30_SkillMenuColumn;
            row = &Stg30_SkillMenuRow[cat];
            top = &Stg30_SkillMenuScroll[cat];
            do {
                if (Pad_State[0].left > 0) {
                    if (cat == 0) break;
                    Stg30_SkillMenuColumn--;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (Pad_State[0].right > 0) {
                    if (cat == 3) break;
                    Stg30_SkillMenuColumn++;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (Pad_State[0].repeat & 0x1000) {
                    if (*row != 0) {
                        *row -= 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                    if (*top == 0) break;
                    *top -= 1;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (Pad_State[0].repeat & 0x4000) {
                    if (*row != 2) {
                        *row += 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                    if (Stg30_SkillMenuLists[cat].skillIds[*row + *top + 1] == 0) break;
                    *top += 1;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (Pad_State[0].cross > 0) {
                    if (Stg30_SkillMenuLists[cat].skillIds[*row + *top] != 0 && Stg30_SkillMenuLists[cat].disabled[*row + *top] == 0) {
                        Stg30_Battle.entries[0].cancelled = 0;
                        Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].turnType = cat + 1;
                        Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].skillId = Stg30_SkillMenuLists[cat].skillIds[*row + *top];
                        Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].effectKind = Stg30_GetSkillEffectKind(Stg30_SkillMenuLists[cat].skillIds[*row + *top]);
                        Snd_PlayById(0xE, 0);
                        Task_NextState0(a0);
                        break;
                    }
                    Snd_PlayById(0x10, 0);
                    break;
                }
                if (Pad_State[0].triangle > 0) {
                    D_80073CD4 = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                }
            } while (0);
            Stg30_SkillMenuRefreshText(a0);
            Text_OpenById(w, 0x179, 4, Stg30_SkillMenuTitlePos);
            for (i = 0; i < 4; i++) {
                if (Stg30_SkillMenuColumn == i) {
                    c = 4;
                } else {
                    c = 5;
                }
                Text_OpenById(&w->texts[i + 1], i + 10, c, Stg30_SkillColumnLabelPos[i]);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 0x12);
            Task_NextState1(a0);
        case 1:
            w->openScale -= 0x555;
            if (w->openScale <= 0) {
                w->openScale = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

void Stg30_SkillMenuDraw(Actor *a0) {
    Stg30SkillMenuWork *w = (Stg30SkillMenuWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;
    s32 bit;
    s32 i;
    s32 m2;
    GfxPart *p2;
    GfxPart *q2;

    while (1) {
        if (a0->elapsed < 0x18) break;
        a0->elapsed = a0->elapsed - 0x18;
    }
    if (w->openScale == 0x1000) {
        p = (GfxPart *)Cd_GetFileEntry(0x1A1001A);
        m = 0;
        bit = 2;
        for (i = 0; i < 4; i++) {
            if (Stg30_SkillMenuScroll[i] == 0) {
                m |= bit;
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            } else if (Stg30_SkillMenuColumn != i) {
                m |= bit;
                bit <<= 2;
            } else {
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            }
            if (Stg30_SkillMenuLists[i].skillIds[0xD] < 4 || Stg30_SkillMenuLists[i].skillIds[0xD] == Stg30_SkillMenuScroll[i] + 3) {
                m |= bit;
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            } else if (Stg30_SkillMenuColumn != i) {
                m |= bit;
                bit <<= 2;
            } else {
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            }
        }
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        m2 = ~m & Stg30_SkillMenuArrowBlinkMasks[Stg30_SkillMenuColumn];
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & m2) {
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    p2 = (GfxPart *)Cd_GetFileEntry(0x1A10019);
    Gfx_SetPartsScale((GfxPartScaleView *)p2, 0x1000, w->openScale);
    Gfx_SetPartsNumber(p2, 0x1000, 3, w->mpCost);
    for (q2 = p2; q2->fileId != 0; q2++) {
        if (q2->groupMask & 0x4000) {
            q2->x = Stg30_SkillMenuCursorPos[Stg30_SkillMenuColumn].x;
            q2->y = Stg30_SkillMenuCursorPos[Stg30_SkillMenuColumn].y + Stg30_SkillMenuRow[Stg30_SkillMenuColumn] * 11;
            q2->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
        }
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p2, Stg30_SkillMenuColHideMasks[Stg30_SkillMenuColumn]);
    Gfx_DrawParts((EntA0 *)p2);
}

void Stg30_TargetSelectUpdate(Actor *a0) {
    Stg30TargetSelectWork *w = (Stg30TargetSelectWork *)a0->work;
    TaskEntry *t;
    s32 i;
    s32 old;
    s32 changed;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->skillId = Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].skillId;
        w->targetMode = Skill_GetTarget(w->skillId);
        w->effectKind = Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].effectKind;
        switch (w->targetMode) {
        case 0:
        case 3:
        case 4:
        case 7:
        default:
            v = D_80073CC8;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 1:
            w->firstSlot = 0;
            w->lastSlot = 2;
            w->team = 0;
            w->target = Stg30_TargetFirst(0, 1, w->effectKind);
            break;
        case 2:
            v = 7;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 5:
            w->firstSlot = 3;
            w->lastSlot = 5;
            w->team = 1;
            w->target = Stg30_TargetFirst(1, 1, w->effectKind);
            break;
        case 6:
            v = 8;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 8:
            v = 9;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 9:
            Stg30_Battle.entries[0].chosenTarget = 0;
            Stg30_Battle.entries[0].cancelled = 0;
            Task_SetState0(a0, 3);
            return;
        }
        Task_NextState0(a0);
        break;
    case 1:
        changed = 0;
        do {
        if (w->targetMode == 1 || w->targetMode == 5) {
            if (Pad_Left > 0) {
                old = w->target;
                if (w->team != 0) {
                    w->target = Stg30_TargetPrev(w->team, old, 1, w->effectKind);
                } else {
                    w->target = Stg30_TargetNext(0, old, 1, w->effectKind);
                }
                if (w->target != old) {
                    changed = 1;
                    Snd_PlayById(0x12, 0);
                }
            }
            if (Pad_State[0].right > 0) {
                old = w->target;
                if (w->team != 0) {
                    w->target = Stg30_TargetNext(w->team, old, 1, w->effectKind);
                } else {
                    w->target = Stg30_TargetPrev(0, old, 1, w->effectKind);
                }
                if (w->target != old) {
                    changed = 1;
                    Snd_PlayById(0x12, 0);
                }
            }
        }
            if (Pad_State[0].cross > 0) {
                Stg30_Battle.entries[0].chosenTarget = w->target;
                Stg30_Battle.entries[0].cancelled = 0;
                Snd_PlayById(0xE, 0);
                Task_SetState0(a0, 3);
                break;
            }
            if (Pad_State[0].triangle > 0) {
                D_80073CD4 = 1;
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 3);
            }
        } while (0);
        if (changed || w->highlightDone == 0) {
            w->highlightDone = 1;
            switch (w->targetMode) {
            case 1:
            case 5:
                for (i = w->firstSlot; i <= w->lastSlot; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL) {
                        if (w->target == i) {
                            Task_SetState01((Actor *)t, 2, 8);
                        } else {
                            Task_SetState01((Actor *)t, 2, 7);
                        }
                    }
                }
                break;
            case 2:
                for (i = 0; i < 3; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && Stg30_Battle.entries[i].hp != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            case 6:
                for (i = 3; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && Stg30_Battle.entries[i].hp != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            case 8:
                for (i = 0; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && Stg30_Battle.entries[i].hp != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            }
        }
        switch (w->targetMode) {
        case 1:
        case 5:
            ((void (*)(s32))Stg30_SetCameraShot)(w->target + 2);
            break;
        case 2:
            Stg30_SetCameraShot(8);
            break;
        case 6:
            Stg30_SetCameraShot(9);
            break;
        case 8:
            Stg30_SetCameraShot(0x18);
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg30_TargetSelectDraw(Actor *a0) {
    Stg30TargetSelectWork *w = (Stg30TargetSelectWork *)a0->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0x1A1000A);
    GfxPart *q;
    s32 m;

    switch (w->targetMode) {
    case 0:
    case 1:
    case 5:
        Gfx_HidePartsByMask((GfxPartMaskView *)p, Stg30_TargetCursorMasks[w->target]);
        break;
    case 2:
        m = Stg30_TargetAllAlliesMask;
        if (Stg30_Battle.entries[2].hp == 0) m |= 8;
        if (Stg30_Battle.entries[1].hp == 0) m |= 4;
        if (Stg30_Battle.entries[0].hp == 0) m |= 2;
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    case 6:
        m = Stg30_TargetAllEnemiesMask;
        if (Stg30_Battle.entries[5].hp == 0) m |= 0x40;
        if (Stg30_Battle.entries[4].hp == 0) m |= 0x20;
        if (Stg30_Battle.entries[3].hp == 0) m |= 0x10;
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    case 8:
        m = -0x7F;
        if (func_8001F0E4(w->skillId) & 0x2000) {
            if (Stg30_Battle.entries[0].digiId == 0) m = -0x7D;
            if (Stg30_Battle.entries[1].digiId == 0) m |= 4;
            if (Stg30_Battle.entries[2].digiId == 0) m |= 8;
            if (Stg30_Battle.entries[3].digiId == 0) m |= 0x10;
            if (Stg30_Battle.entries[4].digiId == 0) m |= 0x20;
            if (Stg30_Battle.entries[5].digiId == 0) m |= 0x40;
        } else {
            if (Stg30_Battle.entries[0].hp == 0) m = -0x7D;
            if (Stg30_Battle.entries[1].hp == 0) m |= 4;
            if (Stg30_Battle.entries[2].hp == 0) m |= 8;
            if (Stg30_Battle.entries[3].hp == 0) m |= 0x10;
            if (Stg30_Battle.entries[4].hp == 0) m |= 0x20;
            if (Stg30_Battle.entries[5].hp == 0) m |= 0x40;
        }
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    }
    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_PingPongRange(a0->elapsed, 8, 0, 3);
    }
    Gfx_DrawParts((EntA0 *)p);
}
