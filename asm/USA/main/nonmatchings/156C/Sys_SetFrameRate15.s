nonmatching Sys_SetFrameRate15, 0x10

glabel Sys_SetFrameRate15
    /* 14190 80023990 0680033C */  lui        $v1, %hi(D_8005F774)
    /* 14194 80023994 04000224 */  addiu      $v0, $zero, 0x4
    /* 14198 80023998 0800E003 */  jr         $ra
    /* 1419C 8002399C 74F762AC */   sw        $v0, %lo(D_8005F774)($v1)
endlabel Sys_SetFrameRate15
