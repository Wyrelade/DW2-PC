#ifndef STAG0000_H
#define STAG0000_H

#include "common.h"
#include "main/156C.h"

/* STAG0000 (Ovl_FileIds id 0, gameMode 0x1xx). */

/* Work area pointed to by Stg00_FontWork. */
typedef struct {
    /* 0x000 */ u16 clut[0x60];
    /* 0x0C0 */ u16 buf[0x400];
    /* 0x8C0 */ u16 clutX;      /* small RECT x (LoadImage) */
    /* 0x8C2 */ u16 clutY;      /* small RECT y */
    /* 0x8C4 */ s16 clutW;      /* small RECT w */
    /* 0x8C6 */ s16 clutH;      /* small RECT h */
    /* 0x8C8 */ RECT rectBig;
    /* 0x8D0 */ s32 *texSlot;
    /* 0x8D4 */ s16 color;
    /* 0x8D6 */ u8 textBuf[0x102]; /* Stg00_FontTextBuf points here */
} Stg00Work; /* size 0x9D8 */

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg00Vec3;

typedef struct {
    /* 0x00 */ s32 view[7];
} Stg00CameraArg;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 homeX;
    /* 0x08 */ s32 homeY;
    /* 0x0C */ s32 homeZ;
} Stg00ModelHomeView;

extern SysState Sys_State;
extern u8 **Stg00_SoundBanks[];
extern u8 *Stg00_FontTextBuf;
extern Stg00Work *Stg00_FontWork;
extern u8 Stg00_FontGlyphs[];       /* 1bpp font bits unpacked by Stg00_FontInit */

extern void Task_DefaultDestroy(Actor *arg0);
extern TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2);
extern void Gfx_ReleaseTexSlot(s32 *arg0);
extern void Mem_Free(ActorWork *arg0);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdControlF(s32, s32);
#endif
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);

void Stg00_FontFree(void);
void Stg00_FontDrawStr(s32 arg0, s32 arg1, u8 *arg2);



/* Actor.work of the objects moved by Stg00_CamMoveViewPoint family (0x1C now a GsCOORDINATE2). */
typedef struct {
    /* 0x00 */ s32 vpx;
    /* 0x04 */ s32 vpy;
    /* 0x08 */ s32 vpz;
    /* 0x0C */ s32 vrx;
    /* 0x10 */ s32 vry;
    /* 0x14 */ s32 vrz;
    /* 0x18 */ s32 projection;
    /* 0x1C */ Coord1F668 coord;
    /* 0x6C */ s32 originX;
    /* 0x70 */ s32 originY;
    /* 0x74 */ s32 originZ;
    u8 _pad78[0x04];
    /* 0x7C */ s16 rotX;
    /* 0x7E */ s16 rotY;
    /* 0x80 */ s16 rotZ;
    u8 _pad82[0x02];
    /* 0x84 */ s32 dirty;
} Stg00CameraWork;

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

/* Actor.work of the parts-drawing tasks (Stg00_LineupDraw / Stg00_GroupViewDraw). */
typedef struct {
    u8 _pad00[0x0C];
    /* 0x0C */ s32 winVariant;
} Stg00PartsWork;

/* Stack block passed to GsSetRefView2. */
typedef struct {
    /* 0x00 */ s32 vpx;
    /* 0x04 */ s32 vpy;
    /* 0x08 */ s32 vpz;
    /* 0x0C */ s32 vrx;
    /* 0x10 */ s32 vry;
    /* 0x14 */ s32 vrz;
    /* 0x18 */ s32 rz;
    /* 0x1C */ Coord1F668 *super;
} Stg00RefView;

/* Init arg of the model task (Stg00_DigiModelInit). */
typedef struct {
    /* 0x00 */ s32 digiId;
    /* 0x04 */ Vec3 pos;
    /* 0x10 */ s32 facing;
} Stg00ModelArg;

typedef struct {
    /* 0x00 */ s32 _pad0;
    /* 0x04 */ Vec3 homePos;
    /* 0x10 */ s32 facing;
    /* 0x14 */ s32 modelFile;
    u8 _pad18[0x08];
    /* 0x20 */ s32 drawTex;
    /* 0x24 */ s32 drawWire;
    /* 0x28 */ CVECTOR wireColor;
} Stg00ModelWork;

/* Actor.work whose first word selects the display mode. */
typedef struct {
    /* 0x00 */ s32 videoMode;
} Stg00ModeWork;

