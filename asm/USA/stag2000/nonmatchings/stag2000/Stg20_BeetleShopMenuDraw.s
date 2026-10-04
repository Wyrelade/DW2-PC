nonmatching Stg20_BeetleShopMenuDraw, 0xD8

glabel Stg20_BeetleShopMenuDraw
    /* 8D14 8006C074 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 8D18 8006C078 2400B5AF */  sw         $s5, 0x24($sp)
    /* 8D1C 8006C07C 21A88000 */  addu       $s5, $a0, $zero
    /* 8D20 8006C080 930C043C */  lui        $a0, (0xC930008 >> 16)
    /* 8D24 8006C084 08008434 */  ori        $a0, $a0, (0xC930008 & 0xFFFF)
    /* 8D28 8006C088 2800BFAF */  sw         $ra, 0x28($sp)
    /* 8D2C 8006C08C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 8D30 8006C090 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8D34 8006C094 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8D38 8006C098 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8D3C 8006C09C 688E000C */  jal        Cd_GetFileEntry
    /* 8D40 8006C0A0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 8D44 8006C0A4 21904000 */  addu       $s2, $v0, $zero
    /* 8D48 8006C0A8 0000428E */  lw         $v0, 0x0($s2)
    /* 8D4C 8006C0AC 00000000 */  nop
    /* 8D50 8006C0B0 1B004010 */  beqz       $v0, .L8006C120
    /* 8D54 8006C0B4 21884002 */   addu      $s1, $s2, $zero
    /* 8D58 8006C0B8 0780023C */  lui        $v0, %hi(D_800709B0)
    /* 8D5C 8006C0BC B0095424 */  addiu      $s4, $v0, %lo(D_800709B0)
    /* 8D60 8006C0C0 9EFF1324 */  addiu      $s3, $zero, -0x62
    /* 8D64 8006C0C4 06005026 */  addiu      $s0, $s2, 0x6
  .L8006C0C8:
    /* 8D68 8006C0C8 1600028E */  lw         $v0, 0x16($s0)
    /* 8D6C 8006C0CC 00000000 */  nop
    /* 8D70 8006C0D0 02004230 */  andi       $v0, $v0, 0x2
    /* 8D74 8006C0D4 0D004010 */  beqz       $v0, .L8006C10C
    /* 8D78 8006C0D8 04000524 */   addiu     $a1, $zero, 0x4
    /* 8D7C 8006C0DC 21300000 */  addu       $a2, $zero, $zero
    /* 8D80 8006C0E0 2800A48E */  lw         $a0, 0x28($s5)
    /* 8D84 8006C0E4 FB88000C */  jal        Math_CycleRange
    /* 8D88 8006C0E8 03000724 */   addiu     $a3, $zero, 0x3
    /* 8D8C 8006C0EC 060002A2 */  sb         $v0, 0x6($s0)
    /* 8D90 8006C0F0 5000828E */  lw         $v0, 0x50($s4)
    /* 8D94 8006C0F4 00000000 */  nop
    /* 8D98 8006C0F8 02004010 */  beqz       $v0, .L8006C104
    /* 8D9C 8006C0FC 70FF0324 */   addiu     $v1, $zero, -0x90
    /* 8DA0 8006C100 A9FF0324 */  addiu      $v1, $zero, -0x57
  .L8006C104:
    /* 8DA4 8006C104 FEFF03A6 */  sh         $v1, -0x2($s0)
    /* 8DA8 8006C108 000013A6 */  sh         $s3, 0x0($s0)
  .L8006C10C:
    /* 8DAC 8006C10C 28003126 */  addiu      $s1, $s1, 0x28
    /* 8DB0 8006C110 0000228E */  lw         $v0, 0x0($s1)
    /* 8DB4 8006C114 00000000 */  nop
    /* 8DB8 8006C118 EBFF4014 */  bnez       $v0, .L8006C0C8
    /* 8DBC 8006C11C 28001026 */   addiu     $s0, $s0, 0x28
  .L8006C120:
    /* 8DC0 8006C120 2176000C */  jal        Gfx_DrawParts
    /* 8DC4 8006C124 21204002 */   addu      $a0, $s2, $zero
    /* 8DC8 8006C128 2800BF8F */  lw         $ra, 0x28($sp)
    /* 8DCC 8006C12C 2400B58F */  lw         $s5, 0x24($sp)
    /* 8DD0 8006C130 2000B48F */  lw         $s4, 0x20($sp)
    /* 8DD4 8006C134 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8DD8 8006C138 1800B28F */  lw         $s2, 0x18($sp)
    /* 8DDC 8006C13C 1400B18F */  lw         $s1, 0x14($sp)
    /* 8DE0 8006C140 1000B08F */  lw         $s0, 0x10($sp)
    /* 8DE4 8006C144 0800E003 */  jr         $ra
    /* 8DE8 8006C148 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg20_BeetleShopMenuDraw
