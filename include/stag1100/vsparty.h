#ifndef STAG1100_VSPARTY_H
#define STAG1100_VSPARTY_H

/* Functions src/stag1100/vsparty.c defines. */
void Stg11_VsPartyBuildList(Stg11VsPartyWork *arg0);
void Stg11_VsPartyOpenRowText(Stg11VsPartyWork *arg0, u8 arg1);
void Stg11_VsPartyPick(Actor *arg0);
void Stg11_VsPartyUnpick(Actor *arg0);
void Stg11_VsPartyInit(Actor *arg0, s16 arg1);
void Stg11_VsPartyUpdate(Actor *arg0);
void Stg11_VsPartyDraw(Actor *arg0);

#endif /* STAG1100_VSPARTY_H */
