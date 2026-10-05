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

DigiBaseData *Digi_FindBaseData(id) s32 id; {
    DigiBaseData *p = (DigiBaseData *)Cd_GetFileOrNull(0xC6C);
    s16 v;

loop:
    v = p->id;
    if (v == 0) {
        goto fail;
    }
    if (v == id) {
        return p;
    }
    p++;
    goto loop;
fail:
    return 0;
}

/* Unnamed: DIGIMNDT byte +3 (0..8), not rank/type/specialty (checked vs MetalKid RankId); only
 * use is an index in stag2000 func_8006A190's table, meaning unproven. */
u8 func_8001D910(s32 digiId) {
    return Digi_FindBaseData(digiId)->field_3;
}

u8 Digi_GetType(s32 digiId) {
    return Digi_FindBaseData(digiId)->u4.attrsLo & 0xF;
}

s32 Digi_GetRank(s32 digiId) {
    return (Digi_FindBaseData(digiId)->u4.field_4h >> 4) & 0xF;
}

s32 Digi_GetSpecialty(s32 digiId) {
    return (Digi_FindBaseData(digiId)->u4.field_4h >> 8) & 0xF;
}

u8 Digi_GetLearnedSkill(s32 digiId) {
    return Digi_FindBaseData(digiId)->learnedSkill;
}

s32 Digi_GetStatGrowth(s32 id, s32 k) {
    switch (k) {
    default:
    case 0:
        return Digi_FindBaseData(id)->u4.field_4h >> 12;
    case 1:
        return Digi_FindBaseData(id)->u6.growthLo & 0xF;
    case 2:
        return (Digi_FindBaseData(id)->u6.field_6h >> 4) & 0xF;
    case 3:
        return (Digi_FindBaseData(id)->u6.field_6h >> 8) & 0xF;
    case 4:
        return Digi_FindBaseData(id)->u6.field_6h >> 12;
    }
}
