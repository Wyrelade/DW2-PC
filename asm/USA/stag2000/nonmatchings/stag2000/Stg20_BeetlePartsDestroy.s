nonmatching Stg20_BeetlePartsDestroy, 0x34

glabel Stg20_BeetlePartsDestroy
    /* B3C0 8006E720 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B3C4 8006E724 1000B0AF */  sw         $s0, 0x10($sp)
    /* B3C8 8006E728 21808000 */  addu       $s0, $a0, $zero
    /* B3CC 8006E72C 1400BFAF */  sw         $ra, 0x14($sp)
    /* B3D0 8006E730 2C00048E */  lw         $a0, 0x2C($s0)
    /* B3D4 8006E734 2C70000C */  jal        Text_CloseArray
    /* B3D8 8006E738 12000524 */   addiu     $a1, $zero, 0x12
    /* B3DC 8006E73C 5C44000C */  jal        Task_DefaultDestroy
    /* B3E0 8006E740 21200002 */   addu      $a0, $s0, $zero
    /* B3E4 8006E744 1400BF8F */  lw         $ra, 0x14($sp)
    /* B3E8 8006E748 1000B08F */  lw         $s0, 0x10($sp)
    /* B3EC 8006E74C 0800E003 */  jr         $ra
    /* B3F0 8006E750 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_BeetlePartsDestroy
