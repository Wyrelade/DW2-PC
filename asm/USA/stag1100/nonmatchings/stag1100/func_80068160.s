nonmatching func_80068160, 0x20

glabel func_80068160
    /* 4E00 80068160 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E04 80068164 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4E08 80068168 5C44000C */  jal        Task_DefaultDestroy
    /* 4E0C 8006816C 00000000 */   nop
    /* 4E10 80068170 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E14 80068174 00000000 */  nop
    /* 4E18 80068178 0800E003 */  jr         $ra
    /* 4E1C 8006817C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068160
