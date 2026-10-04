nonmatching Skill_GetPower, 0x24

glabel Skill_GetPower
    /* F764 8001EF64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F768 8001EF68 1000BFAF */  sw         $ra, 0x10($sp)
    /* F76C 8001EF6C 507B000C */  jal        Skill_FindById
    /* F770 8001EF70 00000000 */   nop
    /* F774 8001EF74 08004284 */  lh         $v0, 0x8($v0)
    /* F778 8001EF78 1000BF8F */  lw         $ra, 0x10($sp)
    /* F77C 8001EF7C 00000000 */  nop
    /* F780 8001EF80 0800E003 */  jr         $ra
    /* F784 8001EF84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetPower
