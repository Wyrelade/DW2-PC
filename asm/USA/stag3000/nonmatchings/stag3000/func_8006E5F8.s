nonmatching func_8006E5F8, 0x3C

glabel func_8006E5F8
    /* B298 8006E5F8 21180000 */  addu       $v1, $zero, $zero
    /* B29C 8006E5FC 0780023C */  lui        $v0, %hi(D_80073A20)
    /* B2A0 8006E600 203A4524 */  addiu      $a1, $v0, %lo(D_80073A20)
  .L8006E604:
    /* B2A4 8006E604 0000A28C */  lw         $v0, 0x0($a1)
    /* B2A8 8006E608 00000000 */  nop
    /* B2AC 8006E60C 07008210 */  beq        $a0, $v0, .L8006E62C
    /* B2B0 8006E610 21106000 */   addu      $v0, $v1, $zero
    /* B2B4 8006E614 01006324 */  addiu      $v1, $v1, 0x1
    /* B2B8 8006E618 0C006228 */  slti       $v0, $v1, 0xC
    /* B2BC 8006E61C F9FF4014 */  bnez       $v0, .L8006E604
    /* B2C0 8006E620 0400A524 */   addiu     $a1, $a1, 0x4
    /* B2C4 8006E624 0800E003 */  jr         $ra
    /* B2C8 8006E628 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006E62C:
    /* B2CC 8006E62C 0800E003 */  jr         $ra
    /* B2D0 8006E630 00000000 */   nop
endlabel func_8006E5F8
