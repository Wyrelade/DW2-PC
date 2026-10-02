#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/stag1100_funcs.h"

void func_8006637C(Actor *arg0) {
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

    if (w->field_8C != 0) {
        ids = (s32 *)Cd_GetFileEntry(0xD280007);
        for (i = 0; ids[i] != 0; i++) {
            parts = (GfxPart *)Cd_GetFileEntry(ids[i]);
            switch (i) {
            case 0:
                tbl = (s32 *)Cd_GetFileEntry(0xD280008);
                bit = (w->field_86 == 2) << 4;
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, tbl[w->field_78 - 1] & ~bit);
                break;
            case 1:
                tbl = (s32 *)Cd_GetFileEntry(0xD280009);
                m1 = tbl[w->field_86];
                if (w->field_94 == 0) {
                    m1 |= 0x20;
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, m1);
                if (w->field_86 == 1) {
                    Menu_SetPartsGridPos(parts, 2, (s32 *)w->cursor, w->u6C.gridSize);
                    Gfx_SetPartsPalette(parts, 2, (arg0->elapsed >> 2) & 3);
                }
                if (w->field_86 == 2) {
                    Menu_SetPartsGridPos(parts, 0x10, (s32 *)w->cursor, w->u6C.gridSize);
                }
                break;
            default:
                tblA = (s32 *)Cd_GetFileEntry(0xD28000A);
                list = w->field_90;
                mask = -1;
                if (w->field_86 == 1) {
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
            Gfx_SetPartsScale((GfxPartScaleView *)parts, 0x1000, w->field_8C);
            Gfx_DrawParts(parts);
        }
    }
    if (w->field_94 != 0) {
        p = (Stg11PolyG4 *)D_8005F770.packet.addr;
        ot = D_8005F770.otLayers.u[0];
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
        p->x1 = w->field_96 + 0x12;
        p->y1 = 0x2A;
        p->x2 = 0x12;
        p->y2 = 0x35;
        p->x3 = w->field_96 + 0x12;
        p->y3 = 0x35;
        p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        D_8005F770.packet.addr = (s32)(p + 1);
    }
}

void func_80066748(Stg11Work66C04 *arg0) {
    Stg11Slot *s = arg0->field_6C;
    Stg11Party *pt = &D_800684A8;
    DigiRosterEntry *e;
    s32 i;
    s32 n;

    for (i = 0; i < 0x26; i++) {
        s[i].field_2 = 0;
        s[i].field_0 = 0;
    }
    arg0->field_54.grid[0] = 1;
    arg0->field_54.grid[1] = 0;
    n = arg0->field_60 < 3 ? 3 : 0x24;
    if (arg0->field_60 < 3) {
        e = pt->field_4;
    } else {
        e = pt->field_0->elems;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->state == 0) {
            break;
        }
        s->field_0 = 1;
        s->field_4 = e;
        s->field_2 = arg0->field_60 < 3 ? i + 3 : 2;
        s++;
        arg0->field_54.grid[1]++;
    }
    arg0->field_6A = 0;
    e = pt->field_0->elems;
    for (i = 0; i < 0x24; i++, e++) {
        if (e->state != 0) {
            arg0->field_6A++;
        }
    }
}

void func_80066860(Stg11Work66C04 *arg0, u8 arg1) {
    TextDesc st;
    Stg11Slot *s;
    s32 i;

    st.strArg0 = 0;
    st.packedStyle = arg1;
    st.color = 0;
    for (i = 0; i < 16; i++) {
        Text_Close(&arg0->field_0[i]);
    }
    s = &arg0->field_6C[arg0->field_66];
    for (i = 0; i < 4; s++, i++) {
        if (s->field_0 != 0) if (s->field_0 == 1) {
            st.x = 0x6D;
            st.y = i * 0x21 + 0x3E;
            st.text = (s32)Cd_GetFileEntry(0x1FD0082);
            Text_OpenDesc(&arg0->field_0[i * 4], &st);
            st.x = 0xD0;
            st.y = i * 0x21 + 0x3E;
            st.text = (s32)Cd_GetFileEntry(0x1FD00BB);
            Text_OpenDesc(&arg0->field_0[i * 4 + 1], &st);
            st.y = i * 0x21 + 0x32;
            st.x = 0x6D;
            st.text = (s32)s->field_4->name;
            Text_OpenDesc(&arg0->field_0[i * 4 + 2], &st);
            st.x = 0xD0;
            st.y = i * 0x21 + 0x32;
            st.text = (s32)Digi_GetDefaultName(s->field_4->digiId);
            Text_OpenDesc(&arg0->field_0[i * 4 + 3], &st);
        }
    }
}

void func_80066A0C(Actor *arg0) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;
    s32 idx;
    Stg11Slot *s;
    s32 i;
    DigiRosterEntry *d;

    idx = Menu_GridIndexColMajor((s16 *)&w->field_50, w->field_54.grid);
    s = &w->field_6C[idx];
    if (s->field_2 != 2) {
        Snd_PlayById(0x10, 0);
        return;
    }
    s->field_2 = w->field_1A0 + 3;
    w->field_1A2[w->field_1A0++] = idx;
    Snd_PlayById(0xE, 0);
    if (w->field_1A0 < 3) {
        Task_SetState1(arg0, 1);
        return;
    }
    for (i = 0; i < 3; i++) {
        d = w->field_6C[w->field_1A2[i]].field_4;
        D_800684A8.field_4[i] = *d;
    }
    Task_SetState0(arg0, 2);
}

void func_80066B60(Actor *arg0) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;

    if (w->field_1A0 == 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(arg0, 2);
    } else {
        w->field_1A0--;
        (w->field_6C + w->field_1A2[w->field_1A0])->field_2 = 2;
        w->field_1A2[w->field_1A0] = 0;
        Snd_PlayById(0xB, 0);
        Task_SetState1(arg0, 1);
    }
}

void func_80066C04(Actor *arg0, s16 arg1) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;
    w->field_60 = arg1;
    w->field_64 = (arg1 - 1) % 2;
    w->field_68 = w->field_60 >= 3;
}

void func_80066C48(Actor *arg0) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;
    s32 *slot;
    s32 r;
    s32 r3;
    s32 *slot2;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        w->field_54.layout = D_800681F8;
        w->field_66 = 0;
        w->field_50.y = 0;
        w->field_50.x = 0;
        func_80066748(w);
        Mem_FillWordsNeg1(w->field_0, 0x14);
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(arg0, &w->scale) == 0) {
                func_80066860(w, 1);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            switch (w->field_60) {
            case 1:
            case 2:
            default:
                if (w->field_6A >= 4) {
                    Task_SetState1(arg0, 3);
                } else {
                    Task_SetState1(arg0, 4);
                }
                break;
            case 3:
            case 4:
                Text_OpenPacked(&w->field_0[0x10], (s32)Cd_GetFileEntry(w->field_1A0 + 0x1FD0109), 0x80, D_80068204);
                Text_OpenPacked(&w->field_0[0x12], (s32)Cd_GetFileEntry(0x1FD00FA), 0, D_80068208);
                Task_NextState1(arg0);
                break;
            }
            break;
        case 2:
            if (Menu_MoveGridCursor((s16 *)&w->field_50, w->field_54.grid, w->field_64) == 0) {
                if (D_8005F6F0[w->field_64].triangle > 0) {
                    func_80066B60(arg0);
                } else if (D_8005F6F0[w->field_64].cross > 0) {
                    func_80066A0C(arg0);
                }
            } else {
                Snd_PlayById(0xD, 0);
                if (w->field_50.y - w->field_66 >= 4) {
                    w->field_66 = w->field_50.y - 3;
                    func_80066860(w, 0);
                } else if (w->field_50.y < w->field_66) {
                    w->field_66 = w->field_50.y;
                    func_80066860(w, 0);
                }
                Task_SetState1(arg0, 1);
            }
            break;
        case 3:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->field_0[0x10], (s32)Cd_GetFileEntry(0x1FD01A9), 0x81, D_80068204);
                Text_SetInputPad(w->field_0[0x10], w->field_64);
                Task_NextState2(arg0);
                break;
            case 1:
                r3 = func_800136A4(w->field_0[0x10]);
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
                Text_OpenPacked(&w->field_0[0x10], (s32)Cd_GetFileEntry(0x1FD01AA), 0x81, D_80068204);
                Text_SetInputPad(w->field_0[0x10], w->field_64);
                Task_NextState2(arg0);
                break;
            case 1:
                r = func_800136A4(w->field_0[0x10]);
                if (r != 0) {
                    if (r == 1) {
                        D_80050780 = r;
                        D_800685C8 = r;
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
                Text_CloseArray(w->field_0, 0x14);
                Task_NextState2(arg0);
                break;
            case 1:
                if (Math_RampToZero(arg0, &w->scale) == 0) {
                    Task_Create(0x605, slot, w->field_64 + 3);
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
            Text_CloseArray(w->field_0, 0x14);
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

void func_80067124(Actor *arg0) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;
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
            if (w->field_68 != 0) {
                p = w->field_50;
                p.y = w->field_50.y - w->field_66;
                Menu_SetPartsGridPos(parts, 2, (s32 *)&p, w->field_54.grid);
                Gfx_SetPartsPalette(parts, 2, (arg0->elapsed >> 2) & 3);
                mask = (w->field_66 < 1) << 2;
                if (w->field_54.grid[1] - w->field_66 - 4 <= 0) {
                    mask |= 8;
                }
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, mask);
                Gfx_SetPartsNumber(parts, 0x10, 2, w->field_50.y + 1);
                Gfx_SetPartsNumber(parts, 0x20, 2, w->field_54.grid[1]);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, -1);
            }
        } else {
            top = w->field_66 - 1;
            e = &w->field_6C[top + i];
            k = i - 1;
            if (k >= w->field_54.grid[1]) {
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, -1);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, 0);
                pal = 2;
                if (w->field_68 != 0 && k == w->field_50.y - w->field_66) {
                    pal = 1;
                }
                switch (e->field_0) {
                case 0:
                    Gfx_HidePartsByMask((GfxPartMaskView *)parts, pal | 0xFE4);
                    break;
                case 1:
                    cell = e->field_4;
                    Gfx_HidePartsByMask((GfxPartMaskView *)parts, pal | D_8006820C[e->field_2 - 1]);
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

INCLUDE_RODATA("asm/USA/stag1100/rodata", D_800634C4);
void func_800673FC(void) {
    Stg11SaveWork *w = (Stg11SaveWork *)D_800685D0->work;
    struct Stg11CardBlock *h = &w->u34.s;
    struct Stg11CardBlock *h2 = h;
    u8 *data = w->u34.s.field_234;

    h->magic[0] = 'S';
    h->magic[1] = 'C';
    h->iconFlag = 0x13;
    h->blocks = 2;
    func_80067724(D_800634C4);
    memset(h->field_78, 0, 0x1C);
    h->clut = D_80068244.clut;
    h->icons[0] = D_80068244.icon;
    h2->icons[1] = D_80068330;
    h2->icons[2] = D_800683F0;
    memset(data, 0, 0x3DFC);
    h->field_4030 = 0x102;
}

u8 *func_800676F4(void) {
    return ((Stg11SaveWork *)D_800685D0->work)->u34.s.field_234;
}

u8 *func_8006770C(void) {
    return ((Stg11SaveWork *)D_800685D0->work)->field_4034;
}

void func_80067724(u8 *arg0) {
    s32 i = 0;
    u8 *d = ((Stg11SaveWork *)D_800685D0->work)->u34.s.field_38;
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

void func_800677AC(u8 arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)D_800685D0->work;
    Task_SetState1(D_800685D0, arg0);
    w->field_0 = arg1;
    w->field_24[arg1][0] = -1;
    w->field_4 = -1;
    w->field_22038 = -1;
    w->field_22040 = 0;
}

s32 func_80067818(void) {
    return ((Stg11SaveWork *)D_800685D0->work)->field_4;
}

void func_80067838(u8 *arg0, u8 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)D_800685D0->work;
    strcpy(w->field_C, arg0);
    w->field_21 = arg1;
}

s32 func_80067880(s32 arg0) {
    Stg11SaveWork *w = (Stg11SaveWork *)D_800685D0->work;
    s32 d = w->field_22038;
    s32 r;

    if (d != 0) {
        if (d < 0) {
            r = 0;
        } else {
            r = arg0 * w->field_2203C / d;
        }
    } else {
        r = arg0;
    }
    return r;
}

s32 func_800678F0(Stg11SaveWork *arg0) {
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

s32 func_80067938(Stg11SaveWork *arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    s32 chan = (arg2 != 0) << 4;
    s32 cmd;
    s32 st;

    if (MemCardSync(1, &cmd, &st) == -1) {
        switch (arg1) {
        case 6:
            st = MemCardCreateFile(chan, (s32)D_800685D4->field_C, 2);
            switch (st) {
            case 1:
                r = 0;
                break;
            case 4:
                r = -1;
                if (++arg0->field_8 >= 5) {
                    r = 1;
                }
                break;
            default:
                r = -1;
                if (++arg0->field_8 >= 5) {
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
            st = MemCardOpen(chan, (s32)D_800685D4->field_C, 1);
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
                if (++arg0->field_8 >= 5) {
                    r = 0xB;
                }
                break;
            case 4:
                r = -1;
                if (++arg0->field_8 >= 5) {
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
                if (++arg0->field_8 >= 5) {
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

s32 func_80067B54(Stg11SaveWork *arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    s32 chan = (arg2 != 0) << 4;
    s32 cmd;
    s32 st;
    s32 sum;

    switch (MemCardSync(1, &cmd, &st)) {
    default:
        if (arg0->field_2203C < arg0->field_22038) {
            arg0->field_2203C++;
        }
        break;
    case -1:
        arg0->field_22038 = 1;
        arg0->field_2203C = 0;
        arg0->field_22040 = 1;
        switch (arg1) {
        case 1:
            MemCardExist(chan);
            break;
        case 2:
            arg0->field_22038 = 0x26;
            MemCardAccept(chan);
            break;
        case 3:
            arg0->field_22038 = 0x83;
            arg0->u34.s.field_4032 = func_800678F0(arg0);
            MemCardWriteFile(chan, (s32)arg0->field_C, (s32)&arg0->u34, 0, 0x4000);
            break;
        case 4:
            if (arg0->field_21 == 0) {
                arg0->field_22038 = 0x81;
                MemCardReadFile(chan, (s32)arg0->field_C, (s32)&arg0->u34, 0, 0x4000);
            } else {
                arg0->field_22038 = 0x3C8;
                MemCardReadFile(chan, (s32)arg0->field_C, (s32)arg0->field_4034, 0, 0x1E000);
            }
            break;
        }
        break;
    case 1:
        if (arg0->field_22040 == 0) {
            return -1;
        }
        arg0->field_2203C = arg0->field_22038;
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
                    if (++arg0->field_8 >= 5) {
                        r = 0xB;
                    }
                    break;
                case 4:
                    r = -1;
                    if (++arg0->field_8 >= 5) {
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
                    if (++arg0->field_8 >= 5) {
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
                    if (arg0->field_21 == 0) {
                        sum = arg0->u34.s.field_4032;
                        if (sum == func_800678F0(arg0) && arg0->u34.s.field_4030 == 0x102) {
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
                    if (++arg0->field_8 >= 5) {
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

void func_80067F64(Actor *arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)arg0->work;
    s32 *p;

    switch (arg0->stateLevel2) {
    case 1:
        break;
    case 0:
    default:
        w->field_24[w->field_0][0] = -1;
        w->field_8 = 0;
        Task_SetState2(arg0, 10);
        break;
    case 10:
        p = &w->field_24[w->field_0][0];
        if (arg1 < 5) {
            *p = func_80067B54(w, arg1, w->field_0);
        } else {
            *p = func_80067938(w, arg1, w->field_0);
        }
        if (*p != -1) {
            Task_SetState2(arg0, 1);
        }
        break;
    }
    w->field_4 = w->field_24[w->field_0][0];
}

void func_80068050(void) {
}

void func_80068058(Actor *arg0) {
    Stg11SaveWork *w = (Stg11SaveWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        D_800685D0 = arg0;
        D_800685D4 = (Stg11SaveWork *)arg0->work;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 4:
            func_80067F64(arg0, 2);
            break;
        case 2:
            func_80067F64(arg0, 1);
            break;
        case 7:
            func_80067F64(arg0, 6);
            break;
        case 5:
            func_80067F64(arg0, 7);
            break;
        case 6:
            func_80067F64(arg0, 8);
            break;
        case 8:
            func_80067F64(arg0, 3);
            break;
        case 9:
            func_80067F64(arg0, 4);
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
    w->field_22034 = arg0->stateLevel1;
}

void func_80068160(Actor *arg0) {
    Task_DefaultDestroy(arg0);
}

void func_80068180(void) {
}
