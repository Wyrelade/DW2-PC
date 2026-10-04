nonmatching Stg20_ShadowInit, 0xC

glabel Stg20_ShadowInit
    /* 6EE8 8006A248 2C00828C */  lw         $v0, 0x2C($a0)
    /* 6EEC 8006A24C 0800E003 */  jr         $ra
    /* 6EF0 8006A250 000045AC */   sw        $a1, 0x0($v0)
endlabel Stg20_ShadowInit
