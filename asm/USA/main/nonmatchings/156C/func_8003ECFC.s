nonmatching func_8003ECFC, 0x118

glabel func_8003ECFC
    /* 2F4FC 8003ECFC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2F500 8003ED00 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2F504 8003ED04 21A08000 */  addu       $s4, $a0, $zero
    /* 2F508 8003ED08 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2F50C 8003ED0C 2198A000 */  addu       $s3, $a1, $zero
    /* 2F510 8003ED10 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2F514 8003ED14 21A8C000 */  addu       $s5, $a2, $zero
    /* 2F518 8003ED18 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2F51C 8003ED1C 2190E000 */  addu       $s2, $a3, $zero
    /* 2F520 8003ED20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F524 8003ED24 0680113C */  lui        $s1, %hi(D_80062F80)
    /* 2F528 8003ED28 802F3126 */  addiu      $s1, $s1, %lo(D_80062F80)
    /* 2F52C 8003ED2C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2F530 8003ED30 2800B6AF */  sw         $s6, 0x28($sp)
    /* 2F534 8003ED34 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2F538 8003ED38 0000228E */  lw         $v0, 0x0($s1)
    /* 2F53C 8003ED3C 4000B68F */  lw         $s6, 0x40($sp)
    /* 2F540 8003ED40 04004018 */  blez       $v0, .L8003ED54
    /* 2F544 8003ED44 00000000 */   nop
    /* 2F548 8003ED48 0180043C */  lui        $a0, %hi(D_80010D18)
    /* 2F54C 8003ED4C 78FB0008 */  j          .L8003EDE0
    /* 2F550 8003ED50 180D8424 */   addiu     $a0, $a0, %lo(D_80010D18)
  .L8003ED54:
    /* 2F554 8003ED54 1400228E */  lw         $v0, 0x14($s1)
    /* 2F558 8003ED58 00000000 */  nop
    /* 2F55C 8003ED5C 04004004 */  bltz       $v0, .L8003ED70
    /* 2F560 8003ED60 7F00C232 */   andi      $v0, $s6, 0x7F
    /* 2F564 8003ED64 0180043C */  lui        $a0, %hi(D_80010C70)
    /* 2F568 8003ED68 78FB0008 */  j          .L8003EDE0
    /* 2F56C 8003ED6C 700C8424 */   addiu     $a0, $a0, %lo(D_80010C70)
  .L8003ED70:
    /* 2F570 8003ED70 04004010 */  beqz       $v0, .L8003ED84
    /* 2F574 8003ED74 7F004232 */   andi      $v0, $s2, 0x7F
    /* 2F578 8003ED78 0180043C */  lui        $a0, %hi(D_80010CBC)
    /* 2F57C 8003ED7C 78FB0008 */  j          .L8003EDE0
    /* 2F580 8003ED80 BC0C8424 */   addiu     $a0, $a0, %lo(D_80010CBC)
  .L8003ED84:
    /* 2F584 8003ED84 14004014 */  bnez       $v0, .L8003EDD8
    /* 2F588 8003ED88 21208002 */   addu      $a0, $s4, $zero
    /* 2F58C 8003ED8C 24003026 */  addiu      $s0, $s1, 0x24
    /* 2F590 8003ED90 46FD000C */  jal        Card_MakeDevName
    /* 2F594 8003ED94 21280002 */   addu      $a1, $s0, $zero
    /* 2F598 8003ED98 21200002 */  addu       $a0, $s0, $zero
    /* 2F59C 8003ED9C 1DFE000C */  jal        strcat
    /* 2F5A0 8003EDA0 21286002 */   addu      $a1, $s3, $zero
    /* 2F5A4 8003EDA4 0480043C */  lui        $a0, %hi(func_8003EE14)
    /* 2F5A8 8003EDA8 14EE8424 */  addiu      $a0, $a0, %lo(func_8003EE14)
    /* 2F5AC 8003EDAC 04000224 */  addiu      $v0, $zero, 0x4
    /* 2F5B0 8003EDB0 000022AE */  sw         $v0, 0x0($s1)
    /* 2F5B4 8003EDB4 040020AE */  sw         $zero, 0x4($s1)
    /* 2F5B8 8003EDB8 080020AE */  sw         $zero, 0x8($s1)
    /* 2F5BC 8003EDBC 180032AE */  sw         $s2, 0x18($s1)
    /* 2F5C0 8003EDC0 200035AE */  sw         $s5, 0x20($s1)
    /* 2F5C4 8003EDC4 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 2F5C8 8003EDC8 89FE000C */  jal        Card_PushTask
    /* 2F5CC 8003EDCC 100034AE */   sw        $s4, 0x10($s1)
    /* 2F5D0 8003EDD0 7BFB0008 */  j          .L8003EDEC
    /* 2F5D4 8003EDD4 01000224 */   addiu     $v0, $zero, 0x1
  .L8003EDD8:
    /* 2F5D8 8003EDD8 0180043C */  lui        $a0, %hi(D_80010CE8)
    /* 2F5DC 8003EDDC E80C8424 */  addiu      $a0, $a0, %lo(D_80010CE8)
  .L8003EDE0:
    /* 2F5E0 8003EDE0 05A8000C */  jal        printf
    /* 2F5E4 8003EDE4 00000000 */   nop
    /* 2F5E8 8003EDE8 21100000 */  addu       $v0, $zero, $zero
  .L8003EDEC:
    /* 2F5EC 8003EDEC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2F5F0 8003EDF0 2800B68F */  lw         $s6, 0x28($sp)
    /* 2F5F4 8003EDF4 2400B58F */  lw         $s5, 0x24($sp)
    /* 2F5F8 8003EDF8 2000B48F */  lw         $s4, 0x20($sp)
    /* 2F5FC 8003EDFC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2F600 8003EE00 1800B28F */  lw         $s2, 0x18($sp)
    /* 2F604 8003EE04 1400B18F */  lw         $s1, 0x14($sp)
    /* 2F608 8003EE08 1000B08F */  lw         $s0, 0x10($sp)
    /* 2F60C 8003EE0C 0800E003 */  jr         $ra
    /* 2F610 8003EE10 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003ECFC
