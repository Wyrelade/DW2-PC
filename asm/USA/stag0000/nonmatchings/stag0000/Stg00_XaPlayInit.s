nonmatching Stg00_XaPlayInit, 0x20

glabel Stg00_XaPlayInit
    /* 4A9C 80067DFC 2C00828C */  lw         $v0, 0x2C($a0)
    /* 4AA0 80067E00 0000A38C */  lw         $v1, 0x0($a1)
    /* 4AA4 80067E04 0400A68C */  lw         $a2, 0x4($a1)
    /* 4AA8 80067E08 0800A78C */  lw         $a3, 0x8($a1)
    /* 4AAC 80067E0C 000043AC */  sw         $v1, 0x0($v0)
    /* 4AB0 80067E10 040046AC */  sw         $a2, 0x4($v0)
    /* 4AB4 80067E14 0800E003 */  jr         $ra
    /* 4AB8 80067E18 080047AC */   sw        $a3, 0x8($v0)
endlabel Stg00_XaPlayInit
