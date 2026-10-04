nonmatching Stg40_PickRandomPart, 0xE4

glabel Stg40_PickRandomPart
    /* E2A8 80071608 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* E2AC 8007160C 2800B2AF */  sw         $s2, 0x28($sp)
    /* E2B0 80071610 21900000 */  addu       $s2, $zero, $zero
    /* E2B4 80071614 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* E2B8 80071618 FFFF1324 */  addiu      $s3, $zero, -0x1
    /* E2BC 8007161C 2400B1AF */  sw         $s1, 0x24($sp)
    /* E2C0 80071620 21884002 */  addu       $s1, $s2, $zero
    /* E2C4 80071624 0780023C */  lui        $v0, %hi(Stg40_RandomPartSlots)
    /* E2C8 80071628 3400B5AF */  sw         $s5, 0x34($sp)
    /* E2CC 8007162C 4C2A5524 */  addiu      $s5, $v0, %lo(Stg40_RandomPartSlots)
    /* E2D0 80071630 3000B4AF */  sw         $s4, 0x30($sp)
    /* E2D4 80071634 1000B427 */  addiu      $s4, $sp, 0x10
    /* E2D8 80071638 3800BFAF */  sw         $ra, 0x38($sp)
    /* E2DC 8007163C 2000B0AF */  sw         $s0, 0x20($sp)
    /* E2E0 80071640 21803502 */  addu       $s0, $s1, $s5
  .L80071644:
    /* E2E4 80071644 00000492 */  lbu        $a0, 0x0($s0)
    /* E2E8 80071648 4689000C */  jal        Beetle_GetPart
    /* E2EC 8007164C 00000000 */   nop
    /* E2F0 80071650 04004018 */  blez       $v0, .L80071664
    /* E2F4 80071654 21189202 */   addu      $v1, $s4, $s2
    /* E2F8 80071658 00000292 */  lbu        $v0, 0x0($s0)
    /* E2FC 8007165C 01005226 */  addiu      $s2, $s2, 0x1
    /* E300 80071660 000062A0 */  sb         $v0, 0x0($v1)
  .L80071664:
    /* E304 80071664 01003126 */  addiu      $s1, $s1, 0x1
    /* E308 80071668 0C00222E */  sltiu      $v0, $s1, 0xC
    /* E30C 8007166C F5FF4014 */  bnez       $v0, .L80071644
    /* E310 80071670 21803502 */   addu      $s0, $s1, $s5
    /* E314 80071674 14004012 */  beqz       $s2, .L800716C8
    /* E318 80071678 21106002 */   addu      $v0, $s3, $zero
    /* E31C 8007167C 60C4010C */  jal        Stg40_RandPercent
    /* E320 80071680 00000000 */   nop
    /* E324 80071684 64000324 */  addiu      $v1, $zero, 0x64
    /* E328 80071688 1A007200 */  div        $zero, $v1, $s2
    /* E32C 8007168C 12180000 */  mflo       $v1
    /* E330 80071690 00000000 */  nop
    /* E334 80071694 00000000 */  nop
    /* E338 80071698 1A004300 */  div        $zero, $v0, $v1
    /* E33C 8007169C 12980000 */  mflo       $s3
    /* E340 800716A0 FFFF4426 */  addiu      $a0, $s2, -0x1
    /* E344 800716A4 21186002 */  addu       $v1, $s3, $zero
    /* E348 800716A8 2A109300 */  slt        $v0, $a0, $s3
    /* E34C 800716AC 03004010 */  beqz       $v0, .L800716BC
    /* E350 800716B0 2110A303 */   addu      $v0, $sp, $v1
    /* E354 800716B4 21188000 */  addu       $v1, $a0, $zero
    /* E358 800716B8 2110A303 */  addu       $v0, $sp, $v1
  .L800716BC:
    /* E35C 800716BC 10005390 */  lbu        $s3, 0x10($v0)
    /* E360 800716C0 00000000 */  nop
    /* E364 800716C4 21106002 */  addu       $v0, $s3, $zero
  .L800716C8:
    /* E368 800716C8 3800BF8F */  lw         $ra, 0x38($sp)
    /* E36C 800716CC 3400B58F */  lw         $s5, 0x34($sp)
    /* E370 800716D0 3000B48F */  lw         $s4, 0x30($sp)
    /* E374 800716D4 2C00B38F */  lw         $s3, 0x2C($sp)
    /* E378 800716D8 2800B28F */  lw         $s2, 0x28($sp)
    /* E37C 800716DC 2400B18F */  lw         $s1, 0x24($sp)
    /* E380 800716E0 2000B08F */  lw         $s0, 0x20($sp)
    /* E384 800716E4 0800E003 */  jr         $ra
    /* E388 800716E8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel Stg40_PickRandomPart
