nonmatching func_8006A254, 0xCC

glabel func_8006A254
    /* 6EF4 8006A254 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EF8 8006A258 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6EFC 8006A25C 21808000 */  addu       $s0, $a0, $zero
    /* 6F00 8006A260 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6F04 8006A264 1000038E */  lw         $v1, 0x10($s0)
    /* 6F08 8006A268 01000224 */  addiu      $v0, $zero, 0x1
    /* 6F0C 8006A26C 13006210 */  beq        $v1, $v0, .L8006A2BC
    /* 6F10 8006A270 02006228 */   slti      $v0, $v1, 0x2
    /* 6F14 8006A274 26004010 */  beqz       $v0, .L8006A310
    /* 6F18 8006A278 00000000 */   nop
    /* 6F1C 8006A27C 24006014 */  bnez       $v1, .L8006A310
    /* 6F20 8006A280 0480053C */   lui       $a1, %hi(Gfx_ZeroVector)
    /* 6F24 8006A284 0437A524 */  addiu      $a1, $a1, %lo(Gfx_ZeroVector)
    /* 6F28 8006A288 1083000C */  jal        Actor_InitTransform
    /* 6F2C 8006A28C 21300000 */   addu      $a2, $zero, $zero
    /* 6F30 8006A290 21200002 */  addu       $a0, $s0, $zero
    /* 6F34 8006A294 6F7F000C */  jal        Gfx_AttachModel
    /* 6F38 8006A298 5B000524 */   addiu     $a1, $zero, 0x5B
    /* 6F3C 8006A29C 04000324 */  addiu      $v1, $zero, 0x4
    /* 6F40 8006A2A0 3C0043AC */  sw         $v1, 0x3C($v0)
    /* 6F44 8006A2A4 7A7D000C */  jal        Gfx_ResetModelBones
    /* 6F48 8006A2A8 21200002 */   addu      $a0, $s0, $zero
    /* 6F4C 8006A2AC 5145000C */  jal        Task_NextState0
    /* 6F50 8006A2B0 21200002 */   addu      $a0, $s0, $zero
    /* 6F54 8006A2B4 C4A80108 */  j          .L8006A310
    /* 6F58 8006A2B8 00000000 */   nop
  .L8006A2BC:
    /* 6F5C 8006A2BC 2C00028E */  lw         $v0, 0x2C($s0)
    /* 6F60 8006A2C0 00000000 */  nop
    /* 6F64 8006A2C4 0000448C */  lw         $a0, 0x0($v0)
    /* 6F68 8006A2C8 00000000 */  nop
    /* 6F6C 8006A2CC 10008010 */  beqz       $a0, .L8006A310
    /* 6F70 8006A2D0 00000000 */   nop
    /* 6F74 8006A2D4 1000828C */  lw         $v0, 0x10($a0)
    /* 6F78 8006A2D8 00000000 */  nop
    /* 6F7C 8006A2DC 0C004010 */  beqz       $v0, .L8006A310
    /* 6F80 8006A2E0 00000000 */   nop
    /* 6F84 8006A2E4 3800038E */  lw         $v1, 0x38($s0)
    /* 6F88 8006A2E8 3800828C */  lw         $v0, 0x38($a0)
    /* 6F8C 8006A2EC 00000000 */  nop
    /* 6F90 8006A2F0 3000478C */  lw         $a3, 0x30($v0)
    /* 6F94 8006A2F4 3400488C */  lw         $t0, 0x34($v0)
    /* 6F98 8006A2F8 3800498C */  lw         $t1, 0x38($v0)
    /* 6F9C 8006A2FC 3C004A8C */  lw         $t2, 0x3C($v0)
    /* 6FA0 8006A300 300067AC */  sw         $a3, 0x30($v1)
    /* 6FA4 8006A304 340068AC */  sw         $t0, 0x34($v1)
    /* 6FA8 8006A308 380069AC */  sw         $t1, 0x38($v1)
    /* 6FAC 8006A30C 3C006AAC */  sw         $t2, 0x3C($v1)
  .L8006A310:
    /* 6FB0 8006A310 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6FB4 8006A314 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FB8 8006A318 0800E003 */  jr         $ra
    /* 6FBC 8006A31C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A254
