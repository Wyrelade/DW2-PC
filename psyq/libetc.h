#ifndef PSYQ_LIBETC_H
#define PSYQ_LIBETC_H

/* Psy-Q 4.7 libetc: the 3 functions the game calls. */

int VSync(int mode);
int ResetCallback(void);
int VSyncCallback(void (*f)(void));

#endif /* PSYQ_LIBETC_H */
