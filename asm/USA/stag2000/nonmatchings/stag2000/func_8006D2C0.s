nonmatching func_8006D2C0, 0x90

glabel func_8006D2C0
    /* 9F60 8006D2C0 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 9F64 8006D2C4 4000B0AF */  sw         $s0, 0x40($sp)
    /* 9F68 8006D2C8 21808000 */  addu       $s0, $a0, $zero
    /* 9F6C 8006D2CC 4400B1AF */  sw         $s1, 0x44($sp)
    /* 9F70 8006D2D0 2188E000 */  addu       $s1, $a3, $zero
    /* 9F74 8006D2D4 E803A228 */  slti       $v0, $a1, 0x3E8
    /* 9F78 8006D2D8 4800BFAF */  sw         $ra, 0x48($sp)
    /* 9F7C 8006D2DC 06004010 */  beqz       $v0, .L8006D2F8
    /* 9F80 8006D2E0 5800A6AF */   sw        $a2, 0x58($sp)
    /* 9F84 8006D2E4 FD01043C */  lui        $a0, (0x1FD0000 >> 16)
    /* 9F88 8006D2E8 688E000C */  jal        Cd_GetFileEntry
    /* 9F8C 8006D2EC 2120A400 */   addu      $a0, $a1, $a0
    /* 9F90 8006D2F0 C1B40108 */  j          .L8006D304
    /* 9F94 8006D2F4 2400A2AF */   sw        $v0, 0x24($sp)
  .L8006D2F8:
    /* 9F98 8006D2F8 2178000C */  jal        Item_GetDescText
    /* 9F9C 8006D2FC 18FCA424 */   addiu     $a0, $a1, -0x3E8
    /* 9FA0 8006D300 2400A2AF */  sw         $v0, 0x24($sp)
  .L8006D304:
    /* 9FA4 8006D304 01000224 */  addiu      $v0, $zero, 0x1
    /* 9FA8 8006D308 1000A2AF */  sw         $v0, 0x10($sp)
    /* 9FAC 8006D30C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 9FB0 8006D310 5800A297 */  lhu        $v0, 0x58($sp)
    /* 9FB4 8006D314 21200002 */  addu       $a0, $s0, $zero
    /* 9FB8 8006D318 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 9FBC 8006D31C 5A00A297 */  lhu        $v0, 0x5A($sp)
    /* 9FC0 8006D320 1000A527 */  addiu      $a1, $sp, 0x10
    /* 9FC4 8006D324 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 9FC8 8006D328 2000A0AF */  sw         $zero, 0x20($sp)
    /* 9FCC 8006D32C 2800A0AF */  sw         $zero, 0x28($sp)
    /* 9FD0 8006D330 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 9FD4 8006D334 096F000C */  jal        Text_Open
    /* 9FD8 8006D338 1A00A2A7 */   sh        $v0, 0x1A($sp)
    /* 9FDC 8006D33C 4800BF8F */  lw         $ra, 0x48($sp)
    /* 9FE0 8006D340 4400B18F */  lw         $s1, 0x44($sp)
    /* 9FE4 8006D344 4000B08F */  lw         $s0, 0x40($sp)
    /* 9FE8 8006D348 0800E003 */  jr         $ra
    /* 9FEC 8006D34C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8006D2C0
