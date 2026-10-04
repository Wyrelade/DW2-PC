nonmatching Stg35_TurnOrderRemove, 0x44

glabel Stg35_TurnOrderRemove
    /* 2A24 80065D84 0B008228 */  slti       $v0, $a0, 0xB
    /* 2A28 80065D88 0D004010 */  beqz       $v0, .L80065DC0
    /* 2A2C 80065D8C 0780023C */   lui       $v0, %hi(Stg35_TurnOrder)
    /* 2A30 80065D90 58AA4524 */  addiu      $a1, $v0, %lo(Stg35_TurnOrder)
    /* 2A34 80065D94 80180400 */  sll        $v1, $a0, 2
  .L80065D98:
    /* 2A38 80065D98 01008224 */  addiu      $v0, $a0, 0x1
    /* 2A3C 80065D9C 21204000 */  addu       $a0, $v0, $zero
    /* 2A40 80065DA0 80100400 */  sll        $v0, $a0, 2
    /* 2A44 80065DA4 21104500 */  addu       $v0, $v0, $a1
    /* 2A48 80065DA8 0000428C */  lw         $v0, 0x0($v0)
    /* 2A4C 80065DAC 21186500 */  addu       $v1, $v1, $a1
    /* 2A50 80065DB0 000062AC */  sw         $v0, 0x0($v1)
    /* 2A54 80065DB4 0B008228 */  slti       $v0, $a0, 0xB
    /* 2A58 80065DB8 F7FF4014 */  bnez       $v0, .L80065D98
    /* 2A5C 80065DBC 80180400 */   sll       $v1, $a0, 2
  .L80065DC0:
    /* 2A60 80065DC0 0800E003 */  jr         $ra
    /* 2A64 80065DC4 00000000 */   nop
endlabel Stg35_TurnOrderRemove
