nonmatching SpuSetVoiceAttr, 0x5F8

glabel SpuSetVoiceAttr
    /* 2D104 8003C904 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2D108 8003C908 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2D10C 8003C90C 21808000 */  addu       $s0, $a0, $zero
    /* 2D110 8003C910 2800B4AF */  sw         $s4, 0x28($sp)
    /* 2D114 8003C914 21A00000 */  addu       $s4, $zero, $zero
    /* 2D118 8003C918 3000BFAF */  sw         $ra, 0x30($sp)
    /* 2D11C 8003C91C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 2D120 8003C920 2400B3AF */  sw         $s3, 0x24($sp)
    /* 2D124 8003C924 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2D128 8003C928 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2D12C 8003C92C 0400118E */  lw         $s1, 0x4($s0)
    /* 2D130 8003C930 0580153C */  lui        $s5, %hi(D_8004FDE4)
    /* 2D134 8003C934 E4FDB526 */  addiu      $s5, $s5, %lo(D_8004FDE4)
    /* 2D138 8003C938 0100322E */  sltiu      $s2, $s1, 0x1
  .L8003C93C:
    /* 2D13C 8003C93C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2D140 8003C940 0000038E */  lw         $v1, 0x0($s0)
    /* 2D144 8003C944 04108202 */  sllv       $v0, $v0, $s4
    /* 2D148 8003C948 24186200 */  and        $v1, $v1, $v0
    /* 2D14C 8003C94C 4A016010 */  beqz       $v1, .L8003CE78
    /* 2D150 8003C950 00000000 */   nop
    /* 2D154 8003C954 04004016 */  bnez       $s2, .L8003C968
    /* 2D158 8003C958 C0981400 */   sll       $s3, $s4, 3
    /* 2D15C 8003C95C 10002232 */  andi       $v0, $s1, 0x10
    /* 2D160 8003C960 07004010 */  beqz       $v0, .L8003C980
    /* 2D164 8003C964 00000000 */   nop
  .L8003C968:
    /* 2D168 8003C968 00111400 */  sll        $v0, $s4, 4
    /* 2D16C 8003C96C 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2D170 8003C970 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2D174 8003C974 14000496 */  lhu        $a0, 0x14($s0)
    /* 2D178 8003C978 21104300 */  addu       $v0, $v0, $v1
    /* 2D17C 8003C97C 040044A4 */  sh         $a0, 0x4($v0)
  .L8003C980:
    /* 2D180 8003C980 03004016 */  bnez       $s2, .L8003C990
    /* 2D184 8003C984 40002232 */   andi      $v0, $s1, 0x40
    /* 2D188 8003C988 04004010 */  beqz       $v0, .L8003C99C
    /* 2D18C 8003C98C 00000000 */   nop
  .L8003C990:
    /* 2D190 8003C990 18000296 */  lhu        $v0, 0x18($s0)
    /* 2D194 8003C994 00000000 */  nop
    /* 2D198 8003C998 0000A2A6 */  sh         $v0, 0x0($s5)
  .L8003C99C:
    /* 2D19C 8003C99C 03004016 */  bnez       $s2, .L8003C9AC
    /* 2D1A0 8003C9A0 20002232 */   andi      $v0, $s1, 0x20
    /* 2D1A4 8003C9A4 0D004010 */  beqz       $v0, .L8003C9DC
    /* 2D1A8 8003C9A8 00000000 */   nop
  .L8003C9AC:
    /* 2D1AC 8003C9AC 0000A596 */  lhu        $a1, 0x0($s5)
    /* 2D1B0 8003C9B0 16000796 */  lhu        $a3, 0x16($s0)
    /* 2D1B4 8003C9B4 02220500 */  srl        $a0, $a1, 8
    /* 2D1B8 8003C9B8 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 2D1BC 8003C9BC 02320700 */  srl        $a2, $a3, 8
    /* 2D1C0 8003C9C0 C1F3000C */  jal        _spu_note2pitch
    /* 2D1C4 8003C9C4 FF00E730 */   andi      $a3, $a3, 0xFF
    /* 2D1C8 8003C9C8 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2D1CC 8003C9CC 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2D1D0 8003C9D0 40181300 */  sll        $v1, $s3, 1
    /* 2D1D4 8003C9D4 21186400 */  addu       $v1, $v1, $a0
    /* 2D1D8 8003C9D8 040062A4 */  sh         $v0, 0x4($v1)
  .L8003C9DC:
    /* 2D1DC 8003C9DC 03004016 */  bnez       $s2, .L8003C9EC
    /* 2D1E0 8003C9E0 01002232 */   andi      $v0, $s1, 0x1
    /* 2D1E4 8003C9E4 35004010 */  beqz       $v0, .L8003CABC
    /* 2D1E8 8003C9E8 00000000 */   nop
  .L8003C9EC:
    /* 2D1EC 8003C9EC 08000296 */  lhu        $v0, 0x8($s0)
    /* 2D1F0 8003C9F0 21200000 */  addu       $a0, $zero, $zero
    /* 2D1F4 8003C9F4 04004016 */  bnez       $s2, .L8003CA08
    /* 2D1F8 8003C9F8 FF7F4530 */   andi      $a1, $v0, 0x7FFF
    /* 2D1FC 8003C9FC 04002232 */  andi       $v0, $s1, 0x4
    /* 2D200 8003CA00 1C004010 */  beqz       $v0, .L8003CA74
    /* 2D204 8003CA04 00000000 */   nop
  .L8003CA08:
    /* 2D208 8003CA08 0C000296 */  lhu        $v0, 0xC($s0)
    /* 2D20C 8003CA0C 00000000 */  nop
    /* 2D210 8003CA10 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2D214 8003CA14 00140200 */  sll        $v0, $v0, 16
    /* 2D218 8003CA18 031C0200 */  sra        $v1, $v0, 16
    /* 2D21C 8003CA1C 0700622C */  sltiu      $v0, $v1, 0x7
    /* 2D220 8003CA20 14004010 */  beqz       $v0, .L8003CA74
    /* 2D224 8003CA24 80100300 */   sll       $v0, $v1, 2
    /* 2D228 8003CA28 0180013C */  lui        $at, %hi(jtbl_80010AF4)
    /* 2D22C 8003CA2C 21082200 */  addu       $at, $at, $v0
    /* 2D230 8003CA30 F40A228C */  lw         $v0, %lo(jtbl_80010AF4)($at)
    /* 2D234 8003CA34 00000000 */  nop
    /* 2D238 8003CA38 08004000 */  jr         $v0
    /* 2D23C 8003CA3C 00000000 */   nop
  jlabel .L8003CA40
    /* 2D240 8003CA40 9DF20008 */  j          .L8003CA74
    /* 2D244 8003CA44 00800434 */   ori       $a0, $zero, 0x8000
  jlabel .L8003CA48
    /* 2D248 8003CA48 9DF20008 */  j          .L8003CA74
    /* 2D24C 8003CA4C 00900434 */   ori       $a0, $zero, 0x9000
  jlabel .L8003CA50
    /* 2D250 8003CA50 9DF20008 */  j          .L8003CA74
    /* 2D254 8003CA54 00A00434 */   ori       $a0, $zero, 0xA000
  jlabel .L8003CA58
    /* 2D258 8003CA58 9DF20008 */  j          .L8003CA74
    /* 2D25C 8003CA5C 00B00434 */   ori       $a0, $zero, 0xB000
  jlabel .L8003CA60
    /* 2D260 8003CA60 9DF20008 */  j          .L8003CA74
    /* 2D264 8003CA64 00C00434 */   ori       $a0, $zero, 0xC000
  jlabel .L8003CA68
    /* 2D268 8003CA68 9DF20008 */  j          .L8003CA74
    /* 2D26C 8003CA6C 00D00434 */   ori       $a0, $zero, 0xD000
  jlabel .L8003CA70
    /* 2D270 8003CA70 00E00434 */  ori        $a0, $zero, 0xE000
  .L8003CA74:
    /* 2D274 8003CA74 0B008010 */  beqz       $a0, .L8003CAA4
    /* 2D278 8003CA78 00000000 */   nop
    /* 2D27C 8003CA7C 08000386 */  lh         $v1, 0x8($s0)
    /* 2D280 8003CA80 00000000 */  nop
    /* 2D284 8003CA84 80006228 */  slti       $v0, $v1, 0x80
    /* 2D288 8003CA88 03004014 */  bnez       $v0, .L8003CA98
    /* 2D28C 8003CA8C 00000000 */   nop
    /* 2D290 8003CA90 A9F20008 */  j          .L8003CAA4
    /* 2D294 8003CA94 7F000524 */   addiu     $a1, $zero, 0x7F
  .L8003CA98:
    /* 2D298 8003CA98 02006104 */  bgez       $v1, .L8003CAA4
    /* 2D29C 8003CA9C 00000000 */   nop
    /* 2D2A0 8003CAA0 21280000 */  addu       $a1, $zero, $zero
  .L8003CAA4:
    /* 2D2A4 8003CAA4 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D2A8 8003CAA8 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D2AC 8003CAAC 40181300 */  sll        $v1, $s3, 1
    /* 2D2B0 8003CAB0 21186200 */  addu       $v1, $v1, $v0
    /* 2D2B4 8003CAB4 2510A400 */  or         $v0, $a1, $a0
    /* 2D2B8 8003CAB8 000062A4 */  sh         $v0, 0x0($v1)
  .L8003CABC:
    /* 2D2BC 8003CABC 03004016 */  bnez       $s2, .L8003CACC
    /* 2D2C0 8003CAC0 02002232 */   andi      $v0, $s1, 0x2
    /* 2D2C4 8003CAC4 35004010 */  beqz       $v0, .L8003CB9C
    /* 2D2C8 8003CAC8 00000000 */   nop
  .L8003CACC:
    /* 2D2CC 8003CACC 0A000296 */  lhu        $v0, 0xA($s0)
    /* 2D2D0 8003CAD0 21200000 */  addu       $a0, $zero, $zero
    /* 2D2D4 8003CAD4 04004016 */  bnez       $s2, .L8003CAE8
    /* 2D2D8 8003CAD8 FF7F4530 */   andi      $a1, $v0, 0x7FFF
    /* 2D2DC 8003CADC 08002232 */  andi       $v0, $s1, 0x8
    /* 2D2E0 8003CAE0 1C004010 */  beqz       $v0, .L8003CB54
    /* 2D2E4 8003CAE4 00000000 */   nop
  .L8003CAE8:
    /* 2D2E8 8003CAE8 0E000296 */  lhu        $v0, 0xE($s0)
    /* 2D2EC 8003CAEC 00000000 */  nop
    /* 2D2F0 8003CAF0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2D2F4 8003CAF4 00140200 */  sll        $v0, $v0, 16
    /* 2D2F8 8003CAF8 031C0200 */  sra        $v1, $v0, 16
    /* 2D2FC 8003CAFC 0700622C */  sltiu      $v0, $v1, 0x7
    /* 2D300 8003CB00 14004010 */  beqz       $v0, .L8003CB54
    /* 2D304 8003CB04 80100300 */   sll       $v0, $v1, 2
    /* 2D308 8003CB08 0180013C */  lui        $at, %hi(jtbl_80010B14)
    /* 2D30C 8003CB0C 21082200 */  addu       $at, $at, $v0
    /* 2D310 8003CB10 140B228C */  lw         $v0, %lo(jtbl_80010B14)($at)
    /* 2D314 8003CB14 00000000 */  nop
    /* 2D318 8003CB18 08004000 */  jr         $v0
    /* 2D31C 8003CB1C 00000000 */   nop
  jlabel .L8003CB20
    /* 2D320 8003CB20 D5F20008 */  j          .L8003CB54
    /* 2D324 8003CB24 00800434 */   ori       $a0, $zero, 0x8000
  jlabel .L8003CB28
    /* 2D328 8003CB28 D5F20008 */  j          .L8003CB54
    /* 2D32C 8003CB2C 00900434 */   ori       $a0, $zero, 0x9000
  jlabel .L8003CB30
    /* 2D330 8003CB30 D5F20008 */  j          .L8003CB54
    /* 2D334 8003CB34 00A00434 */   ori       $a0, $zero, 0xA000
  jlabel .L8003CB38
    /* 2D338 8003CB38 D5F20008 */  j          .L8003CB54
    /* 2D33C 8003CB3C 00B00434 */   ori       $a0, $zero, 0xB000
  jlabel .L8003CB40
    /* 2D340 8003CB40 D5F20008 */  j          .L8003CB54
    /* 2D344 8003CB44 00C00434 */   ori       $a0, $zero, 0xC000
  jlabel .L8003CB48
    /* 2D348 8003CB48 D5F20008 */  j          .L8003CB54
    /* 2D34C 8003CB4C 00D00434 */   ori       $a0, $zero, 0xD000
  jlabel .L8003CB50
    /* 2D350 8003CB50 00E00434 */  ori        $a0, $zero, 0xE000
  .L8003CB54:
    /* 2D354 8003CB54 0B008010 */  beqz       $a0, .L8003CB84
    /* 2D358 8003CB58 00000000 */   nop
    /* 2D35C 8003CB5C 0A000386 */  lh         $v1, 0xA($s0)
    /* 2D360 8003CB60 00000000 */  nop
    /* 2D364 8003CB64 80006228 */  slti       $v0, $v1, 0x80
    /* 2D368 8003CB68 03004014 */  bnez       $v0, .L8003CB78
    /* 2D36C 8003CB6C 00000000 */   nop
    /* 2D370 8003CB70 E1F20008 */  j          .L8003CB84
    /* 2D374 8003CB74 7F000524 */   addiu     $a1, $zero, 0x7F
  .L8003CB78:
    /* 2D378 8003CB78 02006104 */  bgez       $v1, .L8003CB84
    /* 2D37C 8003CB7C 00000000 */   nop
    /* 2D380 8003CB80 21280000 */  addu       $a1, $zero, $zero
  .L8003CB84:
    /* 2D384 8003CB84 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D388 8003CB88 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D38C 8003CB8C 40181300 */  sll        $v1, $s3, 1
    /* 2D390 8003CB90 21186200 */  addu       $v1, $v1, $v0
    /* 2D394 8003CB94 2510A400 */  or         $v0, $a1, $a0
    /* 2D398 8003CB98 020062A4 */  sh         $v0, 0x2($v1)
  .L8003CB9C:
    /* 2D39C 8003CB9C 03004016 */  bnez       $s2, .L8003CBAC
    /* 2D3A0 8003CBA0 80002232 */   andi      $v0, $s1, 0x80
    /* 2D3A4 8003CBA4 04004010 */  beqz       $v0, .L8003CBB8
    /* 2D3A8 8003CBA8 00000000 */   nop
  .L8003CBAC:
    /* 2D3AC 8003CBAC 1C00058E */  lw         $a1, 0x1C($s0)
    /* 2D3B0 8003CBB0 C9EA000C */  jal        _spu_FsetRXXa
    /* 2D3B4 8003CBB4 03006436 */   ori       $a0, $s3, 0x3
  .L8003CBB8:
    /* 2D3B8 8003CBB8 04004016 */  bnez       $s2, .L8003CBCC
    /* 2D3BC 8003CBBC 0100023C */   lui       $v0, (0x10000 >> 16)
    /* 2D3C0 8003CBC0 24102202 */  and        $v0, $s1, $v0
    /* 2D3C4 8003CBC4 04004010 */  beqz       $v0, .L8003CBD8
    /* 2D3C8 8003CBC8 00000000 */   nop
  .L8003CBCC:
    /* 2D3CC 8003CBCC 2000058E */  lw         $a1, 0x20($s0)
    /* 2D3D0 8003CBD0 C9EA000C */  jal        _spu_FsetRXXa
    /* 2D3D4 8003CBD4 07006436 */   ori       $a0, $s3, 0x7
  .L8003CBD8:
    /* 2D3D8 8003CBD8 05004016 */  bnez       $s2, .L8003CBF0
    /* 2D3DC 8003CBDC 40101300 */   sll       $v0, $s3, 1
    /* 2D3E0 8003CBE0 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 2D3E4 8003CBE4 24102202 */  and        $v0, $s1, $v0
    /* 2D3E8 8003CBE8 06004010 */  beqz       $v0, .L8003CC04
    /* 2D3EC 8003CBEC 40101300 */   sll       $v0, $s3, 1
  .L8003CBF0:
    /* 2D3F0 8003CBF0 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2D3F4 8003CBF4 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2D3F8 8003CBF8 3A000496 */  lhu        $a0, 0x3A($s0)
    /* 2D3FC 8003CBFC 21104300 */  addu       $v0, $v0, $v1
    /* 2D400 8003CC00 080044A4 */  sh         $a0, 0x8($v0)
  .L8003CC04:
    /* 2D404 8003CC04 05004016 */  bnez       $s2, .L8003CC1C
    /* 2D408 8003CC08 40101300 */   sll       $v0, $s3, 1
    /* 2D40C 8003CC0C 0400023C */  lui        $v0, (0x40000 >> 16)
    /* 2D410 8003CC10 24102202 */  and        $v0, $s1, $v0
    /* 2D414 8003CC14 06004010 */  beqz       $v0, .L8003CC30
    /* 2D418 8003CC18 40101300 */   sll       $v0, $s3, 1
  .L8003CC1C:
    /* 2D41C 8003CC1C 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2D420 8003CC20 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2D424 8003CC24 3C000496 */  lhu        $a0, 0x3C($s0)
    /* 2D428 8003CC28 21104300 */  addu       $v0, $v0, $v1
    /* 2D42C 8003CC2C 0A0044A4 */  sh         $a0, 0xA($v0)
  .L8003CC30:
    /* 2D430 8003CC30 03004016 */  bnez       $s2, .L8003CC40
    /* 2D434 8003CC34 00082232 */   andi      $v0, $s1, 0x800
    /* 2D438 8003CC38 1C004010 */  beqz       $v0, .L8003CCAC
    /* 2D43C 8003CC3C 00000000 */   nop
  .L8003CC40:
    /* 2D440 8003CC40 30000596 */  lhu        $a1, 0x30($s0)
    /* 2D444 8003CC44 00000000 */  nop
    /* 2D448 8003CC48 8000A22C */  sltiu      $v0, $a1, 0x80
    /* 2D44C 8003CC4C 02004014 */  bnez       $v0, .L8003CC58
    /* 2D450 8003CC50 00000000 */   nop
    /* 2D454 8003CC54 7F000524 */  addiu      $a1, $zero, 0x7F
  .L8003CC58:
    /* 2D458 8003CC58 04004016 */  bnez       $s2, .L8003CC6C
    /* 2D45C 8003CC5C 21300000 */   addu      $a2, $zero, $zero
    /* 2D460 8003CC60 00012232 */  andi       $v0, $s1, 0x100
    /* 2D464 8003CC64 06004010 */  beqz       $v0, .L8003CC80
    /* 2D468 8003CC68 00000000 */   nop
  .L8003CC6C:
    /* 2D46C 8003CC6C 2400038E */  lw         $v1, 0x24($s0)
    /* 2D470 8003CC70 05000224 */  addiu      $v0, $zero, 0x5
    /* 2D474 8003CC74 02006214 */  bne        $v1, $v0, .L8003CC80
    /* 2D478 8003CC78 00000000 */   nop
    /* 2D47C 8003CC7C 80000624 */  addiu      $a2, $zero, 0x80
  .L8003CC80:
    /* 2D480 8003CC80 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D484 8003CC84 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D488 8003CC88 40201300 */  sll        $a0, $s3, 1
    /* 2D48C 8003CC8C 21208200 */  addu       $a0, $a0, $v0
    /* 2D490 8003CC90 08008294 */  lhu        $v0, 0x8($a0)
    /* 2D494 8003CC94 00000000 */  nop
    /* 2D498 8003CC98 FF004330 */  andi       $v1, $v0, 0xFF
    /* 2D49C 8003CC9C 2510A600 */  or         $v0, $a1, $a2
    /* 2D4A0 8003CCA0 00120200 */  sll        $v0, $v0, 8
    /* 2D4A4 8003CCA4 25186200 */  or         $v1, $v1, $v0
    /* 2D4A8 8003CCA8 080083A4 */  sh         $v1, 0x8($a0)
  .L8003CCAC:
    /* 2D4AC 8003CCAC 03004016 */  bnez       $s2, .L8003CCBC
    /* 2D4B0 8003CCB0 00102232 */   andi      $v0, $s1, 0x1000
    /* 2D4B4 8003CCB4 10004010 */  beqz       $v0, .L8003CCF8
    /* 2D4B8 8003CCB8 00000000 */   nop
  .L8003CCBC:
    /* 2D4BC 8003CCBC 32000596 */  lhu        $a1, 0x32($s0)
    /* 2D4C0 8003CCC0 00000000 */  nop
    /* 2D4C4 8003CCC4 1000A22C */  sltiu      $v0, $a1, 0x10
    /* 2D4C8 8003CCC8 02004014 */  bnez       $v0, .L8003CCD4
    /* 2D4CC 8003CCCC 00000000 */   nop
    /* 2D4D0 8003CCD0 0F000524 */  addiu      $a1, $zero, 0xF
  .L8003CCD4:
    /* 2D4D4 8003CCD4 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D4D8 8003CCD8 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D4DC 8003CCDC 40201300 */  sll        $a0, $s3, 1
    /* 2D4E0 8003CCE0 21208200 */  addu       $a0, $a0, $v0
    /* 2D4E4 8003CCE4 08008294 */  lhu        $v0, 0x8($a0)
    /* 2D4E8 8003CCE8 00190500 */  sll        $v1, $a1, 4
    /* 2D4EC 8003CCEC 0FFF4230 */  andi       $v0, $v0, 0xFF0F
    /* 2D4F0 8003CCF0 25104300 */  or         $v0, $v0, $v1
    /* 2D4F4 8003CCF4 080082A4 */  sh         $v0, 0x8($a0)
  .L8003CCF8:
    /* 2D4F8 8003CCF8 03004016 */  bnez       $s2, .L8003CD08
    /* 2D4FC 8003CCFC 00202232 */   andi      $v0, $s1, 0x2000
    /* 2D500 8003CD00 2B004010 */  beqz       $v0, .L8003CDB0
    /* 2D504 8003CD04 00000000 */   nop
  .L8003CD08:
    /* 2D508 8003CD08 34000596 */  lhu        $a1, 0x34($s0)
    /* 2D50C 8003CD0C 00000000 */  nop
    /* 2D510 8003CD10 8000A22C */  sltiu      $v0, $a1, 0x80
    /* 2D514 8003CD14 02004014 */  bnez       $v0, .L8003CD20
    /* 2D518 8003CD18 00000000 */   nop
    /* 2D51C 8003CD1C 7F000524 */  addiu      $a1, $zero, 0x7F
  .L8003CD20:
    /* 2D520 8003CD20 04004016 */  bnez       $s2, .L8003CD34
    /* 2D524 8003CD24 00010624 */   addiu     $a2, $zero, 0x100
    /* 2D528 8003CD28 00022232 */  andi       $v0, $s1, 0x200
    /* 2D52C 8003CD2C 15004010 */  beqz       $v0, .L8003CD84
    /* 2D530 8003CD30 00000000 */   nop
  .L8003CD34:
    /* 2D534 8003CD34 2800038E */  lw         $v1, 0x28($s0)
    /* 2D538 8003CD38 05000224 */  addiu      $v0, $zero, 0x5
    /* 2D53C 8003CD3C 0E006210 */  beq        $v1, $v0, .L8003CD78
    /* 2D540 8003CD40 06006228 */   slti      $v0, $v1, 0x6
    /* 2D544 8003CD44 05004010 */  beqz       $v0, .L8003CD5C
    /* 2D548 8003CD48 01000224 */   addiu     $v0, $zero, 0x1
    /* 2D54C 8003CD4C 08006210 */  beq        $v1, $v0, .L8003CD70
    /* 2D550 8003CD50 00000000 */   nop
    /* 2D554 8003CD54 61F30008 */  j          .L8003CD84
    /* 2D558 8003CD58 00000000 */   nop
  .L8003CD5C:
    /* 2D55C 8003CD5C 07000224 */  addiu      $v0, $zero, 0x7
    /* 2D560 8003CD60 07006210 */  beq        $v1, $v0, .L8003CD80
    /* 2D564 8003CD64 00000000 */   nop
    /* 2D568 8003CD68 61F30008 */  j          .L8003CD84
    /* 2D56C 8003CD6C 00000000 */   nop
  .L8003CD70:
    /* 2D570 8003CD70 61F30008 */  j          .L8003CD84
    /* 2D574 8003CD74 21300000 */   addu      $a2, $zero, $zero
  .L8003CD78:
    /* 2D578 8003CD78 61F30008 */  j          .L8003CD84
    /* 2D57C 8003CD7C 00020624 */   addiu     $a2, $zero, 0x200
  .L8003CD80:
    /* 2D580 8003CD80 00030624 */  addiu      $a2, $zero, 0x300
  .L8003CD84:
    /* 2D584 8003CD84 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D588 8003CD88 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D58C 8003CD8C 40201300 */  sll        $a0, $s3, 1
    /* 2D590 8003CD90 21208200 */  addu       $a0, $a0, $v0
    /* 2D594 8003CD94 0A008294 */  lhu        $v0, 0xA($a0)
    /* 2D598 8003CD98 00000000 */  nop
    /* 2D59C 8003CD9C 3F004330 */  andi       $v1, $v0, 0x3F
    /* 2D5A0 8003CDA0 2510A600 */  or         $v0, $a1, $a2
    /* 2D5A4 8003CDA4 80110200 */  sll        $v0, $v0, 6
    /* 2D5A8 8003CDA8 25186200 */  or         $v1, $v1, $v0
    /* 2D5AC 8003CDAC 0A0083A4 */  sh         $v1, 0xA($a0)
  .L8003CDB0:
    /* 2D5B0 8003CDB0 03004016 */  bnez       $s2, .L8003CDC0
    /* 2D5B4 8003CDB4 00402232 */   andi      $v0, $s1, 0x4000
    /* 2D5B8 8003CDB8 1C004010 */  beqz       $v0, .L8003CE2C
    /* 2D5BC 8003CDBC 00000000 */   nop
  .L8003CDC0:
    /* 2D5C0 8003CDC0 36000596 */  lhu        $a1, 0x36($s0)
    /* 2D5C4 8003CDC4 00000000 */  nop
    /* 2D5C8 8003CDC8 2000A22C */  sltiu      $v0, $a1, 0x20
    /* 2D5CC 8003CDCC 02004014 */  bnez       $v0, .L8003CDD8
    /* 2D5D0 8003CDD0 00000000 */   nop
    /* 2D5D4 8003CDD4 1F000524 */  addiu      $a1, $zero, 0x1F
  .L8003CDD8:
    /* 2D5D8 8003CDD8 04004016 */  bnez       $s2, .L8003CDEC
    /* 2D5DC 8003CDDC 21300000 */   addu      $a2, $zero, $zero
    /* 2D5E0 8003CDE0 00042232 */  andi       $v0, $s1, 0x400
    /* 2D5E4 8003CDE4 08004010 */  beqz       $v0, .L8003CE08
    /* 2D5E8 8003CDE8 00000000 */   nop
  .L8003CDEC:
    /* 2D5EC 8003CDEC 2C00038E */  lw         $v1, 0x2C($s0)
    /* 2D5F0 8003CDF0 03000224 */  addiu      $v0, $zero, 0x3
    /* 2D5F4 8003CDF4 04006210 */  beq        $v1, $v0, .L8003CE08
    /* 2D5F8 8003CDF8 07000224 */   addiu     $v0, $zero, 0x7
    /* 2D5FC 8003CDFC 02006214 */  bne        $v1, $v0, .L8003CE08
    /* 2D600 8003CE00 00000000 */   nop
    /* 2D604 8003CE04 20000624 */  addiu      $a2, $zero, 0x20
  .L8003CE08:
    /* 2D608 8003CE08 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D60C 8003CE0C 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D610 8003CE10 40201300 */  sll        $a0, $s3, 1
    /* 2D614 8003CE14 21208200 */  addu       $a0, $a0, $v0
    /* 2D618 8003CE18 0A008294 */  lhu        $v0, 0xA($a0)
    /* 2D61C 8003CE1C 2518A600 */  or         $v1, $a1, $a2
    /* 2D620 8003CE20 C0FF4230 */  andi       $v0, $v0, 0xFFC0
    /* 2D624 8003CE24 25104300 */  or         $v0, $v0, $v1
    /* 2D628 8003CE28 0A0082A4 */  sh         $v0, 0xA($a0)
  .L8003CE2C:
    /* 2D62C 8003CE2C 03004016 */  bnez       $s2, .L8003CE3C
    /* 2D630 8003CE30 00802232 */   andi      $v0, $s1, 0x8000
    /* 2D634 8003CE34 10004010 */  beqz       $v0, .L8003CE78
    /* 2D638 8003CE38 00000000 */   nop
  .L8003CE3C:
    /* 2D63C 8003CE3C 38000596 */  lhu        $a1, 0x38($s0)
    /* 2D640 8003CE40 00000000 */  nop
    /* 2D644 8003CE44 1000A22C */  sltiu      $v0, $a1, 0x10
    /* 2D648 8003CE48 02004014 */  bnez       $v0, .L8003CE54
    /* 2D64C 8003CE4C 00000000 */   nop
    /* 2D650 8003CE50 0F000524 */  addiu      $a1, $zero, 0xF
  .L8003CE54:
    /* 2D654 8003CE54 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2D658 8003CE58 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2D65C 8003CE5C 40181300 */  sll        $v1, $s3, 1
    /* 2D660 8003CE60 21186200 */  addu       $v1, $v1, $v0
    /* 2D664 8003CE64 08006294 */  lhu        $v0, 0x8($v1)
    /* 2D668 8003CE68 00000000 */  nop
    /* 2D66C 8003CE6C F0FF4230 */  andi       $v0, $v0, 0xFFF0
    /* 2D670 8003CE70 25104500 */  or         $v0, $v0, $a1
    /* 2D674 8003CE74 080062A4 */  sh         $v0, 0x8($v1)
  .L8003CE78:
    /* 2D678 8003CE78 01009426 */  addiu      $s4, $s4, 0x1
    /* 2D67C 8003CE7C 1800822A */  slti       $v0, $s4, 0x18
    /* 2D680 8003CE80 AEFE4014 */  bnez       $v0, .L8003C93C
    /* 2D684 8003CE84 0200B526 */   addiu     $s5, $s5, 0x2
    /* 2D688 8003CE88 01000224 */  addiu      $v0, $zero, 0x1
    /* 2D68C 8003CE8C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2D690 8003CE90 B1F30008 */  j          .L8003CEC4
    /* 2D694 8003CE94 1000A0AF */   sw        $zero, 0x10($sp)
  .L8003CE98:
    /* 2D698 8003CE98 1400A38F */  lw         $v1, 0x14($sp)
    /* 2D69C 8003CE9C 00000000 */  nop
    /* 2D6A0 8003CEA0 40100300 */  sll        $v0, $v1, 1
    /* 2D6A4 8003CEA4 21104300 */  addu       $v0, $v0, $v1
    /* 2D6A8 8003CEA8 80100200 */  sll        $v0, $v0, 2
    /* 2D6AC 8003CEAC 21104300 */  addu       $v0, $v0, $v1
    /* 2D6B0 8003CEB0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2D6B4 8003CEB4 1000A28F */  lw         $v0, 0x10($sp)
    /* 2D6B8 8003CEB8 00000000 */  nop
    /* 2D6BC 8003CEBC 01004224 */  addiu      $v0, $v0, 0x1
    /* 2D6C0 8003CEC0 1000A2AF */  sw         $v0, 0x10($sp)
  .L8003CEC4:
    /* 2D6C4 8003CEC4 1000A28F */  lw         $v0, 0x10($sp)
    /* 2D6C8 8003CEC8 00000000 */  nop
    /* 2D6CC 8003CECC 02004228 */  slti       $v0, $v0, 0x2
    /* 2D6D0 8003CED0 F1FF4014 */  bnez       $v0, .L8003CE98
    /* 2D6D4 8003CED4 00000000 */   nop
    /* 2D6D8 8003CED8 3000BF8F */  lw         $ra, 0x30($sp)
    /* 2D6DC 8003CEDC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 2D6E0 8003CEE0 2800B48F */  lw         $s4, 0x28($sp)
    /* 2D6E4 8003CEE4 2400B38F */  lw         $s3, 0x24($sp)
    /* 2D6E8 8003CEE8 2000B28F */  lw         $s2, 0x20($sp)
    /* 2D6EC 8003CEEC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2D6F0 8003CEF0 1800B08F */  lw         $s0, 0x18($sp)
    /* 2D6F4 8003CEF4 0800E003 */  jr         $ra
    /* 2D6F8 8003CEF8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel SpuSetVoiceAttr
    /* 2D6FC 8003CEFC 00000000 */  nop
    /* 2D700 8003CF00 00000000 */  nop
