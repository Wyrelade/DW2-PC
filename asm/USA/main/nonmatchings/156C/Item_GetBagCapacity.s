nonmatching Item_GetBagCapacity, 0x30

glabel Item_GetBagCapacity
    /* 1301C 8002281C 2800828F */  lw         $v0, %gp_rel(Save_GameStatePtr)($gp)
    /* 13020 80022820 00000000 */  nop
    /* 13024 80022824 34004294 */  lhu        $v0, 0x34($v0)
    /* 13028 80022828 00000000 */  nop
    /* 1302C 8002282C B7FF4424 */  addiu      $a0, $v0, -0x49
    /* 13030 80022830 B5FF4224 */  addiu      $v0, $v0, -0x4B
    /* 13034 80022834 0500422C */  sltiu      $v0, $v0, 0x5
    /* 13038 80022838 02004010 */  beqz       $v0, .L80022844
    /* 1303C 8002283C 08000324 */   addiu     $v1, $zero, 0x8
    /* 13040 80022840 C0180400 */  sll        $v1, $a0, 3
  .L80022844:
    /* 13044 80022844 0800E003 */  jr         $ra
    /* 13048 80022848 21106000 */   addu      $v0, $v1, $zero
endlabel Item_GetBagCapacity
