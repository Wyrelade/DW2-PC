nonmatching func_800702A8, 0x20

glabel func_800702A8
    /* CF48 800702A8 2C00828C */  lw         $v0, 0x2C($a0)
    /* CF4C 800702AC 0000A38C */  lw         $v1, 0x0($a1)
    /* CF50 800702B0 0400A68C */  lw         $a2, 0x4($a1)
    /* CF54 800702B4 0800A78C */  lw         $a3, 0x8($a1)
    /* CF58 800702B8 000043AC */  sw         $v1, 0x0($v0)
    /* CF5C 800702BC 040046AC */  sw         $a2, 0x4($v0)
    /* CF60 800702C0 0800E003 */  jr         $ra
    /* CF64 800702C4 080047AC */   sw        $a3, 0x8($v0)
endlabel func_800702A8
