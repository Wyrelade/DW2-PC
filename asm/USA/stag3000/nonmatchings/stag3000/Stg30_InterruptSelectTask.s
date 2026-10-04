nonmatching Stg30_InterruptSelectTask, 0x358

glabel Stg30_InterruptSelectTask
    /* C918 8006FC78 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C91C 8006FC7C 1400B1AF */  sw         $s1, 0x14($sp)
    /* C920 8006FC80 21888000 */  addu       $s1, $a0, $zero
    /* C924 8006FC84 01000524 */  addiu      $a1, $zero, 0x1
    /* C928 8006FC88 1800BFAF */  sw         $ra, 0x18($sp)
    /* C92C 8006FC8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* C930 8006FC90 1000248E */  lw         $a0, 0x10($s1)
    /* C934 8006FC94 2C00308E */  lw         $s0, 0x2C($s1)
    /* C938 8006FC98 1D008510 */  beq        $a0, $a1, .L8006FD10
    /* C93C 8006FC9C 02008228 */   slti      $v0, $a0, 0x2
    /* C940 8006FCA0 05004010 */  beqz       $v0, .L8006FCB8
    /* C944 8006FCA4 00000000 */   nop
    /* C948 8006FCA8 08008010 */  beqz       $a0, .L8006FCCC
    /* C94C 8006FCAC 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* C950 8006FCB0 EFBF0108 */  j          .L8006FFBC
    /* C954 8006FCB4 00000000 */   nop
  .L8006FCB8:
    /* C958 8006FCB8 02000224 */  addiu      $v0, $zero, 0x2
    /* C95C 8006FCBC B8008210 */  beq        $a0, $v0, .L8006FFA0
    /* C960 8006FCC0 21202002 */   addu      $a0, $s1, $zero
    /* C964 8006FCC4 EFBF0108 */  j          .L8006FFBC
    /* C968 8006FCC8 00000000 */   nop
  .L8006FCCC:
    /* C96C 8006FCCC C03C4424 */  addiu      $a0, $v0, %lo(Stg30_Battle)
    /* C970 8006FCD0 CC02828C */  lw         $v0, 0x2CC($a0)
    /* C974 8006FCD4 03000324 */  addiu      $v1, $zero, 0x3
    /* C978 8006FCD8 02004314 */  bne        $v0, $v1, .L8006FCE4
    /* C97C 8006FCDC 02000224 */   addiu     $v0, $zero, 0x2
    /* C980 8006FCE0 100002AE */  sw         $v0, 0x10($s0)
  .L8006FCE4:
    /* C984 8006FCE4 BC02828C */  lw         $v0, 0x2BC($a0)
    /* C988 8006FCE8 00000000 */  nop
    /* C98C 8006FCEC 02004314 */  bne        $v0, $v1, .L8006FCF8
    /* C990 8006FCF0 00000000 */   nop
    /* C994 8006FCF4 100005AE */  sw         $a1, 0x10($s0)
  .L8006FCF8:
    /* C998 8006FCF8 AC02828C */  lw         $v0, 0x2AC($a0)
    /* C99C 8006FCFC 00000000 */  nop
    /* C9A0 8006FD00 AC004314 */  bne        $v0, $v1, .L8006FFB4
    /* C9A4 8006FD04 21202002 */   addu      $a0, $s1, $zero
    /* C9A8 8006FD08 EDBF0108 */  j          .L8006FFB4
    /* C9AC 8006FD0C 100000AE */   sw        $zero, 0x10($s0)
  .L8006FD10:
    /* C9B0 8006FD10 1400238E */  lw         $v1, 0x14($s1)
    /* C9B4 8006FD14 00000000 */  nop
    /* C9B8 8006FD18 03006010 */  beqz       $v1, .L8006FD28
    /* C9BC 8006FD1C 00000000 */   nop
    /* C9C0 8006FD20 64006410 */  beq        $v1, $a0, .L8006FEB4
    /* C9C4 8006FD24 0780023C */   lui       $v0, %hi(Stg30_Battle)
  .L8006FD28:
    /* C9C8 8006FD28 1800238E */  lw         $v1, 0x18($s1)
    /* C9CC 8006FD2C 00000000 */  nop
    /* C9D0 8006FD30 0500622C */  sltiu      $v0, $v1, 0x5
    /* C9D4 8006FD34 08004010 */  beqz       $v0, .L8006FD58
    /* C9D8 8006FD38 0680023C */   lui       $v0, %hi(jtbl_800637F8)
    /* C9DC 8006FD3C F8374224 */  addiu      $v0, $v0, %lo(jtbl_800637F8)
    /* C9E0 8006FD40 80180300 */  sll        $v1, $v1, 2
    /* C9E4 8006FD44 21186200 */  addu       $v1, $v1, $v0
    /* C9E8 8006FD48 0000628C */  lw         $v0, 0x0($v1)
    /* C9EC 8006FD4C 00000000 */  nop
    /* C9F0 8006FD50 08004000 */  jr         $v0
    /* C9F4 8006FD54 00000000 */   nop
  jlabel .L8006FD58
    /* C9F8 8006FD58 21202002 */  addu       $a0, $s1, $zero
    /* C9FC 8006FD5C 0780023C */  lui        $v0, %hi(D_80074094)
    /* CA00 8006FD60 944040AC */  sw         $zero, %lo(D_80074094)($v0)
    /* CA04 8006FD64 07000224 */  addiu      $v0, $zero, 0x7
    /* CA08 8006FD68 040002AE */  sw         $v0, 0x4($s0)
    /* CA0C 8006FD6C 34030224 */  addiu      $v0, $zero, 0x334
    /* CA10 8006FD70 000000A6 */  sh         $zero, 0x0($s0)
    /* CA14 8006FD74 6045000C */  jal        Task_NextState2
    /* CA18 8006FD78 020002A6 */   sh        $v0, 0x2($s0)
  jlabel .L8006FD7C
    /* CA1C 8006FD7C 00000296 */  lhu        $v0, 0x0($s0)
    /* CA20 8006FD80 00100324 */  addiu      $v1, $zero, 0x1000
    /* CA24 8006FD84 00044224 */  addiu      $v0, $v0, 0x400
    /* CA28 8006FD88 000002A6 */  sh         $v0, 0x0($s0)
    /* CA2C 8006FD8C 00140200 */  sll        $v0, $v0, 16
    /* CA30 8006FD90 03140200 */  sra        $v0, $v0, 16
    /* CA34 8006FD94 37004314 */  bne        $v0, $v1, .L8006FE74
    /* CA38 8006FD98 00000000 */   nop
    /* CA3C 8006FD9C 6045000C */  jal        Task_NextState2
    /* CA40 8006FDA0 21202002 */   addu      $a0, $s1, $zero
  jlabel .L8006FDA4
    /* CA44 8006FDA4 02000296 */  lhu        $v0, 0x2($s0)
    /* CA48 8006FDA8 00000000 */  nop
    /* CA4C 8006FDAC 00024224 */  addiu      $v0, $v0, 0x200
    /* CA50 8006FDB0 020002A6 */  sh         $v0, 0x2($s0)
    /* CA54 8006FDB4 00140200 */  sll        $v0, $v0, 16
    /* CA58 8006FDB8 03140200 */  sra        $v0, $v0, 16
    /* CA5C 8006FDBC 00104228 */  slti       $v0, $v0, 0x1000
    /* CA60 8006FDC0 2C004014 */  bnez       $v0, .L8006FE74
    /* CA64 8006FDC4 00100224 */   addiu     $v0, $zero, 0x1000
    /* CA68 8006FDC8 020002A6 */  sh         $v0, 0x2($s0)
    /* CA6C 8006FDCC 6045000C */  jal        Task_NextState2
    /* CA70 8006FDD0 21202002 */   addu      $a0, $s1, $zero
  jlabel .L8006FDD4
    /* CA74 8006FDD4 0680023C */  lui        $v0, %hi(Pad_State)
    /* CA78 8006FDD8 F0F6438C */  lw         $v1, %lo(Pad_State)($v0)
    /* CA7C 8006FDDC 00000000 */  nop
    /* CA80 8006FDE0 1900601C */  bgtz       $v1, .L8006FE48
    /* CA84 8006FDE4 F0F64424 */   addiu     $a0, $v0, %lo(Pad_State)
    /* CA88 8006FDE8 0400828C */  lw         $v0, 0x4($a0)
    /* CA8C 8006FDEC 00000000 */  nop
    /* CA90 8006FDF0 1800401C */  bgtz       $v0, .L8006FE54
    /* CA94 8006FDF4 00000000 */   nop
    /* CA98 8006FDF8 1400828C */  lw         $v0, 0x14($a0)
    /* CA9C 8006FDFC 00000000 */  nop
    /* CAA0 8006FE00 1C004018 */  blez       $v0, .L8006FE74
    /* CAA4 8006FE04 00000000 */   nop
    /* CAA8 8006FE08 6045000C */  jal        Task_NextState2
    /* CAAC 8006FE0C 21202002 */   addu      $a0, $s1, $zero
    /* CAB0 8006FE10 97BF0108 */  j          .L8006FE5C
    /* CAB4 8006FE14 0E000424 */   addiu     $a0, $zero, 0xE
  jlabel .L8006FE18
    /* CAB8 8006FE18 0400038E */  lw         $v1, 0x4($s0)
    /* CABC 8006FE1C 07000224 */  addiu      $v0, $zero, 0x7
    /* CAC0 8006FE20 14006214 */  bne        $v1, $v0, .L8006FE74
    /* CAC4 8006FE24 00000000 */   nop
    /* CAC8 8006FE28 0C00028E */  lw         $v0, 0xC($s0)
    /* CACC 8006FE2C 00000000 */  nop
    /* CAD0 8006FE30 0E004010 */  beqz       $v0, .L8006FE6C
    /* CAD4 8006FE34 21202002 */   addu      $a0, $s1, $zero
    /* CAD8 8006FE38 7045000C */  jal        Task_SetState0
    /* CADC 8006FE3C 03000524 */   addiu     $a1, $zero, 0x3
    /* CAE0 8006FE40 9DBF0108 */  j          .L8006FE74
    /* CAE4 8006FE44 00000000 */   nop
  .L8006FE48:
    /* CAE8 8006FE48 01000224 */  addiu      $v0, $zero, 0x1
    /* CAEC 8006FE4C 96BF0108 */  j          .L8006FE58
    /* CAF0 8006FE50 0C0002AE */   sw        $v0, 0xC($s0)
  .L8006FE54:
    /* CAF4 8006FE54 0C0000AE */  sw         $zero, 0xC($s0)
  .L8006FE58:
    /* CAF8 8006FE58 12000424 */  addiu      $a0, $zero, 0x12
  .L8006FE5C:
    /* CAFC 8006FE5C A369000C */  jal        Snd_PlayById
    /* CB00 8006FE60 21280000 */   addu      $a1, $zero, $zero
    /* CB04 8006FE64 9DBF0108 */  j          .L8006FE74
    /* CB08 8006FE68 00000000 */   nop
  .L8006FE6C:
    /* CB0C 8006FE6C 5945000C */  jal        Task_NextState1
    /* CB10 8006FE70 21202002 */   addu      $a0, $s1, $zero
  .L8006FE74:
    /* CB14 8006FE74 1800238E */  lw         $v1, 0x18($s1)
    /* CB18 8006FE78 04000224 */  addiu      $v0, $zero, 0x4
    /* CB1C 8006FE7C 07006214 */  bne        $v1, $v0, .L8006FE9C
    /* CB20 8006FE80 07000224 */   addiu     $v0, $zero, 0x7
    /* CB24 8006FE84 0400038E */  lw         $v1, 0x4($s0)
    /* CB28 8006FE88 00000000 */  nop
    /* CB2C 8006FE8C 4B006210 */  beq        $v1, $v0, .L8006FFBC
    /* CB30 8006FE90 01006224 */   addiu     $v0, $v1, 0x1
    /* CB34 8006FE94 EFBF0108 */  j          .L8006FFBC
    /* CB38 8006FE98 040002AE */   sw        $v0, 0x4($s0)
  .L8006FE9C:
    /* CB3C 8006FE9C 0400028E */  lw         $v0, 0x4($s0)
    /* CB40 8006FEA0 00000000 */  nop
    /* CB44 8006FEA4 45004010 */  beqz       $v0, .L8006FFBC
    /* CB48 8006FEA8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* CB4C 8006FEAC EFBF0108 */  j          .L8006FFBC
    /* CB50 8006FEB0 040002AE */   sw        $v0, 0x4($s0)
  .L8006FEB4:
    /* CB54 8006FEB4 C03C4524 */  addiu      $a1, $v0, %lo(Stg30_Battle)
    /* CB58 8006FEB8 D403A3AC */  sw         $v1, 0x3D4($a1)
    /* CB5C 8006FEBC 0680023C */  lui        $v0, %hi(Pad_State)
    /* CB60 8006FEC0 F0F6438C */  lw         $v1, %lo(Pad_State)($v0)
    /* CB64 8006FEC4 00000000 */  nop
    /* CB68 8006FEC8 08006018 */  blez       $v1, .L8006FEEC
    /* CB6C 8006FECC F0F64424 */   addiu     $a0, $v0, %lo(Pad_State)
    /* CB70 8006FED0 1000038E */  lw         $v1, 0x10($s0)
    /* CB74 8006FED4 02000224 */  addiu      $v0, $zero, 0x2
    /* CB78 8006FED8 2A006210 */  beq        $v1, $v0, .L8006FF84
    /* CB7C 8006FEDC 01006224 */   addiu     $v0, $v1, 0x1
    /* CB80 8006FEE0 100002AE */  sw         $v0, 0x10($s0)
    /* CB84 8006FEE4 DFBF0108 */  j          .L8006FF7C
    /* CB88 8006FEE8 12000424 */   addiu     $a0, $zero, 0x12
  .L8006FEEC:
    /* CB8C 8006FEEC 0400828C */  lw         $v0, 0x4($a0)
    /* CB90 8006FEF0 00000000 */  nop
    /* CB94 8006FEF4 08004018 */  blez       $v0, .L8006FF18
    /* CB98 8006FEF8 00000000 */   nop
    /* CB9C 8006FEFC 1000028E */  lw         $v0, 0x10($s0)
    /* CBA0 8006FF00 00000000 */  nop
    /* CBA4 8006FF04 1F004010 */  beqz       $v0, .L8006FF84
    /* CBA8 8006FF08 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* CBAC 8006FF0C 100002AE */  sw         $v0, 0x10($s0)
    /* CBB0 8006FF10 DFBF0108 */  j          .L8006FF7C
    /* CBB4 8006FF14 12000424 */   addiu     $a0, $zero, 0x12
  .L8006FF18:
    /* CBB8 8006FF18 1400828C */  lw         $v0, 0x14($a0)
    /* CBBC 8006FF1C 00000000 */  nop
    /* CBC0 8006FF20 0F004018 */  blez       $v0, .L8006FF60
    /* CBC4 8006FF24 00000000 */   nop
    /* CBC8 8006FF28 1000028E */  lw         $v0, 0x10($s0)
    /* CBCC 8006FF2C 00000000 */  nop
    /* CBD0 8006FF30 00110200 */  sll        $v0, $v0, 4
    /* CBD4 8006FF34 21104500 */  addu       $v0, $v0, $a1
    /* CBD8 8006FF38 AC02438C */  lw         $v1, 0x2AC($v0)
    /* CBDC 8006FF3C 03000224 */  addiu      $v0, $zero, 0x3
    /* CBE0 8006FF40 10006214 */  bne        $v1, $v0, .L8006FF84
    /* CBE4 8006FF44 0E000424 */   addiu     $a0, $zero, 0xE
    /* CBE8 8006FF48 A369000C */  jal        Snd_PlayById
    /* CBEC 8006FF4C 21280000 */   addu      $a1, $zero, $zero
    /* CBF0 8006FF50 5145000C */  jal        Task_NextState0
    /* CBF4 8006FF54 21202002 */   addu      $a0, $s1, $zero
    /* CBF8 8006FF58 E2BF0108 */  j          .L8006FF88
    /* CBFC 8006FF5C 02000524 */   addiu     $a1, $zero, 0x2
  .L8006FF60:
    /* CC00 8006FF60 1C00828C */  lw         $v0, 0x1C($a0)
    /* CC04 8006FF64 00000000 */  nop
    /* CC08 8006FF68 06004018 */  blez       $v0, .L8006FF84
    /* CC0C 8006FF6C 21202002 */   addu      $a0, $s1, $zero
    /* CC10 8006FF70 7745000C */  jal        Task_SetState1
    /* CC14 8006FF74 21280000 */   addu      $a1, $zero, $zero
    /* CC18 8006FF78 0B000424 */  addiu      $a0, $zero, 0xB
  .L8006FF7C:
    /* CC1C 8006FF7C A369000C */  jal        Snd_PlayById
    /* CC20 8006FF80 21280000 */   addu      $a1, $zero, $zero
  .L8006FF84:
    /* CC24 8006FF84 02000524 */  addiu      $a1, $zero, 0x2
  .L8006FF88:
    /* CC28 8006FF88 21300000 */  addu       $a2, $zero, $zero
    /* CC2C 8006FF8C 2800248E */  lw         $a0, 0x28($s1)
    /* CC30 8006FF90 0C89000C */  jal        Math_PingPongRange
    /* CC34 8006FF94 03000724 */   addiu     $a3, $zero, 0x3
    /* CC38 8006FF98 EFBF0108 */  j          .L8006FFBC
    /* CC3C 8006FF9C 080002AE */   sw        $v0, 0x8($s0)
  .L8006FFA0:
    /* CC40 8006FFA0 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* CC44 8006FFA4 1000038E */  lw         $v1, 0x10($s0)
    /* CC48 8006FFA8 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* CC4C 8006FFAC D40340AC */  sw         $zero, 0x3D4($v0)
    /* CC50 8006FFB0 D00343AC */  sw         $v1, 0x3D0($v0)
  .L8006FFB4:
    /* CC54 8006FFB4 5145000C */  jal        Task_NextState0
    /* CC58 8006FFB8 00000000 */   nop
  .L8006FFBC:
    /* CC5C 8006FFBC 1800BF8F */  lw         $ra, 0x18($sp)
    /* CC60 8006FFC0 1400B18F */  lw         $s1, 0x14($sp)
    /* CC64 8006FFC4 1000B08F */  lw         $s0, 0x10($sp)
    /* CC68 8006FFC8 0800E003 */  jr         $ra
    /* CC6C 8006FFCC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_InterruptSelectTask
