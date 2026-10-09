#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backend/psxgpu.h"
#include "host/host.h"
#include "host/ui.h"

/* Screenshots for checks (P1.4): the display area as shown and the whole VRAM (1024x512, 15-bit
 * colour, mask bit ignored), each as an RGB PNG; with HD output on (PG.1) also <tag>_hd.png. No library: the zlib stream uses stored
 * (uncompressed) deflate blocks, so test shots stay byte-identical between builds; F12 shots
 * (PR.23) are compressed by the small deflate encoder below (lossless, same pixels). */

static uint32_t crc_table[256];

static void crc_init(void) {
    uint32_t c;
    int n, k;

    for (n = 0; n < 256; n++) {
        c = (uint32_t)n;
        for (k = 0; k < 8; k++) {
            c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
        }
        crc_table[n] = c;
    }
}

static uint32_t crc(uint32_t c, const uint8_t *p, size_t n) {
    c ^= 0xFFFFFFFFu;
    while (n--) {
        c = crc_table[(c ^ *p++) & 0xFF] ^ (c >> 8);
    }
    return c ^ 0xFFFFFFFFu;
}

static void be32(uint8_t *p, uint32_t v) {
    p[0] = (uint8_t)(v >> 24);
    p[1] = (uint8_t)(v >> 16);
    p[2] = (uint8_t)(v >> 8);
    p[3] = (uint8_t)v;
}

/* crc() chains like zlib's crc32: crc(crc(0, type), data) is the CRC of type + data. */
static void chunk(FILE *f, const char *type, const uint8_t *data, uint32_t n) {
    uint8_t b[4];

    be32(b, n);
    fwrite(b, 1, 4, f);
    fwrite(type, 1, 4, f);
    if (n) {
        fwrite(data, 1, n, f);
    }
    be32(b, crc(crc(0, (const uint8_t *)type, 4), data, n));
    fwrite(b, 1, 4, f);
}

/* PR.23 deflate encoder: per-row PNG filters (smallest sum of differences), LZ77 over a 32 KB
 * window with hash chains, one dynamic Huffman block per BLOCK_SYMS symbols. */

typedef struct {
    uint8_t *buf;
    size_t n, cap;
    uint32_t bits;
    int nbits;
    int fail;
} BitOut;

static void bo_byte(BitOut *o, uint8_t v) {
    if (o->n == o->cap) {
        size_t cap = o->cap ? o->cap * 2 : (size_t)1 << 20;
        uint8_t *p = realloc(o->buf, cap);

        if (p == NULL) {
            o->fail = 1;
            return;
        }
        o->buf = p;
        o->cap = cap;
    }
    o->buf[o->n++] = v;
}

/* n <= 16 bits, LSB first */
static void bo_put(BitOut *o, uint32_t v, int n) {
    o->bits |= v << o->nbits;
    o->nbits += n;
    while (o->nbits >= 8) {
        bo_byte(o, (uint8_t)o->bits);
        o->bits >>= 8;
        o->nbits -= 8;
    }
}

static void bo_flush(BitOut *o) {
    if (o->nbits > 0) {
        bo_byte(o, (uint8_t)o->bits);
    }
    o->bits = 0;
    o->nbits = 0;
}

/* Huffman code lengths for freq[0..n), n <= 288, at most maxbits; unused symbols get 0. Too deep:
 * halve the counts and build again. One used symbol gets a second length-1 code beside it, since
 * zlib refuses an incomplete code-length code. */
static void huff_lengths(const uint32_t *freq_in, int n, int maxbits, uint8_t *len) {
    uint32_t freq[288], w[576];
    int sym[288], parent[576], depth[576];
    int i, j, count, lq, iq, end, max;

    memcpy(freq, freq_in, n * sizeof(uint32_t));
    for (;;) {
        count = 0;
        for (i = 0; i < n; i++) {
            len[i] = 0;
            if (freq[i]) {
                sym[count++] = i;
            }
        }
        if (count == 0) {
            return;
        }
        if (count == 1) {
            len[sym[0]] = 1;
            len[sym[0] == 0 ? 1 : 0] = 1;
            return;
        }
        for (i = 1; i < count; i++) { /* sort by count */
            int t = sym[i];
            for (j = i; j > 0 && freq[sym[j - 1]] > freq[t]; j--) {
                sym[j] = sym[j - 1];
            }
            sym[j] = t;
        }
        for (i = 0; i < count; i++) {
            w[i] = freq[sym[i]];
        }
        /* two queues: sorted leaves, then the inner nodes in the order they are made */
        lq = 0;
        iq = count;
        end = count;
        for (i = 0; i < count - 1; i++) {
            int a = (lq < count && (iq == end || w[lq] <= w[iq])) ? lq++ : iq++;
            int b = (lq < count && (iq == end || w[lq] <= w[iq])) ? lq++ : iq++;

            w[end] = w[a] + w[b];
            parent[a] = end;
            parent[b] = end;
            end++;
        }
        depth[end - 1] = 0;
        for (i = end - 2; i >= 0; i--) {
            depth[i] = depth[parent[i]] + 1;
        }
        max = 0;
        for (i = 0; i < count; i++) {
            len[sym[i]] = (uint8_t)depth[i];
            if (depth[i] > max) {
                max = depth[i];
            }
        }
        if (max <= maxbits) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (freq[i]) {
                freq[i] = (freq[i] >> 1) | 1;
            }
        }
    }
}

/* canonical codes, bit-reversed for the LSB-first stream */
static void huff_codes(const uint8_t *len, int n, uint16_t *code) {
    int count[16] = { 0 }, next[16], i, b, c = 0;

    for (i = 0; i < n; i++) {
        count[len[i]]++;
    }
    count[0] = 0;
    for (b = 1; b < 16; b++) {
        c = (c + count[b - 1]) << 1;
        next[b] = c;
    }
    for (i = 0; i < n; i++) {
        if (len[i]) {
            uint32_t v = (uint32_t)next[len[i]]++, r = 0;

            for (b = 0; b < len[i]; b++) {
                r = (r << 1) | (v & 1);
                v >>= 1;
            }
            code[i] = (uint16_t)r;
        }
    }
}

static const uint16_t len_base[29] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
                                       35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258 };
static const uint8_t len_extra[29] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
                                       3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0 };
static const uint16_t dist_base[30] = { 1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257,
                                        385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193,
                                        12289, 16385, 24577 };
static const uint8_t dist_extra[30] = { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7,
                                        7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13 };
static const uint8_t cl_order[19] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15 };

static int len_code(int l) {
    int c = 28;

    while (len_base[c] > l) {
        c--;
    }
    return c;
}

static int dist_code(int d) {
    int c = 29;

    while (dist_base[c] > d) {
        c--;
    }
    return c;
}

/* d == 0: literal byte v; else a match of length v at distance d */
typedef struct {
    uint16_t v, d;
} Sym;

#define BLOCK_SYMS 65536

