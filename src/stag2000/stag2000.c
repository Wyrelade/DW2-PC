#include "common.h"
#include "stag2000/stag2000.h"

void Stg20_BuildMapGrid(Actor *a) {
    s32 x, y;
    u8 *p;
    s32 bit = 0;
    p = Stg20_GetMapInfo()->bits;
    p--;
    for (x = 0; x < 0x18; x++) {
        for (y = 0; y < 0x18; y++) {
            bit <<= 1;
            if (!(y & 7)) {
                bit = 1;
                p++;
            }
            if (*p & bit) {
                Stg20_MapGrid[y][x] = 1;
            } else {
                Stg20_MapGrid[y][x] = 0;
            }
        }
    }
}

s32 Stg20_GetGridCell(Stg20Cell *c) {
    return Stg20_MapGrid[c->x][c->y];
}

void Stg20_MarkGridOccupant(Stg20Cell *c, s32 set, s32 flag) {
    s32 bit = 0x40;
    s32 m;

    if (flag) {
        bit = 0x80;
    }
    if (set) {
        Stg20_MapGrid[c->x][c->y] |= bit;
    } else {
        m = 0xFF;
        Stg20_MapGrid[c->x][c->y] &= m - bit;
    }
}

void Stg20_MapBgInit(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
    Stg20_BuildMapGrid(a);
}

void Stg20_MapBgUpdate(Actor *a) {
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    s32 *tbl;
    s32 i;

    switch (a->stateLevel0) {
    case 0:
        tbl = (s32 *)Cd_GetFileOrNull(w->fileId);
        for (i = 0; i < 10; i++) {
            if (tbl[i] != 0) {
                w->ids[i] = (w->fileId << 16) + i;
            } else {
                w->ids[i] = 0;
            }
        }
        w->field_2C = 0;
        w->geomY = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                a->elapsed = 0;
                Task_NextState2(a);
            case 1:
                w->field_2C += Stg20_ShakeOffsets[((Stg20BlinkTask *)a)->frameCount & 3].x;
                w->geomY += Stg20_ShakeOffsets[((Stg20BlinkTask *)a)->frameCount & 3].y;
                if (a->elapsed >= 0x78) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    }
}

void Stg20_MapBgDraw(Actor *a) {
    s32 gx = 0;
    s32 gy = 0;
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    Actor *e;
    AllocC40 *t;
    GfxPartPkt *p;
    GfxPartOTag *ot;
    GfxPartTexSlot *tex;
    GfxPart *parts;
    GfxPart *q;
    s32 n;
    s32 j;
    s32 i;
    s16 x;
    s32 sx;

    e = Stg20_FindWalkerByDigiId(0x1F4);
    if (e != 0) {
        if (w->settleFrames >= 5) {
            n = 1;
        } else {
            w->settleFrames++;
            n = 0x14;
        }
        for (j = 0; j < n; j++) {
            t = ((ContC40 *)e)->transform;
            Actor_ProjectToScreen(e);
            if (t->screenX < -0x18) {
                w->field_2C += (s16)(-t->screenX - 0x18) >> 3;
            } else if (t->screenX > 0x18) {
                w->field_2C -= (s16)(t->screenX - 0x18) >> 3;
            }
            if (t->screenY < -0x18) {
                w->geomY += (s16)(-t->screenY - 0x18) >> 3;
            } else if (t->screenY > 0x18) {
                w->geomY -= (s16)(t->screenY - 0x18) >> 3;
            }
            if (w->geomY > 0x20) {
                w->geomY = 0x20;
            }
            gx = w->field_2C / 2 - 0xA0;
            gy = w->geomY / 2;
            SetGeomOffset(w->field_2C, w->geomY);
        }
    }
    ot = (GfxPartOTag *)Sys_State.otLayers.addr[6];
    p = (GfxPartPkt *)Sys_State.packet.addr;
    for (sx = gx - 0xA0, i = 0; i < 10; i++) {
        if (w->ids[i] != 0) {
            tex = (GfxPartTexSlot *)Gfx_FindOrLoadTexSlot(w->ids[i]);
            do {
                p->s.c = *(Col1CE9C *)&Gfx_NeutralRgb;
                p->s.tag.len = 4;
                p->s.c.code = 0x64;
                x = sx + i * 64;
                p->s.x0 = x;
                if (p->s.x0 < -0xE0) {
                    break;
                }
                if (p->s.x0 > 0xA0) {
                    break;
                }
                p->s.u0 = tex->u;
                p->s.w = 0x40;
                p->s.y0 = gy - 0x80;
                p->s.v0 = 0;
                p->s.h = 0xFF;
                p->s.clut = (tex->index + 0x1E0) << 6;
                p->s.tag.addr = ot->addr;
                ot->addr = (u32)p;
                p = (GfxPartPkt *)(&p->s + 1);
                p->t.tag.len = 1;
                p->t.code = 0xE1000600 | (tex->tpage & 0x9FF);
                p->t.tag.addr = ot->addr;
                ot->addr = (u32)p;
                p = (GfxPartPkt *)(&p->t + 1);
            } while (0);
        }
    }
    Sys_PacketCursor = (s32)p;
    if (Stg20_GetMapInfo()->overlayParts != 0) {
        parts = (GfxPart *)Cd_GetFileEntry(Stg20_GetMapInfo()->overlayParts);
        for (q = parts; q->fileId != 0; q++) {
            if (q->groupMask & 4) {
                q->palette = Math_CycleRange(a->elapsed, 8, 0, 7);
            }
            q->x = gx + 0xA0;
            q->y = gy;
        }
        Gfx_DrawParts((s32)parts);
    }
}

void Stg20_StartBgShake(void) {
    Actor *a = (Actor *)Task_FindFirst(0x301, -1, -1);

    if (a != NULL && a->stateLevel0 == 1) {
        Task_SetState1(a, 1);
    }
}

void Stg20_StaticBgInit(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
}

void Stg20_StaticBgUpdate(Actor *a) {
    Stg20LoadWork *w = (Stg20LoadWork *)a->work;
    s32 *tbl;
    s32 i;

    switch (a->stateLevel0) {
    case 0:
        tbl = (s32 *)Cd_GetFileOrNull(w->fileId);
        for (i = 0; i < 10; i++) {
            if (tbl[i] != 0) {
                w->ids[i] = (w->fileId << 16) + i;
            } else {
                w->ids[i] = 0;
            }
        }
        SetGeomOffset(0, 0);
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0x10);
            Task_NextState1(a);
        case 1:
            if (Sys_State.fadeLevel == 0xFF) {
                switch (w->field_2C) {
                case 0:
                default:
                    Sys_State.nextGameMode = 0x303;
                    Sys_State.modeArg = 3;
                    break;
                case 1:
                    Sys_State.nextGameMode = 0x200;
                    break;
                }
                Task_NextState1(a);
            }
            break;
        case 2:
            break;
        }
        break;
    }
}

void Stg20_StaticBgDraw(Actor *a)
{
  Stg20LoadWork *w = (Stg20LoadWork *) a->work;
  GfxPartPkt *p = (GfxPartPkt *) Sys_State.packet.addr;
  GfxPartOTag *ot = (GfxPartOTag *) Sys_State.otLayers.addr[6];
  GfxPartTexSlot *t;
  s32 i;
  s16 x;
  i = 0;
  while (i < 10)
  {
    if (w->ids[i] != 0)
    {
      t = (GfxPartTexSlot *) Gfx_FindOrLoadTexSlot(w->ids[i]);
      p->s.c = *((Col1CE9C *) (&Gfx_NeutralRgb));
      p->s.tag.len = 4;
      p->s.c.code = 0x64;
      x = (i * 64) - 0xA0;
      p->s.x0 = x;
      if (x >= (-0xE0))
      {
        if (x <= 0xA0)
        {
 do { p->s.u0 = t->u; p->s.w = 0x40; p->s.y0 = -0x80; p->s.v0 = 0; p->s.h = 0xFF; p->s.clut = (t->index + 0x1E0) << 6; p->s.tag.addr = ot->addr; ot->addr = (u32) p; p = (GfxPartPkt *) ((&p->s) + 1); p->t.tag.len = 1; p->t.code = 0xE1000600 | (t->tpage & 0x9FF); p->t.tag.addr = ot->addr; ot->addr = (u32) p; p = (GfxPartPkt *) ((&p->t) + 1); } while (0);
        }
      }
    }
    i++;
  }

  Sys_PacketCursor = (s32) p;
}

