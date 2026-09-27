nonmatching func_800676F4, 0x18

glabel func_800676F4
    /* 4394 800676F4 0780023C */  lui        $v0, %hi(D_800685D0)
    /* 4398 800676F8 D085428C */  lw         $v0, %lo(D_800685D0)($v0)
    /* 439C 800676FC 00000000 */  nop
    /* 43A0 80067700 2C00428C */  lw         $v0, 0x2C($v0)
    /* 43A4 80067704 0800E003 */  jr         $ra
    /* 43A8 80067708 34024224 */   addiu     $v0, $v0, 0x234
endlabel func_800676F4
