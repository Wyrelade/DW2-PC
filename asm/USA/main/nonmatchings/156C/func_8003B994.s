nonmatching func_8003B994, 0x4D4

glabel func_8003B994
    /* 2C194 8003B994 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* 2C198 8003B998 6800B2AF */  sw         $s2, 0x68($sp)
    /* 2C19C 8003B99C 21908000 */  addu       $s2, $a0, $zero
    /* 2C1A0 8003B9A0 7C00B7AF */  sw         $s7, 0x7C($sp)
    /* 2C1A4 8003B9A4 21B80000 */  addu       $s7, $zero, $zero
    /* 2C1A8 8003B9A8 7000B4AF */  sw         $s4, 0x70($sp)
    /* 2C1AC 8003B9AC 21A00000 */  addu       $s4, $zero, $zero
    /* 2C1B0 8003B9B0 7800B6AF */  sw         $s6, 0x78($sp)
    /* 2C1B4 8003B9B4 21B00000 */  addu       $s6, $zero, $zero
    /* 2C1B8 8003B9B8 8400BFAF */  sw         $ra, 0x84($sp)
    /* 2C1BC 8003B9BC 8000BEAF */  sw         $fp, 0x80($sp)
    /* 2C1C0 8003B9C0 7400B5AF */  sw         $s5, 0x74($sp)
    /* 2C1C4 8003B9C4 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 2C1C8 8003B9C8 6400B1AF */  sw         $s1, 0x64($sp)
    /* 2C1CC 8003B9CC 6000B0AF */  sw         $s0, 0x60($sp)
    /* 2C1D0 8003B9D0 5800A0AF */  sw         $zero, 0x58($sp)
    /* 2C1D4 8003B9D4 0000538E */  lw         $s3, 0x0($s2)
    /* 2C1D8 8003B9D8 21F00000 */  addu       $fp, $zero, $zero
    /* 2C1DC 8003B9DC 0100752E */  sltiu      $s5, $s3, 0x1
    /* 2C1E0 8003B9E0 0400A016 */  bnez       $s5, .L8003B9F4
    /* 2C1E4 8003B9E4 1000A0AF */   sw        $zero, 0x10($sp)
    /* 2C1E8 8003B9E8 01006232 */  andi       $v0, $s3, 0x1
    /* 2C1EC 8003B9EC 43004010 */  beqz       $v0, .L8003BAFC
    /* 2C1F0 8003B9F0 00000000 */   nop
  .L8003B9F4:
    /* 2C1F4 8003B9F4 0400508E */  lw         $s0, 0x4($s2)
    /* 2C1F8 8003B9F8 00000000 */  nop
    /* 2C1FC 8003B9FC 00010232 */  andi       $v0, $s0, 0x100
    /* 2C200 8003BA00 04004010 */  beqz       $v0, .L8003BA14
    /* 2C204 8003BA04 FFFE0224 */   addiu     $v0, $zero, -0x101
    /* 2C208 8003BA08 24800202 */  and        $s0, $s0, $v0
    /* 2C20C 8003BA0C 01000824 */  addiu      $t0, $zero, 0x1
    /* 2C210 8003BA10 5800A8AF */  sw         $t0, 0x58($sp)
  .L8003BA14:
    /* 2C214 8003BA14 0A00022E */  sltiu      $v0, $s0, 0xA
    /* 2C218 8003BA18 09004010 */  beqz       $v0, .L8003BA40
    /* 2C21C 8003BA1C 80101000 */   sll       $v0, $s0, 2
    /* 2C220 8003BA20 0580043C */  lui        $a0, %hi(D_800503B8)
    /* 2C224 8003BA24 21208200 */  addu       $a0, $a0, $v0
    /* 2C228 8003BA28 B803848C */  lw         $a0, %lo(D_800503B8)($a0)
    /* 2C22C 8003BA2C 0580113C */  lui        $s1, %hi(D_800503B8)
    /* 2C230 8003BA30 41EE000C */  jal        _SpuIsInAllocateArea_
    /* 2C234 8003BA34 B8033126 */   addiu     $s1, $s1, %lo(D_800503B8)
    /* 2C238 8003BA38 03004010 */  beqz       $v0, .L8003BA48
    /* 2C23C 8003BA3C 01001424 */   addiu     $s4, $zero, 0x1
  .L8003BA40:
    /* 2C240 8003BA40 8EEF0008 */  j          .L8003BE38
    /* 2C244 8003BA44 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8003BA48:
    /* 2C248 8003BA48 1000A627 */  addiu      $a2, $sp, 0x10
    /* 2C24C 8003BA4C 43000524 */  addiu      $a1, $zero, 0x43
    /* 2C250 8003BA50 0580013C */  lui        $at, %hi(D_8004FDCC)
    /* 2C254 8003BA54 CCFD30AC */  sw         $s0, %lo(D_8004FDCC)($at)
    /* 2C258 8003BA58 0580033C */  lui        $v1, %hi(D_8004FDCC)
    /* 2C25C 8003BA5C CCFD638C */  lw         $v1, %lo(D_8004FDCC)($v1)
    /* 2C260 8003BA60 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* 2C264 8003BA64 80200300 */  sll        $a0, $v1, 2
    /* 2C268 8003BA68 21209100 */  addu       $a0, $a0, $s1
    /* 2C26C 8003BA6C 00110300 */  sll        $v0, $v1, 4
    /* 2C270 8003BA70 21104300 */  addu       $v0, $v0, $v1
    /* 2C274 8003BA74 80100200 */  sll        $v0, $v0, 2
    /* 2C278 8003BA78 0580033C */  lui        $v1, %hi(D_800503E8)
    /* 2C27C 8003BA7C E8036324 */  addiu      $v1, $v1, %lo(D_800503E8)
    /* 2C280 8003BA80 0000848C */  lw         $a0, 0x0($a0)
    /* 2C284 8003BA84 21184300 */  addu       $v1, $v0, $v1
    /* 2C288 8003BA88 0580013C */  lui        $at, %hi(D_8004FDC4)
    /* 2C28C 8003BA8C C4FD24AC */  sw         $a0, %lo(D_8004FDC4)($at)
  .L8003BA90:
    /* 2C290 8003BA90 00006290 */  lbu        $v0, 0x0($v1)
    /* 2C294 8003BA94 01006324 */  addiu      $v1, $v1, 0x1
    /* 2C298 8003BA98 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2C29C 8003BA9C 0000C2A0 */  sb         $v0, 0x0($a2)
    /* 2C2A0 8003BAA0 FBFFA714 */  bne        $a1, $a3, .L8003BA90
    /* 2C2A4 8003BAA4 0100C624 */   addiu     $a2, $a2, 0x1
    /* 2C2A8 8003BAA8 0580043C */  lui        $a0, %hi(D_8004FDCC)
    /* 2C2AC 8003BAAC CCFD8424 */  addiu      $a0, $a0, %lo(D_8004FDCC)
    /* 2C2B0 8003BAB0 0000838C */  lw         $v1, 0x0($a0)
    /* 2C2B4 8003BAB4 07000224 */  addiu      $v0, $zero, 0x7
    /* 2C2B8 8003BAB8 05006210 */  beq        $v1, $v0, .L8003BAD0
    /* 2C2BC 8003BABC 08000224 */   addiu     $v0, $zero, 0x8
    /* 2C2C0 8003BAC0 07006210 */  beq        $v1, $v0, .L8003BAE0
    /* 2C2C4 8003BAC4 7F000224 */   addiu     $v0, $zero, 0x7F
    /* 2C2C8 8003BAC8 BBEE0008 */  j          .L8003BAEC
    /* 2C2CC 8003BACC 00000000 */   nop
  .L8003BAD0:
    /* 2C2D0 8003BAD0 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 2C2D4 8003BAD4 0C0082AC */  sw         $v0, 0xC($a0)
    /* 2C2D8 8003BAD8 BFEE0008 */  j          .L8003BAFC
    /* 2C2DC 8003BADC 080082AC */   sw        $v0, 0x8($a0)
  .L8003BAE0:
    /* 2C2E0 8003BAE0 0C0080AC */  sw         $zero, 0xC($a0)
    /* 2C2E4 8003BAE4 BFEE0008 */  j          .L8003BAFC
    /* 2C2E8 8003BAE8 080082AC */   sw        $v0, 0x8($a0)
  .L8003BAEC:
    /* 2C2EC 8003BAEC 0580023C */  lui        $v0, %hi(D_8004FDD8)
    /* 2C2F0 8003BAF0 D8FD4224 */  addiu      $v0, $v0, %lo(D_8004FDD8)
    /* 2C2F4 8003BAF4 000040AC */  sw         $zero, 0x0($v0)
    /* 2C2F8 8003BAF8 FCFF40AC */  sw         $zero, -0x4($v0)
  .L8003BAFC:
    /* 2C2FC 8003BAFC 0300A016 */  bnez       $s5, .L8003BB0C
    /* 2C300 8003BB00 08006232 */   andi      $v0, $s3, 0x8
    /* 2C304 8003BB04 45004010 */  beqz       $v0, .L8003BC1C
    /* 2C308 8003BB08 00000000 */   nop
  .L8003BB0C:
    /* 2C30C 8003BB0C 0580033C */  lui        $v1, %hi(D_8004FDCC)
    /* 2C310 8003BB10 CCFD638C */  lw         $v1, %lo(D_8004FDCC)($v1)
    /* 2C314 8003BB14 00000000 */  nop
    /* 2C318 8003BB18 09006228 */  slti       $v0, $v1, 0x9
    /* 2C31C 8003BB1C 3F004010 */  beqz       $v0, .L8003BC1C
    /* 2C320 8003BB20 07006228 */   slti      $v0, $v1, 0x7
    /* 2C324 8003BB24 3D004014 */  bnez       $v0, .L8003BC1C
    /* 2C328 8003BB28 00000000 */   nop
    /* 2C32C 8003BB2C 15008016 */  bnez       $s4, .L8003BB84
    /* 2C330 8003BB30 01001624 */   addiu     $s6, $zero, 0x1
    /* 2C334 8003BB34 1000A527 */  addiu      $a1, $sp, 0x10
    /* 2C338 8003BB38 43000424 */  addiu      $a0, $zero, 0x43
    /* 2C33C 8003BB3C 0580023C */  lui        $v0, %hi(D_8004FDCC)
    /* 2C340 8003BB40 CCFD428C */  lw         $v0, %lo(D_8004FDCC)($v0)
    /* 2C344 8003BB44 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 2C348 8003BB48 00190200 */  sll        $v1, $v0, 4
    /* 2C34C 8003BB4C 21186200 */  addu       $v1, $v1, $v0
    /* 2C350 8003BB50 80180300 */  sll        $v1, $v1, 2
    /* 2C354 8003BB54 0580023C */  lui        $v0, %hi(D_800503E8)
    /* 2C358 8003BB58 E8034224 */  addiu      $v0, $v0, %lo(D_800503E8)
    /* 2C35C 8003BB5C 21186200 */  addu       $v1, $v1, $v0
  .L8003BB60:
    /* 2C360 8003BB60 00006290 */  lbu        $v0, 0x0($v1)
    /* 2C364 8003BB64 01006324 */  addiu      $v1, $v1, 0x1
    /* 2C368 8003BB68 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 2C36C 8003BB6C 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 2C370 8003BB70 FBFF8614 */  bne        $a0, $a2, .L8003BB60
    /* 2C374 8003BB74 0100A524 */   addiu     $a1, $a1, 0x1
    /* 2C378 8003BB78 010C023C */  lui        $v0, (0xC011C00 >> 16)
    /* 2C37C 8003BB7C 001C4234 */  ori        $v0, $v0, (0xC011C00 & 0xFFFF)
    /* 2C380 8003BB80 1000A2AF */  sw         $v0, 0x10($sp)
  .L8003BB84:
    /* 2C384 8003BB84 0281043C */  lui        $a0, (0x81020409 >> 16)
    /* 2C388 8003BB88 0C00428E */  lw         $v0, 0xC($s2)
    /* 2C38C 8003BB8C 09048434 */  ori        $a0, $a0, (0x81020409 & 0xFFFF)
    /* 2C390 8003BB90 401B0200 */  sll        $v1, $v0, 13
    /* 2C394 8003BB94 18006400 */  mult       $v1, $a0
    /* 2C398 8003BB98 10380000 */  mfhi       $a3
    /* 2C39C 8003BB9C 002B0200 */  sll        $a1, $v0, 12
    /* 2C3A0 8003BBA0 00000000 */  nop
    /* 2C3A4 8003BBA4 1800A400 */  mult       $a1, $a0
    /* 2C3A8 8003BBA8 0580013C */  lui        $at, %hi(D_8004FDD4)
    /* 2C3AC 8003BBAC D4FD22AC */  sw         $v0, %lo(D_8004FDD4)($at)
    /* 2C3B0 8003BBB0 2110E300 */  addu       $v0, $a3, $v1
    /* 2C3B4 8003BBB4 83110200 */  sra        $v0, $v0, 6
    /* 2C3B8 8003BBB8 C31F0300 */  sra        $v1, $v1, 31
    /* 2C3BC 8003BBBC 23104300 */  subu       $v0, $v0, $v1
    /* 2C3C0 8003BBC0 1400A497 */  lhu        $a0, 0x14($sp)
    /* 2C3C4 8003BBC4 3600A397 */  lhu        $v1, 0x36($sp)
    /* 2C3C8 8003BBC8 23104400 */  subu       $v0, $v0, $a0
    /* 2C3CC 8003BBCC 2800A2A7 */  sh         $v0, 0x28($sp)
    /* 2C3D0 8003BBD0 1600A297 */  lhu        $v0, 0x16($sp)
    /* 2C3D4 8003BBD4 10300000 */  mfhi       $a2
    /* 2C3D8 8003BBD8 2120C500 */  addu       $a0, $a2, $a1
    /* 2C3DC 8003BBDC 83210400 */  sra        $a0, $a0, 6
    /* 2C3E0 8003BBE0 C32F0500 */  sra        $a1, $a1, 31
    /* 2C3E4 8003BBE4 23208500 */  subu       $a0, $a0, $a1
    /* 2C3E8 8003BBE8 23108200 */  subu       $v0, $a0, $v0
    /* 2C3EC 8003BBEC 2A00A2A7 */  sh         $v0, 0x2A($sp)
    /* 2C3F0 8003BBF0 2E00A297 */  lhu        $v0, 0x2E($sp)
    /* 2C3F4 8003BBF4 21186400 */  addu       $v1, $v1, $a0
    /* 2C3F8 8003BBF8 3400A3A7 */  sh         $v1, 0x34($sp)
    /* 2C3FC 8003BBFC 4E00A397 */  lhu        $v1, 0x4E($sp)
    /* 2C400 8003BC00 21104400 */  addu       $v0, $v0, $a0
    /* 2C404 8003BC04 2C00A2A7 */  sh         $v0, 0x2C($sp)
    /* 2C408 8003BC08 4C00A297 */  lhu        $v0, 0x4C($sp)
    /* 2C40C 8003BC0C 21186400 */  addu       $v1, $v1, $a0
    /* 2C410 8003BC10 4A00A3A7 */  sh         $v1, 0x4A($sp)
    /* 2C414 8003BC14 21104400 */  addu       $v0, $v0, $a0
    /* 2C418 8003BC18 4800A2A7 */  sh         $v0, 0x48($sp)
  .L8003BC1C:
    /* 2C41C 8003BC1C 0300A016 */  bnez       $s5, .L8003BC2C
    /* 2C420 8003BC20 10006232 */   andi      $v0, $s3, 0x10
    /* 2C424 8003BC24 32004010 */  beqz       $v0, .L8003BCF0
    /* 2C428 8003BC28 00000000 */   nop
  .L8003BC2C:
    /* 2C42C 8003BC2C 0580033C */  lui        $v1, %hi(D_8004FDCC)
    /* 2C430 8003BC30 CCFD638C */  lw         $v1, %lo(D_8004FDCC)($v1)
    /* 2C434 8003BC34 00000000 */  nop
    /* 2C438 8003BC38 09006228 */  slti       $v0, $v1, 0x9
    /* 2C43C 8003BC3C 2C004010 */  beqz       $v0, .L8003BCF0
    /* 2C440 8003BC40 07006228 */   slti      $v0, $v1, 0x7
    /* 2C444 8003BC44 2A004014 */  bnez       $v0, .L8003BCF0
    /* 2C448 8003BC48 00000000 */   nop
    /* 2C44C 8003BC4C 19008016 */  bnez       $s4, .L8003BCB4
    /* 2C450 8003BC50 01001E24 */   addiu     $fp, $zero, 0x1
    /* 2C454 8003BC54 1300C016 */  bnez       $s6, .L8003BCA4
    /* 2C458 8003BC58 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2C45C 8003BC5C 43000424 */  addiu      $a0, $zero, 0x43
    /* 2C460 8003BC60 0580023C */  lui        $v0, %hi(D_8004FDCC)
    /* 2C464 8003BC64 CCFD428C */  lw         $v0, %lo(D_8004FDCC)($v0)
    /* 2C468 8003BC68 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 2C46C 8003BC6C 00190200 */  sll        $v1, $v0, 4
    /* 2C470 8003BC70 21186200 */  addu       $v1, $v1, $v0
    /* 2C474 8003BC74 80180300 */  sll        $v1, $v1, 2
    /* 2C478 8003BC78 0580023C */  lui        $v0, %hi(D_800503E8)
    /* 2C47C 8003BC7C E8034224 */  addiu      $v0, $v0, %lo(D_800503E8)
    /* 2C480 8003BC80 21186200 */  addu       $v1, $v1, $v0
  .L8003BC84:
    /* 2C484 8003BC84 00006290 */  lbu        $v0, 0x0($v1)
    /* 2C488 8003BC88 01006324 */  addiu      $v1, $v1, 0x1
    /* 2C48C 8003BC8C FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 2C490 8003BC90 0000A2A0 */  sb         $v0, 0x0($a1)
    /* 2C494 8003BC94 FBFF8614 */  bne        $a0, $a2, .L8003BC84
    /* 2C498 8003BC98 0100A524 */   addiu     $a1, $a1, 0x1
    /* 2C49C 8003BC9C 2CEF0008 */  j          .L8003BCB0
    /* 2C4A0 8003BCA0 80000224 */   addiu     $v0, $zero, 0x80
  .L8003BCA4:
    /* 2C4A4 8003BCA4 1000A28F */  lw         $v0, 0x10($sp)
    /* 2C4A8 8003BCA8 00000000 */  nop
    /* 2C4AC 8003BCAC 80004234 */  ori        $v0, $v0, 0x80
  .L8003BCB0:
    /* 2C4B0 8003BCB0 1000A2AF */  sw         $v0, 0x10($sp)
  .L8003BCB4:
    /* 2C4B4 8003BCB4 0281043C */  lui        $a0, (0x81020409 >> 16)
    /* 2C4B8 8003BCB8 1000438E */  lw         $v1, 0x10($s2)
    /* 2C4BC 8003BCBC 09048434 */  ori        $a0, $a0, (0x81020409 & 0xFFFF)
    /* 2C4C0 8003BCC0 C0110300 */  sll        $v0, $v1, 7
    /* 2C4C4 8003BCC4 21104300 */  addu       $v0, $v0, $v1
    /* 2C4C8 8003BCC8 00120200 */  sll        $v0, $v0, 8
    /* 2C4CC 8003BCCC 18004400 */  mult       $v0, $a0
    /* 2C4D0 8003BCD0 0580013C */  lui        $at, %hi(D_8004FDD8)
    /* 2C4D4 8003BCD4 D8FD23AC */  sw         $v1, %lo(D_8004FDD8)($at)
    /* 2C4D8 8003BCD8 10400000 */  mfhi       $t0
    /* 2C4DC 8003BCDC 21180201 */  addu       $v1, $t0, $v0
    /* 2C4E0 8003BCE0 83190300 */  sra        $v1, $v1, 6
    /* 2C4E4 8003BCE4 C3170200 */  sra        $v0, $v0, 31
    /* 2C4E8 8003BCE8 23186200 */  subu       $v1, $v1, $v0
    /* 2C4EC 8003BCEC 2200A3A7 */  sh         $v1, 0x22($sp)
  .L8003BCF0:
    /* 2C4F0 8003BCF0 0F008012 */  beqz       $s4, .L8003BD30
    /* 2C4F4 8003BCF4 00000000 */   nop
    /* 2C4F8 8003BCF8 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2C4FC 8003BCFC 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2C500 8003BD00 00000000 */  nop
    /* 2C504 8003BD04 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2C508 8003BD08 00000000 */  nop
    /* 2C50C 8003BD0C C2110200 */  srl        $v0, $v0, 7
    /* 2C510 8003BD10 01005730 */  andi       $s7, $v0, 0x1
    /* 2C514 8003BD14 1F00E012 */  beqz       $s7, .L8003BD94
    /* 2C518 8003BD18 00000000 */   nop
    /* 2C51C 8003BD1C AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2C520 8003BD20 00000000 */  nop
    /* 2C524 8003BD24 7FFF4230 */  andi       $v0, $v0, 0xFF7F
    /* 2C528 8003BD28 65EF0008 */  j          .L8003BD94
    /* 2C52C 8003BD2C AA0162A4 */   sh        $v0, 0x1AA($v1)
  .L8003BD30:
    /* 2C530 8003BD30 0300A016 */  bnez       $s5, .L8003BD40
    /* 2C534 8003BD34 02006232 */   andi      $v0, $s3, 0x2
    /* 2C538 8003BD38 09004010 */  beqz       $v0, .L8003BD60
    /* 2C53C 8003BD3C 00000000 */   nop
  .L8003BD40:
    /* 2C540 8003BD40 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2C544 8003BD44 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2C548 8003BD48 08004396 */  lhu        $v1, 0x8($s2)
    /* 2C54C 8003BD4C 00000000 */  nop
    /* 2C550 8003BD50 840143A4 */  sh         $v1, 0x184($v0)
    /* 2C554 8003BD54 08004296 */  lhu        $v0, 0x8($s2)
    /* 2C558 8003BD58 0580013C */  lui        $at, %hi(D_8004FDD0)
    /* 2C55C 8003BD5C D0FD22A4 */  sh         $v0, %lo(D_8004FDD0)($at)
  .L8003BD60:
    /* 2C560 8003BD60 0300A016 */  bnez       $s5, .L8003BD70
    /* 2C564 8003BD64 04006232 */   andi      $v0, $s3, 0x4
    /* 2C568 8003BD68 13004010 */  beqz       $v0, .L8003BDB8
    /* 2C56C 8003BD6C 00000000 */   nop
  .L8003BD70:
    /* 2C570 8003BD70 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2C574 8003BD74 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2C578 8003BD78 0A004396 */  lhu        $v1, 0xA($s2)
    /* 2C57C 8003BD7C 00000000 */  nop
    /* 2C580 8003BD80 860143A4 */  sh         $v1, 0x186($v0)
    /* 2C584 8003BD84 0A004296 */  lhu        $v0, 0xA($s2)
    /* 2C588 8003BD88 0580013C */  lui        $at, %hi(D_8004FDD2)
    /* 2C58C 8003BD8C 6EEF0008 */  j          .L8003BDB8
    /* 2C590 8003BD90 D2FD22A4 */   sh        $v0, %lo(D_8004FDD2)($at)
  .L8003BD94:
    /* 2C594 8003BD94 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2C598 8003BD98 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2C59C 8003BD9C 00000000 */  nop
    /* 2C5A0 8003BDA0 840140A4 */  sh         $zero, 0x184($v0)
    /* 2C5A4 8003BDA4 860140A4 */  sh         $zero, 0x186($v0)
    /* 2C5A8 8003BDA8 0580023C */  lui        $v0, %hi(D_8004FDD0)
    /* 2C5AC 8003BDAC D0FD4224 */  addiu      $v0, $v0, %lo(D_8004FDD0)
    /* 2C5B0 8003BDB0 000040A4 */  sh         $zero, 0x0($v0)
    /* 2C5B4 8003BDB4 020040A4 */  sh         $zero, 0x2($v0)
  .L8003BDB8:
    /* 2C5B8 8003BDB8 05008016 */  bnez       $s4, .L8003BDD0
    /* 2C5BC 8003BDBC 00000000 */   nop
    /* 2C5C0 8003BDC0 0300C016 */  bnez       $s6, .L8003BDD0
    /* 2C5C4 8003BDC4 00000000 */   nop
    /* 2C5C8 8003BDC8 0300C013 */  beqz       $fp, .L8003BDD8
    /* 2C5CC 8003BDCC 00000000 */   nop
  .L8003BDD0:
    /* 2C5D0 8003BDD0 9DEF000C */  jal        _spu_setReverbAttr
    /* 2C5D4 8003BDD4 1000A427 */   addiu     $a0, $sp, 0x10
  .L8003BDD8:
    /* 2C5D8 8003BDD8 5800A88F */  lw         $t0, 0x58($sp)
    /* 2C5DC 8003BDDC 00000000 */  nop
    /* 2C5E0 8003BDE0 05000011 */  beqz       $t0, .L8003BDF8
    /* 2C5E4 8003BDE4 00000000 */   nop
    /* 2C5E8 8003BDE8 0580043C */  lui        $a0, %hi(D_8004FDCC)
    /* 2C5EC 8003BDEC CCFD848C */  lw         $a0, %lo(D_8004FDCC)($a0)
    /* 2C5F0 8003BDF0 E9F0000C */  jal        SpuClearReverbWorkArea
    /* 2C5F4 8003BDF4 00000000 */   nop
  .L8003BDF8:
    /* 2C5F8 8003BDF8 0E008012 */  beqz       $s4, .L8003BE34
    /* 2C5FC 8003BDFC D1000424 */   addiu     $a0, $zero, 0xD1
    /* 2C600 8003BE00 0580053C */  lui        $a1, %hi(D_8004FDC4)
    /* 2C604 8003BE04 C4FDA58C */  lw         $a1, %lo(D_8004FDC4)($a1)
    /* 2C608 8003BE08 B8EA000C */  jal        _spu_FsetRXX
    /* 2C60C 8003BE0C 21300000 */   addu      $a2, $zero, $zero
    /* 2C610 8003BE10 0900E012 */  beqz       $s7, .L8003BE38
    /* 2C614 8003BE14 21100000 */   addu      $v0, $zero, $zero
    /* 2C618 8003BE18 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2C61C 8003BE1C 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2C620 8003BE20 00000000 */  nop
    /* 2C624 8003BE24 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2C628 8003BE28 00000000 */  nop
    /* 2C62C 8003BE2C 80004234 */  ori        $v0, $v0, 0x80
    /* 2C630 8003BE30 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8003BE34:
    /* 2C634 8003BE34 21100000 */  addu       $v0, $zero, $zero
  .L8003BE38:
    /* 2C638 8003BE38 8400BF8F */  lw         $ra, 0x84($sp)
    /* 2C63C 8003BE3C 8000BE8F */  lw         $fp, 0x80($sp)
    /* 2C640 8003BE40 7C00B78F */  lw         $s7, 0x7C($sp)
    /* 2C644 8003BE44 7800B68F */  lw         $s6, 0x78($sp)
    /* 2C648 8003BE48 7400B58F */  lw         $s5, 0x74($sp)
    /* 2C64C 8003BE4C 7000B48F */  lw         $s4, 0x70($sp)
    /* 2C650 8003BE50 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 2C654 8003BE54 6800B28F */  lw         $s2, 0x68($sp)
    /* 2C658 8003BE58 6400B18F */  lw         $s1, 0x64($sp)
    /* 2C65C 8003BE5C 6000B08F */  lw         $s0, 0x60($sp)
    /* 2C660 8003BE60 0800E003 */  jr         $ra
    /* 2C664 8003BE64 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel func_8003B994
    /* 2C668 8003BE68 00000000 */  nop
    /* 2C66C 8003BE6C 00000000 */  nop
    /* 2C670 8003BE70 00000000 */  nop
