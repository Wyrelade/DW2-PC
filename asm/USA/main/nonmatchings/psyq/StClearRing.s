nonmatching StClearRing, 0x60

glabel StClearRing
    /* 1E694 8002DE94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E698 8002DE98 0680053C */  lui        $a1, %hi(D_80061B3C)
    /* 1E69C 8002DE9C 3C1BA58C */  lw         $a1, %lo(D_80061B3C)($a1)
    /* 1E6A0 8002DEA0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E6A4 8002DEA4 0680013C */  lui        $at, %hi(D_80061B24)
    /* 1E6A8 8002DEA8 241B20AC */  sw         $zero, %lo(D_80061B24)($at)
    /* 1E6AC 8002DEAC 0680013C */  lui        $at, %hi(D_80061B20)
    /* 1E6B0 8002DEB0 201B20AC */  sw         $zero, %lo(D_80061B20)($at)
    /* 1E6B4 8002DEB4 0680013C */  lui        $at, %hi(D_80061B1C)
    /* 1E6B8 8002DEB8 1C1B20AC */  sw         $zero, %lo(D_80061B1C)($at)
    /* 1E6BC 8002DEBC 0680013C */  lui        $at, %hi(D_80061B14)
    /* 1E6C0 8002DEC0 141B20AC */  sw         $zero, %lo(D_80061B14)($at)
    /* 1E6C4 8002DEC4 69B8000C */  jal        Cd_ClearStreamSlots
    /* 1E6C8 8002DEC8 21200000 */   addu      $a0, $zero, $zero
    /* 1E6CC 8002DECC 0680013C */  lui        $at, %hi(StCdIntrFlag)
    /* 1E6D0 8002DED0 041B20AC */  sw         $zero, %lo(StCdIntrFlag)($at)
    /* 1E6D4 8002DED4 0680013C */  lui        $at, %hi(D_80061AFC)
    /* 1E6D8 8002DED8 FC1A20A4 */  sh         $zero, %lo(D_80061AFC)($at)
    /* 1E6DC 8002DEDC 0680013C */  lui        $at, %hi(D_80061AF8)
    /* 1E6E0 8002DEE0 F81A20AC */  sw         $zero, %lo(D_80061AF8)($at)
    /* 1E6E4 8002DEE4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E6E8 8002DEE8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E6EC 8002DEEC 0800E003 */  jr         $ra
    /* 1E6F0 8002DEF0 00000000 */   nop
endlabel StClearRing
