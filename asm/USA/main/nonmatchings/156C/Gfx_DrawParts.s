nonmatching Gfx_DrawParts, 0x20

glabel Gfx_DrawParts
    /* E084 8001D884 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E088 8001D888 1000BFAF */  sw         $ra, 0x10($sp)
    /* E08C 8001D88C AD75000C */  jal        Gfx_DrawPartsEx
    /* E090 8001D890 01000524 */   addiu     $a1, $zero, 0x1
    /* E094 8001D894 1000BF8F */  lw         $ra, 0x10($sp)
    /* E098 8001D898 00000000 */  nop
    /* E09C 8001D89C 0800E003 */  jr         $ra
    /* E0A0 8001D8A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Gfx_DrawParts
