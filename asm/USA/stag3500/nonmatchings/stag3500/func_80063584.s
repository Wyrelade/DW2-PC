nonmatching func_80063584, 0x50

glabel func_80063584
    /* 224 80063584 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 228 80063588 21108000 */  addu       $v0, $a0, $zero
    /* 22C 8006358C 06000524 */  addiu      $a1, $zero, 0x6
    /* 230 80063590 21300000 */  addu       $a2, $zero, $zero
    /* 234 80063594 1400BFAF */  sw         $ra, 0x14($sp)
    /* 238 80063598 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23C 8006359C 2800448C */  lw         $a0, 0x28($v0)
    /* 240 800635A0 2C00508C */  lw         $s0, 0x2C($v0)
    /* 244 800635A4 FB88000C */  jal        Math_CycleRange
    /* 248 800635A8 07000724 */   addiu     $a3, $zero, 0x7
    /* 24C 800635AC 21200002 */  addu       $a0, $s0, $zero
    /* 250 800635B0 02000524 */  addiu      $a1, $zero, 0x2
    /* 254 800635B4 4899010C */  jal        func_80066520
    /* 258 800635B8 21304000 */   addu      $a2, $v0, $zero
    /* 25C 800635BC 6C98010C */  jal        func_800661B0
    /* 260 800635C0 21200002 */   addu      $a0, $s0, $zero
    /* 264 800635C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 268 800635C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 26C 800635CC 0800E003 */  jr         $ra
    /* 270 800635D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80063584
