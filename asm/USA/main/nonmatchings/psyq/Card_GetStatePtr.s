nonmatching Card_GetStatePtr, 0xC

glabel Card_GetStatePtr
    /* 2E4F4 8003DCF4 0680023C */  lui        $v0, %hi(D_80062F80)
    /* 2E4F8 8003DCF8 0800E003 */  jr         $ra
    /* 2E4FC 8003DCFC 802F4224 */   addiu     $v0, $v0, %lo(D_80062F80)
endlabel Card_GetStatePtr
