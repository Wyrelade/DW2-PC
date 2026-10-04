nonmatching Stg40_PlayerWaitMsg, 0x48

glabel Stg40_PlayerWaitMsg
    /* 61B4 80069514 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 61B8 80069518 1000B0AF */  sw         $s0, 0x10($sp)
    /* 61BC 8006951C 21808000 */  addu       $s0, $a0, $zero
    /* 61C0 80069520 1400BFAF */  sw         $ra, 0x14($sp)
    /* 61C4 80069524 C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 61C8 80069528 01000424 */   addiu     $a0, $zero, 0x1
    /* 61CC 8006952C 01000324 */  addiu      $v1, $zero, 0x1
    /* 61D0 80069530 06004314 */  bne        $v0, $v1, .L8006954C
    /* 61D4 80069534 0780023C */   lui       $v0, %hi(Stg40_RootState)
    /* 61D8 80069538 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 61DC 8006953C 00000000 */  nop
    /* 61E0 80069540 38004590 */  lbu        $a1, 0x38($v0)
    /* 61E4 80069544 7745000C */  jal        Task_SetState1
    /* 61E8 80069548 21200002 */   addu      $a0, $s0, $zero
  .L8006954C:
    /* 61EC 8006954C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 61F0 80069550 1000B08F */  lw         $s0, 0x10($sp)
    /* 61F4 80069554 0800E003 */  jr         $ra
    /* 61F8 80069558 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_PlayerWaitMsg
