nonmatching Card_IsTaskStackEmpty, 0x10

glabel Card_IsTaskStackEmpty
    /* 3030C 8003FB0C 0580023C */  lui        $v0, %hi(Card_TaskTop)
    /* 30310 8003FB10 E806428C */  lw         $v0, %lo(Card_TaskTop)($v0)
    /* 30314 8003FB14 0800E003 */  jr         $ra
    /* 30318 8003FB18 C2170200 */   srl       $v0, $v0, 31
endlabel Card_IsTaskStackEmpty
    /* 3031C 8003FB1C 00000000 */  nop
    /* 30320 8003FB20 00000000 */  nop
