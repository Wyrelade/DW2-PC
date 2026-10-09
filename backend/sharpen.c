#include <math.h>
#include <stdint.h>

#if defined(__x86_64__) || defined(__i386__)
#include <emmintrin.h>
#define HAVE_SSE2 1
#if !defined(__SSE2__)
#define SSE2_FN __attribute__((target("sse2"))) /* 32-bit x86 build: SSE2 for this code only */
#else
#define SSE2_FN
#endif
#endif

#include "backend/psxgpu_hd.h"

/* PR.2b contrast adaptive sharpening on the CPU (the software renderer's HD picture), the same
 * filter as backend/shaders/sharpen.frag. Per channel, with the 3x3 neighbourhood
 *   a b c
 *   d e f
 *   g h i
 * (values 0..1) mn = min(b, d, e, f, h) + min(all 9), mx = max(b, d, e, f, h) + max(all 9),
 * amp = sqrt(clamp(min(mn, 2 - mx) / mx)), w = amp * peak with peak = -1 / mix(8, 5, sharpness),
 * out = (e + w (b + d + f + h)) / (1 + 4 w). On x86 four pixels at a time with SSE2 (minimum and
 * maximum on the bytes, the rest in float); the edge pixels (rows and columns clamp) and other
 * CPUs use the scalar code. The 4th byte is copied. Rows are split between the HD drawing
 * threads (PsxHd_Parallel). */

typedef struct {
    const uint32_t *in;
    uint32_t *out;
    int w, h;
    float peak;
} Job;

static inline float minf(float a, float b) {
    return a < b ? a : b;
}

static inline float maxf(float a, float b) {
    return a > b ? a : b;
}

/* one pixel, scalar */
static uint32_t pixel(const uint32_t *r0, const uint32_t *r1, const uint32_t *r2, int xl, int x, int xr, float peak) {
    uint32_t o = r1[x] & 0xFF000000u;
    int sh;

    for (sh = 0; sh < 24; sh += 8) {
#define C(row, col) ((float)(((row)[col] >> sh) & 255) * (1.0f / 255.0f))
        float a = C(r0, xl), b = C(r0, x), c = C(r0, xr);
        float d = C(r1, xl), e = C(r1, x), f = C(r1, xr);
        float g = C(r2, xl), h = C(r2, x), i = C(r2, xr);
#undef C
        float cmn = minf(minf(minf(b, d), minf(e, f)), h), cmx = maxf(maxf(maxf(b, d), maxf(e, f)), h);
        float mn = cmn + minf(cmn, minf(minf(a, c), minf(g, i)));
        float mx = cmx + maxf(cmx, maxf(maxf(a, c), maxf(g, i)));
        float r = minf(mn, 2.0f - mx) / maxf(mx, 1.0f / 512.0f);
        float w = sqrtf(r < 0.0f ? 0.0f : r > 1.0f ? 1.0f : r) * peak;
        float v = (e + w * (b + d + f + h)) / (1.0f + 4.0f * w);
        int q = (int)(v * 255.0f + 0.5f);

        q = q < 0 ? 0 : q > 255 ? 255 : q;
        o |= (uint32_t)q << sh;
    }
    return o;
}

#ifdef HAVE_SSE2
/* 4 lanes of 32-bit values (0..255 or 0..510 / 0..1020) to float */
#define F(v) _mm_cvtepi32_ps(v)

/* four pixels x .. x + 3 (all with both neighbours inside the row) */
SSE2_FN static void four(const uint32_t *r0, const uint32_t *r1, const uint32_t *r2, int x, uint32_t *o, float peak) {
    __m128i a = _mm_loadu_si128((const __m128i *)(r0 + x - 1)), b = _mm_loadu_si128((const __m128i *)(r0 + x));
    __m128i c = _mm_loadu_si128((const __m128i *)(r0 + x + 1)), d = _mm_loadu_si128((const __m128i *)(r1 + x - 1));
    __m128i e = _mm_loadu_si128((const __m128i *)(r1 + x)), f = _mm_loadu_si128((const __m128i *)(r1 + x + 1));
    __m128i g = _mm_loadu_si128((const __m128i *)(r2 + x - 1)), h = _mm_loadu_si128((const __m128i *)(r2 + x));
    __m128i i = _mm_loadu_si128((const __m128i *)(r2 + x + 1));
    __m128i cmn = _mm_min_epu8(_mm_min_epu8(_mm_min_epu8(b, d), _mm_min_epu8(e, f)), h);
    __m128i cmx = _mm_max_epu8(_mm_max_epu8(_mm_max_epu8(b, d), _mm_max_epu8(e, f)), h);
    __m128i fmn = _mm_min_epu8(cmn, _mm_min_epu8(_mm_min_epu8(a, c), _mm_min_epu8(g, i)));
    __m128i fmx = _mm_max_epu8(cmx, _mm_max_epu8(_mm_max_epu8(a, c), _mm_max_epu8(g, i)));
    __m128i z = _mm_setzero_si128();
    __m128 vpeak = _mm_set1_ps(peak), one = _mm_set1_ps(1.0f), four_ = _mm_set1_ps(4.0f);
    __m128 half = _mm_set1_ps(0.5f);
    __m128i res16[2];
    int k;

    /* bytes 0..7 then 8..15 as 16-bit lanes */
    for (k = 0; k < 2; k++) {
        __m128i mn16, mx16, e16, s16, res32[2];
        int m;

#define U16(v) (k == 0 ? _mm_unpacklo_epi8(v, z) : _mm_unpackhi_epi8(v, z))
        mn16 = _mm_add_epi16(U16(cmn), U16(fmn));
        mx16 = _mm_add_epi16(U16(cmx), U16(fmx));
        e16 = U16(e);
        s16 = _mm_add_epi16(_mm_add_epi16(U16(b), U16(d)), _mm_add_epi16(U16(f), U16(h)));
#undef U16
        for (m = 0; m < 2; m++) {
#define U32(v) (m == 0 ? _mm_unpacklo_epi16(v, z) : _mm_unpackhi_epi16(v, z))
            /* in 0..255 units: r = min(mn, 510 - mx) / mx; mx at least 1/2 (the shader's 1/512) */
            __m128 mn = F(U32(mn16)), mx = F(U32(mx16)), ev = F(U32(e16)), s = F(U32(s16));
#undef U32
            __m128 r = _mm_div_ps(_mm_min_ps(mn, _mm_sub_ps(_mm_set1_ps(510.0f), mx)), _mm_max_ps(mx, half));
            __m128 w = _mm_mul_ps(_mm_sqrt_ps(_mm_min_ps(_mm_max_ps(r, _mm_setzero_ps()), one)), vpeak);
            __m128 v = _mm_div_ps(_mm_add_ps(ev, _mm_mul_ps(w, s)), _mm_add_ps(one, _mm_mul_ps(four_, w)));

            res32[m] = _mm_cvttps_epi32(_mm_max_ps(_mm_add_ps(v, half), _mm_setzero_ps()));
        }
        res16[k] = _mm_packs_epi32(res32[0], res32[1]);
    }
    {
        __m128i res = _mm_packus_epi16(res16[0], res16[1]);
        __m128i amask = _mm_set1_epi32((int)0xFF000000u);

        res = _mm_or_si128(_mm_andnot_si128(amask, res), _mm_and_si128(amask, e));
        _mm_storeu_si128((__m128i *)(o + x), res);
    }
}
#undef F
#endif

static void run(int part, int parts, void *arg) {
    const Job *j = arg;
    int y0 = j->h * part / parts, y1 = j->h * (part + 1) / parts;
    int x, y;

    for (y = y0; y < y1; y++) {
        const uint32_t *r0 = j->in + (size_t)(y > 0 ? y - 1 : 0) * j->w;
        const uint32_t *r1 = j->in + (size_t)y * j->w;
        const uint32_t *r2 = j->in + (size_t)(y < j->h - 1 ? y + 1 : y) * j->w;
        uint32_t *o = j->out + (size_t)y * j->w;

        x = 0;
#ifdef HAVE_SSE2
        if (j->w >= 6) {
            o[0] = pixel(r0, r1, r2, 0, 0, 1, j->peak);
            for (x = 1; x + 4 < j->w; x += 4) {
                four(r0, r1, r2, x, o, j->peak);
            }
        }
#endif
        for (; x < j->w; x++) {
            int xl = x > 0 ? x - 1 : 0, xr = x < j->w - 1 ? x + 1 : x;

            o[x] = pixel(r0, r1, r2, xl, x, xr, j->peak);
        }
    }
}

void PsxSharpen_Cpu(const uint32_t *in, uint32_t *out, int w, int h, int strength) {
    Job j = { in, out, w, h, -1.0f / (8.0f + (5.0f - 8.0f) * (strength / 100.0f)) };

    PsxHd_Parallel(run, &j);
}
