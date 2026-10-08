#include <string.h>

#include "gte_core.h"
#include "gte_native.h"
#include "psyq_log.h"

/* C model of the PS1 GTE (psyq/gte_core.h) and the 20 gte.h macros of main/model.c on it.
 * Hardware rules from psx-spx "Geometry Transformation Engine (GTE)"; the commands the game
 * reaches are RTPS, NCLIP, MVMVA, NCS and GPF. Any other command logs once and only clears
 * FLAG. */

typedef int64_t s64;
typedef uint64_t u64;

static int32_t d_[32]; /* data registers, as stored */
static int32_t c_[32]; /* control registers, as stored */

/* FLAG bits. */
#define F_MAC_POS(i) (1u << (31 - (i))) /* MAC1..3 larger than 43 bits: 30, 29, 28 */
#define F_MAC_NEG(i) (1u << (28 - (i))) /* MAC1..3 smaller: 27, 26, 25 */
#define F_IR(i) (1u << (25 - (i)))      /* IR1..3 saturated: 24, 23, 22 */
#define F_COLOR(i) (1u << (22 - (i)))   /* colour FIFO R, G, B saturated: 21, 20, 19 */
#define F_SZ 0x00040000u               /* SZ3 / OTZ saturated */
#define F_DIV 0x00020000u              /* divide overflow */
#define F_MAC0_POS 0x00010000u
#define F_MAC0_NEG 0x00008000u
#define F_SX2 0x00004000u
#define F_SY2 0x00002000u
#define F_IR0 0x00001000u
#define F_ERROR_BITS 0x7F87E000u /* bits 30..23 and 18..13 set bit 31 */

static uint32_t flag_;

void (*Gte_PreciseHook)(int32_t sxy, double x, double y, double z, int clamped);

static int16_t lo16(int32_t v) { return (int16_t)(uint16_t)v; }
static int16_t hi16(int32_t v) { return (int16_t)(uint16_t)((uint32_t)v >> 16); }

static int16_t vx(int n) { return lo16(d_[GTE_VXY0 + n * 2]); }
static int16_t vy(int n) { return hi16(d_[GTE_VXY0 + n * 2]); }
static int16_t vz(int n) { return lo16(d_[GTE_VZ0 + n * 2]); }

/* Matrix element (row r, column c) of the control matrix at base 0 (RT), 8 (LLM) or 16 (LCM):
 * five words of packed s16 pairs, the 9th element alone in the low half of word 4. */
static int16_t mat(int base, int r, int c) {
    int k = r * 3 + c;
    int32_t w = c_[base + k / 2];
    return (k & 1) ? hi16(w) : lo16(w);
}

static s64 sx44(s64 v) { return (s64)((u64)v << 20) >> 20; }

/* MAC1..3 accumulation step: flags a 44-bit overflow, then wraps to 44 bits like the
 * hardware adder. */
static s64 mac_step(int i, s64 v) {
    if (v > 0x7FFFFFFFFFFLL) flag_ |= F_MAC_POS(i);
    else if (v < -0x80000000000LL) flag_ |= F_MAC_NEG(i);
    return sx44(v);
}

static void set_mac(int i, s64 v, int shift) {
    v = mac_step(i, v);
    d_[GTE_MAC0 + i] = (int32_t)(v >> shift);
}

static void set_mac0(s64 v) {
    if (v > 0x7FFFFFFFLL) flag_ |= F_MAC0_POS;
    else if (v < -0x80000000LL) flag_ |= F_MAC0_NEG;
    d_[GTE_MAC0] = (int32_t)v;
}

static void set_ir(int i, int32_t v, int lm) {
    int32_t lo = lm ? 0 : -0x8000;
    if (v < lo) { v = lo; flag_ |= F_IR(i); }
    else if (v > 0x7FFF) { v = 0x7FFF; flag_ |= F_IR(i); }
    d_[GTE_IR0 + i] = v;
}

static void set_mac_ir(int i, s64 v, int shift, int lm) {
    set_mac(i, v, shift);
    set_ir(i, d_[GTE_MAC0 + i], lm);
}

static void push_sz(s64 v) {
    if (v < 0) { v = 0; flag_ |= F_SZ; }
    else if (v > 0xFFFF) { v = 0xFFFF; flag_ |= F_SZ; }
    d_[GTE_SZ0] = d_[GTE_SZ1];
    d_[GTE_SZ1] = d_[GTE_SZ2];
    d_[GTE_SZ2] = d_[GTE_SZ3];
    d_[GTE_SZ3] = (int32_t)v;
}

