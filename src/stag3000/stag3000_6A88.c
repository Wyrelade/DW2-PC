#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/banner.h"
#include "stag3000/fightbg.h"
#include "stag3000/actionload.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"

s32 Stg30_CureStatusMasks[] = {
    1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x800, 0x400, 0x100, 0x200, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000,
};
s16 Stg30_CureStatusLabels[] = { 2, 4, 6, 0xD, 0, 0, 5, 0x1C, 5, 3, 0x1E, 0x20, 7, 9, 0xB, 0x19, 0, 0 };
s32 Stg30_RepeatSkillCount = 0;

s16 Stg30_BattleScript[0xC8];

void Stg30_RetargetAction(void) {
    s32 idx = Stg30_TurnOrderGet(0);
    Stg30Rec73F6C *e = &D_80073F6C[idx];
    s32 fl = func_8001F044(e->skillId);
    s32 lo;
    s32 n;
    s32 i;
    s32 t;
    s32 cnt;
    s32 max;
    s32 best;
    s32 list[6];
    s32 k;

    if ((fl & 2) && e->turnType != 2) {
        lo = 0;
        n = 3;
        switch (e->target) {
        case 3:
        case 4:
        case 5:
        case 8:
            lo = 3;
            break;
        case 9:
            n = 6;
            break;
        }
        for (i = 0; i < 100; i++) {
            t = (u16)Rand_Next() % n + lo;
            if (Stg30_Battle.entries[t].hp != 0) {
                break;
            }
        }
        if (i == 100) {
            t = idx;
        }
        e->target = t;
    }
    if ((fl & 4) && e->turnType == 2) {
        e->target = idx < 3 ? 8 : 7;
    }
    if (fl & 8) {
        best = idx;
        cnt = 0;
        for (k = 0; k < 6; k++) {
            if (Stg30_Battle.entries[k].digiId != 0 && Stg30_Battle.entries[k].hp == 0) {
                list[cnt++] = k;
            }
        }
        max = 0;
        for (k = 0; k < cnt; k++) {
            if (max < Stg30_Battle.entries[list[k]].mp) {
                max = Stg30_Battle.entries[list[k]].mp;
                best = list[k];
            }
        }
        e->target = best;
    }
}

s32 Stg30_CompareSpecialty(s32 a, s32 b) {
    if (a == 5) {
        return 0;
    }
    if (b == 5) {
        return 0;
    }
    if (a == 0 && b == 1) {
        return 1;
    }
    if (a == 1 && b == 2) {
        return 1;
    }
    if (a == 2 && b == 3) {
        return 1;
    }
    if (a == 3 && b == 4) {
        return 1;
    }
    if (a == 4 && b == 0) {
        return 1;
    }
    if (a == 0 && b == 2) {
        return -1;
    }
    if (a == 1 && b == 3) {
        return -1;
    }
    if (a == 2 && b == 4) {
        return -1;
    }
    if (a == 3 && b == 0) {
        return -1;
    }
    if (a == 4 && b == 1) {
        return -1;
    }
    return 0;
}

s32 Stg30_GetFloorSpecialty(void) {
    if (Dung_State.floorSpecialty == 0) {
        return 5;
    }
    return Dung_State.floorSpecialty - 2;
}

