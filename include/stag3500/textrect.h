#ifndef STAG3500_TEXTRECT_H
#define STAG3500_TEXTRECT_H

/* Functions src/stag3500/textrect.c defines. */
void Stg35_TextAlloc(Stg35TextHandle *arg0);
void Stg35_TextFree(Stg35TextHandle *arg0);
void Stg35_TextSetLayout(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg35_TextSetString(Stg35PartsHandle *arg0, s32 arg1);
void Stg35_TextSetColor(Stg35PartsHandle *arg0, s32 arg1);
void Stg35_TextSetSysMsg(Stg35TextHandle *arg0, s32 arg1);
void Stg35_TextSetSkillName(Stg35TextHandle *arg0, s32 arg1);
void Stg35_TextOpen(Stg35TextHandle *arg0);
void Stg35_TextClose(Stg35TextHandle *arg0);
void Stg35_RectAlloc(Stg35SpriteHandle *arg0);
void Stg35_RectFree(Stg35SpriteHandle *arg0);
void Stg35_RectDraw(Stg35SpriteHandle *arg0);
void Stg35_RectSetDrawMode(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3);
void Stg35_RectSetColor(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4);
void Stg35_RectSetWidth(Stg35SpriteHandle *arg0, s32 arg1);
void Stg35_RectSetHeight(Stg35SpriteHandle *arg0, s32 arg1);
void Stg35_RectSetX(Stg35SpriteHandle *arg0, s32 arg1);
void Stg35_RectSetY(Stg35SpriteHandle *arg0, s32 arg1);
void Stg35_RectSetBounds(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
s32 Stg35_ScaleBarLen(s32 arg0, s32 arg1, s32 arg2);

#endif /* STAG3500_TEXTRECT_H */
