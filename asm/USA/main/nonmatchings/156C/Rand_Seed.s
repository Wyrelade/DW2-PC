nonmatching Rand_Seed, 0x10

glabel Rand_Seed
    /* 140E4 800238E4 FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 140E8 800238E8 980084AF */  sw         $a0, %gp_rel(D_80050790)($gp)
    /* 140EC 800238EC 0800E003 */  jr         $ra
    /* 140F0 800238F0 00000000 */   nop
endlabel Rand_Seed
