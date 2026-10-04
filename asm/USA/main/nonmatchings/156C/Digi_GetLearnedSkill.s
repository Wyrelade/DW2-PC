nonmatching Digi_GetLearnedSkill, 0x24

glabel Digi_GetLearnedSkill
    /* E1A8 8001D9A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E1AC 8001D9AC 1000BFAF */  sw         $ra, 0x10($sp)
    /* E1B0 8001D9B0 3176000C */  jal        Digi_FindBaseData
    /* E1B4 8001D9B4 00000000 */   nop
    /* E1B8 8001D9B8 02004290 */  lbu        $v0, 0x2($v0)
    /* E1BC 8001D9BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* E1C0 8001D9C0 00000000 */  nop
    /* E1C4 8001D9C4 0800E003 */  jr         $ra
    /* E1C8 8001D9C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetLearnedSkill
