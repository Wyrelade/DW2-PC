#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/commandinput.h"
#include "stag3000/commandmenu.h"
#include "stag3000/itemmenu.h"
#include "stag3000/skillmenu.h"
#include "stag3000/targetselect.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"
#include "stag3000/stag3000_6A88_funcs.h"

void Stg30_BattleScriptTask(Actor *a0);

TaskDesc Stg30_BattleScriptDesc = { 0, Stg30_BattleScriptTask, Task_DefaultDestroy, 0, 4, 0x18 };

void Stg30_BuildGuardScript(s32 idx) {
    s16 *p = Stg30_BattleScript;

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
    Stg30_Battle.entries[idx].mp += Stg30_Battle.entries[idx].maxMp / 10;
    if (Stg30_Battle.entries[idx].maxMp < Stg30_Battle.entries[idx].mp) {
        Stg30_Battle.entries[idx].mp = Stg30_Battle.entries[idx].maxMp;
    }
}

s32 Stg30_PrepareAction(s32 idx) {
    switch (Stg30_Battle.turns[idx].turnType) {
    case 1:
    case 2:
    case 3:
    case 4:
    default:
        Stg30_BuildSkillScript(idx);
        return 1;
    case 5:
        Stg30_BuildGuardScript(idx);
        return 1;
    }
}

void Stg30_BattleScriptTask(Actor *a0) {
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
        w->pc = Stg30_BattleScript;
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
                ((void (*)(s32))Stg30_SetCameraShot)(w->pc[1]);
                cont = 0;
                w->pc += 2;
                break;
            case 3:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->param == w->pc[1]) {
                        Stg30_FighterSetVisible((Actor *)t, 1);
                        Stg30_FighterQueueHomeReset((Actor *)t);
                    } else {
                        Stg30_FighterSetVisible((Actor *)t, 0);
                    }
                }
                w->pc += 2;
                break;
            case 4:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->param < 3) {
                        Stg30_FighterSetVisible((Actor *)t, 1);
                        Stg30_FighterQueueHomeReset((Actor *)t);
                    }
                }
                w->pc += 1;
                break;
            case 5:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    if (t->param >= 3) {
                        Stg30_FighterSetVisible((Actor *)t, 1);
                        Stg30_FighterQueueHomeReset((Actor *)t);
                    }
                }
                w->pc += 1;
                break;
            case 6:
                for (t = Task_FindFirst(0x509, -1, -1); t != NULL; t = Task_FindNext()) {
                    Stg30_FighterSetVisible((Actor *)t, 1);
                    Stg30_FighterQueueHomeReset((Actor *)t);
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
                Stg30_SetDigiAction((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 3, w->pc[2]);
                w->pc += 3;
                break;
            case 11:
                Stg30_SetDigiAction((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 4, w->pc[2]);
                w->pc += 3;
                break;
            case 12:
                Stg30_SetDigiAction((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 5, w->pc[2]);
                if (w->pc[1] >= 3) {
                    Stg30_Battle.joinCandidate = w->pc[1];
                }
                w->pc += 3;
                break;
            case 13:
                Stg30_SetDigiAction((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 6, w->pc[2]);
                w->pc += 3;
                break;
            case 8:
                Stg30_SetDigiAction((Actor *)Task_FindFirst(0x509, -1, w->pc[1]), 0xC, w->pc[2]);
                w->pc += 3;
                break;
            case 19:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    Task_Create(0x510, &sl->interruptTask, 0);
                    Task_NextState1(a0);
                case 1:
                    cont = 0;
                    if (sl->interruptTask == 0) {
                        w->pc += 1;
                        Task_SetState1(a0, 0);
                    }
                    break;
                }
                break;
            case 20:
                if (Stg30_Battle.turns[3].turnType == 3) {
                    Stg30_Battle.interruptSlot = 3;
                } else if (Stg30_Battle.turns[4].turnType == 3) {
                    Stg30_Battle.interruptSlot = 4;
                } else if (Stg30_Battle.turns[5].turnType == 3) {
                    Stg30_Battle.interruptSlot = 5;
                }
                w->pc += 1;
                break;
            case 14:
                a[0] = w->pc[1];
                a[1] = w->pc[2];
                Task_Create(0x50C, &sl->field_0, (s32)a);
                if (Stg30_Battle.statusMsg != 0) {
                    b[0] = 8;
                    b[2] = Stg30_Battle.statusMsg;
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
                h[0] = (s32)Stg30_BattleScript;
                Task_Create(0x50E, (s32 *)&sl->actionLoadTask, (s32)h);
                w->pc += 1;
                break;
            case 22:
                if (sl->actionLoadTask->stateLevel0 != 1) {
                    cont = 0;
                } else {
                    w->pc += 1;
                }
                break;
            case 23:
                switch (a0->stateLevel1) {
                case 0:
                default:
                    q = Skill_GetShotXa(w->pc[1]);
                    g[0] = q[0];
                    g[1] = q[1];
                    g[2] = w->pc[2];
                    Task_Create(0x511, (s32 *)&sl->xaTask, (s32)g);
                    Task_NextState1(a0);
                case 1:
                    if (sl->xaTask->stateLevel0 != 1) {
                        cont = 0;
                        break;
                    }
                    Task_SetState0(sl->xaTask, 2);
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
