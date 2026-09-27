nonmatching func_80068CF8, 0x3C

glabel func_80068CF8
    /* 5998 80068CF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 599C 80068CFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 59A0 80068D00 0D030424 */  addiu      $a0, $zero, 0x30D
    /* 59A4 80068D04 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 59A8 80068D08 4445000C */  jal        Task_FindFirst
    /* 59AC 80068D0C 2130A000 */   addu      $a2, $a1, $zero
    /* 59B0 80068D10 04004010 */  beqz       $v0, .L80068D24
    /* 59B4 80068D14 00000000 */   nop
    /* 59B8 80068D18 2C00448C */  lw         $a0, 0x2C($v0)
    /* 59BC 80068D1C E26E000C */  jal        Text_Close
    /* 59C0 80068D20 00000000 */   nop
  .L80068D24:
    /* 59C4 80068D24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 59C8 80068D28 00000000 */  nop
    /* 59CC 80068D2C 0800E003 */  jr         $ra
    /* 59D0 80068D30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068CF8
