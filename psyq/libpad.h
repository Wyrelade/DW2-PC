#ifndef PSYQ_LIBPAD_H
#define PSYQ_LIBPAD_H

#include "psyq_types.h"

/* Psy-Q 4.7 libpad: the 3 functions the game calls. */

#define PadStateDiscon 0
#define PadStateFindPad 1
#define PadStateFindCTP1 2
#define PadStateFindCTP2 3
#define PadStateReqInfo 4
#define PadStateExecCmd 5
#define PadStateStable 6

void PadInitDirect(u_char *pad1, u_char *pad2);
void PadStartCom(void);
int PadGetState(int port);

#endif /* PSYQ_LIBPAD_H */
