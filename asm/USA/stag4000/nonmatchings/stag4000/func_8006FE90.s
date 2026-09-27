nonmatching func_8006FE90, 0x44

glabel func_8006FE90
    /* CB30 8006FE90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* CB34 8006FE94 1400BFAF */  sw         $ra, 0x14($sp)
    /* CB38 8006FE98 1000B0AF */  sw         $s0, 0x10($sp)
    /* CB3C 8006FE9C 2C00908C */  lw         $s0, 0x2C($a0)
    /* CB40 8006FEA0 4689000C */  jal        func_80022518
    /* CB44 8006FEA4 12000424 */   addiu     $a0, $zero, 0x12
    /* CB48 8006FEA8 0400401C */  bgtz       $v0, .L8006FEBC
    /* CB4C 8006FEAC 0780023C */   lui       $v0, %hi(D_80072B60)
    /* CB50 8006FEB0 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* CB54 8006FEB4 00000000 */  nop
    /* CB58 8006FEB8 7E0040A4 */  sh         $zero, 0x7E($v0)
  .L8006FEBC:
    /* CB5C 8006FEBC 15BF010C */  jal        func_8006FC54
    /* CB60 8006FEC0 21200002 */   addu      $a0, $s0, $zero
    /* CB64 8006FEC4 1400BF8F */  lw         $ra, 0x14($sp)
    /* CB68 8006FEC8 1000B08F */  lw         $s0, 0x10($sp)
    /* CB6C 8006FECC 0800E003 */  jr         $ra
    /* CB70 8006FED0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006FE90
