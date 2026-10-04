nonmatching Rand_Next, 0x34

glabel Rand_Next
    /* 14110 80023910 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14114 80023914 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14118 80023918 3D8E000C */  jal        Rand_Step
    /* 1411C 8002391C 00000000 */   nop
    /* 14120 80023920 0480033C */  lui        $v1, %hi(Rand_Table)
    /* 14124 80023924 04176324 */  addiu      $v1, $v1, %lo(Rand_Table)
    /* 14128 80023928 9800828F */  lw         $v0, %gp_rel(Rand_Index)($gp)
    /* 1412C 8002392C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14130 80023930 40100200 */  sll        $v0, $v0, 1
    /* 14134 80023934 21104300 */  addu       $v0, $v0, $v1
    /* 14138 80023938 00004294 */  lhu        $v0, 0x0($v0)
    /* 1413C 8002393C 0800E003 */  jr         $ra
    /* 14140 80023940 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Rand_Next
