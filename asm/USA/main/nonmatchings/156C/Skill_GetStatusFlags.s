nonmatching Skill_GetStatusFlags, 0x2C

glabel Skill_GetStatusFlags
    /* F868 8001F068 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F86C 8001F06C 1000BFAF */  sw         $ra, 0x10($sp)
    /* F870 8001F070 507B000C */  jal        Skill_FindById
    /* F874 8001F074 00000000 */   nop
    /* F878 8001F078 FF03033C */  lui        $v1, (0x3FFFFFF >> 16)
    /* F87C 8001F07C FFFF6334 */  ori        $v1, $v1, (0x3FFFFFF & 0xFFFF)
    /* F880 8001F080 1800428C */  lw         $v0, 0x18($v0)
    /* F884 8001F084 1000BF8F */  lw         $ra, 0x10($sp)
    /* F888 8001F088 24104300 */  and        $v0, $v0, $v1
    /* F88C 8001F08C 0800E003 */  jr         $ra
    /* F890 8001F090 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetStatusFlags
