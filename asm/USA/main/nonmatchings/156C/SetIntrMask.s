nonmatching SetIntrMask, 0x18

glabel SetIntrMask
    /* 21650 80030E50 0580033C */  lui        $v1, %hi(Sys_IntrMaskPtr)
    /* 21654 80030E54 88FB638C */  lw         $v1, %lo(Sys_IntrMaskPtr)($v1)
    /* 21658 80030E58 00000000 */  nop
    /* 2165C 80030E5C 00006294 */  lhu        $v0, 0x0($v1)
    /* 21660 80030E60 0800E003 */  jr         $ra
    /* 21664 80030E64 000064A4 */   sh        $a0, 0x0($v1)
endlabel SetIntrMask
