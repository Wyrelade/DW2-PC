nonmatching func_8002DC94, 0x3C

glabel func_8002DC94
    /* 1E494 8002DC94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E498 8002DC98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E49C 8002DC9C C1BF000C */  jal        CD_init
    /* 1E4A0 8002DCA0 00000000 */   nop
    /* 1E4A4 8002DCA4 05004014 */  bnez       $v0, .L8002DCBC
    /* 1E4A8 8002DCA8 00000000 */   nop
    /* 1E4AC 8002DCAC 72BF000C */  jal        CD_initvol
    /* 1E4B0 8002DCB0 00000000 */   nop
    /* 1E4B4 8002DCB4 30B70008 */  j          .L8002DCC0
    /* 1E4B8 8002DCB8 0100422C */   sltiu     $v0, $v0, 0x1
  .L8002DCBC:
    /* 1E4BC 8002DCBC 21100000 */  addu       $v0, $zero, $zero
  .L8002DCC0:
    /* 1E4C0 8002DCC0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E4C4 8002DCC4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E4C8 8002DCC8 0800E003 */  jr         $ra
    /* 1E4CC 8002DCCC 00000000 */   nop
endlabel func_8002DC94
