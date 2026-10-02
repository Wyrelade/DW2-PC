nonmatching CdGetSector, 0x20

glabel CdGetSector
    /* 21114 80030914 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21118 80030918 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2111C 8003091C 4DC2000C */  jal        CD_getsector
    /* 21120 80030920 00000000 */   nop
    /* 21124 80030924 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21128 80030928 0100422C */  sltiu      $v0, $v0, 0x1
    /* 2112C 8003092C 0800E003 */  jr         $ra
    /* 21130 80030930 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel CdGetSector
