nonmatching Skill_GetBuffFlags, 0x28

glabel Skill_GetBuffFlags
    /* F930 8001F130 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F934 8001F134 1000BFAF */  sw         $ra, 0x10($sp)
    /* F938 8001F138 507B000C */  jal        Skill_FindById
    /* F93C 8001F13C 00000000 */   nop
    /* F940 8001F140 1400428C */  lw         $v0, 0x14($v0)
    /* F944 8001F144 1000BF8F */  lw         $ra, 0x10($sp)
    /* F948 8001F148 82120200 */  srl        $v0, $v0, 10
    /* F94C 8001F14C FF1F4230 */  andi       $v0, $v0, 0x1FFF
    /* F950 8001F150 0800E003 */  jr         $ra
    /* F954 8001F154 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Skill_GetBuffFlags
