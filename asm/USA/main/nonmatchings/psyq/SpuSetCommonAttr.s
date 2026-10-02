nonmatching SpuSetCommonAttr, 0x37C

glabel SpuSetCommonAttr
    /* 2D924 8003D124 21300000 */  addu       $a2, $zero, $zero
    /* 2D928 8003D128 0000898C */  lw         $t1, 0x0($a0)
    /* 2D92C 8003D12C 00000000 */  nop
    /* 2D930 8003D130 01002A2D */  sltiu      $t2, $t1, 0x1
    /* 2D934 8003D134 06004015 */  bnez       $t2, .L8003D150
    /* 2D938 8003D138 21400000 */   addu      $t0, $zero, $zero
    /* 2D93C 8003D13C 01002231 */  andi       $v0, $t1, 0x1
    /* 2D940 8003D140 2D004010 */  beqz       $v0, .L8003D1F8
    /* 2D944 8003D144 04002231 */   andi      $v0, $t1, 0x4
    /* 2D948 8003D148 1A004010 */  beqz       $v0, .L8003D1B4
    /* 2D94C 8003D14C 00000000 */   nop
  .L8003D150:
    /* 2D950 8003D150 08008384 */  lh         $v1, 0x8($a0)
    /* 2D954 8003D154 00000000 */  nop
    /* 2D958 8003D158 0800622C */  sltiu      $v0, $v1, 0x8
    /* 2D95C 8003D15C 15004010 */  beqz       $v0, .L8003D1B4
    /* 2D960 8003D160 80100300 */   sll       $v0, $v1, 2
    /* 2D964 8003D164 0180013C */  lui        $at, %hi(jtbl_80010B34)
    /* 2D968 8003D168 21082200 */  addu       $at, $at, $v0
    /* 2D96C 8003D16C 340B228C */  lw         $v0, %lo(jtbl_80010B34)($at)
    /* 2D970 8003D170 00000000 */  nop
    /* 2D974 8003D174 08004000 */  jr         $v0
    /* 2D978 8003D178 00000000 */   nop
  jlabel .L8003D17C
    /* 2D97C 8003D17C 6FF40008 */  j          .L8003D1BC
    /* 2D980 8003D180 00800534 */   ori       $a1, $zero, 0x8000
  jlabel .L8003D184
    /* 2D984 8003D184 6FF40008 */  j          .L8003D1BC
    /* 2D988 8003D188 00900534 */   ori       $a1, $zero, 0x9000
  jlabel .L8003D18C
    /* 2D98C 8003D18C 6FF40008 */  j          .L8003D1BC
    /* 2D990 8003D190 00A00534 */   ori       $a1, $zero, 0xA000
  jlabel .L8003D194
    /* 2D994 8003D194 6FF40008 */  j          .L8003D1BC
    /* 2D998 8003D198 00B00534 */   ori       $a1, $zero, 0xB000
  jlabel .L8003D19C
    /* 2D99C 8003D19C 6FF40008 */  j          .L8003D1BC
    /* 2D9A0 8003D1A0 00C00534 */   ori       $a1, $zero, 0xC000
  jlabel .L8003D1A4
    /* 2D9A4 8003D1A4 6FF40008 */  j          .L8003D1BC
    /* 2D9A8 8003D1A8 00D00534 */   ori       $a1, $zero, 0xD000
  jlabel .L8003D1AC
    /* 2D9AC 8003D1AC 6FF40008 */  j          .L8003D1BC
    /* 2D9B0 8003D1B0 00E00534 */   ori       $a1, $zero, 0xE000
  jlabel .L8003D1B4
    /* 2D9B4 8003D1B4 04008694 */  lhu        $a2, 0x4($a0)
    /* 2D9B8 8003D1B8 21280000 */  addu       $a1, $zero, $zero
  .L8003D1BC:
    /* 2D9BC 8003D1BC 0A00A010 */  beqz       $a1, .L8003D1E8
    /* 2D9C0 8003D1C0 FF7FC230 */   andi      $v0, $a2, 0x7FFF
    /* 2D9C4 8003D1C4 04008784 */  lh         $a3, 0x4($a0)
    /* 2D9C8 8003D1C8 04008394 */  lhu        $v1, 0x4($a0)
    /* 2D9CC 8003D1CC 8000E228 */  slti       $v0, $a3, 0x80
    /* 2D9D0 8003D1D0 04004010 */  beqz       $v0, .L8003D1E4
    /* 2D9D4 8003D1D4 7F000624 */   addiu     $a2, $zero, 0x7F
    /* 2D9D8 8003D1D8 0200E004 */  bltz       $a3, .L8003D1E4
    /* 2D9DC 8003D1DC 21300000 */   addu      $a2, $zero, $zero
    /* 2D9E0 8003D1E0 21306000 */  addu       $a2, $v1, $zero
  .L8003D1E4:
    /* 2D9E4 8003D1E4 FF7FC230 */  andi       $v0, $a2, 0x7FFF
  .L8003D1E8:
    /* 2D9E8 8003D1E8 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2D9EC 8003D1EC 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2D9F0 8003D1F0 25104500 */  or         $v0, $v0, $a1
    /* 2D9F4 8003D1F4 800162A4 */  sh         $v0, 0x180($v1)
  .L8003D1F8:
    /* 2D9F8 8003D1F8 05004015 */  bnez       $t2, .L8003D210
    /* 2D9FC 8003D1FC 02002231 */   andi      $v0, $t1, 0x2
    /* 2DA00 8003D200 2D004010 */  beqz       $v0, .L8003D2B8
    /* 2DA04 8003D204 08002231 */   andi      $v0, $t1, 0x8
    /* 2DA08 8003D208 1A004010 */  beqz       $v0, .L8003D274
    /* 2DA0C 8003D20C 00000000 */   nop
  .L8003D210:
    /* 2DA10 8003D210 0A008384 */  lh         $v1, 0xA($a0)
    /* 2DA14 8003D214 00000000 */  nop
    /* 2DA18 8003D218 0800622C */  sltiu      $v0, $v1, 0x8
    /* 2DA1C 8003D21C 15004010 */  beqz       $v0, .L8003D274
    /* 2DA20 8003D220 80100300 */   sll       $v0, $v1, 2
    /* 2DA24 8003D224 0180013C */  lui        $at, %hi(jtbl_80010B54)
    /* 2DA28 8003D228 21082200 */  addu       $at, $at, $v0
    /* 2DA2C 8003D22C 540B228C */  lw         $v0, %lo(jtbl_80010B54)($at)
    /* 2DA30 8003D230 00000000 */  nop
    /* 2DA34 8003D234 08004000 */  jr         $v0
    /* 2DA38 8003D238 00000000 */   nop
  jlabel .L8003D23C
    /* 2DA3C 8003D23C 9FF40008 */  j          .L8003D27C
    /* 2DA40 8003D240 00800534 */   ori       $a1, $zero, 0x8000
  jlabel .L8003D244
    /* 2DA44 8003D244 9FF40008 */  j          .L8003D27C
    /* 2DA48 8003D248 00900534 */   ori       $a1, $zero, 0x9000
  jlabel .L8003D24C
    /* 2DA4C 8003D24C 9FF40008 */  j          .L8003D27C
    /* 2DA50 8003D250 00A00534 */   ori       $a1, $zero, 0xA000
  jlabel .L8003D254
    /* 2DA54 8003D254 9FF40008 */  j          .L8003D27C
    /* 2DA58 8003D258 00B00534 */   ori       $a1, $zero, 0xB000
  jlabel .L8003D25C
    /* 2DA5C 8003D25C 9FF40008 */  j          .L8003D27C
    /* 2DA60 8003D260 00C00534 */   ori       $a1, $zero, 0xC000
  jlabel .L8003D264
    /* 2DA64 8003D264 9FF40008 */  j          .L8003D27C
    /* 2DA68 8003D268 00D00534 */   ori       $a1, $zero, 0xD000
  jlabel .L8003D26C
    /* 2DA6C 8003D26C 9FF40008 */  j          .L8003D27C
    /* 2DA70 8003D270 00E00534 */   ori       $a1, $zero, 0xE000
  jlabel .L8003D274
    /* 2DA74 8003D274 06008894 */  lhu        $t0, 0x6($a0)
    /* 2DA78 8003D278 21280000 */  addu       $a1, $zero, $zero
  .L8003D27C:
    /* 2DA7C 8003D27C 0A00A010 */  beqz       $a1, .L8003D2A8
    /* 2DA80 8003D280 FF7F0231 */   andi      $v0, $t0, 0x7FFF
    /* 2DA84 8003D284 06008684 */  lh         $a2, 0x6($a0)
    /* 2DA88 8003D288 06008394 */  lhu        $v1, 0x6($a0)
    /* 2DA8C 8003D28C 8000C228 */  slti       $v0, $a2, 0x80
    /* 2DA90 8003D290 04004010 */  beqz       $v0, .L8003D2A4
    /* 2DA94 8003D294 7F000824 */   addiu     $t0, $zero, 0x7F
    /* 2DA98 8003D298 0200C004 */  bltz       $a2, .L8003D2A4
    /* 2DA9C 8003D29C 21400000 */   addu      $t0, $zero, $zero
    /* 2DAA0 8003D2A0 21406000 */  addu       $t0, $v1, $zero
  .L8003D2A4:
    /* 2DAA4 8003D2A4 FF7F0231 */  andi       $v0, $t0, 0x7FFF
  .L8003D2A8:
    /* 2DAA8 8003D2A8 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DAAC 8003D2AC 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DAB0 8003D2B0 25104500 */  or         $v0, $v0, $a1
    /* 2DAB4 8003D2B4 820162A4 */  sh         $v0, 0x182($v1)
  .L8003D2B8:
    /* 2DAB8 8003D2B8 03004015 */  bnez       $t2, .L8003D2C8
    /* 2DABC 8003D2BC 40002231 */   andi      $v0, $t1, 0x40
    /* 2DAC0 8003D2C0 06004010 */  beqz       $v0, .L8003D2DC
    /* 2DAC4 8003D2C4 00000000 */   nop
  .L8003D2C8:
    /* 2DAC8 8003D2C8 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DACC 8003D2CC 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DAD0 8003D2D0 10008294 */  lhu        $v0, 0x10($a0)
    /* 2DAD4 8003D2D4 00000000 */  nop
    /* 2DAD8 8003D2D8 B00162A4 */  sh         $v0, 0x1B0($v1)
  .L8003D2DC:
    /* 2DADC 8003D2DC 03004015 */  bnez       $t2, .L8003D2EC
    /* 2DAE0 8003D2E0 80002231 */   andi      $v0, $t1, 0x80
    /* 2DAE4 8003D2E4 06004010 */  beqz       $v0, .L8003D300
    /* 2DAE8 8003D2E8 00000000 */   nop
  .L8003D2EC:
    /* 2DAEC 8003D2EC 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DAF0 8003D2F0 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DAF4 8003D2F4 12008294 */  lhu        $v0, 0x12($a0)
    /* 2DAF8 8003D2F8 00000000 */  nop
    /* 2DAFC 8003D2FC B20162A4 */  sh         $v0, 0x1B2($v1)
  .L8003D300:
    /* 2DB00 8003D300 03004015 */  bnez       $t2, .L8003D310
    /* 2DB04 8003D304 00042231 */   andi      $v0, $t1, 0x400
    /* 2DB08 8003D308 06004010 */  beqz       $v0, .L8003D324
    /* 2DB0C 8003D30C 00000000 */   nop
  .L8003D310:
    /* 2DB10 8003D310 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DB14 8003D314 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DB18 8003D318 1C008294 */  lhu        $v0, 0x1C($a0)
    /* 2DB1C 8003D31C 00000000 */  nop
    /* 2DB20 8003D320 B40162A4 */  sh         $v0, 0x1B4($v1)
  .L8003D324:
    /* 2DB24 8003D324 03004015 */  bnez       $t2, .L8003D334
    /* 2DB28 8003D328 00082231 */   andi      $v0, $t1, 0x800
    /* 2DB2C 8003D32C 06004010 */  beqz       $v0, .L8003D348
    /* 2DB30 8003D330 00000000 */   nop
  .L8003D334:
    /* 2DB34 8003D334 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DB38 8003D338 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DB3C 8003D33C 1E008294 */  lhu        $v0, 0x1E($a0)
    /* 2DB40 8003D340 00000000 */  nop
    /* 2DB44 8003D344 B60162A4 */  sh         $v0, 0x1B6($v1)
  .L8003D348:
    /* 2DB48 8003D348 03004015 */  bnez       $t2, .L8003D358
    /* 2DB4C 8003D34C 00012231 */   andi      $v0, $t1, 0x100
    /* 2DB50 8003D350 12004010 */  beqz       $v0, .L8003D39C
    /* 2DB54 8003D354 00000000 */   nop
  .L8003D358:
    /* 2DB58 8003D358 1400828C */  lw         $v0, 0x14($a0)
    /* 2DB5C 8003D35C 00000000 */  nop
    /* 2DB60 8003D360 07004014 */  bnez       $v0, .L8003D380
    /* 2DB64 8003D364 00000000 */   nop
    /* 2DB68 8003D368 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DB6C 8003D36C 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DB70 8003D370 00000000 */  nop
    /* 2DB74 8003D374 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DB78 8003D378 E6F40008 */  j          .L8003D398
    /* 2DB7C 8003D37C FBFF4230 */   andi      $v0, $v0, 0xFFFB
  .L8003D380:
    /* 2DB80 8003D380 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DB84 8003D384 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DB88 8003D388 00000000 */  nop
    /* 2DB8C 8003D38C AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DB90 8003D390 00000000 */  nop
    /* 2DB94 8003D394 04004234 */  ori        $v0, $v0, 0x4
  .L8003D398:
    /* 2DB98 8003D398 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8003D39C:
    /* 2DB9C 8003D39C 03004015 */  bnez       $t2, .L8003D3AC
    /* 2DBA0 8003D3A0 00022231 */   andi      $v0, $t1, 0x200
    /* 2DBA4 8003D3A4 12004010 */  beqz       $v0, .L8003D3F0
    /* 2DBA8 8003D3A8 00000000 */   nop
  .L8003D3AC:
    /* 2DBAC 8003D3AC 1800828C */  lw         $v0, 0x18($a0)
    /* 2DBB0 8003D3B0 00000000 */  nop
    /* 2DBB4 8003D3B4 07004014 */  bnez       $v0, .L8003D3D4
    /* 2DBB8 8003D3B8 00000000 */   nop
    /* 2DBBC 8003D3BC 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DBC0 8003D3C0 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DBC4 8003D3C4 00000000 */  nop
    /* 2DBC8 8003D3C8 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DBCC 8003D3CC FBF40008 */  j          .L8003D3EC
    /* 2DBD0 8003D3D0 FEFF4230 */   andi      $v0, $v0, 0xFFFE
  .L8003D3D4:
    /* 2DBD4 8003D3D4 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DBD8 8003D3D8 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DBDC 8003D3DC 00000000 */  nop
    /* 2DBE0 8003D3E0 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DBE4 8003D3E4 00000000 */  nop
    /* 2DBE8 8003D3E8 01004234 */  ori        $v0, $v0, 0x1
  .L8003D3EC:
    /* 2DBEC 8003D3EC AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8003D3F0:
    /* 2DBF0 8003D3F0 03004015 */  bnez       $t2, .L8003D400
    /* 2DBF4 8003D3F4 00102231 */   andi      $v0, $t1, 0x1000
    /* 2DBF8 8003D3F8 12004010 */  beqz       $v0, .L8003D444
    /* 2DBFC 8003D3FC 00000000 */   nop
  .L8003D400:
    /* 2DC00 8003D400 2000828C */  lw         $v0, 0x20($a0)
    /* 2DC04 8003D404 00000000 */  nop
    /* 2DC08 8003D408 07004014 */  bnez       $v0, .L8003D428
    /* 2DC0C 8003D40C 00000000 */   nop
    /* 2DC10 8003D410 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DC14 8003D414 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DC18 8003D418 00000000 */  nop
    /* 2DC1C 8003D41C AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DC20 8003D420 10F50008 */  j          .L8003D440
    /* 2DC24 8003D424 F7FF4230 */   andi      $v0, $v0, 0xFFF7
  .L8003D428:
    /* 2DC28 8003D428 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DC2C 8003D42C 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DC30 8003D430 00000000 */  nop
    /* 2DC34 8003D434 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DC38 8003D438 00000000 */  nop
    /* 2DC3C 8003D43C 08004234 */  ori        $v0, $v0, 0x8
  .L8003D440:
    /* 2DC40 8003D440 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8003D444:
    /* 2DC44 8003D444 03004015 */  bnez       $t2, .L8003D454
    /* 2DC48 8003D448 00202231 */   andi      $v0, $t1, 0x2000
    /* 2DC4C 8003D44C 12004010 */  beqz       $v0, .L8003D498
    /* 2DC50 8003D450 00000000 */   nop
  .L8003D454:
    /* 2DC54 8003D454 2400828C */  lw         $v0, 0x24($a0)
    /* 2DC58 8003D458 00000000 */  nop
    /* 2DC5C 8003D45C 07004014 */  bnez       $v0, .L8003D47C
    /* 2DC60 8003D460 00000000 */   nop
    /* 2DC64 8003D464 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DC68 8003D468 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DC6C 8003D46C 00000000 */  nop
    /* 2DC70 8003D470 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DC74 8003D474 25F50008 */  j          .L8003D494
    /* 2DC78 8003D478 FDFF4230 */   andi      $v0, $v0, 0xFFFD
  .L8003D47C:
    /* 2DC7C 8003D47C 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2DC80 8003D480 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2DC84 8003D484 00000000 */  nop
    /* 2DC88 8003D488 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2DC8C 8003D48C 00000000 */  nop
    /* 2DC90 8003D490 02004234 */  ori        $v0, $v0, 0x2
  .L8003D494:
    /* 2DC94 8003D494 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8003D498:
    /* 2DC98 8003D498 0800E003 */  jr         $ra
    /* 2DC9C 8003D49C 00000000 */   nop
endlabel SpuSetCommonAttr
    /* 2DCA0 8003D4A0 00000000 */  nop
