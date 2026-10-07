/* GTE model test (psyq/gte.c, psyq/libgte.c), headless.
 *
 *   gte_test [--exe SLUS_011.93] [--ref tests/gte_ref.bin]
 *       runs every check; exit 0 when all pass.
 *   gte_test --write-cases FILE
 *       writes the command cases (input of tools/gte_probe.py, which runs them on the GTE of
 *       PCSX-Redux and writes tests/gte_ref.bin).
 *
 * Checks:
 * 1. Commands: CASES cases per command word (RTPS, NCLIP, MVMVA forms, NCS, GPF), each with
 *    random control and data registers (in-range values and full-range values, so the overflow
 *    and saturation flags show up). Data registers 0..31 and FLAG after the command must equal
 *    the reference.
 * 2. Tables: rsin_tbl / rcossin_tbl / ratan_tbl against the retail exe bytes, when the exe is
 *    there (dumps/disc/SLUS_011.93); rsin / rcos over every angle against the tables.
 * 3. libgte functions on known values. */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gte_core.h"
#include "libgte.h"

const short *Psyq_SinTable(void);
const short *Psyq_CosSinTable(void);
extern const short Psyq_RatanTable[0x401];

#define CASES 96
#define CASE_WORDS 64 /* ctrl 0..30, data 0..30 (written in order, 15 / 28 / 29 skipped), op word, op index */
#define OUT_WORDS 33  /* data 0..31, FLAG */

static const uint32_t ops[] = {
    GTE_CMD_RTPS,
    0x4A100001u | (1u << 10),           /* RTPS sf 0, lm 1 */
    GTE_CMD_NCLIP,
    GTE_CMD_MVMVA(1, 0, 3, 3, 0),       /* rtir */
    GTE_CMD_MVMVA(1, 0, 0, 0, 0),       /* rtv0tr */
    GTE_CMD_MVMVA(0, 0, 3, 3, 0),       /* ApplyMatrixLV high part */
    GTE_CMD_MVMVA(1, 0, 0, 3, 0),       /* ApplyMatrixSV */
    GTE_CMD_MVMVA(1, 1, 1, 1, 1),
    GTE_CMD_MVMVA(0, 2, 2, 0, 0),
    GTE_CMD_NCS,
    0x4AC0001Eu,                         /* NCS sf 0, lm 0 */
    GTE_CMD_GPF(1),
    0x4B90003Du | (1u << 10),           /* GPF sf 0, lm 1 */
};
#define NOPS ((int)(sizeof(ops) / sizeof(ops[0])))

static uint32_t rng_ = 0x2545F491u;
static uint32_t rnd(void) {
    rng_ ^= rng_ << 13;
    rng_ ^= rng_ >> 17;
    rng_ ^= rng_ << 5;
    return rng_;
}
static int32_t rnd_range(int32_t lo, int32_t hi) { return lo + (int32_t)(rnd() % (uint32_t)(hi - lo + 1)); }
static uint32_t pair(int32_t a, int32_t b) { return ((uint32_t)b << 16) | ((uint32_t)a & 0xFFFF); }

/* One case: wide = 0 typical game ranges, 1 full range, 2 extremes (translations near the
 * 32-bit ends, large matrix and vector elements: the 44-bit MAC overflow flags). */
