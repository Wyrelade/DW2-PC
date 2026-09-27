nonmatching MemCardCreateFile, 0xFC

glabel MemCardCreateFile
    /* 2FAA8 8003F2A8 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 2FAAC 8003F2AC 3000B0AF */  sw         $s0, 0x30($sp)
    /* 2FAB0 8003F2B0 21808000 */  addu       $s0, $a0, $zero
    /* 2FAB4 8003F2B4 3400B1AF */  sw         $s1, 0x34($sp)
    /* 2FAB8 8003F2B8 2188A000 */  addu       $s1, $a1, $zero
    /* 2FABC 8003F2BC 3800B2AF */  sw         $s2, 0x38($sp)
    /* 2FAC0 8003F2C0 0680123C */  lui        $s2, %hi(D_80062F80)
    /* 2FAC4 8003F2C4 802F5226 */  addiu      $s2, $s2, %lo(D_80062F80)
    /* 2FAC8 8003F2C8 4000BFAF */  sw         $ra, 0x40($sp)
    /* 2FACC 8003F2CC 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 2FAD0 8003F2D0 0000428E */  lw         $v0, 0x0($s2)
    /* 2FAD4 8003F2D4 00000000 */  nop
    /* 2FAD8 8003F2D8 0C004010 */  beqz       $v0, .L8003F30C
    /* 2FADC 8003F2DC 2198C000 */   addu      $s3, $a2, $zero
    /* 2FAE0 8003F2E0 0180043C */  lui        $a0, %hi(D_80010D18)
    /* 2FAE4 8003F2E4 05A8000C */  jal        printf
    /* 2FAE8 8003F2E8 180D8424 */   addiu     $a0, $a0, %lo(D_80010D18)
    /* 2FAEC 8003F2EC E2FC0008 */  j          .L8003F388
    /* 2FAF0 8003F2F0 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8003F2F4:
    /* 2FAF4 8003F2F4 E2FC0008 */  j          .L8003F388
    /* 2FAF8 8003F2F8 07000224 */   addiu     $v0, $zero, 0x7
  .L8003F2FC:
    /* 2FAFC 8003F2FC E2FC0008 */  j          .L8003F388
    /* 2FB00 8003F300 04000224 */   addiu     $v0, $zero, 0x4
  .L8003F304:
    /* 2FB04 8003F304 E2FC0008 */  j          .L8003F388
    /* 2FB08 8003F308 06000224 */   addiu     $v0, $zero, 0x6
  .L8003F30C:
    /* 2FB0C 8003F30C 21200002 */  addu       $a0, $s0, $zero
    /* 2FB10 8003F310 46FD000C */  jal        Card_MakeDevName
    /* 2FB14 8003F314 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2FB18 8003F318 1000A427 */  addiu      $a0, $sp, 0x10
    /* 2FB1C 8003F31C 1DFE000C */  jal        strcat
    /* 2FB20 8003F320 21282002 */   addu      $a1, $s1, $zero
    /* 2FB24 8003F324 01000224 */  addiu      $v0, $zero, 0x1
    /* 2FB28 8003F328 0C00438E */  lw         $v1, 0xC($s2)
    /* 2FB2C 8003F32C 04100202 */  sllv       $v0, $v0, $s0
    /* 2FB30 8003F330 25186200 */  or         $v1, $v1, $v0
    /* 2FB34 8003F334 0C0043AE */  sw         $v1, 0xC($s2)
    /* 2FB38 8003F338 21200002 */  addu       $a0, $s0, $zero
    /* 2FB3C 8003F33C 21282002 */  addu       $a1, $s1, $zero
    /* 2FB40 8003F340 6D01010C */  jal        Card_CreateFile
    /* 2FB44 8003F344 21306002 */   addu      $a2, $s3, $zero
    /* 2FB48 8003F348 21204000 */  addu       $a0, $v0, $zero
    /* 2FB4C 8003F34C 0D008010 */  beqz       $a0, .L8003F384
    /* 2FB50 8003F350 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 2FB54 8003F354 E7FF8210 */  beq        $a0, $v0, .L8003F2F4
    /* 2FB58 8003F358 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 2FB5C 8003F35C E7FF8210 */  beq        $a0, $v0, .L8003F2FC
    /* 2FB60 8003F360 FDFF0224 */   addiu     $v0, $zero, -0x3
    /* 2FB64 8003F364 E7FF8210 */  beq        $a0, $v0, .L8003F304
    /* 2FB68 8003F368 04000224 */   addiu     $v0, $zero, 0x4
    /* 2FB6C 8003F36C 06008210 */  beq        $a0, $v0, .L8003F388
    /* 2FB70 8003F370 02000224 */   addiu     $v0, $zero, 0x2
    /* 2FB74 8003F374 06FD000C */  jal        func_8003F418
    /* 2FB78 8003F378 00000000 */   nop
    /* 2FB7C 8003F37C E2FC0008 */  j          .L8003F388
    /* 2FB80 8003F380 00000000 */   nop
  .L8003F384:
    /* 2FB84 8003F384 21100000 */  addu       $v0, $zero, $zero
  .L8003F388:
    /* 2FB88 8003F388 4000BF8F */  lw         $ra, 0x40($sp)
    /* 2FB8C 8003F38C 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 2FB90 8003F390 3800B28F */  lw         $s2, 0x38($sp)
    /* 2FB94 8003F394 3400B18F */  lw         $s1, 0x34($sp)
    /* 2FB98 8003F398 3000B08F */  lw         $s0, 0x30($sp)
    /* 2FB9C 8003F39C 0800E003 */  jr         $ra
    /* 2FBA0 8003F3A0 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel MemCardCreateFile
