#ifndef STAG3000_H
#define STAG3000_H

#include "common.h"
#include "main/156C.h"

/* STAG3000 (Ovl_FileIds id 4, gameMode 0x5xx). */

/* Actor viewed with its (main-header padded) word at 0x04: Stg30_FightMsgInit writes it. */
typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 partGroup;
    /* 0x08 */ s32 param;
    u8 _pad0C[0x04];
    /* 0x10 */ s32 stateLevel0;
    /* 0x14 */ s32 stateLevel1;
    /* 0x18 */ s32 stateLevel2;
    u8 _pad1C[0x08];
    /* 0x24 */ s32 frameCount;  /* word view of Actor.frameCount */
    /* 0x28 */ s32 elapsed;
    /* 0x2C */ ActorWork *work;
} Stg30TaskHead;

/* Work of task D_800732E8 (Stg30_FightMsgDraw): a word and a palette byte. */
typedef struct {
    /* 0x00 */ s32 scale;
    /* 0x04 */ s32 palette;
} Stg30FightMsgWork; /* size 0x8 */

/* 0x28-byte parts record as Stg30_FightMsgDraw writes it (GfxPart shape plus 0x0E/0x10). */
typedef struct {
    /* 0x00 */ s32 fileId;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    u8 _pad08[0x04];
    /* 0x0C */ u8 palette;
    u8 _pad0D[0x01];
    /* 0x0E */ u8 unscaled;
    /* 0x0F */ u8 visible;
    /* 0x10 */ s32 scaleX;
    /* 0x14 */ s32 scaleY;
    u8 _pad18[0x04];
    /* 0x1C */ s32 groupMask;
    u8 _pad20[0x04];
    /* 0x24 */ s16 rotZ;
    u8 _pad26[0x02];
} Stg30Part; /* size 0x28 */

/* Work of task D_80073040 (init Stg30_ActionLoadInit) and D_800730D0 (init Stg30_ItemMenuInit). */
typedef struct {
    /* 0x00 */ s32 field_0;
} Stg30WorkWord;

/* Work of task D_80073040 (Stg30_ActionLoadUpdate, Stg30_ActionLoadAddSorted, Stg30_ActionLoadDestroy): two
   (file, lba) lists kept sorted by lba, plus a list of files to free. */
typedef struct {
    /* 0x000 */ s16 *script;  /* s16 command script (Stg30_ActionLoadUpdate) */
    /* 0x004 */ s32 loadTimer;
    /* 0x008 */ s32 files[60];
    /* 0x0F8 */ s32 lbas[60];
    /* 0x1E8 */ s32 keptFiles[30];
    /* 0x260 */ s32 tempFiles[30];
    /* 0x2D8 */ s32 count;
    /* 0x2DC */ s32 keptCount;
    /* 0x2E0 */ s32 tempCount;
    u8 _pad2E4[0x04];
    /* 0x2E8 */ s32 casterDigiId;
    /* 0x2EC */ s32 targetDigiIds[6];
    /* 0x304 */ s32 targetReactKinds[6];
    /* 0x31C */ s32 skillId;
    /* 0x320 */ s32 itemAction;
} Stg30ActionLoadWork; /* size 0x324 */

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
} Stg30RefView;

/* Work of task D_8007343C (camera, Stg30_CameraDraw). */
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
} Stg30CamWork; /* size 0x84 */

/* Work of task D_80073078 (destroy Stg30_CommandMenuDestroy). */
typedef struct {
    /* 0x00 */ s16 scale;
    u8 _pad02[0x02];
    /* 0x04 */ s32 text[4];
} Stg30Work73078; /* size 0x14 */

/* Work of task D_800732B8 (Stg30_FighterDestroy, Stg30_FighterSetVisible, Stg30_FighterQueueHomeReset, Stg30_FighterSetAnim). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 homeX;
    /* 0x08 */ s32 homeY;
    /* 0x0C */ s32 homeZ;
    /* 0x10 */ s32 facing;
    /* 0x14 */ s32 modelFile;
    /* 0x18 */ s32 drawTex;
    /* 0x1C */ s32 drawWire;
    /* 0x20 */ CVECTOR color;
    /* 0x24 */ s32 lastHudFlag;
    /* 0x28 */ s32 visible;
    /* 0x2C */ s32 skillId;
    /* 0x30 */ s32 homeResetTimer;
    /* 0x34 */ s32 anim;
    /* 0x38 */ s32 startDowned;
} Stg30FighterWork; /* size 0x3C */

/* Work of task D_80073358 (Stg30_InterruptSelectTask, Stg30_InterruptSelectDraw). */
typedef struct {
    /* 0x00 */ s16 scaleX;
    /* 0x02 */ s16 scaleY;
    /* 0x04 */ u8 palette;
    u8 _pad05[0x03];
    /* 0x08 */ u8 cursorPalette;
    u8 _pad09[0x03];
    /* 0x0C */ s32 choice;
    /* 0x10 */ s32 slot;
} Stg30InterruptSelectWork; /* size 0x14 */

/* Stg30InterruptSelectWork with the words at 0x04 / 0x08 as Stg30_InterruptSelectTask writes them. */
typedef struct {
    /* 0x00 */ s16 scaleX;
    /* 0x02 */ s16 scaleY;
    /* 0x04 */ s32 palette;
    /* 0x08 */ s32 cursorPalette;
    /* 0x0C */ s32 choice;
    /* 0x10 */ s32 slot;
} Stg30Work73358W; /* size 0x14 */

/* Work of task D_800733F0 (CD streaming, Stg30_XaPlayTask), as read after the
   Stg30_XaPlayInit Vec3 init: file id, channel byte, 1-based track index, lba range. */
typedef struct {
    /* 0x00 */ s32 file;
    /* 0x04 */ u8 channel;
    u8 _pad05[0x03];
    /* 0x08 */ s32 track;
    /* 0x0C */ s32 start;
    /* 0x10 */ s32 end;
} Stg30CdWork; /* size 0x14 */

/* Work of tasks D_80073328 (init Stg30_PopupInit) and D_800733F0 (init Stg30_XaPlayInit). */
typedef struct {
    /* 0x00 */ Vec3 pos;
    /* 0x0C */ s32 scale;
    /* 0x10 */ s32 palette;
} Stg30WorkVec3; /* size 0x14 */

/* Init arg of task D_800734F8: a pointer whose field_8 is copied to Actor.field_8. */
typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ s32 param;
} Stg30Ref;

/* Work of task D_800734F8 (Stg30_FighterHudInit, Stg30_FighterHudDestroy). */
typedef struct {
    /* 0x00 */ Stg30Ref *ref;
    /* 0x04 */ s16 openScale;
    u8 _pad06[0x02];
    /* 0x08 */ s32 labelSlide;
    /* 0x0C */ s32 text[2];
} Stg30FighterHudWork;

/* Two-word init arg of task D_80073718. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Stg30Pair;

/* Work of task D_80073718 (Stg30_ResultInit, Stg30_ResultDestroy). */
typedef struct {
    /* 0x00 */ Stg30Pair pair;
    /* 0x08 */ u8 buf0[8];
    /* 0x10 */ u8 buf1[8];
    /* 0x18 */ s32 expToNext[3];
    /* 0x24 */ s32 text[14];
} Stg30ResultWork;

/* Work of task D_800737C8 (Stg30_JoinPromptInit, Stg30_JoinPromptDraw). */
typedef struct {
    /* 0x00 */ s32 index;
    /* 0x04 */ s32 text[2];
    /* 0x0C */ Actor *fighter;
    /* 0x10 */ s32 windowVisible;
} Stg30JoinPromptWork;


/* 0x12-byte record of Stg30_Battle.field_240 (arg2 of Stg30_AiCanUseAction): byte lists
   indexed by the same slot i at 0x02, 0x05, 0x09 and 0x0D. */
typedef struct {
    /* 0x00 */ s16 bits;
    /* 0x02 */ u8 skillIds[3];
    /* 0x05 */ u8 conditions[4];
    /* 0x09 */ u8 actionKinds[4];
    /* 0x0D */ u8 targetModes[4];
    u8 _pad11[0x01];
} Stg30EnemyAi; /* size 0x12 */

/* 16-byte record of the Stg30_Battle.field_2AC array. */
typedef struct {
    /* 0x00 */ s32 turnType;
    /* 0x04 */ s16 target;
    /* 0x06 */ s16 skillId;
    /* 0x08 */ s16 effectKind;
    u8 _pad0A[0x02];
    /* 0x0C */ s16 hpDelta;  /* hp delta of the last hit */
    /* 0x0E */ u8 noCounter;
    /* 0x0F */ u8 noInterrupt;
} Stg30Turn;