static int32_t sat_sxy(int32_t v, uint32_t f) {
    if (v < -0x400) { v = -0x400; flag_ |= f; }
    else if (v > 0x3FF) { v = 0x3FF; flag_ |= f; }
    return v;
}

static void push_sxy(int32_t x, int32_t y) {
    d_[GTE_SXY0] = d_[GTE_SXY1];
    d_[GTE_SXY1] = d_[GTE_SXY2];
    d_[GTE_SXY2] = (int32_t)(((uint32_t)y << 16) | ((uint32_t)x & 0xFFFF));
}

static uint32_t sat_color(int i, int32_t v) {
    if (v < 0) { v = 0; flag_ |= F_COLOR(i); }
    else if (v > 0xFF) { v = 0xFF; flag_ |= F_COLOR(i); }
    return (uint32_t)v;
}

/* Colour FIFO push of MAC1..3 / 16 with RGBC's code byte. */
static void push_rgb_from_mac(void) {
    uint32_t r = sat_color(1, d_[GTE_MAC1] >> 4);
    uint32_t g = sat_color(2, d_[GTE_MAC2] >> 4);
    uint32_t b = sat_color(3, d_[GTE_MAC3] >> 4);
    d_[GTE_RGB0] = d_[GTE_RGB1];
    d_[GTE_RGB1] = d_[GTE_RGB2];
    d_[GTE_RGB2] = (int32_t)(r | g << 8 | b << 16 | ((uint32_t)d_[GTE_RGBC] & 0xFF000000u));
}

/* UNR reciprocal table (257 entries), as psx-spx gives it. */
static uint8_t unr_table_[0x101];
static int unr_ready_;

static void unr_init(void) {
    int i;
    for (i = 0; i < 0x101; i++) {
        int v = (0x40000 / (i + 0x100) + 1) / 2 - 0x101;
        unr_table_[i] = (uint8_t)(v < 0 ? 0 : v);
    }
    unr_ready_ = 1;
}

/* H / SZ3 in 16.16 as the GTE's Newton-Raphson divider computes it, or 0x1FFFF and the
 * divide overflow flag when H >= SZ3 * 2. */
static uint32_t unr_divide(uint32_t h, uint32_t sz3) {
    uint32_t z, n, d, u;
    if (h >= sz3 * 2) {
        flag_ |= F_DIV;
        return 0x1FFFF;
    }
    if (!unr_ready_) unr_init();
    z = 0;
    while (!((sz3 << z) & 0x8000)) z++;
    n = h << z;
    d = sz3 << z;
    u = unr_table_[(d - 0x7FC0) >> 7] + 0x101;
    d = (0x2000080 - d * u) >> 8;
    d = (0x0000080 + d * u) >> 8;
    {
        u64 q = ((u64)n * d + 0x8000) >> 16;
        return q > 0x1FFFF ? 0x1FFFF : (uint32_t)q;
    }
}

