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
#include "stag3000/battlestate.h"
#include "stag3000/fighter.h"
#include "stag3000/fightmsg.h"
#include "stag3000/popup.h"
#include "stag3000/interruptselect.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_FighterHudInit(Actor *a0, PTR32(Stg30Ref) *args);
void Stg30_FighterHudUpdate(Stg30TaskHead *a0);
void Stg30_FighterHudDestroy(Actor *a0);
void Stg30_FighterHudDraw(Actor *a0);

s32 Stg30_FighterHudFadeDelay[] = { 5, 11, 17, 5, 11, 17 };
Stg30XY Stg30_FighterHudNamePos[] = { { 17, 215 }, { 116, 215 }, { 215, 215 }, { 17, 16 }, { 116, 16 }, { 215, 16 } };
u8 Stg30_OrderLabelMsgs[] = { 0xA, 0xB, 0xC, 0xD, 6 };
Halves Stg30_OrderLabelPos[] = { { 0x12, 0xAB }, { 0x75, 0xAB }, { 0xD8, 0xAB } };
s32 Stg30_FighterHudParts[] = { 0x01A10023, 0x01A10024, 0x01A10025, 0x01A10020, 0x01A10021, 0x01A10022 };
s32 Stg30_StatusIconGroups[] = { 4, 8, 0x10, 0x40000, 0x80000, 0x100000 };
s32 Stg30_StatusIconFlags[] = { 1, 2, 4, 8, 0x10000, 0x8000 };
Stg30XY Stg30_StatusIconPos[] = { { -99, 85 }, { 0, 85 }, { 99, 85 }, { -99, -90 }, { 0, -90 }, { 99, -90 } };
TaskDesc Stg30_FighterHudDesc = {
    (TaskInitFn)Stg30_FighterHudInit, (TaskFn)Stg30_FighterHudUpdate, Stg30_FighterHudDestroy,
    Stg30_FighterHudDraw, 0x14, 0,
};

void Stg30_FighterHudInit(Actor *a0, PTR32(Stg30Ref) *args) {
    ((Stg30FighterHudWork *)a0->work)->ref = P32(Stg30Ref, args[0]); /* args: 32-bit words (Stg30_FighterTask) */
    a0->param = P32(Stg30Ref, args[0])->param;
}

void Stg30_FighterHudUpdate(Stg30TaskHead *a0) {
    Stg30FighterHudWork *w = (Stg30FighterHudWork *)a0->work;
    TextOpenArgs args;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->labelSlide = 12;
        Mem_FillWordsNeg1(w->text, 2);
        Task_NextState0((Actor *)a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (a0->frameCount > Stg30_FighterHudFadeDelay[a0->param] && w->openScale != 0x1000) {
                w->openScale += 0x100;
            }
            if (w->openScale == 0x1000) {
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            args.text = (s32)Stg30_BattleDigiNames[a0->param].name;
            args.bigFont = 0;
            args.color = 0;
            args.x = Stg30_FighterHudNamePos[a0->param].x;
            args.y = Stg30_FighterHudNamePos[a0->param].y;
            args.charDelay = 8;
            args.charAdvance = 0;
            args.lineAdvance = 0;
            Text_Open(&w->text[0], &args);
            Task_NextState1((Actor *)a0);
            break;
        case 2:
            v = Stg30_Battle.turns[a0->param].turnType;
            if (v != 0) {
                if (w->labelSlide != 0) {
                    w->labelSlide -= 4;
                } else {
                    Text_OpenById(&w->text[1], Stg30_OrderLabelMsgs[v - 1], 0, Stg30_OrderLabelPos[a0->param]);
                }
            } else if (w->labelSlide != 12) {
                w->labelSlide += 4;
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

void Stg30_FighterHudDestroy(Actor *a0) {
    Text_CloseArray(((Stg30FighterHudWork *)a0->work)->text, 2);
    Task_DefaultDestroy(a0);
}

void Stg30_SetGaugeParts(Stg30Part *p, s32 unit, s32 num, s32 den) {
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

void Stg30_FighterHudDraw(Actor *a0) {
    Stg30FighterHudWork *w = (Stg30FighterHudWork *)a0->work;
    Stg30Part *p;
    Stg30Part *q;
    DigiRosterEntry *d;
    s32 off;
    s32 j;
    s32 m;
    s32 k;
    s32 t;

    if (a0->stateLevel0 != 2) {
        p = (Stg30Part *)Cd_GetFileEntry(Stg30_FighterHudParts[a0->param]);
        off = 0;
        for (q = p; q->fileId != 0; q++) {
            j = 0;
            m = q->groupMask;
            for (; j < 6; j++) {
                if (m & Stg30_StatusIconGroups[j]) {
                    if (Stg30_Battle.statusFlags[a0->param] & Stg30_StatusIconFlags[j]) {
                        q->x = Stg30_StatusIconPos[a0->param].x + off;
                        off += 10;
                        q->y = Stg30_StatusIconPos[a0->param].y;
                        q->visible = 1;
                    } else {
                        q->visible = 0;
                    }
                }
            }
        }
        for (q = p; q->fileId != 0; q++) {
            t = w->openScale;
            if (t != 0x1000) {
                q->unscaled = 0;
                q->scaleY = w->openScale;
            } else {
                q->unscaled = 1;
                q->scaleY = t;
            }
            if (q->groupMask & 1) {
                if (w->labelSlide == 12) {
                    q->visible = 0;
                } else {
                    q->visible = 1;
                    q->y = w->labelSlide + 0x55;
                }
            }
        }
        k = a0->param;
        if (k < 3) {
            DigiRosterEntry *s = &Stg30_BattleDigis[k];

            Gfx_SetPartsNumber((GfxPart *)p, 0x20, 3, s->maxHp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x40, 3, s->hp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x80, 3, s->maxMp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x100, 3, s->mp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x200, 2, s->level);
        }
        d = &Stg30_BattleDigis[a0->param];
        if (a0->param < 3) {
            Stg30_SetGaugeParts(p, 0x400, d->hp, d->maxHp);
            Stg30_SetGaugeParts(p, 0x4000, d->mp, d->maxMp);
        } else {
            Stg30_SetGaugeParts(p, 0x20, d->hp, d->maxHp);
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}
