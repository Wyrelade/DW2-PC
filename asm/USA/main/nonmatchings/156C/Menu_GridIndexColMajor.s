nonmatching Menu_GridIndexColMajor, 0x20

glabel Menu_GridIndexColMajor
    /* 4270 80013A70 0200A384 */  lh         $v1, 0x2($a1)
    /* 4274 80013A74 00008284 */  lh         $v0, 0x0($a0)
    /* 4278 80013A78 00000000 */  nop
    /* 427C 80013A7C 18006200 */  mult       $v1, $v0
    /* 4280 80013A80 02008284 */  lh         $v0, 0x2($a0)
    /* 4284 80013A84 12300000 */  mflo       $a2
    /* 4288 80013A88 0800E003 */  jr         $ra
    /* 428C 80013A8C 2110C200 */   addu      $v0, $a2, $v0
endlabel Menu_GridIndexColMajor
