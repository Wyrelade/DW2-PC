#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/stag1100_funcs.h"
#include "stag1100/stag1100_301C_funcs.h"

Layout8C Stg11_VsPartyLayout = { { 1, 1, -60, -66, 0, 0x21 } };
Halves Stg11_VsPromptPos = { 0x10, 0xBA };
Halves D_80068208 = { 0x21, 0x9E };
u16 Stg11_VsRowMasks[] = { 0x0E04, 0x0E04, 0x0C04, 0x0A04, 0x0604 };
TaskDesc Stg11_VsPartyDesc = {
    (TaskInitFn)Stg11_VsPartyInit, Stg11_VsPartyUpdate, Task_DefaultDestroy, Stg11_VsPartyDraw, 0x1A8, 4,
};
/* Memory card icon frames (TIM files). */
INCLUDE_BIN(Stg11_CardIconTim1, "assets/stag1100/card_icon1.tim");
INCLUDE_BIN(Stg11_CardIconTim2, "assets/stag1100/card_icon2.tim");
INCLUDE_BIN(Stg11_CardIconTim3, "assets/stag1100/card_icon3.tim");
BIN_LABEL(Stg11_CardIconImage, Stg11_CardIconTim1, 0x14);
BIN_LABEL(Stg11_CardIcon2, Stg11_CardIconTim2, 0x40);
BIN_LABEL(Stg11_CardIcon3, Stg11_CardIconTim3, 0x40);
TaskDesc Stg11_CardTaskDesc = {
    (TaskInitFn)Stg11_CardTaskInit, Stg11_CardTaskUpdate, Stg11_CardTaskDestroy, (TaskFn)Stg11_CardTaskDraw,
    0x22044, 0,
};
/* Task_DescTable[6]: task ids 0x600-0x606. */
TaskDesc *Stg11_TaskDescs[] = {
    &Stg11_RootDesc, &Stg11_CardTaskDesc, &Stg11_BgDesc, &Stg11_ModeMenuDesc,
    &Stg11_CardMenuDesc, &Stg11_VsPartyDesc, &Stg11_ModeMenuDesc,
};
/* Unreferenced. */
u8 D_800684A4[4] = "AAA\\";
Stg11Party Stg11_VsParty = { 0 };
s16 Stg11_LoadDone = 0;
/* Unreferenced. */
s16 D_800685CA = 0;
s32 D_800685CC = 0;
Actor *Stg11_CardTask = 0;
Stg11SaveWork *Stg11_CardWork = 0;

void Stg11_CardMenuDraw(Actor *arg0) {
    Stg11MenuWork *w = (Stg11MenuWork *)arg0->work;
    s32 *ids;
    GfxPart *parts;
    s32 *tbl;
    s32 *tblA;
    Stg11SaveSlot *slot;
    Stg11PolyG4 *p;
    u32 *ot;
    s32 i;
    s32 mask;
    s32 m1;
    s32 bit;
    Stg11SaveList *list;
    u32 t;
    s32 h;

    if (w->fade != 0) {
        ids = (s32 *)Cd_GetFileEntry(0xD280007);
        for (i = 0; ids[i] != 0; i++) {
            parts = (GfxPart *)Cd_GetFileEntry(ids[i]);
            switch (i) {
            case 0:
                tbl = (s32 *)Cd_GetFileEntry(0xD280008);
                bit = (w->listMode == 2) << 4;
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, tbl[w->menuKind - 1] & ~bit);
                break;
            case 1:
                tbl = (s32 *)Cd_GetFileEntry(0xD280009);
                m1 = tbl[w->listMode];
                if (w->progressMode == 0) {
                    m1 |= 0x20;
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, m1);
                if (w->listMode == 1) {
                    Menu_SetPartsGridPos(parts, 2, (s32 *)w->cursor, w->u6C.gridSize);
                    Gfx_SetPartsPalette(parts, 2, (arg0->elapsed >> 2) & 3);
                }
                if (w->listMode == 2) {
                    Menu_SetPartsGridPos(parts, 0x10, (s32 *)w->cursor, w->u6C.gridSize);
                }
                break;
            default:
                tblA = (s32 *)Cd_GetFileEntry(0xD28000A);
                list = w->saveList;
                mask = -1;
                if (w->listMode == 1) {
                    mask = tblA[1];
                    slot = &list->slots[i - 2];
                    if (list->used[i - 2] != 0) {
                        t = slot->u.hdr.playTime;
                        if (t > 0x14996FF) {
                            t = 0x14996FF;
                        }
                        Gfx_SetPartsNumber(parts, 0x10, 8, slot->u.hdr.money);
                        h = t / 216000;
                        Gfx_SetPartsNumber(parts, 0x20, -4, h * 100 + (t / 3600 - h * 60));
                    } else {
                        Gfx_SetPartsNumber(parts, 0x10, 8, 0);
                        Gfx_SetPartsNumber(parts, 0x20, -4, 0);
                    }
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, mask);
                break;
            }
            Gfx_SetPartsScale((GfxPartScaleView *)parts, 0x1000, w->fade);
            Gfx_DrawParts(parts);
        }
    }
    if (w->progressMode != 0) {
        p = (Stg11PolyG4 *)Sys_State.packet.addr;
        ot = Sys_State.otLayers.u[0];
        p->tag.b.len = 8;
        p->code = 0x38;
        p->r0 = 0xD;
        p->g0 = 0x66;
        p->b0 = 0x11;
        p->r1 = 0xFF;
        p->g1 = 0x96;
        p->b1 = 0;
        p->r2 = 0xD;
        p->g2 = 0x66;
        p->b2 = 0x11;
        p->r3 = 0xFF;
        p->g3 = 0x96;
        p->b3 = 0;
        p->code &= ~2;
        p->x0 = 0x12;
        p->y0 = 0x2A;
        p->x1 = w->progress + 0x12;
        p->y1 = 0x2A;
        p->x2 = 0x12;
        p->y2 = 0x35;
        p->x3 = w->progress + 0x12;
        p->y3 = 0x35;
        p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        Sys_State.packet.addr = (s32)(p + 1);
    }
}

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
                        D_80050780 = r;
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

/* Memory card title: "Digimon World 2" in Shift-JIS full-width letters. */
const u8 Stg11_CardTitle[32] = "\x82\x63\x82\x89\x82\x87\x82\x89\x82\x8D\x82\x8F\x82\x8E"
                               "\x82\x76\x82\x8F\x82\x92\x82\x8C\x82\x84\x82\x51";
void Stg11_CardInitHeader(void) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    struct Stg11CardBlock *h = &w->u34.s;
    struct Stg11CardBlock *h2 = h;
    u8 *data = w->u34.s.data;

    h->magic[0] = 'S';
    h->magic[1] = 'C';
    h->iconFlag = 0x13;
    h->blocks = 2;
    Stg11_CardSetTitle(Stg11_CardTitle);
    memset(h->reserved, 0, 0x1C);
    h->clut = Stg11_CardIconImage.clut;
    h->icons[0] = Stg11_CardIconImage.icon;
    h2->icons[1] = Stg11_CardIcon2;
    h2->icons[2] = Stg11_CardIcon3;
    memset(data, 0, 0x3DFC);
    h->version = 0x102;
}

u8 *Stg11_CardGetDataBuf(void) {
    return ((Stg11SaveWork *)Stg11_CardTask->work)->u34.s.data;
}

u8 *Stg11_CardGetTransferBuf(void) {
    return ((Stg11SaveWork *)Stg11_CardTask->work)->transferBuf;
}

