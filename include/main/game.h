#ifndef MAIN_GAME_H
#define MAIN_GAME_H

/* Declarations shared by the main game translation units (src/main/*.c from
 * Task_Create on). */

#include "common.h"
#include "main/156C.h"

/* Small uninitialised globals (.sbss), in retail order. cc1 writes a unit's tentative
 * definitions (.comm) in first-declaration order, so this block sets their layout. Each
 * one is defined by the unit that reaches it with %gp_rel. */
extern s32 D_80050758; /* first .sbss word: crt0 clears from here to Ovl_LoadArea */
extern s32 Cd_PreloadCount;
extern u8 Bug_LastZappedLevel;
extern s32 Menu_TopMenuResult;
extern MenuCtx *Menu_Ctx;
extern u8 *Menu_PartGridSlots;
extern u8 *Menu_PartGridLabels;
extern s32 Snd_SavedId;
extern s32 Skill_ShotXaFile;
extern s32 Skill_ShotXaChannel;
extern s32 Sys_VsPartyConfirmed;
extern s32 Mem_HeapSize;
extern MemBlock *Mem_HeapHead;
extern s32 Sys_FlipPending;
extern s32 Rand_Index;
extern s32 D_80050794;

/* Uninitialised globals over the small-data size (.bss), in retail order, same rule. */
extern TaskList Task_List;
extern TaskFindFilter Task_FindFilter;
extern s32 Cd_PreloadIds[];
extern u8 Snd_SeqAttrTable[176 * 6 * 16];
extern SndSlot Snd_Slots[3];
extern TextStack Text_ReturnStack;
extern GpuOtBuf Gpu_OtBufs[];
extern s32 Gpu_OtLayoutMode[2];
extern GfxTexSlot Gfx_TexSlots[];
extern FlagEntryState Flag_EntryIter;
extern DungState Dung_State;
extern GameState Save_GameState;
extern Elm678 Pad_PortButtons[];
extern u8 Pad_RecvBufs[];
extern PadState Pad_State[];
extern SysState Sys_State;
extern CdCacheEntry Cd_FileCache[0x50];
extern u8 Cd_SectorHeader[];

extern CdCacheEntry Cd_FileCache[0x50];
extern SndSlot Snd_Slots[3];
extern s32 Cd_PollRead(void);
extern void Cd_LoadFileSync(s32);
extern u8 D_80048F12;
extern u8 D_8004E6E5;
extern u16 D_8004EAFA;
extern s32 D_800506B8;
extern u32 Card_TaskTop;
extern s32 Sys_VideoMode;
extern FlagEntryState Flag_EntryIter;
extern CardState D_80062F80;
extern u8 Pad_RecvBufs[];
extern Elm678 Pad_PortButtons[];
extern PadState Pad_State[];
extern u8 Beetle_PartDigiCapacity[];
extern GpuFuncTable *D_80048F08;
extern void (*D_80048F0C)(void *, ...);
extern u8 D_800102C0;
extern u8 D_80048F20[];
extern u8 D_80048F7C[];
extern TaskFindFilter Task_FindFilter;
extern s32 Cd_FileLba[];
extern SysState Sys_State;
extern ActorWork *Gpu_PrimBufs[];
extern GfxTexSlot Gfx_TexSlots[];
extern FadeState Gfx_FadeState;
extern u16 Rand_Table[];
extern s32 Cd_FileLba[];
extern u16 Cd_FileSectors[];
extern s32 *D_80049018;
extern s32 *D_8004901C;
extern s32 *D_80049020;
extern s32 *D_80049024;
extern u16 *Sys_IntrMaskPtr;
extern s32 D_80062FC4;
extern s32 Spu_InTransfer;
extern void (*Sys_VSyncCallbacks[])(void);
extern TextStack Text_ReturnStack;
extern TaskList Task_List;
extern GpuOtBuf Gpu_OtBufs[];
extern GameState Save_GameState;
extern s32 D_80062FD8;
extern void Digi_InitFromTable(s32, s32, DigiRosterEntry *);
extern void Digi_SortRoster(void);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern GpuOtBuf *ClearOTagR(GpuOtBuf *, s32);
#endif
extern void Snd_PlayById(s32, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 DrawOTag(void *);
#endif
extern s32 EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern s32 StartCARD(void);
extern void ChangeClearPAD(s32);
extern s32 Gfx_ReserveTexSlot(void);
extern s32 Mem_TryAlloc(s32, s32);
extern void Cd_EvictLruFile(void);
extern void Text_Close(s32 *);
extern void Mem_Free(ActorWork *);
extern ActorModel *Gfx_AttachModel(Actor *, s32);
extern void Gfx_ResetModelBones(Actor *);
extern s32 Gfx_ZeroVector[];
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern CdReadState Cd_ReadState;
extern u8 Cd_SectorHeader[];
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdPosToInt(void *);
extern s32 CdGetSector(void *, s32);
extern s32 CdReadyCallback(s32);
extern s32 CdControlF(s32, s32);
extern void *CdSyncCallback(void *);
#endif
extern void Cd_ReadSyncCallback();
extern void Anim_StepModelAnim(Actor *);
extern Blk16 Gfx_FlatLights[];
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 GsSetFlatLight(s32, Blk16 *);
extern void GsSetAmbient(s32, s32, s32);
extern void GsSetLightMode(s32);
#endif
#ifdef DW2_NATIVE
extern s32 func_8001E134(s32 itemId);
#else
extern s32 func_8001E134(void);
#endif
extern s32 *Item_GetEffectRec(s32);
extern s32 Text_WinFrameParts[];
extern void Gfx_SetPartsScale(GfxPartScaleView *, s32, s32);
extern void Gfx_DrawParts(s32);
extern void Text_Open(void *, TextOpenArgs *);
extern void Flag_Set(s32, s32);
extern void Gfx_SetPartsNumber(GfxPart *, s32, s32, s32);
extern s32 Digi_GetExpToNextLevel(s32, s32, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void RotMatrixYXZ(void *, Obj209 *);
extern void GsSetProjection(s32);
#endif
extern void Anim_SetModelAnim(Actor *, s32);
extern s32 D_8004E6D0;
extern s32 D_8004E6CC;
extern void *D_8004E6C8;
extern s32 _exeque();
extern void DMACallback();
extern SpuReverbAttr D_80062C18;
extern void SsUtSetReverbFeedback(s16);
extern void SsUtSetReverbDelay(s16);
extern SndSeqScore *Snd_SeqScores[];
extern s32 _SsReadDeltaValue(s16, s16);
extern s32 D_80060050;
extern s32 D_8006004C;
extern IrqRegs *D_8004FC68;
extern s32 D_8004FC70[];
extern int MemCardCallback(int);
extern IntrCallbackTable *D_8004FB80;
extern u8 D_8005FDD8[];
extern s32 *D_80049014;
extern s32 D_8004904C;
extern s32 D_80049050;
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 VSync(s32);
#endif
extern s32 D_80061B38;
extern s32 D_80061B3C;
extern void StClearRing();
extern s32 D_8004FDB8;
extern s32 D_8004FE44;
extern SioRegs *Pad_SioRegs;
extern MenuCtx *Menu_Ctx;
extern s32 sin_1(s32);
extern s32 CD_init();
extern s32 CD_initvol();
extern s32 _SsVabOpenHeadWithMode();
extern s32 func_80039A78();
extern s32 Snd_VabFixedAddrAlloc(s32, s32);
extern volatile s32 D_80063080;
extern void ChangeClearRCnt(s32, s32);
extern void SysDeqIntRP(s32, u8 *);
extern u8 D_80048E78[];
extern void SpuInit(void);
extern s32 SpuClearReverbWorkArea(s32);
extern void _SsInit();
extern SndVoice D_800624E8[];
extern s32 D_80049064;
extern u8 D_800618B0[];
extern s32 write(s32, u8 *, s32);
extern s32 D_8004E6D8;
extern s32 D_8004E6D4;
extern void Cd_IntrCallback();
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void ResetCallback(void);
#endif
extern void InterruptCallback(s32 arg0, void (*arg1)());
extern s32 Sys_DmaCallbacks[];
extern s32 *Sys_DicrPtr;
extern void trapIntrDMA();
extern s32 setIntrDMA();
extern void memclr_dma(s32 *arg0, u32 arg1);
extern u16 *D_8004FE28;
extern s32 D_8004FE50;
extern void Cd_QueueFile(s32);
extern SsVSyncHooks D_8004FC50;
extern s32 D_80062F94;
extern void close(s32);
extern s32 (*D_80048E30)();
extern s32 D_80048E98;
extern s32 Pad_SioXferDataByte(PadPortSio *, s32);
extern s16 _SsVmSetSeqVol(s32, s32, s32, s32);
extern s32 Card_TaskWork[4][4];
extern s32 (*Card_TaskFuncs[4])(s32 *);
extern char D_80010D44[];
extern void printf();
extern s32 SpuSetReverb(s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 CdControl(s32, u8 *, u8 *);
#endif
extern void func_8002DF74(void);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void InitGeom(void);
#endif
extern void SetFarColor(s32, s32, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void SetGeomOffset(s32, s32);
#endif
extern s16 D_8006197E;
extern s16 D_8006197C;
extern DungState *Dung_StatePtr;
extern DungState Dung_State;
extern char D_8001031C[];
extern void checkRECT(char *, RECT *);
extern s8 D_80010974[];
extern void Debug_PutChar(s8);
extern void (*volatile D_8004FE60)(void);
extern s32 _spu_Fw(s32, u32);
extern SndVmCur D_80062D18;
extern VagAtr *D_80062D08;
extern s32 SsPitchFromNote(s32, s32, s32, s32);
extern s32 D_8004FC5C;
extern GpuEnv D_80048F10;
extern char D_80010250[];
extern char D_80010290[];
extern s32 *D_8004FE38;
extern volatile u16 D_8004FE40;
extern s32 _spu_t(s32, ...);
extern u32 _spu_FsetRXXa(s32, u32);
extern IntrRegs *Pad_IntrRegs;
extern void (*D_80048E40)(void);
extern s32 Sys_VSyncCount;
extern char D_80010B74[];
extern s32 Card_AcceptTask(s32 *);
extern void Card_PushTask(s32 (*)(s32 *));
extern void printf();
extern s16 D_8006198C;
extern void func_8002ACC8(u16, u16, u16, u16, u16);
extern void func_8002BB84(void);
extern void func_8002AE4C();
extern void GsSetDrawBuffClip(void);
extern void GsSetDrawBuffOffset();
extern s32 _spu_isCalled;
extern s32 _spu_EVdma;
extern void _spu_FiDMA(void);
extern s32 OpenEvent(s32, s32, s32, s32);
extern void EnableEvent(s32);
extern char D_80010310[];
extern void checkRECT(char *, RECT *);
extern s32 D_80061B24;
extern s32 D_80061B20;
extern s32 D_80061B1C;
extern s32 D_80061B14;
#ifdef DW2_NATIVE
/* main's view of the libcd stream flag (psyq/libcd.h). */
#define StCdIntrFlag (*(s32 *)&StCdIntrFlag)
#else
extern s32 StCdIntrFlag;
#endif
extern s16 D_80061AFC;
extern s32 D_80061AF8;
extern void Cd_ClearStreamSlots(s32, s32);
extern s32 D_8004FE88;
extern s32 D_8004FE8C;
extern SpuMallocRec *Spu_MemList;
extern s32 Rand_Next();
extern St6191C D_8006191C;
extern GfxScreenMode D_8006196C;
extern s16 D_8006198E;
extern void func_8002AE4C();
extern s32 Task_Run(s32);
extern SndProgAtr *D_80062CFC;
extern s32 _SsVmVSetUp(s16, s16);
extern s32 D_8004E6E8;
extern u8 *D_8004E600;
extern u8 *D_8004E60C;
extern void CdDataCallback(s32);
extern int func_80030A64(int);
extern void func_80030A84(s32);
extern void Pad_CmdQueryModel(Actor *arg0);
extern void Pad_CmdQueryMode(Actor *arg0, u8 arg1);
extern void Pad_CmdQueryComb(Actor *arg0, u8 arg1);
extern s32 Pad_IsTimedOut(void);
extern s32 *D_8004FBC4;
extern Pair61900 D_80061900;
extern s32 D_80061990;
extern s32 D_80061994;
extern s32 D_80061998;
extern s32 D_8006199C;
extern s32 D_800619A0;
extern char D_80010624[];
extern void printf();
extern s16 _SsVmSetSeqVol(s32, s32, s32, s32);
extern void _spu_FwriteByIO(u16 *, u32);
extern s32 SsUtGetVagAtr();
extern s32 SsUtSetVagAtr();
extern void _SsVmSeqKeyOff(s32);
extern u8 D_80062D38[];
extern u16 D_80062D90;
extern s32 D_80062D98[];
extern void SpuFree(s32);
extern s32 _spu_getInTransfer(void);
extern void _spu_setInTransfer(s32);
extern s32 D_80061B28;
extern s32 D_80061B50;
extern s32 D_80061B00;
extern s32 D_80061B10;
extern s32 D_80061B08;
extern s32 D_80061B54;
extern char D_800102AC[];
extern s16 D_800618F0[];
extern s16 D_800618F4[];
extern DrawEnv D_80061908;
extern RECT D_80061980;
extern TaskDesc **Task_DescTable[];
extern char D_80010390[];
extern PadPort *(*D_80048E2C)(void);
extern void (*D_80048E1C)(PadPort *);
extern s32 (*D_80048EA0[])(PadPort *);
extern s32 D_80048E5C;
extern void (*D_80048E18)(s32);
extern void Pad_SetTimeout(s32);
extern s32 func_80025C00(void);
extern char D_80010C98[];
extern char D_80010CBC[];
extern char D_80010CE8[];
extern s32 Card_ReadDataTask(s32 *);
extern char D_80010C98[];
extern char D_80010CBC[];
extern char D_80010CE8[];
extern s32 Card_WriteDataTask(s32 *);
extern s32 D_8004FE78;
extern u8 D_80010364;
extern u8 D_80010378;
extern IntrEnv D_8004EAF8;
extern s32 *D_8004FB8C;
extern s32 D_80063060;
extern s32 D_80063064;
extern s32 D_80063068;
extern s32 D_8006306C;
extern s32 D_80063070;
extern s32 D_80063074;
extern s32 D_80063078;
extern s32 D_8006307C;
extern s32 D_80062D50[];
extern s32 *D_80049034;
extern volatile s32 D_80049038;
extern volatile s32 D_8004903C;
extern s32 D_80049048;
extern GpuQueueEntry D_800600B0[];
extern s32 *D_8004E994;
extern volatile CdIntrStatus D_8004E9A4;
extern s32 D_80048E50;
extern Reg48DF0 *D_80048DF0;
extern State60058 D_80060058;
extern void SysEnqIntRP(s32, u8 *);
extern PadPort *D_80048E4C;
extern s32 Card_InfoTask(s32 *);
extern char D_800102F8[];
extern s32 D_80048E64;
extern s32 D_80048E9C;
extern s32 (*D_80048E20)(PadPortSio *, s32);
extern void (*D_80048E24)(PadPortSio *);
extern s32 _SsVmSetVol(s16, s16, s16, u16, u16);
extern s8 D_80010984[];
extern s32 D_8004FDBC;
extern s32 D_8004FDC0;
extern s32 D_8004FDC4;
extern SpuReverbState D_8004FDCC;
extern s8 D_80062D0C;
extern s32 D_8004FC18;
extern SndVoiceField D_800624F8[];
extern s16 D_80062D30;
extern void Card_ClearTaskStack(void);
extern void Card_OpenEvents(void);
extern void Card_OnVSync();
extern char D_800103C4[];
extern u8 *Digi_GetDefaultName(s32);
extern char D_80010304[];
extern char D_80010328[];
extern void Gpu_RestoreExequeCb(void);
extern Pkt48F9C D_80048F9C;
extern s32 _SsVmSetVol(s16, s16, s16, u16, u16);
extern Reg506BC *D_800506BC;
extern s32 D_8004FDB4;
extern s32 D_8004FDDC;
extern s32 D_8004FDE0;
extern u16 D_8004FDE4[24];
extern s32 D_8004FE14;
extern s32 D_800503B8[];
extern u16 *D_8004E9A0;
extern char D_80010328[];
extern s32 Flag_TestConds();
extern volatile u8 *D_8004EA60;
extern volatile u8 *D_8004EA64;
extern volatile s32 *D_8004EA68;
extern volatile s32 *D_8004EA6C;
extern volatile s32 *D_8004EA70;
extern volatile s32 *D_8004EA74;
extern volatile s32 *D_8004EA78;
extern volatile s32 *D_8004EA7C;
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 ResetGraph(s32);
extern DispEnv *PutDispEnv(DispEnv *);
#endif
extern DispEnv D_80061968;
extern s32 D_80049060;
extern s8 D_80049071[];
extern BlkFill618D0 D_800618D0[];
extern void Cd_ReadFileAsync(s32, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void SsSepStop(s16, s16);
extern void SsSepClose(s16);
extern void SsVabClose(s16);
#endif
extern char D_800103F8[];
extern void Gpu_RestoreExequeCb(void);
extern void Gpu_RestoreExequeCb(void);
extern s32 D_80062F70;
extern s32 D_80062F74;
extern void set_alarm(void);
extern s32 Gpu_OtLayerLens[][8];
extern s32 Gpu_OtLayerOffsets[][8];
extern Mode5CCF8 D_8005CCF8;
extern s32 *D_80049028;
extern s32 *D_8004902C;
extern s32 *D_80049030;
extern s32 *D_80049034;
extern Prm1C Menu_DigiStatusView;
extern s32 Digi_GetModelFile(s32 id);
extern s32 Digi_GetAnimFile(s32 arg0, s32 arg1);
extern void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
#endif

extern void Item_SortList(void);
extern void Stg20_SetSpecialFlag(s32, s32);
extern s32 D_80048E88;
extern s32 D_80048E68;
extern s32 D_80048E6C;
extern s32 D_80048E58;
extern s32 D_80048E60;
extern s32 func_8002533C(PadPort *);
extern char D_800102D4[];
extern char D_800102E0[];
extern char D_800102F4[];
extern s8 D_80010944[];
extern char D_80010950[];
extern u8 D_8004E9A8[];
extern u8 D_8004E6E4;
extern u8 *D_8004E98C;
extern u8 *D_8004E99C;
extern u8 *D_8004E990;
extern Hook33424 Snd_MarkCallbacks[][16];
extern int Card_OnSwIoe(void);
extern int Card_OnSwError(void);
extern int Card_OnSwTimeout(void);
extern int Card_OnSwNewCard(void);
extern int Card_OnHwIoe(void);
extern int Card_OnHwError(void);
extern int Card_OnHwTimeout(void);
extern int Card_OnHwNewCard(void);
extern void Card_ClearEvents(void);
extern char D_80010C70[];
extern void Card_MakeDevName(s32, u8 *);
#ifndef DW2_NATIVE /* libc: <string.h> in the native build */
extern s8 *strcat(s8 *, s8 *);
#endif
extern s32 open(u8 *, s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s32 MemCardSync(s32 wait, s32 *a1, s32 *a2);
#endif
extern void Card_ClearEvents(void);
extern s32 D_80062F90;
extern void Pad_SendInfoCmd(PadPort *a0);
extern void Pad_CmdConfigMode(Actor *arg0, u8 arg1);
extern void (*D_80048E1C)(PadPort *);
extern Flags506C0 *D_800506C0;
extern s32 D_800506DC;
extern GameState *Save_GameStatePtr;
extern char D_8001021C[];
extern char D_8001023C[];
extern char D_80048EC8[];
extern u16 D_80048F90[][2];
extern void GPU_cw(s32);
extern s16 D_800624D0;
extern s16 D_800624D2;
extern s32 D_80061C48;
extern s32 D_80060054;
extern s32 Menu_BlinkOrHideParts(GfxPart *, s32, s32);
extern u16 Menu_SkillPaneMasks[];
extern void (*D_80061BC8)(s16, s16, s32);
extern void (*D_80061BCC)(s16, s16, s32);
extern void (*D_80061BD0)(s16, s16, s32);
extern void (*D_80061BD4)(s16, s16, s32);
extern void (*D_80061BD8)(s16, s16, s32);
extern void (*D_80061BDC)(s16, s16, s32);
extern void (*D_80061BE0)(s16, s16, s32);
extern void (*D_80061BE4)(s16, s16, s32);
extern void (*D_80061BE8)(s16, s16, s32);
extern void (*D_80061BEC)(s16, s16, s32);
extern void (*D_80061BF0)(s16, s16);
extern void Gfx_LoadTexSlotImage(GfxTexSlot *);
extern s32 Pad_ParseInfoReply(PadPort *);
extern s32 D_80061C44;
extern void _SsVmFlush(void);
extern void _SsSndCrescendo(s16, s16);
extern void _SsSndTempo(s16, s16);
extern void _SsSndPause(s32 a0, s16 a1);
extern void _SsSndReplay(s16 a0, s16 a1);
extern void _SsSndStop(s32 arg0, s32 arg1);
extern void func_80031D74(s16, s16);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern s32 Rand_Index;
extern s32 Snd_CurrentId;
extern s32 Snd_SavedId;
extern GameState *Save_GameStatePtr;
extern s32 Ovl_CurrentId;
extern s32 Skill_ShotXaFile;
extern s32 Skill_ShotXaChannel;
extern s32 Mem_HeapSize;
extern MemBlock *Mem_HeapHead;
extern s32 Cd_PreloadIds[];
extern s32 Cd_PreloadCount;
extern s32 Ovl_FileIds[];
extern u8 *const Ovl_LoadAddr; /* overlay load address (0x80063360) */
extern void Snd_StopById(s32);
extern void Snd_StopById(s32);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void SsSepSetVol(s16 a0, s16 a1, s16 a2, s16 a3);
extern void SsSepPlay(s16, s16, s8, s16);
extern void SsUtAllKeyOff(s32);
#endif
extern Halves Menu_ItemMsgPos;
extern Halves Menu_ItemNamePos;
extern s32 Cd_QueueActive;
extern s32 Cd_GetFileSectors(s32 arg0);
extern DigiSortRank Digi_StateSortRank[];
extern s32 Sys_FlipPending;
extern s32 Sys_VSyncsSinceFlip;
extern Halves Menu_ItemUseMsgPos;
extern s32 Item_Use(s32, s32, s32, s32);
extern u8 *Menu_PartGridSlots;
extern u8 *Menu_PartGridLabels;
extern u8 *Menu_PartGridSlots;
extern void Menu_OpenItemNameTexts(Actor *, s32);
extern u8 *Menu_PartGridSlots;
extern char D_80010334[];
extern s32 D_80048FBC;
extern u32 D_80048FD0;
extern Halves Menu_DigiMsgPos;
extern void Menu_UseBugZapItem(Actor *);
extern void Menu_OpenBugTexts(Actor *, s32);
extern s32 Menu_TopMenuResult;
extern s32 Digi_CountByState(s32 mode);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Text_SetColor(s32 a0, s32 a1);
extern Halves Menu_SkillMsgPos;
extern void Menu_SkillListOpenNames(Actor194C8 *, s32);
extern s32 Item_UseOnBeetle(s32, s32, s32, s32);
extern s32 Item_ApplyToDigi(s32, s32, s32, s32);
extern s32 Item_UseStatBoost(s32, s32, s32, s32);
extern s32 Item_UseRecoverAll(s32, s32);
extern Cd4FC48 D_8004FC48;
extern s32 Snd_TicksPerSec;
extern s16 Gfx_FaceImageIds[];
extern GameState *Save_GameStatePtr;
extern SndBankDesc *Snd_BankDescs[];
extern s32 Snd_SlotBufSizes[3];
extern s32 Cd_GetFileState(s32 arg0);
extern s32 Cd_GetFileSync(s32 arg0);
extern void Cd_LockFile(s32 a0);
extern void Cd_UnlockFile(s32 a0);
extern s32 Mem_GetOffsetEntry(s32 arg0, s32 *arg1);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern s16 SsVabOpenHead(s32 arg0, s16 arg1);
extern s16 SsVabTransBody(s32 a0, s16 id);
extern s16 SsVabTransCompleted(s16 a0);
extern s16 SsSepOpen(s32, s16, s32);
#endif
extern s16 D_80062D2C[];
extern u16 D_8004FC24[];
extern void _SsVmInit(s32);
extern s16 D_80062CFA;
extern VagAtr *D_80062CB8[];
extern s32 D_80062C70[];
extern SndProgAtr *D_80062C30[];
extern s32 D_80062D04;
extern void Mem_Zero(void *a0, s32 a1);
extern s32 get_alarm(void);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void ApplyMatrixSV(void *, SVec1D104 *, GfxPartRotXY *);
#endif
extern s32 D_80062F58;
extern s32 D_80062F5C;
extern s32 D_80062F60;
extern s32 D_80062F64;
extern s32 D_80062F68;
extern s32 Card_GetHwEventBits(void);
extern s32 Card_WaitHwEvent(void);
extern void _card_load(s32);
extern void _card_info(s32);
extern s32 Card_GetSwEventBits(void);
extern s32 Card_WaitSwEvent(void);
extern s32 Card_EventToMcErr(s32);
extern s32 _card_clear(s32 a0);
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
extern void Mem_FillWordsNeg1(s32 *arg0, s32 arg1);
extern void Text_CloseArray(s32 *arg0, s32 arg1);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void GsSetOffset(s32, s32);
#endif
extern u8 Digi_GetType(s32);
extern s32 Digi_GetRank(s32);
extern s32 Digi_GetSpecialty(s32);
extern s32 D_8004E88C[];
extern s32 D_8004E78C[];
extern s8 *D_8004E6EC[];
extern s32 D_8004E6DC;
extern u8 D_80061B68[];
extern u8 D_80061B70[];
extern u8 D_80061B78[];
extern s8 D_8001087C[];
extern s8 D_80010888[];
extern s8 D_800108A4[];
extern s8 D_800108B8[];
extern s16 D_80062CF8;
extern u16 D_80062A48[];
extern u8 D_80062A28[];
extern u16 D_80062C10;
extern u16 D_80062C12;
extern u16 D_800624D8;
extern u16 D_800624DA;
extern u16 D_800624DC;
extern u16 D_800624DE;
extern u16 D_800624E0;
extern u16 D_800624E2;
extern u16 D_80062A4A[];
extern u16 D_80062A4C[];
extern u16 Menu_DigiListRowMasks[];
extern SpuMallocRec D_80062DE0;
extern u16 D_80062A48[];
extern u8 D_80062A28[];
extern u8 D_80062D48;
extern s32 D_80062D10;
extern void SpuSetVoiceAttr(VAttr36C54 *);
extern void _SsVmKeyOffNow(s32);
extern s32 D_800506D0;
extern s32 D_8004E9E0[];
extern DmaChanRegs *D_8004FBF4;
extern char D_80010A04[];
extern char D_80010A20[];
extern s32 _SsVmKeyOn(s16, s16, s16, u16, u16, u16);
extern s32 _SsVmKeyOff(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 _SsVmAlloc(s32);
extern void _SsVmDoAllocate(void);
extern u16 note2pitch(void);
extern void vmNoiseOn(u8);
extern u8 _SsVmSelectToneAndVag(u8 *idx, u8 *val);
extern char D_800103AC[];
extern u8 D_8004900C[];
extern DispHRange D_80048FE4[][5];
extern s32 GetVideoMode(void);
extern s32 SpuSetNoiseClock(s32);
extern s32 Menu_NameEntryRowStride[];
extern s32 Menu_NameEntryPageCol[];
extern s32 D_80062F00;
extern s32 (*D_80062F04[2])(void);
extern s32 D_80062F0C;
extern s32 func_8003D7E8(void);
extern s32 func_8003D850(void);
extern void *D_8004E5E0;
extern s32 D_8004E5E4;
extern char D_800106D4[];
extern s32 func_8002DC94(void);
extern void def_cbsync(void);
extern void def_cbready(void);
extern void def_cbread(void);
extern void (*D_80062FE0)(s32 *, s32, s32);
extern s8 D_80062FE8[];
#ifndef DW2_NATIVE /* libc: <string.h> in the native build */
extern s32 strlen(s8 *);
#endif
extern s32 _SsVmKeyOn(s16 a0, s16 a1, s16 a2, u16 a3, u16 arg4, u16 arg5);
extern s8 D_80062D1F;
extern u16 D_80062EE8[];
extern u16 D_80050298[];
extern u16 D_800502B0[];
extern void func_8003F760(s32 *a0, s32 a1, s32 a2);
s32 firstfile();
#ifndef DW2_NATIVE /* libc: <string.h> in the native build */
extern s32 strcmp(s8 *a, s8 *b);
#endif
extern SioRegs *D_80048E00;
extern s32 D_80048E70[];
extern s32 Debug_VPrintf(s32, char *, char *);
extern s32 D_80048E94;
extern s32 Pad_SioExchangeByte(PadPortSio *, s32);
extern s32 *D_8004FE2C;
extern s32 *D_8004FE30;
extern s32 *D_8004FE34;
extern s32 D_800506D8;
extern Mat1F668 D_80061A28;
extern s32 Item_GetBagCapacity(void);
extern s32 Item_GetIdAtIndex(s32 a0);
extern s32 Item_GetCategory(s32 id);
extern char D_80010A34[];
extern TextOp D_80061BB0[37];
extern s32 _SsInitSoundSeq(s16, s16, s16, s32);
extern s32 D_8004FE4C;
extern u32 D_8004FE54;
extern u32 D_8004FE58;
extern CardDevNameTmpl D_80010D38;
extern u32 D_80060060[];
extern u32 D_80060088[];
extern void _cwc(s32 arg0);
extern s32 _param(s32 arg0);
extern s32 D_80048E54;
extern void (*D_80048E48)(void);
extern void (*D_80048E44)(void);
extern s32 Pad_SioExchangeByte();
extern PadPort *D_80048E4C;
extern s32 (*D_80048E34)(void);
extern void Pad_SendQueryInfoCmd(Actor *a);
extern s32 Pad_ParseTableReply();
extern void _spu_gcSPU();
extern u16 D_8004FC88[12];
extern u16 D_8004FCA0[128];
extern s16 _SsVmGetSeqVol(s32 a0, u16 *a1, u16 *a2);
extern char D_80010D18[];
extern char D_80010C70[];
extern s32 Card_ReadFileTask(s32 *a0);
extern char D_80010C70[];
extern char D_80010CBC[];
extern char D_80010CE8[];
extern char D_80010D18[];
extern s32 Card_WriteFileTask(s32 *st);
extern u16 D_80050298[];
extern u16 D_800502B0[];
extern volatile s32 D_8004FE7C;
extern s32 D_8004FE80;
extern void _spu_FsetDelayR(void);
extern void _spu_FsetDelayW(void);
extern char D_80010AA4[];
extern char D_80010AC4[];
extern char D_80010AD8[];
extern char D_80010D18[];
extern s32 Card_Format();
extern s32 Card_EventToMcErr(s32 a0);
#ifndef DW2_NATIVE /* Psy-Q libc (no game C call); the host libc declares its own */
extern u8 *bzero(u8 *s, s32 n);
#endif
extern char D_80010D18[];
extern s32 D_8004E9E0[];
extern s32 CD_cw();
extern s32 CD_sync();
extern s32 D_80062F54;
extern s32 D_80062F50;
extern u32 D_800506C8;
extern s32 D_800506CC;
extern char D_80010B9C[];
extern volatile s32 *D_8004EA88;
extern volatile s32 *D_8004EA8C;
extern volatile s32 D_8004EA90;
extern s32 D_8004EA94;
extern s32 D_8004FE48;
extern volatile s32 D_8004FE64;
extern s32 D_8004FE68[];
extern u16 D_80062EE8[];
extern char D_80010AA4[];
extern char D_80010AB4[];
extern void _spu_Fw1ts(void);
extern s32 Pad_SetupInfoTables(PadPort *a0, s32 a1);
extern s16 D_8004DDC0[];
extern s32 D_80061B80;
extern s32 D_80061B84;
extern char *D_80061B88;
extern char D_8001095C[];
extern char D_80010850[];
extern char D_80010860[];
extern char *D_8004E76C[];
extern s32 *D_8004E9C0;
extern u8 D_8004FE98[];
extern void WaitEvent(s32);
extern char D_8001034C[];
extern s32 D_800506D4;
extern s32 lseek(s32, s32, s32);
extern void Card_ClearEvents(void);
extern s32 Card_GetSwEventBits(void);
extern s32 Card_WaitSwEvent(void);
extern s32 _card_clear(s32 a0);
extern s32 Card_GetHwEventBits(void);
extern s32 Card_WaitHwEvent(void);
extern s32 Pad_GetTxByte(PadPortSio *, s32);
extern s32 (*D_80048E3C)(Actor *);
extern void (*D_80048E38)(PadPort *);
extern u8 D_8005FFB8[];
extern u8 D_80060000[];
extern void func_8002485C(s32 code);
extern void Pad_ResetPortState(PadPort *a0);
extern s32 Pad_ConsumeSendCmd(Actor *arg0);
extern void Pad_AllocActPower(PadPort *a0);
extern u8 *Pad_GetPortBlock(s32 arg0);
extern s32 func_80024CB8(PadPort *a0);
extern void Pad_HandleReply(PadPort *a0);
extern s32 func_80025114(PadPort *p);
extern volatile s8 D_80062D27;
extern u8 Bug_LastZappedLevel;
extern s32 D_80049040;
extern s32 ResetRCnt(s32 arg0);
extern s32 SetRCnt(s32 arg0, s32 arg1, s32 arg2);
extern void _SsTrapIntrVSync(void);
extern void _SsSeqCalledTbyT_1per2(void);
extern char D_800106F4[];
extern volatile DmaCtrlReg *D_8004E68C;
extern volatile u32 *D_8004E688;
extern volatile u8 *D_8004E670;
extern u16 _spu_note2pitch(s32 cenHigh, s32 cenLow, s32 noteHigh, s32 noteLow);
extern u16 *D_8004FB84;
extern s32 D_8004FB90;
extern char D_800109C8[];
extern char D_800109E4[];
extern void ReturnFromException(void);
extern char D_800108D8[];
extern u8 *D_80060048;
extern s32 nextfile(DirEntry *);
extern char D_800108EC[];
extern char D_800108F4[];
extern char D_80010904[];
extern u8 D_8004E6E0[];
extern CdComTables D_8004E80C;
#ifdef DW2_NATIVE
/* libgs light matrix (GsLIGHTWSMATRIX in psyq/libgs.h) under its decomp name. */
#define D_800619A8 (*(Mat1F668 *)&GsLIGHTWSMATRIX)
#else
extern Mat1F668 D_800619A8;
#endif
extern s32 SquareRoot0(s32);
extern void _spu_gcSPU(void);
extern s8 D_80010A64[];
extern char *D_80061B88;
extern char D_800108E0[];
extern char D_80010850[];
extern char D_80010860[];
extern u8 D_80061B78[];
extern u8 D_80061B70[];
extern u8 D_80061B68[];
extern s32 getintr(void);
extern void Debug_PutString(s8 *s);
extern s32 setjmp(s32 *env);
extern void HookEntryInt(s32 *env);
extern void _96_remove(void);
extern s32 D_80062BD0[];
extern u16 D_80062A4E[];
extern u16 D_80062A50[];
extern s32 D_80062BCC;
extern s32 D_80062BD0[];
extern void (*D_80062BC8)(s32);
extern void (*D_80062A40)(s32);
extern void SpuSetKey(s32 on_off, u32 voice_bit);
extern void SpuGetVoiceEnvelope(s32 a0, u16 *a1);
extern void SpuSetNoiseVoice(s32, s32);
extern void SpuSetReverbVoice(s32, s32);
extern void SpuGetNoiseVoice(void);
extern void SpuGetReverbVoice(void);
extern u16 D_80062A4E[];
extern u16 D_80062A50[];
extern u16 D_80062A52[];
extern MemBlock *Mem_HeapStart;
extern RECT Sys_BootImageRect;
extern s32 Sys_LastVSyncTime;
extern void Sys_VSyncHandler(void);
#ifndef DW2_NATIVE /* Psy-Q: psyq/ headers in the native build */
extern void MemCardInit(void);
#endif
extern Pair61900 Menu_ItemSubTasks[];
#ifdef DW2_NATIVE
/* main's view of the libgs MATRIX GsWSMATRIX (psyq/libgs.h). */
#define GsWSMATRIX (*(CoordMatrix *)&GsWSMATRIX)
#else
extern CoordMatrix GsWSMATRIX;
#endif
extern CoordMatrix D_80061A48;
extern CoordMatrix D_800619E8;
extern void GsGetLw();
extern Halves Gfx_NeutralRgb;
extern Pair54 Text_PortraitQuadGrid[3][3];
extern u8 D_800632E0[0x80];
extern CardDirFrame D_800630A0[15];
extern s32 D_80063280[20];
extern SpuReverbRegs D_800503E8[];
extern void Mem_CopyWords(s32 *dst, s32 *src, u32 count);
extern void Cd_StartDma(s32 ch, u32 madr, s32 hi, s32 lo, u32 chcr, u8 mode);
extern char D_80010404[];
extern char D_80010418[];
extern char D_80010420[];
extern Pair61900 D_800618F8;
extern Pair61900 D_800618FC;
extern s32 D_80061988;
extern SndVoiceField D_800624F0[];
extern SndVoiceField D_800624FA[];
extern SndVoiceField D_800624FC[];
extern SndVoiceField D_800624FE[];
extern SndVoiceField D_80062500[];
extern s8 D_800632D0[16];
extern char D_80010D64[];
extern s32 _card_read(s32, s32, u8 *);
extern void Menu_DigiTransferPlace(Actor *);
extern s32 D_80049044;
extern u16 D_80062D60[];
extern MenuGridLayout Menu_DigiListGrid;
extern Pair61900 Menu_DigiListSubTasks[];
extern Halves Menu_DigiListTitlePos[];
extern Halves Menu_DigiListCursorTextPos;
extern void Menu_DigiTransferPlace(Actor *a0);
extern Coord1F668 *D_80061A68[];
extern Coord1F668 *D_80061A64[];
extern void (*D_80061BF4[])(s16, s16, s16, VagAtr, s32, s32);
extern GfxQuadVert Gfx_ZeroSVector[]; /* zero vector; retail reaches it with lui/%lo, so not a sized small-data extern */
extern s32 Gfx_IsOriginOffscreen(void);
extern s32 Gfx_ProjectModelVerts(Vert6Pmv *, ModelProjView *, s32);
extern void Gfx_CalcNormalColors(Vert6Pmv *, ModelProjView *);
extern void Gfx_AddQuadsGT4(ModelQuadGT4 *, s32, ActorModel *, s32);
extern void Gfx_AddTrisGT3(GfxModelTriGT3 *, s32, ActorModel *, s32);
s16 _SsVmPBVoice(s16, s16, s16, s16, u16);
void Save_ClearEventFlags(void);
void Task_RunChildren(TaskChildrenView *a0);
s32 Task_TryRun(void *arg0);
void Task_Destroy(s32 *arg0);

typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ s32 rosterIndex;
    /* 0x08 */ s32 maxLen;
    /* 0x0C */ s32 charTableOfs;
    /* 0x10 */ s32 gridText0;
    /* 0x14 */ s32 gridText1;
    /* 0x18 */ s32 gridText2;
    /* 0x1C */ s32 headerText;
    /* 0x20 */ s32 nameText;
    /* 0x24 */ s32 namePos;
    /* 0x28 */ s32 blinkTimer;
    /* 0x2C */ s16 cursorX;
    /* 0x2E */ s16 cursorY;
} Wk12974;

typedef struct {
    /* 0x00 */ u8 name[0x5C];
} Nm12974;


/* file-local views for Menu_MoveGridCursor */
typedef struct {
    s16 x;
    s16 y;
} Coord138C0;

typedef struct {
    s16 h[2];
} Copy138C0;

/* view of PadState that reads the 0x3C flag word unsigned */
typedef struct {
    u8 _p[0x3C];
    u16 repeat;
    u8 _p2[0x40 - 0x3E];
} PadRepeatView;


/* View of Actor.work used by Menu_DigiStatusDraw (fields 0x80..0x14C). */
typedef struct {
    u8 _pad00[0x80];
    /* 0x80 */ s32 ramp;
    /* 0x84 */ PTR32(s32) digimon;
    u8 _pad88[0xB0 - 0x88];
    /* 0xB0 */ s32 posX;
    /* 0xB4 */ s32 posY;
    /* 0xB8 */ s32 posZ;
    u8 _padBC[0xC0 - 0xBC];
    /* 0xC0 */ s32 modelFile;
    u8 _padC4[0xC8 - 0xC4];
    /* 0xC8 */ s32 modelPhase;
    /* 0xCC */ s32 vpx;
    /* 0xD0 */ s32 vpy;
    /* 0xD4 */ s32 vpz;
    /* 0xD8 */ s32 vrx;
    /* 0xDC */ s32 vry;
    /* 0xE0 */ s32 vrz;
    /* 0xE4 */ s32 projection;
    /* 0xE8 */ s32 coord;
    /* 0xEC */ s32 coordMatrix;
    u8 _padF0[0x100 - 0xF0];
    /* 0x100 */ s32 coordTx;
    /* 0x104 */ s32 coordTy;
    /* 0x108 */ s32 coordTz;
    u8 _pad10C[0x138 - 0x10C];
    /* 0x138 */ s32 rot;
    u8 _pad13C[0x148 - 0x13C];
    /* 0x148 */ s32 field_148;
    /* 0x14C */ s32 modelScale;
} Wk19214;

/* Record reached through Wk19214.field_84. */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 level;
    u8 _padE;
    /* 0x0F */ u8 maxLevel;
    /* 0x10 */ s32 exp;
    /* 0x14 */ s16 maxHp;
    /* 0x16 */ s16 hp;
    /* 0x18 */ s16 maxMp;
    /* 0x1A */ s16 mp;
    /* 0x1C */ s16 attack;
    /* 0x1E */ s16 defense;
    /* 0x20 */ s16 speed;
} Rec19214;

/* Node reached through Actor.u38.ptr38. */
typedef struct {
    u8 _pad00[0x58];
    /* 0x58 */ s32 scaleX;
    /* 0x5C */ s32 scaleY;
    /* 0x60 */ s32 scaleZ;
} Nd19214;

/* Stack context passed to GsSetRefView2. The native build has the Psy-Q GsRVIEW2
 * (psyq/libgs.h, same layout, super typed GsCOORDINATE2 *). */
#ifndef DW2_NATIVE
typedef struct {
    /* 0x00 */ s32 vpx;
    /* 0x04 */ s32 vpy;
    /* 0x08 */ s32 vpz;
    /* 0x0C */ s32 vrx;
    /* 0x10 */ s32 vry;
    /* 0x14 */ s32 vrz;
    /* 0x18 */ s32 rz;
    /* 0x1C */ s32 *super;
} GsRVIEW2;
#endif

/* File-local view of an SndSlot element with the fields Snd_Init stamps. */
typedef struct {
    /* 0x00 */ s32 contentId;
    /* 0x04 */ s32 loadState;
    /* 0x08 */ s16 vabId;
    /* 0x0A */ s16 sepCount;
    u8 _padC[0x28 - 0xC];
    /* 0x28 */ sptr headerBuf; /* SndSlot.headerBuf (s32 *) */
} Ew54C48; /* 0x2C */

extern u8 Snd_SeqAttrTable[176 * 6 * 16];
extern s16 Text_SfxIds[];
extern u8 *Text_BuiltinStrings[];

/* File-local record walked by Gfx_DrawPartsEx (stride 0x28). */
typedef struct {
    /* 0x00 */ s32 fileId;
    u8 _pad04[0xB - 4];
    /* 0x0B */ u8 otLayer;
    u8 _pad0C[0xE - 0xC];
    /* 0x0E */ u8 unscaled;
    /* 0x0F */ u8 visible;
    /* 0x10 */ s32 scaleX;
    /* 0x14 */ s32 scaleY;
    u8 _pad18[0x20 - 0x18];
    /* 0x20 */ s16 rotX;
    /* 0x22 */ s16 rotY;
    /* 0x24 */ s16 rotZ;
    /* 0x26 */ s16 _pad26;
} Rec1D6B4; /* 0x28 */


typedef struct {
    /* 0x00 */ s32 rotXY;
    /* 0x04 */ s16 rotZ;
    u8 _pad06[2];
    /* 0x08 */ s32 scaleX;
    /* 0x0C */ s32 scaleY;
    /* 0x10 */ s32 scaleZ; /* scaleX..scaleZ: the VECTOR ScaleMatrix reads */
    u8 _pad14[4];
    /* 0x18 */ Mat1F668 matrix;
} GfxPartRotCache;

/* 2-byte-aligned aggregate forcing the lwl/lwr + swl/swr block copy. */
typedef struct {
    s16 h[4];
} Agg1D6B4;

extern GfxPartRotCache Gfx_PartRotCache;


extern Blk20 Gfx_IdentityMatrix;

typedef struct {
    s16 id;
    s16 flag;
} Ent22038;

#endif /* MAIN_GAME_H */
