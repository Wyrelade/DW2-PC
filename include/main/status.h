#ifndef MAIN_STATUS_H
#define MAIN_STATUS_H

#include "main/game.h"

/* Functions src/main/status.c defines. */
void Menu_StatusInit(Actor *arg0, s16 arg1);
void Menu_StatusTask(Actor *a0);
void Menu_StatusDraw(Actor *actor);

#endif /* MAIN_STATUS_H */
