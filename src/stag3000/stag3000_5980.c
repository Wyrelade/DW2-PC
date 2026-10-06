#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"

s32 Stg30_StatusWearOff4Masks[] = { 2, 4, 0x40, 0 };
u16 Stg30_StatusWearOff4Labels[] = { 4, 6, 0x203, 0 };
s32 Stg30_StatusWearOff3Masks[] = {
    8, 0x10000, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0,
};
u16 Stg30_StatusWearOff3Labels[] = { 0xD, 0x10D, 0x1C, 0x1E, 0x20, 0x102, 0x104, 0x106, 0x108, 0x10A };

void Stg30_BattleDestroy(Actor *a0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (((Stg30StateDigis *)&Stg30_Battle)->digis[i].state >= 3) {
            Save_GameState.elems[i] = ((Stg30StateDigis *)&Stg30_Battle)->digis[i];
        }
    }
    Gpu_InitDoubleBuffer(0x140, 0xF0, 0, 0);
    Task_DefaultDestroy(a0);
}

s32 Stg30_AiCanUseAction(s32 idx, s32 i, Stg30EnemyAi *p) {
    s32 v = p->actionKinds[i];

    switch (v) {
    case 1:
    case 2:
    case 3:
        if (Stg30_Battle.entries[idx].mp >= Skill_GetMpCost(p->skillIds[i])) {
            return 1;
        }
    case 4:
        return 1;
    default:
        return 0;
    }
}

s32 Stg30_AiCheckCondition(s32 cond, s32 self) {
    s32 r;
    s32 i;
    s32 ret;

    r = Rand_Next() & 0xFFFF;
    switch (cond) {
    case 0:
        return 1;
    case 1:
        return !(r & 1);
    case 2:
        return (r & 3) == 0;
    case 3:
        return (r & 7) == 0;
    case 5:
        return D_80073E02 != 0;
    case 4:
        return D_80073E5E != 0;
    case 6:
        return D_80073EBA != 0;
    case 7:
        ret = 1;
        for (i = 3; i < 6; i++) {
            if (i != self && Stg30_Battle.entries[i].hp != 0) {
                ret = 0;
            }
        }
        return ret;
    case 8:
        ret = 1;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp != Stg30_Battle.entries[i].maxHp) {
                ret = 0;
            }
        }
        return ret;
    case 9:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp < (s16)(Stg30_Battle.entries[i].maxHp / 10)) {
                ret = 1;
            }
        }
        return ret;
    case 10:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && (Stg30_Battle.statusFlags[i] & 7)) {
                ret = 1;
            }
        }
        return ret;
    case 11:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.debuffed[i] != 0) {
                ret = 1;
            }
        }
        return ret;
    case 12:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp == 0) {
                ret = 1;
            }
        }
        return ret;
    case 13:
        ret = 0;
        for (i = 0; i < 6; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp == 0) {
                ret = 1;
            }
        }
        return ret;
    case 14:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.buffed[i] != 0) {
                ret = 1;
            }
        }
        return ret;
    case 15:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Digi_GetType(Stg30_Battle.entries[i].digiId) == 0) {
                ret = 1;
            }
        }
        return ret;
    case 16:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Digi_GetType(Stg30_Battle.entries[i].digiId) == 1) {
                ret = 1;
            }
        }
        return ret;
    case 17:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].digiId != 0 && Digi_GetType(Stg30_Battle.entries[i].digiId) == 2) {
                ret = 1;
            }
        }
        return ret;
    }
    return 0;
}

