#include "common.h"
#include "stag3500/stag3500.h"

void func_800634FC(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;

    if (arg0->stateLevel0 == 0) {
        func_80066120(w);
        func_800661A4(w, 0xD3F0000);
        Task_NextState0(arg0);
    }
}

void func_80063550(Actor *arg0) {
    func_80066168((Stg35LoadHandle *)arg0->work);
    Task_DefaultDestroy(arg0);
}

void func_80063584(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;

    func_80066520(w, 2, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    func_800661B0(w);
}

void func_800635D4(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        arg0->digiId = 0xD77;
        Actor_InitTransform(arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, arg0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
    }
}

void func_8006363C(Actor *arg0) {
    Gfx_AttachModel(arg0, arg0->digiId);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    Gfx_DrawTexModel(arg0, 1);
}

void func_80063684(Actor *arg0, s32 *arg1) {
    ((Stg35Work *)arg0->work)->field_0 = *arg1;
}

void func_80063694(Actor *arg0, s32 arg1, s32 arg2) {
    Stg35ListWork *w = (Stg35ListWork *)arg0->work;
    s32 found = 0;
    s32 i;
    s32 j;

    for (i = 0; i < w->field_2D8; i++) {
        if (arg2 < w->field_F8[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = w->field_2D8; i < j; j--) {
            w->field_8[j] = w->field_8[j - 1];
            w->field_F8[j] = w->field_F8[j - 1];
        }
    }
    w->field_8[i] = arg1;
    w->field_F8[i] = arg2;
    w->field_2D8++;
}

void func_80063758(Actor *arg0) {
    Stg35ListWork *w = (Stg35ListWork *)arg0->work;
    s16 *p;
    GfxPart *part;
    s16 a[4];
    s16 b[4];
    s32 i;
    s32 j;
    s32 k;

    if (arg0->stateLevel0 != 0) {
        return;
    }
    switch (arg0->stateLevel1) {
    case 0:
    default:
        p = w->field_0;
        k = 0;
        while (*p != 0x14) {
            switch (*p) {
            case 13:
            case 19:
                p += 3;
                break;
            case 0:
            case 1:
            case 2:
            case 3:
            case 7:
            case 14:
            case 15:
                p += 2;
                break;
            case 4:
            case 5:
            case 6:
            case 16:
            case 17:
            case 18:
                p += 1;
                break;
            case 8:
                w->field_2E8 = D_8006AA88.rec[p[1]].digiId;
                w->field_31C = p[2];
                p += 3;
                break;
            case 9:
                w->field_304[k] = 1;
                w->field_2EC[k] = D_8006AA88.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 10:
                w->field_304[k] = 2;
                w->field_2EC[k] = D_8006AA88.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 11:
                w->field_304[k] = 3;
                w->field_2EC[k] = D_8006AA88.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 12:
                w->field_304[k] = 0;
                w->field_2EC[k] = D_8006AA88.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            }
        }
        Cd_QueueFile(func_8001EE5C(w->field_31C) >> 16);
        Task_NextState1(arg0);
        break;
    case 1:
        w->field_2DC = 0;
        w->field_2E0 = 0;
        w->field_1E8[w->field_2DC++] = Digi_GetModelFile(w->field_2E8);
        w->field_1E8[w->field_2DC++] = Anim_GetModelAnimFile(w->field_2E8, 0);
        w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2E8, func_8001EE10(w->field_31C) + 5);
        for (i = 0; i < 6; i++) {
            if (w->field_2EC[i] != 0) {
                w->field_1E8[w->field_2DC++] = Digi_GetModelFile(w->field_2EC[i]);
                w->field_1E8[w->field_2DC++] = Anim_GetModelAnimFile(w->field_2EC[i], 0);
                switch (w->field_304[i]) {
                case 0:
                default:
                    break;
                case 1:
                    w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2EC[i], 1);
                    break;
                case 3:
                    w->field_1E8[w->field_2DC++] = Anim_GetModelAnimFile(w->field_2EC[i], 0xA);
                case 2:
                    w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2EC[i], 2);
                    w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2EC[i], 9);
                    break;
                }
            }
        }
        if (w->field_31C != 0) {
            for (k = 0; k < 2; k++) {
                func_8001EEA4(w->field_31C, k, a, b);
                for (j = 0; j < 3; j++) {
                    if (a[j] != 0) {
                        w->field_260[w->field_2E0++] = a[j];
                    }
                    if (b[j] != 0) {
                        w->field_260[w->field_2E0++] = b[j];
                    }
                }
            }
        }
        w->field_1E8[w->field_2DC++] = 0x1A1;
        w->field_1E8[w->field_2DC++] = 0x13B;
        w->field_1E8[w->field_2DC++] = 0x1A0;
        w->field_1E8[w->field_2DC++] = 0x22B;
        w->field_1E8[w->field_2DC++] = 0xCB9;
        Task_NextState1(arg0);
        break;
    case 2:
        if (Cd_GetFileState(func_8001EE5C(w->field_31C) >> 16) == 3) {
            w->field_1E8[w->field_2DC++] = 0x1EF;
            part = (GfxPart *)Cd_GetFileEntry(func_8001EE5C(w->field_31C));
            while (part->fileId != 0) {
                w->field_260[w->field_2E0++] = part->fileId >> 16;
                part++;
            }
            w->field_2D8 = 0;
            for (i = 0; i < w->field_2DC; i++) {
                func_80063694(arg0, w->field_1E8[i], Cd_GetFileLba(w->field_1E8[i]));
            }
            for (i = 0; i < w->field_2E0; i++) {
                func_80063694(arg0, w->field_260[i], Cd_GetFileLba(w->field_260[i]));
            }
            Task_NextState1(arg0);
            w->field_4 = 0;
        }
        break;
    case 3:
        if (++w->field_4 < 300) {
            for (i = 0; i < w->field_2D8; i++) {
                Cd_QueueFile(w->field_8[i]);
                if (Cd_GetFileState(w->field_8[i]) != 3) {
                    return;
                }
            }
        }
        Task_NextState0(arg0);
        break;
    }
}

void func_80063E00(Actor *arg0) {
    Stg35ListWork *w = (Stg35ListWork *)arg0->work;
    s32 i;

    for (i = 0; i < w->field_2E0; i++) {
        if (w->field_260[i] != 0) {
            Cd_FreeFile(w->field_260[i]);
        }
    }
}

void func_80063E74(Actor *arg0) {
    s32 *slot = (s32 *)arg0->u34.children;
    s32 id;
    SysState *s;
    SysState *t;

    if (arg0->stateLevel0 != 0) {
        return;
    }
    s = &D_8005F770;
    switch (s->gameMode) {
    case 0x701:
    default:
        t = s;
        switch (t->prevGameMode) {
        case 0x603:
            t->field_24 = D_80050780 != 0;
            break;
            do {
            } while (0);
        case 0x604:
            s->field_24 = (D_80050780 != 0) ? 2 : 1;
            break;
        default:
            t->field_24 = 0;
            break;
        }
        id = 0x701;
        break;
    case 0x703:
        id = 0x705;
        break;
    case 0x702:
        id = 0x703;
        break;
    }
    Task_Create(id, slot, 0);
    Task_NextState0(arg0);
}

void func_80063F38(Actor *arg0) {
    Stg35Work4 *w = (Stg35Work4 *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 i;
    u16 pad;
    SysState *g;

    switch (arg0->stateLevel0) {
    case 0:
        switch (D_8005F770.field_24) {
        case 0:
        default:
            for (i = 4; i >= 0; i--) {
                D_8005E620.elems[i].state = 0;
            }
            w->field_2C = 0;
            break;
        case 1:
            w->field_2C = 2;
            break;
        case 2:
            w->field_2C = 1;
            break;
        }
        if (D_8005E620.elems[0].state != 0) {
            w->field_34 = 1;
        }
        if (D_8005E620.elems[3].state != 0) {
            w->field_38 = 1;
        }
        Gpu_AllocPacketBufs(0x32000);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, &slot[0], 0);
        Task_Create(0x702, &slot[1], 0);
        for (i = 0; i < 4; i++) {
            func_80066120(&w->load[i]);
        }
        for (i = 0; i < 7; i++) {
            func_800656D0(&w->text[i]);
        }
        Snd_UnloadSlot(2);
        Snd_SetSlotContent(1, 0x18);
        Task_NextState0(arg0);
        break;
    sel:
        Snd_PlayById(0xB, 0);
        w->field_3C = 1;
        goto next;
    case 1:
        if (w->field_40 == 0 && Snd_AnySlotLoading() == 0) {
            w->field_40 = 1;
            Snd_PlayById(0x103, 1);
            Snd_SetSlotContent(2, 0x19);
        }
        switch (arg0->stateLevel1) {
        case 0:
        default:
            func_800661A4(&w->load[0], 0xD3F0001);
            func_800664F4(&w->load[0]);
            func_800661A4(&w->load[1], 0x3120003);
            func_800664F4(&w->load[1]);
            if (w->field_34 != 0) {
                func_800661A4(&w->load[2], 0xD3F0003);
                func_800664F4(&w->load[2]);
                func_80066778(&w->load[2], 2, 3, (s16)D_8005E620.elems[0].maxHp);
                func_80066778(&w->load[2], 0x10, 3, (s16)D_8005E620.elems[0].maxMp);
                func_80066778(&w->load[2], 4, 3, (s16)D_8005E620.elems[1].maxHp);
                func_80066778(&w->load[2], 0x20, 3, (s16)D_8005E620.elems[1].maxMp);
                func_80066778(&w->load[2], 8, 3, (s16)D_8005E620.elems[2].maxHp);
                func_80066778(&w->load[2], 0x40, 3, (s16)D_8005E620.elems[2].maxMp);
            }
            if (w->field_38 != 0) {
                func_800661A4(&w->load[3], 0xD3F0004);
                func_800664F4(&w->load[3]);
                func_80066778(&w->load[3], 2, 3, (s16)D_8005E620.elems[3].maxHp);
                func_80066778(&w->load[3], 0x10, 3, (s16)D_8005E620.elems[3].maxMp);
                func_80066778(&w->load[3], 4, 3, (s16)D_8005E620.elems[4].maxHp);
                func_80066778(&w->load[3], 0x20, 3, (s16)D_8005E620.elems[4].maxMp);
                func_80066778(&w->load[3], 8, 3, (s16)D_8005E620.elems[5].maxHp);
                func_80066778(&w->load[3], 0x40, 3, (s16)D_8005E620.elems[5].maxMp);
            }
            func_80065760(&w->text[0], 0x101, 0x10, 0xBA);
            if (w->field_34 != 0) {
                for (i = 0; i < 3; i++) {
                    func_80065760(&w->text[i + 1], 0, 0x15, i * 0x22 + 0x4E);
                    func_800657A0((Stg35LoadHandle *)&w->text[i + 1], (s32)D_8005E620.elems[i].name);
                    func_80065824(&w->text[i + 1]);
                }
            }
            if (w->field_38 != 0) {
                for (i = 0; i < 3; i++) {
                    func_80065760(&w->text[i + 4], 0, 0xC9, i * 0x22 + 0x4E);
                    func_800657A0((Stg35LoadHandle *)&w->text[i + 4], (s32)D_8005E620.elems[i + 3].name);
                    func_80065824(&w->text[i + 4]);
                }
            }
            w->field_30 = 1;
            Task_NextState1(arg0);
        case 1:
            switch (w->field_2C) {
            case 0:
            default:
                pad = D_8005F6F0[0].pressed;
                break;
            case 1:
                pad = D_8005F6F0[0].pressed | D_8005F6F0[1].pressed;
                break;
            case 2:
                pad = D_8005F6F0[1].pressed;
                break;
            }
            if (pad & 0x10) {
                goto sel;
            }
            if (pad & 0x40) {
                Snd_PlayById(0xE, 0);
                w->field_3C = 0;
            next:
                Task_NextState0(arg0);
            }
            if (w->field_30 != 0) {
                w->field_30 = 0;
                func_800657B8(&w->text[0], D_8006A4AC[w->field_2C]);
                func_80065824(&w->text[0]);
            }
            func_800663CC(&w->load[0], D_8006A4B8[w->field_2C]);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        case 0:
        default:
            for (i = 0; i < 4; i++) {
                func_80066508(&w->load[i]);
            }
            for (i = 0; i < 7; i++) {
                func_80065894(&w->text[i]);
            }
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
        case 1:
            break;
        }
        g = &D_8005F770;
        if (g->fadeLevel == 0xFF) {
            s32 v;

            switch (w->field_2C) {
            case 0:
            default:
                v = w->field_3C == 0 ? 0x603 : 0x401;
                break;
            case 1:
                v = w->field_3C == 0 ? 0x702 : 0x701;
                break;
            case 2:
                v = w->field_3C == 0 ? 0x604 : 0x701;
                break;
            }
            g->nextGameMode = v;
        }
        break;
    }
}

void func_800645B4(Actor *arg0) {
    Stg35Work4 *w = (Stg35Work4 *)arg0->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80066168(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        func_80065718(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_80064638(Actor *arg0) {
    Stg35Work4 *w = (Stg35Work4 *)arg0->work;

    func_80066520(&w->load[0], 0x2A, Math_CycleRange(arg0->elapsed, 6, 0, 7));
    func_800661B0(&w->load[0]);
    func_800661B0(&w->load[1]);
    if (w->field_34 != 0) {
        func_800661B0(&w->load[2]);
    }
    if (w->field_38 != 0) {
        func_800661B0(&w->load[3]);
    }
}

void func_800646C0(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 v;

    switch (arg0->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x32000);
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, slot, 0);
        for (i = 0; i < 1; i++) {
            func_80066120(&w->load[i]);
        }
        for (i = 0; i < 14; i++) {
            func_800656D0(&w->text[i]);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                func_800661A4(w->load, 0xD3F0002);
                func_80066694(w->load, 0, 2, 0x140, 0, -0x1400);
                func_80066694(w->load, 1, 4, -0x140, 0, 0x1400);
                func_800663CC(w->load, 0x18);
                Task_NextState2(arg0);
            case 1:
                if (++arg0->stateLevel3 == 0x14) {
                    Snd_PlayById(0x101, 1);
                    func_800663CC(w->load, 0x10);
                    for (j = 0; j < 6; j++) {
                        func_80065760(&w->text[j], 1, D_8006A4DC[j].x, D_8006A4DC[j].y);
                        func_800657B8(&w->text[j], D_8006A4F4[j]);
                        func_80065824(&w->text[j]);
                    }
                    for (k = 0; k < 6; k++) {
                        func_80065760(&w->text[k + 6], 1, D_8006A500[k / 3].x, D_8006A500[k / 3].y + (k % 3) * 12);
                        func_800657A0((Stg35LoadHandle *)&w->text[k + 6], (s32)Digi_GetDefaultName(D_8005E620.elems[k].digiId));
                        func_80065824(&w->text[k + 6]);
                    }
                    for (l = 0; l < 2; l++) {
                        func_80065760(&w->text[l + 12], 1, D_8006A508[l].x, D_8006A508[l].y);
                        func_800657A0((Stg35LoadHandle *)&w->text[l + 12], (s32)D_8005E620.elems[l + 6].name);
                        func_80065824(&w->text[l + 12]);
                    }
                }
                if (arg0->stateLevel3 == 0x1E) {
                    Task_NextState2(arg0);
                }
                break;
            case 2:
                v = Math_CycleRange(arg0->elapsed, 6, 0, 7);
                func_800663CC(w->load, 0);
                func_80066520(w->load, 0x10, v);
                if (v == 7) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 1:
            if (D_8005F6F0[0].cross > 0 || D_8005F6F0[1].cross > 0) {
                Task_NextState0(arg0);
            }
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel2) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState2(arg0);
        case 1:
            if (D_8005F770.fadeLevel == 0xFF) {
                D_8005F770.nextGameMode = 0x703;
            }
            break;
        }
        break;
    }
}

void func_80064AF0(Actor *arg0) {
    Stg35Work1 *w = (Stg35Work1 *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w->load[i]);
    }
    for (i = 0; i < 14; i++) {
        func_80065718(&w->text[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_80064B70(Actor *arg0) {
    func_800661B0((Stg35LoadHandle *)arg0->work);
}

void func_80064B94(Actor *arg0, s32 arg1, s32 arg2) {
    arg0->stateLevel0 = 2;
    arg0->stateLevel1 = arg1;
    arg0->stateLevel2 = 0;
    arg0->stateLevel3 = 0;
    arg0->stateLevel4 = arg2;
}

void func_80064BB0(Stg35ChildOwner *arg0, s32 arg1) {
    Stg35ChildList *l = arg0->field_34;
    s32 i;

    for (i = 0; i < 6; i++) {
        Actor *a = l->field_2C[i];

        if (a != NULL) {
            if (arg1 == 0) {
                if (i < 3) {
                    func_800674D4(a, 1);
                    func_800674F8(l->field_2C[i]);
                } else {
                    func_800674D4(a, 0);
                }
            } else {
                if (i >= 3) {
                    func_800674D4(a, 1);
                    func_800674F8(l->field_2C[i]);
                } else {
                    func_800674D4(a, 0);
                }
            }
        }
    }
}

void func_80064C54(Stg35ChildOwner *arg0) {
    Stg35ChildList *l = arg0->field_34;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (l->field_2C[i] != NULL) {
            func_800674D4(l->field_2C[i], 1);
            func_800674F8(l->field_2C[i]);
        }
    }
}

void func_80064CB8(Actor *arg0) {
    Stg35BattleWork *w = (Stg35BattleWork *)arg0->work;
    Actor **c = (Actor **)arg0->u34.children;
    Stg35Arg3 a;
    s32 buf[6];
    s32 cnt[2];
    Actor *e;
    Actor *e2;
    s32 i;
    s32 k;
    s32 n;
    s32 m;
    s32 j;
    s32 r;
    s32 sum;
    s32 wait;
    s32 f;

    switch (arg0->stateLevel0) {
    case 0:
        Snd_PlayById(0x102, 1);
        func_80067720();
        Cd_FreeUnlockedFiles();
        Gpu_AllocPacketBufs(0x32000);
        Gfx_InitLights();
        Sys_SetFrameRate30();
        Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x40);
        Task_Create(9, (s32 *)&c[0], 0);
        Task_Create(0x706, (s32 *)&c[4], 0);
        Task_Create(0x704, (s32 *)&c[5], 0);
        Cd_QueueFile(0x1FD);
        Cd_QueueFile(0x25B);
        Cd_QueueFile(0xD3F);
        Cd_QueueFile(0xD41);
        Cd_QueueFile(0xD93);
        for (k = 0; k < 6; k++) {
            D_8006AA88.rec[k] = D_8005E620.elems[k];
        }
        for (j = 0; j < 6; j++) {
            a.field_8 = 0;
            a.field_0 = D_8006AA88.rec[j].digiId;
            a.field_4 = j;
            Task_Create(0x707, (s32 *)&c[11 + j], (s32)&a);
        }
        for (j = 0; j < 6; j++) {
            func_8006A168(j);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (c[4]->stateLevel0 == 1 && c[4]->stateLevel1 == 1) {
                Task_Create(0x708, (s32 *)&c[19], 0);
                Task_NextState1(arg0);
            }
            break;
        case 1:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                func_80064C54((Stg35ChildOwner *)arg0);
                func_8006A080(0x18);
                func_80065E60();
                e2 = (Actor *)Task_FindFirst(0x708, -1, -1);
                if (e2 != NULL) {
                    Task_SetState1(e2, 1);
                }
                Task_NextState2(arg0);
            case 2:
                Task_Create(0x70C, (s32 *)&c[17], w->field_4);
                Task_NextState2(arg0);
            case 3:
                if (c[17] == NULL) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 2:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                if (D_8006AA88.rec[func_80065E44(0)].hp == 0) {
                    Task_NextState1(arg0);
                    break;
                }
                Task_NextState2(arg0);
            case 1:
                switch (arg0->stateLevel3) {
                case 0:
                default:
                    func_8006A080(func_80065E44(0) + 0xA);
                    for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                        if (e->field_8 == func_80065E44(0)) {
                            func_800674D4(e, 1);
                            func_800674F8(e);
                        } else {
                            func_800674D4(e, 0);
                        }
                    }
                    for (m = 0; m < 6; m++) {
                        buf[5 - m] = D_8006AA88.field_238[func_80065E44(0)].field_C[m];
                    }
                    func_80068B10(func_80065E44(0) >= 3, buf);
                    Task_NextState3(arg0);
                    break;
                case 1:
                    if (func_80068B9C() == 1) {
                        break;
                    }
                    if (func_80068B9C() == 2) {
                        Task_SetState1(arg0, 3);
                        break;
                    }
                    f = func_80065E44(0);
                    func_80065F8C(f, func_80068C5C());
                    Task_NextState2(arg0);
                    break;
                }
                break;
            case 2:
                if (func_80069850(func_80065E44(0)) != 0) {
                    Task_Create(0x709, (s32 *)&c[18], 1);
                }
                Task_NextState2(arg0);
            case 3:
                if (c[18] == NULL) {
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        lose:
            Task_SetState1(arg0, 3);
            r = 1;
            w->field_C = r;
            goto chk;
        case 3:
            r = 0;
            sum = 0;
            for (n = 0; n < 3; n++) {
                sum += D_8006AA88.rec[n].hp;
            }
            if (sum == 0) {
                goto lose;
            }
            sum = 0;
            for (n = 3; n < 6; n++) {
                sum += D_8006AA88.rec[n].hp;
            }
            if (sum == 0) {
                Task_SetState1(arg0, 4);
                r = 1;
                w->field_C = 0;
            }
        chk:
            if (r == 0) {
                func_80065D84(0);
                if (func_80065E44(0) == -1) {
                if (++w->field_4 == 3) {
                memset((u8 *)cnt, 0, 8);
                for (n = 0; n < 3; n++) {
                    if (D_8006AA88.rec[n].hp != 0) {
                        cnt[0]++;
                    }
                }
                for (n = 3; n < 6; n++) {
                    if (D_8006AA88.rec[n].hp != 0) {
                        cnt[1]++;
                    }
                }
                if (cnt[0] == cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;
                    for (n = 0; n < 3; n++) {
                        if (D_8006AA88.rec[n].hp != 0) {
                            cnt[0] += D_8006AA88.rec[n].hp;
                        }
                    }
                    for (n = 3; n < 6; n++) {
                        if (D_8006AA88.rec[n].hp != 0) {
                            cnt[1] += D_8006AA88.rec[n].hp;
                        }
                    }
                }
                if (cnt[0] >= cnt[1]) {
                    w->field_C = 0;
                } else {
                    w->field_C = 1;
                }
                } else {
                    Task_SetState1(arg0, 1);
                    break;
                }
                } else {
                    Task_SetState1(arg0, 2);
                    break;
                }
            }
            Task_NextState0(arg0);
            break;
        }
        break;
    case 2:
        switch (arg0->stateLevel1) {
        nf:
            wait = 1;
            goto done;
        case 0:
        default:
            Snd_PlayById(0x202, 1);
            func_8006A080(w->field_C + 0x19);
            func_80064BB0((Stg35ChildOwner *)arg0, w->field_C);
            arg0->elapsed = 0;
            Task_NextState1(arg0);
        case 1:
            wait = 0;
            for (i = w->field_C * 3; i < w->field_C * 3 + 3; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    f = Anim_GetModelAnimFile(D_8006AA88.rec[i].digiId, 8);
                    Cd_QueueFile(f);
                    if (Cd_GetFileState(f) != 3) {
                        goto nf;
                    }
                }
            }
        done:
            if (wait != 0) {
                break;
            }
            if (arg0->elapsed < 0x3C) {
                break;
            }
            for (j = w->field_C * 3; j < w->field_C * 3 + 3; j++) {
                if (D_8006AA88.rec[j].hp != 0) {
                    Task_SetState01(c[11 + j], 2, 2);
                }
            }
            Task_NextState1(arg0);
            arg0->elapsed = 0;
        case 2:
            if (arg0->elapsed < 0x78) {
                break;
            }
            Task_Create(0x70D, (s32 *)&c[10], w->field_C);
            Task_NextState1(arg0);
        case 3:
            if (arg0->elapsed < 0x78) {
                break;
            }
            if (D_8005F6F0[0].cross > 0 || D_8005F6F0[1].cross > 0) {
                Task_NextState1(arg0);
            }
            break;
        case 4:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState1(arg0);
        case 5:
            if (++arg0->stateLevel2 >= 0x10) {
                D_8005F770.nextGameMode = 0x701;
                Task_NextState1(arg0);
            }
            break;
        case 6:
            break;
        }
        break;
    }
}

void func_80065694(Actor *arg0) {
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(arg0);
}

void func_800656D0(Stg35TextHandle *arg0) {
    Stg35TextObj *p = (Stg35TextObj *)Mem_Alloc(0x1C, 2);

    arg0->text = p;
    Mem_Zero(p, 0x1C);
    arg0->text->field_0 = -1;
}

void func_80065718(Stg35TextHandle *arg0) {
    if (arg0->text != NULL) {
        Text_Close(arg0->text);
        Mem_Free(arg0->text);
        arg0->text = NULL;
    }
}

void func_80065760(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->text->field_8 = arg1 >> 8;
    arg0->text->field_C = 0;
    arg0->text->field_10 = arg2;
    arg0->text->field_14 = arg3;
    arg0->text->field_18 = arg1 & 0xFF;
}

void func_800657A0(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->mode = arg1;
}

void func_800657AC(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->u.field_C = arg1;
}

void func_800657B8(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->field_4 = (s32)Cd_GetFileEntry(arg1 + 0x1FD0000);
}

void func_800657F0(Stg35TextHandle *arg0, s32 arg1) {
    arg0->text->field_4 = func_8001ED84(arg1);
}

void func_80065824(Stg35TextHandle *arg0) {
    Stg35TextObj *t = arg0->text;
    TextOpenArgs a;

    a.text = t->field_4;
    a.bigFont = t->field_8;
    a.color = t->field_C;
    a.x = t->field_10;
    a.y = t->field_14;
    a.charAdvance = 0;
    a.lineAdvance = 0;
    a.charDelay = t->field_18;
    Text_Open(t, &a);
}

void func_80065894(Stg35TextHandle *arg0) {
    Text_Close(arg0->text);
}

void func_800658B8(Stg35SpriteHandle *arg0) {
    arg0->sprite = (Stg35Sprite *)Mem_Alloc(0x20, 2);
    Mem_Zero(arg0->sprite, 0x20);
}

void func_800658F4(Stg35SpriteHandle *arg0) {
    if (arg0->sprite != NULL) {
        Mem_Free(arg0->sprite);
        arg0->sprite = NULL;
    }
}

void func_80065930(Stg35SpriteHandle *arg0) {
    Stg35Sprite *s = arg0->sprite;
    SysState *g;
    Stg35PolyG4 *p;
    u32 *ot;

    if (s->field_1C != 0 && s->field_1E != 0) {
        g = &D_8005F770;
        p = (Stg35PolyG4 *)g->packet.work;
        ot = g->otLayers.u[s->field_0];
        p->c0 = s->field_4[0];
        p->c1 = s->field_4[1];
        p->c2 = s->field_4[2];
        p->c3 = s->field_4[3];
        p->tag.b.len = 8;
        p->c0.code = 0x38;
        if (s->field_14 != 0) {
            p->c0.code = 0x3A;
        }
        p->x0 = p->x2 = s->field_18;
        p->x1 = p->x3 = s->field_18 + s->field_1C;
        p->y0 = p->y1 = s->field_1A;
        p->y2 = p->y3 = s->field_1A + s->field_1E;
        p->tag.word = (p->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        p++;
        if (s->field_14 != 0) {
            SetDrawMode((Stg35DrMode *)p, 0, 0, (s->field_16 & 3) << 5, 0);
            ((Stg35DrMode *)p)->tag = (((Stg35DrMode *)p)->tag & 0xFF000000) | (*ot & 0xFFFFFF);
            *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
            p = (Stg35PolyG4 *)((Stg35DrMode *)p + 1);
        }
        g->packet.work = (ActorWork *)p;
    }
}

void func_80065B04(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3) {
    Stg35Sprite *s = arg0->sprite;
    s->field_0 = arg1;
    s->field_14 = arg2;
    s->field_16 = arg3;
}

void func_80065B1C(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->field_4[arg1].r = arg2;
    s->field_4[arg1].g = arg3;
    s->field_4[arg1].b = arg4;
}

void func_80065B3C(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1C = arg1;
}

void func_80065B48(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1E = arg1;
}

void func_80065B54(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_18 = arg1;
}

void func_80065B60(Stg35SpriteHandle *arg0, s32 arg1) {
    arg0->sprite->field_1A = arg1;
}

void func_80065B6C(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Stg35Sprite *s = arg0->sprite;
    s->field_18 = arg1;
    s->field_1A = arg2;
    s->field_1C = arg3;
    s->field_1E = arg4;
}

s32 func_80065B88(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;

    if (arg2 >= arg1) {
        return arg0;
    }
    r = arg0 * arg2 / arg1;
    if (arg2 != 0 && r == 0) {
        r = 1;
    }
    if (r == arg1 && r != arg2) {
        r--;
    }
    return r;
}

s32 func_80065BE0(s32 arg0, s32 arg1, s32 arg2) {
    Stg35Rec5C *rec0 = &D_8006AA98[arg0];
    Stg35Rec5C *rec1 = &D_8006AA98[arg1];
    s32 a;
    s32 b;
    s32 prod;
    s32 c;
    s32 d;
    s32 num;
    s32 idx;
    s32 denom;
    s32 result;

    b = func_8001EF64(arg2);
    a = rec0->field_1C;
    func_8001EF88(arg2);
    c = rec1->field_1E;
    idx = func_80068CA0(arg1 >= 3);
    d = D_8006A540[idx];
    num = a * b;
    prod = c * d;
    c = prod / 100;
    denom = c * 2;
    result = num / denom;
    c = rec1->hp;
    if (result < c) {
        rec1->hp = rec1->hp - result;
    } else {
        rec1->hp = 0;
    }
    return result;
}

void func_80065D00(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_8006AA58[i] = v;
    }
}

void func_80065D2C(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 10; i >= arg0; i--) {
        D_8006AA58[i + 1] = D_8006AA58[i];
    }
    D_8006AA58[arg0] = arg1;
}

void func_80065D84(s32 arg0) {
    for (; arg0 < 11; arg0++) {
        D_8006AA58[arg0] = D_8006AA58[arg0 + 1];
    }
}

s32 func_80065DC8(s32 arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (arg0 == D_8006AA58[i]) {
            return i;
        }
    }
    return -1;
}

s32 func_80065E04(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_8006AA58[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 func_80065E44(s32 arg0) {
    return D_8006AA58[arg0];
}

void func_80065E60(void) {
    s32 v[6];
    s32 i;
    s32 j;
    s32 best;
    s32 max;

    for (i = 0; i < 6; i++) {
        if (D_8006AA88.rec[i].hp != 0) {
            v[i] = D_8006AA88.rec[i].field_20 + (u16)((u16)Rand_Next() % 11);
        } else {
            v[i] = 0;
        }
    }
    func_80065D00();
    for (i = 0; i < 6; i++) {
        max = 0;
        best = 0;
        for (j = 0; j < 6; j++) {
            if (v[j] != 0 && max < v[j]) {
                max = v[j];
                best = j;
            }
        }
        if (max == 0) {
            break;
        }
        func_80065D2C(func_80065E04(), best);
        v[best] = 0;
    }
}

void func_80065F8C(s32 arg0, s32 arg1) {
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s32 t;
    s32 base;
    s32 n;

    b->field_0 = 1;
    b->field_8 = b->field_C[arg1];
    switch (b->field_12[arg1]) {
    case 0:
    default:
        t = D_8006A55C[arg0];
        if (D_8006AA88.rec[t].hp != 0) {
            b->field_4 = t;
            break;
        }
    case 1:
        if (arg0 < 3) {
            base = 3;
        } else {
            base = 0;
        }
        for (n = 0; n < 100; n++) {
            t = (u16)((u16)Rand_Next() % 3) + base;
            if (D_8006AA88.rec[t].hp != 0) {
                break;
            }
        }
        if (n == 100) {
            t = arg0;
        }
        b->field_4 = t;
        break;
    case 2:
        if (arg0 < 3) {
            b->field_4 = 8;
        } else {
            b->field_4 = 7;
        }
        break;
    }
}

void func_80066120(Stg35LoadHandle *arg0) {
    Stg35Load *p = (Stg35Load *)Mem_Alloc(0x24, 2);

    arg0->load = p;
    Mem_Zero(p, 0x24);
    arg0->load->field_8 = 0x1000;
}

void func_80066168(Stg35LoadHandle *arg0) {
    if (arg0->load != NULL) {
        Mem_Free(arg0->load);
        arg0->load = NULL;
    }
}

void func_800661A4(Stg35LoadHandle *arg0, s32 arg1) {
    arg0->load->fileId = arg1;
}

void func_800661B0(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    Stg35Part *p = (Stg35Part *)Cd_GetFileEntry(l->fileId);
    Stg35Part *q;
    Stg35Part *r;
    Stg35Slide *s;
    s32 f;
    s32 c;
    s16 t;
    s32 k;

    switch (l->mode) {
    case 1:
        l->field_8 += 0x200;
        f = l->field_8 >= 0x1000;
        q = p;
        if (q->fileId != 0) {
            r = q;
            do {
                r->field_E = f;
                r->field_14 = l->field_8;
                q++;
                r++;
            } while (q->fileId != 0);
        }
        if (f) {
            l->mode = 0;
        }
        break;
    case 2:
        l->field_8 -= 0x200;
        q = p;
        if (q->fileId != 0) {
            r = q;
            do {
                r->field_E = 0;
                r->field_14 = l->field_8;
                q++;
                r++;
            } while (q->fileId != 0);
        }
        if (l->field_8 == 0) {
            l->mode = 0;
        }
        break;
    }
    for (k = 0; k < 2; k++) {
        if (l->u.slide[k].active != 0) {
            q = p;
            if (q->fileId != 0) {
                r = q;
                do {
                    if (r->groupMask & l->u.slide[k].mask) {
                        if (l->u.slide[k].dir != 0) {
                            l->u.slide[k].accum += l->u.slide[k].speed;
                            r->x += (s16)l->u.slide[k].accum >> 8;
                            l->u.slide[k].accum = (u8)l->u.slide[k].accum;
                            c = l->u.slide[k].target > r->x;
                        } else {
                            l->u.slide[k].accum += l->u.slide[k].speed;
                            r->x -= (s16)l->u.slide[k].accum >> 8;
                            l->u.slide[k].accum = (u8)l->u.slide[k].accum;
                            c = r->x > l->u.slide[k].target;
                        }
                        t = l->u.slide[k].target;
                        if (!c) {
                            r->x = t;
                            l->u.slide[k].active = 0;
                        }
                    }
                    q++;
                    r++;
                } while (q->fileId != 0);
            }
        }
    }
    Gfx_DrawParts((s32)p);
}

void func_800663CC(Stg35LoadHandle *arg0, s32 arg1) {
    Gfx_HidePartsByMask((GfxPartMaskView *)Cd_GetFileEntry(arg0->load->fileId), arg1);
}

void func_80066408(Stg35LoadHandle *arg0, s32 mask) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->visible = 1;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void func_80066480(Stg35LoadHandle *arg0, s32 mask) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->visible = 0;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void func_800664F4(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    l->mode = 1;
    l->field_8 = 0;
}

void func_80066508(Stg35LoadHandle *arg0) {
    Stg35Load *l = arg0->load;
    l->mode = 2;
    l->field_8 = 0x1000;
}

void func_80066520(Stg35LoadHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
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

void func_8006659C(Stg35LoadHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void func_80066618(Stg35LoadHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->y = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void func_80066694(Stg35LoadHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed) {
    Stg35Load *l = arg0->load;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(l->fileId);
    GfxPart *q;

    l->u.slide[idx].mask = mask;
    l->u.slide[idx].active = 1;
    l->u.slide[idx].target = target;
    if (speed < 0) {
        l->u.slide[idx].dir = 0;
        l->u.slide[idx].speed = -speed;
    } else {
        l->u.slide[idx].dir = 1;
        l->u.slide[idx].speed = speed;
    }
    if (p->fileId != 0) {
        q = p;
        do {
            if (q->groupMask & mask) {
                q->x = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void func_80066778(Stg35LoadHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx_SetPartsNumber((GfxPart *)Cd_GetFileEntry(arg0->load->fileId), arg1, arg2, arg3);
}

void func_800667D0(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;

    if (w->field_34 != arg1) {
        w->field_34 = arg1;
        Anim_SetModelAnim(arg0, arg1);
    }
}

void func_80066808(Actor *arg0, Stg35Vec3 *arg1) {
    s32 i = arg1->field_4;
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 n;

    arg0->field_8 = i;
    arg0->digiId = D_8006AA88.rec[i].digiId;
    w->field_14 = Digi_GetModelFile(arg0->digiId);
    if (arg0->field_8 < 3) {
        w->field_10 = 0x800;
    } else {
        w->field_10 = 0;
    }
    n = arg0->field_8;
    w->field_8 = 0;
    w->field_4 = (n % 3) * 0xA00 - 0xA00;
    w->field_C = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = arg1->field_8;
}

void func_800668F8(Actor *arg0, s32 arg1) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    Row6 ofs[3];
    Row6 *o;
    s32 i;

    func_8001EEA4(w->field_2C, 0, a, b);
    func_8001E7E4(arg0->digiId, ofs);
    o = &ofs[arg1];
    for (i = 0; i < 3; i++) {
        if (a[i] != 0) {
            args.field_0 = a[i];
            args.field_4 = b[i];
            args.field_14 = w->field_10;
            args.field_8 = w->field_4;
            args.field_C = w->field_8;
            args.field_10 = w->field_C;
            args.field_18 = 0x78;
            switch (i) {
            case 0:
                args.field_C -= func_8001E79C(arg0->digiId) + 0x280;
                break;
            case 1:
                args.field_C -= o->data[1];
                if (args.field_14 == 0) {
                    args.field_8 += o->data[0];
                    args.field_10 -= 0x100 + o->data[2];
                } else {
                    args.field_8 -= o->data[0];
                    args.field_10 += 0x100 + o->data[2];
                }
                break;
            case 2:
            default:
                break;
            }
            Task_Create(7, &slot[i], (s32)&args);
        }
    }
}

void func_80066A9C(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    s32 *slot = (s32 *)arg0->u34.children;
    Stg35SpawnArgs args;
    s16 a[4];
    s16 b[4];
    s32 i;

    func_8001EEA4(w->field_2C, 1, a, b);
    for (i = 0; i < 3; i++) {
        if (a[i] != 0) {
            args.field_0 = a[i];
            args.field_4 = b[i];
            args.field_14 = w->field_10;
            args.field_8 = w->field_4;
            args.field_C = w->field_8;
            args.field_10 = w->field_C;
            args.field_18 = 0x3C;
            switch (i) {
            case 0:
                args.field_C -= func_8001E79C(arg0->digiId) + 0x280;
                break;
            case 1:
                args.field_C -= func_8001E7C0(arg0->digiId);
                break;
            case 2:
            default:
                break;
            }
            Task_Create(7, &slot[i], (s32)&args);
        }
    }
}

void func_80066BC8(Actor *arg0) {
    Snd_PlayById(!func_8001E8D0(arg0->digiId) ? 0x204 : 0x205, 0);
}

void func_80066C00(Actor *arg0, s32 arg1) {
    Stg35Xform *t = (Stg35Xform *)arg0->u38.ptr38;

    if (arg0->stateLevel3 == 0 && arg0->stateLevel4 == 0) {
        Actor_StopAxisMotion(arg0, 1);
    } else {
        func_80020D54(arg0, 1);
        func_80020E00(arg0, 2);
    }
    switch (arg0->stateLevel3) {
    case 0:
    default:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            Actor_SetAxisMotion(arg0, 2, &D_8006A58C);
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            func_800667D0(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &D_8006A574);
            Task_NextState4(arg0);
            return;
        case 1:
            if (t->field_34 > 0) {
                Actor_StopAxisMotion(arg0, 1);
                t->field_34 = 0;
                t->field_4C = 0;
                Task_NextState3(arg0);
            }
            return;
        }
    case 1:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            func_80066BC8(arg0);
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            func_800667D0(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &D_8006A580);
            Task_NextState4(arg0);
            return;
        case 1:
            if (t->field_34 > 0) {
                Actor_StopAxisMotion(arg0, 1);
                t->field_34 = 0;
                t->field_4C = 0;
                Task_NextState3(arg0);
            }
            return;
        }
    case 2:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            func_80066BC8(arg0);
            func_800667D0(arg0, 0x16);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                Task_NextState3(arg0);
                if (arg1 != 0) {
                    Task_NextState3(arg0);
                }
            }
            break;
        }
        break;
    case 3:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            func_800667D0(arg0, 0x5A);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone < 0) {
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    case 4:
        switch (arg0->stateLevel4) {
        case 0:
        default:
            func_800667D0(arg0, 0x64);
            Task_NextState4(arg0);
            break;
        case 1:
            if (arg0->model->animDone != 0) {
                Task_SetState0(arg0, 1);
            }
            break;
        }
        break;
    }
}

void func_80066EBC(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    Stg35ModelFade *m = (Stg35ModelFade *)arg0->model;
    Stg35Arg1 a1;
    Stg35Xform *t;
    Stg35ModelFade *m0;
    s32 k;

    switch (arg0->stateLevel0) {
    case 0:
        Actor_InitTransform(arg0, &w->field_4, (u16)w->field_10);
        Gfx_AttachModel(arg0, w->field_14)->otIndex = 3;
        w->field_34 = -1;
        func_800667D0(arg0, 0);
        a1.field_0 = (s32)arg0;
        Task_Create(6, &((s32 *)arg0->u34.children)[3], (s32)&a1);
        m0 = (Stg35ModelFade *)arg0->model;
        w->field_18 = 1;
        w->field_1C = 0;
        m0->field_38 = m0->field_39 = m0->field_3A = 0x80;
        w->field_20.r = w->field_20.g = w->field_20.b = 0;
        w->field_28 = 1;
        if (w->field_38 != 0) {
            func_800667D0(arg0, 0x64);
        }
        Task_NextState0(arg0);
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            func_800667D0(arg0, 0);
            Task_SetState0(arg0, 1);
            break;
        case 6:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                func_80066A9C(arg0);
                arg0->elapsed = 0;
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->elapsed >= 0x78) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 1:
            w->field_2C = arg0->stateLevel4;
            k = func_8001EE10(w->field_2C);
            func_800668F8(arg0, k);
            switch (k) {
            case 0:
            default:
                func_800667D0(arg0, 0x32);
                break;
            case 1:
                func_800667D0(arg0, 0x3C);
                break;
            case 2:
                func_800667D0(arg0, 0x46);
                break;
            }
            Task_SetState0(arg0, 1);
            break;
        case 2:
            func_800667D0(arg0, 0x50);
            Task_SetState0(arg0, 1);
            break;
        case 3:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                func_80066A9C(arg0);
                func_800667D0(arg0, 0xA);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 4:
        case 5:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_2C = arg0->stateLevel4;
                func_80066A9C(arg0);
                Task_NextState2(arg0);
            case 1:
                func_80066C00(arg0, arg0->stateLevel1 - 4);
                break;
            }
            break;
        case 11:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                func_800667D0(arg0, 0x5A);
                Task_NextState2(arg0);
                break;
            case 1:
                if (arg0->model->animDone < 0) {
                    Task_SetState1(arg0, 0);
                }
                break;
            }
            break;
        case 12:
            w->field_2C = arg0->stateLevel4;
            func_80066A9C(arg0);
            if (arg0->model->animId != 0) {
                func_800667D0(arg0, 0);
            }
            Task_SetState0(arg0, 1);
            break;
        case 7:
            w->field_18 = 1;
            w->field_1C = 1;
            m->field_34 = 1;
            m->field_36 = 0x20;
            if (m->field_38 > 8) {
                m->field_38 -= 8;
            } else {
                m->field_38 = 0;
            }
            m->field_39 = m->field_3A = m->field_38;
            if (w->field_20.g < 0xEF) {
                w->field_20.g += 0x10;
            } else {
                w->field_20.g = 0xFF;
            }
            if (m->field_38 == 0 && w->field_20.g == 0xFF) {
                m->field_34 = 0;
                m->field_36 = 0;
                w->field_18 = 0;
                Task_SetState0(arg0, 1);
            }
            break;
        case 8:
            w->field_18 = 1;
            w->field_1C = 1;
            m->field_34 = 1;
            m->field_36 = 0x20;
            if (m->field_38 < 0x78) {
                m->field_38 += 8;
            } else {
                m->field_38 = 0x80;
            }
            m->field_39 = m->field_3A = m->field_38;
            if (w->field_20.g > 0x10) {
                w->field_20.g -= 0x10;
            } else {
                w->field_20.g = 0;
            }
            if (m->field_38 == 0x80 && w->field_20.g == 0) {
                m->field_34 = 0;
                m->field_36 = 0;
                w->field_1C = 0;
                Task_SetState0(arg0, 1);
            }
            break;
        case 10:
            w->field_28 = 0;
            break;
        case 9:
            m->field_38 = m->field_39 = m->field_3A = 0x80;
            m->field_34 = 0;
            m->field_36 = 0;
            w->field_18 = 1;
            w->field_1C = 0;
            w->field_28 = 1;
            Task_SetState0(arg0, 1);
            break;
        }
        break;
    }
    if (w->field_28 != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
    if (w->field_30 != 0 && --w->field_30 == 1) {
        t = (Stg35Xform *)arg0->u38.ptr38;
        t->field_30 = w->field_4;
        t->field_38 = w->field_C;
        t->field_50 = 0;
        t->field_48 = 0;
        Actor_StopAxisMotion(arg0, 2);
    }
}

void func_800673C4(Actor *arg0) {
    arg0->childCount = 4;
    Task_DefaultDestroy(arg0);
}

void func_800673E8(Actor *arg0) {
    Stg35Work *w = (Stg35Work *)arg0->work;
    CVECTOR c;

    if (w->field_28 != 0) {
        Gfx_AttachModel(arg0, w->field_14);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        if (w->field_18 != 0) {
            Gfx_DrawTexModel(arg0, 0);
        }
        if (w->field_1C != 0) {
            if (arg0->field_8 < 3) {
                c = w->field_20;
            } else {
                c.r = w->field_20.g;
                c.g = w->field_20.r;
                c.b = w->field_20.b;
            }
            Gfx_DrawWireModel(arg0, 0, &c);
        }
    }
}

void func_800674D4(Actor *arg0, s32 arg1) {
    ((Stg35Work *)arg0->work)->field_28 = arg1;
    if (arg1 != 0) {
        arg0->childCount = 4;
    } else {
        arg0->childCount = 3;
    }
}

void func_800674F8(Actor *arg0) {
    ((Stg35Work *)arg0->work)->field_30 = 2;
}

void func_80067508(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_80067510(Actor *arg0) {
    Stg35FadeWork *w = (Stg35FadeWork *)arg0->work;

    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            func_80066120(&w->load[i]);
        }
        func_800661A4(w->load, 0xD3F0009);
        {
            Stg35Masks masks = D_80063418;

            func_800663CC(w->load, ~masks.v[arg0->field_8]);
        }
        Snd_PlayById(0x24, 0);
        Task_NextState0(arg0);
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_4++;
            func_80066520(w->load, 0x1F, w->field_4 >> 1);
            if (w->field_4 != 14) {
                break;
            }
            Task_NextState1(arg0);
        case 1:
            if (((ActorAllocView *)arg0)->frameCount < 8) {
                break;
            }
            Task_NextState1(arg0);
        case 2:
            w->field_4--;
            func_80066520(w->load, 0x1F, w->field_4 >> 1);
            if (w->field_4 == 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void func_8006768C(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_800676E0(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}

void func_80067720(void) {
    Mem_Zero(&D_8006AA88, 0x358);
}

void func_80067748(Actor *arg0, Stg35Vec3 *arg1) {
    ((Stg35VecWork *)arg0->work)->field_0 = *arg1;
}

void func_80067768(Actor *arg0) {
    Stg35CdWork *w = (Stg35CdWork *)arg0->work;
    u8 filter[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];
    s32 r;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->start = Cd_GetFileLba(w->fileId) + D_8006A600[w->track - 1];
            w->end = w->start + D_8006A618[w->track - 1];
            filter[0] = 1;
            filter[1] = w->channel;
            CdControl(0xD, filter, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, loc);
            CdControlF(0x15, (s32)loc);
            Task_NextState1(arg0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(arg0, 0);
                break;
            case 2:
                Task_NextState0(arg0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((ActorAllocView *)arg0)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
                        Task_SetState0(arg0, 3);
                    } else {
                        CdControlF(0x11, 0);
                    }
                    break;
                }
            }
            break;
        }
        break;
    }
}

void func_8006799C(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

void func_800679D0(Actor *arg0) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 sel = 6 - w->field_54[arg0->field_8] / 4096;
    Stg35TextHandle *t;
    s32 i;

    for (i = 0; i < 7; i++) {
        t = &w->text[i];
        if (arg0->field_8 == 0) {
            func_80065760(t, 0, 0xB8, i * 14 + 0x49);
        } else {
            func_80065760(t, 0, 0x1C, i * 14 + 0x49);
        }
        if (i == 0) {
            func_800657B8(t, 1);
        } else if (w->field_5C[i - 1] != 0) {
            func_800657F0(t, w->field_5C[i - 1]);
        } else {
            func_800657B8(t, 0x1C3);
        }
        if (i == sel) {
            func_800657AC((Stg35LoadHandle *)t, 4);
        } else {
            func_800657AC((Stg35LoadHandle *)t, 1);
        }
        func_80065824(t);
    }
}

void func_80067B18(Actor *arg0, s32 arg1) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 s = func_80065B88(0xC4, 0x7000, w->field_54[arg0->field_8]);
    Stg35SpriteHandle *sp;

    if (arg0->field_8 == 0) {
        sp = &w->sprite[2];
    } else {
        sp = &w->sprite[3];
    }
    func_80065B48(sp, s);
    func_80065B60(sp, 0x60 - s);
    if (w->field_54[arg0->field_8] >= 0x6000) {
        func_80065B1C(sp, 0, 0xA4, 0x19, 2);
        func_80065B1C(sp, 1, 0xA4, 0x19, 2);
        func_80065B1C(sp, 2, 0xA4, 0x19, 2);
        func_80065B1C(sp, 3, 0xA4, 0x19, 2);
    } else {
        func_80065B1C(sp, 0, 0xAE, 0x7E, 0x11);
        func_80065B1C(sp, 1, 0xAE, 0x7E, 0x11);
        func_80065B1C(sp, 2, 0xA4, 0x19, 2);
        func_80065B1C(sp, 3, 0xA4, 0x19, 2);
    }
}

