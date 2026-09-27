nonmatching func_8002DD20, 0x28

glabel func_8002DD20
    /* 1E520 8002DD20 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E524 8002DD24 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E528 8002DD28 00F0043C */  lui        $a0, (0xF0000003 >> 16)
    /* 1E52C 8002DD2C 03008434 */  ori        $a0, $a0, (0xF0000003 & 0xFFFF)
    /* 1E530 8002DD30 55B7000C */  jal        DeliverEvent
    /* 1E534 8002DD34 40000524 */   addiu     $a1, $zero, 0x40
    /* 1E538 8002DD38 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E53C 8002DD3C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E540 8002DD40 0800E003 */  jr         $ra
    /* 1E544 8002DD44 00000000 */   nop
endlabel func_8002DD20
    /* 1E548 8002DD48 00000000 */  nop
    /* 1E54C 8002DD4C 00000000 */  nop
    /* 1E550 8002DD50 00000000 */  nop
