/* Handwritten function */
nonmatching SetGeomScreen, 0xC

glabel SetGeomScreen
    /* 1DEC4 8002D6C4 00D0C448 */  ctc2       $a0, $26 /* handwritten instruction */
    /* 1DEC8 8002D6C8 0800E003 */  jr         $ra
    /* 1DECC 8002D6CC 00000000 */   nop
endlabel SetGeomScreen
    /* 1DED0 8002D6D0 00000000 */  nop
