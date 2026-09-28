#include "common.h"
#include "stag3000/stag3000.h"

void func_80063898(Actor *a0, s32 a1) {
    a0->field_8 = a1;
}

void func_800638A0(Actor *a0) {
    switch (a0->stateLevel0) {
    case 0:
        if (a0->field_8 == 1) Snd_PlayById(0x24, 0);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_8) {
        case 0:
        default:
            if (a0->elapsed >= 0x100) Task_SetState0(a0, 3);
            break;
        case 1:
        case 2:
            if (a0->elapsed >= 0x80) Task_SetState0(a0, 3);
            break;
        case 3:
            if (a0->elapsed >= 0x12D && (D_8005F72A & 0x840)) Task_SetState0(a0, 3);
            break;
        }
        break;
case 2: break;
    }
}

void func_8006399C(Actor *a0) {
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(D_80072FC8[a0->field_8]);
    Stg30Part *q;

    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_CycleRange(a0->elapsed, 4, 0, 7);
    }
    if (a0->field_8 == 3) {
        if (D_80073CC0.entries[0].field_0 != 0) {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 1);
        } else {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 2);
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}

void func_80063A6C(Actor *a0) {
    if (a0->stateLevel0 == 0) {
        if (D_80073CC0.entries[0].field_0 != 0) {
            a0->digiId = D_80073008;
        } else {
            a0->digiId = D_80072FF0[D_8007300C[D_8005E5DD]];
        }
        Actor_InitTransform(a0, D_80043704, 0);
        Gfx_AttachModel(a0, a0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(a0);
        Task_NextState0(a0);
    }
}

void func_80063B28(Actor *a0) {
    Gfx_AttachModel(a0, a0->digiId);
    Actor_UpdateTransform(a0);
    Gfx_CalcModelBoneMatrices(a0);
    Gfx_DrawTexModel(a0, 1);
}

void func_80063B70(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

void func_80063B80(Actor *a0, s32 file, s32 lba) {
    Stg30Work73040 *w = (Stg30Work73040 *)a0->work;
    s32 found = 0;
    s32 i;
    s32 j;

    for (i = 0; i < w->count; i++) {
        if (lba < w->lbas[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = w->count; i < j; j--) {
            w->files[j] = w->files[j - 1];
            w->lbas[j] = w->lbas[j - 1];
        }
    }
    w->files[i] = file;
    w->lbas[i] = lba;
    w->count++;
}

void func_80063C44(Actor *a0) {
    Stg30Work73040 *w = (Stg30Work73040 *)a0->work;
    s16 *p;
    s32 k;
    s32 i;
    s32 j;
    Stg30Part *q;
    s16 a[4];
    s16 b[4];

    if (a0->stateLevel0 != 0) {
        return;
    }
    switch (a0->stateLevel1) {
    case 0:
    default:
        p = w->field_0;
        k = 0;
        while (*p != 0x18) {
            switch (*p) {
            case 16:
                p += 4;
                break;
            case 14:
            case 23:
                p += 3;
                break;
            case 0:
            case 1:
            case 2:
            case 3:
            case 7:
            case 15:
            case 17:
                p += 2;
                break;
            case 4:
            case 5:
            case 6:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
                p += 1;
                break;
            case 9:
                if (p[1] != 6) {
                    w->field_2E8 = D_80073CC0.entries[p[1]].field_19;
                    w->field_320 = 0;
                } else {
                    w->field_320 = 1;
                }
                w->field_31C = p[2];
                p += 3;
                break;
            case 10:
                w->field_304[k] = 1;
                w->field_2EC[k] = D_80073CC0.entries[p[1]].field_19;
                p += 3;
                k++;
                break;
            case 11:
                w->field_304[k] = 2;
                w->field_2EC[k] = D_80073CC0.entries[p[1]].field_19;
                p += 3;
                k++;
                break;
            case 12:
                w->field_304[k] = 3;
                w->field_2EC[k] = D_80073CC0.entries[p[1]].field_19;
                p += 3;
                k++;
                break;
            case 13:
                w->field_304[k] = 0;
                w->field_2EC[k] = D_80073CC0.entries[p[1]].field_19;
                p += 3;
                k++;
                break;
            case 8:
                w->field_304[k] = 4;
                w->field_2EC[k] = D_80073CC0.entries[p[1]].field_19;
                p += 3;
                k++;
                break;
            }
        }
        Cd_QueueFile(func_8001EE5C(w->field_31C) >> 16);
        Task_NextState1(a0);
        break;
    case 1:
        w->field_2DC = 0;
        w->field_2E0 = 0;
        if (w->field_320 == 0) {
            w->field_1E8[w->field_2DC++] = Digi_GetModelFile(w->field_2E8);
            w->field_1E8[w->field_2DC++] = Anim_GetModelAnimFile(w->field_2E8, 0);
            w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2E8, func_8001EE10(w->field_31C) + 5);
        }
        for (i = 0; i < 6; i++) {
            if (w->field_2EC[i] != 0) {
                w->field_1E8[w->field_2DC++] = Digi_GetModelFile(w->field_2EC[i]);
                w->field_1E8[w->field_2DC++] = Anim_GetModelAnimFile(w->field_2EC[i], 0);
                switch (w->field_304[i]) {
                case 0:
                    break;
                case 1:
                    w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2EC[i], 1);
                    break;
                case 3:
                    w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2EC[i], 2);
                    w->field_1E8[w->field_2DC++] = Anim_GetModelAnimFile(w->field_2EC[i], 0xA);
                    break;
                case 2:
                    w->field_260[w->field_2E0++] = Anim_GetModelAnimFile(w->field_2EC[i], 2);
                case 4:
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
        if (w->field_320 != 0) {
            w->field_1E8[w->field_2DC++] = 0xD2D;
            w->field_1E8[w->field_2DC++] = 0xD2B;
        }
        w->field_1E8[w->field_2DC++] = 0x1A1;
        w->field_1E8[w->field_2DC++] = 0x13B;
        w->field_1E8[w->field_2DC++] = 0x1A0;
        w->field_1E8[w->field_2DC++] = 0x22B;
        w->field_1E8[w->field_2DC++] = 0xCB9;
        Task_NextState1(a0);
        break;
    case 2:
        if (w->field_320 == 0) {
            if (Cd_GetFileState(func_8001EE5C(w->field_31C) >> 16) != 3) {
                break;
            }
            w->field_1E8[w->field_2DC++] = 0x1EF;
            for (q = (Stg30Part *)Cd_GetFileEntry(func_8001EE5C(w->field_31C)); q->fileId != 0; q++) {
                w->field_260[w->field_2E0++] = q->fileId >> 16;
            }
        }
        w->count = 0;
        for (i = 0; i < w->field_2DC; i++) {
            func_80063B80(a0, w->field_1E8[i], Cd_GetFileLba(w->field_1E8[i]));
        }
        for (i = 0; i < w->field_2E0; i++) {
            func_80063B80(a0, w->field_260[i], Cd_GetFileLba(w->field_260[i]));
        }
        Task_NextState1(a0);
        w->field_4 = 0;
        break;
    case 3:
        if (++w->field_4 < 300) {
            for (i = 0; i < w->count; i++) {
                Cd_QueueFile(w->files[i]);
                if (Cd_GetFileState(w->files[i]) != 3) {
                    return;
                }
            }
        }
        Task_NextState0(a0);
        break;
    }
}

void func_8006436C(Actor *a0) {
    Stg30Work73040 *w = (Stg30Work73040 *)a0->work;
    s32 i;

    for (i = 0; i < w->field_2E0; i++) {
        if (w->field_260[i] != 0) {
            Cd_FreeFile(w->field_260[i]);
        }
    }
}

void func_800643E0(s32 sel, s32 from, s32 to) {
    s32 i;
    TaskEntry *t;

    for (i = from; i <= to; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            if (sel == -1 || i == sel) {
                Task_SetState01((Actor *)t, 2, 8);
            } else {
                Task_SetState01((Actor *)t, 2, 7);
            }
        }
    }
}

void func_80064480(void) {
    s32 i;
    TaskEntry *t;

    for (i = 0; i < 3; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            Task_SetState01((Actor *)t, 2, 8);
        }
    }
}

void func_800644D4(Actor *a0) {
    Stg30WorkWord *w = (Stg30WorkWord *)a0->work;
    s32 *p = (s32 *)a0->u34.children;
    TaskEntry *t;
    s32 i;
    s32 n;
    s32 a;
    s32 b;
    s32 r;
    s32 j;

    switch (a0->stateLevel0) {
    case 0:
        D_80073CC4 = 0;
        Task_NextState0(a0);
        break;
    case 2:
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            switch (a0->stateLevel2) {
            case 0:
            default:
                func_80070D14(1);
                D_80073CC0.entries[0].field_8 = 6;
                Task_Create(0x504, p, 0);
                D_80073CC0.field_2AC[6].field_0 = 0;
                for (i = 0; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL) {
                        Task_SetState01((Actor *)t, 2, 9);
                    }
                }
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                switch (D_80073CC0.entries[0].field_10) {
                case 0:
                default:
                    Task_SetState1(a0, 2);
                    w->field_0 = func_8006E31C(0, 0, 0);
                    break;
                case 1:
                    Task_SetState1(a0, 1);
                    break;
                case 2:
                    if (D_80073CC0.field_3DC != 0) {
                        D_80073CC0.entries[0].field_4 = 2;
                    } else {
                        a = 0;
                        b = 0;
                        n = 0;
                        for (j = 0; j < 3; j++) {
                            if (D_80073CC0.entries[j].field_2E != 0) {
                                n++;
                                a += D_80073CC0.entries[j].field_38;
                            }
                        }
                        a /= n;
                        n = 0;
                        for (j = 3; j < 6; j++) {
                            if (D_80073CC0.entries[j].field_2E != 0) {
                                n++;
                                b += D_80073CC0.entries[j].field_38;
                            }
                        }
                        b /= n;
                        n = a * 100 / b;
                        if ((Rand_Next() & 0x7F) < n) {
                            D_80073CC4 = 1;
                        } else {
                            D_80073CC4 = 2;
                        }
                    }
                    Task_SetState0(a0, 3);
                    break;
                }
                break;
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                func_80070D14(8);
                Task_Create(0x506, p, 0);
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                if (D_80073CD4 != 0) {
                    Task_SetState1(a0, 0);
                } else {
                    Task_NextState2(a0);
                }
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    Task_Create(0x508, p, 0);
                    Task_NextState3(a0);
                    break;
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (D_80073CC0.entries[0].field_14 != 0) {
                        func_80064480();
                        D_80073CC0.field_2AC[6].field_0 = 0;
                        Task_SetState2(a0, 0);
                        break;
                    }
                    D_80073CC0.field_2AC[6].field_4 = D_80073CC0.entries[0].field_C;
                    w->field_0 = func_8006E31C(0, 0, 0);
                    Task_SetState1(a0, 2);
                    break;
                }
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                func_800643E0(w->field_0, 0, 2);
                ((void (*)(s32))func_80070D14)(w->field_0 + 2);
                D_80073CC8 = w->field_0;
                Task_Create(0x504, p, 0);
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                if (D_80073CC0.entries[0].field_14 != 0) {
                    if (w->field_0 != func_8006E31C(0, 0, 0)) {
                        r = func_8006E3D0(0, w->field_0, 0, 0);
                        w->field_0 = r;
                        D_80073CC0.field_2AC[r].field_0 = 0;
                        Task_SetState1(a0, 2);
                        break;
                    }
                    Task_SetState1(a0, 0);
                    break;
                }
                if (D_80073CC0.entries[0].field_10 == 0) {
                    Task_NextState2(a0);
                    break;
                }
                D_80073CC0.field_2AC[w->field_0].field_0 = 5;
                Task_SetState2(a0, 4);
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    ((void (*)(s32))func_80070D14)(w->field_0 + 2);
                    D_80073CC8 = w->field_0;
                    Task_Create(0x507, p, 0);
                    Task_NextState3(a0);
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (D_80073CD4 != 0) {
                        Task_SetState1(a0, 2);
                    } else {
                        Task_NextState2(a0);
                    }
                    break;
                }
                break;
            case 3:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    Task_Create(0x508, p, 0);
                    Task_NextState3(a0);
                    break;
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (D_80073CC0.entries[0].field_14 != 0) {
                        func_800643E0(w->field_0, 0, 2);
                        Task_SetState2(a0, 2);
                        break;
                    }
                    D_80073CC0.field_2AC[w->field_0].field_4 = D_80073CC0.entries[0].field_C;
                    Task_NextState2(a0);
                    break;
                }
                break;
            case 4:
                n = w->field_0;
                w->field_0 = func_8006E47C(0, n, 0, 0);
                if (w->field_0 == n) {
                    Task_NextState1(a0);
                } else {
                    Task_SetState1(a0, 2);
                }
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                for (n = 0; n < 6; n++) {
                    t = Task_FindFirst(0x509, -1, n);
                    if (t != NULL) {
                        Task_SetState01((Actor *)t, 2, 9);
                    }
                }
                func_80070D14(1);
                Task_NextState2(a0);
            case 1:
                Task_SetState0(a0, 3);
                break;
            }
            break;
        }
        break;
    }
}

