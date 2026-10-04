nonmatching Stg11_VsPartyPick, 0x154

glabel Stg11_VsPartyPick
    /* 36AC 80066A0C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 36B0 80066A10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 36B4 80066A14 21888000 */  addu       $s1, $a0, $zero
    /* 36B8 80066A18 1800BFAF */  sw         $ra, 0x18($sp)
    /* 36BC 80066A1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36C0 80066A20 2C00308E */  lw         $s0, 0x2C($s1)
    /* 36C4 80066A24 00000000 */  nop
    /* 36C8 80066A28 50000426 */  addiu      $a0, $s0, 0x50
    /* 36CC 80066A2C 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 36D0 80066A30 54000526 */   addiu     $a1, $s0, 0x54
    /* 36D4 80066A34 21304000 */  addu       $a2, $v0, $zero
    /* 36D8 80066A38 C0100600 */  sll        $v0, $a2, 3
    /* 36DC 80066A3C 6C004224 */  addiu      $v0, $v0, 0x6C
    /* 36E0 80066A40 21280202 */  addu       $a1, $s0, $v0
    /* 36E4 80066A44 0200A390 */  lbu        $v1, 0x2($a1)
    /* 36E8 80066A48 02000224 */  addiu      $v0, $zero, 0x2
    /* 36EC 80066A4C 05006210 */  beq        $v1, $v0, .L80066A64
    /* 36F0 80066A50 10000424 */   addiu     $a0, $zero, 0x10
    /* 36F4 80066A54 A369000C */  jal        Snd_PlayById
    /* 36F8 80066A58 21280000 */   addu      $a1, $zero, $zero
    /* 36FC 80066A5C D39A0108 */  j          .L80066B4C
    /* 3700 80066A60 00000000 */   nop
  .L80066A64:
    /* 3704 80066A64 A0010292 */  lbu        $v0, 0x1A0($s0)
    /* 3708 80066A68 0E000424 */  addiu      $a0, $zero, 0xE
    /* 370C 80066A6C 03004224 */  addiu      $v0, $v0, 0x3
    /* 3710 80066A70 0200A2A0 */  sb         $v0, 0x2($a1)
    /* 3714 80066A74 A0010296 */  lhu        $v0, 0x1A0($s0)
    /* 3718 80066A78 21280000 */  addu       $a1, $zero, $zero
    /* 371C 80066A7C 01004324 */  addiu      $v1, $v0, 0x1
    /* 3720 80066A80 00140200 */  sll        $v0, $v0, 16
    /* 3724 80066A84 C3130200 */  sra        $v0, $v0, 15
    /* 3728 80066A88 21100202 */  addu       $v0, $s0, $v0
    /* 372C 80066A8C A00103A6 */  sh         $v1, 0x1A0($s0)
    /* 3730 80066A90 A369000C */  jal        Snd_PlayById
    /* 3734 80066A94 A20146A4 */   sh        $a2, 0x1A2($v0)
    /* 3738 80066A98 A0010286 */  lh         $v0, 0x1A0($s0)
    /* 373C 80066A9C 00000000 */  nop
    /* 3740 80066AA0 03004228 */  slti       $v0, $v0, 0x3
    /* 3744 80066AA4 05004010 */  beqz       $v0, .L80066ABC
    /* 3748 80066AA8 21202002 */   addu      $a0, $s1, $zero
    /* 374C 80066AAC 7745000C */  jal        Task_SetState1
    /* 3750 80066AB0 01000524 */   addiu     $a1, $zero, 0x1
    /* 3754 80066AB4 D39A0108 */  j          .L80066B4C
    /* 3758 80066AB8 00000000 */   nop
  .L80066ABC:
    /* 375C 80066ABC 21380000 */  addu       $a3, $zero, $zero
    /* 3760 80066AC0 0780023C */  lui        $v0, %hi(Stg11_VsParty)
    /* 3764 80066AC4 A8844624 */  addiu      $a2, $v0, %lo(Stg11_VsParty)
    /* 3768 80066AC8 21280002 */  addu       $a1, $s0, $zero
  .L80066ACC:
    /* 376C 80066ACC A201A284 */  lh         $v0, 0x1A2($a1)
    /* 3770 80066AD0 00000000 */  nop
    /* 3774 80066AD4 C0100200 */  sll        $v0, $v0, 3
    /* 3778 80066AD8 21100202 */  addu       $v0, $s0, $v0
    /* 377C 80066ADC 7000428C */  lw         $v0, 0x70($v0)
    /* 3780 80066AE0 0400C324 */  addiu      $v1, $a2, 0x4
    /* 3784 80066AE4 50004424 */  addiu      $a0, $v0, 0x50
  .L80066AE8:
    /* 3788 80066AE8 0000488C */  lw         $t0, 0x0($v0)
    /* 378C 80066AEC 0400498C */  lw         $t1, 0x4($v0)
    /* 3790 80066AF0 08004A8C */  lw         $t2, 0x8($v0)
    /* 3794 80066AF4 0C004B8C */  lw         $t3, 0xC($v0)
    /* 3798 80066AF8 000068AC */  sw         $t0, 0x0($v1)
    /* 379C 80066AFC 040069AC */  sw         $t1, 0x4($v1)
    /* 37A0 80066B00 08006AAC */  sw         $t2, 0x8($v1)
    /* 37A4 80066B04 0C006BAC */  sw         $t3, 0xC($v1)
    /* 37A8 80066B08 10004224 */  addiu      $v0, $v0, 0x10
    /* 37AC 80066B0C F6FF4414 */  bne        $v0, $a0, .L80066AE8
    /* 37B0 80066B10 10006324 */   addiu     $v1, $v1, 0x10
    /* 37B4 80066B14 0000488C */  lw         $t0, 0x0($v0)
    /* 37B8 80066B18 0400498C */  lw         $t1, 0x4($v0)
    /* 37BC 80066B1C 08004A8C */  lw         $t2, 0x8($v0)
    /* 37C0 80066B20 000068AC */  sw         $t0, 0x0($v1)
    /* 37C4 80066B24 040069AC */  sw         $t1, 0x4($v1)
    /* 37C8 80066B28 08006AAC */  sw         $t2, 0x8($v1)
    /* 37CC 80066B2C 5C00C624 */  addiu      $a2, $a2, 0x5C
    /* 37D0 80066B30 0100E724 */  addiu      $a3, $a3, 0x1
    /* 37D4 80066B34 0300E228 */  slti       $v0, $a3, 0x3
    /* 37D8 80066B38 E4FF4014 */  bnez       $v0, .L80066ACC
    /* 37DC 80066B3C 0200A524 */   addiu     $a1, $a1, 0x2
    /* 37E0 80066B40 21202002 */  addu       $a0, $s1, $zero
    /* 37E4 80066B44 7045000C */  jal        Task_SetState0
    /* 37E8 80066B48 02000524 */   addiu     $a1, $zero, 0x2
  .L80066B4C:
    /* 37EC 80066B4C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 37F0 80066B50 1400B18F */  lw         $s1, 0x14($sp)
    /* 37F4 80066B54 1000B08F */  lw         $s0, 0x10($sp)
    /* 37F8 80066B58 0800E003 */  jr         $ra
    /* 37FC 80066B5C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_VsPartyPick
