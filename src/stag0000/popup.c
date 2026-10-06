#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"
#include "stag0000/font.h"
#include "stag0000/fightbg.h"
#include "stag0000/digiview.h"
#include "stag0000/lineup.h"
#include "stag0000/videomode.h"
#include "stag0000/groupview.h"
#include "stag0000/digimodel.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg00_PopupInit(Actor *arg0, Stg00Vec3 *arg1);
void Stg00_PopupTask(Actor *arg0);
void Stg00_PopupDraw(Actor *arg0);

s32 Stg00_PopupItemMasks[] = { 0xB, 0xD, 0xE, 0x7 };
s32 Stg00_PopupNumMasks[] = { 0x16, 0xD, 0xB };
s32 Stg00_PopupNumParts[] = { 8, 0x10, 0x10 };
TaskDesc Stg00_PopupDesc = {
    (TaskInitFn)Stg00_PopupInit, Stg00_PopupTask, Task_DefaultDestroy, Stg00_PopupDraw, 0x14, 0,
};
/* Task_DescTable[1]: task ids 0x100-0x10D. */
TaskDesc *Stg00_TaskDescs[] = {
    &Stg00_StageSetupDesc, &Stg00_WindowTestDesc, &Stg00_VideoModeDesc, &Stg00_DigiViewDesc,
    &Stg00_GroupViewDesc, &Stg00_DigiModelDesc, &Stg00_FightBgDesc, &Stg00_SoundTestDesc,
    &Stg00_LineupDesc, &Stg00_CameraDesc, &Stg00_DungSelDesc, &Stg00_PopupDesc,
    &Stg00_XaPlayDesc, &Stg00_ScrollViewDesc,
};

void Stg00_PopupInit(Actor *arg0, Stg00Vec3 *arg1) {
    *(Stg00Vec3 *)arg0->work = *arg1;
}

void Stg00_PopupTask(Actor *arg0) {
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
            w->palette++;
            w->scale += 0x200;
            if (w->palette != 7) {
                break;
            }
            arg0->elapsed = 0;
            w->scale = 0x1000;
            Task_NextState1(arg0);
        case 1:
            v = w->kind;
            if (v != 7) {
                if (arg0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->palette = Math_CycleRange(arg0->elapsed, 2, 8, 0xF);
                if (arg0->elapsed < 0x90) {
                    break;
                }
                w->palette = v;
            }
            Task_NextState1(arg0);
        case 2:
            if (--w->palette < 0) {
                Task_SetState0(arg0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg00_PopupDraw(Actor *arg0) {
    Stg00PanelWork *w = (Stg00PanelWork *)arg0->work;
    EntA0 *e = NULL;
    s32 draw = 1;
    Stg00PartScale *p;
    s32 id;

    switch (w->kind) {
    case 0:
    default:
        e = Cd_GetFileEntry(Skill_GetPartsEntry(w->value));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        e = Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask(e, Stg00_PopupItemMasks[w->kind - 4]);
        break;
    case 1:
    case 2:
    case 3:
        e = Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber(e, Stg00_PopupNumParts[w->kind - 1], 3, w->value);
        Gfx_HidePartsByMask(e, Stg00_PopupNumMasks[w->kind - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->scale != 0x1000) {
                p->unscaled = 0;
                p->scaleX = w->scale;
            } else {
                p->unscaled = 1;
            }
            p->palette = w->palette;
        }
        Gfx_DrawParts(e);
    }
    if (w->subPart != 0) {
        switch (w->subPart >> 8) {
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
        Gfx_HidePartsByMask(e, ~(1 << ((u8)w->subPart - 1)));
        for (p = (Stg00PartScale *)e; p->fileId != 0; p++) {
            if (w->scale != 0x1000) {
                p->unscaled = 0;
                p->scaleX = w->scale;
            } else {
                p->unscaled = 1;
            }
            p->palette = w->palette;
        }
        Gfx_DrawParts(e);
    }
}
