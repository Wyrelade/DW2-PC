#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/floor.h"
#include "stag4000/hud.h"
#include "stag4000/bitswin.h"
#include "stag4000/itemmenu.h"
#include "stag4000/enemyinfo.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"
#include "stag4000/stag4000_8338_funcs.h"

void Stg40_GateUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 0);
    if (Stg40_GetCellFlags(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2) & 0x2000) {
        e->flags |= 0x1000;
    }
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, -1, -1, e->kind);
    }
    if (e->kind == 2) {
        Stg40_ObjQueueFiles((Stg40ObjQueueView *)w, 0xDF0, 0xDF1);
    } else {
        Stg40_ObjQueueFiles((Stg40ObjQueueView *)w, 0xDF2, 0xDF3);
    }
    if (a0->stateLevel1 != 1 && (a0->stateLevel1 < 2 || (a0->stateLevel1 != 4 && a0->stateLevel1 != 9))) {
        Task_SetState1(a0, 1);
    }
}

void Stg40_ChestQueueModel(Stg40ObjQueueView *a0, s32 a1) {
    s32 x;
    s32 y;

    switch (a1) {
    case 0:
    default:
        x = 0xDE3;
        y = 0xDE2;
        break;
    case 1:
        x = 0xDE1;
        y = 0xDDE;
        break;
    case 2:
        x = 0xDDF;
        y = 0xDE0;
        break;
    case 3:
        x = 0xDE4;
        y = 0xDE5;
        break;
    case 4:
        x = 0xDDC;
        y = 0xDDD;
        break;
    }
    Stg40_ObjQueueFiles(a0, x, y);
}

