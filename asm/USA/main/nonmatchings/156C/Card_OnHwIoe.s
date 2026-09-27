nonmatching Card_OnHwIoe, 0x14

glabel Card_OnHwIoe
    /* 30374 8003FB74 01000224 */  addiu      $v0, $zero, 0x1
    /* 30378 8003FB78 0680013C */  lui        $at, %hi(D_80063090)
    /* 3037C 8003FB7C 903022AC */  sw         $v0, %lo(D_80063090)($at)
    /* 30380 8003FB80 0800E003 */  jr         $ra
    /* 30384 8003FB84 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnHwIoe
