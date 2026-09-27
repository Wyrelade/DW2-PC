nonmatching StoreImage2, 0xEC

glabel StoreImage2
    /* 1A488 80029C88 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1A48C 80029C8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1A490 80029C90 21808000 */  addu       $s0, $a0, $zero
    /* 1A494 80029C94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1A498 80029C98 2188A000 */  addu       $s1, $a1, $zero
    /* 1A49C 80029C9C 0180043C */  lui        $a0, %hi(D_8001031C)
    /* 1A4A0 80029CA0 1C038424 */  addiu      $a0, $a0, %lo(D_8001031C)
    /* 1A4A4 80029CA4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1A4A8 80029CA8 3A9D000C */  jal        checkRECT
    /* 1A4AC 80029CAC 21280002 */   addu      $a1, $s0, $zero
    /* 1A4B0 80029CB0 ADC2000C */  jal        VSync
    /* 1A4B4 80029CB4 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1A4B8 80029CB8 0580033C */  lui        $v1, %hi(D_80049024)
    /* 1A4BC 80029CBC 2490638C */  lw         $v1, %lo(D_80049024)($v1)
    /* 1A4C0 80029CC0 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1A4C4 80029CC4 0580013C */  lui        $at, %hi(D_8004904C)
    /* 1A4C8 80029CC8 4C9022AC */  sw         $v0, %lo(D_8004904C)($at)
    /* 1A4CC 80029CCC 0580013C */  lui        $at, %hi(D_80049050)
    /* 1A4D0 80029CD0 509020AC */  sw         $zero, %lo(D_80049050)($at)
    /* 1A4D4 80029CD4 0000628C */  lw         $v0, 0x0($v1)
    /* 1A4D8 80029CD8 41A70008 */  j          .L80029D04
    /* 1A4DC 80029CDC 0001033C */   lui       $v1, (0x1000000 >> 16)
  .L80029CE0:
    /* 1A4E0 80029CE0 6EA6000C */  jal        get_alarm
    /* 1A4E4 80029CE4 00000000 */   nop
    /* 1A4E8 80029CE8 1D004014 */  bnez       $v0, .L80029D60
    /* 1A4EC 80029CEC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1A4F0 80029CF0 0580023C */  lui        $v0, %hi(D_80049024)
    /* 1A4F4 80029CF4 2490428C */  lw         $v0, %lo(D_80049024)($v0)
    /* 1A4F8 80029CF8 00000000 */  nop
    /* 1A4FC 80029CFC 0000428C */  lw         $v0, 0x0($v0)
    /* 1A500 80029D00 0001033C */  lui        $v1, (0x1000000 >> 16)
  .L80029D04:
    /* 1A504 80029D04 24104300 */  and        $v0, $v0, $v1
    /* 1A508 80029D08 F5FF4014 */  bnez       $v0, .L80029CE0
    /* 1A50C 80029D0C 00000000 */   nop
    /* 1A510 80029D10 0580023C */  lui        $v0, %hi(D_80049018)
    /* 1A514 80029D14 1890428C */  lw         $v0, %lo(D_80049018)($v0)
    /* 1A518 80029D18 00000000 */  nop
    /* 1A51C 80029D1C 0000428C */  lw         $v0, 0x0($v0)
    /* 1A520 80029D20 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1A524 80029D24 24104300 */  and        $v0, $v0, $v1
    /* 1A528 80029D28 EDFF4010 */  beqz       $v0, .L80029CE0
    /* 1A52C 80029D2C 00000000 */   nop
    /* 1A530 80029D30 0380053C */  lui        $a1, %hi(Gpu_RestoreExequeCb)
    /* 1A534 80029D34 B49FA524 */  addiu      $a1, $a1, %lo(Gpu_RestoreExequeCb)
    /* 1A538 80029D38 4DC3000C */  jal        DMACallback
    /* 1A53C 80029D3C 02000424 */   addiu     $a0, $zero, 0x2
    /* 1A540 80029D40 0580023C */  lui        $v0, %hi(D_80048F08)
    /* 1A544 80029D44 088F428C */  lw         $v0, %lo(D_80048F08)($v0)
    /* 1A548 80029D48 21200002 */  addu       $a0, $s0, $zero
    /* 1A54C 80029D4C 1C00428C */  lw         $v0, 0x1C($v0)
    /* 1A550 80029D50 00000000 */  nop
    /* 1A554 80029D54 09F84000 */  jalr       $v0
    /* 1A558 80029D58 21282002 */   addu      $a1, $s1, $zero
    /* 1A55C 80029D5C 21100000 */  addu       $v0, $zero, $zero
  .L80029D60:
    /* 1A560 80029D60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1A564 80029D64 1400B18F */  lw         $s1, 0x14($sp)
    /* 1A568 80029D68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1A56C 80029D6C 0800E003 */  jr         $ra
    /* 1A570 80029D70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel StoreImage2
