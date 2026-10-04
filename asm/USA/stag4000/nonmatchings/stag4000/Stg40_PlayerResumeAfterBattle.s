nonmatching Stg40_PlayerResumeAfterBattle, 0xE0

glabel Stg40_PlayerResumeAfterBattle
    /* 5FCC 8006932C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5FD0 80069330 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5FD4 80069334 21888000 */  addu       $s1, $a0, $zero
    /* 5FD8 80069338 01000324 */  addiu      $v1, $zero, 0x1
    /* 5FDC 8006933C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5FE0 80069340 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5FE4 80069344 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5FE8 80069348 2C00228E */  lw         $v0, 0x2C($s1)
    /* 5FEC 8006934C 1800308E */  lw         $s0, 0x18($s1)
    /* 5FF0 80069350 2C00528C */  lw         $s2, 0x2C($v0)
    /* 5FF4 80069354 0D000312 */  beq        $s0, $v1, .L8006938C
    /* 5FF8 80069358 0200022A */   slti      $v0, $s0, 0x2
    /* 5FFC 8006935C 04004014 */  bnez       $v0, .L80069370
    /* 6000 80069360 21202002 */   addu      $a0, $s1, $zero
    /* 6004 80069364 02000224 */  addiu      $v0, $zero, 0x2
    /* 6008 80069368 10000212 */  beq        $s0, $v0, .L800693AC
    /* 600C 8006936C 0580023C */   lui       $v0, %hi(Dung_StatePtr)
  .L80069370:
    /* 6010 80069370 37B9010C */  jal        Stg40_ObjSetAnim
    /* 6014 80069374 2D000524 */   addiu     $a1, $zero, 0x2D
    /* 6018 80069378 21202002 */  addu       $a0, $s1, $zero
    /* 601C 8006937C 8545000C */  jal        Task_SetState2
    /* 6020 80069380 01000524 */   addiu     $a1, $zero, 0x1
    /* 6024 80069384 FDA40108 */  j          .L800693F4
    /* 6028 80069388 00000000 */   nop
  .L8006938C:
    /* 602C 8006938C 319E010C */  jal        Stg40_ObjAnimDone
    /* 6030 80069390 21202002 */   addu      $a0, $s1, $zero
    /* 6034 80069394 17005014 */  bne        $v0, $s0, .L800693F4
    /* 6038 80069398 21202002 */   addu      $a0, $s1, $zero
    /* 603C 8006939C 8545000C */  jal        Task_SetState2
    /* 6040 800693A0 02000524 */   addiu     $a1, $zero, 0x2
    /* 6044 800693A4 FDA40108 */  j          .L800693F4
    /* 6048 800693A8 00000000 */   nop
  .L800693AC:
    /* 604C 800693AC 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* 6050 800693B0 00000000 */  nop
    /* 6054 800693B4 02004290 */  lbu        $v0, 0x2($v0)
    /* 6058 800693B8 00000000 */  nop
    /* 605C 800693BC 0D004014 */  bnez       $v0, .L800693F4
    /* 6060 800693C0 00000000 */   nop
    /* 6064 800693C4 25C3010C */  jal        Stg40_TurnQueueCurrent
    /* 6068 800693C8 00000000 */   nop
    /* 606C 800693CC 00140200 */  sll        $v0, $v0, 16
    /* 6070 800693D0 07004392 */  lbu        $v1, 0x7($s2)
    /* 6074 800693D4 03140200 */  sra        $v0, $v0, 16
    /* 6078 800693D8 03004314 */  bne        $v0, $v1, .L800693E8
    /* 607C 800693DC 21202002 */   addu      $a0, $s1, $zero
    /* 6080 800693E0 FBA40108 */  j          .L800693EC
    /* 6084 800693E4 01000524 */   addiu     $a1, $zero, 0x1
  .L800693E8:
    /* 6088 800693E8 21280000 */  addu       $a1, $zero, $zero
  .L800693EC:
    /* 608C 800693EC 7745000C */  jal        Task_SetState1
    /* 6090 800693F0 00000000 */   nop
  .L800693F4:
    /* 6094 800693F4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6098 800693F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 609C 800693FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 60A0 80069400 1000B08F */  lw         $s0, 0x10($sp)
    /* 60A4 80069404 0800E003 */  jr         $ra
    /* 60A8 80069408 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_PlayerResumeAfterBattle