static void op_rtps(int sf, int lm) {
    int shift = sf ? 12 : 0;
    s64 m[3];
    int i;
    uint32_t q;
    s64 s;
    uint32_t f0 = flag_;
    for (i = 0; i < 3; i++) {
        s64 v = (s64)c_[GTE_TRX + i] << 12;
        v = mac_step(i + 1, v + (s64)mat(0, i, 0) * vx(0));
        v = mac_step(i + 1, v + (s64)mat(0, i, 1) * vy(0));
        v = mac_step(i + 1, v + (s64)mat(0, i, 2) * vz(0));
        m[i] = v;
        set_mac(i + 1, v, shift);
    }
    set_ir(1, d_[GTE_MAC1], lm);
    set_ir(2, d_[GTE_MAC2], lm);
    /* IR3: saturated from MAC3, but its flag comes from MAC3's value shifted by 12 whatever sf
     * says (hardware quirk). */
    {
        s64 z12 = m[2] >> 12;
        int32_t v = d_[GTE_MAC3];
        int32_t lo = lm ? 0 : -0x8000;
        if (z12 < -0x8000 || z12 > 0x7FFF) flag_ |= F_IR(3);
        if (v < lo) v = lo;
        else if (v > 0x7FFF) v = 0x7FFF;
        d_[GTE_IR3] = v;
    }
    push_sz(m[2] >> 12);
    q = unr_divide((uint16_t)c_[GTE_H], (uint32_t)d_[GTE_SZ3]);
    s = (s64)q * (int16_t)d_[GTE_IR1] + c_[GTE_OFX];
    set_mac0(s);
    {
        int32_t x = sat_sxy((int32_t)(s >> 16), F_SX2);
        s = (s64)q * (int16_t)d_[GTE_IR2] + c_[GTE_OFY];
        set_mac0(s);
        push_sxy(x, sat_sxy((int32_t)(s >> 16), F_SY2));
    }
    if (Gte_PreciseHook != NULL) {
        double z = (double)m[2] / 4096.0;
        double h = (uint16_t)c_[GTE_H];
        double div = sf ? 4096.0 : 1.0;

        if (2.0 * z > h) {
            uint32_t sat = (flag_ & ~f0) & (F_IR(1) | F_IR(2) | F_SX2 | F_SY2);

            Gte_PreciseHook(d_[GTE_SXY2], (double)m[0] / div * h / z + c_[GTE_OFX] / 65536.0,
                            (double)m[1] / div * h / z + c_[GTE_OFY] / 65536.0, z, sat != 0);
        }
    }
    s = (s64)q * (int16_t)c_[GTE_DQA] + c_[GTE_DQB];
    set_mac0(s);
    {
        int32_t ir0 = (int32_t)(s >> 12);
        if (ir0 < 0) { ir0 = 0; flag_ |= F_IR0; }
        else if (ir0 > 0x1000) { ir0 = 0x1000; flag_ |= F_IR0; }
        d_[GTE_IR0] = ir0;
    }
}

static void op_nclip(void) {
    s64 x0 = lo16(d_[GTE_SXY0]), y0 = hi16(d_[GTE_SXY0]);
    s64 x1 = lo16(d_[GTE_SXY1]), y1 = hi16(d_[GTE_SXY1]);
    s64 x2 = lo16(d_[GTE_SXY2]), y2 = hi16(d_[GTE_SXY2]);
    set_mac0(x0 * y1 + x1 * y2 + x2 * y0 - x0 * y2 - x1 * y0 - x2 * y1);
}

/* MAC/IR = (T << 12 + M * V) >> shift, one adder step per term. t == NULL: no translation. */
static void mul_mat_vec(int base, const int32_t *t, int16_t x, int16_t y, int16_t z, int shift,
                        int lm) {
    int i;
    for (i = 0; i < 3; i++) {
        s64 v = t ? (s64)t[i] << 12 : 0;
        v = mac_step(i + 1, v + (s64)mat(base, i, 0) * x);
        v = mac_step(i + 1, v + (s64)mat(base, i, 1) * y);
        v = mac_step(i + 1, v + (s64)mat(base, i, 2) * z);
        set_mac_ir(i + 1, v, shift, lm);
    }
}

static void op_mvmva(uint32_t op, int sf, int lm) {
    int shift = sf ? 12 : 0;
    int mx = (op >> 17) & 3, vsel = (op >> 15) & 3, cv = (op >> 13) & 3;
    int16_t x, y, z;
    int32_t t[3];
    const int32_t *tp = t;
    static const int base_of[3] = { GTE_RT0, GTE_LLM0, GTE_LCM0 };
    if (vsel == 3) {
        x = (int16_t)d_[GTE_IR1]; y = (int16_t)d_[GTE_IR2]; z = (int16_t)d_[GTE_IR3];
    } else {
        x = vx(vsel); y = vy(vsel); z = vz(vsel);
    }
    if (cv == 3) tp = NULL;
    else {
        int tb = cv == 0 ? GTE_TRX : cv == 1 ? GTE_RBK : GTE_RFC;
        t[0] = c_[tb]; t[1] = c_[tb + 1]; t[2] = c_[tb + 2];
    }
    if (mx == 3 || cv == 2) {
        /* Garbage matrix / FC translation bug: never issued by the game. */
        PSYQ_LOG("mvmva 0x%08X: mx 3 / cv 2 not modelled", op);
    }
    mul_mat_vec(base_of[mx == 3 ? 0 : mx], tp, x, y, z, shift, lm);
}

static void op_ncs(int sf, int lm) {
    int shift = sf ? 12 : 0;
    int32_t bk[3];
    bk[0] = c_[GTE_RBK]; bk[1] = c_[GTE_GBK]; bk[2] = c_[GTE_BBK];
    mul_mat_vec(GTE_LLM0, NULL, vx(0), vy(0), vz(0), shift, lm);
    mul_mat_vec(GTE_LCM0, bk, (int16_t)d_[GTE_IR1], (int16_t)d_[GTE_IR2], (int16_t)d_[GTE_IR3],
                shift, lm);
    push_rgb_from_mac();
}

