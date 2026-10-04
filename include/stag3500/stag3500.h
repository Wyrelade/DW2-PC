#ifndef STAG3500_H
#define STAG3500_H

#include "common.h"
#include "main/156C.h"

/* STAG3500 (Ovl_FileIds id 6, gameMode 0x7xx). */

/* Part-slide slot (Stg35_PartsStartSlideX sets, Stg35_PartsDraw steps): parts matching mask
   move by speed (8.8 fixed, accum carries the fraction) towards target. */
typedef struct {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 dir;
    /* 0x02 */ s16 target;
    /* 0x04 */ u16 accum;
    /* 0x06 */ s16 speed;
    /* 0x08 */ s32 mask;
} Stg35Slide;

/* File-load request: field_0 is a Cd file id (Stg35_PartsDraw passes it to Cd_GetFileEntry),
   field_4 the load mode (1 or 2, switched on by Stg35_PartsDraw), field_C the two
   part-slide slots (Stg35_TextSetColor writes the first word directly). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 mode;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ union {
        s32 field_C;
        Stg35Slide slide[2];
    } u;
} Stg35Load; /* size 0x24 (Stg35_PartsAlloc allocates 0x24) */

/* Handle whose first word points at a Stg35Load (Stg35_PartsDraw argument). */
typedef struct {
    /* 0x00 */ Stg35Load *load;
} Stg35LoadHandle;

/* Four-byte colour entries at 0x04 of Stg35Sprite. */
typedef struct {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ u8 code;
} Stg35Rgb;

/* Gouraud quad packet (PsyQ POLY_G4 shape) built by Stg35_RectDraw. */
typedef struct {
    /* 0x00 */ union {
        u32 word;
        struct {
            u8 _pad0[3];
            /* 0x03 */ u8 len;
        } b;
    } tag;
    /* 0x04 */ Stg35Rgb c0;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ Stg35Rgb c1;
    /* 0x10 */ s16 x1;
    /* 0x12 */ s16 y1;
    /* 0x14 */ Stg35Rgb c2;
    /* 0x18 */ s16 x2;
    /* 0x1A */ s16 y2;
    /* 0x1C */ Stg35Rgb c3;
    /* 0x20 */ s16 x3;
    /* 0x22 */ s16 y3;
} Stg35PolyG4; /* size 0x24 */

/* Draw-mode packet (PsyQ DR_MODE shape). */
typedef struct {
    /* 0x00 */ u32 tag;
    /* 0x04 */ u32 code[2];
} Stg35DrMode; /* size 0xC */

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Stg35Rgb field_4[4];
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
} Stg35Sprite;

typedef struct {
    /* 0x00 */ Stg35Sprite *sprite;
} Stg35SpriteHandle;

/* 0x1C-byte object allocated by Stg35_TextAlloc (field_0 = -1), closed by Text_Close. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg35TextObj;

typedef struct {
    /* 0x00 */ Stg35TextObj *text;
} Stg35TextHandle;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg35Vec3;

/* Actor.work of the stage tasks. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;          /* model file (Digi_GetModelFile) */
    /* 0x18 */ s32 field_18;          /* draw textured */
    /* 0x1C */ s32 field_1C;          /* draw wireframe */
    /* 0x20 */ CVECTOR field_20;      /* wireframe colour */
    u8 _pad24[0x04];
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
} Stg35Work;

/* Actor.work of the task at Stg35_XaPlayInit: a 12-byte vector at 0. */
typedef struct {
    /* 0x00 */ Stg35Vec3 field_0;
} Stg35VecWork;


/* Work of the task 0x708 read by Stg35_HudStartGauge .. Stg35_HudPeekGaugeLevel. */
typedef struct {
    /* 0x00 */ s32 field_0;           /* target */
    /* 0x04 */ s32 field_4;           /* shown value */
    /* 0x08 */ s32 field_8;           /* max */
} Stg35Work708Ent;

typedef struct {
    /* 0x00 */ Stg35LoadHandle load[3];
    /* 0x0C */ Stg35TextHandle text[7];
    /* 0x28 */ Stg35SpriteHandle sprite[10];
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54[2];
    /* 0x5C */ s32 field_5C[6];
    /* 0x74 */ s32 field_74;
    /* 0x78 */ s32 field_78;
    /* 0x7C */ s32 field_7C;
    /* 0x80 */ Stg35Work708Ent field_80[6];
} Stg35Work708;

