#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"
#include "stag4000/itemmenu.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"

Stg40XY16 Stg40_DirOffsets[] = {
    { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 },
};
Stg40ItemReq Stg40_ObstacleItemReqs[] = {
    { 0x0B, { 0x17, 0x21, -1, -1 }, {0}, 0x01FD0024 },
    { 0x0B, { 0x20, 0x21, -1, -1 }, {0}, 0x01FD0024 },
    { 0, { -1, -1, -1, -1 }, {0}, 0 },
    { 0x0C, { 0x18, 0x28, -1, -1 }, {0}, 0x01FD003D },
    { 0x0C, { 0x25, 0x28, -1, -1 }, {0}, 0x01FD003D },
    { 0x0C, { 0x26, 0x28, -1, -1 }, {0}, 0x01FD003D },
    { 0x0C, { 0x27, 0x28, -1, -1 }, {0}, 0x01FD003D },
};
Stg40ItemReq Stg40_GiftGunReq = { 8, { 0x22, 0x23, 0x24, 0x1B }, {0}, 0x01FD0051 };
s32 Stg40_StatusMsgIds[] = {
    0x01FD001E, 0x01FD001C, 0x01FD002F, 0x01FD0030, 0x01FD0031, 0x01FD0032, 0x01FD0033, 0x01FD0034,
};
u8 Stg40_GiftTakeChance[] = { 96, 92, 88, 84, 80, 76, 72, 68, 64 };
u8 Stg40_GiftPointsByLevel[] = { 10, 20, 40, 80, 160 };
s32 Stg40_ShootMsgIds[] = {
    0x01FD0020, 0x01FD0021, 0x01FD0022, 0x01FD0023, 0, 0, 0x01FD0035,
    0x01FD0039, 0x01FD0036, 0x01FD003A, 0x01FD0037, 0x01FD003B, 0x01FD0038, 0x01FD003C,
};
s16 Stg40_PadDirTable[] = { -1, 0, 4, -1, 6, 7, 5, -1, 2, 1, 3, -1, -1, -1, -1, -1 };

void Stg40_PlayerAnimThenMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    Stg40_ObjSetAnim(a0, a1);
    Task_SetState1(a0, 9);
    Stg40_RootState->msgAnim = a2;
    Stg40_RootState->msgNextState = a3;
    Stg40_RootState->msgId = a4;
    Stg40_RootState->msgArg0 = a5;
    Stg40_RootState->msgArg1 = a6;
}

void Stg40_PlayerShowMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    Stg40_ObjSetAnim(a0, a1);
    Task_SetState1(a0, 0xB);
    Stg40_RootState->msgNextState = a2;
    Stg40_MsgWinOpen(1, a3, a4, a5);
}

s32 Stg40_PlayerCheckEnemyInfo(Actor *a0) {
    Stg40Ent48 *self = ((Stg40ActWork *)a0->work)->ent;
    Stg40Ent48 *e;
    s32 i;

    if (Pad_State[0].square > 0 && self->roomId != 0xFF) {
        e = Dung_StatePtr->ents;
        Stg40_RootState->enemyCount = 0;
        Stg40_RootState->enemyIndex = 0;
        for (i = 0; i < Dung_StatePtr->entCount; e++, i++) {
            if ((e->flags & 0x8000) && e->kind == 1 && e->roomId == self->roomId) {
                Stg40_RootState->enemyList[Stg40_RootState->enemyCount++] = e;
            }
        }
        if (Stg40_RootState->enemyCount != 0) {
            Task_SetState1(a0, 0x1A);
            Stg40_RootState->automapMode = 0;
            return -1;
        }
    }
    return 0;
}

s32 Stg40_PlayerInteract(Actor *a0)
{
    Stg40Ent48 *e;
    Stg40Ent48 *found;
    s32 snd;
    s32 r;
    s32 idx;
    s32 lim;
    s32 snd2;
    Actor *child;
    s32 r2;
    s32 r3;

    e = ((Stg40ActWork *)a0->work)->ent;
    if (Pad_State[0].cross <= 0) {
        return 0;
    }
    found = Stg40_FindEntAt(e->loc.u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(e->octant + 1) << 1],
                          e->loc.u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((e->octant + 1) << 1) | 1]);
    if (found == 0) {
        snd2 = 0x1FD000F;
        r2 = Stg40_GetCellFlags(e->loc.u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(e->octant + 1) << 1],
                          e->loc.u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((e->octant + 1) << 1) | 1]) & 0xF;
        if (r2 >= 3) {
            snd2 = r2 + 0x1FD0194;
        }
        Snd_PlayById(0x2E, 0);
        Stg40_PlayerAnimThenMsg(a0, 0x2D, 0x28, 6, snd2, 0, 0);
        goto end;
    }
    child = found->actor;
    Stg40_RootState->targetActor = child;
    Stg40_RootState->targetEnt = found;
    switch (found->kind) {
    default:
        Snd_PlayById(0x2E, 0);
        Stg40_PlayerAnimThenMsg(a0, 0x2D, 0x28, 6, 0x1FD000F, 0, 0);
        return -1;
    case 2:
    case 3:
        Snd_PlayById(0x2E, 0);
        Stg40_PlayerAnimThenMsg(a0, 0x2D, 0x28, 6, (found->kind == 2) ? 0x1FD0195 : 0x1FD0196, 0, 0);
        return -1;
    case 4:
        Task_SetState1(a0, 0x13);
        return -1;
    case 8:
        snd = -1;
        if (!(found->flags & 0x1000)) {
            break;
        }
        r = Stg40_GetBeetlePart(6);
        if (r == -1) {
            snd = 0x1FD0019;
        } else if (r == 0) {
            snd = 0x1FD001A;
        } else {
            lim = found->params[1];
            if (Stg40_GetPartLevel(6) < lim) {
                snd = 0x1FD0018;
            }
        }
        if (snd != -1) {
            Stg40_PlayerShowMsg(a0, 0x28, 1, snd, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0xE);
        return -1;
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
        idx = found->kind - 6;
        if (!(found->flags & 0x1000)) {
            break;
        }
        Item_CheckId(0);
        r3 = Stg40_ListUsableItems(&Stg40_ObstacleItemReqs[idx]);
        if (r3 != 0) {
            Stg40_PlayerShowMsg(a0, 0x28, 1, r3, 0, 0);
            goto end;
        }
        Task_SetState1(a0, 0x11);
        Stg40_RootState->automapMode = 0;
        Stg40_RootState->giftMenu = 0;
        Stg40_RootState->selItem = Stg40_RootState->itemIds[0];
        goto end;
    }
    Task_SetState1(a0, 0xC);
end:
    return -1;
}

s32 Stg40_PlayerTryMove(Stg40Ent48 *e) {
    Stg40Loc *loc = &e->loc;
    s32 bits;
    s32 idx;
    s32 oct;
    s32 k;
    s32 dir;
    s16 d;
    s32 nx;
    s32 ny;
    u16 f;
    u16 fl;
    u16 fr;
    s16 *pl;
    s16 *tbl;

    if (loc->moving != 0) {
        return 0;
    }
    bits = (Pad_State[0].right != 0) << 2;
    if (Pad_State[0].left != 0) {
        bits |= 8;
    }
    dir = bits;
    if (Pad_State[0].up != 0) {
        dir |= 2;
    }
    idx = dir | (Pad_State[0].down != 0);
    k = Stg40_PadDirTable[idx];
    oct = (s16)k;
    if (k < 0) {
        return 0;
    }
    if (Dung_StatePtr->status.statusFlags & 2) {
        oct = (oct + Dung_StatePtr->status.confusionTurn) & 7;
    }
    e->targetHeading = (oct << 16) >> 7;
    e->octant = oct;
    if (Pad_State[0].l1 != 0 && (oct & 1) == 0) {
        return 0;
    }
    if (Pad_State[0].r1 != 0) {
        return 0;
    }
    dir = oct + 1;
    oct = dir;
    if ((s16)e->targetHeading != e->heading) {
        return 0;
    }
    nx = ny = -1;
    loc->moveFlags &= 0xFFFE;
    d = dir;
    {
        s16 *p = (s16 *)Stg40_DirOffsets;

        f = Stg40_GetCellFlags(loc->u0.pair.field_0 + p[d << 1], loc->u0.pair.field_2 + p[(d << 1) | 1]);
    }
    if (!(f & 0x8000) || (f & 0x30) == 0x20) {
        return 0;
    }
    if (f & 0x10) {
        loc->moveFlags |= 1;
        dir = loc->u0.pair.field_0;
        nx = dir + ((s16 *)Stg40_DirOffsets)[d << 1];
        ny = loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[(d << 1) | 1];
    }
    if ((oct & 1) == 0) {
        pl = &((s16 *)Stg40_DirOffsets)[(d - 1) << 1];
        fl = Stg40_GetCellFlags(loc->u0.pair.field_0 + pl[0],
                           loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d - 1) << 1) | 1]);
        fr = Stg40_GetCellFlags(loc->u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(d + 1) << 1],
                           loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d + 1) << 1) | 1]);
        if (!(fl & 0x8000) || (fl & 0x30) == 0x20 || !(fr & 0x8000) || (fr & 0x30) == 0x20) {
            return 0;
        }
        if (fl & 0x10) {
            loc->moveFlags |= 1;
            nx = loc->u0.pair.field_0 + pl[0];
            ny = loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d - 1) << 1) | 1];
        } else if (fr & 0x10) {
            loc->moveFlags |= 1;
            nx = loc->u0.pair.field_0 + ((s16 *)Stg40_DirOffsets)[(d + 1) << 1];
            ny = loc->u0.pair.field_2 + ((s16 *)Stg40_DirOffsets)[((d + 1) << 1) | 1];
        }
    }
    if (Dung_StatePtr->status.statusFlags & 1) {
        return 1;
    }
    if (nx != -1) {
        Stg40Ent48 *te = Stg40_FindEntAt(nx, ny);
        Stg40B60 *b = Stg40_RootState;

        b->targetEnt = te;
        b->targetActor = te->actor;
    }
    loc->prevTile.field_0 = loc->u0.pair.field_0;
    loc->prevTile.field_2 = loc->u0.pair.field_2;
    tbl = (s16 *)Stg40_DirOffsets;
    loc->u0.pair.field_0 += tbl[(s16)oct << 1];
    loc->u0.pair.field_2 += tbl[((s16)oct << 1) | 1];
    loc->moveFrames = 0xC;
    loc->moveFramesLeft = 0xC;
    dir = loc->prevTile.field_2;
    Stg40_ClearCellOccupied(loc->prevTile.field_0, dir);
    Stg40_SetCellOccupied(loc->u0.pair.field_0, loc->u0.pair.field_2, 1);
    loc->moving = 1;
    return 1;
}

Stg40Ent48 *Stg40_FindObjAtSameTile(Stg40Ent48 *a0) {
    DungState *b = Dung_StatePtr;
    Stg40Ent48 *e = b->ents;
    Stg40Ent48 *r = NULL;
    s32 i;

    for (i = 0; i < b->entCount; i++, e++) {
        if ((e->flags & 0x8000) && e != a0 && e->loc.u0.tileXY == a0->loc.u0.tileXY) {
            r = e;
            break;
        }
    }
    return r;
}

s32 Stg40_PlayerCheckStepHazard(Actor *task) {
    Stg40ActWork *w = (Stg40ActWork *)task->work;
    Stg40Ent48 *ent = w->ent;
    Stg40Ent48 *other;
    GameState *gs;
    u16 dir;
    s32 n;
    s32 hp;
    s32 state;
    s32 ret;
    Actor *child;

    ret = 0;
    if ((u32)((dir = Stg40_GetCellFlags(ent->loc.u0.pair.field_0, ent->loc.u0.pair.field_2) & 0xF) - 8) < 5) {
        n = dir - 7;
        if (Stg40_GetPartLevel(5) < n) {
            n *= 50;
            gs = Save_GameStatePtr;
            hp = gs->hp - n;
            if (hp < 0) {
                hp = ret;
            }
            gs->hp = hp;
            Task_SetState1(task, 0xD);
            return 1;
        }
    }
    other = Stg40_FindObjAtSameTile(ent);
    if (other != NULL) {
        child = other->actor;
        Stg40_RootState->targetActor = child;
        Stg40_RootState->targetEnt = other;
        switch (other->kind) {
        default:
            break;
        case 8:
            Task_SetState1(task, 0x16);
            ret = 1;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            Task_SetState1(task, 0x10);
            ret = 1;
            break;
        }
    }
    return ret;
}

