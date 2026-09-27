nonmatching func_80039B18, 0x34

glabel func_80039B18
    /* 2A318 80039B18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A31C 80039B1C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A320 80039B20 2138C000 */  addu       $a3, $a2, $zero
    /* 2A324 80039B24 002C0500 */  sll        $a1, $a1, 16
    /* 2A328 80039B28 0480063C */  lui        $a2, %hi(Snd_VabFixedAddrAlloc)
    /* 2A32C 80039B2C 4C9BC624 */  addiu      $a2, $a2, %lo(Snd_VabFixedAddrAlloc)
    /* 2A330 80039B30 D5E6000C */  jal        _SsVabOpenHeadWithMode
    /* 2A334 80039B34 032C0500 */   sra       $a1, $a1, 16
    /* 2A338 80039B38 00140200 */  sll        $v0, $v0, 16
    /* 2A33C 80039B3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A340 80039B40 03140200 */  sra        $v0, $v0, 16
    /* 2A344 80039B44 0800E003 */  jr         $ra
    /* 2A348 80039B48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039B18