static void make_case(uint32_t *w, int op_index, int wide) {
    int i;
    int32_t m = wide ? 0x7FFF : 0x1000;
    memset(w, 0, CASE_WORDS * 4);
    for (i = 0; i < 31; i++) {
        uint32_t *c = &w[i];
        if (i < 5 || (i >= 8 && i < 13) || (i >= 16 && i < 21)) *c = pair(rnd_range(-m, m), rnd_range(-m, m));
        else if (i < 8 || (i >= 13 && i < 16) || (i >= 21 && i < 24))
            *c = (uint32_t)(wide ? (int32_t)rnd() : rnd_range(-0x8000, 0x8000));
        else if (i == GTE_OFX || i == GTE_OFY) *c = (uint32_t)(wide ? (int32_t)rnd() : rnd_range(-0x200, 0x200) << 16);
        else if (i == GTE_H) *c = wide ? rnd() & 0xFFFF : (uint32_t)rnd_range(0x100, 0x400);
        else if (i == GTE_DQA) *c = (uint32_t)(wide ? (int32_t)(int16_t)rnd() : -0x1062);
        else if (i == GTE_DQB) *c = wide ? rnd() : 0x1400000;
        else *c = (uint32_t)(int32_t)(int16_t)rnd();
    }
    for (i = 0; i < 31; i++) {
        uint32_t *d = &w[31 + i];
        int32_t v = wide ? 0x7FFF : 0x400;
        if (i == GTE_SXYP || i == GTE_IRGB || i == GTE_ORGB) continue;
        if (i == GTE_VXY0 || i == GTE_VXY1 || i == GTE_VXY2) *d = pair(rnd_range(-v, v), rnd_range(-v, v));
        else if (i == GTE_VZ0 || i == GTE_VZ1 || i == GTE_VZ2)
            *d = (uint32_t)(wide ? (int32_t)rnd() : rnd_range(-v, v));
        else if (i >= GTE_IR0 && i <= GTE_IR3) *d = (uint32_t)(wide ? (int32_t)rnd() : rnd_range(-0x1000, 0x1000));
        else if (i >= GTE_SXY0 && i <= GTE_SXY2) *d = pair(rnd_range(-0x400, 0x3FF), rnd_range(-0x400, 0x3FF));
        else *d = rnd();
    }
    if (wide == 2) {
        for (i = 0; i < 31; i++) {
            int32_t big = (int32_t)(0x7FF00000u | (rnd() & 0xFFFFF));
            if (i < 5 || (i >= 8 && i < 13) || (i >= 16 && i < 21))
                w[i] = (rnd() & 1) ? pair(0x7FFF - (int32_t)(rnd() & 0xFF), 0x7FFF - (int32_t)(rnd() & 0xFF))
                                   : pair(-0x8000 + (int32_t)(rnd() & 0xFF), -0x8000 + (int32_t)(rnd() & 0xFF));
            else if (i < 8 || (i >= 13 && i < 16) || (i >= 21 && i < 24)) w[i] = (uint32_t)((rnd() & 1) ? big : -big);
        }
        for (i = GTE_VXY0; i <= GTE_VZ2; i++) w[31 + i] = (rnd() & 1) ? 0x7FFF7FFFu : 0x80008000u;
        for (i = GTE_IR1; i <= GTE_IR3; i++) w[31 + i] = (rnd() & 1) ? 0x7FFFu : 0xFFFF8000u;
    }
    w[CASE_WORDS - 2] = ops[op_index]; /* for tools/gte_probe.py */
    w[CASE_WORDS - 1] = (uint32_t)op_index;
}

static void run_case(const uint32_t *w, uint32_t *out) {
    int i;
    for (i = 0; i < 31; i++) Gte_Ctc2(i, w[i]);
    for (i = 0; i < 31; i++) {
        if (i == GTE_SXYP || i == GTE_IRGB || i == GTE_ORGB) continue;
        Gte_Mtc2(i, w[31 + i]);
    }
    Gte_Command(ops[w[CASE_WORDS - 1]]);
    for (i = 0; i < 32; i++) out[i] = Gte_Mfc2(i);
    out[32] = Gte_Cfc2(GTE_FLAG);
}

static int ncases(void) { return NOPS * CASES; }

static uint32_t *all_cases(void) {
    int n = ncases(), k;
    uint32_t *w = malloc((size_t)n * CASE_WORDS * 4);
    for (k = 0; k < n; k++) make_case(&w[k * CASE_WORDS], k / CASES, (k % CASES) * 4 / CASES >= 3 ? 2 : (k % CASES) >= CASES / 2);
    return w;
}

static void *read_file(const char *path, long *size) {
    FILE *f = fopen(path, "rb");
    void *p;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);
    p = malloc((size_t)*size);
    if (fread(p, 1, (size_t)*size, f) != (size_t)*size) { free(p); p = NULL; }
    fclose(f);
    return p;
}

static int failures_;
#define CHECK(cond, ...) do { if (!(cond)) { failures_++; if (failures_ < 40) { printf("FAIL: "); printf(__VA_ARGS__); printf("\n"); } } } while (0)

static void test_commands(const char *ref_path) {
    long size;
    uint32_t *ref = read_file(ref_path, &size);
    uint32_t *w = all_cases();
    int n = ncases(), k, i, bad_cases = 0;
    int per_op_bad[NOPS] = { 0 };
    if (!ref) { printf("commands: %s missing (run tools/gte_probe.py)\n", ref_path); failures_++; free(w); return; }
    if (size != (long)n * OUT_WORDS * 4) { printf("commands: %s has the wrong size\n", ref_path); failures_++; free(w); free(ref); return; }
    for (k = 0; k < n; k++) {
        uint32_t out[OUT_WORDS];
        const uint32_t *r = &ref[k * OUT_WORDS];
        int bad = 0;
        run_case(&w[k * CASE_WORDS], out);
        for (i = 0; i < OUT_WORDS; i++) {
            if (out[i] != r[i]) {
                if (!bad && bad_cases < 12)
                    printf("case %d op 0x%08X:", k, ops[k / CASES]);
                if (bad_cases < 12) printf(" %s%d %08X/%08X", i == 32 ? "FLAG" : "d", i == 32 ? 0 : i, out[i], r[i]);
                bad = 1;
            }
        }
        if (bad) {
            if (bad_cases < 12) printf(" (model/PS1)\n");
            bad_cases++;
            per_op_bad[k / CASES]++;
        }
    }
    for (i = 0; i < NOPS; i++)
        printf("  op 0x%08X: %d/%d cases match\n", ops[i], CASES - per_op_bad[i], CASES);
    printf("commands: %d/%d cases match the PS1 GTE reference\n", n - bad_cases, n);
    failures_ += bad_cases;
    free(w);
    free(ref);
}