s32 Stg40_PlayerCheckTileEvent(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;
    s32 r = 0;
    Stg40Ent48 *f;
    Stg40B60 *b;
    Actor *t;

    if (Stg40_CheckEventTile()) {
        Task_SetState1(a0, 0x1E);
        return 1;
    }
    f = Stg40_FindObjAtSameTile(e);
    if (f == NULL) {
        return 0;
    }
    t = f->actor;
    b = Stg40_RootState;
    b->targetActor = t;
    b->targetEnt = f;
    switch (f->kind) {
    case 2:
    case 3:
        Dung_StatePtr->transitionReq = (f->kind != 2) ? 3 : 2;
        Task_SetState1(a0, 0x17);
        r = 1;
        break;
    }
    return r;
}

s32 Stg40_PlayerCheckSporeBounce(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;
    Stg40Loc *l = &e->loc;
    s32 r = 0;
    s16 t;

    if (l->moveFramesLeft == l->moveFrames / 2 && (l->moveFlags & 1)) {
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        t = e->loc.u0.pair.field_0;
        e->loc.u0.pair.field_0 = e->loc.prevTile.field_0;
        e->loc.prevTile.field_0 = t;
        t = e->loc.u0.pair.field_2;
        e->loc.u0.pair.field_2 = e->loc.prevTile.field_2;
        e->loc.prevTile.field_2 = t;
        e->loc.moveFramesLeft = 0xC;
        e->loc.moveFrames = 0x18;
        Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 1);
        Task_SetState1(a0, 0xF);
        r = -1;
    }
    return r;
}

void Stg40_PlayerWaitTurn(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;

    Stg40_ObjSetAnimIfNew(a0, 0x28);
    if (Stg40_TurnQueueCurrent() == e->turnId) {
        Stg40_ScrollFollow(&e->loc);
        if (Stg40_CheckEncounter()) {
            Task_SetState1(a0, 4);
        } else {
            Task_SetState1(a0, 1);
        }
    }
}

void Stg40_PlayerMoveStep(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_ObjSetAnimIfNew(a0, 0x29);
    if (e->loc.moveFramesLeft == 0xB) {
        Snd_PlayById(0x2C, 0);
    }
    if (Stg40_PlayerCheckSporeBounce(a0) != 0) {
        return;
    }
    if (w->ent->loc.moveFramesLeft >= 2) {
        return;
    }
    Save_GameStatePtr->mp = (Save_GameStatePtr->mp - 1 < 0) ? 0 : (u16)Save_GameStatePtr->mp - 1;
    if (Stg40_PlayerCheckStepHazard(a0) != 0) {
        return;
    }
    if (Stg40_TickStatusEffects(a0)) {
        Task_SetState1(a0, 8);
        return;
    }
    if (Flag_Test(0x68) && Save_GameStatePtr->mp == 0) {
        Save_GameStatePtr->mp = 1;
    }
    if (Save_GameStatePtr->mp == 0 || Save_GameStatePtr->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (Stg40_PlayerCheckTileEvent(a0) == 0) {
        Task_SetState1(a0, 3);
    }
}

void Stg40_PlayerMoveEnd(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    if (Stg40_TurnQueueNext() == e->turnId) {
        if (Stg40_PlayerTryMove(w->ent) == 1) {
            Task_SetState1(a0, 2);
        } else {
            Task_SetState1(a0, 0);
        }
    } else if (Stg40_CheckEncounter()) {
        Task_SetState1(a0, 4);
    } else {
        Task_SetState1(a0, 0);
    }
}

void Stg40_PlayerAfterAction(Actor *a0) {
    if (Stg40_TickStatusEffects(a0)) {
        Task_SetState1(a0, 8);
    } else {
        Task_SetState1(a0, 7);
    }
}

void Stg40_PlayerEndTurn(Actor *a0) {
    if (Flag_Test(0x68) && Save_GameStatePtr->mp == 0) {
        Save_GameStatePtr->mp = 1;
    }
    if (Save_GameStatePtr->mp == 0 || Save_GameStatePtr->hp == 0) {
        Task_SetState1(a0, 0x1C);
    } else if (Stg40_PlayerCheckTileEvent(a0) == 0) {
        Stg40_TurnQueueNext();
        Task_SetState1(a0, 0);
        if (Stg40_CheckEncounter()) {
            Task_SetState1(a0, 4);
        }
    }
}

void Stg40_PlayerShowStatusMsgs(Actor *a0) {
    Stg40B60 *b = Stg40_RootState;
    s32 arg = 0;
    s32 k;

    if (b->statusCount == 0) {
        Task_SetState1(a0, 7);
        return;
    }
    b->statusCount--;
    k = b->statusCodes[b->statusCount];
    if (k >= 2 && k < 6) {
        arg = (s32)Save_GameStatePtr->beetleName;
    }
    if (k == 6) {
        arg = b->brokenPartText;
    }
    if (k == 7) {
        arg = (s32)b->lostDigiName;
    }
    Stg40_PlayerShowMsg(a0, 0x28, 8, Stg40_StatusMsgIds[k], arg, 0);
}

void Stg40_PlayerInput(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    s32 v;
    s32 n;

    Stg40_ObjSetAnimIfNew(a0, 0x28);
    if (Dung_StatePtr->freeze != 0) {
        return;
    }
    if (Pad_State[0].circle > 0 && Stg40_RootTask->stateLevel0 == 1 && Stg40_RootTask->stateLevel1 == 1 && Stg40_RootTask->stateLevel2 == 1) {
        Task_SetState1(Stg40_RootTask, 4);
        Dung_StatePtr->freeze = 1;
        return;
    }
    if (Stg40_PlayerTryMove(w->ent) == 1) {
        if (Dung_StatePtr->status.statusFlags & 1) {
            Stg40_PlayerShowMsg(a0, 0x28, 6, 0x1FD001D, 0, 0);
        } else {
            Task_SetState1(a0, 2);
        }
        return;
    }
    if (Stg40_PlayerInteract(a0) == 0 && Stg40_PlayerCheckEnemyInfo(a0) == 0 && Beetle_GetPart(0x12) > 0 && Pad_State[0].select > 0) {
        v = Save_GameStatePtr->automapMode + 1;
        n = (v < 3) ? v : 0;
        Save_GameStatePtr->automapMode = n;
        Stg40_RootState->automapMode = Save_GameStatePtr->automapMode;
    }
}

void Stg40_PlayerResumeAfterBattle(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2D);
        Task_SetState2(a0, 1);
        break;
    case 1:
        if (Stg40_ObjAnimDone(a0) == 1) {
            Task_SetState2(a0, 2);
        }
        break;
    case 2:
        if (Dung_StatePtr->freeze == 0) {
            if (Stg40_TurnQueueCurrent() == e->turnId) {
                Task_SetState1(a0, 1);
            } else {
                Task_SetState1(a0, 0);
            }
        }
        break;
    }
}

void Stg40_PlayerAnimThenMsgUpdate(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            if (Stg40_RootState->msgAnim != -1) {
                Stg40_ObjSetAnim(a0, Stg40_RootState->msgAnim);
            }
            Stg40_MsgWinOpen(1, Stg40_RootState->msgId, Stg40_RootState->msgArg0, Stg40_RootState->msgArg1);
            Task_NextState2(a0);
        }
        break;
    case 1:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, (u8)Stg40_RootState->msgNextState);
        }
        break;
    }
}

void Stg40_PlayerWaitAnim(Actor *a0) {
    if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
        Task_SetState1(a0, (u8)Stg40_RootState->msgNextState);
    }
}

void Stg40_PlayerWaitMsg(Actor *a0) {
    if (Stg40_MsgWinCloseIfDone(1) == 1) {
        Task_SetState1(a0, (u8)Stg40_RootState->msgNextState);
    }
}

void Stg40_PlayerFoundObject(Actor *a0) {
    Stg40B60 *b = Stg40_RootState;
    Stg40Ent48 *e = b->targetEnt;
    Actor *t = b->targetActor;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        Stg40_ObjSetAnim(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Task_SetState1(t, 5);
            Stg40_MsgWinOpen(1, 0x1FD0010, (s32)Cd_GetFileEntry(e->kind + 0x1FD0064), 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerHurtAnim(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2F, 0);
        Stg40_ObjSetAnim(a0, 0x2C);
        Stg40_ObjStartFlash(a0, 1);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjAnimDone(a0) == 1 || a0->stateLevel4++ >= 11) {
            Stg40_ObjSetAnim(a0, 0x28);
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerDestroyMine(Actor *a0) {
    Stg40Ent48 *e = Stg40_RootState->targetEnt;
    Actor *t = Stg40_RootState->targetActor;
    s32 msg;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2A);
        Snd_PlayById(0x2E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            r = Beetle_GetPart(6);
            n = e->params[1];
            if (Item_GetLevel(r) >= n) {
                Task_SetState1(t, 6);
                msg = 0x1FD0017;
            } else {
                msg = 0x1FD0018;
            }
            Stg40_MsgWinOpen(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerSporeDamage(Actor *a0) {
    Stg40Ent48 *e = Stg40_RootState->targetEnt;
    Actor *t = Stg40_RootState->targetActor;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2C);
        Stg40_ObjStartFlash(a0, 2);
        Task_SetState1(t, 4);
        Stg40_RootState->damage = e->params[1] * 200;
        Stg40_DamageBeetle(Stg40_RootState->damage);
        Snd_PlayById(0x33, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Stg40_MsgWinOpen(1, 0x1FD001F, (s32)Save_GameStatePtr->beetleName, (s32)Stg40_NumToDigits(0, Stg40_RootState->damage));
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerBugInvade(Actor *arg0)
{
    Stg40Ent48 *e;
    Actor *t;
    s32 idx;
    s32 bit;
    s32 r;
    s32 n;

    e = Stg40_RootState->targetEnt;
    t = Stg40_RootState->targetActor;
    idx = e->kind - 9;
    bit = 0x100 << idx;
    switch (arg0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(arg0, 0x28);
        Task_SetState1(t, 4);
        Task_NextState2(arg0);
        break;
    case 1:
        if (t->stateLevel1 != 1) {
            return;
        }
        r = 0;
        switch (e->kind) {
        default:
            if (Dung_StatePtr->status.bugLevels[idx] == 0) {
                Dung_StatePtr->status.bugLevels[idx] = e->params[1];
                r = -1;
            }
            break;
        case 9:
            if (Dung_StatePtr->status.bugLevels[0] == 0) {
                if (Save_GameStatePtr->bits != 0 || Stg40_PickRandomPart() != -1) {
                    r = -1;
                    Dung_StatePtr->status.bugLevels[e->kind - 9] = e->params[1];
                }
            }
            break;
        case 0xB:
            if (Dung_StatePtr->status.bugLevels[2] != 0 || ((s32 (*)(s32))Stg40_ListPartyDigi)(1) < 2 || Digi_CountByState(1) >= 0x18) {
                r = 0;
            } else {
                r = -1;
                Dung_StatePtr->status.bugLevels[e->kind - 9] = e->params[1];
            }
            break;
        case 0xC:
            n = ((s32 (*)(void))Beetle_GetDigiCapacity)();
            n -= ((s32 (*)(s32))Stg40_ListPartyDigi)(0);
            if (n != Dung_StatePtr->status.memBugCount) {
                Dung_StatePtr->status.memBugLevels[Dung_StatePtr->status.memBugCount] = e->params[1];
                r = -1;
                Dung_StatePtr->status.memBugCount++;
            }
            break;
        }
        if (r == 0) {
            Stg40_MsgWinOpen(1, e->kind + 0x1FD0022, (s32)Save_GameStatePtr + 0xD1, 0);
            Task_SetState2(arg0, 3);
        } else {
            Dung_StatePtr->status.statusFlags &= ~bit;
            Stg40_ObjSetAnim(arg0, 0x2A);
            Stg40_ObjStartFlash(arg0, 2);
            Task_NextState2(arg0);
            Snd_PlayById(0x2F, 0);
        }
        break;
    case 2:
        if (Stg40_ObjWaitAnimOrSkip(arg0) == 1) {
            Stg40_ObjSetAnim(arg0, 0x28);
            Stg40_MsgWinOpen(1, e->kind + 0x1FD001E, 0, 0);
            Task_NextState2(arg0);
        }
        break;
    case 3:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(arg0, 6);
        }
        break;
    }
}

void Stg40_PlayerEnemyInfo(Actor *a0) {
    Stg40Ent48 *e = ((Stg40ActWork *)a0->work)->ent;
    Stg40B60 *g = Stg40_RootState;
    Stg40Ent48 *t;
    s32 r;
    s32 n;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_Create(0x20C, &Stg40_RootChildren->enemyInfoTask, 0);
        Stg40_ObjSetAnim(a0, 0x28);
        Task_NextState2(a0);
        break;
    case 1:
        t = g->enemyList[g->enemyIndex];
        g->targetActor = t->actor;
        g->targetEnt = t;
        Stg40_ScrollToFollow(&t->loc, 0x10);
        Task_SetState0((Actor *)Stg40_RootChildren->enemyInfoTask, 2);
        Task_SetState1((Actor *)Stg40_RootChildren->enemyInfoTask, 0x64);
        Task_NextState2(a0);
        break;
    case 2:
        if (a0->stateLevel3 == 0) {
            if (Stg40_IsScrollDone() != 0) {
                Snd_PlayById(0x12, 0);
                Task_SetState3(a0, 1);
            }
        }
        if (Pad_State[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 0x64);
        } else if (Pad_State[0].square > 0 && Stg40_RootState->enemyCount >= 2) {
            n = Stg40_RootState->enemyIndex + 1;
            Stg40_RootState->enemyIndex = (n < Stg40_RootState->enemyCount) ? n : 0;
            Task_SetState2(a0, 1);
        } else if (Pad_State[0].cross > 0) {
            r = Stg40_ListUsableItems(&Stg40_GiftGunReq);
            if (r != 0) {
                Stg40_MsgWinOpen(1, r, 0, 0);
                Task_SetState2(a0, 0x3C);
            } else {
                Task_SetState1(a0, 0x11);
                Stg40_RootState->giftMenu = 1;
                Stg40_RootState->selItem = Stg40_RootState->itemIds[0];
            }
        }
        break;
    case 0x3C:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState2(a0, 2);
            Task_SetState3(a0, 1);
        }
        break;
    case 0x64:
        Stg40_ScrollFollow(&e->loc);
        Task_SetState0((Actor *)Stg40_RootChildren->enemyInfoTask, 2);
        Task_NextState2(a0);
        break;
    case 0x65:
        if (Stg40_RootChildren->enemyInfoTask == 0) {
            g->automapMode = Save_GameStatePtr->automapMode;
            Task_SetState1(a0, 1);
        }
        break;
    }
}

void Stg40_PlayerShootGift(Actor *actor) {
    s32 state = actor->stateLevel2;
    Stg40Ent48 *self = ((Stg40ActWork *)actor->work)->ent;
    Stg40Ent48 *target = Stg40_RootState->targetEnt;
    Stg40Loc *loc = &Stg40_RootState->shotLoc;

    switch (state) {
    case 0:
    default: {
        s32 angle;

        Stg40_ObjSetAnim(actor, 0x29);
        angle = ratan2(self->loc.posX - target->loc.posX,
                       target->loc.posY - self->loc.posY);
        Stg40_RootState->shotAngle = angle & 0xFFF;
        Stg40_RootState->shotStepX = -rsin(Stg40_RootState->shotAngle);
        Stg40_RootState->shotStepY = rcos(Stg40_RootState->shotAngle);
        Stg40_RootState->shotX = self->loc.u0.pair.field_0 << 14;
        Stg40_RootState->shotY = self->loc.u0.pair.field_2 << 14;
        Stg40_RootState->shotTargetX = target->loc.u0.pair.field_0 << 14;
        Stg40_RootState->shotTargetY = target->loc.u0.pair.field_2 << 14;
        Task_NextState2(actor);
        break;
    }
    case 1:
        if ((s16)self->targetHeading != Stg40_RootState->shotAngle) {
            s32 h = (s16)self->targetHeading;
            s32 diff = (s16)((u16)Stg40_RootState->shotAngle - ((u16)self->targetHeading - 0x1000));
            s32 d;
            s32 t;

            if (diff < 0) {
                diff += 0x7FF;
            }
            if ((diff >> 11) & 1) {
                self->targetHeading = h - 0x40;
            } else {
                self->targetHeading = h + 0x40;
            }
            t = self->targetHeading & 0xFFF;
            self->targetHeading = t;
            d = Stg40_RootState->shotAngle - t;
            if ((d >= 0) ? (d < 0x40) : (t - Stg40_RootState->shotAngle < 0x40)) {
                self->targetHeading = Stg40_RootState->shotAngle;
            }
            self->heading = self->targetHeading;
        } else {
            Stg40_ObjSetAnim(actor, 0x28);
            goto next;
        }
        break;
    case 2:
        if (actor->stateLevel4++ < 0x10) {
            break;
        }
        Snd_PlayById(0x2D, 0);
        Stg40_ObjSetAnim(actor, 0x2A);
        goto next;
    case 3:
        if (actor->stateLevel4++ < 6) {
            break;
        }
        goto next;
    case 4: {
        s32 ax;
        s32 ay;

        Stg40_RootState->shotX += Stg40_RootState->shotStepX;
        Stg40_RootState->shotY += Stg40_RootState->shotStepY;
        loc->posX = Stg40_RootState->shotX >> 8;
        loc->posY = Stg40_RootState->shotY >> 8;
        Stg40_ScrollFollow(loc);
        ax = Stg40_RootState->shotStepX;
        ax = (ax >= 0) ? ax : -ax;
        if ((Stg40_RootState->shotTargetX - Stg40_RootState->shotX >= 0)
                ? (ax >= Stg40_RootState->shotTargetX - Stg40_RootState->shotX)
                : (ax >= Stg40_RootState->shotX - Stg40_RootState->shotTargetX)) {
            ay = Stg40_RootState->shotStepY;
            ay = (ay >= 0) ? ay : -ay;
            if ((Stg40_RootState->shotTargetY - Stg40_RootState->shotY >= 0)
                    ? (ay >= Stg40_RootState->shotTargetY - Stg40_RootState->shotY)
                    : (ay >= Stg40_RootState->shotY - Stg40_RootState->shotTargetY)) {
                Stg40_ScrollFollow(&target->loc);
                Task_NextState2(actor);
                Snd_PlayById(0x1B, 0);
            }
        }
        break;
    }
    case 5: {
        Stg40EnemyParty *info;
        s32 msg;

        if (actor->stateLevel4++ < 0x1F) {
            break;
        }
        info = (Stg40EnemyParty *)target->params;
        msg = 0x1FD0050;
        if (info->giftsTaken < 9) {
            s32 r = Item_GetCategory(Stg40_RootState->selItem);
            s32 kind;

            if (r >= 0x25) {
                kind = 3;
            } else if (r >= 0x22) {
                kind = 0x22;
                kind = r - kind;
            } else {
                kind = 3;
            }
            if (kind == 3 || kind == info->likedGift) {
                if (Stg40_RandPercent() < Stg40_GiftTakeChance[info->giftsTaken]) {
                    s32 idx;

                    info->giftsTaken++;
                    idx = Item_GetLevel(Stg40_RootState->selItem);
                    msg = 0x1FD004F;
                    info->giftPoints += Stg40_GiftPointsByLevel[idx - 1];
                }
            }
        }
        Stg40_MsgWinOpen(1, msg, Digi_GetDefaultName(info->digiIds[0]),
                      Item_GetNameText(Stg40_RootState->selItem));
        goto next;
    }
    case 6:
        if (Stg40_MsgWinCloseIfDone(1) != 1) {
            break;
        }
        Stg40_ScrollToFollow(&self->loc, 8);
        Task_SetState0((Actor *)Stg40_RootChildren->enemyInfoTask, 2);
    next:
        Task_NextState2(actor);
        break;
    case 7:
        if (Stg40_RootChildren->enemyInfoTask == 0) {
            break;
        }
        Task_SetState1(actor, 6);
        Stg40_RootState->automapMode = Save_GameStatePtr->automapMode;
        break;
    }
}

void Stg40_PlayerChestTrapPrompt(Actor *a0) {
    u8 *d = Stg40_RootState->targetEnt->params;
    s32 r;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x2E, 0);
        Stg40_ObjSetAnim(a0, 0x2D);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (d[1] == 0) {
            Task_SetState1(a0, 0x14);
        } else {
            Stg40_RootState->trapDisarmRank = Stg40_GetTrapDisarmRank(d[1]);
            r = Stg40_GetPartState(7);
            msg = Stg40_RootState->trapDisarmRank + 0x1FD0040;
            if (r == -1) {
                msg = 0x1FD0045;
            }
            if (r == 0) {
                msg = 0x1FD0046;
            }
            Stg40_MsgWinOpen(1, msg, 0, 0);
            Task_NextState2(a0);
        }
        break;
    case 3:
        switch (Stg40_MsgWinGetChoice(1)) {
        case -1:
            Task_SetState1(a0, 6);
            break;
        case 1:
            Task_SetState1(a0, 0x14);
            break;
        }
        break;
    }
}

void Stg40_PlayerOpenChest(Actor *a0) {
    Stg40B60 *b = Stg40_RootState;
    Actor *t = b->targetActor;
    u8 *d = b->targetEnt->params;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Task_SetState1(t, 4);
        Task_NextState2(a0);
        break;
    case 1:
        if (t->stateLevel1 == 3) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (d[1] == 0 || d[1] == 0xFF) {
            Task_SetState1(a0, 0x15);
        } else if (Stg40_RollTrapDisarm(b->trapDisarmRank) == 1) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 0x16);
        }
        break;
    }
}

