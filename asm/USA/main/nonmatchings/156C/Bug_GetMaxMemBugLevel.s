nonmatching Bug_GetMaxMemBugLevel, 0x68

glabel Bug_GetMaxMemBugLevel
    /* 12560 80021D60 2400858F */  lw         $a1, %gp_rel(Dung_StatePtr)($gp)
    /* 12564 80021D64 00000000 */  nop
    /* 12568 80021D68 A80BA290 */  lbu        $v0, 0xBA8($a1)
    /* 1256C 80021D6C 00000000 */  nop
    /* 12570 80021D70 13004010 */  beqz       $v0, .L80021DC0
    /* 12574 80021D74 21300000 */   addu      $a2, $zero, $zero
    /* 12578 80021D78 2A10C200 */  slt        $v0, $a2, $v0
    /* 1257C 80021D7C 10004010 */  beqz       $v0, .L80021DC0
    /* 12580 80021D80 2120C000 */   addu      $a0, $a2, $zero
  .L80021D84:
    /* 12584 80021D84 2110A400 */  addu       $v0, $a1, $a0
    /* 12588 80021D88 A90B4290 */  lbu        $v0, 0xBA9($v0)
    /* 1258C 80021D8C 00000000 */  nop
    /* 12590 80021D90 21184000 */  addu       $v1, $v0, $zero
    /* 12594 80021D94 2A10C300 */  slt        $v0, $a2, $v1
    /* 12598 80021D98 02004014 */  bnez       $v0, .L80021DA4
    /* 1259C 80021D9C 00000000 */   nop
    /* 125A0 80021DA0 2118C000 */  addu       $v1, $a2, $zero
  .L80021DA4:
    /* 125A4 80021DA4 2400858F */  lw         $a1, %gp_rel(Dung_StatePtr)($gp)
    /* 125A8 80021DA8 00000000 */  nop
    /* 125AC 80021DAC A80BA290 */  lbu        $v0, 0xBA8($a1)
    /* 125B0 80021DB0 01008424 */  addiu      $a0, $a0, 0x1
    /* 125B4 80021DB4 2A108200 */  slt        $v0, $a0, $v0
    /* 125B8 80021DB8 F2FF4014 */  bnez       $v0, .L80021D84
    /* 125BC 80021DBC 21306000 */   addu      $a2, $v1, $zero
  .L80021DC0:
    /* 125C0 80021DC0 0800E003 */  jr         $ra
    /* 125C4 80021DC4 2110C000 */   addu      $v0, $a2, $zero
endlabel Bug_GetMaxMemBugLevel
