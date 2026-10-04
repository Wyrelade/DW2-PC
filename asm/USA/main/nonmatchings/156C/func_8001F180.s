nonmatching func_8001F180, 0x28

glabel func_8001F180
    /* F980 8001F180 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F984 8001F184 1000BFAF */  sw         $ra, 0x10($sp)
    /* F988 8001F188 507B000C */  jal        Skill_FindById
    /* F98C 8001F18C 00000000 */   nop
    /* F990 8001F190 1C00428C */  lw         $v0, 0x1C($v0)
    /* F994 8001F194 1000BF8F */  lw         $ra, 0x10($sp)
    /* F998 8001F198 C2150200 */  srl        $v0, $v0, 23
    /* F99C 8001F19C FF004230 */  andi       $v0, $v0, 0xFF
    /* F9A0 8001F1A0 0800E003 */  jr         $ra
    /* F9A4 8001F1A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F180
