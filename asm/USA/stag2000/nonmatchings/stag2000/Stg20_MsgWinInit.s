nonmatching Stg20_MsgWinInit, 0x8

glabel Stg20_MsgWinInit
    /* 57DC 80068B3C 0800E003 */  jr         $ra
    /* 57E0 80068B40 080085AC */   sw        $a1, 0x8($a0)
endlabel Stg20_MsgWinInit
