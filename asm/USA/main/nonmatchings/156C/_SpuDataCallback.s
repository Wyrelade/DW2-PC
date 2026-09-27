nonmatching _SpuDataCallback, 0x24

glabel _SpuDataCallback
    /* 2B514 8003AD14 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B518 8003AD18 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2B51C 8003AD1C 21288000 */  addu       $a1, $a0, $zero
    /* 2B520 8003AD20 4DC3000C */  jal        DMACallback
    /* 2B524 8003AD24 04000424 */   addiu     $a0, $zero, 0x4
    /* 2B528 8003AD28 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2B52C 8003AD2C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2B530 8003AD30 0800E003 */  jr         $ra
    /* 2B534 8003AD34 00000000 */   nop
endlabel _SpuDataCallback
    /* 2B538 8003AD38 00000000 */  nop
    /* 2B53C 8003AD3C 00000000 */  nop
    /* 2B540 8003AD40 00000000 */  nop
