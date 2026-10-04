nonmatching func_8006E858, 0x6C

glabel func_8006E858
    /* B4F8 8006E858 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B4FC 8006E85C 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* B500 8006E860 2007438C */  lw         $v1, %lo(Save_GameStatePtr)($v0)
    /* B504 8006E864 40100400 */  sll        $v0, $a0, 1
    /* B508 8006E868 1000BFAF */  sw         $ra, 0x10($sp)
    /* B50C 8006E86C 21286200 */  addu       $a1, $v1, $v0
    /* B510 8006E870 2C00A294 */  lhu        $v0, 0x2C($a1)
    /* B514 8006E874 00000000 */  nop
    /* B518 8006E878 03004014 */  bnez       $v0, .L8006E888
    /* B51C 8006E87C 21106400 */   addu      $v0, $v1, $a0
    /* B520 8006E880 2DBA0108 */  j          .L8006E8B4
    /* B524 8006E884 21100000 */   addu      $v0, $zero, $zero
  .L8006E888:
    /* B528 8006E888 52004390 */  lbu        $v1, 0x52($v0)
    /* B52C 8006E88C 01000224 */  addiu      $v0, $zero, 0x1
    /* B530 8006E890 08006210 */  beq        $v1, $v0, .L8006E8B4
    /* B534 8006E894 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* B538 8006E898 2C00A494 */  lhu        $a0, 0x2C($a1)
    /* B53C 8006E89C 3978000C */  jal        Item_GetLevel
    /* B540 8006E8A0 00000000 */   nop
    /* B544 8006E8A4 02004014 */  bnez       $v0, .L8006E8B0
    /* B548 8006E8A8 21184000 */   addu      $v1, $v0, $zero
    /* B54C 8006E8AC 01000324 */  addiu      $v1, $zero, 0x1
  .L8006E8B0:
    /* B550 8006E8B0 21106000 */  addu       $v0, $v1, $zero
  .L8006E8B4:
    /* B554 8006E8B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* B558 8006E8B8 00000000 */  nop
    /* B55C 8006E8BC 0800E003 */  jr         $ra
    /* B560 8006E8C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006E858
