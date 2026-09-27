nonmatching func_8001E8D0, 0x24

glabel func_8001E8D0
    /* F0D0 8001E8D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F0D4 8001E8D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* F0D8 8001E8D8 AA79000C */  jal        Digi_FindDataById
    /* F0DC 8001E8DC 00000000 */   nop
    /* F0E0 8001E8E0 0400428C */  lw         $v0, 0x4($v0)
    /* F0E4 8001E8E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* F0E8 8001E8E8 01004230 */  andi       $v0, $v0, 0x1
    /* F0EC 8001E8EC 0800E003 */  jr         $ra
    /* F0F0 8001E8F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E8D0
