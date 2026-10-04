#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"

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

s32 Stg30_AiCanUseAction(s32 idx, s32 i, Stg30ByteLists *p) {
    s32 v = p->field_9[i];

    switch (v) {
    case 1:
    case 2:
    case 3:
        if (Stg30_Battle.entries[idx].field_32 >= Skill_GetMpCost(p->field_2[i])) {
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
            if (i != self && Stg30_Battle.entries[i].field_2E != 0) {
                ret = 0;
            }
        }
        return ret;
    case 8:
        ret = 1;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.entries[i].field_2E != Stg30_Battle.entries[i].field_2C) {
                ret = 0;
            }
        }
        return ret;
    case 9:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.entries[i].field_2E < (s16)(Stg30_Battle.entries[i].field_2C / 10)) {
                ret = 1;
            }
        }
        return ret;
    case 10:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && (Stg30_Battle.field_31C[i] & 7)) {
                ret = 1;
            }
        }
        return ret;
    case 11:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.field_340[i] != 0) {
                ret = 1;
            }
        }
        return ret;
    case 12:
        ret = 0;
        for (i = 3; i < 6; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.entries[i].field_2E == 0) {
                ret = 1;
            }
        }
        return ret;
    case 13:
        ret = 0;
        for (i = 0; i < 6; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.entries[i].field_2E == 0) {
                ret = 1;
            }
        }
        return ret;
    case 14:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.field_346[i] != 0) {
                ret = 1;
            }
        }
        return ret;
    case 15:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Digi_GetType(Stg30_Battle.entries[i].field_19) == 0) {
                ret = 1;
            }
        }
        return ret;
    case 16:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Digi_GetType(Stg30_Battle.entries[i].field_19) == 1) {
                ret = 1;
            }
        }
        return ret;
    case 17:
        ret = 0;
        for (i = 0; i < 3; i++) {
            if (Stg30_Battle.entries[i].field_19 != 0 && Digi_GetType(Stg30_Battle.entries[i].field_19) == 2) {
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
            if (Stg30_Battle.entries[x].field_2E != 0) {
                return x;
            }
        }
        return def;
    case 7:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3);
            if (Stg30_Battle.entries[x].field_2E != 0) {
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
            v = Stg30_Battle.entries[i].field_2E;
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
            v = Stg30_Battle.entries[i].field_2E;
            if (v != 0 && v < min) {
                j = i;
                min = v;
            }
        }
        return j;
    case 6:
        for (i = 0; i < 100; i++) {
            x = (u16)((u16)Rand_Next() % 3) + 3;
            if (Stg30_Battle.entries[x].field_19 != 0 && Stg30_Battle.entries[x].field_2E == 0) {
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
        Stg30ByteLists *p = &((Stg30SlotBlk *)D_80073CD8)->lists[col];
        Stg30Sub10 *out = &((Stg30SlotBlk *)D_80073CD8)->sub[col];
        s32 i;

        if (d->hp != 0) {
            out->field_0 = 0;
            out->field_4 = 0;
            out->field_6 = 0;
            for (i = 0; i < 4; i++) {
                if (p->field_9[i] == 0) {
                    break;
                }
                if (Stg30_AiCanUseAction(col, i, p)) {
                    if (Stg30_AiCheckCondition(p->field_5[i], col)) {
                        s32 v;
                        if (p->field_9[i] == 4) {
                            out->field_0 = 5;
                            break;
                        }
                        v = (&d->b21[0])[p->field_9[i]];
                        out->field_6 = v;
                        out->field_4 = Stg30_PickTarget(v, p->field_D[i], col);
                        out->field_0 = Skill_GetType(out->field_6) + 1;
                        out->field_8 = Stg30_GetSkillEffectKind(out->field_6);
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
        if (Stg30_Battle.entries[i].field_2E != 0 && Stg30_Battle.field_2AC[i].field_0 != 0) {
            bonus = 0;
            if (Stg30_Battle.field_2AC[i].field_0 == 1 && (func_8001F020(Stg30_Battle.field_2AC[i].field_6) & 8)) {
                bonus = Stg30_Battle.entries[i].field_38;
            }
            spd[i] = Stg30_Battle.entries[i].field_38 + bonus + (u16)((u16)Rand_Next() % 11);
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
            switch (Stg30_Battle.field_2AC[i].field_0) {
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
        if (Stg30_Battle.entries[i].field_19 != 0 && Stg30_Battle.field_2AC[i].field_6 != 0 &&
            (func_8001F020(Stg30_Battle.field_2AC[i].field_6) & 0x20)) {
            slot2 = Stg30_TurnOrderFind(i);
            if (slot2 != -1) {
                Stg30_TurnOrderRemove(slot2);
                Stg30_TurnOrderInsert(Stg30_TurnOrderFreeIndex(), i);
            }
        }
    }
    if (Stg30_Battle.field_2AC[Stg30_TurnOrderGet(0)].field_0 == 2) {
        Stg30_Battle.field_2AC[Stg30_TurnOrderGet(0)].field_0 = 1;
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

    Stg30_Battle.field_3B0 = 0;
    for (i = 0; D_800731B8[i] != 0; i++) {
        if ((Stg30_Battle.field_31C[idx] & D_800731B8[i]) && (Rand_Next() & 3) == 0) {
            Stg30_Battle.field_31C[idx] -= D_800731B8[i];
            Stg30_Battle.field_3B0 = D_800731C8[i];
        }
    }
    for (i = 0; D_800731D0[i] != 0; i++) {
        if ((Stg30_Battle.field_31C[idx] & D_800731D0[i]) && (u16)((u16)Rand_Next() % 3) == 0) {
            Stg30_Battle.field_31C[idx] -= D_800731D0[i];
            Stg30_Battle.field_3B0 = D_800731FC[i];
        }
    }
    if (Stg30_Battle.field_31C[idx] & 4) {
        n = 0;
        for (i = 0; i < 12; i++) {
            if (Stg30_Battle.entries[idx].field_3A[i] == 0) {
                break;
            }
            if (Skill_GetCastAnim(Stg30_Battle.entries[idx].field_3A[i]) == 0) {
                buf[n++] = Stg30_Battle.entries[idx].field_3A[i];
            }
        }
        if (n == 0) {
            Stg30_Battle.field_2AC[idx].field_0 = 0;
            Stg30_Battle.field_2AC[idx].field_4 = 0;
            Stg30_Battle.field_2AC[idx].field_6 = 0;
            Stg30_Battle.field_2AC[idx].field_8 = 0;
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
        } while ((n == 1 || n == 5) && Stg30_Battle.entries[t].field_2E == 0);
        Stg30_Battle.field_2AC[idx].field_0 = 1;
        Stg30_Battle.field_2AC[idx].field_6 = tech;
        Stg30_Battle.field_2AC[idx].field_4 = t;
        Stg30_Battle.field_2AC[idx].field_8 = Stg30_GetSkillEffectKind(tech);
    }
    return 1;
}
