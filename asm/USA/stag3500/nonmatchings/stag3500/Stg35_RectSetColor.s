nonmatching Stg35_RectSetColor, 0x20

glabel Stg35_RectSetColor
    /* 27BC 80065B1C 80280500 */  sll        $a1, $a1, 2
    /* 27C0 80065B20 0000828C */  lw         $v0, 0x0($a0)
    /* 27C4 80065B24 1000A38F */  lw         $v1, 0x10($sp)
    /* 27C8 80065B28 21104500 */  addu       $v0, $v0, $a1
    /* 27CC 80065B2C 040046A0 */  sb         $a2, 0x4($v0)
    /* 27D0 80065B30 050047A0 */  sb         $a3, 0x5($v0)
    /* 27D4 80065B34 0800E003 */  jr         $ra
    /* 27D8 80065B38 060043A0 */   sb        $v1, 0x6($v0)
endlabel Stg35_RectSetColor
