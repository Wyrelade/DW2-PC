#ifndef BACKEND_PSXGPU_HD_H
#define BACKEND_PSXGPU_HD_H

#include <stdint.h>

/* HD output of the emulated GPU (PG.1): the draw / display buffers drawn a second time at
 * S x S pixels per VRAM pixel ("surfaces"), next to the 1x VRAM, which stays exactly as the PS1
 * GPU would leave it (textures, CLUTs, CPU access and the classic picture). Textures are always
 * read from the 1x VRAM: the game never samples a draw buffer (PG.0 finding). With scale 1 the
 * HD path is off and nothing here runs. backend/psxgpu.c calls these after each 1x operation. */

/* Drawing state of backend/psxgpu.c (E1-E6). */
typedef struct {
    int clip_x0, clip_y0, clip_x1, clip_y1; /* draw area, inclusive */
    int ofs_x, ofs_y;
    uint32_t tpage;                         /* E1 bits 0-8 and 11 */
    int dither, draw_disp, flip_x, flip_y;
    int tw_mask_x, tw_mask_y, tw_off_x, tw_off_y;
    int set_mask, check_mask;
} PsxGpuState;

/* One polygon vertex in VRAM coordinates (drawing offset applied), colour 8 bits per channel. */
typedef struct {
    int x, y;
    int r, g, b;
    int u, v;
} PsxVtx;

/* Texture of a primitive: mode 0 4-bit, 1 8-bit, 2 15-bit; page tx / ty, CLUT cx / cy. */
typedef struct {
    int mode;
    int tx, ty, cx, cy;
    int raw;
} PsxTex;

/* Scale 1..8 (1 = HD off). Surfaces are rebuilt from the 1x VRAM at the next use. */
void PsxHd_SetScale(int scale);
int PsxHd_Scale(void);
int PsxHd_On(void);
/* Drawing threads for the HD surfaces (0 = one per logical core, at most 8). Takes effect when
 * the first HD frame is drawn. */
void PsxHd_SetThreads(int n);

/* A draw or display buffer rect (PutDrawEnv clip, PutDispEnv area). Kept when an existing
 * surface holds it; otherwise the surfaces it overlaps are dropped and it becomes one. */
void PsxHd_Register(int x, int y, int w, int h);

/* Primitives, drawn into the surface that holds the current draw area. */
void PsxHd_Triangle(const PsxGpuState *st, const PsxVtx *v0, const PsxVtx *v1, const PsxVtx *v2, int gouraud,
                    const PsxTex *t, int semi, int abr);
void PsxHd_Rect(const PsxGpuState *st, int x0, int y0, int w, int h, const PsxTex *t, int u0, int v0, int r, int g,
                int b, int semi, int abr);
void PsxHd_Line(const PsxGpuState *st, const PsxVtx *a, const PsxVtx *b, int gouraud, int semi, int abr);

/* Transfers: a fill (colour in VRAM format), or a rect the 1x VRAM just got from the CPU or a
 * VRAM copy (copied into the surfaces, nearest). */
void PsxHd_Fill(int x, int y, int w, int h, uint16_t c);
void PsxHd_Refresh(int x, int y, int w, int h);

/* The display area (x, y, w, h in VRAM) from a surface: w*S x h*S pixels of 0x00RRGGBB into out
 * (NULL: size only). Returns 0 when HD is off or no surface holds the area. */
int PsxHd_ReadDisplay(int x, int y, int w, int h, uint32_t *out, int *ow, int *oh);
/* Changes on every surface write or display change (the host skips unchanged frames). */
unsigned PsxHd_Serial(void);

#endif /* BACKEND_PSXGPU_HD_H */
