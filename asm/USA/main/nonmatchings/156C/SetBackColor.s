/* Handwritten function */
nonmatching SetBackColor, 0x20

glabel SetBackColor
    /* 1DE64 8002D664 00210400 */  sll        $a0, $a0, 4
    /* 1DE68 8002D668 00290500 */  sll        $a1, $a1, 4
    /* 1DE6C 8002D66C 00310600 */  sll        $a2, $a2, 4
    /* 1DE70 8002D670 0068C448 */  ctc2       $a0, $13 /* handwritten instruction */
    /* 1DE74 8002D674 0070C548 */  ctc2       $a1, $14 /* handwritten instruction */
    /* 1DE78 8002D678 0078C648 */  ctc2       $a2, $15 /* handwritten instruction */
    /* 1DE7C 8002D67C 0800E003 */  jr         $ra
    /* 1DE80 8002D680 00000000 */   nop
endlabel SetBackColor