void Stg40_PlayerTakeChestItem(Actor *a0) {
    Actor *t = Stg40_RootState->targetActor;
    u8 *d = Stg40_RootState->targetEnt->params;

    switch (a0->stateLevel2) {
    case 0:
    default:
        if (d[0] == 0) {
            Stg40_MsgWinOpen(1, 0x1FD004E, 0, 0);
            Task_SetState1(t, 5);
        } else if (Item_AddToBag(d[0]) == -1) {
            Stg40_MsgWinOpen(1, 0x1FD0055, Item_GetNameText(d[0]), 0);
            d[1] = 0xFF;
            Snd_PlayById(0x1C, 0);
        } else {
            Stg40_MsgWinOpen(1, 0x1FD004D, Item_GetNameText(d[0]), 0);
            Task_SetState1(t, 5);
            Snd_PlayById(0x19, 0);
            Item_SortList();
        }
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

void Stg40_PlayerTriggerTrap(Actor *a0) {
    Stg40Ent48 *e = Stg40_RootState->targetEnt;
    Actor *t = Stg40_RootState->targetActor;
    s32 nc = e->kind != 4;
    u8 *d = e->params;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_RootState->trapEffect = Stg40_RollTrapEffect();
        if (Stg40_RootState->trapEffect != 0x10) {
            Stg40_ObjSetAnim(a0, 0x2C);
            Stg40_ObjStartFlash(a0, 1);
            Stg40_ApplyTrapEffect(Stg40_RootState->trapEffect, d[1]);
        }
        if (nc) {
            Task_SetState1(t, 4);
        }
        ((Stg40ActWork *)a0->work)->pendingLinkedModel = d[1] + 1;
        Snd_PlayById(0x34, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            Stg40_ShowTrapEffectMsg(nc, Stg40_RootState->trapEffect);
            Task_NextState2(a0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_NextState2(a0);
        }
        break;
    case 3:
        Task_NextState2(a0);
        break;
    case 4:
        if (nc == 0) {
            Task_SetState1(a0, 0x15);
        } else {
            Task_SetState1(a0, 6);
        }
        break;
    }
}

const Stg40Col Stg40_PlayerExitFadeColor = { 0x80, 0x80, 0x80, 0 };
void Stg40_PlayerExitFloor(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    Stg40ModelFade *m = (Stg40ModelFade *)a0->model;
    s32 v;
    switch (a0->stateLevel2) {
        case 0:
        default:
        {
            u8 k = Dung_StatePtr->transitionReq;
            if (k == 2) {
                Snd_PlayById(0x23, 0);
                w->pendingLinkedModel = 0;
            } else {
                if (k == 3)
                    Snd_PlayById(0x18, 0);
                else
                    Snd_PlayById(0x1F, 0);
                w->pendingLinkedModel = 1;
            }
            m->clutRow = 1;
            m->tpageFlags = 0x20;
            m->fadeColor = Stg40_PlayerExitFadeColor;
            Stg40_ObjSetAnim(a0, 0x28);
            e->flags |= 0x80;
            w->flashKind = 0;
            Task_NextState2(a0);
            break;
        }
        case 1:
            if (a0->stateLevel3++ >= 0x3C) {
                Gfx_FadeOutToBlack(8);
                Task_NextState2(a0);
            }
            break;
        case 2:
            break;
    }

    v = e->scaleX - 0x51;
    if (v < 0) {
        v = 0;
    }
    e->scaleX = v;
    e->scaleZ = v;
    if (m->fadeColor.r != 0xFF) {
        m->fadeColor.r++;
        m->fadeColor.g++;
        m->fadeColor.b++;
    }
}

void Stg40_PlayerShootObstacle(Actor *a0) {
    Stg40Ent48 *e = Stg40_RootState->targetEnt;
    Actor *t = Stg40_RootState->targetActor;
    s32 k = e->kind - 6;
    s32 msg;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x2A);
        Snd_PlayById(k < 3 ? 0x2D : 0x1E, 0);
        Task_NextState2(a0);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
            Stg40_ObjSetAnim(a0, 0x28);
            if (Item_GetLevel(Stg40_RootState->selItem) >= e->params[1]) {
                Task_SetState1(t, 6);
                msg = Stg40_ShootMsgIds[k * 2];
                Task_SetState2(a0, 3);
            } else {
                msg = Stg40_ShootMsgIds[k * 2 + 1];
                Task_NextState2(a0);
            }
            Stg40_MsgWinOpen(1, msg, 0, 0);
        }
        break;
    case 2:
        if (Stg40_MsgWinCloseIfDone(1) == 1) {
            Task_SetState1(a0, 6);
            Stg40_RootState->automapMode = Save_GameStatePtr->automapMode;
        }
        break;
    case 3:
        if (Stg40_MsgWinCloseIfDone(1) == 1 && e->flags == 0) {
            Task_SetState1(a0, 6);
            Stg40_RootState->automapMode = Save_GameStatePtr->automapMode;
        }
        break;
    }
}

void Stg40_ItemMenuRefresh(void) {
    s32 s3;
    s32 s0;
    s32 s1;
    s32 e1;
    s32 e3;
    s32 v1;
    s32 *dst;
    s32 *p;

    s3 = 0;
    s0 = Stg40_RootState->cursor - Stg40_RootState->scrollTop;
    dst = Stg40_ItemMenuGetTextIds();
    p = dst;
    if (s0 >= 6) {
        Stg40_RootState->scrollTop = Stg40_RootState->cursor - 5;
    }
    if (s0 < 0) {
        Stg40_RootState->scrollTop = Stg40_RootState->cursor;
    }
    e1 = Stg40_RootState->itemCount;
    e3 = Stg40_RootState->scrollTop;
    s1 = e1;
    v1 = e3 + 6;
    if (s1 >= v1) {
        s1 = v1;
    }
    s0 = e3;
    while (s0 < s1) {
        *p = Item_GetNameText(Stg40_RootState->itemIds[s0]);
        s0++;
        p++;
    }
    s3 |= Stg40_RootState->scrollTop != 0;
    if (s1 < Stg40_RootState->itemCount) {
        s3 |= 2;
    }
    Stg40_ItemMenuSetCursor(Stg40_RootState->cursor - Stg40_RootState->scrollTop, s1 - Stg40_RootState->scrollTop, s3);
    dst[6] = Item_GetDescText(Stg40_RootState->itemIds[Stg40_RootState->cursor]);
    s1 = e1;
}

