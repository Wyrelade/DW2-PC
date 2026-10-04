nonmatching Stg40_PlayerRunEvent, 0x100

glabel Stg40_PlayerRunEvent
    /* 7FC0 8006B320 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7FC4 8006B324 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7FC8 8006B328 21888000 */  addu       $s1, $a0, $zero
    /* 7FCC 8006B32C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7FD0 8006B330 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7FD4 8006B334 1800238E */  lw         $v1, 0x18($s1)
    /* 7FD8 8006B338 01000224 */  addiu      $v0, $zero, 0x1
    /* 7FDC 8006B33C 16006210 */  beq        $v1, $v0, .L8006B398
    /* 7FE0 8006B340 02006228 */   slti      $v0, $v1, 0x2
    /* 7FE4 8006B344 03004014 */  bnez       $v0, .L8006B354
    /* 7FE8 8006B348 02000224 */   addiu     $v0, $zero, 0x2
    /* 7FEC 8006B34C 1E006210 */  beq        $v1, $v0, .L8006B3C8
    /* 7FF0 8006B350 00000000 */   nop
  .L8006B354:
    /* 7FF4 8006B354 21202002 */  addu       $a0, $s1, $zero
    /* 7FF8 8006B358 37B9010C */  jal        Stg40_ObjSetAnim
    /* 7FFC 8006B35C 28000524 */   addiu     $a1, $zero, 0x28
    /* 8000 8006B360 0780103C */  lui        $s0, %hi(D_80072B60)
    /* 8004 8006B364 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 8008 8006B368 00000000 */  nop
    /* 800C 8006B36C 7001448C */  lw         $a0, 0x170($v0)
    /* 8010 8006B370 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 8014 8006B374 780140AC */  sw         $zero, 0x178($v0)
    /* 8018 8006B378 4579000C */  jal        Flag_SelectBranch
    /* 801C 8006B37C 740143AC */   sw        $v1, 0x174($v0)
    /* 8020 8006B380 602B048E */  lw         $a0, %lo(D_80072B60)($s0)
    /* 8024 8006B384 21284000 */  addu       $a1, $v0, $zero
    /* 8028 8006B388 0E70000C */  jal        Text_OpenMsgClearChoice
    /* 802C 8006B38C 74018424 */   addiu     $a0, $a0, 0x174
    /* 8030 8006B390 EEAC0108 */  j          .L8006B3B8
    /* 8034 8006B394 00000000 */   nop
  .L8006B398:
    /* 8038 8006B398 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 803C 8006B39C 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 8040 8006B3A0 00000000 */  nop
    /* 8044 8006B3A4 7401448C */  lw         $a0, 0x174($v0)
    /* 8048 8006B3A8 826F000C */  jal        Text_IsFinished
    /* 804C 8006B3AC 00000000 */   nop
    /* 8050 8006B3B0 16004010 */  beqz       $v0, .L8006B40C
    /* 8054 8006B3B4 00000000 */   nop
  .L8006B3B8:
    /* 8058 8006B3B8 6045000C */  jal        Task_NextState2
    /* 805C 8006B3BC 21202002 */   addu      $a0, $s1, $zero
    /* 8060 8006B3C0 03AD0108 */  j          .L8006B40C
    /* 8064 8006B3C4 00000000 */   nop
  .L8006B3C8:
    /* 8068 8006B3C8 12C3010C */  jal        Stg40_TurnQueueNext
    /* 806C 8006B3CC 00000000 */   nop
    /* 8070 8006B3D0 21202002 */  addu       $a0, $s1, $zero
    /* 8074 8006B3D4 7745000C */  jal        Task_SetState1
    /* 8078 8006B3D8 21280000 */   addu      $a1, $zero, $zero
    /* 807C 8006B3DC CCB8010C */  jal        Stg40_CheckEncounter
    /* 8080 8006B3E0 00000000 */   nop
    /* 8084 8006B3E4 05004010 */  beqz       $v0, .L8006B3FC
    /* 8088 8006B3E8 21202002 */   addu      $a0, $s1, $zero
    /* 808C 8006B3EC 7745000C */  jal        Task_SetState1
    /* 8090 8006B3F0 04000524 */   addiu     $a1, $zero, 0x4
    /* 8094 8006B3F4 03AD0108 */  j          .L8006B40C
    /* 8098 8006B3F8 00000000 */   nop
  .L8006B3FC:
    /* 809C 8006B3FC 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 80A0 8006B400 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 80A4 8006B404 00000000 */  nop
    /* 80A8 8006B408 020040A0 */  sb         $zero, 0x2($v0)
  .L8006B40C:
    /* 80AC 8006B40C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 80B0 8006B410 1400B18F */  lw         $s1, 0x14($sp)
    /* 80B4 8006B414 1000B08F */  lw         $s0, 0x10($sp)
    /* 80B8 8006B418 0800E003 */  jr         $ra
    /* 80BC 8006B41C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_PlayerRunEvent
