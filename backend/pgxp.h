#ifndef BACKEND_PGXP_H
#define BACKEND_PGXP_H

#include <stdint.h>

/* Precise vertices for the HD output (PG.2, backend/pgxp.c). */

/* An RTPS result: the integer SXY2 word and the float position of the same point (GTE screen
 * space, before the game's halving), z = view depth. Installed as Gte_PreciseHook. */
void Pgxp_Record(int32_t sxy, double x, double y, double z);
/* The precise position for a packet vertex x, y (drawing offset not applied): 1 when known. */
int Pgxp_Lookup(int x, int y, float *fx, float *fy, float *fz);
/* After each DrawOTag: the projections of the frame just drawn are dropped. */
void Pgxp_EndFrame(void);

#endif /* BACKEND_PGXP_H */
