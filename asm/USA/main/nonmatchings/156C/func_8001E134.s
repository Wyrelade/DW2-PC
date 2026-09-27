nonmatching func_8001E134, 0x24

glabel func_8001E134
    /* E934 8001E134 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E938 8001E138 1000BFAF */  sw         $ra, 0x10($sp)
    /* E93C 8001E13C FD77000C */  jal        Item_FindById
    /* E940 8001E140 00000000 */   nop
    /* E944 8001E144 0000428C */  lw         $v0, 0x0($v0)
    /* E948 8001E148 1000BF8F */  lw         $ra, 0x10($sp)
    /* E94C 8001E14C 82170200 */  srl        $v0, $v0, 30
    /* E950 8001E150 0800E003 */  jr         $ra
    /* E954 8001E154 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E134
