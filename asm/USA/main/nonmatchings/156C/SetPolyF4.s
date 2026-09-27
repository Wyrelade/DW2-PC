nonmatching SetPolyF4, 0x14

glabel SetPolyF4
    /* 1B334 8002AB34 05000224 */  addiu      $v0, $zero, 0x5
    /* 1B338 8002AB38 030082A0 */  sb         $v0, 0x3($a0)
    /* 1B33C 8002AB3C 28000224 */  addiu      $v0, $zero, 0x28
    /* 1B340 8002AB40 0800E003 */  jr         $ra
    /* 1B344 8002AB44 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetPolyF4
    /* 1B348 8002AB48 00000000 */  nop
    /* 1B34C 8002AB4C 00000000 */  nop
    /* 1B350 8002AB50 00000000 */  nop
