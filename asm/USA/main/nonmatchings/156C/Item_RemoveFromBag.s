nonmatching Item_RemoveFromBag, 0x2C

glabel Item_RemoveFromBag
    /* 12FF0 800227F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12FF4 800227F4 2800828F */  lw         $v0, %gp_rel(Save_GameStatePtr)($gp)
    /* 12FF8 800227F8 40200400 */  sll        $a0, $a0, 1
    /* 12FFC 800227FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13000 80022800 21104400 */  addu       $v0, $v0, $a0
    /* 13004 80022804 8A89000C */  jal        Item_CompactBag
    /* 13008 80022808 660040A4 */   sh        $zero, 0x66($v0)
    /* 1300C 8002280C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13010 80022810 00000000 */  nop
    /* 13014 80022814 0800E003 */  jr         $ra
    /* 13018 80022818 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Item_RemoveFromBag
