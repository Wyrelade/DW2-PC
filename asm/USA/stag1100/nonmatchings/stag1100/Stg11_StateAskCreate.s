nonmatching Stg11_StateAskCreate, 0xE0

glabel Stg11_StateAskCreate
    /* 1D48 800650A8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D4C 800650AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1D50 800650B0 21908000 */  addu       $s2, $a0, $zero
    /* 1D54 800650B4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1D58 800650B8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D5C 800650BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1D60 800650C0 1800428E */  lw         $v0, 0x18($s2)
    /* 1D64 800650C4 00000000 */  nop
    /* 1D68 800650C8 04004014 */  bnez       $v0, .L800650DC
    /* 1D6C 800650CC 2188A000 */   addu      $s1, $a1, $zero
    /* 1D70 800650D0 84002586 */  lh         $a1, 0x84($s1)
    /* 1D74 800650D4 EB9D010C */  jal        Stg11_CardStartOp
    /* 1D78 800650D8 04000424 */   addiu     $a0, $zero, 0x4
  .L800650DC:
    /* 1D7C 800650DC 21204002 */  addu       $a0, $s2, $zero
    /* 1D80 800650E0 7E92010C */  jal        Stg11_WatchCardRemoved
    /* 1D84 800650E4 21282002 */   addu      $a1, $s1, $zero
    /* 1D88 800650E8 21004014 */  bnez       $v0, .L80065170
    /* 1D8C 800650EC 00000000 */   nop
    /* 1D90 800650F0 1800508E */  lw         $s0, 0x18($s2)
    /* 1D94 800650F4 00000000 */  nop
    /* 1D98 800650F8 03000012 */  beqz       $s0, .L80065108
    /* 1D9C 800650FC 01000224 */   addiu     $v0, $zero, 0x1
    /* 1DA0 80065100 0C000212 */  beq        $s0, $v0, .L80065134
    /* 1DA4 80065104 00000000 */   nop
  .L80065108:
    /* 1DA8 80065108 21202002 */  addu       $a0, $s1, $zero
    /* 1DAC 8006510C 3992010C */  jal        Stg11_SetStatusMsg
    /* 1DB0 80065110 6E010524 */   addiu     $a1, $zero, 0x16E
    /* 1DB4 80065114 21202002 */  addu       $a0, $s1, $zero
    /* 1DB8 80065118 76010524 */  addiu      $a1, $zero, 0x176
    /* 1DBC 8006511C 5792010C */  jal        Stg11_SetPromptMsg
    /* 1DC0 80065120 01000624 */   addiu     $a2, $zero, 0x1
    /* 1DC4 80065124 6045000C */  jal        Task_NextState2
    /* 1DC8 80065128 21204002 */   addu      $a0, $s2, $zero
    /* 1DCC 8006512C 5C940108 */  j          .L80065170
    /* 1DD0 80065130 00000000 */   nop
  .L80065134:
    /* 1DD4 80065134 0400248E */  lw         $a0, 0x4($s1)
    /* 1DD8 80065138 A94D000C */  jal        Text_WaitYesNo
    /* 1DDC 8006513C 00000000 */   nop
    /* 1DE0 80065140 21184000 */  addu       $v1, $v0, $zero
    /* 1DE4 80065144 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1DE8 80065148 07006210 */  beq        $v1, $v0, .L80065168
    /* 1DEC 8006514C 21204002 */   addu      $a0, $s2, $zero
    /* 1DF0 80065150 07007014 */  bne        $v1, $s0, .L80065170
    /* 1DF4 80065154 00000000 */   nop
    /* 1DF8 80065158 7745000C */  jal        Task_SetState1
    /* 1DFC 8006515C 05000524 */   addiu     $a1, $zero, 0x5
    /* 1E00 80065160 5C940108 */  j          .L80065170
    /* 1E04 80065164 00000000 */   nop
  .L80065168:
    /* 1E08 80065168 7045000C */  jal        Task_SetState0
    /* 1E0C 8006516C 02000524 */   addiu     $a1, $zero, 0x2
  .L80065170:
    /* 1E10 80065170 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1E14 80065174 1800B28F */  lw         $s2, 0x18($sp)
    /* 1E18 80065178 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E1C 8006517C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E20 80065180 0800E003 */  jr         $ra
    /* 1E24 80065184 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_StateAskCreate