/* Stg30_Battle: overlay state block (Stg30_InitBattle clears 0x3E0 bytes from here). */
typedef struct {
    /* 0x000 */ s32 fromCity;
    /* 0x004 */ s32 escapeResult;
    /* 0x008 */ s32 inputSlot;
    /* 0x00C */ s32 chosenTarget;
    /* 0x010 */ s32 menuChoice;
    /* 0x014 */ s32 cancelled;
    /* 0x018 */ DigiRosterEntry digis[6];  /* 0..2 the tamer's party (copies of Save_GameState.elems), 3..5 enemies */
    /* 0x240 */ Stg30EnemyAi enemyAi[6];
    /* 0x2AC */ Stg30Turn turns[7];
    /* 0x31C */ s32 statusFlags[6];
    /* 0x334 */ u8 killBuildup[6];
    u8 _pad33A[0x06];
    /* 0x340 */ u8 debuffed[6];
    /* 0x346 */ u8 buffed[6];
    /* 0x34C */ u8 leveledUp[3];
    /* 0x34F */ u8 preventFlags[6];  /* per-slot flag bytes (4 = no status recovery) */
    u8 _pad355[0x01];
    /* 0x356 */ s16 attackCur[6];
    /* 0x362 */ s16 defenseCur[6];
    /* 0x36E */ s16 speedCur[6];
    /* 0x37A */ s16 attackBase[6];
    /* 0x386 */ s16 defenseBase[6];
    /* 0x392 */ s16 speedBase[6];
    /* 0x39E */ s16 powerBuff[6];
    u8 _pad3AA[0x02];
    /* 0x3AC */ s32 itemId;
    /* 0x3B0 */ s16 statusMsg;
    /* 0x3B2 */ s16 itemColumn;
    /* 0x3B4 */ s16 actionTaken;
    u8 _pad3B6[0x02];
    /* 0x3B8 */ s32 lastTargets[6];
    /* 0x3D0 */ s32 interruptSlot;
    /* 0x3D4 */ s32 interruptActive;
    /* 0x3D8 */ s32 joinCandidate;
    /* 0x3DC */ s32 isBossFight;
} Stg30Battle; /* size 0x3E0 */

/* arg0 of Stg30_ShowAllFighters / Stg30_ResetAllFightersHome / Stg30_ShowPartyFighters: a pointer at 0x34 to a
   six-actor list at 0x2C. */
typedef struct {
    /* 0x00 */ s32 textBoxTask;
    u8 _pad04[0x08];
    /* 0x0C */ s32 commandTask;
    /* 0x10 */ s32 cameraTask;
    /* 0x14 */ s32 fightBgTask;
    u8 _pad18[0x0C];
    /* 0x24 */ s32 bannerTask;
    /* 0x28 */ s32 resultTask;
    /* 0x2C */ PTR32(Actor) actors[6]; /* 32-bit task slots */
    u8 _pad44[0x04];
    /* 0x48 */ s32 scriptTask;
} Stg30BattleChildren;

/* Same object as an Actor (state words at 0x18/0x1C). */
typedef struct {
    u8 _pad00[0x18];
    /* 0x18 */ s32 stateLevel2;
    /* 0x1C */ s32 stateLevel3;
    u8 _pad20[NATIVE_OFS(Actor, u34, 0x34) - 0x20];
    /* 0x34 */ Stg30BattleChildren *list;
} Stg30ListOwner;

/* Work of task D_800737A0 (init Stg30_SkillLearnInit, Stg30_SkillLearnCompact). */
typedef struct {
    /* 0x00 */ s32 slot;
    /* 0x04 */ s32 labelTexts[4];
    /* 0x14 */ s32 texts[20];
    /* 0x64 */ s32 text[3];
    /* 0x70 */ s32 descText;
    /* 0x74 */ s16 skillLists[2][12];
    /* 0xA4 */ s32 column;
    /* 0xA8 */ s32 cursorRow[2];
    /* 0xB0 */ s32 scroll[2];
    /* 0xB8 */ s32 count[2];
    /* 0xC0 */ s32 mpCost;
    /* 0xC4 */ s32 buttonIndex;
    /* 0xC8 */ s32 buttonRowActive;
} Stg30SkillLearnWork; /* size 0xCC */

/* Work of task D_800730D0 (init Stg30_ItemMenuInit; Stg30_ItemMenuBuildLists fills three id lists). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 titleText;  /* first of 14 text words cleared by Stg30_ItemMenuUpdate */
    /* 0x08 */ s32 descText;
    /* 0x0C */ s32 columnTitles[3];
    /* 0x18 */ s32 texts[3][3];
    /* 0x3C */ s32 openScale;
    /* 0x40 */ s32 columnEnabled[3];
    /* 0x4C */ s32 columnBroken[3];
    /* 0x58 */ u8 itemLists[3][0x30];
    /* 0xE8 */ s32 itemCounts[3];
    /* 0xF4 */ s32 shownItem;
} Stg30ItemMenuWork; /* size 0xF8 */

/* Work of task D_80073138 (update Stg30_SkillMenuUpdate -> Stg30_SkillMenuRefreshText). */
typedef struct {
    /* 0x00 */ s32 texts[18]; /* [5] is the description text, [6 + row * 3 + col] the grid */
    /* 0x48 */ s32 shownSkill;
    /* 0x4C */ s16 openScale;
    u8 _pad4E[0x02];
    /* 0x50 */ s32 mpCost;
} Stg30SkillMenuWork; /* size 0x54 */

/* 0x1B-byte records of Stg30_SkillMenuLists (Stg30_SkillMenuRefreshText). */
typedef struct {
    /* 0x00 */ u8 disabled[0x0D];
    /* 0x0D */ u8 skillIds[0x0E];
} Stg30SkillList;

