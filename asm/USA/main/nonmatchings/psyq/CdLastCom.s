nonmatching CdLastCom, 0x10

glabel CdLastCom
    /* 20CA4 800304A4 0580023C */  lui        $v0, %hi(D_8004E6E5)
    /* 20CA8 800304A8 E5E64290 */  lbu        $v0, %lo(D_8004E6E5)($v0)
    /* 20CAC 800304AC 0800E003 */  jr         $ra
    /* 20CB0 800304B0 00000000 */   nop
endlabel CdLastCom
