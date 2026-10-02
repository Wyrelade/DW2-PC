#include "common.h"
#include "stag3000/stag3000.h"
#include "stag3000/stag3000_funcs.h"
#include "stag3000/stag3000_100C_funcs.h"
#include "stag3000/stag3000_41D0_funcs.h"
#include "stag3000/stag3000_5980_funcs.h"

void func_80069DE8(void) {
    s32 idx = func_8006E674(0);
    Stg30Rec73F6C *e = &D_80073F6C[idx];
    s32 fl = func_8001F044(e->field_6);
    s32 lo;
    s32 n;
    s32 i;
    s32 t;
    s32 cnt;
    s32 max;
    s32 best;
    s32 list[6];
    s32 k;

    if ((fl & 2) && e->field_0 != 2) {
        lo = 0;
        n = 3;
        switch (e->field_4) {
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
            if (D_80073CC0.entries[t].field_2E != 0) {
                break;
            }
        }
        if (i == 100) {
            t = idx;
        }
        e->field_4 = t;
    }
    if ((fl & 4) && e->field_0 == 2) {
        e->field_4 = idx < 3 ? 8 : 7;
    }
    if (fl & 8) {
        best = idx;
        cnt = 0;
        for (k = 0; k < 6; k++) {
            if (D_80073CC0.entries[k].field_19 != 0 && D_80073CC0.entries[k].field_2E == 0) {
                list[cnt++] = k;
            }
        }
        max = 0;
        for (k = 0; k < cnt; k++) {
            if (max < D_80073CC0.entries[list[k]].field_32) {
                max = D_80073CC0.entries[list[k]].field_32;
                best = list[k];
            }
        }
        e->field_4 = best;
    }
}