/* Init arg of task D_800737A0. */
typedef struct {
    /* 0x00 */ s32 slot;
    /* 0x04 */ s16 skillIds[12];
} Stg30SkillLearnArgs;

/* Two s16 passed by value to Stg30_OpenItemText / Stg30_OpenSkillText (Text_Open x/y). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Stg30XY;





/* Stg30_FighterStateBackup: saved copy of the Stg30_Battle roster (Stg30_SaveFighterStates / Stg30_RestoreFighterStates). */
typedef struct {
    /* 0x000 */ DigiRosterEntry digis[6];
    /* 0x228 */ s32 statusFlags[6];
    /* 0x240 */ u8 debuffed[6];
    /* 0x246 */ u8 buffed[6];
    /* 0x24C */ s16 attackCur[6];
    /* 0x258 */ s16 defenseCur[6];
    /* 0x264 */ s16 speedCur[6];
} Stg30FighterBackup; /* size 0x270 */

/* Seven target words Stg30_CamEaseToward eases a Stg30CamWork camera toward. */
typedef struct {
    /* 0x00 */ s32 rotY;
    /* 0x04 */ s32 vpx;
    /* 0x08 */ s32 vpy;
    /* 0x0C */ s32 vpz;
    /* 0x10 */ s32 vry;
    /* 0x14 */ s32 originX;
    /* 0x18 */ s32 originZ;
} Stg30CamGoal;

/* Init arg of task 7 as Stg30_SpawnSkillHitFx builds it on the stack. */
typedef struct {
    /* 0x00 */ s32 modelFile;
    /* 0x04 */ s32 animFile;
    /* 0x08 */ s32 posX;
    /* 0x0C */ s32 posY;
    /* 0x10 */ s32 posZ;
    /* 0x14 */ s32 facing;
    /* 0x18 */ s32 duration;
} Stg30SpawnArgs;

/* Work of task D_80073170 (update Stg30_TargetSelectUpdate, draw Stg30_TargetSelectDraw). */
typedef struct {
    /* 0x00 */ s32 highlightDone;
    /* 0x04 */ s32 target;
    /* 0x08 */ s32 targetMode;
    /* 0x0C */ s32 firstSlot;
    /* 0x10 */ s32 lastSlot;
    /* 0x14 */ s32 effectKind;
    /* 0x18 */ s32 skillId;
    /* 0x1C */ s32 team;
} Stg30TargetSelectWork; /* size 0x20 */

/* Actor.u38 transform viewed with the vertical speed words. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 posX;
    /* 0x34 */ s32 posY;
    /* 0x38 */ s32 posZ;
    u8 _pad3C[0x0C];
    /* 0x48 */ s32 moveDeltaX;
    /* 0x4C */ s32 moveDeltaY;
    /* 0x50 */ s32 moveDeltaZ;
} Stg30Xform;

/* ActorModel viewed with the three tint bytes at 0x38..0x3A (Stg30_FighterTask). */
typedef struct {
    u8 _pad00[NATIVE_OFS(ActorModel, clutRow, 0x34)];
    /* 0x34 */ s16 clutRow;
    /* 0x36 */ s16 tpageBits;
    /* 0x38 */ u8 flatR;
    /* 0x39 */ u8 flatG;
    /* 0x3A */ u8 flatB;
    u8 _pad3B[0x01];
    /* 0x3C */ s32 otIndex;
    u8 _pad40[NATIVE_OFS(ActorModel, animId, 0x54) - NATIVE_OFS(ActorModel, otzShift, 0x40)];
    /* 0x54 */ s32 animId;
    u8 _pad58[0x08];
    /* 0x60 */ s32 animDone;
} Stg30ModelTint;

extern Elem12 Stg30_HitReactHop1Motion;
extern Elem12 Stg30_HitReactHop2Motion;
extern Elem12 Stg30_HitReactPushMotion;
extern void Task_NextState4(Actor *arg0);
extern void Actor_StopAxisMotion(Ctx38 *arg0, s32 arg1);
extern void Actor_SetAxisMotion(Ctx38 *arg0, s32 arg1, Elem12 *arg2);
extern s32 Actor_ApplyAxisMotion(ContC40 *a0, s32 i);
extern s32 Actor_ApplyAxisMotionRev(ContC40 *a0, s32 i);
extern s32 Anim_HasModelAnim(Actor *a0, s32 n);
extern void Stg30_FighterSetAnim(Actor *a0, s32 anim);
extern void Stg30_PlayHitReactSound(Actor *a0);

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

/* 8-byte text layout records of Stg30_ResultTextLayout (Stg30_ResultUpdate). */
typedef struct {
    /* 0x00 */ u8 slot;
    /* 0x01 */ u8 src;
    /* 0x02 */ u8 color;
    /* 0x03 */ u8 bigFont;
    /* 0x04 */ Stg30XY pos;
} Stg30TextRec;

extern Stg30TextRec Stg30_ResultTextLayout[];
extern s32 Digi_GetExpToNextLevel(s32, s32, s32);
extern u8 *Stg30_NumToDigits(u8 *out, s32 n);
extern void Stg30_LevelUpStats(DigiRosterEntry *);



/* Stg30_BattleDigis viewed as the battle block from 0x18 of Stg30_Battle: the roster
   then the status words (Stg30_Battle.field_31C) at 0x304. The stat arrays after
   it keep their Stg30_Battle names (Stg30_ApplySkillDamage uses this view in one block,
   where retail relocates against a separate symbol, not Stg30_Battle). */
typedef struct {
    /* 0x000 */ DigiRosterEntry digis[6];
    u8 _pad228[0xDC];
    /* 0x304 */ s32 status[6];
    u8 _pad31C[0x0C];
    /* 0x328 */ u8 debuffed[6];   /* Stg30_Battle.debuffed */
    u8 _pad32E[0x10];
    /* 0x33E */ s16 attackCur[6];  /* Stg30_Battle.attackCur */
    /* 0x34A */ s16 defenseCur[6];  /* Stg30_Battle.defenseCur */
    u8 _pad356[0x0C];
    /* 0x362 */ s16 attackBase[6];  /* Stg30_Battle.attackBase */
    /* 0x36E */ s16 defenseBase[6];  /* Stg30_Battle.defenseBase */
} Stg30CombatCD8;


/* Stg30_BattleDigis battle block: roster, then the byte lists and Sub10 records. */
typedef struct {
    /* 0x000 */ DigiRosterEntry digis[6];
    /* 0x228 */ Stg30EnemyAi lists[6];
    /* 0x294 */ Stg30Turn sub[7];
} Stg30SlotBlk;

#ifdef DW2_NATIVE
/* DATA_LABEL alias (battlestate.c) as a field access. */
#define Stg30_BattleDigis (Stg30_Battle.digis)
#else
extern DigiRosterEntry Stg30_BattleDigis[];
#endif
extern s32 Stg30_FighterHudParts[];
extern s32 Stg30_StatusIconGroups[];
extern s32 Stg30_StatusIconFlags[];
extern Stg30XY Stg30_StatusIconPos[];
extern void Stg30_SetGaugeParts(Stg30Part *p, s32 unit, s32 num, s32 den);

extern s32 Stg30_SkillMenuArrowBlinkMasks[];
extern Stg30XY Stg30_SkillMenuCursorPos[];
extern s32 Stg30_SkillMenuColHideMasks[];

extern s32 Stg30_TargetCursorMasks[];
extern s32 Stg30_TargetAllEnemiesMask;
extern s32 Stg30_TargetAllAlliesMask;
extern s32 func_8001F0E4(s32 id);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern u8 func_8001F020(s32 id);  /* u8 in the main exe; used unmasked here */
#else
extern s32 func_8001F020(s32 id);  /* u8 in the main exe; used unmasked here */
#endif
/* Stg30_BattleDigiNames: Stg30_Battle.digis[i].name (0x64 = 0x18 + 0x4C). */
typedef struct {
    /* 0x00 */ u8 name[14];
    u8 _pad0E[0x4E];
} Stg30Name5C; /* size 0x5C */
#ifdef DW2_NATIVE
/* DATA_LABEL alias (battlestate.c): [i].name is Stg30_Battle.digis[i].name. */
#define Stg30_BattleDigiNames ((Stg30Name5C *)Stg30_Battle.digis[0].name)
#else
extern Stg30Name5C Stg30_BattleDigiNames[];
#endif
extern s32 Stg30_FighterHudFadeDelay[];
extern Stg30XY Stg30_FighterHudNamePos[];
extern u8 Stg30_OrderLabelMsgs[];
extern Halves Stg30_OrderLabelPos[];
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);

extern u8 Stg30_CursorBlinkPalettes[];
extern s32 Stg30_ResultParts[];
extern Stg30XY Stg30_ItemListTextPos[];
extern const Stg30XY Stg30_ItemDescTextPos;
extern Stg30XY Stg30_SkillListTextPos[];
extern const Stg30XY Stg30_SkillDescTextPos;
extern s32 Stg30_InterruptCursorMasks[];
extern s32 Stg30_XaTrackStart[];
extern s32 Stg30_XaTrackLength[];
extern s32 Stg30_PopupItemMasks[];
extern s32 Stg30_PopupNumMasks[];
extern s32 Stg30_PopupNumParts[];
extern s32 Stg30_BannerParts[];
extern Halves Stg30_SkillLearnTextPos[];
extern DungState Dung_State;
extern s16 Stg30_CloseUpRotY[];  /* camera goal x per party slot (Stg30_CameraUpdate) */
extern s16 Stg30_CloseUpVpz[];  /* camera goal tables indexed by digimon height step */
extern s16 Stg30_CloseUpVry[];
extern s32 Stg30_FightBgModels[];
extern s32 Stg30_SpecialFightBgModel;
extern s32 Stg30_FightBgByFloorElem[];
extern s32 Stg30_FightMsgParts[];
extern SysState Sys_State;
extern GameState Save_GameState;
extern s32 Gfx_ZeroVector[];

/* main exe */
extern void Task_DefaultDestroy(Actor *);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdControlF(s32, u8 *);
#endif
extern void Anim_SetModelAnim(Actor *, s32);
extern s32 func_8001E8D0(s32 id);
extern s32 Skill_GetRank(s32 id);
extern void Snd_PlayById(s32, s32);
extern void Gfx_DrawParts(s32 arg0);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern TaskEntry *Task_FindFirst(s32, s32, s32);
extern void Task_SetState01(Actor *, u32, u32);
extern void Task_SetState1(Actor *, u32);
extern void Task_NextState0(Actor *);
extern void Digi_InitFromTable(s32, s32, DigiRosterEntry *);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 Skill_GetPower(s32 id);
#else
extern s32 Skill_GetPower(s32 id);
#endif
extern s32 Skill_GetCureFlags(s32 id);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern u8 Skill_GetMpCost(s32 id);
#else
extern s32 Skill_GetMpCost(s32 id);
#endif
extern void Cd_FreeFile(s32);
extern EntA0 *Cd_GetFileEntry(u32);
extern s32 Item_GetDescText(s32);
extern s32 Item_GetNameText(s32);
extern s32 Skill_GetDescText(s32);
extern s32 Skill_GetNameText(s32);
extern void Text_Open(void *, TextOpenArgs *);
extern void Mem_Zero(void *, s32);
extern s32 Flag_Test(s32);
extern void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
extern void Gfx_ResetModelBones(Actor *);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void RotMatrixYXZ(s16 *, Mat1F668 *);
extern void GsSetProjection(s32);
extern s32 GsSetRefView2(Stg30RefView *);
#endif
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
extern void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 func_8001E79C(s32 id);  /* s16 in the main exe; used unextended here */
#else
extern s32 func_8001E79C(s32 id);  /* s16 in the main exe; used unextended here */
#endif
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 Digi_GetHitFxOffsetY(s32 id);
#else
extern s32 Digi_GetHitFxOffsetY(s32 id);
#endif
extern s32 Skill_GetType(s32 id);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern void Digi_GetCastFxOffsets(s32 a0, void *a1);
extern s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi);
extern s32 Item_GetCategory(s32 id);
extern void Text_OpenPacked(void *, s32, u32, Halves);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern u16 Skill_GetSpecialty(s32 id);  /* u16 in the main exe; used unmasked here */
#else
extern s32 Skill_GetSpecialty(s32 id);  /* u16 in the main exe; used unmasked here */
#endif
extern s32 Digi_GetSpecialty(s32 id);
extern s32 Cd_GetFileLba(s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdControl(s32, u8 *, u8 *);
extern s32 CdControlB(s32, u8 *, u8 *);
extern u8 *CdIntToPos(s32, u8 *);
extern s32 CdSync(s32, u8 *);
extern s32 CdLastCom(void);  /* u8 in the main exe; compared unmasked here */
extern s32 CdPosToInt(u8 *);
#endif
extern s32 Skill_GetPartsEntry(s32 id);
extern s32 func_8001F044(s32 id);
extern s32 Rand_Next(void);

/* overlay */
extern void Stg30_FighterSetVisible(Actor *a0, s32 a1);
extern void Stg30_FighterQueueHomeReset(Actor *a0);
extern void Stg30_BuildSkillScript(s32);
extern void Stg30_BuildGuardScript(s32);
extern s32 Stg30_CamEaseStep(s32 a, s32 b);
extern void Stg30_SetCameraShot(u8 state);
extern s32 Stg30_AiCheckCondition(s32, s32);
extern s32 Stg30_PickTarget(s32, s32, s32);
extern s32 Stg30_GetSkillEffectKind(s32 id);
extern s32 Stg30_TurnOrderGet(s32 i);
extern void Stg30_OpenItemText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
extern void Stg30_OpenSkillText(void *a0, s32 id, s32 color, Stg30XY pos, s32 name, s32 delay);
extern void Stg30_ShowPartyFighters(Stg30ListOwner *a0);

/* part 36 salvage */
extern s32 Skill_GetTarget(s32 id);
extern void Stg30_TurnOrderClear(void);
extern void Stg30_TurnOrderInsert(s32 idx, s32 v);
extern void Stg30_TurnOrderRemove(s32 i);
extern s32 Stg30_TurnOrderFind(s32 v);
extern s32 Stg30_TurnOrderFreeIndex(void);
extern s32 Stg30_StatusWearOff4Masks[];
extern u16 Stg30_StatusWearOff4Labels[];
extern s32 Stg30_StatusWearOff3Masks[];
extern u16 Stg30_StatusWearOff3Labels[];
extern s32 Skill_GetCastAnim(s32 id);
extern u16 Stg30_HpMpGrowth[6][3][4];
extern u16 Stg30_AtkDefGrowth[5][3][4];
extern u16 Stg30_SpeedGrowth[5][3][4];
extern s32 Digi_GetRank(s32 id);
extern s32 Digi_GetStatGrowth(s32 id, s32 k);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern u8 Digi_GetType(s32 id);
#else
extern s32 Digi_GetType(s32 id);
#endif
extern PadState Pad_State[];
extern const Halves Stg30_SkillMenuTitlePos;
extern Halves Stg30_SkillColumnLabelPos[];
extern void Stg30_SkillMenuRefreshText(Actor *a0);
extern void Stg30_ItemMenuRefreshText(Actor *a0);
extern s32 Stg30_TargetFirst(s32 team, s32 flag, s32 mode);
extern s32 Stg30_TargetPrev(s32 team, s32 cur, s32 flag, s32 mode);
extern s32 Stg30_TargetNext(s32 team, s32 cur, s32 flag, s32 mode);
extern s32 Stg30_ItemToSkillId(s32 c);
extern const Halves Stg30_ItemMenuTitlePos;
extern Halves Stg30_ItemColumnLabelPos[];
extern s32 Stg30_ItemMenuArrowBlinkMasks[];
extern s32 Stg30_ItemMenuColHideMasks[];
extern Stg30XY Stg30_ItemMenuCursorPos[];
extern void Stg30_SkillLearnRefreshList(Actor *a0);
extern void Stg30_SkillLearnRefreshButtons(Actor *a0);
extern void Stg30_SkillLearnCompact(Actor *a0, s32 row);
extern s32 Stg30_CalcCannonDamage(s32 idx, s32 id, s32 lvl);
extern s32 Skill_GetStatusFlags(s32 id);
extern s32 func_8001F10C(s32 id);
extern s32 Skill_GetBuffFlags(s32 id);
extern s32 func_8001F158(s32 id);
extern s32 Stg30_CompareTypes(s32 a, s32 b);
extern s32 Stg30_CompareSpecialty(s32 a, s32 b);
extern s32 Stg30_GetFloorSpecialty(void);
extern void Stg30_StatDebuff(s16 *max, s16 *b, s16 *c);
extern void Stg30_StatBuff(s16 *max, s16 *b, s16 *c);
extern s32 Stg30_ApplySkillStatus(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5);
extern s32 Stg30_CureStatusMasks[];
extern s16 Stg30_CureStatusLabels[];

extern const Halves Stg30_TamerNameTextPos;

extern Halves Stg30_JoinPromptTextPos[];
extern u8 Stg30_MemoryCapacity[];
extern DungState *Dung_StatePtr;
extern u8 *Digi_GetDefaultName(s32);
extern void Digi_SortRoster(void);
extern void Flag_Set(s32, s32);
extern TaskEntry *Task_FindNext(void);
extern void Stg30_JoinCreateDigi(Actor *a0, s32 a1);
extern void Task_SetState2(Actor *, u32);
extern void Stg30_DimFightersExcept(s32 sel, s32 from, s32 to);
extern void Stg30_UndimPartyFighters(void);
extern s16 Stg30_JoinChance[][3];
extern s32 Digi_GetAnimFile(s32 arg0, s32 arg1);
extern void Cd_QueueFile(s32);
extern s32 Cd_GetFileState(s32 arg0);
extern void Cd_QueueStag4000Files(void);
extern s32 Stg30_HasSkillOrNew(DigiRosterEntry *a0, s16 *a1, u8 id);
extern s32 Stg30_RankCanLearnSkill(s32 a0, u8 a1);
extern void Stg30_ActionLoadAddSorted(Actor *a0, s32 file, s32 lba);
extern s32 Item_GetBagCapacity(void);
extern void Item_SortList(void);
extern s32 Stg30_ApplyItemEffect(s32 target, s32 tech, s16 *p3, s16 *p4);

/* Work of the battle script runner (Stg30_BattleScriptTask): program counter into Stg30_BattleScript. */
typedef struct {
    /* 0x00 */ s16 *pc;
} Stg30WorkPc;

/* Child-task slots at Actor.u34 of the script runner (Task_Create completion words). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 interruptTask;
    /* 0x10 */ PTR32(Actor) actionLoadTask; /* 32-bit task slots */
    /* 0x14 */ PTR32(Actor) xaTask;
} Stg30Slots;

extern void Stg30_SetDigiAction(Actor *a0, s32 a1, s32 a2);
extern s32 *Skill_GetShotXa(s32 id);
extern void Task_SetState4(Actor *, u32);

/* Work of the battle main task D_800731A0 (update Stg30_BattleUpdate). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 counterQueued;
} Stg30BattleWork; /* size 0xC */

extern void Stg30_InitBattle(void);
extern void Snd_SetSlotContent(s32 idx, s32 v);
extern s32 Snd_AnySlotLoading(void);
extern void Cd_FreeUnlockedFiles(void);
extern void Gpu_AllocPacketBufs(s32 a0);
extern void Gfx_InitLights(void);
extern void Sys_SetFrameRate30(void);
extern void Gpu_SetBgClearColor(s32 a0, s32 a1, s32 a2);
extern void Gpu_ClearScreens(void);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Enemy_InitRosterEntry(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o);
extern void Enemy_GetSetSummary(void *a0, Out1DB68 *out);
extern void Stg30_ResetPartyStats(void);
extern void Task_SetState3(Actor *arg0, u32 arg1);
extern void Stg30_AiChooseEnemyTurns(void);
extern void Stg30_BuildTurnOrder(void);
extern s32 Stg30_UpdateTurnStatus(s32 idx);
extern void Stg30_SaveFighterStates(void);
extern void Stg30_RetargetAction(void);
extern s32 Stg30_PrepareAction(s32 idx);
extern void Stg30_RestoreFighterStates(void);
extern void Task_Destroy(s32 *arg0);
extern void Stg30_BattleLostUpdate(Stg30ListOwner *a0);
extern void Stg30_ResetAllFightersHome(Stg30ListOwner *a0);
extern void Stg30_ShowAllFighters(Stg30ListOwner *a0);
extern void Stg30_BuildItemScript(void);
extern void Stg30_BattleWonUpdate(Actor *a0);
extern s32 func_8001F180(s32 id);
extern s32 Stg30_ApplySkillDamage(s32 attacker, s32 target, s32 tech, s16 *p4, s16 *p5);
extern s32 Stg30_SkillHitCheck(s32 idx, s16 *tgt, s32 n, s32 id);
extern s32 Stg30_RepeatSkillCount;

