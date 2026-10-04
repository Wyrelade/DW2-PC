nonmatching Menu_TopMenuInit, 0xC

glabel Menu_TopMenuInit
    /* 43F8 80013BF8 2C00828C */  lw         $v0, 0x2C($a0)
    /* 43FC 80013BFC 0800E003 */  jr         $ra
    /* 4400 80013C00 300045A4 */   sh        $a1, 0x30($v0)
endlabel Menu_TopMenuInit
