#include <string.h>

#include "host/sha256.h"

static const uint32_t k[64] = {
    0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
    0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
    0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
    0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
    0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
    0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
    0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
    0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2,
};

#define ROR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

static void compress(uint32_t *h, const uint8_t *p) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, hh, t1, t2;
    int i;

    for (i = 0; i < 16; i++) {
        w[i] = (uint32_t)p[i * 4] << 24 | (uint32_t)p[i * 4 + 1] << 16 | (uint32_t)p[i * 4 + 2] << 8 | p[i * 4 + 3];
    }
    for (i = 16; i < 64; i++) {
        uint32_t s0 = ROR(w[i - 15], 7) ^ ROR(w[i - 15], 18) ^ (w[i - 15] >> 3);
        uint32_t s1 = ROR(w[i - 2], 17) ^ ROR(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }
    a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], hh = h[7];
    for (i = 0; i < 64; i++) {
        t1 = hh + (ROR(e, 6) ^ ROR(e, 11) ^ ROR(e, 25)) + ((e & f) ^ (~e & g)) + k[i] + w[i];
        t2 = (ROR(a, 2) ^ ROR(a, 13) ^ ROR(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
        hh = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;
    }
    h[0] += a, h[1] += b, h[2] += c, h[3] += d, h[4] += e, h[5] += f, h[6] += g, h[7] += hh;
}

void Sha256_Init(Sha256 *s) {
    static const uint32_t iv[8] = { 0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
                                    0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19 };

    memcpy(s->state, iv, sizeof(iv));
    s->length = 0;
    s->used = 0;
}

void Sha256_Update(Sha256 *s, const void *data, size_t size) {
    const uint8_t *p = data;

    s->length += size;
    if (s->used != 0) {
        size_t n = 64 - s->used < size ? 64 - s->used : size;
        memcpy(s->block + s->used, p, n);
        s->used += n, p += n, size -= n;
        if (s->used < 64) {
            return;
        }
        compress(s->state, s->block);
        s->used = 0;
    }
    for (; size >= 64; p += 64, size -= 64) {
        compress(s->state, p);
    }
    memcpy(s->block, p, size);
    s->used = size;
}

void Sha256_Final(Sha256 *s, uint8_t digest[32]) {
    uint64_t bits = s->length * 8;
    int i;

    s->block[s->used++] = 0x80;
    if (s->used > 56) {
        memset(s->block + s->used, 0, 64 - s->used);
        compress(s->state, s->block);
        s->used = 0;
    }
    memset(s->block + s->used, 0, 56 - s->used);
    for (i = 0; i < 8; i++) {
        s->block[56 + i] = (uint8_t)(bits >> (56 - i * 8));
    }
    compress(s->state, s->block);
    for (i = 0; i < 32; i++) {
        digest[i] = (uint8_t)(s->state[i / 4] >> (24 - (i % 4) * 8));
    }
}