void Stg40_ItemMenuMoveCursor(void) {
    s32 old = Stg40_RootState->cursor;
    s32 n;

    if (Pad_State[0].repeat & 0x1000) {
        if (old != 0) {
            Stg40_RootState->cursor = old - 1;
        }
    }
    if (Pad_State[0].repeat & 0x4000) {
        n = Stg40_RootState->cursor + 1;
        if (n < Stg40_RootState->itemCount) {
            Stg40_RootState->cursor = n;
        }
    }
    if (old != Stg40_RootState->cursor) {
        Snd_PlayById(Stg40_RootState->giftMenu ? 0xD : 0xC, 0);
        Stg40_ItemMenuRefresh();
    }
}

void Stg40_PlayerItemMenu(Actor *a0) {
    s32 arg;
    s32 i;
    u16 *bag;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_RootState->cursor = 0;
        Stg40_RootState->scrollTop = 0;
        Stg40_ObjSetAnim(a0, 0x28);
        arg = Stg40_RootState->giftMenu != 0;
        Task_Create(0x20B, &Stg40_RootChildren->itemMenuTask, (s32)&arg);
        Snd_PlayById(0x37, 0);
        Stg40_ItemMenuRefresh();
        Task_NextState2(a0);
        break;
    case 1:
        if (a0->stateLevel3++ >= 9) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        Stg40_ItemMenuMoveCursor();
        if (Pad_State[0].triangle > 0) {
            Snd_PlayById(0xB, 0);
            Task_SetState2(a0, 4);
        } else if (Pad_State[0].cross > 0) {
            Stg40_RootState->selItem = Stg40_RootState->itemIds[Stg40_RootState->cursor];
            for (i = 0, bag = Save_GameStatePtr->bagItems; i < 0x30; i++, bag++) {
                if (*bag == Stg40_RootState->selItem) {
                    *bag = 0;
                    Item_CompactBag();
                    break;
                }
            }
            if (Stg40_RootState->giftMenu != 0) {
                Stg40_ScrollToFollow(&((Stg40ActWork *)a0->work)->ent->loc, 8);
                Snd_PlayById(0xE, 0);
            } else {
                Snd_PlayById(0xA, 0);
            }
            Task_NextState2(a0);
        }
        if (a0->stateLevel2 != 2) {
            Task_SetState0((Actor *)Stg40_RootChildren->itemMenuTask, 2);
        }
        break;
    case 3:
        if (Stg40_RootChildren->itemMenuTask == 0) {
            if (Stg40_RootState->giftMenu == 0) {
                Task_SetState1(a0, 0x12);
            } else {
                Task_SetState1(a0, 0x1B);
            }
        }
        break;
    case 4:
        if (Stg40_RootChildren->itemMenuTask == 0) {
            if (Stg40_RootState->giftMenu == 0) {
                Task_SetState1(a0, 1);
                Stg40_RootState->automapMode = Save_GameStatePtr->automapMode;
            } else {
                Task_SetState1(a0, 0x1A);
                Task_SetState2(a0, 2);
                Task_SetState3(a0, 1);
            }
        }
        break;
    }
}

