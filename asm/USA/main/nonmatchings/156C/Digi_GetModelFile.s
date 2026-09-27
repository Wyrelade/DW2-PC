nonmatching Digi_GetModelFile, 0x24

glabel Digi_GetModelFile
    /* EF04 8001E704 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EF08 8001E708 1000BFAF */  sw         $ra, 0x10($sp)
    /* EF0C 8001E70C AA79000C */  jal        Digi_FindDataById
    /* EF10 8001E710 00000000 */   nop
    /* EF14 8001E714 06004284 */  lh         $v0, 0x6($v0)
    /* EF18 8001E718 1000BF8F */  lw         $ra, 0x10($sp)
    /* EF1C 8001E71C 00000000 */  nop
    /* EF20 8001E720 0800E003 */  jr         $ra
    /* EF24 8001E724 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetModelFile
