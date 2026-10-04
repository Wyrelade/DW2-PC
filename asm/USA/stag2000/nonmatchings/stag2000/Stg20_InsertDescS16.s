nonmatching Stg20_InsertDescS16, 0x48

glabel Stg20_InsertDescS16
    /* A194 8006D4F4 0D00A018 */  blez       $a1, .L8006D52C
    /* A198 8006D4F8 21400000 */   addu      $t0, $zero, $zero
    /* A19C 8006D4FC 21188000 */  addu       $v1, $a0, $zero
  .L8006D500:
    /* A1A0 8006D500 00006784 */  lh         $a3, 0x0($v1)
    /* A1A4 8006D504 00000000 */  nop
    /* A1A8 8006D508 2A10E600 */  slt        $v0, $a3, $a2
    /* A1AC 8006D50C 03004010 */  beqz       $v0, .L8006D51C
    /* A1B0 8006D510 00000000 */   nop
    /* A1B4 8006D514 000066A4 */  sh         $a2, 0x0($v1)
    /* A1B8 8006D518 2130E000 */  addu       $a2, $a3, $zero
  .L8006D51C:
    /* A1BC 8006D51C 01000825 */  addiu      $t0, $t0, 0x1
    /* A1C0 8006D520 2A100501 */  slt        $v0, $t0, $a1
    /* A1C4 8006D524 F6FF4014 */  bnez       $v0, .L8006D500
    /* A1C8 8006D528 02006324 */   addiu     $v1, $v1, 0x2
  .L8006D52C:
    /* A1CC 8006D52C 40100800 */  sll        $v0, $t0, 1
    /* A1D0 8006D530 21104400 */  addu       $v0, $v0, $a0
    /* A1D4 8006D534 0800E003 */  jr         $ra
    /* A1D8 8006D538 000046A4 */   sh        $a2, 0x0($v0)
endlabel Stg20_InsertDescS16
