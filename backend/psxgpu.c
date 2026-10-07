#include <stdio.h>
#include <string.h>

#include "backend/psxgpu.h"

/* Emulated PS1 GPU (P1.4, title subset). Implemented: VRAM fill (GP0 02), polygons (GP0 20-3F:
 * flat / Gouraud, textured 4 / 8 / 15 bit with CLUT, modulated or raw, semi-transparent),
 * rectangles / sprites (60-7F), VRAM to VRAM copy (80), CPU to VRAM in a packet (A0), draw mode,
 * texture window, draw area, offset, mask bits (E1-E6). Not yet: lines (40-5F, skipped with a log
 * line), dithering (E1 bit 9 is kept, not applied), sprite flip bits, VRAM to CPU in a packet
 * (C0). Every unhandled command logs once.
 *
 * Rasterization rules followed: pixel centers on integer coordinates, top and left polygon edges
 * included, right and bottom excluded; quads are triangles (v0 v1 v2) and (v1 v2 v3); polygons
 * wider than 1023 or taller than 511 are dropped; texel 0 is transparent; semi-transparency
 * applies to untextured polygons with the semi bit and to textured ones only where the texel's
 * bit 15 is set; modulation is texel * colour / 128 per channel, clamped. */

uint16_t PsxGpu_Vram[PSXGPU_VRAM_H][PSXGPU_VRAM_W];

static struct {
    int clip_x0, clip_y0, clip_x1, clip_y1; /* draw area, inclusive */
    int ofs_x, ofs_y;
    uint32_t tpage;                         /* E1 bits 0-8 and 11 */
    int dither, draw_disp;
    int tw_mask_x, tw_mask_y, tw_off_x, tw_off_y;
    int set_mask, check_mask;
} st;

static struct {
    int x, y, w, h, rgb24, on;
} disp;

typedef struct {
    int x, y;
    int r, g, b;
    int u, v;
} Vtx;

typedef struct {
    int mode; /* 0 4-bit, 1 8-bit, 2 15-bit */
    int tx, ty, cx, cy;
    int raw;
} Tex;

static void log_once(int op, const char *what) {
    static unsigned char seen[256];

    if (!seen[op & 0xFF]) {
        seen[op & 0xFF] = 1;
        printf("[gpu] GP0 %02X: %s (logged once)\n", op & 0xFF, what);
    }
}

static int sign11(uint32_t v) {
    return (int)(v << 21) >> 21;
}

void PsxGpu_Reset(int display) {
    memset(&st, 0, sizeof(st));
    st.clip_x1 = PSXGPU_VRAM_W - 1;
    st.clip_y1 = PSXGPU_VRAM_H - 1;
    if (display) {
        disp.on = 0;
    }
}

/* ---- pixels ---- */

static void put(int x, int y, int r, int g, int b, int semi, int abr, int mask) {
    uint16_t *d = &PsxGpu_Vram[y][x];

    if (st.check_mask && (*d & 0x8000)) {
        return;
    }
    if (semi) {
        int br = *d & 31;
        int bg = (*d >> 5) & 31;
        int bb = (*d >> 10) & 31;

        switch (abr) {
        case 0:
            r = (br + r) >> 1;
            g = (bg + g) >> 1;
            b = (bb + b) >> 1;
            break;
        case 1:
            r = br + r;
            g = bg + g;
            b = bb + b;
            break;
        case 2:
            r = br - r;
            g = bg - g;
            b = bb - b;
            break;
        default:
            r = br + (r >> 2);
            g = bg + (g >> 2);
            b = bb + (b >> 2);
            break;
        }
        r = r < 0 ? 0 : r > 31 ? 31 : r;
        g = g < 0 ? 0 : g > 31 ? 31 : g;
        b = b < 0 ? 0 : b > 31 ? 31 : b;
    }
    *d = (uint16_t)(r | (g << 5) | (b << 10) | ((mask || st.set_mask) ? 0x8000 : 0));
}

