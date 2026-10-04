nonmatching func_800635D4, 0x68

glabel func_800635D4
    /* 274 800635D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 278 800635D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 27C 800635DC 21808000 */  addu       $s0, $a0, $zero
    /* 280 800635E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 284 800635E4 1000028E */  lw         $v0, 0x10($s0)
    /* 288 800635E8 00000000 */  nop
    /* 28C 800635EC 0F004014 */  bnez       $v0, .L8006362C
    /* 290 800635F0 0480053C */   lui       $a1, %hi(Gfx_ZeroVector)
    /* 294 800635F4 0437A524 */  addiu      $a1, $a1, %lo(Gfx_ZeroVector)
    /* 298 800635F8 770D0224 */  addiu      $v0, $zero, 0xD77
    /* 29C 800635FC 21300000 */  addu       $a2, $zero, $zero
    /* 2A0 80063600 1083000C */  jal        Actor_InitTransform
    /* 2A4 80063604 0C0002AE */   sw        $v0, 0xC($s0)
    /* 2A8 80063608 0C00058E */  lw         $a1, 0xC($s0)
    /* 2AC 8006360C 6F7F000C */  jal        Gfx_AttachModel
    /* 2B0 80063610 21200002 */   addu      $a0, $s0, $zero
    /* 2B4 80063614 21200002 */  addu       $a0, $s0, $zero
    /* 2B8 80063618 05000324 */  addiu      $v1, $zero, 0x5
    /* 2BC 8006361C 7A7D000C */  jal        Gfx_ResetModelBones
    /* 2C0 80063620 3C0043AC */   sw        $v1, 0x3C($v0)
    /* 2C4 80063624 5145000C */  jal        Task_NextState0
    /* 2C8 80063628 21200002 */   addu      $a0, $s0, $zero
  .L8006362C:
    /* 2CC 8006362C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2D0 80063630 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D4 80063634 0800E003 */  jr         $ra
    /* 2D8 80063638 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800635D4
