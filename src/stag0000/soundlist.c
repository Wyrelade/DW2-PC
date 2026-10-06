#include "common.h"
#include "stag0000/stag0000.h"
#include "stag0000/stag0000_funcs.h"
#include "stag0000/scrollview.h"
#include "stag0000/dungsel.h"
#include "stag0000/font.h"
#include "stag0000/fightbg.h"
#include "stag0000/digiview.h"
#include "stag0000/lineup.h"
#include "stag0000/videomode.h"
#include "stag0000/groupview.h"
#include "stag0000/digimodel.h"

/* Sound test banks: bank name, then its sound files. cc1 writes each table's strings to
 * .rodata right here, last entry first (the retail pool at 0x800634A8). */
u8 *D_80068FE8[] = {
    "COMM00", "BGM_0000", "BGM_0015", "BOX_OPEN", "BUG_0000", "BUG_0001", "BUG_0002", "BUG_0003",
    "BUG_0004", "BUG_0005", "COUNT000", "CURSOR00", "CURSOR01", "CURSOR02", "CURSOR03", "CURSOR04",
    "CURSOR05", "CURSOR06", "CURSOR07", "CURSOR08", "CURSOR09", "CURSOR10", "DEBAGU00", "DEBAGU01",
    "ENEMYOFF", "EXITGATE", "ITEMGET0", "ITEMGET1", "ITEMHIT0", "ITEMLOSE", "ITEMUSE0", "ITEMUSE1",
    "ITEMUSE2", "JISIN000", "LIFT0000", "NAME0001", "NEXTGATE", "PLATE000", "PLATE001", "PLATE002",
    "PLAYER00", "PLAYER01", "PLAYER02", "SIREN000", "TAIMLVUP", "TANK0000", "TANK0001", "TANK0002",
    "TANK0003", "TANK0004", "TITLE000", "TRANS000", "TRAP0000", "TRAP0001", "TRAP0002", "TRAP0003",
    "WINDOW00", "WINDOW01", "WINDOW02", "WINDOW03", 0,
};
u8 *D_800690DC[] = { "MAP001", "BGM_0014", 0 };
u8 *D_800690E8[] = { "MAP002", "BGM_0019", "JOGRESS2", 0 };
u8 *D_800690F8[] = { "MAP003", "BGM_0003", "JOGRESS1", 0 };
u8 *D_80069108[] = { "MAP004", "BGM_001A", "JOGRESS3", 0 };
u8 *D_80069118[] = { "MAP005", "BGM_0005", 0 };
u8 *D_80069124[] = { "MAP006", "BGM_0002", 0 };
u8 *D_80069130[] = { "MAP007", "BGM_0009", "JOGRESS4", 0 };
u8 *D_80069140[] = { "MAP008", "BGM_000A", 0 };
u8 *D_8006914C[] = { "MAP009", "BGM_000B", "JOGRESS6", 0 };
u8 *D_8006915C[] = { "MAP010", "BGM_000D", 0 };
u8 *D_80069168[] = { "MAP011", "BGM_0008", "JOGRESS5", 0 };
u8 *D_80069178[] = { "MAP012", "BGM_0006", 0 };
u8 *D_80069184[] = { "SAVE00", "SAVE0000", 0 };
u8 *D_80069190[] = { "SHOP00", "SHOP0000", 0 };
u8 *D_8006919C[] = { "BOSS00", "BOSS0000", "WF00_000", 0 };
u8 *D_800691AC[] = { "BOSS01", "BOSS0001", "WF00_001", 0 };
u8 *D_800691BC[] = { "BOSS02", "BOSS0002", "WF02_000", 0 };
u8 *D_800691CC[] = { "BOSS03", "BOSS0003", "WF03_000", 0 };
u8 *D_800691DC[] = { "BOSS04", "BOSS0004", "WF04_000", 0 };
u8 *D_800691EC[] = { "BOSS05", "BOSS0005", "WF04_001", 0 };
u8 *D_800691FC[] = { "BOSS06", "BOSS0006", "WF20_000", 0 };
u8 *D_8006920C[] = { "BOSS07", "BOSS0007", "BOSS0008", "WF21_000", 0 };
u8 *D_80069220[] = { "VS2P00", "BUTTON00", "VSDEMO00", "VSMAIN00", "VSMENU00", 0 };
u8 *D_80069238[] = { "SE_D00", "BAT_T000", "BAT_T001", "BAT_T002", "BAT_T004", "DOWN_000", "DOWN_001", "ENCOUNT0", 0 };
/* Unreferenced: the byte between the last string and .text (garbage in retail). */
const u8 D_80063A73 = 0x25;
u8 **Stg00_SoundBanks[] = {
    D_80068FE8, D_800690DC, D_800690E8, D_800690F8, D_80069108, D_80069118, D_80069124,
    D_80069130, D_80069140, D_8006914C, D_8006915C, D_80069168, D_80069178, D_80069184,
    D_80069190, D_8006919C, D_800691AC, D_800691BC, D_800691CC, D_800691DC, D_800691EC,
    D_800691FC, D_8006920C, D_80069220, D_80069238, 0,
};

u8 Stg00_SoundLabelBuf[2][10];

u8 *Stg00_GetSoundLabel(s32 arg0, s32 arg1) {
    u8 *s = Stg00_SoundBanks[arg0][arg1];
    s32 i = 0;
    s32 row = (arg1 != 0);

    for (; s[i] != 0; i++) {
        u8 c = s[i];
        if (c < 0x3A) {
            Stg00_SoundLabelBuf[row][i] = c - 0x30;
        } else if (c == 0x5F) {
            Stg00_SoundLabelBuf[row][i] = 0x24;
        } else {
            Stg00_SoundLabelBuf[row][i] = c + 0xC9;
        }
    }
    Stg00_SoundLabelBuf[row][i] = 0xFF;
    return Stg00_SoundLabelBuf[row];
}

u8 *Stg00_GetBankLabel(s32 arg0) {
    return Stg00_GetSoundLabel(arg0, 0);
}

u8 *Stg00_GetSoundIdLabel(s32 arg0, s32 arg1) {
    return Stg00_GetSoundLabel(arg0, arg1 + 1);
}

s32 Stg00_CountSoundBanks(void) {
    s32 i;

    for (i = 0; Stg00_SoundBanks[i] != NULL; i++) {
    }
    return i;
}

s32 Stg00_CountBankSounds(s32 arg0) {
    u8 **p = Stg00_SoundBanks[arg0];
    s32 i;

    for (i = 0; p[i] != NULL; i++) {
    }
    return i - 1;
}