static uint16_t texel(const Tex *t, int u, int v) {
    int y;

    u = ((u & ~st.tw_mask_x) | (st.tw_off_x & st.tw_mask_x)) & 0xFF;
    v = ((v & ~st.tw_mask_y) | (st.tw_off_y & st.tw_mask_y)) & 0xFF;
    y = (t->ty + v) & (PSXGPU_VRAM_H - 1);
    switch (t->mode) {
    case 0: {
        uint16_t w = PsxGpu_Vram[y][(t->tx + (u >> 2)) & (PSXGPU_VRAM_W - 1)];
        return PsxGpu_Vram[t->cy][(t->cx + ((w >> ((u & 3) * 4)) & 0xF)) & (PSXGPU_VRAM_W - 1)];
    }
    case 1: {
        uint16_t w = PsxGpu_Vram[y][(t->tx + (u >> 1)) & (PSXGPU_VRAM_W - 1)];
        return PsxGpu_Vram[t->cy][(t->cx + ((w >> ((u & 1) * 8)) & 0xFF)) & (PSXGPU_VRAM_W - 1)];
    }
    default:
        return PsxGpu_Vram[y][(t->tx + u) & (PSXGPU_VRAM_W - 1)];
    }
}

/* One pixel of a primitive: colour r, g, b in 8 bits per channel (vertex colour). */
static void shade(int x, int y, const Tex *t, int u, int v, int r, int g, int b, int semi, int abr) {
    if (t != NULL) {
        uint16_t c = texel(t, u, v);
        int tr, tg, tb;

        if (c == 0) {
            return;
        }
        tr = c & 31;
        tg = (c >> 5) & 31;
        tb = (c >> 10) & 31;
        if (!t->raw) {
            tr = (tr * r) >> 7;
            tg = (tg * g) >> 7;
            tb = (tb * b) >> 7;
            tr = tr > 31 ? 31 : tr;
            tg = tg > 31 ? 31 : tg;
            tb = tb > 31 ? 31 : tb;
        }
        put(x, y, tr, tg, tb, semi && (c & 0x8000), abr, c & 0x8000);
    } else {
        put(x, y, r >> 3, g >> 3, b >> 3, semi, abr, 0);
    }
}

/* ---- primitives ---- */

static long long edge(const Vtx *a, const Vtx *b, int px, int py) {
    return (long long)(b->x - a->x) * (py - a->y) - (long long)(b->y - a->y) * (px - a->x);
}

/* Top or left edge (included on ties) for a triangle with positive area under edge(). */
static int top_left(const Vtx *a, const Vtx *b) {
    int dx = b->x - a->x;
    int dy = b->y - a->y;

    return dy < 0 || (dy == 0 && dx > 0);
}

static void triangle(const Vtx *v0, const Vtx *v1, const Vtx *v2, int gouraud, const Tex *t, int semi, int abr) {
    long long area;
    int minx, maxx, miny, maxy;
    int tl0, tl1, tl2;
    int x, y;

    minx = v0->x < v1->x ? v0->x : v1->x;
    minx = v2->x < minx ? v2->x : minx;
    maxx = v0->x > v1->x ? v0->x : v1->x;
    maxx = v2->x > maxx ? v2->x : maxx;
    miny = v0->y < v1->y ? v0->y : v1->y;
    miny = v2->y < miny ? v2->y : miny;
    maxy = v0->y > v1->y ? v0->y : v1->y;
    maxy = v2->y > maxy ? v2->y : maxy;
    if (maxx - minx >= 1024 || maxy - miny >= 512) {
        return;
    }
    area = edge(v0, v1, v2->x, v2->y);
    if (area == 0) {
        return;
    }
    if (area < 0) {
        const Vtx *s = v1;
        v1 = v2;
        v2 = s;
        area = -area;
    }
    if (minx < st.clip_x0) minx = st.clip_x0;
    if (miny < st.clip_y0) miny = st.clip_y0;
    if (maxx > st.clip_x1) maxx = st.clip_x1;
    if (maxy > st.clip_y1) maxy = st.clip_y1;
    tl0 = top_left(v1, v2);
    tl1 = top_left(v2, v0);
    tl2 = top_left(v0, v1);
    for (y = miny; y <= maxy; y++) {
        for (x = minx; x <= maxx; x++) {
            long long w0 = edge(v1, v2, x, y);
            long long w1 = edge(v2, v0, x, y);
            long long w2 = edge(v0, v1, x, y);
            int r = v0->r, g = v0->g, b = v0->b, u = 0, v = 0;

            if (w0 < 0 || w1 < 0 || w2 < 0) {
                continue;
            }
            if ((w0 == 0 && !tl0) || (w1 == 0 && !tl1) || (w2 == 0 && !tl2)) {
                continue;
            }
            if (gouraud) {
                r = (int)((v0->r * w0 + v1->r * w1 + v2->r * w2) / area);
                g = (int)((v0->g * w0 + v1->g * w1 + v2->g * w2) / area);
                b = (int)((v0->b * w0 + v1->b * w1 + v2->b * w2) / area);
            }
            if (t != NULL) {
                u = (int)((v0->u * w0 + v1->u * w1 + v2->u * w2) / area);
                v = (int)((v0->v * w0 + v1->v * w1 + v2->v * w2) / area);
            }
            shade(x, y, t, u, v, r, g, b, semi, abr);
        }
    }
}

