#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/linkedmodel.h"
#include "stag4000/floor.h"
#include "stag4000/hud.h"
#include "stag4000/bitswin.h"
#include "stag4000/itemmenu.h"
#include "stag4000/enemyinfo.h"
#include "stag4000/msgwin.h"
#include "stag4000/obj.h"
#include "stag4000/player.h"
#include "stag4000/enemy.h"
#include "stag4000/entity.h"
#include "stag4000/spawn.h"
#include "stag4000/automap.h"
#include "stag4000/textobj.h"

Stg40Ent48 *Stg40_FindEntByDigiId(s32 id) {
    Stg40Ent48 *e;
    s32 i;

    for (i = 0, e = Dung_StatePtr->ents; i < 41; i++, e++) {
        if (e->flags & 0x8000) {
            if ((id != 0 && id == e->digiId) || (id == 0 && (e->flags & 1))) {
                return e;
            }
        }
    }
    return NULL;
}

void Stg40_TextObjCommand(s32 *arg) {
    Stg40Ent48 *e;
    Actor *t;
    s32 st;

    st = -1;
    Stg40_RootState->cmdDigiId = *arg++;
    Stg40_RootState->cmdArgs.field_0 = arg[0] - 1;
    Stg40_RootState->cmdArgs.field_2 = arg[1] - 1;
    Stg40_RootState->cmdBusy = 0;
    Stg40_RootState->cmdActor = NULL;
    e = Stg40_FindEntByDigiId(Stg40_RootState->cmdDigiId);
    if (e != NULL) {
        t = e->actor;
        Stg40_RootState->cmdBusy = 1;
        switch (Stg40_RootState->cmdArgs.field_0) {
        default:
            st = 5;
            break;
        case 0x62:
            if (Stg40_RootState->cmdArgs.field_2 == -1) {
                st = 4;
                Stg40_RootState->cmdActor = t;
            } else {
                st = 6;
                Stg40_RootState->cmdBusy = 0;
            }
            break;
        case 0x61:
            e->targetHeading = (Stg40_RootState->cmdArgs.field_2 << 12) / 360;
            Stg40_RootState->cmdBusy = 0;
            break;
        case 0x60:
            e->flags |= 0x200;
            Stg40_RootState->cmdBusy = 0;
            break;
        }
        if (st != -1) {
            Task_SetState1(t, (u8)st);
        }
    }
}

void Stg40_EndTextObjCmd(void) {
    Stg40_RootState->cmdBusy = 0;
}

s16 Stg40_IsTextObjCmdBusy(void) {
    return Stg40_RootState->cmdBusy;
}
