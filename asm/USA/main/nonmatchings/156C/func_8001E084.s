nonmatching func_8001E084, 0x3C

glabel func_8001E084
    /* E884 8001E084 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E888 8001E088 1000B0AF */  sw         $s0, 0x10($sp)
    /* E88C 8001E08C 21808000 */  addu       $s0, $a0, $zero
    /* E890 8001E090 1400BFAF */  sw         $ra, 0x14($sp)
    /* E894 8001E094 828E000C */  jal        Cd_GetFileOrNull
    /* E898 8001E098 5E040424 */   addiu     $a0, $zero, 0x45E
    /* E89C 8001E09C 21200002 */  addu       $a0, $s0, $zero
    /* E8A0 8001E0A0 FD77000C */  jal        Item_FindById
    /* E8A4 8001E0A4 21804000 */   addu      $s0, $v0, $zero
    /* E8A8 8001E0A8 0C00428C */  lw         $v0, 0xC($v0)
    /* E8AC 8001E0AC 1400BF8F */  lw         $ra, 0x14($sp)
    /* E8B0 8001E0B0 21105000 */  addu       $v0, $v0, $s0
    /* E8B4 8001E0B4 1000B08F */  lw         $s0, 0x10($sp)
    /* E8B8 8001E0B8 0800E003 */  jr         $ra
    /* E8BC 8001E0BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E084
