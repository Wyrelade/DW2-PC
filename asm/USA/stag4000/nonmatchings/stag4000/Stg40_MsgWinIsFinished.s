nonmatching Stg40_MsgWinIsFinished, 0x34

glabel Stg40_MsgWinIsFinished
    /* 4370 800676D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4374 800676D4 0780023C */  lui        $v0, %hi(Stg40_MsgWinTexts)
    /* 4378 800676D8 842B428C */  lw         $v0, %lo(Stg40_MsgWinTexts)($v0)
    /* 437C 800676DC 80200400 */  sll        $a0, $a0, 2
    /* 4380 800676E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4384 800676E4 21104400 */  addu       $v0, $v0, $a0
    /* 4388 800676E8 0000448C */  lw         $a0, 0x0($v0)
    /* 438C 800676EC 826F000C */  jal        Text_IsFinished
    /* 4390 800676F0 00000000 */   nop
    /* 4394 800676F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4398 800676F8 00000000 */  nop
    /* 439C 800676FC 0800E003 */  jr         $ra
    /* 43A0 80067700 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_MsgWinIsFinished
