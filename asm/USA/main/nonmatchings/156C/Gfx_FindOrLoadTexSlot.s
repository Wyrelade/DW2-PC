nonmatching Gfx_FindOrLoadTexSlot, 0x1AC

glabel Gfx_FindOrLoadTexSlot
    /* D380 8001CB80 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* D384 8001CB84 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* D388 8001CB88 21988000 */  addu       $s3, $a0, $zero
    /* D38C 8001CB8C 0680023C */  lui        $v0, %hi(Gfx_TexSlots)
    /* D390 8001CB90 60CD4424 */  addiu      $a0, $v0, %lo(Gfx_TexSlots)
    /* D394 8001CB94 21180000 */  addu       $v1, $zero, $zero
    /* D398 8001CB98 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* D39C 8001CB9C FEFF0524 */  addiu      $a1, $zero, -0x2
    /* D3A0 8001CBA0 2000BFAF */  sw         $ra, 0x20($sp)
    /* D3A4 8001CBA4 1800B2AF */  sw         $s2, 0x18($sp)
    /* D3A8 8001CBA8 1400B1AF */  sw         $s1, 0x14($sp)
    /* D3AC 8001CBAC 1000B0AF */  sw         $s0, 0x10($sp)
  .L8001CBB0:
    /* D3B0 8001CBB0 0000828C */  lw         $v0, 0x0($a0)
    /* D3B4 8001CBB4 00000000 */  nop
    /* D3B8 8001CBB8 05004610 */  beq        $v0, $a2, .L8001CBD0
    /* D3BC 8001CBBC 00000000 */   nop
    /* D3C0 8001CBC0 03004510 */  beq        $v0, $a1, .L8001CBD0
    /* D3C4 8001CBC4 00000000 */   nop
    /* D3C8 8001CBC8 3A005310 */  beq        $v0, $s3, .L8001CCB4
    /* D3CC 8001CBCC 0680023C */   lui       $v0, %hi(D_8005F770)
  .L8001CBD0:
    /* D3D0 8001CBD0 01006324 */  addiu      $v1, $v1, 0x1
    /* D3D4 8001CBD4 40006228 */  slti       $v0, $v1, 0x40
    /* D3D8 8001CBD8 F5FF4014 */  bnez       $v0, .L8001CBB0
    /* D3DC 8001CBDC 20008424 */   addiu     $a0, $a0, 0x20
    /* D3E0 8001CBE0 FFFF1124 */  addiu      $s1, $zero, -0x1
    /* D3E4 8001CBE4 21900000 */  addu       $s2, $zero, $zero
    /* D3E8 8001CBE8 A872000C */  jal        func_8001CAA0
    /* D3EC 8001CBEC 21206002 */   addu      $a0, $s3, $zero
    /* D3F0 8001CBF0 05004010 */  beqz       $v0, .L8001CC08
    /* D3F4 8001CBF4 20000624 */   addiu     $a2, $zero, 0x20
    /* D3F8 8001CBF8 04730008 */  j          .L8001CC10
    /* D3FC 8001CBFC 01000524 */   addiu     $a1, $zero, 0x1
  .L8001CC00:
    /* D400 8001CC00 1D730008 */  j          .L8001CC74
    /* D404 8001CC04 21908000 */   addu      $s2, $a0, $zero
  .L8001CC08:
    /* D408 8001CC08 40000624 */  addiu      $a2, $zero, 0x40
    /* D40C 8001CC0C 21280000 */  addu       $a1, $zero, $zero
  .L8001CC10:
    /* D410 8001CC10 0680023C */  lui        $v0, %hi(Gfx_TexSlots)
    /* D414 8001CC14 60CD5024 */  addiu      $s0, $v0, %lo(Gfx_TexSlots)
    /* D418 8001CC18 1600C010 */  beqz       $a2, .L8001CC74
    /* D41C 8001CC1C 21200000 */   addu      $a0, $zero, $zero
    /* D420 8001CC20 FFFF0824 */  addiu      $t0, $zero, -0x1
    /* D424 8001CC24 FEFF0724 */  addiu      $a3, $zero, -0x2
  .L8001CC28:
    /* D428 8001CC28 0000028E */  lw         $v0, 0x0($s0)
    /* D42C 8001CC2C 00000000 */  nop
    /* D430 8001CC30 0C004810 */  beq        $v0, $t0, .L8001CC64
    /* D434 8001CC34 00000000 */   nop
    /* D438 8001CC38 0A004710 */  beq        $v0, $a3, .L8001CC64
    /* D43C 8001CC3C 00000000 */   nop
    /* D440 8001CC40 EFFF4010 */  beqz       $v0, .L8001CC00
    /* D444 8001CC44 00000000 */   nop
    /* D448 8001CC48 0400038E */  lw         $v1, 0x4($s0)
    /* D44C 8001CC4C 00000000 */  nop
    /* D450 8001CC50 2B107100 */  sltu       $v0, $v1, $s1
    /* D454 8001CC54 03004010 */  beqz       $v0, .L8001CC64
    /* D458 8001CC58 00000000 */   nop
    /* D45C 8001CC5C 21886000 */  addu       $s1, $v1, $zero
    /* D460 8001CC60 21908000 */  addu       $s2, $a0, $zero
  .L8001CC64:
    /* D464 8001CC64 01008424 */  addiu      $a0, $a0, 0x1
    /* D468 8001CC68 2A108600 */  slt        $v0, $a0, $a2
    /* D46C 8001CC6C EEFF4014 */  bnez       $v0, .L8001CC28
    /* D470 8001CC70 20001026 */   addiu     $s0, $s0, 0x20
  .L8001CC74:
    /* D474 8001CC74 40191200 */  sll        $v1, $s2, 5
    /* D478 8001CC78 0680023C */  lui        $v0, %hi(Gfx_TexSlots)
    /* D47C 8001CC7C 60CD4224 */  addiu      $v0, $v0, %lo(Gfx_TexSlots)
    /* D480 8001CC80 21806200 */  addu       $s0, $v1, $v0
    /* D484 8001CC84 0680023C */  lui        $v0, %hi(D_8005F770)
    /* D488 8001CC88 000013AE */  sw         $s3, 0x0($s0)
    /* D48C 8001CC8C 70F7438C */  lw         $v1, %lo(D_8005F770)($v0)
    /* D490 8001CC90 1400028E */  lw         $v0, 0x14($s0)
    /* D494 8001CC94 080005AE */  sw         $a1, 0x8($s0)
    /* D498 8001CC98 02004230 */  andi       $v0, $v0, 0x2
    /* D49C 8001CC9C 0100422C */  sltiu      $v0, $v0, 0x1
    /* D4A0 8001CCA0 040003AE */  sw         $v1, 0x4($s0)
    /* D4A4 8001CCA4 0700A010 */  beqz       $a1, .L8001CCC4
    /* D4A8 8001CCA8 0C0002AE */   sw        $v0, 0xC($s0)
    /* D4AC 8001CCAC 32730008 */  j          .L8001CCC8
    /* D4B0 8001CCB0 80110200 */   sll       $v0, $v0, 6
  .L8001CCB4:
    /* D4B4 8001CCB4 70F7438C */  lw         $v1, %lo(D_8005F770)($v0)
    /* D4B8 8001CCB8 21108000 */  addu       $v0, $a0, $zero
    /* D4BC 8001CCBC 44730008 */  j          .L8001CD10
    /* D4C0 8001CCC0 040043AC */   sw        $v1, 0x4($v0)
  .L8001CCC4:
    /* D4C4 8001CCC4 C0110200 */  sll        $v0, $v0, 7
  .L8001CCC8:
    /* D4C8 8001CCC8 0C0002AE */  sw         $v0, 0xC($s0)
    /* D4CC 8001CCCC 21200002 */  addu       $a0, $s0, $zero
    /* D4D0 8001CCD0 C0290500 */  sll        $a1, $a1, 7
    /* D4D4 8001CCD4 1C00028E */  lw         $v0, 0x1C($s0)
    /* D4D8 8001CCD8 1800038E */  lw         $v1, 0x18($s0)
    /* D4DC 8001CCDC 00014230 */  andi       $v0, $v0, 0x100
    /* D4E0 8001CCE0 03110200 */  sra        $v0, $v0, 4
    /* D4E4 8001CCE4 2528A200 */  or         $a1, $a1, $v0
    /* D4E8 8001CCE8 FF036330 */  andi       $v1, $v1, 0x3FF
    /* D4EC 8001CCEC 83190300 */  sra        $v1, $v1, 6
    /* D4F0 8001CCF0 1C000296 */  lhu        $v0, 0x1C($s0)
    /* D4F4 8001CCF4 2528A300 */  or         $a1, $a1, $v1
    /* D4F8 8001CCF8 00024230 */  andi       $v0, $v0, 0x200
    /* D4FC 8001CCFC 80100200 */  sll        $v0, $v0, 2
    /* D500 8001CD00 2528A200 */  or         $a1, $a1, $v0
    /* D504 8001CD04 B172000C */  jal        Gfx_LoadTexSlotImage
    /* D508 8001CD08 100005A6 */   sh        $a1, 0x10($s0)
    /* D50C 8001CD0C 21100002 */  addu       $v0, $s0, $zero
  .L8001CD10:
    /* D510 8001CD10 2000BF8F */  lw         $ra, 0x20($sp)
    /* D514 8001CD14 1C00B38F */  lw         $s3, 0x1C($sp)
    /* D518 8001CD18 1800B28F */  lw         $s2, 0x18($sp)
    /* D51C 8001CD1C 1400B18F */  lw         $s1, 0x14($sp)
    /* D520 8001CD20 1000B08F */  lw         $s0, 0x10($sp)
    /* D524 8001CD24 0800E003 */  jr         $ra
    /* D528 8001CD28 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Gfx_FindOrLoadTexSlot
