nonmatching Stg20_XaStreamInit, 0x20

glabel Stg20_XaStreamInit
    /* 84E0 8006B840 2C00828C */  lw         $v0, 0x2C($a0)
    /* 84E4 8006B844 0000A38C */  lw         $v1, 0x0($a1)
    /* 84E8 8006B848 0400A68C */  lw         $a2, 0x4($a1)
    /* 84EC 8006B84C 0800A78C */  lw         $a3, 0x8($a1)
    /* 84F0 8006B850 000043AC */  sw         $v1, 0x0($v0)
    /* 84F4 8006B854 040046AC */  sw         $a2, 0x4($v0)
    /* 84F8 8006B858 0800E003 */  jr         $ra
    /* 84FC 8006B85C 080047AC */   sw        $a3, 0x8($v0)
endlabel Stg20_XaStreamInit
