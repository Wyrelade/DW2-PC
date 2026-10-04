nonmatching Skill_GetRank, 0x24

glabel Skill_GetRank
    /* F8C0 8001F0C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F8C4 8001F0C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* F8C8 8001F0C8 507B000C */  jal        Skill_FindById
    /* F8CC 8001F0CC 00000000 */   nop
    /* F8D0 8001F0D0 0000428C */  lw         $v0, 0x0($v0)
    /* F8D4 8001F0D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* F8D8 8001F0D8 02170200 */  srl        $v0, $v0, 28
    /* F8DC 8001F0DC 0800E003 */  jr         $ra
    /* F8E0 8001F0E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetRank
