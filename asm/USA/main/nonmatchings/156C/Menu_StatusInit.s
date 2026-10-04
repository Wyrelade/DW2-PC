nonmatching Menu_StatusInit, 0xC

glabel Menu_StatusInit
    /* 5178 80014978 2C00828C */  lw         $v0, 0x2C($a0)
    /* 517C 8001497C 0800E003 */  jr         $ra
    /* 5180 80014980 6C0045A4 */   sh        $a1, 0x6C($v0)
endlabel Menu_StatusInit
