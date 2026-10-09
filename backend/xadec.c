#include <string.h>

#include "backend/xadec.h"

/* XA-ADPCM decode and the 37.8 -> 44.1 kHz zigzag resampler, after psx-spx "CDROM XA Audio ADPCM
 * Compression". A sector body is the 8-byte subheader (file, channel, submode, coding info twice)
 * and 18 sound groups of 128 bytes: 16 header bytes (unit u's shift / filter at byte 4 + u) and 28
 * data words (unit u's sample j at byte 16 + j * 4 + u / 2, low nibble for even u; 8-bit: byte
 * 16 + j * 4 + u). 4-bit groups hold 8 units of 28 samples, 8-bit groups 4 units; stereo units
 * alternate left / right. 18.9 kHz samples go into the resampler twice. */

#define FIFO_FRAMES 16384 /* 44.1 kHz stereo frames, about 370 ms */

static const int pos_table[4] = { 0, 60, 115, 98 };
static const int neg_table[4] = { 0, 0, -52, -55 };

/* The controller's zigzag interpolation: 7 output samples per 6 input samples, 29 taps each,
 * newest sample first (psx-spx Table1..Table7, index 1..29). */
static const int16_t zigzag[7][29] = {
    { 0, 0, 0, 0, 0, -0x0002, 0x000A, -0x0022, 0x0041, -0x0054, 0x0034, 0x0009, -0x010A, 0x0400, -0x0A78,
      0x234C, 0x6794, -0x1780, 0x0BCD, -0x0623, 0x0350, -0x016D, 0x006B, 0x000A, -0x0010, 0x0011, -0x0008,
      0x0003, -0x0001 },
    { 0, 0, 0, -0x0002, 0, 0x0003, -0x0013, 0x003C, -0x004B, 0x00A2, -0x00E3, 0x0132, -0x0043, -0x0267,
      0x0C9D, 0x74BB, -0x11B4, 0x09B8, -0x05BF, 0x0372, -0x01A8, 0x00A6, -0x001B, 0x0005, 0x0006, -0x0008,
      0x0003, -0x0001, 0 },
    { 0, 0, -0x0001, 0x0003, -0x0002, -0x0005, 0x001F, -0x004A, 0x00B3, -0x0192, 0x02B1, -0x039E, 0x04F8,
      -0x05A6, 0x7939, -0x05A6, 0x04F8, -0x039E, 0x02B1, -0x0192, 0x00B3, -0x004A, 0x001F, -0x0005,
      -0x0002, 0x0003, -0x0001, 0, 0 },
    { 0, -0x0001, 0x0003, -0x0008, 0x0006, 0x0005, -0x001B, 0x00A6, -0x01A8, 0x0372, -0x05BF, 0x09B8,
      -0x11B4, 0x74BB, 0x0C9D, -0x0267, -0x0043, 0x0132, -0x00E3, 0x00A2, -0x004B, 0x003C, -0x0013,
      0x0003, 0, -0x0002, 0, 0, 0 },
    { -0x0001, 0x0003, -0x0008, 0x0011, -0x0010, 0x000A, 0x006B, -0x016D, 0x0350, -0x0623, 0x0BCD,
      -0x1780, 0x6794, 0x234C, -0x0A78, 0x0400, -0x010A, 0x0009, 0x0034, -0x0054, 0x0041, -0x0022,
      0x000A, -0x0001, 0, 0x0001, 0, 0, 0 },
    { 0x0002, -0x0008, 0x0010, -0x0023, 0x002B, 0x001A, -0x00EB, 0x027B, -0x0548, 0x0AFA, -0x16FA, 0x53E0,
      0x3C07, -0x1249, 0x080E, -0x0347, 0x015B, -0x0044, -0x0017, 0x0046, -0x0023, 0x0011, -0x0005, 0,
      0, 0, 0, 0, 0 },
    { -0x0005, 0x0011, -0x0023, 0x0046, -0x0017, -0x0044, 0x015B, -0x0347, 0x080E, -0x1249, 0x3C07,
      0x53E0, -0x16FA, 0x0AFA, -0x0548, 0x027B, -0x00EB, 0x001A, 0x002B, -0x0023, 0x0010, -0x0008,
      0x0002, 0, 0, 0, 0, 0, 0 },
};

static int hist[2][2];     /* old, older per channel (0 = left / mono, 1 = right) */
static int16_t ring[2][32]; /* resampler input, per channel */
static unsigned ring_pos;
static int sixstep;
static int16_t fifo[FIFO_FRAMES][2];
static int fifo_head, fifo_count;
static int16_t raw[18 * 224][2]; /* last sector before the resampler */
static int raw_frames;
static int counting;  /* a stream runs and has sent its first sector */
static int underruns;

void XaDec_Reset(void) {
    memset(hist, 0, sizeof(hist));
    memset(ring, 0, sizeof(ring));
    ring_pos = 0;
    sixstep = 6;
    fifo_head = 0;
    fifo_count = 0;
    raw_frames = 0;
    counting = 0;
    underruns = 0;
}

static int clamp16(int x) {
    return x > 0x7FFF ? 0x7FFF : x < -0x8000 ? -0x8000 : x;
}

static void fifo_put(int l, int r) {
    int i;

    if (fifo_count == FIFO_FRAMES) { /* consumer stalled: drop the oldest frame */
        fifo_head = (fifo_head + 1) % FIFO_FRAMES;
        fifo_count--;
    }
    i = (fifo_head + fifo_count) % FIFO_FRAMES;
    fifo[i][0] = (int16_t)l;
    fifo[i][1] = (int16_t)r;
    fifo_count++;
}

static int interpolate(int ch, const int16_t *table) {
    int sum = 0, i;

    for (i = 0; i < 29; i++) {
        sum += (ring[ch][(ring_pos - i - 1) & 31] * table[i]) >> 15;
    }
    return clamp16(sum);
}

/* One 37.8 kHz input frame into the resampler; every sixth adds seven 44.1 kHz frames. */
static void resample(int l, int r) {
    int k;

    ring[0][ring_pos & 31] = (int16_t)l;
    ring[1][ring_pos & 31] = (int16_t)r;
    ring_pos++;
    if (--sixstep == 0) {
        sixstep = 6;
        for (k = 0; k < 7; k++) {
            fifo_put(interpolate(0, zigzag[k]), interpolate(1, zigzag[k]));
        }
    }
}

/* 28 samples of sound unit u in a group: 4-bit (nibble) or 8-bit. */
static void decode_unit(const uint8_t *grp, int u, int bits8, int ch, int16_t *out) {
    int hdr = grp[4 + u];
    int shift = hdr & 0xF, filter = (hdr >> 4) & 3;
    int f0 = pos_table[filter], f1 = neg_table[filter];
    int old = hist[ch][0], older = hist[ch][1];
    int j;

    if (shift > 12) {
        shift = 9;
    }
    for (j = 0; j < 28; j++) {
        int t, s;
        if (bits8) {
            t = (int16_t)(grp[16 + j * 4 + u] << 8) >> shift;
        } else {
            t = (int16_t)(((grp[16 + j * 4 + u / 2] >> ((u & 1) * 4)) & 0xF) << 12) >> shift;
        }
        s = clamp16(t + ((old * f0 + older * f1 + 32) >> 6));
        out[j] = (int16_t)s;
        older = old;
        old = s;
    }
    hist[ch][0] = old;
    hist[ch][1] = older;
}

void XaDec_Sector(const uint8_t *body) {
    int ci = body[3];
    int stereo = (ci & 3) == 1, half = (ci >> 2) & 1, bits8 = ((ci >> 4) & 3) == 1;
    int units = bits8 ? 4 : 8;
    int g, u, j, k;
    int16_t s[2][28];

    raw_frames = 0;
    counting = 1;
    for (g = 0; g < 18; g++) {
        const uint8_t *grp = body + 8 + g * 128;
        for (u = 0; u < units; u += stereo ? 2 : 1) {
            decode_unit(grp, u, bits8, 0, s[0]);
            if (stereo) {
                decode_unit(grp, u + 1, bits8, 1, s[1]);
            }
            for (j = 0; j < 28; j++) {
                int l = s[0][j], r = stereo ? s[1][j] : l;
                raw[raw_frames][0] = (int16_t)l;
                raw[raw_frames][1] = (int16_t)r;
                raw_frames++;
                for (k = 0; k <= half; k++) {
                    resample(l, r);
                }
            }
        }
    }
}

void XaDec_Pop(int16_t *l, int16_t *r) {
    if (fifo_count == 0) {
        *l = *r = 0;
        underruns += counting;
        return;
    }
    *l = fifo[fifo_head][0];
    *r = fifo[fifo_head][1];
    fifo_head = (fifo_head + 1) % FIFO_FRAMES;
    fifo_count--;
}

int XaDec_Queued(void) {
    return fifo_count;
}

int XaDec_Underruns(void) {
    return underruns;
}

void XaDec_Stop(void) {
    counting = 0;
}

const int16_t *XaDec_LastRaw(int *frames) {
    *frames = raw_frames;
    return &raw[0][0];
}
