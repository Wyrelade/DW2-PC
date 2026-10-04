nonmatching Stg35_RectSetBounds, 0x1C

glabel Stg35_RectSetBounds
    /* 280C 80065B6C 0000828C */  lw         $v0, 0x0($a0)
    /* 2810 80065B70 1000A38F */  lw         $v1, 0x10($sp)
    /* 2814 80065B74 180045A4 */  sh         $a1, 0x18($v0)
    /* 2818 80065B78 1A0046A4 */  sh         $a2, 0x1A($v0)
    /* 281C 80065B7C 1C0047A4 */  sh         $a3, 0x1C($v0)
    /* 2820 80065B80 0800E003 */  jr         $ra
    /* 2824 80065B84 1E0043A4 */   sh        $v1, 0x1E($v0)
endlabel Stg35_RectSetBounds
