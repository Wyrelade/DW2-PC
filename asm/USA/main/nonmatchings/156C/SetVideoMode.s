nonmatching SetVideoMode, 0x14

glabel SetVideoMode
    /* 22024 80031824 0580023C */  lui        $v0, %hi(Sys_VideoMode)
    /* 22028 80031828 00FC428C */  lw         $v0, %lo(Sys_VideoMode)($v0)
    /* 2202C 8003182C 0580013C */  lui        $at, %hi(Sys_VideoMode)
    /* 22030 80031830 0800E003 */  jr         $ra
    /* 22034 80031834 00FC24AC */   sw        $a0, %lo(Sys_VideoMode)($at)
endlabel SetVideoMode
