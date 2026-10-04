nonmatching Stg20_PartsUpgradeDraw, 0xD4

glabel Stg20_PartsUpgradeDraw
    /* BF2C 8006F28C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* BF30 8006F290 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* BF34 8006F294 21988000 */  addu       $s3, $a0, $zero
    /* BF38 8006F298 2800BFAF */  sw         $ra, 0x28($sp)
    /* BF3C 8006F29C 2400B5AF */  sw         $s5, 0x24($sp)
    /* BF40 8006F2A0 2000B4AF */  sw         $s4, 0x20($sp)
    /* BF44 8006F2A4 1800B2AF */  sw         $s2, 0x18($sp)
    /* BF48 8006F2A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* BF4C 8006F2AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* BF50 8006F2B0 2C00748E */  lw         $s4, 0x2C($s3)
    /* BF54 8006F2B4 688E000C */  jal        Cd_GetFileEntry
    /* BF58 8006F2B8 930C043C */   lui       $a0, (0xC930000 >> 16)
    /* BF5C 8006F2BC 21904000 */  addu       $s2, $v0, $zero
    /* BF60 8006F2C0 0000428E */  lw         $v0, 0x0($s2)
    /* BF64 8006F2C4 00000000 */  nop
    /* BF68 8006F2C8 1A004010 */  beqz       $v0, .L8006F334
    /* BF6C 8006F2CC 21884002 */   addu      $s1, $s2, $zero
    /* BF70 8006F2D0 AAFF1524 */  addiu      $s5, $zero, -0x56
    /* BF74 8006F2D4 06005026 */  addiu      $s0, $s2, 0x6
  .L8006F2D8:
    /* BF78 8006F2D8 1600028E */  lw         $v0, 0x16($s0)
    /* BF7C 8006F2DC 00000000 */  nop
    /* BF80 8006F2E0 02004230 */  andi       $v0, $v0, 0x2
    /* BF84 8006F2E4 0E004010 */  beqz       $v0, .L8006F320
    /* BF88 8006F2E8 04000524 */   addiu     $a1, $zero, 0x4
    /* BF8C 8006F2EC 21300000 */  addu       $a2, $zero, $zero
    /* BF90 8006F2F0 2800648E */  lw         $a0, 0x28($s3)
    /* BF94 8006F2F4 FB88000C */  jal        Math_CycleRange
    /* BF98 8006F2F8 03000724 */   addiu     $a3, $zero, 0x3
    /* BF9C 8006F2FC 060002A2 */  sb         $v0, 0x6($s0)
    /* BFA0 8006F300 FEFF15A6 */  sh         $s5, -0x2($s0)
    /* BFA4 8006F304 3000838E */  lw         $v1, 0x30($s4)
    /* BFA8 8006F308 00000000 */  nop
    /* BFAC 8006F30C 40100300 */  sll        $v0, $v1, 1
    /* BFB0 8006F310 21104300 */  addu       $v0, $v0, $v1
    /* BFB4 8006F314 80100200 */  sll        $v0, $v0, 2
    /* BFB8 8006F318 CCFF4224 */  addiu      $v0, $v0, -0x34
    /* BFBC 8006F31C 000002A6 */  sh         $v0, 0x0($s0)
  .L8006F320:
    /* BFC0 8006F320 28003126 */  addiu      $s1, $s1, 0x28
    /* BFC4 8006F324 0000228E */  lw         $v0, 0x0($s1)
    /* BFC8 8006F328 00000000 */  nop
    /* BFCC 8006F32C EAFF4014 */  bnez       $v0, .L8006F2D8
    /* BFD0 8006F330 28001026 */   addiu     $s0, $s0, 0x28
  .L8006F334:
    /* BFD4 8006F334 2176000C */  jal        Gfx_DrawParts
    /* BFD8 8006F338 21204002 */   addu      $a0, $s2, $zero
    /* BFDC 8006F33C 2800BF8F */  lw         $ra, 0x28($sp)
    /* BFE0 8006F340 2400B58F */  lw         $s5, 0x24($sp)
    /* BFE4 8006F344 2000B48F */  lw         $s4, 0x20($sp)
    /* BFE8 8006F348 1C00B38F */  lw         $s3, 0x1C($sp)
    /* BFEC 8006F34C 1800B28F */  lw         $s2, 0x18($sp)
    /* BFF0 8006F350 1400B18F */  lw         $s1, 0x14($sp)
    /* BFF4 8006F354 1000B08F */  lw         $s0, 0x10($sp)
    /* BFF8 8006F358 0800E003 */  jr         $ra
    /* BFFC 8006F35C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg20_PartsUpgradeDraw
