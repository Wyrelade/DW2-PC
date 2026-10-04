nonmatching Stg40_HudDraw, 0x114

glabel Stg40_HudDraw
    /* 3770 80066AD0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3774 80066AD4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3778 80066AD8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 377C 80066ADC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3780 80066AE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3784 80066AE4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3788 80066AE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 378C 80066AEC 2C00928C */  lw         $s2, 0x2C($a0)
    /* 3790 80066AF0 00000000 */  nop
    /* 3794 80066AF4 0C00428E */  lw         $v0, 0xC($s2)
    /* 3798 80066AF8 00000000 */  nop
    /* 379C 80066AFC 31004010 */  beqz       $v0, .L80066BC4
    /* 37A0 80066B00 21880000 */   addu      $s1, $zero, $zero
    /* 37A4 80066B04 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 37A8 80066B08 20E65424 */  addiu      $s4, $v0, %lo(Save_GameState)
    /* 37AC 80066B0C 0780023C */  lui        $v0, %hi(Stg40_HudParts)
    /* 37B0 80066B10 C0265324 */  addiu      $s3, $v0, %lo(Stg40_HudParts)
  .L80066B14:
    /* 37B4 80066B14 0000648E */  lw         $a0, 0x0($s3)
    /* 37B8 80066B18 688E000C */  jal        Cd_GetFileEntry
    /* 37BC 80066B1C 00000000 */   nop
    /* 37C0 80066B20 04002012 */  beqz       $s1, .L80066B34
    /* 37C4 80066B24 21804000 */   addu      $s0, $v0, $zero
    /* 37C8 80066B28 01000224 */  addiu      $v0, $zero, 0x1
    /* 37CC 80066B2C 17002212 */  beq        $s1, $v0, .L80066B8C
    /* 37D0 80066B30 00000000 */   nop
  .L80066B34:
    /* 37D4 80066B34 21200002 */  addu       $a0, $s0, $zero
    /* 37D8 80066B38 02000524 */  addiu      $a1, $zero, 0x2
    /* 37DC 80066B3C 26008786 */  lh         $a3, 0x26($s4)
    /* 37E0 80066B40 6D75000C */  jal        Gfx_SetPartsNumber
    /* 37E4 80066B44 04000624 */   addiu     $a2, $zero, 0x4
    /* 37E8 80066B48 21200002 */  addu       $a0, $s0, $zero
    /* 37EC 80066B4C 04000524 */  addiu      $a1, $zero, 0x4
    /* 37F0 80066B50 12004786 */  lh         $a3, 0x12($s2)
    /* 37F4 80066B54 6D75000C */  jal        Gfx_SetPartsNumber
    /* 37F8 80066B58 2130A000 */   addu      $a2, $a1, $zero
    /* 37FC 80066B5C 21200002 */  addu       $a0, $s0, $zero
    /* 3800 80066B60 08000524 */  addiu      $a1, $zero, 0x8
    /* 3804 80066B64 2A008786 */  lh         $a3, 0x2A($s4)
    /* 3808 80066B68 6D75000C */  jal        Gfx_SetPartsNumber
    /* 380C 80066B6C 04000624 */   addiu     $a2, $zero, 0x4
    /* 3810 80066B70 21200002 */  addu       $a0, $s0, $zero
    /* 3814 80066B74 10000524 */  addiu      $a1, $zero, 0x10
    /* 3818 80066B78 14004786 */  lh         $a3, 0x14($s2)
    /* 381C 80066B7C 6D75000C */  jal        Gfx_SetPartsNumber
    /* 3820 80066B80 04000624 */   addiu     $a2, $zero, 0x4
    /* 3824 80066B84 E79A0108 */  j          .L80066B9C
    /* 3828 80066B88 21200002 */   addu      $a0, $s0, $zero
  .L80066B8C:
    /* 382C 80066B8C 10004586 */  lh         $a1, 0x10($s2)
    /* 3830 80066B90 4175000C */  jal        Gfx_HidePartsByMask
    /* 3834 80066B94 21200002 */   addu      $a0, $s0, $zero
    /* 3838 80066B98 21200002 */  addu       $a0, $s0, $zero
  .L80066B9C:
    /* 383C 80066B9C 00100524 */  addiu      $a1, $zero, 0x1000
    /* 3840 80066BA0 0C00468E */  lw         $a2, 0xC($s2)
    /* 3844 80066BA4 04007326 */  addiu      $s3, $s3, 0x4
    /* 3848 80066BA8 5475000C */  jal        Gfx_SetPartsScale
    /* 384C 80066BAC 01003126 */   addiu     $s1, $s1, 0x1
    /* 3850 80066BB0 2176000C */  jal        Gfx_DrawParts
    /* 3854 80066BB4 21200002 */   addu      $a0, $s0, $zero
    /* 3858 80066BB8 0200222A */  slti       $v0, $s1, 0x2
    /* 385C 80066BBC D5FF4014 */  bnez       $v0, .L80066B14
    /* 3860 80066BC0 00000000 */   nop
  .L80066BC4:
    /* 3864 80066BC4 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3868 80066BC8 2000B48F */  lw         $s4, 0x20($sp)
    /* 386C 80066BCC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3870 80066BD0 1800B28F */  lw         $s2, 0x18($sp)
    /* 3874 80066BD4 1400B18F */  lw         $s1, 0x14($sp)
    /* 3878 80066BD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 387C 80066BDC 0800E003 */  jr         $ra
    /* 3880 80066BE0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_HudDraw
