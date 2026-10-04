nonmatching Item_AddToBag, 0x48

glabel Item_AddToBag
    /* 12FA8 800227A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12FAC 800227AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12FB0 800227B0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 12FB4 800227B4 7189000C */  jal        Item_FindFreeBagSlot
    /* 12FB8 800227B8 21808000 */   addu      $s0, $a0, $zero
    /* 12FBC 800227BC 21204000 */  addu       $a0, $v0, $zero
    /* 12FC0 800227C0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 12FC4 800227C4 05008210 */  beq        $a0, $v0, .L800227DC
    /* 12FC8 800227C8 40180400 */   sll       $v1, $a0, 1
    /* 12FCC 800227CC 2800828F */  lw         $v0, %gp_rel(Save_GameStatePtr)($gp)
    /* 12FD0 800227D0 00000000 */  nop
    /* 12FD4 800227D4 21104300 */  addu       $v0, $v0, $v1
    /* 12FD8 800227D8 660050A4 */  sh         $s0, 0x66($v0)
  .L800227DC:
    /* 12FDC 800227DC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 12FE0 800227E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 12FE4 800227E4 21108000 */  addu       $v0, $a0, $zero
    /* 12FE8 800227E8 0800E003 */  jr         $ra
    /* 12FEC 800227EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Item_AddToBag
