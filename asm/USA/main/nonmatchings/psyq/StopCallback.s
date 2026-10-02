nonmatching StopCallback, 0x30

glabel StopCallback
    /* 215C8 80030DC8 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 215CC 80030DCC 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 215D0 80030DD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 215D4 80030DD4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 215D8 80030DD8 1000428C */  lw         $v0, 0x10($v0)
    /* 215DC 80030DDC 00000000 */  nop
    /* 215E0 80030DE0 09F84000 */  jalr       $v0
    /* 215E4 80030DE4 00000000 */   nop
    /* 215E8 80030DE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 215EC 80030DEC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 215F0 80030DF0 0800E003 */  jr         $ra
    /* 215F4 80030DF4 00000000 */   nop
endlabel StopCallback
