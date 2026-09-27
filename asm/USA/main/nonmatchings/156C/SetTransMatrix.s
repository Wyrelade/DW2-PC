/* Handwritten function */
nonmatching SetTransMatrix, 0x20

glabel SetTransMatrix
    /* 1DE44 8002D644 1400888C */  lw         $t0, 0x14($a0)
    /* 1DE48 8002D648 1800898C */  lw         $t1, 0x18($a0)
    /* 1DE4C 8002D64C 1C008A8C */  lw         $t2, 0x1C($a0)
    /* 1DE50 8002D650 0028C848 */  ctc2       $t0, $5 /* handwritten instruction */
    /* 1DE54 8002D654 0030C948 */  ctc2       $t1, $6 /* handwritten instruction */
    /* 1DE58 8002D658 0038CA48 */  ctc2       $t2, $7 /* handwritten instruction */
    /* 1DE5C 8002D65C 0800E003 */  jr         $ra
    /* 1DE60 8002D660 00000000 */   nop
endlabel SetTransMatrix
