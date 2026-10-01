#ifndef STAG3000_H
#define STAG3000_H

#include "common.h"
#include "main/156C.h"

/* STAG3000 (Ovl_FileIds id 4, gameMode 0x5xx). */

/* Actor viewed with its (main-header padded) word at 0x04: func_8006F674 writes it. */
typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x04];
    /* 0x10 */ s32 stateLevel0;
    /* 0x14 */ s32 stateLevel1;
    /* 0x18 */ s32 stateLevel2;
    u8 _pad1C[0x08];
    /* 0x24 */ s32 field_24;  /* word view of Actor.frameCount */
    /* 0x28 */ s32 elapsed;
    /* 0x2C */ ActorWork *work;
} Stg30TaskHead;

/* Work of task D_800732E8 (func_8006F820): a word and a palette byte. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Stg30Work732E8; /* size 0x8 */

/* 0x28-byte parts record as func_8006F820 writes it (GfxPart shape plus 0x0E/0x10). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    u8 _pad08[0x04];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x01];
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 visible;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x04];
    /* 0x1C */ s32 groupMask;
    u8 _pad20[0x04];
    /* 0x24 */ s16 field_24;
    u8 _pad26[0x02];
} Stg30Part; /* size 0x28 */

/* Work of task D_80073040 (init func_80063B70) and D_800730D0 (init func_80065584). */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg30WorkWord;

/* Work of task D_80073040 (func_80063C44, func_80063B80, func_8006436C): two
   (file, lba) lists kept sorted by lba, plus a list of files to free. */
typedef struct {
    /* 0x000 */ s16 *field_0;  /* s16 command script (func_80063C44) */
    /* 0x004 */ s32 field_4;
    /* 0x008 */ s32 files[60];
    /* 0x0F8 */ s32 lbas[60];
    /* 0x1E8 */ s32 field_1E8[30];
    /* 0x260 */ s32 field_260[30];
    /* 0x2D8 */ s32 count;
    /* 0x2DC */ s32 field_2DC;
    /* 0x2E0 */ s32 field_2E0;
    u8 _pad2E4[0x04];
    /* 0x2E8 */ s32 field_2E8;
    /* 0x2EC */ s32 field_2EC[6];
    /* 0x304 */ s32 field_304[6];
    /* 0x31C */ s32 field_31C;
    /* 0x320 */ s32 field_320;
} Stg30Work73040; /* size 0x324 */

/* Stack block passed to GsSetRefView2. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 *field_1C;
} Stg30RefView;

/* Work of task D_8007343C (camera, func_80070C68). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ Coord1F668 field_1C;
    /* 0x6C */ s32 field_6C;
    /* 0x70 */ s32 field_70;
    /* 0x74 */ s32 field_74;
    u8 _pad78[0x04];
    /* 0x7C */ s16 field_7C;
    /* 0x7E */ s16 field_7E;
    /* 0x80 */ s16 field_80;
    u8 _pad82[0x02];
} Stg30Work7343C; /* size 0x84 */

/* Work of task D_80073078 (destroy func_80064FBC). */
typedef struct {
    /* 0x00 */ s16 scale;
    u8 _pad02[0x02];
    /* 0x04 */ s32 text[4];
} Stg30Work73078; /* size 0x14 */

/* Work of task D_800732B8 (func_8006F530, func_8006F640, func_8006F664, func_8006E850). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ CVECTOR color;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 anim;
    /* 0x38 */ s32 field_38;
} Stg30Work732B8; /* size 0x3C */

/* Work of task D_80073358 (func_8006FC78, func_8006FFD0). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ u8 field_4;
    u8 _pad05[0x03];
    /* 0x08 */ u8 field_8;
    u8 _pad09[0x03];
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg30Work73358; /* size 0x14 */

/* Stg30Work73358 with the words at 0x04 / 0x08 as func_8006FC78 writes them. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg30Work73358W; /* size 0x14 */
extern s32 D_80074094;

/* Work of task D_800733F0 (CD streaming, func_800702C8), as read after the
   func_800702A8 Vec3 init: file id, channel byte, 1-based track index, lba range. */
