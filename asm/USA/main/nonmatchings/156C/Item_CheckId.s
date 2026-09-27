nonmatching Item_CheckId, 0x2C

glabel Item_CheckId
    /* E908 8001E108 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E90C 8001E10C 1000BFAF */  sw         $ra, 0x10($sp)
    /* E910 8001E110 FD77000C */  jal        func_8001DFF4
    /* E914 8001E114 00000000 */   nop
    /* E918 8001E118 02004014 */  bnez       $v0, .L8001E124
    /* E91C 8001E11C 21180000 */   addu      $v1, $zero, $zero
    /* E920 8001E120 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8001E124:
    /* E924 8001E124 1000BF8F */  lw         $ra, 0x10($sp)
    /* E928 8001E128 21106000 */  addu       $v0, $v1, $zero
    /* E92C 8001E12C 0800E003 */  jr         $ra
    /* E930 8001E130 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Item_CheckId
