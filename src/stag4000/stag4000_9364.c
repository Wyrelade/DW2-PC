#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"
#include "stag4000/stag4000_8338_funcs.h"

void func_8006C6C4(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    if (e->field_8 == 2) {
        func_8006E764((Stg40E764 *)w, 0xDF0, 0xDF1);
    } else {
        func_8006E764((Stg40E764 *)w, 0xDF2, 0xDF3);
    }
    if (a0->stateLevel1 != 1 && (a0->stateLevel1 < 2 || (a0->stateLevel1 != 4 && a0->stateLevel1 != 9))) {
        Task_SetState1(a0, 1);
    }
}

void func_8006C7CC(Stg40E764 *a0, s32 a1) {
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
    func_8006E764(a0, x, y);
}

s32 func_8006C84C(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    if (func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    if (e->field_10[1] >= 1 && e->field_10[1] <= 5) {
        func_8006C7CC((Stg40E764 *)w, e->field_10[1] - 1);
    }
    switch (a0->stateLevel1) {
    case 0:
    default:
        if (e->field_10[1] == 0xFF) {
            func_8006E4DC(a0, 0x29);
        } else {
            func_8006E4DC(a0, 0x28);
        }
        Task_SetState1(a0, 1);
        break;
    case 1:
        if (e->field_10[1] == 0xFF) {
            func_8006E4DC(a0, 0x29);
        } else {
            func_8006E4DC(a0, 0x28);
        }
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 3:
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2A);
            Task_NextState2(a0);
            Snd_PlayById(2, 0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                func_8006E4DC(a0, 0x29);
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
                func_8006E4DC(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006CAD4(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    func_8006C7CC((Stg40E764 *)w, e->field_10[1] - 1);
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
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 |= 0x5000;
            func_8006E4DC(a0, 0x28);
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
            func_8006E4DC(a0, 0x2C);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                func_8006E4DC(a0, 0x28);
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2B);
            Snd_PlayById(0x36, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006CD1C(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;
    Stg40Cell *c;

    c = func_800708A4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    c->field_0 |= 0x10;
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
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
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
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
                func_8006E4DC(a0, 0x2A);
            } else {
                func_8006E4DC(a0, 0x2C);
            }
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                func_8006E4DC(a0, 0x28);
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2B);
            Snd_PlayById(0x35, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006CF54(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 1);
    if (func_800703E0(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2) & 0x2000) {
        e->field_0 |= 0x1000;
    }
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
    }
    switch (a0->stateLevel1) {
    case 0:
    case 3:
    default:
        func_8006E4DC(a0, 0x28);
        e->field_0 |= 0x4000;
        Task_SetState1(a0, 1);
        break;
    case 1:
    case 4:
    case 5:
        break;
    case 2:
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 6:
        switch (a0->stateLevel2) {
        case 0:
        default:
            func_8006E4DC(a0, 0x2B);
            Snd_PlayById(0x35, 0);
            Task_NextState2(a0);
            break;
        case 1:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

s32 func_8006D0E8(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->field_2C;

    func_800708FC(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, 0);
    if (e->field_0 & 0x1000) {
        func_8006EBF4(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, -1, -1, e->field_8);
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
        func_80070974(e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2);
        func_8006EBF4(-1, -1, e->field_18.u0.pair.field_0, e->field_18.u0.pair.field_2, e->field_8);
        e->field_0 = 0;
        Task_SetState0(a0, 3);
        break;
    case 4:
        switch (a0->stateLevel2) {
        case 0:
        default:
            e->field_0 = (e->field_0 | 0x5000) & ~0x400;
            func_8006E4DC(a0, 0x28);
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
                func_8006E4DC(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (func_8006E588(a0) == 1) {
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
            func_8006E4DC(a0, 0x28);
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
                func_8006E4DC(a0, 0x2B);
                Task_NextState2(a0);
            }
            break;
        case 3:
            if (func_8006E588(a0) == 1) {
                Task_SetState1(a0, 2);
            }
            break;
        }
        break;
    }
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", jtbl_800635CC);
#ifdef NORMALIZED
s32 func_8006D418(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;

    switch (w->field_2C->field_8) {
    case 5:
    default:
        return w->field_2C->field_E;
    case 6:
        return func_8006CD1C(a0);
    case 7:
        return func_8006CF54(a0);
    case 8:
        return func_8006CAD4(a0);
    case 9:
    case 10:
    case 11:
    case 12:
        return func_8006D0E8(a0);
    case 4:
        return func_8006C84C(a0);
    case 2:
    case 3:
        return ((s32 (*)(Actor *))func_8006C6C4)(a0);
    }
}
#else
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000_9364", func_8006D418);
s32 func_8006D418(Actor *a0);
#endif
