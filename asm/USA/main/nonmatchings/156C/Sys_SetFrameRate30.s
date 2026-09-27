nonmatching Sys_SetFrameRate30, 0x10

glabel Sys_SetFrameRate30
    /* 14170 80023970 0680033C */  lui        $v1, %hi(D_8005F774)
    /* 14174 80023974 02000224 */  addiu      $v0, $zero, 0x2
    /* 14178 80023978 0800E003 */  jr         $ra
    /* 1417C 8002397C 74F762AC */   sw        $v0, %lo(D_8005F774)($v1)
endlabel Sys_SetFrameRate30
