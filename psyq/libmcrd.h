#ifndef PSYQ_LIBMCRD_H
#define PSYQ_LIBMCRD_H

#include "psyq_types.h"

/* Psy-Q 4.7 libmcrd: the 11 functions the game calls (Psy-Q long = int). The decomp calls
 * MemCardClose by the name Card_CloseFile; the shim provides both. */

#define McFuncExist 1
#define McFuncAccept 2
#define McFuncReadFile 3
#define McFuncWriteFile 4
#define McFuncReadData 5
#define McFuncWriteData 6

#define McErrNone 0
#define McErrCardNotExist 1
#define McErrCardInvalid 2
#define McErrNewCard 3
#define McErrNotFormat 4
#define McErrFileNotExist 5
#define McErrAlreadyExist 6
#define McErrBlockFull 7

void MemCardInit(int val);
void MemCardStart(void);
int MemCardExist(int chan);
int MemCardAccept(int chan);
int MemCardOpen(int chan, char *file, int flag);
void MemCardClose(void);
void Card_CloseFile(void);
int MemCardReadFile(int chan, char *file, u_long *adrs, int ofs, int bytes);
int MemCardWriteFile(int chan, char *file, u_long *adrs, int ofs, int bytes);
int MemCardSync(int mode, int *cmds, int *rslt);
int MemCardCreateFile(int chan, char *file, int blocks);
int MemCardFormat(int chan);

#endif /* PSYQ_LIBMCRD_H */
