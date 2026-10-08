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
 * packet value. Entries live from the projection to the end of the next DrawOTag.
 * PG.10: a key often has several different points in one frame (a city or dungeon frame has
 * hundreds: distinct vertices less than one packet pixel apart, at the same or another depth).
 * Each key keeps up to PG_CAND of them, and a polygon picks one per vertex so that its depths
 * agree (Pgxp_LookupPoly). Before, such keys gave no precise value, and the polygons that used
 * them mixed precise and integer corners with affine texturing, so their texture moved by a
 * different amount than their neighbours' while the camera moved. */

#define PG_BITS 15
#define PG_SIZE (1 << PG_BITS)
#define PG_PROBE 16
#define PG_CAND 8

typedef struct {
    float x, y, z;
} Cand;

typedef struct {
    uint32_t key, gen;
    int n;
    Cand c[PG_CAND];
} Entry;

static Entry tab[PG_SIZE];
static uint32_t gen = 1;

static uint32_t slot(uint32_t key) {
    return (key * 2654435761u) >> (32 - PG_BITS);
}

static uint32_t make_key(int x, int y) {
    return ((uint32_t)(uint16_t)y << 16) | (uint16_t)x;
}

void Pgxp_Record(int32_t sxy, double x, double y, double z, int clamped) {
    int sx = (int16_t)(sxy & 0xFFFF);
    int sy = (int16_t)((uint32_t)sxy >> 16);
    int w, h, shx, shy, i, j;
    uint32_t key, k;
    float fx, fy;

    /* the float must describe the same point as the hardware result; when the GTE saturated
     * the integer one, the float is the true position of that packet vertex (PG.10) */
    if (!clamped && !(x > sx - 2.0 && x < sx + 2.0 && y > sy - 2.0 && y < sy + 2.0)) {
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
            e->n = 1;
            e->c[0].x = fx;
            e->c[0].y = fy;
            e->c[0].z = (float)z;
            return;
        }
        if (e->key == key) {
            /* the same point again (shared vertex projected twice) */
            for (j = 0; j < e->n; j++) {
                float dx = e->c[j].x - fx, dy = e->c[j].y - fy;
                if (dx * dx + dy * dy <= 1.0f / 4096.0f) {
                    return;
                }
            }
            if (e->n < PG_CAND) {
                e->c[e->n].x = fx;
                e->c[e->n].y = fy;
                e->c[e->n].z = (float)z;
                e->n++;
            } else {
                e->n = PG_CAND + 1; /* too many points: no precise value */
            }
            return;
        }
    }
}

static const Entry *find(int x, int y) {
    uint32_t key = make_key(x, y);
    uint32_t k = slot(key);
    int i;

    for (i = 0; i < PG_PROBE; i++) {
        const Entry *e = &tab[(k + i) & (PG_SIZE - 1)];
        if (e->gen != gen) {
            return NULL;
        }
        if (e->key == key) {
            return e->n <= PG_CAND ? e : NULL;
        }
    }
    return NULL;
}

/* relative depth distance */
static float zdist(float a, float b) {
    float d = a > b ? a - b : b - a;
    return d / (a < b ? a : b);
}

/* the candidate of e whose depth is closest to z */
static int nearest(const Entry *e, float z) {
    int j, best = 0;
    float d, bestd = zdist(e->c[0].z, z);

    for (j = 1; j < e->n; j++) {
        d = zdist(e->c[j].z, z);
        if (d < bestd) {
            bestd = d;
            best = j;
        }
    }
    return best;
}

int Pgxp_LookupPoly(int n, const int *x, const int *y, float *fx, float *fy, float *fz) {
    const Entry *e[4];
    int pick[4];
    int i, j, mask = 0, nref = 0, multi = -1;
    float zref = 0;

    for (i = 0; i < n; i++) {
        e[i] = find(x[i], y[i]);
        pick[i] = 0;
        if (e[i] != NULL) {
            mask |= 1 << i;
            if (e[i]->n == 1) {
                zref += e[i]->c[0].z;
                nref++;
            } else if (multi < 0) {
                multi = i;
            }
        }
    }
    if (multi >= 0 && nref > 0) {
        /* each vertex with several points takes the one nearest the others' mean depth */
        zref /= (float)nref;
        for (i = 0; i < n; i++) {
            if (e[i] != NULL && e[i]->n > 1) {
                pick[i] = nearest(e[i], zref);
            }
        }
    } else if (multi >= 0) {
        /* no single-point corner: try each point of the first such vertex as the depth, the
         * others nearest to it, and keep the set with the smallest depth spread */
        float bestcost = -1;
        int best[4] = { 0, 0, 0, 0 };

        for (j = 0; j < e[multi]->n; j++) {
            float z = e[multi]->c[j].z, zmin = z, zmax = z, cost;

            pick[multi] = j;
            for (i = 0; i < n; i++) {
                if (e[i] != NULL && i != multi) {
                    float zi;

                    pick[i] = nearest(e[i], z);
                    zi = e[i]->c[pick[i]].z;
                    zmin = zi < zmin ? zi : zmin;
                    zmax = zi > zmax ? zi : zmax;
                }
            }
            cost = zdist(zmin, zmax);
            if (bestcost < 0 || cost < bestcost) {
                bestcost = cost;
                for (i = 0; i < n; i++) {
                    best[i] = pick[i];
                }
            }
        }
        for (i = 0; i < n; i++) {
            pick[i] = best[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (e[i] != NULL) {
            fx[i] = e[i]->c[pick[i]].x;
            fy[i] = e[i]->c[pick[i]].y;
            fz[i] = e[i]->c[pick[i]].z;
        }
    }
    return mask;
}

void Pgxp_EndFrame(void) {
    if (++gen == 0) {
        memset(tab, 0, sizeof(tab));
        gen = 1;
    }
}
