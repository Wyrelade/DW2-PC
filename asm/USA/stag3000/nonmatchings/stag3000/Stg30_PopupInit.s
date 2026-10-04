nonmatching Stg30_PopupInit, 0x20

glabel Stg30_PopupInit
    /* C56C 8006F8CC 2C00828C */  lw         $v0, 0x2C($a0)
    /* C570 8006F8D0 0000A38C */  lw         $v1, 0x0($a1)
    /* C574 8006F8D4 0400A68C */  lw         $a2, 0x4($a1)
    /* C578 8006F8D8 0800A78C */  lw         $a3, 0x8($a1)
    /* C57C 8006F8DC 000043AC */  sw         $v1, 0x0($v0)
    /* C580 8006F8E0 040046AC */  sw         $a2, 0x4($v0)
    /* C584 8006F8E4 0800E003 */  jr         $ra
    /* C588 8006F8E8 080047AC */   sw        $a3, 0x8($v0)
endlabel Stg30_PopupInit