static void make_tex(Tex *t, uint32_t tpage, uint32_t clut, int raw) {
    t->mode = (tpage >> 7) & 3;
    if (t->mode == 3) {
        t->mode = 2;
    }
    t->tx = (tpage & 0xF) * 64;
    t->ty = ((tpage >> 4) & 1) * 256;
    t->cx = (clut & 0x3F) * 16;
    t->cy = (clut >> 6) & 0x1FF;
    t->raw = raw;
}

static void polygon(const uint32_t *w, int op) {
    int quad = op & 0x08;
    int textured = op & 0x04;
    int semi = op & 0x02;
    int gouraud = op & 0x10;
    int nv = quad ? 4 : 3;
    Vtx v[4];
    uint32_t clut = 0;
    uint32_t tpage = st.tpage;
    uint32_t col = w[0];
    Tex tex;
    int i, k;

    i = 1;
    for (k = 0; k < nv; k++) {
        if (gouraud && k > 0) {
            col = w[i++];
        }
        v[k].r = col & 0xFF;
        v[k].g = (col >> 8) & 0xFF;
        v[k].b = (col >> 16) & 0xFF;
        v[k].x = sign11(w[i] & 0xFFFF) + st.ofs_x;
        v[k].y = sign11(w[i] >> 16) + st.ofs_y;
        i++;
        v[k].u = v[k].v = 0;
        if (textured) {
            v[k].u = w[i] & 0xFF;
            v[k].v = (w[i] >> 8) & 0xFF;
            if (k == 0) {
                clut = w[i] >> 16;
            } else if (k == 1) {
                tpage = w[i] >> 16;
            }
            i++;
        }
    }
    if (textured) {
        /* A textured polygon's page becomes the current draw mode page (GPUSTAT bits 0-8, 11). */
        st.tpage = (st.tpage & ~0x9FFu) | (tpage & 0x9FF);
        make_tex(&tex, tpage, clut, op & 0x01);
    }
    triangle(&v[0], &v[1], &v[2], gouraud, textured ? &tex : NULL, semi, (tpage >> 5) & 3);
    if (quad) {
        triangle(&v[1], &v[2], &v[3], gouraud, textured ? &tex : NULL, semi, (tpage >> 5) & 3);
    }
}

static void rectangle(const uint32_t *w, int op) {
    static const int sizes[4] = { 0, 1, 8, 16 };
    int textured = op & 0x04;
    int semi = op & 0x02;
    int size = sizes[(op >> 3) & 3];
    int r = w[0] & 0xFF, g = (w[0] >> 8) & 0xFF, b = (w[0] >> 16) & 0xFF;
    int x0 = sign11(w[1] & 0xFFFF) + st.ofs_x;
    int y0 = sign11(w[1] >> 16) + st.ofs_y;
    int u0 = 0, v0 = 0;
    int rw, rh, i = 2;
    int x, y;
    Tex tex;

    if (textured) {
        u0 = w[2] & 0xFF;
        v0 = (w[2] >> 8) & 0xFF;
        make_tex(&tex, st.tpage, w[2] >> 16, op & 0x01);
        i = 3;
    }
    if (size == 0) {
        rw = w[i] & 0x3FF;
        rh = (w[i] >> 16) & 0x1FF;
    } else {
        rw = rh = size;
    }
    for (y = 0; y < rh; y++) {
        int py = y0 + y;
        if (py < st.clip_y0 || py > st.clip_y1) {
            continue;
        }
        for (x = 0; x < rw; x++) {
            int px = x0 + x;
            if (px < st.clip_x0 || px > st.clip_x1) {
                continue;
            }
            shade(px, py, textured ? &tex : NULL, u0 + x, v0 + y, r, g, b, semi, (st.tpage >> 5) & 3);
        }
    }
}

/* ---- transfers ---- */

