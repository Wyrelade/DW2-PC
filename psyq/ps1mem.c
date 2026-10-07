#include "psyq_types.h"
#include "ps1mem.h"

/* PS1 main RAM (2 MB) and the scratchpad. The game's heap is Ps1_Ram + 0x75000 .. + 0x1FF000
 * (Mem_HeapStart, Sys_Main); the low part stays unused (main exe and overlay area on the PS1). */
u_char Ps1_Ram[PS1_RAM_SIZE] __attribute__((aligned(16)));
u_char Ps1_Scratchpad[PS1_SCRATCHPAD_SIZE] __attribute__((aligned(16)));
