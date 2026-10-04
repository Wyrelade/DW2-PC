#include "common.h"
#include "main/game.h"
#include "main/187C.h"
#include "main/307C.h"
#include "main/4BCC.h"
#include "main/6530.h"
#include "main/77DC.h"
#include "main/E280.h"

/* Small data this unit defines (retail reaches it with %gp_rel here). The bytes
 * live in the data asm; these tentative definitions are COMMON and bind to it. */
Blk5071C *D_8005071C;

void func_80021D50(void) {
}

void func_80021D58(void) {
}

s32 Bug_GetMaxMemBugLevel(void) {
    s32 best = 0;
    s32 i;
    s32 v;

    if (D_8005071C->memBugCount != 0) {
        for (i = 0; i < D_8005071C->memBugCount; i++) {
            best = (best < (v = D_8005071C->memBugLevels[i])) ? v : best;
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
    Flag_Bits.progress = 0;
}
