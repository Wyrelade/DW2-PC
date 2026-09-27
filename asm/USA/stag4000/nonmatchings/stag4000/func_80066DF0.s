nonmatching func_80066DF0, 0x28

glabel func_80066DF0
    /* 3A90 80066DF0 0780023C */  lui        $v0, %hi(D_80072B70)
    /* 3A94 80066DF4 702B428C */  lw         $v0, %lo(D_80072B70)($v0)
    /* 3A98 80066DF8 00000000 */  nop
    /* 3A9C 80066DFC 2C00428C */  lw         $v0, 0x2C($v0)
    /* 3AA0 80066E00 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 3AA4 80066E04 460044A0 */  sb         $a0, 0x46($v0)
    /* 3AA8 80066E08 440045A0 */  sb         $a1, 0x44($v0)
    /* 3AAC 80066E0C 450046A0 */  sb         $a2, 0x45($v0)
    /* 3AB0 80066E10 0800E003 */  jr         $ra
    /* 3AB4 80066E14 240043AC */   sw        $v1, 0x24($v0)
endlabel func_80066DF0
