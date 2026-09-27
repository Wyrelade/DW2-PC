nonmatching func_800676A4, 0x2C

glabel func_800676A4
    /* 4344 800676A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4348 800676A8 0780023C */  lui        $v0, %hi(D_80072B84)
    /* 434C 800676AC 842B428C */  lw         $v0, %lo(D_80072B84)($v0)
    /* 4350 800676B0 80200400 */  sll        $a0, $a0, 2
    /* 4354 800676B4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4358 800676B8 E26E000C */  jal        Text_Close
    /* 435C 800676BC 21204400 */   addu      $a0, $v0, $a0
    /* 4360 800676C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4364 800676C4 00000000 */  nop
    /* 4368 800676C8 0800E003 */  jr         $ra
    /* 436C 800676CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800676A4
