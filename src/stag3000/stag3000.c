#include "common.h"
#include "stag3000/stag3000.h"

/* Task callbacks the descriptors below need (defined further down; the last one in
 * stag3000_100C.c). */
void Stg30_BannerInit(Actor *a0, s32 a1);
void Stg30_BannerUpdate(Actor *a0);
void Stg30_BannerDraw(Actor *a0);
void Stg30_FightBgUpdate(Actor *a0);
void Stg30_FightBgDraw(Actor *a0);
void Stg30_ActionLoadInit(Actor *a0, s32 *args);
void Stg30_ActionLoadUpdate(Actor *a0);
void Stg30_ActionLoadDestroy(Actor *a0);

s32 Stg30_BannerParts[] = { 0x01A10001, 0x01A10012, 0x01A1001F, 0x01A10013 };
TaskDesc Stg30_BannerDesc = {
    (TaskInitFn)Stg30_BannerInit, Stg30_BannerUpdate, Task_DefaultDestroy, Stg30_BannerDraw, 0, 0,
};
s32 Stg30_FightBgModels[] = { 0xE2D, 0xE2A, 0xE2C, 0xE29, 0xE2E, 0xE2B };
s32 Stg30_SpecialFightBgModel = 0xD77;
s32 Stg30_FightBgByFloorElem[] = { 5, 5, 0, 1, 2, 3, 4 };
TaskDesc Stg30_FightBgDesc = { 0, Stg30_FightBgUpdate, Task_DefaultDestroy, Stg30_FightBgDraw, 0, 0 };
TaskDesc Stg30_ActionLoadDesc = {
    (TaskInitFn)Stg30_ActionLoadInit, Stg30_ActionLoadUpdate, Stg30_ActionLoadDestroy, 0, 0x324, 0,
};

void Stg30_BannerInit(Actor *a0, s32 a1) {
    a0->param = a1;
}

void Stg30_BannerUpdate(Actor *a0) {
    switch (a0->stateLevel0) {
    case 0:
        if (a0->param == 1) Snd_PlayById(0x24, 0);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->param) {
        case 0:
        default:
            if (a0->elapsed >= 0x100) Task_SetState0(a0, 3);
            break;
        case 1:
        case 2:
            if (a0->elapsed >= 0x80) Task_SetState0(a0, 3);
            break;
        case 3:
            if (a0->elapsed >= 0x12D && (Pad_Pressed & 0x840)) Task_SetState0(a0, 3);
            break;
        }
        break;
case 2: break;
    }
}

void Stg30_BannerDraw(Actor *a0) {
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(Stg30_BannerParts[a0->param]);
    Stg30Part *q;

    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_CycleRange(a0->elapsed, 4, 0, 7);
    }
    if (a0->param == 3) {
        if (Stg30_Battle.entries[0].fromCity != 0) {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 1);
        } else {
            Gfx_HidePartsByMask((GfxPartMaskView *)p, 2);
        }
    }
    Gfx_DrawParts((EntA0 *)p);
}

void Stg30_FightBgUpdate(Actor *a0) {
    if (a0->stateLevel0 == 0) {
        if (Stg30_Battle.entries[0].fromCity != 0) {
            a0->digiId = Stg30_SpecialFightBgModel;
        } else {
            a0->digiId = Stg30_FightBgModels[Stg30_FightBgByFloorElem[D_8005E5DD]];
        }
        Actor_InitTransform(a0, Gfx_ZeroVector, 0);
        Gfx_AttachModel(a0, a0->digiId)->otIndex = 5;
        Gfx_ResetModelBones(a0);
        Task_NextState0(a0);
    }
}

void Stg30_FightBgDraw(Actor *a0) {
    Gfx_AttachModel(a0, a0->digiId);
    Actor_UpdateTransform(a0);
    Gfx_CalcModelBoneMatrices(a0);
    Gfx_DrawTexModel(a0, 1);
}

void Stg30_ActionLoadInit(Actor *a0, s32 *args) {
    ((Stg30WorkWord *)a0->work)->field_0 = args[0];
}

