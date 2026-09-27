nonmatching CdPosToInt, 0x80

glabel CdPosToInt
    /* 1E564 8002DD64 00008390 */  lbu        $v1, 0x0($a0)
    /* 1E568 8002DD68 01008690 */  lbu        $a2, 0x1($a0)
    /* 1E56C 8002DD6C 02290300 */  srl        $a1, $v1, 4
    /* 1E570 8002DD70 80100500 */  sll        $v0, $a1, 2
    /* 1E574 8002DD74 21104500 */  addu       $v0, $v0, $a1
    /* 1E578 8002DD78 40100200 */  sll        $v0, $v0, 1
    /* 1E57C 8002DD7C 0F006330 */  andi       $v1, $v1, 0xF
    /* 1E580 8002DD80 21104300 */  addu       $v0, $v0, $v1
    /* 1E584 8002DD84 00290200 */  sll        $a1, $v0, 4
    /* 1E588 8002DD88 2328A200 */  subu       $a1, $a1, $v0
    /* 1E58C 8002DD8C 80280500 */  sll        $a1, $a1, 2
    /* 1E590 8002DD90 02190600 */  srl        $v1, $a2, 4
    /* 1E594 8002DD94 80100300 */  sll        $v0, $v1, 2
    /* 1E598 8002DD98 21104300 */  addu       $v0, $v0, $v1
    /* 1E59C 8002DD9C 40100200 */  sll        $v0, $v0, 1
    /* 1E5A0 8002DDA0 0F00C630 */  andi       $a2, $a2, 0xF
    /* 1E5A4 8002DDA4 21104600 */  addu       $v0, $v0, $a2
    /* 1E5A8 8002DDA8 2128A200 */  addu       $a1, $a1, $v0
    /* 1E5AC 8002DDAC 80180500 */  sll        $v1, $a1, 2
    /* 1E5B0 8002DDB0 21186500 */  addu       $v1, $v1, $a1
    /* 1E5B4 8002DDB4 00110300 */  sll        $v0, $v1, 4
    /* 1E5B8 8002DDB8 02008590 */  lbu        $a1, 0x2($a0)
    /* 1E5BC 8002DDBC 23104300 */  subu       $v0, $v0, $v1
    /* 1E5C0 8002DDC0 02210500 */  srl        $a0, $a1, 4
    /* 1E5C4 8002DDC4 80180400 */  sll        $v1, $a0, 2
    /* 1E5C8 8002DDC8 21186400 */  addu       $v1, $v1, $a0
    /* 1E5CC 8002DDCC 40180300 */  sll        $v1, $v1, 1
    /* 1E5D0 8002DDD0 0F00A530 */  andi       $a1, $a1, 0xF
    /* 1E5D4 8002DDD4 21186500 */  addu       $v1, $v1, $a1
    /* 1E5D8 8002DDD8 21104300 */  addu       $v0, $v0, $v1
    /* 1E5DC 8002DDDC 0800E003 */  jr         $ra
    /* 1E5E0 8002DDE0 6AFF4224 */   addiu     $v0, $v0, -0x96
endlabel CdPosToInt
