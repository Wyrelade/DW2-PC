/* Handwritten function */
nonmatching SetColorMatrix, 0x30

glabel SetColorMatrix
    /* 1DE14 8002D614 0000888C */  lw         $t0, 0x0($a0)
    /* 1DE18 8002D618 0400898C */  lw         $t1, 0x4($a0)
    /* 1DE1C 8002D61C 08008A8C */  lw         $t2, 0x8($a0)
    /* 1DE20 8002D620 0C008B8C */  lw         $t3, 0xC($a0)
    /* 1DE24 8002D624 10008C8C */  lw         $t4, 0x10($a0)
    /* 1DE28 8002D628 0080C848 */  ctc2       $t0, $16 /* handwritten instruction */
    /* 1DE2C 8002D62C 0088C948 */  ctc2       $t1, $17 /* handwritten instruction */
    /* 1DE30 8002D630 0090CA48 */  ctc2       $t2, $18 /* handwritten instruction */
    /* 1DE34 8002D634 0098CB48 */  ctc2       $t3, $19 /* handwritten instruction */
    /* 1DE38 8002D638 00A0CC48 */  ctc2       $t4, $20 /* handwritten instruction */
    /* 1DE3C 8002D63C 0800E003 */  jr         $ra
    /* 1DE40 8002D640 00000000 */   nop
endlabel SetColorMatrix
