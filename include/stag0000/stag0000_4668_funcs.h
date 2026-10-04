#ifndef STAG0000_4668_FUNCS_H
#define STAG0000_4668_FUNCS_H

/* Functions src/stag0000/stag0000_4668.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg00_DigiModelDraw(Actor *arg0);
void Stg00_PopupInit(Actor *arg0, Stg00Vec3 *arg1);
void Stg00_PopupTask(Actor *arg0);
void Stg00_PopupDraw(Actor *arg0);
void Stg00_XaPlayInit(Actor *arg0, Stg00Vec3 *arg1);
void Stg00_XaPlayTask(Actor *arg0);
void Stg00_XaPlayDestroy(Actor *arg0);
u8 *Stg00_GetSoundLabel(s32 arg0, s32 arg1);
u8 *Stg00_GetBankLabel(s32 arg0);
u8 *Stg00_GetSoundIdLabel(s32 arg0, s32 arg1);
s32 Stg00_CountSoundBanks(void);
s32 Stg00_CountBankSounds(s32 arg0);
void Stg00_WindowTestTask(Actor *arg0);
void Stg00_WindowTestDraw(Actor *arg0);
void Stg00_SoundTestTask(Actor *arg0);
void Stg00_SoundTestDraw(void);
void Stg00_CameraInit(Actor *arg0, Stg00CameraArg *arg1);
void Stg00_CameraTask(Actor *arg0);
void Stg00_CameraDraw(Actor *arg0);
TaskEntry *Stg00_FindCamera(void);
void Stg00_CamMoveViewPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamMoveRefPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamSetProjection(Actor *arg0, s32 arg1);
void Stg00_CamMoveOrigin(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamRotate(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);

#endif /* STAG0000_4668_FUNCS_H */
