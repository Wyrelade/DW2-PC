#include "common.h"
#include "stag1100/stag1100.h"

void func_8006358C(Actor *arg0) {
    Stg11MainWork *w = (Stg11MainWork *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;

    switch (arg0->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x20);
        Task_Create(9, slot, 0);
        Task_Create(0x601, slot + 2, 0);
        Task_Create(0x602, slot + 3, 0);
        D_80050780 = 0;
        Task_Create(0x603, slot + 1, D_8005F770.gameMode - 0x600);
        if (D_8005F770.gameMode != 0x603 && D_8005F770.gameMode != 0x604) {
            Snd_StopAll();
            Snd_UnloadSlot(2);
            Snd_SetSlotContent(1, 0xE);
            w->field_0 = 0;
        } else {
            w->field_0 = 1;
        }
        Task_NextState0(arg0);
        break;
    case 1:
        if (arg0->stateLevel1 != 1) {
            if (w->field_0 == 0 && Snd_AnySlotLoading() == 0) {
                w->field_0 = 1;
                Snd_PlayById(0x100, 1);
            }
            if (slot[1] == 0) {
                D_8005F770.nextGameMode = D_8005F770.prevGameMode;
                if (D_8005F770.gameMode == 0x605) {
                    D_8005F770.field_24 = 1;
                }
                Task_NextState1(arg0);
            }
        }
        break;
    case 2:
        break;
    }
}

void func_8006374C(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Task_NextState0(arg0);
    }
}

void func_8006377C(Actor *arg0) {
    GfxPart *list = (GfxPart *)Cd_GetFileEntry(0x459000C);
    GfxPart *p;

    for (p = list; p->fileId != 0; p++) {
        switch (p->groupMask) {
        case 2:
            p->palette = Math_CycleRange(arg0->elapsed, 10, 0, 7);
            break;
        case 8:
            p->x -= 2;
            if (p->x == -0x168) {
                p->x = 0;
            }
            break;
        case 0x10:
            p->x += 1;
            if (p->x == 0xD8) {
                p->x = 0;
            }
            break;
        case 0x20:
            p->x -= 2;
            if (p->x == -0x1C0) {
                p->x = 0;
            }
            break;
        }
    }
    Gfx_DrawParts(list);
}

void func_80063894(Actor *arg0, s16 arg1) {
    Stg11Work63894 *w = (Stg11Work63894 *)arg0->work;
    D_800685C8 = 0;
    w->field_20 = arg1;
    w->field_24 = arg1 == 4;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800638BC);

void func_80063C08(Actor *arg0) {
    Stg11Work63894 *w = (Stg11Work63894 *)arg0->work;
    s32 *list;
    s32 i;
    GfxPart *parts;
    s32 *masks;

    if (w->field_28 != 0) {
        list = (s32 *)Cd_GetFileEntry(0xD280002);
        for (i = 0; list[i] != 0; i++) {
            parts = (GfxPart *)Cd_GetFileEntry(list[i]);
            if (i == 0) {
                masks = (s32 *)Cd_GetFileEntry(0xD280004);
                Menu_SetPartsGridPos(parts, 0x20, &w->field_10, &w->field_14);
                Gfx_SetPartsPalette(parts, 0x20, (arg0->elapsed >> 2) & 3);
                Gfx_HidePartsByMask((GfxPartMaskView *)parts, masks[w->field_20 - 1]);
            }
            Gfx_SetPartsScale((GfxPartScaleView *)parts, 0x1000, w->field_28);
            Gfx_DrawParts(parts);
        }
    }
}

void func_80063D20(void) {
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80063D28);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064000);

void func_80064304(Actor *arg0, Stg11MenuWork *arg1) {
    Halves *pos = (Halves *)Cd_GetFileEntry(0xD28000C);
    Stg11MenuRow *row = arg1->field_98;
    TextDescHalves st;
    s32 i;

    Text_CloseArray(arg1->field_38, 11);
    st.strArg0 = 0;
    st.packedStyle = 0;
    st.color = 0;
    for (i = 0; i < 5; i++, row++) {
        st.pos = *pos++;
        st.text = row->field_0 == 0 ? (s32)Cd_GetFileEntry(0x1FD0098)
                                    : (s32)Digi_GetDefaultName(row->field_0);
        Text_OpenDesc(&arg1->field_38[i * 2], (TextDesc *)&st);
        st.pos = *pos++;
        if (row->field_0 != 0 && row->field_2 != 0) {
            if (row->field_2 == 1) {
                st.text = (s32)Cd_GetFileEntry(0x1FD01B2);
            } else {
                st.text = (s32)Cd_GetFileEntry(0x1FD01B7);
            }
            Text_OpenDesc(&arg1->field_38[i * 2 + 1], (TextDesc *)&st);
        }
    }
    st.pos = D_800681DC;
    st.text = (s32)Cd_GetFileEntry(arg1->field_138 + 0x1FD01BD);
    Text_OpenDesc(&arg1->field_C, (TextDesc *)&st);
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006448C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800646C0);

void func_800648B4(Actor *arg0, Stg11MenuWork *arg1) {
    Text_CloseArray(arg1->field_10, 9);
    arg1->field_86 = 0;
}

void func_800648E4(Stg11MenuWork *arg0, s32 arg1) {
    TextDescHalves st;

    if (arg1 == 0) {
        Text_Close(&arg0->field_8);
    } else {
        st.pos = D_800681D8;
        st.packedStyle = 0x80;
        st.color = 0;
        st.text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
        Text_OpenDesc(&arg0->field_8, (TextDesc *)&st);
    }
}

void func_8006495C(Stg11MenuWork *arg0, s32 arg1, s32 arg2) {
    TextDescHalves st;

    if (arg1 == 0) {
        Text_Close(&arg0->field_4);
    } else {
        st.pos = D_800681D4;
        st.packedStyle = arg2 - 0x80;
        st.color = 0;
        st.text = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
        Text_OpenDesc(&arg0->field_4, (TextDesc *)&st);
    }
}

s32 func_800649D4(Stg11MenuWork *arg0) {
    return Text_IsFinished(arg0->field_4);
}

s32 func_800649F8(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r = 0;
    s32 v = func_80067818();

    if (v != -1) {
        if (v == 0) {
            Task_SetState1(arg0, 3);
            r = -1;
        } else {
            func_800677AC(4, arg1->field_84);
        }
    }
    return r;
}

void func_80064A6C(Actor *arg0, Stg11MenuWork *arg1) {
    if (arg0->stateLevel2 == 0) {
        func_800677AC(4, arg1->field_84);
    }
    if (func_800649F8(arg0, arg1) == 0) {
        arg0->stateLevel2 = 1;
        if (D_8005F6F0[arg1->field_7E].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState0(arg0, 2);
        }
    }
}

void func_80064B00(Actor *arg0, Stg11MenuWork *arg1) {
    s32 msg;

    switch (arg0->stateLevel2) {
    case 0:
        msg = 0;
        switch (func_80067818()) {
        case 1:
            msg = arg1->field_7A == 0 ? 0x16D : 0x16E;
            break;
        case 4:
            msg = 0x183;
            break;
        case 5:
            msg = 0x182;
            break;
        case 6:
            msg = 0x171;
            break;
        case 7:
            msg = 0x194;
            break;
        case 8:
            msg = 0x16F;
            break;
        case 10:
            msg = 0x16E;
            break;
        case 11:
            msg = arg1->field_80 != 0 ? 0x1B1 : 0x186;
            break;
        }
        func_800648E4(arg1, msg);
        func_800648B4(arg0, arg1);
        func_800677AC(4, arg1->field_84);
        Task_NextState2(arg0);
        break;
    case 1:
        if (D_8005F6F0[arg1->field_7E].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState0(arg0, 2);
            return;
        }
        break;
    }
    func_800649F8(arg0, arg1);
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80064C64);

void func_80064EF0(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    if (arg0->stateLevel2 == 0) {
        func_800677AC(4, arg1->field_84);
    }
    if (func_800649F8(arg0, arg1) == 0) {
        switch (arg0->stateLevel2) {
        case 0:
        default:
            func_800648E4(arg1, 0x16D);
            func_8006495C(arg1, 0x177, 1);
            Task_NextState2(arg0);
            break;
        case 1:
            r = func_800136A4(arg1->field_4);
            if (r != -1) {
                if (r == 1) {
                    Task_SetState0(arg0, 2);
                }
            } else {
                Task_SetState1(arg0, 10);
            }
            break;
        }
    }
}

void func_80064FD0(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    switch (arg0->stateLevel2) {
    case 0:
        func_800648E4(arg1, 0x193);
        func_8006495C(arg1, 0, 0);
        func_800677AC(6, arg1->field_84);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->field_94 = 0;
        r = func_80067818();
        switch (r) {
        case 0:
            Task_SetState1(arg0, 3);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        case 0x10:
            Task_SetState1(arg0, 4);
            break;
        case -1:
            break;
        }
        break;
    }
}

