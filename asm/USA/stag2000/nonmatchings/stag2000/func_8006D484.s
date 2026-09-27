nonmatching func_8006D484, 0x38

glabel func_8006D484
    /* A124 8006D484 21300000 */  addu       $a2, $zero, $zero
    /* A128 8006D488 2C00838C */  lw         $v1, 0x2C($a0)
  .L8006D48C:
    /* A12C 8006D48C 00000000 */  nop
    /* A130 8006D490 60006284 */  lh         $v0, 0x60($v1)
    /* A134 8006D494 00000000 */  nop
    /* A138 8006D498 03004514 */  bne        $v0, $a1, .L8006D4A8
    /* A13C 8006D49C 0100C624 */   addiu     $a2, $a2, 0x1
    /* A140 8006D4A0 0800E003 */  jr         $ra
    /* A144 8006D4A4 01000224 */   addiu     $v0, $zero, 0x1
  .L8006D4A8:
    /* A148 8006D4A8 4300C228 */  slti       $v0, $a2, 0x43
    /* A14C 8006D4AC F7FF4014 */  bnez       $v0, .L8006D48C
    /* A150 8006D4B0 02006324 */   addiu     $v1, $v1, 0x2
    /* A154 8006D4B4 0800E003 */  jr         $ra
    /* A158 8006D4B8 21100000 */   addu      $v0, $zero, $zero
endlabel func_8006D484
