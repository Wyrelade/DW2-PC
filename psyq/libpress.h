#ifndef PSYQ_LIBPRESS_H
#define PSYQ_LIBPRESS_H

#include "psyq_types.h"

/* Psy-Q 4.6 libpress (MDEC): the 5 functions the game calls. */

typedef u_short DECDCTTAB[34816];

void DecDCTReset(int mode);
void DecDCTin(u_long *buf, int mode);
void DecDCTout(u_long *buf, int size);
int DecDCToutCallback(void (*func)());
int DecDCTvlc2(u_long *bs, u_long *buf, DECDCTTAB table);

#endif /* PSYQ_LIBPRESS_H */
