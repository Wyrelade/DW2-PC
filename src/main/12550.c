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

/* Small data this unit defines (.sdata). Retail reaches it with %gp_rel here. */
DungState *Dung_StatePtr = &Dung_State;
/* .bss */
DungState Dung_State;

/* Unnamed: empty stub, no callers, no table ref. */
void func_80021D50(void) {
}

/* Unnamed: empty stub, no callers, no table ref. */
void func_80021D58(void) {
}

s32 Bug_GetMaxMemBugLevel(void) {
    s32 best = 0;
    s32 i;
    s32 v;

    if (Dung_StatePtr->memBugCount != 0) {
        for (i = 0; i < Dung_StatePtr->memBugCount; i++) {
            best = (best < (v = Dung_StatePtr->memBugLevels[i])) ? v : best;
        }
    }
    return best;
}


void Save_ClearEventFlags(void) {
    s32 i;
    SaveEventFlags *p;

    i = 0x1F;
    p = (SaveEventFlags *)((u8 *)&Save_GameState + i);
    do {
        p->a[0] = 0;
        p = (SaveEventFlags *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 7;
    p = (SaveEventFlags *)((u8 *)&Save_GameState + i);
    do {
        p->b[0] = 0;
        p = (SaveEventFlags *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 7;
    p = (SaveEventFlags *)((u8 *)&Save_GameState + i);
    do {
        p->c[0] = 0;
        p = (SaveEventFlags *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 0xF;
    p = (SaveEventFlags *)((u8 *)&Save_GameState + i);
    do {
        p->d[0] = 0;
        p = (SaveEventFlags *)((u8 *)p - 1);
    } while (--i >= 0);
    Save_GameState.eventFlags.progress = 0;
}
