nonmatching GetGraphDebug, 0x10

glabel GetGraphDebug
    /* 17B78 80027378 0580023C */  lui        $v0, %hi(D_80048F12)
    /* 17B7C 8002737C 128F4290 */  lbu        $v0, %lo(D_80048F12)($v0)
    /* 17B80 80027380 0800E003 */  jr         $ra
    /* 17B84 80027384 00000000 */   nop
endlabel GetGraphDebug
