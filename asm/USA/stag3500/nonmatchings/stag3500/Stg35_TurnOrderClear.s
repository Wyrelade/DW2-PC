nonmatching Stg35_TurnOrderClear, 0x2C

glabel Stg35_TurnOrderClear
    /* 29A0 80065D00 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 29A4 80065D04 0B000324 */  addiu      $v1, $zero, 0xB
    /* 29A8 80065D08 0780023C */  lui        $v0, %hi(Stg35_TurnOrder)
    /* 29AC 80065D0C 58AA4224 */  addiu      $v0, $v0, %lo(Stg35_TurnOrder)
    /* 29B0 80065D10 2C004224 */  addiu      $v0, $v0, 0x2C
  .L80065D14:
    /* 29B4 80065D14 000044AC */  sw         $a0, 0x0($v0)
    /* 29B8 80065D18 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 29BC 80065D1C FDFF6104 */  bgez       $v1, .L80065D14
    /* 29C0 80065D20 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 29C4 80065D24 0800E003 */  jr         $ra
    /* 29C8 80065D28 00000000 */   nop
endlabel Stg35_TurnOrderClear
