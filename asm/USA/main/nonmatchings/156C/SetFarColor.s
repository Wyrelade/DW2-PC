/* Handwritten function */
nonmatching SetFarColor, 0x20

glabel SetFarColor
    /* 1DE84 8002D684 00210400 */  sll        $a0, $a0, 4
    /* 1DE88 8002D688 00290500 */  sll        $a1, $a1, 4
    /* 1DE8C 8002D68C 00310600 */  sll        $a2, $a2, 4
    /* 1DE90 8002D690 00A8C448 */  ctc2       $a0, $21 /* handwritten instruction */
    /* 1DE94 8002D694 00B0C548 */  ctc2       $a1, $22 /* handwritten instruction */
    /* 1DE98 8002D698 00B8C648 */  ctc2       $a2, $23 /* handwritten instruction */
    /* 1DE9C 8002D69C 0800E003 */  jr         $ra
    /* 1DEA0 8002D6A0 00000000 */   nop
endlabel SetFarColor
