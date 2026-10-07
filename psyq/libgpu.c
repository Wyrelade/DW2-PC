#include <stdio.h>

#include "backend/pgxp.h"
#include "backend/psxgpu.h"
#include "backend/psxgpu_hd.h"
#include "host/host.h"
#include "libgpu.h"
#include "ps1mem.h"
#include "psyq_log.h"

/* libgpu on the emulated GPU (backend/psxgpu.c, P1.4). Drawing runs at once (no queue):
 * DrawSync has nothing to wait for. DrawOTag walks the 24-bit links through the 16 MB window
 * (psyq/ps1mem.h) and hands each packet body to GP0. The packet helpers (AddPrim, SetPolyF4,
 * SetDrawMove, SetDrawMode) write the Psy-Q packet layouts. */

static u_long draw_mode(int dfe, int dtd, int tpage) {
    return 0xE1000000 | (dtd ? 0x200 : 0) | (dfe ? 0x400 : 0) | (tpage & 0x9FF);
}

static u_long tex_window(const RECT *tw) {
    if (tw == 0) {
        return 0;
    }
    return 0xE2000000 | (((tw->y & 0xFF) >> 3) << 15) | (((tw->x & 0xFF) >> 3) << 10) |
           ((((~(tw->h - 1)) & 0xFF) >> 3) << 5) | (((~(tw->w - 1)) & 0xFF) >> 3);
}

static void set_len(void *p, int len) {
    u_long *tag = p;

    *tag = (*tag & 0xFFFFFF) | ((u_long)len << 24);
}

int ResetGraph(int mode) {
    PSYQ_LOG("%d", mode);
    /* 0: full reset (display off), 3: reset keeping the environments, 1: cancel drawing. */
    if (mode == 0 || mode == 3) {
        PsxGpu_Reset(mode == 0);
    }
    return 0;
}

int SetGraphDebug(int level) {
    PSYQ_LOG("%d", level);
    return 0;
}

void SetDispMask(int mask) {
    PSYQ_LOG("%d", mask);
    PsxGpu_SetDisplayEnable(mask != 0);
    if (mask != 0) {
        Host_DisplayOn();
    }
}

int DrawSync(int mode) {
    PSYQ_LOG("%d", mode);
    return 0; /* drawing is done when the call that issued it returns */
}

int ClearImage(RECT *rect, u_char r, u_char g, u_char b) {
    PSYQ_LOG("{%d,%d,%d,%d}, %u, %u, %u", rect->x, rect->y, rect->w, rect->h, r, g, b);
    PsxGpu_Fill(rect->x, rect->y, rect->w, rect->h, r | (g << 8) | (b << 16));
    return 0;
}

/* The interlace variant: the same fill on a PC (no field to skip). */
int ClearImage2(RECT *rect, u_char r, u_char g, u_char b) {
    PSYQ_LOG("{%d,%d,%d,%d}, %u, %u, %u", rect->x, rect->y, rect->w, rect->h, r, g, b);
    PsxGpu_Fill(rect->x, rect->y, rect->w, rect->h, r | (g << 8) | (b << 16));
    return 0;
}

int LoadImage(RECT *rect, u_long *p) {
    PSYQ_LOG("{%d,%d,%d,%d}, %p", rect->x, rect->y, rect->w, rect->h, (void *)p);
    PsxGpu_LoadImage(rect->x, rect->y, rect->w, rect->h, (const uint16_t *)p);
    return 0;
}

int StoreImage(RECT *rect, u_long *p) {
    PSYQ_LOG("{%d,%d,%d,%d}, %p", rect->x, rect->y, rect->w, rect->h, (void *)p);
    PsxGpu_StoreImage(rect->x, rect->y, rect->w, rect->h, (uint16_t *)p);
    return 0;
}

int MoveImage(RECT *rect, int x, int y) {
    PSYQ_LOG("{%d,%d,%d,%d}, %d, %d", rect->x, rect->y, rect->w, rect->h, x, y);
    PsxGpu_MoveImage(rect->x, rect->y, x, y, rect->w, rect->h);
    return 0;
}

/* Reverse ordering table: ot[0] is the end tag, ot[i] links to ot[i - 1] (24-bit address, the
 * PS1 tag format; see psyq/ps1mem.h for the 16 MB window). */
u_long *ClearOTagR(u_long *ot, int n) {
    int i;

    PSYQ_LOG("%p, %d", (void *)ot, n);
    for (i = n - 1; i > 0; i--) {
        ot[i] = (u_long)(uintptr_t)&ot[i - 1] & 0xFFFFFF;
    }
    ot[0] = 0xFFFFFF;
    return ot;
}

/* Packet list walk: tag = len << 24 | next (24 bits, 0xFFFFFF ends the list). */
void DrawOTag(u_long *p) {
    unsigned int n = 0;

    PSYQ_LOG("%p", (void *)p);
    for (;;) {
        u_long tag = *p;
        int len = tag >> 24;

        if (len != 0) {
            PsxGpu_Gp0((const uint32_t *)(p + 1), len);
        }
        if ((tag & 0xFFFFFF) == 0xFFFFFF) {
            break;
        }
        p = PS1_LINK_PTR(tag);
        if (++n == 0x100000) {
            printf("[gpu] DrawOTag: more than 0x100000 packets, list loops? Stopped.\n");
            break;
        }
    }
    Pgxp_EndFrame();
}

