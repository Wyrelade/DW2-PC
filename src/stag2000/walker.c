#include "common.h"
#include "stag2000/stag2000.h"
#include "stag2000/stag2000_funcs.h"
#include "stag2000/areaselect.h"
#ifdef DW2_NATIVE
extern s32 Gfx_WideOnly; /* PG.3, main/model.c */
extern s32 Gfx_NoTexAnim;
#endif

/* Task callbacks the descriptors below need (defined further down). */
void Stg20_WalkerInit(Actor *a, Stg20Spawn *s);
void Stg20_WalkerUpdate(Actor *a);
void Stg20_WalkerDraw(Actor *a);

s16 Stg20_DirAngles[4] = { 0, 1024, 2048, -1024 };
TaskDesc Stg20_WalkerDesc = {
    (TaskInitFn)Stg20_WalkerInit, Stg20_WalkerUpdate, Task_DefaultDestroy, Stg20_WalkerDraw, 0x78, 4,
};
/* Task_DescTable[3]: task ids 0x300-0x31C. */
TaskDesc *Stg20_TaskDescs[] = {
    &Stg20_StageMainDesc, &Stg20_MapBgDesc, &Stg20_WalkerDesc, &Stg20_ShadowDesc, &Stg20_MapExitDesc,
    &Stg20_StaticBgDesc, &Stg20_AreaSelectDesc, &Stg20_DigiLabDesc, &Stg20_CameraDesc, &Stg20_LabJogBgDesc,
    &Stg20_LabDigiModelDesc, &Stg20_LabModeSelDesc, &Stg20_LabRosterDesc, &Stg20_MsgWinDesc,
    &Stg20_LabCaptionDesc, &Stg20_LabInfoDesc, &Stg20_LabSkillsDesc, &Stg20_LabPairDesc, &Stg20_ShopBgDesc,
    &Stg20_XaStreamDesc, &Stg20_ItemShopDesc, &Stg20_ShopBitsDesc, &Stg20_ItemShopMenuDesc,
    &Stg20_ShopListDesc, &Stg20_BeetleShopMenuDesc, &Stg20_BeetleShopDesc, &Stg20_BeetlePartsDesc,
    &Stg20_PartsUpgradeDesc, &Stg20_WarpPadDesc,
};

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
  if ((((Stg20ModelTask *) a)->walkerKind == 0) && (Stg20_MenuState.talkActive == 0))
  {
    switch (a->param)
    {
      case 0:

      default:
        w->input = (w->held = Pad_State[0].held);
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
            switch (Sys_State.gameMode) {
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
                    Stg20_MenuState.talkActive = 1;
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
                    Stg20_MenuState.talkActive = 0;
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
                                Stg20_MenuState.talkActive = 0;
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
                if ((w->input & 0x10) || Stg20_MenuState.talkActive != 0 || ((Stg20ModelTask *)a)->walkerKind != 0) {
                    Stg20_WalkerSetAnim(a, 0x1F);
                    Stg20_SetMoveParams(a, 0);
                } else {
                    Stg20_WalkerSetAnim(a, 0x25);
                    Stg20_SetMoveParams(a, 1);
                }
                if (((Stg20ModelTask *)a)->walkerKind == 0) {
                    ok = 0;
                    w->counter++;
                    if ((w->input & 0x10) || Stg20_MenuState.talkActive != 0) {
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
#ifdef DW2_NATIVE
            Gfx_NoTexAnim = Gfx_WideOnly; /* PG.3: seen only in the 16:9 sides */
#endif
            Gfx_CalcModelBoneMatrices(a);
            Gfx_DrawTexModel(a, 0);
#ifdef DW2_NATIVE
            Gfx_NoTexAnim = 0;
#endif
        }
    }
}