void func_80067C74(Actor *arg0, s32 arg1) {
    Stg35Work708 *w = (Stg35Work708 *)arg0->work;
    s32 s = func_80065B88(0x70, 0x6000, w->field_54[arg0->field_8]);
    Stg35SpriteHandle *sp;

    if (arg0->field_8 == 0) {
        sp = &w->sprite[0];
    } else {
        sp = &w->sprite[1];
    }
    if (arg0->field_8 == 0) {
        func_80065B3C(sp, s);
        func_80065B54(sp, -0x16 - s);
    } else {
        func_80065B3C(sp, s);
    }
    if (s == 0x70) {
        func_80065B1C(sp, 0, 0xA4, 0x19, 2);
        func_80065B1C(sp, 1, 0xA4, 0x19, 2);
        func_80065B1C(sp, 2, 0xA4, 0x19, 2);
        func_80065B1C(sp, 3, 0xA4, 0x19, 2);
    } else if (arg0->field_8 == 0) {
        func_80065B1C(sp, 0, 0xFA, 0, 0);
        func_80065B1C(sp, 1, 0, 0, 0xFC);
        func_80065B1C(sp, 2, 0xFA, 0, 0);
        func_80065B1C(sp, 3, 0, 0, 0xFC);
    } else {
        func_80065B1C(sp, 1, 0xFA, 0, 0);
        func_80065B1C(sp, 0, 0, 0, 0xFC);
        func_80065B1C(sp, 3, 0xFA, 0, 0);
        func_80065B1C(sp, 2, 0, 0, 0xFC);
    }
}

INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80067E48);

