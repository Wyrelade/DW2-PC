nonmatching CdSyncCallback, 0x14

glabel CdSyncCallback
    /* 20D14 80030514 0580023C */  lui        $v0, %hi(D_8004E6C8)
    /* 20D18 80030518 C8E6428C */  lw         $v0, %lo(D_8004E6C8)($v0)
    /* 20D1C 8003051C 0580013C */  lui        $at, %hi(D_8004E6C8)
    /* 20D20 80030520 0800E003 */  jr         $ra
    /* 20D24 80030524 C8E624AC */   sw        $a0, %lo(D_8004E6C8)($at)
endlabel CdSyncCallback
    /* 20D28 80030528 00000000 */  nop
    /* 20D2C 8003052C 00000000 */  nop
    /* 20D30 80030530 00000000 */  nop
