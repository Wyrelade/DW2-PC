#ifndef PSYQ_LIBGPU_H
#define PSYQ_LIBGPU_H

#include "psyq_types.h"

/* Psy-Q 4.7 libgpu: the types and the 17 functions the game calls (+ StoreImage, MoveImage). */

typedef struct {
    short x, y;
    short w, h;
} RECT;

typedef struct {
    u_long tag;
    u_long code[15];
} DR_ENV;

typedef struct {
    RECT clip;      /* clip area */
    short ofs[2];   /* drawing offset */
    RECT tw;        /* texture window */
    u_short tpage;  /* texture page */
    u_char dtd;     /* dither (0 off, 1 on) */
    u_char dfe;     /* draw on the display area (0 off, 1 on) */
    u_char isbg;    /* clear the draw area at PutDrawEnv */
    u_char r0, g0, b0;
    DR_ENV dr_env;  /* reserved */
} DRAWENV;

typedef struct {
    RECT disp;      /* display area */
    RECT screen;    /* display start point */
    u_char isinter; /* interlace */
    u_char isrgb24; /* 24-bit colour */
    u_char pad0, pad1;
} DISPENV;

typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    u_char r0, g0, b0, code;
} P_TAG;

typedef struct {
    u_long tag;
    u_char r0, g0, b0, code;
    short x0, y0;
    short x1, y1;
    short x2, y2;
    short x3, y3;
} POLY_F4;

typedef struct {
    u_long tag;
    u_long code[2];
} DR_MODE;

typedef struct {
    u_long tag;
    u_long code[5];
} DR_MOVE;

int ResetGraph(int mode);
int SetGraphDebug(int level);
void SetDispMask(int mask);
int DrawSync(int mode);
int ClearImage(RECT *rect, u_char r, u_char g, u_char b);
int ClearImage2(RECT *rect, u_char r, u_char g, u_char b);
int LoadImage(RECT *rect, u_long *p);
/* Not called by the game; for tools and tests. */
int StoreImage(RECT *rect, u_long *p);
int MoveImage(RECT *rect, int x, int y);
u_long *ClearOTagR(u_long *ot, int n);
void DrawOTag(u_long *p);
DRAWENV *PutDrawEnv(DRAWENV *env);
DISPENV *PutDispEnv(DISPENV *env);
DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h);
DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h);
void AddPrim(void *ot, void *p);
void SetPolyF4(POLY_F4 *p);
void SetDrawMove(DR_MOVE *p, RECT *rect, int x, int y);
void SetDrawMode(DR_MODE *p, int dfe, int dtd, int tpage, RECT *tw);

#endif /* PSYQ_LIBGPU_H */
