#ifndef STAG4000_PLAYER_H
#define STAG4000_PLAYER_H

/* Functions src/stag4000/player.c defines. */
void Stg40_PlayerBugInvade(Actor *arg0);
void Stg40_PlayerAnimThenMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void Stg40_PlayerShowMsg(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
s32 Stg40_PlayerCheckEnemyInfo(Actor *a0);
s32 Stg40_PlayerInteract(Actor *a0);
Stg40Ent48 *Stg40_FindObjAtSameTile(Stg40Ent48 *a0);
s32 Stg40_PlayerCheckStepHazard(Actor *task);
s32 Stg40_PlayerCheckTileEvent(Actor *a0);
s32 Stg40_PlayerCheckSporeBounce(Actor *a0);
void Stg40_PlayerWaitTurn(Actor *a0);
void Stg40_PlayerMoveStep(Actor *a0);
void Stg40_PlayerMoveEnd(Actor *a0);
void Stg40_PlayerAfterAction(Actor *a0);
void Stg40_PlayerEndTurn(Actor *a0);
void Stg40_PlayerShowStatusMsgs(Actor *a0);
void Stg40_PlayerInput(Actor *a0);
void Stg40_PlayerResumeAfterBattle(Actor *a0);
void Stg40_PlayerAnimThenMsgUpdate(Actor *a0);
void Stg40_PlayerWaitAnim(Actor *a0);
void Stg40_PlayerWaitMsg(Actor *a0);
void Stg40_PlayerFoundObject(Actor *a0);
void Stg40_PlayerHurtAnim(Actor *a0);
void Stg40_PlayerDestroyMine(Actor *a0);
void Stg40_PlayerSporeDamage(Actor *a0);
void Stg40_PlayerEnemyInfo(Actor *a0);
void Stg40_PlayerChestTrapPrompt(Actor *a0);
void Stg40_PlayerOpenChest(Actor *a0);
void Stg40_PlayerTakeChestItem(Actor *a0);
void Stg40_PlayerTriggerTrap(Actor *a0);
void Stg40_PlayerExitFloor(Actor *a0);
void Stg40_PlayerShootObstacle(Actor *a0);
void Stg40_ItemMenuRefresh(void);
void Stg40_ItemMenuMoveCursor(void);
void Stg40_PlayerItemMenu(Actor *a0);
void Stg40_PlayerBeetleDown(Actor *a0);
void Stg40_PlayerRunEvent(Actor *a0);
void Stg40_PlayerUpdate(Actor *a0);

#endif /* STAG4000_PLAYER_H */
