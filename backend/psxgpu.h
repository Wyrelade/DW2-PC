#ifndef BACKEND_PSXGPU_H
#define BACKEND_PSXGPU_H

#include <stdint.h>

/* Emulated PS1 GPU (P1.4): 1024x512 16-bit VRAM, the GP0 command set the game sends, the
 * drawing state (draw area, offset, texture page, texture window, mask) and the display area.
 * Software rasterizer, no host GPU. psyq/libgpu.c drives it; the host reads the display area
 * at each VBlank (PsxGpu_ReadDisplay). Pixel format: PS1 15-bit BGR + mask bit. */

#define PSXGPU_VRAM_W 1024
#define PSXGPU_VRAM_H 512

extern uint16_t PsxGpu_Vram[PSXGPU_VRAM_H][PSXGPU_VRAM_W];

/* GP1(0)-like reset of the drawing state; display off when `display` is set. */
void PsxGpu_Reset(int display);

/* GP0 command words (one OT packet body, or a few words from libgpu). Several commands may
 * follow each other; a command cut off at the end is dropped (logged). */
void PsxGpu_Gp0(const uint32_t *words, int count);

/* VRAM transfers (DMA / libgpu, not clipped by the draw area, coordinates wrap). */
void PsxGpu_Fill(int x, int y, int w, int h, uint32_t rgb24);
void PsxGpu_LoadImage(int x, int y, int w, int h, const uint16_t *src);
void PsxGpu_StoreImage(int x, int y, int w, int h, uint16_t *dst);
void PsxGpu_MoveImage(int sx, int sy, int dx, int dy, int w, int h);

/* Display (GP1 05 / 06 / 07 / 08 / 03 in one call). */
void PsxGpu_SetDisplay(int x, int y, int w, int h, int rgb24);
void PsxGpu_SetDisplayEnable(int on);

/* The visible picture: w x h pixels of 0x00RRGGBB written to `out` (at least 640 x 480 words).
 * Returns 0 when the display is off (out untouched). */
int PsxGpu_ReadDisplay(uint32_t *out, int *w, int *h);
/* The same picture from the HD surface (PG.1, backend/psxgpu_hd.h): w*S x h*S pixels, out NULL
 * = size only. Returns 0 when HD is off, the display is off or 24-bit, or no surface holds it
 * (the caller shows the 1x picture then). */
int PsxGpu_ReadDisplayHd(uint32_t *out, int *w, int *h);

#endif /* BACKEND_PSXGPU_H */
