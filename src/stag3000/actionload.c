#include "common.h"
#include "stag3000/stag3000.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_ActionLoadInit(Actor *a0, s32 *args);
void Stg30_ActionLoadUpdate(Actor *a0);
void Stg30_ActionLoadDestroy(Actor *a0);

TaskDesc Stg30_ActionLoadDesc = {
    (TaskInitFn)Stg30_ActionLoadInit, Stg30_ActionLoadUpdate, Stg30_ActionLoadDestroy, 0, 0x324, 0,
};

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
            w->keptFiles[w->keptCount++] = Digi_GetAnimFile(w->casterDigiId, 0);
            w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->casterDigiId, Skill_GetCastAnim(w->skillId) + 5);
        }
        for (i = 0; i < 6; i++) {
            if (w->targetDigiIds[i] != 0) {
                w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->targetDigiIds[i]);
                w->keptFiles[w->keptCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 0);
                switch (w->targetReactKinds[i]) {
                case 0:
                    break;
                case 1:
                    w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 1);
                    break;
                case 3:
                    w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 2);
                    w->keptFiles[w->keptCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 0xA);
                    break;
                case 2:
                    w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 2);
                case 4:
                    w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 9);
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

void Stg30_ActionLoadDestroy(Actor *a0) {
    Stg30ActionLoadWork *w = (Stg30ActionLoadWork *)a0->work;
    s32 i;

    for (i = 0; i < w->tempCount; i++) {
        if (w->tempFiles[i] != 0) {
            Cd_FreeFile(w->tempFiles[i]);
        }
    }
}
