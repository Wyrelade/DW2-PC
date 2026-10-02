#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"

void func_80067530(Actor *a0, s32 a1, s32 a2) {
    a0->stateLevel0 = 2;
    a0->stateLevel1 = a1;
    a0->stateLevel2 = 0;
    a0->stateLevel3 = 0;
    a0->stateLevel4 = a2;
}

void func_8006754C(Stg30ListOwner *a0) {
    s32 i;
    Stg30ActorList *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            if (i < 3) {
                func_8006F640(l->actors[i], 1);
                func_8006F664(l->actors[i]);
            } else {
                func_8006F640(l->actors[i], 0);
            }
        }
    }
}

void func_800675CC(Stg30ListOwner *a0) {
    s32 i;
    Stg30ActorList *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            func_8006F640(l->actors[i], 1);
        }
    }
}

void func_80067624(Stg30ListOwner *a0) {
    s32 i;
    Stg30ActorList *l = a0->list;

    for (i = 0; i < 6; i++) {
        if (l->actors[i] != NULL) {
            func_8006F664(l->actors[i]);
        }
    }
}

s32 func_8006767C(Stg30IdSet *a0, s16 *a1, u8 id) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (a0->ids[i] == id) {
            return 1;
        }
        if (a1[i] == id) {
            return 1;
        }
    }
    return 0;
}

s32 func_800676C4(s32 a0, u8 a1) {
    return a0 >= func_8001F0C0(a1);
}

INCLUDE_RODATA("asm/USA/stag3000/rodata", jtbl_80063488);
#ifdef NORMALIZED
void func_800676F4(Actor *a0) {
    Stg30ActorList *l = (Stg30ActorList *)a0->u34.children;
    Stg30Pair sum;
    Stg30Init737A0 args;
    u8 ids[24];
    u8 idx[24];
    s32 arg;
    s32 cnt;
    Stg30IdSet *e;
    s32 flag;
    s32 i;
    s32 n;
    s32 m;
    s32 stage;
    s32 f;
    s32 st;
    s32 t;
    s32 k;
    s32 done;
    s32 j;
    s32 stage2;

    switch (a0->stateLevel2) {
    case 0:
    default:
        if (D_8007409C != 0) {
            Snd_PlayById(0x202, 1);
        } else {
            Snd_PlayById(0x201, 1);
        }
        Task_Create(0x505, &l->field_24, 2);
        func_80070D14(0x19);
        func_8006754C((Stg30ListOwner *)a0);
        a0->elapsed = 0;
        Task_NextState2(a0);
    case 1:
        done = 0;
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_2E != 0) {
                f = Anim_GetModelAnimFile(D_80073CC0.entries[i].field_19, 8);
                Cd_QueueFile(f);
                if (Cd_GetFileState(f) != 3) {
                    done = 1;
                    break;
                }
            }
        }
        if (done) {
            break;
        }
        if (a0->elapsed < 0x3C) {
            break;
        }
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_2E != 0) {
                Task_SetState01(l->actors[i], 2, 2);
            }
        }
        Cd_QueueFile(0x13A);
        Cd_QueueFile(0x110);
        Cd_QueueFile(0x25C);
        a0->elapsed = 0;
        Task_NextState2(a0);
    case 2:
        if (Cd_GetFileState(0x13A) != 3 || Cd_GetFileState(0x110) != 3 || Cd_GetFileState(0x25C) != 3) {
            break;
        }
        if (a0->elapsed < 0xF0) {
            break;
        }
        if (D_80073CC0.entries[0].field_0 == 0) {
            sum.field_4 = 0;
            sum.field_0 = 0;
            for (t = 3; t < 6; t++) {
                if (D_80073CC0.entries[t].field_19 != 0) {
                    sum.field_4 += D_80073CC0.field_240[t].field_0;
                    sum.field_0 += D_80073CC0.entries[t].field_28;
                }
            }
            Task_Create(0x502, &l->field_28, (s32)&sum);
            Task_NextState2(a0);
            break;
        }
        Task_SetState2(a0, 5);
        break;
    case 3:
        switch (a0->stateLevel3) {
        case 0:
        default:
            if (l->field_28 != 0) {
                break;
            }
            Task_NextState3(a0);
        case 1:
        case 2:
        case 3:
            if (D_80073CC0.field_34C[a0->stateLevel3 - 1] == 0) {
                Task_NextState3(a0);
                break;
            }
            switch (a0->stateLevel4) {
            case 0:
            default:
                e = (Stg30IdSet *)&((Stg30StateDigis *)&D_80073CC0)->digis[a0->stateLevel3 - 1];
                Mem_Zero(&args, 0x1C);
                args.field_0 = a0->stateLevel3 - 1;
                flag = 0;
                cnt = 0;
                if (e->field_46 != 0) {
                    if (!func_8006767C(e, args.field_4, e->field_46)) {
                        args.field_4[cnt++] = e->field_46;
                        flag = 1;
                    }
                    e->field_46 = 0;
                }
                j = 0;
                n = 0;
                stage = func_8001D958(e->digiId);
                for (; j < 0x18; j++) {
                    if (e->field_2E[j] != 0 && func_800676C4(stage, e->field_2E[j])) {
                        idx[n] = j;
                        ids[n] = e->field_2E[j];
                        n++;
                    }
                }
                if (n != 0) {
                    m = (e->level - 2) % 10;
                    if (m >= 3) {
                        k = n;
                    } else {
                        k = n / (4 - m) + 1;
                    }
                    for (j = 0; j < k; j++) {
                        if (func_8006767C(e, args.field_4, ids[j])) {
                            e->field_2E[idx[j]] = 0;
                        } else {
                            flag = 1;
                            args.field_4[cnt++] = ids[j];
                            e->field_2E[idx[j]] = 0;
                        }
                    }
                }
                if (!flag) {
                    Task_NextState3(a0);
                    break;
                }
                Task_Create(0x512, &l->field_28, (s32)&args);
                Task_NextState4(a0);
                break;
            case 1:
                if (l->field_28 == 0) {
                    Task_NextState3(a0);
                }
                break;
            }
            break;
        case 4:
            Task_NextState2(a0);
            break;
        }
        break;
    case 4:
        if (l->field_28 != 0) {
            break;
        }
        st = D_8005E5E0;
        if (st != 0) {
            stage2 = func_8001D958(D_80073CC0.entries[D_80073CC0.field_3D8].field_19);
            if ((Rand_Next() & 0x7F) < D_80073188[stage2][st - 1]) {
                arg = D_80073CC0.field_3D8;
                Task_Create(0x513, &l->field_28, (s32)&arg);
            }
        }
        Task_NextState2(a0);
        break;
    case 5:
        if (l->field_28 != 0) {
            break;
        }
        if ((D_8005F790 & 0xFF00) == 0x200) {
            func_80011644();
        }
        Task_NextState2(a0);
    case 6:
        switch (a0->stateLevel3) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState3(a0);
        case 1:
            if (++a0->stateLevel4 < 0x10) {
                break;
            }
            if (Flag_Test(0x2DD)) {
                Flag_Set(0x2DD, 0);
                D_8005F78C = 0x406;
            } else {
                D_8005F770.field_24 = 2;
                D_8005F770.nextGameMode = D_8005F770.prevGameMode;
            }
            Task_NextState3(a0);
            break;
        case 2:
            break;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000_41D0", func_800676F4);
