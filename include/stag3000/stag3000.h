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
    u8 _pad0C[0x20];
    /* 0x2C */ ActorWork *work;
} Stg30TaskHead;

/* Work of task D_800732E8 (func_8006F820): a word and a palette byte. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ u8 field_4;
    u8 _pad05[0x03];
} Stg30Work732E8; /* size 0x8 */

/* 0x28-byte parts record as func_8006F820 writes it (GfxPart shape plus 0x0E/0x10). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x08];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x01];
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 visible;
    /* 0x10 */ s32 field_10;
    u8 _pad14[0x08];
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
    u8 _pad00[0x04];
    /* 0x04 */ s32 text[4];
} Stg30Work73078;

/* Work of task D_800732B8 (func_8006F530, func_8006F640, func_8006F664, func_8006E850). */
typedef struct {
    u8 _pad00[0x28];
    /* 0x28 */ s32 field_28;
    u8 _pad2C[0x04];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 anim;
} Stg30Work732B8;

/* Work of tasks D_80073328 (init func_8006F8CC) and D_800733F0 (init func_800702A8). */
typedef struct {
    /* 0x00 */ Vec3 pos;
} Stg30WorkVec3;

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
    u8 _pad08[0x1C];
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
    u8 _pad1A[0x14];
    /* 0x2E */ s16 field_2E;
    u8 _pad30[0x02];
    /* 0x32 */ s16 field_32;
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ s16 field_38;
    u8 _pad3A[0x22];
} Stg30Entry5C; /* size 0x5C */

/* 16-byte record of the D_80073CC0.field_2AC array. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x0C];
} Stg30Sub10;

/* D_80073CC0: overlay state block (func_800701FC clears 0x3E0 bytes from here). */
typedef struct {
    /* 0x000 */ Stg30Entry5C entries[6];
    u8 _pad228[0x84];
    /* 0x2AC */ Stg30Sub10 field_2AC[7];
    /* 0x31C */ s32 field_31C[6];
    u8 _pad334[0xA0];
    /* 0x3D4 */ s32 field_3D4;
} Stg30State; /* size 0x3D8 */

/* arg0 of func_800675CC / func_80067624 / func_8006754C: a pointer at 0x34 to a
   six-actor list at 0x2C. */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ Actor *actors[6];
} Stg30ActorList;

typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ Stg30ActorList *list;
} Stg30ListOwner;

/* Work of task D_800737A0 (init func_80071D70, func_80072080). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x70];
    /* 0x74 */ s16 field_74[2][12];
    u8 _padA4[0x14];
    /* 0xB8 */ s32 field_B8[2];
    u8 _padC0[0x0C];
} Stg30Work737A0; /* size 0xCC */

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

/* arg2 of func_80068DA4: byte lists at 0x02 and 0x09. */
typedef struct {
    u8 _pad00[0x02];
    /* 0x02 */ u8 field_2[7];
    /* 0x09 */ u8 field_9[7];
} Stg30ByteLists;

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
extern s32 CdControlF(s32, s32);
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

/* overlay */
extern void func_8006F640(Actor *a0, s32 a1);
extern void func_8006F664(Actor *a0);
extern void func_8006BBD8(s32);
extern void func_8006CA3C(s32);

#endif
