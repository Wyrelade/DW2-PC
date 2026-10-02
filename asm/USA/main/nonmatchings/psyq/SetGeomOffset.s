/* Handwritten function */
nonmatching SetGeomOffset, 0x18

glabel SetGeomOffset
    /* 1DEA4 8002D6A4 00240400 */  sll        $a0, $a0, 16
    /* 1DEA8 8002D6A8 002C0500 */  sll        $a1, $a1, 16
    /* 1DEAC 8002D6AC 00C0C448 */  ctc2       $a0, $24 /* handwritten instruction */
    /* 1DEB0 8002D6B0 00C8C548 */  ctc2       $a1, $25 /* handwritten instruction */
    /* 1DEB4 8002D6B4 0800E003 */  jr         $ra
    /* 1DEB8 8002D6B8 00000000 */   nop
endlabel SetGeomOffset
    /* 1DEBC 8002D6BC 00000000 */  nop
    /* 1DEC0 8002D6C0 00000000 */  nop
