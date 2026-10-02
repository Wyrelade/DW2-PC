/* Handwritten function */
nonmatching Gte_CountLeadingZeros, 0x18

glabel Gte_CountLeadingZeros
    /* 1E3B4 8002DBB4 00F08448 */  mtc2       $a0, $30 /* handwritten instruction */
    /* 1E3B8 8002DBB8 00000000 */  nop
    /* 1E3BC 8002DBBC 00000000 */  nop
    /* 1E3C0 8002DBC0 00F80248 */  mfc2       $v0, $31 /* handwritten instruction */
    /* 1E3C4 8002DBC4 0800E003 */  jr         $ra
    /* 1E3C8 8002DBC8 00000000 */   nop
endlabel Gte_CountLeadingZeros
    /* 1E3CC 8002DBCC 00000000 */  nop
    /* 1E3D0 8002DBD0 00000000 */  nop
