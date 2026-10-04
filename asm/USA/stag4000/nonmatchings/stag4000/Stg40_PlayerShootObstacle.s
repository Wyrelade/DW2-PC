nonmatching Stg40_PlayerShootObstacle, 0x1C8

glabel Stg40_PlayerShootObstacle
    /* 77E8 8006AB48 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 77EC 8006AB4C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 77F0 8006AB50 0780153C */  lui        $s5, %hi(D_80072B60)
    /* 77F4 8006AB54 602BA38E */  lw         $v1, %lo(D_80072B60)($s5)
    /* 77F8 8006AB58 1800B2AF */  sw         $s2, 0x18($sp)
    /* 77FC 8006AB5C 21908000 */  addu       $s2, $a0, $zero
    /* 7800 8006AB60 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7804 8006AB64 01001124 */  addiu      $s1, $zero, 0x1
    /* 7808 8006AB68 2800BFAF */  sw         $ra, 0x28($sp)
    /* 780C 8006AB6C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7810 8006AB70 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7814 8006AB74 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7818 8006AB78 4000708C */  lw         $s0, 0x40($v1)
    /* 781C 8006AB7C 1800448E */  lw         $a0, 0x18($s2)
    /* 7820 8006AB80 08000292 */  lbu        $v0, 0x8($s0)
    /* 7824 8006AB84 3C00748C */  lw         $s4, 0x3C($v1)
    /* 7828 8006AB88 15009110 */  beq        $a0, $s1, .L8006ABE0
    /* 782C 8006AB8C FAFF5324 */   addiu     $s3, $v0, -0x6
    /* 7830 8006AB90 02008228 */  slti       $v0, $a0, 0x2
    /* 7834 8006AB94 05004014 */  bnez       $v0, .L8006ABAC
    /* 7838 8006AB98 02000224 */   addiu     $v0, $zero, 0x2
    /* 783C 8006AB9C 3D008210 */  beq        $a0, $v0, .L8006AC94
    /* 7840 8006ABA0 03000224 */   addiu     $v0, $zero, 0x3
    /* 7844 8006ABA4 41008210 */  beq        $a0, $v0, .L8006ACAC
    /* 7848 8006ABA8 00000000 */   nop
  .L8006ABAC:
    /* 784C 8006ABAC 21204002 */  addu       $a0, $s2, $zero
    /* 7850 8006ABB0 37B9010C */  jal        Stg40_ObjSetAnim
    /* 7854 8006ABB4 2A000524 */   addiu     $a1, $zero, 0x2A
    /* 7858 8006ABB8 0300622A */  slti       $v0, $s3, 0x3
    /* 785C 8006ABBC 02004010 */  beqz       $v0, .L8006ABC8
    /* 7860 8006ABC0 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 7864 8006ABC4 2D000424 */  addiu      $a0, $zero, 0x2D
  .L8006ABC8:
    /* 7868 8006ABC8 A369000C */  jal        Snd_PlayById
    /* 786C 8006ABCC 21280000 */   addu      $a1, $zero, $zero
    /* 7870 8006ABD0 6045000C */  jal        Task_NextState2
    /* 7874 8006ABD4 21204002 */   addu      $a0, $s2, $zero
    /* 7878 8006ABD8 3BAB0108 */  j          .L8006ACEC
    /* 787C 8006ABDC 00000000 */   nop
  .L8006ABE0:
    /* 7880 8006ABE0 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 7884 8006ABE4 21204002 */   addu      $a0, $s2, $zero
    /* 7888 8006ABE8 40005114 */  bne        $v0, $s1, .L8006ACEC
    /* 788C 8006ABEC 21204002 */   addu      $a0, $s2, $zero
    /* 7890 8006ABF0 37B9010C */  jal        Stg40_ObjSetAnim
    /* 7894 8006ABF4 28000524 */   addiu     $a1, $zero, 0x28
    /* 7898 8006ABF8 602BA28E */  lw         $v0, %lo(D_80072B60)($s5)
    /* 789C 8006ABFC 00000000 */  nop
    /* 78A0 8006AC00 E0004490 */  lbu        $a0, 0xE0($v0)
    /* 78A4 8006AC04 3978000C */  jal        Item_GetLevel
    /* 78A8 8006AC08 00000000 */   nop
    /* 78AC 8006AC0C 1000038E */  lw         $v1, 0x10($s0)
    /* 78B0 8006AC10 00000000 */  nop
    /* 78B4 8006AC14 01006390 */  lbu        $v1, 0x1($v1)
    /* 78B8 8006AC18 00000000 */  nop
    /* 78BC 8006AC1C 2A104300 */  slt        $v0, $v0, $v1
    /* 78C0 8006AC20 0E004014 */  bnez       $v0, .L8006AC5C
    /* 78C4 8006AC24 0780033C */   lui       $v1, %hi(Stg40_ShootMsgIds)
    /* 78C8 8006AC28 21208002 */  addu       $a0, $s4, $zero
    /* 78CC 8006AC2C 7745000C */  jal        Task_SetState1
    /* 78D0 8006AC30 06000524 */   addiu     $a1, $zero, 0x6
    /* 78D4 8006AC34 0780033C */  lui        $v1, %hi(Stg40_ShootMsgIds)
    /* 78D8 8006AC38 9C286324 */  addiu      $v1, $v1, %lo(Stg40_ShootMsgIds)
    /* 78DC 8006AC3C C0101300 */  sll        $v0, $s3, 3
    /* 78E0 8006AC40 21104300 */  addu       $v0, $v0, $v1
    /* 78E4 8006AC44 0000508C */  lw         $s0, 0x0($v0)
    /* 78E8 8006AC48 21204002 */  addu       $a0, $s2, $zero
    /* 78EC 8006AC4C 8545000C */  jal        Task_SetState2
    /* 78F0 8006AC50 03000524 */   addiu     $a1, $zero, 0x3
    /* 78F4 8006AC54 1FAB0108 */  j          .L8006AC7C
    /* 78F8 8006AC58 01000424 */   addiu     $a0, $zero, 0x1
  .L8006AC5C:
    /* 78FC 8006AC5C 9C286324 */  addiu      $v1, $v1, %lo(Stg40_ShootMsgIds)
    /* 7900 8006AC60 C0101300 */  sll        $v0, $s3, 3
    /* 7904 8006AC64 04004234 */  ori        $v0, $v0, 0x4
    /* 7908 8006AC68 21104300 */  addu       $v0, $v0, $v1
    /* 790C 8006AC6C 0000508C */  lw         $s0, 0x0($v0)
    /* 7910 8006AC70 6045000C */  jal        Task_NextState2
    /* 7914 8006AC74 21204002 */   addu      $a0, $s2, $zero
    /* 7918 8006AC78 01000424 */  addiu      $a0, $zero, 0x1
  .L8006AC7C:
    /* 791C 8006AC7C 21280002 */  addu       $a1, $s0, $zero
    /* 7920 8006AC80 21300000 */  addu       $a2, $zero, $zero
    /* 7924 8006AC84 849D010C */  jal        Stg40_MsgWinOpen
    /* 7928 8006AC88 2138C000 */   addu      $a3, $a2, $zero
    /* 792C 8006AC8C 3BAB0108 */  j          .L8006ACEC
    /* 7930 8006AC90 00000000 */   nop
  .L8006AC94:
    /* 7934 8006AC94 C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 7938 8006AC98 01000424 */   addiu     $a0, $zero, 0x1
    /* 793C 8006AC9C 13005114 */  bne        $v0, $s1, .L8006ACEC
    /* 7940 8006ACA0 21204002 */   addu      $a0, $s2, $zero
    /* 7944 8006ACA4 33AB0108 */  j          .L8006ACCC
    /* 7948 8006ACA8 00000000 */   nop
  .L8006ACAC:
    /* 794C 8006ACAC C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 7950 8006ACB0 01000424 */   addiu     $a0, $zero, 0x1
    /* 7954 8006ACB4 0D005114 */  bne        $v0, $s1, .L8006ACEC
    /* 7958 8006ACB8 00000000 */   nop
    /* 795C 8006ACBC 0000028E */  lw         $v0, 0x0($s0)
    /* 7960 8006ACC0 00000000 */  nop
    /* 7964 8006ACC4 09004014 */  bnez       $v0, .L8006ACEC
    /* 7968 8006ACC8 21204002 */   addu      $a0, $s2, $zero
  .L8006ACCC:
    /* 796C 8006ACCC 7745000C */  jal        Task_SetState1
    /* 7970 8006ACD0 06000524 */   addiu     $a1, $zero, 0x6
    /* 7974 8006ACD4 0580023C */  lui        $v0, %hi(Save_GameStatePtr)
    /* 7978 8006ACD8 2007428C */  lw         $v0, %lo(Save_GameStatePtr)($v0)
    /* 797C 8006ACDC 602BA38E */  lw         $v1, %lo(D_80072B60)($s5)
    /* 7980 8006ACE0 00004290 */  lbu        $v0, 0x0($v0)
    /* 7984 8006ACE4 00000000 */  nop
    /* 7988 8006ACE8 7E0062A4 */  sh         $v0, 0x7E($v1)
  .L8006ACEC:
    /* 798C 8006ACEC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 7990 8006ACF0 2400B58F */  lw         $s5, 0x24($sp)
    /* 7994 8006ACF4 2000B48F */  lw         $s4, 0x20($sp)
    /* 7998 8006ACF8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 799C 8006ACFC 1800B28F */  lw         $s2, 0x18($sp)
    /* 79A0 8006AD00 1400B18F */  lw         $s1, 0x14($sp)
    /* 79A4 8006AD04 1000B08F */  lw         $s0, 0x10($sp)
    /* 79A8 8006AD08 0800E003 */  jr         $ra
    /* 79AC 8006AD0C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg40_PlayerShootObstacle
