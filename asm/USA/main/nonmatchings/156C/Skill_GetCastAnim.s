nonmatching Skill_GetCastAnim, 0x24

glabel Skill_GetCastAnim
    /* F610 8001EE10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F614 8001EE14 1000BFAF */  sw         $ra, 0x10($sp)
    /* F618 8001EE18 507B000C */  jal        Skill_FindById
    /* F61C 8001EE1C 00000000 */   nop
    /* F620 8001EE20 02004294 */  lhu        $v0, 0x2($v0)
    /* F624 8001EE24 1000BF8F */  lw         $ra, 0x10($sp)
    /* F628 8001EE28 03004230 */  andi       $v0, $v0, 0x3
    /* F62C 8001EE2C 0800E003 */  jr         $ra
    /* F630 8001EE30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetCastAnim
