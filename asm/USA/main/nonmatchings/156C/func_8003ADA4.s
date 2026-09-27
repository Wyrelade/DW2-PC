nonmatching func_8003ADA4, 0x2C4

glabel func_8003ADA4
    /* 2B5A4 8003ADA4 0580023C */  lui        $v0, %hi(D_8004FDC0)
    /* 2B5A8 8003ADA8 C0FD428C */  lw         $v0, %lo(D_8004FDC0)($v0)
    /* 2B5AC 8003ADAC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2B5B0 8003ADB0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B5B4 8003ADB4 21888000 */  addu       $s1, $a0, $zero
    /* 2B5B8 8003ADB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B5BC 8003ADBC 21800000 */  addu       $s0, $zero, $zero
    /* 2B5C0 8003ADC0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2B5C4 8003ADC4 FFFF1224 */  addiu      $s2, $zero, -0x1
    /* 2B5C8 8003ADC8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2B5CC 8003ADCC 03004014 */  bnez       $v0, .L8003ADDC
    /* 2B5D0 8003ADD0 1C00B3AF */   sw        $s3, 0x1C($sp)
    /* 2B5D4 8003ADD4 7EEB0008 */  j          .L8003ADF8
    /* 2B5D8 8003ADD8 21980000 */   addu      $s3, $zero, $zero
  .L8003ADDC:
    /* 2B5DC 8003ADDC 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 2B5E0 8003ADE0 0580033C */  lui        $v1, %hi(D_8004FDC4)
    /* 2B5E4 8003ADE4 C4FD638C */  lw         $v1, %lo(D_8004FDC4)($v1)
    /* 2B5E8 8003ADE8 0580043C */  lui        $a0, %hi(D_8004FE50)
    /* 2B5EC 8003ADEC 50FE848C */  lw         $a0, %lo(D_8004FE50)($a0)
    /* 2B5F0 8003ADF0 23104300 */  subu       $v0, $v0, $v1
    /* 2B5F4 8003ADF4 04988200 */  sllv       $s3, $v0, $a0
  .L8003ADF8:
    /* 2B5F8 8003ADF8 0580033C */  lui        $v1, %hi(D_8004FE58)
    /* 2B5FC 8003ADFC 58FE638C */  lw         $v1, %lo(D_8004FE58)($v1)
    /* 2B600 8003AE00 00000000 */  nop
    /* 2B604 8003AE04 27100300 */  nor        $v0, $zero, $v1
    /* 2B608 8003AE08 24102202 */  and        $v0, $s1, $v0
    /* 2B60C 8003AE0C 02004010 */  beqz       $v0, .L8003AE18
    /* 2B610 8003AE10 00000000 */   nop
    /* 2B614 8003AE14 21882302 */  addu       $s1, $s1, $v1
  .L8003AE18:
    /* 2B618 8003AE18 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2B61C 8003AE1C 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2B620 8003AE20 0580033C */  lui        $v1, %hi(D_8004FE90)
    /* 2B624 8003AE24 90FE638C */  lw         $v1, %lo(D_8004FE90)($v1)
    /* 2B628 8003AE28 07885100 */  srav       $s1, $s1, $v0
    /* 2B62C 8003AE2C 04885100 */  sllv       $s1, $s1, $v0
    /* 2B630 8003AE30 0000628C */  lw         $v0, 0x0($v1)
    /* 2B634 8003AE34 0040033C */  lui        $v1, (0x40000000 >> 16)
    /* 2B638 8003AE38 24104300 */  and        $v0, $v0, $v1
    /* 2B63C 8003AE3C 03004010 */  beqz       $v0, .L8003AE4C
    /* 2B640 8003AE40 00000000 */   nop
    /* 2B644 8003AE44 B4EB0008 */  j          .L8003AED0
    /* 2B648 8003AE48 21900000 */   addu      $s2, $zero, $zero
  .L8003AE4C:
    /* 2B64C 8003AE4C 1DEC000C */  jal        _spu_gcSPU
    /* 2B650 8003AE50 00000000 */   nop
    /* 2B654 8003AE54 0580033C */  lui        $v1, %hi(D_8004FE88)
    /* 2B658 8003AE58 88FE638C */  lw         $v1, %lo(D_8004FE88)($v1)
    /* 2B65C 8003AE5C 00000000 */  nop
    /* 2B660 8003AE60 2A100302 */  slt        $v0, $s0, $v1
    /* 2B664 8003AE64 1A004010 */  beqz       $v0, .L8003AED0
    /* 2B668 8003AE68 C0101000 */   sll       $v0, $s0, 3
    /* 2B66C 8003AE6C 0040073C */  lui        $a3, (0x40000000 >> 16)
    /* 2B670 8003AE70 0080063C */  lui        $a2, (0x80000000 >> 16)
    /* 2B674 8003AE74 21286000 */  addu       $a1, $v1, $zero
    /* 2B678 8003AE78 0580033C */  lui        $v1, %hi(D_8004FE90)
    /* 2B67C 8003AE7C 90FE638C */  lw         $v1, %lo(D_8004FE90)($v1)
    /* 2B680 8003AE80 00000000 */  nop
    /* 2B684 8003AE84 21204300 */  addu       $a0, $v0, $v1
  .L8003AE88:
    /* 2B688 8003AE88 0000838C */  lw         $v1, 0x0($a0)
    /* 2B68C 8003AE8C 00000000 */  nop
    /* 2B690 8003AE90 24106700 */  and        $v0, $v1, $a3
    /* 2B694 8003AE94 08004014 */  bnez       $v0, .L8003AEB8
    /* 2B698 8003AE98 24106600 */   and       $v0, $v1, $a2
    /* 2B69C 8003AE9C 08004010 */  beqz       $v0, .L8003AEC0
    /* 2B6A0 8003AEA0 00000000 */   nop
    /* 2B6A4 8003AEA4 0400828C */  lw         $v0, 0x4($a0)
    /* 2B6A8 8003AEA8 00000000 */  nop
    /* 2B6AC 8003AEAC 2B105100 */  sltu       $v0, $v0, $s1
    /* 2B6B0 8003AEB0 03004014 */  bnez       $v0, .L8003AEC0
    /* 2B6B4 8003AEB4 00000000 */   nop
  .L8003AEB8:
    /* 2B6B8 8003AEB8 B4EB0008 */  j          .L8003AED0
    /* 2B6BC 8003AEBC 21900002 */   addu      $s2, $s0, $zero
  .L8003AEC0:
    /* 2B6C0 8003AEC0 01001026 */  addiu      $s0, $s0, 0x1
    /* 2B6C4 8003AEC4 2A100502 */  slt        $v0, $s0, $a1
    /* 2B6C8 8003AEC8 EFFF4014 */  bnez       $v0, .L8003AE88
    /* 2B6CC 8003AECC 08008424 */   addiu     $a0, $a0, 0x8
  .L8003AED0:
    /* 2B6D0 8003AED0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B6D4 8003AED4 5D004212 */  beq        $s2, $v0, .L8003B04C
    /* 2B6D8 8003AED8 C0801200 */   sll       $s0, $s2, 3
    /* 2B6DC 8003AEDC 0580073C */  lui        $a3, %hi(D_8004FE90)
    /* 2B6E0 8003AEE0 90FEE78C */  lw         $a3, %lo(D_8004FE90)($a3)
    /* 2B6E4 8003AEE4 00000000 */  nop
    /* 2B6E8 8003AEE8 21300702 */  addu       $a2, $s0, $a3
    /* 2B6EC 8003AEEC 0000C38C */  lw         $v1, 0x0($a2)
    /* 2B6F0 8003AEF0 0040083C */  lui        $t0, (0x40000000 >> 16)
    /* 2B6F4 8003AEF4 24106800 */  and        $v0, $v1, $t0
    /* 2B6F8 8003AEF8 29004010 */  beqz       $v0, .L8003AFA0
    /* 2B6FC 8003AEFC 00000000 */   nop
    /* 2B700 8003AF00 0580023C */  lui        $v0, %hi(D_8004FE88)
    /* 2B704 8003AF04 88FE428C */  lw         $v0, %lo(D_8004FE88)($v0)
    /* 2B708 8003AF08 00000000 */  nop
    /* 2B70C 8003AF0C 2A104202 */  slt        $v0, $s2, $v0
    /* 2B710 8003AF10 4E004010 */  beqz       $v0, .L8003B04C
    /* 2B714 8003AF14 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 2B718 8003AF18 0400C28C */  lw         $v0, 0x4($a2)
    /* 2B71C 8003AF1C 00000000 */  nop
    /* 2B720 8003AF20 23105300 */  subu       $v0, $v0, $s3
    /* 2B724 8003AF24 2B105100 */  sltu       $v0, $v0, $s1
    /* 2B728 8003AF28 48004014 */  bnez       $v0, .L8003B04C
    /* 2B72C 8003AF2C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 2B730 8003AF30 FF0F053C */  lui        $a1, (0xFFFFFFF >> 16)
    /* 2B734 8003AF34 FFFFA534 */  ori        $a1, $a1, (0xFFFFFFF & 0xFFFF)
    /* 2B738 8003AF38 01004426 */  addiu      $a0, $s2, 0x1
    /* 2B73C 8003AF3C C0180400 */  sll        $v1, $a0, 3
    /* 2B740 8003AF40 0000C28C */  lw         $v0, 0x0($a2)
    /* 2B744 8003AF44 21186700 */  addu       $v1, $v1, $a3
    /* 2B748 8003AF48 24104500 */  and        $v0, $v0, $a1
    /* 2B74C 8003AF4C 21105100 */  addu       $v0, $v0, $s1
    /* 2B750 8003AF50 25104800 */  or         $v0, $v0, $t0
    /* 2B754 8003AF54 000062AC */  sw         $v0, 0x0($v1)
    /* 2B758 8003AF58 0400C28C */  lw         $v0, 0x4($a2)
    /* 2B75C 8003AF5C 00000000 */  nop
    /* 2B760 8003AF60 23105100 */  subu       $v0, $v0, $s1
    /* 2B764 8003AF64 040062AC */  sw         $v0, 0x4($v1)
    /* 2B768 8003AF68 0000C28C */  lw         $v0, 0x0($a2)
    /* 2B76C 8003AF6C 0580013C */  lui        $at, %hi(D_8004FE8C)
    /* 2B770 8003AF70 8CFE24AC */  sw         $a0, %lo(D_8004FE8C)($at)
    /* 2B774 8003AF74 0400D1AC */  sw         $s1, 0x4($a2)
    /* 2B778 8003AF78 24104500 */  and        $v0, $v0, $a1
    /* 2B77C 8003AF7C 1DEC000C */  jal        _spu_gcSPU
    /* 2B780 8003AF80 0000C2AC */   sw        $v0, 0x0($a2)
    /* 2B784 8003AF84 0580023C */  lui        $v0, %hi(D_8004FE90)
    /* 2B788 8003AF88 90FE428C */  lw         $v0, %lo(D_8004FE90)($v0)
    /* 2B78C 8003AF8C 00000000 */  nop
    /* 2B790 8003AF90 21100202 */  addu       $v0, $s0, $v0
    /* 2B794 8003AF94 0000428C */  lw         $v0, 0x0($v0)
    /* 2B798 8003AF98 13EC0008 */  j          .L8003B04C
    /* 2B79C 8003AF9C 00000000 */   nop
  .L8003AFA0:
    /* 2B7A0 8003AFA0 0400C88C */  lw         $t0, 0x4($a2)
    /* 2B7A4 8003AFA4 00000000 */  nop
    /* 2B7A8 8003AFA8 2B102802 */  sltu       $v0, $s1, $t0
    /* 2B7AC 8003AFAC 18004010 */  beqz       $v0, .L8003B010
    /* 2B7B0 8003AFB0 FF0F043C */   lui       $a0, (0xFFFFFFF >> 16)
    /* 2B7B4 8003AFB4 0580063C */  lui        $a2, %hi(D_8004FE8C)
    /* 2B7B8 8003AFB8 8CFEC68C */  lw         $a2, %lo(D_8004FE8C)($a2)
    /* 2B7BC 8003AFBC 0580023C */  lui        $v0, %hi(D_8004FE88)
    /* 2B7C0 8003AFC0 88FE428C */  lw         $v0, %lo(D_8004FE88)($v0)
    /* 2B7C4 8003AFC4 00000000 */  nop
    /* 2B7C8 8003AFC8 2A10C200 */  slt        $v0, $a2, $v0
    /* 2B7CC 8003AFCC 10004010 */  beqz       $v0, .L8003B010
    /* 2B7D0 8003AFD0 21187100 */   addu      $v1, $v1, $s1
    /* 2B7D4 8003AFD4 C0100600 */  sll        $v0, $a2, 3
    /* 2B7D8 8003AFD8 21104700 */  addu       $v0, $v0, $a3
    /* 2B7DC 8003AFDC 0080043C */  lui        $a0, (0x80000000 >> 16)
    /* 2B7E0 8003AFE0 25186400 */  or         $v1, $v1, $a0
    /* 2B7E4 8003AFE4 0000458C */  lw         $a1, 0x0($v0)
    /* 2B7E8 8003AFE8 0400448C */  lw         $a0, 0x4($v0)
    /* 2B7EC 8003AFEC 000043AC */  sw         $v1, 0x0($v0)
    /* 2B7F0 8003AFF0 23181101 */  subu       $v1, $t0, $s1
    /* 2B7F4 8003AFF4 040043AC */  sw         $v1, 0x4($v0)
    /* 2B7F8 8003AFF8 0100C324 */  addiu      $v1, $a2, 0x1
    /* 2B7FC 8003AFFC 0580013C */  lui        $at, %hi(D_8004FE8C)
    /* 2B800 8003B000 8CFE23AC */  sw         $v1, %lo(D_8004FE8C)($at)
    /* 2B804 8003B004 080045AC */  sw         $a1, 0x8($v0)
    /* 2B808 8003B008 0C0044AC */  sw         $a0, 0xC($v0)
    /* 2B80C 8003B00C FF0F043C */  lui        $a0, (0xFFFFFFF >> 16)
  .L8003B010:
    /* 2B810 8003B010 0580033C */  lui        $v1, %hi(D_8004FE90)
    /* 2B814 8003B014 90FE638C */  lw         $v1, %lo(D_8004FE90)($v1)
    /* 2B818 8003B018 C0801200 */  sll        $s0, $s2, 3
    /* 2B81C 8003B01C 21180302 */  addu       $v1, $s0, $v1
    /* 2B820 8003B020 0000628C */  lw         $v0, 0x0($v1)
    /* 2B824 8003B024 FFFF8434 */  ori        $a0, $a0, (0xFFFFFFF & 0xFFFF)
    /* 2B828 8003B028 040071AC */  sw         $s1, 0x4($v1)
    /* 2B82C 8003B02C 24104400 */  and        $v0, $v0, $a0
    /* 2B830 8003B030 1DEC000C */  jal        _spu_gcSPU
    /* 2B834 8003B034 000062AC */   sw        $v0, 0x0($v1)
    /* 2B838 8003B038 0580023C */  lui        $v0, %hi(D_8004FE90)
    /* 2B83C 8003B03C 90FE428C */  lw         $v0, %lo(D_8004FE90)($v0)
    /* 2B840 8003B040 00000000 */  nop
    /* 2B844 8003B044 21800202 */  addu       $s0, $s0, $v0
    /* 2B848 8003B048 0000028E */  lw         $v0, 0x0($s0)
  .L8003B04C:
    /* 2B84C 8003B04C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2B850 8003B050 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2B854 8003B054 1800B28F */  lw         $s2, 0x18($sp)
    /* 2B858 8003B058 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B85C 8003B05C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B860 8003B060 0800E003 */  jr         $ra
    /* 2B864 8003B064 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003ADA4
    /* 2B868 8003B068 00000000 */  nop
    /* 2B86C 8003B06C 00000000 */  nop
    /* 2B870 8003B070 00000000 */  nop
