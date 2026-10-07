#include <math.h>
#include <string.h>

#include "gte_core.h"
#include "libgte.h"
#include "psyq_log.h"

/* Psy-Q 4.7 libgte (the 14 functions the game calls) on the C GTE (psyq/gte.c). Each function
 * follows the retail code (asm/USA/main/nonmatchings/psyq/<name>.s): the same GTE register
 * moves and commands, so the results and the GTE state left behind match the PS1.
 *
 * Tables (retail main data at 0x80049110 / 0x80049DC0 / 0x8004DDC0, inside the main 38110
 * block):
 * - rsin_tbl: sin(i * pi / 2048) * 4096 rounded, i = 0..0x400.
 * - rcossin_tbl: (sin, cos) pairs for i = 0..0xFFF, same rounding.
 * Both are generated here; every entry equals the retail bytes (tools/gte_test.c checks it).
 * - ratan_tbl: atan(i / 1024) in 1/4096 turns, i = 0..0x400. It follows no plain rounding of
 *   the formula (189 entries differ by one), so it is the retail table, extracted at build time
 *   (configs/USA/include_bin_native.txt). */

#define PSYQ_ASM_STR_(x) #x
#define PSYQ_ASM_XSTR_(x) PSYQ_ASM_STR_(x)
#define PSYQ_ASM_NAME(NAME) PSYQ_ASM_XSTR_(__USER_LABEL_PREFIX__) NAME

__asm__(
    ".data\n"
    "    .balign 16\n"
    "    .globl " PSYQ_ASM_NAME("Psyq_RatanTable") "\n"
    PSYQ_ASM_NAME("Psyq_RatanTable") ":\n"
    "    .incbin \"assets/main/ratan_tbl.bin\"\n"
    ".text");
extern const short Psyq_RatanTable[0x401];

static short rsin_tbl_[0x401];
static short rcossin_tbl_[0x2000];
static int tables_ready_;

/* Called by InitGeom and by every table user (tests call rsin before InitGeom). */
static void tables_init(void) {
    int i;
    if (tables_ready_) return;
    for (i = 0; i < 0x1000; i++) {
        double a = i * (M_PI / 2048.0);
        short s = (short)floor(sin(a) * 4096.0 + 0.5);
        short c = (short)floor(cos(a) * 4096.0 + 0.5);
        if (i <= 0x400) rsin_tbl_[i] = s;
        rcossin_tbl_[i * 2] = s;
        rcossin_tbl_[i * 2 + 1] = c;
    }
    tables_ready_ = 1;
}

const short *Psyq_SinTable(void) { tables_init(); return rsin_tbl_; }
const short *Psyq_CosSinTable(void) { tables_init(); return rcossin_tbl_; }

/* sin_1: a in 0..0xFFF. */
static int sin_1(int a) {
    if (a <= 0x800) {
        if (a <= 0x400) return rsin_tbl_[a];
        return rsin_tbl_[0x800 - a];
    }
    if (a <= 0xC00) return -rsin_tbl_[a - 0x800];
    return -rsin_tbl_[0x1000 - a];
}

int rsin(int a) {
    tables_init();
    if (a < 0) return -sin_1(-a & 0xFFF);
    return sin_1(a & 0xFFF);
}

int rcos(int a) {
    tables_init();
    if (a < 0) a = -a;
    a &= 0xFFF;
    if (a <= 0x800) {
        if (a <= 0x400) return rsin_tbl_[0x400 - a];
        return -rsin_tbl_[a - 0x400];
    }
    if (a <= 0xC00) return -rsin_tbl_[0xC00 - a];
    return rsin_tbl_[a - 0xC00];
}

int ratan2(int y, int x) {
    int neg_x = 0, neg_y = 0, r;
    if (x < 0) { neg_x = 1; x = -x; }
    if (y < 0) { neg_y = 1; y = -y; }
    if (x == 0 && y == 0) return 0;
    if (y < x) {
        if (y & 0x7FE00000) r = Psyq_RatanTable[y / (x >> 10)];
        else r = Psyq_RatanTable[(y << 10) / x];
    } else {
        if (x & 0x7FE00000) r = Psyq_RatanTable[x / (y >> 10)];
        else r = Psyq_RatanTable[(x << 10) / y];
        r = 0x400 - r;
    }
    if (neg_x) r = 0x800 - r;
    if (neg_y) r = -r;
    return r;
}

