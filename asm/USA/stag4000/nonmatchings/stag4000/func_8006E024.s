nonmatching func_8006E024, 0x1DC

glabel func_8006E024
    /* ACC4 8006E024 0780033C */  lui        $v1, %hi(D_80072B60)
    /* ACC8 8006E028 602B628C */  lw         $v0, %lo(D_80072B60)($v1)
    /* ACCC 8006E02C B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* ACD0 8006E030 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* ACD4 8006E034 4800BEAF */  sw         $fp, 0x48($sp)
    /* ACD8 8006E038 4400B7AF */  sw         $s7, 0x44($sp)
    /* ACDC 8006E03C 4000B6AF */  sw         $s6, 0x40($sp)
    /* ACE0 8006E040 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* ACE4 8006E044 3800B4AF */  sw         $s4, 0x38($sp)
    /* ACE8 8006E048 3400B3AF */  sw         $s3, 0x34($sp)
    /* ACEC 8006E04C 3000B2AF */  sw         $s2, 0x30($sp)
    /* ACF0 8006E050 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* ACF4 8006E054 2800B0AF */  sw         $s0, 0x28($sp)
    /* ACF8 8006E058 21184000 */  addu       $v1, $v0, $zero
    /* ACFC 8006E05C 1000508C */  lw         $s0, 0x10($v0)
    /* AD00 8006E060 0680023C */  lui        $v0, %hi(D_80063664)
    /* AD04 8006E064 64364A24 */  addiu      $t2, $v0, %lo(D_80063664)
    /* AD08 8006E068 0000478D */  lw         $a3, 0x0($t2)
    /* AD0C 8006E06C 0400488D */  lw         $t0, 0x4($t2)
    /* AD10 8006E070 0800498D */  lw         $t1, 0x8($t2)
    /* AD14 8006E074 1000A7AF */  sw         $a3, 0x10($sp)
    /* AD18 8006E078 1400A8AF */  sw         $t0, 0x14($sp)
    /* AD1C 8006E07C 1800A9AF */  sw         $t1, 0x18($sp)
    /* AD20 8006E080 0C00478D */  lw         $a3, 0xC($t2)
    /* AD24 8006E084 1000488D */  lw         $t0, 0x10($t2)
    /* AD28 8006E088 1C00A7AF */  sw         $a3, 0x1C($sp)
    /* AD2C 8006E08C 2000A8AF */  sw         $t0, 0x20($sp)
    /* AD30 8006E090 0000628C */  lw         $v0, 0x0($v1)
    /* AD34 8006E094 00000000 */  nop
    /* AD38 8006E098 4D004010 */  beqz       $v0, .L8006E1D0
    /* AD3C 8006E09C 54001226 */   addiu     $s2, $s0, 0x54
    /* AD40 8006E0A0 00180424 */  addiu      $a0, $zero, 0x1800
    /* AD44 8006E0A4 CF8B000C */  jal        Mem_Alloc
    /* AD48 8006E0A8 02000524 */   addiu     $a1, $zero, 0x2
    /* AD4C 8006E0AC 21B84000 */  addu       $s7, $v0, $zero
    /* AD50 8006E0B0 21B00000 */  addu       $s6, $zero, $zero
    /* AD54 8006E0B4 03001E24 */  addiu      $fp, $zero, 0x3
    /* AD58 8006E0B8 1000B527 */  addiu      $s5, $sp, 0x10
    /* AD5C 8006E0BC 58001326 */  addiu      $s3, $s0, 0x58
  .L8006E0C0:
    /* AD60 8006E0C0 71C4010C */  jal        func_800711C4
    /* AD64 8006E0C4 04000424 */   addiu     $a0, $zero, 0x4
    /* AD68 8006E0C8 21184000 */  addu       $v1, $v0, $zero
    /* AD6C 8006E0CC 01000724 */  addiu      $a3, $zero, 0x1
    /* AD70 8006E0D0 0A006710 */  beq        $v1, $a3, .L8006E0FC
    /* AD74 8006E0D4 02006228 */   slti      $v0, $v1, 0x2
    /* AD78 8006E0D8 05004014 */  bnez       $v0, .L8006E0F0
    /* AD7C 8006E0DC 02000824 */   addiu     $t0, $zero, 0x2
    /* AD80 8006E0E0 09006810 */  beq        $v1, $t0, .L8006E108
    /* AD84 8006E0E4 00000000 */   nop
    /* AD88 8006E0E8 0A007E10 */  beq        $v1, $fp, .L8006E114
    /* AD8C 8006E0EC 00000000 */   nop
  .L8006E0F0:
    /* AD90 8006E0F0 0000628E */  lw         $v0, 0x0($s3)
    /* AD94 8006E0F4 49B80108 */  j          .L8006E124
    /* AD98 8006E0F8 0F005030 */   andi      $s0, $v0, 0xF
  .L8006E0FC:
    /* AD9C 8006E0FC 00007092 */  lbu        $s0, 0x0($s3)
    /* ADA0 8006E100 49B80108 */  j          .L8006E124
    /* ADA4 8006E104 02811000 */   srl       $s0, $s0, 4
  .L8006E108:
    /* ADA8 8006E108 0000628E */  lw         $v0, 0x0($s3)
    /* ADAC 8006E10C 48B80108 */  j          .L8006E120
    /* ADB0 8006E110 02820200 */   srl       $s0, $v0, 8
  .L8006E114:
    /* ADB4 8006E114 0000628E */  lw         $v0, 0x0($s3)
    /* ADB8 8006E118 00000000 */  nop
    /* ADBC 8006E11C 02830200 */  srl        $s0, $v0, 12
  .L8006E120:
    /* ADC0 8006E120 0F001032 */  andi       $s0, $s0, 0xF
  .L8006E124:
    /* ADC4 8006E124 22000012 */  beqz       $s0, .L8006E1B0
    /* ADC8 8006E128 21880000 */   addu      $s1, $zero, $zero
    /* ADCC 8006E12C 21A0A002 */  addu       $s4, $s5, $zero
  .L8006E130:
    /* ADD0 8006E130 71C4010C */  jal        func_800711C4
    /* ADD4 8006E134 04000424 */   addiu     $a0, $zero, 0x4
    /* ADD8 8006E138 21184000 */  addu       $v1, $v0, $zero
    /* ADDC 8006E13C 01000924 */  addiu      $t1, $zero, 0x1
    /* ADE0 8006E140 0A006910 */  beq        $v1, $t1, .L8006E16C
    /* ADE4 8006E144 02006228 */   slti      $v0, $v1, 0x2
    /* ADE8 8006E148 05004014 */  bnez       $v0, .L8006E160
    /* ADEC 8006E14C 02000A24 */   addiu     $t2, $zero, 0x2
    /* ADF0 8006E150 09006A10 */  beq        $v1, $t2, .L8006E178
    /* ADF4 8006E154 00000000 */   nop
    /* ADF8 8006E158 0A007E10 */  beq        $v1, $fp, .L8006E184
    /* ADFC 8006E15C 00000000 */   nop
  .L8006E160:
    /* AE00 8006E160 0000428E */  lw         $v0, 0x0($s2)
    /* AE04 8006E164 65B80108 */  j          .L8006E194
    /* AE08 8006E168 0F004630 */   andi      $a2, $v0, 0xF
  .L8006E16C:
    /* AE0C 8006E16C 00004692 */  lbu        $a2, 0x0($s2)
    /* AE10 8006E170 65B80108 */  j          .L8006E194
    /* AE14 8006E174 02310600 */   srl       $a2, $a2, 4
  .L8006E178:
    /* AE18 8006E178 0000428E */  lw         $v0, 0x0($s2)
    /* AE1C 8006E17C 64B80108 */  j          .L8006E190
    /* AE20 8006E180 02320200 */   srl       $a2, $v0, 8
  .L8006E184:
    /* AE24 8006E184 0000428E */  lw         $v0, 0x0($s2)
    /* AE28 8006E188 00000000 */  nop
    /* AE2C 8006E18C 02330200 */  srl        $a2, $v0, 12
  .L8006E190:
    /* AE30 8006E190 0F00C630 */  andi       $a2, $a2, 0xF
  .L8006E194:
    /* AE34 8006E194 2120E002 */  addu       $a0, $s7, $zero
    /* AE38 8006E198 0000858E */  lw         $a1, 0x0($s4)
    /* AE3C 8006E19C E9B7010C */  jal        func_8006DFA4
    /* AE40 8006E1A0 01003126 */   addiu     $s1, $s1, 0x1
    /* AE44 8006E1A4 2A103002 */  slt        $v0, $s1, $s0
    /* AE48 8006E1A8 E1FF4014 */  bnez       $v0, .L8006E130
    /* AE4C 8006E1AC 00000000 */   nop
  .L8006E1B0:
    /* AE50 8006E1B0 08007326 */  addiu      $s3, $s3, 0x8
    /* AE54 8006E1B4 08005226 */  addiu      $s2, $s2, 0x8
    /* AE58 8006E1B8 0100D626 */  addiu      $s6, $s6, 0x1
    /* AE5C 8006E1BC 0500C22A */  slti       $v0, $s6, 0x5
    /* AE60 8006E1C0 BFFF4014 */  bnez       $v0, .L8006E0C0
    /* AE64 8006E1C4 0400B526 */   addiu     $s5, $s5, 0x4
    /* AE68 8006E1C8 618B000C */  jal        Mem_Free
    /* AE6C 8006E1CC 2120E002 */   addu      $a0, $s7, $zero
  .L8006E1D0:
    /* AE70 8006E1D0 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* AE74 8006E1D4 4800BE8F */  lw         $fp, 0x48($sp)
    /* AE78 8006E1D8 4400B78F */  lw         $s7, 0x44($sp)
    /* AE7C 8006E1DC 4000B68F */  lw         $s6, 0x40($sp)
    /* AE80 8006E1E0 3C00B58F */  lw         $s5, 0x3C($sp)
    /* AE84 8006E1E4 3800B48F */  lw         $s4, 0x38($sp)
    /* AE88 8006E1E8 3400B38F */  lw         $s3, 0x34($sp)
    /* AE8C 8006E1EC 3000B28F */  lw         $s2, 0x30($sp)
    /* AE90 8006E1F0 2C00B18F */  lw         $s1, 0x2C($sp)
    /* AE94 8006E1F4 2800B08F */  lw         $s0, 0x28($sp)
    /* AE98 8006E1F8 0800E003 */  jr         $ra
    /* AE9C 8006E1FC 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8006E024
