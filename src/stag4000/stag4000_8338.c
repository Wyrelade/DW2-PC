#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"

s32 Stg40_AiPathFlee(Stg40Ent48 *e, Pair54 *out) {
    Stg40Loc *loc = &e->loc;
    Pair54 c[3];
    s16 dx = D_80072B60->playerEnt->loc.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->playerEnt->loc.u0.pair.field_2 - loc->u0.pair.field_2;
    s32 n;
    s32 i;

    if (abs(dx) >= 3 || abs(dy) >= 3) {
        return 0;
    }
    if (abs(dx) >= abs(dy)) {
        c[0].field_0 = dx >= 0 ? loc->u0.pair.field_0 - 1 : loc->u0.pair.field_0 + 1;
        c[0].field_2 = loc->u0.pair.field_2;
        if (dy == 0) {
            switch (e->octant) {
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
            switch (e->octant) {
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

s32 Stg40_AiPathToTarget(Stg40Ent48 *e, Pair54 *out) {
    Pair54 *p = &e->loc.u0.pair;
    s16 dx = D_80072B60->cmdArgs.field_0 - p->field_0;
    s16 dy = D_80072B60->cmdArgs.field_2 - p->field_2;

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

s32 Stg40_AiPathChase(Stg40Ent48 *e, Pair54 *out) {
    Stg40Loc *loc = &e->loc;
    Pair54 c[3];
    s16 dx = D_80072B60->playerEnt->loc.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->playerEnt->loc.u0.pair.field_2 - loc->u0.pair.field_2;
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
        if (c[i].field_0 != loc->prevTile.field_0 || c[i].field_2 != loc->prevTile.field_2) {
            out[n].field_0 = c[i].field_0;
            out[n].field_2 = c[i].field_2;
            n++;
        }
    }
    if (n != 3) {
        out[n].field_0 = loc->prevTile.field_0;
        out[n].field_2 = loc->prevTile.field_2;
        n++;
    }
    return n;
}

s32 Stg40_AiPathChaseInRoom(Stg40Ent48 *e, Pair54 *out) {
    s16 k = e->params[4];
    s32 i;
    s32 n;
    s32 m = 0;
    Stg40Loc *loc = &e->loc;
    Pair54 c[3];
    s16 dx = D_80072B60->playerEnt->loc.u0.pair.field_0 - loc->u0.pair.field_0;
    s16 dy = D_80072B60->playerEnt->loc.u0.pair.field_2 - loc->u0.pair.field_2;

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
        if (k == (s16)(Stg40_GetCellFlags(c[i].field_0, c[i].field_2) & 0xF)) {
            out[n].field_0 = c[i].field_0;
            out[n].field_2 = c[i].field_2;
            n++;
        }
    }
    return n;
}

s32 Stg40_AiTryStep(Stg40Ent48 *e, s32 mode) {
    Pair54 buf[3];
    Pair54 *sel = NULL;
    Stg40Loc *loc = &e->loc;
    s32 i;
    s32 n;

    for (i = 0; i < 3; i++) {
        buf[i].field_0 = buf[i].field_2 = -1;
    }
    switch (mode) {
    case 0:
    default:
        n = Stg40_AiPathChase(e, buf);
        break;
    case 1:
        n = Stg40_AiPathFlee(e, buf);
        break;
    case 2:
        n = Stg40_AiPathChaseInRoom(e, buf);
        break;
    case 4:
        n = Stg40_AiPathToTarget(e, buf);
        break;
    case 3:
        return 0;
    }
    for (i = 0; i < n; i++) {
        if ((Stg40_GetCellFlags(buf[i].field_0, buf[i].field_2) & 0x4020) == 0x4000) {
            sel = &buf[i];
            break;
        }
    }
    if (sel == NULL) {
        return 0;
    }
    e->targetHeading = (Stg40_DeltaToOctant(sel->field_0 - loc->u0.pair.field_0, sel->field_2 - loc->u0.pair.field_2) << 16) >> 7;
    loc->prevTile.field_0 = loc->u0.pair.field_0;
    loc->prevTile.field_2 = loc->u0.pair.field_2;
    loc->u0.pair.field_0 = sel->field_0;
    loc->u0.pair.field_2 = sel->field_2;
    loc->moveFramesLeft = loc->moveFrames = 12;
    Stg40_ClearCellOccupied(loc->prevTile.field_0, loc->prevTile.field_2);
    Stg40_SetCellOccupied(loc->u0.pair.field_0, loc->u0.pair.field_2, 1);
    loc->moving = 1;
    return 1;
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_800634FC);
void Stg40_EnemyUpdate(Actor *a0) {
    Stg40ActWork *w = (Stg40ActWork *)a0->work;
    Stg40Ent48 *e = w->ent;
    Stg40Ent48 *other = D_80072B60->playerEnt;
    Stg40ModelFade *m;
    s32 lvl2;
    s32 n;
    s32 v;

    Stg40_SetCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, 1);
    if (e->flags & 0x1000) {
        Stg40_AutomapMoveMarker(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2,
                      e->loc.prevTile.field_0, e->loc.prevTile.field_2, e->kind);
    }
    if (a0->stateLevel1 != 4) {
        Stg40EnemyParty *info = (Stg40EnemyParty *)e->params;
        s32 t = info->giftPoints / (s16)info->pointsPerLevel;
        s32 lvl;
        lvl = 3;
        if (t < 4) {
            lvl = t;
        }
        v = lvl;
        if (v != 0) {
            v += 7;
            if (w->linkedModel != v) {
                w->pendingLinkedModel = v;
            }
        }
    }
    switch (a0->stateLevel1) {
    case 0:
    default:
        Stg40_ObjSetAnimIfNew(a0, 0x28);
        if (e->roomId == other->roomId) {
            Stg40_TurnQueueAdd(e->turnId);
            Task_SetState1(a0, 1);
            ((Stg40EnemyParty *)e->params)->idleCount = 0;
            ((Stg40EnemyParty *)e->params)->stepCount = 0;
            e->loc.prevTile.field_0 = e->loc.u0.pair.field_0;
            e->loc.prevTile.field_2 = e->loc.u0.pair.field_2;
            e->flags |= 0x1000;
        }
        break;
    case 1:
        Stg40_ObjSetAnimIfNew(a0, 0x28);
        if (D_8005071C->freeze != 0) {
            break;
        }
        if (e->roomId != other->roomId) {
            Stg40_TurnQueueRemove(e->turnId);
            Task_SetState1(a0, 0);
            break;
        }
        if (Stg40_TurnQueueCurrent() != e->turnId) {
            break;
        }
        ((Stg40EnemyParty *)e->params)->idleCount++;
        if (((Stg40EnemyParty *)e->params)->idleCount > ((Stg40EnemyParty *)e->params)->idleTicks) {
            Task_SetState1(a0, 2);
            ((Stg40EnemyParty *)e->params)->idleCount = 0;
        } else {
            Stg40_TurnQueueNext();
        }
        break;
    case 2:
        switch (a0->stateLevel2) {
        case 0:
        default:
            if (Stg40_AiTryStep(e, ((Stg40EnemyParty *)e->params)->pathMode) == 1) {
                Stg40_ObjSetAnimIfNew(a0, 0x29);
                Task_SetState2(a0, 1);
            } else {
                Stg40_ObjSetAnim(a0, 0x28);
                Task_SetState2(a0, 2);
            }
            break;
        case 1:
            if (w->ent->loc.moveFramesLeft != 0) {
                break;
            }
            ((Stg40EnemyParty *)e->params)->stepCount++;
            if (((Stg40EnemyParty *)e->params)->stepCount >= ((Stg40EnemyParty *)e->params)->stepsPerBurst) {
                Task_SetState2(a0, 2);
            } else {
                Task_SetState2(a0, 0);
            }
            break;
        case 2:
            ((Stg40EnemyParty *)e->params)->stepCount = 0;
            Stg40_TurnQueueNext();
            if (Stg40_IsEntAdjacent(e, other) == 1) {
                Task_SetState1(a0, 3);
            } else {
                Task_SetState1(a0, 1);
            }
            break;
        }
        break;
    case 3:
        switch (a0->stateLevel2) {
        case 1:
            break;
        case 0:
        default:
            Stg40_ObjSetAnim(a0, 0x28);
            e->targetHeading = (Stg40_DeltaToOctant(other->loc.u0.pair.field_0 - e->loc.u0.pair.field_0,
                                         other->loc.u0.pair.field_2 - e->loc.u0.pair.field_2) << 16) >> 7;
            Task_SetState2(a0, 1);
            break;
        }
        break;
    case 4:
        if (a0->digiId < 0x1F5) {
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg40_ObjSetAnim(a0, 0x28);
                Task_NextState2(a0);
                break;
            case 1:
                if (a0->stateLevel3++ < 10) {
                    break;
                }
                Task_NextState2(a0);
                e->flags |= 0x80;
                break;
            case 2:
                v = e->scaleX - 0x51;
                if (v < 0) {
                    v = 0;
                }
                e->scaleX = v;
                e->scaleZ = v;
                n = a0->stateLevel3;
                e->targetHeading += (n << 13) / 360;
                n++;
                a0->stateLevel3 = n;
                e->targetHeading &= 0xFFF;
                e->heading = e->targetHeading;
                if (++a0->stateLevel3 == 6) {
                    Snd_PlayById(0x17, 0);
                    w->pendingLinkedModel = 7;
                }
                if (e->scaleZ == 0) {
                    Task_NextState2(a0);
                }
                break;
            case 3:
                Task_SetState1(a0, 6);
                break;
            }
        } else {
            lvl2 = a0->stateLevel2;
            m = (Stg40ModelFade *)a0->model;
            switch (lvl2) {
            case 0:
                Stg40_ObjSetAnim(a0, 0x28);
                Task_NextState2(a0);
                break;
            case 1:
                if (a0->stateLevel3++ < 10) {
                    break;
                }
                Task_NextState2(a0);
                e->flags |= 0x80;
                m->tpageFlags = 0x20;
                m->clutRow = lvl2;
                m->fadeColor = D_800634FC;
                Snd_PlayById(0x1F, 0);
                w->pendingLinkedModel = lvl2;
                break;
            case 2: {
                s32 v = e->scaleX - 0x51;
                if (v < 0) {
                    v = 0;
                }
                e->scaleX = v;
                e->scaleZ = v;
                if (m->fadeColor.r != 0xFF) {
                    m->fadeColor.r++;
                    m->fadeColor.g++;
                    m->fadeColor.b++;
                }
                if (e->scaleZ == 0) {
                    Task_NextState2(a0);
                }
                break;
            }
            case 3:
                Task_SetState1(a0, 6);
                break;
            }
        }
        break;
    case 6:
        Stg40_TurnQueueRemove(e->turnId);
        Stg40_ClearCellOccupied(e->loc.u0.pair.field_0, e->loc.u0.pair.field_2);
        Stg40_AutomapMoveMarker(-1, -1, e->loc.u0.pair.field_0, e->loc.u0.pair.field_2, e->kind);
        e->flags = 0;
        if (a0 == D_80072B60->cmdActor) {
            D_80072B60->cmdActor = NULL;
            Stg40_EndTextObjCmd();
        }
        Task_SetState0(a0, 3);
        break;
    case 5:
        switch (a0->stateLevel2) {
        case 0:
        default:
            if (Stg40_AiTryStep(e, 4) == 1) {
                Stg40_ObjSetAnimIfNew(a0, 0x29);
                Task_SetState2(a0, 1);
            } else {
                Stg40_ObjSetAnim(a0, 0x28);
                Stg40_EndTextObjCmd();
                Task_SetState2(a0, 2);
            }
            break;
        case 2:
            break;
        case 1:
            if (w->ent->loc.moveFramesLeft != 0) {
                break;
            }
            Task_SetState2(a0, 0);
            break;
        }
        break;
    }
}
