nonmatching Beetle_SetPartBroken, 0x2C

glabel Beetle_SetPartBroken
    /* 12D4C 8002254C 21300000 */  addu       $a2, $zero, $zero
    /* 12D50 80022550 2800838F */  lw         $v1, %gp_rel(D_80050720)($gp)
    /* 12D54 80022554 40100400 */  sll        $v0, $a0, 1
    /* 12D58 80022558 21106200 */  addu       $v0, $v1, $v0
    /* 12D5C 8002255C 2C004294 */  lhu        $v0, 0x2C($v0)
    /* 12D60 80022560 00000000 */  nop
    /* 12D64 80022564 02004010 */  beqz       $v0, .L80022570
    /* 12D68 80022568 21186400 */   addu      $v1, $v1, $a0
    /* 12D6C 8002256C 2130A000 */  addu       $a2, $a1, $zero
  .L80022570:
    /* 12D70 80022570 0800E003 */  jr         $ra
    /* 12D74 80022574 520066A0 */   sb        $a2, 0x52($v1)
endlabel Beetle_SetPartBroken
