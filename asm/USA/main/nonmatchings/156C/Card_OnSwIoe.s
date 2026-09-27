nonmatching Card_OnSwIoe, 0x14

glabel Card_OnSwIoe
    /* 30324 8003FB24 01000224 */  addiu      $v0, $zero, 0x1
    /* 30328 8003FB28 0680013C */  lui        $at, %hi(D_80063080)
    /* 3032C 8003FB2C 803022AC */  sw         $v0, %lo(D_80063080)($at)
    /* 30330 8003FB30 0800E003 */  jr         $ra
    /* 30334 8003FB34 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnSwIoe
