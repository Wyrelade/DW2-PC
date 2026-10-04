nonmatching Digi_GetSpecialty, 0x28

glabel Digi_GetSpecialty
    /* E180 8001D980 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E184 8001D984 1000BFAF */  sw         $ra, 0x10($sp)
    /* E188 8001D988 3176000C */  jal        Digi_FindBaseData
    /* E18C 8001D98C 00000000 */   nop
    /* E190 8001D990 04004294 */  lhu        $v0, 0x4($v0)
    /* E194 8001D994 1000BF8F */  lw         $ra, 0x10($sp)
    /* E198 8001D998 02120200 */  srl        $v0, $v0, 8
    /* E19C 8001D99C 0F004230 */  andi       $v0, $v0, 0xF
    /* E1A0 8001D9A0 0800E003 */  jr         $ra
    /* E1A4 8001D9A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetSpecialty
