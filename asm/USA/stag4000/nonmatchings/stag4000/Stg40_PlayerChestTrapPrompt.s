nonmatching Stg40_PlayerChestTrapPrompt, 0x17C

glabel Stg40_PlayerChestTrapPrompt
    /* 7138 8006A498 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 713C 8006A49C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7140 8006A4A0 0780123C */  lui        $s2, %hi(Stg40_RootState)
    /* 7144 8006A4A4 602B428E */  lw         $v0, %lo(Stg40_RootState)($s2)
    /* 7148 8006A4A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 714C 8006A4AC 21808000 */  addu       $s0, $a0, $zero
    /* 7150 8006A4B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7154 8006A4B4 01001124 */  addiu      $s1, $zero, 0x1
    /* 7158 8006A4B8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 715C 8006A4BC 4000428C */  lw         $v0, 0x40($v0)
    /* 7160 8006A4C0 1800038E */  lw         $v1, 0x18($s0)
    /* 7164 8006A4C4 1000448C */  lw         $a0, 0x10($v0)
    /* 7168 8006A4C8 0F007110 */  beq        $v1, $s1, .L8006A508
    /* 716C 8006A4CC 02006228 */   slti      $v0, $v1, 0x2
    /* 7170 8006A4D0 05004014 */  bnez       $v0, .L8006A4E8
    /* 7174 8006A4D4 02000224 */   addiu     $v0, $zero, 0x2
    /* 7178 8006A4D8 13006210 */  beq        $v1, $v0, .L8006A528
    /* 717C 8006A4DC 03000224 */   addiu     $v0, $zero, 0x3
    /* 7180 8006A4E0 36006210 */  beq        $v1, $v0, .L8006A5BC
    /* 7184 8006A4E4 00000000 */   nop
  .L8006A4E8:
    /* 7188 8006A4E8 2E000424 */  addiu      $a0, $zero, 0x2E
    /* 718C 8006A4EC A369000C */  jal        Snd_PlayById
    /* 7190 8006A4F0 21280000 */   addu      $a1, $zero, $zero
    /* 7194 8006A4F4 21200002 */  addu       $a0, $s0, $zero
    /* 7198 8006A4F8 37B9010C */  jal        Stg40_ObjSetAnim
    /* 719C 8006A4FC 2D000524 */   addiu     $a1, $zero, 0x2D
    /* 71A0 8006A500 6BA90108 */  j          .L8006A5AC
    /* 71A4 8006A504 00000000 */   nop
  .L8006A508:
    /* 71A8 8006A508 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 71AC 8006A50C 21200002 */   addu      $a0, $s0, $zero
    /* 71B0 8006A510 3A005114 */  bne        $v0, $s1, .L8006A5FC
    /* 71B4 8006A514 21200002 */   addu      $a0, $s0, $zero
    /* 71B8 8006A518 37B9010C */  jal        Stg40_ObjSetAnim
    /* 71BC 8006A51C 28000524 */   addiu     $a1, $zero, 0x28
    /* 71C0 8006A520 6BA90108 */  j          .L8006A5AC
    /* 71C4 8006A524 00000000 */   nop
  .L8006A528:
    /* 71C8 8006A528 01008390 */  lbu        $v1, 0x1($a0)
    /* 71CC 8006A52C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 71D0 8006A530 03006214 */  bne        $v1, $v0, .L8006A540
    /* 71D4 8006A534 15000524 */   addiu     $a1, $zero, 0x15
    /* 71D8 8006A538 7DA90108 */  j          .L8006A5F4
    /* 71DC 8006A53C 21200002 */   addu      $a0, $s0, $zero
  .L8006A540:
    /* 71E0 8006A540 2A006010 */  beqz       $v1, .L8006A5EC
    /* 71E4 8006A544 00000000 */   nop
    /* 71E8 8006A548 01008490 */  lbu        $a0, 0x1($a0)
    /* 71EC 8006A54C 81C4010C */  jal        Stg40_GetTrapDisarmRank
    /* 71F0 8006A550 00000000 */   nop
    /* 71F4 8006A554 602B438E */  lw         $v1, %lo(Stg40_RootState)($s2)
    /* 71F8 8006A558 07000424 */  addiu      $a0, $zero, 0x7
    /* 71FC 8006A55C 77C5010C */  jal        Stg40_GetPartState
    /* 7200 8006A560 500062AC */   sw        $v0, 0x50($v1)
    /* 7204 8006A564 602B438E */  lw         $v1, %lo(Stg40_RootState)($s2)
    /* 7208 8006A568 FD01043C */  lui        $a0, (0x1FD0040 >> 16)
    /* 720C 8006A56C 5000638C */  lw         $v1, 0x50($v1)
    /* 7210 8006A570 40008434 */  ori        $a0, $a0, (0x1FD0040 & 0xFFFF)
    /* 7214 8006A574 21286400 */  addu       $a1, $v1, $a0
    /* 7218 8006A578 21184000 */  addu       $v1, $v0, $zero
    /* 721C 8006A57C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 7220 8006A580 03006214 */  bne        $v1, $v0, .L8006A590
    /* 7224 8006A584 00000000 */   nop
    /* 7228 8006A588 FD01053C */  lui        $a1, (0x1FD0045 >> 16)
    /* 722C 8006A58C 4500A534 */  ori        $a1, $a1, (0x1FD0045 & 0xFFFF)
  .L8006A590:
    /* 7230 8006A590 03006014 */  bnez       $v1, .L8006A5A0
    /* 7234 8006A594 01000424 */   addiu     $a0, $zero, 0x1
    /* 7238 8006A598 FD01053C */  lui        $a1, (0x1FD0046 >> 16)
    /* 723C 8006A59C 4600A534 */  ori        $a1, $a1, (0x1FD0046 & 0xFFFF)
  .L8006A5A0:
    /* 7240 8006A5A0 21300000 */  addu       $a2, $zero, $zero
    /* 7244 8006A5A4 849D010C */  jal        Stg40_MsgWinOpen
    /* 7248 8006A5A8 2138C000 */   addu      $a3, $a2, $zero
  .L8006A5AC:
    /* 724C 8006A5AC 6045000C */  jal        Task_NextState2
    /* 7250 8006A5B0 21200002 */   addu      $a0, $s0, $zero
    /* 7254 8006A5B4 7FA90108 */  j          .L8006A5FC
    /* 7258 8006A5B8 00000000 */   nop
  .L8006A5BC:
    /* 725C 8006A5BC D49D010C */  jal        Stg40_MsgWinGetChoice
    /* 7260 8006A5C0 01000424 */   addiu     $a0, $zero, 0x1
    /* 7264 8006A5C4 21184000 */  addu       $v1, $v0, $zero
    /* 7268 8006A5C8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 726C 8006A5CC 05006210 */  beq        $v1, $v0, .L8006A5E4
    /* 7270 8006A5D0 21200002 */   addu      $a0, $s0, $zero
    /* 7274 8006A5D4 06007110 */  beq        $v1, $s1, .L8006A5F0
    /* 7278 8006A5D8 00000000 */   nop
    /* 727C 8006A5DC 7FA90108 */  j          .L8006A5FC
    /* 7280 8006A5E0 00000000 */   nop
  .L8006A5E4:
    /* 7284 8006A5E4 7DA90108 */  j          .L8006A5F4
    /* 7288 8006A5E8 06000524 */   addiu     $a1, $zero, 0x6
  .L8006A5EC:
    /* 728C 8006A5EC 21200002 */  addu       $a0, $s0, $zero
  .L8006A5F0:
    /* 7290 8006A5F0 14000524 */  addiu      $a1, $zero, 0x14
  .L8006A5F4:
    /* 7294 8006A5F4 7745000C */  jal        Task_SetState1
    /* 7298 8006A5F8 00000000 */   nop
  .L8006A5FC:
    /* 729C 8006A5FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 72A0 8006A600 1800B28F */  lw         $s2, 0x18($sp)
    /* 72A4 8006A604 1400B18F */  lw         $s1, 0x14($sp)
    /* 72A8 8006A608 1000B08F */  lw         $s0, 0x10($sp)
    /* 72AC 8006A60C 0800E003 */  jr         $ra
    /* 72B0 8006A610 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_PlayerChestTrapPrompt
