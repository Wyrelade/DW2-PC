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
/* Code that reads parts of Stg30_Battle through symbols of their own. */
DATA_LABEL(D_80073CC4, Stg30_Battle, 0x004);
DATA_LABEL(D_80073CC8, Stg30_Battle, 0x008);
DATA_LABEL(D_80073CD4, Stg30_Battle, 0x014);
DATA_LABEL(D_80073CD8, Stg30_Battle, 0x018);
DATA_LABEL(D_80073D24, Stg30_Battle, 0x064);
DATA_LABEL(D_80073E02, Stg30_Battle, 0x142);
DATA_LABEL(D_80073E5E, Stg30_Battle, 0x19E);
DATA_LABEL(D_80073EBA, Stg30_Battle, 0x1FA);
DATA_LABEL(D_80073F6C, Stg30_Battle, 0x2AC);
DATA_LABEL(D_80074070, Stg30_Battle, 0x3B0);
DATA_LABEL(D_80074074, Stg30_Battle, 0x3B4);
DATA_LABEL(D_80074094, Stg30_Battle, 0x3D4);
DATA_LABEL(D_80074098, Stg30_Battle, 0x3D8);
DATA_LABEL(D_8007409C, Stg30_Battle, 0x3DC);

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
        if (Stg30_Battle.entries[i].digiId != 0 && (mode == 3 || Stg30_Battle.entries[i].hp != 0)) {
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
        if (Stg30_Battle.entries[i].digiId != 0 && (mode == 3 || Stg30_Battle.entries[i].hp != 0)) {
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
        if (Stg30_Battle.entries[i].digiId != 0 && (mode == 3 || Stg30_Battle.entries[i].hp != 0)) {
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
        Stg30_FighterStateBackup.digis[i] = ((Stg30StateDigis *)&Stg30_Battle)->digis[i];
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
        ((Stg30StateDigis *)&Stg30_Battle)->digis[i] = Stg30_FighterStateBackup.digis[i];
        Stg30_Battle.statusFlags[i] = Stg30_FighterStateBackup.statusFlags[i];
        Stg30_Battle.debuffed[i] = Stg30_FighterStateBackup.debuffed[i];
        Stg30_Battle.buffed[i] = Stg30_FighterStateBackup.buffed[i];
        Stg30_Battle.attackCur[i] = Stg30_FighterStateBackup.attackCur[i];
        Stg30_Battle.defenseCur[i] = Stg30_FighterStateBackup.defenseCur[i];
        Stg30_Battle.speedCur[i] = Stg30_FighterStateBackup.speedCur[i];
    }
}
