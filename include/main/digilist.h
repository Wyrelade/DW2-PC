#ifndef MAIN_DIGILIST_H
#define MAIN_DIGILIST_H

#include "main/game.h"

/* Functions src/main/digilist.c defines. */
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 GsSetRefView2(GsRVIEW2 *);
extern void SsSetTableSize(void *, s16, s16);
extern void SsSetTickMode(s32);
extern void SsStart2();
extern void SsSetMVol(s16, s16);
extern void SsSetSerialAttr(s8, s8, s8);
extern void SsSetSerialVol(s8, s16, s16);
extern s16 SsUtSetReverbType(s16);
extern void SsUtSetReverbDepth(s16, s16);
extern void SsUtReverbOn();
#endif
extern s32 Mem_Alloc(s32, s32);
extern void Cd_ServiceQueue();
extern Obj6A8C0 *Stg20_FindWalkerByDigiId(s32);
extern void Stg20_WalkerWarpToCell(void *, s32 *);
extern s32 Stg20_WalkerIsPathDone(void *);
extern void Stg20_WalkerSetAnim(Obj6A8C0 *, s32);
extern void Stg40_TextObjCommand(s32 *);
#ifdef DW2_NATIVE /* the definition's return type: no caller reads unextended high bits */
extern s16 Stg40_IsTextObjCmdBusy(void);
#else
extern s32 Stg40_IsTextObjCmdBusy(void);
#endif
extern void Stg20_StartBgShake(void);
extern s32 Mem_Alloc(s32, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void ScaleMatrix(Obj209 *, s32 *);
extern void RotMatrixYXZ(void *, Obj209 *);
extern void ScaleMatrix(Obj209 *, s32 *);
#endif
void Menu_DigiTransferPlace(Actor *a0);
void Menu_DigiTransferPickSrc(Actor *a0);
void Menu_ConfirmMultiPick(Actor *a0);
void Menu_UndoLastPick(Actor *s0);
void Menu_UseItemOnDigi(Actor *a0);
void Menu_PickUseItemDirect(Actor *a0);
void Menu_ConfirmSinglePick(Actor *a0);
void Menu_BuildDigiList(MenuDigiListBuildWork *w);
void Menu_DigiListDrawRows(MenuDigiListRowsView *a0, s32 a1);
void Menu_SetDigiListMode(Actor *a, s16 mode);
void Menu_DigiListTask(Actor *a0);
void Menu_DigiListDraw(Actor *actor);

#endif /* MAIN_DIGILIST_H */