void InitGeom(void) {
    /* Retail first patches the BIOS exception handler for the GTE (func_8002DAC4) and turns
     * COP2 on in SR: nothing to do here. Then the default control registers. */
    tables_init();
    Gte_Reset();
    Gte_Ctc2(GTE_ZSF3, 0x155);
    Gte_Ctc2(GTE_ZSF4, 0x100);
    Gte_Ctc2(GTE_H, 0x3E8);
    Gte_Ctc2(GTE_DQA, (unsigned)-0x1062);
    Gte_Ctc2(GTE_DQB, 0x1400000);
    Gte_Ctc2(GTE_OFX, 0);
    Gte_Ctc2(GTE_OFY, 0);
}

static void set_rot(const MATRIX *m) {
    int i;
    for (i = 0; i < 5; i++) {
        unsigned int w;
        memcpy(&w, (const char *)m + i * 4, 4);
        Gte_Ctc2(GTE_RT0 + i, w);
    }
}

/* One component of a long vector split for ApplyMatrixLV: high part (bits 15 up) and low
 * 15 bits, both carrying the sign. */
static void split15(int v, int *hi, int *lo) {
    if (v < 0) {
        unsigned int n = 0u - (unsigned int)v;
        *hi = -(int)((int)n >> 15);
        *lo = -(int)(n & 0x7FFF);
    } else {
        *hi = v >> 15;
        *lo = v & 0x7FFF;
    }
}

static int times8(int v) {
    /* Retail: negate, shift by 3, negate back for negative values (the same bits in 32 bits). */
    return (int)((unsigned int)v << 3);
}

VECTOR *ApplyMatrixLV(MATRIX *m, VECTOR *v0, VECTOR *v1) {
    int hx, hy, hz, lx, ly, lz, mx, my, mz;
    set_rot(m);
    split15(v0->vx, &hx, &lx);
    split15(v0->vy, &hy, &ly);
    split15(v0->vz, &hz, &lz);
    Gte_Mtc2(GTE_IR1, (unsigned int)hx);
    Gte_Mtc2(GTE_IR2, (unsigned int)hy);
    Gte_Mtc2(GTE_IR3, (unsigned int)hz);
    Gte_Command(GTE_CMD_MVMVA(0, 0, 3, 3, 0));
    mx = (int)Gte_Mfc2(GTE_MAC1);
    my = (int)Gte_Mfc2(GTE_MAC2);
    mz = (int)Gte_Mfc2(GTE_MAC3);
    Gte_Mtc2(GTE_IR1, (unsigned int)lx);
    Gte_Mtc2(GTE_IR2, (unsigned int)ly);
    Gte_Mtc2(GTE_IR3, (unsigned int)lz);
    Gte_Command(GTE_CMD_MVMVA(1, 0, 3, 3, 0));
    v1->vx = (int)(Gte_Mfc2(GTE_MAC1) + (unsigned int)times8(mx));
    v1->vy = (int)(Gte_Mfc2(GTE_MAC2) + (unsigned int)times8(my));
    v1->vz = (int)(Gte_Mfc2(GTE_MAC3) + (unsigned int)times8(mz));
    return v1;
}

/* libgte matrix stack: 20 entries of RT (5 words) + TR (3 words). */
static unsigned int matrix_stack_[20][8];
static int matrix_sp_; /* bytes, like retail (0x20 per entry) */

void PushMatrix(void) {
    unsigned int *e;
    int i;
    if (matrix_sp_ >= 0x280) {
        PSYQ_LOG("libgte: PushMatrix stack overflow");
        return;
    }
    e = matrix_stack_[matrix_sp_ / 0x20];
    for (i = 0; i < 8; i++) e[i] = Gte_Cfc2(i);
    matrix_sp_ += 0x20;
}

void PopMatrix(void) {
    unsigned int *e;
    int i;
    if (matrix_sp_ <= 0) {
        PSYQ_LOG("libgte: PopMatrix stack underflow");
        return;
    }
    matrix_sp_ -= 0x20;
    e = matrix_stack_[matrix_sp_ / 0x20];
    for (i = 0; i < 8; i++) Gte_Ctc2(i, e[i]);
}

SVECTOR *ApplyMatrixSV(MATRIX *m, SVECTOR *v0, SVECTOR *v1) {
    set_rot(m);
    Gte_Lwc2(GTE_VXY0, &v0->vx);
    Gte_Lwc2(GTE_VZ0, &v0->vz);
    Gte_Command(GTE_CMD_MVMVA(1, 0, 0, 3, 0));
    v1->vx = (short)Gte_Mfc2(GTE_IR1);
    v1->vy = (short)Gte_Mfc2(GTE_IR2);
    v1->vz = (short)Gte_Mfc2(GTE_IR3);
    return v1;
}

/* (m * s) >> 12 in 32 bits (retail multu, low word). */
static int scale12(short m, int s) { return (int)((unsigned int)(int)m * (unsigned int)s) >> 12; }

MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v) {
    int sx = v->vx, sy = v->vy, sz = v->vz, k;
    int r22;
    for (k = 0; k < 8; k++) {
        int r = k / 3, c = k % 3;
        int s = c == 0 ? sx : c == 1 ? sy : sz;
        m->m[r][c] = (short)scale12(m->m[r][c], s);
    }
    /* m[2][2] is stored as a whole word: the pad halfword after it gets the high bits. */
    r22 = scale12(m->m[2][2], sz);
    memcpy(&m->m[2][2], &r22, 4);
    return m;
}

void SetRotMatrix(MATRIX *m) {
    set_rot(m);
}

void SetTransMatrix(MATRIX *m) {
    Gte_Ctc2(GTE_TRX, (unsigned int)m->t[0]);
    Gte_Ctc2(GTE_TRY, (unsigned int)m->t[1]);
    Gte_Ctc2(GTE_TRZ, (unsigned int)m->t[2]);
}

void SetGeomOffset(int ofx, int ofy) {
    Gte_Ctc2(GTE_OFX, (unsigned int)ofx << 16);
    Gte_Ctc2(GTE_OFY, (unsigned int)ofy << 16);
}

/* The game passes NULL for outputs it does not want (stag4000 Stg40_ProjectGrid: p and flag).
 * Retail stores there anyway: address 0 is PS1 RAM word 0 (kernel low memory, never read back by
 * the game). Here such stores go to this word. */
static int null_store;

int RotTransPers(SVECTOR *v0, int *sxy, int *p, int *flag) {
    if (p == NULL) {
        p = &null_store;
    }
    if (flag == NULL) {
        flag = &null_store;
    }
    Gte_Lwc2(GTE_VXY0, &v0->vx);
    Gte_Lwc2(GTE_VZ0, &v0->vz);
    Gte_Command(GTE_CMD_RTPS);
    Gte_Swc2(GTE_SXY2, sxy);
    Gte_Swc2(GTE_IR0, p);
    *flag = (int)Gte_Cfc2(GTE_FLAG);
    return (int)Gte_Mfc2(GTE_SZ3) >> 2;
}

/* (sin, cos) of one angle from rcossin_tbl, sin negated for a negative angle. */
static void cossin(int a, int *s, int *c) {
    int i = (a < 0 ? -a : a) & 0xFFF;
    *s = a < 0 ? -rcossin_tbl_[i * 2] : rcossin_tbl_[i * 2];
    *c = rcossin_tbl_[i * 2 + 1];
}

static int ir(int n) { return (int)Gte_Mfc2(GTE_IR0 + n); }

static void gpf(int ir0, int ir1, int ir2, int ir3) {
    Gte_Mtc2(GTE_IR0, (unsigned int)ir0);
    Gte_Mtc2(GTE_IR1, (unsigned int)ir1);
    Gte_Mtc2(GTE_IR2, (unsigned int)ir2);
    Gte_Mtc2(GTE_IR3, (unsigned int)ir3);
    Gte_Command(GTE_CMD_GPF(1));
}

MATRIX *RotMatrixYXZ(SVECTOR *r, MATRIX *m) {
    int sx, cx, sy, cy, sz, cz;
    int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
    tables_init();
    cossin(r->vx, &sx, &cx);
    cossin(r->vy, &sy, &cy);
    cossin(r->vz, &sz, &cz);
    /* Retail order of GTE GPF steps (sf 1): products of 4.12 values >> 12 through IR. */
    gpf(cy, sx, sz, cz);
    a1 = ir(1); a2 = ir(2); a3 = ir(3); /* cy*sx, cy*sz, cy*cz */
    gpf(sy, sx, sz, cz);
    b1 = ir(1); b2 = ir(2); b3 = ir(3); /* sy*sx, sy*sz, sy*cz */
    m->m[2][2] = (short)((cx * cy) >> 12);
    gpf(cz, cx, b1, a1);
    c1 = ir(1); c2 = ir(2); c3 = ir(3); /* cz*cx, cz*sy*sx, cz*cy*sx */
    gpf(sz, cx, b1, a1);
    d1 = ir(1); d2 = ir(2); d3 = ir(3); /* sz*cx, sz*sy*sx, sz*cy*sx */
    m->m[1][1] = (short)c1;
    m->m[1][2] = (short)-sx;
    m->m[0][0] = (short)(a3 + d2);
    m->m[0][1] = (short)(c2 - a2);
    m->m[0][2] = (short)((cx * sy) >> 12);
    m->m[1][0] = (short)d1;
    m->m[2][0] = (short)(d3 - b3);
    m->m[2][1] = (short)(c3 + b2);
    return m;
}
