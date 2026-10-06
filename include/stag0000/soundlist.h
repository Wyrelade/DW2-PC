#ifndef STAG0000_SOUNDLIST_H
#define STAG0000_SOUNDLIST_H

/* Functions src/stag0000/soundlist.c defines. */
u8 *Stg00_GetSoundLabel(s32 arg0, s32 arg1);
u8 *Stg00_GetBankLabel(s32 arg0);
u8 *Stg00_GetSoundIdLabel(s32 arg0, s32 arg1);
s32 Stg00_CountSoundBanks(void);
s32 Stg00_CountBankSounds(s32 arg0);

#endif /* STAG0000_SOUNDLIST_H */
