#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/stag0000_1AE4_funcs.h"
#include "stag0000/stag0000_39F0_funcs.h"

void func_800679C8(Actor *arg0) {
    Stg00ModelWork *w = (Stg00ModelWork *)arg0->work;

    Gfx_AttachModel(arg0, w->field_14);
    Anim_StepModelAnim(arg0);
    Actor_UpdateTransform(arg0);
    Gfx_CalcModelBoneMatrices(arg0);
    if (w->field_20 != 0) {
        Gfx_DrawTexModel(arg0, 0);
    }
    if (w->field_24 != 0) {
        Gfx_DrawWireModel(arg0, 0, &w->field_28);
    }
}

void func_80067A50(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void func_80067A70(Actor *arg0) {
    Stg00FadeWork *w = (Stg00FadeWork *)arg0->work;
    s32 v;

    switch (arg0->stateLevel0) {
    case 0:
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_10++;
            w->field_C += 0x200;
            if (w->field_10 != 7) {
                break;
            }
            arg0->elapsed = 0;
            w->field_C = 0x1000;
            Task_NextState1(arg0);
        case 1:
            v = w->field_0;
            if (v != 7) {
                if (arg0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->field_10 = Math_CycleRange(arg0->elapsed, 2, 8, 0xF);
                if (arg0->elapsed < 0x90) {
                    break;
                }
                w->field_10 = v;
            }
            Task_NextState1(arg0);
        case 2:
            if (--w->field_10 < 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_80067BAC(Actor *arg0) {
    Stg00PanelWork *w = (Stg00PanelWork *)arg0->work;
    EntA0 *e = NULL;
    s32 draw = 1;
    Stg00PartScale *p;
    s32 id;

    switch (w->field_0) {
    case 0:
    default:
        e = Cd_GetFileEntry(func_8001EE5C(w->field_4));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        e = Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask(e, D_80068F28[w->field_0 - 4]);
        break;
    case 1:
    case 2:
    case 3:
        e = Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber(e, D_80068F44[w->field_0 - 1], 3, w->field_4);
        Gfx_HidePartsByMask(e, D_80068F38[w->field_0 - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->field_C != 0x1000) {
                p->field_E = 0;
                p->field_10 = w->field_C;
            } else {
                p->field_E = 1;
            }
            p->field_C = w->field_10;
        }
        Gfx_DrawParts(e);
    }
    if (w->field_8 != 0) {
        switch (w->field_8 >> 8) {
        case 0:
        default:
            id = 0x1A10026;
            break;
        case 1:
            id = 0x1A10027;
            break;
        case 2:
            id = 0x1A10028;
            break;
        }
        e = Cd_GetFileEntry(id);
        Gfx_HidePartsByMask(e, ~(1 << ((u8)w->field_8 - 1)));
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->field_C != 0x1000) {
                p->field_E = 0;
                p->field_10 = w->field_C;
            } else {
                p->field_E = 1;
            }
            p->field_C = w->field_10;
        }
        Gfx_DrawParts(e);
    }
}
INCLUDE_RODATA("asm/USA/stag0000/rodata", D_800634A8);

void func_80067DFC(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void func_80067E1C(Actor *arg0) {
    Stg00CdWork *w = (Stg00CdWork *)arg0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];

    switch (arg0->stateLevel0) {
    case 0:
    default:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            w->field_C = Cd_GetFileLba(w->field_0) + D_80068FA0[w->field_8 - 1];
            w->field_10 = w->field_C + D_80068FB8[w->field_8 - 1];
            param[0] = 1;
            param[1] = w->field_4;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->field_C, loc);
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
            CdIntToPos(w->field_C, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(arg0);
            }
            break;
        case 1:
            if ((((Stg00ActorTimer *)arg0)->field_24 & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(arg0, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->field_10) {
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

void func_80068050(Actor *arg0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(arg0);
}

u8 *func_80068084(s32 arg0, s32 arg1) {
    u8 *s = D_8006925C[arg0][arg1];
    s32 i = 0;
    s32 row = (arg1 != 0);

    for (; s[i] != 0; i++) {
        u8 c = s[i];
        if (c < 0x3A) {
            D_80069364[row][i] = c - 0x30;
        } else if (c == 0x5F) {
            D_80069364[row][i] = 0x24;
        } else {
            D_80069364[row][i] = c + 0xC9;
        }
    }
    D_80069364[row][i] = 0xFF;
    return D_80069364[row];
}

u8 *func_80068150(s32 arg0) {
    return func_80068084(arg0, 0);
}

u8 *func_80068170(s32 arg0, s32 arg1) {
    return func_80068084(arg0, arg1 + 1);
}

s32 func_80068190(void) {
    s32 i;

    for (i = 0; D_8006925C[i] != NULL; i++) {
    }
    return i;
}

s32 func_800681C4(s32 arg0) {
    u8 **p = D_8006925C[arg0];
    s32 i;

    for (i = 0; p[i] != NULL; i++) {
    }
    return i - 1;
}

void func_80068208(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    s32 i;
    s32 n;

    switch (arg0->stateLevel0) {
    case 0:
        Sys_SetFrameRate60();
        Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x100);
        Task_NextState0(arg0);
        break;
    case 1:
        if (D_8005F6F0[0].up > 0) {
            if (w->field_0 == 0) {
                break;
            }
            w->field_0--;
            w->field_4 = 0x3C;
        } else if (D_8005F6F0[0].down > 0) {
            if (w->field_0 == 2) {
                break;
            }
            w->field_0++;
            w->field_4 = 0x3C;
        } else {
            n = 5;
            for (i = 5; i >= 0; i--) {
                if (i == 5) {
                    w->field_8[n]++;
                }
                if (w->field_8[i] >= 10) {
                    w->field_8[i] -= 10;
                    if (i != 0) {
                        w->field_8[i - 1]++;
                    }
                }
            }
        }
        break;
    case 2:
        break;
    }
}

void func_8006835C(Actor *arg0) {
    Stg00CountWork *w = (Stg00CountWork *)arg0->work;
    EntA0 *e = Cd_GetFileEntry(0x770000);
    Stg00Part *p;

    Gfx_HidePartsByMask(e, D_800692C4[w->field_0]);
    p = (Stg00Part *)e;
    while (p->fileId != 0) {
        if (p->partMask & D_800692D0[w->field_0].field_8) {
            p->field_E = 0;
            if (w->field_4 != 0) {
                w->field_4--;
            } else {
                p->field_20 += 0x20;
            }
        }
        if (p->partMask & D_800692D0[w->field_0].field_0) {
            if ((p->field_20 + 0x400) & 0x800) {
                p->field_F = 0;
            }
        }
        if (p->partMask & D_800692D0[w->field_0].field_4) {
            if ((p->field_20 - 0x418) & 0x800) {
                p->field_F = 0;
            }
        }
        if (p->partMask & D_800692D0[w->field_0].field_C) {
            p->field_E = 1;
            p->field_20 = 0;
        }
        p++;
    }
    Gfx_DrawParts(e);
}

void func_800684E4(Actor *arg0) {
    Stg00SndWork *w = (Stg00SndWork *)arg0->work;
    TextOpenArgs t;

    switch (arg0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->field_0, 3);
        Snd_UnloadSlot(1);
        Snd_UnloadSlot(2);
        w->field_14 = -1;
        Task_NextState0(arg0);
        break;
    load:
        w->field_14 = w->field_C;
        Snd_SetSlotContent(0, w->field_C + 1);
        w->field_18 = w->field_10;
        Task_SetState1(arg0, 1);
        goto text;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            if (D_8005F6F0[0].right > 0) {
                w->field_C++;
                if (w->field_C == func_80068190()) {
                    w->field_C = 0;
                }
                w->field_10 = 0;
            } else if (D_8005F6F0[0].left > 0) {
                if (w->field_C == 0) {
                    w->field_C = func_80068190() - 1;
                } else {
                    w->field_C--;
                }
                w->field_10 = 0;
            } else if (D_8005F6F0[0].up > 0) {
                w->field_10++;
                if (w->field_10 == func_800681C4(w->field_C)) {
                    w->field_10 = 0;
                }
            } else if (D_8005F6F0[0].down > 0) {
                if (w->field_10 == 0) {
                    w->field_10 = func_800681C4(w->field_C) - 1;
                } else {
                    w->field_10--;
                }
            } else if (D_8005F6F0[0].circle > 0) {
                if (w->field_14 == w->field_C) {
                    Snd_PlayById(w->field_10, 0);
                } else {
                    goto load;
                }
            } else if (D_8005F6F0[0].cross > 0) {
                Snd_StopAll();
            }
        text:
            t.text = (s32)D_80069318;
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x28;
            t.y = 0x28;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->field_0, &t);
            t.text = (s32)func_80068150(w->field_C);
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x78;
            t.y = 0x50;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->field_4, &t);
            t.text = (s32)func_80068170(w->field_C, w->field_10);
            t.bigFont = 1;
            t.color = 0;
            t.x = 0x78;
            t.y = 0x64;
            t.charDelay = 0;
            t.charAdvance = 0xE;
            t.lineAdvance = 0x14;
            Text_Open(&w->field_8, &t);
            break;
        case 1:
            if (!Snd_AnySlotLoading()) {
                Snd_PlayById(w->field_18, 0);
                Task_SetState1(arg0, 0);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_800687E8(void) {
}

void func_800687F0(Actor *arg0, Stg00Blk1C *arg1) {
    *(Stg00Blk1C *)arg0->work = *arg1;
}

void func_80068830(Actor *arg0) {
    if (arg0->stateLevel0 == 0) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        GsInitCoordinate2(NULL, &w->field_1C);
        w->field_84 = 1;
        Task_NextState0(arg0);
    }
}

void func_80068884(Actor *arg0) {
    Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
    Stg00RefView rv;

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

TaskEntry *func_80068930(void) {
    return Task_FindFirst(0x109, -1, -1);
}

void func_80068958(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_0 += arg1;
        w->field_4 += arg2;
        w->field_8 += arg3;
    }
}

void func_8006899C(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_C += arg1;
        w->field_10 += arg2;
        w->field_14 += arg3;
    }
}

void func_800689E0(Actor *arg0, s32 arg1) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_18 = arg1;
        w->field_84 = 1;
    }
}

void func_80068A00(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_6C += arg1;
        w->field_70 += arg2;
        w->field_74 += arg3;
    }
}

void func_80068A44(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != NULL) {
        Stg00ObjWork *w = (Stg00ObjWork *)arg0->work;
        w->field_84 = 1;
        w->field_7C += arg1;
        w->field_7E += arg2;
        w->field_80 += arg3;
    }
}
