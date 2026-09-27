nonmatching func_8001E0E4, 0x24

glabel func_8001E0E4
    /* E8E4 8001E0E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E8E8 8001E0E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* E8EC 8001E0EC FD77000C */  jal        Item_FindById
    /* E8F0 8001E0F0 00000000 */   nop
    /* E8F4 8001E0F4 03004290 */  lbu        $v0, 0x3($v0)
    /* E8F8 8001E0F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* E8FC 8001E0FC 0F004230 */  andi       $v0, $v0, 0xF
    /* E900 8001E100 0800E003 */  jr         $ra
    /* E904 8001E104 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E0E4
