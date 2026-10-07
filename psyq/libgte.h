#ifndef PSYQ_LIBGTE_H
#define PSYQ_LIBGTE_H

#include "psyq_types.h"

/* Psy-Q 4.7 libgte: the types and the 14 functions the game calls (Psy-Q long = int). */

typedef struct {
    short m[3][3]; /* 3x3 rotation, 4.12 fixed point */
    int t[3];      /* translation */
} MATRIX;

typedef struct {
    int vx, vy, vz, pad;
} VECTOR;

typedef struct {
    short vx, vy, vz, pad;
} SVECTOR;

typedef struct {
    u_char r, g, b, cd;
} CVECTOR;

int rsin(int a);
int rcos(int a);
void InitGeom(void);
VECTOR *ApplyMatrixLV(MATRIX *m, VECTOR *v0, VECTOR *v1);
void PushMatrix(void);
void PopMatrix(void);
VECTOR *ApplyMatrixSV(MATRIX *m, SVECTOR *v0, VECTOR *v1);
MATRIX *ScaleMatrix(MATRIX *m, VECTOR *v);
void SetRotMatrix(MATRIX *m);
void SetTransMatrix(MATRIX *m);
void SetGeomOffset(int ofx, int ofy);
int RotTransPers(SVECTOR *v0, int *sxy, int *p, int *flag);
MATRIX *RotMatrixYXZ(SVECTOR *r, MATRIX *m);
int ratan2(int y, int x);

#endif /* PSYQ_LIBGTE_H */
