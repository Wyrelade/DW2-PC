nonmatching func_80039AE4, 0x34

glabel func_80039AE4
    /* 2A2E4 80039AE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A2E8 80039AE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A2EC 80039AEC 2138C000 */  addu       $a3, $a2, $zero
    /* 2A2F0 80039AF0 002C0500 */  sll        $a1, $a1, 16
    /* 2A2F4 80039AF4 0480063C */  lui        $a2, %hi(Snd_VabFixedAddrAlloc)
    /* 2A2F8 80039AF8 4C9BC624 */  addiu      $a2, $a2, %lo(Snd_VabFixedAddrAlloc)
    /* 2A2FC 80039AFC D5E6000C */  jal        _SsVabOpenHeadWithMode
    /* 2A300 80039B00 032C0500 */   sra       $a1, $a1, 16
    /* 2A304 80039B04 00140200 */  sll        $v0, $v0, 16
    /* 2A308 80039B08 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A30C 80039B0C 03140200 */  sra        $v0, $v0, 16
    /* 2A310 80039B10 0800E003 */  jr         $ra
    /* 2A314 80039B14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039AE4