s32 Stg30_ApplySkillStatus(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5) {
    s32 revived;
    s32 flags;
    u32 already;
    s32 cure;
    s32 i;
    s32 old;
    s32 mask;
    s32 hit;

    revived = 0;
    flags = Skill_GetStatusFlags(tech);
    already = Stg30_Battle.statusFlags[target] & 1;
    if (flags & 1) {
        if ((u16)((u16)Rand_Next() % 3) == 0) {
            Stg30_Battle.statusFlags[target] |= 1;
        }
    }
    if (flags & 2) {
        if ((u16)((u16)Rand_Next() % 3) != 0) {
            Stg30_Battle.statusFlags[target] |= 1;
        }
    }
    if (flags & 4) {
        if (Stg30_Battle.turns[attacker].turnType == 2) {
            Stg30_Battle.statusFlags[target] |= 1;
        }
    }
    if (!already) {
        if (Stg30_Battle.statusFlags[target] & 1) {
            *p5 = 1;
        }
    }
    already = (u32)Stg30_Battle.statusFlags[target] >> 1;
    already &= 1;
    if (flags & 0x10) {
        if ((u16)((u16)Rand_Next() % 3) == 0) {
            Stg30_Battle.statusFlags[target] |= 2;
        }
    }
    if (flags & 0x20) {
        if ((u16)((u16)Rand_Next() % 3) != 0) {
            Stg30_Battle.statusFlags[target] |= 2;
        }
    }
    if (flags & 0x40) {
        if (Stg30_Battle.turns[attacker].turnType == 2) {
            Stg30_Battle.statusFlags[target] |= 2;
        }
    }
    if (flags & 0x80) {
        if (Stg30_Battle.turns[attacker].turnType == 3) {
            Stg30_Battle.statusFlags[target] |= 2;
        }
    }
    if (!already) {
        if (Stg30_Battle.statusFlags[target] & 2) {
            *p5 = 3;
        }
    }
    if (Stg30_Battle.isBossFight == 0 || target < 3) {
        already = (u32)Stg30_Battle.statusFlags[target] >> 2;
    already &= 1;
        if (flags & 0x100) {
            if ((u16)((u16)Rand_Next() % 3) == 0) {
                Stg30_Battle.statusFlags[target] |= 4;
            }
        }
        if (flags & 0x200) {
            if ((u16)((u16)Rand_Next() % 3) != 0) {
                Stg30_Battle.statusFlags[target] |= 4;
            }
        }
        if (flags & 0x400) {
            if (Stg30_Battle.turns[attacker].turnType == 2) {
                Stg30_Battle.statusFlags[target] |= 4;
            }
        }
        if (!already) {
            if (Stg30_Battle.statusFlags[target] & 4) {
                *p5 = 5;
            }
        }
    }
    if (flags & 0x1000000) {
        if (Stg30_Battle.entries[target].hp == 0) {
            Stg30_Battle.statusFlags[target] |= 0x8000;
            Stg30_Battle.entries[target].hp = 1;
            Stg30_Battle.preventFlags[target] |= 0xA;
            *p4 = 3;
            *p5 = 0x119;
        }
    }
    if (flags & 0x1000) {
        Stg30_Battle.statusFlags[target] |= 8;
        *p5 = 0xC;
    }
    if (flags & 0x4000) {
        Stg30_Battle.statusFlags[target] |= 0x20;
    }
    if (flags & 0x8000) {
        Stg30_Battle.statusFlags[target] |= 0x40;
        *p5 = 0x10B;
    }
    if (flags & 0x10000) {
        Stg30_Battle.statusFlags[target] |= 0x80;
        *p5 = 0x1B;
    }
    if (flags & 0x20000) {
        Stg30_Battle.statusFlags[target] |= 0x800;
        *p5 = 0x103;
    }
    if (flags & 0x40000) {
        Stg30_Battle.statusFlags[target] |= 0x400;
        *p5 = 0x101;
    }
    if (flags & 0x80000) {
        Stg30_Battle.statusFlags[target] |= 0x100;
        *p5 = 0x1D;
    }
    if (flags & 0x100000) {
        Stg30_Battle.statusFlags[target] |= 0x200;
        *p5 = 0x1F;
    }
    if (flags & 0x200000) {
        Stg30_Battle.statusFlags[target] |= 0x1000;
        *p5 = 0x105;
    }
    if (flags & 0x400000) {
        Stg30_Battle.statusFlags[target] |= 0x2000;
        *p5 = 0x107;
    }
    if (flags & 0x800000) {
        Stg30_Battle.statusFlags[target] |= 0x4000;
        *p5 = 0x109;
    }
    if (flags & 0x2000000) {
        Stg30_Battle.statusFlags[target] |= 0x10000;
        *p5 = 0x10C;
    }
    if (!(Stg30_Battle.preventFlags[target] & 4)) {
        flags = Skill_GetCureFlags(tech);
        if (flags & 0x20000) {
            revived = 1;
            Stg30_Battle.entries[target].hp = Stg30_Battle.entries[target].maxHp;
            *p4 = 3;
            *p5 = 0x18;
        }
        for (cure = 1, i = 0; i < 17; cure <<= 1, i++) {
            old = Stg30_Battle.statusFlags[target];
            mask = Stg30_CureStatusMasks[i];
            hit = old & mask;
            if (flags & cure) {
                Stg30_Battle.statusFlags[target] = old & ~mask;
                if (hit) {
                    *p5 = Stg30_CureStatusLabels[i];
                }
            }
        }
    }
    return revived;
}

