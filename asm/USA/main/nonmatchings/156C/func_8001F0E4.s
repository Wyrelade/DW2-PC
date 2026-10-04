nonmatching func_8001F0E4, 0x28

glabel func_8001F0E4
    /* F8E4 8001F0E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F8E8 8001F0E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* F8EC 8001F0EC 507B000C */  jal        Skill_FindById
    /* F8F0 8001F0F0 00000000 */   nop
    /* F8F4 8001F0F4 1000428C */  lw         $v0, 0x10($v0)
    /* F8F8 8001F0F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* F8FC 8001F0FC 02120200 */  srl        $v0, $v0, 8
    /* F900 8001F100 FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* F904 8001F104 0800E003 */  jr         $ra
    /* F908 8001F108 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001F0E4
