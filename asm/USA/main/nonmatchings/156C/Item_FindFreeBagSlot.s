nonmatching Item_FindFreeBagSlot, 0x64

glabel Item_FindFreeBagSlot
    /* 12DC4 800225C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12DC8 800225C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12DCC 800225CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 12DD0 800225D0 078A000C */  jal        Item_GetBagCapacity
    /* 12DD4 800225D4 FFFF1024 */   addiu     $s0, $zero, -0x1
    /* 12DD8 800225D8 21284000 */  addu       $a1, $v0, $zero
    /* 12DDC 800225DC 0D00A018 */  blez       $a1, .L80022614
    /* 12DE0 800225E0 21180000 */   addu      $v1, $zero, $zero
    /* 12DE4 800225E4 2800848F */  lw         $a0, %gp_rel(Save_GameStatePtr)($gp)
  .L800225E8:
    /* 12DE8 800225E8 00000000 */  nop
    /* 12DEC 800225EC 66008294 */  lhu        $v0, 0x66($a0)
    /* 12DF0 800225F0 00000000 */  nop
    /* 12DF4 800225F4 03004014 */  bnez       $v0, .L80022604
    /* 12DF8 800225F8 00000000 */   nop
    /* 12DFC 800225FC 85890008 */  j          .L80022614
    /* 12E00 80022600 21806000 */   addu      $s0, $v1, $zero
  .L80022604:
    /* 12E04 80022604 01006324 */  addiu      $v1, $v1, 0x1
    /* 12E08 80022608 2A106500 */  slt        $v0, $v1, $a1
    /* 12E0C 8002260C F6FF4014 */  bnez       $v0, .L800225E8
    /* 12E10 80022610 02008424 */   addiu     $a0, $a0, 0x2
  .L80022614:
    /* 12E14 80022614 21100002 */  addu       $v0, $s0, $zero
    /* 12E18 80022618 1400BF8F */  lw         $ra, 0x14($sp)
    /* 12E1C 8002261C 1000B08F */  lw         $s0, 0x10($sp)
    /* 12E20 80022620 0800E003 */  jr         $ra
    /* 12E24 80022624 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Item_FindFreeBagSlot
