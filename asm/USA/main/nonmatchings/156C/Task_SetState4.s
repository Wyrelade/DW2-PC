nonmatching Task_SetState4, 0xC

glabel Task_SetState4
    /* 1E38 80011638 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 1E3C 8001163C 0800E003 */  jr         $ra
    /* 1E40 80011640 200085AC */   sw        $a1, 0x20($a0)
endlabel Task_SetState4
