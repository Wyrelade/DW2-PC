nonmatching func_8006DCCC, 0xA54

glabel func_8006DCCC
    /* A96C 8006DCCC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* A970 8006DCD0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A974 8006DCD4 21988000 */  addu       $s3, $a0, $zero
    /* A978 8006DCD8 2000B4AF */  sw         $s4, 0x20($sp)
    /* A97C 8006DCDC 01001424 */  addiu      $s4, $zero, 0x1
    /* A980 8006DCE0 2400BFAF */  sw         $ra, 0x24($sp)
    /* A984 8006DCE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* A988 8006DCE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* A98C 8006DCEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* A990 8006DCF0 2C00728E */  lw         $s2, 0x2C($s3)
    /* A994 8006DCF4 1000638E */  lw         $v1, 0x10($s3)
    /* A998 8006DCF8 3400718E */  lw         $s1, 0x34($s3)
    /* A99C 8006DCFC 31007410 */  beq        $v1, $s4, .L8006DDC4
    /* A9A0 8006DD00 02006228 */   slti      $v0, $v1, 0x2
    /* A9A4 8006DD04 7E024010 */  beqz       $v0, .L8006E700
    /* A9A8 8006DD08 00000000 */   nop
    /* A9AC 8006DD0C 7C026014 */  bnez       $v1, .L8006E700
    /* A9B0 8006DD10 21204002 */   addu      $a0, $s2, $zero
    /* A9B4 8006DD14 2270000C */  jal        Mem_FillWordsNeg1
    /* A9B8 8006DD18 12000524 */   addiu     $a1, $zero, 0x12
    /* A9BC 8006DD1C 21204002 */  addu       $a0, $s2, $zero
    /* A9C0 8006DD20 0680103C */  lui        $s0, %hi(D_8005E6F1)
    /* A9C4 8006DD24 F1E61026 */  addiu      $s0, $s0, %lo(D_8005E6F1)
    /* A9C8 8006DD28 21280002 */  addu       $a1, $s0, $zero
    /* A9CC 8006DD2C 21300000 */  addu       $a2, $zero, $zero
    /* A9D0 8006DD30 0780033C */  lui        $v1, %hi(D_800705DC)
    /* A9D4 8006DD34 DC056224 */  addiu      $v0, $v1, %lo(D_800705DC)
    /* A9D8 8006DD38 02004794 */  lhu        $a3, 0x2($v0)
    /* A9DC 8006DD3C DC056294 */  lhu        $v0, %lo(D_800705DC)($v1)
    /* A9E0 8006DD40 003C0700 */  sll        $a3, $a3, 16
    /* A9E4 8006DD44 3E4D000C */  jal        Text_OpenPacked
    /* A9E8 8006DD48 25384700 */   or        $a3, $v0, $a3
    /* A9EC 8006DD4C 0D030424 */  addiu      $a0, $zero, 0x30D
    /* A9F0 8006DD50 21282002 */  addu       $a1, $s1, $zero
    /* A9F4 8006DD54 1F44000C */  jal        Task_Create
    /* A9F8 8006DD58 21308002 */   addu      $a2, $s4, $zero
    /* A9FC 8006DD5C 5BFF0396 */  lhu        $v1, -0xA5($s0)
    /* AA00 8006DD60 EA000224 */  addiu      $v0, $zero, 0xEA
    /* AA04 8006DD64 03006214 */  bne        $v1, $v0, .L8006DD74
    /* AA08 8006DD68 EB000224 */   addiu     $v0, $zero, 0xEB
    /* AA0C 8006DD6C 62B70108 */  j          .L8006DD88
    /* AA10 8006DD70 480040AE */   sw        $zero, 0x48($s2)
  .L8006DD74:
    /* AA14 8006DD74 03006214 */  bne        $v1, $v0, .L8006DD84
    /* AA18 8006DD78 02000224 */   addiu     $v0, $zero, 0x2
    /* AA1C 8006DD7C 62B70108 */  j          .L8006DD88
    /* AA20 8006DD80 480054AE */   sw        $s4, 0x48($s2)
  .L8006DD84:
    /* AA24 8006DD84 480042AE */  sw         $v0, 0x48($s2)
  .L8006DD88:
    /* AA28 8006DD88 F3B4010C */  jal        func_8006D3CC
    /* AA2C 8006DD8C 21206002 */   addu      $a0, $s3, $zero
    /* AA30 8006DD90 FF07053C */  lui        $a1, (0x7FFFFFF >> 16)
    /* AA34 8006DD94 FFFFA534 */  ori        $a1, $a1, (0x7FFFFFF & 0xFFFF)
    /* AA38 8006DD98 7F00033C */  lui        $v1, (0x7FFFFE >> 16)
    /* AA3C 8006DD9C FEFF6334 */  ori        $v1, $v1, (0x7FFFFE & 0xFFFF)
    /* AA40 8006DDA0 4800428E */  lw         $v0, 0x48($s2)
    /* AA44 8006DDA4 21206002 */  addu       $a0, $s3, $zero
    /* AA48 8006DDA8 540045AE */  sw         $a1, 0x54($s2)
    /* AA4C 8006DDAC 580043AE */  sw         $v1, 0x58($s2)
    /* AA50 8006DDB0 03004224 */  addiu      $v0, $v0, 0x3
    /* AA54 8006DDB4 5145000C */  jal        Task_NextState0
    /* AA58 8006DDB8 4C0042AE */   sw        $v0, 0x4C($s2)
    /* AA5C 8006DDBC C0B90108 */  j          .L8006E700
    /* AA60 8006DDC0 00000000 */   nop
  .L8006DDC4:
    /* AA64 8006DDC4 1400638E */  lw         $v1, 0x14($s3)
    /* AA68 8006DDC8 00000000 */  nop
    /* AA6C 8006DDCC 1200622C */  sltiu      $v0, $v1, 0x12
    /* AA70 8006DDD0 08004010 */  beqz       $v0, .L8006DDF4
    /* AA74 8006DDD4 0680023C */   lui       $v0, %hi(jtbl_8006359C)
    /* AA78 8006DDD8 9C354224 */  addiu      $v0, $v0, %lo(jtbl_8006359C)
    /* AA7C 8006DDDC 80180300 */  sll        $v1, $v1, 2
    /* AA80 8006DDE0 21186200 */  addu       $v1, $v1, $v0
    /* AA84 8006DDE4 0000628C */  lw         $v0, 0x0($v1)
    /* AA88 8006DDE8 00000000 */  nop
    /* AA8C 8006DDEC 08004000 */  jr         $v0
    /* AA90 8006DDF0 00000000 */   nop
  jlabel .L8006DDF4
    /* AA94 8006DDF4 1800638E */  lw         $v1, 0x18($s3)
    /* AA98 8006DDF8 00000000 */  nop
    /* AA9C 8006DDFC 03006010 */  beqz       $v1, .L8006DE0C
    /* AAA0 8006DE00 01000224 */   addiu     $v0, $zero, 0x1
    /* AAA4 8006DE04 22006210 */  beq        $v1, $v0, .L8006DE90
    /* AAA8 8006DE08 0680023C */   lui       $v0, %hi(D_8005F704)
  .L8006DE0C:
    /* AAAC 8006DE0C 04004426 */  addiu      $a0, $s2, 0x4
    /* AAB0 8006DE10 3E010524 */  addiu      $a1, $zero, 0x13E
    /* AAB4 8006DE14 21300000 */  addu       $a2, $zero, $zero
    /* AAB8 8006DE18 0780103C */  lui        $s0, %hi(D_800705DC)
    /* AABC 8006DE1C DC051026 */  addiu      $s0, $s0, %lo(D_800705DC)
    /* AAC0 8006DE20 06000796 */  lhu        $a3, 0x6($s0)
    /* AAC4 8006DE24 04000296 */  lhu        $v0, 0x4($s0)
    /* AAC8 8006DE28 003C0700 */  sll        $a3, $a3, 16
    /* AACC 8006DE2C F26F000C */  jal        Text_OpenById
    /* AAD0 8006DE30 25384700 */   or        $a3, $v0, $a3
    /* AAD4 8006DE34 08004426 */  addiu      $a0, $s2, 0x8
    /* AAD8 8006DE38 21300000 */  addu       $a2, $zero, $zero
    /* AADC 8006DE3C 4800458E */  lw         $a1, 0x48($s2)
    /* AAE0 8006DE40 0A000796 */  lhu        $a3, 0xA($s0)
    /* AAE4 8006DE44 08000296 */  lhu        $v0, 0x8($s0)
    /* AAE8 8006DE48 3F01A524 */  addiu      $a1, $a1, 0x13F
    /* AAEC 8006DE4C 003C0700 */  sll        $a3, $a3, 16
    /* AAF0 8006DE50 F26F000C */  jal        Text_OpenById
    /* AAF4 8006DE54 25384700 */   or        $a3, $v0, $a3
    /* AAF8 8006DE58 1C004426 */  addiu      $a0, $s2, 0x1C
    /* AAFC 8006DE5C 21380000 */  addu       $a3, $zero, $zero
    /* AB00 8006DE60 4800458E */  lw         $a1, 0x48($s2)
    /* AB04 8006DE64 1E000696 */  lhu        $a2, 0x1E($s0)
    /* AB08 8006DE68 1C000296 */  lhu        $v0, 0x1C($s0)
    /* AB0C 8006DE6C 3B01A524 */  addiu      $a1, $a1, 0x13B
    /* AB10 8006DE70 00340600 */  sll        $a2, $a2, 16
    /* AB14 8006DE74 B0B4010C */  jal        func_8006D2C0
    /* AB18 8006DE78 25304600 */   or        $a2, $v0, $a2
    /* AB1C 8006DE7C 21206002 */  addu       $a0, $s3, $zero
    /* AB20 8006DE80 01000224 */  addiu      $v0, $zero, 0x1
    /* AB24 8006DE84 6045000C */  jal        Task_NextState2
    /* AB28 8006DE88 500042AE */   sw        $v0, 0x50($s2)
    /* AB2C 8006DE8C 0680023C */  lui        $v0, %hi(D_8005F704)
  .L8006DE90:
    /* AB30 8006DE90 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* AB34 8006DE94 00000000 */  nop
    /* AB38 8006DE98 19024018 */  blez       $v0, .L8006E700
    /* AB3C 8006DE9C 13000424 */   addiu     $a0, $zero, 0x13
    /* AB40 8006DEA0 A369000C */  jal        Snd_PlayById
    /* AB44 8006DEA4 21280000 */   addu      $a1, $zero, $zero
    /* AB48 8006DEA8 E26E000C */  jal        Text_Close
    /* AB4C 8006DEAC 04004426 */   addiu     $a0, $s2, 0x4
    /* AB50 8006DEB0 E26E000C */  jal        Text_Close
    /* AB54 8006DEB4 08004426 */   addiu     $a0, $s2, 0x8
    /* AB58 8006DEB8 E26E000C */  jal        Text_Close
    /* AB5C 8006DEBC 1C004426 */   addiu     $a0, $s2, 0x1C
    /* AB60 8006DEC0 3AB80108 */  j          .L8006E0E8
    /* AB64 8006DEC4 00000000 */   nop
  jlabel .L8006DEC8
    /* AB68 8006DEC8 1800638E */  lw         $v1, 0x18($s3)
    /* AB6C 8006DECC 00000000 */  nop
    /* AB70 8006DED0 03006010 */  beqz       $v1, .L8006DEE0
    /* AB74 8006DED4 01000224 */   addiu     $v0, $zero, 0x1
    /* AB78 8006DED8 42006210 */  beq        $v1, $v0, .L8006DFE4
    /* AB7C 8006DEDC 0680033C */   lui       $v1, %hi(Save_GameState)
  .L8006DEE0:
    /* AB80 8006DEE0 04004426 */  addiu      $a0, $s2, 0x4
    /* AB84 8006DEE4 42010524 */  addiu      $a1, $zero, 0x142
    /* AB88 8006DEE8 21300000 */  addu       $a2, $zero, $zero
    /* AB8C 8006DEEC 0780023C */  lui        $v0, %hi(D_800705DC)
    /* AB90 8006DEF0 DC055024 */  addiu      $s0, $v0, %lo(D_800705DC)
    /* AB94 8006DEF4 06000796 */  lhu        $a3, 0x6($s0)
    /* AB98 8006DEF8 04000296 */  lhu        $v0, 0x4($s0)
    /* AB9C 8006DEFC 003C0700 */  sll        $a3, $a3, 16
    /* ABA0 8006DF00 F26F000C */  jal        Text_OpenById
    /* ABA4 8006DF04 25384700 */   or        $a3, $v0, $a3
    /* ABA8 8006DF08 21206002 */  addu       $a0, $s3, $zero
    /* ABAC 8006DF0C 21B5010C */  jal        func_8006D484
    /* ABB0 8006DF10 75000524 */   addiu     $a1, $zero, 0x75
    /* ABB4 8006DF14 02004010 */  beqz       $v0, .L8006DF20
    /* ABB8 8006DF18 76000424 */   addiu     $a0, $zero, 0x76
    /* ABBC 8006DF1C 75000424 */  addiu      $a0, $zero, 0x75
  .L8006DF20:
    /* ABC0 8006DF20 1278000C */  jal        Item_GetNameText
    /* ABC4 8006DF24 00000000 */   nop
    /* ABC8 8006DF28 08004426 */  addiu      $a0, $s2, 0x8
    /* ABCC 8006DF2C 21284000 */  addu       $a1, $v0, $zero
    /* ABD0 8006DF30 21300000 */  addu       $a2, $zero, $zero
    /* ABD4 8006DF34 0A000796 */  lhu        $a3, 0xA($s0)
    /* ABD8 8006DF38 08000296 */  lhu        $v0, 0x8($s0)
    /* ABDC 8006DF3C 003C0700 */  sll        $a3, $a3, 16
    /* ABE0 8006DF40 3E4D000C */  jal        Text_OpenPacked
    /* ABE4 8006DF44 25384700 */   or        $a3, $v0, $a3
    /* ABE8 8006DF48 1278000C */  jal        Item_GetNameText
    /* ABEC 8006DF4C 77000424 */   addiu     $a0, $zero, 0x77
    /* ABF0 8006DF50 0C004426 */  addiu      $a0, $s2, 0xC
    /* ABF4 8006DF54 21284000 */  addu       $a1, $v0, $zero
    /* ABF8 8006DF58 21300000 */  addu       $a2, $zero, $zero
    /* ABFC 8006DF5C 0E000796 */  lhu        $a3, 0xE($s0)
    /* AC00 8006DF60 0C000296 */  lhu        $v0, 0xC($s0)
    /* AC04 8006DF64 003C0700 */  sll        $a3, $a3, 16
    /* AC08 8006DF68 3E4D000C */  jal        Text_OpenPacked
    /* AC0C 8006DF6C 25384700 */   or        $a3, $v0, $a3
    /* AC10 8006DF70 21206002 */  addu       $a0, $s3, $zero
    /* AC14 8006DF74 21B5010C */  jal        func_8006D484
    /* AC18 8006DF78 73000524 */   addiu     $a1, $zero, 0x73
    /* AC1C 8006DF7C 02004010 */  beqz       $v0, .L8006DF88
    /* AC20 8006DF80 74000424 */   addiu     $a0, $zero, 0x74
    /* AC24 8006DF84 73000424 */  addiu      $a0, $zero, 0x73
  .L8006DF88:
    /* AC28 8006DF88 1278000C */  jal        Item_GetNameText
    /* AC2C 8006DF8C 00000000 */   nop
    /* AC30 8006DF90 10004426 */  addiu      $a0, $s2, 0x10
    /* AC34 8006DF94 21284000 */  addu       $a1, $v0, $zero
    /* AC38 8006DF98 21300000 */  addu       $a2, $zero, $zero
    /* AC3C 8006DF9C 12000796 */  lhu        $a3, 0x12($s0)
    /* AC40 8006DFA0 10000296 */  lhu        $v0, 0x10($s0)
    /* AC44 8006DFA4 003C0700 */  sll        $a3, $a3, 16
    /* AC48 8006DFA8 3E4D000C */  jal        Text_OpenPacked
    /* AC4C 8006DFAC 25384700 */   or        $a3, $v0, $a3
    /* AC50 8006DFB0 1C004426 */  addiu      $a0, $s2, 0x1C
    /* AC54 8006DFB4 43010524 */  addiu      $a1, $zero, 0x143
    /* AC58 8006DFB8 21380000 */  addu       $a3, $zero, $zero
    /* AC5C 8006DFBC 1E000696 */  lhu        $a2, 0x1E($s0)
    /* AC60 8006DFC0 1C000296 */  lhu        $v0, 0x1C($s0)
    /* AC64 8006DFC4 00340600 */  sll        $a2, $a2, 16
    /* AC68 8006DFC8 B0B4010C */  jal        func_8006D2C0
    /* AC6C 8006DFCC 25304600 */   or        $a2, $v0, $a2
    /* AC70 8006DFD0 21206002 */  addu       $a0, $s3, $zero
    /* AC74 8006DFD4 03000224 */  addiu      $v0, $zero, 0x3
    /* AC78 8006DFD8 6045000C */  jal        Task_NextState2
    /* AC7C 8006DFDC 500042AE */   sw        $v0, 0x50($s2)
    /* AC80 8006DFE0 0680033C */  lui        $v1, %hi(Save_GameState)
  .L8006DFE4:
    /* AC84 8006DFE4 2800628E */  lw         $v0, 0x28($s3)
    /* AC88 8006DFE8 00000000 */  nop
    /* AC8C 8006DFEC 10004230 */  andi       $v0, $v0, 0x10
    /* AC90 8006DFF0 08004010 */  beqz       $v0, .L8006E014
    /* AC94 8006DFF4 20E67024 */   addiu     $s0, $v1, %lo(Save_GameState)
    /* AC98 8006DFF8 21206002 */  addu       $a0, $s3, $zero
    /* AC9C 8006DFFC 21B5010C */  jal        func_8006D484
    /* ACA0 8006E000 75000524 */   addiu     $a1, $zero, 0x75
    /* ACA4 8006E004 04004010 */  beqz       $v0, .L8006E018
    /* ACA8 8006E008 76000324 */   addiu     $v1, $zero, 0x76
    /* ACAC 8006E00C 06B80108 */  j          .L8006E018
    /* ACB0 8006E010 75000324 */   addiu     $v1, $zero, 0x75
  .L8006E014:
    /* ACB4 8006E014 21180000 */  addu       $v1, $zero, $zero
  .L8006E018:
    /* ACB8 8006E018 21200000 */  addu       $a0, $zero, $zero
    /* ACBC 8006E01C 4E0003A6 */  sh         $v1, 0x4E($s0)
    /* ACC0 8006E020 0680033C */  lui        $v1, %hi(Save_GameState)
    /* ACC4 8006E024 2800628E */  lw         $v0, 0x28($s3)
    /* ACC8 8006E028 00000000 */  nop
    /* ACCC 8006E02C 10004230 */  andi       $v0, $v0, 0x10
    /* ACD0 8006E030 02004010 */  beqz       $v0, .L8006E03C
    /* ACD4 8006E034 20E67024 */   addiu     $s0, $v1, %lo(Save_GameState)
    /* ACD8 8006E038 77000424 */  addiu      $a0, $zero, 0x77
  .L8006E03C:
    /* ACDC 8006E03C 0680023C */  lui        $v0, %hi(D_8005F704)
    /* ACE0 8006E040 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* ACE4 8006E044 00000000 */  nop
    /* ACE8 8006E048 AD014018 */  blez       $v0, .L8006E700
    /* ACEC 8006E04C 500004A6 */   sh        $a0, 0x50($s0)
    /* ACF0 8006E050 14000424 */  addiu      $a0, $zero, 0x14
    /* ACF4 8006E054 A369000C */  jal        Snd_PlayById
    /* ACF8 8006E058 21280000 */   addu      $a1, $zero, $zero
    /* ACFC 8006E05C E26E000C */  jal        Text_Close
    /* AD00 8006E060 04004426 */   addiu     $a0, $s2, 0x4
    /* AD04 8006E064 E26E000C */  jal        Text_Close
    /* AD08 8006E068 08004426 */   addiu     $a0, $s2, 0x8
    /* AD0C 8006E06C E26E000C */  jal        Text_Close
    /* AD10 8006E070 0C004426 */   addiu     $a0, $s2, 0xC
    /* AD14 8006E074 E26E000C */  jal        Text_Close
    /* AD18 8006E078 10004426 */   addiu     $a0, $s2, 0x10
    /* AD1C 8006E07C E26E000C */  jal        Text_Close
    /* AD20 8006E080 1C004426 */   addiu     $a0, $s2, 0x1C
    /* AD24 8006E084 21206002 */  addu       $a0, $s3, $zero
    /* AD28 8006E088 21B5010C */  jal        func_8006D484
    /* AD2C 8006E08C 75000524 */   addiu     $a1, $zero, 0x75
    /* AD30 8006E090 02004010 */  beqz       $v0, .L8006E09C
    /* AD34 8006E094 76000324 */   addiu     $v1, $zero, 0x76
    /* AD38 8006E098 75000324 */  addiu      $v1, $zero, 0x75
  .L8006E09C:
    /* AD3C 8006E09C 21206002 */  addu       $a0, $s3, $zero
    /* AD40 8006E0A0 73000524 */  addiu      $a1, $zero, 0x73
    /* AD44 8006E0A4 77000224 */  addiu      $v0, $zero, 0x77
    /* AD48 8006E0A8 4E0003A6 */  sh         $v1, 0x4E($s0)
    /* AD4C 8006E0AC 21B5010C */  jal        func_8006D484
    /* AD50 8006E0B0 500002A6 */   sh        $v0, 0x50($s0)
    /* AD54 8006E0B4 02004010 */  beqz       $v0, .L8006E0C0
    /* AD58 8006E0B8 74000324 */   addiu     $v1, $zero, 0x74
    /* AD5C 8006E0BC 73000324 */  addiu      $v1, $zero, 0x73
  .L8006E0C0:
    /* AD60 8006E0C0 4E000596 */  lhu        $a1, 0x4E($s0)
    /* AD64 8006E0C4 21206002 */  addu       $a0, $s3, $zero
    /* AD68 8006E0C8 2FB5010C */  jal        func_8006D4BC
    /* AD6C 8006E0CC 4C0003A6 */   sh        $v1, 0x4C($s0)
    /* AD70 8006E0D0 50000596 */  lhu        $a1, 0x50($s0)
    /* AD74 8006E0D4 2FB5010C */  jal        func_8006D4BC
    /* AD78 8006E0D8 21206002 */   addu      $a0, $s3, $zero
    /* AD7C 8006E0DC 4C000596 */  lhu        $a1, 0x4C($s0)
    /* AD80 8006E0E0 2FB5010C */  jal        func_8006D4BC
    /* AD84 8006E0E4 21206002 */   addu      $a0, $s3, $zero
  .L8006E0E8:
    /* AD88 8006E0E8 5945000C */  jal        Task_NextState1
    /* AD8C 8006E0EC 21206002 */   addu      $a0, $s3, $zero
    /* AD90 8006E0F0 C0B90108 */  j          .L8006E700
    /* AD94 8006E0F4 00000000 */   nop
  jlabel .L8006E0F8
    /* AD98 8006E0F8 01001424 */  addiu      $s4, $zero, 0x1
    /* AD9C 8006E0FC 1400718E */  lw         $s1, 0x14($s3)
    /* ADA0 8006E100 1800638E */  lw         $v1, 0x18($s3)
    /* ADA4 8006E104 00000000 */  nop
    /* ADA8 8006E108 D3007410 */  beq        $v1, $s4, .L8006E458
    /* ADAC 8006E10C FEFF3026 */   addiu     $s0, $s1, -0x2
    /* ADB0 8006E110 02006228 */  slti       $v0, $v1, 0x2
    /* ADB4 8006E114 04004014 */  bnez       $v0, .L8006E128
    /* ADB8 8006E118 0780023C */   lui       $v0, %hi(D_80070624)
    /* ADBC 8006E11C 02000224 */  addiu      $v0, $zero, 0x2
    /* ADC0 8006E120 29006210 */  beq        $v1, $v0, .L8006E1C8
    /* ADC4 8006E124 0780023C */   lui       $v0, %hi(D_80070624)
  .L8006E128:
    /* ADC8 8006E128 24064224 */  addiu      $v0, $v0, %lo(D_80070624)
    /* ADCC 8006E12C 80181000 */  sll        $v1, $s0, 2
    /* ADD0 8006E130 21186200 */  addu       $v1, $v1, $v0
    /* ADD4 8006E134 0000658C */  lw         $a1, 0x0($v1)
    /* ADD8 8006E138 4FB5010C */  jal        func_8006D53C
    /* ADDC 8006E13C 21206002 */   addu      $a0, $s3, $zero
    /* ADE0 8006E140 E800428E */  lw         $v0, 0xE8($s2)
    /* ADE4 8006E144 00000000 */  nop
    /* ADE8 8006E148 42014010 */  beqz       $v0, .L8006E654
    /* ADEC 8006E14C 04004426 */   addiu     $a0, $s2, 0x4
    /* ADF0 8006E150 58012526 */  addiu      $a1, $s1, 0x158
    /* ADF4 8006E154 21300000 */  addu       $a2, $zero, $zero
    /* ADF8 8006E158 0780103C */  lui        $s0, %hi(D_800705DC)
    /* ADFC 8006E15C DC051026 */  addiu      $s0, $s0, %lo(D_800705DC)
    /* AE00 8006E160 06000796 */  lhu        $a3, 0x6($s0)
    /* AE04 8006E164 04000296 */  lhu        $v0, 0x4($s0)
    /* AE08 8006E168 003C0700 */  sll        $a3, $a3, 16
    /* AE0C 8006E16C F26F000C */  jal        Text_OpenById
    /* AE10 8006E170 25384700 */   or        $a3, $v0, $a3
    /* AE14 8006E174 08004426 */  addiu      $a0, $s2, 0x8
    /* AE18 8006E178 4F010524 */  addiu      $a1, $zero, 0x14F
    /* AE1C 8006E17C 21300000 */  addu       $a2, $zero, $zero
    /* AE20 8006E180 0A000796 */  lhu        $a3, 0xA($s0)
    /* AE24 8006E184 08000296 */  lhu        $v0, 0x8($s0)
    /* AE28 8006E188 003C0700 */  sll        $a3, $a3, 16
    /* AE2C 8006E18C F26F000C */  jal        Text_OpenById
    /* AE30 8006E190 25384700 */   or        $a3, $v0, $a3
    /* AE34 8006E194 1C004426 */  addiu      $a0, $s2, 0x1C
    /* AE38 8006E198 42012526 */  addiu      $a1, $s1, 0x142
    /* AE3C 8006E19C 21380000 */  addu       $a3, $zero, $zero
    /* AE40 8006E1A0 1E000696 */  lhu        $a2, 0x1E($s0)
    /* AE44 8006E1A4 1C000296 */  lhu        $v0, 0x1C($s0)
    /* AE48 8006E1A8 00340600 */  sll        $a2, $a2, 16
    /* AE4C 8006E1AC B0B4010C */  jal        func_8006D2C0
    /* AE50 8006E1B0 25304600 */   or        $a2, $v0, $a2
    /* AE54 8006E1B4 21206002 */  addu       $a0, $s3, $zero
    /* AE58 8006E1B8 500054AE */  sw         $s4, 0x50($s2)
    /* AE5C 8006E1BC B80154AE */  sw         $s4, 0x1B8($s2)
    /* AE60 8006E1C0 12B90108 */  j          .L8006E448
    /* AE64 8006E1C4 5C0054AE */   sw        $s4, 0x5C($s2)
  .L8006E1C8:
    /* AE68 8006E1C8 0680043C */  lui        $a0, %hi(Save_GameState)
    /* AE6C 8006E1CC 0780033C */  lui        $v1, %hi(D_8007064C)
    /* AE70 8006E1D0 4C066324 */  addiu      $v1, $v1, %lo(D_8007064C)
    /* AE74 8006E1D4 80101000 */  sll        $v0, $s0, 2
    /* AE78 8006E1D8 21104300 */  addu       $v0, $v0, $v1
    /* AE7C 8006E1DC 20E68424 */  addiu      $a0, $a0, %lo(Save_GameState)
    /* AE80 8006E1E0 0000438C */  lw         $v1, 0x0($v0)
    /* AE84 8006E1E4 2800628E */  lw         $v0, 0x28($s3)
    /* AE88 8006E1E8 40180300 */  sll        $v1, $v1, 1
    /* AE8C 8006E1EC 10004230 */  andi       $v0, $v0, 0x10
    /* AE90 8006E1F0 0A004010 */  beqz       $v0, .L8006E21C
    /* AE94 8006E1F4 21206400 */   addu      $a0, $v1, $a0
    /* AE98 8006E1F8 C001428E */  lw         $v0, 0x1C0($s2)
    /* AE9C 8006E1FC C401438E */  lw         $v1, 0x1C4($s2)
    /* AEA0 8006E200 00000000 */  nop
    /* AEA4 8006E204 21104300 */  addu       $v0, $v0, $v1
    /* AEA8 8006E208 40100200 */  sll        $v0, $v0, 1
    /* AEAC 8006E20C 21104202 */  addu       $v0, $s2, $v0
    /* AEB0 8006E210 EC004294 */  lhu        $v0, 0xEC($v0)
    /* AEB4 8006E214 89B80108 */  j          .L8006E224
    /* AEB8 8006E218 2C0082A4 */   sh        $v0, 0x2C($a0)
  .L8006E21C:
    /* AEBC 8006E21C 21100000 */  addu       $v0, $zero, $zero
    /* AEC0 8006E220 2C0082A4 */  sh         $v0, 0x2C($a0)
  .L8006E224:
    /* AEC4 8006E224 0680023C */  lui        $v0, %hi(Pad_State)
    /* AEC8 8006E228 F0F64424 */  addiu      $a0, $v0, %lo(Pad_State)
    /* AECC 8006E22C 3C008394 */  lhu        $v1, 0x3C($a0)
    /* AED0 8006E230 00000000 */  nop
    /* AED4 8006E234 00106230 */  andi       $v0, $v1, 0x1000
    /* AED8 8006E238 0D004010 */  beqz       $v0, .L8006E270
    /* AEDC 8006E23C 00406230 */   andi      $v0, $v1, 0x4000
    /* AEE0 8006E240 C001428E */  lw         $v0, 0x1C0($s2)
    /* AEE4 8006E244 00000000 */  nop
    /* AEE8 8006E248 03004010 */  beqz       $v0, .L8006E258
    /* AEEC 8006E24C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* AEF0 8006E250 ACB80108 */  j          .L8006E2B0
    /* AEF4 8006E254 C00142AE */   sw        $v0, 0x1C0($s2)
  .L8006E258:
    /* AEF8 8006E258 C401428E */  lw         $v0, 0x1C4($s2)
    /* AEFC 8006E25C 00000000 */  nop
    /* AF00 8006E260 E7004010 */  beqz       $v0, .L8006E600
    /* AF04 8006E264 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* AF08 8006E268 ACB80108 */  j          .L8006E2B0
    /* AF0C 8006E26C C40142AE */   sw        $v0, 0x1C4($s2)
  .L8006E270:
    /* AF10 8006E270 14004010 */  beqz       $v0, .L8006E2C4
    /* AF14 8006E274 09000224 */   addiu     $v0, $zero, 0x9
    /* AF18 8006E278 C001438E */  lw         $v1, 0x1C0($s2)
    /* AF1C 8006E27C 00000000 */  nop
    /* AF20 8006E280 03006210 */  beq        $v1, $v0, .L8006E290
    /* AF24 8006E284 01006224 */   addiu     $v0, $v1, 0x1
    /* AF28 8006E288 ACB80108 */  j          .L8006E2B0
    /* AF2C 8006E28C C00142AE */   sw        $v0, 0x1C0($s2)
  .L8006E290:
    /* AF30 8006E290 C401448E */  lw         $a0, 0x1C4($s2)
    /* AF34 8006E294 E800428E */  lw         $v0, 0xE8($s2)
    /* AF38 8006E298 09008324 */  addiu      $v1, $a0, 0x9
    /* AF3C 8006E29C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* AF40 8006E2A0 2A186200 */  slt        $v1, $v1, $v0
    /* AF44 8006E2A4 D6006010 */  beqz       $v1, .L8006E600
    /* AF48 8006E2A8 01008224 */   addiu     $v0, $a0, 0x1
    /* AF4C 8006E2AC C40142AE */  sw         $v0, 0x1C4($s2)
  .L8006E2B0:
    /* AF50 8006E2B0 0D000424 */  addiu      $a0, $zero, 0xD
    /* AF54 8006E2B4 A369000C */  jal        Snd_PlayById
    /* AF58 8006E2B8 21280000 */   addu      $a1, $zero, $zero
    /* AF5C 8006E2BC 81B90108 */  j          .L8006E604
    /* AF60 8006E2C0 01000224 */   addiu     $v0, $zero, 0x1
  .L8006E2C4:
    /* AF64 8006E2C4 1400828C */  lw         $v0, 0x14($a0)
    /* AF68 8006E2C8 00000000 */  nop
    /* AF6C 8006E2CC E3004018 */  blez       $v0, .L8006E65C
    /* AF70 8006E2D0 00000000 */   nop
    /* AF74 8006E2D4 C401428E */  lw         $v0, 0x1C4($s2)
    /* AF78 8006E2D8 C001438E */  lw         $v1, 0x1C0($s2)
    /* AF7C 8006E2DC 00000000 */  nop
    /* AF80 8006E2E0 21104300 */  addu       $v0, $v0, $v1
    /* AF84 8006E2E4 21104202 */  addu       $v0, $s2, $v0
    /* AF88 8006E2E8 72014290 */  lbu        $v0, 0x172($v0)
    /* AF8C 8006E2EC 00000000 */  nop
    /* AF90 8006E2F0 75004014 */  bnez       $v0, .L8006E4C8
    /* AF94 8006E2F4 14000424 */   addiu     $a0, $zero, 0x14
    /* AF98 8006E2F8 A369000C */  jal        Snd_PlayById
    /* AF9C 8006E2FC 21280000 */   addu      $a1, $zero, $zero
    /* AFA0 8006E300 0680063C */  lui        $a2, %hi(Save_GameState)
    /* AFA4 8006E304 20E6C624 */  addiu      $a2, $a2, %lo(Save_GameState)
    /* AFA8 8006E308 0780023C */  lui        $v0, %hi(D_8007064C)
    /* AFAC 8006E30C 4C064224 */  addiu      $v0, $v0, %lo(D_8007064C)
    /* AFB0 8006E310 80281000 */  sll        $a1, $s0, 2
    /* AFB4 8006E314 2128A200 */  addu       $a1, $a1, $v0
    /* AFB8 8006E318 0000A38C */  lw         $v1, 0x0($a1)
    /* AFBC 8006E31C C001428E */  lw         $v0, 0x1C0($s2)
    /* AFC0 8006E320 C401448E */  lw         $a0, 0x1C4($s2)
    /* AFC4 8006E324 40180300 */  sll        $v1, $v1, 1
    /* AFC8 8006E328 21104400 */  addu       $v0, $v0, $a0
    /* AFCC 8006E32C 40100200 */  sll        $v0, $v0, 1
    /* AFD0 8006E330 21104202 */  addu       $v0, $s2, $v0
    /* AFD4 8006E334 EC004294 */  lhu        $v0, 0xEC($v0)
    /* AFD8 8006E338 21186600 */  addu       $v1, $v1, $a2
    /* AFDC 8006E33C 2C0062A4 */  sh         $v0, 0x2C($v1)
    /* AFE0 8006E340 0000A28C */  lw         $v0, 0x0($a1)
    /* AFE4 8006E344 00000000 */  nop
    /* AFE8 8006E348 40100200 */  sll        $v0, $v0, 1
    /* AFEC 8006E34C 21104600 */  addu       $v0, $v0, $a2
    /* AFF0 8006E350 2C004594 */  lhu        $a1, 0x2C($v0)
    /* AFF4 8006E354 93B90108 */  j          .L8006E64C
    /* AFF8 8006E358 21206002 */   addu      $a0, $s3, $zero
  jlabel .L8006E35C
    /* AFFC 8006E35C 1400628E */  lw         $v0, 0x14($s3)
    /* B000 8006E360 1800638E */  lw         $v1, 0x18($s3)
    /* B004 8006E364 F4FF5124 */  addiu      $s1, $v0, -0xC
    /* B008 8006E368 01000224 */  addiu      $v0, $zero, 0x1
    /* B00C 8006E36C 3A006210 */  beq        $v1, $v0, .L8006E458
    /* B010 8006E370 02006228 */   slti      $v0, $v1, 0x2
    /* B014 8006E374 03004014 */  bnez       $v0, .L8006E384
    /* B018 8006E378 02000224 */   addiu     $v0, $zero, 0x2
    /* B01C 8006E37C 44006210 */  beq        $v1, $v0, .L8006E490
    /* B020 8006E380 00000000 */   nop
  .L8006E384:
    /* B024 8006E384 4800428E */  lw         $v0, 0x48($s2)
    /* B028 8006E388 00000000 */  nop
    /* B02C 8006E38C 03004014 */  bnez       $v0, .L8006E39C
    /* B030 8006E390 0300222A */   slti      $v0, $s1, 0x3
    /* B034 8006E394 AF004010 */  beqz       $v0, .L8006E654
    /* B038 8006E398 00000000 */   nop
  .L8006E39C:
    /* B03C 8006E39C 4800438E */  lw         $v1, 0x48($s2)
    /* B040 8006E3A0 01000224 */  addiu      $v0, $zero, 0x1
    /* B044 8006E3A4 04006214 */  bne        $v1, $v0, .L8006E3B8
    /* B048 8006E3A8 21206002 */   addu      $a0, $s3, $zero
    /* B04C 8006E3AC 0400222A */  slti       $v0, $s1, 0x4
    /* B050 8006E3B0 A8004010 */  beqz       $v0, .L8006E654
    /* B054 8006E3B4 00000000 */   nop
  .L8006E3B8:
    /* B058 8006E3B8 4FB5010C */  jal        func_8006D53C
    /* B05C 8006E3BC 63000524 */   addiu     $a1, $zero, 0x63
    /* B060 8006E3C0 E800428E */  lw         $v0, 0xE8($s2)
    /* B064 8006E3C4 00000000 */  nop
    /* B068 8006E3C8 A2004010 */  beqz       $v0, .L8006E654
    /* B06C 8006E3CC 04004426 */   addiu     $a0, $s2, 0x4
    /* B070 8006E3D0 64012526 */  addiu      $a1, $s1, 0x164
    /* B074 8006E3D4 21300000 */  addu       $a2, $zero, $zero
    /* B078 8006E3D8 0780103C */  lui        $s0, %hi(D_800705DC)
    /* B07C 8006E3DC DC051026 */  addiu      $s0, $s0, %lo(D_800705DC)
    /* B080 8006E3E0 06000796 */  lhu        $a3, 0x6($s0)
    /* B084 8006E3E4 04000296 */  lhu        $v0, 0x4($s0)
    /* B088 8006E3E8 003C0700 */  sll        $a3, $a3, 16
    /* B08C 8006E3EC F26F000C */  jal        Text_OpenById
    /* B090 8006E3F0 25384700 */   or        $a3, $v0, $a3
    /* B094 8006E3F4 08004426 */  addiu      $a0, $s2, 0x8
    /* B098 8006E3F8 4F010524 */  addiu      $a1, $zero, 0x14F
    /* B09C 8006E3FC 21300000 */  addu       $a2, $zero, $zero
    /* B0A0 8006E400 0A000796 */  lhu        $a3, 0xA($s0)
    /* B0A4 8006E404 08000296 */  lhu        $v0, 0x8($s0)
    /* B0A8 8006E408 003C0700 */  sll        $a3, $a3, 16
    /* B0AC 8006E40C F26F000C */  jal        Text_OpenById
    /* B0B0 8006E410 25384700 */   or        $a3, $v0, $a3
    /* B0B4 8006E414 1C004426 */  addiu      $a0, $s2, 0x1C
    /* B0B8 8006E418 55012526 */  addiu      $a1, $s1, 0x155
    /* B0BC 8006E41C 21380000 */  addu       $a3, $zero, $zero
    /* B0C0 8006E420 1E000696 */  lhu        $a2, 0x1E($s0)
    /* B0C4 8006E424 1C000296 */  lhu        $v0, 0x1C($s0)
    /* B0C8 8006E428 00340600 */  sll        $a2, $a2, 16
    /* B0CC 8006E42C B0B4010C */  jal        func_8006D2C0
    /* B0D0 8006E430 25304600 */   or        $a2, $v0, $a2
    /* B0D4 8006E434 21206002 */  addu       $a0, $s3, $zero
    /* B0D8 8006E438 01000224 */  addiu      $v0, $zero, 0x1
    /* B0DC 8006E43C 500042AE */  sw         $v0, 0x50($s2)
    /* B0E0 8006E440 B80142AE */  sw         $v0, 0x1B8($s2)
    /* B0E4 8006E444 5C0042AE */  sw         $v0, 0x5C($s2)
  .L8006E448:
    /* B0E8 8006E448 C40140AE */  sw         $zero, 0x1C4($s2)
    /* B0EC 8006E44C C00140AE */  sw         $zero, 0x1C0($s2)
    /* B0F0 8006E450 6045000C */  jal        Task_NextState2
    /* B0F4 8006E454 BC0140AE */   sw        $zero, 0x1BC($s2)
  .L8006E458:
    /* B0F8 8006E458 0680023C */  lui        $v0, %hi(D_8005F704)
    /* B0FC 8006E45C 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* B100 8006E460 00000000 */  nop
    /* B104 8006E464 7D004018 */  blez       $v0, .L8006E65C
    /* B108 8006E468 13000424 */   addiu     $a0, $zero, 0x13
    /* B10C 8006E46C A369000C */  jal        Snd_PlayById
    /* B110 8006E470 21280000 */   addu      $a1, $zero, $zero
    /* B114 8006E474 21206002 */  addu       $a0, $s3, $zero
    /* B118 8006E478 01000224 */  addiu      $v0, $zero, 0x1
    /* B11C 8006E47C 5C0042AE */  sw         $v0, 0x5C($s2)
    /* B120 8006E480 6045000C */  jal        Task_NextState2
    /* B124 8006E484 BC0142AE */   sw        $v0, 0x1BC($s2)
    /* B128 8006E488 97B90108 */  j          .L8006E65C
    /* B12C 8006E48C 00000000 */   nop
  .L8006E490:
    /* B130 8006E490 C001428E */  lw         $v0, 0x1C0($s2)
    /* B134 8006E494 C401438E */  lw         $v1, 0x1C4($s2)
    /* B138 8006E498 00000000 */  nop
    /* B13C 8006E49C 21104300 */  addu       $v0, $v0, $v1
    /* B140 8006E4A0 40100200 */  sll        $v0, $v0, 1
    /* B144 8006E4A4 21104202 */  addu       $v0, $s2, $v0
    /* B148 8006E4A8 EC005184 */  lh         $s1, 0xEC($v0)
    /* B14C 8006E4AC 00000000 */  nop
    /* B150 8006E4B0 0A002012 */  beqz       $s1, .L8006E4DC
    /* B154 8006E4B4 FFFF1024 */   addiu     $s0, $zero, -0x1
    /* B158 8006E4B8 3078000C */  jal        Item_GetCategory
    /* B15C 8006E4BC 21202002 */   addu      $a0, $s1, $zero
    /* B160 8006E4C0 37B90108 */  j          .L8006E4DC
    /* B164 8006E4C4 F9FF5024 */   addiu     $s0, $v0, -0x7
  .L8006E4C8:
    /* B168 8006E4C8 10000424 */  addiu      $a0, $zero, 0x10
    /* B16C 8006E4CC A369000C */  jal        Snd_PlayById
    /* B170 8006E4D0 21280000 */   addu      $a1, $zero, $zero
    /* B174 8006E4D4 97B90108 */  j          .L8006E65C
    /* B178 8006E4D8 00000000 */   nop
  .L8006E4DC:
    /* B17C 8006E4DC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B180 8006E4E0 0C000212 */  beq        $s0, $v0, .L8006E514
    /* B184 8006E4E4 21280000 */   addu      $a1, $zero, $zero
    /* B188 8006E4E8 0680023C */  lui        $v0, %hi(Save_GameState)
    /* B18C 8006E4EC 20E64224 */  addiu      $v0, $v0, %lo(Save_GameState)
    /* B190 8006E4F0 08000326 */  addiu      $v1, $s0, 0x8
    /* B194 8006E4F4 40180300 */  sll        $v1, $v1, 1
    /* B198 8006E4F8 2800648E */  lw         $a0, 0x28($s3)
    /* B19C 8006E4FC 00000000 */  nop
    /* B1A0 8006E500 10008430 */  andi       $a0, $a0, 0x10
    /* B1A4 8006E504 02008010 */  beqz       $a0, .L8006E510
    /* B1A8 8006E508 21186200 */   addu      $v1, $v1, $v0
    /* B1AC 8006E50C 21282002 */  addu       $a1, $s1, $zero
  .L8006E510:
    /* B1B0 8006E510 2C0065A4 */  sh         $a1, 0x2C($v1)
  .L8006E514:
    /* B1B4 8006E514 0680023C */  lui        $v0, %hi(Pad_State)
    /* B1B8 8006E518 F0F64424 */  addiu      $a0, $v0, %lo(Pad_State)
    /* B1BC 8006E51C 3C008394 */  lhu        $v1, 0x3C($a0)
    /* B1C0 8006E520 00000000 */  nop
    /* B1C4 8006E524 00106230 */  andi       $v0, $v1, 0x1000
    /* B1C8 8006E528 1A004010 */  beqz       $v0, .L8006E594
    /* B1CC 8006E52C 00406230 */   andi      $v0, $v1, 0x4000
    /* B1D0 8006E530 C001428E */  lw         $v0, 0x1C0($s2)
    /* B1D4 8006E534 00000000 */  nop
    /* B1D8 8006E538 03004010 */  beqz       $v0, .L8006E548
    /* B1DC 8006E53C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* B1E0 8006E540 57B90108 */  j          .L8006E55C
    /* B1E4 8006E544 C00142AE */   sw        $v0, 0x1C0($s2)
  .L8006E548:
    /* B1E8 8006E548 C401428E */  lw         $v0, 0x1C4($s2)
    /* B1EC 8006E54C 00000000 */  nop
    /* B1F0 8006E550 05004010 */  beqz       $v0, .L8006E568
    /* B1F4 8006E554 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* B1F8 8006E558 C40142AE */  sw         $v0, 0x1C4($s2)
  .L8006E55C:
    /* B1FC 8006E55C 0D000424 */  addiu      $a0, $zero, 0xD
    /* B200 8006E560 A369000C */  jal        Snd_PlayById
    /* B204 8006E564 21280000 */   addu      $a1, $zero, $zero
  .L8006E568:
    /* B208 8006E568 01000224 */  addiu      $v0, $zero, 0x1
    /* B20C 8006E56C 5C0042AE */  sw         $v0, 0x5C($s2)
    /* B210 8006E570 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B214 8006E574 39000212 */  beq        $s0, $v0, .L8006E65C
    /* B218 8006E578 0680033C */   lui       $v1, %hi(Save_GameState)
    /* B21C 8006E57C 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* B220 8006E580 08000226 */  addiu      $v0, $s0, 0x8
    /* B224 8006E584 40100200 */  sll        $v0, $v0, 1
    /* B228 8006E588 21104300 */  addu       $v0, $v0, $v1
    /* B22C 8006E58C 97B90108 */  j          .L8006E65C
    /* B230 8006E590 2C0040A4 */   sh        $zero, 0x2C($v0)
  .L8006E594:
    /* B234 8006E594 1D004010 */  beqz       $v0, .L8006E60C
    /* B238 8006E598 09000224 */   addiu     $v0, $zero, 0x9
    /* B23C 8006E59C C001438E */  lw         $v1, 0x1C0($s2)
    /* B240 8006E5A0 00000000 */  nop
    /* B244 8006E5A4 03006210 */  beq        $v1, $v0, .L8006E5B4
    /* B248 8006E5A8 01006224 */   addiu     $v0, $v1, 0x1
    /* B24C 8006E5AC 75B90108 */  j          .L8006E5D4
    /* B250 8006E5B0 C00142AE */   sw        $v0, 0x1C0($s2)
  .L8006E5B4:
    /* B254 8006E5B4 C401448E */  lw         $a0, 0x1C4($s2)
    /* B258 8006E5B8 E800428E */  lw         $v0, 0xE8($s2)
    /* B25C 8006E5BC 09008324 */  addiu      $v1, $a0, 0x9
    /* B260 8006E5C0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* B264 8006E5C4 2A186200 */  slt        $v1, $v1, $v0
    /* B268 8006E5C8 05006010 */  beqz       $v1, .L8006E5E0
    /* B26C 8006E5CC 01008224 */   addiu     $v0, $a0, 0x1
    /* B270 8006E5D0 C40142AE */  sw         $v0, 0x1C4($s2)
  .L8006E5D4:
    /* B274 8006E5D4 0D000424 */  addiu      $a0, $zero, 0xD
    /* B278 8006E5D8 A369000C */  jal        Snd_PlayById
    /* B27C 8006E5DC 21280000 */   addu      $a1, $zero, $zero
  .L8006E5E0:
    /* B280 8006E5E0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B284 8006E5E4 06000212 */  beq        $s0, $v0, .L8006E600
    /* B288 8006E5E8 0680033C */   lui       $v1, %hi(Save_GameState)
    /* B28C 8006E5EC 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* B290 8006E5F0 08000226 */  addiu      $v0, $s0, 0x8
    /* B294 8006E5F4 40100200 */  sll        $v0, $v0, 1
    /* B298 8006E5F8 21104300 */  addu       $v0, $v0, $v1
    /* B29C 8006E5FC 2C0040A4 */  sh         $zero, 0x2C($v0)
  .L8006E600:
    /* B2A0 8006E600 01000224 */  addiu      $v0, $zero, 0x1
  .L8006E604:
    /* B2A4 8006E604 97B90108 */  j          .L8006E65C
    /* B2A8 8006E608 5C0042AE */   sw        $v0, 0x5C($s2)
  .L8006E60C:
    /* B2AC 8006E60C 1400828C */  lw         $v0, 0x14($a0)
    /* B2B0 8006E610 00000000 */  nop
    /* B2B4 8006E614 11004018 */  blez       $v0, .L8006E65C
    /* B2B8 8006E618 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* B2BC 8006E61C AAFF0212 */  beq        $s0, $v0, .L8006E4C8
    /* B2C0 8006E620 14000424 */   addiu     $a0, $zero, 0x14
    /* B2C4 8006E624 A369000C */  jal        Snd_PlayById
    /* B2C8 8006E628 21280000 */   addu      $a1, $zero, $zero
    /* B2CC 8006E62C 0680033C */  lui        $v1, %hi(Save_GameState)
    /* B2D0 8006E630 20E66324 */  addiu      $v1, $v1, %lo(Save_GameState)
    /* B2D4 8006E634 08000226 */  addiu      $v0, $s0, 0x8
    /* B2D8 8006E638 40100200 */  sll        $v0, $v0, 1
    /* B2DC 8006E63C 21104300 */  addu       $v0, $v0, $v1
    /* B2E0 8006E640 2C0051A4 */  sh         $s1, 0x2C($v0)
    /* B2E4 8006E644 21206002 */  addu       $a0, $s3, $zero
    /* B2E8 8006E648 21282002 */  addu       $a1, $s1, $zero
  .L8006E64C:
    /* B2EC 8006E64C 2FB5010C */  jal        func_8006D4BC
    /* B2F0 8006E650 00000000 */   nop
  .L8006E654:
    /* B2F4 8006E654 5945000C */  jal        Task_NextState1
    /* B2F8 8006E658 21206002 */   addu      $a0, $s3, $zero
  .L8006E65C:
    /* B2FC 8006E65C F7B5010C */  jal        func_8006D7DC
    /* B300 8006E660 21206002 */   addu      $a0, $s3, $zero
    /* B304 8006E664 C0B90108 */  j          .L8006E700
    /* B308 8006E668 00000000 */   nop
  jlabel .L8006E66C
    /* B30C 8006E66C 1800638E */  lw         $v1, 0x18($s3)
    /* B310 8006E670 00000000 */  nop
    /* B314 8006E674 03006010 */  beqz       $v1, .L8006E684
    /* B318 8006E678 01000224 */   addiu     $v0, $zero, 0x1
    /* B31C 8006E67C 17006210 */  beq        $v1, $v0, .L8006E6DC
    /* B320 8006E680 0680023C */   lui       $v0, %hi(D_8005F704)
  .L8006E684:
    /* B324 8006E684 21880000 */  addu       $s1, $zero, $zero
    /* B328 8006E688 20001024 */  addiu      $s0, $zero, 0x20
  .L8006E68C:
    /* B32C 8006E68C E26E000C */  jal        Text_Close
    /* B330 8006E690 21205002 */   addu      $a0, $s2, $s0
    /* B334 8006E694 01003126 */  addiu      $s1, $s1, 0x1
    /* B338 8006E698 0A00222A */  slti       $v0, $s1, 0xA
    /* B33C 8006E69C FBFF4014 */  bnez       $v0, .L8006E68C
    /* B340 8006E6A0 04001026 */   addiu     $s0, $s0, 0x4
    /* B344 8006E6A4 1C004426 */  addiu      $a0, $s2, 0x1C
    /* B348 8006E6A8 4E010524 */  addiu      $a1, $zero, 0x14E
    /* B34C 8006E6AC 21380000 */  addu       $a3, $zero, $zero
    /* B350 8006E6B0 0780023C */  lui        $v0, %hi(D_800705DC)
    /* B354 8006E6B4 DC054224 */  addiu      $v0, $v0, %lo(D_800705DC)
    /* B358 8006E6B8 B80140AE */  sw         $zero, 0x1B8($s2)
    /* B35C 8006E6BC 1E004694 */  lhu        $a2, 0x1E($v0)
    /* B360 8006E6C0 1C004294 */  lhu        $v0, 0x1C($v0)
    /* B364 8006E6C4 00340600 */  sll        $a2, $a2, 16
    /* B368 8006E6C8 B0B4010C */  jal        func_8006D2C0
    /* B36C 8006E6CC 25304600 */   or        $a2, $v0, $a2
    /* B370 8006E6D0 6045000C */  jal        Task_NextState2
    /* B374 8006E6D4 21206002 */   addu      $a0, $s3, $zero
    /* B378 8006E6D8 0680023C */  lui        $v0, %hi(D_8005F704)
  .L8006E6DC:
    /* B37C 8006E6DC 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* B380 8006E6E0 00000000 */  nop
    /* B384 8006E6E4 06004018 */  blez       $v0, .L8006E700
    /* B388 8006E6E8 00000000 */   nop
    /* B38C 8006E6EC D4B4010C */  jal        func_8006D350
    /* B390 8006E6F0 21206002 */   addu      $a0, $s3, $zero
    /* B394 8006E6F4 21206002 */  addu       $a0, $s3, $zero
    /* B398 8006E6F8 7045000C */  jal        Task_SetState0
    /* B39C 8006E6FC 03000524 */   addiu     $a1, $zero, 0x3
  .L8006E700:
    /* B3A0 8006E700 2400BF8F */  lw         $ra, 0x24($sp)
    /* B3A4 8006E704 2000B48F */  lw         $s4, 0x20($sp)
    /* B3A8 8006E708 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B3AC 8006E70C 1800B28F */  lw         $s2, 0x18($sp)
    /* B3B0 8006E710 1400B18F */  lw         $s1, 0x14($sp)
    /* B3B4 8006E714 1000B08F */  lw         $s0, 0x10($sp)
    /* B3B8 8006E718 0800E003 */  jr         $ra
    /* B3BC 8006E71C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006DCCC
