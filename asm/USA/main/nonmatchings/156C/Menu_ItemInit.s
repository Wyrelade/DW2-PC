nonmatching Menu_ItemInit, 0xC

glabel Menu_ItemInit
    /* 71D0 800169D0 2C00828C */  lw         $v0, 0x2C($a0)
    /* 71D4 800169D4 0800E003 */  jr         $ra
    /* 71D8 800169D8 640045A4 */   sh        $a1, 0x64($v0)
endlabel Menu_ItemInit