void func_800650A8(Actor *arg0, Stg11MenuWork *arg1) {
    s32 r;

    if (arg0->stateLevel2 == 0) {
        func_800677AC(4, arg1->field_84);
    }
    if (func_800649F8(arg0, arg1) == 0) {
        switch (arg0->stateLevel2) {
        case 0:
        default:
            func_800648E4(arg1, 0x16E);
            func_8006495C(arg1, 0x176, 1);
            Task_NextState2(arg0);
            break;
        case 1:
            r = func_800136A4(arg1->field_4);
            if (r != -1) {
                if (r == 1) {
                    Task_SetState1(arg0, 5);
                }
            } else {
                Task_SetState0(arg0, 2);
            }
            break;
        }
    }
}

void func_80065188(Actor *arg0, Stg11MenuWork *arg1) {
    switch (arg0->stateLevel2) {
    case 0:
        func_800673FC();
        func_800677AC(7, arg1->field_84);
        func_800648E4(arg1, 0x184);
        func_8006495C(arg1, 0, 0);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->field_94 = 0;
        switch (func_80067818()) {
        case -1:
            arg1->field_94 = 2;
            arg1->field_96 = func_80067880(0x80);
            break;
        case 0:
            Task_SetState1(arg0, 3);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        case 9:
            func_800677AC(8, arg1->field_84);
            Task_NextState2(arg0);
            break;
        }
        break;
    case 2:
        arg1->field_94 = 0;
        switch (func_80067818()) {
        case -1:
            arg1->field_94 = 2;
            arg1->field_96 = func_80067880(0x80);
            break;
        case 0:
        case 0xF:
            Task_SetState1(arg0, 3);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        case 0xC:
            Task_SetState1(arg0, 7);
            break;
        }
        break;
    }
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065318);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800654E4);

void func_80065A3C(Actor *arg0, Stg11MenuWork *arg1) {
    switch (arg0->stateLevel2) {
    case 0:
        func_800677AC(8, arg1->field_84);
        func_8006495C(arg1, 0x173, 1);
        Task_NextState2(arg0);
        break;
    case 1:
        arg1->field_94 = 0;
        switch (func_80067818()) {
        case -1:
            arg1->field_94 = 2;
            arg1->field_96 = func_80067880(0x80);
            break;
        case 0:
        case 0xF:
            arg1->field_88 = 0x182;
            Task_SetState1(arg0, 3);
            break;
        default:
            arg1->field_88 = 0x182;
            Task_SetState1(arg0, 2);
            break;
        case 0xC:
            func_800677AC(4, arg1->field_84);
            func_8006495C(arg1, 0x174, 1);
            Task_NextState2(arg0);
            break;
        }
        break;
    case 2:
        if (func_800649F8(arg0, arg1) == 0) {
            if (arg0->stateLevel3++ >= 0x3C) {
                Task_SetState1(arg0, 7);
            }
        }
        break;
    }
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065BA0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80065E64);

void func_80066028(Actor *arg0, s16 arg1) {
    Stg11MenuWork *w = (Stg11MenuWork *)arg0->work;

    w->field_78 = arg1;
    w->field_7A = arg1 > 2;
    w->field_84 = (w->field_78 - 1) % 2;
    w->field_7E = w->field_78 == 7 || w->field_78 == 8;
    w->field_7C = w->field_78 >= 5 && w->field_78 <= 8;
    w->field_80 = w->field_78 == 9 || w->field_78 == 10;
    if (w->field_78 == 9 || w->field_78 == 10) {
        func_80067838(D_80063454, 1);
    } else {
        func_80067838(D_80063464, 0);
    }
    w->field_90 = func_800676F4();
    w->field_94 = 0;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800660F0);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_8006637C);

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
    arg0->field_54[0] = 1;
    arg0->field_54[1] = 0;
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
        arg0->field_54[1]++;
    }
    arg0->field_6A = 0;
    e = pt->field_0->elems;
    for (i = 0; i < 0x24; i++, e++) {
        if (e->state != 0) {
            arg0->field_6A++;
        }
    }
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066860);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066A0C);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066B60);

void func_80066C04(Actor *arg0, s16 arg1) {
    Stg11Work66C04 *w = (Stg11Work66C04 *)arg0->work;
    w->field_60 = arg1;
    w->field_64 = (arg1 - 1) % 2;
    w->field_68 = w->field_60 >= 3;
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80066C48);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067124);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_800673FC);

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

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067880);

u16 func_800678F0(Stg11SaveWork *arg0) {
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

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067938);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067B54);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067F64);

void func_80068050(void) {
}

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80068058);

void func_80068160(Actor *arg0) {
    Task_DefaultDestroy(arg0);
}

void func_80068180(void) {
}
