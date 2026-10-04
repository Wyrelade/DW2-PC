#ifndef STAG2000_H
#define STAG2000_H

#include "common.h"
#include "main/156C.h"

/* STAG2000 (Ovl_FileIds id 2, gameMode 0x3xx). */

/* Work whose first word is set by Stg20_StaticBgInit / Stg20_MapBgInit / Stg20_ShadowInit. */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg20Work;

/* Work of task 0x30D (Stg20_MsgWinClear closes it with Text_Close, Stg20_MsgWinGetChoice reads 0x1C). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 msgText;
    u8 _pad08[0x10];
    /* 0x18 */ s32 msgPending;
    /* 0x1C */ s32 choice;
} Stg20TextWork;

/* Three words copied into a task work by Stg20_XaStreamInit. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg20Vec3;

/* Model task work (Stg20_WalkerIsPathDone, Stg20_WalkerSetAnim). */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ s32 anim;
    u8 _pad30[0x44];
    /* 0x74 */ s32 done;
} Stg20ModelWork;

/* Actor viewed with the word at 0x04 (Stg20_WalkerSetAnim reads it before the work). */
typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 walkerKind;
    u8 _pad08[0x24];
    /* 0x2C */ Stg20ModelWork *work;
} Stg20ModelTask;

/* Work holding a 0x43-entry s16 list at 0x60 (Stg20_PartsListHas, Stg20_PartsListRemove). */
typedef struct {
    u8 _pad00[0x60];
    /* 0x60 */ s16 inv[0x43];
} Stg20ListWork;

/* Actor.u38.ptr38 viewed with the s16 at 0x42 (Stg20_WalkerFaceDir). */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 posX;
    /* 0x34 */ s32 posY;
    /* 0x38 */ s32 posZ;
    u8 _pad3C[0x06];
    /* 0x42 */ s16 rotY;
    u8 _pad44[0x14];
    /* 0x58 */ s32 scaleX;
    /* 0x5C */ s32 scaleY;
    /* 0x60 */ s32 scaleZ;
    u8 _pad64[0x20];
    /* 0x84 */ Stg20Vec3 axisMotion2;
} Stg20Rot;

/* Map position: two s16 indices into Stg20_MapGrid (Stg20_GetGridCell). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg20Cell;

/* Save_GameState viewed with the u16 list at 0x2C scanned by Stg20_IsPartInstalled. */
typedef struct {
    u8 _pad00[0x01];
    /* 0x01 */ u8 areaSelectArg;
    u8 _pad02[0x22];
    /* 0x24 */ u16 hp;
    /* 0x26 */ u16 maxHp;
    /* 0x28 */ u16 mp;
    /* 0x2A */ u16 maxMp;
    /* 0x2C */ u16 slotItems[0x13];
    /* 0x52 */ u8 slotStatus[0x14];
    /* 0x66 */ u16 bagItems[0x30];
    u8 _padC6[0xD0E];
    /* 0xDD4 */ u16 storageCounts[1];
} Stg20GameState;

/* overlay data */
extern s16 Stg20_DirAngles[4];
extern u8 Stg20_MapGrid[24][24];

/* main exe */
extern GameState Save_GameState;
extern s32 D_8005E628;             /* Save_GameState.field_8 as a scalar reloc */
extern u8 D_8005E6F1;
extern void Task_DefaultDestroy(Actor *);
extern void Task_NextState0(Actor *);
extern TaskEntry *Task_FindFirst(s32, s32, s32);
extern void Text_Close(s32 *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern s32 CdControlF(s32, s32);
extern void Gfx_DrawParts(s32);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void Anim_SetModelAnim(Actor *, s32);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);

/* overlay */
extern void Stg20_BuildMapGrid(Actor *);

/* ---- added by p35 agent o ---- */
extern u8 Stg20_DnaTypeIndexTbl[3][3];
extern u8 Stg20_DnaResultTbl[][3][8][8];
extern u16 Stg20_EngineHpTbl[];
extern u16 Stg20_BatteryEpTbl[];
extern s32 Stg20_TalkActive;
extern Stg20Cell Stg20_CellTmp;
extern Stg20Cell Stg20_DirCellDelta[4];
extern Stg20Vec3 Stg20_MoveParams[];
extern CVECTOR Stg20_JogBgWireColor;
extern Halves Stg20_AreaNamePos;
extern s32 Gfx_ZeroVector[];

extern void Task_SetState1(Actor *arg0, u32 arg1);
extern TaskEntry *Task_FindNext(void);
extern s32 Digi_GetType(s32);
extern s32 func_8001D910(s32);
extern s32 Skill_GetDescText(s32);
extern void Digi_SortRoster(void);
extern void Anim_StepModelAnim(Actor *);
extern void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
extern void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3);
extern void Actor_InitTransform(Actor *, s32 *, s32);
extern void Gfx_ResetModelBones(Actor *);

extern s32 Stg20_GetGridCell(Stg20Cell *c);
extern Stg20Cell *Stg20_GetActorCell(Actor *a);
extern Stg20Cell *Stg20_GetCellInDir(Actor *a, s32 dir);

/* Text work with records (Stg20_AreaSelectShowName). */
typedef struct {
    /* 0x00 */ s32 text;
    u8 _pad04[0x14];
} Stg20TextRec; /* size 0x18 */

typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 text;
    /* 0x08 */ s32 index;
    u8 _pad0C[0x04];
    /* 0x10 */ Stg20TextRec recs[1];
} Stg20PickWork;

/* Model draw work (Stg20_LabDigiModelDraw). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 pos[3];
    u8 _pad10[0x04];
    /* 0x14 */ u16 rot;
    u8 _pad16[0x02];
    /* 0x18 */ s32 modelId;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u8 field_24;
    /* 0x25 */ u8 field_25;
    /* 0x26 */ u8 field_26;
    u8 _pad27[0x05];
    /* 0x2C */ s32 visible;
} Stg20DrawWork;

/* Work with a direction flag word at 0x24 (Stg20_InputToDir). */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ s32 input;
} Stg20FlagWork;

/* GsSetRefView2 block + coordinate at the head of a camera work (Stg20_CameraDraw). */
typedef struct {
    /* 0x00 */ s32 vpx;
    /* 0x04 */ s32 vpy;
    /* 0x08 */ s32 vpz;
    /* 0x0C */ s32 vrx;
    /* 0x10 */ s32 vry;
    /* 0x14 */ s32 vrz;
    /* 0x18 */ s32 rz;
    /* 0x1C */ Coord1F668 *super;
} Stg20RefView;

typedef struct {
    /* 0x00 */ Stg20RefView view;
    /* 0x20 */ Coord1F668 coord;
    /* 0x70 */ s32 proj;
    /* 0x74 */ s32 tx;
    /* 0x78 */ s32 ty;
    /* 0x7C */ s32 tz;
    u8 _pad80[0x04];
    /* 0x84 */ s16 rot[3];
    u8 _pad8A[0x02];
    /* 0x8C */ s32 timer;
    /* 0x90 */ s32 speed;
} Stg20CamWork;

extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg20RefView *);

/* Work of the cursor/marker task (Stg20_WalkerHalt). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 endX;
    /* 0x0A */ s16 endY;
    u8 _pad0C[0x0C];
    /* 0x18 */ s32 index;
    u8 _pad1C[0x40];
    /* 0x5C */ s32 wait;
    u8 _pad60[0x14];
    /* 0x74 */ s32 done;
} Stg20CursorWork;

/* 0x28-stride parts record viewed with the byte at 0x0E (Stg20_MsgWinDraw). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0x0A];
    /* 0x0E */ u8 field_E;
    u8 _pad0F[0x19];
} Stg20Part; /* size 0x28 */

/* Model work (Stg20_WalkerDraw). */
typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ s32 modelId;
    u8 _pad24[0x40];
    /* 0x64 */ s32 visible;
} Stg20Draw2Work;

/* 0xC-stride slot record at 0x48 of the roster menu work (Stg20_LabRosterFillSlots). */
typedef struct {
    /* 0x00 */ s32 used;
    /* 0x04 */ s32 enabled;
    /* 0x08 */ s32 slot;
} Stg20Slot;

typedef struct {
    /* 0x00 */ s32 count;
    /* 0x04 */ u32 timer;
    /* 0x08 */ s32 texts[16];
    /* 0x48 */ Stg20Slot slots[4];
} Stg20SlotWork;

typedef struct {
    /* 0x00 */ s32 menuAllowed;
    /* 0x04 */ s32 talkActive;
    /* 0x08 */ s32 result;
    /* 0x0C */ s32 labMode;
    /* 0x10 */ s32 excludeFirst;
    /* 0x14 */ s32 rosterTop;
    /* 0x18 */ s32 rosterCursor;
    /* 0x1C */ s32 pickedIndex;
    /* 0x20 */ s32 pickStep;
    /* 0x24 */ s32 infoMode;
    /* 0x28 */ s32 infoRosterIndex;
    /* 0x2C */ s32 evoTargetId;
    /* 0x30 */ s32 skillRosterIndex;
    /* 0x34 */ s32 dnaParent0;
    /* 0x38 */ s32 dnaParent1;
    u8 _pad3C[0x04];
    /* 0x40 */ s32 modelDigiId;
    /* 0x44 */ s32 modelNoGrow;
    /* 0x48 */ s32 modelSlide;
    /* 0x4C */ s32 dnaNewSlot;
    /* 0x50 */ s32 menuChoice;
    /* 0x54 */ s32 sellMode;
} Stg20MenuState;

/* 0x18-byte record of file 0xD28xxxx (Stg20_GetMapDest). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 text;
    u8 _pad08[0x0B];
    /* 0x13 */ u8 relocated;
    u8 _pad14[0x04];
} Stg20FileRec; /* size 0x18 */

/* Five map cells with their countdown timers (Stg20_TickOccupantMarks). */
typedef struct {
    /* 0x00 */ Stg20Cell cell[5];
    /* 0x14 */ s32 timer[5];
} Stg20Marks;

/* Text_Open parameter block with a 4-byte copied position (Stg20_OpenText). */
typedef struct {
    /* 0x00 */ s32 bigFont;
    /* 0x04 */ s32 color;
    /* 0x08 */ Stg20Cell pos;
    /* 0x0C */ s32 charAdvance;
    /* 0x10 */ s32 lineAdvance;
    /* 0x14 */ s32 text;
    /* 0x18 */ s32 charDelay;
    /* 0x1C */ s32 strArg0;
    /* 0x20 */ s32 strArg1;
    u8 _pad24[0x8];
} Stg20TextArgs;

extern Halves Stg20_BitsLabelPos;
extern Stg20MenuState Stg20_MenuState;
extern s32 Sys_GameMode[];

/* Stg20_LabModeSelUpdate yes/no prompt */
typedef struct {
    /* 0x00 */ s32 sel;
    /* 0x04 */ s32 texts[2];
} Stg20YesNoWork;
extern s32 D_800709BC; /* Stg20_MenuState.field_C as a scalar reloc */
extern Halves Stg20_LabDigivolveTextPos;
extern Halves Stg20_LabDnaTextPos;

/* Stg20_WalkerGetInput waypoint walker */
typedef struct {
    u8 _pad00[0x04];
    Stg20Cell path[5];
    s32 index;
    u8 _pad1C[0x08];
    s32 input;
    s32 held;
    u8 _pad2C[0x30];
    s32 wait;
    u8 _pad60[0x14];
    s32 done;
} Stg20WalkWork;
extern u16 Pad_Held; /* Pad_State[0].held as a scalar reloc */
extern s32 Rand_Next();

extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3);
extern s32 Actor_ProjectToScreen(ContC40 *a0);
extern s32 Cd_GetFileOrNull(s32 arg0);
extern void Item_SortList(void);
extern void Text_Open(void *arg0, TextOpenArgs *arg1);
extern void Stg20_MarkGridOccupant(Stg20Cell *c, s32 set, s32 flag);

/* ---- added by p35 agent v ---- */
/* Sys_GameMode (game mode word) viewed as its low byte (Stg20_GetMapInfo). */
typedef struct {
    /* 0x00 */ u8 lo;
} Stg20Mode;

/* Map file 0x309xxxx header; offsets relocated by the file base on first use (Stg20_GetMapInfo). */
typedef struct {
    /* 0x00 */ s32 loaded;
    /* 0x04 */ s32 bgFileId;
    /* 0x08 */ s32 startRecs;
    /* 0x0C */ s32 exits;
    /* 0x10 */ u8 *bits;
    /* 0x14 */ s16 sndSlotContent;
    /* 0x16 */ s16 bgmId;
    /* 0x18 */ s32 stepSndBits;
    /* 0x1C */ s32 overlayParts;
    /* 0x20 */ s32 flagTableFile;
} Stg20MapFile;

/* Work of task 0x30D viewed with the 14-byte name at 0x08 (Stg20_MsgWinShowDigiMsg). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 msgText;
    /* 0x08 */ u8 name[0x0E];
    u8 _pad16[0x02];
    /* 0x18 */ s32 msgPending;
    /* 0x1C */ s32 choice;
} Stg20NameWork;

