nonmatching CdDataCallback, 0x24

glabel CdDataCallback
    /* 21234 80030A34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21238 80030A38 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2123C 80030A3C 21288000 */  addu       $a1, $a0, $zero
    /* 21240 80030A40 4DC3000C */  jal        DMACallback
    /* 21244 80030A44 03000424 */   addiu     $a0, $zero, 0x3
    /* 21248 80030A48 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2124C 80030A4C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 21250 80030A50 0800E003 */  jr         $ra
    /* 21254 80030A54 00000000 */   nop
endlabel CdDataCallback
    /* 21258 80030A58 00000000 */  nop
    /* 2125C 80030A5C 00000000 */  nop
    /* 21260 80030A60 00000000 */  nop