void PsxGpu_Fill(int x, int y, int w, int h, uint32_t rgb24) {
    uint16_t c = (uint16_t)(((rgb24 >> 3) & 31) | (((rgb24 >> 11) & 31) << 5) | (((rgb24 >> 19) & 31) << 10));
    int i, j;

    for (j = 0; j < h; j++) {
        uint16_t *row = PsxGpu_Vram[(y + j) & (PSXGPU_VRAM_H - 1)];
        for (i = 0; i < w; i++) {
            row[(x + i) & (PSXGPU_VRAM_W - 1)] = c;
        }
    }
}

void PsxGpu_LoadImage(int x, int y, int w, int h, const uint16_t *src) {
    int i, j;

    for (j = 0; j < h; j++) {
        uint16_t *row = PsxGpu_Vram[(y + j) & (PSXGPU_VRAM_H - 1)];
        for (i = 0; i < w; i++) {
            row[(x + i) & (PSXGPU_VRAM_W - 1)] = *src++;
        }
    }
}

void PsxGpu_StoreImage(int x, int y, int w, int h, uint16_t *dst) {
    int i, j;

    for (j = 0; j < h; j++) {
        const uint16_t *row = PsxGpu_Vram[(y + j) & (PSXGPU_VRAM_H - 1)];
        for (i = 0; i < w; i++) {
            *dst++ = row[(x + i) & (PSXGPU_VRAM_W - 1)];
        }
    }
}

void PsxGpu_MoveImage(int sx, int sy, int dx, int dy, int w, int h) {
    static uint16_t line[PSXGPU_VRAM_W];
    int i, j;

    if (w > PSXGPU_VRAM_W) {
        w = PSXGPU_VRAM_W;
    }
    /* Row order chosen so an overlapping copy reads each row before it is overwritten. */
    for (j = 0; j < h; j++) {
        int jj = dy > sy ? h - 1 - j : j;
        const uint16_t *s = PsxGpu_Vram[(sy + jj) & (PSXGPU_VRAM_H - 1)];
        uint16_t *d = PsxGpu_Vram[(dy + jj) & (PSXGPU_VRAM_H - 1)];
        for (i = 0; i < w; i++) {
            line[i] = s[(sx + i) & (PSXGPU_VRAM_W - 1)];
        }
        for (i = 0; i < w; i++) {
            d[(dx + i) & (PSXGPU_VRAM_W - 1)] = line[i];
        }
    }
}

/* ---- GP0 ---- */

/* Words of the command starting at w[0] (n words available), or 0 when it is cut off. */
static int command_len(const uint32_t *w, int n) {
    int op = w[0] >> 24;

    if (op == 0x02) {
        return 3;
    }
    if (op >= 0x20 && op < 0x40) {
        int nv = (op & 0x08) ? 4 : 3;
        return 1 + nv * ((op & 0x04) ? 2 : 1) + ((op & 0x10) ? nv - 1 : 0);
    }
    if (op >= 0x40 && op < 0x60) {
        int i;
        if (!(op & 0x08)) {
            return (op & 0x10) ? 4 : 3;
        }
        for (i = 3; i < n; i++) { /* polyline: up to the 0x5xxx5xxx terminator */
            if ((w[i] & 0xF000F000) == 0x50005000) {
                return i + 1;
            }
        }
        return 0;
    }
    if (op >= 0x60 && op < 0x80) {
        return 2 + ((op & 0x04) ? 1 : 0) + (((op >> 3) & 3) == 0 ? 1 : 0);
    }
    if (op >= 0x80 && op < 0xA0) {
        return 4;
    }
    if (op >= 0xA0 && op < 0xC0) {
        int cw, ch;
        if (n < 3) {
            return 0;
        }
        cw = (((w[2] & 0xFFFF) - 1) & 0x3FF) + 1;
        ch = (((w[2] >> 16) - 1) & 0x1FF) + 1;
        return 3 + (cw * ch + 1) / 2;
    }
    if (op >= 0xC0 && op < 0xE0) {
        return 3;
    }
    return 1;
}

