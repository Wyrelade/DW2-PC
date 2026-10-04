nonmatching Stg00_PopupInit, 0x20

glabel Stg00_PopupInit
    /* 46F0 80067A50 2C00828C */  lw         $v0, 0x2C($a0)
    /* 46F4 80067A54 0000A38C */  lw         $v1, 0x0($a1)
    /* 46F8 80067A58 0400A68C */  lw         $a2, 0x4($a1)
    /* 46FC 80067A5C 0800A78C */  lw         $a3, 0x8($a1)
    /* 4700 80067A60 000043AC */  sw         $v1, 0x0($v0)
    /* 4704 80067A64 040046AC */  sw         $a2, 0x4($v0)
    /* 4708 80067A68 0800E003 */  jr         $ra
    /* 470C 80067A6C 080047AC */   sw        $a3, 0x8($v0)
endlabel Stg00_PopupInit
