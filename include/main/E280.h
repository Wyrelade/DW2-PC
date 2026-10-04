#ifndef MAIN_E280_H
#define MAIN_E280_H

#include "main/game.h"

/* Functions src/main/E280.c defines or declares, for the units after it. */
extern s32 Flag_TestConds();
extern void Flag_ApplySets();
extern void Mem_Zero(void *, s32);
u8 Digi_GetEvolutionTarget(s32 id, s32 val);
Ent1DB18 *Enemy_FindSetById(s32 id);
void Enemy_GetSetSummary(void *a0, Out1DB68 *out);
void Digi_InitFromTable(s32 a0, s32 a1, DigiRosterEntry *e);
void Enemy_InitRosterEntry(s32 a0, s32 a1, DigiRosterEntry *e, Out1DDA8 *o);
ItemTableEntry *Item_FindById();
s32 Item_GetNameText(s32 arg0);
s32 Item_GetDescText(s32 arg0);
s32 Item_GetCategory(s32 id);
s32 Item_GetLevel(s32);
s32 Item_CheckId(s32);
s32 func_8001E134(void);
s32 func_8001E158(void);
s32 Item_GetPrice(s32);
u8 Item_GetBodyMask(s32);
s32 Item_GetTableIndex(s32 id);
s32 Item_GetIdAtIndex(s32 a0);
void Flag_SetTableFile(s32 arg0);
Blk18 *Flag_GetEntryCondBlock(FlagEntryIdx *arg0);
Blk18 *Flag_GetBranchCondBlock(FlagEntryIdx *arg0, s32 arg1);
Blk18 *Flag_GetBranchSetBlock(FlagEntryIdx *arg0, s32 arg1);
s32 Flag_NextPassingEntry(void);
void Flag_FirstPassingEntry(void);
FlagBranchEntry *Flag_GetEntry();
s32 Flag_SelectBranch(s32 arg0);
s32 Flag_GetTableBase(void);
Blk12 *Flag_GetEntryPosList(s32);
s16 Flag_GetEntryDigiId(s32);
s16 Flag_GetEntryDir(s32);
s32 Digi_GetDataFileId(s32 arg0);
DigiData *Digi_FindDataById(s32 id);
s32 Digi_GetModelFile(s32 id);
s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
u8 *Digi_GetDefaultName(s32 id);
s16 func_8001E79C(s32 id);
s16 func_8001E7C0(s32 id);
void Digi_GetCastFxOffsets(s32 a0, void *a1);
s32 func_8001E8D0(s32 id);
u16 Digi_GetModelListId(s32 idx);
s32 Digi_GetModelListCount(void);
s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur);
s32 Digi_CalcMaxLevel(s32 x);
void func_8001EC00(Actor *arg0, s32 *arg1);
void func_8001EC10(Actor *arg0);
void func_8001ECE4(Actor *arg0);
EntED40 *Skill_FindById(s32 id);
s32 Skill_GetNameText(s32 arg0);
s32 Skill_GetDescText(s32 arg0);
s32 Skill_GetCastAnim(s32 id);
s32 Skill_GetType(s32 id);
s32 Skill_GetPartsEntry(s32 id);
u8 Skill_GetMpCost(s32 id);
void Skill_GetFxSet(s32 id, s32 n, s16 *a, s16 *b);
s32 Skill_GetTarget(s32 id);
s16 Skill_GetPower(s32 id);
u16 Skill_GetSpecialty(s32 id);
s32 *Skill_GetShotXa(s32 id);
u8 func_8001F020(s32 id);
s32 func_8001F044(s32 id);
s32 Skill_GetStatusFlags(s32 id);
s32 Skill_GetCureFlags(s32 id);
s32 Skill_GetRank(s32 id);
s32 func_8001F0E4(s32 id);
s32 func_8001F10C(s32 id);
s32 Skill_GetBuffFlags(s32 id);
s32 func_8001F158(s32 id);
s32 func_8001F180(s32 id);
void Anim_SetModelAnim(Actor *a, s32 n);
void Anim_SetModelAnimFile(Actor *arg0, s32 arg1, s32 arg2);
s32 Anim_HasModelAnim(Actor *a0, s32 n);
void Anim_StepModelAnim(Actor *a);
void Gfx_ResetModelBones(Actor *a0);
void Gfx_AddFlatQuad3D(GfxQuadColor *col, GfxQuadVert *v, s32 flags, s32 idx);
void Gfx_InitLights(void);
s32 Gfx_AnimAllowsBlink(s32 arg0);
void Gfx_AnimateModelTex(Actor *a0);

#endif /* MAIN_E280_H */
