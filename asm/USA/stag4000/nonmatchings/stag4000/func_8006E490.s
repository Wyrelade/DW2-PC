nonmatching func_8006E490, 0x4C

glabel func_8006E490
    /* B130 8006E490 C3170400 */  sra        $v0, $a0, 31
    /* B134 8006E494 02008018 */  blez       $a0, .L8006E4A0
    /* B138 8006E498 08004630 */   andi      $a2, $v0, 0x8
    /* B13C 8006E49C 0400C634 */  ori        $a2, $a2, 0x4
  .L8006E4A0:
    /* B140 8006E4A0 0200A104 */  bgez       $a1, .L8006E4AC
    /* B144 8006E4A4 2A100500 */   slt       $v0, $zero, $a1
    /* B148 8006E4A8 0200C634 */  ori        $a2, $a2, 0x2
  .L8006E4AC:
    /* B14C 8006E4AC 2530C200 */  or         $a2, $a2, $v0
    /* B150 8006E4B0 0780033C */  lui        $v1, %hi(D_800728D4)
    /* B154 8006E4B4 D4286324 */  addiu      $v1, $v1, %lo(D_800728D4)
    /* B158 8006E4B8 40100600 */  sll        $v0, $a2, 1
    /* B15C 8006E4BC 21104300 */  addu       $v0, $v0, $v1
    /* B160 8006E4C0 00004384 */  lh         $v1, 0x0($v0)
    /* B164 8006E4C4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B168 8006E4C8 02006210 */  beq        $v1, $v0, .L8006E4D4
    /* B16C 8006E4CC 21200000 */   addu      $a0, $zero, $zero
    /* B170 8006E4D0 21206000 */  addu       $a0, $v1, $zero
  .L8006E4D4:
    /* B174 8006E4D4 0800E003 */  jr         $ra
    /* B178 8006E4D8 21108000 */   addu      $v0, $a0, $zero
endlabel func_8006E490
