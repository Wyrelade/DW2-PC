#ifndef PSYQ_H
#define PSYQ_H

/* Native build (DW2_NATIVE): the Psy-Q headers the game C sees. include/common.h includes this
 * before any game header, so every Psy-Q call has its real prototype and the decomp's own
 * Psy-Q declarations (behind #ifndef DW2_NATIVE) drop out. */

#include <string.h> /* libc2: memcpy, memset, strcpy */

#include "psyq_types.h"
#include "libgpu.h"
#include "libgte.h"
#include "libgs.h"
#include "libcd.h"
#include "libetc.h"
#include "libsnd.h"
#include "libmcrd.h"
#include "libpad.h"
#include "libpress.h"
#include "ps1mem.h"

#endif /* PSYQ_H */
