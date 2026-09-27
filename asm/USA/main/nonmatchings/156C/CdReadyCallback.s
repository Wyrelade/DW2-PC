nonmatching CdReadyCallback, 0x14

glabel CdReadyCallback
    /* 20D34 80030534 0580023C */  lui        $v0, %hi(D_8004E6CC)
    /* 20D38 80030538 CCE6428C */  lw         $v0, %lo(D_8004E6CC)($v0)
    /* 20D3C 8003053C 0580013C */  lui        $at, %hi(D_8004E6CC)
    /* 20D40 80030540 0800E003 */  jr         $ra
    /* 20D44 80030544 CCE624AC */   sw        $a0, %lo(D_8004E6CC)($at)
endlabel CdReadyCallback
    /* 20D48 80030548 00000000 */  nop
    /* 20D4C 8003054C 00000000 */  nop
    /* 20D50 80030550 00000000 */  nop