static void command(const uint32_t *w) {
    uint32_t c = w[0];
    int op = c >> 24;

    if (op >= 0x20 && op < 0x40) {
        polygon(w, op);
    } else if (op >= 0x60 && op < 0x80) {
        rectangle(w, op);
    } else if (op >= 0x40 && op < 0x60) {
        log_once(op, "line, not drawn yet");
    } else if (op >= 0x80 && op < 0xA0) {
        PsxGpu_MoveImage(w[1] & 0x3FF, (w[1] >> 16) & 0x1FF, w[2] & 0x3FF, (w[2] >> 16) & 0x1FF,
                         (((w[3] & 0xFFFF) - 1) & 0x3FF) + 1, (((w[3] >> 16) - 1) & 0x1FF) + 1);
    } else if (op >= 0xA0 && op < 0xC0) {
        PsxGpu_LoadImage(w[1] & 0x3FF, (w[1] >> 16) & 0x1FF, (((w[2] & 0xFFFF) - 1) & 0x3FF) + 1,
                         (((w[2] >> 16) - 1) & 0x1FF) + 1, (const uint16_t *)&w[3]);
    } else if (op >= 0xC0 && op < 0xE0) {
        log_once(op, "VRAM to CPU in a packet, ignored");
    } else {
        switch (op) {
        case 0x00:
        case 0x01:
            break;
        case 0x02:
            PsxGpu_Fill(w[1] & 0x3F0, (w[1] >> 16) & 0x1FF, ((w[2] & 0x3FF) + 15) & ~15, (w[2] >> 16) & 0x1FF,
                        c & 0xFFFFFF);
            break;
        case 0xE1:
            st.tpage = c & 0x9FF;
            st.dither = (c >> 9) & 1;
            st.draw_disp = (c >> 10) & 1;
            break;
        case 0xE2:
            st.tw_mask_x = (c & 31) * 8;
            st.tw_mask_y = ((c >> 5) & 31) * 8;
            st.tw_off_x = ((c >> 10) & 31) * 8;
            st.tw_off_y = ((c >> 15) & 31) * 8;
            break;
        case 0xE3:
            st.clip_x0 = c & 0x3FF;
            st.clip_y0 = (c >> 10) & 0x1FF;
            break;
        case 0xE4:
            st.clip_x1 = c & 0x3FF;
            st.clip_y1 = (c >> 10) & 0x1FF;
            break;
        case 0xE5:
            st.ofs_x = sign11(c & 0x7FF);
            st.ofs_y = sign11((c >> 11) & 0x7FF);
            break;
        case 0xE6:
            st.set_mask = c & 1;
            st.check_mask = (c >> 1) & 1;
            break;
        default:
            log_once(op, "unhandled command, ignored");
            break;
        }
    }
}

void PsxGpu_Gp0(const uint32_t *words, int count) {
    int i = 0;

    while (i < count) {
        int len = command_len(&words[i], count - i);

        if (len == 0 || i + len > count) {
            log_once(words[i] >> 24, "command cut off at the packet end, dropped");
            return;
        }
        command(&words[i]);
        i += len;
    }
}

/* ---- display ---- */

void PsxGpu_SetDisplay(int x, int y, int w, int h, int rgb24) {
    disp.x = x;
    disp.y = y;
    disp.w = w;
    disp.h = h;
    disp.rgb24 = rgb24;
}

void PsxGpu_SetDisplayEnable(int on) {
    disp.on = on;
}

int PsxGpu_ReadDisplay(uint32_t *out, int *pw, int *ph) {
    int w = disp.w < 1 ? 1 : disp.w > 640 ? 640 : disp.w;
    int h = disp.h < 1 ? 1 : disp.h > 480 ? 480 : disp.h; /* NTSC: at most 480 visible lines */
    int x, y;

    if (!disp.on) {
        return 0;
    }
    for (y = 0; y < h; y++) {
        const uint16_t *row = PsxGpu_Vram[(disp.y + y) & (PSXGPU_VRAM_H - 1)];
        uint32_t *o = out + y * w;

        if (disp.rgb24) {
            const uint8_t *bytes = (const uint8_t *)row;
            for (x = 0; x < w; x++) {
                int i = disp.x * 2 + x * 3;
                o[x] = ((uint32_t)bytes[i & 2047] << 16) | ((uint32_t)bytes[(i + 1) & 2047] << 8) | bytes[(i + 2) & 2047];
            }
        } else {
            for (x = 0; x < w; x++) {
                uint16_t c = row[(disp.x + x) & (PSXGPU_VRAM_W - 1)];
                uint32_t r = c & 31, g = (c >> 5) & 31, b = (c >> 10) & 31;
                o[x] = (((r << 3) | (r >> 2)) << 16) | (((g << 3) | (g >> 2)) << 8) | ((b << 3) | (b >> 2));
            }
        }
    }
    *pw = w;
    *ph = h;
    return 1;
}
