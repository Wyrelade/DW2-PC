#include <stdint.h>
#include <string.h>

#include "backend/pgxp.h"
#include "backend/psxgpu.h"

/* Precise vertices (PG.2, PGXP-style). The C GTE hands every RTPS result over as a float
 * position next to its integer SX / SY (Pgxp_Record through Gte_PreciseHook). The game copies the
 * integers into GPU packets by value, after halving them when the draw area is not 640 / 480 wide
 * / tall (model.c, floor.c), so the entries are keyed by the integer vertex as the packet will
 * hold it, and the float is halved the same way. The integer is the float rounded down, so the
 * float is stored 0.5 lower: the precise picture then sits where the integer one does on
 * average (2D parts and integer vertices line up with it). The GPU looks vertices up by their
 * packet value. A key that two different floats claim in one frame is ambiguous (no precise
 * value). Entries live from the projection to the end of the next DrawOTag. */

#define PG_BITS 15
#define PG_SIZE (1 << PG_BITS)
#define PG_PROBE 16

typedef struct {
    uint32_t key, gen;
    float x, y, z;
    int ambiguous;
} Entry;

static Entry tab[PG_SIZE];
static uint32_t gen = 1;

static uint32_t slot(uint32_t key) {
    return (key * 2654435761u) >> (32 - PG_BITS);
}

static uint32_t make_key(int x, int y) {
    return ((uint32_t)(uint16_t)y << 16) | (uint16_t)x;
}

void Pgxp_Record(int32_t sxy, double x, double y, double z) {
    int sx = (int16_t)(sxy & 0xFFFF);
    int sy = (int16_t)((uint32_t)sxy >> 16);
    int w, h, shx, shy, i;
    uint32_t key, k;
    float fx, fy;

    /* the float must describe the same point as the hardware result */
    if (!(x > sx - 2.0 && x < sx + 2.0 && y > sy - 2.0 && y < sy + 2.0)) {
        return;
    }
    PsxGpu_DrawAreaSize(&w, &h);
    shx = w != 640;
    shy = h != 480;
    fx = (float)((shx ? x / 2.0 : x) - 0.5);
    fy = (float)((shy ? y / 2.0 : y) - 0.5);
    key = make_key(sx >> shx, sy >> shy);
    k = slot(key);
    for (i = 0; i < PG_PROBE; i++) {
        Entry *e = &tab[(k + i) & (PG_SIZE - 1)];
        if (e->gen != gen) {
            e->gen = gen;
            e->key = key;
            e->x = fx;
            e->y = fy;
            e->z = (float)z;
            e->ambiguous = 0;
            return;
        }
        if (e->key == key) {
            float dx = e->x - fx, dy = e->y - fy;
            if (dx * dx + dy * dy > 1.0f / 4096.0f) {
                e->ambiguous = 1;
            }
            return;
        }
    }
}

int Pgxp_Lookup(int x, int y, float *fx, float *fy, float *fz) {
    uint32_t key = make_key(x, y);
    uint32_t k = slot(key);
    int i;

    for (i = 0; i < PG_PROBE; i++) {
        const Entry *e = &tab[(k + i) & (PG_SIZE - 1)];
        if (e->gen != gen) {
            return 0;
        }
        if (e->key == key) {
            if (e->ambiguous) {
                return 0;
            }
            *fx = e->x;
            *fy = e->y;
            *fz = e->z;
            return 1;
        }
    }
    return 0;
}

void Pgxp_EndFrame(void) {
    if (++gen == 0) {
        memset(tab, 0, sizeof(tab));
        gen = 1;
    }
}