extern Stg20MapFile *Stg20_GetMapInfo(void);
/* Actor viewed with the word at 0x24 (Stg20_LabModeSelDraw). */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ u32 frameCount;
    u8 _pad28[0x04];
    /* 0x2C */ Stg20Work *work;
} Stg20BlinkTask;

/* Spawn record (Stg20_WalkerInit). */
typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 facing;
    /* 0x04 */ Stg20Cell blk[6];
    /* 0x1C */ s32 flagEntry;
} Stg20Spawn;

typedef struct {
    /* 0x00 */ s32 facing;
    /* 0x04 */ Stg20Cell blk[6];
    /* 0x1C */ s32 flagEntry;
    u8 _pad20[0x44];
    /* 0x64 */ s32 visible;
} Stg20SpawnWork;

/* Four words at 0x30 of Actor.u38.ptr38 copied as one block (Stg20_ShadowUpdate). */
typedef struct {
    /* 0x00 */ s32 v[4];
} Stg20Pos4;

typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ Stg20Pos4 pos;
} Stg20PosView;

/* Work whose first word links to another actor (Stg20_ShadowUpdate). */
typedef struct {
    /* 0x00 */ Actor *target;
} Stg20LinkWork;

/* Work with a row index at 0x30 (Stg20_PartsUpgradeDraw). */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 index;
} Stg20RowWork;

/* Map position as two words (Stg20_WalkerWarpToCell). */
typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
} Stg20Pos2;

/* 0x20-byte record at 0x38 of the item list work (Stg20_UpgradeListRefresh). */
typedef struct {
    /* 0x00 */ u8 name[0x18];
    /* 0x18 */ s32 price;
    /* 0x1C */ s32 item;
} Stg20ItemRec;

typedef struct {
    /* 0x00 */ s32 hdr[4];
    /* 0x10 */ s32 texts[6];
    /* 0x28 */ s32 descText;
    /* 0x2C */ s32 msgText;
    /* 0x30 */ s32 index;
    /* 0x34 */ s32 dirty;
    /* 0x38 */ Stg20ItemRec recs[6];
    /* 0xF8 */ s32 shownMsg;
    /* 0xFC */ s32 msg;
    /* 0x100 */ s32 msgArg;
} Stg20ItemWork;

/* Save_GameState.elems[] viewed from its own symbol with the 12 skill bytes at 0x22 (Stg20_LabSkillsGroup). */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 level;
    u8 _pad0E[0x14];
    /* 0x22 */ u8 skills[12];
    u8 _pad2E[0x2E];
} Stg20Roster; /* size 0x5C */

/* Save_GameState.elems[].name viewed from its own symbol (stride 0x5C, Stg20_LabPairUpdate). */
typedef struct {
    /* 0x00 */ u8 name[0x5C];
} Stg20RosterName;

/* 14-byte skill group at 0x70 of the skill menu work (Stg20_LabSkillsGroup). */
typedef struct {
    /* 0x00 */ u8 list[13];
    /* 0x0D */ u8 count;
} Stg20SkillGroup;

typedef struct {
    /* 0x00 */ s32 texts[19];
    /* 0x4C */ s32 col;
    /* 0x50 */ s32 cursor[4];
    /* 0x60 */ s32 top[4];
    /* 0x70 */ Stg20SkillGroup groups[4];
    /* 0xA8 */ s32 skill;
} Stg20SkillWork;

/* Work of the stage loader task (Stg20_StaticBgUpdate). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 ids[10];
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 geomY;
    /* 0x34 */ s32 settleFrames;
} Stg20LoadWork;

/* Roster entry viewed with signed stats (Stg20_LabInfoDraw). */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 level;
    /* 0x0E */ u8 dp;
    /* 0x0F */ u8 maxLevel;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    /* 0x1C */ s16 attack;
    /* 0x1E */ s16 defense;
    /* 0x20 */ s16 speed;
} Stg20DigiStats;

typedef struct {
    u8 _pad00[0x5C];
    /* 0x5C */ Stg20DigiStats *digi;
} Stg20StatusWork;

/* Item list work (Stg20_PartsListRefresh). */
typedef struct {
    /* 0x00 */ s32 hdr[7];
    /* 0x1C */ s32 descText;
    /* 0x20 */ s32 texts[10];
    /* 0x48 */ s32 bodyType;
    /* 0x4C */ s32 cannonCount;
    /* 0x50 */ s32 frameMode;
    /* 0x54 */ s32 hideMask0;
    /* 0x58 */ s32 hideMask1;
    /* 0x5C */ s32 dirty;
    /* 0x60 */ s16 inv[0x43];
    u8 _padE6[0x02];
    /* 0xE8 */ s32 count;
    /* 0xEC */ s16 items[0x43];
    /* 0x172 */ u8 colors[0x43];
    u8 _pad1B5[0x03];
    /* 0x1B8 */ s32 listShown;
    /* 0x1BC */ s32 cursorShown;
    /* 0x1C0 */ s32 cursor;
    /* 0x1C4 */ s32 top;
} Stg20ItemListWork;

