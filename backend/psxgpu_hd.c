#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL3/SDL.h>

#include "backend/psxgpu.h"
#include "backend/psxgpu_hd.h"

/* HD surfaces (PG.1). A surface is one draw / display buffer rect of VRAM kept at S x S pixels
 * per VRAM pixel in the PS1 format (15-bit BGR + mask bit). Primitives are drawn into it at
 * that resolution with the PS1 rules applied per pixel of the surface; textures and CLUTs come
 * from the 1x VRAM. Positions inside a surface: pixel (X, Y) samples the VRAM point
 * (x + X / S, y + Y / S), so a 1x pixel is the S x S block whose first pixel samples the same
 * point as the PS1 does. Vertex positions are fixed point with SUB fraction bits.
 *
 * Primitives are queued (with the drawing state they saw) and drawn at the next flush: before
 * any transfer, surface change or display read. A flush splits the surface rows between worker
 * threads (row Y goes to part Y % parts), every part walks the whole queue in order, so each
 * pixel sees the primitives in packet order and the result does not depend on the thread
 * count. */

#define MAX_SURF 4
#define SUB 4

typedef struct {
    int x, y, w, h; /* VRAM rect */
    uint16_t *px;   /* w*S x h*S, NULL until used */
} Surf;

static Surf surf[MAX_SURF];
static int nsurf;
static int scale = 1;
static unsigned serial;

/* PS1 dither offsets by (y & 3, x & 3), as in backend/psxgpu.c. */
static const int dither_tbl[4][4] = {
    { -4, 0, -3, 1 },
    { 2, -2, 3, -1 },
    { -3, 1, -4, 0 },
    { 3, -1, 2, -2 },
};

/* ---- surfaces ---- */

static void drop(int i) {
    free(surf[i].px);
    memmove(&surf[i], &surf[i + 1], (size_t)(nsurf - i - 1) * sizeof(Surf));
    nsurf--;
}

static void release_all(void) {
    int i;

    for (i = 0; i < nsurf; i++) {
        free(surf[i].px);
        surf[i].px = NULL;
    }
}

/* Surface pixels from the 1x VRAM (nearest) for the VRAM rect x, y, w, h inside s. */
static void copy_from_vram(Surf *s, int x, int y, int w, int h) {
    int pitch = s->w * scale;
    int i, j, k;

    for (j = y; j < y + h; j++) {
        const uint16_t *src = PsxGpu_Vram[j & (PSXGPU_VRAM_H - 1)];
        uint16_t *row = s->px + (size_t)(j - s->y) * scale * pitch;
        for (i = x; i < x + w; i++) {
            uint16_t c = src[i & (PSXGPU_VRAM_W - 1)];
            uint16_t *d = row + (size_t)(i - s->x) * scale;
            for (k = 0; k < scale; k++) {
                d[k] = c;
            }
        }
        for (k = 1; k < scale; k++) {
            memcpy(row + (size_t)k * pitch + (size_t)(x - s->x) * scale, row + (size_t)(x - s->x) * scale,
                   (size_t)w * scale * sizeof(uint16_t));
        }
    }
}

static int ensure(Surf *s) {
    if (s->px == NULL) {
        s->px = malloc((size_t)s->w * scale * s->h * scale * sizeof(uint16_t));
        if (s->px == NULL) {
            printf("[gpu] HD surface %dx%d at %dx: out of memory\n", s->w, s->h, scale);
            return 0;
        }
        copy_from_vram(s, s->x, s->y, s->w, s->h);
    }
    return 1;
}

/* ---- queue and worker threads ---- */

enum { CMD_TRI, CMD_RECT, CMD_LINE };

typedef struct {
    int type;
    Surf *s;
    PsxGpuState st;
    PsxVtx v[3];
    PsxTex tex;
    int textured, gouraud, semi, abr;
    int x0, y0, w, h, u0, v0, r, g, b; /* rectangles */
} Cmd;

static Cmd *queue;
static int queued, queue_cap;
static int threads_wanted; /* 0 = automatic */
static int parts = 1;      /* worker threads + the calling thread */

