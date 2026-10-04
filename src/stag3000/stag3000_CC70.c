#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"
#include "stag3000/stag3000_6A88_funcs.h"
#include "stag3000/stag3000_96DC_funcs.h"
#include "stag3000/stag3000_9F8C_funcs.h"
#include "stag3000/stag3000_AF5C_funcs.h"
#include "stag3000/stag3000_C918_funcs.h"

void Stg30_InterruptSelectDraw(Actor *a0) {
    Stg30InterruptSelectWork *w = (Stg30InterruptSelectWork *)a0->work;
    Stg30Part *p;
    Stg30Part *q;
    Stg30Part *r;
    s32 k;

    if (a0->stateLevel0 == 1 && a0->stateLevel1 == 0) {
        p = (Stg30Part *)Cd_GetFileEntry(0x1A10008);
        for (q = p; q->fileId != 0; q++) {
            q->scaleX = w->scaleX;
            q->scaleY = w->scaleY;
            q->palette = w->palette;
            if (w->choice == 0) {
                switch (q->groupMask) {
                case 0x10:
                    q->visible = 0;
                    break;
                case 4:
                    q->visible = ((u32)Sys_State.frameCount >> 1) & 1;
                    break;
                case 8:
                    q->visible = (((u32)Sys_State.frameCount >> 1) ^ 1) & 1;
                    break;
                default:
                    q->visible = 1;
                    break;
                }
            } else {
                switch (q->groupMask) {
                case 4:
                    q->visible = 0;
                    break;
                case 0x10:
                    q->visible = ((u32)Sys_State.frameCount >> 1) & 1;
                    break;
                case 0x20:
                    q->visible = (((u32)Sys_State.frameCount >> 1) ^ 1) & 1;
                    break;
                default:
                    q->visible = 1;
                    break;
                }
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
    if (Stg30_Battle.interruptActive != 0) {
        p = (Stg30Part *)Cd_GetFileEntry(0x1A1000B);
        k = w->slot;
        if (Stg30_Battle.turns[k].turnType != 3) {
            k += 3;
        }
        for (r = p; r->fileId != 0; r++) {
            if (r->groupMask & Stg30_InterruptCursorMasks[k]) {
                r->visible = 1;
                r->palette = w->cursorPalette;
            } else {
                r->visible = 0;
            }
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}

void Stg30_InitBattle(void) {
    Mem_Zero(&Stg30_Battle, 0x3E0);
    Stg30_Battle.interruptActive = 1;
    if ((Sys_State.prevGameMode & 0xFF00) == 0x300) {
        Dung_State.floorSpecialty = 0;
        Dung_State.giftLevel = 0;
        Stg30_Battle.entries[0].fromCity = 1;
    }
    if (Sys_State.modeArg == 0x97 && Flag_Test(0x88)) {
        Sys_State.modeArg++;
    }
    D_80074098 = 4;
}

void Stg30_XaPlayInit(Actor *a0, Vec3 *args) {
    ((Stg30WorkVec3 *)a0->work)->pos = *args;
}

void Stg30_XaPlayTask(Stg30TaskHead *a0) {
    Stg30CdWork *w = (Stg30CdWork *)a0->work;
    u8 param[8];
    u8 mode[8];
    u8 loc[8];
    u8 res[8];
    u8 res2[8];
    s32 lba;
    s32 r;

    switch (a0->stateLevel0) {
    case 0:
    default:
        switch (a0->stateLevel1) {
        case 0:
        default:
            lba = Cd_GetFileLba(w->file) + Stg30_XaTrackStart[w->track - 1];
            w->start = lba;
            w->end = lba + Stg30_XaTrackLength[w->track - 1];
            param[0] = 1;
            param[1] = w->channel;
            CdControl(0xD, param, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, loc);
            CdControlF(0x15, loc);
            Task_NextState1((Actor *)a0);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0((Actor *)a0, 0);
                break;
            case 2:
                Task_NextState0((Actor *)a0);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (a0->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1((Actor *)a0);
            }
            break;
        case 1:
            if (a0->frameCount & 0x1F) {
                break;
            }
            switch (CdSync(1, res2)) {
            case 5:
                Task_SetState0((Actor *)a0, 3);
                break;
            case 2:
                if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
                    Task_SetState0((Actor *)a0, 3);
                } else {
                    CdControlF(0x11, 0);
                }
                break;
            }
            break;
        }
        break;
    }
}

void Stg30_XaPlayDestroy(Actor *a0) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a0);
}

s32 Stg30_CamEaseStep(s32 a, s32 b) {
    s32 neg = 0;
    s32 r;
    a -= b;
    if (a == 0) {
        return neg;
    }
    if (a < 0) {
        neg = 1;
        a = -a;
    }
    r = a / 16;
    if (r == 0) {
        r = 1;
    }
    if (neg) {
        r = -r;
    }
    return r;
}

void Stg30_CamEaseToward(Stg30CamWork *w, Stg30CamGoal *g) {
    s32 i;

    for (i = 0; i < Sys_State.frameDelta; i++) {
        w->rotY += Stg30_CamEaseStep(g->rotY, w->rotY);
        w->vpx += Stg30_CamEaseStep(g->vpx, w->vpx);
        w->vpy += Stg30_CamEaseStep(g->vpy, w->vpy);
        w->vpz += Stg30_CamEaseStep(g->vpz, w->vpz);
        w->vry += Stg30_CamEaseStep(g->vry, w->vry);
        w->originX += Stg30_CamEaseStep(g->originX, w->originX);
        w->originZ += Stg30_CamEaseStep(g->originZ, w->originZ);
    }
}

void Stg30_CameraUpdate(Actor *arg0) {
    Stg30CamWork *w = (Stg30CamWork *)arg0->work;
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
                Stg30CamGoal g;

                g.vpy = -0x169B;
                g.vpz = -0x5366;
                g.originX = 0;
                g.originZ = 0;
                g.rotY = 0;
                g.vpx = 0;
                g.vry = -0x2BC;
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            {
                Stg30CamGoal g;

                i = arg0->stateLevel1 - 2;
                h = func_8001E79C(Stg30_Battle.entries[i].digiId);
                h = h < 0x300 ? 0 : h - 0x300;
                h /= 256;
                g.originX = (i % 3) * 0xA00 - 0xA00;
                g.originZ = (i / 3) * 0x2800 - 0x1400;
                g.rotY = Stg30_CloseUpRotY[i];
                g.vpx = 0;
                g.vpy = -0xC30;
                g.vpz = Stg30_CloseUpVpz[h];
                g.vry = Stg30_CloseUpVry[h];
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 8:
            {
                Stg30CamGoal g;

                g.originZ = -0x1400;
                g.rotY = 0x238;
                g.vpy = -0x91C;
                g.vpz = 0x33FC;
                g.originX = 0;
                g.vpx = 0;
                g.vry = -0x36C;
                Stg30_CamEaseToward(w, &g);
            }
            break;
        case 9:
            {
                Stg30CamGoal g;

                g.originZ = 0x1400;
                g.rotY = 0x5C7;
                g.vpy = -0x91C;
                g.vpz = 0x33FC;
                g.originX = 0;
                g.vpx = 0;
                g.vry = -0x36C;
                Stg30_CamEaseToward(w, &g);
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
                Stg30CamGoal g;

                g.rotY = -0x400;
                g.vpy = -0x50FB;
                g.vpz = -0x6EC6;
                g.originX = 0;
                g.originZ = 0;
                g.vpx = 0;
                g.vry = -0x29C;
                Stg30_CamEaseToward(w, &g);
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
                Stg30_CamShotVariant = Rand_Next() & 3;
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
            switch (Stg30_CamShotVariant) {
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
            w->rotY = 0x238;
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

void Stg30_CameraDraw(Actor *a0) {
    Stg30CamWork *w = (Stg30CamWork *)a0->work;
    Stg30RefView rv;

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

void Stg30_SetCameraShot(u8 state) {
    Actor *t = (Actor *)Task_FindFirst(0x503, -1, -1);

    if (t != NULL && t->stateLevel0 == 1) {
        Task_SetState1(t, state);
    }
}

void Stg30_FighterHudInit(Actor *a0, Stg30Ref **args) {
    ((Stg30FighterHudWork *)a0->work)->ref = args[0];
    a0->param = args[0]->param;
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
            args.text = (s32)D_80073D24[a0->param].name;
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
    Stg30DigiS *d;
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
            Stg30DigiS *s = &D_80073CD8[k];

            Gfx_SetPartsNumber((GfxPart *)p, 0x20, 3, s->maxHp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x40, 3, s->hp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x80, 3, s->maxMp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x100, 3, s->mp);
            Gfx_SetPartsNumber((GfxPart *)p, 0x200, 2, s->level);
        }
        d = &D_80073CD8[a0->param];
        if (a0->param < 3) {
            Stg30_SetGaugeParts(p, 0x400, d->hp, d->maxHp);
            Stg30_SetGaugeParts(p, 0x4000, d->mp, d->maxMp);
        } else {
            Stg30_SetGaugeParts(p, 0x20, d->hp, d->maxHp);
        }
        Gfx_DrawParts((EntA0 *)p);
    }
}

void Stg30_ResultInit(Actor *a0, Stg30Pair *args) {
    ((Stg30ResultWork *)a0->work)->pair = *args;
}

u8 *Stg30_NumToDigits(u8 *out, s32 n) {
    u8 buf[8];
    s32 i;
    s32 lead;
    s32 k;

    for (i = 7; i != -1; i--) {
        buf[i] = n % 10;
        n /= 10;
    }
    lead = 1;
    k = 0;
    for (i = 0; i < 8; i++) {
        if (!lead || buf[i] != 0) {
            out[k++] = buf[i];
            lead = 0;
        }
    }
    out[k] = 0xFF;
    return out;
}

void Stg30_LevelUpStats(DigiRosterEntry *e) {
    u16 *p;
    s32 r;
    s32 c;
    s32 lv;
    s32 k;
    u16 t;

    e->level = e->level + 1;
    lv = e->level;
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            p = &e->maxHp;
        } else {
            p = &e->maxMp;
        }
        r = Rand_Next() & 3;
        c = Digi_GetStatGrowth(e->digiId, k);
        if (lv < 12) {
            *p += Stg30_HpMpGrowth[0][c][r] + 10;
        } else if (lv < 22) {
            *p += Stg30_HpMpGrowth[1][c][r] + 6;
        } else if (lv < 32) {
            *p += Stg30_HpMpGrowth[2][c][r] + 4;
        } else if (lv < 42) {
            *p += Stg30_HpMpGrowth[3][c][r] + 2;
        } else if (lv < 52) {
            *p = *p + Stg30_HpMpGrowth[4][c][r];
        } else {
            *p = *p + Stg30_HpMpGrowth[5][c][r];
        }
        t = *p;
        if ((s16)*p >= 1000) {
            t = 999;
        }
        *p = t;
    }
    k = 1;
    lv = e->level - (Digi_GetRank(e->digiId) * 10 + k);
    for (k = 0; k < 2; k++) {
        if (k == 0) {
            p = (u16 *)&e->attack;
        } else {
            p = &e->defense;
        }
        r = Rand_Next() & 3;
        c = Digi_GetStatGrowth(e->digiId, k + 2);
        if (lv == 1) {
            *p += Stg30_AtkDefGrowth[0][c][r] + 4;
        } else if (lv < 4) {
            *p += Stg30_AtkDefGrowth[1][c][r] + 3;
        } else if (lv < 7) {
            *p += Stg30_AtkDefGrowth[2][c][r] + 2;
        } else if (lv < 11) {
            *p += Stg30_AtkDefGrowth[3][c][r] + 1;
        } else {
            *p = *p + Stg30_AtkDefGrowth[4][c][r];
        }
        t = *p;
        if ((s16)*p >= 1000) {
            t = 999;
        }
        *p = t;
    }
    lv = e->speed;
    p = (u16 *)&e->speed;
    r = Rand_Next() & 3;
    c = Digi_GetStatGrowth(e->digiId, 4);
    if (lv < 21) {
        *p += Stg30_SpeedGrowth[0][c][r] + 3;
    } else if (lv < 51) {
        *p += Stg30_SpeedGrowth[1][c][r] + 2;
    } else if (lv < 101) {
        *p += Stg30_SpeedGrowth[2][c][r] + 1;
    } else {
        *p = *p + Stg30_SpeedGrowth[3][c][r];
    }
    t = *p;
    if ((s16)*p >= 1000) {
        t = 999;
    }
    *p = t;
    e->hp = e->maxHp;
    e->mp = e->maxMp;
}

void Stg30_ResultUpdate(Actor *a0) {
    Stg30ResultWork *w = (Stg30ResultWork *)a0->work;
    Stg30TextArgs args;
    Stg30TextRec *r;
    s32 i;
    s32 j;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->text, 14);
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].hp != 0) {
                Stg30_Battle.entries[i].exp += w->pair.field_0;
            }
            w->expToNext[i] = Digi_GetExpToNextLevel(Stg30_Battle.entries[i].level, Stg30_Battle.entries[i].maxLevel,
                                                   Stg30_Battle.entries[i].exp);
            if (w->expToNext[i] == 0 && Stg30_Battle.entries[i].hp != 0) {
                Stg30_Battle.leveledUp[i] = 1;
                Stg30_LevelUpStats(&((Stg30StateDigis *)&Stg30_Battle)->digis[i]);
            } else {
                Stg30_Battle.leveledUp[i] = 0;
            }
        }
        Save_GameState.bits += w->pair.field_4;
        if (Save_GameState.bits > 99999999) {
            Save_GameState.bits = 99999999;
        }
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            for (j = 0; j < 14; j++) {
                r = &Stg30_ResultTextLayout[j];
                if (r->slot == 9 || Stg30_Battle.entries[r->slot].digiId != 0) {
                    if (r->src < 3) {
                        args.text = (s32)D_80073D24[r->src].name;
                    } else {
                        args.text = (s32)Cd_GetFileEntry(r->src | 0x1FD0000);
                    }
                    if (j == 7) {
                        args.strArg0 = (s32)Stg30_NumToDigits(w->buf0, w->pair.field_0);
                    }
                    if (j == 13) {
                        args.strArg0 = (s32)Stg30_NumToDigits(w->buf1, w->pair.field_4);
                    }
                    args.bigFont = r->bigFont;
                    args.color = r->color;
                    args.pos = r->pos;
                    args.charAdvance = 0;
                    args.lineAdvance = 0;
                    args.charDelay = 0;
                    Text_Open(&w->text[j], (TextOpenArgs *)&args);
                }
            }
            Task_NextState1(a0);
        case 1:
            if (Pad_Cross > 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg30_ResultDestroy(Actor *a0) {
    Text_CloseArray(((Stg30ResultWork *)a0->work)->text, 14);
    Task_DefaultDestroy(a0);
}

void Stg30_ResultDraw(Actor *a0) {
    Stg30ResultWork *w = (Stg30ResultWork *)a0->work;
    GfxPart *p;
    s32 i;
    s32 draw;

    for (i = 0; i < 6; i++) {
        draw = 1;
        p = (GfxPart *)Cd_GetFileEntry(Stg30_ResultParts[i]);
        switch (i) {
        case 0:
        case 1:
        case 2:
            if (Stg30_Battle.entries[i].digiId == 0) {
                draw = 0;
                break;
            }
            if (Stg30_Battle.leveledUp[i] != 0) {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0);
            } else {
                Gfx_HidePartsByMask((GfxPartMaskView *)p, 0x10);
            }
            Gfx_SetPartsNumber(p, 1, 8, Stg30_Battle.entries[i].exp);
            Gfx_SetPartsNumber(p, 4, 8, w->expToNext[i]);
            Gfx_SetPartsNumber(p, 8, 2, Stg30_Battle.entries[i].level);
            break;
        case 4:
            Gfx_SetPartsNumber(p, 1, 8, Save_GameState.bits);
            break;
        }
        if (draw) {
            Gfx_DrawParts((EntA0 *)p);
        }
    }
}

