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

void func_800638BC(Actor *arg0) {
    Stg11Work63894 *w = (Stg11Work63894 *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg11TaskEntry *tasks;
    s32 idx;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        w->field_14.layout = ((Layout8C *)Cd_GetFileEntry(0xD280000))[w->field_20 - 1];
        Mem_FillWordsNeg1(w->texts, 4);
        Task_NextState0(arg0);
        break;
    case 1:
        tasks = (Stg11TaskEntry *)Cd_GetFileEntrySubPtr(0xD280003, w->field_20 - 1);
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (Math_RampToOne(arg0, &w->field_28) == 0) {
                Text_PrintIdList(w->texts, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280001, w->field_20 - 1), 2);
                Text_OpenPacked(&w->texts[3], (s32)Cd_GetFileEntry(w->field_20 + 0x1FD01A2), 0x81, D_800681B8);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if (Menu_MoveGridCursor(w->field_10, w->field_14.gridSize, w->field_24) == 0) {
                if (D_8005F6F0[w->field_24].cross > 0) {
                    if (tasks[Menu_GridIndexColMajor(w->field_10, w->field_14.gridSize)].id != -1) {
                        Snd_PlayById(0xA, 0);
                        Task_NextState1(arg0);
                    }
                } else if (D_8005F6F0[w->field_24].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(arg0, 2);
                }
            } else {
                Snd_PlayById(0xC, 0);
            }
            break;
        case 2:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                idx = Menu_GridIndexColMajor(w->field_10, w->field_14.gridSize);
                Task_Create(tasks[idx].id, slot, tasks[idx].arg);
                Text_Close(&w->texts[3]);
                Task_NextState2(arg0);
                break;
            case 1:
                if (*slot == 0) {
                    if (D_800685C8 == 0) {
                        Text_OpenPacked(&w->texts[3], (s32)Cd_GetFileEntry(w->field_20 + 0x1FD01A2), 0x81, D_800681B8);
                        Task_SetState1(arg0, 1);
                    } else {
                        Task_SetState0(arg0, 2);
                    }
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 4);
            Gfx_FadeOutToBlack(0x20);
            Task_NextState1(arg0);
            break;
        case 1:
            if (Math_RampToZero(arg0, &w->field_28) == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    }
}

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
                Menu_SetPartsGridPos(parts, 0x20, (s32 *)w->field_10, w->field_14.gridSize);
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

void func_80063D28(Stg11MenuRow *arg0, Stg11CardRec *arg1) {
    s16 *skillTbl = (s16 *)Cd_GetFileEntry(0xD28000E);
    Stg11SpeciesRec *t = (Stg11SpeciesRec *)Cd_GetFileEntry(0xD280010);
    s32 i;

    t += func_8001D958(arg0->field_0);
    arg0->level = t->level;
    arg0->field_F = func_8001EB58(arg0->level);
    arg0->exp = t->exp;
    arg0->hp = t->base + arg1->field_92 / 20;
    if (t->hpMax < arg0->hp) {
        arg0->hp = t->hpMax;
    }
    arg0->mp = t->base + arg1->field_96 / 20;
    if (t->hpMax < arg0->mp) {
        arg0->mp = t->hpMax;
    }
    arg0->field_18 = arg1->field_9A / 7;
    if (t->statMax < arg0->field_18) {
        arg0->field_18 = t->statMax;
    }
    if (arg0->field_18 == 0) {
        arg0->field_18 = 1;
    }
    arg0->field_1A = arg1->field_9C / 7;
    if (t->statMax < arg0->field_1A) {
        arg0->field_1A = t->statMax;
    }
    if (arg0->field_1A == 0) {
        arg0->field_1A = 1;
    }
    arg0->field_1C = arg1->field_A0 / 10;
    if (t->field_A < arg0->field_1C) {
        arg0->field_1C = t->field_A;
    }
    if (arg0->field_1C == 0) {
        arg0->field_1C = 1;
    }
    arg0->field_1E = arg1->uid;
    arg0->skillCount = 0;
    for (i = 0; i < arg1->skillCount; i++) {
        if (arg1->skills[i] < 0x78 && skillTbl[arg1->skills[i]] != 0) {
            arg0->skills[arg0->skillCount++] = skillTbl[arg1->skills[i]];
        }
    }
    if (arg0->skillCount == 0) {
        arg0->skills[0] = func_8001D9A8(arg0->field_0);
        arg0->skillCount = 1;
    }
}

void func_80064000(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11CardRec *p = (Stg11CardRec *)func_8006770C();
    s16 *tbl = (s16 *)Cd_GetFileEntry(0xD28000F);
    Stg11MenuRow *c = arg1->field_98;
    Stg11CardRec *rec;
    s16 maxLv;
    s32 i;
    s32 j;
    s32 n;
    s32 sum;

    p = ((Stg11CardArea *)p)->cards;
    arg1->field_138 = 0x18;
    maxLv = 0;
    for (i = 0; i < 0x24; i++) {
        if (D_80050720->elems[i].state == 1) {
            arg1->field_138--;
        }
        if (D_80050720->elems[i].state != 0 && maxLv < func_8001D958(D_80050720->elems[i].digiId)) {
            maxLv = func_8001D958(D_80050720->elems[i].digiId);
        }
    }
    n = 0;
    for (i = 0; i < 5; i++, p++, c++) {
        rec = p;
        c->field_0 = 0;
        c->field_2 = 0;
        for (sum = j = 0; j < 0x80; j++) {
            sum += rec->bytes[j];
        }
        if (sum == 0x880 && (rec->field_BD & 0xF) && rec->field_A2 < 0x100 && tbl[rec->field_A2] != 0
            && rec->field_80 != -1 && rec->field_80 >= 0x780) {
            for (j = 0; j < i; j++) {
                if (arg1->field_98[j].field_0 != 0 && arg1->field_98[j].field_1E == rec->uid) {
                    break;
                }
            }
            if (j == i) {
                c->field_0 = tbl[rec->field_A2];
                for (j = 0; j < 0x24; j++) {
                    if (((Stg11GameState *)D_80050720)->elems[j].state != 0 && ((Stg11GameState *)D_80050720)->elems[j].field_49 != 0 && ((Stg11GameState *)D_80050720)->elems[j].field_4A == rec->uid) {
                        c->field_2 = 1;
                    }
                }
                if (maxLv < func_8001D958(c->field_0)) {
                    c->field_2 = 2;
                }
                if (c->field_2 == 0) {
                    n++;
                }
                func_80063D28(c, rec);
            }
        }
    }
    if (n < arg1->field_138) {
        arg1->field_138 = n;
    }
}

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

void func_8006448C(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11MenuRow *c = &arg1->field_98[Menu_GridIndexColMajor(arg1->cursor, arg1->u6C.gridSize)];
    Stg11DigiEntry *e = (Stg11DigiEntry *)D_80050720->elems;
    u8 *src;
    u8 *dst;
    s32 i;

    if (arg1->field_138 == 0 || c->field_0 == 0 || c->field_2 != 0) {
        Snd_PlayById(0x10, 0);
        return;
    }
    for (i = 0; i < 0x24; i++) {
        if (e[i].state == 0) {
            break;
        }
    }
    if (i == 0x24) {
        Snd_PlayById(0x10, 0);
        return;
    }
    e += i;
    memset((u8 *)e, 0, 0x5C);
    e->state = 1;
    e->digiId = c->field_0;
    e->level = c->level;
    e->field_E = 0;
    e->field_F = c->field_F;
    e->exp = c->exp;
    e->maxHp = c->hp;
    e->hp = c->hp;
    e->maxMp = c->mp;
    e->mp = c->mp;
    e->field_1C = c->field_18;
    e->field_1E = c->field_1A;
    e->field_20 = c->field_1C;
    src = Digi_GetDefaultName(e->digiId);
    dst = e->name;
    while (*src != 0xFF) {
        *dst++ = *src++;
    }
    *dst = 0xFF;
    for (i = 0; i < c->skillCount; i++) {
        e->skills[i] = c->skills[i];
    }
    e->field_49 = 1;
    e->field_4A = c->field_1E;
    arg1->field_138--;
    c->field_2 = 1;
    func_80064304(arg0, arg1);
    func_8006495C(arg1, 0x110, 1);
    Snd_PlayById(0xE, 0);
}

void func_800646C0(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11SaveList *list = arg1->field_90;
    Halves *pos = (Halves *)Cd_GetFileEntry(0xD28000B);
    TextDescHalves st;
    Stg11SaveSlot *slot;
    s32 i;

    st.strArg0 = 0;
    st.packedStyle = 0;
    st.color = 0;
    for (i = 0; i < 3; i++) {
        if (list->used[i] != 0) {
            st.pos = *pos++;
            slot = &list->slots[i];
            st.text = (s32)slot->u.gs.field_14;
            Text_OpenDesc(&arg1->field_10[i * 3], (TextDesc *)&st);
            st.pos = *pos++;
            st.text = (s32)Cd_GetFileEntry(((s16 *)Cd_GetFileEntry(0x513000F))[slot->u.gs.field_11 * 11 + slot->u.gs.field_12] + 0x1FD0000);
            Text_OpenDesc(&arg1->field_10[i * 3 + 1], (TextDesc *)&st);
        } else {
            st.pos = *pos++;
            st.text = (s32)Cd_GetFileEntry(0x1FD0098);
            Text_OpenDesc(&arg1->field_10[i * 3], (TextDesc *)&st);
            st.pos = *pos++;
            Text_OpenDesc(&arg1->field_10[i * 3 + 1], (TextDesc *)&st);
        }
        st.pos = *pos++;
        st.text = (s32)Cd_GetFileEntry(0x1FD005F);
        Text_OpenDesc(&arg1->field_10[i * 3 + 2], (TextDesc *)&st);
    }
}

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

void func_80064C64(Actor *arg0, Stg11MenuWork *arg1) {
    switch (arg0->stateLevel2) {
    case 0:
        func_8006495C(arg1, arg1->field_88, 1);
        arg1->field_88 = 0;
        arg1->field_86 = 0;
        func_800648B4(arg0, arg1);
        Task_SetState2(arg0, 0xA);
    case 10:
        func_800677AC(2, arg1->field_84);
        Task_NextState2(arg0);
        break;
    case 11:
        switch (func_80067818()) {
        case -1:
            break;
        case 2:
            func_800648E4(arg1, arg1->field_80 ? 0x1AD : 0x16B);
            Task_SetState2(arg0, 0x14);
            break;
        case 0:
            func_800648E4(arg1, arg1->field_84 + (arg1->field_80 ? 0x1AE : 0x180));
            Task_SetState2(arg0, 0xA);
            break;
        }
        break;
    case 20:
        func_800677AC(4, arg1->field_84);
        Task_NextState2(arg0);
        break;
    case 21:
        switch (func_80067818()) {
        case -1:
            break;
        case 2:
            Task_SetState2(arg0, 0x1E);
            break;
        case 0:
            func_800648E4(arg1, arg1->field_84 + (arg1->field_80 ? 0x1AE : 0x180));
            Task_SetState2(arg0, 0xA);
            break;
        case 1:
            if (arg1->field_7A != 0) {
                Task_SetState1(arg0, 2);
            } else {
                Task_SetState1(arg0, 9);
            }
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        }
        break;
    case 30:
        func_800677AC(5, arg1->field_84);
        Task_NextState2(arg0);
        break;
    case 31:
        switch (func_80067818()) {
        case -1:
            break;
        case 9:
            Task_SetState1(arg0, 6);
            break;
        case 10:
            if (arg1->field_7A != 0) {
                Task_SetState1(arg0, 2);
            } else {
                Task_SetState1(arg0, 4);
            }
            break;
        case 0:
            Task_SetState2(arg0, 0xA);
            break;
        default:
            Task_SetState1(arg0, 2);
            break;
        }
        break;
    }
    if (D_8005F6F0[arg1->field_7E].triangle > 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(arg0, 2);
    }
}

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

void func_80065318(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11SaveList *list;
    Stg11SaveSlot *slot;
    s32 i;
    s32 j;

    switch (arg0->stateLevel2) {
    case 0:
        func_800677AC(9, arg1->field_84);
        func_800648E4(arg1, arg1->field_80 ? 0x1B0 : 0x185);
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
        case 15:
            arg1->field_88 = arg1->field_7A ? 0x183 : 0;
            Task_SetState1(arg0, 3);
            break;
        default:
            arg1->field_88 = arg1->field_7A ? 0x183 : 0;
            Task_SetState1(arg0, 2);
            break;
        case 14:
            func_800673FC();
            Task_SetState1(arg0, 7);
            break;
        case 13:
            if (arg1->field_80 != 0) {
                Task_SetState1(arg0, 0xC);
                break;
            }
            list = arg1->field_90;
            for (i = 0; i < 3; i++) {
                slot = &list->slots[i];
                if (list->used[i] != 0) {
                    for (j = 0; j < 0x24; j++) {
                        if (slot->u.gs.elems[j].state != 0) {
                            slot->u.gs.elems[j].name[13] = 0xFF;
                        }
                    }
                    slot->u.gs.field_14[5] = 0xFF;
                    slot->u.gs.field_D1[7] = 0xFF;
                }
            }
            Task_SetState1(arg0, 7);
            break;
        }
        break;
    }
}

void func_800654E4(Actor *arg0, Stg11MenuWork *arg1) {
    Stg11SaveList *list = arg1->field_90;
    Stg11SaveSlot *slot;
    DigiRosterEntry *e;
    s32 idx;
    s32 idx2;
    s32 msg;
    s32 r;
    s32 i;
    s32 n;

    if (arg0->stateLevel2 == 0) {
        func_800677AC(4, arg1->field_84);
    }
    if (func_800649F8(arg0, arg1) != 0) {
        return;
    }
    switch (arg0->stateLevel2) {
    case 0:
    default:
        func_800648E4(arg1, 0);
        msg = 0x170;
        if (arg1->field_7A == 0) {
            msg = 0x172;
        }
        if (arg1->field_7C != 0) {
            msg = 0x1A8;
        }
        func_8006495C(arg1, msg, 1);
        arg1->field_86 = 1;
        func_800646C0(arg0, arg1);
        Task_NextState2(arg0);
        break;
    case 1:
        if (Menu_MoveGridCursor(arg1->cursor, arg1->u6C.gridSize, arg1->field_7E) == 0) {
            if (D_8005F6F0[arg1->field_7E].cross > 0) {
                idx = Menu_GridIndexColMajor(arg1->cursor, arg1->u6C.gridSize);
                if (arg1->field_7A == 0) {
                    if (list->used[idx] == 0) {
                        list->used[idx] = D_8005F770.prevGameMode;
                        *(list->slots + idx) = *(Stg11SaveSlot *)D_80050720;
                        func_800646C0(arg0, arg1);
                        Task_SetState1(arg0, 8);
                        Snd_PlayById(0xE, 0);
                    } else {
                        func_8006495C(arg1, 0x175, 1);
                        Task_NextState2(arg0);
                        Snd_PlayById(0xE, 0);
                    }
                } else {
                    if (list->used[idx] == 0) {
                        Snd_PlayById(0x10, 0);
                    } else {
                        if (arg1->field_7C == 0) {
                            *(Stg11SaveSlot *)D_80050720 = *(list->slots + idx);
                            D_800685C8 = 1;
                            D_8005F770.prevGameMode = list->used[idx];
                            Task_SetState0(arg0, 2);
                            Snd_PlayById(0xE, 0);
                        } else {
                            slot = &list->slots[idx];
                            e = slot->u.gs.elems;
                            D_800684A8.field_0 = &slot->u.gs;
                            for (n = i = 0; i < 3; i++, e++) {
                                D_800684A8.field_4[i].state = 0;
                                if (e->state >= 3) {
                                    D_800684A8.field_4[n] = *e;
                                    n++;
                                }
                            }
                            if (n < 3) {
                                Snd_PlayById(0x10, 0);
                                func_8006495C(arg1, 0x1AB, 1);
                            } else {
                                Snd_PlayById(0xE, 0);
                                Task_SetState1(arg0, 0xB);
                            }
                        }
                    }
                }
            } else if (D_8005F6F0[arg1->field_7E].triangle > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(arg0, 2);
            }
        } else {
            Snd_PlayById(0xD, 0);
            msg = 0x170;
            if (arg1->field_7A == 0) {
                msg = 0x172;
            }
            if (arg1->field_7C != 0) {
                msg = 0x1A8;
            }
            func_8006495C(arg1, msg, 0);
        }
        break;
    case 2:
        r = func_800136A4(arg1->field_4);
        if (r != -1) {
            if (r == 1) {
                idx2 = Menu_GridIndexColMajor(arg1->cursor, arg1->u6C.gridSize);
                list->used[idx2] = D_8005F770.prevGameMode;
                *(list->slots + idx2) = *(Stg11SaveSlot *)D_80050720;
                func_800646C0(arg0, arg1);
                Task_SetState1(arg0, 8);
            }
        } else {
            msg = 0x170;
            if (arg1->field_7A == 0) {
                msg = 0x172;
            }
            func_8006495C(arg1, msg, 1);
            Task_SetState2(arg0, 1);
        }
        break;
    }
}

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

void func_80065BA0(Actor *arg0, Stg11MenuWork *arg1) {
    s32 *slot = (s32 *)arg0->u34.children;
    DigiRosterEntry *d;
    u8 *src;
    u8 *dst;
    s32 i;

    if (arg0->stateLevel2 == 0) {
        func_800677AC(4, arg1->field_84);
    }
    if (func_800649F8(arg0, arg1) != 0) {
        if (*slot != 0) {
            Task_SetState0((Actor *)*slot, 2);
        }
        Text_PrintIdList((s32 *)arg1, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280006, arg1->field_78 - 1), 0);
        func_800648B4(arg0, arg1);
        arg1->field_8C = 0x1000;
        return;
    }
    switch (arg0->stateLevel2) {
    case 0:
    default:
        Text_CloseArray((s32 *)arg1, 0x1A);
        Task_NextState2(arg0);
        break;
    case 1:
        if (Math_RampToZero(arg0, &arg1->field_8C) == 0) {
            Task_Create(0x605, slot, arg1->field_7E + 1);
            D_80050780 = 0;
            Task_NextState2(arg0);
        }
        break;
    case 2:
        if (*slot == 0) {
            if (D_80050780 != 0) {
                d = &D_80050720->elems[arg1->field_7E * 3];
                for (i = 0; i < 3; i++) {
                    *d = D_800684A8.field_4[i];
                    if (d->state != 0) {
                        d->state = i + 3;
                    }
                    d++;
                }
                src = D_800684A8.field_0->field_14;
                dst = D_80050720->elems[arg1->field_7E + 6].name;
                while (*src != 0xFF) {
                    *dst++ = *src++;
                }
                *dst = 0xFF;
                Task_SetState0(arg0, 3);
            } else {
                Task_NextState2(arg0);
            }
        }
        break;
    case 3:
        if (Math_RampToOne(arg0, &arg1->field_8C) == 0) {
            Text_PrintIdList((s32 *)arg1, (TextIdListEntry *)Cd_GetFileEntrySubPtr(0xD280006, arg1->field_78 - 1), 2);
            Task_SetState1(arg0, 7);
        }
        break;
    }
}

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
    w->field_90 = (Stg11SaveList *)func_800676F4();
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

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067938);

INCLUDE_ASM("asm/USA/stag1100/nonmatchings/stag1100", func_80067B54);

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