/* Work with 3 load handles, 7 text handles and 10 sprite handles
   (Stg35_BattleHudDestroy destroy, Stg35_BattleHudDraw draw). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[3];
    /* 0x0C */ Stg35TextHandle text[7];
    /* 0x28 */ Stg35SpriteHandle sprite[10];
} Stg35Work3;

/* Work with 4 load handles and 7 text handles (Stg35_VsMenuDestroy destroy,
   Stg35_VsMenuDraw draw). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[4];
    /* 0x10 */ Stg35TextHandle text[7];
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    /* 0x3C */ s32 field_3C;
    /* 0x40 */ s32 field_40;
} Stg35Work4;

/* Work with 1 load handle and 14 text handles (Stg35_MatchupDestroy destroy). */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[1];
    /* 0x04 */ Stg35TextHandle text[14];
} Stg35Work1;

/* Sorted list work (Stg35_ActionLoadAddSorted inserts, Stg35_ActionLoadDestroy frees files).
   Stg35_ActionLoadUpdate fills it from the battle script: field_1E8/field_2DC and
   field_260/field_2E0 are the two file-id lists, field_8/field_F8 the
   (file id, LBA) list sorted by LBA. */
typedef struct {
    /* 0x000 */ s16 *field_0;         /* battle script */
    /* 0x004 */ s32 field_4;          /* wait timer */
    /* 0x008 */ s32 field_8[60];
    /* 0x0F8 */ s32 field_F8[60];
    /* 0x1E8 */ s32 field_1E8[30];
    /* 0x260 */ s32 field_260[30];
    /* 0x2D8 */ s32 field_2D8;
    /* 0x2DC */ s32 field_2DC;
    /* 0x2E0 */ s32 field_2E0;
    u8 _pad2E4[0x04];
    /* 0x2E8 */ s32 field_2E8;        /* player digi id */
    /* 0x2EC */ s32 field_2EC[6];     /* enemy digi ids */
    /* 0x304 */ s32 field_304[6];     /* enemy kinds */
    /* 0x31C */ s32 field_31C;
} Stg35ListWork;

/* Object holding six child actors at 0x2C (Stg35_ShowWinnerSide, Stg35_ShowAllDigi). */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ Actor *field_2C[6];
} Stg35ChildList;

typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ Stg35ChildList *field_34;
} Stg35ChildOwner;

/* 0x5C-byte battle copy of a party digimon (Stg35_Battle.rec[6], at 0x8006AA98);
   shares the leading fields of the main-exe DigiRosterEntry. */
typedef struct {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 digiId;
    u8 _pad02[0x0E];
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    u8 _pad1A[0x02];
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ u8 field_22[12];
    u8 _pad2E[0x1E];
    /* 0x4C */ u8 name[14];
    u8 _pad5A[0x02];
} Stg35Rec5C; /* size 0x5C */

/* Save_GameState (main GameState) viewed with the party slots as Stg35Rec5C. */
typedef struct {
    u8 _pad00[0xE4];
    /* 0xE4 */ Stg35Rec5C elems[0x24];
} Stg35GameState;

extern Stg35GameState Save_GameState;

/* 6-byte entries of the lists pointed to by Stg35_SkillGroups (end at field_0 == 0). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
} Stg35Rec6;

/* Per-party-slot pick table filled by Stg35_BuildCommandList. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ u8 field_C[6];
    /* 0x12 */ s16 field_12[6];
    /* 0x1E */ s16 field_1E[6];
    u8 _pad2A[0x02];
} Stg35Rec2C;

/* Stg35_Battle (Stg35_ClearBattle zeroes all 0x358 bytes). */
typedef struct {
    u8 _pad000[0x10];
    /* 0x010 */ Stg35Rec5C rec[6];
    /* 0x238 */ Stg35Rec2C field_238[6];
    /* 0x340 */ s32 field_340[6];
} Stg35Battle; /* size 0x358 */

/* Camera work (Stg35_CameraDraw), same layout as STAG0000 Stg00CameraWork. */
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
} Stg35CamWork;

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
} Stg35RefView;

/* 7-word argument block passed to Task_Create(7, ...) (Stg35_SpawnSkillHitFx, Stg35_SpawnSkillCastFx). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
} Stg35SpawnArgs;

/* One- and three-word Task_Create argument blocks. */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg35Arg1;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Stg35Arg3;

/* Actor.work of Stg35_RoundBannerTask: one load handle and a fade counter. */
typedef struct {
    /* 0x00 */ Stg35LoadHandle load[1];
    /* 0x04 */ s32 field_4;
} Stg35FadeWork;

/* Actor.work of the CD stream task Stg35_XaPlayTask. */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s32 channel;
    /* 0x08 */ s32 track;             /* 1-based index into Stg35_XaTrackStart/Stg35_XaTrackLength */
    /* 0x0C */ s32 start;             /* start sector */
    /* 0x10 */ s32 end;               /* end sector */
} Stg35CdWork;

/* Actor.u38 transform viewed with the position / vertical speed words. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x0C];
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
} Stg35Xform;

/* ActorModel viewed with the fade colour bytes at 0x38 (as STAG0000 Stg00ModelFade). */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s16 field_34;
    /* 0x36 */ s16 field_36;
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    /* 0x3A */ u8 field_3A;
} Stg35ModelFade;

/* Actor.work of the battle script runner Stg35_BattleScriptTask. */
typedef struct {
    /* 0x00 */ s16 *script;
} Stg35ScriptWork;

/* Actor.work of the battle main task Stg35_BattleUpdate. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;           /* turn count */
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;           /* winning side */
} Stg35BattleWork;

/* GfxPart with the fade fields Stg35_PartsDraw writes (0x0E, 0x14). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    u8 _pad8[4];
    /* 0x0C */ u8 palette;
    /* 0x0D */ u8 frame;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 visible;
    u8 _pad10[4];
    /* 0x14 */ s32 field_14;
    u8 _pad18[4];
    /* 0x1C */ s32 groupMask;
    u8 _pad20[8];
} Stg35Part; /* size 0x28 */

/* s16 screen position pairs (Stg35_MatchupLabelPos, Stg35_MatchupPartyPos, Stg35_MatchupTamerPos, Stg35_HpBarPosP1, Stg35_HpBarPosP2). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg35XY;

extern s32 Stg35_TurnOrder[];
extern Stg35Battle Stg35_Battle;
extern Stg35Rec6 D_8006A6DC[];
extern s32 Stg35_DefaultTargets[];
extern Stg35Rec6 *Stg35_SkillGroups[6];
extern s32 Gfx_ZeroVector[];

extern void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
extern void Gfx_ResetModelBones(Actor *);
extern void Task_SetState1(Actor *arg0, u32 arg1);
extern void Cd_FreeFile(s32 fileId);
extern void Text_Open(void *, TextOpenArgs *);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg35RefView *);
extern void Stg35_TextFree(Stg35TextHandle *arg0);
extern void Stg35_RectFree(Stg35SpriteHandle *arg0);
extern void Stg35_RectDraw(Stg35SpriteHandle *arg0);
extern void Stg35_FighterSetVisible(Actor *arg0, s32 arg1);
extern void Stg35_FighterQueueHomeReset(Actor *arg0);

extern void Text_Close(s32 *slot);
extern void Mem_Zero(void *a0, s32 a1);
extern void Task_DefaultDestroy(Actor *arg0);
extern void Stg35_PartsDraw(Stg35LoadHandle *arg0);
extern void Stg35_BuildSkillScript(s32 arg0);
extern s32 Mem_Alloc(s32, s32);
extern void Mem_Free(ActorWork *arg0);
extern s32 Skill_GetNameText(s32 arg0);
extern s32 func_8001E8D0(s32 id);
extern s32 CdControlF(s32, s32);
extern void Snd_PlayById(s32, s32);
extern void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter);
extern void Gfx_HidePartsByMask(GfxPartMaskView *, s32);
extern void Anim_SetModelAnim(Actor *, s32);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern void Task_NextState0(Actor *arg0);
extern TaskEntry *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2);
extern void Stg35_PartsAlloc(Stg35LoadHandle *arg0);
extern void Stg35_PartsFree(Stg35LoadHandle *arg0);
extern void Stg35_PartsSetFile(Stg35LoadHandle *arg0, s32 arg1);
extern void Stg35_PartsSetPalette(Stg35LoadHandle *arg0, s32 arg1, s32 arg2);
extern void Stg35_PartsHideByMask(Stg35LoadHandle *arg0, s32 arg1);
extern void Stg35_TextSetLayout(Stg35TextHandle *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void Stg35_TextSetColor(Stg35LoadHandle *arg0, s32 arg1);
extern void Stg35_TextSetSysMsg(Stg35TextHandle *arg0, s32 arg1);
extern void Stg35_TextSetSkillName(Stg35TextHandle *arg0, s32 arg1);
extern void Stg35_TextOpen(Stg35TextHandle *arg0);
extern s32 Stg35_CamEaseStep(s32 arg0, s32 arg1);
extern void Stg35_RectSetColor(Stg35SpriteHandle *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void Stg35_RectSetWidth(Stg35SpriteHandle *arg0, s32 arg1);
extern void Stg35_RectSetHeight(Stg35SpriteHandle *arg0, s32 arg1);
extern void Stg35_RectSetX(Stg35SpriteHandle *arg0, s32 arg1);
extern void Stg35_RectSetY(Stg35SpriteHandle *arg0, s32 arg1);
extern void Stg35_RectSetDrawMode(Stg35SpriteHandle *arg0, s32 arg1, s16 arg2, s16 arg3);
extern void Stg35_RectSetBounds(Stg35SpriteHandle *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern s32 Stg35_ScaleBarLen(s32 arg0, s32 arg1, s32 arg2);
extern s32 Stg35_ApplySkillDamage(s32 arg0, s32 arg1, s32 arg2);
extern void Stg35_FindSkillGroup(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
extern void Stg35_TextAlloc(Stg35TextHandle *arg0);
extern void Stg35_TextSetString(Stg35LoadHandle *arg0, s32 arg1);
extern void Stg35_TextClose(Stg35TextHandle *arg0);
extern void Stg35_RectAlloc(Stg35SpriteHandle *arg0);
extern void Stg35_TurnOrderClear(void);
extern void Stg35_TurnOrderInsert(s32 arg0, s32 arg1);
extern void Stg35_TurnOrderRemove(s32 arg0);
extern s32 Stg35_TurnOrderFreeIndex(void);
extern s32 Stg35_TurnOrderGet(s32 arg0);
extern void Stg35_BuildTurnOrder(void);
extern void Stg35_SetChosenAction(s32 arg0, s32 arg1);
extern void Stg35_PartsShowGroup(Stg35LoadHandle *arg0, s32 mask);
extern void Stg35_PartsHideGroup(Stg35LoadHandle *arg0, s32 mask);
extern void Stg35_PartsStartOpen(Stg35LoadHandle *arg0);
extern void Stg35_PartsStartScaleOut(Stg35LoadHandle *arg0);
extern void Stg35_PartsSetX(Stg35LoadHandle *arg0, s32 mask, s32 v);
extern void Stg35_PartsSetY(Stg35LoadHandle *arg0, s32 mask, s32 v);
extern void Stg35_PartsStartSlideX(Stg35LoadHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed);
extern void Stg35_PartsSetNumber(Stg35LoadHandle *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void Stg35_FighterSetAnim(Actor *arg0, s32 arg1);
extern void Stg35_SpawnSkillCastFx(Actor *arg0, s32 arg1);
extern void Stg35_SpawnSkillHitFx(Actor *arg0);
extern void Stg35_PlayHitReactSound(Actor *arg0);
extern void Stg35_HitReactUpdate(Actor *arg0, s32 arg1);
extern void Stg35_ClearBattle(void);
extern void Stg35_HudUpdateSkillList(Actor *arg0);
extern void Stg35_HudUpdateGaugeColumn(Actor *arg0, s32 arg1);
extern void Stg35_HudUpdateGaugeBar(Actor *arg0, s32 arg1);
extern void Stg35_HudStartGauge(s32 arg0, s32 *arg1);
extern s32 Stg35_HudGetGaugeStatus(void);
extern void Stg35_HudSyncHp(void);
extern s32 Stg35_HudGetGaugeLevel(void);
extern s32 Stg35_HudPeekGaugeLevel(s32 arg0);
extern s32 Stg35_PrepareAction(s32 arg0);
extern void Stg35_CamEaseToward(Stg35CamWork *arg0, s32 *arg1);
extern void Stg35_SetCameraShot(s32 arg0);
extern void Stg35_BuildCommandList(s32 arg0);
extern void Stg35_ActionLoadAddSorted(Actor *arg0, s32 arg1, s32 arg2);
extern void Stg35_SetDigiAction(Actor *arg0, s32 arg1, s32 arg2);
extern void Stg35_ShowWinnerSide(Stg35ChildOwner *arg0, s32 arg1);
extern void Stg35_ShowAllDigi(Stg35ChildOwner *arg0);

/* Main-exe functions, declared the way this overlay calls them. */
extern void Task_Create(u32 id, s32 *slot, s32 arg);
extern void Task_NextState1(Actor *arg0);
extern void Task_NextState2(Actor *arg0);
extern void Task_NextState3(Actor *arg0);
extern void Task_NextState4(Actor *arg0);
extern void Task_SetState0(Actor *arg0, u32 arg1);
extern void Task_SetState4(Actor *arg0, u32 arg1);
extern void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2);
extern TaskEntry *Task_FindNext(void);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Sys_SetFrameRate30(void);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Gfx_FadeOutToBlack(s32 arg0);
extern void Gfx_InitLights(void);
extern void Gfx_DrawParts(s32);
extern void Gfx_DrawWireModel(Actor *a0, s32 mode, CVECTOR *col);
extern void SetDrawMode(Stg35DrMode *p, s32 dfe, s32 dtd, s32 tpage, s32 tw);
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern void Anim_StepModelAnim(Actor *);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
extern s32 Anim_HasModelAnim(Actor *a0, s32 n);
extern void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1);
extern void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2);
extern s32 Digi_GetModelFile(s32 id);
extern u8 *Digi_GetDefaultName(s32);
extern s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);
extern s32 Rand_Next();
extern u8 *memset(u8 *s, s32 c, s32 n);
extern s32 Snd_AnySlotLoading(void);
extern void Snd_UnloadSlot(s32 idx);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern void Cd_FreeUnlockedFiles(void);
extern void Cd_QueueFile(s32);
extern s32 Cd_GetFileState(s32 arg0);
extern s32 Cd_GetFileLba(s32 arg0);
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(u8 com, u8 *param, u8 *result);
extern u8 *CdIntToPos(s32 i, u8 *p);
extern s32 CdPosToInt(void *);
extern s32 CdSync(s32 mode, u8 *result);    /* the main C stub is void(void) */
extern s32 CdLastCom(void);                 /* main: u8 */
extern s32 func_8001E79C(s32 id);           /* main: s16 */
extern s32 func_8001E7C0(s32 id);           /* main: s16 */
extern void Digi_GetCastFxOffsets(s32 a0, void *a1);
extern void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b);
extern s32 Skill_GetCastAnim(s32 id);
extern s32 Skill_GetPartsEntry(s32 id);
extern s32 *Skill_GetShotXa(s32 id);
extern s32 Skill_GetPower(s32 id);           /* main: s16 */
extern u16 Skill_GetSpecialty(s32 id);