void Stg40_PlayerBeetleDown(Actor *a0) {
    s32 r;

    switch (a0->stateLevel2) {
    case 0:
    default:
        Snd_PlayById(0x30, 1);
        Stg40_ObjSetAnim(a0, 0x2B);
        break;
    case 1:
        if (Stg40_ObjWaitAnimOrSkip(a0) != 1) {
            return;
        }
        Stg40_MsgWinOpen(1, 0x1FD0054, (s32)Save_GameStatePtr->beetleName, 0);
        break;
    case 2:
        r = Stg40_MsgWinCloseIfDone(1);
        if (r != 1) {
            return;
        }
        Dung_StatePtr->transitionReq = 3;
        Dung_StatePtr->beetleDown = r;
        Snd_PlayById(0x1F, 0);
        break;
    case 3:
        if (a0->stateLevel3++ < 30) {
            return;
        }
        Gfx_FadeOutToBlack(0x10);
        break;
    case 4:
        return;
    }
    Task_NextState2(a0);
}

void Stg40_PlayerRunEvent(Actor *a0) {
    switch (a0->stateLevel2) {
    case 0:
    default:
        Stg40_ObjSetAnim(a0, 0x28);
        Stg40_RootState->cmdDigiId = 0;
        Stg40_RootState->eventText = -1;
        Text_OpenMsgClearChoice(&Stg40_RootState->eventText, Flag_SelectBranch(Stg40_RootState->eventEntry));
        Task_NextState2(a0);
        break;
    case 1:
        if (Text_IsFinished(Stg40_RootState->eventText)) {
            Task_NextState2(a0);
        }
        break;
    case 2:
        Stg40_TurnQueueNext();
        Task_SetState1(a0, 0);
        if (Stg40_CheckEncounter()) {
            Task_SetState1(a0, 4);
        } else {
            Dung_StatePtr->freeze = 0;
        }
        break;
    }
}

void Stg40_PlayerUpdate(Actor *a0) {
    Stg40Ent48 *e;

    Stg40_SetCellOccupied(((Stg40ActWork *)a0->work)->ent->loc.u0.pair.field_0, ((Stg40ActWork *)a0->work)->ent->loc.u0.pair.field_2, 1);
    switch (a0->stateLevel1) {
    case 0:
    case 24:
    case 25:
    default:
        Stg40_PlayerWaitTurn(a0);
        break;
    case 1:
        Stg40_PlayerInput(a0);
        break;
    case 2:
        Stg40_PlayerMoveStep(a0);
        break;
    case 3:
        Stg40_PlayerMoveEnd(a0);
        break;
    case 6:
        Stg40_PlayerAfterAction(a0);
        break;
    case 7:
        Stg40_PlayerEndTurn(a0);
        break;
    case 8:
        Stg40_PlayerShowStatusMsgs(a0);
        break;
    case 4:
        if (a0->stateLevel2 != 1) {
            Dung_StatePtr->transitionReq = 1;
            Dung_StatePtr->freeze = 1;
            Task_NextState2(a0);
        }
        break;
    case 5:
        Stg40_PlayerResumeAfterBattle(a0);
        break;
    case 9:
        Stg40_PlayerAnimThenMsgUpdate(a0);
        break;
    case 10:
        Stg40_PlayerWaitAnim(a0);
        break;
    case 11:
        Stg40_PlayerWaitMsg(a0);
        break;
    case 12:
        Stg40_PlayerFoundObject(a0);
        break;
    case 13:
        Stg40_PlayerHurtAnim(a0);
        break;
    case 14:
        Stg40_PlayerDestroyMine(a0);
        break;
    case 15:
        Stg40_PlayerSporeDamage(a0);
        break;
    case 16:
        Stg40_PlayerBugInvade(a0);
        break;
    case 19:
        Stg40_PlayerChestTrapPrompt(a0);
        break;
    case 20:
        Stg40_PlayerOpenChest(a0);
        break;
    case 21:
        Stg40_PlayerTakeChestItem(a0);
        break;
    case 22:
        Stg40_PlayerTriggerTrap(a0);
        break;
    case 23:
        Stg40_PlayerExitFloor(a0);
        break;
    case 18:
        Stg40_PlayerShootObstacle(a0);
        break;
    case 17:
        Stg40_PlayerItemMenu(a0);
        break;
    case 26:
        Stg40_PlayerEnemyInfo(a0);
        break;
    case 27:
        Stg40_PlayerShootGift(a0);
        break;
    case 28:
        Stg40_PlayerBeetleDown(a0);
        break;
    case 30:
        Stg40_PlayerRunEvent(a0);
        break;
    case 29:
        break;
    }
    e = ((Stg40ActWork *)a0->work)->ent;
    Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->loc.prevTile.field_0, e->loc.prevTile.field_2, e->kind);
}