void Stg30_ActionLoadAddSorted(Actor *a0, s32 file, s32 lba) {
    Stg30ActionLoadWork *w = (Stg30ActionLoadWork *)a0->work;
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

void Stg30_ActionLoadUpdate(Actor *a0) {
    Stg30ActionLoadWork *w = (Stg30ActionLoadWork *)a0->work;
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
        p = w->script;
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
                    w->casterDigiId = Stg30_Battle.entries[p[1]].digiId;
                    w->itemAction = 0;
                } else {
                    w->itemAction = 1;
                }
                w->skillId = p[2];
                p += 3;
                break;
            case 10:
                w->targetReactKinds[k] = 1;
                w->targetDigiIds[k] = Stg30_Battle.entries[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 11:
                w->targetReactKinds[k] = 2;
                w->targetDigiIds[k] = Stg30_Battle.entries[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 12:
                w->targetReactKinds[k] = 3;
                w->targetDigiIds[k] = Stg30_Battle.entries[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 13:
                w->targetReactKinds[k] = 0;
                w->targetDigiIds[k] = Stg30_Battle.entries[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 8:
                w->targetReactKinds[k] = 4;
                w->targetDigiIds[k] = Stg30_Battle.entries[p[1]].digiId;
                p += 3;
                k++;
                break;
            }
        }
        Cd_QueueFile(Skill_GetPartsEntry(w->skillId) >> 16);
        Task_NextState1(a0);
        break;
    case 1:
        w->keptCount = 0;
        w->tempCount = 0;
        if (w->itemAction == 0) {
            w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->casterDigiId);
            w->keptFiles[w->keptCount++] = Anim_GetModelAnimFile(w->casterDigiId, 0);
            w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->casterDigiId, Skill_GetCastAnim(w->skillId) + 5);
        }
        for (i = 0; i < 6; i++) {
            if (w->targetDigiIds[i] != 0) {
                w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->targetDigiIds[i]);
                w->keptFiles[w->keptCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 0);
                switch (w->targetReactKinds[i]) {
                case 0:
                    break;
                case 1:
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 1);
                    break;
                case 3:
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 2);
                    w->keptFiles[w->keptCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 0xA);
                    break;
                case 2:
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 2);
                case 4:
                    w->tempFiles[w->tempCount++] = Anim_GetModelAnimFile(w->targetDigiIds[i], 9);
                    break;
                }
            }
        }
        if (w->skillId != 0) {
            for (k = 0; k < 2; k++) {
                Skill_GetFxSet(w->skillId, k, a, b);
                for (j = 0; j < 3; j++) {
                    if (a[j] != 0) {
                        w->tempFiles[w->tempCount++] = a[j];
                    }
                    if (b[j] != 0) {
                        w->tempFiles[w->tempCount++] = b[j];
                    }
                }
            }
        }
        if (w->itemAction != 0) {
            w->keptFiles[w->keptCount++] = 0xD2D;
            w->keptFiles[w->keptCount++] = 0xD2B;
        }
        w->keptFiles[w->keptCount++] = 0x1A1;
        w->keptFiles[w->keptCount++] = 0x13B;
        w->keptFiles[w->keptCount++] = 0x1A0;
        w->keptFiles[w->keptCount++] = 0x22B;
        w->keptFiles[w->keptCount++] = 0xCB9;
        Task_NextState1(a0);
        break;
    case 2:
        if (w->itemAction == 0) {
            if (Cd_GetFileState(Skill_GetPartsEntry(w->skillId) >> 16) != 3) {
                break;
            }
            w->keptFiles[w->keptCount++] = 0x1EF;
            for (q = (Stg30Part *)Cd_GetFileEntry(Skill_GetPartsEntry(w->skillId)); q->fileId != 0; q++) {
                w->tempFiles[w->tempCount++] = q->fileId >> 16;
            }
        }
        w->count = 0;
        for (i = 0; i < w->keptCount; i++) {
            Stg30_ActionLoadAddSorted(a0, w->keptFiles[i], Cd_GetFileLba(w->keptFiles[i]));
        }
        for (i = 0; i < w->tempCount; i++) {
            Stg30_ActionLoadAddSorted(a0, w->tempFiles[i], Cd_GetFileLba(w->tempFiles[i]));
        }
        Task_NextState1(a0);
        w->loadTimer = 0;
        break;
    case 3:
        if (++w->loadTimer < 300) {
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
