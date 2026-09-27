nonmatching GsSetRefView2, 0x604

glabel GsSetRefView2
    /* 1C964 8002C164 48FFBD27 */  addiu      $sp, $sp, -0xB8
    /* 1C968 8002C168 A800B2AF */  sw         $s2, 0xA8($sp)
    /* 1C96C 8002C16C 21908000 */  addu       $s2, $a0, $zero
    /* 1C970 8002C170 0680043C */  lui        $a0, %hi(D_80061A08)
    /* 1C974 8002C174 081A8424 */  addiu      $a0, $a0, %lo(D_80061A08)
    /* 1C978 8002C178 B000BFAF */  sw         $ra, 0xB0($sp)
    /* 1C97C 8002C17C AC00B3AF */  sw         $s3, 0xAC($sp)
    /* 1C980 8002C180 A400B1AF */  sw         $s1, 0xA4($sp)
    /* 1C984 8002C184 A000B0AF */  sw         $s0, 0xA0($sp)
    /* 1C988 8002C188 0680063C */  lui        $a2, %hi(D_80061A48)
    /* 1C98C 8002C18C 481AC624 */  addiu      $a2, $a2, %lo(D_80061A48)
    /* 1C990 8002C190 0000C28C */  lw         $v0, 0x0($a2)
    /* 1C994 8002C194 0400C38C */  lw         $v1, 0x4($a2)
    /* 1C998 8002C198 0800C58C */  lw         $a1, 0x8($a2)
    /* 1C99C 8002C19C 000082AC */  sw         $v0, 0x0($a0)
    /* 1C9A0 8002C1A0 040083AC */  sw         $v1, 0x4($a0)
    /* 1C9A4 8002C1A4 080085AC */  sw         $a1, 0x8($a0)
    /* 1C9A8 8002C1A8 0C00C28C */  lw         $v0, 0xC($a2)
    /* 1C9AC 8002C1AC 1000C38C */  lw         $v1, 0x10($a2)
    /* 1C9B0 8002C1B0 1400C58C */  lw         $a1, 0x14($a2)
    /* 1C9B4 8002C1B4 0C0082AC */  sw         $v0, 0xC($a0)
    /* 1C9B8 8002C1B8 100083AC */  sw         $v1, 0x10($a0)
    /* 1C9BC 8002C1BC 140085AC */  sw         $a1, 0x14($a0)
    /* 1C9C0 8002C1C0 1800C28C */  lw         $v0, 0x18($a2)
    /* 1C9C4 8002C1C4 1C00C38C */  lw         $v1, 0x1C($a2)
    /* 1C9C8 8002C1C8 180082AC */  sw         $v0, 0x18($a0)
    /* 1C9CC 8002C1CC 1C0083AC */  sw         $v1, 0x1C($a0)
    /* 1C9D0 8002C1D0 1800458E */  lw         $a1, 0x18($s2)
    /* 1C9D4 8002C1D4 DDB1000C */  jal        func_8002C774
    /* 1C9D8 8002C1D8 23280500 */   negu      $a1, $a1
    /* 1C9DC 8002C1DC 0C00428E */  lw         $v0, 0xC($s2)
    /* 1C9E0 8002C1E0 0000438E */  lw         $v1, 0x0($s2)
    /* 1C9E4 8002C1E4 00000000 */  nop
    /* 1C9E8 8002C1E8 23104300 */  subu       $v0, $v0, $v1
    /* 1C9EC 8002C1EC 18004200 */  mult       $v0, $v0
    /* 1C9F0 8002C1F0 1000468E */  lw         $a2, 0x10($s2)
    /* 1C9F4 8002C1F4 0400458E */  lw         $a1, 0x4($s2)
    /* 1C9F8 8002C1F8 12380000 */  mflo       $a3
    /* 1C9FC 8002C1FC 2310C500 */  subu       $v0, $a2, $a1
    /* 1CA00 8002C200 00000000 */  nop
    /* 1CA04 8002C204 18004200 */  mult       $v0, $v0
    /* 1CA08 8002C208 0800438E */  lw         $v1, 0x8($s2)
    /* 1CA0C 8002C20C 1400428E */  lw         $v0, 0x14($s2)
    /* 1CA10 8002C210 12200000 */  mflo       $a0
    /* 1CA14 8002C214 23104300 */  subu       $v0, $v0, $v1
    /* 1CA18 8002C218 00000000 */  nop
    /* 1CA1C 8002C21C 18004200 */  mult       $v0, $v0
    /* 1CA20 8002C220 2110E400 */  addu       $v0, $a3, $a0
    /* 1CA24 8002C224 12180000 */  mflo       $v1
    /* 1CA28 8002C228 21804300 */  addu       $s0, $v0, $v1
    /* 1CA2C 8002C22C 47010012 */  beqz       $s0, .L8002C74C
    /* 1CA30 8002C230 01000224 */   addiu     $v0, $zero, 0x1
    /* 1CA34 8002C234 2310A600 */  subu       $v0, $a1, $a2
    /* 1CA38 8002C238 18004200 */  mult       $v0, $v0
    /* 1CA3C 8002C23C 12880000 */  mflo       $s1
    /* 1CA40 8002C240 EDB6000C */  jal        Gte_CountLeadingZeros
    /* 1CA44 8002C244 21202002 */   addu      $a0, $s1, $zero
    /* 1CA48 8002C248 0C000424 */  addiu      $a0, $zero, 0xC
    /* 1CA4C 8002C24C 23288200 */  subu       $a1, $a0, $v0
    /* 1CA50 8002C250 1600A104 */  bgez       $a1, .L8002C2AC
    /* 1CA54 8002C254 00000000 */   nop
    /* 1CA58 8002C258 B9B3000C */  jal        SquareRoot0
    /* 1CA5C 8002C25C 21200002 */   addu      $a0, $s0, $zero
    /* 1CA60 8002C260 0400438E */  lw         $v1, 0x4($s2)
    /* 1CA64 8002C264 1000448E */  lw         $a0, 0x10($s2)
    /* 1CA68 8002C268 00000000 */  nop
    /* 1CA6C 8002C26C 23186400 */  subu       $v1, $v1, $a0
    /* 1CA70 8002C270 001B0300 */  sll        $v1, $v1, 12
    /* 1CA74 8002C274 23180300 */  negu       $v1, $v1
    /* 1CA78 8002C278 1A006200 */  div        $zero, $v1, $v0
    /* 1CA7C 8002C27C 02004014 */  bnez       $v0, .L8002C288
    /* 1CA80 8002C280 00000000 */   nop
    /* 1CA84 8002C284 0D000700 */  break      7
  .L8002C288:
    /* 1CA88 8002C288 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1CA8C 8002C28C 04004114 */  bne        $v0, $at, .L8002C2A0
    /* 1CA90 8002C290 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1CA94 8002C294 02006114 */  bne        $v1, $at, .L8002C2A0
    /* 1CA98 8002C298 00000000 */   nop
    /* 1CA9C 8002C29C 0D000600 */  break      6
  .L8002C2A0:
    /* 1CAA0 8002C2A0 12180000 */  mflo       $v1
    /* 1CAA4 8002C2A4 C6B00008 */  j          .L8002C318
    /* 1CAA8 8002C2A8 21986000 */   addu      $s3, $v1, $zero
  .L8002C2AC:
    /* 1CAAC 8002C2AC 0400428E */  lw         $v0, 0x4($s2)
    /* 1CAB0 8002C2B0 1000438E */  lw         $v1, 0x10($s2)
    /* 1CAB4 8002C2B4 00000000 */  nop
    /* 1CAB8 8002C2B8 23104300 */  subu       $v0, $v0, $v1
    /* 1CABC 8002C2BC 0C004004 */  bltz       $v0, .L8002C2F0
    /* 1CAC0 8002C2C0 0610B000 */   srlv      $v0, $s0, $a1
    /* 1CAC4 8002C2C4 23208500 */  subu       $a0, $a0, $a1
    /* 1CAC8 8002C2C8 04209100 */  sllv       $a0, $s1, $a0
    /* 1CACC 8002C2CC 1B008200 */  divu       $zero, $a0, $v0
    /* 1CAD0 8002C2D0 02004014 */  bnez       $v0, .L8002C2DC
    /* 1CAD4 8002C2D4 00000000 */   nop
    /* 1CAD8 8002C2D8 0D000700 */  break      7
  .L8002C2DC:
    /* 1CADC 8002C2DC 12200000 */  mflo       $a0
    /* 1CAE0 8002C2E0 6EB3000C */  jal        func_8002CDB8
    /* 1CAE4 8002C2E4 00000000 */   nop
    /* 1CAE8 8002C2E8 C6B00008 */  j          .L8002C318
    /* 1CAEC 8002C2EC 23980200 */   negu      $s3, $v0
  .L8002C2F0:
    /* 1CAF0 8002C2F0 23208500 */  subu       $a0, $a0, $a1
    /* 1CAF4 8002C2F4 04209100 */  sllv       $a0, $s1, $a0
    /* 1CAF8 8002C2F8 1B008200 */  divu       $zero, $a0, $v0
    /* 1CAFC 8002C2FC 02004014 */  bnez       $v0, .L8002C308
    /* 1CB00 8002C300 00000000 */   nop
    /* 1CB04 8002C304 0D000700 */  break      7
  .L8002C308:
    /* 1CB08 8002C308 12200000 */  mflo       $a0
    /* 1CB0C 8002C30C 6EB3000C */  jal        func_8002CDB8
    /* 1CB10 8002C310 00000000 */   nop
    /* 1CB14 8002C314 21984000 */  addu       $s3, $v0, $zero
  .L8002C318:
    /* 1CB18 8002C318 0C00428E */  lw         $v0, 0xC($s2)
    /* 1CB1C 8002C31C 0000438E */  lw         $v1, 0x0($s2)
    /* 1CB20 8002C320 00000000 */  nop
    /* 1CB24 8002C324 23104300 */  subu       $v0, $v0, $v1
    /* 1CB28 8002C328 18004200 */  mult       $v0, $v0
    /* 1CB2C 8002C32C 1400428E */  lw         $v0, 0x14($s2)
    /* 1CB30 8002C330 0800438E */  lw         $v1, 0x8($s2)
    /* 1CB34 8002C334 12200000 */  mflo       $a0
    /* 1CB38 8002C338 23104300 */  subu       $v0, $v0, $v1
    /* 1CB3C 8002C33C 00000000 */  nop
    /* 1CB40 8002C340 18004200 */  mult       $v0, $v0
    /* 1CB44 8002C344 12180000 */  mflo       $v1
    /* 1CB48 8002C348 21888300 */  addu       $s1, $a0, $v1
    /* 1CB4C 8002C34C EDB6000C */  jal        Gte_CountLeadingZeros
    /* 1CB50 8002C350 21202002 */   addu      $a0, $s1, $zero
    /* 1CB54 8002C354 0C000424 */  addiu      $a0, $zero, 0xC
    /* 1CB58 8002C358 23288200 */  subu       $a1, $a0, $v0
    /* 1CB5C 8002C35C 1400A104 */  bgez       $a1, .L8002C3B0
    /* 1CB60 8002C360 23208500 */   subu      $a0, $a0, $a1
    /* 1CB64 8002C364 B9B3000C */  jal        SquareRoot0
    /* 1CB68 8002C368 21202002 */   addu      $a0, $s1, $zero
    /* 1CB6C 8002C36C 21200002 */  addu       $a0, $s0, $zero
    /* 1CB70 8002C370 B9B3000C */  jal        SquareRoot0
    /* 1CB74 8002C374 21804000 */   addu      $s0, $v0, $zero
    /* 1CB78 8002C378 00831000 */  sll        $s0, $s0, 12
    /* 1CB7C 8002C37C 1A000202 */  div        $zero, $s0, $v0
    /* 1CB80 8002C380 02004014 */  bnez       $v0, .L8002C38C
    /* 1CB84 8002C384 00000000 */   nop
    /* 1CB88 8002C388 0D000700 */  break      7
  .L8002C38C:
    /* 1CB8C 8002C38C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1CB90 8002C390 04004114 */  bne        $v0, $at, .L8002C3A4
    /* 1CB94 8002C394 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1CB98 8002C398 02000116 */  bne        $s0, $at, .L8002C3A4
    /* 1CB9C 8002C39C 00000000 */   nop
    /* 1CBA0 8002C3A0 0D000600 */  break      6
  .L8002C3A4:
    /* 1CBA4 8002C3A4 12800000 */  mflo       $s0
    /* 1CBA8 8002C3A8 F5B00008 */  j          .L8002C3D4
    /* 1CBAC 8002C3AC 21100002 */   addu      $v0, $s0, $zero
  .L8002C3B0:
    /* 1CBB0 8002C3B0 04209100 */  sllv       $a0, $s1, $a0
    /* 1CBB4 8002C3B4 0610B000 */  srlv       $v0, $s0, $a1
    /* 1CBB8 8002C3B8 1B008200 */  divu       $zero, $a0, $v0
    /* 1CBBC 8002C3BC 02004014 */  bnez       $v0, .L8002C3C8
    /* 1CBC0 8002C3C0 00000000 */   nop
    /* 1CBC4 8002C3C4 0D000700 */  break      7
  .L8002C3C8:
    /* 1CBC8 8002C3C8 12200000 */  mflo       $a0
    /* 1CBCC 8002C3CC 6EB3000C */  jal        func_8002CDB8
    /* 1CBD0 8002C3D0 00000000 */   nop
  .L8002C3D4:
    /* 1CBD4 8002C3D4 3000B027 */  addiu      $s0, $sp, 0x30
    /* 1CBD8 8002C3D8 21200002 */  addu       $a0, $s0, $zero
    /* 1CBDC 8002C3DC 002C1300 */  sll        $a1, $s3, 16
    /* 1CBE0 8002C3E0 032C0500 */  sra        $a1, $a1, 16
    /* 1CBE4 8002C3E4 00340200 */  sll        $a2, $v0, 16
    /* 1CBE8 8002C3E8 03340600 */  sra        $a2, $a2, 16
    /* 1CBEC 8002C3EC 31AF000C */  jal        func_8002BCC4
    /* 1CBF0 8002C3F0 78000724 */   addiu     $a3, $zero, 0x78
    /* 1CBF4 8002C3F4 0680043C */  lui        $a0, %hi(D_80061A08)
    /* 1CBF8 8002C3F8 081A8424 */  addiu      $a0, $a0, %lo(D_80061A08)
    /* 1CBFC 8002C3FC 89B4000C */  jal        MulMatrix
    /* 1CC00 8002C400 21280002 */   addu      $a1, $s0, $zero
    /* 1CC04 8002C404 84002012 */  beqz       $s1, .L8002C618
    /* 1CC08 8002C408 00000000 */   nop
    /* 1CC0C 8002C40C 0C00428E */  lw         $v0, 0xC($s2)
    /* 1CC10 8002C410 0000438E */  lw         $v1, 0x0($s2)
    /* 1CC14 8002C414 21802002 */  addu       $s0, $s1, $zero
    /* 1CC18 8002C418 23104300 */  subu       $v0, $v0, $v1
    /* 1CC1C 8002C41C 18004200 */  mult       $v0, $v0
    /* 1CC20 8002C420 12880000 */  mflo       $s1
    /* 1CC24 8002C424 EDB6000C */  jal        Gte_CountLeadingZeros
    /* 1CC28 8002C428 21202002 */   addu      $a0, $s1, $zero
    /* 1CC2C 8002C42C 0C000424 */  addiu      $a0, $zero, 0xC
    /* 1CC30 8002C430 23288200 */  subu       $a1, $a0, $v0
    /* 1CC34 8002C434 1600A104 */  bgez       $a1, .L8002C490
    /* 1CC38 8002C438 00000000 */   nop
    /* 1CC3C 8002C43C B9B3000C */  jal        SquareRoot0
    /* 1CC40 8002C440 21200002 */   addu      $a0, $s0, $zero
    /* 1CC44 8002C444 0C00438E */  lw         $v1, 0xC($s2)
    /* 1CC48 8002C448 0000448E */  lw         $a0, 0x0($s2)
    /* 1CC4C 8002C44C 00000000 */  nop
    /* 1CC50 8002C450 23186400 */  subu       $v1, $v1, $a0
    /* 1CC54 8002C454 001B0300 */  sll        $v1, $v1, 12
    /* 1CC58 8002C458 23180300 */  negu       $v1, $v1
    /* 1CC5C 8002C45C 1A006200 */  div        $zero, $v1, $v0
    /* 1CC60 8002C460 02004014 */  bnez       $v0, .L8002C46C
    /* 1CC64 8002C464 00000000 */   nop
    /* 1CC68 8002C468 0D000700 */  break      7
  .L8002C46C:
    /* 1CC6C 8002C46C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1CC70 8002C470 04004114 */  bne        $v0, $at, .L8002C484
    /* 1CC74 8002C474 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1CC78 8002C478 02006114 */  bne        $v1, $at, .L8002C484
    /* 1CC7C 8002C47C 00000000 */   nop
    /* 1CC80 8002C480 0D000600 */  break      6
  .L8002C484:
    /* 1CC84 8002C484 12180000 */  mflo       $v1
    /* 1CC88 8002C488 3FB10008 */  j          .L8002C4FC
    /* 1CC8C 8002C48C 21986000 */   addu      $s3, $v1, $zero
  .L8002C490:
    /* 1CC90 8002C490 0C00428E */  lw         $v0, 0xC($s2)
    /* 1CC94 8002C494 0000438E */  lw         $v1, 0x0($s2)
    /* 1CC98 8002C498 00000000 */  nop
    /* 1CC9C 8002C49C 23104300 */  subu       $v0, $v0, $v1
    /* 1CCA0 8002C4A0 0C004004 */  bltz       $v0, .L8002C4D4
    /* 1CCA4 8002C4A4 0610B000 */   srlv      $v0, $s0, $a1
    /* 1CCA8 8002C4A8 23208500 */  subu       $a0, $a0, $a1
    /* 1CCAC 8002C4AC 04209100 */  sllv       $a0, $s1, $a0
    /* 1CCB0 8002C4B0 1B008200 */  divu       $zero, $a0, $v0
    /* 1CCB4 8002C4B4 02004014 */  bnez       $v0, .L8002C4C0
    /* 1CCB8 8002C4B8 00000000 */   nop
    /* 1CCBC 8002C4BC 0D000700 */  break      7
  .L8002C4C0:
    /* 1CCC0 8002C4C0 12200000 */  mflo       $a0
    /* 1CCC4 8002C4C4 6EB3000C */  jal        func_8002CDB8
    /* 1CCC8 8002C4C8 00000000 */   nop
    /* 1CCCC 8002C4CC 3FB10008 */  j          .L8002C4FC
    /* 1CCD0 8002C4D0 23980200 */   negu      $s3, $v0
  .L8002C4D4:
    /* 1CCD4 8002C4D4 23208500 */  subu       $a0, $a0, $a1
    /* 1CCD8 8002C4D8 04209100 */  sllv       $a0, $s1, $a0
    /* 1CCDC 8002C4DC 1B008200 */  divu       $zero, $a0, $v0
    /* 1CCE0 8002C4E0 02004014 */  bnez       $v0, .L8002C4EC
    /* 1CCE4 8002C4E4 00000000 */   nop
    /* 1CCE8 8002C4E8 0D000700 */  break      7
  .L8002C4EC:
    /* 1CCEC 8002C4EC 12200000 */  mflo       $a0
    /* 1CCF0 8002C4F0 6EB3000C */  jal        func_8002CDB8
    /* 1CCF4 8002C4F4 00000000 */   nop
    /* 1CCF8 8002C4F8 21984000 */  addu       $s3, $v0, $zero
  .L8002C4FC:
    /* 1CCFC 8002C4FC 1400428E */  lw         $v0, 0x14($s2)
    /* 1CD00 8002C500 0800438E */  lw         $v1, 0x8($s2)
    /* 1CD04 8002C504 00000000 */  nop
    /* 1CD08 8002C508 23104300 */  subu       $v0, $v0, $v1
    /* 1CD0C 8002C50C 18004200 */  mult       $v0, $v0
    /* 1CD10 8002C510 12880000 */  mflo       $s1
    /* 1CD14 8002C514 EDB6000C */  jal        Gte_CountLeadingZeros
    /* 1CD18 8002C518 21202002 */   addu      $a0, $s1, $zero
    /* 1CD1C 8002C51C 0C000424 */  addiu      $a0, $zero, 0xC
    /* 1CD20 8002C520 23288200 */  subu       $a1, $a0, $v0
    /* 1CD24 8002C524 1500A104 */  bgez       $a1, .L8002C57C
    /* 1CD28 8002C528 00000000 */   nop
    /* 1CD2C 8002C52C B9B3000C */  jal        SquareRoot0
    /* 1CD30 8002C530 21200002 */   addu      $a0, $s0, $zero
    /* 1CD34 8002C534 1400438E */  lw         $v1, 0x14($s2)
    /* 1CD38 8002C538 0800448E */  lw         $a0, 0x8($s2)
    /* 1CD3C 8002C53C 00000000 */  nop
    /* 1CD40 8002C540 23186400 */  subu       $v1, $v1, $a0
    /* 1CD44 8002C544 001B0300 */  sll        $v1, $v1, 12
    /* 1CD48 8002C548 1A006200 */  div        $zero, $v1, $v0
    /* 1CD4C 8002C54C 02004014 */  bnez       $v0, .L8002C558
    /* 1CD50 8002C550 00000000 */   nop
    /* 1CD54 8002C554 0D000700 */  break      7
  .L8002C558:
    /* 1CD58 8002C558 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 1CD5C 8002C55C 04004114 */  bne        $v0, $at, .L8002C570
    /* 1CD60 8002C560 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 1CD64 8002C564 02006114 */  bne        $v1, $at, .L8002C570
    /* 1CD68 8002C568 00000000 */   nop
    /* 1CD6C 8002C56C 0D000600 */  break      6
  .L8002C570:
    /* 1CD70 8002C570 12180000 */  mflo       $v1
    /* 1CD74 8002C574 7AB10008 */  j          .L8002C5E8
    /* 1CD78 8002C578 21106000 */   addu      $v0, $v1, $zero
  .L8002C57C:
    /* 1CD7C 8002C57C 1400428E */  lw         $v0, 0x14($s2)
    /* 1CD80 8002C580 0800438E */  lw         $v1, 0x8($s2)
    /* 1CD84 8002C584 00000000 */  nop
    /* 1CD88 8002C588 23104300 */  subu       $v0, $v0, $v1
    /* 1CD8C 8002C58C 0C004004 */  bltz       $v0, .L8002C5C0
    /* 1CD90 8002C590 0610B000 */   srlv      $v0, $s0, $a1
    /* 1CD94 8002C594 23208500 */  subu       $a0, $a0, $a1
    /* 1CD98 8002C598 04209100 */  sllv       $a0, $s1, $a0
    /* 1CD9C 8002C59C 1B008200 */  divu       $zero, $a0, $v0
    /* 1CDA0 8002C5A0 02004014 */  bnez       $v0, .L8002C5AC
    /* 1CDA4 8002C5A4 00000000 */   nop
    /* 1CDA8 8002C5A8 0D000700 */  break      7
  .L8002C5AC:
    /* 1CDAC 8002C5AC 12200000 */  mflo       $a0
    /* 1CDB0 8002C5B0 6EB3000C */  jal        func_8002CDB8
    /* 1CDB4 8002C5B4 00000000 */   nop
    /* 1CDB8 8002C5B8 7BB10008 */  j          .L8002C5EC
    /* 1CDBC 8002C5BC 3000B027 */   addiu     $s0, $sp, 0x30
  .L8002C5C0:
    /* 1CDC0 8002C5C0 23208500 */  subu       $a0, $a0, $a1
    /* 1CDC4 8002C5C4 04209100 */  sllv       $a0, $s1, $a0
    /* 1CDC8 8002C5C8 1B008200 */  divu       $zero, $a0, $v0
    /* 1CDCC 8002C5CC 02004014 */  bnez       $v0, .L8002C5D8
    /* 1CDD0 8002C5D0 00000000 */   nop
    /* 1CDD4 8002C5D4 0D000700 */  break      7
  .L8002C5D8:
    /* 1CDD8 8002C5D8 12200000 */  mflo       $a0
    /* 1CDDC 8002C5DC 6EB3000C */  jal        func_8002CDB8
    /* 1CDE0 8002C5E0 00000000 */   nop
    /* 1CDE4 8002C5E4 23100200 */  negu       $v0, $v0
  .L8002C5E8:
    /* 1CDE8 8002C5E8 3000B027 */  addiu      $s0, $sp, 0x30
  .L8002C5EC:
    /* 1CDEC 8002C5EC 21200002 */  addu       $a0, $s0, $zero
    /* 1CDF0 8002C5F0 002C1300 */  sll        $a1, $s3, 16
    /* 1CDF4 8002C5F4 032C0500 */  sra        $a1, $a1, 16
    /* 1CDF8 8002C5F8 00340200 */  sll        $a2, $v0, 16
    /* 1CDFC 8002C5FC 03340600 */  sra        $a2, $a2, 16
    /* 1CE00 8002C600 31AF000C */  jal        func_8002BCC4
    /* 1CE04 8002C604 79000724 */   addiu     $a3, $zero, 0x79
    /* 1CE08 8002C608 0680043C */  lui        $a0, %hi(D_80061A08)
    /* 1CE0C 8002C60C 081A8424 */  addiu      $a0, $a0, %lo(D_80061A08)
    /* 1CE10 8002C610 89B4000C */  jal        MulMatrix
    /* 1CE14 8002C614 21280002 */   addu      $a1, $s0, $zero
  .L8002C618:
    /* 1CE18 8002C618 0680113C */  lui        $s1, %hi(D_80061A08)
    /* 1CE1C 8002C61C 081A3126 */  addiu      $s1, $s1, %lo(D_80061A08)
    /* 1CE20 8002C620 21202002 */  addu       $a0, $s1, $zero
    /* 1CE24 8002C624 0000428E */  lw         $v0, 0x0($s2)
    /* 1CE28 8002C628 9000B327 */  addiu      $s3, $sp, 0x90
    /* 1CE2C 8002C62C 23100200 */  negu       $v0, $v0
    /* 1CE30 8002C630 9000A2AF */  sw         $v0, 0x90($sp)
    /* 1CE34 8002C634 0400428E */  lw         $v0, 0x4($s2)
    /* 1CE38 8002C638 21286002 */  addu       $a1, $s3, $zero
    /* 1CE3C 8002C63C 23100200 */  negu       $v0, $v0
    /* 1CE40 8002C640 9400A2AF */  sw         $v0, 0x94($sp)
    /* 1CE44 8002C644 0800428E */  lw         $v0, 0x8($s2)
    /* 1CE48 8002C648 14002626 */  addiu      $a2, $s1, 0x14
    /* 1CE4C 8002C64C 23100200 */  negu       $v0, $v0
    /* 1CE50 8002C650 DDB3000C */  jal        ApplyMatrixLV
    /* 1CE54 8002C654 9800A2AF */   sw        $v0, 0x98($sp)
    /* 1CE58 8002C658 1C00448E */  lw         $a0, 0x1C($s2)
    /* 1CE5C 8002C65C 00000000 */  nop
    /* 1CE60 8002C660 27008010 */  beqz       $a0, .L8002C700
    /* 1CE64 8002C664 3000B027 */   addiu     $s0, $sp, 0x30
    /* 1CE68 8002C668 0DB2000C */  jal        GsGetLw
    /* 1CE6C 8002C66C 21280002 */   addu      $a1, $s0, $zero
    /* 1CE70 8002C670 21200002 */  addu       $a0, $s0, $zero
    /* 1CE74 8002C674 5000B027 */  addiu      $s0, $sp, 0x50
    /* 1CE78 8002C678 C1B5000C */  jal        TransposeMatrix
    /* 1CE7C 8002C67C 21280002 */   addu      $a1, $s0, $zero
    /* 1CE80 8002C680 21200002 */  addu       $a0, $s0, $zero
    /* 1CE84 8002C684 4400A527 */  addiu      $a1, $sp, 0x44
    /* 1CE88 8002C688 DDB3000C */  jal        ApplyMatrixLV
    /* 1CE8C 8002C68C 21306002 */   addu      $a2, $s3, $zero
    /* 1CE90 8002C690 21202002 */  addu       $a0, $s1, $zero
    /* 1CE94 8002C694 21280002 */  addu       $a1, $s0, $zero
    /* 1CE98 8002C698 9000A28F */  lw         $v0, 0x90($sp)
    /* 1CE9C 8002C69C 9800A38F */  lw         $v1, 0x98($sp)
    /* 1CEA0 8002C6A0 23100200 */  negu       $v0, $v0
    /* 1CEA4 8002C6A4 6400A2AF */  sw         $v0, 0x64($sp)
    /* 1CEA8 8002C6A8 9400A28F */  lw         $v0, 0x94($sp)
    /* 1CEAC 8002C6AC 23180300 */  negu       $v1, $v1
    /* 1CEB0 8002C6B0 6C00A3AF */  sw         $v1, 0x6C($sp)
    /* 1CEB4 8002C6B4 23100200 */  negu       $v0, $v0
    /* 1CEB8 8002C6B8 19B0000C */  jal        func_8002C064
    /* 1CEBC 8002C6BC 6800A2AF */   sw        $v0, 0x68($sp)
    /* 1CEC0 8002C6C0 5000A28F */  lw         $v0, 0x50($sp)
    /* 1CEC4 8002C6C4 5400A38F */  lw         $v1, 0x54($sp)
    /* 1CEC8 8002C6C8 5800A48F */  lw         $a0, 0x58($sp)
    /* 1CECC 8002C6CC 5C00A58F */  lw         $a1, 0x5C($sp)
    /* 1CED0 8002C6D0 000022AE */  sw         $v0, 0x0($s1)
    /* 1CED4 8002C6D4 040023AE */  sw         $v1, 0x4($s1)
    /* 1CED8 8002C6D8 080024AE */  sw         $a0, 0x8($s1)
    /* 1CEDC 8002C6DC 0C0025AE */  sw         $a1, 0xC($s1)
    /* 1CEE0 8002C6E0 6000A28F */  lw         $v0, 0x60($sp)
    /* 1CEE4 8002C6E4 6400A38F */  lw         $v1, 0x64($sp)
    /* 1CEE8 8002C6E8 6800A48F */  lw         $a0, 0x68($sp)
    /* 1CEEC 8002C6EC 6C00A58F */  lw         $a1, 0x6C($sp)
    /* 1CEF0 8002C6F0 100022AE */  sw         $v0, 0x10($s1)
    /* 1CEF4 8002C6F4 140023AE */  sw         $v1, 0x14($s1)
    /* 1CEF8 8002C6F8 180024AE */  sw         $a0, 0x18($s1)
    /* 1CEFC 8002C6FC 1C0025AE */  sw         $a1, 0x1C($s1)
  .L8002C700:
    /* 1CF00 8002C700 0680053C */  lui        $a1, %hi(D_800619E8)
    /* 1CF04 8002C704 E819A524 */  addiu      $a1, $a1, %lo(D_800619E8)
    /* 1CF08 8002C708 0000228E */  lw         $v0, 0x0($s1)
    /* 1CF0C 8002C70C 0400238E */  lw         $v1, 0x4($s1)
    /* 1CF10 8002C710 0800248E */  lw         $a0, 0x8($s1)
    /* 1CF14 8002C714 0000A2AC */  sw         $v0, 0x0($a1)
    /* 1CF18 8002C718 0400A3AC */  sw         $v1, 0x4($a1)
    /* 1CF1C 8002C71C 0800A4AC */  sw         $a0, 0x8($a1)
    /* 1CF20 8002C720 0C00228E */  lw         $v0, 0xC($s1)
    /* 1CF24 8002C724 1000238E */  lw         $v1, 0x10($s1)
    /* 1CF28 8002C728 1400248E */  lw         $a0, 0x14($s1)
    /* 1CF2C 8002C72C 0C00A2AC */  sw         $v0, 0xC($a1)
    /* 1CF30 8002C730 1000A3AC */  sw         $v1, 0x10($a1)
    /* 1CF34 8002C734 1400A4AC */  sw         $a0, 0x14($a1)
    /* 1CF38 8002C738 1800228E */  lw         $v0, 0x18($s1)
    /* 1CF3C 8002C73C 1C00238E */  lw         $v1, 0x1C($s1)
    /* 1CF40 8002C740 1800A2AC */  sw         $v0, 0x18($a1)
    /* 1CF44 8002C744 1C00A3AC */  sw         $v1, 0x1C($a1)
    /* 1CF48 8002C748 21100000 */  addu       $v0, $zero, $zero
  .L8002C74C:
    /* 1CF4C 8002C74C B000BF8F */  lw         $ra, 0xB0($sp)
    /* 1CF50 8002C750 AC00B38F */  lw         $s3, 0xAC($sp)
    /* 1CF54 8002C754 A800B28F */  lw         $s2, 0xA8($sp)
    /* 1CF58 8002C758 A400B18F */  lw         $s1, 0xA4($sp)
    /* 1CF5C 8002C75C A000B08F */  lw         $s0, 0xA0($sp)
    /* 1CF60 8002C760 0800E003 */  jr         $ra
    /* 1CF64 8002C764 B800BD27 */   addiu     $sp, $sp, 0xB8
endlabel GsSetRefView2
    /* 1CF68 8002C768 00000000 */  nop
    /* 1CF6C 8002C76C 00000000 */  nop
    /* 1CF70 8002C770 00000000 */  nop
