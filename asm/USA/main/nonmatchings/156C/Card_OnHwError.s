nonmatching Card_OnHwError, 0x14

glabel Card_OnHwError
    /* 30388 8003FB88 01000224 */  addiu      $v0, $zero, 0x1
    /* 3038C 8003FB8C 0680013C */  lui        $at, %hi(D_80063094)
    /* 30390 8003FB90 943022AC */  sw         $v0, %lo(D_80063094)($at)
    /* 30394 8003FB94 0800E003 */  jr         $ra
    /* 30398 8003FB98 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnHwError
