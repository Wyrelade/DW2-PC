#ifndef STAG1000_MOVIE_H
#define STAG1000_MOVIE_H

/* Functions src/stag1000/movie.c defines. */
void Stg10_MovieInit(s32 arg0, s32 *arg1);
void Stg10_StrKickCd(u8 *arg0);
void Stg10_MovieDestroy(Actor *arg0);
void Stg10_MovieUpdate(Actor *a0);

#endif /* STAG1000_MOVIE_H */
