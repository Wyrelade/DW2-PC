#ifndef STAG4000_CAMERA_H
#define STAG4000_CAMERA_H

/* Functions src/stag4000/camera.c defines. */
s32 Stg40_CamIsMoving(void);
void Stg40_CamStartMove(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3);
void Stg40_CamLoadScript(Stg40CamCmd *src);
void Stg40_CamNextCommand(Actor *a0);
void Stg40_CamMoveStep(Actor *task);
void Stg40_CameraInit(Actor *a0, Block1C *a1);
void Stg40_CameraUpdate(Actor *a0);
void Stg40_CameraDraw(void);

#endif /* STAG4000_CAMERA_H */
