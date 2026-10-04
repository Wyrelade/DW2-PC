nonmatching func_8001F020, 0x24

glabel func_8001F020
    /* F820 8001F020 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F824 8001F024 1000BFAF */  sw         $ra, 0x10($sp)
    /* F828 8001F028 507B000C */  jal        Skill_FindById
    /* F82C 8001F02C 00000000 */   nop
    /* F830 8001F030 10004290 */  lbu        $v0, 0x10($v0)
    /* F834 8001F034 1000BF8F */  lw         $ra, 0x10($sp)
    /* F838 8001F038 00000000 */  nop
    /* F83C 8001F03C 0800E003 */  jr         $ra
    /* F840 8001F040 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F020
