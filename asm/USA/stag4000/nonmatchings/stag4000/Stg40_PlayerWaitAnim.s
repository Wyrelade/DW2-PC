nonmatching Stg40_PlayerWaitAnim, 0x44

glabel Stg40_PlayerWaitAnim
    /* 6170 800694D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6174 800694D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6178 800694D8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 617C 800694DC 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 6180 800694E0 21808000 */   addu      $s0, $a0, $zero
    /* 6184 800694E4 01000324 */  addiu      $v1, $zero, 0x1
    /* 6188 800694E8 06004314 */  bne        $v0, $v1, .L80069504
    /* 618C 800694EC 0780023C */   lui       $v0, %hi(D_80072B60)
    /* 6190 800694F0 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 6194 800694F4 00000000 */  nop
    /* 6198 800694F8 38004590 */  lbu        $a1, 0x38($v0)
    /* 619C 800694FC 7745000C */  jal        Task_SetState1
    /* 61A0 80069500 21200002 */   addu      $a0, $s0, $zero
  .L80069504:
    /* 61A4 80069504 1400BF8F */  lw         $ra, 0x14($sp)
    /* 61A8 80069508 1000B08F */  lw         $s0, 0x10($sp)
    /* 61AC 8006950C 0800E003 */  jr         $ra
    /* 61B0 80069510 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_PlayerWaitAnim
