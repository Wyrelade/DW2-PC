nonmatching Stg20_ShopBgDraw, 0xBC

glabel Stg20_ShopBgDraw
    /* 8760 8006BAC0 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* 8764 8006BAC4 88F7428C */  lw         $v0, %lo(Sys_GameMode)($v0)
    /* 8768 8006BAC8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 876C 8006BACC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 8770 8006BAD0 21A08000 */  addu       $s4, $a0, $zero
    /* 8774 8006BAD4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 8778 8006BAD8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 877C 8006BADC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8780 8006BAE0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8784 8006BAE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8788 8006BAE8 33034228 */  slti       $v0, $v0, 0x333
    /* 878C 8006BAEC 02004010 */  beqz       $v0, .L8006BAF8
    /* 8790 8006BAF0 930C043C */   lui       $a0, (0xC930001 >> 16)
    /* 8794 8006BAF4 D60D043C */  lui        $a0, (0xDD60001 >> 16)
  .L8006BAF8:
    /* 8798 8006BAF8 688E000C */  jal        Cd_GetFileEntry
    /* 879C 8006BAFC 01008434 */   ori       $a0, $a0, (0xDD60001 & 0xFFFF)
    /* 87A0 8006BB00 21904000 */  addu       $s2, $v0, $zero
    /* 87A4 8006BB04 0000428E */  lw         $v0, 0x0($s2)
    /* 87A8 8006BB08 00000000 */  nop
    /* 87AC 8006BB0C 11004010 */  beqz       $v0, .L8006BB54
    /* 87B0 8006BB10 21884002 */   addu      $s1, $s2, $zero
    /* 87B4 8006BB14 02001324 */  addiu      $s3, $zero, 0x2
    /* 87B8 8006BB18 0C005026 */  addiu      $s0, $s2, 0xC
  .L8006BB1C:
    /* 87BC 8006BB1C 1000028E */  lw         $v0, 0x10($s0)
    /* 87C0 8006BB20 00000000 */  nop
    /* 87C4 8006BB24 06005314 */  bne        $v0, $s3, .L8006BB40
    /* 87C8 8006BB28 06000524 */   addiu     $a1, $zero, 0x6
    /* 87CC 8006BB2C 21300000 */  addu       $a2, $zero, $zero
    /* 87D0 8006BB30 2800848E */  lw         $a0, 0x28($s4)
    /* 87D4 8006BB34 FB88000C */  jal        Math_CycleRange
    /* 87D8 8006BB38 07000724 */   addiu     $a3, $zero, 0x7
    /* 87DC 8006BB3C 000002A2 */  sb         $v0, 0x0($s0)
  .L8006BB40:
    /* 87E0 8006BB40 28003126 */  addiu      $s1, $s1, 0x28
    /* 87E4 8006BB44 0000228E */  lw         $v0, 0x0($s1)
    /* 87E8 8006BB48 00000000 */  nop
    /* 87EC 8006BB4C F3FF4014 */  bnez       $v0, .L8006BB1C
    /* 87F0 8006BB50 28001026 */   addiu     $s0, $s0, 0x28
  .L8006BB54:
    /* 87F4 8006BB54 2176000C */  jal        Gfx_DrawParts
    /* 87F8 8006BB58 21204002 */   addu      $a0, $s2, $zero
    /* 87FC 8006BB5C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 8800 8006BB60 2000B48F */  lw         $s4, 0x20($sp)
    /* 8804 8006BB64 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8808 8006BB68 1800B28F */  lw         $s2, 0x18($sp)
    /* 880C 8006BB6C 1400B18F */  lw         $s1, 0x14($sp)
    /* 8810 8006BB70 1000B08F */  lw         $s0, 0x10($sp)
    /* 8814 8006BB74 0800E003 */  jr         $ra
    /* 8818 8006BB78 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg20_ShopBgDraw
