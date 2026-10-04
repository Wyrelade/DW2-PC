nonmatching func_8006E820, 0x38

glabel func_8006E820
    /* B4C0 8006E820 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* B4C4 8006E824 2007458C */  lw         $a1, %lo(Save_GameStatePtr)($v0)
    /* B4C8 8006E828 00000000 */  nop
    /* B4CC 8006E82C 2110A400 */  addu       $v0, $a1, $a0
    /* B4D0 8006E830 52004390 */  lbu        $v1, 0x52($v0)
    /* B4D4 8006E834 01000224 */  addiu      $v0, $zero, 0x1
    /* B4D8 8006E838 05006210 */  beq        $v1, $v0, .L8006E850
    /* B4DC 8006E83C 04104400 */   sllv      $v0, $a0, $v0
    /* B4E0 8006E840 2110A200 */  addu       $v0, $a1, $v0
    /* B4E4 8006E844 2C004294 */  lhu        $v0, 0x2C($v0)
    /* B4E8 8006E848 0800E003 */  jr         $ra
    /* B4EC 8006E84C 00000000 */   nop
  .L8006E850:
    /* B4F0 8006E850 0800E003 */  jr         $ra
    /* B4F4 8006E854 FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel func_8006E820