extern SysState Sys_State;
extern PadState Pad_State[];
extern s16 D_80050780;

extern s32 Stg35_VsMenuPromptMsgs[];
extern s32 Stg35_VsMenuPhaseMasks[];
extern Stg35XY Stg35_MatchupLabelPos[];
extern s16 Stg35_MatchupLabelMsgs[];
extern Stg35XY Stg35_MatchupPartyPos[];
extern Stg35XY Stg35_MatchupTamerPos[];
extern s32 D_8006A540[];
extern Stg35Rec5C D_8006AA98[];
extern Elem12 Stg35_HitReactHop1Motion;
extern Elem12 Stg35_HitReactHop2Motion;
extern Elem12 Stg35_HitReactPushMotion;
extern s32 Stg35_XaTrackStart[];
extern s32 Stg35_XaTrackLength[];
extern Stg35XY Stg35_HpBarPosP1[];
extern Stg35XY Stg35_HpBarPosP2[];
extern s16 D_8006A690[];
extern s16 D_8006A69C[];
extern s16 D_8006A6B0[];
extern s16 Stg35_BattleScript[];              /* battle script buffer (bss) */
extern s32 Stg35_CamShotVariant;


/* rodata {1, 2, 0x10}: Stg35_RoundBannerTask copies it to the stack as a whole (the local's initializer) */
typedef struct {
    /* 0x0 */ s32 v[3];
} Stg35Masks;
extern Stg35Masks Stg35_RoundBannerMasks;

#endif
