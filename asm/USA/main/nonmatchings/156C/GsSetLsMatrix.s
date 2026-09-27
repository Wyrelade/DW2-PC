nonmatching GsSetLsMatrix, 0x2C

glabel GsSetLsMatrix
    /* 1BC94 8002B494 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BC98 8002B498 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1BC9C 8002B49C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1BCA0 8002B4A0 79B5000C */  jal        SetRotMatrix
    /* 1BCA4 8002B4A4 21808000 */   addu      $s0, $a0, $zero
    /* 1BCA8 8002B4A8 91B5000C */  jal        SetTransMatrix
    /* 1BCAC 8002B4AC 21200002 */   addu      $a0, $s0, $zero
    /* 1BCB0 8002B4B0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1BCB4 8002B4B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BCB8 8002B4B8 0800E003 */  jr         $ra
    /* 1BCBC 8002B4BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GsSetLsMatrix
    /* 1BCC0 8002B4C0 00000000 */  nop
