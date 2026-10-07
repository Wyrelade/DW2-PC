#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"

s32 Stg35_GaugeDefPercent[] = { 25, 22, 20, 18, 16, 15, 14 };
s32 Stg35_DefaultTargets[] = { 3, 4, 5, 0, 1, 2 };

s32 Stg35_TurnOrder[12];
Stg35Battle Stg35_Battle;

s32 Stg35_ApplySkillDamage(s32 arg0, s32 arg1, s32 arg2) {
    DigiRosterEntry *rec0 = &Stg35_Battle.rec[arg0];
    DigiRosterEntry *rec1 = &Stg35_Battle.rec[arg1];
    s32 a;
    s32 b;
    s32 prod;
    s32 c;
    s32 d;
    s32 num;
    s32 idx;
    s32 denom;
    s32 result;

    b = Skill_GetPower(arg2);
    a = rec0->attack;
    Skill_GetSpecialty(arg2);
    c = rec1->defense;
    idx = Stg35_HudPeekGaugeLevel(arg1 >= 3);
    d = Stg35_GaugeDefPercent[idx];
    num = a * b;
    prod = c * d;
    c = prod / 100;
    denom = c * 2;
    result = num / denom;
    if (result < rec1->hp) {
        rec1->hp = rec1->hp - result;
    } else {
        rec1->hp = 0;
    }
    return result;
}

void Stg35_TurnOrderClear(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        Stg35_TurnOrder[i] = v;
    }
}

void Stg35_TurnOrderInsert(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 10; i >= arg0; i--) {
        Stg35_TurnOrder[i + 1] = Stg35_TurnOrder[i];
    }
    Stg35_TurnOrder[arg0] = arg1;
}

void Stg35_TurnOrderRemove(s32 arg0) {
    for (; arg0 < 11; arg0++) {
        Stg35_TurnOrder[arg0] = Stg35_TurnOrder[arg0 + 1];
    }
}

s32 Stg35_TurnOrderFind(s32 arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (arg0 == Stg35_TurnOrder[i]) {
            return i;
        }
    }
    return -1;
}

s32 Stg35_TurnOrderFreeIndex(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (Stg35_TurnOrder[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 Stg35_TurnOrderGet(s32 arg0) {
    return Stg35_TurnOrder[arg0];
}

void Stg35_BuildTurnOrder(void) {
    s32 v[6];
    s32 i;
    s32 j;
    s32 best;
    s32 max;

    for (i = 0; i < 6; i++) {
        if (Stg35_Battle.rec[i].hp != 0) {
            v[i] = Stg35_Battle.rec[i].speed + (u16)((u16)Rand_Next() % 11);
        } else {
            v[i] = 0;
        }
    }
    Stg35_TurnOrderClear();
    for (i = 0; i < 6; i++) {
        max = 0;
        best = 0;
        for (j = 0; j < 6; j++) {
            if (v[j] != 0 && max < v[j]) {
                max = v[j];
                best = j;
            }
        }
        if (max == 0) {
            break;
        }
        Stg35_TurnOrderInsert(Stg35_TurnOrderFreeIndex(), best);
        v[best] = 0;
    }
}

void Stg35_SetChosenAction(s32 arg0, s32 arg1) {
    Stg35Action *b = &Stg35_Battle.actions[arg0];
    s32 t;
    s32 base;
    s32 n;

    b->actionState = 1;
    b->skillId = b->skills[arg1];
    switch (b->targetTypes[arg1]) {
    case 0:
    default:
        t = Stg35_DefaultTargets[arg0];
        if (Stg35_Battle.rec[t].hp != 0) {
            b->target = t;
            break;
        }
    case 1:
        if (arg0 < 3) {
            base = 3;
        } else {
            base = 0;
        }
        for (n = 0; n < 100; n++) {
            t = (u16)((u16)Rand_Next() % 3) + base;
            if (Stg35_Battle.rec[t].hp != 0) {
                break;
            }
        }
        if (n == 100) {
            t = arg0;
        }
        b->target = t;
        break;
    case 2:
        if (arg0 < 3) {
            b->target = 8;
        } else {
            b->target = 7;
        }
        break;
    }
}
