#ifndef STAG1000_H
#define STAG1000_H

#include "common.h"

/* main exe */
extern void DMACallback();
extern void ResetCallback(void);
extern u8 D_80050741;

/* this overlay */
extern s32 *D_8006539C;
extern s32 D_80066200;
extern s32 D_80066204;

void func_80064980(s32 arg0);
void func_80064B00(void);

#endif
