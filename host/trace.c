#include <stdio.h>

#include "common.h"
#include "backend/psxgpu_hd.h"
#include "host/host.h"
#include "main/156C.h"

extern SysState Sys_State;

/* Dev log: one line per game mode change (Sys_State.gameMode, scene table index << 8 | row) with
 * the VBlank wait it was seen at, so --press scripts can be lined up with the scenes. */
void Host_TraceTick(unsigned int wait) {
    static s32 last = -1;

    if (Sys_State.gameMode != last) {
        printf("[mode] wait %u (VBlank %llu): game mode 0x%X (prev 0x%X)\n", wait, Host_VBlankCount(),
               (unsigned int)Sys_State.gameMode, (unsigned int)Sys_State.prevGameMode);
        last = Sys_State.gameMode;
    }
}

/* PG.3 16:9: scenes that are a 320-wide 2D picture keep black sides (pillarbox): scene tables 1
 * (stag0000 debug menus), 4 (stag1000 title, movies), 6 (stag1100 memory card / VS party).
 * Called at each VBlank wait, before the flip draws the frame. The city rooms with a static
 * background mark their frames themselves (stag2000 staticbg.c). */
void Host_SceneTick(void) {
    s32 table = Sys_State.gameMode >> 8;

    if (PsxHd_Wide() && (table == 1 || table == 4 || table == 6)) {
        PsxHd_PillarboxFrame();
    }
}
