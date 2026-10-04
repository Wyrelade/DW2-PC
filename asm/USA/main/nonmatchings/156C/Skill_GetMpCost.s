nonmatching Skill_GetMpCost, 0x24

glabel Skill_GetMpCost
    /* F680 8001EE80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F684 8001EE84 1000BFAF */  sw         $ra, 0x10($sp)
    /* F688 8001EE88 507B000C */  jal        Skill_FindById
    /* F68C 8001EE8C 00000000 */   nop
    /* F690 8001EE90 04004290 */  lbu        $v0, 0x4($v0)
    /* F694 8001EE94 1000BF8F */  lw         $ra, 0x10($sp)
    /* F698 8001EE98 00000000 */  nop
    /* F69C 8001EE9C 0800E003 */  jr         $ra
    /* F6A0 8001EEA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetMpCost
