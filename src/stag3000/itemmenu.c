#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_ItemMenuInit(Actor *a0, s32 *args);
void Stg30_ItemMenuUpdate(Actor *a0);
void Stg30_ItemMenuDraw(Actor *a0);

Stg30XY Stg30_ItemListTextPos[] = { { 21, 59 }, { 50, 108 }, { 156, 59 } };
Halves Stg30_ItemColumnLabelPos[] = { { 0x15, 0x30 }, { 0x32, 0x61 }, { 0x9C, 0x30 } };
s32 Stg30_ItemMenuArrowBlinkMasks[] = { 0xA, 0xA0, 0xA00, 0xA000 };
s32 Stg30_ItemMenuColHideMasks[] = { 0xAC, 0x12A, 0xB2 };
Stg30XY Stg30_ItemMenuCursorPos[] = { { -147, -52 }, { -118, -3 }, { -11, -52 } };
TaskDesc Stg30_ItemMenuDesc = {
    (TaskInitFn)Stg30_ItemMenuInit, Stg30_ItemMenuUpdate, Task_DefaultDestroy, Stg30_ItemMenuDraw, 0xF8, 0,
};
s16 Stg30_ItemMenuColumn;
u8 D_800737EA[6];
s16 Stg30_ItemMenuRow[3];
u8 D_800737F6[2];
s16 Stg30_ItemMenuScroll[3];
u8 D_800737FE[2];

void Stg30_ItemMenuBuildLists(Actor *a0) {
    Stg30ItemMenuWork *w = (Stg30ItemMenuWork *)a0->work;
    s32 i;
    s32 n;
    s32 id;

    if (w->columnEnabled[0] != 0 && w->columnBroken[0] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = Save_GameState.bagItems[i];
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
            id = Save_GameState.bagItems[i];
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
            id = Save_GameState.bagItems[i];
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
    GameState *g;
    s32 item;
    s32 id;
    s32 i;
    s32 c;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->titleText, 0xE);
        Text_OpenById(&w->titleText, 0x178, 0, Stg30_ItemMenuTitlePos);
        g = &Save_GameState;
        if (g->slotItems[8] != 0) {
            w->columnEnabled[0] = 1;
        }
        if (g->slotItems[10] != 0) {
            w->columnEnabled[1] = 1;
        }
        if (g->slotItems[9] != 0) {
            w->columnEnabled[2] = 1;
        }
        if (g->slotStatus[8] != 0) {
            w->columnBroken[0] = 1;
        }
        if (g->slotStatus[10] != 0) {
            w->columnBroken[1] = 1;
        }
        if (g->slotStatus[9] != 0) {
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
                    Stg30_Battle.cancelled = 1;
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
                Stg30_Battle.cancelled = 0;
                Stg30_Battle.itemColumn = *pc;
                Stg30_Battle.turns[Stg30_Battle.inputSlot].turnType = Skill_GetType(id) + 1;
                Stg30_Battle.turns[Stg30_Battle.inputSlot].skillId = id;
                Stg30_Battle.turns[Stg30_Battle.inputSlot].effectKind = Stg30_GetSkillEffectKind(id);
                Stg30_Battle.turns[Stg30_Battle.inputSlot].target = Skill_GetTarget(id);
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
            Text_CloseArray(&w->titleText, 0xE);
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
