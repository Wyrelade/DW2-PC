nonmatching func_80068B44, 0x10C

glabel func_80068B44
    /* 57E4 80068B44 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 57E8 80068B48 4400B1AF */  sw         $s1, 0x44($sp)
    /* 57EC 80068B4C 21888000 */  addu       $s1, $a0, $zero
    /* 57F0 80068B50 01000224 */  addiu      $v0, $zero, 0x1
    /* 57F4 80068B54 4800BFAF */  sw         $ra, 0x48($sp)
    /* 57F8 80068B58 4000B0AF */  sw         $s0, 0x40($sp)
    /* 57FC 80068B5C 1000268E */  lw         $a2, 0x10($s1)
    /* 5800 80068B60 2C00308E */  lw         $s0, 0x2C($s1)
    /* 5804 80068B64 0F00C210 */  beq        $a2, $v0, .L80068BA4
    /* 5808 80068B68 0200C228 */   slti      $v0, $a2, 0x2
    /* 580C 80068B6C 33004010 */  beqz       $v0, .L80068C3C
    /* 5810 80068B70 00000000 */   nop
    /* 5814 80068B74 3100C014 */  bnez       $a2, .L80068C3C
    /* 5818 80068B78 00000000 */   nop
    /* 581C 80068B7C 21200002 */  addu       $a0, $s0, $zero
    /* 5820 80068B80 2270000C */  jal        Mem_FillWordsNeg1
    /* 5824 80068B84 01000524 */   addiu     $a1, $zero, 0x1
    /* 5828 80068B88 10000424 */  addiu      $a0, $zero, 0x10
    /* 582C 80068B8C 7188000C */  jal        Flag_Set
    /* 5830 80068B90 21280000 */   addu      $a1, $zero, $zero
    /* 5834 80068B94 5145000C */  jal        Task_NextState0
    /* 5838 80068B98 21202002 */   addu      $a0, $s1, $zero
    /* 583C 80068B9C 0FA30108 */  j          .L80068C3C
    /* 5840 80068BA0 00000000 */   nop
  .L80068BA4:
    /* 5844 80068BA4 1800028E */  lw         $v0, 0x18($s0)
    /* 5848 80068BA8 00000000 */  nop
    /* 584C 80068BAC 18004010 */  beqz       $v0, .L80068C10
    /* 5850 80068BB0 21200002 */   addu      $a0, $s0, $zero
    /* 5854 80068BB4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 5858 80068BB8 0400038E */  lw         $v1, 0x4($s0)
    /* 585C 80068BBC 10000224 */  addiu      $v0, $zero, 0x10
    /* 5860 80068BC0 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 5864 80068BC4 BA000224 */  addiu      $v0, $zero, 0xBA
    /* 5868 80068BC8 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 586C 80068BCC 10000224 */  addiu      $v0, $zero, 0x10
    /* 5870 80068BD0 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5874 80068BD4 03000224 */  addiu      $v0, $zero, 0x3
    /* 5878 80068BD8 2800A2AF */  sw         $v0, 0x28($sp)
    /* 587C 80068BDC 08000226 */  addiu      $v0, $s0, 0x8
    /* 5880 80068BE0 1000A6AF */  sw         $a2, 0x10($sp)
    /* 5884 80068BE4 1400A0AF */  sw         $zero, 0x14($sp)
    /* 5888 80068BE8 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 588C 80068BEC 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 5890 80068BF0 096F000C */  jal        Text_Open
    /* 5894 80068BF4 2400A3AF */   sw        $v1, 0x24($sp)
    /* 5898 80068BF8 10000424 */  addiu      $a0, $zero, 0x10
    /* 589C 80068BFC 7188000C */  jal        Flag_Set
    /* 58A0 80068C00 21280000 */   addu      $a1, $zero, $zero
    /* 58A4 80068C04 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 58A8 80068C08 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 58AC 80068C0C 180000AE */  sw         $zero, 0x18($s0)
  .L80068C10:
    /* 58B0 80068C10 1C00038E */  lw         $v1, 0x1C($s0)
    /* 58B4 80068C14 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 58B8 80068C18 08006214 */  bne        $v1, $v0, .L80068C3C
    /* 58BC 80068C1C 00000000 */   nop
    /* 58C0 80068C20 9E87000C */  jal        Flag_Test
    /* 58C4 80068C24 10000424 */   addiu     $a0, $zero, 0x10
    /* 58C8 80068C28 04004010 */  beqz       $v0, .L80068C3C
    /* 58CC 80068C2C 00000000 */   nop
    /* 58D0 80068C30 9E87000C */  jal        Flag_Test
    /* 58D4 80068C34 11000424 */   addiu     $a0, $zero, 0x11
    /* 58D8 80068C38 1C0002AE */  sw         $v0, 0x1C($s0)
  .L80068C3C:
    /* 58DC 80068C3C 4800BF8F */  lw         $ra, 0x48($sp)
    /* 58E0 80068C40 4400B18F */  lw         $s1, 0x44($sp)
    /* 58E4 80068C44 4000B08F */  lw         $s0, 0x40($sp)
    /* 58E8 80068C48 0800E003 */  jr         $ra
    /* 58EC 80068C4C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_80068B44