void Stg20_LabDnaDigivolve(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    s32 buf[9];
    Stg20WarpFx args;
    Stg20Digi nd;
    Stg20Digi *p;
    Stg20Digi *q;
    s32 t;
    s32 i;
    s32 ok;
    s32 v;
    s32 hi;
    s32 lo;
    s32 best;
    s32 bestv;
    s32 n;
    s32 s;
    u8 ml;
    s32 j;
    s32 k;
    s32 f;

    Stg20_LabIsDna[0] = 1;
    switch (a->stateLevel2) {
    case 0:
    default:
        switch (a->stateLevel3) {
        case 0:
        default:
            if (slot[1] != 0) {
                Task_SetState0((Actor *)slot[1], 2);
            }
            Stg20_MenuState.excludeFirst = 0;
            Task_Create(0x30C, &slot[3], 0);
            Stg20_MsgWinShowSysMsg(0x117);
            Stg20_MenuState.pickStep = 1;
            Task_Create(0x30E, &slot[4], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState0((Actor *)slot[4], 2);
                if (D_800709B8.result != 0) {
                    Task_SetState1(a, 0);
                } else {
                    Task_NextState2(a);
                }
            }
            break;
        }
        break;
    case 1:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.modelDigiId = Save_GameState.elems[Stg20_MenuState.pickedIndex].digiId;
            Stg20_MenuState.modelNoGrow = 0;
            Stg20_MenuState.modelSlide = 0;
            Task_Create(0x30A, &slot[1], 0);
            Task_NextState3(a);
        case 1:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 2;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (Stg20_MenuState.result) {
                case 0:
                    Task_NextState2(a);
                    break;
                case 1:
                case 3:
                    Task_SetState2(a, 0);
                    break;
                case 2:
                    Task_SetState2(a, 3);
                    Stg20_MenuState.dnaParent0 = Stg20_MenuState.infoRosterIndex;
                    break;
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 1);
                Task_SetState3(a, 1);
            }
            break;
        }
        break;
    case 3:
        switch (a->stateLevel3) {
        case 0:
        default:
            Task_SetState1((Actor *)slot[1], 1);
            if (slot[2] != 0) {
                Task_SetState0((Actor *)slot[2], 2);
            }
            Stg20_MenuState.excludeFirst = 1;
            Task_Create(0x30C, &slot[3], 0);
            Stg20_MsgWinShowDigiMsg(0x11C, Save_GameState.elems[Stg20_MenuState.dnaParent0].digiId);
            Stg20_MenuState.pickStep = 2;
            Task_Create(0x30E, &slot[4], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState0((Actor *)slot[4], 2);
                if (Stg20_MenuState.result != 0) {
                    if (slot[1] != 0) {
                        Task_SetState0((Actor *)slot[1], 2);
                    }
                    Task_SetState2(a, 0);
                } else {
                    Stg20_MenuState.dnaParent1 = Stg20_MenuState.pickedIndex;
                    Task_NextState2(a);
                }
            }
            break;
        }
        break;
    case 4:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.modelDigiId = Save_GameState.elems[Stg20_MenuState.dnaParent1].digiId;
            Stg20_MenuState.modelNoGrow = 0;
            Stg20_MenuState.modelSlide = 1;
            Task_Create(0x30A, &slot[2], 0);
            Task_NextState3(a);
        case 1:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 3;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.dnaParent1;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 0:
                    Task_NextState2(a);
                    break;
                case 1:
                case 3:
                    Task_SetState2(a, 3);
                    break;
                case 2:
                    Task_SetState2(a, 6);
                    Task_SetState0((Actor *)slot[5], 3);
                    break;
                }
            }
            break;
        }
        break;
    case 5:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 4);
                Task_SetState3(a, 1);
            }
            break;
        }
        break;
    case 6:
        switch (a->stateLevel3) {
        case 0:
        default:
            ok = 1;
            buf[0] = Digi_GetModelFile(Stg20_MenuState.evoTargetId);
            buf[1] = Anim_GetModelAnimFile(Stg20_MenuState.evoTargetId, 0);
            buf[2] = 0xDD8;
            buf[3] = 0xDD7;
            buf[4] = 0x25B;
            buf[5] = 0x1A1;
            buf[6] = 0x314;
            buf[7] = 0x25C;
            buf[8] = 0x3D0;
            for (f = 0; f < 9; f++) {
                Cd_QueueFile(buf[f]);
                if (Cd_GetFileState(buf[f]) != 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0) {
                Task_NextState3(a);
            }
            break;
        case 1:
            switch (a->stateLevel4) {
            case 0:
            default:
                buf[0] = 0x512;
                buf[1] = 1;
                buf[2] = 0x2A3;
                Task_Create(0x313, &slot[8], (s32)buf);
                Task_NextState4(a);
                Snd_StopById(0x101);
                break;
            case 1:
                if (((Actor *)slot[8])->stateLevel0 == 0) {
                    break;
                }
                Task_SetState0((Actor *)slot[8], 2);
                Task_SetState1((Actor *)w->menu, 2);
                w->timer = 0x5A;
                w->busy = 1;
                Task_NextState3(a);
                break;
            }
            break;
        case 2:
            if (--w->timer != 0) {
                break;
            }
            args.animFileId = 0xDD8;
            args.modelFileId = 0xDD7;
            args.rotY = 0;
            args.duration = 0x78;
            args.z = 0;
            args.y = 0;
            args.x = 0;
            Task_Create(7, &slot[6], (s32)&args);
            Task_SetState1((Actor *)slot[1], 2);
            Task_SetState1((Actor *)slot[2], 1);
            Task_NextState3(a);
            break;
        case 3:
            if (((Actor *)w->menu)->stateLevel2 == 3) {
                Stg20_MenuState.modelDigiId = Stg20_MenuState.evoTargetId;
                Stg20_MenuState.modelNoGrow = 1;
                Stg20_MenuState.modelSlide = 0;
                Task_Create(0x30A, &slot[1], 0);
                Task_SetState0((Actor *)slot[2], 3);
                Task_NextState3(a);
            }
            break;
        case 4:
            if (((Actor *)w->menu)->stateLevel1 != 0) {
                break;
            }
            p = (Stg20Digi *)&D_8005E704[Stg20_MenuState.dnaParent0];
            q = (Stg20Digi *)&D_8005E704[Stg20_MenuState.dnaParent1];
            t = Digi_GetRank(Stg20_MenuState.evoTargetId);
            w->busy = 0;
            Snd_PlayById(0x101, 1);
            Mem_Zero(&nd, 0x5C);
            nd.state = 1;
            nd.level = t * 10 + 1;
            nd.digiId = Stg20_MenuState.evoTargetId;
            nd.dp = (p->dp > q->dp ? p->dp : q->dp) + 1;
            if (p->level > q->level) {
                ml = p->level + q->level / 5;
            } else {
                ml = q->level + p->level / 5;
            }
            nd.maxLevel = ml;
            if (ml >= 99) {
                nd.maxLevel = 99;
            }
            if (nd.level == 1) {
                nd.exp = 0;
            } else {
                nd.exp = Digi_GetExpToNextLevel(nd.level - 1, 100, 0);
            }
            s = p->maxHp + q->maxHp;
            switch (t) {
            case 0:
            default:
                v = s * 10;
                break;
            case 1:
                v = s * 34;
                break;
            case 2:
                v = s * 45;
                break;
            }
            nd.hp = nd.maxHp = v / 100;
            s = p->maxMp + q->maxMp;
            switch (t) {
            case 0:
            default:
                v = s * 10;
                break;
            case 1:
                v = s * 34;
                break;
            case 2:
                v = s * 45;
                break;
            }
            nd.mp = nd.maxMp = v / 100;
            if (p->attack > q->attack) {
                hi = p->attack;
                lo = q->attack;
            } else {
                lo = p->attack;
                hi = q->attack;
            }
            switch (t) {
            case 0:
            default:
                nd.attack = (hi * 40 + lo * 30) / 100;
                break;
            case 1:
                nd.attack = (hi * 50 + lo * 30) / 100;
                break;
            case 2:
                nd.attack = (hi * 50 + lo * 40) / 100;
                break;
            }
            if (p->defense > q->defense) {
                hi = p->defense;
                lo = q->defense;
            } else {
                lo = p->defense;
                hi = q->defense;
            }
            switch (t) {
            case 0:
            default:
                nd.defense = (hi * 40 + lo * 30) / 100;
                break;
            case 1:
                nd.defense = (hi * 50 + lo * 30) / 100;
                break;
            case 2:
                nd.defense = (hi * 50 + lo * 40) / 100;
                break;
            }
            switch (t) {
            case 0:
            default:
                nd.speed = (p->speed + q->speed) * 30 / 100;
                break;
            case 1:
                nd.speed = (p->speed + q->speed) * 45 / 100;
                break;
            case 2:
                nd.speed = (p->speed + q->speed) / 2;
                break;
            }
            best = 0;
            bestv = 0;
            for (i = 0; i < 12; i++) {
                if (p->skills[i] != 0 && t >= Skill_GetRank(p->skills[i])) {
                    v = Skill_GetPower(p->skills[i]);
                    if (bestv < v) {
                        bestv = v;
                        best = p->skills[i];
                    }
                }
                if (q->skills[i] != 0 && t >= Skill_GetRank(q->skills[i])) {
                    v = Skill_GetPower(q->skills[i]);
                    if (bestv < v) {
                        bestv = v;
                        best = q->skills[i];
                    }
                }
            }
            nd.skills[0] = Digi_GetLearnedSkill(nd.digiId);
            if (best != 0 && nd.skills[0] != best) {
                nd.skills[1] = best;
            }
            for (j = 0, n = 0; j < 12; j++) {
                if (p->skills[j] != nd.skills[0] && p->skills[j] != nd.skills[1]) {
                    nd.learned[n++] = p->skills[j];
                }
                if (q->skills[j] != nd.skills[0] && q->skills[j] != nd.skills[1]) {
                    nd.learned[n++] = q->skills[j];
                }
            }
            nd.parent0 = p->digiId;
            nd.parent1 = q->digiId;
            p->state = 0;
            q->state = 0;
            Digi_SortRoster();
            for (k = 0; k < 0x24; k++) {
                if (Save_GameState.elems[k].state == 0) {
                    break;
                }
            }
            Save_GameState.elems[k] = *(DigiRosterEntry *)&nd;
            Stg20_DnaNewSlot = k;
            Task_NextState2(a);
            break;
        }
        break;
    case 7:
        switch (a->stateLevel3) {
        case 0:
        default:
            buf[4] = 0;
            buf[5] = Stg20_DnaNewSlot;
            Task_Create(0x16, &slot[7], (s32)&buf[4]);
            Task_NextState3(a);
            break;
        case 1:
            if (slot[7] == 0) {
                Task_NextState2(a);
            }
            break;
        }
        break;
    case 8:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.pickedIndex = Stg20_MenuState.dnaNewSlot;
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 4;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 1:
                case 2:
                case 3:
                    Digi_SortRoster();
                    Save_GameState.elems[0].state = Save_GameState.elems[0].state != 0 ? 3 : 0;
                    Save_GameState.elems[1].state = Save_GameState.elems[1].state != 0 ? 4 : 0;
                    Save_GameState.elems[2].state = Save_GameState.elems[2].state != 0 ? 5 : 0;
                    Task_SetState2(a, 0);
                    break;
                case 0:
                    Task_NextState2(a);
                    break;
                }
            }
            break;
        }
        break;
    case 9:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 8);
            }
            break;
        }
        break;
    }
}

void Stg20_LabDigivolve(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    s32 buf[5];
    Stg20WarpFx args;
    s32 i;
    s32 ok;
    Stg20DigiBoost *e;
    s16 v;

    Stg20_LabIsDna[0] = 0;
    switch (a->stateLevel2) {
    case 0:
    default:
        switch (a->stateLevel3) {
        case 0:
        default:
            if (slot[1] != 0) {
                Task_SetState0((Actor *)slot[1], 2);
            }
            Stg20_MenuState.excludeFirst = 0;
            Task_Create(0x30C, &slot[3], 0);
            Stg20_MsgWinShowSysMsg(0x116);
            Stg20_MenuState.pickStep = 0;
            Task_Create(0x30E, &slot[4], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState0((Actor *)slot[4], 2);
                if (D_800709B8.result != 0) {
                    Task_SetState1(a, 0);
                } else {
                    Task_NextState2(a);
                }
            }
            break;
        }
        break;
    case 1:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.modelDigiId = Save_GameState.elems[Stg20_MenuState.pickedIndex].digiId;
            Stg20_MenuState.modelNoGrow = 0;
            Stg20_MenuState.modelSlide = 0;
            Task_Create(0x30A, &slot[1], 0);
            Task_NextState3(a);
        case 1:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 0;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 0:
                    Task_NextState2(a);
                    break;
                case 1:
                case 3:
                    Task_SetState2(a, 0);
                    break;
                case 2:
                    Task_SetState0((Actor *)slot[5], 3);
                    Task_SetState2(a, 3);
                    break;
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 1);
                Task_SetState3(a, 1);
            }
            break;
        }
        break;
    case 3:
        switch (a->stateLevel3) {
        case 0:
        default:
            ok = 1;
            buf[0] = Digi_GetModelFile(Stg20_MenuState.evoTargetId);
            buf[1] = Anim_GetModelAnimFile(Stg20_MenuState.evoTargetId, 0);
            buf[2] = 0xDDB;
            buf[3] = 0xDD9;
            buf[4] = 0x3D0;
            for (i = 0; i < 5; i++) {
                Cd_QueueFile(buf[i]);
                if (Cd_GetFileState(buf[i]) != 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0) {
                Task_NextState3(a);
            }
            break;
        case 1:
            switch (a->stateLevel4) {
            case 0:
            default:
                buf[0] = 0x512;
                buf[1] = 0;
                buf[2] = 0x2A3;
                Task_Create(0x313, &slot[8], (s32)buf);
                Task_NextState4(a);
                Snd_StopById(0x101);
                break;
            case 1:
                if (((Actor *)slot[8])->stateLevel0 == 0) {
                    break;
                }
                Task_SetState0((Actor *)slot[8], 2);
                Task_SetState1((Actor *)w->menu, 1);
                w->busy = 1;
                Task_NextState4(a);
                w->timer = 0x5A;
            case 2:
                if (--w->timer != 0) {
                    break;
                }
                args.animFileId = 0xDDB;
                args.modelFileId = 0xDD9;
                args.rotY = 0;
                args.duration = 0x78;
                args.z = 0;
                args.y = 0;
                args.x = 0;
                Task_Create(7, &slot[6], (s32)&args);
                Task_NextState3(a);
                break;
            }
            break;
        case 2:
            if (((Actor *)w->menu)->stateLevel2 == 3) {
                Stg20_MenuState.modelDigiId = Stg20_MenuState.evoTargetId;
                Stg20_MenuState.modelNoGrow = 1;
                Stg20_MenuState.modelSlide = 0;
                Task_Create(0x30A, &slot[1], 0);
                Task_NextState3(a);
            }
            break;
        case 3:
            if (((Actor *)w->menu)->stateLevel1 == 0) {
                w->busy = 0;
                Snd_PlayById(0x101, 1);
                e = (Stg20DigiBoost *)&D_8005E704[Stg20_MenuState.infoRosterIndex];
                e->digiId = Stg20_MenuState.evoTargetId;
                e->maxHp += 30;
                v = e->maxHp;
                if (v >= 1000) {
                    v = 999;
                }
                e->maxHp = v;
                e->hp = v;
                e->maxMp += 30;
                v = e->maxMp;
                if (v >= 1000) {
                    v = 999;
                }
                e->maxMp = v;
                e->mp = v;
                e->field_46 = Digi_GetLearnedSkill(e->digiId);
                Task_NextState2(a);
            }
            break;
        }
        break;
    case 4:
        switch (a->stateLevel3) {
        case 0:
        default:
            if (slot[5] == 0) {
                Task_Create(0x30D, &slot[5], 0);
            }
            Stg20_MenuState.infoMode = 1;
            Stg20_MenuState.infoRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x30F, &slot[3], 0);
            Task_NextState3(a);
            break;
        case 2:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                switch (D_800709B8.result) {
                case 1:
                case 2:
                case 3:
                    Task_SetState2(a, 0);
                    break;
                case 0:
                    Task_NextState2(a);
                    break;
                }
            }
            break;
        }
        break;
    case 5:
        switch (a->stateLevel3) {
        case 0:
        default:
            Stg20_MenuState.skillRosterIndex = Stg20_MenuState.pickedIndex;
            Task_Create(0x310, &slot[3], 0);
            Task_NextState3(a);
        case 1:
            if (((Actor *)slot[3])->stateLevel0 == 2) {
                Task_SetState2(a, 4);
            }
            break;
        }
        break;
    }
}

void Stg20_DigiLabUpdate(Actor *a) {
    Stg20CtrlWork *w = (Stg20CtrlWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        Stg20_MenuState.labMode = 0;
        Task_Create(0x30D, &slot[5], 0);
        w->menu = Task_FindFirst(0x308, -1, -1);
        Stg20_MenuState.menuAllowed = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_SetState0((Actor *)w->menu, 0);
                Task_Create(0x30B, &slot[3], 0);
                Stg20_MsgWinShowSysMsg(0x115);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    if (Stg20_MenuState.result != 0) {
                        Task_NextState0(a);
                    } else {
                        if (Stg20_MenuState.labMode != 0) {
                            Task_NextState1(a);
                        }
                        Task_NextState1(a);
                    }
                }
                break;
            }
            break;
        case 1:
            Stg20_LabDigivolve(a);
            break;
        case 2:
            Stg20_LabDnaDigivolve(a);
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.modeArg = 1;
                Sys_State.nextGameMode = Sys_State.prevGameMode;
            }
            break;
        }
        break;
    }
}

void Stg20_DigiLabDraw(Actor *a) {
    Stg20ScrollWork *w = (Stg20ScrollWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD12000B);
    GfxPart *q;

    if (w->on != 0) {
        if (w->level != 7) {
            w->level++;
        }
    } else {
        if (w->level != 0) {
            w->level--;
        }
    }
    for (q = p; q->fileId != 0; q++) {
        switch (q->groupMask) {
        case 1:
            q->y = w->scroll;
            break;
        case 2:
            q->x = q->x == -0x133 ? 0 : q->x - 1;
            break;
        case 4:
            q->x = q->x == 0xC1 ? 0 : q->x + 1;
            break;
        case 8:
            q->x = q->x == 0x18E ? 0 : q->x + 2;
            break;
        case 16:
            q->x = q->x == -0x18E ? 0 : q->x - 2;
            break;
        }
        if (q->groupMask & 0x1E) {
            if (w->level != 0) {
                q->palette = w->level;
                q->visible = 1;
            } else {
                q->visible = 0;
            }
        }
    }
    w->scroll = w->scroll == -0xEC ? 0 : w->scroll - 1;
    Gfx_DrawParts((s32)p);
}

void Stg20_ItemShopUpdate(Actor *a) {
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        Task_Create(0x312, &slot[0], 0);
        Task_Create(0x315, &slot[1], 0);
        D_80070A00 = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_Create(0x316, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    if (Stg20_MenuState.result != 0) {
                        Task_NextState0(a);
                    } else if (Stg20_MenuState.menuChoice == 0) {
                        Task_SetState1(a, 1);
                    } else {
                        Task_SetState1(a, 2);
                    }
                }
                break;
            }
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                Stg20_ShopSellMode = 0;
                Task_Create(0x317, &slot[3], 0);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                Stg20_ShopSellMode = 1;
                Task_Create(0x317, &slot[3], 0);
                Task_NextState2(a);
            case 1:
                if (slot[3] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = Sys_State.prevGameMode;
                Sys_State.modeArg = Sys_State.gameMode == 0x330 ? 5 : 6;
            }
            break;
        }
        break;
    }
}

void Stg20_RefillBeetleHpEp(void) {
    Stg20GameState *g = (Stg20GameState *)&Save_GameState;

    g->maxHp = g->hp = Stg20_EngineHpTbl[g->slotItems[1] - 1];
    g->maxMp = g->mp = Stg20_BatteryEpTbl[g->slotItems[3] - 0x35];
}

void Stg20_BeetleShopUpdate(Actor *a) {
    s32 *slot = (s32 *)a->u34.children;

    switch (a->stateLevel0) {
    case 0:
        D_80070A00 = 0;
        Task_Create(0x312, &slot[0], 0);
        Task_Create(0x315, &slot[1], 0);
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                if (slot[1] == 0) {
                    Task_Create(0x315, &slot[1], 0);
                }
                Task_Create(0x318, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    if (Stg20_MenuState.result != 0) {
                        Task_NextState0(a);
                    } else if (Stg20_MenuState.menuChoice == 0) {
                        Task_SetState0((Actor *)slot[1], 3);
                        Task_SetState1(a, 1);
                    } else {
                        Task_SetState1(a, 2);
                    }
                }
                break;
            }
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_Create(0x31A, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        case 2:
            switch (a->stateLevel2) {
            case 0:
            default:
                Task_Create(0x31B, &slot[2], 0);
                Task_NextState2(a);
            case 1:
                if (slot[2] == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Stg20_RefillBeetleHpEp();
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.modeArg = 7;
                Sys_State.nextGameMode = Sys_State.prevGameMode;
            }
            break;
        }
        break;
    }
}

void Stg20_StageMain(Actor *a) {
    Stg20MainWork *w = (Stg20MainWork *)a->work;
    s32 *slot = (s32 *)a->u34.children;
    Stg20Spawn sp;
    Stg20Start *st;
    Stg20BytePair *src;
    s32 id;
    s32 n;
    s32 k;
    s32 task;

    switch (a->stateLevel0) {
    case 0:
        Gpu_AllocPacketBufs(0x25800);
        Sys_SetFrameRate30();
        if (Sys_GameMode[0] != 0x32F) {
            Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
        } else {
            Gpu_InitDoubleBuffer(0x140, 0x1E0, 2, 0);
        }
        Gpu_SetBgClearColor(0, 0, 0);
        Gpu_ClearScreens();
        Gfx_FadeInFromBlack(0x1E);
        Task_Create(9, &slot[0], 0);
        Flag_SetTableFile(Stg20_GetMapInfo()->flagTableFile);
        Task_Create(0x308, &slot[5], 0);
        if (Sys_State.gameMode < 0x32A) {
            st = &((Stg20Start *)Stg20_GetMapInfo()->startRecs)[Sys_State.modeArg];
            sp.id = 0x1F4;
            sp.blk[0].x = st->x;
            sp.blk[0].y = st->y;
            sp.blk[1].x = 0;
            sp.blk[1].y = 0;
            sp.facing = st->dir;
            Task_Create(0x302, &slot[4], (s32)&sp);
            if (Stg20_GetMapInfo()->flagTableFile != 0) {
                n = 0;
                for (id = Flag_FirstPassingEntry(); id != -1; id = Flag_NextPassingEntry()) {
                    src = (Stg20BytePair *)Flag_GetEntryPosList(id);
                    sp.id = Flag_GetEntryDigiId(id);
                    sp.facing = Flag_GetEntryDir(id);
                    sp.flagEntry = id;
                    for (k = 0; k < 6; k++) {
                        sp.blk[k].x = src[k].x != 0xFF ? src[k].x : 0;
                        sp.blk[k].y = src[k].y != 0xFF ? src[k].y : 0;
                    }
                    Task_Create(0x302, &slot[6 + n], (s32)&sp);
                    n++;
                }
            }
            Task_Create(0x304, &slot[26], 0);
            Task_Create(0x301, &slot[2], Stg20_GetMapInfo()->bgFileId);
            switch (Sys_GameMode[0]) {
            case 0x31D:
                Task_Create(0x31C, &slot[27], 0);
                break;
            case 0x320:
                Task_Create(0x31C, &slot[27], 1);
                break;
            case 0x326:
                Task_Create(0x31C, &slot[27], 2);
                break;
            case 0x327:
                Task_Create(0x31C, &slot[27], 3);
                break;
            }
        } else if (Sys_State.gameMode < 0x32F) {
            w->areaSelect = 1;
            Stg20_MenuState.menuAllowed = 1;
            Task_Create(0x305, &slot[2], Stg20_GetMapInfo()->bgFileId);
            Task_Create(0x306, &slot[3], 0);
        } else {
            if (Sys_State.gameMode < 0x330) {
                task = 0x307;
            } else if (Sys_State.gameMode < 0x333) {
                task = 0x314;
            } else {
                task = 0x319;
            }
            Task_Create(task, &slot[2], 0);
        }
        Gfx_InitLights();
        ((Stg20MainWork *)a->work)->field_0 = -1;
        Stg20_MenuState.talkActive = 0;
        if (Stg20_GetMapInfo()->sndSlotContent != 0) {
            Snd_UnloadSlot(2);
            Snd_SetSlotContent(1, Stg20_GetMapInfo()->sndSlotContent);
        }
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        if (Sys_State.fadeLevel != 0) {
            Mem_Zero(Pad_State, 0x40);
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Flag_Set(0x10, 0);
                Task_NextState2(a);
            case 1:
                break;
            }
            if (w->bgmOn == 0 && Snd_AnySlotLoading() == 0) {
                if (Stg20_GetMapInfo()->bgmId != -1) {
                    Snd_PlayById(Stg20_GetMapInfo()->bgmId, 1);
                }
                w->bgmOn = 1;
            }
            if (((Stg20BlinkTask *)a)->frameCount == 10) {
                Cd_QueueFile(0x312);
                Cd_QueueFile(0x315);
                Cd_QueueFile(0x325);
            }
            if (((Stg20BlinkTask *)a)->frameCount == 15
                && ((Sys_State.gameMode == 0x307 && Flag_Test(0x320) == 0)
                    || (Sys_GameMode[0] == 0x301 && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x320) == 1 && Flag_Test(0x2336) == 1)
                    || (Sys_GameMode[0] == 0x304 && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x32A) == 1)
                    || (Sys_GameMode[0] == 0x308 && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x320) == 1 && Flag_Test(0x32B) == 1)
                    || (Sys_GameMode[0] == 0x30C && Flag_Test(0x3E8) == 1 && Flag_Test(0x5DD) == 1
                        && Flag_Test(0x32C) == 1))) {
                Cd_QueueFile(0x1FD);
                Cd_QueueFile(0x1A1);
                Cd_QueueFile(0x314);
                Cd_QueueFile(0x25C);
            }
            if (Pad_Circle > 0 && Stg20_MenuState.talkActive == 0 && Sys_GameMode[0] < 0x32F
                && Stg20_MenuState.menuAllowed != 0 && Snd_AnySlotLoading() == 0) {
                Task_Create(0xB, &slot[1], 0);
                a->childCount = 2;
                Task_NextState1(a);
                if (w->areaSelect != 0) {
                    Stg20_AreaSelectShowName((Actor *)slot[3], 0);
                }
            }
            break;
        case 1:
            if (slot[1] == 0) {
                a->childCount = 0x1C;
                if (w->areaSelect != 0 && Menu_TopMenuResult != 0) {
                    Gfx_FadeSetBlack();
                    Sys_State.nextGameMode = 0x601;
                    Task_NextState0(a);
                } else {
                    Gfx_FadeInFromBlack(0x20);
                    Task_SetState1(a, 0);
                }
                if (w->areaSelect != 0) {
                    Stg20_AreaSelectShowName((Actor *)slot[3], 1);
                }
            }
            break;
        }
        break;
    }
}

Stg20MapFile *Stg20_GetMapInfo(void) {
    Stg20MapFile *f = (Stg20MapFile *)Cd_GetFileEntry(((Stg20Mode *)Sys_GameMode)->lo + 0x308FFFF);
    s32 base;

    if (f->loaded == 0) {
        base = Cd_GetFileOrNull(0x309);
        f->loaded = 1;
        f->exits += base;
        f->startRecs += base;
        f->bits += base;
        f->stepSndBits = f->stepSndBits != 0 ? f->stepSndBits + base : 0;
    }
    return f;
}

void Stg20_ApplyStartPreset(s32 arg0) {
    s32 i;
    s32 j;

    if (arg0 == 0) {
        ((Stg20GameInit *)&Save_GameState)->start = Stg20_StartPreset0;
        Save_GameState.elems[0].state = 0;
        Save_GameState.elems[1].state = 0;
        Save_GameState.elems[2].state = 0;
    } else {
        ((Stg20GameInit *)&Save_GameState)->start = Stg20_StartPreset1;
        Digi_InitFromTable(0x99, 0, &Save_GameState.elems[0]);
        Save_GameState.elems[0].state = 3;
        Digi_InitFromTable(0x99, 1, &Save_GameState.elems[1]);
        Save_GameState.elems[1].state = 4;
        Digi_InitFromTable(0x99, 2, &Save_GameState.elems[2]);
        Save_GameState.elems[2].state = 5;
        Digi_SortRoster();
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 8; j++) {
                Save_GameState.elems[i].name[j] = Stg20_PresetDigiNames[i][j];
            }
        }
    }
}

s32 Stg20_OwnsDigi(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state >= 2 && Save_GameState.elems[i].digiId == id) {
            return 1;
        }
    }
    return 0;
}

void Stg20_AddBits(s32 d) {
    GameState *g = &Save_GameState;

    g->bits += d;
    if (g->bits < 0) {
        g->bits = 0;
    }
    if (g->bits > 99999999) {
        g->bits = 99999999;
    }
}

void Stg20_RemoveOwnedDigi(s32 id) {
    s32 i;

    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state >= 2 && Save_GameState.elems[i].digiId == id) {
            Save_GameState.elems[i].state = 0;
            break;
        }
    }
    Digi_SortRoster();
}

s32 Stg20_TestSpecialFlag(s32 id) {
    s32 i;
    s32 n;
    s32 free;
    s32 j;

    switch (id) {
    case 9000:
        n = Item_GetBagCapacity();
        for (j = 0; j < n; j++) {
            if (((Stg20GameState *)&Save_GameState)->bagItems[j] == 0) {
                return 1;
            }
        }
        return 0;
    case 9001:
        n = 0;
        free = 0;
        for (i = 0; i < 0x24; i++) {
            if (Save_GameState.elems[i].state == 0) {
                free = 1;
            }
            if (Save_GameState.elems[i].state >= 2) {
                n++;
            }
        }
        if (free == 0) {
            return 0;
        }
        return n < 12;
    case 9003:
        return Stg20_OwnsDigi(0xDA);
    case 9004:
        return Stg20_OwnsDigi(0xD1);
    case 9005:
        return Stg20_OwnsDigi(0x43);
    case 9023:
        for (n = 0; n < 3; n++) {
            if (((Stg20GameRoster *)&Save_GameState)->elems[n].state == n + 3
                && ((Stg20GameRoster *)&Save_GameState)->elems[n].hp != 0) {
                return 0;
            }
        }
        return 1;
    case 9009:
        return D_8005E64E >= 0x10;
    case 9010:
        return D_8005E64E >= 0x1F;
    case 9012:
        return D_8005F790 == 0x32A;
    case 9034:
        return D_8005F790 == 0x32B;
    case 9013:
        if (Sys_State.gameMode == 0x301 && Sys_State.modeArg == 3) {
            return 1;
        }
        if (Sys_State.gameMode == 0x321 && Sys_State.modeArg == 2) {
            return 1;
        }
        return 0;
    case 9014:
        if (Sys_State.gameMode == 0x301 && Sys_State.modeArg == 4) {
            return 1;
        }
        if (Sys_State.gameMode == 0x321 && Sys_State.modeArg == 3) {
            return 1;
        }
        return 0;
    case 9015:
        return D_8005E628 >= 500;
    case 9016:
        return D_8005E628 >= 1000;
    case 9017:
        return D_8005E628 >= 1500;
    case 9018:
        return D_8005E628 >= 2000;
    case 9019:
        return D_8005E628 >= 2500;
    case 9020:
        return D_8005E628 >= 3000;
    case 9021:
        return D_8005E628 >= 3500;
    case 9022:
        return D_8005E628 >= 4000;
    case 9024:
        return D_8005E632 < 2;
    case 9025:
        return D_8005E632 < 3;
    case 9026:
        return D_8005E632 < 4;
    case 9027:
        return D_8005E632 < 5;
    case 9028:
        return D_8005E632 < 6;
    case 9029:
        return D_8005E632 < 7;
    case 9030:
        return D_8005E632 < 8;
    case 9031:
        return D_8005E632 < 9;
    case 9032:
        return D_8005E632 < 10;
    case 9033:
        return D_8005E632 < 11;
    case 9035:
        if (Flag_Test(0x2C6) == 0) {
            return 0;
        }
        if (Flag_Test(0x2C7) == 0) {
            return 0;
        }
        return Flag_Test(0x2C8) != 0;
    }
    return 0;
}

