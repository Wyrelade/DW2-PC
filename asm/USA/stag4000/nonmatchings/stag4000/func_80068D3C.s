nonmatching func_80068D3C, 0x84

glabel func_80068D3C
    /* 59DC 80068D3C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 59E0 80068D40 1400B1AF */  sw         $s1, 0x14($sp)
    /* 59E4 80068D44 21888000 */  addu       $s1, $a0, $zero
    /* 59E8 80068D48 1800BFAF */  sw         $ra, 0x18($sp)
    /* 59EC 80068D4C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 59F0 80068D50 2C00228E */  lw         $v0, 0x2C($s1)
    /* 59F4 80068D54 00000000 */  nop
    /* 59F8 80068D58 2C00508C */  lw         $s0, 0x2C($v0)
    /* 59FC 80068D5C 3AB9010C */  jal        func_8006E4E8
    /* 5A00 80068D60 28000524 */   addiu     $a1, $zero, 0x28
    /* 5A04 80068D64 25C3010C */  jal        func_80070C94
    /* 5A08 80068D68 00000000 */   nop
    /* 5A0C 80068D6C 00140200 */  sll        $v0, $v0, 16
    /* 5A10 80068D70 07000392 */  lbu        $v1, 0x7($s0)
    /* 5A14 80068D74 03140200 */  sra        $v0, $v0, 16
    /* 5A18 80068D78 0C004314 */  bne        $v0, $v1, .L80068DAC
    /* 5A1C 80068D7C 00000000 */   nop
    /* 5A20 80068D80 4D94010C */  jal        func_80065134
    /* 5A24 80068D84 18000426 */   addiu     $a0, $s0, 0x18
    /* 5A28 80068D88 CCB8010C */  jal        func_8006E330
    /* 5A2C 80068D8C 00000000 */   nop
    /* 5A30 80068D90 03004010 */  beqz       $v0, .L80068DA0
    /* 5A34 80068D94 21202002 */   addu      $a0, $s1, $zero
    /* 5A38 80068D98 69A30108 */  j          .L80068DA4
    /* 5A3C 80068D9C 04000524 */   addiu     $a1, $zero, 0x4
  .L80068DA0:
    /* 5A40 80068DA0 01000524 */  addiu      $a1, $zero, 0x1
  .L80068DA4:
    /* 5A44 80068DA4 7745000C */  jal        Task_SetState1
    /* 5A48 80068DA8 00000000 */   nop
  .L80068DAC:
    /* 5A4C 80068DAC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5A50 80068DB0 1400B18F */  lw         $s1, 0x14($sp)
    /* 5A54 80068DB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 5A58 80068DB8 0800E003 */  jr         $ra
    /* 5A5C 80068DBC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80068D3C
