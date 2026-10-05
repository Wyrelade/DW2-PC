#include "common.h"
#include "main/game.h"

/* Small data this file defines (.sbss, reached with %gp_rel here), then its .bss. */
s32 Cd_PreloadCount;
s32 Cd_PreloadIds[0x40];

void Cd_QueueStag4000Files(void) {
    s32 *p;
    s32 i;

    p = Cd_PreloadIds;
    Cd_QueueFile(0x19A);
    for (i = 0; i < Cd_PreloadCount; i++) {
        Cd_QueueFile(*p);
        p++;
    }
}

/* Unnamed: empty stub, no callers, no table ref. */
void func_800116A8(void) {
}
