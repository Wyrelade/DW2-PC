nonmatching func_8001F044, 0x24

glabel func_8001F044
    /* F844 8001F044 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F848 8001F048 1000BFAF */  sw         $ra, 0x10($sp)
    /* F84C 8001F04C 507B000C */  jal        Skill_FindById
    /* F850 8001F050 00000000 */   nop
    /* F854 8001F054 2000428C */  lw         $v0, 0x20($v0)
    /* F858 8001F058 1000BF8F */  lw         $ra, 0x10($sp)
    /* F85C 8001F05C 0F004230 */  andi       $v0, $v0, 0xF
    /* F860 8001F060 0800E003 */  jr         $ra
    /* F864 8001F064 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F044
