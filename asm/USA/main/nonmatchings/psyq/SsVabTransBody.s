nonmatching SsVabTransBody, 0xC0

glabel SsVabTransBody
    /* 2A744 80039F44 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2A748 80039F48 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2A74C 80039F4C 21988000 */  addu       $s3, $a0, $zero
    /* 2A750 80039F50 FFFFA230 */  andi       $v0, $a1, 0xFFFF
    /* 2A754 80039F54 1100422C */  sltiu      $v0, $v0, 0x11
    /* 2A758 80039F58 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2A75C 80039F5C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2A760 80039F60 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A764 80039F64 1D004010 */  beqz       $v0, .L80039FDC
    /* 2A768 80039F68 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2A76C 80039F6C 00140500 */  sll        $v0, $a1, 16
    /* 2A770 80039F70 038C0200 */  sra        $s1, $v0, 16
    /* 2A774 80039F74 0680033C */  lui        $v1, %hi(D_80062D38)
    /* 2A778 80039F78 21187100 */  addu       $v1, $v1, $s1
    /* 2A77C 80039F7C 382D6390 */  lbu        $v1, %lo(D_80062D38)($v1)
    /* 2A780 80039F80 02000224 */  addiu      $v0, $zero, 0x2
    /* 2A784 80039F84 15006214 */  bne        $v1, $v0, .L80039FDC
    /* 2A788 80039F88 80901100 */   sll       $s2, $s1, 2
    /* 2A78C 80039F8C 0680103C */  lui        $s0, %hi(D_80062D98)
    /* 2A790 80039F90 21801202 */  addu       $s0, $s0, $s2
    /* 2A794 80039F94 982D108E */  lw         $s0, %lo(D_80062D98)($s0)
    /* 2A798 80039F98 F5F1000C */  jal        SpuSetTransferMode
    /* 2A79C 80039F9C 21200000 */   addu      $a0, $zero, $zero
    /* 2A7A0 80039FA0 DDF1000C */  jal        SpuSetTransferStartAddr
    /* 2A7A4 80039FA4 21200002 */   addu      $a0, $s0, $zero
    /* 2A7A8 80039FA8 0C004010 */  beqz       $v0, .L80039FDC
    /* 2A7AC 80039FAC 00000000 */   nop
    /* 2A7B0 80039FB0 0680053C */  lui        $a1, %hi(D_80062D50)
    /* 2A7B4 80039FB4 2128B200 */  addu       $a1, $a1, $s2
    /* 2A7B8 80039FB8 502DA58C */  lw         $a1, %lo(D_80062D50)($a1)
    /* 2A7BC 80039FBC C5F1000C */  jal        SpuWrite
    /* 2A7C0 80039FC0 21206002 */   addu      $a0, $s3, $zero
    /* 2A7C4 80039FC4 21102002 */  addu       $v0, $s1, $zero
    /* 2A7C8 80039FC8 01000324 */  addiu      $v1, $zero, 0x1
    /* 2A7CC 80039FCC 0680013C */  lui        $at, %hi(D_80062D38)
    /* 2A7D0 80039FD0 21082200 */  addu       $at, $at, $v0
    /* 2A7D4 80039FD4 FAE70008 */  j          .L80039FE8
    /* 2A7D8 80039FD8 382D23A0 */   sb        $v1, %lo(D_80062D38)($at)
  .L80039FDC:
    /* 2A7DC 80039FDC 31F2000C */  jal        _spu_setInTransfer
    /* 2A7E0 80039FE0 21200000 */   addu      $a0, $zero, $zero
    /* 2A7E4 80039FE4 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80039FE8:
    /* 2A7E8 80039FE8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2A7EC 80039FEC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2A7F0 80039FF0 1800B28F */  lw         $s2, 0x18($sp)
    /* 2A7F4 80039FF4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2A7F8 80039FF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A7FC 80039FFC 0800E003 */  jr         $ra
    /* 2A800 8003A000 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel SsVabTransBody
