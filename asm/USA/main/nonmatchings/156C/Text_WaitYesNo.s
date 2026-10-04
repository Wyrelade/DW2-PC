nonmatching Text_WaitYesNo, 0x40

glabel Text_WaitYesNo
    /* 3EA4 800136A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3EA8 800136A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3EAC 800136AC 826F000C */  jal        Text_IsFinished
    /* 3EB0 800136B0 00000000 */   nop
    /* 3EB4 800136B4 21184000 */  addu       $v1, $v0, $zero
    /* 3EB8 800136B8 06006010 */  beqz       $v1, .L800136D4
    /* 3EBC 800136BC 00000000 */   nop
    /* 3EC0 800136C0 9E87000C */  jal        Flag_Test
    /* 3EC4 800136C4 11000424 */   addiu     $a0, $zero, 0x11
    /* 3EC8 800136C8 02004014 */  bnez       $v0, .L800136D4
    /* 3ECC 800136CC FFFF0324 */   addiu     $v1, $zero, -0x1
    /* 3ED0 800136D0 01000324 */  addiu      $v1, $zero, 0x1
  .L800136D4:
    /* 3ED4 800136D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3ED8 800136D8 21106000 */  addu       $v0, $v1, $zero
    /* 3EDC 800136DC 0800E003 */  jr         $ra
    /* 3EE0 800136E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Text_WaitYesNo