typedef struct {
    /* 0x00 */ s32 file;
    /* 0x04 */ u8 channel;
    u8 _pad05[0x03];
    /* 0x08 */ s32 track;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg30Work733F0; /* size 0x14 */

/* Work of tasks D_80073328 (init func_8006F8CC) and D_800733F0 (init func_800702A8). */
typedef struct {
    /* 0x00 */ Vec3 pos;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg30WorkVec3; /* size 0x14 */

/* Init arg of task D_800734F8: a pointer whose field_8 is copied to Actor.field_8. */
typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ s32 field_8;
} Stg30Ref;

/* Work of task D_800734F8 (func_80070D68, func_8007100C). */
typedef struct {
    /* 0x00 */ Stg30Ref *ref;
    /* 0x04 */ s16 field_4;
    u8 _pad06[0x02];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 text[2];
} Stg30Work734F8;

/* Two-word init arg of task D_80073718. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Stg30Pair;

/* Work of task D_80073718 (func_80071470, func_80071BDC). */
typedef struct {
    /* 0x00 */ Stg30Pair pair;
    /* 0x08 */ u8 buf0[8];
    /* 0x10 */ u8 buf1[8];
    /* 0x18 */ s32 field_18[3];
    /* 0x24 */ s32 text[14];
} Stg30Work73718;

/* Work of task D_800737C8 (func_800728A0, func_80072F84). */
typedef struct {
    /* 0x00 */ s32 index;
    /* 0x04 */ s32 text[2];
    /* 0x0C */ Actor *field_C;
    /* 0x10 */ s32 field_10;
} Stg30Work737C8;

/* 0x5C-stride entries at the head of D_80073CC0 (index = Stg30Work737C8.index). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ u8 field_18;
    /* 0x19 */ u8 field_19;
    u8 _pad1A[0x0B];
    /* 0x25 */ u8 field_25;
    u8 _pad26[0x01];
    /* 0x27 */ u8 field_27;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s16 field_2C;
    /* 0x2E */ s16 field_2E;
    /* 0x30 */ s16 field_30;
    /* 0x32 */ s16 field_32;
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ s16 field_38;
    /* 0x3A */ u8 field_3A[12];
    u8 _pad46[0x16];
} Stg30Entry5C; /* size 0x5C */

/* 0x12-byte record of D_80073CC0.field_240 (arg2 of func_80068DA4): byte lists
   indexed by the same slot i at 0x02, 0x05, 0x09 and 0x0D. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ u8 field_2[3];
    /* 0x05 */ u8 field_5[4];
    /* 0x09 */ u8 field_9[4];
    /* 0x0D */ u8 field_D[4];
    u8 _pad11[0x01];
} Stg30ByteLists; /* size 0x12 */

/* 16-byte record of the D_80073CC0.field_2AC array. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;
    u8 _pad0A[0x02];
    /* 0x0C */ s16 field_C;  /* hp delta of the last hit */
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
} Stg30Sub10;

/* D_80073CC0: overlay state block (func_800701FC clears 0x3E0 bytes from here). */
typedef struct {
    /* 0x000 */ Stg30Entry5C entries[6];
    u8 _pad228[0x18];
    /* 0x240 */ Stg30ByteLists field_240[6];
    /* 0x2AC */ Stg30Sub10 field_2AC[7];
    /* 0x31C */ s32 field_31C[6];
    /* 0x334 */ u8 field_334[6];
    u8 _pad33A[0x06];
    /* 0x340 */ u8 field_340[6];
    /* 0x346 */ u8 field_346[6];
    /* 0x34C */ u8 field_34C[3];
    /* 0x34F */ u8 field_34F[6];  /* per-slot flag bytes (4 = no status recovery) */
    u8 _pad355[0x01];
    /* 0x356 */ s16 field_356[6];
    /* 0x362 */ s16 field_362[6];
    /* 0x36E */ s16 field_36E[6];
    /* 0x37A */ s16 field_37A[6];
    /* 0x386 */ s16 field_386[6];
    /* 0x392 */ s16 field_392[6];
    /* 0x39E */ s16 field_39E[6];
    u8 _pad3AA[0x02];
    /* 0x3AC */ s32 field_3AC;
    /* 0x3B0 */ s16 field_3B0;
    /* 0x3B2 */ s16 field_3B2;
    /* 0x3B4 */ s16 field_3B4;
    u8 _pad3B6[0x02];
    /* 0x3B8 */ s32 field_3B8[6];
    /* 0x3D0 */ s32 field_3D0;
    /* 0x3D4 */ s32 field_3D4;
    /* 0x3D8 */ s32 field_3D8;
    /* 0x3DC */ s32 field_3DC;
} Stg30State; /* size 0x3E0 */

