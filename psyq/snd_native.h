#ifndef PSYQ_SND_NATIVE_H
#define PSYQ_SND_NATIVE_H

#include <stdint.h>

#include "ps1mem.h"

/* Native libsnd / libspu (P1.8): the retail Psy-Q 4.7 code (asm/USA/main/nonmatchings/psyq)
 * translated to C function by function. The library keeps its globals where retail has them:
 * at their PS1 addresses inside Ps1_Ram, filled at start from the retail exe image (rodata
 * 0x80010000.. and the data / bss block 0x80038000..0x80063360, see Snd_NativeInit). So the
 * translated code addresses memory exactly like the asm does, by 32-bit address:
 *
 * - 0x80000000..0x801FFFFF and the KSEG1 mirror 0xA0000000..: Ps1_Ram (retail globals, tables;
 *   KUSEG 0x00000000.. is not mapped: native stack addresses live there on Windows)
 * - 0x1F801000..0x1F802FFF: hardware registers (SPU 0x1F801C00.., DMA, timers): the SPU model
 *   in backend/psxspu.c and the DMA channel 4 model in psyq/snd_hw.c
 * - anything else: a native pointer (game buffers handed to libsnd, the heap) of this 32-bit
 *   build, stored in retail memory as its 32-bit value.
 *
 * A function pointer stored in retail memory is the native function's address as a 32-bit
 * value (SND_FN / SND_FNVAL). All of this needs a 32-bit build (P1.12 note). */

uint32_t Snd_R32(uint32_t addr);
uint32_t Snd_R16(uint32_t addr); /* zero extended */
uint32_t Snd_R8(uint32_t addr);  /* zero extended */
void Snd_W32(uint32_t addr, uint32_t v);
void Snd_W16(uint32_t addr, uint32_t v);
void Snd_W8(uint32_t addr, uint32_t v);

/* lw / lh / lhu / lb / lbu / sw / sh / sb */
#define LW(a) ((int32_t)Snd_R32((uint32_t)(a)))
#define LH(a) ((int32_t)(int16_t)Snd_R16((uint32_t)(a)))
#define LHU(a) ((int32_t)Snd_R16((uint32_t)(a)))
#define LB(a) ((int32_t)(int8_t)Snd_R8((uint32_t)(a)))
#define LBU(a) ((int32_t)Snd_R8((uint32_t)(a)))
#define SW(a, v) Snd_W32((uint32_t)(a), (uint32_t)(v))
#define SH(a, v) Snd_W16((uint32_t)(a), (uint32_t)(v))
#define SB(a, v) Snd_W8((uint32_t)(a), (uint32_t)(v))

/* A native pointer as the 32-bit value retail memory and registers hold, and back. */
#define SND_ADDR(p) ((uint32_t)(uintptr_t)(p))
#define SND_PTR(v) ((void *)(uintptr_t)(uint32_t)(v))
/* Function pointers stored in retail memory (callback tables, D_8004FC50 ...). */
typedef int (*SndFn)();
#define SND_FNVAL(f) ((uint32_t)(uintptr_t)(f))
#define SND_FN(v) ((SndFn)(uintptr_t)(uint32_t)(v))

/* MIPS mult / multu hi word, for the division-by-constant sequences of the retail code. */
#define MULT_HI(a, b) ((int32_t)(((int64_t)(int32_t)(a) * (int64_t)(int32_t)(b)) >> 32))
#define MULTU_HI(a, b) ((uint32_t)(((uint64_t)(uint32_t)(a) * (uint64_t)(uint32_t)(b)) >> 32))

/* The libapi / libetc services the sound code calls, native versions (psyq/snd_hw.c). The
 * translated code calls these instead of the retail names. */
int Psx_GetVideoMode(void);
int Psx_EnterCriticalSection(void);
void Psx_ExitCriticalSection(void);
int Psx_OpenEvent(int desc, int spec, int mode, uint32_t func);
int Psx_EnableEvent(int event);
int Psx_TestEvent(int event);
int Psx_WaitEvent(int event);
void Psx_DeliverEvent(int ev1, int ev2);
uint32_t Psx_DMACallback(int dma, uint32_t func);
uint32_t Psx_InterruptCallback(int irq, uint32_t func);
int Psx_VSyncCallback(uint32_t func);
void Psx_ResetCallback(void);
int Psx_SetRCnt(int spec, int target, int mode);
int Psx_ResetRCnt(int spec);
void Psx_printf(uint32_t fmt, ...);

/* Every translated libsnd / libspu function that the game does not call directly (those are
 * prototyped in libsnd.h): declared without a prototype so the files can call each other with
 * the argument count the asm passes (all arguments are int-sized in this 32-bit build; each
 * function truncates its own arguments where the asm does). */
#include "snd_internal.h"

void Snd_NativeInit(void);

#endif /* PSYQ_SND_NATIVE_H */
