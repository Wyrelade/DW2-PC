#include "libgs.h"
#include "psyq_log.h"

/* libgs stubs (P1.1). GsGetTimInfo is real (TIM header parse, no hardware). The C libgs over
 * the libgte math comes with P1.4 / P1.5. */

MATRIX GsWSMATRIX;
MATRIX GsLIGHTWSMATRIX;

void GsInitGraph(u_short x_res, u_short y_res, u_short intmode, u_short dith, u_short varmmode) {
    PSYQ_LOG("%u, %u, %u, %u, %u", x_res, y_res, intmode, dith, varmmode);
}

void GsSetOffset(int x, int y) {
    PSYQ_LOG("%d, %d", x, y);
}

void GsInitCoordinate2(GsCOORDINATE2 *super, GsCOORDINATE2 *base) {
    PSYQ_LOG("%p, %p", (void *)super, (void *)base);
}

void GsSetLsMatrix(MATRIX *mp) {
    PSYQ_LOG("%p", (void *)mp);
}

void GsInit3D(void) {
    PSYQ_LOG("");
}

void GsSetProjection(int h) {
    PSYQ_LOG("%d", h);
}

int GsSetFlatLight(int id, GsF_LIGHT *lt) {
    PSYQ_LOG("%d, %p", id, (void *)lt);
    return 0;
}

void GsSetLightMode(int mode) {
    PSYQ_LOG("%d", mode);
}

void GsSetAmbient(int r, int g, int b) {
    PSYQ_LOG("%d, %d, %d", r, g, b);
}

/* TIM: word 0 id 0x10, word 1 flags (bits 0-2 pixel mode, bit 3 CLUT present), then the CLUT
 * block (if any) and the pixel block, each: length word, x, y, w, h halfwords, data. */
void GsGetTimInfo(u_long *im, GsIMAGE *tim) {
    u_long *p;

    PSYQ_LOG("%p, %p", (void *)im, (void *)tim);
    tim->pmode = im[0];
    p = im + 1;
    if (tim->pmode & 8) {
        tim->cx = (short)(p[1] & 0xFFFF);
        tim->cy = (short)(p[1] >> 16);
        tim->cw = (u_short)(p[2] & 0xFFFF);
        tim->ch = (u_short)(p[2] >> 16);
        tim->clut = p + 3;
        p += p[0] / 4;
    } else {
        tim->clut = 0;
    }
    tim->px = (short)(p[1] & 0xFFFF);
    tim->py = (short)(p[1] >> 16);
    tim->pw = (u_short)(p[2] & 0xFFFF);
    tim->ph = (u_short)(p[2] >> 16);
    tim->pixel = p + 3;
}

void GsGetLs(GsCOORDINATE2 *coord, MATRIX *m) {
    PSYQ_LOG("%p, %p", (void *)coord, (void *)m);
}

int GsSetRefView2(GsRVIEW2 *pv) {
    PSYQ_LOG("%p", (void *)pv);
    return 0;
}
