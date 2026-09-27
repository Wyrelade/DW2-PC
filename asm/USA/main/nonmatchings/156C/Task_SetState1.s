nonmatching Task_SetState1, 0x18

glabel Task_SetState1
    /* 1DDC 800115DC FF00A530 */  andi       $a1, $a1, 0xFF
    /* 1DE0 800115E0 140085AC */  sw         $a1, 0x14($a0)
    /* 1DE4 800115E4 200080AC */  sw         $zero, 0x20($a0)
    /* 1DE8 800115E8 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1DEC 800115EC 0800E003 */  jr         $ra
    /* 1DF0 800115F0 180080AC */   sw        $zero, 0x18($a0)
endlabel Task_SetState1
