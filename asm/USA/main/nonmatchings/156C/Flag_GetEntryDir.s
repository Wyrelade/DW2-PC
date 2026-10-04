nonmatching Flag_GetEntryDir, 0x24

glabel Flag_GetEntryDir
    /* EE58 8001E658 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EE5C 8001E65C 1000BFAF */  sw         $ra, 0x10($sp)
    /* EE60 8001E660 3379000C */  jal        Flag_GetEntry
    /* EE64 8001E664 00000000 */   nop
    /* EE68 8001E668 02004284 */  lh         $v0, 0x2($v0)
    /* EE6C 8001E66C 1000BF8F */  lw         $ra, 0x10($sp)
    /* EE70 8001E670 00000000 */  nop
    /* EE74 8001E674 0800E003 */  jr         $ra
    /* EE78 8001E678 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Flag_GetEntryDir