void func_80064B30(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Halves pos;
    TextOpenArgs args;
    s32 i;
    s32 id;
    s32 y;
    s32 j;
    s32 k;

    switch (a0->stateLevel0) {
    case 0:
        D_800737E0 = 0;
        Mem_FillWordsNeg1(w->text, 4);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel2) {
        case 0:
        default:
            switch (a0->stateLevel3) {
            case 0:
            default:
                a0->elapsed = 0;
                Task_NextState3(a0);
                break;
            case 1:
                for (j = 0; j < a0->elapsed; j++) {
                    w->scale += 0x2AA;
                }
                a0->elapsed = 0;
                if (w->scale > 0x1000) {
                    w->scale = 0x1000;
                    Task_NextState2(a0);
                }
                break;
            }
            break;
        case 1:
            do {
                if (D_8005F6F0[0].up > 0) {
                    if (D_800737E0 == 0) break;
                    D_800737E0--;
                    Snd_PlayById(0xC, 0);
                    break;
                }
                if (D_8005F6F0[0].down > 0) {
                    if (D_80073CC0.entries[0].field_8 == 6) {
                        if (D_800737E0 == 2) break;
                        if (D_80073CC0.entries[0].field_0 != 0) break;
                        D_800737E0++;
                        Snd_PlayById(0xC, 0);
                        break;
                    }
                    if (D_800737E0 == 1) break;
                    D_800737E0++;
                    Snd_PlayById(0xC, 0);
                    break;
                }
                if (D_8005F6F0[0].cross > 0) {
                    D_80073CC0.entries[0].field_14 = 0;
                    D_80073CC0.entries[0].field_10 = D_800737E0;
                    Snd_PlayById(0xA, 0);
                    Task_NextState0(a0);
                    break;
                }
                if (D_80073CC0.entries[0].field_8 == 6) break;
                if (D_8005F6F0[0].triangle > 0) {
                    D_80073CC0.entries[0].field_14 = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                }
            } while (0);
            if (D_80073CC0.entries[0].field_8 == 6) {
                Text_OpenPacked(w->text, (s32)D_8005E634, 0x10, D_800633E8);
                for (k = 0, y = 0x3C; k < 3; y += 11, k++) {
                    if (D_80073CC0.entries[0].field_0 != 0 && k != 0) {
                        pos.lo = 0x16;
                        pos.hi = y;
                        Text_OpenById(&w->text[k + 1], k + 2, 3, pos);
                    } else if (D_800737E0 == k) {
                        pos.lo = 0x16;
                        pos.hi = y;
                        Text_OpenById(&w->text[k + 1], k + 2, 0, pos);
                    } else {
                        pos.lo = 0x16;
                        pos.hi = y;
                        Text_OpenById(&w->text[k + 1], k + 2, 1, pos);
                    }
                }
            } else {
                if (w->text[0] == -1) {
                    args.text = (s32)((Stg30StateDigis *)&D_80073CC0)->digis[D_80073CC0.entries[0].field_8].name;
                    args.color = 4;
                    args.x = 0x16;
                    args.bigFont = 0;
                    args.y = 0x30;
                    args.charDelay = 0;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    Text_Open(w->text, &args);
                }
                for (i = 0; i < 2; i++) {
                    pos.hi = i * 11 + 0x3C;
                    pos.lo = 0x16;
                    Text_OpenById(&w->text[i + 1], i + 5, D_800737E0 != i, pos);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->text, 4);
            a0->elapsed = 0;
            Task_NextState1(a0);
            break;
        case 1:
            for (j = 0; j < a0->elapsed; j++) {
                w->scale -= 0x2AA;
            }
            if (w->scale <= 0) {
                w->scale = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

void func_80064FBC(Actor *a0) {
    Text_CloseArray(((Stg30Work73078 *)a0->work)->text, 4);
    Task_DefaultDestroy(a0);
}

void func_80064FF4(Actor *a0) {
    Stg30Work73078 *w = (Stg30Work73078 *)a0->work;
    Stg30Part *p;
    Stg30Part *q;

    p = (Stg30Part *)Cd_GetFileEntry(0x1A10009);
    Gfx_SetPartsScale((GfxPartScaleView *)p, 0x1000, w->scale);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = -0x92;
            q->y = D_800737E0 * 11 - 0x33;
            while (1) {
                if (a0->elapsed < 0x18) break;
                a0->elapsed = a0->elapsed - 0x18;
            }
            q->palette = D_80073070[a0->elapsed / 4];
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}

void func_80065100(Actor *a0) {
    Stg30Work730D0 *w = (Stg30Work730D0 *)a0->work;
    s32 i;
    s32 n;
    s32 id;

    if (w->field_40[0] != 0 && w->field_4C[0] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&D_8005E620)->field_66[i];
            if (id == 0) {
                break;
            }
            switch (func_8001E0C0(id)) {
            case 0x14:
            case 0x1D:
            case 0x1E:
                w->field_58[0][n++] = id;
                break;
            }
        }
        w->field_E8[0] = n;
    } else {
        w->field_E8[0] = 0;
    }
    if (w->field_40[1] != 0 && w->field_4C[1] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&D_8005E620)->field_66[i];
            if (id == 0) {
                break;
            }
            if (func_8001E0C0(id) == 0x1A) {
                w->field_58[1][n++] = id;
            }
        }
        w->field_E8[1] = n;
    } else {
        w->field_E8[1] = 0;
    }
    if (w->field_40[2] != 0 && w->field_4C[2] == 0) {
        i = 0;
        n = i;
        for (; i < 0x30; i++) {
            id = ((Stg30GameIds *)&D_8005E620)->field_66[i];
            if (id == 0) {
                break;
            }
            if (func_8001E0C0(id) == 0x19) {
                w->field_58[2][n++] = id;
            }
        }
        w->field_E8[2] = n;
    } else {
        w->field_E8[2] = 0;
    }
}

void func_800652C8(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay) {
    TextOpenArgs args;

    if (name == 0) {
        args.text = Item_GetDescText(id);
    } else {
        args.text = Item_GetNameText(id);
    }
    args.bigFont = 0;
    args.color = color;
    args.x = pos.x;
    args.y = pos.y;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = delay;
    Text_Open(a0, &args);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065354);

s32 func_80065540(s32 c) {
    if (c >= 0xE1) {
        return c + 0x2E;
    }
    if (c >= 0xD9) {
        return c + 0x2E;
    }
    if (c >= 0xB0) {
        return c + 0x68;
    }
    if (c >= 0xA6) {
        return c + 0x7E;
    }
    return c + 0x85;
}

