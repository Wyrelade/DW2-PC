nonmatching Card_RestoreCallback, 0x28

glabel Card_RestoreCallback
    /* 2E4CC 8003DCCC 0680043C */  lui        $a0, %hi(D_80062FD8)
    /* 2E4D0 8003DCD0 D82F848C */  lw         $a0, %lo(D_80062FD8)($a0)
    /* 2E4D4 8003DCD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E4D8 8003DCD8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E4DC 8003DCDC 5EFC000C */  jal        MemCardCallback
    /* 2E4E0 8003DCE0 00000000 */   nop
    /* 2E4E4 8003DCE4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E4E8 8003DCE8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2E4EC 8003DCEC 0800E003 */  jr         $ra
    /* 2E4F0 8003DCF0 00000000 */   nop
endlabel Card_RestoreCallback