void Stg20_SetSpecialFlag(s32 id, s32 on) {
    s32 i;
    s32 j;

    if (on == 0) {
        return;
    }
    switch (id) {
    case 0x238C:
        D_8005E64C = 0xEB;
        break;
    case 0x23B5:
        D_8005E64C = 0xEC;
        break;
    case 0x238D:
        D_8005E66E = 0x76;
        break;
    case 0x238E:
        Stg20_ApplyStartPreset(0);
        break;
    case 0x238F:
        Stg20_ApplyStartPreset(1);
        break;
    case 0x2390:
        Stg20_AddBits(2000);
        break;
    case 0x2391:
        Stg20_AddBits(1000);
        break;
    case 0x2392:
        Stg20_RemoveOwnedDigi(0x54);
        Digi_AddNew(0xBF);
        break;
    case 0x2393:
        Stg20_RemoveOwnedDigi(0xC5);
        Digi_AddNew(0xC0);
        break;
    case 0x2394:
        Stg20_RemoveOwnedDigi(0xB);
        Digi_AddNew(0xC1);
        break;
    case 0x2395:
        Stg20_RemoveOwnedDigi(0x16);
        Digi_AddNew(0xC2);
        break;
    case 0x2396:
        Stg20_RemoveOwnedDigi(0x4F);
        Digi_AddNew(0xC3);
        break;
    case 0x2397:
        Stg20_RemoveOwnedDigi(0x85);
        Digi_AddNew(0xC4);
        break;
    case 0x2398:
        Stg20_RemoveOwnedDigi(0xEA);
        Digi_AddNew(0xC5);
        break;
    case 0x2399:
        Stg20_RemoveOwnedDigi(0xCC);
        Digi_AddNew(0xC6);
        break;
    case 0x239A:
        Stg20_RemoveOwnedDigi(0x1A);
        Digi_AddNew(0xC7);
        break;
    case 0x23AA:
        Stg20_AddBits(-500);
        break;
    case 0x23AB:
        Stg20_AddBits(-1000);
        break;
    case 0x23AC:
        Stg20_AddBits(-1500);
        break;
    case 0x23AD:
        Stg20_AddBits(-2000);
        break;
    case 0x23AE:
        Stg20_AddBits(-2500);
        break;
    case 0x23AF:
        Stg20_AddBits(-3000);
        break;
    case 0x23B0:
        Stg20_AddBits(-3500);
        break;
    case 0x23B1:
        Stg20_AddBits(-4000);
        break;
    case 0x239C:
        D_8005E632 = 1;
        break;
    case 0x239D:
        D_8005E632 = 2;
        break;
    case 0x239E:
        D_8005E632 = 3;
        break;
    case 0x239F:
        D_8005E632 = 4;
        break;
    case 0x23A0:
        D_8005E632 = 5;
        break;
    case 0x23A1:
        D_8005E632 = 6;
        break;
    case 0x23A2:
        D_8005E632 = 7;
        break;
    case 0x23A3:
        D_8005E632 = 8;
        break;
    case 0x23A4:
        D_8005E632 = 9;
        break;
    case 0x23A5:
        D_8005E632 = 10;
        break;
    case 0x23A6:
        D_8005E631 = 0;
        break;
    case 0x23A7:
        D_8005E631 = 1;
        break;
    case 0x23A8:
        D_8005E631 = 2;
        break;
    case 0x23B3:
        for (j = 0; j < Item_GetBagCapacity(); j++) {
            if (((Stg20GameState *)&Save_GameState)->bagItems[j] == 0xC2) {
                ((Stg20GameState *)&Save_GameState)->bagItems[j] = 0;
                Item_SortList();
                break;
            }
        }
        break;
    case 0x23B2:
    case 0x23B4:
        ((Stg20GameState *)&Save_GameState)->mp = ((Stg20GameState *)&Save_GameState)->maxMp;
        ((Stg20GameState *)&Save_GameState)->hp = ((Stg20GameState *)&Save_GameState)->maxHp;
        for (i = 0; i < 0x13; i++) {
            ((Stg20GameState *)&Save_GameState)->slotStatus[i] = 0;
        }
        for (i = 0; i < 0x24; i++) {
            if (Save_GameState.elems[i].state != 0) {
                Save_GameState.elems[i].hp = Save_GameState.elems[i].maxHp;
                Save_GameState.elems[i].mp = Save_GameState.elems[i].maxMp;
            }
        }
        break;
    case 0x23B6:
        Flag_Set(0x25B, 0);
        Flag_Set(0x25C, 0);
        Flag_Set(0x25D, 0);
        Flag_Set(0x262, 1);
        Flag_Set(0x263, 1);
        Flag_Set(0x264, 1);
        break;
    case 0x23B7:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xDA]++;
        break;
    case 0x23B8:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xBF]++;
        break;
    case 0x23B9:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xD6]++;
        break;
    case 0x23BA:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xC0]++;
        break;
    case 0x23BB:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xDF]++;
        break;
    case 0x23BC:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xE0]++;
        break;
    case 0x23BD:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xD3]++;
        break;
    case 0x23BE:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0xD8]++;
        break;
    case 0x23BF:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x49]++;
        break;
    case 0x23C0:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x4F]++;
        break;
    case 0x23C1:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x2E]++;
        break;
    case 0x23C2:
        ((Stg20GameState *)&Save_GameState)->storageCounts[0x34]++;
        break;
    }
}

void Stg20_OpenText(void *t, s32 text, s32 id, Stg20Cell *pos, s32 color) {
    Stg20TextArgs args;

    if (id == 0) {
        args.text = text;
    } else {
        args.text = (s32)Cd_GetFileEntry(id + 0x1FD0000);
    }
    args.bigFont = 0;
    args.color = color;
    args.pos = *pos;
    args.charAdvance = 0;
    args.lineAdvance = 0xC;
    args.charDelay = 0;
    Text_Open(t, &args);
}

Stg20Cell *Stg20_GetActorCell(Actor *a) {
    ActorTransformView *t = a->u38.ptr38;

    Stg20_CellTmp.x = (t->posX + 0x4500) / 0x600;
    Stg20_CellTmp.y = 0x16 - (t->posZ + 0x4500) / 0x600;
    return &Stg20_CellTmp;
}

s32 Stg20_IsOnCellCenter(Actor *a) {
    ActorTransformView *t = a->u38.ptr38;
    s32 m = 0xE6;
    s32 r;
    s32 v;

    do {
        v = (t->posX + 0x12C73) % 0x600;
        if (v > m) {
            break;
        }
        r = 1;
        v = (t->posZ + 0x12C73) % 0x600;
        if (v > m) {
            break;
        }
        return r;
    } while (0);
    return 0;
}

void Stg20_SnapToCell(Actor *a, s32 doX, s32 doZ) {
    ActorTransformView *t = a->u38.ptr38;

    if (doX) {
        t->posX = (t->posX + 0x12F00) / 0x600 * 0x600 - 0x12C00;
    }
    if (doZ) {
        t->posZ = (t->posZ + 0x12F00) / 0x600 * 0x600 - 0x12C00;
    }
}

void Stg20_SetMoveParams(Actor *a, s32 i) {
    Stg20Vec3 *v = &((Stg20Rot *)a->u38.ptr38)->axisMotion2;

    if (v->field_0 == 0) {
        v->field_0 = Stg20_MoveParams[i].field_0;
    }
    v->field_4 = Stg20_MoveParams[i].field_4;
    v->field_8 = Stg20_MoveParams[i].field_8;
}

Stg20Cell *Stg20_GetCellInDir(Actor *a, s32 dir) {
    Stg20Cell *c = Stg20_GetActorCell(a);

    c->x += Stg20_DirCellDelta[dir].x;
    c->y += Stg20_DirCellDelta[dir].y;
    return c;
}

s32 Stg20_IsCellBlocked(Actor *a, s32 dir) {
    s32 mask;

    if (Stg20_TalkActive != 0) {
        return 0;
    }
    mask = 0xBF;
    if (((Stg20ModelTask *)a)->walkerKind == 0) {
        mask = 0x7F;
    }
    return Stg20_GetGridCell(Stg20_GetCellInDir(a, dir)) & mask;
}

void Stg20_AddOccupantMark(Actor *a, Stg20Marks *m, s32 dir, s32 timer) {
    Stg20Cell *c;
    s32 i;

    if (dir == -1) {
        c = Stg20_GetActorCell(a);
    } else {
        c = Stg20_GetCellInDir(a, dir);
    }
    for (i = 0; i < 5; i++) {
        if (m->cell[i].x == c->x && m->cell[i].y == c->y) {
            goto found;
        }
    }
    for (i = 0; i < 5; i++) {
        if (m->timer[i] == 0) {
            goto found;
        }
    }
    return;
found:
    m->cell[i] = *c;
    m->timer[i] = timer;
}

void Stg20_TickOccupantMarks(Actor *a, Stg20Marks *m) {
    s32 i;
    s32 flag = ((Stg20ModelTask *)a)->walkerKind == 0;

    for (i = 0; i < 5; i++) {
        if (m->timer[i] != 0) {
            if (--m->timer[i] == 0) {
                Stg20_MarkGridOccupant(&m->cell[i], 0, flag);
            } else {
                Stg20_MarkGridOccupant(&m->cell[i], 1, flag);
            }
        }
    }
}

s32 Stg20_CellDistWeighted(Stg20Cell *c, s32 x, s32 y, s32 flag) {
    s32 dx = c->x - x;
    s32 dy;

    if (dx < 0) {
        dx = -dx;
    }
    dy = c->y - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (flag) {
        dx *= 3;
    } else {
        dy *= 3;
    }
    return dx + dy;
}

s32 Stg20_AreaSelectFindDir(Actor *a, s32 dir) {
    Stg20NavWork *w = (Stg20NavWork *)a->work;
    Stg20Cell c;
    s32 best;
    s32 found;
    s32 i;
    s32 d;
    Stg20PickRec *r;

    c.x = w->recs[w->index].cell.x;
    c.y = w->recs[w->index].cell.y;
    best = 0x7D00;
    found = -1;
    for (i = 0; (r = &w->recs[i])->id != -1; i++) {
        if (i == w->index) {
            continue;
        }
        switch (dir) {
        case 0:
            if (c.y < r->cell.y) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 1);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        case 1:
            if (c.x > r->cell.x) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 0);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        case 2:
            if (c.y > r->cell.y) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 1);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        case 3:
            if (c.x < r->cell.x) {
                d = Stg20_CellDistWeighted(&c, r->cell.x, r->cell.y, 0);
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
            break;
        }
    }
    return found;
}

INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_AreaNamePos);
void Stg20_AreaSelectUpdate(Actor *a) {
    Stg20NavWork *w = (Stg20NavWork *)a->work;
    Stg20PickRec *r;
    s32 i;
    s32 n;
    s32 k;

    switch (a->stateLevel0) {
    case 0:
        if (Sys_State.prevGameMode == 0x602) {
            Sys_State.modeArg = ((Stg20GameState *)&Save_GameState)->areaSelectArg;
        }
        Mem_FillWordsNeg1(&w->text, 1);
        w->index = 0;
        for (i = 0, n = 0; ; i++) {
            r = (Stg20PickRec *)Stg20_GetMapDest(i);
            if (i == Sys_State.modeArg) {
                w->index = n;
            }
            if (r->id == -1) {
                break;
            }
            if (r->id == 0 || Flag_Test(r->id) != 0) {
                w->recs[n] = *r;
                n++;
            }
        }
        w->recs[n].id = -1;
        w->redraw = 1;
        ((Stg20GameState *)&Save_GameState)->areaSelectArg = D_8005F794;
        Task_NextState0(a);
        break;
    case 1:
        do {
            if (Pad_State[0].down > 0) {                k = Stg20_AreaSelectFindDir(a, 0);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].left > 0) {                k = Stg20_AreaSelectFindDir(a, 1);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].up > 0) {                k = Stg20_AreaSelectFindDir(a, 2);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].right > 0) {                k = Stg20_AreaSelectFindDir(a, 3);                if (k != -1) {                    Snd_PlayById(0x12, 0);                    w->index = k;                }                w->redraw = 1;            } else if (Pad_State[0].cross > 0) {                if (w->recs[w->index].mode != 0x301) {                    goto play;                }                if (w->recs[w->index].arg != 2 || Flag_Test(0x12) != 0) {                play:                    Snd_PlayById(0xE, 0);                    Task_NextState0(a);                }            }            if (w->redraw != 0) {                w->redraw = 0;                Text_Close(&w->text);                Text_OpenPacked(&w->text, w->recs[w->index].text, 0, Stg20_AreaNamePos);            }        } while (0);
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = w->recs[w->index].mode;
                Sys_State.modeArg = w->recs[w->index].arg;
                Text_CloseArray(&w->text, 1);
            }
            break;
        }
        break;
    }
}

void Stg20_AreaSelectDraw(Actor *a) {
    Stg20NavWork *w = (Stg20NavWork *)a->work;
    s32 i;
    GfxPart *p;
    GfxPart *q;

    for (i = 0; ; i++) {
        GfxPart *unused; /* block-scope decl: keeps GCC from copying the exit test (loop not inverted) */

        if (w->recs[i].fileId == 0) {
            break;
        }
        if (w->recs[i].flag != 0 && Flag_Test(w->recs[i].flag) != 0) {
            p = (GfxPart *)Cd_GetFileEntry(w->recs[i].altFileId);
        } else {
            p = (GfxPart *)Cd_GetFileEntry(w->recs[i].fileId);
        }
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & (0xF - (1 << Math_CycleRange(a->elapsed, 6, 0, 3)))) {
                q->visible = 0;
            } else {
                q->visible = 1;
                q->x = w->recs[i].cell.x;
                q->y = w->recs[i].cell.y;
            }
        }
        Gfx_DrawParts((s32)p);
    }
    p = (GfxPart *)Cd_GetFileEntry(0x4100000);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 7);
            q->x = w->recs[w->index].cell.x;
            q->y = w->recs[w->index].cell.y;
        }
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, Stg20_AreaIconHideMasks[Sys_State.gameMode - 0x32A]);
    do {
        Gfx_DrawParts((s32)p);
    } while (0);
    p = (GfxPart *)Cd_GetFileEntry(Stg20_AreaScreenPartsIds[Sys_State.gameMode - 0x32A]);
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 0xF);
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_AreaSelectShowName(Actor *a, s32 open) {
    Stg20PickWork *w = (Stg20PickWork *)a->work;

    if (open == 0) {
        Text_Close(&w->text);
    } else {
        Text_OpenPacked(&w->text, w->recs[w->index].text, 0, Stg20_AreaNamePos);
    }
}

INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_LabDigivolveTextPos);
INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_LabDnaTextPos);
void Stg20_LabModeSelUpdate(Actor *a)
{
  Stg20YesNoWork *w = (Stg20YesNoWork *) a->work;
  switch (a->stateLevel0)
  {
    case 0:
      w->sel = D_800709BC != 0;
      Mem_FillWordsNeg1(w->texts, 2);
      Text_OpenById(&w->texts[0], 0x102, 0, Stg20_LabDigivolveTextPos);
      Text_OpenById(&w->texts[1], 0x103, 0, Stg20_LabDnaTextPos);
      Task_NextState0(a);
      break;

    case 1:
      if (Pad_State[0].left > 0)
    {
      if (w->sel == 0)
      {
        break;
      }
      w->sel = 0;
      Snd_PlayById(0xC, 0);
    }
    else
      if (Pad_State[0].right > 0)
    {
      if (w->sel != 0)
      {
        break;
      }
      w->sel = 1;
      Snd_PlayById(0xC, 0);
    }
    else
      if (Pad_State[0].triangle <= 0)
    {
 do { if (Pad_State[0].cross > 0) { Stg20_MenuState.result = 0; Stg20_MenuState.labMode = w->sel; Snd_PlayById(0xA, 0); Task_NextState0(a); } } while (0);
    }
    else
    {
      Stg20_MenuState.result = 1;
      Stg20_MenuState.labMode = w->sel;
      Snd_PlayById(0xB, 0);
      Task_NextState0(a);
    }
      break;

    case 2:
      Text_CloseArray(w->texts, 2);
      Task_NextState0(a);
      break;

  }

}

void Stg20_LabModeSelDraw(Actor *a) {
    Stg20BlinkTask *t = (Stg20BlinkTask *)a;
    Stg20Work *w = t->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120000);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->x = w->field_0 * 0x36 - 0x8E;
            q->y = -0x60;
            q->visible = ((t->frameCount >> 4) ^ 1) & 1;
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_LabRosterSetText(Actor *a, s32 i) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    Stg20Slot *s = &w->slots[i];
    Halves *pos = Stg20_LabRosterTextPos[i];
    s32 digi = Save_GameState.elems[s->slot].digiId;
    s32 j;

    if (s->enabled != 0) {
        for (j = 0; j < 4; j++) {
            Text_Close(&w->texts[i * 4 + j]);
        }
        if (s->used != 0) {
            Text_OpenById(&w->texts[i * 4 + 0], 0x81, 0, pos[0]);
            Text_OpenPacked(&w->texts[i * 4 + 1], (s32)Save_RosterNames[s->slot].name, 0, pos[1]);
            Text_OpenPacked(&w->texts[i * 4 + 2], (s32)Digi_GetDefaultName(digi), 0, pos[2]);
            Text_OpenById(&w->texts[i * 4 + 3], Digi_GetRank(digi) + 0xC6, 0, pos[3]);
        }
    }
}

void Stg20_LabRosterFillSlots(Actor *a) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    s32 i;

    for (i = 0; i < 4; i++) {
        w->slots[i].used = Save_GameState.elems[i + Stg20_MenuState.rosterTop].state != 0;
        w->slots[i].enabled = 1;
        w->slots[i].slot = i + Stg20_MenuState.rosterTop;
    }
}

void Stg20_LabRosterUpdate(Actor *a) {
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    s32 i;
    s32 j;
    s32 snd;
    s32 idx;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 16);
        for (j = 0; j < 0x24; j++) {
            if (Save_GameState.elems[j].state != 0) {
                w->count++;
            }
        }
        Stg20_LabRosterFillSlots(a);
        Task_NextState0(a);
        break;
    tri:
        Stg20_MenuState.result = 1;
        Stg20_MenuState.pickedIndex = Stg20_MenuState.rosterTop + Stg20_MenuState.rosterCursor;
        Snd_PlayById(0xB, 0);
        Task_NextState0(a);
        goto done;
    ok:
        Stg20_MenuState.result = 0;
        Stg20_MenuState.pickedIndex = idx;
        Snd_PlayById(0xE, 0);
        Task_NextState0(a);
        goto done;
    case 1:
        snd = 0;
        if (Pad_State[0].repeat & 0x1000) {
            if (Stg20_MenuState.rosterCursor != 0) {
                w->timer = 0;
                snd = 1;
                Stg20_MenuState.rosterCursor--;
            } else if (Stg20_MenuState.rosterTop != 0) {
                Stg20_MenuState.rosterTop--;
                snd = 1;
            }
            Stg20_LabRosterFillSlots(a);
        } else if (Pad_State[0].repeat & 0x4000) {
            if (Stg20_MenuState.rosterCursor != 3) {
                w->timer = 0;
                snd = 1;
                Stg20_MenuState.rosterCursor++;
            } else if (Stg20_MenuState.rosterTop + 4 < w->count) {
                Stg20_MenuState.rosterTop++;
                snd = 1;
            }
            Stg20_LabRosterFillSlots(a);
        } else if (Pad_State[0].triangle > 0) {
            goto tri;
        } else if (Pad_State[0].cross > 0) {
            idx = Stg20_MenuState.rosterTop + Stg20_MenuState.rosterCursor;
            if ((Stg20_MenuState.excludeFirst != 0 && Stg20_MenuState.dnaParent0 == idx) || Save_GameState.elems[idx].state == 0) {
                Snd_PlayById(0x10, 0);
            } else {
                goto ok;
            }
        }
    done:
        if (snd != 0) {
            Snd_PlayById(0xD, 0);
        }
        for (i = 0; i < 4; i++) {
            Stg20_LabRosterSetText(a, i);
        }
        break;
    case 2:
        Text_CloseArray(w->texts, 16);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabRosterDraw(Actor *a) {
    Stg20Roster *ros;
    Stg20SlotWork *w = (Stg20SlotWork *)a->work;
    GfxPart *p;
    GfxPart *r;
    GfxPart *q;
    GfxPart *s;
    s32 i;

    w->timer++;
    p = (GfxPart *)Cd_GetFileEntry(0xD120002);
    do {
        for (q = p; q->fileId != 0; q++) {
            if (q->groupMask & 2) {
                q->x = 0x1D;
                q->y = Stg20_MenuState.rosterCursor * 0x22 - 0x3E;
                q->visible = ((w->timer >> 4) ^ 1) & 1;
            }
            if (q->groupMask & 4) {
                q->visible = Stg20_MenuState.rosterTop != 0;
            }
            if (q->groupMask & 8) {
                q->visible = Stg20_MenuState.rosterTop + 4 < w->count;
            }
        }
        Gfx_DrawParts((s32)p);
        for (i = 0; i < 4; i++) {
            ros = D_8005E704;
            r = (GfxPart *)Cd_GetFileEntry(Stg20_LabRosterPanelIds[i]);
            for (s = r; s->fileId != 0; s++) {
                do {
                    if (s->groupMask & 2) {
                        s->visible = Stg20_MenuState.rosterCursor != i;
                    }
                } while (0);
                if (s->groupMask & 4) {
                    s->visible = Stg20_MenuState.rosterCursor == i;
                }
                if (s->groupMask & 8) {
                    s->visible = w->slots[i].used != 0;
                }
            }
            Gfx_SetPartsNumber(r, 8, 2, ros[i + Stg20_MenuState.rosterTop].level);
            Gfx_DrawParts((s32)r);
        }
    } while (0);
}

void Stg20_MsgWinInit(Actor *a, s32 v) {
    a->param = v;
}

void Stg20_MsgWinUpdate(Actor *a) {
    Stg20NameWork *w = (Stg20NameWork *)a->work;
    Stg20TextArgs args;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1((s32 *)w, 1);
        Flag_Set(0x10, 0);
        Task_NextState0(a);
        break;
    case 1:
        if (w->msgPending != 0) {
            args.text = w->msgText;
            args.bigFont = 1;
            args.color = 0;
            args.pos.x = 0x10;
            args.pos.y = 0xBA;
            args.charAdvance = 0;
            args.lineAdvance = 0x10;
            args.charDelay = 3;
            args.strArg0 = (s32)w->name;
            Text_Open(w, &args);
            Flag_Set(0x10, 0);
            w->choice = -1;
            w->msgPending = 0;
        }
        if (w->choice == -1 && Flag_Test(0x10) != 0) {
            w->choice = Flag_Test(0x11);
        }
        break;
    case 2:
        break;
    }
}

void Stg20_MsgWinDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 1);
    Task_DefaultDestroy(a);
}

void Stg20_MsgWinDraw(Actor *a) {
    Stg20Part *p;
    Stg20Part *q;
    s32 id;

    id = 0x3120003;
    if (a->param != 0) {
        id = 0x3120001;
    }
    p = (Stg20Part *)Cd_GetFileEntry(id);
    for (q = p; q->fileId != 0; q++) {
        q->field_E = 1;
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_MsgWinClear(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Text_Close((s32 *)e->work);
    }
}

void Stg20_MsgWinShowSkillDesc(s32 id) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20TextWork *w = (Stg20TextWork *)e->work;

        w->msgText = Skill_GetDescText(id);
        w->msgPending = 1;
    }
}

void Stg20_MsgWinShowSysMsg(s32 id) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20TextWork *w = (Stg20TextWork *)e->work;

        w->msgText = (s32)Cd_GetFileEntry(id + 0x1FD0000);
        w->msgPending = 1;
    }
}

void Stg20_MsgWinShowDigiMsg(s32 text, s32 digi) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        Stg20NameWork *w = (Stg20NameWork *)e->work;
        u8 *name = Digi_GetDefaultName(digi);
        s32 i;

        for (i = 0; i < 0xE; i++) {
            w->name[i] = name[i];
        }
        w->msgText = (s32)Cd_GetFileEntry(text + 0x1FD0000);
        w->msgPending = 1;
    }
}

s32 Stg20_MsgWinGetChoice(void) {
    TaskEntry *e = Task_FindFirst(0x30D, -1, -1);

    if (e != NULL) {
        return ((Stg20TextWork *)e->work)->choice;
    }
    return 0;
}

