nonmatching func_8001F158, 0x28

glabel func_8001F158
    /* F958 8001F158 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F95C 8001F15C 1000BFAF */  sw         $ra, 0x10($sp)
    /* F960 8001F160 507B000C */  jal        Skill_FindById
    /* F964 8001F164 00000000 */   nop
    /* F968 8001F168 1C00428C */  lw         $v0, 0x1C($v0)
    /* F96C 8001F16C 1000BF8F */  lw         $ra, 0x10($sp)
    /* F970 8001F170 82140200 */  srl        $v0, $v0, 18
    /* F974 8001F174 1F004230 */  andi       $v0, $v0, 0x1F
    /* F978 8001F178 0800E003 */  jr         $ra
    /* F97C 8001F17C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F158
