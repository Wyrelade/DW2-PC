#include "common.h"
#include "main/game.h"
#include "main/187C.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
s32 Menu_TopMenuResult;
MenuCtx *Menu_Ctx;
s32 Ovl_CurrentId;

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
        p = Save_RosterNames[w->rosterIndex].name;
        break;
    case 1:
        p = D_8005E634;
        break;
    case 2:
        p = D_8005E6F1;
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
        if (Sys_GameMode[0] != 0x500) {
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


/* Ovl_FileIds[id] (Cd file ids, matched by LBA + sector count):
 * 0 STAG0000, 1 STAG4000, 2 STAG2000, 3 STAG1000, 4 STAG3000, 5 STAG1100, 6 STAG3500.
 * Sys_GameModeTask loads id (gameMode >> 8) - 1. */
void Ovl_Load(s32 id) {
    s32 *ids;
    s32 *p;
    u8 *src;
    u8 *dst;

    if (Ovl_CurrentId != id) {
        ids = Ovl_FileIds;
        p = &ids[id];
        Ovl_CurrentId = id;
        src = (u8 *)Cd_GetFileSync(*p);
        dst = Ovl_LoadAddr;
        memcpy(dst, src, Cd_GetFileSectors(*p) << 11);
    }
}

s32 Ovl_GetCurrentId(void) {
    return Ovl_CurrentId;
}


extern void Ovl_Load(s32);
extern void Task_Create(u32, s32 *, s32);
extern s32 Snd_AnySlotLoading(void);

void Sys_GameModeTask(Actor *a0) {
    s32 st = a0->stateLevel0;
    s32 t = a0->u34.children;
    switch (st) {
    case 0:
    default:
        Ovl_Load((Sys_State.gameMode >> 8) - 1);
        Task_Create(Sys_State.gameMode & 0xFF00, t, 0);
        Task_NextState0(a0);
        break;
    case 1:
        if (Sys_State.nextGameMode != 0) {
            Task_SetState0(a0, 2);
        }
        break;
    case 2:
        if (Snd_AnySlotLoading() == 0) {
            Task_SetState0(a0, 3);
        }
        break;
    }
}

void Task_DefaultDestroy2(void) {
    Task_Free();
}

void Text_OpenDesc(void *arg0, TextDesc *arg1) {
    TextOpenArgs local;
    local.text = arg1->text;
    local.bigFont = arg1->packedStyle >> 7;
    local.color = arg1->color;
    local.x = arg1->x;
    local.y = arg1->y;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = arg1->packedStyle & 0x7F;
    local.strArg0 = arg1->strArg0;
    local.strArg1 = arg1->strArg1;
    Text_Open(arg0, &local);
}

void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3) {
    TextOpenArgs local;
    local.bigFont = (arg2 >> 7) & 1;
    local.text = arg1;
    local.color = (arg2 >> 2) & 0xF;
    local.x = arg3.lo;
    local.y = arg3.hi;
    local.charAdvance = 0;
    local.lineAdvance = 0;
    local.charDelay = arg2 & 3;
    Text_Open(arg0, &local);
}

s32 Text_PrintIdList(s32 *a0, TextIdListEntry *a1, u32 a2) {
    s32 n = 0;

    while (a1->key != 0) {
        n++;
        Text_OpenPacked(a0, (s32)Cd_GetFileEntry((a1->key & 0xFFF) | 0x1FD0000),
                      a2 | ((a1->key & 0xF000) >> 10), a1->h);
        a1++;
        a0++;
    }
    return n;
}

void Text_PrintList(s32 *a0, Halves *a1, s32 *a2, u32 a3) {
    while (*a2 != 0) {
        Text_OpenPacked(a0, *a2, a3, *a1);
        a2++;
        a1++;
        a0++;
    }
}

s32 Text_WaitYesNo(s32 box) {
    s32 result = Text_IsFinished(box);
    if (result != 0) {
        result = Flag_Test(0x11) == 0 ? 1 : -1;
    }
    return result;
}

s32 Math_RampToOne(s32 arg0, s32 *arg1) {
    s32 v = *arg1 + 0x333;
    *arg1 = v;
    if (v >= 0x1000) {
        *arg1 = 0x1000;
        return 0;
    }
    return 1;
}

s32 Math_RampToZero(s32 arg0, s32 *arg1) {
    s32 v = *arg1 - 0x333;
    *arg1 = v;
    if (v <= 0) {
        *arg1 = 0;
        return 0;
    }
    return 1;
}

void Menu_SetPartsGridPos(void *arg0, s32 mask, s32 *arg2, s16 *arg3) {
    GfxPart *p = arg0;
    GfxPart *q = p;
    s32 x = arg3[2] + ((s16 *)arg2)[0] * arg3[4];
    s32 y = arg3[3] + ((s16 *)arg2)[1] * arg3[5];

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = x;
                q->y = y;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}