void Stg30_SkillLearnInit(Actor *a0, Stg30SkillLearnArgs *args) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 i;

    w->slot = args->slot;
    for (i = 0; i < 12; i++) {
        w->skillLists[0][i] = args->skillIds[i];
    }
    Snd_PlayById(0x2B, 0);
}

void Stg30_SkillLearnRefreshList(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 row;
    s32 col;
    s32 k;
    s32 *slot;
    s32 item;
    s32 id;
    s32 scroll;

    for (row = 0; row < 2; row++) {
        scroll = w->scroll[row];
        for (col = 0; col < 10; col++) {
            k = row * 10 + col;
            slot = &w->texts[k];
            Text_Close(slot);
            item = w->skillLists[row][col + scroll];
            if (item != 0) {
                Text_OpenPacked(slot, Skill_GetNameText(item), 0, Stg30_SkillLearnTextPos[k + 4]);
            }
        }
    }
    Text_Close(&w->descText);
    id = w->skillLists[w->column][w->scroll[w->column] + w->cursorRow[w->column]];
    if (id != 0 && w->buttonRowActive == 0) {
        Text_OpenPacked(&w->descText, Skill_GetDescText(id), 0, Stg30_SkillLearnTextPos[27]);
        w->mpCost = Skill_GetMpCost(id);
    } else {
        w->mpCost = 0;
    }
}

