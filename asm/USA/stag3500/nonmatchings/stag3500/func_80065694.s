nonmatching func_80065694, 0x3C

glabel func_80065694
    /* 2334 80065694 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2338 80065698 1000B0AF */  sw         $s0, 0x10($sp)
    /* 233C 8006569C 21808000 */  addu       $s0, $a0, $zero
    /* 2340 800656A0 40010424 */  addiu      $a0, $zero, 0x140
    /* 2344 800656A4 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 2348 800656A8 21300000 */  addu       $a2, $zero, $zero
    /* 234C 800656AC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2350 800656B0 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 2354 800656B4 2138C000 */   addu      $a3, $a2, $zero
    /* 2358 800656B8 5C44000C */  jal        Task_DefaultDestroy
    /* 235C 800656BC 21200002 */   addu      $a0, $s0, $zero
    /* 2360 800656C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2364 800656C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2368 800656C8 0800E003 */  jr         $ra
    /* 236C 800656CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80065694
