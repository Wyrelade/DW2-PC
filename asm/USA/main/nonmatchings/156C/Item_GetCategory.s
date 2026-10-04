nonmatching Item_GetCategory, 0x24

glabel Item_GetCategory
    /* E8C0 8001E0C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E8C4 8001E0C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* E8C8 8001E0C8 FD77000C */  jal        Item_FindById
    /* E8CC 8001E0CC 00000000 */   nop
    /* E8D0 8001E0D0 02004290 */  lbu        $v0, 0x2($v0)
    /* E8D4 8001E0D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* E8D8 8001E0D8 00000000 */  nop
    /* E8DC 8001E0DC 0800E003 */  jr         $ra
    /* E8E0 8001E0E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Item_GetCategory