static int16_t exe_h(const uint8_t *exe, uint32_t va, int i) {
    uint32_t o = va - 0x80010000u + 0x800u + (uint32_t)i * 2;
    return (int16_t)(exe[o] | exe[o + 1] << 8);
}

static void test_tables(const char *exe_path) {
    long size;
    uint8_t *exe = read_file(exe_path, &size);
    const short *sin_t = Psyq_SinTable(), *cs = Psyq_CosSinTable();
    int i, bad = 0;
    if (!exe) {
        printf("tables: %s missing, retail table check skipped\n", exe_path);
    } else {
        for (i = 0; i <= 0x400; i++) bad += sin_t[i] != exe_h(exe, 0x80049110u, i);
        CHECK(bad == 0, "rsin_tbl: %d entries differ from retail", bad);
        bad = 0;
        for (i = 0; i < 0x2000; i++) bad += cs[i] != exe_h(exe, 0x80049DC0u, i);
        CHECK(bad == 0, "rcossin_tbl: %d entries differ from retail", bad);
        bad = 0;
        for (i = 0; i <= 0x400; i++) bad += Psyq_RatanTable[i] != exe_h(exe, 0x8004DDC0u, i);
        CHECK(bad == 0, "ratan_tbl: %d entries differ from retail", bad);
        printf("tables: rsin_tbl 0x401, rcossin_tbl 0x1000 pairs, ratan_tbl 0x401 checked against %s\n", exe_path);
        free(exe);
    }
    /* rsin / rcos over all angles (and negative / wrapped ones) against rcossin_tbl. */
    bad = 0;
    for (i = -0x2000; i < 0x2000; i++) {
        int a = (i < 0 ? -i : i) & 0xFFF;
        int s = i < 0 ? -cs[a * 2] : cs[a * 2];
        bad += rsin(i) != s;
        bad += rcos(i) != cs[a * 2 + 1];
    }
    CHECK(bad == 0, "rsin / rcos: %d results differ from rcossin_tbl", bad);
    printf("rsin / rcos: angles -0x2000..0x1FFF checked\n");
}

static void test_functions(void) {
    MATRIX m;
    SVECTOR r, v, o;
    VECTOR s, lv, lo;
    int sxy, p, flag, z;

    InitGeom();
    CHECK(Gte_Cfc2(GTE_H) == 0x3E8 && (int)Gte_Cfc2(GTE_DQA) == -0x1062 && Gte_Cfc2(GTE_DQB) == 0x1400000 &&
              Gte_Cfc2(GTE_ZSF3) == 0x155 && Gte_Cfc2(GTE_ZSF4) == 0x100,
          "InitGeom control registers");

    /* ratan2: the four quadrants and the axes, 1/4096 turns. */
    CHECK(ratan2(0, 0) == 0, "ratan2(0, 0) = %d", ratan2(0, 0));
    CHECK(ratan2(0, 100) == 0, "ratan2(0, 100) = %d", ratan2(0, 100));
    CHECK(ratan2(100, 0) == 0x400, "ratan2(100, 0) = %d", ratan2(100, 0));
    CHECK(ratan2(100, 100) == 0x200, "ratan2(100, 100) = %d", ratan2(100, 100));
    CHECK(ratan2(0, -100) == 0x800, "ratan2(0, -100) = %d", ratan2(0, -100));
    CHECK(ratan2(-100, 0) == -0x400, "ratan2(-100, 0) = %d", ratan2(-100, 0));
    CHECK(ratan2(-100, -100) == -0x600, "ratan2(-100, -100) = %d", ratan2(-100, -100));

    /* RotMatrixYXZ: zero angles give the identity; 90 degrees about Y gives the textbook
     * matrix (rows: [c 0 s] [0 1 0] [-s 0 c]). */
    r.vx = r.vy = r.vz = 0;
    memset(&m, 0x55, sizeof(m));
    RotMatrixYXZ(&r, &m);
    CHECK(m.m[0][0] == 4096 && m.m[1][1] == 4096 && m.m[2][2] == 4096 && m.m[0][1] == 0 && m.m[0][2] == 0 &&
              m.m[1][0] == 0 && m.m[1][2] == 0 && m.m[2][0] == 0 && m.m[2][1] == 0,
          "RotMatrixYXZ(0) not identity");
    CHECK(m.t[0] == 0x55555555, "RotMatrixYXZ wrote the translation");
    r.vy = 0x400;
    RotMatrixYXZ(&r, &m);
    CHECK(m.m[0][0] == 0 && m.m[0][2] == 4096 && m.m[2][0] == -4096 && m.m[2][2] == 0 && m.m[1][1] == 4096,
          "RotMatrixYXZ(Y 90): %d %d %d / %d %d", m.m[0][0], m.m[0][2], m.m[2][0], m.m[2][2], m.m[1][1]);

    /* ScaleMatrix: identity scaled by (2.0, 0.5, 1.0); m[2][2]'s word carries the pad. */
    r.vy = 0;
    RotMatrixYXZ(&r, &m);
    s.vx = 0x2000; s.vy = 0x800; s.vz = 0x1000;
    ScaleMatrix(&m, &s);
    CHECK(m.m[0][0] == 8192 && m.m[1][1] == 2048 && m.m[2][2] == 4096, "ScaleMatrix diagonal");

    /* ApplyMatrixSV: identity * 2 on x. */
    v.vx = 100; v.vy = -50; v.vz = 7;
    ApplyMatrixSV(&m, &v, &o);
    CHECK(o.vx == 200 && o.vy == -25 && o.vz == 7, "ApplyMatrixSV: %d %d %d", o.vx, o.vy, o.vz);

    /* ApplyMatrixLV: long vector through the 15-bit split equals the exact product. */
    lv.vx = 0x123456; lv.vy = -0x654321; lv.vz = 0x7FFF;
    ApplyMatrixLV(&m, &lv, &lo);
    CHECK(lo.vx == 0x123456 * 2 && lo.vy == (-0x654321 >> 1) && lo.vz == 0x7FFF,
          "ApplyMatrixLV: %X %X %X", lo.vx, lo.vy, lo.vz);

    /* RotTransPers: identity rotation, TR (0, 0, 1000), H 1000: (100, 50, 0) lands at
     * (100, 50) plus the offset, SZ3 = 1000 -> 250; IR0 (depth cue) saturates at 0: FLAG bit 12. */
    r.vx = r.vy = r.vz = 0;
    RotMatrixYXZ(&r, &m);
    m.t[0] = 0; m.t[1] = 0; m.t[2] = 1000;
    SetRotMatrix(&m);
    SetTransMatrix(&m);
    SetGeomOffset(160, 120);
    v.vx = 100; v.vy = 50; v.vz = 0;
    z = RotTransPers(&v, &sxy, &p, &flag);
    CHECK((int16_t)sxy == 260 && (sxy >> 16) == 170 && z == 250 && flag == 0x1000,
          "RotTransPers: sxy %08X z %d flag %08X", (unsigned)sxy, z, (unsigned)flag);

    /* PushMatrix / PopMatrix keep RT and TR. */
    PushMatrix();
    m.t[2] = 5;
    SetTransMatrix(&m);
    PopMatrix();
    CHECK(Gte_Cfc2(GTE_TRZ) == 1000, "PopMatrix TRZ %d", (int)Gte_Cfc2(GTE_TRZ));
    printf("libgte functions: known values checked\n");
}

int main(int argc, char **argv) {
    const char *exe = "dumps/disc/SLUS_011.93", *ref = "tests/gte_ref.bin";
    int i;
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--write-cases") && i + 1 < argc) {
            uint32_t *w = all_cases();
            FILE *f = fopen(argv[++i], "wb");
            if (!f) return 1;
            fwrite(w, 4, (size_t)ncases() * CASE_WORDS, f);
            fclose(f);
            printf("%d cases (%d words each, %d ops) written\n", ncases(), CASE_WORDS, NOPS);
            return 0;
        }
        if (!strcmp(argv[i], "--exe") && i + 1 < argc) exe = argv[++i];
        else if (!strcmp(argv[i], "--ref") && i + 1 < argc) ref = argv[++i];
    }
    Gte_Reset();
    test_commands(ref);
    test_tables(exe);
    test_functions();
    printf(failures_ ? "gte_test: %d FAILED\n" : "gte_test: all passed\n", failures_);
    return failures_ ? 1 : 0;
}
