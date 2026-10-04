#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"
#include "stag4000/stag4000_8338_funcs.h"

void Stg40_GateUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    Stg40_SetCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (Stg40_GetCellFlags(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        Stg40_AutomapMoveMarker(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    if (e->field_8 == 2) {
        Stg40_ObjQueueFiles((Stg40E764 *)w, 0xDF0, 0xDF1);
    } else {
        Stg40_ObjQueueFiles((Stg40E764 *)w, 0xDF2, 0xDF3);
    }
    if (a0->stateLevel1 != 1 && (a0->stateLevel1 < 2 || (a0->stateLevel1 != 4 && a0->stateLevel1 != 9))) {
        Task_SetState1(a0, 1);
    }
}

void Stg40_ChestQueueModel(Stg40E764 *a0, s32 a1) {
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
    Stg40Ent48 *e = w->field_2C;

    Stg40_SetCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    if (Stg40_GetCellFlags(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        Stg40_AutomapMoveMarker(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    if (e->field_10[1] >= 1 && e->field_10[1] <= 5) {
        Stg40_ChestQueueModel((Stg40E764 *)w, e->field_10[1] - 1);
    }
    switch (a0->stateLevel1) {
    case 0:
    default:
        if (e->field_10[1] == 0xFF) {
            Stg40_ObjSetAnim(a0, 0x29);
        } else {
            Stg40_ObjSetAnim(a0, 0x28);
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        if (e->field_10[1] == 0xFF) {
            Stg40_ObjSetAnim(a0, 0x29);
        } else {
            Stg40_ObjSetAnim(a0, 0x28);
        }
        break;
    case 2:
        Stg40_ClearCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
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
    Stg40Ent48 *e = w->field_2C;

    Stg40_SetCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (e->field_0 & 0x1000) {
        Stg40_AutomapMoveMarker(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    Stg40_ChestQueueModel((Stg40E764 *)w, e->field_10[1] - 1);
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->field_0 &= ~0x4000;
        if (e->field_0 & 0x1000) {
            e->field_0 |= 0x4000;
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 |= 0x5000;
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
            e->field_0 |= 0x5000;
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
    Stg40Ent48 *e = w->field_2C;
    Stg40Cell *c;

    c = Stg40_GetCell2(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
    Stg40_SetCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    c->field_0 |= 0x10;
    if (e->field_0 & 0x1000) {
        Stg40_AutomapMoveMarker(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    e->field_C = e->field_E += 0x155;
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->field_0 &= ~0x4000;
        if (e->field_0 & 0x1000) {
            e->field_0 |= 0x4000;
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        c->field_0 &= ~0x10;
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 |= 0x5000;
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
    Stg40Ent48 *e = w->field_2C;

    Stg40_SetCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    if (Stg40_GetCellFlags(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        Stg40_AutomapMoveMarker(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        Stg40_ObjSetAnim(a0, 0x28);
        e->field_0 |= 0x4000;
        Task_SetState1(a0, 1);
        break;
    case 1:
    case 4:
    case 5:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
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
    Stg40Ent48 *e = w->field_2C;

    Stg40_SetCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (e->field_0 & 0x1000) {
        Stg40_AutomapMoveMarker(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        e->field_18.field_14 = 0x2800;
        e->field_0 = (e->field_0 & 0x1000) ? (e->field_0 | 0x4400) : (e->field_0 & ~0x4000);
        Task_SetState1(a0, 1);
        break;
    case 1:
        break;
    case 2:
        Stg40_ClearCellOccupied(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 = (e->field_0 | 0x5000) & ~0x400;
            Stg40_ObjSetAnim(a0, 0x28);
            e->field_18.field_18 = 0;
            e->field_18.field_14 = 0x2800;
            Snd_PlayById(4, 0);
            Task_NextState2(a0);
            break;
        case 1:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_14 < 0x500) {
                e->field_18.field_14 = 0x500;
                e->field_18.field_18 = -(e->field_18.field_18 / 2);
                Task_NextState2(a0);
            }
            break;
        case 2:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_18 > 0) {
                Stg40_ObjSetAnim(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (Stg40_ObjWaitAnimOrSkip(a0) == 1) {
                e->field_0 |= 0x400;
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 5:
        e->field_0 |= 0x5400;
        Task_SetState1(a0, 1);
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 = (e->field_0 | 0x5000) & ~0x400;
            Stg40_ObjSetAnim(a0, 0x28);
            e->field_18.field_18 = 0;
            e->field_18.field_14 = 0x2800;
            Snd_PlayById(5, 0);
            Task_NextState2(a0);
            break;
        case 1:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_14 < 0) {
                e->field_18.field_14 = 0;
                e->field_18.field_18 = -(e->field_18.field_18 / 2);
                Task_NextState2(a0);
            }
            break;
        case 2:
            e->field_18.field_18 += 0x26;
            e->field_18.field_14 -= e->field_18.field_18;
            if (e->field_18.field_14 < 0) {
                e->field_18.field_14 = 0;
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

    switch (w->field_2C->field_8) {
    case 5:
    default:
        e = w->field_2C;
        if (e->field_0 & 0x1000) {
            return e->field_E;
        }
        return e->field_E;
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
