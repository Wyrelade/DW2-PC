#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/stag1100_funcs.h"
#include "stag1100/bg.h"
#include "stag1100/modemenu.h"
#include "stag1100/cardmenu.h"
#include "stag1100/vsparty.h"

Layout8C Stg11_VsPartyLayout = { { 1, 1, -60, -66, 0, 0x21 } };
Halves Stg11_VsPromptPos = { 0x10, 0xBA };
Halves D_80068208 = { 0x21, 0x9E };
u16 Stg11_VsRowMasks[] = { 0x0E04, 0x0E04, 0x0C04, 0x0A04, 0x0604 };
TaskDesc Stg11_VsPartyDesc = {
    (TaskInitFn)Stg11_VsPartyInit, Stg11_VsPartyUpdate, Task_DefaultDestroy, Stg11_VsPartyDraw, 0x1A8, 4,
};

/* .bss (stag1100.h order) */
Stg11Party Stg11_VsParty;
s16 Stg11_LoadDone;

void Stg11_VsPartyBuildList(Stg11VsPartyWork *arg0) {
    Stg11Slot *s = arg0->rows;
    Stg11Party *pt = &Stg11_VsParty;
    DigiRosterEntry *e;
    s32 i;
    s32 n;

    for (i = 0; i < 0x26; i++) {
        s[i].rowState = 0;
        s[i].kind = 0;
    }
    arg0->menu.grid[0] = 1;
    arg0->menu.grid[1] = 0;
    n = arg0->kind < 3 ? 3 : 0x24;
    if (arg0->kind < 3) {
        e = pt->members;
    } else {
        e = pt->gameState->elems;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->state == 0) {
            break;
        }
        s->kind = 1;
        s->entry = e;
        s->rowState = arg0->kind < 3 ? i + 3 : 2;
        s++;
        arg0->menu.grid[1]++;
    }
    arg0->rosterCount = 0;
    e = pt->gameState->elems;
    for (i = 0; i < 0x24; i++, e++) {
        if (e->state != 0) {
            arg0->rosterCount++;
        }
    }
}

void Stg11_VsPartyOpenRowText(Stg11VsPartyWork *arg0, u8 arg1) {
    TextDesc st;
    Stg11Slot *s;
    s32 i;

    st.strArg0 = 0;
    st.packedStyle = arg1;
    st.color = 0;
    for (i = 0; i < 16; i++) {
        Text_Close(&arg0->texts[i]);
    }
    s = &arg0->rows[arg0->scrollTop];
    for (i = 0; i < 4; s++, i++) {
        if (s->kind != 0) if (s->kind == 1) {
            st.x = 0x6D;
            st.y = i * 0x21 + 0x3E;
            st.text = (s32)Cd_GetFileEntry(0x1FD0082);
            Text_OpenDesc(&arg0->texts[i * 4], &st);
            st.x = 0xD0;
            st.y = i * 0x21 + 0x3E;
            st.text = (s32)Cd_GetFileEntry(0x1FD00BB);
            Text_OpenDesc(&arg0->texts[i * 4 + 1], &st);
            st.y = i * 0x21 + 0x32;
            st.x = 0x6D;
            st.text = (s32)s->entry->name;
            Text_OpenDesc(&arg0->texts[i * 4 + 2], &st);
            st.x = 0xD0;
            st.y = i * 0x21 + 0x32;
            st.text = (s32)Digi_GetDefaultName(s->entry->digiId);
            Text_OpenDesc(&arg0->texts[i * 4 + 3], &st);
        }
    }
}

void Stg11_VsPartyPick(Actor *arg0) {
    Stg11VsPartyWork *w = (Stg11VsPartyWork *)arg0->work;
    s32 idx;
    Stg11Slot *s;
    s32 i;
    DigiRosterEntry *d;

    idx = Menu_GridIndexColMajor((s16 *)&w->cursor, w->menu.grid);
    s = &w->rows[idx];
    if (s->rowState != 2) {
        Snd_PlayById(0x10, 0);
        return;
    }
    s->rowState = w->pickCount + 3;
    w->pickedRows[w->pickCount++] = idx;
    Snd_PlayById(0xE, 0);
    if (w->pickCount < 3) {
        Task_SetState1(arg0, 1);
        return;
    }
    for (i = 0; i < 3; i++) {
        d = w->rows[w->pickedRows[i]].entry;
        Stg11_VsParty.members[i] = *d;
    }
    Task_SetState0(arg0, 2);
}

