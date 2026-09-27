nonmatching Rand_Step, 0x1C

glabel Rand_Step
    /* 140F4 800238F4 9800828F */  lw         $v0, %gp_rel(D_80050790)($gp)
    /* 140F8 800238F8 00000000 */  nop
    /* 140FC 800238FC 01004224 */  addiu      $v0, $v0, 0x1
    /* 14100 80023900 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 14104 80023904 980082AF */  sw         $v0, %gp_rel(D_80050790)($gp)
    /* 14108 80023908 0800E003 */  jr         $ra
    /* 1410C 8002390C 00000000 */   nop
endlabel Rand_Step
