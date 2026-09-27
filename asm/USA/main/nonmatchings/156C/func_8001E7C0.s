nonmatching func_8001E7C0, 0x24

glabel func_8001E7C0
    /* EFC0 8001E7C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EFC4 8001E7C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* EFC8 8001E7C8 AA79000C */  jal        Digi_FindDataById
    /* EFCC 8001E7CC 00000000 */   nop
    /* EFD0 8001E7D0 20004284 */  lh         $v0, 0x20($v0)
    /* EFD4 8001E7D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* EFD8 8001E7D8 00000000 */  nop
    /* EFDC 8001E7DC 0800E003 */  jr         $ra
    /* EFE0 8001E7E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E7C0
