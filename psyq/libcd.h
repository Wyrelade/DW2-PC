#ifndef PSYQ_LIBCD_H
#define PSYQ_LIBCD_H

#include "psyq_types.h"

/* Psy-Q 4.7 libcd (incl. the St* stream functions): the types, the 19 functions and the
 * stream flag the game uses. */

typedef struct {
    u_char minute; /* BCD */
    u_char second; /* BCD */
    u_char sector; /* BCD */
    u_char track;
} CdlLOC;

typedef void (*CdlCB)(u_char status, u_char *result);

/* Command codes the game sends. */
#define CdlNop 0x01
#define CdlSetloc 0x02
#define CdlReadN 0x06
#define CdlPause 0x09
#define CdlSetfilter 0x0D
#define CdlSetmode 0x0E
#define CdlGetlocP 0x11
#define CdlSeekL 0x15
#define CdlReadS 0x1B

/* Interrupt / sync status. */
#define CdlNoIntr 0x00
#define CdlDataReady 0x01
#define CdlComplete 0x02
#define CdlAcknowledge 0x03
#define CdlDataEnd 0x04
#define CdlDiskError 0x05

int CdInit(void);
int CdSetDebug(int level);
int CdPosToInt(CdlLOC *p);
CdlLOC *CdIntToPos(int i, CdlLOC *p);
int CdLastCom(void);
int CdSync(int mode, u_char *result);
CdlCB CdSyncCallback(CdlCB func);
CdlCB CdReadyCallback(CdlCB func);
int CdControl(u_char com, u_char *param, u_char *result);
int CdControlF(u_char com, u_char *param);
int CdControlB(u_char com, u_char *param, u_char *result);
int CdGetSector(void *madr, int size);
int CdRead2(int mode);

void StSetRing(u_long *ring_addr, u_long ring_size);
void StUnSetRing(void);
void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)());
u_long StFreeRing(u_long *base);
u_long StGetNext(u_long **addr, u_long **header);
void StCdInterrupt(void);

/* Set when a stream interrupt was deferred (the game runs StCdInterrupt itself). */
extern u_long StCdIntrFlag;

#endif /* PSYQ_LIBCD_H */
