nonmatching func_8001E79C, 0x24

glabel func_8001E79C
    /* EF9C 8001E79C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EFA0 8001E7A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* EFA4 8001E7A4 AA79000C */  jal        Digi_FindDataById
    /* EFA8 8001E7A8 00000000 */   nop
    /* EFAC 8001E7AC 1E004284 */  lh         $v0, 0x1E($v0)
    /* EFB0 8001E7B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* EFB4 8001E7B4 00000000 */  nop
    /* EFB8 8001E7B8 0800E003 */  jr         $ra
    /* EFBC 8001E7BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E79C
