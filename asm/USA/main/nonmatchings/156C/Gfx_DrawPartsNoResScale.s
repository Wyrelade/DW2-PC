nonmatching Gfx_DrawPartsNoResScale, 0x20

glabel Gfx_DrawPartsNoResScale
    /* E0A4 8001D8A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E0A8 8001D8A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* E0AC 8001D8AC AD75000C */  jal        Gfx_DrawPartsEx
    /* E0B0 8001D8B0 21280000 */   addu      $a1, $zero, $zero
    /* E0B4 8001D8B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* E0B8 8001D8B8 00000000 */  nop
    /* E0BC 8001D8BC 0800E003 */  jr         $ra
    /* E0C0 8001D8C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Gfx_DrawPartsNoResScale