void Stg20_LabCaptionUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        if (D_800709D0 == 0) {
            Text_OpenById(w, 0x102, 0, Stg20_LabCaptionPos[0]);
        } else {
            Text_OpenById(w, 0x103, 0, Stg20_LabCaptionPos[1]);
            Text_OpenById(&w[1], 0x104, 0, Stg20_LabCaptionPos[2]);
        }
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        Text_CloseArray(w, 2);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabCaptionDraw(void) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120001);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 6) {
            switch (Stg20_MenuState.pickStep) {
            case 0:
            default:
                q->visible = 0;
                break;
            case 1:
                q->visible = ((u32)q->groupMask >> 1) & 1;
                break;
            case 2:
                q->visible = ((u32)q->groupMask >> 2) & 1;
                break;
            }
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_LabInfoUpdate(Actor *a) {
    Stg20InfoWork *w = (Stg20InfoWork *)a->work;
    DigiRosterEntry *d;
    s32 t;
    s32 lv;
    s32 ok;
    s32 id0;
    s32 id1;
    s32 x;
    s32 y;
    s32 p;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 0xD);
        w->digi = (DigiRosterEntry *)&D_8005E704[D_800709D8];
        Task_NextState0(a);
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            Stg20_OpenText(&w->texts[0], (s32)w->digi->name, 0, &Stg20_LabInfoTextPos[0], 0);
            Stg20_OpenText(&w->texts[1], (s32)Digi_GetDefaultName(w->digi->digiId), 0, &Stg20_LabInfoTextPos[1], 0);
            Stg20_OpenText(&w->texts[2], 0, Digi_GetType(w->digi->digiId) + 0xC3, &Stg20_LabInfoTextPos[2], 0);
            Stg20_OpenText(&w->texts[3], 0, Digi_GetRank(w->digi->digiId) + 0xC6, &Stg20_LabInfoTextPos[3], 0);
            Stg20_OpenText(&w->texts[4], 0, Digi_GetSpecialty(w->digi->digiId) + 0xCA, &Stg20_LabInfoTextPos[4], 0);
            if (w->digi->attr[0x25] != 0) {
                Stg20_OpenText(&w->texts[5], (s32)Digi_GetDefaultName(w->digi->attr[0x25]), 0, &Stg20_LabInfoTextPos[5], 0);
            }
            if (w->digi->attr[0x26] != 0) {
                Stg20_OpenText(&w->texts[6], (s32)Digi_GetDefaultName(w->digi->attr[0x26]), 0, &Stg20_LabInfoTextPos[6], 0);
            }
            Stg20_OpenText(&w->texts[7], 0, 0x105, &Stg20_LabInfoTextPos[7], 0);
            Stg20_OpenText(&w->texts[8], 0, 0x106, &Stg20_LabInfoTextPos[8], 0);
            Stg20_OpenText(&w->texts[9], 0, 0x107, &Stg20_LabInfoTextPos[9], 0);
            Stg20_OpenText(&w->texts[10], 0, 0xBF, &Stg20_LabInfoTextPos[10], 0);
            Stg20_OpenText(&w->texts[11], 0, 0xD0, &Stg20_LabInfoTextPos[11], 0);
            Stg20_OpenText(&w->texts[12], 0, 0x9D, &Stg20_LabInfoTextPos[12], 0);
            switch (D_800709D4) {
            case 0:
                t = Digi_GetRank(w->digi->digiId);
                d = w->digi;
                lv = (d->level - 1) / 10;
                if (lv >= 4) {
                    lv = 3;
                }
                switch (Stg20_DigivolveRuleTbl[lv][t]) {
                case 0:
                    Stg20_MsgWinShowSysMsg(0x118);
                    break;
                case 1:
                    p = Digi_GetEvolutionTarget(d->digiId, d->dp);
                    Stg20_EvoTargetId = p;
                    if (p == 0) {
                case 2:
                        Stg20_MsgWinShowSysMsg(0x11D);
                    } else {
                        Stg20_MsgWinShowDigiMsg(0x119, p);
                    }
                    break;
                }
                break;
            case 1:
                Stg20_MsgWinShowDigiMsg(0x126, Stg20_EvoTargetId);
                break;
            case 2:
                if (Digi_GetRank(w->digi->digiId) != 0) {
                    Stg20_MsgWinShowSysMsg(0x11B);
                } else {
                    Stg20_MsgWinShowSysMsg(0x11A);
                }
                break;
            case 3:
                ok = 0;
                id0 = Save_GameState.elems[D_800709E4].digiId;
                id1 = w->digi->digiId;
                x = Digi_GetType(id0);
                y = Digi_GetType(id1);
                switch (D_8005F790) {
                case 0x305:
                    if (x != 0 && y != 0) {
                        ok = 1;
                    }
                    break;
                case 0x309:
                    if (x != 2 && y != 2) {
                        ok = 1;
                    }
                    break;
                case 0x30D:
                    if (x != 1 && y != 1) {
                        ok = 1;
                    }
                    break;
                default:
                    ok = 1;
                    break;
                }
                if (ok != 0) {
                    if (Digi_GetRank(w->digi->digiId) == 0) {
                        Stg20_MsgWinShowSysMsg(0x11A);
                    } else {
                        Stg20_EvoTargetId = Stg20_GetDnaResult(id0, id1);
                        Stg20_MsgWinShowDigiMsg(0x128, Stg20_EvoTargetId);
                    }
                } else {
                    Stg20_MsgWinShowSysMsg(0x12A);
                }
                break;
            case 4:
                Stg20_MsgWinShowDigiMsg(0x129, Stg20_EvoTargetId);
                break;
            }
            Task_NextState1(a);
            break;
        case 1:
            do {
                if (Pad_State[0].circle > 0) {
                    D_800709B8.result = 0;
                    Task_NextState0(a);
                    break;
                }
                if (Pad_State[0].triangle > 0) {
                    Snd_PlayById(0xB, 0);
                    D_800709B8.result = 1;
                    Task_NextState0(a);
                    break;
                }
                if (Stg20_MenuState.infoMode == 1) {
                    break;
                }
                switch (Stg20_MsgWinGetChoice()) {
                case 0:
                    Stg20_MenuState.result = 2;
                    Task_NextState0(a);
                    break;
                case 1:
                    Stg20_MenuState.result = 3;
                    Task_NextState0(a);
                    break;
                }
            } while (0);
            break;
        }
        break;
    case 2:
        Text_CloseArray(w->texts, 0xD);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabInfoDraw(Actor *a) {
    Stg20StatusWork *w = (Stg20StatusWork *)a->work;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xD120008);

    Gfx_SetPartsNumber(p, 2, 3, w->digi->maxHp);
    Gfx_SetPartsNumber(p, 4, 3, w->digi->hp);
    Gfx_SetPartsNumber(p, 8, 3, w->digi->maxMp);
    Gfx_SetPartsNumber(p, 0x10, 3, w->digi->mp);
    Gfx_SetPartsNumber(p, 0x20, 2, w->digi->level);
    Gfx_SetPartsNumber(p, 0x40, 3, w->digi->attack);
    Gfx_SetPartsNumber(p, 0x80, 3, w->digi->defense);
    Gfx_SetPartsNumber(p, 0x100, 3, w->digi->speed);
    Gfx_SetPartsNumber(p, 0x200, 8, w->digi->exp);
    Gfx_SetPartsNumber(p, 0x400, 8, Digi_GetExpToNextLevel(w->digi->level, w->digi->maxLevel, w->digi->exp));
    Gfx_SetPartsNumber(p, 0x800, 2, w->digi->dp);
    Gfx_DrawParts((s32)p);
}

void Stg20_LabSkillsGroup(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    Stg20Roster *e = &D_8005E704[a->param];
    s32 cnt[4];
    s32 i;
    s32 j;
    s32 s;
    s32 k;

    for (i = 0; i < 4; i++) {
        cnt[i] = 0;
        w->groups[i].count = 0;
        for (j = 0; j < 12; j++) {
            w->groups[i].list[j] = 0;
        }
    }
    for (i = 0; i < 12; i++) {
        s = e->skills[i];
        if (s != 0) {
            k = Skill_GetType(s);
            w->groups[k].list[cnt[k]] = s;
            cnt[k]++;
        }
    }
    for (i = 0; i < 4; i++) {
        w->groups[i].count = cnt[i];
    }
}

void Stg20_LabSkillsSetText(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    Stg20TextArgs args;
    s32 i;
    s32 j;
    s32 s;
    u8 *list;
    s32 top;

    for (i = 0; i < 4; i++) {
        list = w->groups[i].list;
        top = w->top[i];
        for (j = 0; j < 3; j++) {
            if (list[j + top] != 0) {
                args.text = Skill_GetNameText(list[j + top]);
                args.bigFont = 0;
                args.color = w->col != i;
                args.pos.x = Stg20_LabSkillsCursorPos[i + 8].lo;
                args.pos.y = Stg20_LabSkillsCursorPos[i + 8].hi + j * 11;
                args.charAdvance = 0;
                args.lineAdvance = 0;
                args.charDelay = 0;
                Text_Open(&w->texts[7 + i * 3 + j], &args);
            }
        }
    }
    s = w->groups[w->col].list[w->cursor[w->col] + w->top[w->col]];
    if (s != 0) {
        if (w->skill != s) {
            w->skill = s;
            Stg20_MsgWinShowSkillDesc(s);
        }
    } else {
        w->skill = 0;
        Stg20_MsgWinClear();
    }
}

void Stg20_LabSkillsUpdate(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    s32 snd;
    s32 redraw;
    s32 col;
    s32 *cur;
    s32 *top;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w->texts, 0x13);
        a->param = D_800709E0;
        Stg20_LabSkillsGroup(a);
        Task_NextState0(a);
        break;
    case 1:
        if (a->stateLevel1 == 0) {
            Stg20_OpenText(&w->texts[0], 0, 0xA, &Stg20_LabSkillsTextPos[0], 4);
            Stg20_OpenText(&w->texts[1], 0, 0xB, &Stg20_LabSkillsTextPos[1], 4);
            Stg20_OpenText(&w->texts[2], 0, 0xC, &Stg20_LabSkillsTextPos[2], 4);
            Stg20_OpenText(&w->texts[3], 0, 0xD, &Stg20_LabSkillsTextPos[3], 4);
            Stg20_OpenText(&w->texts[4], (s32)Save_RosterNames[D_800709E0].name, 0, &Stg20_LabSkillsTextPos[8], 0);
            Stg20_OpenText(&w->texts[5], 0, 0xD1, &Stg20_LabSkillsTextPos[9], 0);
            Task_NextState1(a);
        }
        redraw = snd = 0;
        do {
            col = w->col;
            cur = &w->cursor[col];
            top = &w->top[col];
            if (Pad_State[0].left > 0) {
                if (col != 0) {
                    w->col = col - 1;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].right > 0) {
                if (col != 3) {
                    w->col = col + 1;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].repeat & 0x1000) {
                if (*cur != 0) {
                    (*cur)--;
                    snd = 1;
                } else if (*top != 0) {
                    (*top)--;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].repeat & 0x4000) {
                if (*cur != 2) {
                    (*cur)++;
                    snd = 1;
                } else if (w->groups[0].list[*top + col * 14 + 3] != 0) {
                    (*top)++;
                    snd = 1;
                }
                redraw = 1;
            } else if (Pad_State[0].triangle > 0 || Pad_State[0].circle > 0) {
                Task_NextState0(a);
            }
        } while (0);
        if (snd != 0) {
            Snd_PlayById(0xD, 0);
        }
        if (redraw != 0 || ((Stg20BlinkTask *)a)->frameCount == 1) {
            Stg20_LabSkillsSetText(a);
        }
        break;
    case 2:
        Text_CloseArray(w->texts, 0x13);
        Stg20_MsgWinClear();
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabSkillsDraw(Actor *a) {
    Stg20SkillWork *w = (Stg20SkillWork *)a->work;
    GfxPart *p;
    GfxPart *q;
    s32 m;
    s32 bit;
    s32 i;
    s32 m2;

    p = (GfxPart *)Cd_GetFileEntry(0xD120009);
    for (q = p; q->fileId != 0; q++) {
        q->visible = (q->groupMask & Stg20_LabSkillsColHideMasks[w->col]) == 0;
        if (q->groupMask & 0x4000) {
            q->x = Stg20_LabSkillsCursorPos[w->col].lo;
            q->y = Stg20_LabSkillsCursorPos[w->col].hi + w->cursor[w->col] * 11;
        }
    }
    Gfx_DrawParts((s32)p);
    p = (GfxPart *)Cd_GetFileEntry(0xD12000A);
    m = 0;
    bit = 2;
    for (i = 0; i < 4; i++) {
        if (w->top[i] == 0) {
            m |= bit;
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        } else if (w->col != i) {
            m |= bit;
            bit <<= 2;
        } else {
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        }
        if (w->groups[i].count < 4 || w->groups[i].count == w->top[i] + 3) {
            m |= bit;
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        } else if (w->col != i) {
            m |= bit;
            bit <<= 2;
        } else {
            bit <<= 1;
            m |= bit;
            bit <<= 1;
        }
    }
    Gfx_HidePartsByMask((GfxPartMaskView *)p, m);
    m2 = ~m & Stg20_LabSkillsArrowBlinkMasks[w->col];
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & m2) {
            q->palette = Math_PingPongRange(a->elapsed, 4, 0, 3);
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg20_LabPairUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    switch (a->stateLevel0) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        Stg20_OpenText(w, (s32)Save_RosterNames[Stg20_MenuState.dnaParent0].name, 0, &Stg20_LabPairNamePos[0], 0);
        Stg20_OpenText(&w[1], (s32)Save_RosterNames[Stg20_MenuState.dnaParent1].name, 0, &Stg20_LabPairNamePos[1], 0);
        Task_NextState0(a);
        break;
    case 1:
        break;
    case 2:
        Text_CloseArray(w, 2);
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabPairDraw(void) {
    Gfx_DrawParts((s32)Cd_GetFileEntry(0xD120007));
}

s32 Stg20_GetDnaTypeIndex(s32 a, s32 b) {
    a = Digi_GetType(a);
    b = Digi_GetType(b);
    return Stg20_DnaTypeIndexTbl[a][b];
}

u8 Stg20_GetDnaResult(s32 a, s32 b) {
    s32 s4 = Stg20_GetDnaTypeIndex(a, b);
    s32 r1 = Digi_GetRank(a);
    s32 r2 = Digi_GetRank(b);
    s32 m = (r1 < r2 ? r1 : r2) - 1;
    s32 r3 = func_8001D910(a);
    s32 r4 = func_8001D910(b);
    return Stg20_DnaResultTbl[s4][m][r3][r4];
}

void Stg20_ShadowInit(Actor *a, s32 v) {
    ((Stg20Work *)a->work)->field_0 = v;
}

void Stg20_ShadowUpdate(Actor *a) {
    Actor *t;

    switch (a->stateLevel0) {
    case 0:
        Actor_InitTransform(a, Gfx_ZeroVector, 0);
        Gfx_AttachModel(a, 0x5B)->otIndex = 4;
        Gfx_ResetModelBones(a);
        Task_NextState0(a);
        break;
    case 1:
        t = ((Stg20LinkWork *)a->work)->target;
        if (t != NULL && t->stateLevel0 != 0) {
            ((Stg20PosView *)a->u38.ptr38)->pos = ((Stg20PosView *)t->u38.ptr38)->pos;
        }
        break;
    case 2:
        break;
    }
}

void Stg20_ShadowDraw(Actor *a) {
    Gfx_AttachModel(a, 0x2F7);
    Actor_UpdateTransform(a);
    Gfx_CalcModelBoneMatrices(a);
    Gfx_DrawTexModel(a, 1);
}

void Stg20_LabJogBgUpdate(Actor *a) {
    if (a->stateLevel0 == 0) {
        Actor_InitTransform(a, Gfx_ZeroVector, 0);
        Gfx_AttachModel(a, 0xD14)->otIndex = 5;
        Gfx_ResetModelBones(a);
        ((Stg20Rot *)a->u38.ptr38)->rotY = 0x200;
        Task_NextState0(a);
    }
}

INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_JogBgWireColor);
void Stg20_LabJogBgDraw(Actor *a) {
    CVECTOR c;

    Gfx_AttachModel(a, 0xD14);
    Actor_UpdateTransform(a);
    Gfx_CalcModelBoneMatrices(a);
    c = Stg20_JogBgWireColor;
    Gfx_DrawWireModel(a, 1, &c);
}

