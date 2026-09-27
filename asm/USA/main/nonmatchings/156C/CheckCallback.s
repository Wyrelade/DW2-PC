nonmatching CheckCallback, 0x10

glabel CheckCallback
    /* 21628 80030E28 0580023C */  lui        $v0, %hi(D_8004EAFA)
    /* 2162C 80030E2C FAEA4294 */  lhu        $v0, %lo(D_8004EAFA)($v0)
    /* 21630 80030E30 0800E003 */  jr         $ra
    /* 21634 80030E34 00000000 */   nop
endlabel CheckCallback
