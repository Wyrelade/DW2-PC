nonmatching Stg30_CommandMenuDraw, 0x10C

glabel Stg30_CommandMenuDraw
    /* 1C94 80064FF4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C98 80064FF8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C9C 80064FFC 21888000 */  addu       $s1, $a0, $zero
    /* 1CA0 80065000 A101043C */  lui        $a0, (0x1A10009 >> 16)
    /* 1CA4 80065004 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1CA8 80065008 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1CAC 8006500C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CB0 80065010 2C00308E */  lw         $s0, 0x2C($s1)
    /* 1CB4 80065014 688E000C */  jal        Cd_GetFileEntry
    /* 1CB8 80065018 09008434 */   ori       $a0, $a0, (0x1A10009 & 0xFFFF)
    /* 1CBC 8006501C 21904000 */  addu       $s2, $v0, $zero
    /* 1CC0 80065020 21204002 */  addu       $a0, $s2, $zero
    /* 1CC4 80065024 00000686 */  lh         $a2, 0x0($s0)
    /* 1CC8 80065028 5475000C */  jal        Gfx_SetPartsScale
    /* 1CCC 8006502C 00100524 */   addiu     $a1, $zero, 0x1000
    /* 1CD0 80065030 0000428E */  lw         $v0, 0x0($s2)
    /* 1CD4 80065034 00000000 */  nop
    /* 1CD8 80065038 29004010 */  beqz       $v0, .L800650E0
    /* 1CDC 8006503C 21284002 */   addu      $a1, $s2, $zero
    /* 1CE0 80065040 6EFF0824 */  addiu      $t0, $zero, -0x92
    /* 1CE4 80065044 0780073C */  lui        $a3, %hi(Stg30_CommandMenuCursor)
    /* 1CE8 80065048 0780023C */  lui        $v0, %hi(Stg30_CursorBlinkPalettes)
    /* 1CEC 8006504C 70304624 */  addiu      $a2, $v0, %lo(Stg30_CursorBlinkPalettes)
    /* 1CF0 80065050 0C004426 */  addiu      $a0, $s2, 0xC
  .L80065054:
    /* 1CF4 80065054 1000828C */  lw         $v0, 0x10($a0)
    /* 1CF8 80065058 00000000 */  nop
    /* 1CFC 8006505C 02004230 */  andi       $v0, $v0, 0x2
    /* 1D00 80065060 1A004010 */  beqz       $v0, .L800650CC
    /* 1D04 80065064 00000000 */   nop
    /* 1D08 80065068 E037E38C */  lw         $v1, %lo(Stg30_CommandMenuCursor)($a3)
    /* 1D0C 8006506C F8FF88A4 */  sh         $t0, -0x8($a0)
    /* 1D10 80065070 40100300 */  sll        $v0, $v1, 1
    /* 1D14 80065074 21104300 */  addu       $v0, $v0, $v1
    /* 1D18 80065078 80100200 */  sll        $v0, $v0, 2
    /* 1D1C 8006507C 23104300 */  subu       $v0, $v0, $v1
    /* 1D20 80065080 CDFF4224 */  addiu      $v0, $v0, -0x33
    /* 1D24 80065084 FAFF82A4 */  sh         $v0, -0x6($a0)
  .L80065088:
    /* 1D28 80065088 2800238E */  lw         $v1, 0x28($s1)
    /* 1D2C 8006508C 00000000 */  nop
    /* 1D30 80065090 18006228 */  slti       $v0, $v1, 0x18
    /* 1D34 80065094 03004014 */  bnez       $v0, .L800650A4
    /* 1D38 80065098 E8FF6224 */   addiu     $v0, $v1, -0x18
    /* 1D3C 8006509C 22940108 */  j          .L80065088
    /* 1D40 800650A0 280022AE */   sw        $v0, 0x28($s1)
  .L800650A4:
    /* 1D44 800650A4 2800228E */  lw         $v0, 0x28($s1)
    /* 1D48 800650A8 00000000 */  nop
    /* 1D4C 800650AC 02004104 */  bgez       $v0, .L800650B8
    /* 1D50 800650B0 00000000 */   nop
    /* 1D54 800650B4 03004224 */  addiu      $v0, $v0, 0x3
  .L800650B8:
    /* 1D58 800650B8 83100200 */  sra        $v0, $v0, 2
    /* 1D5C 800650BC 21104600 */  addu       $v0, $v0, $a2
    /* 1D60 800650C0 00004290 */  lbu        $v0, 0x0($v0)
    /* 1D64 800650C4 00000000 */  nop
    /* 1D68 800650C8 000082A0 */  sb         $v0, 0x0($a0)
  .L800650CC:
    /* 1D6C 800650CC 2800A524 */  addiu      $a1, $a1, 0x28
    /* 1D70 800650D0 0000A28C */  lw         $v0, 0x0($a1)
    /* 1D74 800650D4 00000000 */  nop
    /* 1D78 800650D8 DEFF4014 */  bnez       $v0, .L80065054
    /* 1D7C 800650DC 28008424 */   addiu     $a0, $a0, 0x28
  .L800650E0:
    /* 1D80 800650E0 2176000C */  jal        Gfx_DrawParts
    /* 1D84 800650E4 21204002 */   addu      $a0, $s2, $zero
    /* 1D88 800650E8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1D8C 800650EC 1800B28F */  lw         $s2, 0x18($sp)
    /* 1D90 800650F0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1D94 800650F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D98 800650F8 0800E003 */  jr         $ra
    /* 1D9C 800650FC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_CommandMenuDraw
