#include "common.h"

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTReset);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTGetEnv);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTPutEnv);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTin);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTout);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTinSync);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCToutSync);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTinCallback);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCToutCallback);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", MDEC_reset);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", MDEC_in);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", MDEC_out);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", MDEC_in_sync);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", MDEC_out_sync);

/* Unnamed: Psy-Q code, maybe MDEC_status: libpress internal: returns *MDEC1 status reg, used by
 * DecDCTinSync(1); SDK internal name not certain. */
INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", func_80064CB4);

/* Unnamed: Psy-Q code, maybe timeout: libpress internal: printf("%s timeout:\n", name) then
 * resets MDEC + DMA0/1 CHCR; static helper, real name not certain. */
INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", func_80064CCC);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTvlcSize2);

INCLUDE_ASM("asm/USA/stag1000/nonmatchings/stag1000_libpress", DecDCTvlc2);
