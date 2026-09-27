nonmatching Card_OnSwError, 0x14

glabel Card_OnSwError
    /* 30338 8003FB38 01000224 */  addiu      $v0, $zero, 0x1
    /* 3033C 8003FB3C 0680013C */  lui        $at, %hi(D_80063084)
    /* 30340 8003FB40 843022AC */  sw         $v0, %lo(D_80063084)($at)
    /* 30344 8003FB44 0800E003 */  jr         $ra
    /* 30348 8003FB48 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnSwError
