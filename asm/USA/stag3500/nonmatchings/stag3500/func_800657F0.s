nonmatching func_800657F0, 0x34

glabel func_800657F0
    /* 2490 800657F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2494 800657F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2498 800657F8 21808000 */  addu       $s0, $a0, $zero
    /* 249C 800657FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 24A0 80065800 617B000C */  jal        func_8001ED84
    /* 24A4 80065804 2120A000 */   addu      $a0, $a1, $zero
    /* 24A8 80065808 0000038E */  lw         $v1, 0x0($s0)
    /* 24AC 8006580C 00000000 */  nop
    /* 24B0 80065810 040062AC */  sw         $v0, 0x4($v1)
    /* 24B4 80065814 1400BF8F */  lw         $ra, 0x14($sp)
    /* 24B8 80065818 1000B08F */  lw         $s0, 0x10($sp)
    /* 24BC 8006581C 0800E003 */  jr         $ra
    /* 24C0 80065820 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800657F0
