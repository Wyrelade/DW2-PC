#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/stag3500_2334_funcs.h"

void func_8006926C(s32 arg0) {
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s16 *p;
    s16 targets[6];
    s32 dmg[6];
    s16 kind = 1;
    s16 skill = (s16)b->field_8;
    s32 hit;
    s32 n;
    s32 c;
    s32 i;

    hit = Skill_GetPower((s16)b->field_8) > 0;
    p = D_8006ADE0;
    for (i = 0; i < 6; i++) {
        dmg[i] = 0;
        targets[i] = -1;
    }
    n = 0;
    switch (b->field_4) {
    default:
        if (D_8006AA88.rec[b->field_4].hp != 0) {
            n = 1;
            targets[0] = b->field_4;
        }
        break;
    case 7:
        if (hit) {
            for (i = 0, c = 0; i < 3; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    targets[c++] = i;
                }
            }
        } else {
            for (i = 0, c = 0; i < 3; i++) {
                targets[c++] = i;
            }
        }
        n = c;
        kind = 0;
        break;
    case 8:
        if (hit) {
            for (c = 0, i = 3; i < 6; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    targets[c++] = i;
                }
            }
        } else {
            for (c = 0, i = 3; i < 6; i++) {
                targets[c++] = i;
            }
        }
        n = c;
        kind = 1;
        break;
    case 9:
        if (hit) {
            for (c = 0, i = 0; i < 6; i++) {
                if (D_8006AA88.rec[i].hp != 0) {
                    targets[c++] = i;
                }
            }
        } else {
            for (c = 0, i = 0; i < 6; i++) {
                targets[c++] = i;
            }
        }
        n = c;
        kind = 2;
        break;
    }
    for (i = 0; i < n; i++) {
        dmg[i] = func_80065BE0(arg0, targets[i], skill);
    }
    *p++ = 2;
    *p++ = arg0 + 10;
    *p++ = 3;
    *p++ = arg0;
    *p++ = 0x11;
    *p++ = 0xD;
    *p++ = D_8006AA88.field_238[arg0].field_0 - 1;
    *p++ = 1;
    *p++ = 0x12;
    *p++ = 0xE;
    *p++ = skill;
    *p++ = 0x13;
    *p++ = skill;
    *p++ = n;
    *p++ = 8;
    *p++ = arg0;
    *p++ = skill;
    *p++ = 0;
    *p++ = 0x96;
    *p++ = 7;
    *p++ = arg0;
    for (i = 0; i < n; i++) {
        *p++ = 2;
        *p++ = targets[i] + 0x10;
        *p++ = 3;
        *p++ = targets[i];
        *p++ = 0;
        *p++ = i == 0 ? 0x1E : 0xC;
        *p++ = 0xF;
        *p++ = dmg[i];
        if (hit) {
            if (D_8006AA88.rec[targets[i]].hp != 0) {
                *p++ = D_8006AA88.field_238[targets[i]].field_0 != 5 ? 0xA : 9;
            } else {
                *p++ = 0xB;
            }
        } else {
            *p++ = 0xC;
        }
        *p++ = targets[i];
        *p++ = skill;
        if (n == 1) {
            if (hit) {
                *p++ = 1;
                *p++ = targets[i];
                *p++ = 0;
                *p++ = 0x1E;
            } else {
                *p++ = 0;
                *p++ = 0x78;
            }
        } else {
            *p++ = 0;
            *p++ = 0x3C;
        }
    }
    if (n != 1) {
        *p++ = 2;
        *p++ = kind + 0x16;
        *p++ = kind + 4;
        *p++ = 0;
        *p++ = 0xB4;
    }
    *p = 0x14;
    for (i = 0; i < 6; i++) {
        D_8006AA88.field_340[i] = targets[i];
    }
}

s32 func_80069850(s32 arg0) {
    func_8006926C(arg0);
    return 1;
}

s32 func_80069870(s32 arg0, s32 arg1) {
    s32 neg = 0;
    s32 r;

    arg0 -= arg1;
    if (arg0 == 0) {
        return neg;
    }
    if (arg0 < 0) {
        neg = 1;
        arg0 = -arg0;
    }
    r = arg0 / 16;
    if (r == 0) {
        r = 1;
    }
    if (neg) {
        r = -r;
    }
    return r;
}

