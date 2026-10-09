#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backend/psxgpu.h"
#include "host/host.h"
#include "host/ui.h"

/* Screenshots for checks (P1.4): the display area as shown and the whole VRAM (1024x512, 15-bit
 * colour, mask bit ignored), each as an RGB PNG; with HD output on (PG.1) also <tag>_hd.png. No library: the zlib stream uses stored
 * (uncompressed) deflate blocks. */

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

/* pixels: w * h words 0x00RRGGBB. */
static int write_png(const char *path, const uint32_t *pixels, int w, int h) {
    static const uint8_t sig[8] = { 0x89, 'P', 'N', 'G', '\r', '\n', 0x1A, '\n' };
    size_t raw_n = (size_t)h * (1 + (size_t)w * 3);
    size_t blocks = (raw_n + 65534) / 65535;
    size_t z_n = 2 + raw_n + blocks * 5 + 4;
    uint8_t *raw = malloc(raw_n);
    uint8_t *z = malloc(z_n);
    uint8_t ihdr[13];
    uint32_t a = 1, b = 0;
    size_t i, at, zi;
    FILE *f;
    int x, y;

    if (raw == NULL || z == NULL) {
        free(raw);
        free(z);
        return 0;
    }
    at = 0;
    for (y = 0; y < h; y++) {
        raw[at++] = 0; /* filter: none */
        for (x = 0; x < w; x++) {
            uint32_t p = pixels[(size_t)y * w + x];
            raw[at++] = (uint8_t)(p >> 16);
            raw[at++] = (uint8_t)(p >> 8);
            raw[at++] = (uint8_t)p;
        }
    }
    zi = 0;
    z[zi++] = 0x78;
    z[zi++] = 0x01;
    for (i = 0; i < raw_n; i += 65535) {
        size_t n = raw_n - i < 65535 ? raw_n - i : 65535;
        z[zi++] = (uint8_t)(i + n == raw_n);
        z[zi++] = (uint8_t)n;
        z[zi++] = (uint8_t)(n >> 8);
        z[zi++] = (uint8_t)~n;
        z[zi++] = (uint8_t)(~n >> 8);
        memcpy(z + zi, raw + i, n);
        zi += n;
    }
    for (i = 0; i < raw_n; i++) {
        a = (a + raw[i]) % 65521;
        b = (b + a) % 65521;
    }
    be32(z + zi, (b << 16) | a);
    zi += 4;

    f = fopen(path, "wb");
    if (f == NULL) {
        free(raw);
        free(z);
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
    chunk(f, "IDAT", z, (uint32_t)zi);
    chunk(f, "IEND", NULL, 0);
    fclose(f);
    free(raw);
    free(z);
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
    if (write_png(path, pixels, w, h)) {
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
    if (write_png(path, pixels, PSXGPU_VRAM_W, PSXGPU_VRAM_H)) {
        printf("[shot] %s (1024x512)\n", path);
    } else {
        printf("[shot] cannot write %s\n", path);
    }
    /* HD output (PG.1): the display area as the window shows it at --scale N */
    if (PsxGpu_ReadDisplayHd(NULL, &w, &h)) {
        uint32_t *hd = malloc((size_t)w * h * sizeof(uint32_t));
        if (hd != NULL && PsxGpu_ReadDisplayHd(hd, &w, &h)) {
            snprintf(path, sizeof(path), "%s/%s_hd.png", dir, tag);
            if (write_png(path, hd, w, h)) {
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
    return write_png(path, pixels, w, h);
}