void func_80065584(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

void func_80065594(Actor *a0) {
    Stg30Work730D0 *w = (Stg30Work730D0 *)a0->work;
    Stg30GameFlags *g;
    s16 *row;
    s16 *top;
    s32 cat;
    s32 item;
    s32 id;
    s32 i;
    s32 c;
    s16 *pc;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(&w->field_4, 0xE);
        Text_OpenById(&w->field_4, 0x178, 0, D_800633F0);
        g = (Stg30GameFlags *)&D_8005E620;
        if (g->field_3C != 0) {
            w->field_40[0] = 1;
        }
        if (g->field_40 != 0) {
            w->field_40[1] = 1;
        }
        if (g->field_3E != 0) {
            w->field_40[2] = 1;
        }
        if (g->field_5A != 0) {
            w->field_4C[0] = 1;
        }
        if (g->field_5C != 0) {
            w->field_4C[1] = 1;
        }
        if (g->field_5B != 0) {
            w->field_4C[2] = 1;
        }
        D_800737E8 = 0;
        D_800737F0[0] = 0;
        D_800737F0[1] = 0;
        D_800737F0[2] = 0;
        D_800737F8[0] = 0;
        D_800737F8[1] = 0;
        D_800737F8[2] = 0;
        w->field_3C = 0;
        func_80065100(a0);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->field_3C += 0x555;
            if (w->field_3C >= 0x1000) {
                w->field_3C = 0x1000;
                Task_NextState1(a0);
            }
            break;
        case 1:
            cat = D_800737E8;
            row = &D_800737F0[cat];
            top = &D_800737F8[cat];
            pc = &D_800737E8;
            do {
                if (D_8005F6F0[0].left > 0) {
                    if (cat == 0) break;
                    D_800737E8--;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (D_8005F6F0[0].right > 0) {
                    if (cat == 2) break;
                    D_800737E8++;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (w->field_40[cat] != 0 && w->field_4C[cat] == 0) {
                    if (D_8005F6F0[0].repeat & 0x1000) {
                        if (*row != 0) {
                            *row -= 1;
                            Snd_PlayById(0xD, 0);
                            break;
                        }
                        if (*top == 0) break;
                        *top -= 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                    if (D_8005F6F0[0].repeat & 0x4000) {
                        if (*row != 2) {
                            *row += 1;
                            Snd_PlayById(0xD, 0);
                            break;
                        }
                        if (w->field_58[cat][*row + *top + 1] == 0) break;
                        *top += 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                }
                if (D_8005F6F0[0].triangle > 0) {
                    D_80073CD4 = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                    break;
                }
                if (D_8005F6F0[0].cross <= 0) break;
                item = w->field_58[D_800737E8][D_800737F0[D_800737E8] + D_800737F8[D_800737E8]];
                if (w->field_40[D_800737E8] == 0 || w->field_4C[D_800737E8] != 0 || item == 0) {
                    Snd_PlayById(0x10, 0);
                    break;
                }
                id = func_80065540(item);
                D_80073CC0.field_3AC = item;
                D_80073CC0.entries[0].field_14 = 0;
                D_80073CC0.field_3B2 = *pc;
                D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_0 = func_8001EE34(id) + 1;
                D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_6 = id;
                D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_8 = func_8006E2BC(id);
                D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_4 = func_8001EF3C(id);
                Snd_PlayById(0xE, 0);
                Task_NextState0(a0);
            } while (0);
            for (i = 0; i < 3; i++) {
                if (D_800737E8 == i) {
                    c = 4;
                } else {
                    c = 5;
                }
                Text_OpenById(&w->field_C[i], i + 7, c, D_8007309C[i]);
            }
            func_80065354(a0);
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(&w->field_4, 0xE);
            Task_NextState1(a0);
        case 1:
            w->field_3C -= 0x555;
            if (w->field_3C <= 0) {
                w->field_3C = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80065A98);

void func_80066000(void) {
    s32 cnt[4];
    s32 a[3];
    s32 b[3];
    Stg30IdSet *d;
    s32 i;
    s32 j;
    s32 id;
    s32 k;
    s32 cost;
    s32 flag;
    s32 m;

    d = (Stg30IdSet *)&((Stg30StateDigis *)&D_80073CC0)->digis[D_80073CC0.entries[0].field_8];
    for (i = 0; i < 4; i++) {
        cnt[i] = 0;
        D_80073820[i].field_D[13] = 0;
        for (j = 0; j < 12; j++) {
            D_80073820[i].field_D[j] = 0;
        }
    }
    for (i = 0; i < 12; i++) {
        j = d->ids[i];
        if (j != 0) {
            k = func_8001EE34(j);
            cost = func_8001EE80(j);
            D_80073820[k].field_D[cnt[k]] = j;
            D_80073820[k].field_0[cnt[k]] = (d->field_1A < cost) * 2;
            cnt[k]++;
        }
    }
    for (i = 0; i < 4; i++) {
        D_80073820[i].field_D[13] = cnt[i];
    }
    if (D_80073CC0.field_31C[D_80073CC0.entries[0].field_8] & 8) {
        b[1] = 0;
        b[0] = 0;
        a[1] = 0;
        a[0] = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < cnt[i]; j++) {
                id = D_80073820[i].field_D[j];
                m = func_8001EF64(id);
                cost = func_8001EE80(id);
                if (a[0] < m) {
                    a[0] = m;
                    a[1] = i;
                    a[2] = j;
                }
                if (b[0] < cost) {
                    b[0] = cost;
                    b[1] = i;
                    b[2] = j;
                }
            }
        }
        if (a[0] != 0) {
            D_80073820[a[1]].field_0[a[2]] = 2;
        }
        if (b[0] != 0) {
            D_80073820[b[1]].field_0[b[2]] = 2;
        }
    }
    flag = 0;
    for (i = 3; i < 6; i++) {
        if (D_80073CC0.entries[i].field_2E != 0 && !(D_80073CC0.field_31C[i] & 0x10000)) {
            flag = 1;
            break;
        }
    }
    if (!flag) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < cnt[i]; j++) {
                if (func_8001EF3C(D_80073820[i].field_D[j]) == 5) {
                    D_80073820[i].field_0[j] = 2;
                }
            }
        }
    }
}

void func_800663F8(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay) {
    TextOpenArgs args;

    if (name == 0) {
        args.text = func_8001EDD4(id);
    } else {
        args.text = func_8001ED84(id);
    }
    args.bigFont = 0;
    args.color = color;
    args.x = pos.x;
    args.y = pos.y;
    args.charAdvance = 0;
    args.lineAdvance = 0;
    args.charDelay = delay;
    Text_Open(a0, &args);
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80066484);

void func_80066698(Actor *a0) {
    Stg30Work73138 *w = (Stg30Work73138 *)a0->work;
    s16 *row;
    s16 *top;
    s32 cat;
    s32 c;
    s32 i;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 0x12);
        func_80066000();
        w->field_48 = -1;
        D_80073800 = 0;
        w->field_4C = 0;
        D_80073808[0] = 0;
        D_80073808[1] = 0;
        D_80073808[2] = 0;
        D_80073808[3] = 0;
        D_80073810[0] = 0;
        D_80073810[1] = 0;
        D_80073810[2] = 0;
        D_80073810[3] = 0;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->field_4C += 0x555;
            if (w->field_4C >= 0x1000) {
                w->field_4C = 0x1000;
                Task_NextState1(a0);
            }
            break;
        case 1:
            cat = D_80073800;
            row = &D_80073808[cat];
            top = &D_80073810[cat];
            do {
                if (D_8005F6F0[0].left > 0) {
                    if (cat == 0) break;
                    D_80073800--;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (D_8005F6F0[0].right > 0) {
                    if (cat == 3) break;
                    D_80073800++;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (D_8005F6F0[0].repeat & 0x1000) {
                    if (*row != 0) {
                        *row -= 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                    if (*top == 0) break;
                    *top -= 1;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (D_8005F6F0[0].repeat & 0x4000) {
                    if (*row != 2) {
                        *row += 1;
                        Snd_PlayById(0xD, 0);
                        break;
                    }
                    if (D_80073820[cat].field_D[*row + *top + 1] == 0) break;
                    *top += 1;
                    Snd_PlayById(0xD, 0);
                    break;
                }
                if (D_8005F6F0[0].cross > 0) {
                    if (D_80073820[cat].field_D[*row + *top] != 0 && D_80073820[cat].field_0[*row + *top] == 0) {
                        D_80073CC0.entries[0].field_14 = 0;
                        D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_0 = cat + 1;
                        D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_6 = D_80073820[cat].field_D[*row + *top];
                        D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_8 = func_8006E2BC(D_80073820[cat].field_D[*row + *top]);
                        Snd_PlayById(0xE, 0);
                        Task_NextState0(a0);
                        break;
                    }
                    Snd_PlayById(0x10, 0);
                    break;
                }
                if (D_8005F6F0[0].triangle > 0) {
                    D_80073CD4 = 1;
                    Snd_PlayById(0xB, 0);
                    Task_NextState0(a0);
                }
            } while (0);
            func_80066484(a0);
            Text_OpenById(w, 0x179, 4, D_800633F8);
            for (i = 0; i < 4; i++) {
                if (D_80073800 == i) {
                    c = 4;
                } else {
                    c = 5;
                }
                Text_OpenById(&w->texts[i + 1], i + 10, c, D_800730F8[i]);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            Text_CloseArray(w->texts, 0x12);
            Task_NextState1(a0);
        case 1:
            w->field_4C -= 0x555;
            if (w->field_4C <= 0) {
                w->field_4C = 0;
                Task_NextState0(a0);
            }
            break;
        }
        break;
    }
}

void func_80066AE0(Actor *a0) {
    Stg30Work73138 *w = (Stg30Work73138 *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;
    s32 bit;
    s32 i;
    s32 m2;
    GfxPart *p2;
    GfxPart *q2;

    while (1) {
        if (a0->elapsed < 0x18) break;
        a0->elapsed = a0->elapsed - 0x18;
    }
    if (w->field_4C == 0x1000) {
        p = (GfxPart *)Cd_GetFileEntry(0x1A1001A);
        m = 0;
        bit = 2;
        for (i = 0; i < 4; i++) {
            if (D_80073810[i] == 0) {
                m |= bit;
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            } else if (D_80073800 != i) {
                m |= bit;
                bit <<= 2;
            } else {
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            }
            if (D_80073820[i].field_D[0xD] < 4 || D_80073820[i].field_D[0xD] == D_80073810[i] + 3) {
                m |= bit;
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            } else if (D_80073800 != i) {
                m |= bit;
                bit <<= 2;
            } else {
                bit <<= 1;
                m |= bit;
                bit <<= 1;
            }
        }
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        m2 = ~m & D_80073108[D_80073800];
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & m2) {
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    p2 = (GfxPart *)Cd_GetFileEntry(0x1A10019);
    Gfx_SetPartsScale((GfxPartScaleView *)p2, 0x1000, w->field_4C);
    Gfx_SetPartsNumber(p2, 0x1000, 3, w->field_50);
    for (q2 = p2; q2->fileId != 0; q2++) {
        if (q2->groupMask & 0x4000) {
            q2->x = D_80073118[D_80073800].x;
            q2->y = D_80073118[D_80073800].y + D_80073808[D_80073800] * 11;
            q2->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
        }
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p2, D_80073128[D_80073800]);
    Gfx_DrawParts((EntA0 *)p2);
}

void func_80066DB0(Actor *a0) {
    Stg30Work73170 *w = (Stg30Work73170 *)a0->work;
    TaskEntry *t;
    s32 i;
    s32 old;
    s32 changed;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->field_18 = D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_6;
        w->field_8 = func_8001EF3C(w->field_18);
        w->field_14 = D_80073CC0.field_2AC[D_80073CC0.entries[0].field_8].field_8;
        switch (w->field_8) {
        case 0:
        case 3:
        case 4:
        case 7:
        default:
            v = D_80073CC8;
            w->field_4 = v;
            w->field_10 = v;
            w->field_C = v;
            break;
        case 1:
            w->field_C = 0;
            w->field_10 = 2;
            w->field_1C = 0;
            w->field_4 = func_8006E31C(0, 1, w->field_14);
            break;
        case 2:
            v = 7;
            w->field_4 = v;
            w->field_10 = v;
            w->field_C = v;
            break;
        case 5:
            w->field_C = 3;
            w->field_10 = 5;
            w->field_1C = 1;
            w->field_4 = func_8006E31C(1, 1, w->field_14);
            break;
        case 6:
            v = 8;
            w->field_4 = v;
            w->field_10 = v;
            w->field_C = v;
            break;
        case 8:
            v = 9;
            w->field_4 = v;
            w->field_10 = v;
            w->field_C = v;
            break;
        case 9:
            D_80073CC0.entries[0].field_C = 0;
            D_80073CC0.entries[0].field_14 = 0;
            Task_SetState0(a0, 3);
            return;
        }
        Task_NextState0(a0);
        break;
    case 1:
        changed = 0;
        do {
        if (w->field_8 == 1 || w->field_8 == 5) {
            if (D_8005F6F4 > 0) {
                old = w->field_4;
                if (w->field_1C != 0) {
                    w->field_4 = func_8006E3D0(w->field_1C, old, 1, w->field_14);
                } else {
                    w->field_4 = func_8006E47C(0, old, 1, w->field_14);
                }
                if (w->field_4 != old) {
                    changed = 1;
                    Snd_PlayById(0x12, 0);
                }
            }
            if (D_8005F6F0[0].right > 0) {
                old = w->field_4;
                if (w->field_1C != 0) {
                    w->field_4 = func_8006E47C(w->field_1C, old, 1, w->field_14);
                } else {
                    w->field_4 = func_8006E3D0(0, old, 1, w->field_14);
                }
                if (w->field_4 != old) {
                    changed = 1;
                    Snd_PlayById(0x12, 0);
                }
            }
        }
            if (D_8005F6F0[0].cross > 0) {
                D_80073CC0.entries[0].field_C = w->field_4;
                D_80073CC0.entries[0].field_14 = 0;
                Snd_PlayById(0xE, 0);
                Task_SetState0(a0, 3);
                break;
            }
            if (D_8005F6F0[0].triangle > 0) {
                D_80073CD4 = 1;
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 3);
            }
        } while (0);
        if (changed || w->field_0 == 0) {
            w->field_0 = 1;
            switch (w->field_8) {
            case 1:
            case 5:
                for (i = w->field_C; i <= w->field_10; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL) {
                        if (w->field_4 == i) {
                            Task_SetState01((Actor *)t, 2, 8);
                        } else {
                            Task_SetState01((Actor *)t, 2, 7);
                        }
                    }
                }
                break;
            case 2:
                for (i = 0; i < 3; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && D_80073CC0.entries[i].field_2E != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            case 6:
                for (i = 3; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && D_80073CC0.entries[i].field_2E != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            case 8:
                for (i = 0; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && D_80073CC0.entries[i].field_2E != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            }
        }
        switch (w->field_8) {
        case 1:
        case 5:
            ((void (*)(s32))func_80070D14)(w->field_4 + 2);
            break;
        case 2:
            func_80070D14(8);
            break;
        case 6:
            func_80070D14(9);
            break;
        case 8:
            func_80070D14(0x18);
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_800672B0(Actor *a0) {
    Stg30Work73170 *w = (Stg30Work73170 *)a0->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0x1A1000A);
    GfxPart *q;
    s32 m;

    switch (w->field_8) {
    case 0:
    case 1:
    case 5:
        Gfx_HidePartsByMask((GfxPartMaskView *)p, D_80073150[w->field_4]);
        break;
    case 2:
        m = D_8007316C;
        if (D_80073CC0.entries[2].field_2E == 0) m |= 8;
        if (D_80073CC0.entries[1].field_2E == 0) m |= 4;
        if (D_80073CC0.entries[0].field_2E == 0) m |= 2;
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    case 6:
        m = D_80073168;
        if (D_80073CC0.entries[5].field_2E == 0) m |= 0x40;
        if (D_80073CC0.entries[4].field_2E == 0) m |= 0x20;
        if (D_80073CC0.entries[3].field_2E == 0) m |= 0x10;
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    case 8:
        m = -0x7F;
        if (func_8001F0E4(w->field_18) & 0x2000) {
            if (D_80073CC0.entries[0].field_19 == 0) m = -0x7D;
            if (D_80073CC0.entries[1].field_19 == 0) m |= 4;
            if (D_80073CC0.entries[2].field_19 == 0) m |= 8;
            if (D_80073CC0.entries[3].field_19 == 0) m |= 0x10;
            if (D_80073CC0.entries[4].field_19 == 0) m |= 0x20;
            if (D_80073CC0.entries[5].field_19 == 0) m |= 0x40;
        } else {
            if (D_80073CC0.entries[0].field_2E == 0) m = -0x7D;
            if (D_80073CC0.entries[1].field_2E == 0) m |= 4;
            if (D_80073CC0.entries[2].field_2E == 0) m |= 8;
            if (D_80073CC0.entries[3].field_2E == 0) m |= 0x10;
            if (D_80073CC0.entries[4].field_2E == 0) m |= 0x20;
            if (D_80073CC0.entries[5].field_2E == 0) m |= 0x40;
        }
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    }
    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_PingPongRange(a0->elapsed, 8, 0, 3);
    }
    Gfx_DrawParts((EntA0 *)p);
}

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

void func_80068CE0(Actor *a0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (((Stg30StateDigis *)&D_80073CC0)->digis[i].state >= 3) {
            D_8005E620.elems[i] = ((Stg30StateDigis *)&D_80073CC0)->digis[i];
        }
    }
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(a0);
}

s32 func_80068DA4(s32 idx, s32 i, Stg30ByteLists *p) {
    s32 v = p->field_9[i];

    switch (v) {
    case 1:
    case 2:
    case 3:
        if (D_80073CC0.entries[idx].field_32 >= func_8001EE80(p->field_2[i])) {
            return 1;
        }
    case 4:
        return 1;
    default:
        return 0;
    }
}

s32 func_80068E34(s32 cond, s32 self) {
    s32 r;
    s32 i;
    s32 ret;

    r = Rand_Next() & 0xFFFF;
    switch (cond) {
    case 0:
        return 1;
    case 1:
        return !(r & 1);
    case 2:
        return (r & 3) == 0;
    case 3:
        return (r & 7) == 0;
    case 5:
        return D_80073E02 != 0;
    case 4:
        return D_80073E5E != 0;
    case 6:
        return D_80073EBA != 0;
    case 7:
        ret = 1;
        for (i = 3; i < 6; i++) {
            if (i != self && D_80073CC0.entries[i].field_2E != 0) {
                ret = 0;
            }
        }
        return ret;
    case 8:
        ret = 1;
        for (i = 3; i < 6; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E != D_80073CC0.entries[i].field_2C) {
                ret = 0;
            }
        }
        return ret;
    case 9:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E < (s16)(D_80073CC0.entries[i].field_2C / 10)) {
                ret = 1;
            }
        }
        return ret;
    case 10:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && (D_80073CC0.field_31C[i] & 7)) {
                ret = 1;
            }
        }
        return ret;
    case 11:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.field_340[i] != 0) {
                ret = 1;
            }
        }
        return ret;
    case 12:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                ret = 1;
            }
        }
        return ret;
    case 13:
        ret = 0;
        for (i = 0; i < 6; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                ret = 1;
            }
        }
        return ret;
    case 14:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.field_346[i] != 0) {
                ret = 1;
            }
        }
        return ret;
    case 15:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && func_8001D934(D_80073CC0.entries[i].field_19) == 0) {
                ret = 1;
            }
        }
        return ret;
    case 16:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && func_8001D934(D_80073CC0.entries[i].field_19) == 1) {
                ret = 1;
            }
        }
        return ret;
    case 17:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_19 != 0 && func_8001D934(D_80073CC0.entries[i].field_19) == 2) {
                ret = 1;
            }
        }
        return ret;
    }
    return 0;
}

s32 func_800692A4(s32 id, s32 kind, s32 def) {
    s32 i;
    s32 j;
    s32 min;
    s32 x;
    s16 v;

    switch (kind) {
    case 0:
        x = func_8001EF3C(id);
        if (x == 2) goto r8;
        if (x < 3) return def;
        if (x == 6) goto r7;
        if (x == 8) goto r9;
        return def;
    r8:
        return 8;
    r7:
        return 7;
    r9:
        return 9;
    case 1:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3) + 3;
            if (D_80073CC0.entries[x].field_2E != 0) {
                return x;
            }
        }
        return def;
    case 7:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3);
            if (D_80073CC0.entries[x].field_2E != 0) {
                return x;
            }
        }
        return def;
    case 3:
        return 3;
    case 2:
        return 4;
    case 4:
        return 5;
    case 5:
        j = def;
        min = 9999;
        for (i = 3; i < 6; i++) {
            v = D_80073CC0.entries[i].field_2E;
            if (v != 0 && v < min) {
                j = i;
                min = v;
            }
        }
        return j;
    case 8:
        j = 0;
        min = 9999;
        for (i = 0; i < 3; i++) {
            v = D_80073CC0.entries[i].field_2E;
            if (v != 0 && v < min) {
                j = i;
                min = v;
            }
        }
        return j;
    case 6:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3) + 3;
            if (D_80073CC0.entries[x].field_19 != 0 && D_80073CC0.entries[x].field_2E == 0) {
                return x;
            }
        }
        return x;
    }
    return def;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_80069594);

