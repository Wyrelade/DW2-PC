nonmatching ResetCallback, 0x30

glabel ResetCallback
    /* 214D4 80030CD4 0580023C */  lui        $v0, %hi(D_8004FB80)
    /* 214D8 80030CD8 80FB428C */  lw         $v0, %lo(D_8004FB80)($v0)
    /* 214DC 80030CDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 214E0 80030CE0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 214E4 80030CE4 0C00428C */  lw         $v0, 0xC($v0)
    /* 214E8 80030CE8 00000000 */  nop
    /* 214EC 80030CEC 09F84000 */  jalr       $v0
    /* 214F0 80030CF0 00000000 */   nop
    /* 214F4 80030CF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 214F8 80030CF8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 214FC 80030CFC 0800E003 */  jr         $ra
    /* 21500 80030D00 00000000 */   nop
endlabel ResetCallback
