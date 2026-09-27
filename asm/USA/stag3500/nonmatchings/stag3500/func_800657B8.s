nonmatching func_800657B8, 0x38

glabel func_800657B8
    /* 2458 800657B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 245C 800657BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2460 800657C0 21808000 */  addu       $s0, $a0, $zero
    /* 2464 800657C4 FD01043C */  lui        $a0, (0x1FD0000 >> 16)
    /* 2468 800657C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 246C 800657CC 688E000C */  jal        Cd_GetFileEntry
    /* 2470 800657D0 2120A400 */   addu      $a0, $a1, $a0
    /* 2474 800657D4 0000038E */  lw         $v1, 0x0($s0)
    /* 2478 800657D8 00000000 */  nop
    /* 247C 800657DC 040062AC */  sw         $v0, 0x4($v1)
    /* 2480 800657E0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2484 800657E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2488 800657E8 0800E003 */  jr         $ra
    /* 248C 800657EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800657B8
