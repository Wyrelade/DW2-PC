nonmatching func_80068B9C, 0x5C

glabel func_80068B9C
    /* 583C 80068B9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5840 80068BA0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5844 80068BA4 08070424 */  addiu      $a0, $zero, 0x708
    /* 5848 80068BA8 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 584C 80068BAC 4445000C */  jal        Task_FindFirst
    /* 5850 80068BB0 2130A000 */   addu      $a2, $a1, $zero
    /* 5854 80068BB4 21204000 */  addu       $a0, $v0, $zero
    /* 5858 80068BB8 05008010 */  beqz       $a0, .L80068BD0
    /* 585C 80068BBC 02000224 */   addiu     $v0, $zero, 0x2
    /* 5860 80068BC0 1400838C */  lw         $v1, 0x14($a0)
    /* 5864 80068BC4 00000000 */  nop
    /* 5868 80068BC8 07006210 */  beq        $v1, $v0, .L80068BE8
    /* 586C 80068BCC 01000224 */   addiu     $v0, $zero, 0x1
  .L80068BD0:
    /* 5870 80068BD0 2C00828C */  lw         $v0, 0x2C($a0)
    /* 5874 80068BD4 00000000 */  nop
    /* 5878 80068BD8 7800428C */  lw         $v0, 0x78($v0)
    /* 587C 80068BDC 00000000 */  nop
    /* 5880 80068BE0 2B100200 */  sltu       $v0, $zero, $v0
    /* 5884 80068BE4 40100200 */  sll        $v0, $v0, 1
  .L80068BE8:
    /* 5888 80068BE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 588C 80068BEC 00000000 */  nop
    /* 5890 80068BF0 0800E003 */  jr         $ra
    /* 5894 80068BF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068B9C
