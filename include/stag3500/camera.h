#ifndef STAG3500_CAMERA_H
#define STAG3500_CAMERA_H

/* Functions src/stag3500/camera.c defines. */
s32 Stg35_CamEaseStep(s32 arg0, s32 arg1);
void Stg35_CamEaseToward(Stg35CamWork *w, s32 *t);
void Stg35_CameraUpdate(Actor *arg0);
void Stg35_CameraDraw(Actor *arg0);
void Stg35_SetCameraShot(s32 arg0);

#endif /* STAG3500_CAMERA_H */
