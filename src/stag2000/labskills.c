#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/areaselect.h"
#include "stag2000/msgwin.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_LabSkillsUpdate(Actor *a);
void Stg20_LabSkillsDraw(Actor *a);

Halves Stg20_LabSkillsCursorPos[] = { { 0xFF71, 0xFFCB }, { 0xFF8E, 6 }, { 0xFFF9, 0xFFCB }, { 0x16, 6 } };
Stg20Cell Stg20_LabSkillsTextPos[10] = {
    { 21, 57 }, { 50, 116 }, { 157, 57 }, { 186, 116 }, { 21, 69 },
    { 50, 128 }, { 157, 69 }, { 186, 128 }, { 18, 24 }, { 204, 24 },
};
s32 Stg20_LabSkillsColHideMasks[4] = { 0xAC, 0xCA, 0xB2, 0x12A };
s32 Stg20_LabSkillsArrowBlinkMasks[4] = { 0xA, 0xA0, 0xA00, 0xA000 };
TaskDesc Stg20_LabSkillsDesc = { 0, Stg20_LabSkillsUpdate, Task_DefaultDestroy, Stg20_LabSkillsDraw, 0xAC, 0 };

void Stg20_LabSkillsGroup(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    DigiRosterEntry *e = &Save_GameState.elems[a->param];
    s32 cnt[4];
    s32 i;
    s32 j;
    s32 s;
    s32 k;

    for (i = 0; i < 4; i++) {
        cnt[i] = 0;
        w->groups[i].count = 0;
        for (j = 0; j < 12; j++) {
            w->groups[i].list[j] = 0;
        }
    }
    for (i = 0; i < 12; i++) {
        s = e->skills[i];
        if (s != 0) {
            k = Skill_GetType(s);
            w->groups[k].list[cnt[k]] = s;
            cnt[k]++;
        }
    }
    for (i = 0; i < 4; i++) {
        w->groups[i].count = cnt[i];
    }
}

void Stg20_LabSkillsSetText(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    Stg20TextArgs args;
    s32 i;
    s32 j;
    s32 s;
    u8 *list;
    s32 top;

    for (i = 0; i < 4; i++) {
        list = w->groups[i].list;
        top = w->top[i];
        for (j = 0; j < 3; j++) {
            if (list[j + top] != 0) {
                args.text = Skill_GetNameText(list[j + top]);
                args.bigFont = 0;
                args.color = w->col != i;
                args.pos.x = Stg20_LabSkillsCursorPos[i + 8].lo;
                args.pos.y = Stg20_LabSkillsCursorPos[i + 8].hi + j * 11;
                args.charAdvance = 0;
                args.lineAdvance = 0;
                args.charDelay = 0;
                Text_Open(&w->texts[7 + i * 3 + j], &args);
            }
        }
    }
    s = w->groups[w->col].list[w->cursor[w->col] + w->top[w->col]];
    if (s != 0) {
        if (w->skill != s) {
            w->skill = s;
            Stg20_MsgWinShowSkillDesc(s);
        }
    } else {
        w->skill = 0;
        Stg20_MsgWinClear();
    }
}

void Stg20_LabSkillsUpdate(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    s32 snd;
    s32 redraw;
    s32 col;
    s32 *cur;
    s32 *top;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 0x13);
        a->param = Stg20_MenuState.skillRosterIndex;
        Stg20_LabSkillsGroup(a);
        Task_NextState0(a);
        break;
    case 1:
        if (a->stateLevel1 == 0) {
            Stg20_OpenText(&w->texts[0], 0, 0xA, &Stg20_LabSkillsTextPos[0], 4);
            Stg20_OpenText(&w->texts[1], 0, 0xB, &Stg20_LabSkillsTextPos[1], 4);
            Stg20_OpenText(&w->texts[2], 0, 0xC, &Stg20_LabSkillsTextPos[2], 4);
            Stg20_OpenText(&w->texts[3], 0, 0xD, &Stg20_LabSkillsTextPos[3], 4);
            Stg20_OpenText(&w->texts[4], (s32)Save_GameState.elems[Stg20_MenuState.skillRosterIndex].name, 0, &Stg20_LabSkillsTextPos[8], 0);
            Stg20_OpenText(&w->texts[5], 0, 0xD1, &Stg20_LabSkillsTextPos[9], 0);
            Task_NextState1(a);
        }
        redraw = snd = 0;
        do {
            col = w->col;
            cur = &w->cursor[col];
            top = &w->top[col];
            if (Pad_State[0].left > 0) {
                if (col != 0) {
                    w->col = col - 1;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].right > 0) {
                if (col != 3) {
                    w->col = col + 1;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].repeat & 0x1000) {
                if (*cur != 0) {
                    (*cur)--;
                    snd = 1;
                } else if (*top != 0) {
                    (*top)--;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].repeat & 0x4000) {
                if (*cur != 2) {
                    (*cur)++;
                    snd = 1;
                } else if (w->groups[0].list[*top + col * 14 + 3] != 0) {
                    (*top)++;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].triangle > 0 || Pad_State[0].circle > 0) {
                Task_NextState0(a);
            }
        } while (0);
        if (snd != 0) {
            Snd_PlayById(0xD, 0);
        }
        if (redraw != 0 || ((Stg20BlinkTask *)a)->frameCount == 1) {
            Stg20_LabSkillsSetText(a);
        }
        break;
    case 2:
        Text_CloseArray(w->texts, 0x13);
        Stg20_MsgWinClear();
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabSkillsDraw(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;
    s32 bit;
    s32 i;
    s32 m2;

    p = (GfxPart *)Cd_GetFileEntry(0xD120009);
    for (q = p; q->fileId != 0; q++) {
        q->visible = (q->groupMask & Stg20_LabSkillsColHideMasks[w->col]) == 0;
        if (q->groupMask & 0x4000) {
            q->x = Stg20_LabSkillsCursorPos[w->col].lo;
            q->y = Stg20_LabSkillsCursorPos[w->col].hi + w->cursor[w->col] * 11;
        }
    }
    Gfx_DrawParts((s32)p);
    p = (GfxPart *)Cd_GetFileEntry(0xD12000A);
    m = 0;
    bit = 2;
    for (i = 0; i < 4; i++) {
        if (w->top[i] == 0) {
            m |= bit;
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        } else if (w->col != i) {
            m |= bit;
            bit <<= 2;
        } else {
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        }
        if (w->groups[i].count < 4 || w->groups[i].count == w->top[i] + 3) {
            m |= bit;
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        } else if (w->col != i) {
            m |= bit;
            bit <<= 2;
        } else {
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        }
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
    m2 = ~m & Stg20_LabSkillsArrowBlinkMasks[w->col];
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & m2) {
            q->palette = Math_PingPongRange(a->elapsed, 4, 0, 3);
        }
    }
    Gfx_DrawParts((s32)p);
}
