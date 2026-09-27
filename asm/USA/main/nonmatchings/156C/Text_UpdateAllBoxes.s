nonmatching Text_UpdateAllBoxes, 0x11C0

glabel Text_UpdateAllBoxes
    /* B1C8 8001A9C8 30FFBD27 */  addiu      $sp, $sp, -0xD0
    /* B1CC 8001A9CC 04000724 */  addiu      $a3, $zero, 0x4
    /* B1D0 8001A9D0 0680083C */  lui        $t0, %hi(D_8005F770)
    /* B1D4 8001A9D4 70F70825 */  addiu      $t0, $t0, %lo(D_8005F770)
    /* B1D8 8001A9D8 CC00BFAF */  sw         $ra, 0xCC($sp)
    /* B1DC 8001A9DC C800BEAF */  sw         $fp, 0xC8($sp)
    /* B1E0 8001A9E0 C400B7AF */  sw         $s7, 0xC4($sp)
    /* B1E4 8001A9E4 C000B6AF */  sw         $s6, 0xC0($sp)
    /* B1E8 8001A9E8 BC00B5AF */  sw         $s5, 0xBC($sp)
    /* B1EC 8001A9EC B800B4AF */  sw         $s4, 0xB8($sp)
    /* B1F0 8001A9F0 B400B3AF */  sw         $s3, 0xB4($sp)
    /* B1F4 8001A9F4 B000B2AF */  sw         $s2, 0xB0($sp)
    /* B1F8 8001A9F8 AC00B1AF */  sw         $s1, 0xAC($sp)
    /* B1FC 8001A9FC A800B0AF */  sw         $s0, 0xA8($sp)
    /* B200 8001AA00 5000A0AF */  sw         $zero, 0x50($sp)
    /* B204 8001AA04 A000A7AF */  sw         $a3, 0xA0($sp)
    /* B208 8001AA08 2C00088D */  lw         $t0, 0x2C($t0)
    /* B20C 8001AA0C 21F08000 */  addu       $fp, $a0, $zero
    /* B210 8001AA10 5400A8AF */  sw         $t0, 0x54($sp)
    /* B214 8001AA14 3400C98F */  lw         $t1, 0x34($fp)
    /* B218 8001AA18 00000000 */  nop
    /* B21C 8001AA1C 4C00A9AF */  sw         $t1, 0x4C($sp)
    /* B220 8001AA20 2C00CA8F */  lw         $t2, 0x2C($fp)
    /* B224 8001AA24 21382001 */  addu       $a3, $t1, $zero
    /* B228 8001AA28 9C00A7AF */  sw         $a3, 0x9C($sp)
    /* B22C 8001AA2C 21B04001 */  addu       $s6, $t2, $zero
    /* B230 8001AA30 4800AAAF */  sw         $t2, 0x48($sp)
  .L8001AA34:
    /* B234 8001AA34 0000C292 */  lbu        $v0, 0x0($s6)
    /* B238 8001AA38 00000000 */  nop
    /* B23C 8001AA3C 37044010 */  beqz       $v0, .L8001BB1C
    /* B240 8001AA40 00000000 */   nop
    /* B244 8001AA44 6400A0AF */  sw         $zero, 0x64($sp)
    /* B248 8001AA48 6800A0AF */  sw         $zero, 0x68($sp)
    /* B24C 8001AA4C 6C00A0AF */  sw         $zero, 0x6C($sp)
    /* B250 8001AA50 7000A0AF */  sw         $zero, 0x70($sp)
    /* B254 8001AA54 7400A0AF */  sw         $zero, 0x74($sp)
    /* B258 8001AA58 7800A0AF */  sw         $zero, 0x78($sp)
    /* B25C 8001AA5C 7C00A0AF */  sw         $zero, 0x7C($sp)
    /* B260 8001AA60 8000A0AF */  sw         $zero, 0x80($sp)
    /* B264 8001AA64 0800D18E */  lw         $s1, 0x8($s6)
    /* B268 8001AA68 8400A0AF */  sw         $zero, 0x84($sp)
    /* B26C 8001AA6C 1F00C88A */  lwl        $t0, 0x1F($s6)
    /* B270 8001AA70 1C00C89A */  lwr        $t0, 0x1C($s6)
    /* B274 8001AA74 00000000 */  nop
    /* B278 8001AA78 2B00A8AB */  swl        $t0, 0x2B($sp)
    /* B27C 8001AA7C 2800A8BB */  swr        $t0, 0x28($sp)
    /* B280 8001AA80 0680083C */  lui        $t0, %hi(D_8005F770)
    /* B284 8001AA84 3100C292 */  lbu        $v0, 0x31($s6)
    /* B288 8001AA88 70F70825 */  addiu      $t0, $t0, %lo(D_8005F770)
    /* B28C 8001AA8C 8800A0A3 */  sb         $zero, 0x88($sp)
    /* B290 8001AA90 80100200 */  sll        $v0, $v0, 2
    /* B294 8001AA94 21104800 */  addu       $v0, $v0, $t0
    /* B298 8001AA98 3801428C */  lw         $v0, 0x138($v0)
    /* B29C 8001AA9C 00000000 */  nop
    /* B2A0 8001AAA0 5800A2AF */  sw         $v0, 0x58($sp)
    /* B2A4 8001AAA4 2000C292 */  lbu        $v0, 0x20($s6)
    /* B2A8 8001AAA8 21A80000 */  addu       $s5, $zero, $zero
    /* B2AC 8001AAAC 6000A0AF */  sw         $zero, 0x60($sp)
    /* B2B0 8001AAB0 0200C2A2 */  sb         $v0, 0x2($s6)
    /* B2B4 8001AAB4 2700C292 */  lbu        $v0, 0x27($s6)
    /* B2B8 8001AAB8 00000000 */  nop
    /* B2BC 8001AABC 17004014 */  bnez       $v0, .L8001AB1C
    /* B2C0 8001AAC0 2190C002 */   addu      $s2, $s6, $zero
    /* B2C4 8001AAC4 0600C286 */  lh         $v0, 0x6($s6)
    /* B2C8 8001AAC8 00000000 */  nop
    /* B2CC 8001AACC 13004010 */  beqz       $v0, .L8001AB1C
    /* B2D0 8001AAD0 0680093C */   lui       $t1, %hi(D_8005F770)
    /* B2D4 8001AAD4 70F72925 */  addiu      $t1, $t1, %lo(D_8005F770)
    /* B2D8 8001AAD8 2100C292 */  lbu        $v0, 0x21($s6)
    /* B2DC 8001AADC 08002391 */  lbu        $v1, 0x8($t1)
    /* B2E0 8001AAE0 00000000 */  nop
    /* B2E4 8001AAE4 21104300 */  addu       $v0, $v0, $v1
    /* B2E8 8001AAE8 0600C386 */  lh         $v1, 0x6($s6)
    /* B2EC 8001AAEC 2100C2A2 */  sb         $v0, 0x21($s6)
    /* B2F0 8001AAF0 FF004230 */  andi       $v0, $v0, 0xFF
    /* B2F4 8001AAF4 2A104300 */  slt        $v0, $v0, $v1
    /* B2F8 8001AAF8 08004014 */  bnez       $v0, .L8001AB1C
    /* B2FC 8001AAFC 00000000 */   nop
    /* B300 8001AB00 2200C292 */  lbu        $v0, 0x22($s6)
    /* B304 8001AB04 2100C392 */  lbu        $v1, 0x21($s6)
    /* B308 8001AB08 0600C492 */  lbu        $a0, 0x6($s6)
    /* B30C 8001AB0C 01004224 */  addiu      $v0, $v0, 0x1
    /* B310 8001AB10 23186400 */  subu       $v1, $v1, $a0
    /* B314 8001AB14 2200C2A2 */  sb         $v0, 0x22($s6)
    /* B318 8001AB18 2100C3A2 */  sb         $v1, 0x21($s6)
  .L8001AB1C:
    /* B31C 8001AB1C 01004292 */  lbu        $v0, 0x1($s2)
    /* B320 8001AB20 00000000 */  nop
    /* B324 8001AB24 0E004010 */  beqz       $v0, .L8001AB60
    /* B328 8001AB28 0D000A24 */   addiu     $t2, $zero, 0xD
    /* B32C 8001AB2C 1001043C */  lui        $a0, (0x1100000 >> 16)
    /* B330 8001AB30 08000224 */  addiu      $v0, $zero, 0x8
    /* B334 8001AB34 1800A2A7 */  sh         $v0, 0x18($sp)
    /* B338 8001AB38 21104001 */  addu       $v0, $t2, $zero
    /* B33C 8001AB3C 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* B340 8001AB40 09000224 */  addiu      $v0, $zero, 0x9
    /* B344 8001AB44 2000A2A7 */  sh         $v0, 0x20($sp)
    /* B348 8001AB48 0E000224 */  addiu      $v0, $zero, 0xE
    /* B34C 8001AB4C 5C00AAAF */  sw         $t2, 0x5C($sp)
    /* B350 8001AB50 E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* B354 8001AB54 2200A2A7 */   sh        $v0, 0x22($sp)
    /* B358 8001AB58 E46A0008 */  j          .L8001AB90
    /* B35C 8001AB5C 1001043C */   lui       $a0, (0x1100000 >> 16)
  .L8001AB60:
    /* B360 8001AB60 11000724 */  addiu      $a3, $zero, 0x11
    /* B364 8001AB64 3A01043C */  lui        $a0, (0x13A0000 >> 16)
    /* B368 8001AB68 07000224 */  addiu      $v0, $zero, 0x7
    /* B36C 8001AB6C 09000324 */  addiu      $v1, $zero, 0x9
    /* B370 8001AB70 1800A2A7 */  sh         $v0, 0x18($sp)
    /* B374 8001AB74 2000A2A7 */  sh         $v0, 0x20($sp)
    /* B378 8001AB78 0A000224 */  addiu      $v0, $zero, 0xA
    /* B37C 8001AB7C 5C00A7AF */  sw         $a3, 0x5C($sp)
    /* B380 8001AB80 1A00A3A7 */  sh         $v1, 0x1A($sp)
    /* B384 8001AB84 E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* B388 8001AB88 2200A2A7 */   sh        $v0, 0x22($sp)
    /* B38C 8001AB8C 3A01043C */  lui        $a0, (0x13A0000 >> 16)
  .L8001AB90:
    /* B390 8001AB90 E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* B394 8001AB94 1000A2AF */   sw        $v0, 0x10($sp)
    /* B398 8001AB98 1400A2AF */  sw         $v0, 0x14($sp)
    /* B39C 8001AB9C 0580023C */  lui        $v0, %hi(Text_ReturnStack)
    /* B3A0 8001ABA0 A000A88F */  lw         $t0, 0xA0($sp)
    /* B3A4 8001ABA4 9C00A98F */  lw         $t1, 0x9C($sp)
    /* B3A8 8001ABA8 5400AA8F */  lw         $t2, 0x54($sp)
    /* B3AC 8001ABAC 21A00000 */  addu       $s4, $zero, $zero
    /* B3B0 8001ABB0 D04C40AC */  sw         $zero, %lo(Text_ReturnStack)($v0)
    /* B3B4 8001ABB4 9000A0AF */  sw         $zero, 0x90($sp)
    /* B3B8 8001ABB8 22005325 */  addiu      $s3, $t2, 0x22
    /* B3BC 8001ABBC 9400A8AF */  sw         $t0, 0x94($sp)
    /* B3C0 8001ABC0 9800A9AF */  sw         $t1, 0x98($sp)
  .L8001ABC4:
    /* B3C4 8001ABC4 00002292 */  lbu        $v0, 0x0($s1)
    /* B3C8 8001ABC8 00000000 */  nop
    /* B3CC 8001ABCC 11FF4324 */  addiu      $v1, $v0, -0xEF
    /* B3D0 8001ABD0 1100622C */  sltiu      $v0, $v1, 0x11
    /* B3D4 8001ABD4 25034010 */  beqz       $v0, .L8001B86C
    /* B3D8 8001ABD8 0180023C */   lui       $v0, %hi(jtbl_8001014C)
    /* B3DC 8001ABDC 4C014224 */  addiu      $v0, $v0, %lo(jtbl_8001014C)
    /* B3E0 8001ABE0 80180300 */  sll        $v1, $v1, 2
    /* B3E4 8001ABE4 21186200 */  addu       $v1, $v1, $v0
    /* B3E8 8001ABE8 0000628C */  lw         $v0, 0x0($v1)
    /* B3EC 8001ABEC 00000000 */  nop
    /* B3F0 8001ABF0 08004000 */  jr         $v0
    /* B3F4 8001ABF4 00000000 */   nop
  jlabel .L8001ABF8
    /* B3F8 8001ABF8 486A000C */  jal        Text_PopReturn
    /* B3FC 8001ABFC 00000000 */   nop
    /* B400 8001AC00 12034014 */  bnez       $v0, .L8001B84C
    /* B404 8001AC04 00000000 */   nop
    /* B408 8001AC08 01001424 */  addiu      $s4, $zero, 0x1
    /* B40C 8001AC0C 21388002 */  addu       $a3, $s4, $zero
    /* B410 8001AC10 060040A6 */  sh         $zero, 0x6($s2)
    /* B414 8001AC14 BC6E0008 */  j          .L8001BAF0
    /* B418 8001AC18 230047A2 */   sb        $a3, 0x23($s2)
  jlabel .L8001AC1C
    /* B41C 8001AC1C 1C004296 */  lhu        $v0, 0x1C($s2)
    /* B420 8001AC20 00000000 */  nop
    /* B424 8001AC24 2800A2A7 */  sh         $v0, 0x28($sp)
    /* B428 8001AC28 04004392 */  lbu        $v1, 0x4($s2)
    /* B42C 8001AC2C 2A00A297 */  lhu        $v0, 0x2A($sp)
    /* B430 8001AC30 00000000 */  nop
    /* B434 8001AC34 21104300 */  addu       $v0, $v0, $v1
    /* B438 8001AC38 BC6E0008 */  j          .L8001BAF0
    /* B43C 8001AC3C 2A00A2A7 */   sh        $v0, 0x2A($sp)
  jlabel .L8001AC40
    /* B440 8001AC40 03004392 */  lbu        $v1, 0x3($s2)
    /* B444 8001AC44 2800A297 */  lhu        $v0, 0x28($sp)
    /* B448 8001AC48 9000A88F */  lw         $t0, 0x90($sp)
    /* B44C 8001AC4C 21104300 */  addu       $v0, $v0, $v1
    /* B450 8001AC50 A7030015 */  bnez       $t0, .L8001BAF0
    /* B454 8001AC54 2800A2A7 */   sh        $v0, 0x28($sp)
    /* B458 8001AC58 22004392 */  lbu        $v1, 0x22($s2)
    /* B45C 8001AC5C 0100A226 */  addiu      $v0, $s5, 0x1
    /* B460 8001AC60 2A104300 */  slt        $v0, $v0, $v1
    /* B464 8001AC64 A2034014 */  bnez       $v0, .L8001BAF0
    /* B468 8001AC68 00000000 */   nop
    /* B46C 8001AC6C 01000924 */  addiu      $t1, $zero, 0x1
    /* B470 8001AC70 21106900 */  addu       $v0, $v1, $t1
    /* B474 8001AC74 BB6E0008 */  j          .L8001BAEC
    /* B478 8001AC78 9000A9AF */   sw        $t1, 0x90($sp)
  jlabel .L8001AC7C
    /* B47C 8001AC7C 01002226 */  addiu      $v0, $s1, 0x1
    /* B480 8001AC80 080042AE */  sw         $v0, 0x8($s2)
    /* B484 8001AC84 220040A2 */  sb         $zero, 0x22($s2)
    /* B488 8001AC88 240040A2 */  sb         $zero, 0x24($s2)
    /* B48C 8001AC8C 250040A2 */  sb         $zero, 0x25($s2)
    /* B490 8001AC90 260040A2 */  sb         $zero, 0x26($s2)
    /* B494 8001AC94 2A0040A2 */  sb         $zero, 0x2A($s2)
    /* B498 8001AC98 2B0040A2 */  sb         $zero, 0x2B($s2)
    /* B49C 8001AC9C 2C0040A2 */  sb         $zero, 0x2C($s2)
    /* B4A0 8001ACA0 2D0040A2 */  sb         $zero, 0x2D($s2)
    /* B4A4 8001ACA4 2E0040A2 */  sb         $zero, 0x2E($s2)
    /* B4A8 8001ACA8 BC6E0008 */  j          .L8001BAF0
    /* B4AC 8001ACAC 2F0040A2 */   sb        $zero, 0x2F($s2)
  jlabel .L8001ACB0
    /* B4B0 8001ACB0 25004292 */  lbu        $v0, 0x25($s2)
    /* B4B4 8001ACB4 6800AA8F */  lw         $t2, 0x68($sp)
    /* B4B8 8001ACB8 00000000 */  nop
    /* B4BC 8001ACBC 29004A14 */  bne        $v0, $t2, .L8001AD64
    /* B4C0 8001ACC0 0680073C */   lui       $a3, %hi(D_8005F6F0)
    /* B4C4 8001ACC4 30004292 */  lbu        $v0, 0x30($s2)
    /* B4C8 8001ACC8 F0F6E724 */  addiu      $a3, $a3, %lo(D_8005F6F0)
    /* B4CC 8001ACCC 80110200 */  sll        $v0, $v0, 6
    /* B4D0 8001ACD0 21104700 */  addu       $v0, $v0, $a3
    /* B4D4 8001ACD4 1400428C */  lw         $v0, 0x14($v0)
    /* B4D8 8001ACD8 00000000 */  nop
    /* B4DC 8001ACDC 09004018 */  blez       $v0, .L8001AD04
    /* B4E0 8001ACE0 01001424 */   addiu     $s4, $zero, 0x1
    /* B4E4 8001ACE4 13000424 */  addiu      $a0, $zero, 0x13
    /* B4E8 8001ACE8 21280000 */  addu       $a1, $zero, $zero
    /* B4EC 8001ACEC 21105401 */  addu       $v0, $t2, $s4
    /* B4F0 8001ACF0 250042A2 */  sb         $v0, 0x25($s2)
    /* B4F4 8001ACF4 A369000C */  jal        Snd_PlayById
    /* B4F8 8001ACF8 270040A2 */   sb        $zero, 0x27($s2)
    /* B4FC 8001ACFC 596B0008 */  j          .L8001AD64
    /* B500 8001AD00 00000000 */   nop
  .L8001AD04:
    /* B504 8001AD04 0680093C */  lui        $t1, %hi(D_8005F770)
    /* B508 8001AD08 70F72925 */  addiu      $t1, $t1, %lo(D_8005F770)
    /* B50C 8001AD0C 4800A88F */  lw         $t0, 0x48($sp)
    /* B510 8001AD10 0800228D */  lw         $v0, 0x8($t1)
    /* B514 8001AD14 280A038D */  lw         $v1, 0xA28($t0)
    /* B518 8001AD18 00000000 */  nop
    /* B51C 8001AD1C 21186200 */  addu       $v1, $v1, $v0
    /* B520 8001AD20 18006228 */  slti       $v0, $v1, 0x18
    /* B524 8001AD24 03004014 */  bnez       $v0, .L8001AD34
    /* B528 8001AD28 280A03AD */   sw        $v1, 0xA28($t0)
    /* B52C 8001AD2C E8FF6224 */  addiu      $v0, $v1, -0x18
    /* B530 8001AD30 280A02AD */  sw         $v0, 0xA28($t0)
  .L8001AD34:
    /* B534 8001AD34 4800AA8F */  lw         $t2, 0x48($sp)
    /* B538 8001AD38 AA2A033C */  lui        $v1, (0x2AAAAAAB >> 16)
    /* B53C 8001AD3C 280A428D */  lw         $v0, 0xA28($t2)
    /* B540 8001AD40 ABAA6334 */  ori        $v1, $v1, (0x2AAAAAAB & 0xFFFF)
    /* B544 8001AD44 18004300 */  mult       $v0, $v1
    /* B548 8001AD48 270054A2 */  sb         $s4, 0x27($s2)
    /* B54C 8001AD4C C3170200 */  sra        $v0, $v0, 31
    /* B550 8001AD50 10380000 */  mfhi       $a3
    /* B554 8001AD54 2310E200 */  subu       $v0, $a3, $v0
    /* B558 8001AD58 03004230 */  andi       $v0, $v0, 0x3
    /* B55C 8001AD5C 1C6E0008 */  j          .L8001B870
    /* B560 8001AD60 4F004424 */   addiu     $a0, $v0, 0x4F
  .L8001AD64:
    /* B564 8001AD64 6800A88F */  lw         $t0, 0x68($sp)
    /* B568 8001AD68 00000000 */  nop
    /* B56C 8001AD6C 01000825 */  addiu      $t0, $t0, 0x1
    /* B570 8001AD70 BC6E0008 */  j          .L8001BAF0
    /* B574 8001AD74 6800A8AF */   sw        $t0, 0x68($sp)
  jlabel .L8001AD78
    /* B578 8001AD78 24004292 */  lbu        $v0, 0x24($s2)
    /* B57C 8001AD7C 6400A98F */  lw         $t1, 0x64($sp)
    /* B580 8001AD80 00000000 */  nop
    /* B584 8001AD84 6E004914 */  bne        $v0, $t1, .L8001AF40
    /* B588 8001AD88 01003126 */   addiu     $s1, $s1, 0x1
    /* B58C 8001AD8C 1400C38F */  lw         $v1, 0x14($fp)
    /* B590 8001AD90 01000A24 */  addiu      $t2, $zero, 0x1
    /* B594 8001AD94 51006A10 */  beq        $v1, $t2, .L8001AEDC
    /* B598 8001AD98 02006228 */   slti      $v0, $v1, 0x2
    /* B59C 8001AD9C 03004014 */  bnez       $v0, .L8001ADAC
    /* B5A0 8001ADA0 02000224 */   addiu     $v0, $zero, 0x2
    /* B5A4 8001ADA4 5A006210 */  beq        $v1, $v0, .L8001AF10
    /* B5A8 8001ADA8 00000000 */   nop
  .L8001ADAC:
    /* B5AC 8001ADAC 00002292 */  lbu        $v0, 0x0($s1)
    /* B5B0 8001ADB0 00000000 */  nop
    /* B5B4 8001ADB4 01004230 */  andi       $v0, $v0, 0x1
    /* B5B8 8001ADB8 02004010 */  beqz       $v0, .L8001ADC4
    /* B5BC 8001ADBC 37000424 */   addiu     $a0, $zero, 0x37
    /* B5C0 8001ADC0 38000424 */  addiu      $a0, $zero, 0x38
  .L8001ADC4:
    /* B5C4 8001ADC4 A369000C */  jal        Snd_PlayById
    /* B5C8 8001ADC8 21280000 */   addu      $a1, $zero, $zero
    /* B5CC 8001ADCC 00002392 */  lbu        $v1, 0x0($s1)
    /* B5D0 8001ADD0 00000000 */  nop
    /* B5D4 8001ADD4 0800622C */  sltiu      $v0, $v1, 0x8
    /* B5D8 8001ADD8 3A004010 */  beqz       $v0, .L8001AEC4
    /* B5DC 8001ADDC 0180023C */   lui       $v0, %hi(jtbl_80010194)
    /* B5E0 8001ADE0 94014224 */  addiu      $v0, $v0, %lo(jtbl_80010194)
    /* B5E4 8001ADE4 80180300 */  sll        $v1, $v1, 2
    /* B5E8 8001ADE8 21186200 */  addu       $v1, $v1, $v0
    /* B5EC 8001ADEC 0000628C */  lw         $v0, 0x0($v1)
    /* B5F0 8001ADF0 00000000 */  nop
    /* B5F4 8001ADF4 08004000 */  jr         $v0
    /* B5F8 8001ADF8 00000000 */   nop
  jlabel .L8001ADFC
    /* B5FC 8001ADFC 04000424 */  addiu      $a0, $zero, 0x4
    /* B600 8001AE00 4C00A78F */  lw         $a3, 0x4C($sp)
    /* B604 8001AE04 9400A88F */  lw         $t0, 0x94($sp)
    /* B608 8001AE08 21300000 */  addu       $a2, $zero, $zero
    /* B60C 8001AE0C 1F44000C */  jal        Task_Create
    /* B610 8001AE10 2128E800 */   addu      $a1, $a3, $t0
    /* B614 8001AE14 70FF0224 */  addiu      $v0, $zero, -0x90
    /* B618 8001AE18 1C0042A6 */  sh         $v0, 0x1C($s2)
    /* B61C 8001AE1C 34000224 */  addiu      $v0, $zero, 0x34
    /* B620 8001AE20 B16B0008 */  j          .L8001AEC4
    /* B624 8001AE24 1E0042A6 */   sh        $v0, 0x1E($s2)
  jlabel .L8001AE28
    /* B628 8001AE28 04000424 */  addiu      $a0, $zero, 0x4
    /* B62C 8001AE2C 4C00A98F */  lw         $t1, 0x4C($sp)
    /* B630 8001AE30 9400AA8F */  lw         $t2, 0x94($sp)
    /* B634 8001AE34 01000624 */  addiu      $a2, $zero, 0x1
    /* B638 8001AE38 956B0008 */  j          .L8001AE54
    /* B63C 8001AE3C 21282A01 */   addu      $a1, $t1, $t2
  jlabel .L8001AE40
    /* B640 8001AE40 04000424 */  addiu      $a0, $zero, 0x4
    /* B644 8001AE44 4C00A78F */  lw         $a3, 0x4C($sp)
    /* B648 8001AE48 9400A88F */  lw         $t0, 0x94($sp)
    /* B64C 8001AE4C 03000624 */  addiu      $a2, $zero, 0x3
    /* B650 8001AE50 2128E800 */  addu       $a1, $a3, $t0
  .L8001AE54:
    /* B654 8001AE54 1F44000C */  jal        Task_Create
    /* B658 8001AE58 00000000 */   nop
    /* B65C 8001AE5C 70FF0224 */  addiu      $v0, $zero, -0x90
    /* B660 8001AE60 1C0042A6 */  sh         $v0, 0x1C($s2)
    /* B664 8001AE64 42000224 */  addiu      $v0, $zero, 0x42
    /* B668 8001AE68 B16B0008 */  j          .L8001AEC4
    /* B66C 8001AE6C 1E0042A6 */   sh        $v0, 0x1E($s2)
  jlabel .L8001AE70
    /* B670 8001AE70 04000424 */  addiu      $a0, $zero, 0x4
    /* B674 8001AE74 4C00A98F */  lw         $t1, 0x4C($sp)
    /* B678 8001AE78 9400AA8F */  lw         $t2, 0x94($sp)
    /* B67C 8001AE7C 02000624 */  addiu      $a2, $zero, 0x2
    /* B680 8001AE80 1F44000C */  jal        Task_Create
    /* B684 8001AE84 21282A01 */   addu      $a1, $t1, $t2
    /* B688 8001AE88 70FF0224 */  addiu      $v0, $zero, -0x90
    /* B68C 8001AE8C 1C0042A6 */  sh         $v0, 0x1C($s2)
    /* B690 8001AE90 12000224 */  addiu      $v0, $zero, 0x12
    /* B694 8001AE94 B16B0008 */  j          .L8001AEC4
    /* B698 8001AE98 1E0042A6 */   sh        $v0, 0x1E($s2)
  jlabel .L8001AE9C
    /* B69C 8001AE9C 9800A78F */  lw         $a3, 0x98($sp)
    /* B6A0 8001AEA0 00000000 */  nop
    /* B6A4 8001AEA4 0400E48C */  lw         $a0, 0x4($a3)
    /* B6A8 8001AEA8 00000000 */  nop
    /* B6AC 8001AEAC 03008010 */  beqz       $a0, .L8001AEBC
    /* B6B0 8001AEB0 00000000 */   nop
    /* B6B4 8001AEB4 7045000C */  jal        Task_SetState0
    /* B6B8 8001AEB8 02000524 */   addiu     $a1, $zero, 0x2
  .L8001AEBC:
    /* B6BC 8001AEBC 5945000C */  jal        Task_NextState1
    /* B6C0 8001AEC0 2120C003 */   addu      $a0, $fp, $zero
  .L8001AEC4:
    /* B6C4 8001AEC4 01000824 */  addiu      $t0, $zero, 0x1
    /* B6C8 8001AEC8 270048A2 */  sb         $t0, 0x27($s2)
    /* B6CC 8001AECC 5945000C */  jal        Task_NextState1
    /* B6D0 8001AED0 2120C003 */   addu      $a0, $fp, $zero
    /* B6D4 8001AED4 D06B0008 */  j          .L8001AF40
    /* B6D8 8001AED8 00000000 */   nop
  .L8001AEDC:
    /* B6DC 8001AEDC 9800A98F */  lw         $t1, 0x98($sp)
    /* B6E0 8001AEE0 00000000 */  nop
    /* B6E4 8001AEE4 0400228D */  lw         $v0, 0x4($t1)
    /* B6E8 8001AEE8 00000000 */  nop
    /* B6EC 8001AEEC 1400428C */  lw         $v0, 0x14($v0)
    /* B6F0 8001AEF0 01000A24 */  addiu      $t2, $zero, 0x1
    /* B6F4 8001AEF4 12004A14 */  bne        $v0, $t2, .L8001AF40
    /* B6F8 8001AEF8 2120C003 */   addu      $a0, $fp, $zero
    /* B6FC 8001AEFC 24004292 */  lbu        $v0, 0x24($s2)
    /* B700 8001AF00 21280000 */  addu       $a1, $zero, $zero
    /* B704 8001AF04 270040A2 */  sb         $zero, 0x27($s2)
    /* B708 8001AF08 CE6B0008 */  j          .L8001AF38
    /* B70C 8001AF0C 21104A00 */   addu      $v0, $v0, $t2
  .L8001AF10:
    /* B710 8001AF10 9800A78F */  lw         $a3, 0x98($sp)
    /* B714 8001AF14 00000000 */  nop
    /* B718 8001AF18 0400E28C */  lw         $v0, 0x4($a3)
    /* B71C 8001AF1C 00000000 */  nop
    /* B720 8001AF20 07004014 */  bnez       $v0, .L8001AF40
    /* B724 8001AF24 2120C003 */   addu      $a0, $fp, $zero
    /* B728 8001AF28 24004292 */  lbu        $v0, 0x24($s2)
    /* B72C 8001AF2C 21280000 */  addu       $a1, $zero, $zero
    /* B730 8001AF30 270040A2 */  sb         $zero, 0x27($s2)
    /* B734 8001AF34 01004224 */  addiu      $v0, $v0, 0x1
  .L8001AF38:
    /* B738 8001AF38 7745000C */  jal        Task_SetState1
    /* B73C 8001AF3C 240042A2 */   sb        $v0, 0x24($s2)
  .L8001AF40:
    /* B740 8001AF40 6400A88F */  lw         $t0, 0x64($sp)
    /* B744 8001AF44 00000000 */  nop
    /* B748 8001AF48 01000825 */  addiu      $t0, $t0, 0x1
    /* B74C 8001AF4C BC6E0008 */  j          .L8001BAF0
    /* B750 8001AF50 6400A8AF */   sw        $t0, 0x64($sp)
  jlabel .L8001AF54
    /* B754 8001AF54 01003126 */  addiu      $s1, $s1, 0x1
    /* B758 8001AF58 00002592 */  lbu        $a1, 0x0($s1)
    /* B75C 8001AF5C 00000000 */  nop
    /* B760 8001AF60 0100A230 */  andi       $v0, $a1, 0x1
    /* B764 8001AF64 11004010 */  beqz       $v0, .L8001AFAC
    /* B768 8001AF68 00000000 */   nop
    /* B76C 8001AF6C 26004292 */  lbu        $v0, 0x26($s2)
    /* B770 8001AF70 6C00A98F */  lw         $t1, 0x6C($sp)
    /* B774 8001AF74 00000000 */  nop
    /* B778 8001AF78 3F004914 */  bne        $v0, $t1, .L8001B078
    /* B77C 8001AF7C 40100500 */   sll       $v0, $a1, 1
    /* B780 8001AF80 4C00AA8F */  lw         $t2, 0x4C($sp)
    /* B784 8001AF84 04004230 */  andi       $v0, $v0, 0x4
    /* B788 8001AF88 21104201 */  addu       $v0, $t2, $v0
    /* B78C 8001AF8C CC00448C */  lw         $a0, 0xCC($v0)
    /* B790 8001AF90 00000000 */  nop
    /* B794 8001AF94 03008010 */  beqz       $a0, .L8001AFA4
    /* B798 8001AF98 00000000 */   nop
    /* B79C 8001AF9C 7045000C */  jal        Task_SetState0
    /* B7A0 8001AFA0 02000524 */   addiu     $a1, $zero, 0x2
  .L8001AFA4:
    /* B7A4 8001AFA4 166C0008 */  j          .L8001B058
    /* B7A8 8001AFA8 3A000424 */   addiu     $a0, $zero, 0x3A
  .L8001AFAC:
    /* B7AC 8001AFAC 26004292 */  lbu        $v0, 0x26($s2)
    /* B7B0 8001AFB0 6C00A78F */  lw         $a3, 0x6C($sp)
    /* B7B4 8001AFB4 00000000 */  nop
    /* B7B8 8001AFB8 2E004714 */  bne        $v0, $a3, .L8001B074
    /* B7BC 8001AFBC 42280500 */   srl       $a1, $a1, 1
    /* B7C0 8001AFC0 01003126 */  addiu      $s1, $s1, 0x1
    /* B7C4 8001AFC4 0100A530 */  andi       $a1, $a1, 0x1
    /* B7C8 8001AFC8 3400A5AF */  sw         $a1, 0x34($sp)
    /* B7CC 8001AFCC 00002292 */  lbu        $v0, 0x0($s1)
    /* B7D0 8001AFD0 01003126 */  addiu      $s1, $s1, 0x1
    /* B7D4 8001AFD4 80280500 */  sll        $a1, $a1, 2
    /* B7D8 8001AFD8 40180200 */  sll        $v1, $v0, 1
    /* B7DC 8001AFDC 21186200 */  addu       $v1, $v1, $v0
    /* B7E0 8001AFE0 C0180300 */  sll        $v1, $v1, 3
    /* B7E4 8001AFE4 21186200 */  addu       $v1, $v1, $v0
    /* B7E8 8001AFE8 80180300 */  sll        $v1, $v1, 2
    /* B7EC 8001AFEC 3000A3AF */  sw         $v1, 0x30($sp)
    /* B7F0 8001AFF0 00002492 */  lbu        $a0, 0x0($s1)
    /* B7F4 8001AFF4 01003126 */  addiu      $s1, $s1, 0x1
    /* B7F8 8001AFF8 80100400 */  sll        $v0, $a0, 2
    /* B7FC 8001AFFC 21104400 */  addu       $v0, $v0, $a0
    /* B800 8001B000 40100200 */  sll        $v0, $v0, 1
    /* B804 8001B004 21186200 */  addu       $v1, $v1, $v0
    /* B808 8001B008 3000A3AF */  sw         $v1, 0x30($sp)
    /* B80C 8001B00C 00002292 */  lbu        $v0, 0x0($s1)
    /* B810 8001B010 4C00A88F */  lw         $t0, 0x4C($sp)
    /* B814 8001B014 21186200 */  addu       $v1, $v1, $v0
    /* B818 8001B018 21100501 */  addu       $v0, $t0, $a1
    /* B81C 8001B01C 3000A3AF */  sw         $v1, 0x30($sp)
    /* B820 8001B020 CC00448C */  lw         $a0, 0xCC($v0)
    /* B824 8001B024 00000000 */  nop
    /* B828 8001B028 05008010 */  beqz       $a0, .L8001B040
    /* B82C 8001B02C CC00A524 */   addiu     $a1, $a1, 0xCC
    /* B830 8001B030 D646000C */  jal        func_80011B58
    /* B834 8001B034 21286000 */   addu      $a1, $v1, $zero
    /* B838 8001B038 166C0008 */  j          .L8001B058
    /* B83C 8001B03C 39000424 */   addiu     $a0, $zero, 0x39
  .L8001B040:
    /* B840 8001B040 05000424 */  addiu      $a0, $zero, 0x5
    /* B844 8001B044 4C00A98F */  lw         $t1, 0x4C($sp)
    /* B848 8001B048 3000A627 */  addiu      $a2, $sp, 0x30
    /* B84C 8001B04C 1F44000C */  jal        Task_Create
    /* B850 8001B050 21282501 */   addu      $a1, $t1, $a1
    /* B854 8001B054 39000424 */  addiu      $a0, $zero, 0x39
  .L8001B058:
    /* B858 8001B058 26004292 */  lbu        $v0, 0x26($s2)
    /* B85C 8001B05C 21280000 */  addu       $a1, $zero, $zero
    /* B860 8001B060 01004224 */  addiu      $v0, $v0, 0x1
    /* B864 8001B064 A369000C */  jal        Snd_PlayById
    /* B868 8001B068 260042A2 */   sb        $v0, 0x26($s2)
    /* B86C 8001B06C 1E6C0008 */  j          .L8001B078
    /* B870 8001B070 00000000 */   nop
  .L8001B074:
    /* B874 8001B074 03003126 */  addiu      $s1, $s1, 0x3
  .L8001B078:
    /* B878 8001B078 6C00AA8F */  lw         $t2, 0x6C($sp)
    /* B87C 8001B07C 00000000 */  nop
    /* B880 8001B080 01004A25 */  addiu      $t2, $t2, 0x1
    /* B884 8001B084 BC6E0008 */  j          .L8001BAF0
    /* B888 8001B088 6C00AAAF */   sw        $t2, 0x6C($sp)
  .L8001B08C:
    /* B88C 8001B08C 290054A2 */  sb         $s4, 0x29($s2)
    /* B890 8001B090 526C0008 */  j          .L8001B148
    /* B894 8001B094 0C000424 */   addiu     $a0, $zero, 0xC
  .L8001B098:
    /* B898 8001B098 290040A2 */  sb         $zero, 0x29($s2)
    /* B89C 8001B09C 526C0008 */  j          .L8001B148
    /* B8A0 8001B0A0 0C000424 */   addiu     $a0, $zero, 0xC
  jlabel .L8001B0A4
    /* B8A4 8001B0A4 28004292 */  lbu        $v0, 0x28($s2)
    /* B8A8 8001B0A8 7000A78F */  lw         $a3, 0x70($sp)
    /* B8AC 8001B0AC 00000000 */  nop
    /* B8B0 8001B0B0 36004714 */  bne        $v0, $a3, .L8001B18C
    /* B8B4 8001B0B4 01003126 */   addiu     $s1, $s1, 0x1
    /* B8B8 8001B0B8 00002392 */  lbu        $v1, 0x0($s1)
    /* B8BC 8001B0BC 01000824 */  addiu      $t0, $zero, 0x1
    /* B8C0 8001B0C0 28006810 */  beq        $v1, $t0, .L8001B164
    /* B8C4 8001B0C4 02006228 */   slti      $v0, $v1, 0x2
    /* B8C8 8001B0C8 03004014 */  bnez       $v0, .L8001B0D8
    /* B8CC 8001B0CC 02000224 */   addiu     $v0, $zero, 0x2
    /* B8D0 8001B0D0 2A006210 */  beq        $v1, $v0, .L8001B17C
    /* B8D4 8001B0D4 00000000 */   nop
  .L8001B0D8:
    /* B8D8 8001B0D8 01001424 */  addiu      $s4, $zero, 0x1
    /* B8DC 8001B0DC 0680093C */  lui        $t1, %hi(D_8005F6F0)
    /* B8E0 8001B0E0 30004292 */  lbu        $v0, 0x30($s2)
    /* B8E4 8001B0E4 F0F62925 */  addiu      $t1, $t1, %lo(D_8005F6F0)
    /* B8E8 8001B0E8 270054A2 */  sb         $s4, 0x27($s2)
    /* B8EC 8001B0EC 80110200 */  sll        $v0, $v0, 6
    /* B8F0 8001B0F0 21204900 */  addu       $a0, $v0, $t1
    /* B8F4 8001B0F4 3A008394 */  lhu        $v1, 0x3A($a0)
    /* B8F8 8001B0F8 00000000 */  nop
    /* B8FC 8001B0FC 00606230 */  andi       $v0, $v1, 0x6000
    /* B900 8001B100 E2FF4014 */  bnez       $v0, .L8001B08C
    /* B904 8001B104 00906230 */   andi      $v0, $v1, 0x9000
    /* B908 8001B108 E3FF4014 */  bnez       $v0, .L8001B098
    /* B90C 8001B10C 00000000 */   nop
    /* B910 8001B110 1400828C */  lw         $v0, 0x14($a0)
    /* B914 8001B114 00000000 */  nop
    /* B918 8001B118 0D004018 */  blez       $v0, .L8001B150
    /* B91C 8001B11C 10000424 */   addiu     $a0, $zero, 0x10
    /* B920 8001B120 28004292 */  lbu        $v0, 0x28($s2)
    /* B924 8001B124 21288002 */  addu       $a1, $s4, $zero
    /* B928 8001B128 270040A2 */  sb         $zero, 0x27($s2)
    /* B92C 8001B12C 21105400 */  addu       $v0, $v0, $s4
    /* B930 8001B130 7188000C */  jal        Flag_Set
    /* B934 8001B134 280042A2 */   sb        $v0, 0x28($s2)
    /* B938 8001B138 29004592 */  lbu        $a1, 0x29($s2)
    /* B93C 8001B13C 7188000C */  jal        Flag_Set
    /* B940 8001B140 11000424 */   addiu     $a0, $zero, 0x11
    /* B944 8001B144 0A000424 */  addiu      $a0, $zero, 0xA
  .L8001B148:
    /* B948 8001B148 A369000C */  jal        Snd_PlayById
    /* B94C 8001B14C 21280000 */   addu      $a1, $zero, $zero
  .L8001B150:
    /* B950 8001B150 7000AA8F */  lw         $t2, 0x70($sp)
    /* B954 8001B154 00000000 */  nop
    /* B958 8001B158 01004A25 */  addiu      $t2, $t2, 0x1
    /* B95C 8001B15C BC6E0008 */  j          .L8001BAF0
    /* B960 8001B160 7000AAAF */   sw        $t2, 0x70($sp)
  .L8001B164:
    /* B964 8001B164 29004292 */  lbu        $v0, 0x29($s2)
    /* B968 8001B168 00000000 */  nop
    /* B96C 8001B16C C0014010 */  beqz       $v0, .L8001B870
    /* B970 8001B170 53000424 */   addiu     $a0, $zero, 0x53
    /* B974 8001B174 636C0008 */  j          .L8001B18C
    /* B978 8001B178 00000000 */   nop
  .L8001B17C:
    /* B97C 8001B17C 29004292 */  lbu        $v0, 0x29($s2)
    /* B980 8001B180 01000724 */  addiu      $a3, $zero, 0x1
    /* B984 8001B184 BA014710 */  beq        $v0, $a3, .L8001B870
    /* B988 8001B188 53000424 */   addiu     $a0, $zero, 0x53
  .L8001B18C:
    /* B98C 8001B18C 03004392 */  lbu        $v1, 0x3($s2)
    /* B990 8001B190 2800A297 */  lhu        $v0, 0x28($sp)
    /* B994 8001B194 00000000 */  nop
    /* B998 8001B198 21104300 */  addu       $v0, $v0, $v1
    /* B99C 8001B19C BC6E0008 */  j          .L8001BAF0
    /* B9A0 8001B1A0 2800A2A7 */   sh        $v0, 0x28($sp)
  jlabel .L8001B1A4
    /* B9A4 8001B1A4 0680083C */  lui        $t0, %hi(D_8005F770)
    /* B9A8 8001B1A8 70F70825 */  addiu      $t0, $t0, %lo(D_8005F770)
    /* B9AC 8001B1AC 00002292 */  lbu        $v0, 0x0($s1)
    /* B9B0 8001B1B0 1800038D */  lw         $v1, 0x18($t0)
    /* B9B4 8001B1B4 F6004238 */  xori       $v0, $v0, 0xF6
    /* B9B8 8001B1B8 0100422C */  sltiu      $v0, $v0, 0x1
    /* B9BC 8001B1BC 02006104 */  bgez       $v1, .L8001B1C8
    /* B9C0 8001B1C0 21B84000 */   addu      $s7, $v0, $zero
    /* B9C4 8001B1C4 FF006324 */  addiu      $v1, $v1, 0xFF
  .L8001B1C8:
    /* B9C8 8001B1C8 01003126 */  addiu      $s1, $s1, 0x1
    /* B9CC 8001B1CC 03120300 */  sra        $v0, $v1, 8
    /* B9D0 8001B1D0 02004238 */  xori       $v0, $v0, 0x2
    /* B9D4 8001B1D4 0100422C */  sltiu      $v0, $v0, 0x1
    /* B9D8 8001B1D8 2A004392 */  lbu        $v1, 0x2A($s2)
    /* B9DC 8001B1DC 7400A98F */  lw         $t1, 0x74($sp)
    /* B9E0 8001B1E0 00000000 */  nop
    /* B9E4 8001B1E4 4D006914 */  bne        $v1, $t1, .L8001B31C
    /* B9E8 8001B1E8 21804000 */   addu      $s0, $v0, $zero
    /* B9EC 8001B1EC 1400C28F */  lw         $v0, 0x14($fp)
    /* B9F0 8001B1F0 00000000 */  nop
    /* B9F4 8001B1F4 03004010 */  beqz       $v0, .L8001B204
    /* B9F8 8001B1F8 01000A24 */   addiu     $t2, $zero, 0x1
    /* B9FC 8001B1FC 2E004A10 */  beq        $v0, $t2, .L8001B2B8
    /* BA00 8001B200 FF000232 */   andi      $v0, $s0, 0xFF
  .L8001B204:
    /* BA04 8001B204 21300000 */  addu       $a2, $zero, $zero
    /* BA08 8001B208 3800A527 */  addiu      $a1, $sp, 0x38
  .L8001B20C:
    /* BA0C 8001B20C 00002292 */  lbu        $v0, 0x0($s1)
    /* BA10 8001B210 01003126 */  addiu      $s1, $s1, 0x1
    /* BA14 8001B214 0100C624 */  addiu      $a2, $a2, 0x1
    /* BA18 8001B218 40180200 */  sll        $v1, $v0, 1
    /* BA1C 8001B21C 21186200 */  addu       $v1, $v1, $v0
    /* BA20 8001B220 C0180300 */  sll        $v1, $v1, 3
    /* BA24 8001B224 21186200 */  addu       $v1, $v1, $v0
    /* BA28 8001B228 80180300 */  sll        $v1, $v1, 2
    /* BA2C 8001B22C 0000A3AC */  sw         $v1, 0x0($a1)
    /* BA30 8001B230 00002492 */  lbu        $a0, 0x0($s1)
    /* BA34 8001B234 01003126 */  addiu      $s1, $s1, 0x1
    /* BA38 8001B238 80100400 */  sll        $v0, $a0, 2
    /* BA3C 8001B23C 21104400 */  addu       $v0, $v0, $a0
    /* BA40 8001B240 40100200 */  sll        $v0, $v0, 1
    /* BA44 8001B244 21186200 */  addu       $v1, $v1, $v0
    /* BA48 8001B248 0000A3AC */  sw         $v1, 0x0($a1)
    /* BA4C 8001B24C 00002292 */  lbu        $v0, 0x0($s1)
    /* BA50 8001B250 01003126 */  addiu      $s1, $s1, 0x1
    /* BA54 8001B254 21186200 */  addu       $v1, $v1, $v0
    /* BA58 8001B258 0000A3AC */  sw         $v1, 0x0($a1)
    /* BA5C 8001B25C 0300C228 */  slti       $v0, $a2, 0x3
    /* BA60 8001B260 EAFF4014 */  bnez       $v0, .L8001B20C
    /* BA64 8001B264 0400A524 */   addiu     $a1, $a1, 0x4
    /* BA68 8001B268 FF000232 */  andi       $v0, $s0, 0xFF
    /* BA6C 8001B26C 05004010 */  beqz       $v0, .L8001B284
    /* BA70 8001B270 00000000 */   nop
    /* BA74 8001B274 EFC7010C */  jal        func_80071FBC
    /* BA78 8001B278 3800A427 */   addiu     $a0, $sp, 0x38
    /* BA7C 8001B27C AA6C0008 */  j          .L8001B2A8
    /* BA80 8001B280 01000824 */   addiu     $t0, $zero, 0x1
  .L8001B284:
    /* BA84 8001B284 3800A48F */  lw         $a0, 0x38($sp)
    /* BA88 8001B288 30AA010C */  jal        func_8006A8C0
    /* BA8C 8001B28C 00000000 */   nop
    /* BA90 8001B290 21204000 */  addu       $a0, $v0, $zero
    /* BA94 8001B294 4800A78F */  lw         $a3, 0x48($sp)
    /* BA98 8001B298 3C00A527 */  addiu      $a1, $sp, 0x3C
    /* BA9C 8001B29C 48AA010C */  jal        func_8006A920
    /* BAA0 8001B2A0 2C0AE4AC */   sw        $a0, 0xA2C($a3)
    /* BAA4 8001B2A4 01000824 */  addiu      $t0, $zero, 0x1
  .L8001B2A8:
    /* BAA8 8001B2A8 270048A2 */  sb         $t0, 0x27($s2)
    /* BAAC 8001B2AC 5945000C */  jal        Task_NextState1
    /* BAB0 8001B2B0 2120C003 */   addu      $a0, $fp, $zero
    /* BAB4 8001B2B4 FF000232 */  andi       $v0, $s0, 0xFF
  .L8001B2B8:
    /* BAB8 8001B2B8 0C004014 */  bnez       $v0, .L8001B2EC
    /* BABC 8001B2BC FF00E232 */   andi      $v0, $s7, 0xFF
    /* BAC0 8001B2C0 0E004010 */  beqz       $v0, .L8001B2FC
    /* BAC4 8001B2C4 2120C003 */   addu      $a0, $fp, $zero
    /* BAC8 8001B2C8 4800A98F */  lw         $t1, 0x48($sp)
    /* BACC 8001B2CC 00000000 */  nop
    /* BAD0 8001B2D0 2C0A248D */  lw         $a0, 0xA2C($t1)
    /* BAD4 8001B2D4 7EAA010C */  jal        func_8006A9F8
    /* BAD8 8001B2D8 00000000 */   nop
    /* BADC 8001B2DC 07004014 */  bnez       $v0, .L8001B2FC
    /* BAE0 8001B2E0 2120C003 */   addu      $a0, $fp, $zero
    /* BAE4 8001B2E4 C86C0008 */  j          .L8001B320
    /* BAE8 8001B2E8 00000000 */   nop
  .L8001B2EC:
    /* BAEC 8001B2EC 3FC8010C */  jal        func_800720FC
    /* BAF0 8001B2F0 00000000 */   nop
    /* BAF4 8001B2F4 0A004014 */  bnez       $v0, .L8001B320
    /* BAF8 8001B2F8 2120C003 */   addu      $a0, $fp, $zero
  .L8001B2FC:
    /* BAFC 8001B2FC 2A004292 */  lbu        $v0, 0x2A($s2)
    /* BB00 8001B300 21280000 */  addu       $a1, $zero, $zero
    /* BB04 8001B304 270040A2 */  sb         $zero, 0x27($s2)
    /* BB08 8001B308 01004224 */  addiu      $v0, $v0, 0x1
    /* BB0C 8001B30C 7745000C */  jal        Task_SetState1
    /* BB10 8001B310 2A0042A2 */   sb        $v0, 0x2A($s2)
    /* BB14 8001B314 C86C0008 */  j          .L8001B320
    /* BB18 8001B318 00000000 */   nop
  .L8001B31C:
    /* BB1C 8001B31C 08003126 */  addiu      $s1, $s1, 0x8
  .L8001B320:
    /* BB20 8001B320 7400AA8F */  lw         $t2, 0x74($sp)
    /* BB24 8001B324 00000000 */  nop
    /* BB28 8001B328 01004A25 */  addiu      $t2, $t2, 0x1
    /* BB2C 8001B32C BC6E0008 */  j          .L8001BAF0
    /* BB30 8001B330 7400AAAF */   sw        $t2, 0x74($sp)
  jlabel .L8001B334
    /* BB34 8001B334 2B004292 */  lbu        $v0, 0x2B($s2)
    /* BB38 8001B338 7800A78F */  lw         $a3, 0x78($sp)
    /* BB3C 8001B33C 00000000 */  nop
    /* BB40 8001B340 10004714 */  bne        $v0, $a3, .L8001B384
    /* BB44 8001B344 1E000224 */   addiu     $v0, $zero, 0x1E
    /* BB48 8001B348 4800A88F */  lw         $t0, 0x48($sp)
    /* BB4C 8001B34C 00000000 */  nop
    /* BB50 8001B350 300A038D */  lw         $v1, 0xA30($t0)
    /* BB54 8001B354 00000000 */  nop
    /* BB58 8001B358 06006214 */  bne        $v1, $v0, .L8001B374
    /* BB5C 8001B35C 01001424 */   addiu     $s4, $zero, 0x1
    /* BB60 8001B360 2110F400 */  addu       $v0, $a3, $s4
    /* BB64 8001B364 2B0042A2 */  sb         $v0, 0x2B($s2)
    /* BB68 8001B368 270040A2 */  sb         $zero, 0x27($s2)
    /* BB6C 8001B36C E16C0008 */  j          .L8001B384
    /* BB70 8001B370 300A00AD */   sw        $zero, 0xA30($t0)
  .L8001B374:
    /* BB74 8001B374 4800A98F */  lw         $t1, 0x48($sp)
    /* BB78 8001B378 21107400 */  addu       $v0, $v1, $s4
    /* BB7C 8001B37C 300A22AD */  sw         $v0, 0xA30($t1)
    /* BB80 8001B380 270054A2 */  sb         $s4, 0x27($s2)
  .L8001B384:
    /* BB84 8001B384 7800AA8F */  lw         $t2, 0x78($sp)
    /* BB88 8001B388 00000000 */  nop
    /* BB8C 8001B38C 01004A25 */  addiu      $t2, $t2, 0x1
    /* BB90 8001B390 BC6E0008 */  j          .L8001BAF0
    /* BB94 8001B394 7800AAAF */   sw        $t2, 0x78($sp)
  jlabel .L8001B398
    /* BB98 8001B398 01003126 */  addiu      $s1, $s1, 0x1
    /* BB9C 8001B39C 00003092 */  lbu        $s0, 0x0($s1)
    /* BBA0 8001B3A0 00000000 */  nop
    /* BBA4 8001B3A4 1000022A */  slti       $v0, $s0, 0x10
    /* BBA8 8001B3A8 25004010 */  beqz       $v0, .L8001B440
    /* BBAC 8001B3AC 01003126 */   addiu     $s1, $s1, 0x1
    /* BBB0 8001B3B0 2D004292 */  lbu        $v0, 0x2D($s2)
    /* BBB4 8001B3B4 8000A78F */  lw         $a3, 0x80($sp)
    /* BBB8 8001B3B8 00000000 */  nop
    /* BBBC 8001B3BC 1A004714 */  bne        $v0, $a3, .L8001B428
    /* BBC0 8001B3C0 00000000 */   nop
    /* BBC4 8001B3C4 00002292 */  lbu        $v0, 0x0($s1)
    /* BBC8 8001B3C8 01003126 */  addiu      $s1, $s1, 0x1
    /* BBCC 8001B3CC 00002392 */  lbu        $v1, 0x0($s1)
    /* BBD0 8001B3D0 01003126 */  addiu      $s1, $s1, 0x1
    /* BBD4 8001B3D4 40200200 */  sll        $a0, $v0, 1
    /* BBD8 8001B3D8 21208200 */  addu       $a0, $a0, $v0
    /* BBDC 8001B3DC C0200400 */  sll        $a0, $a0, 3
    /* BBE0 8001B3E0 21208200 */  addu       $a0, $a0, $v0
    /* BBE4 8001B3E4 80200400 */  sll        $a0, $a0, 2
    /* BBE8 8001B3E8 80100300 */  sll        $v0, $v1, 2
    /* BBEC 8001B3EC 21104300 */  addu       $v0, $v0, $v1
    /* BBF0 8001B3F0 40100200 */  sll        $v0, $v0, 1
    /* BBF4 8001B3F4 00002392 */  lbu        $v1, 0x0($s1)
    /* BBF8 8001B3F8 21208200 */  addu       $a0, $a0, $v0
    /* BBFC 8001B3FC 30AA010C */  jal        func_8006A8C0
    /* BC00 8001B400 21208300 */   addu      $a0, $a0, $v1
    /* BC04 8001B404 03004010 */  beqz       $v0, .L8001B414
    /* BC08 8001B408 21204000 */   addu      $a0, $v0, $zero
    /* BC0C 8001B40C 83AA010C */  jal        func_8006AA0C
    /* BC10 8001B410 1E000526 */   addiu     $a1, $s0, 0x1E
  .L8001B414:
    /* BC14 8001B414 2D004292 */  lbu        $v0, 0x2D($s2)
    /* BC18 8001B418 00000000 */  nop
    /* BC1C 8001B41C 01004224 */  addiu      $v0, $v0, 0x1
    /* BC20 8001B420 0B6D0008 */  j          .L8001B42C
    /* BC24 8001B424 2D0042A2 */   sb        $v0, 0x2D($s2)
  .L8001B428:
    /* BC28 8001B428 02003126 */  addiu      $s1, $s1, 0x2
  .L8001B42C:
    /* BC2C 8001B42C 8000A88F */  lw         $t0, 0x80($sp)
    /* BC30 8001B430 00000000 */  nop
    /* BC34 8001B434 01000825 */  addiu      $t0, $t0, 0x1
    /* BC38 8001B438 BC6E0008 */  j          .L8001BAF0
    /* BC3C 8001B43C 8000A8AF */   sw        $t0, 0x80($sp)
  .L8001B440:
    /* BC40 8001B440 2000022A */  slti       $v0, $s0, 0x20
    /* BC44 8001B444 28004010 */  beqz       $v0, .L8001B4E8
    /* BC48 8001B448 3000022A */   slti      $v0, $s0, 0x30
    /* BC4C 8001B44C 2C004292 */  lbu        $v0, 0x2C($s2)
    /* BC50 8001B450 7C00A98F */  lw         $t1, 0x7C($sp)
    /* BC54 8001B454 00000000 */  nop
    /* BC58 8001B458 1D004914 */  bne        $v0, $t1, .L8001B4D0
    /* BC5C 8001B45C 00000000 */   nop
    /* BC60 8001B460 00002292 */  lbu        $v0, 0x0($s1)
    /* BC64 8001B464 01003126 */  addiu      $s1, $s1, 0x1
    /* BC68 8001B468 00002392 */  lbu        $v1, 0x0($s1)
    /* BC6C 8001B46C 01003126 */  addiu      $s1, $s1, 0x1
    /* BC70 8001B470 40200200 */  sll        $a0, $v0, 1
    /* BC74 8001B474 21208200 */  addu       $a0, $a0, $v0
    /* BC78 8001B478 C0200400 */  sll        $a0, $a0, 3
    /* BC7C 8001B47C 21208200 */  addu       $a0, $a0, $v0
    /* BC80 8001B480 80200400 */  sll        $a0, $a0, 2
    /* BC84 8001B484 80100300 */  sll        $v0, $v1, 2
    /* BC88 8001B488 21104300 */  addu       $v0, $v0, $v1
    /* BC8C 8001B48C 40100200 */  sll        $v0, $v0, 1
    /* BC90 8001B490 21208200 */  addu       $a0, $a0, $v0
    /* BC94 8001B494 F0FF0226 */  addiu      $v0, $s0, -0x10
    /* BC98 8001B498 00002392 */  lbu        $v1, 0x0($s1)
    /* BC9C 8001B49C 80820200 */  sll        $s0, $v0, 10
    /* BCA0 8001B4A0 30AA010C */  jal        func_8006A8C0
    /* BCA4 8001B4A4 21208300 */   addu      $a0, $a0, $v1
    /* BCA8 8001B4A8 04004010 */  beqz       $v0, .L8001B4BC
    /* BCAC 8001B4AC 00000000 */   nop
    /* BCB0 8001B4B0 3800428C */  lw         $v0, 0x38($v0)
    /* BCB4 8001B4B4 00000000 */  nop
    /* BCB8 8001B4B8 420050A4 */  sh         $s0, 0x42($v0)
  .L8001B4BC:
    /* BCBC 8001B4BC 2C004292 */  lbu        $v0, 0x2C($s2)
    /* BCC0 8001B4C0 00000000 */  nop
    /* BCC4 8001B4C4 01004224 */  addiu      $v0, $v0, 0x1
    /* BCC8 8001B4C8 356D0008 */  j          .L8001B4D4
    /* BCCC 8001B4CC 2C0042A2 */   sb        $v0, 0x2C($s2)
  .L8001B4D0:
    /* BCD0 8001B4D0 02003126 */  addiu      $s1, $s1, 0x2
  .L8001B4D4:
    /* BCD4 8001B4D4 7C00AA8F */  lw         $t2, 0x7C($sp)
    /* BCD8 8001B4D8 00000000 */  nop
    /* BCDC 8001B4DC 01004A25 */  addiu      $t2, $t2, 0x1
    /* BCE0 8001B4E0 BC6E0008 */  j          .L8001BAF0
    /* BCE4 8001B4E4 7C00AAAF */   sw        $t2, 0x7C($sp)
  .L8001B4E8:
    /* BCE8 8001B4E8 2D004010 */  beqz       $v0, .L8001B5A0
    /* BCEC 8001B4EC 4000022A */   slti      $v0, $s0, 0x40
    /* BCF0 8001B4F0 2E004292 */  lbu        $v0, 0x2E($s2)
    /* BCF4 8001B4F4 8400A78F */  lw         $a3, 0x84($sp)
    /* BCF8 8001B4F8 00000000 */  nop
    /* BCFC 8001B4FC 22004714 */  bne        $v0, $a3, .L8001B588
    /* BD00 8001B500 00000000 */   nop
    /* BD04 8001B504 1400C28F */  lw         $v0, 0x14($fp)
    /* BD08 8001B508 00000000 */  nop
    /* BD0C 8001B50C 03004010 */  beqz       $v0, .L8001B51C
    /* BD10 8001B510 01000824 */   addiu     $t0, $zero, 0x1
    /* BD14 8001B514 10004810 */  beq        $v0, $t0, .L8001B558
    /* BD18 8001B518 00000000 */   nop
  .L8001B51C:
    /* BD1C 8001B51C 16000424 */  addiu      $a0, $zero, 0x16
    /* BD20 8001B520 3000A627 */  addiu      $a2, $sp, 0x30
    /* BD24 8001B524 4C00A98F */  lw         $t1, 0x4C($sp)
    /* BD28 8001B528 0F000232 */  andi       $v0, $s0, 0xF
    /* BD2C 8001B52C 3000A2AF */  sw         $v0, 0x30($sp)
    /* BD30 8001B530 3400A0AF */  sw         $zero, 0x34($sp)
    /* BD34 8001B534 1F44000C */  jal        Task_Create
    /* BD38 8001B538 D4002525 */   addiu     $a1, $t1, 0xD4
    /* BD3C 8001B53C 1400C28F */  lw         $v0, 0x14($fp)
    /* BD40 8001B540 00000000 */  nop
    /* BD44 8001B544 01004224 */  addiu      $v0, $v0, 0x1
    /* BD48 8001B548 1400C2AF */  sw         $v0, 0x14($fp)
    /* BD4C 8001B54C 01000A24 */  addiu      $t2, $zero, 0x1
    /* BD50 8001B550 636D0008 */  j          .L8001B58C
    /* BD54 8001B554 27004AA2 */   sb        $t2, 0x27($s2)
  .L8001B558:
    /* BD58 8001B558 4C00A78F */  lw         $a3, 0x4C($sp)
    /* BD5C 8001B55C 00000000 */  nop
    /* BD60 8001B560 D400E28C */  lw         $v0, 0xD4($a3)
    /* BD64 8001B564 00000000 */  nop
    /* BD68 8001B568 08004014 */  bnez       $v0, .L8001B58C
    /* BD6C 8001B56C 02003126 */   addiu     $s1, $s1, 0x2
    /* BD70 8001B570 1400C0AF */  sw         $zero, 0x14($fp)
    /* BD74 8001B574 2E004292 */  lbu        $v0, 0x2E($s2)
    /* BD78 8001B578 270040A2 */  sb         $zero, 0x27($s2)
    /* BD7C 8001B57C 01004224 */  addiu      $v0, $v0, 0x1
    /* BD80 8001B580 636D0008 */  j          .L8001B58C
    /* BD84 8001B584 2E0042A2 */   sb        $v0, 0x2E($s2)
  .L8001B588:
    /* BD88 8001B588 FFFF3126 */  addiu      $s1, $s1, -0x1
  .L8001B58C:
    /* BD8C 8001B58C 8400A88F */  lw         $t0, 0x84($sp)
    /* BD90 8001B590 00000000 */  nop
    /* BD94 8001B594 01000825 */  addiu      $t0, $t0, 0x1
    /* BD98 8001B598 BC6E0008 */  j          .L8001BAF0
    /* BD9C 8001B59C 8400A8AF */   sw        $t0, 0x84($sp)
  .L8001B5A0:
    /* BDA0 8001B5A0 04004010 */  beqz       $v0, .L8001B5B4
    /* BDA4 8001B5A4 0F000232 */   andi      $v0, $s0, 0xF
    /* BDA8 8001B5A8 020042A2 */  sb         $v0, 0x2($s2)
    /* BDAC 8001B5AC BC6E0008 */  j          .L8001BAF0
    /* BDB0 8001B5B0 FFFF3126 */   addiu     $s1, $s1, -0x1
  .L8001B5B4:
    /* BDB4 8001B5B4 2F004392 */  lbu        $v1, 0x2F($s2)
    /* BDB8 8001B5B8 8800A293 */  lbu        $v0, 0x88($sp)
    /* BDBC 8001B5BC 00000000 */  nop
    /* BDC0 8001B5C0 13006214 */  bne        $v1, $v0, .L8001B610
    /* BDC4 8001B5C4 0F001032 */   andi      $s0, $s0, 0xF
    /* BDC8 8001B5C8 07000224 */  addiu      $v0, $zero, 0x7
    /* BDCC 8001B5CC 07000212 */  beq        $s0, $v0, .L8001B5EC
    /* BDD0 8001B5D0 0480033C */   lui       $v1, %hi(D_8004142C)
    /* BDD4 8001B5D4 2C146324 */  addiu      $v1, $v1, %lo(D_8004142C)
    /* BDD8 8001B5D8 40101000 */  sll        $v0, $s0, 1
    /* BDDC 8001B5DC 21104300 */  addu       $v0, $v0, $v1
    /* BDE0 8001B5E0 00004484 */  lh         $a0, 0x0($v0)
    /* BDE4 8001B5E4 A369000C */  jal        Snd_PlayById
    /* BDE8 8001B5E8 21280000 */   addu      $a1, $zero, $zero
  .L8001B5EC:
    /* BDEC 8001B5EC 2F004292 */  lbu        $v0, 0x2F($s2)
    /* BDF0 8001B5F0 00000000 */  nop
    /* BDF4 8001B5F4 01004224 */  addiu      $v0, $v0, 0x1
    /* BDF8 8001B5F8 2F0042A2 */  sb         $v0, 0x2F($s2)
    /* BDFC 8001B5FC 04000224 */  addiu      $v0, $zero, 0x4
    /* BE00 8001B600 03000216 */  bne        $s0, $v0, .L8001B610
    /* BE04 8001B604 00000000 */   nop
    /* BE08 8001B608 218F010C */  jal        func_80063C84
    /* BE0C 8001B60C 00000000 */   nop
  .L8001B610:
    /* BE10 8001B610 8800A993 */  lbu        $t1, 0x88($sp)
    /* BE14 8001B614 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* BE18 8001B618 01002925 */  addiu      $t1, $t1, 0x1
    /* BE1C 8001B61C BC6E0008 */  j          .L8001BAF0
    /* BE20 8001B620 8800A9A3 */   sb        $t1, 0x88($sp)
  jlabel .L8001B624
    /* BE24 8001B624 01001424 */  addiu      $s4, $zero, 0x1
    /* BE28 8001B628 1400C28F */  lw         $v0, 0x14($fp)
    /* BE2C 8001B62C 00000000 */  nop
    /* BE30 8001B630 03004010 */  beqz       $v0, .L8001B640
    /* BE34 8001B634 21883402 */   addu      $s1, $s1, $s4
    /* BE38 8001B638 05005410 */  beq        $v0, $s4, .L8001B650
    /* BE3C 8001B63C 00000000 */   nop
  .L8001B640:
    /* BE40 8001B640 3C71000C */  jal        Gfx_FadeOutToBlack
    /* BE44 8001B644 0A000424 */   addiu     $a0, $zero, 0xA
    /* BE48 8001B648 5945000C */  jal        Task_NextState1
    /* BE4C 8001B64C 2120C003 */   addu      $a0, $fp, $zero
  .L8001B650:
    /* BE50 8001B650 1800C28F */  lw         $v0, 0x18($fp)
    /* BE54 8001B654 00000000 */  nop
    /* BE58 8001B658 01004224 */  addiu      $v0, $v0, 0x1
    /* BE5C 8001B65C 1800C2AF */  sw         $v0, 0x18($fp)
    /* BE60 8001B660 19004228 */  slti       $v0, $v0, 0x19
    /* BE64 8001B664 22014014 */  bnez       $v0, .L8001BAF0
    /* BE68 8001B668 FC000224 */   addiu     $v0, $zero, 0xFC
    /* BE6C 8001B66C 00002392 */  lbu        $v1, 0x0($s1)
    /* BE70 8001B670 00000000 */  nop
    /* BE74 8001B674 05006214 */  bne        $v1, $v0, .L8001B68C
    /* BE78 8001B678 FD000224 */   addiu     $v0, $zero, 0xFD
    /* BE7C 8001B67C 05060224 */  addiu      $v0, $zero, 0x605
    /* BE80 8001B680 06800A3C */  lui        $t2, %hi(D_8005F770)
    /* BE84 8001B684 BB6D0008 */  j          .L8001B6EC
    /* BE88 8001B688 70F74A25 */   addiu     $t2, $t2, %lo(D_8005F770)
  .L8001B68C:
    /* BE8C 8001B68C 06006214 */  bne        $v1, $v0, .L8001B6A8
    /* BE90 8001B690 FE000224 */   addiu     $v0, $zero, 0xFE
    /* BE94 8001B694 00050224 */  addiu      $v0, $zero, 0x500
    /* BE98 8001B698 0680073C */  lui        $a3, %hi(D_8005F770)
    /* BE9C 8001B69C 70F7E724 */  addiu      $a3, $a3, %lo(D_8005F770)
    /* BEA0 8001B6A0 BC6D0008 */  j          .L8001B6F0
    /* BEA4 8001B6A4 1C00E2AC */   sw        $v0, 0x1C($a3)
  .L8001B6A8:
    /* BEA8 8001B6A8 06006214 */  bne        $v1, $v0, .L8001B6C4
    /* BEAC 8001B6AC FF000224 */   addiu     $v0, $zero, 0xFF
    /* BEB0 8001B6B0 04040224 */  addiu      $v0, $zero, 0x404
    /* BEB4 8001B6B4 0680083C */  lui        $t0, %hi(D_8005F770)
    /* BEB8 8001B6B8 70F70825 */  addiu      $t0, $t0, %lo(D_8005F770)
    /* BEBC 8001B6BC BC6D0008 */  j          .L8001B6F0
    /* BEC0 8001B6C0 1C0002AD */   sw        $v0, 0x1C($t0)
  .L8001B6C4:
    /* BEC4 8001B6C4 06006214 */  bne        $v1, $v0, .L8001B6E0
    /* BEC8 8001B6C8 06800A3C */   lui       $t2, %hi(D_8005F770)
    /* BECC 8001B6CC 05040224 */  addiu      $v0, $zero, 0x405
    /* BED0 8001B6D0 0680093C */  lui        $t1, %hi(D_8005F770)
    /* BED4 8001B6D4 70F72925 */  addiu      $t1, $t1, %lo(D_8005F770)
    /* BED8 8001B6D8 BC6D0008 */  j          .L8001B6F0
    /* BEDC 8001B6DC 1C0022AD */   sw        $v0, 0x1C($t1)
  .L8001B6E0:
    /* BEE0 8001B6E0 00002292 */  lbu        $v0, 0x0($s1)
    /* BEE4 8001B6E4 70F74A25 */  addiu      $t2, $t2, %lo(D_8005F770)
    /* BEE8 8001B6E8 00034224 */  addiu      $v0, $v0, 0x300
  .L8001B6EC:
    /* BEEC 8001B6EC 1C0042AD */  sw         $v0, 0x1C($t2)
  .L8001B6F0:
    /* BEF0 8001B6F0 01003126 */  addiu      $s1, $s1, 0x1
    /* BEF4 8001B6F4 0680073C */  lui        $a3, %hi(D_8005F770)
    /* BEF8 8001B6F8 00002292 */  lbu        $v0, 0x0($s1)
    /* BEFC 8001B6FC 70F7E724 */  addiu      $a3, $a3, %lo(D_8005F770)
    /* BF00 8001B700 BC6E0008 */  j          .L8001BAF0
    /* BF04 8001B704 2400E2AC */   sw        $v0, 0x24($a3)
  jlabel .L8001B708
    /* BF08 8001B708 01003126 */  addiu      $s1, $s1, 0x1
    /* BF0C 8001B70C 00002292 */  lbu        $v0, 0x0($s1)
    /* BF10 8001B710 01003126 */  addiu      $s1, $s1, 0x1
    /* BF14 8001B714 00002392 */  lbu        $v1, 0x0($s1)
    /* BF18 8001B718 01003126 */  addiu      $s1, $s1, 0x1
    /* BF1C 8001B71C 01002426 */  addiu      $a0, $s1, 0x1
    /* BF20 8001B720 FFFFB526 */  addiu      $s5, $s5, -0x1
    /* BF24 8001B724 40800200 */  sll        $s0, $v0, 1
    /* BF28 8001B728 21800202 */  addu       $s0, $s0, $v0
    /* BF2C 8001B72C C0801000 */  sll        $s0, $s0, 3
    /* BF30 8001B730 21800202 */  addu       $s0, $s0, $v0
    /* BF34 8001B734 80801000 */  sll        $s0, $s0, 2
    /* BF38 8001B738 80100300 */  sll        $v0, $v1, 2
    /* BF3C 8001B73C 21104300 */  addu       $v0, $v0, $v1
    /* BF40 8001B740 40100200 */  sll        $v0, $v0, 1
    /* BF44 8001B744 00002392 */  lbu        $v1, 0x0($s1)
    /* BF48 8001B748 21800202 */  addu       $s0, $s0, $v0
    /* BF4C 8001B74C 3D6A000C */  jal        Text_PushReturn
    /* BF50 8001B750 21800302 */   addu      $s0, $s0, $v1
    /* BF54 8001B754 1278000C */  jal        Item_GetNameText
    /* BF58 8001B758 21200002 */   addu      $a0, $s0, $zero
    /* BF5C 8001B75C BC6E0008 */  j          .L8001BAF0
    /* BF60 8001B760 FFFF5124 */   addiu     $s1, $v0, -0x1
  jlabel .L8001B764
    /* BF64 8001B764 01003126 */  addiu      $s1, $s1, 0x1
    /* BF68 8001B768 00002292 */  lbu        $v0, 0x0($s1)
    /* BF6C 8001B76C 01003126 */  addiu      $s1, $s1, 0x1
    /* BF70 8001B770 00002392 */  lbu        $v1, 0x0($s1)
    /* BF74 8001B774 01003126 */  addiu      $s1, $s1, 0x1
    /* BF78 8001B778 01002426 */  addiu      $a0, $s1, 0x1
    /* BF7C 8001B77C FFFFB526 */  addiu      $s5, $s5, -0x1
    /* BF80 8001B780 40800200 */  sll        $s0, $v0, 1
    /* BF84 8001B784 21800202 */  addu       $s0, $s0, $v0
    /* BF88 8001B788 C0801000 */  sll        $s0, $s0, 3
    /* BF8C 8001B78C 21800202 */  addu       $s0, $s0, $v0
    /* BF90 8001B790 80801000 */  sll        $s0, $s0, 2
    /* BF94 8001B794 80100300 */  sll        $v0, $v1, 2
    /* BF98 8001B798 21104300 */  addu       $v0, $v0, $v1
    /* BF9C 8001B79C 40100200 */  sll        $v0, $v0, 1
    /* BFA0 8001B7A0 00002392 */  lbu        $v1, 0x0($s1)
    /* BFA4 8001B7A4 21800202 */  addu       $s0, $s0, $v0
    /* BFA8 8001B7A8 3D6A000C */  jal        Text_PushReturn
    /* BFAC 8001B7AC 21800302 */   addu      $s0, $s0, $v1
    /* BFB0 8001B7B0 D679000C */  jal        Digi_GetDefaultName
    /* BFB4 8001B7B4 21200002 */   addu      $a0, $s0, $zero
    /* BFB8 8001B7B8 BC6E0008 */  j          .L8001BAF0
    /* BFBC 8001B7BC FFFF5124 */   addiu     $s1, $v0, -0x1
  jlabel .L8001B7C0
    /* BFC0 8001B7C0 01003126 */  addiu      $s1, $s1, 0x1
    /* BFC4 8001B7C4 00003092 */  lbu        $s0, 0x0($s1)
    /* BFC8 8001B7C8 3D6A000C */  jal        Text_PushReturn
    /* BFCC 8001B7CC 01002426 */   addiu     $a0, $s1, 0x1
    /* BFD0 8001B7D0 FF000332 */  andi       $v1, $s0, 0xFF
    /* BFD4 8001B7D4 05006228 */  slti       $v0, $v1, 0x5
    /* BFD8 8001B7D8 07004010 */  beqz       $v0, .L8001B7F8
    /* BFDC 8001B7DC 00000000 */   nop
    /* BFE0 8001B7E0 10006014 */  bnez       $v1, .L8001B824
    /* BFE4 8001B7E4 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* BFE8 8001B7E8 08006010 */  beqz       $v1, .L8001B80C
    /* BFEC 8001B7EC 0480023C */   lui       $v0, %hi(D_80041440)
    /* BFF0 8001B7F0 0F6E0008 */  j          .L8001B83C
    /* BFF4 8001B7F4 40144224 */   addiu     $v0, $v0, %lo(D_80041440)
  .L8001B7F8:
    /* BFF8 8001B7F8 05000224 */  addiu      $v0, $zero, 0x5
    /* BFFC 8001B7FC 06006210 */  beq        $v1, $v0, .L8001B818
    /* C000 8001B800 0480023C */   lui       $v0, %hi(D_80041440)
    /* C004 8001B804 0E6E0008 */  j          .L8001B838
    /* C008 8001B808 40144224 */   addiu     $v0, $v0, %lo(D_80041440)
  .L8001B80C:
    /* C00C 8001B80C 0680023C */  lui        $v0, %hi(D_8005E633)
    /* C010 8001B810 156E0008 */  j          .L8001B854
    /* C014 8001B814 33E65124 */   addiu     $s1, $v0, %lo(D_8005E633)
  .L8001B818:
    /* C018 8001B818 0680023C */  lui        $v0, %hi(D_8005E6F0)
    /* C01C 8001B81C 156E0008 */  j          .L8001B854
    /* C020 8001B820 F0E65124 */   addiu     $s1, $v0, %lo(D_8005E6F0)
  .L8001B824:
    /* C024 8001B824 80100200 */  sll        $v0, $v0, 2
    /* C028 8001B828 21104202 */  addu       $v0, $s2, $v0
    /* C02C 8001B82C 0C00428C */  lw         $v0, 0xC($v0)
    /* C030 8001B830 156E0008 */  j          .L8001B854
    /* C034 8001B834 FFFF5124 */   addiu     $s1, $v0, -0x1
  .L8001B838:
    /* C038 8001B838 FF000332 */  andi       $v1, $s0, 0xFF
  .L8001B83C:
    /* C03C 8001B83C FAFF6324 */  addiu      $v1, $v1, -0x6
    /* C040 8001B840 80180300 */  sll        $v1, $v1, 2
    /* C044 8001B844 21186200 */  addu       $v1, $v1, $v0
    /* C048 8001B848 0000628C */  lw         $v0, 0x0($v1)
  .L8001B84C:
    /* C04C 8001B84C 00000000 */  nop
    /* C050 8001B850 FFFF5124 */  addiu      $s1, $v0, -0x1
  .L8001B854:
    /* C054 8001B854 BC6E0008 */  j          .L8001BAF0
    /* C058 8001B858 FFFFB526 */   addiu     $s5, $s5, -0x1
  jlabel .L8001B85C
    /* C05C 8001B85C 01003126 */  addiu      $s1, $s1, 0x1
    /* C060 8001B860 00002292 */  lbu        $v0, 0x0($s1)
    /* C064 8001B864 1C6E0008 */  j          .L8001B870
    /* C068 8001B868 F0004424 */   addiu     $a0, $v0, 0xF0
  .L8001B86C:
    /* C06C 8001B86C 00002492 */  lbu        $a0, 0x0($s1)
  .L8001B870:
    /* C070 8001B870 01004292 */  lbu        $v0, 0x1($s2)
    /* C074 8001B874 00000000 */  nop
    /* C078 8001B878 09004010 */  beqz       $v0, .L8001B8A0
    /* C07C 8001B87C 00140400 */   sll       $v0, $a0, 16
    /* C080 8001B880 03140200 */  sra        $v0, $v0, 16
    /* C084 8001B884 88004228 */  slti       $v0, $v0, 0x88
    /* C088 8001B888 04004014 */  bnez       $v0, .L8001B89C
    /* C08C 8001B88C 01000824 */   addiu     $t0, $zero, 0x1
    /* C090 8001B890 78FF8424 */  addiu      $a0, $a0, -0x88
    /* C094 8001B894 286E0008 */  j          .L8001B8A0
    /* C098 8001B898 6000A8AF */   sw        $t0, 0x60($sp)
  .L8001B89C:
    /* C09C 8001B89C 6000A0AF */  sw         $zero, 0x60($sp)
  .L8001B8A0:
    /* C0A0 8001B8A0 00240400 */  sll        $a0, $a0, 16
    /* C0A4 8001B8A4 5C00A78F */  lw         $a3, 0x5C($sp)
    /* C0A8 8001B8A8 03240400 */  sra        $a0, $a0, 16
    /* C0AC 8001B8AC 1A008700 */  div        $zero, $a0, $a3
    /* C0B0 8001B8B0 12200000 */  mflo       $a0
    /* C0B4 8001B8B4 10280000 */  mfhi       $a1
    /* C0B8 8001B8B8 09000224 */  addiu      $v0, $zero, 0x9
    /* C0BC 8001B8BC 0580073C */  lui        $a3, %hi(D_8005074C)
    /* C0C0 8001B8C0 4C07E724 */  addiu      $a3, $a3, %lo(D_8005074C)
    /* C0C4 8001B8C4 0300E888 */  lwl        $t0, 0x3($a3)
    /* C0C8 8001B8C8 0000E898 */  lwr        $t0, 0x0($a3)
    /* C0CC 8001B8CC 00000000 */  nop
    /* C0D0 8001B8D0 E5FF68AA */  swl        $t0, -0x1B($s3)
    /* C0D4 8001B8D4 E2FF68BA */  swr        $t0, -0x1E($s3)
    /* C0D8 8001B8D8 E1FF62A2 */  sb         $v0, -0x1F($s3)
    /* C0DC 8001B8DC 2C000224 */  addiu      $v0, $zero, 0x2C
    /* C0E0 8001B8E0 E5FF62A2 */  sb         $v0, -0x1B($s3)
    /* C0E4 8001B8E4 2800A297 */  lhu        $v0, 0x28($sp)
    /* C0E8 8001B8E8 00000000 */  nop
    /* C0EC 8001B8EC F6FF62A6 */  sh         $v0, -0xA($s3)
    /* C0F0 8001B8F0 E6FF62A6 */  sh         $v0, -0x1A($s3)
    /* C0F4 8001B8F4 1800A397 */  lhu        $v1, 0x18($sp)
    /* C0F8 8001B8F8 00000000 */  nop
    /* C0FC 8001B8FC 21104300 */  addu       $v0, $v0, $v1
    /* C100 8001B900 FEFF62A6 */  sh         $v0, -0x2($s3)
    /* C104 8001B904 EEFF62A6 */  sh         $v0, -0x12($s3)
    /* C108 8001B908 2A00A297 */  lhu        $v0, 0x2A($sp)
    /* C10C 8001B90C 00000000 */  nop
    /* C110 8001B910 F0FF62A6 */  sh         $v0, -0x10($s3)
    /* C114 8001B914 E8FF62A6 */  sh         $v0, -0x18($s3)
    /* C118 8001B918 1A00A397 */  lhu        $v1, 0x1A($sp)
    /* C11C 8001B91C 00000000 */  nop
    /* C120 8001B920 21104300 */  addu       $v0, $v0, $v1
    /* C124 8001B924 000062A6 */  sh         $v0, 0x0($s3)
    /* C128 8001B928 F8FF62A6 */  sh         $v0, -0x8($s3)
    /* C12C 8001B92C 2000A287 */  lh         $v0, 0x20($sp)
    /* C130 8001B930 00000000 */  nop
    /* C134 8001B934 1800A200 */  mult       $a1, $v0
    /* C138 8001B938 6000A78F */  lw         $a3, 0x60($sp)
    /* C13C 8001B93C 00000000 */  nop
    /* C140 8001B940 80100700 */  sll        $v0, $a3, 2
    /* C144 8001B944 1000A527 */  addiu      $a1, $sp, 0x10
    /* C148 8001B948 2128A200 */  addu       $a1, $a1, $v0
    /* C14C 8001B94C 0000A28C */  lw         $v0, 0x0($a1)
    /* C150 8001B950 00000000 */  nop
    /* C154 8001B954 0C004290 */  lbu        $v0, 0xC($v0)
    /* C158 8001B958 12180000 */  mflo       $v1
    /* C15C 8001B95C 21104300 */  addu       $v0, $v0, $v1
    /* C160 8001B960 FAFF62A2 */  sb         $v0, -0x6($s3)
    /* C164 8001B964 EAFF62A2 */  sb         $v0, -0x16($s3)
    /* C168 8001B968 1800A393 */  lbu        $v1, 0x18($sp)
    /* C16C 8001B96C 00000000 */  nop
    /* C170 8001B970 21104300 */  addu       $v0, $v0, $v1
    /* C174 8001B974 020062A2 */  sb         $v0, 0x2($s3)
    /* C178 8001B978 F2FF62A2 */  sb         $v0, -0xE($s3)
    /* C17C 8001B97C 2200A287 */  lh         $v0, 0x22($sp)
    /* C180 8001B980 00000000 */  nop
    /* C184 8001B984 18008200 */  mult       $a0, $v0
    /* C188 8001B988 12200000 */  mflo       $a0
    /* C18C 8001B98C F3FF64A2 */  sb         $a0, -0xD($s3)
    /* C190 8001B990 EBFF64A2 */  sb         $a0, -0x15($s3)
    /* C194 8001B994 1A00A293 */  lbu        $v0, 0x1A($sp)
    /* C198 8001B998 00000000 */  nop
    /* C19C 8001B99C 21208200 */  addu       $a0, $a0, $v0
    /* C1A0 8001B9A0 030064A2 */  sb         $a0, 0x3($s3)
    /* C1A4 8001B9A4 FBFF64A2 */  sb         $a0, -0x5($s3)
    /* C1A8 8001B9A8 0000A48C */  lw         $a0, 0x0($a1)
    /* C1AC 8001B9AC 02004292 */  lbu        $v0, 0x2($s2)
    /* C1B0 8001B9B0 1C008394 */  lhu        $v1, 0x1C($a0)
    /* C1B4 8001B9B4 F8004224 */  addiu      $v0, $v0, 0xF8
    /* C1B8 8001B9B8 21186200 */  addu       $v1, $v1, $v0
    /* C1BC 8001B9BC 1800828C */  lw         $v0, 0x18($a0)
    /* C1C0 8001B9C0 80190300 */  sll        $v1, $v1, 6
    /* C1C4 8001B9C4 03110200 */  sra        $v0, $v0, 4
    /* C1C8 8001B9C8 3F004230 */  andi       $v0, $v0, 0x3F
    /* C1CC 8001B9CC 25186200 */  or         $v1, $v1, $v0
    /* C1D0 8001B9D0 ECFF63A6 */  sh         $v1, -0x14($s3)
    /* C1D4 8001B9D4 0000A28C */  lw         $v0, 0x0($a1)
    /* C1D8 8001B9D8 0680073C */  lui        $a3, %hi(D_8005F770)
    /* C1DC 8001B9DC 10004294 */  lhu        $v0, 0x10($v0)
    /* C1E0 8001B9E0 70F7E724 */  addiu      $a3, $a3, %lo(D_8005F770)
    /* C1E4 8001B9E4 F4FF62A6 */  sh         $v0, -0xC($s3)
    /* C1E8 8001B9E8 1001E38C */  lw         $v1, 0x110($a3)
    /* C1EC 8001B9EC 40010224 */  addiu      $v0, $zero, 0x140
    /* C1F0 8001B9F0 0D006214 */  bne        $v1, $v0, .L8001BA28
    /* C1F4 8001B9F4 0680083C */   lui       $t0, %hi(D_8005F770)
    /* C1F8 8001B9F8 E6FF6296 */  lhu        $v0, -0x1A($s3)
    /* C1FC 8001B9FC EEFF6396 */  lhu        $v1, -0x12($s3)
    /* C200 8001BA00 40100200 */  sll        $v0, $v0, 1
    /* C204 8001BA04 E6FF62A6 */  sh         $v0, -0x1A($s3)
    /* C208 8001BA08 F6FF6296 */  lhu        $v0, -0xA($s3)
    /* C20C 8001BA0C 40180300 */  sll        $v1, $v1, 1
    /* C210 8001BA10 EEFF63A6 */  sh         $v1, -0x12($s3)
    /* C214 8001BA14 FEFF6396 */  lhu        $v1, -0x2($s3)
    /* C218 8001BA18 40100200 */  sll        $v0, $v0, 1
    /* C21C 8001BA1C 40180300 */  sll        $v1, $v1, 1
    /* C220 8001BA20 F6FF62A6 */  sh         $v0, -0xA($s3)
    /* C224 8001BA24 FEFF63A6 */  sh         $v1, -0x2($s3)
  .L8001BA28:
    /* C228 8001BA28 70F70825 */  addiu      $t0, $t0, %lo(D_8005F770)
    /* C22C 8001BA2C 1401038D */  lw         $v1, 0x114($t0)
    /* C230 8001BA30 F0000224 */  addiu      $v0, $zero, 0xF0
    /* C234 8001BA34 0D006214 */  bne        $v1, $v0, .L8001BA6C
    /* C238 8001BA38 FF00043C */   lui       $a0, (0xFFFFFF >> 16)
    /* C23C 8001BA3C E8FF6296 */  lhu        $v0, -0x18($s3)
    /* C240 8001BA40 F0FF6396 */  lhu        $v1, -0x10($s3)
    /* C244 8001BA44 40100200 */  sll        $v0, $v0, 1
    /* C248 8001BA48 E8FF62A6 */  sh         $v0, -0x18($s3)
    /* C24C 8001BA4C F8FF6296 */  lhu        $v0, -0x8($s3)
    /* C250 8001BA50 40180300 */  sll        $v1, $v1, 1
    /* C254 8001BA54 F0FF63A6 */  sh         $v1, -0x10($s3)
    /* C258 8001BA58 00006396 */  lhu        $v1, 0x0($s3)
    /* C25C 8001BA5C 40100200 */  sll        $v0, $v0, 1
    /* C260 8001BA60 40180300 */  sll        $v1, $v1, 1
    /* C264 8001BA64 F8FF62A6 */  sh         $v0, -0x8($s3)
    /* C268 8001BA68 000063A6 */  sh         $v1, 0x0($s3)
  .L8001BA6C:
    /* C26C 8001BA6C FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* C270 8001BA70 00FF053C */  lui        $a1, (0xFF000000 >> 16)
    /* C274 8001BA74 28007326 */  addiu      $s3, $s3, 0x28
    /* C278 8001BA78 5400A98F */  lw         $t1, 0x54($sp)
    /* C27C 8001BA7C 5800AA8F */  lw         $t2, 0x58($sp)
    /* C280 8001BA80 0000228D */  lw         $v0, 0x0($t1)
    /* C284 8001BA84 0000438D */  lw         $v1, 0x0($t2)
    /* C288 8001BA88 24104500 */  and        $v0, $v0, $a1
    /* C28C 8001BA8C 24186400 */  and        $v1, $v1, $a0
    /* C290 8001BA90 25104300 */  or         $v0, $v0, $v1
    /* C294 8001BA94 000022AD */  sw         $v0, 0x0($t1)
    /* C298 8001BA98 0000428D */  lw         $v0, 0x0($t2)
    /* C29C 8001BA9C 24202401 */  and        $a0, $t1, $a0
    /* C2A0 8001BAA0 24104500 */  and        $v0, $v0, $a1
    /* C2A4 8001BAA4 25104400 */  or         $v0, $v0, $a0
    /* C2A8 8001BAA8 000042AD */  sw         $v0, 0x0($t2)
    /* C2AC 8001BAAC 03004392 */  lbu        $v1, 0x3($s2)
    /* C2B0 8001BAB0 2800A297 */  lhu        $v0, 0x28($sp)
    /* C2B4 8001BAB4 9000A78F */  lw         $a3, 0x90($sp)
    /* C2B8 8001BAB8 28002925 */  addiu      $t1, $t1, 0x28
    /* C2BC 8001BABC 5400A9AF */  sw         $t1, 0x54($sp)
    /* C2C0 8001BAC0 21104300 */  addu       $v0, $v0, $v1
    /* C2C4 8001BAC4 0A00E014 */  bnez       $a3, .L8001BAF0
    /* C2C8 8001BAC8 2800A2A7 */   sh        $v0, 0x28($sp)
    /* C2CC 8001BACC 22004392 */  lbu        $v1, 0x22($s2)
    /* C2D0 8001BAD0 0100A226 */  addiu      $v0, $s5, 0x1
    /* C2D4 8001BAD4 2A104300 */  slt        $v0, $v0, $v1
    /* C2D8 8001BAD8 05004014 */  bnez       $v0, .L8001BAF0
    /* C2DC 8001BADC 00000000 */   nop
    /* C2E0 8001BAE0 01000824 */  addiu      $t0, $zero, 0x1
    /* C2E4 8001BAE4 21106800 */  addu       $v0, $v1, $t0
    /* C2E8 8001BAE8 9000A8AF */  sw         $t0, 0x90($sp)
  .L8001BAEC:
    /* C2EC 8001BAEC 220042A2 */  sb         $v0, 0x22($s2)
  .L8001BAF0:
    /* C2F0 8001BAF0 0A008016 */  bnez       $s4, .L8001BB1C
    /* C2F4 8001BAF4 01003126 */   addiu     $s1, $s1, 0x1
    /* C2F8 8001BAF8 06004286 */  lh         $v0, 0x6($s2)
    /* C2FC 8001BAFC 00000000 */  nop
    /* C300 8001BB00 30FC4010 */  beqz       $v0, .L8001ABC4
    /* C304 8001BB04 00000000 */   nop
    /* C308 8001BB08 22004292 */  lbu        $v0, 0x22($s2)
    /* C30C 8001BB0C 0100B526 */  addiu      $s5, $s5, 0x1
    /* C310 8001BB10 2A10A202 */  slt        $v0, $s5, $v0
    /* C314 8001BB14 2BFC4014 */  bnez       $v0, .L8001ABC4
    /* C318 8001BB18 00000000 */   nop
  .L8001BB1C:
    /* C31C 8001BB1C 3400D626 */  addiu      $s6, $s6, 0x34
    /* C320 8001BB20 9C00A98F */  lw         $t1, 0x9C($sp)
    /* C324 8001BB24 A000AA8F */  lw         $t2, 0xA0($sp)
    /* C328 8001BB28 5000A78F */  lw         $a3, 0x50($sp)
    /* C32C 8001BB2C 04002925 */  addiu      $t1, $t1, 0x4
    /* C330 8001BB30 04004A25 */  addiu      $t2, $t2, 0x4
    /* C334 8001BB34 0100E724 */  addiu      $a3, $a3, 0x1
    /* C338 8001BB38 3200E228 */  slti       $v0, $a3, 0x32
    /* C33C 8001BB3C 9C00A9AF */  sw         $t1, 0x9C($sp)
    /* C340 8001BB40 A000AAAF */  sw         $t2, 0xA0($sp)
    /* C344 8001BB44 BBFB4014 */  bnez       $v0, .L8001AA34
    /* C348 8001BB48 5000A7AF */   sw        $a3, 0x50($sp)
    /* C34C 8001BB4C 5400A88F */  lw         $t0, 0x54($sp)
    /* C350 8001BB50 CC00BF8F */  lw         $ra, 0xCC($sp)
    /* C354 8001BB54 C800BE8F */  lw         $fp, 0xC8($sp)
    /* C358 8001BB58 C400B78F */  lw         $s7, 0xC4($sp)
    /* C35C 8001BB5C C000B68F */  lw         $s6, 0xC0($sp)
    /* C360 8001BB60 BC00B58F */  lw         $s5, 0xBC($sp)
    /* C364 8001BB64 B800B48F */  lw         $s4, 0xB8($sp)
    /* C368 8001BB68 B400B38F */  lw         $s3, 0xB4($sp)
    /* C36C 8001BB6C B000B28F */  lw         $s2, 0xB0($sp)
    /* C370 8001BB70 AC00B18F */  lw         $s1, 0xAC($sp)
    /* C374 8001BB74 A800B08F */  lw         $s0, 0xA8($sp)
    /* C378 8001BB78 0680023C */  lui        $v0, %hi(D_8005F79C)
    /* C37C 8001BB7C 9CF748AC */  sw         $t0, %lo(D_8005F79C)($v0)
    /* C380 8001BB80 0800E003 */  jr         $ra
    /* C384 8001BB84 D000BD27 */   addiu     $sp, $sp, 0xD0
endlabel Text_UpdateAllBoxes
