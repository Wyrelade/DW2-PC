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
