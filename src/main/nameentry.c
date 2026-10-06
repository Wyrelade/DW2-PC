#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"

/* Task callbacks the descriptors below name (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_NameEntryInit(Actor *a, MenuNameEntryArg *v);
void Menu_NameEntryTask(Actor *a0);
void Menu_NameEntryDrawParts(Actor *a);

/* Name entry character grid: row stride and first column of each of the 3 pages. */
s32 Menu_NameEntryRowStride[] = { 6, 6, 3 };
s32 Menu_NameEntryPageCol[] = { 0, 5, 10 };
TaskDesc Menu_NameEntryDesc = {
    (TaskInitFn)Menu_NameEntryInit, Menu_NameEntryTask, Task_DefaultDestroy, Menu_NameEntryDrawParts, 0x30, 0,
};

u8 Menu_NameEntryGetChar(Actor *a0) {
    ActorWork *w;
    s32 base;
    s32 k;
    u8 *p;

    w = a0->work;
    base = 0x1FD00D4;
    base += w->field_C;
    k = w->field_2C >= 10;
    if (w->field_2C >= 5) {
        k++;
    }
    p = (u8 *)Cd_GetFileEntry(base + k);
    return p[w->field_2E * Menu_NameEntryRowStride[k] + w->field_2C - Menu_NameEntryPageCol[k]];
}

void Menu_NameEntryInit(Actor *a, MenuNameEntryArg *v) {
    ActorWork *w = a->work;

    *(MenuNameEntryArg *)w = *v;
    switch (w->field_0) {
    case 0:
    default:
        w->field_8 = 0xD;
        break;
    case 1:
        w->field_8 = 5;
        break;
    case 2:
        w->field_8 = 7;
        break;
    }
}
extern u8 Menu_NameEntryGetChar(Actor *);
extern void Snd_SaveCurrentId(void);
extern void Snd_RestoreSavedId(void);

void Menu_NameEntryTask(Actor *a0) {
    Wk12974 *w = (Wk12974 *)a0->work;
    u8 *p;
    u8 *src;
    s32 i;
    s32 j;
    u16 k;
    TextOpenArgs arg;
    TextOpenArgs arg2;

    switch (w->mode) {
    default:
    case 0:
        p = Save_GameState.elems[w->rosterIndex].name;
        break;
    case 1:
        p = Save_GameState.playerName;
        break;
    case 2:
        p = Save_GameState.field_D1;
        break;
    }
    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->gridText0, 5);
        {
            s32 j;
            for (j = 0; j < w->maxLen; j++) {
                p[j] = 0xFD;
            }
            p[j] = 0xFF;
        }
        switch (w->mode) {
        default:
        case 0:
            src = Digi_GetDefaultName(Save_GameState.elems[w->rosterIndex].digiId);
            for (i = 0; i < 14; i++) {
                if (src[i] == 0xFF) {
                    break;
                }
                p[i] = src[i];
            }
            break;
        case 1:
            p[0] = 0xA;
            p[1] = 0x2E;
            p[2] = 0x2C;
            p[3] = 0x35;
            p[4] = 0x24;
            break;
        case 2:
            p[0] = 0x10;
            p[1] = 0x38;
            p[2] = 0x31;
            p[3] = 0x31;
            p[4] = 0x28;
            p[5] = 0x35;
            break;
        }
        Snd_SaveCurrentId();
        Snd_PlayById(0x22, 1);
        w->charTableOfs = 6;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_Close(&w->gridText0);
            Text_Close(&w->gridText1);
            Text_Close(&w->gridText2);
            Text_Close(&w->nameText);
            arg.text = (s32)Cd_GetFileEntry(w->charTableOfs + 0x1FD00D4);
            arg.x = 0x28;
            arg.y = 0x42;
            arg.charAdvance = 0x13;
            arg.bigFont = 1;
            arg.color = 0;
            arg.lineAdvance = 0x12;
            arg.charDelay = 0;
            Text_Open(&w->gridText0, &arg);
            arg.text = (s32)Cd_GetFileEntry(w->charTableOfs + 0x1FD00D5);
            arg.x += 0x65;
            Text_Open(&w->gridText1, &arg);
            arg.text = (s32)Cd_GetFileEntry(w->charTableOfs + 0x1FD00D6);
            arg.x += 0x65;
            Text_Open(&w->gridText2, &arg);
            arg.x = 0x26;
            arg.text = (s32)p;
            arg.y = 0x20;
            arg.charAdvance = 0;
            arg.lineAdvance = 0;
            arg.charDelay = 0;
            Text_Open(&w->nameText, &arg);
            switch (w->mode) {
            default:
            case 0:
                arg2.text = (s32)Digi_GetDefaultName(Save_GameState.elems[w->rosterIndex].digiId);
                break;
            case 1:
                arg2.text = (s32)Cd_GetFileEntry(0x1FD0074);
                break;
            L34:
                w->cursorX = 10;
                w->cursorY = 7;
                Snd_PlayById(0x12, 0);
                goto keys_done;
            Lnone:
                Snd_PlayById(0x10, 0);
                goto keys_done;
            case 2:
                arg2.text = (s32)Cd_GetFileEntry(0x1FD0072);
                break;
            }
            arg2.color = 4;
            arg2.x = 0x23;
            arg2.bigFont = 0;
            arg2.y = 0x13;
            arg2.charAdvance = 0;
            arg2.lineAdvance = 0;
            arg2.charDelay = 0;
            Text_Open(&w->headerText, &arg2);
            Task_NextState1(a0);
        case 1:
            k = Pad_State[0].repeat;
            if (k & 0x2000) {
                if (w->cursorX != 10) {
                    if (++w->cursorX == 10) {
                        w->cursorY = 7;
                    }
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x8000) {
                if (w->cursorX != 0) {
                    w->cursorX--;
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x1000) {
                if (w->cursorY != 0) {
                    w->cursorY--;
                    if (w->cursorX == 10) {
                        w->cursorX--;
                    }
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x4000) {
                if (w->cursorY != 7) {
                    w->cursorY++;
                    Snd_PlayById(0x12, 0);
                }
            } else if (Pad_State[0].r1 > 0) {
                if (w->namePos != w->maxLen) {
                    w->namePos++;
                    Snd_PlayById(0x12, 0);
                }
            } else if (Pad_State[0].l1 > 0) {
                if (w->namePos != 0) {
                    w->namePos--;
                    Snd_PlayById(0x12, 0);
                }
            } else if (Pad_State[0].triangle > 0) {
                i = w->namePos;
                if (i != 0) {
                    do {
                        s32 n = i - 1;
                        w->namePos = n;
                        p[n] = 0xFD;
                        Snd_PlayById(0xB, 0);
                    } while (0);
                }
            } else if (Pad_State[0].start > 0) {
                goto L34;
            } else if (Pad_State[0].cross > 0) {
                if (w->cursorX < 10 || w->cursorY < 4) {
                    if (w->namePos != w->maxLen) {
                        p[w->namePos] = Menu_NameEntryGetChar(a0);
                        w->namePos++;
                        Snd_PlayById(0xE, 0);
                    }
                } else if (w->cursorY == 7) {
                    for (i = 0; i < w->maxLen; i++) {
                        if (p[i] != 0xFD) {
                            break;
                        }
                    }
                    j = w->maxLen - 1;
                    if (i != w->maxLen) {
                        for (; j >= 0; j--) {
                            if (p[j] != 0xFD) {
                                break;
                            }
                            p[j] = 0xFF;
                        }
                        Task_NextState0(a0);
                        Snd_PlayById(0xE, 0);
                    } else {
                        goto Lnone;
                    }
                }
            }
        keys_done:
            if (w->namePos == w->maxLen) {
                w->cursorX = 10;
                w->cursorY = 7;
            }
            if (Pad_State[0].repeat & 0xF000) {
                w->blinkTimer = 0;
            }
            break;
        }
        break;
    case 2:
        if (Sys_State.gameMode != 0x500) {
            Snd_RestoreSavedId();
        }
        Text_CloseArray(&w->gridText0, 5);
        Task_NextState0(a0);
        break;
    }
}