void func_800698C8(Stg35CamWork *w, s32 *t) {
    s32 i;

    for (i = 0; i < Sys_State.frameDelta; i++) {
        w->field_7E += func_80069870(t[0], w->field_7E);
        w->field_0 += func_80069870(t[1], w->field_0);
        w->field_4 += func_80069870(t[2], w->field_4);
        w->field_8 += func_80069870(t[3], w->field_8);
        w->field_10 += func_80069870(t[4], w->field_10);
        w->field_6C += func_80069870(t[5], w->field_6C);
        w->field_74 += func_80069870(t[6], w->field_74);
    }
}

void func_800699FC(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    s32 i;
    s32 h;

    switch (arg0->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->field_1C);
        w->field_4 = -0x4E20;
        w->field_10 = 0x12C;
        w->field_18 = 0x5DC;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->field_4 += 0xE9;
                w->field_8 -= 0x15E;
                w->field_7E += 0x44;
                if (w->field_7E > 0x1000) {
                    w->field_7E = 0;
                    Task_NextState2(arg0);
                }
                break;
            case 1:
                w->field_10 -= 0x21;
                if (++arg0->stateLevel3 == 0x1E) {
                    w->field_10 = -0x2BC;
                    Task_NextState1(arg0);
                }
                break;
            }
            break;
        case 1:
            {
                s32 t[7];

                t[2] = -0x169B;
                t[3] = -0x5366;
                t[5] = 0;
                t[6] = 0;
                t[0] = 0;
                t[1] = 0;
                t[4] = -0x2BC;
                func_800698C8(w, t);
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            {
                s32 t[7];

                i = arg0->stateLevel1 - 2;
                h = func_8001E79C(D_8006AA88.rec[i].digiId);
                h = h < 0x300 ? 0 : h - 0x300;
                h /= 256;
                t[5] = (i % 3) * 0xA00 - 0xA00;
                t[6] = (i / 3) * 0x2800 - 0x1400;
                t[0] = D_8006A690[i];
                t[1] = 0;
                t[2] = -0xC30;
                t[3] = D_8006A69C[h];
                t[4] = D_8006A6B0[h];
                func_800698C8(w, t);
            }
            break;
        case 8:
            {
                s32 t[7];

                t[6] = -0x1400;
                t[0] = 0x238;
                t[2] = -0x91C;
                t[3] = 0x33FC;
                t[5] = 0;
                t[1] = 0;
                t[4] = -0x36C;
                func_800698C8(w, t);
            }
            break;
        case 9:
            {
                s32 t[7];

                t[6] = 0x1400;
                t[0] = 0x5C7;
                t[2] = -0x91C;
                t[3] = 0x33FC;
                t[5] = 0;
                t[1] = 0;
                t[4] = -0x36C;
                func_800698C8(w, t);
            }
            break;
        case 22:
            w->field_74 = -0x1E00;
            w->field_4 = -0x1F40;
            w->field_6C = 0;
            w->field_7E = 0;
            w->field_0 = 0;
            w->field_8 = 0x4E20;
            w->field_C = 0;
            w->field_10 = 0;
            w->field_14 = 0;
            break;
        case 23:
            w->field_74 = 0x1E00;
            w->field_7E = 0x800;
            w->field_4 = -0x1F40;
            w->field_6C = 0;
            w->field_0 = 0;
            w->field_8 = 0x4E20;
            w->field_C = 0;
            w->field_10 = 0;
            w->field_14 = 0;
            break;
        case 24:
            {
                s32 t[7];

                t[0] = -0x400;
                t[2] = -0x50FB;
                t[3] = -0x6EC6;
                t[5] = 0;
                t[6] = 0;
                t[1] = 0;
                t[4] = -0x29C;
                func_800698C8(w, t);
            }
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                D_8006AF70 = Rand_Next() & 3;
                Task_NextState2(arg0);
            case 1:
                break;
            }
            w->field_4 = -0x514;
            w->field_8 = 0x2EE0;
            w->field_10 = -0x578;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_14 = 0;
            w->field_7E = 0xAA;
            w->field_6C = (arg0->stateLevel1 - 10) * 0xA00 - 0xC80;
            w->field_74 = -0x1400;
            switch (D_8006AF70) {
            case 1:
                w->field_7E = 0x38;
                w->field_6C = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->field_8 = 0x34BC;
                break;
            case 2:
                w->field_4 = -0x1914;
                w->field_6C = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->field_74 = -0xF00;
                w->field_8 = 0x34BC;
                break;
            }
            if (arg0->stateLevel1 >= 13) {
                w->field_7E = 0x800 - w->field_7E;
                w->field_6C -= 0x1E00;
                w->field_74 = -w->field_74;
            }
            break;
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            w->field_4 = -0x5DC;
            w->field_8 = 0x2EE0;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_10 = -0x640;
            w->field_14 = 0;
            if (arg0->stateLevel1 < 19) {
                w->field_7E = 0xAA;
                w->field_6C = (arg0->stateLevel1 - 16) * 0xA00 - 0xA00;
                w->field_74 = -0x1400;
            } else {
                w->field_7E = 0x755;
                w->field_6C = (arg0->stateLevel1 - 19) * 0xA00 - 0xA00;
                w->field_74 = 0x1400;
            }
            break;
        case 25:
            w->field_74 = -0x1400;
            w->field_4 = -0x1388;
            w->field_8 = 0x3A98;
            w->field_6C = 0;
            w->field_70 = 0;
            w->field_7E = 0;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_10 = -0x3E8;
            w->field_14 = 0;
            break;
        case 26:
            w->field_74 = 0x1400;
            w->field_7E = 0x800;
            w->field_4 = -0x1388;
            w->field_8 = 0x3A98;
            w->field_6C = 0;
            w->field_70 = 0;
            w->field_0 = 0;
            w->field_C = 0;
            w->field_10 = -0x3E8;
            w->field_14 = 0;
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void func_80069FD4(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    Stg35RefView rv;

    RotMatrixYXZ(&w->field_7C, &w->field_1C.coord);
    w->field_1C.coord.t[0] = w->field_6C;
    w->field_1C.coord.t[1] = w->field_70;
    w->field_1C.coord.t[2] = w->field_74;
    w->field_1C.flg = 0;
    rv.field_0 = w->field_0;
    rv.field_4 = w->field_4;
    rv.field_8 = w->field_8;
    rv.field_C = w->field_C;
    rv.field_10 = w->field_10;
    rv.field_14 = w->field_14;
    rv.field_18 = 0;
    rv.field_1C = &w->field_1C;
    GsSetProjection(w->field_18);
    GsSetRefView2(&rv);
}