void Stg11_VsPartyUnpick(Actor *arg0) {
    Stg11VsPartyWork *w = (Stg11VsPartyWork *)arg0->work;

    if (w->pickCount == 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(arg0, 2);
    } else {
        w->pickCount--;
        (w->rows + w->pickedRows[w->pickCount])->rowState = 2;
        w->pickedRows[w->pickCount] = 0;
        Snd_PlayById(0xB, 0);
        Task_SetState1(arg0, 1);
    }
}

void Stg11_VsPartyInit(Actor *arg0, s16 arg1) {
    Stg11VsPartyWork *w = (Stg11VsPartyWork *)arg0->work;
    w->kind = arg1;
    w->padIndex = (arg1 - 1) % 2;
    w->isRosterList = w->kind >= 3;
}

void Stg11_VsPartyUpdate(Actor *arg0) {
    Stg11VsPartyWork *w = (Stg11VsPartyWork *)arg0->work;
    s32 *slot;
    s32 r;
    s32 r3;
    s32 *slot2;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        w->menu.layout = Stg11_VsPartyLayout;
        w->scrollTop = 0;
        w->cursor.y = 0;
        w->cursor.x = 0;
        Stg11_VsPartyBuildList(w);
        Mem_FillWordsNeg1(w->texts, 0x14);
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(arg0, &w->scale) == 0) {
                Stg11_VsPartyOpenRowText(w, 1);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            switch (w->kind) {
            case 1:
            case 2:
            default:
                if (w->rosterCount >= 4) {
                    Task_SetState1(arg0, 3);
                } else {
                    Task_SetState1(arg0, 4);
                }
                break;
            case 3:
            case 4:
                Text_OpenPacked(&w->texts[0x10], (s32)Cd_GetFileEntry(w->pickCount + 0x1FD0109), 0x80, Stg11_VsPromptPos);
                Text_OpenPacked(&w->texts[0x12], (s32)Cd_GetFileEntry(0x1FD00FA), 0, D_80068208);
                Task_NextState1(arg0);
                break;
            }
            break;
        case 2:
            if (Menu_MoveGridCursor((s16 *)&w->cursor, w->menu.grid, w->padIndex) == 0) {
                if (Pad_State[w->padIndex].triangle > 0) {
                    Stg11_VsPartyUnpick(arg0);
                } else if (Pad_State[w->padIndex].cross > 0) {
                    Stg11_VsPartyPick(arg0);
                }
            } else {
                Snd_PlayById(0xD, 0);
                if (w->cursor.y - w->scrollTop >= 4) {
                    w->scrollTop = w->cursor.y - 3;
                    Stg11_VsPartyOpenRowText(w, 0);
                } else if (w->cursor.y < w->scrollTop) {
                    w->scrollTop = w->cursor.y;
                    Stg11_VsPartyOpenRowText(w, 0);
                }
                Task_SetState1(arg0, 1);
            }
            break;
        case 3:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->texts[0x10], (s32)Cd_GetFileEntry(0x1FD01A9), 0x81, Stg11_VsPromptPos);
                Text_SetInputPad(w->texts[0x10], w->padIndex);
                Task_NextState2(arg0);
                break;
            case 1:
                r3 = Text_WaitYesNo(w->texts[0x10]);
                if (r3 != 0) {
                    if (r3 == 1) {
                        Task_SetState1(arg0, 5);
                    } else {
                        Task_SetState1(arg0, 4);
                    }
                }
                break;
            }
            break;
        case 4:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->texts[0x10], (s32)Cd_GetFileEntry(0x1FD01AA), 0x81, Stg11_VsPromptPos);
                Text_SetInputPad(w->texts[0x10], w->padIndex);
                Task_NextState2(arg0);
                break;
            case 1:
                r = Text_WaitYesNo(w->texts[0x10]);
                if (r != 0) {
                    if (r == 1) {
                        Sys_VsPartyConfirmed = r;
                        Stg11_LoadDone = r;
                    }
                    Task_SetState0(arg0, 2);
                }
                break;
            }
            break;
        case 5:
            slot = (s32 *)arg0->u34.children;
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(w->texts, 0x14);
                Task_NextState2(arg0);
                break;
            case 1:
                if (Math_RampToZero(arg0, &w->scale) == 0) {
                    Task_Create(0x605, slot, w->padIndex + 3);
                    Task_NextState2(arg0);
                }
                break;
            case 2:
                if (*slot == 0) {
                    Task_SetState0(arg0, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        slot2 = (s32 *)arg0->u34.children;
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (*slot2 != 0) {
                Task_SetState0((Actor *)*slot2, 2);
            }
            Text_CloseArray(w->texts, 0x14);
            Task_NextState1(arg0);
            break;
        case 1:
            if (*slot2 == 0) {
                Task_NextState1(arg0);
            }
            break;
        case 2:
            if (Math_RampToZero(arg0, &w->scale) == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    }
}

void Stg11_VsPartyDraw(Actor *arg0) {
    Stg11VsPartyWork *w = (Stg11VsPartyWork *)arg0->work;
    s32 *ids;
    GfxPart *parts;
    Stg11Slot *e;
    DigiRosterEntry *cell;
    Stg11Pos p;
    s32 i;
    s32 k;
    s32 mask;
    s32 pal;
    s32 top;

    if (w->scale == 0) {
        return;
    }
    ids = (s32 *)Cd_GetFileEntry(0xD28000D);
    for (i = 0; ids[i] != 0; i++) {
        parts = (GfxPart *)Cd_GetFileEntry(ids[i]);
        if (i == 0) {
            if (w->isRosterList != 0) {
                p = w->cursor;
                p.y = w->cursor.y - w->scrollTop;
                Menu_SetPartsGridPos(parts, 2, (s32 *)&p, w->menu.grid);
                Gfx_SetPartsPalette(parts, 2, (arg0->elapsed >> 2) & 3);
                mask = (w->scrollTop < 1) << 2;
                if (w->menu.grid[1] - w->scrollTop - 4 <= 0) {
                    mask |= 8;
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, mask);
                Gfx_SetPartsNumber(parts, 0x10, 2, w->cursor.y + 1);
                Gfx_SetPartsNumber(parts, 0x20, 2, w->menu.grid[1]);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, -1);
            }
        } else {
            top = w->scrollTop - 1;
            e = &w->rows[top + i];
            k = i - 1;
            if (k >= w->menu.grid[1]) {
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, -1);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, 0);
                pal = 2;
                if (w->isRosterList != 0 && k == w->cursor.y - w->scrollTop) {
                    pal = 1;
                }
                switch (e->kind) {
                case 0:
                    Gfx_HidePartsByMask((GfxPartMaskView *)parts, pal | 0xFE4);
                    break;
                case 1:
                    cell = e->entry;
                    Gfx_HidePartsByMask((GfxPartMaskView *)parts, pal | Stg11_VsRowMasks[e->rowState - 1]);
                    Gfx_SetPartsNumber(parts, 0x20, 3, (s16)cell->maxHp);
                    Gfx_SetPartsNumber(parts, 0x40, 3, (s16)cell->hp);
                    Gfx_SetPartsNumber(parts, 0x80, 3, (s16)cell->maxMp);
                    Gfx_SetPartsNumber(parts, 0x100, 3, (s16)cell->mp);
                    break;
                case 2:
                case 3:
                    Gfx_HidePartsByMask((GfxPartMaskView *)parts, -5);
                    break;
                }
            }
        }
        Gfx_SetPartsScale((GfxPartScaleView *)parts, 0x1000, w->scale);
        Gfx_DrawParts(parts);
    }
}