/* File-relative pointer tables fixed up by Stg00_RelocDungFile. */
typedef struct {
    /* 0x00 */ u32 cellBits;
    /* 0x04 */ u32 spawnPoints;
    /* 0x08 */ u32 chests;
    /* 0x0C */ u32 cmdList;
    /* 0x10 */ u32 enemyParties;
} Stg00DungLayout;

/* 8-byte record of the list at Stg00DungLayout.field_C (tag 0xFF ends it). */
typedef struct {
    /* 0x00 */ union {
        u8 tag;
        u32 bits;
    } posPicks01;
    /* 0x04 */ u32 picks23;
} Stg00RelocCmd;

typedef struct {
    /* 0x00 */ u8 itemId;
    u8 _pad01[0x03];
} Stg00RelocFlag;

typedef struct {
    /* 0x00 */ u32 sel;
    /* 0x04 */ u32 chk;
} Stg00RelocPair;

typedef struct {
    /* 0x00 */ u32 name;
    u8 _pad04[0x04];
    /* 0x08 */ PTR32(Stg00DungLayout) layouts[8]; /* file words relocated in place */
    u8 _pad28[0x06];
    /* 0x2E */ s16 hazardLevel;
    u8 _pad30[0x04];
    /* 0x34 */ Stg00RelocFlag chests[8];
    /* 0x54 */ Stg00RelocPair hazardGroups[5];
} Stg00DungFloor;

/* Bit table copied to the stack by Stg00_CalcLayoutMask (5 groups of 6 words). */
typedef struct {
    /* 0x00 */ u32 bits[5][6];
} Stg00BitTbl; /* size 0x78 */
extern const Stg00BitTbl Stg00_LayoutMaskBits;

/* Actor.work of the select task (Stg00_DungSelTask and its states). */
typedef struct {
    /* 0x00 */ s16 dungeonIdx;
    /* 0x02 */ s16 floor;
    /* 0x04 */ s16 lastFloor;
    /* 0x06 */ s16 floorCount;
    /* 0x08 */ u8 layout;
    u8 _pad09[0x01];
    /* 0x0A */ s16 flagIdx;
    /* 0x0C */ u32 *floorTable;
    /* 0x10 */ u32 firstFloor;
} Stg00SelWork;

typedef struct {
    /* 0x00 */ s16 dungFileId;
    u8 _pad02[0x12];
} Stg00DungEntry; /* size 0x14 */


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
    /* 0x00 */ s32 digiId;
    /* 0x04 */ s32 posX;
    /* 0x08 */ s32 posY;
    /* 0x0C */ s32 posZ;
    /* 0x10 */ s32 facing;
} Stg00TaskArgs5;

typedef struct {
    /* 0x0 */ s16 posX;
    /* 0x2 */ s16 posZ;
} Stg00Pos;

/* Sorted list work (Stg00_LineupBuildList / Stg00_LineupSpawnModels). */
typedef struct {
    u8 _pad000[0x10];
    /* 0x010 */ s32 sortKeys[200];
    /* 0x330 */ s32 digiIds[200];
    /* 0x650 */ s32 count;
    /* 0x654 */ s32 scrollTop;
    /* 0x658 */ s32 layout;
} Stg00ListWork;

typedef struct {
    u8 _pad00[0x10];
    /* 0x10 */ s32 modelListIdx;
    /* 0x14 */ s32 nameText;
    /* 0x18 */ s32 nameTextSmall;
} Stg00NameWork;

typedef struct {
    /* 0x00 */ s32 scrollX;
    /* 0x04 */ s32 scrollY;
} Stg00ScrollWork;

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 homeX;
    /* 0x08 */ s32 homeY;
    /* 0x0C */ s32 homeZ;
    /* 0x10 */ s32 facing;
    u8 _pad14[0x18];
    /* 0x2C */ s32 skillId;
} Stg00SpawnWork;

extern Halves Gfx_NeutralRgb;
extern s32 Gfx_ZeroVector[];
extern PadState Pad_State[];
extern DungState *Dung_StatePtr;
extern s32 Stg00_LineupWinMasks[];
extern s32 Stg00_GroupWinMasks[];
extern Stg00Pos Stg00_LineupLayouts[][9];
extern u8 Stg00_SoundLabelBuf[2][10];

extern void Gfx_HidePartsByMask(GfxPartMaskView *p, s32 mask);
extern void Gfx_DrawParts(s32 arg0);
extern void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
extern void Gfx_ResetModelBones(Actor *);
extern void Task_NextState0(Actor *);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Task_Destroy(s32 *arg0);
extern void Task_Create(u32, s32 *, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
#endif
extern s32 Digi_GetModelFile(s32 id);
extern void Anim_StepModelAnim(Actor *);
extern void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg00RefView *);
#endif
extern void Flag_Set(s32, s32);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern u16 Digi_GetModelListId(s32 idx);
#else
extern s32 Digi_GetModelListId(s32 idx);
#endif
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 func_8001E79C(s32 id);
#else
extern s32 func_8001E79C(s32 id);
#endif
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 Digi_GetHitFxOffsetY(s32 id);
#else
extern s32 Digi_GetHitFxOffsetY(s32 id);
#endif
extern s32 Digi_GetModelListCount(void);
extern void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b);
extern s32 Rand_Next();
extern void Text_Close(s32 *);
extern void Text_Open(void *, TextOpenArgs *);
extern u8 *Digi_GetDefaultName(s32);
extern s32 Skill_GetNameText(s32);
extern u8 Stg00_DigiViewSkills[];

/* Stg00_DigiViewPages record: parts file id at 0 (Stg00_DigiViewDraw). */
typedef struct {
    /* 0x0 */ s32 partsFileId;
    /* 0x4 */ s32 maxRow;
} Stg00DigiViewPage; /* size 8 */
extern Stg00DigiViewPage Stg00_DigiViewPages[];

/* Actor.work of Stg00_DigiViewDraw (also Stg00_DigiViewTask: the same dialog-cursor state). */
typedef struct {
    /* 0x00 */ s32 digiCursor;
    /* 0x04 */ s32 pageCursor;
    /* 0x08 */ s32 panel;
    /* 0x0C */ s32 page;
    /* 0x10 */ s32 modelListIdx;
    /* 0x14 */ s32 nameText;
    /* 0x18 */ s32 nameTextSmall;
    /* 0x1C */ s32 skillTexts[14]; /* text handles */
    /* 0x54 */ s32 drawTex;
    /* 0x58 */ s32 lastDirUp;
    /* 0x5C */ s32 skillScroll;
    /* 0x60 */ s32 skillCol;
    /* 0x64 */ s32 skillRow;
} Stg00DigiViewWork;

/* Stg00DigiViewWork's leading 4 words (field_0..field_C) viewed as a slot array,
 * indexed by field_8 (Stg00_DigiViewTask). */
typedef union {
    /* 0x00 */ s32 words[4];
    /* 0x00 */ u8 bytes[16];
} Work65E24Slots;

extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern void Stg00_DigiViewSpawnModel(Actor *arg0);
extern void Task_SetState2(Actor *arg0, u32 arg1);
extern void Task_SetState4(Actor *arg0, u32 arg1);
extern u8 Stg00_DigiViewPage2Anims[][4];
extern u8 Stg00_DigiViewPage3Anims[][4];

void Stg00_RelocPtr(u32 *arg0, u32 arg1);
void Stg00_DungSelPickFloor(Actor *arg0, Stg00SelWork *arg1);
void func_80064E44(void);
void Stg00_FontInit(void);
void Stg00_FontSetColor(s16 arg0);
u8 *Stg00_GetSoundLabel(s32 arg0, s32 arg1);

/* ---- functions ---- */


/* Actor.work of the fade task (Stg00_PopupTask). */
typedef struct {
    /* 0x00 */ s32 kind;
    u8 _pad04[0x08];
    /* 0x0C */ s32 scale;
    /* 0x10 */ s32 palette;
} Stg00FadeWork;

/* Actor.work of the counter task (Stg00_WindowTestTask) and parts task (Stg00_WindowTestDraw). */
typedef struct {
    /* 0x00 */ s32 cursor;
    /* 0x04 */ s32 holdDelay;
    /* 0x08 */ u8 counterDigits[6];
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
    /* 0x0E */ u8 unscaled;
    /* 0x0F */ u8 visible;
    u8 _pad10[0x0C];
    /* 0x1C */ s32 partMask;
    /* 0x20 */ s16 rotX;
    u8 _pad22[0x06];
} Stg00Part; /* size 0x28 */

typedef struct {
    /* 0x00 */ s32 frontMask;
    /* 0x04 */ s32 backMask;
    /* 0x08 */ s32 spinMask;
    /* 0x0C */ s32 resetMask;
} Stg00PartMasks;

/* 0x28-stride zero-terminated part list (colour/scale view). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x08];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x01];
    /* 0x0E */ u8 unscaled;
    u8 _pad0F[0x01];
    /* 0x10 */ s32 scaleX;
    u8 _pad14[0x14];
} Stg00PartScale; /* size 0x28 */

/* Actor.work of the panel task (Stg00_PopupDraw). */
typedef struct {
    /* 0x00 */ s32 kind;
    /* 0x04 */ s32 value;
    /* 0x08 */ s32 subPart;
    /* 0x0C */ s32 scale;
    /* 0x10 */ u8 palette;
} Stg00PanelWork;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg00TaskArgs3;

typedef struct {
    /* 0x00 */ s32 owner;
} Stg00TaskArg1;

/* Actor.work of the CD stream task (Stg00_XaPlayTask). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ u8 xaChannel;
    u8 _pad05[0x03];
    /* 0x08 */ s32 track;
    /* 0x0C */ s32 startSector;
    /* 0x10 */ s32 endSector;
} Stg00CdWork;

/* Actor viewed with the frame counter at 0x24 as a word. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ s32 frameCount;
} Stg00ActorTimer;

/* Actor.u38 transform viewed with the vertical speed words. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s32 posY;
    u8 _pad38[0x14];
    /* 0x4C */ s32 moveDeltaY;
} Stg00Xform;

/* Actor.work of the sound test task (Stg00_SoundTestTask). */
typedef struct {
    /* 0x00 */ s32 titleText;
    /* 0x04 */ s32 bankText;
    /* 0x08 */ s32 soundText;
    /* 0x0C */ s32 bank;
    /* 0x10 */ s32 sound;
    /* 0x14 */ s32 loadedBank;
    /* 0x18 */ s32 pendingSound;
} Stg00SndWork;

/* Stg00SelWork with field_8 as s16 and the per-slot tables. */
typedef struct {
    /* 0x00 */ s16 dungeonIdx;
    /* 0x02 */ s16 floor;
    /* 0x04 */ s16 lastFloor;
    /* 0x06 */ s16 floorCount;
    /* 0x08 */ s16 layout;
    /* 0x0A */ s16 flagIdx;
    /* 0x0C */ u32 *floorTable;
    /* 0x10 */ u32 firstFloor;
    /* 0x14 */ s32 layoutMasks[8];
    /* 0x34 */ u16 maskBitCounts[8];
    /* 0x44 */ u8 maskGroupCounts[8][10];
} Stg00SelWorkX;

/* Actor.work of the random-pose viewer (Stg00_GroupViewTask). */
typedef struct {
    /* 0x00 */ s32 videoMode;
    /* 0x04 */ s32 _pad4;
    /* 0x08 */ s32 camPreset;
    /* 0x0C */ s32 winVariant;
} Stg00ViewWork;

/* Stg00ModelWork with the fields Stg00_DigiModelTask touches. */
typedef struct {
    /* 0x00 */ s32 _pad0;
    /* 0x04 */ Vec3 homePos;
    /* 0x10 */ s32 facing;
    /* 0x14 */ s32 modelFile;
    u8 _pad18[0x04];
    /* 0x1C */ s32 subFrame;
    /* 0x20 */ s32 drawTex;
    /* 0x24 */ s32 drawWire;
    /* 0x28 */ CVECTOR wireColor;
    /* 0x2C */ s32 skillId;
} Stg00ModelWorkX;

/* ActorModel viewed with the fade colour bytes at 0x38. */
typedef struct {
    u8 _pad00[NATIVE_OFS(ActorModel, clutRow, 0x34)];
    /* 0x34 */ s16 clutRow;
    /* 0x36 */ s16 tpageBits;
    /* 0x38 */ u8 flatR;
    /* 0x39 */ u8 flatG;
    /* 0x3A */ u8 flatB;
} Stg00ModelFade;

/* ---- externs ---- */
extern TaskDesc Stg00_ScrollViewDesc;
#ifdef DW2_NATIVE
/* DATA_LABEL alias (scrollview.c): Stg00_ScrollViewDesc read as s32[]. Retail reads up to 20
 * words, past the 24-byte TaskDesc (debug view bug); the native layout behind it differs. */
#define Stg00_ScrollTileTex ((s32 *)&Stg00_ScrollViewDesc)
#else
extern s32 Stg00_ScrollTileTex[];
#endif
extern s32 Stg00_WindowTestMasks[];
extern Stg00PartMasks Stg00_WindowTestParts[];
extern s32 Stg00_PopupItemMasks[];
extern s32 Stg00_PopupNumMasks[];
extern s32 Stg00_PopupNumParts[];
extern s32 Stg00_XaTrackStart[];
extern s32 Stg00_XaTrackLength[];
extern Elem12 Stg00_HitReactHop1Motion;
extern Elem12 Stg00_HitReactHop2Motion;
extern Elem12 Stg00_HitReactPushMotion;
extern u8 Stg00_SoundTestTitle[];

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
extern void Gfx_SetPartsNumber(GfxPart *p, s32 mask, s32 n, s32 val);
extern void Digi_GetCastFxOffsets(s32 a0, void *a1);
extern s32 Skill_GetPartsEntry(s32);
extern s32 Skill_GetCastAnim(s32 id);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 Skill_GetPower(s32 id);
#else
extern s32 Skill_GetPower(s32 id);
#endif
extern s32 *Skill_GetShotXa(s32 id);
extern s32 Cd_GetFileLba(s32 arg0);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(s32, u8 *, u8 *);
extern void CdIntToPos(s32, u8 *);
extern s32 CdPosToInt(void *);
extern s32 CdSync(s32, u8 *);
extern s32 CdLastCom(void);
#endif
extern void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1);
extern void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2);
extern s32 Actor_ApplyAxisMotion(ContC40 *a0, s32 i);
extern s32 Actor_ApplyAxisMotionRev(ContC40 *a0, s32 i);
extern s32 Anim_HasModelAnim(Actor *a0, s32 n);
extern void Anim_SetModelAnim(Actor *, s32);
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Snd_UnloadSlot(s32 idx);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern void Snd_PlayById(s32 id, s32 set);
extern void Snd_StopAll(void);
extern s32 Snd_AnySlotLoading(void);

void Stg00_InitTileSprt(Stg00Sprt *arg0, GfxPartTexSlot *arg1, s32 arg2, s32 arg3);
s32 Stg00_CalcLayoutMask(Stg00DungFloor *arg0, s32 arg1);
void Stg00_LineupSetVideoMode(Actor *arg0);
void Stg00_LineupBuildList(Actor *arg0);
void Stg00_LineupSpawnModels(Actor *arg0);
void Stg00_GroupViewSetVideoMode(Actor *arg0);
void Stg00_SpawnRandomGroup(Actor *arg0);
void Stg00_SpawnSkillCastFx(Actor *arg0, s32 arg1);
void Stg00_SpawnSkillHitFx(Actor *arg0);
void Stg00_HitReactUpdate(Actor *arg0, s32 arg1, s32 arg2);
void Stg00_ResetToHomePos(Actor *arg0);
u8 *Stg00_GetBankLabel(s32 arg0);
u8 *Stg00_GetSoundIdLabel(s32 arg0, s32 arg1);
s32 Stg00_CountSoundBanks(void);
s32 Stg00_CountBankSounds(s32 arg0);
TaskEntry *Stg00_FindCamera(void);
void Stg00_CamMoveViewPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamMoveRefPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamMoveOrigin(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamRotate(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);

/* Task descriptors (Stg00_TaskDescs rows). */
extern TaskDesc Stg00_StageSetupDesc;
extern TaskDesc Stg00_DungSelDesc;
extern TaskDesc Stg00_FightBgDesc;
extern TaskDesc Stg00_DigiViewDesc;
extern TaskDesc Stg00_LineupDesc;
extern TaskDesc Stg00_VideoModeDesc;
extern TaskDesc Stg00_GroupViewDesc;
extern TaskDesc Stg00_DigiModelDesc;
extern TaskDesc Stg00_PopupDesc;
extern TaskDesc Stg00_XaPlayDesc;
extern TaskDesc Stg00_WindowTestDesc;
extern TaskDesc Stg00_SoundTestDesc;
extern TaskDesc Stg00_CameraDesc;
extern TaskDesc *Stg00_TaskDescs[];

/* ---- functions ---- */

#endif