void Stg11_CardSetTitle(const u8 *arg0) {
    s32 i = 0;
    u8 *d = ((Stg11SaveWork *)Stg11_CardTask->work)->u34.s.title;
    u8 c;

    memset(d, i, 0x40);
loop:
    c = *arg0++;
    if (c == 0) {
        return;
    }
    *d++ = c;
    *d++ = *arg0++;
    if (++i < 0x20) {
        goto loop;
    }
}

void Stg11_CardStartOp(u8 arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    Task_SetState1(Stg11_CardTask, arg0);
    w->port = arg1;
    w->portResult[arg1][0] = -1;
    w->result = -1;
    w->progressTotal = -1;
    w->opStarted = 0;
}

s32 Stg11_CardGetResult(void) {
    return ((Stg11SaveWork *)Stg11_CardTask->work)->result;
}

void Stg11_CardSetFileName(const u8 *arg0, u8 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    strcpy(w->fileName, arg0);
    w->isTransferFile = arg1;
}

s32 Stg11_CardGetProgress(s32 arg0) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    s32 d = w->progressTotal;
    s32 r;

    if (d != 0) {
        if (d < 0) {
            r = 0;
        } else {
            r = arg0 * w->progressDone / d;
        }
    } else {
        r = arg0;
    }
    return r;
}

s32 Stg11_CardChecksum(Stg11SaveWork *arg0) {
    u16 *p = arg0->u34.sum;
    u16 sum = 0;
    s32 n = 0x1FFF;

    while (1) {
        if (--n == -1) {
            break;
        }
        sum ^= *p++;
        if (--n == -1) {
            break;
        }
        sum += *p++;
    }
    return sum;
}

s32 Stg11_CardFileOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    s32 chan = (arg2 != 0) << 4;
    s32 cmd;
    s32 st;

    if (MemCardSync(1, &cmd, &st) == -1) {
        switch (arg1) {
        case 6:
            st = MemCardCreateFile(chan, (s32)Stg11_CardWork->fileName, 2);
            switch (st) {
            case 1:
                r = 0;
                break;
            case 4:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 1;
                }
                break;
            default:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 6;
                }
                break;
            case 7:
                r = 8;
                break;
            case 0:
            case 6:
                r = 9;
                break;
            }
            break;
        case 7:
            st = MemCardOpen(chan, (s32)Stg11_CardWork->fileName, 1);
            switch (st) {
            case 0:
                r = 9;
                Card_CloseFile();
                break;
            case 1:
                r = 0;
                break;
            case 2:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 0xB;
                }
                break;
            case 4:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 1;
                }
                break;
            case 3:
            case 5:
            default:
                r = 0xA;
                break;
            }
            break;
        case 8:
            st = MemCardFormat(chan);
            switch (st) {
            case 2:
            default:
                if (++arg0->retryCount >= 5) {
                    r = 7;
                }
                break;
            case 1:
                r = 0;
                break;
            case 0:
                r = 0x10;
                break;
            }
            break;
        }
    }
    return r;
}

