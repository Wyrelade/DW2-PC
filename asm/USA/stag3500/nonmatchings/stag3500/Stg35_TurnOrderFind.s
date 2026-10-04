nonmatching Stg35_TurnOrderFind, 0x3C

glabel Stg35_TurnOrderFind
    /* 2A68 80065DC8 21180000 */  addu       $v1, $zero, $zero
    /* 2A6C 80065DCC 0780023C */  lui        $v0, %hi(Stg35_TurnOrder)
    /* 2A70 80065DD0 58AA4524 */  addiu      $a1, $v0, %lo(Stg35_TurnOrder)
  .L80065DD4:
    /* 2A74 80065DD4 0000A28C */  lw         $v0, 0x0($a1)
    /* 2A78 80065DD8 00000000 */  nop
    /* 2A7C 80065DDC 07008210 */  beq        $a0, $v0, .L80065DFC
    /* 2A80 80065DE0 21106000 */   addu      $v0, $v1, $zero
    /* 2A84 80065DE4 01006324 */  addiu      $v1, $v1, 0x1
    /* 2A88 80065DE8 0C006228 */  slti       $v0, $v1, 0xC
    /* 2A8C 80065DEC F9FF4014 */  bnez       $v0, .L80065DD4
    /* 2A90 80065DF0 0400A524 */   addiu     $a1, $a1, 0x4
    /* 2A94 80065DF4 0800E003 */  jr         $ra
    /* 2A98 80065DF8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80065DFC:
    /* 2A9C 80065DFC 0800E003 */  jr         $ra
    /* 2AA0 80065E00 00000000 */   nop
endlabel Stg35_TurnOrderFind
