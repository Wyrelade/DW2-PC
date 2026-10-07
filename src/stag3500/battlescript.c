#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"
#include "stag3500/turn.h"
#include "stag3500/fighter.h"
#include "stag3500/hud.h"

/* Task callbacks this unit defines further down (the descriptors come first). */
void Stg35_BattleScriptTask(Actor *arg0);

TaskDesc Stg35_BattleScriptDesc = { 0, Stg35_BattleScriptTask, Task_DefaultDestroy, 0, 4, 0x14 };
s16 Stg35_BattleScript[0xC8];

void Stg35_BattleScriptTask(Actor *arg0) {
    Stg35ScriptWork *w = (Stg35ScriptWork *)arg0->work;
    PTR32(Actor) *children = (PTR32(Actor) *)arg0->u34.children;
    Actor *e;
    s32 *q;
    s32 cont;
    Stg35Arg1 a1;
    Stg35Arg3 a3;

    switch (arg0->stateLevel0) {
    case 0:
        w->script = Stg35_BattleScript;
        Task_NextState0(arg0);
        break;
    case 1:
        cont = 1;
        do {
            switch (w->script[0]) {
            case 0:
                switch (arg0->stateLevel1) {
                case 0:
                default:
                    arg0->elapsed = 0;
                    arg0->stateLevel1++;
                case 1:
                    break;
                }
                if (w->script[1] < arg0->elapsed) {
                    arg0->stateLevel1 = 0;
                    w->script += 2;
                } else {
                    cont = 0;
                }
                break;
            case 1:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                if (e->stateLevel0 == 2) {
                    cont = 0;
                } else {
                    w->script += 2;
                }
                break;
            case 2:
                Stg35_SetCameraShot(w->script[1]);
                cont = 0;
                w->script += 2;
                break;
            case 3:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->param == w->script[1]) {
                        Stg35_FighterSetVisible(e, 1);
                        Stg35_FighterQueueHomeReset(e);
                    } else {
                        Stg35_FighterSetVisible(e, 0);
                    }
                }
                w->script += 2;
                break;
            case 4:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->param < 3) {
                        Stg35_FighterSetVisible(e, 1);
                        Stg35_FighterQueueHomeReset(e);
                    }
                }
                w->script += 1;
                break;
            case 5:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    if (e->param >= 3) {
                        Stg35_FighterSetVisible(e, 1);
                        Stg35_FighterQueueHomeReset(e);
                    }
                }
                w->script += 1;
                break;
            case 6:
                for (e = (Actor *)Task_FindFirst(0x707, -1, -1); e != NULL; e = (Actor *)Task_FindNext()) {
                    Stg35_FighterSetVisible(e, 1);
                    Stg35_FighterQueueHomeReset(e);
                }
                w->script += 1;
                break;
            case 7:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Task_SetState0(e, 2);
                Task_SetState1(e, 0);
                w->script += 2;
                break;
            case 8:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Task_SetState0(e, 2);
                Task_SetState1(e, 1);
                Task_SetState4(e, (u8)w->script[2]);
                w->script += 3;
                break;
            case 9:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_SetDigiAction(e, 3, w->script[2]);
                w->script += 3;
                break;
            case 10:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_HudSyncHp();
                Stg35_SetDigiAction(e, 4, w->script[2]);
                w->script += 3;
                break;
            case 11:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_HudSyncHp();
                Stg35_SetDigiAction(e, 5, w->script[2]);
                w->script += 3;
                break;
            case 12:
                e = (Actor *)Task_FindFirst(0x707, -1, w->script[1]);
                Stg35_SetDigiAction(e, 6, w->script[2]);
                w->script += 3;
                break;
            case 13:
                w->script += 3;
                break;
            case 14:
            case 15:
                w->script += 2;
                break;
            case 16:
                break;
            case 17:
                a1.field_0 = (s32)Stg35_BattleScript;
                Task_Create(0x70A, (s32 *)&children[3], (s32)&a1);
                w->script += 1;
                break;
            case 18:
                if (P32(Actor, children[3])->stateLevel0 == 1) {
                    w->script += 1;
                } else {
                    cont = 0;
                }
                break;
            case 19:
                switch (arg0->stateLevel1) {
                case 0:
                default:
                    q = Skill_GetShotXa(w->script[1]);
                    a3.field_0 = q[0];
                    a3.field_4 = q[1];
                    a3.field_8 = w->script[2];
                    Task_Create(0x70B, (s32 *)&children[4], (s32)&a3);
                    Task_NextState1(arg0);
                case 1:
                    break;
                }
                if (P32(Actor, children[4])->stateLevel0 == 1) {
                    Task_SetState0(P32(Actor, children[4]), 2);
                    w->script += 3;
                    Task_SetState1(arg0, 0);
                } else {
                    cont = 0;
                }
                break;
            case 20:
                Task_SetState0(arg0, 3);
                cont = 0;
                break;
            }
        } while (cont);
        break;
    }
}

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
