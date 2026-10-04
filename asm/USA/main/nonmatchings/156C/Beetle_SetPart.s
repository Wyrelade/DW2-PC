nonmatching Beetle_SetPart, 0x2C

glabel Beetle_SetPart
    /* 12CEC 800224EC 2800838F */  lw         $v1, %gp_rel(Save_GameStatePtr)($gp)
    /* 12CF0 800224F0 40100400 */  sll        $v0, $a0, 1
    /* 12CF4 800224F4 21106200 */  addu       $v0, $v1, $v0
    /* 12CF8 800224F8 21186400 */  addu       $v1, $v1, $a0
    /* 12CFC 800224FC 0300A010 */  beqz       $a1, .L8002250C
    /* 12D00 80022500 2C0045A4 */   sh        $a1, 0x2C($v0)
    /* 12D04 80022504 0800E003 */  jr         $ra
    /* 12D08 80022508 520066A0 */   sb        $a2, 0x52($v1)
  .L8002250C:
    /* 12D0C 8002250C 01000224 */  addiu      $v0, $zero, 0x1
    /* 12D10 80022510 0800E003 */  jr         $ra
    /* 12D14 80022514 520062A0 */   sb        $v0, 0x52($v1)
endlabel Beetle_SetPart
