#ifndef PSYQ_VBLANK_H
#define PSYQ_VBLANK_H

/* One VBlank "interrupt": advances the VSync(-1) counter and runs the VSyncCallback handler
 * (Sys_VSyncHandler). Called by libetc's VSync waits and by the host. */
void Psyq_VBlank(void);
int Psyq_VBlankCount(void);

#endif /* PSYQ_VBLANK_H */
