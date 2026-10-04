nonmatching Menu_UseItemOnDigi, 0x108

glabel Menu_UseItemOnDigi
    /* 7F7C 8001777C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 7F80 80017780 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 7F84 80017784 21888000 */  addu       $s1, $a0, $zero
    /* 7F88 80017788 3000BFAF */  sw         $ra, 0x30($sp)
    /* 7F8C 8001778C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 7F90 80017790 2C00308E */  lw         $s0, 0x2C($s1)
    /* 7F94 80017794 00000000 */  nop
    /* 7F98 80017798 50000426 */  addiu      $a0, $s0, 0x50
    /* 7F9C 8001779C 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 7FA0 800177A0 54000526 */   addiu     $a1, $s0, 0x54
    /* 7FA4 800177A4 C0100200 */  sll        $v0, $v0, 3
    /* 7FA8 800177A8 6C004224 */  addiu      $v0, $v0, 0x6C
    /* 7FAC 800177AC 0680033C */  lui        $v1, %hi(D_8005F704)
    /* 7FB0 800177B0 04F7638C */  lw         $v1, %lo(D_8005F704)($v1)
    /* 7FB4 800177B4 00000000 */  nop
    /* 7FB8 800177B8 2D006018 */  blez       $v1, .L80017870
    /* 7FBC 800177BC 21300202 */   addu      $a2, $s0, $v0
    /* 7FC0 800177C0 0000C390 */  lbu        $v1, 0x0($a2)
    /* 7FC4 800177C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 7FC8 800177C8 27006214 */  bne        $v1, $v0, .L80017868
    /* 7FCC 800177CC 10000424 */   addiu     $a0, $zero, 0x10
    /* 7FD0 800177D0 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 7FD4 800177D4 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 7FD8 800177D8 0400C78C */  lw         $a3, 0x4($a2)
    /* 7FDC 800177DC 08014484 */  lh         $a0, 0x108($v0)
    /* 7FE0 800177E0 0A014584 */  lh         $a1, 0x10A($v0)
    /* 7FE4 800177E4 DE49000C */  jal        Item_Use
    /* 7FE8 800177E8 21300000 */   addu      $a2, $zero, $zero
    /* 7FEC 800177EC 1D004010 */  beqz       $v0, .L80017864
    /* 7FF0 800177F0 FD01043C */   lui       $a0, (0x1FD00FD >> 16)
    /* 7FF4 800177F4 FD008434 */  ori        $a0, $a0, (0x1FD00FD & 0xFFFF)
    /* 7FF8 800177F8 81000224 */  addiu      $v0, $zero, 0x81
    /* 7FFC 800177FC 1700888B */  lwl        $t0, %gp_rel(D_8005070F)($gp)
    /* 8000 80017800 1400889B */  lwr        $t0, %gp_rel(Menu_DigiMsgPos)($gp)
    /* 8004 80017804 00000000 */  nop
    /* 8008 80017808 1F00A8AB */  swl        $t0, 0x1F($sp)
    /* 800C 8001780C 1C00A8BB */  swr        $t0, 0x1C($sp)
    /* 8010 80017810 2100A0A3 */  sb         $zero, 0x21($sp)
    /* 8014 80017814 688E000C */  jal        Cd_GetFileEntry
    /* 8018 80017818 2000A2A3 */   sb        $v0, 0x20($sp)
    /* 801C 8001781C 0580033C */  lui        $v1, %hi(Menu_Ctx)
    /* 8020 80017820 6807638C */  lw         $v1, %lo(Menu_Ctx)($v1)
    /* 8024 80017824 1000A2AF */  sw         $v0, 0x10($sp)
    /* 8028 80017828 08016484 */  lh         $a0, 0x108($v1)
    /* 802C 8001782C 1278000C */  jal        Item_GetNameText
    /* 8030 80017830 00000000 */   nop
    /* 8034 80017834 40000426 */  addiu      $a0, $s0, 0x40
    /* 8038 80017838 1000A527 */  addiu      $a1, $sp, 0x10
    /* 803C 8001783C 1C4D000C */  jal        Text_OpenDesc
    /* 8040 80017840 1400A2AF */   sw        $v0, 0x14($sp)
    /* 8044 80017844 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 8048 80017848 A369000C */  jal        Snd_PlayById
    /* 804C 8001784C 21280000 */   addu      $a1, $zero, $zero
    /* 8050 80017850 21202002 */  addu       $a0, $s1, $zero
    /* 8054 80017854 7745000C */  jal        Task_SetState1
    /* 8058 80017858 04000524 */   addiu     $a1, $zero, 0x4
    /* 805C 8001785C 1C5E0008 */  j          .L80017870
    /* 8060 80017860 00000000 */   nop
  .L80017864:
    /* 8064 80017864 10000424 */  addiu      $a0, $zero, 0x10
  .L80017868:
    /* 8068 80017868 A369000C */  jal        Snd_PlayById
    /* 806C 8001786C 21280000 */   addu      $a1, $zero, $zero
  .L80017870:
    /* 8070 80017870 3000BF8F */  lw         $ra, 0x30($sp)
    /* 8074 80017874 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 8078 80017878 2800B08F */  lw         $s0, 0x28($sp)
    /* 807C 8001787C 0800E003 */  jr         $ra
    /* 8080 80017880 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Menu_UseItemOnDigi
