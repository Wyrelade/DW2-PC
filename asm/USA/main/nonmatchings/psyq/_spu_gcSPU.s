nonmatching _spu_gcSPU, 0x300

glabel _spu_gcSPU
    /* 2B874 8003B074 0580023C */  lui        $v0, %hi(D_8004FE8C)
    /* 2B878 8003B078 8CFE428C */  lw         $v0, %lo(D_8004FE8C)($v0)
    /* 2B87C 8003B07C 00000000 */  nop
    /* 2B880 8003B080 33004004 */  bltz       $v0, .L8003B150
    /* 2B884 8003B084 21480000 */   addu      $t1, $zero, $zero
    /* 2B888 8003B088 00800C3C */  lui        $t4, (0x80000000 >> 16)
    /* 2B88C 8003B08C FF2F0A3C */  lui        $t2, (0x2FFFFFFF >> 16)
    /* 2B890 8003B090 FFFF4A35 */  ori        $t2, $t2, (0x2FFFFFFF & 0xFFFF)
    /* 2B894 8003B094 FF0F0B3C */  lui        $t3, (0xFFFFFFF >> 16)
    /* 2B898 8003B098 FFFF6B35 */  ori        $t3, $t3, (0xFFFFFFF & 0xFFFF)
    /* 2B89C 8003B09C 0580083C */  lui        $t0, %hi(Spu_MemList)
    /* 2B8A0 8003B0A0 90FE088D */  lw         $t0, %lo(Spu_MemList)($t0)
    /* 2B8A4 8003B0A4 21684000 */  addu       $t5, $v0, $zero
    /* 2B8A8 8003B0A8 21380001 */  addu       $a3, $t0, $zero
  .L8003B0AC:
    /* 2B8AC 8003B0AC 0000E28C */  lw         $v0, 0x0($a3)
    /* 2B8B0 8003B0B0 00000000 */  nop
    /* 2B8B4 8003B0B4 24104C00 */  and        $v0, $v0, $t4
    /* 2B8B8 8003B0B8 1D004010 */  beqz       $v0, .L8003B130
    /* 2B8BC 8003B0BC 01002625 */   addiu     $a2, $t1, 0x1
    /* 2B8C0 8003B0C0 C0100600 */  sll        $v0, $a2, 3
    /* 2B8C4 8003B0C4 21184800 */  addu       $v1, $v0, $t0
  .L8003B0C8:
    /* 2B8C8 8003B0C8 0000628C */  lw         $v0, 0x0($v1)
    /* 2B8CC 8003B0CC 00000000 */  nop
    /* 2B8D0 8003B0D0 03004A14 */  bne        $v0, $t2, .L8003B0E0
    /* 2B8D4 8003B0D4 08006324 */   addiu     $v1, $v1, 0x8
    /* 2B8D8 8003B0D8 32EC0008 */  j          .L8003B0C8
    /* 2B8DC 8003B0DC 0100C624 */   addiu     $a2, $a2, 0x1
  .L8003B0E0:
    /* 2B8E0 8003B0E0 C0100600 */  sll        $v0, $a2, 3
    /* 2B8E4 8003B0E4 21284800 */  addu       $a1, $v0, $t0
    /* 2B8E8 8003B0E8 0000A38C */  lw         $v1, 0x0($a1)
    /* 2B8EC 8003B0EC 00000000 */  nop
    /* 2B8F0 8003B0F0 24106C00 */  and        $v0, $v1, $t4
    /* 2B8F4 8003B0F4 0E004010 */  beqz       $v0, .L8003B130
    /* 2B8F8 8003B0F8 24106B00 */   and       $v0, $v1, $t3
    /* 2B8FC 8003B0FC 0000E38C */  lw         $v1, 0x0($a3)
    /* 2B900 8003B100 0400E48C */  lw         $a0, 0x4($a3)
    /* 2B904 8003B104 24186B00 */  and        $v1, $v1, $t3
    /* 2B908 8003B108 21186400 */  addu       $v1, $v1, $a0
    /* 2B90C 8003B10C 08004314 */  bne        $v0, $v1, .L8003B130
    /* 2B910 8003B110 00000000 */   nop
    /* 2B914 8003B114 0000AAAC */  sw         $t2, 0x0($a1)
    /* 2B918 8003B118 0400E28C */  lw         $v0, 0x4($a3)
    /* 2B91C 8003B11C 0400A38C */  lw         $v1, 0x4($a1)
    /* 2B920 8003B120 00000000 */  nop
    /* 2B924 8003B124 21104300 */  addu       $v0, $v0, $v1
    /* 2B928 8003B128 4EEC0008 */  j          .L8003B138
    /* 2B92C 8003B12C 0400E2AC */   sw        $v0, 0x4($a3)
  .L8003B130:
    /* 2B930 8003B130 0800E724 */  addiu      $a3, $a3, 0x8
    /* 2B934 8003B134 01002925 */  addiu      $t1, $t1, 0x1
  .L8003B138:
    /* 2B938 8003B138 2A10A901 */  slt        $v0, $t5, $t1
    /* 2B93C 8003B13C DBFF4010 */  beqz       $v0, .L8003B0AC
    /* 2B940 8003B140 00000000 */   nop
    /* 2B944 8003B144 0580023C */  lui        $v0, %hi(D_8004FE8C)
    /* 2B948 8003B148 8CFE428C */  lw         $v0, %lo(D_8004FE8C)($v0)
    /* 2B94C 8003B14C 00000000 */  nop
  .L8003B150:
    /* 2B950 8003B150 10004004 */  bltz       $v0, .L8003B194
    /* 2B954 8003B154 21480000 */   addu      $t1, $zero, $zero
    /* 2B958 8003B158 FF2F053C */  lui        $a1, (0x2FFFFFFF >> 16)
    /* 2B95C 8003B15C FFFFA534 */  ori        $a1, $a1, (0x2FFFFFFF & 0xFFFF)
    /* 2B960 8003B160 21204000 */  addu       $a0, $v0, $zero
    /* 2B964 8003B164 0580033C */  lui        $v1, %hi(Spu_MemList)
    /* 2B968 8003B168 90FE638C */  lw         $v1, %lo(Spu_MemList)($v1)
    /* 2B96C 8003B16C 00000000 */  nop
  .L8003B170:
    /* 2B970 8003B170 0400628C */  lw         $v0, 0x4($v1)
    /* 2B974 8003B174 00000000 */  nop
    /* 2B978 8003B178 02004014 */  bnez       $v0, .L8003B184
    /* 2B97C 8003B17C 00000000 */   nop
    /* 2B980 8003B180 000065AC */  sw         $a1, 0x0($v1)
  .L8003B184:
    /* 2B984 8003B184 01002925 */  addiu      $t1, $t1, 0x1
    /* 2B988 8003B188 2A108900 */  slt        $v0, $a0, $t1
    /* 2B98C 8003B18C F8FF4010 */  beqz       $v0, .L8003B170
    /* 2B990 8003B190 08006324 */   addiu     $v1, $v1, 0x8
  .L8003B194:
    /* 2B994 8003B194 0580033C */  lui        $v1, %hi(D_8004FE8C)
    /* 2B998 8003B198 8CFE638C */  lw         $v1, %lo(D_8004FE8C)($v1)
    /* 2B99C 8003B19C 00000000 */  nop
    /* 2B9A0 8003B1A0 2F006004 */  bltz       $v1, .L8003B260
    /* 2B9A4 8003B1A4 21480000 */   addu      $t1, $zero, $zero
    /* 2B9A8 8003B1A8 00400E3C */  lui        $t6, (0x40000000 >> 16)
    /* 2B9AC 8003B1AC FF0F0C3C */  lui        $t4, (0xFFFFFFF >> 16)
    /* 2B9B0 8003B1B0 05800D3C */  lui        $t5, %hi(Spu_MemList)
    /* 2B9B4 8003B1B4 90FEAD8D */  lw         $t5, %lo(Spu_MemList)($t5)
    /* 2B9B8 8003B1B8 FFFF8C35 */  ori        $t4, $t4, (0xFFFFFFF & 0xFFFF)
    /* 2B9BC 8003B1BC 2150A001 */  addu       $t2, $t5, $zero
  .L8003B1C0:
    /* 2B9C0 8003B1C0 0000428D */  lw         $v0, 0x0($t2)
    /* 2B9C4 8003B1C4 00000000 */  nop
    /* 2B9C8 8003B1C8 24104E00 */  and        $v0, $v0, $t6
    /* 2B9CC 8003B1CC 24004014 */  bnez       $v0, .L8003B260
    /* 2B9D0 8003B1D0 00000000 */   nop
    /* 2B9D4 8003B1D4 01002625 */  addiu      $a2, $t1, 0x1
    /* 2B9D8 8003B1D8 2A106600 */  slt        $v0, $v1, $a2
    /* 2B9DC 8003B1DC 1A004014 */  bnez       $v0, .L8003B248
    /* 2B9E0 8003B1E0 C0100600 */   sll       $v0, $a2, 3
    /* 2B9E4 8003B1E4 21404001 */  addu       $t0, $t2, $zero
    /* 2B9E8 8003B1E8 05800B3C */  lui        $t3, %hi(D_8004FE8C)
    /* 2B9EC 8003B1EC 8CFE6B8D */  lw         $t3, %lo(D_8004FE8C)($t3)
    /* 2B9F0 8003B1F0 21204D00 */  addu       $a0, $v0, $t5
  .L8003B1F4:
    /* 2B9F4 8003B1F4 0000858C */  lw         $a1, 0x0($a0)
    /* 2B9F8 8003B1F8 00000000 */  nop
    /* 2B9FC 8003B1FC 2410AE00 */  and        $v0, $a1, $t6
    /* 2BA00 8003B200 11004014 */  bnez       $v0, .L8003B248
    /* 2BA04 8003B204 2410AC00 */   and       $v0, $a1, $t4
    /* 2BA08 8003B208 0000078D */  lw         $a3, 0x0($t0)
    /* 2BA0C 8003B20C 00000000 */  nop
    /* 2BA10 8003B210 2418EC00 */  and        $v1, $a3, $t4
    /* 2BA14 8003B214 2B104300 */  sltu       $v0, $v0, $v1
    /* 2BA18 8003B218 07004010 */  beqz       $v0, .L8003B238
    /* 2BA1C 8003B21C 00000000 */   nop
    /* 2BA20 8003B220 000005AD */  sw         $a1, 0x0($t0)
    /* 2BA24 8003B224 0400828C */  lw         $v0, 0x4($a0)
    /* 2BA28 8003B228 0400038D */  lw         $v1, 0x4($t0)
    /* 2BA2C 8003B22C 040002AD */  sw         $v0, 0x4($t0)
    /* 2BA30 8003B230 000087AC */  sw         $a3, 0x0($a0)
    /* 2BA34 8003B234 040083AC */  sw         $v1, 0x4($a0)
  .L8003B238:
    /* 2BA38 8003B238 0100C624 */  addiu      $a2, $a2, 0x1
    /* 2BA3C 8003B23C 2A106601 */  slt        $v0, $t3, $a2
    /* 2BA40 8003B240 ECFF4010 */  beqz       $v0, .L8003B1F4
    /* 2BA44 8003B244 08008424 */   addiu     $a0, $a0, 0x8
  .L8003B248:
    /* 2BA48 8003B248 0580033C */  lui        $v1, %hi(D_8004FE8C)
    /* 2BA4C 8003B24C 8CFE638C */  lw         $v1, %lo(D_8004FE8C)($v1)
    /* 2BA50 8003B250 01002925 */  addiu      $t1, $t1, 0x1
    /* 2BA54 8003B254 2A106900 */  slt        $v0, $v1, $t1
    /* 2BA58 8003B258 D9FF4010 */  beqz       $v0, .L8003B1C0
    /* 2BA5C 8003B25C 08004A25 */   addiu     $t2, $t2, 0x8
  .L8003B260:
    /* 2BA60 8003B260 0580053C */  lui        $a1, %hi(D_8004FE8C)
    /* 2BA64 8003B264 8CFEA58C */  lw         $a1, %lo(D_8004FE8C)($a1)
    /* 2BA68 8003B268 00000000 */  nop
    /* 2BA6C 8003B26C 1D00A004 */  bltz       $a1, .L8003B2E4
    /* 2BA70 8003B270 21480000 */   addu      $t1, $zero, $zero
    /* 2BA74 8003B274 0040083C */  lui        $t0, (0x40000000 >> 16)
    /* 2BA78 8003B278 FF2F073C */  lui        $a3, (0x2FFFFFFF >> 16)
    /* 2BA7C 8003B27C 0580063C */  lui        $a2, %hi(Spu_MemList)
    /* 2BA80 8003B280 90FEC68C */  lw         $a2, %lo(Spu_MemList)($a2)
    /* 2BA84 8003B284 FFFFE734 */  ori        $a3, $a3, (0x2FFFFFFF & 0xFFFF)
    /* 2BA88 8003B288 2120C000 */  addu       $a0, $a2, $zero
  .L8003B28C:
    /* 2BA8C 8003B28C 0000838C */  lw         $v1, 0x0($a0)
    /* 2BA90 8003B290 00000000 */  nop
    /* 2BA94 8003B294 24106800 */  and        $v0, $v1, $t0
    /* 2BA98 8003B298 12004014 */  bnez       $v0, .L8003B2E4
    /* 2BA9C 8003B29C 00000000 */   nop
    /* 2BAA0 8003B2A0 0A006714 */  bne        $v1, $a3, .L8003B2CC
    /* 2BAA4 8003B2A4 C0100500 */   sll       $v0, $a1, 3
    /* 2BAA8 8003B2A8 21104600 */  addu       $v0, $v0, $a2
    /* 2BAAC 8003B2AC 0000438C */  lw         $v1, 0x0($v0)
    /* 2BAB0 8003B2B0 00000000 */  nop
    /* 2BAB4 8003B2B4 000083AC */  sw         $v1, 0x0($a0)
    /* 2BAB8 8003B2B8 0400428C */  lw         $v0, 0x4($v0)
    /* 2BABC 8003B2BC 0580013C */  lui        $at, %hi(D_8004FE8C)
    /* 2BAC0 8003B2C0 8CFE29AC */  sw         $t1, %lo(D_8004FE8C)($at)
    /* 2BAC4 8003B2C4 B9EC0008 */  j          .L8003B2E4
    /* 2BAC8 8003B2C8 040082AC */   sw        $v0, 0x4($a0)
  .L8003B2CC:
    /* 2BACC 8003B2CC 0580053C */  lui        $a1, %hi(D_8004FE8C)
    /* 2BAD0 8003B2D0 8CFEA58C */  lw         $a1, %lo(D_8004FE8C)($a1)
    /* 2BAD4 8003B2D4 01002925 */  addiu      $t1, $t1, 0x1
    /* 2BAD8 8003B2D8 2A10A900 */  slt        $v0, $a1, $t1
    /* 2BADC 8003B2DC EBFF4010 */  beqz       $v0, .L8003B28C
    /* 2BAE0 8003B2E0 08008424 */   addiu     $a0, $a0, 0x8
  .L8003B2E4:
    /* 2BAE4 8003B2E4 0580023C */  lui        $v0, %hi(D_8004FE8C)
    /* 2BAE8 8003B2E8 8CFE428C */  lw         $v0, %lo(D_8004FE8C)($v0)
    /* 2BAEC 8003B2EC 00000000 */  nop
    /* 2BAF0 8003B2F0 FFFF4924 */  addiu      $t1, $v0, -0x1
    /* 2BAF4 8003B2F4 1D002005 */  bltz       $t1, .L8003B36C
    /* 2BAF8 8003B2F8 C0100900 */   sll       $v0, $t1, 3
    /* 2BAFC 8003B2FC 0080083C */  lui        $t0, (0x80000000 >> 16)
    /* 2BB00 8003B300 FF0F063C */  lui        $a2, (0xFFFFFFF >> 16)
    /* 2BB04 8003B304 FFFFC634 */  ori        $a2, $a2, (0xFFFFFFF & 0xFFFF)
    /* 2BB08 8003B308 0040073C */  lui        $a3, (0x40000000 >> 16)
    /* 2BB0C 8003B30C 0580053C */  lui        $a1, %hi(Spu_MemList)
    /* 2BB10 8003B310 90FEA58C */  lw         $a1, %lo(Spu_MemList)($a1)
    /* 2BB14 8003B314 00000000 */  nop
    /* 2BB18 8003B318 21204500 */  addu       $a0, $v0, $a1
  .L8003B31C:
    /* 2BB1C 8003B31C 0000838C */  lw         $v1, 0x0($a0)
    /* 2BB20 8003B320 00000000 */  nop
    /* 2BB24 8003B324 24106800 */  and        $v0, $v1, $t0
    /* 2BB28 8003B328 10004010 */  beqz       $v0, .L8003B36C
    /* 2BB2C 8003B32C 24106600 */   and       $v0, $v1, $a2
    /* 2BB30 8003B330 0580033C */  lui        $v1, %hi(D_8004FE8C)
    /* 2BB34 8003B334 8CFE638C */  lw         $v1, %lo(D_8004FE8C)($v1)
    /* 2BB38 8003B338 25104700 */  or         $v0, $v0, $a3
    /* 2BB3C 8003B33C 000082AC */  sw         $v0, 0x0($a0)
    /* 2BB40 8003B340 0400828C */  lw         $v0, 0x4($a0)
    /* 2BB44 8003B344 0580013C */  lui        $at, %hi(D_8004FE8C)
    /* 2BB48 8003B348 8CFE29AC */  sw         $t1, %lo(D_8004FE8C)($at)
    /* 2BB4C 8003B34C C0180300 */  sll        $v1, $v1, 3
    /* 2BB50 8003B350 21186500 */  addu       $v1, $v1, $a1
    /* 2BB54 8003B354 0400638C */  lw         $v1, 0x4($v1)
    /* 2BB58 8003B358 FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 2BB5C 8003B35C 21104300 */  addu       $v0, $v0, $v1
    /* 2BB60 8003B360 040082AC */  sw         $v0, 0x4($a0)
    /* 2BB64 8003B364 EDFF2105 */  bgez       $t1, .L8003B31C
    /* 2BB68 8003B368 F8FF8424 */   addiu     $a0, $a0, -0x8
  .L8003B36C:
    /* 2BB6C 8003B36C 0800E003 */  jr         $ra
    /* 2BB70 8003B370 00000000 */   nop
endlabel _spu_gcSPU
