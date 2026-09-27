nonmatching Pad_ResetButtons, 0x20

glabel Pad_ResetButtons
    /* 138DC 800230DC 0C0080AC */  sw         $zero, 0xC($a0)
    /* 138E0 800230E0 150080A0 */  sb         $zero, 0x15($a0)
    /* 138E4 800230E4 140080A0 */  sb         $zero, 0x14($a0)
    /* 138E8 800230E8 100080AC */  sw         $zero, 0x10($a0)
    /* 138EC 800230EC 080080AC */  sw         $zero, 0x8($a0)
    /* 138F0 800230F0 040080AC */  sw         $zero, 0x4($a0)
    /* 138F4 800230F4 0800E003 */  jr         $ra
    /* 138F8 800230F8 080080AC */   sw        $zero, 0x8($a0)
endlabel Pad_ResetButtons
