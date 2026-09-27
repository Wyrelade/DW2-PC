nonmatching Menu_GridIndexRowMajor, 0x20

glabel Menu_GridIndexRowMajor
    /* 4290 80013A90 0000A384 */  lh         $v1, 0x0($a1)
    /* 4294 80013A94 02008284 */  lh         $v0, 0x2($a0)
    /* 4298 80013A98 00000000 */  nop
    /* 429C 80013A9C 18006200 */  mult       $v1, $v0
    /* 42A0 80013AA0 00008284 */  lh         $v0, 0x0($a0)
    /* 42A4 80013AA4 12300000 */  mflo       $a2
    /* 42A8 80013AA8 0800E003 */  jr         $ra
    /* 42AC 80013AAC 2110C200 */   addu      $v0, $a2, $v0
endlabel Menu_GridIndexRowMajor
