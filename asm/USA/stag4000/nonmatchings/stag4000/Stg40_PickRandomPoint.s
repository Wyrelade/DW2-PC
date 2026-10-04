nonmatching Stg40_PickRandomPoint, 0x90

glabel Stg40_PickRandomPoint
    /* DC8C 80070FEC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DC90 80070FF0 2138A000 */  addu       $a3, $a1, $zero
    /* DC94 80070FF4 FFFF0924 */  addiu      $t1, $zero, -0x1
    /* DC98 80070FF8 1000BFAF */  sw         $ra, 0x10($sp)
    /* DC9C 80070FFC 0000E390 */  lbu        $v1, 0x0($a3)
    /* DCA0 80071000 FF000224 */  addiu      $v0, $zero, 0xFF
    /* DCA4 80071004 14006210 */  beq        $v1, $v0, .L80071058
    /* DCA8 80071008 21400000 */   addu      $t0, $zero, $zero
    /* DCAC 8007100C FF00C630 */  andi       $a2, $a2, 0xFF
    /* DCB0 80071010 21184000 */  addu       $v1, $v0, $zero
    /* DCB4 80071014 0100A524 */  addiu      $a1, $a1, 0x1
  .L80071018:
    /* DCB8 80071018 0100A290 */  lbu        $v0, 0x1($a1)
    /* DCBC 8007101C 00000000 */  nop
    /* DCC0 80071020 08004614 */  bne        $v0, $a2, .L80071044
    /* DCC4 80071024 00000000 */   nop
    /* DCC8 80071028 0000E290 */  lbu        $v0, 0x0($a3)
    /* DCCC 8007102C 00000000 */  nop
    /* DCD0 80071030 000082A4 */  sh         $v0, 0x0($a0)
    /* DCD4 80071034 0000A290 */  lbu        $v0, 0x0($a1)
    /* DCD8 80071038 01000825 */  addiu      $t0, $t0, 0x1
    /* DCDC 8007103C 020082A4 */  sh         $v0, 0x2($a0)
    /* DCE0 80071040 04008424 */  addiu      $a0, $a0, 0x4
  .L80071044:
    /* DCE4 80071044 0300E724 */  addiu      $a3, $a3, 0x3
    /* DCE8 80071048 0000E290 */  lbu        $v0, 0x0($a3)
    /* DCEC 8007104C 00000000 */  nop
    /* DCF0 80071050 F1FF4314 */  bne        $v0, $v1, .L80071018
    /* DCF4 80071054 0300A524 */   addiu     $a1, $a1, 0x3
  .L80071058:
    /* DCF8 80071058 04000011 */  beqz       $t0, .L8007106C
    /* DCFC 8007105C 00000000 */   nop
    /* DD00 80071060 71C4010C */  jal        Stg40_RandInt
    /* DD04 80071064 21200001 */   addu      $a0, $t0, $zero
    /* DD08 80071068 21484000 */  addu       $t1, $v0, $zero
  .L8007106C:
    /* DD0C 8007106C 1000BF8F */  lw         $ra, 0x10($sp)
    /* DD10 80071070 21102001 */  addu       $v0, $t1, $zero
    /* DD14 80071074 0800E003 */  jr         $ra
    /* DD18 80071078 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_PickRandomPoint
