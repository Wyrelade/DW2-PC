nonmatching Stg20_MsgWinGetChoice, 0x44

glabel Stg20_MsgWinGetChoice
    /* 5B0C 80068E6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5B10 80068E70 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5B14 80068E74 0D030424 */  addiu      $a0, $zero, 0x30D
    /* 5B18 80068E78 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 5B1C 80068E7C 4445000C */  jal        Task_FindFirst
    /* 5B20 80068E80 2130A000 */   addu      $a2, $a1, $zero
    /* 5B24 80068E84 03004014 */  bnez       $v0, .L80068E94
    /* 5B28 80068E88 00000000 */   nop
    /* 5B2C 80068E8C A8A30108 */  j          .L80068EA0
    /* 5B30 80068E90 21100000 */   addu      $v0, $zero, $zero
  .L80068E94:
    /* 5B34 80068E94 2C00428C */  lw         $v0, 0x2C($v0)
    /* 5B38 80068E98 00000000 */  nop
    /* 5B3C 80068E9C 1C00428C */  lw         $v0, 0x1C($v0)
  .L80068EA0:
    /* 5B40 80068EA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5B44 80068EA4 00000000 */  nop
    /* 5B48 80068EA8 0800E003 */  jr         $ra
    /* 5B4C 80068EAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_MsgWinGetChoice
