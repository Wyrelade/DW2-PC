#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_SkillMenuUpdate(Actor *a0);
void Stg30_SkillMenuDraw(Actor *a0);

Stg30XY Stg30_SkillListTextPos[] = { { 21, 59 }, { 50, 108 }, { 156, 59 }, { 185, 108 } };
Halves Stg30_SkillColumnLabelPos[] = { { 0x15, 0x30 }, { 0x32, 0x61 }, { 0x9C, 0x30 }, { 0xB9, 0x61 } };
s32 Stg30_SkillMenuArrowBlinkMasks[] = { 0xA, 0xA0, 0xA00, 0xA000 };
Stg30XY Stg30_SkillMenuCursorPos[] = { { -147, -52 }, { -118, -3 }, { -11, -52 }, { 18, -3 } };
s32 Stg30_SkillMenuColHideMasks[] = { 0xAC, 0xCA, 0xB2, 0x12A };
TaskDesc Stg30_SkillMenuDesc = { 0, Stg30_SkillMenuUpdate, Task_DefaultDestroy, Stg30_SkillMenuDraw, 0x54, 0 };
s16 Stg30_SkillMenuColumn;
u8 D_80073802[6];
s16 Stg30_SkillMenuRow[4];
s16 Stg30_SkillMenuScroll[4];
u8 D_80073818[8];
Stg30SkillList Stg30_SkillMenuLists[4];
u8 D_8007388C[4];

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
