nonmatching GetVideoMode, 0x10

glabel GetVideoMode
    /* 22038 80031838 0580023C */  lui        $v0, %hi(Sys_VideoMode)
    /* 2203C 8003183C 00FC428C */  lw         $v0, %lo(Sys_VideoMode)($v0)
    /* 22040 80031840 0800E003 */  jr         $ra
    /* 22044 80031844 00000000 */   nop
endlabel GetVideoMode
    /* 22048 80031848 00000000 */  nop
    /* 2204C 8003184C 00000000 */  nop
    /* 22050 80031850 00000000 */  nop
