nonmatching Stg40_ItemMenuRefresh, 0x164

glabel Stg40_ItemMenuRefresh
    /* 79B0 8006AD10 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 79B4 8006AD14 2000B4AF */  sw         $s4, 0x20($sp)
    /* 79B8 8006AD18 0780143C */  lui        $s4, %hi(D_80072B60)
    /* 79BC 8006AD1C 602B828E */  lw         $v0, %lo(D_80072B60)($s4)
    /* 79C0 8006AD20 2800BFAF */  sw         $ra, 0x28($sp)
    /* 79C4 8006AD24 2400B5AF */  sw         $s5, 0x24($sp)
    /* 79C8 8006AD28 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 79CC 8006AD2C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 79D0 8006AD30 1400B1AF */  sw         $s1, 0x14($sp)
    /* 79D4 8006AD34 1000B0AF */  sw         $s0, 0x10($sp)
    /* 79D8 8006AD38 E2004390 */  lbu        $v1, 0xE2($v0)
    /* 79DC 8006AD3C E3004290 */  lbu        $v0, 0xE3($v0)
    /* 79E0 8006AD40 21980000 */  addu       $s3, $zero, $zero
    /* 79E4 8006AD44 869B010C */  jal        Stg40_ItemMenuGetTextIds
    /* 79E8 8006AD48 23806200 */   subu      $s0, $v1, $v0
    /* 79EC 8006AD4C 21A84000 */  addu       $s5, $v0, $zero
    /* 79F0 8006AD50 0600022A */  slti       $v0, $s0, 0x6
    /* 79F4 8006AD54 07004014 */  bnez       $v0, .L8006AD74
    /* 79F8 8006AD58 2190A002 */   addu      $s2, $s5, $zero
    /* 79FC 8006AD5C 602B838E */  lw         $v1, %lo(D_80072B60)($s4)
    /* 7A00 8006AD60 00000000 */  nop
    /* 7A04 8006AD64 E2006290 */  lbu        $v0, 0xE2($v1)
    /* 7A08 8006AD68 00000000 */  nop
    /* 7A0C 8006AD6C FBFF4224 */  addiu      $v0, $v0, -0x5
    /* 7A10 8006AD70 E30062A0 */  sb         $v0, 0xE3($v1)
  .L8006AD74:
    /* 7A14 8006AD74 06000106 */  bgez       $s0, .L8006AD90
    /* 7A18 8006AD78 00000000 */   nop
    /* 7A1C 8006AD7C 602B838E */  lw         $v1, %lo(D_80072B60)($s4)
    /* 7A20 8006AD80 00000000 */  nop
    /* 7A24 8006AD84 E2006290 */  lbu        $v0, 0xE2($v1)
    /* 7A28 8006AD88 00000000 */  nop
    /* 7A2C 8006AD8C E30062A0 */  sb         $v0, 0xE3($v1)
  .L8006AD90:
    /* 7A30 8006AD90 602B828E */  lw         $v0, %lo(D_80072B60)($s4)
    /* 7A34 8006AD94 00000000 */  nop
    /* 7A38 8006AD98 E1004390 */  lbu        $v1, 0xE1($v0)
    /* 7A3C 8006AD9C E3004490 */  lbu        $a0, 0xE3($v0)
    /* 7A40 8006ADA0 21886000 */  addu       $s1, $v1, $zero
    /* 7A44 8006ADA4 06008324 */  addiu      $v1, $a0, 0x6
    /* 7A48 8006ADA8 2A102302 */  slt        $v0, $s1, $v1
    /* 7A4C 8006ADAC 02004014 */  bnez       $v0, .L8006ADB8
    /* 7A50 8006ADB0 21808000 */   addu      $s0, $a0, $zero
    /* 7A54 8006ADB4 21886000 */  addu       $s1, $v1, $zero
  .L8006ADB8:
    /* 7A58 8006ADB8 2A101102 */  slt        $v0, $s0, $s1
    /* 7A5C 8006ADBC 0B004010 */  beqz       $v0, .L8006ADEC
    /* 7A60 8006ADC0 00000000 */   nop
  .L8006ADC4:
    /* 7A64 8006ADC4 602B828E */  lw         $v0, %lo(D_80072B60)($s4)
    /* 7A68 8006ADC8 00000000 */  nop
    /* 7A6C 8006ADCC 21105000 */  addu       $v0, $v0, $s0
    /* 7A70 8006ADD0 B0004490 */  lbu        $a0, 0xB0($v0)
    /* 7A74 8006ADD4 1278000C */  jal        Item_GetNameText
    /* 7A78 8006ADD8 01001026 */   addiu     $s0, $s0, 0x1
    /* 7A7C 8006ADDC 000042AE */  sw         $v0, 0x0($s2)
    /* 7A80 8006ADE0 2A101102 */  slt        $v0, $s0, $s1
    /* 7A84 8006ADE4 F7FF4014 */  bnez       $v0, .L8006ADC4
    /* 7A88 8006ADE8 04005226 */   addiu     $s2, $s2, 0x4
  .L8006ADEC:
    /* 7A8C 8006ADEC 0780103C */  lui        $s0, %hi(D_80072B60)
    /* 7A90 8006ADF0 602B058E */  lw         $a1, %lo(D_80072B60)($s0)
    /* 7A94 8006ADF4 00000000 */  nop
    /* 7A98 8006ADF8 E300A290 */  lbu        $v0, 0xE3($a1)
    /* 7A9C 8006ADFC E100A390 */  lbu        $v1, 0xE1($a1)
    /* 7AA0 8006AE00 2B100200 */  sltu       $v0, $zero, $v0
    /* 7AA4 8006AE04 2A182302 */  slt        $v1, $s1, $v1
    /* 7AA8 8006AE08 02006010 */  beqz       $v1, .L8006AE14
    /* 7AAC 8006AE0C 25986202 */   or        $s3, $s3, $v0
    /* 7AB0 8006AE10 02007336 */  ori        $s3, $s3, 0x2
  .L8006AE14:
    /* 7AB4 8006AE14 E200A490 */  lbu        $a0, 0xE2($a1)
    /* 7AB8 8006AE18 E300A590 */  lbu        $a1, 0xE3($a1)
    /* 7ABC 8006AE1C 21306002 */  addu       $a2, $s3, $zero
    /* 7AC0 8006AE20 23208500 */  subu       $a0, $a0, $a1
    /* 7AC4 8006AE24 7C9B010C */  jal        Stg40_ItemMenuSetCursor
    /* 7AC8 8006AE28 23282502 */   subu      $a1, $s1, $a1
    /* 7ACC 8006AE2C 602B028E */  lw         $v0, %lo(D_80072B60)($s0)
    /* 7AD0 8006AE30 00000000 */  nop
    /* 7AD4 8006AE34 E2004390 */  lbu        $v1, 0xE2($v0)
    /* 7AD8 8006AE38 00000000 */  nop
    /* 7ADC 8006AE3C 21104300 */  addu       $v0, $v0, $v1
    /* 7AE0 8006AE40 B0004490 */  lbu        $a0, 0xB0($v0)
    /* 7AE4 8006AE44 2178000C */  jal        Item_GetDescText
    /* 7AE8 8006AE48 00000000 */   nop
    /* 7AEC 8006AE4C 1800A2AE */  sw         $v0, 0x18($s5)
    /* 7AF0 8006AE50 2800BF8F */  lw         $ra, 0x28($sp)
    /* 7AF4 8006AE54 2400B58F */  lw         $s5, 0x24($sp)
    /* 7AF8 8006AE58 2000B48F */  lw         $s4, 0x20($sp)
    /* 7AFC 8006AE5C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7B00 8006AE60 1800B28F */  lw         $s2, 0x18($sp)
    /* 7B04 8006AE64 1400B18F */  lw         $s1, 0x14($sp)
    /* 7B08 8006AE68 1000B08F */  lw         $s0, 0x10($sp)
    /* 7B0C 8006AE6C 0800E003 */  jr         $ra
    /* 7B10 8006AE70 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg40_ItemMenuRefresh
