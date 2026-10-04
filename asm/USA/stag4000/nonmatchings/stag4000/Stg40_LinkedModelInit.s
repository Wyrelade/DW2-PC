nonmatching Stg40_LinkedModelInit, 0x1C

glabel Stg40_LinkedModelInit
    /* 1610 80064970 2C00838C */  lw         $v1, 0x2C($a0)
    /* 1614 80064974 0000A28C */  lw         $v0, 0x0($a1)
    /* 1618 80064978 00000000 */  nop
    /* 161C 8006497C 200062AC */  sw         $v0, 0x20($v1)
    /* 1620 80064980 0400A294 */  lhu        $v0, 0x4($a1)
    /* 1624 80064984 0800E003 */  jr         $ra
    /* 1628 80064988 240062A4 */   sh        $v0, 0x24($v1)
endlabel Stg40_LinkedModelInit
