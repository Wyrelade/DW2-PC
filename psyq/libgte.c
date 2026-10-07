#include <math.h>

#include "libgte.h"
#include "psyq_log.h"

/* libgte stubs (P1.1): no GTE state yet, matrix functions leave their output alone and return
 * the Psy-Q result pointer. rsin / rcos / ratan2 are float approximations of the 4.12 table
 * functions. P1.5 brings the C fixed-point GTE with the Psy-Q tables. */

int rsin(int a) {
    PSYQ_LOG("%d", a);
    return (int)lround(sin(a * (M_PI / 2048.0)) * 4096.0);
}

int rcos(int a) {
    PSYQ_LOG("%d", a);
    return (int)lround(cos(a * (M_PI / 2048.0)) * 4096.0);
}

int ratan2(int y, int x) {
    PSYQ_LOG("%d, %d", y, x);
    return (int)lround(atan2((double)y, (double)x) * (2048.0 / M_PI));
}

void InitGeom(void) {
    PSYQ_LOG("");
}

VECTOR *ApplyMatrixLV(MATRIX *m, VECTOR *v0, VECTOR *v1) {
    PSYQ_LOG("%p, %p, %p", (void *)m, (void *)v0, (void *)v1);
    return v1;
}

void PushMatrix(void) {
    PSYQ_LOG("");
}

void PopMatrix(void) {
    PSYQ_LOG("");
}

VECTOR *ApplyMatrixSV(MATRIX *m, SVECTOR *v0, VECTOR *v1) {
    PSYQ_LOG("%p, %p, %p", (void *)m, (void *)v0, (void *)v1);
    return v1;
}

MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v) {
    PSYQ_LOG("%p, %p", (void *)m, (void *)v);
    return m;
}

void SetRotMatrix(MATRIX *m) {
    PSYQ_LOG("%p", (void *)m);
}

void SetTransMatrix(MATRIX *m) {
    PSYQ_LOG("%p", (void *)m);
}

void SetGeomOffset(int ofx, int ofy) {
    PSYQ_LOG("%d, %d", ofx, ofy);
}

int RotTransPers(SVECTOR *v0, int *sxy, int *p, int *flag) {
    PSYQ_LOG("%p, %p, %p, %p", (void *)v0, (void *)sxy, (void *)p, (void *)flag);
    return 0;
}

MATRIX *RotMatrixYXZ(SVECTOR *r, MATRIX *m) {
    PSYQ_LOG("%p, %p", (void *)r, (void *)m);
    return m;
}
