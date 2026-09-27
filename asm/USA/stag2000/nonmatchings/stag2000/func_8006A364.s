nonmatching func_8006A364, 0x6C

glabel func_8006A364
    /* 7004 8006A364 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7008 8006A368 1000B0AF */  sw         $s0, 0x10($sp)
    /* 700C 8006A36C 21808000 */  addu       $s0, $a0, $zero
    /* 7010 8006A370 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7014 8006A374 1000028E */  lw         $v0, 0x10($s0)
    /* 7018 8006A378 00000000 */  nop
    /* 701C 8006A37C 10004014 */  bnez       $v0, .L8006A3C0
    /* 7020 8006A380 0480053C */   lui       $a1, %hi(D_80043704)
    /* 7024 8006A384 0437A524 */  addiu      $a1, $a1, %lo(D_80043704)
    /* 7028 8006A388 1083000C */  jal        Actor_InitTransform
    /* 702C 8006A38C 21300000 */   addu      $a2, $zero, $zero
    /* 7030 8006A390 21200002 */  addu       $a0, $s0, $zero
    /* 7034 8006A394 6F7F000C */  jal        Gfx_AttachModel
    /* 7038 8006A398 140D0524 */   addiu     $a1, $zero, 0xD14
    /* 703C 8006A39C 21200002 */  addu       $a0, $s0, $zero
    /* 7040 8006A3A0 05000324 */  addiu      $v1, $zero, 0x5
    /* 7044 8006A3A4 7A7D000C */  jal        Gfx_ResetModelBones
    /* 7048 8006A3A8 3C0043AC */   sw        $v1, 0x3C($v0)
    /* 704C 8006A3AC 21200002 */  addu       $a0, $s0, $zero
    /* 7050 8006A3B0 3800838C */  lw         $v1, 0x38($a0)
    /* 7054 8006A3B4 00020224 */  addiu      $v0, $zero, 0x200
    /* 7058 8006A3B8 5145000C */  jal        Task_NextState0
    /* 705C 8006A3BC 420062A4 */   sh        $v0, 0x42($v1)
  .L8006A3C0:
    /* 7060 8006A3C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7064 8006A3C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 7068 8006A3C8 0800E003 */  jr         $ra
    /* 706C 8006A3CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A364
