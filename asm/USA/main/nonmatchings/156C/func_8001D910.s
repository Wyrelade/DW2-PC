nonmatching func_8001D910, 0x24

glabel func_8001D910
    /* E110 8001D910 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E114 8001D914 1000BFAF */  sw         $ra, 0x10($sp)
    /* E118 8001D918 3176000C */  jal        Digi_FindBaseData
    /* E11C 8001D91C 00000000 */   nop
    /* E120 8001D920 03004290 */  lbu        $v0, 0x3($v0)
    /* E124 8001D924 1000BF8F */  lw         $ra, 0x10($sp)
    /* E128 8001D928 00000000 */  nop
    /* E12C 8001D92C 0800E003 */  jr         $ra
    /* E130 8001D930 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D910
