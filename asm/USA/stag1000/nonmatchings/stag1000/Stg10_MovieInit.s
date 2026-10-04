nonmatching Stg10_MovieInit, 0x28

glabel Stg10_MovieInit
    /* B28 80063E88 0580033C */  lui        $v1, %hi(D_80050741)
    /* B2C 80063E8C 01000224 */  addiu      $v0, $zero, 0x1
    /* B30 80063E90 410762A0 */  sb         $v0, %lo(D_80050741)($v1)
    /* B34 80063E94 0000A38C */  lw         $v1, 0x0($a1)
    /* B38 80063E98 0680023C */  lui        $v0, %hi(Stg10_MovieFileId)
    /* B3C 80063E9C 006243AC */  sw         $v1, %lo(Stg10_MovieFileId)($v0)
    /* B40 80063EA0 0400A38C */  lw         $v1, 0x4($a1)
    /* B44 80063EA4 0680023C */  lui        $v0, %hi(Stg10_MovieEndFrame)
    /* B48 80063EA8 0800E003 */  jr         $ra
    /* B4C 80063EAC 046243AC */   sw        $v1, %lo(Stg10_MovieEndFrame)($v0)
endlabel Stg10_MovieInit
