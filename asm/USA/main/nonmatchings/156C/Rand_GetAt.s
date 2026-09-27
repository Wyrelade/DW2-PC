nonmatching Rand_GetAt, 0x20

glabel Rand_GetAt
    /* 14144 80023944 0480023C */  lui        $v0, %hi(D_80041704)
    /* 14148 80023948 04174224 */  addiu      $v0, $v0, %lo(D_80041704)
    /* 1414C 8002394C FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 14150 80023950 40200400 */  sll        $a0, $a0, 1
    /* 14154 80023954 21208200 */  addu       $a0, $a0, $v0
    /* 14158 80023958 00008294 */  lhu        $v0, 0x0($a0)
    /* 1415C 8002395C 0800E003 */  jr         $ra
    /* 14160 80023960 00000000 */   nop
endlabel Rand_GetAt