void Stg30_StatDebuff(s16 *max, s16 *b, s16 *c) {
    s16 half = *max / 2;

    *c = *c * 90 / 128;
    if (*c < half) {
        *c = half;
    }
    *b = *b * 90 / 128;
    if (*b < half) {
        *b = half;
    }
}

void Stg30_StatBuff(s16 *max, s16 *b, s16 *c) {
    s16 lim;
    s16 t;

    t = *c + *c / 2;
    lim = *max * 2;
    *c = t;
    if (*c > lim) {
        *c = lim;
    }
    *b += *b / 2;
    if (*b > lim) {
        *b = lim;
    }
}

s32 Stg30_ApplySkillDamage(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5) {
    Stg30DigiS *a = &((Stg30StateS *)&Stg30_Battle)->digis[attacker];
    Stg30DigiS *t = &((Stg30StateS *)&Stg30_Battle)->digis[target];
    s32 type[2];
    s32 revived;
    s32 flags1;
    s32 flags2;
    s32 buff;
    s32 prevent;
    s32 dmg;
    s32 idx;
    s32 atk;
    s32 power;
    s32 aAtk;
    s32 def;
    s32 el;
    s32 tEl;
    s32 st;
    s32 hit;
    s32 hp;
    s32 gain;
    s32 drain;
    s32 steal;

    flags1 = func_8001F0E4(tech);
    flags2 = func_8001F10C(tech);
    buff = Skill_GetBuffFlags(tech);
    prevent = func_8001F158(tech);
    type[0] = Digi_GetType(a->digiId);
    dmg = 0;
    revived = 0;
    type[1] = Digi_GetType(t->digiId);
    if (prevent & 2) {
        Stg30_Battle.preventFlags[target] |= 2;
        *p5 = 0xF;
    }
    if (prevent & 4) {
        Stg30_Battle.preventFlags[target] |= 4;
        *p5 = 0x11;
    }
    if (prevent & 8) {
        idx = Stg30_TurnOrderFind(target);
        if (idx != -1) {
            switch (Stg30_Battle.turns[target].turnType) {
            case 2:
            case 3:
                Stg30_TurnOrderRemove(idx);
                *p5 = 0x118;
                break;
            }
        }
    }
    if (prevent & 0x10) {
        Stg30_Battle.preventFlags[target] |= 8;
        *p5 = 0x19;
    }
    if (flags2 & 0x200) {
        Stg30_Battle.statusFlags[target] |= Stg30_Battle.statusFlags[attacker];
    }
    if (buff & 1) {
        Stg30_StatDebuff(&Stg30_Battle.attackBase[target], &t->attack, &Stg30_Battle.attackCur[target]);
        *p5 = 9;
        Stg30_Battle.debuffed[target] = 1;
    }
    if (buff & 2) {
        Stg30_StatBuff(&Stg30_Battle.attackBase[target], &t->attack, &Stg30_Battle.attackCur[target]);
        *p5 = 0x15;
        Stg30_Battle.buffed[target] = 1;
    }
    if (buff & 4) {
        Stg30_StatDebuff(&Stg30_Battle.defenseBase[target], &t->defense, &Stg30_Battle.defenseCur[target]);
        *p5 = 0xA;
        Stg30_Battle.debuffed[target] = 1;
    }
    if (buff & 8) {
        Stg30_StatBuff(&Stg30_Battle.defenseBase[target], &t->defense, &Stg30_Battle.defenseCur[target]);
        *p5 = 0x16;
        Stg30_Battle.buffed[target] = 1;
    }
    if (buff & 0x10) {
        Stg30_StatDebuff(&Stg30_Battle.speedBase[target], &t->speed, &Stg30_Battle.speedCur[target]);
        *p5 = 0xB;
        Stg30_Battle.debuffed[target] = 1;
    }
    if (buff & 0x20) {
        Stg30_StatBuff(&Stg30_Battle.speedBase[target], &t->speed, &Stg30_Battle.speedCur[target]);
        *p5 = 0x17;
        Stg30_Battle.buffed[target] = 1;
    }
    if ((buff & 0x100) && Stg30_Battle.debuffed[target] != 0) {
        t->attack = Stg30_Battle.attackBase[target];
        t->defense = Stg30_Battle.defenseBase[target];
        t->speed = Stg30_Battle.speedBase[target];
        Stg30_Battle.debuffed[target] = 0;
    }
    if ((buff & 0x200) && Stg30_Battle.buffed[target] != 0) {
        t->attack = Stg30_Battle.attackBase[target];
        t->defense = Stg30_Battle.defenseBase[target];
        t->speed = Stg30_Battle.speedBase[target];
        Stg30_Battle.debuffed[target] = 0;
    }
    if ((buff & 0x400) && type[1] == 1) {
        Stg30_StatDebuff(&Stg30_Battle.attackBase[target], &t->attack, &Stg30_Battle.attackCur[target]);
        Stg30_StatDebuff(&Stg30_Battle.defenseBase[target], &t->defense, &Stg30_Battle.defenseCur[target]);
        *p5 = 0x14;
        Stg30_Battle.debuffed[target] = 1;
    }
    if ((buff & 0x800) && type[1] == 2) {
        Stg30_StatDebuff(&Stg30_Battle.attackBase[target], &t->attack, &Stg30_Battle.attackCur[target]);
        Stg30_StatDebuff(&Stg30_Battle.defenseBase[target], &t->defense, &Stg30_Battle.defenseCur[target]);
        *p5 = 0x14;
        Stg30_Battle.debuffed[target] = 1;
    }
    if ((buff & 0x1000) && type[1] == 0) {
        Stg30_StatDebuff(&((Stg30CombatCD8 *)D_80073CD8)->attackBase[target], &t->attack, &((Stg30CombatCD8 *)D_80073CD8)->attackCur[target]);
        Stg30_StatDebuff(&((Stg30CombatCD8 *)D_80073CD8)->defenseBase[target], &t->defense, &((Stg30CombatCD8 *)D_80073CD8)->defenseCur[target]);
        *p5 = 0x14;
        ((Stg30CombatCD8 *)D_80073CD8)->debuffed[target] = 1;
    }
    do {
        if (Stg30_Battle.turns[attacker].turnType == 2 && (flags1 & 1)) {
            hit = Stg30_Battle.turns[attacker].hpDelta;
            dmg = hit / 2 + hit;
            t->hp = (dmg < t->hp) ? t->hp - dmg : 0;
            break;
        }
        if (flags2 & 2) {
            dmg = t->hp / 2;
            t->hp -= dmg;
            if (t->hp == 0) {
                t->hp = 1;
            }
            break;
        }
        if ((flags2 & 4) && t->hp != 0) {
            dmg = t->maxHp - t->hp;
            t->hp = t->maxHp;
            break;
        }
        if (flags2 & 8) {
            if (t->hp < 60) {
                dmg = t->hp;
                t->hp = 0;
            } else {
                dmg = 0;
            }
            break;
        }
        revived = Stg30_ApplySkillStatus(attacker, target, tech, p4, p5);
        atk = Skill_GetPower(tech);
        if (atk == 0 || (Stg30_Battle.preventFlags[target] & 8)) {
            break;
        }
        if (atk < 0) {
            if (Stg30_Battle.statusFlags[attacker] & 0x8000) {
                dmg = 0;
                revived = 1;
                break;
            }
            dmg = 0;
            if (!(Stg30_Battle.preventFlags[target] & 2)) {
                t->hp -= atk;
                if (t->maxHp < t->hp) {
                    t->hp = t->maxHp;
                }
                dmg = atk;
            }
            break;
        }
        if (flags1 & 0x10) {
            if (Stg30_Battle.powerBuff[attacker] < 70) {
                Stg30_Battle.powerBuff[attacker] += 5;
            } else {
                Stg30_Battle.powerBuff[attacker] = 70;
            }
            atk += Stg30_Battle.powerBuff[attacker];
        } else {
            Stg30_Battle.powerBuff[attacker] = 0;
        }
        if ((flags1 & 0x20) && Stg30_Battle.turns[attacker].turnType == 2) {
            atk += atk / 2;
        }
        if ((flags1 & 0x40) && (Stg30_Battle.statusFlags[attacker] & 1)) {
            atk += atk / 2;
        }
        if ((flags1 & 0x80) && Stg30_Battle.turns[target].turnType == 3) {
            atk += atk / 2;
        }
        if ((flags1 & 0x100) && Stg30_Battle.turns[target].turnType == 2) {
            atk += atk / 2;
        }
        if ((flags1 & 0x200) && (Stg30_Battle.turns[target].turnType == 2 || Stg30_Battle.turns[target].turnType == 3)) {
            atk += atk / 2;
        }
        if ((flags1 & 0x400) && Stg30_Battle.interruptSlot != -1 && Stg30_Battle.turns[attacker].hpDelta > 0) {
            atk += atk / 2;
        }
        power = atk;
        aAtk = a->attack;
        el = Skill_GetSpecialty(tech);
        def = t->defense;
        tEl = Digi_GetSpecialty(t->digiId);
        st = Stg30_Battle.statusFlags[attacker];
        if (st & 0x400) {
            el = 0;
        }
        if (st & 0x800) {
            el = 1;
        }
        if (st & 0x1000) {
            el = 2;
        }
        if (st & 0x2000) {
            el = 3;
        }
        if (st & 0x4000) {
            el = 4;
        }
        if (Stg30_Battle.turns[target].turnType == 5) {
            def = def * 150 / 100;
        }
        switch (Stg30_CompareTypes(type[0], type[1])) {
        case 1:
            aAtk = aAtk * 120 / 100;
            break;
        case -1:
            aAtk = aAtk * 80 / 100;
            break;
        }
        switch (Stg30_CompareSpecialty(el, tEl)) {
        case 1:
            power = power * 120 / 100;
            break;
        case -1:
            power = power * 80 / 100;
            break;
        }
        if (el != 5 && el == Stg30_GetFloorSpecialty()) {
            power = power * 120 / 100;
        }
        if (tEl != 5 && tEl == Stg30_GetFloorSpecialty()) {
            def = def * 120 / 100;
        }
        dmg = aAtk * power / (def * 2);
        if (Stg30_Battle.statusFlags[target] & 1) {
            dmg += 10;
        }
        if (dmg < t->hp) {
            t->hp -= dmg;
        } else {
            t->hp = 0;
        }
        if (flags1 & 0x800) {
            a->hp = (a->hp + dmg > a->maxHp) ? a->maxHp : a->hp + dmg;
            *p5 = 0x13;
        }
        if (attacker != target) {
            if (Stg30_Battle.statusFlags[target] & 0x40) {
                Stg30_Battle.statusFlags[attacker] |= 1;
            }
            if (Stg30_Battle.statusFlags[attacker] & 0x80) {
                Stg30_Battle.statusFlags[target] |= 1;
                *p5 = 1;
            }
            if (Stg30_Battle.statusFlags[attacker] & 0x100) {
                Stg30_Battle.statusFlags[target] |= 2;
                *p5 = 3;
            }
            if ((Stg30_Battle.isBossFight == 0 || target < 3) && (Stg30_Battle.statusFlags[attacker] & 0x200)) {
                Stg30_Battle.statusFlags[target] |= 4;
                *p5 = 5;
            }
        }
    } while (0);
    if ((flags1 & 2) && Stg30_CompareTypes(type[0], type[1]) == -1) {
        hp = t->hp + dmg;
        if (t->maxHp < hp) {
            hp = t->maxHp;
        }
        t->hp = hp;
        *p4 = 1;
    }
    if (flags1 & 0x2000) {
        steal = 100;
        if (t->mp < 100) {
            steal = t->mp;
        }
        t->mp -= steal;
        a->mp = (a->mp + steal > a->maxMp) ? a->maxMp : a->mp + steal;
        *p5 = 0x201;
    }
    if (flags1 & 0x4000) {
        gain = Skill_GetMpCost(Stg30_Battle.turns[target].skillId);
        a->mp = (a->mp + gain > a->maxMp) ? a->maxMp : a->mp + gain;
        *p5 = 0x201;
    }
    if (flags2 & 0x20) {
        drain = (Rand_Next() & 3) + 4;
        t->mp = (t->mp < drain) ? 0 : t->mp - drain;
        *p5 = 0x120;
    }
    if (flags2 & 0x40) {
        drain = (Rand_Next() & 7) + 13;
        t->mp = (t->mp < drain) ? 0 : t->mp - drain;
        *p5 = 0x120;
    }
    if (flags2 & 0x10) {
        if (++Stg30_Battle.killBuildup[target] >= 3) {
            t->hp = 0;
            dmg = 999;
        }
    }
    if (dmg == 0 && revived == 0) {
        *p4 = 4;
    }
    return dmg;
}

