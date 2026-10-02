#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"
#include "stag3000/stag3000_6A88_funcs.h"

void func_8006CA3C(s32 idx) {
    s16 *p = D_80073890;

    *p++ = 2;
    *p++ = idx + 10;
    *p++ = 3;
    *p++ = idx;
    *p++ = 0xE;
    *p++ = 4;
    *p++ = 1;
    *p++ = 0;
    p[0] = 0x78;
    p[1] = 0x18;
    D_80073CC0.entries[idx].field_32 += D_80073CC0.entries[idx].field_30 / 10;
    if (D_80073CC0.entries[idx].field_30 < D_80073CC0.entries[idx].field_32) {
        D_80073CC0.entries[idx].field_32 = D_80073CC0.entries[idx].field_30;
    }
}

s32 func_8006CB28(s32 idx) {
    switch (D_80073CC0.field_2AC[idx].field_0) {
    case 1:
    case 2:
    case 3:
    case 4:
    default:
        func_8006BBD8(idx);
        return 1;
    case 5:
        func_8006CA3C(idx);
        return 1;
    }
}

void func_8006CB8C(Actor *a0) {
    Stg30WorkPc *w = (Stg30WorkPc *)a0->work;
    Stg30Slots *sl = (Stg30Slots *)a0->u34.children;
    s32 a[2];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];
    s32 f[3];
    s32 g[3];
    s32 h[1];
    TaskEntry *t;
    s32 *q;
    s32 cont;
    s32 v;

    switch (a0->stateLevel0) {
    case 0:
        w->pc = D_80073890;
        Task_NextState0(a0);
        break;
    case 1:
        cont = 1;
        do {
            switch (*w->pc) {
            case 0:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    a0->elapsed = 0;
                    a0->stateLevel1++;
                case 1:
                    if (w->pc[1] < a0->elapsed) {
                        a0->stateLevel1 = 0;
                        w->pc += 2;
                    } else {
                        cont = 0;
                    }
                    break;
                }
                break;
            case 1:
                t = Task_FindFirst(0x509, -1, w->pc[1]);
                if (((Actor *)t)->stateLevel0 == 2) {
                    cont = 0;
                } else {
                    w->pc += 2;
                }
                break;
            case 2:
                ((void (*)(s32))func_80070D14)(w->pc[1]);
                cont = 0;
                w->pc += 2;
                break;
            case 3:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 == w->pc[1]) {
                        func_8006F640((Actor *)t, 1);
                        func_8006F664((Actor *)t);
                    } else {
                        func_8006F640((Actor *)t, 0);
                    }
                }
                w->pc += 2;
                break;
            case 4:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 < 3) {
                        func_8006F640((Actor *)t, 1);
                        func_8006F664((Actor *)t);
                    }
                }
                w->pc += 1;
                break;
            case 5:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->field_8 >= 3) {
                        func_8006F640((Actor *)t, 1);
                        func_8006F664((Actor *)t);
                    }
                }
                w->pc += 1;
                break;
            case 6:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    func_8006F640((Actor *)t, 1);
                    func_8006F664((Actor *)t);
                }
                w->pc += 1;
                break;
            case 7:
                t = Task_FindFirst(0x509, -1, w->pc[1]);
                Task_SetState0((Actor *)t, 2);
                Task_SetState1((Actor *)t, 0);
                w->pc += 2;
                break;
            case 9:
                if (w->pc[1] != 6) {
                    t = Task_FindFirst(0x509, -1, w->pc[1]);
                    Task_SetState0((Actor *)t, 2);
                    Task_SetState1((Actor *)t, 1);
                    Task_SetState4((Actor *)t, (u8)w->pc[2]);
                }
                w->pc += 3;
                break;
            case 10:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 3, w->pc[2]);
                w->pc += 3;
                break;
            case 11:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 4, w->pc[2]);
                w->pc += 3;
                break;
            case 12:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 5, w->pc[2]);
                if (w->pc[1] >= 3) {
                    D_80073CC0.field_3D8 = w->pc[1];
                }
                w->pc += 3;
                break;
            case 13:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 6, w->pc[2]);
                w->pc += 3;
                break;
            case 8:
                func_80067530((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 0xC, w->pc[2]);
                w->pc += 3;
                break;
            case 19:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    Task_Create(0x510, &sl->field_C, 0);
                    Task_NextState1(a0);
                case 1:
                    cont = 0;
                    if (sl->field_C == 0) {
                        w->pc += 1;
                        Task_SetState1(a0, 0);
                    }
                    break;
                }
                break;
            case 20:
                if (D_80073CC0.field_2AC[3].field_0 == 3) {
                    D_80073CC0.field_3D0 = 3;
                } else if (D_80073CC0.field_2AC[4].field_0 == 3) {
                    D_80073CC0.field_3D0 = 4;
                } else if (D_80073CC0.field_2AC[5].field_0 == 3) {
                    D_80073CC0.field_3D0 = 5;
                }
                w->pc += 1;
                break;
            case 14:
                a[0] = w->pc[1];
                a[1] = w->pc[2];
                Task_Create(0x50C, &sl->field_0, (s32)a);
                if (D_80073CC0.field_3B0 != 0) {
                    b[0] = 8;
                    b[2] = D_80073CC0.field_3B0;
                    Task_Create(0x50D, &sl->field_8, (s32)b);
                }
                w->pc += 3;
                break;
            case 15:
                c[0] = 0;
                c[1] = w->pc[1];
                c[2] = 0;
                Task_Create(0x50D, &sl->field_4, (s32)c);
                w->pc += 2;
                break;
            case 17:
                d[0] = w->pc[1] + 4;
                d[2] = 0;
                Task_Create(0x50D, &sl->field_0, (s32)d);
                w->pc += 2;
                break;
            case 18:
                e[0] = 7;
                e[2] = 0;
                Task_Create(0x50D, &sl->field_8, (s32)e);
                w->pc += 1;
                break;
            case 16:
                f[0] = w->pc[2];
                v = w->pc[1];
                if (v < 0) {
                    v = -v;
                }
                f[1] = v;
                f[2] = w->pc[3];
                Task_Create(0x50D, &sl->field_4, (s32)f);
                w->pc += 4;
                break;
            case 21:
                h[0] = (s32)D_80073890;
                Task_Create(0x50E, (s32 *)&sl->field_10, (s32)h);
                w->pc += 1;
                break;
            case 22:
                if (sl->field_10->stateLevel0 != 1) {
                    cont = 0;
                } else {
                    w->pc += 1;
                }
                break;
            case 23:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    q = func_8001EFF0(w->pc[1]);
                    g[0] = q[0];
                    g[1] = q[1];
                    g[2] = w->pc[2];
                    Task_Create(0x511, (s32 *)&sl->field_14, (s32)g);
                    Task_NextState1(a0);
                case 1:
                    if (sl->field_14->stateLevel0 != 1) {
                        cont = 0;
                        break;
                    }
                    Task_SetState0(sl->field_14, 2);
                    w->pc += 3;
                    Task_SetState1(a0, 0);
                    break;
                }
                break;
            case 24:
                Task_SetState0(a0, 3);
                cont = 0;
                break;
            }
        } while (cont);
        break;
    }
}