void func_800689FC(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80066168(&w->load[i]);
    }
    for (i = 0; i < 7; i++) {
        func_80065718(&w->text[i]);
    }
    for (i = 0; i < 10; i++) {
        func_800658F4(&w->sprite[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_80068AA0(Actor *arg0) {
    Stg35Work3 *w = (Stg35Work3 *)arg0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_800661B0(&w->load[i]);
    }
    for (i = 0; i < 10; i++) {
        func_80065930(&w->sprite[i]);
    }
}

void func_80068B10(s32 arg0, s32 *arg1) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        Task_SetState1(e, 2);
        e->field_8 = arg0;
        for (i = 0; i < 6; i++) {
            w->field_5C[i] = arg1[i];
        }
    }
}

s32 func_80068B9C(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);

    if (e != NULL && e->stateLevel1 == 2) {
        return 1;
    }
    return (((Stg35Work708 *)e->work)->field_78 != 0) * 2;
}

void func_80068BF8(void) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 i;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        for (i = 0; i < 6; i++) {
            w->field_80[i].field_0 = D_8006AA88.rec[i].hp;
            w->field_80[i].field_8 = D_8006AA88.rec[i].maxHp;
        }
    }
}

s32 func_80068C5C(void) {
    TaskEntry *e = Task_FindFirst(0x708, -1, -1);

    if (e != NULL) {
        return ((Stg35Work708 *)e->work)->field_74;
    }
    return 1;
}

s32 func_80068CA0(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x708, -1, -1);
    Stg35Work708 *w;
    s32 n;

    if (e != NULL) {
        w = (Stg35Work708 *)e->work;
        n = w->field_54[arg0] / 4096;
        if (w->field_5C[5 - n] != 0) {
            if (n == 6) {
                return 6;
            }
            return n;
        }
    }
    return 0;
}

void func_80068D34(Actor *arg0) {
    Stg35ScriptWork *w = (Stg35ScriptWork *)arg0->work;
    Actor **children = (Actor **)arg0->u34.children;
    Actor *e;
    s32 *q;
    s32 cont;
    Stg35Arg1 a1;
    Stg35Arg3 a3;

    switch (arg0->stateLevel0) {
    case 0:
        w->script = D_8006ADE0;
        Task_NextState0(arg0);
        break;
    case 1:
        cont = 1;
        do {
            switch (w->script[0]) {
            case 0:
                switch (arg0->stateLevel1) {
                case 0:
                default:
                    arg0->elapsed = 0;
                    arg0->stateLevel1++;
                case 1:
                    break;
                }
                if (w->script[1] < arg0->elapsed) {
                    arg0->stateLevel1 = 0;
                    w->script += 2;
                } else {
                    cont = 0;
                }
                break;
            case 1:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                if (e->stateLevel0 == 2) {
                    cont = 0;
                } else {
                    w->script += 2;
                }
                break;
            case 2:
                func_8006A080(w->script[1]);
                cont = 0;
                w->script += 2;
                break;
            case 3:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->field_8 == w->script[1]) {
                        func_800674D4(e, 1);
                        func_800674F8(e);
                    } else {
                        func_800674D4(e, 0);
                    }
                }
                w->script += 2;
                break;
            case 4:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->field_8 < 3) {
                        func_800674D4(e, 1);
                        func_800674F8(e);
                    }
                }
                w->script += 1;
                break;
            case 5:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->field_8 >= 3) {
                        func_800674D4(e, 1);
                        func_800674F8(e);
                    }
                }
                w->script += 1;
                break;
            case 6:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    func_800674D4(e, 1);
                    func_800674F8(e);
                }
                w->script += 1;
                break;
            case 7:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Task_SetState0(e, 2);
                Task_SetState1(e, 0);
                w->script += 2;
                break;
            case 8:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Task_SetState0(e, 2);
                Task_SetState1(e, 1);
                Task_SetState4(e, (u8)w->script[2]);
                w->script += 3;
                break;
            case 9:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                func_80064B94(e, 3, w->script[2]);
                w->script += 3;
                break;
            case 10:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                func_80068BF8();
                func_80064B94(e, 4, w->script[2]);
                w->script += 3;
                break;
            case 11:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                func_80068BF8();
                func_80064B94(e, 5, w->script[2]);
                w->script += 3;
                break;
            case 12:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                func_80064B94(e, 6, w->script[2]);
                w->script += 3;
                break;
            case 13:
                w->script += 3;
                break;
            case 14:
            case 15:
                w->script += 2;
                break;
            case 16:
                break;
            case 17:
                a1.field_0 = (s32)D_8006ADE0;
                Task_Create(0x70A, (s32 *)&children[3], (s32)&a1);
                w->script += 1;
                break;
            case 18:
                if (children[3]->stateLevel0 == 1) {
                    w->script += 1;
                } else {
                    cont = 0;
                }
                break;
            case 19:
                switch (arg0->stateLevel1) {
                case 0:
                default:
                    q = func_8001EFF0(w->script[1]);
                    a3.field_0 = q[0];
                    a3.field_4 = q[1];
                    a3.field_8 = w->script[2];
                    Task_Create(0x70B, (s32 *)&children[4], (s32)&a3);
                    Task_NextState1(arg0);
                case 1:
                    break;
                }
                if (children[4]->stateLevel0 == 1) {
                    Task_SetState0(children[4], 2);
                    w->script += 3;
                    Task_SetState1(arg0, 0);
                } else {
                    cont = 0;
                }
                break;
            case 20:
                Task_SetState0(arg0, 3);
                cont = 0;
                break;
            }
        } while (cont);
        break;
    }
}

void func_8006926C(s32 arg0) {
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s16 *p;
    s16 targets[6];
    s32 dmg[6];
    s16 kind = 1;
    s16 skill = (s16)b->field_8;
    s32 hit;
    s32 n;
    s32 c;
    s32 i;

    hit = func_8001EF64((s16)b->field_8) > 0;
    p = D_8006ADE0;
    for (i = 0; i < 6; i++) {
        dmg[i] = 0;
        targets[i] = -1;
    }
    n = 0;
    switch (b->field_4) {
    default:
        if (D_8006AA88.rec[b->field_4].hp != 0) {
            n = 1;
            targets[0] = b->field_4;
        }
        break;
    case 7:
        if (hit) {
            for (i = 0, c = 0; i < 3; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    targets[c++] = i;
                }
            }
        } else {
            for (i = 0, c = 0; i < 3; i++) {
                targets[c++] = i;
            }
        }
        n = c;
        kind = 0;
        break;
    case 8:
        if (hit) {
            for (c = 0, i = 3; i < 6; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    targets[c++] = i;
                }
            }
        } else {
            for (c = 0, i = 3; i < 6; i++) {
                targets[c++] = i;
            }
        }
        n = c;
        kind = 1;
        break;
    case 9:
        if (hit) {
            for (c = 0, i = 0; i < 6; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    targets[c++] = i;
                }
            }
        } else {
            for (c = 0, i = 0; i < 6; i++) {
                targets[c++] = i;
            }
        }
        n = c;
        kind = 2;
        break;
    }
    for (i = 0; i < n; i++) {
        dmg[i] = func_80065BE0(arg0, targets[i], skill);
    }
    *p++ = 2;
    *p++ = arg0 + 10;
    *p++ = 3;
    *p++ = arg0;
    *p++ = 0x11;
    *p++ = 0xD;
    *p++ = D_8006AA88.field_238[arg0].field_0 - 1;
    *p++ = 1;
    *p++ = 0x12;
    *p++ = 0xE;
    *p++ = skill;
    *p++ = 0x13;
    *p++ = skill;
    *p++ = n;
    *p++ = 8;
    *p++ = arg0;
    *p++ = skill;
    *p++ = 0;
    *p++ = 0x96;
    *p++ = 7;
    *p++ = arg0;
    for (i = 0; i < n; i++) {
        *p++ = 2;
        *p++ = targets[i] + 0x10;
        *p++ = 3;
        *p++ = targets[i];
        *p++ = 0;
        *p++ = i == 0 ? 0x1E : 0xC;
        *p++ = 0xF;
        *p++ = dmg[i];
        if (hit) {
            if (D_8006AA88.rec[targets[i]].hp != 0) {
                *p++ = D_8006AA88.field_238[targets[i]].field_0 != 5 ? 0xA : 9;
            } else {
                *p++ = 0xB;
            }
        } else {
            *p++ = 0xC;
        }
        *p++ = targets[i];
        *p++ = skill;
        if (n == 1) {
            if (hit) {
                *p++ = 1;
                *p++ = targets[i];
                *p++ = 0;
                *p++ = 0x1E;
            } else {
                *p++ = 0;
                *p++ = 0x78;
            }
        } else {
            *p++ = 0;
            *p++ = 0x3C;
        }
    }
    if (n != 1) {
        *p++ = 2;
        *p++ = kind + 0x16;
        *p++ = kind + 4;
        *p++ = 0;
        *p++ = 0xB4;
    }
    *p = 0x14;
    for (i = 0; i < 6; i++) {
        D_8006AA88.field_340[i] = targets[i];
    }
}

s32 func_80069850(s32 arg0) {
    func_8006926C(arg0);
    return 1;
}

