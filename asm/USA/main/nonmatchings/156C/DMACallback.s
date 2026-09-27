nonmatching DMACallback, 0x30

glabel DMACallback
    /* 21534 80030D34 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 21538 80030D38 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 2153C 80030D3C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21540 80030D40 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21544 80030D44 0400428C */  lw         $v0, 0x4($v0)
    /* 21548 80030D48 00000000 */  nop
    /* 2154C 80030D4C 09F84000 */  jalr       $v0
    /* 21550 80030D50 00000000 */   nop
    /* 21554 80030D54 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21558 80030D58 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2155C 80030D5C 0800E003 */  jr         $ra
    /* 21560 80030D60 00000000 */   nop
endlabel DMACallback