void Stg30_SkillLearnRefreshButtons(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 i;

    for (i = 0; i < 3; i++) {
        Text_Close(&w->text[i]);
        if (w->buttonRowActive == 0 || w->buttonIndex != i || !(a0->elapsed & 0x10)) {
            s32 c;
            if (w->buttonIndex == i) c = 4; else c = 5;
            Text_OpenById(&w->text[i], i + 0x188, c, Stg30_SkillLearnTextPos[i + 24]);
        }
    }
}

void Stg30_SkillLearnCompact(Actor *a0, s32 row) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 i;
    s32 n;

    i = 0;
    n = i;
    for (; i < 12; i++) {
        if (w->skillLists[row][i] != 0) {
            w->skillLists[row][n] = w->skillLists[row][i];
            if (i != n) {
                w->skillLists[row][i] = 0;
            }
            n++;
        }
    }
    w->count[row] = n;
}

void Stg30_SkillLearnUpdate(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    s32 *cur;
    s32 *scr;
    s32 *cnt;
    s32 row;
    s32 other;
    s16 v;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->labelTexts, 0x1C);
        a0->digiId = Stg30_Battle.entries[w->slot].digiId;
        for (i = 0; i < 12; i++) {
            w->skillLists[1][i] = Stg30_Battle.entries[w->slot].skillIds[i];
        }
        w->count[0] = 0;
        w->count[1] = 0;
        for (i = 0; i < 12; i++) {
            if (w->skillLists[0][i] != 0) {
                w->count[0]++;
            }
            if (w->skillLists[1][i] != 0) {
                w->count[1]++;
            }
        }
        Text_OpenPacked(&w->labelTexts[0], (s32)D_80073D24[w->slot].name, 0x10, Stg30_SkillLearnTextPos[0]);
        Text_OpenPacked(&w->labelTexts[1], (s32)Cd_GetFileEntry(0x1FD0187), 0x80, Stg30_SkillLearnTextPos[1]);
        Text_OpenById(&w->labelTexts[2], 0x18B, 4, Stg30_SkillLearnTextPos[2]);
        Text_OpenById(&w->labelTexts[3], 0x18C, 4, Stg30_SkillLearnTextPos[3]);
        ((void (*)(s32))Stg30_SetCameraShot)(w->slot + 2);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            w->buttonRowActive = 1;
            do {
                if (Pad_State[0].right > 0) {
                    if (w->buttonIndex != 2) {
                        w->buttonIndex++;
                        Snd_PlayById(0xC, 0);
                    }
                } else if (Pad_State[0].left > 0) {
                    if (w->buttonIndex != 0) {
                        w->buttonIndex--;
                        Snd_PlayById(0xC, 0);
                    }
                } else if (Pad_State[0].cross > 0) {
                    switch (w->buttonIndex) {
                    case 0:
                        for (n = 0; n < 12; n++) {
                            if (w->skillLists[1][n] == 0) {
                                break;
                            }
                        }
                        if (n < 12) {
                            for (j = 0; n < 12; n++) {
                                if (w->skillLists[0][j] == 0) {
                                    break;
                                }
                                w->skillLists[1][n] = w->skillLists[0][j];
                                w->skillLists[0][j++] = 0;
                            }
                        }
                        Stg30_SkillLearnCompact(a0, 0);
                        Stg30_SkillLearnCompact(a0, 1);
                        Snd_PlayById(0xA, 0);
                        break;
                    case 1:
                        Task_NextState1(a0);
                        Snd_PlayById(0xA, 0);
                        break;
                    case 2:
                        Task_NextState0(a0);
                        Snd_PlayById(0xA, 0);
                        break;
                    default:
                        Snd_PlayById(0xA, 0);
                        break;
                    }
                }
            } while (0);
            break;
        case 1:
            w->buttonRowActive = 0;
            do {
                row = w->column;
                cur = &w->cursorRow[row];
                scr = &w->scroll[row];
                cnt = &w->count[row];
                if (Pad_State[0].right > 0) {
                    if (row == 0) {
                        w->column = 1;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].left > 0) {
                    if (row != 0) {
                        w->column = 0;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].repeat & 0x1000) {
                    if (*cur != 0) {
                        *cur -= 1;
                        Snd_PlayById(0xD, 0);
                    } else if (*scr != 0) {
                        *scr -= 1;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].repeat & 0x4000) {
                    if (*cur != 9) {
                        *cur += 1;
                        Snd_PlayById(0xD, 0);
                    } else if (*scr + 10 < *cnt) {
                        *scr += 1;
                        Snd_PlayById(0xD, 0);
                    }
                } else if (Pad_State[0].triangle > 0) {
                    Task_SetState1(a0, 0);
                    Snd_PlayById(0xB, 0);
                } else if (Pad_State[0].cross > 0) {
                    v = w->skillLists[row][*cur + *scr];
                    other = row ^ 1;
                    if (v == 0 || w->count[other] == 12) {
                        Snd_PlayById(0x10, 0);
                    } else if (row != 0 && w->count[row] == 1) {
                        Snd_PlayById(0x10, 0);
                    } else {
                        w->skillLists[other][w->count[other]] = v;
                        w->skillLists[w->column][*cur + *scr] = 0;
                        Stg30_SkillLearnCompact(a0, 0);
                        Stg30_SkillLearnCompact(a0, 1);
                        Snd_PlayById(0xE, 0);
                    }
                }
            } while (0);
            break;
        }
        Stg30_SkillLearnRefreshList(a0);
        Stg30_SkillLearnRefreshButtons(a0);
        break;
    case 2:
        Text_CloseArray(w->labelTexts, 0x1C);
        for (k = 0; k < 12; k++) {
            Stg30_Battle.entries[w->slot].skillIds[k] = w->skillLists[1][k];
        }
        Task_NextState0(a0);
        break;
    }
}

void Stg30_SkillLearnDraw(Actor *a0) {
    Stg30SkillLearnWork *w = (Stg30SkillLearnWork *)a0->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;

    p = (GfxPart *)Cd_GetFileEntry(0x1A1001B);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001C);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001D);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 0x4000) {
            if (w->buttonRowActive != 0) {
                q->visible = 0;
            } else {
                q->visible = 1;
                q->x = w->column != 0 ? 3 : -0x85;
                q->y = w->cursorRow[w->column] * 11 - 0x15;
                q->palette = Math_PingPongRange(a0->elapsed, 4, 0, 3);
            }
        }
    }
    Gfx_SetPartsNumber(p, 0x800, 3, w->mpCost);
    Gfx_DrawParts((EntA0 *)p);
    p = (GfxPart *)Cd_GetFileEntry(0x1A1001E);
    m = (w->scroll[0] == 0) << 1;
    if (w->scroll[0] + 10 >= w->count[0]) {
        m |= 8;
    }
    if (w->scroll[1] == 0) {
        m |= 0x20;
    }
    if (w->scroll[1] + 10 >= w->count[1]) {
        m |= 0x80;
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
    Gfx_DrawParts((EntA0 *)p);
}

void Stg30_JoinPromptInit(Actor *a0, s32 *args) {
    s32 idx = args[0];

    ((Stg30JoinPromptWork *)a0->work)->index = idx;
    a0->digiId = Stg30_Battle.entries[idx].digiId;
}

void Stg30_JoinCreateDigi(Actor *a0, s32 a1) {
    DigiRosterEntry *e = &D_8005F398;

    Digi_InitFromTable(D_8005F794, ((Stg30WorkWord *)a0->work)->field_0 - 3, e);
    if (a1 != 0) {
        e->state = 1;
    }
}

void Stg30_JoinPromptUpdate(Actor *a0) {
    Stg30JoinPromptWork *w = (Stg30JoinPromptWork *)a0->work;
    Stg30GameRoster *g;
    TaskEntry *t;
    Stg30Pair args;
    s32 i;
    s32 cnt;
    s32 n;
    s32 j;
    s32 *p;

    p = (s32 *)a0->u34.children;

    switch (a0->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->text, 2);
        w->fighter = (Actor *)Task_FindFirst(0x509, -1, w->index);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            ((void (*)(s32))Stg30_SetCameraShot)(w->index + 2);
            Stg30_FighterSetVisible(w->fighter, 1);
            a0->elapsed = 0;
            Task_NextState1(a0);
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                if (a0->elapsed < 0x15) {
                    break;
                }
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->param < 3) {
                        Stg30_FighterSetVisible((Actor *)t, 0);
                        Stg30_FighterQueueHomeReset((Actor *)t);
                    }
                }
                Task_NextState2(a0);
                break;
            case 1:
                if (a0->elapsed < 0x78) {
                    break;
                }
                Task_SetState0(w->fighter, 2);
                Task_SetState1(w->fighter, 0xB);
                Task_NextState1(a0);
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                w->windowVisible = 1;
                Text_OpenPacked(&w->text[0], (s32)Digi_GetDefaultName(a0->digiId), 0, Stg30_JoinPromptTextPos[0]);
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018D), 0x81, Stg30_JoinPromptTextPos[1]);
                Flag_Set(0x10, 0);
                Task_NextState2(a0);
                break;
            case 1:
                if (!Flag_Test(0x10)) {
                    break;
                }
                if (Flag_Test(0x11)) {
                    Task_SetState1(a0, 8);
                    break;
                }
                Task_SetState1(a0, 3);
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                cnt = 0;
                for (j = 0; j < 0x24; j++) {
                    if (Save_GameState.elems[j].state >= 2) {
                        cnt++;
                    }
                }
                n = Stg30_MemoryCapacity[D_8005E650 - 0x2F] - Dung_StatePtr->memBugCount;
                if (n > 0 && cnt < n) {
                    Task_SetState1(a0, 4);
                    break;
                }
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018E), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
                break;
            case 1:
                if (Pad_Cross <= 0) {
                    break;
                }
                g = (Stg30GameRoster *)&Save_GameState;
                if (g->field_4A == 0) {
                    Task_SetState1(a0, 6);
                    break;
                }
                if (g->dmTransferBroken != 0) {
                    Task_SetState1(a0, 7);
                    break;
                }
                cnt = 0;
                for (i = 0; i < 0x24; i++) {
                    if (g->elems[i].state == 1) {
                        cnt++;
                    }
                }
                if (cnt < 0x18) {
                    Task_SetState1(a0, 5);
                    break;
                }
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0190), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
                break;
            case 2:
                if (Pad_Cross > 0) {
                    Task_SetState1(a0, 8);
                }
                break;
            }
            break;
        case 4: {
            s32 *q = (s32 *)a0->u34.children;

            switch (a0->stateLevel2) {
            case 0:
            default:
                w->windowVisible = 0;
                Text_Close(&w->text[0]);
                Text_Close(&w->text[1]);
                Stg30_JoinCreateDigi(a0, 0);
                args.field_0 = 0;
                args.field_4 = 0x23;
                Task_Create(0x16, q, (s32)&args);
                Task_NextState2(a0);
                break;
            case 1:
                if (*q != 0) {
                    break;
                }
                Digi_SortRoster();
                Task_NextState0(a0);
                break;
            }
            break;
        }
        case 5:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD018F), 0x81, Stg30_JoinPromptTextPos[1]);
                Flag_Set(0x10, 0);
                Task_NextState2(a0);
                break;
            case 1:
                if (!Flag_Test(0x10)) {
                    break;
                }
                if (!Flag_Test(0x11)) {
                    Task_NextState2(a0);
                    break;
                }
                Task_SetState1(a0, 8);
                break;
            case 2:
                w->windowVisible = 0;
                Text_Close(&w->text[0]);
                Text_Close(&w->text[1]);
                Stg30_JoinCreateDigi(a0, 1);
                args.field_0 = 0;
                args.field_4 = 0x23;
                Task_Create(0x16, p, (s32)&args);
                Task_NextState2(a0);
                break;
            case 3:
                if (*p != 0) {
                    break;
                }
                Digi_SortRoster();
                Task_NextState0(a0);
                break;
            }
            break;
        case 7:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0191), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
                break;
            case 1:
                if (Pad_Cross > 0) {
                    Task_SetState1(a0, 8);
                }
                break;
            }
            break;
        case 6:
        case 8:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Snd_PlayById(0x1C, 0);
                Text_OpenPacked(&w->text[1], (s32)Cd_GetFileEntry(0x1FD0192), 0x81, Stg30_JoinPromptTextPos[1]);
                Task_NextState2(a0);
            case 1:
                if (Pad_Cross > 0) {
                    Task_NextState0(a0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        Text_CloseArray(w->text, 2);
        Task_NextState0(a0);
        break;
    }
}

void Stg30_JoinPromptDraw(Actor *a0) {
    if (((Stg30JoinPromptWork *)a0->work)->windowVisible != 0) {
        Gfx_DrawParts(Cd_GetFileEntry(0x1A10017));
    }
}
