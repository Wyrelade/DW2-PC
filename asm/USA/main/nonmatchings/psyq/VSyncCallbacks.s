nonmatching VSyncCallbacks, 0x30

glabel VSyncCallbacks
    /* 21598 80030D98 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 2159C 80030D9C 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 215A0 80030DA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 215A4 80030DA4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 215A8 80030DA8 1400428C */  lw         $v0, 0x14($v0)
    /* 215AC 80030DAC 00000000 */  nop
    /* 215B0 80030DB0 09F84000 */  jalr       $v0
    /* 215B4 80030DB4 00000000 */   nop
    /* 215B8 80030DB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 215BC 80030DBC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 215C0 80030DC0 0800E003 */  jr         $ra
    /* 215C4 80030DC4 00000000 */   nop
endlabel VSyncCallbacks
