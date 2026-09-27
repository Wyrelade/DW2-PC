nonmatching func_800634FC, 0x54

glabel func_800634FC
    /* 19C 800634FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1A0 80063500 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1A4 80063504 21888000 */  addu       $s1, $a0, $zero
    /* 1A8 80063508 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1AC 8006350C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B0 80063510 1000228E */  lw         $v0, 0x10($s1)
    /* 1B4 80063514 2C00308E */  lw         $s0, 0x2C($s1)
    /* 1B8 80063518 08004014 */  bnez       $v0, .L8006353C
    /* 1BC 8006351C 00000000 */   nop
    /* 1C0 80063520 4898010C */  jal        func_80066120
    /* 1C4 80063524 21200002 */   addu      $a0, $s0, $zero
    /* 1C8 80063528 21200002 */  addu       $a0, $s0, $zero
    /* 1CC 8006352C 6998010C */  jal        func_800661A4
    /* 1D0 80063530 3F0D053C */   lui       $a1, (0xD3F0000 >> 16)
    /* 1D4 80063534 5145000C */  jal        Task_NextState0
    /* 1D8 80063538 21202002 */   addu      $a0, $s1, $zero
  .L8006353C:
    /* 1DC 8006353C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1E0 80063540 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E4 80063544 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E8 80063548 0800E003 */  jr         $ra
    /* 1EC 8006354C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800634FC
