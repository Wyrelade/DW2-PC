nonmatching Stg30_ItemMenuInit, 0x10

glabel Stg30_ItemMenuInit
    /* 2224 80065584 2C00838C */  lw         $v1, 0x2C($a0)
    /* 2228 80065588 0000A28C */  lw         $v0, 0x0($a1)
    /* 222C 8006558C 0800E003 */  jr         $ra
    /* 2230 80065590 000062AC */   sw        $v0, 0x0($v1)
endlabel Stg30_ItemMenuInit
