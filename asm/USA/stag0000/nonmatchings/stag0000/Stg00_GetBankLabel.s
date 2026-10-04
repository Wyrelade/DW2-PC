nonmatching Stg00_GetBankLabel, 0x20

glabel Stg00_GetBankLabel
    /* 4DF0 80068150 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4DF4 80068154 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4DF8 80068158 21A0010C */  jal        Stg00_GetSoundLabel
    /* 4DFC 8006815C 21280000 */   addu      $a1, $zero, $zero
    /* 4E00 80068160 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E04 80068164 00000000 */  nop
    /* 4E08 80068168 0800E003 */  jr         $ra
    /* 4E0C 8006816C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg00_GetBankLabel