s32 Stg11_CardAsyncOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    s32 chan = (arg2 != 0) << 4;
    s32 cmd;
    s32 st;
    s32 sum;

    switch (MemCardSync(1, &cmd, &st)) {
    default:
        if (arg0->progressDone < arg0->progressTotal) {
            arg0->progressDone++;
        }
        break;
    case -1:
        arg0->progressTotal = 1;
        arg0->progressDone = 0;
        arg0->opStarted = 1;
        switch (arg1) {
        case 1:
            MemCardExist(chan);
            break;
        case 2:
            arg0->progressTotal = 0x26;
            MemCardAccept(chan);
            break;
        case 3:
            arg0->progressTotal = 0x83;
            arg0->u34.s.checksum = Stg11_CardChecksum(arg0);
            MemCardWriteFile(chan, (s32)arg0->fileName, (s32)&arg0->u34, 0, 0x4000);
            break;
        case 4:
            if (arg0->isTransferFile == 0) {
                arg0->progressTotal = 0x81;
                MemCardReadFile(chan, (s32)arg0->fileName, (s32)&arg0->u34, 0, 0x4000);
            } else {
                arg0->progressTotal = 0x3C8;
                MemCardReadFile(chan, (s32)arg0->fileName, (s32)arg0->transferBuf, 0, 0x1E000);
            }
            break;
        }
        break;
    case 1:
        if (arg0->opStarted == 0) {
            return -1;
        }
        arg0->progressDone = arg0->progressTotal;
        switch (arg1) {
        case 1:
            if (cmd == arg1) {
                switch (st) {
                case 0:
                case 3:
                    r = 2;
                    break;
                case 1:
                case 2:
                    r = 0;
                    break;
                }
            }
            break;
        case 2:
            if (cmd == arg1) {
                switch (st) {
                case 0:
                case 3:
                    r = 2;
                    break;
                case 1:
                    r = 0;
                    break;
                case 2:
                default:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 0xB;
                    }
                    break;
                case 4:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 1;
                    }
                    break;
                }
            }
            break;
        case 3:
            if (cmd == 4) {
                switch (st) {
                case 0:
                    r = 0xC;
                    break;
                case 1:
                    r = 0;
                    break;
                case 2:
                case 4:
                default:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 5;
                    }
                    break;
                case 3:
                    r = 0xF;
                    break;
                case 5:
                    r = 0xA;
                    break;
                }
            }
            break;
        case 4:
            if (cmd == 3) {
                switch (st) {
                case 0:
                    r = 0xD;
                    if (arg0->isTransferFile == 0) {
                        sum = arg0->u34.s.checksum;
                        if (sum == Stg11_CardChecksum(arg0) && arg0->u34.s.version == 0x102) {
                            r = 0xD;
                        } else {
                            r = 0xE;
                        }
                    }
                    break;
                case 1:
                    r = 0;
                    break;
                case 5:
                    r = 0xA;
                    break;
                case 2:
                case 4:
                default:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 4;
                    }
                    break;
                case 3:
                    r = 0xF;
                    break;
                }
            }
            break;
        }
        break;
    }
    return r;
}

void Stg11_CardRunOp(Actor *arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)arg0->work;
    s32 *p;

    switch (arg0->stateLevel2) {
    case 1:
        break;
    case 0:
    default:
        w->portResult[w->port][0] = -1;
        w->retryCount = 0;
        Task_SetState2(arg0, 10);
        break;
    case 10:
        p = &w->portResult[w->port][0];
        if (arg1 < 5) {
            *p = Stg11_CardAsyncOp(w, arg1, w->port);
        } else {
            *p = Stg11_CardFileOp(w, arg1, w->port);
        }
        if (*p != -1) {
            Task_SetState2(arg0, 1);
        }
        break;
    }
    w->result = w->portResult[w->port][0];
}

void Stg11_CardTaskInit(void) {
}

void Stg11_CardTaskUpdate(Actor *arg0) {
    Stg11SaveWork *w = (Stg11SaveWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        Stg11_CardTask = arg0;
        Stg11_CardWork = (Stg11SaveWork *)arg0->work;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 4:
            Stg11_CardRunOp(arg0, 2);
            break;
        case 2:
            Stg11_CardRunOp(arg0, 1);
            break;
        case 7:
            Stg11_CardRunOp(arg0, 6);
            break;
        case 5:
            Stg11_CardRunOp(arg0, 7);
            break;
        case 6:
            Stg11_CardRunOp(arg0, 8);
            break;
        case 8:
            Stg11_CardRunOp(arg0, 3);
            break;
        case 9:
            Stg11_CardRunOp(arg0, 4);
            break;
        case 0:
        case 1:
        case 3:
            break;
        }
        break;
    case 2:
        break;
    }
    w->curOp = arg0->stateLevel1;
}

void Stg11_CardTaskDestroy(Actor *arg0) {
    Task_DefaultDestroy(arg0);
}

void Stg11_CardTaskDraw(void) {
}
