nonmatching Beetle_GetPart, 0x34

glabel Beetle_GetPart
    /* 12D18 80022518 2800858F */  lw         $a1, %gp_rel(Save_GameStatePtr)($gp)
    /* 12D1C 8002251C 00000000 */  nop
    /* 12D20 80022520 2110A400 */  addu       $v0, $a1, $a0
    /* 12D24 80022524 52004390 */  lbu        $v1, 0x52($v0)
    /* 12D28 80022528 01000224 */  addiu      $v0, $zero, 0x1
    /* 12D2C 8002252C 05006210 */  beq        $v1, $v0, .L80022544
    /* 12D30 80022530 04104400 */   sllv      $v0, $a0, $v0
    /* 12D34 80022534 2110A200 */  addu       $v0, $a1, $v0
    /* 12D38 80022538 2C004294 */  lhu        $v0, 0x2C($v0)
    /* 12D3C 8002253C 0800E003 */  jr         $ra
    /* 12D40 80022540 00000000 */   nop
  .L80022544:
    /* 12D44 80022544 0800E003 */  jr         $ra
    /* 12D48 80022548 FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel Beetle_GetPart
