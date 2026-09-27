nonmatching Task_SetState3, 0x10

glabel Task_SetState3
    /* 1E28 80011628 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 1E2C 8001162C 1C0085AC */  sw         $a1, 0x1C($a0)
    /* 1E30 80011630 0800E003 */  jr         $ra
    /* 1E34 80011634 200080AC */   sw        $zero, 0x20($a0)
endlabel Task_SetState3
