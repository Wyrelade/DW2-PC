nonmatching Stg35_RectSetX, 0xC

glabel Stg35_RectSetX
    /* 27F4 80065B54 0000828C */  lw         $v0, 0x0($a0)
    /* 27F8 80065B58 0800E003 */  jr         $ra
    /* 27FC 80065B5C 180045A4 */   sh        $a1, 0x18($v0)
endlabel Stg35_RectSetX
