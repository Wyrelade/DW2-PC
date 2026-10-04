nonmatching Stg40_InitFloorHeader, 0x2C

glabel Stg40_InitFloorHeader
    /* 488 800637E8 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* 48C 800637EC 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* 490 800637F0 00000000 */  nop
    /* 494 800637F4 340E4324 */  addiu      $v1, $v0, 0xE34
    /* 498 800637F8 540E43AC */  sw         $v1, 0xE54($v0)
    /* 49C 800637FC 40000324 */  addiu      $v1, $zero, 0x40
    /* 4A0 80063800 340E43A4 */  sh         $v1, 0xE34($v0)
    /* 4A4 80063804 540E438C */  lw         $v1, 0xE54($v0)
    /* 4A8 80063808 30000224 */  addiu      $v0, $zero, 0x30
    /* 4AC 8006380C 0800E003 */  jr         $ra
    /* 4B0 80063810 020062A4 */   sh        $v0, 0x2($v1)
endlabel Stg40_InitFloorHeader
