nonmatching func_80068D34, 0x50

glabel func_80068D34
    /* 59D4 80068D34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 59D8 80068D38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 59DC 80068D3C 21808000 */  addu       $s0, $a0, $zero
    /* 59E0 80068D40 0D030424 */  addiu      $a0, $zero, 0x30D
    /* 59E4 80068D44 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 59E8 80068D48 1400BFAF */  sw         $ra, 0x14($sp)
    /* 59EC 80068D4C 4445000C */  jal        Task_FindFirst
    /* 59F0 80068D50 2130A000 */   addu      $a2, $a1, $zero
    /* 59F4 80068D54 07004010 */  beqz       $v0, .L80068D74
    /* 59F8 80068D58 21200002 */   addu      $a0, $s0, $zero
    /* 59FC 80068D5C 2C00508C */  lw         $s0, 0x2C($v0)
    /* 5A00 80068D60 757B000C */  jal        func_8001EDD4
    /* 5A04 80068D64 00000000 */   nop
    /* 5A08 80068D68 040002AE */  sw         $v0, 0x4($s0)
    /* 5A0C 80068D6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 5A10 80068D70 180002AE */  sw         $v0, 0x18($s0)
  .L80068D74:
    /* 5A14 80068D74 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5A18 80068D78 1000B08F */  lw         $s0, 0x10($sp)
    /* 5A1C 80068D7C 0800E003 */  jr         $ra
    /* 5A20 80068D80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068D34
