nonmatching Stg35_HudGetGaugeLevel, 0x44

glabel Stg35_HudGetGaugeLevel
    /* 58FC 80068C5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5900 80068C60 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5904 80068C64 08070424 */  addiu      $a0, $zero, 0x708
    /* 5908 80068C68 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 590C 80068C6C 4445000C */  jal        Task_FindFirst
    /* 5910 80068C70 2130A000 */   addu      $a2, $a1, $zero
    /* 5914 80068C74 03004014 */  bnez       $v0, .L80068C84
    /* 5918 80068C78 00000000 */   nop
    /* 591C 80068C7C 24A30108 */  j          .L80068C90
    /* 5920 80068C80 01000224 */   addiu     $v0, $zero, 0x1
  .L80068C84:
    /* 5924 80068C84 2C00428C */  lw         $v0, 0x2C($v0)
    /* 5928 80068C88 00000000 */  nop
    /* 592C 80068C8C 7400428C */  lw         $v0, 0x74($v0)
  .L80068C90:
    /* 5930 80068C90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5934 80068C94 00000000 */  nop
    /* 5938 80068C98 0800E003 */  jr         $ra
    /* 593C 80068C9C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_HudGetGaugeLevel
