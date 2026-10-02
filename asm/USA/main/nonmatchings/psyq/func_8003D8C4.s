nonmatching func_8003D8C4, 0x28

glabel func_8003D8C4
    /* 2E0C4 8003D8C4 0680093C */  lui        $t1, %hi(jtbl_80062F18)
    /* 2E0C8 8003D8C8 182F298D */  lw         $t1, %lo(jtbl_80062F18)($t1)
    /* 2E0CC 8003D8CC 00000000 */  nop
    /* 2E0D0 8003D8D0 08002001 */  jr         $t1
    /* 2E0D4 8003D8D4 00000000 */   nop
    /* 2E0D8 8003D8D8 0680093C */  lui        $t1, %hi(jtbl_80062F1C)
    /* 2E0DC 8003D8DC 1C2F298D */  lw         $t1, %lo(jtbl_80062F1C)($t1)
    /* 2E0E0 8003D8E0 00000000 */  nop
    /* 2E0E4 8003D8E4 08002001 */  jr         $t1
    /* 2E0E8 8003D8E8 00000000 */   nop
endlabel func_8003D8C4