DRAWENV *PutDrawEnv(DRAWENV *env) {
    u_long cmd[6];
    int x0 = env->clip.x, y0 = env->clip.y;
    int x1 = x0 + env->clip.w - 1, y1 = y0 + env->clip.h - 1;

    PSYQ_LOG("%p", (void *)env);
    x0 = x0 < 0 ? 0 : x0 > 1023 ? 1023 : x0;
    x1 = x1 < 0 ? 0 : x1 > 1023 ? 1023 : x1;
    y0 = y0 < 0 ? 0 : y0 > 511 ? 511 : y0;
    y1 = y1 < 0 ? 0 : y1 > 511 ? 511 : y1;
    cmd[0] = 0xE3000000 | (y0 << 10) | x0;
    cmd[1] = 0xE4000000 | (y1 << 10) | x1;
    cmd[2] = 0xE5000000 | ((env->ofs[1] & 0x7FF) << 11) | (env->ofs[0] & 0x7FF);
    cmd[3] = draw_mode(env->dfe, env->dtd, env->tpage);
    cmd[4] = tex_window(&env->tw);
    cmd[5] = 0xE6000000;
    PsxGpu_Gp0((const uint32_t *)cmd, 6);
    PsxHd_Register(x0, y0, x1 - x0 + 1, y1 - y0 + 1);
    if (env->isbg) {
        PsxGpu_Fill(x0, y0, x1 - x0 + 1, y1 - y0 + 1, env->r0 | (env->g0 << 8) | (env->b0 << 16));
    }
    return env;
}

DISPENV *PutDispEnv(DISPENV *env) {
    PSYQ_LOG("%p", (void *)env);
    if (env->screen.x != 0 || env->screen.y != 0 || env->screen.w != 0 || env->screen.h != 0 || env->isinter) {
        /* screen = TV fine position / visible range, isinter = interlace fields: the host shows
         * the display area as one progressive picture (P1.19 note). */
        PSYQ_LOG("PutDispEnv: screen %d %d %d %d, isinter %d not applied", env->screen.x, env->screen.y,
                 env->screen.w, env->screen.h, env->isinter);
    }
    PsxGpu_SetDisplay(env->disp.x, env->disp.y, env->disp.w, env->disp.h, env->isrgb24);
    return env;
}

DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h) {
    PSYQ_LOG("%p, %d, %d, %d, %d", (void *)env, x, y, w, h);
    env->clip.x = x;
    env->clip.y = y;
    env->clip.w = w;
    env->clip.h = h;
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tw.x = env->tw.y = env->tw.w = env->tw.h = 0;
    env->tpage = 0x0A; /* GetTPage(0, 0, 640, 0) */
    env->dtd = 1;
    env->dfe = h < 289;
    env->isbg = 0;
    env->r0 = env->g0 = env->b0 = 0;
    return env;
}

DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h) {
    PSYQ_LOG("%p, %d, %d, %d, %d", (void *)env, x, y, w, h);
    env->disp.x = x;
    env->disp.y = y;
    env->disp.w = w;
    env->disp.h = h;
    env->screen.x = env->screen.y = env->screen.w = env->screen.h = 0;
    env->isinter = 0;
    env->isrgb24 = 0;
    return env;
}

void AddPrim(void *ot, void *p) {
    u_long *o = ot;
    u_long *t = p;

    PSYQ_LOG("%p, %p", ot, p);
    *t = (*t & 0xFF000000) | (*o & 0xFFFFFF);
    *o = (*o & 0xFF000000) | ((u_long)(uintptr_t)t & 0xFFFFFF);
}

void SetPolyF4(POLY_F4 *p) {
    PSYQ_LOG("%p", (void *)p);
    set_len(p, 5);
    p->code = 0x28;
}

void SetDrawMove(DR_MOVE *p, RECT *rect, int x, int y) {
    PSYQ_LOG("%p, %p, %d, %d", (void *)p, (void *)rect, x, y);
    set_len(p, rect->w != 0 && rect->h != 0 ? 5 : 0);
    p->code[0] = 0x01000000;
    p->code[1] = 0x80000000;
    p->code[2] = ((u_long)(u_short)rect->y << 16) | (u_short)rect->x;
    p->code[3] = ((u_long)(u_short)y << 16) | (u_short)x;
    p->code[4] = ((u_long)(u_short)rect->h << 16) | (u_short)rect->w;
}

void SetDrawMode(DR_MODE *p, int dfe, int dtd, int tpage, RECT *tw) {
    PSYQ_LOG("%p, %d, %d, 0x%X, %p", (void *)p, dfe, dtd, tpage, (void *)tw);
    set_len(p, 2);
    p->code[0] = draw_mode(dfe, dtd, tpage);
    p->code[1] = tex_window(tw);
}
