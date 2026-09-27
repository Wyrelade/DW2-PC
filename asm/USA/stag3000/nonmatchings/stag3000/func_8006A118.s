nonmatching func_8006A118, 0x28

glabel func_8006A118
    /* 6DB8 8006A118 0680023C */  lui        $v0, %hi(D_8005D5A0)
    /* 6DBC 8006A11C A0D54324 */  addiu      $v1, $v0, %lo(D_8005D5A0)
    /* 6DC0 8006A120 3D106290 */  lbu        $v0, 0x103D($v1)
    /* 6DC4 8006A124 00000000 */  nop
    /* 6DC8 8006A128 03004014 */  bnez       $v0, .L8006A138
    /* 6DCC 8006A12C FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 6DD0 8006A130 0800E003 */  jr         $ra
    /* 6DD4 8006A134 05000224 */   addiu     $v0, $zero, 0x5
  .L8006A138:
    /* 6DD8 8006A138 0800E003 */  jr         $ra
    /* 6DDC 8006A13C 00000000 */   nop
endlabel func_8006A118
