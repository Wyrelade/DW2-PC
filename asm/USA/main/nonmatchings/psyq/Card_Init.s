nonmatching Card_Init, 0x90

glabel Card_Init
    /* 2DD04 8003D504 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2DD08 8003D508 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DD0C 8003D50C 21808000 */  addu       $s0, $a0, $zero
    /* 2DD10 8003D510 21200000 */  addu       $a0, $zero, $zero
    /* 2DD14 8003D514 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2DD18 8003D518 31C3000C */  jal        ChangeClearPAD
    /* 2DD1C 8003D51C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 2DD20 8003D520 ADC2000C */  jal        VSync
    /* 2DD24 8003D524 21200000 */   addu      $a0, $zero, $zero
    /* 2DD28 8003D528 F19B000C */  jal        EnterCriticalSection
    /* 2DD2C 8003D52C 00000000 */   nop
    /* 2DD30 8003D530 84F5000C */  jal        Pad_IsInitialized
    /* 2DD34 8003D534 21884000 */   addu      $s1, $v0, $zero
    /* 2DD38 8003D538 02004014 */  bnez       $v0, .L8003D544
    /* 2DD3C 8003D53C 00000000 */   nop
    /* 2DD40 8003D540 21800000 */  addu       $s0, $zero, $zero
  .L8003D544:
    /* 2DD44 8003D544 75F6000C */  jal        InitCARD
    /* 2DD48 8003D548 21200002 */   addu      $a0, $s0, $zero
    /* 2DD4C 8003D54C F9F6000C */  jal        func_8003DBE4
    /* 2DD50 8003D550 00000000 */   nop
    /* 2DD54 8003D554 B8F6000C */  jal        func_8003DAE0
    /* 2DD58 8003D558 00000000 */   nop
    /* 2DD5C 8003D55C DDF6000C */  jal        func_8003DB74
    /* 2DD60 8003D560 00000000 */   nop
    /* 2DD64 8003D564 81F6000C */  jal        func_8003DA04
    /* 2DD68 8003D568 00000000 */   nop
    /* 2DD6C 8003D56C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2DD70 8003D570 03002216 */  bne        $s1, $v0, .L8003D580
    /* 2DD74 8003D574 00000000 */   nop
    /* 2DD78 8003D578 F59B000C */  jal        ExitCriticalSection
    /* 2DD7C 8003D57C 00000000 */   nop
  .L8003D580:
    /* 2DD80 8003D580 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2DD84 8003D584 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DD88 8003D588 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DD8C 8003D58C 0800E003 */  jr         $ra
    /* 2DD90 8003D590 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Card_Init
