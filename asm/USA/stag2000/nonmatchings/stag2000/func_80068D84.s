nonmatching func_80068D84, 0x54

glabel func_80068D84
    /* 5A24 80068D84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5A28 80068D88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5A2C 80068D8C 21808000 */  addu       $s0, $a0, $zero
    /* 5A30 80068D90 0D030424 */  addiu      $a0, $zero, 0x30D
    /* 5A34 80068D94 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 5A38 80068D98 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5A3C 80068D9C 4445000C */  jal        Task_FindFirst
    /* 5A40 80068DA0 2130A000 */   addu      $a2, $a1, $zero
    /* 5A44 80068DA4 08004010 */  beqz       $v0, .L80068DC8
    /* 5A48 80068DA8 FD01043C */   lui       $a0, (0x1FD0000 >> 16)
    /* 5A4C 80068DAC 21200402 */  addu       $a0, $s0, $a0
    /* 5A50 80068DB0 2C00508C */  lw         $s0, 0x2C($v0)
    /* 5A54 80068DB4 688E000C */  jal        Cd_GetFileEntry
    /* 5A58 80068DB8 00000000 */   nop
    /* 5A5C 80068DBC 040002AE */  sw         $v0, 0x4($s0)
    /* 5A60 80068DC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 5A64 80068DC4 180002AE */  sw         $v0, 0x18($s0)
  .L80068DC8:
    /* 5A68 80068DC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5A6C 80068DCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5A70 80068DD0 0800E003 */  jr         $ra
    /* 5A74 80068DD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068D84
