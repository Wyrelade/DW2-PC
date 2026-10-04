#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/stag3500_2334_funcs.h"

void Stg35_BuildSkillScript(s32 arg0) {
    Stg35Action *b = &Stg35_Battle.actions[arg0];
    s16 *p;
    s16 targets[6];
    s32 dmg[6];
    s16 kind = 1;
    s16 skill = (s16)b->skillId;
    s32 hit;
    s32 n;
    s32 c;
    s32 i;

    hit = Skill_GetPower((s16)b->skillId) > 0;
    p = Stg35_BattleScript;
    for (i = 0; i < 6; i++) {
        dmg[i] = 0;
        targets[i] = -1;
    }
    n = 0;
    switch (b->target) {
    default:
        if (Stg35_Battle.rec[b->target].hp != 0) {
            n = 1;
            targets[0] = b->target;
        }
        break;
    case 7:
        if (hit) {
            for (i = 0, c = 0; i < 3; i++) {
                if (Stg35_Battle.rec[i].hp != 0) {
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
                if (Stg35_Battle.rec[i].hp != 0) {
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
                if (Stg35_Battle.rec[i].hp != 0) {
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
        dmg[i] = Stg35_ApplySkillDamage(arg0, targets[i], skill);
    }
    *p++ = 2;
    *p++ = arg0 + 10;
    *p++ = 3;
    *p++ = arg0;
    *p++ = 0x11;
    *p++ = 0xD;
    *p++ = Stg35_Battle.actions[arg0].actionState - 1;
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
            if (Stg35_Battle.rec[targets[i]].hp != 0) {
                *p++ = Stg35_Battle.actions[targets[i]].actionState != 5 ? 0xA : 9;
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
        Stg35_Battle.scriptTargets[i] = targets[i];
    }
}

s32 Stg35_PrepareAction(s32 arg0) {
    Stg35_BuildSkillScript(arg0);
    return 1;
}

s32 Stg35_CamEaseStep(s32 arg0, s32 arg1) {
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

void Stg35_CamEaseToward(Stg35CamWork *w, s32 *t) {
    s32 i;

    for (i = 0; i < Sys_State.frameDelta; i++) {
        w->rotY += Stg35_CamEaseStep(t[0], w->rotY);
        w->vpx += Stg35_CamEaseStep(t[1], w->vpx);
        w->vpy += Stg35_CamEaseStep(t[2], w->vpy);
        w->vpz += Stg35_CamEaseStep(t[3], w->vpz);
        w->vry += Stg35_CamEaseStep(t[4], w->vry);
        w->originX += Stg35_CamEaseStep(t[5], w->originX);
        w->originZ += Stg35_CamEaseStep(t[6], w->originZ);
    }
}

void Stg35_CameraUpdate(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    s32 i;
    s32 h;

    switch (arg0->stateLevel0) {
    case 0:
        GsInitCoordinate2(0, &w->coord);
        w->vpy = -0x4E20;
        w->vry = 0x12C;
        w->projection = 0x5DC;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 0:
        default:
            switch (arg0->stateLevel2) {
            case 0:
            default:
                w->vpy += 0xE9;
                w->vpz -= 0x15E;
                w->rotY += 0x44;
                if (w->rotY > 0x1000) {
                    w->rotY = 0;
                    Task_NextState2(arg0);
                }
                break;
            case 1:
                w->vry -= 0x21;
                if (++arg0->stateLevel3 == 0x1E) {
                    w->vry = -0x2BC;
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
                Stg35_CamEaseToward(w, t);
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
                h = func_8001E79C(Stg35_Battle.rec[i].digiId);
                h = h < 0x300 ? 0 : h - 0x300;
                h /= 256;
                t[5] = (i % 3) * 0xA00 - 0xA00;
                t[6] = (i / 3) * 0x2800 - 0x1400;
                t[0] = Stg35_CloseUpRotY[i];
                t[1] = 0;
                t[2] = -0xC30;
                t[3] = Stg35_CloseUpVpz[h];
                t[4] = Stg35_CloseUpVry[h];
                Stg35_CamEaseToward(w, t);
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
                Stg35_CamEaseToward(w, t);
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
                Stg35_CamEaseToward(w, t);
            }
            break;
        case 22:
            w->originZ = -0x1E00;
            w->vpy = -0x1F40;
            w->originX = 0;
            w->rotY = 0;
            w->vpx = 0;
            w->vpz = 0x4E20;
            w->vrx = 0;
            w->vry = 0;
            w->vrz = 0;
            break;
        case 23:
            w->originZ = 0x1E00;
            w->rotY = 0x800;
            w->vpy = -0x1F40;
            w->originX = 0;
            w->vpx = 0;
            w->vpz = 0x4E20;
            w->vrx = 0;
            w->vry = 0;
            w->vrz = 0;
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
                Stg35_CamEaseToward(w, t);
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
                Stg35_CamShotVariant = Rand_Next() & 3;
                Task_NextState2(arg0);
            case 1:
                break;
            }
            w->vpy = -0x514;
            w->vpz = 0x2EE0;
            w->vry = -0x578;
            w->vpx = 0;
            w->vrx = 0;
            w->vrz = 0;
            w->rotY = 0xAA;
            w->originX = (arg0->stateLevel1 - 10) * 0xA00 - 0xC80;
            w->originZ = -0x1400;
            switch (Stg35_CamShotVariant) {
            case 1:
                w->rotY = 0x38;
                w->originX = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->vpz = 0x34BC;
                break;
            case 2:
                w->vpy = -0x1914;
                w->originX = (arg0->stateLevel1 - 10) * 0xA00 - 0xA00;
                w->originZ = -0xF00;
                w->vpz = 0x34BC;
                break;
            }
            if (arg0->stateLevel1 >= 13) {
                w->rotY = 0x800 - w->rotY;
                w->originX -= 0x1E00;
                w->originZ = -w->originZ;
            }
            break;
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            w->vpy = -0x5DC;
            w->vpz = 0x2EE0;
            w->vpx = 0;
            w->vrx = 0;
            w->vry = -0x640;
            w->vrz = 0;
            if (arg0->stateLevel1 < 19) {
                w->rotY = 0xAA;
                w->originX = (arg0->stateLevel1 - 16) * 0xA00 - 0xA00;
                w->originZ = -0x1400;
            } else {
                w->rotY = 0x755;
                w->originX = (arg0->stateLevel1 - 19) * 0xA00 - 0xA00;
                w->originZ = 0x1400;
            }
            break;
        case 25:
            w->originZ = -0x1400;
            w->vpy = -0x1388;
            w->vpz = 0x3A98;
            w->originX = 0;
            w->originY = 0;
            w->rotY = 0;
            w->vpx = 0;
            w->vrx = 0;
            w->vry = -0x3E8;
            w->vrz = 0;
            break;
        case 26:
            w->originZ = 0x1400;
            w->rotY = 0x800;
            w->vpy = -0x1388;
            w->vpz = 0x3A98;
            w->originX = 0;
            w->originY = 0;
            w->vpx = 0;
            w->vrx = 0;
            w->vry = -0x3E8;
            w->vrz = 0;
            break;
        }
        break;
    case 2:
    default:
        break;
    }
}

void Stg35_CameraDraw(Actor *arg0) {
    Stg35CamWork *w = (Stg35CamWork *)arg0->work;
    Stg35RefView rv;

    RotMatrixYXZ(&w->rotX, &w->coord.coord);
    w->coord.coord.t[0] = w->originX;
    w->coord.coord.t[1] = w->originY;
    w->coord.coord.t[2] = w->originZ;
    w->coord.flg = 0;
    rv.vpx = w->vpx;
    rv.vpy = w->vpy;
    rv.vpz = w->vpz;
    rv.vrx = w->vrx;
    rv.vry = w->vry;
    rv.vrz = w->vrz;
    rv.rz = 0;
    rv.super = &w->coord;
    GsSetProjection(w->projection);
    GsSetRefView2(&rv);
}

void Stg35_SetCameraShot(s32 arg0) {
    Actor *e = (Actor *)Task_FindFirst(0x706, -1, -1);

    if (e != NULL && e->stateLevel0 == 1) {
        Task_SetState1(e, (u8)arg0);
    }
}

void Stg35_FindSkillGroup(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    Stg35SkillGroupEntry *p;
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        p = Stg35_SkillGroups[i];
        j = 0;
        while (p->skillId != 0) {
            if (p->skillId == arg0) {
                goto found;
            }
            p++;
            j++;
        }
        continue;
    found:
        *arg1 = i;
        *arg2 = j;
        *arg3 = p->targetType;
        *arg4 = p->field_2;
        return;
    }
    *arg1 = -1;
    *arg2 = 100;
}

void Stg35_BuildCommandList(s32 arg0) {
    u8 *ids = Stg35_Battle.rec[arg0].skillIds;
    Stg35Action *b = &Stg35_Battle.actions[arg0];
    s32 best[6];
    s32 grp;
    s32 idx;
    s32 v4;
    s32 v2;
    s32 found;
    s32 i;

    for (i = 0; i < 6; i++) {
        b->skills[i] = 0;
        best[i] = 100;
    }
    found = 0;
    for (i = 0; i < 12; i++) {
        if (ids[i] != 0) {
            Stg35_FindSkillGroup(ids[i], &grp, &idx, &v4, &v2);
            if (grp != -1 && best[grp] > idx) {
                best[grp] = idx;
                found = 1;
                b->skills[grp] = ids[i];
                b->field_1E[grp] = v2;
                b->targetTypes[grp] = v4;
            }
        }
    }
    if (!found) {
        b->skills[0] = Stg35_SkillGroup0[1].skillId;
        b->field_1E[0] = Stg35_SkillGroup0[1].field_2;
        b->targetTypes[0] = Stg35_SkillGroup0[1].targetType;
    }
}

void Stg35_WinBannerInit(Actor *arg0, s32 arg1) {
    arg0->param = arg1;
}

void Stg35_WinBannerUpdate(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 masks[2];
    s32 i;

    switch (arg0->stateLevel0) {
    case 0:
        for (i = 0; i < 1; i++) {
            Stg35_PartsAlloc(&w[i]);
        }
        Stg35_PartsSetFile(w, 0xD3F0008);
        masks[0] = 2;
        masks[1] = 4;
        Stg35_PartsHideByMask(w, ~masks[arg0->param]);
        Task_NextState0(arg0);
    case 1:
        Stg35_PartsSetPalette(w, 6, Math_PingPongRange(arg0->elapsed, 4, 0, 7));
        break;
    case 2:
    default:
        break;
    }
}

void Stg35_WinBannerDestroy(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsFree(&w[i]);
    }
    Task_DefaultDestroy(arg0);
}

void Stg35_WinBannerDraw(Actor *arg0) {
    Stg35PartsHandle *w = (Stg35PartsHandle *)arg0->work;
    s32 i;

    for (i = 0; i < 1; i++) {
        Stg35_PartsDraw(&w[i]);
    }
}
