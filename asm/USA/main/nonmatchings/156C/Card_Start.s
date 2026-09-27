nonmatching Card_Start, 0x48

glabel Card_Start
    /* 2DD94 8003D594 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2DD98 8003D598 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2DD9C 8003D59C F19B000C */  jal        EnterCriticalSection
    /* 2DDA0 8003D5A0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2DDA4 8003D5A4 79F6000C */  jal        StartCARD
    /* 2DDA8 8003D5A8 21804000 */   addu      $s0, $v0, $zero
    /* 2DDAC 8003D5AC 31C3000C */  jal        ChangeClearPAD
    /* 2DDB0 8003D5B0 21200000 */   addu      $a0, $zero, $zero
    /* 2DDB4 8003D5B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2DDB8 8003D5B8 04000216 */  bne        $s0, $v0, .L8003D5CC
    /* 2DDBC 8003D5BC 21100000 */   addu      $v0, $zero, $zero
    /* 2DDC0 8003D5C0 F59B000C */  jal        ExitCriticalSection
    /* 2DDC4 8003D5C4 00000000 */   nop
    /* 2DDC8 8003D5C8 21100000 */  addu       $v0, $zero, $zero
  .L8003D5CC:
    /* 2DDCC 8003D5CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2DDD0 8003D5D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DDD4 8003D5D4 0800E003 */  jr         $ra
    /* 2DDD8 8003D5D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Card_Start