s32 func_8006A030(s32 a, s32 b) {
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

s32 func_8006A118(void) {
    if (D_8005D5A0.field_103D == 0) {
        return 5;
    }
    return D_8005D5A0.field_103D - 2;
}

s32 func_8006A140(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5) {
    s32 revived;
    s32 flags;
    u32 already;
    s32 cure;
    s32 i;
    s32 old;
    s32 mask;
    s32 hit;

    revived = 0;
    flags = func_8001F068(tech);
    already = D_80073CC0.field_31C[target] & 1;
    if (flags & 1) {
        if ((u16)((u16)Rand_Next() % 3) == 0) {
            D_80073CC0.field_31C[target] |= 1;
        }
    }
    if (flags & 2) {
        if ((u16)((u16)Rand_Next() % 3) != 0) {
            D_80073CC0.field_31C[target] |= 1;
        }
    }
    if (flags & 4) {
        if (D_80073CC0.field_2AC[attacker].field_0 == 2) {
            D_80073CC0.field_31C[target] |= 1;
        }
    }
    if (!already) {
        if (D_80073CC0.field_31C[target] & 1) {
            *p5 = 1;
        }
    }
    already = (u32)D_80073CC0.field_31C[target] >> 1;
    already &= 1;
    if (flags & 0x10) {
        if ((u16)((u16)Rand_Next() % 3) == 0) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (flags & 0x20) {
        if ((u16)((u16)Rand_Next() % 3) != 0) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (flags & 0x40) {
        if (D_80073CC0.field_2AC[attacker].field_0 == 2) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (flags & 0x80) {
        if (D_80073CC0.field_2AC[attacker].field_0 == 3) {
            D_80073CC0.field_31C[target] |= 2;
        }
    }
    if (!already) {
        if (D_80073CC0.field_31C[target] & 2) {
            *p5 = 3;
        }
    }
    if (D_80073CC0.field_3DC == 0 || target < 3) {
        already = (u32)D_80073CC0.field_31C[target] >> 2;
    already &= 1;
        if (flags & 0x100) {
            if ((u16)((u16)Rand_Next() % 3) == 0) {
                D_80073CC0.field_31C[target] |= 4;
            }
        }
        if (flags & 0x200) {
            if ((u16)((u16)Rand_Next() % 3) != 0) {
                D_80073CC0.field_31C[target] |= 4;
            }
        }
        if (flags & 0x400) {
            if (D_80073CC0.field_2AC[attacker].field_0 == 2) {
                D_80073CC0.field_31C[target] |= 4;
            }
        }
        if (!already) {
            if (D_80073CC0.field_31C[target] & 4) {
                *p5 = 5;
            }
        }
    }
    if (flags & 0x1000000) {
        if (D_80073CC0.entries[target].field_2E == 0) {
            D_80073CC0.field_31C[target] |= 0x8000;
            D_80073CC0.entries[target].field_2E = 1;
            D_80073CC0.field_34F[target] |= 0xA;
            *p4 = 3;
            *p5 = 0x119;
        }
    }
    if (flags & 0x1000) {
        D_80073CC0.field_31C[target] |= 8;
        *p5 = 0xC;
    }
    if (flags & 0x4000) {
        D_80073CC0.field_31C[target] |= 0x20;
    }
    if (flags & 0x8000) {
        D_80073CC0.field_31C[target] |= 0x40;
        *p5 = 0x10B;
    }
    if (flags & 0x10000) {
        D_80073CC0.field_31C[target] |= 0x80;
        *p5 = 0x1B;
    }
    if (flags & 0x20000) {
        D_80073CC0.field_31C[target] |= 0x800;
        *p5 = 0x103;
    }
    if (flags & 0x40000) {
        D_80073CC0.field_31C[target] |= 0x400;
        *p5 = 0x101;
    }
    if (flags & 0x80000) {
        D_80073CC0.field_31C[target] |= 0x100;
        *p5 = 0x1D;
    }
    if (flags & 0x100000) {
        D_80073CC0.field_31C[target] |= 0x200;
        *p5 = 0x1F;
    }
    if (flags & 0x200000) {
        D_80073CC0.field_31C[target] |= 0x1000;
        *p5 = 0x105;
    }
    if (flags & 0x400000) {
        D_80073CC0.field_31C[target] |= 0x2000;
        *p5 = 0x107;
    }
    if (flags & 0x800000) {
        D_80073CC0.field_31C[target] |= 0x4000;
        *p5 = 0x109;
    }
    if (flags & 0x2000000) {
        D_80073CC0.field_31C[target] |= 0x10000;
        *p5 = 0x10C;
    }
    if (!(D_80073CC0.field_34F[target] & 4)) {
        flags = func_8001F094(tech);
        if (flags & 0x20000) {
            revived = 1;
            D_80073CC0.entries[target].field_2E = D_80073CC0.entries[target].field_2C;
            *p4 = 3;
            *p5 = 0x18;
        }
        for (cure = 1, i = 0; i < 17; cure <<= 1, i++) {
            old = D_80073CC0.field_31C[target];
            mask = D_80073210[i];
            hit = old & mask;
            if (flags & cure) {
                D_80073CC0.field_31C[target] = old & ~mask;
                if (hit) {
                    *p5 = D_80073254[i];
                }
            }
        }
    }
    return revived;
}

void func_8006A968(s16 *max, s16 *b, s16 *c) {
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

void func_8006AA18(s16 *max, s16 *b, s16 *c) {
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

INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000_6A88", func_8006AAA8);

s32 func_8006B950(s32 idx, s16 *tgt, s32 n, s32 id) {
    s32 hp;
    s32 min;
    s32 i;
    s32 v;
    s32 chance;
    s32 t;
    hp = D_80073CC0.entries[idx].field_38;
    min = 0x270F;
    if ((D_80073CC0.field_3DC != 0) && (idx < 3)) {
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
    if ((n == 1) && (D_80073CC0.field_31C[tgt[0]] & 0x10000)) {
        return 0;
    }
    if (func_8001F0E4(id) & 4) {
        return D_80073CC0.field_2AC[idx].field_0 == 2;
    }
    if (D_80073CC0.field_34F[idx] & 0x10) {
        return (Rand_Next() & 3) == 0;
    }
    if (D_80073CC0.field_31C[idx] & 2) {
        if (Rand_Next() & 1) {
            return 0;
        }
    }
    if ((n == 1) && (D_80073CC0.field_2AC[tgt[0]].field_0 == 2)) {
        if (func_8001F020(D_80073CC0.field_2AC[tgt[0]].field_6) & 0x10) {
            if (Rand_Next() & 1) {
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        v = tgt[i];
        t = D_80073CC0.entries[v].field_38;
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

INCLUDE_RODATA("asm/USA/stag3000/rodata", jtbl_80063568);
INCLUDE_ASM("asm/USA/stag3000/nonmatchings/stag3000_6A88", func_8006BBD8);
