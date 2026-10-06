#include "common.h"
#include "stag3500/stag3500.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_ActionLoadInit(Actor *arg0, s32 *arg1);
void Stg35_ActionLoadUpdate(Actor *arg0);
void Stg35_ActionLoadDestroy(Actor *arg0);

TaskDesc Stg35_ActionLoadDesc = {
    (TaskInitFn)Stg35_ActionLoadInit, Stg35_ActionLoadUpdate, Stg35_ActionLoadDestroy, 0, 0x320, 0,
};

void Stg35_ActionLoadInit(Actor *arg0, s32 *arg1) {
    ((Stg35FighterWork *)arg0->work)->field_0 = *arg1;
}

void Stg35_ActionLoadAddSorted(Actor *arg0, s32 arg1, s32 arg2) {
    Stg35ActionLoadWork *w = (Stg35ActionLoadWork *)arg0->work;
    s32 found = 0;
    s32 i;
    s32 j;

    for (i = 0; i < w->sortedCount; i++) {
        if (arg2 < w->sortedLbas[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = w->sortedCount; i < j; j--) {
            w->sortedFileIds[j] = w->sortedFileIds[j - 1];
            w->sortedLbas[j] = w->sortedLbas[j - 1];
        }
    }
    w->sortedFileIds[i] = arg1;
    w->sortedLbas[i] = arg2;
    w->sortedCount++;
}

void Stg35_ActionLoadUpdate(Actor *arg0) {
    Stg35ActionLoadWork *w = (Stg35ActionLoadWork *)arg0->work;
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
        p = w->script;
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
                w->casterDigiId = Stg35_Battle.rec[p[1]].digiId;
                w->skillId = p[2];
                p += 3;
                break;
            case 9:
                w->targetReactKinds[k] = 1;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 10:
                w->targetReactKinds[k] = 2;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 11:
                w->targetReactKinds[k] = 3;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            case 12:
                w->targetReactKinds[k] = 0;
                w->targetDigiIds[k] = Stg35_Battle.rec[p[1]].digiId;
                p += 3;
                k++;
                break;
            }
        }
        Cd_QueueFile(Skill_GetPartsEntry(w->skillId) >> 16);
        Task_NextState1(arg0);
        break;
    case 1:
        w->keptCount = 0;
        w->tempCount = 0;
        w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->casterDigiId);
        w->keptFiles[w->keptCount++] = Digi_GetAnimFile(w->casterDigiId, 0);
        w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->casterDigiId, Skill_GetCastAnim(w->skillId) + 5);
        for (i = 0; i < 6; i++) {
            if (w->targetDigiIds[i] != 0) {
                w->keptFiles[w->keptCount++] = Digi_GetModelFile(w->targetDigiIds[i]);
                w->keptFiles[w->keptCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 0);
                switch (w->targetReactKinds[i]) {
                case 0:
                default:
                    break;
                case 1:
                    w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 1);
                    break;
                case 3:
                    w->keptFiles[w->keptCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 0xA);
                case 2:
                    w->tempFiles[w->tempCount++] = Digi_GetAnimFile(w->targetDigiIds[i], 2);
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
        w->keptFiles[w->keptCount++] = 0x1A1;
        w->keptFiles[w->keptCount++] = 0x13B;
        w->keptFiles[w->keptCount++] = 0x1A0;
        w->keptFiles[w->keptCount++] = 0x22B;
        w->keptFiles[w->keptCount++] = 0xCB9;
        Task_NextState1(arg0);
        break;
    case 2:
        if (Cd_GetFileState(Skill_GetPartsEntry(w->skillId) >> 16) == 3) {
            w->keptFiles[w->keptCount++] = 0x1EF;
            part = (GfxPart *)Cd_GetFileEntry(Skill_GetPartsEntry(w->skillId));
            while (part->fileId != 0) {
                w->tempFiles[w->tempCount++] = part->fileId >> 16;
                part++;
            }
            w->sortedCount = 0;
            for (i = 0; i < w->keptCount; i++) {
                Stg35_ActionLoadAddSorted(arg0, w->keptFiles[i], Cd_GetFileLba(w->keptFiles[i]));
            }
            for (i = 0; i < w->tempCount; i++) {
                Stg35_ActionLoadAddSorted(arg0, w->tempFiles[i], Cd_GetFileLba(w->tempFiles[i]));
            }
            Task_NextState1(arg0);
            w->loadTimer = 0;
        }
        break;
    case 3:
        if (++w->loadTimer < 300) {
            for (i = 0; i < w->sortedCount; i++) {
                Cd_QueueFile(w->sortedFileIds[i]);
                if (Cd_GetFileState(w->sortedFileIds[i]) != 3) {
                    return;
                }
            }
        }
        Task_NextState0(arg0);
        break;
    }
}

void Stg35_ActionLoadDestroy(Actor *arg0) {
    Stg35ActionLoadWork *w = (Stg35ActionLoadWork *)arg0->work;
    s32 i;

    for (i = 0; i < w->tempCount; i++) {
        if (w->tempFiles[i] != 0) {
            Cd_FreeFile(w->tempFiles[i]);
        }
    }
}
