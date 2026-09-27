nonmatching func_8002DCF8, 0x28

glabel func_8002DCF8
    /* 1E4F8 8002DCF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E4FC 8002DCFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E500 8002DD00 00F0043C */  lui        $a0, (0xF0000003 >> 16)
    /* 1E504 8002DD04 03008434 */  ori        $a0, $a0, (0xF0000003 & 0xFFFF)
    /* 1E508 8002DD08 55B7000C */  jal        DeliverEvent
    /* 1E50C 8002DD0C 40000524 */   addiu     $a1, $zero, 0x40
    /* 1E510 8002DD10 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E514 8002DD14 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E518 8002DD18 0800E003 */  jr         $ra
    /* 1E51C 8002DD1C 00000000 */   nop
endlabel func_8002DCF8
