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
#include "main/digilist.h"
#include "main/digistatus.h"
#include "main/skilllist.h"
#include "main/spawnlist.h"
#include "main/winframe.h"
#include "main/sound.h"
#include "main/text.h"
#include "main/gpu.h"
#include "main/fade.h"
#include "main/ot.h"
#include "main/primbuf.h"
#include "main/texslot.h"
#include "main/parts.h"
#include "main/digibase.h"

u8 Digi_GetEvolutionTarget(s32 id, s32 val) {
    DigiBaseData *e = Digi_FindBaseData(id);
    s32 i;

    if (e->rangeValues[0] == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (e->rangeBounds[i + 1] == 0) {
            break;
        }
        if (val >= e->rangeBounds[i] && val < e->rangeBounds[i + 1]) {
            break;
        }
    }
    return e->rangeValues[i];
}

Ent1DB18 *Enemy_FindSetById(s32 id) {
    Rec1DB18 *p = (Rec1DB18 *)Cd_GetFileOrNull(0xC6F);

    while (1) {
        if (p->id == 0) {
            break;
        }
        if (p->id == id) {
            return (Ent1DB18 *)p;
        }
        p++;
    }
    return 0;
}

void Enemy_GetSetSummary(void *a0, Out1DB68 *out) {
    Ent1DB18 *src = Enemy_FindSetById(a0);
    Ent1DB18 *p;
    s32 i;
    out->mapDigiId = src->u0.h.mapDigiId;
    out->aiType = ((s32)src->u0.field_0 << 20) >> 28;
    out->paceType = ((s32)src->u0.field_0 << 16) >> 28;
    out->likedGift = src->u4.likedGift;
    out->useDungeonBgm = (src->u4.field_4 >> 8) & 0xF;
    out->isBossFight = (src->u4.field_4 >> 12) & 0xF;
    p = src;
    out->pointsPerLevel = p->u4.h.pointsPerLevel;
    {
        DigiInitRow *row = (DigiInitRow *)p;
        for (i = 0; i < 3; i++) {
            out->digiIds[i] = row[i].digiId;
            out->levels[i] = row[i].level;
        }
    }
}

void Digi_InitFromTable(s32 a0, s32 a1, DigiRosterEntry *e) {
    DigiInitRow *r = (DigiInitRow *)Enemy_FindSetById(a0);
    u8 *name;
    s32 i;

    if ((Sys_State.gameMode & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    Mem_Zero(e, 0x5C);
    e->state = 2;
    {
        DigiInitRow *row = &r[a1];
        e->digiId = row->digiId;
        e->hp = e->maxHp = row->hp;
        e->mp = e->maxMp = row->mp;
    }
    name = Digi_GetDefaultName(e->digiId);
    for (i = 0; i < 14; i++) {
        e->name[i] = name[i];
    }
    {
        DigiInitRow *row = &r[a1];
        e->level = row->level;
        e->attack = row->attack;
        e->defense = row->defense;
        e->speed = row->speed;
        e->skills[0] = row->skill0;
        e->skills[1] = row->skill1;
        e->skills[2] = row->skill2;
    }
    e->maxLevel = Digi_CalcMaxLevel(e->level);
    if (e->level == 1) {
        e->exp = 0;
    } else {
        e->exp = Digi_GetExpToNextLevel(e->level - 1, 100, 0);
    }
}

void Enemy_InitRosterEntry(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o) {
    Tbl1DDA8 *t = (Tbl1DDA8 *)Enemy_FindSetById(a0);
    u8 *name;
    s32 i;

    if ((Sys_State.gameMode & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    e->state = a1 + 3;
    e->digiId = t->rows[a1].digiId;
    e->hp = e->maxHp = t->rows[a1].hp;
    e->mp = e->maxMp = t->rows[a1].mp;
    if (e->digiId != 0) {
        name = Digi_GetDefaultName(e->digiId);
        for (i = 0; i < 14; i++) {
            e->name[i] = name[i];
        }
        e->level = t->rows[a1].level;
        e->exp = t->rows[a1].exp;
        e->attack = t->rows[a1].attack;
        e->defense = t->rows[a1].defense;
        e->speed = t->rows[a1].speed;
        e->skills[0] = t->rows[a1].attr0;
        e->skills[1] = t->rows[a1].attr1;
        e->skills[2] = t->rows[a1].attr2;
        for (i = 3; i < 12; i++) {
            e->skills[i] = 0;
        }
        o->skill0 = t->rows[a1].attr0;
        o->skill1 = t->rows[a1].attr1;
        o->skill2 = t->rows[a1].attr2;
        o->actionKinds[0] = t->rows[a1].aiRules[0][1];
        o->actionKinds[1] = t->rows[a1].aiRules[1][1];
        o->actionKinds[2] = t->rows[a1].aiRules[2][1];
        o->actionKinds[3] = t->rows[a1].aiRules[3][1];
        o->bits = t->rows[a1].bits;
        o->targetModes[0] = t->rows[a1].aiRules[0][2];
        o->targetModes[1] = t->rows[a1].aiRules[1][2];
        o->targetModes[2] = t->rows[a1].aiRules[2][2];
        o->targetModes[3] = t->rows[a1].aiRules[3][2];
        o->conditions[0] = t->rows[a1].aiRules[0][0];
        o->conditions[1] = t->rows[a1].aiRules[1][0];
        o->conditions[2] = t->rows[a1].aiRules[2][0];
        o->conditions[3] = t->rows[a1].aiRules[3][0];
    }
}

ItemTableEntry *Item_FindById(arg0)
s32 arg0;
{
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    while (*p != 0) {
        if (*p == arg0) {
            return (ItemTableEntry *)p;
        }
        p = (s16 *)((u8 *)p + 0x10);
    }
    return 0;
}

s32 Item_GetNameText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->nameOffset + base;
}

s32 Item_GetDescText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->descOffset + base;
}

s32 Item_GetCategory(s32 id) {
    return Item_FindById(id)->u0.b0.category;
}

s32 Item_GetLevel(s32 itemId) {
    return Item_FindById(itemId)->u0.b0.field_3 & 0xF;
}

s32 Item_CheckId(s32 itemId) {
    return Item_FindById(itemId) != 0 ? 0 : -1;
}

s32 func_8001E134(void) {
    return Item_FindById()->u0.field_0 >> 30;
}

/* Unnamed: ITEMDATA word0 bits 28-29, values 0/2/3, no callers. */
s32 func_8001E158(void) {
    return (Item_FindById()->u0.field_0 >> 28) & 3;
}

s32 Item_GetPrice(s32 itemId) {
    return Item_FindById(itemId)->u4.field_4 & 0xFFFFFF;
}

u8 Item_GetBodyMask(s32 itemId) {
    return Item_FindById(itemId)->u4.b4.bodyMask;
}

s32 Item_GetTableIndex(s32 id) {
    ItemTableEntry *p = (ItemTableEntry *)Cd_GetFileEntry(0x45E0000);
    s32 i = 0;

    while (p->u0.id != 0) {
        if (p->u0.id == id) {
            return i;
        }
        p++;
        i++;
    }
    return 0;
}

s32 Item_GetIdAtIndex(s32 a0) {
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    s32 i;
    s32 r;
    for (i = 0; i < a0; i++) {
        if (*p == 0) break;
        p = (s16 *)((u8 *)p + 0x10);
    }
    r = 0;
    if (i == a0) {
        r = *p;
    }
    return r;
}
