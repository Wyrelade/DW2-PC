nonmatching Card_Stop, 0x28

glabel Card_Stop
    /* 2DDDC 8003D5DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DDE0 8003D5E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2DDE4 8003D5E4 7DF6000C */  jal        StopCARD
    /* 2DDE8 8003D5E8 00000000 */   nop
    /* 2DDEC 8003D5EC 09F7000C */  jal        func_8003DC24
    /* 2DDF0 8003D5F0 00000000 */   nop
    /* 2DDF4 8003D5F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DDF8 8003D5F8 21100000 */  addu       $v0, $zero, $zero
    /* 2DDFC 8003D5FC 0800E003 */  jr         $ra
    /* 2DE00 8003D600 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Card_Stop
