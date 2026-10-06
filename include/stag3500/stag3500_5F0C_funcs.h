#ifndef STAG3500_5F0C_FUNCS_H
#define STAG3500_5F0C_FUNCS_H

/* Functions src/stag3500/stag3500_5F0C.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
s32 Stg35_CamEaseStep(s32 arg0, s32 arg1);
void Stg35_CamEaseToward(Stg35CamWork *w, s32 *t);
void Stg35_CameraUpdate(Actor *arg0);
void Stg35_CameraDraw(Actor *arg0);
void Stg35_SetCameraShot(s32 arg0);
void Stg35_FindSkillGroup(u8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
void Stg35_BuildCommandList(s32 arg0);
void Stg35_WinBannerInit(Actor *arg0, s32 arg1);
void Stg35_WinBannerUpdate(Actor *arg0);
void Stg35_WinBannerDestroy(Actor *arg0);
void Stg35_WinBannerDraw(Actor *arg0);

#endif /* STAG3500_5F0C_FUNCS_H */
