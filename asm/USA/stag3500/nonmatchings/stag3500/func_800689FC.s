nonmatching func_800689FC, 0xA4

glabel func_800689FC
    /* 569C 800689FC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 56A0 80068A00 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 56A4 80068A04 21988000 */  addu       $s3, $a0, $zero
    /* 56A8 80068A08 2000BFAF */  sw         $ra, 0x20($sp)
    /* 56AC 80068A0C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 56B0 80068A10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 56B4 80068A14 1000B0AF */  sw         $s0, 0x10($sp)
    /* 56B8 80068A18 2C00728E */  lw         $s2, 0x2C($s3)
    /* 56BC 80068A1C 21800000 */  addu       $s0, $zero, $zero
    /* 56C0 80068A20 21884002 */  addu       $s1, $s2, $zero
  .L80068A24:
    /* 56C4 80068A24 5A98010C */  jal        func_80066168
    /* 56C8 80068A28 21202002 */   addu      $a0, $s1, $zero
    /* 56CC 80068A2C 01001026 */  addiu      $s0, $s0, 0x1
    /* 56D0 80068A30 0300022A */  slti       $v0, $s0, 0x3
    /* 56D4 80068A34 FBFF4014 */  bnez       $v0, .L80068A24
    /* 56D8 80068A38 04003126 */   addiu     $s1, $s1, 0x4
    /* 56DC 80068A3C 21800000 */  addu       $s0, $zero, $zero
    /* 56E0 80068A40 0C001124 */  addiu      $s1, $zero, 0xC
  .L80068A44:
    /* 56E4 80068A44 C695010C */  jal        func_80065718
    /* 56E8 80068A48 21205102 */   addu      $a0, $s2, $s1
    /* 56EC 80068A4C 01001026 */  addiu      $s0, $s0, 0x1
    /* 56F0 80068A50 0700022A */  slti       $v0, $s0, 0x7
    /* 56F4 80068A54 FBFF4014 */  bnez       $v0, .L80068A44
    /* 56F8 80068A58 04003126 */   addiu     $s1, $s1, 0x4
    /* 56FC 80068A5C 21800000 */  addu       $s0, $zero, $zero
    /* 5700 80068A60 28001124 */  addiu      $s1, $zero, 0x28
  .L80068A64:
    /* 5704 80068A64 3D96010C */  jal        func_800658F4
    /* 5708 80068A68 21205102 */   addu      $a0, $s2, $s1
    /* 570C 80068A6C 01001026 */  addiu      $s0, $s0, 0x1
    /* 5710 80068A70 0A00022A */  slti       $v0, $s0, 0xA
    /* 5714 80068A74 FBFF4014 */  bnez       $v0, .L80068A64
    /* 5718 80068A78 04003126 */   addiu     $s1, $s1, 0x4
    /* 571C 80068A7C 5C44000C */  jal        Task_DefaultDestroy
    /* 5720 80068A80 21206002 */   addu      $a0, $s3, $zero
    /* 5724 80068A84 2000BF8F */  lw         $ra, 0x20($sp)
    /* 5728 80068A88 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 572C 80068A8C 1800B28F */  lw         $s2, 0x18($sp)
    /* 5730 80068A90 1400B18F */  lw         $s1, 0x14($sp)
    /* 5734 80068A94 1000B08F */  lw         $s0, 0x10($sp)
    /* 5738 80068A98 0800E003 */  jr         $ra
    /* 573C 80068A9C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800689FC
