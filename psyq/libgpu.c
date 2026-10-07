#include "libgpu.h"
#include "psyq_log.h"

/* libgpu stubs (P1.1): log the first call, return what the game expects. The emulated GPU
 * (VRAM, OT walk, GP0 packets) comes in P1.4. ClearOTagR is real: game C walks the OT links. */

int ResetGraph(int mode) {
    PSYQ_LOG("%d", mode);
    return 0;
}

int SetGraphDebug(int level) {
    PSYQ_LOG("%d", level);
    return 0;
}

void SetDispMask(int mask) {
    PSYQ_LOG("%d", mask);
}

int DrawSync(int mode) {
    PSYQ_LOG("%d", mode);
    return 0; /* nothing queued */
}

int ClearImage(RECT *rect, u_char r, u_char g, u_char b) {
    PSYQ_LOG("{%d,%d,%d,%d}, %u, %u, %u", rect->x, rect->y, rect->w, rect->h, r, g, b);
    return 0;
}

int ClearImage2(RECT *rect, u_char r, u_char g, u_char b) {
    PSYQ_LOG("{%d,%d,%d,%d}, %u, %u, %u", rect->x, rect->y, rect->w, rect->h, r, g, b);
    return 0;
}

int LoadImage(RECT *rect, u_long *p) {
    PSYQ_LOG("{%d,%d,%d,%d}, %p", rect->x, rect->y, rect->w, rect->h, (void *)p);
    return 0;
}

/* Reverse ordering table: ot[0] is the end tag, ot[i] links to ot[i - 1] (24-bit address, the
 * PS1 tag format; see psyq/ps1mem.h for the 16 MB window). */
u_long *ClearOTagR(u_long *ot, int n) {
    int i;

    PSYQ_LOG("%p, %d", (void *)ot, n);
    for (i = n - 1; i > 0; i--) {
        ot[i] = (u_long)(unsigned int)&ot[i - 1] & 0xFFFFFF;
    }
    ot[0] = 0xFFFFFF;
    return ot;
}

void DrawOTag(u_long *p) {
    PSYQ_LOG("%p", (void *)p);
}

DRAWENV *PutDrawEnv(DRAWENV *env) {
    PSYQ_LOG("%p", (void *)env);
    return env;
}

DISPENV *PutDispEnv(DISPENV *env) {
    PSYQ_LOG("%p", (void *)env);
    return env;
}

DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h) {
    PSYQ_LOG("%p, %d, %d, %d, %d", (void *)env, x, y, w, h);
    return env;
}

DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h) {
    PSYQ_LOG("%p, %d, %d, %d, %d", (void *)env, x, y, w, h);
    return env;
}

void AddPrim(void *ot, void *p) {
    PSYQ_LOG("%p, %p", ot, p);
}

void SetPolyF4(POLY_F4 *p) {
    PSYQ_LOG("%p", (void *)p);
}

void SetDrawMove(DR_MOVE *p, RECT *rect, int x, int y) {
    PSYQ_LOG("%p, %p, %d, %d", (void *)p, (void *)rect, x, y);
}

void SetDrawMode(DR_MODE *p, int dfe, int dtd, int tpage, RECT *tw) {
    PSYQ_LOG("%p, %d, %d, 0x%X, %p", (void *)p, dfe, dtd, tpage, (void *)tw);
}
