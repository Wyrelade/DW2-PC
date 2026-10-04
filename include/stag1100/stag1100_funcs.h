#ifndef STAG1100_FUNCS_H
#define STAG1100_FUNCS_H

/* Functions src/stag1100/stag1100.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg11_OpenSlotText(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_RootUpdate(Actor *arg0);
void Stg11_BgUpdate(Actor *arg0);
void Stg11_BgDraw(Actor *arg0);
void Stg11_ModeMenuInit(Actor *arg0, s16 arg1);
void Stg11_ModeMenuUpdate(Actor *arg0);
void Stg11_ModeMenuDraw(Actor *arg0);
void func_80063D20(void);
void Stg11_ConvertCardDigi(Stg11MenuRow *arg0, Stg11CardRec *arg1);
void Stg11_ScanTransferCards(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_OpenTransferText(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_TransferSelected(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_CloseSlotText(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_SetStatusMsg(Stg11MenuWork *arg0, s32 arg1);
void Stg11_SetPromptMsg(Stg11MenuWork *arg0, s32 arg1, s32 arg2);
s32 Stg11_IsPromptFinished(Stg11MenuWork *arg0);
s32 Stg11_WatchCardRemoved(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateWaitCancel(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateCardError(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateCheckCard(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateAskFormat(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateFormat(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateAskCreate(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateCreateFile(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateReadFile(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateSelectSlot(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateWriteSave(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateVsPartySelect(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_StateTransferList(Actor *arg0, Stg11MenuWork *arg1);
void Stg11_CardMenuInit(Actor *arg0, s16 arg1);
void Stg11_CardMenuUpdate(Actor *arg0);

#endif /* STAG1100_FUNCS_H */
