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
    u8 _pad20[0x08];
} Stg30Part; /* size 0x28 */

/* Work of task D_80073040 (init func_80063B70) and D_800730D0 (init func_80065584). */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg30WorkWord;

/* Work of task D_80073040 (func_80063C44, func_80063B80, func_8006436C): two
   (file, lba) lists kept sorted by lba, plus a list of files to free. */
typedef struct {
    /* 0x000 */ s32 field_0;
    u8 _pad004[0x04];
    /* 0x008 */ s32 files[60];
    /* 0x0F8 */ s32 lbas[60];
    /* 0x1E8 */ s32 field_1E8[30];
    /* 0x260 */ s32 field_260[30];
    /* 0x2D8 */ s32 count;
    /* 0x2DC */ s32 field_2DC;
    /* 0x2E0 */ s32 field_2E0;
    u8 _pad2E4[0x40];
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
    u8 _pad24[0x04];
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
    u8 _pad04[0x08];
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
    u8 _pad08[0x10];
    /* 0x18 */ s32 field_18[3];
    /* 0x24 */ s32 text[14];
} Stg30Work73718;

/* Work of task D_800737C8 (func_800728A0, func_80072F84). */
typedef struct {
    /* 0x00 */ s32 index;
    u8 _pad04[0x0C];
    /* 0x10 */ s32 field_10;
} Stg30Work737C8;

/* 0x5C-stride entries at the head of D_80073CC0 (index = Stg30Work737C8.index). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x14];
    /* 0x18 */ u8 field_18;
    /* 0x19 */ u8 field_19;
    u8 _pad1A[0x0B];
    /* 0x25 */ u8 field_25;
    u8 _pad26[0x02];
    /* 0x28 */ s32 field_28;
    u8 _pad2C[0x02];
    /* 0x2E */ s16 field_2E;
    /* 0x30 */ s16 field_30;
    /* 0x32 */ s16 field_32;
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ s16 field_38;
    /* 0x3A */ u8 field_3A[3];
    u8 _pad3D[0x1F];
} Stg30Entry5C; /* size 0x5C */

/* 0x12-byte record of D_80073CC0.field_240 (arg2 of func_80068DA4): byte lists
   indexed by the same slot i at 0x02, 0x05, 0x09 and 0x0D. */
typedef struct {
    u8 _pad00[0x02];
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
    u8 _pad0A[0x06];
} Stg30Sub10;

/* D_80073CC0: overlay state block (func_800701FC clears 0x3E0 bytes from here). */
typedef struct {
    /* 0x000 */ Stg30Entry5C entries[6];
    u8 _pad228[0x18];
    /* 0x240 */ Stg30ByteLists field_240[6];
    /* 0x2AC */ Stg30Sub10 field_2AC[7];
    /* 0x31C */ s32 field_31C[6];
    u8 _pad334[0x0C];
    /* 0x340 */ u8 field_340[6];
    /* 0x346 */ u8 field_346[6];
    /* 0x34C */ u8 field_34C[6];
    u8 _pad352[0x04];
    /* 0x356 */ s16 field_356[6];
    /* 0x362 */ s16 field_362[6];
    /* 0x36E */ s16 field_36E[6];
    u8 _pad37A[0x5A];
    /* 0x3D4 */ s32 field_3D4;
} Stg30State; /* size 0x3D8 */

/* arg0 of func_800675CC / func_80067624 / func_8006754C: a pointer at 0x34 to a
   six-actor list at 0x2C. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ s32 field_24;
    u8 _pad28[0x04];
    /* 0x2C */ Actor *actors[6];
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
    u8 _pad04[0x10];
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
    u8 _pad04[0x04];
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x0C];
    /* 0x18 */ s32 texts[3][3];
    u8 _pad3C[0x04];
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
    u8 _pad4C[0x04];
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


/* Struct passed as arg0 of func_8006767C: 12 byte ids at 0x22. */
typedef struct {
    u8 _pad00[0x22];
    /* 0x22 */ u8 ids[12];
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

#endif
