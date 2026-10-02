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

#ifdef NORMALIZED
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
#else
INCLUDE_ASM("asm/USA/stag3500/nonmatchings/stag3500", func_80063F38);
void func_80063F38(Actor *arg0);
#endif

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
