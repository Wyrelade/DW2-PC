#ifndef PSYQ_VBLANK_H
#define PSYQ_VBLANK_H

/* One VBlank "interrupt": advances the VSync(-1) counter and runs the VSyncCallback handler
 * (Sys_VSyncHandler). Called by the host's 59.94 Hz clock (host/vblank.c). */
void Psyq_VBlank(void);
int Psyq_VBlankCount(void);
/* libpad: the VBlank controller read into the PadInitDirect buffers (after PadStartCom). */
void Psyq_PadVBlank(void);

#endif /* PSYQ_VBLANK_H */
