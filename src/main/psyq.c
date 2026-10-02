#include "common.h"

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PadGetState);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PadStartCom);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PadStopCom);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PadInitDirect);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_InitDriverHooks);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_ResetPortState);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002485C);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_ConsumeSendCmd);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_GetTxByte);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_AllocActPower);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_GetPortBlock);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80024CB8);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_HandleReply);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80025034);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80025114);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_VBlankIrqVerify);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_800251AC);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002533C);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioRunStep);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioXferDataByte);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioExchangeByte);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80025C00);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_WaitSioRx);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SetCmd);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SendInfoCmd);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_ParseInfoReply);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_CalcInfoBufSize);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SetupInfoTables);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SendQueryInfoCmd);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_ParseTableReply);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_CmdConfigMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_CmdQueryModel);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_CmdQueryMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_CmdQueryAct);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_CmdQueryComb);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_800265FC);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SetTimeout);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_IsTimedOut);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_800266D0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioStepSendCmd);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioStepRecvId);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioStepRecv5A);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SioStepRecvData);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", InitHeap);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", EnterCriticalSection);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ExitCriticalSection);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SysEnqIntRP);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SysDeqIntRP);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ChangeClearRCnt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", bzero);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", memcpy);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", memset);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", strcpy);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ResetGraph);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetGraphDebug);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetGrapQue);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetGraphDebug);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DrawSyncCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDispMask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DrawSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", checkRECT);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ClearImage);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ClearImage2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", LoadImage);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StoreImage);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MoveImage);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ClearOTag);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ClearOTagR);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DrawPrim);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DrawOTag);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PutDrawEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DrawOTagEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetDrawEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PutDispEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetDispEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetODE);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDrawArea);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDrawOffset);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_800282CC);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_800284C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", get_mode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", get_cs);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", get_ce);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", get_ofs);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", get_tw);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _status);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _otc);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _clr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _dws);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _drs);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _ctl);

void func_80029118(void) {
}

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _cwb);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _cwc);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _param);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _addque);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _addque2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _exeque);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _reset);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _sync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", set_alarm);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", get_alarm);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _version);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", LoadImage2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StoreImage2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MoveImage2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DrawOTag2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Gpu_RestoreExequeCb);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Mem_FillBytes);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GPU_cw);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", printf);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Debug_VPrintf);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", memchr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Debug_PutChar);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Debug_FlushOut);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Debug_PutCharFlush);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", write);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", strlen);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDefDrawEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDefDispEnv);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", AddPrim);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetPolyF4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDrawMove);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetDrawMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsInitGraph);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002ACC8);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002ADE4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002AE4C);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSortClear);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetDrawBuffOffset);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetDrawBuffClip);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetOffset);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsInitCoordinate2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetLsMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002B4C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetProjection);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetFlatLight);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Gfx_SetLightColorMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Gfx_GetLightColorMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetLightMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetAmbient);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002BB84);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsGetTimInfo);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Math_MakeAxisRotMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsGetLs);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsMulCoord2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsMulCoord3);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsSetRefView2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Math_MulMatrixRotZ);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GsGetLw);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", rsin);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", sin_1);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", rcos);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002CC64);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002CDB8);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002CE54);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002CE5C);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SquareRoot0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ApplyMatrixLV);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002D0D4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PopMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MulMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MulMatrix2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ApplyMatrixSV);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ScaleMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetRotMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetColorMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetTransMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetBackColor);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetFarColor);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetGeomOffset);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetGeomScreen);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", RotTransPers);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", TransposeMatrix);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", RotMatrixYXZ);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ratan2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002DAC4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002DB70);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", FlushCache);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Gte_CountLeadingZeros);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StSetRing);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002DC94);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", def_cbsync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", def_cbready);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", def_cbread);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DeliverEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdPosToInt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdRead2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002DE68);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StClearRing);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StUnSetRing);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002DF74);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002E000);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StSetStream);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StFreeRing);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Cd_ClearStreamSlots);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StGetNext);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StSetMask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8002E2C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Mem_CopyWords);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Cd_StartDma);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", getintr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_sync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_ready);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_cw);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_vol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_flush);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_initvol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_initintr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_init);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_datasync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003024C);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Cd_IntrCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Debug_PutString);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdIntToPos);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdLastCom);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdSetDebug);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdReady);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdSyncCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdReadyCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdControl);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdControlF);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdControlB);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdGetSector);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CD_getsector);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CdDataCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80030A64);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80030A84);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", VSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", v_wait);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ChangeClearPAD);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ResetCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", InterruptCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", DMACallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", VSyncCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", VSyncCallbacks);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StopCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", RestartCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CheckCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetIntrMask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetIntrMask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", startIntr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", trapIntr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", setIntr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", stopIntr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", restartIntr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", memclr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80031394);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _96_remove);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ReturnFromException);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ResetEntryInt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", HookEntryInt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", setjmp);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", longjmp);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", startIntrVSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", trapIntrVSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", setIntrVSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", memclr_vb);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", startIntrDMA);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", trapIntrDMA);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", setIntrDMA);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", memclr_dma);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetVideoMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetVideoMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSeqCalledTbyT);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSndCrescendo);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSndPause);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80031D74);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80031DA4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Snd_SeqEndOfTrack);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsGetSeqData);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsReadDeltaValue);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSndNextSep);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSndReplay);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsClose);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80032820);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSepClose);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSepOpen);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContBankChange);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContDataEntry);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContMainVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContPanpot);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContExpression);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContDamper);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContExternal);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContNrpn1);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContNrpn2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContRpn1);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContRpn2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsContResetAll);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr1);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr3);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsUtResolveADSR);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsUtBuildADSR);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr5);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr6);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr7);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr8);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr9);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr10);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr11);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr12);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr13);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr14);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr15);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr16);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr17);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr18);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetNrpnVabAttr19);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetPitchBend);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetControlChange);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsGetMetaEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsNoteOn);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSetProgramChange);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsInitSoundSeq);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSepPlay);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Snd_SetPlayMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSetSerialAttr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSetMVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsStart);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsStart);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsStart2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsTrapIntrVSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSeqCalledTbyT_1per2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SetRCnt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", GetRCnt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StartRCnt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StopRCnt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", ResetRCnt);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSndStop);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSeqStop);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSepStop);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSetSerialVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSetTableSize);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSetTickMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80035B54);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSeqSetVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsSepSetVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsSndTempo);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtAllKeyOff);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtGetProgAtr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtGetVagAtr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtSetReverbDelay);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtSetReverbDepth);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtSetReverbType);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtSetReverbFeedback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtReverbOff);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtReverbOn);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsUtSetVagAtr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmDamperOff);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmDamperOn);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmFlush);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmKeyOn);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmKeyOff);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80037620);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003770C);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmAlloc);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmDoAllocate);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", note2pitch);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", note2pitch2);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsPitchFromNote);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", vmNoiseOn);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", vmNoiseOff);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmKeyOffNow);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmKeyOnNow);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmPBVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmPitchBend);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80038B74);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmSetSeqVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmGetSeqVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmSeqKeyOff);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmSelectToneAndVag);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmSetVol);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVmVSetUp);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsVabClose);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsVabOpenHead);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80039A78);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80039AE4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_80039B18);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Snd_VabFixedAddrAlloc);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SsVabOpenHeadWithMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsVabTransBody);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SsVabTransCompleted);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SpuInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuStart);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", OpenEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", EnableEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_init);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FwriteByIO);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FiDMA);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003A6D0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_t);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_Fw);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_Fr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FsetRXX);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FsetRXXa);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FgetRXXa);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FsetPCR);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FsetDelayW);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_FsetDelayR);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_Fw1ts);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SpuDataCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuInitMalloc);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuMalloc);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_gcSPU);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuFree);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetNoiseVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SpuSetAnyVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuGetNoiseVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SpuGetAnyVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetNoiseClock);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetReverb);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SpuIsInAllocateArea);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _SpuIsInAllocateArea_);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetReverbModeParam);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_setReverbAttr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetReverbVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuGetReverbVoice);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuClearReverbWorkArea);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", WaitEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetKey);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuWrite);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetTransferStartAddr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetTransferMode);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuIsTransferCompleted);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", TestEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_setInTransfer);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_getInTransfer);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetVoiceAttr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_note2pitch);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _spu_pitch2note);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuGetVoiceEnvelope);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", SpuSetCommonAttr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardInit);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardEnd);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _bu_init);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_Init);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_Start);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_Stop);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_SetInitialized);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_IsInitialized);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D620);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D6B0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Pad_Start);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D770);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D7E8);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D850);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", InitPAD);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StartPAD);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", PAD_init);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D8C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D8EC);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003D964);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", InitCARD);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StartCARD);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", StopCARD);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DA04);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DA48);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DA74);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DAB8);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DAE0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DB74);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DBE4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003DC24);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_SaveCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_RestoreCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_GetStatePtr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardStart);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardStop);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardExist);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_InfoTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardAccept);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_AcceptTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardOpen);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_CloseFile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardReadData);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_ReadDataTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardWriteData);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_WriteDataTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardReadFile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_ReadFileTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardWriteFile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_WriteFileTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardGetDirentry);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardCallback);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardCreateFile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", MemCardFormat);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_EventToMcErr);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnVSync);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_MakeDevName);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", open);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", lseek);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", read);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", close);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", nextfile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003F5C4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003F760);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", firstfile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", strcat);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", strcmp);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _card_info);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _card_load);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _card_clear);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _card_write);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _new_card);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_ClearTaskStack);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_PushTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_RunTopTask);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_IsTaskStackEmpty);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnSwIoe);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnSwError);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnSwTimeout);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnSwNewCard);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnHwIoe);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnHwError);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnHwTimeout);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OnHwNewCard);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003FBC4);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_OpenEvents);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", func_8003FDD0);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_CloseEvents);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_ClearEvents);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_WaitSwEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_WaitHwEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_GetSwEventBits);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_GetHwEventBits);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", CloseEvent);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_Format);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", Card_CreateFile);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", strncpy);

INCLUDE_ASM("asm/USA/main/nonmatchings/psyq", _card_read);
