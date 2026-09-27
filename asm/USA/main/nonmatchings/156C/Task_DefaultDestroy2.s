nonmatching Task_DefaultDestroy2, 0x20

glabel Task_DefaultDestroy2
    /* 3C50 80013450 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C54 80013454 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C58 80013458 9744000C */  jal        Task_Free
    /* 3C5C 8001345C 00000000 */   nop
    /* 3C60 80013460 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3C64 80013464 00000000 */  nop
    /* 3C68 80013468 0800E003 */  jr         $ra
    /* 3C6C 8001346C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Task_DefaultDestroy2