s32 func_80069870(s32 arg0, s32 arg1) {
    s32 neg = 0;
    s32 r;

    arg0 -= arg1;
    if (arg0 == 0) {
        return neg;
    }
    if (arg0 < 0) {
        neg = 1;
        arg0 = -arg0;
    }
    r = arg0 / 16;
    if (r == 0) {
        r = 1;
    }
    if (neg) {
        r = -r;
    }
    return r;
}

void func_800698C8(Stg35CamWork *w, s32 *t) {
    s32 i;

    for (i = 0; i < D_8005F770.frameDelta; i++) {
        w->field_7E += func_80069870(t[0], w->field_7E);
        w->field_0 += func_80069870(t[1], w->field_0);
        w->field_4 += func_80069870(t[2], w->field_4);
        w->field_8 += func_80069870(t[3], w->field_8);
        w->field_10 += func_80069870(t[4], w->field_10);
        w->field_6C += func_80069870(t[5], w->field_6C);
        w->field_74 += func_80069870(t[6], w->field_74);
    }
}

void func_800699FC(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    s32 i;
    s32 h;

    switch (arg0->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->field_1C);
        w->field_4 = -0x4E20;
        w->field_10 = 0x12C;
        w->field_18 = 0x5DC;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_4 += 0xE9;
                w->field_8 -= 0x15E;
                w->field_7E += 0x44;
                if (w->field_7E > 0x1000) {
                    w->field_7E = 0;
                    Task_NextState2(arg0);
                }
                break;
            case 1:
                w->field_10 -= 0x21;
                if (++arg0->stateLevel3 == 0x1E) {
                    w->field_10 = -0x2BC;
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 1:
            {
                s32 t[7];

                t[2] = -0x169B;
                t[3] = -0x5366;
                t[5] = 0;
                t[6] = 0;
                t[0] = 0;
                t[1] = 0;
                t[4] = -0x2BC;
                func_800698C8(w, t);
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            {
                s32 t[7];

                i = arg0->stateLevel1 - 2;
                h = func_8001E79C(D_8006AA88.rec[i].digiId);
                h = h < 0x300 ? 0 : h - 0x300;
                h /= 256;
                t[5] = (i % 3) * 0xA00 - 0xA00;
                t[6] = (i / 3) * 0x2800 - 0x1400;
                t[0] = D_8006A690[i];
                t[1] = 0;
                t[2] = -0xC30;
                t[3] = D_8006A69C[h];
                t[4] = D_8006A6B0[h];
                func_800698C8(w, t);
            }
            break;
        case 8:
            {
                s32 t[7];

                t[6] = -0x1400;
                t[0] = 0x238;
                t[2] = -0x91C;
                t[3] = 0x33FC;
                t[5] = 0;
                t[1] = 0;
                t[4] = -0x36C;
                func_800698C8(w, t);
            }
            break;
        case 9:
            {
                s32 t[7];

                t[6] = 0x1400;
                t[0] = 0x5C7;
                t[2] = -0x91C;
                t[3] = 0x33FC;
                t[5] = 0;
                t[1] = 0;
                t[4] = -0x36C;
                func_800698C8(w, t);
            }
            break;
        case 22:
            w->field_74 = -0x1E00;
            w->field_4 = -0x1F40;
            w->field_6C = 0;
            w->field_7E = 0;
            w->field_0 = 0;
            w->field_8 = 0x4E20;
            w->field_C = 0;
            w->field_10 = 0;
            w->field_14 = 0;
            break;
        case 23:
            w->field_74 = 0x1E00;
            w->field_7E = 0x800;
            w->field_4 = -0x1F40;
            w->field_6C = 0;
            w->field_0 = 0;
            w->field_8 = 0x4E20;
            w->field_C = 0;
            w->field_10 = 0;
            w->field_14 = 0;
            break;
        case 24:
            {
                s32 t[7];

                t[0] = -0x400;
                t[2] = -0x50FB;
                t[3] = -0x6EC6;
                t[5] = 0;
                t[6] = 0;
                t[1] = 0;
                t[4] = -0x29C;
                func_800698C8(w, t);
            }
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                D_8006AF70 = Rand_Next() & 3;
                Task_NextState2(arg0);
            case 1:
                break;
            }
            w->field_4 = -0x514;
            w->field_8 = 0x2EE0;
            w->field_10 = -0x578;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_14 = 0;
            w->field_7E = 0xAA;
            w->field_6C = (arg0->stateLevel1 - 10) * 0xA00 - 0xC80;
            w->field_74 = -0x1400;
            switch (D_8006AF70) {
            case 1:
                w->field_7E = 0x38;
                w->field_6C = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->field_8 = 0x34BC;
                break;
            case 2:
                w->field_4 = -0x1914;
                w->field_6C = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->field_74 = -0xF00;
                w->field_8 = 0x34BC;
                break;
            }
            if (arg0->stateLevel1 >= 13) {
                w->field_7E = 0x800 - w->field_7E;
                w->field_6C -= 0x1E00;
                w->field_74 = -w->field_74;
            }
            break;
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            w->field_4 = -0x5DC;
            w->field_8 = 0x2EE0;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_10 = -0x640;
            w->field_14 = 0;
            if (arg0->stateLevel1 < 19) {
                w->field_7E = 0xAA;
                w->field_6C = (arg0->stateLevel1 - 16) * 0xA00 - 0xA00;
                w->field_74 = -0x1400;
            } else {
                w->field_7E = 0x755;
                w->field_6C = (arg0->stateLevel1 - 19) * 0xA00 - 0xA00;
                w->field_74 = 0x1400;
            }
            break;
        case 25:
            w->field_74 = -0x1400;
            w->field_4 = -0x1388;
            w->field_8 = 0x3A98;
            w->field_6C = 0;
            w->field_70 = 0;
            w->field_7E = 0;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_10 = -0x3E8;
            w->field_14 = 0;
            break;
        case 26:
            w->field_74 = 0x1400;
            w->field_7E = 0x800;
            w->field_4 = -0x1388;
            w->field_8 = 0x3A98;
            w->field_6C = 0;
            w->field_70 = 0;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_10 = -0x3E8;
            w->field_14 = 0;
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void func_80069FD4(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    Stg35RefView rv;

    RotMatrixYXZ(&w->field_7C, &w->field_1C.coord);
    w->field_1C.coord.t[0] = w->field_6C;
    w->field_1C.coord.t[1] = w->field_70;
    w->field_1C.coord.t[2] = w->field_74;
    w->field_1C.flg = 0;
    rv.field_0 = w->field_0;
    rv.field_4 = w->field_4;
    rv.field_8 = w->field_8;
    rv.field_C = w->field_C;
    rv.field_10 = w->field_10;
    rv.field_14 = w->field_14;
    rv.field_18 = 0;
    rv.field_1C = &w->field_1C;
    GsSetProjection(w->field_18);
    GsSetRefView2(&rv);
}

void func_8006A080(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x706, -1, -1);

    if (e != NULL && e->stateLevel0 == 1) {
        Task_SetState1(e, (u8)arg0);
    }
}

void func_8006A0D4(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    Stg35Rec6 *p;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        p = D_8006AA24[i];
        j = 0;
        while (p->field_0 != 0) {
            if (p->field_0 == arg0) {
                goto found;
            }
            p++;
            j++;
        }
        continue;
    found:
        *arg1 = i;
        *arg2 = j;
        *arg3 = p->field_4;
        *arg4 = p->field_2;
        return;
    }
    *arg1 = -1;
    *arg2 = 100;
}

void func_8006A168(s32 arg0) {
    u8 *ids = D_8006AA88.rec[arg0].field_22;
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s32 best[6];
    s32 grp;
    s32 idx;
    s32 v4;
    s32 v2;
    s32 found;
    s32 i;

    for (i = 0; i < 6; i++) {
        b->field_C[i] = 0;
        best[i] = 100;
    }
    found = 0;
    for (i = 0; i < 12; i++) {
        if (ids[i] != 0) {
            func_8006A0D4(ids[i], &grp, &idx, &v4, &v2);
            if (grp != -1 && best[grp] > idx) {
                best[grp] = idx;
                found = 1;
                b->field_C[grp] = ids[i];
                b->field_1E[grp] = v2;
                b->field_12[grp] = v4;
            }
        }
    }
    if (!found) {
        b->field_C[0] = D_8006A6DC[1].field_0;
        b->field_1E[0] = D_8006A6DC[1].field_2;
        b->field_12[0] = D_8006A6DC[1].field_4;
    }
}

void func_8006A2D0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_8006A2D8(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 masks[2];
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            func_80066120(&w[i]);
        }
        func_800661A4(w, 0xD3F0008);
        masks[0] = 2;
        masks[1] = 4;
        func_800663CC(w, ~masks[arg0->field_8]);
        Task_NextState0(arg0);
    case 1:
        func_80066520(w, 6, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
        break;
    case 2:
    default:
        break;
    }
}

void func_8006A3B8(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_8006A40C(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}
