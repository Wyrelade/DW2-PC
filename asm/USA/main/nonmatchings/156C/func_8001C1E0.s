nonmatching func_8001C1E0, 0x2E8

glabel func_8001C1E0
    /* C9E0 8001C1E0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* C9E4 8001C1E4 2000B2AF */  sw         $s2, 0x20($sp)
    /* C9E8 8001C1E8 21908000 */  addu       $s2, $a0, $zero
    /* C9EC 8001C1EC 1800B0AF */  sw         $s0, 0x18($sp)
    /* C9F0 8001C1F0 2180A000 */  addu       $s0, $a1, $zero
    /* C9F4 8001C1F4 3000B6AF */  sw         $s6, 0x30($sp)
    /* C9F8 8001C1F8 21B00000 */  addu       $s6, $zero, $zero
    /* C9FC 8001C1FC 0680023C */  lui        $v0, %hi(D_8005F770)
    /* CA00 8001C200 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* CA04 8001C204 70F75124 */  addiu      $s1, $v0, %lo(D_8005F770)
    /* CA08 8001C208 C2171200 */  srl        $v0, $s2, 31
    /* CA0C 8001C20C 21104202 */  addu       $v0, $s2, $v0
    /* CA10 8001C210 2400B3AF */  sw         $s3, 0x24($sp)
    /* CA14 8001C214 43980200 */  sra        $s3, $v0, 1
    /* CA18 8001C218 C2171000 */  srl        $v0, $s0, 31
    /* CA1C 8001C21C 21100202 */  addu       $v0, $s0, $v0
    /* CA20 8001C220 2800B4AF */  sw         $s4, 0x28($sp)
    /* CA24 8001C224 43A00200 */  sra        $s4, $v0, 1
    /* CA28 8001C228 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* CA2C 8001C22C 01001524 */  addiu      $s5, $zero, 0x1
    /* CA30 8001C230 3400BFAF */  sw         $ra, 0x34($sp)
    /* CA34 8001C234 100133AE */  sw         $s3, 0x110($s1)
    /* CA38 8001C238 2800D510 */  beq        $a2, $s5, .L8001C2DC
    /* CA3C 8001C23C 140134AE */   sw        $s4, 0x114($s1)
    /* CA40 8001C240 0200C228 */  slti       $v0, $a2, 0x2
    /* CA44 8001C244 04004014 */  bnez       $v0, .L8001C258
    /* CA48 8001C248 30002426 */   addiu     $a0, $s1, 0x30
    /* CA4C 8001C24C 02000224 */  addiu      $v0, $zero, 0x2
    /* CA50 8001C250 4300C210 */  beq        $a2, $v0, .L8001C360
    /* CA54 8001C254 00000000 */   nop
  .L8001C258:
    /* CA58 8001C258 21280000 */  addu       $a1, $zero, $zero
    /* CA5C 8001C25C 21300002 */  addu       $a2, $s0, $zero
    /* CA60 8001C260 21384002 */  addu       $a3, $s2, $zero
    /* CA64 8001C264 7DAA000C */  jal        func_8002A9F4
    /* CA68 8001C268 1000B0AF */   sw        $s0, 0x10($sp)
    /* CA6C 8001C26C 8C002426 */  addiu      $a0, $s1, 0x8C
    /* CA70 8001C270 21280000 */  addu       $a1, $zero, $zero
    /* CA74 8001C274 2130A000 */  addu       $a2, $a1, $zero
    /* CA78 8001C278 21384002 */  addu       $a3, $s2, $zero
    /* CA7C 8001C27C 7DAA000C */  jal        func_8002A9F4
    /* CA80 8001C280 1000B0AF */   sw        $s0, 0x10($sp)
    /* CA84 8001C284 E8002426 */  addiu      $a0, $s1, 0xE8
    /* CA88 8001C288 21280000 */  addu       $a1, $zero, $zero
    /* CA8C 8001C28C 2130A000 */  addu       $a2, $a1, $zero
    /* CA90 8001C290 21384002 */  addu       $a3, $s2, $zero
    /* CA94 8001C294 ADAA000C */  jal        SetDefDispEnv
    /* CA98 8001C298 1000B0AF */   sw        $s0, 0x10($sp)
    /* CA9C 8001C29C FC002426 */  addiu      $a0, $s1, 0xFC
    /* CAA0 8001C2A0 21280000 */  addu       $a1, $zero, $zero
    /* CAA4 8001C2A4 21300002 */  addu       $a2, $s0, $zero
    /* CAA8 8001C2A8 21384002 */  addu       $a3, $s2, $zero
    /* CAAC 8001C2AC ADAA000C */  jal        SetDefDispEnv
    /* CAB0 8001C2B0 1000B0AF */   sw        $s0, 0x10($sp)
    /* CAB4 8001C2B4 21184002 */  addu       $v1, $s2, $zero
    /* CAB8 8001C2B8 21101402 */  addu       $v0, $s0, $s4
    /* CABC 8001C2BC 380033A6 */  sh         $s3, 0x38($s1)
    /* CAC0 8001C2C0 3A0022A6 */  sh         $v0, 0x3A($s1)
    /* CAC4 8001C2C4 940033A6 */  sh         $s3, 0x94($s1)
    /* CAC8 8001C2C8 02004106 */  bgez       $s2, .L8001C2D4
    /* CACC 8001C2CC 960034A6 */   sh        $s4, 0x96($s1)
    /* CAD0 8001C2D0 1F004326 */  addiu      $v1, $s2, 0x1F
  .L8001C2D4:
    /* CAD4 8001C2D4 1E710008 */  j          .L8001C478
    /* CAD8 8001C2D8 43110300 */   sra       $v0, $v1, 5
  .L8001C2DC:
    /* CADC 8001C2DC 30002426 */  addiu      $a0, $s1, 0x30
    /* CAE0 8001C2E0 21280000 */  addu       $a1, $zero, $zero
    /* CAE4 8001C2E4 2130A000 */  addu       $a2, $a1, $zero
    /* CAE8 8001C2E8 21384002 */  addu       $a3, $s2, $zero
    /* CAEC 8001C2EC 7DAA000C */  jal        func_8002A9F4
    /* CAF0 8001C2F0 1000B0AF */   sw        $s0, 0x10($sp)
    /* CAF4 8001C2F4 8C002426 */  addiu      $a0, $s1, 0x8C
    /* CAF8 8001C2F8 21280000 */  addu       $a1, $zero, $zero
    /* CAFC 8001C2FC 2130A000 */  addu       $a2, $a1, $zero
    /* CB00 8001C300 21384002 */  addu       $a3, $s2, $zero
    /* CB04 8001C304 7DAA000C */  jal        func_8002A9F4
    /* CB08 8001C308 1000B0AF */   sw        $s0, 0x10($sp)
    /* CB0C 8001C30C E8002426 */  addiu      $a0, $s1, 0xE8
    /* CB10 8001C310 21280000 */  addu       $a1, $zero, $zero
    /* CB14 8001C314 2130A000 */  addu       $a2, $a1, $zero
    /* CB18 8001C318 21384002 */  addu       $a3, $s2, $zero
    /* CB1C 8001C31C ADAA000C */  jal        SetDefDispEnv
    /* CB20 8001C320 1000B0AF */   sw        $s0, 0x10($sp)
    /* CB24 8001C324 FC002426 */  addiu      $a0, $s1, 0xFC
    /* CB28 8001C328 21280000 */  addu       $a1, $zero, $zero
    /* CB2C 8001C32C 2130A000 */  addu       $a2, $a1, $zero
    /* CB30 8001C330 21384002 */  addu       $a3, $s2, $zero
    /* CB34 8001C334 ADAA000C */  jal        SetDefDispEnv
    /* CB38 8001C338 1000B0AF */   sw        $s0, 0x10($sp)
    /* CB3C 8001C33C 21104002 */  addu       $v0, $s2, $zero
    /* CB40 8001C340 380033A6 */  sh         $s3, 0x38($s1)
    /* CB44 8001C344 3A0034A6 */  sh         $s4, 0x3A($s1)
    /* CB48 8001C348 940033A6 */  sh         $s3, 0x94($s1)
    /* CB4C 8001C34C 02004106 */  bgez       $s2, .L8001C358
    /* CB50 8001C350 960034A6 */   sh        $s4, 0x96($s1)
    /* CB54 8001C354 1F004226 */  addiu      $v0, $s2, 0x1F
  .L8001C358:
    /* CB58 8001C358 1E710008 */  j          .L8001C478
    /* CB5C 8001C35C 43110200 */   sra       $v0, $v0, 5
  .L8001C360:
    /* CB60 8001C360 2300E010 */  beqz       $a3, .L8001C3F0
    /* CB64 8001C364 30002426 */   addiu     $a0, $s1, 0x30
    /* CB68 8001C368 E0010524 */  addiu      $a1, $zero, 0x1E0
    /* CB6C 8001C36C 21300000 */  addu       $a2, $zero, $zero
    /* CB70 8001C370 40010724 */  addiu      $a3, $zero, 0x140
    /* CB74 8001C374 2180A000 */  addu       $s0, $a1, $zero
    /* CB78 8001C378 7DAA000C */  jal        func_8002A9F4
    /* CB7C 8001C37C 1000B0AF */   sw        $s0, 0x10($sp)
    /* CB80 8001C380 8C002426 */  addiu      $a0, $s1, 0x8C
    /* CB84 8001C384 21280000 */  addu       $a1, $zero, $zero
    /* CB88 8001C388 2130A000 */  addu       $a2, $a1, $zero
    /* CB8C 8001C38C 40010724 */  addiu      $a3, $zero, 0x140
    /* CB90 8001C390 7DAA000C */  jal        func_8002A9F4
    /* CB94 8001C394 1000B0AF */   sw        $s0, 0x10($sp)
    /* CB98 8001C398 E8002426 */  addiu      $a0, $s1, 0xE8
    /* CB9C 8001C39C 21280000 */  addu       $a1, $zero, $zero
    /* CBA0 8001C3A0 2130A000 */  addu       $a2, $a1, $zero
    /* CBA4 8001C3A4 40010724 */  addiu      $a3, $zero, 0x140
    /* CBA8 8001C3A8 ADAA000C */  jal        SetDefDispEnv
    /* CBAC 8001C3AC 1000B0AF */   sw        $s0, 0x10($sp)
    /* CBB0 8001C3B0 FC002426 */  addiu      $a0, $s1, 0xFC
    /* CBB4 8001C3B4 E0010524 */  addiu      $a1, $zero, 0x1E0
    /* CBB8 8001C3B8 21300000 */  addu       $a2, $zero, $zero
    /* CBBC 8001C3BC 40010724 */  addiu      $a3, $zero, 0x140
    /* CBC0 8001C3C0 F90035A2 */  sb         $s5, 0xF9($s1)
    /* CBC4 8001C3C4 ADAA000C */  jal        SetDefDispEnv
    /* CBC8 8001C3C8 1000B0AF */   sw        $s0, 0x10($sp)
    /* CBCC 8001C3CC 21105302 */  addu       $v0, $s2, $s3
    /* CBD0 8001C3D0 0D0135A2 */  sb         $s5, 0x10D($s1)
    /* CBD4 8001C3D4 470035A2 */  sb         $s5, 0x47($s1)
    /* CBD8 8001C3D8 A30035A2 */  sb         $s5, 0xA3($s1)
    /* CBDC 8001C3DC 380022A6 */  sh         $v0, 0x38($s1)
    /* CBE0 8001C3E0 3A0034A6 */  sh         $s4, 0x3A($s1)
    /* CBE4 8001C3E4 940033A6 */  sh         $s3, 0x94($s1)
    /* CBE8 8001C3E8 21710008 */  j          .L8001C484
    /* CBEC 8001C3EC 960034A6 */   sh        $s4, 0x96($s1)
  .L8001C3F0:
    /* CBF0 8001C3F0 21284002 */  addu       $a1, $s2, $zero
    /* CBF4 8001C3F4 21300000 */  addu       $a2, $zero, $zero
    /* CBF8 8001C3F8 21384002 */  addu       $a3, $s2, $zero
    /* CBFC 8001C3FC 7DAA000C */  jal        func_8002A9F4
    /* CC00 8001C400 1000B0AF */   sw        $s0, 0x10($sp)
    /* CC04 8001C404 8C002426 */  addiu      $a0, $s1, 0x8C
    /* CC08 8001C408 21280000 */  addu       $a1, $zero, $zero
    /* CC0C 8001C40C 2130A000 */  addu       $a2, $a1, $zero
    /* CC10 8001C410 21384002 */  addu       $a3, $s2, $zero
    /* CC14 8001C414 7DAA000C */  jal        func_8002A9F4
    /* CC18 8001C418 1000B0AF */   sw        $s0, 0x10($sp)
    /* CC1C 8001C41C E8002426 */  addiu      $a0, $s1, 0xE8
    /* CC20 8001C420 21280000 */  addu       $a1, $zero, $zero
    /* CC24 8001C424 2130A000 */  addu       $a2, $a1, $zero
    /* CC28 8001C428 21384002 */  addu       $a3, $s2, $zero
    /* CC2C 8001C42C ADAA000C */  jal        SetDefDispEnv
    /* CC30 8001C430 1000B0AF */   sw        $s0, 0x10($sp)
    /* CC34 8001C434 FC002426 */  addiu      $a0, $s1, 0xFC
    /* CC38 8001C438 21284002 */  addu       $a1, $s2, $zero
    /* CC3C 8001C43C 21300000 */  addu       $a2, $zero, $zero
    /* CC40 8001C440 21384002 */  addu       $a3, $s2, $zero
    /* CC44 8001C444 ADAA000C */  jal        SetDefDispEnv
    /* CC48 8001C448 1000B0AF */   sw        $s0, 0x10($sp)
    /* CC4C 8001C44C 21204002 */  addu       $a0, $s2, $zero
    /* CC50 8001C450 21109300 */  addu       $v0, $a0, $s3
    /* CC54 8001C454 470035A2 */  sb         $s5, 0x47($s1)
    /* CC58 8001C458 A30035A2 */  sb         $s5, 0xA3($s1)
    /* CC5C 8001C45C 380022A6 */  sh         $v0, 0x38($s1)
    /* CC60 8001C460 3A0034A6 */  sh         $s4, 0x3A($s1)
    /* CC64 8001C464 940033A6 */  sh         $s3, 0x94($s1)
    /* CC68 8001C468 02008104 */  bgez       $a0, .L8001C474
    /* CC6C 8001C46C 960034A6 */   sh        $s4, 0x96($s1)
    /* CC70 8001C470 0F008424 */  addiu      $a0, $a0, 0xF
  .L8001C474:
    /* CC74 8001C474 03110400 */  sra        $v0, $a0, 4
  .L8001C478:
    /* CC78 8001C478 40100200 */  sll        $v0, $v0, 1
    /* CC7C 8001C47C 40000324 */  addiu      $v1, $zero, 0x40
    /* CC80 8001C480 23B06200 */  subu       $s6, $v1, $v0
  .L8001C484:
    /* CC84 8001C484 4B73000C */  jal        func_8001CD2C
    /* CC88 8001C488 2120C002 */   addu      $a0, $s6, $zero
    /* CC8C 8001C48C 31AD000C */  jal        func_8002B4C4
    /* CC90 8001C490 00000000 */   nop
    /* CC94 8001C494 21200000 */  addu       $a0, $zero, $zero
    /* CC98 8001C498 A9B5000C */  jal        SetGeomOffset
    /* CC9C 8001C49C 21288000 */   addu      $a1, $a0, $zero
    /* CCA0 8001C4A0 3400BF8F */  lw         $ra, 0x34($sp)
    /* CCA4 8001C4A4 3000B68F */  lw         $s6, 0x30($sp)
    /* CCA8 8001C4A8 2C00B58F */  lw         $s5, 0x2C($sp)
    /* CCAC 8001C4AC 2800B48F */  lw         $s4, 0x28($sp)
    /* CCB0 8001C4B0 2400B38F */  lw         $s3, 0x24($sp)
    /* CCB4 8001C4B4 2000B28F */  lw         $s2, 0x20($sp)
    /* CCB8 8001C4B8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* CCBC 8001C4BC 1800B08F */  lw         $s0, 0x18($sp)
    /* CCC0 8001C4C0 0800E003 */  jr         $ra
    /* CCC4 8001C4C4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8001C1E0