/* Task descriptors (Stg30_TaskDescs rows). */
extern TaskDesc Stg30_BannerDesc;
extern TaskDesc Stg30_FightBgDesc;
extern TaskDesc Stg30_ActionLoadDesc;
extern TaskDesc Stg30_CommandInputDesc;
extern TaskDesc Stg30_CommandMenuDesc;
extern TaskDesc Stg30_ItemMenuDesc;
extern TaskDesc Stg30_SkillMenuDesc;
extern TaskDesc Stg30_TargetSelectDesc;
extern TaskDesc Stg30_BattleDesc;
extern TaskDesc Stg30_BattleScriptDesc;
extern TaskDesc Stg30_FighterDesc;
extern TaskDesc Stg30_FightMsgDesc;
extern TaskDesc Stg30_PopupDesc;
extern TaskDesc Stg30_InterruptSelectDesc;
extern TaskDesc Stg30_XaPlayDesc;
extern TaskDesc Stg30_CameraDesc;
extern TaskDesc Stg30_FighterHudDesc;
extern TaskDesc Stg30_ResultDesc;
extern TaskDesc Stg30_SkillLearnDesc;
extern TaskDesc Stg30_JoinPromptDesc;
extern TaskDesc *Stg30_TaskDescs[];

/* .bss of each unit, in retail order. STAG3000.PRO carries its .bss in the file, after all
 * .data. cc1 writes a unit's uninitialised globals in first-declaration order, so this list
 * sets the layout. D_ entries are unreferenced padding; three of them hold leftover non-zero
 * bytes in retail, which the build copies from the disc (configs/USA/image_bytes.txt). */
/* stag3000_100C.c */
extern s32 Stg30_CommandMenuCursor;
extern u8 D_800737E4[4];
extern s16 Stg30_ItemMenuColumn;
extern u8 D_800737EA[6];
extern s16 Stg30_ItemMenuRow[3];
extern u8 D_800737F6[2];
extern s16 Stg30_ItemMenuScroll[3];
extern u8 D_800737FE[2];
extern s16 Stg30_SkillMenuColumn;
extern u8 D_80073802[6];
extern s16 Stg30_SkillMenuRow[4];
extern s16 Stg30_SkillMenuScroll[4];
extern u8 D_80073818[8];
extern Stg30SkillList Stg30_SkillMenuLists[4];
extern u8 D_8007388C[4];
/* stag3000_6A88.c */
extern s16 Stg30_BattleScript[0xC8];
/* stag3000_AF5C.c */
extern s32 Stg30_TurnOrder[12];
extern Stg30FighterBackup Stg30_FighterStateBackup;
extern Stg30Battle Stg30_Battle;
/* stag3000_CC70.c */
extern s32 Stg30_CamShotVariant; /* random camera variant (0..3) */

#endif
