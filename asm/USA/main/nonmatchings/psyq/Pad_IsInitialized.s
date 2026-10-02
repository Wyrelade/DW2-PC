nonmatching Pad_IsInitialized, 0x10

glabel Pad_IsInitialized
    /* 2DE10 8003D610 0580023C */  lui        $v0, %hi(D_800506B8)
    /* 2DE14 8003D614 B806428C */  lw         $v0, %lo(D_800506B8)($v0)
    /* 2DE18 8003D618 0800E003 */  jr         $ra
    /* 2DE1C 8003D61C 00000000 */   nop
endlabel Pad_IsInitialized
