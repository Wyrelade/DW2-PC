#include "common.h"
#include "main/game.h"
#include "main/task.h"
#include "main/cdpreload.h"
#include "main/portrait.h"
#include "main/faceslot.h"
#include "main/itemeffect.h"
#include "main/nameentry.h"
#include "main/gamemode.h"
#include "main/topmenu.h"
#include "main/submenu.h"
#include "main/status.h"
#include "main/itemuse.h"
#include "main/itemmenu.h"
#include "main/77DC.h"

/* Small data this unit defines (.sbss in game.h's order). Retail reaches the first two
 * with %gp_rel here; D_80050780 is only used by overlays. */
s32 Skill_ShotXaFile;
s32 D_8005077C;
s32 D_80050780;

EntED40 *Skill_FindById(s32 id) {
    EntED40 *p = (EntED40 *)Cd_GetFileEntry(0x25B0000);

    do {
        if (p->u0.id == id) {
            return p;
        }
    } while ((p++)->u0.id != 0);
    return 0;
}

s32 Skill_GetNameText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    EntED40 *p = Skill_FindById(arg0);
    if (p != 0) {
        return p->nameOffset + base;
    }
    return 0;
}

s32 Skill_GetDescText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    return Skill_FindById(arg0)->descOffset + base;
}

s32 Skill_GetCastAnim(s32 id) {
    return Skill_FindById(id)->u0.h0.field_2 & 3;
}

s32 Skill_GetType(s32 id) {
    return (Skill_FindById(id)->u0.field_0 >> 18) & 3;
}

s32 Skill_GetPartsEntry(s32 id) {
    return Skill_FindById(id)->partsEntry;
}

u8 Skill_GetMpCost(s32 id) {
    return Skill_FindById(id)->mpCost;
}

void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b) {
    EntED40 *p = Skill_FindById(id);
    s32 i;

    n *= 2;
    for (i = 0; i < 3; i++) {
        a[i] = p->field_2C[n][i];
        b[i] = p->field_2C[n + 1][i];
    }
}

s32 Skill_GetTarget(s32 id) {
    return (Skill_FindById(id)->u0.field_0 >> 20) & 0xF;
}

s16 Skill_GetPower(s32 id) {
    return Skill_FindById(id)->power;
}

u16 Skill_GetSpecialty(s32 id) {
    u16 v = Skill_FindById(id)->u0.b0.field_3 & 0xF;

    if (v == 6) {
        return (u16)Rand_Next() % 5;
    }
    return v;
}

s32 *Skill_GetShotXa(s32 id) {
    EntED40 *e = Skill_FindById(id);
    Skill_ShotXaFile = e->shotXaFile;
    D_8005077C = e->field_5;
    return &Skill_ShotXaFile;
}

/* Unnamed: WAZADATA byte 0x10 bit set (8/0x10/0x20/1/2 tested for different battle effects), no
 * single meaning. */
u8 func_8001F020(s32 id) {
    return Skill_FindById(id)->u10.field_10b;
}

/* Unnamed: WAZADATA field_20 low nibble, bit 8 retargets in battle target selection; other bits
 * unproven. */
s32 func_8001F044(s32 id) {
    return Skill_FindById(id)->field_20 & 0xF;
}

s32 Skill_GetStatusFlags(s32 id) {
    return Skill_FindById(id)->statusFlags & 0x3FFFFFF;
}

s32 Skill_GetCureFlags(s32 id) {
    return Skill_FindById(id)->field_1C & 0x3FFFF;
}

s32 Skill_GetRank(s32 id) {
    return Skill_FindById(id)->u0.field_0 >> 28;
}

/* Unnamed: WAZADATA (field_10>>8)&0x7FFF mixed effect flag set (bits 4, 0x2000 tested), no
 * single meaning. */
s32 func_8001F0E4(s32 id) {
    return (Skill_FindById(id)->u10.field_10 >> 8) & 0x7FFF;
}

/* Unnamed: WAZADATA field_14 &0x3FF effect flags read once in battle damage calc, meaning
 * unproven. */
s32 func_8001F10C(s32 id) {
    return Skill_FindById(id)->field_14 & 0x3FF;
}

s32 Skill_GetBuffFlags(s32 id) {
    return (Skill_FindById(id)->field_14 >> 10) & 0x1FFF;
}

/* Unnamed: WAZADATA (field_1C>>18)&0x1F flags read once in battle damage calc, meaning unproven
 * (issue #4 calls it "prevent", unconfirmed). */
s32 func_8001F158(s32 id) {
    return (Skill_FindById(id)->field_1C >> 18) & 0x1F;
}

/* Unnamed: WAZADATA (field_1C>>23)&0xFF flags read once in battle turn code, meaning unproven. */
s32 func_8001F180(s32 id) {
    return (Skill_FindById(id)->field_1C >> 23) & 0xFF;
}
