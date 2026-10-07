#include "libsnd.h"
#include "psyq_log.h"

/* libsnd stubs (P1.1, also the title prototype): no audio. Opens hand out ids, VAB uploads
 * complete at once. Sound is P1.8. */

static short next_vab;
static short next_sep;

void SsInit(void) { PSYQ_LOG(""); }
void SsStart2(void) { PSYQ_LOG(""); }
void SsSetTickMode(int tick_mode) { PSYQ_LOG("0x%X", tick_mode); }
void SsSeqCalledTbyT(void) { PSYQ_LOG(""); }
void SsSetTableSize(char *table, short s_max, short t_max) { PSYQ_LOG("%p, %d, %d", (void *)table, s_max, t_max); }
void SsSetMVol(short voll, short volr) { PSYQ_LOG("%d, %d", voll, volr); }
void SsSetSerialAttr(char s_num, char attr, char mode) { PSYQ_LOG("%d, %d, %d", s_num, attr, mode); }
void SsSetSerialVol(char s_num, short voll, short volr) { PSYQ_LOG("%d, %d, %d", s_num, voll, volr); }

short SsSepOpen(u_long *addr, short vab_id, short seq_num) {
    PSYQ_LOG("%p, %d, %d", (void *)addr, vab_id, seq_num);
    return next_sep++ & 0xF;
}

void SsSepClose(short sep_access_num) { PSYQ_LOG("%d", sep_access_num); }

void SsSepPlay(short sep_access_num, short seq_num, char play_mode, short l_count) {
    PSYQ_LOG("%d, %d, %d, %d", sep_access_num, seq_num, play_mode, l_count);
}

void SsSepStop(short sep_access_num, short seq_num) { PSYQ_LOG("%d, %d", sep_access_num, seq_num); }

void SsSepSetVol(short sep_access_num, short seq_num, short voll, short volr) {
    PSYQ_LOG("%d, %d, %d, %d", sep_access_num, seq_num, voll, volr);
}

void SsUtAllKeyOff(short mode) { PSYQ_LOG("%d", mode); }

short SsUtSetReverbType(short type) {
    PSYQ_LOG("%d", type);
    return type;
}

void SsUtSetReverbDepth(short ldepth, short rdepth) { PSYQ_LOG("%d, %d", ldepth, rdepth); }
void SsUtReverbOn(void) { PSYQ_LOG(""); }

short SsVabOpenHead(u_char *addr, short vabid) {
    PSYQ_LOG("%p, %d", (void *)addr, vabid);
    return vabid >= 0 ? vabid : (next_vab++ & 0xF);
}

short SsVabTransBody(u_char *addr, short vabid) {
    PSYQ_LOG("%p, %d", (void *)addr, vabid);
    return vabid;
}

short SsVabTransCompleted(short immediateFlag) {
    PSYQ_LOG("%d", immediateFlag);
    return 1;
}

void SsVabClose(short vab_id) { PSYQ_LOG("%d", vab_id); }