s32 Stg40_ChestUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 1);
    if (Stg40_GetCellFlags(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2) & 0x2000) {
        e->flags |= 0x1000;
    }
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, -1, -1, e->kind);
    }
    if (e->params[1] >= 1 && e->params[1] <= 5) {
        Stg40_ChestQueueModel((Stg40ObjQueueView *)w, e->params[1] - 1);
    }
    switch (a0->stateLevel1) {
    case 0:
    default:
        if (e->params[1] == 0xFF) {
            Stg40_ObjSetAnim(a0, 0x29);
        } else {
            Stg40_ObjSetAnim(a0, 0x28);
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        if (e->params[1] == 0xFF) {
            Stg40_ObjSetAnim(a0, 0x29);
        } else {
            Stg40_ObjSetAnim(a0, 0x28);
        }
        break;
    case 2:
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->kind);
        e->flags = 0;
        Task_SetState0(a0, 3);
        break;
    case 3:
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            Stg40_ObjSetAnim(a0, 0x2A);
            Task_NextState2(a0);
            Snd_PlayById(2, 0);
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Stg40_ObjSetAnim(a0, 0x29);
                Task_SetState1(a0, 3);
            }
            break;
        }
        break;
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            if (a0->stateLevel4++ >= 11) {
                Stg40_ObjSetAnim(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 Stg40_MineUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 0);
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, -1, -1, e->kind);
    }
    Stg40_ChestQueueModel((Stg40ObjQueueView *)w, e->params[1] - 1);
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->flags &= ~0x4000;
        if (e->flags & 0x1000) {
            e->flags |= 0x4000;
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->kind);
        e->flags = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->flags |= 0x5000;
            Stg40_ObjSetAnim(a0, 0x28);
            Task_NextState2(a0);
            break;
        case 1:
            if (a0->stateLevel3++ >= 6) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->flags |= 0x5000;
            Stg40_ObjSetAnim(a0, 0x2C);
            Task_NextState2(a0);
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Stg40_ObjSetAnim(a0, 0x28);
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            Stg40_ObjSetAnim(a0, 0x2B);
            Snd_PlayById(0x36, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 Stg40_SporeUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    Stg40Cell *c;

    c = Stg40_GetCell2(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 1);
    c->flags |= 0x10;
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, -1, -1, e->kind);
    }
    e->heading = e->targetHeading += 0x155;
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->flags &= ~0x4000;
        if (e->flags & 0x1000) {
            e->flags |= 0x4000;
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->kind);
        c->flags &= ~0x10;
        e->flags = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->flags |= 0x5000;
            if (a0->stateLevel1 == 4) {
                Stg40_ObjSetAnim(a0, 0x2A);
            } else {
                Stg40_ObjSetAnim(a0, 0x2C);
            }
            Task_NextState2(a0);
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Stg40_ObjSetAnim(a0, 0x28);
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            Stg40_ObjSetAnim(a0, 0x2B);
            Snd_PlayById(0x35, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 Stg40_RockUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 1);
    if (Stg40_GetCellFlags(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2) & 0x2000) {
        e->flags |= 0x1000;
    }
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, -1, -1, e->kind);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        Stg40_ObjSetAnim(a0, 0x28);
        e->flags |= 0x4000;
        Task_SetState1(a0, 1);
        break;
    case 1:
    case 4:
    case 5:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->kind);
        e->flags = 0;
        Task_SetState0(a0, 3);
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            Stg40_ObjSetAnim(a0, 0x2B);
            Snd_PlayById(0x35, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 Stg40_BugUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;

    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 0);
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, -1, -1, e->kind);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->loc.height = 0x2800;
        e->flags = (e->flags & 0x1000) ? (e->flags | 0x4400) : (e->flags & ~0x4000);
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->kind);
        e->flags = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->flags = (e->flags | 0x5000) & ~0x400;
            Stg40_ObjSetAnim(a0, 0x28);
            e->loc.fallSpeed = 0;
            e->loc.height = 0x2800;
            Snd_PlayById(4, 0);
            Task_NextState2(a0);
            break;
        case 1:
            e->loc.fallSpeed += 0x26;
            e->loc.height -= e->loc.fallSpeed;
            if (e->loc.height < 0x500) {
                e->loc.height = 0x500;
                e->loc.fallSpeed = -(e->loc.fallSpeed / 2);
                Task_NextState2(a0);
            }
            break;
        case 2:
            e->loc.fallSpeed += 0x26;
            e->loc.height -= e->loc.fallSpeed;
            if (e->loc.fallSpeed > 0) {
                Stg40_ObjSetAnim(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                e->flags |= 0x400;
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 5:
        e->flags |= 0x5400;
        Task_SetState1(a0, 1);
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->flags = (e->flags | 0x5000) & ~0x400;
            Stg40_ObjSetAnim(a0, 0x28);
            e->loc.fallSpeed = 0;
            e->loc.height = 0x2800;
            Snd_PlayById(5, 0);
            Task_NextState2(a0);
            break;
        case 1:
            e->loc.fallSpeed += 0x26;
            e->loc.height -= e->loc.fallSpeed;
            if (e->loc.height < 0) {
                e->loc.height = 0;
                e->loc.fallSpeed = -(e->loc.fallSpeed / 2);
                Task_NextState2(a0);
            }
            break;
        case 2:
            e->loc.fallSpeed += 0x26;
            e->loc.height -= e->loc.fallSpeed;
            if (e->loc.height < 0) {
                e->loc.height = 0;
                Stg40_ObjSetAnim(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

/* The default case tests field_0 & 0x1000 and returns field_E either way. The test does
 * nothing, but retail's codegen has it: the compiler merges the two identical arms only
 * after register allocation, and that is what leaves `e` in v1 and the branch deleted the
 * way retail has it. Every form without the test allocates differently (see the learnings). */
s32 Stg40_FixtureUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e;

    switch (w->ent->kind) {
    case 5:
    default:
        e = w->ent;
        if (e->flags & 0x1000) {
            return e->targetHeading;
        }
        return e->targetHeading;
    case 6:
        return Stg40_SporeUpdate(a0);
    case 7:
        return Stg40_RockUpdate(a0);
    case 8:
        return Stg40_MineUpdate(a0);
    case 9:
    case 10:
    case 11:
    case 12:
        return Stg40_BugUpdate(a0);
    case 4:
        return Stg40_ChestUpdate(a0);
    case 2:
    case 3:
        return ((s32 (*)(Actor *))Stg40_GateUpdate)(a0);
    }
}
