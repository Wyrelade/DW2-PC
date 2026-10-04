nonmatching Menu_DigiTransferPickSrc, 0x9C

glabel Menu_DigiTransferPickSrc
    /* 7CF8 800174F8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7CFC 800174FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7D00 80017500 21888000 */  addu       $s1, $a0, $zero
    /* 7D04 80017504 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7D08 80017508 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7D0C 8001750C 2C00308E */  lw         $s0, 0x2C($s1)
    /* 7D10 80017510 00000000 */  nop
    /* 7D14 80017514 50000426 */  addiu      $a0, $s0, 0x50
    /* 7D18 80017518 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 7D1C 8001751C 54000526 */   addiu     $a1, $s0, 0x54
    /* 7D20 80017520 C0100200 */  sll        $v0, $v0, 3
    /* 7D24 80017524 6C004224 */  addiu      $v0, $v0, 0x6C
    /* 7D28 80017528 0680033C */  lui        $v1, %hi(D_8005F704)
    /* 7D2C 8001752C 04F7638C */  lw         $v1, %lo(D_8005F704)($v1)
    /* 7D30 80017530 00000000 */  nop
    /* 7D34 80017534 12006018 */  blez       $v1, .L80017580
    /* 7D38 80017538 21280202 */   addu      $a1, $s0, $v0
    /* 7D3C 8001753C 0000A390 */  lbu        $v1, 0x0($a1)
    /* 7D40 80017540 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D44 80017544 0C006214 */  bne        $v1, $v0, .L80017578
    /* 7D48 80017548 10000424 */   addiu     $a0, $zero, 0x10
    /* 7D4C 8001754C 21202002 */  addu       $a0, $s1, $zero
    /* 7D50 80017550 0580033C */  lui        $v1, %hi(Menu_Ctx)
    /* 7D54 80017554 6807638C */  lw         $v1, %lo(Menu_Ctx)($v1)
    /* 7D58 80017558 0400A28C */  lw         $v0, 0x4($a1)
    /* 7D5C 8001755C 03000524 */  addiu      $a1, $zero, 0x3
    /* 7D60 80017560 280162AC */  sw         $v0, 0x128($v1)
    /* 7D64 80017564 2110A000 */  addu       $v0, $a1, $zero
    /* 7D68 80017568 260160A4 */  sh         $zero, 0x126($v1)
    /* 7D6C 8001756C 7745000C */  jal        Task_SetState1
    /* 7D70 80017570 620002A6 */   sh        $v0, 0x62($s0)
    /* 7D74 80017574 0E000424 */  addiu      $a0, $zero, 0xE
  .L80017578:
    /* 7D78 80017578 A369000C */  jal        Snd_PlayById
    /* 7D7C 8001757C 21280000 */   addu      $a1, $zero, $zero
  .L80017580:
    /* 7D80 80017580 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7D84 80017584 1400B18F */  lw         $s1, 0x14($sp)
    /* 7D88 80017588 1000B08F */  lw         $s0, 0x10($sp)
    /* 7D8C 8001758C 0800E003 */  jr         $ra
    /* 7D90 80017590 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Menu_DigiTransferPickSrc
