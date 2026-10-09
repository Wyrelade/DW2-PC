#ifndef PSYQ_VBLANK_H
#define PSYQ_VBLANK_H

/* One VBlank "interrupt": advances the VSync(-1) counter and runs the VSyncCallback handler
 * (Sys_VSyncHandler). Called by the host's 59.94 Hz clock (host/vblank.c). */
void Psyq_VBlank(void);
int Psyq_VBlankCount(void);
/* libpad: the VBlank controller read into the PadInitDirect buffers (after PadStartCom). */
void Psyq_PadVBlank(void);
/* libmcrd: the card driver's VBlank step (async card operations finish on VBlanks). */
void Psyq_CardVBlank(void);
/* libsnd / libspu hardware: DMA channel 4 completion delivered (psyq/snd_hw.c). */
void Snd_HwVBlank(void);
/* libcd: the timed CD stream's VBlank step (XA audio sectors into the decoder, PR.5). */
void Psyq_CdVBlank(void);
/* libcd: 1 while a timed stream runs (XA audio or a movie): the speed-up waits for it (PR.28). */
int Psyq_CdStreaming(void);

#endif /* PSYQ_VBLANK_H */
