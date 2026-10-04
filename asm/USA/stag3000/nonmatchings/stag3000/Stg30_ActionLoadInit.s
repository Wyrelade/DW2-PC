nonmatching Stg30_ActionLoadInit, 0x10

glabel Stg30_ActionLoadInit
    /* 810 80063B70 2C00838C */  lw         $v1, 0x2C($a0)
    /* 814 80063B74 0000A28C */  lw         $v0, 0x0($a1)
    /* 818 80063B78 0800E003 */  jr         $ra
    /* 81C 80063B7C 000062AC */   sw        $v0, 0x0($v1)
endlabel Stg30_ActionLoadInit
