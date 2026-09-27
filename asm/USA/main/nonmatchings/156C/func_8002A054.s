nonmatching func_8002A054, 0x694

glabel func_8002A054
    /* 1A854 8002A054 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 1A858 8002A058 5400B1AF */  sw         $s1, 0x54($sp)
    /* 1A85C 8002A05C 2188C000 */  addu       $s1, $a2, $zero
    /* 1A860 8002A060 7400BFAF */  sw         $ra, 0x74($sp)
    /* 1A864 8002A064 7000BEAF */  sw         $fp, 0x70($sp)
    /* 1A868 8002A068 6C00B7AF */  sw         $s7, 0x6C($sp)
    /* 1A86C 8002A06C 6800B6AF */  sw         $s6, 0x68($sp)
    /* 1A870 8002A070 6400B5AF */  sw         $s5, 0x64($sp)
    /* 1A874 8002A074 6000B4AF */  sw         $s4, 0x60($sp)
    /* 1A878 8002A078 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 1A87C 8002A07C 5800B2AF */  sw         $s2, 0x58($sp)
    /* 1A880 8002A080 0300A014 */  bnez       $a1, .L8002A090
    /* 1A884 8002A084 5000B0AF */   sw        $s0, 0x50($sp)
    /* 1A888 8002A088 AEA90008 */  j          .L8002A6B8
    /* 1A88C 8002A08C 21100000 */   addu      $v0, $zero, $zero
  .L8002A090:
    /* 1A890 8002A090 21B8A000 */  addu       $s7, $a1, $zero
    /* 1A894 8002A094 0180073C */  lui        $a3, %hi(D_80010404)
    /* 1A898 8002A098 0404E724 */  addiu      $a3, $a3, %lo(D_80010404)
    /* 1A89C 8002A09C 4800A7AF */  sw         $a3, 0x48($sp)
    /* 1A8A0 8002A0A0 3800A0AF */  sw         $zero, 0x38($sp)
  .L8002A0A4:
    /* 1A8A4 8002A0A4 0000E492 */  lbu        $a0, 0x0($s7)
    /* 1A8A8 8002A0A8 00000000 */  nop
    /* 1A8AC 8002A0AC 75018010 */  beqz       $a0, .L8002A684
    /* 1A8B0 8002A0B0 25000224 */   addiu     $v0, $zero, 0x25
    /* 1A8B4 8002A0B4 7C018214 */  bne        $a0, $v0, .L8002A6A8
    /* 1A8B8 8002A0B8 21980000 */   addu      $s3, $zero, $zero
    /* 1A8BC 8002A0BC FFFF1424 */  addiu      $s4, $zero, -0x1
    /* 1A8C0 8002A0C0 21F00000 */  addu       $fp, $zero, $zero
    /* 1A8C4 8002A0C4 3C00A0AF */  sw         $zero, 0x3C($sp)
    /* 1A8C8 8002A0C8 4000A0AF */  sw         $zero, 0x40($sp)
    /* 1A8CC 8002A0CC 4400A0AF */  sw         $zero, 0x44($sp)
  .L8002A0D0:
    /* 1A8D0 8002A0D0 0100F726 */  addiu      $s7, $s7, 0x1
    /* 1A8D4 8002A0D4 0000E392 */  lbu        $v1, 0x0($s7)
    /* 1A8D8 8002A0D8 00000000 */  nop
    /* 1A8DC 8002A0DC 7900622C */  sltiu      $v0, $v1, 0x79
    /* 1A8E0 8002A0E0 6D014010 */  beqz       $v0, .L8002A698
    /* 1A8E4 8002A0E4 80100300 */   sll       $v0, $v1, 2
    /* 1A8E8 8002A0E8 0180013C */  lui        $at, %hi(jtbl_80010434)
    /* 1A8EC 8002A0EC 21082200 */  addu       $at, $at, $v0
    /* 1A8F0 8002A0F0 3404228C */  lw         $v0, %lo(jtbl_80010434)($at)
    /* 1A8F4 8002A0F4 00000000 */  nop
    /* 1A8F8 8002A0F8 08004000 */  jr         $v0
    /* 1A8FC 8002A0FC 00000000 */   nop
  jlabel .L8002A100
    /* 1A900 8002A100 F3FFC017 */  bnez       $fp, .L8002A0D0
    /* 1A904 8002A104 00000000 */   nop
    /* 1A908 8002A108 34A80008 */  j          .L8002A0D0
    /* 1A90C 8002A10C 20001E24 */   addiu     $fp, $zero, 0x20
  jlabel .L8002A110
    /* 1A910 8002A110 34A80008 */  j          .L8002A0D0
    /* 1A914 8002A114 08007336 */   ori       $s3, $s3, 0x8
  jlabel .L8002A118
    /* 1A918 8002A118 04003126 */  addiu      $s1, $s1, 0x4
    /* 1A91C 8002A11C FCFF278E */  lw         $a3, -0x4($s1)
    /* 1A920 8002A120 00000000 */  nop
    /* 1A924 8002A124 EAFFE104 */  bgez       $a3, .L8002A0D0
    /* 1A928 8002A128 4400A7AF */   sw        $a3, 0x44($sp)
    /* 1A92C 8002A12C 23380700 */  negu       $a3, $a3
    /* 1A930 8002A130 4400A7AF */  sw         $a3, 0x44($sp)
  jlabel .L8002A134
    /* 1A934 8002A134 34A80008 */  j          .L8002A0D0
    /* 1A938 8002A138 10007336 */   ori       $s3, $s3, 0x10
  jlabel .L8002A13C
    /* 1A93C 8002A13C 34A80008 */  j          .L8002A0D0
    /* 1A940 8002A140 2B001E24 */   addiu     $fp, $zero, 0x2B
  jlabel .L8002A144
    /* 1A944 8002A144 0100F726 */  addiu      $s7, $s7, 0x1
    /* 1A948 8002A148 0000E392 */  lbu        $v1, 0x0($s7)
    /* 1A94C 8002A14C 2A000224 */  addiu      $v0, $zero, 0x2A
    /* 1A950 8002A150 05006214 */  bne        $v1, $v0, .L8002A168
    /* 1A954 8002A154 8000622C */   sltiu     $v0, $v1, 0x80
    /* 1A958 8002A158 04003126 */  addiu      $s1, $s1, 0x4
    /* 1A95C 8002A15C FCFF308E */  lw         $s0, -0x4($s1)
    /* 1A960 8002A160 6FA80008 */  j          .L8002A1BC
    /* 1A964 8002A164 21A00002 */   addu      $s4, $s0, $zero
  .L8002A168:
    /* 1A968 8002A168 12004010 */  beqz       $v0, .L8002A1B4
    /* 1A96C 8002A16C 21800000 */   addu      $s0, $zero, $zero
  .L8002A170:
    /* 1A970 8002A170 0000E492 */  lbu        $a0, 0x0($s7)
    /* 1A974 8002A174 0580023C */  lui        $v0, %hi(D_80049071)
    /* 1A978 8002A178 21104400 */  addu       $v0, $v0, $a0
    /* 1A97C 8002A17C 71904290 */  lbu        $v0, %lo(D_80049071)($v0)
    /* 1A980 8002A180 00000000 */  nop
    /* 1A984 8002A184 04004230 */  andi       $v0, $v0, 0x4
    /* 1A988 8002A188 0A004010 */  beqz       $v0, .L8002A1B4
    /* 1A98C 8002A18C 80101000 */   sll       $v0, $s0, 2
    /* 1A990 8002A190 0100F726 */  addiu      $s7, $s7, 0x1
    /* 1A994 8002A194 21105000 */  addu       $v0, $v0, $s0
    /* 1A998 8002A198 40100200 */  sll        $v0, $v0, 1
    /* 1A99C 8002A19C D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 1A9A0 8002A1A0 0000E392 */  lbu        $v1, 0x0($s7)
    /* 1A9A4 8002A1A4 00000000 */  nop
    /* 1A9A8 8002A1A8 8000632C */  sltiu      $v1, $v1, 0x80
    /* 1A9AC 8002A1AC F0FF6014 */  bnez       $v1, .L8002A170
    /* 1A9B0 8002A1B0 21804400 */   addu      $s0, $v0, $a0
  .L8002A1B4:
    /* 1A9B4 8002A1B4 FFFFF726 */  addiu      $s7, $s7, -0x1
    /* 1A9B8 8002A1B8 21A00002 */  addu       $s4, $s0, $zero
  .L8002A1BC:
    /* 1A9BC 8002A1BC C4FF0106 */  bgez       $s0, .L8002A0D0
    /* 1A9C0 8002A1C0 00000000 */   nop
    /* 1A9C4 8002A1C4 34A80008 */  j          .L8002A0D0
    /* 1A9C8 8002A1C8 FFFF1424 */   addiu     $s4, $zero, -0x1
  jlabel .L8002A1CC
    /* 1A9CC 8002A1CC 34A80008 */  j          .L8002A0D0
    /* 1A9D0 8002A1D0 20007336 */   ori       $s3, $s3, 0x20
  jlabel .L8002A1D4
    /* 1A9D4 8002A1D4 21800000 */  addu       $s0, $zero, $zero
  .L8002A1D8:
    /* 1A9D8 8002A1D8 0000E292 */  lbu        $v0, 0x0($s7)
    /* 1A9DC 8002A1DC 0100F726 */  addiu      $s7, $s7, 0x1
    /* 1A9E0 8002A1E0 80181000 */  sll        $v1, $s0, 2
    /* 1A9E4 8002A1E4 21187000 */  addu       $v1, $v1, $s0
    /* 1A9E8 8002A1E8 40180300 */  sll        $v1, $v1, 1
    /* 1A9EC 8002A1EC D0FF6324 */  addiu      $v1, $v1, -0x30
    /* 1A9F0 8002A1F0 0000E492 */  lbu        $a0, 0x0($s7)
    /* 1A9F4 8002A1F4 00000000 */  nop
    /* 1A9F8 8002A1F8 8000842C */  sltiu      $a0, $a0, 0x80
    /* 1A9FC 8002A1FC 09008010 */  beqz       $a0, .L8002A224
    /* 1AA00 8002A200 21806200 */   addu      $s0, $v1, $v0
    /* 1AA04 8002A204 0000E292 */  lbu        $v0, 0x0($s7)
    /* 1AA08 8002A208 0580013C */  lui        $at, %hi(D_80049071)
    /* 1AA0C 8002A20C 21082200 */  addu       $at, $at, $v0
    /* 1AA10 8002A210 71902290 */  lbu        $v0, %lo(D_80049071)($at)
    /* 1AA14 8002A214 00000000 */  nop
    /* 1AA18 8002A218 04004230 */  andi       $v0, $v0, 0x4
    /* 1AA1C 8002A21C EEFF4014 */  bnez       $v0, .L8002A1D8
    /* 1AA20 8002A220 00000000 */   nop
  .L8002A224:
    /* 1AA24 8002A224 4400B0AF */  sw         $s0, 0x44($sp)
    /* 1AA28 8002A228 34A80008 */  j          .L8002A0D0
    /* 1AA2C 8002A22C FFFFF726 */   addiu     $s7, $s7, -0x1
  jlabel .L8002A230
    /* 1AA30 8002A230 34A80008 */  j          .L8002A0D0
    /* 1AA34 8002A234 02007336 */   ori       $s3, $s3, 0x2
  jlabel .L8002A238
    /* 1AA38 8002A238 34A80008 */  j          .L8002A0D0
    /* 1AA3C 8002A23C 04007336 */   ori       $s3, $s3, 0x4
  jlabel .L8002A240
    /* 1AA40 8002A240 34A80008 */  j          .L8002A0D0
    /* 1AA44 8002A244 01007336 */   ori       $s3, $s3, 0x1
  jlabel .L8002A248
    /* 1AA48 8002A248 1000B227 */  addiu      $s2, $sp, 0x10
    /* 1AA4C 8002A24C 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AA50 8002A250 01001624 */  addiu      $s6, $zero, 0x1
    /* 1AA54 8002A254 FCFF2292 */  lbu        $v0, -0x4($s1)
    /* 1AA58 8002A258 21F00000 */  addu       $fp, $zero, $zero
    /* 1AA5C 8002A25C 30A90008 */  j          .L8002A4C0
    /* 1AA60 8002A260 1000A2A3 */   sb        $v0, 0x10($sp)
  jlabel .L8002A264
    /* 1AA64 8002A264 01007336 */  ori        $s3, $s3, 0x1
  jlabel .L8002A268
    /* 1AA68 8002A268 01006232 */  andi       $v0, $s3, 0x1
    /* 1AA6C 8002A26C 07004014 */  bnez       $v0, .L8002A28C
    /* 1AA70 8002A270 04006232 */   andi      $v0, $s3, 0x4
    /* 1AA74 8002A274 05004010 */  beqz       $v0, .L8002A28C
    /* 1AA78 8002A278 00000000 */   nop
    /* 1AA7C 8002A27C 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AA80 8002A280 FCFF2386 */  lh         $v1, -0x4($s1)
    /* 1AA84 8002A284 A6A80008 */  j          .L8002A298
    /* 1AA88 8002A288 00000000 */   nop
  .L8002A28C:
    /* 1AA8C 8002A28C 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AA90 8002A290 FCFF238E */  lw         $v1, -0x4($s1)
    /* 1AA94 8002A294 00000000 */  nop
  .L8002A298:
    /* 1AA98 8002A298 61006104 */  bgez       $v1, .L8002A420
    /* 1AA9C 8002A29C 0A000524 */   addiu     $a1, $zero, 0xA
    /* 1AAA0 8002A2A0 23180300 */  negu       $v1, $v1
    /* 1AAA4 8002A2A4 08A90008 */  j          .L8002A420
    /* 1AAA8 8002A2A8 2D001E24 */   addiu     $fp, $zero, 0x2D
  jlabel .L8002A2AC
    /* 1AAAC 8002A2AC 01006232 */  andi       $v0, $s3, 0x1
    /* 1AAB0 8002A2B0 08004014 */  bnez       $v0, .L8002A2D4
    /* 1AAB4 8002A2B4 04006232 */   andi      $v0, $s3, 0x4
    /* 1AAB8 8002A2B8 06004010 */  beqz       $v0, .L8002A2D4
    /* 1AABC 8002A2BC 00000000 */   nop
    /* 1AAC0 8002A2C0 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AAC4 8002A2C4 FCFF228E */  lw         $v0, -0x4($s1)
    /* 1AAC8 8002A2C8 3800A797 */  lhu        $a3, 0x38($sp)
    /* 1AACC 8002A2CC ACA90008 */  j          .L8002A6B0
    /* 1AAD0 8002A2D0 000047A4 */   sh        $a3, 0x0($v0)
  .L8002A2D4:
    /* 1AAD4 8002A2D4 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AAD8 8002A2D8 FCFF228E */  lw         $v0, -0x4($s1)
    /* 1AADC 8002A2DC 3800A78F */  lw         $a3, 0x38($sp)
    /* 1AAE0 8002A2E0 ACA90008 */  j          .L8002A6B0
    /* 1AAE4 8002A2E4 000047AC */   sw        $a3, 0x0($v0)
  jlabel .L8002A2E8
    /* 1AAE8 8002A2E8 01007336 */  ori        $s3, $s3, 0x1
  jlabel .L8002A2EC
    /* 1AAEC 8002A2EC 01006232 */  andi       $v0, $s3, 0x1
    /* 1AAF0 8002A2F0 07004014 */  bnez       $v0, .L8002A310
    /* 1AAF4 8002A2F4 04006232 */   andi      $v0, $s3, 0x4
    /* 1AAF8 8002A2F8 05004010 */  beqz       $v0, .L8002A310
    /* 1AAFC 8002A2FC 08000524 */   addiu     $a1, $zero, 0x8
    /* 1AB00 8002A300 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AB04 8002A304 FCFF2386 */  lh         $v1, -0x4($s1)
    /* 1AB08 8002A308 08A90008 */  j          .L8002A420
    /* 1AB0C 8002A30C 21F00000 */   addu      $fp, $zero, $zero
  .L8002A310:
    /* 1AB10 8002A310 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AB14 8002A314 FCFF238E */  lw         $v1, -0x4($s1)
    /* 1AB18 8002A318 07A90008 */  j          .L8002A41C
    /* 1AB1C 8002A31C 08000524 */   addiu     $a1, $zero, 0x8
  jlabel .L8002A320
    /* 1AB20 8002A320 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AB24 8002A324 FCFF238E */  lw         $v1, -0x4($s1)
    /* 1AB28 8002A328 07A90008 */  j          .L8002A41C
    /* 1AB2C 8002A32C 10000524 */   addiu     $a1, $zero, 0x10
  jlabel .L8002A330
    /* 1AB30 8002A330 04003126 */  addiu      $s1, $s1, 0x4
    /* 1AB34 8002A334 FCFF328E */  lw         $s2, -0x4($s1)
    /* 1AB38 8002A338 00000000 */  nop
    /* 1AB3C 8002A33C 03004016 */  bnez       $s2, .L8002A34C
    /* 1AB40 8002A340 00000000 */   nop
    /* 1AB44 8002A344 0180123C */  lui        $s2, %hi(D_80010418)
    /* 1AB48 8002A348 18045226 */  addiu      $s2, $s2, %lo(D_80010418)
  .L8002A34C:
    /* 1AB4C 8002A34C 0B008006 */  bltz       $s4, .L8002A37C
    /* 1AB50 8002A350 21204002 */   addu      $a0, $s2, $zero
    /* 1AB54 8002A354 21280000 */  addu       $a1, $zero, $zero
    /* 1AB58 8002A358 BDA9000C */  jal        memchr
    /* 1AB5C 8002A35C 21308002 */   addu      $a2, $s4, $zero
    /* 1AB60 8002A360 04004010 */  beqz       $v0, .L8002A374
    /* 1AB64 8002A364 23B05200 */   subu      $s6, $v0, $s2
    /* 1AB68 8002A368 2A109602 */  slt        $v0, $s4, $s6
    /* 1AB6C 8002A36C 54004010 */  beqz       $v0, .L8002A4C0
    /* 1AB70 8002A370 21F00000 */   addu      $fp, $zero, $zero
  .L8002A374:
    /* 1AB74 8002A374 E2A80008 */  j          .L8002A388
    /* 1AB78 8002A378 21B08002 */   addu      $s6, $s4, $zero
  .L8002A37C:
    /* 1AB7C 8002A37C 6DAA000C */  jal        func_8002A9B4
    /* 1AB80 8002A380 21204002 */   addu      $a0, $s2, $zero
    /* 1AB84 8002A384 21B04000 */  addu       $s6, $v0, $zero
  .L8002A388:
    /* 1AB88 8002A388 30A90008 */  j          .L8002A4C0
    /* 1AB8C 8002A38C 21F00000 */   addu      $fp, $zero, $zero
  jlabel .L8002A390
    /* 1AB90 8002A390 01007336 */  ori        $s3, $s3, 0x1
  jlabel .L8002A394
    /* 1AB94 8002A394 01006232 */  andi       $v0, $s3, 0x1
    /* 1AB98 8002A398 07004014 */  bnez       $v0, .L8002A3B8
    /* 1AB9C 8002A39C 04006232 */   andi      $v0, $s3, 0x4
    /* 1ABA0 8002A3A0 05004010 */  beqz       $v0, .L8002A3B8
    /* 1ABA4 8002A3A4 0A000524 */   addiu     $a1, $zero, 0xA
    /* 1ABA8 8002A3A8 04003126 */  addiu      $s1, $s1, 0x4
    /* 1ABAC 8002A3AC FCFF2386 */  lh         $v1, -0x4($s1)
    /* 1ABB0 8002A3B0 08A90008 */  j          .L8002A420
    /* 1ABB4 8002A3B4 21F00000 */   addu      $fp, $zero, $zero
  .L8002A3B8:
    /* 1ABB8 8002A3B8 04003126 */  addiu      $s1, $s1, 0x4
    /* 1ABBC 8002A3BC FCFF238E */  lw         $v1, -0x4($s1)
    /* 1ABC0 8002A3C0 07A90008 */  j          .L8002A41C
    /* 1ABC4 8002A3C4 0A000524 */   addiu     $a1, $zero, 0xA
  jlabel .L8002A3C8
    /* 1ABC8 8002A3C8 0180073C */  lui        $a3, %hi(D_80010420)
    /* 1ABCC 8002A3CC 2004E724 */  addiu      $a3, $a3, %lo(D_80010420)
    /* 1ABD0 8002A3D0 4800A7AF */  sw         $a3, 0x48($sp)
  jlabel .L8002A3D4
    /* 1ABD4 8002A3D4 01006232 */  andi       $v0, $s3, 0x1
    /* 1ABD8 8002A3D8 07004014 */  bnez       $v0, .L8002A3F8
    /* 1ABDC 8002A3DC 04006232 */   andi      $v0, $s3, 0x4
    /* 1ABE0 8002A3E0 05004010 */  beqz       $v0, .L8002A3F8
    /* 1ABE4 8002A3E4 10000524 */   addiu     $a1, $zero, 0x10
    /* 1ABE8 8002A3E8 04003126 */  addiu      $s1, $s1, 0x4
    /* 1ABEC 8002A3EC FCFF2386 */  lh         $v1, -0x4($s1)
    /* 1ABF0 8002A3F0 02A90008 */  j          .L8002A408
    /* 1ABF4 8002A3F4 08006232 */   andi      $v0, $s3, 0x8
  .L8002A3F8:
    /* 1ABF8 8002A3F8 04003126 */  addiu      $s1, $s1, 0x4
    /* 1ABFC 8002A3FC FCFF238E */  lw         $v1, -0x4($s1)
    /* 1AC00 8002A400 10000524 */  addiu      $a1, $zero, 0x10
    /* 1AC04 8002A404 08006232 */  andi       $v0, $s3, 0x8
  .L8002A408:
    /* 1AC08 8002A408 05004010 */  beqz       $v0, .L8002A420
    /* 1AC0C 8002A40C 21F00000 */   addu      $fp, $zero, $zero
    /* 1AC10 8002A410 03006010 */  beqz       $v1, .L8002A420
    /* 1AC14 8002A414 00000000 */   nop
    /* 1AC18 8002A418 40007336 */  ori        $s3, $s3, 0x40
  .L8002A41C:
    /* 1AC1C 8002A41C 21F00000 */  addu       $fp, $zero, $zero
  .L8002A420:
    /* 1AC20 8002A420 03008006 */  bltz       $s4, .L8002A430
    /* 1AC24 8002A424 3C00B4AF */   sw        $s4, 0x3C($sp)
    /* 1AC28 8002A428 DFFF0224 */  addiu      $v0, $zero, -0x21
    /* 1AC2C 8002A42C 24986202 */  and        $s3, $s3, $v0
  .L8002A430:
    /* 1AC30 8002A430 05006014 */  bnez       $v1, .L8002A448
    /* 1AC34 8002A434 3800B227 */   addiu     $s2, $sp, 0x38
    /* 1AC38 8002A438 3C00A78F */  lw         $a3, 0x3C($sp)
    /* 1AC3C 8002A43C 00000000 */  nop
    /* 1AC40 8002A440 1E00E010 */  beqz       $a3, .L8002A4BC
    /* 1AC44 8002A444 2310B203 */   subu      $v0, $sp, $s2
  .L8002A448:
    /* 1AC48 8002A448 1B006500 */  divu       $zero, $v1, $a1
    /* 1AC4C 8002A44C 0200A014 */  bnez       $a1, .L8002A458
    /* 1AC50 8002A450 00000000 */   nop
    /* 1AC54 8002A454 0D000700 */  break      7
  .L8002A458:
    /* 1AC58 8002A458 12180000 */  mflo       $v1
    /* 1AC5C 8002A45C 10100000 */  mfhi       $v0
    /* 1AC60 8002A460 4800A78F */  lw         $a3, 0x48($sp)
    /* 1AC64 8002A464 00000000 */  nop
    /* 1AC68 8002A468 2110E200 */  addu       $v0, $a3, $v0
    /* 1AC6C 8002A46C 00004490 */  lbu        $a0, 0x0($v0)
    /* 1AC70 8002A470 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 1AC74 8002A474 F4FF6014 */  bnez       $v1, .L8002A448
    /* 1AC78 8002A478 000044A2 */   sb        $a0, 0x0($s2)
    /* 1AC7C 8002A47C 0180073C */  lui        $a3, %hi(D_80010404)
    /* 1AC80 8002A480 0404E724 */  addiu      $a3, $a3, %lo(D_80010404)
    /* 1AC84 8002A484 08006232 */  andi       $v0, $s3, 0x8
    /* 1AC88 8002A488 0B004010 */  beqz       $v0, .L8002A4B8
    /* 1AC8C 8002A48C 4800A7AF */   sw        $a3, 0x48($sp)
    /* 1AC90 8002A490 08000224 */  addiu      $v0, $zero, 0x8
    /* 1AC94 8002A494 0900A214 */  bne        $a1, $v0, .L8002A4BC
    /* 1AC98 8002A498 2310B203 */   subu      $v0, $sp, $s2
    /* 1AC9C 8002A49C 00160400 */  sll        $v0, $a0, 24
    /* 1ACA0 8002A4A0 03160200 */  sra        $v0, $v0, 24
    /* 1ACA4 8002A4A4 30000324 */  addiu      $v1, $zero, 0x30
    /* 1ACA8 8002A4A8 04004310 */  beq        $v0, $v1, .L8002A4BC
    /* 1ACAC 8002A4AC 2310B203 */   subu      $v0, $sp, $s2
    /* 1ACB0 8002A4B0 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 1ACB4 8002A4B4 000043A2 */  sb         $v1, 0x0($s2)
  .L8002A4B8:
    /* 1ACB8 8002A4B8 2310B203 */  subu       $v0, $sp, $s2
  .L8002A4BC:
    /* 1ACBC 8002A4BC 38005624 */  addiu      $s6, $v0, 0x38
  .L8002A4C0:
    /* 1ACC0 8002A4C0 4000A78F */  lw         $a3, 0x40($sp)
    /* 1ACC4 8002A4C4 0200C013 */  beqz       $fp, .L8002A4D0
    /* 1ACC8 8002A4C8 21A0C702 */   addu      $s4, $s6, $a3
    /* 1ACCC 8002A4CC 01009426 */  addiu      $s4, $s4, 0x1
  .L8002A4D0:
    /* 1ACD0 8002A4D0 40006232 */  andi       $v0, $s3, 0x40
    /* 1ACD4 8002A4D4 02004010 */  beqz       $v0, .L8002A4E0
    /* 1ACD8 8002A4D8 00000000 */   nop
    /* 1ACDC 8002A4DC 02009426 */  addiu      $s4, $s4, 0x2
  .L8002A4E0:
    /* 1ACE0 8002A4E0 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 1ACE4 8002A4E4 00000000 */  nop
    /* 1ACE8 8002A4E8 2A10B402 */  slt        $v0, $s5, $s4
    /* 1ACEC 8002A4EC 02004010 */  beqz       $v0, .L8002A4F8
    /* 1ACF0 8002A4F0 30006232 */   andi      $v0, $s3, 0x30
    /* 1ACF4 8002A4F4 21A88002 */  addu       $s5, $s4, $zero
  .L8002A4F8:
    /* 1ACF8 8002A4F8 0E004014 */  bnez       $v0, .L8002A534
    /* 1ACFC 8002A4FC 2120C003 */   addu      $a0, $fp, $zero
    /* 1AD00 8002A500 4400A78F */  lw         $a3, 0x44($sp)
    /* 1AD04 8002A504 00000000 */  nop
    /* 1AD08 8002A508 0A00E010 */  beqz       $a3, .L8002A534
    /* 1AD0C 8002A50C 2A10A702 */   slt       $v0, $s5, $a3
    /* 1AD10 8002A510 08004010 */  beqz       $v0, .L8002A534
    /* 1AD14 8002A514 2180A002 */   addu      $s0, $s5, $zero
  .L8002A518:
    /* 1AD18 8002A518 D1A9000C */  jal        Debug_PutChar
    /* 1AD1C 8002A51C 20000424 */   addiu     $a0, $zero, 0x20
    /* 1AD20 8002A520 4400A78F */  lw         $a3, 0x44($sp)
    /* 1AD24 8002A524 01001026 */  addiu      $s0, $s0, 0x1
    /* 1AD28 8002A528 2A100702 */  slt        $v0, $s0, $a3
    /* 1AD2C 8002A52C FAFF4014 */  bnez       $v0, .L8002A518
    /* 1AD30 8002A530 2120C003 */   addu      $a0, $fp, $zero
  .L8002A534:
    /* 1AD34 8002A534 04008010 */  beqz       $a0, .L8002A548
    /* 1AD38 8002A538 40006232 */   andi      $v0, $s3, 0x40
    /* 1AD3C 8002A53C D1A9000C */  jal        Debug_PutChar
    /* 1AD40 8002A540 00000000 */   nop
    /* 1AD44 8002A544 40006232 */  andi       $v0, $s3, 0x40
  .L8002A548:
    /* 1AD48 8002A548 07004010 */  beqz       $v0, .L8002A568
    /* 1AD4C 8002A54C 30006332 */   andi      $v1, $s3, 0x30
    /* 1AD50 8002A550 D1A9000C */  jal        Debug_PutChar
    /* 1AD54 8002A554 30000424 */   addiu     $a0, $zero, 0x30
    /* 1AD58 8002A558 0000E482 */  lb         $a0, 0x0($s7)
    /* 1AD5C 8002A55C D1A9000C */  jal        Debug_PutChar
    /* 1AD60 8002A560 00000000 */   nop
    /* 1AD64 8002A564 30006332 */  andi       $v1, $s3, 0x30
  .L8002A568:
    /* 1AD68 8002A568 20000224 */  addiu      $v0, $zero, 0x20
    /* 1AD6C 8002A56C 0D006214 */  bne        $v1, $v0, .L8002A5A4
    /* 1AD70 8002A570 00000000 */   nop
    /* 1AD74 8002A574 4400A78F */  lw         $a3, 0x44($sp)
    /* 1AD78 8002A578 00000000 */  nop
    /* 1AD7C 8002A57C 2A10A702 */  slt        $v0, $s5, $a3
    /* 1AD80 8002A580 08004010 */  beqz       $v0, .L8002A5A4
    /* 1AD84 8002A584 2180A002 */   addu      $s0, $s5, $zero
  .L8002A588:
    /* 1AD88 8002A588 D1A9000C */  jal        Debug_PutChar
    /* 1AD8C 8002A58C 30000424 */   addiu     $a0, $zero, 0x30
    /* 1AD90 8002A590 4400A78F */  lw         $a3, 0x44($sp)
    /* 1AD94 8002A594 01001026 */  addiu      $s0, $s0, 0x1
    /* 1AD98 8002A598 2A100702 */  slt        $v0, $s0, $a3
    /* 1AD9C 8002A59C FAFF4014 */  bnez       $v0, .L8002A588
    /* 1ADA0 8002A5A0 00000000 */   nop
  .L8002A5A4:
    /* 1ADA4 8002A5A4 3C00A78F */  lw         $a3, 0x3C($sp)
    /* 1ADA8 8002A5A8 21808002 */  addu       $s0, $s4, $zero
    /* 1ADAC 8002A5AC 2A100702 */  slt        $v0, $s0, $a3
    /* 1ADB0 8002A5B0 08004010 */  beqz       $v0, .L8002A5D4
    /* 1ADB4 8002A5B4 00000000 */   nop
  .L8002A5B8:
    /* 1ADB8 8002A5B8 D1A9000C */  jal        Debug_PutChar
    /* 1ADBC 8002A5BC 30000424 */   addiu     $a0, $zero, 0x30
    /* 1ADC0 8002A5C0 3C00A78F */  lw         $a3, 0x3C($sp)
    /* 1ADC4 8002A5C4 01001026 */  addiu      $s0, $s0, 0x1
    /* 1ADC8 8002A5C8 2A100702 */  slt        $v0, $s0, $a3
    /* 1ADCC 8002A5CC FAFF4014 */  bnez       $v0, .L8002A5B8
    /* 1ADD0 8002A5D0 00000000 */   nop
  .L8002A5D4:
    /* 1ADD4 8002A5D4 FFFFD026 */  addiu      $s0, $s6, -0x1
    /* 1ADD8 8002A5D8 0B000006 */  bltz       $s0, .L8002A608
    /* 1ADDC 8002A5DC 00000000 */   nop
  .L8002A5E0:
    /* 1ADE0 8002A5E0 00004482 */  lb         $a0, 0x0($s2)
    /* 1ADE4 8002A5E4 01005226 */  addiu      $s2, $s2, 0x1
    /* 1ADE8 8002A5E8 D1A9000C */  jal        Debug_PutChar
    /* 1ADEC 8002A5EC FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 1ADF0 8002A5F0 05000006 */  bltz       $s0, .L8002A608
    /* 1ADF4 8002A5F4 00000000 */   nop
    /* 1ADF8 8002A5F8 78A90008 */  j          .L8002A5E0
    /* 1ADFC 8002A5FC 00000000 */   nop
  .L8002A600:
    /* 1AE00 8002A600 D1A9000C */  jal        Debug_PutChar
    /* 1AE04 8002A604 30000424 */   addiu     $a0, $zero, 0x30
  .L8002A608:
    /* 1AE08 8002A608 4000A78F */  lw         $a3, 0x40($sp)
    /* 1AE0C 8002A60C 00000000 */  nop
    /* 1AE10 8002A610 FFFFE724 */  addiu      $a3, $a3, -0x1
    /* 1AE14 8002A614 FAFFE104 */  bgez       $a3, .L8002A600
    /* 1AE18 8002A618 4000A7AF */   sw        $a3, 0x40($sp)
    /* 1AE1C 8002A61C 10006232 */  andi       $v0, $s3, 0x10
    /* 1AE20 8002A620 0D004010 */  beqz       $v0, .L8002A658
    /* 1AE24 8002A624 00000000 */   nop
    /* 1AE28 8002A628 4400A78F */  lw         $a3, 0x44($sp)
    /* 1AE2C 8002A62C 00000000 */  nop
    /* 1AE30 8002A630 2A10A702 */  slt        $v0, $s5, $a3
    /* 1AE34 8002A634 08004010 */  beqz       $v0, .L8002A658
    /* 1AE38 8002A638 2180A002 */   addu      $s0, $s5, $zero
  .L8002A63C:
    /* 1AE3C 8002A63C D1A9000C */  jal        Debug_PutChar
    /* 1AE40 8002A640 20000424 */   addiu     $a0, $zero, 0x20
    /* 1AE44 8002A644 4400A78F */  lw         $a3, 0x44($sp)
    /* 1AE48 8002A648 01001026 */  addiu      $s0, $s0, 0x1
    /* 1AE4C 8002A64C 2A100702 */  slt        $v0, $s0, $a3
    /* 1AE50 8002A650 FAFF4014 */  bnez       $v0, .L8002A63C
    /* 1AE54 8002A654 00000000 */   nop
  .L8002A658:
    /* 1AE58 8002A658 4400A38F */  lw         $v1, 0x44($sp)
    /* 1AE5C 8002A65C 00000000 */  nop
    /* 1AE60 8002A660 2A107500 */  slt        $v0, $v1, $s5
    /* 1AE64 8002A664 02004010 */  beqz       $v0, .L8002A670
    /* 1AE68 8002A668 00000000 */   nop
    /* 1AE6C 8002A66C 2118A002 */  addu       $v1, $s5, $zero
  .L8002A670:
    /* 1AE70 8002A670 3800A78F */  lw         $a3, 0x38($sp)
    /* 1AE74 8002A674 00000000 */  nop
    /* 1AE78 8002A678 2138E300 */  addu       $a3, $a3, $v1
    /* 1AE7C 8002A67C ACA90008 */  j          .L8002A6B0
    /* 1AE80 8002A680 3800A7AF */   sw        $a3, 0x38($sp)
  jlabel .L8002A684
    /* 1AE84 8002A684 10AA000C */  jal        Debug_FlushOut
    /* 1AE88 8002A688 00000000 */   nop
    /* 1AE8C 8002A68C 3800A28F */  lw         $v0, 0x38($sp)
    /* 1AE90 8002A690 AEA90008 */  j          .L8002A6B8
    /* 1AE94 8002A694 00000000 */   nop
  jlabel .L8002A698
    /* 1AE98 8002A698 3800A78F */  lw         $a3, 0x38($sp)
    /* 1AE9C 8002A69C 0000E482 */  lb         $a0, 0x0($s7)
    /* 1AEA0 8002A6A0 0100E724 */  addiu      $a3, $a3, 0x1
    /* 1AEA4 8002A6A4 3800A7AF */  sw         $a3, 0x38($sp)
  .L8002A6A8:
    /* 1AEA8 8002A6A8 D1A9000C */  jal        Debug_PutChar
    /* 1AEAC 8002A6AC 00000000 */   nop
  .L8002A6B0:
    /* 1AEB0 8002A6B0 29A80008 */  j          .L8002A0A4
    /* 1AEB4 8002A6B4 0100F726 */   addiu     $s7, $s7, 0x1
  .L8002A6B8:
    /* 1AEB8 8002A6B8 7400BF8F */  lw         $ra, 0x74($sp)
    /* 1AEBC 8002A6BC 7000BE8F */  lw         $fp, 0x70($sp)
    /* 1AEC0 8002A6C0 6C00B78F */  lw         $s7, 0x6C($sp)
    /* 1AEC4 8002A6C4 6800B68F */  lw         $s6, 0x68($sp)
    /* 1AEC8 8002A6C8 6400B58F */  lw         $s5, 0x64($sp)
    /* 1AECC 8002A6CC 6000B48F */  lw         $s4, 0x60($sp)
    /* 1AED0 8002A6D0 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 1AED4 8002A6D4 5800B28F */  lw         $s2, 0x58($sp)
    /* 1AED8 8002A6D8 5400B18F */  lw         $s1, 0x54($sp)
    /* 1AEDC 8002A6DC 5000B08F */  lw         $s0, 0x50($sp)
    /* 1AEE0 8002A6E0 0800E003 */  jr         $ra
    /* 1AEE4 8002A6E4 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8002A054
    /* 1AEE8 8002A6E8 00000000 */  nop
    /* 1AEEC 8002A6EC 00000000 */  nop
    /* 1AEF0 8002A6F0 00000000 */  nop
