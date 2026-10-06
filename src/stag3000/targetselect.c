#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_TargetSelectUpdate(Actor *a0);
void Stg30_TargetSelectDraw(Actor *a0);

s32 Stg30_TargetCursorMasks[] = { ~0x2, ~0x4, ~0x8, ~0x10, ~0x20, ~0x40 };
s32 Stg30_TargetAllEnemiesMask = ~0x70;
s32 Stg30_TargetAllAlliesMask = ~0xE;
TaskDesc Stg30_TargetSelectDesc = {
    0, Stg30_TargetSelectUpdate, Task_DefaultDestroy, Stg30_TargetSelectDraw, 0x20, 0,
};

void Stg30_TargetSelectUpdate(Actor *a0) {
    Stg30TargetSelectWork *w = (Stg30TargetSelectWork *)a0->work;
    TaskEntry *t;
    s32 i;
    s32 old;
    s32 changed;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->skillId = Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].skillId;
        w->targetMode = Skill_GetTarget(w->skillId);
        w->effectKind = Stg30_Battle.turns[Stg30_Battle.entries[0].inputSlot].effectKind;
        switch (w->targetMode) {
        case 0:
        case 3:
        case 4:
        case 7:
        default:
            v = Stg30_Battle.entries[0].inputSlot;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 1:
            w->firstSlot = 0;
            w->lastSlot = 2;
            w->team = 0;
            w->target = Stg30_TargetFirst(0, 1, w->effectKind);
            break;
        case 2:
            v = 7;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 5:
            w->firstSlot = 3;
            w->lastSlot = 5;
            w->team = 1;
            w->target = Stg30_TargetFirst(1, 1, w->effectKind);
            break;
        case 6:
            v = 8;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 8:
            v = 9;
            w->target = v;
            w->lastSlot = v;
            w->firstSlot = v;
            break;
        case 9:
            Stg30_Battle.entries[0].chosenTarget = 0;
            Stg30_Battle.entries[0].cancelled = 0;
            Task_SetState0(a0, 3);
            return;
        }
        Task_NextState0(a0);
        break;
    case 1:
        changed = 0;
        do {
        if (w->targetMode == 1 || w->targetMode == 5) {
            if (Pad_State[0].left > 0) {
                old = w->target;
                if (w->team != 0) {
                    w->target = Stg30_TargetPrev(w->team, old, 1, w->effectKind);
                } else {
                    w->target = Stg30_TargetNext(0, old, 1, w->effectKind);
                }
                if (w->target != old) {
                    changed = 1;
                    Snd_PlayById(0x12, 0);
                }
            }
            if (Pad_State[0].right > 0) {
                old = w->target;
                if (w->team != 0) {
                    w->target = Stg30_TargetNext(w->team, old, 1, w->effectKind);
                } else {
                    w->target = Stg30_TargetPrev(0, old, 1, w->effectKind);
                }
                if (w->target != old) {
                    changed = 1;
                    Snd_PlayById(0x12, 0);
                }
            }
        }
            if (Pad_State[0].cross > 0) {
                Stg30_Battle.entries[0].chosenTarget = w->target;
                Stg30_Battle.entries[0].cancelled = 0;
                Snd_PlayById(0xE, 0);
                Task_SetState0(a0, 3);
                break;
            }
            if (Pad_State[0].triangle > 0) {
                Stg30_Battle.entries[0].cancelled = 1;
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 3);
            }
        } while (0);
        if (changed || w->highlightDone == 0) {
            w->highlightDone = 1;
            switch (w->targetMode) {
            case 1:
            case 5:
                for (i = w->firstSlot; i <= w->lastSlot; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL) {
                        if (w->target == i) {
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
                    if (t != NULL && Stg30_Battle.entries[i].hp != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            case 6:
                for (i = 3; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && Stg30_Battle.entries[i].hp != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            case 8:
                for (i = 0; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL && Stg30_Battle.entries[i].hp != 0) {
                        Task_SetState01((Actor *)t, 2, 8);
                    } else {
                        Task_SetState01((Actor *)t, 2, 7);
                    }
                }
                break;
            }
        }
        switch (w->targetMode) {
        case 1:
        case 5:
            ((void (*)(s32))Stg30_SetCameraShot)(w->target + 2);
            break;
        case 2:
            Stg30_SetCameraShot(8);
            break;
        case 6:
            Stg30_SetCameraShot(9);
            break;
        case 8:
            Stg30_SetCameraShot(0x18);
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg30_TargetSelectDraw(Actor *a0) {
    Stg30TargetSelectWork *w = (Stg30TargetSelectWork *)a0->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0x1A1000A);
    GfxPart *q;
    s32 m;

    switch (w->targetMode) {
    case 0:
    case 1:
    case 5:
        Gfx_HidePartsByMask((GfxPartMaskView *)p, Stg30_TargetCursorMasks[w->target]);
        break;
    case 2:
        m = Stg30_TargetAllAlliesMask;
        if (Stg30_Battle.entries[2].hp == 0) m |= 8;
        if (Stg30_Battle.entries[1].hp == 0) m |= 4;
        if (Stg30_Battle.entries[0].hp == 0) m |= 2;
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    case 6:
        m = Stg30_TargetAllEnemiesMask;
        if (Stg30_Battle.entries[5].hp == 0) m |= 0x40;
        if (Stg30_Battle.entries[4].hp == 0) m |= 0x20;
        if (Stg30_Battle.entries[3].hp == 0) m |= 0x10;
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    case 8:
        m = -0x7F;
        if (func_8001F0E4(w->skillId) & 0x2000) {
            if (Stg30_Battle.entries[0].digiId == 0) m = -0x7D;
            if (Stg30_Battle.entries[1].digiId == 0) m |= 4;
            if (Stg30_Battle.entries[2].digiId == 0) m |= 8;
            if (Stg30_Battle.entries[3].digiId == 0) m |= 0x10;
            if (Stg30_Battle.entries[4].digiId == 0) m |= 0x20;
            if (Stg30_Battle.entries[5].digiId == 0) m |= 0x40;
        } else {
            if (Stg30_Battle.entries[0].hp == 0) m = -0x7D;
            if (Stg30_Battle.entries[1].hp == 0) m |= 4;
            if (Stg30_Battle.entries[2].hp == 0) m |= 8;
            if (Stg30_Battle.entries[3].hp == 0) m |= 0x10;
            if (Stg30_Battle.entries[4].hp == 0) m |= 0x20;
            if (Stg30_Battle.entries[5].hp == 0) m |= 0x40;
        }
        Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
        break;
    }
    for (q = p; q->fileId != 0; q++) {
        q->palette = Math_PingPongRange(a0->elapsed, 8, 0, 3);
    }
    Gfx_DrawParts((EntA0 *)p);
}
