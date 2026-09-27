nonmatching InitHeap, 0xC

glabel InitHeap
    /* 177B4 80026FB4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 177B8 80026FB8 08004001 */  jr         $t2
    /* 177BC 80026FBC 39000924 */   addiu     $t1, $zero, 0x39
endlabel InitHeap
    /* 177C0 80026FC0 00000000 */  nop
