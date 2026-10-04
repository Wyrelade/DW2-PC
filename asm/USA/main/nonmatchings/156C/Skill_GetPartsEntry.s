nonmatching Skill_GetPartsEntry, 0x24

glabel Skill_GetPartsEntry
    /* F65C 8001EE5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F660 8001EE60 1000BFAF */  sw         $ra, 0x10($sp)
    /* F664 8001EE64 507B000C */  jal        Skill_FindById
    /* F668 8001EE68 00000000 */   nop
    /* F66C 8001EE6C 0C00428C */  lw         $v0, 0xC($v0)
    /* F670 8001EE70 1000BF8F */  lw         $ra, 0x10($sp)
    /* F674 8001EE74 00000000 */  nop
    /* F678 8001EE78 0800E003 */  jr         $ra
    /* F67C 8001EE7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetPartsEntry
