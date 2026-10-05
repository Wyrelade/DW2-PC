#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"

/* Declarations the original file made before this code. */
extern void Task_Create(u32, s32 *, s32);

/* Small data this unit defines: initialised ones go to .sdata, the rest to .sbss in
 * game.h's order. Retail reaches them with %gp_rel here. */
s32 Menu_TopMenuResult;
MenuCtx *Menu_Ctx;

/* Task callbacks the descriptors below name (defined further down). */
void Task_DefaultDestroy(Actor *arg0);
void Menu_TopMenuInit(Actor *arg0, s16 arg1);
void Menu_TopMenuTask(Actor *a0);
void Menu_TopMenuDraw(Actor *actor);

TaskDesc D_80040E9C = {
    (TaskInitFn)Menu_TopMenuInit, Menu_TopMenuTask, Task_DefaultDestroy, Menu_TopMenuDraw, 0x38, 4,
};

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
