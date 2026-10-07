#ifndef HOST_HOST_H
#define HOST_HOST_H

/* Host layer hooks the game C calls in the native build (DW2_NATIVE). */

/* Ovl_Load: all overlays are linked; restore overlay `id`'s initial .data and zero its .bss
 * (what the retail file copy over the overlay area did). id = Ovl_FileIds index. */
void Host_OvlReset(int id);

/* Sys_Main's spin on Sys_FlipPending: one host VBlank per call (P1.1 pump, P1.2 paces it). */
void Host_WaitVBlank(void);

#endif /* HOST_HOST_H */
