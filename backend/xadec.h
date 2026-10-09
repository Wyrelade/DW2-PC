#ifndef BACKEND_XADEC_H
#define BACKEND_XADEC_H

#include <stdint.h>

/* XA-ADPCM decoder of the PS1 CD controller (PR.5): takes the 2336-byte body of a Mode 2 Form 2
 * audio sector (subheader + 2328 bytes), decodes it (4 / 8 bit, mono / stereo, 37.8 / 18.9 kHz)
 * and resamples it to 44.1 kHz with the controller's zigzag filter. The frames wait in a FIFO
 * that the SPU's CD input (backend/psxspu.c) reads one frame per output sample. All on the game
 * thread. */

/* New stream: clears the FIFO, the ADPCM history and the resampler. */
void XaDec_Reset(void);

/* Decodes one audio sector into the FIFO (body = subheader at byte 0). */
void XaDec_Sector(const uint8_t *body);

/* Next 44.1 kHz stereo frame for the SPU CD input; zeros when the FIFO is empty. */
void XaDec_Pop(int16_t *l, int16_t *r);

/* Frames waiting in the FIFO. */
int XaDec_Queued(void);

/* Pops that found the FIFO empty since the first sector of the stream (XaDec_Reset); XaDec_Stop
 * ends the count when the stream stops (the frames already decoded still play out). */
int XaDec_Underruns(void);
void XaDec_Stop(void);

/* Dev / test: the 37.8 kHz decode before the resampler (frames, s16 L R) of the last sector, and
 * how many frames it has (18.9 kHz sectors count each sample once). */
const int16_t *XaDec_LastRaw(int *frames);

#endif /* BACKEND_XADEC_H */
