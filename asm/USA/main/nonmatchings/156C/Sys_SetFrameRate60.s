nonmatching Sys_SetFrameRate60, 0xC

glabel Sys_SetFrameRate60
    /* 14164 80023964 0680023C */  lui        $v0, %hi(D_8005F774)
    /* 14168 80023968 0800E003 */  jr         $ra
    /* 1416C 8002396C 74F740AC */   sw        $zero, %lo(D_8005F774)($v0)
endlabel Sys_SetFrameRate60
