#include "libmcrd.h"
#include "psyq_log.h"

/* libmcrd stubs (P1.1): no card in either slot; async ops finish at once. Save files are
 * P1.9. */

void MemCardInit(int val) { PSYQ_LOG("%d", val); }
void MemCardStart(void) { PSYQ_LOG(""); }

int MemCardExist(int chan) {
    PSYQ_LOG("0x%X", chan);
    return 1; /* command issued */
}

int MemCardAccept(int chan) {
    PSYQ_LOG("0x%X", chan);
    return 1;
}

int MemCardOpen(int chan, char *file, int flag) {
    PSYQ_LOG("0x%X, %p, %d", chan, (void *)file, flag);
    return McErrCardNotExist;
}

void MemCardClose(void) { PSYQ_LOG(""); }

/* Decomp name of MemCardClose (stag1100 card.c). */
void Card_CloseFile(void) {
    PSYQ_LOG("");
}

int MemCardReadFile(int chan, char *file, u_long *adrs, int ofs, int bytes) {
    PSYQ_LOG("0x%X, %p, %p, %d, %d", chan, (void *)file, (void *)adrs, ofs, bytes);
    return 1;
}

int MemCardWriteFile(int chan, char *file, u_long *adrs, int ofs, int bytes) {
    PSYQ_LOG("0x%X, %p, %p, %d, %d", chan, (void *)file, (void *)adrs, ofs, bytes);
    return 1;
}

int MemCardSync(int mode, int *cmds, int *rslt) {
    PSYQ_LOG("%d, %p, %p", mode, (void *)cmds, (void *)rslt);
    if (cmds != 0) {
        *cmds = McFuncExist;
    }
    if (rslt != 0) {
        *rslt = McErrCardNotExist;
    }
    return 1; /* done */
}

int MemCardCreateFile(int chan, char *file, int blocks) {
    PSYQ_LOG("0x%X, %p, %d", chan, (void *)file, blocks);
    return McErrCardNotExist;
}

int MemCardFormat(int chan) {
    PSYQ_LOG("0x%X", chan);
    return McErrCardNotExist;
}
