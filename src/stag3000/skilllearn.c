#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"
#include "stag3000/battlestate.h"
#include "stag3000/fighter.h"
#include "stag3000/fightmsg.h"
#include "stag3000/popup.h"
#include "stag3000/interruptselect.h"
#include "stag3000/camera.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_SkillLearnInit(Actor *a0, Stg30SkillLearnArgs *args);
void Stg30_SkillLearnUpdate(Actor *a0);
void Stg30_SkillLearnDraw(Actor *a0);

Halves Stg30_SkillLearnTextPos[] = {
    { 0x23, 0x13 }, { 0x22, 0x20 }, { 0x23, 0x4E }, { 0xAB, 0x4E }, { 0x23, 0x5A }, { 0x23, 0x65 }, { 0x23, 0x70 },
    { 0x23, 0x7B }, { 0x23, 0x86 }, { 0x23, 0x91 }, { 0x23, 0x9C }, { 0x23, 0xA7 }, { 0x23, 0xB2 }, { 0x23, 0xBD },
    { 0xAB, 0x5A }, { 0xAB, 0x65 }, { 0xAB, 0x70 }, { 0xAB, 0x7B }, { 0xAB, 0x86 }, { 0xAB, 0x91 }, { 0xAB, 0x9C },
    { 0xAB, 0xA7 }, { 0xAB, 0xB2 }, { 0xAB, 0xBD }, { 0x29, 0x3A }, { 0x5B, 0x3A }, { 0x9E, 0x3A }, { 0x20, 0xD1 },
};
TaskDesc Stg30_SkillLearnDesc = {
    (TaskInitFn)Stg30_SkillLearnInit, Stg30_SkillLearnUpdate, Task_DefaultDestroy, Stg30_SkillLearnDraw, 0xCC, 0,
};

void Stg30_SkillLearnInit(Actor *a0, Stg30SkillLearnArgs *args) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 i;

    w->slot = args->slot;
    for (i = 0; i < 12; i++) {
        w->skillLists[0][i] = args->skillIds[i];
    }
    Snd_PlayById(0x2B, 0);
}

void Stg30_SkillLearnRefreshList(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 row;
    s32 col;
    s32 k;
    s32 *slot;
    s32 item;
    s32 id;
    s32 scroll;

    for (row = 0; row < 2; row++) {
        scroll = w->scroll[row];
        for (col = 0; col < 10; col++) {
            k = row * 10 + col;
            slot = &w->texts[k];
            Text_Close(slot);
            item = w->skillLists[row][col + scroll];
            if (item != 0) {
                Text_OpenPacked(slot, Skill_GetNameText(item), 0, Stg30_SkillLearnTextPos[k + 4]);
            }
        }
    }
    Text_Close(&w->descText);
    id = w->skillLists[w->column][w->scroll[w->column] + w->cursorRow[w->column]];
    if (id != 0 && w->buttonRowActive == 0) {
        Text_OpenPacked(&w->descText, Skill_GetDescText(id), 0, Stg30_SkillLearnTextPos[27]);
        w->mpCost = Skill_GetMpCost(id);
    } else {
        w->mpCost = 0;
    }
}

void Stg30_SkillLearnRefreshButtons(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Text_Close(&w->text[i]);
        if (w->buttonRowActive == 0 || w->buttonIndex != i || !(a0->elapsed & 0x10)) {
            s32 c;
            if (w->buttonIndex == i) c = 4; else c = 5;
            Text_OpenById(&w->text[i], i + 0x188, c, Stg30_SkillLearnTextPos[i + 24]);
        }
    }
}

void Stg30_SkillLearnCompact(Actor *a0, s32 row) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 i;
    s32 n;

    i = 0;
    n = i;
    for (; i < 12; i++) {
        if (w->skillLists[row][i] != 0) {
            w->skillLists[row][n] = w->skillLists[row][i];
            if (i != n) {
                w->skillLists[row][i] = 0;
            }
            n++;
        }
    }
    w->count[row] = n;
}

