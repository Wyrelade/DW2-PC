nonmatching Stg20_FindWalkerByDigiId, 0x60

glabel Stg20_FindWalkerByDigiId
    /* 7560 8006A8C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7564 8006A8C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7568 8006A8C8 21808000 */  addu       $s0, $a0, $zero
    /* 756C 8006A8CC 02030424 */  addiu      $a0, $zero, 0x302
    /* 7570 8006A8D0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 7574 8006A8D4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7578 8006A8D8 4445000C */  jal        Task_FindFirst
    /* 757C 8006A8DC 2130A000 */   addu      $a2, $a1, $zero
    /* 7580 8006A8E0 21184000 */  addu       $v1, $v0, $zero
    /* 7584 8006A8E4 0A006010 */  beqz       $v1, .L8006A910
    /* 7588 8006A8E8 21100000 */   addu      $v0, $zero, $zero
  .L8006A8EC:
    /* 758C 8006A8EC 0C00628C */  lw         $v0, 0xC($v1)
    /* 7590 8006A8F0 00000000 */  nop
    /* 7594 8006A8F4 06005010 */  beq        $v0, $s0, .L8006A910
    /* 7598 8006A8F8 21106000 */   addu      $v0, $v1, $zero
    /* 759C 8006A8FC 1045000C */  jal        Task_FindNext
    /* 75A0 8006A900 00000000 */   nop
    /* 75A4 8006A904 21184000 */  addu       $v1, $v0, $zero
    /* 75A8 8006A908 F8FF6014 */  bnez       $v1, .L8006A8EC
    /* 75AC 8006A90C 21100000 */   addu      $v0, $zero, $zero
  .L8006A910:
    /* 75B0 8006A910 1400BF8F */  lw         $ra, 0x14($sp)
    /* 75B4 8006A914 1000B08F */  lw         $s0, 0x10($sp)
    /* 75B8 8006A918 0800E003 */  jr         $ra
    /* 75BC 8006A91C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_FindWalkerByDigiId
