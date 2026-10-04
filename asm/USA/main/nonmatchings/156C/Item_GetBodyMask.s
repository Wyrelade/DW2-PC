nonmatching Item_GetBodyMask, 0x24

glabel Item_GetBodyMask
    /* E9AC 8001E1AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E9B0 8001E1B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* E9B4 8001E1B4 FD77000C */  jal        Item_FindById
    /* E9B8 8001E1B8 00000000 */   nop
    /* E9BC 8001E1BC 07004290 */  lbu        $v0, 0x7($v0)
    /* E9C0 8001E1C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* E9C4 8001E1C4 00000000 */  nop
    /* E9C8 8001E1C8 0800E003 */  jr         $ra
    /* E9CC 8001E1CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Item_GetBodyMask
