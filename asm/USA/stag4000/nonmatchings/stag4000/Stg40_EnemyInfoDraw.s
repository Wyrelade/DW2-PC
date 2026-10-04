nonmatching Stg40_EnemyInfoDraw, 0x108

glabel Stg40_EnemyInfoDraw
    /* 40F4 80067454 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 40F8 80067458 2800BFAF */  sw         $ra, 0x28($sp)
    /* 40FC 8006745C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 4100 80067460 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4104 80067464 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4108 80067468 1800B2AF */  sw         $s2, 0x18($sp)
    /* 410C 8006746C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4110 80067470 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4114 80067474 2C00958C */  lw         $s5, 0x2C($a0)
    /* 4118 80067478 00000000 */  nop
    /* 411C 8006747C 0000A28E */  lw         $v0, 0x0($s5)
    /* 4120 80067480 00000000 */  nop
    /* 4124 80067484 2C004010 */  beqz       $v0, .L80067538
    /* 4128 80067488 0780023C */   lui       $v0, %hi(Stg40_RootState)
    /* 412C 8006748C 602B438C */  lw         $v1, %lo(Stg40_RootState)($v0)
    /* 4130 80067490 00000000 */  nop
    /* 4134 80067494 AC00628C */  lw         $v0, 0xAC($v1)
    /* 4138 80067498 21880000 */  addu       $s1, $zero, $zero
    /* 413C 8006749C 80100200 */  sll        $v0, $v0, 2
    /* 4140 800674A0 21186200 */  addu       $v1, $v1, $v0
    /* 4144 800674A4 8000628C */  lw         $v0, 0x80($v1)
    /* 4148 800674A8 0780033C */  lui        $v1, %hi(Stg40_EnemyInfoParts)
    /* 414C 800674AC 1000548C */  lw         $s4, 0x10($v0)
    /* 4150 800674B0 50277324 */  addiu      $s3, $v1, %lo(Stg40_EnemyInfoParts)
    /* 4154 800674B4 21908002 */  addu       $s2, $s4, $zero
  .L800674B8:
    /* 4158 800674B8 0000648E */  lw         $a0, 0x0($s3)
    /* 415C 800674BC 688E000C */  jal        Cd_GetFileEntry
    /* 4160 800674C0 00000000 */   nop
    /* 4164 800674C4 0B008392 */  lbu        $v1, 0xB($s4)
    /* 4168 800674C8 00000000 */  nop
    /* 416C 800674CC 2A182302 */  slt        $v1, $s1, $v1
    /* 4170 800674D0 06006014 */  bnez       $v1, .L800674EC
    /* 4174 800674D4 21804000 */   addu      $s0, $v0, $zero
    /* 4178 800674D8 21200002 */  addu       $a0, $s0, $zero
    /* 417C 800674DC 4175000C */  jal        Gfx_HidePartsByMask
    /* 4180 800674E0 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 4184 800674E4 479D0108 */  j          .L8006751C
    /* 4188 800674E8 00000000 */   nop
  .L800674EC:
    /* 418C 800674EC 21200002 */  addu       $a0, $s0, $zero
    /* 4190 800674F0 02000524 */  addiu      $a1, $zero, 0x2
    /* 4194 800674F4 16004786 */  lh         $a3, 0x16($s2)
    /* 4198 800674F8 6D75000C */  jal        Gfx_SetPartsNumber
    /* 419C 800674FC 2130A000 */   addu      $a2, $a1, $zero
    /* 41A0 80067500 21200002 */  addu       $a0, $s0, $zero
    /* 41A4 80067504 4175000C */  jal        Gfx_HidePartsByMask
    /* 41A8 80067508 21280000 */   addu      $a1, $zero, $zero
    /* 41AC 8006750C 21200002 */  addu       $a0, $s0, $zero
    /* 41B0 80067510 0000A68E */  lw         $a2, 0x0($s5)
    /* 41B4 80067514 5475000C */  jal        Gfx_SetPartsScale
    /* 41B8 80067518 00100524 */   addiu     $a1, $zero, 0x1000
  .L8006751C:
    /* 41BC 8006751C 2176000C */  jal        Gfx_DrawParts
    /* 41C0 80067520 21200002 */   addu      $a0, $s0, $zero
    /* 41C4 80067524 02005226 */  addiu      $s2, $s2, 0x2
    /* 41C8 80067528 01003126 */  addiu      $s1, $s1, 0x1
    /* 41CC 8006752C 0300222A */  slti       $v0, $s1, 0x3
    /* 41D0 80067530 E1FF4014 */  bnez       $v0, .L800674B8
    /* 41D4 80067534 04007326 */   addiu     $s3, $s3, 0x4
  .L80067538:
    /* 41D8 80067538 2800BF8F */  lw         $ra, 0x28($sp)
    /* 41DC 8006753C 2400B58F */  lw         $s5, 0x24($sp)
    /* 41E0 80067540 2000B48F */  lw         $s4, 0x20($sp)
    /* 41E4 80067544 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 41E8 80067548 1800B28F */  lw         $s2, 0x18($sp)
    /* 41EC 8006754C 1400B18F */  lw         $s1, 0x14($sp)
    /* 41F0 80067550 1000B08F */  lw         $s0, 0x10($sp)
    /* 41F4 80067554 0800E003 */  jr         $ra
    /* 41F8 80067558 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg40_EnemyInfoDraw
