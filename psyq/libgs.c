#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gte_core.h"
#include "libgs.h"
#include "psyq_log.h"

/* Psy-Q 4.7 libgs: the 12 functions the game calls, on the C GTE (psyq/gte.c). Each function
 * follows the retail code (asm/USA/main/nonmatchings/psyq/<name>.s) and the libgs internals it
 * calls (MulMatrix, MulMatrix2, TransposeMatrix, GsMulCoord2 / 3, GsGetLw, the square roots,
 * the axis matrices, SetColorMatrix / SetBackColor / SetFarColor / SetGeomScreen), so the
 * matrices and the GTE state left behind match the PS1.
 *
 * libgs globals (retail .bss addresses for reference):
 * - GsWSMATRIX 0x80061A08: world to screen, written by GsSetRefView2, read by game C.
 * - GsLIGHTWSMATRIX 0x800619A8 (decomp D_800619A8): light directions, one row per light.
 * - GsIDMATRIX 0x80061A28 (identity) and GsIDMATRIX2 0x80061A48 (identity with the aspect
 *   factor in m[1][1]), set by GsInitGraph.
 * - the light colour matrix 0x800619C8 (decomp names of its accessors:
 *   Gfx_Get / Gfx_SetLightColorMatrix), GsWSMATRIX_ORG 0x800619E8.
 * - PSDCNT 0x80061988: frame count of the coordinate cache (1 from GsInitGraph; only
 *   GsSwapDispBuff advances it and the game never calls it), the coordinate stack 0x80061A68. */

MATRIX GsWSMATRIX;
MATRIX GsLIGHTWSMATRIX;
static MATRIX GsIDMATRIX;
static MATRIX GsIDMATRIX2;
static MATRIX GsLIGHTCOLMATRIX;
static MATRIX GsWSMATRIX_ORG;
static u_long PSDCNT;
static short PSDIDX;        /* draw buffer index (0x8006198C) */
static short PSDOFSX[2];    /* per buffer offsets (0x800618F0); GsDefDispBuff, never called */
static short PSDOFSY[2];    /* (0x800618F4) */
static short POSITION_offx; /* last GTE offset set by libgs (0x8006197C / E) */
static short POSITION_offy;
static short GsORIGIN[2];   /* screen centre from GsInit3D (0x80061900) */
static RECT GsCLIP;         /* 0x80061980 */
static DRAWENV GsDRAWENV;   /* 0x80061908 */
static DISPENV GsDISPENV;   /* 0x80061968 */
static short GsOFSMODE;     /* GsOFSGPU bit of GsInitGraph's intmode (0x8006198E) */
static int GsSCREENW;       /* 0x80061990 */
static int GsSCREENH;       /* 0x80061994 */
static int GsLIGHT_MODE;    /* 0x8006199C */
static int GsZOVERLAP;      /* 0x80061998, 0x3FFF from GsInit3D */
static int GsLMODE_A0;      /* 0x800619A0, 10 from GsInit3D */
static GsCOORDINATE2 *GsCoordStack[101]; /* 0x80061A68 */

/* --- libgte internals used by libgs ------------------------------------------------------- */

static uint32_t ld32(const void *p) {
    uint32_t w;
    memcpy(&w, p, 4);
    return w;
}

static uint32_t ld16u(const void *p) {
    uint16_t h;
    memcpy(&h, p, 2);
    return h;
}

static void st32(void *p, uint32_t w) { memcpy(p, &w, 4); }

static void SetGeomScreen(int h) { Gte_Ctc2(GTE_H, (uint32_t)h); }

static void SetBackColor(int r, int g, int b) {
    Gte_Ctc2(GTE_RBK, (uint32_t)r << 4);
    Gte_Ctc2(GTE_GBK, (uint32_t)g << 4);
    Gte_Ctc2(GTE_BBK, (uint32_t)b << 4);
}

static void SetFarColor(int r, int g, int b) {
    Gte_Ctc2(GTE_RFC, (uint32_t)r << 4);
    Gte_Ctc2(GTE_GFC, (uint32_t)g << 4);
    Gte_Ctc2(GTE_BFC, (uint32_t)b << 4);
}

static void SetColorMatrix(MATRIX *m) {
    int i;
    for (i = 0; i < 5; i++) Gte_Ctc2(GTE_LCM0 + i, ld32((char *)m + i * 4));
}

