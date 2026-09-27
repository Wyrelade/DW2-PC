nonmatching Card_OnHwNewCard, 0x14

glabel Card_OnHwNewCard
    /* 303B0 8003FBB0 01000224 */  addiu      $v0, $zero, 0x1
    /* 303B4 8003FBB4 0680013C */  lui        $at, %hi(D_8006309C)
    /* 303B8 8003FBB8 9C3022AC */  sw         $v0, %lo(D_8006309C)($at)
    /* 303BC 8003FBBC 0800E003 */  jr         $ra
    /* 303C0 8003FBC0 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnHwNewCard
