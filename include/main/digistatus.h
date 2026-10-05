#ifndef MAIN_DIGISTATUS_H
#define MAIN_DIGISTATUS_H

#include "main/game.h"

/* Functions src/main/digistatus.c defines. */
void Menu_DigiStatusInit(Actor *a0, s16 a1);
void Menu_DigiStatusTask(Actor *a);
void Menu_DigiStatusDraw(Actor *actor);

#endif /* MAIN_DIGISTATUS_H */
