nonmatching Ovl_GetCurrentId, 0xC

glabel Ovl_GetCurrentId
    /* 3B78 80013378 0400828F */  lw         $v0, %gp_rel(Ovl_CurrentId)($gp)
    /* 3B7C 8001337C 0800E003 */  jr         $ra
    /* 3B80 80013380 00000000 */   nop
endlabel Ovl_GetCurrentId
