nonmatching Card_ClearTaskStack, 0x10

glabel Card_ClearTaskStack
    /* 30214 8003FA14 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 30218 8003FA18 0580013C */  lui        $at, %hi(Card_TaskTop)
    /* 3021C 8003FA1C 0800E003 */  jr         $ra
    /* 30220 8003FA20 E80622AC */   sw        $v0, %lo(Card_TaskTop)($at)
endlabel Card_ClearTaskStack
