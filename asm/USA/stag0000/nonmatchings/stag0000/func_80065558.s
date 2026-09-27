nonmatching func_80065558, 0x60

glabel func_80065558
    /* 21F8 80065558 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21FC 8006555C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2200 80065560 21808000 */  addu       $s0, $a0, $zero
    /* 2204 80065564 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2208 80065568 1000028E */  lw         $v0, 0x10($s0)
    /* 220C 8006556C 00000000 */  nop
    /* 2210 80065570 0D004014 */  bnez       $v0, .L800655A8
    /* 2214 80065574 0480053C */   lui       $a1, %hi(D_80043704)
    /* 2218 80065578 0437A524 */  addiu      $a1, $a1, %lo(D_80043704)
    /* 221C 8006557C 1083000C */  jal        Actor_InitTransform
    /* 2220 80065580 21300000 */   addu      $a2, $zero, $zero
    /* 2224 80065584 21200002 */  addu       $a0, $s0, $zero
    /* 2228 80065588 6F7F000C */  jal        Gfx_AttachModel
    /* 222C 8006558C 78000524 */   addiu     $a1, $zero, 0x78
    /* 2230 80065590 05000324 */  addiu      $v1, $zero, 0x5
    /* 2234 80065594 3C0043AC */  sw         $v1, 0x3C($v0)
    /* 2238 80065598 7A7D000C */  jal        Gfx_ResetModelBones
    /* 223C 8006559C 21200002 */   addu      $a0, $s0, $zero
    /* 2240 800655A0 5145000C */  jal        Task_NextState0
    /* 2244 800655A4 21200002 */   addu      $a0, $s0, $zero
  .L800655A8:
    /* 2248 800655A8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 224C 800655AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2250 800655B0 0800E003 */  jr         $ra
    /* 2254 800655B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80065558
