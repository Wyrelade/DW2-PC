nonmatching func_8001D104, 0x400

glabel func_8001D104
    /* D904 8001D104 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* D908 8001D108 5C00B7AF */  sw         $s7, 0x5C($sp)
    /* D90C 8001D10C 21B88000 */  addu       $s7, $a0, $zero
    /* D910 8001D110 6400BFAF */  sw         $ra, 0x64($sp)
    /* D914 8001D114 6000BEAF */  sw         $fp, 0x60($sp)
    /* D918 8001D118 5800B6AF */  sw         $s6, 0x58($sp)
    /* D91C 8001D11C 5400B5AF */  sw         $s5, 0x54($sp)
    /* D920 8001D120 5000B4AF */  sw         $s4, 0x50($sp)
    /* D924 8001D124 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* D928 8001D128 4800B2AF */  sw         $s2, 0x48($sp)
    /* D92C 8001D12C 4400B1AF */  sw         $s1, 0x44($sp)
    /* D930 8001D130 4000B0AF */  sw         $s0, 0x40($sp)
    /* D934 8001D134 6C00A5AF */  sw         $a1, 0x6C($sp)
    /* D938 8001D138 7000A6AF */  sw         $a2, 0x70($sp)
    /* D93C 8001D13C 7400A7AF */  sw         $a3, 0x74($sp)
    /* D940 8001D140 0000E48E */  lw         $a0, 0x0($s7)
    /* D944 8001D144 688E000C */  jal        func_800239A0
    /* D948 8001D148 00000000 */   nop
    /* D94C 8001D14C 21F04000 */  addu       $fp, $v0, $zero
    /* D950 8001D150 0000E28E */  lw         $v0, 0x0($s7)
    /* D954 8001D154 FFFF043C */  lui        $a0, (0xFFFF0000 >> 16)
    /* D958 8001D158 E072000C */  jal        func_8001CB80
    /* D95C 8001D15C 24204400 */   and       $a0, $v0, $a0
    /* D960 8001D160 0680033C */  lui        $v1, %hi(D_8005F79C)
    /* D964 8001D164 21A84000 */  addu       $s5, $v0, $zero
    /* D968 8001D168 9CF7768C */  lw         $s6, %lo(D_8005F79C)($v1)
    /* D96C 8001D16C 0000C393 */  lbu        $v1, 0x0($fp)
    /* D970 8001D170 FF000224 */  addiu      $v0, $zero, 0xFF
    /* D974 8001D174 D5006210 */  beq        $v1, $v0, .L8001D4CC
    /* D978 8001D178 1800A827 */   addiu     $t0, $sp, 0x18
    /* D97C 8001D17C 3800A8AF */  sw         $t0, 0x38($sp)
    /* D980 8001D180 0600D427 */  addiu      $s4, $fp, 0x6
    /* D984 8001D184 2200D026 */  addiu      $s0, $s6, 0x22
  .L8001D188:
    /* D988 8001D188 06008392 */  lbu        $v1, 0x6($s4)
    /* D98C 8001D18C 0D00E292 */  lbu        $v0, 0xD($s7)
    /* D990 8001D190 00000000 */  nop
    /* D994 8001D194 C8006214 */  bne        $v1, $v0, .L8001D4B8
    /* D998 8001D198 09000224 */   addiu     $v0, $zero, 0x9
    /* D99C 8001D19C 0B00E98A */  lwl        $t1, 0xB($s7)
    /* D9A0 8001D1A0 0800E99A */  lwr        $t1, 0x8($s7)
    /* D9A4 8001D1A4 00000000 */  nop
    /* D9A8 8001D1A8 E5FF09AA */  swl        $t1, -0x1B($s0)
    /* D9AC 8001D1AC E2FF09BA */  swr        $t1, -0x1E($s0)
    /* D9B0 8001D1B0 E1FF02A2 */  sb         $v0, -0x1F($s0)
    /* D9B4 8001D1B4 2C000224 */  addiu      $v0, $zero, 0x2C
    /* D9B8 8001D1B8 E5FF02A2 */  sb         $v0, -0x1B($s0)
    /* D9BC 8001D1BC 05008292 */  lbu        $v0, 0x5($s4)
    /* D9C0 8001D1C0 00000000 */  nop
    /* D9C4 8001D1C4 80004230 */  andi       $v0, $v0, 0x80
    /* D9C8 8001D1C8 09004010 */  beqz       $v0, .L8001D1F0
    /* D9CC 8001D1CC 2E000224 */   addiu     $v0, $zero, 0x2E
    /* D9D0 8001D1D0 E5FF02A2 */  sb         $v0, -0x1B($s0)
    /* D9D4 8001D1D4 05008292 */  lbu        $v0, 0x5($s4)
    /* D9D8 8001D1D8 1000A396 */  lhu        $v1, 0x10($s5)
    /* D9DC 8001D1DC 03004230 */  andi       $v0, $v0, 0x3
    /* D9E0 8001D1E0 40110200 */  sll        $v0, $v0, 5
    /* D9E4 8001D1E4 25186200 */  or         $v1, $v1, $v0
    /* D9E8 8001D1E8 7F740008 */  j          .L8001D1FC
    /* D9EC 8001D1EC F4FF03A6 */   sh        $v1, -0xC($s0)
  .L8001D1F0:
    /* D9F0 8001D1F0 1000A296 */  lhu        $v0, 0x10($s5)
    /* D9F4 8001D1F4 00000000 */  nop
    /* D9F8 8001D1F8 F4FF02A6 */  sh         $v0, -0xC($s0)
  .L8001D1FC:
    /* D9FC 8001D1FC FCFF8296 */  lhu        $v0, -0x4($s4)
    /* DA00 8001D200 00000000 */  nop
    /* DA04 8001D204 2800A2A7 */  sh         $v0, 0x28($sp)
    /* DA08 8001D208 1800A2A7 */  sh         $v0, 0x18($sp)
    /* DA0C 8001D20C 02008392 */  lbu        $v1, 0x2($s4)
    /* DA10 8001D210 FCFF8296 */  lhu        $v0, -0x4($s4)
    /* DA14 8001D214 00000000 */  nop
    /* DA18 8001D218 21104300 */  addu       $v0, $v0, $v1
    /* DA1C 8001D21C 3000A2A7 */  sh         $v0, 0x30($sp)
    /* DA20 8001D220 2000A2A7 */  sh         $v0, 0x20($sp)
    /* DA24 8001D224 FEFF8296 */  lhu        $v0, -0x2($s4)
    /* DA28 8001D228 00000000 */  nop
    /* DA2C 8001D22C 2200A2A7 */  sh         $v0, 0x22($sp)
    /* DA30 8001D230 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* DA34 8001D234 03008292 */  lbu        $v0, 0x3($s4)
    /* DA38 8001D238 00000000 */  nop
    /* DA3C 8001D23C 05004010 */  beqz       $v0, .L8001D254
    /* DA40 8001D240 00000000 */   nop
    /* DA44 8001D244 03008392 */  lbu        $v1, 0x3($s4)
    /* DA48 8001D248 FEFF8296 */  lhu        $v0, -0x2($s4)
    /* DA4C 8001D24C 98740008 */  j          .L8001D260
    /* DA50 8001D250 21104300 */   addu      $v0, $v0, $v1
  .L8001D254:
    /* DA54 8001D254 FEFF8296 */  lhu        $v0, -0x2($s4)
    /* DA58 8001D258 00000000 */  nop
    /* DA5C 8001D25C FF004224 */  addiu      $v0, $v0, 0xFF
  .L8001D260:
    /* DA60 8001D260 3200A2A7 */  sh         $v0, 0x32($sp)
    /* DA64 8001D264 2A00A2A7 */  sh         $v0, 0x2A($sp)
    /* DA68 8001D268 21980000 */  addu       $s3, $zero, $zero
    /* DA6C 8001D26C 3800B28F */  lw         $s2, 0x38($sp)
    /* DA70 8001D270 2188C002 */  addu       $s1, $s6, $zero
    /* DA74 8001D274 3400A0A7 */  sh         $zero, 0x34($sp)
    /* DA78 8001D278 2C00A0A7 */  sh         $zero, 0x2C($sp)
    /* DA7C 8001D27C 2400A0A7 */  sh         $zero, 0x24($sp)
    /* DA80 8001D280 1C00A0A7 */  sh         $zero, 0x1C($sp)
  .L8001D284:
    /* DA84 8001D284 21284002 */  addu       $a1, $s2, $zero
    /* DA88 8001D288 6C00A48F */  lw         $a0, 0x6C($sp)
    /* DA8C 8001D28C 11B5000C */  jal        ApplyMatrixSV
    /* DA90 8001D290 1000A627 */   addiu     $a2, $sp, 0x10
    /* DA94 8001D294 1000A297 */  lhu        $v0, 0x10($sp)
    /* DA98 8001D298 0400E396 */  lhu        $v1, 0x4($s7)
    /* DA9C 8001D29C 08005226 */  addiu      $s2, $s2, 0x8
    /* DAA0 8001D2A0 21104300 */  addu       $v0, $v0, $v1
    /* DAA4 8001D2A4 080022A6 */  sh         $v0, 0x8($s1)
    /* DAA8 8001D2A8 1200A297 */  lhu        $v0, 0x12($sp)
    /* DAAC 8001D2AC 0600E396 */  lhu        $v1, 0x6($s7)
    /* DAB0 8001D2B0 01007326 */  addiu      $s3, $s3, 0x1
    /* DAB4 8001D2B4 21104300 */  addu       $v0, $v0, $v1
    /* DAB8 8001D2B8 0A0022A6 */  sh         $v0, 0xA($s1)
    /* DABC 8001D2BC 0400622A */  slti       $v0, $s3, 0x4
    /* DAC0 8001D2C0 F0FF4014 */  bnez       $v0, .L8001D284
    /* DAC4 8001D2C4 08003126 */   addiu     $s1, $s1, 0x8
    /* DAC8 8001D2C8 0000C393 */  lbu        $v1, 0x0($fp)
    /* DACC 8001D2CC 0C00A292 */  lbu        $v0, 0xC($s5)
    /* DAD0 8001D2D0 00000000 */  nop
    /* DAD4 8001D2D4 21186200 */  addu       $v1, $v1, $v0
    /* DAD8 8001D2D8 FAFF03A2 */  sb         $v1, -0x6($s0)
    /* DADC 8001D2DC EAFF03A2 */  sb         $v1, -0x16($s0)
    /* DAE0 8001D2E0 02008292 */  lbu        $v0, 0x2($s4)
    /* DAE4 8001D2E4 00000000 */  nop
    /* DAE8 8001D2E8 21186200 */  addu       $v1, $v1, $v0
    /* DAEC 8001D2EC 020003A2 */  sb         $v1, 0x2($s0)
    /* DAF0 8001D2F0 F2FF03A2 */  sb         $v1, -0xE($s0)
    /* DAF4 8001D2F4 1000E28E */  lw         $v0, 0x10($s7)
    /* DAF8 8001D2F8 00000000 */  nop
    /* DAFC 8001D2FC 03004104 */  bgez       $v0, .L8001D30C
    /* DB00 8001D300 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* DB04 8001D304 020002A2 */  sb         $v0, 0x2($s0)
    /* DB08 8001D308 F2FF02A2 */  sb         $v0, -0xE($s0)
  .L8001D30C:
    /* DB0C 8001D30C F2FF0292 */  lbu        $v0, -0xE($s0)
    /* DB10 8001D310 00000000 */  nop
    /* DB14 8001D314 03004014 */  bnez       $v0, .L8001D324
    /* DB18 8001D318 FF000224 */   addiu     $v0, $zero, 0xFF
    /* DB1C 8001D31C 020002A2 */  sb         $v0, 0x2($s0)
    /* DB20 8001D320 F2FF02A2 */  sb         $v0, -0xE($s0)
  .L8001D324:
    /* DB24 8001D324 FBFF8292 */  lbu        $v0, -0x5($s4)
    /* DB28 8001D328 00000000 */  nop
    /* DB2C 8001D32C F3FF02A2 */  sb         $v0, -0xD($s0)
    /* DB30 8001D330 EBFF02A2 */  sb         $v0, -0x15($s0)
    /* DB34 8001D334 FBFF8392 */  lbu        $v1, -0x5($s4)
    /* DB38 8001D338 03008292 */  lbu        $v0, 0x3($s4)
    /* DB3C 8001D33C 00000000 */  nop
    /* DB40 8001D340 21186200 */  addu       $v1, $v1, $v0
    /* DB44 8001D344 030003A2 */  sb         $v1, 0x3($s0)
    /* DB48 8001D348 FBFF03A2 */  sb         $v1, -0x5($s0)
    /* DB4C 8001D34C 1400E28E */  lw         $v0, 0x14($s7)
    /* DB50 8001D350 00000000 */  nop
    /* DB54 8001D354 03004104 */  bgez       $v0, .L8001D364
    /* DB58 8001D358 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* DB5C 8001D35C 030002A2 */  sb         $v0, 0x3($s0)
    /* DB60 8001D360 FBFF02A2 */  sb         $v0, -0x5($s0)
  .L8001D364:
    /* DB64 8001D364 FBFF0292 */  lbu        $v0, -0x5($s0)
    /* DB68 8001D368 00000000 */  nop
    /* DB6C 8001D36C 03004014 */  bnez       $v0, .L8001D37C
    /* DB70 8001D370 FF000224 */   addiu     $v0, $zero, 0xFF
    /* DB74 8001D374 030002A2 */  sb         $v0, 0x3($s0)
    /* DB78 8001D378 FBFF02A2 */  sb         $v0, -0x5($s0)
  .L8001D37C:
    /* DB7C 8001D37C 0800A28E */  lw         $v0, 0x8($s5)
    /* DB80 8001D380 00000000 */  nop
    /* DB84 8001D384 0A004010 */  beqz       $v0, .L8001D3B0
    /* DB88 8001D388 00000000 */   nop
    /* DB8C 8001D38C 1400A496 */  lhu        $a0, 0x14($s5)
    /* DB90 8001D390 04008392 */  lbu        $v1, 0x4($s4)
    /* DB94 8001D394 0C00E292 */  lbu        $v0, 0xC($s7)
    /* DB98 8001D398 E0018424 */  addiu      $a0, $a0, 0x1E0
    /* DB9C 8001D39C 21186400 */  addu       $v1, $v1, $a0
    /* DBA0 8001D3A0 21104300 */  addu       $v0, $v0, $v1
    /* DBA4 8001D3A4 80110200 */  sll        $v0, $v0, 6
    /* DBA8 8001D3A8 FC740008 */  j          .L8001D3F0
    /* DBAC 8001D3AC ECFF02A6 */   sh        $v0, -0x14($s0)
  .L8001D3B0:
    /* DBB0 8001D3B0 01008492 */  lbu        $a0, 0x1($s4)
    /* DBB4 8001D3B4 1C00A296 */  lhu        $v0, 0x1C($s5)
    /* DBB8 8001D3B8 00000000 */  nop
    /* DBBC 8001D3BC 21208200 */  addu       $a0, $a0, $v0
    /* DBC0 8001D3C0 04008292 */  lbu        $v0, 0x4($s4)
    /* DBC4 8001D3C4 0C00E392 */  lbu        $v1, 0xC($s7)
    /* DBC8 8001D3C8 21104400 */  addu       $v0, $v0, $a0
    /* DBCC 8001D3CC 21186200 */  addu       $v1, $v1, $v0
    /* DBD0 8001D3D0 00008292 */  lbu        $v0, 0x0($s4)
    /* DBD4 8001D3D4 1800A48E */  lw         $a0, 0x18($s5)
    /* DBD8 8001D3D8 80190300 */  sll        $v1, $v1, 6
    /* DBDC 8001D3DC 21104400 */  addu       $v0, $v0, $a0
    /* DBE0 8001D3E0 03110200 */  sra        $v0, $v0, 4
    /* DBE4 8001D3E4 3F004230 */  andi       $v0, $v0, 0x3F
    /* DBE8 8001D3E8 25186200 */  or         $v1, $v1, $v0
    /* DBEC 8001D3EC ECFF03A6 */  sh         $v1, -0x14($s0)
  .L8001D3F0:
    /* DBF0 8001D3F0 7400A98F */  lw         $t1, 0x74($sp)
    /* DBF4 8001D3F4 00000000 */  nop
    /* DBF8 8001D3F8 01002231 */  andi       $v0, $t1, 0x1
    /* DBFC 8001D3FC 0D004010 */  beqz       $v0, .L8001D434
    /* DC00 8001D400 00000000 */   nop
    /* DC04 8001D404 E6FF0296 */  lhu        $v0, -0x1A($s0)
    /* DC08 8001D408 EEFF0396 */  lhu        $v1, -0x12($s0)
    /* DC0C 8001D40C 40100200 */  sll        $v0, $v0, 1
    /* DC10 8001D410 E6FF02A6 */  sh         $v0, -0x1A($s0)
    /* DC14 8001D414 F6FF0296 */  lhu        $v0, -0xA($s0)
    /* DC18 8001D418 40180300 */  sll        $v1, $v1, 1
    /* DC1C 8001D41C EEFF03A6 */  sh         $v1, -0x12($s0)
    /* DC20 8001D420 FEFF0396 */  lhu        $v1, -0x2($s0)
    /* DC24 8001D424 40100200 */  sll        $v0, $v0, 1
    /* DC28 8001D428 40180300 */  sll        $v1, $v1, 1
    /* DC2C 8001D42C F6FF02A6 */  sh         $v0, -0xA($s0)
    /* DC30 8001D430 FEFF03A6 */  sh         $v1, -0x2($s0)
  .L8001D434:
    /* DC34 8001D434 7400AA8F */  lw         $t2, 0x74($sp)
    /* DC38 8001D438 00000000 */  nop
    /* DC3C 8001D43C 02004231 */  andi       $v0, $t2, 0x2
    /* DC40 8001D440 0D004010 */  beqz       $v0, .L8001D478
    /* DC44 8001D444 FF00043C */   lui       $a0, (0xFFFFFF >> 16)
    /* DC48 8001D448 E8FF0296 */  lhu        $v0, -0x18($s0)
    /* DC4C 8001D44C F0FF0396 */  lhu        $v1, -0x10($s0)
    /* DC50 8001D450 40100200 */  sll        $v0, $v0, 1
    /* DC54 8001D454 E8FF02A6 */  sh         $v0, -0x18($s0)
    /* DC58 8001D458 F8FF0296 */  lhu        $v0, -0x8($s0)
    /* DC5C 8001D45C 40180300 */  sll        $v1, $v1, 1
    /* DC60 8001D460 F0FF03A6 */  sh         $v1, -0x10($s0)
    /* DC64 8001D464 00000396 */  lhu        $v1, 0x0($s0)
    /* DC68 8001D468 40100200 */  sll        $v0, $v0, 1
    /* DC6C 8001D46C 40180300 */  sll        $v1, $v1, 1
    /* DC70 8001D470 F8FF02A6 */  sh         $v0, -0x8($s0)
    /* DC74 8001D474 000003A6 */  sh         $v1, 0x0($s0)
  .L8001D478:
    /* DC78 8001D478 FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* DC7C 8001D47C 28001026 */  addiu      $s0, $s0, 0x28
    /* DC80 8001D480 00FF053C */  lui        $a1, (0xFF000000 >> 16)
    /* DC84 8001D484 7000AB8F */  lw         $t3, 0x70($sp)
    /* DC88 8001D488 0000C38E */  lw         $v1, 0x0($s6)
    /* DC8C 8001D48C 0000628D */  lw         $v0, 0x0($t3)
    /* DC90 8001D490 24186500 */  and        $v1, $v1, $a1
    /* DC94 8001D494 24104400 */  and        $v0, $v0, $a0
    /* DC98 8001D498 25186200 */  or         $v1, $v1, $v0
    /* DC9C 8001D49C 2420C402 */  and        $a0, $s6, $a0
    /* DCA0 8001D4A0 0000C3AE */  sw         $v1, 0x0($s6)
    /* DCA4 8001D4A4 0000628D */  lw         $v0, 0x0($t3)
    /* DCA8 8001D4A8 2800D626 */  addiu      $s6, $s6, 0x28
    /* DCAC 8001D4AC 24104500 */  and        $v0, $v0, $a1
    /* DCB0 8001D4B0 25104400 */  or         $v0, $v0, $a0
    /* DCB4 8001D4B4 000062AD */  sw         $v0, 0x0($t3)
  .L8001D4B8:
    /* DCB8 8001D4B8 1000DE27 */  addiu      $fp, $fp, 0x10
    /* DCBC 8001D4BC 0000C393 */  lbu        $v1, 0x0($fp)
    /* DCC0 8001D4C0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* DCC4 8001D4C4 30FF6214 */  bne        $v1, $v0, .L8001D188
    /* DCC8 8001D4C8 10009426 */   addiu     $s4, $s4, 0x10
  .L8001D4CC:
    /* DCCC 8001D4CC 6400BF8F */  lw         $ra, 0x64($sp)
    /* DCD0 8001D4D0 6000BE8F */  lw         $fp, 0x60($sp)
    /* DCD4 8001D4D4 5C00B78F */  lw         $s7, 0x5C($sp)
    /* DCD8 8001D4D8 0680023C */  lui        $v0, %hi(D_8005F79C)
    /* DCDC 8001D4DC 9CF756AC */  sw         $s6, %lo(D_8005F79C)($v0)
    /* DCE0 8001D4E0 5800B68F */  lw         $s6, 0x58($sp)
    /* DCE4 8001D4E4 5400B58F */  lw         $s5, 0x54($sp)
    /* DCE8 8001D4E8 5000B48F */  lw         $s4, 0x50($sp)
    /* DCEC 8001D4EC 4C00B38F */  lw         $s3, 0x4C($sp)
    /* DCF0 8001D4F0 4800B28F */  lw         $s2, 0x48($sp)
    /* DCF4 8001D4F4 4400B18F */  lw         $s1, 0x44($sp)
    /* DCF8 8001D4F8 4000B08F */  lw         $s0, 0x40($sp)
    /* DCFC 8001D4FC 0800E003 */  jr         $ra
    /* DD00 8001D500 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_8001D104
