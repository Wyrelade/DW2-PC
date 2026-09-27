nonmatching StSetMask, 0x1C

glabel StSetMask
    /* 1EAA4 8002E2A4 0680013C */  lui        $at, %hi(D_80061B30)
    /* 1EAA8 8002E2A8 301B24AC */  sw         $a0, %lo(D_80061B30)($at)
    /* 1EAAC 8002E2AC 0680013C */  lui        $at, %hi(D_80061B0C)
    /* 1EAB0 8002E2B0 0C1B25AC */  sw         $a1, %lo(D_80061B0C)($at)
    /* 1EAB4 8002E2B4 0680013C */  lui        $at, %hi(D_80061B2C)
    /* 1EAB8 8002E2B8 0800E003 */  jr         $ra
    /* 1EABC 8002E2BC 2C1B26AC */   sw        $a2, %lo(D_80061B2C)($at)
endlabel StSetMask
    /* 1EAC0 8002E2C0 00000000 */  nop
