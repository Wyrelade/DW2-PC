#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_PopupInit(Actor *a0, Vec3 *args);
void Stg30_PopupUpdate(Actor *a0);
void Stg30_PopupDraw(Actor *a0);

s32 Stg30_PopupItemMasks[] = { 0xB, 0xD, 0xE, 0x7 };
s32 Stg30_PopupNumMasks[] = { 0x16, 0xD, 0xB };
s32 Stg30_PopupNumParts[] = { 8, 0x10, 0x10 };
TaskDesc Stg30_PopupDesc = {
    (TaskInitFn)Stg30_PopupInit, Stg30_PopupUpdate, Task_DefaultDestroy, Stg30_PopupDraw, 0x14, 0,
};

void Stg30_PopupInit(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void Stg30_PopupUpdate(Actor *a0) {
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
            w->palette++;
            w->scale += 0x200;
            if (w->palette != 7) {
                break;
            }
            a0->elapsed = 0;
            w->scale = 0x1000;
            Task_NextState1(a0);
        case 1:
            t = w->pos.x;
            if (t != 7) {
                if (a0->elapsed < 0x28) {
                    break;
                }
            } else {
                w->palette = Math_CycleRange(a0->elapsed, 2, 8, 0xF);
                if (a0->elapsed < 0x90) {
                    break;
                }
                w->palette = t;
            }
            Task_NextState1(a0);
        case 2:
            if (--w->palette < 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg30_PopupDraw(Actor *a0) {
    Stg30WorkVec3 *w = (Stg30WorkVec3 *)a0->work;
    Stg30Part *p = NULL;
    Stg30Part *q;
    s32 draw = 1;
    s32 id;

    switch (w->pos.x) {
    case 0:
    default:
        p = (Stg30Part *)Cd_GetFileEntry(Skill_GetPartsEntry(w->pos.y));
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        p = (Stg30Part *)Cd_GetFileEntry(0xD2D0000);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, Stg30_PopupItemMasks[w->pos.x - 4]);
        break;
    case 1:
    case 2:
    case 3:
        p = (Stg30Part *)Cd_GetFileEntry(0x1A10000);
        Gfx_SetPartsNumber((GfxPart *)p, Stg30_PopupNumParts[w->pos.x - 1], 3, w->pos.y);
        Gfx_HidePartsByMask((GfxPartMaskView *)p, Stg30_PopupNumMasks[w->pos.x - 1]);
        break;
    case 8:
        draw = 0;
        break;
    }
    if (draw) {
        for (q = p; q->fileId != 0; q++) {
            if (w->scale != 0x1000) {
                q->unscaled = 0;
                q->scaleX = w->scale;
            } else {
                q->unscaled = 1;
            }
            q->palette = w->palette;
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
            if (w->scale != 0x1000) {
                q->unscaled = 0;
                q->scaleX = w->scale;
            } else {
                q->unscaled = 1;
            }
            q->palette = w->palette;
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}
