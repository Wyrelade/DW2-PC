#ifndef PSYQ_GTE_CORE_H
#define PSYQ_GTE_CORE_H

#include <stdint.h>

/* C model of the PS1 GTE (COP2), shared by libgte (psyq/libgte.c) and the gte.h macros
 * (psyq/gte.c). The 32 data and 32 control registers keep their hardware view: a write stores
 * what the register holds (16-bit registers sign or zero extended), a read returns what mfc2 /
 * cfc2 would. Commands take the COP2 instruction word, so sf, lm and the MVMVA fields come
 * from the same bits as on the PS1. Results follow the hardware rules (psx-spx "GTE"): 44-bit
 * MAC accumulation with overflow flags, IR / colour / SZ / SXY saturation, the UNR divide, and
 * FLAG bit 31 as the error summary. */

/* Data registers. */
enum {
    GTE_VXY0 = 0, GTE_VZ0, GTE_VXY1, GTE_VZ1, GTE_VXY2, GTE_VZ2, GTE_RGBC, GTE_OTZ,
    GTE_IR0, GTE_IR1, GTE_IR2, GTE_IR3, GTE_SXY0, GTE_SXY1, GTE_SXY2, GTE_SXYP,
    GTE_SZ0, GTE_SZ1, GTE_SZ2, GTE_SZ3, GTE_RGB0, GTE_RGB1, GTE_RGB2, GTE_RES1,
    GTE_MAC0, GTE_MAC1, GTE_MAC2, GTE_MAC3, GTE_IRGB, GTE_ORGB, GTE_LZCS, GTE_LZCR
};

/* Control registers. */
enum {
    GTE_RT0 = 0, GTE_TRX = 5, GTE_TRY, GTE_TRZ, GTE_LLM0, GTE_RBK = 13, GTE_GBK, GTE_BBK,
    GTE_LCM0, GTE_RFC = 21, GTE_GFC, GTE_BFC, GTE_OFX, GTE_OFY, GTE_H, GTE_DQA, GTE_DQB,
    GTE_ZSF3, GTE_ZSF4, GTE_FLAG
};

/* Command words as the Psy-Q macros and libgte emit them (include/gte_macros.inc). */
#define GTE_CMD_RTPS 0x4A180001u
#define GTE_CMD_NCLIP 0x4B400006u
#define GTE_CMD_NCS 0x4AC8041Eu
#define GTE_CMD_MVMVA(sf, mx, v, cv, lm) \
    (0x4A400012u | ((unsigned)(sf) << 19) | ((unsigned)(mx) << 17) | ((unsigned)(v) << 15) | \
     ((unsigned)(cv) << 13) | ((unsigned)(lm) << 10))
#define GTE_CMD_GPF(sf) (0x4B90003Du | ((unsigned)(sf) << 19))

void Gte_Reset(void);
void Gte_Mtc2(int reg, uint32_t value);
uint32_t Gte_Mfc2(int reg);
void Gte_Ctc2(int reg, uint32_t value);
uint32_t Gte_Cfc2(int reg);
/* lwc2 / swc2: a 32-bit word between memory (any alignment) and a data register. */
void Gte_Lwc2(int reg, const void *addr);
void Gte_Swc2(int reg, void *addr);
void Gte_Command(uint32_t op);

/* PG.2 (no-wobble HD output): called after every RTPS with the integer SXY2 word and a float
 * projection of the same point from the unshifted MAC1..3 (x = view x * H / z + OFX, y the same,
 * before the 11-bit cut; z = view depth). Skipped when H >= 2 * z (the UNR divide saturates).
 * NULL by default (gte_test): the hardware view is never changed by it. */
extern void (*Gte_PreciseHook)(int32_t sxy, double x, double y, double z);

#endif /* PSYQ_GTE_CORE_H */