static void emit_block(BitOut *o, const Sym *s, int ns, int last) {
    uint32_t lf[286] = { 0 }, df[30] = { 0 }, cf[19] = { 0 };
    uint8_t ll[316], cl[19], seq[316], op[316], opx[316];
    uint16_t lc[286], dc[30], cc[19];
    int i, nlit, ndist, nops = 0, ncl, total, any = 0;

    for (i = 0; i < ns; i++) {
        if (s[i].d == 0) {
            lf[s[i].v]++;
        } else {
            lf[257 + len_code(s[i].v)]++;
            df[dist_code(s[i].d)]++;
            any = 1;
        }
    }
    lf[256] = 1;
    if (!any) {
        df[0] = 1;
    }
    huff_lengths(lf, 286, 15, ll);
    huff_lengths(df, 30, 15, ll + 286);
    huff_codes(ll, 286, lc);
    huff_codes(ll + 286, 30, dc);
    for (nlit = 286; nlit > 257 && ll[nlit - 1] == 0; nlit--) {
    }
    for (ndist = 30; ndist > 1 && ll[286 + ndist - 1] == 0; ndist--) {
    }
    memcpy(seq, ll, nlit);
    memcpy(seq + nlit, ll + 286, ndist);
    total = nlit + ndist;
    /* code lengths, run-length coded: 16 repeats the last length 3..6 times, 17 / 18 zeros */
    for (i = 0; i < total;) {
        int l = seq[i], run = 1;

        while (i + run < total && seq[i + run] == l) {
            run++;
        }
        if (l == 0 && run >= 3) {
            int r = run > 138 ? 138 : run;

            op[nops] = r >= 11 ? 18 : 17;
            opx[nops++] = (uint8_t)(r >= 11 ? r - 11 : r - 3);
            i += r;
        } else if (l != 0 && run >= 4) {
            op[nops] = (uint8_t)l;
            opx[nops++] = 0;
            i++;
            run--;
            while (run >= 3) {
                int r = run > 6 ? 6 : run;

                op[nops] = 16;
                opx[nops++] = (uint8_t)(r - 3);
                i += r;
                run -= r;
            }
        } else {
            op[nops] = (uint8_t)l;
            opx[nops++] = 0;
            i++;
        }
    }
    for (i = 0; i < nops; i++) {
        cf[op[i]]++;
    }
    huff_lengths(cf, 19, 7, cl);
    huff_codes(cl, 19, cc);
    for (ncl = 19; ncl > 4 && cl[cl_order[ncl - 1]] == 0; ncl--) {
    }

    bo_put(o, last ? 1 : 0, 1);
    bo_put(o, 2, 2); /* dynamic Huffman */
    bo_put(o, (uint32_t)(nlit - 257), 5);
    bo_put(o, (uint32_t)(ndist - 1), 5);
    bo_put(o, (uint32_t)(ncl - 4), 4);
    for (i = 0; i < ncl; i++) {
        bo_put(o, cl[cl_order[i]], 3);
    }
    for (i = 0; i < nops; i++) {
        bo_put(o, cc[op[i]], cl[op[i]]);
        if (op[i] == 16) {
            bo_put(o, opx[i], 2);
        } else if (op[i] == 17) {
            bo_put(o, opx[i], 3);
        } else if (op[i] == 18) {
            bo_put(o, opx[i], 7);
        }
    }
    for (i = 0; i < ns; i++) {
        if (s[i].d == 0) {
            bo_put(o, lc[s[i].v], ll[s[i].v]);
        } else {
            int c = len_code(s[i].v), d = dist_code(s[i].d);

            bo_put(o, lc[257 + c], ll[257 + c]);
            if (len_extra[c]) {
                bo_put(o, s[i].v - len_base[c], len_extra[c]);
            }
            bo_put(o, dc[d], ll[286 + d]);
            if (dist_extra[d]) {
                bo_put(o, s[i].d - dist_base[d], dist_extra[d]);
            }
        }
    }
    bo_put(o, lc[256], ll[256]);
}

#define WIN 32768
#define HASH_BITS 15
#define MAX_CHAIN 48

static uint32_t hash3(const uint8_t *p) {
    return ((uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16) * 2654435761u >> (32 - HASH_BITS);
}

static int deflate_buf(BitOut *o, const uint8_t *d, int32_t n) {
    int32_t *head = malloc(sizeof(int32_t) << HASH_BITS);
    int32_t *prev = malloc(sizeof(int32_t) * WIN);
    Sym *s = malloc(sizeof(Sym) * BLOCK_SYMS);
    int32_t i = 0, k;
    int ns = 0;

    if (head == NULL || prev == NULL || s == NULL) {
        free(head);
        free(prev);
        free(s);
        return 0;
    }
    for (k = 0; k < 1 << HASH_BITS; k++) {
        head[k] = -1;
    }
    while (i < n) {
        int best = 0, bestd = 0;

        if (i + 3 <= n) {
            uint32_t h = hash3(d + i);
            int32_t p = head[h];
            int chain = MAX_CHAIN, max = n - i < 258 ? n - i : 258;

            while (p >= 0 && i - p <= WIN && chain-- > 0) {
                if (d[p + best] == d[i + best]) {
                    int l = 0;

                    while (l < max && d[p + l] == d[i + l]) {
                        l++;
                    }
                    if (l > best) {
                        best = l;
                        bestd = i - p;
                        if (l >= max) {
                            break;
                        }
                    }
                }
                p = prev[p & (WIN - 1)];
            }
            prev[i & (WIN - 1)] = head[h];
            head[h] = i;
        }
        if (best >= 3) {
            s[ns].v = (uint16_t)best;
            s[ns++].d = (uint16_t)bestd;
            for (k = i + 1; k < i + best && k + 3 <= n; k++) {
                uint32_t h = hash3(d + k);

                prev[k & (WIN - 1)] = head[h];
                head[h] = k;
            }
            i += best;
        } else {
            s[ns].v = d[i];
            s[ns++].d = 0;
            i++;
        }
        if (ns == BLOCK_SYMS) {
            emit_block(o, s, ns, i == n);
            ns = 0;
        }
    }
    if (ns > 0 || n == 0) {
        emit_block(o, s, ns, 1);
    }
    free(head);
    free(prev);
    free(s);
    return !o->fail;
}

static int paeth(int a, int b, int c) {
    int p = a + b - c, pa = abs(p - a), pb = abs(p - b), pc = abs(p - c);

    return pa <= pb && pa <= pc ? a : pb <= pc ? b : c;
}

/* one row filtered with filter f into out (out[0] = f); cur / up: w * 3 bytes, up NULL on row 0 */
static void filter_row(uint8_t *out, const uint8_t *cur, const uint8_t *up, int n, int f) {
    int x;

    out[0] = (uint8_t)f;
    for (x = 0; x < n; x++) {
        int a = x >= 3 ? cur[x - 3] : 0, b = up ? up[x] : 0, c = x >= 3 && up ? up[x - 3] : 0;
        int v = cur[x];

        switch (f) {
        case 1: v -= a; break;
        case 2: v -= b; break;
        case 3: v -= (a + b) >> 1; break;
        case 4: v -= paeth(a, b, c); break;
        }
        out[1 + x] = (uint8_t)v;
    }
}

/* pixels: w * h words 0x00RRGGBB; pack 0 = stored deflate blocks, filter none (test shots);
 * pack 1 = filtered + compressed (F12). */
static int write_png(const char *path, const uint32_t *pixels, int w, int h, int pack) {
    static const uint8_t sig[8] = { 0x89, 'P', 'N', 'G', '\r', '\n', 0x1A, '\n' };
    size_t row = 1 + (size_t)w * 3;
    size_t raw_n = (size_t)h * row;
    uint8_t *raw = malloc(raw_n);
    uint8_t *rgb = malloc(2 * (size_t)w * 3 + 5 * row);
    BitOut z = { 0 };
    uint8_t ihdr[13];
    uint32_t a = 1, b = 0;
    size_t i, at;
    FILE *f;
    int x, y;

    if (raw == NULL || rgb == NULL) {
        free(raw);
        free(rgb);
        return 0;
    }
    at = 0;
    for (y = 0; y < h; y++) {
        uint8_t *cur = rgb + (size_t)(y & 1) * w * 3;
        uint8_t *up = y > 0 ? rgb + (size_t)((y - 1) & 1) * w * 3 : NULL;

        for (x = 0; x < w; x++) {
            uint32_t p = pixels[(size_t)y * w + x];
            cur[x * 3] = (uint8_t)(p >> 16);
            cur[x * 3 + 1] = (uint8_t)(p >> 8);
            cur[x * 3 + 2] = (uint8_t)p;
        }
        if (!pack) {
            filter_row(raw + at, cur, up, w * 3, 0);
        } else {
            /* the filter with the smallest sum of |signed bytes| (the usual PNG heuristic) */
            uint8_t *trial = rgb + 2 * (size_t)w * 3;
            uint32_t best_sum = 0xFFFFFFFFu;
            int fl, best = 0;

            for (fl = 0; fl < 5; fl++) {
                uint8_t *t = trial + fl * row;
                uint32_t sum = 0;

                filter_row(t, cur, up, w * 3, fl);
                for (i = 1; i < row; i++) {
                    sum += t[i] < 128 ? t[i] : 256 - t[i];
                }
                if (sum < best_sum) {
                    best_sum = sum;
                    best = fl;
                }
            }
            memcpy(raw + at, trial + best * row, row);
        }
        at += row;
    }
    free(rgb);
    bo_byte(&z, 0x78);
    bo_byte(&z, 0x01);
    if (pack) {
        if (raw_n > 0x7FFFFFFF || !deflate_buf(&z, raw, (int32_t)raw_n)) {
            free(raw);
            free(z.buf);
            return 0;
        }
        bo_flush(&z);
    } else {
        for (i = 0; i < raw_n; i += 65535) {
            size_t n = raw_n - i < 65535 ? raw_n - i : 65535;
            bo_byte(&z, (uint8_t)(i + n == raw_n));
            bo_byte(&z, (uint8_t)n);
            bo_byte(&z, (uint8_t)(n >> 8));
            bo_byte(&z, (uint8_t)~n);
            bo_byte(&z, (uint8_t)(~n >> 8));
            for (at = 0; at < n; at++) {
                bo_byte(&z, raw[i + at]);
            }
        }
    }
    for (i = 0; i < raw_n; i++) {
        a = (a + raw[i]) % 65521;
        b = (b + a) % 65521;
    }
    bo_byte(&z, (uint8_t)(b >> 8));
    bo_byte(&z, (uint8_t)b);
    bo_byte(&z, (uint8_t)(a >> 8));
    bo_byte(&z, (uint8_t)a);
    free(raw);
    if (z.fail) {
        free(z.buf);
        return 0;
    }

    f = fopen(path, "wb");
    if (f == NULL) {
        free(z.buf);
        return 0;
    }
    be32(ihdr, (uint32_t)w);
    be32(ihdr + 4, (uint32_t)h);
    ihdr[8] = 8;  /* bit depth */
    ihdr[9] = 2;  /* RGB */
    ihdr[10] = 0;
    ihdr[11] = 0;
    ihdr[12] = 0;
    fwrite(sig, 1, 8, f);
    chunk(f, "IHDR", ihdr, 13);
    chunk(f, "IDAT", z.buf, (uint32_t)z.n);
    chunk(f, "IEND", NULL, 0);
    fclose(f);
    free(z.buf);
    return 1;
}

void Host_SaveShot(const char *dir, const char *tag) {
    static uint32_t pixels[PSXGPU_VRAM_W * PSXGPU_VRAM_H];
    char path[1024];
    int w, h, x, y;

    if (crc_table[1] == 0) {
        crc_init();
    }
    if (!PsxGpu_ReadDisplay(pixels, &w, &h)) {
        w = 320;
        h = 240;
        for (x = 0; x < w * h; x++) {
            pixels[x] = 0;
        }
    }
    snprintf(path, sizeof(path), "%s/%s_display.png", dir, tag);
    if (write_png(path, pixels, w, h, 0)) {
        printf("[shot] %s (%dx%d)\n", path, w, h);
    } else {
        printf("[shot] cannot write %s\n", path);
    }
    for (y = 0; y < PSXGPU_VRAM_H; y++) {
        for (x = 0; x < PSXGPU_VRAM_W; x++) {
            uint16_t c = PsxGpu_Vram[y][x];
            uint32_t r = c & 31, g = (c >> 5) & 31, b = (c >> 10) & 31;
            pixels[y * PSXGPU_VRAM_W + x] =
                (((r << 3) | (r >> 2)) << 16) | (((g << 3) | (g >> 2)) << 8) | ((b << 3) | (b >> 2));
        }
    }
    snprintf(path, sizeof(path), "%s/%s_vram.png", dir, tag);
    if (write_png(path, pixels, PSXGPU_VRAM_W, PSXGPU_VRAM_H, 0)) {
        printf("[shot] %s (1024x512)\n", path);
    } else {
        printf("[shot] cannot write %s\n", path);
    }
    /* HD output (PG.1): the display area as the window shows it at --scale N */
    if (PsxGpu_ReadDisplayHd(NULL, &w, &h)) {
        uint32_t *hd = malloc((size_t)w * h * sizeof(uint32_t));
        if (hd != NULL && PsxGpu_ReadDisplayHd(hd, &w, &h)) {
            snprintf(path, sizeof(path), "%s/%s_hd.png", dir, tag);
            if (write_png(path, hd, w, h, 0)) {
                printf("[shot] %s (%dx%d)\n", path, w, h);
            } else {
                printf("[shot] cannot write %s\n", path);
            }
        }
        free(hd);
    }
    Ui_Shot(dir, tag); /* --settings-ui / --devui headless: the window picture with the UI */
    fflush(stdout);
}

/* UI shots (host/ui.cpp): pixels w * h words 0x00RRGGBB. */
int Host_WritePng(const char *path, const uint32_t *pixels, int w, int h) {
    if (crc_table[1] == 0) {
        crc_init();
    }
    return write_png(path, pixels, w, h, 0);
}

/* F12 (PR.23): compressed; called from the shot thread, so the CRC table is built here first */
int Host_WritePngPacked(const char *path, const uint32_t *pixels, int w, int h) {
    if (crc_table[1] == 0) {
        crc_init();
    }
    return write_png(path, pixels, w, h, 1);
}
