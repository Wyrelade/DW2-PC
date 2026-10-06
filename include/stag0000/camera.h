#ifndef STAG0000_CAMERA_H
#define STAG0000_CAMERA_H

/* Functions src/stag0000/camera.c defines. */
void Stg00_CameraInit(Actor *arg0, Stg00CameraArg *arg1);
void Stg00_CameraTask(Actor *arg0);
void Stg00_CameraDraw(Actor *arg0);
TaskEntry *Stg00_FindCamera(void);
void Stg00_CamMoveViewPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamMoveRefPoint(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamSetProjection(Actor *arg0, s32 arg1);
void Stg00_CamMoveOrigin(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);
void Stg00_CamRotate(Actor *arg0, s32 arg1, s32 arg2, s32 arg3);

#endif /* STAG0000_CAMERA_H */
