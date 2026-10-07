#ifndef PSYQ_LIBSND_H
#define PSYQ_LIBSND_H

#include "psyq_types.h"

/* Psy-Q 4.7 libsnd: the 21 functions the game calls (Psy-Q long = int). */

#define SS_NOTICK 0x1000
#define SS_SERIAL_A 0
#define SS_MIX 0

void SsInit(void);
void SsStart2(void);
void SsSetTickMode(int tick_mode);
void SsSeqCalledTbyT(void);
void SsSetTableSize(char *table, short s_max, short t_max);
void SsSetMVol(short voll, short volr);
void SsSetSerialAttr(char s_num, char attr, char mode);
void SsSetSerialVol(char s_num, short voll, short volr);
short SsSepOpen(u_long *addr, short vab_id, short seq_num);
void SsSepClose(short sep_access_num);
void SsSepPlay(short sep_access_num, short seq_num, char play_mode, short l_count);
void SsSepStop(short sep_access_num, short seq_num);
void SsSepSetVol(short sep_access_num, short seq_num, short voll, short volr);
void SsUtAllKeyOff(short mode);
short SsUtSetReverbType(short type);
void SsUtSetReverbDepth(short ldepth, short rdepth);
void SsUtReverbOn(void);
short SsVabOpenHead(u_char *addr, short vabid);
short SsVabTransBody(u_char *addr, short vabid);
short SsVabTransCompleted(short immediateFlag);
void SsVabClose(short vab_id);

#endif /* PSYQ_LIBSND_H */