s32 Stg30_PickTarget(s32 id, s32 kind, s32 def) {
    s32 i;
    s32 j;
    s32 min;
    s32 x;
    s16 v;

    switch (kind) {
    case 0:
        x = Skill_GetTarget(id);
        if (x == 2) goto r8;
        if (x < 3) return def;
        if (x == 6) goto r7;
        if (x == 8) goto r9;
        return def;
    r8:
        return 8;
    r7:
        return 7;
    r9:
        return 9;
    case 1:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3) + 3;
            if (Stg30_Battle.entries[x].hp != 0) {
                return x;
            }
        }
        return def;
    case 7:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3);
            if (Stg30_Battle.entries[x].hp != 0) {
                return x;
            }
        }
        return def;
    case 3:
        return 3;
    case 2:
        return 4;
    case 4:
        return 5;
    case 5:
        j = def;
        min = 9999;
        for (i = 3; i < 6; i++) {
            v = Stg30_Battle.entries[i].hp;
            if (v != 0 && v < min) {
                j = i;
                min = v;
            }
        }
        return j;
    case 8:
        j = 0;
        min = 9999;
        for (i = 0; i < 3; i++) {
            v = Stg30_Battle.entries[i].hp;
            if (v != 0 && v < min) {
                j = i;
                min = v;
            }
        }
        return j;
    case 6:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3) + 3;
            if (Stg30_Battle.entries[x].digiId != 0 && Stg30_Battle.entries[x].hp == 0) {
                return x;
            }
        }
        return x;
    }
    return def;
}

void Stg30_AiChooseEnemyTurns(void) {
    s32 col;

    for (col = 3; col < 6; col++) {
        Stg30DigiB21 *d = &((Stg30SlotBlk *)D_80073CD8)->digis[col];
        Stg30EnemyAi *p = &((Stg30SlotBlk *)D_80073CD8)->lists[col];
        Stg30Turn *out = &((Stg30SlotBlk *)D_80073CD8)->sub[col];
        s32 i;

        if (d->hp != 0) {
            out->turnType = 0;
            out->target = 0;
            out->skillId = 0;
            for (i = 0; i < 4; i++) {
                if (p->actionKinds[i] == 0) {
                    break;
                }
                if (Stg30_AiCanUseAction(col, i, p)) {
                    if (Stg30_AiCheckCondition(p->conditions[i], col)) {
                        s32 v;
                        if (p->actionKinds[i] == 4) {
                            out->turnType = 5;
                            break;
                        }
                        v = (&d->b21[0])[p->actionKinds[i]];
                        out->skillId = v;
                        out->target = Stg30_PickTarget(v, p->targetModes[i], col);
                        out->turnType = Skill_GetType(out->skillId) + 1;
                        out->effectKind = Stg30_GetSkillEffectKind(out->skillId);
                        break;
                    }
                }
            }
        }
    }
}

