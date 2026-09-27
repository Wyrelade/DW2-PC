nonmatching VSyncCallback, 0x34

glabel VSyncCallback
    /* 21564 80030D64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21568 80030D68 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 2156C 80030D6C 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 21570 80030D70 21288000 */  addu       $a1, $a0, $zero
    /* 21574 80030D74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21578 80030D78 1400428C */  lw         $v0, 0x14($v0)
    /* 2157C 80030D7C 00000000 */  nop
    /* 21580 80030D80 09F84000 */  jalr       $v0
    /* 21584 80030D84 04000424 */   addiu     $a0, $zero, 0x4
    /* 21588 80030D88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2158C 80030D8C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 21590 80030D90 0800E003 */  jr         $ra
    /* 21594 80030D94 00000000 */   nop
endlabel VSyncCallback