s32 Stg30_SkillHitCheck(s32 idx, s16 *tgt, s32 n, s32 id) {
    s32 hp;
    s32 min;
    s32 i;
    s32 v;
    s32 chance;
    s32 t;
    hp = Stg30_Battle.entries[idx].speed;
    min = 0x270F;
    if ((Stg30_Battle.isBossFight != 0) && (idx < 3)) {
        if (id == 0xA8) {
            return 0;
        }
        if (id == 0x3A) {
            return 0;
        }
        if (id == 0x49) {
            return 0;
        }
        if (id == 0x73) {
            return 0;
        }
        if (id == 0xA3) {
            return 0;
        }
    }
    if ((n == 1) && (Stg30_Battle.statusFlags[tgt[0]] & 0x10000)) {
        return 0;
    }
    if (func_8001F0E4(id) & 4) {
        return Stg30_Battle.turns[idx].turnType == 2;
    }
    if (Stg30_Battle.preventFlags[idx] & 0x10) {
        return (Rand_Next() & 3) == 0;
    }
    if (Stg30_Battle.statusFlags[idx] & 2) {
        if (Rand_Next() & 1) {
            return 0;
        }
    }
    if ((n == 1) && (Stg30_Battle.turns[tgt[0]].turnType == 2)) {
        if (func_8001F020(Stg30_Battle.turns[tgt[0]].skillId) & 0x10) {
            if (Rand_Next() & 1) {
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        v = tgt[i];
        t = Stg30_Battle.entries[v].speed;
        v = t;
        if (v >= min) {
            v = min;
        }
        min = v;
    }

    t = func_8001F0E4(id);
    if (t & 8) {
        hp *= 10;
    }
    chance = min << 7;
    chance = chance / (hp * 20);
    return (Rand_Next() & 0x7F) >= chance;
}

void Stg30_BuildSkillScript(s32 idx) {
    s16 kind = 1;
    Stg30Turn *rec = &Stg30_Battle.turns[idx];
    s16 targets[6];
    s32 results[6];
    s16 hitKind[6];
    s16 msg[6];
    s16 *out = Stg30_BattleScript;
    s32 id;
    s32 num;
    s32 i;
    s32 n;
    s32 attr;
    s32 flags;
    s32 cost;
    s16 *mp;

    id = (u16)rec->skillId;
    Stg30_Battle.actionTaken = 1;
    attr = func_8001F020((s16)id);
    if (attr & 1) {
        Stg30_Battle.turns[idx].noCounter = 1;
    }
    if (attr & 2) {
        Stg30_Battle.turns[idx].noInterrupt = 1;
    }
    if (attr & 0x40) {
        Stg30_Battle.entries[idx].defense /= 2;
    }
    for (i = 0; i < 6; i++) {
        results[i] = 0;
        targets[i] = -1;
        hitKind[i] = rec->effectKind;
        msg[i] = 0;
    }
    num = 0;
    switch (rec->target) {
    default:
        if (func_8001F044((s16)id) & 8) {
            if (idx != rec->target) {
                targets[0] = rec->target;
                num = 1;
            }
        } else if (Skill_GetCureFlags((s16)id) & 0x20000) {
            num = 1;
            targets[0] = rec->target;
        } else if (Stg30_Battle.entries[rec->target].hp != 0) {
            targets[0] = rec->target;
            num = 1;
        }
        break;
    case 7:
        switch (hitKind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            for (i = 0, n = 0; i < 3; i++) {
                if (Stg30_Battle.entries[i].hp != 0) {
                    targets[n++] = i;
                }
            }
            num = n;
            break;
        case 3:
            for (i = 0, n = 0; i < 3; i++) {
                if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp == 0) {
                    targets[n++] = i;
                }
            }
            num = n;
            break;
        }
        kind = 0;
        break;
    case 8:
        switch (hitKind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            n = 0;
            for (i = 3; i < 6; i++) {
                if (Stg30_Battle.entries[i].hp != 0) {
                    targets[n++] = i;
                }
            }
            num = n;
            break;
        case 3:
            n = 0;
            for (i = 3; i < 6; i++) {
                if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp == 0) {
                    targets[n++] = i;
                }
            }
            num = n;
            break;
        }
        kind = 1;
        break;
    case 9:
        switch (hitKind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            n = 0;
            for (i = 0; i < 6; i++) {
                if (Stg30_Battle.entries[i].hp != 0) {
                    targets[n++] = i;
                }
            }
            num = n;
            break;
        case 3:
            n = 0;
            for (i = 0; i < 6; i++) {
                if (Stg30_Battle.entries[i].digiId != 0 && Stg30_Battle.entries[i].hp == 0) {
                    targets[n++] = i;
                }
            }
            num = n;
            break;
        }
        kind = 2;
        break;
    }
    if (num == 0 || (rec->effectKind == 0 && Stg30_SkillHitCheck(idx, targets, num, (s16)id) == 0)) {
        D_80074074 = 0;
    }
    if (Stg30_Battle.actionTaken != 0) {
        if (rec->turnType == 3) {
            flags = func_8001F180((s16)id);
            if (flags & 1) {
                if (Stg30_Battle.isBossFight == 0 || idx >= 3) {
                    if (Rand_Next() & 7) {
                        Stg30_TurnOrderRemove(1);
                    }
                }
            }
            if (flags & 4) {
                s32 slot = Stg30_TurnOrderGet(1);

                if (slot != -1) {
                    Stg30_Battle.entries[slot].attack = Stg30_Battle.entries[slot].attack * 38 / 128;
                    msg[0] = 0x111;
                }
            }
            if (flags & 8) {
                s32 slot = Stg30_TurnOrderGet(1);

                if (slot != -1) {
                    Stg30_Battle.entries[slot].attack = Stg30_Battle.entries[slot].attack * 77 / 128;
                    msg[0] = 0x111;
                }
            }
            if (flags & 0x10) {
                s32 slot = Stg30_TurnOrderGet(1);

                if (slot != -1) {
                    Stg30_Battle.preventFlags[slot] = 0x10;
                }
            }
            if (flags & 0x40) {
                s32 slot = Stg30_TurnOrderGet(1);

                if (slot != -1) {
                    Stg30_TurnOrderRemove(1);
                    Stg30_TurnOrderInsert(Stg30_TurnOrderFreeIndex(), slot);
                }
            }
        }
        if ((s16)id == 0xF1 || (s16)id == 0xF4) {
            Stg30_Battle.statusMsg = 0x11E;
        } else if ((s16)id == 0xDD) {
            Stg30_Battle.statusMsg = 0x202;
        }
        for (i = 0; i < num; i++) {
            results[i] = Stg30_ApplySkillDamage(idx, targets[i], (s16)id, &hitKind[i], &msg[i]);
        }
        *out++ = 2;
        *out++ = idx + 0xA;
        *out++ = 3;
        *out++ = idx;
        *out++ = 0x15;
        *out++ = 0xE;
        *out++ = Stg30_Battle.turns[idx].turnType - 1;
        *out++ = 1;
        if (Stg30_Battle.turns[idx].noInterrupt == 0 && Stg30_Battle.interruptSlot == -1 && rec->turnType != 2) {
            if (idx >= 3) {
                if (Stg30_Battle.turns[0].turnType == 3 || Stg30_Battle.turns[1].turnType == 3 ||
                    Stg30_Battle.turns[2].turnType == 3) {
                    *out++ = 0;
                    *out++ = 0x3C;
                    *out++ = 0x13;
                }
            } else if (Stg30_Battle.turns[3].turnType == 3 || Stg30_Battle.turns[4].turnType == 3 ||
                       Stg30_Battle.turns[5].turnType == 3) {
                *out++ = 0;
                *out++ = 0x3C;
                *out++ = 0x14;
            }
        }
        *out++ = 0x16;
        *out++ = 0xF;
        *out++ = id;
        *out++ = 0x17;
        *out++ = id;
        *out++ = num;
        *out++ = 9;
        *out++ = idx;
        *out++ = id;
        *out++ = 0;
        *out++ = 0x96;
        *out++ = 7;
        *out++ = idx;
        for (i = 0; i < num; i++) {
            *out++ = 2;
            *out++ = targets[i] + 0x10;
            *out++ = 3;
            *out++ = targets[i];
            *out++ = 0;
            *out++ = (i == 0) ? 0x1E : 0xC;
            *out++ = 0x10;
            *out++ = results[i];
            *out++ = (hitKind[i] < 3) ? hitKind[i] + 1 : 8;
            *out++ = msg[i];
            switch (hitKind[i]) {
            case 0:
                if (Stg30_Battle.entries[targets[i]].hp != 0) {
                    *out++ = (Stg30_Battle.turns[targets[i]].turnType != 5) ? 0xB : 0xA;
                } else {
                    *out++ = 0xC;
                }
                break;
            case 3:
                *out++ = 8;
                break;
            case 1:
            case 2:
            case 4:
                *out++ = 0xD;
                break;
            }
            *out++ = targets[i];
            *out++ = id;
            if (num == 1) {
                if (hitKind[i] == 0) {
                    *out++ = num;
                    *out++ = targets[i];
                    *out++ = 0;
                    *out++ = 0x1E;
                } else if (hitKind[i] >= 0) {
                    if (hitKind[i] < 5) {
                        *out++ = 0;
                        *out++ = 0x78;
                    }
                }
            } else {
                *out++ = 0;
                *out++ = 0x3C;
            }
        }
        if (num != 1) {
            *out++ = 2;
            *out++ = kind + 0x16;
            *out++ = kind + 4;
            *out++ = 0;
            *out++ = 0xB4;
        }
    } else {
        *out++ = 2;
        *out++ = idx + 0xA;
        *out++ = 3;
        *out++ = idx;
        *out++ = 0xE;
        *out++ = 0;
        *out++ = 0;
        *out++ = 0;
        *out++ = 0xB4;
    }
    *out = 0x18;
    if (Stg30_Battle.actionTaken == 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        s32 tgt = targets[i];

        Stg30_Battle.lastTargets[i] = tgt;
        if (tgt != -1) {
            Stg30_Battle.turns[tgt].hpDelta = results[i];
        }
    }
    cost = Skill_GetMpCost((s16)id);
    if (rec->turnType == 2 && (func_8001F0E4((s16)id) & 0x1000)) {
        mp = &Stg30_Battle.entries[targets[0]].mp;
    } else {
        mp = &Stg30_Battle.entries[idx].mp;
    }
    *mp -= cost;
    if (*mp < 0) {
        *mp = 0;
    }
    do {
        if ((s16)id == 0x4D || (s16)id == 0xFB) {
            if (Stg30_Battle.entries[targets[0]].hp == 0) {
                Stg30_Battle.turns[idx].skillId = 0xFB;
                if (idx < 3) {
                    Stg30_Battle.turns[idx].target = Stg30_PickTarget(0x4D, 1, idx);
                } else {
                    Stg30_Battle.turns[idx].target = Stg30_PickTarget(0x4D, 7, idx);
                }
                if (Stg30_Battle.turns[idx].target != idx) {
                    Stg30_TurnOrderInsert(1, idx);
                }
                break;
            }
        }
        if ((s16)id == 0x68 && Skill_GetMpCost(0x68) <= Stg30_Battle.entries[idx].mp) {
            if (idx < 3) {
                Stg30_Battle.turns[idx].target = Stg30_PickTarget(0x4D, 1, idx);
            } else {
                Stg30_Battle.turns[idx].target = Stg30_PickTarget(0x4D, 7, idx);
            }
            if (Stg30_Battle.turns[idx].target != idx) {
                Stg30_TurnOrderInsert(1, idx);
            }
            break;
        }
        if ((s16)id == 0xDC) {
            if (Stg30_RepeatSkillCount == 0) {
                Stg30_RepeatSkillCount = (u16)((u16)Rand_Next() % 3) + 1;
            }
            if (--Stg30_RepeatSkillCount != 0) {
                if (Skill_GetMpCost(0xDC) <= Stg30_Battle.entries[idx].mp) {
                    if (idx < 3) {
                        Stg30_Battle.turns[idx].target = Stg30_PickTarget(0x4D, 1, idx);
                    } else {
                        Stg30_Battle.turns[idx].target = Stg30_PickTarget(0x4D, 7, idx);
                    }
                    if (Stg30_Battle.turns[idx].target != idx) {
                        Stg30_TurnOrderInsert(1, idx);
                    }
                } else {
                    Stg30_RepeatSkillCount = 0;
                }
            }
        }
    } while (0);
}
