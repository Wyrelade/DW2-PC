nonmatching _addque, 0x24

glabel _addque
    /* 199D8 800291D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 199DC 800291DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 199E0 800291E0 2138C000 */  addu       $a3, $a2, $zero
    /* 199E4 800291E4 7FA4000C */  jal        _addque2
    /* 199E8 800291E8 21300000 */   addu      $a2, $zero, $zero
    /* 199EC 800291EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 199F0 800291F0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 199F4 800291F4 0800E003 */  jr         $ra
    /* 199F8 800291F8 00000000 */   nop
endlabel _addque
