nonmatching Sys_SetFrameRate20, 0x10

glabel Sys_SetFrameRate20
    /* 14180 80023980 0680033C */  lui        $v1, %hi(D_8005F774)
    /* 14184 80023984 03000224 */  addiu      $v0, $zero, 0x3
    /* 14188 80023988 0800E003 */  jr         $ra
    /* 1418C 8002398C 74F762AC */   sw        $v0, %lo(D_8005F774)($v1)
endlabel Sys_SetFrameRate20