/* arg0 of func_800675CC / func_80067624 / func_8006754C: a pointer at 0x34 to a
   six-actor list at 0x2C. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x08];
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x0C];
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ Actor *actors[6];
    u8 _pad44[0x04];
    /* 0x48 */ s32 field_48;
} Stg30ActorList;

/* Same object as an Actor (state words at 0x18/0x1C). */
typedef struct {
    u8 _pad00[0x18];
    /* 0x18 */ s32 stateLevel2;
    /* 0x1C */ s32 stateLevel3;
    u8 _pad20[0x14];
    /* 0x34 */ Stg30ActorList *list;
} Stg30ListOwner;

/* Work of task D_800737A0 (init func_80071D70, func_80072080). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4[4];
    /* 0x14 */ s32 texts[20];
    /* 0x64 */ s32 text[3];
    /* 0x70 */ s32 field_70;
    /* 0x74 */ s16 field_74[2][12];
    /* 0xA4 */ s32 field_A4;
    /* 0xA8 */ s32 field_A8[2];
    /* 0xB0 */ s32 field_B0[2];
    /* 0xB8 */ s32 field_B8[2];
    /* 0xC0 */ s32 field_C0;
    /* 0xC4 */ s32 field_C4;
    /* 0xC8 */ s32 field_C8;
} Stg30Work737A0; /* size 0xCC */

/* Work of task D_800730D0 (init func_80065584; func_80065100 fills three id lists). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;  /* first of 14 text words cleared by func_80065594 */
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C[3];
    /* 0x18 */ s32 texts[3][3];
    /* 0x3C */ s32 field_3C;
    /* 0x40 */ s32 field_40[3];
    /* 0x4C */ s32 field_4C[3];
    /* 0x58 */ u8 field_58[3][0x30];
    /* 0xE8 */ s32 field_E8[3];
    /* 0xF4 */ s32 field_F4;
} Stg30Work730D0; /* size 0xF8 */

/* Work of task D_80073138 (update func_80066698 -> func_80066484). */
typedef struct {
    /* 0x00 */ s32 texts[18]; /* [5] is the description text, [6 + row * 3 + col] the grid */
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s16 field_4C;
    u8 _pad4E[0x02];
    /* 0x50 */ s32 field_50;
} Stg30Work73138; /* size 0x54 */

/* 0x1B-byte records of D_80073820 (func_80066484). */
typedef struct {
    /* 0x00 */ u8 field_0[0x0D];
    /* 0x0D */ u8 field_D[0x0E];
} Stg30Rec1B;

/* D_8005E620 viewed through the u16 id list at 0x66 (func_80065100). */
typedef struct {
    u8 _pad00[0x66];
    /* 0x66 */ u16 field_66[0x30];
} Stg30GameIds;

/* 16-byte records of D_80073F6C (indexed by a D_80073A20 slot; func_80069DE8). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    u8 _pad08[0x08];
} Stg30Rec73F6C; /* size 0x10 */

/* Init arg of task D_800737A0. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4[12];
} Stg30Init737A0;

/* Two s16 passed by value to func_800652C8 / func_800663F8 (Text_Open x/y). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg30XY;


/* Struct passed as arg0 of func_8006767C: 12 byte ids at 0x22 (a roster entry:
   func_800676F4 also reads digiId, level, the 24 bytes at 0x2E and the byte at 0x46). */
typedef struct {
    u8 _pad00[0x01];
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x0B];
    /* 0x0D */ u8 level;
    u8 _pad0E[0x0C];
    /* 0x1A */ s16 field_1A;
    u8 _pad1C[0x06];
    /* 0x22 */ u8 ids[12];
    /* 0x2E */ u8 field_2E[0x18];
    /* 0x46 */ u8 field_46;
} Stg30IdSet;

/* Main-exe global read at 0x103D by func_8006A118. */
typedef struct {
    u8 _pad0000[0x103D];
    /* 0x103D */ u8 field_103D;
    u8 _pad103E[0x02];
    /* 0x1040 */ s16 field_1040;
} Stg30Glob5D5A0;

/* D_80073CC0 viewed as a 0x18-byte head followed by six DigiRosterEntry (the same
   bytes Stg30Entry5C reads at 0x18..: field_18 = state, field_19 = digiId, ...). */
typedef struct {
    u8 _pad000[0x18];
    /* 0x018 */ DigiRosterEntry digis[6];
} Stg30StateDigis;

/* D_80073A50: saved copy of the D_80073CC0 roster (func_8006E690 / func_8006E770). */
typedef struct {
    /* 0x000 */ DigiRosterEntry digis[6];
    /* 0x228 */ s32 field_228[6];
    /* 0x240 */ u8 field_240[6];
    /* 0x246 */ u8 field_246[6];
    /* 0x24C */ s16 field_24C[6];
    /* 0x258 */ s16 field_258[6];
    /* 0x264 */ s16 field_264[6];
} Stg30Save73A50; /* size 0x270 */

/* Seven target words func_80070588 eases a Stg30Work7343C camera toward. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg30CamGoal;

/* Init arg of task 7 as func_8006EB24 builds it on the stack. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg30FxArgs;

/* Work of task D_80073170 (update func_80066DB0, draw func_800672B0). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Stg30Work73170; /* size 0x20 */

/* Actor.u38 transform viewed with the vertical speed words. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x0C];
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
} Stg30Xform;

/* ActorModel viewed with the three tint bytes at 0x38..0x3A (func_8006EF50). */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
    u8 _pad3B[0x01];
    /* 0x3C */ s32 otIndex;
    u8 _pad40[0x14];
    /* 0x54 */ s32 animId;
    u8 _pad58[0x08];
    /* 0x60 */ s32 animDone;
} Stg30ModelTint;

extern Elem12 D_80073294;
extern Elem12 D_800732A0;
extern Elem12 D_800732AC;
extern void Task_NextState4(Actor *arg0);
extern void Actor_StopAxisMotion(Actor *arg0, s32 arg1);
extern void Actor_SetAxisMotion(Actor *arg0, s32 arg1, Elem12 *arg2);
extern s32 func_80020D54(Actor *a0, s32 i);
extern s32 func_80020E00(Actor *a0, s32 i);
extern s32 Anim_HasModelAnim(Actor *a0, s32 n);
extern void func_8006E850(Actor *a0, s32 anim);
extern void func_8006EC5C(Actor *a0);

/* TextOpenArgs with x/y as one Stg30XY (copied as a unit from a table). */
typedef struct {
    /* 0x00 */ s32 bigFont;
    /* 0x04 */ s32 color;
    /* 0x08 */ Stg30XY pos;
    /* 0x0C */ s32 charAdvance;
    /* 0x10 */ s32 lineAdvance;
    /* 0x14 */ s32 text;
    /* 0x18 */ s32 charDelay;
    /* 0x1C */ s32 strArg0;
    /* 0x20 */ s32 strArg1;
    u8 _pad24[0x8];
} Stg30TextArgs;

/* 8-byte text layout records of D_80073690 (func_8007191C). */
typedef struct {
    /* 0x00 */ u8 slot;
    /* 0x01 */ u8 src;
    /* 0x02 */ u8 color;
    /* 0x03 */ u8 bigFont;
    /* 0x04 */ Stg30XY pos;
} Stg30TextRec;

extern Stg30TextRec D_80073690[];
extern s32 D_8005F704;
extern s32 Digi_GetExpToNextLevel(s32, s32, s32);
extern u8 *func_80071488(u8 *out, s32 n);
extern void func_80071538(DigiRosterEntry *);

