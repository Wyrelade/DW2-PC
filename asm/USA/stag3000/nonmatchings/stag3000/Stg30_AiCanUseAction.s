nonmatching Stg30_AiCanUseAction, 0x90

glabel Stg30_AiCanUseAction
    /* 5A44 80068DA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5A48 80068DA8 2130C500 */  addu       $a2, $a2, $a1
    /* 5A4C 80068DAC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5A50 80068DB0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5A54 80068DB4 0900C390 */  lbu        $v1, 0x9($a2)
    /* 5A58 80068DB8 00000000 */  nop
    /* 5A5C 80068DBC 18006010 */  beqz       $v1, .L80068E20
    /* 5A60 80068DC0 04006228 */   slti      $v0, $v1, 0x4
    /* 5A64 80068DC4 06004014 */  bnez       $v0, .L80068DE0
    /* 5A68 80068DC8 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 5A6C 80068DCC 04000224 */  addiu      $v0, $zero, 0x4
    /* 5A70 80068DD0 11006210 */  beq        $v1, $v0, .L80068E18
    /* 5A74 80068DD4 21100000 */   addu      $v0, $zero, $zero
    /* 5A78 80068DD8 89A30108 */  j          .L80068E24
    /* 5A7C 80068DDC 00000000 */   nop
  .L80068DE0:
    /* 5A80 80068DE0 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 5A84 80068DE4 40180400 */  sll        $v1, $a0, 1
    /* 5A88 80068DE8 21186400 */  addu       $v1, $v1, $a0
    /* 5A8C 80068DEC C0180300 */  sll        $v1, $v1, 3
    /* 5A90 80068DF0 23186400 */  subu       $v1, $v1, $a0
    /* 5A94 80068DF4 80180300 */  sll        $v1, $v1, 2
    /* 5A98 80068DF8 21186200 */  addu       $v1, $v1, $v0
    /* 5A9C 80068DFC 0200C490 */  lbu        $a0, 0x2($a2)
    /* 5AA0 80068E00 32007084 */  lh         $s0, 0x32($v1)
    /* 5AA4 80068E04 A07B000C */  jal        Skill_GetMpCost
    /* 5AA8 80068E08 00000000 */   nop
    /* 5AAC 80068E0C 2A800202 */  slt        $s0, $s0, $v0
    /* 5AB0 80068E10 04000012 */  beqz       $s0, .L80068E24
    /* 5AB4 80068E14 01000224 */   addiu     $v0, $zero, 0x1
  .L80068E18:
    /* 5AB8 80068E18 89A30108 */  j          .L80068E24
    /* 5ABC 80068E1C 01000224 */   addiu     $v0, $zero, 0x1
  .L80068E20:
    /* 5AC0 80068E20 21100000 */  addu       $v0, $zero, $zero
  .L80068E24:
    /* 5AC4 80068E24 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5AC8 80068E28 1000B08F */  lw         $s0, 0x10($sp)
    /* 5ACC 80068E2C 0800E003 */  jr         $ra
    /* 5AD0 80068E30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_AiCanUseAction
