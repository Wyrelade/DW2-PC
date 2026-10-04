nonmatching Stg40_PlayerAnimThenMsgUpdate, 0xC4

glabel Stg40_PlayerAnimThenMsgUpdate
    /* 60AC 8006940C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 60B0 80069410 1400B1AF */  sw         $s1, 0x14($sp)
    /* 60B4 80069414 21888000 */  addu       $s1, $a0, $zero
    /* 60B8 80069418 1800BFAF */  sw         $ra, 0x18($sp)
    /* 60BC 8006941C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 60C0 80069420 1800308E */  lw         $s0, 0x18($s1)
    /* 60C4 80069424 00000000 */  nop
    /* 60C8 80069428 03000012 */  beqz       $s0, .L80069438
    /* 60CC 8006942C 01000224 */   addiu     $v0, $zero, 0x1
    /* 60D0 80069430 19000212 */  beq        $s0, $v0, .L80069498
    /* 60D4 80069434 00000000 */   nop
  .L80069438:
    /* 60D8 80069438 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 60DC 8006943C 21202002 */   addu      $a0, $s1, $zero
    /* 60E0 80069440 01000324 */  addiu      $v1, $zero, 0x1
    /* 60E4 80069444 1D004314 */  bne        $v0, $v1, .L800694BC
    /* 60E8 80069448 0780103C */   lui       $s0, %hi(D_80072B60)
    /* 60EC 8006944C 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 60F0 80069450 00000000 */  nop
    /* 60F4 80069454 3400458C */  lw         $a1, 0x34($v0)
    /* 60F8 80069458 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 60FC 8006945C 0300A210 */  beq        $a1, $v0, .L8006946C
    /* 6100 80069460 00000000 */   nop
    /* 6104 80069464 37B9010C */  jal        Stg40_ObjSetAnim
    /* 6108 80069468 21202002 */   addu      $a0, $s1, $zero
  .L8006946C:
    /* 610C 8006946C 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 6110 80069470 00000000 */  nop
    /* 6114 80069474 4400458C */  lw         $a1, 0x44($v0)
    /* 6118 80069478 4800468C */  lw         $a2, 0x48($v0)
    /* 611C 8006947C 4C00478C */  lw         $a3, 0x4C($v0)
    /* 6120 80069480 849D010C */  jal        Stg40_MsgWinOpen
    /* 6124 80069484 01000424 */   addiu     $a0, $zero, 0x1
    /* 6128 80069488 6045000C */  jal        Task_NextState2
    /* 612C 8006948C 21202002 */   addu      $a0, $s1, $zero
    /* 6130 80069490 2FA50108 */  j          .L800694BC
    /* 6134 80069494 00000000 */   nop
  .L80069498:
    /* 6138 80069498 C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 613C 8006949C 01000424 */   addiu     $a0, $zero, 0x1
    /* 6140 800694A0 06005014 */  bne        $v0, $s0, .L800694BC
    /* 6144 800694A4 0780023C */   lui       $v0, %hi(D_80072B60)
    /* 6148 800694A8 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 614C 800694AC 00000000 */  nop
    /* 6150 800694B0 38004590 */  lbu        $a1, 0x38($v0)
    /* 6154 800694B4 7745000C */  jal        Task_SetState1
    /* 6158 800694B8 21202002 */   addu      $a0, $s1, $zero
  .L800694BC:
    /* 615C 800694BC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6160 800694C0 1400B18F */  lw         $s1, 0x14($sp)
    /* 6164 800694C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6168 800694C8 0800E003 */  jr         $ra
    /* 616C 800694CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_PlayerAnimThenMsgUpdate