static void op_gpf(int sf, int lm) {
    int shift = sf ? 12 : 0;
    s64 ir0 = (int16_t)d_[GTE_IR0];
    int i;
    for (i = 1; i <= 3; i++) set_mac_ir(i, ir0 * (int16_t)d_[GTE_IR0 + i], shift, lm);
    push_rgb_from_mac();
}

void Gte_Command(uint32_t op) {
    int sf = (op >> 19) & 1, lm = (op >> 10) & 1;
    flag_ = 0;
    switch (op & 0x3F) {
    case 0x01: op_rtps(sf, lm); break;
    case 0x06: op_nclip(); break;
    case 0x12: op_mvmva(op, sf, lm); break;
    case 0x1E: op_ncs(sf, lm); break;
    case 0x3D: op_gpf(sf, lm); break;
    default: PSYQ_LOG("command 0x%08X not modelled", op); break;
    }
    if (flag_ & F_ERROR_BITS) flag_ |= 0x80000000u;
    c_[GTE_FLAG] = (int32_t)flag_;
}

void Gte_Reset(void) {
    memset(d_, 0, sizeof(d_));
    memset(c_, 0, sizeof(c_));
    d_[GTE_LZCR] = 32;
}

static int32_t lzc(int32_t v) {
    uint32_t u = v < 0 ? ~(uint32_t)v : (uint32_t)v;
    int32_t n = 0;
    while (n < 32 && !(u & 0x80000000u)) { u <<= 1; n++; }
    return n;
}

static uint32_t sat5(int32_t ir) {
    int32_t v = ir >> 7;
    return (uint32_t)(v < 0 ? 0 : v > 0x1F ? 0x1F : v);
}

void Gte_Mtc2(int reg, uint32_t value) {
    switch (reg) {
    case GTE_VZ0: case GTE_VZ1: case GTE_VZ2:
    case GTE_IR0: case GTE_IR1: case GTE_IR2: case GTE_IR3:
        d_[reg] = lo16((int32_t)value);
        break;
    case GTE_OTZ: case GTE_SZ0: case GTE_SZ1: case GTE_SZ2: case GTE_SZ3:
        d_[reg] = (int32_t)(value & 0xFFFF);
        break;
    case GTE_SXYP:
        d_[GTE_SXY0] = d_[GTE_SXY1];
        d_[GTE_SXY1] = d_[GTE_SXY2];
        d_[GTE_SXY2] = (int32_t)value;
        break;
    case GTE_IRGB:
        d_[GTE_IR1] = (int32_t)((value & 0x1F) << 7);
        d_[GTE_IR2] = (int32_t)(((value >> 5) & 0x1F) << 7);
        d_[GTE_IR3] = (int32_t)(((value >> 10) & 0x1F) << 7);
        break;
    case GTE_ORGB: case GTE_LZCR:
        break; /* read only */
    case GTE_LZCS:
        d_[GTE_LZCS] = (int32_t)value;
        d_[GTE_LZCR] = lzc((int32_t)value);
        break;
    default:
        d_[reg] = (int32_t)value;
        break;
    }
}

uint32_t Gte_Mfc2(int reg) {
    switch (reg) {
    case GTE_SXYP:
        return (uint32_t)d_[GTE_SXY2];
    case GTE_IRGB: case GTE_ORGB:
        return sat5(d_[GTE_IR1]) | sat5(d_[GTE_IR2]) << 5 | sat5(d_[GTE_IR3]) << 10;
    default:
        return (uint32_t)d_[reg];
    }
}

void Gte_Ctc2(int reg, uint32_t value) {
    switch (reg) {
    case 4: case 12: case 20: /* RT33, L33, LB3 */
    case GTE_H: case GTE_DQA: case GTE_ZSF3: case GTE_ZSF4:
        c_[reg] = lo16((int32_t)value); /* H reads back sign extended too */
        break;
    case GTE_FLAG:
        value &= 0x7FFFF000u;
        if (value & F_ERROR_BITS) value |= 0x80000000u;
        c_[GTE_FLAG] = (int32_t)value;
        break;
    default:
        c_[reg] = (int32_t)value;
        break;
    }
}

