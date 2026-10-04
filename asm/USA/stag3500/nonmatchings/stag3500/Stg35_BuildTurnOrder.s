nonmatching Stg35_BuildTurnOrder, 0x12C

glabel Stg35_BuildTurnOrder
    /* 2B00 80065E60 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2B04 80065E64 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2B08 80065E68 21900000 */  addu       $s2, $zero, $zero
    /* 2B0C 80065E6C 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2B10 80065E70 1000B127 */  addiu      $s1, $sp, 0x10
    /* 2B14 80065E74 0780023C */  lui        $v0, %hi(Stg35_Battle)
    /* 2B18 80065E78 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2B1C 80065E7C 88AA5024 */  addiu      $s0, $v0, %lo(Stg35_Battle)
    /* 2B20 80065E80 3400BFAF */  sw         $ra, 0x34($sp)
  .L80065E84:
    /* 2B24 80065E84 26000286 */  lh         $v0, 0x26($s0)
    /* 2B28 80065E88 00000000 */  nop
    /* 2B2C 80065E8C 13004010 */  beqz       $v0, .L80065EDC
    /* 2B30 80065E90 00000000 */   nop
    /* 2B34 80065E94 448E000C */  jal        Rand_Next
    /* 2B38 80065E98 00000000 */   nop
    /* 2B3C 80065E9C FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2B40 80065EA0 2EBA033C */  lui        $v1, (0xBA2E8BA3 >> 16)
    /* 2B44 80065EA4 A38B6334 */  ori        $v1, $v1, (0xBA2E8BA3 & 0xFFFF)
    /* 2B48 80065EA8 19004300 */  multu      $v0, $v1
    /* 2B4C 80065EAC 10380000 */  mfhi       $a3
    /* 2B50 80065EB0 C2200700 */  srl        $a0, $a3, 3
    /* 2B54 80065EB4 40180400 */  sll        $v1, $a0, 1
    /* 2B58 80065EB8 21186400 */  addu       $v1, $v1, $a0
    /* 2B5C 80065EBC 80180300 */  sll        $v1, $v1, 2
    /* 2B60 80065EC0 23186400 */  subu       $v1, $v1, $a0
    /* 2B64 80065EC4 23104300 */  subu       $v0, $v0, $v1
    /* 2B68 80065EC8 30000386 */  lh         $v1, 0x30($s0)
    /* 2B6C 80065ECC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2B70 80065ED0 21186200 */  addu       $v1, $v1, $v0
    /* 2B74 80065ED4 B8970108 */  j          .L80065EE0
    /* 2B78 80065ED8 000023AE */   sw        $v1, 0x0($s1)
  .L80065EDC:
    /* 2B7C 80065EDC 000020AE */  sw         $zero, 0x0($s1)
  .L80065EE0:
    /* 2B80 80065EE0 04003126 */  addiu      $s1, $s1, 0x4
    /* 2B84 80065EE4 01005226 */  addiu      $s2, $s2, 0x1
    /* 2B88 80065EE8 0600422A */  slti       $v0, $s2, 0x6
    /* 2B8C 80065EEC E5FF4014 */  bnez       $v0, .L80065E84
    /* 2B90 80065EF0 5C001026 */   addiu     $s0, $s0, 0x5C
    /* 2B94 80065EF4 4097010C */  jal        Stg35_TurnOrderClear
    /* 2B98 80065EF8 21900000 */   addu      $s2, $zero, $zero
    /* 2B9C 80065EFC 1000B127 */  addiu      $s1, $sp, 0x10
    /* 2BA0 80065F00 21300000 */  addu       $a2, $zero, $zero
  .L80065F04:
    /* 2BA4 80065F04 2180C000 */  addu       $s0, $a2, $zero
    /* 2BA8 80065F08 2120C000 */  addu       $a0, $a2, $zero
    /* 2BAC 80065F0C 21282002 */  addu       $a1, $s1, $zero
  .L80065F10:
    /* 2BB0 80065F10 0000A38C */  lw         $v1, 0x0($a1)
    /* 2BB4 80065F14 00000000 */  nop
    /* 2BB8 80065F18 05006010 */  beqz       $v1, .L80065F30
    /* 2BBC 80065F1C 2A10C300 */   slt       $v0, $a2, $v1
    /* 2BC0 80065F20 03004010 */  beqz       $v0, .L80065F30
    /* 2BC4 80065F24 00000000 */   nop
    /* 2BC8 80065F28 21306000 */  addu       $a2, $v1, $zero
    /* 2BCC 80065F2C 21808000 */  addu       $s0, $a0, $zero
  .L80065F30:
    /* 2BD0 80065F30 01008424 */  addiu      $a0, $a0, 0x1
    /* 2BD4 80065F34 06008228 */  slti       $v0, $a0, 0x6
    /* 2BD8 80065F38 F5FF4014 */  bnez       $v0, .L80065F10
    /* 2BDC 80065F3C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 2BE0 80065F40 0C00C010 */  beqz       $a2, .L80065F74
    /* 2BE4 80065F44 00000000 */   nop
    /* 2BE8 80065F48 8197010C */  jal        Stg35_TurnOrderFreeIndex
    /* 2BEC 80065F4C 01005226 */   addiu     $s2, $s2, 0x1
    /* 2BF0 80065F50 21204000 */  addu       $a0, $v0, $zero
    /* 2BF4 80065F54 4B97010C */  jal        Stg35_TurnOrderInsert
    /* 2BF8 80065F58 21280002 */   addu      $a1, $s0, $zero
    /* 2BFC 80065F5C 80101000 */  sll        $v0, $s0, 2
    /* 2C00 80065F60 21102202 */  addu       $v0, $s1, $v0
    /* 2C04 80065F64 000040AC */  sw         $zero, 0x0($v0)
    /* 2C08 80065F68 0600422A */  slti       $v0, $s2, 0x6
    /* 2C0C 80065F6C E5FF4014 */  bnez       $v0, .L80065F04
    /* 2C10 80065F70 21300000 */   addu      $a2, $zero, $zero
  .L80065F74:
    /* 2C14 80065F74 3400BF8F */  lw         $ra, 0x34($sp)
    /* 2C18 80065F78 3000B28F */  lw         $s2, 0x30($sp)
    /* 2C1C 80065F7C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 2C20 80065F80 2800B08F */  lw         $s0, 0x28($sp)
    /* 2C24 80065F84 0800E003 */  jr         $ra
    /* 2C28 80065F88 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg35_BuildTurnOrder
