nonmatching Pad_CalcInfoBufSize, 0x38

glabel Pad_CalcInfoBufSize
    /* 167BC 80025FBC E3008290 */  lbu        $v0, 0xE3($a0)
    /* 167C0 80025FC0 E9008590 */  lbu        $a1, 0xE9($a0)
    /* 167C4 80025FC4 EC008494 */  lhu        $a0, 0xEC($a0)
    /* 167C8 80025FC8 01004224 */  addiu      $v0, $v0, 0x1
    /* 167CC 80025FCC 43100200 */  sra        $v0, $v0, 1
    /* 167D0 80025FD0 80100200 */  sll        $v0, $v0, 2
    /* 167D4 80025FD4 80180500 */  sll        $v1, $a1, 2
    /* 167D8 80025FD8 21186500 */  addu       $v1, $v1, $a1
    /* 167DC 80025FDC 03006324 */  addiu      $v1, $v1, 0x3
    /* 167E0 80025FE0 FC0F6330 */  andi       $v1, $v1, 0xFFC
    /* 167E4 80025FE4 04006324 */  addiu      $v1, $v1, 0x4
    /* 167E8 80025FE8 21104300 */  addu       $v0, $v0, $v1
    /* 167EC 80025FEC 0800E003 */  jr         $ra
    /* 167F0 80025FF0 21104400 */   addu      $v0, $v0, $a0
endlabel Pad_CalcInfoBufSize
