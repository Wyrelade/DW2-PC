#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"
#include "stag3000/stag3000_6A88_funcs.h"
#include "stag3000/stag3000_96DC_funcs.h"

s32 func_8006D2EC(s32 idx, s32 id, s32 lvl) {
    s32 k = (lvl + 1) * 20;
    s32 pow = Skill_GetPower(id);
    s32 el = Skill_GetSpecialty(id);
    s32 def = D_80073CC0.entries[idx].field_36;
    s32 el2 = Digi_GetSpecialty(D_80073CC0.entries[idx].field_19);
    s32 r;

    if (D_80073CC0.field_2AC[idx].field_0 == 5) {
        def = def * 192 / 128;
    }
    switch (func_8006A030(el, el2)) {
    case 1:
        pow = pow * 154 / 128;
        break;
    case -1:
        pow = pow * 102 / 128;
        break;
    }
    if (el == func_8006A118()) {
        pow = pow * 154 / 128;
    }
    if (el2 != 5 && el2 == func_8006A118()) {
        def = def * 154 / 128;
    }
    r = k * pow / (def * 2);
    if (D_80073CC0.field_31C[idx] & 1) {
        r += 10;
    }
    return r;
}

s32 func_8006D4D8(s32 target, s32 tech, s16 *p3, s16 *p4) {
    Stg30DigiS *d = &D_80073CD8[target];
    s32 *st = &((Stg30CombatCD8 *)D_80073CD8)->status[target];
    s32 type = Digi_GetType(d->digiId);
    s32 dmg;

    switch (tech) {
    case 0xFD:
    case 0x100:
    case 0x107:
    case 0x10A:
        dmg = 40;
        break;
    case 0xFE:
    case 0x101:
    case 0x108:
    case 0x10B:
        dmg = 80;
        break;
    case 0xFF:
    case 0x102:
    case 0x109:
    case 0x10C:
        dmg = 160;
        break;
    case 0x10F:
        if (type == 0) {
            dmg = d->maxHp - d->hp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x110:
        if (type == 0) {
            dmg = d->maxMp - d->mp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x112:
        if (type == 1) {
            dmg = d->maxHp - d->hp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x113:
        if (type == 1) {
            dmg = d->maxMp - d->mp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x115:
        if (type == 2) {
            dmg = d->maxHp - d->hp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x116:
        if (type == 2) {
            dmg = d->maxMp - d->mp;
        } else {
            dmg = 0;
            *p3 = 4;
        }
        break;
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12A:
    case 0x12B:
    case 0x12C:
    case 0x12D:
        dmg = func_8006D2EC(target, tech, D_8005E65E - 0x60);
        break;
    default:
        dmg = 0;
        break;
    }
    switch (tech) {
    case 0xFD:
    case 0xFE:
    case 0xFF:
    case 0x107:
    case 0x108:
    case 0x109:
    case 0x10F:
    case 0x112:
    case 0x115:
        d->hp += dmg;
        if (d->maxHp < d->hp) {
            d->hp = d->maxHp;
        }
        break;
    case 0x100:
    case 0x101:
    case 0x102:
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x110:
    case 0x113:
    case 0x116:
        d->mp += dmg;
        if (d->maxMp < d->mp) {
            d->mp = d->maxMp;
        }
        break;
    case 0x103:
        *p3 = 4;
        *p4 = 2;
        *st &= ~1;
        break;
    case 0x104:
        *p3 = 4;
        *p4 = 4;
        *st &= ~2;
        break;
    case 0x105:
        *p3 = 4;
        *p4 = 6;
        *st &= ~4;
        break;
    case 0x106:
    case 0x10D:
        *p3 = 4;
        *p4 = 0x10F;
        *st = 0;
        break;
    case 0x10E:
        *p3 = 4;
        *p4 = 0x204;
        d->hp = d->maxHp;
        d->mp = d->maxMp;
        break;
    case 0x111:
        if (type == 0) {
            d->hp = d->maxHp;
            *p4 = 0x18;
        } else {
            *p3 = 4;
        }
        break;
    case 0x114:
        if (type == 1) {
            d->hp = d->maxHp;
            *p4 = 0x18;
        } else {
            *p3 = 4;
        }
        break;
    case 0x117:
        if (type == 2) {
            d->hp = d->maxHp;
            *p4 = 0x18;
        } else {
            *p3 = 4;
        }
        break;
    case 0x118:
        if (type == 0) {
            d->defense = d->defense * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x16;
        }
        *p3 = 4;
        break;
    case 0x119:
        if (type == 0) {
            d->defense = d->defense * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 0xA;
        }
        *p3 = 4;
        break;
    case 0x11A:
        if (type == 0) {
            d->attack = d->attack * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x15;
        }
        *p3 = 4;
        break;
    case 0x11B:
        if (type == 0) {
            d->attack = d->attack * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 9;
        }
        *p3 = 4;
        break;
    case 0x11C:
        if (type == 1) {
            d->defense = d->defense * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x16;
        }
        *p3 = 4;
        break;
    case 0x11D:
        if (type == 1) {
            d->defense = d->defense * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 0xA;
        }
        *p3 = 4;
        break;
    case 0x11E:
        if (type == 1) {
            d->attack = d->attack * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x15;
        }
        *p3 = 4;
        break;
    case 0x11F:
        if (type == 1) {
            d->attack = d->attack * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 9;
        }
        *p3 = 4;
        break;
    case 0x120:
        if (type == 2) {
            d->defense = d->defense * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x16;
        }
        *p3 = 4;
        break;
    case 0x121:
        if (type == 2) {
            d->defense = d->defense * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 0xA;
        }
        *p3 = 4;
        break;
    case 0x122:
        if (type == 2) {
            d->attack = d->attack * 120 / 100;
            D_80073CC0.field_346[target] = 1;
            *p4 = 0x15;
        }
        *p3 = 4;
        break;
    case 0x123:
        if (type == 2) {
            d->attack = d->attack * 80 / 100;
            D_80073CC0.field_340[target] = 1;
            *p4 = 9;
        }
        *p3 = 4;
        break;
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12A:
    case 0x12B:
    case 0x12C:
    case 0x12D:
        d->hp = (d->hp < dmg) ? 0 : d->hp - dmg;
        break;
    }
    return dmg;
}

void func_8006DB90(void) {
    s16 tgt[8];
    s32 res[6];
    s16 kind[8];
    s16 z[8];
    Stg30Sub10 *act;
    s16 *out;
    s32 i;
    s32 n;
    s32 mode;
    s32 cnt;
    s16 tech;

    act = &D_80073CC0.field_2AC[6];
    tech = act->field_6;
    mode = 1;
    out = D_80073890;
    for (i = 0; i < Item_GetBagCapacity(); i++) {
        if (((Stg30GameIds *)&Save_GameState)->field_66[i] == D_80073CC0.field_3AC) {
            ((Stg30GameIds *)&Save_GameState)->field_66[i] = 0;
            Item_SortList();
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        res[i] = 0;
        tgt[i] = -1;
        kind[i] = act->field_8;
        z[i] = 0;
    }
    switch (act->field_4) {
    default:
        tgt[0] = act->field_4;
        n = 1;
        break;
    case 7:
        switch (kind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            i = 0;
            cnt = 0;
            for (; i < 3; i++) {
                if (D_80073CC0.entries[i].field_2E != 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        case 3:
            i = 0;
            cnt = 0;
            for (; i < 3; i++) {
                if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        }
        mode = 0;
        break;
    case 8:
        switch (kind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            cnt = 0;
            for (i = 3; i < 6; i++) {
                if (D_80073CC0.entries[i].field_2E != 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        case 3:
            cnt = 0;
            for (i = 3; i < 6; i++) {
                if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        }
        mode = 1;
        break;
    case 9:
        switch (kind[0]) {
        case 0:
        case 1:
        case 2:
        default:
            cnt = 0;
            for (i = 0; i < 6; i++) {
                if (D_80073CC0.entries[i].field_2E != 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        case 3:
            cnt = 0;
            for (i = 0; i < 6; i++) {
                if (D_80073CC0.entries[i].field_19 != 0 && D_80073CC0.entries[i].field_2E == 0) {
                    tgt[cnt++] = i;
                }
            }
            n = cnt;
            break;
        }
        mode = 2;
        break;
    }
    for (i = 0; i < n; i++) {
        kind[i] = act->field_8;
        res[i] = func_8006D4D8(tgt[i], tech, &kind[i], &z[i]);
    }
    *out++ = 2;
    *out++ = tgt[0] + 10;
    *out++ = 3;
    *out++ = tgt[0];
    *out++ = 9;
    *out++ = 6;
    *out++ = tech;
    *out++ = 0x15;
    *out++ = 0x16;
    *out++ = 0x11;
    *out++ = D_80073CC0.field_3B2;
    *out++ = 0x12;
    *out++ = 0x17;
    *out++ = tech;
    *out++ = n;
    *out++ = 0;
    *out++ = 0x96;
    for (i = 0; i < n; i++) {
        *out++ = 2;
        *out++ = tgt[i] + 0x10;
        *out++ = 3;
        *out++ = tgt[i];
        *out++ = 0;
        *out++ = (i == 0) ? 0x1E : 0xC;
        *out++ = 0x10;
        *out++ = res[i];
        *out++ = (kind[i] < 3) ? act->field_8 + 1 : 8;
        *out++ = z[i];
        switch (kind[i]) {
        case 0:
            if (D_80073CC0.entries[tgt[i]].field_2E != 0) {
                *out++ = (D_80073CC0.field_2AC[tgt[i]].field_0 != 5) ? 11 : 10;
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
        *out++ = tgt[i];
        *out++ = tech;
        if (n == 1) {
            if (kind[i] == 0) {
                *out++ = n;
                *out++ = tgt[i];
                *out++ = 0;
                *out++ = 0x1E;
            } else if (kind[i] >= 0) {
                if (kind[i] < 5) {
                    *out++ = 0;
                    *out++ = 0x78;
                }
            }
        } else {
            *out++ = 0;
            *out++ = 0x3C;
        }
    }
    if (n != 1) {
        *out++ = 2;
        *out++ = mode + 0x16;
        *out++ = mode + 4;
        *out++ = 0;
        *out++ = 0xB4;
    }
    *out = 0x18;
    for (i = 0; i < 6; i++) {
        D_80073CC0.field_3B8[i] = tgt[i];
    }
}
