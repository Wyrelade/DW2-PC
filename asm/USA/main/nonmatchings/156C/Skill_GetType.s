nonmatching Skill_GetType, 0x28

glabel Skill_GetType
    /* F634 8001EE34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F638 8001EE38 1000BFAF */  sw         $ra, 0x10($sp)
    /* F63C 8001EE3C 507B000C */  jal        Skill_FindById
    /* F640 8001EE40 00000000 */   nop
    /* F644 8001EE44 0000428C */  lw         $v0, 0x0($v0)
    /* F648 8001EE48 1000BF8F */  lw         $ra, 0x10($sp)
    /* F64C 8001EE4C 82140200 */  srl        $v0, $v0, 18
    /* F650 8001EE50 03004230 */  andi       $v0, $v0, 0x3
    /* F654 8001EE54 0800E003 */  jr         $ra
    /* F658 8001EE58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetType
