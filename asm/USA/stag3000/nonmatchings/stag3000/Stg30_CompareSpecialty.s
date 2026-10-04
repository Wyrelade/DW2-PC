nonmatching Stg30_CompareSpecialty, 0xE8

glabel Stg30_CompareSpecialty
    /* 6CD0 8006A030 05000224 */  addiu      $v0, $zero, 0x5
    /* 6CD4 8006A034 03008214 */  bne        $a0, $v0, .L8006A044
    /* 6CD8 8006A038 00000000 */   nop
  .L8006A03C:
    /* 6CDC 8006A03C 0800E003 */  jr         $ra
    /* 6CE0 8006A040 21100000 */   addu      $v0, $zero, $zero
  .L8006A044:
    /* 6CE4 8006A044 FDFFA210 */  beq        $a1, $v0, .L8006A03C
    /* 6CE8 8006A048 00000000 */   nop
    /* 6CEC 8006A04C 03008014 */  bnez       $a0, .L8006A05C
    /* 6CF0 8006A050 01000224 */   addiu     $v0, $zero, 0x1
    /* 6CF4 8006A054 2E00A210 */  beq        $a1, $v0, .L8006A110
    /* 6CF8 8006A058 00000000 */   nop
  .L8006A05C:
    /* 6CFC 8006A05C 03008214 */  bne        $a0, $v0, .L8006A06C
    /* 6D00 8006A060 02000224 */   addiu     $v0, $zero, 0x2
    /* 6D04 8006A064 0900A210 */  beq        $a1, $v0, .L8006A08C
    /* 6D08 8006A068 00000000 */   nop
  .L8006A06C:
    /* 6D0C 8006A06C 03008214 */  bne        $a0, $v0, .L8006A07C
    /* 6D10 8006A070 03000224 */   addiu     $v0, $zero, 0x3
    /* 6D14 8006A074 0500A210 */  beq        $a1, $v0, .L8006A08C
    /* 6D18 8006A078 00000000 */   nop
  .L8006A07C:
    /* 6D1C 8006A07C 05008214 */  bne        $a0, $v0, .L8006A094
    /* 6D20 8006A080 04000224 */   addiu     $v0, $zero, 0x4
    /* 6D24 8006A084 0300A214 */  bne        $a1, $v0, .L8006A094
    /* 6D28 8006A088 00000000 */   nop
  .L8006A08C:
    /* 6D2C 8006A08C 0800E003 */  jr         $ra
    /* 6D30 8006A090 01000224 */   addiu     $v0, $zero, 0x1
  .L8006A094:
    /* 6D34 8006A094 03008214 */  bne        $a0, $v0, .L8006A0A4
    /* 6D38 8006A098 00000000 */   nop
    /* 6D3C 8006A09C FBFFA010 */  beqz       $a1, .L8006A08C
    /* 6D40 8006A0A0 00000000 */   nop
  .L8006A0A4:
    /* 6D44 8006A0A4 04008014 */  bnez       $a0, .L8006A0B8
    /* 6D48 8006A0A8 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D4C 8006A0AC 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D50 8006A0B0 0F00A210 */  beq        $a1, $v0, .L8006A0F0
    /* 6D54 8006A0B4 01000224 */   addiu     $v0, $zero, 0x1
  .L8006A0B8:
    /* 6D58 8006A0B8 04008214 */  bne        $a0, $v0, .L8006A0CC
    /* 6D5C 8006A0BC 02000224 */   addiu     $v0, $zero, 0x2
    /* 6D60 8006A0C0 03000224 */  addiu      $v0, $zero, 0x3
    /* 6D64 8006A0C4 0A00A210 */  beq        $a1, $v0, .L8006A0F0
    /* 6D68 8006A0C8 02000224 */   addiu     $v0, $zero, 0x2
  .L8006A0CC:
    /* 6D6C 8006A0CC 04008214 */  bne        $a0, $v0, .L8006A0E0
    /* 6D70 8006A0D0 03000224 */   addiu     $v0, $zero, 0x3
    /* 6D74 8006A0D4 04000224 */  addiu      $v0, $zero, 0x4
    /* 6D78 8006A0D8 0500A210 */  beq        $a1, $v0, .L8006A0F0
    /* 6D7C 8006A0DC 03000224 */   addiu     $v0, $zero, 0x3
  .L8006A0E0:
    /* 6D80 8006A0E0 05008214 */  bne        $a0, $v0, .L8006A0F8
    /* 6D84 8006A0E4 04000224 */   addiu     $v0, $zero, 0x4
    /* 6D88 8006A0E8 0300A014 */  bnez       $a1, .L8006A0F8
    /* 6D8C 8006A0EC 00000000 */   nop
  .L8006A0F0:
    /* 6D90 8006A0F0 0800E003 */  jr         $ra
    /* 6D94 8006A0F4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006A0F8:
    /* 6D98 8006A0F8 05008214 */  bne        $a0, $v0, .L8006A110
    /* 6D9C 8006A0FC 21100000 */   addu      $v0, $zero, $zero
    /* 6DA0 8006A100 01000324 */  addiu      $v1, $zero, 0x1
    /* 6DA4 8006A104 0200A310 */  beq        $a1, $v1, .L8006A110
    /* 6DA8 8006A108 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6DAC 8006A10C 21100000 */  addu       $v0, $zero, $zero
  .L8006A110:
    /* 6DB0 8006A110 0800E003 */  jr         $ra
    /* 6DB4 8006A114 00000000 */   nop
endlabel Stg30_CompareSpecialty
