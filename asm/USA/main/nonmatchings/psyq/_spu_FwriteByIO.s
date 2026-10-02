nonmatching _spu_FwriteByIO, 0x1C0

glabel _spu_FwriteByIO
    /* 2AC54 8003A454 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AC58 8003A458 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AC5C 8003A45C 0580033C */  lui        $v1, %hi(D_8004FE40)
    /* 2AC60 8003A460 40FE6394 */  lhu        $v1, %lo(D_8004FE40)($v1)
    /* 2AC64 8003A464 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2AC68 8003A468 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2AC6C 8003A46C 2188A000 */  addu       $s1, $a1, $zero
    /* 2AC70 8003A470 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2AC74 8003A474 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2AC78 8003A478 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2AC7C 8003A47C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2AC80 8003A480 AE014594 */  lhu        $a1, 0x1AE($v0)
    /* 2AC84 8003A484 21908000 */  addu       $s2, $a0, $zero
    /* 2AC88 8003A488 A60143A4 */  sh         $v1, 0x1A6($v0)
    /* 2AC8C 8003A48C 2BEB000C */  jal        _spu_Fw1ts
    /* 2AC90 8003A490 FF07B330 */   andi      $s3, $a1, 0x7FF
    /* 2AC94 8003A494 39002012 */  beqz       $s1, .L8003A57C
    /* 2AC98 8003A498 4100222E */   sltiu     $v0, $s1, 0x41
  .L8003A49C:
    /* 2AC9C 8003A49C 02004010 */  beqz       $v0, .L8003A4A8
    /* 2ACA0 8003A4A0 40001024 */   addiu     $s0, $zero, 0x40
    /* 2ACA4 8003A4A4 21802002 */  addu       $s0, $s1, $zero
  .L8003A4A8:
    /* 2ACA8 8003A4A8 0A00001A */  blez       $s0, .L8003A4D4
    /* 2ACAC 8003A4AC 21180000 */   addu      $v1, $zero, $zero
    /* 2ACB0 8003A4B0 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2ACB4 8003A4B4 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
  .L8003A4B8:
    /* 2ACB8 8003A4B8 00004296 */  lhu        $v0, 0x0($s2)
    /* 2ACBC 8003A4BC 02005226 */  addiu      $s2, $s2, 0x2
    /* 2ACC0 8003A4C0 02006324 */  addiu      $v1, $v1, 0x2
    /* 2ACC4 8003A4C4 A80182A4 */  sh         $v0, 0x1A8($a0)
    /* 2ACC8 8003A4C8 2A107000 */  slt        $v0, $v1, $s0
    /* 2ACCC 8003A4CC FAFF4014 */  bnez       $v0, .L8003A4B8
    /* 2ACD0 8003A4D0 00000000 */   nop
  .L8003A4D4:
    /* 2ACD4 8003A4D4 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2ACD8 8003A4D8 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2ACDC 8003A4DC 00000000 */  nop
    /* 2ACE0 8003A4E0 AA016494 */  lhu        $a0, 0x1AA($v1)
    /* 2ACE4 8003A4E4 00000000 */  nop
    /* 2ACE8 8003A4E8 CFFF8230 */  andi       $v0, $a0, 0xFFCF
    /* 2ACEC 8003A4EC 10004234 */  ori        $v0, $v0, 0x10
    /* 2ACF0 8003A4F0 2BEB000C */  jal        _spu_Fw1ts
    /* 2ACF4 8003A4F4 AA0162A4 */   sh        $v0, 0x1AA($v1)
    /* 2ACF8 8003A4F8 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2ACFC 8003A4FC 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AD00 8003A500 00000000 */  nop
    /* 2AD04 8003A504 AE014294 */  lhu        $v0, 0x1AE($v0)
    /* 2AD08 8003A508 00000000 */  nop
    /* 2AD0C 8003A50C 00044230 */  andi       $v0, $v0, 0x400
    /* 2AD10 8003A510 14004010 */  beqz       $v0, .L8003A564
    /* 2AD14 8003A514 21180000 */   addu      $v1, $zero, $zero
    /* 2AD18 8003A518 01006324 */  addiu      $v1, $v1, 0x1
  .L8003A51C:
    /* 2AD1C 8003A51C 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2AD20 8003A520 08004014 */  bnez       $v0, .L8003A544
    /* 2AD24 8003A524 00000000 */   nop
    /* 2AD28 8003A528 0180043C */  lui        $a0, %hi(D_80010AA4)
    /* 2AD2C 8003A52C A40A8424 */  addiu      $a0, $a0, %lo(D_80010AA4)
    /* 2AD30 8003A530 0180053C */  lui        $a1, %hi(D_80010AC4)
    /* 2AD34 8003A534 05A8000C */  jal        printf
    /* 2AD38 8003A538 C40AA524 */   addiu     $a1, $a1, %lo(D_80010AC4)
    /* 2AD3C 8003A53C 59E90008 */  j          .L8003A564
    /* 2AD40 8003A540 00000000 */   nop
  .L8003A544:
    /* 2AD44 8003A544 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AD48 8003A548 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AD4C 8003A54C 00000000 */  nop
    /* 2AD50 8003A550 AE014294 */  lhu        $v0, 0x1AE($v0)
    /* 2AD54 8003A554 00000000 */  nop
    /* 2AD58 8003A558 00044230 */  andi       $v0, $v0, 0x400
    /* 2AD5C 8003A55C EFFF4014 */  bnez       $v0, .L8003A51C
    /* 2AD60 8003A560 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A564:
    /* 2AD64 8003A564 2BEB000C */  jal        _spu_Fw1ts
    /* 2AD68 8003A568 23883002 */   subu      $s1, $s1, $s0
    /* 2AD6C 8003A56C 2BEB000C */  jal        _spu_Fw1ts
    /* 2AD70 8003A570 00000000 */   nop
    /* 2AD74 8003A574 C9FF2016 */  bnez       $s1, .L8003A49C
    /* 2AD78 8003A578 4100222E */   sltiu     $v0, $s1, 0x41
  .L8003A57C:
    /* 2AD7C 8003A57C 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AD80 8003A580 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AD84 8003A584 00000000 */  nop
    /* 2AD88 8003A588 AA014494 */  lhu        $a0, 0x1AA($v0)
    /* 2AD8C 8003A58C FFFF6532 */  andi       $a1, $s3, 0xFFFF
    /* 2AD90 8003A590 CFFF8330 */  andi       $v1, $a0, 0xFFCF
    /* 2AD94 8003A594 AA0143A4 */  sh         $v1, 0x1AA($v0)
    /* 2AD98 8003A598 AE014294 */  lhu        $v0, 0x1AE($v0)
    /* 2AD9C 8003A59C 00000000 */  nop
    /* 2ADA0 8003A5A0 FF074230 */  andi       $v0, $v0, 0x7FF
    /* 2ADA4 8003A5A4 14004510 */  beq        $v0, $a1, .L8003A5F8
    /* 2ADA8 8003A5A8 21180000 */   addu      $v1, $zero, $zero
    /* 2ADAC 8003A5AC 01006324 */  addiu      $v1, $v1, 0x1
  .L8003A5B0:
    /* 2ADB0 8003A5B0 010F622C */  sltiu      $v0, $v1, 0xF01
    /* 2ADB4 8003A5B4 08004014 */  bnez       $v0, .L8003A5D8
    /* 2ADB8 8003A5B8 00000000 */   nop
    /* 2ADBC 8003A5BC 0180043C */  lui        $a0, %hi(D_80010AA4)
    /* 2ADC0 8003A5C0 A40A8424 */  addiu      $a0, $a0, %lo(D_80010AA4)
    /* 2ADC4 8003A5C4 0180053C */  lui        $a1, %hi(D_80010AD8)
    /* 2ADC8 8003A5C8 05A8000C */  jal        printf
    /* 2ADCC 8003A5CC D80AA524 */   addiu     $a1, $a1, %lo(D_80010AD8)
    /* 2ADD0 8003A5D0 7EE90008 */  j          .L8003A5F8
    /* 2ADD4 8003A5D4 00000000 */   nop
  .L8003A5D8:
    /* 2ADD8 8003A5D8 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2ADDC 8003A5DC 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2ADE0 8003A5E0 00000000 */  nop
    /* 2ADE4 8003A5E4 AE014294 */  lhu        $v0, 0x1AE($v0)
    /* 2ADE8 8003A5E8 00000000 */  nop
    /* 2ADEC 8003A5EC FF074230 */  andi       $v0, $v0, 0x7FF
    /* 2ADF0 8003A5F0 EFFF4514 */  bne        $v0, $a1, .L8003A5B0
    /* 2ADF4 8003A5F4 01006324 */   addiu     $v1, $v1, 0x1
  .L8003A5F8:
    /* 2ADF8 8003A5F8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2ADFC 8003A5FC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2AE00 8003A600 1800B28F */  lw         $s2, 0x18($sp)
    /* 2AE04 8003A604 1400B18F */  lw         $s1, 0x14($sp)
    /* 2AE08 8003A608 1000B08F */  lw         $s0, 0x10($sp)
    /* 2AE0C 8003A60C 0800E003 */  jr         $ra
    /* 2AE10 8003A610 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _spu_FwriteByIO
