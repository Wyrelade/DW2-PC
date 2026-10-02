nonmatching GetIntrMask, 0x18

glabel GetIntrMask
    /* 21638 80030E38 0580023C */  lui        $v0, %hi(Sys_IntrMaskPtr)
    /* 2163C 80030E3C 88FB428C */  lw         $v0, %lo(Sys_IntrMaskPtr)($v0)
    /* 21640 80030E40 00000000 */  nop
    /* 21644 80030E44 00004294 */  lhu        $v0, 0x0($v0)
    /* 21648 80030E48 0800E003 */  jr         $ra
    /* 2164C 80030E4C 00000000 */   nop
endlabel GetIntrMask
