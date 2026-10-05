#ifndef MAIN_FADE_H
#define MAIN_FADE_H

#include "main/game.h"

/* Functions src/main/fade.c defines. */
void Gfx_FadeInFromBlack(s32 arg0);
void Gfx_FadeOutToBlack(s32 arg0);
void Gfx_FadeInFromWhite(s32 arg0);
void Gfx_FadeOutToWhite(s32 arg0);
void Gfx_FadeClear(void);
void Gfx_FadeSetBlack(void);
void Gfx_DrawFade(void);

#endif /* MAIN_FADE_H */
