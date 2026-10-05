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

s32 Digi_GetDataFileId(s32 arg0) {
    if (arg0 < 0x12C) {
        return 0xCB9;
    }
    if ((u32)(arg0 - 0x190) < 0x65) {
        return 0xCBB;
    }
    return 0xCBA;
}

DigiData *Digi_FindDataById(s32 id) {
    DigiData *e = (DigiData *)Cd_GetFileEntry(Digi_GetDataFileId(id) << 16);
    s32 k;

    while (1) {
        k = (e->u4.packedId >> 1) & 0x7FFF;
        if (k == 0) {
            break;
        }
        if (k == id) {
            return e;
        }
        e++;
    }
    return 0;
}

s32 Digi_GetModelFile(s32 id) {
    return Digi_FindDataById(id)->u4.h4.modelFile;
}

s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1) {
    return Digi_FindDataById(arg0)->animFiles[arg1];
}

u8 *Digi_GetDefaultName(s32 id) {
    s32 v;

    v = Digi_FindDataById(id)->nameOffset;
    v += Cd_GetFileOrNull(Digi_GetDataFileId(id));
    return (u8 *)v;
}

/* Unnamed: DigiData field_1E (MODELDTx), subtracted with +0x280 from fx Y, lineup sort key,
 * battle height bucket; values do not track model size (Monzaemon 857, Biyomon 1280), meaning
 * unproven. */
s16 func_8001E79C(s32 id) {
    return Digi_FindDataById(id)->field_1E;
}

/* Unnamed: DigiData field_20, Y offset for hit-fx slot 1 only; meaning unproven. */
s16 func_8001E7C0(s32 id) {
    return Digi_FindDataById(id)->field_20;
}

void Digi_GetCastFxOffsets(s32 a0, void *a1) {
    u8 *base;
    DigiData *e;
    base = (u8 *)Cd_GetFileEntry((Digi_GetDataFileId(a0) << 16) | 1);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 0) = *(Row6 *)(base + e->field_22 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 6) = *(Row6 *)(base + e->field_24 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 12) = *(Row6 *)(base + e->field_26 * 6);
}

/* Unnamed: DigiData packedId bit 0 (set on e.g. Overlord GAIA, C-Seadramon) picks sound 0x204 vs
 * 0x205 in the hit reaction; what the bit means is unproven. */
s32 func_8001E8D0(s32 id) {
    return Digi_FindDataById(id)->u4.packedId & 1;
}

u16 Digi_GetModelListId(s32 idx) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000) + idx;
    return (p->packedId >> 1) & 0x7FFF;
}

s32 Digi_GetModelListCount(void) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000);
    s32 i = 0;
    while ((p->packedId >> 1) & 0x7FFF) {
        p++;
        i++;
    }
    return i;
}

s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur) {
    s32 x;
    s32 exp;

    if (lv >= max) {
        return 99999999;
    }
    if (lv >= 62) {
        x = lv - 61;
        exp = 826540 + x * 65535;
    } else if (lv >= 31) {
        x = lv - 30;
        exp = x * x * x * 20 + x * x * 60 + x * 4580 + 31080;
    } else if (lv >= 21) {
        x = lv - 20;
        exp = x * x * x * 10 + x * x * 30 + x * 1220 + 5880;
    } else if (lv >= 11) {
        x = lv - 10;
        exp = x * x * x * 10 / 3 + x * x * 10 + x * 107 + 480;
    } else {
        x = lv;
        exp = x * x * x / 3 + x * x + x * 5;
    }
    if (exp < cur) {
        return 0;
    }
    return exp - cur;
}

s32 Digi_CalcMaxLevel(s32 x) {
    s32 h = x / 2;

    if (x < 6) {
        return x / 3 + 13;
    }
    if (x < 18) {
        return h + 14;
    }
    if (x < 28) {
        return h + 17;
    }
    {
        s32 r = (u16)((u16)Rand_Next() % 3) + 2;
        return x + r;
    }
}