void func_800676F4(Actor *a0);
#endif

void func_80067DB4(Stg30ListOwner *a0) {
    Stg30ActorList *l = a0->list;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x203, 1);
        func_8006754C(a0);
        Task_Create(0x505, &l->field_24, 3);
        func_80070D14(0x19);
        Task_NextState2((Actor *)a0);
    case 1:
        if (l->field_24 != 0) {
            break;
        }
        Task_NextState2((Actor *)a0);
    case 2:
        switch (a0->stateLevel3) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xF);
            Task_NextState3((Actor *)a0);
        case 1:
            if (D_8005F770.fadeLevel == 0xFF) {
                if (D_80073CC0.entries[0].field_0 != 0) {
                    D_8005F770.field_24 = 2;
                    D_8005F770.nextGameMode = D_8005F770.prevGameMode;
                } else {
                    D_8005F770.nextGameMode = 0x401;
                }
                Task_NextState3((Actor *)a0);
            }
        case 2:
            break;
        }
        break;
    }
}

void func_80067EC4(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_80073CC0.entries[i].field_18 >= 3) {
            D_80073CC0.entries[i].field_34 = D_8005E620.elems[i].field_1C;
            D_80073CC0.entries[i].field_36 = D_8005E620.elems[i].field_1E;
            D_80073CC0.entries[i].field_38 = D_8005E620.elems[i].field_20;
        }
    }
}