void func_8006A080(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x706, -1, -1);

    if (e != NULL && e->stateLevel0 == 1) {
        Task_SetState1(e, (u8)arg0);
    }
}

void func_8006A0D4(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    Stg35Rec6 *p;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        p = D_8006AA24[i];
        j = 0;
        while (p->field_0 != 0) {
            if (p->field_0 == arg0) {
                goto found;
            }
            p++;
            j++;
        }
        continue;
    found:
        *arg1 = i;
        *arg2 = j;
        *arg3 = p->field_4;
        *arg4 = p->field_2;
        return;
    }
    *arg1 = -1;
    *arg2 = 100;
}

void func_8006A168(s32 arg0) {
    u8 *ids = D_8006AA88.rec[arg0].field_22;
    Stg35Rec2C *b = &D_8006AA88.field_238[arg0];
    s32 best[6];
    s32 grp;
    s32 idx;
    s32 v4;
    s32 v2;
    s32 found;
    s32 i;

    for (i = 0; i < 6; i++) {
        b->field_C[i] = 0;
        best[i] = 100;
    }
    found = 0;
    for (i = 0; i < 12; i++) {
        if (ids[i] != 0) {
            func_8006A0D4(ids[i], &grp, &idx, &v4, &v2);
            if (grp != -1 && best[grp] > idx) {
                best[grp] = idx;
                found = 1;
                b->field_C[grp] = ids[i];
                b->field_1E[grp] = v2;
                b->field_12[grp] = v4;
            }
        }
    }
    if (!found) {
        b->field_C[0] = D_8006A6DC[1].field_0;
        b->field_1E[0] = D_8006A6DC[1].field_2;
        b->field_12[0] = D_8006A6DC[1].field_4;
    }
}

void func_8006A2D0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_8006A2D8(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 masks[2];
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            func_80066120(&w[i]);
        }
        func_800661A4(w, 0xD3F0008);
        masks[0] = 2;
        masks[1] = 4;
        func_800663CC(w, ~masks[arg0->field_8]);
        Task_NextState0(arg0);
    case 1:
        func_80066520(w, 6, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
        break;
    case 2:
    default:
        break;
    }
}

void func_8006A3B8(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80066168(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void func_8006A40C(Actor *arg0) {
    Stg35LoadHandle *w = (Stg35LoadHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        func_800661B0(&w[i]);
    }
}