typedef struct {
    SDL_Thread *thread;
    SDL_Semaphore *go;
    int part;
} Worker;

static Worker workers[15];
static int nworkers;
static SDL_Semaphore *done;

static void draw_tri(const Cmd *c, int part, int parts);
static void draw_rect(const Cmd *c, int part, int parts);
static void draw_line(const Cmd *c, int part, int parts);

static void run_part(int part) {
    int i;

    for (i = 0; i < queued; i++) {
        const Cmd *c = &queue[i];
        switch (c->type) {
        case CMD_TRI:
            draw_tri(c, part, parts);
            break;
        case CMD_RECT:
            draw_rect(c, part, parts);
            break;
        default:
            draw_line(c, part, parts);
            break;
        }
    }
}

static int worker_main(void *arg) {
    Worker *w = arg;

    for (;;) {
        SDL_WaitSemaphore(w->go);
        if (w->part < 0) {
            return 0;
        }
        run_part(w->part);
        SDL_SignalSemaphore(done);
    }
}

static void start_workers(void) {
    int n = threads_wanted;
    int i;

    if (n <= 0) {
        n = SDL_GetNumLogicalCPUCores();
        n = n > 8 ? 8 : n;
    }
    n = n < 1 ? 1 : n > 16 ? 16 : n;
    done = SDL_CreateSemaphore(0);
    for (i = 0; i < n - 1 && done != NULL; i++) {
        Worker *w = &workers[nworkers];
        w->part = nworkers + 1;
        w->go = SDL_CreateSemaphore(0);
        if (w->go == NULL) {
            break;
        }
        w->thread = SDL_CreateThread(worker_main, "hd", w);
        if (w->thread == NULL) {
            SDL_DestroySemaphore(w->go);
            break;
        }
        nworkers++;
    }
    parts = nworkers + 1;
    printf("[gpu] HD: %d drawing thread%s\n", parts, parts == 1 ? "" : "s");
}

/* Draws the queue into the surfaces. */
static void flush(void) {
    int i;

    if (queued == 0) {
        return;
    }
    if (done == NULL) {
        start_workers();
    }
    for (i = 0; i < nworkers; i++) {
        SDL_SignalSemaphore(workers[i].go);
    }
    run_part(0);
    for (i = 0; i < nworkers; i++) {
        SDL_WaitSemaphore(done);
    }
    queued = 0;
}

static Cmd *push(int type, Surf *s, const PsxGpuState *st) {
    Cmd *c;

    if (queued == queue_cap) {
        int cap = queue_cap ? queue_cap * 2 : 4096;
        Cmd *q = realloc(queue, (size_t)cap * sizeof(Cmd));
        if (q == NULL) {
            flush();
        } else {
            queue = q;
            queue_cap = cap;
        }
    }
    c = &queue[queued++];
    c->type = type;
    c->s = s;
    c->st = *st;
    return c;
}

void PsxHd_SetThreads(int n) {
    threads_wanted = n;
}

void PsxHd_SetScale(int s) {
    s = s < 1 ? 1 : s > 8 ? 8 : s;
    if (s != scale) {
        flush();
        release_all();
        scale = s;
        serial++;
    }
}

int PsxHd_Scale(void) {
    return scale;
}

int PsxHd_On(void) {
    return scale > 1;
}

static int contains(const Surf *s, int x, int y, int w, int h) {
    return x >= s->x && y >= s->y && x + w <= s->x + s->w && y + h <= s->y + s->h;
}

void PsxHd_Register(int x, int y, int w, int h) {
    int i;

    if (w <= 0 || h <= 0) {
        return;
    }
    flush();
    serial++; /* a flip: the display may show another buffer now */
    for (i = 0; i < nsurf; i++) {
        if (contains(&surf[i], x, y, w, h)) {
            return;
        }
    }
    for (i = nsurf - 1; i >= 0; i--) {
        Surf *s = &surf[i];
        if (x < s->x + s->w && s->x < x + w && y < s->y + s->h && s->y < y + h) {
            drop(i);
        }
    }
    if (nsurf == MAX_SURF) {
        drop(0);
    }
    surf[nsurf].x = x;
    surf[nsurf].y = y;
    surf[nsurf].w = w;
    surf[nsurf].h = h;
    surf[nsurf].px = NULL;
    nsurf++;
    serial++;
}