/* D_80073CC0 roster (Stg30StateDigis.digis) as a scalar reloc at 0x18, with the
   stat halfwords read signed. */
typedef struct {
    u8 _pad00[0x01];
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x0B];
    /* 0x0D */ u8 level;
    u8 _pad0E[0x06];
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    /* 0x1C */ s16 attack;
    /* 0x1E */ s16 defense;
    /* 0x20 */ s16 speed;
    u8 _pad22[0x3A];
} Stg30DigiS; /* size 0x5C */

/* D_80073CC0 viewed with its roster as Stg30DigiS (signed stat reads). */
typedef struct {
    u8 _pad000[0x18];
    /* 0x018 */ Stg30DigiS digis[6];
} Stg30StateS;

/* D_80073CD8 viewed as the battle block from 0x18 of D_80073CC0: the roster
   then the status words (D_80073CC0.field_31C) at 0x304. */
typedef struct {
    /* 0x000 */ Stg30DigiS digis[6];
    u8 _pad228[0xDC];
    /* 0x304 */ s32 status[6];
} Stg30CombatCD8;

/* Roster entry viewed as the byte table at 0x21 indexed by Stg30ByteLists.field_9. */
typedef struct {
    u8 _pad00[0x16];
    /* 0x16 */ s16 hp;
    u8 _pad18[0x9];
    /* 0x21 */ u8 b21[0x3B];
} Stg30DigiB21; /* size 0x5C */

/* D_80073CD8 battle block: roster, then the byte lists and Sub10 records. */
typedef struct {
    /* 0x000 */ Stg30DigiB21 digis[6];
    /* 0x228 */ Stg30ByteLists lists[6];
    /* 0x294 */ Stg30Sub10 sub[7];
} Stg30SlotBlk;

extern Stg30DigiS D_80073CD8[];
extern s32 D_80073498[];
extern s32 D_800734B0[];
extern s32 D_800734C8[];
extern Stg30XY D_800734E0[];
extern void func_80071044(Stg30Part *p, s32 unit, s32 num, s32 den);

extern s32 D_80073108[];
extern Stg30XY D_80073118[];
extern s32 D_80073128[];

extern s32 D_80073150[];
extern s32 D_80073168;
extern s32 D_8007316C;
extern s32 func_8001F0E4(s32 id);
extern u8 func_8001F020(s32 id);
/* D_80073CC0 roster names: Stg30StateDigis.digis[i].name as a scalar reloc (0x64 = 0x18 + 0x4C). */
typedef struct {
    /* 0x00 */ u8 name[14];
    u8 _pad0E[0x4E];
} Stg30Name5C; /* size 0x5C */
extern Stg30Name5C D_80073D24[];
extern s32 D_80073454[];
extern Stg30XY D_8007346C[];
extern u8 D_80073484[];
extern Halves D_8007348C[];
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);

extern Stg30Save73A50 D_80073A50;
extern s32 D_800737E0;
extern u8 D_80073070[];
extern s32 D_80073700[];
extern Stg30XY D_80073090[];
extern s16 D_800737E8;
extern s16 D_800737F0[];
extern s16 D_800737F8[];
extern Stg30XY D_800633EC;
extern Stg30XY D_800730E8[];
extern s16 D_80073800;
extern s16 D_80073808[];
extern s16 D_80073810[];
extern Stg30Rec1B D_80073820[];
extern Stg30XY D_800633F4;
extern s32 D_80073340[];
extern s32 D_800733C0[];
extern s32 D_800733D8[];
extern s32 D_80073300[];
extern s32 D_80073310[];
extern s32 D_8007331C[];
extern Stg30Rec73F6C D_80073F6C[];
extern s32 D_80072FC8[];
extern Halves D_80073730[];
extern s16 D_80073890[];
extern u16 D_8005F72A;  /* D_8005F6F0[0].pressed as a scalar reloc */
extern Stg30Glob5D5A0 D_8005D5A0;
extern s32 D_80073A20[12];
extern Stg30State D_80073CC0;
extern s16 D_80073408[];  /* camera goal x per party slot (func_800706BC) */
extern s16 D_80073414[];  /* camera goal tables indexed by digimon height step */
extern s16 D_80073428[];
extern s32 D_800740A0;    /* random camera variant (0..3) */
extern s32 D_80072FF0[];
extern s32 D_80073008;
extern s32 D_8007300C[];
extern s32 D_800732D0[];
extern s32 D_80074098;
extern DigiRosterEntry D_8005F398;  /* D_8005E620.elems[35] as a scalar reloc */
extern s32 D_8005F794;
extern SysState D_8005F770;
extern u8 D_8005E5DD;  /* D_8005D5A0.field_103D as a scalar reloc */
extern GameState D_8005E620;
extern s32 D_80043704[];

