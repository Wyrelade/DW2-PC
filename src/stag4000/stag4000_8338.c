#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"

s32 func_8006B698(Stg40Ent48 *e, Pair54 *out) {
    Stg40Loc *loc = &e->field_18;
    Pair54 c[3];
    s16 dx = D_80072B60->field_4->field_18.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->field_4->field_18.u0.pair.field_2 - loc->u0.pair.field_2;
    s32 n;
    s32 i;

    if (abs(dx) >= 3 || abs(dy) >= 3) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        c[0].field_0 = dx >= 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[0].field_2 = loc->u0.pair.field_2;
        if (dy == 0) {
            switch (e->field_B) {
            case 0:
            case 1:
            case 7:
                dy--;
                break;
            }
        }
        c[1].field_0 = loc->u0.pair.field_0;
        c[1].field_2 = dy < 0 ? loc->u0.pair.field_2 + 1 : loc->u0.pair.field_2 - 1;
        c[2].field_0 = loc->u0.pair.field_0;
        c[2].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
    } else {
        c[0].field_2 = dy >= 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        c[0].field_0 = loc->u0.pair.field_0;
        if (dx == 0) {
            switch (e->field_B) {
            case 5:
            case 6:
            case 7:
                dx--;
                break;
            }
        }
        c[1].field_2 = loc->u0.pair.field_2;
        c[1].field_0 = dx < 0 ? loc->u0.pair.field_0 + 1 : loc->u0.pair.field_0 - 1;
        c[2].field_2 = loc->u0.pair.field_2;
        c[2].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
    }
    for (i = 0, n = 0; i < 3; i++) {
        out[n].field_0 = c[i].field_0;
        out[n].field_2 = c[i].field_2;
        n++;
    }
    return n;
}

s32 func_8006B8C8(Stg40Ent48 *e, Pair54 *out) {
    Pair54 *p = &e->field_18.u0.pair;
    s16 dx = D_80072B60->field_17C.field_0 - p->field_0;
    s16 dy = D_80072B60->field_17C.field_2 - p->field_2;

    if (dx == 0 && dy == 0) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        out->field_0 = dx < 0 ? p->field_0 - 1 : p->field_0 + 1;
        out->field_2 = p->field_2;
    } else {
        out->field_0 = p->field_0;
        out->field_2 = dy < 0 ? p->field_2 - 1 : p->field_2 + 1;
    }
    return 1;
}

s32 func_8006B9A8(Stg40Ent48 *e, Pair54 *out) {
    Stg40Loc *loc = &e->field_18;
    Pair54 c[3];
    s16 dx = D_80072B60->field_4->field_18.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->field_4->field_18.u0.pair.field_2 - loc->u0.pair.field_2;
    s32 n;
    s32 i;

    if (abs(dx) + abs(dy) < 2) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        c[0].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[0].field_2 = loc->u0.pair.field_2;
        c[1].field_0 = loc->u0.pair.field_0;
        c[1].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        c[2].field_0 = loc->u0.pair.field_0;
        c[2].field_2 = dy >= 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
    } else {
        c[0].field_0 = loc->u0.pair.field_0;
        c[0].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        c[1].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[1].field_2 = loc->u0.pair.field_2;
        c[2].field_0 = dx >= 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[2].field_2 = loc->u0.pair.field_2;
    }
    n = 0;
    for (i = 0; i < 3; i++) {
        if (c[i].field_0 != loc->field_4.field_0 || c[i].field_2 != loc->field_4.field_2) {
            out[n].field_0 = c[i].field_0;
            out[n].field_2 = c[i].field_2;
            n++;
        }
    }
    if (n != 3) {
        out[n].field_0 = loc->field_4.field_0;
        out[n].field_2 = loc->field_4.field_2;
        n++;
    }
    return n;
}

s32 func_8006BBBC(Stg40Ent48 *e, Pair54 *out) {
    s16 k = e->field_10[4];
    s32 i;
    s32 n;
    s32 m = 0;
    Stg40Loc *loc = &e->field_18;
    Pair54 c[3];
    s16 dx = D_80072B60->field_4->field_18.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->field_4->field_18.u0.pair.field_2 - loc->u0.pair.field_2;

    if (dx != 0) {
        if (dy != 0) {
            if (abs(dx) >= abs(dy)) {
                c[0].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
                c[0].field_2 = loc->u0.pair.field_2;
                c[1].field_0 = loc->u0.pair.field_0;
                c[1].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
            } else {
                c[1].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
                c[1].field_2 = loc->u0.pair.field_2;
                c[0].field_0 = loc->u0.pair.field_0;
                c[0].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
            }
            m = 2;
        } else {
            c[0].field_0 = dx < 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
            c[0].field_2 = loc->u0.pair.field_2;
            m = 1;
        }
    } else if (dy != 0) {
        c[0].field_0 = loc->u0.pair.field_0;
        c[0].field_2 = dy < 0 ? loc->u0.pair.field_2 - 1 : loc->u0.pair.field_2 + 1;
        m = 1;
    }
    for (i = 0, n = 0; i < m; i++) {
        if (k == (s16)(func_800703E0(c[i].field_0, c[i].field_2) & 0xF)) {
            out[n].field_0 = c[i].field_0;
            out[n].field_2 = c[i].field_2;
            n++;
        }
    }
    return n;
}

s32 func_8006BDEC(Stg40Ent48 *e, s32 mode) {
    Pair54 buf[3];
    Pair54 *sel = NULL;
    Stg40Loc *loc = &e->field_18;
    s32 i;
    s32 n;

    for (i = 0; i < 3; i++) {
        buf[i].field_0 = buf[i].field_2 = -1;
    }
    switch (mode) {
    case 0:
    default:
        n = func_8006B9A8(e, buf);
        break;
    case 1:
        n = func_8006B698(e, buf);
        break;
    case 2:
        n = func_8006BBBC(e, buf);
        break;
    case 4:
        n = func_8006B8C8(e, buf);
        break;
    case 3:
        return 0;
    }
    for (i = 0; i < n; i++) {
        if ((func_800703E0(buf[i].field_0, buf[i].field_2) & 0x4020) == 0x4000) {
            sel = &buf[i];
            break;
        }
    }
    if (sel == NULL) {
        return 0;
    }
    e->field_E = (func_8006E490(sel->field_0 - loc->u0.pair.field_0, sel->field_2 - loc->u0.pair.field_2) << 16) >> 7;
    loc->field_4.field_0 = loc->u0.pair.field_0;
    loc->field_4.field_2 = loc->u0.pair.field_2;
    loc->u0.pair.field_0 = sel->field_0;
    loc->u0.pair.field_2 = sel->field_2;
    loc->field_8 = loc->field_A = 12;
    func_80070974(loc->field_4.field_0, loc->field_4.field_2);
    func_800708FC(loc->u0.pair.field_0, loc->u0.pair.field_2, 1);
    loc->field_1C = 1;
    return 1;
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_800634FC);
INCLUDE_RODATA("asm/USA/stag4000/rodata", jtbl_80063500);
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000_8338", func_8006BFB0);