void Stg20_LabDigiModelUpdate(Actor *a) {
    Stg20Rot *o = (Stg20Rot *)a->u38.ptr38;
    Stg20DrawWork *w = (Stg20DrawWork *)a->work;
    Stg20ModelTint *t;
    s32 f;
    s32 st;
    s32 v;

    switch (a->stateLevel0) {
    case 0:
        switch (a->stateLevel1) {
        case 0:
        default:
            a->digiId = Stg20_MenuState.modelDigiId;
            w->modelId = Digi_GetModelFile(a->digiId);
            w->pos[0] = 0;
            w->pos[1] = 0;
            w->pos[2] = 0;
            a->param = Stg20_MenuState.modelSlide;
            Task_NextState1(a);
        case 1:
            f = Digi_GetModelFile(a->digiId);
            Cd_QueueFile(f);
            st = Cd_GetFileState(f);
            if (st != 3) {
                break;
            }
            f = Anim_GetModelAnimFile(a->digiId, 0);
            Cd_QueueFile(f);
            if (Cd_GetFileState(f) != st) {
                break;
            }
            Task_NextState1(a);
        case 2:
            Actor_InitTransform(a, w->pos, w->rot);
            o = (Stg20Rot *)a->u38.ptr38;
            Gfx_AttachModel(a, w->modelId)->otIndex = 3;
            Anim_SetModelAnim(a, 0);
            t = (Stg20ModelTint *)a->model;
            w->field_1C = 1;
            w->field_20 = 0;
            t->b = 0x80;
            t->g = 0x80;
            t->r = 0x80;
            w->field_26 = 0;
            w->field_25 = 0;
            w->field_24 = 0;
            if (D_800709F4 == 0) {
                o->scaleZ = 0;
                o->scaleY = 0;
                o->scaleX = 0;
            }
            w->visible = 1;
            Task_NextState0(a);
            if (a->param != 0) {
                Task_SetState1(a, 2);
            }
            break;
        }
        break;
    case 1:
        switch (a->stateLevel1) {
        case 0:
        default:
            break;
        case 1:
            if (o->posX > -0x640) {
                o->posX -= 0x20;
            } else {
                o->posX = -0x640;
                Task_SetState1(a, 0);
            }
            break;
        case 2:
            if (o->posX < 0x640) {
                o->posX += 0x20;
            } else {
                o->posX = 0x640;
                Task_SetState1(a, 0);
            }
            break;
        }
        if (a->param != 0) {
            o->rotY -= 0xB;
        } else {
            o->rotY += 0xB;
        }
        if (o->scaleX != 0x1000) {
            v = o->scaleX + 0x100;
            o->scaleX = v;
            o->scaleZ = v;
            o->scaleY = v;
        }
        break;
    case 2:
        Task_NextState0(a);
        break;
    }
}

void Stg20_LabDigiModelDraw(Actor *a) {
    Stg20DrawWork *w = (Stg20DrawWork *)a->work;

    if (w->visible != 0) {
        Gfx_AttachModel(a, w->modelId);
        Anim_StepModelAnim(a);
        Actor_UpdateTransform(a);
        Gfx_CalcModelBoneMatrices(a);
        Gfx_DrawTexModel(a, 0);
    }
}

void Stg20_MapExitUpdate(Actor *a) {
    Stg20ExitWork *w = (Stg20ExitWork *)a->work;
    Stg20Exit *e;
    Stg20Cell c;

    switch (a->stateLevel0) {
    case 0:
        Task_NextState0(a);
        break;
    case 1:
        for (e = (Stg20Exit *)Stg20_GetMapInfo()->exits; e->x != 0; e++) {
            c.x = e->x;
            c.y = e->y;
            if (Stg20_GetGridCell(&c) & 0x80) {
                Task_FindFirst(0x302, 0, -1)->param = 1;
                w->mode = e->mode + 0x300;
                w->arg = e->arg;
                Task_NextState0(a);
                break;
            }
        }
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            Gfx_FadeOutToBlack(0xA);
            Task_NextState1(a);
        case 1:
            if (++a->stateLevel2 >= 0x19) {
                Sys_State.nextGameMode = w->mode;
                Sys_State.modeArg = w->arg;
            }
            break;
        }
        break;
    }
}

Actor *Stg20_FindWalkerByDigiId(s32 id) {
    Actor *e;

    for (e = (Actor *)Task_FindFirst(0x302, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
        if (e->digiId == id) {
            return e;
        }
    }
    return NULL;
}

void Stg20_WalkerWarpToCell(Actor *a, Stg20Pos2 *pos) {
    Stg20CursorWork *w = (Stg20CursorWork *)a->work;
    ActorTransformView *t = a->u38.ptr38;
    Stg20Cell c = *Stg20_GetActorCell(a);

    if (c.x != pos->x && c.y != pos->y) {
        t->posX = (pos->x - 11) * 0x600;
        t->posY = 0;
        t->posZ = -((pos->y - 11) * 0x600);
    }
    w->x = pos->x;
    w->y = pos->y;
    w->endX = w->endY = 1;
    w->done = 0;
    w->wait = 0;
    w->index = 0;
}

s32 Stg20_WalkerIsPathDone(Actor *a) {
    return ((Stg20ModelWork *)a->work)->done;
}

void Stg20_WalkerSetAnim(Actor *a, s32 anim) {
    Stg20ModelTask *t = (Stg20ModelTask *)a;
    Stg20ModelWork *w = t->work;

    if (t->walkerKind >= 0 && w->anim != anim) {
        w->anim = anim;
        Anim_SetModelAnim(a, anim);
    }
}

void Stg20_WalkerInit(Actor *a, Stg20Spawn *s) {
    Stg20SpawnWork *w = (Stg20SpawnWork *)a->work;
    s32 i;

    a->digiId = s->id;
    w->facing = s->facing;
    w->flagEntry = s->flagEntry;
    for (i = 0; i < 6; i++) {
        w->blk[i] = s->blk[i];
    }
    ((Stg20ModelTask *)a)->walkerKind = 1;
    if (s->id == 0x1F2) {
        ((Stg20ModelTask *)a)->walkerKind = -3;
    } else if (s->id == 0x1F3) {
        ((Stg20ModelTask *)a)->walkerKind = -2;
    } else if (s->id == 0x1F4) {
        ((Stg20ModelTask *)a)->walkerKind = 0;
    }
    w->visible = 1;
    if (s->id >= 0x1F1 && s->id <= 0x1F3) {
        w->visible = 0;
    }
}

void Stg20_WalkerGetInput(Actor *a)
{
  Stg20WalkWork *w = (Stg20WalkWork *) a->work;
  Stg20Cell *c;
  Stg20Cell *p;
  s32 r;
  if ((((Stg20ModelTask *) a)->walkerKind == 0) && (Stg20_TalkActive == 0))
  {
    switch (a->param)
    {
      case 0:

      default:
        w->input = (w->held = Pad_Held);
        break;

      case 1:
        w->input = (w->held & 0xF000) | 0x10;
        break;

    }

    return;
  }
  if ((w->path[1].x != 0) || (w->done == 0))
  {
    if (w->wait != 0)
    {
      w->wait--;
    }
    else
    {
 do { c = Stg20_GetActorCell(a); if (((c->x == w->path[w->index].x) && (c->y == w->path[w->index].y)) && (Stg20_IsOnCellCenter(a) != 0)) { w->index++; switch (w->path[w->index].x) { case 1: w->done = 1; case 0: w->index = 0; break; } r = Rand_Next(); w->input = 0; w->wait = ((u16) (((u16) r) % 60)) + 15; } else { p = &w->path[w->index]; if (c->y != p->y) { if (c->y < p->y) { w->input = 0x4000; } else { w->input = 0x1000; } } if (c->x != p->x) { if (c->x < p->x) { w->input = 0x2000; } else { w->input = 0x8000; } } } } while (0);
    }
  }
  else
  {
    w->input = 0;
  }
}

s32 Stg20_InputToDir(Actor *a) {
    u16 m = 0x1000;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (((Stg20FlagWork *)a->work)->input & m) {
            return (i + 2) % 4;
        }
        m <<= 1;
    }
    return -1;
}

void Stg20_WalkerFaceDir(Actor *a, s32 i) {
    ((Stg20Rot *)a->u38.ptr38)->rotY = Stg20_DirAngles[i];
}

void Stg20_WalkerHalt(Actor *a) {
    Stg20CursorWork *w = (Stg20CursorWork *)a->work;
    Stg20Cell c = *Stg20_GetActorCell(a);

    w->x = c.x;
    w->y = c.y;
    w->endX = w->endY = 1;
    w->done = 1;
    w->wait = 0;
    w->index = 0;
}

void Stg20_WalkerUpdate(Actor *a) {
    Stg20NpcWork *w = (Stg20NpcWork *)a->work;
    s32 pos[3];
    Stg20Cell c;
    Stg20Cell c2;
    Actor *e;
    Actor *p;
    Actor *q;
    Stg20NpcWork *ew;
    s32 v;
    s32 dir;
    s32 d2;
    s32 idx;
    s32 mask;
    s32 found;
    s32 ok;
    s32 snd;
    Stg20Rot *r;

    if (((Stg20ModelTask *)a)->walkerKind == 0) {
        Stg20_MenuState.menuAllowed = 0;
    }
    switch (a->stateLevel0) {
    case 0:
        pos[0] = (w->blk[0].x - 0xB) * 0x600;
        pos[1] = 0;
        pos[2] = -((w->blk[0].y - 0xB) * 0x600);
        Actor_InitTransform(a, pos, (w->facing << 10) & 0xFC00);
        if (w->visible != 0) {
            w->modelId = Digi_GetModelFile(a->digiId);
            Gfx_AttachModel(a, w->modelId)->otIndex = 3;
            Stg20_WalkerSetAnim(a, 0x1E);
            Task_Create(0x303, (s32 *)a->u34.children, (s32)a);
            r = (Stg20Rot *)a->u38.ptr38;
            switch (Sys_GameMode[0]) {
            case 0x30F:
                v = 0;
                if (a->digiId == 0x2E) {
                    v = -0x480;
                }
                r->posY = v;
                break;
            case 0x318:
                v = 0;
                if (a->digiId == 0x14) {
                    v = -0x480;
                }
                r->posY = v;
                break;
            }
        }
        w->text = -1;
        Task_NextState0(a);
        break;
    case 2:
        break;
    case 1:
        if (((Stg20ModelTask *)a)->walkerKind < -1) {
            switch (a->stateLevel1) {
            case 0:
            default:
                p = (Actor *)Task_FindFirst(0x302, 0, -1);
                if (p == NULL) {
                    break;
                }
                c = *Stg20_GetActorCell(p);
                if (w->blk[0].x == c.x && w->blk[0].y == c.y && Stg20_IsOnCellCenter(p) != 0) {
                    Text_OpenMsgClearChoice(&w->text, Flag_SelectBranch(w->flagEntry));
                    w->target = p;
                    Stg20_WalkerHalt(p);
                    Task_SetState1(p, 0);
                    Task_NextState1(a);
                    Stg20_TalkActive = 1;
                }
                break;
            case 1:
                Flag_GetTableBase();
                if (Text_IsFinished(w->text) != 0) {
                    Text_Close(&w->text);
                    if (Flag_Test(0x10) != 0) {
                        Text_OpenMsgClearChoice(&w->text, Flag_SelectBranch(w->flagEntry));
                        break;
                    }
                    if (((Stg20ModelTask *)a)->walkerKind == -2) {
                        Task_SetState0(a, 3);
                    } else {
                        Task_SetState1(a, 0);
                    }
                    Task_SetState1(w->target, 0);
                    Stg20_TalkActive = 0;
                }
                break;
            }
            break;
        }
        if (w->visible != 0) {
            Stg20_WalkerGetInput(a);
        } else {
            w->input = 0;
        }
        switch (a->stateLevel1) {
        case 0:
        default:
            switch (a->stateLevel2) {
            case 0:
            default:
                Actor_StopAxisMotion(a, 2);
                Stg20_WalkerSetAnim(a, 0x1E);
                Stg20_SnapToCell(a, 1, 1);
                Task_NextState2(a);
            case 1:
                Stg20_AddOccupantMark(a, &w->marks, -1, 5);
                if (w->input & 0xF000) {
                    if (Stg20_IsCellBlocked(a, Stg20_InputToDir(a)) == 0) {
                        Stg20_AddOccupantMark(a, &w->marks, Stg20_InputToDir(a), 0x14);
                        Task_SetState1(a, 1);
                        w->counter = 0;
                    } else {
                        Stg20_WalkerFaceDir(a, Stg20_InputToDir(a));
                    }
                } else if (((Stg20ModelTask *)a)->walkerKind == 0) {
                    if (w->timer < Sys_State.frameCount && (w->input & 0x40)) {
                        dir = (((Stg20Rot *)a->u38.ptr38)->rotY & 0xFFF) / 0x400;
                        if (Stg20_IsCellBlocked(a, dir) & 0x40) {
                            e = (Actor *)Task_FindFirst(0x302, 1, -1);
                            found = 0;
                            c = *Stg20_GetCellInDir(a, dir);
                            while (e != NULL) {
                                c2 = *Stg20_GetActorCell(e);
                                if (c2.x == c.x && c2.y == c.y) {
                                    if (e->stateLevel1 == 0) {
                                        w->target = e;
                                        found = 1;
                                    }
                                    break;
                                }
                                e = (Actor *)Task_FindNext();
                            }
                            if (found != 0) {
                                Task_NextState2(a);
                            }
                        }
                    }
                    if (((Stg20ModelTask *)a)->walkerKind == 0 && a->stateLevel2 == 1) {
                        Stg20_MenuState.menuAllowed = 1;
                    }
                }
                break;
            case 2:
                if (((Stg20ModelTask *)a)->walkerKind == 0) {
                    q = w->target;
                    ew = (Stg20NpcWork *)q->work;
                    Stg20_MenuState.talkActive = 1;
                    Stg20_AddOccupantMark(a, &w->marks, -1, 5);
                    Stg20_WalkerSetAnim(a, 0x20);
                    Task_SetState1(q, 0);
                    Task_SetState2(q, 2);
                    ew->target = a;
                    ((Stg20Rot *)q->u38.ptr38)->rotY = ((Stg20Rot *)a->u38.ptr38)->rotY + 0x800;
                    Stg20_WalkerHalt(a);
                    Task_SetState1(a, 0);
                    Task_SetState2(a, 1);
                } else {
                    switch (a->stateLevel3) {
                    case 0:
                    default:
                        Stg20_WalkerSetAnim(a, 0x20);
                        Text_OpenMsgClearChoice(&w->text, Flag_SelectBranch(w->flagEntry));
                        Task_NextState3(a);
                        break;
                    case 1:
                        Flag_GetTableBase();
                        if (Text_IsFinished(w->text) != 0) {
                            Text_Close(&w->text);
                            if (Flag_Test(0x10) != 0) {
                                Task_SetState3(a, 0);
                            } else {
                                ((Stg20NpcWork *)w->target->work)->timer = Sys_State.frameCount + 0x1E;
                                Task_SetState1(w->target, 0);
                                Task_SetState2(a, 0);
                                Stg20_TalkActive = 0;
                            }
                        }
                        break;
                    }
                }
                break;
            case 3:
                break;
            }
            if (w->anim < 0x25) {
                if (w->anim >= 0x22 && a->model->animDone != 0) {
                    Stg20_WalkerSetAnim(a, 0x1E);
                }
            }
            break;
        case 1:
            switch (a->stateLevel2) {
            case 0:
            default:
                d2 = Stg20_InputToDir(a);
                if (d2 == -1) {
                    Task_SetState1(a, 0);
                    break;
                }
                Stg20_WalkerFaceDir(a, d2);
                w->dir = d2;
                if (Stg20_IsCellBlocked(a, Stg20_InputToDir(a)) != 0) {
                    Task_SetState1(a, 0);
                    break;
                }
                Stg20_AddOccupantMark(a, &w->marks, w->dir, 0x14);
                Task_NextState2(a);
            case 1:
                if ((w->input & 0x10) || Stg20_TalkActive != 0 || ((Stg20ModelTask *)a)->walkerKind != 0) {
                    Stg20_WalkerSetAnim(a, 0x1F);
                    Stg20_SetMoveParams(a, 0);
                } else {
                    Stg20_WalkerSetAnim(a, 0x25);
                    Stg20_SetMoveParams(a, 1);
                }
                if (((Stg20ModelTask *)a)->walkerKind == 0) {
                    ok = 0;
                    w->counter++;
                    if ((w->input & 0x10) || Stg20_TalkActive != 0) {
                        if (w->counter >= 13) {
                            ok = 1;
                        }
                    } else if (w->counter >= 5) {
                        ok = 1;
                    }
                    if (ok != 0) {
                        snd = 0x27;
                        if (Stg20_GetMapInfo()->stepSndBits != 0) {
                            c = *Stg20_GetActorCell(a);
                            idx = c.y * 3 + c.x / 8;
                            mask = 1 << (s16)(c.x % 8);
                            if (((u8 *)Stg20_GetMapInfo()->stepSndBits)[idx] & mask) {
                                snd = 0x28;
                            }
                        }
                        Snd_PlayById(snd, 0);
                        w->counter = 0;
                    }
                }
                Actor_ApplyAxisMotion(a, 2);
                Stg20_AddOccupantMark(a, &w->marks, -1, 5);
                if (Stg20_IsOnCellCenter(a) != 0) {
                    if ((w->input & 0xF000) && Stg20_IsCellBlocked(a, Stg20_InputToDir(a)) == 0) {
                        Task_SetState1(a, 1);
                    } else {
                        Task_SetState1(a, 0);
                    }
                }
                switch (w->dir) {
                case 0:
                case 2:
                    Stg20_SnapToCell(a, 1, 0);
                    break;
                case 1:
                case 3:
                    Stg20_SnapToCell(a, 0, 1);
                    break;
                }
                break;
            }
            break;
        }
        Stg20_TickOccupantMarks(a, &w->marks);
        break;
    }
}

void Stg20_WalkerDraw(Actor *a) {
    Stg20Draw2Work *w = (Stg20Draw2Work *)a->work;

    if (w->visible != 0) {
        Gfx_AttachModel(a, w->modelId);
        Anim_StepModelAnim(a);
        Actor_UpdateTransform(a);
        if (Actor_ProjectToScreen(a) == 0) {
            Gfx_CalcModelBoneMatrices(a);
            Gfx_DrawTexModel(a, 0);
        }
    }
}

void Stg20_XaStreamInit(Actor *a, Stg20Vec3 *v) {
    *(Stg20Vec3 *)a->work = *v;
}

void Stg20_XaStreamUpdate(Actor *a) {
    Stg20XaWork *w = (Stg20XaWork *)a->work;
    u8 filter[8];
    u8 mode[8];
    u8 pos[8];
    u8 res[8];
    u8 res2[8];

    switch (a->stateLevel0) {
    case 0:
    default:
        switch (a->stateLevel1) {
        case 0:
        default:
            w->start = Cd_GetFileLba(w->fileId);
            w->end = w->start + w->len;
            filter[0] = 1;
            filter[1] = w->channel;
            CdControl(0xD, filter, 0);
            mode[0] = 0xC8;
            CdControlB(0xE, mode, 0);
            CdIntToPos(w->start, pos);
            CdControlF(0x15, (s32)pos);
            Task_NextState1(a);
            break;
        case 1:
            switch (CdSync(1, res)) {
            case 5:
                Task_SetState0(a, 0);
                break;
            case 2:
                Task_NextState0(a);
                break;
            }
            break;
        }
        break;
    case 1:
        break;
    case 2:
        switch (a->stateLevel1) {
        case 0:
        default:
            CdIntToPos(w->start, res);
            if (CdControl(0x1B, res, 0) == 1) {
                Task_NextState1(a);
            }
            break;
        case 1:
            if ((((Stg20BlinkTask *)a)->frameCount & 0x1F) == 0) {
                switch (CdSync(1, res2)) {
                case 5:
                    Task_SetState0(a, 3);
                    break;
                case 2:
                    if (CdLastCom() == 0x11 && CdPosToInt(&res2[5]) >= w->end) {
                        Task_SetState0(a, 3);
                    } else {
                        CdControlF(0x11, 0);
                    }
                    break;
                }
            }
            break;
        }
        break;
    }
}

void Stg20_XaStreamDestroy(Actor *a) {
    CdControlF(9, 0);
    Task_DefaultDestroy(a);
}

void Stg20_ShopBgUpdate(Actor *a) {
    if (a->stateLevel0 == 0) {
        Task_NextState0(a);
    }
}

void Stg20_ShopBgDraw(Actor *a) {
    GfxPart *p;
    GfxPart *q;

    if (Sys_GameMode[0] < 0x333) {
        p = (GfxPart *)Cd_GetFileEntry(0xDD60001);
    } else {
        p = (GfxPart *)Cd_GetFileEntry(0xC930001);
    }
    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask == 2) {
            q->palette = Math_CycleRange(a->elapsed, 6, 0, 7);
        }
    }
    Gfx_DrawParts((s32)p);
}

INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_BitsLabelPos);
void Stg20_ShopBitsUpdate(Actor *a) {
    s32 *w = (s32 *)a->work;

    if (a->stateLevel0 == 0) {
        Mem_FillWordsNeg1(w, 1);
        Text_OpenById(w, 0x5F, 0, Stg20_BitsLabelPos);
        Task_NextState0(a);
    }
}

void Stg20_ShopBitsDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 1);
    Task_DefaultDestroy(a);
}

void Stg20_ShopBitsDraw(void) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xDD60000);

    Gfx_SetPartsNumber(p, 2, 8, D_8005E628);
    Gfx_DrawParts((s32)p);
}

INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_ShopMenuBuyPos);
INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_ShopMenuSellPos);
void Stg20_ItemShopMenuUpdate(Actor *a) {
    s32 state = a->stateLevel0;
    s32 *w = (s32 *)a->work;

    switch (state) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        Text_OpenById(w, 0x12B, 0, Stg20_ShopMenuBuyPos);
        Text_OpenById(&w[1], 0x12C, 0, Stg20_ShopMenuSellPos);
        Task_NextState0(a);
        break;

    case 1:
        do {
            s32 *p = &D_800709B8.menuChoice;

            if (Pad_State[0].right > 0) {
                if (*p != 0) {
                    break;
                }
                *p = state;
                Snd_PlayById(0xC, 0);
            } else if (Pad_State[0].left > 0) {
                if (*p == 0) {
                    break;
                }
                *p -= 1;
                Snd_PlayById(0xC, 0);
            } else if (Pad_State[0].triangle > 0) {
                p[-18] = state;
                Snd_PlayById(0xB, 0);
                Task_SetState0(a, 3);
            } else if (Pad_State[0].cross > 0) {
                p[-18] = 0;
                Snd_PlayById(0xA, 0);
                Task_SetState0(a, 3);
            }
        } while (0);
        break;

    case 2:
        break;
    }
}

void Stg20_ItemShopMenuDestroy(Actor *a) {
    Text_CloseArray((s32 *)a->work, 2);
    Task_DefaultDestroy(a);
}

void Stg20_ItemShopMenuDraw(Actor *a) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(0xDD60004);
    GfxPart *q;

    for (q = p; q->fileId != 0; q++) {
        if (q->groupMask & 2) {
            q->palette = Math_CycleRange(a->elapsed, 4, 0, 3);
            q->x = Stg20_MenuState.menuChoice != 0 ? -0x6C : -0x90;
            q->y = -0x62;
        }
    }
    Gfx_DrawParts((s32)p);
}

INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_BeetleMenuPartsPos);
INCLUDE_RODATA("asm/USA/stag2000/rodata", Stg20_BeetleMenuUpgradePos);
void Stg20_BeetleShopMenuUpdate(Actor *a) {
    s32 state = a->stateLevel0;
    s32 *w = (s32 *)a->work;

    switch (state) {
    case 0:
        Mem_FillWordsNeg1(w, 2);
        Text_OpenById(w, 0xDD, 0, Stg20_BeetleMenuPartsPos);
        Text_OpenById(&w[1], 0xDE, 0, Stg20_BeetleMenuUpgradePos);
        Task_NextState0(a);
        break;

    case 1:
        do {
            /* D_80070A00 reached as D_800709B8.field_48; field_0 is p[-18] */
            s32 *p = &D_800709B8.menuChoice;

            if (Pad_State[0].right > 0) {
                if (*p != 0) {
                    break;
                }
                *p = state;
                Snd_PlayById(0xC, 0);
            } else if (Pad_State[0].left > 0) {
                if (*p == 0) {
                    break;
                }
                *p -= 1;
                Snd_PlayById(0xC, 0);
            } else if (Pad_State[0].triangle > 0) {
                p[-18] = state;
                Snd_PlayById(0xB, 0);
                Task_SetState0(a, 3);
            } else if (Pad_State[0].cross > 0) {
                p[-18] = 0;
                Snd_PlayById(0xA, 0);
                Task_SetState0(a, 3);
            }
        } while (0);
        break;

    case 2:
        break;
    }
}
