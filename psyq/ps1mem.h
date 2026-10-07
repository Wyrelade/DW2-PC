#ifndef PSYQ_PS1MEM_H
#define PSYQ_PS1MEM_H

#include "psyq_types.h"

/* PS1 memory map on PC. The game C names a few fixed PS1 addresses (heap 0x80075000 up to
 * 0x801FF000, RAM top 0x801FFFFF, scratchpad 0x1F800000). The native build maps them into
 * one arena with the size of PS1 main RAM: PS1_RAM(0x80075000) = Ps1_Ram + 0x75000.
 *
 * The 24-bit OT links (P1.4): game C stores (u32)p & 0xFFFFFF in GPU packets. The exe is linked
 * at a 16 MB-aligned image base (CMakeLists.txt) and stays under 16 MB, so every global,
 * Ps1_Ram and so the heap share one 16 MB window: base | link gives the pointer back. */

#define PS1_RAM_SIZE 0x200000
#define PS1_SCRATCHPAD_SIZE 0x400

extern u_char Ps1_Ram[PS1_RAM_SIZE];
extern u_char Ps1_Scratchpad[PS1_SCRATCHPAD_SIZE];

/* A PS1 RAM address (KSEG0 / KUSEG / KSEG1 alike) inside the arena. */
#define PS1_RAM(addr) ((void *)(Ps1_Ram + ((u_long)(addr) & (PS1_RAM_SIZE - 1))))
/* The 1 KB data cache used as fast RAM (0x1F800000). */
#define PS1_SCRATCHPAD ((void *)Ps1_Scratchpad)

#endif /* PSYQ_PS1MEM_H */
