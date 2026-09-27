nonmatching func_80068B8C, 0xD4

glabel func_80068B8C
    /* 582C 80068B8C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5830 80068B90 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5834 80068B94 21908000 */  addu       $s2, $a0, $zero
    /* 5838 80068B98 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 583C 80068B9C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5840 80068BA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5844 80068BA4 2C00428E */  lw         $v0, 0x2C($s2)
    /* 5848 80068BA8 00000000 */  nop
    /* 584C 80068BAC 2C00508C */  lw         $s0, 0x2C($v0)
    /* 5850 80068BB0 B3B9010C */  jal        func_8006E6CC
    /* 5854 80068BB4 21880000 */   addu      $s1, $zero, $zero
    /* 5858 80068BB8 05004010 */  beqz       $v0, .L80068BD0
    /* 585C 80068BBC 21204002 */   addu      $a0, $s2, $zero
    /* 5860 80068BC0 7745000C */  jal        Task_SetState1
    /* 5864 80068BC4 1E000524 */   addiu     $a1, $zero, 0x1E
    /* 5868 80068BC8 12A30108 */  j          .L80068C48
    /* 586C 80068BCC 01000224 */   addiu     $v0, $zero, 0x1
  .L80068BD0:
    /* 5870 80068BD0 78A2010C */  jal        func_800689E0
    /* 5874 80068BD4 21200002 */   addu      $a0, $s0, $zero
    /* 5878 80068BD8 21204000 */  addu       $a0, $v0, $zero
    /* 587C 80068BDC 1A008010 */  beqz       $a0, .L80068C48
    /* 5880 80068BE0 21100000 */   addu      $v0, $zero, $zero
    /* 5884 80068BE4 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 5888 80068BE8 1400838C */  lw         $v1, 0x14($a0)
    /* 588C 80068BEC 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 5890 80068BF0 00000000 */  nop
    /* 5894 80068BF4 3C0043AC */  sw         $v1, 0x3C($v0)
    /* 5898 80068BF8 400044AC */  sw         $a0, 0x40($v0)
    /* 589C 80068BFC 08008390 */  lbu        $v1, 0x8($a0)
    /* 58A0 80068C00 00000000 */  nop
    /* 58A4 80068C04 04006228 */  slti       $v0, $v1, 0x4
    /* 58A8 80068C08 0E004010 */  beqz       $v0, .L80068C44
    /* 58AC 80068C0C 02006228 */   slti      $v0, $v1, 0x2
    /* 58B0 80068C10 0D004014 */  bnez       $v0, .L80068C48
    /* 58B4 80068C14 21102002 */   addu      $v0, $s1, $zero
    /* 58B8 80068C18 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 58BC 80068C1C 1C07458C */  lw         $a1, %lo(D_8005071C)($v0)
    /* 58C0 80068C20 02000224 */  addiu      $v0, $zero, 0x2
    /* 58C4 80068C24 02006210 */  beq        $v1, $v0, .L80068C30
    /* 58C8 80068C28 02000424 */   addiu     $a0, $zero, 0x2
    /* 58CC 80068C2C 03000424 */  addiu      $a0, $zero, 0x3
  .L80068C30:
    /* 58D0 80068C30 0100A4A0 */  sb         $a0, 0x1($a1)
    /* 58D4 80068C34 21204002 */  addu       $a0, $s2, $zero
    /* 58D8 80068C38 7745000C */  jal        Task_SetState1
    /* 58DC 80068C3C 17000524 */   addiu     $a1, $zero, 0x17
    /* 58E0 80068C40 01001124 */  addiu      $s1, $zero, 0x1
  .L80068C44:
    /* 58E4 80068C44 21102002 */  addu       $v0, $s1, $zero
  .L80068C48:
    /* 58E8 80068C48 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 58EC 80068C4C 1800B28F */  lw         $s2, 0x18($sp)
    /* 58F0 80068C50 1400B18F */  lw         $s1, 0x14($sp)
    /* 58F4 80068C54 1000B08F */  lw         $s0, 0x10($sp)
    /* 58F8 80068C58 0800E003 */  jr         $ra
    /* 58FC 80068C5C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80068B8C
