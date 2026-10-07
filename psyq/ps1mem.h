#ifndef PSYQ_PS1MEM_H
#define PSYQ_PS1MEM_H

#include <stdint.h>

#include "psyq_types.h"

/* PS1 memory map on PC. The game C names a few fixed PS1 addresses (heap 0x80075000 up to
 * 0x801FF000, RAM top 0x801FFFFF, scratchpad 0x1F800000). The native build maps them into
 * one arena with the size of PS1 main RAM: PS1_RAM(0x80075000) = Ps1_Ram + 0x75000.
 *
 * The 24-bit OT links (P1.4): game C stores (u32)p & 0xFFFFFF in GPU packets. The exe is linked
 * at a 16 MB-aligned image base (CMakeLists.txt) and stays under 16 MB, so every global,
 * Ps1_Ram and so the heap share one 16 MB window: base | link gives the pointer back. */

#define PS1_RAM_SIZE 0x200000
/* 1 KB on the PS1; twice that here: Gfx_CalcModelBoneMatrices keeps its bone nodes there
 * (0x44 bytes each, 0x48 in 64-bit, P1.12). */
#define PS1_SCRATCHPAD_SIZE 0x800

extern u_char Ps1_Ram[PS1_RAM_SIZE];
extern u_char Ps1_Scratchpad[PS1_SCRATCHPAD_SIZE];

/* A PS1 RAM address (KSEG0 / KUSEG / KSEG1 alike) inside the arena. */
#define PS1_RAM(addr) ((void *)(Ps1_Ram + ((u_long)(addr) & (PS1_RAM_SIZE - 1))))
/* A 24-bit GPU packet link (OT tag) back to a pointer in the 16 MB window of Ps1_Ram. */
#define PS1_LINK_PTR(link) \
    ((u_long *)(((uintptr_t)Ps1_Ram & ~(uintptr_t)0xFFFFFF) | ((uintptr_t)(link) & 0xFFFFFF)))
/* The 1 KB data cache used as fast RAM (0x1F800000). */
#define PS1_SCRATCHPAD ((void *)Ps1_Scratchpad)

#endif /* PSYQ_PS1MEM_H */
