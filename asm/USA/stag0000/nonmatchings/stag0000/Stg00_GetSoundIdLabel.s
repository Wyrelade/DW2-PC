nonmatching Stg00_GetSoundIdLabel, 0x20

glabel Stg00_GetSoundIdLabel
    /* 4E10 80068170 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E14 80068174 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4E18 80068178 21A0010C */  jal        Stg00_GetSoundLabel
    /* 4E1C 8006817C 0100A524 */   addiu     $a1, $a1, 0x1
    /* 4E20 80068180 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E24 80068184 00000000 */  nop
    /* 4E28 80068188 0800E003 */  jr         $ra
    /* 4E2C 8006818C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg00_GetSoundIdLabel
