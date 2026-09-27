#include "common.h"
#include "main/156C.h"

extern Ent23A78 D_8005F8C8[0x50];
extern Ent54C48 D_80054C48[3];
extern s32 Cd_PollRead(void);
extern void Cd_LoadFileSync(s32);
extern s32 D_8005F774;
extern u8 D_80048F12;
extern u8 D_8004E6E5;
extern u16 D_8004EAFA;
extern s32 D_800506B8;
extern u32 Card_TaskTop;
extern s32 Sys_VideoMode;
extern S5D560 D_8005D560;
extern s32 D_8005F780;
extern State62F80 D_80062F80;
extern u8 D_8005F6A8[];
extern Elm678 D_8005F678[];
extern Elm6F0 D_8005F6F0[];
extern u8 D_800416FC[];
extern Obj48F08 *D_80048F08;
extern void (*D_80048F0C)(void *, ...);
extern u8 D_800102C0;
extern u8 D_80048F20[];
extern u8 D_80048F7C[];
extern Blk50938 Task_FindFilter;
extern s32 Cd_FileLba[];
extern Actor D_8005F770;
extern ActorWork *D_80041670[];
extern Elem20 Gfx_TexSlots[];
extern Obj80041564 Gfx_FadeState;
extern u16 D_80041704[];
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
extern Stack54CD0 Text_ReturnStack;
extern List50798 Task_List;
extern Blk54CF8 Gpu_OtBufs[];
extern Blk54CF8 D_80058D28[];
extern EntE620 D_8005E620;
extern s32 D_80062FD8;
extern void Digi_InitFromTable(s32, s32, ElmE620 *);
extern void Digi_SortRoster(void);
extern Blk54CF8 *ClearOTagR(Blk54CF8 *, s32);
extern void Snd_PlayById(s32, s32);
extern s32 DrawOTag(void *);
extern s32 EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern s32 StartCARD(void);
extern void ChangeClearPAD(s32);
extern s32 Gfx_ReserveTexSlot(void);
extern s32 Mem_TryAlloc(s32, s32);
extern void Cd_EvictLruFile(void);
extern void Text_Close(s32 *);
extern void Mem_Free(ActorWork *);
extern s32 D_8005F79C;
extern Sub3C *Gfx_AttachModel(Actor *, s32);
extern void Gfx_ResetModelBones(Actor *);
extern s32 D_80043704[];
extern void Actor_UpdateTransform(Actor *);
extern void Gfx_CalcModelBoneMatrices(Actor *);
extern void Gfx_DrawTexModel(Actor *, s32);
extern Obj48DB8 D_80048DB8;
extern u8 D_8005FDC8[];
extern s32 CdPosToInt(void *);
extern s32 CdGetSector(void *, s32);
extern s32 CdReadyCallback(s32);
extern s32 CdControlF(s32, s32);
extern void *CdSyncCallback(void *);
extern void Cd_ReadSyncCallback();
extern void Anim_StepModelAnim(Actor *);
extern Blk16 D_800416CC[];
extern s32 GsSetFlatLight(s32, Blk16 *);
extern void GsSetAmbient(s32, s32, s32);
extern void GsSetLightMode(s32);
extern s32 func_8001E134(void);
extern s32 *Item_GetEffectRec(s32);
extern s32 D_80040FD0[];
extern void Gfx_SetPartsScale(Ent1D550 *, s32, s32);
extern void Gfx_DrawParts(s32);
extern void Text_Open(void *, Arg1BC24 *);
extern void Flag_Set(s32, s32);
extern void Gfx_SetPartsNumber(Part28 *, s32, s32, s32);
extern s32 Digi_GetExpToNextLevel(s32, s32, s32);
extern void func_8002D744(void *, Obj209 *);
extern void GsSetProjection(s32);
extern void Anim_SetModelAnim(Actor *, s32);
extern s32 D_8004E6D0;
extern s32 D_8004E6CC;
extern void *D_8004E6C8;
extern s32 _exeque();
extern void DMACallback();
extern Cmd62C18 D_80062C18;
extern void SsUtSetReverbFeedback(s16);
extern void SsUtSetReverbDelay(s16);
extern Elm354F4 *Snd_SeqScores[];
extern s32 _SsReadDeltaValue(s16, s16);
extern s32 D_80060050;
extern s32 D_8006004C;
extern Flags4FC68 *D_8004FC68;
extern s32 D_8004FC70[];
extern int MemCardCallback(int);
extern Vt4FB80 *D_8004FB80;
extern u8 D_8005FDD8[];
extern s32 *D_80049014;
extern s32 D_8004904C;
extern s32 D_80049050;
extern s32 VSync(s32);
extern s32 D_80061B38;
extern s32 D_80061B3C;
extern void StClearRing();
extern s32 D_8004FDB8;
extern s32 D_8004FE44;
extern Stat48E90 *Pad_SioRegs;
extern Obj50768 *Menu_Ctx;
extern s32 sin_1(s32);
extern s32 CD_init();
extern s32 func_8002FDC8();
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
extern Elm624E8 D_800624E8[];
extern s32 D_80049064;
extern u8 D_800618B0[];
extern s32 write(s32, u8 *, s32);
extern s32 D_8004E6D8;
extern s32 D_8004E6D4;
extern void Cd_IntrCallback();
extern void ResetCallback(void);
extern void InterruptCallback(s32 arg0, void (*arg1)());
extern s32 Sys_DmaCallbacks[];
extern s32 *Sys_DicrPtr;
extern void trapIntrDMA();
extern s32 setIntrDMA();
extern void memclr_dma(s32 *arg0, u32 arg1);
extern u16 *D_8004FE28;
extern s32 D_8004FE50;
extern void Cd_QueueFile(s32);
extern Hooks4FC50 D_8004FC50;
extern s32 D_80062F94;
extern void close(s32);
extern s32 (*D_80048E30)();
extern s32 D_80048E98;
extern s32 func_80025760(Ent266D0 *, s32);
extern s16 _SsVmSetSeqVol(s32, s32, s32, s32);
extern s32 Card_TaskWork[4][4];
extern s32 (*Card_TaskFuncs[4])(s32 *);
extern char D_80010D44[];
extern void printf();
extern s32 SpuSetReverb(s32);
extern s32 CdControl(s32, u8 *, u8 *);
extern void func_8002DF74(void);
extern void func_8002CE5C(void);
extern void SetFarColor(s32, s32, s32);
extern void SetGeomOffset(s32, s32);
extern s16 D_8006197E;
extern s16 D_8006197C;
extern Blk5071C *D_8005071C;
extern char D_8001031C[];
extern void checkRECT(char *, Rect2AB54 *);
extern s8 D_80010974[];
extern void Debug_PutChar(s8);
extern void (*volatile D_8004FE60)(void);
extern s32 _spu_Fw(s32, u32);
extern Snd62D18 D_80062D18;
extern Rec62D08 *D_80062D08;
extern s32 SsPitchFromNote(s32, s32, s32, s32);
extern s32 D_8004FC5C;
extern Gpu48F10 D_80048F10;
extern char D_80010250[];
extern char D_80010290[];
extern s32 *D_8004FE38;
extern volatile u16 D_8004FE40;
extern s32 _spu_t(s32, ...);
extern u32 _spu_FsetRXXa(s32, u32);
extern Regs48E8C *Pad_IntrRegs;
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
extern void checkRECT(char *, Rect2AB54 *);
extern s32 D_80061B24;
extern s32 D_80061B20;
extern s32 D_80061B1C;
extern s32 D_80061B14;
extern s32 D_80061B04;
extern s16 D_80061AFC;
extern s32 D_80061AF8;
extern void Cd_ClearStreamSlots(s32, s32);
extern s32 D_8004FE88;
extern s32 D_8004FE8C;
extern Hdr3AD44 *Spu_MemList;
extern s32 Rand_Next();
extern St6191C D_8006191C;
extern St6196C D_8006196C;
extern s16 D_8006198E;
extern void func_8002AE4C();
extern s32 Task_Run(s32);
extern Ent62CFC *D_80062CFC;
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
extern void func_8003A454(u16 *, u32);
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
extern Rect2AB54 D_80061980;
extern ObjDesc **D_80040D50[];
extern char D_80010390[];
extern Obj25FBC *(*D_80048E2C)(void);
extern void (*D_80048E1C)(Obj25FBC *);
extern s32 (*D_80048EA0[])(Obj25FBC *);
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
extern Obj4EAF8 D_8004EAF8;
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
extern Que291FC D_800600B0[];
extern s32 *D_8004E994;
extern volatile Cd4E9A4 D_8004E9A4;
extern s32 D_80048E50;
extern Reg48DF0 *D_80048DF0;
extern State60058 D_80060058;
extern void SysEnqIntRP(s32, u8 *);
extern Obj25FBC *D_80048E4C;
extern s32 Card_InfoTask(s32 *);
extern s32 D_8005F704;
extern char D_800102F8[];
extern s32 D_80048E64;
extern s32 D_80048E9C;
extern s32 (*D_80048E20)(Ent266D0 *, s32);
extern void (*D_80048E24)(Ent266D0 *);
extern s32 func_80039334(s16, s16, s16, u16, u16);
extern s8 D_80010984[];
extern s32 D_8004FDBC;
extern s32 D_8004FDC0;
extern s32 D_8004FDC4;
extern Blk4FDCC D_8004FDCC;
extern s8 D_80062D0C;
extern s32 D_8004FC18;
extern Rec624F8 D_800624F8[];
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
extern s32 func_80039334(s16, s16, s16, u16, u16);
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
extern s32 ResetGraph(s32);
extern DispEnv *PutDispEnv(DispEnv *);
extern DispEnv D_80061968;
extern s32 D_80049060;
extern s8 D_80049071[];
extern BlkFill618D0 D_800618D0[];
extern void Cd_ReadFileAsync(s32, s32);
extern void SsSepStop(s16, s16);
extern void func_80032844(s16);
extern void SsVabClose(s16);
extern char D_800103F8[];
extern void Gpu_RestoreExequeCb(void);
extern void Gpu_RestoreExequeCb(void);
extern s32 D_80062F70;
extern s32 D_80062F74;
extern void set_alarm(void);
extern s32 D_80041570[][8];
extern s32 D_800415F0[][8];
extern Mode5CCF8 D_8005CCF8;
extern s32 *D_80049028;
extern s32 *D_8004902C;
extern s32 *D_80049030;
extern s32 *D_80049034;
extern Prm1C D_80040F64;
extern s32 func_8001E704(s32 id);
extern s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1);
extern void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2);
extern void GsInitCoordinate2(Coord1F668 *, Coord1F668 *);
extern s16 D_8005E6E4;
extern void Item_SortList(void);
extern void func_80066F34(s32, s32);
extern s32 D_80048E88;
extern s32 D_80048E68;
extern s32 D_80048E6C;
extern s32 D_80048E58;
extern s32 D_80048E60;
extern s32 func_8002533C(Obj25FBC *);
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
extern s8 *strcat(s8 *, s8 *);
extern s32 open(u8 *, s32);
extern s32 MemCardSync(s32 wait, s32 *a1, s32 *a2);
extern void Card_ClearEvents(void);
extern s32 D_80062F90;
extern void Pad_SendInfoCmd(Obj25FBC *a0);
extern void Pad_CmdConfigMode(Actor *arg0, u8 arg1);
extern void (*D_80048E1C)(Obj25FBC *);
extern Flags506C0 *D_800506C0;
extern s32 D_800506DC;
extern Obj50720 *D_80050720;
extern char D_8001021C[];
extern char D_8001023C[];
extern char D_80048EC8[];
extern u16 D_80048F90[][2];
extern void GPU_cw(s32);
extern s16 D_800624D0;
extern s16 D_800624D2;
extern s32 D_80061C48;
extern s32 D_80060054;
extern s32 func_80013854(Part28 *, s32, s32);
extern u16 D_80040F98[];
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
extern void Gfx_LoadTexSlotImage(Elem20 *);
extern s32 Pad_ParseInfoReply(Obj25FBC *);
extern s32 D_80061C44;
extern void _SsVmFlush(void);
extern void _SsSndCrescendo(s16, s16);
extern void _SsSndTempo(s16, s16);
extern void _SsSndPause(s32 a0, s16 a1);
extern void _SsSndReplay(s16 a0, s16 a1);
extern void _SsSndStop(s32 arg0, s32 arg1);
extern void func_80031D74(s16, s16);
extern s32 Math_CycleRange(s32, s32, s32, s32);
extern s32 D_80050790;
extern s32 Snd_CurrentId;
extern s32 Snd_SavedId;
extern Obj50720 *D_80050720;
extern s32 D_800506FC;
extern s32 D_80050778;
extern s32 D_8005077C;
extern s32 D_80050784;
extern Blk22E60 *D_80050788;
extern s32 D_80050948[];
extern s32 D_8005075C;
extern s32 D_80040E68[];
extern u8 *D_80010000[];
extern void Snd_StopById(s32);
extern void Snd_StopById(s32);
extern void func_80035C4C(s16 a0, s16 a1, s16 a2, s16 a3);
extern void SsSepPlay(s16, s16, s8, s16);
extern void SsUtAllKeyOff(s32);
extern Halves D_80050704;
extern Halves D_80050708;
extern s32 D_80050750;
extern s32 Cd_GetFileSectors(s32 arg0);
extern Tbl50724 D_80050724[];
extern s32 D_8005078C;
extern s32 D_8005072C;
extern Halves D_80050700;
extern s32 Item_Use(s32, s32, s32, s32);
extern u8 *D_8005076C;
extern u8 *D_80050770;
extern u8 *D_8005076C;
extern void func_80015298(Actor *, s32);
extern u8 *D_8005076C;
extern char D_80010334[];
extern s32 D_80048FBC;
extern u32 D_80048FD0;
extern Halves D_8005070C;
extern void func_80014F78(Actor *);
extern void func_800153F4(Actor *, s32);
extern s32 D_80050764;
extern s32 D_8005F788[];
extern s32 Digi_CountByState(s32 mode);
extern void Gfx_FadeInFromBlack(s32 arg0);
extern void Text_SetColor(s32 a0, s32 a1);
extern Halves D_80050714;
extern void func_80019614(Actor194C8 *, s32);
extern s32 func_8001204C(s32, s32, s32, s32);
extern s32 Item_ApplyToDigi(s32, s32, s32, s32);
extern s32 Item_UseStatBoost(s32, s32, s32, s32);
extern s32 Item_UseRecoverAll(s32, s32);
extern Cd4FC48 D_8004FC48;
extern s32 Snd_TicksPerSec;
extern s16 D_80040DAC[];
extern Obj50720 *D_80050720;
extern Rec41194 *D_80041194[];
extern s32 D_800411FC[3];
extern s32 Cd_GetFileState(s32 arg0);
extern s32 Cd_GetFileSync(s32 arg0);
extern void Cd_LockFile(s32 a0);
extern void Cd_UnlockFile(s32 a0);
extern s32 Mem_GetOffsetEntry(s32 arg0, s32 *arg1);
extern s16 SsVabOpenHead(s32 arg0, s16 arg1);
extern s16 SsVabTransBody(s32 a0, s16 id);
extern s16 SsVabTransCompleted(s16 a0);
extern s16 SsSepOpen(s32, s16, s32);
extern s16 D_80062D2C[];
extern u16 D_8004FC24[];
extern void _SsVmInit(s32);
extern s16 D_80062CFA;
extern Rec62D08 *D_80062CB8[];
extern s32 D_80062C70[];
extern Ent62CFC *D_80062C30[];
extern s32 D_80062D04;
extern void Mem_Zero(void *a0, s32 a1);
extern s32 get_alarm(void);
extern void ApplyMatrixSV(void *, SVec1D104 *, DVec1D104 *);
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
extern void GsSetOffset(s32, s32);
extern u8 func_8001D934(void);
extern s32 func_8001D958(void);
extern s32 func_8001D980(void);
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
extern u16 D_80040F40[];
extern Hdr3AD44 D_80062DE0;
extern u16 D_80062A48[];
extern u8 D_80062A28[];
extern u8 D_80062D48;
extern s32 D_80062D10;
extern void SpuSetVoiceAttr(VAttr36C54 *);
extern void _SsVmKeyOffNow(s32);
extern s32 D_800506D0;
extern s32 D_8004E9E0[];
extern Dma4FBF4 *D_8004FBF4;
extern char D_80010A04[];
extern char D_80010A20[];
extern s32 _SsVmKeyOn(s16, s16, s16, u16, u16, u16);
extern s32 _SsVmKeyOff(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 _SsVmAlloc(s32);
extern void _SsVmDoAllocate(void);
extern u16 note2pitch(void);
extern void func_80037D64(u8);
extern u8 _SsVmSelectToneAndVag(u8 *idx, u8 *val);
extern char D_800103AC[];
extern u8 D_8004900C[];
extern Rng48FE4 D_80048FE4[][5];
extern s32 GetVideoMode(void);
extern s32 SpuSetNoiseClock(s32);
extern s32 D_80040E38[];
extern s32 D_80040E44[];
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
extern s32 strlen(s8 *);
extern s32 _SsVmKeyOn(s16 a0, s16 a1, s16 a2, u16 a3, u16 arg4, u16 arg5);
extern s8 D_80062D1F;
extern u16 D_80062EE8[];
extern u16 D_80050298[];
extern u16 D_800502B0[];
extern void func_8003F760(s32 *a0, s32 a1, s32 a2);
s32 firstfile();
extern s32 strcmp(s8 *a, s8 *b);
extern Stat48E90 *D_80048E00;
extern s32 D_80048E70[];
extern s32 func_8002A054(s32, char *, char *);
extern s32 D_80048E94;
extern s32 Pad_SioExchangeByte(Ent266D0 *, s32);
extern s32 *D_8004FE2C;
extern s32 *D_8004FE30;
extern s32 *D_8004FE34;
extern s32 D_800506D8;
extern Mat1F668 D_80061A28;
extern s32 Item_GetBagCapacity(void);
extern s32 Item_GetIdAtIndex(s32 a0);
extern s32 func_8001E0C0(s32 id);
extern char D_80010A34[];
extern TextOp D_80061BB0[37];
extern s32 _SsInitSoundSeq(s16, s16, s16, s32);
extern s32 D_8004FE4C;
extern u32 D_8004FE54;
extern u32 D_8004FE58;
extern Str3F518 D_80010D38;
extern u32 D_80060060[];
extern u32 D_80060088[];
extern void _cwc(s32 arg0);
extern s32 _param(s32 arg0);
extern s32 D_80048E54;
extern void (*D_80048E48)(void);
extern void (*D_80048E44)(void);
extern s32 Pad_SioExchangeByte();
extern Obj25FBC *D_80048E4C;
extern s32 (*D_80048E34)(void);
extern void func_800260C8(Actor *a);
extern s32 func_80026170();
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
extern s32 func_800401E4();
extern s32 Card_EventToMcErr(s32 a0);
extern u8 *bzero(u8 *s, s32 n);
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
extern s32 func_80025FF4(Obj25FBC *a0, s32 a1);
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
extern s32 func_80024960(Ent266D0 *, s32);
extern s32 (*D_80048E3C)(Actor *);
extern void (*D_80048E38)(Obj25FBC *);
extern u8 D_8005FFB8[];
extern u8 D_80060000[];
extern void func_8002485C(s32 code);
extern void Pad_ResetPortState(Obj25FBC *a0);
extern s32 func_80024950(Actor *arg0);
extern void Pad_AllocActPower(Obj25FBC *a0);
extern u8 *Pad_GetPortBlock(s32 arg0);
extern s32 func_80024CB8(Obj25FBC *a0);
extern void func_80024DC8(Obj25FBC *a0);
extern s32 func_80025114(Obj25FBC *p);
extern volatile s8 D_80062D27;
extern u8 D_80050760;
extern s32 D_80049040;
extern s32 ResetRCnt(s32 arg0);
extern s32 SetRCnt(s32 arg0, s32 arg1, s32 arg2);
extern void _SsTrapIntrVSync(void);
extern void _SsSeqCalledTbyT_1per2(void);
extern char D_800106F4[];
extern volatile Reg2EC0C *D_8004E68C;
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
extern s32 nextfile(Ent3EF1C *);
extern char D_800108EC[];
extern char D_800108F4[];
extern char D_80010904[];
extern u8 D_8004E6E0[];
extern CdTbl4E80C D_8004E80C;
extern Mat1F668 D_800619A8;
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
extern Blk22E60 *D_800506F8[];
extern s32 D_80050730;
extern s32 D_80050738;
extern void Sys_VSyncHandler(void);
extern void func_8003D4A4(void);
extern Pair61900 D_80040EFC[];
extern ObjC0E4 D_80061A08;
extern ObjC0E4 D_80061A48;
extern ObjC0E4 D_800619E8;
extern void GsGetLw();
extern Halves D_8005074C;
extern Pair54 D_80040D70[][3];
extern u8 D_800632E0[0x80];
extern McDir401E4 D_800630A0[15];
extern s32 D_80063280[20];
extern Rev3B994 D_800503E8[];
extern void Mem_CopyWords(s32 *dst, s32 *src, u32 count);
extern void func_8002EC0C(s32 ch, u32 madr, s32 hi, s32 lo, u32 chcr, u8 mode);
extern char D_80010404[];
extern char D_80010418[];
extern char D_80010420[];
extern Pair61900 D_800618F8;
extern Pair61900 D_800618FC;
extern s32 D_80061988;
extern Rec624F8 D_800624F0[];
extern Rec624F8 D_800624FA[];
extern Rec624F8 D_800624FC[];
extern Rec624F8 D_800624FE[];
extern Rec624F8 D_80062500[];
extern s8 D_800632D0[16];
extern char D_80010D64[];
extern s32 _card_read(s32, s32, u8 *);
extern void func_80017214(Actor *);
extern s32 D_80049044;
extern u16 D_80062D60[];
extern Box16198 D_80040F1C;
extern Pair61900 D_80040F28[];
extern Halves D_80040F38[];
extern Halves D_80050710;
extern void func_80017214(Actor *a0);
extern s32 D_8005F70C;
extern Coord1F668 *D_80061A68[];
extern Coord1F668 *D_80061A64[];
extern void (*D_80061BF4[])(s16, s16, s16, Rec62D08, s32, s32);
extern SVec1F668 D_80050744;
extern s32 Gfx_IsOriginOffscreen(void);
extern s32 Gfx_ProjectModelVerts(Vert6Pmv *, Obj21ABC *, s32);
extern void Gfx_CalcNormalColors(Vert6Pmv *, Obj21ABC *);
extern void Gfx_AddQuadsGT4(QuadGT4_2130C *, s32, Sub3C *, s32);
extern void func_80020FD0(TriGT3_20FD0 *, s32, Sub3C *, s32);
s16 _SsVmPBVoice(s16, s16, s16, s16, u16);
void Save_ClearEventFlags(void);

ASM_SOURCE("src/main/asm/crt0", func_80010D6C);

void func_80010D74(void) {
}

ASM_SOURCE("src/main/asm/crt0", Sys_Start);

void Task_RunChildren(Obj10E38 *a0) {
    s32 n = a0->field_30;
    s32 *arr = a0->field_34;
    s32 i;

    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[i] = Task_Run(arr[i]);
        }
    }
}

s32 Task_TryRun(void *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return Task_Run(arg0);
}

void Task_Destroy(s32 *arg0) {
    if (*arg0 != 0) {
        Task_SetState0(*arg0, 3);
        do {
            *arg0 = Task_TryRun(*arg0);
        } while (*arg0 != 0);
        *arg0 = 0;
    }
}

ASM_SOURCE("src/main/asm/game", Task_Run);

void Task_Create(u32 id, s32 *slot, s32 arg) {
    ObjDesc *d;
    Buf111D4 *o;

    if (*slot != 0) {
        Task_Destroy(slot);
    }
    d = D_80040D50[id >> 8][id & 0xFF];
    o = Task_AllocWithBuffers(d->field_10, d->field_14);
    o->field_0 = id;
    o->field_24 = 0;
    if (arg != 0 && d->init != 0) {
        d->init(o, arg);
    }
    *slot = (s32)o;
}

void func_80011140(void) {
    Task_NextState0();
}

void func_80011160(void) {
}

void func_80011168(void) {
}

void Task_DefaultDestroy(Actor *arg0) {
    Task_Free();
}

void Task_ClearList(void) {
    s16 i;
    for (i = 0; i < 100; i++) {
        Task_List.entries[i] = 0;
    }
    Task_List.count = 0;
}

Buf111D4 *Task_Alloc(void) {
    Buf111D4 *s0 = (Buf111D4 *)Mem_Alloc(0x40, 2);
    s32 i;
    Mem_Zero(s0, 0x40);
    for (i = 0; i < 0x64; i++) {
        if (Task_List.entries[i] == 0) {
            Task_List.entries[i] = (s32)s0;
            break;
        }
    }
    if (Task_List.count < i + 1) {
        Task_List.count = i + 1;
    }
    return s0;
}

void Task_Free(arg0)
Act125C *arg0;
{
    Obj125C *sub;
    s32 i;
    s32 *p;
    s32 j;

    if (arg0->field_30 != 0) {
        s32 *fp = arg0->field_34;
        i = 0;
        if (arg0->field_30 > 0) {
            p = fp;
            do {
                Task_Destroy(p);
                p++;
            } while (++i < arg0->field_30);
            fp = arg0->field_34;
        }
        Mem_Free((ActorWork *)fp);
    }

    if (arg0->field_2C != 0) {
        Mem_Free(arg0->field_2C);
    }
    if (arg0->field_38 != 0) {
        Mem_Free(arg0->field_38);
    }

    sub = arg0->field_3C;
    if (sub != 0) {
        if (sub->field_6C != 0) {
            Mem_Free(sub->field_6C);
        }
        if (sub->field_70 != 0) {
            Mem_Free(sub->field_70);
        }
        i = sub->field_74 != 0;
        if (i) {
            Mem_Free(sub->field_74);
        }
        if (sub->field_78 != 0) {
            Mem_Free(sub->field_78);
        }
        Mem_Free((ActorWork *)arg0->field_3C);
    }

    for (j = 0; j < 100; j++) {
        if (Task_List.entries[j] == (s32)arg0) {
            Task_List.entries[j] = 0;
            break;
        }
    }

    Mem_Free((ActorWork *)arg0);
}

Buf111D4 *Task_AllocWithBuffers(s32 a0, s32 a1) {
    Buf111D4 *s0 = Task_Alloc();
    if (a0 != 0) {
        s32 x = Mem_Alloc(a0, 2);
        s0->field_2C = x;
        Mem_Zero((void *)x, a0);
    }
    if (a1 != 0) {
        s32 y = Mem_Alloc(a1, 2);
        s0->field_34 = y;
        Mem_Zero((void *)y, a1);
        s0->field_30 = a1 >> 2;
    }
    return s0;
}

Ent11440 *Task_FindNext(void) {
    s32 i;
    Ent11440 *e;

    i = Task_FindFilter.field_C;
    while (i < Task_List.count) {
        e = (Ent11440 *)Task_List.entries[i];
        if (e != 0
            && (Task_FindFilter.field_0 == -1 || e->field_0 == Task_FindFilter.field_0)
            && (Task_FindFilter.field_4 == -1 || e->field_4 == Task_FindFilter.field_4)
            && (Task_FindFilter.field_8 == -1 || e->field_8 == Task_FindFilter.field_8)) {
            Task_FindFilter.field_C = i + 1;
            return (Ent11440 *)Task_List.entries[i];
        }
        i++;
    }
    return 0;
}

extern Ent11440 *Task_FindNext(void);

Ent11440 *Task_FindFirst(s32 arg0, s32 arg1, s32 arg2) {
    Task_FindFilter.field_0 = arg0;
    Task_FindFilter.field_4 = arg1;
    Task_FindFilter.field_8 = arg2;
    Task_FindFilter.field_C = 0;
    return Task_FindNext();
}

void Task_NextState0(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
    arg0->field_14 = 0;
    arg0->field_10++;
}

void Task_NextState1(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
    arg0->field_14++;
}

void Task_NextState2(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18++;
}

void Task_NextState3(Actor *arg0) {
    arg0->field_20 = 0;
    arg0->field_1C++;
}

void Task_NextState4(Actor *arg0) {
    arg0->field_20++;
}

void Task_SetState0(Actor *arg0, u32 arg1) {
    arg0->field_10 = arg1 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
    arg0->field_14 = 0;
}

void Task_SetState1(Actor *arg0, u32 arg1) {
    arg0->field_14 = arg1 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
}

void Task_SetState01(Actor *arg0, u32 arg1, u32 arg2) {
    arg0->field_10 = arg1 & 0xFF;
    arg0->field_14 = arg2 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
    arg0->field_18 = 0;
}

void Task_SetState2(Actor *arg0, u32 arg1) {
    arg0->field_18 = arg1 & 0xFF;
    arg0->field_20 = 0;
    arg0->field_1C = 0;
}

void Task_SetState3(Actor *arg0, u32 arg1) {
    arg0->field_1C = arg1 & 0xFF;
    arg0->field_20 = 0;
}

void Task_SetState4(Actor *arg0, u32 arg1) {
    arg0->field_20 = arg1 & 0xFF;
}

void func_80011644(void) {
    s32 *p;
    s32 i;

    p = D_80050948;
    Cd_QueueFile(0x19A);
    for (i = 0; i < D_8005075C; i++) {
        Cd_QueueFile(*p);
        p++;
    }
}


void func_800116A8(void) {
}

void func_800116B0(Actor *arg0, s32 *arg1) {
    ActorWork *w = arg0->work;
    w->field_0 = arg1[0];
    w->field_4 = arg1[1];
}

void func_800116CC(Actor *a0) {
    Wk116CC *w = (Wk116CC *)a0->work;
    s32 v;

    switch (a0->field_10) {
    case 0:
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
            break;
        case 1:
            return;
        }
        if (w->field_10 == 0) {
            switch (w->field_8) {
            case 0:
                v = 0xE;
                goto set;
            case 1:
                v = 0xD;
                goto set;
            case 2:
                v = 0xB;
            set:
                w->field_C = v;
                w->field_14 = 0;
                w->field_10 = 0;
                break;
            default:
                w->field_C = 7;
                w->field_10 = 2;
                w->field_14 = w->field_8 - 3;
                break;
            }
            w->field_8++;
            if (w->field_8 == 0x12) {
                w->field_8 = 0xF;
            }
        } else {
            w->field_10--;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 1:
            w->field_C = 0xD;
            w->field_14 = 0;
            a0->field_14++;
            break;
        case 2:
            w->field_C = 0xE;
            w->field_14 = 0;
            a0->field_14++;
            break;
        case 0:
        default:
            w->field_C = 0xB;
            w->field_14 = 0;
            a0->field_14++;
            break;
        case 3:
            Task_SetState0(a0, 3);
            break;
        }
        break;
    }
}

void func_80011854(Actor *a0) {
    ActorWork *w = a0->work;
    Part11854 *e;
    Part11854 *q;
    Pt11BEC pos;
    Pt11BEC clut;
    Tex11BEC tex;
    s32 s;
    s32 i;
    s32 j;
    u8 u;
    u8 v;
    Actor *g;
    Ft4_11854 *p;

    e = (Part11854 *)Cd_GetFileEntry(0x3120002);
    for (q = e; q->field_0 != 0; q++) {
        if (q->field_1C & w->field_C) {
            q->field_F = 0;
        } else {
            q->field_F = 1;
            q->field_C = w->field_14;
            if (w->field_4 != 0) {
                q->field_10 = -0x1000;
                q->field_E = 0;
            } else {
                q->field_10 = 0x1000;
                q->field_E = 1;
            }
        }
    }
    Gfx_DrawParts((s32)e);
    Gfx_FindOrLoadImageSlot(w->field_0, &tex, &pos, &clut);
    s = 1;
    if (w->field_4 != 0) {
        s = -1;
    }
    g = &D_8005F770;
    p = (Ft4_11854 *)g->work;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            p->c.rgb = D_8005074C;
            p->tag.len = 9;
            p->c.b.code = 0x2C;
            p->x0 = D_80040D70[j][i].field_0 * s;
            p->x1 = D_80040D70[j][i + 1].field_0 * s;
            p->x2 = D_80040D70[j + 1][i].field_0 * s;
            p->x3 = D_80040D70[j + 1][i + 1].field_0 * s;
            p->y0 = D_80040D70[j][i].field_2;
            p->y1 = D_80040D70[j][i + 1].field_2;
            p->y2 = D_80040D70[j + 1][i].field_2;
            p->y3 = D_80040D70[j + 1][i + 1].field_2;
            u = pos.x + (tex.field_C + i * 20);
            p->u0 = p->u2 = u;
            p->u1 = p->u3 = u + 20;
            v = pos.y + j * 20;
            p->v0 = p->v1 = v;
            p->v2 = p->v3 = v + 20;
            p->tpage = tex.field_10;
            p->clut = ((tex.field_1C + clut.y) << 6) | (((tex.field_18 + clut.x) >> 4) & 0x3F);
            p->tag.addr = ((PTag11854 *)g->field_138[0])->addr;
            ((PTag11854 *)g->field_138[0])->addr = (u32)p;
            p++;
        }
    }
    D_8005F79C = (s32)p;
}

void func_80011B58(Actor *arg0, s32 arg1) {
    arg0->work->field_0 = arg1;
}

void Gfx_TexSlotTaskInit(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->field_10 == 0) {
        w->field_0 = Gfx_ReserveTexSlot();
        Task_NextState0(arg0);
    }
}

void Gfx_TexSlotTaskKill(Actor *arg0) {
    Gfx_ReleaseTexSlot(arg0->work->field_0);
    Task_DefaultDestroy(arg0);
}

void Gfx_FindOrLoadImageSlot(s32 id, Tex11BEC *out, Pt11BEC *pos, Pt11BEC *clut) {
    Tbl11BEC *t;
    s32 i;
    s32 k;
    s32 *p;
    Rect2AB54 r;
    Rect2AB54 r2;

    t = (Tbl11BEC *)Task_FindFirst(10, -1, -1)->field_2C;
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == id) {
            goto found;
        }
    }
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == 0) {
            goto load;
        }
    }
    {
        s32 m = 0;
        s32 bi = 0;
        for (i = 0; i < 18; i++) {
            if (m < t->slot[i].t) {
                m = t->slot[i].t;
                bi = i;
            }
        }
        i = bi;
    }
load:
    for (k = 0; D_80040DAC[k] != -1; k++) {
        if (D_80040DAC[k] == id) {
            break;
        }
    }
    p = (s32 *)Cd_GetFileEntry(k + 0x3250000);
    p++;
    if (*p++ & 8) {
        r.x = t->field_0->field_18 + i / 16 * 16;
        r.y = t->field_0->field_1C + 0xF0;
        r.y += i % 16;
        r.w = 16;
        r.h = 1;
        LoadImage(&r, ((TimBlk11BEC *)p)->data);
    }
    p = (s32 *)((u8 *)p + *p);
    r2.x = t->field_0->field_18 + i % 3 * 10;
    r2.y = t->field_0->field_1C + i / 3 * 40;
    r2.w = ((TimBlk11BEC *)p)->w;
    r2.h = ((TimBlk11BEC *)p)->h;
    LoadImage(&r2, ((TimBlk11BEC *)p)->data);
    t->slot[i].id = D_80040DAC[k];
found:
    t->slot[i].t = D_8005F774;
    *out = *t->field_0;
    pos->x = i % 3 * 40;
    pos->y = i / 3 * 40;
    clut->x = i / 16 * 16;
    clut->y = i % 16 + 0xF0;
}

void func_80011F04(void) {
    s32 i;
    s32 j;
    s32 v;

    i = 0;
    j = i;
    do {
        v = D_8005071C->field_BA9[i];
        D_8005071C->field_BA9[i] = 0;
        if (v != 0) {
            D_8005071C->field_BA9[j++] = v;
        }
        i++;
    } while (i < 12);
}

s32 *Item_GetEffectRec(s32 id) {
    s32 *base = 0;
    u32 i;
    s32 key;

    if ((i = id - 0x78) < 0x10) {
        key = 0x5130000;
    } else if ((i = id - 0xD0) < 0x1A) {
        key = 0x5130001;
    } else if ((i = id - 0x97) < 0xF) {
        key = 0x5130002;
    } else {
        goto end;
    }
    base = (s32 *)Cd_GetFileEntry(key);
    id = i;
end:
    if (base != 0) {
        base = &base[id];
    }
    return base;
}

s32 func_80011FE4(s32 arg0) {
    s32 r = 0;
    if (func_8001E134() != 0) {
        u8 *p = Item_GetEffectRec(arg0);
        if (p != 0) {
            u8 b = *p;
            if (b != 0) {
                if (b < 5) {
                    r = 1;
                } else {
                    r = 2;
                }
            }
        }
    }
    return r;
}

s32 func_8001204C(s32 a0, s32 a1, s32 a2, s32 a3) {
    Rec11F5C *rec;
    s32 r;
    s16 *p;
    s16 *q;
    u8 v;
    s32 c;
    s32 i;
    s32 j;
    s32 best;
    s32 max;
    s32 n;
    s32 cnt;

    rec = (Rec11F5C *)Item_GetEffectRec(a0);
    r = 0;
    switch (rec->field_1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    default:
        if (rec->field_1 == 0) {
            p = &D_80050720->field_24;
            q = &D_80050720->field_26;
        } else {
            p = &D_80050720->field_28;
            q = &D_80050720->field_2A;
        }
        if (*p >= *q) {
            return r;
        }
        *p = (*q < *p + rec->field_2) ? *q : (s16)(*p + rec->field_2);
        r = 1;
        break;
    case 0xB:
        if (func_80022518(a2) < 0) {
            func_8002254C(a2, 0);
            r = 1;
        }
    case 0xC:
    case 0xD:
    case 0xE:
        c = D_8005071C->field_BA5[rec->field_1 - 0xC];
        v = c;
        if (c != 0) {
            r = 2;
            if (rec->field_2 >= v) {
                D_8005071C->field_BA5[rec->field_1 - 0xC] = 0;
                r = 1;
            }
        }
        break;
    case 0xF:
        if (D_8005071C->field_BA8 != 0) {
            best = -1;
            max = 0;
            for (j = 0; j < D_8005071C->field_BA8; j++) {
                v = D_8005071C->field_BA9[j];
                if (rec->field_2 >= v && max < v) {
                    best = j;
                    max = v;
                }
            }
            r = 1;
            if (best == -1) {
                goto none;
            }
            D_8005071C->field_BA8--;
            D_8005071C->field_BA9[best] = 0;
            func_80011F04();
            D_80050760 = max;
            break;
        }
        break;
    case 0x10:
        if (D_8005071C->field_BA5[0] + D_8005071C->field_BA5[1] + D_8005071C->field_BA5[2] + D_8005071C->field_BA8 != 0) {
            cnt = 0;
            for (i = 0; i < 3; i++) {
                if (D_8005071C->field_BA5[i] != 0 && rec->field_2 >= D_8005071C->field_BA5[i]) {
                    D_8005071C->field_BA5[i] = 0;
                    cnt++;
                }
            }
            n = D_8005071C->field_BA8;
            for (i = 0; i < n; i++) {
                if (rec->field_2 >= D_8005071C->field_BA9[i]) {
                    D_8005071C->field_BA9[i] = 0;
                    D_8005071C->field_BA8--;
                    cnt++;
                }
            }
            func_80011F04();
            r = 1;
            if (cnt == 0) {
            none:
                r = 2;
            }
        }
        break;
    }
    return r;
}


s32 Item_ApplyToDigi(s32 a0, s32 a1, s32 a2, s32 a3) {
    Obj1236C *o = (Obj1236C *)a3;
    Rec11F5C *r = (Rec11F5C *)Item_GetEffectRec(a0);
    s16 *cur;
    s16 *lim;
    s16 step;

    if (r->field_0 == 3 && r->field_2 != ((s32 (*)(s32))func_8001D934)(o->field_1)) {
        return 0;
    }
    if (r->field_1 == 3) {
        if (o->field_16 != 0) {
            return 0;
        }
        o->field_16 = o->field_14;
        return 1;
    }
    if (o->field_16 == 0) {
        return 0;
    }
    if (r->field_1 == 0) {
        cur = &o->field_16;
        lim = &o->field_14;
    } else {
        cur = &o->field_1A;
        lim = &o->field_18;
    }
    if (*cur == *lim) {
        return 0;
    }
    if (r->field_0 == 3) {
        step = *lim - *cur;
    } else {
        step = r->field_2;
    }
    *cur = (*lim < *cur + step) ? *lim : (s16)(*cur + step);
    return 1;
}

s32 Item_UseStatBoost(s32 a0, s32 a1, s32 a2, s32 a3) {
    Dg12490 *dg = (Dg12490 *)a3;
    Rec12490 *rec;
    s16 *p;
    s32 d;
    s32 n;
    s32 inc;

    rec = (Rec12490 *)Item_GetEffectRec(a0);
    if (dg->field_16 == 0) {
        return 0;
    }
    switch (rec->field_1) {
    case 9:
        d = rec->field_2;
        if (d > 0 && d + dg->field_E >= 100) {
            return 0;
        }
        if (d < 0 && d + dg->field_E < 0) {
            return 0;
        }
        dg->field_E += rec->field_2;
        return 1;
    case 10:
        if (dg->field_10 == 99999999) {
            return 0;
        }
        d = dg->field_10 += rec->field_2;
        if (d > 99999999) {
            d = 99999999;
        }
        dg->field_10 = d;
        return 1;
    case 4:
    default:
        p = &dg->field_14;
        break;
    case 5:
        p = &dg->field_18;
        break;
    case 6:
        p = &dg->field_1C;
        break;
    case 7:
        p = &dg->field_1E;
        break;
    case 8:
        p = &dg->field_20;
        break;
    }
    if (*p == 999) {
        return 0;
    }
    n = (Rand_Next() & 0xFFF) * 100 / 0x21000;
    inc = 3;
    if (n < 3) {
        inc = n + 1;
    }
    n = inc;
    *p = (*p + n < 1000) ? (s16)(*p + n) : 999;
    return 1;
}


s32 Item_UseRecoverAll(s32 a0, s32 a1) {
    ElmE620 *e = D_80050720->elems;
    Cfg12640 *c = (Cfg12640 *)Item_GetEffectRec(a0);
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x24; i++, e++) {
        s16 cur;
        s16 max;
        if (e->field_0 < 2) continue;
        cur = e->field_16;
        if (cur == 0) continue;
        if (c->field_1 == 0 || c->field_1 == 2) {
            max = e->field_14;
            if (cur != max) {
                if (c->field_2 == 0) {
                    e->field_16 = max;
                } else {
                    e->field_16 = max < cur + c->field_2 ? max : e->field_16 + c->field_2;
                }
                n++;
            }
        }
        if ((u8)(c->field_1 - 1) < 2) {
            cur = e->field_1A;
            max = e->field_18;
            if (cur != max) {
                if (c->field_2 == 0) {
                    e->field_1A = max;
                } else {
                    e->field_1A = max < cur + c->field_2 ? max : e->field_1A + c->field_2;
                }
                n++;
            }
        }
    }
    return n != 0;
}


s32 Item_Use(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p;
    s32 r;

    p = (u8 *)Item_GetEffectRec(a0);
    r = 0;
    if (p != NULL) {
        switch (*p) {
        case 5:
            r = func_8001204C(a0, a1, a2, a3);
            break;
        case 1:
        case 3:
            r = Item_ApplyToDigi(a0, a1, a2, a3);
            break;
        case 4:
            r = Item_UseStatBoost(a0, a1, a2, a3);
            break;
        case 2:
            r = Item_UseRecoverAll(a0, a1);
            break;
        }
        if (r != 0) {
            Item_RemoveFromBag(a1);
        }
    }
    return r;
}


u8 Menu_NameEntryGetChar(Actor *a0) {
    ActorWork *w;
    s32 base;
    s32 k;
    u8 *p;

    w = a0->work;
    base = w->field_C;
    base += 0x1FD00D4;
    k = w->field_2C >= 10;
    if (w->field_2C >= 5) {
        k++;
    }
    p = (u8 *)Cd_GetFileEntry(base + k);
    return p[w->field_2E * D_80040E38[k] + w->field_2C - D_80040E44[k]];
}


void func_8001291C(Actor *a, Pair1291C *v) {
    ActorWork *w = a->work;

    *(Pair1291C *)w = *v;
    switch (w->field_0) {
    case 0:
    default:
        w->field_8 = 0xD;
        break;
    case 1:
        w->field_8 = 5;
        break;
    case 2:
        w->field_8 = 7;
        break;
    }
}

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s16 field_2C;
    /* 0x2E */ s16 field_2E;
} Wk12974;

typedef struct {
    /* 0x00 */ u8 name[0x5C];
} Nm12974;

extern u8 D_8005E634[];
extern u8 D_8005E6F1[];
extern Nm12974 D_8005E750[];
extern u16 D_8005F72C;
extern u8 Menu_NameEntryGetChar(Actor *);
extern void Snd_SaveCurrentId(void);
extern void Snd_RestoreSavedId(void);

void Menu_NameEntryTask(Actor *a0) {
    Wk12974 *w = (Wk12974 *)a0->work;
    u8 *p;
    u8 *src;
    s32 i;
    u16 k;
    Arg1BC24 arg;
    Arg1BC24 arg2;

    switch (w->field_0) {
    default:
    case 0:
        p = D_8005E750[w->field_4].name;
        break;
    case 1:
        p = D_8005E634;
        break;
    case 2:
        p = D_8005E6F1;
        break;
    }
    switch (a0->field_10) {
    case 0:
        Mem_FillWordsNeg1(&w->field_10, 5);
        for (i = 0; i < w->field_8; i++) {
            p[i] = 0xFD;
        }
        p[i] = 0xFF;
        switch (w->field_0) {
        default:
        case 0:
            src = Digi_GetDefaultName(D_8005E620.elems[w->field_4].field_1);
            for (i = 0; i < 14; i++) {
                if (src[i] == 0xFF) {
                    break;
                }
                p[i] = src[i];
            }
            break;
        case 1:
            p[0] = 0xA;
            p[1] = 0x2E;
            p[2] = 0x2C;
            p[3] = 0x35;
            p[4] = 0x24;
            break;
        case 2:
            p[0] = 0x10;
            p[1] = 0x38;
            p[2] = 0x31;
            p[3] = 0x31;
            p[4] = 0x28;
            p[5] = 0x35;
            break;
        }
        Snd_SaveCurrentId();
        Snd_PlayById(0x22, 1);
        w->field_C = 6;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            Text_Close(&w->field_10);
            Text_Close(&w->field_14);
            Text_Close(&w->field_18);
            Text_Close(&w->field_20);
            arg.field_14 = (s32)Cd_GetFileEntry(w->field_C + 0x1FD00D4);
            arg.field_8 = 0x28;
            arg.field_A = 0x42;
            arg.field_C = 0x13;
            arg.field_0 = 1;
            arg.field_4 = 0;
            arg.field_10 = 0x12;
            arg.field_18 = 0;
            Text_Open(&w->field_10, &arg);
            arg.field_14 = (s32)Cd_GetFileEntry(w->field_C + 0x1FD00D5);
            arg.field_8 += 0x65;
            Text_Open(&w->field_14, &arg);
            arg.field_14 = (s32)Cd_GetFileEntry(w->field_C + 0x1FD00D6);
            arg.field_8 += 0x65;
            Text_Open(&w->field_18, &arg);
            arg.field_8 = 0x26;
            arg.field_14 = (s32)p;
            arg.field_A = 0x20;
            arg.field_C = 0;
            arg.field_10 = 0;
            arg.field_18 = 0;
            Text_Open(&w->field_20, &arg);
            switch (w->field_0) {
            default:
            case 0:
                arg2.field_14 = (s32)Digi_GetDefaultName(D_8005E620.elems[w->field_4].field_1);
                break;
            case 1:
                arg2.field_14 = (s32)Cd_GetFileEntry(0x1FD0074);
                break;
            L34:
                w->field_2C = 10;
                w->field_2E = 7;
                Snd_PlayById(0x12, 0);
                goto keys_done;
            Lnone:
                Snd_PlayById(0x10, 0);
                goto keys_done;
            case 2:
                arg2.field_14 = (s32)Cd_GetFileEntry(0x1FD0072);
                break;
            }
            arg2.field_4 = 4;
            arg2.field_8 = 0x23;
            arg2.field_0 = 0;
            arg2.field_A = 0x13;
            arg2.field_C = 0;
            arg2.field_10 = 0;
            arg2.field_18 = 0;
            Text_Open(&w->field_1C, &arg2);
            Task_NextState1(a0);
        case 1:
            k = D_8005F6F0[0].field_3C;
            if (k & 0x2000) {
                if (w->field_2C != 10) {
                    if (++w->field_2C == 10) {
                        w->field_2E = 7;
                    }
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x8000) {
                if (w->field_2C != 0) {
                    w->field_2C--;
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x1000) {
                if (w->field_2E != 0) {
                    w->field_2E--;
                    if (w->field_2C == 10) {
                        w->field_2C--;
                    }
                    Snd_PlayById(0x12, 0);
                }
            } else if (k & 0x4000) {
                if (w->field_2E != 7) {
                    w->field_2E++;
                    Snd_PlayById(0x12, 0);
                }
            } else if (D_8005F6F0[0].field_20 > 0) {
                if (w->field_24 != w->field_8) {
                    w->field_24++;
                    Snd_PlayById(0x12, 0);
                }
            } else if (D_8005F6F0[0].field_28 > 0) {
                if (w->field_24 != 0) {
                    w->field_24--;
                    Snd_PlayById(0x12, 0);
                }
            } else if (D_8005F6F0[0].field_1C > 0) {
                if (w->field_24 != 0) {
                    w->field_24--;
                    p[w->field_24] = 0xFD;
                    Snd_PlayById(0xB, 0);
                }
            } else if (D_8005F6F0[0].field_34 > 0) {
                goto L34;
            } else if (D_8005F6F0[0].field_14 > 0) {
                if (w->field_2C < 10 || w->field_2E < 4) {
                    if (w->field_24 != w->field_8) {
                        p[w->field_24] = Menu_NameEntryGetChar(a0);
                        w->field_24++;
                        Snd_PlayById(0xE, 0);
                    }
                } else if (w->field_2E == 7) {
                    for (i = 0; i < w->field_8; i++) {
                        if (p[i] != 0xFD) {
                            break;
                        }
                    }
                    if (i != w->field_8) {
                        for (i = w->field_8 - 1; i >= 0; i--) {
                            if (p[i] != 0xFD) {
                                break;
                            }
                            p[i] = 0xFF;
                        }
                        Task_NextState0(a0);
                        Snd_PlayById(0xE, 0);
                    } else {
                        goto Lnone;
                    }
                }
            }
        keys_done:
            if (w->field_24 == w->field_8) {
                w->field_2C = 10;
                w->field_2E = 7;
            }
            if (D_8005F72C & 0xF000) {
                w->field_28 = 0;
            }
            break;
        }
        break;
    case 2:
        if (D_8005F788[0] != 0x500) {
            Snd_RestoreSavedId();
        }
        Text_CloseArray(&w->field_10, 5);
        Task_NextState0(a0);
        break;
    }
}


void Menu_NameEntryDrawParts(Actor *a) {
    ActorWork *w = a->work;
    Part28 *base = (Part28 *)Cd_GetFileEntry(0x1A10018);
    Part28 *p;
    s32 k;
    s32 v;
    s32 x;

    w->field_28 += D_8005F770.field_8;
    for (p = base; p->field_0 != 0; p++) {
        if (p->field_1C & 0x20) {
            v = w->field_24;
            p->field_6 = -0x48;
            p->field_4 = v * 9 - 0x71;
            if (w->field_24 == w->field_8) {
                p->field_F = 0;
            } else {
                p->field_F = 1;
            }
        } else if (p->field_1C & 0x40) {
            v = w->field_2C;
            x = -0x73;
            if (v >= 10) {
                x = -0x6D;
            }
            if (v >= 5) {
                x += 6;
            }
            p->field_4 = x + v * 19;
            p->field_6 = w->field_2E * 18 - 0x2F;
        }
        k = 0;
        if (w->field_2C >= 10 && w->field_2E >= 4) {
            k = w->field_2E - 3;
        }
        if (p->field_1C & 0x7DC) {
            p->field_F = 0;
        }
        if (!(w->field_28 & 0x10)) {
            switch (k) {
            case 0:
                if (p->field_1C & 0x40) {
                    p->field_F = 1;
                }
                break;
            case 1:
                if (p->field_1C & 0x80) {
                    p->field_F = 1;
                }
                break;
            case 2:
                if (p->field_1C & 0x100) {
                    p->field_F = 1;
                }
                break;
            case 3:
                if (p->field_1C & 0x200) {
                    p->field_F = 1;
                }
                break;
            case 4:
                if (p->field_1C & 0x400) {
                    p->field_F = 1;
                }
                break;
            }
        }
        if (w->field_0 == 0 && (p->field_1C & 4)) {
            p->field_F = 1;
        }
        if (w->field_0 == 1 && (p->field_1C & 8)) {
            p->field_F = 1;
        }
        if (w->field_0 == 2 && (p->field_1C & 0x10)) {
            p->field_F = 1;
        }
    }
    Gfx_DrawParts((s32)base);
}


void func_80013308(s32 id) {
    s32 *p;
    u8 *src;
    u8 *dst;

    if (D_800506FC != id) {
        p = &D_80040E68[id];
        D_800506FC = id;
        src = (u8 *)Cd_GetFileSync(*p);
        dst = D_80010000[0];
        memcpy(dst, src, Cd_GetFileSectors(*p) << 11);
    }
}

s32 func_80013378(void) {
    return D_800506FC;
}


extern void func_80013308(s32);
extern void Task_Create(u32, s32 *, s32);
extern s32 Snd_AnySlotLoading(void);
extern s32 D_8005F78C;

void func_80013384(Actor *a0) {
    s32 st = a0->field_10;
    s32 t = a0->u34.field_34;
    switch (st) {
    case 0:
    default:
        func_80013308((D_8005F770.field_18 >> 8) - 1);
        Task_Create(D_8005F770.field_18 & 0xFF00, t, 0);
        Task_NextState0(a0);
        break;
    case 1:
        if (D_8005F78C != 0) {
            Task_SetState0(a0, 2);
        }
        break;
    case 2:
        if (Snd_AnySlotLoading() == 0) {
            Task_SetState0(a0, 3);
        }
        break;
    }
}

void Task_DefaultDestroy2(void) {
    Task_Free();
}

void Text_OpenDesc(void *arg0, Src13470 *arg1) {
    Arg1BC24 local;
    local.field_14 = arg1->field_0;
    local.field_0 = arg1->field_10 >> 7;
    local.field_4 = arg1->field_11;
    local.field_8 = arg1->field_C;
    local.field_A = arg1->field_E;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_18 = arg1->field_10 & 0x7F;
    local.field_1C = arg1->field_4;
    local.field_20 = arg1->field_8;
    Text_Open(arg0, &local);
}

void Text_OpenPacked(void *arg0, s32 arg1, u32 arg2, Halves arg3) {
    Arg1BC24 local;
    local.field_0 = (arg2 >> 7) & 1;
    local.field_14 = arg1;
    local.field_4 = (arg2 >> 2) & 0xF;
    local.field_8 = arg3.lo;
    local.field_A = arg3.hi;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_18 = arg2 & 3;
    Text_Open(arg0, &local);
}

s32 Text_PrintIdList(s32 *a0, Key13558 *a1, u32 a2) {
    s32 n = 0;

    while (a1->key != 0) {
        n++;
        Text_OpenPacked(a0, (s32)Cd_GetFileEntry((a1->key & 0xFFF) | 0x1FD0000),
                      a2 | ((a1->key & 0xF000) >> 10), a1->h);
        a1++;
        a0++;
    }
    return n;
}

void Text_PrintList(s32 *a0, Halves *a1, s32 *a2, u32 a3) {
    while (*a2 != 0) {
        Text_OpenPacked(a0, *a2, a3, *a1);
        a2++;
        a1++;
        a0++;
    }
}

s32 func_800136A4() {
    s32 result = Text_IsFinished();
    if (result != 0) {
        result = Flag_Test(0x11) == 0 ? 1 : -1;
    }
    return result;
}

s32 Math_RampToOne(s32 arg0, s32 *arg1) {
    s32 v = *arg1 + 0x333;
    *arg1 = v;
    if (v >= 0x1000) {
        *arg1 = 0x1000;
        return 0;
    }
    return 1;
}

s32 Math_RampToZero(s32 arg0, s32 *arg1) {
    s32 v = *arg1 - 0x333;
    *arg1 = v;
    if (v <= 0) {
        *arg1 = 0;
        return 0;
    }
    return 1;
}

void Menu_SetPartsGridPos(void *arg0, s32 mask, s32 *arg2, s16 *arg3) {
    Part28 *p = arg0;
    Part28 *q = p;
    s32 x = arg3[2] + ((s16 *)arg2)[0] * arg3[4];
    s32 y = arg3[3] + ((s16 *)arg2)[1] * arg3[5];

    if (p->field_0 != 0) {
        do {
            if (q->field_1C & mask) {
                q->field_4 = x;
                q->field_6 = y;
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}


void Gfx_SetPartsPalette(Part28 *p, s32 mask, s32 v) {
    Part28 *q = p;

    if (p->field_0 != 0) {
        do {
            if (q->field_1C & mask) {
                q->field_C = v;
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}

void Menu_SetPartsPos(Part28 *p, s32 mask, u16 *xy) {
    Part28 *q = p;

    if (p->field_0 != 0) {
        do {
            if (q->field_1C & mask) {
                q->field_4 = xy[0];
                q->field_6 = xy[1];
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}

s32 func_80013854(Part28 *p, s32 mask, s32 n) {
    Part28 *q;
    s32 r = 0;

    if (n <= 0) {
        r = mask;
    } else {
        q = p;
        if (p->field_0 != 0) {
            do {
                if (q->field_1C & mask) {
                    q->field_C = (Menu_Ctx->field_4 >> 2) & 3;
                }
                p++;
                q++;
            } while (p->field_0 != 0);
        }
    }
    return r;
}

/* file-local views for Menu_MoveGridCursor */
typedef struct {
    s16 field_0;
    s16 field_2;
} Coord138C0;

typedef struct {
    s16 h[2];
} Copy138C0;

/* view of Elm6F0 that reads the 0x3C flag word unsigned */
typedef struct {
    u8 _p[0x3C];
    u16 field_3C;
    u8 _p2[0x40 - 0x3E];
} ElmFlags138C0;

s32 Menu_MoveGridCursor(s32 a0, s32 a1, s32 a2) {
    Coord138C0 *p0 = (Coord138C0 *)a0;
    Coord138C0 *p1 = (Coord138C0 *)a1;
    Copy138C0 saved;
    s32 changed;

    changed = 0;
    saved = *(Copy138C0 *)p0;

    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x8000) {
        if (p0->field_0 > 0) {
            p0->field_0 = p0->field_0 - 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x2000) {
        if (p0->field_0 < p1->field_0 - 1) {
            p0->field_0 = p0->field_0 + 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x1000) {
        if (p0->field_2 > 0) {
            p0->field_2 = p0->field_2 - 1;
            goto tail;
        }
    }
    if (((ElmFlags138C0 *)D_8005F6F0)[a2].field_3C & 0x4000) {
        if (p0->field_2 < p1->field_2 - 1) {
            p0->field_2 = p0->field_2 + 1;
        }
    }

tail:
    if (saved.h[0] != p0->field_0 || saved.h[1] != p0->field_2) {
        changed = -1;
    }
    return changed;
}

s32 Menu_MoveGridCursorP1(s32 arg0, s32 arg1) {
    return Menu_MoveGridCursor(arg0, arg1, 0);
}

s32 Menu_ScrollToShow(s32 *arg0, s32 arg1, s32 arg2) {
    s32 old = *arg0;

    if (arg2 - 1 < arg1 - old) {
        *arg0 = arg1 - (arg2 - 1);
    } else if (arg1 < old) {
        *arg0 = arg1;
    }
    return *arg0 - old;
}

s32 Menu_GridIndexColMajor(s16 *arg0, s16 *arg1) {
    return arg1[1] * arg0[0] + arg0[1];
}

s32 Menu_GridIndexRowMajor(s16 *arg0, s16 *arg1) {
    return arg1[0] * arg0[1] + arg0[0];
}

s32 Cd_GetFileEntrySubPtr(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)Cd_GetFileEntry(arg0);
    s32 r = Cd_GetFileOrNull(arg0 >> 16);
    return p[arg1] + r;
}

void Text_FormatNumber(u8 *out, s32 val, s32 width) {
    u8 buf[8];
    s32 sign = 0;
    s32 done = 0;
    s32 i;

    if (width < 0) {
        width = -width;
        sign = 1;
    }
    if (val > 99999999) {
        val = 99999999;
    }
    for (i = 0; i < width; i++) {
        u8 *p = &buf[i];
        if (!done) {
            *p = val % 10;
        } else {
            *p = 0xFD;
        }
        val = val / 10;
        done = (val == 0);
    }
    for (i = width - 1; i >= 0; i--) {
        if (sign && buf[i] == 0xFD) {
            continue;
        }
        *out++ = buf[i];
    }
    *out = 0xFF;
}

void func_80013BF8(Actor *arg0, s16 arg1) {
    arg0->work->field_30 = arg1;
}

void Menu_TopMenuTask(Actor *a0) {
    Wk13C04 *w = (Wk13C04 *)a0->work;
    s32 *slot = (s32 *)a0->u34.field_34;
    Pair54 *tbl;
    s32 v;
    s32 k;
    s32 snd;

    switch (a0->field_10) {
    case 0:
    default:
        Menu_Ctx = (Obj50768 *)Mem_Alloc(0x364, 2);
        Menu_Ctx->field_360 = 0;
        D_80050764 = 0;
        *(Layout8C *)w->field_24 = *(Layout8C *)Cd_GetFileEntry(0x5130005);
        Menu_Ctx->field_0 = 0;
        v = D_8005F788[0];
        if (v / 256 != 2) {
            switch (v) {
            default:
                Menu_Ctx->field_0 = 2;
                break;
            case 0x32D ... 0x32E:
                Menu_Ctx->field_0 = 6;
                break;
            case 0x32A ... 0x32C:
                Menu_Ctx->field_0 = 4;
                break;
            }
        } else {
            Menu_Ctx->field_0 = 1;
            if (Flag_Test(0x67) == 0) {
                Menu_Ctx->field_0 |= 8;
            }
        }
        if (Digi_CountByState(0) == 0x24) {
            Menu_Ctx->field_0 = (Menu_Ctx->field_0 | 0x10) & ~2;
        }
        Menu_Ctx->field_4 = 0;
        Mem_FillWordsNeg1(&w->field_0, 8);
        Task_NextState0(a0);
        Gfx_FadeInFromBlack(0x20);
        break;
    case 1:
        tbl = (Pair54 *)Cd_GetFileEntry(0x5130006);
        switch (a0->field_14) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->field_34) != 0) {
                break;
            }
            Text_PrintIdList(&w->field_0, (Key13558 *)Cd_GetFileEntry(0x5130003), 2);
            Text_Close((Menu_Ctx->field_0 & 1) ? &w->field_14 : &w->field_18);
            Text_SetColor(w->field_4, (Menu_Ctx->field_0 >> 4) & 1);
            Text_SetColor(w->field_8, (Menu_Ctx->field_0 >> 4) & 1);
            Text_SetColor(w->field_C, (Menu_Ctx->field_0 >> 4) & 1);
            Text_SetColor(w->field_10, !(Menu_Ctx->field_0 & 2));
            Text_SetColor(w->field_14, !(Menu_Ctx->field_0 & 4));
            Text_SetColor(w->field_18, !(Menu_Ctx->field_0 & 8));
            Task_NextState1(a0);
            break;
        case 1:
            if (Menu_MoveGridCursorP1((s32)w->field_20, (s32)w->field_24) != 0) {
                snd = 0xC;
            } else if (D_8005F6F0[0].field_14 > 0) {
                k = Menu_GridIndexColMajor(w->field_20, w->field_24);
                if (k == 5 && (Menu_Ctx->field_0 & 1)) {
                    k = 6;
                }
                if ((u32)(k - 1) < 3 && (Menu_Ctx->field_0 & 0x10)) {
                    snd = 0x10;
                } else if (k == 4 && !(Menu_Ctx->field_0 & 2)) {
                    snd = 0x10;
                } else if (k == 5 && !(Menu_Ctx->field_0 & 4)) {
                    snd = 0x10;
                } else if (k == 6 && !(Menu_Ctx->field_0 & 8)) {
                    snd = 0x10;
                } else if (k == 5) {
                    Menu_Ctx->field_360 = 1;
                    Task_SetState0(a0, 2);
                    snd = 0xA;
                } else {
                    w->field_32 = k;
                    Task_NextState1(a0);
                    snd = 0xA;
                }
            } else {
                if (D_8005F6F0[0].field_1C > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(a0, 2);
                }
                break;
            }
            Snd_PlayById(snd, 0);
            break;
        case 2:
            switch (a0->field_18) {
            case 0:
            default:
                Text_CloseArray(&w->field_0, 8);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->field_34) == 0) {
                    Task_NextState1(a0);
                }
                break;
            }
            break;
        case 3:
            switch (a0->field_18) {
            case 0:
            default:
                Task_Create(tbl[w->field_32].field_0, slot, tbl[w->field_32].field_2);
                Task_NextState2(a0);
                break;
            case 1:
                if (*slot == 0) {
                    if (Menu_Ctx->field_360 != 0) {
                        Task_SetState0(a0, 2);
                    } else {
                        Task_SetState1(a0, 0);
                    }
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            Text_CloseArray(&w->field_0, 8);
            D_80050764 = Menu_Ctx->field_360;
            Task_NextState1(a0);
            Gfx_FadeOutToBlack(0x20);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->field_34) == 0) {
                Task_SetState0(a0, 3);
                Mem_Free((ActorWork *)Menu_Ctx);
            }
            break;
        }
        break;
    }
    if (Menu_Ctx != NULL) {
        Menu_Ctx->field_4 = a0->field_28;
    }
}


void func_800141D4(Actor *actor) {
    Work141D4 *w = (Work141D4 *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    Part28 *base;
    Part28 *q;
    Part28 *r;

    if (w->field_34 != 0) {
        p = (s32 *)Cd_GetFileEntry(0x5130004);
        if (*p != 0) {
            i = 0;
            list = p;
            do {
                obj = Cd_GetFileEntry(*list);
                switch (i) {
                case 0:
                default:
                    Menu_SetPartsGridPos(obj, 2, &w->field_20, &w->field_24);
                    Gfx_SetPartsPalette(obj, 2, (actor->field_28 >> 2) & 3);
                    break;
                case 1:
                    Gfx_SetPartsNumber(obj, 2, 8, D_80050720->field_8);
                    break;
                }
                Gfx_SetPartsScale(obj, 0x1000, w->field_34);
                list++;
                Gfx_DrawParts((s32)obj);
                i++;
            } while (*list != 0);
        }
    }
    base = (Part28 *)Cd_GetFileEntry(0x459000C);
    for (q = base; q->field_0 != 0; q++) {
        switch (q->field_1C) {
        case 2:
            q->field_C = Math_CycleRange(actor->field_28, 0xA, 0, 7);
            break;
        case 8:
            q->field_4 -= 2;
            if (q->field_4 == -0x168) {
                q->field_4 = 0;
            }
            break;
        case 0x10:
            q->field_4 += 1;
            if (q->field_4 == 0xD8) {
                q->field_4 = 0;
            }
            break;
        case 0x20:
            q->field_4 -= 2;
            if (q->field_4 == -0x1C0) {
                q->field_4 = 0;
            }
            break;
        }
    }
    Gfx_DrawParts((s32)base);
}

void func_800143CC(Actor *arg0, s16 arg1) {
    ActorWork *w = arg0->work;

    w->field_38 = arg1;
    if (arg1 == 3) {
        Menu_Ctx->field_35C = 0;
        w->field_3C = 0;
    }
}

void Menu_SubMenuTask(Actor *a) {
    Wk14400 *w = (Wk14400 *)a->work;
    s32 *p = (s32 *)a->u34.field_34;
    Pair54 *tbl;
    Pair54 *e;
    s32 idx;

    switch (a->field_10) {
    default:
    case 0:
        w->u2C.blk = ((Blk14400 *)Cd_GetFileEntry(0x5130007))[w->field_38 - 1];
        Mem_FillWordsNeg1(w, 0xA);
        Task_NextState0(a);
        break;
    case 1:
        tbl = (Pair54 *)Cd_GetFileEntrySubPtr(0x513000A, w->field_38 - 1);
        switch (a->field_14) {
        default:
        case 0:
            if (Math_RampToOne((s32)a, &w->field_40) == 0) {
                Text_PrintIdList((s32 *)w, (Key13558 *)Cd_GetFileEntrySubPtr(0x5130008, w->field_38 - 1), 2);
                switch (w->field_38) {
                case 5:
                case 6:
                    Task_SetState1(a, 2);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            }
            break;
        case 1:
            if (((s32 (*)(s16 *, s16 *))Menu_MoveGridCursorP1)(w->field_28, w->u2C.field_2C) == 0) {
            if (D_8005F6F0[0].field_14 > 0) {
                idx = Menu_GridIndexColMajor(w->field_28, w->u2C.field_2C);
                if (tbl[idx].field_0 == -1) {
                    break;
                }
                w->field_3A = idx;
                Snd_PlayById(0xA, 0);
                switch (w->field_38) {
                case 7:
                case 8:
                    Menu_Ctx->field_124 = w->field_28[0];
                    Task_NextState1(a);
                    break;
                case 4:
                    Task_SetState1(a, 3);
                    break;
                default:
                    Task_NextState1(a);
                    break;
                }
            } else if (D_8005F6F0[0].field_1C > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a, 2);
            }
            } else {
                Snd_PlayById(0xC, 0);
            }
            break;
        case 2:
            switch (a->field_18) {
            default:
            case 0:
                e = &tbl[w->field_3A];
                Task_Create(e->field_0, p, e->field_2);
                Task_NextState2(a);
                break;
            case 1:
                if (w->field_38 == 3) {
                    switch (Menu_Ctx->field_35C) {
                    case 1:
                        Text_CloseArray(w->field_4, 9);
                        w->field_3C = 1;
                        break;
                    case 2:
                        Text_CloseArray(w, 0xA);
                        Text_PrintIdList((s32 *)w, (Key13558 *)Cd_GetFileEntrySubPtr(0x5130008, w->field_38 - 1), 0);
                        w->field_3C = 0;
                        break;
                    }
                    Menu_Ctx->field_35C = 0;
                }
                if (*p == 0) {
                    switch (w->field_38) {
                    default:
                        Task_SetState1(a, 1);
                        break;
                    case 5:
                    case 6:
                        Task_SetState0(a, 2);
                        break;
                    }
                }
                break;
            }
            break;
        case 3: {
            s32 *q = (s32 *)a->u34.field_34;
            switch (a->field_18) {
            default:
            case 0:
                Text_CloseArray(w, 0xA);
                Task_NextState2(a);
                break;
            case 1:
                if (Math_RampToZero((s32)a, &w->field_40) == 0) {
                    Task_NextState2(a);
                }
                break;
            case 2:
                e = &tbl[w->field_3A];
                Task_Create(e->field_0, q, e->field_2);
                Task_NextState2(a);
                break;
            case 3:
                if (*q == 0) {
                    Task_SetState1(a, 0);
                }
                break;
            }
            break;
        }
        }
        break;
    case 2:
        switch (a->field_14) {
        default:
        case 0:
            Text_CloseArray(w, 0xA);
            Task_NextState1(a);
            break;
        case 1:
            if (Math_RampToZero((s32)a, &w->field_40) == 0) {
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}


extern void Menu_SetPartsGridPos(void *, s32, s32 *, s16 *);
extern void Gfx_SetPartsPalette(Part28 *, s32, s32);
extern void Gfx_HidePartsByMask(Obj1D504 *, s32);

void func_80014870(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;

    if (w->field_40 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130009);
    if (*p == 0) {
        return;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        if (w->field_2C != 0 && w->field_3C == 0) {
            Menu_SetPartsGridPos(obj, 2, &w->field_28, &w->field_2C);
            Gfx_SetPartsPalette(obj, 2, (actor->field_28 >> 2) & 3);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 2);
        }
        list++;
        Gfx_SetPartsScale(obj, 0x1000, w->field_40);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);
}

void func_80014978(Actor *arg0, s16 arg1) {
    arg0->work->field_6C = arg1;
}

void func_80014984(Actor *a0) {
    Wk14CBC *w = (Wk14CBC *)a0->work;
    s32 i;
    s32 v;
    s32 id;
    s32 *p;
    s16 *tbl;
    Halves *h;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_AC = Digi_ListByState(3, (ElmE620 **)w->field_A0);
        Mem_FillWordsNeg1(w, 0x1A);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->field_70) != 0) {
                break;
            }
            Text_PrintIdList(w->field_0, (Key13558 *)Cd_GetFileEntry(0x513000B), 2);
            w->field_74[0] = (s32)D_80050720->field_14;
            tbl = (s16 *)Cd_GetFileEntry(0x513000F);
            w->field_74[1] = (s32)Cd_GetFileEntry(tbl[D_80050720->field_11 * 11 + D_80050720->field_12] + 0x1FD0000);
            w->field_74[2] = (s32)D_80050720->field_D1;
            p = &w->field_74[3];
            for (i = 0; i < w->field_AC; i++) {
                *p++ = (s32)w->field_A0[i]->field_4C;
            }
            *p = 0;
            Text_PrintList(w->field_40, (Halves *)Cd_GetFileEntry(0x513000C), w->field_74, 2);
            if (Menu_Ctx->field_0 & 1) {
                h = (Halves *)Cd_GetFileEntry(0x513000D);
                for (i = 0; i < 4; i++) {
                    v = (i == 3) ? func_80021D60() : D_8005071C->field_BA5[i];
                    if (v != 0) {
                        id = v + 0x1FD00EC;
                        Text_OpenPacked(&w->field_58[i], (s32)Cd_GetFileEntry(i * 3 + id), 1, h[i]);
                    }
                }
            }
            for (i = w->field_AC; i < 3; i++) {
                Text_Close(&w->field_0[i * 3 + 7]);
                Text_Close(&w->field_0[i * 3 + 8]);
                Text_Close(&w->field_0[i * 3 + 9]);
            }
            Task_NextState1(a0);
            break;
        case 1:
            if (D_8005F6F0[0].field_1C > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 2);
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            Text_CloseArray(w, 0x1A);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->field_70) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}

void func_80014CBC(Actor *actor) {
    Wk14CBC *w = (Wk14CBC *)actor->work;
    s32 *p;
    s32 *list;
    s32 i;
    Part28 *obj;
    Rec14CBC *rec;

    if (w->field_70 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x513000E);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
    do {
        obj = (Part28 *)Cd_GetFileEntry(*list);
        if (i == 0) {
            Gfx_SetPartsNumber(obj, 2, 8, D_80050720->field_8);
            Gfx_SetPartsNumber(obj, 4, 4, D_80050720->field_26);
            Gfx_SetPartsNumber(obj, 8, 4, D_80050720->field_24);
            Gfx_SetPartsNumber(obj, 0x10, 4, D_80050720->field_2A);
            Gfx_SetPartsNumber(obj, 0x20, 4, D_80050720->field_28);
        } else if (i - 1 < w->field_AC) {
            rec = w->field_A0[i - 1];
            Gfx_SetPartsNumber(obj, 2, 3, rec->field_14);
            Gfx_SetPartsNumber(obj, 4, 3, rec->field_16);
            Gfx_SetPartsNumber(obj, 8, 3, rec->field_18);
            Gfx_SetPartsNumber(obj, 0x10, 3, rec->field_1A);
            Gfx_SetPartsNumber(obj, 0x20, 2, rec->field_D);
            Gfx_HidePartsByMask(obj, 0);
        } else {
            Gfx_HidePartsByMask(obj, 0xFFFF);
        }
        Gfx_SetPartsScale((Ent1D550 *)obj, 0x1000, w->field_70);
        list++;
        Gfx_DrawParts((s32)obj);
        i++;
    } while (*list != 0);
}

void Menu_UseItemDirect(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    Src16198 st;

    if (Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, 0, 0) != 0) {
        st.field_C = D_80050700;
        st.field_11 = 0;
        st.field_10 = 0x81;
        st.field_0 = (s32)Cd_GetFileEntry(0x1FD00FD);
        st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
        Text_OpenDesc(&w->field_50, (Src13470 *)&st);
        Snd_PlayById(0x1D, 0);
    } else {
        Text_OpenPacked(&w->field_50, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, D_80050700);
    }
}


void func_80014F78(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    Halves *pos;
    Sub17D84 *rec;
    s32 n;
    s32 m;
    s32 r;
    Src16198 st;

    rec = (Sub17D84 *)Item_GetEffectRec(Menu_Ctx->field_108);
    pos = &D_80050700;
    n = rec->field_1 - 0xC;
    m = D_8005071C->field_BA5[n];
    st.field_C = *pos;
    st.field_11 = 0;
    st.field_10 = 0x81;
    switch (rec->field_1) {
    case 0xC:
    case 0xD:
    case 0xE:
        r = Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, 0, 0);
        if (r == 0) {
            Text_OpenPacked(&w->field_50, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, *pos);
            goto end;
        }
        if (r == 1) {
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B3);
            r = m + 0x1FD00EC;
            st.field_4 = (s32)Cd_GetFileEntry(n * 3 + r);
        } else {
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
        }
        Text_OpenDesc(&w->field_50, (Src13470 *)&st);
        break;
    case 0xF:
    default:
        r = Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, 0, 0);
        if (r == 0) {
            Text_OpenPacked(&w->field_50, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, D_80050700);
            goto end;
        }
        if (r == 2) {
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
        } else if (D_8005071C->field_BA8 != 0) {
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B5);
            st.field_4 = 0;
        } else {
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B3);
            r = 0x1FD00EC;
            st.field_4 = (s32)Cd_GetFileEntry(n * 3 + (D_80050760 + r));
        }
        Text_OpenDesc(&w->field_50, (Src13470 *)&st);
        break;
    case 0x10:
        r = Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, 0, 0);
        if (r == 0) {
            Text_OpenPacked(&w->field_50, (s32)Cd_GetFileEntry(0x1FD00A0), 0x81, *pos);
            goto end;
        }
        if (r == 2) {
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B4);
            st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
        } else {
            st.field_4 = 0;
            if (D_8005071C->field_BA5[0] + D_8005071C->field_BA5[1] + D_8005071C->field_BA5[2] + D_8005071C->field_BA8 != 0) {
                st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B7);
            } else {
                st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B6);
            }
        }
        Text_OpenDesc(&w->field_50, (Src13470 *)&st);
        break;
    }
end:
    func_800153F4(a0, 0);
}


void func_80015298(Actor *a0, s32 a1) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 i;
    s32 id;
    s32 k;
    s32 img;
    Halves h;

    for (i = 0; i < 20; i++) {
        img = (s32)Cd_GetFileEntry(0x1FD0098);
        id = D_8005076C[i];
        k = 0;
        if (id != 0xFF && D_80050720->field_2C[id] != 0) {
            img = Item_GetNameText(D_80050720->field_2C[id]);
            if (D_80050720->field_52[id] != 0) {
                k = 3;
            }
        }
        h.lo = (i / w->field_8C[1]) * 98 + 0x88;
        h.hi = (i % w->field_8C[1]) * 12 + 0x32;
        Text_OpenPacked(&w->field_0[i], img, a1, h);
        Text_SetColor(w->field_0[i], k);
    }
}


void func_800153F4(Actor *a0, s32 a1) {
    HudSlots153F4 *w = (HudSlots153F4 *)a0->work;
    Halves *h;
    s32 i;
    s32 id;
    s32 v;

    h = (Halves *)Cd_GetFileEntry(0x5130016);
    for (i = 0; i < 4; i++) {
        if (i == 3) {
            v = func_80021D60();
        } else {
            v = D_8005071C->field_BA5[i];
        }
        if (v != 0) {
            id = v + 0x1FD00EC;
            id = i * 3 + id;
            Text_OpenPacked(&w->slot[i], (s32)Cd_GetFileEntry(id), a1, *h);
        } else {
            Text_Close(&w->slot[i]);
        }
        h++;
    }
}

void func_800154F0(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 i;
    s32 id;
    Halves h;

    i = Menu_GridIndexColMajor(w->field_88, w->field_8C);
    Text_Close(&w->field_50);
    Text_Close(&w->field_54);
    Text_Close(&w->field_58);
    id = D_8005076C[i];
    if (id != 0xFF) {
        h.lo = 0xF;
        h.hi = 0x32;
        Text_OpenPacked(&w->field_58, (s32)Cd_GetFileEntry(D_80050770[i] | 0x1FD0000), 0, h);
        if (D_80050720->field_2C[id] != 0) {
            Text_OpenPacked(&w->field_50, func_8001E084(D_80050720->field_2C[id]), 0x80, D_80050700);
            if (D_80050720->field_52[id] != 0) {
                h.lo = 0x10;
                h.hi = 0xCA;
                Text_OpenPacked(&w->field_54, (s32)Cd_GetFileEntry(0x1FD0097), 0x80, h);
            }
        }
    }
}


void func_80015668(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    Halves h;

    Text_Close(&w->field_58);
    Text_Close(&w->field_5C);
    h.lo = 0xF;
    h.hi = 0x32;
    Text_OpenPacked(&w->field_58, (s32)Cd_GetFileEntry(0x1FD009B), 0, h);
    h.lo = 0xF;
    h.hi = 0x47;
    Text_OpenPacked(&w->field_5C, Item_GetNameText(Menu_Ctx->field_108), 0, h);
    if (w->field_98 == 3) {
        Text_OpenPacked(&w->field_50, (s32)Cd_GetFileEntry(0x1FD00FB), 0x80, D_80050700);
    }
}


void Menu_UseItemOnTarget(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 id;
    Src16198 st;

    if (D_8005F704 > 0) {
        id = D_8005076C[Menu_GridIndexColMajor(w->field_88, w->field_8C)];
        if (id != 0xFF && Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, id, 0) != 0) {
            st.field_C = D_80050700;
            st.field_11 = 0;
            st.field_10 = 0x81;
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00FC);
            st.field_4 = Item_GetNameText(D_80050720->field_2C[id]);
            Text_OpenDesc(&w->field_50, (Src13470 *)&st);
            func_80015298(a0, 0);
            Snd_PlayById(0x1D, 0);
            Task_SetState1(a0, 3);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}


void Menu_SetItemUseMode(Actor *a, s16 arg) {
    ActorWork *w = a->work;
    s32 mode;
    s32 k;

    w->field_98 = arg;
    mode = arg;
    if (mode == 2) {
        k = ((u8 *)Item_GetEffectRec(Menu_Ctx->field_108))[1];
        if (k == 11) {
            goto three;
        }
        if (k < 11) {
            goto def;
        }
        if (k < 17) {
            w->field_98 = 4;
            return;
        }
    def:
        w->field_98 = mode;
        return;
    three:
        w->field_98 = 3;
    }
}

void Menu_ItemUseTask(Actor *a0) {
    Wk14EA4 *w = (Wk14EA4 *)a0->work;
    s32 r;
    s32 id;
    s32 next;

    D_8005076C = (u8 *)Cd_GetFileEntry(0x5130014);
    D_80050770 = (u8 *)Cd_GetFileEntry(0x5130015);
    switch (a0->field_10) {
    case 0:
    default:
        *(Layout8C *)w->field_8C = *(Layout8C *)Cd_GetFileEntry(0x5130010);
        Mem_FillWordsNeg1(w->field_0, 0x22);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->field_9C) != 0) {
                break;
            }
            Text_PrintIdList(&w->field_70, (Key13558 *)Cd_GetFileEntry(0x5130011), 2);
            func_80015298(a0, 1);
            if (Menu_Ctx->field_0 & 1) {
                func_800153F4(a0, 1);
            }
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->field_98) {
            case 1:
                func_800154F0(a0);
                Task_NextState1(a0);
                break;
            case 2:
                func_80015668(a0);
                Menu_UseItemDirect(a0);
                Task_SetState1(a0, 3);
                break;
            case 3:
                func_80015668(a0);
                Task_NextState1(a0);
                break;
            case 4:
                func_80015668(a0);
                func_80014F78(a0);
                Task_SetState1(a0, 3);
                break;
            case 5:
switch (func_80022518(0x10)) {
case -1:
id = 0x154;
 next = 3;
break;
case 0:
id = 0x153;
 next = 3;
break;
default:
id = 0x152;
 next = 4;
break;
}
                Text_OpenPacked(&w->field_50, (s32)Cd_GetFileEntry(id | 0x1FD0000), 0x82, D_80050700);
                Task_SetState1(a0, next);
                break;
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->field_88, (s32)w->field_8C) == 0) {
                if (D_8005F6F0[0].field_1C > 0) {
                    Snd_PlayById(0xB, 0);
                    Task_SetState0(a0, 2);
                } else if (w->field_98 == 3) {
                    Menu_UseItemOnTarget(a0);
                }
            } else {
                Snd_PlayById(0xD, 0);
                Task_SetState1(a0, 1);
            }
            break;
        case 3:
            switch (a0->field_18) {
            case 0:
                if (Text_IsFinished(w->field_50) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_14 > 0 || a0->field_20++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 4:
            r = func_800136A4(w->field_50);
            switch (r) {
            case 1:
                Gfx_FadeOutToBlack(0x20);
                Menu_Ctx->field_360 = r;
                Task_SetState0(a0, 2);
                break;
            case -1:
                Task_SetState0(a0, 2);
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            Text_CloseArray(w->field_0, 0x22);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->field_9C) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80015D30(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 k;
    s32 mask;

    if (w->field_9C == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130012);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        mask = 1 << i;
        if (((s32 *)Cd_GetFileEntry(0x5130013))[w->field_98 - 1] & mask) {
            switch (i) {
            case 0:
            if (w->field_98 == 1 || w->field_98 == 3) {
                Menu_SetPartsGridPos(obj, 2, &w->field_88, &w->field_8C);
                Gfx_SetPartsPalette(obj, 2, (actor->field_28 >> 2) & 3);
                Gfx_HidePartsByMask(obj, 0);
            } else {
                Gfx_HidePartsByMask(obj, 2);
            }
            Gfx_SetPartsNumber(obj, 4, 4, D_80050720->field_26);
            Gfx_SetPartsNumber(obj, 8, 4, D_80050720->field_24);
            Gfx_SetPartsNumber(obj, 0x10, 4, D_80050720->field_2A);
            Gfx_SetPartsNumber(obj, 0x20, 4, D_80050720->field_28);
                break;
            case 1:
            case 3:
                k = 0;
                if (w->field_98 == 5) {
                    k = -1;
                } else if (i == 3) {
                    k = 4;
                }
                Gfx_HidePartsByMask(obj, k);
                break;
            default:
                Gfx_HidePartsByMask(obj, 0);
                break;
            }
            Gfx_SetPartsScale(obj, 0x1000, w->field_9C);
            Gfx_DrawParts((s32)obj);
        }
        list++;
        i++;
    } while (*list != 0);
}


void Item_BuildMenuList(Obj16198 *w) {
    Cell16198 *c = w->field_72;
    Cell16198 *q;
    Cell16198 *p;
    s32 i;
    s32 id;

    if (w->field_64 >= 6) {
        goto party;
    }
    if (w->field_64 < 4) {
    party:
        i = 0;
        w->field_6C = Item_GetBagCapacity();
        p = w->field_72;
        for (; i < w->field_6C;) {
            c->field_0 = D_80050720->field_66[i];
            p->field_2 = 0;
            p->field_4 = i++;
            p++;
            c++;
        }
        w->field_58.field_0[0] = w->field_6C / 8;
        w->field_58.field_0[1] = w->field_6C >= 9 ? 8 : w->field_6C;
    } else {
        w->field_6C = 0;
        q = w->field_72;
        for (i = 1; i < 0x118; i++) {
            id = Item_GetIdAtIndex(i - 1);
            if (w->field_64 == 4) {
                if (func_8001E0C0(id) == 0x1F) {
                    continue;
                }
            } else if (func_8001E0C0(id) != 0x1F) {
                continue;
            }
            if (D_80050720->field_DD4[id] != 0) {
                c->field_0 = id;
                q->field_2 = D_80050720->field_DD4[id];
                q->field_2 = q->field_2 >= 100 ? 99 : q->field_2;
                q->field_2 = w->field_64 == 5 ? 0 : q->field_2;
                q++;
                c++;
                w->field_6C++;
            }
        }
        w->field_58.field_0[0] = w->field_6C / 8;
        w->field_58.field_0[0] += (u16)w->field_6C % 8 != 0;
        w->field_58.field_0[1] = w->field_6C >= 9 ? 8 : w->field_6C;
    }
    w->field_70 = w->field_6C != 0;
}


void Menu_DrawItemGrid(Obj16198 *a0, s32 a1) {
    s32 n;
    s32 i;
    s32 base;
    s32 img;
    Halves h;
    Src16198 st;

    base = a0->field_6E * 8;
    n = a0->field_6C - base;
    n = (n > 16) ? 16 : n;
    for (i = 0; i < 16; i++) {
        Text_Close(&a0->field_0[i]);
    }
    for (i = 0; i < n; i++) {
        h.lo = (i / 8) * 113 + 30;
        h.hi = (i % 8) * 12 + 71;
        if (a0->field_72[base + i].field_0 == 0) {
            img = (s32)Cd_GetFileEntry(0x1FD0098);
        } else {
            img = Item_GetNameText(a0->field_72[base + i].field_0);
        }
        if (a0->field_72[base + i].field_0 != 0 && a0->field_72[base + i].field_2 != 0) {
            st.field_C = h;
            st.field_10 = a1;
            st.field_11 = 0;
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD0125);
            st.field_4 = img;
            st.field_8 = a0->field_702[i];
            Text_FormatNumber(a0->field_702[i], a0->field_72[base + i].field_2, -2);
            Text_OpenDesc(&a0->field_0[i], (Src13470 *)&st);
        } else {
            Text_OpenPacked(&a0->field_0[i], img, a1, h);
        }
    }
}

void Item_MoveToStorage(Actor *a0, Obj16198 *w) {
    Cell16198 *c;
    s32 id;
    s32 snd;
    Src16198 st;

    c = &w->field_72[Menu_GridIndexColMajor(w->field_54, w->field_58.field_0)];
    if (c->field_0 == 0) {
        snd = 0x10;
    } else {
        id = c->field_0;
        D_80050720->field_DD4[id] += (D_80050720->field_DD4[id] + 1 < 100);
        Item_RemoveFromBag(c->field_4);
        st.field_C = D_80050704;
        st.field_10 = 0x81;
        st.field_11 = 0;
        st.field_4 = Item_GetNameText(id);
        st.field_0 = (s32)Cd_GetFileEntry(0x1FD0122);
        Text_OpenDesc(&w->field_40, (Src13470 *)&st);
        Item_BuildMenuList(w);
        Menu_DrawItemGrid(w, 0);
        Task_SetState1(a0, 2);
        snd = 0xE;
    }
    Snd_PlayById(snd, 0);
}

void Item_TakeFromStorage(Actor *a0, Obj16198 *w) {
    Cell16198 *c;
    s32 n;
    s32 i;
    s32 t;
    s32 snd;
    Src16198 st;

    c = &w->field_72[Menu_GridIndexColMajor(w->field_54, w->field_58.field_0)];
    if (c->field_0 == 0) {
        snd = 0x10;
    } else if (Menu_GridIndexColMajor(w->field_54, w->field_58.field_0) >= w->field_6C) {
        snd = 0x10;
    } else {
        n = Item_GetBagCapacity();
        for (i = 0; i < n; i++) {
            if (D_80050720->field_66[i] == 0) {
                break;
            }
        }
        if (i == n) {
            Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(0x1FD0124), 0x81, D_80050704);
            snd = 0x10;
        } else {
            D_80050720->field_66[i] = c->field_0;
            D_80050720->field_DD4[c->field_0]--;
            st.field_C = D_80050704;
            st.field_10 = 0x81;
            st.field_11 = 0;
            st.field_4 = Item_GetNameText(c->field_0);
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD0123);
            Text_OpenDesc(&w->field_40, (Src13470 *)&st);
            Item_BuildMenuList(w);
            if (w->field_54[0] >= w->field_58.field_0[0]) {
                w->field_54[0] = w->field_58.field_0[0] - 1;
            }
            if (w->field_54[1] >= w->field_58.field_0[1]) {
                w->field_54[1] = w->field_58.field_0[1] - 1;
            }
            t = w->field_58.field_0[0] - 2;
            if (t < 0) {
                t = 0;
            }
            w->field_6E = (w->field_6E < t) ? w->field_6E : t;
            Menu_DrawItemGrid(w, 0);
            if (w->field_6C == 0) {
                Task_SetState1(a0, 6);
            } else {
                Task_SetState1(a0, 2);
            }
            snd = 0xE;
        }
    }
    Snd_PlayById(snd, 0);
}


void Menu_PickItemToUse(Actor *a0, Obj166FC *o) {
    s16 *pos = o->field_54;
    s16 *size = o->field_58;
    s32 id = o->field_72[Menu_GridIndexColMajor(pos, size)].field_0;
    s32 r;
    Halves h;

    if (id != 0) {
        r = func_80011FE4(id);
        if (r != 0) {
            goto found;
        }
        h.lo = 0x10;
        h.hi = 0xBA;
        Text_OpenPacked(o->field_44, Cd_GetFileEntry(0x1FD00A1), 0x81, h);
    }
    Snd_PlayById(0x10, 0);
    return;
found:
    Menu_Ctx->field_108 = id;
    Menu_Ctx->field_10A = o->field_72[Menu_GridIndexColMajor(pos, size)].field_4;
    o->field_66 = r == 1;
    Snd_PlayById(0xE, 0);
    Task_NextState1(a0);
}

void Menu_ItemGridSelect(Actor *a0, GridMenu *m) {
    u16 v = m->field_72[Menu_GridIndexColMajor(m->field_54, m->field_58)].field_0;

    if (v == 0) {
        Snd_PlayById(0x10, 0);
    } else {
        Snd_PlayById(0xE, 0);
        Menu_Ctx->field_108 = v;
        Menu_Ctx->field_10A = Menu_GridIndexColMajor(m->field_54, m->field_58);
        Task_SetState1(a0, 4);
    }
}

void Menu_ShowSelItemText(Actor *a0, Obj166FC *o) {
    s32 idx;
    u16 id;

    idx = Menu_GridIndexColMajor(o->field_54, o->field_58);
    Text_Close(&o->field_40);
    Text_Close((s32 *)o->field_44);
    id = o->field_72[idx].field_0;
    if (id != 0) {
        if (o->field_64 != 5) {
            Text_OpenPacked(&o->field_40, Item_GetNameText(id), 0, D_80050708);
        }
        Text_OpenPacked(o->field_44, func_8001E084(id), 0x80, D_80050704);
    }
}

void func_800169D0(Actor *arg0, s16 arg1) {
    arg0->work->field_64 = arg1;
}

void Menu_ItemTask(Actor *a0) {
    Obj16198 *w = (Obj16198 *)a0->work;
    s32 *slot;
    s32 r;
    s32 id;
    Src16198 st;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_58 = *(Box16198 *)Cd_GetFileEntry(0x5130017);
        Item_SortList();
        w->field_6E = 0;
        w->field_54[1] = 0;
        w->field_54[0] = 0;
        Item_BuildMenuList(w);
        Mem_FillWordsNeg1(w->field_0, 0x15);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->field_68) != 0) {
                break;
            }
            Text_PrintIdList(&w->field_4C, (Key13558 *)Cd_GetFileEntrySubPtr(0x5130018, w->field_64 - 1), 2);
            Item_BuildMenuList(w);
            Menu_DrawItemGrid(w, 1);
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->field_64) {
            default:
                Menu_ShowSelItemText(a0, (Obj166FC *)w);
                break;
            case 5:
                if (w->field_6C == 0) {
                    id = 0x1FD0151;
                    goto msg;
                }
                Menu_ShowSelItemText(a0, (Obj166FC *)w);
                Task_NextState1(a0);
                return;
            case 3:
            case 4:
                if (w->field_64 == 4) {
                    if (w->field_6C == 0) {
                        goto full;
                    }
                }
                Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(((s32)((u16)w->field_64 << 16) >> 16) + 0x1FD011D), 0x80, D_80050704);
                break;
            }
            Task_NextState1(a0);
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->field_54, (s32)w->field_58.field_0) != 0) {
                Snd_PlayById(0xD, 0);
                if (w->field_54[0] - w->field_6E >= 2) {
                    w->field_6E = w->field_54[0] - 1;
                    Menu_DrawItemGrid(w, 0);
                } else if (w->field_54[0] < w->field_6E) {
                    w->field_6E = w->field_54[0];
                    Menu_DrawItemGrid(w, 0);
                }
                Task_SetState1(a0, 1);
            } else if (D_8005F6F0[0].field_1C > 0) {
                Snd_PlayById(0xB, 0);
                Task_SetState0(a0, 2);
            } else if (D_8005F6F0[0].field_14 > 0) {
                switch (w->field_64) {
                case 1:
                    Menu_PickItemToUse(a0, (Obj166FC *)w);
                    break;
                case 2:
                    Menu_ItemGridSelect(a0, (GridMenu *)w);
                    break;
                case 3:
                    Item_MoveToStorage(a0, w);
                    break;
                case 4:
                    Item_TakeFromStorage(a0, w);
                    break;
                }
            }
            break;
        case 3:
            slot = (s32 *)a0->u34.field_34;
            switch (a0->field_18) {
            case 0:
            default:
                Text_CloseArray(w->field_0, 0x15);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->field_68) != 0) {
                    break;
                }
                Task_Create(D_80040EFC[w->field_66].field_0, slot, D_80040EFC[w->field_66].field_2);
                Task_NextState2(a0);
                break;
            case 2:
                if (*slot == 0) {
                    Task_SetState1(a0, 0);
                }
                break;
            }
            break;
        case 4:
            st.field_C.lo = 0x10;
            st.field_C.hi = 0xBA;
            st.field_10 = 0x81;
            st.field_11 = 0;
            st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
            switch (a0->field_18) {
            case 0:
            default:
                st.field_0 = (s32)Cd_GetFileEntry(0x1FD00B9);
                Text_OpenDesc(&w->field_44, (Src13470 *)&st);
                Task_NextState2(a0);
                break;
            case 1:
                r = func_800136A4(w->field_44);
                switch (r) {
                case 1:
                    Item_RemoveFromBag(Menu_Ctx->field_10A);
                    st.field_0 = (s32)Cd_GetFileEntry(0x1FD00BA);
                    Text_OpenDesc(&w->field_44, (Src13470 *)&st);
                    Item_BuildMenuList(w);
                    Menu_DrawItemGrid(w, 0);
                    Task_SetState1(a0, 2);
                    break;
                case -1:
                    Task_SetState1(a0, 1);
                    break;
                }
                break;
            }
            break;
        case 5:
            switch (a0->field_18) {
            case 0:
                if (Text_IsFinished(w->field_40) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_14 > 0 || a0->field_20++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 6:
            if (Text_IsFinished(w->field_40) == 0) {
                break;
            }
        full:
            id = 0x1FD0127;
        msg:
            Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(id), 0x81, D_80050704);
            Task_SetState1(a0, 5);
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            Item_SortList();
            Text_CloseArray(w->field_0, 0x15);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->field_68) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80016FDC(Actor *actor) {
    ActorWork *w = actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 k;
    s32 f;
    u16 m;
    Pair54 tmp;

    if (w->field_68 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130019);
    if (*p == 0) {
        return;
    }
    i = 0;
    list = p;
loop:
        obj = Cd_GetFileEntry(*list);
        switch (i) {
        case 0:
            tmp = w->field_54;
            f = w->field_54.field_0 + 1;
            Gfx_SetPartsNumber(obj, 0x10, 2, f ? f : 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->field_58 ? w->field_58 : 1);
            tmp.field_0 = w->field_54.field_0 - w->field_6E;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->field_58);
            Gfx_SetPartsPalette(obj, 2, (actor->field_28 >> 2) & 3);
            f = func_80013854(obj, 8, w->field_6E);
            f |= func_80013854(obj, 4, w->field_58 - w->field_6E - 2);
            if (w->field_70 == 0) {
                f |= 0xE;
            }
            Gfx_HidePartsByMask(obj, f);
            break;
        case 1:
            if (w->field_64 < 3) {
                m = 2;
            } else {
                m = 0xFFFF;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        case 3:
            m = 0xFFFF;
            if (w->field_64 == 3 || w->field_64 == 5) {
                m = 1;
            } else if (w->field_64 == 4) {
                m = 2;
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->field_68);
        list++;
        Gfx_DrawParts((s32)obj);
        i++;
    if (*list != 0) goto loop;
}


void func_80017214(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Sel174F8 *e;
    Rec17214 *g;
    Sel174F8 *d;
    Rec17214 tmp;
    u8 k;
    s32 id;
    s32 n;
    Obj50768 *p;

    e = &w->field_6C[Menu_GridIndexColMajor(w->field_50, w->field_54)];
    p = Menu_Ctx;
    do {} while (0);
    n = D_8005F704;
    g = (Rec17214 *)p->field_128;
    if (n > 0) {
        switch (e->field_0) {
        case 0:
        default:
            if (g->field_0 >= 3) {
                id = 0x1FD0111;
            icon:
                Text_OpenPacked(w->field_40, Cd_GetFileEntry(id), 0x81, D_8005070C);
                break;
            }
            g->field_0 = w->field_1A0[3] != 0 ? 1 : 2;
            d = &w->field_6C[w->field_50[1]];
            d->field_0 = 1;
            d->field_4 = (s32)g;
            d->field_2 = g->field_0;
            id = 0x1FD0110;
            goto swap;
        case 1:
            k = g->field_0;
            tmp = *(Rec17214 *)e->field_4;
            g->field_0 = tmp.field_0;
            tmp.field_0 = k;
            *(Rec17214 *)e->field_4 = *g;
            *g = tmp;
            id = 0x1FD0112;
        swap:
            Text_OpenPacked(w->field_40, Cd_GetFileEntry(id), 0x81, D_8005070C);
            Menu_Ctx->field_126 = -1;
            func_80017D84((Obj17D84 *)w, 0);
            Snd_PlayById(0xE, 0);
            Task_SetState1(a0, 4);
            return;
        case 3:
            if (g->field_0 >= 3) {
                id = 0x1FD011E;
                goto icon;
            }
            Text_OpenPacked(w->field_40, Cd_GetFileEntry(0x1FD011F), 0x81, D_8005070C);
            Task_SetState1(a0, 5);
            return;
        case 2:
            break;
        }
        Snd_PlayById(0x10, 0);
    }
}

void func_800174F8(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Sel174F8 *e = &w->field_6C[Menu_GridIndexColMajor(w->field_50, w->field_54)];
    s32 k;

    if (D_8005F704 > 0) {
        k = 0x10;
        if (e->field_0 == 1) {
            Menu_Ctx->field_128 = e->field_4;
            Menu_Ctx->field_126 = 0;
            w->field_62 = 3;
            Task_SetState1(a0, 3);
            k = 0xE;
        }
        Snd_PlayById(k, 0);
    }
}

void Menu_ConfirmMultiPick(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    s32 k = Menu_GridIndexColMajor(w->field_50, w->field_54);
    Sel174F8 *e = &w->field_6C[k];
    s32 i;

    if (D_8005F704 > 0) {
        if (e->field_2 != 2) {
            Snd_PlayById(0x10, 0);
            return;
        }
        e->field_2 = w->field_19E + 3;
        w->field_1A0[w->field_19E++] = k;
        Snd_PlayById(0xE, 0);
        if (w->field_19E < w->field_19C) {
            Task_SetState1(a0, 1);
        } else {
            Obj50768 *d;
            Menu_Ctx->field_120 = w->field_19C;
            d = Menu_Ctx;
            i = 0;
            if (w->field_19C > 0) {
                do {
                    d->field_114[i] = w->field_6C[w->field_1A0[i]].field_4;
                } while (++i < w->field_19C);
            }
            w->field_62 = 2;
            Task_SetState1(a0, 3);
        }
    }
}

void Menu_UndoLastPick(Actor *s0) {
    Work176D8 *w = (Work176D8 *)s0->work;
    s16 c = w->field_19E;
    if (c == 0) {
        Snd_PlayById(0xB, 0);
        Task_SetState0(s0, 2);
    } else {
        s16 idx = (u16)c - 1;
        s16 v;
        w->field_19E = idx;
        v = w->field_1A0[idx];
        ((WorkElem8 *)((u8 *)w + 0x6C))[v].field_2 = 2;
        w->field_1A0[w->field_19E] = 0;
        Snd_PlayById(0xB, 0);
        Task_SetState1(s0, 1);
    }
}

void Menu_UseItemOnDigi(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Sel174F8 *e = &w->field_6C[Menu_GridIndexColMajor(w->field_50, w->field_54)];
    Src16198 st;

    if (D_8005F704 > 0) {
        if (e->field_0 == 1 && Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, 0, e->field_4) != 0) {
            st.field_C = D_8005070C;
            st.field_11 = 0;
            st.field_10 = 0x81;
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00FD);
            st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
            Text_OpenDesc(w->field_40, (Src13470 *)&st);
            Snd_PlayById(0x1D, 0);
            Task_SetState1(a0, 4);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}

void Menu_PickUseItemDirect(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    Src16198 st;

    st.field_C = D_8005070C;
    st.field_11 = 0;
    st.field_10 = 0x81;
    if (Item_Use(Menu_Ctx->field_108, Menu_Ctx->field_10A, 0, 0) != 0) {
        st.field_0 = (s32)Cd_GetFileEntry(0x1FD00FD);
        st.field_4 = Item_GetNameText(Menu_Ctx->field_108);
        Snd_PlayById(0x1D, 0);
    } else {
        st.field_0 = (s32)Cd_GetFileEntry(0x1FD00A0);
        st.field_4 = 0;
    }
    Text_OpenDesc(w->field_40, (Src13470 *)&st);
}

void Menu_ConfirmSinglePick(Actor *a0) {
    Work174F8 *w = (Work174F8 *)a0->work;
    s32 k;
    s32 c;

    if (D_8005F704 > 0) {
        k = Menu_GridIndexColMajor(w->field_50, w->field_54);
        if ((c = w->field_6C[k].field_0) == 1) {
            Menu_Ctx->field_110 = (u8 *)w->field_6C[k].field_4;
            w->field_62 = 0;
            Task_SetState1(a0, 3);
            Menu_Ctx->field_35C = c;
            Snd_PlayById(0xE, 0);
        } else {
            Snd_PlayById(0x10, 0);
        }
    }
}


void func_800179EC(Wk179EC *w) {
    Row179EC *r = w->rows;
    ElmE620 *el = D_80050720->elems;
    s32 n = 0;
    s32 i;
    s32 ok;
    Row179EC *t;

    t = r;
    for (i = 0; i < 0x26; i++) {
        t->field_2 = 0;
        t->field_0 = 0;
        t++;
    }
    w->field_54 = 1;
    switch (w->field_60) {
    default:
        w->field_56 = func_80022578();
        break;
    case 2:
        w->field_56 = 0x18;
        break;
    case 7:
    case 8:
        if (w->field_1A6 == 0) {
            w->field_56 = func_80022578();
        } else {
            w->field_56 = 0x18;
        }
        if (w->field_60 == 8) {
            w->field_56++;
            n++;
            r->field_0 = 3;
            r->field_4 = 0;
            r->field_2 = 0;
            r++;
            w->field_52++;
        }
        break;
    case 6:
        w->field_56 = Menu_Ctx->field_120;
        for (i = 0; i < Menu_Ctx->field_120; i++) {
            r->field_0 = 1;
            r->field_4 = Menu_Ctx->field_114[i];
            r->field_2 = i + 3;
            r++;
        }
        return;
    }
    for (i = 0; i < 0x24; i++, el++) {
        if (el->field_0 != 0) {
            ok = 0;
            switch (w->field_60) {
            default:
                if (el->field_0 >= 2) ok = -1;
                break;
            case 5:
                if (el->field_0 >= 2 && (s16)el->field_16 != 0) ok = -1;
                break;
            case 7:
            case 8:
                if (w->field_1A6 != 0) {
                    if (el->field_0 == 1) ok = -1;
                } else {
                    if (el->field_0 >= 2) ok = -1;
                }
                break;
            case 2:
                if (el->field_0 == 1) ok = -1;
                break;
            }
            if (ok) {
                r->field_0 = 1;
                r->field_4 = el;
                r->field_2 = (w->field_60 == 5) ? 2 : el->field_0;
                r++;
                n++;
            }
        }
    }
    if (Menu_Ctx->field_0 & 1) {
        if (w->field_60 != 2 && w->field_60 != 5) {
            r = &w->rows[w->field_56 - 1];
            for (i = 0; i < D_8005071C->field_BA8; i++, r--) {
                r->field_0 = 2;
                r->field_1 = D_8005071C->field_BA9[i];
            }
        }
    }
    if (w->field_60 == 5) {
        w->field_56 = n;
        if (n < 4) {
            w->field_19C = n;
        } else {
            w->field_19C = 3;
        }
        w->field_19E = 0;
        w->field_1A4 = 0;
        w->field_1A2 = 0;
        w->field_1A0 = 0;
    }
}


void func_80017D84(Obj17D84 *a0, s32 a1) {
    s32 i;
    Ent17D84 *rec;
    Src13470 st;

    st.field_4 = 0;
    st.field_10 = a1;
    st.field_11 = 0;
    for (i = 0; i < 16; i++) {
        Text_Close(&a0->field_0[i]);
    }
    rec = &a0->field_6C[a0->field_68];
    for (i = 0; i < 4; i++) {
        switch (rec->field_0) {
        case 0:
            break;
        case 1:
            st.field_C = 109;
            st.field_E = i * 33 + 62;
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD0082);
            Text_OpenDesc(&a0->field_0[i * 4], &st);
            st.field_C = 208;
            st.field_E = i * 33 + 62;
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD00BB);
            Text_OpenDesc(&a0->field_0[i * 4 + 1], &st);
            st.field_C = 109;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)rec->field_4->field_4C;
            Text_OpenDesc(&a0->field_0[i * 4 + 2], &st);
            st.field_C = 208;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)Digi_GetDefaultName(rec->field_4->field_1);
            Text_OpenDesc(&a0->field_0[i * 4 + 3], &st);
            break;
        case 2:
            st.field_C = 109;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)Cd_GetFileEntry(rec->field_1 + 0x1FD00F5);
            Text_OpenDesc(&a0->field_0[i * 4 + 2], &st);
            break;
        case 3:
            st.field_C = 109;
            st.field_E = i * 33 + 50;
            st.field_0 = (s32)Cd_GetFileEntry(0x1FD0114);
            Text_OpenDesc(&a0->field_0[i * 4 + 2], &st);
            break;
        }
        rec++;
    }
}

void func_80017F6C(Actor *a, s16 mode) {
    ModeWork17F6C *w = (ModeWork17F6C *)a->work;

    w->mode = mode;
    if (mode == 3 && ((Rec11F5C *)Item_GetEffectRec(Menu_Ctx->field_108))->field_0 == 2) {
        w->mode = 4;
    }
    w->flag6A = 1;
    switch (w->mode) {
    default:
        w->flag6A = 1;
        break;
    case 4:
    case 6:
        w->flag6A = 0;
        break;
    case 7:
    case 8:
        { s16 t = Menu_Ctx->field_124 - 7; w->parity = (w->mode + t) & 1; }
        break;
    }
}

void func_80018048(Actor *a0) {
    Wk18048 *w = (Wk18048 *)a0->work;
    s32 *slot;
    s32 r;
    s32 i;
    s32 id;
    u8 *p;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_54 = D_80040F1C;
        w->field_68 = 0;
        w->field_50[1] = 0;
        w->field_50[0] = 0;
        func_800179EC((Wk179EC *)w);
        Mem_FillWordsNeg1(w->field_0, 0x14);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->field_64) != 0) {
                break;
            }
            func_80017D84((Obj17D84 *)w, 1);
            Task_NextState1(a0);
            break;
        case 1:
            switch (w->field_60) {
            default:
                Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(0x1FD00D3), 0x80, D_8005070C);
                Task_NextState1(a0);
                break;
            case 3:
                Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(0x1FD009E), 0x80, D_8005070C);
                Task_NextState1(a0);
                break;
            case 4:
                Menu_PickUseItemDirect(a0);
                Task_SetState1(a0, 4);
                break;
            case 5:
                Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(w->field_19E + 0x1FD0109), 0x80, D_8005070C);
                Task_NextState1(a0);
                break;
            case 6:
                Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(0x1FD010C), 0x80, D_8005070C);
                Task_SetState1(a0, 5);
                break;
            case 7:
            case 8:
                Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(w->field_60 + 0x1FD0107), 0x80, D_8005070C);
                id = 0x1FD0072;
                if (w->field_1A6 != 0) {
                    id = 0x1FD009A;
                }
                Text_OpenPacked(&w->field_44, (s32)Cd_GetFileEntry(id), 0, D_80040F38[w->field_1A6]);
                Task_NextState1(a0);
                break;
            }
            if (w->field_6A != 0) {
                Text_OpenPacked(&w->field_48, (s32)Cd_GetFileEntry(0x1FD00FA), 0, D_80050710);
            }
            break;
        case 2:
            if (Menu_MoveGridCursorP1((s32)w->field_50, (s32)w->field_54.field_0) == 0) {
                if (D_8005F70C > 0) {
                    if (w->field_60 != 5) {
                        Snd_PlayById(0xB, 0);
                        Task_SetState0(a0, 2);
                    } else {
                        Menu_UndoLastPick(a0);
                    }
                } else {
                    switch (w->field_60) {
                    case 1:
                    case 2:
                        Menu_ConfirmSinglePick(a0);
                        break;
                    case 3:
                        Menu_UseItemOnDigi(a0);
                        break;
                    case 5:
                        Menu_ConfirmMultiPick(a0);
                        break;
                    case 7:
                        func_800174F8(a0);
                        break;
                    case 8:
                        func_80017214(a0);
                        break;
                    }
                }
            } else {
                Snd_PlayById(0xD, 0);
                if (w->field_50[1] - w->field_68 >= 4) {
                    w->field_68 = w->field_50[1] - 3;
                    func_80017D84((Obj17D84 *)w, 0);
                } else if (w->field_50[1] < w->field_68) {
                    w->field_68 = w->field_50[1];
                    func_80017D84((Obj17D84 *)w, 0);
                }
                Task_SetState1(a0, 1);
            }
            break;
        case 3:
            slot = (s32 *)a0->u34.field_34;
            switch (a0->field_18) {
            case 0:
            default:
                Text_CloseArray(w->field_0, 0x14);
                Task_NextState2(a0);
                break;
            case 1:
                if (Math_RampToZero((s32)a0, &w->field_64) != 0) {
                    break;
                }
                Task_NextState2(a0);
                break;
            case 2:
                Task_Create(D_80040F28[w->field_62].field_0, slot, D_80040F28[w->field_62].field_2);
                Task_NextState2(a0);
                break;
            case 3:
                if (*slot != 0) {
                    break;
                }
                switch (w->field_60) {
                case 1:
                case 2:
                    if (Menu_Ctx->field_35E == 0) {
                        Task_SetState1(a0, 0);
                        Menu_Ctx->field_35C = 2;
                    } else {
                        w->field_62 ^= 1;
                        Task_SetState2(a0, 2);
                    }
                    break;
                case 5:
                    if (Menu_Ctx->field_122 != 0) {
                        Digi_SortRoster();
                        Task_SetState0(a0, 2);
                        break;
                    }
                    Menu_UndoLastPick(a0);
                    Task_SetState1(a0, 0);
                    break;
                case 7:
                    if (Menu_Ctx->field_126 != 0) {
                        Digi_SortRoster();
                        Task_SetState0(a0, 0);
                        break;
                    }
                default:
                    Task_SetState1(a0, 0);
                    break;
                }
                break;
            }
            break;
        case 4:
            switch (a0->field_18) {
            case 0:
                if (Text_IsFinished(w->field_40) != 0) {
                    Task_NextState2(a0);
                }
                break;
            case 1:
                if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_14 > 0 || a0->field_20++ >= 0x1F) {
                    Task_SetState0(a0, 2);
                }
                break;
            }
            break;
        case 5:
            r = func_800136A4(w->field_40);
            if (r == 0) {
                break;
            }
            switch (w->field_60) {
            case 6:
            default:
                if (r == 1) {
                    Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(0x1FD010D), 0x81, D_8005070C);
                    for (i = 0; i < 0x24; i++) {
                        if (D_80050720->elems[i].field_0 >= 3) {
                            D_80050720->elems[i].field_0 = 2;
                        }
                    }
                    for (i = 0; i < Menu_Ctx->field_120; i++) {
                        *Menu_Ctx->field_114[i] = i + 3;
                    }
                    Menu_Ctx->field_122 = -1;
                    Task_SetState1(a0, 4);
                } else {
                    Menu_Ctx->field_122 = 0;
                    Task_SetState0(a0, 2);
                }
                break;
            case 8:
                if (r == 1) {
                    p = (u8 *)Menu_Ctx->field_128;
                    Text_OpenPacked(&w->field_40, (s32)Cd_GetFileEntry(0x1FD0113), 0x81, D_8005070C);
                    *p = 0;
                    Menu_Ctx->field_126 = -1;
                    Snd_PlayById(0xE, 0);
                    Task_SetState1(a0, 4);
                } else {
                    Task_SetState1(a0, 1);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            Text_CloseArray(w->field_0, 0x14);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->field_64) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_800188BC(Actor *actor) {
    Wk188BC *w = (Wk188BC *)actor->work;
    s32 *p;
    void *obj;
    s32 i;
    s32 j;
    s32 f;
    u16 m;
    Row188BC *r;
    Part188BC *e;
    Pair54 tmp;

    if (w->field_64 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x513001B);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            if (w->field_6A != 0) {
            tmp = w->field_50;
            tmp.field_2 = w->field_50.field_2 - w->field_68;
            Menu_SetPartsGridPos(obj, 2, (s32 *)&tmp, &w->field_54);
            Gfx_SetPartsPalette(obj, 2, (actor->field_28 >> 2) & 3);
            {
                s32 fl = (w->field_68 < 1) << 2;
                if (w->field_56 - w->field_68 - 4 <= 0) {
                    fl |= 8;
                }
                Gfx_HidePartsByMask(obj, fl);
            }
            Gfx_SetPartsNumber(obj, 0x10, 2, w->field_50.field_2 + 1);
            Gfx_SetPartsNumber(obj, 0x20, 2, w->field_56);
            } else {
                Gfx_HidePartsByMask(obj, -1);
            }
            break;
        default:
            f = w->field_68 - 1;
            r = &w->rows[f + i];
            j = i - 1;
            if (j >= w->field_56) {
                Gfx_HidePartsByMask(obj, -1);
                break;
            }
            Gfx_HidePartsByMask(obj, 0);
            f = 2;
            if (w->field_6A != 0 && j == w->field_50.field_2 - w->field_68) {
                f = 1;
            }
            switch (r->field_0) {
            case 0:
                Gfx_HidePartsByMask(obj, f | 0xFE4);
                break;
            case 1:
                e = (Part188BC *)r->field_4;
                Gfx_HidePartsByMask(obj, f | D_80040F40[r->field_2 - 1]);
                Gfx_SetPartsNumber(obj, 0x20, 3, e->field_14);
                Gfx_SetPartsNumber(obj, 0x40, 3, e->field_16);
                Gfx_SetPartsNumber(obj, 0x80, 3, e->field_18);
                Gfx_SetPartsNumber(obj, 0x100, 3, e->field_1A);
                break;
            case 2:
            case 3:
                Gfx_HidePartsByMask(obj, -5);
                break;
            }
            break;
        case 5:
            break;
        case 6:
            m = 0xFFFF;
            if (w->field_60 == 7 || w->field_60 == 8) {
                m = 1;
                if (w->field_1A6 != 0) {
                    m = 2;
                }
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->field_64);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void func_80018BF8(Actor *a0, s16 a1) {
    Wk18BF8 *w;
    u8 *p;
    s32 i;
    Blk16 *b;
    s32 *q;

    w = (Wk18BF8 *)a0->work;
    w->field_7C = a1;
    p = Menu_Ctx->field_110;
    w->field_84 = p;
    a0->field_C = p[1];
    Actor_InitTransform((ContC40 *)a0, w->field_B0, w->field_BC);
    w->field_C0 = func_8001E704(a0->field_C);
    w->field_C4 = Anim_GetModelAnimFile(a0->field_C, 0);
    Gfx_AttachModel(a0, w->field_C0)->field_3C = 3;
    Cd_QueueFile(w->field_C0);
    Cd_QueueFile(w->field_C4);
    w->field_C8 = 0;
    w->field_14C = 0;
    w->field_CC = D_80040F64;
    GsInitCoordinate2(0, (Coord1F668 *)&w->field_E8);
    w->field_148 = 1;
    w->field_142 = 11;
    w->field_140 = 0;
    w->field_144 = 0;
    w->field_138 = -0xE3;
    b = (Blk16 *)Cd_GetFileEntry(0x513001F);
    q = (s32 *)Cd_GetFileEntry(0x5130020);
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &b[i]);
    }
    GsSetAmbient(q[0], q[1], q[2]);
    GsSetLightMode(0);
}


void func_80018D78(Actor *a) {
    Wk18D78 *w = (Wk18D78 *)a->work;
    Halves *h;
    Rec18D78 *r;
    u8 **q;
    s32 i;
    Actor *t[1];
    s16 *p;
    s16 *s;
    Elm6F0 *d;

    switch (a->field_10) {
    default:
    case 0:
        w->blk = *(Blk18D78 *)Cd_GetFileEntry(0x513001C);
        Mem_FillWordsNeg1(w, 0x1B);
        GsSetOffset(-0xA0, 0xB4);
        t[0] = a;
        Task_Create(6, (s32 *)a->u34.field_34, (s32)t);
        a->field_30 = 0;
        Task_NextState0(a);
        break;
    case 1:
        switch (a->field_14) {
        default:
        case 0:
            h = (Halves *)Cd_GetFileEntry(0x513001E);
            (*(Actor **)a->u34.field_34)->field_3C->field_3C = 4;
            if (Math_RampToOne((s32)a, &w->field_80) != 0) {
                break;
            }
            Text_PrintIdList((s32 *)w, (Key13558 *)Cd_GetFileEntrySubPtr(0x513001D, 0), 1);
            r = w->field_84;
            Text_OpenPacked(&w->field_50, (s32)r->field_4C, 0x81, h[0]);
            w->field_88 = Digi_GetDefaultName(r->field_1);
            w->field_8C = Cd_GetFileEntry(((s32 (*)(s32))func_8001D934)(r->field_1) + 0x1FD00C3);
            w->field_90 = Cd_GetFileEntry(((s32 (*)(s32))func_8001D958)(r->field_1) + 0x1FD00C6);
            w->field_94 = Cd_GetFileEntry(((s32 (*)(s32))func_8001D980)(r->field_1) + 0x1FD00CA);
            q = w->field_98;
            for (i = 0; i < 2; i++) {
                if (r->field_47[i] != 0) {
                    *q++ = Digi_GetDefaultName(r->field_47[i]);
                }
            }
            *q = 0;
            Text_PrintList(&w->field_54, &h[1], (s32 *)&w->field_88, 1);
            Task_NextState1(a);
            break;
        case 1:
            w->field_C8 = 1;
            GsSetOffset(-0xA0, w->field_138[0] * 80 / 682 + 180);
            Task_NextState1(a);
            break;
        case 2:
            Math_RampToOne((s32)a, &w->field_14C);
            p = w->field_138;
            s = w->field_140;
            a->field_30 = 1;
            p[1] += s[1];
            if (D_8005F6F0[0].field_4 != 0) {
                s[1] = (s[1] - 5 < -0x22) ? -0x22 : s[1] - 5;
            }
            if (D_8005F6F0[0].field_0 != 0) {
                s[1] = (s[1] + 5 >= 0x23) ? 0x22 : s[1] + 5;
            }
            if (D_8005F6F0[0].field_C != 0) {
                p[0] = (p[0] + 0xB > 0) ? 0 : p[0] + 0xB;
            }
            if (D_8005F6F0[0].field_8 != 0) {
                p[0] = (p[0] - 0xB < -0x2AA) ? -0x2AA : p[0] - 0xB;
            }
            GsSetOffset(-0xA0, p[0] * 80 / 682 + 180);
            d = D_8005F6F0;
            if (d->field_1C > 0 || d->field_10 > 0) {
                Task_SetState0(a, 2);
                if (d->field_10 > 0) {
                    Menu_Ctx->field_35E = -1;
                    Snd_PlayById(0xE, 0);
                } else {
                    Menu_Ctx->field_35E = 0;
                    Snd_PlayById(0xB, 0);
                }
            }
            break;
        }
        break;
    case 2:
        switch (a->field_14) {
        default:
        case 0:
            Text_CloseArray(w, 0x1B);
            Task_NextState1(a);
            break;
        case 1:
            Math_RampToZero((s32)a, &w->field_14C);
            if (Math_RampToZero((s32)a, &w->field_80) == 0) {
                GsSetOffset(0, 0);
                Task_SetState0(a, 3);
            }
            break;
        }
        break;
    }
}


/* View of Actor.work used by func_80019214 (fields 0x80..0x14C). */
typedef struct {
    u8 _pad00[0x80];
    /* 0x80 */ s32 field_80;
    /* 0x84 */ s32 *field_84;
    u8 _pad88[0xB0 - 0x88];
    /* 0xB0 */ s32 field_B0;
    /* 0xB4 */ s32 field_B4;
    /* 0xB8 */ s32 field_B8;
    u8 _padBC[0xC0 - 0xBC];
    /* 0xC0 */ s32 field_C0;
    u8 _padC4[0xC8 - 0xC4];
    /* 0xC8 */ s32 field_C8;
    /* 0xCC */ s32 field_CC;
    /* 0xD0 */ s32 field_D0;
    /* 0xD4 */ s32 field_D4;
    /* 0xD8 */ s32 field_D8;
    /* 0xDC */ s32 field_DC;
    /* 0xE0 */ s32 field_E0;
    /* 0xE4 */ s32 field_E4;
    /* 0xE8 */ s32 field_E8;
    /* 0xEC */ s32 field_EC;
    u8 _padF0[0x100 - 0xF0];
    /* 0x100 */ s32 field_100;
    /* 0x104 */ s32 field_104;
    /* 0x108 */ s32 field_108;
    u8 _pad10C[0x138 - 0x10C];
    /* 0x138 */ s32 field_138;
    u8 _pad13C[0x148 - 0x13C];
    /* 0x148 */ s32 field_148;
    /* 0x14C */ s32 field_14C;
} Wk19214;

/* Record reached through Wk19214.field_84. */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 field_D;
    u8 _padE;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
} Rec19214;

/* Node reached through Actor.u38.ptr38. */
typedef struct {
    u8 _pad00[0x58];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
} Nd19214;

/* Stack context passed to GsSetRefView2. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 *field_1C;
} Ctx19214;

extern s32 GsSetRefView2(Ctx19214 *);

void func_80019214(Actor *actor) {
    Wk19214 *work;
    Rec19214 *rec;
    s32 *list;
    s32 *p;
    void *obj;
    Nd19214 *node;
    Ctx19214 ls;

    work = (Wk19214 *)actor->work;
    if (work->field_80 == 0) {
        goto Ltail;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130021);
    rec = (Rec19214 *)work->field_84;
    if (*p == 0) {
        goto Ltail;
    }
    list = p;
    do {
        obj = Cd_GetFileEntry(*list);
        list++;
        Gfx_SetPartsNumber(obj, 0x2, 3, rec->field_14);
        Gfx_SetPartsNumber(obj, 0x4, 3, rec->field_16);
        Gfx_SetPartsNumber(obj, 0x8, 3, rec->field_18);
        Gfx_SetPartsNumber(obj, 0x10, 3, rec->field_1A);
        Gfx_SetPartsNumber(obj, 0x20, 2, rec->field_D);
        Gfx_SetPartsNumber(obj, 0x40, 3, rec->field_1C);
        Gfx_SetPartsNumber(obj, 0x80, 3, rec->field_1E);
        Gfx_SetPartsNumber(obj, 0x100, 3, rec->field_20);
        Gfx_SetPartsNumber(obj, 0x200, 8, rec->field_10);
        Gfx_SetPartsNumber(obj, 0x400, 8, Digi_GetExpToNextLevel(rec->field_D, rec->field_F, rec->field_10));
        Gfx_SetPartsScale((Ent1D550 *)obj, 0x1000, work->field_80);
        Gfx_DrawParts((s32)obj);
    } while (*list != 0);

Ltail:
    work->field_148 = 0;
    func_8002D744(&work->field_138, &work->field_EC);
    work->field_100 = work->field_B0;
    work->field_104 = work->field_B4;
    work->field_108 = work->field_B8;
    work->field_E8 = 0;
    ls.field_0 = work->field_CC;
    ls.field_4 = work->field_D0;
    ls.field_8 = work->field_D4;
    ls.field_C = work->field_D8;
    ls.field_10 = work->field_DC;
    ls.field_14 = work->field_E0;
    ls.field_18 = 0;
    ls.field_1C = &work->field_E8;
    GsSetProjection(work->field_E4);
    GsSetRefView2(&ls);
    if (work->field_C8 == 0) {
        return;
    }
    if (work->field_14C == 0) {
        return;
    }
    if (work->field_C8 == 1) {
        Anim_SetModelAnim(actor, 0);
        work->field_C8 = work->field_C8 + 1;
    }
    node = (Nd19214 *)actor->u38.ptr38;
    node->field_58 = work->field_14C;
    node->field_5C = work->field_14C;
    node->field_60 = work->field_14C;
    Gfx_AttachModel(actor, work->field_C0);
    Anim_StepModelAnim(actor);
    Actor_UpdateTransform(actor);
    Gfx_CalcModelBoneMatrices(actor);
    Gfx_DrawTexModel(actor, 0);
}

void func_800194C8(a)
Actor194C8 *a;
{
    u8 *tbl;
    s32 i;
    s32 r, c;
    u8 *q;
    void *base;

    tbl = a->field_118;

    for (i = 3; i >= 0; i--) {
        a->records[i].count = 0;
    }

    for (i = 0; i < 0xC; i++) {
        q = tbl + i;
        if (q[0x22] == 0) continue;
        r = func_8001EE34(q[0x22]);
        c = a->records[r].count;
        a->records[r].arr[c] = q[0x22];
        a->records[r].count = (u16)a->records[r].count + 1;
    }

    for (i = 0; i < 4; i++) {
        base = Cd_GetFileEntry(0x5130022);
        a->block64[i] = *(Blk12 *)((u8 *)base + i * 0xC);
        a->field_94[i] = 0;
        a->slot54[i].v = 0;
        *(s16 *)((u8 *)&a->block64[i] + 2) = a->records[i].count;
    }
}

void func_80019614(Actor194C8 *w, s32 arg1) {
    Src16198 st;
    s32 i;
    s32 ch;
    s32 n;
    s32 j;
    s32 k;
    s32 d0;
    s32 d;
    s32 f;
    s32 m;

    for (i = 6; i < 18; i++) {
        Text_Close(&w->field_0[i]);
    }
    st.field_4 = 0;
    st.field_10 = arg1;
    for (ch = 0; ch < 4; ch++) {
        st.field_C = ((Halves *)Cd_GetFileEntry(0x5130025))[ch];
        d0 = w->field_94[ch];
        d = w->records[ch].count - d0;
        n = 3;
        if (d < 4) {
            n = d;
        }
        for (j = 0; j < n; j++) {
            f = 0;
            if (w->field_114 != ch) {
                f = 1;
            } else if (w->slot54[ch].field_2 != j + d0) {
                f = 1;
            }
            st.field_11 = f;
            st.field_0 = func_8001ED84(w->records[ch].arr[j + d0]);
            m = j + 6;
            Text_OpenDesc(&w->field_0[ch * 3 + m], (Src13470 *)&st);
            st.field_C.hi += 11;
        }
        Text_SetColor(w->field_0[ch + 2], w->field_114 != ch);
    }
}


void func_800197FC(Actor *arg0, s16 arg1) {
    arg0->work->field_A4 = arg1;
}

void func_80019808(Actor *a0) {
    Actor194C8 *w = (Actor194C8 *)a0->work;
    Halves h;
    Src16198 st;
    s32 i;
    s32 k;
    s32 id;
    s32 t;
    s32 j;
    s32 n;

    switch (a0->field_10) {
    case 0:
    default:
        w->field_118 = Menu_Ctx->field_110;
        func_800194C8(w);
        w->field_114 = 0;
        Mem_FillWordsNeg1(&w->field_0, 0x15);
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->field_14) {
        case 0:
        default:
            if (Math_RampToOne((s32)a0, &w->field_A8) != 0) {
                break;
            }
            Text_PrintIdList(&w->field_0, (Key13558 *)Cd_GetFileEntrySubPtr(0x5130024, 0), 1);
            func_80019614(w, 1);
            h.lo = 0x13;
            h.hi = 0x32;
            Text_OpenPacked(&w->field_50, (s32)&w->field_118[0x4C], 1, h);
            Task_NextState1(a0);
            break;
        case 1:
            i = w->field_114;
            k = Menu_GridIndexColMajor(&w->slot54[i].v, (s16 *)w->block64[i].data);
            Text_Close(&w->field_48);
            Text_Close(&w->field_4C);
            if (k < w->records[i].count) {
                id = w->records[i].arr[w->slot54[i].field_2];
                st.field_C = D_80050714;
                st.field_10 = 0x80;
                st.field_11 = 0;
                st.field_0 = func_8001EDD4(id);
                Text_OpenDesc(&w->field_48, (Src13470 *)&st);
                st.field_C.hi = 0xCA;
                st.field_0 = (s32)Cd_GetFileEntry(0x1FD0150);
                Text_FormatNumber(w->field_11C, func_8001EE80(id), -4);
                st.field_4 = (s32)w->field_11C;
                Text_OpenDesc(&w->field_4C, (Src13470 *)&st);
            }
            Task_NextState1(a0);
            break;
        case 2:
            t = D_8005F6F0[0].field_4;
            if (t > 0 || D_8005F6F0[0].field_0 > 0) {
                n = w->field_114;
                if (t > 0) {
                    n--;
                } else {
                    n++;
                }
                w->field_114 = n & 3;
                Snd_PlayById(0xD, 0);
                func_80019614(w, 0);
                Task_SetState1(a0, 1);
            } else {
                j = w->field_114;
                if (Menu_MoveGridCursorP1((s32)&w->slot54[j], (s32)&w->block64[j]) != 0) {
                    Menu_ScrollToShow(&w->field_94[j], w->slot54[j].field_2, 3);
                    func_80019614(w, 0);
                    Snd_PlayById(0xD, 0);
                    Task_SetState1(a0, 1);
                } else if (D_8005F6F0[0].field_1C > 0 || D_8005F6F0[0].field_10 > 0) {
                    Task_SetState0(a0, 2);
                    if (D_8005F6F0[0].field_10 > 0) {
                        Menu_Ctx->field_35E = -1;
                        Snd_PlayById(0xE, 0);
                    } else {
                        Menu_Ctx->field_35E = 0;
                        Snd_PlayById(0xB, 0);
                    }
                }
            }
            break;
        }
        break;
    case 2:
        switch (a0->field_14) {
        case 0:
        default:
            Text_CloseArray(&w->field_0, 0x15);
            Task_NextState1(a0);
            break;
        case 1:
            if (Math_RampToZero((s32)a0, &w->field_A8) == 0) {
                Task_SetState0(a0, 3);
            }
            break;
        }
        break;
    }
}


void func_80019BF4(Actor *actor) {
    Wk19BF4 *w = (Wk19BF4 *)actor->work;
    s32 *p;
    s32 *list;
    void *obj;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    u16 v;
    Pair54 tmp;

    if (w->field_A8 == 0) {
        return;
    }
    p = (s32 *)Cd_GetFileEntry(0x5130026);
    if (*p == 0) {
        return;
    }
    i = 0;
    do {
        obj = Cd_GetFileEntry(p[i]);
        switch (i) {
        case 0:
            k = w->field_114;
            v = D_80040F98[k];
            if (w->field_AC[k].field_0 != 0) {
                tmp = w->field_54[k];
                tmp.field_2 = w->field_54[k].field_2 - w->field_94[k];
                Menu_SetPartsGridPos(obj, 0x4000, (s32 *)&tmp, &w->field_64[k].field_0);
                Gfx_SetPartsPalette(obj, 0x4000, (actor->field_28 >> 2) & 3);
            } else {
                v |= 0x4000;
            }
            Gfx_HidePartsByMask(obj, v);
            break;
        case 1:
            m = 0xFFFFF;
            for (j = 0; j < 4; j++) {
                if (w->field_94[j] != 0) {
                    if (w->field_114 == j) {
                        m -= 1 << (j * 4 + 1);
                    } else {
                        m -= 1 << (j * 4 + 2);
                    }
                }
                if (w->field_64[j].field_2 - w->field_94[j] >= 4) {
                    if (w->field_114 == j) {
                        m -= 1 << (j * 4 + 3);
                    } else {
                        m -= 1 << (j * 4 + 4);
                    }
                }
            }
            Gfx_HidePartsByMask(obj, m);
            break;
        }
        Gfx_SetPartsScale(obj, 0x1000, w->field_A8);
        Gfx_DrawParts((s32)obj);
        i++;
    } while (p[i] != 0);
}


void func_80019E40(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void Task_SpawnListFromFile(Actor *a0) {
    Ent19E50 *p;
    s32 *slot;
    s32 end = -1;
    s32 *s;

    if (a0->field_10 != 0) {
        return;
    }
    s = (s32 *)a0->u34.field_34;
    p = (Ent19E50 *)Cd_GetFileOrNull(a0->work->field_0);
    slot = s;
loop:
    if (p->field_0 == end) {
        goto done;
    }
    Task_Create(p->field_0, slot, (s32)&p->field_10);
    slot++;
    p = (Ent19E50 *)((u8 *)p + p->field_C);
    goto loop;
done:
    Task_NextState0(a0);
}


void func_80019EE0(Actor *arg0, s32 arg1) {
    arg0->field_8 = arg1;
}

void func_80019EE8(Actor *a0) {
    s32 v1 = a0->field_10;
    u16 *a1 = (u16 *)&a0->work->field_0;
    switch (v1) {
    case 1:
        if (a0->field_14 == 0 || a0->field_14 != v1) {
            u16 nv = *a1 + 0x555;
            *a1 = nv;
            if ((s16)nv >= 0x1000) {
                *a1 = 0x1000;
                Task_NextState1(a0);
            }
        }
        break;
    case 0:
        Task_NextState0(a0);
        break;
    case 2: {
        s16 nv = *a1 - 0x555;
        *a1 = nv;
        if (nv <= 0) {
            *a1 = 0;
            Task_NextState0(a0);
        }
        break;
    }
    }
}

void func_80019FB4(Actor *arg0) {
    ActorWork *w = arg0->work;
    void *e = Cd_GetFileEntry(D_80040FD0[arg0->field_8]);
    Gfx_SetPartsScale(e, 0x1000, *(s16 *)w);
    Gfx_DrawParts((s32)e);
}

void Snd_ServiceSlotLoads(void) {
    s32 i;
    Ent54C48 *e;
    u32 n;
    u32 k;
    s32 *src;
    s32 *dst;
    s32 p;
    s32 j;

    for (i = 0; i < 3; i++) {
        e = &D_80054C48[i];
        switch (e->field_4) {
        case 0:
            break;
        case 1:
            if (e->field_0 == 0) {
                e->field_4 = 0;
                break;
            }
            e->field_20 = D_80041194[e->field_0]->field_0 >> 16;
            e->field_24 = D_80041194[e->field_0]->field_4 >> 16;
            Cd_QueueFile(e->field_24);
            e->field_4++;
            break;
        case 2:
            if (Cd_GetFileState(e->field_24) == 3) {
                src = (s32 *)Cd_GetFileSync(e->field_24);
                n = D_800411FC[i];
                dst = e->field_28;
                if ((u32)src + n > 0x801FFFFF) {
                    n = 0x801FFFFC - (u32)src;
                }
                n >>= 2;
                for (k = 0; k < n; k++) {
                    *dst++ = *src++;
                }
                e->field_4++;
            }
            break;
        case 3:
            Cd_QueueFile(e->field_20);
            e->field_4++;
            break;
        case 4:
            e->field_8 = SsVabOpenHead(Mem_GetOffsetEntry(D_80041194[e->field_0]->field_4, e->field_28), i);
            e->field_4++;
            break;
        case 5:
            if (Cd_GetFileState(e->field_20) == 3) {
                Cd_LockFile(e->field_20);
                e->field_8 = SsVabTransBody((s32)Cd_GetFileEntry(D_80041194[e->field_0]->field_0), e->field_8);
                e->field_4++;
            }
            break;
        case 6:
            e->field_A = 0;
            e->field_4++;
        case 7:
            j = e->field_A;
            p = *(j + D_80041194[e->field_0]->field_8);
            if (p != 0) {
                e->field_C[j] = SsSepOpen(Mem_GetOffsetEntry(p, e->field_28), e->field_8, 0x10);
                e->field_A++;
            } else {
                e->field_4++;
            }
            break;
        default:
            if (SsVabTransCompleted(0)) {
                Cd_UnlockFile(e->field_20);
                e->field_4 = 0;
            }
            break;
        }
    }
}


s32 Snd_AnySlotLoading(void) {
    s32 found = 0;
    s32 i = 0;
    Ent54C48 *p = D_80054C48;
    for (; i < 3; i++, p++) {
        if (p->field_4 != 0) found = 1;
        if (found) break;
    }
    return found;
}

void Snd_StopAll(void) {
    Ent54C48 *p;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 3; i++) {
        p = &D_80054C48[i];
        if (p->field_8 != -1) {
            for (j = 0; j < p->field_A; j++) {
                for (k = 0; k < 0x10; k++) {
                    SsSepStop(p->field_C[j], k);
                }
            }
        }
    }
    SsUtAllKeyOff(0);
    Snd_CurrentId = -1;
}

void Snd_StopById(s32 id) {
    s32 i;
    s32 j;
    s32 k;

    if (id != -1) {
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        if (D_80054C48[i].field_4 == 0) {
            SsSepStop(D_80054C48[i].field_C[j], k);
        }
        if (Snd_CurrentId == id) {
            Snd_CurrentId = -1;
        }
    }
}

void Snd_UnloadSlot(s32 idx) {
    s32 i;
    s32 k;

    if (D_80054C48[idx].field_8 == -1) {
        return;
    }
    for (i = 0; i < D_80054C48[idx].field_A; i++) {
        for (k = 0; k < 0x10; k++) {
            SsSepStop(D_80054C48[idx].field_C[i], k);
        }
        func_80032844(D_80054C48[idx].field_C[i]);
    }
    SsVabClose(D_80054C48[idx].field_8);
    D_80054C48[idx].field_4 = 0;
    D_80054C48[idx].field_0 = -1;
    D_80054C48[idx].field_A = 0;
    D_80054C48[idx].field_8 = -1;
}

void Snd_SetSlotContent(s32 idx, s32 v) {
    Ent54C48 *e = &D_80054C48[idx];

    if (e->field_0 != v) {
        Snd_UnloadSlot(idx);
        e->field_4 = 1;
        e->field_0 = v;
        if (Snd_CurrentId != -1 && idx == ((Snd_CurrentId & 0xF00) >> 8)) {
            Snd_StopById(Snd_CurrentId);
        }
    }
}

void Snd_PlayById(s32 id, s32 set) {
    s32 k;
    s32 i;
    s32 j;
    if (Snd_CurrentId != id) {
        if (set != 0 && Snd_CurrentId != -1) {
            Snd_StopById(Snd_CurrentId);
        }
        i = id >> 8;
        j = (id >> 4) & 0xF;
        k = id & 0xF;
        SsSepStop(D_80054C48[i].field_C[j], k);
        func_80035C4C(D_80054C48[i].field_C[j], k, 0x7F, 0x7F);
        SsSepPlay(D_80054C48[i].field_C[j], k, 1, 1);
        if (set != 0) {
            Snd_CurrentId = id;
        }
    }
}

/* File-local view of an Ent54C48 element with the fields Snd_Init stamps. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    u8 _padC[0x28 - 0xC];
    /* 0x28 */ s32 field_28;
} Ew54C48; /* 0x2C */

extern u8 D_80050A48;

extern void SsSetTableSize(void *, s16, s16);
extern void SsSetTickMode(s32);
extern void SsStart2();
extern void SsSetMVol(s16, s16);
extern void SsSetSerialAttr(s8, s8, s8);
extern void SsSetSerialVol(s8, s16, s16);
extern s16 SsUtSetReverbType(s16);
extern void SsUtSetReverbDepth(s16, s16);
extern void SsUtReverbOn();
extern s32 Mem_Alloc(s32, s32);
extern void Snd_SetSlotContent(s32, s32);
extern void Cd_ServiceQueue();

void Snd_Init(void) {
    s32 v0;
    s32 i;
    Ew54C48 *e;

    SsSetTableSize(&D_80050A48, 6, 0x10);
    SsSetTickMode(0x1000);
    SsStart2();
    SsSetMVol(0x7F, 0x7F);
    SsSetSerialAttr(0, 0, 1);
    SsSetSerialVol(0, 0x7F, 0x7F);
    SsUtSetReverbType(3);
    SsUtSetReverbDepth(0, 0);
    SsUtReverbOn();

    v0 = Mem_Alloc(D_800411FC[0] + D_800411FC[1] + D_800411FC[2], 4);
    e = (Ew54C48 *)D_80054C48;
    e[0].field_28 = v0;
    v0 += D_800411FC[0];
    e[1].field_28 = v0;
    v0 += D_800411FC[1];
    e[2].field_28 = v0;
    for (i = 0; i < 3; i++) {
        e[i].field_4 = 0;
        e[i].field_0 = -1;
        e[i].field_A = 0;
        e[i].field_8 = -1;
    }

    Snd_SetSlotContent(0, 1);
    do {
        Snd_ServiceSlotLoads();
        Cd_ServiceQueue();
    } while (D_80054C48[0].field_4 != 0);

    Snd_SetSlotContent(1, 0xE);
    do {
        Snd_ServiceSlotLoads();
        Cd_ServiceQueue();
    } while (D_80054C48[1].field_4 != 0);
}

void Snd_SaveCurrentId(void) {
    Snd_SavedId = Snd_CurrentId;
}


void Snd_RestoreSavedId(void) {
    Snd_PlayById(Snd_SavedId, 1);
}


void Text_PushReturn(s32 arg0) {
    Text_ReturnStack.data[Text_ReturnStack.count] = arg0;
    Text_ReturnStack.count = Text_ReturnStack.count + 1;
}

s32 Text_PopReturn(void) {
    if (Text_ReturnStack.count == 0) {
        return 0;
    }
    Text_ReturnStack.count = Text_ReturnStack.count - 1;
    return Text_ReturnStack.data[Text_ReturnStack.count];
}

extern Elem20 *Gfx_FindOrLoadTexSlot(s32);
extern void Task_Create(u32, s32 *, s32);

void func_8001A958(Actor *a0) {
    if (a0->field_10 != 0) {
        return;
    }
    Gfx_FindOrLoadTexSlot(0x13A0000);
    if ((D_8005F788[0] & 0xF00) != 0x500) {
        Gfx_FindOrLoadTexSlot(0x1100000);
        Task_Create(0xA, a0->u34.field_34, 0);
    }
    Task_NextState0(a0);
}

extern Elem20 *Gfx_FindOrLoadTexSlot(s32);
extern Obj6A8C0 *func_8006A8C0(s32);
extern void func_8006A920(void *, s32 *);
extern s32 func_8006A9F8(void *);
extern void func_8006AA0C(Obj6A8C0 *, s32);
extern void func_80071FBC(s32 *);
extern s32 func_800720FC(void);
extern void func_80063C84(void);
extern s16 D_8004142C[];
extern s32 D_80041440[];
extern u8 D_8005E633;
extern u8 D_8005E6F0;

void Text_UpdateAllBoxes(Actor *a0) {
    Elem20 *font[2];
    Pair54 glyph;
    Pair54 cell;
    Pair54 pos;
    s32 num[2];
    s32 nums[3];
    Wk1A9C8 *wk;
    Actor **slots;
    s32 row;
    Ft4_1A9C8 *pkt;
    s32 *ot;
    s32 cols;
    s32 page;
    s32 nFA;
    s32 nFB;
    s32 nF9;
    s32 nF8;
    s32 nF6;
    s32 nF5;
    s32 nF4b;
    s32 nF4a;
    s32 nF4c;
    u8 nF4d;
    s32 grew;
    Rec34 *r;
    u8 *s;
    s32 stop;
    s32 line;
    s32 c;
    s32 v;
    s32 vf;
    u8 k9;
    s32 k4;
    s32 id;
    u8 k;
    s32 j;
    s32 *np;
    u8 isF6;
    u8 mode2;
    Obj6A8C0 *h;
    Elm6F0 *e;
    Elm6F0 *tb;

    pkt = (Ft4_1A9C8 *)((Gl1A9C8 *)&D_8005F770)->field_2C;
    slots = (Actor **)a0->u34.field_34;
    wk = (Wk1A9C8 *)a0->work;
    tb = D_8005F6F0;
    row = 0;
    do {
        if (wk->rec[row].field_0 != 0) {
            r = &wk->rec[row];
            nFA = 0;
            nFB = 0;
            nF9 = 0;
            nF8 = 0;
            nF6 = 0;
            nF5 = 0;
            nF4b = 0;
            nF4a = 0;
            s = (u8 *)r->field_8;
            nF4c = 0;
            pos = *(Pair54 *)&r->field_1C;
            nF4d = 0;
            ot = ((Gl1A9C8 *)&D_8005F770)->field_138[r->field_31];
            line = 0;
            page = 0;
            r->field_2 = r->field_20;
            if (r->field_27 == 0 && r->field_6 != 0) {
                r->field_21 += ((Gl1A9C8 *)&D_8005F770)->field_8;
                if (r->field_21 >= r->field_6) {
                    r->field_22++;
                    r->field_21 -= r->field_6;
                }
            }
            if (r->field_1 != 0) {
                glyph.field_0 = 8;
                glyph.field_2 = 0xD;
                cell.field_0 = 9;
                cols = 0xD;
                cell.field_2 = 0xE;
                font[0] = Gfx_FindOrLoadTexSlot(0x1100000);
                font[1] = Gfx_FindOrLoadTexSlot(0x1100000);
            } else {
                glyph.field_0 = 7;
                cell.field_0 = 7;
                cols = 0x11;
                glyph.field_2 = 9;
                cell.field_2 = 0xA;
                font[0] = Gfx_FindOrLoadTexSlot(0x13A0000);
                font[1] = Gfx_FindOrLoadTexSlot(0x13A0000);
            }
            Text_ReturnStack.count = 0;
            stop = 0;
            grew = 0;
            do {
                switch (*s) {
                case 0xFF:
                    vf = Text_PopReturn();
                    if (vf == 0) {
                        r->field_6 = 0;
                        r->field_23 = 1;
                        stop = 1;
                        break;
                    }
                    s = (u8 *)vf - 1;
                    line--;
                    break;
                case 0xFE:
                    pos.field_0 = r->field_1C;
                    pos.field_2 += r->field_4;
                    break;
                case 0xFD:
                    pos.field_0 += r->field_3;
                    if (grew == 0 && line + 1 >= r->field_22) {
                        grew = 1;
                        r->field_22++;
                    }
                    break;
                case 0xFC:
                    r->field_8 = (s32)(s + 1);
                    r->field_22 = 0;
                    r->field_24 = 0;
                    r->field_25 = 0;
                    r->field_26 = 0;
                    r->field_2A = 0;
                    r->field_2B = 0;
                    r->field_2C = 0;
                    r->field_2D = 0;
                    r->field_2E = 0;
                    r->field_2F = 0;
                    break;
                case 0xFB:
                    if (r->field_25 == nFB) {
                        stop = 1;
                        if (tb[r->field_30].field_14 > 0) {
                            r->field_25 = nFB + 1;
                            r->field_27 = 0;
                            Snd_PlayById(0x13, 0);
                        } else {
                            wk->field_A28 += ((Gl1A9C8 *)&D_8005F770)->field_8;
                            if (wk->field_A28 >= 0x18) {
                                wk->field_A28 -= 0x18;
                            }
                            c = ((wk->field_A28 / 6) & 3) + 0x4F;
                            r->field_27 = 1;
                            goto draw;
                        }
                    }
                    nFB++;
                    break;
                case 0xFA:
                    s++;
                    if (r->field_24 == nFA) {
                        switch (a0->field_14) {
                        default:
                        case 0:
                            Snd_PlayById((*s & 1) ? 0x38 : 0x37, 0);
                            switch (*s) {
                            case 0:
                                Task_Create(4, (s32 *)&slots[row + 1], 0);
                                r->field_1C = -0x90;
                                r->field_1E = 0x34;
                                break;
                            case 2:
                                Task_Create(4, (s32 *)&slots[row + 1], 1);
                                r->field_1C = -0x90;
                                r->field_1E = 0x42;
                                break;
                            case 6:
                                Task_Create(4, (s32 *)&slots[row + 1], 3);
                                r->field_1C = -0x90;
                                r->field_1E = 0x42;
                                break;
                            case 4:
                                Task_Create(4, (s32 *)&slots[row + 1], 2);
                                r->field_1C = -0x90;
                                r->field_1E = 0x12;
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                if (slots[row + 1] != 0) {
                                    Task_SetState0(slots[row + 1], 2);
                                }
                                Task_NextState1(a0);
                                break;
                            }
                            r->field_27 = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            if (slots[row + 1]->field_14 == 1) {
                                r->field_27 = 0;
                                r->field_24++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        case 2:
                            if (slots[row + 1] == 0) {
                                r->field_27 = 0;
                                r->field_24++;
                                Task_SetState1(a0, 0);
                            }
                            break;
                        }
                    }
                    nFA++;
                    break;
                case 0xF9:
                    s++;
                    k9 = *s;
                    if (k9 & 1) {
                        if (r->field_26 == nF9) {
                            if (slots[((k9 >> 1) & 1) + 0x33] != 0) {
                                Task_SetState0(slots[((k9 >> 1) & 1) + 0x33], 2);
                            }
                            r->field_26++;
                            Snd_PlayById(0x3A, 0);
                        }
                    } else if (r->field_26 == nF9) {
                        num[1] = (k9 >> 1) & 1;
                        s++;
                        num[0] = *s++ * 100;
                        num[0] += *s++ * 10;
                        num[0] += *s;
                        if (slots[num[1] + 0x33] != 0) {
                            func_80011B58(slots[num[1] + 0x33], num[0]);
                        } else {
                            Task_Create(5, (s32 *)&slots[num[1] + 0x33], (s32)num);
                        }
                        r->field_26++;
                        Snd_PlayById(0x39, 0);
                    } else {
                        s += 3;
                    }
                    nF9++;
                    break;
                set1:
                    r->field_29 = 1;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                set0:
                    r->field_29 = 0;
                    Snd_PlayById(0xC, 0);
                    goto cntF8;
                case 0xF8:
                    s++;
                    if (r->field_28 == nF8) {
                        switch (*s) {
                        default:
                        case 0:
                            stop = 1;
                            r->field_27 = 1;
                            e = &tb[r->field_30];
                            if (e->field_3A & 0x6000) {
                                goto set1;
                            }
                            if (e->field_3A & 0x9000) {
                                goto set0;
                            }
                            if (e->field_14 > 0) {
                                r->field_27 = 0;
                                r->field_28++;
                                Flag_Set(0x10, 1);
                                Flag_Set(0x11, r->field_29);
                                Snd_PlayById(0xA, 0);
                            }
                        cntF8:
                            nF8++;
                            goto next;
                        case 1:
                            c = 0x53;
                            if (r->field_29 == 0) {
                                goto draw;
                            }
                            break;
                        case 2:
                            c = 0x53;
                            if (r->field_29 == 1) {
                                goto draw;
                            }
                            break;
                        }
                    }
                    pos.field_0 += r->field_3;
                    break;
                case 0xF6:
                case 0xF7:
                    isF6 = *s == 0xF6;
                    mode2 = ((Gl1A9C8 *)&D_8005F770)->field_18 / 256 == 2;
                    s++;
                    if (r->field_2A == nF6) {
                        switch (a0->field_14) {
                        case 0:
                        default:
                            np = nums;
                            for (j = 0; j < 3; j++) {
                                *np = *s++ * 100;
                                *np += *s++ * 10;
                                *np += *s++;
                                np++;
                            }
                            if (mode2) {
                                func_80071FBC(nums);
                            } else {
                                h = func_8006A8C0(nums[0]);
                                wk->field_A2C = h;
                                func_8006A920(h, &nums[1]);
                            }
                            r->field_27 = 1;
                            Task_NextState1(a0);
                            break;
                        case 1:
                            break;
                        }
                        if (mode2 == 0) {
                            if (isF6 == 0 || func_8006A9F8(wk->field_A2C) != 0) {
                                goto advF6;
                            }
                            goto nextF6;
                        }
                        if (func_800720FC() != 0) {
                            goto nextF6;
                        }
                    advF6:
                        r->field_27 = 0;
                        r->field_2A++;
                        Task_SetState1(a0, 0);
                    } else {
                        s += 8;
                    }
                nextF6:
                    nF6++;
                    break;
                case 0xF5:
                    if (r->field_2B == nF5) {
                        stop = 1;
                        if (wk->field_A30 == 0x1E) {
                            r->field_2B = nF5 + 1;
                            r->field_27 = 0;
                            wk->field_A30 = 0;
                        } else {
                            wk->field_A30++;
                            r->field_27 = 1;
                        }
                    }
                    nF5++;
                    break;
                case 0xF4:
                    s++;
                    k4 = *s;
                    s++;
                    if (k4 < 0x10) {
                        if (r->field_2D == nF4a) {
                            s32 d0, d1;
                            d0 = *s++;
                            d1 = *s++;
                            h = func_8006A8C0(d0 * 100 + d1 * 10 + *s);
                            if (h != 0) {
                                func_8006AA0C(h, k4 + 0x1E);
                            }
                            r->field_2D++;
                        } else {
                            s += 2;
                        }
                        nF4a++;
                    } else if (k4 < 0x20) {
                        if (r->field_2C == nF4b) {
                            s32 n;
                            n = *s++ * 100;
                            n += *s++ * 10;
                            do {} while (0);
                            k4 = (k4 - 0x10) << 10;
                            h = func_8006A8C0(n + *s);
                            if (h != 0) {
                                h->field_38->field_42 = k4;
                            }
                            r->field_2C++;
                        } else {
                            s += 2;
                        }
                        nF4b++;
                    } else if (k4 < 0x30) {
                        if (r->field_2E == nF4c) {
                            switch (a0->field_14) {
                            case 0:
                            default:
                                num[0] = k4 & 0xF;
                                num[1] = 0;
                                Task_Create(0x16, (s32 *)&slots[0x35], (s32)num);
                                a0->field_14++;
                                r->field_27 = 1;
                                break;
                            case 1:
                                s += 2;
                                if (slots[0x35] == 0) {
                                    a0->field_14 = 0;
                                    r->field_27 = 0;
                                    r->field_2E++;
                                }
                                break;
                            }
                        } else {
                            s--;
                        }
                        nF4c++;
                    } else if (k4 < 0x40) {
                        r->field_2 = k4 & 0xF;
                        s--;
                    } else {
                        k4 &= 0xF;
                        if (r->field_2F == nF4d) {
                            if (k4 != 7) {
                                Snd_PlayById(D_8004142C[k4], 0);
                            }
                            r->field_2F++;
                            if (k4 == 4) {
                                func_80063C84();
                            }
                        }
                        s--;
                        nF4d++;
                    }
                    break;
                case 0xF3:
                    stop = 1;
                    s++;
                    switch (a0->field_14) {
                    case 0:
                    default:
                        Gfx_FadeOutToBlack(0xA);
                        Task_NextState1(a0);
                        break;
                    case 1:
                        break;
                    }
                    if (++a0->field_18 >= 0x19) {
                        if (*s == 0xFC) {
                            ((Gl1A9C8 *)&D_8005F770)->field_1C = 0x605;
                        } else if (*s == 0xFD) {
                            ((Gl1A9C8 *)&D_8005F770)->field_1C = 0x500;
                        } else if (*s == 0xFE) {
                            ((Gl1A9C8 *)&D_8005F770)->field_1C = 0x404;
                        } else if (*s == 0xFF) {
                            ((Gl1A9C8 *)&D_8005F770)->field_1C = 0x405;
                        } else {
                            ((Gl1A9C8 *)&D_8005F770)->field_1C = *s + 0x300;
                        }
                        s++;
                        ((Gl1A9C8 *)&D_8005F770)->field_24 = *s;
                    }
                    break;
                case 0xF2:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        line--;
                        Text_PushReturn((s32)(s + 1));
                        s = (u8 *)Item_GetNameText(n) - 1;
                    }
                    break;
                case 0xF1:
                    {
                        s32 n;
                        s++;
                        n = *s++ * 100;
                        n += *s++ * 10;
                        n += *s;
                        line--;
                        Text_PushReturn((s32)(s + 1));
                        s = Digi_GetDefaultName(n) - 1;
                    }
                    break;
                case 0xF0:
                    s++;
                    k = *s;
                    Text_PushReturn((s32)(s + 1));
                    switch (k) {
                    case 0:
                        s = &D_8005E633;
                        break;
                    case 5:
                        s = &D_8005E6F0;
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        {
                            s32 jj = k - 1;
                            s = (u8 *)(&r->field_C)[jj] - 1;
                        }
                        break;
                    default:
                        s = (u8 *)D_80041440[k - 6] - 1;
                        break;
                    }
                    line--;
                    break;
                case 0xEF:
                    do {
                        s++;
                        c = *s + 0xF0;
                        goto draw;
                    } while (0);
                default:
                    c = *s;
                draw:
                    if (r->field_1 != 0) {
                        if ((s16)c >= 0x88) {
                            c -= 0x88;
                            page = 1;
                        } else {
                            page = 0;
                        }
                    }
                    pkt->c = *(Col1A9C8 *)&D_8005074C;
                    pkt->tag.b.len = 9;
                    pkt->c.code = 0x2C;
                    pkt->x0 = pkt->x2 = pos.field_0;
                    pkt->x1 = pkt->x3 = pkt->x0 + glyph.field_0;
                    pkt->y0 = pkt->y1 = pos.field_2;
                    pkt->y2 = pkt->y3 = pkt->y0 + glyph.field_2;
                    pkt->u0 = pkt->u2 = font[page]->field_C + ((s16)c % cols) * cell.field_0;
                    pkt->u1 = pkt->u3 = pkt->u0 + glyph.field_0;
                    pkt->v0 = pkt->v1 = ((s16)c / cols) * cell.field_2;
                    pkt->v2 = pkt->v3 = pkt->v0 + glyph.field_2;
                    pkt->clut = ((font[page]->field_1C + (r->field_2 + 0xF8)) << 6) | ((font[page]->field_18 >> 4) & 0x3F);
                    pkt->tpage = font[page]->field_10;
                    if (((Gl1A9C8 *)&D_8005F770)->field_110 == 0x140) {
                        pkt->x0 *= 2;
                        pkt->x1 *= 2;
                        pkt->x2 *= 2;
                        pkt->x3 *= 2;
                    }
                    if (((Gl1A9C8 *)&D_8005F770)->field_114 == 0xF0) {
                        pkt->y0 *= 2;
                        pkt->y1 *= 2;
                        pkt->y2 *= 2;
                        pkt->y3 *= 2;
                    }
                    pkt->tag.word = (pkt->tag.word & 0xFF000000) | (*ot & 0xFFFFFF);
                    *ot = (*ot & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
                    pkt++;
                    pos.field_0 += r->field_3;
                    if (grew == 0 && line + 1 >= r->field_22) {
                        grew = 1;
                        r->field_22++;
                    }
                    break;
                }
            next:
                s++;
                if (stop != 0) {
                    break;
                }
            } while (r->field_6 == 0 || ++line < r->field_22);
        }
    } while (++row < 0x32);
    D_8005F79C = (s32)pkt;
}


void Text_Close(s32 *slot) {
    Ent11440 *e;
    Actor *a;
    s32 i;
    Rec34 *r;
    Actor **q;

    if (*slot == -1) {
        return;
    }
    e = Task_FindFirst(9, -1, -1);
    if (e != 0) {
        i = *slot;
        r = &e->field_2C[i];
        q = &e->field_34[i];
        r->field_0 = 0;
        a = q[1];
        if (a != 0) {
            Task_SetState0(a, 3);
        }
        *slot = -1;
    }
}


void Text_Open(void *arg0, Arg1BC24 *arg1) {
    SrcBC24 *src = (SrcBC24 *)arg1;
    Ent11440 *r;
    Rec34 *base;
    Rec34 *p;
    Rec34 *rec;
    s32 i;

    r = Task_FindFirst(9, -1, -1);
    if (r == 0) {
        return;
    }
    i = 0;
    base = r->field_2C;
    Text_Close(arg0);

    for (p = base; i < 0x32; i++, p++) {
        if (p->field_0 == 0) {
            break;
        }
    }

    if (src->field_C == 0) {
        if (src->field_0 != 0) {
            src->field_C = 9;
        } else {
            src->field_C = 7;
        }
    }
    if (src->field_10 == 0) {
        if (src->field_0 != 0) {
            src->field_10 = 0xF;
        } else {
            src->field_10 = 0xA;
        }
    }

    rec = &base[i];
    rec->field_0 = 1;
    rec->field_1 = *(u8 *)&src->field_0;
    rec->field_2 = *(u8 *)&src->field_4;
    rec->field_8 = src->field_14;
    rec->field_1C = src->field_8 - 0xA0;
    rec->field_1E = src->field_A - 0x78;
    rec->field_3 = *(u8 *)&src->field_C;
    rec->field_4 = *(u8 *)&src->field_10;
    rec->field_6 = *(u16 *)&src->field_18;
    rec->field_C = src->field_1C;
    rec->field_10 = src->field_20;
    rec->field_14 = src->field_24;
    rec->field_18 = src->field_28;
    rec->field_20 = *(u8 *)&src->field_4;
    rec->field_21 = *(u8 *)&src->field_18;
    rec->field_22 = 0;
    rec->field_23 = 0;
    rec->field_24 = 0;
    rec->field_25 = 0;
    rec->field_27 = 0;
    rec->field_26 = 0;
    rec->field_28 = 0;
    rec->field_29 = 0;
    rec->field_2A = 0;
    rec->field_2B = 0;
    rec->field_2C = 0;
    rec->field_2D = 0;
    rec->field_2E = 0;
    rec->field_2F = 0;
    rec->field_30 = 0;
    rec->field_31 = 0;

    *(s32 *)arg0 = i;
}

s32 Text_IsFinished(s32 id) {
    Ent11440 *p;

    if (id == -1) {
        return 1;
    }
    p = Task_FindFirst(9, -1, -1);
    if (p == 0) {
        return 0;
    }
    return p->field_2C[id].field_23;
}

void Text_SetColor(s32 a0, s32 a1) {
    Ent11440 *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        Rec34 *r = &p->field_2C[a0];
        r->field_20 = a1;
        r->field_2 = a1;
    }
}

void Text_SetInputPad(s32 a0, s32 a1) {
    Ent11440 *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        p->field_2C[a0].field_30 = a1;
    }
}

void Text_SetOtLayer(s32 a0, s32 a1) {
    Ent11440 *p = Task_FindFirst(9, -1, -1);
    if (a0 != -1 && p != 0) {
        p->field_2C[a0].field_31 = a1;
    }
}

void Text_OpenById(void *a0, s32 a1, s32 a2, Halves a3) {
    Arg1BC24 local;
    local.field_14 = (s32)Cd_GetFileEntry(a1 + 0x1FD0000);
    local.field_0 = 0;
    local.field_4 = a2;
    local.field_8 = a3.lo;
    local.field_A = a3.hi;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_18 = 0;
    Text_Open(a0, &local);
}

void func_8001C038(void *arg0, s32 arg1) {
    Arg1BC24 local;
    local.field_0 = 1;
    local.field_4 = 0;
    local.field_8 = 0;
    local.field_A = 0;
    local.field_C = 0;
    local.field_10 = 0;
    local.field_14 = arg1;
    local.field_18 = 1;
    Text_Open(arg0, &local);
    Flag_Set(0x10, 0);
}

void Mem_FillWordsNeg1(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        *arg0++ = -1;
    }
}

void Text_CloseArray(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        Text_Close(arg0);
        arg0++;
    }
}

void Gpu_ClearScreens(void) {
    Rect2AB54 r;
    s32 i;

    for (i = 0; i < 2; i++) {
        r = ((View1C104 *)&D_8005F770)->area[i].rect;
        ResetGraph(1);
        ClearImage2((s32)&r, 0, 0, 0);
        DrawSync(0);
    }
}


void func_8001C194(s32 a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_8005F770.field_48[i].field_0 = 1;
        D_8005F770.field_48[i].field_1 = a0;
        D_8005F770.field_48[i].field_2 = a1;
        D_8005F770.field_48[i].field_3 = a2;
    }
}

void func_8001C1CC(void) {
    D_8005F770.field_48[0].field_0 = 0;
    D_8005F770.field_48[1].field_0 = 0;
}

void Gpu_InitDoubleBuffer(s32 w, s32 h, s32 mode, s32 inter) {
    Db5F770 *g = (Db5F770 *)&D_8005F770;
    s32 n = 0;
    s32 hw = w / 2;
    s32 hh = h / 2;

    g->field_110 = hw;
    g->field_114 = hh;
    switch (mode) {
    default:
    case 0:
        SetDefDrawEnv(&g->draw[0], 0, h, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, h, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = h + hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 1:
        SetDefDrawEnv(&g->draw[0], 0, 0, w, h);
        SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
        SetDefDispEnv(&g->disp[0], 0, 0, w, h);
        SetDefDispEnv(&g->disp[1], 0, 0, w, h);
        g->draw[0].ofs[0] = hw;
        g->draw[0].ofs[1] = hh;
        g->draw[1].ofs[0] = hw;
        g->draw[1].ofs[1] = hh;
        n = 0x40 - (w / 32) * 2;
        break;
    case 2:
        if (inter != 0) {
            SetDefDrawEnv(&g->draw[0], 480, 0, 320, 480);
            SetDefDrawEnv(&g->draw[1], 0, 0, 320, 480);
            SetDefDispEnv(&g->disp[0], 0, 0, 320, 480);
            g->disp[0].isrgb24 = 1;
            SetDefDispEnv(&g->disp[1], 480, 0, 320, 480);
            g->disp[1].isrgb24 = 1;
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
        } else {
            SetDefDrawEnv(&g->draw[0], w, 0, w, h);
            SetDefDrawEnv(&g->draw[1], 0, 0, w, h);
            SetDefDispEnv(&g->disp[0], 0, 0, w, h);
            SetDefDispEnv(&g->disp[1], w, 0, w, h);
            g->draw[0].dfe = 1;
            g->draw[1].dfe = 1;
            g->draw[0].ofs[0] = w + hw;
            g->draw[0].ofs[1] = hh;
            g->draw[1].ofs[0] = hw;
            g->draw[1].ofs[1] = hh;
            n = 0x40 - (w / 16) * 2;
        }
        break;
    }
    Gfx_SetTexSlotCount(n);
    func_8002B4C4();
    SetGeomOffset(0, 0);
}

void Gfx_FadeInFromBlack(s32 arg0) {
    Gfx_FadeState.field_8 = 0;
    Gfx_FadeState.field_0 = 2;
    Gfx_FadeState.field_4 = arg0;
    D_8005F780 = arg0 + 0xFF;
}

void Gfx_FadeOutToBlack(s32 arg0) {
    Gfx_FadeState.field_8 = 0;
    Gfx_FadeState.field_0 = 3;
    Gfx_FadeState.field_4 = arg0;
}

void Gfx_FadeInFromWhite(s32 arg0) {
    Gfx_FadeState.field_8 = 1;
    Gfx_FadeState.field_0 = 2;
    Gfx_FadeState.field_4 = arg0;
    D_8005F780 = arg0 + 0xFF;
}

void Gfx_FadeOutToWhite(s32 arg0) {
    Gfx_FadeState.field_8 = 1;
    Gfx_FadeState.field_0 = 3;
    Gfx_FadeState.field_4 = arg0;
}

void Gfx_FadeClear(void) {
    Gfx_FadeState.field_8 = 0;
    Gfx_FadeState.field_0 = 0;
}

void Gfx_FadeSetBlack(void) {
    Gfx_FadeState.field_8 = 0;
    Gfx_FadeState.field_0 = 1;
}

void Gfx_DrawFade(void) {
    Fade1C584 *p;
    Fade1C584Mode *q;
    Tag1CE9C *ot;
    s32 w;
    s32 h;
    u8 c;
    s32 abr;

    if (D_8005F770.work == 0) {
        return;
    }
    for (;;) {
        switch (Gfx_FadeState.field_0) {
        default:
        case 0:
            D_8005F770.field_10 = 0;
            return;
        case 1:
            D_8005F770.field_10 = 0xFF;
            goto check;
        case 2:
            D_8005F770.field_10 -= Gfx_FadeState.field_4;
            if (D_8005F770.field_10 > 0) {
                goto draw;
            }
            D_8005F770.field_10 = 0;
            Gfx_FadeState.field_0 = 0;
            continue;
        case 3:
            D_8005F770.field_10 += Gfx_FadeState.field_4;
            if (D_8005F770.field_10 < 0xFF) {
                goto check;
            }
            D_8005F770.field_10 = 0xFF;
            Gfx_FadeState.field_0 = 1;
            continue;
        }
    }
check:
    if (D_8005F780 == 0) {
        return;
    }
draw:
    abr = 2;
    q = (Fade1C584Mode *)D_8005F770.work;
    p = (Fade1C584 *)q;
    ot = (Tag1CE9C *)D_8005F770.field_138[0];
    p->t.len = 5;
    p->code = 0x2A;
    c = D_8005F770.field_10;
    p->g = c;
    p->b = c;
    p->r = c;
    w = D_8005F770.field_110;
    p->x0 = p->x2 = -w;
    p->x1 = p->x3 = w;
    h = D_8005F770.field_114;
    p->y0 = p->y1 = -h;
    p->y2 = p->y3 = h;
    p->t.addr = ot->addr;
    ot->addr = (u32)p;
    q = &p->m;
    if (Gfx_FadeState.field_8 != 0) {
        abr = 1;
    }
    q->t.len = 1;
    q->mode = (abr << 5) | 0xE1000400;
    p->m.t.addr = ot->addr;
    ot->addr = (u32)q;
    q = (Fade1C584Mode *)(p + 1);
    D_8005F770.work = (ActorWork *)q;
}

void Gpu_SetLayerOtPtrs(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_8005F770.field_118[i] = D_80041570[D_8005CCF8.field_60][i];
        D_8005F770.field_138[i] = &Gpu_OtBufs[D_8005F770.field_28].field_0[D_800415F0[D_8005CCF8.field_60][i]];
    }
}

void func_8001C800(s32 arg0) {
    Gpu_OtBufs[2].field_0[0] = arg0;
}

void Gpu_ClearOt(s32 arg0) {
    ClearOTagR(&Gpu_OtBufs[arg0], 0x100C);
}

s32 Gpu_DrawOt(s32 arg0) {
    s32 *p = (s32 *)&D_80058D28[arg0];
    return DrawOTag(&p[-1]);
}

void Gpu_SkipEmptyOtEntries(s32 arg0) {
    u32 *p = (u32 *)&D_80058D28[arg0];
    u32 *end = (u32 *)&D_80058D28[arg0 - 1];
    u32 *q;
    u32 m = 0xFFFFFF;

    p--;
    while (p != end) {
        q = p - 1;
        if ((*p & m) == ((u32)q & m)) {
            u32 v = *q;
            u32 w = (u32)(q - 1) & m;

            while ((v & m) == w) {
                q--;
                v = *q;
                w = (u32)(q - 1) & m;
            }
            *p = (u32)q & m;
        }
        p = q;
    }
}

s32 func_8001C92C(void) {
    return 0;
}

void Gpu_FreePrimBufs(void) {
    if (D_80041670[0] != 0) {
        Mem_Free(D_80041670[0]);
        D_80041670[0] = 0;
        Mem_Free(D_80041670[1]);
        D_80041670[1] = 0;
    }
    D_8005F79C = 0;
}

void Gpu_ResetPrimBuf(void) {
    D_8005F770.work = D_80041670[D_8005F770.field_28];
}

extern s32 Mem_Alloc(s32, s32);

void Gpu_AllocPacketBufs(s32 a0) {
    D_80041670[2] = (ActorWork *)a0;
    D_80041670[0] = (ActorWork *)Mem_Alloc(a0, 2);
    D_80041670[1] = (ActorWork *)Mem_Alloc(a0, 2);
    D_8005F770.work = D_80041670[D_8005F770.field_28];
}

Elem20 *Gfx_GetTexSlot(s32 arg0) {
    return &Gfx_TexSlots[arg0];
}

void Gfx_InitTexSlots(void) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        Gfx_TexSlots[i].field_18 = 0x3E0 - (i / 2) * 32;
        Gfx_TexSlots[i].field_14 = i;
        Gfx_TexSlots[i].field_1C = (i & 1) << 8;
        Gfx_TexSlots[i].field_0 = 0;
        Gfx_TexSlots[i].field_4 = 0;
        Gfx_TexSlots[i].field_8 = 0;
        Gfx_TexSlots[i].field_C = 0;
        Gfx_TexSlots[i].field_10 = 0;
    }
}

s32 func_8001CAA0() {
    return Cd_GetFileEntry()->field_4 & 7;
}

void Gfx_LoadTexSlotImage(Elem20 *a0) {
    u32 *p;
    u32 flags;
    Rect2AB54 clut;
    Rect2AB54 img;

    p = (u32 *)Cd_GetFileEntry(a0->field_0);
    p++;
    flags = *p++;
    if (flags & 8) {
        if (flags & 7) {
            clut.x = 0;
            clut.y = a0->field_14 + 0x1E0;
            clut.w = 0x100;
            clut.h = 1;
            LoadImage((s32)&clut, (s32)((TimBlk *)p + 1));
        }
        p = (u32 *)((u8 *)p + *p);
    }
    img.x = a0->field_18;
    img.y = a0->field_1C;
    img.w = ((TimBlk *)p)->rect.w;
    img.h = ((TimBlk *)p)->rect.h;
    LoadImage((s32)&img, (s32)((TimBlk *)p + 1));
}


Elem20 *Gfx_FindOrLoadTexSlot(s32 id) {
    Elem20 *e;
    Elem20 *p;
    s32 i;
    u32 best;
    s32 idx;
    s32 n;
    s32 tp;
    s32 t;

    p = Gfx_TexSlots;
    for (i = 0; i < 0x40; i++, p++) {
        if (p->field_0 == -1) {
            continue;
        }
        if (p->field_0 == -2) {
            continue;
        }
        if (p->field_0 == id) {
            p->field_4 = D_8005F770.field_0;
            return p;
        }
    }
    best = -1;
    idx = 0;
    if (func_8001CAA0(id)) {
        n = 0x20;
        tp = 1;
    } else {
        n = 0x40;
        tp = 0;
    }
    e = Gfx_TexSlots;
    for (i = 0; i < n; i++, e++) {
        if (e->field_0 == -1) {
            continue;
        }
        if (e->field_0 == -2) {
            continue;
        }
        if (e->field_0 == 0) {
            idx = i;
            break;
        }
        if (e->field_4 < best) {
            best = e->field_4;
            idx = i;
        }
    }
    e = &Gfx_TexSlots[idx];
    e->field_0 = id;
    e->field_4 = D_8005F770.field_0;
    e->field_8 = tp;
    t = e->field_14 & 2;
    e->field_C = t == 0;
    if (tp) {
        e->field_C <<= 6;
    } else {
        e->field_C <<= 7;
    }
    e->field_10 = (tp << 7) | ((e->field_1C & 0x100) >> 4) | ((e->field_18 & 0x3FF) >> 6) | ((e->field_1C & 0x200) << 2);
    Gfx_LoadTexSlotImage(e);
    return e;
}

void Gfx_SetTexSlotCount(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        Elem20 *p = Gfx_GetTexSlot(i);
        if (i >= arg0) {
            p->field_0 = -1;
        } else {
            if (p->field_0 == -1) p->field_0 = 0;
        }
    }
}

s32 Gfx_ReserveTexSlot(void) {
    u32 min = -1;
    s32 best = 0;
    s32 i;
    Elem20 *p = Gfx_TexSlots;

    for (i = 0; i < 24; i++, p++) {
        if (p->field_0 == -2) {
            continue;
        }
        if (p->field_0 == 0) {
            best = i;
            break;
        }
        if ((u32)p->field_4 < min) {
            min = p->field_4;
            best = i;
        }
    }
    p = &Gfx_TexSlots[best];
    p->field_0 = -2;
    p->field_4 = D_8005F770.field_0;
    p->field_8 = 0;
    p->field_C = ((p->field_14 & 2) == 0) << 7;
    p->field_10 = ((p->field_1C & 0x100) >> 4) | ((p->field_18 & 0x3FF) >> 6) | ((p->field_1C & 0x200) << 2);
    return (s32)p;
}

void Gfx_ReleaseTexSlot(s32 *arg0) {
    if (*arg0 == -2) {
        *arg0 = 0;
    }
}

void Gfx_DrawPartSprites(void *arg0, s32 arg1) {
    Obj1CE9C *s = arg0;
    Tag1CE9C *ot = (Tag1CE9C *)arg1;
    Ent1CE9C *e;
    Tex1CE9C *t;
    Pkt1CE9C *p;
    u16 tpage;
    s32 y;

    e = (Ent1CE9C *)Cd_GetFileEntry(s->field_0);
    t = (Tex1CE9C *)Gfx_FindOrLoadTexSlot(s->field_0 & 0xFFFF0000);
    p = (Pkt1CE9C *)D_8005F79C;
    for (; e->field_0 != 0xFF; e++) {
        if (e->field_C != s->field_D) {
            continue;
        }
        p->s.c = s->field_8;
        p->s.tag.len = 4;
        p->s.c.code = 0x64;
        if (e->field_B & 0x80) {
            p->s.c.code = 0x66;
            tpage = t->field_10 + ((e->field_B & 3) << 5);
        } else {
            tpage = t->field_10;
        }
        p->s.x0 = e->field_2 + s->field_4;
        p->s.u0 = e->field_0 + t->field_C;
        p->s.w = e->field_8;
        p->s.y0 = e->field_4 + s->field_6;
        p->s.v0 = e->field_1;
        p->s.h = e->field_9;
        if (p->s.h == 0) {
            p->s.h--;
        }
        if (t->field_8 != 0) {
            y = t->field_14 + 0x1E0;
            p->s.clut = (e->field_A + y + s->field_C) << 6;
        } else {
            p->s.clut = ((e->field_7 + t->field_1C + e->field_A + s->field_C) << 6) |
                       (((e->field_6 + t->field_18) >> 4) & 0x3F);
        }
        p->s.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (Pkt1CE9C *)(&p->s + 1);
        p->t.tag.len = 1;
        p->t.code = 0xE1000600 | (tpage & 0x9FF);
        p->t.tag.addr = ot->addr;
        ot->addr = (u32)p;
        p = (Pkt1CE9C *)(&p->t + 1);
    }
    D_8005F79C = (s32)p;
}


void Gfx_DrawPartQuadsRot(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    Ent1CE9C *e;
    Tex1CE9C *t;
    Poly1D104 *p;
    DVec1D104 out;
    SVec1D104 sv[4];
    s32 i;
    s32 u;
    s32 y;

    e = (Ent1CE9C *)Cd_GetFileEntry(((Obj1CE9C *)arg0)->field_0);
    t = (Tex1CE9C *)Gfx_FindOrLoadTexSlot(((Obj1CE9C *)arg0)->field_0 & 0xFFFF0000);
    p = (Poly1D104 *)D_8005F79C;
    for (; e->field_0 != 0xFF; e++) {
        if (e->field_C != ((Obj1CE9C *)arg0)->field_D) {
            continue;
        }
        p->c = ((Obj1CE9C *)arg0)->field_8;
        p->tag.len = 9;
        p->c.code = 0x2C;
        if (e->field_B & 0x80) {
            p->c.code = 0x2E;
            p->v[1].extra = t->field_10 | ((e->field_B & 3) << 5);
        } else {
            p->v[1].extra = t->field_10;
        }
        sv[0].vx = sv[2].vx = e->field_2;
        sv[1].vx = sv[3].vx = e->field_2 + e->field_8;
        sv[0].vy = sv[1].vy = e->field_4;
        if (e->field_9) sv[2].vy = sv[3].vy = e->field_4 + e->field_9; else sv[2].vy = sv[3].vy = e->field_4 + 0xFF;
        sv[0].vz = sv[1].vz = sv[2].vz = sv[3].vz = 0;
        for (i = 0; i < 4; i++) {
            ApplyMatrixSV(arg1, &sv[i], &out);
            p->v[i].x = out.vx + ((Obj1CE9C *)arg0)->field_4;
            p->v[i].y = out.vy + ((Obj1CE9C *)arg0)->field_6;
        }
        u = e->field_0 + t->field_C;
        p->v[0].u = p->v[2].u = u;
        u += e->field_8;
        p->v[1].u = p->v[3].u = u;
        if (((Obj1CE9C *)arg0)->field_10 < 0) {
            p->v[1].u = p->v[3].u = u - 1;
        }
        if (p->v[1].u == 0) {
            p->v[1].u = p->v[3].u = 0xFF;
        }
        p->v[0].v = p->v[1].v = e->field_1;
        u = e->field_1 + e->field_9;
        p->v[2].v = p->v[3].v = u;
        if (((Obj1CE9C *)arg0)->field_14 < 0) {
            p->v[2].v = p->v[3].v = u - 1;
        }
        if (p->v[2].v == 0) {
            p->v[2].v = p->v[3].v = 0xFF;
        }
        if (t->field_8 != 0) {
            y = t->field_14 + 0x1E0;
            p->v[0].extra = (e->field_A + y + ((Obj1CE9C *)arg0)->field_C) << 6;
        } else {
            p->v[0].extra = ((e->field_7 + t->field_1C + e->field_A + ((Obj1CE9C *)arg0)->field_C) << 6) |
                            (((e->field_6 + t->field_18) >> 4) & 0x3F);
        }
        if (arg3 & 1) {
            p->v[0].x *= 2;
            p->v[1].x *= 2;
            p->v[2].x *= 2;
            p->v[3].x *= 2;
        }
        if (arg3 & 2) {
            p->v[0].y *= 2;
            p->v[1].y *= 2;
            p->v[2].y *= 2;
            p->v[3].y *= 2;
        }
        p->tag.addr = ((Tag1CE9C *)arg2)->addr;
        ((Tag1CE9C *)arg2)->addr = (u32)p;
        p++;
    }
    D_8005F79C = (s32)p;
}


void Gfx_HidePartsByMask(Obj1D504 *p, s32 mask) {
    if (p->field_0 != 0) {
        do {
            if (p->field_1C & mask) {
                p->field_F = 0;
            } else {
                p->field_F = 1;
            }
            p++;
        } while (p->field_0 != 0);
    }
}

void Gfx_SetPartsScale(Ent1D550 *p, s32 a1, s32 a2) {
    if (p->field_0 == 0) {
        return;
    }
    do {
        if (a1 != 0x1000) {
            p->field_E = 0;
        } else {
            p->field_E = 1;
        }
        p->field_10 = a1;
        if (a2 != 0x1000) {
            p->field_E = 0;
        } else {
            p->field_E = 1;
        }
        p->field_14 = a2;
        p++;
    } while (p->field_0 != 0);
}

void Gfx_SetPartsNumber(Part28 *p, s32 mask, s32 n, s32 val) {
    u8 d[8];
    Part28 *q;
    s32 i = 0;
    s32 lead = 0;
    s32 k;
    s32 x;

    if (n < 0) {
        lead = 1;
        n = -n;
    }
    x = val;
    for (k = n - 1; k != -1; k--) {
        d[k] = x % 10;
        x /= 10;
    }
    if (p->field_0 != 0) {
        q = p;
        do {
            if (q->field_1C & mask) {
                if (lead == 1 || i == n - 1 || d[i] != 0) {
                    lead = 1;
                    q->field_D = d[i];
                } else {
                    q->field_D = 0xFF;
                }
                i++;
            }
            p++;
            q++;
        } while (p->field_0 != 0);
    }
}

/* File-local record walked by func_8001D6B4 (stride 0x28). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0xB - 4];
    /* 0x0B */ u8 field_B;
    u8 _pad0C[0xE - 0xC];
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x20 - 0x18];
    /* 0x20 */ s16 field_20;
    /* 0x22 */ s16 field_22;
    /* 0x24 */ s16 field_24;
    /* 0x26 */ s16 field_26;
} Rec1D6B4; /* 0x28 */

/* View of D_8005F770 (=Actor) fields func_8001D6B4 reads. */
typedef struct {
    u8 _pad00[0x110];
    /* 0x110 */ s32 field_110;
    /* 0x114 */ s32 field_114;
    u8 _pad118[0x138 - 0x118];
    /* 0x138 */ s32 field_138[1];
} Wk1D6B4;

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    u8 _pad06[2];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    u8 _pad10[0x18 - 0x10];
    /* 0x18 */ s32 field_18;
} G4167C;

/* 2-byte-aligned aggregate forcing the lwl/lwr + swl/swr block copy. */
typedef struct {
    s16 h[4];
} Agg1D6B4;

extern G4167C D_8004167C;
extern u8 D_80041694;
extern void Gfx_DrawPartSprites(void *, s32);
extern void Gfx_DrawPartQuadsRot(void *, void *, s32, s32);
extern void ScaleMatrix(Obj209 *, s32 *);

void func_8001D6B4(void *arg0, s32 arg1) {
    Rec1D6B4 *s2 = (Rec1D6B4 *)arg0;
    s32 s3 = 0;
    s32 s4;

    if (arg1 != 0) {
        s32 f114 = ((Wk1D6B4 *)&D_8005F770)->field_114;
        s3 = 0;
        s3 = (((Wk1D6B4 *)&D_8005F770)->field_110 ^ 0x140) == s3;
        if (f114 == 0xF0) {
            s3 |= 2;
        }
    }
    if (s2->field_0 == 0) {
        return;
    }
    do {
        s4 = ((Wk1D6B4 *)&D_8005F770)->field_138[s2->field_B];
        if (s2->field_F != 0) {
            if (s2->field_E != 0) {
                if (s3 != 0) {
                    s2->field_24 = 0;
                    s2->field_22 = 0;
                    s2->field_20 = 0;
                    s2->field_10 = 0x1000;
                    s2->field_14 = 0x1000;
                } else {
                    Gfx_DrawPartSprites(s2, s4);
                    goto Ladv;
                }
            }
            if (D_8004167C.field_0 == *(s32 *)&s2->field_20 &&
                D_8004167C.field_4 == s2->field_24 &&
                D_8004167C.field_8 == s2->field_10 &&
                D_8004167C.field_C == s2->field_14) {
            } else {
                *(Agg1D6B4 *)&D_8004167C = *(Agg1D6B4 *)&s2->field_20;
                D_8004167C.field_8 = s2->field_10;
                D_8004167C.field_C = s2->field_14;
                func_8002D744(&D_8004167C, (Obj209 *)&D_8004167C.field_18);
                ScaleMatrix((Obj209 *)&D_8004167C.field_18, &D_8004167C.field_8);
            }
            Gfx_DrawPartQuadsRot(s2, &D_80041694, s4, s3);
        }
    Ladv:
        s2 = (Rec1D6B4 *)((u8 *)s2 + 0x28);
    } while (s2->field_0 != 0);
}

void Gfx_DrawParts(s32 arg0) {
    func_8001D6B4(arg0, 1);
}

void func_8001D8A4(s32 arg0) {
    func_8001D6B4(arg0, 0);
}

EntD8C4 *func_8001D8C4(id) s32 id; {
    EntD8C4 *p = (EntD8C4 *)Cd_GetFileOrNull(0xC6C);
    s16 v;

loop:
    v = p->field_0;
    if (v == 0) {
        goto fail;
    }
    if (v == id) {
        return p;
    }
    p++;
    goto loop;
fail:
    return 0;
}

u8 func_8001D910(void) {
    return func_8001D8C4()->field_3;
}

u8 func_8001D934(void) {
    return func_8001D8C4()->u4.field_4 & 0xF;
}

s32 func_8001D958(void) {
    return (func_8001D8C4()->u4.field_4h >> 4) & 0xF;
}

s32 func_8001D980(void) {
    return (func_8001D8C4()->u4.field_4h >> 8) & 0xF;
}

u8 func_8001D9A8(void) {
    return func_8001D8C4()->field_2;
}

s32 func_8001D9CC(s32 id, s32 k) {
    switch (k) {
    default:
    case 0:
        return func_8001D8C4(id)->u4.field_4h >> 12;
    case 1:
        return func_8001D8C4(id)->u6.field_6 & 0xF;
    case 2:
        return (func_8001D8C4(id)->u6.field_6h >> 4) & 0xF;
    case 3:
        return (func_8001D8C4(id)->u6.field_6h >> 8) & 0xF;
    case 4:
        return func_8001D8C4(id)->u6.field_6h >> 12;
    }
}


u8 func_8001DA80(s32 id, s32 val) {
    EntD8C4 *e = func_8001D8C4(id);
    s32 i;

    if (e->field_D[0] == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (e->field_8[i + 1] == 0) {
            break;
        }
        if (val >= e->field_8[i] && val < e->field_8[i + 1]) {
            break;
        }
    }
    return e->field_D[i];
}

Ent1DB18 *func_8001DB18(s32 id) {
    Rec1DB18 *p = (Rec1DB18 *)Cd_GetFileOrNull(0xC6F);

    while (1) {
        if (p->field_0 == 0) {
            break;
        }
        if (p->field_0 == id) {
            return (Ent1DB18 *)p;
        }
        p++;
    }
    return 0;
}

void func_8001DB68(void *a0, Out1DB68 *out) {
    Ent1DB18 *src = func_8001DB18(a0);
    Ent1DB18 *p;
    s32 i;
    out->field_0 = src->u0.h.field_2;
    out->field_4 = ((s32)src->u0.field_0 << 20) >> 28;
    out->field_8 = ((s32)src->u0.field_0 << 16) >> 28;
    out->field_C = src->u4.field_4b;
    out->field_10 = (src->u4.field_4 >> 8) & 0xF;
    out->field_14 = (src->u4.field_4 >> 12) & 0xF;
    p = src;
    out->field_18 = p->u4.h.field_6;
    {
        Row1DB18 *row = (Row1DB18 *)p;
        for (i = 0; i < 3; i++) {
            out->field_1C[i] = row[i].field_8;
            out->field_22[i] = row[i].field_12;
        }
    }
}

void Digi_InitFromTable(s32 a0, s32 a1, ElmE620 *e) {
    Row1DB18 *r = (Row1DB18 *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    Mem_Zero(e, 0x5C);
    e->field_0 = 2;
    e->field_1 = r[a1].field_8;
    e->field_16 = e->field_14 = r[a1].field_A;
    e->field_1A = e->field_18 = r[a1].field_C;
    name = Digi_GetDefaultName(e->field_1);
    for (i = 0; i < 14; i++) {
        e->field_4C[i] = name[i];
    }
    e->field_D = r[a1].field_12;
    e->field_1C = r[a1].field_13;
    e->field_1E = r[a1].field_14;
    e->field_20 = r[a1].field_16;
    e->field_22 = r[a1].field_17;
    e->field_23 = r[a1].field_18;
    e->field_24 = r[a1].field_19;
    e->field_F = func_8001EB58(e->field_D);
    if (e->field_D == 1) {
        e->field_10 = 0;
    } else {
        e->field_10 = Digi_GetExpToNextLevel(e->field_D - 1, 100, 0);
    }
}

void func_8001DDA8(s32 a0, s32 a1, ElmE620 *e, Out1DDA8 *o) {
    Tbl1DDA8 *t = (Tbl1DDA8 *)func_8001DB18(a0);
    u8 *name;
    s32 i;

    if ((D_8005F788[0] & 0xFF00) == 0x500) {
        if (a1 == 0) {
            a1 = 1;
        } else if (a1 == 1) {
            a1 = 0;
        }
    }
    e->field_0 = a1 + 3;
    e->field_1 = t->rows[a1].field_0;
    e->field_16 = e->field_14 = t->rows[a1].field_2;
    e->field_1A = e->field_18 = t->rows[a1].field_4;
    if (e->field_1 != 0) {
        name = Digi_GetDefaultName(e->field_1);
        for (i = 0; i < 14; i++) {
            e->field_4C[i] = name[i];
        }
        e->field_D = t->rows[a1].field_A;
        e->field_10 = t->rows[a1].field_6;
        e->field_1C = t->rows[a1].field_B;
        e->field_1E = t->rows[a1].field_C;
        e->field_20 = t->rows[a1].field_E;
        e->field_22 = t->rows[a1].field_F;
        e->field_23 = t->rows[a1].field_10;
        e->field_24 = t->rows[a1].field_11;
        for (i = 3; i < 12; i++) {
            e->field_25[i - 3] = 0;
        }
        o->field_2 = t->rows[a1].field_F;
        o->field_3 = t->rows[a1].field_10;
        o->field_4 = t->rows[a1].field_11;
        o->field_9[0] = t->rows[a1].field_12[0][1];
        o->field_9[1] = t->rows[a1].field_12[1][1];
        o->field_9[2] = t->rows[a1].field_12[2][1];
        o->field_9[3] = t->rows[a1].field_12[3][1];
        o->field_0 = t->rows[a1].field_8;
        o->field_D[0] = t->rows[a1].field_12[0][2];
        o->field_D[1] = t->rows[a1].field_12[1][2];
        o->field_D[2] = t->rows[a1].field_12[2][2];
        o->field_D[3] = t->rows[a1].field_12[3][2];
        o->field_5[0] = t->rows[a1].field_12[0][0];
        o->field_5[1] = t->rows[a1].field_12[1][0];
        o->field_5[2] = t->rows[a1].field_12[2][0];
        o->field_5[3] = t->rows[a1].field_12[3][0];
    }
}


EntDFF4 *Item_FindById(arg0)
s32 arg0;
{
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    while (*p != 0) {
        if (*p == arg0) {
            return (EntDFF4 *)p;
        }
        p = (s16 *)((u8 *)p + 0x10);
    }
    return 0;
}

s32 Item_GetNameText(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->field_8 + base;
}

s32 func_8001E084(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x45E);
    return Item_FindById(arg0)->field_C + base;
}

s32 func_8001E0C0(s32 id) {
    return Item_FindById(id)->u0.b0.field_2;
}

s32 func_8001E0E4(void) {
    return Item_FindById()->u0.b0.field_3 & 0xF;
}

s32 Item_CheckId(void) {
    return Item_FindById() != 0 ? 0 : -1;
}

s32 func_8001E134(void) {
    return Item_FindById()->u0.field_0 >> 30;
}

s32 func_8001E158(void) {
    return (Item_FindById()->u0.field_0 >> 28) & 3;
}

s32 func_8001E180(void) {
    return Item_FindById()->u4.field_4 & 0xFFFFFF;
}

u8 func_8001E1AC(void) {
    return Item_FindById()->u4.b4.field_7;
}

s32 Item_GetTableIndex(s32 id) {
    EntDFF4 *p = (EntDFF4 *)Cd_GetFileEntry(0x45E0000);
    s32 i = 0;

    while (p->u0.field_0h != 0) {
        if (p->u0.field_0h == id) {
            return i;
        }
        p++;
        i++;
    }
    return 0;
}

s32 Item_GetIdAtIndex(s32 a0) {
    s16 *p = (s16 *)Cd_GetFileEntry(0x45E0000);
    s32 i;
    s32 r;
    for (i = 0; i < a0; i++) {
        if (*p == 0) break;
        p = (s16 *)((u8 *)p + 0x10);
    }
    r = 0;
    if (i == a0) {
        r = *p;
    }
    return r;
}

void func_8001E28C(s32 arg0) {
    D_8005D560.field_0 = arg0;
}

Blk18 *func_8001E298(ArgE298 *arg0) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.field_0 << 16) | 2);
    return &base[arg0->field_5];
}

Blk18 *func_8001E2E0(ArgE298 *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.field_0 << 16) | 2);
    return &base[((ArgE298 *)((u8 *)arg0 + arg1))->field_6];
}

Blk18 *func_8001E338(ArgE298 *arg0, s32 arg1) {
    Blk18 *base = (Blk18 *)Cd_GetFileEntry((D_8005D560.field_0 << 16) | 2);
    return &base[((ArgE298 *)((u8 *)arg0 + arg1))->field_C];
}

s32 func_8001E390(void) {
    while (D_8005D560.field_C->field_0 != 0) {
        if (Flag_TestConds(func_8001E298((ArgE298 *)D_8005D560.field_C)) != 0) {
            D_8005D560.field_10 = *D_8005D560.field_C;
            {
                s32 r = D_8005D560.field_8;

                D_8005D560.field_C++;
                D_8005D560.field_8 = r + 1;
                return r;
            }
        }
        D_8005D560.field_C++;
        D_8005D560.field_8++;
    }
    return -1;
}

void func_8001E480(void) {
    D_8005D560.field_4 = Cd_GetFileOrNull(D_8005D560.field_0);
    D_8005D560.field_C = Cd_GetFileEntry(D_8005D560.field_0 << 16);
    D_8005D560.field_8 = 0;
    func_8001E390();
}

EntE4CC *func_8001E4CC(arg0)
s32 arg0;
{
    EntE4CC *base = (EntE4CC *)Cd_GetFileEntry(D_8005D560.field_0 << 16);
    return &base[arg0];
}

extern s32 Flag_TestConds();
extern void Flag_ApplySets();

s32 func_8001E514(s32 arg0) {
    EntE4CC *base;
    s32 r;
    s32 i;
    r = Cd_GetFileOrNull(D_8005D560.field_0);
    base = func_8001E4CC(arg0);
    for (i = 0; i < 6; i++) {
        if (Flag_TestConds(func_8001E2E0((ArgE298 *)base, i)) != 0) {
            break;
        }
    }
    if (i == 6) {
        i = 0;
    }
    Flag_ApplySets(func_8001E338((ArgE298 *)base, i));
    return base->field_14[i] + r;
}

s32 func_8001E5C0(void) {
    return Cd_GetFileOrNull(D_8005D560.field_0);
}

Blk12 *func_8001E5E8(void) {
    EntE4CC *e = func_8001E4CC();
    Blk12 *base = (Blk12 *)Cd_GetFileEntry((D_8005D560.field_0 << 16) | 1);
    return &base[e->field_4];
}

s16 func_8001E634(void) {
    return func_8001E4CC()->field_0;
}

s16 func_8001E658(void) {
    return func_8001E4CC()->field_2;
}

s32 func_8001E67C(s32 arg0) {
    if (arg0 < 0x12C) {
        return 0xCB9;
    }
    if ((u32)(arg0 - 0x190) < 0x65) {
        return 0xCBB;
    }
    return 0xCBA;
}

EntE6A8 *Digi_FindDataById(s32 id) {
    EntE6A8 *e = (EntE6A8 *)Cd_GetFileEntry(func_8001E67C(id) << 16);
    s32 k;

    while (1) {
        k = (e->u4.field_4 >> 1) & 0x7FFF;
        if (k == 0) {
            break;
        }
        if (k == id) {
            return e;
        }
        e++;
    }
    return 0;
}

s32 func_8001E704(s32 id) {
    return Digi_FindDataById(id)->u4.h4.field_6;
}

s32 Anim_GetModelAnimFile(s32 arg0, s32 arg1) {
    return Digi_FindDataById(arg0)->field8[arg1];
}

u8 *Digi_GetDefaultName(s32 id) {
    s32 v;

    v = Digi_FindDataById(id)->field_0;
    v += Cd_GetFileOrNull(func_8001E67C(id));
    return (u8 *)v;
}

s16 func_8001E79C(s32 id) {
    return Digi_FindDataById(id)->field_1E;
}

s16 func_8001E7C0(s32 id) {
    return Digi_FindDataById(id)->field_20;
}

void func_8001E7E4(s32 a0, void *a1) {
    u8 *base;
    EntE6A8 *e;
    base = (u8 *)Cd_GetFileEntry((func_8001E67C(a0) << 16) | 1);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 0) = *(Row6 *)(base + e->field_22 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 6) = *(Row6 *)(base + e->field_24 * 6);
    e = Digi_FindDataById(a0);
    *(Row6 *)((u8 *)a1 + 12) = *(Row6 *)(base + e->field_26 * 6);
}

s32 func_8001E8D0(s32 id) {
    return Digi_FindDataById(id)->u4.field_4 & 1;
}

u16 func_8001E8F4(s32 idx) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000) + idx;
    return (p->field_4 >> 1) & 0x7FFF;
}

s32 func_8001E938(void) {
    EntA0 *p = Cd_GetFileEntry(0x1F80000);
    s32 i = 0;
    while ((p->field_4 >> 1) & 0x7FFF) {
        p++;
        i++;
    }
    return i;
}

s32 Digi_GetExpToNextLevel(s32 lv, s32 max, s32 cur) {
    s32 x;
    s32 sq;
    s32 exp;

    if (lv >= max) {
        return 99999999;
    }
    if (lv >= 62) {
        x = lv - 61;
        exp = 826540 + x * 65535;
    } else if (lv >= 31) {
        x = lv - 30;
        sq = x * x;
        exp = (sq * x * 5 + sq * 15 + x * 1145) * 4 + 31080;
    } else if (lv >= 21) {
        x = lv - 20;
        sq = x * x;
        exp = (sq * x * 5 + sq * 15) * 2 + x * 1220 + 5880;
    } else if (lv >= 11) {
        x = lv - 10;
        sq = x * x;
        exp = sq * x * 10 / 3 + sq * 10 + x * 107 + 480;
    } else {
        x = lv;
        sq = x * x;
        exp = sq * x / 3 + sq + x * 5;
    }
    if (exp < cur) {
        return 0;
    }
    return exp - cur;
}

s32 func_8001EB58(s32 x) {
    s32 h = x / 2;

    if (x < 6) {
        return x / 3 + 13;
    }
    if (x < 18) {
        return h + 14;
    }
    if (x < 28) {
        return h + 17;
    }
    {
        s32 r = (u16)((u16)Rand_Next() % 3) + 2;
        return x + r;
    }
}

void func_8001EC00(Actor *arg0, s32 *arg1) {
    arg0->work->field_0 = *arg1;
}

void func_8001EC10(Actor *arg0) {
    s32 state = arg0->field_10;

    switch (state) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, D_80043704, 0);
        Gfx_AttachModel(arg0, 0x5B)->field_3C = 4;
        Gfx_ResetModelBones(arg0);
        Task_NextState0(arg0);
        break;
    case 1: {
        ActorWork *w = arg0->work;
        Actor *v1 = (Actor *)w->field_0;
        w->field_4 = 0;
        if (v1 != 0) {
            s32 st = v1->field_10;
            if (st != 0 && st != 3) {
                DstElem *de = v1->field_3C->field_78;
                ObjEC10 *dst = arg0->u38.ptr38;
                s32 t = de->field_34;
                dst->field_34 = 0;
                dst->field_30 = t;
                dst->field_38 = de->field_3C;
                w->field_4 = state;
            }
        }
        break;
    }
    case 2:
        break;
    }
}

void func_8001ECE4(Actor *arg0) {
    if (arg0->work->field_4 != 0) {
        Gfx_AttachModel(arg0, 0x5B);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 1);
    }
}

EntED40 *func_8001ED40(s32 id) {
    EntED40 *p = (EntED40 *)Cd_GetFileEntry(0x25B0000);

    do {
        if (p->u0.id == id) {
            return p;
        }
    } while ((p++)->u0.id != 0);
    return 0;
}

s32 func_8001ED84(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    EntED40 *p = func_8001ED40(arg0);
    if (p != 0) {
        return p->field_24 + base;
    }
    return 0;
}

s32 func_8001EDD4(s32 arg0) {
    s32 base = Cd_GetFileOrNull(0x25B);
    return func_8001ED40(arg0)->field_28 + base;
}

s32 func_8001EE10(s32 id) {
    return func_8001ED40(id)->u0.h0.field_2 & 3;
}

s32 func_8001EE34(s32 id) {
    return (func_8001ED40(id)->u0.field_0 >> 18) & 3;
}

s32 func_8001EE5C(s32 id) {
    return func_8001ED40(id)->field_C;
}

u8 func_8001EE80(s32 id) {
    return func_8001ED40(id)->field_4;
}

void func_8001EEA4(s32 id, s32 n, s16 *a, s16 *b) {
    EntED40 *p = func_8001ED40(id);
    s32 i;

    n *= 2;
    for (i = 0; i < 3; i++) {
        *a++ = p->field_2C[n][i];
        *b++ = p->field_2C[n + 1][i];
    }
}


s32 func_8001EF3C(s32 id) {
    return (func_8001ED40(id)->u0.field_0 >> 20) & 0xF;
}

s16 func_8001EF64(s32 id) {
    return func_8001ED40(id)->field_8;
}

u16 func_8001EF88(s32 id) {
    u16 v = func_8001ED40(id)->u0.b0.field_3 & 0xF;

    if (v == 6) {
        return (u16)Rand_Next() % 5;
    }
    return v;
}

s32 *func_8001EFF0(s32 id) {
    EntED40 *e = func_8001ED40(id);
    D_80050778 = e->field_6;
    D_8005077C = e->field_5;
    return &D_80050778;
}


u8 func_8001F020(s32 id) {
    return func_8001ED40(id)->u10.field_10b;
}

s32 func_8001F044(s32 id) {
    return func_8001ED40(id)->field_20 & 0xF;
}

s32 func_8001F068(s32 id) {
    return func_8001ED40(id)->field_18 & 0x3FFFFFF;
}

s32 func_8001F094(s32 id) {
    return func_8001ED40(id)->field_1C & 0x3FFFF;
}

s32 func_8001F0C0(s32 id) {
    return func_8001ED40(id)->u0.field_0 >> 28;
}

s32 func_8001F0E4(s32 id) {
    return (func_8001ED40(id)->u10.field_10 >> 8) & 0x7FFF;
}

s32 func_8001F10C(s32 id) {
    return func_8001ED40(id)->field_14 & 0x3FF;
}

s32 func_8001F130(s32 id) {
    return (func_8001ED40(id)->field_14 >> 10) & 0x1FFF;
}

s32 func_8001F158(s32 id) {
    return (func_8001ED40(id)->field_1C >> 18) & 0x1F;
}

s32 func_8001F180(s32 id) {
    return (func_8001ED40(id)->field_1C >> 23) & 0xFF;
}

void Anim_SetModelAnim(Actor *a, s32 n) {
    Sub3C *s = a->field_3C;
    s32 i;
    s32 k;

    s->field_54 = n;
    s->field_58 = 0;
    s->field_50 = 0;
    for (i = 10; i < 0x6F; i += 10) {
        if (n < i) {
            s->field_48 = Anim_GetModelAnimFile(a->field_C, i / 10 - 1);
            k = i - 10;
            s->field_4C = n - k;
            break;
        }
    }
    s->field_5C = 1;
    s->field_60 = 0;
}

void Anim_SetModelAnimFile(Actor *arg0, s32 arg1, s32 arg2) {
    Sub3C *p = arg0->field_3C;
    p->field_54 = arg1;
    p->field_58 = 0;
    p->field_50 = 0;
    p->field_48 = arg2;
    p->field_4C = 0;
    p->field_5C = 1;
    p->field_60 = 0;
}

s32 Anim_HasModelAnim(Actor *a0, s32 n) {
    Sub3C *sub = a0->field_3C;
    s32 id;
    s32 k;
    s32 *p;

    if (n < 10) {
        k = 0;
        n = k;
        id = Anim_GetModelAnimFile(a0->field_C, k);
    } else if (n < 20) {
        id = Anim_GetModelAnimFile(a0->field_C, 1);
        n -= 10;
    } else {
        id = Anim_GetModelAnimFile(a0->field_C, 2);
        n -= 20;
    }
    p = (s32 *)(Cd_GetFileOrNull(id) + ((sub->field_8 + 1) << 2));
    sub->field_64 = p;
    return p[n] != 0;
}

void Anim_StepModelAnim(Actor *a) {
    Sub3C *s = a->field_3C;
    s32 *data = (s32 *)Cd_GetFileOrNull(s->field_48);
    s32 i;
    s32 j;
    s32 k;
    DstElem *e;
    u8 *f;
    u8 *q;
    s32 pos;
    Rec18 *r;

    if (data != s->field_50) {
        s->field_50 = data;
        s->field_68 = data + 1;
        i = s->field_8 + 1;
        s->field_64 = &data[i];
    }
    if (data[0] == 0) {
        data[0] = 1;
        for (k = 0; s->field_64[k] != 1; k++) {
            if (s->field_64[k] != 0) {
                s->field_64[k] += (s32)data;
            }
        }
        for (k = 0; k < s->field_8; k++) {
            s->field_68[k] += (s32)data;
        }
    }
    s->field_5C += D_8005F770.field_8;
    while (s->field_5C >= 2) {
        s->field_5C -= 2;
        e = s->field_78;
        f = (u8 *)s->field_64[s->field_4C];
        pos = s->field_58;
        for (i = 0; i < s->field_8; i++) {
            e->field_80 = f[s->field_58++];
            e++;
        }
        q = &f[s->field_58];
        if (*q & 0x80) {
            switch (*q) {
            case 0xFF:
                s->field_60 = -1;
                s->field_58 = pos;
                goto done;
            case 0xFE:
                s->field_58 = (q[2] << 8) | q[1];
                s->field_60 = -1;
                break;
            }
        }
    }
done:
    e = s->field_78;
    for (i = 0; i < s->field_8; i++) {
        r = &((Rec18 *)s->field_68[i])[e->field_80];
        e->field_60.m = r->m;
        for (j = 0; j < 3; j++) {
            e->field_60.t[j] = r->t[j];
        }
        e++;
    }
}


extern Blk20 D_80043714;

void Gfx_ResetModelBones(Actor *a0) {
    Sub3C *sub = a0->field_3C;
    DstElem *p = sub->field_78;
    s32 i = 0;
    while (i < sub->field_8) {
        i++;
        p->field_60 = D_80043714;
        p++;
    }
}

void Gfx_AddFlatQuad3D(Col1F668 *col, SVec1F668 *v, s32 flags, s32 idx) {
    Coord1F668 coord;
    Mat1F668 m;
    s32 pz;
    s32 flag;
    PolyF4_1F668 *p;
    PolyF4_1F668 *q;
    DrMode1F668 *dm;
    s32 *ot;
    Actor *g;

    GsInitCoordinate2(0, &coord);
    GsGetLs(&coord, &m);
    GsSetLsMatrix(&m);
    g = &D_8005F770;
    p = (PolyF4_1F668 *)g->work;
    ot = g->field_138[idx];
    p->c = *col;
    SetPolyF4((u8 *)p);
    q = p;
    if (flags & 4) {
        p->c.code |= 2;
    }
    RotTransPers(&v[0], &p->xy[0], &pz, &flag);
    p->xy[0].x /= 2;
    p->xy[0].y /= 2;
    RotTransPers(&v[1], &p->xy[1], &pz, &flag);
    p->xy[1].x /= 2;
    p->xy[1].y /= 2;
    RotTransPers(&v[2], &p->xy[2], &pz, &flag);
    p->xy[2].x /= 2;
    p->xy[2].y /= 2;
    RotTransPers(&v[3], &p->xy[3], &pz, &flag);
    p->xy[3].x /= 2;
    p->xy[3].y /= 2;
    p->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p++;
    SetDrawMode((DrMode1F668 *)p, 0, 0, (flags & 3) << 5, 0);
    dm = (DrMode1F668 *)(q + 1);
    dm->tag.addr = ((Tag1F668 *)ot)->addr;
    ((Tag1F668 *)ot)->addr = (u32)p;
    p = (PolyF4_1F668 *)(dm + 1);
    g->work = (ActorWork *)p;
}


void Gfx_InitLights(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        GsSetFlatLight(i, &D_800416CC[i]);
    }
    GsSetAmbient(0x4CC, 0x4CC, 0x4CC);
    GsSetLightMode(0);
}

s32 func_8001F970(s32 arg0) {
    if (arg0 == 0x64 || arg0 == 0xA || arg0 == 0x14) {
        return 0;
    }
    if (arg0 == 0x15) {
        return 0;
    }
    return arg0 != 0x16;
}

void Gfx_AnimateModelTex(Actor *a0) {
    Sub3C *w = a0->field_3C;
    Part1F9AC *r = (Part1F9AC *)w->field_1C;
    Pos1F9AC *pos = w->field_44;
    s32 k = 0;
    s32 j;
    s32 i;
    s32 m;
    DrMove2AB54 *prim;
    Rect2AB54 rc;
    Rect2AB54 rc2;
    Anim1F9AC *q;
    u8 n;

    if (r->field_0 != 0xFF) {
        if (func_8001F970(w->field_54) != 0) {
            switch (w->field_2C >> 1) {
            case 0:
                w->field_2C = (Rand_Next() & 0x7F) + 0x3C;
                k = 0;
                break;
            case 1:
            case 2:
            case 5:
            case 6:
                k = 2;
                break;
            case 3:
            case 4:
                k = 4;
                break;
            }
            if ((w->field_2C -= D_8005F770.field_8) < 0) {
                w->field_2C = 0;
            }
        } else {
            k = 4;
            w->field_2C = 0;
        }
    }
    w->field_30 += D_8005F770.field_8;
    while (1) {
        if (w->field_30 < 0x18) break;
        w->field_30 -= 0x18;
    }
    j = (w->field_30 / 8) * 2;
    prim = ((Wk1F9AC *)&D_8005F770)->field_2C;
    for (i = 0; i < 10; i++, r++) {
        if (i < 2) {
            if (r->field_0 == 0xFF) continue;
        } else {
            if (r->field_0 == 0xFF) break;
            if (r->field_0 == 0xFE) break;
        }
        if (i < 2) {
            rc.x = r->uv[k] + pos->field_18;
            rc.y = r->uv[k + 1] + pos->field_1C;
        } else {
            rc.x = r->uv[j] + pos->field_18;
            rc.y = r->uv[j + 1] + pos->field_1C;
        }
        rc.w = r->field_2;
        rc.h = r->field_3;
        SetDrawMove(prim, &rc, r->field_0 + pos->field_18, r->field_1 + pos->field_1C);
        AddPrim(((Wk1F9AC *)&D_8005F770)->field_150, (unsigned int *)prim);
        prim++;
    }
    if (r->field_0 == 0xFE) {
        q = (Anim1F9AC *)&r->field_1;
        for (i = 0; i < 10; i++, q++) {
            if (q->field_0 == 0xFF) break;
            if (D_8005F770.field_8 == 1) {
                q->field_9 += 1;
            } else {
                q->field_9 += 2;
            }
            n = q->field_8;
            while (1) {
                if (q->field_9 < n) break;
                q->field_9 -= n;
            }
            m = (q->field_9 >> 1) * 4;
            rc2.x = q->uv[m] + pos->field_18;
            rc2.y = q->uv[m + 1] + pos->field_1C;
            rc2.w = q->field_2;
            rc2.h = q->field_3;
            SetDrawMove(prim, &rc2, q->field_0 + pos->field_18, q->field_1 + pos->field_1C);
            AddPrim(((Wk1F9AC *)&D_8005F770)->field_150, (unsigned int *)prim);
            prim++;
            rc2.x = q->uv[m + 2] + pos->field_18;
            rc2.y = q->uv[m + 3] + pos->field_1C;
            rc2.w = q->field_6;
            rc2.h = q->field_7;
            SetDrawMove(prim, &rc2, q->field_4 + pos->field_18, q->field_5 + pos->field_1C);
            AddPrim(((Wk1F9AC *)&D_8005F770)->field_150, (unsigned int *)prim);
            prim++;
        }
    }
    D_8005F79C = (s32)prim;
}


Sub3C *Gfx_AttachModel(Actor *a0, s32 id) {
    s32 fresh = 0;
    Mdl1FDBC *m = (Mdl1FDBC *)Cd_GetFileOrNull(id);
    Mdl1FDBC *base = m;
    Sub3C *t = a0->field_3C;
    Sub3C *s;
    s32 i;
    Sec1FDBC20 *p;
    Sec1FDBC20 *q;
    Sec1FDBC16 *r;
    s32 v;
    Ent1FDBC20 *e;

    if (t == NULL) {
        a0->field_3C = (Sub3C *)Mem_Alloc(0x7C, 2);
        Mem_Zero(a0->field_3C, 0x7C);
        fresh = 1;
    } else if (t->field_4 == m && m->field_4 != 0) {
        return t;
    }
    s = a0->field_3C;
    s->field_0 = id;
    s->field_4 = base;
    s->field_8 = m->field_8;
    s->field_C = (s16 **)base->field_C;
    s->field_10 = s->field_C + s->field_8;
    s->field_14 = (Sec1FDBC20 **)(s->field_10 + s->field_8);
    s->field_18 = (s32 *)(s->field_14 + s->field_8);
    s->field_1C = s->field_18 + s->field_8;
    if (m->field_4 == 0) {
        for (i = 0; i < s->field_8; i++) {
            s->field_C[i] = (s16 *)((s32)s->field_C[i] + (s32)base);
            s->field_10[i] = (s16 *)((s32)s->field_10[i] + (s32)base);
            s->field_14[i] = (Sec1FDBC20 *)((s32)s->field_14[i] + (s32)base);
        }
        m->field_4 = 1;
    }
    if (fresh) {
        s->field_20 = 0;
        s->field_24 = 0;
        for (i = 0; i < s->field_8; i++) {
            if (s->field_20 < *s->field_C[i]) {
                s->field_20 = *s->field_C[i];
            }
            if (s->field_24 < *s->field_10[i]) {
                s->field_24 = *s->field_10[i];
            }
        }
        s->field_28 = 0;
        for (i = 0; i < s->field_8; i++) {
            p = s->field_14[i];
            e = p->e;
            q = (Sec1FDBC20 *)(e + p->n);
            e = q->e;
            r = (Sec1FDBC16 *)(e + q->n);
            v = r->e[r->n].v[0];
            if (s->field_28 < v) {
                s->field_28 = v;
            }
        }
        s->field_78 = (DstElem *)Mem_Alloc(s->field_8 * sizeof(DstElem), 2);
        s->field_6C = (s32 *)Mem_Alloc(s->field_20 * 4, 2);
        s->field_70 = (s32 *)Mem_Alloc(s->field_20 * 4, 2);
        s->field_74 = (s32 *)Mem_Alloc(s->field_24 * 4, 2);
    }
    return s;
}

void Gfx_CalcModelBoneMatrices(Actor *a0) {
    ObjC0E4 cam;
    Mat1F668 light;
    Sub3C *s;
    ObjEC10 *o;
    DstElem *d;
    SpNode200D0 *sp;
    SpNode200D0 *e;
    Blk20 *r;
    Blk20 *in;
    Blk20 *out;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    s = a0->field_3C;
    o = a0->u38.ptr38;
    d = s->field_78;
    cam = D_80061A08;
    light = D_800619A8;
    sp = (SpNode200D0 *)0x1F800000;
    sp[0].parent = 0;
    sp[0].local = o->field_0;
    sp[0].local.t[0] = o->field_30;
    sp[0].local.t[1] = o->field_34;
    sp[0].local.t[2] = o->field_38;
    sp[0].world.m = sp[0].local;
    for (i = 1; i < 9; i++) {
        sp[i].parent = &sp[i - 1];
    }
    n = s->field_8;
    for (j = 0; j < n; j++, d++) {
        e = &sp[s->field_18[j] + 1];
        e->local = d->field_60;
        for (k = 0; k < 3; k++) {
            switch (k) {
            default:
            case 0:
                r = &e->parent->world.m;
                in = &e->local;
                out = &e->world.m;
                break;
            case 1:
                r = (Blk20 *)&cam;
                in = &e->world.m;
                out = &d->field_0;
                break;
            case 2:
                r = (Blk20 *)&light;
                in = &e->world.m;
                out = &d->field_40;
                break;
            }
            gte_SetRotMatrix(r);
            gte_ldclmv(&in->m.m[0][0]);
            gte_rtir();
            if (k == 1) {
                d->field_20 = e->world.w[0];
                d->field_24 = e->world.w[1];
            }
            gte_stclmv(&out->m.m[0][0]);
            gte_ldclmv(&in->m.m[0][1]);
            gte_rtir();
            if (k == 1) {
                d->field_28 = e->world.w[2];
                d->field_2C = e->world.w[3];
            }
            gte_stclmv(&out->m.m[0][1]);
            gte_ldclmv(&in->m.m[0][2]);
            gte_rtir();
            if (k == 1) {
                d->field_30 = e->world.w[4];
                d->field_34 = e->world.w[5];
            }
            gte_stclmv(&out->m.m[0][2]);
            gte_SetTransMatrix(r);
            gte_ldlv0(in->t);
            gte_rtv0tr();
            if (k == 1) {
                d->field_38 = e->world.w[6];
                d->field_3C = e->world.w[7];
            }
            gte_stlvnl(out->t);
        }
    }
}


void Gfx_DrawTexModel(Actor *a0, s32 mode) {
    Sub3C *s;
    DstElem *e;
    Sec1FDBC20 *p;
    QuadGT4_2130C *q;
    TriGT3_20FD0 *r;
    s32 i;
    s32 j;
    s32 n;

    s = a0->field_3C;
    i = 0;
    e = s->field_78;
    s->field_44 = (struct Pos1F9AC *)Gfx_FindOrLoadTexSlot(s->field_0 << 16);
    s->field_40 = D_8005F770.field_118[s->field_3C] - 2;
    for (; i < s->field_8; i++, e++) {
        p = s->field_14[i];
        gte_SetRotMatrix(&e->field_0);
        gte_SetTransMatrix(&e->field_0);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->field_C[i], (Obj21ABC *)s, mode) != 0) {
            continue;
        }
        gte_SetLightMatrix(&e->field_40);
        Gfx_CalcNormalColors((Vert6Pmv *)s->field_10[i], (Obj21ABC *)s);
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = (QuadGT4_2130C *)p->e;
            if (n != 0) {
                if (s->field_34 == 1) {
                    Gfx_AddQuadsGT4(q, n, s, 2);
                } else {
                    Gfx_AddQuadsGT4(q, n, s, j);
                }
                q += n;
            }
            p = (Sec1FDBC20 *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = (TriGT3_20FD0 *)((Sec1FDBC16 *)p)->e;
            if (n != 0) {
                if (s->field_34 == 1) {
                    func_80020FD0(r, n, s, 2);
                } else {
                    func_80020FD0(r, n, s, j);
                }
                r += n;
            }
            p = (Sec1FDBC20 *)r;
        }
    }
    Gfx_AnimateModelTex(a0);
}


void Gfx_DrawWireModel(Actor *a0, s32 mode, Col21ABC *col) {
    Sub3C *s;
    DstElem *e;
    Sec1FDBC20 *p;
    Ent1FDBC20 *q;
    Ent1FDBC16 *r;
    s32 i;
    s32 j;
    s32 n;

    i = 0;
    s = a0->field_3C;
    e = s->field_78;
    s->field_40 = D_8005F770.field_118[s->field_3C] - 2;
    for (; i < s->field_8; i++, e++) {
        p = s->field_14[i];
        gte_SetRotMatrix(&e->field_0);
        gte_SetTransMatrix(&e->field_0);
        if (mode == 0 && Gfx_IsOriginOffscreen() != 0) {
            continue;
        }
        if (Gfx_ProjectModelVerts((Vert6Pmv *)s->field_C[i], (Obj21ABC *)s, mode) != 0) {
            continue;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            q = p->e;
            if (n != 0) {
                Gfx_DrawWireQuads((Quad21ABC *)q, n, (Obj21ABC *)s, col);
                q += n;
            }
            p = (Sec1FDBC20 *)q;
        }
        for (j = 0; j < 2; j++) {
            n = p->n;
            r = ((Sec1FDBC16 *)p)->e;
            if (n != 0) {
                Gfx_DrawWireTris((Tri218CC *)r, n, (Obj21ABC *)s, col);
                r += n;
            }
            p = (Sec1FDBC20 *)r;
        }
    }
}


extern void func_8002D744(void *, Obj209 *);
extern void ScaleMatrix(Obj209 *, s32 *);

void Actor_UpdateTransform(Actor *arg0) {
    Obj209 *obj = (Obj209 *)arg0->u38.ptr38;
    s32 local[3];

    obj->field_20 = obj->field_30;
    func_8002D744(&obj->field_40, obj);
    ApplyMatrixLV((ObjC0E4 *)obj, &obj->field_48, local);
    obj->field_30.x += local[0];
    obj->field_30.y += local[1];
    obj->field_30.z += local[2];
    if (obj->field_58 == 0x1000 && obj->field_5C == obj->field_58 &&
        obj->field_60 == obj->field_5C) {
    } else {
        ScaleMatrix(obj, &obj->field_58);
    }
    obj->field_50 = 0;
    obj->field_4C = 0;
    obj->field_48 = 0;
}

s32 Actor_ProjectToScreen(ContC40 *a0) {
    Mat1F668 m;
    AllocC40 *p;
    Vec3_209F8 *t;
    s32 x, y;

    p = a0->field_38;
    t = &p->t;
    *t = *(Vec3_209F8 *)&p->field_30;
    gte_SetRotMatrix(&D_80061A08);
    gte_ldclmv(&p->m[0][0]);
    gte_rtir();
    gte_stclmv(&m.m[0][0]);
    gte_ldclmv(&p->m[0][1]);
    gte_rtir();
    gte_stclmv(&m.m[0][1]);
    gte_ldclmv(&p->m[0][2]);
    gte_rtir();
    gte_stclmv(&m.m[0][2]);
    gte_SetTransMatrix(&D_80061A08);
    gte_ldlv0(t);
    gte_rtv0tr();
    gte_stlvnl(m.t);
    gte_SetRotMatrix(&m);
    gte_SetTransMatrix(&m);
    gte_ldv0(&D_80050744);
    gte_rtps();
    gte_stsxy(&p->field_68);
    x = 0x160;
    y = 0x110;
    if (p->field_68 < -x) return 1;
    if (p->field_68 > x) return 1;
    if (p->field_6A < -y) return 1;
    return p->field_6A > y;
}


void Actor_RefreshTransform(s32 arg0) {
    Actor_UpdateTransform(arg0);
    Actor_ProjectToScreen(arg0);
}

extern void Mem_Zero(void *, s32);

void Actor_InitTransform(ContC40 *a0, s32 *a1, u16 a2) {
    AllocC40 *p;
    if (a0->field_38 == 0) {
        a0->field_38 = (AllocC40 *)Mem_Alloc(0x90, 2);
    }
    Mem_Zero(a0->field_38, 0x90);
    p = a0->field_38;
    p->field_60 = 0x1000;
    p->field_5C = 0x1000;
    p->field_58 = 0x1000;
    if (a1 != 0) {
        p->field_30 = a1[0];
        p->field_34 = a1[1];
        p->field_38 = a1[2];
    }
    p->field_42 = a2;
    Actor_RefreshTransform((s32)a0);
}

void func_80020CE8(Obj20CE8 *a0, s32 a1) {
    s32 v = a0->field_0 + a0->field_4;
    a0->field_0 = v;
    if (v > 0) {
        if (v >= a0->field_8) {
            a0->field_0 = a0->field_8;
        }
    } else if (a1 == 0) {
        a0->field_8 = 0;
        a0->field_4 = 0;
        a0->field_0 = 0;
    } else {
        if (v >= a0->field_8) {
            a0->field_0 = -a0->field_8;
        }
    }
}

s32 func_80020D54(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->field_38;
    Obj20CE8 *e = &p->field_6C[i];

    if (i != 1) {
        func_80020CE8(e, 0);
    } else {
        func_80020CE8(e, 1);
    }
    if (i != 2) {
        p->field_48[i] += e->field_0 >> 8;
    } else {
        p->field_48[2] -= e->field_0 >> 8;
    }
    return e->field_0 >> 8;
}

s32 func_80020E00(ContC40 *a0, s32 i) {
    AllocC40 *p = a0->field_38;
    Obj20CE8 *e = &p->field_6C[i];

    func_80020CE8(e, 0);
    switch (i) {
    case 0:
    case 1:
        p->field_48[i] -= e->field_0 >> 8;
        break;
    case 2:
        p->field_48[2] += e->field_0 >> 8;
        break;
    }
    return e->field_0 >> 8;
}

void func_80020EB0(Ctx38 *arg0, s32 arg1, Elem12 *arg2) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->field_0 = arg2->field_0;
    e->field_4 = arg2->field_4;
    e->field_8 = arg2->field_8;
}

void func_80020EE8(Ctx38 *arg0, s32 arg1) {
    Elem12 *e = &arg0->buf->elems[arg1];
    e->field_8 = 0;
    e->field_4 = 0;
    e->field_0 = 0;
}

void Gfx_CalcNormalColors(Vert6Pmv *v, Obj21ABC *o) {
    s32 n;
    Col21ABC *c;
    s32 i;

    n = v->vx;
    c = o->field_74;
    v++;
    if (o->field_34 != 0) {
        for (i = 0; i < n; i++) {
            *c = o->field_38;
            c++;
        }
        return;
    }
    gte_ldv0u(v);
    gte_ncs();
    gte_strgb(c);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_ncs();
        v++;
        c++;
        i++;
        gte_strgb(c);
    }
}

INCLUDE_ASM("asm/USA/main/nonmatchings/156C", func_80020FD0);

void Gfx_AddQuadsGT4(QuadGT4_2130C *t, s32 n, Sub3C *s, s32 mode) {
    s32 sxy[4];
    s32 opz;
    s32 *xy;
    s32 *sz;
    Col21ABC *col;
    Elem20 *tex;
    s32 idx;
    u8 code;
    PolyGT4_2130C *p;
    s32 i;
    s32 z;
    Actor *g;

    tex = (Elem20 *)s->field_44;
    xy = s->field_6C;
    col = (Col21ABC *)s->field_74;
    sz = s->field_70;
    idx = s->field_3C;
    code = 0x3E;
    if (mode == 1) {
        code = 0x3C;
    }
    g = &D_8005F770;
    p = (PolyGT4_2130C *)g->work;
    for (i = 0; i < n; i++, t++) {
        sxy[0] = xy[t->v[0]];
        sxy[1] = xy[t->v[1]];
        sxy[2] = xy[t->v[2]];
        sxy[3] = xy[t->v[3]];
        gte_ldsxy3(sxy[0], sxy[1], sxy[2]);
        gte_nclip();
        if (sxy[0] == sxy[1] || sxy[0] == sxy[2] || sxy[0] == sxy[3] ||
            sxy[1] == sxy[2] || sxy[1] == sxy[3] || sxy[2] == sxy[3]) {
            continue;
        }
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        p->tag.len = 12;
        p->c0.code = 0x3C;
        p->xy0 = sxy[0];
        p->xy1 = sxy[1];
        p->xy2 = sxy[2];
        p->xy3 = sxy[3];
        p->c0 = col[t->c[0]];
        p->c1 = col[t->c[1]];
        p->c2 = col[t->c[2]];
        p->c3 = col[t->c[3]];
        p->c0.code = code;
        z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]] + sz[t->v[3]]) / 4;
        if (mode == 2) {
            p->tpage = tex->field_10 | s->field_36;
        } else {
            p->tpage = tex->field_10 | t->tpage;
        }
        p->clut = t->clut + (((tex->field_1C + s->field_34) << 6) | ((tex->field_18 >> 4) & 0x3F));
        p->u0 = t->u0 + tex->field_C;
        p->u1 = t->u1 + tex->field_C;
        p->u2 = t->u2 + tex->field_C;
        p->u3 = t->u3 + tex->field_C;
        p->v0 = t->v0;
        p->v1 = t->v1;
        p->v2 = t->v2;
        p->v3 = t->v3;
        p->tag.addr = ((Tag21ABC *)&g->field_138[idx][z])->addr;
        ((Tag21ABC *)&g->field_138[idx][z])->addr = (u32)p;
        p++;
    }
    D_8005F79C = (s32)p;
}


s32 Gfx_ProjectModelVerts(Vert6Pmv *v, Obj21ABC *o, s32 noCheck) {
    s32 otz;
    s32 flag;
    s32 n;
    SxyPmv *sxy;
    s32 *z;
    s32 zs;
    s32 xs;
    s32 ys;
    s32 i;
    ScrPmv *scr;

    n = v->vx;
    v++;
    scr = (ScrPmv *)&D_8005F770;
    sxy = (SxyPmv *)o->field_6C;
    z = o->field_70;
    zs = o->field_40;
    xs = scr->w != 320;
    ys = scr->h != 240;
    gte_ldv0u(v);
    gte_rtps();
    gte_stsxy(sxy);
    gte_stszotz(&otz);
    v++;
    for (i = 1; i < n; ) {
        gte_ldv0u(v);
        gte_rtps();
        v++;
        i++;
        *z = otz >> zs;
        z++;
        sxy->vx >>= xs;
        sxy->vy >>= ys;
        sxy++;
        gte_stsxy(sxy);
        gte_stszotz(&otz);
        if (!noCheck) {
            gte_stflg(&flag);
            if (flag < 0) {
                return 1;
            }
        }
    }
    *z = otz >> zs;
    sxy->vx >>= xs;
    sxy->vy >>= ys;
    return 0;
}

s32 Gfx_IsOriginOffscreen(void) {
    SxyIso sxy;
    s32 flag;

    gte_ldv0(D_80043704);
    gte_rtps();
    gte_stflg(&flag);
    if (flag < 0) {
        return 1;
    }
    gte_stsxy(&sxy);
    if (sxy.vx < -0x160) {
        return 1;
    }
    if (sxy.vx > 0x160) {
        return 1;
    }
    if (sxy.vy < -0x110) {
        return 1;
    }
    return sxy.vy > 0x110;
}

void Gfx_DrawWireTris(Tri218CC *t, s32 n, Obj21ABC *o, Col21ABC *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 *sxy;
    s32 *sz;
    Tag21ABC *pk;
    LineF4_21ABC *l;
    Tpage21ABC *tp;
    s32 idx;

    pk = (Tag21ABC *)D_8005F770.work;
    sxy = o->field_6C;
    sz = o->field_70;
    idx = o->field_3C;
    for (i = 0; i < n; i++, t++) {
        do {
            z = (sz[t->v[0]] + sz[t->v[1]] + sz[t->v[2]]) / 3;
            ot = (u32 *)D_8005F770.field_138[idx];
            l = (LineF4_21ABC *)pk;
            l->c = *col;
            l->tag.len = 6;
            l->c.code = 0x4E;
            l->end = 0x55555555;
            l->xy[3] = l->xy[0] = sxy[t->v[0]];
            l->xy[1] = sxy[t->v[1]];
            l->xy[2] = sxy[t->v[2]];
            ot += z;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((LineF4_21ABC *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F79C = (s32)pk;
}

void Gfx_DrawWireQuads(Quad21ABC *q, s32 n, Obj21ABC *o, Col21ABC *col) {
    s32 i;
    s32 z;
    u32 *ot;
    s32 xy[4];
    s32 *sxy;
    s32 *sz;
    Tag21ABC *pk;
    LineF4_21ABC *l4;
    LineF2_21ABC *l2;
    Tpage21ABC *tp;
    s32 idx;

    pk = (Tag21ABC *)D_8005F770.work;
    sxy = o->field_6C;
    sz = o->field_70;
    idx = o->field_3C;
    for (i = 0; i < n; i++, q++) {
        do {
            z = (sz[q->v[0]] + sz[q->v[1]] + sz[q->v[2]] + sz[q->v[3]]) / 4;
            ot = (u32 *)D_8005F770.field_138[idx];
            xy[0] = sxy[q->v[0]];
            xy[1] = sxy[q->v[1]];
            xy[2] = sxy[q->v[2]];
            xy[3] = sxy[q->v[3]];
            l4 = (LineF4_21ABC *)pk;
            l4->c = *col;
            l4->tag.len = 6;
            l4->c.code = 0x4E;
            l4->end = 0x55555555;
            l4->xy[0] = xy[0];
            l4->xy[1] = xy[1];
            l4->xy[2] = xy[3];
            l4->xy[3] = xy[2];
            do {
            } while (0);
            ot += z;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((LineF4_21ABC *)pk + 1);
            l2 = (LineF2_21ABC *)pk;
            l2->c = *col;
            l2->tag.len = 3;
            l2->c.code = 0x42;
            l2->xy[0] = xy[2];
            l2->xy[1] = xy[0];
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((LineF2_21ABC *)pk + 1);
            tp = (Tpage21ABC *)pk;
            tp->tag.len = 1;
            tp->code = 0xE1000620;
            pk->addr = ((Tag21ABC *)ot)->addr;
            ((Tag21ABC *)ot)->addr = (u32)pk;
            pk = (Tag21ABC *)((Tpage21ABC *)pk + 1);
        } while (0);
    }
    D_8005F79C = (s32)pk;
}


void func_80021D50(void) {
}

void func_80021D58(void) {
}

s32 func_80021D60(void) {
    s32 best = 0;
    s32 i;
    s32 v;

    if (D_8005071C->field_BA8 != 0) {
        for (i = 0; i < D_8005071C->field_BA8; i++) {
            best = (best < (v = D_8005071C->field_BA9[i])) ? v : best;
        }
    }
    return best;
}


void Save_ClearEventFlags(void) {
    s32 i;
    V1004_21DC8 *p;

    i = 0x1F;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->a[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 7;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->b[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 7;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->c[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    i = 0xF;
    p = (V1004_21DC8 *)((u8 *)&D_8005E620 + i);
    do {
        p->d[0] = 0;
        p = (V1004_21DC8 *)((u8 *)p - 1);
    } while (--i >= 0);
    D_8005F664 = 0;
}


s32 Mem_TestBit(u8 *arg0, s32 arg1) {
    s32 i = arg1 >> 3;
    s32 m = 1 << (arg1 & 7);

    return (arg0[i] & m) != 0;
}

/* file-local views over D_8005E620 for Flag_Test */
typedef struct { u8 _p[0x66]; u16 a[1]; } V66_21E78;
typedef struct { u8 _p[0xDD4]; u16 a[1]; } VDD4_21E78;
typedef struct { u8 field_0; u8 field_1; u8 _p[0x5A]; } ElmV_21E78; /* 0x5C */
typedef struct { u8 _p[0xE4]; ElmV_21E78 elems[0x24]; } EntV_21E78;

extern s32 D_8005F624;
extern s32 D_8005F644;
extern s32 D_8005F64C;
extern s32 D_8005F654;
extern s32 D_8005F664;
extern s32 Mem_TestBit(u8 *, s32);
extern s32 func_80066B48(s32);

s32 Flag_Test(s32 arg0) {
    s32 i;

    if (arg0 < 0x258) {
        return Mem_TestBit(&D_8005F624, arg0);
    }
    if (arg0 < 0x2BC) {
        return Mem_TestBit(&D_8005F644, arg0 - 0x258);
    }
    if (arg0 < 0x320) {
        return Mem_TestBit(&D_8005F64C, arg0 - 0x2BC);
    }
    if (arg0 < 0x3E8) {
        return Mem_TestBit(&D_8005F654, arg0 - 0x320);
    }
    if (arg0 < 0x44C) {
        return D_8005F664 >= arg0 - 0x3E8;
    }
    if (arg0 < 0x640) {
        return D_8005F664 < arg0 - 0x5DC;
    }
    if (arg0 < 0x8BD) {
        for (i = 0; i < 0x30; i++) {
            if (((V66_21E78 *)&D_8005E620)->a[i] == arg0 - 0x7D0) {
                return 1;
            }
        }
        return 0;
    }
    if (arg0 < 0xBB8) {
        return ((VDD4_21E78 *)&D_8005E620)->a[arg0 - 0x7D0] != 0;
    }
    if (arg0 < 0xFA0) {
        s32 key = arg0 - 0xBB8;
        for (i = 0; i < 0x24; i++) {
            if (((EntV_21E78 *)&D_8005E620)->elems[i].field_1 == key) {
                if (((EntV_21E78 *)&D_8005E620)->elems[i].field_0 >= 2) {
                    return 1;
                }
            }
        }
        return 0;
    }
    if (func_80013378() == 2) {
        return func_80066B48(arg0);
    }
    return 0;
}

typedef struct {
    s16 id;
    s16 flag;
} Ent22038;

s32 Flag_TestConds(Ent22038 *p) {
    s32 i;
    for (i = 0; i < 6; i++, p++) {
        if (p->id != -1) {
            if (p->flag != 0) {
                if (Flag_Test(p->id) != 1) {
                    return 0;
                }
            } else {
                if (Flag_Test(p->id) != 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


void Mem_WriteBit(u8 *arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 >> 3;
    s32 mask = 1 << (arg1 & 7);
    if (arg2 != 0) {
        arg0[idx] |= mask;
    } else {
        arg0[idx] &= ~mask;
    }
}

void Digi_AddNew(s32 arg0) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        if (D_8005E620.elems[i].field_0 == 0) {
            break;
        }
    }
    Digi_InitFromTable(arg0, 0, &D_8005E620.elems[i]);
    Digi_SortRoster();
    for (i = 0; i < 3; i++) {
        D_8005E620.elems[i].field_0 =
            (D_8005E620.elems[i].field_0 >= 2) ? (i + 3) : 0;
    }
}

void Flag_Set(s32 id, s32 val) {
    if (id < 600) {
        if (id == 0x10 && val == 0) {
            Mem_WriteBit((u8 *)&D_8005F624, 0x11, 0);
        }
        Mem_WriteBit((u8 *)&D_8005F624, id, val);
    } else if (id < 700) {
        Mem_WriteBit((u8 *)&D_8005F644, id - 600, val);
    } else if (id < 800) {
        Mem_WriteBit((u8 *)&D_8005F64C, id - 700, val);
    } else if (id < 1000) {
        Mem_WriteBit((u8 *)&D_8005F654, id - 800, val);
    } else if (id < 2000) {
        D_8005F664 = id - 1900;
    } else if (id < 0x8BD) {
        D_8005E6E4 = id - 2000;
        Item_SortList();
    } else if (id < 3000) {
        ((VDD4_21E78 *)&D_8005E620)->a[id - 2000]++;
    } else if (id < 4000) {
        switch (id - 3000) {
        case 3:
            Digi_AddNew(0xB7);
            break;
        case 31:
            Digi_AddNew(0xB6);
            break;
        case 217:
            Digi_AddNew(0xB8);
            break;
        }
    } else if (id < 10000) {
        if (func_80013378() == 2) {
            func_80066F34(id, val);
        }
    }
}

void Flag_ApplySets(Pair22388 *p) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (p[i].field_0 != -1) {
            Flag_Set(p[i].field_0, p[i].field_2);
        }
    }
}

s32 Math_CycleRange(s32 v, s32 div, s32 lo, s32 hi) {
    s32 r;
    v /= div;
    if (lo < hi) {
        r = v % (hi - lo + 1);
        return r + lo;
    } else {
        r = v % (lo - hi + 1);
        return lo - r;
    }
}


s32 Math_PingPongRange(s32 v, s32 div, s32 lo, s32 hi) {
    s32 span;
    s32 r;

    v /= div;
    span = hi - lo;
    r = v % (span * 2);
    if (r < span) {
        return r + lo;
    }
    return hi - (r - span);
}


void func_80022468(void) {
    Mem_Zero(D_80050720, 0x1058);
    D_80050720->field_0 = 1;
    Save_ClearEventFlags();
    D_8005E620.field_14 = 0x8F;
    D_8005E620.field_15 = 0x95;
    D_8005E620.field_16 = 0xB7;
    D_8005E620.field_17 = 0xFF;
    D_8005E620.field_8 = 0x1F4;
    D_8005E620.field_D1 = 0x9E;
    D_8005E620.field_D2 = 0xD5;
    D_8005E620.field_D3 = 0x96;
    D_8005E620.field_D4 = 0xFF;
    D_8005E620.field_4 = 0;
}


void func_800224EC(s32 i, s32 v, s32 flag) {
    Obj50720 *p = D_80050720;
    u8 *q = &p->field_52[i];

    p->field_2C[i] = v;
    if (v != 0) {
        *q = flag;
        return;
    }
    *q = 1;
}


s32 func_80022518(s32 i) {
    Obj50720 *p = D_80050720;
    if (p->field_52[i] == 1) {
        return -1;
    }
    return p->field_2C[i];
}


void func_8002254C(s32 i, s32 v) {
    s32 r = 0;
    Obj50720 *p = D_80050720;
    u16 t = p->field_2C[i];
    u8 *q = &p->field_52[i];

    if (t != 0) {
        r = v;
    }
    *q = r;
}


u8 func_80022578(void) {
    u8 result = 0;
    s32 v = func_80022518(2) - 0x2F;
    if ((u32)v < 6) {
        result = D_800416FC[v];
    }
    return result;
}

s32 func_800225C4(void) {
    s32 r;
    s32 n;
    s32 i;

    r = -1;
    n = Item_GetBagCapacity();
    for (i = 0; i < n; i++) {
        if (D_80050720->field_66[i] == 0) {
            r = i;
            goto done;
        }
    }
done:
    return r;
}


void Item_CompactBag(void) {
    u16 *src;
    u16 *dst;
    s32 i;
    s32 v;

    src = D_80050720->field_66;
    dst = src;
    for (i = 0; i < 0x30; i++, src++) {
        v = *src;
        *src = 0;
        if (((s32 (*)(s32))Item_CheckId)(v & 0xFFFF) == 0) {
            *dst = v;
            if ((v & 0xFFFF) != 0) {
                dst++;
            }
        }
    }
}


void Item_SortList(void) {
    u16 *base = D_80050720->field_66;
    u16 *pi;
    s32 i;
    s32 j;
    s32 best;
    s32 bestv;
    s32 v;
    u16 t;

    Item_CompactBag();
    pi = base;
    for (i = 0; i < 0x2F; i++, pi++) {
        if (*pi == 0) {
            return;
        }
        best = i;
        bestv = Item_GetTableIndex(*pi);
        for (j = i + 1; j < 0x30; j++) {
            if (base[j] == 0) {
                break;
            }
            v = Item_GetTableIndex(base[j]);
            if (v < bestv) {
                best = j;
                bestv = v;
            }
        }
        if (best != i) {
            t = *pi;
            *pi = base[best];
            base[best] = t;
        }
    }
}


s32 Item_AddToBag(s32 id) {
    s32 i = func_800225C4();
    if (i != -1) {
        D_80050720->field_66[i] = id;
    }
    return i;
}


void Item_RemoveFromBag(s32 i) {
    D_80050720->field_66[i] = 0;
    Item_CompactBag();
}


s32 Item_GetBagCapacity(void) {
    u16 v = D_80050720->field_34;
    s32 r = v - 0x49;
    s32 ret = 8;
    if ((u32)(v - 0x4B) < 5) {
        ret = r * 8;
    }
    return ret;
}


s32 Digi_CountByState(s32 mode) {
    s32 n = 0;
    s32 i;
    ElmE620 *e = D_80050720->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->field_0 == mode) n++;
            break;
        case 2:
            if (e->field_0 >= 2) n++;
            break;
        case 3:
            if (e->field_0 >= 3) n++;
            break;
        case 4:
            if (e->field_0 == 2) n++;
            break;
        }
    }
    return n;
}


s32 Digi_ListByState(s32 mode, ElmE620 **list) {
    s32 n = 0;
    s32 i;
    ElmE620 **p = list;
    ElmE620 *e = D_80050720->elems;

    for (i = 0; i < 0x24; i++, e++) {
        switch (mode) {
        default:
            if (e->field_0 == mode) {
                *p++ = e;
                n++;
            }
            break;
        case 2:
            if (e->field_0 >= 2) {
                *p++ = e;
                n++;
            }
            break;
        case 3:
            if (e->field_0 >= 3) {
                p++;
                list[e->field_0 - 3] = e;
                n++;
            }
            break;
        case 4:
            if (e->field_0 == 2) {
                *p++ = e;
                n++;
            }
            break;
        }
    }
    return n;
}


void Digi_CompactRoster(void) {
    ElmE620 tmp;
    ElmE620 *src;
    ElmE620 *dst;
    s32 i;

    src = D_80050720->elems;
    dst = src;
    for (i = 0; i < 0x24; i++, src++) {
        tmp = *src;
        src->field_0 = 0;
        if (tmp.field_0 != 0) {
            *dst = tmp;
            if (dst->field_0 != 0) {
                dst++;
            }
        }
    }
}


void Digi_SortRoster(void) {
    Tbl50724 tbl = D_80050724[0];
    ElmE620 *base = D_80050720->elems;
    ElmE620 tmp;
    s32 i;
    s32 j;
    s32 best;
    s32 bestk;
    s32 k;

    Digi_CompactRoster();
    for (i = 0; i < 0x23; i++) {
        if (base[i].field_0 == 0) {
            return;
        }
        best = i;
        bestk = base[i].field_1 + (999 - base[i].field_D) * 1000 + tbl.b[base[i].field_0] * 1000000;
        for (j = i + 1; j < 0x24; j++) {
            if (base[j].field_0 == 0) {
                break;
            }
            k = base[j].field_1 + (999 - base[j].field_D) * 1000 + tbl.b[base[j].field_0] * 1000000;
            if (k < bestk) {
                best = j;
                bestk = k;
            }
        }
        if (best != i) {
            tmp = base[i];
            base[i] = base[best];
            base[best] = tmp;
        }
    }
}


void Mem_Free(ActorWork *arg0) {
    Node22D84 *n = (Node22D84 *)((u8 *)arg0 - 0xC);
    Node22D84 *m = n->field_0;
    Node22D84 *nx = n->field_4;
    n->field_8 = 0;
    if (nx->field_8 == 0) {
        n->field_4 = nx->field_4;
        nx->field_4->field_0 = n;
    }
    if (m->field_8 == 0) {
        m->field_4 = n->field_4;
        n->field_4->field_0 = m;
    }
}

void Mem_FreeTag(s32 tag) {
    Blk22E60 *b = D_80050788;

    if (b->field_8 != 1) {
        do {
            if (b->field_8 == tag) {
                Mem_Free((ActorWork *)(b + 1));
            }
            b = b->field_4;
        } while (b->field_8 != 1);
    }
}


void Mem_InitHeap(Blk22E60 *heap, s32 size) {
    Blk22E60 *end;

    D_80050784 = size;
    D_80050788 = heap;
    end = (Blk22E60 *)((u8 *)heap + size) - 1;
    heap->field_0 = NULL;
    heap->field_4 = end;
    heap->field_8 = 0;
    end->field_0 = heap;
    end->field_4 = NULL;
    end->field_8 = 1;
}


s32 Mem_TryAlloc(s32 arg0, s32 tag) {
    u32 size = ((u32)(arg0 + 3) >> 2) << 2;
    Blk22E60 *b = D_80050788;
    Blk22E60 *n;
    u32 avail;
    u32 lim = size + 0x14;

    if (b->field_8 != 1) {
        do {
            if (b->field_8 == 0) {
                avail = (s32)b->field_4 - (s32)b - 0xC;
                if (avail >= size) {
                    if (lim < avail) {
                        n = (Blk22E60 *)((u8 *)b + size + 0xC);
                        n->field_0 = b;
                        n->field_4 = b->field_4;
                        n->field_8 = 0;
                        b->field_4->field_0 = n;
                        b->field_4 = n;
                    }
                    b->field_8 = tag;
                    return (s32)(b + 1);
                }
            }
            b = b->field_4;
        } while (b->field_8 != 1);
    }
    return 0;
}


s32 Mem_Alloc(s32 arg0, s32 arg1) {
    s32 r;
    while ((r = Mem_TryAlloc(arg0, arg1)) == 0) {
        Cd_EvictLruFile();
    }
    return r;
}

void Mem_Zero(void *a0, s32 a1) {
    s32 i;
    if (a1 & 3) {
        u8 *b = (u8 *)a0;
        for (i = 0; i < a1; i++) b[i] = 0;
    } else {
        s32 *w = (s32 *)a0;
        a1 >>= 2;
        for (i = 0; i < a1; i++) *w++ = 0;
    }
}

void Mem_SumSizesByTag(s32 *tbl) {
    Blk22E60 *b = D_80050788;

    if (b->field_8 != 1) {
        do {
            tbl[b->field_8] += (s32)b->field_4 - (s32)b;
            b = b->field_4;
        } while (b->field_8 != 1);
    }
}


u32 Mem_GetLargestFree(void) {
    Blk22E60 *b = D_80050788;
    u32 best = 0;
    u32 sz;

    while (b->field_8 != 1) {
        if (b->field_8 == 0) {
            sz = (s32)b->field_4 - (s32)b;
            if (best < sz) {
                best = sz;
            }
        }
        b = b->field_4;
    }
    return best;
}


void Pad_Init(void) {
    PadInitDirect(D_8005F6A8, D_8005F6A8 + 0x22);
    PadStartCom();
}

void Pad_ResetButtons(Rec230DC *arg0) {
    arg0->field_C = 0;
    arg0->field_15 = 0;
    arg0->field_14 = 0;
    arg0->field_10 = 0;
    arg0->field_8 = 0;
    arg0->field_4 = 0;
    arg0->field_8 = 0;
}

void Pad_UpdateButtons(Rec230DC *p, u8 *buf) {
    s32 n;

    p->field_8 = p->field_4;
    p->field_4 = ((buf[2] << 8) + buf[3]) ^ 0xFFFF;
    p->field_0 = (p->field_8 ^ p->field_4) & p->field_4;
    if (p->field_8 != p->field_4) {
        p->field_10 = p->field_0;
        p->field_14 = 0;
        p->field_15 = 0;
        return;
    }
    n = ++p->field_15;
    if (p->field_14 == 0) {
        if (n >= 11) {
            goto rep;
        }
    } else if (n >= 4) {
    rep:
        p->field_14 = 1;
        p->field_15 = 0;
        p->field_10 = p->field_4;
        return;
    }
    p->field_10 = 0;
}

void Pad_PollPort(Elm6A8 *a0, s32 i) {
    switch (PadGetState(i << 4)) {
    case 2:
    case 6:
        switch (D_8005F678[i].field_C) {
        case 0:
        default:
            Pad_ResetButtons((Rec230DC *)&D_8005F678[i]);
            D_8005F678[i].field_C = 1;
            break;
        case 1:
            Pad_UpdateButtons(&D_8005F678[i], a0);
            break;
        }
        break;
    case 0:
    default:
        D_8005F678[i].field_C = 0;
        break;
    }
}

s32 Pad_GetButtonState(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    if (arg0 & arg2) {
        r = 1;
    } else if (arg1 & arg2) {
        r = -1;
    }
    return r;
}

void Pad_Update(void) {
    s32 i;
    Elm6A8 *a8 = (Elm6A8 *)D_8005F6A8;

    for (i = 0; i < 2; i++) {
        if (a8[i].field_0 != 0) {
            D_8005F678[i].field_C = 0;
            D_8005F678[i].field_4 = 0;
            D_8005F678[i].field_0 = 0;
            D_8005F678[i].field_10 = 0;
            D_8005F6F0[i].field_3E = 0;
        } else if ((a8[i].field_1 >> 4) == 4) {
            Pad_PollPort(&a8[i], i);
            D_8005F6F0[i].field_3E = 1;
        } else {
            D_8005F678[i].field_4 = 0;
            D_8005F678[i].field_0 = 0;
            D_8005F678[i].field_10 = 0;
            D_8005F6F0[i].field_3E = 0;
        }
        D_8005F6F0[i].field_8 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x1000);
        D_8005F6F0[i].field_C = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x4000);
        D_8005F6F0[i].field_0 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x2000);
        D_8005F6F0[i].field_4 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x8000);
        D_8005F6F0[i].field_10 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x20);
        D_8005F6F0[i].field_14 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x40);
        D_8005F6F0[i].field_1C = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x10);
        D_8005F6F0[i].field_18 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x80);
        D_8005F6F0[i].field_28 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x4);
        D_8005F6F0[i].field_2C = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x1);
        D_8005F6F0[i].field_20 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x8);
        D_8005F6F0[i].field_24 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x2);
        D_8005F6F0[i].field_30 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x100);
        D_8005F6F0[i].field_34 = Pad_GetButtonState(D_8005F678[i].field_0, D_8005F678[i].field_4, 0x800);
        D_8005F6F0[i].field_38 = D_8005F678[i].field_4;
        D_8005F6F0[i].field_3A = D_8005F678[i].field_0;
        D_8005F6F0[i].field_3C = D_8005F678[i].field_10;
    }
}

void Sys_VSyncHandler(void) {
    s32 t = ((Db5F770 *)&D_8005F770)->field_4 - (((Db5F770 *)&D_8005F770)->field_4 != 0);

    if (D_8005078C != 0 && D_8005072C >= t) {
        ((Db5F770 *)&D_8005F770)->field_28 = (((Db5F770 *)&D_8005F770)->field_28 == 0);
        PutDispEnv(&((Db5F770 *)&D_8005F770)->disp[((Db5F770 *)&D_8005F770)->field_28]);
        PutDrawEnv(&((Db5F770 *)&D_8005F770)->draw[((Db5F770 *)&D_8005F770)->field_28]);
        Gpu_DrawOt(((Db5F770 *)&D_8005F770)->field_28 ^ 1);
        D_8005078C = 0;
        D_8005072C = 0;
    } else {
        D_8005072C++;
    }
    SsSeqCalledTbyT();
}


void Sys_Main(void) {
    Rect23550 r;
    TimInfo2BBD4 tim;
    u8 buf;
    s32 slot;
    s32 i;
    s32 t;
    s32 d;
    s32 u;

    func_80010D74();
    ResetCallback();
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    VSyncCallback((s32)Sys_VSyncHandler);
    r.x = 0;
    r.y = 0;
    r.w = 0x280;
    r.h = 0x1FF;
    ClearImage((s32)&r, 0, 0, 0);
    DrawSync(0);
    GsInitGraph(0x140, 0xF0, 1, 1, 0);
    func_8002B4C4();
    SsInit();
    func_8002CE5C();
    Gpu_InitDoubleBuffer(0x140, 0x280, 1, 0);
    PutDrawEnv(&((Db5F770 *)&D_8005F770)->draw[0]);
    PutDispEnv(&((Db5F770 *)&D_8005F770)->disp[0]);
    VSync(0);
    GsGetTimInfo((u32 *)(D_80010000[0] + 4), &tim);
    VSync(0);
    LoadImage((s32)&D_80050730, (s32)tim.paddr);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);
    CdInit();
    CdSetDebug(0);
    SetGraphDebug(0);
    Mem_InitHeap(D_800506F8[0], 0x801FF000 - (s32)D_800506F8[0]);
    Cd_ClearFileCache();
    Snd_Init();
    D_8005F770.field_0 = 0;
    ((Db5F770 *)&D_8005F770)->field_4 = 0;
    D_8005F770.field_28 = 1;
    Gpu_FreePrimBufs();
    func_8001C800(0);
    Gpu_SetLayerOtPtrs();
    Rand_Seed(0);
    ((void (*)(s32))func_8003D4A4)(0);
    MemCardStart();
    Pad_Init();
    buf = 0x80;
    while (((s32 (*)(s32, u8 *, s32))CdControl)(0xE, &buf, 0) == 0) {
    }
    VSync(3);
    CdControlB(9, 0, 0);
    Task_ClearList();
    Gfx_InitTexSlots();
    Gpu_ClearOt(0);
    Gpu_ClearOt(1);
    D_8005F770.field_0 = 1;
    D_8005F770.field_18 = 0x402;
    D_8005F770.field_1C = 0x402;
    ((Db5F770 *)&D_8005F770)->field_24 = 0;
    D_8005F770.field_C = 0;
    func_80022468();
    D_8005071C->field_0 = 0;
    Gfx_FadeSetBlack();
    Gfx_DrawFade();
    slot = 0;
    for (;;) {
        if (slot == 0) {
            Task_ClearList();
            Gpu_FreePrimBufs();
            Mem_FreeTag(2);
            Gpu_ClearOt(0);
            Gpu_ClearOt(1);
            t = D_8005F770.field_18;
            u = D_8005F770.field_1C;
            D_8005F770.field_1C = 0;
            D_8005F770.field_20 = t;
            D_8005F770.field_18 = u;
            for (i = 0; i < 0x11; i++) {
                Flag_Set(i, 0);
            }
            Task_Create(1, &slot, 0);
        }
        Gfx_DrawFade();
        D_8005F770.field_14 = 0;
        slot = Task_TryRun((void *)slot);
        D_8005F770.field_14 = 1;
        slot = Task_TryRun((void *)slot);
        Gpu_SkipEmptyOtEntries(D_8005F770.field_28);
        DrawSync(0);
        D_8005078C = 1;
        while (*(volatile s32 *)&D_8005078C != 0) {
        }
        Gpu_ResetPrimBuf();
        Gpu_SetLayerOtPtrs();
        Gpu_ClearOt(D_8005F770.field_28);
        t = VSync(-1);
        u = D_80050738;
        D_80050738 = t;
        d = t - u;
        D_8005F770.field_8 = d;
        D_8005E620.field_4 += d;
        if (d > 6) {
            D_8005F770.field_8 = 6;
        }
        D_8005F770.field_0++;
        Pad_Update();
        Rand_Step();
        Cd_ServiceQueue();
        Snd_ServiceSlotLoads();
    }
}


void Rand_Seed(s32 a0) {
    D_80050790 = a0 & 0xFFF;
}


void Rand_Step(void) {
    D_80050790 = (D_80050790 + 1) & 0xFFF;
}


s32 Rand_Next(void) {
    Rand_Step();
    return D_80041704[D_80050790];
}


u16 Rand_GetAt(u32 arg0) {
    return D_80041704[arg0 & 0xFFF];
}

void func_80023964(void) {
    D_8005F774 = 0;
}

void func_80023970(void) {
    D_8005F774 = 2;
}

void func_80023980(void) {
    D_8005F774 = 3;
}

void func_80023990(void) {
    D_8005F774 = 4;
}

EntA0 *Cd_GetFileEntry(u32 arg0) {
    u32 index;
    u8 *base;
    if (arg0 == 0) {
        return 0;
    }
    index = arg0 & 0xFFFF;
    base = (u8 *)Cd_GetFileSync(arg0 >> 16);
    return (EntA0 *)(((u32 *)base)[index] + (u32)base);
}

s32 Mem_GetOffsetEntry(s32 arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg1[(u16)arg0] + (s32)arg1;
}

s32 Cd_GetFileOrNull(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return Cd_GetFileSync(arg0);
}

void Cd_ClearFileCache(void) {
    s32 i;
    Ent23A78 *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        p->field_4 = 0;
        p->field_C = 0;
        p->field_0 = 0;
        p->field_2 = 0;
        p->field_8 = 0;
    }
}

Ent23A78 *Cd_FindCachedFile(arg0)
s32 arg0;
{
    s32 i;
    Ent23A78 *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == arg0) return p;
    }
    return NULL;
}

Ent23A78 *Cd_FindFreeCacheSlot(void) {
    s32 i;
    Ent23A78 *p = D_8005F8C8;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == 0) return p;
    }
    return NULL;
}

Ent23AE8 *Cd_FindLruCachedFile(void) {
    s32 min = D_8005F770.field_0;
    Ent23A78 *p = D_8005F8C8;
    Ent23A78 *best = 0;
    s32 i;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == 0) continue;
        if (p->field_2 != 0) continue;
        if (p->field_0 != 3) continue;
        if (min < p->field_8) continue;
        min = p->field_8;
        best = p;
    }
    return (Ent23AE8 *)best;
}

s32 Cd_GetFileState(s32 arg0) {
    Ent23A78 *e = Cd_FindCachedFile(arg0);

    if (e != 0) {
        e->field_8 = D_8005F770.field_0;
        return e->field_0;
    }
    return 0;
}

void Cd_EvictLruFile(void) {
    Ent23AE8 *p = Cd_FindLruCachedFile();
    Mem_Free(p->field_C);
    p->field_4 = 0;
    p->field_C = 0;
    p->field_8 = 0;
    p->field_0 = 0;
    p->field_2 = 0;
}

void Cd_QueueFile(s32 id) {
    Ent23A78 *p = Cd_FindCachedFile(id);

    if (p != NULL) {
        p->field_8 = D_8005F770.field_0;
        return;
    }
    p = Cd_FindFreeCacheSlot();
    p->field_4 = id;
    p->field_C = Mem_Alloc(Cd_GetFileSectors(id) << 11, 3);
    p->field_0 = 1;
    p->field_8 = 0;
    D_80050750 = 1;
}


void Cd_ServiceQueue(void) {
    s32 started;
    s32 busy;
    s32 i;
    Ent23A78 *p;

    if (D_80050750 == 0) {
        return;
    }
    if (Cd_PollRead() != 0) {
        return;
    }
    p = D_8005F8C8;
    started = 0;
    busy = 0;
    for (i = 0; i < 0x50; i++, p++) {
        if (p->field_4 == 0) {
            continue;
        }
        if (p->field_0 != 1) {
            if (p->field_0 == 2) {
                p->field_0 = 3;
                p->field_8 = D_8005F770.field_0;
                busy = 1;
            }
        } else {
            busy = 1;
            if (started == 0) {
                Cd_ReadFileAsync(p->field_4, p->field_C);
                p->field_0 = 2;
                p->field_8 = D_8005F770.field_0;
                started = busy;
            }
        }
    }
    if (busy == 0) {
        D_80050750 = 0;
    }
}


void Cd_LoadFileSync(s32 arg0) {
    Cd_QueueFile(arg0);
    do {
        Cd_ServiceQueue();
    } while (Cd_GetFileState(arg0) != 3);
}

s32 Cd_GetFileSync(s32 arg0) {
    Ent23A78 *p = Cd_FindCachedFile(arg0);
    if (p != 0 && p->field_0 == 3) {
        p->field_8 = D_8005F770.field_0;
    } else {
        while (Cd_PollRead() != 0) {
        }
        Cd_LoadFileSync(arg0);
    }
    return Cd_FindCachedFile(arg0)->field_C;
}

void Cd_FreeFile(void) {
    Ent23A78 *p = Cd_FindCachedFile();
    if (p != 0) {
        if (p->field_0 == 3) {
            Mem_Free(p->field_C);
            p->field_4 = 0;
            p->field_C = 0;
            p->field_8 = 0;
            p->field_0 = 0;
        }
    }
}

void Cd_LockFile(s32 a0) {
    Ent23A78 *p = Cd_FindCachedFile();
    if (p != 0) {
        if (p->field_0 == 3) {
            p->field_2 = 1;
        }
    }
}

void Cd_UnlockFile(s32 a0) {
    Ent23A78 *p = Cd_FindCachedFile();
    if (p != 0) {
        if (p->field_0 == 3) {
            p->field_2 = 0;
        }
    }
}

void Cd_FreeUnlockedFiles(void) {
    s32 i;
    for (i = 0; i < 0x50; i++) {
        if (D_8005F8C8[i].field_4 != 0 && D_8005F8C8[i].field_2 == 0) {
            Mem_Free(D_8005F8C8[i].field_C);
            D_8005F8C8[i].field_4 = 0;
            D_8005F8C8[i].field_C = 0;
            D_8005F8C8[i].field_8 = 0;
            D_8005F8C8[i].field_0 = 0;
        }
    }
}

s32 Cd_IsFileValid(s32 arg0) {
    return Cd_FileLba[arg0] != 0;
}

s32 Cd_GetFileSectors(s32 arg0) {
    return Cd_FileSectors[arg0];
}

s32 Cd_GetFileLba(s32 arg0) {
    return Cd_FileLba[arg0];
}

void Cd_GetFilePos(s32 arg0, void *arg1) {
    CdIntToPos(Cd_FileLba[arg0]);
}

s32 Cd_CheckNextSector(void) {
    s32 x;
    CdGetSector(D_8005FDC8, 3);
    x = CdPosToInt(D_8005FDC8);
    if (x == D_80048DB8.field_1C) {
        D_80048DB8.field_1C = x + 1;
        return 0;
    }
    return -1;
}

void Cd_ReadSectorCallback(s32 a0) {
    if (a0 == 1 && Cd_CheckNextSector() == 0) {
        CdGetSector((void *)D_80048DB8.field_8, 0x200);
        D_80048DB8.field_8 += 0x800;
        D_80048DB8.field_4 -= 1;
        if (D_80048DB8.field_4 != 0) {
            return;
        }
    } else {
        D_80048DB8.field_4 = -1;
    }
    CdReadyCallback(0);
    CdControlF(9, 0);
}

void Cd_ReadSyncCallback(s32 ev) {
    if (ev == 5) {
        if (D_80048DB8.field_0 == 4) {
            CdControlF(9, 0);
        } else {
            D_80048DB8.field_0 = 0;
            D_80048DB8.field_4 = D_80048DB8.field_10;
            Cd_ReadFileAsync(D_80048DB8.field_14, D_80048DB8.field_18);
        }
    } else if (ev == 2) {
        switch (D_80048DB8.field_0) {
        case 1:
            D_80048DB8.field_C = 0xA0;
            CdControlF(14, &D_80048DB8.field_C);
            D_80048DB8.field_0++;
            break;
        case 2:
            CdReadyCallback((s32)Cd_ReadSectorCallback);
            CdControlF(6, 0);
            D_80048DB8.field_0++;
            break;
        case 3:
            D_80048DB8.field_0 = 4;
            break;
        case 4:
            if (D_80048DB8.field_4 == 0) {
                D_80048DB8.field_0 = 5;
                CdSyncCallback(0);
            } else {
                D_80048DB8.field_0 = 0;
                D_80048DB8.field_4 = D_80048DB8.field_10;
                Cd_ReadFileAsync(D_80048DB8.field_14, D_80048DB8.field_18);
            }
            break;
        }
    }
}

s32 Cd_PollRead(void) {
    switch (D_80048DB8.field_0) {
    case 0:
        return 0;
    case 5:
        D_80048DB8.field_0 = 0;
        return 2;
    }
    return 1;
}

void Cd_ReadFileAsync(s32 arg0, s32 arg1) {
    u8 sp10[8];
    s32 r;

    if (D_80048DB8.field_0 != 0) {
        while (Cd_PollRead() != 0) {}
    }
    Cd_GetFilePos(arg0, sp10);
    r = Cd_GetFileSectors(arg0);
    D_80048DB8.field_4 = r;
    D_80048DB8.field_8 = arg1;
    D_80048DB8.field_10 = r;
    D_80048DB8.field_14 = arg0;
    D_80048DB8.field_18 = arg1;
    D_80048DB8.field_1C = Cd_GetFileLba(arg0);
    D_80048DB8.field_0 += 1;
    CdSyncCallback(Cd_ReadSyncCallback);
    CdControlF(2, sp10);
}

void func_80024310(Actor *arg0, Block1C *arg1) {
    *(Block1C *)arg0->work = *arg1;
}

void func_80024350(Actor *arg0) {
    ActorWork *work = arg0->work;

    switch (arg0->field_10) {
    case 0:
        Actor_InitTransform((ContC40 *)arg0, &work->field_8, work->field_14);
        Gfx_AttachModel(arg0, work->field_0)->field_3C = 3;
        Anim_SetModelAnimFile(arg0, 0, work->field_4);
        Task_NextState0(arg0);
        break;
    case 1: {
        Sub3C *s = arg0->field_3C;
        if (arg0->field_28 < work->field_18 && s->field_60 >= 0)
            break;
        Task_SetState0(arg0, 3);
        break;
    }
    case 2:
        break;
    }
}

void func_80024410(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->field_10 == 1) {
        Gfx_AttachModel(arg0, w->field_0);
        Anim_StepModelAnim(arg0);
        Actor_UpdateTransform(arg0);
        Gfx_CalcModelBoneMatrices(arg0);
        Gfx_DrawTexModel(arg0, 0);
    }
}

u8 PadGetState(void) {
    Obj25FBC *o = D_80048E2C();

    if (o->field_37 != 0 || o->field_38 != 0 || (o != o->field_10 && o->field_39 != 0)
        || *o->field_30 != 0) {
        switch (o->field_49) {
        case 3:
            return 1;
        case 2:
            return 1;
        case 6:
            return 4;
        }
    }
    return o->field_49;
}

void PadStartCom(void) {
    State60058 *p = &D_80060058;

    D_80048E50 = 0;
    EnterCriticalSection();
    SysDeqIntRP(2, D_80048E78);
    SysEnqIntRP(2, D_80048E78);
    D_80048DF0->field_0 = -2;
    D_80048DF0->field_4 |= 1;
    ChangeClearRCnt(3, 0);
    ExitCriticalSection();
    D_80048E1C(D_80048E4C);
    D_80048E1C(&D_80048E4C[1]);
    p->field_4 = 0;
    p->field_0 = 0;
    D_80048E50 = 1;
}

void PadStopCom(void) {
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, D_80048E78);
    ExitCriticalSection();
}

void PadInitDirect(u8 *a0, u8 *a1) {
    Obj25FBC *base;
    Obj25FBC *p;
    u8 *q;
    s32 i;
    s32 j;

    D_80048E50 = 0;
    D_80048E64 = 0;
    Pad_InitDriverHooks();
    base = D_80048E4C;
    base[0].field_30 = a0;
    base[1].field_30 = a1;
    p = base;
    for (i = 0; i < 2; i++, p++) {
        q = p->field_5D;
        p->field_C = 0;
        p->field_10 = p;
        p->field_30[0] = 0xFF;
        p->field_30[1] = 0;
        for (j = 5; j >= 0; j--) {
            *q++ = 0xFF;
        }
    }
    D_80048E50 = 1;
}


void Pad_InitDriverHooks(void) {
    Obj25FBC *o = (Obj25FBC *)D_8005FDD8;

    bzero((u8 *)o, 0x1E0);
    o[0].field_3C = D_8005FFB8;
    o[0].field_40 = D_80060000;
    o[1].field_3C = &D_8005FFB8[0x23];
    D_80048E18 = func_8002485C;
    D_80048E1C = Pad_ResetPortState;
    D_80048E20 = func_80024960;
    D_80048E24 = (void (*)(Ent266D0 *))Pad_AllocActPower;
    D_80048E2C = (Obj25FBC *(*)(void))Pad_GetPortBlock;
    D_80048E3C = func_80024950;
    D_80048E30 = func_80024CB8;
    D_80048E34 = (s32 (*)(void))func_80025114;
    D_80048E4C = o;
    o[1].field_40 = &D_80060000[0x23];
    D_80048E38 = func_80024DC8;
}

void Pad_ResetPortState(Obj25FBC *a0) {
    u8 *p;
    s32 k;
    u8 c;

    if (a0->field_49 != 0) {
        p = a0->field_5D;
        c = 0xFF;
        k = 5;
        a0->field_49 = 0;
        a0->field_46 = 0;
        a0->field_E6 = 0;
        a0->field_14 = 0;
        a0->field_18 = 0;
        a0->field_E3 = 0;
        a0->field_E4 = 0;
        a0->field_E6 = 0;
        a0->field_E9 = 0;
        a0->field_EA = 0;
        a0->field_0 = 0;
        a0->field_4 = 0;
        a0->field_8 = 0;
        do {
            *p = c;
            k--;
            p++;
        } while (k >= 0);
    }
}

void func_8002485C(s32 code) {
    Obj25FBC *o;
    s32 done;

    do {
        o = &((Obj25FBC *)D_8005FDD8)[D_80048E58];
        if (code != -9) {
            if (code == 0) {
                *(D_80048E70 + D_80048E58) = 0;
            } else {
                func_80025034(o);
                func_80024950((Actor *)o);
            }
        }
        D_80048E5C = 0;
        D_80048E00->field_A = 0;
        D_80048E58++;
        if (D_80048E58 <= D_80048E6C) {
            done = func_8002533C(&((Obj25FBC *)D_8005FDD8)[D_80048E58]);
        } else {
            done = 1;
        }
        code = 0xFFFF;
    } while (done == 0);
}


s32 func_80024950(Actor *arg0) {
    s32 tmp = arg0->u34.b.field_37;
    arg0->u34.b.field_37 = 0;
    arg0->u38.field_38 = tmp;
    return tmp;
}

s32 func_80024960(Ent266D0 *e, s32 a1) {
    Obj25FBC *a0 = (Obj25FBC *)e;
    s32 i = a0->field_45 - 3;

    switch (a0->field_37) {
    case 0:
        if (i < 6 && a0->field_57[i] == 0) {
            return 0;
        }
        if (i < a0->field_34) {
            return a0->field_28[i];
        }
        return 0;
    case 0x4D:
        if (i < a0->field_36) {
            return a0->field_2C[i];
        }
        return 0xFF;
    default:
        if (i < a0->field_36) {
            return a0->field_2C[i];
        }
        return 0;
    }
}


void Pad_AllocActPower(Obj25FBC *a0) {
    s32 n;
    s32 i;
    s32 j;
    s32 found;
    s32 mask;
    s32 s;
    u8 *p;
    u8 *q;

    bzero(a0->field_57, 6);
    if (a0->field_E6 != 0 && a0->field_28 != 0) {
        n = 6;
        if (a0->field_34 < 7) {
            n = a0->field_34;
        }
        for (i = 0; i < a0->field_E9; i++) {
            found = 0;
            mask = 1;
            if (a0->field_4[i].field_2 != 0) {
                mask = 0xFF;
            }
            p = a0->field_5D;
            q = a0->field_28;
            for (j = 0; j < n; p++, j++, q++) {
                if (*p == i && (*q & mask)) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                s = D_80048E60 + a0->field_4[i].field_3;
                if (s < 0x3D) {
                    D_80048E60 = s;
                } else {
                    found = 0;
                }
                if (found) {
                    p = a0->field_5D;
                    q = a0->field_57;
                    for (j = 0; j < n; j++, q++) {
                        if (*p++ == i) {
                            *q = 1;
                        }
                    }
                }
            }
        }
        return;
    }
    if ((a0->field_E8 - 4U < 2 || a0->field_E8 == 7) && a0->field_E6 == 0 && a0->field_34 >= 2) {
        if ((a0->field_28[0] & 0xC0) == 0x40 && (a0->field_28[1] & 1) && D_80048E60 + 10 < 0x3D) {
            a0->field_57[1] = 1;
            a0->field_57[0] = 1;
            D_80048E60 += 10;
        }
        return;
    }
    if (*(volatile u8 *)&a0->field_E8 == 3) {
        a0->field_57[0] = 1;
        return;
    }
    if (a0->field_E6 == 0) {
        for (i = 0; i < 6; i++) {
            a0->field_57[i] = 1;
        }
    }
}

u8 *Pad_GetPortBlock(s32 arg0) {
    u8 *p = D_8005FDD8;

    if (arg0 & 0xF0) {
        p += 0xF0;
    }
    return p;
}

s32 func_80024CB8(Obj25FBC *a0) {
    if (*a0->field_3C == 0xF3) {
        if (a0->field_E8 == 0) {
            Pad_CmdConfigMode((Actor *)a0, 0);
            return 0;
        }
        if (a0->field_46 == 0xFF) {
            goto stop;
        }
        if (a0->field_49 == 2) {
            D_80048E1C(a0);
        }
    }
    switch (a0->field_46) {
    case 1:
        Pad_CmdConfigMode((Actor *)a0, 1);
        break;
    case 0xFE:
    stop:
        Pad_CmdConfigMode((Actor *)a0, 0);
        break;
    case 0:
    case 0xFF:
        break;
    default:
        if (a0->field_14 != 0) {
            a0->field_14(a0);
        } else {
            Pad_SendInfoCmd(a0);
        }
        break;
    }
    return 0;
}

void func_80024DC8(Obj25FBC *a0) {
    s32 old;
    s32 i;
    s32 r;

    if (!(*a0->field_3C & 0xF0)) {
        a0->field_30[0] = 0xFF;
        a0->field_30[1] = 0;
        a0->field_E8 = 0;
        a0->field_35 = 0;
        D_80048E1C(a0);
        return;
    }
    old = a0->field_E8;
    a0->field_E8 = *a0->field_3C >> 4;
    if (a0->field_E8 == 0xF) {
        a0->field_E8 = old;
    } else {
        a0->field_30[0] = 0;
        a0->field_30[1] = a0->field_3C[0];
        a0->field_35 = a0->field_44;
        for (i = 2; i < a0->field_44; i++) {
            a0->field_30[i] = a0->field_3C[i];
        }
    }
    if ((a0->field_3C[1] == 0 && (a0->field_46 != 1 || a0->field_14 != 0) && a0->field_50 == 0)
        || a0->field_E8 != old) {
        D_80048E1C(a0);
    }

    a0->field_4A = 0;
    if (a0->field_46 == 0xFF) {
        return;
    }
    if (a0->field_46 != 0 && a0->field_37 == 0) {
        return;
    }
    if ((u8)(a0->field_46 - 2) < 0xFC && *a0->field_3C != 0xF3) {
        D_80048E1C(a0);
        return;
    }
    switch (a0->field_46) {
    case 0:
        a0->field_49 = 1;
        a0->field_46++;
        break;
    case 1:
        a0->field_47 = 0;
        a0->field_46++;
        break;
    case 0xFE:
        a0->field_46 = 0xFF;
        break;
    default:
        if (a0->field_18 != 0) {
            a0->field_46 += a0->field_18(a0);
        } else {
            a0->field_46 += Pad_ParseInfoReply(a0);
        }
        break;
    }
}

void func_80025034(Obj25FBC *a0) {
    a0->field_4C++;
    if (a0->field_46 != 0) {
        if (a0->field_46 == 1) {
            if (a0->field_4A < 11) {
                a0->field_4A++;
                return;
            }
            a0->field_49 = 2;
            a0->field_46 = 0xFF;
            return;
        }
        if (a0->field_4A < 11) {
            a0->field_4A++;
            return;
        }
        if (a0->field_49 != 0) {
            D_80048E1C(a0);
        }
    }
    if (*a0->field_3C != 0xF3) {
        a0->field_30[0] = 0xFF;
        a0->field_30[1] = 0;
        a0->field_E8 = 0;
        a0->field_35 = 0;
    }
}

s32 func_80025114(Obj25FBC *p) {
    if (p->field_E6 != 0 && p->field_46 == 0xFF) {
        return 0;
    }
    return 1;
}

s32 Pad_VBlankIrqVerify(void) {
    if (!(Pad_IntrRegs->field_4 & 1)) {
        return 0;
    }
    if (!(Pad_IntrRegs->field_0 & 1)) {
        return 0;
    }
    if (D_80048E40 != 0) {
        D_80048E40();
    }
    return 1;
}

s32 func_800251AC(void) {
    if (Pad_SioRegs->field_A & 2) {
        Pad_SioRegs->field_A = 0;
    } else {
        s32 a = D_80048E68;

        D_80048E88 = 1;
        if (a != 0 && D_80060058.field_0 < 150) {
            D_80060058.field_0++;
        }
        if (D_80048E6C == 0 && D_80060058.field_4 < 150) {
            D_80060058.field_4++;
        }
        if (D_80048E50 != 0 && D_80048E68 <= D_80048E6C) {
            D_80048E5C = 0;
            D_80048E58 = D_80048E68;
            if (func_8002533C(&D_80048E4C[D_80048E68]) == 0) {
                D_80048E18(0xFFFF);
            }
            D_80048E60 = 0;
            while (D_80048E58 <= D_80048E6C) {
                Pad_SioRunStep(&D_80048E4C[D_80048E58]);
            }
            Pad_SioRegs->field_E = 0x88;
        }
    }
    return 0;
}

s32 func_8002533C(Obj25FBC *a0) {
    Stat48E90 *st;
    s32 *tbl;
    s32 *q;
    s32 *p;
    s32 n;

    st = Pad_SioRegs;
    *(volatile u16 *)&st->field_A = 0x40;
    *(volatile u16 *)&st->field_A = 0;
    *(volatile u16 *)&st->field_8 = 0xD;
    *(volatile u16 *)&st->field_E = 0x88;
    Pad_SetTimeout(a0->field_E8 == 8 ? 0x50 : 0x91);
    Pad_SioRegs->field_A = D_80048E58 ? 0x3003 : 0x1003;
    n = D_80048E70[D_80048E58];
    tbl = D_80048E70;
    if (n >= 0) {
        if (n > 0) {
            do {
                p = tbl;
                D_80048E38(&a0->field_C[--p[D_80048E58]]);
            } while (p[D_80048E58] > 0);
        }
        q = &D_80048E70[D_80048E58];
        if (*q == 0) {
            void (*fp)(Obj25FBC *);
            fp = D_80048E38;
            *q = -1;
            fp(a0);
            D_80048E3C((Actor *)a0);
        }
    }
    st = Pad_SioRegs;
    if (st->field_4 & 0x200) {
        *(volatile u16 *)&st->field_A |= 0x10;
        if (st->field_4 & 0x200) {
            do {
            } while (Pad_IsTimedOut() == 0);
            Pad_SioRegs->field_0 = 1;
            Pad_SetTimeout(0x7D0);
            if (func_80025C00() == 0) {
                return 0;
            }
            Pad_WaitSioRx();
            Pad_SioRegs->field_0;
            Pad_SetTimeout(0x1AE);
            while (!(Pad_IntrRegs->field_0 & 0x80)) {
                if (Pad_IsTimedOut() != 0) {
                    return 0;
                }
            }
            Pad_SioRegs->field_0 = 0x42;
            Pad_SetTimeout(0x3C);
            if (func_80025C00() == 0) {
                return 0;
            }
            Pad_WaitSioRx();
            Pad_SioRegs->field_0;
            Pad_SetTimeout(0x1AE);
            while (!(Pad_IntrRegs->field_0 & 0x80)) {
                if (Pad_IsTimedOut() != 0) {
                    return 0;
                }
            }
            Pad_SioRegs->field_0 = 1;
            Pad_SetTimeout(0x3C);
            if (func_80025C00() == 0) {
                return 0;
            }
            Pad_WaitSioRx();
            Pad_SioRegs->field_0;
            return 0;
        }
        Pad_IntrRegs->field_0 = -0x81;
    }
    if (a0->field_50 != 0 && a0->field_37 != 0) {
        return 0;
    }
    return 1;
}


void Pad_SioRunStep(Obj25FBC *a0) {
    s32 r;

    r = D_80048EA0[D_80048E5C++](a0);
    if (r >= 0) {
        if (D_80048E5C != 0) {
            if (D_80048E5C != 3 || *a0->field_3C != 0x80) {
                Pad_SetTimeout(0x3C);
                if (func_80025C00() == 0) {
                    D_80048E18(-3);
                }
            }
        }
        if (D_80048E5C >= 5) {
            D_80048E5C--;
        }
    } else {
        D_80048E18(r);
    }
}

s32 func_80025760(Ent266D0 *a0, s32 a1) {
    s32 r;
    s32 v;
    s32 t;

    if (a1 < 0) {
        r = Pad_SioRegs->field_0;
        a0->field_44 = 0xFF;
        a0->field_45 = 1;
        *a0->field_40 = ~a1;
        while (!(Pad_SioRegs->field_4 & 1)) {
        }
        while (Pad_IsTimedOut() == 0) {
        }
        Pad_SioRegs->field_0 = ~a1;
    } else {
        v = 0x88;
        t = *a0->field_3C;
        if ((t >> 4) == 8 && a0->field_44 >= 9) {
            v = 0x22;
        }
        D_80060050 = 0x1AE;
        D_8006004C = *(volatile u16 *)0x1F801120;
        D_80060054 = *(volatile u16 *)0x1F801124;
        while (!(Pad_SioRegs->field_4 & 2)) {
        }
        r = Pad_SioRegs->field_0;
        Pad_SioRegs->field_E = v;
        while (!(Pad_IntrRegs->field_0 & 0x80)) {
            if (Pad_IsTimedOut() != 0) {
                return -0x14;
            }
        }
        Pad_SioRegs->field_0 = a1;
        if (v == 0x22) {
            Pad_IntrRegs->field_0 = -0x81;
            Pad_SioRegs->field_A |= 0x10;
        }
        a0->field_45++;
        a0->field_3C[a0->field_44] = r;
        a0->field_44++;
    }
    return r;
}


s32 Pad_SioExchangeByte(Ent266D0 *a0, s32 a1) {
    s32 v;
    s32 r;
    s32 t;
    s32 d;
    s32 base;
    s32 lim;
    Regs48E8C *p;

    d = *a0->field_3C;
    if ((d >> 4) == 8 && a0->field_44 >= 9) {
        v = 0x22;
    } else {
        v = 0x88;
    }
    while (!(Pad_SioRegs->field_4 & 2)) {
    }
    Pad_SetTimeout(0x190);
    r = Pad_SioRegs->field_0;
    if (a0->field_44 != 0 || (r >> 4) != 8) {
        *(volatile u16 *)&Pad_SioRegs->field_E = v;
    } else {
        Pad_SioRegs->field_E = 0x22;
    }
    if (!(Pad_IntrRegs->field_0 & 0x80)) {
        base = D_8006004C;
        lim = D_80060050;
        do {
            *(volatile u16 *)0x1F801124;
            t = *(volatile u16 *)0x1F801120;
            if (t < base) {
                if (*(volatile u16 *)0x1F801128 != 0) {
                    t += *(volatile u16 *)0x1F801128;
                } else {
                    t += 0x10000;
                }
            }
            if (*(volatile u16 *)0x1F801124 & 0x200) {
                if (t - base >= lim) {
                    return -2;
                }
            } else if (((t - base) >> 3) >= lim) {
                return -2;
            }
        } while (!(Pad_IntrRegs->field_0 & 0x80));
    }
    if (((Slot267F0 *)a0)->field_E8 != 8 && D_80048E5C == 2) {
        Pad_SetTimeout(0x3C);
        while (Pad_IsTimedOut() == 0) {
        }
    }
    Pad_SioRegs->field_0 = a1;
    if (D_80048E5C == 3 && r == 0x80) {
        Pad_IntrRegs->field_0 = -0x81;
        Pad_SioRegs->field_A |= 0x10;
    }
    a0->field_45++;
    if (a0->field_44 != 0xFF) {
        (*(u8 * volatile *)&a0->field_3C)[*(volatile u8 *)&a0->field_44] = r;
    }
    a0->field_44++;
    return r;
}


s32 func_80025C00(void) {
    Regs48E8C *q = Pad_IntrRegs;
    Stat48E90 *st = Pad_SioRegs;

    q->field_0 = -0x81;
    if (st->field_4 & 0x80) {
        do {
            if (Pad_IsTimedOut() != 0) {
                return 0;
            }
        } while (Pad_SioRegs->field_4 & 0x80);
    }
    Pad_SioRegs->field_A |= 0x10;
    return 1;
}

void Pad_WaitSioRx(void) {
    while (!(Pad_SioRegs->field_4 & 2)) {
    }
}

void Pad_SetCmd(Actor *arg0, u8 arg1, ActorWork *arg2, u8 arg3) {
    arg0->u34.b.field_37 = arg1;
    arg0->work = arg2;
    arg0->u34.b.field_36 = arg3;
}

void Pad_SendInfoCmd(Obj25FBC *a0) {
    switch (a0->field_46) {
    case 2:
        Pad_CmdQueryModel((Actor *)a0);
        break;
    case 3:
        Pad_CmdQueryMode((Actor *)a0, a0->field_E4);
        break;
    case 4:
        Pad_CmdQueryComb((Actor *)a0, a0->field_47);
        break;
    }
}

s32 Pad_ParseInfoReply(Obj25FBC *a0) {
    u8 *p;
    s32 v;

    switch (a0->field_46) {

    case 2:
        p = *(u8 *volatile *)&a0->field_3C;
        if (p[7] != 0) {
            goto ret0;
        }
        if (a0->field_E3 == p[3] && a0->field_E4 == p[4] && a0->field_E9 == p[5] && a0->field_EA == p[6]) {
            a0->field_EE = 0;
        } else {
            a0->field_EE = 0xFFFF;
        }
        a0->field_E3 = (*(u8 *volatile *)&a0->field_3C)[3];
        a0->field_E4 = (*(u8 *volatile *)&a0->field_3C)[4];
        a0->field_E6 = 0;
        a0->field_E9 = (*(u8 *volatile *)&a0->field_3C)[5];
        a0->field_EA = (*(u8 *volatile *)&a0->field_3C)[6];
        a0->field_EC = 0;
        if (a0->field_EE != 0) {
            goto ret0;
        }
        a0->field_EB = 0;
        break;

    case 3:
        p = *(u8 *volatile *)&a0->field_3C;
        if (p[2] != 0) {
            goto ret0;
        }
        if (p[3] != 0) {
            goto ret0;
        }
        v = p[5] + (p[4] << 8);
        a0->field_E6 = v;
        if (a0->field_EE != (u16)v) {
            a0->field_EE = v;
        ret0:
            return 0;
        }
        a0->field_EE = 0xFFFF;
        a0->field_EB = 0;
        a0->field_47 = 0;
        break;

    case 4:
        p = *(u8 *volatile *)&a0->field_3C;
        if (p[2] != 0) {
            goto ret0;
        }
        if (p[3] != 0) {
            goto ret0;
        }
        v = a0->field_EC;
        v += 8;
        v += (p[4] + 3) & 0x1FC;
        a0->field_EC = v;
        if (++a0->field_47 < a0->field_EA) {
            goto ret0;
        }
        if (func_80025FBC(a0) > 0x80) {
            D_80048E1C(a0);
            a0->field_46 = 0xFE;
            a0->field_49 = 2;
            goto ret0;
        }
        if (a0->field_EE != a0->field_EC) {
            a0->field_EE = a0->field_EC;
            a0->field_47 = 0;
            a0->field_EC = 0;
            return 0;
        }
        a0->field_EE = 0;
        a0->field_EB = 0;
        a0->field_46 = 0xFF;
        func_80025FF4(a0, a0->field_63);
        a0->field_46 = 2;
        goto ret0;

    }
    return 1;
}


s32 func_80025FBC(Obj25FBC *arg0) {
    s32 a = ((arg0->field_E3 + 1) >> 1) << 2;
    s32 b = ((arg0->field_E9 * 5 + 3) & 0xFFC) + 4;
    return a + b + arg0->field_EC;
}

s32 func_80025FF4(Obj25FBC *a0, s32 a1) {
    s32 n;

    if (a1 == 0 || a0->field_4 != 0 || D_80048E34() != 0) {
        return 0;
    }
    a0->field_49 = 4;
    a0->field_46 = 1;
    a0->field_14 = (s32)func_800260C8;
    a0->field_18 = (s32)func_80026170;
    n = (a1 + 3) >> 2 << 2;
    a0->field_0 = n;
    a0->field_47 = 0;
    n += (a0->field_E3 + 1) / 2 * 4;
    a0->field_4 = n;
    n += (a0->field_E9 * 5 + 3) & 0xFFC;
    a0->field_8 = n;
    return 1;
}

void func_800260C8(Actor *a) {
    switch (a->field_46) {
    case 2:
        Pad_CmdQueryMode(a, a->field_47);
        return;
    case 3:
        Pad_CmdQueryAct(a, a->field_47);
        return;
    case 4:
        if (a->field_48[0].field_0 == 0) {
            Pad_CmdQueryComb(a, a->field_47);
            return;
        }
        func_800265FC(a);
        return;
    }
}

s32 func_80026170(Obj26170 *a) {
    volatile Ent26170 *q;
    Blk26170 *e;
    u8 *src;
    s32 n;
    s32 x;

    switch (a->field_46) {
    case 2:
        if (a->field_3C[2] != 0) return 0;
        if (a->field_3C[3] != 0) return 0;
        a->field_0[a->field_47] = (a->field_3C[4] << 8) + a->field_3C[5];
        if (a->field_EE != a->field_0[a->field_47]) {
            a->field_EE = a->field_0[a->field_47];
            return 0;
        }
        a->field_EE = 0;
        a->field_EB = 0;
        if (++a->field_47 < a->field_E3) return 0;
        a->field_47 = 0;
        break;
    case 3:
        if (a->field_3C[2] != 0) return 0;
        if (a->field_3C[3] != 0) return 0;
        q = &a->field_4[a->field_47];
        if (q->field_0 == a->field_3C[4] && q->field_1 == (a->field_3C[5] & 0x7F) && q->field_2 == a->field_3C[6]
            && q->field_3 == a->field_3C[7] && (x = a->field_3C[5], q->field_4 == x >> 7)) {
            a->field_EE = 0;
        } else {
            a->field_EE = 0xFFFF;
        }
        q->field_0 = a->field_3C[4];
        q->field_1 = a->field_3C[5] & 0x7F;
        q->field_2 = a->field_3C[6];
        q->field_3 = a->field_3C[7];
        q->field_4 = (x = a->field_3C[5]) >> 7;
        if (a->field_EE != 0) return 0;
        a->field_EB = 0;
        if (++a->field_47 < a->field_E9) return 0;
        a->field_47 = 0;
        a->field_48 = 0;
        break;
    case 4:
        if (a->field_3C[2] != 0) {
            a->field_48 = 0;
            return 0;
        }
        e = &a->field_8[a->field_47];
        if (a->field_48 == 0) {
            e->field_0 = a->field_48 = a->field_3C[4];
            src = a->field_3C + 5;
            n = 3;
            if (a->field_47 == 0) {
                D_80060048 = e->field_4 = (u8 *)&a->field_8[a->field_EA];
            } else {
                D_80060048 = e->field_4 = e[-1].field_4 + ((e[-1].field_0 + 3) & 0x1FC);
            }
        } else {
            src = a->field_3C + 3;
            n = 5;
        }
        while (--n != -1) {
            if (a->field_48 == 0) goto done;
            if (D_80060048 >= &a->field_E3) goto fail;
            if (*D_80060048 != *src) a->field_EE = 0xFFFF;
            *D_80060048++ = *src++;
            a->field_48--;
        }
        if (a->field_48 != 0) return 0;
    done:
        if (a->field_EE != 0) {
            a->field_EE = 0;
            a->field_48 = 0;
            return 0;
        }
        if (++a->field_47 >= a->field_EA) {
            a->field_49 = 6;
            a->field_46 = 0xFE;
            a->field_EB = 0;
            return 0;
        }
        a->field_48 = 0;
        a->field_EB = 0;
        return 0;
    fail:
        a->field_47 = 0;
        a->field_48 = 0;
        return 0;
    }
    return 1;
}


void Pad_CmdConfigMode(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x43;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void Pad_CmdQueryModel(Actor *arg0) {
    arg0->u34.b.field_37 = 0x45;
    arg0->work = NULL;
    arg0->u34.b.field_36 = 0;
}

void Pad_CmdQueryMode(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x4C;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void Pad_CmdQueryAct(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x46;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void Pad_CmdQueryComb(Actor *arg0, u8 arg1) {
    arg0->u34.b.field_37 = 0x47;
    arg0->work = (ActorWork *)&arg0->field_24;
    arg0->field_24 = arg1;
    arg0->u34.b.field_36 = 1;
}

void func_800265FC(Actor *arg0) {
    arg0->u34.b.field_37 = 0x4B;
    arg0->work = NULL;
    arg0->u34.b.field_36 = 0;
}

void Pad_SetTimeout(s32 arg0) {
    D_80060050 = arg0;
    D_8006004C = *(volatile u16 *)0x1F801120;
}

s32 Pad_IsTimedOut(void) {
    u16 c = *(volatile u16 *)0x1F801120;
    s32 t = c;
    s32 d;
    s32 lim;

    if (t < D_8006004C) {
        if (*(volatile u16 *)0x1F801128 != 0) {
            t += *(volatile u16 *)0x1F801128;
        } else {
            t += 0x10000;
        }
    }
    if (!(*(volatile u16 *)0x1F801124 & 0x200)) {
        d = (t - D_8006004C) >> 3;
        lim = D_80060050;
    } else {
        d = t - D_8006004C;
        lim = D_80060050;
    }
    return d >= lim;
}


void func_800266D0(Ent266D0 *a0) {
    D_80048E98 = D_80048E30(a0);
    *a0->field_3C = 0;
    func_80025760(a0, -2);
}

void Pad_SioStepSendCmd(Obj25FBC *a0) {
    if (D_80048E58 == D_80048E68 && D_80048E54 != 0) {
        D_80048E48();
        D_80048E44();
    }
    if (D_80048E98 != 0) {
        D_80048E30(a0->field_C);
        D_80048E30(&a0->field_C[1]);
    }
    if (a0->field_37 == 0) {
        Pad_SioExchangeByte(a0, 0x42);
    } else {
        Pad_SioExchangeByte(a0, a0->field_37);
    }
}


s32 Pad_SioStepRecvId(Ent266D0 *a0) {
    s32 r;

    if (D_80048E98 != 0) {
        D_80048E30(&a0->field_C[2].e);
        D_80048E30(&a0->field_C[3].e);
    }
    r = Pad_SioExchangeByte(a0, a0->field_37 ? 0 : D_80048E64);
    if (r >= 0) {
        D_80048E94 = (r & 0xF) * 2;
        if (D_80048E94 == 0) {
            D_80048E94 = 0x20;
        }
        r = 0;
    }
    return r;
}


s32 Pad_SioStepRecv5A(Ent266D0 *a0) {
    s32 f = 0;
    s32 r;

    if (D_80048E64 != 0) {
        s32 st = *a0->field_3C;
        if ((st >> 4) == 8) {
            f = a0->field_37 == 0;
        }
    }
    D_80048E9C = f;
    if (f == 0 && a0->field_37 == 0 && a0->field_38 == 0
        && (a0 == a0->field_10 || a0->field_39 == 0) && *a0->field_30 == 0) {
        D_80048E24(a0);
    }
    r = Pad_SioExchangeByte(a0, (u8)D_80048E20(a0, D_80048E9C));
    if (r == 0x5A || r == 0) {
        return r;
    }
    if (r >= 0) {
        return -4;
    }
    return r;
}

static inline s32 inl_w(s32 arg0) {
    volatile Regs48E8C *q = Pad_IntrRegs;
    Stat48E90 *st = Pad_SioRegs;
    D_80060050 = arg0;
    D_8006004C = *(volatile u16 *)0x1F801120;
    q->field_0 = -0x81;
    if (st->field_4 & 0x80) {
        do {
            if (Pad_IsTimedOut() != 0) {
                return 0;
            }
        } while (Pad_SioRegs->field_4 & 0x80);
    }
    Pad_SioRegs->field_A |= 0x10;
    return 1;
}

static inline s32 inl_h(s32 arg0, volatile u16 *hw) {
    volatile Regs48E8C *q = Pad_IntrRegs;
    Stat48E90 *st = Pad_SioRegs;
    D_80060050 = arg0;
    D_8006004C = *hw;
    q->field_0 = -0x81;
    if (st->field_4 & 0x80) {
        do {
            if (Pad_IsTimedOut() != 0) {
                return 0;
            }
        } while (Pad_SioRegs->field_4 & 0x80);
    }
    Pad_SioRegs->field_A |= 0x10;
    return 1;
}

s32 Pad_SioStepRecvData(Ent266D0 *a0) {
    s32 f;
    s32 i;
    s32 r;
    s32 t;
    s32 ok;
    s32 idx;
    Obj25FBC *e;
    Slot267F0 *s;
    s32 *slot;
    s32 c;

    if (D_80048E9C != 0 && a0->field_37 == 0 && a0->field_38 == 0
        && (a0 == a0->field_10 || a0->field_39 == 0) && *a0->field_30 == 0) {
        D_80048E24(a0);
    }
    f = D_80048E9C;
    if (f != 0) {
        for (i = -1; i < 4; i++) {
            if (--D_80048E94 <= 0) {
                break;
            }
            if (i >= 0) {
                s = &a0->field_C[i];
                if (s->e.field_37 == 0 && s->e.field_38 == 0
                    && (&s->e == s->e.field_10 || s->e.field_39 == 0) && *s->e.field_30 == 0) {
                    D_80048E24(&s->e);
                }
            }
            r = Pad_SioExchangeByte(a0, (u8)D_80048E20(a0, 1));
            if (r < 0) {
                return r;
            }
            if (inl_w(0x3C) == 0) {
                return -3;
            }
        }
    }
    e = 0;
    idx = D_80048E58 == 0;
    while (D_80048E94 >= 2) {
        slot = &D_80048E70[idx];
        t = 0x3C;
        c = 3;
            if (*slot < 0) {
                break;
            }
            if (*slot > 0) {
                e = D_80048E4C[idx].field_C + *slot - 1;
                D_80048E38(e);
            }
            switch (*slot) {
            case 4:
                *slot = c;
                break;
            case 3:
                D_80048E38(e - 1);
                *slot = 1;
                break;
            case 0:
            case 1:
                e = &D_80048E4C[idx];
                D_80048E38(e);
                D_80048E3C((Actor *)e);
                *slot = -1;
                break;
            }
            r = func_80025760(a0, (u8)D_80048E20(a0, f));
            if (r < 0) {
                return r;
            }
            if (inl_w(t) == 0) {
                return -3;
            }
        D_80048E94--;
    }
    while (--D_80048E94 > 0) {
        s32 u = 0x22;
        volatile u16 *hw = (volatile u16 *)0x1F801120;
        t = 0x3C;
        r = func_80025760(a0, (u8)D_80048E20(a0, f));
        if (r < 0) {
            return r;
        }
        if (Pad_SioRegs->field_E != u) {
            if (inl_h(t, hw) == 0) {
                return -3;
            }
        }
    }
    {
        Stat48E90 *st = Pad_SioRegs;
        while (!(st->field_4 & 2)) {
        }
    }
    {
        s32 k = a0->field_44;
        a0->field_44 = k + 1;
        a0->field_3C[k] = Pad_SioRegs->field_0;
    }
    D_80048E18(0);
    return 0;
}


ASM_SOURCE("src/main/asm/libapi", InitHeap);

ASM_SOURCE("src/main/asm/libapi", EnterCriticalSection);

ASM_SOURCE("src/main/asm/libapi", ExitCriticalSection);

ASM_SOURCE("src/main/asm/libapi", SysEnqIntRP);

ASM_SOURCE("src/main/asm/libapi", SysDeqIntRP);

ASM_SOURCE("src/main/asm/libapi", ChangeClearRCnt);

u8 *bzero(u8 *s, s32 n) {
    u8 *r = 0;

    if (s != 0) {
        r = s;
        if (n <= 0) {
            r = 0;
        } else {
            while (n > 0) {
                *s++ = 0;
                n--;
            }
        }
    }
    return r;
}


u8 *memcpy(u8 *dst, u8 *src, s32 n) {
    u8 *r = 0;

    if (dst != 0) {
        u8 *d = dst;

        while (n > 0) {
            *dst++ = *src++;
            n--;
        }
        r = d;
    }
    return r;
}

u8 *memset(u8 *s, s32 c, s32 n) {
    u8 *r = 0;

    if (s != 0) {
        r = s;
        if (n <= 0) {
            r = 0;
        } else {
            while (n > 0) {
                *s++ = c;
                n--;
            }
        }
    }
    return r;
}


u8 *strcpy(u8 *dst, u8 *src) {
    u8 *r = 0;

    if (dst != 0) {
        u8 *d = dst;
        if (src != 0) {
            s32 c = *src++;

            *dst++ = c;
            while (c != 0) {
                c = *src++;
                *dst++ = c;
            }
            r = d;
        }
    }
    return r;
}

s32 ResetGraph(s32 mode) {
    Gpu48F10 *g;

    switch (mode & 7) {
    case 0:
    case 3:
        printf(D_8001021C, D_80048EC8, &D_80048F10);
    case 5:
        g = &D_80048F10;
        func_80029FDC((u8 *)g, 0, 0x80);
        ResetCallback();
        GPU_cw((s32)D_80048F08 & 0xFFFFFF);
        g->field_0 = _reset(mode);
        g->field_1 = 1;
        g->field_4 = D_80048F90[((volatile Gpu48F10 *)g)->field_0][0];
        g->field_6 = D_80048F9C.field_0[g->field_0][0];
        func_80029FDC(g->field_10, -1, 0x5C);
        func_80029FDC((u8 *)&g->field_6C, -1, 0x14);
        return g->field_0;
    default:
        if (D_80048F12 >= 2) {
            D_80048F0C(D_8001023C, mode);
        }
        return D_80048F08->fn_34(1);
    }
}

u8 SetGraphDebug(u8 level) {
    s32 old = D_80048F10.field_2;

    D_80048F10.field_2 = level;
    if (level) {
        D_80048F0C(D_80010250, D_80048F10.field_2, D_80048F10.field_0, D_80048F10.field_3);
    }
    return old;
}

extern char D_8001027C[];

s32 SetGrapQue(s32 a0) {
    s32 old = D_80048F10.field_1;

    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_8001027C, a0);
    }
    if (a0 != D_80048F10.field_1) {
        D_80048F08->fn_34(1);
        D_80048F10.field_1 = a0;
        DMACallback(2, 0);
    }
    return old;
}


u8 GetGraphDebug(void) {
    return D_80048F12;
}

s32 DrawSyncCallback(s32 a0) {
    s32 old;

    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_80010290, a0);
    }
    old = D_80048F10.field_C;
    D_80048F10.field_C = a0;
    return old;
}

void SetDispMask(s32 a0) {
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_800102AC, a0);
    }
    if (a0 == 0) {
        func_80029FDC((u8 *)&D_80048F10.field_6C, -1, 0x14);
    }
    D_80048F08->fn_10(a0 ? 0x03000000 : 0x03000001);
}

void DrawSync(void *a0) {
    if (D_80048F12 >= 2) {
        D_80048F0C(&D_800102C0, a0);
    }
    D_80048F08->fn_3C(a0);
}

void checkRECT(char *name, Rect2AB54 *r) {
    switch (D_80048F10.field_2) {
    case 1:
        if (r->w > D_80048F10.field_4 || r->w + r->x > D_80048F10.field_4
            || r->y > D_80048F10.field_6 || r->y + r->h > D_80048F10.field_6
            || r->w <= 0 || r->x < 0 || r->y < 0 || r->h <= 0) {
            D_80048F0C(D_800102D4, name);
            D_80048F0C(D_800102E0, r->x, r->y, r->w, r->h);
        }
        break;
    case 2:
        D_80048F0C(D_800102F4, name);
        D_80048F0C(D_800102E0, r->x, r->y, r->w, r->h);
        break;
    }
}

void ClearImage(s32 a0, s32 a1, s32 a2, s32 a3) {
    checkRECT(D_800102F8, a0);
    D_80048F08->fn_8(D_80048F08->field_C, a0, 8, ((a3 & 0xFF) << 16) | ((a2 & 0xFF) << 8) | (a1 & 0xFF));
}

void ClearImage2(s32 a0, s32 a1, s32 a2, s32 a3) {
    checkRECT(D_80010304, a0);
    D_80048F08->fn_8(D_80048F08->field_C, a0, 8, ((a3 & 0xFF) << 16 | 0x80000000 | (a2 & 0xFF) << 8) | (a1 & 0xFF));
}

void LoadImage(s32 a0, s32 a1) {
    checkRECT(D_80010310, a0);
    D_80048F08->fn_8(D_80048F08->field_20, a0, 8, a1);
}

void StoreImage(s32 a0, s32 a1) {
    checkRECT(D_8001031C, a0);
    D_80048F08->fn_8(D_80048F08->field_1C, a0, 8, a1);
}

s32 MoveImage(Rect2AB54 *rect, s32 x, s32 y) {
    checkRECT(D_80010328, (s32)rect);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_80048F9C.move[2] = *(u32 *)&rect->x;
    D_80048F9C.move[3] = (y << 16) | (x & 0xFFFF);
    D_80048F9C.move[4] = *(u32 *)&rect->w;
    return D_80048F08->fn_8((s32)D_80048F08->field_18, (s32)D_80048F9C.move, 0x14, 0);
}

OTag *ClearOTag(OTag *ot, s32 n) {
    u32 *term;

    if (D_80048F12 >= 2) {
        D_80048F0C(D_80010334, ot, n);
    }
    while (--n) {
        ot->len = 0;
        ot->addr = (u32)(ot + 1);
        ot++;
    }
    term = &D_80048FD0;
    *term = ((u32)&D_80048FBC & 0xFFFFFF) | 0x04000000;
    *(u32 *)ot = (u32)term & 0xFFFFFF;
    return ot;
}

Blk54CF8 *ClearOTagR(Blk54CF8 *ot, s32 n) {
    u32 *term;

    if (D_80048F12 >= 2) {
        D_80048F0C(D_8001034C, ot, n);
    }
    D_80048F08->fn_2C(ot->field_0, n);
    term = &D_80048FD0;
    *term = ((u32)&D_80048FBC & 0xFFFFFF) | 0x4000000;
    ot->field_0[0] = (u32)term & 0xFFFFFF;
    return ot;
}

void DrawPrim(Ent27A18 *a0) {
    s32 n = a0->field_3;

    D_80048F08->fn_3C(0);
    D_80048F08->fn_14(a0->field_4, n);
}

s32 DrawOTag(void *a0) {
    if (D_80048F12 >= 2) {
        D_80048F0C(&D_80010364, a0);
    }
    return D_80048F08->fn_8(D_80048F08->field_18, (s32)a0, 0, 0);
}

DrawEnv *PutDrawEnv(DrawEnv *env) {
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(&D_80010378, env);
    }
    func_800284C4(env->dr_env, env);
    env->dr_env[0] |= 0xFFFFFF;
    D_80048F08->fn_8(D_80048F08->field_18, (s32)env->dr_env, 0x40, 0);
    memcpy(D_80048F10.field_10, env, 0x5C);
    return env;
}

void DrawOTagEnv(s32 ot, DrawEnv *env) {
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_80010390, ot, env);
    }
    func_800284C4(env->dr_env, env);
    env->dr_env[0] = (env->dr_env[0] & 0xFF000000) | (ot & 0xFFFFFF);
    D_80048F08->fn_8(D_80048F08->field_18, (s32)env->dr_env, 0x40, 0);
    memcpy(D_80048F10.field_10, env, 0x5C);
}

s32 GetDrawEnv(s32 arg0) {
    memcpy(arg0, D_80048F20, 0x5C);
    return arg0;
}

DispEnv *PutDispEnv(DispEnv *e) {
    DispEnv *env = e;
    s32 mode;
    s32 hs;
    s32 he;
    s32 vs;
    s32 ve;
    s32 k;
    s32 w;
    s32 t;
    s32 y;
    volatile DispEnv *d;

    mode = 0x08000000;
    if (D_80048F10.field_2 >= 2) {
        D_80048F0C(D_800103AC, env);
    }
    D_80048F08->fn_10(0x05000000 | ((env->disp.y & 0x3FF) << 10) | (env->disp.x & 0x3FF));
    d = &D_80048F10.field_6C;
    if (*(volatile s32 *)&D_80048F10.field_6C.isinter != *(s32 *)&env->isinter
        || d->disp.x != env->disp.x
        || d->disp.y != env->disp.y
        || d->disp.w != env->disp.w
        || d->disp.h != env->disp.h) {
        env->pad0 = GetVideoMode();
        if (env->pad0 == 1) {
            mode |= 0x08;
        }
        if (env->isrgb24) {
            mode |= 0x10;
        }
        if (env->isinter) {
            mode |= 0x20;
        }
        if (D_80048F10.field_3) {
            mode |= 0x80;
        }
        if (env->disp.w > 280) {
            if (env->disp.w <= 352) {
                mode |= 0x01;
            } else if (env->disp.w <= 400) {
                mode |= 0x40;
            } else if (env->disp.w <= 560) {
                mode |= 0x02;
            } else {
                mode |= 0x03;
            }
        }
        y = env->disp.h;
        if (env->pad0 != 0) {
            t = y < 289;
        } else {
            t = y < 257;
        }
        if (!t) {
            mode |= 0x24;
        }
        D_80048F08->fn_10(mode);
        env->pad0 = 8;
    }
    if (D_80048F10.field_6C.screen.x != env->screen.x
        || D_80048F10.field_6C.screen.y != env->screen.y
        || D_80048F10.field_6C.screen.w != env->screen.w
        || D_80048F10.field_6C.screen.h != env->screen.h
        || env->pad0 == 8) {
        env->pad0 = GetVideoMode();
        y = env->screen.y;
        if (env->pad0 != 0) {
            vs = y + 0x13;
        } else {
            vs = y + 0x10;
        }
        if (env->screen.h != 0) {
            ve = vs + env->screen.h;
        } else {
            ve = vs + 0xF0;
        }
        if (env->disp.w <= 280) {
            k = 0;
        } else if (env->disp.w <= 352) {
            k = 1;
        } else if (env->disp.w <= 400) {
            k = 2;
        } else if (env->disp.w <= 560) {
            k = 3;
        } else {
            k = 4;
        }
        hs = D_80048FE4[env->pad0][k].lo + env->screen.x * D_8004900C[k];
        w = D_80048FE4[env->pad0][k].hi - D_80048FE4[env->pad0][k].lo;
        he = hs + (env->screen.w != 0 ? (w * env->screen.w) >> 8 : w);
        if (env->pad0 != 0) {
            hs = hs < 0x21C ? 0x21C : (hs > 0xC94 ? 0xC94 : hs);
            he = he < hs + D_8004900C[k] * 4 ? hs + D_8004900C[k] * 4 : (he > 0xCBC ? 0xCBC : he);
            vs = vs < 0x13 ? 0x13 : (vs > 0x12F ? 0x12F : vs);
            ve = ve < vs + 2 ? vs + 2 : (ve > 0x131 ? 0x131 : ve);
        } else {
            hs = hs < 0x1F4 ? 0x1F4 : (hs > 0xCB2 ? 0xCB2 : hs);
            he = he < hs + D_8004900C[k] * 4 ? hs + D_8004900C[k] * 4 : (he > 0xCDA ? 0xCDA : he);
            vs = vs < 0x10 ? 0x10 : (vs > 0x101 ? 0x101 : vs);
            ve = ve < vs + 2 ? vs + 2 : (ve > 0x102 ? 0x102 : ve);
        }
        D_80048F08->fn_10(0x06000000 | ((he & 0xFFF) << 12) | (hs & 0xFFF));
        D_80048F08->fn_10(0x07000000 | ((ve & 0x3FF) << 10) | (vs & 0x3FF));
    }
    memcpy((u8 *)&D_80048F10.field_6C, (u8 *)env, 0x14);
    return env;
}


s32 GetDispEnv(s32 arg0) {
    memcpy(arg0, D_80048F7C, 0x14);
    return arg0;
}

u32 GetODE(void) {
    return (u32)D_80048F08->fn() >> 31;
}

extern s32 get_cs(s16, s16);
extern s32 get_ce(s16, s16);

void SetDrawArea(Obj8228C *a0, Pt8228C *a1) {
    a0->field_3 = 2;
    a0->field_4 = get_cs(a1->field_0, a1->field_2);
    a0->field_8 = get_ce((s16)(a1->field_0 + a1->field_4 - 1),
                                (s16)(a1->field_2 + a1->field_6 - 1));
}

void SetDrawOffset(Obj8228C *arg0, Pt8228C *arg1) {
    arg0->field_3 = 2;
    arg0->field_4 = get_ofs(arg1->field_0, arg1->field_2);
    arg0->field_8 = 0;
}

void func_800282CC(DrEnv282CC *d, DrawEnv *env) {
    Rect282CC rect;
    s32 len;

    d->w[1] = get_cs(env->clip_x, env->clip_y);
    d->w[2] = get_ce(env->clip_w + env->clip_x - 1, env->clip_y + env->clip_h - 1);
    d->w[3] = get_ofs(env->ofs[0], env->ofs[1]);
    d->w[4] = get_mode(env->dfe, env->dtd, env->tpage);
    d->w[5] = get_tw((Rect288A0 *)&env->tw_x);
    d->w[6] = 0xE6000000;
    len = 7;
    if (env->isbg) {
        rect.r.x = env->clip_x;
        rect.r.y = env->clip_y;
        rect.r.w = env->clip_w;
        rect.r.h = env->clip_h;
        rect.r.w = (rect.r.w < 0) ? 0 : ((rect.r.w > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : rect.r.w);
        rect.r.h = (rect.r.h < 0) ? 0 : ((rect.r.h > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : rect.r.h);
        rect.r.x -= env->ofs[0];
        rect.r.y -= env->ofs[1];
        d->w[len++] = 0x60000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
        d->w[len++] = rect.w[0];
        d->w[len++] = rect.w[1];
    }
    d->h.len = len - 1;
}

void func_800284C4(DrEnv282CC *d, DrawEnv *env) {
    Rect282CC rect;
    s32 len;

    d->w[1] = get_cs(env->clip_x, env->clip_y);
    d->w[2] = get_ce(env->clip_w + env->clip_x - 1, env->clip_y + env->clip_h - 1);
    d->w[3] = get_ofs(env->ofs[0], env->ofs[1]);
    d->w[4] = get_mode(env->dfe, env->dtd, env->tpage);
    d->w[5] = get_tw((Rect288A0 *)&env->tw_x);
    d->w[6] = 0xE6000000;
    len = 7;
    if (env->isbg) {
        rect.r.x = env->clip_x;
        rect.r.y = env->clip_y;
        rect.r.w = env->clip_w;
        rect.r.h = env->clip_h;
        rect.r.w = (rect.r.w < 0) ? 0 : ((rect.r.w > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : rect.r.w);
        rect.r.h = (rect.r.h < 0) ? 0 : ((rect.r.h > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : rect.r.h);
        if ((rect.r.x & 0x3F) || (rect.r.w & 0x3F)) {
            rect.r.x -= env->ofs[0];
            rect.r.y -= env->ofs[1];
            d->w[len++] = 0x60000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            d->w[len++] = rect.w[0];
            d->w[len++] = rect.w[1];
        } else {
            d->w[len++] = 0x02000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            d->w[len++] = rect.w[0];
            d->w[len++] = rect.w[1];
        }
    }
    d->h.len = len - 1;
}

int get_mode(int a0, int a1, int a2) {
    int v1 = 0xE1000000;
    int v0;
    if (a1) v1 = 0xE1000200;
    v0 = a2 & 0x9FF;
    if (a0) v0 |= 0x400;
    return v0 | v1;
}

s32 get_cs(s16 x, s16 y) {
    x = (x < 0) ? 0 : ((x > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : x);
    y = (y < 0) ? 0 : ((y > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : y);
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

s32 get_ce(s16 x, s16 y) {
    x = (x < 0) ? 0 : ((x > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : x);
    y = (y < 0) ? 0 : ((y > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : y);
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

s32 get_ofs(s32 arg0, s32 arg1) {
    return 0xE5000000 | ((arg1 & 0x7FF) << 11) | (arg0 & 0x7FF);
}

u32 get_tw(Rect288A0 *tw) {
    s32 t[4];

    if (tw != 0) {
        t[0] = (tw->x & 0xFF) >> 3;
        t[2] = (-tw->w & 0xFF) >> 3;
        t[1] = (tw->y & 0xFF) >> 3;
        t[3] = (-tw->h & 0xFF) >> 3;
        return 0xE2000000 | (t[1] << 15) | (t[0] << 10) | (t[3] << 5) | t[2];
    }
    return 0;
}

s32 _status(void) {
    return *D_80049018;
}

s32 _otc(s32 *a0, s32 a1) {
    *D_80049034 |= 0x08000000;
    *D_80049030 = 0;
    *D_80049028 = (s32)&a0[a1 - 1];
    *D_8004902C = a1;
    *D_80049030 = 0x11000002;
    set_alarm();
    while (*D_80049030 & 0x01000000) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    return a1;
}

s32 _clr(Rect282CC *rect, s32 color) {
    rect->r.w = (rect->r.w < 0) ? 0 : ((rect->r.w > D_80048F10.field_4 - 1) ? D_80048F10.field_4 - 1 : rect->r.w);
    rect->r.h = (rect->r.h < 0) ? 0 : ((rect->r.h > D_80048F10.field_6 - 1) ? D_80048F10.field_6 - 1 : rect->r.h);
    if ((rect->r.x & 0x3F) || (rect->r.w & 0x3F)) {
        D_80060060[0] = ((u32)D_80060088 & 0xFFFFFF) | 0x08000000;
        D_80060060[1] = 0xE3000000;
        D_80060060[2] = 0xE4FFFFFF;
        D_80060060[3] = 0xE5000000;
        D_80060060[4] = 0xE6000000;
        D_80060060[5] = gpu_draw_mode(0xE1000000, (u32)color >> 31, *D_80049018);
        D_80060060[6] = (color & 0xFFFFFF) | 0x60000000;
        D_80060060[7] = rect->w[0];
        D_80060060[8] = rect->w[1];
        D_80060088[0] = 0x03FFFFFF;
        D_80060088[1] = _param(3) | 0xE3000000;
        D_80060088[2] = _param(4) | 0xE4000000;
        D_80060088[3] = _param(5) | 0xE5000000;
    } else {
        D_80060060[0] = 0x05FFFFFF;
        D_80060060[1] = 0xE6000000;
        D_80060060[2] = gpu_draw_mode(0xE1000000, (u32)color >> 31, *D_80049018);
        D_80060060[3] = (color & 0xFFFFFF) | 0x02000000;
        D_80060060[4] = rect->w[0];
        D_80060060[5] = rect->w[1];
    }
    _cwc((s32)D_80060060);
    return 0;
}


s32 _dws(Rect28C48 *rect, s32 *p) {
    s32 size;
    s32 n;
    s32 blocks;
    s32 clr;
    s32 v;
    s32 *g;

    set_alarm();
    clr = 0;
    rect->r.w = (rect->r.w < 0) ? 0 : ((rect->r.w > D_80048F10.field_4) ? D_80048F10.field_4 : rect->r.w);
    rect->r.h = (rect->r.h < 0) ? 0 : ((rect->r.h > D_80048F10.field_6) ? D_80048F10.field_6 : rect->r.h);
    size = (rect->r.w * rect->r.h + 1) / 2;
    if (size <= 0) {
        return -1;
    }
    n = size % 16;
    blocks = size / 16;
    while (!(*D_80049018 & 0x4000000)) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    *D_80049018 = 0x4000000;
    *D_80049014 = 0x1000000;
    v = 0xA0000000;
    g = D_80049014;
    if (clr) {
        v = 0xB0000000;
    }
    *g = v;
    *D_80049014 = rect->word[0];
    *D_80049014 = rect->word[1];
    for (n--; n != -1; n--) {
        *D_80049014 = *p++;
    }
    if (blocks != 0) {
        *D_80049018 = 0x4000002;
        *D_8004901C = (s32)p;
        *D_80049020 = (blocks << 16) | 0x10;
        *D_80049024 = 0x1000201;
    }
    return 0;
}


s32 _drs(Rect28E84 *rect, s32 *p) {
    s32 size;
    s32 n;
    s32 blocks;

    set_alarm();
    rect->r.w = (rect->r.w < 0) ? 0 : ((rect->r.w > D_80048F10.field_4) ? D_80048F10.field_4 : rect->r.w);
    rect->r.h = (rect->r.h < 0) ? 0 : ((rect->r.h > D_80048F10.field_6) ? D_80048F10.field_6 : rect->r.h);
    size = (rect->r.w * rect->r.h + 1) / 2;
    if (size <= 0) {
        return -1;
    }
    n = size % 16;
    blocks = size / 16;
    while (!(*D_80049018 & 0x4000000)) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    *D_80049018 = 0x4000000;
    *D_80049014 = 0x1000000;
    *D_80049014 = 0xC0000000;
    *D_80049014 = rect->w[0];
    *D_80049014 = rect->w[1];
    while (!(*D_80049018 & 0x8000000)) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    for (n--; n != -1; n--) {
        *p++ = *D_80049014;
    }
    if (blocks != 0) {
        *D_80049018 = 0x4000003;
        *D_8004901C = (s32)p;
        *D_80049020 = (blocks << 16) | 0x10;
        *D_80049024 = 0x1000200;
    }
    return 0;
}


void _ctl(s32 arg0) {
    *D_80049018 = arg0;
}

void func_80029118(void) {
}

s32 _cwb(s32 *arg0, u32 arg1) {
    *D_80049018 = 0x4000000;
    while (arg1-- != 0) {
        *D_80049014 = *arg0++;
    }
    return 0;
}

void _cwc(s32 arg0) {
    *D_80049018 = 0x4000002;
    *D_8004901C = arg0;
    *D_80049020 = 0;
    *D_80049024 = 0x1000401;
}

s32 _param(s32 arg0) {
    *D_80049018 = arg0 | 0x10000000;
    return *D_80049014 & 0xFFFFFF;
}

void _addque(s32 arg0, s32 arg1, s32 arg2) { _addque2(arg0, arg1, 0, arg2); }

s32 _addque2(void (*func)(s32 *, s32), s32 *param, s32 n, s32 x) {
    s32 i;
    Gpu48F10 *g;

    set_alarm();
    while (((D_80049038 + 1) & 0x3F) == D_8004903C) {
        if (get_alarm() != 0) {
            return -1;
        }
        _exeque();
    }
    D_80049040 = SetIntrMask(0);
    g = &D_80048F10;
    g->field_8 = 1;
    if (g->field_1 == 0 ||
        (D_80049038 == D_8004903C && !(*D_80049024 & 0x1000000) && g->field_C == 0)) {
        while (!(*(volatile s32 *)D_80049018 & 0x4000000)) {
        }
        func(param, x);
        SetIntrMask(D_80049040);
        return 0;
    }
    DMACallback(2, _exeque);
    if (n != 0) {
        for (i = 0; i < n / 4; i++) {
            volatile s32 *d = D_800600B0[D_80049038].param;
            d[i] = param[i];
        }
        D_800600B0[D_80049038].ptr = D_800600B0[D_80049038].param;
    } else {
        D_800600B0[D_80049038].ptr = param;
    }
    D_800600B0[D_80049038].x = x;
    D_800600B0[D_80049038].func = func;
    D_80049038 = (D_80049038 + 1) & 0x3F;
    SetIntrMask(D_80049040);
    _exeque();
    return (D_80049038 - D_8004903C) & 0x3F;
}


s32 _exeque(void) {
    void (*cb)(void);
    volatile s32 *g;
    s32 k1;
    s32 k2;

    if (*D_80049024 & 0x1000000) {
        return 1;
    }
    D_80049044 = SetIntrMask(0);
    while (D_80049038 != D_8004903C && (k2 = 0x1000000, !(*D_80049024 & k2))) {
        if (((D_8004903C + 1) & 0x3F) == D_80049038 && D_80048F10.field_C == 0) {
            DMACallback(2, 0);
        }
        g = (volatile s32 *)D_80049018;
        while (k1 = 0x4000000, !(*g & k1)) {
        }
        D_800600B0[D_8004903C].func(D_800600B0[D_8004903C].ptr, D_800600B0[D_8004903C].x);
        D_8004903C = (D_8004903C + 1) & 0x3F;
    }
    SetIntrMask(D_80049044);
    if (D_80049038 == D_8004903C && !(*D_80049024 & 0x1000000) && D_80048F10.field_8 != 0) {
        cb = (void (*)(void))D_80048F10.field_C;
        if (cb != 0) {
            ((volatile Gpu48F10 *)&D_80048F10)->field_8 = 0;
            cb();
        }
    }
    return (D_80049038 - D_8004903C) & 0x3F;
}


s32 _reset(s32 mode) {
    D_80049048 = SetIntrMask(0);
    D_80049038 = D_8004903C = 0;
    switch (mode & 7) {
    case 0:
    case 5:
        *D_80049024 = 0x401;
        *D_80049034 |= 0x800;
        *D_80049018 = 0;
        func_80029FDC((u8 *)D_800600B0, 0, 0x1800);
        break;
    case 1:
    case 3:
        *D_80049024 = 0x401;
        *D_80049034 |= 0x800;
        *D_80049018 = 0x2000000;
        *D_80049018 = 0x1000000;
        break;
    }
    SetIntrMask(D_80049048);
    if (mode & 7) {
        return 0;
    }
    return _version(mode);
}

s32 _sync(s32 a0) {
    s32 n;

    if (a0 == 0) {
        set_alarm();
        while (D_80049038 != D_8004903C) {
            _exeque();
            if (get_alarm() != 0) {
                return -1;
            }
        }
        while ((*D_80049024 & 0x1000000) || !(*D_80049018 & 0x4000000)) {
            if (get_alarm() != 0) {
                return -1;
            }
        }
        return 0;
    }
    n = (D_80049038 - D_8004903C) & 0x3F;
    if (n != 0) {
        _exeque();
    }
    if ((*D_80049024 & 0x1000000) || !(*D_80049018 & 0x4000000)) {
        if (n != 0) {
            return n;
        }
        return 1;
    }
    return n;
}


void set_alarm(void) {
    D_8004904C = VSync(-1) + 0xF0;
    D_80049050 = 0;
}

s32 get_alarm(void) {
    if (VSync(-1) > D_8004904C || D_80049050++ > 0xF0000) {
        *(volatile s32 *)D_80049018;
        printf(D_800103C4, (D_80049038 - D_8004903C) & 0x3F, *(volatile s32 *)D_80049018,
                      *(volatile s32 *)D_80049024, *(volatile s32 *)D_8004901C);
        D_80049048 = SetIntrMask(0);
        D_8004903C = 0;
        D_80049038 = D_8004903C;
        *D_80049024 = 0x401;
        *D_80049034 |= 0x800;
        *D_80049018 = 0x2000000;
        *D_80049018 = 0x1000000;
        SetIntrMask(D_80049048);
        return -1;
    }
    return 0;
}

s32 _version(s32 a0) {
    *D_80049018 = 0x10000007;
    if ((*D_80049014 & 0xFFFFFF) != 2) {
        *D_80049014 = (*D_80049018 & 0x3FFF) | 0xE1001000;
        *(volatile s32 *)D_80049014;
        return 0;
    }
    if (!(a0 & 8)) {
        return 1;
    }
    *D_80049018 = 0x09000001;
    return 2;
}

s32 LoadImage2(s32 a0, s32 a1) {
    checkRECT(D_800103F8, a0);
    D_8004904C = VSync(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x01000000) || !(*D_80049018 & 0x04000000)) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    DMACallback(2, Gpu_RestoreExequeCb);
    D_80048F08->field_20(a0, a1);
    return 0;
}

s32 StoreImage2(s32 a0, s32 a1) {
    checkRECT(D_8001031C, a0);
    D_8004904C = VSync(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x1000000) || !(*D_80049018 & 0x4000000)) {
        if (get_alarm()) {
            return -1;
        }
    }
    DMACallback(2, Gpu_RestoreExequeCb);
    D_80048F08->field_1C(a0, a1);
    return 0;
}

s32 MoveImage2(Rect2AB54 *rect, s32 x, s32 y) {
    checkRECT(D_80010328, (s32)rect);
    D_8004904C = VSync(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x01000000) || !(*D_80049018 & 0x04000000)) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    DMACallback(2, Gpu_RestoreExequeCb);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_80048F9C.move[2] = *(u32 *)&rect->x;
    D_80048F9C.move[3] = (y << 16) | (x & 0xFFFF);
    D_80048F9C.move[4] = *(u32 *)&rect->w;
    D_80048F08->field_18(D_80048F9C.move);
    return 0;
}

s32 DrawOTag2(u32 *p) {
    if (D_80048F12 >= 2) {
        D_80048F0C(&D_80010364, p);
    }
    D_8004904C = VSync(-1) + 0xF0;
    D_80049050 = 0;
    while ((*D_80049024 & 0x01000000) || !(*D_80049018 & 0x04000000)) {
        if (get_alarm() != 0) {
            return -1;
        }
    }
    DMACallback(2, Gpu_RestoreExequeCb);
    D_80048F08->field_18(p);
    return 0;
}

void Gpu_RestoreExequeCb(void) { DMACallback(0x2, _exeque); }

void func_80029FDC(u8 *arg0, s32 arg1, u32 arg2) {
    while (arg2-- != 0) {
        *arg0++ = arg1;
    }
}

ASM_SOURCE("src/main/asm/libapi", GPU_cw);

void printf(fmt, a1, a2, a3) char *fmt; s32 a1; s32 a2; s32 a3; {
    char **fp = &fmt;
    s32 *ap = &a1;
    ap[1] = a2;
    ap[2] = a3;
    func_8002A054(1, *fp, (char *)ap);
}


s32 func_8002A054(s32 fd, char *fmt0, char *ap) {
    s32 ret;
    s32 dprec;
    s32 fpprec;
    s32 width;
    char *xdigs;
    u8 *fmt;
    s32 ch;
    s32 n;
    char *cp;
    s32 flags;
    s32 prec;
    s32 sign;
    u32 _ulong;
    s32 base;
    s32 fieldsz;
    s32 realsz;
    s32 size;
    char *p;
    char buf[40];

    if (fmt0 == 0) {
        return 0;
    }
    fmt = (u8 *)fmt0;
    xdigs = D_80010404;
    ret = 0;
    for (;; fmt++) {
        ch = *fmt;
        if (ch == 0) {
            goto done;
        }
        if (ch != '%') {
            goto put;
        }
        flags = 0;
        prec = -1;
        sign = 0;
        dprec = 0;
        fpprec = 0;
        width = 0;
    rflag:
        ch = *++fmt;
        switch (ch) {
        case ' ':
            if (!sign) {
                sign = ' ';
            }
            goto rflag;
        case '#':
            flags |= 8;
            goto rflag;
        case '*':
            if ((width = VA_ARG(ap, s32)) >= 0) {
                goto rflag;
            }
            width = -width;
        case '-':
            flags |= 0x10;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *++fmt) == '*') {
                n = VA_ARG(ap, s32);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while ((u32)ch < 0x80 && (D_80049071[*fmt] & 4)) {
                n = n * 10 + (s32)(*fmt++ - '0');
                ch = *fmt;
            }
            fmt--;
            prec = n < 0 ? -1 : n;
            goto rflag;
        case '0':
            flags |= 0x20;
            goto rflag;
        case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            n = 0;
            do {
                n = n * 10 + (s32)(*fmt++ - '0');
            } while ((u32)(ch = *fmt) < 0x80 && (D_80049071[*(volatile u8 *)fmt] & 4));
            width = n;
            fmt--;
            goto rflag;
        case 'L':
            flags |= 2;
            goto rflag;
        case 'h':
            flags |= 4;
            goto rflag;
        case 'l':
            flags |= 1;
            goto rflag;
        case 'c':
            *(cp = buf) = VA_ARG(ap, s32);
            size = 1;
            sign = 0;
            break;
        case 'D':
            flags |= 1;
        case 'd':
        case 'i':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            if ((s32)_ulong < 0) {
                _ulong = -_ulong;
                sign = '-';
            }
            base = 10;
            goto number;
        case 'n':
            if (flags & 1) {
                *VA_ARG(ap, s32 *) = ret;
            } else if (flags & 4) {
                *VA_ARG(ap, s16 *) = ret;
            } else {
                *VA_ARG(ap, s32 *) = ret;
            }
            continue;
        case 'O':
            flags |= 1;
        case 'o':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            base = 8;
            goto nosign;
        case 'p':
            _ulong = VA_ARG(ap, s32);
            base = 16;
            goto nosign;
        case 's':
            if ((cp = VA_ARG(ap, char *)) == 0) {
                cp = D_80010418;
            }
            if (prec >= 0) {
                p = (char *)memchr((u8 *)cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec) {
                        size = prec;
                    }
                } else {
                    size = prec;
                }
            } else {
                size = strlen((s8 *)cp);
            }
            sign = 0;
            break;
        case 'U':
            flags |= 1;
        case 'u':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            base = 10;
            goto nosign;
        case 'X':
            xdigs = D_80010420;
        case 'x':
            _ulong = (flags & 1) ? VA_ARG(ap, s32) : (flags & 4) ? (s16)VA_ARG(ap, s32) : VA_ARG(ap, s32);
            base = 16;
            if ((flags & 8) && _ulong != 0) {
                flags |= 0x40;
            }
        nosign:
            sign = 0;
        number:
            if ((dprec = prec) >= 0) {
                flags &= ~0x20;
            }
            cp = buf + 40;
            if (_ulong != 0 || dprec != 0) {
                do {
                    *--cp = xdigs[_ulong % base];
                    _ulong /= base;
                } while (_ulong);
                xdigs = D_80010404;
                if ((flags & 8) && base == 8 && *(s8 *)cp != '0') {
                    *--cp = '0';
                }
            }
            size = buf + 40 - cp;
            break;
        case '\0':
            goto done;
        default:
            goto put_s;
        }
        fieldsz = size + fpprec;
        if (sign) {
            fieldsz++;
        }
        if (flags & 0x40) {
            fieldsz += 2;
        }
        realsz = fieldsz > dprec ? fieldsz : dprec;
        if ((flags & 0x30) == 0 && width) {
            for (n = realsz; n < width; n++) {
                Debug_PutChar(' ');
            }
        }
        ch = sign;
        if (ch) {
            ((void (*)(s32))Debug_PutChar)(ch);
        }
        if (flags & 0x40) {
            Debug_PutChar('0');
            Debug_PutChar(*fmt);
        }
        if ((flags & 0x30) == 0x20) {
            for (n = realsz; n < width; n++) {
                Debug_PutChar('0');
            }
        }
        for (n = fieldsz; n < dprec; n++) {
            Debug_PutChar('0');
        }
        for (n = size; --n >= 0;) {
            Debug_PutChar(*cp++);
        }
        while (--fpprec >= 0) {
            Debug_PutChar('0');
        }
        if (flags & 0x10) {
            for (n = realsz; n < width; n++) {
                Debug_PutChar(' ');
            }
        }
        ret += realsz > width ? realsz : width;
        continue;
    done:
        Debug_FlushOut();
        return ret;
    put_s:
        ret++;
        Debug_PutChar(*fmt);
        continue;
    put:
        ((void (*)(s32))Debug_PutChar)(ch);
    }
}


u8 *memchr(u8 *p, s32 c, s32 n) {
    u8 *r = 0;

    if (p == 0) {
        goto end;
    }
    if (n <= 0) {
        goto end;
    }
    n--;
    goto test;
found:
    r = p - 1;
    goto end;
test:
    if (n < 0) {
        r = 0;
        goto end;
    }
    c &= 0xFF;
loop:
    if (*p++ == c) {
        goto found;
    }
    if (--n >= 0) {
        goto loop;
    }
    r = 0;
end:
    return r;
}


void Debug_PutChar(s8 c) {
    switch (c) {
    case 10:
        Debug_PutChar(0xD);
        D_80049060 = 0;
        break;
    case 9:
        do {
            Debug_PutChar(0x20);
        } while (D_80049060 & 7);
        return;
    default:
        if (D_80049071[(u8)c] & 0x97) {
            D_80049060++;
        }
        break;
    }
    if (D_80049064 >= 0x20) {
        write(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
    D_800618B0[D_80049064++] = c;
}


void Debug_FlushOut(void) {
    if (D_80049064 > 0) {
        write(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
}

void func_8002A87C(s8 c) {
    switch (c) {
    case 10:
        Debug_PutChar(0xD);
        D_80049060 = 0;
        break;
    case 9:
        for (;;) {
            Debug_PutChar(0x20);
            if ((D_80049060 & 7) == 0) {
                goto flush;
            }
        }
    default:
        if (D_80049071[(u8)c] & 0x97) {
            D_80049060++;
        }
        break;
    }
    if (D_80049064 >= 0x20) {
        write(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
    {
        s32 n = D_80049064;

        D_800618B0[n] = c;
        D_80049064 = n + 1;
    }
flush:
    if (D_80049064 > 0) {
        write(1, D_800618B0, D_80049064);
        D_80049064 = 0;
    }
}

ASM_SOURCE("src/main/asm/libapi", write);

s32 strlen(s8 *s) {
    s32 n = 0;
    s32 r = 0;

    if (s != 0) {
        while (*s++ != 0) {
            n++;
        }
        r = n;
    }
    return r;
}


DrawEnv *SetDefDrawEnv(DrawEnv *env, s32 x, s32 y, s32 w, s32 h) {
    s32 mode = GetVideoMode();

    env->clip_x = x;
    env->clip_y = y;
    env->clip_w = w;
    env->tw_x = 0;
    env->tw_y = 0;
    env->tw_w = 0;
    env->tw_h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip_h = h;
    if (mode) {
        env->dfe = h < 0x121;
    } else {
        env->dfe = h < 0x101;
    }
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tpage = 10;
    env->isbg = 0;
    return env;
}

Rec2AAB4 *SetDefDispEnv(Rec2AAB4 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->field_0 = arg1;
    arg0->field_2 = arg2;
    arg0->field_4 = arg3;
    arg0->field_8 = 0;
    arg0->field_A = 0;
    arg0->field_C = 0;
    arg0->field_E = 0;
    arg0->field_11 = 0;
    arg0->field_10 = 0;
    arg0->field_13 = 0;
    arg0->field_12 = 0;
    arg0->field_6 = arg4;
    return arg0;
}

void AddPrim(unsigned int *a0, unsigned int *a1) {
    *a1 = (*a1 & 0xFF000000) | (*a0 & 0x00FFFFFF);
    *a0 = (*a0 & 0xFF000000) | ((unsigned int)a1 & 0x00FFFFFF);
}

void SetPolyF4(u8 *a0) {
    a0[3] = 5;
    a0[7] = 0x28;
}

void SetDrawMove(DrMove2AB54 *p, Rect2AB54 *r, s32 x, s32 y) {
    s32 len = 5;

    if (r->w == 0 || r->h == 0) {
        len = 0;
    }
    p->code[0] = 0x01000000;
    p->code[1] = 0x80000000;
    p->len = len;
    p->code[2] = *(u32 *)&r->x;
    p->code[3] = (y << 16) | (x & 0xFFFF);
    p->code[4] = *(u32 *)&r->w;
}

typedef struct {
    s16 x, y, w, h;
} Rect2ABB4;

typedef struct {
    u8 addr[3];
    u8 len;
    u32 code[2];
} DrMode2ABB4;

void SetDrawMode(DrMode2ABB4 *p, s32 dfe, s32 dtd, s32 tpage, Rect2ABB4 *tw) {
    p->len = 2;
    p->code[0] = 0xE1000000 | (dtd ? 0x200 : 0) | (dfe ? 0x400 : 0) | (tpage & 0x9FF);
    if (tw) {
        p->code[1] = 0xE2000000 | (((tw->y & 0xFF) >> 3) << 15) | (((tw->x & 0xFF) >> 3) << 10)
            | ((((-tw->h) & 0xFF) >> 3) << 5) | (((-tw->w) & 0xFF) >> 3);
    } else {
        p->code[1] = 0;
    }
}


void GsInitGraph(u16 a0, u16 a1, u16 a2, u16 a3, u16 a4) {
    func_8002ACC8(a0, a1, a2, a3, a4);
    func_8002BB84();
    D_8006198C = 0;
    func_8002AE4C(a0, a1);
    GsSetDrawBuffClip();
    GsSetDrawBuffOffset();
}

void func_8002ACC8(u16 x, u16 y, u16 flags, u16 dtd, u16 rgb24) {
    Rect2AB54 *r;
    s32 mode;
    s32 m;

    m = 0;
    if (((flags >> 4) & 3) == 3) {
        m = 3;
    }
    ResetGraph(m);
    D_80061908.ofs[0] = D_80061908.ofs[1] = 0;
    D_80061908.tw_h = 0;
    D_80061908.tw_w = 0;
    D_80061908.tw_y = 0;
    D_80061908.tw_x = 0;
    D_80061908.tpage = 0;
    D_80061908.dtd = dtd;
    D_80061908.dfe = 0;
    D_80061908.isbg = 0;
    PutDrawEnv(&D_80061908);
    D_80061968.disp.x = 0;
    D_80061968.disp.y = 0;
    D_80061968.disp.w = x;
    D_80061968.disp.h = y;
    r = &D_80061968.screen;
    r->x = 0;
    r->y = 0;
    r->w = 0;
    r->h = 0;
    mode = GetVideoMode();
    if (mode == 1) {
        D_80061968.screen.y = 0x18;
        D_80061968.pad0 = mode;
    }
    D_80061968.isinter = flags & 1;
    D_8006198E = flags & 4;
    D_80061968.isrgb24 = rgb24;
    PutDispEnv(&D_80061968);
}

void func_8002ADE4(s16 a0, s16 a1, s32 flags, u8 a3, u16 a4) {
    D_8006191C.field_0 = 0;
    D_8006191C.field_2 = a3;
    D_8006191C.field_3 = 0;
    D_8006191C.field_4 = 0;
    D_8006196C.field_0 = a0;
    D_8006196C.field_2 = a1;
    D_8006196C.field_C = flags & 1;
    D_8006198E = flags & 4;
    D_8006196C.field_D = a4;
    func_8002AE4C((u16)a0, (u16)a1, flags & 4);
}

/* y_div_x_inpb */
/* b_p */
void func_8002AE4C(a0, a1)
u16 a0;
u16 a1;
{
    s32 asp;
    BlkFill618D0 *p;
    Rect2AB54 *r;

    D_80061990 = a0;
    D_80061994 = a1;
    asp = (*(volatile s32 *)&D_80061994 << 14) / *(volatile s32 *)&D_80061990;
    do {
    D_80061A28.m[2][2] = D_80061A28.m[1][1] = D_80061A28.m[0][0] = 0x1000;
    D_80061A28.m[2][0] = D_80061A28.m[2][1] = D_80061A28.m[1][0] = D_80061A28.m[1][2] = D_80061A28.m[0][1] = D_80061A28.m[0][2] = 0;
    D_80061A28.t[0] = D_80061A28.t[1] = D_80061A28.t[2] = 0;
    (*(Mat1F668 *)&D_80061A48) = D_80061A28;
    } while (0);
    do {
    D_800619A8 = D_80061A28;
    D_800619A8.m[0][0] = D_800619A8.m[1][1] = D_800619A8.m[2][2] = 0;
    D_800619C8 = D_800619A8;
    } while (0);
    D_800618F8.field_0 = 0;
    D_800618F8.field_2 = 0;
    D_800618FC.field_0 = 0;
    D_800618FC.field_2 = 0;
    D_80061900.field_0 = D_80061900.field_2 = 0;
    r = &D_80061980;
    r->y = 0;
    (*(Mat1F668 *)&D_80061A48).m[1][1] = asp / 3;
    do {
    p = D_800618D0;
    r->x = 0;
    p->len = 3;
    p->code = 2;
    p++;
    p->len = 3;
    p->code = 2;
    } while (0);
    D_80061988 = 1;
    r->w = D_80061990;
    r->h = D_80061994;
}


void func_8002B06C(u8 r, u8 g, u8 b, Db2B06C *db) {
    s32 i;

    D_800618D0[D_8006198C].r = r;
    D_800618D0[D_8006198C].g = g;
    D_800618D0[D_8006198C].b = b;
    i = D_8006198C;
    D_800618D0[i].x0 = D_800618F0[i];
    D_800618D0[i].y0 = D_800618F4[i];
    D_800618D0[i].h = D_80061994;
    if (D_8006196C.field_D != 0) {
        D_800618D0[i].w = D_80061990 * 3 / 2;
    } else {
        D_800618D0[i].w = D_80061990;
    }
    AddPrim(db->ot, (unsigned int *)&D_800618D0[D_8006198C]);
}

void GsSetDrawBuffOffset() {
    s32 x;
    s32 y;

    if (D_8006198E != 0) {
        D_8006197E = 0;
        D_8006197C = 0;
        D_80061908.ofs[0] = D_80061900.field_0 + D_800618F0[D_8006198C];
        D_80061908.ofs[1] = D_80061900.field_2 + D_800618F4[D_8006198C];
        PutDrawEnv(&D_80061908);
    } else {
        x = D_80061900.field_0 + *(D_8006198C ? &D_800618F0[0] : &D_800618F0[1]);
        y = D_80061900.field_2 + *(D_8006198C ? &D_800618F4[0] : &D_800618F4[1]);
        SetGeomOffset(x, y);
        D_8006197C = x;
        D_8006197E = y;
    }
}


void GsSetDrawBuffClip(void) {
    DrawEnv *dst = &D_80061908;
    Rect2AB54 *src = &D_80061980;
    s32 dx = D_800618F0[D_8006198C];
    s32 dy = D_800618F4[D_8006198C];
    s32 x;
    s32 y;

    dst->clip_w = src->w;
    dst->clip_h = src->h;
    x = src->x;
    y = src->y;
    dst->clip_x = x + dx;
    dst->clip_y = y + dy;
    PutDrawEnv(dst);
}

void GsSetOffset(s32 a0, s32 a1) {
    s32 x;
    s32 y;

    if (D_8006198E != 0) {
        D_8006197E = 0;
        D_8006197C = 0;
        D_80061908.ofs[0] = D_800618F0[D_8006198C] + a0;
        D_80061908.ofs[1] = D_800618F4[D_8006198C] + a1;
        PutDrawEnv(&D_80061908);
    } else {
        x = a0 + *(D_8006198C ? &D_800618F0[0] : &D_800618F0[1]);
        y = a1 + *(D_8006198C ? &D_800618F4[0] : &D_800618F4[1]);
        SetGeomOffset(x, y);
        D_8006197C = x;
        D_8006197E = y;
    }
}


void GsInitCoordinate2(Coord1F668 *super, Coord1F668 *c) {
    c->coord = D_80061A28;
    c->super = super;
    c->flg = 0;
    if ((u32)super >= 2) {
        c->super->sub = c;
    }
}


extern void SetRotMatrix();
extern s32 SetTransMatrix();

s32 GsSetLsMatrix(s32 a0) {
    SetRotMatrix(a0);
    return SetTransMatrix(a0);
}
__asm__(".word 0\n");

void func_8002B4C4(void) {
    D_80061900.field_0 = D_80061990 / 2;
    D_80061900.field_2 = D_80061994 / 2;
    GsSetDrawBuffOffset(&D_80061900);
    D_800619A0 = 10;
    D_8006199C = 0;
    D_80061998 = 0x3FFF;
}

void GsSetProjection(s32 arg0) { SetGeomScreen(); }

s32 GsSetFlatLight(s32 idx, Blk16 *src) {
    S32 lm;
    S32 cm;
    s32 r;
    s32 g;
    s32 b;
    s32 len;

    r = src->r;
    g = src->g;
    b = src->b;
    lm = D_800619A8;
    Gfx_GetLightColorMatrix(&cm);
    len = SquareRoot0(src->x * src->x + src->y * src->y + src->z * src->z);
    if (len == 0) {
        return -1;
    }
    switch (idx) {
    case 0:
        lm.m[0][0] = -src->x * 4096 / len;
        lm.m[0][1] = -src->y * 4096 / len;
        lm.m[0][2] = -src->z * 4096 / len;
        cm.m[0][0] = (r << 12) / 255;
        cm.m[1][0] = (g << 12) / 255;
        cm.m[2][0] = (b << 12) / 255;
        break;
    case 1:
        lm.m[1][0] = -src->x * 4096 / len;
        lm.m[1][1] = -src->y * 4096 / len;
        lm.m[1][2] = -src->z * 4096 / len;
        cm.m[0][1] = (r << 12) / 255;
        cm.m[1][1] = (g << 12) / 255;
        cm.m[2][1] = (b << 12) / 255;
        break;
    case 2:
        lm.m[2][0] = -src->x * 4096 / len;
        lm.m[2][1] = -src->y * 4096 / len;
        lm.m[2][2] = -src->z * 4096 / len;
        cm.m[0][2] = (r << 12) / 255;
        cm.m[1][2] = (g << 12) / 255;
        cm.m[2][2] = (b << 12) / 255;
        break;
    }
    D_800619A8 = lm;
    Gfx_SetLightColorMatrix(&cm);
    return 0;
}


extern S32 D_800619C8;
extern void SetColorMatrix(S32 *);

void Gfx_SetLightColorMatrix(S32 *src) {
    D_800619C8 = *src;
    SetColorMatrix(src);
}
void Gfx_GetLightColorMatrix(S32 *dst) { *dst = D_800619C8; }

void GsSetLightMode(s32 a0) {
    switch (a0) {
    case 0:
        D_8006199C = 0;
        break;
    case 1:
        D_8006199C = a0;
        break;
    case 2:
        D_8006199C = a0;
        break;
    case 3:
        D_8006199C = a0;
        break;
    default:
        printf(D_80010624, a0);
        break;
    }
}

void GsSetAmbient(s32 arg0, s32 arg1, s32 arg2) { SetBackColor(arg0 >> 4, arg1 >> 4, arg2 >> 4); }

void func_8002BB84(void) {
    func_8002CE5C();
    SetFarColor(0, 0, 0);
    SetGeomOffset(0, 0);
    D_8006197E = 0;
    D_8006197C = 0;
}

void GsGetTimInfo(u32 *tim, TimInfo2BBD4 *out) {
    u32 flag = *tim;
    u32 *p;

    out->mode = flag;
    if ((flag >> 3) & 1) {
        tim++;
        p = tim + (*tim >> 2);
        tim++;
        out->crect.x = ((TimHalves *)tim)->lo;
        out->crect.y = ((TimHalves *)tim)->hi;
        tim++;
        out->crect.w = ((TimHalves *)tim)->lo;
        out->crect.h = ((TimHalves *)tim)->hi;
        tim++;
        out->caddr = tim;
        p++;
        out->prect.x = ((TimHalves *)p)->lo;
        out->prect.y = ((TimHalves *)p)->hi;
        p++;
        out->prect.w = ((TimHalves *)p)->lo;
        out->prect.h = ((TimHalves *)p)->hi;
        p++;
        out->paddr = p;
    } else {
        tim += 2;
        out->prect.x = ((TimHalves *)tim)->lo;
        out->prect.y = ((TimHalves *)tim)->hi;
        tim++;
        out->prect.w = ((TimHalves *)tim)->lo;
        out->prect.h = ((TimHalves *)tim)->hi;
        tim++;
        out->paddr = tim;
    }
}


void Math_MakeAxisRotMatrix(Mat1F668 *m, s16 s, s16 c, s8 axis) {
    *m = D_80061A28;
    switch (axis) {
    case 'X':
    case 'x':
        m->m[1][1] = c;
        m->m[2][2] = c;
        m->m[1][2] = -s;
        m->m[2][1] = s;
        break;
    case 'Y':
    case 'y':
        m->m[0][0] = c;
        m->m[2][2] = c;
        m->m[0][2] = s;
        m->m[2][0] = -s;
        break;
    case 'Z':
    case 'z':
        m->m[0][0] = c;
        m->m[1][1] = c;
        m->m[0][1] = -s;
        m->m[1][0] = s;
        break;
    }
}


void GsGetLs(Coord1F668 *coord, Mat1F668 *m) {
    Coord1F668 *p;
    s32 i;
    s32 j;
    Coord1F668 **stk;
    Coord1F668 **q;
    s32 t;

    p = coord;
    i = 0;
    j = 100;
    stk = D_80061A68;
    for (;;) {
        stk[i] = p;
        if (p->super == NULL) {
            if (p->flg == D_80061988 || p->flg == 0) {
                p->workm = p->coord;
                t = ((Stamp61988 *)&D_80061988)->stamp;
                *m = p->workm;
                p->flg = t;
                break;
            }
            if (j == 100) {
                *m = D_80061A68[0]->workm;
                i = 0;
            } else {
                i = j + 1;
                *m = stk[i]->workm;
            }
            break;
        }
        if (p->flg == D_80061988) {
            *m = p->workm;
            break;
        }
        if (p->flg == 0) {
            j = i;
        }
        p = p->super;
        i++;
    }
    if (i > 0) {
        q = &D_80061A64[i];
        do {
            GsMulCoord3((ObjC0E4 *)m, (ArgC0E4 *)&(*q)->coord);
            i--;
            (*q)->workm = *m;
            (*q)->flg = D_80061988;
            q--;
        } while (i > 0);
    }
    GsMulCoord2(&D_80061A08, (ArgC0E4 *)m);
}


extern void ApplyMatrixLV(ObjC0E4 *, s32 *, s32 *);
extern void MulMatrix(ObjC0E4 *, ArgC0E4 *);
extern void MulMatrix2(ObjC0E4 *, ArgC0E4 *);

void GsMulCoord2(ObjC0E4 *a0, ArgC0E4 *a1) {
    s32 tmp[3];
    ApplyMatrixLV(a0, &a1->field_14, tmp);
    MulMatrix2(a0, a1);
    a1->field_14 = tmp[0] + a0->field_14;
    a1->field_18 = tmp[1] + a0->field_18;
    a1->field_1C = tmp[2] + a0->field_1C;
}

void GsMulCoord3(ObjC0E4 *a0, ArgC0E4 *a1) {
    s32 tmp[3];
    ApplyMatrixLV(a0, &a1->field_14, tmp);
    MulMatrix(a0, a1);
    a0->field_14 = tmp[0] + a0->field_14;
    a0->field_18 = tmp[1] + a0->field_18;
    a0->field_1C = tmp[2] + a0->field_1C;
}

s32 GsSetRefView2(Ctx19214 *c) {
    Mat1F668 m0;
    Mat1F668 m;
    ObjC0E4 o;
    ObjC0E4 o0;
    s32 v[3];
    u32 d;
    u32 x;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 e;
    s16 a;
    s16 b;
    s32 ret;

    D_80061A08 = D_80061A48;
    Math_MulMatrixRotZ(&D_80061A08, -c->field_18);
    dx = c->field_C - c->field_0;
    dy = c->field_10 - c->field_4;
    dz = c->field_14 - c->field_8;
    d = dx * dx + dy * dy + dz * dz;
    ret = 1;
    if (d != 0) {
        dy = c->field_4 - c->field_10;
        x = dy * dy;
        e = 12 - Gte_CountLeadingZeros(x);
        if (e < 0) {
            a = -((c->field_4 - c->field_10) << 12) / SquareRoot0(d);
        } else if (c->field_4 - c->field_10 >= 0) {
            a = -func_8002CDB8((x << (12 - e)) / (d >> e));
        } else {
            a = func_8002CDB8((x << (12 - e)) / (d >> e));
        }
        dx = c->field_C - c->field_0;
        dz = c->field_14 - c->field_8;
        x = dx * dx + dz * dz;
        e = 12 - Gte_CountLeadingZeros(x);
        if (e < 0) {
            b = (SquareRoot0(x) << 12) / SquareRoot0(d);
        } else {
            b = func_8002CDB8((x << (12 - e)) / (d >> e));
        }
        Math_MakeAxisRotMatrix(&m, a, b, 0x78);
        MulMatrix(&D_80061A08, (ArgC0E4 *)&m);
        if (x != 0) {
            d = x;
            dx = c->field_C - c->field_0;
            x = dx * dx;
            e = 12 - Gte_CountLeadingZeros(x);
            if (e < 0) {
                a = -((c->field_C - c->field_0) << 12) / SquareRoot0(d);
            } else if (c->field_C - c->field_0 >= 0) {
                a = -func_8002CDB8((x << (12 - e)) / (d >> e));
            } else {
                a = func_8002CDB8((x << (12 - e)) / (d >> e));
            }
            dz = c->field_14 - c->field_8;
            x = dz * dz;
            e = 12 - Gte_CountLeadingZeros(x);
            if (e < 0) {
                b = ((c->field_14 - c->field_8) << 12) / SquareRoot0(d);
            } else if (c->field_14 - c->field_8 >= 0) {
                b = func_8002CDB8((x << (12 - e)) / (d >> e));
            } else {
                b = -func_8002CDB8((x << (12 - e)) / (d >> e));
            }
            Math_MakeAxisRotMatrix(&m, a, b, 0x79);
            MulMatrix(&D_80061A08, (ArgC0E4 *)&m);
        }
        v[0] = -c->field_0;
        v[1] = -c->field_4;
        v[2] = -c->field_8;
        ApplyMatrixLV(&D_80061A08, v, &D_80061A08.field_14);
        if (c->field_1C != NULL) {
            GsGetLw(c->field_1C, &m);
            TransposeMatrix((Obj2D704 *)&m, (Obj2D704 *)&o);
            ApplyMatrixLV(&o, &m.t[0], v);
            o.field_14 = -v[0];
            o.field_18 = -v[1];
            o.field_1C = -v[2];
            GsMulCoord2(&D_80061A08, (ArgC0E4 *)&o);
            D_80061A08 = o;
        }
        D_800619E8 = D_80061A08;
        ret = 0;
    }
    return ret;
}


extern s32 func_8002CBC4(s32);
extern s32 rsin(s32);

void Math_MulMatrixRotZ(ObjC0E4 *a0, s32 a1) {
    ArgC0E4 mtx;
    s32 a = a1 / 360;
    s32 c = func_8002CBC4(a);
    s32 s = rsin(a);
    if (a1 == 0) {
        return;
    }
    mtx.m[0][0] = c;
    mtx.m[0][1] = -s;
    mtx.m[0][2] = 0;
    mtx.m[1][0] = s;
    mtx.m[1][1] = c;
    mtx.m[1][2] = 0;
    mtx.m[2][0] = 0;
    mtx.m[2][1] = 0;
    mtx.m[2][2] = 0x1000;
    mtx.field_14 = 0;
    mtx.field_18 = 0;
    mtx.field_1C = 0;
    MulMatrix(a0, &mtx);
}
__asm__(".word 0\n.word 0\n.word 0\n");

void GsGetLw(Coord1F668 *coord, Mat1F668 *m) {
    Coord1F668 *p;
    s32 i;
    s32 j;
    Coord1F668 **stk;
    Coord1F668 **q;
    s32 t;

    p = coord;
    i = 0;
    j = 100;
    stk = D_80061A68;
    for (;;) {
        stk[i] = p;
        if (p->super == NULL) {
            if (p->flg == D_80061988 || p->flg == 0) {
                p->workm = p->coord;
                t = ((Stamp61988 *)&D_80061988)->stamp;
                *m = p->workm;
                p->flg = t;
                break;
            }
            if (j == 100) {
                *m = D_80061A68[0]->workm;
                i = 0;
            } else {
                i = j + 1;
                *m = stk[i]->workm;
            }
            break;
        }
        if (p->flg == D_80061988) {
            *m = p->workm;
            break;
        }
        if (p->flg == 0) {
            j = i;
        }
        p = p->super;
        i++;
    }
    if (i > 0) {
        q = &D_80061A64[i];
        do {
            GsMulCoord3((ObjC0E4 *)m, (ArgC0E4 *)&(*q)->coord);
            i--;
            (*q)->workm = *m;
            (*q)->flg = D_80061988;
            q--;
        } while (i > 0);
    }
}


s32 rsin(s32 arg0) {
    if (arg0 < 0) {
        return -sin_1(-arg0 & 0xFFF);
    }
    return sin_1(arg0 & 0xFFF);
}

extern s16 D_80049110[];
extern s16 D_80048110[];

s32 sin_1(s32 a) {
    if (a <= 0x800) {
        if (a <= 0x400) {
            return D_80049110[a];
        }
        return D_80049110[0x800 - a];
    }
    if (a <= 0xC00) {
        return -D_80048110[a];
    }
    return -D_80049110[0x1000 - a];
}


extern s16 D_80047910[];
extern s16 D_80048910[];
extern s16 D_80049110[];

s32 func_8002CBC4(s32 a) {
    if (a < 0) {
        a = -a;
    }
    a &= 0xFFF;
    if (a <= 0x800) {
        if (a <= 0x400) {
            return D_80049110[0x400 - a];
        }
        return -D_80048910[a];
    }
    if (a <= 0xC00) {
        return -D_80049110[0xC00 - a];
    }
    return D_80047910[a];
}


s32 func_8002CC64(s32 a) {
    s32 v[2][8];
    s32 i;
    s32 *yb;
    s32 *p;
    s32 *q;
    s32 xx, yy, nx, ny;

    i = 1;
    yb = &v[1][1];
    q = &v[1][2];
    p = &v[0][1];
    v[0][1] = a + 0x5D50AD;
    v[1][1] = a - 0x5D50AD;
    for (; i < 7; q++, i++, p++) {
        if (i != 4) {
            if (p[8] >= 0) {
                p[1] = p[0] - (p[8] >> i);
                *q = p[8] - (p[0] >> i);
            } else {
                p[1] = p[0] + (p[8] >> i);
                yb[i] = p[8] + (p[0] >> i);
            }
        } else {
            yy = v[1][4];
            if (yy >= 0) {
                nx = v[0][4] - (yy >> 4);
                ny = yy - (v[0][4] >> 4);
                v[0][4] = nx;
                v[1][4] = ny;
                if (ny >= 0) {
                    v[0][5] = nx - (ny >> 4);
                    v[1][5] = ny - (nx >> 4);
                } else {
                    v[0][5] = nx + (ny >> 4);
                    v[1][5] = ny + (nx >> 4);
                }
            } else {
                nx = v[0][4] + (yy >> 4);
                ny = yy + (v[0][4] >> 4);
                v[0][4] = nx;
                v[1][4] = ny;
                if (ny >= 0) {
                    v[0][5] = nx - (ny >> 4);
                    v[1][5] = ny - (nx >> 4);
                } else {
                    v[0][5] = nx + (ny >> 4);
                    v[1][5] = ny + (nx >> 4);
                }
            }
        }
    }
    return v[0][7];
}

extern s32 Gte_CountLeadingZeros(s32);
extern s32 func_8002CC64(s32);

s32 func_8002CDB8(s32 a0) {
    s32 e, sh, x;
    if (a0 == 0) {
        return 0;
    }
    e = 8 - Gte_CountLeadingZeros(a0);
    if (e >= 0) {
        sh = e >> 1;
        x = a0 >> (sh << 1);
    } else {
        sh = (e >> 1) + 1;
        x = a0 << (-(sh << 1));
    }
    sh -= 6;
    if (sh >= 0) {
        return func_8002CC64(x) << sh;
    }
    return func_8002CC64(x) >> (-sh);
}
__asm__(".word 0\n");

ASM_SOURCE("src/main/asm/crt0", func_8002CE54);

ASM_SOURCE("src/main/asm/libgte", func_8002CE5C);

ASM_SOURCE("src/main/asm/libgte", SquareRoot0);

ASM_SOURCE("src/main/asm/libgte", ApplyMatrixLV);

ASM_SOURCE("src/main/asm/libgte", func_8002D0D4);

ASM_SOURCE("src/main/asm/libgte", func_8002D178);

ASM_SOURCE("src/main/asm/libgte", MulMatrix);

ASM_SOURCE("src/main/asm/libgte", MulMatrix2);

ASM_SOURCE("src/main/asm/libgte", ApplyMatrixSV);

ASM_SOURCE("src/main/asm/libgte", ScaleMatrix);

ASM_SOURCE("src/main/asm/libgte", SetRotMatrix);

ASM_SOURCE("src/main/asm/libgte", SetColorMatrix);

ASM_SOURCE("src/main/asm/libgte", SetTransMatrix);

ASM_SOURCE("src/main/asm/libgte", SetBackColor);

ASM_SOURCE("src/main/asm/libgte", SetFarColor);

ASM_SOURCE("src/main/asm/libgte", SetGeomOffset);

ASM_SOURCE("src/main/asm/libgte", SetGeomScreen);

ASM_SOURCE("src/main/asm/libgte", RotTransPers);

Obj2D704 *TransposeMatrix(Obj2D704 *src, Obj2D704 *dst) {
    s32 a;
    s32 b;
    s32 c;
    s32 e;
    s32 x;

    a = src->f0.w;
    b = src->f4.w;
    dst->f4.w = a;
    dst->f0.w = b;
    dst->f0.h = a;
    c = src->f8.w;
    e = src->fC.w;
    dst->fC.w = c;
    dst->f8.w = e;
    dst->fC.h = b;
    dst->f8.h = c;
    x = src->f10;
    dst->f4.h = e;
    dst->f10 = x;
    return dst;
}


ASM_SOURCE("src/main/asm/libgte", func_8002D744);

s32 ratan2(s32 y, s32 x) {
    s32 c;
    s32 r;
    s32 s1 = 0;
    s32 s2 = 0;

    if (x < 0) {
        s1 = 1;
        x = -x;
    }
    if (y < 0) {
        s2 = 1;
        y = -y;
    }
    if (x == 0 && y == 0) {
        return 0;
    }
    if (y < x) {
        if (y & 0x7FE00000) {
            c = y / (x >> 10);
        } else {
            c = (y << 10) / x;
        }
        c = D_8004DDC0[c];
    } else {
        if (x & 0x7FE00000) {
            c = x / (y >> 10);
        } else {
            c = (x << 10) / y;
        }
        c = 0x400 - D_8004DDC0[c];
    }
    if (s1) {
        c = 0x800 - c;
    }
    if (s2) {
        c = -c;
    }
    return c;
}


ASM_SOURCE("src/main/asm/libapi", func_8002DAC4);

ASM_SOURCE("src/main/asm/libapi", func_8002DB70);

ASM_SOURCE("src/main/asm/libapi", FlushCache);

ASM_SOURCE("src/main/asm/libgte", Gte_CountLeadingZeros);

void StSetRing(s32 arg0, s32 arg1) {
    D_80061B38 = arg0;
    D_80061B3C = arg1;
    StClearRing();
}

s32 CdInit(void) {
    s32 i;

    i = 4;
loop:
    if (func_8002DC94() != 1) {
        if (--i != -1) {
            goto loop;
        }
        printf(D_800106D4);
        return 0;
    }
    D_8004E6C8 = def_cbsync;
    D_8004E6CC = (s32)def_cbready;
    D_8004E5E0 = def_cbread;
    D_8004E5E4 = 0;
    return 1;
}


s32 func_8002DC94(void) {
    if (CD_init() != 0) {
        return 0;
    }
    return func_8002FDC8() == 0;
}

void def_cbsync(void) { DeliverEvent(0xF0000003, 0x20); }

void def_cbready(void) { DeliverEvent(0xF0000003, 0x40); }

void def_cbread(void) { DeliverEvent(0xF0000003, 0x40); }

ASM_SOURCE("src/main/asm/libapi", DeliverEvent);

s32 CdPosToInt(void *arg) {
    u8 *p = arg;

    return (((p[0] >> 4) * 10 + (p[0] & 0xF)) * 60
          + ((p[1] >> 4) * 10 + (p[1] & 0xF))) * 75
         + ((p[2] >> 4) * 10 + (p[2] & 0xF)) - 150;
}

extern s32 D_80061B98;
extern void func_8002DE68(void);

void CdRead2(s32 arg0) {
    u8 b = arg0;

    CdControl(0xE, &b, 0);
    if (arg0 & 0x100) {
        if (arg0 & 0x20) {
            D_80061B98 = 0;
        } else {
            D_80061B98 = 1;
        }
        CdDataCallback((s32)func_8002DF74);
        CdReadyCallback((s32)func_8002DE68);
    }
    CdControl(0x1B, 0, 0);
}

void func_8002DE68(void) { func_8002E2C4(); }

void StClearRing(void) {
    D_80061B24 = 0;
    D_80061B20 = 0;
    D_80061B1C = 0;
    D_80061B14 = 0;
    Cd_ClearStreamSlots(0, D_80061B3C);
    D_80061B04 = 0;
    D_80061AFC = 0;
    D_80061AF8 = 0;
}

void StUnSetRing(void) {
    EnterCriticalSection();
    if (D_8004E6E8 == 1) {
        func_80030A84(0);
        func_80030A64(0);
    } else {
        CdDataCallback(0);
        CdReadyCallback(0);
    }
    *D_8004E600 = 0;
    *D_8004E60C = 0;
    ExitCriticalSection();
}

void func_8002DF74(void) {
    Rec2DF74 *r = &((Rec2DF74 *)D_80061B38)[D_80061B20];
    void (*cb)(void);

    r->field_0 = 2;
    *(B4_2DF74 *)&D_80061B40 = r->field_1C;
    D_80061B44 = r->field_8;
    D_80061B20 = ((W1_2DF74 *)&D_80061B1C)->v;
    cb = ((F1_2DF74 *)&D_80061B50)->f;
    if (cb != 0) {
        cb();
    }
    D_80061B14 = 0;
}


extern s32 D_80061B98;
extern s32 D_80061B40;
extern s32 D_80061B44;

s32 func_8002E000(s32 arg0) {
    s32 t;
    if (D_80061B98 != 0) {
        return -1;
    }
    t = CdPosToInt(&D_80061B40);
    CdIntToPos(t + 1, arg0);
    return D_80061B44;
}
__asm__(".word 0\n.word 0\n.word 0\n");

void StSetStream(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    StSetMask(1, a1, a2);
    D_80061B28 = 0;
    D_80061B50 = a3;
    D_80061B00 = a0 & 1;
    D_80061B10 = 0;
    D_80061B08 = 0;
    D_80061AFC = 0;
    D_80061AF8 = 0;
    D_80061B54 = a4;
}

s32 StFreeRing(u32 *arg0) {
    s32 idx;
    s32 i;
    s32 ret = 1;
    u16 n;
    Rec2DF74 *r;

    idx = (arg0 - (u32 *)&((Rec2DF74 *)D_80061B38)[D_80061B3C]) / 504;
    r = &((Rec2DF74 *)D_80061B38)[idx];
    n = r->field_6;
    if (r->field_0 != 4) {
        goto end;
    }
    for (i = 0; i < (s16)n; i++) {
        ((Rec2DF74 *)*(volatile s32 *)&D_80061B38)[i + idx].field_0 = 0;
    }
    D_80061B24 = i + idx;
    ret = 0;
end:
    return ret;
}


void Cd_ClearStreamSlots(s32 first, s32 n) {
    u32 i;
    s32 *w;

    for (i = 0; i < (u32)n; i++) {
        w = &((Slot2E1A4 *)D_80061B38)[i + first].field_0;
        *w = 0;
    }
}

s32 StGetNext(Sect2E1E4 **a0, u16 **a1) {
    u16 *s;

    s = &((Slot2E1E4 *)D_80061B38)[D_80061B24].status;
    if (*s == 1) {
        D_80061B24 = 0;
        if (D_80061B2C != 0) {
            *s = 0;
        }
        s = &((Slot2E1E4 *)D_80061B38)[D_80061B24].status;
    }
    if (*(volatile u16 *)s != 2) {
        return 1;
    }
    *s = 4;
    *a0 = &((Sect2E1E4 *)&((Slot2E1E4 *)D_80061B38)[D_80061B3C])[D_80061B24];
    *a1 = s;
    return 0;
}

extern s32 D_80061B30, D_80061B0C, D_80061B2C;
void StSetMask(s32 a0, s32 a1, s32 a2) {
    D_80061B30 = a0;
    D_80061B0C = a1;
    D_80061B2C = a2;
}

extern volatile u32 *D_8004E690;
extern volatile u8 *D_8004E670;
extern volatile u8 *D_8004E67C;
extern volatile u8 *D_8004E678;
extern volatile u32 *D_8004E680;
extern volatile u32 *D_8004E684;
extern volatile u32 *D_8004E6A0;
extern s32 D_8004E6B8;
extern s32 D_80061B18;
extern volatile u16 *D_80061B58;
extern u32 *D_80061B34;
extern void CdReady(void);

void func_8002E2C4(void) {
    volatile Res2E2C4 r;
    Hdr2E2C4 hdr;
    u8 res[8];
    u32 i;
    s32 m;
    u32 *s;
    u32 *d;

    if (D_80061B14 == 1) {
        return;
    }
    if (D_80061B00 != 0 && (*D_8004E690 & 0x1000000)) {
        D_80061B04 = 1;
        if (D_80061B28 != 0) {
            D_80061B18++;
        }
        D_8004E6B8 = 1;
        return;
    }
    if (((s32 (*)(s32, u8 *))CdReady)(1, res) == 5) {
        return;
    }
    r.stat = res[0];
    r.intr = res[1];
    if (r.stat & 4) {
        D_8004E6B8 = 3;
        return;
    }
    D_80061B58 = &((Sect2E2C4 *)D_80061B38)[D_80061B1C].field_0;
    if (D_80061B58[0] != 0) {
        if (D_80061B28 != 0) {
            D_80061B18++;
        }
        D_8004E6B8 = 4;
        return;
    }
    *D_8004E670 = 0;
    *D_8004E67C = 0;
    *D_8004E670 = 0;
    *D_8004E67C = 0x80;
    *D_8004E680 = 0x20943;
    *D_8004E684 = 0x1323;
    if (D_80061B98 == 0) {
        for (i = 0; i < 4; i++) {
            hdr.b[i] = *D_8004E678;
        }
        for (i = 0; i < 8; i++) {
            *D_8004E678;
        }
    }
    m = 0x11000000;
    if (D_80061B28 != 0) {
        ((void (*)(void *, s32, s32, s32))Mem_CopyWords)((void *)D_80061B58, D_80061B28 + D_80061B18 * 2048, 8, 0);
    } else {
        ((void (*)(s32, void *, s32, s32, s32, s32, s32))func_8002EC0C)(3, (void *)D_80061B58, 0, 8, m, 0, 0);
    }
    while (*D_8004E6A0 & 0x1000000) {
    }
    ((Sect2E2C4 *)D_80061B58)->field_1C = hdr;
    *D_8004E680 = 0x20843;
    *D_8004E684 = 0x1325;
    if (D_80061B30 == 1 && D_80061B0C != 0) {
        if (D_80061B0C != D_80061B58[4]) {
            D_80061B58[0] = 0;
            if (D_80061B28 != 0) {
                D_80061B18++;
            }
            return;
        }
        D_80061B30 = 0;
    }
    if (D_80061B58[0] != 0x160 || ((D_80061B58[1] >> 10) & 0x1F) != D_80061B10) {
        if (D_80061B28 != 0) {
            D_80061B18 = 0;
        } else {
            D_80061B58[0];
        }
        D_8004E6B8 = 5;
        D_80061B58[0] = 0;
        return;
    }
    if (D_80061AFC != D_80061B58[2] || (D_80061AF8 != 0 && D_80061AF8 != D_80061B58[4])) {
        D_80061AF8 = 0;
        D_80061AFC = 0;
        Cd_ClearStreamSlots(D_80061B20, D_80061B1C - D_80061B20);
        D_80061B1C = D_80061B20;
        D_80061B58[0] = 0;
        if (D_80061B28 != 0) {
            D_80061B18++;
        }
        D_8004E6B8 = 6;
        return;
    }
    if (D_80061B58[2] == 0) {
        D_80061AFC = 0;
        D_80061AF8 = D_80061B58[4];
        if (D_80061B2C != 0 && (u32)D_80061AF8 >= (u32)D_80061B2C) {
            D_80061AF8 = 0;
            D_80061AFC = 0;
            Cd_ClearStreamSlots(D_80061B20, D_80061B1C - D_80061B20);
            D_80061B1C = D_80061B20;
            D_80061B58[0] = 0;
            D_80061B30 = 1;
            if (D_80061B54 != 0) {
                ((void (*)(void))D_80061B54)();
            }
            if (D_80061B28 != 0) {
                D_80061B18++;
            }
            D_8004E6B8 = 7;
            return;
        }
        if ((u32)(D_80061B3C - D_80061B1C - 1) < D_80061B58[3]) {
            if (D_80061B2C == 0) {
                D_80061B58[0] = 1;
                D_80061B30 = 1;
                if (D_80061B54 != 0) {
                    ((void (*)(void))D_80061B54)();
                }
                if (D_80061B28 != 0) {
                    D_80061B18++;
                }
                D_8004E6B8 = 8;
                return;
            }
            if (*(s16 *)D_80061B38 != 0) {
                D_80061B58[0] = 0;
                if (D_80061B28 != 0) {
                    D_80061B18++;
                }
                D_8004E6B8 = 9;
                return;
            }
            D_80061B58[0] = 1;
            d = (u32 *)D_80061B38;
            s = (u32 *)D_80061B58;
            D_80061B1C = 0;
            for (i = 0; i < 8; i++) {
                *d++ = *s++;
            }
            D_80061B58 = &((Sect2E2C4 *)D_80061B38)->field_0;
        }
        D_80061B20 = D_80061B1C;
    }
    D_8004E6B8 = 10;
    D_80061AFC++;
    D_80061B34 = (u32 *)((Sect2E2C4 *)D_80061B38 + D_80061B3C) + D_80061B1C * 504;
    if (D_80061B00 != 0) {
        m = 0x11000000;
        *D_8004E680 = 0x20943;
        *D_8004E684 = 0x1323;
    } else {
        m = 0x11400100;
        *D_8004E680 = 0x21020843;
    }
    if (D_80061B58[3] - 1 == D_80061B58[2]) {
        D_80061B14 = 1;
        if (D_80061B28 != 0) {
            ((void (*)(void *, s32, s32, s32))Mem_CopyWords)(D_80061B34, D_80061B28 + D_80061B18 * 2048 + 0x20, 0x1F8, 1);
            D_80061B18++;
        } else {
            ((void (*)(s32, void *, s32, s32, s32, s32, s32))func_8002EC0C)(3, D_80061B34, 0, 0x1F8, m, 1, 0);
        }
        D_80061AFC = 0;
        D_80061AF8 = 0;
        D_80061B10 = D_80061B08;
    } else {
        if (D_80061B28 != 0) {
            ((void (*)(void *, s32, s32, s32))Mem_CopyWords)(D_80061B34, D_80061B28 + D_80061B18 * 2048 + 0x20, 0x1F8, 0);
            D_80061B18++;
        } else {
            ((void (*)(s32, void *, s32, s32, s32, s32, s32))func_8002EC0C)(3, D_80061B34, 0, 0x1F8, m, 0, 0);
        }
    }
    *D_8004E684 = 0x1325;
    D_80061B58[0] = 3;
    D_80061B1C++;
    if (D_80061B28 != 0 && D_80061B14 != 0) {
        func_8002DF74();
    }
}


void Mem_CopyWords(s32 *dst, s32 *src, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        *dst++ = *src++;
    }
}

void func_8002EC0C(s32 ch, u32 madr, s32 hi, s32 lo, u32 chcr, u8 mode) {
    volatile s32 dummy;
    volatile u32 *p;
    s32 off;
    s32 i;
    volatile Reg2EC0C *r;
    u8 v;
    s32 bit;

    i = 0;
    off = ch * 16;
    while (*(volatile u32 *)(off + 0x1F801088) & 0x01000000) {
        if (i == 0x10000) {
            printf(D_800106F4, *(volatile u32 *)(off + 0x1F801088));
            break;
        }
        i++;
    }
    if (mode == 1) {
        r = D_8004E68C;
        v = r->b[2] | (1 << ch);
    } else {
        r = D_8004E68C;
        v = r->b[2] & ~(1 << ch);
    }
    r->b[2] = v;
    do {
        dummy = D_8004E68C->w;
    } while (0);
    do {
        bit = 1 << (ch * 4 + 3);
    } while (0);
    p = (volatile u32 *)(ch * 16 + 0x1F801080);
    *D_8004E688 |= bit;
    *p++ = madr;
    *p++ = (hi << 16) | lo;
    while (!(*D_8004E670 & 0x40)) {
    }
    *p = chcr;
    dummy = *p;
}

extern u8 *D_8004E998;

static inline void cd_memcpy2EDB4(u8 *dst, u8 *src, u32 n) {
    if (dst != 0) {
        while (n--) {
            *dst++ = *src++;
        }
    }
}

s32 getintr(void) {
    volatile u8 r;
    u8 result[8];
    s32 i;
    s32 j;
    s32 err;

    *D_8004E98C = 1;
    r = *D_8004E990 & 7;
    err = 0;
    if (r == 0) {
        return 0;
    }
    while (r != (*D_8004E990 & 7)) {
        r = *D_8004E990 & 7;
    }
    for (i = 0; i < 8; i++) {
        if (!(*D_8004E98C & 0x20)) {
            break;
        }
        result[i] = *D_8004E998;
    }
    for (j = i; j < 8; j++) {
        result[j] = 0;
    }
    *D_8004E98C = 1;
    *D_8004E990 = 7;
    *D_8004E99C = 7;
    if (r != 3 || D_8004E88C[D_8004E6E5] != 0) {
        if (!(D_8004E6D4 & 0x10) && (result[0] & 0x10)) {
            D_8004E6DC++;
        }
        D_8004E6D4 = result[0] & 0xFF;
        D_8004E6D8 = result[1];
        err = D_8004E6D4 & 0x1D;
    }
    if (r == 5 && D_8004E6D0 >= 3) {
        printf(D_8001087C);
        if (D_8004E6D0 >= 3) {
            printf(D_80010888, D_8004E6EC[D_8004E6E5], D_8004E6D4, D_8004E6D8);
        }
    }
    switch (r) {
    case 3:
        if (err) {
            ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = 5;
            cd_memcpy2EDB4(D_80061B68, result, 8);
            return 2;
        } else if (D_8004E78C[D_8004E6E5] != 0) {
            ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = 3;
            cd_memcpy2EDB4(D_80061B68, result, 8);
            return 1;
        } else {
            ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = 2;
            cd_memcpy2EDB4(D_80061B68, result, 8);
            return 2;
        }
    case 2:
        D_8004E9A4.field_0 = err ? 5 : 2;
        cd_memcpy2EDB4(D_80061B68, result, 8);
        return 2;
    case 1:
        if (err && i == 1) {
            err = 0;
        }
        ((volatile Cd4E9A4 *)&D_8004E9A4)->field_1 = err ? 5 : 1;
        cd_memcpy2EDB4(D_80061B70, result, 8);
        *D_8004E98C = 0;
        *D_8004E990 = 0;
        return 4;
    case 4:
        ((volatile Cd4E9A4 *)&D_8004E9A4)->field_1 = ((volatile Cd4E9A4 *)&D_8004E9A4)->field_2 = 4;
        cd_memcpy2EDB4(D_80061B78, result, 8);
        cd_memcpy2EDB4(D_80061B70, result, 8);
        return 4;
    case 5:
        ((volatile Cd4E9A4 *)&D_8004E9A4)->field_0 = ((volatile Cd4E9A4 *)&D_8004E9A4)->field_1 = 5;
        cd_memcpy2EDB4(D_80061B68, result, 8);
        cd_memcpy2EDB4(D_80061B70, result, 8);
        return 6;
    default:
        Debug_PutString(D_800108A4);
        printf(D_800108B8, r);
        return 0;
    }
}


s32 CD_sync(a0, a1)
    s32 a0;
    u8 *a1;
{
    s32 r;
    s32 n;
    s32 e;
    s32 t;
    u8 s;
    s32 two;
    char **p0;
    s8 **com;
    char **intr;

    D_80061B80 = VSync(-1) + 0x3C0;
    com = D_8004E6EC;
    intr = D_8004E76C;
    two = 2;
    D_80061B84 = 0;
    D_80061B88 = D_800108D8;
    do {
        if (D_80061B80 < VSync(-1) || (n = D_80061B84++, n > 0x3C0000)) {
            Debug_PutString(D_80010850);
            p0 = &intr[D_8004E9A4.field_0];
            printf(D_80010860, D_80061B88, *(s8 * volatile *)&com[D_8004E6E5], *(char * volatile *)p0, intr[D_8004E9A4.field_1]);
            CD_flush();
            r = -1;
        } else {
            r = 0;
        }
        if (r != 0) {
            return -1;
        }
        if (CheckCallback() != 0) {
            s = *D_8004E98C & 3;
            while ((e = getintr()) != 0) {
                if (e & 4) {
                    if (D_8004E6CC != 0) {
                        ((void (*)(s32, u8 *))D_8004E6CC)(D_8004E9A4.field_1, D_80061B70);
                    }
                }
                if (e & 2) {
                    if (D_8004E6C8 != 0) {
                        ((void (*)(s32, u8 *))D_8004E6C8)(D_8004E9A4.field_0, D_80061B68);
                    }
                }
            }
            *D_8004E98C = s;
        }
        t = D_8004E9A4.field_0;
        if (t == two || t == 5) {
            D_8004E9A4.field_0 = two;
            cd_memcpy2EDB4(a1, D_80061B68, 8);
            return t;
        }
    } while (a0 == 0);
    return 0;
}


static __inline__ s32 func_8002F598_timeout(s8 **com, char **intr) {
    if (D_80061B80 < VSync(-1) || D_80061B84++ > 0x3C0000) {
        Debug_PutString(D_80010850);
        {
        char **p = &intr[D_8004E9A4.field_0];
        printf(D_80010860, D_80061B88, com[D_8004E6E5], *p, intr[D_8004E9A4.field_1]);
        }
        CD_flush();
        return -1;
    }
    return 0;
}

s32 CD_ready(mode, result)
s32 mode;
u8 *result;
{
    s32 r;
    s8 **com;
    char **intr;
    s32 ie;
    s32 st;
    s32 v;
    s32 n;
    u8 *src;
    u8 *dst;

    D_80061B80 = VSync(-1) + 0x3C0;
    D_80061B84 = 0;
    D_80061B88 = D_800108E0;
    com = D_8004E6EC;
    intr = D_8004E76C;
    do {
        if (func_8002F598_timeout(com, intr) != 0) {
            return -1;
        }
        if (CheckCallback() != 0) {
            st = *D_8004E98C & 3;
            while ((ie = getintr()) != 0) {
                if (ie & 4) {
                    if (D_8004E6CC != 0) {
                        ((void (*)(s32, u8 *))D_8004E6CC)(D_8004E9A4.field_1, D_80061B70);
                    }
                }
                if (ie & 2) {
                    if (D_8004E6C8 != 0) {
                        ((void (*)(s32, u8 *))D_8004E6C8)(D_8004E9A4.field_0, D_80061B68);
                    }
                }
            }
            *D_8004E98C = st;
        }
        if ((v = D_8004E9A4.field_2) != 0) {
            ((volatile Cd4E9A4 *)(Cd4E9A4 *)&D_8004E9A4)->field_2 = 0;
            src = D_80061B78;
            if (result != 0) {
                dst = result;
                for (n = 7; n != -1; n--) {
                    *dst++ = *src++;
                }
            }
            return v;
        }
        if ((v = D_8004E9A4.field_1) != 0) {
            ((volatile Cd4E9A4 *)(Cd4E9A4 *)&D_8004E9A4)->field_1 = 0;
            dst = result;
            src = D_80061B70;
            if (dst != 0) {
                for (n = 7; n != -1; n--) {
                    *dst++ = *src++;
                }
            }
            return v;
        }
    } while (mode == 0);
    return 0;
}


s32 CD_cw(com, param, result, async)
    u8 com;
    u8 *param;
    u8 *result;
    s32 async;
{
    s32 i;
    s32 r;
    s32 n;
    s32 e;
    s8 **cm;
    char **intr;
    char **p0;
    CdTbl4E80C *t;
    s32 *np;

    if (D_8004E6D0 >= 2) {
        printf(D_800108EC, D_8004E6EC[com]);
    }
    if (D_8004E80C.field_100[com] != 0 && param == 0) {
        if (D_8004E6D0 > 0) {
            printf(D_800108F4, D_8004E6EC[com]);
        }
        return -2;
    }
    CD_sync(0, 0);
    if (com == 2) {
        for (i = 0; i < 4; i++) {
            D_8004E6E0[i] = param[i];
        }
    }
    if (com == 0xE) {
        D_8004E6E4 = param[0];
    }
    D_8004E9A4.field_0 = 0;
    t = &D_8004E80C;
    if (t->field_0[com] != 0) {
        D_8004E9A4.field_1 = 0;
    }
    *D_8004E98C = 0;
    np = t->field_100;
    for (i = 0; i < np[com]; i++) {
        *D_8004E99C = param[i];
    }
    D_8004E6E5 = com;
    *(volatile u8 *)D_8004E998 = com;
    if (async == 0) {
        D_80061B80 = VSync(-1) + 0x3C0;
        D_80061B84 = 0;
        D_80061B88 = D_80010904;
        if (D_8004E9A4.field_0 == 0) {
            cm = D_8004E6EC;
            intr = D_8004E76C;
            do {
                if (D_80061B80 < VSync(-1) || (n = D_80061B84++, n > 0x3C0000)) {
                    Debug_PutString(D_80010850);
                    p0 = &intr[D_8004E9A4.field_0];
                    printf(D_80010860, D_80061B88, *(s8 * volatile *)&cm[D_8004E6E5], *(char * volatile *)p0, intr[D_8004E9A4.field_1]);
                    CD_flush();
                    r = -1;
                } else {
                    r = 0;
                }
                if (r != 0) {
                    return -1;
                }
                if (CheckCallback() != 0) {
                    com = *D_8004E98C & 3;
                    while ((e = getintr()) != 0) {
                        if (e & 4) {
                            if (D_8004E6CC != 0) {
                                ((void (*)(s32, u8 *))D_8004E6CC)(D_8004E9A4.field_1, D_80061B70);
                            }
                        }
                        if (e & 2) {
                            if (D_8004E6C8 != 0) {
                                ((void (*)(s32, u8 *))D_8004E6C8)(D_8004E9A4.field_0, D_80061B68);
                            }
                        }
                    }
                    *D_8004E98C = com;
                }
            } while (D_8004E9A4.field_0 == 0);
        }
        cd_memcpy2EDB4(result, D_80061B68, 8);
        r = 0;
        if (D_8004E9A4.field_0 == 5) {
            r = -1;
        }
        return r;
    }
    return 0;
}


extern u8 *D_8004E98C;
extern u8 *D_8004E99C;
extern u8 *D_8004E990;
extern u8 *D_8004E998;
s32 CD_vol(u8 *a0) {
    *D_8004E98C = 2;
    *D_8004E99C = a0[0];
    *D_8004E990 = a0[1];
    *D_8004E98C = 3;
    *D_8004E998 = a0[2];
    *D_8004E99C = a0[3];
    *D_8004E990 = 0x20;
    return 0;
}

void CD_flush(void) {
    *D_8004E98C = 1;
    while (*D_8004E990 & 7) {
        *D_8004E98C = 1;
        *D_8004E990 = 7;
        *D_8004E99C = 7;
    }
    {
        volatile Cd4E9A4 *p = &D_8004E9A4;

        p->field_1 = p->field_2 = 0;
        p->field_0 = 2;
    }
    *D_8004E98C = 0;
    *D_8004E990 = 0;
    *D_8004E994 = 0x1325;
}

s32 func_8002FDC8(void) {
    u8 v[4];

    if (D_8004E9A0[0xDC] == 0 && D_8004E9A0[0xDD] == 0) {
        D_8004E9A0[0xC0] = 0x3FFF;
        D_8004E9A0[0xC1] = 0x3FFF;
    }
    D_8004E9A0[0xD8] = 0x3FFF;
    D_8004E9A0[0xD9] = 0x3FFF;
    D_8004E9A0[0xD5] = 0xC001;
    v[2] = 0x80;
    v[0] = 0x80;
    v[3] = 0;
    v[1] = 0;
    *D_8004E98C = 2;
    *D_8004E99C = v[0];
    *D_8004E990 = v[1];
    *D_8004E98C = 3;
    *D_8004E998 = v[2];
    *D_8004E99C = v[3];
    *D_8004E990 = 0x20;
    return 0;
}

void CD_initintr(void) {
    D_8004E6CC = 0;
    D_8004E6C8 = 0;
    D_8004E6D8 = 0;
    D_8004E6D4 = 0;
    ResetCallback();
    InterruptCallback(2, Cd_IntrCallback);
}

s32 CD_init(void) {
    Debug_PutString(D_80010944);
    printf(D_80010950, D_8004E9A8);
    D_8004E6E5 = 0;
    D_8004E6E4 = 0;
    D_8004E6CC = 0;
    D_8004E6C8 = 0;
    D_8004E6D8 = 0;
    D_8004E6D4 = 0;
    ResetCallback();
    InterruptCallback(2, Cd_IntrCallback);
    *D_8004E98C = 1;
    while (*D_8004E990 & 7) {
        *D_8004E98C = 1;
        *D_8004E990 = 7;
        *D_8004E99C = 7;
    }
    {
        volatile Cd4E9A4 *p = &D_8004E9A4;

        p->field_1 = p->field_2 = 0;
        p->field_0 = 2;
    }
    *D_8004E98C = 0;
    *D_8004E990 = 0;
    *D_8004E994 = 0x1325;
    CD_cw(1, 0, 0, 0);
    if (D_8004E6D4 & 0x10) {
        CD_cw(1, 0, 0, 0);
    }
    if (CD_cw(10, 0, 0, 0) != 0) {
        return -1;
    }
    if (CD_cw(12, 0, 0, 0) != 0) {
        return -1;
    }
    if (CD_sync(0, 0) != 2) {
        return -1;
    }
    return 0;
}


s32 CD_datasync(s32 mode) {
    s32 t;
    s32 n;
    char **p0;
    s8 **q;
    char *c;
    s32 lim;
    s8 **com;
    volatile Cd4E9A4 *st;
    char **intr;

    D_80061B80 = VSync(-1) + 0x3C0;
    lim = 0x3C0000;
    com = D_8004E6EC;
    st = &D_8004E9A4;
    intr = D_8004E76C;
    D_80061B84 = 0;
    D_80061B88 = D_8001095C;
    do {
        if (D_80061B80 < VSync(-1) || (n = D_80061B84++, n > lim)) {
            Debug_PutString(D_80010850);
p0 = &intr[st->field_0];
printf(D_80010860, D_80061B88, *(s8 * volatile *)&com[D_8004E6E5], *(char * volatile *)p0, intr[st->field_1]);
            CD_flush();
            t = -1;
        } else {
            t = 0;
        }
        if (t != 0) {
            return -1;
        }
        if (!(*D_8004E9C0 & 0x01000000)) {
            return 0;
        }
    } while (mode == 0);
    return 1;
}


extern s32 D_8004E970;
void func_8003024C(s32 a0) {
    D_8004E970 = a0;
}

void Cd_IntrCallback(void) {
    u8 save = *D_8004E98C & 3;
    s32 st;
    void (*cb)(u8, u8 *);
    volatile u8 *p1 = &D_8004E9A4.field_1;
    volatile u8 *p0 = &D_8004E9A4.field_0;

loop:
    st = getintr();
    if (st != 0) {
        if (st & 4) {
            cb = (void (*)(u8, u8 *))D_8004E6CC;
            if (cb != 0) {
                cb(*p1, D_80061B70);
            }
        }
        if (st & 2) {
            cb = (void (*)(u8, u8 *))D_8004E6C8;
            if (cb != 0) {
                cb(*p0, D_80061B68);
            }
        }
        goto loop;
    }
    *D_8004E98C = save;
}

void Debug_PutString(s8 *s) {
    s8 c;

    if (!s) {
        s = D_80010974;
    }
    for (; (c = *s) != 0; ) {
        s++;
        Debug_PutChar(c);
    }
    Debug_FlushOut();
}

u8 *CdIntToPos(a0, a1)
s32 a0;
u8 *a1;
{
    s32 D = a0 + 0x96;
    s32 q1 = D / 75;
    s32 r1 = D % 75;
    s32 q2 = q1 / 60;
    s32 r2 = q1 % 60;
    a1[2] = (r1 / 10) * 16 + r1 % 10;
    a1[1] = (r2 / 10) * 16 + r2 % 10;
    a1[0] = (q2 / 10) * 16 + q2 % 10;
    return a1;
}
__asm__(".word 0\n.word 0\n.word 0\n");

u8 CdLastCom(void) {
    return D_8004E6E5;
}

s32 CdSetDebug(s32 a0) { s32 old = D_8004E6D0; D_8004E6D0 = a0; return old; }

void CdSync(void) { CD_sync(); }

void CdReady(void) { CD_ready(); }

void *CdSyncCallback(void *a0) { void *old = D_8004E6C8; D_8004E6C8 = a0; return old; }

s32 CdReadyCallback(s32 a0) { s32 old = D_8004E6CC; D_8004E6CC = a0; return old; }

s32 CdControl(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *param = arg1;
    u8 *result = arg2;
    s32 com = arg0;
    void *old = D_8004E6C8;
    s32 cnt;
    s32 *tbl = D_8004E9E0;
    s32 ret;

    for (cnt = 3; cnt != -1; cnt--) {
        s32 c = com & 0xFF;
        s32 *len = &tbl[c];
        ret = 0;
        D_8004E6C8 = 0;
        if (c != 1 && (*(u8 *)&D_8004E6D4 & 0x10)) {
            CD_cw(1, 0, 0, 0);
        }
        if (param == 0 || *len == 0 || CD_cw(2, param, result, 0) == 0) {
            D_8004E6C8 = old;
            if (CD_cw((u8)com, param, result, 0) == 0) {
                goto end;
            }
        }
    }
    D_8004E6C8 = old;
    ret = -1;
end:
    return ret + 1;
}

s32 CdControlF(s32 arg0, s32 arg1) {
    s32 param = arg1;
    s32 com = arg0;
    void *old = D_8004E6C8;
    s32 cnt;
    s32 *tbl = D_8004E9E0;
    s32 ret;

    for (cnt = 3; cnt != -1; cnt--) {
        s32 c = com & 0xFF;
        s32 *len = &tbl[c];
        ret = 0;
        D_8004E6C8 = 0;
        if (c != 1 && (*(u8 *)&D_8004E6D4 & 0x10)) {
            CD_cw(1, 0, 0, 0);
        }
        if (param == 0 || *len == 0 || CD_cw(2, param, 0, 0) == 0) {
            D_8004E6C8 = old;
            if (CD_cw((u8)com, param, 0, 1) == 0) {
                goto end;
            }
        }
    }
    D_8004E6C8 = old;
    ret = -1;
end:
    return ret + 1;
}


s32 CdControlB(u8 com, u8 *param, u8 *result) {
    void *old = D_8004E6C8;
    s32 n;
    s32 r;
    s32 *f;

    n = 3;
    do {
        D_8004E6C8 = 0;
        f = &D_8004E9E0[com];
        if (com != 1 && (*(u8 *)&D_8004E6D4 & 0x10)) {
            CD_cw(1, 0, 0, 0);
        }
        if (param == 0 || *f == 0 || CD_cw(2, param, result, 0) == 0) {
            D_8004E6C8 = old;
            if (CD_cw(com, param, result, 0) == 0) {
                r = 0;
                goto done;
            }
        }
    } while (--n != -1);
    r = -1;
    D_8004E6C8 = old;
done:
    if (r != 0) {
        return 0;
    }
    return CD_sync(0, result) == 2;
}


s32 CdGetSector(void *arg0, s32 arg1) {
    return CD_getsector() == 0;
}

s32 CD_getsector(s32 addr, s32 size) {
    *D_8004EA60 = 0;
    *D_8004EA64 = 0x80;
    *D_8004EA6C = 0x20943;
    *D_8004EA68 = 0x1323;
    *D_8004EA70 |= 0x8000;
    *D_8004EA78 = addr;
    *D_8004EA7C = size | 0x10000;
    while (!(*D_8004EA60 & 0x40)) {
    }
    *D_8004EA74 = 0x11000000;
    while (*D_8004EA74 & 0x01000000) {
    }
    *D_8004EA68 = 0x1325;
    return 0;
}

void CdDataCallback(s32 arg0) { DMACallback(3, arg0); }

extern s32 D_80061BA4;
int func_80030A64(int a0) {
    int old = D_80061BA4;
    D_80061BA4 = a0;
    return old;
}

void func_80030A84(s32 arg0) { DMACallback(3, arg0); }

s32 VSync(s32 mode) {
    volatile s32 buf;
    s32 status;
    s32 count;
    s32 v;
    s32 w;
    s32 m;

    status = *D_8004EA88;
    do {
        buf = *D_8004EA8C;
    } while (buf != *D_8004EA8C);
    count = (buf - D_8004EA90) & 0xFFFF;
    if (mode < 0) {
        return Sys_VSyncCount;
    }
    if (mode == 1) {
        return count;
    }
    m = mode;
    if (m > 0) {
        w = D_8004EA94 - 1;
        v = w + m;
    } else {
        v = D_8004EA94;
    }
    v_wait(v, m > 0 ? m - 1 : 0);
    status = *D_8004EA88;
    v_wait(Sys_VSyncCount + 1, 1);
    if (status & 0x400000) {
        while (((status ^ *D_8004EA88) & 0x80000000) == 0) {
        }
    }
    D_8004EA94 = Sys_VSyncCount;
    do {
        D_8004EA90 = *D_8004EA8C;
    } while (D_8004EA90 != *D_8004EA8C);
    return count;
}


void v_wait(s32 a0, s32 a1) {
    volatile s32 n = a1 << 15;

    while (Sys_VSyncCount < a0) {
        if (--n == -1) {
            Debug_PutString(D_80010984);
            ChangeClearPAD(0);
            ChangeClearRCnt(3, 0);
            return;
        }
    }
}

ASM_SOURCE("src/main/asm/libapi", ChangeClearPAD);

void ResetCallback(void) {
    D_8004FB80->fn_C();
}

void InterruptCallback(s32 arg0, void (*arg1)()) {
    D_8004FB80->fn_8(arg0, arg1);
}

void DMACallback(s32 arg0, s32 arg1) {
    D_8004FB80->fn_4(arg0, arg1);
}

void VSyncCallback(s32 arg0) {
    D_8004FB80->fn_14(4, arg0);
}

void VSyncCallbacks(s32 a0, s32 a1) {
    D_8004FB80->fn_14(a0, a1);
}

void StopCallback(void) {
    D_8004FB80->fn_10();
}

void RestartCallback(void) {
    D_8004FB80->fn_18();
}

u16 CheckCallback(void) {
    return D_8004EAFA;
}

u16 GetIntrMask(void) {
    return *Sys_IntrMaskPtr;
}

int SetIntrMask(int a0) {
    int old = *Sys_IntrMaskPtr;
    *Sys_IntrMaskPtr = a0;
    return old;
}

Obj4EAF8 *startIntr(void) {
    u16 *r;
    volatile u16 *q;

    if (D_8004EAF8.field_0 != 0) {
        return 0;
    }
    r = D_8004FB84;
    q = Sys_IntrMaskPtr;
    *q = 0;
    *r = *q;
    *D_8004FB8C = 0x33333333;
    memclr((s32 *)&D_8004EAF8, 0x41A);
    if (setjmp(D_8004EAF8.field_38) != 0) {
        trapIntr();
    }
    D_8004EAF8.field_38[1] = (s32)D_8004EAF8.stack_top;
    HookEntryInt(D_8004EAF8.field_38);
    D_8004EAF8.field_0 = 1;
    D_8004FB80->fn_14 = (void (*)())startIntrVSync();
    D_8004FB80->fn_4 = (void (*)())startIntrDMA();
    _96_remove();
    ExitCriticalSection();
    return &D_8004EAF8;
}

void trapIntr(void) {
    s32 i;
    u16 mask;

    if (D_8004EAF8.field_0 == 0) {
        printf(D_800109C8, *D_8004FB84);
        ReturnFromException();
    }
    D_8004EAF8.field_2 = 1;
    while ((mask = (D_8004EAF8.field_30 & *(volatile u16 *)D_8004FB84) & *(volatile u16 *)Sys_IntrMaskPtr) != 0) {
        for (i = 0; mask != 0 && i < 11; i++, mask >>= 1) {
            if (mask & 1) {
                *D_8004FB84 = ~(1 << i);
                if (((void (**)(void))D_8004EAF8.field_4)[i] != 0) {
                    ((void (**)(void))D_8004EAF8.field_4)[i]();
                }
            }
        }
    }
    if (*D_8004FB84 & *(volatile u16 *)Sys_IntrMaskPtr) {
        if (D_8004FB90++ > 0x800) {
            printf(D_800109E4, *D_8004FB84, *(volatile u16 *)Sys_IntrMaskPtr);
            D_8004FB90 = 0;
            *D_8004FB84 = 0;
        }
    } else {
        D_8004FB90 = 0;
    }
    D_8004EAFA = 0;
    ReturnFromException();
}

s32 setIntr(s32 ch, s32 val) {
    s32 *arr = D_8004EAF8.field_4;
    s32 *slot = &arr[ch];
    s32 old = *slot;
    Obj4EAF8 *p;
    s32 m;
    s32 o;
    s32 z;

    if (val != old) {
        p = &D_8004EAF8;
        if (p->field_0 != 0) {
            o = *Sys_IntrMaskPtr;
            *Sys_IntrMaskPtr = 0;
            m = (u16)o;
            if (val != 0) {
                *slot = val;
                m |= 1 << ch;
                p->field_30 |= 1 << ch;
            } else {
                *slot = 0;
                m &= ~(1 << ch);
                D_8004EAF8.field_30 &= ~(1 << ch);
            }
            if (ch == 0) {
                z = val == 0;
                ChangeClearPAD(z);
                ChangeClearRCnt(3, z);
            }
            if (ch == 4) {
                ChangeClearRCnt(0, val == 0);
            }
            if (ch == 5) {
                ChangeClearRCnt(1, val == 0);
            }
            if (ch == 6) {
                ChangeClearRCnt(2, val == 0);
            }
            *Sys_IntrMaskPtr = m;
        }
    }
    return old;
}

extern u16 *D_8004FB84;
extern void ResetEntryInt();

Obj4EAF8 *stopIntr(void) {
    Obj4EAF8 *p = &D_8004EAF8;
    volatile u16 *q;
    u16 *r;

    if (p->field_0 == 0) {
        return 0;
    }
    EnterCriticalSection();
    q = Sys_IntrMaskPtr;
    p->field_32 = *q;
    p->field_34 = *D_8004FB8C;
    r = D_8004FB84;
    *q = 0;
    *r = *q;
    *D_8004FB8C &= 0x77777777;
    ResetEntryInt();
    p->field_0 = 0;
    return p;
}


Obj4EAF8 *restartIntr(void) {
    Obj4EAF8 *p = &D_8004EAF8;

    if (p->field_0 != 0) {
        return 0;
    }
    HookEntryInt(p->field_38);
    p->field_0 = 1;
    *Sys_IntrMaskPtr = p->field_32;
    *D_8004FB8C = p->field_34;
    ExitCriticalSection();
    return p;
}

void memclr(s32 *arg0, s32 arg1) {
    s32 i;
    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

ASM_SOURCE("src/main/asm/crt0", func_80031394);

ASM_SOURCE("src/main/asm/libapi", _96_remove);

ASM_SOURCE("src/main/asm/libapi", ReturnFromException);

ASM_SOURCE("src/main/asm/libapi", ResetEntryInt);

ASM_SOURCE("src/main/asm/libapi", HookEntryInt);

ASM_SOURCE("src/main/asm/libc", setjmp);

ASM_SOURCE("src/main/asm/libc", longjmp);

extern void trapIntrVSync(void);
extern void setIntrVSync(s32 arg0, void (*arg1)(void));

void (*startIntrVSync(void))(s32, void (*)(void)) {
    *D_8004FBC4 = 0x100;
    Sys_VSyncCount = 0;
    memclr_vb(Sys_VSyncCallbacks, 8);
    InterruptCallback(0, trapIntrVSync);
    return setIntrVSync;
}

void trapIntrVSync(void) {
    void (**p)(void);
    s32 i;

    i = 0;
    p = Sys_VSyncCallbacks;
    Sys_VSyncCount++;
    do {
        if (*p != 0) {
            (*p)();
        }
        i++;
        p++;
    } while (i < 8);
}

void setIntrVSync(s32 arg0, void (*arg1)(void)) {
    if (arg1 != Sys_VSyncCallbacks[arg0]) {
        Sys_VSyncCallbacks[arg0] = arg1;
    }
}

void memclr_vb(s32 *arg0, u32 arg1) {
    while (arg1-- != 0) {
        *arg0++ = 0;
    }
}

void *startIntrDMA(void) {
    memclr_dma(Sys_DmaCallbacks, 8);
    *Sys_DicrPtr = 0;
    InterruptCallback(3, trapIntrDMA);
    return setIntrDMA;
}

void trapIntrDMA(void) {
    u32 mask;
    s32 i;

    while ((mask = (*(volatile u32 *)Sys_DicrPtr >> 24) & 0x7F) != 0) {
        for (i = 0; mask != 0 && i < 7; i++, mask >>= 1) {
            if (mask & 1) {
                *(volatile u32 *)Sys_DicrPtr &= (1 << (i + 24)) | 0xFFFFFF;
                if (((void (**)(void))Sys_DmaCallbacks)[i] != 0) {
                    ((void (**)(void))Sys_DmaCallbacks)[i]();
                }
            }
        }
    }
    if ((*(volatile u32 *)Sys_DicrPtr & 0xFF000000) == 0x80000000 || (*(volatile u32 *)Sys_DicrPtr & 0x8000)) {
        printf(D_80010A04, *(volatile u32 *)Sys_DicrPtr);
        for (i = 0; i < 7; i++) {
            printf(D_80010A20, i, D_8004FBF4[i].madr);
        }
    }
}


s32 setIntrDMA(s32 ch, s32 v) {
    s32 *p = Sys_DmaCallbacks;
    s32 old;

    p += ch;
    old = *p;

    if (v != old) {
        if (v != 0) {
            s32 *d = Sys_DicrPtr;
            s32 t, b;
            *p = v;
            t = *d & 0xFFFFFF;
            b = (1 << (ch + 16)) | 0x800000;
            *d = t | b;
        } else {
            s32 *e = Sys_DicrPtr;
            *p = 0;
            *e = ((*e & 0xFFFFFF) | 0x800000) & ~(1 << (ch + 16));
        }
    }
    return old;
}


void memclr_dma(s32 *arg0, u32 arg1) {
    while (arg1-- != 0) {
        *arg0++ = 0;
    }
}

s32 SetVideoMode(s32 a0) { s32 old = Sys_VideoMode; Sys_VideoMode = a0; return old; }

s32 GetVideoMode(void) {
    return Sys_VideoMode;
}
__asm__(".word 0\n.word 0\n.word 0\n");

void SsSeqCalledTbyT(void) {
    s32 ch;
    s32 i;
    Elm354F4 **pp;
    Elm354F4 **q;

    if (D_80061C44 == 1) {
        return;
    }
    D_80061C44 = 1;
    _SsVmFlush();
    ch = 0;
    if (ch < D_800624D0) {
    pp = Snd_SeqScores;
    do {
        s32 m = 1 << ch;

        if (!(D_80061C48 & m)) {
            continue;
        }
        i = 0;
        if (i < D_800624D2) {
        q = pp;
        do {
            if ((*q)[i].field_98 & 1) {
                func_80031D74(ch, i);
                if ((*q)[i].field_98 & 0x10) {
                    _SsSndCrescendo(ch, i);
                }
                if ((*q)[i].field_98 & 0x20) {
                    _SsSndCrescendo(ch, i);
                }
                if ((*q)[i].field_98 & 0x40) {
                    _SsSndTempo(ch, i);
                }
                if ((*q)[i].field_98 & 0x80) {
                    _SsSndTempo(ch, i);
                }
            }
            if ((*q)[i].field_98 & 2) {
                _SsSndPause((s16)ch, (s16)i);
            }
            if ((*q)[i].field_98 & 8) {
                _SsSndReplay((s16)ch, (s16)i);
            }
            if ((*q)[i].field_98 & 4) {
                _SsSndStop((s16)ch, (s16)i);
                (*q)[i].field_98 = 0;
            }
        } while (++i < D_800624D2);
        }
    } while (pp++, ++ch < D_800624D0);
    }
    D_80061C44 = 0;
}

void _SsSndCrescendo(s16 a0, s16 a1) {
    Elm354F4 **pp = &Snd_SeqScores[a0];
    Elm354F4 *e = &(*pp)[a1];
    u16 vol[2];
    s32 t;
    s32 d;
    s32 l;
    s32 r;

    t = e->field_A0 + 1;
    e->field_A0 = t;
    if (e->field_9C < t) {
        (*pp)[a1].field_98 &= ~0x10;
    } else {
        d = e->field_48 * t / e->field_9C;
        d -= e->field_4A;
        if (d != 0) {
            e->field_4A += d;
            _SsVmGetSeqVol((s16)(a0 | (a1 << 8)), &vol[0], &vol[1]);
            l = vol[0] + d;
            if (l >= 0x80) {
                l = 0x7F;
            }
            if (l < 0) {
                l = 0;
            }
            r = vol[1] + d;
            if (r >= 0x80) {
                r = 0x7F;
            }
            if (r < 0) {
                r = 0;
            }
            _SsVmSetSeqVol((s16)(a0 | (a1 << 8)), (u16)l, (u16)r, 1);
            if ((l == 0x7F && r == l) || (l == 0 && r == 0)) {
                Snd_SeqScores[a0][a1].field_98 &= ~0x10;
            }
        }
    }
    _SsVmGetSeqVol((s16)(a0 | (a1 << 8)), (u16 *)&e->field_5C, (u16 *)&e->field_5E);
}


void _SsSndPause(s32 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[(s16)a0][a1];

    _SsVmSeqKeyOff((s16)(a0 | (a1 << 8)));
    e->field_14 = 0;
    Snd_SeqScores[(s16)a0][a1].field_98 &= ~2;
}

void func_80031DA4(s16 arg0, s16 arg1);

void func_80031D74(s16 arg0, s16 arg1) { func_80031DA4(arg0, arg1); }

void func_80031DA4(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    s32 d;
    s32 acc;

    d = e->field_90 - e->field_54;
    if (d > 0) {
        if (e->field_52 > 0) {
            e->field_52--;
        } else if (e->field_52 == 0) {
            e->field_52 = e->field_54;
            e->field_90 = e->field_90 - 1;
        } else {
            e->field_90 = d;
        }
    } else if (e->field_54 >= e->field_90) {
        acc = e->field_90;
        do {
            do {
                _SsGetSeqData(a0, a1);
            } while (e->field_90 == 0);
            acc += e->field_90;
        } while (acc < e->field_54);
        e->field_90 = acc - e->field_54;
    }
}

void func_80031EA0(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];

    e->field_21++;
    if ((s8)e->field_20 == 0) {
        e->field_88 = 0;
        e->field_1C = 0;
        e->field_90 = 0;
        if (Snd_SeqScores[a0][a1].field_98 & 0x400) {
            e->field_0 = e->field_C;
        } else {
            e->field_0 = e->field_4;
        }
        return;
    }
    if ((s8)e->field_21 < (s8)e->field_20) {
        e->field_88 = 0;
        e->field_1C = 0;
        e->field_90 = 0;
        if (Snd_SeqScores[a0][a1].field_98 & 0x400) {
            e->field_0 = e->field_C;
            e->field_8 = (s32)e->field_C;
        } else {
            e->field_0 = e->field_4;
            e->field_8 = (s32)e->field_4;
        }
        return;
    }
    Snd_SeqScores[a0][a1].field_98 &= ~1;
    Snd_SeqScores[a0][a1].field_98 &= ~8;
    Snd_SeqScores[a0][a1].field_98 &= ~2;
    Snd_SeqScores[a0][a1].field_98 |= 0x200;
    Snd_SeqScores[a0][a1].field_98 |= 4;
    e->field_14 = 0;
    if (Snd_SeqScores[a0][a1].field_98 & 0x400) {
        e->field_8 = (s32)e->field_C;
    } else {
        e->field_8 = (s32)e->field_4;
    }
    {
        s8 n = e->field_22;
        if (n != -1) {
            e->field_14 = 0;
            _SsSndNextSep(e->field_22, (s8)e->field_23);
            _SsVmSeqKeyOff((s16)(a0 | (a1 << 8)));
        }
    }
    _SsVmSeqKeyOff((s16)(a0 | (a1 << 8)));
    e->field_90 = e->field_54;
}


s32 _SsGetSeqData(s16 a0, s16 a1) {
    Elm354F4 **pp = &Snd_SeqScores[a0];
    Elm354F4 *e = &(*pp)[a1];
    u8 st = *e->field_0++;
    s32 c;
    s32 d;
    s32 n;
    s32 ev;
    s32 ret = 0;

    if (((*pp)[a1].field_98 & 0x401) == 0x401 && e->field_0 == (u8 *)e->field_10 + 1) {
        ((void (*)(s16, s16, s32))func_80031EA0)(a0, a1, ((u8 *)e->field_10)[1]);
        return -1;
    }
    if (st & 0x80) {
        e->field_17 = st & 0xF;
        ev = st & 0xF0;
        switch (ev) {
        case 0x90:
            e->field_16 = ev;
            n = *e->field_0++;
            d = *e->field_0++;
            e->field_90 = _SsReadDeltaValue(a0, a1);
            D_80061BB0[0](a0, a1, n, d);
            break;
        case 0xB0:
            e->field_16 = ev;
            D_80061BB0[4](a0, a1, *e->field_0++);
            break;
        case 0xC0:
            e->field_16 = ev;
            D_80061BB0[1](a0, a1, *e->field_0++);
            break;
        case 0xE0:
            e->field_16 = ev;
            e->field_0++;
            D_80061BB0[2](a0, a1);
            break;
        case 0xF0:
            e->field_16 = 0xFF;
            st = *e->field_0++; c = st;
            if (c == 0x2F) {
                goto end_track;
            }
            goto meta;
        }
    } else {
        switch (e->field_16) {
        case 0x90:
            d = *e->field_0++;
            e->field_90 = _SsReadDeltaValue(a0, a1);
            D_80061BB0[0](a0, a1, st, d);
            break;
        case 0xB0:
            D_80061BB0[4](a0, a1, st);
            break;
        case 0xC0:
            D_80061BB0[1](a0, a1, st);
            break;
        case 0xE0:
            D_80061BB0[2](a0, a1);
            break;
        case 0xFF:
            c = (u8)st;
            if (c == 0x2F) {
end_track:
                ret = 1;
                ((void (*)(s16, s16, s32))func_80031EA0)(a0, a1, 0x2F);
            } else {
meta:
                D_80061BB0[3](a0, a1, c);
            }
            break;
        }
    }
    return ret;
}


s32 _SsReadDeltaValue(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    u32 v = *e->field_0++;
    s32 r;

    if (v != 0) {
        if (v & 0x80) {
            u32 c;

            v &= 0x7F;
            do {
                c = *e->field_0++;
                v = (v << 7) + (c & 0x7F);
            } while (c & 0x80);
        }
        r = v * 10;
        e->field_88 += r;
    } else {
        r = 0;
    }
    return r;
}

void _SsSndNextSep(s32 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[(s16)a0][a1];

    e->field_20 = 1;
    e->field_21 = 0;
    Snd_SeqScores[(s16)a0][a1].field_98 &= ~0x100;
    Snd_SeqScores[(s16)a0][a1].field_98 &= ~8;
    Snd_SeqScores[(s16)a0][a1].field_98 &= ~2;
    Snd_SeqScores[(s16)a0][a1].field_98 &= ~4;
    Snd_SeqScores[(s16)a0][a1].field_98 &= ~0x200;
    e->field_14 = 1;
    e->field_0 = e->field_4;
    Snd_SeqScores[(s16)a0][a1].field_98 |= 1;
}

void _SsSndReplay(s16 a0, s16 a1) {
    Snd_SeqScores[a0][a1].field_14 = 1;
    Snd_SeqScores[a0][a1].field_98 &= ~8;
}

void _SsClose(s16 id) {
    s32 i;
    Elm354F4 **pp;

    _SsVmSetSeqVol(id, 0, 0, 1);
    _SsVmSeqKeyOff(id);
    D_80061C48 &= ~(1 << id);
    for (i = 0; i < D_800624D2; i++) {
        pp = &Snd_SeqScores[id];
        (*pp)[i].field_98 = 0;
        (*pp)[i].field_22 = -1;
        (*pp)[i].field_23 = 0;
        (*pp)[i].field_48 = 0;
        (*pp)[i].field_4A = 0;
        (*pp)[i].field_9C = 0;
        (*pp)[i].field_A0 = 0;
        (*pp)[i].field_4C = 0;
        (*pp)[i].field_AC = 0;
        (*pp)[i].field_A8 = 0;
        (*pp)[i].field_A4 = 0;
        (*pp)[i].field_4E = 0;
        (*pp)[i].field_58 = 0x7F;
        (*pp)[i].field_5A = 0x7F;
    }
}

void func_80032820(s16 arg0) { _SsClose(arg0); }

void func_80032844(s16 arg0) { _SsClose(arg0); }

void _SsInit(void) {
    volatile u16 *dst = (volatile u16 *)0x1F801D80;
    u16 *src = D_8004FC24;
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        *dst++ = *src++;
    }
    _SsVmInit(0x18);
    for (i = 0; i < 32; i++) {
        Hook33424 *row = Snd_MarkCallbacks[i];
        for (j = 15; j >= 0; j--) {
            row[j] = 0;
        }
    }
    Snd_TicksPerSec = 0x3C;
    D_80061C48 = 0;
    D_80061C44 = 0;
}


void SsInit(void) {
    ResetCallback();
    SpuInit();
    SpuClearReverbWorkArea(7);
    _SsInit();
}

s16 SsSepOpen(s32 src, s16 arg1, s32 count) {
    s16 code;
    s32 i;
    s16 j;
    s32 r;
    s32 m;

    code = 0;
    if (D_80061C48 == -1) {
        printf(D_80010A34);
        return -1;
    }
    D_80061BB0[0] = (TextOp)_SsNoteOn;
    D_80061BB0[1] = (TextOp)_SsSetProgramChange;
    D_80061BB0[3] = (TextOp)_SsGetMetaEvent;
    D_80061BB0[2] = (TextOp)_SsSetPitchBend;
    D_80061BB0[4] = (TextOp)_SsSetControlChange;
    D_80061BB0[5] = (TextOp)_SsContBankChange;
    D_80061BB0[7] = (TextOp)_SsContMainVol;
    D_80061BB0[8] = (TextOp)_SsContPanpot;
    D_80061BB0[9] = (TextOp)_SsContExpression;
    D_80061BB0[10] = (TextOp)_SsContDamper;
    D_80061BB0[11] = (TextOp)_SsContNrpn1;
    D_80061BB0[12] = (TextOp)_SsContNrpn2;
    D_80061BB0[13] = (TextOp)_SsContRpn1;
    D_80061BB0[14] = (TextOp)_SsContRpn2;
    D_80061BB0[15] = (TextOp)_SsContExternal;
    D_80061BB0[16] = (TextOp)_SsContResetAll;
    D_80061BB0[6] = (TextOp)_SsContDataEntry;
    D_80061BB0[17] = (TextOp)_SsSetNrpnVabAttr0;
    D_80061BB0[18] = (TextOp)_SsSetNrpnVabAttr1;
    D_80061BB0[19] = (TextOp)_SsSetNrpnVabAttr2;
    D_80061BB0[20] = (TextOp)_SsSetNrpnVabAttr3;
    D_80061BB0[21] = (TextOp)_SsSetNrpnVabAttr4;
    D_80061BB0[22] = (TextOp)_SsSetNrpnVabAttr5;
    D_80061BB0[23] = (TextOp)_SsSetNrpnVabAttr6;
    D_80061BB0[24] = (TextOp)_SsSetNrpnVabAttr7;
    D_80061BB0[25] = (TextOp)_SsSetNrpnVabAttr8;
    D_80061BB0[26] = (TextOp)_SsSetNrpnVabAttr9;
    D_80061BB0[27] = (TextOp)_SsSetNrpnVabAttr10;
    D_80061BB0[28] = (TextOp)_SsSetNrpnVabAttr11;
    D_80061BB0[29] = (TextOp)_SsSetNrpnVabAttr12;
    D_80061BB0[30] = (TextOp)_SsSetNrpnVabAttr13;
    D_80061BB0[31] = (TextOp)_SsSetNrpnVabAttr14;
    D_80061BB0[32] = (TextOp)_SsSetNrpnVabAttr15;
    D_80061BB0[33] = (TextOp)_SsSetNrpnVabAttr16;
    D_80061BB0[34] = (TextOp)_SsSetNrpnVabAttr17;
    D_80061BB0[35] = (TextOp)_SsSetNrpnVabAttr18;
    D_80061BB0[36] = (TextOp)_SsSetNrpnVabAttr19;
    for (i = 0; i < 32; i++) {
        m = 1 << i;
        if (!(D_80061C48 & m)) {
            code = i;
            break;
        }
    }
    D_80061C48 |= 1 << code;
    for (j = 0; j < (s16)count; j++) {
        r = _SsInitSoundSeq(code, j, arg1, src);
        src += r;
        if (r == -1) {
            return -1;
        }
    }
    return code;
}


void _SsContBankChange(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &Snd_SeqScores[arg0][arg1];
    e->field_26 = *e->field_0++;
    e->field_90 = _SsReadDeltaValue(arg0, arg1);
}

void _SsContDataEntry(s16 a0, s16 a1, s16 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    s32 k = e->field_17;
    SlotHead8 h[2];
    Rec62D08 atr;
    s32 i;
    u16 t;
    u8 v;

    SsUtGetProgAtr(e->field_26, e->field_37[k], h);
    v = a2;
    if (e->field_1C == 1 && e->field_15 == 0) {
        e->field_1D = a2;
        e->field_1C = 0;
        e->field_15 = 1;
        e->field_90 = _SsReadDeltaValue(a0, a1);
    } else if (e->field_1E == 2) {
        if (e->field_19 == 0) {
            for (i = 0; i < h[0].field_0; i++) {
                SsUtGetVagAtr(e->field_26, e->field_37[k], (s16)i, &atr);
                switch (e->field_18) {
                case 0:
                    atr.field_C = atr.field_D = v & 0x7F;
                    break;
                case 1:
                    if ((u8)(v - 0x41) < 0x3F) {
                        t = ((v * 100) / 0x2000) << 13;
                    } else {
                        t = 0;
                    }
                    atr.field_5 |= t >> 16;
                    break;
                case 2:
                    if ((u8)(v - 0x40) < 0x40) {
                        t = v * 6400;
                    } else {
                        t = 0;
                    }
                    atr.field_4 |= t >> 16;
                    if (v > 0x80) t = 0;
                    if (v < 0x40) t = 0;
                    break;
                }
                SsUtSetVagAtr(e->field_26, e->field_37[k], (s16)i, &atr);
            }
        }
        e->field_90 = _SsReadDeltaValue(a0, a1);
        e->field_1E = 0;
    } else if (e->field_1F == 2) {
        if (e->field_1B == 0x10) {
            void (**tbl)(s16, s16, s16, Rec62D08, s32, s32) = D_80061BF4;
            tbl[e->field_1A](e->field_26, e->field_37[k], 0, atr, e->field_1A, v);
        } else {
            void (**tbl)(s16, s16, s16, Rec62D08, s32, s32) = D_80061BF4;
            tbl[e->field_1A](e->field_26, e->field_37[k], e->field_1B, atr, e->field_1A, v);
        }
        e->field_90 = _SsReadDeltaValue(a0, a1);
        e->field_1F = 0;
    } else {
        e->field_90 = _SsReadDeltaValue(a0, a1);
    }
}


void _SsContMainVol(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    u8 k = e->field_17;

    func_80039334((s16)(a0 | (a1 << 8)), (s8)e->field_26, e->field_37[k], a2, e->field_27[k]);
    e->field_60[k] = a2;
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsContPanpot(s16 a0, s16 a1, s32 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    s32 i = e->field_17;

    func_80039334(a0 | (a1 << 8), e->field_26, e->field_37[i], e->field_60[i], (u8)a2);
    e->field_27[i] = a2;
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsContExpression(s16 a0, s16 a1, s32 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    u8 k = e->field_17;

    func_80038B74((s8)e->field_26, e->field_37[k], (u8)a2);
    func_80039334(a0 | (a1 << 8), (s8)e->field_26, e->field_37[k], e->field_60[k], e->field_27[k]);
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

extern void _SsVmDamperOff(void);
extern void _SsVmDamperOn(void);

void _SsContDamper(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];

    if (a2 < 0x40) {
        _SsVmDamperOff();
    } else {
        _SsVmDamperOn();
    }
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsContExternal(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];

    SsUtSetReverbDepth(a2, a2);
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsContNrpn1(s16 a0, s16 a1, u8 a2) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    Hook33424 *row;

    if (e->field_1B == 0x28) {
        row = Snd_MarkCallbacks[a0];
        if (row[a1] != 0) {
            row[a1](a0, a1, a2);
        }
    }
    if (e->field_1B != 0x1E && e->field_1B != 0x14 && e->field_1B != 0x28) {
        e->field_1A = a2;
        e->field_1C = 0;
        e->field_1F++;
    }
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsContNrpn2(a0, a1, a2)
s16 a0;
s16 a1;
u8 a2;
{
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    u8 n;

    switch (a2) {
    case 0x14:
        e->field_1B = a2;
        e->field_1C = 1;
        e->field_90 = _SsReadDeltaValue(a0, a1);
        e->field_8 = (s32)e->field_0;
        break;
    case 0x1E:
        n = e->field_1D;
        e->field_1B = a2;
        if (n == 0) {
            e->field_15 = 0;
            e->field_90 = _SsReadDeltaValue(a0, a1);
        } else if (n < 0x7F) {
            e->field_1D = n - 1;
            e->field_90 = _SsReadDeltaValue(a0, a1);
            if (e->field_1D != 0) {
                e->field_0 = (u8 *)e->field_8;
            } else {
                e->field_15 = 0;
            }
        } else {
            _SsReadDeltaValue(a0, a1);
            e->field_90 = 0;
            e->field_0 = (u8 *)e->field_8;
        }
        break;
    default:
        e->field_1B = a2;
        e->field_1F++;
        e->field_90 = _SsReadDeltaValue(a0, a1);
        break;
    }
}

void _SsContRpn1(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &Snd_SeqScores[arg0][arg1];
    e->field_18 = arg2;
    e->field_1E++;
    e->field_90 = _SsReadDeltaValue(arg0, arg1);
}

void _SsContRpn2(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &Snd_SeqScores[arg0][arg1];
    e->field_19 = arg2;
    e->field_1E++;
    e->field_90 = _SsReadDeltaValue(arg0, arg1);
}

void _SsContResetAll(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];

    SsUtReverbOff();
    _SsVmDamperOff();
    e->field_37[e->field_17] = e->field_17;
    e->field_18 = 0;
    e->field_19 = 0;
    e->field_60[e->field_17] = 0x7F;
    e->field_27[e->field_17] = 0x40;
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsSetNrpnVabAttr0(s16 a0, s16 a1, s16 a2, HandlerArg arg) {
    s32 v = arg.field_24;

    SsUtGetVagAtr(a0, a1, a2, &arg);
    arg.field_0 = v;
    SsUtSetVagAtr(a0, a1, a2, &arg);
}

void _SsSetNrpnVabAttr1(s16 a0, s16 a1, s16 a2, HandlerArg arg) {
    s32 v = arg.field_24;

    SsUtGetVagAtr(a0, a1, a2, &arg);
    arg.field_1 = v;
    SsUtSetVagAtr(a0, a1, a2, &arg);
    v &= 0xFF;
    if (v == 0) {
        SsUtReverbOff();
    } else if (v == 4) {
        SsUtReverbOn();
    }
}

void _SsSetNrpnVabAttr2(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    s32 flag = d.field_24;

    SsUtGetVagAtr(a0, a1, a2, &d);
    d.field_6 = flag;
    SsUtSetVagAtr(a0, a1, a2, &d);
}

extern s32 SsUtGetVagAtr();
extern s32 SsUtSetVagAtr();

void _SsSetNrpnVabAttr3(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    s32 v = d.field_24;

    SsUtGetVagAtr(a0, a1, a2, &d);
    d.field_7 = v;
    SsUtSetVagAtr(a0, a1, a2, &d);
}


extern s32 SsUtGetVagAtr();
extern void _SsUtBuildADSR();
extern s32 SsUtSetVagAtr();
void _SsUtResolveADSR(u32, u32, Out33B24 *);

void _SsSetNrpnVabAttr4(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_A = 0;
    buf.field_0 = flag;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsUtResolveADSR(u32 arg0, u32 arg1, Out33B24 *arg2) {
    arg2->field_A = arg0 & 0x8000;
    arg2->field_C = arg1 & 0x8000;
    arg2->field_10 = arg1 & 0x4000;
    arg2->field_E = arg1 & 0x20;
    arg2->field_0 = ((arg0 & 0xFFFF) >> 8) & 0x7F;
    arg2->field_2 = ((arg0 & 0xFFFF) >> 4) & 0xF;
    arg2->field_4 = arg0 & 0xF;
    arg2->field_6 = (arg1 >> 6) & 0x7F;
    arg2->field_8 = arg1 & 0x1F;
}

void _SsUtBuildADSR(Out33B24 *p, u16 *adsr1, u16 *adsr2) {
    u16 c;
    u16 a;
    u16 m;
    u16 r1;
    u16 r2;
    c = -(p->field_C != 0) & 0x8000;
    a = -(p->field_A != 0) & 0x8000;
    m = c;
    if (p->field_10) {
        m = c | 0x4000;
    }
    if (p->field_E) {
        m |= 0x20;
    }
    r1 = a | ((p->field_0 << 8) & 0x7F00) | ((p->field_2 << 4) & 0xF0) | (p->field_4 & 0xF);
    r2 = m | ((p->field_6 << 6) & 0x1FC0) | (p->field_8 & 0x1F);
    *adsr1 = r1;
    *adsr2 = r2;
}


void _SsSetNrpnVabAttr5(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_A = 1;
    buf.field_0 = flag;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr6(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    Out33B24 buf;
    s32 v = (u8)d.field_24;

    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_2 = v;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr7(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_4 = flag;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr8(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_C = 0;
    buf.field_6 = flag;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr9(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_C = 1;
    buf.field_6 = flag;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr10(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    u16 flag = d.field_24;
    SsUtGetVagAtr(a0, a1, a2, &d);
    _SsUtResolveADSR(d.field_10, d.field_12, &buf);
    buf.field_E = 0;
    buf.field_8 = flag;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr11(s16 a0, s16 a1, s16 a2, Arg33 d) {
    Out33B24 buf;
    s32 f = d.field_24;

    SsUtGetVagAtr(a0, a1, a2, &d);
    buf.field_E = 1;
    buf.field_8 = f;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr12(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    Out33B24 buf;
    s32 v = d.field_24;

    SsUtGetVagAtr(a0, a1, a2, &d);
    if ((u8)(v - 1) < 63) {
        buf.field_10 = 0;
    } else if ((u8)(v - 64) < 64) {
        buf.field_10 = 1;
    }
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr13(s16 a0, s16 a1, s16 a2, HandlerArg d) {
    Out33B24 buf;
    s32 v = d.field_24;

    SsUtGetVagAtr(a0, a1, a2, &d);
    d.field_9 = v;
    _SsUtBuildADSR(&buf, &d.field_10, &d.field_12);
    SsUtSetVagAtr(a0, a1, a2, &d);
}

void _SsSetNrpnVabAttr14(s16 a0, s16 a1, s16 a2, HandlerArg arg) {
    Out33B24 buf;
    s32 v = arg.field_24;

    SsUtGetVagAtr(a0, a1, a2, &arg);
    arg.field_A = v;
    _SsUtBuildADSR(&buf, &arg.field_10, &arg.field_12);
    SsUtSetVagAtr(a0, a1, a2, &arg);
}

void _SsSetNrpnVabAttr15(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    SsUtSetReverbType((u8)arg.field_24);
}

void _SsSetNrpnVabAttr16(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    SsUtSetReverbDepth((u8)arg.field_24, (u8)arg.field_24);
}

void _SsSetNrpnVabAttr17(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    SsUtSetReverbFeedback((u8)arg.field_24);
}

void _SsSetNrpnVabAttr18(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    SsUtSetReverbDelay((u8)arg.field_24);
}

void _SsSetNrpnVabAttr19(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg) {
    SsUtSetReverbDelay((u8)arg.field_24);
}

void _SsSetPitchBend(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    s32 note = *e->field_0++;

    _SsVmPitchBend((s16)(a0 | (a1 << 8)), e->field_26, e->field_37[e->field_17], note);
    e->field_90 = _SsReadDeltaValue(a0, a1);
}

void _SsSetControlChange(s16 a0, s16 a1, s32 a2) {
    s16 i = a0;
    s16 j = a1;
    Elm354F4 *e = &Snd_SeqScores[i][j];
    s32 v = *e->field_0++;

    switch ((u8)a2) {
    case 0:
        e->field_26 = v;
        e->field_90 = _SsReadDeltaValue(i, j);
        return;
    case 6:
        D_80061BC8(i, j, v);
        return;
    case 7:
        D_80061BCC(i, j, v);
        return;
    case 10:
        D_80061BD0(i, j, v);
        return;
    case 11:
        D_80061BD4(i, j, v);
        return;
    case 64:
        D_80061BD8(i, j, v);
        return;
    case 91:
        D_80061BEC(i, j, v);
        return;
    case 98:
        D_80061BDC(i, j, v);
        return;
    case 99:
        D_80061BE0(i, j, v);
        return;
    case 100:
        D_80061BE4(i, j, v);
        return;
    case 101:
        D_80061BE8(i, j, v);
        return;
    case 0x79:
        D_80061BF0(i, j);
        return;
    }
    e->field_90 = _SsReadDeltaValue(a0, a1);
}


void _SsGetMetaEvent(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    s32 b0;
    s32 b1;
    s32 b2;
    u32 t;
    u32 r;

    b0 = *e->field_0++;
    b1 = *e->field_0++;
    b2 = *e->field_0++;
    e->field_94 = 60000000 / (b2 | ((b0 << 16) | (b1 << 8)));
    t = e->field_50 * e->field_94;
    if (t * 10 < Snd_TicksPerSec * 60) {
        e->field_52 = Snd_TicksPerSec * 600 / t;
        e->field_54 = Snd_TicksPerSec * 600 / t;
    } else {
        e->field_52 = -1;
        e->field_54 = (u32)(e->field_50 * e->field_94 * 10) / (Snd_TicksPerSec * 60);
        if (Snd_TicksPerSec * 30 < (u32)(e->field_50 * e->field_94 * 10) % (Snd_TicksPerSec * 60)) {
            e->field_54 = e->field_54 + 1;
        }
    }
    e->field_90 = _SsReadDeltaValue(a0, a1);
}


void _SsNoteOn(s32 a0, s32 a1, s32 a2, s32 a3) {
    Elm354F4 *e = &Snd_SeqScores[(s16)a0][(s16)a1];
    u8 k = e->field_17;
    s32 v = e->field_27[k];
    s32 on = (u8)a3;

    if (a3 & 0xFF) {
        if (!((e->field_80 >> k) & 1)) {
            _SsVmKeyOn((s16)(a0 | (a1 << 8)), e->field_26, e->field_37[k], (u8)a2, on, v);
        }
    } else {
        _SsVmKeyOff((s16)(a0 | (a1 << 8)), e->field_26, e->field_37[k], (u8)a2);
    }
}

void _SsSetProgramChange(s16 arg0, s16 arg1, s16 arg2) {
    Elm354F4 *e = &Snd_SeqScores[arg0][arg1];
    e->field_37[e->field_17] = arg2;
    e->field_90 = _SsReadDeltaValue(arg0, arg1);
}

s32 _SsInitSoundSeq(s16 a0, s16 a1, s16 a2, s32 a3) {
    Elm354F4 *e;
    s32 n;
    s32 i;
    s32 b0;
    s32 b1;
    s32 b2;
    s32 t;
    s32 len;
    s32 r;
    u32 x;
    u32 q;
    u8 *pC;
    u8 *p8;
    u8 *p4;

    n = 0;
    e = &Snd_SeqScores[a0][a1];
    e->field_20 = 1;
    e->field_15 = 0;
    e->field_16 = 0;
    e->field_17 = 0;
    e->field_18 = 0;
    e->field_19 = 0;
    e->field_1A = 0;
    e->field_1B = 0;
    e->field_1C = 0;
    e->field_1D = 0;
    e->field_1E = 0;
    e->field_1F = 0;
    e->field_14 = 0;
    e->field_21 = 0;
    e->field_52 = 1;
    e->field_50 = 0;
    e->field_26 = a2;
    e->field_56 = 0;
    e->field_84 = 0;
    e->field_88 = 0;
    e->field_8C = 0;
    e->field_90 = 0;
    e->field_80 = 0;
    e->field_24 = 0;
    e->field_25 = 0;
    for (i = 0; i < 0x10; i++) {
        e->field_27[i] = 0x40;
        e->field_37[i] = i;
        e->field_60[i] = 0x7F;
    }
    e->field_0 = (u8 *)a3;
    if (a1 == 0) {
        if (*e->field_0 == 'S' || *e->field_0 == 'p') {
            e->field_0 += 5;
            if (*e->field_0++ != 0) {
                printf(D_80010A64);
                return -1;
            }
            e->field_0 += 2;
            n += 8;
        }
    } else {
        e->field_0 += 2;
        n += 2;
    }
    b0 = *e->field_0++;
    b1 = *e->field_0++;
    e->field_50 = b1 | (b0 << 8);
    {
        s32 c0 = *e->field_0++;
        s32 c1 = *e->field_0++;
        s32 c2 = *e->field_0++;
        e->field_8C = c2 | ((c0 << 16) | (c1 << 8));
    }
    n += 5;
    if ((s32)((u32)e->field_8C >> 1) < 0x3938700 % e->field_8C) {
        e->field_8C = 0x3938700 / e->field_8C + 1;
    } else {
        e->field_8C = 0x3938700 / e->field_8C;
    }
    e->field_94 = e->field_8C;
    e->field_24 = *e->field_0++;
    e->field_25 = *e->field_0++;
    b0 = *e->field_0++;
    b1 = *e->field_0++;
    b2 = *e->field_0++;
    t = *e->field_0++;
    len = t | ((b0 << 24) + (b1 << 16) + (b2 << 8));
    n += 6;
    r = _SsReadDeltaValue(a0, a1);
    x = e->field_50 * e->field_8C;
    pC = *(u8 *volatile *)&e->field_0;
    p8 = *(u8 *volatile *)&e->field_0;
    p4 = *(u8 *volatile *)&e->field_0;
    e->field_C = pC;
    e->field_84 = r;
    e->field_90 = r;
    e->field_10 = 0;
    e->field_8 = (s32)p8;
    e->field_4 = p4;
    if (x * 10 < (u32)(Snd_TicksPerSec * 60)) {
        e->field_54 = e->field_52 = (u32)(Snd_TicksPerSec * 600) / x;
    } else {
        e->field_52 = -1;
        q = (u32)(e->field_50 * e->field_8C * 10) / (u32)(Snd_TicksPerSec * 60);
        e->field_54 = q;
        if ((u32)(Snd_TicksPerSec * 30) < (u32)(e->field_50 * e->field_8C * 10) % (u32)(Snd_TicksPerSec * 60)) {
            e->field_54 = q + 1;
        }
    }
    e->field_56 = e->field_54;
    return n + len;
}


void Snd_SetPlayMode(s16 a0, s16 a1, s8 a2, s16 a3);

void SsSepPlay(s16 arg0, s16 arg1, s8 arg2, s16 arg3) { Snd_SetPlayMode(arg0, arg1, arg2, arg3); }

void Snd_SetPlayMode(s16 a0, s16 a1, s8 a2, s16 a3) {
    Elm354F4 **p = &Snd_SeqScores[a0];
    Elm354F4 *e = &(*p)[a1];
    s32 c;

    e->field_0 = e->field_4;
    e->field_8 = e->field_4;
    e->field_C = e->field_4;
    (*p)[a1].field_98 &= ~0x200;
    c = a2;
    (*p)[a1].field_98 &= ~4;
    e->field_20 = a3;
    if (c == 1) {
        (*p)[a1].field_98 |= 1;
        e->field_14 = c;
        e->field_21 = 0;
        _SsVmSetSeqVol((s16)(a0 | (a1 << 8)), e->field_58, e->field_5A, 1);
    } else if (c == 0) {
        (*p)[a1].field_98 |= 2;
    }
}

void SsSetSerialAttr(s8 a0, s8 a1, s8 a2) {
    Cmd3D124 c;

    if (a0 == 0) {
        if (a1 == 0) {
            c.field_0 = 0x200;
            c.field_18 = a2;
        }
        if (a1 == 1) {
            c.field_0 = 0x100;
            c.field_14 = a2;
        }
    }
    if (a0 == 1) {
        if (a1 == 0) {
            c.field_0 = 0x2000;
            c.field_24 = a2;
        }
        if (a1 == 1) {
            c.field_0 = 0x1000;
            c.field_20 = a2;
        }
    }
    SpuSetCommonAttr(&c);
}

void SsSetMVol(s16 a0, s16 a1) {
    Cmd3D124 c;

    c.field_0 = 3;
    c.field_4 = a0 * 0x81;
    c.field_6 = a1 * 0x81;
    SpuSetCommonAttr(&c);
}

void _SsStart(s32 a0) {
    s32 i;
    s32 cmd;
    u16 rate;

    i = 0x3E7;
    do {
        i--;
    } while (i >= 0);
    cmd = 0xF2000002;
    rate = 0x44E8;
    D_8004FC48.b0 = 0;
    D_8004FC48.b1 = 0;
    D_8004FC48.b2 = 6;
    D_8004FC48.fn_4 = 0;
    switch (D_8004FC48.mode) {
    case 0:
        D_8004FC48.b2 = 0x7F;
        return;
    case 5:
        D_8004FC48.b2 = 0;
        if (a0 == 0) {
            D_8004FC48.b0 = 1;
        } else {
            cmd = 0xF2000003;
            rate = 1;
        }
        break;
    case 3:
        rate = 0x89D0;
        break;
    case 2:
        break;
    default:
        if (D_8004FC48.flag != 0) {
            return;
        }
        if (D_8004FC48.mode < 0x46) {
            rate = 0x204CC0 / D_8004FC48.mode;
            D_8004FC48.b1++;
        } else {
            rate = 0x409980 / D_8004FC48.mode;
        }
        break;
    }
    if (D_8004FC48.b0 != 0) {
        EnterCriticalSection();
        VSyncCallback((s32)D_8004FC48.fn_0);
    } else {
        EnterCriticalSection();
        ResetRCnt(cmd);
        SetRCnt(cmd, (u16)rate, 0x1000);
        if (D_8004FC48.b2 == 0) {
            D_8004FC48.fn_4 = ((void (*(*)(s32, void (*)(void)))(void))InterruptCallback)(0, 0);
            InterruptCallback(D_8004FC48.b2, _SsTrapIntrVSync);
        } else if (D_8004FC48.b1 != 0) {
            InterruptCallback(D_8004FC48.b2, _SsSeqCalledTbyT_1per2);
        } else {
            InterruptCallback(D_8004FC48.b2, D_8004FC48.fn_0);
        }
    }
    ExitCriticalSection();
}


void SsStart(void) { _SsStart(1); }

void SsStart2(void) { _SsStart(0); }

void _SsTrapIntrVSync(void) {
    if (D_8004FC50.fn_4 != 0) {
        D_8004FC50.fn_4();
    }
    D_8004FC50.fn_0();
}

void _SsSeqCalledTbyT_1per2(void) {
    if (D_8004FC5C == 0) {
        D_8004FC5C = 1;
    } else {
        D_8004FC5C = 0;
        D_8004FC50.fn_0();
    }
}

typedef struct {
    /* 0x0 */ u16 field_0;
    u8 _pad2[2];
    /* 0x4 */ u16 field_4;
    u8 _pad6[2];
    /* 0x8 */ u16 field_8;
    u8 _padA[6];
} Ch35384;

extern Ch35384 *Sys_RCntRegs;

s32 SetRCnt(s32 arg0, s32 arg1, s32 arg2) {
    s32 ch = (u16)arg0;
    s32 flags = 0x48;
    if (ch >= 3) {
        return 0;
    }
    Sys_RCntRegs[ch].field_4 = 0;
    Sys_RCntRegs[ch].field_8 = arg1;
    if (ch == 0 || ch == 1) {
        if (arg2 & 0x10) {
            flags = 0x49;
        }
        if (!(arg2 & 1)) {
            flags |= 0x100;
        }
    } else if (ch == 2) {
        if (!(arg2 & 1)) {
            flags |= 0x200;
        }
    }
    if (arg2 & 0x1000) {
        flags |= 0x10;
    }
    Sys_RCntRegs[ch].field_4 = flags;
    return 1;
}


s32 GetRCnt(s32 arg0) {
    s32 ch = arg0 & 0xFFFF;
    s32 ret;

    if (ch < 3) {
        ret = Sys_RCntRegs[ch].field_0;
    } else {
        ret = 0;
    }
    return ret;
}


s32 StartRCnt(u16 arg0) {
    s32 i = arg0;

    D_8004FC68->field_4 |= D_8004FC70[i];
    return i < 3;
}

s32 StopRCnt(u16 arg0) {
    D_8004FC68->field_4 &= ~D_8004FC70[arg0];
    return 1;
}

s32 ResetRCnt(s32 arg0) {
    s32 ch = arg0 & 0xFFFF;

    if (ch >= 3) {
        return 0;
    }
    Sys_RCntRegs[ch].field_0 = 0;
    return 1;
}


extern void _SsVmDamperOff(void);

void _SsSndStop(s32 arg0, s32 arg1) {
    Elm354F4 *e;
    s32 i;
    s32 idx = (s16)arg0;

    e = &Snd_SeqScores[idx][(s16)arg1];
    e->field_98 &= ~1;
    Snd_SeqScores[(s16)arg0][(s16)arg1].field_98 &= ~2;
    Snd_SeqScores[(s16)arg0][(s16)arg1].field_98 &= ~8;
    Snd_SeqScores[(s16)arg0][(s16)arg1].field_98 &= ~0x400;
    Snd_SeqScores[(s16)arg0][(s16)arg1].field_98 |= 4;
    _SsVmSeqKeyOff((s16)(arg0 | (arg1 << 8)));
    _SsVmDamperOff();

    e->field_14 = 0;
    e->field_88 = 0;
    e->field_1C = 0;
    e->field_18 = 0;
    e->field_19 = 0;
    e->field_1E = 0;
    e->field_1A = 0;
    e->field_1B = 0;
    e->field_1F = 0;
    e->field_17 = 0;
    e->field_21 = 0;
    e->field_1C = 0;
    e->field_1D = 0;
    e->field_15 = 0;
    e->field_16 = 0;
    e->field_90 = e->field_84;
    e->field_94 = e->field_8C;
    e->field_54 = e->field_56;
    e->field_0 = e->field_4;
    e->field_8 = e->field_4;

    for (i = 0; i < 0x10; i++) {
        e->field_37[i] = i;
        e->field_27[i] = 0x40;
        e->field_60[i] = 0x7F;
    }
    e->field_5C = 0x7F;
    e->field_5E = 0x7F;
}

void SsSeqStop(s16 arg0) { _SsSndStop(arg0, 0); }

void SsSepStop(s16 arg0, s16 arg1) { _SsSndStop(arg0, arg1); }

void SsSetSerialVol(s8 a0, s16 l, s16 r) {
    Cmd3D124 c;

    if (a0 == 0) {
        c.field_0 = 0xC0;
        if (l >= 0x80) {
            l = 0x7F;
        }
        if (r >= 0x80) {
            r = 0x7F;
        }
        c.field_10 = l * 0x102;
        c.field_12 = r * 0x102;
    }
    if (a0 == 1) {
        c.field_0 = 0xC00;
        if (l >= 0x80) {
            l = 0x7F;
        }
        if (r >= 0x80) {
            r = 0x7F;
        }
        c.field_1C = l * 0x102;
        c.field_1E = r * 0x102;
    }
    SpuSetCommonAttr(&c);
}

void SsSetTableSize(void *base, s16 rows, s16 cols) {
    Elm354F4 *b = base;
    Elm354F4 **pp;
    s32 i;
    s32 j;
    s32 m1;
    s32 k;
    s32 n;

    D_800624D0 = rows;
    D_800624D2 = cols;
    i = 0;
    if (i < rows) {
        n = cols;
        pp = Snd_SeqScores;
        do {
            *pp = &b[i * n];
            pp++;
        } while (++i < rows);
    }
    for (i = rows; i < 32; i++) {
        D_80061C48 |= 1 << i;
    }
    i = 0;
    if (i < D_800624D0) {
        m1 = -1;
        k = 0x7F;
        pp = Snd_SeqScores;
        do {
            Elm354F4 **q;

            j = 0;
            if (j < D_800624D2) {
                q = pp;
                do {
                    (*q)[j].field_98 = 0;
                    (*q)[j].field_22 = m1;
                    (*q)[j].field_23 = 0;
                    (*q)[j].field_48 = 0;
                    (*q)[j].field_4A = 0;
                    (*q)[j].field_9C = 0;
                    (*q)[j].field_A0 = 0;
                    (*q)[j].field_4C = 0;
                    (*q)[j].field_AC = 0;
                    (*q)[j].field_A8 = 0;
                    (*q)[j].field_A4 = 0;
                    (*q)[j].field_4E = 0;
                    (*q)[j].field_58 = k;
                    (*q)[j].field_5A = k;
                    (*q)[j].field_5C = k;
                    (*q)[j].field_5E = k;
                } while (++j < D_800624D2);
            }
            pp++;
        } while (++i < D_800624D0);
    }
}


void SsSetTickMode(s32 arg) {
    s32 mode;

    mode = GetVideoMode();
    if (arg & 0x1000) {
        D_8004FC48.flag = 1;
        D_8004FC48.mode = arg & 0xFFF;
    } else {
        D_8004FC48.flag = 0;
        D_8004FC48.mode = arg;
    }
    if (D_8004FC48.mode < 6) {
        switch (D_8004FC48.mode) {
        case 4:
            Snd_TicksPerSec = 0x32;
            if (mode == 1) {
                D_8004FC48.mode = 5;
            } else {
                D_8004FC48.mode = 0x32;
            }
            break;
        case 1:
            Snd_TicksPerSec = 0x3C;
            if (mode == 0) {
                D_8004FC48.mode = 5;
            } else {
                D_8004FC48.mode = 0x3C;
            }
            break;
        case 3:
            Snd_TicksPerSec = 0x78;
            break;
        case 2:
            Snd_TicksPerSec = 0xF0;
            break;
        case 5:
            if (mode == 0) {
                Snd_TicksPerSec = 0x3C;
            } else if (mode == 1) {
                Snd_TicksPerSec = 0x32;
            } else {
                Snd_TicksPerSec = 0x3C;
            }
            break;
        case 0:
            if (mode == 0) {
                Snd_TicksPerSec = 0x3C;
            } else if (mode == 1) {
                Snd_TicksPerSec = 0x32;
            } else {
                Snd_TicksPerSec = 0x3C;
            }
            break;
        default:
            Snd_TicksPerSec = 0x3C;
            break;
        }
    } else {
        Snd_TicksPerSec = D_8004FC48.mode;
    }
}


void func_80035B54(s32 a0, s16 a1, s16 a2, s16 a3) {
    Elm354F4 *e = &Snd_SeqScores[(s16)a0][a1];

    if (e->field_98 != 1) {
        e->field_58 = a2;
        e->field_5A = a3;
    } else {
        _SsVmSetSeqVol((s16)(a0 | (a1 << 8)), (u16)a2, (u16)a3, 1);
    }
}

void SsSeqSetVol(s16 a0, s16 a1, s16 a2) {
    Elm354F4 *e = Snd_SeqScores[a0];

    if (e->field_98 != 1) {
        e->field_58 = a1;
        e->field_5A = a2;
    } else {
        _SsVmSetSeqVol(a0, (u16)a1, (u16)a2, 1);
    }
}

void func_80035C4C(s16 a0, s16 a1, s16 a2, s16 a3) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];

    if (e->field_98 != 1) {
        e->field_58 = a2;
        e->field_5A = a3;
    } else {
        _SsVmSetSeqVol((s16)(a0 | (a1 << 8)), (u16)a2, (u16)a3, 1);
    }
}

void _SsSndTempo(s16 a0, s16 a1) {
    Elm354F4 *e = &Snd_SeqScores[a0][a1];
    s32 t;
    s32 n;
    u32 cur;
    u32 tgt;
    u32 v;

    t = e->field_A8 - 1;
    e->field_A8 = t;
    if (t < 0) {
        Snd_SeqScores[a0][a1].field_98 &= ~0x40;
        Snd_SeqScores[a0][a1].field_98 &= ~0x80;
        return;
    }
    n = e->field_4E;
    if (n > 0) {
        if (t % n != 0) {
            return;
        }
        cur = e->field_94;
        tgt = e->field_AC;
        if (tgt < cur) {
            v = cur - 1;
        } else {
            if (cur >= tgt) {
                goto done;
            }
            v = cur + 1;
        }
        e->field_94 = v;
    } else {
        cur = e->field_94;
        tgt = e->field_AC;
        if (tgt < cur) {
            v = cur + n;
            e->field_94 = v;
            if (v < tgt) {
                e->field_94 = tgt;
            }
        } else if (cur < tgt) {
            v = cur - n;
            e->field_94 = v;
            if ((u32)e->field_AC < v) {
                e->field_94 = e->field_AC;
            }
        }
    }
done:
    e->field_54 = (u32)(e->field_50 * e->field_94 * 10) / (Snd_TicksPerSec * 60);
    if (e->field_54 <= 0) {
        e->field_54 = 1;
    }
    if (e->field_A8 == 0 || e->field_94 == e->field_AC) {
        Snd_SeqScores[a0][a1].field_98 &= ~0x40;
        Snd_SeqScores[a0][a1].field_98 &= ~0x80;
    }
}


void SsUtAllKeyOff(s32 arg) {
    VAttr36C54 attr;
    s16 i;
    s32 bit;

    attr.mask = 0x60093;
    attr.pitch = 0x1000;
    attr.addr = 0x1000;
    attr.adsr1 = 0x80FF;
    attr.vol_l = 0;
    attr.vol_r = 0;
    attr.adsr2 = 0x4000;
    for (i = 0; i < D_80062D0C; i++) {
        bit = 1 << i;
        if (!(D_8004FC18 & bit)) {
            D_800624E8[i].field_2 = 0x18;
            D_800624E8[i].field_6 = 0;
            D_800624E8[i].field_10 = 0xFF;
            D_800624E8[i].field_12 = 0;
            D_800624E8[i].field_14 = 0;
            D_800624E8[i].field_16 = 0xFF;
            D_800624E8[i].field_36 = 0;
            attr.voice = bit;
            SpuSetVoiceAttr(&attr);
            D_80062D30 = i;
            _SsVmKeyOffNow(1);
        }
    }
}


s32 SsUtGetProgAtr(s16 a0, s16 a1, SlotHead8 *out) {
    if (D_80062D38[a0] == 1) {
        _SsVmVSetUp(a0, a1);
        out->field_0 = D_80062CFC[a1].field_0;
        out->field_1 = D_80062CFC[a1].field_1;
        out->field_2 = D_80062CFC[a1].field_2;
        out->field_3 = D_80062CFC[a1].field_3;
        out->field_4 = D_80062CFC[a1].field_4;
        out->field_6 = D_80062CFC[a1].field_6;
        return 0;
    }
    return -1;
}

s32 SsUtGetVagAtr(s32 a0, s32 a1, s32 a2, Rec62D08 *out) {
    s32 k;

    if (D_80062D38[(s16)a0] == 1) {
        _SsVmVSetUp(a0, a1);
        k = (s16)(a2 + D_80062D1F * 16);
        out->field_0 = D_80062D08[k].field_0;
        out->field_1 = D_80062D08[k].field_1;
        out->field_2 = D_80062D08[k].field_2;
        out->field_3 = D_80062D08[k].field_3;
        out->field_4 = D_80062D08[k].field_4;
        out->field_5 = D_80062D08[k].field_5;
        out->field_7 = D_80062D08[k].field_7;
        out->field_6 = D_80062D08[k].field_6;
        out->field_8 = D_80062D08[k].field_8;
        out->field_9 = D_80062D08[k].field_9;
        out->field_A = D_80062D08[k].field_A;
        out->field_B = D_80062D08[k].field_B;
        out->field_C = D_80062D08[k].field_C;
        out->field_D = D_80062D08[k].field_D;
        out->field_10 = D_80062D08[k].field_10;
        out->field_12 = D_80062D08[k].field_12;
        out->field_14 = D_80062D08[k].field_14;
        out->field_16 = D_80062D08[k].field_16;
        return 0;
    }
    return -1;
}


void SsUtSetReverbDelay(s16 arg0) {
    D_80062C18.field_0 = 8;
    D_80062C18.field_C = arg0;
    SpuSetReverbModeParam(&D_80062C18);
}

void SsUtSetReverbDepth(s16 arg0, s16 arg1) {
    D_80062C18.field_0 = 6;
    D_80062C18.field_8 = arg0 * 0x7FFF / 127;
    D_80062C18.field_A = arg1 * 0x7FFF / 127;
    SpuSetReverbModeParam(&D_80062C18);
}

s16 SsUtSetReverbType(s16 arg0) {
    s32 neg = 0;
    s16 v = arg0;
    s16 r;

    if (arg0 < 0) {
        neg = 1;
        v = -arg0;
    }
    if ((u16)v < 10) {
        Cmd62C18 *c = &D_80062C18;

        c->field_0 = 1;
        if (neg) {
            c->field_4 = (s16)(v | 0x100);
        } else {
            c->field_4 = v;
        }
        r = v;
        if (r == 0) {
            SpuSetReverb(0);
        }
        SpuSetReverbModeParam(&D_80062C18);
        return r;
    }
    return -1;
}

void SsUtSetReverbFeedback(s16 arg0) {
    D_80062C18.field_0 = 0x10;
    D_80062C18.field_10 = arg0;
    SpuSetReverbModeParam(&D_80062C18);
}

void SsUtReverbOff(void) { SpuSetReverb(0); }

void SsUtReverbOn(void) { SpuSetReverb(1); }

s32 SsUtSetVagAtr(a0, a1, a2, src)
s16 a0;
s16 a1;
s16 a2;
Rec62D08 *src;
{
    s16 i;

    if (D_80062D38[a0] == 1) {
        _SsVmVSetUp(a0, a1);
        i = a2 + D_80062D18.field_7 * 16;
        D_80062D08[i].field_0 = src->field_0;
        D_80062D08[i].field_1 = src->field_1;
        D_80062D08[i].field_2 = src->field_2;
        D_80062D08[i].field_3 = src->field_3;
        D_80062D08[i].field_4 = src->field_4;
        D_80062D08[i].field_5 = src->field_5;
        D_80062D08[i].field_7 = src->field_7;
        D_80062D08[i].field_6 = src->field_6;
        D_80062D08[i].field_8 = src->field_8;
        D_80062D08[i].field_9 = src->field_9;
        D_80062D08[i].field_A = src->field_A;
        D_80062D08[i].field_B = src->field_B;
        D_80062D08[i].field_C = src->field_C;
        D_80062D08[i].field_D = src->field_D;
        D_80062D08[i].field_10 = src->field_10;
        D_80062D08[i].field_12 = src->field_12;
        D_80062D08[i].field_14 = src->field_14;
        D_80062D08[i].field_16 = src->field_16;
        return 0;
    }
    return -1;
}

extern u16 D_80062CB0;
void _SsVmDamperOff(void) {
    D_80062CB0 = 0;
}

void _SsVmDamperOn(void) {
    D_80062CB0 = 2;
}

void _SsVmFlush(void) {
    VAttr36C54 attr;
    s32 i;
    s32 m;
    s32 x;
    s32 *masks;
    s32 *q;
    u8 *fl;
    Rec62A48 *r;
    s32 two;
    s32 k;
    Stride16 *p0, *p1, *p2, *p3, *p4, *p5;

    D_80062BCC = (D_80062BCC + 1) & 0xF;
    D_80062BD0[D_80062BCC] = 0;
    masks = D_80062BD0;
    for (i = 0; i < D_80062D0C; i++) {
        SpuGetVoiceEnvelope(i, (u16 *)&D_800624E8[i].field_6);
        if (D_800624E8[i].field_6 == 0) {
            masks[D_80062BCC] |= 1 << i;
        }
    }
    if (*(s8 *)&D_80062D48 == 0) {
        m = -1;
        q = D_80062BD0;
        for (i = 0; i < 15; i++) {
            m &= q[i];
        }
        for (i = 0; i < D_80062D0C; i++) {
            s32 bit;
            two = 2;
            bit = 1 << i;
            if (m & bit) {
                if (D_800624E8[i].field_1D == two) {
                    s16 lo;
                    u8 hi;
                    if (i < 16) {
                        hi = 0;
                        lo = bit;
                    } else {
                        lo = 0;
                        hi = 1 << (i - 16);
                    }
                    SpuSetNoiseVoice(0, (hi << 16) | lo);
                }
                D_800624E8[i].field_1D = 0;
            }
        }
    }
    D_800624D8 &= ~D_80062C10;
    D_800624DA &= ~D_80062C12;
    for (i = 0; i < 24; i++) {
        if (D_800624E8[i].field_1E != 0) {
            D_80062BC8(i);
        }
        if (D_800624E8[i].field_2A != 0) {
            D_80062A40(i);
        }
    }
    i = 0;
    fl = D_80062A28;
    r = (Rec62A48 *)D_80062A48;
    p5 = (Stride16 *)&r->field_A;
    p4 = (Stride16 *)&r->field_8;
    p3 = (Stride16 *)&r->field_6;
    p2 = (Stride16 *)&r->field_4;
    p1 = (Stride16 *)&r->field_2;
    p0 = (Stride16 *)&r->field_0;
    for (; i < 24; i++) {
        attr.mask = 0;
        attr.voice = 1 << i;
        if (*fl & 1) {
            attr.mask = 3;
            attr.vol_l = p0->v;
            attr.vol_r = p1->v;
        }
        if (*fl & 4) {
            attr.mask |= 0x10;
            attr.pitch = p2->v;
        }
        if (*fl & 8) {
            attr.mask |= 0x80;
            attr.addr = p3->v << 3;
        }
        if (*fl & 0x10) {
            attr.mask |= 0x60000;
            attr.adsr1 = p4->v;
            attr.adsr2 = p5->v;
        }
        if (attr.mask != 0) {
            SpuSetVoiceAttr(&attr);
        }
        *fl = 0;
        fl++;
        p5++;
        p4++;
        p3++;
        p2++;
        p1++;
        p0++;
    }
    SpuSetKey(0, ((D_80062C12 & 0xFF) << 16) | D_80062C10);
    SpuSetKey(1, ((D_800624DA & 0xFF) << 16) | D_800624D8);
    k = 0xFFFFFF >> (24 - D_80062D0C);
    x = ((D_800624DE << 16) | D_800624DC) & k;
    SpuSetReverbVoice(8, x | (((s32 (*)(void))SpuGetReverbVoice)() & ~k));
    x = ((D_800624E2 << 16) | D_800624E0) & k;
    SpuSetNoiseVoice(8, x | (((s32 (*)(void))SpuGetNoiseVoice)() & ~k));
    D_80062C10 = 0;
    D_80062C12 = 0;
    D_800624D8 = 0;
    D_800624DA = 0;
    D_800624E0 = 0;
    D_800624E2 = 0;
}


void _SsVmInit(s32 arg) {
    VAttr36C54 attr;
    s32 n;
    u16 i;
    u16 *p;

    _spu_setInTransfer(0);
    D_80062CB0 = 0;
    SpuInitMalloc(0x20, &D_80062DE0);
    p = D_80062A48;
    for (i = 0; i < 0xC0; i++) {
        p[i] = 0;
    }
    for (i = 0; i < 0x18; i++) {
        D_80062A28[i] = 0;
    }
    D_80062D90 = 0;
    for (i = 0; i < 0x10; i++) {
        D_80062D38[i] = 0;
    }
    n = (s8)arg;
    if ((u32)n >= 0x18) {
        D_80062D0C = 0x18;
    } else {
        D_80062D0C = n;
    }
    attr.mask = 0x60093;
    attr.pitch = 0x1000;
    attr.addr = 0x1000;
    attr.adsr1 = 0x80FF;
    attr.vol_l = 0;
    attr.vol_r = 0;
    attr.adsr2 = 0x4000;
    for (i = 0; i < D_80062D0C; i++) {
        D_800624E8[i].field_2 = 0x18;
        D_800624E8[i].field_0 = 0xFF;
        D_800624E8[i].field_1D = 0;
        D_800624E8[i].field_4 = 0;
        D_800624E8[i].field_6 = 0;
        D_800624E8[i].field_10 = -1;
        D_800624E8[i].field_12 = 0;
        D_800624E8[i].field_14 = 0;
        D_800624E8[i].field_16 = 0xFF;
        D_800624E8[i].field_8 = 0;
        D_800624E8[i].field_C = 0;
        D_800624E8[i].field_A = 0x40;
        D_800624E8[i].field_36 = 0;
        D_800624E8[i].field_1E = 0;
        D_800624E8[i].field_20 = 0;
        D_800624E8[i].field_22 = 0;
        D_800624E8[i].field_24 = 0;
        D_800624E8[i].field_2A = 0;
        D_800624E8[i].field_2C = 0;
        D_800624E8[i].field_2E = 0;
        D_800624E8[i].field_30 = 0;
        D_800624E8[i].field_32 = 0;
        D_800624E8[i].field_26 = 0;
        attr.voice = 1 << i;
        SpuSetVoiceAttr(&attr);
        D_80062D30 = i;
        _SsVmKeyOffNow(1);
    }
    D_80062C18.field_0 = 0;
    D_80062C18.field_8 = 0x3FFF;
    D_80062C18.field_A = 0x3FFF;
    D_80062C18.field_4 = 0;
    D_800624D8 = 0;
    D_800624DA = 0;
    D_80062C10 = 0;
    D_800624DC = 0;
    D_800624DE = 0;
    D_800624E0 = 0;
    D_800624E2 = 0;
    D_80062D48 = 0;
    D_80062CF8 = 0;
    D_80062D10 = 0;
    D_80062CFA = 0x80;
    _SsVmFlush();
}


s32 _SsVmKeyOn(s16 a0, s16 a1, s16 a2, u16 a3, u16 arg4, u16 arg5) {
    s32 a4 = arg4;
    s32 a5 = arg5;
    u8 val[128];
    u8 idx[128];
    Elm354F4 *e;
    s32 ret;
    u8 n;
    u8 i;
    u16 k;

    ret = 0;
    e = &Snd_SeqScores[a0 & 0xFF][(a0 & 0xFF00) >> 8];
    if (_SsVmVSetUp(a1, a2) != 0) {
        return -1;
    }
    D_80062D18.field_14 = a0;
    D_80062D18.field_2 = a3;
    D_80062D18.field_3 = 0;
    if (a0 == 0x21) {
        D_80062D18.field_4 = a4;
    } else {
        D_80062D18.field_4 = a4 * *(e->field_17 + e->field_60) / 127;
    }
    D_80062D18.field_5 = a5;
    D_80062D18.field_A = D_80062CFC[a2].field_1;
    D_80062D18.field_B = D_80062CFC[a2].field_4;
    D_80062D18.field_0 = D_80062CFC[a2].field_0;
    if (D_80062D18.field_7 >= ((Snd62D04 *)D_80062D04)->field_12) {
        return -1;
    }
    if (a4 == 0) {
        ret = _SsVmKeyOff(a0, a1, a2, a3);
    } else {
        n = _SsVmSelectToneAndVag(idx, val);
        for (i = 0; i < n; i++) {
            D_80062D18.field_16 = val[i];
            k = (s8)idx[i] + D_80062D18.field_7 * 16;
            D_80062D18.field_C = idx[i];
            D_80062D18.field_F = D_80062D08[k].field_0;
            D_80062D18.field_D = D_80062D08[k].field_2;
            D_80062D18.field_E = D_80062D08[k].field_3;
            D_80062D18.field_10 = D_80062D08[k].field_4;
            D_80062D18.field_11 = D_80062D08[k].field_5;
            D_80062D18.field_12 = D_80062D08[k].field_1;
            D_80062D18.field_18 = _SsVmAlloc(0);
            if (D_80062D18.field_18 < D_80062D0C) {
                D_800624E8[D_80062D18.field_18].field_1D = 1;
                D_800624E8[D_80062D18.field_18].field_2 = 0;
                D_800624E8[D_80062D18.field_18].field_10 = a0;
                D_800624E8[D_80062D18.field_18].field_18 = D_80062D18.field_1;
                D_800624E8[D_80062D18.field_18].field_12 = D_80062D18.field_7;
                D_800624E8[D_80062D18.field_18].field_14 = a2;
                if (a0 != 0x21) {
                    D_800624E8[D_80062D18.field_18].field_8 = a4;
                    D_800624E8[D_80062D18.field_18].field_C = e->field_17;
                }
                D_800624E8[D_80062D18.field_18].field_A = a5;
                D_800624E8[D_80062D18.field_18].field_36 = D_80062D18.field_4;
                D_800624E8[D_80062D18.field_18].field_16 = (s8)D_80062D18.field_C;
                D_800624E8[D_80062D18.field_18].field_E = a3;
                D_800624E8[D_80062D18.field_18].field_1A = (s8)D_80062D18.field_F;
                D_800624E8[D_80062D18.field_18].field_0 = D_80062D18.field_16;
                _SsVmDoAllocate();
                if (D_80062D18.field_16 == 0xFF) {
                    func_80037D64(D_80062D18.field_18);
                } else {
                    _SsVmKeyOnNow(n, note2pitch());
                }
                ret |= 1 << D_80062D30;
            } else {
                ret = -1;
            }
        }
    }
    return ret;
}


s32 _SsVmKeyOff(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 bit;
    s32 k;
    u8 i;
    s32 n = 0;

    i = 0;
    if (i < D_80062D0C) {
        bit = 1;
        k = a3 & 0xFFFF;
        do {
            s32 m = bit << i;

            if (!(D_8004FC18 & m) && D_800624E8[i].field_E == k && D_800624E8[i].field_14 == (s16)a2 && D_800624E8[i].field_10 == (s16)a0 && D_800624E8[i].field_18 == (s16)a1) {
                if (D_800624E8[i].field_0 == 0xFF) {
                    vmNoiseOff(i);
                } else {
                    D_80062D30 = i;
                    _SsVmKeyOffNow(0);
                }
                n++;
            }
            i++;
        } while (i < D_80062D0C);
    }
    return n;
}

void func_80037620(s32 a0, s32 a1, s32 a2, s32 a3, u16 p4, u16 p5) {
    u16 a;
    u16 b;

    if (p4 == p5) {
        b = 0x40;
        a = p4;
    } else if (p5 < p4) {
        b = (p5 << 6) / p4;
        a = p4;
    } else {
        a = p5;
        b = 0x7F - (p4 << 6) / p5;
    }
    _SsVmKeyOn(0x21, (s16)a0, (s16)a1, (u16)a2, a, b);
}


void func_8003770C(s16 arg0, s16 arg1, u16 arg2) { _SsVmKeyOff(0x21, arg0, arg1, arg2); }

u8 _SsVmAlloc(s32 arg0) {
    u8 res = 99;
    u16 best_ee = 0xFFFF;
    u8 count = 0;
    s32 best_ea = 0;
    u8 cand = 99;
    u8 i = 0;
    u16 prio = D_80062D27;
    s32 bit;
    s32 mask;
    s32 n;

    if (i < D_80062D0C) {
        bit = 1;
        mask = D_8004FC18;
        for (; i < D_80062D0C; i++) {
            s32 m = bit << i;

            if (!(mask & m)) {
                if (D_800624E8[i].field_1D == 0 && D_800624E8[i].field_6 == 0) {
                    res = i;
                    break;
                }
                if (D_800624E8[i].field_1A < prio) {
                    prio = D_800624E8[i].field_1A;
                    cand = i;
                    best_ee = D_800624E8[i].field_6;
                    best_ea = D_800624E8[i].field_2;
                    count = 1;
                } else if (D_800624E8[i].field_1A == prio) {
                    count++;
                    if (D_800624E8[i].field_6 < best_ee) {
                        best_ea = D_800624E8[i].field_2;
                        best_ee = D_800624E8[i].field_6;
                        cand = i;
                    } else if (D_800624E8[i].field_6 == best_ee) {
                        s32 t = D_800624E8[i].field_2;

                        if (best_ea < (s16)D_800624E8[i].field_2) {
                            best_ea = t;
                            cand = i;
                        }
                    }
                }
            }
        }
    }
    if (res == 99) {
        res = cand;
        if (count == 0) {
            res = D_80062D0C;
        }
    }
    if (res < D_80062D0C) {
        for (i = 0; i < D_80062D0C; i++) {
            s32 m = 1 << i;

            if (!(D_8004FC18 & m)) {
                D_800624E8[i].field_2++;
            }
        }
        D_800624E8[res].field_2 = 0;
        D_800624E8[res].field_1A = D_80062D27;
        D_800624E8[res].field_2A = 0;
        D_800624E8[res].field_1E = 0;
    }
    return res;
}

void _SsVmDoAllocate(void) {
    s32 i;
    s16 vi;
    s16 v;
    u16 w;
    u16 x;
    u16 m;
    u16 *d;
    Rec62D08 *r;
    s32 *p;
    s16 *q;

    i = 0;
    x = D_80062D18.field_18;
    vi = x * 8;
    D_800624E8[(s16)x].field_6 = 0x7FFF;
    for (; i < 16; i++) {
        D_80062BD0[i] &= ~(1 << D_80062D18.field_18);
    }
    q = &D_80062D18.field_16;
    x = *q;
    if (((s16)x & 1) > 0) {
        D_80062A4E[vi] = D_80062CFC[((s16)x - 1) / 2].field_C;
        D_80062A28[q[1]] |= 8;
    } else {
        D_80062A4E[vi] = D_80062CFC[((s16)x - 1) / 2].field_E;
        D_80062A28[q[1]] |= 8;
    }
    d = D_80062A50;
    D_80062A50[vi] = (r = &D_80062D08[D_80062D18.field_7 * 16 + (s8)D_80062D18.field_C])->field_10;
    w = r->field_12;
    v = D_80062CB0 + (w & 0x1F);
    m = w & 0xFFE0;
    if (v >= 0x20) {
        v = 0x1F;
    }
    d += vi;
    d[1] = v | m;
    D_80062A28[D_80062D18.field_18] |= 0x30;
}


u16 note2pitch(void) {
    u32 v = D_80062D18.field_11;

    if (v >= 0x80) {
        v = 0x7F;
    }
    return SsPitchFromNote(D_80062D18.field_2, 0, D_80062D18.field_10, v);
}

u16 note2pitch2(s16 a0, s16 a1) {
    s16 i = D_80062D18.field_7 * 16 + (s8)D_80062D18.field_C;
    return SsPitchFromNote(a0, a1, D_80062D08[i].field_4, D_80062D08[i].field_5);
}

s32 SsPitchFromNote(s32 note, s32 fine, s32 center, s32 shift) {
    s16 f = (u8)shift + fine;
    s16 n;
    s16 fr;
    s16 oct;
    s16 idx;
    u32 p;

    n = note + f / 128 - (u8)center;
    fr = f % 128;
    if (fr < 0) {
        fr += 128;
        n--;
        n += fr / 128;
    }
    oct = n / 12 - 2;
    idx = n % 12;
    if (idx < 0) {
        idx += 12;
        oct = n / 12 - 3;
    }
    p = (D_8004FC88[idx] * D_8004FCA0[fr]) >> 16;
    if (oct >= 0) {
        p = 0x3FFF;
    } else {
        p += 1 << (-oct - 1);
        p >>= -oct;
    }
    return (u16)p;
}


void func_80037D64(u8 a0) {
    u32 vol;
    u32 l;
    u32 r;
    Elm354F4 *e;
    u32 pan;
    u32 l2;
    u32 r2;
    s32 lo;
    s32 hi;
    s16 i;
    s32 m;
    u32 v;

    e = &Snd_SeqScores[D_80062D18.field_14 & 0xFF][(D_80062D18.field_14 & 0xFF00) >> 8];
    vol = ((Snd62D04 *)D_80062D04)->field_18 * 0x3FFF;
    vol = D_80062D18.field_4 * (s32)vol / 0x3F01;
    vol = vol * D_80062D18.field_A * D_80062D18.field_D / 0x3F01;
    l = r = vol;
    if (D_80062D18.field_14 != 0x21) {
        l = vol * e->field_58 / 127;
        r = vol * e->field_5A / 127;
    }
    pan = (s8)D_80062D18.field_E;
    if (pan < 0x40) {
        r2 = r * pan / 63;
        l2 = l;
    } else {
        l2 = l * (0x7F - pan) / 63;
        r2 = r;
    }
    pan = (s8)D_80062D18.field_B;
    if (pan < 0x40) {
        r2 = r2 * pan / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    pan = (s8)D_80062D18.field_5;
    if (pan < 0x40) {
        r2 = pan * r2 / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    if (D_80062CF8 == 1) {
        if (l2 < r2) {
            l2 = r2;
        } else {
            r2 = l2;
        }
    }
    if (D_80062D18.field_14 != 0x21) {
        l2 = l2 * l2 / 0x3FFF;
        r2 = r2 * r2 / 0x3FFF;
    }
    v = a0;
    SpuSetNoiseClock((D_80062D18.field_2 - (s8)D_80062D18.field_10) & 0x3F);
    ((Snd62A28 *)D_80062A28)->regs[v].vol_r = r2;
    D_80062A48[v * 8] = l2;
    D_80062A28[v] |= 3;
    if (v < 16) {
        lo = 1 << v;
        hi = 0;
    } else {
        lo = 0;
        hi = 1 << (v - 16);
    }
    D_800624E8[a0].field_4 = 10;
    for (i = 0; i < D_80062D0C; i++) {
        m = 1 << i;
        if (!(D_8004FC18 & m)) {
            D_800624E8[i].field_1D &= 1;
        }
    }
    D_800624E8[a0].field_1D = 2;
    D_800624D8 |= lo;
    D_800624DA |= hi;
    D_80062C10 &= ~D_800624D8;
    D_80062C12 &= ~D_800624DA;
    if (D_80062D18.field_12 & 4) {
        D_800624DC |= lo;
        D_800624DE |= hi;
    } else {
        D_800624DC &= ~lo;
        D_800624DE &= ~hi;
    }
    D_800624E0 = lo;
    D_800624E2 = hi;
}


void vmNoiseOff(u8 arg0) {
    D_800624E8[arg0].field_1D = 0;
    D_800624E8[arg0].field_0 = 0;
    D_800624E8[arg0].field_4 = 0;
}

void _SsVmKeyOffNow(s32 a0) {
    u16 ch = D_80062D30;
    u32 v = ch & 0xFFFF;
    s32 hi;
    s32 lo;
    s32 c10;
    s32 c12;

    if (v < 16) {
        lo = 1 << v;
        hi = 0;
    } else {
        lo = 0;
        hi = 1 << (v - 16);
    }
    D_800624E8[ch].field_1D = 0;
    c10 = D_80062C10;
    c12 = D_80062C12;
    D_800624E8[ch].field_4 = 0;
    D_800624E8[ch].field_0 = 0;
    c10 |= lo;
    D_80062C10 = c10;
    D_800624D8 &= ~c10;
    c12 |= hi;
    D_80062C12 = c12;
    D_800624DA &= ~c12;
}

void _SsVmKeyOnNow(u8 a0, u16 a1) {
    u32 vol;
    u32 l;
    u32 r;
    u16 k;
    s32 lo;
    s32 hi;
    Elm354F4 *e;
    u8 pan;
    u32 l2;
    u32 r2;

    k = D_80062D18.field_18 * 8;
    vol = ((Snd62D04 *)D_80062D04)->field_18 * 0x3FFF;
    vol = D_80062D18.field_4 * (s32)vol / 0x3F01;
    vol = vol * D_80062D18.field_A * D_80062D18.field_D / 0x3F01;
    e = &Snd_SeqScores[D_80062D18.field_14 & 0xFF][(D_80062D18.field_14 & 0xFF00) >> 8];
    l = r = vol;
    if (D_80062D18.field_14 != 0x21) {
        l = vol * e->field_58 / 127;
        r = vol * e->field_5A / 127;
    }
    pan = D_80062D18.field_E;
    if (pan < 0x40) {
        r2 = r * pan / 63;
        l2 = l;
    } else {
        l2 = l * (0x7F - pan) / 63;
        r2 = r;
    }
    pan = D_80062D18.field_B;
    if (pan < 0x40) {
        r2 = r2 * pan / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    pan = D_80062D18.field_5;
    if (pan < 0x40) {
        r2 = r2 * pan / 63;
    } else {
        l2 = l2 * (0x7F - pan) / 63;
    }
    if (D_80062CF8 == 1) {
        if (l2 < r2) {
            l2 = r2;
        } else {
            r2 = l2;
        }
    }
    if (D_80062D18.field_14 != 0x21) {
        l2 = l2 * l2 / 0x3FFF;
        r2 = r2 * r2 / 0x3FFF;
    }
    D_80062A4C[k] = a1;
    D_80062A48[k] = l2;
    D_80062A4A[k] = r2;
    D_80062A28[D_80062D18.field_18] |= 7;
    D_800624E8[D_80062D18.field_18].field_4 = a1;
    if (D_80062D18.field_18 < 16) {
        lo = 1 << D_80062D18.field_18;
        hi = 0;
    } else {
        lo = 0;
        hi = 1 << (D_80062D18.field_18 - 16);
    }
    if (D_80062D18.field_12 & 4) {
        D_800624DC |= lo;
        D_800624DE |= hi;
    } else {
        D_800624DC &= ~lo;
        D_800624DE &= ~hi;
    }
    D_800624E0 &= ~lo;
    D_800624E2 &= ~hi;
    D_800624D8 |= lo;
    D_800624DA |= hi;
    D_80062C10 &= ~D_800624D8;
    D_80062C12 &= ~D_800624DA;
}


s16 _SsVmPBVoice(s16 id, s16 a1, s16 a2, s16 a3, u16 a4) {
    u16 idx;
    u16 base;
    u16 frac;
    s16 d;
    s32 t;
    s32 q;
    s32 ret;

    d = a4 - 0x40;
    if (D_800624E8[id].field_10 == a1 && D_800624E8[id].field_18 == a2 && D_800624E8[id].field_14 == a3) {
    base = D_800624E8[id].field_E;
    idx = D_800624E8[id].field_16 + D_80062D1F * 16;
    if (d > 0) {
        t = d * D_80062D08[idx].field_D;
        q = t / 63;
        base += q;
        frac = (t - q * 63) * 2;
    } else if (d < 0) {
        t = d * D_80062D08[idx].field_C;
        q = t / 64;
        base = base + q - 1;
        frac = (t - q * 64) * 2 + 0x7F;
    } else {
        frac = 0;
    }
    D_80062D18.field_C = D_800624E8[id].field_16;
    D_80062D18.field_18 = id;
    ((Snd62A28 *)D_80062A28)->regs[id].pitch = ((u16 (*)())note2pitch2)(base, frac);
    D_80062A28[id] |= 4;
    return 1;
    }
    return 0;
}

s32 _SsVmPitchBend(s16 a0, s16 a1, s16 a2, s32 a3) {
    s16 i;
    s32 sum;

    _SsVmVSetUp(a1, a2);
    i = 0;
    D_80062D2C[0] = a0;
    sum = 0;
    for (; i < D_80062D0C; i++) {
        sum += _SsVmPBVoice(i, a0, a1, a2, a3);
    }
    return sum;
}


s32 func_80038B74(s16 a0, s16 a1, s32 a2) {
    if (_SsVmVSetUp(a0, a1) != 0) {
        return -1;
    }
    D_80062CFC[a1].field_1 = a2;
    return D_80062CFC[a1].field_1;
}

s16 _SsVmSetSeqVol(s32 a0, s32 a1, s32 a2, s32 a3) {
    Elm354F4 *e;
    s16 i;
    s32 t;
    u32 vol;
    u32 l;
    u32 r;
    s32 l2;
    u16 r2;
    u8 pan;
    u16 *pl;
    s32 id;
    u16 *pr;
    u16 x;

    e = &Snd_SeqScores[a0 & 0xFF][(a0 & 0xFF00) >> 8];
    e->field_58 = a1;
    e->field_5A = a2;
    id = a0;
    if (((volatile Elm354F4 *)e)->field_58 >= 0x7F) {
        e->field_58 = 0x7F;
    }
    if (e->field_5A >= 0x7F) {
        e->field_5A = 0x7F;
    }
    for (i = 0; i < D_80062D0C; i++) {
        s32 m;

        pr = D_80062A4A;
        pl = D_80062A48;
        m = 1 << i;

        if (!(D_8004FC18 & m) && D_800624E8[i].field_10 == (s16)id && D_800624E8[i].field_18 == e->field_26) {
            _SsVmVSetUp(D_800624E8[i].field_18, D_800624E8[i].field_12);
            t = D_800624E8[i].field_8 * *(D_800624E8[i].field_C + e->field_60) / 127 * 0x3FFF;
            vol = ((Snd62D04 *)D_80062D04)->field_18 * t / 0x3F01;
            vol = vol * D_80062CFC[D_800624E8[i].field_14].field_1 * D_80062D08[D_800624E8[i].field_12 * 16 + D_800624E8[i].field_16].field_2 / 0x3F01;
            l = vol * e->field_58 / 127;
            r = vol * e->field_5A / 127;
            pan = D_80062D08[D_800624E8[i].field_12 * 16 + D_800624E8[i].field_16].field_3;
            if (pan < 0x40) {
                r = r * pan / 63;
            } else {
                l = l * (0x7F - pan) / 63;
            }
            pan = D_80062CFC[D_800624E8[i].field_14].field_4;
            if (pan < 0x40) {
                r2 = (u16)r * pan / 63;
            } else {
                r2 = r;
                l = (u16)l * (0x7F - pan) / 63;
            }
            pan = D_800624E8[i].field_A;
            if (pan < 0x40) {
                r2 = r2 * pan / 63;
            } else {
                l = (u16)l * (0x7F - pan) / 63;
            }
            l2 = (u16)l;
            if (D_80062CF8 == 1) {
                if ((u32)l2 < r2) {
                    *(u16 *)&l = r2;
                } else {
                    r2 = l;
                }
                l2 = (u16)l;
            }
            l2 = l2 * l2 / 0x3FFF;
            pl[i * 8] = l2;
            pr[i * 8] = r2 * r2 / 0x3FFF;
            D_80062A28[i] |= 3;
        }
    }
    return id;
}

s16 _SsVmGetSeqVol(s32 a0, u16 *a1, u16 *a2) {
    Elm354F4 *base = Snd_SeqScores[a0 & 0xFF];
    Elm354F4 *e;

    D_80062D2C[0] = a0;
    e = &base[(a0 & 0xFF00) >> 8];
    *a1 = e->field_58;
    *a2 = e->field_5A;
    return D_80062D2C[0];
}

void _SsVmSeqKeyOff(s32 id) {
    u8 i;

    for (i = 0; i < D_80062D0C; i++) {
        s32 m = 1 << i;

        if (!(D_8004FC18 & m) && D_800624F8[i].field_0 == (s16)id) {
            D_80062D30 = i;
            _SsVmKeyOffNow(0);
        }
    }
}

u8 _SsVmSelectToneAndVag(u8 *idx, u8 *val) {
    u8 n = 0;
    s8 i;

    for (i = 0; i < D_80062D18.field_0; i++) {
        Rec62D08 *r = &D_80062D08[D_80062D18.field_7 * 16 + i];

        if (D_80062D18.field_2 >= r->field_6 && D_80062D18.field_2 <= r->field_7) {
            val[n] = r->field_16;
            idx[n++] = i;
        }
    }
    return n;
}

s32 func_80039334(s16 a0, s16 a1, s16 a2, u16 a3, u16 a4) {
    Elm354F4 *e;
    Rec62D08 *rec;
    s16 i;
    s32 n;
    s32 t;
    u32 vol;
    u32 l;
    u32 r;
    u32 l2;
    u32 r2;
    u8 pan;
    s32 v4;
    s32 k;

    n = 0;
    v4 = a4;
    e = &Snd_SeqScores[a0 & 0xFF][(a0 & 0xFF00) >> 8];
    _SsVmVSetUp(a1, a2);
    D_80062D2C[0] = a0;
    if (v4 == 0) {
        v4 = 1;
    }
    if (a3 == 0) {
        a3 = 1;
    }
    for (i = 0; i < D_80062D0C; i++) {
        s32 m = 1 << i;
        s32 c1 = a1;

        if (D_8004FC18 & m) {
            continue;
        }
        if (D_800624F8[i].field_0 != a0) {
            continue;
        }
        if (D_800624FC[i].field_0 != a2) {
            continue;
        }
        if (D_80062500[i].field_0 != c1) {
            continue;
        }
        k = e->field_17;
        if ((&e->field_60[k])[0] != a3 && (&e->field_60[k])[0] == 0) {
            (&e->field_60[k])[0] = 1;
        }
        t = D_800624F0[i].field_0 * a3 / 127;
        do {} while (0);
        vol = ((Snd62D04 *)D_80062D04)->field_18 * 0x3FFF;
        vol = (s32)(t * vol) / 0x3F01;
        t = (s32)vol / 127;
        t = t / 0x3F01;
        vol = vol * D_80062CFC[a2].field_1;
        k = D_800624FA[i].field_0 * 16 + D_800624FE[i].field_0;
        vol = vol * D_80062D08[k].field_2 / 0x3F01;
        l = vol * e->field_58 / 127;
        r = vol * e->field_5A / 127;
        pan = D_80062D08[k].field_3;
        if (pan < 0x40) {
            r2 = r * pan / 63;
            l2 = l;
        } else {
            l2 = l * (0x7F - pan) / 63;
            r2 = r;
        }
        pan = D_80062CFC[D_800624FC[i].field_0].field_4;
        if (pan < 0x40) {
            r2 = r2 * pan / 63;
        } else {
            l2 = l2 * (0x7F - pan) / 63;
        }
        pan = (u8)v4;
        if (pan < 0x40) {
            r2 = r2 * pan / 63;
        } else {
            l2 = l2 * (0x7F - pan) / 63;
        }
        if (D_80062CF8 == 1) {
            if (l2 < r2) {
                l2 = r2;
            } else {
                r2 = l2;
            }
        }
        l2 = l2 * l2 / 0x3FFF;
        r2 = r2 * r2 / 0x3FFF;
        (&D_80062A48[0])[i * 8] = l2;
        (&D_80062A48[1])[i * 8] = r2;
        D_80062A28[i] |= 3;
        n++;
    }
    return n;
}


s32 _SsVmVSetUp(s16 a0, s16 a1) {
    if ((u16)a0 >= 16 || D_80062D38[a0] != 1 || a1 >= D_80062CFA) {
        return -1;
    }
    D_80062D04 = D_80062C70[a0];
    D_80062CFC = D_80062C30[a0];
    D_80062D08 = D_80062CB8[a0];
    D_80062D18.field_1 = a0;
    D_80062D18.field_6 = a1;
    D_80062D18.field_7 = D_80062CFC[a1].field_8;
    return 0;
}


void SsVabClose(s16 id) {
    s32 st;

    if ((u16)id < 16) {
        st = D_80062D38[id];
        if (st < 3) {
            if (st != 0) {
                SpuFree(D_80062D98[id]);
                D_80062D38[id] = 0;
                D_80062D90--;
                if (_spu_getInTransfer() == 1) {
                    _spu_setInTransfer(0);
                }
            }
        }
    }
}

s16 SsVabOpenHead(s32 arg0, s16 arg1) {
    return _SsVabOpenHeadWithMode(arg0, arg1, func_80039A78, 0);
}

s32 func_80039A78(s32 a0, s32 a1, s32 id) {
    s32 r = SpuMalloc(a0, a1);

    if (r == -1) {
        D_80062D38[(s16)id] = 0;
        _spu_setInTransfer(0);
        D_80062D90--;
        return -1;
    }
    return r;
}

s16 func_80039AE4(s32 arg0, s16 arg1, s32 arg2) {
    return _SsVabOpenHeadWithMode(arg0, arg1, Snd_VabFixedAddrAlloc, arg2);
}

s16 func_80039B18(s32 arg0, s16 arg1, s32 arg2) {
    return _SsVabOpenHeadWithMode(arg0, arg1, Snd_VabFixedAddrAlloc, arg2);
}

s32 Snd_VabFixedAddrAlloc(s32 arg0, s32 arg1) {
    return arg1;
}

s32 _SsVabOpenHeadWithMode(u8 *addr, s32 vabid, s32 (*fn)(), s32 mode) {
    s32 vagLens[256];
    s16 id;
    s32 i;
    s32 n;
    u8 vs;
    VabHdr39B54 *vh;
    Prog39B54 *prog;
    u16 *p;
    u8 *q;
    s32 spu;

    id = 16;
    if (_spu_getInTransfer() == 1) {
        return -1;
    }
    _spu_setInTransfer(1);
    if ((s16)vabid >= 16) {
        goto fail;
    }
    {
        if ((s16)vabid == -1) {
            for (i = 0; i < 16; i++) {
                if (D_80062D38[i] == 0) {
                    D_80062D38[i] = 1;
                    D_80062D90++;
                    id = i;
                    break;
                }
            }
        } else if (D_80062D38[(s16)vabid] == 0) {
            D_80062D38[(s16)vabid] = 1;
            D_80062D90++;
            id = (s16)vabid;
        }
    }
    if (id >= 16) {
    fail:
        _spu_setInTransfer(0);
        return -1;
    }
    q = addr;
    D_80062C70[id] = (s32)q;
    q += sizeof(VabHdr39B54);
    vh = (VabHdr39B54 *)addr;
    D_80062D10 = 0;
    if (((u32)vh->form >> 8) != 0x564142) {
        D_80062D38[id] = 0;
        _spu_setInTransfer(0);
        D_80062D90--;
        return -1;
    }
    if ((vh->form & 0xFF) == 'p' && vh->ver >= 5) {
        D_80062CFA = 0x80;
    } else {
        D_80062CFA = 0x40;
    }
    if (vh->ps > D_80062CFA) {
        D_80062D38[id] = 0;
        _spu_setInTransfer(0);
        D_80062D90--;
        return -1;
    }
    D_80062C30[id] = (Ent62CFC *)q;
    prog = (Prog39B54 *)q;
    q += D_80062CFA * sizeof(Prog39B54);
    n = 0;
    for (i = 0; i < D_80062CFA; i++) {
        prog[i].reserved1 = n;
        if (prog[i].tones != 0) {
            n++;
        }
    }
    D_80062CB8[id] = (Rec62D08 *)q;
    q += vh->ps * 16 * sizeof(Rec62D08);
    p = (u16 *)q;
    vs = vh->vs;
    n = 0;
    for (i = 0; i < 256; i++) {
        if (i <= vs) {
            s32 x = *p;
            if (vh->ver < 5) {
                vagLens[i] = x << 2;
            } else {
                vagLens[i] = x << 3;
            }
            n += vagLens[i];
        }
        p++;
    }
    n = (n + 0x3F) & ~0x3F;
    spu = fn(n, mode, id);
    if (spu == -1) {
        return -1;
    }
    if ((u32)(spu + n) > 0x80000) {
        D_80062D38[id] = 0;
        _spu_setInTransfer(0);
        D_80062D90--;
        return -1;
    }
    D_80062D98[id] = spu;
    n = 0;
    for (i = 0; i <= vs; i++) {
        n += vagLens[i];
        if (i % 2 == 0) {
            prog[i / 2].vagLo = (u32)(spu + n) >> 3;
        } else {
            prog[i / 2].vagHi = (u32)(spu + n) >> 3;
        }
    }
    D_80062D50[id] = n;
    D_80062D38[id] = 2;
    return id;
}


s16 SsVabTransBody(s32 a0, s16 id) {
    s32 addr;

    if ((u16)id < 17) {
        if (D_80062D38[id] == 2) {
            addr = D_80062D98[id];
            SpuSetTransferMode(0);
            if (SpuSetTransferStartAddr(addr) != 0) {
                SpuWrite(a0, D_80062D50[id]);
                D_80062D38[id] = 1;
                return id;
            }
        }
    }
    _spu_setInTransfer(0);
    return -1;
}

extern s32 SpuIsTransferCompleted();

s16 SsVabTransCompleted(s16 a0) {
    do { } while (0);
    return SpuIsTransferCompleted(a0);
}
__asm__(".word 0\n.word 0\n");

extern void _SpuInit(s32);

void SpuInit(void) { _SpuInit(0); }

void _SpuInit(s32 a0) {
    s32 i;
    u16 *p;

    ResetCallback();
    _spu_init(a0);
    if (a0 == 0) {
        i = 23;
        p = &D_8004FDE4[23];
        do {
            *p = 0xC000;
            i--;
            p--;
        } while (i >= 0);
    }
    SpuStart();
    D_8004FDBC = 0;
    D_8004FDC0 = 0;
    D_8004FDCC.field_0 = 0;
    D_8004FDCC.field_4 = 0;
    D_8004FDCC.field_6 = 0;
    D_8004FDCC.field_8 = 0;
    D_8004FDCC.field_C = 0;
    D_8004FDC4 = D_800503B8[0];
    _spu_FsetRXX(0xD1, D_800503B8[0], 0);
    D_8004FE88 = 0;
    D_8004FE8C = 0;
    Spu_MemList = 0;
    D_8004FDB8 = 0;
    D_8004FE44 = 0;
    D_8004FDB4 = 0;
    D_8004FDE0 = 0;
    D_8004FDDC = 0;
    D_8004FE14 = 0;
}

void SpuStart(void) {
    if (_spu_isCalled == 0) {
        _spu_isCalled = 1;
        EnterCriticalSection();
        _SpuDataCallback((s32)_spu_FiDMA);
        _spu_EVdma = OpenEvent(0xF0000009, 0x20, 0x2000, 0);
        EnableEvent(_spu_EVdma);
        ExitCriticalSection();
    }
}

ASM_SOURCE("src/main/asm/libapi", OpenEvent);

ASM_SOURCE("src/main/asm/libapi", EnableEvent);

s32 _spu_init(s32 a0) {
    u32 i;
    s32 j;
    volatile u16 *p;
    volatile u16 *q;

    *D_8004FE38 |= 0xB0000;
    D_8004FE44 = 0;
    D_8004FE48 = 0;
    D_8004FE40 = 0;
    ((volatile u16 *)D_8004FE28)[0xC0] = 0;
    ((volatile u16 *)D_8004FE28)[0xC1] = 0;
    ((volatile u16 *)D_8004FE28)[0xD5] = 0;
    _spu_Fw1ts();
    ((volatile u16 *)D_8004FE28)[0xC0] = 0;
    ((volatile u16 *)D_8004FE28)[0xC1] = 0;
    i = 0;
    while (((volatile u16 *)D_8004FE28)[0xD7] & 0x7FF) {
        if (++i > 0xF00) {
            printf(D_80010AA4, D_80010AB4);
            break;
        }
    }
    j = 0;
    p = D_80062EE8;
    D_8004FE4C = 2;
    D_8004FE50 = 3;
    D_8004FE54 = 8;
    D_8004FE58 = 7;
    ((volatile u16 *)D_8004FE28)[0xD6] = 4;
    ((volatile u16 *)D_8004FE28)[0xC2] = 0;
    ((volatile u16 *)D_8004FE28)[0xC3] = 0;
    ((volatile u16 *)D_8004FE28)[0xC6] = 0xFFFF;
    ((volatile u16 *)D_8004FE28)[0xC7] = 0xFFFF;
    ((volatile u16 *)D_8004FE28)[0xCC] = 0;
    ((volatile u16 *)D_8004FE28)[0xCD] = 0;
    do {
        *p++ = 0;
    } while (++j < 10);
    if (a0 == 0) {
        D_8004FE40 = 0x200;
        ((volatile u16 *)D_8004FE28)[0xC8] = 0;
        ((volatile u16 *)D_8004FE28)[0xC9] = 0;
        ((volatile u16 *)D_8004FE28)[0xCA] = 0;
        ((volatile u16 *)D_8004FE28)[0xCB] = 0;
        ((volatile u16 *)D_8004FE28)[0xD8] = 0;
        ((volatile u16 *)D_8004FE28)[0xD9] = 0;
        ((volatile u16 *)D_8004FE28)[0xDA] = 0;
        ((volatile u16 *)D_8004FE28)[0xDB] = 0;
        func_8003A454((s32)D_8004FE68, 0x10);
        q = D_8004FE28;
        for (j = 0; j < 24; j++) {
            q[0] = 0;
            q[1] = 0;
            q[2] = 0x3FFF;
            q[3] = 0x200;
            q[4] = 0;
            q[5] = 0;
            q += 8;
        }
        ((volatile u16 *)D_8004FE28)[0xC4] = 0xFFFF;
        ((volatile u16 *)D_8004FE28)[0xC5] = 0xFF;
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        ((volatile u16 *)D_8004FE28)[0xC6] = 0xFFFF;
        ((volatile u16 *)D_8004FE28)[0xC7] = 0xFF;
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
    }
    Spu_InTransfer = 1;
    ((volatile u16 *)D_8004FE28)[0xD5] = 0xC000;
    D_8004FE60 = 0;
    D_8004FE64 = 0;
    return 0;
}


void func_8003A454(u16 *addr, u32 size) {
    u16 status;
    s32 wsize;
    s32 i;
    u32 count;

    ((volatile u16 *)D_8004FE28)[0xD3] = D_8004FE40;
    status = ((volatile u16 *)D_8004FE28)[0xD7] & 0x7FF;
    _spu_Fw1ts();
    while (size != 0) {
        wsize = 0x40;
        if (size <= 0x40) {
            wsize = size;
        }
        for (i = 0; i < wsize; i += 2) {
            ((volatile u16 *)D_8004FE28)[0xD4] = *addr++;
        }
        ((volatile u16 *)D_8004FE28)[0xD5] = (((volatile u16 *)D_8004FE28)[0xD5] & ~0x30) | 0x10;
        _spu_Fw1ts();
        count = 0;
        while (((volatile u16 *)D_8004FE28)[0xD7] & 0x400) {
            if (++count > 0xF00) {
                printf(D_80010AA4, D_80010AC4);
                break;
            }
        }
        _spu_Fw1ts();
        _spu_Fw1ts();
        size -= wsize;
    }
    ((volatile u16 *)D_8004FE28)[0xD5] &= ~0x30;
    count = 0;
    while ((((volatile u16 *)D_8004FE28)[0xD7] & 0x7FF) != status) {
        if (++count > 0xF00) {
            printf(D_80010AA4, D_80010AD8);
            break;
        }
    }
}

void _spu_FiDMA(void) {
    volatile u16 *r;
    u32 i;

    if (D_8004FE78 == 0) {
        _spu_Fw1ts();
    }
    r = D_8004FE28;
    r[0xD5] &= 0xFFCF;
    i = 0;
    while (r[0xD5] & 0x30) {
        if (++i > 0xF00) {
            break;
        }
    }
    if (D_8004FE60 != 0) {
        D_8004FE60();
    } else {
        DeliverEvent(0xF0000009, 0x20);
    }
}

void func_8003A6D0(s32 addr, u16 spuAddr, s32 blocks) {
    D_8004FE28[0xD3] = spuAddr;
    _spu_Fw1ts();
    D_8004FE28[0xD5] |= 0x30;
    blocks <<= 16;
    _spu_Fw1ts();
    _spu_FsetDelayR();
    *D_8004FE2C = addr;
    *D_8004FE30 = blocks | 0x10;
    D_8004FE78 = 1;
    *D_8004FE34 = 0x1000200;
}


s32 _spu_t(s32 mode, ...) {
    u32 *ap;
    u32 t;
    u16 m;
    u32 i;
    s32 c;

    ap = (u32 *)(&mode + 1);
    switch (mode) {
    case 2:
        t = *ap;
        D_8004FE40 = t >> D_8004FE50;
        ((volatile u16 *)D_8004FE28)[0xD3] = t >> D_8004FE50;
        break;
    case 1:
        D_8004FE78 = 0;
        i = 0;
        while (((volatile u16 *)D_8004FE28)[0xD3] != *(u16 *)&D_8004FE40) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        ((volatile u16 *)D_8004FE28)[0xD5] = (((volatile u16 *)D_8004FE28)[0xD5] & ~0x30) | 0x20;
        break;
    case 0:
        D_8004FE78 = 1;
        i = 0;
        while (((volatile u16 *)D_8004FE28)[0xD3] != *(u16 *)&D_8004FE40) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        ((volatile u16 *)D_8004FE28)[0xD5] |= 0x30;
        break;
    case 3:
        m = 0x20;
        if (D_8004FE78 == 1) {
            m = 0x30;
        }
        i = 0;
        while ((((volatile u16 *)D_8004FE28)[0xD5] & 0x30) != m) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        if (D_8004FE78 == 1) {
            _spu_FsetDelayR();
        } else {
            _spu_FsetDelayW();
        }
        ap++;
        c = 0x1000201;
        D_8004FE7C = ap[-1];
        t = *ap;
        D_8004FE80 = t / 64 + (t % 64 != 0);
        *(volatile s32 *)D_8004FE2C = D_8004FE7C;
        *(volatile s32 *)D_8004FE30 = (D_8004FE80 << 16) | 0x10;
        if (D_8004FE78 == 1) {
            c = 0x1000200;
        }
        *(volatile s32 *)D_8004FE34 = c;
        break;
    }
    return 0;
}

s32 _spu_Fw(s32 a0, u32 a1) {
    if (D_8004FE44 == 0) {
        _spu_t(2, D_8004FE40 << D_8004FE50);
        _spu_t(1);
        _spu_t(3, a0, a1);
    } else {
        func_8003A454(a0, a1);
    }
    return a1;
}

s32 _spu_Fr(s32 a0, s32 a1) {
    _spu_t(2, D_8004FE40 << D_8004FE50);
    _spu_t(0);
    _spu_t(3, a0, a1);
    return a1;
}

void _spu_FsetRXX(s32 arg0, u32 arg1, s32 arg2) {
    if (arg2 == 0) {
        D_8004FE28[arg0] = arg1;
    } else {
        D_8004FE28[arg0] = arg1 >> D_8004FE50;
    }
}

u32 _spu_FsetRXXa(s32 idx, u32 a1) {
    u32 v;
    u32 d;
    u16 r;

    if (D_8004FE4C != 0) {
        d = D_8004FE54;
        if (a1 % d) {
            a1 += d;
            a1 &= ~D_8004FE58;
        }
    }
    v = a1 >> D_8004FE50;
    r = v;
    switch (idx) {
    case -1:
        return r;
    case -2:
        return a1;
    default:
        D_8004FE28[idx] = v;
        return a1;
    }
}


s32 _spu_FgetRXXa(s32 a0, s32 a1) {
    u16 x = D_8004FE28[a0];
    if (a1 == -1) return x;
    return x << D_8004FE50;
}

void _spu_FsetPCR(s32 a0) {
    *D_8004FE38 &= 0xFFF8FFFF;
    if (a0 != 0) {
        *D_8004FE38 |= 0x30000;
    } else {
        *D_8004FE38 |= 0x50000;
    }
}

extern u32 *D_8004FE3C;
void _spu_FsetDelayW(void) {
    *D_8004FE3C = (*D_8004FE3C & 0xF0FFFFFF) | 0x20000000;
}

void _spu_FsetDelayR(void) {
    *D_8004FE3C = (*D_8004FE3C & 0xF0FFFFFF) | 0x22000000;
}

void _spu_Fw1ts(void) {
    volatile s32 i;
    volatile s32 x;

    x = 13;
    for (i = 0; i < 60; i++) {
        x *= 13;
    }
}

void _SpuDataCallback(s32 arg0) { DMACallback(4, arg0); }

s32 SpuInitMalloc(s32 n, Hdr3AD44 *h) {
    if (n > 0) {
        h->field_0 = 0x40001010;
        Spu_MemList = h;
        D_8004FE8C = 0;
        D_8004FE88 = n;
        h->field_4 = (0x10000 << D_8004FE50) - 0x1010;
        return n;
    }
    return 0;
}

s32 SpuMalloc(s32 size) {
    s32 i = 0;
    s32 found = -1;
    s32 rev;
    s32 n;
    s32 esz;
    Hdr3AD44 *e;
    u32 ta;
    s32 tb;

    if (D_8004FDC0 == 0) {
        rev = 0;
    } else {
        rev = (0x10000 - D_8004FDC4) << D_8004FE50;
    }
    if (size & ~D_8004FE58) {
        size += D_8004FE58;
    }
    size >>= D_8004FE50;
    size <<= D_8004FE50;

    if (Spu_MemList->field_0 & 0x40000000) {
        found = 0;
    } else {
        _spu_gcSPU();
        for (; i < D_8004FE88; i++) {
            if ((Spu_MemList[i].field_0 & 0x40000000) ||
                ((Spu_MemList[i].field_0 & 0x80000000) && (u32)Spu_MemList[i].field_4 >= (u32)size)) {
                found = i;
                break;
            }
        }
    }
    if (found == -1) {
        return -1;
    }
    e = &Spu_MemList[found];
    if (e->field_0 & 0x40000000) {
        if (found >= D_8004FE88) {
            return -1;
        }
        if ((u32)(e->field_4 - rev) < (u32)size) {
            return -1;
        }
        n = found + 1;
        Spu_MemList[n].field_0 = ((*(volatile u32 *)&e->field_0 & 0x0FFFFFFF) + size) | 0x40000000;
        Spu_MemList[n].field_4 = e->field_4 - size;
        D_8004FE8C = n;
        e->field_4 = size;
        e->field_0 &= 0x0FFFFFFF;
        _spu_gcSPU();
        return Spu_MemList[found].field_0;
    }
    esz = e->field_4;
    if ((u32)size < (u32)esz) {
        n = D_8004FE8C;
        if (n < D_8004FE88) {
            ta = Spu_MemList[n].field_0;
            tb = Spu_MemList[n].field_4;
            Spu_MemList[n].field_0 = (e->field_0 + size) | 0x80000000;
            Spu_MemList[n].field_4 = esz - size;
            D_8004FE8C = n + 1;
            Spu_MemList[n + 1].field_0 = ta;
            Spu_MemList[n + 1].field_4 = tb;
        }
    }
    Spu_MemList[found].field_4 = size;
    Spu_MemList[found].field_0 &= 0x0FFFFFFF;
    _spu_gcSPU();
    return Spu_MemList[found].field_0;
}


void _spu_gcSPU(void) {
    Hdr3AD44 *e;
    Hdr3AD44 *o;
    s32 i;
    s32 j;
    u32 t;
    s32 v;
    s32 n;
    Hdr3AD44 *tab;
    Hdr3AD44 *p;

    i = 0;
    if (D_8004FE8C >= 0) {
        n = D_8004FE8C;
        tab = Spu_MemList;
        do {
            if (tab[i].field_0 & 0x80000000) {
                j = i + 1;
                p = &tab[j];
            scan:
                if ((p++)->field_0 == 0x2FFFFFFF) {
                    j++;
                    goto scan;
                }
                if ((tab[j].field_0 & 0x80000000)
                    && (tab[j].field_0 & 0x0FFFFFFF) == (tab[i].field_0 & 0x0FFFFFFF) + tab[i].field_4) {
                    tab[j].field_0 = 0x2FFFFFFF;
                    tab[i].field_4 += tab[j].field_4;
                    continue;
                }
            }
            i++;
        } while (i <= n);
    }
    for (i = 0; i <= D_8004FE8C; i++) {
        if (Spu_MemList[i].field_4 == 0) {
            Spu_MemList[i].field_0 = 0x2FFFFFFF;
        }
    }
    for (i = 0; i <= D_8004FE8C; i++) {
        if (Spu_MemList[i].field_0 & 0x40000000) {
            break;
        }
        for (j = i + 1; j <= D_8004FE8C; j++) {
            if (Spu_MemList[j].field_0 & 0x40000000) {
                break;
            }
            if ((Spu_MemList[j].field_0 & 0x0FFFFFFF) < (Spu_MemList[i].field_0 & 0x0FFFFFFF)) {
                t = Spu_MemList[i].field_0;
                Spu_MemList[i].field_0 = Spu_MemList[j].field_0;
                v = Spu_MemList[i].field_4;
                Spu_MemList[i].field_4 = Spu_MemList[j].field_4;
                Spu_MemList[j].field_0 = t;
                Spu_MemList[j].field_4 = v;
            }
        }
    }
    for (i = 0; i <= D_8004FE8C; i++) {
        if (Spu_MemList[i].field_0 & 0x40000000) {
            break;
        }
        if (Spu_MemList[i].field_0 == 0x2FFFFFFF) {
            Spu_MemList[i].field_0 = Spu_MemList[D_8004FE8C].field_0;
            Spu_MemList[i].field_4 = Spu_MemList[D_8004FE8C].field_4;
            D_8004FE8C = i;
            break;
        }
    }
    for (i = D_8004FE8C - 1; i >= 0; i--) {
        e = &Spu_MemList[i];
        if (!(e->field_0 & 0x80000000)) {
            break;
        }
        e->field_0 = (e->field_0 & 0x0FFFFFFF) | 0x40000000;
        e->field_4 += Spu_MemList[D_8004FE8C].field_4;
        D_8004FE8C = i;
    }
}


void SpuFree(s32 id) {
    s32 i;
    u32 w;

    for (i = 0; i < D_8004FE88; i++) {
        w = Spu_MemList[i].field_0;
        if (w & 0x40000000) {
            break;
        }
        if (w == id) {
            Spu_MemList[i].field_0 = id | 0x80000000;
            break;
        }
    }
    _spu_gcSPU();
}

void SpuSetNoiseVoice(s32 arg0, s32 arg1) { _SpuSetAnyVoice(arg0, arg1, 0xCA, 0xCB); }

s32 _SpuSetAnyVoice(s32 mode, u32 bits, s32 lo, s32 hi) {
    volatile u16 *r;
    u32 ret;
    u32 h;
    s32 one;
    u32 b;

    r = D_80062D60;
    b = bits;
    if (!(D_8004FE14 & 1)) {
        r = D_8004FE28;
    }
    h = (r[hi] & 0xFF) << 16;
    ret = r[lo] | h;
    one = 1;
    switch (mode) {
        do {} while (0);
    case 1:
        if (D_8004FE14 & 1) {
            u16 *p = &D_80062D60[lo];
            u16 *q = &D_80062D60[hi];
            *p |= b;
            *q |= (b >> 16) & 0xFF;
            D_8004FDE0 |= one << ((lo - 0xC6) >> 1);
        } else {
            D_8004FE28[lo] |= b;
            D_8004FE28[hi] |= (b >> 16) & 0xFF;
        }
        ret |= b & 0xFFFFFF;
        break;
        do {} while (0);
    case 0:
        if (D_8004FE14 & 1) {
            u16 *p = &D_80062D60[lo];
            u16 *q = &D_80062D60[hi];
            *p &= ~b;
            *q &= ~((b >> 16) & 0xFF);
            D_8004FDE0 |= one << ((lo - 0xC6) >> 1);
        } else {
            D_8004FE28[lo] &= ~b;
            D_8004FE28[hi] &= ~((b >> 16) & 0xFF);
        }
        ret &= ~(b & 0xFFFFFF);
        break;
        do {} while (0);
    case 8:
        if (D_8004FE14 & 1) {
            u16 *p = &D_80062D60[lo];
            u16 *q = &D_80062D60[hi];
            *p = b;
            *q = (b >> 16) & 0xFF;
            D_8004FDE0 |= one << ((lo - 0xC6) >> 1);
        } else {
            D_8004FE28[lo] = b;
            D_8004FE28[hi] = (b >> 16) & 0xFF;
        }
        ret = b & 0xFFFFFF;
        break;
    default:
        break;
    }
    return ret & 0xFFFFFF;
}


void SpuGetNoiseVoice(void) { _SpuGetAnyVoice(0xCA, 0xCB); }

s32 _SpuGetAnyVoice(s32 a0, s32 a1) {
    volatile u16 *r = D_8004FE28;
    s32 hi = (r[a1] & 0xFF) << 16;

    return r[a0] | hi;
}

s32 SpuSetNoiseClock(s32 arg0) {
    s32 v;

    if (arg0 < 0) {
        v = 0;
    } else {
        v = arg0;
        if (v >= 0x40) {
            v = 0x3F;
        }
    }
    D_8004FE28[0xD5] = (D_8004FE28[0xD5] & 0xC0FF) | ((v & 0x3F) << 8);
    return v;
}

s32 SpuSetReverb(s32 a0) {
    u16 r;

    switch (a0) {
    case 0:
        r = D_8004FE28[0xD5];
        D_8004FDBC = 0;
        D_8004FE28[0xD5] = r & ~0x80;
        D_8004FE28[0xC2] = 0;
        D_8004FE28[0xC3] = 0;
        D_8004FDCC.field_4 = 0;
        D_8004FDCC.field_6 = 0;
        break;
    case 1:
        if (D_8004FDC0 != a0 && _SpuIsInAllocateArea_(D_8004FDC4) != 0) {
            r = D_8004FE28[0xD5];
            D_8004FDBC = 0;
            D_8004FE28[0xD5] = r & ~0x80;
        } else {
            r = D_8004FE28[0xD5];
            D_8004FDBC = a0;
            D_8004FE28[0xD5] = r | 0x80;
        }
        break;
    }
    return D_8004FDBC;
}

s32 _SpuIsInAllocateArea(u32 addr) {
    Hdr3AD44 *h;
    u32 v;

    if (Spu_MemList == NULL) {
        return 0;
    }
    h = Spu_MemList;
    for (;; h++) {
        v = h->field_0;
        if (v & 0x80000000) {
            continue;
        }
        if (v & 0x40000000) {
            break;
        }
        v &= 0x0FFFFFFF;
        if (v >= addr) {
            return 1;
        }
        if (addr < v + h->field_4) {
            return 1;
        }
    }
    return 0;
}

s32 _SpuIsInAllocateArea_(u32 a0) {
    Hdr3AD44 *p;
    u32 v;
    u32 m1;
    u32 m2;
    u32 m3;

    a0 <<= D_8004FE50;
    if (Spu_MemList == 0) {
        return 0;
    }
    m1 = 0x80000000;
    m2 = 0x40000000;
    m3 = 0xFFFFFFF;
    p = Spu_MemList;
    for (;;) {
        v = p->field_0;
        if (!(v & m1)) {
            if (v & m2) {
                goto zero;
            }
            v &= m3;
            if (v < a0) {
                if (a0 < v + p->field_4) {
                    break;
                }
            } else {
                break;
            }
        }
        p++;
    }
    return 1;
zero:
    return 0;
}


#define REVCPY(d, s) { u8 *_d = (u8 *)(d); u8 *_s = (u8 *)(s); s32 _n; for (_n = 0x43; _n != -1; _n--) { *_d++ = *_s++; } }
s32 SpuSetReverbModeParam(Cmd62C18 *attr) {
    Rev3B994 p;
    s32 mask;
    u32 mode;
    s32 all;
    volatile s32 clear;
    s32 modeSet;
    s32 delaySet;
    s32 fbSet;
    s32 wasOn;
    s32 t;
    s32 m;
    s32 *tbl;
    s32 d;

    wasOn = 0;
    modeSet = 0;
    delaySet = 0;
    clear = 0;
    mask = ((volatile Cmd62C18 *)attr)->field_0;
    fbSet = 0;
    all = mask == 0;
    p.field_0 = 0;
    if (all || (mask & 1)) {
        mode = attr->field_4;
        if (mode & 0x100) {
            mode &= ~0x100;
            clear = 1;
        }
        if (mode >= 10 || (tbl = D_800503B8, _SpuIsInAllocateArea_(D_800503B8[mode]))) {
            return -1;
        }
        modeSet = 1;
        D_8004FDCC.field_0 = mode;
        m = ((volatile Blk4FDCC *)&D_8004FDCC)->field_0;
        tbl += m;
        D_8004FDC4 = *tbl;
        REVCPY(&p, &D_800503E8[m]);
        switch (D_8004FDCC.field_0) {
        case 7:
            D_8004FDCC.field_C = 0x7F;
            D_8004FDCC.field_8 = 0x7F;
            break;
        case 8:
            D_8004FDCC.field_C = 0;
            D_8004FDCC.field_8 = 0x7F;
            break;
        default:
            D_8004FDCC.field_C = 0;
            D_8004FDCC.field_8 = 0;
            break;
        }
    }
    if (all || (mask & 8)) {
        s32 mm = D_8004FDCC.field_0;
        if (mm < 9) {
            if (mm >= 7) {
                delaySet = 1;
                if (!modeSet) {
                    REVCPY(&p, &D_800503E8[((volatile Blk4FDCC *)&D_8004FDCC)->field_0]);
                    p.field_0 = 0xC011C00;
                }
                d = attr->field_C;
                D_8004FDCC.field_8 = d;
                t = (d << 12) / 127;
                p.field_18 = (d << 13) / 127 - p.field_4;
                p.field_1A = t - p.field_6;
                p.field_1C = p.field_1E + t;
                p.field_24 = p.field_26 + t;
                p.field_38 = p.field_3C + t;
                p.field_3A = p.field_3E + t;
            }
        }
    }
    if (all || (mask & 0x10)) {
        s32 mm = D_8004FDCC.field_0;
        if (mm < 9) {
            if (mm >= 7) {
                fbSet = 1;
                if (!modeSet) {
                    if (!delaySet) {
                        REVCPY(&p, &D_800503E8[((volatile Blk4FDCC *)&D_8004FDCC)->field_0]);
                        p.field_0 = 0x80;
                    } else {
                        p.field_0 |= 0x80;
                    }
                }
                d = attr->field_10;
                D_8004FDCC.field_C = d;
                p.field_12 = (d * 0x8100) / 127;
            }
        }
    }
    if (modeSet) {
        wasOn = (((volatile u16 *)D_8004FE28)[0xD5] >> 7) & 1;
        if (wasOn) {
            ((volatile u16 *)D_8004FE28)[0xD5] &= ~0x80;
        }
    } else {
        if (all || (mask & 2)) {
            D_8004FE28[0xC2] = attr->field_8;
            D_8004FDCC.field_4 = attr->field_8;
        }
        if (all || (mask & 4)) {
            D_8004FE28[0xC3] = attr->field_A;
            D_8004FDCC.field_6 = attr->field_A;
        }
        goto done;
    }
    D_8004FE28[0xC2] = 0;
    D_8004FE28[0xC3] = 0;
    D_8004FDCC.field_4 = 0;
    D_8004FDCC.field_6 = 0;
done:
    if (modeSet || delaySet || fbSet) {
        _spu_setReverbAttr(&p);
    }
    if (clear) {
        SpuClearReverbWorkArea(D_8004FDCC.field_0);
    }
    if (modeSet) {
        _spu_FsetRXX(0xD1, D_8004FDC4, 0);
        if (wasOn) {
            D_8004FE28[0xD5] |= 0x80;
        }
    }
    return 0;
}


void _spu_setReverbAttr(Rev3B994 *p) {
    u32 mask;
    s32 all;

    mask = p->field_0;
    all = mask == 0;
    if (all || (mask & 0x1)) {
        D_8004FE28[0xE0] = p->field_4;
    }
    if (all || (mask & 0x2)) {
        D_8004FE28[0xE1] = p->field_6;
    }
    if (all || (mask & 0x4)) {
        D_8004FE28[0xE2] = p->field_8;
    }
    if (all || (mask & 0x8)) {
        D_8004FE28[0xE3] = p->field_A;
    }
    if (all || (mask & 0x10)) {
        D_8004FE28[0xE4] = p->field_C;
    }
    if (all || (mask & 0x20)) {
        D_8004FE28[0xE5] = p->field_E;
    }
    if (all || (mask & 0x40)) {
        D_8004FE28[0xE6] = p->field_10;
    }
    if (all || (mask & 0x80)) {
        D_8004FE28[0xE7] = p->field_12;
    }
    if (all || (mask & 0x100)) {
        D_8004FE28[0xE8] = p->field_14;
    }
    if (all || (mask & 0x200)) {
        D_8004FE28[0xE9] = p->field_16;
    }
    if (all || (mask & 0x400)) {
        D_8004FE28[0xEA] = p->field_18;
    }
    if (all || (mask & 0x800)) {
        D_8004FE28[0xEB] = p->field_1A;
    }
    if (all || (mask & 0x1000)) {
        D_8004FE28[0xEC] = p->field_1C;
    }
    if (all || (mask & 0x2000)) {
        D_8004FE28[0xED] = p->field_1E;
    }
    if (all || (mask & 0x4000)) {
        D_8004FE28[0xEE] = p->field_20;
    }
    if (all || (mask & 0x8000)) {
        D_8004FE28[0xEF] = p->field_22;
    }
    if (all || (mask & 0x10000)) {
        D_8004FE28[0xF0] = p->field_24;
    }
    if (all || (mask & 0x20000)) {
        D_8004FE28[0xF1] = p->field_26;
    }
    if (all || (mask & 0x40000)) {
        D_8004FE28[0xF2] = p->field_28;
    }
    if (all || (mask & 0x80000)) {
        D_8004FE28[0xF3] = p->field_2A;
    }
    if (all || (mask & 0x100000)) {
        D_8004FE28[0xF4] = p->field_2C;
    }
    if (all || (mask & 0x200000)) {
        D_8004FE28[0xF5] = p->field_2E;
    }
    if (all || (mask & 0x400000)) {
        D_8004FE28[0xF6] = p->field_30;
    }
    if (all || (mask & 0x800000)) {
        D_8004FE28[0xF7] = p->field_32;
    }
    if (all || (mask & 0x1000000)) {
        D_8004FE28[0xF8] = p->field_34;
    }
    if (all || (mask & 0x2000000)) {
        D_8004FE28[0xF9] = p->field_36;
    }
    if (all || (mask & 0x4000000)) {
        D_8004FE28[0xFA] = p->field_38;
    }
    if (all || (mask & 0x8000000)) {
        D_8004FE28[0xFB] = p->field_3A;
    }
    if (all || (mask & 0x10000000)) {
        D_8004FE28[0xFC] = p->field_3C;
    }
    if (all || (mask & 0x20000000)) {
        D_8004FE28[0xFD] = p->field_3E;
    }
    if (all || (mask & 0x40000000)) {
        D_8004FE28[0xFE] = p->field_40;
    }
    if (all || (mask & 0x80000000)) {
        D_8004FE28[0xFF] = p->field_42;
    }
}


void SpuSetReverbVoice(s32 arg0, s32 arg1) { _SpuSetAnyVoice(arg0, arg1, 0xCC, 0xCD); }

void SpuGetReverbVoice(void) { _SpuGetAnyVoice(0xCC, 0xCD); }

s32 SpuClearReverbWorkArea(s32 a0) {
    u32 size;
    u32 addr;
    u32 n;
    s32 cont;
    s32 mode;
    s32 wait = 0;
    s32 *p;
    void (*volatile cb)(void) = 0;

    if ((u32)a0 >= 10 || _SpuIsInAllocateArea_(*(p = &D_800503B8[a0])) != 0) {
        return -1;
    }
    if (a0 == 0) {
        size = 0x10 << D_8004FE50;
        addr = 0xFFF0 << D_8004FE50;
    } else {
        size = (0x10000 - *p) << D_8004FE50;
        addr = *p << D_8004FE50;
    }
    mode = D_8004FE44;
    if (mode == 1) {
        D_8004FE44 = 0;
        wait = 1;
    }
    cont = 1;
    if (D_8004FE60 != 0) {
        cb = D_8004FE60;
        D_8004FE60 = 0;
    }
    do {
        n = 0x400;
        if (size <= 0x400) {
            n = size;
            cont = 0;
        }
        _spu_t(2, addr);
        _spu_t(1);
        _spu_t(3, D_8004FE98, n);
        size -= 0x400;
        addr += 0x400;
        WaitEvent(_spu_EVdma);
    } while (cont);
    if (wait) {
        D_8004FE44 = mode;
    }
    if (cb != 0) {
        D_8004FE60 = cb;
    }
    return 0;
}

ASM_SOURCE("src/main/asm/libapi", WaitEvent);

void SpuSetKey(s32 on_off, u32 voice_bit) {
    u32 hi;
    s32 t;
    volatile u16 *p;

    voice_bit &= 0xFFFFFF;
    hi = voice_bit >> 16;
    switch (on_off) {
    case 1:
        if (D_8004FE14 & 1) {
            p = D_80062EE8;
            p[0] = voice_bit;
            p[1] = hi;
            *(volatile s32 *)&D_8004FDE0 |= 1;
            *(volatile s32 *)&D_8004FDDC |= voice_bit;
            if (p[2] & voice_bit) {
                p[2] &= ~voice_bit;
            }
            if (p[3] & hi) {
                p[3] &= ~hi;
            }
        } else {
            D_8004FE28[0xC4] = voice_bit;
            D_8004FE28[0xC5] = hi;
            t = D_8004FDB4 | voice_bit;
            goto store;
        }
        break;
    case 0:
        if (D_8004FE14 & 1) {
            p = D_80062EE8;
            p[2] = voice_bit;
            p[3] = hi;
            *(volatile s32 *)&D_8004FDE0 |= 1;
            *(volatile s32 *)&D_8004FDDC &= ~voice_bit;
            if (p[0] & voice_bit) {
                p[0] &= ~voice_bit;
            }
            if (p[1] & hi) {
                p[1] &= ~hi;
            }
        } else {
            ((volatile u16 *)D_8004FE28)[0xC6] = voice_bit;
            ((volatile u16 *)D_8004FE28)[0xC7] = hi;
            t = *(volatile s32 *)&D_8004FDB4 & ~voice_bit;
        store:
            D_8004FDB4 = t;
        }
        break;
    }
}


u32 SpuWrite(s32 a0, u32 n) {
    if (n > 0x7EFF0) {
        n = 0x7EFF0;
    }
    _spu_Fw(a0, n);
    if (D_8004FE60 == 0) {
        Spu_InTransfer = 0;
    }
    return n;
}

s32 SpuSetTransferStartAddr(u32 addr) {
    if (addr - 0x1010 > 0x7EFE8) {
        return 0;
    }
    D_8004FE40 = _spu_FsetRXXa(-1, addr);
    return D_8004FE40 << D_8004FE50;
}

void SpuSetTransferMode(s32 arg0) {
    s32 v;

    switch (arg0) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    default:
        v = 0;
        break;
    }
    D_8004FDB8 = arg0;
    D_8004FE44 = v;
}

s32 SpuIsTransferCompleted(s32 a0) {
    s32 r;

    if (D_8004FDB8 == 1 || Spu_InTransfer == 1) {
        return 1;
    }
    r = TestEvent(_spu_EVdma);
    if (a0 == 1) {
        if (r == 0) {
            while (TestEvent(_spu_EVdma) == 0) {
            }
        }
        r = 1;
    } else if (r != 1) {
        return r;
    }
    Spu_InTransfer = r;
    return r;
}

ASM_SOURCE("src/main/asm/libapi", TestEvent);

void _spu_setInTransfer(s32 arg0) {
    if (arg0 == 1) {
        Spu_InTransfer = 0;
    } else {
        Spu_InTransfer = 1;
    }
}

s32 _spu_getInTransfer(void) {
    return (Spu_InTransfer ^ 1) != 0;
}

void SpuSetVoiceAttr(VAttr36C54 *arg) {
    s32 ch;
    s32 ch8;
    u32 mask;
    s32 all;
    s32 vol;
    s32 vmode;
    u32 v;
    s32 m;
    volatile s32 i;
    volatile s32 w;

    mask = arg->mask;
    all = mask == 0;
    for (ch = 0; ch < 24; ch++) {
        if (!(arg->voice & (1 << ch))) {
            continue;
        }
        ch8 = ch << 3;
        if (all || (mask & 0x10)) {
            D_8004FE28[(ch << 3) + 2] = arg->pitch;
        }
        if (all || (mask & 0x40)) {
            D_8004FDE4[ch] = arg->sample_note;
        }
        if (all || (mask & 0x20)) {
            D_8004FE28[ch8 + 2] = _spu_note2pitch(D_8004FDE4[ch] >> 8, D_8004FDE4[ch] & 0xFF,
                                                arg->note >> 8, arg->note & 0xFF);
        }
        if (all || (mask & 0x1)) {
            vmode = 0;
            vol = arg->vol_l & 0x7FFF;
            if (all || (mask & 0x4)) {
                switch (arg->volmode_l) {
                case 1:
                    vmode = 0x8000;
                    break;
                case 2:
                    vmode = 0x9000;
                    break;
                case 3:
                    vmode = 0xA000;
                    break;
                case 4:
                    vmode = 0xB000;
                    break;
                case 5:
                    vmode = 0xC000;
                    break;
                case 6:
                    vmode = 0xD000;
                    break;
                case 7:
                    vmode = 0xE000;
                    break;
                }
            }
            if (vmode != 0) {
                if (arg->vol_l >= 0x80) {
                    vol = 0x7F;
                } else if (arg->vol_l < 0) {
                    vol = 0;
                }
            }
            D_8004FE28[ch8] = vol | vmode;
        }
        if (all || (mask & 0x2)) {
            vmode = 0;
            vol = arg->vol_r & 0x7FFF;
            if (all || (mask & 0x8)) {
                switch (arg->volmode_r) {
                case 1:
                    vmode = 0x8000;
                    break;
                case 2:
                    vmode = 0x9000;
                    break;
                case 3:
                    vmode = 0xA000;
                    break;
                case 4:
                    vmode = 0xB000;
                    break;
                case 5:
                    vmode = 0xC000;
                    break;
                case 6:
                    vmode = 0xD000;
                    break;
                case 7:
                    vmode = 0xE000;
                    break;
                }
            }
            if (vmode != 0) {
                if (arg->vol_r >= 0x80) {
                    vol = 0x7F;
                } else if (arg->vol_r < 0) {
                    vol = 0;
                }
            }
            D_8004FE28[ch8 + 1] = vol | vmode;
        }
        if (all || (mask & 0x80)) {
            _spu_FsetRXXa(ch8 | 3, arg->addr);
        }
        if (all || (mask & 0x10000)) {
            _spu_FsetRXXa(ch8 | 7, arg->loop_addr);
        }
        if (all || (mask & 0x20000)) {
            D_8004FE28[ch8 + 4] = arg->adsr1;
        }
        if (all || (mask & 0x40000)) {
            D_8004FE28[ch8 + 5] = arg->adsr2;
        }
        if (all || (mask & 0x800)) {
            v = arg->ar;
            if (v >= 0x80) {
                v = 0x7F;
            }
            m = 0;
            if (all || (mask & 0x100)) {
                if (arg->a_mode == 5) {
                    m = 0x80;
                }
            }
            D_8004FE28[ch8 + 4] = (((volatile u16 *)D_8004FE28)[ch8 + 4] & 0xFF) | ((v | m) << 8);
        }
        if (all || (mask & 0x1000)) {
            v = arg->dr;
            if (v >= 0x10) {
                v = 0xF;
            }
            D_8004FE28[ch8 + 4] = (((volatile u16 *)D_8004FE28)[ch8 + 4] & 0xFF0F) | (v << 4);
        }
        if (all || (mask & 0x2000)) {
            v = arg->sr;
            if (v >= 0x80) {
                v = 0x7F;
            }
            m = 0x100;
            if (all || (mask & 0x200)) {
                switch (arg->s_mode) {
                case 1:
                    m = 0;
                    break;
                case 5:
                    m = 0x200;
                    break;
                case 7:
                    m = 0x300;
                    break;
                }
            }
            D_8004FE28[ch8 + 5] = (((volatile u16 *)D_8004FE28)[ch8 + 5] & 0x3F) | ((v | m) << 6);
        }
        if (all || (mask & 0x4000)) {
            v = arg->rr;
            if (v >= 0x20) {
                v = 0x1F;
            }
            m = 0;
            if (all || (mask & 0x400)) {
                switch (arg->r_mode) {
                case 3:
                    m = 0;
                    break;
                case 7:
                    m = 0x20;
                    break;
                }
            }
            D_8004FE28[ch8 + 5] = (((volatile u16 *)D_8004FE28)[ch8 + 5] & 0xFFC0) | (v | m);
        }
        if (all || (mask & 0x8000)) {
            v = arg->sl;
            if (v >= 0x10) {
                v = 0xF;
            }
            D_8004FE28[ch8 + 4] = (((volatile u16 *)D_8004FE28)[ch8 + 4] & 0xFFF0) | v;
        }
    }
    w = 1;
    for (i = 0; i < 2; i++) {
        w *= 13;
    }
}


u16 _spu_note2pitch(s32 cenHigh, s32 cenLow, s32 noteHigh, s32 noteLow) {
    s16 fine;
    s32 note;
    s32 oct;
    s16 key;
    s16 shift;
    u32 pitch;

    fine = noteLow + cenLow;
    note = (s16)(noteHigh + ((u16)fine >> 7) - cenHigh);
    fine = (u16)fine % 128;
    oct = note / 12;
    shift = oct - 2;
    key = note - oct * 12;
    if (key < 0) {
        key += 12;
        shift = oct - 3;
    }
    pitch = (D_80050298[key] * D_800502B0[(u16)fine]) >> 16;
    if (shift >= 0) {
        pitch = 0x3FFF;
    } else {
        pitch = (pitch + (1 << (-shift - 1))) >> -shift;
    }
    return pitch;
}

s32 _spu_pitch2note(s32 note, s32 fine, u16 pitch) {
    s32 i;
    s32 j;
    s32 k;
    s32 bit = 0;
    s32 n;
    s32 m;
    s32 t;
    u16 f;
    u16 fn;
    u16 nt;
    u16 *p;
    u16 *q;

    if (pitch >= 0x4000) {
        pitch = 0x3FFF;
    }
    for (i = 0; i < 14; i++) {
        if ((pitch >> i) & 1) {
            bit = i;
        }
    }
    pitch = pitch << (15 - bit);
    j = 11;
    p = D_80050298;
    for (; j >= 0; j--) {
        if (pitch >= p[j]) {
            n = j;
            break;
        }
    }
    f = ((u32)pitch << 15) / D_80050298[(u16)n];
    for (k = 127, q = &D_800502B0[127]; k >= 0; k--, q--) {
        if (f >= *q) {
            m = k;
            break;
        }
    }
    t = m + 1;
    m = fine + t;
    fn = m;
    note = note + (bit - 12) * 12 + n + (fn >> 7);
    return ((u16)note << 8) | (fn & 0x7E);
}


void SpuGetVoiceEnvelope(s32 a0, u16 *a1) {
    *a1 = D_8004FE28[a0 * 8 + 6];
}

void SpuSetCommonAttr(Cmd3D124 *a0) {
    s32 mask;
    s32 all;
    s32 mode;
    u16 vl;
    u16 vr;
    u16 *r;
    u16 v;

    vl = 0;
    mask = a0->field_0;
    vr = 0;
    all = mask == 0;
    if (all || (mask & 1)) {
        if (all || (mask & 4)) {
            switch (a0->field_8) {
            case 1:
                mode = 0x8000;
                break;
            case 2:
                mode = 0x9000;
                break;
            case 3:
                mode = 0xA000;
                break;
            case 4:
                mode = 0xB000;
                break;
            case 5:
                mode = 0xC000;
                break;
            case 6:
                mode = 0xD000;
                break;
            case 7:
                mode = 0xE000;
                break;
            case 0:
            default:
                vl = a0->field_4;
                mode = 0;
                break;
            }
        } else {
            vl = a0->field_4;
            mode = 0;
        }
        if (mode != 0) {
            if (a0->field_4 >= 0x80) {
                vl = 0x7F;
            } else if (a0->field_4 < 0) {
                vl = 0;
            } else {
                vl = a0->field_4;
            }
        }
        D_8004FE28[0xC0] = (vl & 0x7FFF) | mode;
    }
    if (all || (mask & 2)) {
        if (all || (mask & 8)) {
            switch (a0->field_A) {
            case 1:
                mode = 0x8000;
                break;
            case 2:
                mode = 0x9000;
                break;
            case 3:
                mode = 0xA000;
                break;
            case 4:
                mode = 0xB000;
                break;
            case 5:
                mode = 0xC000;
                break;
            case 6:
                mode = 0xD000;
                break;
            case 7:
                mode = 0xE000;
                break;
            case 0:
            default:
                vr = a0->field_6;
                mode = 0;
                break;
            }
        } else {
            vr = a0->field_6;
            mode = 0;
        }
        if (mode != 0) {
            if (a0->field_6 >= 0x80) {
                vr = 0x7F;
            } else if (a0->field_6 < 0) {
                vr = 0;
            } else {
                vr = a0->field_6;
            }
        }
        D_8004FE28[0xC1] = (vr & 0x7FFF) | mode;
    }
    if (all || (mask & 0x40)) {
        D_8004FE28[0xD8] = a0->field_10;
    }
    if (all || (mask & 0x80)) {
        D_8004FE28[0xD9] = a0->field_12;
    }
    if (all || (mask & 0x400)) {
        D_8004FE28[0xDA] = a0->field_1C;
    }
    if (all || (mask & 0x800)) {
        D_8004FE28[0xDB] = a0->field_1E;
    }
    if (all || (mask & 0x100)) {
        if (a0->field_14 == 0) {
            D_8004FE28[0xD5] &= ~4;
        } else {
            D_8004FE28[0xD5] |= 4;
        }
    }
    if (all || (mask & 0x200)) {
        if (a0->field_18 == 0) {
            D_8004FE28[0xD5] &= ~1;
        } else {
            D_8004FE28[0xD5] |= 1;
        }
    }
    if (all || (mask & 0x1000)) {
        if (a0->field_20 == 0) {
            D_8004FE28[0xD5] &= ~8;
        } else {
            D_8004FE28[0xD5] |= 8;
        }
    }
    if (all || (mask & 0x2000)) {
        if (a0->field_24 == 0) {
            r = D_8004FE28;
            v = r[0xD5] & ~2;
        } else {
            r = D_8004FE28;
            v = r[0xD5] | 2;
        }
        r[0xD5] = v;
    }
}


void func_8003D4A4(void) {
    func_8003D504();
    Card_Start();
    _bu_init();
}

void func_8003D4D4(void) { Card_Stop(); }

ASM_SOURCE("src/main/asm/libapi", _bu_init);

extern s32 Pad_IsInitialized(void);
extern void InitCARD(s32);
extern void func_8003DBE4(void);
extern void func_8003DAE0(void);
extern void func_8003DB74(void);
extern void func_8003DA04(void);

/* K&R definition: func_8003D4A4 / func_8003FBC4 call it without arguments. */
void func_8003D504(a0)
s32 a0;
{
    s32 s0 = a0;
    s32 s1;
    ChangeClearPAD(0);
    VSync(0);
    s1 = EnterCriticalSection();
    if (Pad_IsInitialized() == 0) {
        s0 = 0;
    }
    InitCARD(s0);
    func_8003DBE4();
    func_8003DAE0();
    func_8003DB74();
    func_8003DA04();
    if (s1 == 1) {
        ExitCriticalSection();
    }
}

s32 Card_Start(void) {
    s32 s = EnterCriticalSection();
    StartCARD();
    ChangeClearPAD(0);
    if (s == 1) {
        ExitCriticalSection();
        return 0;
    }
    return 0;
}

s32 Card_Stop(void) {
    StopCARD();
    func_8003DC24();
    return 0;
}

extern s32 D_800506B8;
void Pad_SetInitialized(s32 a0) {
    D_800506B8 = a0;
}

s32 Pad_IsInitialized(void) {
    return D_800506B8;
}

void func_8003D620(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8003D964();
    EnterCriticalSection();
    func_8003D8EC();
    ExitCriticalSection();
    ChangeClearPAD(0);
    func_8003D770();
    PAD_init(a0, a1, a2, a3);
    D_800506B8 = 1;
}

void func_8003D6B0(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8003D964();
    EnterCriticalSection();
    func_8003D8EC();
    ExitCriticalSection();
    ChangeClearPAD(0);
    func_8003D770();
    InitPAD(a0, a1, a2, a3);
    D_800506B8 = 1;
}

s32 Pad_Start(void) {
    StartPAD();
    ChangeClearPAD(0);
    func_8003D8C4();
    return 1;
}

s32 func_8003D770(void) {
    EnterCriticalSection();
    D_80062F04[0] = func_8003D7E8;
    D_80062F04[1] = func_8003D850;
    D_80062F00 = 0;
    D_80062F0C = 0;
    SysDeqIntRP(1, (u8 *)&D_80062F04[-1]);
    SysEnqIntRP(1, (u8 *)&D_80062F04[-1]);
    ExitCriticalSection();
    return 1;
}


s32 func_8003D7E8(void) {
    volatile s32 i[4];

    D_800506BC->field_A = 0;
    i[0] = 10;
    while (--i[0] != -1) {
    }
    return 0;
}

s32 func_8003D850(void) {
    Flags506C0 *p = D_800506C0;

if (!((p->field_4 & 1) && (p->field_0 & 1))) {
 return 0;
 }
 return 1;
}

ASM_SOURCE("src/main/asm/libapi", InitPAD);

ASM_SOURCE("src/main/asm/libapi", StartPAD);

ASM_SOURCE("src/main/asm/libapi", PAD_init);

ASM_SOURCE("src/main/asm/libapi", func_8003D8C4);

ASM_SOURCE("src/main/asm/libapi", func_8003D8EC);

ASM_SOURCE("src/main/asm/libapi", func_8003D964);

ASM_SOURCE("src/main/asm/libapi", InitCARD);

ASM_SOURCE("src/main/asm/libapi", StartCARD);

ASM_SOURCE("src/main/asm/libapi", StopCARD);

ASM_SOURCE("src/main/asm/libapi", func_8003DA04);

ASM_SOURCE("src/main/asm/libapi", func_8003DA48);

ASM_SOURCE("src/main/asm/libapi", func_8003DA74);

ASM_SOURCE("src/main/asm/libapi", func_8003DAB8);

ASM_SOURCE("src/main/asm/libapi", func_8003DAE0);

ASM_SOURCE("src/main/asm/libapi", func_8003DB74);

ASM_SOURCE("src/main/asm/libapi", func_8003DBE4);

ASM_SOURCE("src/main/asm/libapi", func_8003DC24);

void Card_SaveCallback(void) {
    D_80062FD8 = MemCardCallback(0);
}

void Card_RestoreCallback(void) { MemCardCallback(D_80062FD8); }

s32 *Card_GetStatePtr(void) {
    return &D_80062F80.field_0;
}

void MemCardStart(void) {
    State62F80 *p = &D_80062F80;

    p->field_C = 0;
    p->field_44 = 0;
    Card_ClearTaskStack();
    p->field_0 = 0;
    p->field_4 = 0;
    p->field_8 = 0;
    ((volatile State62F80 *)p)->field_50[1] = 0;
    p->field_14 = -1;
    p->field_48[1] = 1;
    p->field_48[0] = 1;
    p->field_50[0] = ((volatile State62F80 *)p)->field_50[1];
    Card_OpenEvents();
    VSyncCallbacks(7, (s32)Card_OnVSync);
}

void MemCardStop(void) {
    volatile s32 *p = &D_80062F80.field_0;

    while (*p != 0) {
    }
    VSyncCallbacks(7, 0);
    Card_CloseEvents();
}

s32 MemCardExist(s32 arg0) {
    s32 r;

    if (D_80062F80.field_0 <= 0) {
        D_80062F80.field_0 = 1;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_10 = arg0;
        Card_PushTask(Card_InfoTask);
        r = 1;
    } else {
        printf(D_80010B74, arg0);
        r = 0;
    }
    return r;
}

s32 Card_InfoTask(s32 *st) {
    s32 r;
    volatile State62F80 *q;
    s32 m;
    s32 v;
    s32 *e;
    s32 *tbl;
    s32 k;
    s32 c;
    s32 w;
    s32 *pt;
    s32 k2;

    switch (*st) {
    case 0:
        D_80062F54 = 0;
        D_80062F50 = 0;
        *st = 10;
        e = &D_80062F80.field_50[D_80062F80.field_10 >> 4];
        v = *e;
        *e = 0;
        D_800506C8 = v;
    case 10:
        Card_ClearEvents();
        _card_info(D_80062F80.field_10);
        *st = *st + 1;
        break;
    case 11:
        if (Card_GetSwEventBits() == 0) {
            return 0;
        }
        r = Card_WaitSwEvent();
        D_80062F54 = r;
        k = D_80062F80.field_10;
        tbl = D_80062F80.field_48;
        e = &tbl[k >> 4];
        D_800506CC = *e;
        switch (r) {
        case 4:
            if (D_800506CC == 0 && D_800506C8 < 0x80) {
                Card_ClearEvents();
                _card_clear(D_80062F80.field_10);
                *st = 0x15;
                break;
            }
            k = D_80062F80.field_10;
            tbl = D_80062F80.field_48;
            tbl[k >> 4] = 1;
            ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(D_80062F54);
            return 1;
        case 0:
            c = D_80062F80.field_C;
            m = 1 << k;
            if (!(c & m)) {
                D_80062F54 = 4;
            }
            w = D_80062F54;
            *e = 0;
            ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(w);
            return 1;
        case 2:
            if (++D_80062F50 < 3) {
                *st = 10;
                break;
            }
            *e = 1;
            ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(2);
            return 1;
        case 1:
            if (++D_80062F50 < 17) {
                *st = 10;
                break;
            }
            ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(1);
            tbl[D_80062F80.field_10 >> 4] = 0;
            return 1;
        default:
            ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(D_80062F54);
            pt = D_80062F80.field_48;
            pt[D_80062F80.field_10 >> 4] = 0;
            return 1;
        }
        break;
    case 21:
        if (Card_GetHwEventBits() == 0) {
            return 0;
        }
        Card_WaitHwEvent();
        *st = 0;
        break;
    default:
        printf(D_80010B9C);
        break;
    }
    return 0;
}


s32 MemCardAccept(s32 arg0) {
    s32 r;

    if (D_80062F80.field_0 <= 0) {
        D_80062F80.field_0 = 2;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_10 = arg0;
        Card_PushTask(Card_AcceptTask);
        r = 1;
    } else {
        printf(D_80010B74);
        r = 0;
    }
    return r;
}

s32 Card_AcceptTask(s32 *st) {
    s32 r;

    switch (*st) {
    case 0:
        D_80062F5C = 0;
        D_80062F60 = 0;
        D_80062F58 = 0;
        D_80062F68 = 0;
        D_80062F64 = 0;
        (*st)++;
    case 1:
        Card_PushTask(Card_InfoTask);
        *st = 10;
        break;
    case 10:
        switch (D_80062F80.field_4) {
        case 1:
            return 1;
        case 3:
            {
                volatile State62F80 *q = (volatile State62F80 *)&D_80062F80;
                D_80062F68 = 1;
                q->field_C = D_80062F80.field_C | (1 << D_80062F80.field_10);
            }
            Card_ClearEvents();
            _card_clear(D_80062F80.field_10);
            *st = 0x15;
            break;
        case 0:
        set30:
            *st = 30;
            break;
        default:
            return 1;
        }
        break;
    case 21:
        if (Card_GetHwEventBits() == 0) {
            return 0;
        }
        Card_WaitHwEvent();
        *st = 30;
    case 30:
        Card_ClearEvents();
        _card_load(D_80062F90);
        *st = *st + 1;
        break;
    case 31:
        if (Card_GetSwEventBits() == 0) {
            return 0;
        }
        r = Card_WaitSwEvent();
        D_80062F64 = r;
        switch (r) {
        case 0:
            ((volatile State62F80 *)&D_80062F80)->field_4 = D_80062F68 ? 3 : 0;
            return 1;
        case 4:
            Card_ClearEvents();
            _card_info(D_80062F90);
            *st = 0x32;
            break;
        case 2:
            *st = 1;
            return 0;
        case 1:
            if (++D_80062F5C < 17) {
                goto set30;
            }
        default:
            ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(D_80062F64);
            return 1;
        }
        break;
    case 50:
        if (Card_GetSwEventBits() == 0) {
            return 0;
        }
        r = Card_WaitSwEvent();
        D_80062F64 = r;
        if (r == 0) {
            ((volatile State62F80 *)&D_80062F80)->field_4 = 4;
            return 1;
        }
        *st = 1;
        break;
    default:
        return 0;
    }
    return 0;
}


s32 MemCardOpen(s32 a0, s32 a1, s32 a2) {
    s32 tries;
    s32 r;
    s32 st;

    tries = 0;
    if (D_80062F80.field_14 >= 0) {
        printf(D_80010C70);
        return -1;
    }
    Card_MakeDevName(a0, D_80062F80.field_24);
    strcat(D_80062F80.field_24, a1);
    D_80062F80.field_10 = a0;
    do {
    retry:
        r = open(D_80062F80.field_24, 1);
        if (r >= 0) {
            goto ok;
        }
        D_80062FD8 = MemCardCallback(0);
        if (D_80062F80.field_0 > 0) {
            printf(D_80010B74);
        } else {
            D_80062F80.field_0 = 2;
            D_80062F80.field_4 = 0;
            D_80062F80.field_8 = 0;
            D_80062F90 = a0;
            Card_PushTask(Card_AcceptTask);
        }
        MemCardSync(0, NULL, &st);
        MemCardCallback(D_80062FD8);
        if (st == 3) {
            goto retry;
        }
        if (st != 2) {
            break;
        }
    } while (++tries < 5);
    if (st == 0) {
        st = 5;
    }
    return st;
ok:
    close(r);
    Card_ClearEvents();
    D_80062F80.field_14 = open(D_80062F80.field_24, a2 | 0x8000);
    return 0;
}


void Card_CloseFile(void) {
    s32 *p = &D_80062F94;

    if (*p >= 0) {
        close(*p);
        *p = -1;
    }
}

s32 MemCardReadData(s32 a0, s32 a1, s32 a2) {
    char *msg;

    if (D_80062F80.field_14 < 0) {
        msg = D_80010C98;
    } else if (D_80062F80.field_0 > 0) {
        msg = D_80010B74;
    } else if (a2 & 0x7F) {
        msg = D_80010CBC;
    } else if (a1 & 0x7F) {
        msg = D_80010CE8;
    } else {
        D_80062F80.field_0 = 5;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_18 = a1;
        D_80062F80.field_20 = a0;
        D_80062F80.field_1C = a2;
        Card_PushTask(Card_ReadDataTask);
        return 1;
    }
    printf(msg);
    return 0;
}

s32 Card_ReadDataTask(s32 *state) {
    s32 r;

    switch (*state) {
    case 0:
        D_800506D0 = 0;
        *state = 10;
        Card_PushTask(Card_InfoTask);
        return 0;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        while (lseek(D_80062F80.field_14, D_80062F80.field_18, 0) != D_80062F80.field_18) {
        }
        Card_ClearEvents();
        while (read(D_80062F80.field_14, D_80062F80.field_20, D_80062F80.field_1C) != 0) {
        }
        *state = 30;
        break;
    case 30:
        if (Card_GetSwEventBits() == 0) {
            return 0;
        }
        r = Card_WaitSwEvent();
        if (r == 0) {
            goto fail;
        }
        if (++D_800506D0 < 4) {
            *state = 10;
            break;
        }
        if (r == 4) {
            Card_ClearEvents();
            _card_clear(D_80062F90);
            *state = 32;
            break;
        }
    fail:
        ((volatile State62F80 *)&D_80062F80)->field_4 = Card_EventToMcErr(r);
        return 1;
    case 32:
        if (Card_GetHwEventBits() == 0) {
            return 0;
        }
        Card_WaitHwEvent();
        *state = 0;
        break;
    default:
        return 0;
    }
    return 0;
}


s32 MemCardWriteData(s32 a0, s32 a1, s32 a2) {
    char *msg;

    if (D_80062F80.field_14 < 0) {
        msg = D_80010C98;
    } else if (D_80062F80.field_0 > 0) {
        msg = D_80010B74;
    } else if (a2 & 0x7F) {
        msg = D_80010CBC;
    } else if (a1 & 0x7F) {
        msg = D_80010CE8;
    } else {
        D_80062F80.field_0 = 6;
        D_80062F80.field_4 = 0;
        D_80062F80.field_8 = 0;
        D_80062F80.field_18 = a1;
        D_80062F80.field_20 = a0;
        D_80062F80.field_1C = a2;
        Card_PushTask(Card_WriteDataTask);
        return 1;
    }
    printf(msg);
    return 0;
}

s32 Card_WriteDataTask(s32 *st) {
    s32 r;

    switch (*st) {
    case 0:
        D_800506D4 = 0;
        Card_PushTask(Card_InfoTask);
        *st = 10;
        break;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        while (lseek(D_80062F80.field_14, D_80062F80.field_18, 0) != D_80062F80.field_18) {
        }
        Card_ClearEvents();
        while (write(D_80062F80.field_14, (u8 *)D_80062F80.field_20, D_80062F80.field_1C) != 0) {
        }
        *st = 30;
        break;
    case 30:
        if (!Card_GetSwEventBits()) {
            return 0;
        }
        r = Card_WaitSwEvent();
        if (r != 0) {
            if (++D_800506D4 < 4) {
                *st = 10;
                break;
            }
            if (r == 4) {
                Card_ClearEvents();
                _card_clear(D_80062F80.field_10);
                *st = 32;
                break;
            }
        }
        {
            State62F80 *g = &D_80062F80;

            g->field_4 = Card_EventToMcErr(r);
        }
        return 1;
    case 32:
        if (!Card_GetHwEventBits()) {
            return 0;
        }
        Card_WaitHwEvent();
        *st = 0;
        break;
    default:
        return 0;
    }
    return 0;
}

s32 MemCardReadFile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (D_80062F80.field_0 > 0) {
        printf(D_80010D18);
        return 0;
    }
    if (D_80062F80.field_14 >= 0) {
        printf(D_80010C70);
        return 0;
    }
    if (a4 & 0x7F) {
        printf(D_80010CBC);
        return 0;
    }
    if (a3 & 0x7F) {
        printf(D_80010CE8);
        return 0;
    }
    Card_MakeDevName(a0, &D_80062F80.field_24);
    strcat(&D_80062F80.field_24, a1);
    D_80062F80.field_0 = 3;
    D_80062F80.field_4 = 0;
    D_80062F80.field_8 = 0;
    D_80062F80.field_18 = a3;
    D_80062F80.field_20 = a2;
    D_80062F80.field_1C = a4;
    D_80062F80.field_10 = a0;
    Card_PushTask(Card_ReadFileTask);
    return 1;
}

s32 Card_ReadFileTask(s32 *a0) {
    State62F80 *p;
    s32 r;

    switch (*a0) {
    case 0:
        D_800506D8 = 0;
        Card_PushTask(Card_InfoTask);
        *a0 = 10;
        break;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        r = open(D_80062F80.field_24, 0x8001);
        D_80062F80.field_14 = r;
        p = &D_80062F80;
        if (r < 0) {
            p->field_4 = 5;
            return 1;
        }
    case 11:
        *a0 = 20;
        Card_PushTask(Card_ReadDataTask);
        return 0;
    case 20:
        close(D_80062F80.field_14);
        D_80062F80.field_14 = -1;
        return 1;
    }
    return 0;
}


s32 MemCardWriteFile(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (D_80062F80.field_0 > 0) {
        printf(D_80010D18);
        return 0;
    }
    if (D_80062F80.field_14 >= 0) {
        printf(D_80010C70);
        return 0;
    }
    if (a4 & 0x7F) {
        printf(D_80010CBC);
        return 0;
    }
    if (a3 & 0x7F) {
        printf(D_80010CE8);
        return 0;
    }
    Card_MakeDevName(a0, D_80062F80.field_24);
    strcat(D_80062F80.field_24, a1);
    D_80062F80.field_0 = 4;
    D_80062F80.field_4 = 0;
    D_80062F80.field_8 = 0;
    D_80062F80.field_18 = a3;
    D_80062F80.field_20 = a2;
    D_80062F80.field_1C = a4;
    D_80062F80.field_10 = a0;
    Card_PushTask(Card_WriteFileTask);
    return 1;
}

s32 Card_WriteFileTask(s32 *st) {
    s32 r;
    s32 *q;
    volatile State62F80 *vp;

    switch (*st) {
    case 0:
        D_800506DC = 0;
        Card_PushTask(Card_InfoTask);
        *st = 10;
        break;
    case 10:
        if (D_80062F80.field_4 != 0) {
            return 1;
        }
        r = open(D_80062F80.field_24, 0x8001);
        D_80062F80.field_14 = r;
        if (r < 0) {
            vp = &D_80062F80;
            vp->field_4 = 5;
            return 1;
        }
    case 11:
        *st = 20;
        Card_PushTask(Card_WriteDataTask);
        break;
    case 20:
        q = &D_80062F94;
        close(*q);
        *q = -1;
        return 1;
    }
    return 0;
}

s32 MemCardGetDirentry(s32 a0_arg, s8 *a1, Ent3EF1C *out_arg, s32 *count_arg, s32 skip, s32 n) {
    s32 a0 = a0_arg;
    Ent3EF1C *out = out_arg;
    s32 *count_out = count_arg;
    s8 buf[0x20];
    Ent3EF1C ent;
    s32 st;
    s32 tries;
    s32 i;
    s32 count;
    s32 r;
    s32 ret;

    if (D_80062F80.field_0 != 0) {
        printf(D_80010D18);
        ret = -1;
        goto end;
    }
    Card_MakeDevName(a0, buf);
    strcat(buf, a1);
    tries = 0;
    i = 0;
    st = 0;
    D_80062F80.field_C |= 1 << a0;
    count = 0;
    for (; i < skip + n; i++) {
        if (i == 0) {
            do {
                Card_ClearEvents();
                r = func_8003F5C4(buf, (s32)&ent);
                if (r != 0) {
                    goto have;
                }
                st = Card_EventToMcErr(Card_WaitHwEvent());
                if (st == 0) {
                    goto have;
                }
            } while (++tries < 4);
            D_80062FD8 = MemCardCallback(0);
            if (D_80062F80.field_0 > 0) {
                printf(D_80010B74);
            } else {
                D_80062F80.field_0 = 2;
                D_80062F80.field_4 = 0;
                D_80062F80.field_8 = 0;
                D_80062F90 = a0;
                Card_PushTask(Card_AcceptTask);
            }
            MemCardSync(0, NULL, &st);
            MemCardCallback(D_80062FD8);
            ret = st;
            goto end;
        } else {
            r = nextfile(&ent);
        }
    have:
        if (r == 0) {
            break;
        }
        if (i >= skip && out != NULL) {
            out[count] = ent;
            count++;
        }
    }
    ret = 0;
    if (count_out != NULL) {
        *count_out = count;
    }
end:
    return ret;
}


int MemCardCallback(int a0) {
    int old = D_80062FC4;
    D_80062FC4 = a0;
    return old;
}

s32 MemCardSync(s32 wait, s32 *a1, s32 *a2) {
    State62F80 *p = &D_80062F80;
    s32 t0;
    s32 a3;

    if (p->field_0 == 0 && p->field_8 == 0) {
        return -1;
    }
    t0 = p->field_0;
    a3 = p->field_4;
    if (wait == 0) {
        if (p->field_8 == 0) {
            volatile s32 *q = &p->field_8;

            do {
            } while (*q == 0);
        }
        if (a2 != 0) {
            *a2 = *(volatile s32 *)&D_80062F74;
        }
        if (a1 != 0) {
            *a1 = *(volatile s32 *)&D_80062F70;
        }
        ((volatile State62F80 *)&D_80062F80)->field_8 = 0;
        return 1;
    }
    if (p->field_8 == 0) {
        if (a2 != 0) {
            *a2 = a3;
        }
        if (a1 == 0) {
            return 0;
        }
        *a1 = t0;
        return 0;
    }
    if (a2 != 0) {
        *a2 = *(volatile s32 *)&D_80062F74;
    }
    if (a1 != 0) {
        *a1 = *(volatile s32 *)&D_80062F70;
    }
    p->field_8 = 0;
    return 1;
}

s32 MemCardCreateFile(s32 a0, s32 a1, s32 a2) {
    u8 buf[0x20];
    s32 r;

    if (D_80062F80.field_0 == 0) {
        goto work;
    }
    printf(D_80010D18);
    return -1;
e1:
    return 7;
e2:
    return 4;
e3:
    return 6;
work:
    Card_MakeDevName(a0, buf);
    strcat(buf, a1);
    D_80062F80.field_C |= 1 << a0;
    r = Card_CreateFile(a0, a1, a2);
    if (r == 0) {
        goto e0;
    }
    if (r == -1) {
        goto e1;
    }
    if (r == -2) {
        goto e2;
    }
    if (r == -3) {
        goto e3;
    }
    if (r == 4) {
        return 2;
    }
    return Card_EventToMcErr(r);
e0:
    return 0;
}

s32 func_8003F3A4(void) {
    State62F80 *s = &D_80062F80;
    s32 r;

    if (s->field_0 != 0) {
        printf(D_80010D18);
        return -1;
    }
    r = func_800401E4();
    if (r != 0) {
        if (r == 4) {
            return 2;
        }
        return Card_EventToMcErr(r);
    }
    return 0;
}

s32 Card_EventToMcErr(s32 a0) {
    s32 r = 0;

    switch (a0) {
    case 0:
        break;
    case 2:
        r = 1;
        break;
    default:
        r = a0 | 0x8000;
        break;
    case 4:
        r = 3;
        break;
    case 1:
        r = 2;
        break;
    }
    return r;
}

void Card_OnVSync(void) {
    State62F80 *s;
    Pair62F70 *d;
    volatile State62F80 *v;

    if (Card_IsTaskStackEmpty() == 0) {
        Card_RunTopTask();
        if (Card_IsTaskStackEmpty() != 0) {
            s = &D_80062F80;
            ((volatile State62F80 *)s)->field_8 = 1;
            d = (Pair62F70 *)&D_80062F70;
            ((volatile Pair62F70 *)d)->field_0 = ((volatile State62F80 *)s)->field_0;
            ((volatile Pair62F70 *)d)->field_4 = ((volatile State62F80 *)s)->field_4;
            ((volatile State62F80 *)s)->field_0 = 0;
            ((volatile State62F80 *)s)->field_4 = 0;
            if (s->field_44 != 0) {
                ((void (*)(s32, s32))s->field_44)(((volatile Pair62F70 *)d)->field_0, ((volatile Pair62F70 *)d)->field_4);
            }
        }
    }
    v = &D_80062F80;
    v->field_50[0]++;
    v->field_50[1]++;
}

void Card_MakeDevName(s32 n, u8 *out) {
    *(Str3F518 *)out = D_80010D38;
    out[2] = n / 16 + '0';
    out[3] = n % 16 + '0';
}


ASM_SOURCE("src/main/asm/libapi", open);

ASM_SOURCE("src/main/asm/libapi", lseek);

ASM_SOURCE("src/main/asm/libapi", read);

ASM_SOURCE("src/main/asm/libapi", close);

ASM_SOURCE("src/main/asm/libapi", nextfile);

s32 func_8003F5C4(s8 *name, s32 a1) {
    Dcb3F760 *e;
    Dcb3F760 *base;
    u32 n;
    s8 *s;
    s8 *d;
    s32 found;

    s = name;
    d = D_80062FE8;
    while (*s >= 0x3B) {
        *d++ = *s++;
    }
    *d = 0;
    n = *(u32 *)0x154 / 0x50;
    base = *(Dcb3F760 **)0x150;
    for (e = base; e < base + n; e++) {
        if (e->field_0 != 0 && strcmp(e->field_0, D_80062FE8) == 0) {
            D_80062FE0 = e->field_34;
            found = 1;
            goto done;
        }
    }
    found = 0;
done:
    if (found == 0) {
        return 0;
    }
    n = *(u32 *)0x154 / 0x50;
    base = *(Dcb3F760 **)0x150;
    for (e = base; e < base + n; e++) {
        if (e->field_0 != 0 && strcmp(e->field_0, D_80062FE8) == 0) {
            e->field_34 = func_8003F760;
            break;
        }
    }
    return firstfile(name, a1);
}


void func_8003F760(s32 *a0, s32 a1, s32 a2) {
    Dcb3F760 *e;
    Dcb3F760 *base;
    u32 n;
    void (*fn)(s32 *, s32, s32);

    if (*a0 == 0) {
        *a0 = 1;
    }
    n = *(u32 *)0x154 / 0x50;
    base = *(Dcb3F760 **)0x150;
    fn = D_80062FE0;
    for (e = base; e < base + n; e++) {
        if (e->field_0 != 0 && strcmp(e->field_0, D_80062FE8) == 0) {
            e->field_34 = fn;
            break;
        }
    }
    D_80062FE0(a0, a1, a2);
}


ASM_SOURCE("src/main/asm/libapi", firstfile);

s8 *strcat(s8 *dst, s8 *src) {
    s8 *ret;
    s32 c;

    if (dst == 0 || src == 0) {
        return 0;
    }
    if (dst + strlen(dst) != src + strlen(src)) {
        ret = dst;
        while (*dst++ != 0) {
        }
        dst--;
        do {
            c = *(u8 *)src++;
            *dst++ = c;
        } while (c != 0);
        return ret;
    }
    return 0;
}


s32 strcmp(s8 *a, s8 *b) {
    if (a == 0 || b == 0) {
        if (a == b) {
            return 0;
        }
        if (a == 0) {
            return -1;
        }
        return 1;
    }
    while (*a == *b++) {
        if (*a++ == 0) {
            return 0;
        }
    }
    return *a - b[-1];
}

ASM_SOURCE("src/main/asm/libapi", _card_info);

ASM_SOURCE("src/main/asm/libapi", _card_load);

extern void _new_card();
extern s32 _card_write();

s32 _card_clear(s32 a0) {
    _new_card(a0);
    return _card_write(a0, 0x3F, 0);
}
__asm__(".word 0\n.word 0\n.word 0\n");

ASM_SOURCE("src/main/asm/libapi", _card_write);

ASM_SOURCE("src/main/asm/libapi", _new_card);

void Card_ClearTaskStack(void) {
    Card_TaskTop = -1;
}

void Card_PushTask(s32 (*fn)(s32 *)) {
    s32 i = Card_TaskTop + 1;
    s32 *p;
    s32 k;

    if (i >= 4) {
        printf(D_80010D44);
        return;
    }
    k = 3;
    p = &Card_TaskWork[i][3];
    Card_TaskTop = i;
    Card_TaskFuncs[i] = fn;
    for (; k >= 0; k--) {
        *p-- = 0;
    }
}

void Card_RunTopTask(void) {
    s32 i = Card_TaskTop;

    if (i >= 0) {
        if (Card_TaskFuncs[i](Card_TaskWork[i]) != 0) {
            Card_TaskTop--;
        }
    }
}

s32 Card_IsTaskStackEmpty(void) {
    return Card_TaskTop >> 31;
}
__asm__(".word 0\n.word 0\n");

int Card_OnSwIoe(void) {
    D_80063080 = 1;
    return 0;
}

extern volatile s32 D_80063084;
int Card_OnSwError(void) {
    D_80063084 = 1;
    return 0;
}

extern volatile s32 D_80063088;
int Card_OnSwTimeout(void) {
    D_80063088 = 1;
    return 0;
}

extern volatile s32 D_8006308C;
int Card_OnSwNewCard(void) {
    D_8006308C = 1;
    return 0;
}

extern volatile s32 D_80063090;
int Card_OnHwIoe(void) {
    D_80063090 = 1;
    return 0;
}

extern volatile s32 D_80063094;
int Card_OnHwError(void) {
    D_80063094 = 1;
    return 0;
}

extern volatile s32 D_80063098;
int Card_OnHwTimeout(void) {
    D_80063098 = 1;
    return 0;
}

extern volatile s32 D_8006309C;
int Card_OnHwNewCard(void) {
    D_8006309C = 1;
    return 0;
}

void func_8003FBC4(void) {
    func_8003D504();
    Card_Start();
    _bu_init();
}

void Card_OpenEvents(void) {
    s32 s;

    s = EnterCriticalSection();
    D_80063060 = OpenEvent(0xF4000001, 4, 0x1000, (s32)Card_OnSwIoe);
    D_80063064 = OpenEvent(0xF4000001, 0x8000, 0x1000, (s32)Card_OnSwError);
    D_80063068 = OpenEvent(0xF4000001, 0x100, 0x1000, (s32)Card_OnSwTimeout);
    D_8006306C = OpenEvent(0xF4000001, 0x2000, 0x1000, (s32)Card_OnSwNewCard);
    D_80063070 = OpenEvent(0xF0000011, 4, 0x1000, (s32)Card_OnHwIoe);
    D_80063074 = OpenEvent(0xF0000011, 0x8000, 0x1000, (s32)Card_OnHwError);
    D_80063078 = OpenEvent(0xF0000011, 0x100, 0x1000, (s32)Card_OnHwTimeout);
    D_8006307C = OpenEvent(0xF0000011, 0x2000, 0x1000, (s32)Card_OnHwNewCard);
    EnableEvent(D_80063060);
    EnableEvent(D_80063064);
    EnableEvent(D_80063068);
    EnableEvent(D_8006306C);
    EnableEvent(D_80063070);
    EnableEvent(D_80063074);
    EnableEvent(D_80063078);
    EnableEvent(D_8006307C);
    Card_ClearEvents();
    if (s == 1) {
        ExitCriticalSection();
    }
}


void func_8003FDD0(void) { Card_Stop(); }

void Card_CloseEvents(void) {
    s32 s = EnterCriticalSection();

    CloseEvent(D_80063060);
    CloseEvent(D_80063064);
    CloseEvent(D_80063068);
    CloseEvent(D_8006306C);
    CloseEvent(D_80063070);
    CloseEvent(D_80063074);
    CloseEvent(D_80063078);
    CloseEvent(D_8006307C);
    if (s == 1) {
        ExitCriticalSection();
    }
}

void Card_ClearEvents(void) {
    TestEvent(D_80063060);
    TestEvent(D_80063064);
    TestEvent(D_80063068);
    TestEvent(D_8006306C);
    TestEvent(D_80063070);
    TestEvent(D_80063074);
    TestEvent(D_80063078);
    TestEvent(D_8006307C);
    D_80063080 = D_80063084 = D_80063088 = D_8006308C = 0;
    D_80063090 = D_80063094 = D_80063098 = D_8006309C = 0;
}

s32 Card_WaitSwEvent(void) {
    s32 r;

    do {
        r = D_80063080 + D_80063084 * 2 + D_80063088 * 4 + D_8006308C * 8;
    } while (r == 0);
    TestEvent(D_80063070);
    TestEvent(D_80063074);
    TestEvent(D_80063078);
    TestEvent(D_8006307C);
    D_80063080 = D_80063084 = D_80063088 = D_8006308C = 0;
    return r >> 1;
}

s32 Card_WaitHwEvent(void) {
    s32 v;

    do {
        v = D_80063090 + D_80063094 * 2 + D_80063098 * 4 + D_8006309C * 8;
    } while (v == 0);
    TestEvent(D_80063060);
    TestEvent(D_80063064);
    TestEvent(D_80063068);
    TestEvent(D_8006306C);
    D_80063090 = D_80063094 = D_80063098 = D_8006309C = 0;
    return v >> 1;
}

s32 Card_GetSwEventBits(void) {
    return D_80063080 + D_80063084 * 2 + D_80063088 * 4 + D_8006308C * 8;
}

s32 Card_GetHwEventBits(void) {
    return D_80063090 + D_80063094 * 2 + D_80063098 * 4 + D_8006309C * 8;
}

ASM_SOURCE("src/main/asm/libapi", CloseEvent);

static inline s32 mcWriteFrame401E4(s32 port, s32 blk) {
    s32 j = 0;
    u8 *p = D_800632E0;
    u8 c = 0;
    s32 k;
    s32 r;

    for (k = 0; k < 0x7F; k++) {
        c ^= *p++;
    }
    *p = c;
    do {
        Card_ClearEvents();
        _card_write(port, blk, D_800632E0);
        r = Card_WaitHwEvent();
        if (r == 0) break;
        if (r == 4) {
            Card_ClearEvents();
            _card_clear(port);
            Card_WaitHwEvent();
        }
        j++;
    } while (j < 8);
    return r;
}

s32 func_800401E4(s32 a0) {
    s32 i;
    s32 r;
    s32 n = 0;
    u8 *buf;
    McDir401E4 *d;
    s32 *q;

    d = D_800630A0;
    for (i = 0; i < 15; i++, d++) {
        buf = D_800632E0;
        bzero(buf, 0x80);
        bzero((u8 *)d, 0x20);
        D_800630A0[i].field_0 = 0xA0;
        D_800630A0[i].field_4 = 0;
        D_800630A0[i].field_8 = 0xFFFF;
        do { *(McBlk20 *)buf = *(McBlk20 *)d; } while (0);
        r = mcWriteFrame401E4(a0, i + 1);
        if (r != 0) goto out;
    }
    q = D_80063280;
    for (i = 0; i < 20; i++, q++) {
        do { *q = -1; } while (0);
        buf = D_800632E0;
        bzero(buf, 0x80);
        do { *(McBlk4 *)buf = *(McBlk4 *)q; } while (0);
        r = mcWriteFrame401E4(a0, i + 0x10);
        if (r != 0) goto out;
    }
    buf = D_800632E0;
    bzero(buf, 0x80);
    {
        s32 j = 0;
        u8 c = 0;
        s32 k;
        s32 t;

        buf[0] = 'M';
        buf[1] = 'C';
        for (k = 0; k < 0x7F; k++) {
            c ^= *buf++;
        }
        *buf = c;
        do {
            Card_ClearEvents();
            _card_write(a0, 0, D_800632E0);
            t = Card_WaitHwEvent();
            if (t == 0) break;
            if (t == 4) {
                Card_ClearEvents();
                _card_clear(a0);
                Card_WaitHwEvent();
            }
            j++;
        } while (j < 8);
        r = t;
    }
    if (r != 0) goto out;
    do {
        Card_ClearEvents();
        _card_load(a0);
        r = Card_WaitSwEvent();
        if (r == 0) return 0;
        n++;
        Card_ClearEvents();
        _card_clear(a0);
        Card_WaitHwEvent();
    } while (n < 8);
out:
    return r;
}


s32 Card_CreateFile(s32 port, s8 *name, s32 nblocks)
{
    s8 *nm;
    s32 nb;
    s32 free;
    s32 tries;
    s32 i;
    s32 r;
    u32 j;
    s32 prev;
    s32 k;
    u8 *p;
    u8 x;
    s32 ret;
    s8 *u;
    McDir401E4 *d;
    s32 blk;
    s32 n;
    s32 sz;
    s8 *np;

    nm = name;
    nb = nblocks;
    free = 0;
    tries = 0;
    bzero(D_800632E0, 0x80);
    i = 0;
    bzero(D_800632E0, 0x80);
    do {
        Card_ClearEvents();
        _card_read(port, 0, D_800632E0);
        r = Card_WaitHwEvent();
        if (r == 0) {
            break;
        }
        if (r == 4) {
            Card_ClearEvents();
            _card_clear(port);
            Card_WaitHwEvent();
        }
    } while (++i < 8);
    ret = r;
    i = 0;
    if (ret != 0) {
        return ret;
    }
    if (D_800632E0[0] != 'M') {
        return -2;
    }
    if (D_800632E0[1] != 'C') {
        return -2;
    }
    d = D_800630A0;
    blk = 1;
    for (i = 0; i < 15; d++, blk++) {
        D_800632D0[blk - 1] = 0;
        bzero(D_800632E0, 0x80);
        k = 0;
        bzero(D_800632E0, 0x80);
        do {
            Card_ClearEvents();
            _card_read(port, blk, D_800632E0);
            r = Card_WaitHwEvent();
            if (r == 0) {
                break;
            }
            if (r == 4) {
                Card_ClearEvents();
                _card_clear(port);
                Card_WaitHwEvent();
            }
        } while (++k < 8);
        ret = r;
        i++;
        if (ret != 0) {
            return ret;
        }
        do { *(McBlk20 *)d = *(McBlk20 *)D_800632E0; } while (0);
    }
    for (i = 0; i < 15; i++) {
        if (D_800630A0[i].field_0 == 0x51) {
            D_800632D0[i] = 1;
            j = i;
            while (D_800630A0[j].field_8 != 0xFFFF) {
                j = D_800630A0[j].field_8;
                if (j >= 15) {
                    break;
                }
                D_800632D0[j] = 1;
            }
        }
    }
    for (i = 0; i < 15; i++) {
        if (D_800632D0[i] == 0) {
            D_800630A0[i].field_0 = 0xA0;
        }
    }
    for (i = 0; i < 15; i++) {
        if (D_800630A0[i].field_0 == 0x51 && strcmp(D_800630A0[i].field_A, nm) == 0) {
            printf(D_80010D64, D_800630A0[i].field_A, nm);
            return -3;
        }
    }
    for (i = 0; i < 15; i++) {
        D_800632D0[i] = 0;
        if ((D_800630A0[i].field_0 & 0xF0) == 0xA0) {
            free++;
        }
    }
    if (free < nb) {
        return -1;
    }
    free = 0;
    prev = 0;
    sz = nb << 13;
    for (i = 0; i < 15; i++) {
        if ((D_800630A0[i].field_0 & 0xF0) == 0xA0) {
            if (free == 0) {
                D_800630A0[i].field_0 = 0x51;
                D_800630A0[i].field_4 = sz;
                strncpy((u8 *)D_800630A0[i].field_A, (u8 *)nm, 0x14);
                prev = i;
                D_800632D0[i] = 1;
            } else {
                D_800630A0[prev].field_8 = i;
                D_800630A0[i].field_0 = 0x52;
                prev = i;
                D_800632D0[i] = 1;
            }
            free++;
            if (free >= nb) {
                D_800630A0[i].field_8 = 0xFFFF;
                if (free >= 2) {
                    D_800630A0[i].field_0 = 0x53;
                }
                break;
            }
        }
    }
    d = &D_800630A0[14];
    for (i = 14; i >= 0; i--, d--) {
        if (D_800632D0[i] != 0) {
            bzero(D_800632E0, 0x80);
            do { *(McBlk20 *)D_800632E0 = *(McBlk20 *)d; } while (0);
            blk = i + 1;
            k = 0;
            p = D_800632E0;
            x = 0;
            n = 0x7E;
            do {
                x ^= *p++;
            } while (--n >= 0);
            *p = x;
            do {
                Card_ClearEvents();
                _card_write(port, blk, D_800632E0);
                r = Card_WaitHwEvent();
                if (r == 0) {
                    break;
                }
                if (r == 4) {
                    Card_ClearEvents();
                    _card_clear(port);
                    Card_WaitHwEvent();
                }
            } while (++k < 8);
            ret = r;
            k = 0;
            if (ret != 0) {
                return ret;
            }
        }
    }
    do {
        Card_ClearEvents();
        _card_load(port);
        r = Card_WaitSwEvent();
        if (r == 0) {
            return 0;
        }
        Card_ClearEvents();
        _card_clear(port);
        Card_WaitHwEvent();
    } while (++tries < 8);
    return r;
}



u8 *strncpy(u8 *dst, u8 *src, s32 n) {
    u8 *r = 0;

    if (dst != 0 && src != 0) {
        s32 i;
        u8 *d = dst;
        s32 c;

        i = 0;
        if (n > 0) {
            do {
                c = *src++;
                *dst++ = c;
                if (c == 0) {
                    goto inc;
                body:
                    *dst++ = 0;
                inc:
                    i++;
                    if (i < n) goto body;
                    break;
                }
            } while (++i < n);
        }
        r = d;
    }
    return r;
}


ASM_SOURCE("src/main/asm/libapi", _card_read);
