#include <string.h>

#include "backend/mdec.h"

/* ---- bitstream -> run-length codes (DecDCTvlc2) ---- */

/* MPEG-1 dct_coeff_next (ISO 11172-2 table B.5c..g) without the sign bit. "10" is the end of a
 * block, "000001" the escape (6-bit run, 10-bit signed level in STR version 2). Each block starts
 * with a 10-bit DC value; DC 0x1FF ends the frame. The header size counts the run-length codes
 * in whole 32-word units; the rest is 0xFE00. */
static const struct {
    const char *code;
    unsigned char run, level;
} ac_codes[] = {
    { "11", 0, 1 }, { "011", 1, 1 }, { "0100", 0, 2 }, { "0101", 2, 1 },
    { "00101", 0, 3 }, { "00111", 3, 1 }, { "00110", 4, 1 },
    { "000110", 1, 2 }, { "000111", 5, 1 }, { "000101", 6, 1 }, { "000100", 7, 1 },
    { "0000110", 0, 4 }, { "0000100", 2, 2 }, { "0000111", 8, 1 }, { "0000101", 9, 1 },
    { "00100110", 0, 5 }, { "00100001", 0, 6 }, { "00100101", 1, 3 }, { "00100100", 3, 2 },
    { "00100111", 10, 1 }, { "00100011", 11, 1 }, { "00100010", 12, 1 }, { "00100000", 13, 1 },
    { "0000001010", 0, 7 }, { "0000001100", 1, 4 }, { "0000001011", 2, 3 }, { "0000001111", 4, 2 },
    { "0000001001", 5, 2 }, { "0000001110", 14, 1 }, { "0000001101", 15, 1 }, { "0000001000", 16, 1 },
    { "000000011101", 0, 8 }, { "000000011000", 0, 9 }, { "000000010011", 0, 10 },
    { "000000010000", 0, 11 }, { "000000011011", 1, 5 }, { "000000010100", 2, 4 },
    { "000000011100", 3, 3 }, { "000000010010", 4, 3 }, { "000000011110", 6, 2 },
    { "000000010101", 7, 2 }, { "000000010001", 8, 2 }, { "000000011111", 17, 1 },
    { "000000011010", 18, 1 }, { "000000011001", 19, 1 }, { "000000010111", 20, 1 },
    { "000000010110", 21, 1 },
    { "0000000011010", 0, 12 }, { "0000000011001", 0, 13 }, { "0000000011000", 0, 14 },
    { "0000000010111", 0, 15 }, { "0000000010110", 1, 6 }, { "0000000010101", 1, 7 },
    { "0000000010100", 2, 5 }, { "0000000010011", 3, 4 }, { "0000000010010", 5, 3 },
    { "0000000010001", 9, 2 }, { "0000000010000", 10, 2 }, { "0000000011111", 22, 1 },
    { "0000000011110", 23, 1 }, { "0000000011101", 24, 1 }, { "0000000011100", 25, 1 },
    { "0000000011011", 26, 1 },
    { "00000000011111", 0, 16 }, { "00000000011110", 0, 17 }, { "00000000011101", 0, 18 },
    { "00000000011100", 0, 19 }, { "00000000011011", 0, 20 }, { "00000000011010", 0, 21 },
    { "00000000011001", 0, 22 }, { "00000000011000", 0, 23 }, { "00000000010111", 0, 24 },
    { "00000000010110", 0, 25 }, { "00000000010101", 0, 26 }, { "00000000010100", 0, 27 },
    { "00000000010011", 0, 28 }, { "00000000010010", 0, 29 }, { "00000000010001", 0, 30 },
    { "00000000010000", 0, 31 },
    { "000000000011000", 0, 32 }, { "000000000010111", 0, 33 }, { "000000000010110", 0, 34 },
    { "000000000010101", 0, 35 }, { "000000000010100", 0, 36 }, { "000000000010011", 0, 37 },
    { "000000000010010", 0, 38 }, { "000000000010001", 0, 39 }, { "000000000010000", 0, 40 },
    { "000000000011111", 1, 8 }, { "000000000011110", 1, 9 }, { "000000000011101", 1, 10 },
    { "000000000011100", 1, 11 }, { "000000000011011", 1, 12 }, { "000000000011010", 1, 13 },
    { "000000000011001", 1, 14 },
    { "0000000000010011", 1, 15 }, { "0000000000010010", 1, 16 }, { "0000000000010001", 1, 17 },
    { "0000000000010000", 1, 18 }, { "0000000000010100", 6, 3 }, { "0000000000011010", 11, 2 },
    { "0000000000011001", 12, 2 }, { "0000000000011000", 13, 2 }, { "0000000000010111", 14, 2 },
    { "0000000000010110", 15, 2 }, { "0000000000010101", 16, 2 }, { "0000000000011111", 27, 1 },
    { "0000000000011110", 28, 1 }, { "0000000000011101", 29, 1 }, { "0000000000011100", 30, 1 },
    { "0000000000011011", 31, 1 },
};

enum { AC_NONE, AC_CODE, AC_EOB, AC_ESCAPE };

/* Indexed by the next 16 bits: kind, code length (without sign), run, level. */
static struct {
    unsigned char kind, len, run, level;
} ac_lut[1 << 16];
static int ac_ready;

static void ac_fill(const char *code, int kind, int run, int level) {
    int len = (int)strlen(code);
    unsigned int prefix = 0;
    unsigned int i, n;
    int b;

    for (b = 0; b < len; b++) {
        prefix = prefix << 1 | (unsigned int)(code[b] - '0');
    }
    n = 1u << (16 - len);
    for (i = 0; i < n; i++) {
        unsigned int k = prefix << (16 - len) | i;
        ac_lut[k].kind = (unsigned char)kind;
        ac_lut[k].len = (unsigned char)len;
        ac_lut[k].run = (unsigned char)run;
        ac_lut[k].level = (unsigned char)level;
    }
}

static void ac_init(void) {
    size_t i;

    for (i = 0; i < sizeof(ac_codes) / sizeof(ac_codes[0]); i++) {
        ac_fill(ac_codes[i].code, AC_CODE, ac_codes[i].run, ac_codes[i].level);
    }
    ac_fill("10", AC_EOB, 0, 0);
    ac_fill("000001", AC_ESCAPE, 0, 0);
    ac_ready = 1;
}

/* Bits come from 16-bit little-endian words, most significant bit first. */
typedef struct {
    const uint8_t *p;
    uint32_t buf; /* next bits, left-aligned */
    int have;     /* valid bits in buf */
} Bits;

static void bits_fill(Bits *b) {
    while (b->have <= 16) {
        b->buf |= (uint32_t)(b->p[0] | b->p[1] << 8) << (16 - b->have);
        b->p += 2;
        b->have += 16;
    }
}

static unsigned int bits_peek16(Bits *b) {
    bits_fill(b);
    return b->buf >> 16;
}

static unsigned int bits_get(Bits *b, int n) {
    unsigned int v;

    bits_fill(b);
    v = b->buf >> (32 - n);
    b->buf <<= n;
    b->have -= n;
    return v;
}

int Mdec_Vlc(const uint8_t *bs, uint32_t *out, int out_words) {
    unsigned int words = bs[0] | bs[1] << 8;
    unsigned int magic = bs[2] | bs[3] << 8;
    unsigned int q = bs[4] | bs[5] << 8;
    unsigned int version = bs[6] | bs[7] << 8;
    uint16_t *o = (uint16_t *)(out + 1);
    unsigned int want = words * 2, n = 0;
    Bits b = { bs + 8, 0, 0 };

    out[0] = 0x38000000;
    if (!ac_ready) {
        ac_init();
    }
    if (magic != 0x3800 || (version != 1 && version != 2) || q > 63 || (int)words + 1 > out_words) {
        return -1;
    }
    while (n < want) {
        int dc = (int)bits_get(&b, 10);

        if (dc == 0x1FF) {
            break; /* end of frame */
        }
        o[n++] = (uint16_t)(q << 10 | (unsigned int)dc);
        for (;;) {
            unsigned int k = bits_peek16(&b);
            int run, level;

            if (n >= want) {
                return -1; /* the block runs past the size in the header */
            }
            switch (ac_lut[k].kind) {
            case AC_EOB:
                bits_get(&b, 2);
                o[n++] = 0xFE00;
                goto next_block;
            case AC_ESCAPE:
                bits_get(&b, 6);
                run = (int)bits_get(&b, 6);
                level = (int)bits_get(&b, 10);
                break;
            case AC_CODE:
                bits_get(&b, ac_lut[k].len);
                run = ac_lut[k].run;
                level = bits_get(&b, 1) ? -ac_lut[k].level : ac_lut[k].level;
                break;
            default:
                return -1;
            }
            o[n++] = (uint16_t)(run << 10 | (level & 0x3FF));
        }
    next_block:;
    }
    while (n < want) {
        o[n++] = 0xFE00; /* the size is whole 32-word units */
    }
    out[0] = 0x38000000 | words;
    return (int)words + 1;
}

/* ---- MDEC: run-length codes -> pixels (DecDCTin / DecDCTout) ---- */

static const unsigned char zigzag[64] = {
    0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18, 11, 4, 5,
    12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13, 6, 7, 14, 21, 28,
    35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51,
    58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63,
};

/* Psy-Q's default table (DecDCTReset): the MPEG-1 intra matrix with 2 for DC, row major. Luma and
 * chroma use the same one. */
static const unsigned char quant[64] = {
    2, 16, 19, 22, 26, 27, 29, 34,
    16, 16, 22, 24, 27, 29, 34, 37,
    19, 22, 26, 27, 29, 34, 34, 38,
    22, 22, 26, 27, 29, 34, 37, 40,
    22, 26, 27, 29, 32, 35, 40, 48,
    26, 27, 29, 32, 35, 40, 48, 58,
    26, 27, 29, 34, 38, 46, 56, 69,
    27, 29, 35, 38, 46, 56, 69, 83,
};

/* The MDEC's IDCT matrix (Psy-Q's scale table): row u, column x. */
static const int16_t scale[64] = {
    0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82,
    0x7D8A, 0x6A6D, 0x471C, 0x18F8, -0x18F9, -0x471D, -0x6A6E, -0x7D8B,
    0x7641, 0x30FB, -0x30FC, -0x7642, -0x7642, -0x30FC, 0x30FB, 0x7641,
    0x6A6D, -0x18F9, -0x7D8B, -0x471D, 0x471C, 0x7D8A, 0x18F8, -0x6A6E,
    0x5A82, -0x5A83, -0x5A83, 0x5A82, 0x5A82, -0x5A83, -0x5A83, 0x5A82,
    0x471C, -0x7D8B, 0x18F8, 0x6A6D, -0x6A6E, -0x18F9, 0x7D8A, -0x471D,
    0x30FB, -0x7642, 0x7641, -0x30FC, -0x30FC, 0x7641, -0x7642, 0x30FB,
    0x18F8, -0x471D, 0x6A6D, -0x7D8B, 0x7D8A, -0x6A6E, 0x471C, -0x18F9,
};

static const uint16_t *m_in, *m_end;
static int m_rgb24, m_stp;

void Mdec_Start(const uint32_t *in, int rgb24, int stp) {
    m_in = (const uint16_t *)(in + 1);
    m_end = m_in + (in[0] & 0xFFFF) * 2;
    m_rgb24 = rgb24;
    m_stp = stp;
}

static int signed10(unsigned int v) {
    return (int)(v & 0x3FF) - (int)((v & 0x200) << 1);
}

static int clamp(int v, int lo, int hi) {
    return v < lo ? lo : v > hi ? hi : v;
}

/* Two 1-D passes, each transposes: out[x + y * 8] = sum over u of in[y + u * 8] * scale[u][x]. */
static void idct(int *blk) {
    int tmp[64];
    int *src = blk, *dst = tmp;
    int pass, x, y, u;

    for (pass = 0; pass < 2; pass++) {
        for (x = 0; x < 8; x++) {
            for (y = 0; y < 8; y++) {
                int sum = 0;

                for (u = 0; u < 8; u++) {
                    sum += src[y + u * 8] * scale[x + u * 8];
                }
                dst[x + y * 8] = (sum + 0x8000) >> 16;
            }
        }
        src = tmp;
        dst = blk;
    }
}

/* One block from the stream (0 if the stream has ended). */
static int read_block(int *blk) {
    unsigned int n;
    int qs, k;

    memset(blk, 0, 64 * sizeof(int));
    do {
        if (m_in >= m_end) {
            return 0;
        }
        n = *m_in++;
    } while (n == 0xFE00);
    qs = (int)(n >> 10);
    k = 0;
    if (qs == 0) {
        blk[0] = clamp(signed10(n) * 2, -0x400, 0x3FF);
    } else {
        blk[0] = clamp(signed10(n) * quant[0], -0x400, 0x3FF);
    }
    while (m_in < m_end) {
        n = *m_in++;
        if (n == 0xFE00) {
            break;
        }
        k += (int)(n >> 10) + 1;
        if (k > 63) {
            break;
        }
        if (qs == 0) {
            blk[k] = clamp(signed10(n) * 2, -0x400, 0x3FF);
        } else {
            blk[zigzag[k]] = clamp((signed10(n) * quant[zigzag[k]] * qs + 4) >> 3, -0x400, 0x3FF);
        }
    }
    idct(blk);
    return 1;
}

/* One 16x16 macroblock (Cr, Cb, Y top left, top right, bottom left, bottom right) into out. */
static void macroblock(uint32_t *out) {
    int cr[64], cb[64], y[4][64];
    int ok = read_block(cr) & read_block(cb);
    int i, px, py;

    for (i = 0; i < 4; i++) {
        ok &= read_block(y[i]);
    }
    for (py = 0; py < 16; py++) {
        for (px = 0; px < 16; px++) {
            int c = (px >> 1) + (py >> 1) * 8;
            int lum = y[(py >> 3) * 2 + (px >> 3)][(px & 7) + (py & 7) * 8];
            int r = 0, g = 0, b = 0;

            if (ok) {
                r = clamp(lum + ((cr[c] * 1436) >> 10), -128, 127) + 128;
                g = clamp(lum - ((cb[c] * 352 + cr[c] * 731) >> 10), -128, 127) + 128;
                b = clamp(lum + ((cb[c] * 1815) >> 10), -128, 127) + 128;
            }
            if (m_rgb24) {
                uint8_t *o = (uint8_t *)out + (py * 16 + px) * 3;
                o[0] = (uint8_t)r;
                o[1] = (uint8_t)g;
                o[2] = (uint8_t)b;
            } else {
                ((uint16_t *)out)[py * 16 + px] =
                    (uint16_t)((r >> 3) | (g >> 3) << 5 | (b >> 3) << 10 | m_stp << 15);
            }
        }
    }
}

void Mdec_Out(uint32_t *out, int words) {
    int mb = m_rgb24 ? 192 : 128;

    while (words >= mb) {
        macroblock(out);
        out += mb;
        words -= mb;
    }
}