void Menu_NameEntryDrawParts(Actor *a) {
    ActorWork *w = a->work;
    GfxPart *base = (GfxPart *)Cd_GetFileEntry(0x1A10018);
    GfxPart *p;
    s32 v;
    s32 x;

    w->field_28 += Sys_State.frameDelta;
    for (p = base; p->fileId != 0; p++) {
        if (p->groupMask & 0x20) {
            v = w->namePos;
            p->y = -0x48;
            p->x = v * 9 - 0x71;
            if (w->namePos == w->field_8) {
                p->visible = 0;
            } else {
                p->visible = 1;
            }
        } else if (p->groupMask & 0x40) {
            v = w->field_2C;
            x = -0x73;
            if (v >= 10) {
                x = -0x6D;
            }
            if (v >= 5) {
                x += 6;
            }
            p->x = x + v * 19;
            p->y = w->field_2E * 18 - 0x2F;
        }
        x = 0;
        if (w->field_2C >= 10 && w->field_2E >= 4) {
            x = w->field_2E - 3;
        }
        if (p->groupMask & 0x7DC) {
            p->visible = 0;
        }
        if (!(w->field_28 & 0x10)) {
            switch (x) {
            case 0:
                if (p->groupMask & 0x40) {
                    p->visible = 1;
                }
                break;
            case 1:
                if (p->groupMask & 0x80) {
                    p->visible = 1;
                }
                break;
            case 2:
                if (p->groupMask & 0x100) {
                    p->visible = 1;
                }
                break;
            case 3:
                if (p->groupMask & 0x200) {
                    p->visible = 1;
                }
                break;
            case 4:
                if (p->groupMask & 0x400) {
                    p->visible = 1;
                }
                break;
            }
        }
        if (w->field_0 == 0 && (p->groupMask & 4)) {
            p->visible = 1;
        }
        if (w->field_0 == 1 && (p->groupMask & 8)) {
            p->visible = 1;
        }
        if (w->field_0 == 2 && (p->groupMask & 0x10)) {
            p->visible = 1;
        }
    }
    Gfx_DrawParts((s32)base);
}
