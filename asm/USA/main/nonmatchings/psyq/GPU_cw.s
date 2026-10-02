nonmatching GPU_cw, 0xC

glabel GPU_cw
    /* 1A804 8002A004 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 1A808 8002A008 08004001 */  jr         $t2
    /* 1A80C 8002A00C 49000924 */   addiu     $t1, $zero, 0x49
endlabel GPU_cw
    /* 1A810 8002A010 00000000 */  nop
