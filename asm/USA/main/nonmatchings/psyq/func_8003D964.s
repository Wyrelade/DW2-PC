/* Handwritten function */
nonmatching func_8003D964, 0x68

glabel func_8003D964
    /* 2E164 8003D964 0680013C */  lui        $at, %hi(D_80062F20)
    /* 2E168 8003D968 202F3FAC */  sw         $ra, %lo(D_80062F20)($at)
    /* 2E16C 8003D96C F19B000C */  jal        EnterCriticalSection
    /* 2E170 8003D970 00000000 */   nop
    /* 2E174 8003D974 57000924 */  addiu      $t1, $zero, 0x57
    /* 2E178 8003D978 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 2E17C 8003D97C 09F84001 */  jalr       $t2
    /* 2E180 8003D980 00000000 */   nop
    /* 2E184 8003D984 09000A24 */  addiu      $t2, $zero, 0x9
    /* 2E188 8003D988 6C01428C */  lw         $v0, 0x16C($v0)
    /* 2E18C 8003D98C 00000000 */  nop
    /* 2E190 8003D990 2C064320 */  addi       $v1, $v0, 0x62C /* handwritten instruction */
  .L8003D994:
    /* 2E194 8003D994 000060AC */  sw         $zero, 0x0($v1)
    /* 2E198 8003D998 04006324 */  addiu      $v1, $v1, 0x4
    /* 2E19C 8003D99C FFFF4A25 */  addiu      $t2, $t2, -0x1
    /* 2E1A0 8003D9A0 FCFF4015 */  bnez       $t2, .L8003D994
    /* 2E1A4 8003D9A4 00000000 */   nop
    /* 2E1A8 8003D9A8 E9B6000C */  jal        FlushCache
    /* 2E1AC 8003D9AC 00000000 */   nop
    /* 2E1B0 8003D9B0 F59B000C */  jal        ExitCriticalSection
    /* 2E1B4 8003D9B4 00000000 */   nop
    /* 2E1B8 8003D9B8 06801F3C */  lui        $ra, %hi(D_80062F20)
    /* 2E1BC 8003D9BC 202FFF8F */  lw         $ra, %lo(D_80062F20)($ra)
    /* 2E1C0 8003D9C0 00000000 */  nop
    /* 2E1C4 8003D9C4 0800E003 */  jr         $ra
    /* 2E1C8 8003D9C8 00000000 */   nop
endlabel func_8003D964
    /* 2E1CC 8003D9CC 00000000 */  nop
    /* 2E1D0 8003D9D0 00000000 */  nop
