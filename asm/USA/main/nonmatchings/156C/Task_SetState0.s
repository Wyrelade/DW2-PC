nonmatching Task_SetState0, 0x1C

glabel Task_SetState0
    /* 1DC0 800115C0 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 1DC4 800115C4 100085AC */  sw         $a1, 0x10($a0)
    /* 1DC8 800115C8 200080AC */  sw         $zero, 0x20($a0)
    /* 1DCC 800115CC 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1DD0 800115D0 180080AC */  sw         $zero, 0x18($a0)
    /* 1DD4 800115D4 0800E003 */  jr         $ra
    /* 1DD8 800115D8 140080AC */   sw        $zero, 0x14($a0)
endlabel Task_SetState0
