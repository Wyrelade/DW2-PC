#ifndef BACKEND_PGXP_H
#define BACKEND_PGXP_H

#include <stdint.h>

/* Precise vertices for the HD output (PG.2, backend/pgxp.c). */

/* An RTPS result: the integer SXY2 word and the float position of the same point (GTE screen
 * space, before the game's halving), z = view depth, clamped = the GTE saturated the integer one.
 * Installed as Gte_PreciseHook. */
void Pgxp_Record(int32_t sxy, double x, double y, double z, int clamped);
/* The precise positions for the n (3 or 4) packet vertices of one polygon (drawing offset not
 * applied): bit k of the result is set when vertex k is known (fx / fy / fz [k] filled). A vertex
 * with several points in this frame gets the one whose depth fits the polygon's other corners. */
int Pgxp_LookupPoly(int n, const int *x, const int *y, float *fx, float *fy, float *fz);
/* After each DrawOTag: the projections of the frame just drawn are dropped. */
void Pgxp_EndFrame(void);

#endif /* BACKEND_PGXP_H */