extern Halves Stg20_BeetlePartsTextPos[];
extern s32 Item_GetNameText(s32);
extern void Stg20_OpenMsgOrDesc(void *t, s32 id, Halves pos, s32 arg);
extern Stg20Pos2 Stg20_ShakeOffsets[4];
extern Halves Stg20_ShopMenuBuyPos;
extern Halves Stg20_ShopMenuSellPos;
extern PadState Pad_State[];
extern s32 Digi_GetExpToNextLevel(s32, s32, s32);
extern void Snd_PlayById(s32, s32);
extern void Task_SetState0(Actor *, u32);
extern void Task_NextState2(Actor *);

extern Stg20Roster D_8005E704[];
extern Stg20RosterName Save_RosterNames[];
extern Stg20Cell Stg20_LabPairNamePos[2];
extern SysState Sys_State;
extern s32 Skill_GetType(s32);
extern void SetGeomOffset(s32, s32);
extern void Task_NextState1(Actor *);
extern void Gfx_FadeOutToBlack(s32);
extern void Stg20_OpenText(void *t, s32 text, s32 id, Stg20Cell *pos, s32 color);
extern s32 Stg20_ShopSellMode;
extern s32 D_800709D0;
extern Halves Stg20_LabCaptionPos[3];
extern Halves Stg20_UpgradeTextPos[];
extern s32 Item_GetPrice(s32);
extern s32 Flag_Test(s32);
extern void Flag_Set(s32, s32);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern s32 Item_GetDescText(s32);
extern u8 *Digi_GetDefaultName(s32);

/* part 36 salvage */
typedef struct {
    /* 0x00 */ s16 items[50];
    /* 0x64 */ u8 names[50][25];
} Stg20ShopList;
typedef struct {
    /* 0x00 */ s32 hdr[4];
    /* 0x10 */ s32 descText;
    /* 0x14 */ s32 text14;
    /* 0x18 */ s32 text18;
    /* 0x1C */ s32 texts[8];
    /* 0x3C */ s32 dirty;
    /* 0x40 */ s32 cursor;
    /* 0x44 */ s32 page;
    /* 0x48 */ s32 count;
    /* 0x4C */ s32 pages;
    /* 0x50 */ u8 field_50;
    /* 0x51 */ u8 field_51;
    u8 _pad52[0x06];
    /* 0x58 */ s32 ownedCount;
    /* 0x5C */ s32 msgId;
    /* 0x60 */ s32 promptId;
} Stg20ShopListWork;
extern Stg20ShopList Stg20_ShopItems;
extern u16 D_8005E686[0x30];
/* Save_GameState.field_66 as a scalar reloc */
extern void Stg20_FormatPrice(u8 *out, s32 v);
extern void Task_Create(u32, s32 *, s32);
extern void Stg20_MsgWinShowSysMsg(s32 id);
extern void Stg20_LabDigivolve(Actor *a);
extern void Stg20_LabDnaDigivolve(Actor *a);
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ TaskEntry *menu;
    /* 0x08 */ s32 timer;
    /* 0x0C */ s32 busy;
} Stg20CtrlWork;
extern s32 Stg20_ByteListHas(u8 *s, s32 c);
extern s32 Stg20_IsPartInstalled(s32 id);
extern u8 Stg20_PartsAnyBody[];
extern u8 Stg20_ShooterGunAmmo[];
extern u8 Stg20_ZCannonAmmo[];
extern u8 Stg20_PartsAdmantOnly[];
extern u8 Stg20_PartsSteelOnly[];
extern u8 Stg20_PartsNotAdmant[];
extern u8 Stg20_PartsTitanOnly[];
extern u8 Stg20_PartsNotSteel[];
extern u8 Stg20_MissileGunAmmo[];
extern u8 Stg20_RCannonAmmo[];
extern u16 D_8005E64C;
/* Save_GameState.field_2C[0] as a scalar reloc */
extern u16 D_8005E65C;
/* Save_GameState.field_2C[8] */
extern u16 D_8005E65E;
/* Save_GameState.field_2C[9] */
extern u16 D_8005E660;
/* Save_GameState.field_2C[10] */
extern u16 D_8005E662;
extern s32 Cd_GetFileLba(s32 arg0);
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(s32, u8 *, u8 *);
extern void CdIntToPos(s32, u8 *);
extern s32 CdPosToInt(void *);
extern s32 CdSync(s32, u8 *);
extern s32 CdLastCom(void);
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ u8 channel;
    u8 _pad05[0x03];
    /* 0x08 */ s32 len;
    /* 0x0C */ s32 start;
    /* 0x10 */ s32 end;
} Stg20XaWork;
extern s32 D_80070A00;
typedef struct {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
    /* 0x02 */ u8 mode;
    /* 0x03 */ u8 arg;
} Stg20Exit;
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ s32 arg;
} Stg20ExitWork;
typedef struct {
    /* 0x00 */ s32 scroll;
    u8 _pad04[0x08];
    /* 0x0C */ s32 on;
    /* 0x10 */ s32 level;
} Stg20ScrollWork;
typedef struct {
    u8 _pad00[0x40];
    /* 0x40 */ s32 row;
    /* 0x44 */ s32 page;
    u8 _pad48[0x04];
    /* 0x4C */ s32 pages;
    u8 _pad50[0x08];
    /* 0x58 */ s32 ownedCount;
} Stg20ShopWork;
extern Halves Stg20_LabRosterTextPos[4][4];
extern s32 Digi_GetRank(s32);

/* ---- added by p36 agent b ---- */
extern s32 Stg20_CellDistWeighted(Stg20Cell *c, s32 x, s32 y, s32 flag);

/* 0x18-byte pick record (Stg20_AreaSelectFindDir). */
typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 flag;
    /* 0x04 */ s32 text;
    /* 0x08 */ s32 fileId;
    /* 0x0C */ s32 altFileId;
    /* 0x10 */ s16 mode;
    /* 0x12 */ u8 arg;
    u8 _pad13[0x01];
    /* 0x14 */ Stg20Cell cell;
} Stg20PickRec; /* size 0x18 */

typedef struct {
    /* 0x00 */ s32 redraw;
    /* 0x04 */ s32 text;
    /* 0x08 */ s32 index;
    /* 0x0C */ Stg20PickRec recs[1];
} Stg20NavWork;

extern GfxTexSlot *Gfx_FindOrLoadTexSlot(s32);
extern Halves Gfx_NeutralRgb;
extern s32 Sys_PacketCursor;

extern s32 Stg20_LabRosterPanelIds[4];

extern Halves Stg20_LabSkillsCursorPos[];
extern s32 Stg20_LabSkillsColHideMasks[4];
extern s32 Stg20_LabSkillsArrowBlinkMasks[4];
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);

extern s32 Stg20_BodyDiagramParts[2][3];
extern void Stg20_CalcBeetleHideMasks(Actor *a);

extern s32 Stg20_UpgradeSlots[6];
extern s32 Stg20_CanUpgradePart(s32 item);

extern s32 Stg20_AreaIconHideMasks[];
extern s32 Stg20_AreaScreenPartsIds[];

extern Stg20Cell Stg20_ShopListTextPos[6];
extern s32 Stg20_CountOwnedItem(s32 id);

/* 0xBE-byte new-game block copied to Save_GameState+0x24 (Stg20_ApplyStartPreset). */
typedef struct {
    /* 0x00 */ u16 data[0x5F];
} Stg20StartBlock;

/* Save_GameState viewed with the start block at 0x24. */
typedef struct {
    u8 _pad00[0x24];
    /* 0x24 */ Stg20StartBlock start;
} Stg20GameInit;

extern Stg20StartBlock Stg20_StartPreset0;
extern Stg20StartBlock Stg20_StartPreset1;
extern u8 Stg20_PresetDigiNames[3][8];
extern void Digi_InitFromTable(s32, s32, DigiRosterEntry *);

extern s32 Item_GetCategory(s32 id);
extern s32 Item_GetBodyMask(s32 id);
extern void Stg20_InsertDescS16(s16 *list, s32 n, s32 v);

/* ActorModel viewed with the three tint bytes at 0x38 (Stg20_LabDigiModelUpdate). */
typedef struct {
    u8 _pad00[0x38];
    /* 0x38 */ u8 r;
    /* 0x39 */ u8 g;
    /* 0x3A */ u8 b;
} Stg20ModelTint;

extern s32 D_800709F4;
extern s32 Digi_GetModelFile(s32 id);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
extern void Cd_QueueFile(s32);
extern s32 Cd_GetFileState(s32 arg0);

/* Warp point: map cell, next game mode and field_24 value (Stg20_WarpPadUpdate). */
typedef struct {
    /* 0x00 */ Stg20Cell cell;
    /* 0x04 */ s32 nextMode;
    /* 0x08 */ s32 modeArg;
} Stg20Warp; /* size 0xC */

/* Task 7 creation args (Stg20_WarpPadUpdate). */
typedef struct {
    /* 0x00 */ s32 modelFileId;
    /* 0x04 */ s32 animFileId;
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 z;
    /* 0x14 */ s32 rotY;
    /* 0x18 */ s32 duration;
} Stg20WarpFx;

extern Stg20Warp Stg20_WarpPads[];
extern void Stg20_WalkerHalt(Actor *a);

extern u8 D_8005F794; /* Sys_State.field_24 low byte as a scalar reloc */
extern Stg20FileRec *Stg20_GetMapDest(s32 i);

/* Roster entry viewed with a signed word at 0x16 (Stg20_TestSpecialFlag). */
typedef struct {
    /* 0x00 */ u8 state;
    u8 _pad01[0x15];
    /* 0x16 */ s16 hp;
    u8 _pad18[0x44];
} Stg20RosterHp; /* size 0x5C */

/* Save_GameState viewed with the roster at 0xE4 as Stg20RosterHp (Stg20_TestSpecialFlag). */
typedef struct {
    u8 _pad00[0xE4];
    /* 0xE4 */ Stg20RosterHp elems[0x24];
} Stg20GameRoster;

extern u16 D_8005E64E; /* Save_GameState.field_2C[1] as a scalar reloc */
extern u8 D_8005E632;  /* Save_GameState byte 0x12 as a scalar reloc */
extern s32 D_8005F790; /* Sys_State.prevGameMode as a scalar reloc */
extern s32 Item_GetBagCapacity(void);
extern s32 Stg20_OwnsDigi(s32 id);

/* ---- added by p36 agent e ---- */
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern void Gfx_FadeOutToWhite(s32);
extern void Gfx_FadeInFromWhite(s32);
extern s32 Stg20_LabIsDna[];

extern void Digi_AddNew(s32);
extern u16 D_8005E66E; /* Save_GameState.field_66[4] as a scalar reloc */
extern u8 D_8005E631;  /* Save_GameState byte 0x11 as a scalar reloc */


/* Stg20_MenuState viewed from its field_8 (Stg20_ShopListUpdate addresses Stg20_MenuState.field_54 as 0x4C from it). */
typedef struct {
    /* 0x00 */ s32 result;
    u8 _pad04[0x44];
    /* 0x48 */ s32 menuChoice; /* = D_80070A00 (Stg20_BeetleShopMenuUpdate addresses result as -0x48 from it) */
    /* 0x4C */ s32 sellMode;
} Stg20MenuSub;
extern Stg20MenuSub D_800709B8;
extern s32 Skill_GetNameText(s32);
extern Halves Stg20_BeetleMenuPartsPos;
extern Halves Stg20_BeetleMenuUpgradePos;
extern s32 Pad_Triangle; /* Pad_State[0].triangle as a scalar reloc */
extern void Item_RemoveFromBag(s32 i);

/* Digimon info page work: 13 texts and the roster entry shown (Stg20_LabInfoUpdate). */
typedef struct {
    /* 0x00 */ s32 texts[13];
    u8 _pad34[0x28];
    /* 0x5C */ DigiRosterEntry *digi;
} Stg20InfoWork;

extern Stg20Cell Stg20_LabInfoTextPos[13];
extern u8 Stg20_DigivolveRuleTbl[4][4];
extern s32 D_800709D4;
extern s32 D_800709D8;
extern s32 Stg20_EvoTargetId;
extern s32 D_800709E4;
extern s32 Digi_GetSpecialty(s32);
extern s32 Digi_GetEvolutionTarget(s32 id, s32 val);

extern void Task_NextState3(Actor *);
extern void Task_NextState4(Actor *);
extern void Task_SetState2(Actor *, u32);
extern void Task_SetState3(Actor *, u32);
extern void Snd_StopById(s32);
extern u8 Digi_GetLearnedSkill(s32);

/* Roster entry viewed with signed HP/MP words and the byte at 0x46 (Stg20_LabDigivolve). */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x12];
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    u8 _pad1C[0x2A];
    /* 0x46 */ u8 field_46;
    u8 _pad47[0x15];
} Stg20DigiBoost; /* size 0x5C */

extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gfx_FadeSetBlack(void);
extern void Gfx_InitLights(void);
extern void Flag_SetTableFile(s32 arg0);
extern s32 Flag_FirstPassingEntry(void); /* main defines it void; its tail call leaves Flag_NextPassingEntry's result in v0 */
extern Blk12 *Flag_GetEntryPosList(s32 id);
extern s16 Flag_GetEntryDigiId(s32 id);
extern s16 Flag_GetEntryDir(s32 id);
extern s32 Flag_NextPassingEntry(void);
extern void Snd_UnloadSlot(s32 idx);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern void Mem_Zero(void *a0, s32 a1);
extern s32 Snd_AnySlotLoading(void);
extern s32 Menu_TopMenuResult;
extern s32 Pad_Circle; /* Pad_State[0].circle as a scalar reloc */

/* Work of the stage main task (Stg20_StageMain). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 bgmOn;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 areaSelect;
} Stg20MainWork;

/* 4-byte start position record at Stg20MapFile.field_8 (Stg20_StageMain). */
typedef struct {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
    /* 0x02 */ u16 dir;
} Stg20Start;

/* Byte pair of the 0xC-byte NPC block (Stg20_StageMain). */
typedef struct {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
} Stg20BytePair;

extern void Stg20_SnapToCell(Actor *a, s32 doX, s32 doZ);
extern void Stg20_SetMoveParams(Actor *a, s32 i);
extern s32 Stg20_IsOnCellCenter(Actor *a);
extern s32 Stg20_IsCellBlocked(Actor *a, s32 dir);
extern void Stg20_AddOccupantMark(Actor *a, Stg20Marks *m, s32 dir, s32 timer);
extern void Stg20_TickOccupantMarks(Actor *a, Stg20Marks *m);
extern void Stg20_WalkerSetAnim(Actor *a, s32 anim);
extern void Stg20_WalkerGetInput(Actor *a);
extern s32 Stg20_InputToDir(Actor *a);
extern void Stg20_WalkerFaceDir(Actor *a, s32 i);

extern s32 Flag_SelectBranch(s32 arg0);
extern void Text_OpenMsgClearChoice(void *arg0, s32 arg1);
extern s32 Text_IsFinished(s32 id);
extern s32 Flag_GetTableBase(void);
extern void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1);
extern s32 Actor_ApplyAxisMotion(ContC40 *a0, s32 i);

/* Work of the map walker/NPC model task (Stg20_WalkerUpdate). */
typedef struct {
    /* 0x00 */ s32 facing;
    /* 0x04 */ Stg20Cell blk[6];
    /* 0x1C */ s32 flagEntry;
    /* 0x20 */ s32 modelId;
    /* 0x24 */ s32 input;
    /* 0x28 */ s32 held;
    /* 0x2C */ s32 anim;
    /* 0x30 */ s32 dir;
    /* 0x34 */ Stg20Marks marks;
    /* 0x5C */ s32 wait;
    /* 0x60 */ s32 counter;
    /* 0x64 */ s32 visible;
    /* 0x68 */ Actor *target;
    /* 0x6C */ s32 text;
    /* 0x70 */ s32 timer;
} Stg20NpcWork;

extern s32 Pad_Cross; /* Pad_State[0].cross as a scalar reloc */
extern s32 Stg20_PartsPageCategory[10];
extern s32 Stg20_PartsPageSlot[10];

extern s32 Skill_GetRank(s32 id);
extern s32 Skill_GetPower(s32 id);
extern s32 Stg20_DnaNewSlot;

/* Roster entry as the jogress code builds and reads it (Stg20_LabDnaDigivolve). */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x0B];
    /* 0x0D */ u8 level;
    /* 0x0E */ u8 dp;
    /* 0x0F */ u8 maxLevel;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    /* 0x1C */ s16 attack;
    /* 0x1E */ s16 defense;
    /* 0x20 */ s16 speed;
    /* 0x22 */ u8 skills[12];
    /* 0x2E */ u8 learned[0x19];
    /* 0x47 */ u8 parent0;
    /* 0x48 */ u8 parent1;
    u8 _pad49[0x13];
} Stg20Digi; /* size 0x5C */

extern void Stg20_MsgWinShowDigiMsg(s32 text, s32 digi);

extern s32 D_800709E0;
extern Stg20Cell Stg20_LabSkillsTextPos[10];
extern void Stg20_LabSkillsSetText(Actor *a);

#endif