void Gfx_SetPartsPalette(GfxPart *p, s32 mask, s32 v) {
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->palette = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Menu_SetPartsPos(GfxPart *p, s32 mask, u16 *xy) {
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = xy[0];
                q->y = xy[1];
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

s32 Menu_BlinkOrHideParts(GfxPart *p, s32 mask, s32 n) {
    GfxPart *q;
    s32 r = 0;

    if (n <= 0) {
        r = mask;
    } else {
        q = p;
        if (p->fileId != 0) {
            do {
                if (q->groupMask & mask) {
                    q->palette = (Menu_Ctx->elapsed >> 2) & 3;
                }
                p++;
                q++;
            } while (p->fileId != 0);
        }
    }
    return r;
}

s32 Menu_MoveGridCursor(s32 a0, s32 a1, s32 a2) {
    Coord138C0 *p0 = (Coord138C0 *)a0;
    Coord138C0 *p1 = (Coord138C0 *)a1;
    Copy138C0 saved;
    s32 changed;

    changed = 0;
    saved = *(Copy138C0 *)p0;

    if (((PadRepeatView *)Pad_State)[a2].repeat & 0x8000) {
        if (p0->x > 0) {
            p0->x = p0->x - 1;
            goto tail;
        }
    }
    if (((PadRepeatView *)Pad_State)[a2].repeat & 0x2000) {
        if (p0->x < p1->x - 1) {
            p0->x = p0->x + 1;
            goto tail;
        }
    }
    if (((PadRepeatView *)Pad_State)[a2].repeat & 0x1000) {
        if (p0->y > 0) {
            p0->y = p0->y - 1;
            goto tail;
        }
    }
    if (((PadRepeatView *)Pad_State)[a2].repeat & 0x4000) {
        if (p0->y < p1->y - 1) {
            p0->y = p0->y + 1;
        }
    }

tail:
    if (saved.h[0] != p0->x || saved.h[1] != p0->y) {
        changed = -1;
    }
    return changed;
}

s32 Menu_MoveGridCursorP1(s32 arg0, s32 arg1) {
    return Menu_MoveGridCursor(arg0, arg1, 0);
}

s32 Menu_ScrollToShow(s32 *arg0, s32 arg1, s32 arg2) {
    s32 old = *arg0;

    if (arg2 - 1 < arg1 - old) {
        *arg0 = arg1 - (arg2 - 1);
    } else if (arg1 < old) {
        *arg0 = arg1;
    }
    return *arg0 - old;
}

s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1) {
    return arg1[1] * arg0[0] + arg0[1];
}

s32 Menu_GridIndexRowMajor(s16 *arg0, s16 *arg1) {
    return arg1[0] * arg0[1] + arg0[0];
}

s32 Cd_GetFileEntrySubPtr(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)Cd_GetFileEntry(arg0);
    s32 r = Cd_GetFileOrNull(arg0 >> 16);
    return p[arg1] + r;
}

void Text_FormatNumber(u8 *out, s32 val, s32 width) {
    u8 buf[8];
    s32 sign = 0;
    s32 done = 0;
    s32 i;

    if (width < 0) {
        width = -width;
        sign = 1;
    }
    if (val > 99999999) {
        val = 99999999;
    }
    for (i = 0; i < width; i++) {
        u8 *p = &buf[i];
        if (!done) {
            *p = val % 10;
        } else {
            *p = 0xFD;
        }
        val = val / 10;
        done = (val == 0);
    }
    for (i = width - 1; i >= 0; i--) {
        if (sign && buf[i] == 0xFD) {
            continue;
        }
        *out++ = buf[i];
    }
    *out = 0xFF;
}

void Menu_TopMenuInit(Actor *arg0, s16 arg1) {
    arg0->work->field_30 = arg1;
}