uint32_t Gte_Cfc2(int reg) { return (uint32_t)c_[reg]; }

void Gte_Lwc2(int reg, const void *addr) {
    uint32_t w;
    memcpy(&w, addr, 4);
    Gte_Mtc2(reg, w);
}

void Gte_Swc2(int reg, void *addr) {
    uint32_t w = Gte_Mfc2(reg);
    memcpy(addr, &w, 4);
}

/* gte.h macros (include/gte.h): each is the inline_n.h register sequence on the model above. */

static uint16_t ld16(const void *p) {
    uint16_t v;
    memcpy(&v, p, 2);
    return v;
}

static void st16(void *p, uint32_t v) {
    uint16_t h = (uint16_t)v;
    memcpy(p, &h, 2);
}

static void st32(void *p, uint32_t v) { memcpy(p, &v, 4); }

void GteC_ldv0(const void *r0) {
    Gte_Lwc2(GTE_VXY0, r0);
    Gte_Lwc2(GTE_VZ0, (const char *)r0 + 4);
}

void GteC_ldv0u(const void *r0) {
    /* lwl / lwr + lhu: the same two registers from an unaligned SVECTOR. */
    Gte_Lwc2(GTE_VXY0, r0);
    Gte_Mtc2(GTE_VZ0, ld16((const char *)r0 + 4));
}

void GteC_ldlv0(const void *r0) {
    const char *p = r0;
    Gte_Mtc2(GTE_VXY0, ld16(p) | (uint32_t)ld16(p + 4) << 16);
    Gte_Lwc2(GTE_VZ0, p + 8);
}

void GteC_ldclmv(const void *r0) {
    const char *p = r0;
    Gte_Mtc2(GTE_IR1, ld16(p));
    Gte_Mtc2(GTE_IR2, ld16(p + 6));
    Gte_Mtc2(GTE_IR3, ld16(p + 12));
}

void GteC_ldsxy3(int r0, int r1, int r2) {
    Gte_Mtc2(GTE_SXY0, (uint32_t)r0);
    Gte_Mtc2(GTE_SXY2, (uint32_t)r2);
    Gte_Mtc2(GTE_SXY1, (uint32_t)r1);
}

static void set_ctrl_words(int reg, const void *src, int n) {
    int i;
    for (i = 0; i < n; i++) {
        uint32_t w;
        memcpy(&w, (const char *)src + i * 4, 4);
        Gte_Ctc2(reg + i, w);
    }
}

void GteC_SetRotMatrix(const void *r0) { set_ctrl_words(GTE_RT0, r0, 5); }
void GteC_SetTransMatrix(const void *r0) { set_ctrl_words(GTE_TRX, (const char *)r0 + 20, 3); }
void GteC_SetLightMatrix(const void *r0) { set_ctrl_words(GTE_LLM0, r0, 5); }

void GteC_rtps(void) { Gte_Command(GTE_CMD_RTPS); }
void GteC_rtir(void) { Gte_Command(GTE_CMD_MVMVA(1, 0, 3, 3, 0)); }
void GteC_rtv0tr(void) { Gte_Command(GTE_CMD_MVMVA(1, 0, 0, 0, 0)); }
void GteC_ncs(void) { Gte_Command(GTE_CMD_NCS); }
void GteC_nclip(void) { Gte_Command(GTE_CMD_NCLIP); }

void GteC_stflg(void *r0) { st32(r0, Gte_Cfc2(GTE_FLAG)); }
void GteC_stsxy(void *r0) { Gte_Swc2(GTE_SXY2, r0); }
void GteC_stszotz(void *r0) { st32(r0, (uint32_t)((int32_t)Gte_Mfc2(GTE_SZ3) >> 2)); }
void GteC_strgb(void *r0) { Gte_Swc2(GTE_RGB2, r0); }

void GteC_stclmv(void *r0) {
    char *p = r0;
    st16(p, Gte_Mfc2(GTE_IR1));
    st16(p + 6, Gte_Mfc2(GTE_IR2));
    st16(p + 12, Gte_Mfc2(GTE_IR3));
}

void GteC_stlvnl(void *r0) {
    char *p = r0;
    Gte_Swc2(GTE_MAC1, p);
    Gte_Swc2(GTE_MAC2, p + 4);
    Gte_Swc2(GTE_MAC3, p + 8);
}

void GteC_stopz(void *r0) { Gte_Swc2(GTE_MAC0, r0); }
