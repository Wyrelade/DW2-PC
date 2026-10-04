nonmatching Stg30_TurnOrderClear, 0x2C

glabel Stg30_TurnOrderClear
    /* B1D0 8006E530 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* B1D4 8006E534 0B000324 */  addiu      $v1, $zero, 0xB
    /* B1D8 8006E538 0780023C */  lui        $v0, %hi(Stg30_TurnOrder)
    /* B1DC 8006E53C 203A4224 */  addiu      $v0, $v0, %lo(Stg30_TurnOrder)
    /* B1E0 8006E540 2C004224 */  addiu      $v0, $v0, 0x2C
  .L8006E544:
    /* B1E4 8006E544 000044AC */  sw         $a0, 0x0($v0)
    /* B1E8 8006E548 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* B1EC 8006E54C FDFF6104 */  bgez       $v1, .L8006E544
    /* B1F0 8006E550 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* B1F4 8006E554 0800E003 */  jr         $ra
    /* B1F8 8006E558 00000000 */   nop
endlabel Stg30_TurnOrderClear