void Menu_TopMenuTask(Actor *a0) {
    MenuTopWork *w = (MenuTopWork *)a0->work;
    s32 *slot = (s32 *)a0->u34.children;
    Pair54 *tbl;
    s32 v;
    s32 k;
    s32 snd;

    switch (a0->stateLevel0) {
    case 0:
    default:
        Menu_Ctx = (MenuCtx *)Mem_Alloc(0x364, 2);
        Menu_Ctx->topMenuResult = 0;
        Menu_TopMenuResult = 0;
        *(Layout8C *)w->gridSize = *(Layout8C *)Cd_GetFileEntry(0x5130005);
        Menu_Ctx->flags = 0;
        v = Sys_GameMode[0];
        if (v / 256 != 2) {
            switch (v) {
            default:
                Menu_Ctx->flags = 2;
                break;
            case 0x32D ... 0x32E:
                Menu_Ctx->flags = 6;
                break;
            case 0x32A ... 0x32C:
                Menu_Ctx->flags = 4;
                break;
            }
        } else {
            Menu_Ctx->flags = 1;
            if (Flag_Test(0x67) == 0) {
                Menu_Ctx->flags |= 8;
            }
        }
        if (Digi_CountByState(0) == 0x24) {
            Menu_Ctx->flags = (Menu_Ctx->flags | 0x10) & ~2;
        }
        Menu_Ctx->elapsed = 0;
        Mem_FillWordsNeg1(&w->option0Text, 8);
        Task_NextState0(a0);
        Gfx_FadeInFromBlack(0x20);
        break;
    case 1:
        tbl = (Pair54 *)Cd_GetFileEntry(0x5130006);
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->ramp) != 0) {
                break;
            }
            Text_PrintIdList(&w->option0Text, (TextIdListEntry *)Cd_GetFileEntry(0x5130003), 2);
            Text_Close((Menu_Ctx->flags & 1) ? &w->option5Text : &w->option6Text);
            Text_SetColor(w->option1Text, (Menu_Ctx->flags >> 4) & 1);
            Text_SetColor(w->option2Text, (Menu_Ctx->flags >> 4) & 1);
            Text_SetColor(w->option3Text, (Menu_Ctx->flags >> 4) & 1);
            Text_SetColor(w->option4Text, !(Menu_Ctx->flags & 2));
            Text_SetColor(w->option5Text, !(Menu_Ctx->flags & 4));
            Text_SetColor(w->option6Text, !(Menu_Ctx->flags & 8));
            Task_NextState1(a0);
            break;
        case 1:
            if (Menu_MoveGridCursorP1((s32)w->cursor, (s32)w->gridSize) != 0) {
                snd = 0xC;
            } else if (Pad_State[0].cross > 0) {
                k = Menu_GridIndexColMajor(w->cursor, w->gridSize);
                if (k == 5 && (Menu_Ctx->flags & 1)) {
                    k = 6;
                }
                if ((u32)(k - 1) < 3 && (Menu_Ctx->flags & 0x10)) {
                    snd = 0x10;
                } else if (k == 4 && !(Menu_Ctx->flags & 2)) {
                    snd = 0x10;
                } else if (k == 5 && !(Menu_Ctx->flags & 4)) {
                    snd = 0x10;
                } else if (k == 6 && !(Menu_Ctx->flags & 8)) {
                    snd = 0x10;
                } else if (k == 5) {
                    Menu_Ctx->topMenuResult = 1;
                    Task_SetState0(a0, 2);
                    snd = 0xA;
                } else {
                    w->selection = k;
                    Task_NextState1(a0);
                    snd = 0xA;
                }
            } else {
                if (Pad_State[0].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(a0, 2);
                }
                break;
            }
            Snd_PlayById(snd, 0);
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(&w->option0Text, 8);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->ramp) == 0) {
                    Task_NextState1(a0);
                }
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Task_Create(tbl[w->selection].field_0, slot, tbl[w->selection].field_2);
                Task_NextState2(a0);
                break;
            case 1:
                if (*slot == 0) {
                    if (Menu_Ctx->topMenuResult != 0) {
                        Task_SetState0(a0, 2);
                    } else {
                        Task_SetState1(a0, 0);
                    }
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
            Text_CloseArray(&w->option0Text, 8);
            Menu_TopMenuResult = Menu_Ctx->topMenuResult;
            Task_NextState1(a0);
            Gfx_FadeOutToBlack(0x20);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->ramp) == 0) {
                Task_SetState0(a0, 3);
                Mem_Free((ActorWork *)Menu_Ctx);
            }
            break;
        }
        break;
    }
    if (Menu_Ctx != NULL) {
        Menu_Ctx->elapsed = a0->elapsed;
    }
}


void Menu_TopMenuDraw(Actor *actor) {
    MenuTopDrawWork *w = (MenuTopDrawWork *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    GfxPart *base;
    GfxPart *q;
    GfxPart *r;

    if (w->ramp != 0) {
        p = (s32 *)Cd_GetFileEntry(0x5130004);
        if (*p != 0) {
            i = 0;
            list = p;
            do {
                obj = Cd_GetFileEntry(*list);
                switch (i) {
                case 0:
                default:
                    Menu_SetPartsGridPos(obj, 2, &w->cursor, &w->gridSize);
                    Gfx_SetPartsPalette(obj, 2, (actor->elapsed >> 2) & 3);
                    break;
                case 1:
                    Gfx_SetPartsNumber(obj, 2, 8, Save_GameStatePtr->bits);
                    break;
                }
                Gfx_SetPartsScale(obj, 0x1000, w->ramp);
                list++;
                Gfx_DrawParts((s32)obj);
                i++;
            } while (*list != 0);
        }
    }
    base = (GfxPart *)Cd_GetFileEntry(0x459000C);
    for (q = base; q->fileId != 0; q++) {
        switch (q->groupMask) {
        case 2:
            q->palette = Math_CycleRange(actor->elapsed, 0xA, 0, 7);
            break;
        case 8:
            q->x -= 2;
            if (q->x == -0x168) {
                q->x = 0;
            }
            break;
        case 0x10:
            q->x += 1;
            if (q->x == 0xD8) {
                q->x = 0;
            }
            break;
        case 0x20:
            q->x -= 2;
            if (q->x == -0x1C0) {
                q->x = 0;
            }
            break;
        }
    }
    Gfx_DrawParts((s32)base);
}