void func_800696E8(void) {
    s32 spd[6];
    s32 i;
    s32 n;
    s32 best;
    s32 bonus;
    s32 k;
    s32 slot;
    s32 slot2;
    s32 j;

    for (i = 0; i < 6; i++) {
        if (D_80073CC0.entries[i].field_2E != 0 && D_80073CC0.field_2AC[i].field_0 != 0) {
            bonus = 0;
            if (D_80073CC0.field_2AC[i].field_0 == 1 && (func_8001F020(D_80073CC0.field_2AC[i].field_6) & 8)) {
                bonus = D_80073CC0.entries[i].field_38;
            }
            spd[i] = D_80073CC0.entries[i].field_38 + bonus + (u16)((u16)Rand_Next() % 11);
        } else {
            spd[i] = 0;
        }
    }
    func_8006E530();
    for (i = 0; i < 6; ) {
        best = 0;
        n = 0;
        for (j = 0; j < 6; j++) {
            if (spd[j] != 0 && best < spd[j]) {
                best = spd[j];
                n = j;
            }
        }
        if (best == 0) {
            break;
        }
        i++;
        func_8006E55C(func_8006E634(), n);
        spd[n] = 0;
    }
    for (i = 0; i < 6; i++) {
        slot = func_8006E5F8(i);
        k = func_8006E674(slot);
        if (slot != -1) {
            switch (D_80073CC0.field_2AC[i].field_0) {
            case 2:
                func_8006E5B4(slot);
                func_8006E55C(func_8006E634(), i);
                break;
            case 3:
                func_8006E5B4(slot);
                break;
            case 5:
                func_8006E5B4(slot);
                func_8006E55C(0, k);
                break;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.field_2AC[i].field_6 != 0 &&
            (func_8001F020(D_80073CC0.field_2AC[i].field_6) & 0x20)) {
            slot2 = func_8006E5F8(i);
            if (slot2 != -1) {
                func_8006E5B4(slot2);
                func_8006E55C(func_8006E634(), i);
            }
        }
    }
    if (D_80073CC0.field_2AC[func_8006E674(0)].field_0 == 2) {
        D_80073CC0.field_2AC[func_8006E674(0)].field_0 = 1;
    }
}

s32 func_800699F8(s32 a, s32 b) {
    if (a == b) {
        return 0;
    }
    if (a == 0 && b == 1) {
        return 1;
    }
    if (a == 1 && b == 2) {
        return 1;
    }
    if (a == 2 && b == 0) {
        return 1;
    }
    return -1;
}

s32 func_80069A44(s32 idx) {
    u8 buf[12];
    s32 i;
    s32 n;
    s32 tech;
    s32 t;

    D_80073CC0.field_3B0 = 0;
    for (i = 0; D_800731B8[i] != 0; i++) {
        if ((D_80073CC0.field_31C[idx] & D_800731B8[i]) && (Rand_Next() & 3) == 0) {
            D_80073CC0.field_31C[idx] -= D_800731B8[i];
            D_80073CC0.field_3B0 = D_800731C8[i];
        }
    }
    for (i = 0; D_800731D0[i] != 0; i++) {
        if ((D_80073CC0.field_31C[idx] & D_800731D0[i]) && (u16)((u16)Rand_Next() % 3) == 0) {
            D_80073CC0.field_31C[idx] -= D_800731D0[i];
            D_80073CC0.field_3B0 = D_800731FC[i];
        }
    }
    if (D_80073CC0.field_31C[idx] & 4) {
        n = 0;
        for (i = 0; i < 12; i++) {
            if (D_80073CC0.entries[idx].field_3A[i] == 0) {
                break;
            }
            if (func_8001EE10(D_80073CC0.entries[idx].field_3A[i]) == 0) {
                buf[n++] = D_80073CC0.entries[idx].field_3A[i];
            }
        }
        if (n == 0) {
            D_80073CC0.field_2AC[idx].field_0 = 0;
            D_80073CC0.field_2AC[idx].field_4 = 0;
            D_80073CC0.field_2AC[idx].field_6 = 0;
            D_80073CC0.field_2AC[idx].field_8 = 0;
            return 0;
        }
        tech = buf[(u16)Rand_Next() % n];
        n = func_8001EF3C(tech);
        do {
            switch (n) {
            case 0:
            case 3:
            case 4:
            case 7:
            default:
                t = idx;
                break;
            case 1:
                if (idx < 3) {
                    t = (u16)((u16)Rand_Next() % 3);
                } else {
                    t = (u16)((u16)Rand_Next() % 3) + 3;
                }
                break;
            case 5:
                if (idx < 3) {
                    t = (u16)((u16)Rand_Next() % 3);
                } else {
                    t = (u16)((u16)Rand_Next() % 3) + 3;
                }
                break;
            case 2:
            case 6:
                if (idx < 3) {
                    t = 7;
                } else {
                    t = 8;
                }
                break;
            case 8:
                t = 9;
                break;
            }
        } while ((n == 1 || n == 5) && D_80073CC0.entries[t].field_2E == 0);
        D_80073CC0.field_2AC[idx].field_0 = 1;
        D_80073CC0.field_2AC[idx].field_6 = tech;
        D_80073CC0.field_2AC[idx].field_4 = t;
        D_80073CC0.field_2AC[idx].field_8 = func_8006E2BC(tech);
    }
    return 1;
}

void func_80069DE8(void) {
    s32 idx = func_8006E674(0);
    Stg30Rec73F6C *e = &D_80073F6C[idx];
    s32 fl = func_8001F044(e->field_6);
    s32 lo;
    s32 n;
    s32 i;
    s32 t;
    s32 cnt;
    s32 max;
    s32 best;
    s32 list[6];
    s32 k;

    if ((fl & 2) && e->field_0 != 2) {
        lo = 0;
        n = 3;
        switch (e->field_4) {
        case 3:
        case 4:
        case 5:
        case 8:
            lo = 3;
            break;
        case 9:
            n = 6;
            break;
        }
        for (i = 0; i < 100; i++) {
            t = (u16)Rand_Next() % n + lo;
            if (D_80073CC0.entries[t].field_2E != 0) {
                break;
            }
        }
        if (i == 100) {
            t = idx;
        }
        e->field_4 = t;
    }
    if ((fl & 4) && e->field_0 == 2) {
        e->field_4 = idx < 3 ? 8 : 7;
    }
    if (fl & 8) {
        best = idx;
        cnt = 0;
        for (k = 0; k < 6; k++) {
            if (D_80073CC0.entries[k].field_19 != 0 && D_80073CC0.entries[k].field_2E == 0) {
                list[cnt++] = k;
            }
        }
        max = 0;
        for (k = 0; k < cnt; k++) {
            if (max < D_80073CC0.entries[list[k]].field_32) {
                max = D_80073CC0.entries[list[k]].field_32;
                best = list[k];
            }
        }
        e->field_4 = best;
    }
}

s32 func_8006A030(s32 a, s32 b) {
    if (a == 5) {
        return 0;
    }
    if (b == 5) {
        return 0;
    }
    if (a == 0 && b == 1) {
        return 1;
    }
    if (a == 1 && b == 2) {
        return 1;
    }
    if (a == 2 && b == 3) {
        return 1;
    }
    if (a == 3 && b == 4) {
        return 1;
    }
    if (a == 4 && b == 0) {
        return 1;
    }
    if (a == 0 && b == 2) {
        return -1;
    }
    if (a == 1 && b == 3) {
        return -1;
    }
    if (a == 2 && b == 4) {
        return -1;
    }
    if (a == 3 && b == 0) {
        return -1;
    }
    if (a == 4 && b == 1) {
        return -1;
    }
    return 0;
}

s32 func_8006A118(void) {
    if (D_8005D5A0.field_103D == 0) {
        return 5;
    }
    return D_8005D5A0.field_103D - 2;
}

s32 func_8006A140(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5) {
    s32 revived;
    s32 flags;
    u32 already;
    s32 cure;
    s32 i;
    s32 old;
    s32 mask;
    s32 hit;

    revived = 0;
    flags = func_8001F068(tech);
    already = D_80073CC0.field_31C[target] & 1;
    if (flags & 1) {
        if ((u16)((u16)Rand_Next() % 3) == 0) {
            D_80073CC0.field_31C[target] |= 1;
        }
    }
    if (flags & 2) {
        if ((u16)((u16)Rand_Next() % 3) != 0) {
            D_80073CC0.field_31C[target] |= 1;
        }
    }
    if (flags & 4) {
        if (D_80073CC0.field_2AC[attacker].field_0 == 2) {
            D_80073CC0.field_31C[target] |= 1;
        }
    }
    if (!already) {
        if (D_80073CC0.field_31C[target] & 1) {
            *p5 = 1;
        }
    }
    already = (u32)D_80073CC0.field_31C[target] >> 1;
    already &= 1;
    if (flags & 0x10) {
        if ((u16)((u16)Rand_Next() % 3) == 0) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (flags & 0x20) {
        if ((u16)((u16)Rand_Next() % 3) != 0) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (flags & 0x40) {
        if (D_80073CC0.field_2AC[attacker].field_0 == 2) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (flags & 0x80) {
        if (D_80073CC0.field_2AC[attacker].field_0 == 3) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (!already) {
        if (D_80073CC0.field_31C[target] & 2) {
            *p5 = 3;
        }
    }
    if (D_80073CC0.field_3DC == 0 || target < 3) {
        already = (u32)D_80073CC0.field_31C[target] >> 2;
    already &= 1;
        if (flags & 0x100) {
            if ((u16)((u16)Rand_Next() % 3) == 0) {
                D_80073CC0.field_31C[target] |= 4;
            }
        }
        if (flags & 0x200) {
            if ((u16)((u16)Rand_Next() % 3) != 0) {
                D_80073CC0.field_31C[target] |= 4;
            }
        }
        if (flags & 0x400) {
            if (D_80073CC0.field_2AC[attacker].field_0 == 2) {
                D_80073CC0.field_31C[target] |= 4;
            }
        }
        if (!already) {
            if (D_80073CC0.field_31C[target] & 4) {
                *p5 = 5;
            }
        }
    }
    if (flags & 0x1000000) {
        if (D_80073CC0.entries[target].field_2E == 0) {
            D_80073CC0.field_31C[target] |= 0x8000;
            D_80073CC0.entries[target].field_2E = 1;
            D_80073CC0.field_34F[target] |= 0xA;
            *p4 = 3;
            *p5 = 0x119;
        }
    }
    if (flags & 0x1000) {
        D_80073CC0.field_31C[target] |= 8;
        *p5 = 0xC;
    }
    if (flags & 0x4000) {
        D_80073CC0.field_31C[target] |= 0x20;
    }
    if (flags & 0x8000) {
        D_80073CC0.field_31C[target] |= 0x40;
        *p5 = 0x10B;
    }
    if (flags & 0x10000) {
        D_80073CC0.field_31C[target] |= 0x80;
        *p5 = 0x1B;
    }
    if (flags & 0x20000) {
        D_80073CC0.field_31C[target] |= 0x800;
        *p5 = 0x103;
    }
    if (flags & 0x40000) {
        D_80073CC0.field_31C[target] |= 0x400;
        *p5 = 0x101;
    }
    if (flags & 0x80000) {
        D_80073CC0.field_31C[target] |= 0x100;
        *p5 = 0x1D;
    }
    if (flags & 0x100000) {
        D_80073CC0.field_31C[target] |= 0x200;
        *p5 = 0x1F;
    }
    if (flags & 0x200000) {
        D_80073CC0.field_31C[target] |= 0x1000;
        *p5 = 0x105;
    }
    if (flags & 0x400000) {
        D_80073CC0.field_31C[target] |= 0x2000;
        *p5 = 0x107;
    }
    if (flags & 0x800000) {
        D_80073CC0.field_31C[target] |= 0x4000;
        *p5 = 0x109;
    }
    if (flags & 0x2000000) {
        D_80073CC0.field_31C[target] |= 0x10000;
        *p5 = 0x10C;
    }
    if (!(D_80073CC0.field_34F[target] & 4)) {
        flags = func_8001F094(tech);
        if (flags & 0x20000) {
            revived = 1;
            D_80073CC0.entries[target].field_2E = D_80073CC0.entries[target].field_2C;
            *p4 = 3;
            *p5 = 0x18;
        }
        for (cure = 1, i = 0; i < 17; cure <<= 1, i++) {
            old = D_80073CC0.field_31C[target];
            mask = D_80073210[i];
            hit = old & mask;
            if (flags & cure) {
                D_80073CC0.field_31C[target] = old & ~mask;
                if (hit) {
                    *p5 = D_80073254[i];
                }
            }
        }
    }
    return revived;
}

void func_8006A968(s16 *max, s16 *b, s16 *c) {
    s16 half = *max / 2;

    *c = *c * 90 / 128;
    if (*c < half) {
        *c = half;
    }
    *b = *b * 90 / 128;
    if (*b < half) {
        *b = half;
    }
}

void func_8006AA18(s16 *max, s16 *b, s16 *c) {
    s16 lim;
    s16 t;

    t = *c + *c / 2;
    lim = *max * 2;
    *c = t;
    if (*c > lim) {
        *c = lim;
    }
    *b += *b / 2;
    if (*b > lim) {
        *b = lim;
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006AAA8);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006B950);

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006BBD8);

void func_8006CA3C(s32 idx) {
    s16 *p = D_80073890;

    *p++ = 2;
    *p++ = idx + 10;
    *p++ = 3;
    *p++ = idx;
    *p++ = 0xE;
    *p++ = 4;
    *p++ = 1;
    *p++ = 0;
    p[0] = 0x78;
    p[1] = 0x18;
    D_80073CC0.entries[idx].field_32 += D_80073CC0.entries[idx].field_30 / 10;
    if (D_80073CC0.entries[idx].field_30 < D_80073CC0.entries[idx].field_32) {
        D_80073CC0.entries[idx].field_32 = D_80073CC0.entries[idx].field_30;
    }
}

s32 func_8006CB28(s32 idx) {
    switch (D_80073CC0.field_2AC[idx].field_0) {
    case 1:
    case 2:
    case 3:
    case 4:
    default:
        func_8006BBD8(idx);
        return 1;
    case 5:
        func_8006CA3C(idx);
        return 1;
    }
}

void func_8006CB8C(Actor *a0) {
    Stg30WorkPc *w = (Stg30WorkPc *)a0->work;
    Stg30Slots *sl = (Stg30Slots *)a0->u34.children;
    s32 a[2];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];
    s32 f[3];
    s32 g[3];
    s32 h[1];
    TaskEntry *t;
    s32 *q;
    s32 cont;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->pc = D_80073890;
        Task_NextState0(a0);
        break;
    case 1:
        cont = 1;
        do {
            switch (*w->pc) {
            case 0:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    a0->elapsed = 0;
                    a0->stateLevel1++;
                case 1:
                    if (w->pc[1] < a0->elapsed) {
                        a0->stateLevel1 = 0;
                        w->pc += 2;
                    } else {
                        cont = 0;
                    }
                    break;
                }
                break;
            case 1:
                t = Task_FindFirst(0x509, -1, w->pc[1]);
                if (((Actor *)t)->stateLevel0 == 2) {
                    cont = 0;
                } else {
                    w->pc += 2;
                }
                break;
            case 2:
                ((void (*)(s32))func_80070D14)(w->pc[1]);
                cont = 0;
                w->pc += 2;
                break;
            case 3:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 == w->pc[1]) {
                        func_8006F640((Actor *)t, 1);
                        func_8006F664((Actor *)t);
                    } else {
                        func_8006F640((Actor *)t, 0);
                    }
                }
                w->pc += 2;
                break;
            case 4:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 < 3) {
                        func_8006F640((Actor *)t, 1);
                        func_8006F664((Actor *)t);
                    }
                }
                w->pc += 1;
                break;
            case 5:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 >= 3) {
                        func_8006F640((Actor *)t, 1);
                        func_8006F664((Actor *)t);
                    }
                }
                w->pc += 1;
                break;
            case 6:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    func_8006F640((Actor *)t, 1);
                    func_8006F664((Actor *)t);
                }
                w->pc += 1;
                break;
            case 7:
                t = Task_FindFirst(0x509, -1, w->pc[1]);
                Task_SetState0((Actor *)t, 2);
                Task_SetState1((Actor *)t, 0);
                w->pc += 2;
                break;
            case 9:
                if (w->pc[1] != 6) {
                    t = Task_FindFirst(0x509, -1, w->pc[1]);
                    Task_SetState0((Actor *)t, 2);
                    Task_SetState1((Actor *)t, 1);
                    Task_SetState4((Actor *)t, (u8)w->pc[2]);
                }
                w->pc += 3;
                break;
            case 10:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 3, w->pc[2]);
                w->pc += 3;
                break;
            case 11:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 4, w->pc[2]);
                w->pc += 3;
                break;
            case 12:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 5, w->pc[2]);
                if (w->pc[1] >= 3) {
                    D_80073CC0.field_3D8 = w->pc[1];
                }
                w->pc += 3;
                break;
            case 13:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 6, w->pc[2]);
                w->pc += 3;
                break;
            case 8:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 0xC, w->pc[2]);
                w->pc += 3;
                break;
            case 19:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    Task_Create(0x510, &sl->field_C, 0);
                    Task_NextState1(a0);
                case 1:
                    cont = 0;
                    if (sl->field_C == 0) {
                        w->pc += 1;
                        Task_SetState1(a0, 0);
                    }
                    break;
                }
                break;
            case 20:
                if (D_80073CC0.field_2AC[3].field_0 == 3) {
                    D_80073CC0.field_3D0 = 3;
                } else if (D_80073CC0.field_2AC[4].field_0 == 3) {
                    D_80073CC0.field_3D0 = 4;
                } else if (D_80073CC0.field_2AC[5].field_0 == 3) {
                    D_80073CC0.field_3D0 = 5;
                }
                w->pc += 1;
                break;
            case 14:
                a[0] = w->pc[1];
                a[1] = w->pc[2];
                Task_Create(0x50C, &sl->field_0, (s32)a);
                if (D_80073CC0.field_3B0 != 0) {
                    b[0] = 8;
                    b[2] = D_80073CC0.field_3B0;
                    Task_Create(0x50D, &sl->field_8, (s32)b);
                }
                w->pc += 3;
                break;
            case 15:
                c[0] = 0;
                c[1] = w->pc[1];
                c[2] = 0;
                Task_Create(0x50D, &sl->field_4, (s32)c);
                w->pc += 2;
                break;
            case 17:
                d[0] = w->pc[1] + 4;
                d[2] = 0;
                Task_Create(0x50D, &sl->field_0, (s32)d);
                w->pc += 2;
                break;
            case 18:
                e[0] = 7;
                e[2] = 0;
                Task_Create(0x50D, &sl->field_8, (s32)e);
                w->pc += 1;
                break;
            case 16:
                f[0] = w->pc[2];
                v = w->pc[1];
                if (v < 0) {
                    v = -v;
                }
                f[1] = v;
                f[2] = w->pc[3];
                Task_Create(0x50D, &sl->field_4, (s32)f);
                w->pc += 4;
                break;
            case 21:
                h[0] = (s32)D_80073890;
                Task_Create(0x50E, (s32 *)&sl->field_10, (s32)h);
                w->pc += 1;
                break;
            case 22:
                if (sl->field_10->stateLevel0 != 1) {
                    cont = 0;
                } else {
                    w->pc += 1;
                }
                break;
            case 23:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    q = func_8001EFF0(w->pc[1]);
                    g[0] = q[0];
                    g[1] = q[1];
                    g[2] = w->pc[2];
                    Task_Create(0x511, (s32 *)&sl->field_14, (s32)g);
                    Task_NextState1(a0);
                case 1:
                    if (sl->field_14->stateLevel0 != 1) {
                        cont = 0;
                        break;
                    }
                    Task_SetState0(sl->field_14, 2);
                    w->pc += 3;
                    Task_SetState1(a0, 0);
                    break;
                }
                break;
            case 24:
                Task_SetState0(a0, 3);
                cont = 0;
                break;
            }
        } while (cont);
        break;
    }
}