void func_80067F2C(Actor *a0) {
    Stg30Work731A0 *w = (Stg30Work731A0 *)a0->work;
    Stg30ActorList *l = (Stg30ActorList *)a0->u34.children;
    s32 args[3];
    Out1DB68 out;
    TaskEntry *t;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 v;
    s32 sum;
    s32 alive;
    s32 flag;
    s32 n1;
    s32 n2;
    s32 n3;
    s32 n4;
    s32 n5;
    s32 n6;
    s32 n7;

    switch (a0->stateLevel0) {
    case 0:
        switch (a0->stateLevel1) {
        case 0:
        default:
            func_800701FC();
            Task_NextState1(a0);
        case 1:
            if (D_80073CC0.entries[0].field_0 != 0) {
                switch (a0->stateLevel2) {
                case 0:
                default:
                    Snd_SetSlotContent(2, 0x19);
                    Task_NextState2(a0);
                case 1:
                    if (Snd_AnySlotLoading()) {
                        break;
                    }
                    Snd_PlayById(0x200, 1);
                    Task_NextState1(a0);
                    break;
                }
                break;
            }
            Task_NextState1(a0);
        case 2:
            Cd_FreeUnlockedFiles();
            Gpu_AllocPacketBufs(0x32000);
            Gfx_InitLights();
            Sys_SetFrameRate30();
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
            Gpu_SetBgClearColor(0, 0, 0);
            Gpu_ClearScreens();
            Gfx_FadeInFromBlack(0x40);
            Task_Create(9, &l->field_0, 0);
            Task_Create(0x503, &l->field_10, 0);
            Task_Create(0x50A, &l->field_14, 0);
            Task_Create(0x505, &l->field_24, 0);
            Cd_QueueFile(0x1FD);
            Cd_QueueFile(0x25B);
            Cd_QueueFile(0xC6C);
            Cd_QueueFile(0x1A0);
            Cd_QueueFile(0x22B);
            Cd_QueueFile(0x45E);
            for (i = 0; i < 3; i++) {
                Mem_Zero(&((Stg30StateDigis *)&D_80073CC0)->digis[i], 0x5C);
                if (D_8005E620.elems[i].state >= 3) {
                    ((Stg30StateDigis *)&D_80073CC0)->digis[i] = D_8005E620.elems[i];
                    args[1] = i;
                    args[2] = D_80073CC0.entries[i].field_2E == 0;
                    Task_Create(0x509, (s32 *)&l->actors[i], (s32)args);
                }
            }
            for (i = 3; i < 6; i++) {
                Mem_Zero(&((Stg30StateDigis *)&D_80073CC0)->digis[i], 0x5C);
                func_8001DDA8(D_8005F770.field_24, i - 3, &((Stg30StateDigis *)&D_80073CC0)->digis[i],
                              (Out1DDA8 *)&D_80073CC0.field_240[i]);
                if (D_80073CC0.entries[i].field_19 != 0) {
                    args[1] = i;
                    args[2] = 0;
                    Task_Create(0x509, (s32 *)&l->actors[i], (s32)args);
                }
            }
            func_8001DB68((void *)D_8005F794, &out);
            D_80073CC0.field_3DC = out.field_14;
            for (n1 = 0; n1 < 6; n1++) {
                D_80073CC0.field_37A[n1] = D_80073CC0.field_356[n1] = D_80073CC0.entries[n1].field_34;
                D_80073CC0.field_386[n1] = D_80073CC0.field_362[n1] = D_80073CC0.entries[n1].field_36;
                D_80073CC0.field_392[n1] = D_80073CC0.field_36E[n1] = D_80073CC0.entries[n1].field_38;
            }
            w->field_0 = 0;
            Task_NextState0(a0);
            break;
        }
        break;
    case 2:
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            t = Task_FindFirst(0x503, -1, -1);
            if (t != NULL && ((Actor *)t)->stateLevel0 == 1 && ((Actor *)t)->stateLevel1 == 1) {
                Task_NextState1(a0);
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                for (n2 = 0; n2 < 7; n2++) {
                    D_80073CC0.field_2AC[n2].field_F = 0;
                    D_80073CC0.field_2AC[n2].field_E = 0;
                    D_80073CC0.field_2AC[n2].field_6 = 0;
                    D_80073CC0.field_2AC[n2].field_4 = 0;
                    D_80073CC0.field_2AC[n2].field_0 = 0;
                }
                for (n3 = 0; n3 < 6; n3++) {
                    D_80073CC0.entries[n3].field_34 = D_80073CC0.field_356[n3];
                    D_80073CC0.entries[n3].field_36 = D_80073CC0.field_362[n3];
                    D_80073CC0.entries[n3].field_38 = D_80073CC0.field_36E[n3];
                }
                func_80067624((Stg30ListOwner *)a0);
                func_800675CC((Stg30ListOwner *)a0);
                Task_Create(0x50B, &l->field_C, 0);
                Task_NextState2(a0);
                break;
            case 1:
                Cd_QueueFile(0x22B);
                if (l->field_C != 0) {
                    break;
                }
                if (D_80073CC4 == 1) {
                    switch (a0->stateLevel3) {
                    case 0:
                    default:
                        out.field_0 = 5;
                        out.field_4 = 1;
                        Task_Create(0x50C, &l->field_24, (s32)&out);
                        Task_NextState3(a0);
                    case 1:
                        if (l->field_24 != 0) {
                            break;
                        }
                        func_80067EC4();
                        Gfx_FadeOutToBlack(0xF);
                        Task_NextState3(a0);
                    case 2:
                        if (++a0->stateLevel4 < 0x10) {
                            break;
                        }
                        D_8005F770.nextGameMode = D_8005F770.prevGameMode;
                        break;
                    }
                    break;
                }
                if (D_80073CC4 == 2) {
                    switch (a0->stateLevel3) {
                    case 0:
                    default:
                        out.field_0 = 5;
                        out.field_4 = 0;
                        Task_Create(0x50C, &l->field_24, (s32)&out);
                        Task_NextState3(a0);
                    case 1:
                        if (l->field_24 != 0) {
                            break;
                        }
                        for (n4 = 0; n4 < 3; n4++) {
                            D_80073CC0.field_2AC[n4].field_6 = 0;
                            D_80073CC0.field_2AC[n4].field_4 = 0;
                            D_80073CC0.field_2AC[n4].field_0 = 0;
                        }
                        D_80073CC4 = 0;
                        break;
                    }
                    break;
                }
                Task_NextState2(a0);
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                    Task_Create(0x505, &l->field_24, 1);
                    Task_NextState3(a0);
                case 1:
                    if (l->field_24 != 0) {
                        break;
                    }
                    D_80073CC0.field_3D4 = 0;
                    if (D_80073CC0.field_2AC[6].field_0 != 0) {
                        Task_NextState3(a0);
                    } else {
                        Task_SetState3(a0, 0xFF);
                    }
                    break;
                case 2:
                    func_8006DB90();
                    Task_Create(0x50F, &l->field_48, 0);
                    Task_NextState3(a0);
                case 3:
                    if (l->field_48 != 0) {
                        break;
                    }
                    sum = 0;
                    for (n5 = 3; n5 < 6; n5++) {
                        sum += D_80073CC0.entries[n5].field_2E;
                    }
                    if (sum == 0) {
                        func_80067EC4();
                        Task_SetState1(a0, 4);
                        break;
                    }
                    Task_NextState3(a0);
                default:
                    a0->elapsed = 0;
                    Task_NextState2(a0);
                    break;
                }
                break;
            case 3:
                if (a0->elapsed < 0x3C) {
                    break;
                }
                func_80069594();
                func_800696E8();
                for (n6 = 5; n6 >= 0; n6--) {
                    D_80073CC0.field_2AC[n6].field_C = 0;
                }
                Task_NextState1(a0);
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                D_80073CC0.field_3B4 = 0;
                D_80073CC0.field_3D4 = 0;
                D_80073CC0.field_34F[0] = 0;
                D_80073CC0.field_34F[1] = 0;
                D_80073CC0.field_34F[2] = 0;
                D_80073CC0.field_34F[3] = 0;
                D_80073CC0.field_34F[4] = 0;
                D_80073CC0.field_34F[5] = 0;
                w->field_4 = 0;
                Task_NextState2(a0);
            case 1:
                if (D_80073CC0.entries[func_8006E674(0)].field_2E == 0) {
                    Task_SetState2(a0, 4);
                    break;
                }
                func_8006E690();
                if (!func_80069A44(func_8006E674(0))) {
                    Task_SetState2(a0, 4);
                    break;
                }
                func_80069DE8();
                w->field_8 = 0;
                D_80073CC0.field_3D0 = -1;
                if (func_8006CB28(func_8006E674(0))) {
                    Task_Create(0x50F, &l->field_48, 1);
                }
                Task_NextState2(a0);
            case 2:
                if (D_80073CC0.field_3D0 != -1) {
                    switch (a0->stateLevel3) {
                    case 0:
                    default:
                        func_8006E770();
                        Task_Destroy(&l->field_48);
                        D_80073CC0.field_2AC[D_80073CC0.field_3D0].field_4 = func_8006E674(0);
                        func_8006E55C(0, D_80073CC0.field_3D0);
                        D_80073CC0.field_3B0 = 0;
                        if (func_8006CB28(func_8006E674(0))) {
                            Task_Create(0x50F, &l->field_48, 1);
                        }
                        Task_NextState3(a0);
                    case 1:
                        if (l->field_48 != 0) {
                            break;
                        }
                        D_80073CC0.field_2AC[func_8006E674(0)].field_0 = 0;
                        func_8006E5B4(0);
                        if (D_80073CC0.entries[func_8006E674(0)].field_2E == 0) {
                            Task_NextState2(a0);
                            Task_NextState2(a0);
                            break;
                        }
                        D_80073CC0.field_3B0 = 0;
                        if (func_8006CB28(func_8006E674(0))) {
                            Task_Create(0x50F, &l->field_48, 1);
                        }
                        Task_NextState3(a0);
                    case 2:
                        if (l->field_48 != 0) {
                            break;
                        }
                        Task_NextState2(a0);
                        Task_NextState2(a0);
                        break;
                    }
                    break;
                }
                if (l->field_48 != 0) {
                    break;
                }
                Task_NextState2(a0);
                break;
            case 3:
                if (D_80073CC0.field_3B4 != 0 && D_80073CC0.field_2AC[func_8006E674(0)].field_0 == 1 &&
                    D_80073CC0.field_2AC[func_8006E674(0)].field_E == 0) {
                    for (i = 0; i < 6; i++) {
                        if (D_80073CC0.field_3B8[i] == -1) {
                            continue;
                        }
                        if (D_80073CC0.entries[D_80073CC0.field_3B8[i]].field_2E == 0) {
                            continue;
                        }
                        j = func_8006E5F8(D_80073CC0.field_3B8[i]);
                        if (j == -1) {
                            continue;
                        }
                        k = func_8006E674(j);
                        if (D_80073CC0.field_2AC[k].field_0 != 2) {
                            continue;
                        }
                        func_8006E5B4(j);
                        func_8006E55C(1, k);
                        if (func_8006E674(0) < 3 && D_80073CC0.field_3B8[i] < 3) {
                            D_80073CC0.field_2AC[k].field_4 = func_800692A4(0, 1, D_80073CC0.field_3B8[i]);
                        } else if (func_8006E674(0) >= 3 && D_80073CC0.field_3B8[i] >= 3) {
                            D_80073CC0.field_2AC[k].field_4 = func_800692A4(0, 7, D_80073CC0.field_3B8[i]);
                        } else {
                            D_80073CC0.field_2AC[k].field_4 = func_8006E674(0);
                        }
                        w->field_8 = 1;
                    }
                }
                Task_NextState2(a0);
            case 4:
                m = func_8006E674(0);
                if (m != func_8006E674(1)) {
                    if (D_80073CC0.field_2AC[func_8006E674(0)].field_0 != 5) {
                        D_80073CC0.field_2AC[func_8006E674(0)].field_0 = 0;
                    }
                }
                flag = 0;
                do {
                    alive = 0;
                    for (n7 = 0; n7 < 3; n7++) {
                        if (D_80073CC0.entries[n7].field_2E != 0) {
                            alive = 1;
                        } else {
                            D_80073CC0.field_31C[n7] = 0;
                        }
                    }
                    if (!alive) {
                        Task_SetState1(a0, 3);
                        flag = 1;
                        break;
                    }
                    alive = 0;
                    for (n7 = 3; n7 < 6; n7++) {
                        if (D_80073CC0.entries[n7].field_2E != 0) {
                            alive = 1;
                        } else {
                            D_80073CC0.field_31C[n7] = 0;
                        }
                    }
                    if (!alive) {
                        Task_SetState1(a0, 4);
                        flag = 1;
                    }
                } while (0);
                if (flag) {
                    func_80067EC4();
                    break;
                }
                func_8006E5B4(0);
                v = func_8006E674(0);
                if (v != -1) {
                    if (w->field_8 == 0) {
                        if (D_80073CC0.field_2AC[v].field_0 == 2) {
                            D_80073CC0.field_2AC[v].field_0 = 1;
                        }
                    }
                    Task_SetState2(a0, 1);
                    break;
                }
                Task_SetState1(a0, 1);
                D_80073CC0.field_3D4 = 1;
                for (n7 = 5; n7 >= 0; n7--) {
                    D_80073CC0.field_2AC[n7].field_0 = 0;
                }
                break;
            }
            break;
        case 3:
            func_80067DB4((Stg30ListOwner *)a0);
            break;
        case 4:
            func_800676F4(a0);
            break;
        }
        break;
    }
}
