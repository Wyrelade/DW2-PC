nonmatching Card_OnHwTimeout, 0x14

glabel Card_OnHwTimeout
    /* 3039C 8003FB9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 303A0 8003FBA0 0680013C */  lui        $at, %hi(D_80063098)
    /* 303A4 8003FBA4 983022AC */  sw         $v0, %lo(D_80063098)($at)
    /* 303A8 8003FBA8 0800E003 */  jr         $ra
    /* 303AC 8003FBAC 21100000 */   addu      $v0, $zero, $zero
endlabel Card_OnHwTimeout