/* MulMatrix / MulMatrix2 (handwritten retail asm): rotation registers = a, each column of b
 * through MVMVA (sf 1, RT, V0, no translation), the product written over a (MulMatrix) or b
 * (MulMatrix2). m[2][2] is stored as the whole IR3 word, so the pad halfword gets its sign. */
static void mul_matrix(MATRIX *a, MATRIX *b, MATRIX *out) {
    const char *pb = (const char *)b;
    char *po = (char *)out;
    uint32_t c0[3], c1[3], c2[3];
    int i;

    for (i = 0; i < 5; i++) Gte_Ctc2(GTE_RT0 + i, ld32((char *)a + i * 4));
    Gte_Mtc2(GTE_VXY0, ld16u(pb + 0) | (ld32(pb + 4) & 0xFFFF0000u));
    Gte_Mtc2(GTE_VZ0, ld32(pb + 0xC));
    Gte_Command(GTE_CMD_MVMVA(1, 0, 0, 3, 0));
    for (i = 0; i < 3; i++) c0[i] = Gte_Mfc2(GTE_IR1 + i);
    Gte_Mtc2(GTE_VXY0, ld16u(pb + 2) | (ld32(pb + 8) << 16));
    Gte_Mtc2(GTE_VZ0, (uint32_t)(int32_t)(int16_t)ld16u(pb + 0xE));
    Gte_Command(GTE_CMD_MVMVA(1, 0, 0, 3, 0));
    for (i = 0; i < 3; i++) c1[i] = Gte_Mfc2(GTE_IR1 + i);
    Gte_Mtc2(GTE_VXY0, ld16u(pb + 4) | (ld32(pb + 8) & 0xFFFF0000u));
    Gte_Mtc2(GTE_VZ0, ld32(pb + 0x10));
    Gte_Command(GTE_CMD_MVMVA(1, 0, 0, 3, 0));
    for (i = 0; i < 3; i++) c2[i] = Gte_Mfc2(GTE_IR1 + i);
    st32(po + 0x0, (c1[0] << 16) | (c0[0] & 0xFFFF));
    st32(po + 0xC, (c1[2] << 16) | (c0[2] & 0xFFFF));
    st32(po + 0x4, (c0[1] << 16) | (c2[0] & 0xFFFF));
    st32(po + 0x8, (c2[1] << 16) | (c1[1] & 0xFFFF));
    st32(po + 0x10, c2[2]);
}

static MATRIX *MulMatrix(MATRIX *m0, MATRIX *m1) {
    mul_matrix(m0, m1, m0);
    return m0;
}

static MATRIX *MulMatrix2(MATRIX *m0, MATRIX *m1) {
    mul_matrix(m0, m1, m1);
    return m1;
}

static MATRIX *TransposeMatrix(MATRIX *m0, MATRIX *m1) {
    int r, c;
    for (r = 0; r < 3; r++)
        for (c = 0; c < 3; c++) m1->m[r][c] = m0->m[c][r];
    return m1;
}

/* GTE LZCS / LZCR: leading bits equal to the sign bit. */
static int lzc(int v) {
    Gte_Mtc2(GTE_LZCS, (uint32_t)v);
    return (int)Gte_Mfc2(GTE_LZCR);
}

/* SquareRoot0: integer square root from the 0x40..0xFF table. The retail table (0x80049930,
 * 192 s16) is floor(sqrt(i / 64) * 4096) for i = 0x40..0xFF, generated here. */
static short sqrt_tbl_[0xC0];

static int SquareRoot0(int a) {
    int lz, t2, t1, t3, t4;
    if (sqrt_tbl_[0] == 0) {
        int i;
        for (i = 0; i < 0xC0; i++) {
            /* exact: integer square root of (0x40 + i) << 18 */
            unsigned int v = (unsigned int)(0x40 + i) << 18, r = 0;
            unsigned int bit = 1u << 30;
            while (bit > v) bit >>= 2;
            while (bit) {
                if (v >= r + bit) { v -= r + bit; r = (r >> 1) + bit; }
                else r >>= 1;
                bit >>= 2;
            }
            sqrt_tbl_[i] = (short)r;
        }
    }
    lz = lzc(a);
    if (lz == 32) return 0;
    t2 = lz & ~1;
    t1 = (31 - t2) >> 1;
    t3 = t2 - 24;
    if (t3 >= 0) t4 = (int)((unsigned int)a << t3);
    else t4 = a >> (24 - t2);
    t4 -= 0x40;
    if (t4 < 0 || t4 >= 0xC0) {
        /* retail reads past the table (negative input): not reached by the game so far */
        PSYQ_LOG("SquareRoot0: input %d out of range", a);
        return 0;
    }
    return (int)((unsigned int)((int)sqrt_tbl_[t4] << t1) >> 12);
}

/* func_8002CC64: hyperbolic CORDIC (6 steps, step 4 repeated) for the square root of a 20.12
 * value in its normalized range; returns x[6]. */
static int sqrt_cordic(int a) {
    int x[8], y[8], i;
    x[0] = a + 0x5D50AD;
    y[0] = a - 0x5D50AD;
    for (i = 1; i < 7; i++) {
        if (i != 4) {
            if (y[i - 1] >= 0) {
                x[i] = x[i - 1] - (y[i - 1] >> i);
                y[i] = y[i - 1] - (x[i - 1] >> i);
            } else {
                x[i] = x[i - 1] + (y[i - 1] >> i);
                y[i] = y[i - 1] + (x[i - 1] >> i);
            }
        } else {
            int x3 = x[3], y3 = y[3];
            if (y3 >= 0) {
                x[3] = x3 - (y3 >> 4);
                y[3] = y3 - (x3 >> 4);
            } else {
                x[3] = x3 + (y3 >> 4);
                y[3] = y3 + (x3 >> 4);
            }
            if (y[3] >= 0) {
                x[4] = x[3] - (y[3] >> 4);
                y[4] = y[3] - (x[3] >> 4);
            } else {
                x[4] = x[3] + (y[3] >> 4);
                y[4] = y[3] + (x[3] >> 4);
            }
        }
    }
    return x[6];
}

/* func_8002CDB8 (SquareRoot12): sqrt of a 20.12 value, result 20.12. */
static int SquareRoot12(int a) {
    int v, s, n;
    if (a == 0) return 0;
    v = 8 - lzc(a);
    if (v >= 0) {
        s = v >> 1;
        n = a >> (s * 2);
    } else {
        s = (v >> 1) + 1;
        n = (int)((unsigned int)a << ((-(s * 2)) & 31));
    }
    s -= 6;
    if (s < 0) return sqrt_cordic(n) >> -s;
    return (int)((unsigned int)sqrt_cordic(n) << s);
}

/* Math_MakeAxisRotMatrix (decomp name): identity with one axis rotation from sin / cos. */
static void make_axis_rot(MATRIX *m, short s, short c, int axis) {
    *m = GsIDMATRIX;
    switch (axis) {
    case 'X': case 'x':
        m->m[1][1] = c; m->m[2][2] = c; m->m[1][2] = (short)-s; m->m[2][1] = s;
        break;
    case 'Y': case 'y':
        m->m[0][0] = c; m->m[2][2] = c; m->m[0][2] = s; m->m[2][0] = (short)-s;
        break;
    case 'Z': case 'z':
        m->m[0][0] = c; m->m[1][1] = c; m->m[0][1] = (short)-s; m->m[1][0] = s;
        break;
    }
}

/* Math_MulMatrixRotZ (decomp name): m *= rotation about Z by a / 360 (rsin / rcos units). */
static void mul_rot_z(MATRIX *m, int a) {
    MATRIX r;
    int k = a / 360;
    int c = rcos(k), s = rsin(k);
    if (a == 0) return;
    memset(&r, 0, sizeof(r));
    r.m[0][0] = (short)c; r.m[0][1] = (short)-s;
    r.m[1][0] = (short)s; r.m[1][1] = (short)c;
    r.m[2][2] = 0x1000;
    MulMatrix(m, &r);
}

/* GsMulCoord2: m1 = m0 * m1 (translation m0.R * m1.t + m0.t). */
static void GsMulCoord2(MATRIX *m0, MATRIX *m1) {
    VECTOR t;
    ApplyMatrixLV(m0, (VECTOR *)m1->t, &t);
    MulMatrix2(m0, m1);
    m1->t[0] = t.vx + m0->t[0];
    m1->t[1] = t.vy + m0->t[1];
    m1->t[2] = t.vz + m0->t[2];
}

/* GsMulCoord3: m0 = m0 * m1 (translation m0.R * m1.t + m0.t). */
static void GsMulCoord3(MATRIX *m0, MATRIX *m1) {
    VECTOR t;
    ApplyMatrixLV(m0, (VECTOR *)m1->t, &t);
    MulMatrix(m0, m1);
    m0->t[0] = t.vx + m0->t[0];
    m0->t[1] = t.vy + m0->t[1];
    m0->t[2] = t.vz + m0->t[2];
}

/* GsGetLw: local to world of coord through its super chain, with the per-coordinate cache
 * (flg == PSDCNT: workm valid; flg == 0: changed since). */
static void GsGetLw(GsCOORDINATE2 *coord, MATRIX *m) {
    int i = 0, dirty = 100;

    for (;;) {
        GsCoordStack[i] = coord;
        if (coord->super == 0) {
            if (coord->flg == PSDCNT || coord->flg == 0) {
                coord->workm = coord->coord;
                *m = coord->workm;
                coord->flg = PSDCNT;
            } else if (dirty == 100) {
                *m = GsCoordStack[0]->workm;
                i = 0;
            } else {
                i = dirty + 1;
                *m = GsCoordStack[i]->workm;
            }
            break;
        }
        if (coord->flg == PSDCNT) {
            *m = coord->workm;
            break;
        }
        if (coord->flg == 0) dirty = i;
        coord = coord->super;
        i++;
    }
    for (; i > 0; i--) {
        GsCOORDINATE2 *c = GsCoordStack[i - 1];
        GsMulCoord3(m, &c->coord);
        c->workm = *m;
        c->flg = PSDCNT;
    }
}

/* --- libgs ------------------------------------------------------------------------------- */

/* GsSetDrawBuffOffset: GsOFSGPU puts the origin into the drawing offset, GsOFSGTE into the
 * GTE offset (retail picks the other buffer's PSDOFS in GTE mode). */
static void GsSetDrawBuffOffset(void) {
    if (GsOFSMODE != 0) {
        POSITION_offy = 0;
        POSITION_offx = 0;
        GsDRAWENV.ofs[0] = (short)(GsORIGIN[0] + PSDOFSX[PSDIDX]);
        GsDRAWENV.ofs[1] = (short)(GsORIGIN[1] + PSDOFSY[PSDIDX]);
        PutDrawEnv(&GsDRAWENV);
    } else {
        int k = PSDIDX != 0 ? 0 : 1;
        int x = GsORIGIN[0] + PSDOFSX[k];
        int y = GsORIGIN[1] + PSDOFSY[k];
        SetGeomOffset(x, y);
        POSITION_offx = (short)x;
        POSITION_offy = (short)y;
    }
}

static void GsSetDrawBuffClip(void) {
    GsDRAWENV.clip.w = GsCLIP.w;
    GsDRAWENV.clip.h = GsCLIP.h;
    GsDRAWENV.clip.x = (short)(GsCLIP.x + PSDOFSX[PSDIDX]);
    GsDRAWENV.clip.y = (short)(GsCLIP.y + PSDOFSY[PSDIDX]);
    PutDrawEnv(&GsDRAWENV);
}

void GsInitGraph(u_short x_res, u_short y_res, u_short intmode, u_short dith, u_short varmmode) {
    int h14;

    PSYQ_LOG("%u, %u, %u, %u, %u", x_res, y_res, intmode, dith, varmmode);
    /* func_8002ACC8: GPU reset, a cleared draw environment, the display environment. */
    ResetGraph(((intmode >> 4) & 3) == 3 ? 3 : 0);
    memset(&GsDRAWENV.ofs, 0, sizeof(GsDRAWENV.ofs));
    memset(&GsDRAWENV.tw, 0, sizeof(GsDRAWENV.tw));
    GsDRAWENV.tpage = 0;
    GsDRAWENV.dtd = (u_char)dith;
    GsDRAWENV.dfe = 0;
    GsDRAWENV.isbg = 0;
    PutDrawEnv(&GsDRAWENV);
    memset(&GsDISPENV, 0, sizeof(GsDISPENV));
    GsDISPENV.disp.w = (short)x_res;
    GsDISPENV.disp.h = (short)y_res;
    /* GetVideoMode() is NTSC here (PAL would set screen.y 0x18). */
    GsDISPENV.isinter = intmode & 1;
    GsOFSMODE = intmode & 4;
    GsDISPENV.isrgb24 = (u_char)varmmode;
    PutDispEnv(&GsDISPENV);
    /* func_8002BB84 */
    InitGeom();
    SetFarColor(0, 0, 0);
    SetGeomOffset(0, 0);
    POSITION_offy = 0;
    POSITION_offx = 0;
    PSDIDX = 0;
    /* func_8002AE4C: screen size, the identity matrices, zero light matrices, clip, PSDCNT. */
    GsSCREENW = x_res;
    GsSCREENH = y_res;
    h14 = (GsSCREENH << 14) / GsSCREENW;
    memset(&GsIDMATRIX, 0, sizeof(GsIDMATRIX));
    GsIDMATRIX.m[0][0] = GsIDMATRIX.m[1][1] = GsIDMATRIX.m[2][2] = 0x1000;
    GsIDMATRIX2 = GsIDMATRIX;
    GsLIGHTWSMATRIX = GsIDMATRIX;
    GsLIGHTWSMATRIX.m[0][0] = GsLIGHTWSMATRIX.m[1][1] = GsLIGHTWSMATRIX.m[2][2] = 0;
    GsLIGHTCOLMATRIX = GsLIGHTWSMATRIX;
    GsIDMATRIX2.m[1][1] = (short)(h14 / 3);
    GsORIGIN[0] = GsORIGIN[1] = 0;
    GsCLIP.x = GsCLIP.y = 0;
    GsCLIP.w = (short)GsSCREENW;
    GsCLIP.h = (short)GsSCREENH;
    PSDCNT = 1;
    GsSetDrawBuffClip();
    GsSetDrawBuffOffset();
}

void GsInit3D(void) {
    PSYQ_LOG("");
    GsORIGIN[0] = (short)(GsSCREENW / 2);
    GsORIGIN[1] = (short)(GsSCREENH / 2);
    GsSetDrawBuffOffset();
    GsLMODE_A0 = 10;
    GsLIGHT_MODE = 0;
    GsZOVERLAP = 0x3FFF;
}

void GsSetOffset(int x, int y) {
    PSYQ_LOG("%d, %d", x, y);
    if (GsOFSMODE != 0) {
        POSITION_offy = 0;
        POSITION_offx = 0;
        GsDRAWENV.ofs[0] = (short)(PSDOFSX[PSDIDX] + x);
        GsDRAWENV.ofs[1] = (short)(PSDOFSY[PSDIDX] + y);
        PutDrawEnv(&GsDRAWENV);
    } else {
        int k = PSDIDX != 0 ? 0 : 1;
        int ox = x + PSDOFSX[k];
        int oy = y + PSDOFSY[k];
        SetGeomOffset(ox, oy);
        POSITION_offx = (short)ox;
        POSITION_offy = (short)oy;
    }
}

void GsInitCoordinate2(GsCOORDINATE2 *super, GsCOORDINATE2 *base) {
    PSYQ_LOG("%p, %p", (void *)super, (void *)base);
    base->coord = GsIDMATRIX;
    base->super = super;
    base->flg = 0;
    /* retail: sltiu super, 2 */
    if ((uintptr_t)super >= 2) base->super->sub = base;
}

void GsSetLsMatrix(MATRIX *mp) {
    PSYQ_LOG("%p", (void *)mp);
    SetRotMatrix(mp);
    SetTransMatrix(mp);
}

void GsSetProjection(int h) {
    PSYQ_LOG("%d", h);
    SetGeomScreen(h);
}

int GsSetFlatLight(int id, GsF_LIGHT *lt) {
    MATRIX l, c;
    int r = lt->r, g = lt->g, b = lt->b, len;

    PSYQ_LOG("%d, %p", id, (void *)lt);
    l = GsLIGHTWSMATRIX;
    c = GsLIGHTCOLMATRIX;
    len = SquareRoot0((int)((unsigned int)lt->vx * lt->vx + (unsigned int)lt->vy * lt->vy +
                            (unsigned int)lt->vz * lt->vz));
    if (len == 0) return -1;
    if (id >= 0 && id <= 2) {
        l.m[id][0] = (short)((int)((unsigned int)-lt->vx << 12) / len);
        l.m[id][1] = (short)((int)((unsigned int)-lt->vy << 12) / len);
        l.m[id][2] = (short)((int)((unsigned int)-lt->vz << 12) / len);
        c.m[0][id] = (short)((r << 12) / 255);
        c.m[1][id] = (short)((g << 12) / 255);
        c.m[2][id] = (short)((b << 12) / 255);
    }
    GsLIGHTWSMATRIX = l;
    GsLIGHTCOLMATRIX = c;
    SetColorMatrix(&c);
    return 0;
}

void GsSetLightMode(int mode) {
    PSYQ_LOG("%d", mode);
    if (mode >= 0 && mode <= 3) GsLIGHT_MODE = mode;
    else PSYQ_LOG("GsSetLightMode: unknown mode %d", mode);
}

void GsSetAmbient(int r, int g, int b) {
    PSYQ_LOG("%d, %d, %d", r, g, b);
    SetBackColor(r >> 4, g >> 4, b >> 4);
}

/* TIM: word 0 id 0x10, word 1 flags (bits 0-2 pixel mode, bit 3 CLUT present), then the CLUT
 * block (if any) and the pixel block, each: length word, x, y, w, h halfwords, data. */
void GsGetTimInfo(u_long *im, GsIMAGE *tim) {
    u_long *p;

    PSYQ_LOG("%p, %p", (void *)im, (void *)tim);
    tim->pmode = im[0];
    p = im + 1;
    if (tim->pmode & 8) {
        tim->cx = (short)(p[1] & 0xFFFF);
        tim->cy = (short)(p[1] >> 16);
        tim->cw = (u_short)(p[2] & 0xFFFF);
        tim->ch = (u_short)(p[2] >> 16);
        tim->clut = p + 3;
        p += p[0] / 4;
    } else {
        tim->clut = 0;
    }
    tim->px = (short)(p[1] & 0xFFFF);
    tim->py = (short)(p[1] >> 16);
    tim->pw = (u_short)(p[2] & 0xFFFF);
    tim->ph = (u_short)(p[2] >> 16);
    tim->pixel = p + 3;
}

void GsGetLs(GsCOORDINATE2 *coord, MATRIX *m) {
    PSYQ_LOG("%p, %p", (void *)coord, (void *)m);
    GsGetLw(coord, m);
    GsMulCoord2(&GsWSMATRIX, m);
}

/* GsSetRefView2: GsWSMATRIX from the eye (vp), the reference point (vr) and the twist rz:
 * GsIDMATRIX2 * RotZ(-rz) * RotX * RotY, translation -eye; with a super coordinate the view is
 * moved into it. sin / cos of the two angles come from square roots of the squared
 * differences (SquareRoot0 for large values, the 20.12 CORDIC root for the normalized ratio),
 * in the retail order and 32-bit arithmetic. Returns 1 when eye == reference point. */
static int div_or_log(int n, int d) {
    if (d == 0) {
        PSYQ_LOG("GsSetRefView2: division by zero");
        return 0;
    }
    return n / d;
}

static unsigned int udiv_or_log(unsigned int n, unsigned int d) {
    if (d == 0) {
        PSYQ_LOG("GsSetRefView2: division by zero");
        return 0;
    }
    return n / d;
}

/* Dev trace (DW2_GS_TRACE set): the libgs matrices as hex bytes whenever they change, in the
 * layout of the retail memory dumps (scratchpad Redux probes). */
static void gs_hex(const char *tag, const void *p, int n) {
    const unsigned char *b = (const unsigned char *)p;
    int i;
    fprintf(stderr, "[gs] %s ", tag);
    for (i = 0; i < n; i++) fprintf(stderr, "%02X", b[i]);
    fprintf(stderr, "\n");
}

static void gs_trace(void) {
    static int on = -1;
    static MATRIX last[3];
    MATRIX now[3];
    if (on < 0) on = getenv("DW2_GS_TRACE") != 0;
    if (!on) return;
    now[0] = GsWSMATRIX;
    now[1] = GsLIGHTWSMATRIX;
    now[2] = GsLIGHTCOLMATRIX;
    if (memcmp(now, last, sizeof(now)) == 0) return;
    memcpy(last, now, sizeof(now));
    gs_hex("WS", &now[0], 0x20);
    gs_hex("LWS", &now[1], 0x20);
    gs_hex("LCOL", &now[2], 0x20);
    gs_hex("ID2", &GsIDMATRIX2, 0x20);
}

int GsSetRefView2(GsRVIEW2 *pv) {
    MATRIX rot, lw, tr;
    VECTOR eye;
    unsigned int total, sq, horiz;
    int s, c, a1, lz;

    PSYQ_LOG("%p", (void *)pv);
    GsWSMATRIX = GsIDMATRIX2;
    mul_rot_z(&GsWSMATRIX, -pv->rz);
    {
        unsigned int dx = (unsigned int)(pv->vrx - pv->vpx);
        unsigned int dy = (unsigned int)(pv->vry - pv->vpy);
        unsigned int dz = (unsigned int)(pv->vrz - pv->vpz);
        total = dx * dx + dy * dy + dz * dz;
    }
    if (total == 0) return 1;

    /* X axis: sin = -(vp.y - vr.y) / |d|, cos = |d.xz| / |d|. */
    {
        int py = pv->vpy - pv->vry;
        sq = (unsigned int)py * (unsigned int)py;
        lz = lzc((int)sq);
        a1 = 12 - lz;
        if (a1 < 0) {
            s = div_or_log(-(int)((unsigned int)py << 12), SquareRoot0((int)total));
        } else {
            int r = SquareRoot12((int)udiv_or_log(sq << lz, total >> a1));
            s = py >= 0 ? -r : r;
        }
    }
    {
        unsigned int dx = (unsigned int)(pv->vrx - pv->vpx);
        unsigned int dz = (unsigned int)(pv->vrz - pv->vpz);
        horiz = dx * dx + dz * dz;
        lz = lzc((int)horiz);
        a1 = 12 - lz;
        if (a1 < 0) {
            int sh = SquareRoot0((int)horiz);
            c = div_or_log(sh << 12, SquareRoot0((int)total));
        } else {
            c = SquareRoot12((int)udiv_or_log(horiz << lz, total >> a1));
        }
    }
    make_axis_rot(&rot, (short)s, (short)c, 'x');
    MulMatrix(&GsWSMATRIX, &rot);

    if (horiz != 0) {
        /* Y axis: sin = -d.x / |d.xz|, cos = d.z / |d.xz|. */
        int dx = pv->vrx - pv->vpx;
        int dz = pv->vrz - pv->vpz;
        sq = (unsigned int)dx * (unsigned int)dx;
        lz = lzc((int)sq);
        a1 = 12 - lz;
        if (a1 < 0) {
            s = div_or_log(-(int)((unsigned int)dx << 12), SquareRoot0((int)horiz));
        } else {
            int r = SquareRoot12((int)udiv_or_log(sq << lz, horiz >> a1));
            s = dx >= 0 ? -r : r;
        }
        sq = (unsigned int)dz * (unsigned int)dz;
        lz = lzc((int)sq);
        a1 = 12 - lz;
        if (a1 < 0) {
            c = div_or_log((int)((unsigned int)dz << 12), SquareRoot0((int)horiz));
        } else {
            int r = SquareRoot12((int)udiv_or_log(sq << lz, horiz >> a1));
            c = dz >= 0 ? r : -r;
        }
        make_axis_rot(&rot, (short)s, (short)c, 'y');
        MulMatrix(&GsWSMATRIX, &rot);
    }

    eye.vx = -pv->vpx;
    eye.vy = -pv->vpy;
    eye.vz = -pv->vpz;
    ApplyMatrixLV(&GsWSMATRIX, &eye, (VECTOR *)GsWSMATRIX.t);
    if (pv->super != 0) {
        GsGetLw(pv->super, &lw);
        TransposeMatrix(&lw, &tr);
        ApplyMatrixLV(&tr, (VECTOR *)lw.t, &eye);
        tr.t[0] = -eye.vx;
        tr.t[1] = -eye.vy;
        tr.t[2] = -eye.vz;
        GsMulCoord2(&GsWSMATRIX, &tr);
        GsWSMATRIX = tr;
    }
    GsWSMATRIX_ORG = GsWSMATRIX;
    gs_trace();
    return 0;
}
