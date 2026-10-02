nonmatching func_8003DA48, 0x2C

glabel func_8003DA48
    /* 2E248 8003DA48 0A006F94 */  lhu        $t7, 0xA($v1)
    /* 2E24C 8003DA4C 0000083C */  lui        $t0, (0x0 >> 16)
    /* 2E250 8003DA50 25C0E201 */  or         $t8, $t7, $v0
    /* 2E254 8003DA54 12001937 */  ori        $t9, $t8, 0x12
    /* 2E258 8003DA58 0A0079A4 */  sh         $t9, 0xA($v1)
    /* 2E25C 8003DA5C 28000824 */  addiu      $t0, $zero, 0x28
  .L8003DA60:
    /* 2E260 8003DA60 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 2E264 8003DA64 FEFF0015 */  bnez       $t0, .L8003DA60
    /* 2E268 8003DA68 00000000 */   nop
    /* 2E26C 8003DA6C 0800E003 */  jr         $ra
    /* 2E270 8003DA70 00000000 */   nop
endlabel func_8003DA48
