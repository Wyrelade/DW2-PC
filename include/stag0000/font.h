#ifndef STAG0000_FONT_H
#define STAG0000_FONT_H

/* Functions src/stag0000/font.c defines. */
void Stg00_FontInit(void);
void func_80064E44(void);
void Stg00_FontSetColor(s16 arg0);
void Stg00_FontFree(void);
void Stg00_FontDrawStr(s32 arg0, s32 arg1, u8 *arg2);
void Stg00_FontDrawSheet(void);
void Stg00_FontPrintBuf(s32 arg0, s32 arg1);
void Stg00_FontPrintBufCentered(s32 arg0, s32 arg1);

#endif /* STAG0000_FONT_H */
