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
#include "stag3000/battle.h"
#include "stag3000/turn.h"
#include "stag3000/skilleffect.h"
#include "stag3000/battlescript.h"
#include "stag3000/itemeffect.h"

s32 Stg30_TurnOrder[12];
Stg30FighterBackup Stg30_FighterStateBackup;
Stg30Battle Stg30_Battle;
/* Stg30_Battle.digis (0x18) and their names (0x18 + 0x4C) under their own symbols: retail code
 * reaches the fighter block from 0x18 through these (Stg30CombatCD8 / Stg30SlotBlk views). */
DATA_LABEL(Stg30_BattleDigis, Stg30_Battle, 0x018);
DATA_LABEL(Stg30_BattleDigiNames, Stg30_Battle, 0x064);

s32 Stg30_GetSkillEffectKind(s32 id) {
    s32 r = Skill_GetPower(id);

    if (r > 0) {
        return 0;
    }
    if (r < 0) {
        return 1;
    }
    if (Skill_GetCureFlags(id) & 0x20000) {
        return 3;
    }
    return 2;
}

s32 Stg30_TargetFirst(s32 team, s32 flag, s32 mode) {
    s32 i;
    s32 lo = team * 3;

    for (i = lo; i < lo + 3; i++) {
        if (Stg30_Battle.digis[i].digiId != 0 && (mode == 3 || Stg30_Battle.digis[i].hp != 0)) {
            if (flag == 0 || !(Stg30_Battle.statusFlags[i] & 0x10000)) {
                return i;
            }
        }
    }
    return lo;
}

s32 Stg30_TargetPrev(s32 team, s32 cur, s32 flag, s32 mode) {
    s32 i;
    s32 lo = team * 3;

    for (i = cur - 1; i >= lo; i--) {
        if (Stg30_Battle.digis[i].digiId != 0 && (mode == 3 || Stg30_Battle.digis[i].hp != 0)) {
            if (flag == 0 || !(Stg30_Battle.statusFlags[i] & 0x10000)) {
                return i;
            }
        }
    }
    return cur;
}

s32 Stg30_TargetNext(s32 team, s32 cur, s32 flag, s32 mode) {
    s32 i;

    for (i = cur + 1; i < team * 3 + 3; i++) {
        if (Stg30_Battle.digis[i].digiId != 0 && (mode == 3 || Stg30_Battle.digis[i].hp != 0)) {
            if (flag == 0 || !(Stg30_Battle.statusFlags[i] & 0x10000)) {
                return i;
            }
        }
    }
    return cur;
}

void Stg30_TurnOrderClear(void) {
    s32 v = -1;
    s32 i;

    for (i = 11; i >= 0; i--) {
        Stg30_TurnOrder[i] = v;
    }
}

void Stg30_TurnOrderInsert(s32 idx, s32 v) {
    s32 i;

    for (i = 10; i >= idx; i--) {
        Stg30_TurnOrder[i + 1] = Stg30_TurnOrder[i];
    }
    Stg30_TurnOrder[idx] = v;
}

void Stg30_TurnOrderRemove(s32 i) {
    for (; i < 11; i++) {
        Stg30_TurnOrder[i] = Stg30_TurnOrder[i + 1];
    }
}

s32 Stg30_TurnOrderFind(s32 v) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (v == Stg30_TurnOrder[i]) {
            return i;
        }
    }
    return -1;
}

s32 Stg30_TurnOrderFreeIndex(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (Stg30_TurnOrder[i] == -1) {
            return i;
        }
    }
    return i - 1;
}

s32 Stg30_TurnOrderGet(s32 i) {
    return Stg30_TurnOrder[i];
}

void Stg30_SaveFighterStates(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        Stg30_FighterStateBackup.digis[i] = Stg30_Battle.digis[i];
        Stg30_FighterStateBackup.statusFlags[i] = Stg30_Battle.statusFlags[i];
        Stg30_FighterStateBackup.debuffed[i] = Stg30_Battle.debuffed[i];
        Stg30_FighterStateBackup.buffed[i] = Stg30_Battle.buffed[i];
        Stg30_FighterStateBackup.attackCur[i] = Stg30_Battle.attackCur[i];
        Stg30_FighterStateBackup.defenseCur[i] = Stg30_Battle.defenseCur[i];
        Stg30_FighterStateBackup.speedCur[i] = Stg30_Battle.speedCur[i];
    }
}

void Stg30_RestoreFighterStates(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        Stg30_Battle.digis[i] = Stg30_FighterStateBackup.digis[i];
        Stg30_Battle.statusFlags[i] = Stg30_FighterStateBackup.statusFlags[i];
        Stg30_Battle.debuffed[i] = Stg30_FighterStateBackup.debuffed[i];
        Stg30_Battle.buffed[i] = Stg30_FighterStateBackup.buffed[i];
        Stg30_Battle.attackCur[i] = Stg30_FighterStateBackup.attackCur[i];
        Stg30_Battle.defenseCur[i] = Stg30_FighterStateBackup.defenseCur[i];
        Stg30_Battle.speedCur[i] = Stg30_FighterStateBackup.speedCur[i];
    }
}
