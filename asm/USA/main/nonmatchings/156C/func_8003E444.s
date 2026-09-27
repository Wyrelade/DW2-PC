nonmatching func_8003E444, 0x188

glabel func_8003E444
    /* 2EC44 8003E444 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2EC48 8003E448 2400B3AF */  sw         $s3, 0x24($sp)
    /* 2EC4C 8003E44C 21988000 */  addu       $s3, $a0, $zero
    /* 2EC50 8003E450 2800B4AF */  sw         $s4, 0x28($sp)
    /* 2EC54 8003E454 21A0A000 */  addu       $s4, $a1, $zero
    /* 2EC58 8003E458 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 2EC5C 8003E45C 21A8C000 */  addu       $s5, $a2, $zero
    /* 2EC60 8003E460 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2EC64 8003E464 0680113C */  lui        $s1, %hi(D_80062F94)
    /* 2EC68 8003E468 942F3126 */  addiu      $s1, $s1, %lo(D_80062F94)
    /* 2EC6C 8003E46C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 2EC70 8003E470 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2EC74 8003E474 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2EC78 8003E478 0000228E */  lw         $v0, 0x0($s1)
    /* 2EC7C 8003E47C 00000000 */  nop
    /* 2EC80 8003E480 06004004 */  bltz       $v0, .L8003E49C
    /* 2EC84 8003E484 21900000 */   addu      $s2, $zero, $zero
    /* 2EC88 8003E488 0180043C */  lui        $a0, %hi(D_80010C70)
    /* 2EC8C 8003E48C 05A8000C */  jal        printf
    /* 2EC90 8003E490 700C8424 */   addiu     $a0, $a0, %lo(D_80010C70)
    /* 2EC94 8003E494 6AF90008 */  j          .L8003E5A8
    /* 2EC98 8003E498 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8003E49C:
    /* 2EC9C 8003E49C 21206002 */  addu       $a0, $s3, $zero
    /* 2ECA0 8003E4A0 10003026 */  addiu      $s0, $s1, 0x10
    /* 2ECA4 8003E4A4 46FD000C */  jal        Card_MakeDevName
    /* 2ECA8 8003E4A8 21280002 */   addu      $a1, $s0, $zero
    /* 2ECAC 8003E4AC 21200002 */  addu       $a0, $s0, $zero
    /* 2ECB0 8003E4B0 1DFE000C */  jal        strcat
    /* 2ECB4 8003E4B4 21288002 */   addu      $a1, $s4, $zero
    /* 2ECB8 8003E4B8 FCFF33AE */  sw         $s3, -0x4($s1)
    /* 2ECBC 8003E4BC ECFF3426 */  addiu      $s4, $s1, -0x14
    /* 2ECC0 8003E4C0 02001124 */  addiu      $s1, $zero, 0x2
  .L8003E4C4:
    /* 2ECC4 8003E4C4 21200002 */  addu       $a0, $s0, $zero
  .L8003E4C8:
    /* 2ECC8 8003E4C8 5DFD000C */  jal        open
    /* 2ECCC 8003E4CC 01000524 */   addiu     $a1, $zero, 0x1
    /* 2ECD0 8003E4D0 2C004104 */  bgez       $v0, .L8003E584
    /* 2ECD4 8003E4D4 00000000 */   nop
    /* 2ECD8 8003E4D8 5EFC000C */  jal        MemCardCallback
    /* 2ECDC 8003E4DC 21200000 */   addu      $a0, $zero, $zero
    /* 2ECE0 8003E4E0 DCFF038E */  lw         $v1, -0x24($s0)
    /* 2ECE4 8003E4E4 0680013C */  lui        $at, %hi(D_80062FD8)
    /* 2ECE8 8003E4E8 06006018 */  blez       $v1, .L8003E504
    /* 2ECEC 8003E4EC D82F22AC */   sw        $v0, %lo(D_80062FD8)($at)
    /* 2ECF0 8003E4F0 0180043C */  lui        $a0, %hi(D_80010B74)
    /* 2ECF4 8003E4F4 05A8000C */  jal        printf
    /* 2ECF8 8003E4F8 740B8424 */   addiu     $a0, $a0, %lo(D_80010B74)
    /* 2ECFC 8003E4FC 4AF90008 */  j          .L8003E528
    /* 2ED00 8003E500 21200000 */   addu      $a0, $zero, $zero
  .L8003E504:
    /* 2ED04 8003E504 0480043C */  lui        $a0, %hi(func_8003E19C)
    /* 2ED08 8003E508 9CE18424 */  addiu      $a0, $a0, %lo(func_8003E19C)
    /* 2ED0C 8003E50C DCFF11AE */  sw         $s1, -0x24($s0)
    /* 2ED10 8003E510 040080AE */  sw         $zero, 0x4($s4)
    /* 2ED14 8003E514 080080AE */  sw         $zero, 0x8($s4)
    /* 2ED18 8003E518 0680013C */  lui        $at, %hi(D_80062F90)
    /* 2ED1C 8003E51C 89FE000C */  jal        Card_PushTask
    /* 2ED20 8003E520 902F33AC */   sw        $s3, %lo(D_80062F90)($at)
    /* 2ED24 8003E524 21200000 */  addu       $a0, $zero, $zero
  .L8003E528:
    /* 2ED28 8003E528 21280000 */  addu       $a1, $zero, $zero
    /* 2ED2C 8003E52C 63FC000C */  jal        MemCardSync
    /* 2ED30 8003E530 1000A627 */   addiu     $a2, $sp, 0x10
    /* 2ED34 8003E534 0680043C */  lui        $a0, %hi(D_80062FD8)
    /* 2ED38 8003E538 D82F848C */  lw         $a0, %lo(D_80062FD8)($a0)
    /* 2ED3C 8003E53C 5EFC000C */  jal        MemCardCallback
    /* 2ED40 8003E540 00000000 */   nop
    /* 2ED44 8003E544 1000A38F */  lw         $v1, 0x10($sp)
    /* 2ED48 8003E548 03000224 */  addiu      $v0, $zero, 0x3
    /* 2ED4C 8003E54C DEFF6210 */  beq        $v1, $v0, .L8003E4C8
    /* 2ED50 8003E550 21200002 */   addu      $a0, $s0, $zero
    /* 2ED54 8003E554 05007114 */  bne        $v1, $s1, .L8003E56C
    /* 2ED58 8003E558 00000000 */   nop
    /* 2ED5C 8003E55C 01005226 */  addiu      $s2, $s2, 0x1
    /* 2ED60 8003E560 0500422A */  slti       $v0, $s2, 0x5
    /* 2ED64 8003E564 D7FF4014 */  bnez       $v0, .L8003E4C4
    /* 2ED68 8003E568 00000000 */   nop
  .L8003E56C:
    /* 2ED6C 8003E56C 02006014 */  bnez       $v1, .L8003E578
    /* 2ED70 8003E570 05000224 */   addiu     $v0, $zero, 0x5
    /* 2ED74 8003E574 1000A2AF */  sw         $v0, 0x10($sp)
  .L8003E578:
    /* 2ED78 8003E578 1000A28F */  lw         $v0, 0x10($sp)
    /* 2ED7C 8003E57C 6AF90008 */  j          .L8003E5A8
    /* 2ED80 8003E580 00000000 */   nop
  .L8003E584:
    /* 2ED84 8003E584 69FD000C */  jal        close
    /* 2ED88 8003E588 21204000 */   addu      $a0, $v0, $zero
    /* 2ED8C 8003E58C A9FF000C */  jal        func_8003FEA4
    /* 2ED90 8003E590 00000000 */   nop
    /* 2ED94 8003E594 21200002 */  addu       $a0, $s0, $zero
    /* 2ED98 8003E598 5DFD000C */  jal        open
    /* 2ED9C 8003E59C 0080A536 */   ori       $a1, $s5, 0x8000
    /* 2EDA0 8003E5A0 F0FF02AE */  sw         $v0, -0x10($s0)
    /* 2EDA4 8003E5A4 21100000 */  addu       $v0, $zero, $zero
  .L8003E5A8:
    /* 2EDA8 8003E5A8 3000BF8F */  lw         $ra, 0x30($sp)
    /* 2EDAC 8003E5AC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 2EDB0 8003E5B0 2800B48F */  lw         $s4, 0x28($sp)
    /* 2EDB4 8003E5B4 2400B38F */  lw         $s3, 0x24($sp)
    /* 2EDB8 8003E5B8 2000B28F */  lw         $s2, 0x20($sp)
    /* 2EDBC 8003E5BC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2EDC0 8003E5C0 1800B08F */  lw         $s0, 0x18($sp)
    /* 2EDC4 8003E5C4 0800E003 */  jr         $ra
    /* 2EDC8 8003E5C8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8003E444
