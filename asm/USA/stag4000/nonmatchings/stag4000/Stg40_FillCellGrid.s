nonmatching Stg40_FillCellGrid, 0x414

glabel Stg40_FillCellGrid
    /* CC6C 8006FFCC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* CC70 8006FFD0 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* CC74 8006FFD4 1C07448C */  lw         $a0, %lo(Dung_StatePtr)($v0)
    /* CC78 8006FFD8 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* CC7C 8006FFDC 602B458C */  lw         $a1, %lo(Stg40_RootState)($v0)
    /* CC80 8006FFE0 0780023C */  lui        $v0, %hi(Stg40_SpecialFloorValues)
    /* CC84 8006FFE4 B4294224 */  addiu      $v0, $v0, %lo(Stg40_SpecialFloorValues)
    /* CC88 8006FFE8 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* CC8C 8006FFEC 3800BEAF */  sw         $fp, 0x38($sp)
    /* CC90 8006FFF0 3400B7AF */  sw         $s7, 0x34($sp)
    /* CC94 8006FFF4 3000B6AF */  sw         $s6, 0x30($sp)
    /* CC98 8006FFF8 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* CC9C 8006FFFC 2800B4AF */  sw         $s4, 0x28($sp)
    /* CCA0 80070000 2400B3AF */  sw         $s3, 0x24($sp)
    /* CCA4 80070004 2000B2AF */  sw         $s2, 0x20($sp)
    /* CCA8 80070008 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* CCAC 8007000C 1800B0AF */  sw         $s0, 0x18($sp)
    /* CCB0 80070010 580E918C */  lw         $s1, 0xE58($a0)
    /* CCB4 80070014 1000A38C */  lw         $v1, 0x10($a1)
    /* CCB8 80070018 540E848C */  lw         $a0, 0xE54($a0)
    /* CCBC 8007001C 2C006384 */  lh         $v1, 0x2C($v1)
    /* CCC0 80070020 00009E84 */  lh         $fp, 0x0($a0)
    /* CCC4 80070024 02008484 */  lh         $a0, 0x2($a0)
    /* CCC8 80070028 40180300 */  sll        $v1, $v1, 1
    /* CCCC 8007002C 21186200 */  addu       $v1, $v1, $v0
    /* CCD0 80070030 1400A28C */  lw         $v0, 0x14($a1)
    /* CCD4 80070034 0780063C */  lui        $a2, %hi(Stg40_FloorBitsPal)
    /* CCD8 80070038 1000A4AF */  sw         $a0, 0x10($sp)
    /* CCDC 8007003C 0000548C */  lw         $s4, 0x0($v0)
    /* CCE0 80070040 00006294 */  lhu        $v0, 0x0($v1)
    /* CCE4 80070044 A029C424 */  addiu      $a0, $a2, %lo(Stg40_FloorBitsPal)
    /* CCE8 80070048 0E0082A4 */  sh         $v0, 0xE($a0)
    /* CCEC 8007004C 1000A88F */  lw         $t0, 0x10($sp)
    /* CCF0 80070050 00000000 */  nop
    /* CCF4 80070054 66000019 */  blez       $t0, .L800701F0
    /* CCF8 80070058 21980000 */   addu      $s3, $zero, $zero
    /* CCFC 8007005C 21A8C000 */  addu       $s5, $a2, $zero
    /* CD00 80070060 FFFF1625 */  addiu      $s6, $t0, -0x1
  .L80070064:
    /* CD04 80070064 5D00C01B */  blez       $fp, .L800701DC
    /* CD08 80070068 21900000 */   addu      $s2, $zero, $zero
    /* CD0C 8007006C 2AB87602 */  slt        $s7, $s3, $s6
    /* CD10 80070070 03003026 */  addiu      $s0, $s1, 0x3
  .L80070074:
    /* CD14 80070074 0780043C */  lui        $a0, %hi(Stg40_FloorBitsPal)
    /* CD18 80070078 A0298424 */  addiu      $a0, $a0, %lo(Stg40_FloorBitsPal)
    /* CD1C 8007007C 21288002 */  addu       $a1, $s4, $zero
    /* CD20 80070080 21304002 */  addu       $a2, $s2, $zero
    /* CD24 80070084 D5BF010C */  jal        Stg40_ReadFloorBits
    /* CD28 80070088 21386002 */   addu      $a3, $s3, $zero
    /* CD2C 8007008C FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* CD30 80070090 06008014 */  bnez       $a0, .L800700AC
    /* CD34 80070094 00804234 */   ori       $v0, $v0, 0x8000
    /* CD38 80070098 FF000224 */  addiu      $v0, $zero, 0xFF
    /* CD3C 8007009C 000020A6 */  sh         $zero, 0x0($s1)
    /* CD40 800700A0 FFFF02A2 */  sb         $v0, -0x1($s0)
    /* CD44 800700A4 70C00108 */  j          .L800701C0
    /* CD48 800700A8 000000A2 */   sb        $zero, 0x0($s0)
  .L800700AC:
    /* CD4C 800700AC 000022A6 */  sh         $v0, 0x0($s1)
    /* CD50 800700B0 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* CD54 800700B4 01000224 */  addiu      $v0, $zero, 0x1
    /* CD58 800700B8 02008210 */  beq        $a0, $v0, .L800700C4
    /* CD5C 800700BC 00000000 */   nop
    /* CD60 800700C0 00406334 */  ori        $v1, $v1, 0x4000
  .L800700C4:
    /* CD64 800700C4 0B006012 */  beqz       $s3, .L800700F4
    /* CD68 800700C8 000023A6 */   sh        $v1, 0x0($s1)
    /* CD6C 800700CC 0D00601A */  blez       $s3, .L80070104
    /* CD70 800700D0 21288002 */   addu      $a1, $s4, $zero
    /* CD74 800700D4 0780043C */  lui        $a0, %hi(Stg40_FloorBitsPal)
    /* CD78 800700D8 A0298424 */  addiu      $a0, $a0, %lo(Stg40_FloorBitsPal)
    /* CD7C 800700DC 21304002 */  addu       $a2, $s2, $zero
    /* CD80 800700E0 D5BF010C */  jal        Stg40_ReadFloorBits
    /* CD84 800700E4 FFFF6726 */   addiu     $a3, $s3, -0x1
    /* CD88 800700E8 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* CD8C 800700EC 05004014 */  bnez       $v0, .L80070104
    /* CD90 800700F0 00000000 */   nop
  .L800700F4:
    /* CD94 800700F4 00002296 */  lhu        $v0, 0x0($s1)
    /* CD98 800700F8 00000000 */  nop
    /* CD9C 800700FC 00084234 */  ori        $v0, $v0, 0x800
    /* CDA0 80070100 000022A6 */  sh         $v0, 0x0($s1)
  .L80070104:
    /* CDA4 80070104 0A007612 */  beq        $s3, $s6, .L80070130
    /* CDA8 80070108 00000000 */   nop
    /* CDAC 8007010C 0C00E012 */  beqz       $s7, .L80070140
    /* CDB0 80070110 A029A426 */   addiu     $a0, $s5, %lo(Stg40_FloorBitsPal)
    /* CDB4 80070114 21288002 */  addu       $a1, $s4, $zero
    /* CDB8 80070118 21304002 */  addu       $a2, $s2, $zero
    /* CDBC 8007011C D5BF010C */  jal        Stg40_ReadFloorBits
    /* CDC0 80070120 01006726 */   addiu     $a3, $s3, 0x1
    /* CDC4 80070124 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* CDC8 80070128 05004014 */  bnez       $v0, .L80070140
    /* CDCC 8007012C 00000000 */   nop
  .L80070130:
    /* CDD0 80070130 00002296 */  lhu        $v0, 0x0($s1)
    /* CDD4 80070134 00000000 */  nop
    /* CDD8 80070138 00044234 */  ori        $v0, $v0, 0x400
    /* CDDC 8007013C 000022A6 */  sh         $v0, 0x0($s1)
  .L80070140:
    /* CDE0 80070140 0A004012 */  beqz       $s2, .L8007016C
    /* CDE4 80070144 00000000 */   nop
    /* CDE8 80070148 0C00401A */  blez       $s2, .L8007017C
    /* CDEC 8007014C A029A426 */   addiu     $a0, $s5, %lo(Stg40_FloorBitsPal)
    /* CDF0 80070150 21288002 */  addu       $a1, $s4, $zero
    /* CDF4 80070154 FFFF4626 */  addiu      $a2, $s2, -0x1
    /* CDF8 80070158 D5BF010C */  jal        Stg40_ReadFloorBits
    /* CDFC 8007015C 21386002 */   addu      $a3, $s3, $zero
    /* CE00 80070160 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* CE04 80070164 06004014 */  bnez       $v0, .L80070180
    /* CE08 80070168 FFFFC227 */   addiu     $v0, $fp, -0x1
  .L8007016C:
    /* CE0C 8007016C 00002296 */  lhu        $v0, 0x0($s1)
    /* CE10 80070170 00000000 */  nop
    /* CE14 80070174 00024234 */  ori        $v0, $v0, 0x200
    /* CE18 80070178 000022A6 */  sh         $v0, 0x0($s1)
  .L8007017C:
    /* CE1C 8007017C FFFFC227 */  addiu      $v0, $fp, -0x1
  .L80070180:
    /* CE20 80070180 0A004212 */  beq        $s2, $v0, .L800701AC
    /* CE24 80070184 2A104202 */   slt       $v0, $s2, $v0
    /* CE28 80070188 0C004010 */  beqz       $v0, .L800701BC
    /* CE2C 8007018C A029A426 */   addiu     $a0, $s5, %lo(Stg40_FloorBitsPal)
    /* CE30 80070190 21288002 */  addu       $a1, $s4, $zero
    /* CE34 80070194 01004626 */  addiu      $a2, $s2, 0x1
    /* CE38 80070198 D5BF010C */  jal        Stg40_ReadFloorBits
    /* CE3C 8007019C 21386002 */   addu      $a3, $s3, $zero
    /* CE40 800701A0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* CE44 800701A4 06004014 */  bnez       $v0, .L800701C0
    /* CE48 800701A8 FF000224 */   addiu     $v0, $zero, 0xFF
  .L800701AC:
    /* CE4C 800701AC 00002296 */  lhu        $v0, 0x0($s1)
    /* CE50 800701B0 00000000 */  nop
    /* CE54 800701B4 00014234 */  ori        $v0, $v0, 0x100
    /* CE58 800701B8 000022A6 */  sh         $v0, 0x0($s1)
  .L800701BC:
    /* CE5C 800701BC FF000224 */  addiu      $v0, $zero, 0xFF
  .L800701C0:
    /* CE60 800701C0 FFFF02A2 */  sb         $v0, -0x1($s0)
    /* CE64 800701C4 000000A2 */  sb         $zero, 0x0($s0)
    /* CE68 800701C8 04001026 */  addiu      $s0, $s0, 0x4
    /* CE6C 800701CC 01005226 */  addiu      $s2, $s2, 0x1
    /* CE70 800701D0 2A105E02 */  slt        $v0, $s2, $fp
    /* CE74 800701D4 A7FF4014 */  bnez       $v0, .L80070074
    /* CE78 800701D8 04003126 */   addiu     $s1, $s1, 0x4
  .L800701DC:
    /* CE7C 800701DC 1000A88F */  lw         $t0, 0x10($sp)
    /* CE80 800701E0 01007326 */  addiu      $s3, $s3, 0x1
    /* CE84 800701E4 2A106802 */  slt        $v0, $s3, $t0
    /* CE88 800701E8 9EFF4014 */  bnez       $v0, .L80070064
    /* CE8C 800701EC 00000000 */   nop
  .L800701F0:
    /* CE90 800701F0 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* CE94 800701F4 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* CE98 800701F8 1000A88F */  lw         $t0, 0x10($sp)
    /* CE9C 800701FC 580E518C */  lw         $s1, 0xE58($v0)
    /* CEA0 80070200 6B000019 */  blez       $t0, .L800703B0
    /* CEA4 80070204 21980000 */   addu      $s3, $zero, $zero
  .L80070208:
    /* CEA8 80070208 6400C01B */  blez       $fp, .L8007039C
    /* CEAC 8007020C 21900000 */   addu      $s2, $zero, $zero
    /* CEB0 80070210 FFFF1624 */  addiu      $s6, $zero, -0x1
    /* CEB4 80070214 03003026 */  addiu      $s0, $s1, 0x3
  .L80070218:
    /* CEB8 80070218 00002296 */  lhu        $v0, 0x0($s1)
    /* CEBC 8007021C 00000000 */  nop
    /* CEC0 80070220 0F004230 */  andi       $v0, $v0, 0xF
    /* CEC4 80070224 57004010 */  beqz       $v0, .L80070384
    /* CEC8 80070228 21204002 */   addu      $a0, $s2, $zero
    /* CECC 8007022C F8C0010C */  jal        Stg40_GetCellFlags
    /* CED0 80070230 FFFF6526 */   addiu     $a1, $s3, -0x1
    /* CED4 80070234 21204002 */  addu       $a0, $s2, $zero
    /* CED8 80070238 01006526 */  addiu      $a1, $s3, 0x1
    /* CEDC 8007023C F8C0010C */  jal        Stg40_GetCellFlags
    /* CEE0 80070240 21A84000 */   addu      $s5, $v0, $zero
    /* CEE4 80070244 2120C002 */  addu       $a0, $s6, $zero
    /* CEE8 80070248 21286002 */  addu       $a1, $s3, $zero
    /* CEEC 8007024C F8C0010C */  jal        Stg40_GetCellFlags
    /* CEF0 80070250 21B84000 */   addu      $s7, $v0, $zero
    /* CEF4 80070254 01004426 */  addiu      $a0, $s2, 0x1
    /* CEF8 80070258 21286002 */  addu       $a1, $s3, $zero
    /* CEFC 8007025C F8C0010C */  jal        Stg40_GetCellFlags
    /* CF00 80070260 21A04000 */   addu      $s4, $v0, $zero
    /* CF04 80070264 00002396 */  lhu        $v1, 0x0($s1)
    /* CF08 80070268 00000000 */  nop
    /* CF0C 8007026C 00086330 */  andi       $v1, $v1, 0x800
    /* CF10 80070270 0D006010 */  beqz       $v1, .L800702A8
    /* CF14 80070274 21204000 */   addu      $a0, $v0, $zero
    /* CF18 80070278 FFFF8232 */  andi       $v0, $s4, 0xFFFF
    /* CF1C 8007027C C2120200 */  srl        $v0, $v0, 11
    /* CF20 80070280 01004238 */  xori       $v0, $v0, 0x1
    /* CF24 80070284 00000392 */  lbu        $v1, 0x0($s0)
    /* CF28 80070288 01004230 */  andi       $v0, $v0, 0x1
    /* CF2C 8007028C 25186200 */  or         $v1, $v1, $v0
    /* CF30 80070290 000003A2 */  sb         $v1, 0x0($s0)
    /* CF34 80070294 00088230 */  andi       $v0, $a0, 0x800
    /* CF38 80070298 02004014 */  bnez       $v0, .L800702A4
    /* CF3C 8007029C FF006330 */   andi      $v1, $v1, 0xFF
    /* CF40 800702A0 02006334 */  ori        $v1, $v1, 0x2
  .L800702A4:
    /* CF44 800702A4 000003A2 */  sb         $v1, 0x0($s0)
  .L800702A8:
    /* CF48 800702A8 00002296 */  lhu        $v0, 0x0($s1)
    /* CF4C 800702AC 00000000 */  nop
    /* CF50 800702B0 00044230 */  andi       $v0, $v0, 0x400
    /* CF54 800702B4 0B004010 */  beqz       $v0, .L800702E4
    /* CF58 800702B8 00048230 */   andi      $v0, $a0, 0x400
    /* CF5C 800702BC 00000392 */  lbu        $v1, 0x0($s0)
    /* CF60 800702C0 02004014 */  bnez       $v0, .L800702CC
    /* CF64 800702C4 00000000 */   nop
    /* CF68 800702C8 04006334 */  ori        $v1, $v1, 0x4
  .L800702CC:
    /* CF6C 800702CC 000003A2 */  sb         $v1, 0x0($s0)
    /* CF70 800702D0 00048232 */  andi       $v0, $s4, 0x400
    /* CF74 800702D4 02004014 */  bnez       $v0, .L800702E0
    /* CF78 800702D8 FF006330 */   andi      $v1, $v1, 0xFF
    /* CF7C 800702DC 08006334 */  ori        $v1, $v1, 0x8
  .L800702E0:
    /* CF80 800702E0 000003A2 */  sb         $v1, 0x0($s0)
  .L800702E4:
    /* CF84 800702E4 00002296 */  lhu        $v0, 0x0($s1)
    /* CF88 800702E8 00000000 */  nop
    /* CF8C 800702EC 00024230 */  andi       $v0, $v0, 0x200
    /* CF90 800702F0 0B004010 */  beqz       $v0, .L80070320
    /* CF94 800702F4 0002E232 */   andi      $v0, $s7, 0x200
    /* CF98 800702F8 00000392 */  lbu        $v1, 0x0($s0)
    /* CF9C 800702FC 02004014 */  bnez       $v0, .L80070308
    /* CFA0 80070300 00000000 */   nop
    /* CFA4 80070304 10006334 */  ori        $v1, $v1, 0x10
  .L80070308:
    /* CFA8 80070308 000003A2 */  sb         $v1, 0x0($s0)
    /* CFAC 8007030C 0002A232 */  andi       $v0, $s5, 0x200
    /* CFB0 80070310 02004014 */  bnez       $v0, .L8007031C
    /* CFB4 80070314 FF006330 */   andi      $v1, $v1, 0xFF
    /* CFB8 80070318 20006334 */  ori        $v1, $v1, 0x20
  .L8007031C:
    /* CFBC 8007031C 000003A2 */  sb         $v1, 0x0($s0)
  .L80070320:
    /* CFC0 80070320 00002296 */  lhu        $v0, 0x0($s1)
    /* CFC4 80070324 00000000 */  nop
    /* CFC8 80070328 00014230 */  andi       $v0, $v0, 0x100
    /* CFCC 8007032C 0B004010 */  beqz       $v0, .L8007035C
    /* CFD0 80070330 0001A232 */   andi      $v0, $s5, 0x100
    /* CFD4 80070334 00000392 */  lbu        $v1, 0x0($s0)
    /* CFD8 80070338 02004014 */  bnez       $v0, .L80070344
    /* CFDC 8007033C 00000000 */   nop
    /* CFE0 80070340 40006334 */  ori        $v1, $v1, 0x40
  .L80070344:
    /* CFE4 80070344 000003A2 */  sb         $v1, 0x0($s0)
    /* CFE8 80070348 0001E232 */  andi       $v0, $s7, 0x100
    /* CFEC 8007034C 02004014 */  bnez       $v0, .L80070358
    /* CFF0 80070350 FF006330 */   andi      $v1, $v1, 0xFF
    /* CFF4 80070354 80006334 */  ori        $v1, $v1, 0x80
  .L80070358:
    /* CFF8 80070358 000003A2 */  sb         $v1, 0x0($s0)
  .L8007035C:
    /* CFFC 8007035C 2120C002 */  addu       $a0, $s6, $zero
    /* D000 80070360 F8C0010C */  jal        Stg40_GetCellFlags
    /* D004 80070364 FFFF6526 */   addiu     $a1, $s3, -0x1
    /* D008 80070368 0F004230 */  andi       $v0, $v0, 0xF
    /* D00C 8007036C 05004014 */  bnez       $v0, .L80070384
    /* D010 80070370 00000000 */   nop
    /* D014 80070374 00002296 */  lhu        $v0, 0x0($s1)
    /* D018 80070378 00000000 */  nop
    /* D01C 8007037C 80004234 */  ori        $v0, $v0, 0x80
    /* D020 80070380 000022A6 */  sh         $v0, 0x0($s1)
  .L80070384:
    /* D024 80070384 04001026 */  addiu      $s0, $s0, 0x4
    /* D028 80070388 04003126 */  addiu      $s1, $s1, 0x4
    /* D02C 8007038C 01005226 */  addiu      $s2, $s2, 0x1
    /* D030 80070390 2A105E02 */  slt        $v0, $s2, $fp
    /* D034 80070394 A0FF4014 */  bnez       $v0, .L80070218
    /* D038 80070398 0100D626 */   addiu     $s6, $s6, 0x1
  .L8007039C:
    /* D03C 8007039C 1000A88F */  lw         $t0, 0x10($sp)
    /* D040 800703A0 01007326 */  addiu      $s3, $s3, 0x1
    /* D044 800703A4 2A106802 */  slt        $v0, $s3, $t0
    /* D048 800703A8 97FF4014 */  bnez       $v0, .L80070208
    /* D04C 800703AC 00000000 */   nop
  .L800703B0:
    /* D050 800703B0 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* D054 800703B4 3800BE8F */  lw         $fp, 0x38($sp)
    /* D058 800703B8 3400B78F */  lw         $s7, 0x34($sp)
    /* D05C 800703BC 3000B68F */  lw         $s6, 0x30($sp)
    /* D060 800703C0 2C00B58F */  lw         $s5, 0x2C($sp)
    /* D064 800703C4 2800B48F */  lw         $s4, 0x28($sp)
    /* D068 800703C8 2400B38F */  lw         $s3, 0x24($sp)
    /* D06C 800703CC 2000B28F */  lw         $s2, 0x20($sp)
    /* D070 800703D0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* D074 800703D4 1800B08F */  lw         $s0, 0x18($sp)
    /* D078 800703D8 0800E003 */  jr         $ra
    /* D07C 800703DC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel Stg40_FillCellGrid
