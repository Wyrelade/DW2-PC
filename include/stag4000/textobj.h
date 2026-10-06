#ifndef STAG4000_TEXTOBJ_H
#define STAG4000_TEXTOBJ_H

/* Functions src/stag4000/textobj.c defines. */
Stg40Ent48 *Stg40_FindEntByDigiId(s32 id);
void Stg40_TextObjCommand(s32 *arg);
void Stg40_EndTextObjCmd(void);
s16 Stg40_IsTextObjCmdBusy(void);

#endif /* STAG4000_TEXTOBJ_H */
