nonmatching func_8001CAA0, 0x24

glabel func_8001CAA0
    /* D2A0 8001CAA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D2A4 8001CAA4 1000BFAF */  sw         $ra, 0x10($sp)
    /* D2A8 8001CAA8 688E000C */  jal        Cd_GetFileEntry
    /* D2AC 8001CAAC 00000000 */   nop
    /* D2B0 8001CAB0 0400428C */  lw         $v0, 0x4($v0)
    /* D2B4 8001CAB4 1000BF8F */  lw         $ra, 0x10($sp)
    /* D2B8 8001CAB8 07004230 */  andi       $v0, $v0, 0x7
    /* D2BC 8001CABC 0800E003 */  jr         $ra
    /* D2C0 8001CAC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001CAA0
