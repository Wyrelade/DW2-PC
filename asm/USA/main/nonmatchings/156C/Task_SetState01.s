nonmatching Task_SetState01, 0x20

glabel Task_SetState01
    /* 1DF4 800115F4 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 1DF8 800115F8 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 1DFC 800115FC 100085AC */  sw         $a1, 0x10($a0)
    /* 1E00 80011600 140086AC */  sw         $a2, 0x14($a0)
    /* 1E04 80011604 200080AC */  sw         $zero, 0x20($a0)
    /* 1E08 80011608 1C0080AC */  sw         $zero, 0x1C($a0)
    /* 1E0C 8001160C 0800E003 */  jr         $ra
    /* 1E10 80011610 180080AC */   sw        $zero, 0x18($a0)
endlabel Task_SetState01
