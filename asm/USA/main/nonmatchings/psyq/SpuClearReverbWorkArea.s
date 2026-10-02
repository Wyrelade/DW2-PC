nonmatching SpuClearReverbWorkArea, 0x194

glabel SpuClearReverbWorkArea
    /* 2CBA4 8003C3A4 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2CBA8 8003C3A8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2CBAC 8003C3AC 21808000 */  addu       $s0, $a0, $zero
    /* 2CBB0 8003C3B0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 2CBB4 8003C3B4 0A00022E */  sltiu      $v0, $s0, 0xA
    /* 2CBB8 8003C3B8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 2CBBC 8003C3BC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 2CBC0 8003C3C0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 2CBC4 8003C3C4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2CBC8 8003C3C8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2CBCC 8003C3CC 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2CBD0 8003C3D0 0A004010 */  beqz       $v0, .L8003C3FC
    /* 2CBD4 8003C3D4 21A80000 */   addu      $s5, $zero, $zero
    /* 2CBD8 8003C3D8 0580033C */  lui        $v1, %hi(D_800503B8)
    /* 2CBDC 8003C3DC B8036324 */  addiu      $v1, $v1, %lo(D_800503B8)
    /* 2CBE0 8003C3E0 80101000 */  sll        $v0, $s0, 2
    /* 2CBE4 8003C3E4 21884300 */  addu       $s1, $v0, $v1
    /* 2CBE8 8003C3E8 0000248E */  lw         $a0, 0x0($s1)
    /* 2CBEC 8003C3EC 41EE000C */  jal        _SpuIsInAllocateArea_
    /* 2CBF0 8003C3F0 00000000 */   nop
    /* 2CBF4 8003C3F4 03004010 */  beqz       $v0, .L8003C404
    /* 2CBF8 8003C3F8 00000000 */   nop
  .L8003C3FC:
    /* 2CBFC 8003C3FC 45F10008 */  j          .L8003C514
    /* 2CC00 8003C400 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8003C404:
    /* 2CC04 8003C404 08000016 */  bnez       $s0, .L8003C428
    /* 2CC08 8003C408 0100023C */   lui       $v0, (0x10000 >> 16)
    /* 2CC0C 8003C40C 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2CC10 8003C410 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2CC14 8003C414 10000324 */  addiu      $v1, $zero, 0x10
    /* 2CC18 8003C418 04884300 */  sllv       $s1, $v1, $v0
    /* 2CC1C 8003C41C F0FF0334 */  ori        $v1, $zero, 0xFFF0
    /* 2CC20 8003C420 10F10008 */  j          .L8003C440
    /* 2CC24 8003C424 04904300 */   sllv      $s2, $v1, $v0
  .L8003C428:
    /* 2CC28 8003C428 0000248E */  lw         $a0, 0x0($s1)
    /* 2CC2C 8003C42C 0580033C */  lui        $v1, %hi(D_8004FE50)
    /* 2CC30 8003C430 50FE638C */  lw         $v1, %lo(D_8004FE50)($v1)
    /* 2CC34 8003C434 23104400 */  subu       $v0, $v0, $a0
    /* 2CC38 8003C438 04886200 */  sllv       $s1, $v0, $v1
    /* 2CC3C 8003C43C 04906400 */  sllv       $s2, $a0, $v1
  .L8003C440:
    /* 2CC40 8003C440 0580143C */  lui        $s4, %hi(D_8004FE44)
    /* 2CC44 8003C444 44FE948E */  lw         $s4, %lo(D_8004FE44)($s4)
    /* 2CC48 8003C448 01000224 */  addiu      $v0, $zero, 0x1
    /* 2CC4C 8003C44C 04008216 */  bne        $s4, $v0, .L8003C460
    /* 2CC50 8003C450 00000000 */   nop
    /* 2CC54 8003C454 0580013C */  lui        $at, %hi(D_8004FE44)
    /* 2CC58 8003C458 44FE20AC */  sw         $zero, %lo(D_8004FE44)($at)
    /* 2CC5C 8003C45C 01001524 */  addiu      $s5, $zero, 0x1
  .L8003C460:
    /* 2CC60 8003C460 0580023C */  lui        $v0, %hi(D_8004FE60)
    /* 2CC64 8003C464 60FE428C */  lw         $v0, %lo(D_8004FE60)($v0)
    /* 2CC68 8003C468 00000000 */  nop
    /* 2CC6C 8003C46C 07004010 */  beqz       $v0, .L8003C48C
    /* 2CC70 8003C470 01001324 */   addiu     $s3, $zero, 0x1
    /* 2CC74 8003C474 0580023C */  lui        $v0, %hi(D_8004FE60)
    /* 2CC78 8003C478 60FE428C */  lw         $v0, %lo(D_8004FE60)($v0)
    /* 2CC7C 8003C47C 00000000 */  nop
    /* 2CC80 8003C480 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2CC84 8003C484 0580013C */  lui        $at, %hi(D_8004FE60)
    /* 2CC88 8003C488 60FE20AC */  sw         $zero, %lo(D_8004FE60)($at)
  .L8003C48C:
    /* 2CC8C 8003C48C 0104222E */  sltiu      $v0, $s1, 0x401
  .L8003C490:
    /* 2CC90 8003C490 03004010 */  beqz       $v0, .L8003C4A0
    /* 2CC94 8003C494 00041024 */   addiu     $s0, $zero, 0x400
    /* 2CC98 8003C498 21802002 */  addu       $s0, $s1, $zero
    /* 2CC9C 8003C49C 21980000 */  addu       $s3, $zero, $zero
  .L8003C4A0:
    /* 2CCA0 8003C4A0 02000424 */  addiu      $a0, $zero, 0x2
    /* 2CCA4 8003C4A4 DEE9000C */  jal        _spu_t
    /* 2CCA8 8003C4A8 21284002 */   addu      $a1, $s2, $zero
    /* 2CCAC 8003C4AC DEE9000C */  jal        _spu_t
    /* 2CCB0 8003C4B0 01000424 */   addiu     $a0, $zero, 0x1
    /* 2CCB4 8003C4B4 03000424 */  addiu      $a0, $zero, 0x3
    /* 2CCB8 8003C4B8 0580053C */  lui        $a1, %hi(D_8004FE98)
    /* 2CCBC 8003C4BC 98FEA524 */  addiu      $a1, $a1, %lo(D_8004FE98)
    /* 2CCC0 8003C4C0 DEE9000C */  jal        _spu_t
    /* 2CCC4 8003C4C4 21300002 */   addu      $a2, $s0, $zero
    /* 2CCC8 8003C4C8 0580043C */  lui        $a0, %hi(_spu_EVdma)
    /* 2CCCC 8003C4CC B0FD848C */  lw         $a0, %lo(_spu_EVdma)($a0)
    /* 2CCD0 8003C4D0 00FC3126 */  addiu      $s1, $s1, -0x400
    /* 2CCD4 8003C4D4 51F1000C */  jal        WaitEvent
    /* 2CCD8 8003C4D8 00045226 */   addiu     $s2, $s2, 0x400
    /* 2CCDC 8003C4DC ECFF6016 */  bnez       $s3, .L8003C490
    /* 2CCE0 8003C4E0 0104222E */   sltiu     $v0, $s1, 0x401
    /* 2CCE4 8003C4E4 0300A012 */  beqz       $s5, .L8003C4F4
    /* 2CCE8 8003C4E8 00000000 */   nop
    /* 2CCEC 8003C4EC 0580013C */  lui        $at, %hi(D_8004FE44)
    /* 2CCF0 8003C4F0 44FE34AC */  sw         $s4, %lo(D_8004FE44)($at)
  .L8003C4F4:
    /* 2CCF4 8003C4F4 1000A28F */  lw         $v0, 0x10($sp)
    /* 2CCF8 8003C4F8 00000000 */  nop
    /* 2CCFC 8003C4FC 05004010 */  beqz       $v0, .L8003C514
    /* 2CD00 8003C500 21100000 */   addu      $v0, $zero, $zero
    /* 2CD04 8003C504 1000A28F */  lw         $v0, 0x10($sp)
    /* 2CD08 8003C508 0580013C */  lui        $at, %hi(D_8004FE60)
    /* 2CD0C 8003C50C 60FE22AC */  sw         $v0, %lo(D_8004FE60)($at)
    /* 2CD10 8003C510 21100000 */  addu       $v0, $zero, $zero
  .L8003C514:
    /* 2CD14 8003C514 3000BF8F */  lw         $ra, 0x30($sp)
    /* 2CD18 8003C518 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 2CD1C 8003C51C 2800B48F */  lw         $s4, 0x28($sp)
    /* 2CD20 8003C520 2400B38F */  lw         $s3, 0x24($sp)
    /* 2CD24 8003C524 2000B28F */  lw         $s2, 0x20($sp)
    /* 2CD28 8003C528 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2CD2C 8003C52C 1800B08F */  lw         $s0, 0x18($sp)
    /* 2CD30 8003C530 0800E003 */  jr         $ra
    /* 2CD34 8003C534 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel SpuClearReverbWorkArea
    /* 2CD38 8003C538 00000000 */  nop
    /* 2CD3C 8003C53C 00000000 */  nop
    /* 2CD40 8003C540 00000000 */  nop
