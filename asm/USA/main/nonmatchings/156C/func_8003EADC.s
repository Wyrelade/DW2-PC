nonmatching func_8003EADC, 0x118

glabel func_8003EADC
    /* 2F2DC 8003EADC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2F2E0 8003EAE0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2F2E4 8003EAE4 21A08000 */  addu       $s4, $a0, $zero
    /* 2F2E8 8003EAE8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2F2EC 8003EAEC 2198A000 */  addu       $s3, $a1, $zero
    /* 2F2F0 8003EAF0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2F2F4 8003EAF4 21A8C000 */  addu       $s5, $a2, $zero
    /* 2F2F8 8003EAF8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2F2FC 8003EAFC 2190E000 */  addu       $s2, $a3, $zero
    /* 2F300 8003EB00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F304 8003EB04 0680113C */  lui        $s1, %hi(D_80062F80)
    /* 2F308 8003EB08 802F3126 */  addiu      $s1, $s1, %lo(D_80062F80)
    /* 2F30C 8003EB0C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2F310 8003EB10 2800B6AF */  sw         $s6, 0x28($sp)
    /* 2F314 8003EB14 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2F318 8003EB18 0000228E */  lw         $v0, 0x0($s1)
    /* 2F31C 8003EB1C 4000B68F */  lw         $s6, 0x40($sp)
    /* 2F320 8003EB20 04004018 */  blez       $v0, .L8003EB34
    /* 2F324 8003EB24 00000000 */   nop
    /* 2F328 8003EB28 0180043C */  lui        $a0, %hi(D_80010D18)
    /* 2F32C 8003EB2C F0FA0008 */  j          .L8003EBC0
    /* 2F330 8003EB30 180D8424 */   addiu     $a0, $a0, %lo(D_80010D18)
  .L8003EB34:
    /* 2F334 8003EB34 1400228E */  lw         $v0, 0x14($s1)
    /* 2F338 8003EB38 00000000 */  nop
    /* 2F33C 8003EB3C 04004004 */  bltz       $v0, .L8003EB50
    /* 2F340 8003EB40 7F00C232 */   andi      $v0, $s6, 0x7F
    /* 2F344 8003EB44 0180043C */  lui        $a0, %hi(D_80010C70)
    /* 2F348 8003EB48 F0FA0008 */  j          .L8003EBC0
    /* 2F34C 8003EB4C 700C8424 */   addiu     $a0, $a0, %lo(D_80010C70)
  .L8003EB50:
    /* 2F350 8003EB50 04004010 */  beqz       $v0, .L8003EB64
    /* 2F354 8003EB54 7F004232 */   andi      $v0, $s2, 0x7F
    /* 2F358 8003EB58 0180043C */  lui        $a0, %hi(D_80010CBC)
    /* 2F35C 8003EB5C F0FA0008 */  j          .L8003EBC0
    /* 2F360 8003EB60 BC0C8424 */   addiu     $a0, $a0, %lo(D_80010CBC)
  .L8003EB64:
    /* 2F364 8003EB64 14004014 */  bnez       $v0, .L8003EBB8
    /* 2F368 8003EB68 21208002 */   addu      $a0, $s4, $zero
    /* 2F36C 8003EB6C 24003026 */  addiu      $s0, $s1, 0x24
    /* 2F370 8003EB70 46FD000C */  jal        Card_MakeDevName
    /* 2F374 8003EB74 21280002 */   addu      $a1, $s0, $zero
    /* 2F378 8003EB78 21200002 */  addu       $a0, $s0, $zero
    /* 2F37C 8003EB7C 1DFE000C */  jal        strcat
    /* 2F380 8003EB80 21286002 */   addu      $a1, $s3, $zero
    /* 2F384 8003EB84 0480043C */  lui        $a0, %hi(func_8003EBF4)
    /* 2F388 8003EB88 F4EB8424 */  addiu      $a0, $a0, %lo(func_8003EBF4)
    /* 2F38C 8003EB8C 03000224 */  addiu      $v0, $zero, 0x3
    /* 2F390 8003EB90 000022AE */  sw         $v0, 0x0($s1)
    /* 2F394 8003EB94 040020AE */  sw         $zero, 0x4($s1)
    /* 2F398 8003EB98 080020AE */  sw         $zero, 0x8($s1)
    /* 2F39C 8003EB9C 180032AE */  sw         $s2, 0x18($s1)
    /* 2F3A0 8003EBA0 200035AE */  sw         $s5, 0x20($s1)
    /* 2F3A4 8003EBA4 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 2F3A8 8003EBA8 89FE000C */  jal        Card_PushTask
    /* 2F3AC 8003EBAC 100034AE */   sw        $s4, 0x10($s1)
    /* 2F3B0 8003EBB0 F3FA0008 */  j          .L8003EBCC
    /* 2F3B4 8003EBB4 01000224 */   addiu     $v0, $zero, 0x1
  .L8003EBB8:
    /* 2F3B8 8003EBB8 0180043C */  lui        $a0, %hi(D_80010CE8)
    /* 2F3BC 8003EBBC E80C8424 */  addiu      $a0, $a0, %lo(D_80010CE8)
  .L8003EBC0:
    /* 2F3C0 8003EBC0 05A8000C */  jal        printf
    /* 2F3C4 8003EBC4 00000000 */   nop
    /* 2F3C8 8003EBC8 21100000 */  addu       $v0, $zero, $zero
  .L8003EBCC:
    /* 2F3CC 8003EBCC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2F3D0 8003EBD0 2800B68F */  lw         $s6, 0x28($sp)
    /* 2F3D4 8003EBD4 2400B58F */  lw         $s5, 0x24($sp)
    /* 2F3D8 8003EBD8 2000B48F */  lw         $s4, 0x20($sp)
    /* 2F3DC 8003EBDC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2F3E0 8003EBE0 1800B28F */  lw         $s2, 0x18($sp)
    /* 2F3E4 8003EBE4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2F3E8 8003EBE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2F3EC 8003EBEC 0800E003 */  jr         $ra
    /* 2F3F0 8003EBF0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003EADC
