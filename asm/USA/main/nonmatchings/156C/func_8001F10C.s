nonmatching func_8001F10C, 0x24

glabel func_8001F10C
    /* F90C 8001F10C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F910 8001F110 1000BFAF */  sw         $ra, 0x10($sp)
    /* F914 8001F114 507B000C */  jal        Skill_FindById
    /* F918 8001F118 00000000 */   nop
    /* F91C 8001F11C 1400428C */  lw         $v0, 0x14($v0)
    /* F920 8001F120 1000BF8F */  lw         $ra, 0x10($sp)
    /* F924 8001F124 FF034230 */  andi       $v0, $v0, 0x3FF
    /* F928 8001F128 0800E003 */  jr         $ra
    /* F92C 8001F12C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F10C
