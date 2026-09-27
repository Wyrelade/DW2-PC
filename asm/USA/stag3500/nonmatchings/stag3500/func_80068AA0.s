nonmatching func_80068AA0, 0x70

glabel func_80068AA0
    /* 5740 80068AA0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5744 80068AA4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5748 80068AA8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 574C 80068AAC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5750 80068AB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5754 80068AB4 2C00928C */  lw         $s2, 0x2C($a0)
    /* 5758 80068AB8 21800000 */  addu       $s0, $zero, $zero
    /* 575C 80068ABC 21884002 */  addu       $s1, $s2, $zero
  .L80068AC0:
    /* 5760 80068AC0 6C98010C */  jal        func_800661B0
    /* 5764 80068AC4 21202002 */   addu      $a0, $s1, $zero
    /* 5768 80068AC8 01001026 */  addiu      $s0, $s0, 0x1
    /* 576C 80068ACC 0300022A */  slti       $v0, $s0, 0x3
    /* 5770 80068AD0 FBFF4014 */  bnez       $v0, .L80068AC0
    /* 5774 80068AD4 04003126 */   addiu     $s1, $s1, 0x4
    /* 5778 80068AD8 21800000 */  addu       $s0, $zero, $zero
    /* 577C 80068ADC 28001124 */  addiu      $s1, $zero, 0x28
  .L80068AE0:
    /* 5780 80068AE0 4C96010C */  jal        func_80065930
    /* 5784 80068AE4 21205102 */   addu      $a0, $s2, $s1
    /* 5788 80068AE8 01001026 */  addiu      $s0, $s0, 0x1
    /* 578C 80068AEC 0A00022A */  slti       $v0, $s0, 0xA
    /* 5790 80068AF0 FBFF4014 */  bnez       $v0, .L80068AE0
    /* 5794 80068AF4 04003126 */   addiu     $s1, $s1, 0x4
    /* 5798 80068AF8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 579C 80068AFC 1800B28F */  lw         $s2, 0x18($sp)
    /* 57A0 80068B00 1400B18F */  lw         $s1, 0x14($sp)
    /* 57A4 80068B04 1000B08F */  lw         $s0, 0x10($sp)
    /* 57A8 80068B08 0800E003 */  jr         $ra
    /* 57AC 80068B0C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80068AA0