void Stg30_BuildTurnOrder(void) {
    s32 spd[6];
    s32 i;
    s32 n;
    s32 best;
    s32 bonus;
    s32 k;
    s32 slot;
    s32 slot2;
    s32 j;

    for (i = 0; i < 6; i++) {
        if (Stg30_Battle.entries[i].hp != 0 && Stg30_Battle.turns[i].turnType != 0) {
            bonus = 0;
            if (Stg30_Battle.turns[i].turnType == 1 && (func_8001F020(Stg30_Battle.turns[i].skillId) & 8)) {
                bonus = Stg30_Battle.entries[i].speed;
            }
            spd[i] = Stg30_Battle.entries[i].speed + bonus + (u16)((u16)Rand_Next() % 11);
        } else {
            spd[i] = 0;
        }
    }
    Stg30_TurnOrderClear();
    for (i = 0; i < 6; ) {
        best = 0;
        n = 0;
        for (j = 0; j < 6; j++) {
            if (spd[j] != 0 && best < spd[j]) {
                best = spd[j];
                n = j;
            }
        }
        if (best == 0) {
            break;
        }
        i++;
        Stg30_TurnOrderInsert(Stg30_TurnOrderFreeIndex(), n);
        spd[n] = 0;
    }
    for (i = 0; i < 6; i++) {
        slot = Stg30_TurnOrderFind(i);
        k = Stg30_TurnOrderGet(slot);
        if (slot != -1) {
            switch (Stg30_Battle.turns[i].turnType) {
            case 2:
                Stg30_TurnOrderRemove(slot);
                Stg30_TurnOrderInsert(Stg30_TurnOrderFreeIndex(), i);
                break;
            case 3:
                Stg30_TurnOrderRemove(slot);
                break;
            case 5:
                Stg30_TurnOrderRemove(slot);
                Stg30_TurnOrderInsert(0, k);
                break;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.turns[i].skillId != 0 &&
            (func_8001F020(Stg30_Battle.turns[i].skillId) & 0x20)) {
            slot2 = Stg30_TurnOrderFind(i);
            if (slot2 != -1) {
                Stg30_TurnOrderRemove(slot2);
                Stg30_TurnOrderInsert(Stg30_TurnOrderFreeIndex(), i);
            }
        }
    }
    if (Stg30_Battle.turns[Stg30_TurnOrderGet(0)].turnType == 2) {
        Stg30_Battle.turns[Stg30_TurnOrderGet(0)].turnType = 1;
    }
}

s32 Stg30_CompareTypes(s32 a, s32 b) {
    if (a == b) {
        return 0;
    }
    if (a == 0 && b == 1) {
        return 1;
    }
    if (a == 1 && b == 2) {
        return 1;
    }
    if (a == 2 && b == 0) {
        return 1;
    }
    return -1;
}

s32 Stg30_UpdateTurnStatus(s32 idx) {
    u8 buf[12];
    s32 i;
    s32 n;
    s32 tech;
    s32 t;

    Stg30_Battle.statusMsg = 0;
    for (i = 0; Stg30_StatusWearOff4Masks[i] != 0; i++) {
        if ((Stg30_Battle.statusFlags[idx] & Stg30_StatusWearOff4Masks[i]) && (Rand_Next() & 3) == 0) {
            Stg30_Battle.statusFlags[idx] -= Stg30_StatusWearOff4Masks[i];
            Stg30_Battle.statusMsg = Stg30_StatusWearOff4Labels[i];
        }
    }
    for (i = 0; Stg30_StatusWearOff3Masks[i] != 0; i++) {
        if ((Stg30_Battle.statusFlags[idx] & Stg30_StatusWearOff3Masks[i]) && (u16)((u16)Rand_Next() % 3) == 0) {
            Stg30_Battle.statusFlags[idx] -= Stg30_StatusWearOff3Masks[i];
            Stg30_Battle.statusMsg = Stg30_StatusWearOff3Labels[i];
        }
    }
    if (Stg30_Battle.statusFlags[idx] & 4) {
        n = 0;
        for (i = 0; i < 12; i++) {
            if (Stg30_Battle.entries[idx].skillIds[i] == 0) {
                break;
            }
            if (Skill_GetCastAnim(Stg30_Battle.entries[idx].skillIds[i]) == 0) {
                buf[n++] = Stg30_Battle.entries[idx].skillIds[i];
            }
        }
        if (n == 0) {
            Stg30_Battle.turns[idx].turnType = 0;
            Stg30_Battle.turns[idx].target = 0;
            Stg30_Battle.turns[idx].skillId = 0;
            Stg30_Battle.turns[idx].effectKind = 0;
            return 0;
        }
        tech = buf[(u16)Rand_Next() % n];
        n = Skill_GetTarget(tech);
        do {
            switch (n) {
            case 0:
            case 3:
            case 4:
            case 7:
            default:
                t = idx;
                break;
            case 1:
                if (idx < 3) {
                    t = (u16)((u16)Rand_Next() % 3);
                } else {
                    t = (u16)((u16)Rand_Next() % 3) + 3;
                }
                break;
            case 5:
                if (idx < 3) {
                    t = (u16)((u16)Rand_Next() % 3);
                } else {
                    t = (u16)((u16)Rand_Next() % 3) + 3;
                }
                break;
            case 2:
            case 6:
                if (idx < 3) {
                    t = 7;
                } else {
                    t = 8;
                }
                break;
            case 8:
                t = 9;
                break;
            }
        } while ((n == 1 || n == 5) && Stg30_Battle.entries[t].hp == 0);
        Stg30_Battle.turns[idx].turnType = 1;
        Stg30_Battle.turns[idx].skillId = tech;
        Stg30_Battle.turns[idx].target = t;
        Stg30_Battle.turns[idx].effectKind = Stg30_GetSkillEffectKind(tech);
    }
    return 1;
}
