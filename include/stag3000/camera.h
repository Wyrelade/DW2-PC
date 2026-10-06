#ifndef STAG3000_CAMERA_H
#define STAG3000_CAMERA_H

/* Functions src/stag3000/camera.c defines. */
s32 Stg30_CamEaseStep(s32 a, s32 b);
void Stg30_CamEaseToward(Stg30CamWork *w, Stg30CamGoal *g);
void Stg30_CameraUpdate(Actor *arg0);
void Stg30_CameraDraw(Actor *a0);
void Stg30_SetCameraShot(u8 state);

#endif /* STAG3000_CAMERA_H */