/* main exe */
extern void Task_DefaultDestroy(Actor *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 CdControlF(s32, u8 *);
extern void Anim_SetModelAnim(Actor *, s32);
extern s32 func_8001E8D0(s32 id);
extern s32 func_8001F0C0(s32 id);
extern void Snd_PlayById(s32, s32);
extern void Gfx_DrawParts(EntA0 *);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern TaskEntry *Task_FindFirst(s32, s32, s32);
extern void Task_SetState01(Actor *, u32, u32);
extern void Task_SetState1(Actor *, u32);
extern void Task_NextState0(Actor *);
extern void Digi_InitFromTable(s32, s32, DigiRosterEntry *);
extern s32 func_8001EF64(s32 id);
extern s32 func_8001F094(s32 id);
extern s32 func_8001EE80(s32 id);
extern void Cd_FreeFile(s32);
extern EntA0 *Cd_GetFileEntry(u32);
extern s32 Item_GetDescText(s32);
extern s32 Item_GetNameText(s32);
extern s32 func_8001EDD4(s32);
extern s32 func_8001ED84(s32);
extern void Text_Open(void *, TextOpenArgs *);
extern void Mem_Zero(void *, s32);
extern s32 Flag_Test(s32);
extern void Actor_InitTransform(Actor *, s32 *, s32);
extern void Gfx_ResetModelBones(Actor *);
extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg30RefView *);
extern void Gpu_InitDoubleBuffer(s32, s32, s32, s32);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Text_Close(s32 *);
extern void Text_OpenById(void *, s32, s32, Halves);
extern s32 Digi_GetModelFile(s32 id);
extern void Anim_StepModelAnim(Actor *);
extern void Gfx_DrawWireModel(Actor *, s32, CVECTOR *);
extern void Task_SetState0(Actor *, u32);
extern void Gfx_SetPartsScale(GfxPartScaleView *, s32, s32);
extern void Task_Create(u32, s32 *, s32);
extern void Task_NextState1(Actor *);
extern void Task_NextState2(Actor *);
extern void Task_NextState3(Actor *);
extern void Gfx_FadeOutToBlack(s32);
extern void func_8001EEA4(s32 id, s32 n, s16 *a, s16 *b);
extern s32 func_8001E79C(s32 id);  /* s16 in the main exe; used unextended here */
extern s32 func_8001E7C0(s32 id);
extern s32 func_8001EE34(s32 id);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void func_8001E7E4(s32 id, Row6 *out);
extern s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);
extern s32 func_8001E0C0(s32 id);
extern void Text_OpenPacked(void *, s32, u32, Halves);
extern s32 func_8001EF88(s32 id);  /* u16 in the main exe; used unmasked here */
extern s32 func_8001D980(s32 id);
extern s32 Cd_GetFileLba(s32);
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(s32, u8 *, u8 *);
extern u8 *CdIntToPos(s32, u8 *);
extern s32 CdSync(s32, u8 *);
extern s32 CdLastCom(void);  /* u8 in the main exe; compared unmasked here */
extern s32 CdPosToInt(u8 *);
extern s32 func_8001EE5C(s32 id);
extern s32 func_8001F044(s32 id);
extern s32 Rand_Next(void);

