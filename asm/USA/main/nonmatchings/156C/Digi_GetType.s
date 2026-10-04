nonmatching Digi_GetType, 0x24

glabel Digi_GetType
    /* E134 8001D934 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E138 8001D938 1000BFAF */  sw         $ra, 0x10($sp)
    /* E13C 8001D93C 3176000C */  jal        Digi_FindBaseData
    /* E140 8001D940 00000000 */   nop
    /* E144 8001D944 04004290 */  lbu        $v0, 0x4($v0)
    /* E148 8001D948 1000BF8F */  lw         $ra, 0x10($sp)
    /* E14C 8001D94C 0F004230 */  andi       $v0, $v0, 0xF
    /* E150 8001D950 0800E003 */  jr         $ra
    /* E154 8001D954 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetType
