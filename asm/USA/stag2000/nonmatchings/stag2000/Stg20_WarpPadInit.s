nonmatching Stg20_WarpPadInit, 0x8

glabel Stg20_WarpPadInit
    /* C078 8006F3D8 0800E003 */  jr         $ra
    /* C07C 8006F3DC 080085AC */   sw        $a1, 0x8($a0)
endlabel Stg20_WarpPadInit
