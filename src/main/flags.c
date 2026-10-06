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
#include "main/gamedata.h"
#include "main/flagtable.h"
#include "main/digidata.h"
#include "main/shadow.h"
#include "main/skill.h"
#include "main/anim.h"
#include "main/model.h"
#include "main/12550.h"

s32 Mem_TestBit(u8 *arg0, s32 arg1) {
    s32 i = arg1 >> 3;
    s32 m = 1 << (arg1 & 7);

    return (arg0[i] & m) != 0;
}

extern s32 Mem_TestBit(u8 *, s32);
extern s32 Stg20_TestSpecialFlag(s32);

s32 Flag_Test(s32 arg0) {
    s32 i;

    if (arg0 < 0x258) {
        return Mem_TestBit(Save_GameState.eventFlags.flags0, arg0);
    }
    if (arg0 < 0x2BC) {
        return Mem_TestBit(Save_GameState.eventFlags.flags600, arg0 - 0x258);
    }
    if (arg0 < 0x320) {
        return Mem_TestBit(Save_GameState.eventFlags.flags700, arg0 - 0x2BC);
    }
    if (arg0 < 0x3E8) {
        return Mem_TestBit(Save_GameState.eventFlags.flags800, arg0 - 0x320);
    }
    if (arg0 < 0x44C) {
        return Save_GameState.eventFlags.progress >= arg0 - 0x3E8;
    }
    if (arg0 < 0x640) {
        return Save_GameState.eventFlags.progress < arg0 - 0x5DC;
    }
    if (arg0 < 0x8BD) {
        for (i = 0; i < 0x30; i++) {
            if (((V66_21E78 *)&Save_GameState)->a[i] == arg0 - 0x7D0) {
                return 1;
            }
        }
        return 0;
    }
    if (arg0 < 0xBB8) {
        return ((VDD4_21E78 *)&Save_GameState)->a[arg0 - 0x7D0] != 0;
    }
    if (arg0 < 0xFA0) {
        s32 key = arg0 - 0xBB8;
        for (i = 0; i < 0x24; i++) {
            if (Save_GameState.elems[i].digiId == key) {
                if (Save_GameState.elems[i].state >= 2) {
                    return 1;
                }
            }
        }
        return 0;
    }
    if (Ovl_GetCurrentId() == 2) {
        return Stg20_TestSpecialFlag(arg0);
    }
    return 0;
}

s32 Flag_TestConds(Ent22038 *p) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (p[i].id != -1) {
            if (p[i].flag != 0) {
                if (Flag_Test(p[i].id) != 1) {
                    return 0;
                }
            } else {
                if (Flag_Test(p[i].id) != 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void Mem_WriteBit(u8 *arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 >> 3;
    s32 mask = 1 << (arg1 & 7);
    if (arg2 != 0) {
        arg0[idx] |= mask;
    } else {
        arg0[idx] &= ~mask;
    }
}

void Digi_AddNew(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        if (Save_GameState.elems[i].state == 0) {
            break;
        }
    }
    Digi_InitFromTable(arg0, 0, &Save_GameState.elems[i]);
    Digi_SortRoster();
    for (i = 0; i < 3; i++) {
        Save_GameState.elems[i].state =
            (Save_GameState.elems[i].state >= 2) ? (i + 3) : 0;
    }
}

void Flag_Set(s32 id, s32 val) {
    if (id < 600) {
        if (id == 0x10 && val == 0) {
            Mem_WriteBit(Save_GameState.eventFlags.flags0, 0x11, 0);
        }
        Mem_WriteBit(Save_GameState.eventFlags.flags0, id, val);
    } else if (id < 700) {
        Mem_WriteBit(Save_GameState.eventFlags.flags600, id - 600, val);
    } else if (id < 800) {
        Mem_WriteBit(Save_GameState.eventFlags.flags700, id - 700, val);
    } else if (id < 1000) {
        Mem_WriteBit(Save_GameState.eventFlags.flags800, id - 800, val);
    } else if (id < 2000) {
        Save_GameState.eventFlags.progress = id - 1900;
    } else if (id < 0x8BD) {
        Save_GameState.field_C4 = id - 2000;
        Item_SortList();
    } else if (id < 3000) {
        ((VDD4_21E78 *)&Save_GameState)->a[id - 2000]++;
    } else if (id < 4000) {
        switch (id - 3000) {
        case 3:
            Digi_AddNew(0xB7);
            break;
        case 31:
            Digi_AddNew(0xB6);
            break;
        case 217:
            Digi_AddNew(0xB8);
            break;
        }
    } else if (id < 10000) {
        if (Ovl_GetCurrentId() == 2) {
            Stg20_SetSpecialFlag(id, val);
        }
    }
}

void Flag_ApplySets(FlagSetPair *p) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (p[i].flag != -1) {
            Flag_Set(p[i].flag, p[i].value);
        }
    }
}

s32 Math_CycleRange(s32 v, s32 div, s32 lo, s32 hi) {
    s32 r;
    v /= div;
    if (lo < hi) {
        r = v % (hi - lo + 1);
        return r + lo;
    } else {
        r = v % (lo - hi + 1);
        return lo - r;
    }
}

s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi) {
    s32 span;
    s32 r;

    v /= div;
    span = hi - lo;
    r = v % (span * 2);
    if (r < span) {
        return r + lo;
    }
    return hi - (r - span);
}
