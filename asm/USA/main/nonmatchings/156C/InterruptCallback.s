nonmatching InterruptCallback, 0x30

glabel InterruptCallback
    /* 21504 80030D04 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 21508 80030D08 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 2150C 80030D0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21510 80030D10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21514 80030D14 0800428C */  lw         $v0, 0x8($v0)
    /* 21518 80030D18 00000000 */  nop
    /* 2151C 80030D1C 09F84000 */  jalr       $v0
    /* 21520 80030D20 00000000 */   nop
    /* 21524 80030D24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21528 80030D28 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2152C 80030D2C 0800E003 */  jr         $ra
    /* 21530 80030D30 00000000 */   nop
endlabel InterruptCallback
