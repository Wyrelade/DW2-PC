nonmatching Task_DefaultDestroy, 0x20

glabel Task_DefaultDestroy
    /* 1970 80011170 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1974 80011174 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1978 80011178 9744000C */  jal        Task_Free
    /* 197C 8001117C 00000000 */   nop
    /* 1980 80011180 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1984 80011184 00000000 */  nop
    /* 1988 80011188 0800E003 */  jr         $ra
    /* 198C 8001118C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Task_DefaultDestroy