s32 func_8006D2EC(s32 idx, s32 id, s32 lvl) {
    s32 k = (lvl + 1) * 20;
    s32 pow = func_8001EF64(id);
    s32 el = func_8001EF88(id);
    s32 def = D_80073CC0.entries[idx].field_36;
    s32 el2 = func_8001D980(D_80073CC0.entries[idx].field_19);
    s32 r;

    if (D_80073CC0.field_2AC[idx].field_0 == 5) {
        def = def * 192 / 128;
    }
    switch (func_8006A030(el, el2)) {
    case 1:
        pow = pow * 154 / 128;
        break;
    case -1:
        pow = pow * 102 / 128;
        break;
    }
    if (el == func_8006A118()) {
        pow = pow * 154 / 128;
    }
    if (el2 != 5 && el2 == func_8006A118()) {
        def = def * 154 / 128;
    }
    r = k * pow / (def * 2);
    if (D_80073CC0.field_31C[idx] & 1) {
        r += 10;
    }
    return r;
}

s32 func_8006D4D8(s32 target, s32 tech, s16 *p3, s16 *p4) {
    Stg30DigiS *d = &D_80073CD8[target];
    s32 *st = &((Stg30CombatCD8 *)D_80073CD8)->status[target];
    s32 type = func_8001D934(d->digiId);
    s32 dmg;

    switch (tech) {
    case 0xFD:
    case 0x100:
    case 0x107:
    case 0x10A:
        dmg = 40;
        break;
    case 0xFE:
    case 0x101:
    case 0x108:
    case 0x10B:
        dmg = 80;
        break;
    case 0xFF:
    case 0x102:
    case 0x109:
    case 0x10C:
        dmg = 160;
        break;
    case 0x10F:
        if (type == 0) {
            dmg = d->maxHp - d->hp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x110:
        if (type == 0) {
            dmg = d->maxMp - d->mp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x112:
        if (type == 1) {
            dmg = d->maxHp - d->hp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x113:
        if (type == 1) {
            dmg = d->maxMp - d->mp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x115:
        if (type == 2) {
            dmg = d->maxHp - d->hp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x116:
        if (type == 2) {
            dmg = d->maxMp - d->mp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12A:
    case 0x12B:
    case 0x12C:
    case 0x12D:
        dmg = func_8006D2EC(target, tech, D_8005E65E - 0x60);
        break;
    default:
        dmg = 0;
        break;
    }
    switch (tech) {
    case 0xFD:
    case 0xFE:
    case 0xFF:
    case 0x107:
    case 0x108:
    case 0x109:
    case 0x10F:
    case 0x112:
    case 0x115:
        d->hp += dmg;
        if (d->maxHp < d->hp) {
            d->hp = d->maxHp;
        }
        break;
    case 0x100:
    case 0x101:
    case 0x102:
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x110:
    case 0x113:
    case 0x116:
        d->mp += dmg;
        if (d->maxMp < d->mp) {
            d->mp = d->maxMp;
        }
        break;
    case 0x103:
        *p3 = 4;
        *p4 = 2;
        *st &= ~1;
        break;
    case 0x104:
        *p3 = 4;
        *p4 = 4;
        *st &= ~2;
        break;
    case 0x105:
        *p3 = 4;
        *p4 = 6;
        *st &= ~4;
        break;
    case 0x106:
    case 0x10D:
        *p3 = 4;
        *p4 = 0x10F;
        *st = 0;
        break;
    case 0x10E:
        *p3 = 4;
        *p4 = 0x204;
        d->hp = d->maxHp;
        d->mp = d->maxMp;
        break;
    case 0x111:
        if (type == 0) {
            d->hp = d->maxHp;
            *p4 = 0x18;
        } else {
            *p3 = 4;
        }
        break;
    case 0x114:
        if (type == 1) {
            d->hp = d->maxHp;
            *p4 = 0x18;
        } else {
            *p3 = 4;
        }
        break;
    case 0x117:
        if (type == 2) {
            d->hp = d->maxHp;
            *p4 = 0x18;
        } else {
            *p3 = 4;
        }
        break;
    case 0x118:
        if (type == 0) {
            d->defense = d->defense * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x16;
        }
        *p3 = 4;
        break;
    case 0x119:
        if (type == 0) {
            d->defense = d->defense * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 0xA;
        }
        *p3 = 4;
        break;
    case 0x11A:
        if (type == 0) {
            d->attack = d->attack * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x15;
        }
        *p3 = 4;
        break;
    case 0x11B:
        if (type == 0) {
            d->attack = d->attack * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 9;
        }
        *p3 = 4;
        break;
    case 0x11C:
        if (type == 1) {
            d->defense = d->defense * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x16;
        }
        *p3 = 4;
        break;
    case 0x11D:
        if (type == 1) {
            d->defense = d->defense * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 0xA;
        }
        *p3 = 4;
        break;
    case 0x11E:
        if (type == 1) {
            d->attack = d->attack * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x15;
        }
        *p3 = 4;
        break;
    case 0x11F:
        if (type == 1) {
            d->attack = d->attack * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 9;
        }
        *p3 = 4;
        break;
    case 0x120:
        if (type == 2) {
            d->defense = d->defense * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x16;
        }
        *p3 = 4;
        break;
    case 0x121:
        if (type == 2) {
            d->defense = d->defense * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 0xA;
        }
        *p3 = 4;
        break;
    case 0x122:
        if (type == 2) {
            d->attack = d->attack * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x15;
        }
        *p3 = 4;
        break;
    case 0x123:
        if (type == 2) {
            d->attack = d->attack * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 9;
        }
        *p3 = 4;
        break;
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12A:
    case 0x12B:
    case 0x12C:
    case 0x12D:
        d->hp = (d->hp < dmg) ? 0 : d->hp - dmg;
        break;
    }
    return dmg;
}

void func_8006DB90(void) {
    s16 tgt[8];
    s32 res[6];
    s16 kind[8];
    s16 z[8];
    Stg30Sub10 *act;
    s16 *out;
    s32 i;
    s32 n;
    s32 mode;
    s32 cnt;
    s16 tech;

    act = &D_80073CC0.field_2AC[6];
    tech = act->field_6;
    mode = 1;
    out = D_80073890;
    for (i = 0; i < Item_GetBagCapacity(); i++) {
        if (((Stg30GameIds *)&D_8005E620)->field_66[i] == D_80073CC0.field_3AC) {
            ((Stg30GameIds *)&D_8005E620)->field_66[i] = 0;
            Item_SortList();
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        res[i] = 0;
        tgt[i] = -1;
        kind[i] = act->field_8;
        z[i] = 0;
    }
    switch (act->field_4) {
    default:
        tgt[0] = act->field_4;
        n = 1;
        break;
    case 7:
        switch (kind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            i = 0;
            cnt = 0;
            for (; i < 3; i++) {
                if (D_80073CC0.entries[i].field_2E != 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        case 3:
            i = 0;
            cnt = 0;
            for (; i < 3; i++) {
                if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        }
        mode = 0;
        break;
    case 8:
        switch (kind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            cnt = 0;
            for (i = 3; i < 6; i++) {
                if (D_80073CC0.entries[i].field_2E != 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        case 3:
            cnt = 0;
            for (i = 3; i < 6; i++) {
                if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        }
        mode = 1;
        break;
    case 9:
        switch (kind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            cnt = 0;
            for (i = 0; i < 6; i++) {
                if (D_80073CC0.entries[i].field_2E != 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        case 3:
            cnt = 0;
            for (i = 0; i < 6; i++) {
                if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        }
        mode = 2;
        break;
    }
    for (i = 0; i < n; i++) {
        kind[i] = act->field_8;
        res[i] = func_8006D4D8(tgt[i], tech, &kind[i], &z[i]);
    }
    *out++ = 2;
    *out++ = tgt[0] + 10;
    *out++ = 3;
    *out++ = tgt[0];
    *out++ = 9;
    *out++ = 6;
    *out++ = tech;
    *out++ = 0x15;
    *out++ = 0x16;
    *out++ = 0x11;
    *out++ = D_80073CC0.field_3B2;
    *out++ = 0x12;
    *out++ = 0x17;
    *out++ = tech;
    *out++ = n;
    *out++ = 0;
    *out++ = 0x96;
    for (i = 0; i < n; i++) {
        *out++ = 2;
        *out++ = tgt[i] + 0x10;
        *out++ = 3;
        *out++ = tgt[i];
        *out++ = 0;
        *out++ = (i == 0) ? 0x1E : 0xC;
        *out++ = 0x10;
        *out++ = res[i];
        *out++ = (kind[i] < 3) ? act->field_8 + 1 : 8;
        *out++ = z[i];
        switch (kind[i]) {
        case 0:
            if (D_80073CC0.entries[tgt[i]].field_2E != 0) {
                *out++ = (D_80073CC0.field_2AC[tgt[i]].field_0 != 5) ? 11 : 10;
            } else {
                *out++ = 0xC;
            }
            break;
        case 3:
            *out++ = 8;
            break;
        case 1:
        case 2:
        case 4:
            *out++ = 0xD;
            break;
        }
        *out++ = tgt[i];
        *out++ = tech;
        if (n == 1) {
            if (kind[i] == 0) {
                *out++ = n;
                *out++ = tgt[i];
                *out++ = 0;
                *out++ = 0x1E;
            } else if (kind[i] >= 0) {
                if (kind[i] < 5) {
                    *out++ = 0;
                    *out++ = 0x78;
                }
            }
        } else {
            *out++ = 0;
            *out++ = 0x3C;
        }
    }
    if (n != 1) {
        *out++ = 2;
        *out++ = mode + 0x16;
        *out++ = mode + 4;
        *out++ = 0;
        *out++ = 0xB4;
    }
    *out = 0x18;
    for (i = 0; i < 6; i++) {
        D_80073CC0.field_3B8[i] = tgt[i];
    }
}

s32 func_8006E2BC(s32 id) {
    s32 r = func_8001EF64(id);

    if (r > 0) {
        return 0;
    }
    if (r < 0) {
        return 1;
    }
    if (func_8001F094(id) & 0x20000) {
        return 3;
    }
    return 2;
}

s32 func_8006E31C(s32 team, s32 flag, s32 mode) {
    s32 i;
    s32 lo = team * 3;

    for (i = lo; i < lo + 3; i++) {
        if (D_80073CC0.entries[i].field_19 != 0 && (mode == 3 || D_80073CC0.entries[i].field_2E != 0)) {
            if (flag == 0 || !(D_80073CC0.field_31C[i] & 0x10000)) {
                return i;
            }
        }
    }
    return lo;
}

s32 func_8006E3D0(s32 team, s32 cur, s32 flag, s32 mode) {
    s32 i;
    s32 lo = team * 3;

    for (i = cur - 1; i >= lo; i--) {
        if (D_80073CC0.entries[i].field_19 != 0 && (mode == 3 || D_80073CC0.entries[i].field_2E != 0)) {
            if (flag == 0 || !(D_80073CC0.field_31C[i] & 0x10000)) {
                return i;
            }
        }
    }
    return cur;
}

s32 func_8006E47C(s32 team, s32 cur, s32 flag, s32 mode) {
    s32 i;

    for (i = cur + 1; i < team * 3 + 3; i++) {
        if (D_80073CC0.entries[i].field_19 != 0 && (mode == 3 || D_80073CC0.entries[i].field_2E != 0)) {
            if (flag == 0 || !(D_80073CC0.field_31C[i] & 0x10000)) {
                return i;
            }
        }
    }
    return cur;
}

void func_8006E530(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        D_80073A20[i] = v;
    }
}

void func_8006E55C(s32 idx, s32 v) {
    s32 i;

    for (i = 10; i >= idx; i--) {
        D_80073A20[i + 1] = D_80073A20[i];
    }
    D_80073A20[idx] = v;
}

void func_8006E5B4(s32 i) {
    for (; i < 11; i++) {
        D_80073A20[i] = D_80073A20[i + 1];
    }
}

s32 func_8006E5F8(s32 v) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (v == D_80073A20[i]) {
            return i;
        }
    }
    return -1;
}

s32 func_8006E634(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_80073A20[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 func_8006E674(s32 i) {
    return D_80073A20[i];
}

void func_8006E690(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_80073A50.digis[i] = ((Stg30StateDigis *)&D_80073CC0)->digis[i];
        D_80073A50.field_228[i] = D_80073CC0.field_31C[i];
        D_80073A50.field_240[i] = D_80073CC0.field_340[i];
        D_80073A50.field_246[i] = D_80073CC0.field_346[i];
        D_80073A50.field_24C[i] = D_80073CC0.field_356[i];
        D_80073A50.field_258[i] = D_80073CC0.field_362[i];
        D_80073A50.field_264[i] = D_80073CC0.field_36E[i];
    }
}

void func_8006E770(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ((Stg30StateDigis *)&D_80073CC0)->digis[i] = D_80073A50.digis[i];
        D_80073CC0.field_31C[i] = D_80073A50.field_228[i];
        D_80073CC0.field_340[i] = D_80073A50.field_240[i];
        D_80073CC0.field_346[i] = D_80073A50.field_246[i];
        D_80073CC0.field_356[i] = D_80073A50.field_24C[i];
        D_80073CC0.field_362[i] = D_80073A50.field_258[i];
        D_80073CC0.field_36E[i] = D_80073A50.field_264[i];
    }
}

void func_8006E850(Actor *a0, s32 anim) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;

    if (w->anim != anim) {
        w->anim = anim;
        Anim_SetModelAnim(a0, anim);
    }
}

void func_8006E888(Actor *a0, s32 *args) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    s32 idx = args[1];
    s32 n;

    a0->field_8 = idx;
    a0->digiId = D_80073CC0.entries[idx].field_19;
    w->field_14 = Digi_GetModelFile(a0->digiId);
    if (a0->field_8 < 3) {
        w->field_10 = 0x800;
    } else {
        w->field_10 = 0;
    }
    n = a0->field_8;
    w->field_8 = 0;
    w->field_4 = (n % 3) * 0xA00 - 0xA00;
    w->field_C = (n / 3) * 0x2800 - 0x1400;
    w->field_38 = args[2];
}

void func_8006E978(Actor *a0, s32 k) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    Stg30FxArgs args;
    s32 *slots;
    s16 a[4];
    s16 b[4];
    Row6 rows[4];
    Row6 *r;
    s32 i;

    slots = (s32 *)a0->u34.children;
    func_8001EEA4(w->field_2C, 0, a, b);
    func_8001E7E4(a0->digiId, rows);
    r = &rows[k];
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
                args.field_C += -0x280 - func_8001E79C(a0->digiId);
                break;
            case 1:
                args.field_C -= r->data[1];
                if (args.field_14 == 0) {
                    args.field_8 += r->data[0];
                    args.field_10 += -0x100 - r->data[2];
                } else {
                    args.field_8 -= r->data[0];
                    args.field_10 += 0x100 + r->data[2];
                }
                break;
            case 2:
                break;
            }
            Task_Create(7, &slots[i + 1], (s32)&args);
        }
    }
}

void func_8006EB24(Actor *a0) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    Stg30FxArgs args;
    s32 *slots;
    s16 a[4];
    s16 b[4];
    s32 i;

    slots = (s32 *)a0->u34.children;
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
                args.field_C += -0x280 - func_8001E79C(a0->digiId);
                break;
            case 1:
                args.field_C -= func_8001E7C0(a0->digiId);
                break;
            case 2:
                break;
            }
            Task_Create(7, &slots[i + 1], (s32)&args);
        }
    }
}

void func_8006EC5C(Actor *a0) {
    Snd_PlayById(func_8001E8D0(a0->digiId) == 0 ? 0x204 : 0x205, 0);
}

void func_8006EC94(Actor *arg0, s32 arg1) {
    Stg30Xform *t = (Stg30Xform *)arg0->u38.ptr38;

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
            Actor_SetAxisMotion(arg0, 2, &D_800732AC);
            if (!Anim_HasModelAnim(arg0, 0x14)) {
                Task_NextState3(arg0);
                break;
            }
            func_8006E850(arg0, 0x14);
            Actor_SetAxisMotion(arg0, 1, &D_80073294);
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
            func_8006EC5C(arg0);
            if (!Anim_HasModelAnim(arg0, 0x15)) {
                Task_NextState3(arg0);
                break;
            }
            func_8006E850(arg0, 0x15);
            Actor_SetAxisMotion(arg0, 1, &D_800732A0);
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
            func_8006EC5C(arg0);
            func_8006E850(arg0, 0x16);
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
            func_8006E850(arg0, 0x5A);
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
            func_8006E850(arg0, 0x64);
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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006EF50);

void func_8006F530(Actor *a0) {
    a0->childCount = 5;
    Task_DefaultDestroy(a0);
}

void func_8006F554(Actor *a0) {
    Stg30Work732B8 *w = (Stg30Work732B8 *)a0->work;
    CVECTOR c;

    if (w->field_28 != 0) {
        Gfx_AttachModel(a0, w->field_14);
        Anim_StepModelAnim(a0);
        Actor_UpdateTransform(a0);
        Gfx_CalcModelBoneMatrices(a0);
        if (w->field_18 != 0) {
            Gfx_DrawTexModel(a0, 0);
        }
        if (w->field_1C != 0) {
            if (a0->field_8 < 3) {
                c = w->color;
            } else {
                c.r = w->color.g;
                c.g = w->color.r;
                c.b = w->color.b;
            }
            Gfx_DrawWireModel(a0, 0, &c);
        }
    }
}

void func_8006F640(Actor *a0, s32 a1) {
    ((Stg30Work732B8 *)a0->work)->field_28 = a1;
    if (a1 != 0) {
        a0->childCount = 5;
    } else {
        a0->childCount = 4;
    }
}

void func_8006F664(Actor *a0) {
    ((Stg30Work732B8 *)a0->work)->field_30 = 2;
}

void func_8006F674(Stg30TaskHead *a0, s32 *args) {
    a0->field_8 = args[0];
    a0->field_4 = args[1] ? 2 : 4;
}

void func_8006F69C(Stg30TaskHead *a0) {
    Stg30Work732E8 *w = (Stg30Work732E8 *)a0->work;
    s32 snd;

    switch (a0->stateLevel0) {
    case 0:
        switch (a0->field_8) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        default:
            snd = 0x25;
            break;
        case 5:
            if (a0->field_4 == 2) {
                snd = 0x26;
            } else {
                snd = 0x1C;
            }
            break;
        }
        Snd_PlayById(snd, 0);
        Task_NextState0((Actor *)a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->field_4 != 7) {
                w->field_4++;
            }
            w->field_0 += 0x200;
            if (w->field_0 >= 0x1000) {
                w->field_0 = 0x1000;
                w->field_4 = 7;
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                a0->elapsed = 0;
                Task_NextState2((Actor *)a0);
                break;
            case 1:
                if (a0->elapsed >= 0x3C) {
                    Task_NextState0((Actor *)a0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        if (w->field_4 != 0) {
            w->field_4--;
        } else {
            Task_SetState0((Actor *)a0, 3);
        }
        break;
    }
}

void func_8006F820(Stg30TaskHead *a0) {
    Stg30Work732E8 *w = (Stg30Work732E8 *)a0->work;
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(D_800732D0[a0->field_8]);
    Stg30Part *q;
    s32 vis;

    for (q = p; q->fileId != 0; q++) {
        vis = q->groupMask == a0->field_4;
        q->field_E = 0;
        q->visible = vis;
        q->field_10 = w->field_0;
        q->palette = w->field_4;
    }
    Gfx_DrawParts((EntA0 *)p);
}

void func_8006F8CC(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void func_8006F8EC(Actor *a0) {
    Stg30WorkVec3 *w = (Stg30WorkVec3 *)a0->work;
    s32 t;

    switch (a0->stateLevel0) {
    case 0:
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->field_10++;
            w->field_C += 0x200;
            if (w->field_10 != 7) {
                break;
            }
            a0->elapsed = 0;
            w->field_C = 0x1000;
            Task_NextState1(a0);
        case 1:
            t = w->pos.x;
            if (t != 7) {
                if (a0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->field_10 = Math_CycleRange(a0->elapsed, 2, 8, 0xF);
                if (a0->elapsed < 0x90) {
                    break;
                }
                w->field_10 = t;
            }
            Task_NextState1(a0);
        case 2:
            if (--w->field_10 < 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_8006FA28(Actor *a0) {
    Stg30WorkVec3 *w = (Stg30WorkVec3 *)a0->work;
    Stg30Part *p = NULL;
    Stg30Part *q;
    s32 draw = 1;
    s32 id;

    switch (w->pos.x) {
    case 0:
    default:
        p = (Stg30Part *)Cd_GetFileEntry(func_8001EE5C(w->pos.y));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        p = (Stg30Part *)Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, D_80073300[w->pos.x - 4]);
        break;
    case 1:
    case 2:
    case 3:
        p = (Stg30Part *)Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber((GfxPart *)p, D_8007331C[w->pos.x - 1], 3, w->pos.y);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, D_80073310[w->pos.x - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (q = p; q->fileId != 0; q++) {
            if (w->field_C != 0x1000) {
                q->field_E = 0;
                q->field_10 = w->field_C;
            } else {
                q->field_E = 1;
            }
            q->palette = w->field_10;
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    if (w->pos.z != 0) {
        switch (w->pos.z >> 8) {
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
        p = (Stg30Part *)Cd_GetFileEntry(id);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, ~(1 << ((u8)w->pos.z - 1)));
        for (q = p; q->fileId != 0; q++) {
            if (w->field_C != 0x1000) {
                q->field_E = 0;
                q->field_10 = w->field_C;
            } else {
                q->field_E = 1;
            }
            q->palette = w->field_10;
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_8006FC78);

void func_8006FFD0(Actor *a0) {
    Stg30Work73358 *w = (Stg30Work73358 *)a0->work;
    Stg30Part *p;
    Stg30Part *q;
    s32 k;

    if (a0->stateLevel0 == 1 && a0->stateLevel1 == 0) {
        p = (Stg30Part *)Cd_GetFileEntry(0x1A10008);
        for (q = p; q->fileId != 0; q++) {
            q->field_10 = w->field_0;
            q->field_14 = w->field_2;
            q->palette = w->field_4;
            if (w->field_C == 0) {
                switch (q->groupMask) {
                case 0x10:
                    q->visible = 0;
                    break;
                case 4:
                    q->visible = ((u32)D_8005F770.frameCount >> 1) & 1;
                    break;
                case 8:
                    q->visible = (((u32)D_8005F770.frameCount >> 1) ^ 1) & 1;
                    break;
                default:
                    q->visible = 1;
                    break;
                }
            } else {
                switch (q->groupMask) {
                case 4:
                    q->visible = 0;
                    break;
                case 0x10:
                    q->visible = ((u32)D_8005F770.frameCount >> 1) & 1;
                    break;
                case 0x20:
                    q->visible = (((u32)D_8005F770.frameCount >> 1) ^ 1) & 1;
                    break;
                default:
                    q->visible = 1;
                    break;
                }
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    if (D_80073CC0.field_3D4 != 0) {
        p = (Stg30Part *)Cd_GetFileEntry(0x1A1000B);
        k = w->field_10;
        if (D_80073CC0.field_2AC[k].field_0 != 3) {
            k += 3;
        }
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & D_80073340[k]) {
                q->visible = 1;
                q->palette = w->field_8;
            } else {
                q->visible = 0;
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}

void func_800701FC(void) {
    Mem_Zero(&D_80073CC0, 0x3E0);
    D_80073CC0.field_3D4 = 1;
    if ((D_8005F770.prevGameMode & 0xFF00) == 0x300) {
        D_8005D5A0.field_103D = 0;
        D_8005D5A0.field_1040 = 0;
        D_80073CC0.entries[0].field_0 = 1;
    }
    if (D_8005F770.field_24 == 0x97 && Flag_Test(0x88)) {
        D_8005F770.field_24++;
    }
    D_80074098 = 4;
}

void func_800702A8(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void func_800702C8(Stg30TaskHead *a0) {
    Stg30Work733F0 *w = (Stg30Work733F0 *)a0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];
    s32 lba;
    s32 r;

    switch (a0->stateLevel0) {
    case 0:
    default:
        switch (a0->stateLevel1) {
        case 0:
        default:
            lba = Cd_GetFileLba(w->file) + D_800733C0[w->track - 1];
            w->field_C = lba;
            w->field_10 = lba + D_800733D8[w->track - 1];
            param[0] = 1;
            param[1] = w->channel;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->field_C, loc);
            CdControlF(0x15, loc);
            Task_NextState1((Actor *)a0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0((Actor *)a0, 0);
                break;
            case 2:
                Task_NextState0((Actor *)a0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->field_C, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            if (a0->field_24 & 0x1F) {
                break;
            }
            switch (CdSync(1, res2)) {
            case 5:
                Task_SetState0((Actor *)a0, 3);
                break;
            case 2:
                if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->field_10) {
                    Task_SetState0((Actor *)a0, 3);
                } else {
                    CdControlF(0x11, 0);
                }
                break;
            }
            break;
        }
        break;
    }
}

void func_800704FC(Actor *a0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a0);
}

s32 func_80070530(s32 a, s32 b) {
    s32 neg = 0;
    s32 r;
    a -= b;
    if (a == 0) {
        return neg;
    }
    if (a < 0) {
        neg = 1;
        a = -a;
    }
    r = a / 16;
    if (r == 0) {
        r = 1;
    }
    if (neg) {
        r = -r;
    }
    return r;
}

void func_80070588(Stg30Work7343C *w, Stg30CamGoal *g) {
    s32 i;

    for (i = 0; i < D_8005F770.frameDelta; i++) {
        w->field_7E += func_80070530(g->field_0, w->field_7E);
        w->field_0 += func_80070530(g->field_4, w->field_0);
        w->field_4 += func_80070530(g->field_8, w->field_4);
        w->field_8 += func_80070530(g->field_C, w->field_8);
        w->field_10 += func_80070530(g->field_10, w->field_10);
        w->field_6C += func_80070530(g->field_14, w->field_6C);
        w->field_74 += func_80070530(g->field_18, w->field_74);
    }
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800706BC);

void func_80070C68(Actor *a0) {
    Stg30Work7343C *w = (Stg30Work7343C *)a0->work;
    Stg30RefView rv;

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

void func_80070D14(u8 state) {
    Actor *t = (Actor *)Task_FindFirst(0x503, -1, -1);

    if (t != NULL && t->stateLevel0 == 1) {
        Task_SetState1(t, state);
    }
}

void func_80070D68(Actor *a0, Stg30Ref **args) {
    ((Stg30Work734F8 *)a0->work)->ref = args[0];
    a0->field_8 = args[0]->field_8;
}

void func_80070D8C(Stg30TaskHead *a0) {
    Stg30Work734F8 *w = (Stg30Work734F8 *)a0->work;
    TextOpenArgs args;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->field_8 = 12;
        Mem_FillWordsNeg1(w->text, 2);
        Task_NextState0((Actor *)a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (a0->field_24 > D_80073454[a0->field_8] && w->field_4 != 0x1000) {
                w->field_4 += 0x100;
            }
            if (w->field_4 == 0x1000) {
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            args.text = (s32)D_80073D24[a0->field_8].name;
            args.bigFont = 0;
            args.color = 0;
            args.x = D_8007346C[a0->field_8].x;
            args.y = D_8007346C[a0->field_8].y;
            args.charDelay = 8;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            Text_Open(&w->text[0], &args);
            Task_NextState1((Actor *)a0);
            break;
        case 2:
            v = D_80073CC0.field_2AC[a0->field_8].field_0;
            if (v != 0) {
                if (w->field_8 != 0) {
                    w->field_8 -= 4;
                } else {
                    Text_OpenById(&w->text[1], D_80073484[v - 1], 0, D_8007348C[a0->field_8]);
                }
            } else if (w->field_8 != 12) {
                w->field_8 += 4;
                Text_Close(&w->text[1]);
            }
            break;
        }
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_CloseArray(w->text, 2);
                Task_NextState2((Actor *)a0);
                break;
            case 1:
                break;
            }
            break;
        case 1:
            Task_SetState01((Actor *)a0, 1, 1);
            break;
        }
        break;
    }
}

void func_8007100C(Actor *a0) {
    Text_CloseArray(((Stg30Work734F8 *)a0->work)->text, 2);
    Task_DefaultDestroy(a0);
}

void func_80071044(Stg30Part *p, s32 unit, s32 num, s32 den) {
    s32 lv[4];
    s32 masks[4];
    s32 n;
    s32 i;

    if (num != 0) {
        n = num * 40 / den;
        if (n == 0) {
            n = 1;
        }
    } else {
        n = 0;
    }
    masks[0] = unit;
    masks[1] = unit * 2;
    masks[2] = unit * 4;
    masks[3] = unit * 8;
    if (n < 10) {
        lv[0] = 10 - n;
        lv[1] = 10;
        lv[2] = 10;
        lv[3] = 10;
    } else if (n < 20) {
        lv[0] = 0;
        lv[1] = 20 - n;
        lv[2] = 10;
        lv[3] = 10;
    } else if (n < 30) {
        lv[0] = 0;
        lv[1] = 0;
        lv[2] = 30 - n;
        lv[3] = 10;
    } else {
        lv[0] = 0;
        lv[1] = 0;
        lv[2] = 0;
        lv[3] = 40 - n;
    }
    for (; p->fileId != 0; p++) {
        for (i = 0; i < 4; i++) {
            if (p->groupMask == masks[i]) {
                p->palette = lv[3 - i];
            }
        }
    }
}

void func_8007118C(Actor *a0) {
    Stg30Work734F8 *w = (Stg30Work734F8 *)a0->work;
    Stg30Part *p;
    Stg30Part *q;
    Stg30DigiS *d;
    s32 off;
    s32 j;
    s32 m;
    s32 k;
    s32 t;

    if (a0->stateLevel0 != 2) {
        p = (Stg30Part *)Cd_GetFileEntry(D_80073498[a0->field_8]);
        off = 0;
        for (q = p; q->fileId != 0; q++) {
            j = 0;
            m = q->groupMask;
            for (; j < 6; j++) {
                if (m & D_800734B0[j]) {
                    if (D_80073CC0.field_31C[a0->field_8] & D_800734C8[j]) {
                        q->x = D_800734E0[a0->field_8].x + off;
                        off += 10;
                        q->y = D_800734E0[a0->field_8].y;
                        q->visible = 1;
                    } else {
                        q->visible = 0;
                    }
                }
            }
        }
        for (q = p; q->fileId != 0; q++) {
            t = w->field_4;
            if (t != 0x1000) {
                q->field_E = 0;
                q->field_14 = w->field_4;
            } else {
                q->field_E = 1;
                q->field_14 = t;
            }
            if (q->groupMask & 1) {
                if (w->field_8 == 12) {
                    q->visible = 0;
                } else {
                    q->visible = 1;
                    q->y = w->field_8 + 0x55;
                }
            }
        }
        k = a0->field_8;
        if (k < 3) {
            Gfx_SetPartsNumber((GfxPart *)p, 0x20, 3, D_80073CD8[k].maxHp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x40, 3, D_80073CD8[k].hp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x80, 3, D_80073CD8[k].maxMp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x100, 3, D_80073CD8[k].mp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x200, 2, D_80073CD8[k].level);
        }
        d = &D_80073CD8[a0->field_8];
        if (a0->field_8 < 3) {
            func_80071044(p, 0x400, d->hp, d->maxHp);
            func_80071044(p, 0x4000, d->mp, d->maxMp);
        } else {
            func_80071044(p, 0x20, d->hp, d->maxHp);
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}

void func_80071470(Actor *a0, Stg30Pair *args) {
    ((Stg30Work73718 *)a0->work)->pair = *args;
}

u8 *func_80071488(u8 *out, s32 n) {
    u8 buf[8];
    s32 i;
    s32 lead;
    s32 k;

    for (i = 7; i != -1; i--) {
        buf[i] = n % 10;
        n /= 10;
    }
    lead = 1;
    k = 0;
    for (i = 0; i < 8; i++) {
        if (!lead || buf[i] != 0) {
            out[k++] = buf[i];
            lead = 0;
        }
    }
    out[k] = 0xFF;
    return out;
}

void func_80071538(DigiRosterEntry *e) {
    u16 *p;
    s32 r;
    s32 c;
    s32 lv;
    s32 k;
    u16 t;

    e->level = e->level + 1;
    lv = e->level;
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            p = &e->maxHp;
        } else {
            p = &e->maxMp;
        }
        r = Rand_Next() & 3;
        c = func_8001D9CC(e->digiId, k);
        if (lv < 12) {
            *p += D_80073510[0][c][r] + 10;
        } else if (lv < 22) {
            *p += D_80073510[1][c][r] + 6;
        } else if (lv < 32) {
            *p += D_80073510[2][c][r] + 4;
        } else if (lv < 42) {
            *p += D_80073510[3][c][r] + 2;
        } else if (lv < 52) {
            *p = *p + D_80073510[4][c][r];
        } else {
            *p = *p + D_80073510[5][c][r];
        }
        t = *p;
        if ((s16)*p >= 1000) {
            t = 999;
        }
        *p = t;
    }
    k = 1;
    lv = e->level - (func_8001D958(e->digiId) * 10 + k);
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            p = (u16 *)&e->field_1C;
        } else {
            p = &e->field_1E;
        }
        r = Rand_Next() & 3;
        c = func_8001D9CC(e->digiId, k + 2);
        if (lv == 1) {
            *p += D_800735A0[0][c][r] + 4;
        } else if (lv < 4) {
            *p += D_800735A0[1][c][r] + 3;
        } else if (lv < 7) {
            *p += D_800735A0[2][c][r] + 2;
        } else if (lv < 11) {
            *p += D_800735A0[3][c][r] + 1;
        } else {
            *p = *p + D_800735A0[4][c][r];
        }
        t = *p;
        if ((s16)*p >= 1000) {
            t = 999;
        }
        *p = t;
    }
    lv = e->field_20;
    p = (u16 *)&e->field_20;
    r = Rand_Next() & 3;
    c = func_8001D9CC(e->digiId, 4);
    if (lv < 21) {
        *p += D_80073618[0][c][r] + 3;
    } else if (lv < 51) {
        *p += D_80073618[1][c][r] + 2;
    } else if (lv < 101) {
        *p += D_80073618[2][c][r] + 1;
    } else {
        *p = *p + D_80073618[3][c][r];
    }
    t = *p;
    if ((s16)*p >= 1000) {
        t = 999;
    }
    *p = t;
    e->hp = e->maxHp;
    e->mp = e->maxMp;
}

void func_8007191C(Actor *a0) {
    Stg30Work73718 *w = (Stg30Work73718 *)a0->work;
    Stg30TextArgs args;
    Stg30TextRec *r;
    s32 i;
    s32 j;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->text, 14);
        for (i = 0; i < 3; i++) {
            if (D_80073CC0.entries[i].field_2E != 0) {
                D_80073CC0.entries[i].field_28 += w->pair.field_0;
            }
            w->field_18[i] = Digi_GetExpToNextLevel(D_80073CC0.entries[i].field_25, D_80073CC0.entries[i].field_27,
                                                   D_80073CC0.entries[i].field_28);
            if (w->field_18[i] == 0 && D_80073CC0.entries[i].field_2E != 0) {
                D_80073CC0.field_34C[i] = 1;
                func_80071538(&((Stg30StateDigis *)&D_80073CC0)->digis[i]);
            } else {
                D_80073CC0.field_34C[i] = 0;
            }
        }
        D_8005E620.field_8 += w->pair.field_4;
        if (D_8005E620.field_8 > 99999999) {
            D_8005E620.field_8 = 99999999;
        }
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            for (j = 0; j < 14; j++) {
                r = &D_80073690[j];
                if (r->slot == 9 || D_80073CC0.entries[r->slot].field_19 != 0) {
                    if (r->src < 3) {
                        args.text = (s32)D_80073D24[r->src].name;
                    } else {
                        args.text = (s32)Cd_GetFileEntry(r->src | 0x1FD0000);
                    }
                    if (j == 7) {
                        args.strArg0 = (s32)func_80071488(w->buf0, w->pair.field_0);
                    }
                    if (j == 13) {
                        args.strArg0 = (s32)func_80071488(w->buf1, w->pair.field_4);
                    }
                    args.bigFont = r->bigFont;
                    args.color = r->color;
                    args.pos = r->pos;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    args.charDelay = 0;
                    Text_Open(&w->text[j], (TextOpenArgs *)&args);
                }
            }
            Task_NextState1(a0);
        case 1:
            if (D_8005F704 > 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void func_80071BDC(Actor *a0) {
    Text_CloseArray(((Stg30Work73718 *)a0->work)->text, 14);
    Task_DefaultDestroy(a0);
}

void func_80071C14(Actor *a0) {
    Stg30Work73718 *w = (Stg30Work73718 *)a0->work;
    GfxPart *p;
    s32 i;
    s32 draw;

    for (i = 0; i < 6; i++) {
        draw = 1;
        p = (GfxPart *)Cd_GetFileEntry(D_80073700[i]);
        switch (i) {
        case 0:
        case 1:
        case 2:
            if (D_80073CC0.entries[i].field_19 == 0) {
                draw = 0;
                break;
            }
            if (D_80073CC0.field_34C[i] != 0) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0x10);
            }
            Gfx_SetPartsNumber(p, 1, 8, D_80073CC0.entries[i].field_28);
            Gfx_SetPartsNumber(p, 4, 8, w->field_18[i]);
            Gfx_SetPartsNumber(p, 8, 2, D_80073CC0.entries[i].field_25);
            break;
        case 4:
            Gfx_SetPartsNumber(p, 1, 8, D_8005E620.field_8);
            break;
        }
        if (draw) {
            Gfx_DrawParts((EntA0 *)p);
        }
    }
}

void func_80071D70(Actor *a0, Stg30Init737A0 *args) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;

    w->field_0 = args->field_0;
    for (i = 0; i < 12; i++) {
        w->field_74[0][i] = args->field_4[i];
    }
    Snd_PlayById(0x2B, 0);
}

void func_80071DC4(Actor *a0) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 row;
    s32 col;
    s32 k;
    s32 *slot;
    s32 item;
    s32 id;
    s32 scroll;

    for (row = 0; row < 2; row++) {
        scroll = w->field_B0[row];
        for (col = 0; col < 10; col++) {
            k = row * 10 + col;
            slot = &w->texts[k];
            Text_Close(slot);
            item = w->field_74[row][col + scroll];
            if (item != 0) {
                Text_OpenPacked(slot, func_8001ED84(item), 0, D_80073730[k + 4]);
            }
        }
    }
    Text_Close(&w->field_70);
    id = w->field_74[w->field_A4][w->field_B0[w->field_A4] + w->field_A8[w->field_A4]];
    if (id != 0 && w->field_C8 == 0) {
        Text_OpenPacked(&w->field_70, func_8001EDD4(id), 0, D_80073730[27]);
        w->field_C0 = func_8001EE80(id);
    } else {
        w->field_C0 = 0;
    }
}

void func_80071F9C(Actor *a0) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Text_Close(&w->text[i]);
        if (w->field_C8 == 0 || w->field_C4 != i || !(a0->elapsed & 0x10)) {
            s32 c;
            if (w->field_C4 == i) c = 4; else c = 5;
            Text_OpenById(&w->text[i], i + 0x188, c, D_80073730[i + 24]);
        }
    }
}

void func_80072080(Actor *a0, s32 row) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    s32 i;
    s32 n;

    i = 0;
    n = i;
    for (; i < 12; i++) {
        if (w->field_74[row][i] != 0) {
            w->field_74[row][n] = w->field_74[row][i];
            if (i != n) {
                w->field_74[row][i] = 0;
            }
            n++;
        }
    }
    w->field_B8[row] = n;
}

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000", func_800720E4);

void func_800726E8(Actor *a0) {
    Stg30Work737A0 *w = (Stg30Work737A0 *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;

    p = (GfxPart *)Cd_GetFileEntry(0x1A1001B);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001C);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001D);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 0x4000) {
            if (w->field_C8 != 0) {
                q->visible = 0;
            } else {
                q->visible = 1;
                q->x = w->field_A4 != 0 ? 3 : -0x85;
                q->y = w->field_A8[w->field_A4] * 11 - 0x15;
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
    }
    Gfx_SetPartsNumber(p, 0x800, 3, w->field_C0);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001E);
    m = (w->field_B0[0] == 0) << 1;
    if (w->field_B0[0] + 10 >= w->field_B8[0]) {
        m |= 8;
    }
    if (w->field_B0[1] == 0) {
        m |= 0x20;
    }
    if (w->field_B0[1] + 10 >= w->field_B8[1]) {
        m |= 0x80;
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
    Gfx_DrawParts((EntA0 *)p);
}

void func_800728A0(Actor *a0, s32 *args) {
    s32 idx = args[0];

    ((Stg30Work737C8 *)a0->work)->index = idx;
    a0->digiId = D_80073CC0.entries[idx].field_19;
}

void func_800728D8(Actor *a0, s32 a1) {
    DigiRosterEntry *e = &D_8005F398;

    Digi_InitFromTable(D_8005F794, ((Stg30WorkWord *)a0->work)->field_0 - 3, e);
    if (a1 != 0) {
        e->state = 1;
    }
}

void func_8007292C(Actor *a0) {
    Stg30Work737C8 *w = (Stg30Work737C8 *)a0->work;
    Stg30GameRoster *g;
    TaskEntry *t;
    Stg30Pair args;
    s32 i;
    s32 cnt;
    s32 n;
    s32 j;
    s32 *p;

    p = (s32 *)a0->u34.children;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->text, 2);
        w->field_C = (Actor *)Task_FindFirst(0x509, -1, w->index);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            ((void (*)(s32))func_80070D14)(w->index + 2);
            func_8006F640(w->field_C, 1);
            a0->elapsed = 0;
            Task_NextState1(a0);
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                if (a0->elapsed < 0x15) {
                    break;
                }
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 < 3) {
                        func_8006F640((Actor *)t, 0);
                        func_8006F664((Actor *)t);
                    }
                }
                Task_NextState2(a0);
                break;
            case 1:
                if (a0->elapsed < 0x78) {
                    break;
                }
                Task_SetState0(w->field_C, 2);
                Task_SetState1(w->field_C, 0xB);
                Task_NextState1(a0);
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                w->field_10 = 1;
                Text_OpenPacked(&w->text[0], (s32)Digi_GetDefaultName(a0->digiId), 0, D_800737B8[0]);
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018D), 0x81, D_800737B8[1]);
                Flag_Set(0x10, 0);
                Task_NextState2(a0);
                break;
            case 1:
                if (!Flag_Test(0x10)) {
                    break;
                }
                if (Flag_Test(0x11)) {
                    Task_SetState1(a0, 8);
                    break;
                }
                Task_SetState1(a0, 3);
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                cnt = 0;
                for (j = 0; j < 0x24; j++) {
                    if (D_8005E620.elems[j].state >= 2) {
                        cnt++;
                    }
                }
                n = D_800737C0[D_8005E650 - 0x2F] - D_8005071C->field_BA8;
                if (n > 0 && cnt < n) {
                    Task_SetState1(a0, 4);
                    break;
                }
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018E), 0x81, D_800737B8[1]);
                Task_NextState2(a0);
                break;
            case 1:
                if (D_8005F704 <= 0) {
                    break;
                }
                g = (Stg30GameRoster *)&D_8005E620;
                if (g->field_4A == 0) {
                    Task_SetState1(a0, 6);
                    break;
                }
                if (g->field_61 != 0) {
                    Task_SetState1(a0, 7);
                    break;
                }
                cnt = 0;
                for (i = 0; i < 0x24; i++) {
                    if (g->elems[i].state == 1) {
                        cnt++;
                    }
                }
                if (cnt < 0x18) {
                    Task_SetState1(a0, 5);
                    break;
                }
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0190), 0x81, D_800737B8[1]);
                Task_NextState2(a0);
                break;
            case 2:
                if (D_8005F704 > 0) {
                    Task_SetState1(a0, 8);
                }
                break;
            }
            break;
        case 4:
            p = (s32 *)a0->u34.children;
            switch (a0->stateLevel2) {
            case 0:
            default:
                w->field_10 = 0;
                Text_Close(&w->text[0]);
                Text_Close(&w->text[1]);
                func_800728D8(a0, 0);
                args.field_0 = 0;
                args.field_4 = 0x23;
                Task_Create(0x16, p, (s32)&args);
                Task_NextState2(a0);
                break;
            case 1:
                if (*p != 0) {
                    break;
                }
                Digi_SortRoster();
                Task_NextState0(a0);
                break;
            }
            break;
        case 5:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018F), 0x81, D_800737B8[1]);
                Flag_Set(0x10, 0);
                Task_NextState2(a0);
                break;
            case 1:
                if (!Flag_Test(0x10)) {
                    break;
                }
                if (!Flag_Test(0x11)) {
                    Task_NextState2(a0);
                    break;
                }
                Task_SetState1(a0, 8);
                break;
            case 2:
                w->field_10 = 0;
                Text_Close(&w->text[0]);
                Text_Close(&w->text[1]);
                func_800728D8(a0, 1);
                args.field_0 = 0;
                args.field_4 = 0x23;
                Task_Create(0x16, p, (s32)&args);
                Task_NextState2(a0);
                break;
            case 3:
                if (*p != 0) {
                    break;
                }
                Digi_SortRoster();
                Task_NextState0(a0);
                break;
            }
            break;
        case 7:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0191), 0x81, D_800737B8[1]);
                Task_NextState2(a0);
                break;
            case 1:
                if (D_8005F704 > 0) {
                    Task_SetState1(a0, 8);
                }
                break;
            }
            break;
        case 6:
        case 8:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Snd_PlayById(0x1C, 0);
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0192), 0x81, D_800737B8[1]);
                Task_NextState2(a0);
            case 1:
                if (D_8005F704 > 0) {
                    Task_NextState0(a0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        Text_CloseArray(w->text, 2);
        Task_NextState0(a0);
        break;
    }
}

void func_80072F84(Actor *a0) {
    if (((Stg30Work737C8 *)a0->work)->field_10 != 0) {
        Gfx_DrawParts(Cd_GetFileEntry(0x1A10017));
    }
}