void Stg30_SkillLearnUpdate(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 *cur;
    s32 *scr;
    s32 *cnt;
    s32 row;
    s32 other;
    s16 v;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->labelTexts, 0x1C);
        a0->digiId = Stg30_Battle.entries[w->slot].digiId;
        for (i = 0; i < 12; i++) {
            w->skillLists[1][i] = Stg30_Battle.entries[w->slot].skillIds[i];
        }
        w->count[0] = 0;
        w->count[1] = 0;
        for (i = 0; i < 12; i++) {
            if (w->skillLists[0][i] != 0) {
                w->count[0]++;
            }
            if (w->skillLists[1][i] != 0) {
                w->count[1]++;
            }
        }
        Text_OpenPacked(&w->labelTexts[0], (s32)D_80073D24[w->slot].name, 0x10, Stg30_SkillLearnTextPos[0]);
        Text_OpenPacked(&w->labelTexts[1], (s32)Cd_GetFileEntry(0x1FD0187), 0x80, Stg30_SkillLearnTextPos[1]);
        Text_OpenById(&w->labelTexts[2], 0x18B, 4, Stg30_SkillLearnTextPos[2]);
        Text_OpenById(&w->labelTexts[3], 0x18C, 4, Stg30_SkillLearnTextPos[3]);
        ((void (*)(s32))Stg30_SetCameraShot)(w->slot + 2);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->buttonRowActive = 1;
            do {
                if (Pad_State[0].right > 0) {
                    if (w->buttonIndex != 2) {
                        w->buttonIndex++;
                        Snd_PlayById(0xC, 0);
                    }
                } else if (Pad_State[0].left > 0) {
                    if (w->buttonIndex != 0) {
                        w->buttonIndex--;
                        Snd_PlayById(0xC, 0);
                    }
                } else if (Pad_State[0].cross > 0) {
                    switch (w->buttonIndex) {
                    case 0:
                        for (n = 0; n < 12; n++) {
                            if (w->skillLists[1][n] == 0) {
                                break;
                            }
                        }
                        if (n < 12) {
                            for (j = 0; n < 12; n++) {
                                if (w->skillLists[0][j] == 0) {
                                    break;
                                }
                                w->skillLists[1][n] = w->skillLists[0][j];
                                w->skillLists[0][j++] = 0;
                            }
                        }
                        Stg30_SkillLearnCompact(a0, 0);
                        Stg30_SkillLearnCompact(a0, 1);
                        Snd_PlayById(0xA, 0);
                        break;
                    case 1:
                        Task_NextState1(a0);
                        Snd_PlayById(0xA, 0);
                        break;
                    case 2:
                        Task_NextState0(a0);
                        Snd_PlayById(0xA, 0);
                        break;
                    default:
                        Snd_PlayById(0xA, 0);
                        break;
                    }
                }
            } while (0);
            break;
        case 1:
            w->buttonRowActive = 0;
            do {
                row = w->column;
                cur = &w->cursorRow[row];
                scr = &w->scroll[row];
                cnt = &w->count[row];
                if (Pad_State[0].right > 0) {
                    if (row == 0) {
                        w->column = 1;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].left > 0) {
                    if (row != 0) {
                        w->column = 0;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].repeat & 0x1000) {
                    if (*cur != 0) {
                        *cur -= 1;
                        Snd_PlayById(0xD, 0);
                    } else if (*scr != 0) {
                        *scr -= 1;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].repeat & 0x4000) {
                    if (*cur != 9) {
                        *cur += 1;
                        Snd_PlayById(0xD, 0);
                    } else if (*scr + 10 < *cnt) {
                        *scr += 1;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].triangle > 0) {
                    Task_SetState1(a0, 0);
                    Snd_PlayById(0xB, 0);
                } else if (Pad_State[0].cross > 0) {
                    v = w->skillLists[row][*cur + *scr];
                    other = row ^ 1;
                    if (v == 0 || w->count[other] == 12) {
                        Snd_PlayById(0x10, 0);
                    } else if (row != 0 && w->count[row] == 1) {
                        Snd_PlayById(0x10, 0);
                    } else {
                        w->skillLists[other][w->count[other]] = v;
                        w->skillLists[w->column][*cur + *scr] = 0;
                        Stg30_SkillLearnCompact(a0, 0);
                        Stg30_SkillLearnCompact(a0, 1);
                        Snd_PlayById(0xE, 0);
                    }
                }
            } while (0);
            break;
        }
        Stg30_SkillLearnRefreshList(a0);
        Stg30_SkillLearnRefreshButtons(a0);
        break;
    case 2:
        Text_CloseArray(w->labelTexts, 0x1C);
        for (k = 0; k < 12; k++) {
            Stg30_Battle.entries[w->slot].skillIds[k] = w->skillLists[1][k];
        }
        Task_NextState0(a0);
        break;
    }
}

void Stg30_SkillLearnDraw(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;

    p = (GfxPart *)Cd_GetFileEntry(0x1A1001B);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001C);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001D);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 0x4000) {
            if (w->buttonRowActive != 0) {
                q->visible = 0;
            } else {
                q->visible = 1;
                q->x = w->column != 0 ? 3 : -0x85;
                q->y = w->cursorRow[w->column] * 11 - 0x15;
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
    }
    Gfx_SetPartsNumber(p, 0x800, 3, w->mpCost);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001E);
    m = (w->scroll[0] == 0) << 1;
    if (w->scroll[0] + 10 >= w->count[0]) {
        m |= 8;
    }
    if (w->scroll[1] == 0) {
        m |= 0x20;
    }
    if (w->scroll[1] + 10 >= w->count[1]) {
        m |= 0x80;
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
    Gfx_DrawParts((EntA0 *)p);
}
