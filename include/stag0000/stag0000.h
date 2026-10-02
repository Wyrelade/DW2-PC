#ifndef STAG0000_H
#define STAG0000_H

#include "common.h"
#include "main/156C.h"

/* STAG0000 (Ovl_FileIds id 0, gameMode 0x1xx). */

/* Work area pointed to by D_80069360. */
typedef struct {
    /* 0x000 */ u16 clut[0x60];
    /* 0x0C0 */ u16 buf[0x400];
    /* 0x8C0 */ u16 field_8C0;      /* small RECT x (LoadImage) */
    /* 0x8C2 */ u16 field_8C2;      /* small RECT y */
    /* 0x8C4 */ s16 field_8C4;      /* small RECT w */
    /* 0x8C6 */ s16 field_8C6;      /* small RECT h */
    /* 0x8C8 */ RECT rectBig;
    /* 0x8D0 */ s32 *field_8D0;
    /* 0x8D4 */ s16 field_8D4;
} Stg00Work;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg00Vec3;

typedef struct {
    /* 0x00 */ s32 field_0[7];
} Stg00Blk1C;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Stg00Work73FC;

extern SysState D_8005F770;
extern u8 **D_8006925C[];
extern u8 *D_8006935C;
extern Stg00Work *D_80069360;
extern u8 D_80068AD0[];       /* 1bpp font bits unpacked by func_80064E78 */

extern void Task_DefaultDestroy(Actor *arg0);
extern TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2);
extern void Gfx_ReleaseTexSlot(s32 *arg0);
extern void Mem_Free(ActorWork *arg0);
extern s32 CdControlF(s32, s32);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);

void func_80065114(void);
void func_80065150(s32 arg0, s32 arg1, u8 *arg2);



/* Actor.work of the objects moved by func_80068958 family (0x1C now a GsCOORDINATE2). */
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
    /* 0x84 */ s32 field_84;
} Stg00ObjWork;

/* SPRT packet with the tag's length byte addressable. */
typedef struct {
    u8 addr[3];
    u8 len;
} Stg00Tag;

typedef struct {
    /* 0x00 */ Stg00Tag tag;
    /* 0x04 */ Col1A9C8 c;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ u8 u0;
    /* 0x0D */ u8 v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ s16 w;
    /* 0x12 */ s16 h;
} Stg00Sprt;

/* Actor.work of the parts-drawing tasks (func_80066618 / func_80066D50). */
typedef struct {
    u8 _pad00[0x0C];
    /* 0x0C */ s32 field_C;
} Stg00PartsWork;

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
} Stg00RefView;

/* Init arg of the model task (func_80066DB0). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Vec3 field_4;
    /* 0x10 */ s32 field_10;
} Stg00ModelArg;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Vec3 field_4;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x08];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ CVECTOR field_28;
} Stg00ModelWork;

/* Actor.work whose first word selects the display mode. */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg00ModeWork;

/* File-relative pointer tables fixed up by func_80064084. */
typedef struct {
    /* 0x00 */ u32 field_0;
    /* 0x04 */ u32 field_4;
    /* 0x08 */ u32 field_8;
    /* 0x0C */ u32 field_C;
    /* 0x10 */ u32 field_10;
} Stg00RelocEnt;

typedef struct {
    /* 0x00 */ u32 field_0;
    u8 _pad04[0x04];
    /* 0x08 */ Stg00RelocEnt *field_8[8];
} Stg00RelocHdr;

/* Actor.work of the select task (func_800649D8 and its states). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ u8 field_8;
    u8 _pad09[0x01];
    /* 0x0A */ s16 field_A;
    /* 0x0C */ u32 *field_C;
    /* 0x10 */ u32 field_10;
} Stg00SelWork;

typedef struct {
    /* 0x00 */ s16 field_0;
    u8 _pad02[0x12];
} Stg00SelEnt; /* size 0x14 */

/* View of *D_8005071C (main Blk5071C) at bytes 3/4. */
typedef struct {
    u8 _pad0[0x03];
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
} Stg00Blk5071C;

/* Task_Create arg blocks. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg00TaskArgs;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg00TaskArgs5;

typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Stg00Pos;

/* Sorted list work (func_8006620C / func_80066130). */
typedef struct {
    u8 _pad000[0x10];
    /* 0x010 */ s32 field_10[200];
    /* 0x330 */ s32 field_330[200];
    /* 0x650 */ s32 field_650;
    /* 0x654 */ s32 field_654;
    /* 0x658 */ s32 field_658;
} Stg00ListWork;

typedef struct {
    u8 _pad00[0x10];
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg00NameWork;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Stg00ScrollWork;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    u8 _pad14[0x18];
    /* 0x2C */ s32 field_2C;
} Stg00SpawnWork;

extern Halves D_8005074C;
extern s32 D_80043704[];
extern u16 D_8005F72C;
extern s32 D_8005F700;
extern PadState D_8005F6F0[];
extern s32 D_8005F78C;
extern Stg00Blk5071C *D_8005071C;
extern s32 D_80068E84[];
extern s32 D_80068EC4[];
extern Stg00Pos D_80068E18[][9];
extern u8 D_80069364[2][10];

extern void Gfx_HidePartsByMask(EntA0 *, s32);
extern void Gfx_DrawParts(EntA0 *);
extern void Actor_InitTransform(Actor *, s32 *, s32);
extern void Gfx_ResetModelBones(Actor *);
extern void Task_NextState0(Actor *);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Task_Destroy(s32 *arg0);
extern void Task_Create(u32, s32 *, s32);
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern s32 Digi_GetModelFile(s32 id);
extern void Anim_StepModelAnim(Actor *);
extern void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg00RefView *);
extern void Flag_Set(s32, s32);
extern s32 func_8001E8F4(s32 idx);
extern s32 func_8001E79C(s32 id);
extern s32 func_8001E7C0(s32 id);
extern s32 func_8001E938(void);
extern void func_8001EEA4(s32 id, s32 n, s16 *a, s16 *b);
extern s32 Rand_Next();
extern void Text_Close(s32 *);
extern void Text_Open(void *, TextOpenArgs *);
extern u8 *Digi_GetDefaultName(s32);
extern s32 func_8001ED84(s32);
extern u8 D_80068CE8[];

/* D_80068DB8 record: parts file id at 0 (func_80065E24). */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s32 field_4;
} Ent68DB8; /* size 8 */
extern Ent68DB8 D_80068DB8[];

/* Actor.work of func_80065E24 (also func_8006571C: the same dialog-cursor state). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C[14]; /* text handles */
    /* 0x54 */ s32 field_54;
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
    /* 0x64 */ s32 field_64;
} Work65E24;

/* Work65E24's leading 4 words (field_0..field_C) viewed as a slot array,
 * indexed by field_8 (func_8006571C). */
typedef union {
    /* 0x00 */ s32 words[4];
    /* 0x00 */ u8 bytes[16];
} Work65E24Slots;

extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern void func_800655FC(Actor *arg0);
extern void Task_SetState2(Actor *arg0, u32 arg1);
extern void Task_SetState4(Actor *arg0, u32 arg1);
extern u8 D_80068DD8[][4];
extern u8 D_80068DF4[][4];

void func_80064064(u32 *arg0, u32 arg1);
void func_800642BC(Actor *arg0, Stg00SelWork *arg1);
void func_80064E44(void);
void func_80064E78(void);
void func_80064E4C(s16 arg0);
u8 *func_80068084(s32 arg0, s32 arg1);

/* ---- functions ---- */


/* Actor.work of the fade task (func_80067A70). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x08];
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg00FadeWork;

/* Actor.work of the counter task (func_80068208) and parts task (func_8006835C). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u8 field_8[6];
} Stg00CountWork;

/* Texture slot behind Stg00Work.field_8D0. */
typedef struct {
    u8 _pad00[0x0C];
    /* 0x0C */ u8 u;
    u8 _pad0D[0x0B];
    /* 0x18 */ s32 x;
    /* 0x1C */ s32 y;
} Stg00TexSlot;

/* POLY_FT4 packet. */
typedef struct {
    /* 0x00 */ union {
        u32 word;
        struct {
            u8 addr[3];
            u8 len;
        } b;
    } tag;
    /* 0x04 */ u8 r0;
    /* 0x05 */ u8 g0;
    /* 0x06 */ u8 b0;
    /* 0x07 */ u8 code;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ u8 u0;
    /* 0x0D */ u8 v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ s16 x1;
    /* 0x12 */ s16 y1;
    /* 0x14 */ u8 u1;
    /* 0x15 */ u8 v1;
    /* 0x16 */ u16 tpage;
    /* 0x18 */ s16 x2;
    /* 0x1A */ s16 y2;
    /* 0x1C */ u8 u2;
    /* 0x1D */ u8 v2;
    u16 _pad1E;
    /* 0x20 */ s16 x3;
    /* 0x22 */ s16 y3;
    /* 0x24 */ u8 u3;
    /* 0x25 */ u8 v3;
    u16 _pad26;
} Stg00PolyFT4; /* size 0x28 */

/* Ordering-table link word (libgs setaddr/addPrim shape: 24-bit next pointer, 8-bit length). */
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} Stg00OTag;

/* 0x28-stride zero-terminated part list returned by Cd_GetFileEntry (GfxPartMaskView shape). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x0A];
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    u8 _pad10[0x0C];
    /* 0x1C */ s32 partMask;
    /* 0x20 */ s16 field_20;
    u8 _pad22[0x06];
} Stg00Part; /* size 0x28 */

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Stg00PartMasks;

/* 0x28-stride zero-terminated part list (colour/scale view). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x08];
    /* 0x0C */ u8 field_C;
    u8 _pad0D[0x01];
    /* 0x0E */ u8 field_E;
    u8 _pad0F[0x01];
    /* 0x10 */ s32 field_10;
    u8 _pad14[0x14];
} Stg00PartScale; /* size 0x28 */

/* Actor.work of the panel task (func_80067BAC). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ u8 field_10;
} Stg00PanelWork;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg00TaskArgs3;

typedef struct {
    /* 0x00 */ s32 field_0;
} Stg00TaskArg1;

/* Actor.work of the CD stream task (func_80067E1C). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ u8 field_4;
    u8 _pad05[0x03];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Stg00CdWork;

/* Actor viewed with the frame counter at 0x24 as a word. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ s32 field_24;
} Stg00ActorTimer;

/* Actor.u38 transform viewed with the vertical speed words. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s32 field_34;
    u8 _pad38[0x14];
    /* 0x4C */ s32 field_4C;
} Stg00Xform;

/* Actor.work of the sound test task (func_800684E4). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg00SndWork;

/* Stg00SelWork with field_8 as s16 and the per-slot tables. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ u32 *field_C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ s32 field_14[8];
    /* 0x34 */ u16 field_34[8];
    /* 0x44 */ u8 field_44[8][10];
} Stg00SelWorkX;

/* Actor.work of the random-pose viewer (func_800669F4). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Stg00ViewWork;

/* Stg00ModelWork with the fields func_80067428 touches. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Vec3 field_4;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x04];
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ CVECTOR field_28;
    /* 0x2C */ s32 field_2C;
} Stg00ModelWorkX;

/* ActorModel viewed with the fade colour bytes at 0x38. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
} Stg00ModelFade;

/* ---- externs ---- */
extern s32 D_8005F708;
extern s32 D_8005F714;
extern s32 D_8005F720;
extern s32 D_8005F724;
extern s32 D_8005F778;
extern s32 D_8005F788;
extern s32 D_8005F79C;
extern s32 D_80068AA0[];
extern s32 D_800692C4[];
extern Stg00PartMasks D_800692D0[];
extern s32 D_80068F28[];
extern s32 D_80068F38[];
extern s32 D_80068F44[];
extern s32 D_80068FA0[];
extern s32 D_80068FB8[];
extern Elem12 D_80068EEC;
extern Elem12 D_80068EF8;
extern Elem12 D_80068F04;
extern u8 D_80069318[];

extern void Sys_SetFrameRate60(void);
extern void Task_NextState1(Actor *arg0);
extern void Task_NextState2(Actor *arg0);
extern void Task_NextState3(Actor *arg0);
extern void Task_NextState4(Actor *arg0);
extern void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Gfx_InitLights(void);
extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern void Gfx_SetPartsNumber(EntA0 *, s32, s32, s32);
extern void func_8001E7E4(s32 a0, void *a1);
extern s32 func_8001EE5C(s32);
extern s32 func_8001EE10(s32 id);
extern s32 func_8001EF64(s32 id);
extern s32 *func_8001EFF0(s32 id);
extern s32 Cd_GetFileLba(s32 arg0);
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(s32, u8 *, u8 *);
extern void CdIntToPos(s32, u8 *);
extern s32 CdPosToInt(void *);
extern s32 CdSync(s32, u8 *);
extern s32 CdLastCom(void);
extern void Actor_StopAxisMotion(Actor *arg0, s32 arg1);
extern void Actor_SetAxisMotion(Actor *arg0, s32 arg1, Elem12 *arg2);
extern s32 func_80020D54(Actor *a0, s32 i);
extern s32 func_80020E00(Actor *a0, s32 i);
extern s32 Anim_HasModelAnim(Actor *a0, s32 n);
extern void Anim_SetModelAnim(Actor *, s32);
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Snd_UnloadSlot(s32 idx);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern void Snd_PlayById(s32 id, s32 set);
extern void Snd_StopAll(void);
extern s32 Snd_AnySlotLoading(void);

void func_80063E34(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s32 arg2, s32 arg3);
s32 func_80064B08(Stg00RelocHdr *arg0, s32 arg1);
void func_80066084(Actor *arg0);
void func_8006620C(Actor *arg0);
void func_80066130(Actor *arg0);
void func_80066828(Actor *arg0);
void func_800668D4(Actor *arg0);
void func_80066E1C(Actor *arg0, s32 arg1);
void func_80066FE8(Actor *arg0);
void func_80067120(Actor *arg0, s32 arg1, s32 arg2);
void func_800673FC(Actor *arg0);
u8 *func_80068150(s32 arg0);
u8 *func_80068170(s32 arg0, s32 arg1);
s32 func_80068190(void);
s32 func_800681C4(s32 arg0);
TaskEntry *func_80068930(void);
void func_80068958(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8006899C(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80068A00(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80068A44(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);

/* ---- functions ---- */

#endif
