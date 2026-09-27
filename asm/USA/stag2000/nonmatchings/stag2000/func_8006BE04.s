nonmatching func_8006BE04, 0xD8

glabel func_8006BE04
    /* 8AA4 8006BE04 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 8AA8 8006BE08 2400B5AF */  sw         $s5, 0x24($sp)
    /* 8AAC 8006BE0C 21A88000 */  addu       $s5, $a0, $zero
    /* 8AB0 8006BE10 D60D043C */  lui        $a0, (0xDD60004 >> 16)
    /* 8AB4 8006BE14 04008434 */  ori        $a0, $a0, (0xDD60004 & 0xFFFF)
    /* 8AB8 8006BE18 2800BFAF */  sw         $ra, 0x28($sp)
    /* 8ABC 8006BE1C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 8AC0 8006BE20 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8AC4 8006BE24 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8AC8 8006BE28 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8ACC 8006BE2C 688E000C */  jal        Cd_GetFileEntry
    /* 8AD0 8006BE30 1000B0AF */   sw        $s0, 0x10($sp)
    /* 8AD4 8006BE34 21904000 */  addu       $s2, $v0, $zero
    /* 8AD8 8006BE38 0000428E */  lw         $v0, 0x0($s2)
    /* 8ADC 8006BE3C 00000000 */  nop
    /* 8AE0 8006BE40 1B004010 */  beqz       $v0, .L8006BEB0
    /* 8AE4 8006BE44 21884002 */   addu      $s1, $s2, $zero
    /* 8AE8 8006BE48 0780023C */  lui        $v0, %hi(D_800709B0)
    /* 8AEC 8006BE4C B0095424 */  addiu      $s4, $v0, %lo(D_800709B0)
    /* 8AF0 8006BE50 9EFF1324 */  addiu      $s3, $zero, -0x62
    /* 8AF4 8006BE54 06005026 */  addiu      $s0, $s2, 0x6
  .L8006BE58:
    /* 8AF8 8006BE58 1600028E */  lw         $v0, 0x16($s0)
    /* 8AFC 8006BE5C 00000000 */  nop
    /* 8B00 8006BE60 02004230 */  andi       $v0, $v0, 0x2
    /* 8B04 8006BE64 0D004010 */  beqz       $v0, .L8006BE9C
    /* 8B08 8006BE68 04000524 */   addiu     $a1, $zero, 0x4
    /* 8B0C 8006BE6C 21300000 */  addu       $a2, $zero, $zero
    /* 8B10 8006BE70 2800A48E */  lw         $a0, 0x28($s5)
    /* 8B14 8006BE74 FB88000C */  jal        Math_CycleRange
    /* 8B18 8006BE78 03000724 */   addiu     $a3, $zero, 0x3
    /* 8B1C 8006BE7C 060002A2 */  sb         $v0, 0x6($s0)
    /* 8B20 8006BE80 5000828E */  lw         $v0, 0x50($s4)
    /* 8B24 8006BE84 00000000 */  nop
    /* 8B28 8006BE88 02004010 */  beqz       $v0, .L8006BE94
    /* 8B2C 8006BE8C 70FF0324 */   addiu     $v1, $zero, -0x90
    /* 8B30 8006BE90 94FF0324 */  addiu      $v1, $zero, -0x6C
  .L8006BE94:
    /* 8B34 8006BE94 FEFF03A6 */  sh         $v1, -0x2($s0)
    /* 8B38 8006BE98 000013A6 */  sh         $s3, 0x0($s0)
  .L8006BE9C:
    /* 8B3C 8006BE9C 28003126 */  addiu      $s1, $s1, 0x28
    /* 8B40 8006BEA0 0000228E */  lw         $v0, 0x0($s1)
    /* 8B44 8006BEA4 00000000 */  nop
    /* 8B48 8006BEA8 EBFF4014 */  bnez       $v0, .L8006BE58
    /* 8B4C 8006BEAC 28001026 */   addiu     $s0, $s0, 0x28
  .L8006BEB0:
    /* 8B50 8006BEB0 2176000C */  jal        Gfx_DrawParts
    /* 8B54 8006BEB4 21204002 */   addu      $a0, $s2, $zero
    /* 8B58 8006BEB8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 8B5C 8006BEBC 2400B58F */  lw         $s5, 0x24($sp)
    /* 8B60 8006BEC0 2000B48F */  lw         $s4, 0x20($sp)
    /* 8B64 8006BEC4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8B68 8006BEC8 1800B28F */  lw         $s2, 0x18($sp)
    /* 8B6C 8006BECC 1400B18F */  lw         $s1, 0x14($sp)
    /* 8B70 8006BED0 1000B08F */  lw         $s0, 0x10($sp)
    /* 8B74 8006BED4 0800E003 */  jr         $ra
    /* 8B78 8006BED8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006BE04
