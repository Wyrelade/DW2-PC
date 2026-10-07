#ifndef BACKEND_PSXSPU_H
#define BACKEND_PSXSPU_H

#include <stdint.h>

/* Emulated PS1 SPU (P1.8): 512 KB sound RAM, the register file at 0x1F801C00..0x1F801FFF, 24
 * ADPCM voices with pitch counter, 4-point interpolation, ADSR envelope, voice / main volume,
 * pitch modulation, noise. Output at 44100 Hz stereo, the SPU's own rate. The Psy-Q libspu
 * code (psyq/libspu.c) programs it through PsxSpu_Write16 / PsxSpu_Read16; DMA channel 4 lands
 * in PsxSpu_DmaWrite / PsxSpu_DmaRead. Reverb is mixed; the CD audio input is not yet
 * (logged once when enabled with a nonzero volume). */

#define PSXSPU_RAM_SIZE 0x80000

extern uint8_t PsxSpu_Ram[PSXSPU_RAM_SIZE];

void PsxSpu_Reset(void);

/* Register access, offset from 0x1F801C00 (0..0x3FF), 16-bit. */
void PsxSpu_Write16(uint32_t off, uint16_t v);
uint16_t PsxSpu_Read16(uint32_t off);

/* DMA channel 4: words to / from sound RAM at the current transfer address. */
void PsxSpu_DmaWrite(const uint32_t *src, uint32_t words);
void PsxSpu_DmaRead(uint32_t *dst, uint32_t words);

/* Produce n stereo frames (s16 L, R interleaved) at 44100 Hz. */
void PsxSpu_Render(int16_t *out, int n);

#endif /* BACKEND_PSXSPU_H */