/* The surface holding the current draw area (allocated), or NULL. */
static Surf *target(const PsxGpuState *st) {
    static int missed;
    int i;

    for (i = 0; i < nsurf; i++) {
        Surf *s = &surf[i];
        if (contains(s, st->clip_x0, st->clip_y0, st->clip_x1 - st->clip_x0 + 1, st->clip_y1 - st->clip_y0 + 1)) {
            serial++;
            return ensure(s) ? s : NULL;
        }
    }
    if (!missed) {
        missed = 1;
        printf("[gpu] HD: draw area %d,%d..%d,%d is in no surface, drawn at 1x only (logged once)\n", st->clip_x0,
               st->clip_y0, st->clip_x1, st->clip_y1);
    }
    return NULL;
}

/* Clip rect of the current draw area in surface pixels, inclusive. */
static void hd_clip(const PsxGpuState *st, const Surf *s, int *x0, int *y0, int *x1, int *y1) {
    *x0 = (st->clip_x0 - s->x) * scale;
    *y0 = (st->clip_y0 - s->y) * scale;
    *x1 = (st->clip_x1 + 1 - s->x) * scale - 1;
    *y1 = (st->clip_y1 + 1 - s->y) * scale - 1;
}

/* ---- pixels ---- */

static void hput(const PsxGpuState *st, uint16_t *d, int r, int g, int b, int semi, int abr, int mask) {
    if (st->check_mask && (*d & 0x8000)) {
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
    *d = (uint16_t)(r | (g << 5) | (b << 10) | ((mask || st->set_mask) ? 0x8000 : 0));
}

static uint16_t texel(const PsxGpuState *st, const PsxTex *t, int u, int v) {
    int y;

    u = ((u & ~st->tw_mask_x) | (st->tw_off_x & st->tw_mask_x)) & 0xFF;
    v = ((v & ~st->tw_mask_y) | (st->tw_off_y & st->tw_mask_y)) & 0xFF;
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

static int to5(int c8, int d) {
    c8 += d;
    c8 = c8 < 0 ? 0 : c8 > 255 ? 255 : c8;
    return c8 >> 3;
}

/* One pixel of a primitive (see shade() in backend/psxgpu.c); d = dither offset or 0. */
static void hshade(const PsxGpuState *st, uint16_t *p, const PsxTex *t, int u, int v, int r, int g, int b, int semi,
                   int abr, int d) {
    if (t != NULL) {
        uint16_t c = texel(st, t, u, v);
        int tr, tg, tb;

        if (c == 0) {
            return;
        }
        tr = c & 31;
        tg = (c >> 5) & 31;
        tb = (c >> 10) & 31;
        if (!t->raw) {
            tr = to5((tr * r) >> 4, d);
            tg = to5((tg * g) >> 4, d);
            tb = to5((tb * b) >> 4, d);
        }
        hput(st, p, tr, tg, tb, semi && (c & 0x8000), abr, c & 0x8000);
    } else {
        hput(st, p, to5(r, d), to5(g, d), to5(b, d), semi, abr, 0);
    }
}

/* ---- triangles ---- */

static int64_t fdiv(int64_t a, int64_t b) {
    int64_t q = a / b;

    if ((a % b) != 0 && ((a < 0) != (b < 0))) {
        q--;
    }
    return q;
}

static int64_t cdiv(int64_t a, int64_t b) {
    return -fdiv(-a, b);
}

typedef struct {
    int64_t ax, ay, dx, dy; /* edge from (ax, ay) by (dx, dy), fixed point */
    int thr;                /* 0 on a top / left edge (included on ties), else 1 */
} Edge;

static void make_edge(Edge *e, int64_t ax, int64_t ay, int64_t bx, int64_t by) {
    e->ax = ax;
    e->ay = ay;
    e->dx = bx - ax;
    e->dy = by - ay;
    e->thr = (e->dy < 0 || (e->dy == 0 && e->dx > 0)) ? 0 : 1;
}

/* Edge function at pixel column 0 of row Y, and its step per column. */
static int64_t edge_row(const Edge *e, int Y) {
    return e->dx * (((int64_t)Y << SUB) - e->ay) + e->dy * e->ax;
}

static int64_t edge_step(const Edge *e) {
    return -(e->dy << SUB);
}

void PsxHd_Triangle(const PsxGpuState *st, const PsxVtx *v0, const PsxVtx *v1, const PsxVtx *v2, int gouraud,
                    const PsxTex *t, int semi, int abr) {
    int minx1, maxx1, miny1, maxy1;
    Surf *s;
    Cmd *c;

    /* the 1x rejections (backend/psxgpu.c triangle) */
    minx1 = v0->x < v1->x ? v0->x : v1->x;
    minx1 = v2->x < minx1 ? v2->x : minx1;
    maxx1 = v0->x > v1->x ? v0->x : v1->x;
    maxx1 = v2->x > maxx1 ? v2->x : maxx1;
    miny1 = v0->y < v1->y ? v0->y : v1->y;
    miny1 = v2->y < miny1 ? v2->y : miny1;
    maxy1 = v0->y > v1->y ? v0->y : v1->y;
    maxy1 = v2->y > maxy1 ? v2->y : maxy1;
    if (maxx1 - minx1 >= 1024 || maxy1 - miny1 >= 512) {
        return;
    }
    if ((int64_t)(v1->x - v0->x) * (v2->y - v0->y) - (int64_t)(v1->y - v0->y) * (v2->x - v0->x) == 0) {
        return;
    }
    s = target(st);
    if (s == NULL) {
        return;
    }
    c = push(CMD_TRI, s, st);
    c->v[0] = *v0;
    c->v[1] = *v1;
    c->v[2] = *v2;
    c->textured = t != NULL;
    if (t != NULL) {
        c->tex = *t;
    }
    c->gouraud = gouraud;
    c->semi = semi;
    c->abr = abr;
}

static void draw_tri(const Cmd *c, int part, int parts) {
    const PsxGpuState *st = &c->st;
    const PsxVtx *v0 = &c->v[0], *v1 = &c->v[1], *v2 = &c->v[2];
    const PsxTex *t = c->textured ? &c->tex : NULL;
    int gouraud = c->gouraud, semi = c->semi, abr = c->abr;
    Surf *s = c->s;
    const PsxVtx *v[3];
    int64_t px[3], py[3], area, a1;
    int64_t step[3], nr[3], dn[5], att[5][3];
    Edge e[3];
    int pitch, cx0, cy0, cx1, cy1;
    int miny, maxy, Y, i, k, natt;
    int dith = st->dither && (gouraud || (t != NULL && !t->raw));
    int block = 0;
    int umin = 0, umax = 0;

    a1 = (int64_t)(v1->x - v0->x) * (v2->y - v0->y) - (int64_t)(v1->y - v0->y) * (v2->x - v0->x);
    v[0] = v0;
    if (a1 < 0) {
        v[1] = v2;
        v[2] = v1;
    } else {
        v[1] = v1;
        v[2] = v2;
    }
    for (i = 0; i < 3; i++) {
        px[i] = (int64_t)(v[i]->x - s->x) * scale << SUB;
        py[i] = (int64_t)(v[i]->y - s->y) * scale << SUB;
    }
    make_edge(&e[0], px[1], py[1], px[2], py[2]);
    make_edge(&e[1], px[2], py[2], px[0], py[0]);
    make_edge(&e[2], px[0], py[0], px[1], py[1]);
    area = e[2].dx * (py[2] - py[0]) - e[2].dy * (px[2] - px[0]);
    if (area <= 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        step[i] = edge_step(&e[i]);
    }

    /* attributes: 0 r, 1 g, 2 b, 3 u, 4 v */
    natt = 0;
    for (i = 0; i < 3; i++) {
        att[0][i] = v[i]->r;
        att[1][i] = v[i]->g;
        att[2][i] = v[i]->b;
        att[3][i] = v[i]->u;
        att[4][i] = v[i]->v;
    }
    for (k = 0; k < 5; k++) {
        dn[k] = att[k][0] * step[0] + att[k][1] * step[1] + att[k][2] * step[2];
    }
    if (t != NULL) {
        /* No cross terms (du / dy = dv / dx = 0): a 2D sprite-like mapping. Its texels are read
         * at the 1x pixel's position so pixel art stays exact at any scale. */
        int64_t dudy = att[3][0] * e[0].dx + att[3][1] * e[1].dx + att[3][2] * e[2].dx;
        block = dudy == 0 && dn[4] == 0;
        umin = v[0]->u < v[1]->u ? v[0]->u : v[1]->u;
        umin = v[2]->u < umin ? v[2]->u : umin;
        umax = v[0]->u > v[1]->u ? v[0]->u : v[1]->u;
        umax = v[2]->u > umax ? v[2]->u : umax;
    }
    natt = gouraud ? 3 : 0;

    pitch = s->w * scale;
    hd_clip(st, s, &cx0, &cy0, &cx1, &cy1);
    if (cx0 < 0) cx0 = 0;
    if (cy0 < 0) cy0 = 0;
    if (cx1 > pitch - 1) cx1 = pitch - 1;
    if (cy1 > s->h * scale - 1) cy1 = s->h * scale - 1;
    miny = (int)cdiv(py[0] < py[1] ? (py[0] < py[2] ? py[0] : py[2]) : (py[1] < py[2] ? py[1] : py[2]), 1 << SUB);
    maxy = (int)fdiv(py[0] > py[1] ? (py[0] > py[2] ? py[0] : py[2]) : (py[1] > py[2] ? py[1] : py[2]), 1 << SUB);
    if (miny < cy0) miny = cy0;
    if (maxy > cy1) maxy = cy1;

    if (miny > maxy) {
        return;
    }
    for (Y = miny + ((part - miny % parts) % parts + parts) % parts; Y <= maxy; Y += parts) {
        int64_t xl = cx0, xr = cx1;
        int64_t c24[3], d24[3];
        int64_t vrow = 0;
        uint16_t *row = s->px + (size_t)Y * pitch;
        int X, bx, sub, dy;
        int r = v[0]->r, g = v[0]->g, b = v[0]->b, u = 0, vv = 0;
        int64_t u24 = 0, v24 = 0, du24 = 0, dv24 = 0;

        for (i = 0; i < 3; i++) {
            nr[i] = edge_row(&e[i], Y);
            if (step[i] > 0) {
                int64_t lo = cdiv(e[i].thr - nr[i], step[i]);
                if (lo > xl) xl = lo;
            } else if (step[i] < 0) {
                int64_t hi = fdiv(nr[i] - e[i].thr, -step[i]);
                if (hi < xr) xr = hi;
            } else if (nr[i] < e[i].thr) {
                xl = 1;
                xr = 0;
            }
        }
        if (xl > xr) {
            continue;
        }
        /* attribute numerators at xl: sum att * edge; value = numerator / area */
        for (k = 0; k < natt; k++) {
            int64_t n = att[k][0] * (nr[0] + step[0] * xl) + att[k][1] * (nr[1] + step[1] * xl) +
                        att[k][2] * (nr[2] + step[2] * xl);
            c24[k] = (fdiv(n << 16, area) << 8) + 0x80;
            d24[k] = fdiv(dn[k] << 24, area);
        }
        if (t != NULL && !block) {
            int64_t nu = att[3][0] * (nr[0] + step[0] * xl) + att[3][1] * (nr[1] + step[1] * xl) +
                         att[3][2] * (nr[2] + step[2] * xl);
            int64_t nv = att[4][0] * (nr[0] + step[0] * xl) + att[4][1] * (nr[1] + step[1] * xl) +
                         att[4][2] * (nr[2] + step[2] * xl);
            u24 = (fdiv(nu << 16, area) << 8) + 0x80;
            v24 = (fdiv(nv << 16, area) << 8) + 0x80;
            du24 = fdiv(dn[3] << 24, area);
            dv24 = fdiv(dn[4] << 24, area);
        } else if (t != NULL) {
            /* v from the row of the 1x pixel (constant along the row) */
            int yb = Y - Y % scale;
            int64_t n = 0;
            for (i = 0; i < 3; i++) {
                n += att[4][i] * edge_row(&e[i], yb);
            }
            vrow = fdiv(n, area);
            vv = (int)vrow;
        }
        dy = (Y / scale) & 3;
        bx = (int)xl / scale;
        sub = (int)xl % scale;
        u = -1;
        for (X = (int)xl; X <= (int)xr; X++) {
            int d = dith ? dither_tbl[dy][bx & 3] : 0;

            if (natt) {
                r = (int)(c24[0] >> 24);
                g = (int)(c24[1] >> 24);
                b = (int)(c24[2] >> 24);
                r = r < 0 ? 0 : r > 255 ? 255 : r;
                g = g < 0 ? 0 : g > 255 ? 255 : g;
                b = b < 0 ? 0 : b > 255 ? 255 : b;
            }
            if (t != NULL) {
                if (block) {
                    if (sub == 0 || u < 0) {
                        int64_t xb = (int64_t)bx * scale;
                        int64_t n = att[3][0] * (nr[0] + step[0] * xb) + att[3][1] * (nr[1] + step[1] * xb) +
                                    att[3][2] * (nr[2] + step[2] * xb);
                        u = (int)fdiv(n, area);
                        u = u < umin ? umin : u > umax ? umax : u;
                    }
                } else {
                    u = (int)(u24 >> 24);
                    vv = (int)(v24 >> 24);
                }
            }
            hshade(st, row + X, t, u, vv, r, g, b, semi, abr, d);
            for (k = 0; k < natt; k++) {
                c24[k] += d24[k];
            }
            u24 += du24;
            v24 += dv24;
            if (++sub == scale) {
                sub = 0;
                bx++;
            }
        }
    }
}

/* ---- rectangles ---- */

void PsxHd_Rect(const PsxGpuState *st, int x0, int y0, int w, int h, const PsxTex *t, int u0, int v0, int r, int g,
                int b, int semi, int abr) {
    Surf *s = target(st);
    Cmd *c;

    if (s == NULL || w <= 0 || h <= 0) {
        return;
    }
    c = push(CMD_RECT, s, st);
    c->x0 = x0;
    c->y0 = y0;
    c->w = w;
    c->h = h;
    c->textured = t != NULL;
    if (t != NULL) {
        c->tex = *t;
    }
    c->u0 = u0;
    c->v0 = v0;
    c->r = r;
    c->g = g;
    c->b = b;
    c->semi = semi;
    c->abr = abr;
}

static void draw_rect(const Cmd *c, int part, int parts) {
    const PsxGpuState *st = &c->st;
    const PsxTex *t = c->textured ? &c->tex : NULL;
    Surf *s = c->s;
    int x0 = c->x0, y0 = c->y0, w = c->w, h = c->h, u0 = c->u0, v0 = c->v0;
    int r = c->r, g = c->g, b = c->b, semi = c->semi, abr = c->abr;
    int pitch, cx0, cy0, cx1, cy1;
    int X, Y, xs, xe, ys, ye;

    pitch = s->w * scale;
    hd_clip(st, s, &cx0, &cy0, &cx1, &cy1);
    if (cx0 < 0) cx0 = 0;
    if (cy0 < 0) cy0 = 0;
    if (cx1 > pitch - 1) cx1 = pitch - 1;
    if (cy1 > s->h * scale - 1) cy1 = s->h * scale - 1;
    xs = (x0 - s->x) * scale;
    xe = (x0 + w - s->x) * scale - 1;
    ys = (y0 - s->y) * scale;
    ye = (y0 + h - s->y) * scale - 1;
    if (xs < cx0) xs = cx0;
    if (xe > cx1) xe = cx1;
    if (ys < cy0) ys = cy0;
    if (ye > cy1) ye = cy1;
    if (ys > ye) {
        return;
    }
    for (Y = ys + ((part - ys % parts) % parts + parts) % parts; Y <= ye; Y += parts) {
        uint16_t *row = s->px + (size_t)Y * pitch;
        int yy = Y / scale + s->y - y0;
        int tv = st->flip_y ? v0 - yy : v0 + yy;

        for (X = xs; X <= xe; X++) {
            int xx = X / scale + s->x - x0;
            hshade(st, row + X, t, st->flip_x ? u0 - xx : u0 + xx, tv, r, g, b, semi, abr, 0);
        }
    }
}

/* ---- lines ---- */

/* A line S pixels thick: along the longer axis every surface column (or row) from the first
 * 1x end pixel's block to the last one's, the other axis interpolated between the block
 * centres. Colour interpolated the same way, dithered by the 1x pixel. */
void PsxHd_Line(const PsxGpuState *st, const PsxVtx *a, const PsxVtx *b, int gouraud, int semi, int abr) {
    int dx = b->x - a->x, dy = b->y - a->y;
    Surf *s;
    Cmd *c;

    if (dx <= -1024 || dx >= 1024 || dy <= -512 || dy >= 512) {
        return;
    }
    s = target(st);
    if (s == NULL) {
        return;
    }
    c = push(CMD_LINE, s, st);
    c->v[0] = *a;
    c->v[1] = *b;
    c->gouraud = gouraud;
    c->semi = semi;
    c->abr = abr;
}

static void draw_line(const Cmd *c, int part, int parts) {
    const PsxGpuState *st = &c->st;
    const PsxVtx *a = &c->v[0], *b = &c->v[1];
    int gouraud = c->gouraud, semi = c->semi, abr = c->abr;
    Surf *s = c->s;
    int dx = b->x - a->x, dy = b->y - a->y;
    int adx = dx < 0 ? -dx : dx, ady = dy < 0 ? -dy : dy;
    int xmajor = adx >= ady;
    int dith = st->dither && gouraud;
    int pitch, cx0, cy0, cx1, cy1;
    int64_t ac, bc, aw, bw, len;
    int m, m0, m1, j;

    pitch = s->w * scale;
    hd_clip(st, s, &cx0, &cy0, &cx1, &cy1);
    if (cx0 < 0) cx0 = 0;
    if (cy0 < 0) cy0 = 0;
    if (cx1 > pitch - 1) cx1 = pitch - 1;
    if (cy1 > s->h * scale - 1) cy1 = s->h * scale - 1;
    /* major axis centres ac -> bc, minor axis centres aw -> bw (surface pixels) */
    if (xmajor) {
        ac = (int64_t)(a->x - s->x) * scale + scale / 2;
        bc = (int64_t)(b->x - s->x) * scale + scale / 2;
        aw = (int64_t)(a->y - s->y) * scale + scale / 2;
        bw = (int64_t)(b->y - s->y) * scale + scale / 2;
    } else {
        ac = (int64_t)(a->y - s->y) * scale + scale / 2;
        bc = (int64_t)(b->y - s->y) * scale + scale / 2;
        aw = (int64_t)(a->x - s->x) * scale + scale / 2;
        bw = (int64_t)(b->x - s->x) * scale + scale / 2;
    }
    len = bc - ac;
    m0 = (int)((ac < bc ? ac : bc) - scale / 2);
    m1 = (int)((ac < bc ? bc : ac) - scale / 2 + scale - 1);
    for (m = m0; m <= m1; m++) {
        int64_t tn = len == 0 ? 0 : (m - ac);
        int64_t w;
        int r = a->r, g = a->g, bl = a->b;

        if (len != 0) {
            int64_t l = len < 0 ? -len : len;
            if (len < 0) tn = -tn;
            tn = tn < 0 ? 0 : tn > l ? l : tn;
            w = aw + fdiv((bw - aw) * tn * 2 + l, 2 * l);
            if (gouraud) {
                r = a->r + (int)((int64_t)(b->r - a->r) * tn / l);
                g = a->g + (int)((int64_t)(b->g - a->g) * tn / l);
                bl = a->b + (int)((int64_t)(b->b - a->b) * tn / l);
            }
        } else {
            w = aw;
        }
        for (j = 0; j < scale; j++) {
            int X, Y, d;
            int64_t q = w - scale / 2 + j;

            if (xmajor) {
                X = m;
                Y = (int)q;
            } else {
                X = (int)q;
                Y = m;
            }
            if (X < cx0 || X > cx1 || Y < cy0 || Y > cy1 || Y % parts != part) {
                continue;
            }
            d = dith ? dither_tbl[(Y / scale) & 3][(X / scale) & 3] : 0;
            hput(st, s->px + (size_t)Y * pitch + X, to5(r, d), to5(g, d), to5(bl, d), semi, abr, 0);
        }
    }
}

/* ---- transfers ---- */

/* Intersection of a VRAM rect with surface s (no wrap: the game's transfers stay inside VRAM). */
static int clip_rect(const Surf *s, int *x, int *y, int *w, int *h) {
    int x0 = *x > s->x ? *x : s->x;
    int y0 = *y > s->y ? *y : s->y;
    int x1 = *x + *w < s->x + s->w ? *x + *w : s->x + s->w;
    int y1 = *y + *h < s->y + s->h ? *y + *h : s->y + s->h;

    if (x1 <= x0 || y1 <= y0) {
        return 0;
    }
    *x = x0;
    *y = y0;
    *w = x1 - x0;
    *h = y1 - y0;
    return 1;
}

void PsxHd_Fill(int x, int y, int w, int h, uint16_t c) {
    int i;

    flush();
    for (i = 0; i < nsurf; i++) {
        Surf *s = &surf[i];
        int fx = x, fy = y, fw = w, fh = h, j, k;
        int pitch = s->w * scale;

        if (s->px == NULL || !clip_rect(s, &fx, &fy, &fw, &fh)) {
            continue;
        }
        for (j = (fy - s->y) * scale; j < (fy + fh - s->y) * scale; j++) {
            uint16_t *row = s->px + (size_t)j * pitch;
            for (k = (fx - s->x) * scale; k < (fx + fw - s->x) * scale; k++) {
                row[k] = c;
            }
        }
        serial++;
    }
}

void PsxHd_Refresh(int x, int y, int w, int h) {
    int i;

    flush();
    for (i = 0; i < nsurf; i++) {
        Surf *s = &surf[i];
        int fx = x, fy = y, fw = w, fh = h;

        if (s->px == NULL || !clip_rect(s, &fx, &fy, &fw, &fh)) {
            continue;
        }
        copy_from_vram(s, fx, fy, fw, fh);
        serial++;
    }
}

/* ---- display ---- */

int PsxHd_ReadDisplay(int x, int y, int w, int h, uint32_t *out, int *ow, int *oh) {
    int i, X, Y;

    if (!PsxHd_On()) {
        return 0;
    }
    flush();
    for (i = 0; i < nsurf; i++) {
        Surf *s = &surf[i];
        int pitch = s->w * scale;

        if (!contains(s, x, y, w, h) || !ensure(s)) {
            continue;
        }
        *ow = w * scale;
        *oh = h * scale;
        if (out == NULL) {
            return 1;
        }
        for (Y = 0; Y < h * scale; Y++) {
            const uint16_t *row = s->px + (size_t)((y - s->y) * scale + Y) * pitch + (size_t)(x - s->x) * scale;
            uint32_t *o = out + (size_t)Y * w * scale;
            for (X = 0; X < w * scale; X++) {
                uint16_t c = row[X];
                uint32_t r = c & 31, g = (c >> 5) & 31, b = (c >> 10) & 31;
                o[X] = (((r << 3) | (r >> 2)) << 16) | (((g << 3) | (g >> 2)) << 8) | ((b << 3) | (b >> 2));
            }
        }
        return 1;
    }
    return 0;
}

unsigned PsxHd_Serial(void) {
    return serial;
}