/* overlay */
extern void func_8006F640(Actor *a0, s32 a1);
extern void func_8006F664(Actor *a0);
extern void func_8006BBD8(s32);
extern void func_8006CA3C(s32);
extern s32 func_80070530(s32 a, s32 b);
extern void func_80070D14(u8 state);
extern s32 func_80068E34(s32, s32);
extern s32 func_800692A4(s32, s32, s32);
extern s32 func_8006E2BC(s32 id);
extern s32 func_8006E674(s32 i);
extern void func_800652C8(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
extern void func_800663F8(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
extern void func_8006754C(Stg30ListOwner *a0);

/* part 36 salvage */
extern s32 func_8001EF3C(s32 id);
extern void func_8006E530(void);
extern void func_8006E55C(s32 idx, s32 v);
extern void func_8006E5B4(s32 i);
extern s32 func_8006E5F8(s32 v);
extern s32 func_8006E634(void);
extern s32 D_800731B8[];
extern u16 D_800731C8[];
extern s32 D_800731D0[];
extern u16 D_800731FC[];
extern s32 func_8001EE10(s32 id);
extern u16 D_80073510[6][3][4];
extern u16 D_800735A0[5][3][4];
extern u16 D_80073618[4][3][4];
extern s32 func_8001D958(s32 id);
extern s32 func_8001D9CC(s32 id, s32 k);
extern s32 func_8001D934(s32 id);
extern s16 D_80073E02;  /* D_80073CC0.entries[3].field_2E as a scalar reloc */
extern s16 D_80073E5E;  /* D_80073CC0.entries[4].field_2E */
extern s16 D_80073EBA;  /* D_80073CC0.entries[5].field_2E */
extern PadState D_8005F6F0[];
extern Halves D_800633F8;
extern Halves D_800730F8[];
extern s32 D_80073CD4;  /* D_80073CC0.entries[0].field_14 as a scalar reloc */
extern void func_80066484(Actor *a0);
extern void func_80065354(Actor *a0);
extern s32 D_8005F6F4;  /* D_8005F6F0[0].left as a scalar reloc */
extern s32 D_80073CC8;  /* D_80073CC0.entries[0].field_8 as a scalar reloc */
extern s32 func_8006E31C(s32 team, s32 flag, s32 mode);
extern s32 func_8006E3D0(s32 team, s32 cur, s32 flag, s32 mode);
extern s32 func_8006E47C(s32 team, s32 cur, s32 flag, s32 mode);
extern s32 func_80065540(s32 c);
extern Halves D_800633F0;
extern Halves D_8007309C[];
extern s32 D_800730A8[];
extern s32 D_800730B8[];
extern Stg30XY D_800730C4[];
extern void func_80071DC4(Actor *a0);
extern void func_80071F9C(Actor *a0);
extern void func_80072080(Actor *a0, s32 row);
extern s32 func_8006D2EC(s32 idx, s32 id, s32 lvl);
extern s32 func_8001F068(s32 id);
extern s32 func_8001F10C(s32 id);
extern s32 func_8001F130(s32 id);
extern s32 func_8001F158(s32 id);
extern s32 func_800699F8(s32 a, s32 b);
extern s32 func_8006A030(s32 a, s32 b);
extern s32 func_8006A118(void);
extern void func_8006A968(s16 *max, s16 *b, s16 *c);
extern void func_8006AA18(s16 *max, s16 *b, s16 *c);
extern s32 func_8006A140(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5);
extern s32 D_80073210[];
extern s16 D_80073254[];
extern u16 D_8005E65E;  /* D_8005E620 halfword at 0x3E as a scalar reloc (Z-cannon level) */

/* D_8005E620 viewed with the item-menu enable words/bytes func_80065594 reads. */
typedef struct {
    u8 _pad00[0x3C];
    /* 0x3C */ u16 field_3C;
    /* 0x3E */ u16 field_3E;
    /* 0x40 */ u16 field_40;
    u8 _pad42[0x18];
    /* 0x5A */ u8 field_5A;
    /* 0x5B */ u8 field_5B;
    /* 0x5C */ u8 field_5C;
} Stg30GameFlags;


extern u8 D_8005E634[];
extern Halves D_800633E8;

/* D_8005E620 viewed with the words func_8007292C reads (0x30 map id, 0x4A, 0x61). */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ u16 field_30;
    u8 _pad32[0x18];
    /* 0x4A */ u16 field_4A;
    u8 _pad4C[0x15];
    /* 0x61 */ u8 field_61;
    u8 _pad62[0x82];
    /* 0xE4 */ DigiRosterEntry elems[0x24];
} Stg30GameRoster;

extern Halves D_800737B8[];
extern u8 D_800737C0[];
extern u16 D_8005E650;  /* D_8005E620 halfword at 0x30 as a scalar reloc (map id) */
extern Blk5071C *D_8005071C;
extern u8 *Digi_GetDefaultName(s32);
extern void Digi_SortRoster(void);
extern void Flag_Set(s32, s32);
extern TaskEntry *Task_FindNext(void);
extern void func_800728D8(Actor *a0, s32 a1);
extern void Task_SetState2(Actor *, u32);
extern s32 D_80073CC4;  /* D_80073CC0.entries[0].field_4 as a scalar reloc */
extern void func_800643E0(s32 sel, s32 from, s32 to);
extern void func_80064480(void);
extern s32 D_8007409C;
extern s16 D_80073188[][3];
extern s16 D_8005E5E0;  /* D_8005D5A0.field_1040 as a scalar reloc */
extern s32 D_8005F78C;  /* D_8005F770.nextGameMode as a scalar reloc */
extern s32 D_8005F790;  /* D_8005F770.prevGameMode as a scalar reloc */
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
extern void Cd_QueueFile(s32);
extern s32 Cd_GetFileState(s32 arg0);
extern void func_80011644(void);
extern s32 func_8006767C(Stg30IdSet *a0, s16 *a1, u8 id);
extern s32 func_800676C4(s32 a0, u8 a1);
extern void func_80063B80(Actor *a0, s32 file, s32 lba);
extern s32 Item_GetBagCapacity(void);
extern void Item_SortList(void);
extern s32 func_8006D4D8(s32 target, s32 tech, s16 *p3, s16 *p4);

/* Work of the battle script runner (func_8006CB8C): program counter into D_80073890. */
typedef struct {
    /* 0x00 */ s16 *pc;
} Stg30WorkPc;

/* Child-task slots at Actor.u34 of the script runner (Task_Create completion words). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ Actor *field_10;
    /* 0x14 */ Actor *field_14;
} Stg30Slots;

