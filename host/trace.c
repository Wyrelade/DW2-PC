#include <stdio.h>

#include "common.h"
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
