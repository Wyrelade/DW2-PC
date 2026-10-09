#include "common.h"

#if DW2_DEV

#include "stag4000/stag4000.h"

/* PD.4 (DW2_DEV only): the one stag4000 value the state edit needs, in its own file because the
 * overlay headers do not go together with each other or with the host headers. Game thread. */

/* Floors of the current domain (Stg40_LoadDungFile), 0 when no domain is loaded. */
int DevEdit_FloorCount(void) {
    extern s32 Ovl_CurrentId;

    if (Ovl_CurrentId != 1 || Stg40_RootState == NULL) {
        return 0;
    }
    return Stg40_RootState->floorCount;
}

#endif /* DW2_DEV */
