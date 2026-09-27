nonmatching func_800699F8, 0x4C

glabel func_800699F8
    /* 6698 800699F8 10008510 */  beq        $a0, $a1, .L80069A3C
    /* 669C 800699FC 21100000 */   addu      $v0, $zero, $zero
    /* 66A0 80069A00 03008014 */  bnez       $a0, .L80069A10
    /* 66A4 80069A04 01000224 */   addiu     $v0, $zero, 0x1
    /* 66A8 80069A08 0C00A210 */  beq        $a1, $v0, .L80069A3C
    /* 66AC 80069A0C 00000000 */   nop
  .L80069A10:
    /* 66B0 80069A10 05008214 */  bne        $a0, $v0, .L80069A28
    /* 66B4 80069A14 02000224 */   addiu     $v0, $zero, 0x2
    /* 66B8 80069A18 0300A214 */  bne        $a1, $v0, .L80069A28
    /* 66BC 80069A1C 00000000 */   nop
    /* 66C0 80069A20 0800E003 */  jr         $ra
    /* 66C4 80069A24 01000224 */   addiu     $v0, $zero, 0x1
  .L80069A28:
    /* 66C8 80069A28 04008214 */  bne        $a0, $v0, .L80069A3C
    /* 66CC 80069A2C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 66D0 80069A30 0200A010 */  beqz       $a1, .L80069A3C
    /* 66D4 80069A34 01000224 */   addiu     $v0, $zero, 0x1
    /* 66D8 80069A38 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80069A3C:
    /* 66DC 80069A3C 0800E003 */  jr         $ra
    /* 66E0 80069A40 00000000 */   nop
endlabel func_800699F8
