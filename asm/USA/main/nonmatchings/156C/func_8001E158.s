nonmatching func_8001E158, 0x28

glabel func_8001E158
    /* E958 8001E158 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E95C 8001E15C 1000BFAF */  sw         $ra, 0x10($sp)
    /* E960 8001E160 FD77000C */  jal        Item_FindById
    /* E964 8001E164 00000000 */   nop
    /* E968 8001E168 0000428C */  lw         $v0, 0x0($v0)
    /* E96C 8001E16C 1000BF8F */  lw         $ra, 0x10($sp)
    /* E970 8001E170 02170200 */  srl        $v0, $v0, 28
    /* E974 8001E174 03004230 */  andi       $v0, $v0, 0x3
    /* E978 8001E178 0800E003 */  jr         $ra
    /* E97C 8001E17C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E158
