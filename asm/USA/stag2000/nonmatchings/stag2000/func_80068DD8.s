nonmatching func_80068DD8, 0x94

glabel func_80068DD8
    /* 5A78 80068DD8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5A7C 80068DDC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5A80 80068DE0 21888000 */  addu       $s1, $a0, $zero
    /* 5A84 80068DE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5A88 80068DE8 2180A000 */  addu       $s0, $a1, $zero
    /* 5A8C 80068DEC 0D030424 */  addiu      $a0, $zero, 0x30D
    /* 5A90 80068DF0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 5A94 80068DF4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 5A98 80068DF8 4445000C */  jal        Task_FindFirst
    /* 5A9C 80068DFC 2130A000 */   addu      $a2, $a1, $zero
    /* 5AA0 80068E00 15004010 */  beqz       $v0, .L80068E58
    /* 5AA4 80068E04 00000000 */   nop
    /* 5AA8 80068E08 21200002 */  addu       $a0, $s0, $zero
    /* 5AAC 80068E0C 2C00508C */  lw         $s0, 0x2C($v0)
    /* 5AB0 80068E10 D679000C */  jal        Digi_GetDefaultName
    /* 5AB4 80068E14 00000000 */   nop
    /* 5AB8 80068E18 21284000 */  addu       $a1, $v0, $zero
    /* 5ABC 80068E1C 21200000 */  addu       $a0, $zero, $zero
    /* 5AC0 80068E20 21180402 */  addu       $v1, $s0, $a0
  .L80068E24:
    /* 5AC4 80068E24 2110A400 */  addu       $v0, $a1, $a0
    /* 5AC8 80068E28 00004290 */  lbu        $v0, 0x0($v0)
    /* 5ACC 80068E2C 01008424 */  addiu      $a0, $a0, 0x1
    /* 5AD0 80068E30 080062A0 */  sb         $v0, 0x8($v1)
    /* 5AD4 80068E34 0E008228 */  slti       $v0, $a0, 0xE
    /* 5AD8 80068E38 FAFF4014 */  bnez       $v0, .L80068E24
    /* 5ADC 80068E3C 21180402 */   addu      $v1, $s0, $a0
    /* 5AE0 80068E40 FD01043C */  lui        $a0, (0x1FD0000 >> 16)
    /* 5AE4 80068E44 688E000C */  jal        Cd_GetFileEntry
    /* 5AE8 80068E48 21202402 */   addu      $a0, $s1, $a0
    /* 5AEC 80068E4C 040002AE */  sw         $v0, 0x4($s0)
    /* 5AF0 80068E50 01000224 */  addiu      $v0, $zero, 0x1
    /* 5AF4 80068E54 180002AE */  sw         $v0, 0x18($s0)
  .L80068E58:
    /* 5AF8 80068E58 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5AFC 80068E5C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5B00 80068E60 1000B08F */  lw         $s0, 0x10($sp)
    /* 5B04 80068E64 0800E003 */  jr         $ra
    /* 5B08 80068E68 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80068DD8
