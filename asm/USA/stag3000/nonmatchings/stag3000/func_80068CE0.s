nonmatching func_80068CE0, 0xC4

glabel func_80068CE0
    /* 5980 80068CE0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5984 80068CE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5988 80068CE8 21808000 */  addu       $s0, $a0, $zero
    /* 598C 80068CEC 21380000 */  addu       $a3, $zero, $zero
    /* 5990 80068CF0 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 5994 80068CF4 20E64624 */  addiu      $a2, $v0, %lo(Save_GameState)
    /* 5998 80068CF8 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* 599C 80068CFC C03C4424 */  addiu      $a0, $v0, %lo(D_80073CC0)
    /* 59A0 80068D00 1400BFAF */  sw         $ra, 0x14($sp)
  .L80068D04:
    /* 59A4 80068D04 18008290 */  lbu        $v0, 0x18($a0)
    /* 59A8 80068D08 00000000 */  nop
    /* 59AC 80068D0C 0300422C */  sltiu      $v0, $v0, 0x3
    /* 59B0 80068D10 14004014 */  bnez       $v0, .L80068D64
    /* 59B4 80068D14 E400C324 */   addiu     $v1, $a2, 0xE4
    /* 59B8 80068D18 18008224 */  addiu      $v0, $a0, 0x18
    /* 59BC 80068D1C 68008524 */  addiu      $a1, $a0, 0x68
  .L80068D20:
    /* 59C0 80068D20 0000488C */  lw         $t0, 0x0($v0)
    /* 59C4 80068D24 0400498C */  lw         $t1, 0x4($v0)
    /* 59C8 80068D28 08004A8C */  lw         $t2, 0x8($v0)
    /* 59CC 80068D2C 0C004B8C */  lw         $t3, 0xC($v0)
    /* 59D0 80068D30 000068AC */  sw         $t0, 0x0($v1)
    /* 59D4 80068D34 040069AC */  sw         $t1, 0x4($v1)
    /* 59D8 80068D38 08006AAC */  sw         $t2, 0x8($v1)
    /* 59DC 80068D3C 0C006BAC */  sw         $t3, 0xC($v1)
    /* 59E0 80068D40 10004224 */  addiu      $v0, $v0, 0x10
    /* 59E4 80068D44 F6FF4514 */  bne        $v0, $a1, .L80068D20
    /* 59E8 80068D48 10006324 */   addiu     $v1, $v1, 0x10
    /* 59EC 80068D4C 0000488C */  lw         $t0, 0x0($v0)
    /* 59F0 80068D50 0400498C */  lw         $t1, 0x4($v0)
    /* 59F4 80068D54 08004A8C */  lw         $t2, 0x8($v0)
    /* 59F8 80068D58 000068AC */  sw         $t0, 0x0($v1)
    /* 59FC 80068D5C 040069AC */  sw         $t1, 0x4($v1)
    /* 5A00 80068D60 08006AAC */  sw         $t2, 0x8($v1)
  .L80068D64:
    /* 5A04 80068D64 5C00C624 */  addiu      $a2, $a2, 0x5C
    /* 5A08 80068D68 0100E724 */  addiu      $a3, $a3, 0x1
    /* 5A0C 80068D6C 0300E228 */  slti       $v0, $a3, 0x3
    /* 5A10 80068D70 E4FF4014 */  bnez       $v0, .L80068D04
    /* 5A14 80068D74 5C008424 */   addiu     $a0, $a0, 0x5C
    /* 5A18 80068D78 40010424 */  addiu      $a0, $zero, 0x140
    /* 5A1C 80068D7C F0000524 */  addiu      $a1, $zero, 0xF0
    /* 5A20 80068D80 21300000 */  addu       $a2, $zero, $zero
    /* 5A24 80068D84 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 5A28 80068D88 2138C000 */   addu      $a3, $a2, $zero
    /* 5A2C 80068D8C 5C44000C */  jal        Task_DefaultDestroy
    /* 5A30 80068D90 21200002 */   addu      $a0, $s0, $zero
    /* 5A34 80068D94 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5A38 80068D98 1000B08F */  lw         $s0, 0x10($sp)
    /* 5A3C 80068D9C 0800E003 */  jr         $ra
    /* 5A40 80068DA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80068CE0
