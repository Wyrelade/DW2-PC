#ifndef BACKEND_PSXGPU_HD_INT_H
#define BACKEND_PSXGPU_HD_INT_H

/* Internal to the HD output: the surfaces and the primitive queue of backend/psxgpu_hd.c, shared
 * with the GPU renderer backend/psxgpu_hw.c (PG.10b). */

#include <stdint.h>

#include "backend/psxgpu_hd.h"

typedef struct {
    int x, y, w, h; /* VRAM rect */
    int m;          /* 16:9 margin on each side, VRAM pixels */
    uint16_t *px;   /* software: (w + 2m)*S x h*S, NULL until used */
    void *tex;      /* GPU: the render texture, NULL until used */
} PsxHdSurf;

enum { PSXHD_TRI, PSXHD_RECT, PSXHD_LINE, PSXHD_FILL, PSXHD_COPY };

/* One queued operation. Fills and copies are queued only by the GPU renderer (x0 / y0 / w / h:
 * the VRAM rect inside s; r: the fill colour in VRAM format). */
typedef struct {
    int type;
    PsxHdSurf *s;
    PsxGpuState st;
    PsxVtx v[3];
    PsxTex tex;
    int textured, gouraud, semi, abr, precise;
    int wide; /* may draw into the 16:9 margins */
    int x0, y0, w, h, u0, v0, r, g, b; /* rectangles */
} PsxHdCmd;

/* Clip rect of the draw area of c in surface pixels, inclusive, inside the surface. */
void PsxHd_CmdClip(const PsxHdCmd *c, int *x0, int *y0, int *x1, int *y1);

/* backend/psxgpu_hw.c: the queue drawn on the GPU. PsxHw_Flush draws n commands in order
 * (uploading the VRAM rows marked dirty first); surfaces get their texture from PsxHw_Create.
 * PsxHw_Read downloads the surface pixels x, y, w, h (surface pixels) as 0x00RRGGBB. */
int PsxHw_Active(void);
void *PsxHw_Create(int w, int h);
void PsxHw_Release(void *tex);
void PsxHw_MarkDirty(int y, int h);
void PsxHw_Flush(const PsxHdCmd *q, int n, int scale);
int PsxHw_Read(void *tex, int x, int y, int w, int h, uint32_t *out);

#endif /* BACKEND_PSXGPU_HD_INT_H */