extern void func_80067530(Actor *a0, s32 a1, s32 a2);
extern s32 *func_8001EFF0(s32 id);
extern void Task_SetState4(Actor *, u32);

/* Work of the battle main task D_800731A0 (update func_80067F2C). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg30Work731A0; /* size 0xC */

extern void func_800701FC(void);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern s32 Snd_AnySlotLoading(void);
extern void Cd_FreeUnlockedFiles(void);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Gfx_InitLights(void);
extern void Sys_SetFrameRate30(void);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void func_8001DDA8(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o);
extern void func_8001DB68(void *a0, Out1DB68 *out);
extern void func_80067EC4(void);
extern void Task_SetState3(Actor *arg0, u32 arg1);
extern void func_80069594(void);
extern void func_800696E8(void);
extern s32 func_80069A44(s32 idx);
extern void func_8006E690(void);
extern void func_80069DE8(void);
extern s32 func_8006CB28(s32 idx);
extern void func_8006E770(void);
extern void Task_Destroy(s32 *arg0);
extern void func_80067DB4(Stg30ListOwner *a0);
extern void func_80067624(Stg30ListOwner *a0);
extern void func_800675CC(Stg30ListOwner *a0);
extern void func_8006DB90(void);
extern void func_800676F4(Actor *a0);
extern s32 func_8001F180(s32 id);
extern s32 func_8006AAA8(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5);
extern s32 func_8006B950(s32 idx, s16 *tgt, s32 n, s32 id);
extern s16 D_80074070;
extern s16 D_80074074;
extern s32 D_80073278;

#endif
