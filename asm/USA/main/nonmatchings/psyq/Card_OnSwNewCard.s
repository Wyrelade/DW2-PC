nonmatching Card_OnSwNewCard, 0x14

glabel Card_OnSwNewCard
    /* 30360 8003FB60 01000224 */  addiu      $v0, $zero, 0x1
    /* 30364 8003FB64 0680013C */  lui        $at, %hi(D_8006308C)
    /* 30368 8003FB68 8C3022AC */  sw         $v0, %lo(D_8006308C)($at)
    /* 3036C 8003FB6C 0800E003 */  jr         $ra
    /* 30370 8003FB70 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnSwNewCard
