/* Handwritten function */
nonmatching SquareRoot0, 0x84

glabel SquareRoot0
    /* 1D6E4 8002CEE4 00F08448 */  mtc2       $a0, $30 /* handwritten instruction */
    /* 1D6E8 8002CEE8 00000000 */  nop
    /* 1D6EC 8002CEEC 00000000 */  nop
    /* 1D6F0 8002CEF0 00F80248 */  mfc2       $v0, $31 /* handwritten instruction */
    /* 1D6F4 8002CEF4 20000124 */  addiu      $at, $zero, 0x20
    /* 1D6F8 8002CEF8 19004110 */  beq        $v0, $at, .L8002CF60
    /* 1D6FC 8002CEFC 00000000 */   nop
    /* 1D700 8002CF00 01004830 */  andi       $t0, $v0, 0x1
    /* 1D704 8002CF04 FEFF0124 */  addiu      $at, $zero, -0x2
    /* 1D708 8002CF08 24504100 */  and        $t2, $v0, $at
    /* 1D70C 8002CF0C 1F000924 */  addiu      $t1, $zero, 0x1F
    /* 1D710 8002CF10 22482A01 */  sub        $t1, $t1, $t2 /* handwritten instruction */
    /* 1D714 8002CF14 43480900 */  sra        $t1, $t1, 1
    /* 1D718 8002CF18 E8FF4B21 */  addi       $t3, $t2, -0x18 /* handwritten instruction */
    /* 1D71C 8002CF1C 03006005 */  bltz       $t3, .L8002CF2C
    /* 1D720 8002CF20 00000000 */   nop
    /* 1D724 8002CF24 04606401 */  sllv       $t4, $a0, $t3
    /* 1D728 8002CF28 03000010 */  b          .L8002CF38
  .L8002CF2C:
    /* 1D72C 8002CF2C 18000B24 */   addiu     $t3, $zero, 0x18
    /* 1D730 8002CF30 22586A01 */  sub        $t3, $t3, $t2 /* handwritten instruction */
    /* 1D734 8002CF34 07606401 */  srav       $t4, $a0, $t3
  .L8002CF38:
    /* 1D738 8002CF38 C0FF8C21 */  addi       $t4, $t4, -0x40 /* handwritten instruction */
    /* 1D73C 8002CF3C 40600C00 */  sll        $t4, $t4, 1
    /* 1D740 8002CF40 05800D3C */  lui        $t5, %hi(D_80049930)
    /* 1D744 8002CF44 2168AC01 */  addu       $t5, $t5, $t4
    /* 1D748 8002CF48 3099AD85 */  lh         $t5, %lo(D_80049930)($t5)
    /* 1D74C 8002CF4C 00000000 */  nop
    /* 1D750 8002CF50 04682D01 */  sllv       $t5, $t5, $t1
    /* 1D754 8002CF54 02130D00 */  srl        $v0, $t5, 12
    /* 1D758 8002CF58 0800E003 */  jr         $ra
    /* 1D75C 8002CF5C 00000000 */   nop
  .L8002CF60:
    /* 1D760 8002CF60 0800E003 */  jr         $ra
    /* 1D764 8002CF64 00000224 */   addiu     $v0, $zero, 0x0
endlabel SquareRoot0
    /* 1D768 8002CF68 00000000 */  nop
    /* 1D76C 8002CF6C 00000000 */  nop
    /* 1D770 8002CF70 00000000 */  nop
