#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"

/* Task callbacks the descriptors below need (defined further down). */
void Stg30_CommandInputTask(Actor *a0);

TaskDesc Stg30_CommandInputDesc = { 0, Stg30_CommandInputTask, Task_DefaultDestroy, 0, 4, 4 };

void Stg30_DimFightersExcept(s32 sel, s32 from, s32 to) {
    s32 i;
    TaskEntry *t;

    for (i = from; i <= to; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            if (sel == -1 || i == sel) {
                Task_SetState01((Actor *)t, 2, 8);
            } else {
                Task_SetState01((Actor *)t, 2, 7);
            }
        }
    }
}

void Stg30_UndimPartyFighters(void) {
    s32 i;
    TaskEntry *t;

    for (i = 0; i < 3; i++) {
        t = Task_FindFirst(0x509, -1, i);
        if (t != NULL) {
            Task_SetState01((Actor *)t, 2, 8);
        }
    }
}

void Stg30_CommandInputTask(Actor *a0) {
    Stg30WorkWord *w = (Stg30WorkWord *)a0->work;
    s32 *p = (s32 *)a0->u34.children;
    TaskEntry *t;
    s32 i;
    s32 n;
    s32 a;
    s32 b;
    s32 r;
    s32 j;

    switch (a0->stateLevel0) {
    case 0:
        Stg30_Battle.entries[0].escapeResult = 0;
        Task_NextState0(a0);
        break;
    case 2:
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_SetCameraShot(1);
                Stg30_Battle.entries[0].inputSlot = 6;
                Task_Create(0x504, p, 0);
                Stg30_Battle.turns[6].turnType = 0;
                for (i = 0; i < 6; i++) {
                    t = Task_FindFirst(0x509, -1, i);
                    if (t != NULL) {
                        Task_SetState01((Actor *)t, 2, 9);
                    }
                }
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                switch (Stg30_Battle.entries[0].menuChoice) {
                case 0:
                default:
                    Task_SetState1(a0, 2);
                    w->field_0 = Stg30_TargetFirst(0, 0, 0);
                    break;
                case 1:
                    Task_SetState1(a0, 1);
                    break;
                case 2:
                    if (Stg30_Battle.isBossFight != 0) {
                        Stg30_Battle.entries[0].escapeResult = 2;
                    } else {
                        a = 0;
                        b = 0;
                        n = 0;
                        for (j = 0; j < 3; j++) {
                            if (Stg30_Battle.entries[j].hp != 0) {
                                n++;
                                a += Stg30_Battle.entries[j].speed;
                            }
                        }
                        a /= n;
                        n = 0;
                        for (j = 3; j < 6; j++) {
                            if (Stg30_Battle.entries[j].hp != 0) {
                                n++;
                                b += Stg30_Battle.entries[j].speed;
                            }
                        }
                        b /= n;
                        n = a * 100 / b;
                        if ((Rand_Next() & 0x7F) < n) {
                            Stg30_Battle.entries[0].escapeResult = 1;
                        } else {
                            Stg30_Battle.entries[0].escapeResult = 2;
                        }
                    }
                    Task_SetState0(a0, 3);
                    break;
                }
                break;
            }
            break;
        case 1:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_SetCameraShot(8);
                Task_Create(0x506, p, 0);
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                if (Stg30_Battle.entries[0].cancelled != 0) {
                    Task_SetState1(a0, 0);
                } else {
                    Task_NextState2(a0);
                }
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    Task_Create(0x508, p, 0);
                    Task_NextState3(a0);
                    break;
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (Stg30_Battle.entries[0].cancelled != 0) {
                        Stg30_UndimPartyFighters();
                        Stg30_Battle.turns[6].turnType = 0;
                        Task_SetState2(a0, 0);
                        break;
                    }
                    Stg30_Battle.turns[6].target = Stg30_Battle.entries[0].chosenTarget;
                    w->field_0 = Stg30_TargetFirst(0, 0, 0);
                    Task_SetState1(a0, 2);
                    break;
                }
                break;
            }
            break;
        case 2:
            switch (a0->stateLevel2) {
            case 0:
            default:
                Stg30_DimFightersExcept(w->field_0, 0, 2);
                ((void (*)(s32))Stg30_SetCameraShot)(w->field_0 + 2);
                Stg30_Battle.entries[0].inputSlot = w->field_0;
                Task_Create(0x504, p, 0);
                Task_NextState2(a0);
            case 1:
                if (*p != 0) {
                    break;
                }
                if (Stg30_Battle.entries[0].cancelled != 0) {
                    if (w->field_0 != Stg30_TargetFirst(0, 0, 0)) {
                        r = Stg30_TargetPrev(0, w->field_0, 0, 0);
                        w->field_0 = r;
                        Stg30_Battle.turns[r].turnType = 0;
                        Task_SetState1(a0, 2);
                        break;
                    }
                    Task_SetState1(a0, 0);
                    break;
                }
                if (Stg30_Battle.entries[0].menuChoice == 0) {
                    Task_NextState2(a0);
                    break;
                }
                Stg30_Battle.turns[w->field_0].turnType = 5;
                Task_SetState2(a0, 4);
                break;
            case 2:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    ((void (*)(s32))Stg30_SetCameraShot)(w->field_0 + 2);
                    Stg30_Battle.entries[0].inputSlot = w->field_0;
                    Task_Create(0x507, p, 0);
                    Task_NextState3(a0);
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (Stg30_Battle.entries[0].cancelled != 0) {
                        Task_SetState1(a0, 2);
                    } else {
                        Task_NextState2(a0);
                    }
                    break;
                }
                break;
            case 3:
                switch (a0->stateLevel3) {
                case 0:
                default:
                    Task_Create(0x508, p, 0);
                    Task_NextState3(a0);
                    break;
                case 1:
                    if (*p != 0) {
                        break;
                    }
                    if (Stg30_Battle.entries[0].cancelled != 0) {
                        Stg30_DimFightersExcept(w->field_0, 0, 2);
                        Task_SetState2(a0, 2);
                        break;
                    }
                    Stg30_Battle.turns[w->field_0].target = Stg30_Battle.entries[0].chosenTarget;
                    Task_NextState2(a0);
                    break;
                }
                break;
            case 4:
                n = w->field_0;
                w->field_0 = Stg30_TargetNext(0, n, 0, 0);
                if (w->field_0 == n) {
                    Task_NextState1(a0);
                } else {
                    Task_SetState1(a0, 2);
                }
                break;
            }
            break;
        case 3:
            switch (a0->stateLevel2) {
            case 0:
            default:
                for (n = 0; n < 6; n++) {
                    t = Task_FindFirst(0x509, -1, n);
                    if (t != NULL) {
                        Task_SetState01((Actor *)t, 2, 9);
                    }
                }
                Stg30_SetCameraShot(1);
                Task_NextState2(a0);
            case 1:
                Task_SetState0(a0, 3);
                break;
            }
            break;
        }
        break;
    }
}
