#ifndef PSYQ_LIBGS_H
#define PSYQ_LIBGS_H

#include "psyq_types.h"
#include "libgte.h"
#include "libgpu.h"

/* Psy-Q 4.7 libgs: the types, the 12 functions and the 2 data objects the game uses. */

typedef struct {
    VECTOR scale;
    SVECTOR rotate;
    VECTOR trans;
} GsCOORD2PARAM;

typedef struct _GsCOORDINATE2 {
    u_long flg;
    MATRIX coord;
    MATRIX workm;
    GsCOORD2PARAM *param;
    struct _GsCOORDINATE2 *super;
    struct _GsCOORDINATE2 *sub;
} GsCOORDINATE2;

typedef struct {
    int vpx, vpy, vpz;
    int vrx, vry, vrz;
    int rz;
    GsCOORDINATE2 *super;
} GsRVIEW2;

typedef struct {
    int vx, vy, vz;
    u_char r, g, b;
} GsF_LIGHT;

typedef struct {
    u_long pmode;
    short px, py;
    u_short pw, ph;
    u_long *pixel;
    short cx, cy;
    u_short cw, ch;
    u_long *clut;
} GsIMAGE;

#define GsOFSGTE 0
#define GsOFSGPU 4
#define GsINTER 1
#define GsNONINTER 0

void GsInitGraph(u_short x_res, u_short y_res, u_short intmode, u_short dith, u_short varmmode);
void GsSetOffset(int x, int y);
void GsInitCoordinate2(GsCOORDINATE2 *super, GsCOORDINATE2 *base);
void GsSetLsMatrix(MATRIX *mp);
void GsInit3D(void);
void GsSetProjection(int h);
int GsSetFlatLight(int id, GsF_LIGHT *lt);
void GsSetLightMode(int mode);
void GsSetAmbient(int r, int g, int b);
void GsGetTimInfo(u_long *im, GsIMAGE *tim);
void GsGetLs(GsCOORDINATE2 *coord, MATRIX *m);
int GsSetRefView2(GsRVIEW2 *pv);

/* World to screen (GsSetRefView2) and world light matrix (GsSetFlatLight). The game reads
 * both through its own views (decomp names D_800619A8 for the light matrix). */
extern MATRIX GsWSMATRIX;
extern MATRIX GsLIGHTWSMATRIX;

#endif /* PSYQ_LIBGS_H */
