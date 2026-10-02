nonmatching Card_OnSwTimeout, 0x14

glabel Card_OnSwTimeout
    /* 3034C 8003FB4C 01000224 */  addiu      $v0, $zero, 0x1
    /* 30350 8003FB50 0680013C */  lui        $at, %hi(D_80063088)
    /* 30354 8003FB54 883022AC */  sw         $v0, %lo(D_80063088)($at)
    /* 30358 8003FB58 0800E003 */  jr         $ra
    /* 3035C 8003FB5C 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnSwTimeout
