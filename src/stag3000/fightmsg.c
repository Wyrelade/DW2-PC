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
void Stg30_FightMsgInit(Stg30TaskHead *a0, s32 *args);
void Stg30_FightMsgUpdate(Stg30TaskHead *a0);
void Stg30_FightMsgDraw(Stg30TaskHead *a0);

s32 Stg30_FightMsgParts[] = { 0x01A10002, 0x01A10003, 0x01A10004, 0x01A10005, 0x01A10006, 0x01A10007 };
TaskDesc Stg30_FightMsgDesc = {
    (TaskInitFn)Stg30_FightMsgInit, (TaskFn)Stg30_FightMsgUpdate, Task_DefaultDestroy, (TaskFn)Stg30_FightMsgDraw,
    8, 0,
};

void Stg30_FightMsgInit(Stg30TaskHead *a0, s32 *args) {
    a0->param = args[0];
    a0->partGroup = args[1] ? 2 : 4;
}

void Stg30_FightMsgUpdate(Stg30TaskHead *a0) {
    Stg30FightMsgWork *w = (Stg30FightMsgWork *)a0->work;
    s32 snd;

    switch (a0->stateLevel0) {
    case 0:
        switch (a0->param) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        default:
            snd = 0x25;
            break;
        case 5:
            if (a0->partGroup == 2) {
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
            if (w->palette != 7) {
                w->palette++;
            }
            w->scale += 0x200;
            if (w->scale >= 0x1000) {
                w->scale = 0x1000;
                w->palette = 7;
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
        if (w->palette != 0) {
            w->palette--;
        } else {
            Task_SetState0((Actor *)a0, 3);
        }
        break;
    }
}

void Stg30_FightMsgDraw(Stg30TaskHead *a0) {
    Stg30FightMsgWork *w = (Stg30FightMsgWork *)a0->work;
    Stg30Part *p = (Stg30Part *)Cd_GetFileEntry(Stg30_FightMsgParts[a0->param]);
    Stg30Part *q;
    s32 vis;

    for (q = p; q->fileId != 0; q++) {
        vis = q->groupMask == a0->partGroup;
        q->unscaled = 0;
        q->visible = vis;
        q->scaleX = w->scale;
        q->palette = w->palette;
    }
    Gfx_DrawParts((EntA0 *)p);
}
